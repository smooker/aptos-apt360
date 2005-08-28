//original 360 assembler:
/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
AEXTRC   START 0
*      *
*      * AEXTRC EXTRACTS A CHARACTER FROM THE INPUT CARD,
*      * AND IF NON-BLANK, STORES IT IN CHAR, AND CLASSIFIES IT THUSLY:
*      *       CHAR = 0   , NF = 0 , ICHAR = 0
*      *       CHAR = 1-9 , NF = 1 , ICHAR = 1-9, RESPECTIVELY
*      *       CHAR = $   , NF = 2
*      *       CHAR = '   , NF = 3
*      *       CHAR = +   , NF = 4
*      *       CHAR = -   , NF = 5
*      *       CHAR = *   , NF = 6
*      *       CHAR = .   , NF = 7
*      *       CHAR = ,   , NF = 8
*      *       CHAR = (   , NF = 9
*      *       CHAR = )   , NF = 10
*      *       CHAR = =   , NF = 11
*      *       CHAR = /   , NF = 12
*      *       CHAR = E   , NF = 13
*      *       CHAR = A-D , NF = 14
*      *       CHAR = F-Z , NF = 14
*      *
         ENTRY AEXTRC
*      *
         EXTRN ASCANC,AINPOT
*      *
         USING AEXTRC,15
         USING SCANCOM,2
         STM   2,6,28(13)         SAVE SOME GR'S
         LM    1,4,COMADD         GR'S 2 AND 3 CONTAIN COMMON ADDRESSES
         LH    5,N72+2            CHAR. PICKUP INDEX IN GR5
BLANKS   AR    5,1                INCREMEMT
         CR    5,4                END OF CARD SCAN
         BC    2,EOCARD           YES
         LR    6,5
         AR    6,3                ADD. OF CHARACTER IN INWORD
         CLI   0(6),X'40'         CHECK FOR BLANK
         BC    8,BLANKS           YES
         STH   5,N72+2            NO - SAVE PICKUP INDEX
         LH    4,NUMCOL+2         UPDATE
         AR    4,1                SQUEEZE
         STH   4,NUMCOL+2         INDEX
         SR    0,0                PICK UP
         IC    0,0(6)             CHARACTER
         AR    4,3                PUT CHARACTER IN
         STC   0,0(4)             SQUEEZED CARD
         ST    0,CHAR             RETURN CHARACTER IN CHAR
         ST    0,ICHAR            PUT CHARACTER IN ICHAR
         NI    ICHAR+3,X'0F'      CONVERT TO POSSIBLE DEC. DIGIT
         ST    0,NF               PUT CHARACTER IN NF
         TR    NF+3(1),NFTAB      TRANSLATE NF TO PROPER CODE
         LM    2,6,28(13)         RECONDITION USED GR'S
         BCR   15,14              RETURN
EOCARD   CLI   MDOLAR+3,1         CHECK FOR $
         BC    8,RET              YES
         LH    4,NUMCOL+2         NO - INSERT $$ AT END OF CARD
         AR    3,4                ADD. OF LAST SQUEEZED CHAR. IN GR3
         MVC   1(2,3),DDOLR
         LA    4,2(4)             SET END OF SQUEEZED
         STH   4,NUMCOL+2         CARD INDEX
RET      LCR   1,1                SET END-OF-CARD FLAG
         ST    1,NF
         LM    2,6,28(13)         RECONDITION USED GR'S
         BCR   15,14              RETURN
         DS    0F
COMADD   DC    F'1'
         DC    A(ASCANC,AINPOT-1)
         DC    F'94'
DDOLR    DC    CL2'$$'
NFTAB    DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E070A09040E'
         DC    XL16'040E0E0E0E0E0E0E0E0E0E02060A0E0E'
         DC    XL16'050C0E0E0E0E0E0E0E0E0E08090E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0B03030B0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0D0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E0E'
         DC    XL16'000101010101010101010E0E0E0E0E0E'
SCANCOM  DSECT
CHAR     DS    F
N72      DS    F
NF       DS    F
ICHAR    DS    F
NUMCOL   DS    F
MDOLAR   DS    F
         END
*/
//end 360 assembler

#include "f2c.h"
#include <assert.h>
#include <stdio.h>

struct {
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

struct {
    integer char__, n72, nf, ichar, numcol, mdolar, jskip;
} ascanc_;

#define ascanc_1 ascanc_
void lookup();
int aextrc_()
{
//-1 in card array is for difference in the C and Fortran arrays value selection
	char* card;
	card=(char*)ainpot_1.inword;
	ascanc_1.n72++;	
	while(card[ascanc_1.n72-1]<33){//skip blanks, other non-printing
		ascanc_1.n72++;	
		if( ascanc_1.n72>94 ){
			if(ascanc_1.mdolar) {
					ascanc_1.nf=-1;//end of card flag
					return 0;
			}else{
				card[ascanc_1.numcol]='$';
				card[ascanc_1.numcol+1]='$';
				ascanc_1.numcol+=2;
				ascanc_1.nf=-1;//end of card flag
				return 0;
			}
		}
	}

	//get the char 
	ascanc_1.char__=card[ascanc_1.n72-1];
	ascanc_1.numcol++;
	//squeeze blanks out:ie, a condensed version
	card[ascanc_1.numcol-1]=ascanc_1.char__;
	lookup();//put the character code in the ascanc_ struct	
	return 0;
}

//------------------------------------------

void lookup(){//a lookup table like the assembler might be faster, but this works for now
if(ascanc_1.char__>48  && ascanc_1.char__ < 58){//ascii nums
		ascanc_1.ichar=ascanc_1.char__;
		ascanc_1.nf = 1;
		//ascii letters except 'E':
	}else if(  (ascanc_1.char__>64 && ascanc_1.char__<69)
		|| (ascanc_1.char__>69 && ascanc_1.char__<91)  ){
		ascanc_1.nf = 14;
	}else{
		switch(ascanc_1.char__){
			case '0': ascanc_1.nf = 0; ascanc_1.ichar = 48; break;
			case '$': ascanc_1.nf = 2; break;
			case '\'': ascanc_1.nf = 3; break;
			case '+': ascanc_1.nf = 4; break;
			case '-': ascanc_1.nf = 5; break;
			case '*': ascanc_1.nf = 6; break;
			case '.': ascanc_1.nf = 7; break;
			case ',': ascanc_1.nf = 8; break;
			case '(': ascanc_1.nf = 9; break;
			case ')': ascanc_1.nf = 10; break;
			case '=': ascanc_1.nf = 11; break;
			case '/': ascanc_1.nf = 12; break;
			case 'e': 
			case 'E': ascanc_1.nf = 13; ascanc_1.ichar = 69;break;
			default:
			break;
		} 
	}	


}
