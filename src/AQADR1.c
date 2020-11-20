/* AQADR1.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int aqadr1_()
{
    /* Local variables */
    static integer k;
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  Q = QADRIC/A,B,C,F,G,H,P,Q,R,D $$ */


    for (k = 1; k <= 3; ++k) {
/* L10: */
	defans[k - 1] = deftab[k];
    }
    defans[3] = deftab[10];
    for (k = 5; k <= 10; ++k) {
/* L20: */
	defans[k - 1] = deftab[k - 1] / (float)2.;
    }
    return 0;
} /* aqadr1_ */

#undef defans
#undef deftab


