/* ATDL.f -- translated by f2c (version 20000121).
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

/* Table of constant values */

static integer c_n1 = -1;

/* Subroutine */ int atdl_()
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer j;
    static doublereal sum, sum4;
    extern /* Subroutine */ int atfmvc_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
    atfmvc_(&c_n1);
    sum4 = adfsto_1.defsto[3] * adfsto_1.defsto[3] + adfsto_1.defsto[4] * 
	    adfsto_1.defsto[4] + adfsto_1.defsto[5] * adfsto_1.defsto[5];
    if ((d__1 = sum4 - 1., abs(d__1)) <= 1e-13) {
	goto L20;
    }
    sum4 = sqrt(sum4);
    adfsto_1.defsto[6] *= sum4;
    sum4 = 1. / sum4;
    for (j = 4; j <= 6; ++j) {
/* L10: */
	adfsto_1.defsto[j - 1] *= sum4;
    }
L20:
    sum = adfsto_1.defsto[3] * atmaty_1.tmatx[3] + adfsto_1.defsto[4] * 
	    atmaty_1.tmatx[7] + adfsto_1.defsto[5] * atmaty_1.tmatx[11];
    adfsto_1.defsto[6] += sum;
    return 0;
} /* atdl_ */

