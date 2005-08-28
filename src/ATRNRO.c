/* ATRNRO.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int atrnro_(x1, y1, x11, y11, ra, iz)
doublereal *x1, *y1, *x11, *y11, *ra;
integer *iz;
{
    /* Builtin functions */
    double sin(), cos();

    /* Local variables */
    static doublereal tc, ts;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 *** */
/* ... */
/* ...  ROTATE (X1,Y1) BY ANGLE RA IN DIRECTION DETERMINED BY SIGN OF IZ. */
/* ...  PUT ROTATED COORDINATES IN (X11,Y11). */
/* ... */
    ts = sin(*ra);
    tc = cos(*ra);
    if (*iz >= 0) {
	goto L1;
    } else {
	goto L2;
    }
L1:
    *x11 = *x1 * tc - *y1 * ts;
    *y11 = *x1 * ts + *y1 * tc;
    goto L3;
L2:
    *x11 = *x1 * tc + *y1 * ts;
    *y11 = -(*x1) * ts + *y1 * tc;
L3:
    return 0;
} /* atrnro_ */

