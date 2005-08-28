/* SECTN2.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int sectn2_()
{
    /* Format strings */
    static char fmt_6[] = "(\0021\002,\002***WARNING ... DAC ARELEM NOT FOUN\
D***\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, fmt_6, 0 };


/*     *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 3 *** */
/* L6: */
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* sectn2_ */

