/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
         PRINT NOGEN
ATAPRD  CSECT
        EXTRN FILETAB
         ENTRY TAPERD
TAPERD   B     12(15)
         DC    AL1(7)
        DC    CL7'ATAPRD '
         STM   14,12,12(13)
         BALR  2,0
         USING *,2
         LR    15,13
         LA    13,SAVE
         ST    13,8(15)
         ST    15,4(13)
        ST    1,SAVE1
        L     3,0(1)
        LM    3,4,0(3)
        STM   3,4,DATASET
        CLI   DATASET+7,X'00'
        BE    IRET11
        CALL  ABUFTP,(DATASET,TWO)
        L     1,SAVE1
         L     10,=A(FILETAB)
         LA    11,7          7 = TOTAL NUMBER OF FTXXF001 WORK FILES
SRCFILE  CLC   DATASET+7(1),0(10)      FIND FILE BLOCK ENTRY FOR THIS
         BE    FNDFILE                 DATA REF.
         A     10,=F'20'
         BCT   11,SRCFILE
         B     NOFILE
FNDFILE L     3,12(1)                 GET ARRAY COUNT
        L     3,0(3)
        LH    11,6(10)
        L     12,8(10)
        L     4,16(1)
         AR    11,12                    COMPUTE BUFFER POINTER
         LH    6,0(12)
         AR    6,12                     COMPUTE BLOCK END IN BUFFER
         CR    11,6
         BL    RECSTR                   IS A NEW BLOCK NEEDED
         BAL   12,NEWBLK                GET A NEW BLOCK
         BAL   12,NXTTAB               GO BUMP DISP IN CROSS REF TABLE
         L     12,8(10)
         LH    6,0(12)
         AR    6,12                     COMPUTE BLOCK END IN BUFFER
         A     11,=F'4'                BUMP BUF POINTER OVER BCW
RECSTR   LH    5,0(11)                  GET SEGMENT BYTE COUNT
         MVC   RECNUM(4),4(11)          SAVE RECORD NUMBER
         S     5,=F'4'                  DECREASE COUNT FOR SCW
         CLI   1(11),X'10'              IS THERE 3 FULL WORDS IN SEG.
         BL    OVREAD                   NO
         CLC   8(4,11),EOD             YES,TEST FOR TRAILER LABEL
         BE    EODRTN                   BRANCH IF TRAILER
         L     8,4(1)                   SET NORMAL RETURN CODE IN
         MVI   0(8),X'80'               CALLING PROGRAM.
         C     3,=F'11'                 ARE THERE MORE THAN TEN ARRAYS
         BL    LESS                     BRANCH IF NO
         L     3,=F'10'                 SET NUMBER OF ARRAYS TO TEN
         ST    3,IRET12                 SET ERROR CODE
LESS     L     12,=F'3'                 SET NUMBER OF FULL WORDS
         LR    8,11                     SAVE ADDRESS OF SCW
         SR    7,7                      SET PARA. LIST DISPLACEMENT
GETCT    L     9,20(7,1)                GET ARRAY BYTE COUNT
         L     9,0(9)
         LTR   9,9
         BM    FMINUS
         BZ    FZERO
STFULL   MVC   0(4,4),4(11)             MOVE WORD FROM BUFFER TO ARRAY
         A     4,=F'4'                  BUMP ARRAY ADDRESS
         A     11,=F'4'                 BUMP BUFFER POINTER
         S     5,=F'4'                  DECREASE SEGMENT BYTE COUNT
         BCT   12,NXFULL                DECREASE FULL WORD COUNT
         B     FULL                     BRANCH,ALL FULL WORDS MOVED
NXFULL   BCT   9,STFULL                 BRANCH BACK IF ARRAY NOT EMPTY
         A     7,=F'8'                  ARRAY EMPTY,GET NEXT ARRAY
         L     4,16(7,1)                GET ARRAY ADDRESS
         BCT   3,GETCT                  BRANCH IF ANOTHER ARRAY
         B     DONE                     NO MORE ARRAYS
FULL     BCT   9,STMOVE                 BRANCH IF DOUBLE WORDS IN ARRAY
NEWARRY  BCT   3,BUMP                   BRANCH IF ANOTHER ARRAY
         B     DONE                     NO MORE ARRAYS
BUMP     A     7,=F'8'                  BUMP PARA.LIST DISPLACEMENT
         L     4,16(7,1)                GET ARRAY ADDRESS
         L     9,20(7,1)                GET ARRAY BYTE COUNT
         L     9,0(9)
         LTR   9,9
         BM    DMINUS
         BZ    DZERO
STMOVE   ST    9,SAVECNT                SAVE WORD COUNT
         SLA   9,3                      CHANGE TO BYTE COUNT
TESTSEG  CR    9,5                      WILL ARRAY OVERFLOW SEGMENT
         BH    SEGOVFL                  BRANCH IF YES
MOVEIT   S     9,=F'1'                  MOVE SEGMENT INTO ARRAY
         EX    9,MOVE
         A     9,=F'1'
         SR    5,9                      DECREASE SEG. BYTE COUNT
         AR    11,9                     BUMP BUFFER POINTER
         B     NEWARRY                  GO GET NEXT ARRAY
SEGOVFL  TM    2(8),X'01'               WILL ARRAY OVERFLOW RECORD
         BZ    OVREAD                   BRANCH IF YES FOR ERROR
         LTR   5,5                      IS CURRENT SEG EMPTY
         BZ    NEWSEG                   BRANCH IF YES
         S     5,=F'1'
         EX    5,MOVE                   MOVE SEGMENT TO ARRAY
         A     5,=F'1'
         SR    9,5                      DECREASE ARRAY BYTE COUNT
         AR    4,5
         AR    11,5
NEWSEG   A     11,=F'4'                BUMP BUF OVER SCW
         CR    11,6                    IS A NEW BLOCK NEEDED
         BL    SAVSEG                   BRANCH IF NO
         BAL   12,NEWBLK                GET NEXT BLOCK
         MVI   TFLAG,X'FF'             SET FLAG FOR BUMPING CROSS REF
         L     12,8(10)
         LH    6,0(12)
         AR    6,12                     COMPUTE BLOCK LIMIT
         A     11,=F'4'                BUMP BUF FOR BCW
SAVSEG   LR    8,11                     SAVE SCW ADDRESS
         LH    5,0(8)                   GET SEG BYTE COINT
         S     5,=F'4'                  DECREASE BY LENGTH OF SCW
         B     TESTSEG
DZERO    MVI   ZERFLG,X'FF'             SET FLAG FOR DOUBLE WORD ENTRY
         B     TEST5
FZERO    MVI   ZERFLG,X'00'             SET FLAG FOR FULL WORD ENTRY
TEST5    LTR   5,5                      IS CURRENT SEG EMPTY
         BZ    SEGEMPT                  BRANCH IF YES
MOVESEG  S     5,=F'1'
         EX    5,MOVE                   MOVE SEGMENT TO ARRAY
         A     5,=F'1'
         AR    9,5                      BUMP ARRAY COUNT
         AR    11,5                     BUMP BUFFER POINTER
         AR    4,5                      BUMP ARRAY ADDRESS
         SR    5,5                     NOTE SEG AS EMPTY
SEGEMPT  TM    2(8),X'01'               IS LAST DATA MOVED
         BZ    ARRYFUL                  BRANCH IF YES
         A     11,=F'4'                BUMP BUF OVER SCW
         CR    11,6                     IS NEXT BLOCK NEEDED
         BL    BUFOK                    NO
         BAL   12,NEWBLK                GET NEXT BLOCK
         MVI   TFLAG,X'FF'             SET FLAG FOR BUMPING CROSS REF
         L     12,8(10)
         LH    6,0(12)
         AR    6,12                     COMPUTE BLOCK END
         A     11,=F'4'                BUMP BUF OVER BCW
BUFOK    LR    8,11                     SAVE SCW ADDRESS
         LH    5,0(8)                   GET SEGMENT BYTE COUNT
         S     5,=F'4'                  DECREASE BY SCW LENGTH
         B     MOVESEG
ARRYFUL  LTR   9,9                      WAS DATA MOVED
         BZ    NODATA                   BRANCH IF NO
         CLI   ZERFLG,X'FF'
         BE    DOUBLE
         SRA   9,2                      CHANGE TO FULL WORD COUNT
         B     STCNT
DOUBLE   SRA   9,3                      CHANGE TO DOUBLE WORD COUNT
STCNT    ST    9,SAVECNT
         B     DONE
FMINUS   LCR   9,9                      MAKE PLUS
         ST    7,IREC                   SET ERROR
         B     STFULL
DMINUS   LCR   9,9                      MAKE PLUS
         ST    7,IREC                   SET ERROR
         B     STMOVE
OVREAD   L     12,=F'10'                USER REQUESTED MORE DATA THAN
         AR    12,7                     WAS IS RECORD.SET ERROR FLAG
         ST    12,IREC
         LTR   5,5                      IS SEGMENT EMPTY
         BZ    DONE                     BRANCH IF YES
         S     5,=F'1'
         EX    5,MOVE                   MOVE CURRENT SEGMENT TO ARRAY
         A     5,=F'1'
         AR    9,5                      INCREASE ARRAY BYTE COUNT
         SRA   9,3                      MAKE DOUBLE WORD COUNT
         ST    9,SAVECNT
DONE     A     11,=F'4'                 BUMP BUFFER POINTER OVER SCW
         LTR   5,5                      TEST SEGMENT BYTE COUNT
         BZ    RETURN
CHASE    AR    11,5                     FLUSH REST OF RECORD SO NEXT
         TM    2(8),X'01'               RECORD IS POSITIONED FOR READ.
         BZ    RETURN
         CR    11,6
         BL    NXTSCW
         BAL   12,NEWBLK
         MVI   TFLAG,X'FF'             SET FLAG FOR BUMPING CROSS REF
         L     12,8(10)
         LH    6,0(12)
         AR    6,12
         A     11,=F'4'
NXTSCW   LR    8,11
         LH    5,0(8)
         B     CHASE
NODATA   ST    9,SAVECNT
         A     11,=F'4'                BUMP TO NEXT SCW
RETURN   L     6,RECNUM                 UPDATE RECORD NUMBER IN DATASET
         A     6,=F'1'
         ST    6,RECNUM
         CLI   TFLAG,X'FF'             DID WE GET A NEW BUFFER
         BNE   SETDISP                 BRANCH IF NO
         BAL   12,NXTTAB               GO BUMP DISP IN CROSS REF TABLE
         MVI   TFLAG,X'00'             CLEAR FLAG
SETDISP  S     11,8(10)                BUF DISP=POINTER-BUF BASE
         STH   11,6(10)                STORE BUF DISP OF NEXT RECORD
SETDS    MVC   DATASET+1(2),RECNUM+2
         L     3,0(1)
         MVC   0(8,3),DATASET           RESGORE DATASET TO USER
         L     7,IREC                   TEST FOR ERRORS
         C     7,ZERO
         BE    SAVEST
         SRA   7,3
         A     7,=F'21'
         L     3,4(1)
         ST    7,0(3)
         MVC   IREC(4),ZERO
SAVEST   CLC   IRET12(4),ZERO
         BE    BOK
         L     3,4(1)
         MVC   0(4,3),=F'12'
         MVC   IRET12(4),ZERO
BOK      L     8,8(1)
         MVC   0(4,8),SAVECNT           PASS COUNT BACK TO USER
         B     GOBCK
EODRTN   MVC   DATASET+1(2),RECNUM+2    TRAILER LABEL REACHED
         L     6,4(1)
         MVC   0(4,6),ZERO
         L     6,0(1)
         MVC   0(8,6),DATASET
GOBCK    L     13,4(13)
         LM    14,12,12(13)
         BR    14
NEWBLK   ST    1,SAVE1                  GET NEXT BLOCK INTO CORE
         L     6,8(10)
         S     6,=F'8'
         LH    5,0(6)
         A     5,=F'1'
         ST    5,BLKNUM
         ST    10,BLKNUM+4
         STH   5,0(6)
         CALL  AEXCP,(BLKNUM)
         L     11,8(10)
         L     1,SAVE1
         BR    12
NXTTAB   LH    15,4(10)                GET CROSS REF TABLE DISP
         C     15,=F'392'              TEST FOR END OF THIS TABLE
         BE    NEWTAB                  BRANCH IF YES
         A     15,=F'4'                BUMP TABLE DISP
         STH   15,4(10)                STORE NEW DISP
         BR    12
NEWTAB   L     15,0(10)                GET OLD TABLE BASE
         CLC   397(3,15),ZERO          IS THERE ANOTHER XREF TABLE
         BE    NOXREF                  BRANCH IF NO
         MVC   1(3,10),397(15)         MOVE NEW BASE INTO FCB
         MVC   4(2,10),=H'0'           RESET DISP
         BR    12
NOXREF   MVC   4(2,10),=H'396'         SET XREF DISP TO 396
         BR    12
IRET11   L     3,4(1)
         MVC   0(4,3),=F'11'
         B     GOBCK
NOFILE   L     3,4(1)
         MVC   0(4,3),=F'14'
         B     GOBCK
         LTORG
SAVE     DC    18F'0'
SAVE1    DC    F'0'
DATASET  DC    2F'0'
TWO      DC    F'2'
RECNUM   DC    F'0'
IRET12   DC    F'0'
SAVECNT  DC    F'0'
IREC     DC    F'0'
ZERO     DC    F'0'
EOD      DC    C'APTE'
BLKNUM   DC    2F'0'
MOVE     MVC   0(0,4),4(11)
ZERFLG   DC    X'00'
TFLAG    DC    X'00'
         END
*/
