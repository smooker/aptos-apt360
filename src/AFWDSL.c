/* AFWDSL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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
	    qnul, qfil[10];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__5 = 5;
static integer c__1100 = 1100;
static integer c__504 = 504;

/* Subroutine */ int afwdsl_(iii)
integer *iii;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_6 = { {'A', 'F', 'W', 'D', 'S', 'L', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_6)


    static integer ier1, ier2, ier3, itry;
    extern /* Subroutine */ int aerr_(), avsub_(), avsto_(), adyndp_(), 
	    avcros_(), avnorm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ...  TO SELECT THE FORWARD DIRECTION  (FWD) */
/* ...      III = 0  ALLOW ERROR EXIT TO AERR */
/* ...      III = 1  DISABLE ERROR EXIT TO AERR */
/* ...  AFWDSL IS USED PRIMARILY BY AREPRE TO SET UP THE FORWARD DIRECTION */
/* ...  OF MOTION BUT IS ALSO USED BY ATINKR IN CERTAIN MULTI-AXIS STARTUP */
/* ...  CASES. WHEN CALLED FROM ATINKR, THE ERROR EXIT IS DISABLED. */
/* ... A2CMMN START */
/* ... A2CMMN END */

    adyndp_(ab, &c__5, &c__1100);

    avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.fwd);
    itry = 1;
L1:
    avnorm_(a2cmmn_1.fwd, a2cmmn_1.fwd, &ier1);
    avcros_(a2cmmn_1.fwd, a2cmmn_1.ta, a2cmmn_1.rgt);
    avnorm_(a2cmmn_1.rgt, a2cmmn_1.rgt, &ier2);
    avcros_(a2cmmn_1.ta, a2cmmn_1.rgt, a2cmmn_1.fwd);
    avnorm_(a2cmmn_1.fwd, a2cmmn_1.fwd, &ier1);
/* L2: */
    avcros_(a2cmmn_1.rgt, a2cmmn_1.fwd, a2cmmn_1.up);
    avnorm_(a2cmmn_1.up, a2cmmn_1.up, &ier3);
    if (ier1 + ier2 + ier3 == 0) {
	goto L10;
    }
/* ... */
/* ...                     FORWARD DIRECTION CAN NOT BE DETERMINED (504) */
    if (itry != 1 && *iii != 1) {
	aerr_(&c__504);
    }
    if (itry != 1) {
	return 0;
    }
    itry = 2;
/* ...  IF ANY OF THE NORMALIZATIONS FAIL, TRY THE SAME STEPS USING PMOVE */
/* ...  AS THE INITIAL FWD. IF THIS SECOND TRY FAILS, CALL AERR(504). */
    avsto_(a2cmmn_1.pmove, a2cmmn_1.fwd);
    goto L1;



L10:

/* ...  COMMON CELL IGO IS SET AS SHOWN IN THE FOLLOWING TABLE BELOW. */
/* ...  IT IS USED AS A BRANCHING INDICATOR TO SET THE TRUE FORWARD */
/* ...  DIRECTION AS INDICATED. */
/* ...              IGO        FWD */
/* ...  GOLFT        1     FWD = -RGT */
/* ...  GORGT        2     FWD =  RGT */
/* ...  GOFWD        3     FWD =  FWD */
/* ...  GOBACK       4     FWD = -FWD */
/* ...  GOUP         5     FWD =  UP */
/* ...  GODOWN       6     FWD = -UP */
/* ... */
    switch ((int)a2cmmn_1.igo) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
    }
L100:
    avsub_(a2cmmn_1.vnul, a2cmmn_1.rgt, a2cmmn_1.fwd);
    goto L300;
L200:
    avsto_(a2cmmn_1.rgt, a2cmmn_1.fwd);
/* ............................ */
L300:
    return 0;
L400:
    avsub_(a2cmmn_1.vnul, a2cmmn_1.fwd, a2cmmn_1.fwd);
    goto L300;
L500:
    avsto_(a2cmmn_1.up, a2cmmn_1.fwd);
    goto L300;
L600:
    avsub_(a2cmmn_1.vnul, a2cmmn_1.up, a2cmmn_1.fwd);
    goto L300;
} /* afwdsl_ */

#undef ab


