/* ANAMLT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal atapes[10];
    integer intape, ioutap;
    real puntap;
} ataptb_;

#define ataptb_1 ataptb_

/* Subroutine */ int anamlt_()
{
    /* Format strings */
    static char fmt_5[] = "(\002 *****     THIS IS A DUMMY NAMELIST SUBROUTI\
NE     *****\002//\002 TO OBTAIN THE CORRECT NAMELIST ROUTINES THE ASECT0 LO\
AD\002/\002 MODULE MUST BE LINK EDITED WITH THE FOLLOWING CARDS:\002//\002  \
REPLACE AFRDNL\002/\002  REPLACE ANAMLT#\002/\002  REPLACE FRDNL#\002/\002  \
REPLACE FWRNL#\002//\002 THIS WILL ALLOW THE REAL NAMELIST ROUTINES TO BE\
\002/\002 RETRIEVED FROM THE FORTRAN LIBRARY\002//\002 *********************\
**********************************\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 0, 0, fmt_5, 0 };


    io___1.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___1);
    e_wsfe();
    return 0;
} /* anamlt_ */

