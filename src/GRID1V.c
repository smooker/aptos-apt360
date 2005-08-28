/* GRID1V.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int grid1v_(k2, p, pt, pto, ptu, dx, dy, n, m, k, ip, ipx, 
	ipy)
integer *k2;
real *p, *pt, *pto, *ptu, *dx, *dy;
integer *n, *m, *k, *ip, *ipx, *ipy;
{
    /* Format strings */
    static char fmt_1[] = "(\002 GRID1V\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_1, 0 };


    *k2 = *k2;
    *p = *p;
    *ip = *ip;
    *pt = *pt;
    *ipx = *ipx;
    *pto = *pto;
    *ipy = *ipy;
    *ptu = *ptu;
    *dx = *dx;
    *dy = *dy;
    *n = *n;
    *m = *m;
    *k = *k;
/* L1: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* grid1v_ */

