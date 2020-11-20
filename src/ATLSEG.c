/* ATLSEG.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal adum[720], te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3]
	    , pmove[3], ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[
	    3], ex[3], ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3]
	    , axis2[3], axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3],
	     zlpnt[3], tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[
	    3], oldu1[3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[
	    3], delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
	    gamma, cagl, sagl, com1, com4, costh, ctocl, diam, dif, difout, 
	    dinc, dp, dpe, dpi, dpl, dpmax, dp1, dpcnt, dsmov, d1, d2a, el1, 
	    el2, fipnt, flipck, hafdia, hchord, offset, prod1, prod2, psi, 
	    radno, rc1, rdrm, rdrn, rone, rzerol, save1, siuth, tangl, theta, 
	    alp, eps7, vamax, vl, zdotc, zgamma, zign, zl, zl1, zl2, znpts, 
	    tolbnd, cendis, cenlen, chord, abcd[2], acard[2], save[6], cutdat[
	    7], tem[10], temp[20], tcdat[260], qequiv[20];
    integer is, iis, it, iit, ips, iips, ids, iids, ics, iics, igs, iigs, 
	    icdefl, icdefs, iautps, igo, icrdct, icut, igtflg, inops, isrch, 
	    iofset, istrup, i3dflg, mulout, multax, numax, numsfs, numsur, 
	    igoug, ipdpl, numdim, irstrt, icscnt, i3, i31, j, ja, jl, js, jt, 
	    kc, knd, kr, l, incfs, np, ibegin, ifar1, ik, ins1, itnflg, 
	    ivamax, iws, iiws, iz, next1, next2, npts, numpt1, jam, jap, 
	    jtused, ifrl, n, m, mdic, jbr, jckr, jcpr, jcr, jdr, jgr, jmin, 
	    jminr, jpr, jpxr, jtr, jcnt1, jcnt2, jcnt3, jsw, jtkf, lisv, lsv, 
	    ipt, jfind, ic, icc, il, k, numpts, iamdct, ifl2, j5, j6, jw6, 
	    j10, j12, j13, j40, j43, j54, j103;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

static struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

static struct {
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

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

/* Table of constant values */

static integer c__1 = 1;
static integer c__11 = 11;
static integer c__417 = 417;
static integer c__401 = 401;
static integer c__402 = 402;
static integer c__403 = 403;
static integer c__404 = 404;
static integer c__405 = 405;
static integer c__406 = 406;
static integer c__407 = 407;
static integer c__408 = 408;
static integer c__409 = 409;
static integer c_n415 = -415;
static integer c__413 = 413;
static integer c__410 = 410;
static integer c__411 = 411;
static integer c__412 = 412;
static integer c_n416 = -416;
static integer c__414 = 414;

/* Subroutine */ int atlseg_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_6 = { {'A', 'T', 'L', 'S', 'E', 'G', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_6)


    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sin(), cos(), sqrt();

    /* Local variables */
    static integer i__;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int aerr_(), adyndp_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
    a2cmmn_1.icdefl = 0;
    adyndp_(ab, &c__1, &c__11);
/*      TEST FOR BAD DEFINITION IF E AND F GIVEN */
    if (a2cmmn_1.cutdat[2] + a2cmmn_1.cutdat[3] <= 0.) {
	goto L101;
    } else {
	goto L100;
    }
L100:
    tlldat[0] = a2cmmn_1.cutdat[0] * a2fpc_1.qp5;
    tlldat[4] = a2cmmn_1.cutdat[4] * a2fpc_1.q1rad;
    tlldat[5] = sin(a2cmmn_1.cutdat[4]) / cos(a2cmmn_1.cutdat[4]);
    tlldat[1] = tlldat[0] * tlldat[5];
/* Computing 2nd power */
    d__1 = a2cmmn_1.cutdat[2] - tlldat[0];
/* Computing 2nd power */
    d__2 = a2cmmn_1.cutdat[3] - tlldat[1];
    tlldat[2] = sqrt(d__1 * d__1 + d__2 * d__2);
    if (tlldat[2] - a2cmmn_1.cutdat[1] < -a2fpc_1.qp7x01) {
	aerr_(&c__417);
    }
L101:
    for (i__ = 3; i__ <= 58; ++i__) {
/* L1: */
	tlldat[i__ - 1] = a2fpc_1.qnul;
    }
/*  MAKE SURE TOOL DIAMETER NOT LESS THAN ZERO */
    if (a2cmmn_1.cutdat[0] < 0.) {
	goto L2;
    } else if (a2cmmn_1.cutdat[0] == 0) {
	goto L92;
    } else {
	goto L3;
    }
L2:
    aerr_(&c__401);
/*  EXAMINE TOOL HEIGHT. IF LESS THAN ZERO ERROR. SET TO 5 IF = ZERO. */
/*  OKAY OTHERWISE */
L3:
    if (a2cmmn_1.cutdat[6] < 0.) {
	goto L4;
    } else if (a2cmmn_1.cutdat[6] == 0) {
	goto L5;
    } else {
	goto L6;
    }
L4:
    aerr_(&c__402);
L5:
    a2cmmn_1.cutdat[6] = max(a2fpc_1.q5p,a2cmmn_1.cutdat[1]);
/*  SUM OF ANGLES A AND B MUST BE LESS THAN 90 DEGREES */
L6:
    if (a2fpc_1.q90p - a2cmmn_1.cutdat[4] - a2cmmn_1.cutdat[5] <= 0.) {
	goto L7;
    } else {
	goto L8;
    }
L7:
    aerr_(&c__403);
L8:
    tlldat[46] = a2fpc_1.qp5 * a2cmmn_1.cutdat[0];
    a2cmmn_1.cutdat[0] = tlldat[46];
/*  ERROR IF ANGLE A NEGATIVE */
    if (a2cmmn_1.cutdat[4] < 0.) {
	goto L9;
    } else if (a2cmmn_1.cutdat[4] == 0) {
	goto L10;
    } else {
	goto L11;
    }
L9:
    aerr_(&c__404);
L10:
    tlldat[12] = a2fpc_1.q1p;
    tlldat[3] = a2fpc_1.q1pe38;
    goto L12;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR A GREATER THAN ZERO */
L11:
    tlldat[58] = a2fpc_1.q1rad * a2cmmn_1.cutdat[4];
    tlldat[11] = sin(tlldat[58]);
    tlldat[12] = cos(tlldat[58]);
    tlldat[8] = tlldat[11] / tlldat[12];
    tlldat[42] = tlldat[8] * tlldat[46];
    tlldat[3] = a2fpc_1.q1p / tlldat[8];
/*  MAKE SURE HEIGHT OF BOTTOM LINE SEGMENT DOES NOT EXCEED TOOL HEIGHT */
L12:
    if (a2fpc_1.qp4x01 - (d__1 = a2cmmn_1.cutdat[6] - tlldat[42], abs(d__1)) 
	    <= 0.) {
	goto L13;
    } else {
	goto L15;
    }
L13:
    if (a2cmmn_1.cutdat[6] - tlldat[42] <= 0.) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    aerr_(&c__405);
L15:
    tlldat[42] = a2cmmn_1.cutdat[6];
/*  ERROR IF ANGLE B NEGATIVE */
L16:
    a2cmmn_1.ipt = 1;
    if (a2cmmn_1.cutdat[5] < 0.) {
	goto L17;
    } else if (a2cmmn_1.cutdat[5] == 0) {
	goto L18;
    } else {
	goto L19;
    }
L17:
    aerr_(&c__406);
L18:
    tlldat[43] = a2fpc_1.q1p;
    goto L20;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR B GREATER THAN ZERO */
L19:
    tlldat[59] = a2fpc_1.q1rad * a2cmmn_1.cutdat[5];
    tlldat[43] = cos(tlldat[59]);
    tlldat[44] = sin(tlldat[59]);
    tlldat[52] = tlldat[44] / tlldat[43];
/*  FURTHER CALCULATIONS */
L20:
    tlldat[13] = tlldat[46] / tlldat[12];
    tlldat[45] = (a2cmmn_1.cutdat[6] - tlldat[42]) / tlldat[43];
    tlldat[54] = tlldat[46] + tlldat[44] * tlldat[45];
    tlldat[16] = a2fpc_1.q1p;
    tlldat[48] = a2fpc_1.q1p;
/*  EXAMINE TOOL RADIUS. IF GREATER THAN ZERO, CORNER CIRCLE WILL BE PART */
/*  OF TOOL CONFIGURATION. IF = ZERO, TOOL WILL CONSIST ONLY OF LINE AND */
/*  POINT CIRCLE SEGMENTS. ERROR IF NEGATIVE. */
    if (a2cmmn_1.cutdat[1] < 0.) {
	goto L21;
    } else if (a2cmmn_1.cutdat[1] == 0) {
	goto L22;
    } else {
	goto L25;
    }
L21:
    aerr_(&c__407);
/*  COMPARE LENGTH OF UPPER LINE SEGMENT TO ZERO. SET VALUES IN TLLDAT */
/*  BLOCK ACCORDINGLY */
L22:
    if (tlldat[45] <= 0.) {
	goto L23;
    } else {
	goto L24;
    }
L23:
    tlldat[52] = tlldat[3];
    tlldat[48] = a2fpc_1.qnul;
    goto L87;
L24:
    tlldat[26] = tlldat[42];
    tlldat[30] = tlldat[46];
    tlldat[27] = tlldat[52];
    tlldat[28] = tlldat[3];
    goto L86;
/*  COMPUTE CENTER OF CORNER CIRCLE */
L27:
    a2cmmn_1.cutdat[2] = tlldat[46] - tlldat[31];
    a2cmmn_1.cutdat[3] = tlldat[31];
    goto L26;
/*  STORE RADIUS OF CORNER CIRCLE AND COMPUTE DISTANCE FROM CENTER OF */
/*  CIRCLE TO BOTTOM LINE (TLLDAT(22)) */
L25:
    tlldat[31] = a2cmmn_1.cutdat[1];
L26:
    tlldat[21] = a2cmmn_1.cutdat[3] * tlldat[12] - a2cmmn_1.cutdat[2] * 
	    tlldat[11];
    tlldat[4] = a2cmmn_1.cutdat[2] * a2cmmn_1.cutdat[2] + a2cmmn_1.cutdat[3] *
	     a2cmmn_1.cutdat[3];
/*  IF = 0, CENTER OF CORNER CIRCLE HAS TO BE CALCULATED */
    if (tlldat[4] + a2cmmn_1.cutdat[4] + a2cmmn_1.cutdat[5] != 0.) {
	goto L28;
    } else {
	goto L27;
    }
/*  DISTANCE FROM CENTER OF CIRCLE TO INTERSECTION OF LINE SEGMENTS */
L28:
    tlldat[5] = sqrt((a2cmmn_1.cutdat[2] - tlldat[46]) * (a2cmmn_1.cutdat[2] 
	    - tlldat[46]) + (a2cmmn_1.cutdat[3] - tlldat[42]) * (
	    a2cmmn_1.cutdat[3] - tlldat[42]));
    tlldat[53] = tlldat[52] * (a2cmmn_1.cutdat[6] - tlldat[42]);
/*  DISTANCE FROM CENTER OF CIRCLE TO UPPER END OF UPPER LINE SEGMENT */
    tlldat[29] = sqrt((a2cmmn_1.cutdat[3] - a2cmmn_1.cutdat[6]) * (
	    a2cmmn_1.cutdat[3] - a2cmmn_1.cutdat[6]) + (a2cmmn_1.cutdat[2] - 
	    tlldat[54]) * (a2cmmn_1.cutdat[2] - tlldat[54]));
/*  IF THE Y COORD. (F) OF THE CENTER OF THE CORNER CIRCLE IS LESS THAN */
/*  THE Y COORD. OF THE INTERSECTION OF THE LINES, THEN ERROR */
    if (a2cmmn_1.cutdat[3] + a2fpc_1.qp4x01 - tlldat[42] <= 0.) {
	goto L29;
    } else {
	goto L30;
    }
L29:
    aerr_(&c__408);
/*  IF THE RADIUS IS BOTH LARGER THAN THE DISTANCE TO THE INTERSECTION */
/*  OF THE LINES AND DIFFERENT THAN THE DISTANCE TO THE ORIGIN OF THE */
/*  BOTTOM LINE SEGMENT, WE HAVE AN INVALID TOOL CONFIGURATION */
L33:
    if (a2fpc_1.qp4x01 - (d__1 = tlldat[4] - tlldat[31] * tlldat[31], abs(
	    d__1)) <= 0.) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    aerr_(&c__409);
/*  IF E GREATER THAN ZERO, WE HAVE AN INVALID TOOL CONFIGURATION */
L35:
    if (a2cmmn_1.cutdat[2] < 0.) {
	goto L53;
    } else if (a2cmmn_1.cutdat[2] == 0) {
	goto L37;
    } else {
	goto L34;
    }
L53:
    aerr_(&c_n415);
    tlldat[3] = a2cmmn_1.cutdat[3] / a2cmmn_1.cutdat[2];
    tlldat[8] = a2cmmn_1.cutdat[2] / a2cmmn_1.cutdat[3];
/*  NO LOWER LINE SEGMENT */
L54:
    tlldat[16] = a2fpc_1.qnul;
/*  FURTHER TLLDAT VARIABLES */
L55:
    tlldat[28] = tlldat[3];
L56:
    tlldat[37] = (tlldat[46] - a2cmmn_1.cutdat[2]) * tlldat[43] + tlldat[44] *
	     (a2cmmn_1.cutdat[3] - tlldat[42]);
/*  IF = 0, THERE IS NO UPPER LINE SEGMENT AND IN THIS CASE TOOL NO GOOD */
    if (tlldat[45] != 0.) {
	goto L67;
    } else {
	goto L57;
    }
/*  IF GREATER THAN ZERO, RADIUS AND DISTANCE FROM CENTER OF CORNER */
/*  CIRCLE TO INTERSECTION OF LINES EQUAL. */
L67:
    if (tlldat[31] - tlldat[5] <= 0.) {
	goto L68;
    } else {
	goto L62;
    }
L68:
    tlldat[56] = tlldat[31] * tlldat[31] - tlldat[37] * tlldat[37];
/*  LENGTH OF UPPER LINE SEGMENT */
/* Computing 2nd power */
    d__2 = tlldat[5];
/* Computing 2nd power */
    d__3 = tlldat[37];
    tlldat[45] = tlldat[45] + sqrt((abs(tlldat[56]))) - sqrt((d__1 = d__2 * 
	    d__2 - d__3 * d__3, abs(d__1)));
    tlldat[61] = a2cmmn_1.cutdat[3] - a2cmmn_1.cutdat[6] - tlldat[52] * (
	    tlldat[53] + tlldat[46] - a2cmmn_1.cutdat[2]);
    if (a2fpc_1.qp4x01 - abs(tlldat[61]) <= 0.) {
	goto L72;
    } else {
	goto L69;
    }
L72:
    if (tlldat[61] <= 0.) {
	goto L73;
    } else {
	goto L77;
    }
/*  IF GREATER THAN ZERO, UPPER LINE SEGMENT WITH CORNER CIRCLE TANGENT. */
/*  OTHERWISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN PT. CIRCLE */
L73:
    if (a2fpc_1.qp4x01 - abs(tlldat[56]) <= 0.) {
	goto L75;
    } else {
	goto L74;
    }
L75:
    if (tlldat[56] <= 0.) {
	goto L76;
    } else {
	goto L83;
    }
L76:
    goto L41;
L57:
    aerr_(&c__413);
/*  WE MUST CHANGE PARAMETERS FOR BOTTOM POINT CIRCLE DUE TO NATURE OF */
/*  CORNER CIRCLE */
L37:
    aerr_(&c_n415);
    tlldat[8] = a2fpc_1.qnul;
    tlldat[3] = a2fpc_1.q1pe38;
    goto L54;
/*  IF GREATER THAN OR EQUAL TO ZERO, CORNER CIRCLE IS A POINT CIRCLE */
L30:
    if (a2fpc_1.qp4x01 - (d__1 = tlldat[31] - tlldat[5], abs(d__1)) >= 0.) {
	goto L22;
    } else {
	goto L31;
    }
/*  IF NOT GREATER THAN ZERO, CONTINUE CALCULATIONS FOR CORNER CIRCLE */
L31:
    if (tlldat[31] - tlldat[5] <= 0.) {
	goto L38;
    } else {
	goto L33;
    }
L38:
    if (tlldat[46] + tlldat[8] * (tlldat[42] - a2cmmn_1.cutdat[3]) - 
	    a2cmmn_1.cutdat[2] + a2fpc_1.qp4x01 <= 0.) {
	goto L39;
    } else {
	goto L40;
    }
/*  CORNER CIRCLE INTERSECTS LOWER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L39:
    aerr_(&c__410);
L40:
    if (a2cmmn_1.cutdat[3] + a2fpc_1.qp4x01 - tlldat[42] - tlldat[52] * (
	    tlldat[46] - a2cmmn_1.cutdat[2]) <= 0.) {
	goto L41;
    } else {
	goto L42;
    }
/*  CORNER CIRCLE INTERSECTS UPPER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L41:
    aerr_(&c__411);
L42:
    tlldat[20] = tlldat[31] * tlldat[31] - tlldat[21] * tlldat[21];
/*  LENGTH OF LOWER LINE SEGMENT */
/* Computing 2nd power */
    d__2 = tlldat[5];
/* Computing 2nd power */
    d__3 = tlldat[21];
    tlldat[13] = tlldat[13] + sqrt((abs(tlldat[20]))) - sqrt((d__1 = d__2 * 
	    d__2 - d__3 * d__3, abs(d__1)));
    tlldat[60] = a2cmmn_1.cutdat[2] + tlldat[8] * a2cmmn_1.cutdat[3];
    if (abs(tlldat[60]) - a2fpc_1.qp4x01 >= 0.) {
	goto L46;
    } else {
	goto L43;
    }
/*  IF GREATER THAN ZERO, PT. CIRCLE FOLLOWED BY CORNER CIRCLE OR JUST */
/*  CORNER CIRCLE. OTHERWISE PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. */
/*  CIRCLE, AND THEN CORNER CIRCLE */
L43:
    if (a2fpc_1.qp4x01 - abs(tlldat[20]) <= 0.) {
	goto L44;
    } else {
	goto L54;
    }
L44:
    if (tlldat[20] <= 0.) {
	goto L45;
    } else {
	goto L50;
    }
L45:
    goto L39;
L46:
    if (tlldat[60] >= 0.) {
	goto L47;
    } else {
	goto L51;
    }
/*  IF GREATER THAN ZERO,PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. CIR- */
/*  CLE, AND THEN CORNER CIRCLE. IF = 0, PT. CIRCLE AND CORNER CIRCLE. */
/*  ERROR LESS THAN ZERO */
L51:
    if ((d__1 = tlldat[31] * tlldat[31] - tlldat[4]) < 0.) {
	goto L52;
    } else if (d__1 == 0) {
	goto L53;
    } else {
	goto L50;
    }
L52:
    goto L39;
/*  IF GREATER THAN ZERO, CORNER CIRCLE TANGENT TO LOWER LINE SEGMENT */
L47:
    if (a2fpc_1.qp4x01 - abs(tlldat[20]) <= 0.) {
	goto L48;
    } else {
	goto L55;
    }
L48:
    if (tlldat[20] <= 0.) {
	goto L49;
    } else {
	goto L50;
    }
L49:
    goto L39;
/*  LOWER LINE SEGMENT, PT. CIRCLE, AND CORNER CIRCLE PARAMETER CALC. */
L50:
    tlldat[24] = sqrt((abs(tlldat[20]))) / tlldat[21];
    tlldat[19] = (a2fpc_1.q1p - tlldat[8] * tlldat[24]) / (tlldat[8] + tlldat[
	    24]);
    tlldat[18] = tlldat[11] * tlldat[13];
    tlldat[22] = tlldat[12] * tlldat[13];
    tlldat[20] = tlldat[3];
    tlldat[28] = tlldat[19];
    goto L56;
L62:
    if (a2fpc_1.qp4x01 - (d__1 = tlldat[29] - tlldat[31], abs(d__1)) <= 0.) {
	goto L63;
    } else {
	goto L64;
    }
L63:
    aerr_(&c__412);
/*  IF GREATER THAN ZERO, CORNER CIRCLE MEETS UPPER PT. CIRCLE AT UNAC- */
/*  CEPTABLE ANGLE. IF = 0 WE MUST CHANGE PARAMETERS FOR UPPER PT. CIRCLE */
L64:
    if ((d__1 = a2cmmn_1.cutdat[6] - a2cmmn_1.cutdat[3]) < 0.) {
	goto L78;
    } else if (d__1 == 0) {
	goto L66;
    } else {
	goto L63;
    }
L78:
    aerr_(&c_n416);
    tlldat[52] = (a2cmmn_1.cutdat[3] - a2cmmn_1.cutdat[6]) / (tlldat[46] + 
	    tlldat[53] - a2cmmn_1.cutdat[2]);
L79:
    tlldat[48] = a2fpc_1.qnul;
/* L80: */
    tlldat[27] = a2fpc_1.qnul;
    goto L85;
/*  NO UPPER LINE SEGMENT. CHANGE IN PARAMETERS FOR UPPER POINT CIRCLE */
/*  NECESSARY DUE TO NATURE OF CORNER CIRCLE */
L66:
    aerr_(&c_n416);
    tlldat[52] = a2fpc_1.qnul;
    goto L79;
/*  IF GREATER THAN ZERO,CORNER CIRCLE AND THEN UPPER PT. CIRCLE. OTHER- */
/*  WISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN UPPER PT. CIRCLE */
L69:
    if (a2fpc_1.qp4x01 - abs(tlldat[56]) <= 0.) {
	goto L70;
    } else {
	goto L79;
    }
L70:
    if (tlldat[56] <= 0.) {
	goto L71;
    } else {
	goto L83;
    }
L71:
    goto L41;
L74:
    tlldat[27] = tlldat[52];
    goto L84;
L77:
    if (a2fpc_1.qp4x01 - (d__1 = tlldat[31] - tlldat[29], abs(d__1)) <= 0.) {
	goto L81;
    } else {
	goto L78;
    }
L81:
    if (tlldat[31] - tlldat[29] <= 0.) {
	goto L82;
    } else {
	goto L83;
    }
L82:
    goto L41;
/*  FURTHER CALCULATIONS FOR TLLDAT BLOCK PARAMETERS */
L83:
    tlldat[40] = sqrt((abs(tlldat[56]))) / tlldat[37];
    tlldat[27] = (tlldat[40] + tlldat[52]) / (a2fpc_1.q1p - tlldat[40] * 
	    tlldat[52]);
    tlldat[36] = tlldat[27];
    tlldat[35] = tlldat[52];
L84:
    tlldat[38] = tlldat[54] - tlldat[44] * tlldat[45];
    tlldat[34] = a2cmmn_1.cutdat[6] - tlldat[43] * tlldat[45];
    tlldat[42] = tlldat[34];
    tlldat[46] = tlldat[38];
L85:
    tlldat[26] = a2cmmn_1.cutdat[3];
    tlldat[30] = a2cmmn_1.cutdat[2];
L86:
    tlldat[32] = a2fpc_1.q1p;
L87:
    tlldat[4] = a2fpc_1.q1pe38;
    tlldat[17] = a2fpc_1.q1p;
    tlldat[49] = a2fpc_1.q1p;
    tlldat[50] = a2cmmn_1.cutdat[6];
    a2cmmn_1.ibegin = 9;
/*  WE NOW SEARCH EACH OF THE 7 POSSIBLE SEGMENTS TO DETERMINE FIRST ONE */
L91:
    if (a2ctdf_1.tcont[a2cmmn_1.ibegin - 1] != 0.) {
	goto L90;
    } else {
	goto L88;
    }
L90:
    tlldat[a2cmmn_1.ibegin - 9] = -a2fpc_1.q1p;
    tlldat[64] = -a2fpc_1.q1p;
    tlldat[56] = a2fpc_1.q1p;
    tlldat[51] = -a2fpc_1.q1pe38;
    tlldat[59] = -a2fpc_1.q1pe38;
    tlldat[60] = a2fpc_1.q1pe38;
    tlldat[65] = a2fpc_1.qnul;
    tlldat[63] = a2fpc_1.qnul;
/* ... */
/* ... */
/* L99: */
    return 0;
L88:
    a2cmmn_1.ibegin += 8;
    if (57 - a2cmmn_1.ibegin >= 0) {
	goto L91;
    } else {
	goto L89;
    }
L89:
    aerr_(&c__414);
L92:
    if (a2cmmn_1.cutdat[6] < 0.) {
	goto L4;
    } else if (a2cmmn_1.cutdat[6] == 0) {
	goto L93;
    } else {
	goto L10;
    }
L93:
    a2cmmn_1.ipt = 0;
    tlldat[52] = a2fpc_1.q1pe38;
    a2cmmn_1.ibegin = 57;
    goto L90;
} /* atlseg_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


