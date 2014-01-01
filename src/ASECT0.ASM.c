/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***

ASECT0   START 0

         ENTRY APTTRU

         USING ASECT0,12

         SAVE  (2,12),T,ASECT0

         LR    12,15

         ST    13,SAVEAREA+4

         LA    10,SAVEAREA

         ST    10,8(0,13)

         L     15,VIBCOM               INITIALIZE IBCOM#

         BAL   14,64(0,15)

         LR    13,10                    INITIALIZE INTERRUPT HANDLING

*        B     AROUND     ACTIVATE THIS INSTRUCTION TO DISABLE SPIE

         SPIE  ARITH,(9,11,12,13,15)

         LR    13,10

AROUND   CALL  ACNTRL

OUT      L     13,SAVEAREA+4

         L     15,VIBCOM

         BAL   14,68(0,15)              RETURN TO CONTROL PROGRAM

         DC    H'0'

         USING APTTRU,15

APTTRU   L     12,ASECT0AD

         B     OUT

ASECT0AD DC    A(ASECT0)

         DROP  12

         USING *,15

ARITH    STM   1,2,SAVEREG1

         LH    2,6(0,1)                 GET INTERRUPTION CODE

         SH    2,=H'8'

         SLA   2,2                      POSITION TO WORD BOUNDARY

         CH    2,MOST

         BNL   RETURN

         L     1,VIBCOM

         BC    15,TRAPS(2)

*

TRAPS    DS    0F

         BC    15,FXOVF                 FIXED POINT OVERFLOW

         BC    15,FXDVC                 FIXED POINT DIVIDE

         BC    15,DCOVF                 DECIMAL OVERFLOW

         BC    15,DCDVC                 DECIMAL DIVIDE

         BC    15,FPOVF                 EXPONENT OVERFLOW

         BC    15,FPUNF                 EXPONENT UNDERFLOW

         BC    15,FPSIG                 SIGNIFICANCE

         BC    15,FPDVC                 FLOATING POINT DIVIDE

MOST     DC    AL2(*-TRAPS)

*

FPOVF    MVI   72(1),X'FF'              SET OVERFLOW INDICATOR IN IBCOM

         MVI   OFLOFLAG,X'01'

         B     TOLERNCE

*

FPUNF    MVI   72(1),X'0F'             SER UNDERFLOW INDICATOR IN IBCOM

         MVI   OFLOFLAG,X'00'

TOLERNCE L     1,SAVEREG1

         STM   3,6,SAVEREG3

         L     3,8(1)     GET 2ND HALF OF OLD PSW

        L     4,8(1)

        MVC   SAVEREGE(8),12(1)

        N     4,IA     GET I. A. FROM OLD PSW

        S     4,TWO

        N     3,NOILC     TEST IF ILC IS ZERO

        BC    8,RESTORE     BRANCH IF ZERO

        N     3,ILC     TEST IF ILC IS 1

         BC    8,ILCIS2     BRANCH IF ILC IS 2

GETR1    IC    3,1(4)     GET 2ND BYTE FROM FL PT INSTRUCTION

         N     3,R1     GET R1 FROM FL PT INSTRUCTION

         STC   3,EXR1

         B     ERRTYPE

ILCIS2   S     4,TWO

        CLI   0(4),X'44'     TEST FOR 'EX' OP CODE

         BNE   GETR1     BRANCH IF NOT 'EX'

        IC    3,1(4)     GET 2ND BYTE OF 'EX' INSTRUCTION

        N     3,X2     GET X2 FROM 'EX'

        SLL   3,2     MULT. BY 4 TO GET SAVEREG DISPLACEMENT

        LA    5,SAVEREG1-4

        AR    3,5

        L     6,0(3)     SAVE X2 VALUE IN REG 6

        IC    3,2(4)     GET 3RD BYTE OF EX INSTRUCTION

        N     3,B2     GET B2 FROM EX

        SLL   3,2     MULT. BY 4 TO SAVEREG DISPLACEMENT

        AR    3,5

        A     6,0(3)     X2+B2

         LH    3,2(4)     GET DISP FROM EX INSTRUCTION

         SLL   3,20

         SRL   3,20

         AR    6,3     X2+B2+DISPLACEMENT

         IC    3,1(4)     GET 2ND BYTE FROM EX

         N     3,R1     GET R1 FROM EX INSTRUCTION

        IC    2,1(6)     GET 2ND BYTE OF FL PT INSTRUCTION

         N     2,R1     GET R1 FROM FL PT INSTRUCTION

        OR    3,2     OR R1 FROM EX AND R1 FROM X2+B2+DISPLACEMENT

         LR    4,6

ERRTYPE  CLI   OFLOFLAG,X'01'     SEE IF INTERRUPT WAS OVERFLOW

        BE    OVERFLOW

        LA    5,Z

        B     TESTLENG

OVERFLOW EX    3,COMPARE     TEST SIGN OF FL PT REG TO BE MODIFIED

        BL    OVFMINUS

        LA    5,P

        B     TESTLENG

OVFMINUS LA 5,M

TESTLENG CLI 0(4),X'30'     TEST FOR LONG

         BL    OFLOLONG

         CLI   0(4),X'40'          TEST FOR SHORT

         BL    OVFSHORT

         CLI   0(4),X'70'     TEST FOR LONG

         BL    OFLOLONG

         B     OVFSHORT     MUST BE SHORT

OVFSHORT MVI   LOADREG,X'78'     OP CODE FOR LE

         B     EXEC

OFLOLONG MVI   LOADREG,X'68'     OP CODE FOR LD

EXEC     EX    3,LOADREG

RESTORE  LM    1,6,SAVEREG1

         BR    14

COMPARE  CE    0,Z

LOADREG  LD    0,0(5)

         DS    0F

IA       DC    X'00FFFFFF'

NOILC    DC    X'C0000000'

ILC      DC    X'40000000'

TWO      DC    F'2'

X2       DC    X'0000000F'

SAVEREG1 DC    2F'0'

SAVEREG3 DC    11F'0'

SAVEREGE DC    2F'0'

R1       EQU   *

B2       DC    X'000000F0'

OFLOFLAG DC    X'00'

EXR1     DC    X'00'

         DC    2X'00'

         DS    0D

M        DC    X'FFFFFFFFFFFFFFFF'

P        DC    X'7FFFFFFFFFFFFFFF'

Z        DC    X'0000000000000000'

*

DVCHK    MVI   73(1),X'FF'   SET DIVIDE CHECK INDICATOR IN IBCOM

*

RETURN   LM    1,2,SAVEREG1

         BR    14

FXOVF    EQU   RETURN

FXDVC    EQU   DVCHK

DCOVF    EQU   RETURN

DCDVC    EQU   DVCHK

FPSIG    EQU   RETURN

FPDVC    EQU   DVCHK

VIBCOM   DC    V(IBCOM#)

SAVEAREA DC    18F'0'

         END

*/

