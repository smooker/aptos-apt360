/* AMATM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

/* Subroutine */ int amatm_(nsize)
integer *nsize;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, j4, j2, j3, j5, j1, ns, nts;
    static doublereal sum;

/* L1: */
    ns = *nsize;
/* L2: */
    nts = ns * ns;
/* L3: */
    j4 = ns + a0con_1.k1;
/* L4: */
    j2 = 1 - ns;
/* L5: */
    i__1 = nts;
    for (j = 1; j <= i__1; ++j) {
/* L6: */
	if (j4 - ns >= 0) {
	    goto L7;
	} else {
	    goto L11;
	}
L7:
	j2 += ns;
/* L8: */
	j3 = j2 + ns - a0con_1.k1;
/* L9: */
	j4 = a0con_1.k1;
/* L10: */
	goto L12;
L11:
	j4 += a0con_1.k1;
L12:
	j5 = j4;
/* L13: */
	sum = (float)0.;
/* L14: */
	i__2 = j3;
	for (j1 = j2; j1 <= i__2; ++j1) {
/* L15: */
	    sum = atmaty_1.xmat1[j1 - 1] * atmaty_1.xmat2[j5 - 1] + sum;
/* L16: */
	    j5 += ns;
/* L17: */
	}
/* L18: */
	atmaty_1.xmat3[j - 1] = sum;
/* L19: */
    }
/* L20: */
    return 0;
} /* amatm_ */

