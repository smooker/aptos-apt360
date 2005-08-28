/* APLANE.f -- translated by f2c (version 20000121).
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
    doublereal savtt, savto, savti, savt1, savt2, savt3, savt4, savt6, savt8;
    integer ismata, iismat, kchnge, kon, kst;
} taumd2_;

#define taumd2_1 taumd2_

/* Table of constant values */

static integer c__3 = 3;
static integer c_b4 = 111100;
static integer c__5 = 5;
static integer c_b8 = 110000;
static integer c_n846 = -846;
static integer c_n845 = -845;

/* Subroutine */ int aplane_()
{
    /* Initialized data */

    static struct {
	char e_1[56];
	real e_2;
	} equiv_10 = { {'A', 'P', 'L', 'A', 'N', 'E', 'T', 'P', 'A', 'P', 'L',
		 'A', 'N', 'E', '0', '1', 'A', 'P', 'L', 'A', 'N', 'E', '0', 
		'2', 'A', 'P', 'L', 'A', 'N', 'E', '0', '3', 'A', 'P', 'L', 
		'A', 'N', 'E', '0', '4', 'A', 'P', 'L', 'A', 'N', 'E', '0', 
		'5', 'A', 'P', 'L', 'A', 'N', 'E', 'E', 'X'}, (float)0. };

#define ab ((real *)&equiv_10)


    static integer i__;
    static doublereal ans;
    extern /* Subroutine */ int aerr_();
    static integer ker846;
    extern /* Subroutine */ int avadd_();
    static integer ier, kaerr;
    extern /* Subroutine */ int avsto_(), addst_(), avdot_(), avsub_(), 
	    acheck_(), adyndp_();
    static integer kdespr, ktansf;
    extern /* Subroutine */ int acentr_();
    static integer kwhich;
    extern /* Subroutine */ int avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
    kdespr = 0;
    ktansf = 0;
    taumd2_1.kchnge = 0;
    kaerr = 0;
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 4) {
	goto L2222;
    }
    if (a2cmmn_1.th[a2cmmn_1.is - 1] != a2fpc_1.qnul) {
	goto L2222;
    }
    ktansf = 41;
    if (a2cmmn_1.ifl4[a2cmmn_1.iis - 1] == 1) {
	ktansf = 1;
    }
    if (a2cmmn_1.itseg[ktansf - 1] != 9) {
	goto L2222;
    }
/* ...PSTAN, TANTO, S TO TAN SURF CALCULATED FROM TE */
    taumd2_1.kchnge = 1;
    taumd2_1.kon = a2cmmn_1.itlon[a2cmmn_1.iis - 1];
    taumd2_1.kst = a2cmmn_1.isftyp[a2cmmn_1.iis - 1];
    taumd2_1.ismata = a2cmmn_1.is;
    taumd2_1.iismat = a2cmmn_1.iis;
/* ... */
    taumd2_1.savtt = a2cmmn_1.tau[a2cmmn_1.is - 1];
    taumd2_1.savto = a2cmmn_1.tau1[a2cmmn_1.is - 1];
    taumd2_1.savti = a2cmmn_1.tau2[a2cmmn_1.is - 1];
    taumd2_1.savt1 = a2cmmn_1.eps1[a2cmmn_1.is - 1];
    taumd2_1.savt2 = a2cmmn_1.eps2[a2cmmn_1.is - 1];
    taumd2_1.savt3 = a2cmmn_1.eps3[a2cmmn_1.is - 1];
    taumd2_1.savt4 = a2cmmn_1.eps4[a2cmmn_1.is - 1];
    taumd2_1.savt6 = a2cmmn_1.eps6[a2cmmn_1.is - 1];
    taumd2_1.savt8 = a2cmmn_1.eps8[a2cmmn_1.is - 1];
/* ... */
/* ... */
    a2cmmn_1.itlon[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.isftyp[a2cmmn_1.iis - 1] = 3;
/* ... */
    a2cmmn_1.tau[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.tau1[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.tau2[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps1[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps2[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps3[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps4[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps6[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
    a2cmmn_1.eps8[a2cmmn_1.is - 1] *= a2fpc_1.qp001;
L2222:
/* ***APLANE TP*** */
    adyndp_(ab, &c__3, &c_b4);
/* ... */
L9:
    acheck_();
    ker846 = 0;
/* ... */
    if (taumd2_1.kchnge == 1 && a2cmmn_1.j50[a2cmmn_1.iis - 1] == 1) {
	goto L1;
    }
/* ***APLANE 01*** */
    adyndp_(&ab[2], &c__5, &c_b8);
/* ... */
    if (a2cmmn_1.jckr != 0) {
	goto L1;
    } else {
	goto L14;
    }
/* ... */
L1:
/* ***APLANE 02*** */
    adyndp_(&ab[4], &c__5, &c_b8);
    if (a2cmmn_1.ichkct[a2cmmn_1.iis - 1] != 0) {
	goto L125;
    }
/* ... */
L320:
    acentr_();
/* ... */
    if (a2cmmn_1.jcr == 2) {
	goto L2;
    }
    if (a2cmmn_1.jcr < 0) {
	goto L2;
    } else if (a2cmmn_1.jcr == 0) {
	goto L10;
    } else {
	goto L11;
    }
L2:
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 >= 0) {
	goto L4;
    } else {
	goto L12;
    }
L12:
    a2cmmn_1.j21[a2cmmn_1.iis - 1] = 1;
    if (a2cmmn_1.jcr != 2) {
	avsto_(a2cmmn_1.tel, a2cmmn_1.te);
    }
    if (a2cmmn_1.icscnt > 1) {
	goto L30;
    }
    if (a2cmmn_1.jcr != 2 || a2cmmn_1.isftyp[a2cmmn_1.iis - 1] != 1) {
	goto L310;
    }
/* ...  WARNING- RESTART EXIT FROM ACENTR IN APLANE */
    ++ker846;
    if (ker846 > 1) {
	goto L310;
    }
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ti, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    addst_();
    ans = a2cmmn_1.s[a2cmmn_1.is - 1] - a2cmmn_1.cutdat[0];
    avmult_(a2cmmn_1.ti, &ans, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.te);
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 1;
    goto L320;
L310:
    if (a2cmmn_1.jckr == 1 && a2cmmn_1.jcr == -1) {
	goto L311;
    }



    goto L312;
L311:
    ans = a2cmmn_1.dp * a2fpc_1.qp1;
    avmult_(a2cmmn_1.ti, &ans, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.te);
    goto L9;
L312:
    aerr_(&c_n846);
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q3p * a2cmmn_1.dp;
    adyndp_(&ab[6], &c__5, &c_b8);
    if (a2cmmn_1.icscnt - 1 <= 0) {
	goto L15;
    } else {
	goto L30;
    }
L30:
    a2cmmn_1.stck[a2cmmn_1.is - 1] = a2fpc_1.q1pe6;
    a2cmmn_1.dp = a2cmmn_1.dpmax;
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2fpc_1.q3p5 * a2cmmn_1.dp;
    a2cmmn_1.csd[a2cmmn_1.is - 1] = a2fpc_1.q11p * a2cmmn_1.dp;
    a2cmmn_1.ichkct[a2cmmn_1.iis - 1] = 1;
    goto L15;
/* .......... */
L4:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L5: */
	a2cmmn_1.cmove[i__ - 1] = a2cmmn_1.tau[a2cmmn_1.is - 1] * a2cmmn_1.ti[
		i__ - 1] + a2cmmn_1.tel[i__ - 1] - a2cmmn_1.te[i__ - 1];
    }
    a2cmmn_1.dpmx1[a2cmmn_1.is - 1] = a2fpc_1.qp5 * a2cmmn_1.dpmx1[
	    a2cmmn_1.is - 1];
    a2cmmn_1.temp[0] = a2cmmn_1.dpmx1[a2cmmn_1.is - 1] - a2cmmn_1.tau[
	    a2cmmn_1.is - 1];
/* ***APLANE 04*** */
    if (a2cmmn_1.temp[0] >= 0.) {
	goto L7;
    } else {
	goto L6;
    }
L6:
    ++kdespr;
    if (kdespr >= 2) {
	goto L62571;
    }
    if (ktansf == 0) {
	goto L62571;
    }
    kwhich = a2cmmn_1.ids;
    if (ktansf == 1) {
	kwhich = a2cmmn_1.ips;
    }
    avdot_(a2cmmn_1.ta, &a2cmmn_1.sn[kwhich - 1], &ans);
    if (abs(ans) > a2fpc_1.qp4x95) {
	goto L62571;
    }
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ti, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    addst_();
    if (ier == 0) {
	goto L62571;
    }
    a2cmmn_1.isftyp[a2cmmn_1.iis - 1] = 1;
    avsto_(a2cmmn_1.tek, a2cmmn_1.te);
    goto L9;
L62571:
    kaerr = 843;
    goto L1111;
/* ... */
L7:
    avadd_(a2cmmn_1.te, a2cmmn_1.cmove, a2cmmn_1.te);
    goto L9;
/* ............ */
L10:
    kaerr = 842;
    goto L1111;
/* ... */
L11:
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ti, &ans);
/* ***APLANE 05*** */
    adyndp_(&ab[10], &c__5, &c_b8);
    if (ans < a2fpc_1.qnul) {
	goto L120;
    }
/* L13: */
    if (a2cmmn_1.jcr - 1 != 0) {
	goto L21;
    } else {
	goto L20;
    }
L21:
    a2cmmn_1.jpr = -1;
    goto L16;
/* ... */
L20:
    a2cmmn_1.jpr = 1;
    goto L16;
/* ... */
L14:
    --a2cmmn_1.numpt1;
    if (a2cmmn_1.numpt1 - 1 != 0) {
	goto L15;
    } else {
	goto L17;
    }
L15:
    a2cmmn_1.jpr = 0;
L16:
/* ***APLANE EX*** */
    adyndp_(&ab[12], &c__3, &c_b4);
/* ... */
L1111:
    if (taumd2_1.kchnge == 0) {
	goto L3333;
    }
    a2cmmn_1.itlon[a2cmmn_1.iis - 1] = taumd2_1.kon;
    a2cmmn_1.isftyp[a2cmmn_1.iis - 1] = taumd2_1.kst;
    a2cmmn_1.tau[a2cmmn_1.is - 1] = taumd2_1.savtt;
    a2cmmn_1.tau1[a2cmmn_1.is - 1] = taumd2_1.savto;
    a2cmmn_1.tau2[a2cmmn_1.is - 1] = taumd2_1.savti;
    a2cmmn_1.eps1[a2cmmn_1.is - 1] = taumd2_1.savt1;
    a2cmmn_1.eps2[a2cmmn_1.is - 1] = taumd2_1.savt2;
    a2cmmn_1.eps3[a2cmmn_1.is - 1] = taumd2_1.savt3;
    a2cmmn_1.eps4[a2cmmn_1.is - 1] = taumd2_1.savt4;
    a2cmmn_1.eps6[a2cmmn_1.is - 1] = taumd2_1.savt6;
    a2cmmn_1.eps8[a2cmmn_1.is - 1] = taumd2_1.savt8;
    taumd2_1.kchnge = 0;
L3333:
    if (kaerr == 0) {
	return 0;
    }
    aerr_(&kaerr);
    return 0;
/* ... */
L17:
    kaerr = 841;
    goto L1111;
/* ... */
L120:
    aerr_(&c_n845);
    goto L12;
L125:
    a2cmmn_1.ichkct[a2cmmn_1.iis - 1] = 0;
    goto L14;
/* **********NOTE TAU, EPS, ITLON, ISFTYP ADJUSTMENTS NOT MADE */
/* IN PSTAN, TANTO, AND -845 OR -846 */
} /* aplane_ */

#undef ab


