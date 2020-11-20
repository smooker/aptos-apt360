/* ASCHTB.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Subroutine */ int aschtb_(ifo, xs, ys, er)
integer *ifo;
doublereal *xs, *ys, *er;
{
    /* Format strings */
    static char fmt_12[] = "(\0020TABCYL INTERVAL NOT FOUND\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6201)
    static integer i__;
#define id ((integer *)&avst_1 + 12402)
    static integer nap;
#define deftab ((doublereal *)&avst_1 + 6200)

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_12, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */

/* .....SEARCH FOR TABCYL INTERVAL */

/* .......THIS VERSION OF SCHTB INCORPORATES 4Q65 LOGIC---LINES ADDED OR */
/*     ALTERED 12590032,34,36,90 ,100,110,120,150,160,180,190,200,215,220 */
/*     250,260,270,280 */
/* *********************************************************************** */
    nap = id[OTHER_ENDIAN_S((*ifo << 1) - 1)] - 1;
    *ifo += 11;
    i__1 = nap;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = d__[*ifo - 1] - *xs, abs(d__1)) - (float).01 <= 0.) {
	    goto L2;
	} else {
	    goto L1;
	}
L2:
	if ((d__1 = d__[*ifo] - *ys, abs(d__1)) - (float).01 <= 0.) {
	    goto L8;
	} else {
	    goto L1;
	}
L1:
	*ifo += 7;
/* L11: */
    }
    if (*er != 0.) {
	goto L13;
    } else {
	goto L111;
    }
L111:
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    e_wsfe();
L13:
    *er = (float)1.;
    return 0;
L8:
    *er = (float)0.;
    return 0;
} /* aschtb_ */

#undef deftab
#undef id
#undef d__


