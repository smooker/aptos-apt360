// Table lookup of Apt keywords
//original 360 assembler:
/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
ATBLKP   START 0                  SUBPROGRAM ATBLKP(W,N,M)
*      *                          SEARCHES APT VOCABULARY AND
*      *                          SYNONYMS (IF ANY) FOR THE
*      *                          WORD STORED IN W. IF A VOCABULARY
*      *                          WORD OR SYNONYM IS DISCOVERED, W
*      *                          IS REPLACED BY THE PROTAPE CLASS
*      *                          AND SUBCLASS, AND THE ICLASS
*      *                          INFORMATION IS PLACED IN N. IF
*      *                          NOT, N IS SET TO ZERO. IF W IS
*      *                          A POSTPROCESSOR NAME (CLASS 30),
*      *                          W IS NOT REPLACED. IF M IS SET
*      *                          TO ONE, ONLY THE APT FIXED FIELD
*      *                          VOCABULARY IS SEARCHED.
*      *
         ENTRY ATBLKP
*      *
         EXTRN AXTABL,ASYNTB
*      *
         USING ATBLKP,15
         STM   2,6,28(13)         SAVE SOME GR'S
         LM    1,3,0(1)           LOAD PARAM. ADD. LIST
         XC    0(4,2),0(2)        CLEAR FOUND FLAG
         L     4,0(3)             FIXED FIELD FLAG IN GR4
         L     3,COMADD           ADD. OF VOCAB. TABLE
         LR    5,3
         AH    5,12(3)            LOW INDEX = END OF FIXED FIELD TABLE.
         BCT   4,NOFIX            CHECK FOR FIXED FIELD CALL
FIXF     LA    4,16               YES - INCREMENT TO GR4
         SR    5,4                REDUCE END OF LOOP BY 16
NOTYET   CLC   0(8,1),0(3)        IS THIS A FIXED FIELD WORD OR SYNONYM
         BC    8,GOTHIM           YES
         BXLE  3,4,NOTYET         NO
RET      LM    2,6,28(13)         RESTORE USED GR'S
         BCR   15,14              RETURN
NOFIX    LH    6,14(3)            LENGTH OF REG. VOCAB. TABLE
         AR    6,3                HIGH INDEX = END OF REG. VOCAB. TAB.
HALVE    LR    4,6                SAVE HIGH INDEX IN GR6
         LR    3,5                SAVE LOW INDEX IN GR5
         SR    4,3                DIFFERENCE
         SRL   4,5                HALVE
         SLL   4,4                X 16
         AR    3,4                ADD TO LOW INDEX
         CLC   0(8,1),0(3)        HAVE WE FOUND A VOCAB. WORD
         BC    8,GOTHIM           YES
         BC    4,LOW
         LR    5,3                COMPARE IS HIGH - RESET LOW INDEX
ENDIT    LTR   4,4                END OF VOCAB. SEARCH
         BC    6,HALVE            NO - HALVE TABLE AGAIN
         L     3,COMADD+4         YES - CHECK SYN TABLE - ADD. TO GR3
         CLI   803(3),0           ANY SYNONYMS
         BC    8,RET              NO
         L     5,800(3)           NO. OF SYN ENTRIES
         SLL   5,3                MULTIPLY FOR DOUBLE 8-BYTE ENTRIES
         AR    5,3                END OF SYN TABLE
         BC    15,FIXF            LOOK THROUGH SYN TABLE
LOW      LR    6,3                COMPARE IS LOW - RESET HIGH INDEX
         BC    15,ENDIT           CHECK FOR END
GOTHIM   LH    0,8(3)             SET UP ICLASS
         SLL   0,8
         STH   0,2(2)             CLASS
         LH    0,10(3)            AND
         STH   0,0(2)             SUBCLASS
         CLI   2(2),30            CHECK FOR POSTPROCESSOR NAME
         BC    8,RET              YES - ALL FINISHED
         LH    0,12(3)            NO - SET UP PROTAP
         ST    0,0(1)             SUBCLASS
         LH    0,14(3)            AND
         ST    0,4(1)             CLASS
         BC    15,RET             GO HOME
COMADD   DC    A(AXTABL,ASYNTB)
         END
*/
//from ASCAN.f:
/*
C     TBLKUP(W,B,C) SEARCHES XTABLE FOR W  - IF NOT IN XTABLE, B = 0
C                   IF IN XTABLE, THEN B = CLASS,,SUB-CLASS.AND C IS THE
C                   PROTAP CODE (IF APPLICABLE)
C          IF    A = 0    , NF = 0          IF    A = 1-9  , NF = 1
C          IF    A = $    , NF = 2          IF    A = BLANK, NF = 3
C          IF    A = +    , NF = 4          IF    A = -    , NF = 5
C          IF    A = *    , NF = 6          IF    A = .    , NF = 7
C          IF    A = ,    , NF = 8          IF    A = (    , NF = 9
C          IF    A = )    , NF = 10         IF    A = =    , NF = 11
C          IF    A = /    , NF = 12         IF    A = E    , NF = 13
C          IF    A = A THRU D   OR  F    THRU  Z  ,  THEN    NF = 14
*/



//end of 360 assembler
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include "f2c.h"
#include "AXTABL.ASM.h"

extern struct Keyword keyarray[];
void storeClassSubClassInN(unsigned int* n, integer i)
{
	integer tmp;		

	*n=keyarray[i].data.classId;	
	*n<<=8;
	tmp=keyarray[i].data.subClass;
	tmp<<=16;
	*n+=tmp;


}

int atblkp_(unsigned char* entry,unsigned int* n,unsigned int*c)

{

	int i=0;
	char tmpEntry[9];
	long long int* ent;
	int imax;
	tmpEntry[8]='\0';//end of c-string
	*n=0;
	
	while(i<8){
		tmpEntry[i]=entry[i];
		++i;
	}

//c=1-only search fixed field words
	i=0;
/*
goto skip;	
	if(*c==1){
		while( i<5){
			if(strcmp(keyarray[i].word,tmpEntry )==0){
				storeClassSubClassInN(n,i);
			//TODO: protap stuff
				return 0;
			}
		++i;
		}
		return 0;
	}

skip:
*/
	i=0;
	
	if(*c==1){imax=5;}
	else imax=INT_MAX;
	while( (keyarray[i].word !=0)  &&  (i<imax)  ){
		if(strcmp(keyarray[i].word,tmpEntry )==0){
			storeClassSubClassInN(n,i);
			if(keyarray[i].data.classId==30)return 0;
			else { 
				ent=(long long int*)entry;		
				*ent=keyarray[i].data.proTapSubClass;
				*ent<<=32;
				*ent+=keyarray[i].data.proTapClass;
			}
			break;
		}
		++i;
	}

	return 0;
}

