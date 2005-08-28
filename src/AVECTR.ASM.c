#include <assert.h>
#include <math.h>
#include <float.h>

int avsto_(double* v1, double* v2)
{
	v2[0]=v1[0];
	v2[1]=v1[1];
	v2[2]=v1[2];
	return 0;
}
//----------------
int avadd_(double* v1,double* v2, double* v3)
{
	v3[0]=v1[0]+v2[0];
	v3[1]=v1[1]+v2[1];
	v3[2]=v1[2]+v2[2];
	return 0;
}
//----------------
int avsub_(double* v1,double* v2, double* v3)
{
	v3[0]=v1[0]-v2[0];
	v3[1]=v1[1]-v2[1];
	v3[2]=v1[2]-v2[2];
	return 0;
}
//----------------
int avdot_(double* v1,double* v2, double* dot)
{
	*dot=v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2];
	return 0;
}
//----------------
int avleng_(double* v1, double* leng)
{
	*leng=sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);

	return 0;
}
//----------------
void avnorm_(double* v1,double* v2, int* ier)
{

	double leng=sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);
	if(leng<=2*DBL_EPSILON){*ier=1;return;}
	else *ier=0;
	v2[0] = v1[0]/leng;
	v2[1] = v1[1]/leng;
	v2[2] = v1[2]/leng;

}
//----------------
void avcros_(double* v1,double* v2, double* v3)
{
	double temp[3];
	temp[0]=v1[1]*v2[2]-v1[2]*v2[1];
	temp[1]=v1[2]*v2[0]-v1[0]*v2[2];
	temp[2]=v1[0]*v2[1]-v1[1]*v2[0];
	
	v3[0]=temp[0];
	v3[1]=temp[1];
	v3[2]=temp[2];

}
//----------------
void avmult_(double* v1,double* a, double* v2)
{
	double aa=*a;
	v2[0]=aa*v1[0];
	v2[1]=aa*v1[1];
	v2[2]=aa*v1[2];
}
//----------------
void avdiv_(double* v1,double* a, double* v2, int* ier)
{
	double leng=*a;
	if(fabs(leng)<=2*DBL_EPSILON){*ier=1;return;}
	else *ier=0;
	v2[0] = v1[0]/leng;
	v2[1] = v1[1]/leng;
	v2[2] = v1[2]/leng;
}





/*
*     ASMBLR
AVEC     TITLE '* * * * * *  VECTOR PACKAGE  * * * * * *'
*.. THIS SUBROUTINE COMPLETELY MODIFIED FOR VERSION 4 MODIFICATION 0 **
* * * * * * *
*             THIS ROUTINE PERFORMS GENERAL COMPUTATIONS FOR VECTORS
*               1. STORE      CALL AVST0(V1,V2)      V2 = V1
*               2. ADD        CALL AVADD(V1,V2,V3)   V3 = V1 + V2
*               3. SUBTRACT   CALL AVSUB(V1,V2,V3)   V3 = V1 - V2
*               4. DOT PROD   CALL AVDOT(V1,V2,DOT)  DOT= V1 . V2
*               5. LENGTH     CALL AVLENG(V1,LENG)   LENG= /V1/
*               6. NORMALIZE  CALL AVNORM(V1,V2,IER) V2 = V1 NORMALIZED
*               7. CROSS PROD CALL AVCROS(V1,V2,V3)  V3 = V1 X V2
*               8. SCAL MULT  CALL AVMULT(V1,A,V2)   V2 = V1 * A
*               9  SCAL DIVID CALL AVDIV(V1,A,V2,IER) V2= V1/A
*               WHERE V1,V2,V3 ARE DOUBLE PRECISION VECTORS
*                     ALL OTHER PARAMETERS EXCEPT IER ARE
*                     DOUBLE PRECISION SCALARS
*                     IER=0   V2 IS ACCEPTABLE
*                     IER=1   V2 NOT ACCEPTABLE BECAUSE OF SMALL
*                             DIVISOR
* * * * * * * * *
AVECTR   CSECT
         BR    14
         EJECT
         ENTRY AVSTO
         USING *,15
AVSTO    DS    0H
         STM   2,3,SAVE
         L     2,0(1)
         L     3,4(1)
         LD    0,0(2)
         STD   0,0(3)
         LD    0,8(2)
         STD   0,8(3)
         LD    0,16(2)
         STD   0,16(3)
         L     2,SAVE
         L     3,SAVE+4
         BR    14
         DROP  15
         EJECT
         ENTRY AVADD
         USING *,15
AVADD    DS    0H
         STM   2,4,SAVE
         LM    2,4,0(1)
         LD    0,0(2)
         AD    0,0(3)
         STD   0,0(4)
         LD    0,8(2)
         AD    0,8(3)
         STD   0,8(4)
         LD    0,16(2)
         AD    0,16(3)
         STD   0,16(4)
         LM    2,4,SAVE
         BR    14
         DROP  15
         EJECT
         ENTRY AVSUB
         USING *,15
AVSUB    DS    0H
         STM   2,4,SAVE
         LM    2,4,0(1)
         LD    0,0(2)
         SD    0,0(3)
         STD   0,0(4)
         LD    0,8(2)
         SD    0,8(3)
         STD   0,8(4)
         LD    0,16(2)
         SD    0,16(3)
         STD   0,16(4)
         LM    2,4,SAVE
         BR    14
         DROP  15
         EJECT
         ENTRY AVDOT
         USING *,15
AVDOT    DS    0H
         STM   2,4,SAVE
         LM    2,4,0(1)
         LD    0,0(2)
         MD    0,0(3)
         LD    2,8(2)
         MD    2,8(3)
         ADR   0,2
         LD    2,16(2)
         MD    2,16(3)
         ADR   0,2
         STD   0,0(4)
         LM    2,4,SAVE
         BR    14
         DROP  15
         EJECT
         ENTRY AVLENG
         USING *,15
AVLENG   DS    0H
         STM   14,3,SAVE
         LM    2,3,0(1)
         LD    0,0(2)
         MDR   0,0
         LD    2,8(2)
         MDR   2,2
         ADR   0,2
         LD    2,16(2)
         MDR   2,2
         ADR   0,2
         STD   0,TEMP
*   CALL DSQRT
         LM    14,1,LGCALLRG
         BR    15
         DROP  15
         USING *,14
LGSQRET  DS    0H
         STD   0,0(3)
         LM    14,3,SAVE
         BR    14
         DROP  14
LGCALLRG DS    0D
LGR14    DC    A(LGSQRET)
LGR15    DC    V(DSQRT)
LGR0     DC    F'0'
LGR1     DC    A(ATEMP)
         EJECT
         ENTRY AVNORM
         USING *,15
AVNORM   DS    0H
         STM   14,4,SAVE
         LM    2,4,0(1)
         LD    0,0(2)
         MDR   0,0
         LD    2,8(2)
         MDR   2,2
         ADR   0,2
         LD    2,16(2)
         MDR   2,2
         ADR   0,2
         CD    0,DBLONE
         BNE   NRSTO01
         CR    2,3
         BE    NRSTO0
         LD    0,0(2)
         STD   0,0(3)
         LD    0,8(2)
         STD   0,8(3)
         LD    0,16(2)
         STD   0,16(3)
NRSTO0   DS    0H
         SR    3,3
         ST    3,0(4)
         LM    14,4,SAVE
         BR    14
NRSTO01  DS    0H
         STD   0,TEMP
*   CALL DSQRT
         LM    14,1,NRCALLRG
         BR    15
         DROP  15
         USING *,14
NRSQRET  DS    0H
         CD    0,TOLERANS
         BL    NRX1
         LD    2,DBLONE
         DDR   2,0
         LD    0,0(2)
         CD    0,DBLZERO
         BE    NRSTO1
         MDR   0,2
         LPDR  4,0
         CD    4,COMPTOL
         BL    NRX2
NRSTO1   DS    0H
         STD   0,WRKVEC2
         LD    0,8(2)
         CD    0,DBLZERO
         BE    NRSTO2
         MDR   0,2
         LPDR  4,0
         CD    4,COMPTOL
         BL    NRX3
NRSTO2   DS    0H
         STD   0,WRKVEC2+8
         LD    0,16(2)
         CD    0,DBLZERO
         BE    NRSTO3
         MDR   0,2
         LPDR  4,0
         CD    4,COMPTOL
         BL    NRX4
NRSTO3   DS    0H
         STD   0,16(3)
         LD    0,WRKVEC2
         STD   0,0(3)
         LD    0,WRKVEC2+8
         STD   0,8(3)
         SR    3,3
         ST    3,0(4)
         LM    14,4,SAVE
         BR    14
NRX1     SDR   0,0
         STD   0,0(3)
         STD   0,8(3)
         STD   0,16(3)
         LA    3,1
         ST    3,0(4)
         LM    14,4,SAVE
         BR    14
NRX2     SDR   0,0
         STD   0,WRKVEC
         LD    0,8(2)
         STD   0,WRKVEC+8
         LD    0,16(2)
         STD   0,WRKVEC+16
         LA    2,WRKVEC
         L     15,SAVE+4
         B     8(15)
NRX3     LD    0,0(2)
         STD   0,WRKVEC
         SDR   0,0
         STD   0,WRKVEC+8
         LD    0,16(2)
         STD   0,WRKVEC+16
         LA    2,WRKVEC
         L     15,SAVE+4
         B     8(15)
NRX4     LD    0,0(2)
         STD   0,WRKVEC
         LD    0,8(2)
         STD   0,WRKVEC+8
         SDR   0,0
         STD   0,WRKVEC+16
         LA    2,WRKVEC
         L     15,SAVE+4
         B     8(15)
         DROP  14
NRCALLRG DS    0D
NRR14    DC    A(NRSQRET)
NRR15    DC    V(DSQRT)
NRR0     DC    F'0'
NRR1     DC    A(ATEMP)
         EJECT
         ENTRY AVDIV
         USING *,15
AVDIV    DS    0H
         STM   2,5,SAVE
         LM    2,5,0(1)
         LD    0,0(3)
         CD    0,TOLERANS
         BL    DVX1
         LD    2,DBLONE
         DDR   2,0
         LDR   0,2
         MD    0,0(2)
         STD   0,0(4)
         LDR   0,2
         MD    0,8(2)
         STD   0,8(4)
         MD    2,16(2)
         STD   2,16(4)
         SR    3,3
         ST    3,0(5)
         LM    2,5,SAVE
         BR    14
DVX1     DS    0H
         SDR   0,0
         STD   0,0(4)
         STD   0,8(4)
         STD   0,16(4)
         LA    3,1
         ST    3,0(5)
         LM    2,5,SAVE
         BR    14
         DROP  15
         EJECT
         ENTRY AVMULT
         USING *,15
AVMULT   DS    0H
         STM   2,4,SAVE
         LM    2,4,0(1)
         LD    0,0(3)
         LDR   2,0
         MD    2,0(2)
         STD   2,0(4)
         LDR   2,0
         MD    2,8(2)
         STD   2,8(4)
         MD    0,16(2)
         STD   0,16(4)
         LM    2,4,SAVE
         BR    14
         DROP  15
         EJECT
         ENTRY AVCROS
         USING *,15
AVCROS   DS    0H
         STM   3,5,SAVE
         LM    3,5,0(1)
         LD    4,8(3)
         MD    4,16(4)
         LD    2,16(3)
         MD    2,8(4)
         SDR   4,2
         LD    6,16(3)
         MD    6,0(4)
         LD    2,0(3)
         MD    2,16(4)
         SDR   6,2
         LD    0,0(3)
         MD    0,8(4)
         LD    2,8(3)
         MD    2,0(4)
         SDR   0,2
         STD   0,16(5)
         STD   4,0(5)
         STD   6,8(5)
         LM    3,5,SAVE
         BR    14
         DROP  15
         EJECT
*   GENERAL AREA ADDRESSABLE BY ALL ROUTINES
TEMP     DS    D
SAVE     DS    18F
TOLERANS DC    D'0.000001'
COMPTOL  DC    X'27FFFFFFFFFFFFFF'
DBLZERO  DC    D'0.0'
DBLONE   DC    D'1.0'
WRKVEC   DS    3D
WRKVEC2  DS    3D
ATEMP    DS    0F
         DC    A(TEMP)
         ORG   *-4
         DC    X'80'
         ORG   *+3
         END
*/
