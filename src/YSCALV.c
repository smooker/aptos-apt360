/* YSCALV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int yscalv_(p, pt, n, m)
real *p, *pt;
integer *n, *m;
{
    /* Format strings */
    static char fmt_1[] = "(\002 YSCALE\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *p = *p;
    *pt = *pt;
    *n = *n;
    *m = *m;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* yscalv_ */

