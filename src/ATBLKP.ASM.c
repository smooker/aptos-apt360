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
         //<<assembler deleted-see original file>>
//from ASCAN.f:
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
#ifdef WIN32
#include <stdlib.h>
#endif
#include "f2c.h"
#include "AXTABL.ASM.h"

extern struct Keyword keyarray[];

void storeClassSubClassInN(uinteger* n, integer i)
{
	integer tmp;		
	*n=keyarray[i].data.classId;	
	*n<<=8;
	tmp=keyarray[i].data.subClass;
	tmp<<=16;
	*n+=tmp;
}
int atblkp_(unsigned char* entry, uinteger* n, uinteger*c)
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

