/*

*  ASMBLR

*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***

*

         PRINT NOGEN

ABUFTP  CSECT

         EXTRN FILETAB,DCBTAB

         ENTRY BUFFTP

BUFFTP   B     12(15)

         DC    AL1(7)

        DC    CL7'ABUFTP '

         STM   14,12,12(13)

         BALR  2,0

         USING *,2

         LR    15,13

         LA    13,SAVE

         ST    13,8(15)

         ST    15,4(13)

         L     10,=A(FILETAB)

         LA    11,7          7 = TOTAL NUMBER OF FTXXF001 WORK FILES

        L     3,0(1)

SRCFILE CLC   0(1,10),7(3)            FIND FILE BLOCK ENTRY FOR THIS

         BE    FNDFILE                 DATA REF.

         LA    10,20(10)

         BCT   11,SRCFILE

        B     GOBCK

FNDFILE ST    1,SAVE1

         ST    10,BLKCNT+4

         ST    10,ONE+4

        LM    3,4,0(3)

        STM   3,4,DATASET

        L     5,4(1)                  TEST CALL TYPE

        CLI   3(5),X'02'

        BL    WRITE

        BE    READ

        CALL  ATAPOP,(DATASET,ONE,RET)

        B     RETURN

WRITE   CLC   DATASET+1(2),ZERO       IS CURRENT RECORD ZERO

         BNE   TESTADD                 BRANCH IF NONZERO

WTMODCK CLI   DATASET,X'40'           IS CURRENT MODE WRITE

        BE    GOBCK                   NOP IF YES

         CLI   12(10),X'02'

         BNE   GETBUF

         MVC   4(4,10),ZERO

         CLI   16(10),X'00'

         BE    ONETAB

         L     1,16(10)

         SR    3,3

         IC    3,16(10)

FREELP   L     1,396(1)

         BCT   3,FREELP

         FREEMAIN R,LV=400,A=(1)

         IC    3,16(10)

         C     3,=F'1'

         BE    ONETAB

         S     3,=F'1'

         STC   3,16(10)

         L     1,16(10)

         B     FREELP

ONETAB   MVI   16(10),X'00'

         MVC   1(3,10),17(10)

         L     1,16(10)

         MVI   0(1),X'00'

         MVC   1(255,1),0(1)

         MVC   256(144,1),255(1)

         L     6,8(10)

         S     6,=F'8'

         MVC   0(2,6),=H'1'            SET BUFFER BLOCK COUNT TO ONE

         L     6,=A(DCBTAB)

         L     9,8(10)

         B     FNDDCB

GETBUF  L     6,=A(DCBTAB)

         GETMAIN R,LV=3240             GET A BUFFER

         MVC   0(2,1),=H'1'             SET BUFFER BLOCK COUNT TO ONE

         A     1,=F'8'                  ADJUST BUFFER ORIGIN

        ST    1,8(10)                 STORE ADDRESS IN FB

        MVC   4(2,10),ZERO            RESET BUFFER COUNTER IN FB

        GETMAIN R,LV=400              GET A TABLE

        MVI   0(1),X'00'              CLEAR TABLE

        MVC   1(255,1),0(1)

        MVC   256(144,1),255(1)

        L     9,8(10)                 GET BUFFER ADDRESS

        N     1,=X'00FFFFFF'          CLEAR GET MAIN COUNT

         ST    1,16(10)

        MVC   1(3,10),17(10)          SET TABLE BASE = FIRST TABLE

FNDDCB  CLC   DATASET+7(1),0(6)       FIND DATAREF DCB

        BE THISDCB

         LA    6,12(6)

        B     FNDDCB

THISDCB CLI   3(5),X'02'

        BE    RDMODE                  BRANCH IF READ

         MVC   4(24,9),LABEL            MOVE IN HEADER LABEL

         MVC   19(1,9),DATASET+7

         MVC   6(2,10),=H'28'

         CLI   12(10),X'00'

         BE    UCBTST

         L     3,12(10)

         TM    17(3),X'81'

         BO    TAPE1

DISK1    L     3,4(6)

         ST    3,12(10)

         TM    48(3),X'10'

         BZ    OPEND

         L     1,12(10)

         LA    0,=F'1'

         POINT (1),(0)

         B     RETURN

OPEND    OPEN  ((3),(OUTPUT))

         B     RETURN

TAPE1    MVI   12(10),X'01'

         L     3,12(10)

         CLOSE ((3),REREAD),TYPE=T

         B     RETURN

RDMODE   MVC   DATAREF+7(1),0(10)  FILE BEING OPEN FIRST TIME AS A READ

UCBTST   MVI   FTCARD+2,X'F0'

         CLI   0(10),X'0A'   TEST IF DATASET REFERENCE GREATER THAN 9

         BL    NORMAL

         BH    DUMPDD

*        BNE   FILE11

         MVC   FTCARD+2(2),FILE10C

         B     UCBT

FILE10C  DC    C'10'

*---------------------------------------------------------------------

*FILE11  CLI   0(10),X'0B'             ******

*        BNE   FILE12                  *

*        MVC   FTCARD+2(2),FILE11C     *     SAMPLE CODE TO SUPPORT

*        B     UCBT                    *     MORE FTXXF001 WORK FILES

*FILE11C DC    C'11'                   ******

*----------------------------------------------------------------------

NORMAL   NI    FTCARD+3,X'F0'

         OC    FTCARD+3(1),0(10)

UCBT     SR    11,11

         L     3,16

         L     3,0(3)

         L     3,4(3)

         L     9,12(3)

TIOTSR   CLC   FTCARD,28(9)

         BE    TIOT

         IC    11,24(9)

         AR    9,11

         CLI   24(9),X'00'              TEST IS THERE ANOTHER ENTRY

         BNE   TIOTSR                   BRANCH IF YES

DUMPDD   MVC   NODDMSG+14(2),FTCARD+2   TERMINATE. USER MISSING DD CARD

WRITEMSG LM    4,5,ATAPTBAD

         MVC   IOUTAP(4),84(4)

         MVC   0(4,5),=X'00FFFFFF'

         CNOP  0,4

         L     15,=V(IBCOM#)

         BAL   14,4(15)

         DC    XL1'1',AL3(IOUTAP)

         DC    AL4(NODDMSG)

         BAL   14,16(15)

         L     15,=V(APTTRU)            TERMINATE JOB

         BR    15

IOUTAP   DC    F'0'

NODDMSG  DC    X'021A29'

         DC    CL41' MISSING FT00F001 DD CARD. JOB CANCELED. '

         DC    X'1E22'

TIOT     L     11,40(9)

         CLI   3(5),X'02'

         BE    INNER

         CLI   18(11),X'80'

         BNE   DISK1

         L     3,92(6)

         ST    3,12(10)

         MVI   12(10),X'01'

         OPEN  ((3),(OUTIN))

         B     RETURN

INNER    CLI   18(11),X'80'

         BE    TAPEIN

         L     3,8(6)

         B     OPENIN

TAPEIN   L     3,92(6)

         OPEN  ((3),(INOUT))

         B     GETONE

OPENIN   OPEN  ((3),(INPUT))

GETONE   ST    3,12(10)

         CALL  AEXCP,(ONE)

        L     9,8(10)

         CLC   DATAREF(7),12(9)

        BE    RITEFIL                 BRANCH IF YES

WTOMSG   WTO   'APT MSG: WRONG FILE MOUNTED.JOB CANCELED'

         MVC   NODDMSG+4(40),WTOMSG+8

         B     WRITEMSG

RITEFIL  LA    12,2(0)                  SET UP TO GET NEXT BLOCK

         L     5,0(10)                  GET TABLE BASE ADDRESS

         MVC   0(4,5),=F'1'             FIRST ENTRY RECORD ZERO,BLOCK 1

         LA    4,99(0)                  SET TABLE LIMIT

         A     5,=F'4'                  BUMP TABLE ADDRESS

         LR    11,9                     SAVE BCW ADDRESS IN GR9

         LH    3,0(9)                  GET BYTE COUNT THIS BLOCK

         AR    3,9                     ADD IN BLOCK ORG.

         A     11,=F'4'                 BUMP BUFFER ADDRESS OVER BCW

FORMTB   LH    6,0(11)                  GET SEG BYTE COUNT

         LH    7,2(11)                  GET SCW CODE

EODTST   CLC   8(8,11),EOD              TEST FOR TRAILER LABEL

         MVC   DATASET+3(2),6(11)

         BE    ENDATA                   BRANCH IF LABEL

         AR    11,6                     BUMP BUFFER ADDRESS OVEF SEG

         CR    11,3                    TEST FOR BUFFER LIMIT

         BL    FORMTB                   BRANCH IF NOT END OF BUFFER

NEXTBLK  BCT   4,GETBLK                 GET NEXT BLOCK IF ROOM IN TABLE

         B     NEWTB                    GET A NEW TABLE

GETBLK   ST    12,BLKCNT

         CALL  AEXCP,(BLKCNT)           GET BLOCK INTO CORE

         A     12,=F'1'                 BUMP BLOCK NUMBER

         LR    11,9                     PUT BCW ADDRESS IN GR11

         LH    3,0(9)                  GET BYTE COUNT THIS BLOCK

         AR    3,9                     ADD IN BLOCK ORG.

         A     11,=F'4'                 BUMP BUFFER TO FIRST SCW

LOOPTHU  LH    6,0(11)                  GET SEGMENT BYTE COUNT

         CLI   2(11),X'01'              IS THIS FIRST OR ONLY SCW

         BH    TESTEND                  BRANCH IF NO

         MVC   0(2,5),6(11)             MOVE RECORD NUMBER INTO TABLE

         MVC   2(2,5),BLKCNT+2          MOVE BLOCK NUMBER INTO TABLE

         A     5,=F'4'                  BUMP TABLE ADDRESS

         B     EODTST                   GO TEST FOR TRAILER LABEL

TESTEND  AR    11,6                     BUMP BUFFER TO NEXT SCW

         CR    11,3                    TEST FOR BUFFER LIMIT

         BL    LOOPTHU                  BRANCH BACK IF NOT END

         B     GETBLK                   GO GET NEXT BLOCK

NEWTB    GETMAIN R,LV=400               GET NEW TABLE

         ST    1,0(5)                   POINT OLD TABLE TO NEW TABLE

         LR    5,1                      SET NEW TABLE ADDRESS

         IC    4,0(10)

         ST    1,0(10)                  STORE IN FILE CONTROL BLOCK

         STC   4,0(10)

         IC    4,16(10)

         A     4,=F'1'                  BUMP GETMAIN COUNT

         STC   4,16(10)

         MVI   0(5),X'00'               CLEAR NEW TABLE

         MVC   1(255,5),0(5)

         MVC   256(144,5),255(5)

         LA    4,99(0)                  SET TABLE LIMIT

         B     GETBLK                   GO GET NEW BLOCK

READ    CLI   DATASET,X'00'           IS THIS FILE OPEN

        BE    GETBUF                  IF NO GO FORM TABLE

        CLI   DATASET,X'80'           WAS LAST ACTION READ

        BE    RETURN

        CLI   DATASET,X'40'           WAS LAST ACTION WRITE

        BNE   RDOVER                  IF NO MUST BE REWOUND

ENDATA  CALL  ATAPOP,(DATASET,ONE,RET) REWIND FILE

RDOVER   CALL  AEXCP,(ONE)

         MVC   6(2,10),=H'28'           BUMP DISPLACEMENT OVER LABEL

         L     1,8(10)

         S     1,=F'8'                  SET BUFFER BLOCK COUNT TO ONE

         MVC   0(2,1),=H'1'

RETURN  L     1,SAVE1

        L     5,4(1)

        L     6,0(1)

        MVC   0(8,6),DATASET

        CLI   3(5),X'02'

        BL    SETWT

        BE    SETRD

        B     GOBCK

SETWT MVI 0(6),X'40'

        B     GOBCK

SETRD   MVI   0(6),X'80'

GOBCK   L     13,4(13)

        LM    14,12,12(13)

        BR    14

TESTADD  CLI   DATASET,X'40'

         BE    RETURN

         CLC   DATASET+1(2),DATASET+3

         BNL   NOUPDATE

         SR    7,7

         L     3,0(10)

         LH    4,4(10)

         L     5,396(3)

         LTR   5,5

         BZ    ENDCHASE

         L     6,396(5)

FREE1    LR    1,5

         FREEMAIN R,LV=400,A=(1)

         LA    7,1(7)

         LTR   6,6

         BZ    ENDCHASE

         LR    5,6

         L     6,396(6)

         B     FREE1

ENDCHASE SR    6,6

         IC    6,16(10)

         SR    6,7

         STC   6,16(10)

         LA    5,4(3,4)

         LA    6,400(3)

         SR    6,5

         SRL   6,2

         SR    7,7

ZEROTBL  ST    7,0(5)

         LA    5,4(5)

         BCT   6,ZEROTBL

NOUPDATE CLC   6(2,10),=H'2981'         LEO BUFFER SIZE-249

         BL    GETADCB

NOTUP1   L     5,8(10)

         S     5,=F'8'

         LH    6,0(5)

         A     6,=F'1'

         STH   6,0(5)

         LH    4,4(10)

         L     6,0(10)

         L     6,0(6,4)

         C     6,ZERO

         BE    NOBUMP

         A     4,=F'4'

         STH   4,4(10)

NOBUMP   MVC   6(2,10),=H'4'

GETADCB  L     6,=A(DCBTAB)

WHATDCB  CLC   DATASET+7(1),0(6)       FIND FILE DCB

         BE    THATDCB

         LA    6,12(6)

         B     WHATDCB

THATDCB  L     1,12(10)

         TM    17(1),X'81'

         BO    TAPEOLD

         CLC   DATASET+1(2),DATASET+3

         BNL   NOUP2

         L     1,8(6)

         MVC   BBCCHHR(8),5(1)

         L     1,44(1)

         L     15,16

         L     15,32(15)

         ST    13,SAVE13

         LR    3,2

         LA    2,BBCCHHR

         BALR  14,15

         LR    2,3

SKIP     L     13,SAVE13

         SRL   0,8

         IC    7,0(6)

         ST    0,0(6)

         STC   7,0(6)

         L     10,ONE+4

NOUP2    L     3,4(6)

         ST    3,12(10)

         TM    48(3),X'10'

         BO    GETTTR

         OPEN  ((3),(OUTPUT))

GETTTR   L     0,0(6)

         SLL   0,8

         C     0,ZERO

         BNE   STORETTR

         L     0,TTR001

STORETTR ST    0,TTR

         POINT (3),TTR

         B     RETURN

TAPEOLD  LM    5,6,8(10)     ADDR OF BUFFER AND DCB FROM FCB

         MVI   12(10),X'01'

         S     5,=F'8'

         L     7,12(6)       DCB BLK COUNT

         LA    7,1(7)        ADD 1

         SH    7,0(5)        # OF BLOCKS TO BACKSPACE ON TAPE

         BZ    RETURN

         CNTRL (6),BSR,(7)

         B     RETURN

        LTORG

ATAPTBAD DC    V(ATAPTB,AOUTFG)

SAVE13   DC    F'0'

BBCCHHR  DC    2F'0'

SAVE1   DC    F'0'

SAVE    DC    18F'0'

TTR001   DC    F'256'

DATASET DC    2F'0'

ONE     DC    F'1'

         DC    F'0'

RET     DC    F'0'

ZERO    DC    F'0'

LABEL    DC    H'24'

        DC    H'00'

         DC    F'0'

        DC    C'APTDATA0'

        DC    2F'0'

DATAREF DC    C'APTDATA0'

BLKCNT   DC    2F'0'

TTR      DC    F'0'

EOD     DC    C'APTEFILE'

FTCARD   DC    C'FT00F001'

        END

*/

