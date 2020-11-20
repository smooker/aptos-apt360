/* AGOUCK.f -- translated by f2c (version 20000121).
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
    doublereal adum[2100];
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
static integer c_b3 = 111100;
static integer c_n881 = -881;
static integer c_n882 = -882;

/* Subroutine */ int agouck_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_10 = { {'A', 'G', 'O', 'U', 'C', 'K', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_10)


    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__;
#define ang ((doublereal *)&a2cmmn_1 + 88)
#define iax ((integer *)&a2cmmn_1 + 2547)
    static doublereal goug[1], ans;
    extern /* Subroutine */ int avadd_(), aerr_(), amind_(), avsub_(), avdot_(
	    ), avsto_();
    static integer issto, kgaerr;
    extern /* Subroutine */ int adyndp_(), avleng_(), avnorm_(), accurv_(), 
	    avmult_();
    static integer iissto;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */

/* ... */
    adyndp_(ab, &c__3, &c_b3);
    kgaerr = 0;
    a2cmmn_1.jgr = 0;
/*         DENOTE CUT VECTOR (UNITIZED) D2, LENGTH ZL */
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.d2);
    avleng_(a2cmmn_1.d2, &a2cmmn_1.zl);
    avnorm_(a2cmmn_1.d2, a2cmmn_1.d2, &a2cmmn_1.ier);

    if (a2cmmn_1.ier <= 0) {
	goto L101;
    } else {
	goto L620;
    }
L101:
/* *** */
/* *** */
/*      NOTE, GOUGE SURFACE IS AFTER LAST CS */
/*      DIMENSION GOUG(1) */
/*      EQUIVALENCE(ANG,COS1(1)),(IAX,I31) */
    a2cmmn_1.is = a2cmmn_1.igs;
    a2cmmn_1.iis = a2cmmn_1.iigs;
    a2cmmn_1.it = a2cmmn_1.ips;
    a2cmmn_1.iit = a2cmmn_1.iips;
/* ... */

/*         DETERMINE AXIS CONDITION */
    if (a2cmmn_1.isftyp[a2cmmn_1.iips - 1] - 3 != 0) {
	goto L210;
    } else {
	goto L231;
    }
L210:
    if (a2cmmn_1.multax > 0) {
	goto L250;
    }
L220:
    avdot_(a2cmmn_1.ta, a2cmmn_1.d2, &ans);
    if (abs(ans) >= a2fpc_1.qp0005) {
	goto L232;
    }
/*         TA PERPENDICULAR TO CUT VECTOR OR TE ON SURFACE */
L231:
    *iax = 0;
    goto L400;
/*         TA OBLIQUE TO CUT VECTOR */
L232:
    *iax = 1;
    goto L400;
L250:
    avdot_(a2cmmn_1.ta, a2cmmn_1.tak, &ans);
    if (ans > a2fpc_1.qp4x95) {
	goto L220;
    }
/*         AXIS CHANGE DURING CUT */
/* L233: */
    *iax = 2;
    goto L400;

/*         PRELIMINARY TO AXIS CONDITION SETTING FOR DS */
L300:
    a2cmmn_1.it = a2cmmn_1.ids;
    a2cmmn_1.iit = a2cmmn_1.iids;
    if (a2cmmn_1.isftyp[a2cmmn_1.iids - 1] - 3 != 0) {
	goto L310;
    } else {
	goto L231;
    }
/*         IF TOOL END ON PS BUT NOT DS,GO THROUGH AXIS CONDITION ROUTINE */
L310:
    if (a2cmmn_1.isftyp[a2cmmn_1.iips - 1] - 3 != 0) {
	goto L400;
    } else {
	goto L210;
    }

/*         SAVE AND ESTABLISH SYSTEM VARIABLES */
L400:
/* ... */
    i__1 = a2cmmn_1.lsv;
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= i__1; ++a2cmmn_1.k) {
	a2cmmn_1.l = a2cmmn_1.igs - 1 + a2cmmn_1.k;
	a2cmmn_1.j = a2cmmn_1.it - 1 + a2cmmn_1.k;
/* L410: */
	a2cmmn_1.sp[a2cmmn_1.l - 1] = a2cmmn_1.sp[a2cmmn_1.j - 1];
    }
    i__1 = a2cmmn_1.lisv;
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= i__1; ++a2cmmn_1.k) {
	a2cmmn_1.l = a2cmmn_1.iigs - 1 + a2cmmn_1.k;
	a2cmmn_1.j = a2cmmn_1.iit - 1 + a2cmmn_1.k;
/* L420: */
	a2cmmn_1.iafl[a2cmmn_1.l - 1] = a2cmmn_1.iafl[a2cmmn_1.j - 1];
    }
    avsto_(a2cmmn_1.ta, &a2cmmn_1.sfvct[a2cmmn_1.igs - 1]);
    avsto_(a2cmmn_1.te, &a2cmmn_1.vndir[a2cmmn_1.igs - 1]);
    a2cmmn_1.jent[a2cmmn_1.iigs - 1] = 0;
    a2cmmn_1.jtn[a2cmmn_1.iigs - 1] = 0;
    a2cmmn_1.iopset[a2cmmn_1.iigs - 1] = 0;
    a2cmmn_1.ju1[a2cmmn_1.iigs - 1] = 0;
    a2cmmn_1.jiops[a2cmmn_1.iigs - 1] = 0;
/* ... */
/*         CONVERGENCE CRITERION FOR FIRST 10 ITERATIONS */
    *ang = a2fpc_1.qp0005;
/*         INITIALIZE ITERATION COUNTER */
    i__ = 0;


/*         CONVERGENCE ROUTINE */
L1000:
    accurv_(&a2cmmn_1.is, &a2cmmn_1.iis, &a2cmmn_1.sp[a2cmmn_1.is - 1], &
	    a2cmmn_1.spk[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1]);
/*         IF IT PLANE, RESTORE SYSTEM VARIABLES AND TEST NEXT SURFACE */
    if ((i__1 = -a2cmmn_1.isigcr[a2cmmn_1.iis - 1]) < 0) {
	goto L1010;
    } else if (i__1 == 0) {
	goto L1020;
    } else {
	goto L600;
    }
/*         IF POINTS TOO CLOSE AFTER ONE OR MORE ITERATION,USE LAST GUESS */
L1010:
    if (i__ < 0) {
	goto L1020;
    } else if (i__ == 0) {
	goto L600;
    } else {
	goto L1230;
    }
L1020:
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], &a2cmmn_1.spk[a2cmmn_1.is - 1]);

/*         TE=PROJECTION OF CC ON CUT VECTOR */
/* L1030: */
    avsub_(&a2cmmn_1.cc[a2cmmn_1.is - 1], a2cmmn_1.te, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.d2, a2cmmn_1.temp);
    avmult_(a2cmmn_1.d2, a2cmmn_1.temp, a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.te);
/*         IF PROJECTION NOT ON CUT VECTOR RESTORE SURFACE VARIABLES */
/*        AND TEST NEXT SURFACE */
/* L1040: */
    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.d2, &a2cmmn_1.zl1);
/* ... */
    if (a2cmmn_1.zl1 <= 0.) {
	goto L1044;
    } else {
	goto L1042;
    }
L1042:
    if (a2cmmn_1.zl - a2cmmn_1.zl1 <= 0.) {
	goto L1044;
    } else {
	goto L1050;
    }
L1044:
    ++kgaerr;
    if (kgaerr > 10) {
	aerr_(&c_n881);
    }
    goto L600;

L1050:
    issto = a2cmmn_1.it;
    iissto = a2cmmn_1.iit;
/* ... */
    amind_();
    a2cmmn_1.it = issto;
    a2cmmn_1.iit = iissto;
/*         CONVERGENCE WHEN TN (HENCE SN) PERPENDICULAR TO CUT VECTOR */
    avdot_(&a2cmmn_1.sn[a2cmmn_1.is - 1], a2cmmn_1.d2, &ans);
/* ... */
    if (*ang >= abs(ans)) {
	goto L1300;
    }

/*         PREPARE FOR NEXT ITERATION */
/*         IF TENTH ITERATION, ASSUME SURFACE HAS LARGE DIMENSIONS */
/*        AND RELAX CONVERGENCE CRITERION */
/* L1200: */
    if ((i__1 = 9 - i__) < 0) {
	goto L1220;
    } else if (i__1 == 0) {
	goto L1210;
    } else {
	goto L1212;
    }
L1210:
    *ang = a2fpc_1.qp0047;
L1212:
    ++i__;
/* ... */
    goto L1000;
/*         IF FIFTEENTH ITERATION, GIVE UP AND USE LAST GUESS */
L1220:
    if (14 - i__ >= 0) {
	goto L1212;
    } else {
	goto L1230;
    }
L1230:
    ++kgaerr;
    if (kgaerr > 10) {
	aerr_(&c_n882);
    }


L1300:
    goug[0] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1));


/*         SET RETURN VARIABLE */
/* ... */
    if (a2fpc_1.qp8 * a2cmmn_1.tau[a2cmmn_1.it - 1] - goug[0] <= 0.) {
	goto L510;
    } else {
	goto L600;
    }
L510:
    if (a2cmmn_1.it - a2cmmn_1.ips <= 0) {
	goto L522;
    } else {
	goto L524;
    }
L522:
    a2cmmn_1.jgr = 1;
    goto L600;
L524:
    a2cmmn_1.jgr += 2;


/*         RESTORE SYSTEM VARIBLES */
L600:
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= 3; ++a2cmmn_1.k) {
	a2cmmn_1.l = a2cmmn_1.igs - 1 + a2cmmn_1.k;
	a2cmmn_1.ta[a2cmmn_1.k - 1] = a2cmmn_1.sfvct[a2cmmn_1.l - 1];
/* L610: */
	a2cmmn_1.te[a2cmmn_1.k - 1] = a2cmmn_1.vndir[a2cmmn_1.l - 1];
    }
/* ... */


    if (a2cmmn_1.ids - a2cmmn_1.it <= 0) {
	goto L620;
    } else {
	goto L300;
    }
L620:
/* ... */
    return 0;
} /* agouck_ */

#undef iax
#undef ang
#undef ab


