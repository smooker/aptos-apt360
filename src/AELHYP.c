/* AELHYP.f -- translated by f2c (version 20000121).
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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal defprg[16];
} adfprg_;

#define adfprg_1 adfprg_

/* Subroutine */ int aelhyp_()
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sin(), cos();

    /* Local variables */
#define pm ((doublereal *)&adfprg_1 + 15)
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  CALCULATES GENERAL EQUATION FOR THE ELLIPSE */
/* ...  AND HYPERBOLA. PM IS FLAG = +1 FOR ELLIPSE */
/* ...                              -1 FOR HYPERBOLA */


/* ...  DEFTAB(11,12,...,16) = SIN THETA,COS THETA,SIN THETA**2, */
/* ...                         COS THETA**2,B**2,A**2, RESPECTIVELY */

    deftab[10] = sin(deftab[8] / (float)57.29577951289617);
    deftab[11] = cos(deftab[8] / (float)57.29577951289617);
/* Computing 2nd power */
    d__1 = deftab[10];
    deftab[12] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = deftab[11];
    deftab[13] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = deftab[7];
    deftab[14] = d__1 * d__1;
/* Computing 2nd power */
    d__1 = deftab[6];
    deftab[15] = d__1 * d__1;
    defans[0] = deftab[14] * deftab[13] + *pm * deftab[15] * deftab[12];
    defans[1] = deftab[14] * deftab[12] + *pm * deftab[15] * deftab[13];

/* ...  DEFANS(3) = 0. */

/* Computing 2nd power */
    d__1 = deftab[3] * deftab[11] + deftab[4] * deftab[10];
/* Computing 2nd power */
    d__2 = deftab[3] * deftab[10] - deftab[4] * deftab[11];
    defans[3] = deftab[14] * (d__1 * d__1) + *pm * deftab[15] * (d__2 * d__2) 
	    - deftab[14] * deftab[15];

/* ...  DEFANS(5) = 0. */
/* ...  DEFANS(6) = 0. */
/* ...  DEFANS(7) = 2H */

    defans[6] = deftab[10] * deftab[11] * (deftab[14] - *pm * deftab[15]);

/* ...  DEFANS(8) = 2P */

    defans[7] = deftab[4] * deftab[10] * deftab[11] * (*pm * deftab[15] - 
	    deftab[14]) - deftab[3] * (deftab[14] * deftab[13] + *pm * deftab[
	    15] * deftab[12]);

/* ...  DEFANS(9) = 2Q */

    defans[8] = deftab[3] * deftab[10] * deftab[11] * (*pm * deftab[15] - 
	    deftab[14]) - deftab[4] * (deftab[14] * deftab[12] + *pm * deftab[
	    15] * deftab[13]);

/* ...  DEFANS(10) = 0. */

    return 0;
} /* aelhyp_ */

#undef defans
#undef deftab
#undef pm


