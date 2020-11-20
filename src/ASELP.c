/* ASELP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal dummy[1308], cscf[3], dscf[3], cftem[3], vtem[3], ptem1[3], 
	    ptem2[3], pt[18]	/* was [3][6] */, dot[6], fpnt[3], te2d[3], 
	    ti2d[3], cr, thds, thcs, tauds, taucs, percen, ans, res, pnttan[3]
	    , ex[3], ey[3], ez[3], vnul[3];
    integer icscf, idscf, itopt, n, idone, nrev, itfar, itc, ioc, ipc, intp, 
	    ier, nint, icase, itan;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__724 = 724;
static integer c__0 = 0;

/* Subroutine */ int aselp_()
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, kk, iacc;
    extern /* Subroutine */ int aerr_(), avadd_(), aviol_(), avsub_();
    static integer iviol;
    extern /* Subroutine */ int avsto_(), adecis_(), avleng_(), avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */

/* ...  SELECTS FINAL POINT */

/* ...  SET COUNTERS FOR TO,ON AND PAST, AND INITIALIZE IDONE FOR ADECIS */

    a2cmmn_1.idone = 0;
L1:
    a2cmmn_1.itc = 0;
    a2cmmn_1.ioc = 0;
    a2cmmn_1.ipc = 0;
/*      SPECIAL CASE CHECK */
/*      (TANTO) */
    if (a2cmmn_1.nint == -1) {
	goto L100;
    }

/* ...  SEE IF CURRENTLY VIOLATING SURFACE */
    if (a2cmmn_1.icase == 2 && a2cmmn_1.nint == 2) {
	goto L200;
    }
    goto L210;
L200:
    if (a2cmmn_1.itopt != 2 && a2cmmn_1.itopt != 4) {
	goto L150;
    }
L210:
    aviol_(a2cmmn_1.te2d, &iviol);
    if (a2cmmn_1.itopt == 1 && iviol == 0 && a2cmmn_1.cr < a2cmmn_1.taucs) {
	a2cmmn_1.taucs = a2cmmn_1.cr * .9;
    }
    if (a2cmmn_1.idscf != 1 || a2cmmn_1.nint != 6) {
	goto L300;
    }
    if (a2cmmn_1.dot[0] >= (float)0. || a2cmmn_1.dot[1] >= (float)0.) {
	goto L300;
    }
    if (a2cmmn_1.dot[2] < (float)0. || iviol != 0) {
	goto L300;
    }
    a2cmmn_1.dot[2] = -a2cmmn_1.dot[2];
L300:
    if (a2cmmn_1.icase < 3) {
	goto L5;
    }
    if (a2cmmn_1.cr <= 0.) {
	goto L5;
    }
    if (a2cmmn_1.itopt == 2 || a2cmmn_1.itopt == 4) {
	goto L5;
    }
    if (a2cmmn_1.nint != 2) {
	goto L5;
    }
    avmult_(a2cmmn_1.ti2d, &a2cmmn_1.taucs, a2cmmn_1.ptem1);
    avadd_(a2cmmn_1.ptem1, a2cmmn_1.te2d, a2cmmn_1.ptem2);
    avadd_(a2cmmn_1.ptem1, a2cmmn_1.ptem2, a2cmmn_1.ptem2);
    aviol_(a2cmmn_1.ptem2, &iviol);
L5:
/*     SET INTP      0 FOR NEXT IS TO */
/*                   1 FOR NEXT IS PAST */
    a2cmmn_1.intp = 0;
    if (iviol == 1) {
	a2cmmn_1.intp = 1;
    }
    if (a2cmmn_1.nint != 2) {
	goto L9;
    }
    if (a2cmmn_1.icase != 3) {
	goto L9;
    }
    if (a2cmmn_1.itopt == 3) {
	goto L9;
    }
    if (a2cmmn_1.itopt == 1 && iviol == 0) {
	goto L9;
    }
    a2cmmn_1.ans = a2cmmn_1.cscf[0] * (a2cmmn_1.te2d[0] - a2cmmn_1.pt[0]) + 
	    a2cmmn_1.cscf[1] * (a2cmmn_1.te2d[1] - a2cmmn_1.pt[1]);
    if (abs(a2cmmn_1.ans) - a2cmmn_1.taucs >= 0.) {
	goto L6;
    }
    a2cmmn_1.ans = a2cmmn_1.cscf[0] * a2cmmn_1.ti2d[0] + a2cmmn_1.cscf[1] * 
	    a2cmmn_1.ti2d[1];
L6:
    a2cmmn_1.ans *= a2cmmn_1.cscf[0] * (a2cmmn_1.dscf[0] - a2cmmn_1.pt[0]) + 
	    a2cmmn_1.cscf[1] * (a2cmmn_1.dscf[1] - a2cmmn_1.pt[1]);
    a2cmmn_1.intp = 0;
    if (a2cmmn_1.ans <= 0.) {
	a2cmmn_1.intp = 1;
    }
L9:
/* ...  BEGIN EXAMINATION OF POINTS */

    i__1 = a2cmmn_1.nint;
    for (i__ = 1; i__ <= i__1; ++i__) {

/* ...  IF DS IS LINE AND DOT IS NEGATIVE, SKIP */

	if (a2cmmn_1.idscf == 1 && a2cmmn_1.dot[i__ - 1] <= (float)0.) {
	    goto L50;
	}

/* ...  SEE IF POINT IS AN ON  TYPE */

	aviol_(&a2cmmn_1.pt[i__ * 3 - 3], &iviol);
	if (iviol == 1) {
	    goto L10;
	}

/* ...  NOT ON, CHECK TO,PAST */

	if (a2cmmn_1.intp == 0) {
	    goto L20;
	}
	if (a2cmmn_1.intp == 1) {
	    goto L30;
	}

/* ...  ON */

L10:
	++a2cmmn_1.ioc;
	adecis_(&c__2, &a2cmmn_1.ioc, &iacc);
	if (iacc == 1) {
	    goto L80;
	}
	a2cmmn_1.intp = 1;
	goto L50;
/* ...  TO */

L20:
	++a2cmmn_1.itc;
	a2cmmn_1.intp = 1;
	adecis_(&c__1, &a2cmmn_1.itc, &iacc);
	if (iacc == 1) {
	    goto L80;
	}
	goto L50;

/* ...  PAST */

L30:
	++a2cmmn_1.ipc;
	a2cmmn_1.intp = 0;
	adecis_(&c__3, &a2cmmn_1.ipc, &iacc);
	if (iacc == 1) {
	    goto L80;
	}
	goto L50;

/* ...  STORE FINAL POINT */
L80:
	avsto_(&a2cmmn_1.pt[i__ * 3 - 3], a2cmmn_1.fpnt);
	return 0;

/* ...  LOOP END */

L50:
	;
    }

/* ...  IF EVER FALL THROUGH, HAVE NOT   ACCEPTED ANY POINT */
/*      TEST FOR SPECIAL CASE ... IF SO, TRY AGAIN */
    if (a2cmmn_1.icase < 3) {
	goto L99;
    }
    kk = a2cmmn_1.nint % 2;
    if (kk != 1) {
	goto L99;
    }
    if (a2cmmn_1.itfar != 2) {
	goto L99;
    }
    a2cmmn_1.itfar = 1;
    ++a2cmmn_1.nrev;
    goto L1;
L99:
    if (a2cmmn_1.icase != 1 || a2cmmn_1.itopt != 3 || a2cmmn_1.dot[2] <= 0.) {
	aerr_(&c__724);
    }
    avsto_(&a2cmmn_1.pt[6], a2cmmn_1.fpnt);
    return 0;
L100:
    avsto_(a2cmmn_1.pt, a2cmmn_1.fpnt);

/* ...  CALL ADECIS TO SET REVOLUTION COUNTER NREV */
    a2cmmn_1.idone = 0;
    adecis_(&c__0, &c__0, &iacc);
    avsub_(a2cmmn_1.te2d, a2cmmn_1.fpnt, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    if (a2cmmn_1.ans < a2cmmn_1.tauds * .5) {
	++a2cmmn_1.nrev;
    }
    return 0;
L150:
    if (a2cmmn_1.n > 1) {
	goto L153;
    }
    if (a2cmmn_1.itopt == 1 && a2cmmn_1.dot[0] > 0.) {
	goto L151;
    }
    if (a2cmmn_1.itopt == 3 && a2cmmn_1.dot[1] > 0.) {
	goto L152;
    }
L153:
    aerr_(&c__724);
L151:
    avsto_(a2cmmn_1.pt, a2cmmn_1.fpnt);
    return 0;
L152:
    avsto_(&a2cmmn_1.pt[3], a2cmmn_1.fpnt);
    return 0;
} /* aselp_ */

