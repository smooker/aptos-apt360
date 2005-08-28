/* DXDYV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dxdyv_(k1, p, r__, dx, n, i2, nx, dc, ierr)
integer *k1;
real *p, *r__, *dx;
integer *n, *i2, *nx;
real *dc;
integer *ierr;
{
    /* Format strings */
    static char fmt_1[] = "(\002  DXDYV\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *k1 = *k1;
    *p = *p;
    *r__ = *r__;
    *dx = *dx;
    *n = *n;
    *i2 = *i2;
    *nx = *nx;
    *dc = *dc;
    *ierr = *ierr;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* dxdyv_ */

