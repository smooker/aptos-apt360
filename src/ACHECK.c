/* ACHECK.f -- translated by f2c (version 20000121).
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
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

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

static integer c__3 = 3;
static integer c_b3 = 111111;
static integer c__5 = 5;
static integer c_b10 = 110000;
static integer c_n822 = -822;
static integer c_b51 = 111100;
static integer c_n821 = -821;

/* Subroutine */ int acheck_()
{
    /* Initialized data */

    static struct {
	char e_1[176];
	real e_2;
	} equiv_13 = { {'A', 'C', 'H', 'E', 'C', 'K', 'T', 'P', 'A', 'C', 'H',
		 'E', 'C', 'K', '0', '1', 'A', 'C', 'H', 'E', 'C', 'K', '0', 
		'2', 'A', 'C', 'H', 'E', 'C', 'K', '0', '3', 'A', 'C', 'H', 
		'E', 'C', 'K', '0', '4', 'A', 'C', 'H', 'E', 'C', 'K', '0', 
		'5', 'A', 'C', 'H', 'E', 'C', 'K', '0', '6', 'A', 'C', 'H', 
		'E', 'C', 'K', '0', '7', 'A', 'C', 'H', 'E', 'C', 'K', '0', 
		'8', 'A', 'C', 'H', 'E', 'C', 'K', 'E', 'X', 'A', 'C', 'H', 
		'E', 'C', 'K', '0', '9', 'A', 'C', 'H', 'E', 'C', 'K', '1', 
		'0', 'A', 'C', 'H', 'E', 'C', 'K', '1', '1', 'A', 'C', 'H', 
		'E', 'C', 'K', '1', '2', 'A', 'C', 'H', 'E', 'C', 'K', '1', 
		'3', 'A', 'C', 'H', 'E', 'C', 'K', '1', '4', 'A', 'C', 'H', 
		'E', 'C', 'K', '1', '5', 'A', 'C', 'H', 'E', 'C', 'K', '1', 
		'6', 'A', 'C', 'H', 'E', 'C', 'K', '1', '7', 'A', 'C', 'H', 
		'E', 'C', 'K', '1', '8', 'A', 'C', 'H', 'E', 'C', 'K', '1', 
		'9', 'A', 'C', 'H', 'E', 'C', 'K', '2', '0'}, (float)0. };

#define ab ((real *)&equiv_13)


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    static integer jwr, kat;
    static doublereal ans;
    extern /* Subroutine */ int aerr_(), avadd_();
    static integer kiit, kiis;
    static doublereal ssav;
    extern /* Subroutine */ int amind_();
    static doublereal tesav[3], vtsav[3];
    extern /* Subroutine */ int avsto_(), avsub_(), avdot_(), addst_(), 
	    acplan_(), avleng_();
    static doublereal tisave[3];
    extern /* Subroutine */ int adyndp_(), avmult_(), avnorm_();
    static integer irejct;
    extern /* Subroutine */ int ddlimt_(), avcros_();
    static integer itlsav;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/* ... */
/* ... */
/* ***ACHECK TP*** */
    adyndp_(ab, &c__3, &c_b3);
/* 	PAST,or not? */
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 >= 0) {
	goto L401;
    } else {
	goto L400;
    }
/* 	multiply Tool aiming direction by the constant PAST(IS) */
/* 	store in TN(IS) */
L400:
    avmult_(a2cmmn_1.ti, &a2cmmn_1.past[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
L401:
    if ((i__1 = a2cmmn_1.j20[a2cmmn_1.iis - 1] - 1) < 0) {
	goto L1;
    } else if (i__1 == 0) {
	goto L8;
    } else {
	goto L3;
    }
L1:
    jwr = 0;
    avsto_(a2cmmn_1.ti, tisave);
/* ***ACHECK 01*** */
    adyndp_(&ab[2], &c__5, &c_b10);
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2fpc_1.q1pe6;
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j21[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j22[a2cmmn_1.iis - 1] = 0;
/* L2: */
    a2cmmn_1.iopset[a2cmmn_1.iis - 1] = 0;
    if (a2cmmn_1.icscnt > 1) {
	goto L333;
    }
/* ... IF(PLANE PS,DS) AND (TO,CS), AND MOTION, LOOK ONLY + */
    if (a2cmmn_1.istrup == 1) {
	goto L333;
    }
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] == a2fpc_1.qnul) {
	goto L333;
    }
    if (a2cmmn_1.ipdpl == 1 && a2cmmn_1.isftyp[a2cmmn_1.iis - 1] == 1) {
	a2cmmn_1.iopset[a2cmmn_1.iis - 1] = 1;
    }
/* ... */
L333:
/* ***ACHECK 02*** */
    adyndp_(&ab[4], &c__5, &c_b10);
    a2cmmn_1.jtn[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.ju1[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.jiops[a2cmmn_1.iis - 1] = 0;
/* ... */
/* ... */
    goto L9;
L3:
    if (abs(a2cmmn_1.ti[0]) >= abs(a2cmmn_1.ti[1])) {
	goto L9999;
    }
    if (abs(a2cmmn_1.ti[2]) >= abs(a2cmmn_1.ti[1])) {
	goto L9998;
    }
    kat = 2;
    goto L9996;
L9999:
    if (abs(a2cmmn_1.ti[0]) >= abs(a2cmmn_1.ti[2])) {
	goto L9997;
    }
L9998:
    kat = 3;
    goto L9996;
L9997:
    kat = 1;
L9996:
    avsto_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    if (a2cmmn_1.ti[kat - 1] >= a2fpc_1.qnul) {
	goto L9995;
    }
    if (a2cmmn_1.vtem[kat - 1] >= a2cmmn_1.te[kat - 1]) {
	goto L7;
    }
    goto L9994;
L9995:
    if (a2cmmn_1.vtem[kat - 1] <= a2cmmn_1.te[kat - 1]) {
	goto L7;
    }
L9994:
    avsub_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.tek, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.tik, &ans);
/* ***ACHECK 03*** */
    adyndp_(&ab[6], &c__5, &c_b10);
    if (ans > a2cmmn_1.eps1[a2cmmn_1.is - 1]) {
	goto L66;
    }
/* .....................................ERROR -822 */
/* L4: */
    aerr_(&c_n822);
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q3p * a2cmmn_1.dp;
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.qnul;
/* ***ACHECK 04*** */
    adyndp_(&ab[8], &c__5, &c_b10);
    goto L11;
/* ... */
/* ... */
L66:
    a2cmmn_1.j21[a2cmmn_1.iis - 1] = 0;
    avsub_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.tek, a2cmmn_1.cmove);
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.temp);
    avleng_(a2cmmn_1.cmove, &a2cmmn_1.csd[a2cmmn_1.is - 1]);
    avnorm_(a2cmmn_1.cmove, a2cmmn_1.tem, &a2cmmn_1.ier);
    avleng_(a2cmmn_1.temp, a2cmmn_1.vtem);
    avnorm_(a2cmmn_1.temp, a2cmmn_1.temp, &a2cmmn_1.ier);
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (a2cmmn_1.csd[a2cmmn_1.is - 1] - 
	    a2cmmn_1.vtem[0]) * (a2cmmn_1.dpi / a2cmmn_1.zl) * a2fpc_1.q1p1;
/* ***ACHECK 05*** */
    adyndp_(&ab[10], &c__5, &c_b10);
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2cmmn_1.eps1[a2cmmn_1.is - 1] <= 0.) 
	    {
	goto L7;
    } else {
	goto L16;
    }
L7:
    avsto_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.te);
    goto L18;
/* ... */
/* ...................................................SUBS ENTRY........ */
L8:
    a2cmmn_1.s[a2cmmn_1.is - 1] -= a2cmmn_1.dp;
/* ***ACHECK 06*** */
    adyndp_(&ab[12], &c__5, &c_b10);
    if (a2cmmn_1.j21[a2cmmn_1.iis - 1] == 1) {
	goto L1;
    }
    avdot_(a2cmmn_1.ti, tisave, &ans);
    if (abs(ans) <= a2fpc_1.qp866) {
	goto L9;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 1 && a2cmmn_1.itlon[a2cmmn_1.iis - 
	    1] == 0 && a2cmmn_1.multax == 2) {
	goto L9;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] == 4 && a2cmmn_1.s[a2cmmn_1.is - 1] 
	    < a2fpc_1.q2p5 * a2cmmn_1.dp) {
	goto L9;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] == 4 && (a2cmmn_1.j24[a2cmmn_1.iis 
	    - 1] != 7 || a2cmmn_1.j24[a2cmmn_1.iis - 1] != 8)) {
	goto L9;
    }
    if (a2cmmn_1.j24[a2cmmn_1.iips - 1] == 3) {
	goto L9;
    }
    if (a2cmmn_1.s[a2cmmn_1.is - 1] - a2fpc_1.q2p * a2cmmn_1.dp >= 0.) {
	goto L11;
    } else {
	goto L9;
    }
/*                                      NORMAL DIST CALC TO CS */
L9:
    a2cmmn_1.jminr = 1;
    a2cmmn_1.jent[a2cmmn_1.iis - 1] = 1;
    irejct = 0;
/* ***ACHECK 07*** */
    adyndp_(&ab[14], &c__5, &c_b10);
/* ... */
L99:
    amind_();
/* ... */
/* ***ACHECK 08*** */
    adyndp_(&ab[16], &c__5, &c_b10);
    a2cmmn_1.jminr = 0;
    if (a2cmmn_1.jmin != 0) {
	goto L10;
    }
    if (a2cmmn_1.multax != 2) {
	goto L1269;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] != 1) {
	goto L1269;
    }
    if (a2cmmn_1.itlon[a2cmmn_1.iis - 1] != 0) {
	goto L1269;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) < a2fpc_1.q2p * 
	    a2cmmn_1.dp) {
	goto L18;
    }
L1269:
    if (a2cmmn_1.jmin != 0) {
	goto L10;
    } else {
	goto L19;
    }
L10:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.qnul;
L11:
    a2cmmn_1.j21[a2cmmn_1.iis - 1] = 0;
L12:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2cmmn_1.eps1[a2cmmn_1.is - 1] >= 0.) 
	    {
	goto L15;
    } else {
	goto L13;
    }
L13:
    if (a2cmmn_1.istrup <= 0) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.q2p * a2cmmn_1.dpmx1[a2cmmn_1.is 
	    - 1];
L15:
    if (a2cmmn_1.stck[a2cmmn_1.is - 1] <= a2fpc_1.qnul) {
	goto L18;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] >= 4 && a2cmmn_1.csd[a2cmmn_1.is - 
	    1] <= a2cmmn_1.dp) {
	goto L18;
    }
L16:
    a2cmmn_1.jckr = 0;
/* ... */
L17:
/* ***ACHECK EX*** */
    adyndp_(&ab[18], &c__3, &c_b51);
    return 0;
/* ********************************************************************* */
L18:
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 1;
/* ***ACHECK 09*** */
    adyndp_(&ab[20], &c__5, &c_b10);
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.plnd1[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.notan[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.jckr = 1;
    goto L17;
/* ... */
L19:
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 >= 0) {
	goto L22;
    } else {
	goto L190;
    }
L190:
    if (a2cmmn_1.j23[a2cmmn_1.iis - 1] != 0) {
	goto L20;
    } else {
	goto L21;
    }
L20:
    a2cmmn_1.stck1[a2cmmn_1.is - 1] = a2cmmn_1.z__[a2cmmn_1.is - 1] * 
	    a2cmmn_1.s[a2cmmn_1.is - 1];
    a2cmmn_1.j23[a2cmmn_1.iis - 1] = 0;
    if (irejct != 0) {
	goto L21;
    }
    goto L22;
/* ... */
L21:
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2cmmn_1.stck1[a2cmmn_1.is - 1] * 
	    a2cmmn_1.z__[a2cmmn_1.is - 1] * a2cmmn_1.s[a2cmmn_1.is - 1];
L22:
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ti, &a2cmmn_1.cos1[
	    a2cmmn_1.is - 1]);
/* ... */
/* ***ACHECK 10*** */
    adyndp_(&ab[22], &c__5, &c_b10);
    if ((i__1 = a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 2) < 0) {
	goto L23;
    } else if (i__1 == 0) {
	goto L30;
    } else {
	goto L39;
    }
L23:
    if (a2cmmn_1.cos1[a2cmmn_1.is - 1] >= 0.) {
	goto L25;
    } else {
	goto L24;
    }
L24:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    a2cmmn_1.j23[a2cmmn_1.iis - 1] = 1;
    ++irejct;
    if (irejct > 6) {
	goto L11;
    }
/* ... */
/* ***ACHECK 11*** */
    adyndp_(&ab[24], &c__5, &c_b10);
    goto L99;
/* ... */
L25:
    if (a2cmmn_1.eps6[a2cmmn_1.is - 1] - a2cmmn_1.s[a2cmmn_1.is - 1] <= 0.) {
	goto L26;
    } else {
	goto L32;
    }
L26:
    if (a2cmmn_1.cos1[a2cmmn_1.is - 1] != 0.) {
	goto L27;
    } else {
	goto L28;
    }
L27:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1] / 
	    a2cmmn_1.cos1[a2cmmn_1.is - 1], abs(d__1));
/* ***ACHECK 12*** */
    adyndp_(&ab[26], &c__5, &c_b10);
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 1) {
	goto L29;
    }
    if (a2cmmn_1.ipdpl == 1 && a2cmmn_1.s[a2cmmn_1.is - 1] > a2fpc_1.qnul) {
	a2cmmn_1.j21[a2cmmn_1.iis - 1] = 0;
    }
    goto L29;
/* ... */
L28:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(
	    d__1)) + a2cmmn_1.tau[a2cmmn_1.is - 1];
L29:
    if (a2cmmn_1.ipdpl == 1 && a2cmmn_1.j21[a2cmmn_1.iis - 1] == 0) {
	goto L18;
    }
    if (a2cmmn_1.dp - a2cmmn_1.csd[a2cmmn_1.is - 1] >= 0.) {
	goto L201;
    } else {
	goto L11;
    }
L201:
    if (a2cmmn_1.j50[a2cmmn_1.iis - 1] >= 0) {
	goto L18;
    } else {
	goto L202;
    }
L202:
    if (a2cmmn_1.tau[a2cmmn_1.is - 1] - a2cmmn_1.csd[a2cmmn_1.is - 1] >= 0.) {
	goto L18;
    } else {
	goto L11;
    }
L30:
    if (a2cmmn_1.cos1[a2cmmn_1.is - 1] <= 0.) {
	goto L31;
    } else {
	goto L24;
    }
L31:
    if (a2cmmn_1.eps6[a2cmmn_1.is - 1] - a2cmmn_1.s[a2cmmn_1.is - 1] <= 0.) {
	goto L32;
    } else {
	goto L26;
    }
L32:
    if (a2cmmn_1.j21[a2cmmn_1.iis - 1] <= 0) {
	goto L301;
    } else {
	goto L33;
    }
L301:
    if (a2cmmn_1.ipdpl <= 0) {
	goto L15;
    } else {
	goto L18;
    }
L33:
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.temp);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.temp[3]);
    avmult_(a2cmmn_1.ti, &a2cmmn_1.tau[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.sp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 2 && a2cmmn_1.icscnt <= 1) {
	avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    }
    avsto_(a2cmmn_1.ti, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.temp[6] = a2cmmn_1.s[a2cmmn_1.is - 1];
/* ***ACHECK 13*** */
    adyndp_(&ab[28], &c__5, &c_b10);
    if (a2cmmn_1.limfl[a2cmmn_1.iis - 1] != 0) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    ddlimt_();
    goto L36;
/* ... */
L35:
    addst_();
L36:
    avsto_(a2cmmn_1.temp, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.temp[3], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    if (a2cmmn_1.ier != 0) {
	goto L38;
    } else {
	goto L55;
    }
L38:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.s[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(
	    d__1));
    a2cmmn_1.j23[a2cmmn_1.iis - 1] = 1;
    goto L12;
/* ... */
L39:
    if (3 - a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 0) {
	goto L40;
    } else {
	goto L23;
    }
L40:
    a2cmmn_1.cptst[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.cplfl[a2cmmn_1.is - 1] = a2fpc_1.qnul;
/* ... */
/* ***ACHECK 14*** */
    adyndp_(&ab[30], &c__5, &c_b10);
/* ... */
    acplan_();
/* ... */
/* ***ACHECK 15*** */
    adyndp_(&ab[32], &c__5, &c_b10);
    a2cmmn_1.it = a2cmmn_1.it;
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], 
	    abs(d__1));
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] < (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], 
	    abs(d__1))) {
	a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__2 = a2cmmn_1.s[a2cmmn_1.is - 1], 
		abs(d__2));
    }
    if (a2cmmn_1.jcpr != 0) {
	goto L41;
    } else {
	goto L45;
    }
/* ...WARNING MESSAGE(-821) */
L41:
    aerr_(&c_n821);
    goto L11;
L45:
    avdot_(a2cmmn_1.ta, a2cmmn_1.ez, &ans);
    if (abs(ans) < a2fpc_1.qp4x95) {
	goto L321;
    }
    if (a2cmmn_1.icscnt <= 1) {
	goto L321;
    }
    if (a2cmmn_1.j24[a2cmmn_1.iit - 1] != 2 || a2cmmn_1.j24[a2cmmn_1.iis - 1] 
	    != 2) {
	goto L321;
    }
    kiit = a2cmmn_1.ipontr[a2cmmn_1.iit - 1];
    kiis = a2cmmn_1.ipontr[a2cmmn_1.iis - 1];
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[kiit + 6], &ans);
    if (abs(ans) < a2fpc_1.qp4x95) {
	goto L321;
    }
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[kiis + 6], &ans);
    if (abs(ans) < a2fpc_1.qp4x95) {
	goto L321;
    }
    avsub_(&a2cmmn_1.cansto[kiis + 3], &a2cmmn_1.cansto[kiit + 3], 
	    a2cmmn_1.vtem);
    avcros_(a2cmmn_1.ta, a2cmmn_1.vtem, a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L321;
    }
    a2cmmn_1.vtem[2] = a2cmmn_1.vtem[0] * a2cmmn_1.cansto[kiit + 3] + 
	    a2cmmn_1.vtem[1] * a2cmmn_1.cansto[kiit + 4];
    ans = a2cmmn_1.vtem[0] * a2cmmn_1.te[0] + a2cmmn_1.vtem[1] * a2cmmn_1.te[
	    1] - a2cmmn_1.vtem[2];
    a2cmmn_1.csd[a2cmmn_1.is - 1] = abs(ans);
L321:
/* ...USE SP OF THE TANGENT SURFACE TO COMPUTE STCKN */
    if (a2cmmn_1.ipdpl == 1) {
	goto L18;
    }
/* ... */
    avsto_(a2cmmn_1.te, tesav);
    itlsav = a2cmmn_1.itlon[a2cmmn_1.iis - 1];
    a2cmmn_1.itlon[a2cmmn_1.iis - 1] = 0;
    avsto_(&a2cmmn_1.sp[a2cmmn_1.it - 1], a2cmmn_1.te);
    ssav = a2cmmn_1.s[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.vt[a2cmmn_1.is - 1], vtsav);
    a2cmmn_1.jent[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.jminr = 1;
/* ... */
    amind_();
/* ... */
/* ***ACHECK 16*** */
    adyndp_(&ab[34], &c__5, &c_b10);
    a2cmmn_1.jminr = 0;
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.ti, &a2cmmn_1.cos1[
	    a2cmmn_1.is - 1]);
    a2cmmn_1.stckn[a2cmmn_1.is - 1] = a2cmmn_1.s[a2cmmn_1.is - 1] * 
	    a2cmmn_1.cos1[a2cmmn_1.is - 1];
    a2cmmn_1.itlon[a2cmmn_1.iis - 1] = itlsav;
    avsto_(vtsav, &a2cmmn_1.vt[a2cmmn_1.is - 1]);
    avsto_(tesav, a2cmmn_1.te);
    ans = a2cmmn_1.s[a2cmmn_1.is - 1];
    a2cmmn_1.s[a2cmmn_1.is - 1] = ssav;
    ssav = ans;
    if (a2cmmn_1.jmin != 0) {
	goto L11;
    }
/*      SEE IF FIRST ENTRY OR IF CS NOT FORWAED YET */
    if (a2cmmn_1.j22[a2cmmn_1.iis - 1] == 0) {
	goto L50;
    }
/* ... */
/*      NOT FIRST ENTRY */
L4321:
/* ***ACHECK 17*** */
    adyndp_(&ab[36], &c__5, &c_b10);
    if (a2cmmn_1.stckn[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	goto L18;
    }
    if (abs(ssav) < a2cmmn_1.dp) {
	goto L18;
    }
    if ((d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1)) < a2fpc_1.q2p * 
	    a2cmmn_1.dp) {
	goto L18;
    }
    avdot_(a2cmmn_1.ta, &a2cmmn_1.plnv[a2cmmn_1.is - 1], &ans);
    if (abs(ans) < a2fpc_1.qp4x05) {
	goto L11;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) < a2fpc_1.q2p * 
	    a2cmmn_1.dp) {
	goto L18;
    }
    goto L11;
/* ... */
L50:
/*       FIRST ENTRY OR CS NOT AHEAD YET */
/* ***ACHECK 18*** */
    adyndp_(&ab[38], &c__5, &c_b10);
    if (a2cmmn_1.icscnt > 1 || a2cmmn_1.ifar[a2cmmn_1.iis - 1] > 1) {
	goto L1234;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iit - 1] != 1) {
	goto L1234;
    }
    if (a2cmmn_1.plnd[a2cmmn_1.is - 1] >= a2fpc_1.q2p * a2cmmn_1.dp) {
	goto L1234;
    }
    a2cmmn_1.stck2[a2cmmn_1.is - 1] = a2cmmn_1.stckn[a2cmmn_1.is - 1];
    a2cmmn_1.j22[a2cmmn_1.iis - 1] = 1;
    goto L4321;
L1234:
    if (abs(ssav) < a2fpc_1.qp001) {
	goto L11;
    }
    if ((d__1 = a2cmmn_1.cos1[a2cmmn_1.is - 1], abs(d__1)) < a2fpc_1.qp001) {
	goto L11;
    }
    if (abs(ssav) < (d__1 = a2cmmn_1.th[a2cmmn_1.is - 1], abs(d__1))) {
	goto L56;
    }
    if (a2cmmn_1.stckn[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	goto L11;
    }
L56:
    a2cmmn_1.stck2[a2cmmn_1.is - 1] = a2cmmn_1.stckn[a2cmmn_1.is - 1];
    a2cmmn_1.j22[a2cmmn_1.iis - 1] = 1;
    goto L11;
/* ... */
L52:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q2p * a2cmmn_1.dp >= 0.) {
	goto L12;
    } else {
	goto L53;
    }
L53:
    avmult_(a2cmmn_1.ti, &ans, a2cmmn_1.cmove);
    if (ans < a2cmmn_1.csd[a2cmmn_1.is - 1]) {
	a2cmmn_1.csd[a2cmmn_1.is - 1] -= ans;
    }
/* ... WHEN PLANE (PS,DS), CSD = .9*S----S IS DIST FROM INITIAL SP TO */
/* ... CS IN DIRECTION OF TI */
    if (a2cmmn_1.ipdpl == 1) {
	a2cmmn_1.csd[a2cmmn_1.is - 1] = ans;
    }
    avadd_(a2cmmn_1.te, a2cmmn_1.cmove, a2cmmn_1.te);
/* ***ACHECK 19*** */
    adyndp_(&ab[40], &c__5, &c_b10);
    goto L18;
/* ... */
L55:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.temp[6] / a2cmmn_1.cos1[
	    a2cmmn_1.is - 1] + a2cmmn_1.s[a2cmmn_1.is - 1] + a2cmmn_1.tau[
	    a2cmmn_1.is - 1], abs(d__1));
    a2cmmn_1.temp[7] = a2cmmn_1.s[a2cmmn_1.is - 1];
    ans = a2fpc_1.qp9 * a2cmmn_1.s[a2cmmn_1.is - 1];
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q5p * a2cmmn_1.dp >= 0.) {
	goto L102;
    } else {
	goto L101;
    }
L101:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L152;
/* ... */
L102:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q5p * a2cmmn_1.dp;
/* ***ACHECK 20*** */
    adyndp_(&ab[42], &c__5, &c_b10);
L152:
    if (a2cmmn_1.s[a2cmmn_1.is - 1] - abs(a2cmmn_1.temp[6]) >= 0.) {
	goto L52;
    } else {
	goto L153;
    }
L153:
    a2cmmn_1.s[a2cmmn_1.is - 1] = abs(a2cmmn_1.temp[6]);
    goto L52;
} /* acheck_ */

#undef ab


