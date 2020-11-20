/* APOCKB.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
    doublereal adum[720], te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3]
	    , pmove[3], ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[
	    3], ex[3], ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3]
	    , axis2[3], axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3],
	     zlpnt[3], tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[
	    3], oldu1[3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[
	    3], delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
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
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

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
    doublereal addem1, addem2, bl[20], cosva, crosto[3], ctemp[60]	/* 
	    was [3][20] */, cutrad, dcov, deldst, dist, dummy, ofcsto, offsto,
	     phitmp, ptint[3], qone[3], q[63]	/* was [3][21] */, rtest, 
	    sin2va, sphio2, t[3], tcrsto[3], u[63]	/* was [3][21] */, 
	    ucrsto[3], uprim[60]	/* was [3][20] */, vprim[60]	/* 
	    was [3][20] */, w[60]	/* was [3][20] */, wd[3], wone[3], xi[
	    66]	/* was [3][22] */, xiprim[63]	/* was [3][21] */, x1, x2, x3,
	     y[3];
} a2pok8_;

#define a2pok8_1 a2pok8_

static struct {
    integer ipcerr, iwdcnt, nwd, ibm1, ibm2, ibm3, ibm4, ibm6;
} a2pock_;

#define a2pock_1 a2pock_

static struct {
    integer jone, nc, ncorig, jtwo, jthr, jfou, kalc, move, init, ncutbk, 
	    nplus1, nless1, icrsto, ktab[20], kutbac, kolaps, jsave, inter, 
	    kone, ktwo, jdummy, num, itest, kt1, kt2, kover;
} a2pok2_;

#define a2pok2_1 a2pok2_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__2000 = 2000;
static integer c__1009 = 1009;
static integer c__0 = 0;
static integer c__3508 = 3508;
static integer c__3509 = 3509;
static integer c__3506 = 3506;
static integer c__6 = 6;
static integer c__5000 = 5000;
static integer c__5 = 5;

/* Subroutine */ int apockb_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_13 = { {'P', 'O', 'C', 'K', 'E', 'T', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_13)


    /* Local variables */
#define cor ((doublereal *)&a2cmmn_1 + 1317)
    extern /* Subroutine */ int aerr_();
    static integer indx;
#define frone ((doublereal *)&a2cmmn_1 + 1312)
#define frtwo ((doublereal *)&a2cmmn_1 + 1313)
    extern /* Subroutine */ int avsto_();
#define radeff ((doublereal *)&a2cmmn_1 + 1309)
#define pocdat ((doublereal *)&a2cmmn_1 + 1308)
#define frthre ((doublereal *)&a2cmmn_1 + 1314)
#define ofsetc ((doublereal *)&a2cmmn_1 + 1310)
#define ofsetf ((doublereal *)&a2cmmn_1 + 1311)
#define ovride ((doublereal *)&a2cmmn_1 + 1315)
#define pttype ((doublereal *)&a2cmmn_1 + 1316)
    extern /* Subroutine */ int atapwt_(), aserch_(), ataprd_();

/* ... A2CMMN START */
/* ... A2CMMN END */
/*     EQUIVALENCE FOR POCKET */


/* L1611: */
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__4, &asistm_1.nclrec, &
	    c__1, &c__2000, &c__1, &c__1009, &c__1, frone, &c__1, &
	    a2fpc_1.q1p, &c__0, &a2fpc_1.q1p, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1630;
    }
/* L1620: */
    aerr_(&c__3508);
L1630:
    aserch_(&ataptb_1.poctap, &a2pock_1.ibm1, &a2pock_1.ipcerr);
    if (a2pock_1.ipcerr < 0) {
	goto L1640;
    }
    aerr_(&c__3509);
L1640:
    ataprd_(&ataptb_1.poctap, &a2pock_1.ipcerr, &a2pock_1.ibm4, &c__4, &
	    a2pock_1.ibm1, &c__1, &a2pock_1.ibm2, &c__1, &a2pock_1.ibm3, &
	    c__1, a2cmmn_1.tcdat, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1650;
    }
    aerr_(&c__3506);
L1650:
/* L1660: */
    --a2pock_1.ibm1;
    a2pock_1.ibm3 = 1;
    ++asistm_1.nclrec;
    if (a2cmmn_1.mulout == 1) {
	goto L1670;
    }
    a2pock_1.nwd = 3;
    goto L1680;
L1670:
    a2pock_1.nwd = 6;
L1680:
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__6, &asistm_1.nclrec, &
	    c__1, &c__5000, &c__1, &c__5, &c__1, ab, &c__1, &c__0, &c__1, &
	    a2cmmn_1.tcdat[a2pock_1.ibm3 - 1], &a2pock_1.nwd);
    if (a2pock_1.ipcerr < 0) {
	goto L1690;
    }
    aerr_(&c__3508);
L1690:
    --a2pock_1.ibm2;
    a2pock_1.ibm3 += a2pock_1.nwd;
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__4, &asistm_1.nclrec, &
	    c__1, &c__2000, &c__1, &c__1009, &c__1, frtwo, &c__1, &
	    a2fpc_1.q1p, &c__0, &a2fpc_1.q1p, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1700;
    }
    aerr_(&c__3508);
L1700:
    if (a2pock_1.ibm1 == 0) {
	goto L1760;
    }
/* L1710: */
    if (a2pock_1.ibm2 == 0) {
	goto L1730;
    }
/* L1720: */
    a2pock_1.ibm4 = a2pock_1.ibm2 * a2pock_1.nwd;
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__6, &asistm_1.nclrec, &
	    c__1, &c__5000, &c__1, &c__5, &c__1, ab, &c__1, &c__0, &c__1, &
	    a2cmmn_1.tcdat[a2pock_1.ibm3 - 1], &a2pock_1.ibm4);
    if (a2pock_1.ipcerr < 0) {
	goto L1730;
    }
    aerr_(&c__3508);
L1730:
    aserch_(&ataptb_1.poctap, &a2pock_1.ibm1, &a2pock_1.ipcerr);
    if (a2pock_1.ipcerr < 0) {
	goto L1740;
    }
    aerr_(&c__3509);
L1740:
    ataprd_(&ataptb_1.poctap, &a2pock_1.ipcerr, &a2pock_1.ibm4, &c__4, &
	    a2pock_1.ibm1, &c__1, &a2pock_1.ibm2, &c__1, &a2pock_1.ibm3, &
	    c__1, a2cmmn_1.tcdat, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1750;
    }
    aerr_(&c__3506);
L1750:
    a2pock_1.ibm3 = 1;
    --a2pock_1.ibm1;
    goto L1700;
L1760:
    if (a2pock_1.ibm2 <= a2pok2_1.ncorig + 1) {
	goto L1775;
    }
    a2pock_1.ibm4 = (a2pock_1.ibm2 - 1 - a2pok2_1.ncorig) * a2pock_1.nwd;
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__6, &asistm_1.nclrec, &
	    c__1, &c__5000, &c__1, &c__5, &c__1, ab, &c__1, &c__0, &c__1, &
	    a2cmmn_1.tcdat[a2pock_1.ibm3 - 1], &a2pock_1.ibm4);
    if (a2pock_1.ipcerr < 0) {
	goto L1770;
    }
    aerr_(&c__3508);
L1770:
    a2pock_1.ibm3 += a2pock_1.ibm4;
    goto L1780;
L1775:
    a2pock_1.ibm4 = a2pock_1.ibm2 * a2pock_1.nwd;
    goto L1785;
L1780:
    a2pock_1.ibm4 = (a2pok2_1.ncorig + 1) * a2pock_1.nwd;
L1785:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__4, &asistm_1.nclrec, &
	    c__1, &c__2000, &c__1, &c__1009, &c__1, frthre, &c__1, &
	    a2fpc_1.q1p, &c__0, &a2fpc_1.q1p, &c__0);
    if (a2pock_1.ipcerr < 0) {
	goto L1790;
    }
    aerr_(&c__3508);
L1790:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2pock_1.ipcerr, &c__6, &asistm_1.nclrec, &
	    c__1, &c__5000, &c__1, &c__5, &c__1, ab, &c__1, &c__0, &c__1, &
	    a2cmmn_1.tcdat[a2pock_1.ibm3 - 1], &a2pock_1.ibm4);
    indx = a2pock_1.ibm3 + a2pock_1.ibm4 - 3 - a2cmmn_1.mulout * 3;
    avsto_(&a2cmmn_1.tcdat[indx - 1], a2cmmn_1.te);
    if (a2pock_1.ipcerr < 0) {
	goto L1800;
    }
    aerr_(&c__3508);
L1800:
    return 0;
} /* apockb_ */

#undef pttype
#undef ovride
#undef ofsetf
#undef ofsetc
#undef frthre
#undef pocdat
#undef radeff
#undef frtwo
#undef frone
#undef cor
#undef ab


