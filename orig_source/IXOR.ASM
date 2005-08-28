*     ASMBLR
*...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 ***
IXOR   START   0
*         IXOR IS AN 'EXCLUSIVE OR' FUNCTION FOR VTLAXS.
*         CALLING SEQUENCE IS
*           ITEST=IXOR(IX2,MASK)
*         ITEST IS SET TO 'EXCLUSIVE OR' RESULT (ONLY UNLIKE BITS = 1)
       SAVE    (14,12)
       BALR    11,0
       USING   *,11
       L       6,0(1)
       L       7,4(1)
       MVC     20(4,13),0(6)
       XC      20(4,13),0(7)
       RETURN  (14,12)
       END     IXOR

