/* ACCINT.f -- translated by f2c (version 20000121).
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

struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

struct {
    doublereal q15x01, qp9x01, qp6x01, qp5x01, qp4x01, qp0001, qp001, qp01, 
	    qp1, q1p, q10p, q1000p, q1pe5, q1pe6, q1pe10, q1pe20, q1pe30, 
	    q1pe36, q1pe38, qp8x01, qp7x01, qp4x09, qp9, qp99, qp995, qp997, 
	    qp999, qp9999, qp4x95, qp5x95, qp6x9, qp7x9, qp6x05, qp5x05, 
	    qp4x05, qp0005, qp005, qp05, qp5, q5p, q4x045, qp0002, qp0047, 
	    qp017, q1rad, qp0349, qp125, qp6, qp2, qp2499, qp25, qp3, qp7, 
	    qp75, qp8, qp866, q1p01, q1p1, q1p2, q1p25, q1p5, q2p, q2p5, q3p, 
	    q3p5, q4p, q8p, q11p, q45p, q90p, q130p, q4500p, q9000p, qp02, 
	    qnul, qpie, qfil[9];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__717 = 717;
static integer c__718 = 718;
static integer c_n726 = -726;
static integer c_n725 = -725;

/* Subroutine */ int accint_(cf1, cf2, pt1, pt2, eps)
doublereal *cf1, *cf2, *pt1, *pt2, *eps;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Local variables */
    static integer i__, j, kk, ker, iier;
    extern /* Subroutine */ int aerr_();
    static doublereal ansn;
    extern /* Subroutine */ int avadd_(), avsub_(), alcint_(), avleng_(), 
	    avnorm_(), avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */


/*      INTERSECTS TWO CIRCLES */
/*      CF1 = CANONICAL FORM OF FIRST */
/*      CF2 = CANONICAL FORM OF SECOND */
/*      PT1 = FORST ANSWER POINT */
/*      PT2 = SECOND ANS WR POINT */
/*      IER = 0,1,2    NUMBER OF INTERSECTIONS */
/*      EPS = TOLERANCE */

/*      COMPUTE DISTANCE BETWEEN CENTERS */
/* A */
    /* Parameter adjustments */
    --pt2;
    --pt1;
    --cf2;
    --cf1;

    /* Function Body */
    avsub_(&cf1[1], &cf2[1], a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
/*      ZERO OUT NON SIGNIVICANT VALUE */
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    if (a2cmmn_1.ans < a2fpc_1.qp4x01) {
	aerr_(&c__717);
    }

/*      SEE IF NO INTERSECTION */

    a2cmmn_1.ier = 2;
    if (a2cmmn_1.ans + cf1[3] < cf2[3] - *eps) {
	a2cmmn_1.ier = 0;
    }
    if (a2cmmn_1.ans + cf2[3] < cf1[3] - *eps) {
	a2cmmn_1.ier = 0;
    }
    if (a2cmmn_1.ans - *eps > cf1[3] + cf2[3]) {
	a2cmmn_1.ier = 0;
    }
    if ((d__1 = cf1[3] + cf2[3] - a2cmmn_1.ans, abs(d__1)) < *eps + 
	    a2fpc_1.qp5x01) {
	a2cmmn_1.ier = 1;
    }
    if ((d__2 = (d__1 = cf1[3] - cf2[3], abs(d__1)) - a2cmmn_1.ans, abs(d__2))
	     < *eps + a2fpc_1.qp5x01) {
	a2cmmn_1.ier = 3;
    }
    j = a2cmmn_1.ier + 1;
    switch ((int)j) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }

/*      NO INTERSECTIONS */

L10:
    return 0;

/*      ONE INTERSECTION */
L40:
    a2cmmn_1.ier = 1;
    if (cf2[3] > cf1[3]) {
	goto L20;
    }
    avsub_(a2cmmn_1.vnul, a2cmmn_1.vtem, a2cmmn_1.vtem);
L20:
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &ker);
    if (ker == 1) {
	aerr_(&c__718);
    }
    avmult_(a2cmmn_1.vtem, &cf2[3], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, &cf2[1], &pt1[1]);
    pt1[3] -= cf2[3];
    if (j == 2 || j == 4) {
	goto L100;
    }
    return 0;
L100:
/* ... WHEN ONLY ONE INTERSECTION FOUND, CALCULATE THE DISTANCE FROM THE */
/* ... INTERSECTION POINT TO THE PSEUDO DS, AND STORE THAT IN QFIL(9) */
/* ... USED IN AINT TO SELECT BEST TAN. PT. IN 'MULTIPLE TAN. PT.' CASE */
    avsub_(&pt1[1], &cf1[1], a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    a2fpc_1.qfil[8] = (d__1 = a2cmmn_1.ans - cf1[3], abs(d__1));
    return 0;
/* ... */
/*      TWO INTERSECTIONS */
L30:

/*               2        2    2 */
/*   GIVEN (X-A1) + (Y-B1) = R1 */


/*   AND */
/*               2        2    2 */
/*         (X-A2) + (Y-B2) = R2 */

/*   EXPAND */

/*    2           2            2    2    2 */
/*   X  - 2A1X + Y  -2B1Y  = R1  -A1  -B1 */


/*   SUBTRACT */

/*                                2    2    2    2    2    2 */
/*    X(2A1-2A2) + Y(2B1-2B2) = A1  +B1  -R1  -A2  -B2  +R2 */


/*     THIS IS THE EQUATION OF A PLANE  NORMAL TO THE LINE JOINING THE */
/*   CENTERS OF THE CIRCLES, AND WHICH INTERSECTS THE CIRCLES AT THEIR */
/*     MUTUAL INTERSECTION.   WE COULD HAVE USED THIS TECHNIQUE EXCLUSIVE */
/*      FOR THIS WHOLE SUBROUTINE, BUT THE TOLERANCE WOULD NOT BE PROPER */
/*      FOR THE TANGENCY CASES.   THEREFORE, IT IS USED ONLY WHEN WE KNOW */
/*      TWO INTERSECTIONS. */


/*      USE VTEM AS A TEMPORARY CANONICAL FORM STORAGE AREA */
    a2cmmn_1.vtem[0] = a2fpc_1.q2p * (cf1[1] - cf2[1]);
    a2cmmn_1.vtem[1] = a2fpc_1.q2p * (cf1[2] - cf2[2]);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avleng_(a2cmmn_1.vtem, &ansn);
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &iier);
    if (iier == 1) {
	aerr_(&c_n726);
    }
/* Computing 2nd power */
    d__1 = cf1[1];
/* Computing 2nd power */
    d__2 = cf1[2];
/* Computing 2nd power */
    d__3 = cf1[3];
/* Computing 2nd power */
    d__4 = cf2[1];
/* Computing 2nd power */
    d__5 = cf2[2];
/* Computing 2nd power */
    d__6 = cf2[3];
    a2cmmn_1.vtem[2] = d__1 * d__1 + d__2 * d__2 - d__3 * d__3 - d__4 * d__4 
	    - d__5 * d__5 + d__6 * d__6;
    a2cmmn_1.vtem[2] /= ansn;
    alcint_(a2cmmn_1.vtem, &cf2[1], &pt1[1], &pt2[1], &a2cmmn_1.taucs);
    if (a2cmmn_1.ier != 2) {
	alcint_(a2cmmn_1.vtem, &cf1[1], &pt1[1], &pt2[1], &a2cmmn_1.tauds);
    }
    if (a2cmmn_1.ier == 0) {
	aerr_(&c_n725);
    }
/*      DUMMY DO LOOP */
    kk = 3;
    i__1 = kk;
    for (i__ = 3; i__ <= i__1; ++i__) {
	a2cmmn_1.vtem[i__ - 1] = a2fpc_1.qnul;
/* L88: */
    }
/* ... IF ALCINT RETURN INDICATES ONE INTERSECTION, CALCULATE THE */
/* ... DISTANCE FROM THE INTERSECTION POINT (PT1) TO THE PSEUDO DS, */
/* ... AND STORE THAT DISTANCE IN QFIL(9) ... USED IN AINT TO SELECT BEST */
/* ... TAN. PT. IN 'MULTIPLE TAN. PT.' CASE. */
    if (a2cmmn_1.ier != 1) {
	goto L98765;
    }
    avsub_(&pt1[1], &cf1[1], a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    a2fpc_1.qfil[8] = (d__1 = a2cmmn_1.ans - cf1[3], abs(d__1));
L98765:
    return 0;
} /* accint_ */

