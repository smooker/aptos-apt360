/* ACROSS.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int across_(a, b, c__)
doublereal *a, *b, *c__;
{
    static doublereal c1, c2, c3;


/* ...  TAKE THE CROSS PRODUCT OF TWO VECTORS... C = A X B */


    /* Parameter adjustments */
    --c__;
    --b;
    --a;

    /* Function Body */
    c1 = a[2] * b[3] - a[3] * b[2];
    c2 = a[3] * b[1] - a[1] * b[3];
    c3 = a[1] * b[2] - a[2] * b[1];
    c__[1] = c1;
    c__[2] = c2;
    c__[3] = c3;
    return 0;
} /* across_ */

