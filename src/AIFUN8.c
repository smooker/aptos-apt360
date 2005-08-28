/* AIFUN8.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Subroutine */ int aifun8_(a, name__)
doublereal *a, *name__;
{
    /* Initialized data */

    static integer ipl[5] = { 100000,10000,1000,100,10 };

    /* System generated locals */
    static doublereal equiv_0[1];

    /* Local variables */
#define b (equiv_0)
    static integer i__, ia;
#define lb ((logical1 *)equiv_0)
    static logical1 lc[10], ibl;
    static integer ind;


/* ...  CONVERTS DOUBLE PRECISION FLOATING POINT NUMBER @A@ TO AN 8 BYTE */
/* ...  EBCDIC INTEGER ( 6 DIGITS MAXIMUM ) WITH LEADING BLANKS, */
/* ...  AND STORES THE RESULT IN ARGUMENT @NAME@ */

/*      DATA LC/ZF0,ZF1,ZF2,ZF3,ZF4,ZF5,ZF6,ZF7,ZF8,ZF9/ */
/*      DATA IBL/Z40/ */

	lc[0]=0;
	lc[1]=1;
	lc[2]=2;
	lc[3]=3;
	lc[4]=4;
	lc[5]=5;
	lc[6]=6;
	lc[7]=7;
	lc[8]=8;
	lc[9]=9;
	ibl=0x40;
	
/*     CONVERT TO INTEGER */
    ia = (integer) (*a);
/*     TRUNCATE */
    ind = ia / 1000000;
    ia -= ind * 1000000;
/*     LEADING ZEROS */
    lb[OTHER_ENDIAN_8(0)] = lc[0];
    lb[OTHER_ENDIAN_8(1)] = lc[0];
    for (i__ = 1; i__ <= 5; ++i__) {
	ind = ia / ipl[i__ - 1];
	ia -= ind * ipl[i__ - 1];
/* L10: */
	lb[OTHER_ENDIAN_8(i__ + 1)] = lc[ind];
    }
    lb[OTHER_ENDIAN_8(7)] = lc[ia];
/*     PUT IN LEADING BLANKS */
    for (i__ = 1; i__ <= 7; ++i__) {
	if (lc[0] != lb[OTHER_ENDIAN_8(i__ - 1)]) {
	    goto L30;
	}
/* L20: */
	lb[OTHER_ENDIAN_8(i__ - 1)] = ibl;
    }
L30:
    *name__ = b[0];
    return 0;
} /* aifun8_ */

#undef lb
#undef b


