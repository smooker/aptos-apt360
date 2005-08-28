/* AORDP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal dummy[1308], cscf[3], dscf[3], cftem[3], vtem[3], ptem1[3], 
	    ptem2[3], pt[18]	/* was [3][6] */, dot[6], fpnt[3], te2d[3], 
	    ti2d[3], cr, thds, thcs, tauds, taucs, percen, ans, res, pnttan[3]
	    , ex[3], ey[3], ez[3], vnul[3];
    integer icscf, idscf, itopt, n, idone, nrev, itfar, itc, ioc, ipc, intp, 
	    ier, nint, icase, itan;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

/* Table of constant values */

static integer c__724 = 724;
static integer c__740 = 740;

/* Subroutine */ int aordp_()
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k, ii, ill, kll;
    extern /* Subroutine */ int aerr_();
    static doublereal qnul;
    static integer ibmct;
    extern /* Subroutine */ int avdot_();
    static integer limit;
    extern /* Subroutine */ int avsub_(), avsto_(), avleng_();
    static integer nlimit;
    extern /* Subroutine */ int avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */

    qnul = 0.;
/*     TO ORDER  POINTS IN THE DIRECTION OF TRAVEL */

    ibmct = 0;
    limit = abs(a2cmmn_1.nint);
    i__1 = limit;
    for (i__ = 1; i__ <= i__1; ++i__) {
	avsub_(&a2cmmn_1.pt[i__ * 3 - 3], a2cmmn_1.te2d, a2cmmn_1.vtem);
	avleng_(a2cmmn_1.vtem, &a2cmmn_1.res);
	a2cmmn_1.vtem[2] = qnul;
	if (a2cmmn_1.idscf != 2) {
	    goto L5;
	}
/*     CIRCLE DS, NORMALIZE  SORTING VECTORS */
	avleng_(a2cmmn_1.vtem, &a2cmmn_1.dot[i__ - 1]);
	avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
	if (a2cmmn_1.ier != 1 && a2cmmn_1.dot[i__ - 1] >= a2cmmn_1.tauds) {
	    goto L5;
	}
	a2cmmn_1.dot[i__ - 1] = -1.;
	goto L10;
L5:
	a2cmmn_1.vtem[2] = qnul;
	avdot_(a2cmmn_1.ti2d, a2cmmn_1.vtem, &a2cmmn_1.dot[i__ - 1]);
	if (a2cmmn_1.idscf == 1 && a2cmmn_1.nint == -1 && a2cmmn_1.dot[0] < 
		qnul) {
	    aerr_(&c__724);
	}
	if (a2cmmn_1.idscf == 1 && a2cmmn_1.res < a2cmmn_1.tauds) {
	    a2cmmn_1.dot[i__ - 1] = -abs(a2cmmn_1.res);
	}
L10:
	;
    }


/*     NOW HAVE DOT PRODUCTS- SORT FROM LARGEST + TO SMALLEST NEG IN CIR- */
/*     CLE DS CASE - FROM LARGEST -TO+  IN LINE  CASE  (EFFECTIVELY THE */
/*     ORDER IN WHICH THE POINTS WILL BE ENCOUNTERED,ALTHO IN THE LINE CA */
/*     SE YOU HAVE ALREADY PASSED ANY ONE WITH NEGATIVE POT */

/*     TEST FOR SPECIAL CASE */
    if (limit == 1) {
	return 0;
    }
    nlimit = a2cmmn_1.nint - 1;
/* L20: */
    i__1 = nlimit;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ill = i__;
L30:
	ii = i__ + 1;
	i__2 = a2cmmn_1.nint;
	for (k = ii; k <= i__2; ++k) {
	    kll = k;
	    switch ((int)a2cmmn_1.idscf) {
		case 1:  goto L31;
		case 2:  goto L32;
	    }

/*     LINE */
L31:
	    if (a2cmmn_1.dot[ill - 1] > a2cmmn_1.dot[kll - 1]) {
		goto L35;
	    }
	    goto L40;

/*     CIRCLE */
L32:
	    if (a2cmmn_1.dot[i__ - 1] - a2cmmn_1.dot[k - 1] >= 0.) {
		goto L40;
	    } else {
		goto L35;
	    }

/*     REVERSE POINTS ANDOT VALUES AND  RESTART INNERMOST LOOP */
L35:
	    avsto_(&a2cmmn_1.pt[i__ * 3 - 3], a2cmmn_1.vtem);
	    avsto_(&a2cmmn_1.pt[k * 3 - 3], &a2cmmn_1.pt[i__ * 3 - 3]);
	    avsto_(a2cmmn_1.vtem, &a2cmmn_1.pt[k * 3 - 3]);
	    a2cmmn_1.ans = a2cmmn_1.dot[i__ - 1];
	    a2cmmn_1.dot[i__ - 1] = a2cmmn_1.dot[k - 1];
	    a2cmmn_1.dot[k - 1] = a2cmmn_1.ans;
	    ++ibmct;
	    if (ibmct > 100) {
		aerr_(&c__740);
	    }
	    goto L30;
L40:
	    ;
	}
/* L50: */
    }
    return 0;
} /* aordp_ */

