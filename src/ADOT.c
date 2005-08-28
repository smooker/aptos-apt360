/* ADOT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int adot_(a, b, dot)
doublereal *a, *b, *dot;
{
    static integer i__;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    *dot = (float)0.;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	*dot = a[i__] * b[i__] + *dot;
    }
    return 0;
} /* adot_ */

