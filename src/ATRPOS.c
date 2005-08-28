/* ATRPOS.f -- translated by f2c (version 20000121).
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

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int atrpos_(n)
integer *n;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, j1, j2, ns, ns2;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
    ns = *n;
    ns2 = ns * ns;
    j1 = a0con_1.k0;
    j2 = ns2 + a0con_1.k2;
    i__1 = ns2;
    for (j = a0con_1.k1; j <= i__1; ++j) {
	if (j2 - ns2 + ns - j1 >= 0) {
	    goto L10;
	} else {
	    goto L20;
	}
L10:
	j1 += a0con_1.k1;
	j2 = j1;
	goto L25;
L20:
	j2 += ns;
L25:
	atmaty_1.xmat1[j - 1] = atmaty_1.xmat2[j2 - 1];
/* L30: */
    }
    return 0;
} /* atrpos_ */

