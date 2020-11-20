/* ABKKPR.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal adum[600];
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
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

/* Table of constant values */

static integer c__5 = 5;
static integer c__11 = 11;

/* Subroutine */ int abkkpr_(ibmn, jb)
integer *ibmn, *jb;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_7 = { {'A', 'B', 'K', 'K', 'P', 'R', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_7)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, n1, n2, mm, isign;
    extern /* Subroutine */ int adyndp_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/*      BOOK KEEPER FOR MOVING CANONICAL FORMS OF DS AND CS */
/* ... A2CMMN START */
/* ... A2CMMN END */
    a2cmmn_1.n = *ibmn;
    a2cmmn_1.ja = *jb;
    adyndp_(ab, &c__5, &c__11);
/* ...  DRIVE OR CHECK SURFACE */
/* L10: */
    if (a2cmmn_1.n == 3) {
	goto L60;
    }
/* ...  DRIVE SURFACE */
/* L20: */
    n1 = a2cmmn_1.ipontr[a2cmmn_1.iids - 1];
/* L30: */
    n2 = n1 + a2cmmn_1.lofs[a2cmmn_1.iids - 1] - 1;
/* ...  UPDATE IPONTR POINTER */
/* L40: */
    a2cmmn_1.ipontr[a2cmmn_1.iids - 1] += a2cmmn_1.ja;
/* L50: */
    goto L200;
/* ...  CHECK SURFACE(S) */
L60:
    n1 = a2cmmn_1.ipontr[a2cmmn_1.iics - 1];
/* L70: */
    n2 = a2cmmn_1.jtused;
/* ...  UPDATE ALL IPONTR POINTERS USED FOR CHECK SURFACES */
/* L80: */
    i__1 = a2cmmn_1.numsfs;
    for (i__ = 3; i__ <= i__1; ++i__) {
/* L90: */
	a2cmmn_1.k = a2cmmn_1.lisv * (i__ - 1) + 1;
/* L100: */
	mm = a2cmmn_1.ipontr[a2cmmn_1.k - 1] + a2cmmn_1.lofs[a2cmmn_1.k - 1];
/* L110: */
	a2cmmn_1.ipontr[a2cmmn_1.k - 1] += a2cmmn_1.ja;
/* L120: */
	if (a2cmmn_1.k == a2cmmn_1.jtused) {
	    goto L200;
	}
/* L130: */
    }
L200:
    a2cmmn_1.k = n2 - n1 + 1;
/* ...  IS IT FORWARD OR BACKWARD SHIFT */
/* L210: */
    if (a2cmmn_1.ja < 0) {
	goto L220;
    } else if (a2cmmn_1.ja == 0) {
	goto L330;
    } else {
	goto L250;
    }
/* ...  BACKWARD */
L220:
    n2 = n1 + a2cmmn_1.ja;
/* L230: */
    isign = 1;
/* L240: */
    goto L280;
/* ...  FORWARD */
L250:
    n1 = n2;
/* L260: */
    n2 = n1 + a2cmmn_1.ja;
/* L270: */
    isign = -1;
/* ...  ALL SET--SH1FT CANON1CAL FORMS */
L280:
    i__1 = a2cmmn_1.k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L290: */
	a2cmmn_1.cansto[n2 - 1] = a2cmmn_1.cansto[n1 - 1];
/* L300: */
	n1 += isign;
/* L310: */
	n2 += isign;
/* L320: */
    }
L330:

    return 0;
} /* abkkpr_ */

#undef ab


