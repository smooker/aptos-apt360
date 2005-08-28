/* ARLM3.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
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
    integer kttry2;
} atanco_;

#define atanco_1 atanco_

/* Table of constant values */

static integer c__1 = 1;
static integer c_b3 = 111111;
static integer c__2 = 2;
static integer c_b16 = 111100;
static integer c__804 = 804;
static integer c_n805 = -805;
static integer c__802 = 802;
static integer c__803 = 803;
static integer c__801 = 801;

/* Subroutine */ int arlm3_()
{
    /* Initialized data */

    static struct {
	char e_1[160];
	real e_2;
	} equiv_38 = { {'A', 'R', 'L', 'M', '3', ' ', 'T', 'P', 'A', 'R', 'L',
		 'M', '3', ' ', '0', '1', 'A', 'R', 'L', 'M', '3', ' ', '0', 
		'2', 'A', 'R', 'L', 'M', '3', ' ', '0', '3', 'A', 'R', 'L', 
		'M', '3', ' ', '0', '4', 'A', 'R', 'L', 'M', '3', ' ', '0', 
		'5', 'A', 'R', 'L', 'M', '3', ' ', '0', '6', 'A', 'R', 'L', 
		'M', '3', ' ', '0', '7', 'A', 'R', 'L', 'M', '3', ' ', '0', 
		'8', 'A', 'R', 'L', 'M', '3', ' ', '0', '9', 'A', 'R', 'L', 
		'M', '3', ' ', '1', '0', 'A', 'R', 'L', 'M', '3', ' ', '1', 
		'1', 'A', 'R', 'L', 'M', '3', ' ', '1', '2', 'A', 'R', 'L', 
		'M', '3', ' ', '1', '3', 'A', 'R', 'L', 'M', '3', ' ', '1', 
		'4', 'A', 'R', 'L', 'M', '3', ' ', '1', '5', 'A', 'R', 'L', 
		'M', '3', ' ', '1', '6', 'A', 'R', 'L', 'M', '3', ' ', '1', 
		'7', 'A', 'R', 'L', 'M', '3', ' ', '1', '8', 'A', 'R', 'L', 
		'M', '3', ' ', 'E', 'X'}, (float)0. };

#define ab ((real *)&equiv_38)


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, ii, kk, k804, k805;
    static doublereal ds1, ds2, ds3, ds4, ds5, ds6, ps1, ps2, ps3, ps4, ps5, 
	    ps6, tew[3], pstn[3], dstn[3], tae[3];
    static integer ils1, iils1;
    extern /* Subroutine */ int avadd_(), aerr_();
    static doublereal ans;
    static integer isto;
    extern /* Subroutine */ int amind_(), atape_();
    static integer kstop;
    extern /* Subroutine */ int avsto_(), avdot_(), avsub_();
    static doublereal aftr12;
    static integer iisto;
    extern /* Subroutine */ int astos_();
    static integer icsrj1, icsrj2;
    extern /* Subroutine */ int acheck_(), adelta_();
    static integer i3stry;
    extern /* Subroutine */ int aplane_();
    static integer kgotbe;
    extern /* Subroutine */ int acentr_(), adyndp_();
    static integer nogood;
    static doublereal csdsav;
    extern /* Subroutine */ int avmult_();
    static integer isstop;
    extern /* Subroutine */ int avcros_(), avnorm_(), avleng_();
    static integer icsrej;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ... A2CMMN START */
/* ... A2CMMN END */
/* *** */
/* *** */
/* *** */
/* ... */
/* ... */
/*    local vars: */
    isstop = -100;
    kstop = 0;
/* ***ARLM3 TP*** */
    adyndp_(ab, &c__1, &c_b3);
    k805 = 0;
/* ... */
    k804 = 0;
/*      SET IFRL SO DD AND UN ROUTINES WILL CALL PROPER LS ROUTINE */
    a2cmmn_1.icl = 5;
    a2cmmn_1.jbr = 0;
/* ...NOGOOD..MC- WHEN 3 SURF ITER FAILS, THAT ICS IGNORED FOR NEXT TIME */
/* ...THIS IS DONE JUST ONCE */
    nogood = 0;
    if (atanco_1.kttry2 == 1) {
	goto L12;
    }
    i3stry = 0;
    icsrj1 = 0;
    icsrj2 = 0;
    csdsav = a2fpc_1.q130p;
/* ... */
    ils1 = (a2cmmn_1.icscnt + 2) * a2cmmn_1.lsv + 1;
    iils1 = (a2cmmn_1.icscnt + 2) * a2cmmn_1.lisv + 1;
/* ... */
    a2cmmn_1.nw = 0;
    a2cmmn_1.numpt1 = a2cmmn_1.numpts;
/* 	local var */
    kgotbe = 0;
/* ... */
/* 	TE is Tool end. Tek=Tew=te */
/* 	storing old vectors? */
    avsto_(a2cmmn_1.te, a2cmmn_1.tek);
    avsto_(a2cmmn_1.te, tew);
/* 	TA is toolaxis */
    avsto_(a2cmmn_1.ta, a2cmmn_1.tak);
    a2cmmn_1.ipdpl = 0;
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] == 1 && a2cmmn_1.ipl[a2cmmn_1.iids - 
	    1] == 1) {
	a2cmmn_1.ipdpl = 1;
    }
/* ... */
/* 	initialize ...store old tooldirection? */
L2:
    for (i__ = 1; i__ <= 3; ++i__) {
	a2cmmn_1.tik[i__ - 1] = a2cmmn_1.ti[i__ - 1];
	i__1 = ils1;
	i__2 = a2cmmn_1.lsv;
	for (a2cmmn_1.k = a2cmmn_1.ics; i__2 < 0 ? a2cmmn_1.k >= i__1 : 
		a2cmmn_1.k <= i__1; a2cmmn_1.k += i__2) {
	    a2cmmn_1.l = a2cmmn_1.k + i__ - 1;
/* L3: */
	    a2cmmn_1.tn[a2cmmn_1.l - 1] = a2cmmn_1.ti[i__ - 1];
	}
    }
/* ... */
L602:
    a2cmmn_1.j12 = 0;
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
    a2cmmn_1.j10 = 1;
    a2cmmn_1.dp = a2cmmn_1.dpmax;
    i__2 = ils1;
    i__1 = a2cmmn_1.lsv;
    for (i__ = a2cmmn_1.ics; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += 
	    i__1) {
/* L601: */
	a2cmmn_1.dpmx1[i__ - 1] = a2cmmn_1.dpmax;
    }
/* ... */
    i__1 = iils1;
    i__2 = a2cmmn_1.lisv;
    for (i__ = a2cmmn_1.iics; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += 
	    i__2) {
	a2cmmn_1.j20[i__ - 1] = 0;
	a2cmmn_1.j23[i__ - 1] = 1;
	a2cmmn_1.j50[i__ - 1] = -a2cmmn_1.ipdpl;
	a2cmmn_1.j51[i__ - 1] = 0;
	a2cmmn_1.ichkct[i__ - 1] = 0;
	a2cmmn_1.notan[i__ - 1] = 0;
/* L6601: */
    }
/* ... */
/* 	SP-surface point? start pt? */
    avsto_(&a2cmmn_1.sp[a2cmmn_1.ips - 1], &a2cmmn_1.sp[500]);
    avsto_(&a2cmmn_1.sp[a2cmmn_1.ids - 1], &a2cmmn_1.sp[503]);
    if (a2cmmn_1.ipdpl != 0) {
	goto L207;
    } else {
	goto L203;
    }
/* ... */
L207:
    avsto_(&a2cmmn_1.sp[500], &a2cmmn_1.sp[a2cmmn_1.ips - 1]);
    avsto_(&a2cmmn_1.sp[503], &a2cmmn_1.sp[a2cmmn_1.ids - 1]);
    avsto_(a2cmmn_1.tak, a2cmmn_1.ta);
/* ... */
L5:
    if (a2cmmn_1.ipdpl == 1 && a2cmmn_1.ichkct[a2cmmn_1.iis - 1] == 1) {
	goto L69696;
    }
/* ... */
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
    a2cmmn_1.iws = a2cmmn_1.is;
    a2cmmn_1.iiws = a2cmmn_1.iis;
    a2cmmn_1.dp1 = a2fpc_1.q1pe6;
/* ... */
L6:
    avsto_(tew, a2cmmn_1.te);
/* ... */
/* ***ARLM3 01*** */
    adyndp_(&ab[2], &c__2, &c_b16);
    if (a2cmmn_1.icscnt <= 1) {
	goto L7777;
    }
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 0;
/* ... */
L7777:
    acheck_();
/* ... */
/* ***ARLM3 02*** */
    adyndp_(&ab[4], &c__2, &c_b16);
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = (a2cmmn_1.j50[a2cmmn_1.iis - 1] + 1) / 2;
/* ... */
/* L8: */
    if (a2fpc_1.q1p - a2cmmn_1.csd[a2cmmn_1.is - 1] >= 0.) {
	goto L16;
    } else {
	goto L9;
    }
L9:
    if (a2cmmn_1.ipdpl != 0) {
	goto L10;
    } else {
	goto L12;
    }
L12:
    if (a2cmmn_1.dp - a2cmmn_1.csd[a2cmmn_1.is - 1] <= 0.) {
	goto L14;
    } else {
	goto L13;
    }
L14:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q2p * a2cmmn_1.dp >= 0.) {
	goto L18;
    } else {
	goto L15;
    }
L15:
    a2cmmn_1.dp = a2fpc_1.qp6 * a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L18;
/* ... */
L10:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] > a2cmmn_1.dpmax + a2cmmn_1.dpmax) {
	goto L15;
    }
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q10p * a2cmmn_1.dp <= 0.) {
	goto L11;
    } else {
	goto L18;
    }
L11:
    a2cmmn_1.dp = a2fpc_1.qp9 * a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L18;
/* ... */
L203:
    avmult_(a2cmmn_1.ti, &a2fpc_1.qp125, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, a2cmmn_1.te, a2cmmn_1.te);
/* ... */
/* ***ARLM3 03*** */
    adyndp_(&ab[6], &c__2, &c_b16);
/* ... */
    acentr_();
/* ... */
/* ***ARLM3 04*** */
    adyndp_(&ab[8], &c__2, &c_b16);
    if (a2cmmn_1.jcr != 0) {
	goto L205;
    } else {
	goto L206;
    }
L205:
    a2cmmn_1.dp = a2fpc_1.qp01 * a2cmmn_1.dpmax;
    goto L207;
/* ... */
L206:
/* ***ARLM3 05*** */
    adyndp_(&ab[10], &c__2, &c_b16);
/* ... */
/* 	intol/outtol calc */
    adelta_();
/* ... */
/* ***ARLM3 06*** */
    adyndp_(&ab[12], &c__2, &c_b16);
    if (a2cmmn_1.jdr != 0) {
	goto L207;
    } else {
	goto L227;
    }
L227:
    if (a2cmmn_1.dpl - a2cmmn_1.dpmax <= 0.) {
	goto L728;
    } else {
	goto L727;
    }
L728:
    a2cmmn_1.dp = a2cmmn_1.dpl;
    goto L207;
/* ... */
L727:
    a2cmmn_1.dp = a2cmmn_1.dpmax;
    goto L207;
/* ... */
L16:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] != 0.) {
	goto L12;
    } else {
	goto L17;
    }
L13:
    a2cmmn_1.dp = a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L18;
/* ... */
L17:
    a2cmmn_1.dp = a2cmmn_1.tau[a2cmmn_1.is - 1];
L18:
/* ...WINNING CS IS DETERMINED ON THE BASIS OF CSD........... */
/* ... */
/* L181: */
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] >= csdsav) {
	goto L20;
    }
/* ... */
/* ... */
/* L19: */
    if (a2cmmn_1.icscnt > 1 && a2cmmn_1.is == nogood) {
	goto L20;
    }
    a2cmmn_1.iws = a2cmmn_1.is;
    a2cmmn_1.iiws = a2cmmn_1.iis;
    csdsav = a2cmmn_1.csd[a2cmmn_1.is - 1];
    a2cmmn_1.dp1 = a2cmmn_1.dp;
/* ... */
/* ...UP SURFACE SUBSCRIPT...EXAMINE CSD FOR THAT SURFACE........... */
L20:
    a2cmmn_1.is += a2cmmn_1.lsv;
    a2cmmn_1.iis += a2cmmn_1.lisv;
    if (ils1 - a2cmmn_1.is <= 0) {
	goto L21;
    } else {
	goto L6;
    }
/* ... */
L21:
    a2cmmn_1.is = a2cmmn_1.iws;
    a2cmmn_1.iis = a2cmmn_1.iiws;
    if (nogood != 0) {
	nogood = 0;
    }
    a2cmmn_1.dpcnt = a2fpc_1.q10p;
    if (a2cmmn_1.dp > a2cmmn_1.dp1) {
	a2cmmn_1.dp = a2cmmn_1.dp1;
    }
    if (a2cmmn_1.dp > a2cmmn_1.dpmax) {
	a2cmmn_1.dp = a2cmmn_1.dpmax;
    }
/* ... */
    if (a2cmmn_1.j50[a2cmmn_1.iis - 1] <= 0) {
	goto L22;
    } else {
	goto L548;
    }
/* ... */
L548:
    if (a2cmmn_1.ipdpl != 0) {
	goto L22;
    } else {
	goto L48;
    }
/* ... */
L22:
    avsto_(a2cmmn_1.te, a2cmmn_1.tel);
    a2cmmn_1.jbr = 0;
    if (a2cmmn_1.ipdpl != 0) {
	goto L24;
    } else {
	goto L26;
    }
/* ... */
/* ... */
L26:
    avsto_(a2cmmn_1.tek, a2cmmn_1.tes);
    if (a2cmmn_1.icscnt > 1 && a2cmmn_1.numpts == a2cmmn_1.numpt1) {
	a2cmmn_1.dp = a2fpc_1.qp5 * a2cmmn_1.dp;
    }
/* ... */
L28:
    avsto_(a2cmmn_1.tak, a2cmmn_1.ta);
    avmult_(a2cmmn_1.tik, &a2cmmn_1.dp, a2cmmn_1.cmove);
    avadd_(a2cmmn_1.tes, a2cmmn_1.cmove, a2cmmn_1.te);
/* ... */
/* ...NOW TE MOVED BY DP, DO 2 SURF ITER OR CALL APLANE...... */
    if (a2cmmn_1.ipdpl != 0) {
	goto L68;
    } else {
	goto L244;
    }
/* ... */
L244:
/* ........ 2 SURF ITER    ........... */
/* ***ARLM3 07*** */
    adyndp_(&ab[14], &c__2, &c_b16);
/* ... */
    acentr_();
/* ... */
/* ***ARLM3 08*** */
    adyndp_(&ab[16], &c__2, &c_b16);
    if (a2cmmn_1.jcr != 0) {
	goto L532;
    } else {
	goto L33;
    }
/* ......................................ERROR 804............ */
L532:
    ++k804;
    if (k804 > 10) {
	aerr_(&c__804);
    }
    a2cmmn_1.dp *= a2fpc_1.qp75;
    goto L28;
/* ... */
L32:
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j21[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2fpc_1.q1p;
    avsto_(a2cmmn_1.tek, a2cmmn_1.te);
    avsto_(a2cmmn_1.tak, a2cmmn_1.ta);
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 0;
    if (a2cmmn_1.icscnt <= 1) {
	goto L22;
    }
/* ...TEK CONTAINS MOST CURRENT PT IN TCDAT AND NEXT ITERATION DONE FROM */
/* ...THIS POINT. TA ALSO RESTORED TO TAK.  NOTICE JUST BEFORE CALLING */
/* ...CENTER TO DO 2 SURF ITERATION. */
    nogood = a2cmmn_1.is;
    csdsav = a2fpc_1.q130p;
    goto L207;
L24:
    avsto_(a2cmmn_1.te, a2cmmn_1.tes);
    if (a2cmmn_1.numpts - a2cmmn_1.numpt1 == 0 && a2cmmn_1.th[a2cmmn_1.ics - 
	    1] != a2fpc_1.qnul) {
	a2cmmn_1.dp = a2fpc_1.qp6 * a2cmmn_1.dp;
    }
    goto L28;
/* ... */
L33:
    a2cmmn_1.j10 = 0;
/* ***ARLM3 09*** */
    adyndp_(&ab[18], &c__2, &c_b16);
/* ... */
/* 	step vector delta */
    adelta_();
/* ... */
/* ***ARLM3 10*** */
    adyndp_(&ab[20], &c__2, &c_b16);
    if (a2cmmn_1.jdr != 0) {
	goto L34;
    } else {
	goto L36;
    }
L34:
    if (a2cmmn_1.dpcnt - a2fpc_1.q1p != 0.) {
	goto L35;
    } else {
	goto L77;
    }
L35:
    a2cmmn_1.dpcnt -= a2fpc_1.q1p;
    avsto_(a2cmmn_1.tek, a2cmmn_1.te);
    avsto_(a2cmmn_1.tak, a2cmmn_1.ta);
    if (a2cmmn_1.dpcnt < a2fpc_1.q5p && a2cmmn_1.jbr == 1) {
	a2cmmn_1.dp *= a2fpc_1.qp6;
    }
    goto L28;
/* ... */
L38:
    avdot_(a2cmmn_1.ti, a2cmmn_1.tik, &ans);
    if (ans >= a2fpc_1.qnul) {
	goto L43;
    }
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ti, a2cmmn_1.ti);
    goto L43;
/* ... */
L36:
    avcros_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.sn[a2cmmn_1.ids - 1], 
	    a2cmmn_1.ti);
    avnorm_(a2cmmn_1.ti, a2cmmn_1.ti, &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L41;
    } else {
	goto L38;
    }
L41:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.ti);
/* 	TI is tool aiming */
    avnorm_(a2cmmn_1.ti, a2cmmn_1.ti, &a2cmmn_1.ier);
L43:
/* ... */
/* ***ARLM3 11*** */
    adyndp_(&ab[22], &c__2, &c_b16);
    if (i3stry > 4) {
	goto L44;
    }
/* ... */
    acheck_();
/* ... */
/* ***ARLM3 12*** */
    adyndp_(&ab[24], &c__2, &c_b16);
    if (a2cmmn_1.jckr != 0) {
	goto L48;
    }
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    aftr12 = ans;
    if (ans > a2fpc_1.qp6x01) {
	goto L44;
    }
/* .....................................ERROR -805...... */
    aerr_(&c_n805);
    goto L8000;
/* ... */
L48:
    avsto_(a2cmmn_1.te, &a2cmmn_1.tee[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ta, tae);
/* ......... 3 SURF ITER       ............... */
/* ***ARLM3 13*** */
    adyndp_(&ab[26], &c__2, &c_b16);
/* ... */
    acentr_();
/* ... */
/* ***ARLM3 14*** */
    adyndp_(&ab[28], &c__2, &c_b16);
    if ((i__2 = a2cmmn_1.jcr - 1) < 0) {
	goto L78;
    } else if (i__2 == 0) {
	goto L49;
    } else {
	goto L3332;
    }
L78:
    if (a2cmmn_1.icscnt - 1 <= 0) {
	goto L278;
    } else {
	goto L279;
    }
/* ..............................ERROR 802......... */
L278:
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 4) {
	aerr_(&c__802);
    }
    atanco_1.kttry2 = 1;
    return 0;
/* ... */
L3332:
    if ((a2cmmn_1.te[0] - a2cmmn_1.tee[a2cmmn_1.is - 1]) * a2cmmn_1.ti[0] + (
	    a2cmmn_1.te[1] - a2cmmn_1.tee[a2cmmn_1.is]) * a2cmmn_1.ti[1] + (
	    a2cmmn_1.te[2] - a2cmmn_1.tee[a2cmmn_1.is + 1]) * a2cmmn_1.ti[2] 
	    <= 0.) {
	goto L3333;
    } else {
	goto L332;
    }
L3333:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    avsto_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.te);
    avsto_(tae, a2cmmn_1.ta);
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    if (ans < a2fpc_1.qp5x01) {
	goto L332;
    }
    isto = a2cmmn_1.is;
    a2cmmn_1.is = a2cmmn_1.ips;
    iisto = a2cmmn_1.iis;
    a2cmmn_1.iis = a2cmmn_1.iips;
/* ... */
    amind_();
/* ... */
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
/* ... */
    amind_();
/* ... */
    a2cmmn_1.is = isto;
    a2cmmn_1.iis = iisto;
    goto L44;
/* ... */
L279:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q5p * a2cmmn_1.dp;
    nogood = a2cmmn_1.is;
    csdsav = a2fpc_1.q130p;
    goto L207;
/* ... */
L44:
    astos_();
/* ... */
L8000:
    if (i3stry > 4) {
	a2cmmn_1.csd[a2cmmn_1.is - 1] = a2cmmn_1.dp;
    }
    i3stry = 0;
    a2cmmn_1.jbr = 0;
    icsrej = 0;
    if (a2cmmn_1.numpt1 <= 0) {
	goto L79;
    } else {
	goto L46;
    }
/* ........................ERROR 803....... */
L79:
    aerr_(&c__803);
/* ... */
L46:
    --a2cmmn_1.numpt1;
    for (i__ = 1; i__ <= 3; ++i__) {
	a2cmmn_1.tek[i__ - 1] = a2cmmn_1.te[i__ - 1];
	a2cmmn_1.tak[i__ - 1] = a2cmmn_1.ta[i__ - 1];
	a2cmmn_1.tik[i__ - 1] = a2cmmn_1.ti[i__ - 1];
	i__2 = ils1;
	i__1 = a2cmmn_1.lsv;
	for (a2cmmn_1.k = a2cmmn_1.ips; i__1 < 0 ? a2cmmn_1.k >= i__2 : 
		a2cmmn_1.k <= i__2; a2cmmn_1.k += i__1) {
	    a2cmmn_1.j = a2cmmn_1.k + i__ - 1;
	    a2cmmn_1.tpk[a2cmmn_1.j - 1] = a2cmmn_1.tp[a2cmmn_1.j - 1];
	    a2cmmn_1.spk[a2cmmn_1.j - 1] = a2cmmn_1.sp[a2cmmn_1.j - 1];
/* L47: */
	    a2cmmn_1.snk[a2cmmn_1.j - 1] = a2cmmn_1.sn[a2cmmn_1.j - 1];
	}
    }
    avsto_(&a2cmmn_1.tn[a2cmmn_1.ips - 1], &a2cmmn_1.tnk[a2cmmn_1.ips - 1]);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.ids - 1], &a2cmmn_1.tnk[a2cmmn_1.ids - 1]);
    a2cmmn_1.dp1 = a2cmmn_1.dp;
    csdsav = a2fpc_1.q130p;
/* ..MULTI-CS AND LARGE CUTTER RELATIVE TO CIRCULAR DS, AVOID J20=2 LOGIC */
    if (a2cmmn_1.icscnt == 1) {
	goto L88801;
    }
    if (a2cmmn_1.j24[a2cmmn_1.iids - 1] != 2) {
	goto L88801;
    }
    a2cmmn_1.k = a2cmmn_1.ipontr[a2cmmn_1.iids - 1] + 10;
    if (a2cmmn_1.cutdat[0] < a2cmmn_1.cansto[a2cmmn_1.k - 1] * a2fpc_1.q5p) {
	goto L88801;
    }
    goto L802;
L88801:
    if (a2cmmn_1.j20[a2cmmn_1.iis - 1] - 2 != 0) {
	goto L802;
    } else {
	goto L801;
    }
L801:
    avsto_(&a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.te);
    avsto_(a2cmmn_1.tal, a2cmmn_1.ta);
    a2cmmn_1.tp[a2cmmn_1.ips - 1] = ps1;
    a2cmmn_1.tp[a2cmmn_1.ips] = ps2;
    a2cmmn_1.tp[a2cmmn_1.ips + 1] = ps3;
    a2cmmn_1.sn[a2cmmn_1.ips - 1] = ps4;
    a2cmmn_1.sn[a2cmmn_1.ips] = ps5;
    a2cmmn_1.sn[a2cmmn_1.ips + 1] = ps6;
    a2cmmn_1.tp[a2cmmn_1.ids - 1] = ds1;
    a2cmmn_1.tp[a2cmmn_1.ids] = ds2;
    a2cmmn_1.tp[a2cmmn_1.ids + 1] = ds3;
    a2cmmn_1.sn[a2cmmn_1.ids - 1] = ds4;
    a2cmmn_1.sn[a2cmmn_1.ids] = ds5;
    a2cmmn_1.sn[a2cmmn_1.ids + 1] = ds6;
    avsto_(pstn, &a2cmmn_1.tn[a2cmmn_1.ips - 1]);
    avsto_(dstn, &a2cmmn_1.tn[a2cmmn_1.ids - 1]);
    goto L55;
/* .......... */
L802:
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
    a2cmmn_1.iws = a2cmmn_1.is;
    a2cmmn_1.iiws = a2cmmn_1.iis;
    if (a2cmmn_1.icscnt - 1 <= 0) {
	goto L12;
    } else {
	goto L851;
    }
L851:
    avsto_(a2cmmn_1.te, tew);
    goto L6;
L49:
    avsub_(a2cmmn_1.te, &a2cmmn_1.tee[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ti, &ans);
    avsto_(a2cmmn_1.te, &a2cmmn_1.tee[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ta, tae);
    if (ans < a2fpc_1.qnul) {
	goto L2468;
    }
    if (a2cmmn_1.ifar[a2cmmn_1.iis - 1] > 1 && a2cmmn_1.numpts - 
	    a2cmmn_1.numpt1 == 0) {
	goto L2468;
    }
    goto L8624;
L2468:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    if (abs(ans) > a2fpc_1.qp5 * a2cmmn_1.tau[a2cmmn_1.is - 1]) {
	goto L8624;
    }
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.dp = a2fpc_1.q4p * a2cmmn_1.tau[a2cmmn_1.is - 1];
    goto L22;
L8624:
    a2cmmn_1.iws = a2cmmn_1.is;
    a2cmmn_1.iiws = a2cmmn_1.iis;
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
L52:
    if (a2cmmn_1.is - ils1 >= 0) {
	goto L54;
    } else {
	goto L50;
    }
L50:
    if (a2cmmn_1.is - a2cmmn_1.iws != 0) {
	goto L53;
    } else {
	goto L51;
    }
/* ... */
L53:
    amind_();
/* ... */
/* L211: */
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 != 0) {
	goto L212;
    } else {
	goto L219;
    }
L212:
    if (a2cmmn_1.j23[a2cmmn_1.iis - 1] > 0) {
	goto L51;
    }
/* ...CHECK CSD ... DONE AFTER OK 3 SURF ITER TO ONE CS */
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] == 1 && a2cmmn_1.s[a2cmmn_1.is - 1] 
	    < a2fpc_1.qnul) {
	goto L9999;
    }
    if ((d__1 = a2cmmn_1.csd[a2cmmn_1.is - 1] - a2cmmn_1.csd[a2cmmn_1.iws - 1]
	    , abs(d__1)) > a2fpc_1.qp5 * a2cmmn_1.dp) {
	goto L51;
    }
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2cmmn_1.s[a2cmmn_1.is - 1] * 
	    a2cmmn_1.z__[a2cmmn_1.is - 1] * a2cmmn_1.stck1[a2cmmn_1.is - 1];
    if (a2cmmn_1.stck[a2cmmn_1.is - 1] <= 0.) {
	goto L9999;
    } else {
	goto L51;
    }
L9999:
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 1;
    if (a2cmmn_1.iws == 201) {
	++icsrj1;
    }
    if (a2cmmn_1.iws == 301) {
	++icsrj2;
    }
    if (icsrj1 + icsrj2 > 3) {
	goto L51;
    }
    if (icsrj1 == 0 || icsrj2 == 0) {
	goto L48;
    }
    avsub_(&a2cmmn_1.tee[200], &a2cmmn_1.tee[300], a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ti, &ans);
    if (ans <= 0.) {
	goto L4802;
    } else {
	goto L4803;
    }
L4802:
    a2cmmn_1.iws = 201;
    a2cmmn_1.iiws = 81;
    goto L54;
L4803:
    a2cmmn_1.iws = 301;
    a2cmmn_1.iiws = 121;
    goto L54;
/* ... */
L219:
    if (a2cmmn_1.j22[a2cmmn_1.iis - 1] <= 0) {
	goto L51;
    } else {
	goto L213;
    }
L213:
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 0;
/* ... */
    acheck_();
/* ... */
    if (a2cmmn_1.stckn[a2cmmn_1.is - 1] > a2fpc_1.qnul) {
	goto L51;
    }
    goto L9999;
L51:
    a2cmmn_1.is += a2cmmn_1.lsv;
    a2cmmn_1.iis += a2cmmn_1.lisv;
    goto L52;
L54:
    a2cmmn_1.is = a2cmmn_1.iws;
    a2cmmn_1.iis = a2cmmn_1.iiws;
    avsto_(a2cmmn_1.ta, a2cmmn_1.tal);
    avcros_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.sn[a2cmmn_1.ids - 1], 
	    a2cmmn_1.til);
    avnorm_(a2cmmn_1.til, a2cmmn_1.til, &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L805;
    } else {
	goto L808;
    }
L805:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.til);
    avnorm_(a2cmmn_1.til, a2cmmn_1.til, &a2cmmn_1.ier);
/* ... */
L808:
    ps1 = a2cmmn_1.tp[a2cmmn_1.ips - 1];
    ps2 = a2cmmn_1.tp[a2cmmn_1.ips];
    ps3 = a2cmmn_1.tp[a2cmmn_1.ips + 1];
    ps4 = a2cmmn_1.sn[a2cmmn_1.ips - 1];
    ps5 = a2cmmn_1.sn[a2cmmn_1.ips];
    ps6 = a2cmmn_1.sn[a2cmmn_1.ips + 1];
    ds1 = a2cmmn_1.tp[a2cmmn_1.ids - 1];
    ds2 = a2cmmn_1.tp[a2cmmn_1.ids];
    ds3 = a2cmmn_1.tp[a2cmmn_1.ids + 1];
    ds4 = a2cmmn_1.sn[a2cmmn_1.ids - 1];
    ds5 = a2cmmn_1.sn[a2cmmn_1.ids];
    ds6 = a2cmmn_1.sn[a2cmmn_1.ids + 1];
    avsto_(&a2cmmn_1.tn[a2cmmn_1.ips - 1], pstn);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.ids - 1], dstn);
L55:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.v);
    avdot_(a2cmmn_1.v, a2cmmn_1.tik, &ans);
    if (ans >= a2fpc_1.qnul) {
	goto L57;
    }
L332:
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q5p * a2cmmn_1.dp;
    ++i3stry;
    goto L32;
/* ... */
L57:
    avleng_(a2cmmn_1.v, &a2cmmn_1.vl);
    if (a2cmmn_1.numpts == a2cmmn_1.numpt1 && a2cmmn_1.vl < a2cmmn_1.tau1[
	    a2cmmn_1.is - 1]) {
	goto L332;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 != 0) {
	goto L949;
    } else {
	goto L449;
    }
L949:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L449;
    }
    avdot_(a2cmmn_1.vtem, &a2cmmn_1.tn[a2cmmn_1.is - 1], &ans);
    if (abs(ans) < a2fpc_1.qp017) {
	goto L449;
    }
    if (ans * a2cmmn_1.past[a2cmmn_1.is - 1] >= 0.) {
	goto L449;
    } else {
	goto L401;
    }
L401:
    if (a2cmmn_1.is != isstop) {
	goto L400;
    }
    ++kstop;
    if (a2cmmn_1.icscnt > 1 && a2cmmn_1.jcr == 1 && kstop > 20) {
	goto L402;
    }
    goto L403;
L402:
    isstop = -100;
    kstop = 0;
    goto L449;
L400:
    isstop = a2cmmn_1.is;
    kstop = 0;
L403:
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.notan[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.plnd1[a2cmmn_1.is - 1] = 0.;
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    goto L48;
/* ... */
L449:
    a2cmmn_1.j10 = 1;
/* ***ARLM3 15*** */
    adyndp_(&ab[30], &c__2, &c_b16);
/* ... */
    adelta_();
/* ... */
/* ***ARLM3 16*** */
    adyndp_(&ab[32], &c__2, &c_b16);
    if (a2cmmn_1.jdr != 0) {
	goto L58;
    } else {
	goto L63;
    }
L58:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.q1p2 * a2cmmn_1.vl;
/* ..................................ERROR -805...... */
/* ... */
    ++k805;
    if (k805 > 10) {
	aerr_(&c_n805);
    }
    if (a2cmmn_1.dp - a2cmmn_1.csd[a2cmmn_1.is - 1] <= 0.) {
	goto L61;
    } else {
	goto L59;
    }
L61:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q2p * a2cmmn_1.dp >= 0.) {
	goto L60;
    } else {
	goto L62;
    }
L62:
    a2cmmn_1.dp = a2fpc_1.qp6 * a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L60;
/* ... */
L59:
    a2cmmn_1.dp = a2cmmn_1.csd[a2cmmn_1.is - 1];
L60:
    a2cmmn_1.dpcnt = a2fpc_1.q10p;
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 2;
    goto L22;
/* ... */
L63:
    if (a2cmmn_1.ifar[a2cmmn_1.iis - 1] - 1 != 0) {
	goto L64;
    } else {
	goto L76;
    }
L64:
    --a2cmmn_1.ifar[a2cmmn_1.iis - 1];
    if (a2cmmn_1.ipdpl != 0) {
	goto L66;
    } else {
	goto L65;
    }
L65:
    astos_();
/* ... */
    avdot_(a2cmmn_1.ti, a2cmmn_1.til, a2cmmn_1.temp);
/* ... */
    a2cmmn_1.a = a2cmmn_1.temp[0];
    a2cmmn_1.temp[0] = a2fpc_1.q1p;
    if (a2cmmn_1.a < a2fpc_1.qnul) {
	a2cmmn_1.temp[0] = -a2fpc_1.q1p;
    }
    avmult_(a2cmmn_1.til, a2cmmn_1.temp, a2cmmn_1.ti);
L66:
    avsto_(a2cmmn_1.te, a2cmmn_1.tek);
    avsto_(a2cmmn_1.ta, a2cmmn_1.tak);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L67: */
	tew[i__ - 1] = a2fpc_1.q3p * a2cmmn_1.tau[a2cmmn_1.is - 1] * 
		a2cmmn_1.ti[i__ - 1] + a2cmmn_1.te[i__ - 1];
    }
    goto L2;
/* ... */
/* ... */
/* ... */
L68:
/* ***ARLM3 17*** */
    adyndp_(&ab[34], &c__2, &c_b16);
/* ... */
    aplane_();
/* ... */
    csdsav = a2fpc_1.q130p;
/* ***ARLM3 18*** */
    adyndp_(&ab[36], &c__2, &c_b16);
    if (a2cmmn_1.jpr < 0) {
	goto L604;
    } else if (a2cmmn_1.jpr == 0) {
	goto L603;
    } else {
	goto L69;
    }
L603:
    avsto_(a2cmmn_1.te, tew);
    goto L5;
/* ... */
L604:
    avmult_(a2cmmn_1.ti, &a2fpc_1.qp5, tew);
    avadd_(tew, a2cmmn_1.te, tew);
/*     ENSURE THAT  MOVEMENT DOES NOT VIOLATE ANOTHER CS */
    if (a2cmmn_1.icscnt <= 1) {
	goto L602;
    }
    avsub_(tew, a2cmmn_1.tek, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    a2cmmn_1.csd[a2cmmn_1.is - 1] = ans;
    i__1 = a2cmmn_1.icscnt;
    for (ii = 1; ii <= i__1; ++ii) {
	kk = a2cmmn_1.lsv * (ii - 1) + 201;
	if (a2cmmn_1.csd[kk - 1] >= ans) {
	    goto L6022;
	}
	ans = a2cmmn_1.csd[kk - 1] * a2fpc_1.qp9;
	avmult_(a2cmmn_1.ti, &ans, a2cmmn_1.cmove);
	avadd_(a2cmmn_1.tek, a2cmmn_1.cmove, tew);
L6022:
	;
    }
    goto L602;
/* ... */
L69:
    if (kgotbe == 1) {
	goto L63;
    }
    a2cmmn_1.iws = a2cmmn_1.is;
    a2cmmn_1.iiws = a2cmmn_1.iis;
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
L84:
    if (ils1 - a2cmmn_1.is <= 0) {
	goto L70;
    } else {
	goto L72;
    }
L70:
    a2cmmn_1.is = a2cmmn_1.iws;
    a2cmmn_1.iis = a2cmmn_1.iiws;
    goto L63;
L73:
    a2cmmn_1.is += a2cmmn_1.lsv;
    a2cmmn_1.iis += a2cmmn_1.lisv;
    goto L84;
L72:
    if (a2cmmn_1.is - a2cmmn_1.iws != 0) {
	goto L75;
    } else {
	goto L73;
    }
/* ... */
L75:
    amind_();
/* ... */
/* L214: */
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 != 0) {
	goto L215;
    } else {
	goto L226;
    }
L215:
    if (a2cmmn_1.j23[a2cmmn_1.iis - 1] > 0) {
	goto L73;
    }
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2cmmn_1.stck1[a2cmmn_1.is - 1] * 
	    a2cmmn_1.z__[a2cmmn_1.is - 1] * a2cmmn_1.s[a2cmmn_1.is - 1];
    if (a2cmmn_1.stck[a2cmmn_1.is - 1] <= 0.) {
	goto L74;
    } else {
	goto L73;
    }
L74:
    avsto_(a2cmmn_1.tel, a2cmmn_1.te);
    a2cmmn_1.dp = a2fpc_1.q1p1 * a2cmmn_1.csd[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.spl[a2cmmn_1.ids - 1], &a2cmmn_1.sp[a2cmmn_1.ids - 1]);
    avsto_(&a2cmmn_1.spl[a2cmmn_1.ips - 1], &a2cmmn_1.sp[a2cmmn_1.ips - 1]);
    goto L68;
/* ... */
L226:
    if (a2cmmn_1.j22[a2cmmn_1.iis - 1] <= 0) {
	goto L73;
    } else {
	goto L216;
    }
L216:
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 0;
/* ... */
    acheck_();
/* ... */
    if (a2cmmn_1.stckn[a2cmmn_1.is - 1] <= 0.) {
	goto L74;
    } else {
	goto L73;
    }
L76:
    if (a2cmmn_1.multax != 1) {
	goto L997;
    }
    if (a2cmmn_1.numpt1 == a2cmmn_1.numpts) {
	goto L997;
    }
    if (a2cmmn_1.ipdpl == 1) {
	goto L997;
    }
    if (a2cmmn_1.j24[a2cmmn_1.iips - 1] != 8) {
	goto L997;
    }
    if (a2cmmn_1.vl <= aftr12 * a2fpc_1.q1p5) {
	goto L997;
    }
    a2cmmn_1.dp = aftr12 * a2fpc_1.q1p5;
    goto L60;
/* ... */
L997:
    astos_();
    a2cmmn_1.ier = -10;
/* ... */
    atape_();
/* ... */
/* ***ARLM3 EX*** */
    adyndp_(&ab[38], &c__1, &c_b3);
    a2cmmn_1.nw = 0;
    return 0;
/* ******************************************************************** */
/* ... */
L77:
    if (a2cmmn_1.jbr == 1) {
	goto L907;
    }
/* ...................ERROR -805................ */
    aerr_(&c_n805);
    a2cmmn_1.dpcnt += a2fpc_1.q10p;
    a2cmmn_1.jbr = 1;
    goto L35;
/* ... */
L907:
    a2cmmn_1.jbr = 0;
/* ...................................ERROR 801............ */
    aerr_(&c__801);
L69696:
    kgotbe = 1;
    if (a2cmmn_1.is == 201) {
	goto L79797;
    }
    a2cmmn_1.is = 201;
    a2cmmn_1.iis = 81;
    goto L68;
L79797:
    a2cmmn_1.is = 301;
    a2cmmn_1.iis = 121;
    goto L68;
} /* arlm3_ */

#undef ab


