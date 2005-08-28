*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
SHIFT    START 0
*----------------------------------------------------------------------
* CALL SHIFT (A,N) WHERE
* A IS AN 8 BYTE WORD WHOSE CHARACTERS ARE TO BE SHIFTED LEFT WITHIN
*        ITSELF
* N IS THE NUMBER OF PLACES THE DATA IS TO BE SHIFTED LEFT
*        BLANKS ARE MOVED IN FROM THE RIGHT
*----------------------------------------------------------------------
*
BASEREG1 EQU   12
CALLREG  EQU   11
ARGREG   EQU   3
         USING SHIFT,BASEREG1
         USING CALLLIST,CALLREG
         USING ARGUMENT,ARGREG
         SAVE  (2,12),T,SHIFT
         LR    BASEREG1,15
         LR    CALLREG,1
         L     5,A           ADDRESS OF A IN REG 5
         L     3,N
         L     3,VALUE       N VALUE IS IN REG 3
         C     3,=F'0'
         BNL   NOWPOS
         LPR   6,3
         LR    3,6
NOWPOS   C     3,=F'8'
         BNH   TRANS
         L     3,=F'8'
TRANS    MVC   C(8),0(5)     MOVING DATA FROM A TO C
         LA    7,C           ADDRESS OF C IS IN REG 7
         AR    7,3           C ADDRESS + N VALUE IN REG 7
         MVC   0(8,5),0(7)
         RETURN (14,12),T
C        DS    CL8
CPLUS8   DC    X'4040404040404040'
ARGUMENT DSECT
VALUE    DS    A
CALLLIST DSECT
A        DS    A
N        DS    A
         CSECT
         END

