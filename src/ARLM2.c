/* ARLM2.f -- translated by f2c (version 20000121).
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

static integer c__701 = 701;
static integer c__2 = 2;
static integer c__10 = 10;
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ int arlm2_(arg1, arg2, arg3, arg4, arg5, aarg6, aarg7, iarg8,
	 iarg9, arg10, arg11, arg12, idump)
doublereal *arg1, *arg2, *arg3, *arg4, *arg5, *aarg6, *aarg7;
integer *iarg8, *iarg9;
doublereal *arg10, *arg11, *arg12;
integer *idump;
{
    /* Initialized data */

    static struct {
	char e_1[72];
	real e_2;
	} equiv_4 = { {'A', 'R', 'L', 'M', '2', ' ', '0', '1', 'A', 'R', 'L', 
		'M', '2', ' ', '0', '2', 'A', 'R', 'L', 'M', '2', ' ', '0', 
		'3', 'A', 'R', 'L', 'M', '2', ' ', '0', '4', 'A', 'R', 'L', 
		'M', '2', ' ', '0', '5', 'A', 'R', 'L', 'M', '2', ' ', '0', 
		'6', 'A', 'R', 'L', 'M', '2', ' ', '0', '7', 'A', 'R', 'L', 
		'M', '2', ' ', '0', '8', 'A', 'R', 'L', 'M', '2', ' ', '0', 
		'9'}, (float)0. };

#define ab ((real *)&equiv_4)


    static integer i__;
    extern /* Subroutine */ int aerr_(), aint_();
    static integer itry;
    extern /* Subroutine */ int acscf_(), adscf_(), avadd_(), aselp_(), 
	    aordp_(), azcor_(), avsub_(), avsto_(), adyndp_(), asegmt_(), 
	    avnorm_(), avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */
/*      CR,THDS,THCS,TE,TI,LDS1,LCS,ITOPT,N,TAUDS,TAUCS,PERCEN */
    /* Parameter adjustments */
    --aarg7;
    --aarg6;
    --arg5;
    --arg4;
    --arg2;

    /* Function Body */
    a2cmmn_.cr = *arg1;
    itry = 1;

    avsto_(&arg4[1], a2cmmn_.te2d);
    avsto_(&arg5[1], a2cmmn_.ti2d);
    a2cmmn_.itopt = *iarg8;
    a2cmmn_.n = *iarg9;
    a2cmmn_.tauds = *arg10;
    a2cmmn_.taucs = *arg11;
    a2cmmn_.percen = *arg12;
    if (a2cmmn_.percen > a2fpc_1.q100p || a2cmmn_.percen < a2fpc_1.qnul) {
	goto L1;
    }
    if (a2cmmn_.itopt != 4) {
	goto L2;
    }
L1:
    a2cmmn_.tauds = *arg10 + a2fpc_1.qp4x05;
    a2cmmn_.taucs = *arg11 + a2fpc_1.qp4x05;
L2:

/* ...  ARLM2 FOR DECK C1.0  AUGUST 65 */
/*     CR        =CUTTER RADIUS */
/*     THDS      =THICKNESS OF DRIVE SURFACE */
/*     THCS      =THICKNESS OF CHECK SURFACE */
/*     TE2D      =CURRENT CUTTER LOCATION */
/*     TI2D      =CURRENT DIRECTION OF MOVEMENT */
/*     LOCDS     =1ST CELL OF 3-D DS CANONICAL FORM */
/*     LOCCC     =1ST CELL OF 3-D CS CANONICAL FORM */
/*     TAUDS     =TOTAL DS TOLERANCE */
/*     TAUCS     =TOTAL CS TOLERANCE */
/*     ITOPT     =MOTION TERMINATION MODIFIER */
/*               =1 TO */
/*               =2 ON */
/*               =3 PAST */
/*               =4 TANTO */
/*     PERCEN    =PERCENTAGE OF DS TOLERANCE USED AT TE2D LOCATION */


/* ......zero.. */
    for (i__ = 1; i__ <= 3; ++i__) {
	a2cmmn_.ex[i__ - 1] = a2fpc_1.qnul;
	a2cmmn_.ey[i__ - 1] = a2fpc_1.qnul;
	a2cmmn_.ez[i__ - 1] = a2fpc_1.qnul;
	a2cmmn_.vnul[i__ - 1] = a2fpc_1.qnul;
/* L11: */
    }
    a2cmmn_.ex[0] = a2fpc_1.q1p;
    a2cmmn_.ey[1] = a2fpc_1.q1p;
    a2cmmn_.ez[2] = a2fpc_1.q1p;
/* ***  MAKE TE2D AND TI2D  TWO DIMENSIONAL */

/* 	ie, 3rd component is zeroed on toolend and tool aiming */
    a2cmmn_.te2d[2] = a2fpc_1.qnul;
    a2cmmn_.ti2d[2] = a2fpc_1.qnul;
/* 	then normalized */
    avnorm_(a2cmmn_.ti2d, a2cmmn_.ti2d, &a2cmmn_.ier);
    if (a2cmmn_.ier == 1) {
	aerr_(&c__701);
    }

/* ...  STORE 2D CANONICAL FORMS */

L12:
/* 	DS canonical form convert to 2d? */
    adscf_(&aarg6[1]);

    if (*idump != 0) {
	adyndp_(ab, &c__2, &c__10);
    }
/* 	CS canonical form */
    acscf_(&aarg7[1]);


/* ...  COMPUTE ALL POSSIBLE INTERSECTIONS */
L13:

    if (*idump != 0) {
	adyndp_(&ab[4], &c__2, &c__10);
    }
/* ARG2 IS TOOL NORMAL FOR DS -- USED TO TRY INNER AND OUTTER */
/* TOLERANCE BANDS IN PLANE CASE */
/* 	AINT "all intersections" */
    aint_(&itry);
    if (itry != 0) {
	goto L95;
    }

/* ...  ORDER POINTS IN DIRECTION OF TRAVEL */

    if (*idump != 0) {
	adyndp_(&ab[6], &c__2, &c__10);
    }
    aordp_();

/* ...  SELECT FINAL POINT */

    if (*idump != 0) {
	adyndp_(&ab[8], &c__2, &c__10);
    }
    aselp_();


/* ... INITIALIZE AZCOR */

    if (*idump != 0) {
	adyndp_(&ab[10], &c__2, &c__10);
    }
    azcor_(&arg4[1], &c_n1);
/* ***  SEGMENT CIRCLE DS IF APPROPRIATE */

    if (*idump != 0) {
	adyndp_(&ab[12], &c__2, &c__10);
    }
    if (a2cmmn_.idscf == 2) {
	asegmt_();
    }

/* ...  CORRECT 2 VALUE OF FINAL POINT */
/*   INDICATE THAT THIS IS THE LAST POINT SO AZCOR WILL FLUSH THE BUFFER */

    if (*idump != 0) {
	adyndp_(&ab[14], &c__2, &c__10);
    }
    azcor_(a2cmmn_.fpnt, &c__1);
    if (*idump != 0) {
	adyndp_(&ab[16], &c__2, &c__10);
    }

    return 0;
L95:
    switch ((int)a2cmmn_.idscf) {
	case 1:  goto L100;
	case 2:  goto L110;
    }
L100:
    switch ((int)itry) {
	case 1:  goto L101;
	case 2:  goto L102;
    }
L101:
    a2cmmn_.ans = a2cmmn_.tauds * a2cmmn_.percen / a2fpc_1.q100p;
    avmult_(&arg2[1], &a2cmmn_.ans, a2cmmn_.vtem);
    avadd_(&arg4[1], a2cmmn_.vtem, a2cmmn_.te2d);
    a2cmmn_.te2d[2] = a2fpc_1.qnul;
    itry = 2;
    goto L12;
L102:
    a2cmmn_.ans = a2cmmn_.tauds * (a2fpc_1.q100p - a2cmmn_.percen) / 
	    a2fpc_1.q100p;
    avmult_(&arg2[1], &a2cmmn_.ans, a2cmmn_.vtem);
    avsub_(&arg4[1], a2cmmn_.vtem, a2cmmn_.te2d);
    itry = 3;
    goto L12;
L110:
    switch ((int)itry) {
	case 1:  goto L111;
	case 2:  goto L112;
    }
L111:
    a2cmmn_.dscf[2] -= a2cmmn_.tauds * a2cmmn_.percen / a2fpc_1.q100p;
    a2cmmn_.percen = a2fpc_1.qnul;
    itry = 2;
    goto L13;
L112:
    a2cmmn_.dscf[2] += a2cmmn_.tauds;
    a2cmmn_.percen = a2fpc_1.q100p;
    itry = 3;
    goto L13;
} /* arlm2_ */

#undef ab


