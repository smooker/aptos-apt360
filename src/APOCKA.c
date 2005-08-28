/* APOCKA.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
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

struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

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

struct {
    integer ipcerr, iwdcnt, nwd, ibm1, ibm2, ibm3, ibm4, ibm6;
} a2pock_;

#define a2pock_1 a2pock_

struct {
    integer jone, nc, ncorig, jtwo, jthr, jfou, kalc, move, init, ncutbk, 
	    nplus1, nless1, icrsto, ktab[20], kutbac, kolaps, jsave, inter, 
	    kone, ktwo, jdummy, num, itest, kt1, kt2, kover;
} a2pok2_;

#define a2pok2_1 a2pok2_

/* Table of constant values */

static integer c__3501 = 3501;
static integer c__3502 = 3502;
static integer c__3504 = 3504;
static integer c__3503 = 3503;
static integer c__3510 = 3510;

/* Subroutine */ int apocka_()
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, jj;
#define cor ((doublereal *)&a2cmmn_1 + 1317)
    extern /* Subroutine */ int aerr_();
    static integer ierr;
#define frone ((doublereal *)&a2cmmn_1 + 1312)
#define frtwo ((doublereal *)&a2cmmn_1 + 1313)
    extern /* Subroutine */ int avsub_(), avdot_();
#define radeff ((doublereal *)&a2cmmn_1 + 1309)
#define pocdat ((doublereal *)&a2cmmn_1 + 1308)
#define frthre ((doublereal *)&a2cmmn_1 + 1314)
#define ofsetc ((doublereal *)&a2cmmn_1 + 1310)
#define ofsetf ((doublereal *)&a2cmmn_1 + 1311)
#define ovride ((doublereal *)&a2cmmn_1 + 1315)
#define pttype ((doublereal *)&a2cmmn_1 + 1316)
    extern /* Subroutine */ int avcros_(), avnorm_(), avmult_();

/* ... A2CMMN START */
/* ... A2CMMN END */
/*     EQUIVALENCE FOR POCKET */
    switch ((int)a2cmmn_1.jgr) {
	case 1:  goto L470;
	case 2:  goto L480;
	case 3:  goto L490;
	case 4:  goto L500;
	case 5:  goto L510;
	case 6:  goto L550;
	case 7:  goto L590;
	case 8:  goto L90;
	case 9:  goto L245;
    }
L90:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = a2pok8_1.xi[i__ + a2cmmn_1.j * 3 - 4] - cor[i__ + 
		    a2cmmn_1.j * 3 - 4], abs(d__1)) - a2fpc_1.qp0005 <= 0.) {
		goto L100;
	    } else {
		goto L110;
	    }
L100:
	    ;
	}
	aerr_(&c__3501);
L110:
	;
    }
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = a2pok8_1.u[i__ + (a2cmmn_1.j + 1) * 3 - 4] - 
		    a2pok8_1.u[i__ + a2cmmn_1.j * 3 - 4], abs(d__1)) - 
		    a2fpc_1.qp0005 <= 0.) {
		goto L120;
	    } else {
		goto L130;
	    }
L120:
	    ;
	}
	aerr_(&c__3502);
L130:
	;
    }
    a2pok2_1.icrsto = 1;
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	avsub_(a2cmmn_1.vnul, &a2pok8_1.u[a2cmmn_1.j * 3 - 3], 
		a2pok8_1.crosto);
	avcros_(a2pok8_1.crosto, &a2pok8_1.u[(a2cmmn_1.j + 1) * 3 - 3], 
		a2pok8_1.crosto);
	avnorm_(a2pok8_1.crosto, a2pok8_1.ucrsto, &ierr);
	if (a2pok2_1.icrsto <= 0) {
	    goto L160;
	} else {
	    goto L140;
	}
L140:
	for (i__ = 1; i__ <= 3; ++i__) {
/* L150: */
	    a2pok8_1.tcrsto[i__ - 1] = a2pok8_1.ucrsto[i__ - 1];
	}
	a2pok2_1.icrsto = 0;
	goto L180;
L160:
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = a2pok8_1.ucrsto[i__ - 1] - a2pok8_1.tcrsto[i__ - 1], 
		    abs(d__1)) - a2fpc_1.qp0005 <= 0.) {
		goto L170;
	    } else {
		goto L270;
	    }
L170:
	    ;
	}
L180:
	;
    }
    return 0;
L270:
    for (i__ = 1; i__ <= 3; ++i__) {
	if ((d__3 = (d__1 = a2pok8_1.ucrsto[i__ - 1], abs(d__1)) - (d__2 = 
		a2pok8_1.tcrsto[i__ - 1], abs(d__2)), abs(d__3)) - 
		a2fpc_1.qp0005 <= 0.) {
	    goto L280;
	} else {
	    goto L290;
	}
L280:
	;
    }
    aerr_(&c__3504);
L290:
    aerr_(&c__3503);
    return 0;
L245:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	avdot_(a2cmmn_1.ta, &a2pok8_1.u[a2cmmn_1.j * 3 - 3], &a2pok8_1.addem1)
		;
	avdot_(a2cmmn_1.ta, &a2pok8_1.u[(a2cmmn_1.j + 1) * 3 - 3], &
		a2pok8_1.addem2);
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok8_1.qone[i__ - 1] = a2pok8_1.u[i__ + a2cmmn_1.j * 3 - 4] - 
		    a2cmmn_1.ta[i__ - 1] * a2pok8_1.addem1;
/* L250: */
	    a2pok8_1.wone[i__ - 1] = a2pok8_1.u[i__ + (a2cmmn_1.j + 1) * 3 - 
		    4] - a2cmmn_1.ta[i__ - 1] * a2pok8_1.addem2;
	}
	avnorm_(a2pok8_1.qone, a2pok8_1.qone, &ierr);
	avnorm_(a2pok8_1.wone, a2pok8_1.wone, &ierr);
	avsub_(a2pok8_1.wone, a2pok8_1.qone, a2pok8_1.t);
	avnorm_(a2pok8_1.t, a2pok8_1.t, &ierr);
	avdot_(a2pok8_1.t, a2pok8_1.wone, &a2cmmn_1.alpha);
/* Computing 2nd power */
	d__2 = a2cmmn_1.alpha;
	a2cmmn_1.alpha = a2pok8_1.cutrad / sqrt((d__1 = a2fpc_1.q1p - d__2 * 
		d__2, abs(d__1)));
	avmult_(a2pok8_1.t, &a2cmmn_1.alpha, a2pok8_1.y);
	avdot_(a2pok8_1.y, a2pok8_1.tcrsto, &a2cmmn_1.alpha);
	avdot_(a2cmmn_1.ta, a2pok8_1.tcrsto, &a2pok8_1.x1);
	for (i__ = 1; i__ <= 3; ++i__) {
/* L260: */
	    cor[i__ + a2cmmn_1.j * 3 - 4] = cor[i__ + a2cmmn_1.j * 3 - 4] + 
		    a2pok8_1.y[i__ - 1] - a2cmmn_1.alpha * a2cmmn_1.ta[i__ - 
		    1] / a2pok8_1.x1;
	}
/* L261: */
    }
    return 0;
L470:
    a2pok2_1.move = 2;
    goto L490;
L480:
    a2pok2_1.move = 3;
L490:
    a2pok8_1.deldst = a2fpc_1.qp5 * *ofsetf * a2pok8_1.cutrad;
    goto L520;
L500:
    a2pok2_1.move = 4;
L510:
    a2pok8_1.deldst = a2fpc_1.qp5 * *ofsetc * a2pok8_1.cutrad;
L520:
    a2pok8_1.dist += a2pok8_1.deldst;
/* L530: */
    if (a2pok2_1.kalc <= 0) {
	goto L540;
    } else {
	goto L550;
    }
L540:
    a2pok2_1.kalc = 1;
    goto L560;
L550:
    a2pok2_1.kalc = 0;
/*     EXIT IF ZERO DIAMETER CUTTER */
L560:
    if (a2pok8_1.cutrad > a2fpc_1.qnul) {
	goto L570;
    }
    aerr_(&c__3510);
L570:
    if (a2pok2_1.jfou <= 0) {
	goto L590;
    } else {
	goto L580;
    }
L580:
    *ofsetc = a2pok8_1.ofcsto;
    *ofsetf = a2pok8_1.offsto;
    a2pok2_1.jfou = 1;
L590:
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L600: */
	    a2pok8_1.xiprim[i__ + a2cmmn_1.j * 3 - 4] = cor[i__ + a2cmmn_1.j *
		     3 - 4] + a2pok8_1.dist / a2pok8_1.bl[a2cmmn_1.j - 1] * 
		    a2pok8_1.w[i__ + a2cmmn_1.j * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L610: */
	a2pok8_1.xiprim[i__ + (a2pok2_1.nc + 1) * 3 - 4] = a2pok8_1.xiprim[
		i__ - 1];
    }
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	a2pok8_1.addem1 = a2fpc_1.qnul;
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok8_1.vprim[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.xiprim[i__ + (
		    a2cmmn_1.j + 1) * 3 - 4] - a2pok8_1.xiprim[i__ + 
		    a2cmmn_1.j * 3 - 4];
/* L620: */
/* Computing 2nd power */
	    d__1 = a2pok8_1.vprim[i__ + a2cmmn_1.j * 3 - 4];
	    a2pok8_1.addem1 = d__1 * d__1 + a2pok8_1.addem1;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* L630: */
	    a2pok8_1.uprim[i__ + a2cmmn_1.j * 3 - 4] = a2pok8_1.vprim[i__ + 
		    a2cmmn_1.j * 3 - 4] / sqrt((abs(a2pok8_1.addem1)));
	}
    }
/*     COLLAPSE TESTS */
/* L640: */
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	a2pok2_1.ktab[a2cmmn_1.j - 1] = 0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = a2pok8_1.u[i__ + (a2cmmn_1.j + 1) * 3 - 4] - 
		    a2pok8_1.uprim[i__ + a2cmmn_1.j * 3 - 4], abs(d__1)) - 
		    a2fpc_1.qp005 <= 0.) {
		goto L644;
	    } else {
		goto L642;
	    }
L642:
	    a2pok2_1.ktab[a2cmmn_1.j - 1] = 1;
L644:
	    ;
	}
    }
L646:
    a2pok2_1.ncutbk = a2pok2_1.nc;
    a2pok2_1.kutbac = 0;
    a2pok2_1.kolaps = 0;
    a2pok8_1.phitmp = a2fpc_1.q1p;
    i__1 = a2pok2_1.nc;
    for (a2cmmn_1.j = 1; a2cmmn_1.j <= i__1; ++a2cmmn_1.j) {
	if (a2pok2_1.ktab[a2cmmn_1.j - 1] <= 0) {
	    goto L650;
	} else {
	    goto L780;
	}
L650:
	if (a2pok2_1.jone <= 0) {
	    goto L710;
	} else {
	    goto L655;
	}
L655:
	a2pok2_1.jone = 0;
/* L660: */
	if (a2pok2_1.kutbac - a2cmmn_1.j + 1 != 0) {
	    goto L680;
	} else {
	    goto L670;
	}
L670:
	a2pok2_1.jsave = a2cmmn_1.j;
	a2pok2_1.kolaps = 0;
	goto L950;
L680:
	a2pok2_1.inter = 1;
	a2pok2_1.kone = a2cmmn_1.j - a2pok2_1.kolaps - 1;
	a2pok2_1.ktwo = a2cmmn_1.j;
	goto L890;
L690:
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok2_1.jdummy = a2cmmn_1.j - a2pok2_1.kutbac;
/* L700: */
	    a2pok8_1.ctemp[i__ + a2pok2_1.jdummy * 3 - 4] = a2pok8_1.ptint[
		    i__ - 1];
	}
	a2pok2_1.kolaps = 0;
	goto L730;
L710:
	for (i__ = 1; i__ <= 3; ++i__) {
	    a2pok2_1.jdummy = a2cmmn_1.j - a2pok2_1.kutbac;
/* L720: */
	    a2pok8_1.ctemp[i__ + a2pok2_1.jdummy * 3 - 4] = a2pok8_1.xiprim[
		    i__ + a2cmmn_1.j * 3 - 4];
	}
L730:
	if (a2cmmn_1.j - a2pok2_1.nc >= 0) {
	    goto L740;
	} else {
	    goto L950;
	}
L740:
	if (a2pok2_1.jtwo <= 0) {
	    goto L950;
	} else {
	    goto L745;
	}
L745:
	a2pok2_1.jtwo = 0;
/* L750: */
	a2pok2_1.inter = 2;
	a2pok2_1.kone = a2cmmn_1.j;
	a2pok2_1.ktwo = a2pok2_1.jsave;
	goto L890;
L760:
	for (i__ = 1; i__ <= 3; ++i__) {
/* L770: */
	    a2pok8_1.ctemp[i__ - 1] = a2pok8_1.ptint[i__ - 1];
	}
	goto L950;
L780:
	--a2pok2_1.ncutbk;
	++a2pok2_1.kutbac;
	++a2pok2_1.kolaps;
	a2pok2_1.jone = 1;
	if (a2cmmn_1.j - 1 <= 0) {
	    goto L790;
	} else {
	    goto L800;
	}
L790:
	a2pok2_1.jtwo = 1;
	goto L950;
L800:
	if (a2cmmn_1.j - a2pok2_1.nc >= 0) {
	    goto L810;
	} else {
	    goto L950;
	}
L810:
	if (a2pok2_1.ncutbk - 1 <= 0) {
	    goto L820;
	} else {
	    goto L850;
	}
L820:
	a2pok2_1.move = 5;
	if (a2pok2_1.kalc <= 0) {
	    goto L830;
	} else {
	    goto L825;
	}
L825:
	a2pok2_1.num = 1;
	if (a2pock_1.ibm2 <= 0) {
	    goto L826;
	} else {
	    goto L827;
	}
L826:
	a2cmmn_1.jgr = 1;
	return 0;
L827:
	a2cmmn_1.jgr = 2;
	return 0;
L830:
	i__2 = a2pok2_1.nc;
	for (jj = 1; jj <= i__2; ++jj) {
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L840: */
		a2pok8_1.xiprim[i__ + jj * 3 - 4] = a2pok8_1.ctemp[i__ + jj * 
			3 - 4];
	    }
	}
	a2cmmn_1.jgr = 3;
	return 0;
L850:
	if (a2pok2_1.jtwo <= 0) {
	    goto L880;
	} else {
	    goto L855;
	}
L855:
	a2pok2_1.jtwo = 0;
/* L860: */
	a2pok2_1.ktwo = a2pok2_1.jsave;
L870:
	a2pok2_1.inter = 2;
	a2pok2_1.kone = a2cmmn_1.j - a2pok2_1.kolaps;
	goto L890;
L880:
	a2pok2_1.ktwo = 1;
	goto L870;
/*     CALCULATE INTERSECTION OF NON-COLLAPSING SIDES */
L890:
	a2pok2_1.itest = 1;
	a2pok2_1.kt1 = a2pok2_1.kone;
	a2pok2_1.kt2 = a2pok2_1.ktwo;
L895:
	avdot_(&a2pok8_1.uprim[a2pok2_1.kt1 * 3 - 3], &a2pok8_1.uprim[
		a2pok2_1.kt2 * 3 - 3], &a2pok8_1.cosva);
	a2pok8_1.addem2 = sqrt((d__1 = (a2fpc_1.q1p + a2pok8_1.cosva) / 
		a2fpc_1.q2p, abs(d__1)));
	if (a2pok8_1.addem2 - a2pok8_1.phitmp >= 0.) {
	    goto L898;
	} else {
	    goto L896;
	}
L896:
	a2pok8_1.phitmp = a2pok8_1.addem2;
L898:
/* Computing 2nd power */
	d__1 = a2pok8_1.cosva;
	a2pok8_1.sin2va = a2fpc_1.q1p - d__1 * d__1;
	if (a2pok8_1.sin2va - a2fpc_1.qp0001 <= 0.) {
	    goto L2140;
	} else {
	    goto L2340;
	}
/*     SIDES ARE NEARLY PARALLEL - TAKE AVERAGE OF TWO VERTICES */
L2140:
	for (a2cmmn_1.l = 1; a2cmmn_1.l <= 3; ++a2cmmn_1.l) {
/* L2240: */
	    a2pok8_1.ptint[a2cmmn_1.l - 1] = (a2pok8_1.xiprim[a2cmmn_1.l + (
		    a2pok2_1.kone + 1) * 3 - 4] + a2pok8_1.xiprim[a2cmmn_1.l 
		    + a2pok2_1.ktwo * 3 - 4]) / a2fpc_1.q2p;
	}
	goto L940;
/*     SIDES INTERSECT - COMPUTE INTERSECTION */
L2340:
	a2cmmn_1.alpha = a2fpc_1.qnul;
	for (a2cmmn_1.l = 1; a2cmmn_1.l <= 3; ++a2cmmn_1.l) {
/* L2440: */
	    a2cmmn_1.alpha += (a2pok8_1.xiprim[a2cmmn_1.l + a2pok2_1.kt2 * 3 
		    - 4] - a2pok8_1.xiprim[a2cmmn_1.l + a2pok2_1.kt1 * 3 - 4])
		     * (a2pok8_1.uprim[a2cmmn_1.l + a2pok2_1.kt1 * 3 - 4] - 
		    a2pok8_1.uprim[a2cmmn_1.l + a2pok2_1.kt2 * 3 - 4] * 
		    a2pok8_1.cosva);
	}
	a2cmmn_1.alpha /= a2pok8_1.sin2va;
	a2pok8_1.addem1 = a2fpc_1.qnul;
	for (a2cmmn_1.l = 1; a2cmmn_1.l <= 3; ++a2cmmn_1.l) {
/* L2540: */
/* Computing 2nd power */
	    d__1 = a2pok8_1.xiprim[a2cmmn_1.l + (a2pok2_1.kt1 + 1) * 3 - 4] - 
		    a2pok8_1.xiprim[a2cmmn_1.l + a2pok2_1.kt1 * 3 - 4];
	    a2pok8_1.addem1 += d__1 * d__1;
	}
	a2pok8_1.addem1 = sqrt((abs(a2pok8_1.addem1)));
	switch ((int)a2pok2_1.itest) {
	    case 1:  goto L2640;
	    case 2:  goto L2740;
	    case 3:  goto L3040;
	    case 4:  goto L3340;
	    case 5:  goto L3540;
	    case 6:  goto L3840;
	}
L2640:
	if (a2cmmn_1.alpha < 0.) {
	    goto L2650;
	} else if (a2cmmn_1.alpha == 0) {
	    goto L2140;
	} else {
	    goto L3140;
	}
L2650:
	--a2pok2_1.kt1;
	if (a2pok2_1.kt1 <= 0) {
	    goto L2680;
	} else {
	    goto L2660;
	}
L2660:
	if (a2pok2_1.ktab[a2pok2_1.kt1 - 1] <= 0) {
	    goto L2670;
	} else {
	    goto L2650;
	}
L2670:
	a2pok2_1.itest = 2;
	goto L895;
L2680:
	a2pok2_1.kt1 = a2pok2_1.nc;
L2690:
	if (a2pok2_1.ktab[a2pok2_1.kt1 - 1] <= 0) {
	    goto L2670;
	} else {
	    goto L2700;
	}
L2700:
	--a2pok2_1.kt1;
	if (a2pok2_1.kt1 - a2pok2_1.kt2 <= 0) {
	    goto L2140;
	} else {
	    goto L2690;
	}
L2740:
	if (a2cmmn_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L2840;
	}
L2840:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 <= 0.) {
	    goto L2940;
	} else {
	    goto L2140;
	}
L2940:
	a2pok2_1.kt2 = a2pok2_1.kt1;
	a2pok2_1.kt1 = a2pok2_1.ktwo;
	a2pok2_1.itest = 3;
	goto L2340;
L3040:
	if (a2cmmn_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3050;
	}
L3050:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 <= 0.) {
	    goto L3060;
	} else {
	    goto L2140;
	}
/*     SIDE OUTSIDE POLYGON - PLACE SIDE IN COLLAPSE CONDITION */
L3060:
	a2pok2_1.ktab[a2pok2_1.kone - 1] = 1;
	goto L3870;
L3140:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 >= 0.) {
	    goto L2140;
	} else {
	    goto L3240;
	}
L3240:
	a2pok2_1.kt1 = a2pok2_1.ktwo;
	a2pok2_1.kt2 = a2pok2_1.kone;
	a2pok2_1.itest = 4;
	goto L2340;
L3340:
	if (a2cmmn_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3350;
	}
L3350:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 <= 0.) {
	    goto L5940;
	} else {
	    goto L3440;
	}
L3440:
	a2pok2_1.kt1 = a2pok2_1.kt2;
	a2pok2_1.kt2 = a2pok2_1.ktwo;
L3450:
	++a2pok2_1.kt2;
	if (a2pok2_1.kt2 - a2pok2_1.nc <= 0) {
	    goto L3460;
	} else {
	    goto L3480;
	}
L3460:
	if (a2pok2_1.ktab[a2pok2_1.kt2 - 1] <= 0) {
	    goto L3470;
	} else {
	    goto L3450;
	}
L3470:
	a2pok2_1.itest = 5;
	goto L895;
L3480:
	a2pok2_1.kt2 = 1;
L3490:
	if (a2pok2_1.ktab[a2pok2_1.kt2 - 1] <= 0) {
	    goto L3470;
	} else {
	    goto L3510;
	}
L3510:
	++a2pok2_1.kt2;
	if (a2pok2_1.kt2 - a2pok2_1.kt1 - 1 >= 0) {
	    goto L2140;
	} else {
	    goto L3490;
	}
L3540:
	if (a2cmmn_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3640;
	}
L3640:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 <= 0.) {
	    goto L3740;
	} else {
	    goto L2140;
	}
L3740:
	a2pok2_1.kt1 = a2pok2_1.kt2;
	a2pok2_1.kt2 = a2pok2_1.kone;
	a2pok2_1.itest = 6;
	goto L2340;
L3840:
	if (a2cmmn_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3850;
	}
L3850:
	if (a2cmmn_1.alpha - a2pok8_1.addem1 <= 0.) {
	    goto L3860;
	} else {
	    goto L2140;
	}
/*     SIDE OUTSIDE POLYGON - PLACE SIDE IN COLLAPSE CONDITION */
L3860:
	a2pok2_1.ktab[a2pok2_1.ktwo - 1] = 1;
L3870:
	a2pok2_1.jone = 0;
/* L3880: */
	a2pok2_1.jtwo = 0;
	goto L646;
L5940:
	for (a2cmmn_1.l = 1; a2cmmn_1.l <= 3; ++a2cmmn_1.l) {
/* L6040: */
	    a2pok8_1.ptint[a2cmmn_1.l - 1] = a2pok8_1.xiprim[a2cmmn_1.l + 
		    a2pok2_1.kt1 * 3 - 4] + a2cmmn_1.alpha * a2pok8_1.uprim[
		    a2cmmn_1.l + a2pok2_1.kt1 * 3 - 4];
	}
L940:
	switch ((int)a2pok2_1.inter) {
	    case 1:  goto L690;
	    case 2:  goto L760;
	}
L950:
	;
    }
    a2cmmn_1.jgr = 4;
    return 0;
} /* apocka_ */

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


