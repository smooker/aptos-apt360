/* AJUNDD.f -- translated by f2c (version 20000121).
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
    integer k1083;
} kk1083_;

#define kk1083_1 kk1083_

/* Table of constant values */

static integer c__4 = 4;
static integer c_b3 = 111100;
static integer c_n1022 = -1022;
static integer c__1021 = 1021;

/* Subroutine */ int ajundd_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_4 = { {'A', 'J', 'U', 'N', 'D', 'D', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_4)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal qq;
    extern /* Subroutine */ int aerr_();
    static doublereal ans;
    extern /* Subroutine */ int avadd_(), avsub_(), addst_(), avsto_(), 
	    avdot_(), aradar_(), anrmal_(), adyndp_(), avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */


    kk1083_1.k1083 = 0;


    adyndp_(ab, &c__4, &c_b3);
    a2cmmn_1.mdic = 10;
    a2cmmn_1.j = a2cmmn_1.is + 2;
    if (a2cmmn_1.jiops[a2cmmn_1.iis - 1] != 0) {
	goto L6;
    } else {
	goto L1;
    }
L1:
    if ((i__1 = a2cmmn_1.iopset[a2cmmn_1.iis - 1]) < 0) {
	goto L2;
    } else if (i__1 == 0) {
	goto L5;
    } else {
	goto L4;
    }
L2:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
/* L3: */
    qq = a2fpc_1.q2p * a2cmmn_1.th[a2cmmn_1.is - 1];
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &qq, a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
L4:
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;

    goto L6;
L5:
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
L6:
    a2cmmn_1.rdrn = a2fpc_1.qnul;
L106:

    addst_();
/* L31: */
    if (a2cmmn_1.ier != 0) {
	goto L7;
    } else {
	goto L11;
    }
L7:
    if (a2cmmn_1.iopset[a2cmmn_1.iis - 1] <= 0) {
	goto L10;
    } else {
	goto L8;
    }
L8:
    if (a2cmmn_1.jiops[a2cmmn_1.iis - 1] != 0) {
	goto L10;
    } else {
	goto L9;
    }
L10:
    aradar_();
    if (kk1083_1.k1083 == 1) {
	goto L22;
    }

    goto L106;
L9:
    aerr_(&c_n1022);
    a2cmmn_1.iopset[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;

    goto L10;
L11:
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], &a2cmmn_1.spl[a2cmmn_1.is - 1]);
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.s[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.sp[
	    a2cmmn_1.is - 1]);
    a2cmmn_1.iunfl[a2cmmn_1.iis - 1] = (i__1 = a2cmmn_1.iunfl[a2cmmn_1.iis - 
	    1], abs(i__1));

/* L202: */
    if (a2cmmn_1.iopset[a2cmmn_1.iis - 1] >= 0) {
	goto L15;
    } else {
	goto L13;
    }
L13:
    a2cmmn_1.s[a2cmmn_1.is - 1] = -a2cmmn_1.s[a2cmmn_1.is - 1];
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[
	    a2cmmn_1.is - 1]);
L15:
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.snl[a2cmmn_1.is - 1]);

    anrmal_();
/* L41: */
    if (a2cmmn_1.ier != 0) {
	goto L17;
    } else {
	goto L18;
    }
L17:
    aerr_(&c__1021);
L18:
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] != 0) {
	goto L23;
    } else {
	goto L19;
    }
L23:
    avdot_(&a2cmmn_1.tnl[a2cmmn_1.is - 1], &a2cmmn_1.sn[a2cmmn_1.is - 1], &
	    ans);

    if (ans >= a2fpc_1.qnul) {
	goto L52;
    }
/* L24: */
    a2cmmn_1.z__[a2cmmn_1.is - 1] = -a2fpc_1.q1p;
    goto L20;
L52:
    a2cmmn_1.z__[a2cmmn_1.is - 1] = a2fpc_1.q1p;
    goto L22;
L19:
    if (a2cmmn_1.z__[a2cmmn_1.is - 1] >= 0.) {
	goto L22;
    } else {
	goto L20;
    }
L20:
    avsub_(a2cmmn_1.vnul, &a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.sn[
	    a2cmmn_1.is - 1]);
L22:

    return 0;
} /* ajundd_ */

#undef ab


