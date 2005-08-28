/* NXV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

integer nxv_(a)
real *a;
{
    /* Format strings */
    static char fmt_1[] = "(\002 FRAMEV\002)";

    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *a = *a;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return ret_val;
} /* nxv_ */

