
#include <assert.h>
#include <f2c.h>
#include <stdio.h>
// **note** s/370 is bigendian, i386 is little;
//descriptions may be reversed from code

//***************************************************************************
//*      *
//*      * AEXTRA(A,I) EXTRACTS LOW ORDER 4 OR 2 BYTES OF
//*      * 8 OR 4-BYTE 'A' AS 'I' IS 4 OR 2 RESPECTIVELY.
//*      *
//***************************************************************************
integer aextra_(long long int* a , integer* i)
{
	long long int ret;	
	if(*i==4){
		ret=*a;
		return ret &= 0xffffffff;
	} else if(*i==2){
		ret=*a;
		return ret &= 0xffff;

	}
	assert(0);
	
}
//***************************************************************************
//*      *
//*      * AMDTOA(A,I) MOVES HIGH ORDER 4 OR 2 BYTES OF
//*      * 8 OR 4-BYTE 'A' TO LOW ORDER AS 'I' IS 4 OR 2 RESPECTIVELY
//*      *
//***************************************************************************
 integer amdtoa_(long long int* a , integer* i)
{
	long long int ret;
	if(*i==4){
		ret =*a;
		return ret>>=32;
	} else if(*i==2){
		ret =*a;
		ret>>=16;
		return ret&=0xff;

	}
	assert(0);
}


//***************************************************************************
//*      * AFULL8(A,B) PUTS'A' IN HIGH ORDER
//*      * AND 'B' IN LOW ORDER 4 BYTES OF FPR 0
//***************************************************************************
doublereal afull8_(integer* a , integer* b)
{

	doublereal* promotionWorkaround;
	int combinedInts[2];
	combinedInts[1]=*a;
	combinedInts[0]=*b;

//we don't want the compiler to convert the combinedInts 
//to a float representation, so this pointer is used to get
//around the promotion rules.

//for some reason, this doesn't work:	
//	unsigned long long int combinedInts=0;
//	combinedInts=*a;
//	combinedInts<<=32;
//	combinedInts|=*((unsigned long long int*)b);
//      combinedInts|=*b;

	promotionWorkaround=&combinedInts;
	return  *promotionWorkaround;
}
void amatod_(double* i , double* j)
{
	assert(0);
}
void aextrd_(double* i , double* j)
{
	assert(0);
}
void agetr_(double* i , double* j)
{
	assert(0);
}
//sense light
void slite_(double* i )
{
//	assert(0);
}
//sense light
void slitet_(double* i , double* j)
{
//	assert(0);
}





///original assembler:

/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 3, MODIFICATION 0 ***
*
ABTSHL   START 0
*      *
*      *       APT/360 SECTION ONE BIT MANIPULATION ROUTINES
*      *
         PRINT ON,DATA
*      *
         ENTRY AGETR,AGETI,AFULL8,AEXTRA,AEXTRD,AMATOD,AMDTOA,AEXCH
*      *
         USING *,15
AGETR    STM   2,4,WORK
AGETI    EQU   AGETR
         LM    3,4,0(1)           FROM ADD. IN GR3, TO ADD. IN GR4
         L     0,0(0,3)
         LE    0,4(0,3)
         L     3,8(0,1)
         L     3,0(0,3)           OP CODE
         LA    1,1
         LR    2,1
         BXH   1,2,OP1            OP1
         BXH   1,2,OP2            OP2
         BXH   1,2,OP3            OP3
         BXH   1,2,OP4            OP4
         STE   0,4(0,4)           OP5   2 - 2
OP1      ST    0,0(0,4)                 1 - 1
         BC    15,RET
OP2      STE   0,0(0,4)                 2 - 1
         BC    15,RET
OP3      ST    0,4(0,4)                 1 - 2
         BC    15,RET
OP4      STE   0,4(0,4)                 2 - 2
RET      LM    2,4,WORK
         BCR   15,14
*      *
*      * AFULL8(A,B) PUTS'A' IN HIGH ORDER
*      * AND 'B' IN LOW ORDER 4 BYTES OF FPR 0
*      *
         USING *,15
AFULL8   LR    0,2                SAVE GR2
         LM    1,2,0(1)           ADD. OF A IN GR1, ADD. OF B IN GR2
         MVC   WORK(4),0(1)       'A' IN HIGH ORDER
         MVC   WORK+4(4),0(2)     'B' IN LOW ORDER
         LD    0,WORK             INTO FUNCTION RETURN REG.
         LR    2,0                RESTORE GR2
         BCR   15,14              RETURN
*      *
*      * AEXTRA(A,I) EXTRACTS LOW ORDER 4 OR 2 BYTES OF
*      * 8 OR 4-BYTE 'A' AS 'I' IS 4 OR 2 RESPECTIVELY.
*      *
         USING *,15
AEXTRA   LR    0,2                SAVE GR2
         LM    1,2,0(1)           ADD. OF A IN GR1, ADD. OF I IN GR2
         CLI   3(2),X'02'         SET CONDITION CODE ACCORDING TO 'I'
         LR    2,0                RESTORE GR2
         BC    8,*+10             BRANCH ON OPERATION TYPE
         L     0,4(0,1)           FULL WORD OPERATION
         BCR   15,14              RETURN
         LH    0,2(0,1)           HALF WORD OPERATION
         BCR   15,14              RETURN
*      *
*      * AEXTRD(A,I) EXTRACTS HIGH ORDER 4 OR 2 BYTES OF
*      * 8 OR 4-BYTE 'A' AS 'I' IS 4 OR 2 RESPECTIVELY
*      *
         USING *,15
AEXTRD   LR    0,2                SAVE GR2
         LM    1,2,0(1)           ADD. OF A IN GR1, ADD. OF I IN GR2
         CLI   3(2),X'02'         SET CONDITION CODE ACCORDING TO 'I'
         LR    2,0                RESTORE GR2
         BC    8,*+10             BRANCH ON OPERATION TYPE
         L     0,0(0,1)           FULL WORD OPERATION
         BCR   15,14              RETURN
         LH    0,0(0,1)           HALF WORD OPERATION
         SLL   0,16
         BCR   15,14              RETURN
*      *
*      * AMATOD(A,I) MOVES LOW ORDER 4 OR 2 BYTES OF
*      * 8 OR 4-BYTE 'A' TO HIGH ORDER AS 'I' IS 4 OR 2 RESPECTIVELY
*      *
         USING *,15
AMATOD   LR    0,2                SAVE GR2
         LM    1,2,0(1)           ADD. OF A IN GR1, ADD. OF I IN GR2
         CLI   3(2),X'02'         SET CONDITION CODE ACCORDING TO 'I'
         LR    2,0                RESTORE GR2
         BC    8,*+10             BRANCH ON OPERATION TYPE
         L     0,4(0,1)           FULL WORD OPERATION
         BCR   15,14              RETURN
         LH    0,2(0,1)           HALF WORD OPERATION
         SLL   0,16
         BCR   15,14              RETURN
*      *
*      * AMDTOA(A,I) MOVES HIGH ORDER 4 OR 2 BYTES OF
*      * 8 OR 4-BYTE 'A' TO LOW ORDER AS 'I' IS 4 OR 2 RESPECTIVELY
*      *
         USING *,15
AMDTOA   LR    0,2                SAVE GR2
         LM    1,2,0(1)           ADD. OF A IN GR1, ADD. OF I IN GR2
         CLI   3(2),X'02'         SET CONDITION CODE ACCORDING TO 'I'
         LR    2,0                RESTORE GR2
         BC    8,*+10             BRANCH ON OPERATION TYPE
         L     0,0(0,1)           FULL WORD OPERATION
         BCR   15,14              RETURN
         LH    0,0(0,1)           HALF WORD OPERATION
         BCR   15,14              RETURN
*      *
*      * AEXCH(A,I) EXCHANGES HIGH AND LOW ORDER 2 BYTES OF 'A'
*      *
         USING *,15
AEXCH    L     1,0(0,1)           ADD. OF 'A'
         MVC   WORK(2),2(1)       LOW TO HIGH
         MVC   WORK+2(2),0(1)     HIGH TO LOW
         L     0,WORK             INTO RETURN REG.
         BCR   15,14              RETURN
*      *
         DS    0D
WORK     DS    3F
         END
*/
