/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***

*

         PRINT NOGEN

*        CALL  USERTN,(INDEB,INDCB,OUTDCB,BLKNUM,CYL,TRK,RECNUM,EXTNUM)

USERTN   CSECT

         B     12(15)

         DC    AL1(7)

         DC    CL7'USERTN '

         STM   14,12,12(13)

         BALR  2,0

         USING *,2

         LR    15,13

         LA    13,SAVE

         ST    13,8(15)

         ST    15,4(13)

         ST    1,SAVE1

         LM    3,6,0(1)                 GET INPUT PARAMETER VALUES

         TM    48(5),X'10'              IS OUTPUT DCB OPEN.

         BZ    EXTOK                    BRANCH IF NO.

         L     11,44(5)                 TEST IF NEW EXTENT WAS OBTAINED

         CLC   16(1,11),16(3)           SINCE OPEN OF INPUT.

         BE    EXTOK                    BRANCH IF NUM OF EXTENTS EQ.

         CLOSE ((4))                    FORCE NEW EXTENT INTO INPUT DEB

         OPEN  ((4),(INPUT))            BY CLOSE AND REOPEN OF FILE.

         L     3,44(4)             GET NEW DEB ADDRESS

         L     1,SAVE1

EXTOK    L     11,32(3)                 GET UCB ADDRESS

         CLI   19(11),X'02'             TEST FOR 2301 DRUM

         BE    D2301                   BRANCH IF YES

         B     USERCOD                  ADD USER CODE HERE FOR OTHERS

D2301    ST    7,SAVE7

         LR    7,6

         L     10,32(1)           GET FCB ENTRY

         L     9,=V(DCBTAB)

WHATDCB  CLC   0(1,10),0(9)

         BE    THISDCB

         A     9,=F'12'

         B     WHATDCB

THISDCB  SR    6,6

         S     7,=F'1'

         D     6,=F'6'

         A     6,=F'1'            TTR = ((BLOCK#-1)/6)+1

         CLI   3(9),X'06'         TEST IF LAST TRACK HAS SHORT BLOCK

         BNH   SETRECNO           BRANCH IF NOT

         S     7,=F'1'

         STH   7,TTREL

         A     7,=F'1'

         CLC   1(2,9),TTREL       TEST IF BLOCK ON LAST TRACK

         BNE   SETRECNO

         S     7,=F'1'

         LA    6,7                SET RECORD NUMBER TO 7

SETRECNO ST    6,24(1)            RETURN RECNUM TO AEXCP

         A     7,=F'1'

         LR    6,7

         L     7,SAVE7

         B     FNDEXT

FNDEXT   SR    11,11

         SR    15,15

         SR    12,12

EXTLOOP  LH    0,40(11,3)               GET START TRACK THIS EXTENT

         LH    1,44(11,3)               GET END TRACK THIS EXTENT

         SR    1,0                      COMPUTE NUMBER OF TRACKS IN

         A     1,=F'1'                  THIS EXTENT

         AR    12,1                     TOTAL UP TRACKS TO THIS POINT

         CR    6,12                     IS BLOCK IN THIS EXTENT

         BH    NXEXT                    NO,BRANCH TO GET NEXT EXTENT

         B     THISEXT                  YES,FIND WHICH TRACK

NXEXT    A     11,=F'16'                BUMP EXTENT INDEX

         A     15,=F'1'                 BUMP INDEX NUMBER

         B     EXTLOOP                  GET NEXT EXTENT

THISEXT  SR    12,6                     GR12=TOTAL TRACKS-BLOCK NUM.

         LH    0,44(11,3)               GET LAST TRACK NUMBER

         SR    0,12                     TRACK=LAST-DIFF

         L     8,SAVE1

         ST    0,20(8)             STORE TRACK NUMBER

         LH    1,42(11,3)               GET CYLINDER NUMBER

         ST    1,16(8)             STORE CYLINDER NUMBER

         ST    15,28(8)            STORE EXTENT NUMBER

         B     GOBCK

USERCOD  DC    F'0'                     ABEND IF NO USER CODE

TTREL    DC    H'0'

GOBCK    L     13,4(13)

         LM    14,12,12(13)

         BR    14

SAVE     DC    18F'0'

SAVE1    DC    F'0'

SAVE7    DC    F'0'

         LTORG

         END

*/

