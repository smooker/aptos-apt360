/* AOFSET.f -- translated by f2c (version 20000121).
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
    doublereal adum[2100];
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

/* Table of constant values */

static integer c__33 = 33;
static integer c__1 = 1;
static integer c_b4 = 111111;
static integer c__34 = 34;
static integer c__38 = 38;
static integer c__39 = 39;
static integer c__35 = 35;
static integer c__36 = 36;
static integer c_n37 = -37;

/* Subroutine */ int aofset_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_7 = { {'A', 'O', 'F', 'S', 'E', 'T', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_7)


    static doublereal ans, gdir[3];
    extern /* Subroutine */ int aerr_(), avadd_();
    static doublereal ans1;
    static integer iret;
    extern /* Subroutine */ int amind_(), atape_();
    static doublereal torig[3];
    extern /* Subroutine */ int avsto_(), addst_(), avsub_(), avdot_(), 
	    amove_(), astos_(), anrmal_(), avleng_(), adyndp_(), avnorm_(), 
	    avmult_(), atltst_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*      TO PROCESS THE OFFSET STATEMENT */
/*      THE ALGORITHM IS TO PIERCE THE DRIVE SURFACE WITH THE INDIR */
/*      VECTOR (WHICH MUST HAVE BEEN GIVEN FOR THE DS AND ONLY FOR THE */
/*      DS),  FROM THIS POINT, MOVE THE CUTTER EXACTLY ALONG THE SURFACE */
/*      NORMAL UNTIL A PROPER POSITION HAS BEEN REACHED (TO, ON ,OR PAST) */
/*      IF THIS IS A NOPS CASE, THAT COMPLETES THE MOTION.  IF NOT, */
/*      MOVE THE CUTTER EXACTLY ALONG ITS AXIS TO,ON, OR PAST THE PS. */
/*      THEN CHECK TO SEE IF THIS LAST MOTION HAS CAUSED THE CUTTER */
/*      TO MOVE OUT OF TOLERANCE OF THE DS. IF SO, OUTPUT A WARNING MES- */
/*      SAGE. */

/* ...   CHECK FOR PROPER INDIR SEECIFICATION */
    if (a2cmmn_1.indir__[(4920 + (0 + (a2cmmn_1.iips - 1 << 2)) - 4920) / 4] 
	    != 0 || a2cmmn_1.indir__[(4920 + (0 + (a2cmmn_1.iics - 1 << 2)) - 
	    4920) / 4] != 0 || a2cmmn_1.indir__[(4920 + (0 + (a2cmmn_1.iids - 
	    1 << 2)) - 4920) / 4] != 1) {
	aerr_(&c__33);
    }
    adyndp_(ab, &c__1, &c_b4);
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    avsto_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);

/* ... */

L10:
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
/* ... */
    addst_();
    if (a2cmmn_1.ier != 0) {
	aerr_(&c__34);
    }
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.s[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.te);
    avsto_(a2cmmn_1.te, torig);
/* ... */
    if (a2cmmn_1.itlon[a2cmmn_1.iis - 1] == 0) {
	goto L30;
    }

/* ... */

/* L20: */
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.past[a2cmmn_1.is - 1], 
	    gdir);
    avsub_(a2cmmn_1.vnul, gdir, gdir);
    if (a2cmmn_1.is == a2cmmn_1.ips) {
	goto L25;
    }
    avsto_(a2cmmn_1.te, &a2cmmn_1.sp[a2cmmn_1.is - 1]);
    anrmal_();
    if (a2cmmn_1.ier != 0) {
	aerr_(&c__38);
    }
/* L1: */
    avdot_(gdir, &a2cmmn_1.sn[a2cmmn_1.is - 1], &ans);
    if (ans < a2fpc_1.qnul) {
	goto L21;
    }
    if (ans == a2fpc_1.qnul) {
	goto L22;
    }
    if (ans > a2fpc_1.qnul) {
	goto L23;
    }
L21:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.is - 1], gdir);
    goto L25;
L22:
    aerr_(&c__39);
L23:
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], gdir);
/* ... */
L25:
    amove_(gdir);
    avsub_(a2cmmn_1.te, torig, a2cmmn_1.vtem);
    avleng_(a2cmmn_1.vtem, &ans1);
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
/* ... */
    if (a2cmmn_1.ier == 1) {
	goto L30;
    }
    avmult_(a2cmmn_1.vtem, &a2fpc_1.qp4x01, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(torig, &a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[a2cmmn_1.is - 1]
	    );
    avsto_(a2cmmn_1.vtem, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
/* ... */
    addst_();
    if (a2cmmn_1.ier == 1 || a2cmmn_1.s[a2cmmn_1.is - 1] > ans1) {
	goto L30;
    }
    aerr_(&c__35);

/* ... */
/* . */
L30:
/* ... */
    if (a2cmmn_1.inops == 1) {
	goto L80;
    }

/* ... */

/* L40: */
/* ... */
    if (a2cmmn_1.is == a2cmmn_1.ips) {
	goto L70;
    }

/* ... */

/* L50: */
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(a2cmmn_1.ta, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
/* ... */
    addst_();
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__36);
    }
/* ... */
    if (a2cmmn_1.s[a2cmmn_1.is - 1] <= a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
		a2cmmn_1.is - 1]);
    }
    goto L10;

/* ... */

L70:

/* ... */

    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    a2cmmn_1.jent[a2cmmn_1.iis - 1] = 1;
    avmult_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], &a2cmmn_1.past[a2cmmn_1.is - 1],
	     &a2cmmn_1.tn[a2cmmn_1.is - 1]);
/* ... */
    amind_();
/* ... */
    atltst_(&iret);
    if (iret != 0) {
	aerr_(&c_n37);
    }
/* ... */

/* ... */

L80:
/* ... */
    a2cmmn_1.nw = 0;
    astos_();
    atape_();
/* ... */
    return 0;
} /* aofset_ */

#undef ab


