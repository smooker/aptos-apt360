/* ATFMVC.f -- translated by f2c (version 20000121).
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

static doublereal c_b6 = .33333333333333331;

/* Subroutine */ int atfmvc_(it)
integer *it;
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(), sqrt();

    /* Local variables */
    static integer i__, j, k;
    static doublereal x, y, z__;
    static integer tt;
    static doublereal fac, det, sum;
#define kstyp ((integer *)&adfsto_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
    tt = *it;
    if (tt < 0) {
	goto L10;
    } else if (tt == 0) {
	goto L30;
    } else {
	goto L20;
    }
L10:
    tt = 0;
L20:
    x = adfsto_1.defsto[3];
    y = adfsto_1.defsto[4];
    z__ = adfsto_1.defsto[5];
    k = 4;
/*     TRANSFORM RADIUS OF CIRCLE, CYLINDER AND SPHERE */
    if (*kstyp != 4 && *kstyp != 5 && *kstyp != 13) {
	goto L40;
    }
    i__ = 10;
    if (*kstyp == 13) {
	i__ = 7;
    }
    det = atmaty_1.tmatx[0] * (atmaty_1.tmatx[5] * atmaty_1.tmatx[10] - 
	    atmaty_1.tmatx[9] * atmaty_1.tmatx[6]) - atmaty_1.tmatx[1] * (
	    atmaty_1.tmatx[4] * atmaty_1.tmatx[10] - atmaty_1.tmatx[6] * 
	    atmaty_1.tmatx[8]) + atmaty_1.tmatx[2] * (atmaty_1.tmatx[4] * 
	    atmaty_1.tmatx[9] - atmaty_1.tmatx[5] * atmaty_1.tmatx[8]);
    d__1 = abs(det);
    det = pow_dd(&d__1, &c_b6);
    adfsto_1.defsto[i__ - 1] *= det;
    goto L40;
L30:
    x = adfsto_1.defsto[6];
    y = adfsto_1.defsto[7];
    z__ = adfsto_1.defsto[8];
    k = a0con_1.k7;
L40:
    for (j = a0con_1.k1; j <= 9; j += 4) {
	sum = atmaty_1.tmatx[j - 1] * x + atmaty_1.tmatx[j] * y + 
		atmaty_1.tmatx[j + 1] * z__;
	if (tt == 0) {
	    goto L50;
	}
	adfsto_1.defsto[k - 1] = sum + atmaty_1.tmatx[j + 2];
	goto L60;
L50:
	adfsto_1.defsto[k - 1] = sum;
L60:
	k += a0con_1.k1;
/* L70: */
    }
/*     NORMALIZE VECTOR OF CYLINDER AND CONE */
    if (*it != 0) {
	goto L90;
    }
    if (*kstyp != 5 && *kstyp != 8) {
	goto L90;
    }
    fac = adfsto_1.defsto[6] * adfsto_1.defsto[6] + adfsto_1.defsto[7] * 
	    adfsto_1.defsto[7] + adfsto_1.defsto[8] * adfsto_1.defsto[8];
    if ((d__1 = fac - 1., abs(d__1)) <= 1e-12) {
	goto L90;
    }
    fac = 1. / sqrt(fac);
    for (k = 7; k <= 9; ++k) {
	adfsto_1.defsto[k - 1] *= fac;
/* L80: */
    }
L90:
    return 0;
} /* atfmvc_ */

#undef kstyp


