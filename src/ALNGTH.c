/* ALNGTH.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int alngth_(a, scalar)
doublereal *a, *scalar;
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 *** */
    /* Parameter adjustments */
    --a;

    /* Function Body */
/* Computing 2nd power */
    d__1 = a[1];
/* Computing 2nd power */
    d__2 = a[2];
/* Computing 2nd power */
    d__3 = a[3];
    *scalar = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    return 0;
} /* alngth_ */

