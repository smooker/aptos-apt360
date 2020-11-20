/* ASIMEQ.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int asimeq_()
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal a[12]	/* was [3][4] */;
    static integer i__, j, k, l, kk, ll;
    static doublereal bug, unk[4], gnat, temp;
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer nprmut[3];

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  SOLVES THREE SIMULTANEOUS EQUATIONS BY GAUSSIAN ELIMINATION */
/*     THE COEFFICIENTS OF THE UNKNOWNS AND THEIR RESPECTIVE CONSTANT */
/*     MUST BE STORED SEQUENTIALLY BY ROWS STARTING IN DEFTAB(100) */
/*     BEFORE THE SUBROUTINE IS ENTERED. THE SOLUTIONS TO THE EQUATIONS */
/*     ARE STORED SEQUENTIALLY STARTING IN DEFTAB(112). THE DEFERMINANT */
/*     IS STORED IN DEFTAB(115). */
/*     THE DETERMINANT IS TESTED, AND IF FOUND TO BE ZERO, JSUBER IS */
/* ...  SET TO 1005 BEFORE RETURNING. */



    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
/* L10: */
	nprmut[i__ - 1] = i__;
    }
    deftab[114] = (float)0.;
    unk[3] = (float)0.;
    k = 100;
    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
	for (j = a0con_1.k1; j <= 4; ++j) {
	    a[i__ + j * 3 - 4] = deftab[k - 1];
/* L20: */
	    k += a0con_1.k1;
	}
    }
    for (k = a0con_1.k1; k <= 2; ++k) {
	gnat = a[k + k * 3 - 4];
	if (abs(gnat) - (float)1e-4 <= 0.) {
	    goto L30;
	} else {
	    goto L68;
	}
L30:
	for (j = k; j <= 3; ++j) {
	    if ((d__1 = a[k + j * 3 - 4], abs(d__1)) - (float)1e-4 <= 0.) {
		goto L40;
	    } else {
		goto L50;
	    }
L40:
	    ;
	}
	goto L140;
L50:
	for (l = a0con_1.k1; l <= 3; ++l) {
	    temp = a[l + j * 3 - 4];
	    a[l + j * 3 - 4] = a[l + k * 3 - 4];
/* L60: */
	    a[l + k * 3 - 4] = temp;
	}
	if (k >= 2) {
	    goto L65;
	}
	nprmut[k - 1] = j;
	nprmut[j - 1] = k;
	goto L68;
L65:
	temp = (doublereal) nprmut[k - 1];
	nprmut[k - 1] = nprmut[j - 1];
	nprmut[j - 1] = (integer) temp;
L68:
	gnat = a[k + k * 3 - 4];
/* L70: */
	for (j = k; j <= 4; ++j) {
/* L80: */
	    a[k + j * 3 - 4] /= gnat;
	}
	kk = k + a0con_1.k1;
	for (i__ = kk; i__ <= 3; ++i__) {
	    bug = a[i__ + k * 3 - 4];
	    for (j = k; j <= 4; ++j) {
/* L90: */
		a[i__ + j * 3 - 4] -= a[k + j * 3 - 4] * bug;
	    }
	}
    }
    if (abs(a[8]) - (float)1e-5 <= 0.) {
	goto L140;
    } else {
	goto L100;
    }
L100:
    a[11] /= a[8];
    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
	k = a0con_1.k4 - i__;
	kk = k + a0con_1.k1;
	unk[k - 1] = a[k + 8];
	for (j = kk; j <= 4; ++j) {
/* L110: */
	    unk[k - 1] -= unk[j - 1] * a[k + j * 3 - 4];
	}
    }
    deftab[114] = a[8];
    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
/* ... */
/* ...  CODE CHANGED TO AGREE WITH VERSION SEVEN */
/* ... */
	ll = nprmut[i__ - 1];
	deftab[ll + 110] = unk[i__ - 1];
/* L130: */
    }
    goto L150;
L140:
    a1com_1.jsuber = 1005;
L150:
    return 0;
} /* asimeq_ */

#undef deftab


