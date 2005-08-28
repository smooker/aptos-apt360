/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
         PRINT NOGEN
SAM      CSECT
        ENTRY FILETAB,DCBTAB
         ENTRY AEXCP
AEXCP    B     12(15)
         DC    AL1(7)
         DC    CL7'AEXCP  '
         STM   14,12,12(13)
         BALR  2,0
         USING *,2
         LR    15,13
         LA    13,SAVE
         ST    13,8(15)
         ST    15,4(13)
RETRY    MVI   SRCADDR,X'00'
         L     3,0(1)
         L     1,0(3)
         L     10,4(3)
         ST    10,DUMMY            SAVE INPUT DCB ADDRESS
         L     11,12(10)                GET INPUT DCB AND TEST DEVTYP
         L     9,44(11)                FIND DEVICE TYPE IN UCB
         L     9,32(9)
         CLI   18(9),X'80'
         BE    T2400
         CLI   18(9),X'20'
         BNE   IOERR
         CLI   19(9),X'01'
         BE    D2311
         CLI   19(9),X'08'
         BE    D2314
         CLI   19(9),X'04'
         BE    D2302
         CLI   19(9),X'03'             TEST FOR 2303
         BE    D2311
         MVC   WRTCCW(4),8(10)         MOVE IN BUFFER ADDR READ COMING
         LA    9,DCBTAB            FIND INPUT DCB ADDRESS
DCBLOOP  CLC   0(1,10),0(9)
         BE    DCBFOND
         A     9,=F'12'
         B     DCBLOOP
DCBFOND  L     9,4(9)              SET ARG TO USER RTN
         ST    9,OUTDCB
         ST    10,FCBENTRY
         ST    11,INDCB
         L     12,44(11)
         ST    12,INDEB
         ST    1,BLKNUM
         LA    1,INDEB             LOAD PARAMETER REGISTER
         CALL  USERTN
         SR    3,3
         IC    3,RECNUM+3
         S     3,=F'1'
         STC   3,SRCADDR
         MVC   CNTADDR(1),RECNUM+3
         MVC   IOB+39(1),RECNUM+3
         MVC   12(1,11),RECNUM+3
         L     3,EXTNUM
         L     5,CYL
         L     7,TRK
         B     SETUP
T2400    L     9,12(11)                 GET BCKCNT FROM DCB
         LR    8,1
         LR    7,9
         CR    7,8                     FIND DIRECTION OF REQESTED REC.
         BNL   BACKUP                  BACKWARD
         A     7,=F'1'                 FORWARD
         CR    7,8                     IS IT NEXT BLOCK
         BE    READIT                  YES
         SR    8,7                     COMPUTE NUMBER OF BLOCKS FORWARD
         B     FORWARD                 FORWARD SPACE
BACKUP   SRL   7,1                     FIND HALF WAY POINT IN FILE
         CR    8,7                      COMPARE TO DESIRED BLK NUM
         BH    BKSPACE
         CLOSE ((11),REREAD),TYPE=T     REWIND
         S     8,=F'1'
         BZ    READIT
FORWARD  CNTRL (11),FSR,(8)            FORWARD SPACE
         B     READIT
BKSPACE  SR    9,8
         A     9,=F'1'
         CNTRL (11),BSR,(9)             BACKSPACE
READIT   L     8,8(10)
         MVI   DECB,X'00'
         READ  DECB,SF,(11),(8),'S'
         CHECK DECB
         B     GOBCK
D2314    A     1,=F'1'                  ADJ. FOR TWO BLOCKS/TRACK
         MVC   TPERC(4),=F'20'         20 TRACKS PER CYLINDER
         SRL   1,1
         TM    3(3),X'01'
         BO    FIRSTR                  GET FIRST REC OFF TRACK
         MVI   12(11),X'02'             SET UP SECOND BLOCK ON TRACK
         MVI   IOB+39,X'02'
         MVI   CNTADDR,X'02'
         MVI   SRCADDR,X'01'
         B     GETDEB
D2302    MVC   TPERC(4),=F'46'
         B     FIRSTR
D2311    MVC   TPERC(4),=F'10'         10 TRACKS PER CYLINDER
FIRSTR   MVI   CNTADDR,X'01'           SET UP FIRST BLOCK ON TRACK
         MVI   IOB+39,X'01'
         MVI   12(11),X'01'
GETDEB   LA    9,DCBTAB
WHATDCB  CLC   0(1,10),0(9)
         BE    THISDCB
         A     9,=F'12'
         B     WHATDCB
THISDCB  CLI   3(9),X'01'          TEST FOR SHORT LAST BLOCK THAT
         BNH   TESTOPN             FIT ON A TRACK ASSIGNED TO THE
         CLI   TPERC+3,X'14'       PREVIOUS BLOCK
         BE    TST2314
         LR    6,1
         S     6,=F'2'
         STH   6,TTREL
         CLC   1(2,9),TTREL
         BNE   TESTOPN
         S     1,=F'1'             YES,SHORT BLOCK FOR 2311
         MVI   SRCADDR,X'01'
         MVI   CNTADDR,X'02'
         MVI   IOB+39,X'02'
         MVI   12(11),X'02'
         B     TESTOPN
TST2314  CLI   3(9),X'02'
         BNH   TESTOPN
         LR    6,1
         S     6,=F'2'
         STH   6,TTREL
         CLC   1(2,9),TTREL
         BNE   TESTOPN
         S     1,=F'1'             YES,SHORT BLOCK ON 2314
         MVI   SRCADDR,X'02'
         MVI   12(11),X'03'
         MVI   IOB+39,X'03'
         MVI   CNTADDR,X'03'
TESTOPN  L     10,4(9)             TEST OUTPUT DCB FOR OPEN
         TM    48(10),X'10'
         BZ    EXTOK                   IF NOT OPEN BRANCH
         L     9,8(9)                  CHECK NUMBER OF EXTENTS IN
         L     11,44(10)               OUTPUT AND INPUT.IF NOT SAME
         L     8,44(9)                 A NEW EXTENT WAS NEEDED FOR
         CLC   16(1,8),16(11)          OUTPUT.TO REFLECT THIS IN INPUT
         BE    EXTOK                   REQUIRES A CLOSE FOLLOWED BY
         LR    6,1
         LR    8,9                     AN OPEN.THIS PUTS NEW EXTENT IN
         CLOSE ((9))                   IN THE INPUT DEB.
         OPEN  ((8),(INPUT))
         LR    1,6
EXTOK    L     10,DUMMY
         L     6,12(10)
         L     6,44(6)                 GET DEB ADDRESS
         SR    12,12
         SR    3,3
         SR    4,4
         MVC   WRTCCW(4),8(10)         GET BUFFER ADDRESS
EXTLOOP  LH    11,38(4,6)              FIND EXTENT IN DEB THAT BRACKETS
         M     10,TPERC                BLOCK
         AH    11,40(4,6)
         LH    9,42(4,6)
         M     8,TPERC
         AH    9,44(4,6)
         SR    9,11
         A     9,=F'1'
         AR    12,9
         CR    1,12
         BH    NXEXT
         B     THISEXT
NXEXT    A     3,=F'1'                 GET NEXT EXTENT
         A     4,=F'16'
         SR    11,11
         IC    11,16(6)      GETS NUMBER OF EXTENTS FROM DEB
         CR    3,11          TEST IF ANY MORE EXTENTS TO BE CHECKED
         BE    AGAIN         BRANCH IF NO EXTENTS LEFT
         B     EXTLOOP
THISEXT  SR    12,1
         LH    5,42(4,6)               CC END
         LH    7,44(4,6)               HH END
         CR    12,7
         BH    CYLBCK
         SR    7,12
         B     SETUP
CYLBCK   S     5,=F'1'                 BACK OFF A CYLINDER
         S     12,TPERC
         CR    12,7
         BH    CYLBCK
         SR    7,12
         B     SETUP
SETUP    L     10,DUMMY
         MVC   IOB+21(3),13(10)        PUT DCB ADDR IN IOB
         STC   3,IOB+32                STORE EXTENT IN IOB
         L     4,12(10)
         STC   3,5(4)                  STORE EXTENT IN DCB
         STH   5,8(4)                  CC IN DCB
         STH   7,10(4)                 HH IN DCB
         MVC   IOB+35(4),8(4)          CCHH IN IOB
         MVC   SRCHFL,8(4)             CCHH IN SEARCH ID EQ
         MVC   CNTFL,8(4)              CCHH IN COUNT FIELD
SWITCH   BC    0,UPRECNO          BRANCH IF LOOKING FOR SHORT BLOCK
EXCCW    NI    EXECB,X'3F'
         EXCP  IOB                     READ DATA
         WAIT  1,ECB=EXECB
         CLI   EXECB,X'7F'
         BNE   TEST41
GOBCK    L     13,4(13)
         LM    14,12,12(13)
         BR    14
TEST41   CLI   EXECB,X'41'
         BNE   IOERR
         CLI   IOB+39,X'01'       WAS SEEKING FIRST RECORD?
         BNE   IOERR
AGAIN    OI    SWITCH+1,X'F0'
         L     1,4(13)            GET REG 13
         L     1,24(1)            RESTORE REG 1
         L     3,0(1)             GET ADDR OF BLKNUM
         L     1,0(3)             GET BLKNUM
         S     1,=F'1'            SUBTRACT 1 FROM BLKNUM
         ST    1,NEWARG           SET UP NEW ARG LIST
         MVC   NEWARG+4(4),4(3)
         LA    1,NEWARGAD
         B     RETRY
UPRECNO  SR    8,8
         IC    8,IOB+39           GET RECNUM TO BE SEEKED
         STC   8,SRCADDR          STORE RECNUM
         A     8,=F'1'            ADD 1 TO RECNUM
         STC   8,IOB+39           STORE RECNUM
         STC   8,CNTADDR
         STC   8,12(4)            STORE RECNUM INTO DCB
         NI    SWITCH+1,X'0F'
         B     EXCCW
IOERR    ABEND 3072,DUMP,STEP
*       S T A R T  P A R A M E T E R  L I S T
INDEB    DC    F'0'
INDCB    DC    F'0'
OUTDCB   DC    F'0'
BLKNUM   DC    F'0'
CYL      DC    F'0'
TRK      DC    F'0'
RECNUM   DC    F'0'
EXTNUM   DC    F'0'
FCBENTRY DC    F'0'
*           E N D  P A R A M E T E R  L I S T
TPERC    DC    F'0'
IOB      DC    X'42000000'
         DC    A(EXECB)
         DC    2F'0'
         DC    A(SRCHCCW)
         DC    5F'0'
EXECB    DC    F'0'
CNTFL    DC    F'0'
CNTADDR  DC    X'0100'
COUNT    DC    H'3228'
SRCHFL   DC    F'0'
SRCADDR  DC    X'00'
SRCHCCW  CCW   49,SRCHFL,64,5
TICCCW   CCW   08,*-8,0,0
CNTCCW   CCW   30,CNTFL,128,8
WRTCCW   CCW   0,DUMMY,X'20',3228
DUMMY    DC    F'0'
SAVE     DC    18F'0'
NEWARGAD DC    A(NEWARG)
NEWARG   DC    2F'0'
TTREL    DC    H'00'
         DS    0F
FILETAB  DC    X'01'                   FILE 1 FILE CONTROL BLOCK
TABASE   DC    X'000000'
TABDISP  DC    H'0'
BUFPNT   DC    H'0'
BUFADDR  DC    F'0'
OPENMOD  DC    X'00'
DCBADDR  DC    X'000000'
GETMCNT  DC    X'00'
TABORG   DC    X'000000'
FILE2    DC    X'02000000'             FILE 2 FILE CONTROL BLOCK
         DC    4F'0'
FILE3    DC    X'03000000'             FILE 3 FILE CONTROL BLOCK
         DC    4F'0'
FILE4    DC    X'04000000'             FILE 4 FILE CONTROL BLOCK
         DC    4F'0'
FILE8    DC    X'08000000'             FILE 8 FILE CONTROL BLOCK
         DC    4F'0'
FILE9    DC    X'09000000'             FILE 9 FILE CONTROL BLOCK
         DC    4F'0'
FILE10   DC    X'0A000000'             FILE10 FILE CONTROL BLOCK
         DC    4F'0'
*                            DCB ADDRESSES FOR D. A. DEVICES
DCBTAB   DC    X'01000000'
         DC    X'01'
         DC    AL3(QISAM1)
         DC    X'02'
         DC    AL3(BISAM1)
         DC    X'02000000'
         DC    X'01'
         DC    AL3(QISAM2)
         DC    X'02'
         DC    AL3(BISAM2)
         DC    X'03000000'
         DC    X'01'
         DC    AL3(QISAM3)
         DC    X'02'
         DC    AL3(BISAM3)
         DC    X'04000000'
         DC    X'01'
         DC    AL3(QISAM4)
         DC    X'02'
         DC    AL3(BISAM4)
         DC    X'08000000'
         DC    X'01'
         DC    AL3(QISAM8)
         DC    X'02'
         DC    AL3(BISAM8)
         DC    X'09000000'
         DC    X'01'
         DC    AL3(QISAM9)
         DC    X'02'
         DC    AL3(BISAM9)
         DC    X'0A000000'
         DC    X'01'
         DC    AL3(QISAM10)
         DC    X'02'
         DC    AL3(BISAM10)
*                            DCB ADDRESSES FOR TAPE DEVICES
         DC    X'01000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM1)
         DC    X'02000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM2)
         DC    X'03000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM3)
         DC    X'04000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM4)
         DC    X'08000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM8)
         DC    X'09000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM9)
         DC    X'0A000000'
         DC    F'0'
         DC    X'02'
         DC    AL3(BSAM10)
QISAM1   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT01F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM2   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT02F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM3   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT03F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM4   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT04F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM8   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT08F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM9   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT09F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
QISAM10  DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT10F001,DEVD=DA,  X
               DSORG=PS,LRECL=248,MACRF=(WP)
BISAM1   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT01F001
BISAM2   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT02F001
BISAM3   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT03F001
BISAM4   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT04F001
BISAM8   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT08F001
BISAM9   DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT09F001
BISAM10  DCB   DSORG=PS,MACRF=(E),IOBAD=IOB,DEVD=DA,KEYLEN=0,          X
               DDNAME=FT10F001
BSAM1    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT01F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM2    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT02F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM3    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT03F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM4    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT04F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM8    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT08F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM9    DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT09F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
BSAM10   DCB   BFALN=F,BLKSIZE=3228,RECFM=VB,DDNAME=FT10F001,DEVD=TA,  X
               DSORG=PS,LRECL=248,MACRF=(RC,WC)
         LTORG
         END
*/
