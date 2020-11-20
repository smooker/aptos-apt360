/* ATLNRM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal sp[3], sn[3], tp[3], tn[3], snk[3], snl[3], spk[3], spl[3], 
	    tnk[3], tnl[3], tpk[3], tpl[3], plnv[3], cc[3], u1[3], cuth[3], 
	    sfvct[3], vndir[3], vmd[3], vt[3], tee[3], slx[3], dplan[3], s[1],
	     rc[1], plnd[1], th[1], csd[1], z__[1], eps1[1], eps2[1], eps3[1],
	     eps4[1], eps6[1], eps8[1], tau[1], tau1[1], tau2[1], stck[1], 
	    stckn[1], stck1[1], stck2[1], cos1[1], dpmx1[1], cplfl[1], cptst[
	    1], plncs[1], plnd1[1], pltst[1], past[1], spast[1], adcs[1], h__[
	    1], cutr[1], afillr[500];
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
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, itlsel;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

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

static integer c__4 = 4;
static integer c_b5 = 111111;
static integer c__1061 = 1061;

/* Subroutine */ int atlnrm_(u1var)
doublereal *u1var;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_30 = { {'A', 'T', 'L', 'N', 'R', 'M', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_30)


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, ll;
    static doublereal aa1;
    static integer jj;
    static doublereal zln[21]	/* was [3][7] */;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    static doublereal zlp[21]	/* was [3][7] */;
    static integer itz[7];
    static doublereal caj24[3], ans;
    extern /* Subroutine */ int avadd_();
    static doublereal qqk;
    static integer ksaka, itn;
    static doublereal zzll;
    extern /* Subroutine */ int avsto_(), avsub_();
    static integer lside, ksega1, kount;
    extern /* Subroutine */ int avdot_(), aerr_();
    static integer kamin, kside, kkk, kamax;
    extern /* Subroutine */ int avleng_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    static doublereal zendis[7];
    extern /* Subroutine */ int adyndp_();
    static integer ksegup, kseglo, kbests, kkkkkk;
    extern /* Subroutine */ int avmult_(), avnorm_(), avcros_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
    /* Parameter adjustments */
    --u1var;

    /* Function Body */
    if (a2cmmn_1.multax != 1 || a2cmmn_1.icc != 1) {
	goto L61871;
    }
    if (a2cmmn_1.istrup != 1 || a2cmmn_1.is != a2cmmn_1.ips) {
	goto L61871;
    }
    if (a2cmmn_1.jam != 1) {
	goto L61871;
    }
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ta, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    goto L39;
L61871:
/* ........... */
    lside = 0;
    adyndp_(ab, &c__4, &c_b5);
/* 	segments of the tool? */
    ksega1 = 0;
/* 	upper line segment of tool? */
    ksegup = 0;
/* 	lower segment? */
    kseglo = 0;
/* ...KBESTS = 1 INDICATES WORK ONLY WITH BEST SEGMENT AFTER FAILING FIRST */
/* ...25 ITERATIONS. BEST SEG SENT HERE AS NEG VALUE IN IAMDCT. */
    kbests = 0;
    if (a2cmmn_1.iamdct >= 0) {
	goto L12345;
    }
    kbests = 1;
    ksega1 = -a2cmmn_1.iamdct;
    a2cmmn_1.iamdct = 0;
    ksegup = ksega1 + 8;
    kseglo = ksega1 - 8;
L12345:
    kount = 0;
    kkkkkk = 0;
    if (a2cmmn_1.j24[a2cmmn_1.iis - 1] != 2) {
	goto L99999;
    }
    ksaka = a2cmmn_1.ipontr[a2cmmn_1.iis - 1];
    avsto_(&a2cmmn_1.cansto[ksaka + 6], caj24);
    avdot_(a2cmmn_1.ta, caj24, &ans);
    ans = abs(ans);
    if (ans < a2fpc_1.qp9999 && ans > a2fpc_1.qp0047) {
	kkkkkk = 1;
    }
L99999:
    a2cmmn_1.j = a2cmmn_1.is + 2;
    a2cmmn_1.jfind = 1;
    a2cmmn_1.it = a2cmmn_1.ibegin;
    avsto_(&u1var[1], a2cmmn_1.uvec);
    if (a2cmmn_1.itlon[a2cmmn_1.iis - 1] == 0) {
	goto L1;
    }
/* L451: */
    if ((i__1 = a2cmmn_1.iafl[a2cmmn_1.iis - 1] + a2cmmn_1.jtlflg[
	    a2cmmn_1.iis - 1]) < 0) {
	goto L403;
    } else if (i__1 == 0) {
	goto L404;
    } else {
	goto L401;
    }
L403:
    if (a2cmmn_1.ipt != 0) {
	goto L84;
    } else {
	goto L1;
    }
L404:
    if (a2ctdf_1.r1[64] != 0.) {
	goto L405;
    } else {
	goto L406;
    }
L405:
    if (a2cmmn_1.jtlflg[a2cmmn_1.iis - 1] == 1) {
	goto L1000;
    }
    a2cmmn_1.temp[0] = a2fpc_1.q1p;
    a2cmmn_1.temp[1] = a2fpc_1.q1p;
    goto L407;
L401:
    avmult_(a2cmmn_1.uvec, &a2cmmn_1.cutr[a2cmmn_1.is - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.cuth[a2cmmn_1.is - 1], &
	    a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.te, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.uvec, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
/* .....***** */
    goto L39;
L406:
    a2cmmn_1.temp[1] = a2fpc_1.qnul;
L407:
    qqk = a2cmmn_1.temp[0] * a2ctdf_1.r1[64];
    avmult_(a2cmmn_1.uvec, &qqk, a2cmmn_1.vtem);
    avmult_(a2cmmn_1.ta, &a2ctdf_1.tlhite[64], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    goto L408;
L84:
    a2ctdf_1.tcont[64] = -a2fpc_1.q1p;
/* L85: */
    a2cmmn_1.n = 8;
/* .....***** */
/* ...DETERMINE IF CUTTER MIDPOINT IS INSIDE OR OUTSIDE OF SURFACE */
/* L11: */
    ans = a2fpc_1.qp5 * a2cmmn_1.cutdat[6];
    avmult_(a2cmmn_1.ta, &ans, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, a2cmmn_1.te, a2cmmn_1.vtem);
    avsub_(&a2cmmn_1.cc[a2cmmn_1.is - 1], a2cmmn_1.vtem, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    ans = (d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(d__1)) - ans;
    itn = 1;
    if (ans < a2fpc_1.qnul) {
	itn = -1;
    }
/* ...ITN NOW SET TO INDICATE IF CUTTER MIDPOINT IS */
/*    INSIDE OR OUTSIDE THE SURFACE */
/* .....***** */
L13:
    if ((d__1 = a2ctdf_1.tcont[a2cmmn_1.it - 1]) < 0.) {
	goto L700;
    } else if (d__1 == 0) {
	goto L42;
    } else {
	goto L14;
    }
L14:
    a2cmmn_1.k = 1;
    if (kbests == 0) {
	goto L14444;
    }
    if (a2cmmn_1.it > ksegup) {
	goto L42;
    }
    if (a2cmmn_1.it < kseglo) {
	goto L42;
    }
L14444:
    i__1 = a2cmmn_1.j;
    for (i__ = a2cmmn_1.is; i__ <= i__1; ++i__) {
	a2cmmn_1.refpnt[a2cmmn_1.k - 1] = a2cmmn_1.te[a2cmmn_1.k - 1] + 
		a2ctdf_1.r1[a2cmmn_1.it - 1] * a2cmmn_1.uvec[a2cmmn_1.k - 1] 
		+ a2ctdf_1.tlhite[a2cmmn_1.it - 1] * a2cmmn_1.ta[a2cmmn_1.k - 
		1];
	a2cmmn_1.ogle[a2cmmn_1.k - 1] = a2cmmn_1.cc[i__ - 1] - 
		a2cmmn_1.refpnt[a2cmmn_1.k - 1];
/* L15: */
	++a2cmmn_1.k;
    }
    if (a2cmmn_1.isigcr[a2cmmn_1.iis - 1] != 1) {
	goto L14001;
    }

    avdot_(a2cmmn_1.ogle, &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans);
    if (ans < a2fpc_1.qnul) {
	goto L14002;
    }
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ogle);
    goto L14001;
L14002:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ogle);
L14001:
    avnorm_(a2cmmn_1.ogle, a2cmmn_1.u2, &a2cmmn_1.ier);
/* .....***** */
    if (a2cmmn_1.ier != 0) {
	goto L42;
    }
/* L155: */
    if (a2ctdf_1.tlinc[a2cmmn_1.it - 1] != 0.) {
	goto L40;
    } else {
	goto L16;
    }
L40:
    a2ctdf_1.corrad[a2cmmn_1.it - 1] = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
	a2cmmn_1.u2[i__ - 1] = cosl[a2cmmn_1.it - 1] * a2cmmn_1.uvec[i__ - 1] 
		+ sinl[a2cmmn_1.it - 1] * a2cmmn_1.ta[i__ - 1];
/* L41: */
	a2ctdf_1.corrad[a2cmmn_1.it - 1] += a2cmmn_1.ogle[i__ - 1] * 
		a2cmmn_1.u2[i__ - 1];
    }
    if (a2cmmn_1.isigcr[a2cmmn_1.iis - 1] != 1) {
	goto L45;
    }
    avdot_(a2cmmn_1.u2, &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans);
    if (abs(ans) >= a2fpc_1.qp4x01) {
	goto L42;
    }
    avsub_(a2cmmn_1.refpnt, &a2cmmn_1.sp[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans);
    a2ctdf_1.corrad[a2cmmn_1.it - 1] = a2fpc_1.qnul;
    a2cmmn_1.k = a2cmmn_1.is;
    for (i__ = 1; i__ <= 3; ++i__) {
	a2ctdf_1.corrad[a2cmmn_1.it - 1] += (a2cmmn_1.sp[a2cmmn_1.k - 1] + 
		ans * a2cmmn_1.sn[a2cmmn_1.k - 1] - a2cmmn_1.refpnt[i__ - 1]) 
		* a2cmmn_1.u2[i__ - 1];
/* L46: */
	++a2cmmn_1.k;
    }
L45:
    if (a2ctdf_1.corrad[a2cmmn_1.it - 1] + a2fpc_1.qp5x01 >= 0.) {
	goto L43;
    } else {
	goto L42;
    }
L42:
    a2cmmn_1.it += a2cmmn_1.n;
    goto L13;
L16:
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 0 && a2cmmn_1.isigcr[a2cmmn_1.iis - 
	    1] <= 0) {
	goto L1667;
    }
    avdot_(a2cmmn_1.ogle, &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans);
    if (ans < 0.) {
	goto L1665;
    } else if (ans == 0) {
	goto L1667;
    } else {
	goto L1664;
    }
L1664:
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ogle);
    goto L1666;
L1665:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ogle);
L1666:
    avsto_(a2cmmn_1.ogle, a2cmmn_1.u2);
L1667:
    avdot_(a2cmmn_1.ogle, a2cmmn_1.ta, &a2cmmn_1.com1);
    avdot_(a2cmmn_1.ogle, a2cmmn_1.ogle, &a2cmmn_1.com4);
    a2cmmn_1.com4 -= a2cmmn_1.com1 * a2cmmn_1.com1;
/* .....***** */
    if (a2cmmn_1.com4 <= 0.) {
	goto L18;
    } else {
	goto L19;
    }
L18:
    if (a2cmmn_1.it - 57 != 0) {
	goto L21;
    } else {
	goto L101;
    }
L101:
    a2cmmn_1.tangl = -a2fpc_1.q1pe30;
    avsto_(a2cmmn_1.ta, a2cmmn_1.u2);
/* .....***** */
    goto L25;
L1:
    a2cmmn_1.temp[1] = a2fpc_1.qnul;
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
L408:
    avsub_(&a2cmmn_1.cc[a2cmmn_1.is - 1], &a2cmmn_1.tp[a2cmmn_1.is - 1], &
	    a2cmmn_1.tn[a2cmmn_1.is - 1]);
    zzll = a2cmmn_1.temp[0] * a2cmmn_1.temp[1] + a2fpc_1.q4p;
    ll = (integer) zzll;
    avnorm_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1], &
	    a2cmmn_1.ier);
/* .....***** */
    if (a2cmmn_1.j24[a2cmmn_1.iis - 1] == 2) {
	goto L4448;
    }
    if (a2cmmn_1.ier == 0) {
	goto L8;
    }
L3:
    if (a2cmmn_1.temp[1] <= 0.) {
	goto L409;
    } else {
	goto L410;
    }
L409:
    aerr_(&c__1061);
L410:
    a2cmmn_1.temp[ll - 1] = -a2fpc_1.q1p;
    goto L417;
L8:
    if (a2cmmn_1.temp[1] <= 0.) {
	goto L411;
    } else {
	goto L412;
    }
L411:
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] <= 0) {
	goto L413;
    } else {
	goto L414;
    }
L413:
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans)
	    ;
    if (ans <= 0.) {
	goto L39;
    } else {
	goto L340;
    }
L414:
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tnl[a2cmmn_1.is - 1], &
	    ans);
    if (ans >= 0.) {
	goto L39;
    } else {
	goto L340;
    }
L340:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    goto L39;
L412:
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] > 0) {
	goto L416;
    }
/* L415: */
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans)
	    ;
    a2cmmn_1.temp[ll - 1] = abs(ans);
    goto L417;
L416:
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tnl[a2cmmn_1.is - 1], &
	    ans);
    a2cmmn_1.temp[ll - 1] = abs(ans);
L417:
    if (a2cmmn_1.temp[0] >= 0.) {
	goto L420;
    } else {
	goto L418;
    }
L418:
    if (a2cmmn_1.temp[2] - a2cmmn_1.temp[4] >= 0.) {
	goto L411;
    } else {
	goto L419;
    }
L419:
    a2cmmn_1.temp[0] = a2fpc_1.q1p;
    goto L406;
L420:
    a2cmmn_1.temp[0] = -a2fpc_1.q1p;
    goto L407;
L19:
    a2cmmn_1.com4 = sqrt(a2cmmn_1.com4);
    if ((d__1 = a2cmmn_1.com1 / a2cmmn_1.com4, abs(d__1)) - a2fpc_1.q1000p >= 
	    0.) {
	goto L18;
    } else {
	goto L20;
    }
L20:
    a2cmmn_1.tangl = -a2cmmn_1.com1 / a2cmmn_1.com4;
    goto L22;
L21:
    a2cmmn_1.tangl = a2fpc_1.q1pe30;
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ta, a2cmmn_1.u2);
    goto L25;
/*   22 CALL AVDOT(UVEC,OGLE,ANS) IF(ANS) 23,25,25 */
L22:
    avdot_(a2cmmn_1.uvec, a2cmmn_1.ogle, &ans);
    if (ans >= 0.) {
	goto L25;
    } else {
	goto L23;
    }
L23:
    a2cmmn_1.tangl = -a2cmmn_1.tangl;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L24: */
	a2cmmn_1.u2[i__ - 1] = -a2cmmn_1.u2[i__ - 1];
    }
L25:
/* .....***** */
    if (a2ctdf_1.tanlo[a2cmmn_1.it - 1] - a2cmmn_1.tangl >= 0.) {
	goto L28;
    } else {
	goto L26;
    }
L26:
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] != 0) {
	goto L27;
    } else {
	goto L42;
    }
L27:
    a2cmmn_1.n = -8;
    goto L42;
L28:
    if (a2ctdf_1.tanhi[a2cmmn_1.it - 1] - a2cmmn_1.tangl <= 0.) {
	goto L29;
    } else {
	goto L42;
    }
L29:
    avsto_(a2cmmn_1.u2, a2cmmn_1.zlnorm);
L31:
    avmult_(a2cmmn_1.u2, &a2ctdf_1.corrad[a2cmmn_1.it - 1], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.refpnt, a2cmmn_1.vtem, a2cmmn_1.zlpnt);
/* .....***** */

    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] > 0) {
	goto L237;
    }
L33:
    ++kount;
/* ...STORE TENTATIVE TP,TN,IT, AND GO TO EXAMINE NEXT SEGMENT */
    avsto_(a2cmmn_1.zlnorm, &zln[kount * 3 - 3]);
    avsto_(a2cmmn_1.zlpnt, &zlp[kount * 3 - 3]);
    avsub_(&a2cmmn_1.cc[a2cmmn_1.is - 1], a2cmmn_1.zlpnt, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
/* .....***** */
    a2cmmn_1.cendis = (d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(d__1)) - ans;
    if (a2cmmn_1.isigcr[a2cmmn_1.iis - 1] != 1) {
	goto L333;
    }
    avsub_(&a2cmmn_1.sp[a2cmmn_1.is - 1], a2cmmn_1.zlpnt, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.zlnorm, &a2cmmn_1.cendis);
L333:
    zendis[kount - 1] = a2cmmn_1.cendis;

/* L36: */
    a2cmmn_1.jfind = -1;

/* .....***** */
    itz[kount - 1] = a2cmmn_1.it;
/* .....***** */
    goto L42;
L237:
    avdot_(&a2cmmn_1.tnl[a2cmmn_1.is - 1], a2cmmn_1.zlnorm, &ans);
    aa1 = -a2fpc_1.q1p;
    if (ans >= 0.) {
	goto L33;
    } else {
	goto L601;
    }
L601:
    avdot_(&a2cmmn_1.tnl[a2cmmn_1.is - 1], a2cmmn_1.ta, &ans);
    if (abs(ans) - a2fpc_1.qp9999 <= 0.) {
	goto L33;
    } else {
	goto L603;
    }
L603:
    if (kount > 0) {
	goto L42;
    }
    if (a2cmmn_1.it - 57 != 0) {
	goto L604;
    } else {
	goto L605;
    }
L604:
    a2cmmn_1.it = 57;
    a2cmmn_1.itseg[a2cmmn_1.iis - 1] = 57;
    avmult_(&a2cmmn_1.u1[a2cmmn_1.is - 1], &a2ctdf_1.r1[a2cmmn_1.it - 1], 
	    a2cmmn_1.vtem);
    avmult_(a2cmmn_1.ta, &a2ctdf_1.tlhite[a2cmmn_1.it - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    goto L39;
L605:
    a2cmmn_1.itseg[a2cmmn_1.iis - 1] = a2cmmn_1.ibegin;
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    goto L39;
L39:
/* .....***** */
    return 0;
L43:
    if (a2ctdf_1.corrad[a2cmmn_1.it - 1] - a2ctdf_1.umax[a2cmmn_1.it - 1] >= 
	    0.) {
	goto L42;
    } else {
	goto L44;
    }
L44:
    avmult_(a2cmmn_1.uvec, &sinl[a2cmmn_1.it - 1], a2cmmn_1.zlnorm);
    avmult_(a2cmmn_1.ta, &cosl[a2cmmn_1.it - 1], a2cmmn_1.vtem);
    avsub_(a2cmmn_1.zlnorm, a2cmmn_1.vtem, a2cmmn_1.zlnorm);
    if (a2ctdf_1.corrad[a2cmmn_1.it - 1] < a2fpc_1.qp01 * a2ctdf_1.umax[
	    a2cmmn_1.it - 1]) {
	goto L31;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 1) {
	a2ctdf_1.corrad[a2cmmn_1.it - 1] = a2ctdf_1.umax[a2cmmn_1.it - 1];
    }
    goto L31;
L700:
    if (a2cmmn_1.jfind < 0) {
	goto L650;
    }
    if (kbests == 0) {
	goto L701;
    }
    if (a2cmmn_1.it > ksegup) {
	goto L650;
    }
    if (a2cmmn_1.it < kseglo) {
	goto L650;
    }
L701:
    a2cmmn_1.temp[0] = a2fpc_1.q2p * (doublereal) a2cmmn_1.jtn[a2cmmn_1.iis - 
	    1] - a2fpc_1.q1p;
    avmult_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.temp, &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    avdot_(a2cmmn_1.ta, &a2cmmn_1.tn[a2cmmn_1.is - 1], &ans);
    a2cmmn_1.com1 = -ans;
    a2cmmn_1.com4 = sqrt((d__1 = a2fpc_1.q1p - a2cmmn_1.com1 * a2cmmn_1.com1, 
	    abs(d__1)));
    if (a2cmmn_1.com4 - a2fpc_1.qp001 <= 0.) {
	goto L702;
    } else {
	goto L703;
    }
L702:
    if (a2cmmn_1.com1 >= 0.) {
	goto L605;
    } else {
	goto L604;
    }
L703:
    a2cmmn_1.tangl = a2cmmn_1.com1 / a2cmmn_1.com4;
    a2cmmn_1.it = a2cmmn_1.ibegin;
L704:
    if ((d__1 = a2ctdf_1.tcont[a2cmmn_1.it - 1]) < 0.) {
	goto L3;
    } else if (d__1 == 0) {
	goto L705;
    } else {
	goto L706;
    }
L705:
    a2cmmn_1.it += 8;
    goto L704;
L706:
    if (a2ctdf_1.tlinc[a2cmmn_1.it - 1] != 0.) {
	goto L705;
    } else {
	goto L707;
    }
L707:
    if (a2cmmn_1.tangl - a2ctdf_1.tanhi[a2cmmn_1.it - 1] >= 0.) {
	goto L708;
    } else {
	goto L705;
    }
L708:
    avmult_(a2cmmn_1.ta, &a2ctdf_1.tlhite[a2cmmn_1.it - 1], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avmult_(a2cmmn_1.uvec, &a2ctdf_1.r1[a2cmmn_1.it - 1], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2ctdf_1.corrad[a2cmmn_1.it - 1], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    goto L39;
L1000:
    if (a2cmmn_1.j40 == 1) {
	goto L2000;
    }
L2010:
/* .....***** */
    avmult_(a2cmmn_1.uvec, &a2ctdf_1.r1[64], a2cmmn_1.vtem);
    avmult_(a2cmmn_1.ta, &a2ctdf_1.tlhite[64], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    if (a2cmmn_1.iamdct < 20) {
	goto L1001;
    }
    avmult_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.rc[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avsub_(&a2cmmn_1.sp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.cc[
	    a2cmmn_1.is - 1]);
L1001:
    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.cc[a2cmmn_1.is - 1], &
	    a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avnorm_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1], &
	    a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L1005;
    }
L1002:
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], a2cmmn_1.uvec, &ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
		a2cmmn_1.is - 1]);
    }
    goto L39;
L1005:
/* .....***** */
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    goto L1002;
L4448:
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans)
	    ;
    if (abs(ans) < a2fpc_1.qp01) {
	avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    }
    goto L8;
L2000:
    avcros_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ta, a2cmmn_1.vtem);
    avcros_(a2cmmn_1.ta, a2cmmn_1.vtem, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avnorm_(&a2cmmn_1.tn[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	goto L2010;
    }
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans)
	    ;
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] == 1 && ans > a2fpc_1.qnul) {
	goto L2020;
    }
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] == 0 && ans < a2fpc_1.qnul) {
	goto L2020;
    }
    avsub_(a2cmmn_1.vnul, a2cmmn_1.vtem, a2cmmn_1.vtem);
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
L2020:
    avmult_(a2cmmn_1.vtem, &a2cmmn_1.ra, a2cmmn_1.vtem);
    avmult_(a2cmmn_1.ta, &a2cmmn_1.hi, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.te, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    goto L39;
L650:
/* ... IF ONLY ONE LINE-UP, STORE ZLNORM,ZLPNT,ITSEG AND EXIT */
    if (kount > 1) {
	goto L655;
    }
    kamin = 1;
    if (lside > 0) {
	goto L685;
    }
    lside = 1;
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ta, &ans);
    if (abs(ans) < .98) {
	goto L685;
    }
    avdot_(zln, &a2cmmn_1.tn[a2cmmn_1.is - 1], &ans);
    if (ans >= a2fpc_1.qnul) {
	goto L685;
    }
    avsub_(a2cmmn_1.vnul, a2cmmn_1.uvec, a2cmmn_1.uvec);
    a2cmmn_1.it = a2cmmn_1.ibegin;
    goto L13;
/* SEE IF ALL LINE-UP TOOL POINTS ON THE SAME SIDE OF THE SURFACE */
/*     KSIDE = 1      ALL ON SAME SIDE OF SURFACE */
/*    KSIDE = -1    ALL NOT ON SAME SIDE OF SURFACE */
L655:
    kside = 1;
    if (a2cmmn_1.istrup == 0) {
	goto L675;
    }
    i__1 = kount;
    for (kkk = 2; kkk <= i__1; ++kkk) {
	if (zendis[kkk - 1] * zendis[0] < a2fpc_1.qnul) {
	    kside = -1;
	}
/* L665: */
    }
L675:
    if (kside < 0) {
	goto L690;
    }
/* ... LINE-UP TOOL POINTS ALL ON THE SAME SIDE */
    kamax = 1;
    kamin = 1;
    i__1 = kount;
    for (a2cmmn_1.j = 2; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	if ((d__1 = zendis[a2cmmn_1.j - 1], abs(d__1)) > (d__2 = zendis[kamax 
		- 1], abs(d__2))) {
	    kamax = a2cmmn_1.j;
	}
	if ((d__1 = zendis[a2cmmn_1.j - 1], abs(d__1)) < (d__2 = zendis[kamin 
		- 1], abs(d__2))) {
	    kamin = a2cmmn_1.j;
	}
/* L680: */
    }
    if (a2cmmn_1.istrup == 0) {
	goto L685;
    }
    if (zendis[0] * (doublereal) itn * a2cmmn_1.zign >= a2fpc_1.qnul) {
	goto L685;
    }
L696:
    avsto_(&zln[kamax * 3 - 3], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(&zlp[kamax * 3 - 3], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    a2cmmn_1.itseg[a2cmmn_1.iis - 1] = itz[kamax - 1];
    a2cmmn_1.j = kamax;
    goto L39393;
L685:
    avsto_(&zln[kamin * 3 - 3], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(&zlp[kamin * 3 - 3], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    a2cmmn_1.itseg[a2cmmn_1.iis - 1] = itz[kamin - 1];
    a2cmmn_1.j = kamin;
    goto L39393;
/* ... LINE-UP TOOL POINTS NOT ALL ON SAME SIDE */
L690:
    kamax = 1;
    kamin = 1;
    i__1 = kount;
    for (jj = 2; jj <= i__1; ++jj) {
	if (zendis[jj - 1] > zendis[kamax - 1]) {
	    kamax = jj;
	}
	if (zendis[jj - 1] < zendis[kamin - 1]) {
	    kamin = jj;
	}
/* L695: */
    }
    if ((doublereal) itn * a2cmmn_1.zign > a2fpc_1.qnul) {
	goto L685;
    }
    goto L696;
L39393:
    if (kount != 2) {
	goto L39;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] != 1) {
	goto L39;
    }
    if (a2cmmn_1.is != a2cmmn_1.ips) {
	goto L39;
    }
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] != 0) {
	goto L39;
    }
    avdot_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans)
	    ;
    if (ans < a2fpc_1.qnul) {
	goto L39;
    }
    if (a2cmmn_1.j == 1) {
	jj = 2;
    }
    if (a2cmmn_1.j == 2) {
	jj = 1;
    }
    avsto_(&zln[jj * 3 - 3], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(&zlp[jj * 3 - 3], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    a2cmmn_1.itseg[a2cmmn_1.iis - 1] = itz[jj - 1];
    goto L39;
} /* atlnrm_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


