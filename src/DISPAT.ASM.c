/*

*  ASMBLR

*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***

DISPAT   START 0

         ENTRY AERROR

         SAVE  (2,12),T,DISPAT

         USING DISPAT,12

         LR    12,15

         LA    10,SAVEAREA

         ST    10,8(13)

         ST    13,SAVEAREA+4

         LR    13,10

         LM    2,4,COMADD         REG2 = A(ASISTM)  REG3 = A(APOSTP)

         MVC   IOUTAP(4),84(4)    SET UP IOUTAP TO CORRECT REFERENCE NO

         SR    4,4                NUMBER OF POST PROCESSORS DONE

         L     9,32(2)            GET NUMPST VALUE

NEXT     LTR   9,9

         BC    2,GETPP            BRANCH IF POST PROC. TO BE EXECUTED

         LA    1,FILE             GET ARGUMENT LIST FOR ATAPOP CALL

         L     15,ATAPOPAD

         L     5,ATAPTBAD

         LA    6,0(5)             PROTAP

         ST    6,FILE

         BALR  14,15              REWIND PROTAP

         LA    6,16(5)            CLTAPE

         ST    6,FILE

         BALR  14,15              REWIND CLTAPE

         LA    6,24(5)            POCTAP

         ST    6,FILE

         BALR  14,15              REWIND POCTAP

         LA    6,40(5)            SRFTAP

         ST    6,FILE

         BALR  14,15              REWIND SRFTAP

         LA    6,72(5)            TAPES4

         ST    6,FILE

         BALR  14,15              REWIND TAPES4

RET      L     15,=V(IBCOM#)

         CNOP  0,4

         BAL   14,4(15)

         DC    XL1'1',AL3(IOUTAP)

         DC    AL4(ENDMSG)

         BAL   14,16(15)

         CALL  ACNTRL             RETURN TO NEXT PART PROGRAM

GETPP    LR    8,9

         S     8,K1               NUMPST=NUMPST-1

         ST    8,32(2)

         LA    4,1(4)

         LR    8,4

         SLL   8,1

         BCTR  8,0                CALCULATE SUBSCRIPT TO APOSTP

         ST    8,36(2)            STORE SUBSCRIPT TO APOSTP IN NUMPTR

         BCTR  8,0

         SLL   8,3                REL. DISP. TO EBCDIC NAME IN APOSTP

         LA    7,0(3,8)           ADDRESS TO EBCDIC NAME IN APOSTP

         LR    8,7

         MVC   6(2,8),PP          ADD PP SUFFIX

         LA    5,6

         SR    6,6

ISBLNK   CLC   0(1,7),BLANKS

         BC    6,NOBLNK

         LA    6,1(6)

         LA    7,1(7)

         BCT   5,ISBLNK

NOBLNK   MVC   PPNAME+2(6),BLANKS

         LA    5,7

         SR    5,6

         STC   5,SETUP+1

SETUP    MVC   PPNAME(0),0(7)

         MVC   6(2,8),BLANKS      BLANK PP SUFFIX

         BLDL  0,LIST             BUILD LIST

         CH    15,=H'4'           TEST RETURN CODE

         BC    8,NOPPR            ENTRY NOT FOUND

         BC    2,IOERR            DIRECTORY READ ERROR

         L     1,SYSADDRS

         LINK  DE=PPNAME          ALL OK - LINK TO POSTPROCESSOR

         CNOP  2,4

         BALR  14,0

         L     12,8(14)

         BC    15,12(14)

         DC    A(DISPAT)

         C     15,=F'0'

         BNE   ERREXIT

         BCTR  9,0

         B     NEXT

NOPPR    MVC   PPMSG+4(8),PPNAME  PUT PP NAME IN MESSAGE

         L     15,=V(IBCOM#)      WRITE MESSAGE - PP NOT FOUND

         CNOP  0,4

         BAL   14,4(15)

         DC    XL1'1',AL3(IOUTAP)

         DC    A(PPMSG)

         BAL   14,16(15)

         BCTR  9,0

         B     NEXT

IOERR    L     15,=V(IBCOM#)      WRITE MESSAGE - DIRECTORY READ ERROR

         CNOP  0,4

         BAL   14,4(15)

         DC    XL1'1',AL3(IOUTAP)

         DC    A(IOMSG)

         BAL   14,16(15)

         B     RET                GO BACK FOR NEXT PART

ERREXIT  CALL  POSOUT

LIST     DC    H'1'               SKELETON FOR BLDL MACRO

         DC    H'58'

PPNAME   DS    CL8                WILL CONTAIN NAME OF PP MODULE

         DS    CL50               REMAINDER OF LIST - USED FOR LINK

BLANKS   DC    CL6'      '

         DS    0H

PPMSG    DC    X'021A29F0'

         DC    CL40'XXXXXXXX POST PROCESSOR MEMBER NOT FOUND'

         DC    X'22'

         DS    0H

IOMSG    DC    X'021A32F0'

         DC    C'DIRECTORY READ ERROR SEARCHING FOR POSTPROCESSOR.'

         DC    X'22'

         DS    0H

ENDMSG   DC    X'021A4AF0'

         DC    CL40'                                        '

         DC    CL33'     ** END OF POST PROCESSING **'

         DC    X'22'

PP       DC    CL2'PP'

FILE     DC    F'0'

         DC    A(K1)

         DC    XL1'80',AL3(IRET)

K1       DC    F'1'

IRET     DC    F'0'

IOUTAP   DC    F'0'

SYSADDRS DC    V(SYSCOMON)

COMADD   DC    V(ASISTM)

         DC    V(APOSTP)

ATAPTBAD DC    V(ATAPTB)

ATAPOPAD DC    V(ATAPOP)

SAVEAREA DC    18F'0'

AERROR   DC    F'0'               THIS FIELD MUST FOLLOW THE SAVEAREA

         END

*/

