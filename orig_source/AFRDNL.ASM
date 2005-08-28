*  ASMBLR
AFRDNL   START 0
*        PROGRAM CALLS ANAMLT TO PRINT OUT DUMMY NAMELIST MESSAGE
         ENTRY FRDNL#,FWRNL#
         USING *,15
FRDNL#   EQU   *
FWRNL#   EQU   *
         LA    14,8(14)
         STM   14,12,SAVEREG
         LA    12,BASE
         USING *,12
BASE     ST    13,SAVEAREA+4
         LA    13,SAVEAREA
         CALL  ANAMLT
         L     13,SAVEAREA+4
         LM    14,12,SAVEREG
         BR    14
SAVEREG  DC    15F'0'
SAVEAREA DC    18F'0'
         END

