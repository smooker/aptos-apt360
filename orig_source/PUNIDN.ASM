*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
PUNIDN   START 0
*              PUNIDN-PUNSEQ-PUNNUM
*                SYSTEM/360 APT
*---------------------------------------------------------------------
* CALL PUNIDN (A) WHERE
* A IS THE ADDRESS FIELD OF 4 BCD CHRS.
*---------------------------------------------------------------------
* CALL PUNSEQ (B) WHERE
* B WILL BE THE STARTING SEQUENCE NUMBER TO BE PUNCHED
* B IS A FLOATING-POINT SINGLE PRECISION NUMBER
*---------------------------------------------------------------------
* CALL PUNNUM (C) WHERE
* C WILL BE GIVEN THE LATEST SEQUENCE NUMBER BEING USED ON CARD OUTPUT
* THE SEQUENCE NUMBER WILL BE A FLOATING PT SINGLE PRECISION NUMBER
*
         ENTRY PUNSEQ
         ENTRY PUNNUM
         ENTRY PUNIDS
         ENTRY PUNNOM
BASEREG1 EQU   12
CALLREG  EQU   11
ARGREG   EQU   3
         USING PUNIDN,BASEREG1
         USING CALLLIST,CALLREG
         USING ARGUMENT,ARGREG
BASE     SAVE  (2,12),T,PUNIDN
         LR    BASEREG1,15
         LR    CALLREG,1
         L     3,A           GET A'S ADDRESS
         MVC   PUNIDS(4),VALUE     MOVE A TO PUNIDS
         RETURN (14,12),T
         CNOP  0,4
PUNSEQ   SAVE  (2,12),T,PUNSEQ
         L     BASEREG1,POINTER-PUNSEQ(0,15)
         LR    CALLREG,1
         L     3,B
         MVC   PUNNOM(4),VALUE     MOVE B TO PUNNOM
         RETURN (14,12),T
         CNOP  0,4
PUNNUM   SAVE  (2,12),T,PUNNUM
         L     BASEREG1,POINTER-PUNNUM(0,15)
         LR    CALLREG,1
         L     3,C
         MVC   0(4,3),PUNNOM       MOVE PUNNOM TO C
         RETURN (14,12),T
PUNNOM   DC    F'0'
PUNIDS   DC    C'    '
POINTER  DC    A(BASE)
CALLLIST DSECT
ARGUMNT1 DS    A
ARGUMENT DSECT
VALUE    DS    A
         CSECT
IDN      EQU   CALLLIST
A        EQU   ARGUMNT1
SEQ      EQU   CALLLIST
B        EQU   ARGUMNT1
NUM      EQU   CALLLIST
C        EQU   ARGUMNT1
         END

