/* ATLTST.f -- translated by f2c (version 20000121).
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
	    qnul, qpie, q100p, qfil[8];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__5 = 5;
static integer c_b3 = 100000;

/* Subroutine */ int atltst_(iret)
integer *iret;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_4 = { {'A', 'T', 'L', 'T', 'S', 'T', 'T', 'P'}, (float)0. };

#define ab ((real *)&equiv_4)


    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal qq1, taut;
    extern /* Subroutine */ int avsto_(), adyndp_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     NOTE AMIND COMPUTES DISTANCE TO POINT 1110 OF TOLERANCE BAND */
/*     FROM SURFACE WITH GREATEST RADIUS OF CURVATURE EXCEPT IN PLANE */
/*     CASE, WHEN DISTANCE IS EXACT. */

/*     NOTE... RC IS NEGATIVE WHEN CUTTER IS ON CONCAVE SIDE OF */
/*     SURFACE... IE. INSIDE CYLINDER */
    adyndp_(ab, &c__5, &c_b3);
    *iret = 0;
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] == 1) {
	goto L10;
    }
/*     NOT A PLANE */
    qq1 = a2cmmn_1.rc[a2cmmn_1.is - 1] * a2cmmn_1.s[a2cmmn_1.is - 1];
    if (a2cmmn_1.jtn[a2cmmn_1.iis - 1] == 1) {
	qq1 = -qq1;
    }
    if (qq1 < a2fpc_1.qnul && (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) 
	    > a2fpc_1.qp9 * a2cmmn_1.tau[a2cmmn_1.is - 1] + a2fpc_1.qp4x05) {
	*iret = 1;
    }
    if (qq1 > a2fpc_1.qnul && (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) 
	    > a2fpc_1.qp1 * a2cmmn_1.tau[a2cmmn_1.is - 1] + a2fpc_1.qp4x05) {
	*iret = 1;
    }

    if (a2cmmn_1.is != a2cmmn_1.ids) {
	goto L12;
    }

/* ...  SET UP PERCENTAGE OF TOLERANCE BAND USED FOR POSSIBLE USE BY TWO D */
/*     ROUTE */
/*     . . . . . */
/*     USE VTEM(1) TO TRANSMIT THIS VALUE BACK TO AREPRE */

    a2cmmn_1.qequiv[0] = a2fpc_1.q1p;
    if (qq1 < a2fpc_1.qnul) {
	a2cmmn_1.qequiv[0] = -a2fpc_1.q1p;
    }
    a2cmmn_1.vtem[0] = (a2fpc_1.qp9 * a2cmmn_1.tau[a2cmmn_1.is - 1] + 
	    a2cmmn_1.qequiv[0] * (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(
	    d__1))) / a2cmmn_1.tau[a2cmmn_1.is - 1] * a2fpc_1.q100p;
L12:
    if (a2cmmn_1.jap == 0) {
	return 0;
    }


    if (*iret != 0) {
	return 0;
    }
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tpk[a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.snk[a2cmmn_1.is - 1]);
    return 0;

/*     PLANE CASE */
/* ... */
/* ...  IF S IS NEGATIVE, PERCEN = ((|INTOL| - |S|) / TOTAL TOL) * 100 */
/* ...  IF S IS POSITIVE, PERCEN = ((|INTOL| + S) / TOTAL TOL) * 100 */
/* ...  VALUE OF PERCEN TRANSMITTED BACK TO AREPRE BY VTEM(1) */
/* ...  FOR POSSIBLE USE BY ARLM2 */
L10:
    a2cmmn_1.vtem[0] = ((d__1 = a2cmmn_1.tau2[a2cmmn_1.is - 1], abs(d__1)) + 
	    a2cmmn_1.s[a2cmmn_1.is - 1]) / a2cmmn_1.tau[a2cmmn_1.is - 1] * 
	    a2fpc_1.q100p;
    if (a2cmmn_1.s[a2cmmn_1.is - 1] == a2fpc_1.qnul) {
	return 0;
    }
    taut = a2cmmn_1.tau1[a2cmmn_1.is - 1] + a2fpc_1.qp4x05;
    if (a2cmmn_1.itlon[a2cmmn_1.iis - 1] == 0 && (d__1 = a2cmmn_1.s[
	    a2cmmn_1.is - 1], abs(d__1)) < taut) {
	goto L12;
    }
    if (a2cmmn_1.s[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	taut = (d__1 = a2cmmn_1.tau2[a2cmmn_1.is - 1], abs(d__1)) + 
		a2fpc_1.qp4x05;
    }
    if ((d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) > taut) {
	*iret = 1;
    }
    goto L12;
} /* atltst_ */

#undef ab


