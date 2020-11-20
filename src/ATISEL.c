/* ATISEL.f -- translated by f2c (version 20000121).
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
	    1], cutr[1], afillr[500], adum[120], te[3], tek[3], tel[3], tes[3]
	    , ta[3], tak[3], tal[3], pmove[3], ti[3], tik[3], til[3], u2[3], 
	    uvec[3], vtem[3], cmove[3], ex[3], ey[3], ez[3], vnul[3], tm[3], 
	    dir[3], axis[3], axis1[3], axis2[3], axis3[3], refpnt[3], rgt[3], 
	    fwd[3], up[3], zlnorm[3], zlpnt[3], tndir[3], va[3], tmvcmp[3], 
	    p1[3], p2[3], pnt[3], pnt1[3], oldu1[3], ogle[3], rzero[3], 
	    tanmot[3], tlend1[3], v[3], cend[3], delmot[3], d2[3], dnmot[3], 
	    ax4[3], a, b, c__, ra, hi, alpha, gamma, cagl, sagl, com1, com4, 
	    costh, ctocl, diam, dif, difout, dinc, dp, dpe, dpi, dpl, dpmax, 
	    dp1, dpcnt, dsmov, d1, d2a, el1, el2, fipnt, flipck, hafdia, 
	    hchord, offset, prod1, prod2, psi, radno, rc1, rdrm, rdrn, rone, 
	    rzerol, save1, siuth, tangl, theta, alp, eps7, vamax, vl, zdotc, 
	    zgamma, zign, zl, zl1, zl2, znpts, tolbnd, cendis, cenlen, chord, 
	    abcd[2], acard[2], save[6], cutdat[7], tem[10], temp[20], tcdat[
	    260], qequiv[20];
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
    doublereal bdum[2100];
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

static integer c__5 = 5;
static integer c__1100 = 1100;
static integer c__505 = 505;

/* Subroutine */ int atisel_(iii)
integer *iii;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_3 = { {'A', 'T', 'I', 'S', 'E', 'L', 'T', 'P'}, (float)0. };

#define ab ((real *)&equiv_3)


    static doublereal ans;
    extern /* Subroutine */ int aerr_(), avdot_(), avsub_(), avsto_(), 
	    adyndp_(), avcros_(), avnorm_();

/* ...  TO SELECT THE PROPER DIRECTION OF MOTION TI ON THE BASIS OF THE */
/* ...  FORWARD DIRECTION FWD. ATISEL IS PRIMARILY USED BY AREPRE TO */
/* ...  SELECT THE DIRECTION OF MOTION TI. IT IS ALSO USED IN CERTAIN */
/* ...  MULTI-AXIS STARTUP CASES BY ATINKR, AND IN THIS CASE THE ERROR */
/* ...  EXIT IS DISABLED. */
/* ...                     CALL ATISEL(III) */
/* ...                        WHERE  III = 0  ALLOW ERROR */
/* ...                                   = 1  DISABLE ERROR */
/* ... */
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/* ... */
/* ...  IF THE TI VECTOR CAN NOT BE COMPUTED (THE PS AND DS ARE TANGENT */
/* ...  AT THE INPUT POINT), TI IS SET EXACTLY EQUAL TO FWD. */
/* ... */
    adyndp_(ab, &c__5, &c__1100);
    avcros_(&a2cmmn_.sn[a2cmmn_.ips - 1], &a2cmmn_.sn[a2cmmn_.ids - 1], 
	    a2cmmn_.ti);
    avnorm_(a2cmmn_.ti, a2cmmn_.ti, &a2cmmn_.ier);
    if (a2cmmn_.ier == 1) {
	goto L20;
    }
    avdot_(a2cmmn_.fwd, a2cmmn_.ti, &ans);
/* ...  IF THE ANGLE BETWEEN TI AND FWD IS EQUAL TO OR GREATER THAN 88 */
/* ...  DEGREES, CALL AERR(505). */
    if (abs(ans) <= a2fpc_1.qp0349 && *iii == 0) {
	aerr_(&c__505);
    }
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_.vnul, a2cmmn_.ti, a2cmmn_.ti);
    }
L30:
    return 0;
L20:
    avsto_(a2cmmn_.fwd, a2cmmn_.ti);
    goto L30;
} /* atisel_ */

#undef ab


