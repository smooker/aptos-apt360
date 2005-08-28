*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 ***
*
1123     TITLE 'IBM SYSTEM/360 APT SECTION 1 SUBROUTINE FOR PERFORMING $
               80-COLUMN INPUT CARD CHARACTER EDIT'
         PRINT ON,GEN,DATA
***********************************************************************
***********************************************************************
*                  IBM SYSTEM/360 APT SECTION 1 SUBROUTINE            *
*                    FOR PERFORMING AN 80-COLUMN INPUT CARD           *
*                    BCDIC-EBCDIC CHARACTER EDIT                      *
***********************************************************************
***********************************************************************
*                                                                   RCS
*                             CALL ACHEDT(INPUT,N)
*
*                    LINKAGE... L     15,CHAREDAD
*                               BALR  14,15
*                        GPR 1 CONTAINS INDIRECT ADDRESS OF ARGUMENTS
*                        GPR 13 CONTAINS ADDRESS OF GPR SAVE AREA
*                        GPR 14 CONTAINS RETURN ADDRESS TO CALLING PROG
*                        GPR 15 CONTAINS ADDRESS OF CSECT ACHEDT
*
ACHEDT   CSECT
*
         USING *,15                SPECIFY BASE REGISTER 15
*
***********************************************************************
*                    *SUBROUTINE ENTRY*                               *
***********************************************************************
CHAREDIT STM   1,6,SAVE+4*6(13)    SAVE GPR 1-6
         LM    3,4,ARGS(1)         LOAD ADDRESS ARGUMENTS IN GPR 3-4
         BCTR  3,0                 GPR 3 CONTAINS ADDRESS OF INPUT-1
         SR    5,5                 SET GPR 5 FOR NO ERROR
         SR    6,6                 SET GPR 6 FOR ERROR OUTPUT
         LA    0,106(0,0)          LOAD LENGTH OF SCAN IN GPR 0
         LA    1,CHARBGN-CHAREND+1 LOAD NO. OF LEGAL CODES IN GPR 1
CCPOINTR LA    3,1(0,3)            UPDATE INPUT CHARACTER POINTER
         LA    2,CHARTAB-1(1)      LOAD ADDRESS CHARTAB ENTRY IN GPR 2
         CLC   CHAR(1*1,3),CHAR(2) COMPARE INPUT CHARACTER TO ENTRY IN
*                                  ALLOWABLE CHARACTER TABLE
         BE    CHIT                BRANCH IF CHARACTER VERIFIED
*                        CHARACTER MATCH NOT FOUND
CMISS    BCT   1,CCPOINTR+4        BRANCH IF ALL CODES NOT INVESTIGATED
*                        CHARACTER IS ILLEGAL
NOTLEGAL LTR   6,6                 TEST FOR COMMENTS FIELD
         BNE   NOEDIT              SKIP ERROR OUTPUT, ? SUBSTITUTION
         LA    5,8(0,0)            LOAD ERROR NUMBER IN GPR 5
         MVI   CHAR(3),X'6F'       INSERT '?' FOR ILLEGAL CHARACTER
         B     NOEDIT
*                        CHARACTER LEGALITY DETERMINED
CHIT     CH    1,HEXBR             COMPARE CHAR. TABLE INDEX TO BRANCH
         BH    NOEDIT              BRANCH IF CHAR. NOT BCD OR $
         BL    EDIT                BRANCH IF CHARACTER NOT $
         LA    6,1(0,0)            SET GPR 6 FOR COMMENTS FIELD
         B     NOEDIT
*                                  FOR '+'  '('  ')'  OR '='
EDIT     MVC   CHAR(1,3),EBCDIC(2) REPLACE BCDIC CODES WITH EBCDIC
         BCT   0,CCPOINTR-4        BRANCH IF 80 COLUMNS UNVERIFIED
*                        CARD IS TOTALLY VERIFIED
VERIFIED ST    5,N(0,4)            STORE N
         LM    1,6,SAVE+4*6(13)    RESTORE GPR 1-6
RETURN   BR    14                  EXIT VIA GPR 14
*
HEXBR    DC    H'5'
*
***********************************************************************
CHARTAB  DS    0C    *TABLE OF LEGITIMATE CARD PUNCHES*               *
***********************************************************************
CHAREND  DC    X'50'               BCDIC '+'                          *
         DC    X'4C'               BCDIC ')'                          *
         DC    X'6C'               BCDIC '('                          *
         DC    X'7B'               BCDIC '='                          *
*                                                                     *
         DC    C'$'                                                   *
         DC    C'+'               EBCDIC PUNCTUATION                  *
         DC    C')'                                                   *
         DC    C'('                                                   *
         DC    C'='                                                   *
         DC    C'/'                                                   *
         DC    C'-'                                                   *
         DC    C','                                                   *
         DC    C'.'                                                   *
         DC    C'*'                                                   *
*                                                                     *
         DC    C'9'                EBCDIC NUMERALS                    *
         DC    C'8'                                                   *
         DC    C'7'                                                   *
         DC    C'6'                                                   *
         DC    C'5'                                                   *
         DC    C'4'                                                   *
         DC    C'3'                                                   *
         DC    C'2'                                                   *
         DC    C'1'                                                   *
         DC    C'0'                                                   *
*                                                                     *
         DC    C'Q'                EBCDIC LETTERS                     *
         DC    C'H'                                                   *
         DC    C'I'                                                   *
         DC    C'W'                                                   *
         DC    C'V'                                                   *
         DC    C'U'                                                   *
         DC    C'M'                                                   *
         DC    C'E'                                                   *
         DC    C'R'                                                   *
         DC    C'Y'                                                   *
         DC    C'Z'                                                   *
         DC    C'O'                                                   *
         DC    C'B'                                                   *
         DC    C'T'                                                   *
         DC    C'D'                                                   *
         DC    C'K'                                                   *
         DC    C'J'                                                   *
         DC    C'X'                                                   *
         DC    C'P'                                                   *
         DC    C'F'                                                   *
         DC    C'G'                                                   *
         DC    C'C'                                                   *
         DC    C'L'                                                   *
         DC    C'A'                                                   *
         DC    C'S'                                                   *
         DC    C'N'                                                   *
CHARBGN  DC    C' '                'BLANK'                            *
***********************************************************************
*
***********************************************************************
*                    *ACHEDT SUBROUTINE EQUIVALENCES*                 *
***********************************************************************
ARGS     EQU   4*0
CHAR     EQU   1*0
EBCDIC   EQU   1*5
N        EQU   4*0
NOEDIT   EQU   EDIT+6
SAVE     EQU   4*0
*
***********************************************************************
***********************************************************************
         END

