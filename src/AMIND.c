/* AMIND.f -- translated by f2c (version 20000121).
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

static struct {
    integer k1083;
} kk1083_;

#define kk1083_1 kk1083_

/* Table of constant values */

static integer c__4 = 4;
static integer c_b4 = 111100;
static integer c__6 = 6;
static integer c_b17 = 110000;
static integer c__12 = 12;
static integer c_n1004 = -1004;
static integer c__1009 = 1009;
static integer c__1002 = 1002;

/* Subroutine */ int amind_()
{
    /* Initialized data */

    static struct {
	char e_1[136];
	real e_2;
	} equiv_27 = { {'A', 'M', 'I', 'N', 'D', ' ', 'T', 'P', 'A', 'M', 'I',
		 'N', 'D', ' ', '0', '1', 'A', 'M', 'I', 'N', 'D', ' ', '0', 
		'2', 'A', 'M', 'I', 'N', 'D', ' ', '0', '3', 'A', 'M', 'I', 
		'N', 'D', ' ', '0', '4', 'A', 'M', 'I', 'N', 'D', ' ', '0', 
		'5', 'A', 'M', 'I', 'N', 'D', ' ', '0', '6', 'A', 'M', 'I', 
		'N', 'D', ' ', '0', '7', 'A', 'M', 'I', 'N', 'D', ' ', '0', 
		'8', 'A', 'M', 'I', 'N', 'D', ' ', 'E', 'X', 'A', 'M', 'I', 
		'N', 'D', ' ', '0', '9', 'A', 'M', 'I', 'N', 'D', ' ', '1', 
		'0', 'A', 'M', 'I', 'N', 'D', ' ', '1', '1', 'A', 'M', 'I', 
		'N', 'D', ' ', '1', '2', 'A', 'M', 'I', 'N', 'D', ' ', '1', 
		'3', 'A', 'M', 'I', 'N', ' ', 'D', '1', '4', 'A', 'M', 'I', 
		'N', 'D', ' ', '1', '5'}, (float)0. };

#define ab ((real *)&equiv_27)


    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign();

    /* Local variables */
    static integer i__;
    static doublereal qq, ans;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    static doublereal u1ibm[3];
    extern /* Subroutine */ int avadd_();
    static integer kju1, map;
    static doublereal sibm;
    extern /* Subroutine */ int aerr_(), amd2_();
    static doublereal tnibm[3], snibm[3], tpibm[3], spibm[3];
    static integer ksntn, kount;
    static doublereal flipl;
    extern /* Subroutine */ int avsto_(), avdot_(), avsub_(), au1cmp_();
    static integer ksega1, iret, ktmadj;
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    static doublereal saveth;
    static integer kbests;
    extern /* Subroutine */ int adyndp_();
    static integer newmap, jtnmap;
    extern /* Subroutine */ int avnorm_(), avmult_(), ajundd_(), accurv_(), 
	    atlnrm_(), atltst_();
    static integer itlret;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ... A2CMMN START */
/* ... A2CMMN END */
    saveth = a2cmmn_.th[(576 + (0 + (a2cmmn_.is - 1 << 3)) - 576) / 8];
    a2cmmn_.itlsel = 1;
    ktmadj = 0;
L22222:
/* ...KBESTS = 1 INDICATES WORK ONLY WITH BEST SEGMENT AFTER FAILING FIRST */
/* ...25 ITERATIONS. BEST SEG SENT TO ATLNRM AS NEG VALUE IN IAMDCT. */
    kbests = 0;
    a2cmmn_.jmin = 0;
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] == 0) {
	a2cmmn_.th[a2cmmn_.is - 1] = a2fpc_1.qnul;
    }
    adyndp_(ab, &c__4, &c_b4);
    a2cmmn_.zign = a2fpc_1.q1p;
    newmap = 0;
    ksntn = 0;
L10101:
    a2cmmn_.j = a2cmmn_.is + 2;
    jtnmap = 0;
    a2cmmn_.j40 = 0;
    kount = 0;
    kk1083_1.k1083 = 0;
    a2cmmn_.iamdct = 0;
    if (newmap == 0) {
	flipl = -a2fpc_1.qp3;
    }
    a2cmmn_.flipck = a2fpc_1.qnul;
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tnl[a2cmmn_.is - 1]);
    if (a2cmmn_.jent[a2cmmn_.iis - 1] != 0) {
	goto L2;
    } else {
	goto L12;
    }
L2:
    if (a2cmmn_.ifrl == 1 && a2cmmn_.iis == a2cmmn_.iids && (a2cmmn_.j24[
	    a2cmmn_.iis - 1] == 7 || a2cmmn_.j24[a2cmmn_.iis - 1] == 8)) {
	avsto_(a2cmmn_.pmove, &a2cmmn_.tn[a2cmmn_.is - 1]);
    }
    avnorm_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1], &
	    a2cmmn_.ier);
    if (a2cmmn_.igo > 2 || a2cmmn_.ier != 0) {
	avsto_(&a2cmmn_.tnl[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1]);
    }
    if (a2cmmn_.jtlflg[a2cmmn_.iis - 1] == 1) {
	goto L3;
    }
    a2cmmn_.temp[0] = a2fpc_1.qp5 * a2cmmn_.cutdat[6];
    ans = min(a2cmmn_.temp[0],a2cmmn_.cutdat[0]);
    if (a2cmmn_.j24[a2cmmn_.iis - 1] == 4 && a2cmmn_.rc[a2cmmn_.is - 1] < 
	    a2fpc_1.qnul) {
	goto L405;
    }
    if (ktmadj == 0) {
	ans = a2cmmn_.temp[0];
    }
L405:
//find tool midpoint given tool endpoint and tool axis; ans=1/2 ht of tool
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1: */
	a2cmmn_.tm[i__ - 1] = a2cmmn_.te[i__ - 1] + ans * a2cmmn_.ta[i__ - 
		1];
    }
    avsto_(a2cmmn_.tm, &a2cmmn_.tp[a2cmmn_.is - 1]);
    a2cmmn_.rc[a2cmmn_.is - 1] = a2cmmn_.rc1;
    goto L403;
L3:
    avmult_(a2cmmn_.ta, &a2ctdf_1.tlhite[64], &a2cmmn_.tp[a2cmmn_.is - 1]);
    avadd_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.te, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    a2cmmn_.rc[a2cmmn_.is - 1] = a2cmmn_.rc1;
L403:
    a2cmmn_.z__[a2cmmn_.is - 1] = a2fpc_1.q1p;
    if ((i__1 = a2cmmn_.iafl[a2cmmn_.iis - 1]) < 0) {
	goto L201;
    } else if (i__1 == 0) {
	goto L202;
    } else {
	goto L218;
    }
L201:
    a2cmmn_.itseg[a2cmmn_.iis - 1] = a2cmmn_.ibegin;
    goto L251;
/* *** */
/* *** */
/*      NOTE DIFFICULTY HERE */
/*      HAS DO WITH SECTN2 MODIFICATION */
/* *** */
/* *** */
/* 218 TP(IS)=TE+SV(IS+130) */
/*     TP(IS+1)=TE(2)+SV(IS+131) */
/*     TP(IS+2)=TE(3)+SV(IS+132) */
L218:
    avadd_(a2cmmn_.te, &a2cmmn_.cuth[a2cmmn_.is - 1], &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    adyndp_(&ab[2], &c__6, &c_b17);
L251:
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] == 0) {
	avsto_(a2cmmn_.te, &a2cmmn_.tp[a2cmmn_.is - 1]);
    }
    ajundd_();
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 0) {
	goto L4;
    } else {
	goto L6;
    }
L4:
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1]);
    goto L9;
L6:
    avdot_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1], &
	    a2cmmn_.z__[a2cmmn_.is - 1]);
    if ((d__1 = a2cmmn_.z__[a2cmmn_.is - 1], abs(d__1)) < a2fpc_1.qp005) {
	goto L6000;
    }
L6005:
    a2cmmn_.z__[a2cmmn_.is - 1] *= a2cmmn_.s[a2cmmn_.is - 1];
    d__1 = a2cmmn_.past[a2cmmn_.is - 1] * a2cmmn_.z__[a2cmmn_.is - 1];
    a2cmmn_.z__[a2cmmn_.is - 1] = -d_sign(&a2fpc_1.q1p, &d__1);
/* L445: */
    avmult_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.z__[a2cmmn_.is - 1], &
	    a2cmmn_.sn[a2cmmn_.is - 1]);
    avsub_(a2cmmn_.vnul, &a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.tn[
	    a2cmmn_.is - 1]);
    if (a2cmmn_.th[a2cmmn_.is - 1] != a2fpc_1.qnul) {
	goto L9;
    }
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] != 0) {
	goto L9;
    }
    avdot_(&a2cmmn_.tn[a2cmmn_.is - 1], a2cmmn_.ta, &ans);
    if (ans < a2fpc_1.qnul) {
	goto L9;
    }
    avsub_(a2cmmn_.vnul, &a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.sn[
	    a2cmmn_.is - 1]);
    avsub_(a2cmmn_.vnul, &a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tn[
	    a2cmmn_.is - 1]);
    a2cmmn_.z__[a2cmmn_.is - 1] = -a2cmmn_.z__[a2cmmn_.is - 1];
L9:
    ajundd_();
    adyndp_(&ab[4], &c__6, &c_b17);
    accurv_(&a2cmmn_.is, &a2cmmn_.iis, &a2cmmn_.sp[a2cmmn_.is - 1], &
	    a2cmmn_.spl[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1]);
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] != 0) {
	goto L90;
    } else {
	goto L338;
    }
L90:
    kju1 = a2cmmn_.ju1[a2cmmn_.iis - 1];
    a2cmmn_.ju1[a2cmmn_.iis - 1] = -99;
    au1cmp_();
    a2cmmn_.ju1[a2cmmn_.iis - 1] = kju1;
    if (a2cmmn_.jap != 1) {
	goto L92;
    }
    avdot_(&a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1], &ans)
	    ;
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_.vnul, &a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.u1[
		a2cmmn_.is - 1]);
    }
L92:
    avsto_(&a2cmmn_.u1[a2cmmn_.is - 1], a2cmmn_.oldu1);
    goto L338;
L12:
    avadd_(&a2cmmn_.vt[a2cmmn_.is - 1], a2cmmn_.te, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.th[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, &a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    if (a2cmmn_.iafl[a2cmmn_.iis - 1] != 0) {
	goto L9;
    } else {
	goto L212;
    }
L338:
/* L915: */
L38:
    map = 0;
L712:
    atlnrm_(&a2cmmn_.u1[a2cmmn_.is - 1]);
    adyndp_(&ab[6], &c__6, &c_b17);
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.th[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avadd_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
L28:
    ajundd_();
    if (kk1083_1.k1083 == 1) {
	goto L30;
    }
    avdot_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1], &
	    a2cmmn_.flipck);
    adyndp_(&ab[8], &c__12, &c_b4);
    ans = (doublereal) ((real) (a2cmmn_.jtn[a2cmmn_.iis - 1] - 1)) * 
	    a2cmmn_.flipck;
    if (flipl > ans) {
	goto L28801;
    }
    if (a2cmmn_.mdic != 10 || a2cmmn_.rdrn != a2fpc_1.qnul) {
	goto L28801;
    }
    avsto_(&a2cmmn_.sp[a2cmmn_.is - 1], spibm);
    sibm = a2cmmn_.s[a2cmmn_.is - 1];
    if (flipl > abs(a2cmmn_.flipck)) {
	goto L28801;
    }
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], tnibm);
    avsto_(&a2cmmn_.u1[a2cmmn_.is - 1], u1ibm);
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], snibm);
    flipl = ans;
    avsto_(&a2cmmn_.tp[a2cmmn_.is - 1], tpibm);
    ksega1 = a2cmmn_.itseg[a2cmmn_.iis - 1];
/* ...  IF STARTUP, S<3TAU, USE TIGHTER TEST(.6X9) FOR IAMDCT UP TO 22 */
L28801:
    if (a2cmmn_.istrup != 1) {
	goto L28802;
    }
    if (a2cmmn_.iamdct >= 23) {
	goto L28802;
    }
    if ((d__1 = a2cmmn_.s[a2cmmn_.is - 1], abs(d__1)) >= a2fpc_1.q3p * 
	    a2cmmn_.tau[a2cmmn_.is - 1]) {
	goto L28802;
    }
    if (abs(a2cmmn_.flipck) - a2fpc_1.qp6x9 >= 0.) {
	goto L41;
    } else {
	goto L29;
    }
L28802:
    if (abs(a2cmmn_.flipck) > a2fpc_1.qp4x95) {
	goto L41;
    }
L29:
    ++a2cmmn_.iamdct;
    if ((i__1 = 25 - a2cmmn_.iamdct) < 0) {
	goto L132;
    } else if (i__1 == 0) {
	goto L13111;
    } else {
	goto L32;
    }
L132:
    if (a2cmmn_.jminr <= 0) {
	goto L131;
    } else {
	goto L30;
    }
L30:
    a2cmmn_.jmin = 1;
    if (a2cmmn_.jminr <= 0) {
	goto L31;
    } else {
	goto L48;
    }
L31:
    if (abs(a2cmmn_.flipck) - a2fpc_1.qp995 <= 0.) {
	goto L131;
    } else {
	goto L341;
    }
L341:
    aerr_(&c_n1004);
    goto L41;
L131:
    if (a2cmmn_.istrup != 1) {
	goto L10541;
    }
    if (newmap == 0) {
	goto L10541;
    }
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] != 0) {
	goto L10541;
    }
    if (ksntn != 0) {
	goto L10541;
    }
    ksntn = 1;
    a2cmmn_.iopset[a2cmmn_.iis - 1] = 1;
    goto L28;
L10541:
    if (a2cmmn_.j40 == 1) {
	goto L1311;
    }
    if (a2cmmn_.jtlflg[a2cmmn_.iis - 1] != 1) {
	goto L1311;
    }
    a2cmmn_.j40 = 1;
    a2cmmn_.iamdct = 0;
    goto L32;
/* ... */
L13111:
    avsto_(tpibm, &a2cmmn_.tp[a2cmmn_.is - 1]);
    avsto_(tnibm, &a2cmmn_.tn[a2cmmn_.is - 1]);
    avsto_(u1ibm, &a2cmmn_.u1[a2cmmn_.is - 1]);
    avsto_(snibm, &a2cmmn_.sn[a2cmmn_.is - 1]);
    a2cmmn_.flipck = flipl;
    a2cmmn_.zign = a2fpc_1.q1p;
/* ... */
/* ... */

    avdot_(snibm, tnibm, &ans);
    if ((doublereal) ((real) (a2cmmn_.jtn[a2cmmn_.iis - 1] - 1)) * ans < 
	    a2fpc_1.qnul && map <= 0) {
	goto L710;
    }
/* L11111: */
/* ... */
/* ... */
    amd2_(&iret);
    a2cmmn_.iamdct = 25;
    if (iret == 1) {
	goto L712;
    }
    goto L30;
L32:
    accurv_(&a2cmmn_.is, &a2cmmn_.iis, &a2cmmn_.sp[a2cmmn_.is - 1], &
	    a2cmmn_.spl[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1]);
    adyndp_(&ab[10], &c__6, &c_b17);
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] != 0) {
	goto L91;
    } else {
	goto L38;
    }
L91:
    au1cmp_();
    if (a2cmmn_.ju1[a2cmmn_.iis - 1] != 0) {
	goto L39;
    } else {
	goto L33;
    }
L39:
    goto L38;
L33:
    avdot_(a2cmmn_.oldu1, &a2cmmn_.u1[a2cmmn_.is - 1], &ans);
    if (ans >= a2fpc_1.qnul) {
	goto L39;
    }
/* L34: */
    avsub_(a2cmmn_.vnul, &a2cmmn_.u1[a2cmmn_.is - 1], a2cmmn_.oldu1);
    avsto_(a2cmmn_.oldu1, &a2cmmn_.u1[a2cmmn_.is - 1]);
/* L35: */
    avdot_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snl[a2cmmn_.is - 1], &
	    ans);
    if (ans > a2fpc_1.qp9) {
	goto L39;
    }
    a2cmmn_.iopset[a2cmmn_.iis - 1] = -1;
    adyndp_(&ab[12], &c__6, &c_b17);
    ajundd_();
    a2cmmn_.iopset[a2cmmn_.iis - 1] = 0;
    accurv_(&a2cmmn_.is, &a2cmmn_.iis, &a2cmmn_.sp[a2cmmn_.is - 1], &
	    a2cmmn_.spl[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1]);
    goto L38;
L41:
    if (a2cmmn_.rdrn != 0.) {
	goto L29;
    } else {
	goto L802;
    }
L802:
    if (a2cmmn_.mdic - 10 != 0) {
	goto L29;
    } else {
	goto L803;
    }
L803:
    if ((doublereal) ((real) (a2cmmn_.jtn[a2cmmn_.iis - 1] - 1)) * 
	    a2cmmn_.flipck >= 0.) {
	goto L711;
    } else {
	goto L709;
    }
L709:
    if (map <= 0) {
	goto L710;
    } else {
	goto L7100;
    }
L7100:
    if (a2cmmn_.jminr == 1) {
	goto L7101;
    }
    if (newmap == 1) {
	goto L131;
    }
L12345:
    newmap = 1;
    if (a2cmmn_.j24[a2cmmn_.iis - 1] == 4 && a2cmmn_.jtn[a2cmmn_.iis - 1] 
	    == 0) {
	goto L8000;
    }
    a2cmmn_.jent[a2cmmn_.iis - 1] = 1;
    a2cmmn_.ju1[a2cmmn_.iis - 1] = 1 - a2cmmn_.ju1[a2cmmn_.iis - 1];
    goto L10101;
L7101:
    if (newmap == 0) {
	goto L12345;
    }
    a2cmmn_.jmin = 1;
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] == 0) {
	a2cmmn_.th[a2cmmn_.is - 1] = saveth;
    }
    return 0;
L710:
    if (newmap == 1) {
	a2cmmn_.zign = -a2fpc_1.q1p;
    }
    map = 1;
    a2cmmn_.flipck = a2fpc_1.qnul;
    flipl = a2fpc_1.qnul;
    avsub_(a2cmmn_.vnul, &a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.u1[
	    a2cmmn_.is - 1]);
    avsub_(a2cmmn_.vnul, a2cmmn_.oldu1, a2cmmn_.oldu1);
    goto L712;
L711:
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 1) {
	goto L7111;
    }
    if (a2cmmn_.flipck > a2fpc_1.qnul) {
	goto L7111;
    }
    if (jtnmap == 1) {
	aerr_(&c__1009);
    }
/*  CALL AERR(-1008) IS DELETED.  3-6-68 */
    jtnmap = 1;
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tnl[a2cmmn_.is - 1]);
    a2cmmn_.flipck = a2fpc_1.qnul;
    flipl = a2fpc_1.qnul;
    goto L9;
L7111:
    a2cmmn_.jmin = 0;
    if (a2cmmn_.ipl[a2cmmn_.iis - 1] <= 0) {
	goto L42;
    } else {
	goto L346;
    }
L42:
    a2cmmn_.temp[0] = a2cmmn_.tau[a2cmmn_.is - 1] - a2cmmn_.eps8[
	    a2cmmn_.is - 1];
    if (a2cmmn_.rc[a2cmmn_.is - 1] <= 0.) {
	goto L49;
    } else {
	goto L43;
    }
L49:
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 0) {
	goto L45;
    } else {
	goto L44;
    }
L43:
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 0) {
	goto L44;
    } else {
	goto L45;
    }
L44:
    a2cmmn_.temp[0] = a2cmmn_.eps8[a2cmmn_.is - 1];
L45:
    a2cmmn_.s[a2cmmn_.is - 1] = a2cmmn_.s[a2cmmn_.is - 1] - a2cmmn_.tau2[
	    a2cmmn_.is - 1] - a2cmmn_.temp[0];
    adyndp_(&ab[14], &c__6, &c_b17);
L346:
    if (a2cmmn_.ifrl == 0) {
	goto L347;
    }
    if (a2cmmn_.iamdct >= 21) {
	goto L347;
    }
    atltst_(&itlret);
    if (itlret != 0) {
	goto L29;
    }
L347:
    if (a2cmmn_.jent[a2cmmn_.iis - 1] != 0) {
	goto L215;
    } else {
	goto L46;
    }
L215:
    avsto_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.tpk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.sp[a2cmmn_.is - 1], &a2cmmn_.spk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snk[a2cmmn_.is - 1]);
    a2cmmn_.jent[a2cmmn_.iis - 1] = 0;
    if (a2cmmn_.is > a2cmmn_.ids) {
	goto L46;
    }
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tnk[a2cmmn_.is - 1]);
L46:
    adyndp_(&ab[16], &c__6, &c_b17);
    if (a2cmmn_.iopset[a2cmmn_.iis - 1] >= 0) {
	goto L51;
    } else {
	goto L47;
    }
L47:
    a2cmmn_.iopset[a2cmmn_.iis - 1] = 0;
L51:
    avsub_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.te, &a2cmmn_.vt[
	    a2cmmn_.is - 1]);
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.th[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avsub_(&a2cmmn_.vt[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.vt[
	    a2cmmn_.is - 1]);
L48:
    adyndp_(&ab[18], &c__4, &c_b4);
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] == 0) {
	a2cmmn_.th[a2cmmn_.is - 1] = saveth;
    }
    return 0;
L202:
    a2cmmn_.ic = a2cmmn_.ipontr[a2cmmn_.iis - 1] + 4;
/* L203: */
    avsto_(&a2cmmn_.cansto[a2cmmn_.ic - 1], &a2cmmn_.tn[a2cmmn_.is - 1]);
    avdot_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.cansto[a2cmmn_.ic - 1], &
	    ans);
    if (a2cmmn_.past[a2cmmn_.is - 1] * (a2cmmn_.cansto[a2cmmn_.ic + 2] - 
	    ans) < a2fpc_1.qnul) {
	goto L205;
    }
/* L302: */
    a2cmmn_.spast[a2cmmn_.is - 1] = a2fpc_1.q1p;
L204:
    if (a2cmmn_.itlon[a2cmmn_.iis - 1] != 0) {
	goto L501;
    } else {
	goto L502;
    }
L502:
    avsto_(a2cmmn_.te, &a2cmmn_.tp[a2cmmn_.is - 1]);
    goto L305;
L501:
    if (a2cmmn_.ips - a2cmmn_.is != 0) {
	goto L303;
    } else {
	goto L304;
    }
L304:
    a2cmmn_.temp[0] = a2fpc_1.qp5 * a2cmmn_.cutdat[6];
    ans = min(a2cmmn_.temp[0],a2cmmn_.cutdat[0]);
    if (ktmadj == 0) {
	ans = a2cmmn_.temp[0];
    }
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &ans, a2cmmn_.vtem);
    avadd_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    adyndp_(&ab[20], &c__6, &c_b17);
    goto L305;
L303:
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.cutr[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, &a2cmmn_.cuth[a2cmmn_.is - 1], a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, a2cmmn_.te, &a2cmmn_.tp[a2cmmn_.is - 1]);

L305:
    avdot_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.cansto[a2cmmn_.ic - 1], &
	    ans);
    a2cmmn_.s[a2cmmn_.is - 1] = a2cmmn_.spast[a2cmmn_.is - 1] * (
	    a2cmmn_.cansto[a2cmmn_.ic + 2] - ans);
    adyndp_(&ab[22], &c__6, &c_b17);
    goto L206;
L205:
    avsub_(a2cmmn_.vnul, &a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tn[
	    a2cmmn_.is - 1]);
    a2cmmn_.spast[a2cmmn_.is - 1] = -a2fpc_1.q1p;
    goto L204;
L206:
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 0) {
	goto L207;
    } else {
	goto L208;
    }
L207:
    a2cmmn_.z__[a2cmmn_.is - 1] = a2cmmn_.spast[a2cmmn_.is - 1];
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.u1[a2cmmn_.is - 1]);
    goto L209;
L208:
    a2cmmn_.z__[a2cmmn_.is - 1] = -a2cmmn_.spast[a2cmmn_.is - 1];
    avsub_(a2cmmn_.vnul, &a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.sn[
	    a2cmmn_.is - 1]);
L209:
    a2cmmn_.rc[a2cmmn_.is - 1] = a2cmmn_.rc1;
    adyndp_(&ab[24], &c__6, &c_b17);
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snl[a2cmmn_.is - 1]);
    a2cmmn_.isigcr[a2cmmn_.iis - 1] = -1;
/* L210: */
    a2cmmn_.s[a2cmmn_.is - 1] -= a2cmmn_.th[a2cmmn_.is - 1];
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.th[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avadd_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
L213:
//find surface point give tool point, directed distance, and tool normal
    a2cmmn_.sp[a2cmmn_.is - 1] = a2cmmn_.tp[a2cmmn_.is - 1] + a2cmmn_.s[
	    a2cmmn_.is - 1] * a2cmmn_.tn[a2cmmn_.is - 1];
    a2cmmn_.sp[a2cmmn_.is] = a2cmmn_.tp[a2cmmn_.is] + a2cmmn_.s[
	    a2cmmn_.is - 1] * a2cmmn_.tn[a2cmmn_.is];
    a2cmmn_.sp[a2cmmn_.is + 1] = a2cmmn_.tp[a2cmmn_.is + 1] + a2cmmn_.s[
	    a2cmmn_.is - 1] * a2cmmn_.tn[a2cmmn_.is + 1];
    a2cmmn_.cc[a2cmmn_.is - 1] = a2cmmn_.sp[a2cmmn_.is - 1] - a2cmmn_.rc[
	    a2cmmn_.is - 1] * a2cmmn_.sn[a2cmmn_.is - 1];
    a2cmmn_.cc[a2cmmn_.is] = a2cmmn_.sp[a2cmmn_.is] - a2cmmn_.rc[
	    a2cmmn_.is - 1] * a2cmmn_.sn[a2cmmn_.is];
    adyndp_(&ab[26], &c__6, &c_b17);
    a2cmmn_.cc[a2cmmn_.is + 1] = a2cmmn_.sp[a2cmmn_.is + 1] - a2cmmn_.rc[
	    a2cmmn_.is - 1] * a2cmmn_.sn[a2cmmn_.is + 1];
    if (a2cmmn_.jent[a2cmmn_.iis - 1] != 0) {
	goto L211;
    } else {
	goto L46;
    }
L211:
    avsto_(&a2cmmn_.sp[a2cmmn_.is - 1], &a2cmmn_.spl[a2cmmn_.is - 1]);
    goto L215;
L212:
    a2cmmn_.ic = a2cmmn_.ipontr[a2cmmn_.iis - 1] + 4;
    if (a2cmmn_.jtn[a2cmmn_.iis - 1] != 0) {
	goto L214;
    } else {
	goto L307;
    }

L307:
    avdot_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.cansto[a2cmmn_.ic - 1], &
	    ans);
    a2cmmn_.s[a2cmmn_.is - 1] = a2cmmn_.spast[a2cmmn_.is - 1] * (
	    a2cmmn_.cansto[a2cmmn_.ic + 2] - ans);

    avsto_(&a2cmmn_.sp[a2cmmn_.is - 1], &a2cmmn_.spl[a2cmmn_.is - 1]);
    adyndp_(&ab[28], &c__6, &c_b17);
    goto L213;
L214:
    avdot_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.u1[a2cmmn_.is - 1], &ans)
	    ;
    if (ans < a2fpc_1.qnul) {
	goto L309;
    }
/* L308: */
    avsto_(&a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1]);
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.th[a2cmmn_.is - 1], 
	    a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, &a2cmmn_.vt[a2cmmn_.is - 1], a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, a2cmmn_.te, &a2cmmn_.tp[a2cmmn_.is - 1]);
    goto L307;
L309:
    avsub_(a2cmmn_.vnul, &a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.tn[
	    a2cmmn_.is - 1]);
    a2cmmn_.spast[a2cmmn_.is - 1] = -a2cmmn_.spast[a2cmmn_.is - 1];
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snl[a2cmmn_.is - 1]);
    avsub_(a2cmmn_.vnul, &a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.sn[
	    a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.u1[a2cmmn_.is - 1]);
    a2cmmn_.z__[a2cmmn_.is - 1] = -a2cmmn_.z__[a2cmmn_.is - 1];
    adyndp_(&ab[30], &c__6, &c_b17);
    qq = a2cmmn_.cutr[a2cmmn_.is - 1] + a2cmmn_.th[a2cmmn_.is - 1];
    avmult_(&a2cmmn_.tn[a2cmmn_.is - 1], &qq, a2cmmn_.vtem);
    avadd_(a2cmmn_.te, &a2cmmn_.cuth[a2cmmn_.is - 1], &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    avadd_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.tp[
	    a2cmmn_.is - 1]);
    adyndp_(&ab[32], &c__6, &c_b17);
    goto L307;
L6000:
    ++kount;
    if (kount > 10) {
	goto L6005;
    }
    a2cmmn_.z__[a2cmmn_.is - 1] = a2fpc_1.q1p;
    avadd_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.sn[a2cmmn_.is - 1], &
	    a2cmmn_.tn[a2cmmn_.is - 1]);
    avnorm_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tn[a2cmmn_.is - 1], &
	    a2cmmn_.ier);
    goto L251;
L1311:
    if (a2cmmn_.istrup != 1 || ktmadj != 0) {
	goto L1312;
    }
    ktmadj = 1;
    goto L22222;
L8000:
    a2cmmn_.z__[a2cmmn_.is - 1] = -a2cmmn_.z__[a2cmmn_.is - 1];
    a2cmmn_.iamdct = 0;
    avsub_(a2cmmn_.vnul, &a2cmmn_.u1[a2cmmn_.is - 1], &a2cmmn_.u1[
	    a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.u1[a2cmmn_.is - 1], a2cmmn_.oldu1);
    goto L38;
L1312:
    avdot_(tnibm, snibm, &a2cmmn_.flipck);
    if (flipl == -a2fpc_1.q3p || abs(a2cmmn_.flipck) < a2fpc_1.qp995) {
	aerr_(&c__1002);
    }
    if (abs(a2cmmn_.flipck) < .9995) {
	aerr_(&c_n1004);
    }
    avsto_(tpibm, &a2cmmn_.tp[a2cmmn_.is - 1]);
    avsto_(tnibm, &a2cmmn_.tn[a2cmmn_.is - 1]);
    avsto_(spibm, &a2cmmn_.sp[a2cmmn_.is - 1]);
    avsto_(snibm, &a2cmmn_.sn[a2cmmn_.is - 1]);
    avsto_(u1ibm, &a2cmmn_.u1[a2cmmn_.is - 1]);
    a2cmmn_.s[a2cmmn_.is - 1] = sibm;
    goto L711;
} /* amind_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


