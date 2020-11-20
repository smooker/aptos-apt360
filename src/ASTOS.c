/* ASTOS.f -- translated by f2c (version 20000121).
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
    doublereal bdum[2100];
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

static struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

/* Table of constant values */

static integer c__5 = 5;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__1 = 1;
static integer c__1100 = 1100;

/* Subroutine */ int astos_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_2 = { {'A', 'S', 'T', 'O', 'S', 'T', 'P', ' '}, (float)0. };

#define ab ((real *)&equiv_2)


    extern /* Subroutine */ int atape_(), avsto_(), bdyndp_(), cdyndp_(), 
	    adyndp_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/*     ASTOS SUBROUTINE STORES SPECIFIED POINT (AND TLAXIS IF MULTIAXIS) */
/*     IN TCDAT. IF TCDAT IS FULL, IT IS WRITTEN ON CLTAPE BY ATAPE */
/*     AND RESTARTED. */
/*     PROGRAM */
    bdyndp_(ab, &c__5, &c_n1);
    cdyndp_(&c__2, &c__1);
    adyndp_(ab, &c__5, &c__1100);
    if (a2cmmn_1.nw - 240 >= 0) {
	goto L180;
    } else {
	goto L181;
    }
L180:
    atape_();

L181:
    avsto_(a2cmmn_1.te, &a2cmmn_1.tcdat[a2cmmn_1.nw]);
    a2cmmn_1.nw += 3;
/*        2Q65 MESSES WITH KFLAG3 HERE */
    if (a2dydp_1.kdynfq[6] <= a2cmmn_1.nw / (a2cmmn_1.mulout * 3 + 3)) {
	a2dydp_1.kdynfq[6] = 0;
    }
/*     THIS ZEROES OUT KDYNFQ(7) AFTER THE NUMBER OF POINTS SPECIFIED */
/*     HAVE BEEN COMPUTED. KDYNFQ(7).NE.0  INHIBITS DYNAMIC DUMPING */
/* L184: */
    if (a2cmmn_1.mulout != 0) {
	goto L182;
    } else {
	goto L183;
    }
L182:
    avsto_(a2cmmn_1.ta, &a2cmmn_1.tcdat[a2cmmn_1.nw]);
    a2cmmn_1.nw += 3;
L183:
    return 0;
} /* astos_ */

#undef ab


