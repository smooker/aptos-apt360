*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
INIT     START 0
*----------------------------------------------------------------------
* INIT IS USED TO DEFINE AN ARRAY FROM AN ALPHAMERIC STRING
* OF BCD CHARACTERS
* CALL INIT (X,8H EXAMPLE,M) WHERE
*        X IS THE ARRAY IN WHICH THE STRING WILL BE PLACED
*        THE SECOND PARAMETER IS THE STRING TO BE PLACED IN ARRAY X
*        M IS THE NUMBER OF 4 BYTE WORDS WHICH WILL CONTAIN THE STRING
*----------------------------------------------------------------------
*
BASEREG1 EQU   12
CALLREG  EQU   11
         USING INIT,BASEREG1
         USING CALLLIST,CALLREG
         SAVE  (2,12),T,INIT
         LR    BASEREG1,15
         LR    CALLREG,1
         L     3,M
         L     4,0(0,3)      M'S VALUE IN REG 4
         L     3,4(0,1)      STRING'S ADDRESS IN REG 3
         L     2,X           X'S ADDRESS IN REG 2
MOVEMENT MVC   0(4,2),0(3)
         S     4,=F'1'
         C     4,=F'0'
         BE    RET
         A     2,=F'4'
         A     3,=F'4'
         B     MOVEMENT
RET      RETURN (14,12),T
CALLLIST DSECT
ARGUMNT1 DS    A
         DS    A
ARGUMNT3 DS    A
         CSECT
X        EQU   ARGUMNT1
M        EQU   ARGUMNT3
         END

