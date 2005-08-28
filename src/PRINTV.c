/* PRINTV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int printv_(n, pprint, nx, ny)
integer *n;
real *pprint;
integer *nx, *ny;
{
    /* Format strings */
    static char fmt_1[] = "(\002 PRINTV\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *n = *n;
    *pprint = *pprint;
    *nx = *nx;
    *ny = *ny;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* printv_ */

