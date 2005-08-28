*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
         PRINT NOGEN
ATAPOP  CSECT
        EXTRN FILETAB,DCBTAB
         ENTRY TAPEOP
TAPEOP   B     12(15)
         DC    AL1(7)
        DC    CL7'ATAPOP '
         STM   14,12,12(13)
         BALR  2,0
         USING *,2
         LR    15,13
         LA    13,SAVE
         ST    13,8(15)
         ST    15,4(13)
        ST    1,SAVE1
         L     10,=A(FILETAB)
         LA    11,7          7 = TOTAL NUMBER OF FTXXF001 WORK FILES
         L     3,0(1)
         MVC   DATASET(8),0(3)
SRCFILE  CLC   DATASET+7(1),0(10)      FIND FILE BLOCK ENTRY FOR THIS
         BE    FNDFILE                 DATA REF.
         A     10,=F'20'
         BCT   11,SRCFILE
         B     NOFILE
FNDFILE L     3,8(1)
        MVI   0(3),X'80'
         L     3,4(1)                  TEST ENTRY TYPE
        CLI   3(3),X'01'
        BE    REWIND
        CLI   3(3),X'02'
        BE    EOF
        CLI   3(3),X'03'
        BE    BKSPC
        L     3,8(1)                  ERROR
        MVC   0(4,3),ZERO
        B     RETURN
BKSPC    MVC   CURRNT(2),DATASET+1     GET CURRENT RECORD NUMBER
        LH    4,CURRNT                TEST FOR START OF DATA
        C     4,ZERO
        BE    RETURN
        S     4,=F'1'
        BZ    RETURN
        STH   4,CURRNT
         CALL  ASERCH,(DATASET,BSREC1,IRC)  LET ASERCH BACKSPACE
        B     RETURN
EOF     MVC   LABEL1+2(2),DATASET+1   FORM TRAILER LABEL
        MVC   LABEL2+6(2),DATASET+1
        CALL  ATAPWT,(DATASET,IRC,TWO,LABEL1,THREE,LABEL2,ONE)
        MVC   DATASET+3(2),LABEL1+2   SET MAX COUNT IN DATASET
        B     RETURN
REWIND  CLI   12(10),X'00'            IS FILE ACTIVE
        BE    RETURN                  RETURN IF NOT
        CLI   12(10),X'01'            IS FILE OUTPUT
        BE    OUTPUT
RESET   MVI   DATASET,X'20'
        MVC   DATASET+1(2),ZERO       MAKE CURRENT REC ZERO
        MVC   1(3,10),17(10)
        MVC   4(4,10),ZERO
         L     3,12(10)
         TM    17(3),X'81'
         BO    TCLOSE
         B     RETURN
TCLOSE   CLOSE ((3),REREAD),TYPE=T
        B     RETURN
OUTPUT   L     7,8(10)                 GET BUFFER BASE ADDRESS
         MVC   0(2,7),6(10)            FORM BCW BYTE COUNT
         MVC   2(2,7),ZERO             COMPLETE BCW
         L     3,12(10)
         L     8,8(10)
         MVI   DECB,X'00'
         WRITE DECB,SF,(3),(8)
         CHECK DECB
         L     1,12(10)
         TM    17(3),X'81'
         BO    TAPE
         NOTE  (1)
        L     7,=A(DCBTAB)            GET BISAM INPUT DCB ADDRSS
         B     DCBLOOP
TAPE     L     7,=A(DCBTAB)
         LA    7,84(7)        84= DISP TO TAPE ENTRIES IN DCBTAB
DCBLOOP CLC   0(1,7),0(10)
        BE    THISDCB
        A     7,=F'12'
        B     DCBLOOP
THISDCB MVC 12(4,10),8(7)             PUT DCB ADDRESS IN FILE BLOCK
         MVI   12(10),X'02'
         TM    17(3),X'81'
         BO    RESET
         IC    0,0(7)
         SRL   1,8
         ST    1,0(7)
         STC   0,0(7)
OPIN     L     3,12(10)
         TM    48(3),X'10'             TEST IF DCB ALREADY OPEN
         BO    RESET                   BRANCH IF YES
        OPEN  ((3),(INPUT))           OPEN AS BISAM INPUT
        B     RESET
RETURN  L     1,SAVE1
        L     3,0(1)
        MVC   0(8,3),DATASET
GOBCK   L     13,4(13)
        LM    14,12,12(13)
        BR    14
NOFILE  L     3,8(1)
        MVC   0(4,3),=F'1'
        B     GOBCK
        LTORG
SAVE    DC    18F'0'
SAVE1   DC    F'0'
DATASET DC    2F'0'
ZERO    DC    F'0'
BSREC1   DC    H'0'
CURRNT  DC    H'0'
IRC     DC    F'0'
LABEL1  DC    F'0'
        DC    C'APTEFILE'
LABEL2  DC    C'        '
TWO     DC    F'2'
THREE   DC    F'3'
ONE     DC    F'1'
        END

