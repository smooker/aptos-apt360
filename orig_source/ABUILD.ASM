*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
ABUILD   START 0
*      *
*      * ABUILD(A,ICHAR)
*      * SHIFTS DATA IN DOUBLE WORD 'A' LEFT 8 BITS
*      * AND INSERTS THE 8-BIT CODE WHICH IS RIGHT JUSTIFIED
*      * IN 'ICHAR' INTO THE SIXTH BYTE OF 'A'.
*      *
         ENTRY ABUILD
         PRINT ON
*      *
         LR    0,2                SAVE GR2
         LM    1,2,0(1)           A(A) IN GR1, A(ICHAR) IN GR2
         MVC   0(5,1),1(1)        SHIFT LEFT
         MVC   5(1,1),3(2)        INSERT CHARACTER
         LR    2,0                RESTORE GR2
         BCR   15,14              RETURN
         END

