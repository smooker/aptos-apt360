/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***

DVLIEGPP START 0

         ENTRY DISPAT

         ENTRY ATAPRD,ATAPOP,ATAPWT,ABUFTP,ATAPXC,ASERCH

         ENTRY TAPERD,TAPEOP,TAPEWT,BUFFTP,TAPECH

         ENTRY ACRDPN,CARDPN

         ENTRY DCOS,DSIN,COS,SIN,IHCERRM

         ENTRY IBCOM#

         ENTRY FRDNL#,FWRNL#

         ENTRY PDUMP,DUMP,DVCHK,OVERFL

         ENTRY CLSETP,CLREAD

         ENTRY CONBCD,INIT,CHKMIN,SETMIN

         ENTRY NNTAIN,PARNOM,PARNEM

         ENTRY PUNCHA,PUNCHB,PUNIDN,PUNSEQ

         ENTRY PUNNUM,PUNIDS,PUNNOM,SHIFT

         USING START,12

START    SAVE  (2,12),T,DVLIEGPP

         LR    12,15

         LA    10,SAVEAREA

         ST    10,8(0,13)

         ST    13,SAVEAREA+4

         LA    2,DISPAT

         ST    2,18*4(13)

         LR    13,10

         MVC   ATAPRDAD(144),20(1)

         LM    2,6,0(1)

         LM    7,11,SYSCOMON

         MVC   0(92,7),0(2)     ATAPTB

         MVC   0(56,8),0(3)    A0CON

         MVC   0(88,9),0(4)   ASISTM

         MVC   0(160,10),0(5)  APOSTP

         MVC   0(32,11),0(6)  ATIME

         CALL  DVLIEG

RET      L     13,SAVEAREA+4

         L     14,12(0,13)

         RETURN (0,12),T

         USING DISPAT,15

DISPAT   L     12,STARTAD

         L     1,RETAD

         SR    15,15

         BR    1

STARTAD  DC    A(START)

RETAD    DC    A(RET)

         USING FRDNL#,15

FRDNL#   L     15,FRDNLAD

         BR    15

         USING FWRNL#,15

FWRNL#   L     15,FWRNLAD

         BR    15

         USING COS,15

COS      L     15,COSAD

         BR    15

         USING SIN,15

SIN      L     15,SINAD

         BR    15

         USING IHCERRM,15

IHCERRM  L     15,CERRMAD

         BR    15

         USING CLSETP,15

CLSETP   L     15,CLSETPAD

         BR    15

         USING *,15

CLREAD   L     15,CLREADAD

         BR    15

         USING *,15

SETMIN   L     15,SETMINAD

         BR    15

         USING *,15

CHKMIN   L     15,CHKMINAD

         BR    15

         USING *,15

CONBCD   L     15,CONBCDAD

         BR    15

         USING *,15

INIT     L     15,INITAD

         BR    15

         USING *,15

NNTAIN   L     15,NNTAINAD

         BR    15

         USING *,15

PARNOM   L     15,PARNOMAD

         BR    15

         USING *,15

PARNEM   L     15,PARNEMAD

         BR    15

         USING *,15

PUNCHA   L     15,PUNCHAAD

         BR    15

         USING *,15

PUNCHB   L     15,PUNCHBAD

         BR    15

         USING *,15

PUNIDN   L     15,PUNIDNAD

         BR    15

         USING *,15

PUNSEQ   L     15,PUNSEQAD

         BR    15

         USING *,15

PUNNUM   L     15,PUNNUMAD

         BR    15

         USING *,15

PUNIDS   L     15,PUNIDSAD

         BR    15

         USING *,15

PUNNOM   L     15,PUNNOMAD

         BR    15

         USING *,15

SHIFT    L     15,SHIFTAD

         BR    15

         USING IBCOM#,15

         DS    0F

IBCOM#    B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

          B    IBADD

         B     IBADD

         B     IBADD

         DS    H

         BAL   1,EX               INST. ADD.+4 INTO GR1

         BAL   1,EX               .

         BAL   1,EX               .

         BAL   1,EX               .

         BAL   1,EX               .

         BAL   1,EX               .

         BAL   1,EX               .

         BAL   1,EX               .

IBADD    LR    1,14               INST. ADD.+4 INTO GR1

EX       SL    1,FOUR             INST. ADD.

         L     15,AIBCOM     SET REAL IBCOM# ADDRESS IN 15

         BR    1                  EXEC. INST. AGAIN

         USING PDUMP,15

PDUMP    L     15,PDUMPAD

         BR    15

         USING *,15

DUMP     L     15,DUMPAD

         BR    15

         USING *,15

DVCHK    L     15,DVCHKAD

         BR    15

         USING *,15

OVERFL   L     15,OVERFLAD

         BR    15

         USING TAPERD,15

TAPERD   L     15,ATAPRDAD

         BR    15

         USING TAPEOP,15

TAPEOP   L     15,ATAPOPAD

         BR    15

         USING TAPEWT,15

TAPEWT   L     15,ATAPWTAD

         BR    15

         USING SEARCH,15

SEARCH   L     15,ASERCHAD

         BR    15

         USING BUFFTP,15

BUFFTP   L     15,ABUFTPAD

         BR    15

         USING TAPECH,15

TAPECH   L     15,ATAPXCAD

         BR    15

         USING CARDPN,15

CARDPN   L     15,ACRDPNAD

         BR    15

         USING DCOS,15

DCOS     L     15,DCOSAD

         BR    15

         USING DSIN,15

DSIN     L     15,DSINAD

         BR    15

IBSAVE   DS    16F

FOUR     DC    F'4'

ZERO     DC    H'0'

SAVEAREA DC    18F'0'

SYSCOMON DC    V(ATAPTB)

         DC    V(A0CON)

         DC    V(ASISTM)

         DC    V(APOSTP)

         DC    V(ATIME)

ATAPRDAD DC    F'0'

ATAPOPAD DC    F'0'

ATAPWTAD DC    F'0'

ASERCHAD DC    F'0'

ABUFTPAD DC    F'0'

ATAPXCAD DC    F'0'

ACRDPNAD DC    F'0'

AIBCOM   DC    F'0'

PDUMPAD  DC    F'0'

DUMPAD   DC    F'0'

DVCHKAD  DC    F'0'

OVERFLAD DC    F'0'

DCOSAD   DC    F'0'

DSINAD   DC    F'0'

FRDNLAD  DC    F'0'

FWRNLAD  DC    F'0'

COSAD    DC    F'0'

SINAD    DC    F'0'

CERRMAD  DC    F'0'

CLSETPAD DC    F'0'

CLREADAD DC    F'0'

SETMINAD DC    F'0'

CHKMINAD DC    F'0'

CONBCDAD DC    F'0'

INITAD   DC    F'0'

NNTAINAD DC    F'0'

PARNOMAD DC    F'0'

PARNEMAD DC    F'0'

PUNCHAAD DC    F'0'

PUNCHBAD DC    F'0'

PUNIDNAD DC    F'0'

PUNSEQAD DC    F'0'

PUNNUMAD DC    F'0'

PUNIDSAD DC    F'0'

PUNNOMAD DC    F'0'

SHIFTAD  DC    F'0'

ATAPRD   EQU   TAPERD

ATAPOP   EQU   TAPEOP

ATAPWT   EQU   TAPEWT

ASERCH   EQU   SEARCH

ABUFTP   EQU   BUFFTP

ATAPXC   EQU   TAPECH

ACRDPN   EQU   CARDPN

         END

*/

