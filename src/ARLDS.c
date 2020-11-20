/* ARLDS.f -- translated by f2c (version 20000121).
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
    doublereal adum[536];
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

static integer c__8 = 8;
static integer c__2 = 2;
static integer c__1401 = 1401;
static integer c__1402 = 1402;

/* Subroutine */ int arlds_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static doublereal a[3], b[3], d__[3], e[3];
#define f ((doublereal *)&a2cmmn_1 + 1408)
    static doublereal g;
    static integer i__;
#define p ((doublereal *)&a2cmmn_1 + 1408)
#define r__ ((doublereal *)&a2cmmn_1 + 1417)
#define w ((doublereal *)&a2cmmn_1 + 1408)
    static doublereal x[3], p0[3], q1[3], q2[3];
#define r2 ((doublereal *)&a2cmmn_1 + 1423)
#define r3 ((doublereal *)&a2cmmn_1 + 1420)
    static doublereal v1[3], w1[3], w2[3], v2[3], t1[3], s1[3], dc[3], fc[3];
#define pp ((doublereal *)&a2cmmn_1 + 1408)
#define wp ((doublereal *)&a2cmmn_1 + 1408)
#define vp ((doublereal *)&a2cmmn_1 + 1408)
#define zn ((doublereal *)&a2cmmn_1 + 1411)
#define sl ((doublereal *)&a2cmmn_1 + 1414)
    static doublereal cp[3], sc[3], dv[3];
    static integer lp, lw, lv;
    static doublereal ep;
    static integer ic1;
    static doublereal ep2, ep5, ep6, ut1[3], dcp[3], dvp[3];
    static integer lsd, lpp, lwp, lvp;
    static doublereal xll, sum, csl, csm, csn, sma, smb, dot, sig, beta;
    static integer icss, iops, j24ss, loop, ls1m3, ls2m3;
    static doublereal delt, alph;
    extern /* Subroutine */ int aerr_();
    static doublereal sign1, sign2;
#define delta ((doublereal *)&a2cmmn_1 + 1409)
    static doublereal sigma;
    extern /* Subroutine */ int avsto_(), astor_();
#define zlambd ((doublereal *)&a2cmmn_1 + 1410)
    extern /* Subroutine */ int anrmal_(), avleng_(), addstr_();
    static integer iguess;
    extern /* Subroutine */ int avcros_();
    static doublereal savesp[3];
    extern /* Subroutine */ int avnorm_();
    static integer ipntrs;

/*     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 *** */
/* 2433  RULED SURFACE FOR SYSTEM/360 SECTION 2 */
/*     COMMON, DIMENSION AND EQUIVALENCE FOR ARLDSR */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     VARIABLES NOT IN SECTION 2 COMMON */
/*     VARIABLES NOT IN COMMON */

/*     STORE TOOL NORMAL LOCALLY */

/* L100: */
    d__[0] = a2cmmn_1.tn[a2cmmn_1.is - 1];
    d__[1] = a2cmmn_1.tn[a2cmmn_1.is];
    d__[2] = a2cmmn_1.tn[a2cmmn_1.is + 1];

/*     STORE TOOL POINT LOCALLY */

    p0[0] = a2cmmn_1.tp[a2cmmn_1.is - 1];
    p0[1] = a2cmmn_1.tp[a2cmmn_1.is];
    p0[2] = a2cmmn_1.tp[a2cmmn_1.is + 1];

/*     SAVE */

    icss = a2cmmn_1.ic;
    iops = a2cmmn_1.iop[a2cmmn_1.iis - 1];
    j24ss = a2cmmn_1.j24[a2cmmn_1.iis - 1];
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], savesp);

/*     INITIALIZE */

    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
    iguess = 0;
    loop = 25;
    ep2 = 1e-5;

/*     COMPUTE VARIABLE SUBSCRIPTS */

/* 200  **** CARDS 1240 - 1370 360 VERSION */
/* L200: */
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 2], &c__8, &ic1, &c__2);
    lsd = a2cmmn_1.ic + ic1 + 4;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 3], &c__8, &ic1, &c__2);
    ls1m3 = a2cmmn_1.ic + ic1 - 1;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 4], &c__8, &ic1, &c__2);
    lp = a2cmmn_1.ic + ic1 + 2;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 5], &c__8, &ic1, &c__2);
    lw = a2cmmn_1.ic + ic1 + 2;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 6], &c__8, &ic1, &c__2);
    lv = a2cmmn_1.ic + ic1 + 2;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 7], &c__8, &ic1, &c__2);
    ls2m3 = a2cmmn_1.ic + ic1 - 1;

/*     COMPUTE UNIT VECTOR DV  PARALEL TO CHORD(1) */

    q1[0] = p[lp - 1];
    q1[1] = p[lp];
    q1[2] = p[lp + 1];
    w1[0] = w[lw - 1] - q1[0];
    w1[1] = w[lw] - q1[1];
    w1[2] = w[lw + 1] - q1[2];
    avnorm_(w1, dv, &a2cmmn_1.ier);

/*     STORE LENGTH OF DV  IN EP5 */

    avleng_(w1, &ep5);

/*     STORE VECTOR (1) LOCALLY */

    v1[0] = f[lv - 1];
    v1[1] = f[lv];
    v1[2] = f[lv + 1];

/*     BRANCH TO 201 IF POINT AND CURVE FORMAT (FORMAT A ) */
/*     202 IF TWO CURVE FORMAT (FORMAT B ) */

    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 2], &c__8, &ic1, &c__2);
    if (ic1 - 5 != 0) {
	goto L202;
    } else {
	goto L201;
    }

/*     FORMAT A  STORE POINT IN CP AND ZERO OUT DCP */

L201:
    cp[0] = pp[ls2m3 + 2];
    cp[1] = pp[ls2m3 + 3];
    cp[2] = pp[ls2m3 + 4];
    dcp[0] = 0.;
    dcp[1] = 0.;
    dcp[2] = 0.;

    goto L300;

/*     FORMAT B  COMPUTE VARIABLE SUBSCRIPTS FOR SECOND CURVE */

/* 202  **** CARDS 1530 - 1580 360 VERSION */
L202:
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 8], &c__8, &ic1, &c__2);
    lpp = a2cmmn_1.ic + ic1 + 2;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 9], &c__8, &ic1, &c__2);
    lwp = a2cmmn_1.ic + ic1 + 2;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 10], &c__8, &ic1, &c__2);
    lvp = a2cmmn_1.ic + ic1 + 2;

/*     COMPUTE UNIT VECTOR DVP PARALEL TO CHORD(2) */

    q2[0] = pp[lpp - 1];
    q2[1] = pp[lpp];
    q2[2] = pp[lpp + 1];
    w2[0] = wp[lwp - 1] - q2[0];
    w2[1] = wp[lwp] - q2[1];
    w2[2] = wp[lwp + 1] - q2[2];
    avnorm_(w2, dvp, &a2cmmn_1.ier);

/*     STORE LENGTH OF DVP IN EP6 */

    avleng_(w2, &ep6);

/*     STORE VECTOR(2) LOCALLY */

    v2[0] = vp[lvp - 1];
    v2[1] = vp[lvp];
    v2[2] = vp[lvp + 1];

/*     IF FIRST ENTRY,CHOOSE FIRST SET OF PARAMETERS DELTA,LAMBDA */
/*     FROM TABLE AT 1000,OTHERWISE USE THE LAST  COMPUTED PARAMETERS */

L300:
    if (a2cmmn_1.cansto[lsd - 1] != 0.) {
	goto L400;
    } else {
	goto L1000;
    }

/*     TAKE DOT PRODUCT OF TOOL NORMAL AND SURFACE NORMAL */

L400:
    g = d__[0] * zn[lsd - 1] + d__[1] * zn[lsd] + d__[2] * zn[lsd + 1];

/*     IF COSINE OF ANGLE LESS THAN .01,CHOOSE NEW PARAMETERS */

    if (abs(g) - .01 <= 0.) {
	goto L1100;
    } else {
	goto L401;
    }

/*     SUM IS THE DISTANCE BETWEEN THE POINT OF INTERSECTION OF TOOL */
/*     NORMAL WITH THE PLANE AND THE SURFACE POINT */
/*     SIGMA IS THE COSINE OF THE ANGLE BETWEEN TOOL NORMAL AND */
/*     NORMALIZED(TOOL POINT-SURFACE POINT) */

L401:
    x[0] = p0[0] - r__[lsd - 1];
    x[1] = p0[1] - r__[lsd];
    x[2] = p0[2] - r__[lsd + 1];
    xll = (-x[0] * zn[lsd - 1] - x[1] * zn[lsd] - x[2] * zn[lsd + 1]) / g;
    avnorm_(x, a, &a2cmmn_1.ier);
    x[0] += xll * d__[0];
    x[1] += xll * d__[1];
    x[2] += xll * d__[2];
    sum = abs(x[0]) + abs(x[1]) + abs(x[2]);
    sigma = (d__1 = a[0] * d__[0] + a[1] * d__[1] + a[2] * d__[2], abs(d__1));

/*     DECLARE CONVERGENCE IF EITHER ANGLE OR DISTANCE IS LESS THAN */
/*     TEST QUANTITIES(510) OTHERWISE(600) */

    if (sigma - .99995 <= 0.) {
	goto L509;
    } else {
	goto L510;
    }
L509:
    if (sum - ep2 <= 0.) {
	goto L510;
    } else {
	goto L600;
    }

/*     TEST FOR SIGN OF DIRECTED DISTANCE */

L510:
    if (iops <= 0) {
	goto L512;
    } else {
	goto L511;
    }
L511:
    if (xll >= 0.) {
	goto L512;
    } else {
	goto L513;
    }

/*     COMPUTATIONS SUCCESSFUL STORE DATA FOR RETURN */

L512:
    a2cmmn_1.ier = 0;
    a2cmmn_1.s[a2cmmn_1.is - 1] = xll;
    a2cmmn_1.sn[a2cmmn_1.is - 1] = zn[lsd - 1];
    a2cmmn_1.sn[a2cmmn_1.is] = zn[lsd];
    a2cmmn_1.sn[a2cmmn_1.is + 1] = zn[lsd + 1];
    a2cmmn_1.slx[a2cmmn_1.is - 1] = sl[lsd - 1];
    a2cmmn_1.slx[a2cmmn_1.is] = sl[lsd];
    a2cmmn_1.slx[a2cmmn_1.is + 1] = sl[lsd + 1];
    goto L1600;

/*     UNABLE TO COMPUTE DIRECTED DISTANCE */

L513:
    a2cmmn_1.ier = 1;
    goto L1600;

/*     UPDATE COUNTER  PICK UP NEW PARMATERS (1100)IF COUNTER EXHAUSTED */

L600:
    --loop;
    if (loop <= 0) {
	goto L1100;
    } else {
	goto L700;
    }

/*     ALPH AND BETA ARE LINEAR CORRECTION TO DELTA AND LAMBDA */

L700:
/* Computing 2nd power */
    d__1 = r3[lsd - 1];
/* Computing 2nd power */
    d__2 = r3[lsd];
/* Computing 2nd power */
    d__3 = r3[lsd + 1];
    csl = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    csm = r3[lsd - 1] * r2[lsd - 1] + r3[lsd] * r2[lsd] + r3[lsd + 1] * r2[
	    lsd + 1];
/* Computing 2nd power */
    d__1 = r2[lsd - 1];
/* Computing 2nd power */
    d__2 = r2[lsd];
/* Computing 2nd power */
    d__3 = r2[lsd + 1];
    csn = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    sma = r3[lsd - 1] * x[0] + r3[lsd] * x[1] + r3[lsd + 1] * x[2];
    smb = r2[lsd - 1] * x[0] + r2[lsd] * x[1] + r2[lsd + 1] * x[2];
/* Computing 2nd power */
    d__1 = csm;
    delt = csl * csn - d__1 * d__1;
    if (1e-5 - delt >= 0.) {
	goto L1100;
    } else {
	goto L701;
    }
L701:
    alph = (sma * csn - smb * csm) / delt;
    beta = (smb * csl - sma * csm) / delt;
    delta[lsd - 1] += alph * (float).8;
    zlambd[lsd - 1] += beta * (float).8;
L800:

/*     PROCESS ONE CURVE IF FORMAT A(920),TWO CURVES OTHERWISE (910) */

/* L900: */
    astor_(&a2cmmn_1.cansto[icss + 2], &c__8, &ic1, &c__2);
    if (ic1 - 5 <= 0) {
	goto L920;
    } else {
	goto L910;
    }

/* FIND POINT CP AND DERIV WRT DELTA DCP ON 2ND COMPONENT SURFACE */

L910:
    for (i__ = 1; i__ <= 3; ++i__) {
	x[i__ - 1] = q2[i__ - 1] + delta[lsd - 1] * w2[i__ - 1];
/* L911: */
	b[i__ - 1] = dvp[i__ - 1];
    }
    a2cmmn_1.tn[a2cmmn_1.is - 1] = v2[0];
    a2cmmn_1.tn[a2cmmn_1.is] = v2[1];
    a2cmmn_1.tn[a2cmmn_1.is + 1] = v2[2];
    ep = ep6;
    a2cmmn_1.ic = ls2m3;
    avcros_(v2, dvp, sc);
    avnorm_(sc, fc, &a2cmmn_1.ier);
    avleng_(sc, &sign1);
    if (a2cmmn_1.ier != 0) {
	goto L1100;
    } else {
	goto L27;
    }
L27:
    goto L930;
L915:
    cp[0] = e[0];
    cp[1] = e[1];
    cp[2] = e[2];
    dcp[0] = dc[0];
    dcp[1] = dc[1];
    dcp[2] = dc[2];

/* FIND POINT E AND DERIV WRT DELTA DC ON 1ST COMPONENT SURFACE */

L920:
    for (i__ = 1; i__ <= 3; ++i__) {
	x[i__ - 1] = q1[i__ - 1] + delta[lsd - 1] * w1[i__ - 1];
/* L921: */
	b[i__ - 1] = dv[i__ - 1];
    }
    a2cmmn_1.tn[a2cmmn_1.is - 1] = v1[0];
    a2cmmn_1.tn[a2cmmn_1.is] = v1[1];
    a2cmmn_1.tn[a2cmmn_1.is + 1] = v1[2];
    a2cmmn_1.ic = ls1m3;
    ep = ep5;
    avcros_(v1, dv, sc);
    avnorm_(sc, fc, &a2cmmn_1.ier);
    avleng_(sc, &sign1);
    if (a2cmmn_1.ier != 0) {
	goto L1100;
    } else {
	goto L930;
    }

L930:
    a2cmmn_1.tp[a2cmmn_1.is - 1] = x[0];
    a2cmmn_1.tp[a2cmmn_1.is] = x[1];
    a2cmmn_1.tp[a2cmmn_1.is + 1] = x[2];
L8000:
    addstr_();
    if (a2cmmn_1.iop[a2cmmn_1.iis - 1] == 1) {
	goto L8001;
    }
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
    if (a2cmmn_1.ier <= 0) {
	goto L933;
    } else {
	goto L1100;
    }
L8001:
    if (a2cmmn_1.ier == 0) {
	goto L933;
    }
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
    goto L8000;
L933:
    e[0] = a2cmmn_1.tp[a2cmmn_1.is - 1] + a2cmmn_1.s[a2cmmn_1.is - 1] * 
	    a2cmmn_1.tn[a2cmmn_1.is - 1];
    e[1] = a2cmmn_1.tp[a2cmmn_1.is] + a2cmmn_1.s[a2cmmn_1.is - 1] * 
	    a2cmmn_1.tn[a2cmmn_1.is];
    e[2] = a2cmmn_1.tp[a2cmmn_1.is + 1] + a2cmmn_1.s[a2cmmn_1.is - 1] * 
	    a2cmmn_1.tn[a2cmmn_1.is + 1];
    a2cmmn_1.sp[a2cmmn_1.is - 1] = e[0];
    a2cmmn_1.sp[a2cmmn_1.is] = e[1];
    a2cmmn_1.sp[a2cmmn_1.is + 1] = e[2];
/*     ****************************************************************** */
/*     CODE THRU 10000 ADDED TO SET PROPER J24(IIS) SWICH FOR CALL */
/*     TO ANRMAL R.E. LYMAN 3/24/69 */
    astor_(&a2cmmn_1.cansto[a2cmmn_1.ic + 1], &c__8, &ic1, &c__2);
    ic1 += -3000;
    if (ic1 <= 0) {
	goto L9040;
    }
    if ((i__1 = ic1 - 15) < 0) {
	goto L9030;
    } else if (i__1 == 0) {
	goto L9100;
    } else {
	goto L9000;
    }
L9000:
    if ((i__1 = ic1 - 50) < 0) {
	goto L9040;
    } else if (i__1 == 0) {
	goto L9020;
    } else {
	goto L9010;
    }
L9010:
    if ((i__1 = ic1 - 53) < 0) {
	goto L9020;
    } else if (i__1 == 0) {
	goto L9100;
    } else {
	goto L9040;
    }
L9020:
    ic1 += -34;
L9030:
    switch ((int)ic1) {
	case 1:  goto L9040;
	case 2:  goto L9050;
	case 3:  goto L9050;
	case 4:  goto L9060;
	case 5:  goto L9060;
	case 6:  goto L9070;
	case 7:  goto L9070;
	case 8:  goto L9080;
	case 9:  goto L9070;
	case 10:  goto L9070;
	case 11:  goto L9040;
	case 12:  goto L9040;
	case 13:  goto L9090;
	case 14:  goto L9070;
	case 15:  goto L9100;
	case 16:  goto L9110;
	case 17:  goto L9040;
	case 18:  goto L9040;
	case 19:  goto L9100;
    }
L9040:
    aerr_(&c__1401);
L9050:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 1;
    goto L10000;
L9060:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 2;
    goto L10000;
L9070:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 3;
    goto L10000;
L9080:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 4;
    goto L10000;
L9090:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 5;
    goto L10000;
L9100:
    aerr_(&c__1402);
L9110:
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = 7;
L10000:
/*     ****************************************************************** */
/*     SET IPONTR(IIS) TO PICK UP CORRECT IC IN ANRMAL */
    ipntrs = a2cmmn_1.ipontr[a2cmmn_1.iis - 1];
    a2cmmn_1.ipontr[a2cmmn_1.iis - 1] = a2cmmn_1.ic - 1;
    anrmal_();
/*     RESTORE IPONTR(IIS) */
    a2cmmn_1.ipontr[a2cmmn_1.iis - 1] = ipntrs;
    avcros_(fc, &a2cmmn_1.sn[a2cmmn_1.is - 1], ut1);
    avnorm_(ut1, t1, &a2cmmn_1.ier);
    dot = t1[0] * b[0] + t1[1] * b[1] + t1[2] * b[2];
    if (dot <= 0.) {
	goto L17;
    } else {
	goto L18;
    }
L18:
    sig = (float)1.;
    goto L19;
L17:
    sig = (float)-1.;
L19:
    avcros_(t1, &a2cmmn_1.tn[a2cmmn_1.is - 1], s1);
    avnorm_(s1, ut1, &a2cmmn_1.ier);
    avleng_(s1, &sign2);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L951: */
	dc[i__ - 1] = t1[i__ - 1] * sig * sign1 * ep / sign2;
    }
    if (a2cmmn_1.ic - ls2m3 != 0) {
	goto L980;
    } else {
	goto L915;
    }



/*     R3 AND R2 ARE PARTIAL DERIVATIVES WRT DELTA AND LAMBDA RESPECTIVEL */

L980:
    r3[lsd - 1] = dc[0] + zlambd[lsd - 1] * (dcp[0] - dc[0]);
    r3[lsd] = dc[1] + zlambd[lsd - 1] * (dcp[1] - dc[1]);
    r3[lsd + 1] = dc[2] + zlambd[lsd - 1] * (dcp[2] - dc[2]);
    r2[lsd - 1] = cp[0] - e[0];
    r2[lsd] = cp[1] - e[1];
    r2[lsd + 1] = cp[2] - e[2];
    avnorm_(&r3[lsd - 1], &zn[lsd - 1], &a2cmmn_1.ier);
    if (a2cmmn_1.ier <= 0) {
	goto L981;
    } else {
	goto L1100;
    }
L981:
    avnorm_(&r2[lsd - 1], &sl[lsd - 1], &a2cmmn_1.ier);
    if (a2cmmn_1.ier <= 0) {
	goto L982;
    } else {
	goto L1100;
    }
L982:
    avcros_(&zn[lsd - 1], &sl[lsd - 1], sc);

/*     ZN(LSD) CONTAINS THE SURFACE NORMAL */

    avnorm_(sc, &zn[lsd - 1], &a2cmmn_1.ier);
    if (a2cmmn_1.ier <= 0) {
	goto L983;
    } else {
	goto L1100;
    }

/*     R(LSD) CONTAINS THE SURFACE POINT */

L983:
    r__[lsd - 1] = e[0] + zlambd[lsd - 1] * r2[lsd - 1];
    r__[lsd] = e[1] + zlambd[lsd - 1] * r2[lsd];
    r__[lsd + 1] = e[2] + zlambd[lsd - 1] * r2[lsd + 1];
    goto L400;

/*     SET IFST=1 TO INDICATE SUBSEQUENT ENTRIES */

L1000:
    a2cmmn_1.cansto[lsd - 1] = a2fpc_1.q1p;
L1100:
    loop = 25;

/*     THE CHOICE OF PARAMETERS ISMADE BASED ON THE VALUE OF IGUESS */

    ++iguess;
/* L1200: */
    zlambd[lsd - 1] = .5;
    if (iguess - 7 <= 0) {
	goto L1210;
    } else {
	goto L1209;
    }
L1209:
    a2cmmn_1.ier = 1;
    goto L1600;
L1210:
    switch ((int)iguess) {
	case 1:  goto L1216;
	case 2:  goto L1217;
	case 3:  goto L1213;
	case 4:  goto L1212;
	case 5:  goto L1211;
	case 6:  goto L1214;
	case 7:  goto L1215;
    }
L1211:
    delta[lsd - 1] = .5;
    goto L800;
L1212:
    delta[lsd - 1] = .999;
    goto L800;
L1213:
    delta[lsd - 1] = .001;
    goto L800;
L1214:
    delta[lsd - 1] = .75;
    goto L800;
L1215:
    delta[lsd - 1] = .25;
    goto L800;
L1216:
    delta[lsd - 1] = -.2;
    goto L800;
L1217:
    delta[lsd - 1] = 1.2;
    goto L800;
L1600:
    a2cmmn_1.tp[a2cmmn_1.is - 1] = p0[0];
    a2cmmn_1.tp[a2cmmn_1.is] = p0[1];
    a2cmmn_1.tp[a2cmmn_1.is + 1] = p0[2];
    a2cmmn_1.tn[a2cmmn_1.is - 1] = d__[0];
    a2cmmn_1.tn[a2cmmn_1.is] = d__[1];
    a2cmmn_1.tn[a2cmmn_1.is + 1] = d__[2];
    avsto_(savesp, &a2cmmn_1.sp[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = iops;
    a2cmmn_1.ic = icss;
    a2cmmn_1.j24[a2cmmn_1.iis - 1] = j24ss;
/* L1700: */
    return 0;
} /* arlds_ */

#undef zlambd
#undef delta
#undef sl
#undef zn
#undef vp
#undef wp
#undef pp
#undef r3
#undef r2
#undef w
#undef r__
#undef p
#undef f


