/* ACENTR.f -- translated by f2c (version 20000121).
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

struct {
    integer j51ckp, j51ckd;
    doublereal rvrsu1[6];
} cntru1_;

#define cntru1_1 cntru1_

/* Table of constant values */

static integer c__3 = 3;
static integer c_b3 = 111100;
static integer c__5 = 5;
static integer c_b9 = 110000;
static integer c__902 = 902;
static integer c_n906 = -906;
static integer c__907 = 907;
static integer c_n901 = -901;
static integer c__904 = 904;
static integer c__903 = 903;

/* Subroutine */ int acentr_()
{
    /* Initialized data */

    static struct {
	char e_1[184];
	real e_2;
	} equiv_21 = { {'A', 'C', 'E', 'N', 'T', 'R', 'T', 'P', 'A', 'C', 'E',
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

#define ab ((real *)&equiv_21)


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__;
    static doublereal aa2;
    static integer k51ckd, kfl602, jtrc;
    extern /* Subroutine */ int amind_(), aerr_(), avadd_();
    static doublereal ans;
    static integer k51ckp, issto;
    extern /* Subroutine */ int avsto_(), avsub_(), avdot_(), addst_();
    static integer itol, isave;
    extern /* Subroutine */ int acntr2_();
    static doublereal svu1tn[3], svu1tp[3];
    extern /* Subroutine */ int adyndp_();
    static integer nflunk;
    static doublereal cmvlst, reduce;
    static integer iissto;
    extern /* Subroutine */ int avmult_();
    static integer iisave;
    extern /* Subroutine */ int atltst_(), avcros_(), avnorm_(), atinkr_(), 
	    aplnex_(), avleng_();
    static integer kkplne, kknone;

/* ...  TO ITERATE THE CUTTER INTO A POSITION WITHIN THE SPECIFIED */
/* ...  TOLERANCE OF TWO OR THREE SURFACES. */
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ... A2CMMN START */

/* ... */
/* ...  ****************************************************** TP ***** */
    k51ckp = 0;
    k51ckd = 0;
    adyndp_(ab, &c__3, &c_b3);
    kfl602 = 0;
    a2cmmn_1.jw6 = 0;
    cmvlst = a2fpc_1.q1pe38;
    acencm_1.kas905 = 0;
    cntru1_1.j51ckp = 0;
    cntru1_1.j51ckd = 0;
    jtrc = 10;
    acencm_1.kount = 0;
    a2cmmn_1.itnflg = 0;
    a2cmmn_1.js = 0;
    a2cmmn_1.probuf[6] = a2fpc_1.q1pe6;
    a2cmmn_1.probuf[16] = a2fpc_1.q1pe6;
    if (a2cmmn_1.j51[a2cmmn_1.iis - 1] == 1 && a2cmmn_1.isftyp[a2cmmn_1.iis - 
	    1] == 4 && a2cmmn_1.cend[0] == a2fpc_1.qnul) {
	goto L8000;
    }
L8001:
    a2cmmn_1.jtkf = 0;
/* ... TANANG....CONVERGENCE CRITERIA FOR TOOL NORMALS IN TANGENT CS CASE */
    acencm_1.tanang = a2fpc_1.q1p - a2fpc_1.qp5 * a2cmmn_1.tau[a2cmmn_1.is - 
	    1];
    if (acencm_1.tanang > a2fpc_1.qp4x95) {
	acencm_1.tanang = a2fpc_1.qp4x95;
    }
    if (acencm_1.tanang < a2fpc_1.qp999) {
	acencm_1.tanang = a2fpc_1.qp4x95;
    }
/* ... CPLFL .. INDICATOR FROM ACPLAN ... =0 TO INITIALIZE ACPLAN */
/* ...          = -1 IF BOTH CS AND TANGENT SURFACE APPEAR TO BE PLANES. */
/* ...          = +1 IN ALL OTHER CASES. */
    a2cmmn_1.cplfl[a2cmmn_1.is - 1] = a2fpc_1.qnul;
/* ... CPTST .. COUNTER WHICH CONTROLS CALLING OF ACPLAN BY ACENTR. */
/* ...          ACPLAN IS CALLED EVERY OTHER PASS THRU 3 SURF ITERATION */
    a2cmmn_1.cptst[a2cmmn_1.is - 1] = a2fpc_1.qnul;
/* ...          J54 ... SWITCH TO ALTERNATE PLND CALCULATION IN TANGENT CS */
    a2cmmn_1.j54 = 0;
    acencm_1.jta = 1;
/* ... */
L1010:
    a2cmmn_1.jcnt1 = 25;
    a2cmmn_1.jcnt2 = 25;
    a2cmmn_1.jcnt3 = 25;
/* ... */
L11:
    issto = a2cmmn_1.is;
    iissto = a2cmmn_1.iis;
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
/* ...  ****************************************************** 01 ***** */
    adyndp_(&ab[2], &c__5, &c_b9);
    a2cmmn_1.jminr = 1;
    if (a2cmmn_1.istrup == 0) {
	a2cmmn_1.jminr = 0;
    }
    nflunk = 0;
    reduce = a2cmmn_1.dp;
    if (a2cmmn_1.jcnt3 == 10) {
	goto L70002;
    }
L512:
    amind_();
    goto L70001;
L70000:
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
/* ...  ****************************************************** 02 ***** */
    adyndp_(&ab[4], &c__5, &c_b9);
    a2cmmn_1.jminr = 1;
    if (a2cmmn_1.istrup == 0) {
	a2cmmn_1.jminr = 0;
    }
    nflunk = 0;
    reduce = a2cmmn_1.dp;
/* ... */
L514:
    amind_();
/* ... */
L70001:
    if (a2cmmn_1.jmin == 0) {
	goto L99999;
    }
L70002:
    ++nflunk;

    if (nflunk > 4) {
	aerr_(&c__902);
    }
    reduce = a2fpc_1.qp5 * reduce;
    avmult_(a2cmmn_1.tik, &reduce, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.tek, a2cmmn_1.vtem, a2cmmn_1.te);
    avsto_(&a2cmmn_1.tnk[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.tpk[a2cmmn_1.is - 1], &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    goto L514;


L99999:
    if (k51ckp > 5 || k51ckd > 5) {
	goto L99998;
    }
    if (a2cmmn_1.j24[a2cmmn_1.iis - 1] != 2 || a2cmmn_1.rc[a2cmmn_1.is - 1] > 
	    a2fpc_1.qnul) {
	goto L99998;
    }
    if (a2cmmn_1.istrup == 1) {
	goto L99998;
    }
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], svu1tn);
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], svu1tp);
    aa2 = a2cmmn_1.s[a2cmmn_1.is - 1];
    i__ = a2cmmn_1.iop[a2cmmn_1.iis - 1];

    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.te, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.ta, a2cmmn_1.vtem, &ans);
    avmult_(a2cmmn_1.ta, &ans, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.u1[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
    addst_();
    if (a2cmmn_1.ier != 0) {
	goto L99997;
    }
    if (a2cmmn_1.s[a2cmmn_1.is - 1] >= a2fpc_1.qnul) {
	goto L99997;
    }
    if (a2cmmn_1.is == a2cmmn_1.ids) {
	goto L99996;
    }
    cntru1_1.j51ckp = a2cmmn_1.ips;
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.u1[a2cmmn_1.is - 1], cntru1_1.rvrsu1);
    ++k51ckp;
    goto L512;
L99996:
    cntru1_1.j51ckd = a2cmmn_1.ids;
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.u1[a2cmmn_1.is - 1], &cntru1_1.rvrsu1[3]);
    ++k51ckd;
    goto L514;
L99997:
    avsto_(svu1tn, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(svu1tp, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    a2cmmn_1.s[a2cmmn_1.is - 1] = aa2;
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = i__;
L99998:
    if (a2cmmn_1.is == a2cmmn_1.ips) {
	goto L70000;
    }
    a2cmmn_1.is = issto;
    a2cmmn_1.iis = iissto;
    a2cmmn_1.jminr = 0;

/* L12: */
    avsto_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.plnv[a2cmmn_1.ips - 1]);
    a2cmmn_1.plnd[a2cmmn_1.ips - 1] = a2cmmn_1.s[a2cmmn_1.ips - 1];
    avsto_(&a2cmmn_1.sn[a2cmmn_1.ids - 1], &a2cmmn_1.plnv[a2cmmn_1.ids - 1]);
    a2cmmn_1.plnd[a2cmmn_1.ids - 1] = a2cmmn_1.s[a2cmmn_1.ids - 1];
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.tn[a2cmmn_1.ips - 1], &
	    ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.plnv[a2cmmn_1.ips - 1], &
		a2cmmn_1.plnv[a2cmmn_1.ips - 1]);
    }
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.ids - 1], &a2cmmn_1.tn[a2cmmn_1.ids - 1], &
	    ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.plnv[a2cmmn_1.ids - 1], &
		a2cmmn_1.plnv[a2cmmn_1.ids - 1]);
    }
/* ... */
    cntru1_1.j51ckp = 0;
    cntru1_1.j51ckd = 0;
    k51ckp = 0;
    k51ckd = 0;
/* L13: */
    if (a2cmmn_1.j50[a2cmmn_1.iis - 1] <= 0) {
	goto L15;
    } else {
	goto L25;
    }
/* ... */
/* ... TWO SURFACE ITERATION  ..... NOTE  J = 1 */
L15:
    a2cmmn_1.j = 1;
/* ***** */
/*     NOTE INDEXING----- */
/* ***** */
/* ... THIS LOOP CHECKS TO SEE IF S(IPS) AND S(IDS) ARE BOTH LESS THAN OR */
/* ... EQUAL TO .1 OF TOLERANCE.  IF SO, YOU WILL SEE TWO ACENTR03 ON THE */
/* ... DYNDMP LISTING. THEN CALL ATLTST TO VERIFY. */
/* ... ONLY OTHER EXIT FROM THIS LOOP IS TO 4005. THIS HAPPENS WHEN ONE */
/* ... OR BOTH SURFACE(S) DOES NOT MEET ABOVE TEST. THEN SETUP PSEUDO */
/* ... CS PLANE, CALL APLNEX TO MOVE THE CUTTER CLOSER TO TWO SURFACES. */
/* ... IF APLNEX OPERATION IS SUCCESSFUL, CALL AMIND FOR PS AND DS, DO */
/* ... THE TOLERANCE TEST, IF OK, SET JCR=0 AND RETURN. IF NOT, TRY THE */
/* ... ITERATION OVER(MAX. 25 TIMES). */
L4004:
    i__1 = a2cmmn_1.ids;
    i__2 = a2cmmn_1.lsv;
    for (i__ = a2cmmn_1.ips; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += 
	    i__2) {
	a2cmmn_1.k = (i__ - a2cmmn_1.ips) / a2cmmn_1.lsv * a2cmmn_1.lisv + 1;
/* ... JS SET = TO 0 AT ENTRY. AND SET = TO 1 WHEN JCNT2(COUNTER FOR */
/* ... TANGENT CS LOOP) IS EXHAUSTED. */
	if (a2cmmn_1.js == 1) {
	    goto L4011;
	}
	if (a2cmmn_1.ipl[a2cmmn_1.k - 1] <= 0) {
	    goto L4012;
	} else {
	    goto L4003;
	}
L4012:
	if ((d__1 = a2cmmn_1.s[i__ - 1], abs(d__1)) - a2cmmn_1.tau[i__ - 1] >=
		 0.) {
	    goto L4005;
	} else {
	    goto L4011;
	}
L4003:
	if (a2cmmn_1.itlon[a2cmmn_1.k - 1] != 0) {
	    goto L13579;
	}
	if ((d__1 = a2cmmn_1.s[i__ - 1], abs(d__1)) < a2cmmn_1.tau1[i__ - 1]) 
		{
	    goto L4011;
	}
	if ((d__1 = a2cmmn_1.s[i__ - 1], abs(d__1)) < (d__2 = a2cmmn_1.tau2[
		i__ - 1], abs(d__2))) {
	    goto L4011;
	}
	goto L4005;
L13579:
	if ((d__1 = a2cmmn_1.s[i__ - 1]) < 0.) {
	    goto L4006;
	} else if (d__1 == 0) {
	    goto L4011;
	} else {
	    goto L4007;
	}
L4006:
	if (a2cmmn_1.s[i__ - 1] - a2fpc_1.qp1 * a2cmmn_1.tau2[i__ - 1] + 
		a2fpc_1.qp5x01 >= 0.) {
	    goto L4011;
	} else {
	    goto L4005;
	}
L4007:
	if (a2cmmn_1.s[i__ - 1] - a2fpc_1.qp1 * a2cmmn_1.tau1[i__ - 1] - 
		a2fpc_1.qp5x01 <= 0.) {
	    goto L4011;
	} else {
	    goto L4005;
	}
L4011:
	adyndp_(&ab[6], &c__5, &c_b9);
    }
/* ... */
    itol = 0;
    isave = a2cmmn_1.is;
    iisave = a2cmmn_1.iis;
/* ... */
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    atltst_(&acencm_1.iret);
/* ... */
    itol += acencm_1.iret;
/* ... */
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    atltst_(&acencm_1.iret);
/* ... */
    itol += acencm_1.iret;
    a2cmmn_1.is = isave;
    a2cmmn_1.iis = iisave;
/* ... */
    if (itol != 0) {
	goto L4005;
    }
/* ... WITHIN TOLERANCE OF PS AND DS.  ** SMILE ** */
/* ... REMEMBER J=1 WHEN J50=0 */
    switch ((int)a2cmmn_1.j) {
	case 1:  goto L25;
	case 2:  goto L72;
	case 3:  goto L41;
    }
/* ... OUT OF TOLERANCE OF PS OR DS(OR BOTH) */
L4005:
    switch ((int)a2cmmn_1.j) {
	case 1:  goto L17;
	case 2:  goto L2036;
	case 3:  goto L302;
    }
L17:
    avcros_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.plnv[a2cmmn_1.ids - 1]
	    , &a2cmmn_1.plnv[a2cmmn_1.is - 1]);
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.plnv[a2cmmn_1.is - 1], 
	    &a2cmmn_1.ier);
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = a2fpc_1.qnul;
    adyndp_(&ab[8], &c__5, &c_b9);
    if (a2cmmn_1.multax == 0) {
	goto L1701;
    }
/* L1751: */
    atinkr_();
    a2cmmn_1.jw6 = 1;
    if (a2cmmn_1.jtr < 0) {
	goto L1756;
    } else if (a2cmmn_1.jtr == 0) {
	goto L1752;
    } else {
	goto L1701;
    }
L1752:
    if (acencm_1.jta != 0) {
	goto L1753;
    } else {
	goto L1754;
    }
L1753:
    acencm_1.jta = 0;
    goto L11;
L1754:
    acencm_1.jta = 1;
L1701:
    aplnex_();
/* L1711: */
    if (a2cmmn_1.jpxr != 0) {
	goto L20;
    } else {
	goto L188;
    }
L20:
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.ips - 1], abs(d__1)) - (d__2 = a2cmmn_1.s[
	    a2cmmn_1.ids - 1], abs(d__2)) >= 0.) {
	goto L23;
    } else {
	goto L21;
    }
L23:
    i__ = a2cmmn_1.ips;
L22:
    avmult_(&a2cmmn_1.tn[i__ - 1], &a2cmmn_1.s[i__ - 1], a2cmmn_1.cmove);
    adyndp_(&ab[10], &c__5, &c_b9);
    goto L24;
L21:
    i__ = a2cmmn_1.ids;
    goto L22;
L24:
    a2cmmn_1.cmove[0] = a2fpc_1.qp9 * a2cmmn_1.cmove[0] + a2cmmn_1.plnd[
	    a2cmmn_1.is - 1] * a2cmmn_1.plnv[a2cmmn_1.is - 1];
    a2cmmn_1.cmove[1] = a2fpc_1.qp9 * a2cmmn_1.cmove[1] + a2cmmn_1.plnd[
	    a2cmmn_1.is - 1] * a2cmmn_1.plnv[a2cmmn_1.is];
    a2cmmn_1.cmove[2] = a2fpc_1.qp9 * a2cmmn_1.cmove[2] + a2cmmn_1.plnd[
	    a2cmmn_1.is - 1] * a2cmmn_1.plnv[a2cmmn_1.is + 1];
    goto L18;
L188:
    if ((i__2 = a2cmmn_1.jcnt1 - 10) < 0) {
	goto L189;
    } else if (i__2 == 0) {
	goto L191;
    } else {
	goto L18;
    }
L189:
    if ((i__2 = a2cmmn_1.jcnt1 - 5) < 0) {
	goto L190;
    } else if (i__2 == 0) {
	goto L191;
    } else {
	goto L18;
    }
L190:
    if (a2cmmn_1.jcnt1 - 3 != 0) {
	goto L18;
    } else {
	goto L191;
    }
L191:
    avmult_(a2cmmn_1.cmove, &a2fpc_1.qp5, a2cmmn_1.cmove);
L18:
    acencm_1.icmvl = 0;
    avleng_(a2cmmn_1.cmove, &ans);
    if (a2cmmn_1.jam == 1 && a2cmmn_1.ipdpl == 1) {
	goto L618;
    }
    if (ans <= a2cmmn_1.dpmax || ans >= cmvlst) {
	goto L618;
    }
    cmvlst = ans;
    avnorm_(a2cmmn_1.cmove, a2cmmn_1.cmove, &a2cmmn_1.ier);
    avmult_(a2cmmn_1.cmove, &a2cmmn_1.dpmax, a2cmmn_1.cmove);
    acencm_1.icmvl = 1;
L618:
    avadd_(a2cmmn_1.te, a2cmmn_1.cmove, a2cmmn_1.te);
    adyndp_(&ab[12], &c__5, &c_b9);
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans);
    if (a2cmmn_1.icscnt > 1 && a2cmmn_1.j51[a2cmmn_1.iis - 1] == 1 && ans >= 
	    a2cmmn_1.dp * 100.) {
	goto L4001;
    }
    if (a2cmmn_1.jcnt1 != 0) {
	goto L19;
    } else {
	goto L10;
    }
L19:
    if (acencm_1.icmvl == 0) {
	--a2cmmn_1.jcnt1;
    }
    goto L11;

/*     C2A */
L1756:
    aerr_(&c_n906);
    --jtrc;
    if (jtrc <= 0) {
	goto L1755;
    } else {
	goto L1701;
    }
/* ... */
L1755:
    aerr_(&c__907);
/* ... */
L10:
    if (a2cmmn_1.istrup != 1 || a2cmmn_1.numsur != 2) {
	goto L97531;
    }
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] + a2cmmn_1.ipl[a2cmmn_1.iids - 1] == 
	    2) {
	goto L97531;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iips - 1] + a2cmmn_1.isftyp[a2cmmn_1.iids - 
	    1] != 2) {
	goto L97531;
    }
    if (kfl602 != 0) {
	goto L97531;
    }
    avdot_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.sn[a2cmmn_1.ids - 1], &
	    ans);
    if (abs(ans) < a2fpc_1.qp9999) {
	goto L97531;
    }
    kfl602 = 1;
    if (a2cmmn_1.ipl[a2cmmn_1.iids - 1] == 1) {
	goto L97530;
    }
    kkplne = a2cmmn_1.ips;
    kknone = a2cmmn_1.ids;
    goto L97529;
L97530:
    kkplne = a2cmmn_1.ids;
    kknone = a2cmmn_1.ips;
L97529:
    avsub_(&a2cmmn_1.sp[kkplne - 1], &a2cmmn_1.cc[kknone - 1], a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, &a2cmmn_1.sn[kkplne - 1], &ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[kkplne - 1], a2cmmn_1.vtem);
    }
    avmult_(a2cmmn_1.vtem, &a2cmmn_1.rc[kknone - 1], a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.cc[kknone - 1], a2cmmn_1.vtem, a2cmmn_1.vtem);
    avsub_(a2cmmn_1.vtem, a2cmmn_1.tek, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.tek, a2cmmn_1.vtem, a2cmmn_1.te);
    goto L11;
L97531:
    if (a2cmmn_1.icscnt > 1 && a2cmmn_1.j51[a2cmmn_1.iis - 1] != 0) {
	goto L4001;
    }

    if (a2cmmn_1.jam != 0) {
	goto L87;
    } else {
	goto L870;
    }
L870:
    a2cmmn_1.eps8[a2cmmn_1.ips - 1] = a2fpc_1.q2p * a2cmmn_1.eps8[
	    a2cmmn_1.ips - 1];
    a2cmmn_1.eps8[a2cmmn_1.ids - 1] = a2fpc_1.q2p * a2cmmn_1.eps8[
	    a2cmmn_1.ids - 1];
    a2cmmn_1.eps8[a2cmmn_1.is - 1] = a2fpc_1.q2p * a2cmmn_1.eps8[a2cmmn_1.is 
	    - 1];
    a2cmmn_1.jam = 1;
    a2cmmn_1.jcnt1 = 25;
    adyndp_(&ab[14], &c__5, &c_b9);
    aerr_(&c_n901);
    goto L11;
L87:
    if (a2cmmn_1.j51[a2cmmn_1.iis - 1] != 0) {
	goto L4001;
    } else {
	goto L88;
    }
L88:
    a2cmmn_1.dp = a2fpc_1.qp6 * a2cmmn_1.dp;
    if (a2cmmn_1.dp - (d__1 = a2cmmn_1.tau[a2cmmn_1.is - 1], abs(d__1)) >= 0.)
	     {
	goto L4001;
    } else {
	goto L89;
    }
L89:
    if (a2cmmn_1.jcnt1 <= 0) {
	goto L90;
    } else {
	goto L91;
    }
L90:
    aerr_(&c__902);
L25:
    if (a2cmmn_1.j51[a2cmmn_1.iis - 1] != 0) {
	goto L26;
    } else {
	goto L4002;
    }
/* ...  3 SURFACE ITERATION BEGINS .... */
L26:
    a2cmmn_1.jminr = 1;
/* ...  ****************************************************** 08 ***** */
    adyndp_(&ab[16], &c__5, &c_b9);
/* ... */
    amind_();
/* ... */
/* ...  ****************************************************** 09 ***** */
    adyndp_(&ab[18], &c__5, &c_b9);
    a2cmmn_1.jminr = 0;
    if (a2cmmn_1.jmin <= 0) {
	goto L29;
    } else {
	goto L87;
    }
L29:
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 4 != 0) {
	goto L30;
    } else {
	goto L50;
    }
L30:
    if (a2cmmn_1.notan[a2cmmn_1.iis - 1] <= 0) {
	goto L31;
    } else {
	goto L9;
    }
L9:
    goto L50;
/* ... */
L31:
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = a2cmmn_1.s[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.plnv[a2cmmn_1.is - 1]);
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1], &
	    ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.plnv[
		a2cmmn_1.is - 1]);
    }
/* L34: */
    a2cmmn_1.j = 2;
    adyndp_(&ab[20], &c__5, &c_b9);
    goto L4004;
L2036:
    if (a2cmmn_1.notan[a2cmmn_1.iis - 1] >= 0) {
	goto L36;
    } else {
	goto L1701;
    }
L36:
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.ips - 1], &
	    ans);
    if (abs(ans) <= a2fpc_1.qp9999) {
	goto L37;
    }
/* L139: */
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.dp >= 0.) {
	goto L37;
    } else {
	goto L39;
    }
L39:
    a2cmmn_1.ifl4[a2cmmn_1.iis - 1] = 1;
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] + a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 2)
	     {
	goto L1701;
    }
    goto L40;
L37:
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.ids - 1], &
	    ans);
    if (abs(ans) <= a2fpc_1.qp9999) {
	goto L1701;
    }
/* L138: */
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.dp >= 0.) {
	goto L1701;
    } else {
	goto L38;
    }
L38:
    a2cmmn_1.ifl4[a2cmmn_1.iis - 1] = 0;
    if (a2cmmn_1.ipl[a2cmmn_1.iids - 1] + a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 2)
	     {
	goto L1701;
    }
L40:
    a2cmmn_1.notan[a2cmmn_1.iis - 1] = 1;
    adyndp_(&ab[22], &c__5, &c_b9);
    goto L11;
L4002:
    a2cmmn_1.jcr = 0;
    goto L4101;
L4001:
    a2cmmn_1.jcr = -1;
    goto L47;
L41:
    a2cmmn_1.jcr = 1;
L4101:
    if (a2cmmn_1.multax == 0) {
	goto L47;
    }
/* L42: */
/* ...  ****************************************************** 12 ***** */
    adyndp_(&ab[24], &c__5, &c_b9);
/* ... */
    atinkr_();
/* ... */
/* ...  ****************************************************** 13 ***** */
    adyndp_(&ab[26], &c__5, &c_b9);
/* ... */
    a2cmmn_1.jw6 = 1;
    if (a2cmmn_1.jtr < 0) {
	goto L43;
    } else if (a2cmmn_1.jtr == 0) {
	goto L44;
    } else {
	goto L47;
    }
/* ... COULD NOT DETERMINE NEW TA DURING 5-AXIS CALCULATION.  *** 904 *** */
L43:
    aerr_(&c__904);
L44:
    if (a2cmmn_1.jcnt3 >= 0) {
	goto L45;
    } else {
	goto L46;
    }
/* ... 5-AXIS ITERATION DID NOT CONVERGE.                     *** 903 *** */
L46:
    aerr_(&c__903);
/* ... */
L45:
    --a2cmmn_1.jcnt3;
    a2cmmn_1.jcnt2 = 25;
    a2cmmn_1.jcnt1 = 25;
/* ...  ****************************************************** 14 ***** */
    adyndp_(&ab[28], &c__5, &c_b9);
/* ... */
    goto L11;
/* ... */
L47:
    if (a2cmmn_1.j51[a2cmmn_1.iis - 1] != 0) {
	goto L48;
    } else {
	goto L49;
    }
L48:
    a2cmmn_1.j50[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j51[a2cmmn_1.iis - 1] = 0;
L49:
    if (a2cmmn_1.jam != 0) {
	goto L1001;
    } else {
	goto L1000;
    }
L1001:
    a2cmmn_1.jam = 0;
    a2cmmn_1.eps8[a2cmmn_1.ips - 1] = a2cmmn_1.eps1[a2cmmn_1.ips - 1];
    a2cmmn_1.eps8[a2cmmn_1.ids - 1] = a2cmmn_1.eps1[a2cmmn_1.ids - 1];
    a2cmmn_1.eps8[a2cmmn_1.is - 1] = a2cmmn_1.eps1[a2cmmn_1.is - 1];
L1000:
    a2cmmn_1.notan[a2cmmn_1.iis - 1] = 0;
/* ...  ****************************************************** EX ***** */
    adyndp_(&ab[30], &c__3, &c_b3);
/* .... */
    return 0;
/* ... */
/* ...                NEXT 15 CARDS FOR SPLIT.  BHC */
/* ...  ACENTR PARTITIONED AT BHC TO USE 180K COMPILER */
/* ...  SET UP BRANCHING INDEX 'IIN', THEN CALL ACNTR2 */

L50:
    acencm_1.iin = 1;
    goto L9000;
/* ... */
L72:
    acencm_1.iin = 2;
    goto L9000;
L91:
    acencm_1.iin = 3;
    goto L9000;
L302:
    acencm_1.iin = 4;
    goto L9000;
L8000:
    acencm_1.iin = 5;
L9000:
    acntr2_();
    switch ((int)acencm_1.iout) {
	case 1:  goto L11;
	case 2:  goto L25;
	case 3:  goto L41;
	case 4:  goto L48;
	case 5:  goto L89;
	case 6:  goto L1010;
	case 7:  goto L1701;
	case 8:  goto L4001;
	case 9:  goto L4004;
	case 10:  goto L8001;
	case 11:  goto L36;
    }
} /* acentr_ */

#undef ab


