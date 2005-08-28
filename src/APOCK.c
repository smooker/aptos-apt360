/* APOCK.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

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
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
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

struct {
    doublereal addem1, addem2, bl[20], cosva, crosto[3], ctemp[60]	/* 
	    was [3][20] */, cutrad, dcov, deldst, dist, dummy, ofcsto, offsto,
	     phitmp, ptint[3], qone[3], q[63]	/* was [3][21] */, rtest, 
	    sin2va, sphio2, t[3], tcrsto[3], u[63]	/* was [3][21] */, 
	    ucrsto[3], uprim[60]	/* was [3][20] */, vprim[60]	/* 
	    was [3][20] */, w[60]	/* was [3][20] */, wd[3], wone[3], xi[
	    66]	/* was [3][22] */, xiprim[63]	/* was [3][21] */, x1, x2, x3,
	     y[3];
} a2pok8_;

#define a2pok8_1 a2pok8_

struct {
    integer ipcerr, iwdcnt, nwd, ibm1, ibm2, ibm3, ibm4, ibm6;
} a2pock_;

#define a2pock_1 a2pock_

struct {
    integer jone, nc, ncorig, jtwo, jthr, jfou, kalc, move, init, ncutbk, 
	    nplus1, nless1, icrsto, ktab[20], kutbac, kolaps, jsave, inter, 
	    kone, ktwo, jdummy, num, itest, kt1, kt2, kover;
} a2pok2_;

#define a2pok2_1 a2pok2_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3511 = 3511;
static integer c__3512 = 3512;
static integer c__3513 = 3513;
static integer c__3514 = 3514;
static integer c__3515 = 3515;
static integer c__3516 = 3516;
static integer c__3507 = 3507;
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__3505 = 3505;
static integer c__3517 = 3517;
static integer c__3518 = 3518;
static integer c__3519 = 3519;

/* Subroutine */ int apock_()
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, kk1, kk2;
#define cor ((doublereal *)&a2cmmn_1 + 1317)
#define cor1 ((doublereal *)&a2cmmn_1 + 2917)
    static doublereal ans;
    static integer jjj;
    static doublereal bns, gpnt[3];
    extern /* Subroutine */ int aerr_(), avadd_();
#define frone ((doublereal *)&a2cmmn_1 + 1312)
#define frtwo ((doublereal *)&a2cmmn_1 + 1313)
    extern /* Subroutine */ int avdot_(), avsto_();
#define radeff ((doublereal *)&a2cmmn_1 + 1309)
    extern /* Subroutine */ int apocka_(), apockb_();
#define pocdat ((doublereal *)&a2cmmn_1 + 1308)
#define frthre ((doublereal *)&a2cmmn_1 + 1314)
#define ofsetc ((doublereal *)&a2cmmn_1 + 1310)
#define ofsetf ((doublereal *)&a2cmmn_1 + 1311)
#define ovride ((doublereal *)&a2cmmn_1 + 1315)
#define pttype ((doublereal *)&a2cmmn_1 + 1316)
    extern /* Subroutine */ int atapop_(), atapwt_(), avcros_(), avnorm_(), 
	    avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     EQUIVALENCE FOR POCKET */


/* L1: */
    atapop_(&ataptb_1.poctap, &c__1, &a2pock_1.ipcerr);
    for (i__ = 1; i__ <= 99; ++i__) {
	a2cmmn_1.cansto[1601 - i__ - 1] = a2cmmn_1.probuf[100 - i__ - 1];
/* L2: */
	a2cmmn_1.probuf[101 - i__ - 1] = a2cmmn_1.probuf[100 - i__ - 1];
    }
    a2pok2_1.jone = a2cmmn_1.nwds + 1;
    a2pok2_1.nc = (a2pok2_1.jone - 9) / 3;
    a2pok2_1.ncorig = a2pok2_1.nc;
    i__ = (integer) (*pttype + a2fpc_1.qp01);
    if (i__ > 1) {
	goto L9999;
    }
L9997:
    a2pock_1.ibm6 = 1;
    a2pok8_1.cutrad = a2cmmn_1.cutdat[0];
    if (*radeff < a2fpc_1.qnul) {
	aerr_(&c__3511);
    }
    if (*ofsetc < a2fpc_1.qnul) {
	aerr_(&c__3512);
    }
    if (*ofsetf < a2fpc_1.qnul) {
	aerr_(&c__3513);
    }
    if (frone[0] < a2fpc_1.qnul || frtwo[0] < a2fpc_1.qnul || frthre[0] < 
	    a2fpc_1.qnul) {
	aerr_(&c__3514);
    }
    i__ = (integer) (*ovride + a2fpc_1.qp01);
    if (i__ != 0 && i__ != 1) {
	aerr_(&c__3515);
    }
    i__ = (integer) (*pttype + a2fpc_1.qp01);
    if (i__ != 0 && i__ != 1) {
	aerr_(&c__3516);
    }
    a2pok2_1.jone = 0;
    a2pock_1.ibm1 = 0;
    a2pok2_1.jtwo = 0;
    a2pok2_1.jthr = 0;
    a2pok2_1.jfou = 0;
    if (*radeff <= 0.) {
	goto L10;
    } else {
	goto L20;
    }
L10:
    *radeff = a2fpc_1.qp5 * *ofsetc * a2pok8_1.cutrad;
L20:
    a2pok2_1.kalc = 0;
    a2pok2_1.move = 1;
    a2pok2_1.init = 1;
    a2pok8_1.deldst = a2fpc_1.qnul;
    goto L40;
L30:
    a2pok2_1.nc = a2pok2_1.ncutbk;
    *pttype = a2fpc_1.qnul;
L40:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L50: */
	    a2pok8_1.xi[i__ + (a2cmmn_1.j + 1) * 3 - 4] = cor[i__ + 
		    a2cmmn_1.j * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	a2pok8_1.xi[i__ - 1] = cor[i__ + a2pok2_1.nc * 3 - 4];
/* L60: */
	a2pok8_1.xi[i__ + (a2pok2_1.nc + 2) * 3 - 4] = cor[i__ - 1];
    }
    a2pok2_1.nplus1 = a2pok2_1.nc + 1;
    a2pok2_1.nless1 = a2pok2_1.nc - 1;
    i__1 = a2pok2_1.nplus1;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	a2pok8_1.addem1 = a2fpc_1.qnul;
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok8_1.q[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.xi[i__ + (
		    a2cmmn_1.j + 1) * 3 - 4] - a2pok8_1.xi[i__ + a2cmmn_1.j * 
		    3 - 4];
/* L70: */
/* Computing 2nd power */
	    d__1 = a2pok8_1.q[i__ + a2cmmn_1.j * 3 - 4];
	    a2pok8_1.addem1 = d__1 * d__1 + a2pok8_1.addem1;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* L80: */
	    a2pok8_1.u[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.q[i__ + 
		    a2cmmn_1.j * 3 - 4] / sqrt(a2pok8_1.addem1);
	}
    }
    if (a2pok2_1.init >= 0) {
	goto L85;
    } else {
	goto L300;
    }
L85:
    a2cmmn_1.jgr = 8;
    apocka_();
/*     ADJUST POCKET VERTICES IF POCKET BOTTOM IS CANTED WITH RESPECT T0 */
/*     TOOL AXIS AND VERTICES DESCRIBE ACTUAL POCKET BOUNDARIES */
    avdot_(a2cmmn_1.ta, a2pok8_1.tcrsto, &a2pok8_1.addem1);
    a2pok8_1.x1 = abs(a2pok8_1.addem1);
    if (a2pok8_1.x1 - a2fpc_1.qp2 <= 0.) {
	goto L190;
    } else {
	goto L200;
    }
L190:
    aerr_(&c__3507);
L200:
    if (a2pok8_1.x1 - a2fpc_1.qp9999 >= 0.) {
	goto L210;
    } else {
	goto L220;
    }
L210:
    a2pok2_1.init = -1;
L220:
    if (a2pok2_1.init < 0) {
	goto L300;
    } else if (a2pok2_1.init == 0) {
	goto L210;
    } else {
	goto L230;
    }
L230:
    if (*pttype < 0.) {
	goto L190;
    } else if (*pttype == 0) {
	goto L210;
    } else {
	goto L240;
    }
L240:
    a2pok2_1.init = 0;
    *pttype = a2fpc_1.qnul;
    a2cmmn_1.jgr = 9;
    apocka_();
    goto L40;
L300:
    if (*ovride != 0.) {
	goto L430;
    } else {
	goto L310;
    }
L310:
    a2pok8_1.sphio2 = a2fpc_1.q1p;
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	avdot_(&a2pok8_1.u[a2cmmn_1.j * 3 - 3], &a2pok8_1.u[(a2cmmn_1.j + 1) *
		 3 - 3], &a2pok8_1.addem2);
	a2pok8_1.dummy = sqrt((d__1 = (a2fpc_1.q1p + a2pok8_1.addem2) / 
		a2fpc_1.q2p, abs(d__1)));
	if (a2pok8_1.dummy - a2pok8_1.sphio2 >= 0.) {
	    goto L340;
	} else {
	    goto L330;
	}
L330:
	a2pok8_1.sphio2 = a2pok8_1.dummy;
L340:
	;
    }
    a2pok8_1.dummy = *radeff / a2pok8_1.cutrad * (a2fpc_1.q1p + 
	    a2pok8_1.sphio2);
    if (*ofsetc - a2pok8_1.dummy <= 0.) {
	goto L360;
    } else {
	goto L350;
    }
L350:
    *ofsetc = a2pok8_1.dummy;
L360:
    if (*ofsetf - a2pok8_1.dummy <= 0.) {
	goto L380;
    } else {
	goto L370;
    }
L370:
    *ofsetf = a2pok8_1.dummy;
L380:
    if (a2pok2_1.jfou <= 0) {
	goto L430;
    } else {
	goto L385;
    }
L385:
    a2pok2_1.jfou = 0;
/* L390: */
    a2pok8_1.ofcsto = *ofsetc;
    a2pok8_1.offsto = *ofsetf;
    a2pok8_1.dummy = a2fpc_1.q2p * *radeff / a2pok8_1.cutrad * 
	    a2pok8_1.sphio2;
    if (*ofsetc - a2pok8_1.dummy <= 0.) {
	goto L420;
    } else {
	goto L400;
    }
L400:
    *ofsetc = a2pok8_1.dummy;
    if (*ofsetf - a2pok8_1.dummy <= 0.) {
	goto L420;
    } else {
	goto L410;
    }
L410:
    *ofsetf = a2pok8_1.dummy;
L420:
    a2pok2_1.jfou = 1;
L430:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L440: */
	    a2pok8_1.w[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.u[i__ + (
		    a2cmmn_1.j + 1) * 3 - 4] - a2pok8_1.u[i__ + a2cmmn_1.j * 
		    3 - 4];
	}
	a2pok8_1.addem1 = a2fpc_1.qnul;
	a2pok8_1.addem2 = a2fpc_1.qnul;
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok8_1.addem1 = a2pok8_1.w[i__ + a2cmmn_1.j * 3 - 4] * 
		    a2pok8_1.u[i__ + (a2cmmn_1.j + 1) * 3 - 4] + 
		    a2pok8_1.addem1;
/* L450: */
	    a2pok8_1.addem2 = a2pok8_1.w[i__ + a2cmmn_1.j * 3 - 4] * 
		    a2pok8_1.w[i__ + a2cmmn_1.j * 3 - 4] + a2pok8_1.addem2;
	}
/* L460: */
/* Computing 2nd power */
	d__2 = a2pok8_1.addem1;
	a2pok8_1.bl[a2cmmn_1.j - 1] = sqrt((d__1 = a2pok8_1.addem2 - d__2 * 
		d__2, abs(d__1)));
    }
    a2pok8_1.dist = *pttype * a2pok8_1.cutrad;
    a2cmmn_1.jgr = 7;
/* L461: */
    apocka_();
/* L462: */
    switch ((int)a2cmmn_1.jgr) {
	case 1:  goto L1610;
	case 2:  goto L1560;
	case 3:  goto L1450;
	case 4:  goto L951;
    }
L951:
    if (a2pok2_1.nc - a2pok2_1.ncutbk <= 0) {
	goto L1140;
    } else {
	goto L960;
    }
L960:
    if (a2pok2_1.kalc != 0) {
	goto L980;
    } else {
	goto L970;
    }
L970:
    if (*ovride != 0.) {
	goto L1000;
    } else {
	goto L1020;
    }
L980:
    if (*ovride != 0.) {
	goto L1000;
    } else {
	goto L990;
    }
L990:
    a2pok2_1.jfou = 1;
L1000:
    i__1 = a2pok2_1.ncutbk;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L1010: */
	    cor[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.ctemp[i__ + a2cmmn_1.j * 
		    3 - 4];
	}
    }
    goto L30;
L1020:
    if (a2pok2_1.jfou <= 0) {
	goto L1040;
    } else {
	goto L1025;
    }
L1025:
    a2pok2_1.jfou = 0;
/* L1030: */
    if (a2pok2_1.jthr <= 0) {
	goto L1040;
    } else {
	goto L1035;
    }
L1035:
    a2pok2_1.jthr = 0;
    goto L1000;
L1040:
    if (a2pok8_1.phitmp - a2pok8_1.sphio2 >= 0.) {
	goto L1000;
    } else {
	goto L1050;
    }
L1050:
    a2pok8_1.sphio2 = a2pok8_1.phitmp;
    a2pok8_1.dummy = *radeff / a2pok8_1.cutrad * (a2fpc_1.q1p + 
	    a2pok8_1.sphio2);
    if (*ofsetc - a2pok8_1.dummy <= 0.) {
	goto L1080;
    } else {
	goto L1060;
    }
L1060:
    a2pok8_1.ofcsto = a2pok8_1.dummy;
    if (*ofsetf - a2pok8_1.dummy <= 0.) {
	goto L1090;
    } else {
	goto L1070;
    }
L1070:
    a2pok8_1.offsto = a2pok8_1.dummy;
    goto L1100;
L1080:
    a2pok8_1.ofcsto = *ofsetc;
L1090:
    a2pok8_1.offsto = *ofsetf;
L1100:
    a2pok8_1.dummy = a2fpc_1.q2p * *radeff / a2pok8_1.cutrad * 
	    a2pok8_1.sphio2;
    if (*ofsetc - a2pok8_1.dummy <= 0.) {
	goto L1000;
    } else {
	goto L1110;
    }
L1110:
    *ofsetc = a2pok8_1.dummy;
    if (*ofsetf - a2pok8_1.dummy <= 0.) {
	goto L1130;
    } else {
	goto L1120;
    }
L1120:
    *ofsetf = a2pok8_1.dummy;
L1130:
    a2pok2_1.jfou = 1;
    a2pok2_1.jthr = 1;
    a2pok8_1.dist -= a2pok8_1.deldst;
    a2pok2_1.kalc = 1;
    switch ((int)a2pok2_1.move) {
	case 1:  goto L1131;
	case 2:  goto L1132;
	case 3:  goto L1132;
	case 4:  goto L1133;
	case 5:  goto L1133;
    }
L1131:
    a2cmmn_1.jgr = 6;
    goto L1134;
L1132:
    a2cmmn_1.jgr = 3;
    goto L1134;
L1133:
    a2cmmn_1.jgr = 5;
L1134:
    apocka_();
    switch ((int)a2cmmn_1.jgr) {
	case 1:  goto L1610;
	case 2:  goto L1560;
	case 3:  goto L1450;
	case 4:  goto L951;
    }
L1140:
    if (a2pok2_1.kalc != 0) {
	goto L1160;
    } else {
	goto L1150;
    }
L1150:
    a2pok2_1.jone = 0;
    a2pok2_1.jtwo = 0;
    a2pok2_1.jthr = 0;
    a2pok2_1.jfou = 0;
/*     COVERAGE TESTS */
L1160:
    a2pok8_1.rtest = a2fpc_1.q2p * *radeff;
    a2pok2_1.kover = 2;
    goto L1180;
L1170:
    a2pok8_1.rtest = *radeff;
    a2pok2_1.kover = 1;
L1180:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	i__2 = a2pok2_1.nless1;
	for (a2cmmn_1.l = 2; a2cmmn_1.l <= i__2; ++a2cmmn_1.l) {
	    a2cmmn_1.k = a2cmmn_1.j + a2cmmn_1.l;
	    if (a2cmmn_1.k - a2pok2_1.nc <= 0) {
		goto L1200;
	    } else {
		goto L1190;
	    }
L1190:
	    a2cmmn_1.k -= a2pok2_1.nc;
L1200:
	    switch ((int)a2pok2_1.kover) {
		case 1:  goto L1210;
		case 2:  goto L1230;
	    }
L1210:
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L1220: */
		a2pok8_1.y[i__ - 1] = a2pok8_1.xiprim[i__ + a2cmmn_1.k * 3 - 
			4] - a2pok8_1.xiprim[i__ + (a2cmmn_1.j + 1) * 3 - 4];
	    }
L1230:
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L1240: */
		a2pok8_1.t[i__ - 1] = a2pok8_1.xiprim[i__ + a2cmmn_1.k * 3 - 
			4] - a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4];
	    }
	    avdot_(a2pok8_1.t, &a2pok8_1.uprim[a2cmmn_1.j * 3 - 3], &
		    a2pok8_1.addem1);
	    avdot_(a2pok8_1.t, a2pok8_1.t, &a2pok8_1.addem2);
/* Computing 2nd power */
	    d__2 = a2pok8_1.addem1;
	    a2pok8_1.dcov = sqrt((d__1 = a2pok8_1.addem2 - d__2 * d__2, abs(
		    d__1)));
	    if (a2pok8_1.dcov - a2pok8_1.rtest <= 0.) {
		goto L1260;
	    } else {
		goto L1360;
	    }
L1260:
	    switch ((int)a2pok2_1.kover) {
		case 1:  goto L1270;
		case 2:  goto L1340;
	    }
L1270:
	    a2pok8_1.addem1 = a2fpc_1.qnul;
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L1280: */
		a2pok8_1.addem1 = a2pok8_1.y[i__ - 1] * (-a2pok8_1.uprim[i__ 
			+ a2cmmn_1.j * 3 - 4]) + a2pok8_1.addem1;
	    }
	    if (a2pok8_1.addem1 < 0.) {
		goto L1290;
	    } else if (a2pok8_1.addem1 == 0) {
		goto L1340;
	    } else {
		goto L1310;
	    }
L1290:
	    avdot_(a2pok8_1.y, a2pok8_1.y, &a2pok8_1.addem1);
	    a2pok8_1.addem2 = sqrt(a2pok8_1.addem1);
	    if (a2pok8_1.addem2 - a2pok8_1.rtest <= 0.) {
		goto L1340;
	    } else {
		goto L1360;
	    }
L1310:
	    avdot_(a2pok8_1.t, &a2pok8_1.uprim[a2cmmn_1.j * 3 - 3], &
		    a2pok8_1.addem1);
	    if (a2pok8_1.addem1 >= 0.) {
		goto L1340;
	    } else {
		goto L1330;
	    }
L1330:
	    a2pok8_1.addem1 = sqrt(a2pok8_1.addem2);
	    if (a2pok8_1.addem1 - a2pok8_1.rtest <= 0.) {
		goto L1340;
	    } else {
		goto L1360;
	    }
L1340:
	    ;
	}
	a2pok2_1.move = 5;
	switch ((int)a2pok2_1.kover) {
	    case 1:  goto L1380;
	    case 2:  goto L1350;
	}
L1350:
	if (a2pok2_1.kalc <= 0) {
	    goto L1450;
	} else {
	    goto L1170;
	}
L1360:
	;
    }
    switch ((int)a2pok2_1.kover) {
	case 1:  goto L1450;
	case 2:  goto L1370;
    }
L1370:
    if (a2pok2_1.kalc <= 0) {
	goto L1450;
    } else {
	goto L1470;
    }
L1380:
    a2pok8_1.addem1 = a2fpc_1.qnul;
    a2pok8_1.addem2 = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
/* Computing 2nd power */
	d__1 = a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4] - a2pok8_1.xiprim[
		i__ - 1];
	a2pok8_1.addem1 = d__1 * d__1 + a2pok8_1.addem1;
/* L1390: */
/* Computing 2nd power */
	d__1 = a2pok8_1.xiprim[i__ + (a2cmmn_1.j + 1) * 3 - 4] - 
		a2pok8_1.xiprim[i__ - 1];
	a2pok8_1.addem2 = d__1 * d__1 + a2pok8_1.addem2;
    }
    if (sqrt(a2pok8_1.addem1) - sqrt(a2pok8_1.addem2) <= 0.) {
	goto L1400;
    } else {
	goto L1430;
    }
L1400:
    for (i__ = 1; i__ <= 3; ++i__) {
	a2pok8_1.wd[i__ - 1] = a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4];
/* L1410: */
	a2pok8_1.xiprim[i__ - 1] = a2pok8_1.xiprim[i__ + (a2cmmn_1.j + 1) * 3 
		- 4];
    }
L1420:
    a2cmmn_1.j = 2;
    a2pok2_1.num = 2;
    goto L1500;
L1430:
    for (i__ = 1; i__ <= 3; ++i__) {
	a2pok8_1.wd[i__ - 1] = a2pok8_1.xiprim[i__ + (a2cmmn_1.j + 1) * 3 - 4]
		;
/* L1440: */
	a2pok8_1.xiprim[i__ - 1] = a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4];
    }
    goto L1420;
L1450:
    a2pok2_1.num = a2pok2_1.nplus1;
    a2cmmn_1.j = a2pok2_1.num;
    goto L1480;
L1460:
    a2cmmn_1.j = a2pok2_1.num - 1;
    a2pok2_1.num = a2cmmn_1.j;
    if (a2cmmn_1.j <= 0) {
	goto L1470;
    } else {
	goto L1480;
    }
L1470:
    switch ((int)a2pok2_1.move) {
	case 1:  goto L1471;
	case 2:  goto L1472;
	case 3:  goto L1473;
	case 4:  goto L1474;
	case 5:  goto L1610;
    }
L1471:
    a2cmmn_1.jgr = 1;
    goto L1475;
L1472:
    a2cmmn_1.jgr = 2;
    goto L1475;
L1473:
    a2cmmn_1.jgr = 4;
    goto L1475;
L1474:
    a2cmmn_1.jgr = 5;
L1475:
    apocka_();
/* L1476: */
    switch ((int)a2cmmn_1.jgr) {
	case 1:  goto L1610;
	case 2:  goto L1560;
	case 3:  goto L1450;
	case 4:  goto L951;
    }
L1480:
    if (a2pok2_1.move < 5) {
	goto L1485;
    }
    if (a2cmmn_1.j > 1) {
	goto L1485;
    }
    a2pock_1.ibm6 = 2;
L1485:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1490: */
	a2pok8_1.wd[i__ - 1] = a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4];
    }
L1500:
    if (a2pock_1.ibm6 != 1) {
	goto L1520;
    }
/* L1510: */
    a2pock_1.ibm2 = 0;
    a2pock_1.ibm3 = 241;
    a2pock_1.ibm6 = 0;
L1520:
    a2pock_1.ibm3 += -3;
/* L1530: */
    if (a2cmmn_1.mulout < 1) {
	goto L1540;
    }
    avsto_(a2cmmn_1.ta, &a2cmmn_1.tcdat[a2pock_1.ibm3 - 1]);
    a2pock_1.ibm3 += -3;
L1540:
    avsto_(a2pok8_1.wd, &a2cmmn_1.tcdat[a2pock_1.ibm3 - 1]);
/* L1550: */
    ++a2pock_1.ibm2;
    if (a2pock_1.ibm3 < 13) {
	goto L1560;
    }
    if (a2pock_1.ibm6 != 2) {
	goto L1460;
    }
L1560:
    ++a2pock_1.ibm1;
    if (a2cmmn_1.mulout == 1) {
	goto L1580;
    }
/* L1570: */
    a2pock_1.ibm4 = a2pock_1.ibm2 * 3;
    goto L1590;
L1580:
    a2pock_1.ibm4 = a2pock_1.ibm2 * 6;
/* ...    *** ON S/360  IBM1, IBM2, IBM4, IPCERR, IBM3,NWD  MUST BE 4 BYTE */
/*            INTEGERS  *** */
L1590:
    atapwt_(&ataptb_1.poctap, &a2pock_1.ipcerr, &c__4, &a2pock_1.ibm1, &c__1, 
	    &a2pock_1.ibm2, &c__1, &a2pock_1.ibm4, &c__1, &a2cmmn_1.tcdat[
	    a2pock_1.ibm3 - 1], &a2pock_1.ibm4, &a2fpc_1.q1p, &c__0, &
	    a2fpc_1.q1p, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1600;
    }
    aerr_(&c__3505);
L1600:
    a2pock_1.ibm2 = 0;
    a2pock_1.ibm3 = 241;
    goto L1460;
/*     USING DATA STORED ON TAPE */
L1610:
    if (a2cmmn_1.cansto[1508] < a2fpc_1.qp5) {
	goto L1650;
    }
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= 3; ++a2cmmn_1.k) {
/* L1611: */
	cor1[a2cmmn_1.k + (a2pok2_1.ncorig + 1) * 3 - 4] = cor1[a2cmmn_1.k - 
		1];
    }
    i__1 = a2pok2_1.ncorig;
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= i__1; ++a2cmmn_1.k) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L1614: */
	    a2cmmn_1.vtem[i__ - 1] = cor1[i__ + a2cmmn_1.k * 3 - 4] - cor1[
		    i__ + (a2cmmn_1.k + 1) * 3 - 4];
	}
	avcros_(a2cmmn_1.vtem, a2cmmn_1.ta, a2cmmn_1.vtem);
	avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
	if (a2cmmn_1.ier == 1) {
	    aerr_(&c__3517);
	}
	avdot_(a2cmmn_1.vtem, &cor1[a2cmmn_1.k * 3 - 3], &a2cmmn_1.a);
	avdot_(a2cmmn_1.vtem, a2pok8_1.wd, &a2cmmn_1.b);
	if ((d__1 = a2cmmn_1.a - a2cmmn_1.b, abs(d__1)) < a2cmmn_1.cutdat[0] 
		- a2fpc_1.qp0001) {
	    aerr_(&c__3518);
	}
/* L1615: */
    }
L1650:
    ++asistm_1.nclrec;
    apockb_();
    return 0;
L9999:
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] != 1) {
	aerr_(&c__3519);
    }
    *pttype -= a2fpc_1.q2p;

    a2cmmn_1.cansto[1508] = *pttype;
    kk1 = a2cmmn_1.ipontr[a2cmmn_1.iips - 1] + 4;
    avsto_(&a2cmmn_1.cansto[kk1 - 1], a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ta, &ans);
    if (abs(ans) < a2fpc_1.qp9x01) {
	aerr_(&c__3507);
    }
    kk2 = a2cmmn_1.ipontr[a2cmmn_1.iips - 1] + 7;
    a2cmmn_1.j = 0;
    jjj = (a2pok2_1.ncorig - 1) * 3 + 1510;
    i__1 = jjj;
    for (a2cmmn_1.k = 1510; a2cmmn_1.k <= i__1; a2cmmn_1.k += 3) {
	++a2cmmn_1.j;
	avsto_(&a2cmmn_1.cansto[a2cmmn_1.k - 1], gpnt);
	avdot_(gpnt, a2cmmn_1.vtem, &ans);
	avdot_(a2cmmn_1.ta, a2cmmn_1.vtem, &bns);
	ans = (a2cmmn_1.cansto[kk2 - 1] - ans) / bns;
	avmult_(a2cmmn_1.ta, &ans, a2cmmn_1.temp);
	avadd_(gpnt, a2cmmn_1.temp, a2cmmn_1.temp);
	avsto_(a2cmmn_1.temp, &cor[a2cmmn_1.j * 3 - 3]);
/* L9998: */
    }
    goto L9997;
} /* apock_ */

#undef pttype
#undef ovride
#undef ofsetf
#undef ofsetc
#undef frthre
#undef pocdat
#undef radeff
#undef frtwo
#undef frone
#undef cor1
#undef cor


