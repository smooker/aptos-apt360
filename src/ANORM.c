/* ANORM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int anorm_(a, b)
doublereal *a, *b;
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__;
    static doublereal s;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */

/* ...  NORMALIZE VECTOR A, AND STORE IN B */


    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
/* Computing 2nd power */
    d__1 = a[1];
/* Computing 2nd power */
    d__2 = a[2];
/* Computing 2nd power */
    d__3 = a[3];
    s = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    for (i__ = 1; i__ <= 3; ++i__) {
	b[i__] = a[i__] / s;
	if ((d__1 = b[i__], abs(d__1)) - (float)1e-6 <= 0.) {
	    goto L10;
	} else {
	    goto L20;
	}
L10:
	b[i__] = (float)0.;
L20:
	;
    }
    return 0;
} /* anorm_ */

