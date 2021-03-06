/* ATN2.f -- translated by f2c (version 20000121).
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
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

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

static struct {
    doublereal u1md[3], u1mi[3], u1pl[3], ccmd[3], ccmi[3], ccpl[3];
    integer iout, itry, icond, iexp;
    doublereal dotmd, dotmi, dotpl, ax2[3], ax3[3];
    integer idir, ix;
    doublereal tpmi[3], tpmd[3], tppl[3], tnmi[3], tnmd[3], tnpl[3];
} a2amd2_;

#define a2amd2_1 a2amd2_

/* Table of constant values */

static integer c__1500 = 1500;

/* Subroutine */ int atn2_()
{
    /* Builtin functions */
    double pow_di();

    /* Local variables */
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int avsto_();
    static doublereal ans;
    extern /* Subroutine */ int avadd_(), aerr_(), avsub_(), au1cmp_(), 
	    avdot_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int avmult_(), avcros_(), avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */

/*          ITYR = 1  MOVE IN TA */
/*               =-1  MOVE IN THETA */

/*          IECP = EXPONENT DIVISOR */

/*          IDIR = 1 MOVE PLUS */
/*               = 2 MOVE MINUS */

    avsto_(a2amd2_1.tpmd, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(a2amd2_1.tnmd, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(a2amd2_1.u1md, &a2cmmn_1.u1[a2cmmn_1.is - 1]);
    avsto_(a2amd2_1.ccmd, &a2cmmn_1.cc[a2cmmn_1.is - 1]);

/* ...  COMPUTE PHONEY CC */

    if (a2cmmn_1.j24[a2cmmn_1.iis - 1] == 2) {
	goto L300;
    }
    ans = a2fpc_1.q10p * a2cmmn_1.cutdat[0];
    if (ans < a2fpc_1.qp1) {
	ans = a2fpc_1.q10p;
    }
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &ans, a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.cc[
	    a2cmmn_1.is - 1]);
    ans = ans * .08749 / pow_di(&a2fpc_1.q2p, &a2amd2_1.iexp);


    if (a2amd2_1.itry < 0) {
	goto L200;
    } else if (a2amd2_1.itry == 0) {
	goto L99;
    } else {
	goto L100;
    }
L99:
    aerr_(&c__1500);

L100:
    if (a2amd2_1.idir == 2) {
	ans = -ans;
    }
    avmult_(a2cmmn_1.ta, &ans, a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.cc[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.cc[
	    a2cmmn_1.is - 1]);

    return 0;

L200:
    avcros_(a2cmmn_1.ta, &a2cmmn_1.u1[a2cmmn_1.is - 1], a2cmmn_1.vtem);
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	a2cmmn_1.ier = 100;
    }
    if (a2cmmn_1.ier == 100) {
	return 0;
    }
    if (a2amd2_1.idir == 2) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.vtem, a2cmmn_1.vtem);
    }

    avmult_(a2cmmn_1.vtem, &ans, a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.cc[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.cc[
	    a2cmmn_1.is - 1]);
L250:
    au1cmp_();
    avdot_(&a2cmmn_1.u1[a2cmmn_1.is - 1], a2cmmn_1.oldu1, &ans);
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, &a2cmmn_1.u1[a2cmmn_1.is - 1], &a2cmmn_1.u1[
		a2cmmn_1.is - 1]);
    }

    return 0;
L300:
    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.cansto[a2cmmn_1.jt - 1], 
	    a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, &a2cmmn_1.cansto[a2cmmn_1.jt + 2], &ans);
    avmult_(&a2cmmn_1.cansto[a2cmmn_1.jt + 2], &ans, &a2cmmn_1.cc[a2cmmn_1.is 
	    - 1]);
    avadd_(&a2cmmn_1.cansto[a2cmmn_1.jt - 1], &a2cmmn_1.cc[a2cmmn_1.is - 1], &
	    a2cmmn_1.cc[a2cmmn_1.is - 1]);
    goto L250;
} /* atn2_ */

#undef tlldat
#undef cosl
#undef sinl


