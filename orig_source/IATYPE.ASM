*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
IATYPE   START 0
*      *
*      * INTEGER FUNCTION IATYPE(N)
*      * EXTRACTS LOW ORDER BYTE OF ICLASS(N)
*      *
         ENTRY IATYPE
         EXTRN AILMTB
*      *
         USING *,15
         L     1,0(0,1)           ADD. OF 'N'
         L     1,0(0,1)           SUBSCRIPT 'N'
         SLL   1,2                MULTIPLY FOR INTEGER*4 ARRAY
         A     1,ICLASS           ADD COMMON AREA ADD.
         SR    0,0                CLEAR FUNCTION RETURN REG.
         IC    0,3(0,1)           INSERT LOW ORDER CHARACTER
         BCR   15,14              RETURN
ICLASS   DC    A(AILMTB+4796)     A(ICLASS-4)
         END

