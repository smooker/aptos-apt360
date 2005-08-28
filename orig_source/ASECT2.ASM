*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
ASECT2   START 0
         ENTRY ATAPRD
         ENTRY ATAPOP
         ENTRY ATAPWT
         ENTRY ASERCH
         ENTRY ABUFTP
         ENTRY ATAPXC
         ENTRY ACRDPN
         ENTRY TAPERD
         ENTRY TAPEOP
         ENTRY TAPEWT
         ENTRY BUFFTP
         ENTRY TAPECH
         ENTRY CARDPN
         ENTRY IBCOM#
         ENTRY PDUMP,DUMP
         ENTRY SYSCOMON
         ENTRY ACNTRL
         ENTRY DVCHK,OVERFL
         ENTRY DCOS,DSIN,IHCERRM
         SAVE  (2,12),T,ASECT2
         USING ASECT2,12
         LR    12,15
         LA    10,SAVEAREA
         ST    10,8(0,13)
         ST    13,SAVEAREA+4
         LR    13,10
         MVC   ATAPRDAD(76),20(1)
         LM    2,6,0(1)
         LM    7,11,SYSCOMON
         MVC   0(92,7),0(2)     ATAPTB
         MVC   0(56,8),0(3)  A0CON
         MVC   0(88,9),0(4)  ASISTM
         MVC   0(160,10),0(5)  APOSTP
         STM   2,6,SECT0COM
         CALL  A2CTRL
         USING ACNTRL,12
ACNTRL   LR    12,15
         LM    2,6,SECT0COM
         LM    7,11,SYSCOMON
         MVC   0(92,2),0(7)
         MVC   0(56,3),0(8)
         MVC   0(88,4),0(9)
         MVC   0(160,5),0(10)
         SR    15,15
         L     13,SAVEAREA+4
         L     14,12(0,13)
         RETURN (0,12),T
SECT0COM DC    5F'0'
         USING IHCERRM,15
IHCERRM  L     15,CERRMAD
         BR    15
         DS    0F
         USING IBCOM#,15
IBCOM#   B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
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
SYSCOMON DC    V(ATAPTB)
         DC    V(A0CON)
         DC    V(ASISTM)
         DC    V(APOSTP)
         DC    F'0'
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
         DC    4F'0'
CERRMAD  DC    F'0'
SAVEAREA DC    18F'0'
ATAPRD   EQU   TAPERD
ATAPOP   EQU   TAPEOP
ATAPWT   EQU   TAPEWT
ASERCH   EQU   SEARCH
ABUFTP   EQU   BUFFTP
ATAPXC   EQU   TAPECH
ACRDPN   EQU   CARDPN
         END

