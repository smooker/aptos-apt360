/* ACNTR2.f -- translated by f2c (version 20000121).
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
    doublereal probuf[100], adum[2000];
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
    integer icmvl, jta, kount, iret, iin, iout;
    doublereal tanang;
    integer kas905;
} acencm_;

#define acencm_1 acencm_

/* Table of constant values */

static integer c__5 = 5;
static integer c_b8 = 110000;
static integer c__906 = 906;
static integer c_n910 = -910;
static integer c__12 = 12;
static integer c_b52 = 111111;
static integer c_n905 = -905;

/* Subroutine */ int acntr2_()
{
    /* Initialized data */

    static struct {
	char e_1[184];
	real e_2;
	} equiv_5 = { {'A', 'C', 'E', 'N', 'T', 'R', 'T', 'P', 'A', 'C', 'E', 
		'N', 'T', 'R', '0', '1', 'A', 'C', 'E', 'N', 'T', 'R', '0', 
		'2', 'A', 'C', 'E', 'N', 'T', 'R', '0', '3', 'A', 'C', 'E', 
		'N', 'T', 'R', '0', '4', 'A', 'C', 'E', 'N', 'T', 'R', '0', 
		'5', 'A', 'C', 'E', 'N', 'T', 'R', '0', '6', 'A', 'C', 'E', 
		'N', 'T', 'R', '0', '7', 'A', 'C', 'E', 'N', 'T', 'R', '0', 
		'8', 'A', 'C', 'E', 'N', 'T', 'R', '0', '9', 'A', 'C', 'E', 
		'N', 'T', 'R', '1', '0', 'A', 'C', 'E', 'N', 'T', 'R', '1', 
		'1', 'A', 'C', 'E', 'N', 'T', 'R', '1', '2', 'A', 'C', 'E', 
		'N', 'T', 'R', '1', '3', 'A', 'C', 'E', 'N', 'T', 'R', '1', 
		'4', 'A', 'C', 'E', 'N', 'T', 'R', 'E', 'X', 'A', 'C', 'E', 
		'N', 'T', 'R', '1', '5', 'A', 'C', 'E', 'N', 'T', 'R', '1', 
		'6', 'A', 'C', 'E', 'N', 'T', 'R', '1', '7', 'A', 'C', 'E', 
		'N', 'T', 'R', '1', '8', 'A', 'C', 'E', 'N', 'T', 'R', '1', 
		'9', 'A', 'C', 'E', 'N', 'T', 'R', '2', '0', 'A', 'C', 'E', 
		'N', 'T', 'R', '2', '1'}, (float)0. };

#define ab ((real *)&equiv_5)


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    extern /* Subroutine */ int aerr_();
    static doublereal ans;
    static integer its;
    static doublereal bns;
    extern /* Subroutine */ int avsub_(), avdot_(), avsto_(), acplan_(), 
	    avleng_(), adyndp_(), avnorm_(), avmult_(), atltst_();

/*     *** THIS PROGRAM HAS BEEN ADDED FOR VERSION 4, MODIFICATION 2 *** */
/*  ***  AND PARTITIONED FOR FORTRAN H COMPILER (180K)               BHC */

/* ... A2CMMN START */

/* ...                                    NEXT 1 CARD FOR SPLIT.      BHC */
/* ...                                    NEXT  7 CARDS FOR SPLIT.    BHC */

/* ...    ACENTR PARTITIONED AT BHC TO USE 180K COMPILER. */

/* ...    BRANCH BY IIN */

    switch ((int)acencm_1.iin) {
	case 1:  goto L50;
	case 2:  goto L72;
	case 3:  goto L91;
	case 4:  goto L302;
	case 5:  goto L8000;
    }

/* ... */
L50:
/* ...  ****************************************************** 15 ***** */
    adyndp_(&ab[32], &c__5, &c_b8);
/* ... */
    acplan_();
/* ... */
/* ...  ****************************************************** 16 ***** */
    adyndp_(&ab[34], &c__5, &c_b8);
/* ... */
    a2cmmn_1.it = a2cmmn_1.it;
    a2cmmn_1.iit = a2cmmn_1.iit;
/* L501: */
    if (a2cmmn_1.jcpr != 0) {
	goto L6;
    } else {
	goto L555;
    }
/* ... TANGENT CS STOPPING POSITION COULD NOT BE DETERMINED.  *** 906 *** */
L6:
    aerr_(&c__906);
L555:
    acencm_1.jta = 0;
/* L5: */
    if (a2cmmn_1.notan[a2cmmn_1.iis - 1] <= 0) {
	goto L51;
    } else {
	goto L71;
    }
L51:
    if (a2cmmn_1.plncs[a2cmmn_1.is - 1] >= 0.) {
	goto L53;
    } else {
	goto L52;
    }
L52:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    adyndp_(&ab[36], &c__5, &c_b8);
    ++acencm_1.kount;
    if (acencm_1.kount >= 50) {
	aerr_(&c_n910);
    }
    if (a2cmmn_1.istrup != 1 || a2cmmn_1.numsur != 3 || a2cmmn_1.isftyp[
	    a2cmmn_1.iics - 1] != 4 || acencm_1.kount < 25) {
	goto L25;
    }
    a2cmmn_1.jent[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.jtn[a2cmmn_1.iics - 1] = 1;
    goto L25;
L53:
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.it - 1], &ans)
	    ;
    if (abs(ans) > acencm_1.tanang) {
	goto L71;
    }
/* L55: */
    if ((d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.eps4[
	    a2cmmn_1.is - 1] <= 0.) {
	goto L56;
    } else {
	goto L59;
    }
L56:
    if (a2cmmn_1.j54 != 0) {
	goto L57;
    } else {
	goto L58;
    }
L57:
    a2cmmn_1.j54 = 0;
    goto L79;
L58:
    a2cmmn_1.j54 = 1;
L59:
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 0;
    goto L6000;
L6500:
    if (a2fpc_1.q1p5 - (d__1 = a2cmmn_1.cptst[a2cmmn_1.is - 1], abs(d__1)) >= 
	    0.) {
	goto L61;
    } else {
	goto L60;
    }
L60:
    ans = a2fpc_1.q1p;
    if (a2cmmn_1.cptst[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	ans = -a2fpc_1.q1p;
    }
    a2cmmn_1.cptst[a2cmmn_1.is - 1] -= ans;
    if (a2cmmn_1.plnd1[a2cmmn_1.is - 1] != 0.) {
	goto L62;
    } else {
	goto L61;
    }
L62:
    a2cmmn_1.pltst[a2cmmn_1.is - 1] = a2cmmn_1.plnd[a2cmmn_1.is - 1] / 
	    a2cmmn_1.plnd1[a2cmmn_1.is - 1];
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.tnk[a2cmmn_1.is - 1], &
	    ans);
    if (ans < a2fpc_1.qnul) {
	a2cmmn_1.pltst[a2cmmn_1.is - 1] = -a2cmmn_1.pltst[a2cmmn_1.is - 1];
    }
    if (a2fpc_1.qp9 - (d__1 = a2cmmn_1.pltst[a2cmmn_1.is - 1], abs(d__1)) >= 
	    0.) {
	goto L69;
    } else {
	goto L63;
    }
L63:
    if (a2cmmn_1.pltst[a2cmmn_1.is - 1] <= 0.) {
	goto L64;
    } else {
	goto L67;
    }
L64:
    a2cmmn_1.pltst[a2cmmn_1.is - 1] = -a2fpc_1.qp9;
L65:
    a2cmmn_1.plnd[a2cmmn_1.is - 1] *= a2fpc_1.q1p - (d__1 = a2cmmn_1.pltst[
	    a2cmmn_1.is - 1], abs(d__1));
L66:
    a2cmmn_1.plnd1[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    a2cmmn_1.jcnt1 = 25;
    adyndp_(&ab[38], &c__5, &c_b8);
    goto L70;
L67:
    a2cmmn_1.pltst[a2cmmn_1.is - 1] = a2fpc_1.qp9;
L68:
    a2cmmn_1.plnd[a2cmmn_1.is - 1] /= a2fpc_1.q1p - (d__1 = a2cmmn_1.pltst[
	    a2cmmn_1.is - 1], abs(d__1));
    goto L66;
L69:
    if (a2cmmn_1.pltst[a2cmmn_1.is - 1] <= 0.) {
	goto L65;
    } else {
	goto L68;
    }
L61:
    a2cmmn_1.plnd1[a2cmmn_1.is - 1] = a2cmmn_1.plnd[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.tnk[a2cmmn_1.is - 1]);
L70:
    if (a2cmmn_1.jcnt2 < 0) {
	goto L89;
    } else if (a2cmmn_1.jcnt2 == 0) {
	goto L6800;
    } else {
	goto L101;
    }
L101:
    if (acencm_1.icmvl == 0) {
	--a2cmmn_1.jcnt2;
    }
    if (a2cmmn_1.jcnt2 >= 6) {
	goto L1701;
    }
    if (a2cmmn_1.js != 1) {
	goto L1701;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) > a2cmmn_1.eps4[
	    a2cmmn_1.is - 1]) {
	goto L1701;
    }
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    ans = a2cmmn_1.plnd[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.plnv[a2cmmn_1.is - 1]);
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = a2fpc_1.qp5 * a2cmmn_1.s[a2cmmn_1.is - 1]
	    ;
    avsto_(a2cmmn_1.vtem, &a2cmmn_1.plnv[a2cmmn_1.it - 1]);
    a2cmmn_1.plnd[a2cmmn_1.it - 1] = ans;
    goto L1701;
L71:
    if ((d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.eps4[
	    a2cmmn_1.is - 1] <= 0.) {
	goto L72;
    } else {
	goto L59;
    }
L72:
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] <= 0) {
	goto L75;
    } else {
	goto L366;
    }
L75:
    ans = a2cmmn_1.rc[a2cmmn_1.is - 1] * a2cmmn_1.s[a2cmmn_1.is - 1];
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] == 0) {
	ans = -ans;
    }
    adyndp_(ab, &c__12, &c_b52);
    if (ans < 0.) {
	goto L73;
    } else if (ans == 0) {
	goto L765;
    } else {
	goto L74;
    }
L73:
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.eps8[
	    a2cmmn_1.is - 1] - a2fpc_1.qp5x05 <= 0.) {
	goto L765;
    } else {
	goto L359;
    }
L74:
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) - (a2cmmn_1.tau[
	    a2cmmn_1.is - 1] - a2cmmn_1.eps8[a2cmmn_1.is - 1] + 
	    a2fpc_1.qp5x05) <= 0.) {
	goto L765;
    } else {
	goto L359;
    }
L366:
    if (a2cmmn_1.itlon[a2cmmn_1.iis - 1] != 0) {
	goto L98765;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) < a2cmmn_1.tau1[
	    a2cmmn_1.is - 1]) {
	goto L766;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) < (d__2 = 
	    a2cmmn_1.tau2[a2cmmn_1.is - 1], abs(d__2))) {
	goto L766;
    }
    goto L359;
L98765:
    if (a2cmmn_1.s[a2cmmn_1.is - 1] >= 0.) {
	goto L367;
    } else {
	goto L368;
    }
L367:
    if (a2cmmn_1.s[a2cmmn_1.is - 1] - a2fpc_1.qp5x05 - a2cmmn_1.tau1[
	    a2cmmn_1.is - 1] <= 0.) {
	goto L765;
    } else {
	goto L359;
    }
L368:
    if (a2cmmn_1.s[a2cmmn_1.is - 1] + a2fpc_1.qp5x05 - a2cmmn_1.tau2[
	    a2cmmn_1.is - 1] >= 0.) {
	goto L765;
    } else {
	goto L359;
    }
L359:
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 != 0) {
	goto L2001;
    } else {
	goto L2002;
    }
L2001:
    if ((i__1 = a2cmmn_1.notan[a2cmmn_1.iis - 1]) < 0) {
	goto L1701;
    } else if (i__1 == 0) {
	goto L36;
    } else {
	goto L2002;
    }
L2002:
    if (a2fpc_1.q8p * a2cmmn_1.tau[a2cmmn_1.is - 1] - (d__1 = a2cmmn_1.s[
	    a2cmmn_1.is - 1], abs(d__1)) >= 0.) {
	goto L522;
    } else {
	goto L302;
    }
L522:
    if (a2cmmn_1.notan[a2cmmn_1.iis - 1] != 0) {
	goto L523;
    } else {
	goto L59;
    }
L523:
    a2cmmn_1.notan[a2cmmn_1.iis - 1] = -1;
    goto L1010;
L765:
    atltst_(&acencm_1.iret);
    if (acencm_1.iret == 0) {
	goto L766;
    }
    goto L359;
L766:
    if (a2cmmn_1.notan[a2cmmn_1.iis - 1] <= 0) {
	goto L41;
    } else {
	goto L201;
    }
L302:
    a2cmmn_1.jcr = 2;
    adyndp_(&ab[40], &c__5, &c_b8);
    goto L48;
L201:
    a2cmmn_1.j = 3;
    adyndp_(&ab[42], &c__5, &c_b8);
    goto L4004;
L79:
    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[a2cmmn_1.it - 1], 
	    a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ta, &a2cmmn_1.temp[1]);
    avmult_(a2cmmn_1.ta, &a2cmmn_1.temp[1], &a2cmmn_1.temp[2]);
    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.temp[2], &a2cmmn_1.temp[2]
	    );
    avsto_(&a2cmmn_1.tp[a2cmmn_1.it - 1], &a2cmmn_1.temp[5]);
    if (a2cmmn_1.ipl[a2cmmn_1.iit - 1] <= 0) {
	goto L81;
    } else {
	goto L83;
    }
L81:
    avsub_(&a2cmmn_1.temp[2], a2cmmn_1.te, &a2cmmn_1.vt[a2cmmn_1.it - 1]);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.it - 1]);
L83:
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] <= 0) {
	goto L84;
    } else {
	goto L85;
    }
L84:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.it - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
    a2cmmn_1.vt[a2cmmn_1.is - 1] = a2cmmn_1.temp[5] + a2cmmn_1.temp[1] * 
	    a2cmmn_1.ta[0] - a2cmmn_1.te[0];
    a2cmmn_1.vt[a2cmmn_1.is] = a2cmmn_1.temp[6] + a2cmmn_1.temp[1] * 
	    a2cmmn_1.ta[1] - a2cmmn_1.te[1];
    a2cmmn_1.vt[a2cmmn_1.is + 1] = a2cmmn_1.temp[7] + a2cmmn_1.temp[1] * 
	    a2cmmn_1.ta[2] - a2cmmn_1.te[2];
L85:
    ans = a2fpc_1.q1p;
    if (a2cmmn_1.cptst[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	ans = -ans;
    }
    a2cmmn_1.cptst[a2cmmn_1.is - 1] -= ans;
    adyndp_(&ab[44], &c__5, &c_b8);
    goto L11;
L91:
    ++acencm_1.kas905;
    if (acencm_1.kas905 > 5) {
	aerr_(&c_n905);
    }
    goto L4001;
/* ... 3 SURF ITERATION, TANTO OR PSTAN, AND PS OR DS TOL NOT MODIFIED. */
/* ... BRANCHED TO HERE AFTER ENTRY AND INITIALIZATION OF SOME VARIABLES */
/* ... IF ABOVE 3 CONDITIONS ARE MET. */
L8000:
    its = a2cmmn_1.ids;
    if (a2cmmn_1.ifl4[a2cmmn_1.iis - 1] == 1) {
	its = a2cmmn_1.ips;
    }
    if (a2cmmn_1.tau1[a2cmmn_1.is - 1] >= a2cmmn_1.tau1[its - 1]) {
	goto L8050;
    }
    if (a2cmmn_1.tau1[a2cmmn_1.is - 1] == a2fpc_1.qnul) {
	goto L8050;
    }
/* ...   CEND  = TOLERANCE MODIFICATION INDICATOR. */
/* ...   CEND(1) = 1  PS OR DS TOLERANCE WAS MODIFIED BY ACENTR. */
/* ...   CEND(1) NOT = 1  PS OR DS TOLERANCE WAS NOT MODIFIED. */
/* ...   IF CEND(1)=1, CEND(2) AND CEND(3) CONTAIN THE VALUES OF TAU1 AND */
/* ...   TAU2 BEFORE MODIFICATION. */
/* ... */
/* ...   CEND(1) SET TO 1 IF CS TAU1 IS LESS THAN DS(OR PS) TAU1 AND */
/* ...   CS TAU1 IS NOT ZERO. */
    a2cmmn_1.cend[0] = a2fpc_1.q1p;
    a2cmmn_1.cend[1] = a2cmmn_1.tau1[its - 1];
    a2cmmn_1.tau1[its - 1] = a2cmmn_1.tau1[a2cmmn_1.is - 1];
L8050:
    if ((d__1 = a2cmmn_1.tau2[a2cmmn_1.is - 1], abs(d__1)) >= (d__2 = 
	    a2cmmn_1.tau2[its - 1], abs(d__2))) {
	goto L8100;
    }
    if (a2cmmn_1.tau2[a2cmmn_1.is - 1] == a2fpc_1.qnul) {
	goto L8100;
    }
    a2cmmn_1.cend[0] += a2fpc_1.q2p;
    a2cmmn_1.cend[2] = a2cmmn_1.tau2[its - 1];
    a2cmmn_1.tau2[its - 1] = a2cmmn_1.tau2[a2cmmn_1.is - 1];
L8100:
    if (a2cmmn_1.cend[0] == a2fpc_1.qnul) {
	goto L8001;
    }
/* ...  DS(OR PS) TOLERANCE HAS BEEN MODIFIED ... ADJUST EPS */
    if (a2cmmn_1.ifl4[a2cmmn_1.iis - 1] == 1) {
	a2cmmn_1.cend[0] = -a2cmmn_1.cend[0];
    }
    a2cmmn_1.tau[its - 1] = a2cmmn_1.tau1[its - 1] - a2cmmn_1.tau2[its - 1];
    a2cmmn_1.eps1[its - 1] = a2fpc_1.qp1 * a2cmmn_1.tau[its - 1];
    a2cmmn_1.eps8[its - 1] = a2cmmn_1.eps1[its - 1];
    a2cmmn_1.eps2[its - 1] = a2fpc_1.q1p - a2cmmn_1.eps1[its - 1];
    a2cmmn_1.eps3[its - 1] = a2fpc_1.qp9 * a2cmmn_1.eps1[its - 1];
    a2cmmn_1.eps4[its - 1] = a2fpc_1.q2p * a2cmmn_1.tau[its - 1];
    a2cmmn_1.eps6[its - 1] = a2fpc_1.qp02 * a2cmmn_1.eps1[its - 1];
    goto L8001;
/* ... */
L6000:
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], a2cmmn_1.ti, &ans);
    ans *= a2cmmn_1.plnd[a2cmmn_1.is - 1];
    bns = ans;
    if (ans > a2fpc_1.qnul) {
	goto L6100;
    }
    if ((i__1 = abs(a2cmmn_1.itnflg) - 1) < 0) {
	goto L6010;
    } else if (i__1 == 0) {
	goto L6020;
    } else {
	goto L6050;
    }
L6010:
    a2cmmn_1.itnflg = -1;
    goto L6050;
L6020:
    if (a2cmmn_1.itnflg < 0) {
	goto L6050;
    }
    a2cmmn_1.itnflg = -2;
L6050:
    if ((d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1)) > a2cmmn_1.probuf[
	    16]) {
	goto L6400;
    }
    avsto_(a2cmmn_1.te, &a2cmmn_1.probuf[10]);
    avsto_(a2cmmn_1.ta, &a2cmmn_1.probuf[13]);
    a2cmmn_1.probuf[16] = (d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1));
    goto L6400;
L6100:
    if ((i__1 = abs(a2cmmn_1.itnflg) - 1) < 0) {
	goto L6110;
    } else if (i__1 == 0) {
	goto L6120;
    } else {
	goto L6150;
    }
L6110:
    a2cmmn_1.itnflg = 1;
    goto L6150;
L6120:
    if (a2cmmn_1.itnflg > 0) {
	goto L6150;
    }
    a2cmmn_1.itnflg = 2;
L6150:
    if ((d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1)) > a2cmmn_1.probuf[
	    6]) {
	goto L6400;
    }
    avsto_(a2cmmn_1.te, a2cmmn_1.probuf);
    avsto_(a2cmmn_1.ta, &a2cmmn_1.probuf[3]);
    a2cmmn_1.probuf[6] = (d__1 = a2cmmn_1.plnd[a2cmmn_1.is - 1], abs(d__1));
L6400:
    if (a2cmmn_1.js == 0) {
	goto L6500;
    }
/*      SPECIAL HALVING ALGORITHM */
    a2cmmn_1.jcnt1 = 25;
    if (bns > a2fpc_1.qnul) {
	goto L6700;
    }
    avsub_(a2cmmn_1.probuf, a2cmmn_1.te, a2cmmn_1.vtem);
    goto L6750;
L6700:
    avsub_(&a2cmmn_1.probuf[10], a2cmmn_1.te, a2cmmn_1.vtem);
L6750:
    avleng_(a2cmmn_1.vtem, &ans);
    avnorm_(a2cmmn_1.vtem, &a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.ier);
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = a2fpc_1.qp5 * ans;
    goto L70;
L6800:
    if (a2cmmn_1.js == 1) {
	goto L89;
    }
    if (abs(a2cmmn_1.itnflg) <= 1) {
	goto L89;
    }
    a2cmmn_1.js = 1;
    a2cmmn_1.jcnt2 = 25;
    avsto_(a2cmmn_1.probuf, a2cmmn_1.te);
    avsto_(&a2cmmn_1.probuf[3], a2cmmn_1.ta);
    goto L11;
/* ...    SET UP INDEX AND RETURN.        NEXT 23 CARDS FOR SPLIT.    BHC */
L11:
    acencm_1.iout = 1;
    goto L9000;
L25:
    acencm_1.iout = 2;
    goto L9000;
L41:
    acencm_1.iout = 3;
    goto L9000;
L48:
    acencm_1.iout = 4;
    goto L9000;
L89:
    acencm_1.iout = 5;
    goto L9000;
L1010:
    acencm_1.iout = 6;
    goto L9000;
L1701:
    acencm_1.iout = 7;
    goto L9000;
L4001:
    acencm_1.iout = 8;
    goto L9000;
L4004:
    acencm_1.iout = 9;
    goto L9000;
L8001:
    acencm_1.iout = 10;
    goto L9000;
L36:
    acencm_1.iout = 11;
L9000:
    return 0;
} /* acntr2_ */

#undef ab


