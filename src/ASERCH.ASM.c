/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
*
         PRINT NOGEN
ASERCH   CSECT
         ENTRY SEARCH
         EXTRN FILETAB
         B     12(15)
         DC    AL1(7)
         DC    CL7'ASERCH '
SEARCH   STM   14,12,12(13)
         BALR  2,0
         USING *,2
         LR    15,13
         LA    13,SAVE
         ST    13,8(15)
         ST    15,4(13)
         L     3,0(1)
         LM    3,4,0(3)
         STM   3,4,DATASET
         CLI   DATASET+7,X'00'
         BE    IRET11
         L     10,=A(FILETAB)
         LA    11,7          7 = TOTAL NUMBER OF FTXXF001 WORK FILES
SRCFILE  CLC   DATASET+7(1),0(10)      FIND FILE BLOCK ENTRY FOR THIS
         BE    FNDFILE                 DATA REF.
         A     10,=F'20'
         BCT   11,SRCFILE
         B     NOFILE
FNDFILE  L     3,4(1)
         ST    10,BLKNUM+4
         CLC   DATASET+3(2),=H'0'      TEST FOR FRESH DATASET(NO MAX)
         BE    TESTNEW                 NO MAX MUST BE FRESH BRANCH
         CLI   12(10),X'01'            TEST STATUS OF FILE
         BH    INOPN                   OPERATING AS INPUT
         BE    REWIND                  OPERATING AS OUTPUT
TESTNEW  CLC   0(4,3),=F'1'            TEST IF SEARCHING FOR START OF
         BE    GOODARG                 FILE.BRANCH IF YES
         L     6,=F'1'
         B     NOREC                   OTHERWISE IND. ERROR
INOPN    CLC   2(2,3),DATASET+3         TEST ADDING NEXT RECORD
         BNE   FOPEN                   BRANCH IN CASE NO
         CLC   DATASET+1(2),DATASET+3       TEST FOR RITE POSITION
         BE    GOODARG                 BRANCH IF ALREADY RITE
         MVI   DFLAG,X'FF'              SET FLAG FOR ADDING RECORD
         L     3,0(3)                   DECREASE ARG TO FIND REAL
         S     3,=F'1'                  RECORD.
         B     POSIT
REWIND   CLC   2(2,3),DATASET+3        ARE WE ADDING NEXT RECORD
         BE    GOODARG                 EVERYTHING SET UP ALREADY
REW      LR    9,1                     MUST BE A READ COMING FOR THIS
         CALL  ATAPOP,(DATASET,ONE,RETCOD)   SEARCH CALL.DUMP BUFFER
         LR    1,9                     BY CALLING FOR REWIND
FOPEN    L     3,0(3)                  FILE OPEN NORMAL SEARCH
         LTR   3,3
         BP    POSIT
         LCR   3,3
         MVC   IRET(4),=F'1'
POSIT   CLI    DATASET,X'20'           TEST FOR REWOUND
        BNE    TABTST
        LR     9,1
         CALL  ABUFTP,(DATASET,TWO)    READ OVER LABEL
        LR     1,9
TABTST   L     4,0(10)                  GET TABLE BASE
         LH    5,4(10)                  GET TABLE DISPLACEMENT
         C     5,=F'392'                IS THIS LAST TABLE ENTRY
         BNE   START                    BRANCH IF NO
         L     6,0(4,5)
         SRL   6,16                     GET RECORD # FROM XREF TABLE
         L     7,396(4)                 GET POINTER TO NEXT TABLE
         C     7,ZERO                   IS THERE A NEXT TABLE
         BE    CORETST                  BRANCH IF NO
         L     7,0(7)
         SRL   7,16                     GET FIRST RECORD # IN BLOCK
         B     SUB1
START    L     6,0(4,5)
         SRL   6,16                     GET RECORD NUMBER IN THIS BLOCK
         L     7,4(4,5)
         SRL   7,16                     GET RECORD NUMBER IN NEXT BLOCK
         C     7,ZERO                   IS THIS END OF TABLE
         BE    CORETST                  BRANCH IF YES
SUB1     S     7,=F'1'                  COMPUTE LAST RECORD THIS BLOCK
CORETST  LTR   6,6
         BZ    CHASE
         CR    3,6                     TEST BLOCK IN CORE FOR RECORD
         BL    LOWER                    EARLIER BLOCK
         LTR   7,7                     IS THIS LAST BLOCK
         BZ    BLKTST                  IF SO TEST CORE FOR RECORD
         CR    3,7
         BH    HIGHER                   LATER BLOCK
BLKTST   L     11,8(10)                GET BUFFER ADDRESS
         S     11,=F'8'                GET BUFFER BLKNUM ADDRESS
         LH    12,2(4,5)               GET CORRELATION TABLE BLKNUM
         CH    12,0(11)                TEST FOR MATCH CRTBL AND BUFFER
         BNE   BRACK                   BLKNUM.  GET BLK ON MISMATCH
RESRT    L     11,=F'4'                 DISPLACE OVER BCW
         L     12,8(10)                 SEARCH BLOCK IN CORE FOR RECORD
TEST     LH    6,2(11,12)               GET SCW CODE
         CH    6,=H'256'                TEST FOR SINGLE OR FIRST SCW
         BH    AROUND                   BRANCH IF NOT
         L     6,4(11,12)               GET RECORD NUMBER
         CR    6,3                      IS THIS REQUESTED RECORD
         BE    THISONE                  BRANCH IF YES
AROUND   AH    11,0(11,12)              ADD SCW BYTE COUNT TO DISPLACE.
         CH    11,0(12)                 TEST FOR END OF BUFFER
         BL    TEST                     BRANCH IF NOT END
         STH   11,6(10)
         B     NOREC                    RECORD DOES NOT EXIST
THISONE  STH   11,6(10)                 STORE BUFFER DISPLACEMENT
         B     RETURN
LOWER    L     6,0(4)
         SRL   6,16                     TEST IF LOWER XREF TABLE NEEDED
         CR    3,6
         BL    CHASE                   LOWER TABLE NEEDED
BINARY   LA    7,4(5)                  BINARY SEARCH OF TABLE
HALF     SRA   7,1
         N     7,=X'FFFFFFFC'
         BZ    PREV
         SR    5,7
LOOPB    L     6,0(4,5)
         SRL   6,16                     GET RECORD # IN XREF ENTRY
         CR    3,6
         BL    HALF
         L     6,4(4,5)
         SRL   6,16                     GET RECORD # FROM NEXT ENTRY
         S     6,=F'1'                  DECREASE TO MAKE LAST THIS BLK
         CR    3,6
         BH    DOUBLE
         B     BRACK
DOUBLE   SRA   7,1
         N     7,=X'FFFFFFFC'
         BZ    NEXT
         AR    5,7
         B     LOOPB
PREV     S     5,=F'4'
         B     LOOPB
NEXT     A     5,=F'4'
         B     LOOPB
HIGHER   L     7,396(4)                 GET POINTER TO NEXT TABLE
         C     7,=F'0'                  WAS THIS LAST TABLE
         BE    BACKOFF                  BRANCH IF YES
         L     5,=F'392'                DISPLACEMENT=LAST TABLE ENTRY
         L     6,0(7)
         SRL   6,16                     COMPUTE LAST RECORD # IN
         S     6,=F'1'                  TABLE BEING TESTED.
         CR    3,6                      IS RECORD IN THIS TABLE
         BH    NXTAB                    NO,GET NEXT TABLE
         BE    BRACK                    RECORD STARTS IN THIS BLOCK
         L     7,0(4,5)
         SRL   7,16                     GET FIRST RECORD # IN LAST BLK
         CR    3,7                     COMPARE TO REQ. RECORD
         BL    BINARY                  BRANCH IF BELOW LAST BLOCK
         B     BRACK                   IN LAST BLOCK BRANCH
BACKOFF  L     5,=F'392'
LOOPDN L       6,0(4,5)
         C     6,ZERO
         BNE   T1
         S     5,=F'4'
         B     LOOPDN
T1       L     6,0(4,5)
         SRL   6,16                     GET RECORD # IN LAST XREF ENTRY
         CR    3,6                     IS REQESTED RECORD GREATER OR
         BL    BINARY                  EQ TO STARTING RECORD OF LAST
         B     BRACK                   BLOCK.BRACK IF YES.BINARY OTHER
NXTAB    L     4,396(4)
SAVEREF  IC    6,0(10)
         ST    4,0(10)
         STC   6,0(10)
         SR    5,5
         STH   5,4(10)
         B     HIGHER                  GET NEXT TABLE
CHASE    L     4,16(10)
         B     SAVEREF
BRACK    STH   5,4(10)                 TABLE ENTRY FOUND FOR RECORD
         LR    9,1
         LH    5,2(4,5)                 GET BLOCK NUMBER FROM TABLE
         ST    5,BLKNUM
         CALL  AEXCP,(BLKNUM)
         L     5,8(10)                 GET BUFFER BASE
         S     5,=F'8'                 GET BUFFER NUM ADDR
         MVC   0(2,5),BLKNUM+2         STORE BLOCK NUMBER
         LR    1,9
         L     12,8(10)
         B     RESRT
IRET11   L     3,8(1)
         MVC   0(4,3),=F'11'
         B     GOBCK
NOFILE   L     3,8(1)
         MVC   0(4,3),=F'14'
         B     GOBCK
NOREC    L     3,8(1)
         ST    6,0(3)                  OTHERWISE STORE MAX REC IN ERROR
         B     GOBCK                   ARG. OF CALLING ROUTINE
RETURN   CLI   DFLAG,X'00'
         BE    NORMAL
         A     3,=F'1'                  RESTORE SEARCH ARG FOR ADDING
         LH    4,6(10)                 USER IS LOOKING FOR NEXT
         L     5,8(10)                 AVAIL. POSITION IN FILE
TEST1    CH    4,0(5)
         BNE   FNDEND
         B     GETBLK
FNDEND   LA    6,2(4,5)
         AH    4,0(4,5)
         TM    0(6),X'01'
         BZ    THATSIT
         B     TEST1
THATSIT  STH   4,6(10)
         MVI   DFLAG,X'00'
         C     4,=F'2981'              IS THERE LRECL LEFT IN BUFFER
         BL    TSTFLG                  BR IF YES
         S     5,=F'8'                 SET UP WRITE FOR NEW BLOCK
         LH    6,0(5)
         A     6,=F'1'
         STH   6,0(5)
         MVI   TFLAG,X'00'             CLEAR SPAN FLAG
         LH    4,4(10)                 BUMP CROSSREF TABLE
         A     4,=F'4'
         STH   4,4(10)
         MVC   6(2,10),=H'4'           SET BUF DISP OVER BCW
         B     NORMAL
TSTFLG   CLI   TFLAG,X'FF'             ARE WE IN A NEW BLOCK
         BNE   NORMAL                  NO
         LH    4,4(10)                  BUMP CROSSREF TABLE
         A     4,=F'4'
         STH   4,4(10)
         MVI   TFLAG,X'00'
         B     NORMAL
GETBLK   S     5,=F'8'                 NEW BLOCK NEEDED FOR NEXT
         LH    4,0(5)                  POSITION IN FILE
         A     4,=F'1'
         STH   4,0(5)
         ST    4,BLKNUM
         LR    9,1
         CALL  AEXCP,(BLKNUM)
         LR    1,9
         MVI   TFLAG,X'FF'
         A     5,=F'8'
         L     4,=F'4'
         B     FNDEND
NORMAL   ST    3,RECCUR
         MVC   DATASET+1(2),RECCUR+2
         L     3,0(1)
         MVC   0(8,3),DATASET
         CLI   IRET+3,X'00'
         BE    GOODARG
         MVI   IRET+3,X'00'
         L     3,=F'1'
         B     STRET
GOODARG  L     3,=F'-1'
STRET    L     4,8(1)
         ST    3,0(4)
GOBCK    L     13,4(13)
         LM    14,12,12(13)
         BR    14
         LTORG
TWO      DC    F'2'
ZERO     DC    F'0'
RECCUR   DC    F'0'
SAVE     DC    18F'0'
DATASET  DC    2F'0'
IRET     DC    F'0'
BLKNUM   DC    2F'0'
ONE      DC    F'1'
RETCOD   DC    F'0'
DFLAG    DC    X'00'
TFLAG    DC    X'00'
         END
*/
