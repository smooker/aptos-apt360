/* LINEV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int linev_(n1, n2, n3, n4)
integer *n1, *n2, *n3, *n4;
{
    /* Format strings */
    static char fmt_1[] = "(\002  LINEV\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *n1 = *n1;
    *n2 = *n2;
    *n3 = *n3;
    *n4 = *n4;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* linev_ */

