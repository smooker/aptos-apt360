/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
APTLNK   START 0
         ENTRY ASCNTL,A2CTRL,SECTN3,APTPOS
         ENTRY AOUTFG
         USING APTLNK,15
ASCNTL   SAVE  (2,12),T,ASCNTL
         LA    9,LINKADDR
         MVC   0(8,9),=C'ASECT1  '
         BC    15,8(0,9)
         LTORG
         USING A2CTRL,15
A2CTRL   SAVE  (2,12),T,A2CTRL
         LA    9,LINKADDR
         MVC   0(8,9),=C'ASECT2  '
         BC    15,8(0,9)
         LTORG
         USING SECTN3,15
SECTN3   SAVE  (2,12),T,SECTN3
         LA    9,LINKADDR
         MVC   0(8,9),=C'ASECT3  '
         BC    15,8(0,9)
         LTORG
         USING APTPOS,15
APTPOS   SAVE  (2,12),T,APTPOS
         LA    9,LINKADDR
         MVC   0(8,9),=C'ASECT4  '
         BC    15,8(0,9)
         LTORG
         USING LINKADDR,9
LINKADDR DS    D'0'
         LA    10,SAVEAREA
         ST    10,8(0,13)
         ST    13,SAVEAREA+4
         LR    13,10
         LA    1,ATAPTBAD
         LINK  EPLOC=LINKADDR
         CNOP  2,4
         BALR  14,0
         L     9,8(14)
         BC    15,12(14)
         DC    A(LINKADDR)
         C     15,AOUTFG
         BNE   CALLEXIT
         CALL  ACNTRL
CALLEXIT CALL  APTTRU
ATAPTBAD DC    V(ATAPTB)
         DC    V(A0CON)
         DC    V(ASISTM)
         DC    V(APOSTP)
         DC    V(ATIME)
         DC    V(ATAPRD)
         DC    V(ATAPOP)
         DC    V(ATAPWT)
         DC    V(ASERCH)
         DC    V(ABUFTP)
         DC    V(ATAPXC)
         DC    V(ACRDPN)
         DC    V(IBCOM#)
         DC    V(PDUMP)
         DC    V(DUMP)
         DC    V(DVCHK)
         DC    V(OVERFL)
         DC    V(DCOS)
         DC    V(DSIN)
         DC    V(FRDNL#)
         DC    V(FWRNL#)
         DC    V(COS)
         DC    V(SIN)
         DC    V(IHCERRM)
AOUTFG   DC    F'0'
SAVEAREA DC    18F'0'
         END
*/
