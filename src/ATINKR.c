/* ATINKR.f -- translated by f2c (version 20000121).
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

static integer c__10 = 10;
static integer c_b3 = 111111;
static integer c__850 = 850;
static integer c__851 = 851;
static integer c__8 = 8;
static integer c__4 = 4;
static integer c__852 = 852;
static integer c__1 = 1;
static integer c__853 = 853;
static integer c__854 = 854;
static integer c__855 = 855;
static integer c__856 = 856;
static integer c_n857 = -857;
static integer c__861 = 861;
static integer c_n858 = -858;
static integer c__859 = 859;

/* Subroutine */ int atinkr_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_34 = { {'A', 'T', 'I', 'N', 'K', 'R', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_34)


    /* Builtin functions */
    double sqrt(), cos(), sin();

    /* Local variables */
#define v1 ((doublereal *)&a2cmmn_1 + 1354)
#define v2 ((doublereal *)&a2cmmn_1 + 1357)
#define vc ((doublereal *)&a2cmmn_1 + 1360)
    static integer ii, kk, ii1;
#define aii ((doublereal *)&a2cmmn_1 + 1334)
#define slx1 ((doublereal *)&a2cmmn_1 + 1348)
#define slx2 ((doublereal *)&a2cmmn_1 + 1351)
#define vnc ((doublereal *)&a2cmmn_1 + 1363)
#define ans ((doublereal *)&a2cmmn_1 + 1327)
#define ans1 ((doublereal *)&a2cmmn_1 + 1328)
#define ans2 ((doublereal *)&a2cmmn_1 + 1329)
#define aiii ((doublereal *)&a2cmmn_1 + 1335)
    extern /* Subroutine */ int aerr_();
    static doublereal ssav;
    extern /* Subroutine */ int avadd_();
    static integer iii;
#define tpsav ((doublereal *)&a2cmmn_1 + 1366)
#define tnsav ((doublereal *)&a2cmmn_1 + 1369)
#define spsav ((doublereal *)&a2cmmn_1 + 1372)
#define snsav ((doublereal *)&a2cmmn_1 + 1375)
    static integer jtnps, jtnds;
    extern /* Subroutine */ int avsto_(), avdot_(), avsub_();
    static integer issav;
    extern /* Subroutine */ int addst_(), astor_();
#define cosbta ((doublereal *)&a2cmmn_1 + 1330)
    extern /* Subroutine */ int anrmal_();
#define cosalp ((doublereal *)&a2cmmn_1 + 1331)
#define costhe ((doublereal *)&a2cmmn_1 + 1332)
#define sndssv ((doublereal *)&a2cmmn_1 + 1381)
#define sinthe ((doublereal *)&a2cmmn_1 + 1333)
    extern /* Subroutine */ int adyndp_();
    static integer ksconv;
    extern /* Subroutine */ int avmult_();
    static integer iissav;
#define snpssv ((doublereal *)&a2cmmn_1 + 1378)
    static integer iopsav;
    extern /* Subroutine */ int afwdsl_(), atisel_(), avcros_(), avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/* ... */
/*      PROCESS MULTI AXIS PART PROGRAMS */
/*      INPUT VALUES */
/*     NUMAX = 3      3AXIS */
/*     NUMAX = 4      4AXIS */
/*     NUMAX = 5      5AXIS */
/*     MULTAX = 1     NORMPS OR NORMDS */
/*     MULTAX = 2     PARALLEL TO RULINGS OF RULED SURFACE */
/*     MULTAX = 3     GENERSL FOUR OR FIVE AXIS CASE */
/*      ICC   = 1 IF PS CONTROL, =2 IF DS CONTROL */
/* ....... */
    adyndp_(ab, &c__10, &c_b3);

/* ...  TEST INPUT FLAGS AND BRANCH TO APPROPRIATE AREA */

    jtnps = a2cmmn_1.jtn[a2cmmn_1.iips - 1];
    jtnds = a2cmmn_1.jtn[a2cmmn_1.iids - 1];
    avsto_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], snpssv);
    avsto_(&a2cmmn_1.sn[a2cmmn_1.ids - 1], sndssv);
    if (a2cmmn_1.itlon[a2cmmn_1.iips - 1] != 0) {
	goto L1;
    }
    avdot_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], a2cmmn_1.ta, ans);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.sn[
		a2cmmn_1.ips - 1]);
    }
    a2cmmn_1.jtn[a2cmmn_1.iips - 1] = 0;
L1:
    if (a2cmmn_1.itlon[a2cmmn_1.iids - 1] != 0) {
	goto L2;
    }
    avdot_(&a2cmmn_1.sn[a2cmmn_1.ids - 1], a2cmmn_1.ta, ans);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.ids - 1], &a2cmmn_1.sn[
		a2cmmn_1.ids - 1]);
    }
    a2cmmn_1.jtn[a2cmmn_1.iids - 1] = 0;
L2:
/*      SET SWITCH TO INDICATE NO TROUBLE WITH SIGN CONVENTION */
    ksconv = 0;
    if (a2cmmn_1.numax == 5 && a2cmmn_1.multax == 1) {
	goto L100;
    }
/*      (100 FOR NORMPS OR DS) */
/* ... */
    if (a2cmmn_1.numax == 5 && a2cmmn_1.multax == 2) {
	goto L200;
    }
/*      (200 FOR PARALLEL TO RULED SURFACE) */
    if (a2cmmn_1.numax == 4 && a2cmmn_1.multax == 3) {
	goto L400;
    }
/*      (400 FOR GENERAL FOUR AXIS.... USED ALSO FOR FIVE XXIS) */
    if (a2cmmn_1.numax == 5 && a2cmmn_1.multax == 3) {
	goto L500;
    }
/*      (500 FOR FIVE AXIS) */
/*      IF HAVE NOT TAKEN ANY BRANCH, INVALIS CASE */
    aerr_(&c__850);
L100:
/* ... */
/*      NORMPS OR NORMDS... SET UP II AS INDEX OF CONTROLLING SURFACE */
/*      TEST FOR VALID ICSUR */
    if (a2cmmn_1.icc == 1 || a2cmmn_1.icc == 2) {
	goto L120;
    }
L110:
    aerr_(&c__851);
L120:
    ii = a2cmmn_1.ips;
    *aii = a2fpc_1.q1p;
    if (a2cmmn_1.jtn[a2cmmn_1.iips - 1] == 1) {
	*aii = -a2fpc_1.q1p;
    }
    if (a2cmmn_1.icc != 2) {
	goto L121;
    }
    ii = a2cmmn_1.ids;
    *aii = a2fpc_1.q1p;
    if (a2cmmn_1.jtn[a2cmmn_1.iids - 1] == 1) {
	*aii = -a2fpc_1.q1p;
    }
L121:
    avmult_(&a2cmmn_1.sn[ii - 1], aii, a2cmmn_1.slx);
    avsto_(a2cmmn_1.slx, slx1);
    issav = a2cmmn_1.is;
    iissav = a2cmmn_1.iis;
    a2cmmn_1.is = ii;
    a2cmmn_1.iis = a2cmmn_1.iips;
    if (a2cmmn_1.icc == 2) {
	a2cmmn_1.iis = a2cmmn_1.iids;
    }
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], tpsav);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], tnsav);
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], spsav);
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], snsav);
    ssav = a2cmmn_1.s[a2cmmn_1.is - 1];
    iopsav = a2cmmn_1.iop[a2cmmn_1.iis - 1];
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ta, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    addst_();
    if (a2cmmn_1.ier == 1) {
	goto L140;
    }
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.s[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, &a2cmmn_1.sp[a2cmmn_1.is - 1]);
    anrmal_();
    if (a2cmmn_1.ier == 1) {
	goto L140;
    }
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], slx1, ans);
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.slx);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.slx, a2cmmn_1.slx);
    }
L140:
    avsto_(tpsav, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(tnsav, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(spsav, &a2cmmn_1.sp[a2cmmn_1.is - 1]);
    avsto_(snsav, &a2cmmn_1.sn[a2cmmn_1.is - 1]);
    a2cmmn_1.s[a2cmmn_1.is - 1] = ssav;
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = iopsav;
    a2cmmn_1.is = issav;
    a2cmmn_1.iis = iissav;
/*      GO TO TESTING AREA */
/* ... */
    goto L1000;
L200:
/* ... */
/*      PARALLEL TO THE RULINGS OF A RULED SURFACE... */
/*      TEST FOR AVALID ICSUR */
    if (a2cmmn_1.icc != 1 && a2cmmn_1.icc != 2) {
	goto L110;
    }
/*      NOW BE SURE THAT IT IS A RULED SURFACE */
    ii = a2cmmn_1.ipontr[a2cmmn_1.iips - 1];
    if (a2cmmn_1.icc == 2) {
	ii = a2cmmn_1.ipontr[a2cmmn_1.iids - 1];
    }
    if (a2cmmn_1.icc == 2) {
	avsto_(&a2cmmn_1.slx[a2cmmn_1.ids - 1], &a2cmmn_1.slx[a2cmmn_1.ips - 
		1]);
    }
    astor_(&a2cmmn_1.cansto[ii - 1], &c__8, &ii1, &c__4);
    if (ii1 != 53) {
	aerr_(&c__852);
    }
/*      MAKE SLX DOT POSITIVELY ON TA TO ENSURE THE MINIMUM AXIS CHANGE */
/*      WHICH WILL GIVE A LINE UP */
    avdot_(a2cmmn_1.ta, a2cmmn_1.slx, ans);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.slx, a2cmmn_1.slx);
    }
/*      GO TO TESTING AREA */
/* ... */
    goto L1000;
L500:
/* ... */
/*      GENERAL FIVE AXIS CASE... REDUCES TO 4 AXIS CASE, EXCEPT THAT */
/*      TI HAS TO BE SET PROPERLY IN STARTUP CSSE */
/*      IF NOT STARTUP, GO TO 400 AND SET UP CONTROLLING AND NON CONT- */
/*      ROLLING SURFACE VECTORS JUST AS IN 4 AXIS CASE */
    if (a2cmmn_1.istrup != 1) {
	goto L400;
    }
/* ... */
/*      ESTABLISH TI */
    afwdsl_(&c__1);
    atisel_(&c__1);
/*      NOW GO SET UP CONTROLLING AND NON CONTROLLING VECTORS */
    goto L400;
L400:
/* ... */
/*      FOR BOTH 4 AXIS AND 5 AXIS CASES, SET UP VC = SURFACE NORMAL */
/*      OF CONTROLLING SURFACE AND VNC = SURFACE NORMAL OF NON CONTROLLIN */
/*      SURFACE... ALSO TEST FOR VALID ICSUR */
    if (a2cmmn_1.icc != 1 && a2cmmn_1.icc != 2) {
	goto L110;
    }
    ii = a2cmmn_1.ips;
    iii = a2cmmn_1.ids;
    *aii = a2fpc_1.q1p;
    *aiii = a2fpc_1.q1p;
    if (a2cmmn_1.jtn[a2cmmn_1.iips - 1] == 1) {
	*aii = -a2fpc_1.q1p;
    }
    if (a2cmmn_1.jtn[a2cmmn_1.iids - 1] == 1) {
	*aiii = -a2fpc_1.q1p;
    }
    if (a2cmmn_1.icc == 1) {
	goto L410;
    }
    ii = a2cmmn_1.ids;
    iii = a2cmmn_1.ips;
    *ans = *aiii;
    *aiii = *aii;
    *aii = *ans;
L410:
    avmult_(&a2cmmn_1.sn[ii - 1], aii, vc);
    avmult_(&a2cmmn_1.sn[iii - 1], aiii, vnc);
/* ... */
/*     BRANCH ON FOUR OR FIVE AXIS CASE */
    if (a2cmmn_1.numax == 5) {
	goto L510;
    }

/*      FIVE AXIS CASE WILL REJOIN RIGHT HERE AFTER COMPUTING AX4,THE PLA */
/*      PLANE VECTOR */
L450:
/* ... */
/* C */
/*      BE SURE THAT AX4 DOTS POSITIVELY WITH VC... REDUNDANT IN 5 AXIS C */
    avdot_(vc, a2cmmn_1.ax4, ans);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.ax4, a2cmmn_1.ax4);
    }
/*      SET UP SINE AND COSINE OF BETA */
    *cosbta = sqrt(a2fpc_1.q1p - *ans * *ans);
    *cosalp = cos((abs(a2cmmn_1.alp)));
/*      TEST FAOR IMPOSSIBLE SPECIFICATION */
    if (*cosbta < *cosalp) {
	aerr_(&c__853);
    }
/*      NOW SET UP ANGLE THETA, ANGLE TA MAKES IN PLANE AX4 WITH PROJ */
/*      ECTION OF SNC */
    *costhe = *cosalp / *cosbta;
    *sinthe = sqrt(a2fpc_1.q1p - *costhe * *costhe);
/* ... */
/*      NOW CONSTRUCH UNIT VECTORS TO USE IN SETTING SLX */
    avcros_(vc, a2cmmn_1.ax4, v1);
    avnorm_(v1, v1, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__854);
    }
/*      IF NORM ERROR, PLANE IS NORMAL TO CONTROLLING SURFACE NORMAL */
/*      WHICH CANT BE */
    avcros_(a2cmmn_1.ax4, v1, v2);
    avnorm_(v2, v2, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__855);
    }
/*      SHOULD NEVER GER ERROR */
/*      V1,V2,AND AX4 NOW FORM AN ORTHOGONAL COORDINETE SYSTEM */
/*      CONSTRUCT THE TWO CANDIDATE VECTORS */
    avmult_(v2, costhe, slx1);
    avmult_(v1, sinthe, a2cmmn_1.vtem);
    avsub_(slx1, a2cmmn_1.vtem, slx2);
    avadd_(slx1, a2cmmn_1.vtem, slx1);
/*      V1=V2*COSTHE + V1*SINTHE */
/*      SLX2 = V2*COSTHE - V1*SINTHE */
    avnorm_(slx1, slx1, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__856);
    }
    avnorm_(slx2, slx2, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__856);
    }
/*      NOW SELECT RPOPER VECTOR ON BASIS OF ALPHA SIGN */

/* ....    IF THE SIGN CONVENTION BRAAKS DOWN , THAT IS,THE */
/*      NON CONTROLLING SURFACE NORMAL IS NORMAL TO THE PLANE OF THE TWO */
/*      TWO VECTORS, OF DOTS EQUALLY ON THEM, THE PROGRAM WILL REENTER HE */
/*      HERE USING TI INSTEAD OF VNC */
/* ... */
L455:
    avdot_(slx1, vnc, ans1);
    avdot_(slx2, vnc, ans2);
/* ... */
/*      SELECT PROPER VECTOR BASED ON SIGN OF ALPHA */
/*      IF ALPHA +,  SELECT LARGEST + DOT PRODUCT */
/*      IF ALPHA -, SELECT SMALLEST (LARGEST NEGATIVE) DOT PRODUCT */
/*      IF ALPHA IS ZERO,  AND IT IS A 4AXIS CASE, OUTPUT A WARNING */
    if (a2cmmn_1.alp < 0.) {
	goto L460;
    } else if (a2cmmn_1.alp == 0) {
	goto L470;
    } else {
	goto L480;
    }
L470:
    if (a2cmmn_1.numax == 5) {
	goto L480;
    }
    aerr_(&c_n857);
    a2cmmn_1.alp = a2fpc_1.qp001;
/*      THIS WILL CAUSE THIS MESSAGE TO BE OUTPUT ONLY ONCE, */
/*      WITHOUT SIGNIFICANTLY CHANGING THE CALCULATION */
    goto L480;
L460:
    if (*ans1 > *ans2) {
	goto L485;
    }
/* ... */
    goto L490;
L480:
    if (*ans1 > *ans2) {
	goto L490;
    }
/* ... */
    goto L485;
L490:
/* ... */
    avsto_(slx1, a2cmmn_1.slx);
    goto L495;
L485:
/* ... */
    avsto_(slx2, a2cmmn_1.slx);

L495:
/* ... */
/*      SEE IF THE SIGN CONVENTION BROKE DOUWN */
    *ans = abs(*ans1) - abs(*ans2);
    if (abs(*ans) < a2fpc_1.qp0001) {
	goto L496;
    }
/* ... */
/*      GO TO TESTING AREA */
    goto L1000;
L496:
/*      SEE IF SIGN OF DOT PRODUCT VECTORS IS ALSO THE SAME */
    if (*ans1 * *ans2 < a2fpc_1.qnul) {
	goto L1000;
    }
    if (ksconv == 1 && abs(a2cmmn_1.alp) < a2fpc_1.qp01) {
	goto L1000;
    }
    if (ksconv == 1) {
	aerr_(&c__861);
    }
    ksconv = 1;
    aerr_(&c_n858);
/*      USE TI INSTEAD OV VNC */
    avsto_(a2cmmn_1.ti, vnc);
    goto L455;
/* ... */
/*      5 AXIS CASE, SET UP AX4 PLANE WHICH MAY THEN BE SUSED IN 4 AXIX C */
L510:
    if (abs(a2cmmn_1.gamma) <= abs(a2cmmn_1.alp)) {
	goto L5111;
    }
    aerr_(&c__859);
L5111:
    if (abs(a2cmmn_1.gamma) > a2fpc_1.qp0001 || abs(a2cmmn_1.alp) > 
	    a2fpc_1.qp0001) {
	goto L511;
    }
/* ...    SPECIAL CASE--REALLY NORMAL TO CONTROLLING SURFACE */
    a2cmmn_1.multax = 1;
    goto L100;

L511:
    avcros_(&a2cmmn_1.sn[a2cmmn_1.ips - 1], &a2cmmn_1.sn[a2cmmn_1.ids - 1], 
	    a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ti, ans);
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.ti, &a2cmmn_1.ier);
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.ti, a2cmmn_1.ti);
    }
/* ... */
    *ans1 = cos((abs(a2cmmn_1.alp)));
    *ans2 = sin((abs(a2cmmn_1.gamma)));
    avmult_(a2cmmn_1.ti, ans1, a2cmmn_1.vtem);
    avmult_(vc, ans2, a2cmmn_1.temp);
/*      SET UP PLANE */
    if (a2cmmn_1.gamma > a2fpc_1.qnul) {
	goto L516;
    }
    avadd_(a2cmmn_1.vtem, a2cmmn_1.temp, a2cmmn_1.ax4);
    goto L517;
L516:
    avsub_(a2cmmn_1.temp, a2cmmn_1.vtem, a2cmmn_1.ax4);
L517:
    avnorm_(a2cmmn_1.ax4, a2cmmn_1.ax4, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	avsto_(a2cmmn_1.ti, a2cmmn_1.ax4);
    }
/*      REJOIN 4 AXIS CALCULATION */
    goto L450;


/* ... */
/*      TESTING AREA */


L1000:
    avdot_(a2cmmn_1.ta, a2cmmn_1.slx, ans);
/* ... */
    if (a2cmmn_1.jw6 == 0) {
	goto L1010;
    }
    if (*ans < a2fpc_1.qp4x95) {
	goto L1010;
    }
L1001:
    a2cmmn_1.jtr = 1;
    goto L1020;
L1010:
    kk = a2cmmn_1.iips;
    if (a2cmmn_1.icc == 2) {
	kk = a2cmmn_1.iids;
    }
    if (a2cmmn_1.itlon[kk - 1] == 0 || a2cmmn_1.cutdat[0] == a2fpc_1.qnul) {
	goto L1030;
    }
    goto L1040;
L1030:
    if (*ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.slx, a2cmmn_1.slx);
    }
    if (a2cmmn_1.jw6 == 0) {
	goto L1040;
    }
    if (abs(*ans) >= a2fpc_1.qp4x95) {
	goto L1001;
    }
L1040:
    if (a2cmmn_1.jcnt3 > 10) {
	goto L1011;
    }
    avadd_(a2cmmn_1.ta, a2cmmn_1.slx, a2cmmn_1.slx);
    avnorm_(a2cmmn_1.slx, a2cmmn_1.slx, &a2cmmn_1.ier);
L1011:
    avsto_(a2cmmn_1.slx, a2cmmn_1.ta);
    a2cmmn_1.jtr = 0;
L1020:
/* ... */
    a2cmmn_1.jtn[a2cmmn_1.iips - 1] = jtnps;
    a2cmmn_1.jtn[a2cmmn_1.iids - 1] = jtnds;
    avsto_(snpssv, &a2cmmn_1.sn[a2cmmn_1.ips - 1]);
    avsto_(sndssv, &a2cmmn_1.sn[a2cmmn_1.ids - 1]);
    return 0;
} /* atinkr_ */

#undef snpssv
#undef sinthe
#undef sndssv
#undef costhe
#undef cosalp
#undef cosbta
#undef snsav
#undef spsav
#undef tnsav
#undef tpsav
#undef aiii
#undef ans2
#undef ans1
#undef ans
#undef vnc
#undef slx2
#undef slx1
#undef aii
#undef vc
#undef v2
#undef v1
#undef ab


