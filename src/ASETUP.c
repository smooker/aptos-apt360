/* ASETUP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal adum[600];
    integer iafl[1], ipontr[1], ifar[1], ipl[1], iunfl[1], isftyp[1], itlon[1]
	    , isvfl[1], ifl4[1], iop[1], iopset[1], jiops[1], notan[1], jent[
	    1], ju1[1], isigcr[1], itseg[1], jtlflg[1], lofs[1], limfl[1], 
	    icstr[1], jtn[1], ichkct[1], j20[1], j21[1], j22[1], j23[1], j24[
	    1], j50[1], j51[1], indir__[1], ifillr[209];
    doublereal te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3], pmove[3],
	     ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[3], ex[3], 
	    ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3], axis2[3],
	     axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3], zlpnt[3], 
	    tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[3], oldu1[
	    3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[3], 
	    delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
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
    doublereal probuf[100], cansto[2000];
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

struct {
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

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

static integer c__5 = 5;
static integer c_b3 = 111100;
static integer c__8 = 8;
static integer c__2 = 2;

/* Subroutine */ int asetup_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_9 = { {'A', 'S', 'E', 'T', 'U', 'P', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_9)


    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;

    /* Local variables */
    static integer i__, in;
    static doublereal ans;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int astor_(), avdot_(), avsub_(), avsto_(), 
	    avleng_(), adyndp_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int avmult_();
    static integer istype;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*     SETS SPECIAL ITERATION FLAGS FOR */
/*     MINIMUM DISTANCE AND SETS NUMDIM */
/* ... A2CMMN START */
/* ... A2CMMN END */

    adyndp_(ab, &c__5, &c_b3);
/*     SET UP TO TEST PS */
    if (a2cmmn_1.istrup > 0) {
	goto L7;
    }
    a2cmmn_1.ic = a2cmmn_1.ipontr[a2cmmn_1.iips - 1];
    a2cmmn_1.n = a2cmmn_1.ips;
    in = a2cmmn_1.iips;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic - 1], &c__8, &istype, &c__2);
    ans = a2fpc_1.qnul;
    if (istype > 3) {
	goto L5;
    }
/*     PLANE TEST AXIS */
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[4], &ans);
    if (ans < 0.) {
	goto L33;
    } else if (ans == 0) {
	goto L5;
    } else {
	goto L34;
    }
L33:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.cansto[4], a2cmmn_1.vtem);
    goto L36;
L34:
    avsto_(&a2cmmn_1.cansto[4], a2cmmn_1.vtem);
L36:
    avmult_(a2cmmn_1.vtem, a2cmmn_1.cutdat, a2cmmn_1.vtem);
    avmult_(a2cmmn_1.ta, a2cmmn_1.cutdat, a2cmmn_1.temp);
    avsub_(a2cmmn_1.vtem, a2cmmn_1.temp, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, a2cmmn_1.vtem);
    if (a2cmmn_1.vtem[0] - (float)2.5e-5 >= 0.) {
	goto L5;
    } else {
	goto L3;
    }
/*     NOT NORMAL TO CUTTER */
L5:
    if (abs(ans) <= a2fpc_1.qp2) {
	a2cmmn_1.numdim = 1;
    }
    goto L7;

/*     IS NORMAL */
L3:
    a2cmmn_1.iafl[in - 1] = 0;
    a2cmmn_1.itseg[in - 1] = 9;
    goto L7;

/*     SET FOR DS */
L7:
    a2cmmn_1.n = a2cmmn_1.ids;
    in = a2cmmn_1.iids;
L1:
    a2cmmn_1.k = a2cmmn_1.ipontr[in - 1];
    astor_(&a2cmmn_1.cansto[a2cmmn_1.k - 1], &c__8, &i__, &c__2);
    if (i__ == 2 || i__ == 3) {
	goto L20;
    }
    if (i__ == 4 || i__ == 5) {
	goto L40;
    }
    if (i__ == 6 || i__ == 7 || i__ == 9 || i__ == 10) {
	goto L60;
    }

/*     NOT A SPECIAL CASE GO LOOP */
    a2cmmn_1.numdim = 1;
    if (i__ != 50) {
	goto L100;
    }
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[a2cmmn_1.k + 11], &ans);
    if (abs(ans) < a2fpc_1.qp7x9) {
	goto L100;
    }
    goto L84;
L20:
/*     PLANE */
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[a2cmmn_1.k + 3], &ans);
    if (abs(ans) > a2fpc_1.qp6x01) {
	goto L99;
    }
    if (abs(a2cmmn_1.ta[0]) > a2fpc_1.qp6x01 || abs(a2cmmn_1.ta[1]) > 
	    a2fpc_1.qp6x01) {
	goto L99;
    }
    a2cmmn_1.iafl[in - 1] = 0;
    goto L85;

/*     SEG SETTER AREA */
L84:
    a2cmmn_1.iafl[in - 1] = 1;
L85:
    a2cmmn_1.itseg[in - 1] = 33;
    if (tlldat[40] != a2fpc_1.qnul) {
	a2cmmn_1.itseg[in - 1] = 41;
    }
    if (tlldat[52] != a2fpc_1.qnul) {
	a2cmmn_1.itseg[in - 1] = 57;
    }
    if (a2cmmn_1.itlon[in - 1] == 0) {
	a2cmmn_1.itseg[in - 1] = 9;
    }
    goto L100;
/*     CIRCLE, CYLINDER */
L40:
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[a2cmmn_1.k + 6], &ans);
    if (abs(ans) <= a2fpc_1.qp7x9) {
	goto L99;
    }
    goto L84;
L60:
    a2cmmn_1.numdim = 1;
    if ((d__1 = a2cmmn_1.cansto[a2cmmn_1.k + 5], abs(d__1)) + (d__2 = 
	    a2cmmn_1.cansto[a2cmmn_1.k + 7], abs(d__2)) + (d__3 = 
	    a2cmmn_1.cansto[a2cmmn_1.k + 8], abs(d__3)) + (d__4 = 
	    a2cmmn_1.cansto[a2cmmn_1.k + 12], abs(d__4)) > a2fpc_1.qnul) {
	goto L100;
    }
    if (a2cmmn_1.ta[2] != a2fpc_1.q1p) {
	goto L100;
    }
    goto L84;

L99:
    a2cmmn_1.numdim = 1;


L100:
    a2cmmn_1.n += a2cmmn_1.lsv;
    in += a2cmmn_1.lisv;
    if (a2cmmn_1.n <= (a2cmmn_1.icscnt + 2) * a2cmmn_1.lsv) {
	goto L1;
    }



    return 0;
} /* asetup_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


