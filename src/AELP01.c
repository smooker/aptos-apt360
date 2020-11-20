/* AELP01.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal defprg[16];
} adfprg_;

#define adfprg_1 adfprg_

/* Subroutine */ int aelp01_()
{
    /* Local variables */
#define pm ((doublereal *)&adfprg_1 + 15)
#define deftab ((doublereal *)&avst_1 + 6200)
    extern /* Subroutine */ int aelhyp_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  E = ELLIPS/CENTER, SYM. PT. AT CENTER, LENGTH SEMI-MAJOR, $ */
/* ...             LENGTH SEMI-MINOR, ANGLE OF MAJOR AXIS WITH X-AXIS $$ */


/*     FOR HYPERB DEFINITION JSUBER IS NON-ZERO */
/* L10: */
    if (a1com_1.jsuber != 0) {
	goto L30;
    } else {
	goto L20;
    }
L20:
    *pm = (float)1.;
    goto L40;
L30:
    *pm = (float)-1.;
    a1com_1.jsuber = 0;
L40:
    aelhyp_();
    return 0;
} /* aelp01_ */

#undef deftab
#undef pm


