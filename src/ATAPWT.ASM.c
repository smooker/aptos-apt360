/*

*  ASMBLR

*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***

*

         PRINT NOGEN

ATAPWT   CSECT

         EXTRN FILETAB

         ENTRY TAPEWT

TAPEWT   B     12(15)

         DC    AL1(7)

         DC    CL7'ATAPWT '

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

         CALL  ABUFTP,(DATASET,ONE)     SET WRITE MODE

        L     1,SAVE1

         SR    6,6

         SR    4,4

         L     3,8(1)

         L     3,0(3)

         C     3,=F'10'

         BH    IRET12

         ST    3,PAIRCNT

ADDUP    L     5,16(4,1)

         A     4,=F'8'

         L     5,0(5)

         LPR   5,5

         AR    6,5

         BCT   3,ADDUP

         SLA   6,3

         S     6,=F'12'

         L     10,=A(FILETAB)

         LA    11,7          7 = TOTAL NUMBER OF FTXXF001 WORK FILES

SRCFILE  CLC   DATASET+7(1),0(10)      FIND FILE BLOCK ENTRY FOR THIS

         BE    FNDFILE                 DATA REF.

         A     10,=F'20'

         BCT   11,SRCFILE

         B     NOFILE

FNDFILE  C     6,=F'12'

         BL    IRET13

LOADBUF  L     9,8(10)

         LH    11,6(10)

         AR    11,9                     BUFFER ADDRESS

         A     9,=F'2981'               LRECL LIMIT IN BUFFER END

         LR    8,6                      TOTAL BYTE COUNT

         C     8,=F'244'                TEST FOR SELF-CONTAINED SCW

         BH    FSTSEG

         A     6,=F'4'                 LEN OF SCW

         STH   6,0(11)                 SELF CONTAINED SEG

         MVC   2(2,11),=H'0'

         B     GETREC

FSTSEG   MVC   0(2,11),=H'248'          FIRST SCW

         MVI   2(11),X'01'

         MVI   3(11),X'00'

GETREC   L     7,12(1)

         L     7,0(7)                   GET RECORD NUMBER

         LH    3,4(10)

         L     4,0(10)

         L     6,0(3,4)

         C     6,=F'0'                  TEST FOR ENTRY IN TABLE

         BNE   UPREC                    BLOCK ALREADY IN TABLE

         C     3,=F'396'                IS NEW TABLE NEEDED

         BL    STAB                     NO

         SR    1,1                      YES

         IC    1,16(10)

         A     1,=F'1'                  BUMP GETMAIN COUNT

         STC   1,16(10)

         GETMAIN R,LV=400               GET TABLE

         IC    12,0(10)

         ST    1,0(10)                  NEW BASE

         STC   12,0(10)

         ST    1,396(4)                 CHAIN TO OLD TABLE

         LR    4,1

         SR    3,3

         STH   3,4(10)                  ZERO TABLE DISPLACEMENT

         L     1,SAVE1

         MVI   0(4),X'00'               CLEAR NEW TABLE

         MVC   1(255,4),0(4)

         MVC   256(144,4),255(4)

STAB     L     6,8(10)                  GET BLOCK NUMBER FROM BUFFER

         S     6,=F'8'

         LH    6,0(6)

         STH   7,0(3,4)                 STORE RECNUM IN TABLE

         STH   6,2(3,4)                 STORE BLKNUM IN TABLE

UPREC    A     7,=F'1'                  UPDATE DATASET RECNUMS

         STH   7,CUREC

         MVC   DATASET+1(2),CUREC

         MVC   DATASET+3(2),CUREC

         MVI   IREC,X'80'

LOCDUB   L     4,=F'12'                 SET PARA LIST DISP

         L     5,=F'244'                SET ROOM IN SEGMENT

         SR    7,7

NXARRY   L     3,4(4,1)                 GET ARRAY WORD COUNT

         L     3,0(3)

         LTR   3,3

         BM    NEG

         BZ    WZERO

GETARRY  L     6,0(4,1)                 GET ARRAY ADDRESS

GETFUL   L     12,0(6,7)                GET ONE WORD OF DATA

         ST    12,4(11)                 STORE IN BUFFER

         A     11,=F'4'                 BUMP BUFFER POINTER

         S     5,=F'4'                  DECREASE ROOM IN SEGMENT

         A     7,=F'4'                  BUMP ARRAY ADDR. DISPL.

         C     5,=F'232'                TEST FOR THREE FULL WORDS

         BE    FULL

         BCT   3,GETFUL                 GET NEXT WORD FROM ARRAY

WZERO    A     4,=F'8'                  THIS ARRAY IS EMPTY

         SR    7,7

         B     NXARRY                   GET NEXT ARRAY

FULL     S     8,=F'12'                 ALL FULL WORDS STORED

         LR    12,7

         LR    7,11

         S     7,=F'12'                 SAVE ADDRESS OF SCW

         C     3,=F'1'                  IS ARRAY EMPTY

         BE    EMPTY                    YES

         S     3,=F'1'

         SLA   3,3                      NO,CHANGE TO BYTE COUNT

         AR    6,12

         B     CKFIT                    JUMP INTO MIDDLE OF DOUBLE MOVE

NEG      LA    14,GETARRY

NEG1     LR    12,4

         SRA   12,3

         A     12,=F'20'

         ST    12,IREC

         LCR   3,3

         BR    14

NEGD     LA    14,MPY8

         B     NEG1

EMPTY    C     8,=F'0'                  ANY DATA LEFT FOR BUFFER

         BH    OUTLOOP                  YES

         A     11,=F'4'

         B     SELFSCW                 NO

OUTLOOP  A     4,=F'8'                  START MOVEING DOUBLE WORDS

         L     6,0(4,1)                 GET ARRAY ADDRESS

         L     3,4(4,1)                 GET ARRAY COUNT

         L     3,0(3)

         LTR   3,3

         BM    NEGD

         BZ    OUTLOOP

MPY8     SLA   3,3                      CHANGE WORD COUNT TO BYTES

CKFIT    CR    3,5                      COMPARE ARRAY TO SEGMENT SPACE

         BNH   FIT                      BRANCH IF ARRAY WILL FIT

         SR    8,5                      ARRAY SPANS SEGMENTS

         S     5,=F'1'

         EX    5,MOVE                   FILL THIS SEGMENT

         A     5,=F'1'

         AR    6,5                      MOVE POINTER DOWN ARRAY

         SR    3,5                      DECREASE COUNT OF DATA IN ARRAU

         A     5,=F'4'                  ADD IN LENGTH OF SCW

         AR    11,5                     NEW VALUE FOR BUFFER POINTER

         LR    7,11                     SAVE ADDRESS OF SCW

         MVC   0(4,11),INTSCW           MOVE INTERMEDIATE SCW

         L     5,=F'244'                RESET ROOM IN SEGMENT

         CR    11,9                     IS THERE LRECL LEFT IN BUFFER

         BNH   CKFIT                    YES,GO GET MORE DATA

         BAL   12,DUMPBUF               NO,WRIRE OUT BUFFER

         MVC   0(4,11),INTSCW           START NEXT BUFFER WITH

         B     CKFIT                    INTERMEDIATE SCW

FIT      S     3,=F'1'                  ARRAY FITS IN SEGMENT

         EX    3,MOVE

         A     3,=F'1'

         AR    11,3                     BUMP BUFFER POINTER

         SR    8,3                      IS ALL DATA MOVED

         BNZ   MODATA                   BRANCH IF NO

         A     11,=F'4'                BUMP BY SCW LEN

         CLI   2(7),X'00'               YES,IS ALL DATA IN ONE SEG

         BE    SELFSCW                  BRANCH IF YES

         MVI   2(7),X'02'               MAKE LAST SCW

         LR    8,11

         SR    8,7                      COMPUTE BYTE COUNT OF SEGMENT

         STH   8,0(7)                   STORE BYTE COUNT IN SCW

         MVI   3(7),X'00'

SELFSCW  CR    11,9                     IS THERE LRECL LEFT IN BUFFER

         BNH   DONE                     BRANCH IF YES

         BAL   12,DUMPBUF               NO,WRITE OUT BUFFER

DONE     LR    8,11

         L     12,8(10)

         SR    11,12

         STH   11,6(10)                 SET BUFFER DISPLACEMENT

         STH   11,0(12)                STORE BCW BYTE COUNT

         CLI   TFLAG,X'FF'             WAS A NEW BLOCK STARTED

         BNE   RETURN                  NO

         LH    4,4(10)                 BUMP CROSSREF TABLE

         A     4,=F'4'

         STH   4,4(10)

         MVI   TFLAG,X'00'

         B     RETURN

MODATA   SR    5,3                      COMPUTE ROOM LEFT IN SEGMENT

         BZ    SCWFULL                  BRANCH IF SEGMENT IS FULL

         B     OUTLOOP                  BRANCH BACK FOR MORE DATA

SCWFULL  LA    11,4(11)                 INCREMENT TO NEW SCW

         LR    7,11                     SAVE NEW SCW ADDRESS

         MVC   0(4,11),INTSCW           MOVE IN INTERMEDIATE SCW

         L     5,=F'244'                RESET ROOM IN SEGMENT

         CR    11,9                     IS THERE LRECL LEFT IN BUFFER

         BNH   OUTLOOP                  BRANCH IF YES

         BAL   12,DUMPBUF               WRIRE OUT BUFFER

         MVC   0(4,11),INTSCW           MOVE IN INTERMEDIATE SCW

         B     OUTLOOP                  BRANCH BACK FOR MORE DATA

DUMPBUF  ST    1,SAVE1

         L     7,8(10)                  GET BUFFER ADDRESS

         SR    11,7                     COMPUTE BCW COUNT

         STH   11,0(7)                  STORE BCW COUNT

         MVC   2(2,7),=H'0'

         L     11,12(10)                GET DCB ADDRESS

         MVI   DECB,X'00'

         WRITE DECB,SF,(11),(7)

         CHECK DECB

         MVI   TFLAG,X'FF'

         S     7,=F'8'

         LH    11,0(7)                  GET BLOCK NUMBER FROM BUFFER

         A     11,=F'1'                 BUMP BLOCK NUMBER

         STH   11,0(7)

         LA    7,12(7)                  SET ADDRESS OF NEXT SCW

         LR    11,7                     SET BUFFER POINTER

         L     1,SAVE1

         BR    12

IRET12   MVC   IREC(4),=F'12'

         B     RETURN

IRET11   MVC   IREC(4),=F'11'

         B     RETURN

IRET13   MVC   IREC(4),=F'13'

         B     RETURN

NOFILE   MVC   IREC(4),=F'14'

         B     RETURN

ERRREC   MVC   IREC(4),=F'15'

         B     RETURN

RETURN   L     1,SAVE1

         L     3,0(1)

         MVC   0(8,3),DATASET

         L     3,4(1)

         L     4,IREC

         ST    4,0(3)

         L     13,4(13)

         LM    14,12,12(13)

         BR    14

         LTORG

SAVE     DC    18F'0'

SAVE1    DC    F'0'

DATASET  DC    2F'0'

ONE      DC    F'1'

PAIRCNT  DC    F'0'

IREC     DC    F'0'

MOVE     MVC   4(0,11),0(6)

CUREC    DC    H'0'

INTSCW   DC    H'248'

         DC    X'0300'

TFLAG    DC    X'00'

         END

*/

