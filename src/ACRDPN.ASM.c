#include <assert.h>

/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***

ACRDPN   START 0

         ENTRY CARDPN

BASE     EQU   *

* THIS ROUTINE PUNCHES BCD, EBCDIC, OR COLUMN BINARY CARDS.

* CALLING SEQUENCE

*      CALL CARDPN(A,N,M,I,D,J)

* A IS ADDRESS OF FIRST WORD TO BE PUNCHED

* N IS NO. OF 4 BYTE WORDS TO BE PUNCHED, NORMALLY 18, IF GREATER NO

* ID AND SEQUENCE NO. WILL BE PUNCHED.

* M IS MODE.

*        M=1, CONVERT BCD TO EBCDIC AND PUNCH

*        M=2, CONVERT EBCDIC TO BCD AND PUNCH

*        M=3, PUNCH AS IS- NO CONVERSION

*        M=4, PUNCH 8 BIT COLUMN BINARY

* I  IS 4 BYTE SEQUENCE NO. TO BE PUNCHED IN COLUMNS 77-80, TREATED AS

* MODULO 10,000.

* D IS LOCATION OF A  4 BYTE IDENTIFICATION WORD TO BE PUNCHED IN

* COLUMNS 73-76(ALPHA ONLY.)

* J IS USED FOR COLUMN BINARY

*        J=1, PUNCH ROWS 2-9

*        J=2, PUNCH ROWS 1-8

*        J=3, PUNCH ROWS 0-7

*        J=4, CLOSE OUTPUT FILE

****     ****       ****      ****      ****       ****          ****

CARDPN   SAVE  (2,12),T,CARDPN

         USING BASE,12

         LR    12,15

         LR    2,1            ARGUMENT POINTER

         ST    13,SAVEAREA+4

         LA    3,SAVEAREA

         ST    3,8(13,0)

         LR    13,3

         CLI   16(2),X'80'        TEST IF ONLY 5 PARAMETERS GIVEN

         BE    BLCARRAY           BRANCH IF YES

         L     4,20(2,0)          ADDRESS OF J

         L     9,0(4,0)           J

         C     9,=F'4'            TEST IF FILE IS TO BE CLOSED

         BNE   BLCARRAY           BRANCH IF NO

         CLC   FILEOPEN,K1

         BNE   OUT

         CNOP  0,4

NORMCLOS CLOSE (BCDPUNCH,LEAVE)

         XC    FILEOPEN,FILEOPEN

         B     OUT

BLCARRAY MVI   CARRAY,X'40'

         MVC   CARRAY+1(79),CARRAY   BLANK CARRAY

         MVI   BARRAY,X'00'

         MVC   BARRAY+1(159),BARRAY    ZERO BINARY ARRAY

         L     4,4(2,0)       ADDRESS OF N

         L     9,0(4,0)       N

         C     9,=F'18'

         BH    NOID           IF BRANCH, NO ID AND SEQ. NO.

         L     5,16(2,0)      ADDRESS OF D

         L     5,0(5,0)       D

         ST    5,CARRAY+72

         SR    6,6

         L     7,12(2,0)      ADDRESS OF I

         L     7,0(7,0)       I

         D     6,=F'10000'    I MODULO 10,000

         LPR   6,6

         CVD   6,IDDOUBLE     CONVERT TO PACKED DECIMAL

         UNPK  CARRAY+76(4),IDDOUBLE+4(4)  UNPACK AND STORE

         OI    CARRAY+79,X'F0'     CHANGE ZONE

NOID     L     5,8(2,0)       ADDRESS OF M

         L     5,0(5,0)       M

         L     6,0(2,0)       ADDRESS OF A

         M     8,K4           NO. OF CHARACTERS

         CH    5,K3+2

         BH    BINARY         IF BRANCH, COLUMN BINARY MODE

         SH    9,K1+2

         STH   9,MOVE

         AH    9,K1+2

         OI    MOVE,X'D2'     OPCODE IN MOVE DESTROYED BY ST 9,MOVE

         CNOP  0,4

MOVE     MVC   CARRAY,0(6)         LENGTH = NO. CHARACTERS

         CH    5,K3+2

         BE    PUNCH          IF BRANCH, NO CONVERSION

         LA    5,BASE2

         LA    6,BASE2

         USING BASE2,5

LOOPSTRT TM    0(6),X'C0'

         BC    8,ZEROZONE     IF BRANCH, ZONE IS ZERO

         TM    0(6),X'80'

         BC    1,LOOPEND      IF BRANCH, CHARACTER IS ALPHA OR ZONE F

         TR    0(1,6),TABLE2-64  CONVERT

         B     LOOPEND

ZEROZONE TR    0(1,6),TABLE1    MAKE ZONE F OR + OR -

LOOPEND  A     6,K1           UPDATE POINTER

         BCT   9,LOOPSTRT

         DROP  5

         B     PUNCH

BINARY   L     7,20(2,0)      ADDRESS OF J

         L     7,0(7,0)       J

         A     7,K1

         SR    10,10

BINLOOPS SR    3,3

         IC    3,0(6,0)       GET BYTE TO BE PUNCHED

         SLL   3,0(7)         BITS 16-23 CONTAIN BYTE 1 TO BE PUNCHED

         LR    1,3

         N     3,=X'000000FF'   GET BITS IN BYTE 2 TO BE PUNCHED

         SRL   3,2(0)

         N     1,=X'00000F00'   GET BITS IN BYTE 1 TO BE PUNCHED

         OR    3,1            BITS 16-31 CONTAIN 2 BYTES TO BE PUNCHED

         STH   3,BARRAY(10)

         A     10,K2          UPDATE BARRAY INDEX

         A     6,K1           UPDATE A INDEX

         BCT   9,BINLOOPS

         L     9,0(4,0)       N

         C     9,=F'18'

         BH    CHEKOPEN      IF BRANCH, NO ID. AND SEQ. NO.

         SR    10,10

         SR    3,3

         SR    5,5

         L     1,K4

IDSTRT   IC    3,CARRAY+72(5)      FIRST ALPH ID

         LR    7,3

         SRL   3,4(0)         ZONE REMAINING

         C     3,FZONE

         BE    DROPZONE

         A     3,K6

         L     6,=X'80000000'

          SRL 6,0(3)         ZONE PUNCH IN BIT 18,19 OR 20

         B     ZONEFIX

DROPZONE SR    6,6

ZONEFIX  N     7,=X'0000000F' DIGIT REMAINING

         L     8,K1

         C     7,K3

         BH    FIXS           IF BRANCH, DIGIT INTO BYTE 2 OF FIELD

         L     9,K11

         B     COMBINER

FIXS     L     9,K9

COMBINER SR    9,7            NO. BITS TO SHIFT

         SLL   8,0(9)

         OR    6,8            ZONE AND DIGIT COMBINED

         STH   6,BARRAY+144(10)

         A     10,K2

         A     5,K1

         CNOP  0,4

BRANLAST BCT   1,IDSTRT

         L     6,CARRAY+76

         N     6,=X'0F0F0F0F'

         ST    6,CARRAY+76

         L     1,K5

         LA    0,SEQOUT

         SR    0,12

         L     4,BRANLAST

         O     0,=X'47F0C000'  SET UP BRANCH ADDRESS

         ST    0,BRANLAST

SEQOUT   BCT   1,IDSTRT

         ST    4,BRANLAST     RESTORE

CHEKOPEN CLC   FILEOPEN,K1             IS FILE ALREADY OPEN

         BE    BINPUT     BRANCH IF YES

BINOPEN  OPEN  (BINPUNCH,(OUTPUT))

         MVC   FILEOPEN,K1

         MVC   NORMCLOS+5(3),BINCLOSE      SET FILE TO BE CLOSED

BINPUT   WRITE BINDECB,SF,BINPUNCH,BARRAY

         CHECK BINDECB

         B     OUT

PUNCH    CLC   FILEOPEN,K1        IS FILE ALREADY OPEN

         BE    BCDPUT     BRANCH IF YES

         OPEN  (BCDPUNCH,(OUTPUT))

         MVC   FILEOPEN,K1

BCDPUT   WRITE BCDDECB,SF,BCDPUNCH,CARRAY

         CHECK BCDDECB

OUT      L     13,SAVEAREA+4

         RETURN (14,12),T

         DS    0H

BARRAY   DC    160XL1'00'

         DS    0F

BASE2    EQU   *

CARRAY   DC    20F'0'

SAVEAREA DC    18F'0'

BINCLOSE DC    AL3(BINPUNCH)     DCB ADDRESS

FILEOPEN DC    F'0'     1 MEANS FILE IS ALREADY OPEN

K1       DC    F'1'

K2       DC    F'2'

K3       DC    F'3'

K4       DC    F'4'

K5       DC    F'5'

K6       DC    F'6'

K9       DC    F'9'

K11      DC    F'11'

IDDOUBLE DC    D'0'

FZONE    DC    XL4'0000000F'

TABLE1   DC    XL14'F0F1F2F3F4F5F6F7F8F9405060'

TABLE2   DC    11XL1'40'

         DC    XL5'4B406C5040'

         DC    XL1'4E'

         DC    10XL1'40'

         DC    XL3'5B5C4C'

         DC    2XL1'40'

         DC    XL2'6061'

         DC    9XL1'40'

         DC    XL2'6B4D'

         DC    14XL1'40'

         DC    XL4'7E40407B'

BCDPUNCH DCB   DSORG=PS,MACRF=W,DDNAME=APTPUNCH,DEVD=PC,MODE=E,STACK=1,X

               LRECL=80,BLKSIZE=80,BUFNO=2,RECFM=F

BINPUNCH DCB   DSORG=PS,MACRF=W,DDNAME=APTPUNCH,DEVD=PC,MODE=C,STACK=1,X

               LRECL=160,BLKSIZE=160,BUFNO=2,RECFM=F

         DCBD  DSORG=(PS),DEVD=(PC)

         END

*/

