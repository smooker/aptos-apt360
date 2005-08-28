/* AGENCN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int agencn_(n)
integer *n;
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*               *          *          *          *         * */
/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L200;
    }

/* ...  GC = GCONIC/A,B,C,D,E,F $$ */

L100:
    defans[0] = deftab[1];
    defans[1] = deftab[3];

/* ...  DEFANS(3) = 0. */

    defans[3] = deftab[6];

/* ...  DEFANS(5) = 0. */
/* ...  DEFANS(6) = 0. */

    defans[6] = deftab[2] / (float)2.;
    defans[7] = deftab[4] / (float)2.;
    defans[8] = deftab[5] / (float)2.;

/* ...  DEFANS(10) = 0. */

    goto L240;
L200:
/* Computing 2nd power */
    d__1 = deftab[1];
    defans[0] = d__1 * d__1 - deftab[3];
    defans[1] = (float)1.;

/* ...  DEFANS(3) = 0. */

/* Computing 2nd power */
    d__1 = deftab[2];
    defans[3] = d__1 * d__1 - deftab[5];

/* ...  DEFANS(5) = 0. */
/* ...  DEFANS(6) = 0. */

    defans[6] = -deftab[1];
    defans[7] = (deftab[1] * (float)2. * deftab[2] - deftab[4]) / (float)2.;
    defans[8] = -deftab[2];

/* ...  DEFANS(10) = 0. */

    if (idftab[OTHER_ENDIAN_S(13)] != 4) {
	goto L240;
    }
/* L150: */
    deftab[7] = defans[0];
    defans[0] = defans[1];
    defans[1] = deftab[7];
    deftab[7] = defans[7];
    defans[7] = defans[8];
    defans[8] = deftab[7];
L240:
    return 0;
} /* agencn_ */

#undef defans
#undef idftab
#undef deftab


