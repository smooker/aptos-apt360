/* ASEC2A.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal adentc, adent, adummy, ans;
} a2burp_;

#define a2burp_1 a2burp_

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
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

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
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

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

static integer c__41 = 41;
static integer c_n307 = -307;
static integer c__6 = 6;
static integer c__7 = 7;
static integer c__8 = 8;
static integer c__3 = 3;

/* Subroutine */ int asec2a_(istx1, istx2)
integer *istx1, *istx2;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int aerr_(), avadd_(), atape_(), avsub_(), avsto_(
	    ), avdot_(), astos_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     ***** */
    if (*istx1 == 1) {
	goto L5000;
    }
/*     SPECIAL TREATMENT OF CODES 5000,6000,7000,8000,AND 11000 IN RESTRT */


/*     IN THE RESTART MODE, THERE ARE SEVERAL */
/*      VALID RESTART CONDITIONS */
/*     1. ANY FROM POINT */
/*      2. A GO TO/ FOLLOWED BY */
/*            A) ANOTHER GO TO/ */
/*            B)A GO DELTA NOT ALONG THE TOOL AXIS */
/*            C) AN INDIR FOR THE DRIVE SRFACE */
/*            D A GO/ STATEMENT */
/*     3. ANY POCKET */

/*      NOTE... THE USEFULNESS OF THE GO TO/ IN RESTARTING  IS WIPED OUT */
/*               AN INTERVENING MOTION COMMAND OF THE TYPE GOXX/ */
/*             OR A TRANTO, OR A MULTICS TRANTO */
/*      THE FOLLOWING CODE SETS IGTFLG = 1 WHENEVER A USEABLE GO */
/*      IS IN EFFECT, RESTARTS UNDER THE STATED CONDITIONS, AND */
/*      WIPES OUT THE IGTFLG AS DESCRIBED */
/*      GO DELTA AND INDIR VECTORS ARE CHECKED TO SEE THAT THEY DO NOT */
/*      LIE ALONG THE CUTTER AXIS */

/*     IS THIS A FROM -IF SO, CAN RESTART HERE */
/* L5300: */
    if (a2cmmn_.instr2 != 3) {
	goto L5301;
    }
/*     IS A FROM, RESET MODE AND IRSTRT */
    a2cmmn_.isrch = 1;
    a2cmmn_.igtflg = 0;
    goto L5000;
L5301:
    switch ((int)a2cmmn_.instr2) {
	case 1:  goto L5310;
	case 2:  goto L5320;
	case 3:  goto L5330;
	case 4:  goto L5340;
	case 5:  goto L5350;
	case 6:  goto L5360;
    }
/*      BRANCH ON TYPE OF RECORD */
/*      INDIRP */
L5310:
    if (a2cmmn_.igtflg != 1 || a2cmmn_.probuf[0] == a2burp_1.adummy) {
	goto L200;
    }
    avsub_(a2cmmn_.te, &a2cmmn_.probuf[2], a2cmmn_.vtem);
    goto L5345;
/*     INDIRV */
L5320:
    if (a2cmmn_.igtflg != 1 || a2cmmn_.probuf[0] == a2burp_1.adummy) {
	goto L200;
    }
    avsto_(&a2cmmn_.probuf[2], a2cmmn_.vtem);
    goto L5345;
/*   STATEMENT SHOULD NEVER BE REACHED */
L5330:
    aerr_(&c__41);
/*      GO DELTA */
L5340:
    if (a2cmmn_.igtflg != 1 || a2cmmn_.nwds == 3) {
	goto L200;
    }
    avsto_(&a2cmmn_.probuf[2], a2cmmn_.vtem);
L5345:
    avnorm_(a2cmmn_.vtem, a2cmmn_.vtem, &a2cmmn_.ier);
    if (a2cmmn_.ier == 1) {
	goto L5000;
    }
    avdot_(a2cmmn_.vtem, a2cmmn_.ta, &a2burp_1.ans);
    if (abs(a2burp_1.ans) > a2fpc_1.qp4x95) {
	goto L5000;
    }
/*   RESTART RIGHT HERE */
    a2cmmn_.isrch = 1;
    a2cmmn_.igtflg = 0;
    a2cmmn_.irstrt = 0;
    goto L5000;
/*      GO TO/    IF THIS IS THE SECOND IN A ROW, RESTART HERE */
/*      IF NOT, SET THE IGTFLG TO SHOW THAT THERE IS A USEABLE GO */
L5350:
    if (a2cmmn_.igtflg == 1) {
	goto L5355;
    }
    a2cmmn_.igtflg = 1;
    goto L5000;
L5355:
    a2cmmn_.isrch = 1;
    a2cmmn_.igtflg = 0;
    goto L5000;
/*      WARNING, COMPUTED CUTTER CENTERS ON PROTAPE */
L5360:
    aerr_(&c_n307);
L2000:
    *istx2 = a0con_1.k2;
    return 0;
L200:
    *istx2 = a0con_1.k1;
    return 0;
/*     5000 */
L5000:
    switch ((int)a2cmmn_.instr2) {
	case 1:  goto L5010;
	case 2:  goto L5010;
	case 3:  goto L5030;
	case 4:  goto L5040;
	case 5:  goto L5050;
	case 6:  goto L5060;
	case 7:  goto L200;
	case 8:  goto L5010;
    }
/*     INDIRP,INDIRV,SRFVCT HAVE SAME FORMAT */
/*     J INDEXES SURFACE, */
/*     K POINTS TO APPROPRIATE PROBUF WORD */
L5010:
    a2cmmn_.j = 0;
    a2cmmn_.k = -4;
L5011:
    ++a2cmmn_.j;
    a2cmmn_.k += 5;
    switch ((int)a2cmmn_.j) {
	case 1:  goto L5013;
	case 2:  goto L5012;
	case 3:  goto L5014;
	case 4:  goto L200;
    }
L5012:
    a2cmmn_.it = a2cmmn_.ips;
    a2cmmn_.iit = a2cmmn_.iips;
    goto L5015;
L5013:
    a2cmmn_.it = a2cmmn_.ids;
    a2cmmn_.iit = a2cmmn_.iids;
    goto L5015;
L5014:
    a2cmmn_.it = a2cmmn_.ics;
    a2cmmn_.iit = a2cmmn_.iics;
/*     IF NO INFO GIVEN FOR THIS SURFACE, THE NAME IDUMMY WILL APPEAR */
L5015:
    if (a2cmmn_.probuf[a2cmmn_.k - 1] == a2burp_1.adummy) {
	goto L5011;
    }
/*     SEPARATE INDIRP(1),INDIRV(2) AND SRFVCT(8) */
    if ((i__1 = a2cmmn_.instr2 - 2) < 0) {
	goto L5020;
    } else if (i__1 == 0) {
	goto L5021;
    } else {
	goto L5022;
    }
/*     INDIRP */
/*     SET UP UNDIR VECTOR */
L5020:
    for (i__ = 1; i__ <= 3; ++i__) {
	a2cmmn_.next1 = a2cmmn_.it + i__ - 1;
	a2cmmn_.next2 = a2cmmn_.k + i__ + 1;
/* L5019: */
	a2cmmn_.vndir[a2cmmn_.next1 - 1] = a2cmmn_.probuf[a2cmmn_.next2 - 
		1] - a2cmmn_.te[i__ - 1];
    }
    avnorm_(&a2cmmn_.vndir[a2cmmn_.it - 1], &a2cmmn_.vndir[a2cmmn_.it - 1]
	    , &a2cmmn_.ier);
    if (a2cmmn_.ier == 0) {
	goto L5025;
    }
    aerr_(&c__6);
L5025:
    a2cmmn_.indir__[a2cmmn_.iit - 1] = 1;
    if (a2cmmn_.it != a2cmmn_.ids) {
	goto L5011;
    }
    avsto_(&a2cmmn_.vndir[a2cmmn_.it - 1], a2cmmn_.ti);
    avsub_(a2cmmn_.te, &a2cmmn_.vndir[a2cmmn_.it - 1], a2cmmn_.tek);
    goto L5011;
/*       INDIRV */
L5021:
    avnorm_(&a2cmmn_.probuf[a2cmmn_.k + 1], &a2cmmn_.vndir[a2cmmn_.it - 1]
	    , &a2cmmn_.ier);
    if (a2cmmn_.ier == 0) {
	goto L5025;
    }
    aerr_(&c__7);
/*     SRFVCT */
L5022:
    avnorm_(&a2cmmn_.probuf[a2cmmn_.k + 1], &a2cmmn_.sfvct[a2cmmn_.it - 1]
	    , &a2cmmn_.ier);
    if (a2cmmn_.ier != 0) {
	goto L5026;
    }
    a2cmmn_.isvfl[a2cmmn_.iit - 1] = 1;
    goto L5011;
L5026:
    aerr_(&c__8);


/*     FROM POINT - ZERO OUT PREVIOUS CUTTER POSITION */
L5030:
    avsto_(a2cmmn_.vnul, a2cmmn_.tek);
/*      SET UP TYPE CODE ICL FRO ATAPE */
    a2cmmn_.icl = 3;
/*     SET CURRENT CUTTER LOCATION TO GIVEN POINT */
    avsto_(&a2cmmn_.probuf[2], a2cmmn_.te);
/*     SET UP NAME + SUBSCRIPT OF POINT */
L5035:
    a2cmmn_.abcd[0] = a2cmmn_.probuf[0];
    a2cmmn_.abcd[1] = a2cmmn_.probuf[1];
/*     GOTO COMMON AREA TO CHECK IF AXIS GIVEN AND UPDATE PMOVE */
    goto L5100;

/*     GODLTA/V, GODLTA/N */
L5040:
/*      SET UP CL TAPE TYPE  ODE FOR ATAPE */
    a2cmmn_.icl = 5;
/*     SEE IF ONE PARAMETER OR 3 GIVEN BUT FIRST UPDATE TEK */
    avsto_(a2cmmn_.te, a2cmmn_.tek);
    if (a2cmmn_.nwds > 3) {
	goto L5045;
    }
/*     NO MOVE IS ALONG AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L5041: */
	a2cmmn_.te[i__ - 1] += a2cmmn_.probuf[2] * a2cmmn_.ta[i__ - 1];
    }
/*     GO TO COMMON AREA TO CHECK TLAX + UPDATE PMOVE (WONT BE UPDATED IN */
/*     THIS CASE BECAUSE MOVE IS ALONG AXIS */
    goto L5035;
/*     YES, MOVE IS VECTOR */
L5045:
    avadd_(&a2cmmn_.probuf[2], a2cmmn_.te, a2cmmn_.te);
    goto L5035;


/*     GO TO POINT - UPDATE TEK (PREVIOUS CUTTER LOCATION) */
L5050:
    avsto_(a2cmmn_.te, a2cmmn_.tek);
    a2cmmn_.icl = 5;
/*     UPDATE CUTTER LOCATION */
    avsto_(&a2cmmn_.probuf[2], a2cmmn_.te);
/*     GO CHECK TOOL AXIS ETC */
    goto L5035;

/*     SERIES OF POINTS - OUTPUT TO CLTAPE WITH WARNING */
L5060:
    aerr_(&c_n307);
    goto L2000;


/*     COMMON AREA NWDS INDICATES WHETHER TOOL AXIS WAS GIVEN ON INPUT */
/*     STATEMENT IF SO, SAVE OLD AND STORE NEW. SET UP TI VECTOR AS UNIT */
/*     VECTOR IN MOVEMENT DIRECTION, UPDATE PMOVE UNLESS MOVE IS ALONG */
/*     TOOL AXIS, AND OUTPUT POINT. */
L5100:
    if (a2cmmn_.nwds <= 5) {
	goto L5110;
    }
/*     TOOL AXIS GIVEN - SAVE OLD */
/* L5102: */
    avsto_(a2cmmn_.ta, a2cmmn_.tak);
/*     STORE NEW */
    a2cmmn_.multax = 0;
    a2cmmn_.numax = 3;
    a2cmmn_.icc = 0;
    if (a2cmmn_.instr1 != 5000) {
	goto L10;
    }
    if (a2cmmn_.instr2 != 4) {
	goto L10;
    }
    if (a2cmmn_.nwds == 6) {
	goto L5110;
    }
L10:
    avsto_(&a2cmmn_.probuf[5], a2cmmn_.ta);
    avnorm_(a2cmmn_.ta, a2cmmn_.ta, &a2cmmn_.ier);
    if (a2cmmn_.ier == 0) {
	goto L5110;
    }
    aerr_(&c__3);

/*     SET UP TI */
L5110:
    avsub_(a2cmmn_.te, a2cmmn_.tek, a2cmmn_.ti);
    avnorm_(a2cmmn_.ti, a2cmmn_.ti, &a2cmmn_.ier);
/*     INSERT ERROR TEST HERE */
    if (a2cmmn_.ier == 1) {
	goto L5112;
    }
    avdot_(a2cmmn_.ti, a2cmmn_.ta, &a2burp_1.ans);
    if (abs(a2burp_1.ans) <= a2fpc_1.qp997) {
	avsto_(a2cmmn_.ti, a2cmmn_.pmove);
    }
/*     OUTPUT CUTTER LOCATION AND GO READ PROTAP */
L5112:
    a2cmmn_.nw = 0;
    astos_();
    atape_();
    goto L200;
} /* asec2a_ */

#undef tlldat
#undef cosl
#undef sinl


