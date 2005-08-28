/* ASTUF.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int astuf_(b, a)
real *b, *a;
{
    /* Parameter adjustments */
    --a;
    --b;

    /* Function Body */
    b[2] = a[1];
/* L10: */
    return 0;
} /* astuf_ */

