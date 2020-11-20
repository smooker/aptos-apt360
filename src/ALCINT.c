/* ALCINT.f -- translated by f2c (version 20000121).
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

static struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

static struct {
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

/* Subroutine */ int alcint_(cfl, cfc, pans1, pans2, eps)
doublereal *cfl, *cfc, *pans1, *pans2, *eps;
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double d_sign(), sqrt();

    /* Local variables */
    static integer j;
    static doublereal dist, root;
    extern /* Subroutine */ int avsub_(), avleng_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */
/*      INTERSECTS A LINE AND A CORCLE */


/*      CFL = LINE CANONICAL FORM8 OF FORM AX +BY = D */
/*      CFC = CIRCLE CANONICAL FORM8 OF FORM (X-A)**2 + (Y-B)**2 = R**I */
/*      PANS1 AND 2 ARE ANSWERS */
/*      IER = 0  NO INTERSECTIONS  =1 ONE, =2, TWO */

/*      COMPUTE THE DISTANCE FOM CORCLE TO LINE */
    /* Parameter adjustments */
    --pans2;
    --pans1;
    --cfc;
    --cfl;

    /* Function Body */
    dist = cfl[1] * cfc[1] + cfl[2] * cfc[2] - cfl[3];

/*      SEE IF NONE8 ONE OR TWO INTERSECTIONS */
    a2cmmn_1.ier = 2;
    if (abs(dist) > cfc[3] + *eps) {
	a2cmmn_1.ier = 0;
    }
    if ((d__1 = abs(dist) - cfc[3], abs(d__1)) <= *eps) {
	a2cmmn_1.ier = 1;
    }
    if (a2cmmn_1.ier != 1 || a2cmmn_1.itopt == 4) {
	goto L10;
    }
    if (abs(dist) < cfc[3]) {
	a2cmmn_1.ier = 2;
    }
L10:
    j = a2cmmn_1.ier + 1;
    switch ((int)j) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
    }
L1:
    goto L5;
/*      ONE     RESIDUL TIMES PLANE VECTOR IS POINT */
L2:
    if (a2cmmn_1.icase != 3) {
	goto L22;
    }
    if ((d__1 = abs(dist) - a2cmmn_1.dscf[2], abs(d__1)) < *eps) {
	dist = d_sign(&a2cmmn_1.dscf[2], &dist);
    }
L22:
    pans1[1] = -dist * cfl[1] + cfc[1];
    pans1[2] = -dist * cfl[2] + cfc[2];
    pans1[3] = a2fpc_1.qnul;
    goto L5;

/*      TWO INTERSECTIONS */
L3:
/* Computing 2nd power */
    d__1 = cfc[3];
/* Computing 2nd power */
    d__2 = dist;
    root = sqrt(d__1 * d__1 - d__2 * d__2);
    pans1[1] = cfc[1] - dist * cfl[1] - root * cfl[2];
    pans1[2] = cfc[2] - dist * cfl[2] + root * cfl[1];
    pans2[1] = cfc[1] - dist * cfl[1] + root * cfl[2];
    pans2[2] = cfc[2] - dist * cfl[2] - root * cfl[1];
    pans1[3] = a2fpc_1.qnul;
    pans2[3] = a2fpc_1.qnul;
/* ... WHEN ONLY ONE INTERSECTION FOUND, CALCULATE THE DISTANCE FROM THE */
/* ... INTERSECTION POINT TO THE PSEUDO DS, AND STORE THAT IN QFIL(9) */
/* ... USED IN AINT TO SELECT BEST TAN. PT. IN 'MULTIPLE TAN. PT.' CASE */
L5:
    if (j != 2) {
	goto L40;
    }
    if (a2cmmn_1.icase != 2) {
	goto L50;
    }
    a2fpc_1.qfil[8] = (d__1 = cfl[1] * pans1[1] + cfl[2] * pans1[2] - cfl[3], 
	    abs(d__1));
    return 0;
L50:
    avsub_(&pans1[1], &cfc[1], a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    a2fpc_1.qfil[8] = (d__1 = a2cmmn_1.ans - cfl[3], abs(d__1));
L40:
    return 0;
} /* alcint_ */

