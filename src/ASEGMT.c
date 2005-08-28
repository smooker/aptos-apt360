/* ASEGMT.f -- translated by f2c (version 20000121).
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
	    qnul, qpie, q100p, qfil[8];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__0 = 0;

/* Subroutine */ int asegmt_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double atan2(), sqrt(), atan(), cos(), sin();

    /* Local variables */
    static integer i__;
    static doublereal a1, a2, ai, pi, dai, rfp[3], rte[3], rbig, rang, apnt[3]
	    , rlit, fpang, teang, stang, sense;
    extern /* Subroutine */ int azcor_(), avsub_();
    static integer nstep;
    extern /* Subroutine */ int avsto_();
    static doublereal delang;
    extern /* Subroutine */ int avleng_();
    static doublereal alowan, anstep;
    extern /* Subroutine */ int avcros_(), avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */
/*      SEGMENTS A CIRCULAR DRIVE SURFACE */
/*      GENERAL CALCULATION PROCEESS IS AS FOLLOWS... */
/*      INITIALLY, SET UP SOME VALUES TO BE USED LATER */
/*      RBIG IS LARGE RADIUS RSMAL IS SMALL RADIUS OF TOLERANCE BAND */
/*      RTE IS VECTOR FROM CENTER OF CIRCLE TO TE POSITION */
/*      F   RFP IS VECTOR FROM CENTER TO FINAL POINT FPNT */
/*      SET UP SENSE = + OR - 1. FOR CLOCKWISE OR COUNTERCLOCKWISE */
/*      MOTION REQUIRED.      THEN COMPUTE THE ANGULAR DIFFERENCE */
/*      BETWEEN THE POINTS  DELTAN */
/*      WHICH HAS BEEN CORRECTED FOR MULTIPLE REVOLUTIONS */
/*      ALSO COMPUTE THE MAXIMUM ALLOWABLE ANCLE  DECIDE WOW MANY */
/*     STEPS ARE REQUIRED, AND SEGMENT */
/*      DO NOT OUPUT THE LAST POINT, AS THAT IS DONE BY ARLMI */
    if (a2cmmn_1.itopt == 4) {
	a2cmmn_1.tauds -= a2fpc_1.qp4x05;
    }
    rbig = a2cmmn_1.dscf[2] + a2cmmn_1.tauds * (a2fpc_1.q100p - 
	    a2cmmn_1.percen) / a2fpc_1.q100p;
    rlit = a2cmmn_1.dscf[2] - a2cmmn_1.tauds * (a2cmmn_1.percen / 
	    a2fpc_1.q100p);
    avsub_(a2cmmn_1.te2d, a2cmmn_1.dscf, rte);
    avsub_(a2cmmn_1.fpnt, a2cmmn_1.dscf, rfp);
/* ...NECESSARY TO AVOID PROBLEM OF COMPUTATIONAL NOISES */
    avsub_(a2cmmn_1.te2d, a2cmmn_1.fpnt, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &a2cmmn_1.ans);
    if (a2cmmn_1.ans < a2fpc_1.qp0001 * a2cmmn_1.taucs) {
	avsto_(rte, rfp);
    }
    rte[2] = a2fpc_1.qnul;
    rfp[2] = a2fpc_1.qnul;
    avcros_(rte, a2cmmn_1.ti2d, a2cmmn_1.vtem);
    sense = a2fpc_1.q1p;
    if (a2cmmn_1.vtem[2] < a2fpc_1.qnul) {
	sense = -a2fpc_1.q1p;
    }

/*      -1. FOR CLOCKWISE ... +1. FOR COUNTERCLOCKWISE */
/*      TEANG IS ANGLE IN RADIANS TO TE LOCATION */
    a1 = rte[1];
    a2 = rte[0];
    teang = atan2(a1, a2);
/*      FPANG IS TO FINAL POINT */
    a1 = rfp[1];
    a2 = rfp[0];
    fpang = atan2(a1, a2);

/*      ALOWAN = ALOWABLE ANGLE */
/*      BUT ONLY FOR U/I OF A FULL CUT LENGTH */
/* Computing 2nd power */
    d__1 = rbig;
/* Computing 2nd power */
    d__2 = rlit;
    alowan = sqrt(d__1 * d__1 - d__2 * d__2) / rlit;
    alowan = atan(alowan);
/*      = U    1/2 OF STEP ANGLE ALLOWED */
/*      NOW GET DELANG   ...   ANGULAR DIFFERENCE TO GO */
/*      THERE ARE FOUR CASES   TEANG LESSTHAN FPANG AND COUNTER CLOCKWISE */
/*                             TEANG GREATER THAN FPANG AND COUNTER CKWSE */
/*                             TEANG LESS THAN FPANG AND CLOCKWISE */
/*                             TEANG GREATER THAN  FPANG AND CLOCKWISE */


    delang = sense * (fpang - teang);

/*      CASE 1    DELANG IS POSITIVE AND FINAL */
/*      CASE 2      DELANG IS NEGATIVE AND NOT FINAL */
/*      CASE 3      DELANG IS NEGATIVE AND NOT FINAL */
/*      CASE 4  DELANG IS POSITIVE AND FINAL */

    pi = a2fpc_1.qpie;
    if (delang >= 0.) {
	goto L4;
    } else {
	goto L3;
    }
L3:
    delang = a2fpc_1.q2p * pi + delang;
    goto L5;
L4:
    avsub_(a2cmmn_1.fpnt, a2cmmn_1.te2d, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &stang);
    if (stang >= a2cmmn_1.taucs * .5) {
	goto L5;
    }
    if (a2cmmn_1.n == 1 && a2cmmn_1.itopt == 4 && a2cmmn_1.nrev == 1) {
	goto L5;
    }
    ++a2cmmn_1.nrev;
L5:
/*  NOW GET NUMBER OF HALF STEPS TO TAKE */
    anstep = (delang + (doublereal) a2cmmn_1.nrev * a2fpc_1.q2p * pi) / 
	    alowan;
/*      ROUND THIS UP TO THE NEAREST INTERER */
    nstep = (integer) (anstep + a2fpc_1.q1p);
/*      HAVING ROUNDED  UP TO THE NEAREST INTEGER, NOW ROUND UP AGAIN TO */
/*      NEAREST EVEN INTEGER.  THE REASON FOR THIS IS AS FOLLOWS. */
/*      NEITHER THE FIRST POINT,TE, NOR THE LAST POINT FPNT ARE */
/*      EXACTLY ON THE OUTSIDE OF THE TOLERANCE BAND.  THEREFORE, */
/*      IN ORDER TO BE SURE AND NOT VIOLATE THE SURFACE, THE FIRST */
/*      AND LAST STEPS MUST BE 1/2 STEPS.(1/2 OF THE MAXIMUM ALLOWED */
/*      STEPPING ANGLE..    THIS ALLOWS THE DO LOOP BELOW, WHICH PUTS OUT */
/*      THE FIRST, THIRD, FIFTH, ETC. HALF STEPS TO STOP LEAVING */
/*      EXACTLY ONE-HALF STEP LEFT TO THE FINAL POINT */
/*      MOREOVER, BETWEEN THE FIRST  AND THIRD HALF-STEP POINTS, THERE IS */
/*      JUST EXACTLY ONE FULL STEP.  (FIGGURES YOU SAY...) */
/*      MOREOVER, CONSIDER THE SITUATION WHEN THE COMPUTED ANGULAR DIFFER */
/*      BETWEEN THE FIRST AND LAST POINTS IS SUCH THAT THE ENTIRE */
/*      STEP COULD BE MADE AT ONCE.  THAT STILL DOES NOT SOLVE THE */
/*      PROBLEM, BECAUSEPOINTS MAY BE EXACTLY ON THE INNER TOLERANCE */
/*      BAND, AND SUCH A SINGLE STEP WOULD GOUGE THE SURFACE.  THAT CASE */
/*      CAUSE NSTEP TO BE COMPUTED AS 1, ROUNDED UP TO 2, AND A */
/*      POINT EXACTLY ON THE OUTER TOLERANCE BAND HALF WAY BETWEEN THE */
/*      TWO POINTS WOULD BE OUTPUT. */
/*      BEFORE THE FINAL POINT WAS OUTPUT, THUS SOLVING THE PROBLEM */
    nstep += nstep % 2;
/*      GET ACTUL SPETTING ANGLE */
    stang = (delang + (doublereal) a2cmmn_1.nrev * a2fpc_1.q2p * pi) / (
	    doublereal) nstep;
/*      STEP OFF AND OUTPUT */
    if (nstep == 0) {
	return 0;
    }
    i__1 = nstep;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
/*       ONLY OUTPUTTING EVERY OTHER, BECAUSE ALOWAN WAS FOR HALF STEP */
	ai = (doublereal) i__;
	dai = ai;
	rang = teang + sense * dai * stang;
	apnt[0] = a2cmmn_1.dscf[0] + rbig * cos(rang);
	apnt[1] = a2cmmn_1.dscf[1] + rbig * sin(rang);
	apnt[2] = a2fpc_1.qnul;
	if (nstep > 2) {
	    goto L99;
	}
	avsub_(apnt, a2cmmn_1.fpnt, a2cmmn_1.vtem);
	avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
	if (a2cmmn_1.ier == 1) {
	    goto L100;
	}
L99:
	azcor_(apnt, &c__0);
L100:
	;
    }
    return 0;
} /* asegmt_ */

