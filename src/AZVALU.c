/* AZVALU.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal zsur[4];
} azurf_;

#define azurf_1 azurf_

/* Subroutine */ int azvalu_()
{
    /* Local variables */
#define defans ((doublereal *)&adfsto_1 + 3)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ...  THIS ROUTINE CALCULATES THE Z-COORDINATE */
/*     VALUE ON THE CURRENT ZSURF PLANE */
/*     FOR POINT DEFINITIONS YIELDING ONLY */
/* ...  X- AND Y-COORDINATE VALUES */

    defans[2] = (azurf_1.zsur[3] - azurf_1.zsur[0] * defans[0] - azurf_1.zsur[
	    1] * defans[1]) / azurf_1.zsur[2];
    return 0;
} /* azvalu_ */

#undef defans


