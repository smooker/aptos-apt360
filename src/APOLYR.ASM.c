#include <config.h>
#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#ifdef HAVE_GSL_GSL_POLY_H
	#include <gsl/gsl_poly.h>
#endif
//as far as I can tell, the only roots this function needs to solve
//are 3rd and 5th degree
int apolyr_(double* aa,int* ii,void* nn,double* r,int* err)
{
#ifdef HAVE_LIBGSL
	double a,b,c,x0,x1,x2;
	int rtnval;
	x0=x1=x2=0;
	
	if(*ii !=3)assert(0); //haven't got 5th degree polys yet

	//division by zero pre-check
	if(fabs(aa[0])<2*DBL_EPSILON){ *err=1;return 0;}

	//gsl routine assumes the cubic constant is 1, so divide by aa[0]
	//to get it in that form
	a=aa[1]/aa[0];
	b=aa[2]/aa[0];
	c=aa[3]/aa[0];

	r[1]=r[3]=r[5]=1;//in the r array, this represents the imaginary part of the roots;
			//assume 1 so that calling function doesn't assume more real roots 
			//than actual; change based on rtnval
	
	rtnval=gsl_poly_solve_cubic(a, b, c,&x0, &x1, &x2);

	if(rtnval==0){*err=1;return 0;}
	r[0]=x0;
	r[1]=0;
	if(rtnval==1)return 0;//one real root
	r[2]=x1;
	r[3]=0;
	if(rtnval==2)return 0;//two real roots
	r[4]=x2;
	r[5]=0;

	return 0; //three roots
#else
	fprintf(stderr, "\n\n\napt360 error: ***no gsl libraries installed*** you will need to install gsl libs and run: make clean configure make install to prevent TABCYL and other functions that use gsl from failing\n"); 
	exit(1); 
#endif
}
/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
APOLYR   CSECT
*              ROOT EXTRACTION ROUTINE
         EXTRN DSQRT
         USING *,15
         BC    15,12(15)
         DC    CL7'APOLYR'
         DC    X'06'
         STM   14,12,12(13)
         LR    2,13          SAVE GPR 13
         LA    13,SAREA      PUT ADDRESS OF MY SAVE AREA
         ST    13,8(0,2)     INTO SAVE AREA OF CALLING PROGRAM
         ST    2,4(0,13)     PUT ADDRESS OF CALLING PROGRAM SAVE AREA
*                            IN MY SAVE AREA
A        L     6,0(1)        LOAD ADDRESS OF POLYNOMIAL INTO GPR 6
         L     9,4(1)
         L     11,0(9)
         ST    11,DEG        STORE DEGREE OF POLYNOMIAL IN DEG
         M     10,EIGHT
         ST    11,DEG2       STORE 8*DEG IN DEG2 - 8 BYTES/WORD
         L     11,0(9)
         A     11,ONE
         ST    11,NOC        STORE NO. OF COEFFIEICENTS
         M     10,EIGHT
         ST    11,NOC2       STORE 8*(NO. OF COEFFIEICENTS) IN NOC2
         LA    7,WORK        LOAD ADDRESS OF DEPRESSED EQU IN GPR 7
*                            THIS IS ALSO FIRST LOC. OF WORK AREA
         LR    9,7
         A     9,NUM16
         A     9,NOC2        ADD OF (WK AREA+ 16+NOC2) FOR SAVING
*                            DEPRESSED EQUATION-IS IN GPR  9
         LR    11,9
         A     11,NUM16
         A     11,NOC2       ADD OF (WORK AREA+32+2*NOC2)IN GPR 11
*                            FOR FIRST DERIVATIVE
         L     4,8(1)
         L     5,0(4)
         LR    3,5
         A     5,ONE
         SRA   5,1(0)
         SRA   3,1(0)
         CR    3,5
         BC    7,CCNV
CCNV1    ST    5,CONV
         L     3,12(1)
         L     4,CON2
         ST    4,SCALE       STORE SCALE FACTOR
         SR    2,2
         ST    2,SCALE1
         L     8,16(1)
         ST    2,0(8)        STORE ZERO IN CALLERS ERROR IND AND SAVE 8
         ST    2,ERIND       STORE ZERO IN ERROR IND. ERIND
         SR    4,4           GPR4=0   KEEP COUNT OF ROOTS IN GPR 4
*
*              SAVE ORIGINAL POLYNOMIAL
*
         LD    4,CON2
         L     2,DEG2
MOVNT    LD    2,0(2,6)
         MDR   2,4
         STD   2,0(2,7)
         MD    4,SCALE
         S     2,EIGHT
         BC    10,MOVNT
*
*              SEE IF QUADRATIC OR LINEAR REMAINS
*
D        L     2,NOC
         S     2,THREE
         BC    8,T           QUADRATIC REMAINS
         BC    4,U           LINEAR REMAINS
B        MVC   COUNT(4),HUN5 SETUP COUNT FOR NO. OF ITERATIONS
         L     2,DEG2
         LD    6,0(2,7)
         LTDR  6,6
         BC    7,NZ5
         STD   6,0(4,3)      STORE ROOTS(ZERO) IN REAL
         STD   6,8(4,3)      AND IMAGINARY
         A     4,NUM16
*
*              REDUCE DEGREE AND NO. OF COEFFICIENTS
*
C        L     0,DEG
         ST    0,NOC
         S     0,ONE
         ST    0,DEG
         L     0,DEG2        REDUCE DEG2 AND NOC
         ST    0,NOC2
         S     0,EIGHT
         ST    0,DEG2
         BC    15,D
CCNV     LH    3,CSFZ1
         STC   3,CSFZ(5)
         BC    15,CCNV1
*
*              SET UP GUESS FOR NEWTON RAPHSON
*
NZ5      L     2,NOC2
         S     2,NUM16
         LD    6,0(2,7)
         LTDR  6,6
         BC    7,E           BRANCH IF NOT ZERO
         LD    6,8(2,7)      NEWTON GUESS WILL BE -(A SUB ZERO)
         BC    15,F
E        LD    6,8(2,7)      NEWTON GUESS WILL BE -(A SUB ZERO/A SUB 1)
         DD    6,0(2,7)
F        SDR   4,4
         SDR   4,6
         STD   4,NEWT
*
*              SET UP GUESS FOR MODIFIED BAIRSTOW
*
         S     2,EIGHT
         LD    6,0(2,7)
         LTDR  6,6
         BC    7,G           BRANCH IF NOT ZERO
         LD    6,8(2,7)      SMALL A = A SUB 1
         STD   6,BAIR1       WHEN A SUB 2 = 0
         LD    6,16(2,7)     SMALL B = A SUB 0 WHEN A SUB 2 = 0
         BC    15,H
G        LD    6,8(2,7)
         DD    6,0(2,7)      IF A SUB 2 IS NOT ZERO
         STD   6,BAIR1       SMALL A = A SUB 1/A SUB 2
         LD    6,16(2,7)     IF A SUB 2 IS NOT ZERO
         DD    6,0(2,7)      SMALL B = A SUB 0/A SUB 2
H        STD   6,BAIR2
*
*              DO AN ITERATION BY NEWTON SOLUTION
*
H1       L     0,DEG2
         SR    1,1
         SR    2,2
         LD    6,0(2,7)
         STD   6,0(1,9)
A8T2     A     2,EIGHT
         LD    4,NEWT
         MD    4,0(1,9)
         AD    4,0(2,7)
         A     1,EIGHT
         STD   4,0(1,9)
         CR    0,2
         BC    2,A8T2        BRANCH IF GPR0 IS GREATER THAN GPR2
         STD   4,FR1
         S     0,EIGHT
         SR    1,1
         SR    2,2
         LD    6,0(1,9)
         STD   6,0(2,11)
A8T1     A     1,EIGHT
         LD    4,NEWT
         MD    4,0(2,11)
         AD    4,0(1,9)
         A     2,EIGHT
         STD   4,0(2,11)
         CR    0,1
         BC    2,A8T1        BRANCH IF GPR0 IS GREATER THAN GPR2
         STD   4,FR2
         S     2,EIGHT       EQUAL ROOT TEST AREA
         LD    4,NEWT
         MD    4,0(2,11)
         AW    4,0(1,9)
         STD   4,WORKFG
         NC    WORKFG(3),CSFZ
         BC    8,ERR         EQUAL ROOT TRANSFER
         LD    4,FR1
         DD    4,FR2
         SDR   6,6
         SDR   6,4
         AD    6,NEWT
         STD   6,NEWT2       STORE R SUB 2
         SW    6,NEWT        CHECK FOR CONVERGENCE
         STD   6,WORKFG
         L     1,CONV
         EX    1,CVCKT
         BC    7,K           HAS NOT CONVERGED - BRANCH
         LD    6,NEWT2
         MD    6,SCALE
         STD   6,0(4,3)      STORE REAL ROOT
         SDR   0,0
         STD   0,8(4,3)      STORE ZERO IMGINARY PART
         A     4,NUM16
         BC    15,V
CVCKT    NC    WORKFG(1),CSFZ
*
*              DO AN ITERATION BY MODIFIED BAIRSTOW METHOD
*
K        LD    4,NEWT2
         STD   4,NEWT        STORE NEW GUESS NEWTON GUESS
MBAIR    L     0,DEG2        GO ON WITH MODIFIED BAIRSTOW METHOD
         L     1,NUM16
         LNR   1,1
         SDR   0,0
         STD   0,0(1,9)
         STD   0,8(1,9)
         SR    2,2
N        LD    6,0(1,9)
         MD    6,BAIR2
         LD    4,8(1,9)
         MD    4,BAIR1
         ADR   4,6
         SDR   6,6
         SDR   6,4
         AD    6,0(2,7)
         A     1,EIGHT
         STD   6,8(1,9)
         A     2,EIGHT
         CR    0,2
         BC    2,N           BRANCH IF GPR0 IS GREATER THAN GPR2
         STD   6,X
         LD    4,0(1,9)
         MD    4,BAIR2
         SDR   6,6
         SDR   6,4
         AD    6,0(2,7)
         STD   6,Y
         S     0,NUM16
         L     2,NUM16
         LNR   2,2
         SDR   0,0
         STD   0,0(2,11)
         STD   0,8(2,11)
         SR    1,1
Q        LD    6,0(2,11)
         MD    6,BAIR2
         LD    4,8(2,11)
         MD    4,BAIR1
         ADR   4,6
         SDR   6,6
         SDR   6,4
         AD    6,0(1,9)
         A     2,EIGHT
         STD   6,8(2,11)
         A     1,EIGHT
         CR    0,1
         BC    2,Q           BRANCH IF GPR0 IS GREATER THAN GPR1
         STD   6,XB
         LD    4,0(2,11)
         MD    4,BAIR2
         SDR   6,6
         SDR   6,4
         AD    6,0(1,9)
         STD   6,YB
         LD    4,XB
         MD    4,BAIR1
         SDR   6,6
         SDR   6,4
         AD    6,YB
         STD   6,XA
         LD    4,XB
         MD    4,BAIR2
         SDR   6,6
         SDR   6,4
         STD   6,YA
         MD    6,XB
         LD    4,XA
         MD    4,YB
         SDR   4,6
         LD    6,Y
         MD    6,XB
         LD    2,YB
         MD    2,X
         SDR   2,6
         DDR   2,4
         STD   2,DELTA
         LD    6,X
         MD    6,YA
         LD    2,Y
         MD    2,XA
         SDR   2,6
         DDR   2,4
         STD   2,DELTB
         LD    6,BAIR1
         AD    6,DELTA
         STD   6,NEWA        OBTAIN NEW A
         AD    2,BAIR2
         STD   2,NEWB        OBTAIN NEW B
         L     1,CONV        CHECK FOR CONVERGENCE
         SW    6,BAIR1
         STD   6,WORKFG
         EX    1,CVCKT
         BC    7,R           HAS NOT CONVERGED - BRANCH
         SW    2,BAIR2
         STD   2,WORKFG
         EX    1,CVCKT
         BC    7,R           HAS NOT CONVERGED - BRANCH
S        LD    6,NEWA        PROBLEM CONVERGED
         STD   6,AA
         LD    4,NEWB
         STD   4,BB
         BAL   10,QUAD
         L     1,DEG
         S     1,ONE
         ST    1,DEG
         L     1,DEG2
         S     1,EIGHT
         ST    1,DEG2
         SR    0,0
         ST    0,ERIND       RESTORE EQUAL ROOT IND.
*
*              SAVE DEPRESSED EQUATION
*
V        L     1,NOC2
         SR    2,2
V1       LD    6,0(2,9)
         STD   6,0(2,7)
         A     2,EIGHT
         CR    1,2
         BC    2,V1
         BC    15,C
R        LD    6,NEWA
         STD   6,BAIR1
         LD    4,NEWB
         STD   4,BAIR2
         L     1,COUNT
         S     1,ONE
         BC    12,ERR2
         ST    1,COUNT
         L     2,ERIND
         LTR   2,2
         BC    7,MBAIR       EQUAL ROOT TRANSFER
         BC    15,H1         GO BACK FOR ANOTHER ITERATION
*
*              QUADRATIC REMAINS
*
T        LD    4,8(0,7)
         DD    4,0(0,7)
         STD   4,AA
         LD    4,16(0,7)
         DD    4,0(0,7)
         STD   4,BB
         LTDR  4,4
         BC    7,QSLVE       NOT ZERO-BRANCH
         SDR   6,6
         STD   6,0(4,3)
         STD   6,8(4,3)
         A     4,NUM16
         BC    15,U
QSLVE    BAL   10,QUAD
BACK     MVC   CSFZ+2(6),CSFZ+1
         L     13,SAREA+4
         LM    2,12,28(13)
         L     14,12(13)
         MVI   12(13),X'FF'
         BCR   15,14         RETURN TO CALLER
*
*              LINEAR REMAINS
*
U        LD    6,8(0,7)
         SDR   4,4
         SDR   4,6
         DD    4,0(0,7)
         MD    4,SCALE
         STD   4,0(4,3)      STORE  REAL ROOT
         SDR   0,0
         STD   0,8(4,3)      STORE  ZERO IN IMAGINARY ROOT
         BC    15,BACK
*
*              SOLUTION TO A QUADRATIC GIVEN A AND B
*
QUAD     LD    6,AA
         DD    6,CONFL       A/2
         STD   6,WORKFG      A/2 IS SAVED IN WORKFG
         MDR   6,6
         SD    6,BB          (A/2)SQUARED-B
         BC    4,ONTO        RESULT NEGATIVE - BRANCH
         STD   6,SRARG
         LA    1,ALIST
         LA    13,SAREA
         L     15,SQRT1
         BALR  14,15         BRANCH TO SQ. ROOT ROUTINE
         BC    0,X'004'
         L     13,4(13)
         L     15,16(13)
         SDR   6,6
         SD    6,WORKFG
         SDR   6,0
         MD    6,SCALE
         STD   6,0(4,3)           STORE REAL ROOT NO. 1
         SDR   2,2
         STD   2,8(4,3)           STORE ZERO IN IMAGINARY ROOT NO.1
         A     4,NUM16
         STD   2,8(4,3)           STORE ZERO IN IMAGINARY ROOT NO.2
         SD    0,WORKFG
         MD    0,SCALE
         STD   0,0(4,3)           STORE REAL ROOT NO. 2
ONTO1    A     4,NUM16
         BCR   15,10
ONTO     LPDR  6,6
         STD   6,SRARG
         LA    1,ALIST
         LA    13,SAREA
         L     15,SQRT1
         BALR  14,15         BRANCH TO SQ. ROOT ROUTINE
         BC    0,X'002'
         L     13,4(13)
         L     15,16(13)
         MD    0,SCALE
         STD   0,8(4,3)      STORE IMAGINARY ROOT NO. 1
         A     4,NUM16
         SDR   6,6
         SDR   6,0
         STD   6,8(4,3)      STORE IMAGINARY ROOT NO. 2
         SDR   6,6
         SD    6,WORKFG
         MD    6,SCALE
         STD   6,0(4,3)      STORE REAL ROOT NO. 2
         S     4,NUM16
         STD   6,0(4,3)      STORE REAL ROOT NO. 1
         A     4,NUM16
         BC    15,ONTO1
ERR      L     1,ONE         SET EQUAL ROOTS IND. TO ONE
         ST    1,ERIND       AND TRY BAIRSTOW METHOD
         LD    6,NEWT
         ADR   6,6
         SDR   4,4
         SDR   4,6
         STD   4,BAIR1
         LD    6,NEWT
         MDR   6,6
         STD   6,BAIR2
         BC    15,MBAIR
ERR2     L     1,DEG         WOULD NOT CONVERGE - ERROR RETURN
         ST    1,0(8)
         BC    15,BACK
DEG      DS    1F
NOC      DS    1F
DEG2     DS    1F
NOC2     DS    1F
CONV     DS    1F
ALIST    DC    X'80'
         DC    AL3(SRARG)
SQRT1    DC    A(DSQRT)
ONE      DC    1F'1'
TWO      DC    1F'2'
THREE    DC    1F'3'
FOUR     DC    1F'4'
EIGHT    DC    1F'8'
NUM16    DC    1F'16'
HUN5     DC    1F'500'
ERIND    DC    1F'0'
COUNT    DC    1F'500'
FR1      DS    1D
FR2      DS    1D
NEWT     DS    1D
NEWT2    DS    1D
BAIR1    DS    1D
BAIR2    DS    1D
SCALE    DS    1F
SCALE1   DS    1F
X        DS    1D
Y        DS    1D
XB       DS    1D
XA       DS    1D
YB       DS    1D
YA       DS    1D
DELTA    DS    1D
DELTB    DS    1D
NEWA     DS    1D
NEWB     DS    1D
AA       DS    1D
BB       DS    1D
WORKFG   DS    1D
SRARG    DS    1D
CON2     DC    1D'1.0'
CONFL    DC    1D'2.0'
CSFZ     DC    X'00FFFFFFFFFFFFFF'
SAREA    DS    18F
WORK     DS    28D
CSFZ1    DC    X'00F0' $$DRILL THE HOLES*************************

        $$PRINT DIMENSIONS
        
        C2=2.93  $$HOLE CIRCLE DIA
        
 DRILLC=CIRCLE/CENTER,(POINT/0,0),RADIUS,(C2/2)

TL=11
SPD=1200
CUTR=.5
CALL/STRTUP
CYCLE/DRILL,.4,20.,IPM,.1
DRILLP=PATERN/ARC,DRILLC,(90-20),(90+20),CLW,19
GOTO/DRILLP
CYCLE/OFF
COOLNT/OFF
REWIND

         END
*/
