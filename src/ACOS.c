/* ACOS.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/*      REAL FUNCTION ACOS*8(A) */
doublereal acos_(a)
doublereal *a;
{
    /* System generated locals */
    doublereal ret_val, d__1;

    /* Builtin functions */
    double sqrt(), atan();

    /* Local variables */
    static doublereal b;

/* ...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 *** */

/* ...    ACOS IS ARC COSINE FUNCTION FOR VTLAXS. */
/* ...    ARGUMENT (A) IS COSINE OF DESIRED ANGLE. */
/* ...    ARC COSINE IS RETURNED IN RADIANS. */
/* ... */
/* Computing 2nd power */
    d__1 = *a;
    b = sqrt((float)1. - d__1 * d__1);
    ret_val = atan(b / *a);
    return ret_val;
} /* acos_ */

