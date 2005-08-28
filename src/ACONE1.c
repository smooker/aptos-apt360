/* ACONE1.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    integer k1000, k1001, k1002, k1003, k1004, k1005;
} ac_;

#define ac_1 ac_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int acone1_()
{
    /* Builtin functions */
    double cos();

    /* Local variables */
    static integer i__, j, k, i1;
    extern /* Subroutine */ int anorm_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  CN = CONE/SYM. PT., SYM. VECTOR, HALF ANGLE IN DEGREES $$ */


/* L20: */
    azvect_(&deftab[6]);
    if (a1com_1.jsuber != 0) {
	goto L60;
    } else {
	goto L30;
    }
L30:
    if (deftab[9] - (float)90. >= 0.) {
	goto L60;
    } else {
	goto L40;
    }
L40:
    j = 0;
    for (k = a0con_1.k2; k <= 6; k += 4) {
	for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
	    i1 = k + i__;
	    j += a0con_1.k1;
/* L50: */
	    defans[j - 1] = deftab[i1 - 1];
	}
    }
    anorm_(&defans[3], &defans[3]);
    defans[6] = cos(deftab[9] / (float)57.29577951289617);
    return 0;
L60:
    a1com_1.jsuber = 1005;
    return 0;
} /* acone1_ */

#undef defans
#undef deftab


