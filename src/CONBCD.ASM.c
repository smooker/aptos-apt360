#include <assert.h>
int conbcd_(void* a,void* b,void* c,void* d,void* e)
{
	assert(0);
	return 0;
}
/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 ***
CONBCD   START 0
*---------------------------------------------------------------------
* CONBCD  SUBPROGRAM TO CONVERT A FLOATING-POINT NUMBER TO A FIXED
*         FORMAT FOR SEBSEQUENT TAPE PUNCHING
* CALL CONBCD (A,B,I,J,K) WHERE
* A IS THE FLOATING POINT NUMBER TO BE CONVERTED TO BCD
* B IS THE LOCATION WHERE THE BCD NUMBERS WILL BE STORED
* I IS THE NUMBER OF BCD DIGITS TO BE INCLUDED IN B.  IF I IS NEGATIVE,
*        THE SIGN OF A WILL BE INCLUDED AND THE FIELD LENGTH WILL BE
*        I+1 BCD CHARACTERS.
* J IS THE NUMBER OF FRACTIONAL BCD DIGITS TO BE INCLUDED IN I.  FOR
*        J NEGATIVE, THE FIELD LENGTH WILL BE I+1 BCD CHRS AND THE
*        DECIMAL SIGN WILL BE INCLUDED.  FOR BOTH I AND J NEGATIVE,
*        THE FIELD LENGTH WILL BE I+2 BCD CHRS.  IF THE ABSOLUTE VALUE
*        OF J IS GREATER THAN 100, TRAILING ZEROS WILL BE DELETED.
*        J WILL THEN EQUAL THE ABSOLUTE VALUE MINUS 100.  IF THE
*        ABSOLUTE VALUE OF J IS GREATER THAN 200, LEADING ZEROS WILL BE
*        DELETED.  J WILL THEN BE THE ABSOLUTE VALUE MINUS 200.
* K IS OPTIONAL.  IF INCLUDED, A IS SINGLE PRECISION FOR K=1, AND
*        DOUBLE PRECISION FOR K=2.  NO K IMPLIES DOUBLE PRECISION.
*---------------------------------------------------------------------
         EXTRN A0CON
K0       EQU   A0CON
K1       EQU   A0CON+4
K2       EQU   A0CON+8
K3       EQU   A0CON+12
K4       EQU   A0CON+16
K5       EQU   A0CON+20
K6       EQU   A0CON+24
K7       EQU   A0CON+28
K8       EQU   A0CON+32
K9       EQU   A0CON+36
K10      EQU   A0CON+40
K11      EQU   A0CON+44
K12      EQU   A0CON+48
SAVEREG  EQU   13
BASEREG1 EQU   12
CALLREG  EQU   10
WORKREG  EQU   9
CONSTREG EQU   8
ARGREG   EQU   3
         USING CONBCD,BASEREG1
         USING CALLLIST,CALLREG
         USING ARGUMENT,ARGREG
         USING A0CON,CONSTREG
         SAVE  (2,12),T,CONBCD
         LR    BASEREG1,15
         LR    CALLREG,1
         ST    SAVEREG,INVOLKNG
         LA    WORKREG,SAVE
         ST    WORKREG,8(0,13)
         LR    SAVEREG,WORKREG
         L     CONSTREG,=V(A0CON)
         MVC   SFL,K0
         MVC   DFL,K0
         MVC   TZFL,K0
         MVC   LZFL,K0
         L     3,A
         MVC   DP50(8),VALUE
         TM    J,X'80'       TESTING FOR FIFTH PARAMETER
         BZ    HAVEK
         MVC   PREC,K0
         MVC   IM,K12
         MVC   JM,K8
         MVC   IR,K6
         B     A4
HAVEK    L     3,K
         L     3,VALUE
         C     3,K1
         BE    KEQUAL1
         MVC   PREC,K2
         MVC   IM,=F'16'
         MVC   JM,=F'14'
         MVC   IR,K8
         B     A4
KEQUAL1  MVC   PREC,K1
         MVC   DP50+4(4),K0
         MVC   IM,K8
         MVC   JM,K6
         MVC   IR,K4
A4       L     3,I           ******
         L     4,VALUE       *
         ST    4,CC          *
         C     4,K0          * TESTING TO SEE IF I IS NEG OR POS
         BE    ERR1          *
         BH    P1            ******
         LPR   3,4           MAKING I POSITIVE
         A     3,K1
         ST    3,CC          INCREMENTING I BY 1
         MVC   SFL,K1        SETTING SIGN INCLUSION FLAG
P1       L     3,J           ******
         L     4,VALUE       *
         ST    4,JVALUE      * TESTING TO SEE IF J IS NEG OR POS
         C     4,K0          *
         BNL   P2            ******
         LPR   3,4           MAKING J POSITIVE
         ST    3,JVALUE
         L     3,CC          ******
         A     3,K1          * INCREMENTING I BY 1
         ST    3,CC          ******
         MVC   DFL,K1        SETTING DECIMAL INCLUSION FLAG
P2       L     3,JVALUE      ******
         C     3,=F'200'     *
         BL    P3            *
         S     3,=F'200'     * TESTING TO SEE IF J IS GREATER THAN 200
         ST    3,JVALUE      *
         MVC   LZFL,K1       ******
         B     P4
P3       C     3,=F'100'     ******
         BL    P4            *
         S     3,=F'100'     * TESTING TO SEE IF J IS GREATER THAN 100
         ST    3,JVALUE      *
         MVC   TZFL,K1       ******
P4       CLC   JVALUE,JM     ******
         BNH   P5            *
         MVC   JVALUE,JM     *
P5       CLC   CC,IM         * TESTING IF J AND I ARE WITHIN RANGE
         BNH   P6            *
         MVC   CC,IM         *
P6       L     3,IM          *
         S     3,CC          ******
CALCLB   C     3,IR          ******
         BL    HAVELB        *
         S     3,IR          * CALCULATING NO OF LEADING BLANKS
         B     CALCLB        ******
HAVELB   ST    3,NOOFLB
         L     5,B
LOADLB   C     3,K0          ******
         BE    CALCLS        *
         MVI   0(5),X'40'    * STUFFING IN LEADING BLANKS
         S     3,K1          *
         A     5,K1          *
         B     LOADLB        ******
CALCLS   L     3,CC
         S     3,JVALUE      ******
         CLC   SFL,K1        *
         BNE   *+8           *
         S     3,K1          * CALCULATING NO OF LEADING SPACES
         CLC   DFL,K1        * AVAILABLE FOR INTEGER DIGITS BEFORE
         BNE   *+8           * THE DECIMAL POINT
         S     3,K1          *
         ST    3,LEADROOM    ******
         C     3,K0
         BL    ERR1
         LD    4,DP50
         LPDR  2,4
         SDR   4,4
         ADR   4,2
PUTSIGN  CLC   SFL,K1        ******
         BNE   LOADLS        *
         LE    0,DP50        *
         CE    0,=E'0'       *
         BNL   POSITIVE      * STUFFING IN SIGN
         MVI   0(5),X'60'    *
         A     5,K1          *
         B     LOADLS        *
POSITIVE MVI   0(5),X'4E'    *
         A     5,K1          ******
LOADLS   CD    4,=D'1'
         BNL   LO5
         L     6,K0
         B     LO2
LO5      L     6,K1
LO1      CD    4,=D'10'
         BL    LO2
         DD    4,=D'10'
         A     6,K1
         B     LO1
DELETINT S     6,LEADROOM    ******
DELETMOR STD   4,NUM         *
         NC    NUM(8),KEEP3  * GET RID OF INTEGER FOR WHICH NO ROOM
         LD    6,NUM         * HAS BEEN ALLOCATED BY THE CALLING
         SDR   4,6           * PARAMETERS
INTISZER S     6,K1          ******
         BZ    WHERETO       BRANCH IF ENOUGH INTEGERS ARE DELETED
         MD    4,=D'10'      ******
         CD    4,=D'1'       * GET NEXT INTEGER
         BNL   DELETMOR      ******
         B     INTISZER
WHERETO  CLC   LEADROOM,K0   IS FIRST CHAR TO BE CONVERTED AN INTEGER
         BE    NOPOSEX       BRANCH IF NO
         L     6,LEADROOM    ******
         MVC   IFL,K1        * SET INTEGER FLAG
         B     NO3           *******
LO2      LR    9,5
         S     9,K1
         ST    9,STOPROND    GET ADDRESS TO STOP ROUNDING
         C     6,LEADROOM    COMPARE NO. OF INTEGERS TO SPACE AVAILABLE
         BE    TESTEXP
         BH    DELETINT
         L     3,LEADROOM
         SR    3,6
LO3      CLC   LZFL,K0       ******
         BE    LO4           *
         MVI   0(5),X'40'    * PUTTING IN LEADING ZEROS OF ELSE BLANKS
         B     *+8           * IF DELETION OF LEADING ZEROS IS DESIRED
LO4      MVI   0(5),X'F0'    *
         A     5,K1          *
         S     3,K1          *
         BC    8,TESTEXP     ******
         B     LO3
TESTEXP  CD    4,=D'1'
         BNL   POSEXP
NOPOSEX  CLC   DFL,K1        ******
         BNE   NO2           *
         MVI   0(5),X'4B'    * PUTTING IN DECIMAL POINT
         A     5,K1          ******
NO2      MVC   IFL,K0        ******
         L     6,JVALUE      * LOADING JVALUE
         A     6,K1          ******
NO3      MD    4,=D'10'
         CD    4,=D'1'
         BNL   PO1
         L     4,=F'240'
         B     PO1A
POSEXP   MVC   IFL,K1
PO1      STD   4,NUM         ******
         NC    NUM(8),KEEP3  *
         LD    6,NUM         *
         SDR   4,6           * SUBTRACTING DIGIT FROM NUMBER
         L     4,NUM         * CHANGING INTEGER TO BCD
         N     4,DIGIT       *
         SRL   4,20          *
         O     4,FDIGIT      *
PO1A     C     6,K1          ******
         BE    PO2
         B     PO4
PO2      CLC   IFL,K0
         BE    PO3
         B     PO4
PO3      ST    4,RDIGIT
         B     ROUND
PO4      STC   4,0(0,5)      STUFFING BCD DIGIT INTO B
         A     5,K1
         S     6,K1
         BNE   NO3
IORF     CLC   IFL,K1        ******
         BNE   ROUND         *
         CLC   DFL,K1        * DETERMINING WHETHER END OF INTEGER OR
         BNE   NO2           * END OF FRACTION
         B     NOPOSEX       ******
ROUND    S     5,K1          *****
         ST    5,LDIGIT      *
         L     3,RDIGIT      * TESTING IF ROUNDING DIGIT IS GREATER
         C     3,=F'245'     * THAN 5
         BL    FOLBLNKS      ******
         A     5,K1
RO1      S     5,K1          ******
         C     5,STOPROND    *
         BE    FOLBLNKS      *
         CLI   0(5),X'F9'    *
         BE    NINER         *
         CLI   0(5),X'4B'    *
         BE    RO1           *
         CLI   0(5),X'40'    *
         BE    BLANK         *
         L     3,K0          * ROUNDING
         IC    3,0(0,5)      *
         A     3,K1          *
         STC   3,0(0,5)      *
         B     FOLBLNKS      *
NINER    MVI   0(5),X'F0'    *
         B     RO1           ******
BLANK    MVI   0(5),X'F1'
FOLBLNKS CLC   PREC,K0
         BNE   TRAILING
         L     5,LDIGIT
         A     5,K1
         L     3,CC
         A     3,NOOFLB
         C     3,K6
         BH    FOURWORD
         MVC   0(2,5),FOURZERO
         B     TRAILING
FOURWORD MVC   0(4,5),FOURZERO
TRAILING CLC   TZFL,K1
         BNE   RET
         L     5,LDIGIT
         L     3,JVALUE
TO1      C     3,K0
         BE    RET
         CLI   0(5),X'F0'
         BNE   RET
         MVI   0(5),X'40'
         S     5,K1
         S     3,K1
         B     TO1
ERR1     L     4,IOCOMMON
         L     3,84(0,4)
         ST    3,IOADDR
         CNOP  0,4
         L     15,IBKOM
         BAL   14,4(0,15)
         DC    XL1'1',AL3(IOADDR)
         DC    AL4(ERL1)
         BAL   14,16(0,15)
ERREXIT  L     15,AERRORAD
         L     15,0(15)
         BR    15
RET      L     SAVEREG,INVOLKNG
         RETURN (14,12),T
ERL1     DC    X'021A22'
         DC    C' CONBCD PARAMETER SPECIFIED WRONG '
         DC    X'1E22'
         DS    0F
IOCOMMON DC    V(ATAPTB)
IOADDR   DC    F'0'
IBKOM    DC    V(IBCOM#)
AERRORAD DC    V(AERROR)
FDIGIT   DC    X'000000F0'
DIGIT    DC    X'00F00000'
KEEP3    DC    X'FFF0000000000000'
VLFL     DS    F
SFL      DS    F             SIGN INCLUSION FLAG
DFL      DS    F             DECIMAL INCLUSION FLAG
DP50     DS    D
RDIGIT   DC    X'00000000'
IM       DS    F
JM       DS    F
IR       DS    F
CC       DS    F   I PLUS SPACES FOR SIGN AND DECIMAL IF NEEDED
PREC     DS    F
JVALUE   DS    F   NUMBER OF FRACTIONAL DIGITS (NOTHING ELSE)
TZFL     DS    F
LEADROOM DS    F
STOPROND DC    F'0'          ADDRESS TO STOP ROUNDING OUTPUT
NUM      DS    D
LDIGIT   DS    F   LAST DIGIT WANTED BY THE PROGRAMMER
IFL      DS    F
LZFL     DS    F
NOOFLB   DS    F
FOURZERO DC    C'    '
SAVE     DS    0F
INDICATR DS    F
INVOLKNG DS    F
INVOLKED DS    F
RETURNXX DS    F
ENTRYXXX DS    F
REGOTO12 DS    13F
CALLLIST DSECT
ARGUMNT1 DS    A
ARGUMNT2 DS    A
ARGUMNT3 DS    A
ARGUMNT4 DS    A
ARGUMNT5 DS    A
ARGUMENT DSECT
VALUE    DS    CL4
         CSECT
CON      EQU   CALLLIST
A        EQU   ARGUMNT1
B        EQU   ARGUMNT2
I        EQU   ARGUMNT3
J        EQU   ARGUMNT4
K        EQU   ARGUMNT5
         END
*/
