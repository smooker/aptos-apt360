/* AVIOL.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int aviol_(pa, iviol)
doublereal *pa;
integer *iviol;
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, kk;


/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */

/* ...  CHECK WHETHER CUTTER VIOLATES SURFACE AT GIVEN POINT */


/* ...  BRANCH ON SURFACE TYPE */

    /* Parameter adjustments */
    --pa;

    /* Function Body */
    switch ((int)a2cmmn_1.icscf) {
	case 1:  goto L10;
	case 2:  goto L20;
    }

/* ...  LINE */
/* . */
L10:
    a2cmmn_1.res = a2cmmn_1.cscf[0] * pa[1] + a2cmmn_1.cscf[1] * pa[2] - 
	    a2cmmn_1.cscf[2];
    goto L30;

/* ...  CIRCLE */

L20:
/* Computing 2nd power */
    d__1 = a2cmmn_1.cscf[0] - pa[1];
/* Computing 2nd power */
    d__2 = a2cmmn_1.cscf[1] - pa[2];
    a2cmmn_1.res = sqrt(d__1 * d__1 + d__2 * d__2) - a2cmmn_1.cscf[2];
    goto L30;

/* ...  TEST RES, WHICH IS MINIMUM DISTANCE, AGAINST CUTTER RADIUS */

L30:
/* Computing MAX */
    d__2 = (d__1 = a2cmmn_1.cr - a2cmmn_1.taucs, abs(d__1)), d__3 = 
	    a2cmmn_1.cr * a2fpc_1.qp01;
    a2cmmn_1.cftem[0] = max(d__2,d__3);
    if (a2cmmn_1.cr <= a2fpc_1.qnul) {
	a2cmmn_1.cftem[0] = a2cmmn_1.taucs;
    }
    if (abs(a2cmmn_1.res) > a2cmmn_1.cftem[0]) {
	goto L35;
    }

/* ...  YES,IN VIOLATION */

    *iviol = 1;
    return 0;

/* ...  VIOLATION DOES EXIST */

L35:
    *iviol = 0;
    if (abs(a2cmmn_1.res) < a2fpc_1.qp6x01) {
	*iviol = 1;
    }
    kk = 3;
    for (i__ = kk; i__ <= 3; ++i__) {
	pa[i__] = a2fpc_1.qnul;
/* L88: */
    }
    return 0;
} /* aviol_ */

