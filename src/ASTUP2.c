/* ASTUP2.f -- translated by f2c (version 20000121).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c_b3 = 111111;
static integer c__9 = 9;
static integer c_b7 = 110000;
static integer c__8 = 8;
static integer c__2 = 2;
static integer c__40 = 40;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__6 = 6;
static integer c__0 = 0;
static integer c__45 = 45;
static integer c__42 = 42;
static integer c__43 = 43;

/* Subroutine */ int astup2_()
{
    /* Initialized data */

    static struct {
	char e_1[88];
	real e_2;
	} equiv_12 = { {'A', 'S', 'T', 'U', 'P', '2', 'T', 'P', 'A', 'S', 'T',
		 'U', 'P', '2', '0', '1', 'A', 'S', 'T', 'U', 'P', '2', '0', 
		'2', 'A', 'S', 'T', 'U', 'P', '2', '0', '3', 'A', 'S', 'T', 
		'U', 'P', '2', '0', '4', 'A', 'S', 'T', 'U', 'P', '2', '0', 
		'5', 'A', 'S', 'T', 'U', 'P', '2', '0', '6', 'A', 'S', 'T', 
		'U', 'P', '2', '0', '7', 'A', 'S', 'T', 'U', 'P', '2', '0', 
		'8', 'A', 'S', 'T', 'U', 'P', '2', '0', '9', 'A', 'S', 'T', 
		'U', 'P', '2', 'E', 'X'}, (float)0. };

#define ab ((real *)&equiv_12)


    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__, ki;
    static doublereal apnt[3], ans;
    extern /* Subroutine */ int avadd_(), aerr_(), arlm2_(), amind_(), atape_(
	    );
    static doublereal dctem[8], pctem[8], tetem[3];
    extern /* Subroutine */ int avsto_(), astor_(), avdot_(), avsub_(), 
	    addst_();
    static integer ktopt, jsave;
    extern /* Subroutine */ int astos_(), avleng_(), adyndp_(), avnorm_(), 
	    avmult_();
    static integer iwitol;
    extern /* Subroutine */ int avcros_(), astrup_();

/* ... A2CMMN START */
/* ... A2CMMN END */
/* ...             SET UP PSUDO DS AS PLANE,EITHER ALONG VINDIR OR MINDIST */
    adyndp_(ab, &c__1, &c_b3);
    if (a2cmmn_1.indir__[a2cmmn_1.iids - 1] != 1) {
	goto L20;
    }
/* L10: */
    adyndp_(&ab[2], &c__9, &c_b7);
    avsto_(&a2cmmn_1.vndir[a2cmmn_1.ids - 1], a2cmmn_1.ti);
    if (abs(a2cmmn_1.ti[2]) > a2fpc_1.qp995) {
	goto L270;
    }
    ki = a2cmmn_1.ipontr[a2cmmn_1.iids - 1];
    ans = a2fpc_1.q1p;
    goto L100;
L20:
    adyndp_(&ab[4], &c__9, &c_b7);
/*     NO INDIR */
    a2cmmn_1.k = a2cmmn_1.ipontr[a2cmmn_1.iids - 1];
    ki = a2cmmn_1.k;
    astor_(&a2cmmn_1.cansto[a2cmmn_1.k - 1], &c__8, &i__, &c__2);
    if (i__ != 2 && i__ != 3) {
	goto L40;
    }
/* ...             PLANE */
/* L30: */
    adyndp_(&ab[6], &c__9, &c_b7);
    avsto_(&a2cmmn_1.cansto[a2cmmn_1.k + 3], a2cmmn_1.ti);
    avdot_(a2cmmn_1.te, a2cmmn_1.ti, &ans);
    ans = a2cmmn_1.cansto[a2cmmn_1.k + 6] - ans;
    if (ans < a2fpc_1.qnul) {
	avsub_(a2cmmn_1.vnul, a2cmmn_1.ti, a2cmmn_1.ti);
    }
    ans = abs(ans);
/* ...             TI NOW SET TO POINT TOWARD PLANE */
    goto L90;
/* ...             CIRCLE */
L40:
    adyndp_(&ab[8], &c__9, &c_b7);
    avsub_(a2cmmn_1.te, &a2cmmn_1.cansto[a2cmmn_1.k + 3], a2cmmn_1.vtem);
    a2cmmn_1.vtem[2] = a2fpc_1.qnul;
    avnorm_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.ier);
    avmult_(a2cmmn_1.vtem, &a2cmmn_1.cansto[a2cmmn_1.k + 9], apnt);
    avadd_(apnt, &a2cmmn_1.cansto[a2cmmn_1.k + 3], apnt);
/* ...             APNT IS MINIMUM DISTANCE POINT ON SURFACE - USE IT TO */
/*                SET UP THE AIMING DIRECTION TI */
    avsub_(apnt, a2cmmn_1.te, a2cmmn_1.ti);
    a2cmmn_1.ti[2] = a2fpc_1.qnul;
    avleng_(a2cmmn_1.ti, &ans, &a2cmmn_1.ier);
    avnorm_(a2cmmn_1.ti, a2cmmn_1.ti, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__40);
    }
L90:
    if (ans > a2cmmn_1.cutdat[0]) {
	goto L100;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iids - 1] != 1) {
	goto L100;
    }
    a2cmmn_1.isftyp[a2cmmn_1.iids - 1] = 2;
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ti, a2cmmn_1.ti);


/* ...             USE DCTEM TO STORE PSUDO DS CANONICAL FORM */
L100:
    if (a2cmmn_1.itlon[a2cmmn_1.iids - 1] != 0) {
	ans = abs(ans) - a2cmmn_1.cutdat[0];
    }
    iwitol = 0;
    if (abs(ans) <= a2cmmn_1.tau[a2cmmn_1.ids - 1]) {
	iwitol = 1;
    }
    adyndp_(&ab[10], &c__9, &c_b7);
    astor_(&c__3, &c__4, dctem, &c__8);
    astor_(&c__6, &c__4, &dctem[1], &c__8);
/* ...   **TROUBLE FOR S/360 **** */
    astor_("DSGO        ", &c__8, &dctem[2], &c__8, (ftnlen)12);
    astor_(&c__0, &c__4, &dctem[3], &c__8);
    avcros_(a2cmmn_1.ti, a2cmmn_1.ta, &dctem[4]);
    avnorm_(&dctem[4], &dctem[4], &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__45);
    }
    dctem[7] = a2fpc_1.qnul;

/* ...             IF NOPS NOT GIVEN, GET PROPERLY POSITIONED TO PS...IF */
/*                NOPS WAS GIVEN, SET UP PSUDO PS PLANE */
    if (a2cmmn_1.inops != 1) {
	goto L120;
    }
/*                NOPS WAS GIVEN */
/* L110: */
    adyndp_(&ab[12], &c__9, &c_b7);
    avcros_(a2cmmn_1.ti, a2cmmn_1.ta, a2cmmn_1.vtem);
    avcros_(a2cmmn_1.ti, a2cmmn_1.vtem, &pctem[4]);
    avnorm_(&pctem[4], &pctem[4], &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__42);
    }
/* ...             SET UP PS CANONICAL FORM */
    astor_(&c__3, &c__4, pctem, &c__8);
    astor_(&c__6, &c__4, &pctem[1], &c__8);
    astor_("PSGO        ", &c__8, &pctem[2], &c__8, (ftnlen)12);
    astor_(&c__0, &c__4, &pctem[3], &c__8);
    pctem[7] = a2fpc_1.qnul;
    avsto_(a2cmmn_1.te, tetem);
    goto L200;


L120:
/*                NOPS NOT GIVEN-POSITION CUTTER TO PS PLANE BY */
/*                VERTICAL MOTION ONLY */


    if (a2cmmn_1.itlon[a2cmmn_1.iips - 1] == 0) {
	goto L140;
    }

/* L130: */
/*                CUTTER IS NOT TO BE ON PS-COMPUTE MINIMUM DISTANCE SO */
/*                TOOL POINT CAN BE USED */
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.ips - 1]);
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ez, &a2cmmn_1.tn[a2cmmn_1.ips - 1]);
/*                INITIAL VALUES OF TP AND TN SET-NOW INITIALIZE AMIND */
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    a2cmmn_1.jent[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.jtn[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.iopset[a2cmmn_1.iis - 1] = 0;
/*                NOTE JTN SET FOR TOOL NORMAL CONTROL IN AMIND */
    a2cmmn_1.jiops[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.ju1[a2cmmn_1.iis - 1] = 0;
    amind_();
/*                AMIND HAS NOW ITERATED AROUND AND FOUND A MINIMUM DIST. */
/*                IT PRESUMABLY HAS MODIFIED TP AND IN SUCH THAT TN LINES */
/*                UP PARALLEL OR ANTI-PARALLEL TO THE PLANE PS NORMAL. */
/*                IT SHOULD STILL BE IN A GENERALLY DOWNWARD DIRECTION, */
/*                AS TN WAS INITIALLY IN THE -Z DIRECTION. IF THE CUTTER */
/*                HAS TO BE MOVED DOWN,S THE MINIMUM DISTANCE SHOULD BE */
/*                POSITIVE. IF UPWARD MOTION IS REQUIRED, S SHOULD BE NEG */

/*                TP SHOULD NOW BE THE POINT ON THE CUTTER WHICH IS */
/*                CLOSEST TO THE PLANE, IF THE PLANE IS BELOW THE */
/*                CUTTER OR FURTHERS FROM THE PLANE IF THE PLANE IS ABOVE */
/*                THE CUTTER. IN EITHER CASE IT TIS THE DESIRED POINT OF */
/*                CONTACT BETWEEN CUTTER AND PS PLANE */

    goto L150;
L140:
    adyndp_(&ab[14], &c__9, &c_b7);
/*                CUTTER IS TO BE ON PS USE DIRECTED DISTANCE ROUTINE TO */
/*                SEE HOW MUCH TO MOVE IT. DDST LOOKS FROM TP IN DIRECT- */
/*                ION TN. S IS RETURNED AS THE DIRECTED DISTANCE, POS. IF */
/*                FORWARD ALONG TN, NEG IF BACK ALONG TN.. */

/*                SET UP TP FOR ON CASE...FOR OFFSET CASE TP HAS BEEN */
/*                COMPUTED IN AMIND */
    avsto_(a2cmmn_1.te, &a2cmmn_1.tp[a2cmmn_1.ips - 1]);
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;

L150:
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 0;
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ez, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    addst_();
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__43);
    }
    if (a2cmmn_1.past[a2cmmn_1.ips - 1] < a2fpc_1.qnul) {
	goto L270;
    }
    if (a2cmmn_1.itlon[a2cmmn_1.iips - 1] != 0 && a2cmmn_1.s[a2cmmn_1.ips - 1]
	     < a2fpc_1.qnul && (d__1 = a2cmmn_1.s[a2cmmn_1.ips - 1], abs(d__1)
	    ) > a2fpc_1.qp5 * a2cmmn_1.cutdat[6]) {
	goto L270;
    }

/*                SET UP CUTTER LOCATION FOR ARLM2 INPUT. DO NOT WANT TO */
/*                USE TE AS IT MIGHT MESS UP PMOVE COMPUTATUION */
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.s[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, tetem);


/*                STORE PS CANONICAL FORM IN PCTEM SO BOOKS WILL BE KEPT */
/*                STRAIGHT. */
/*                THE PROBLEM IS THAT THE 2D ROUTE REFERENCES THE PS CAN- */
/*                ONICAL FORM DIRECTLY- */
/*                THEREFORE WE HAVE TO FOOL IT IN NOPS CASES BY LOADING */
/*                A PSUDOPS AND RESTORING THE REAL ONE LATER */

    for (i__ = 1; i__ <= 8; ++i__) {
	pctem[i__ - 1] = a2cmmn_1.cansto[i__ - 1];
/* L155: */
    }

    goto L200;

L200:
    adyndp_(&ab[16], &c__9, &c_b7);
/*                SET UP TO,ON,PAST,TANTO FOR ARLM2 */
/*                KTOPT =  1,2,3,4 FOR TO,ON,PAST,TANTO */
/*                HOWEVER IN 3D ROUTE, ISFTYP = 1,2,3,4 FOR TO,PAST,ON, */
/*                TANTO.. */

    ktopt = a2cmmn_1.isftyp[a2cmmn_1.iids - 1];
    if (a2cmmn_1.isftyp[a2cmmn_1.iids - 1] == 2) {
	ktopt = 3;
    }
    if (a2cmmn_1.isftyp[a2cmmn_1.iids - 1] == 3) {
	ktopt = 2;
    }

    if (iwitol == 1) {
	goto L260;
    }
/*                LOAD PS CANONICAL FORM */
    jsave = a2cmmn_1.j24[a2cmmn_1.iips - 1];
    a2cmmn_1.j24[a2cmmn_1.iips - 1] = 1;
    for (i__ = 1; i__ <= 8; ++i__) {
	a2cmmn_1.temp[i__ - 1] = a2cmmn_1.cansto[i__ - 1];
	a2cmmn_1.cansto[i__ - 1] = pctem[i__ - 1];
	pctem[i__ - 1] = a2cmmn_1.temp[i__ - 1];
/* L205: */
    }
/*                CALL ARLM2 */
    adyndp_(&ab[18], &c__9, &c_b7);
    arlm2_(a2cmmn_1.cutdat, a2cmmn_1.vnul, &a2fpc_1.qnul, tetem, a2cmmn_1.ti, 
	    dctem, &a2cmmn_1.cansto[ki - 1], &ktopt, &c__1, &a2cmmn_1.eps1[
	    a2cmmn_1.ids - 1], &a2cmmn_1.tau[a2cmmn_1.ids - 1], &a2fpc_1.qnul,
	     &a2dydp_1.kdynfq[8]);

/*                RESTORE PS CANONICAL FORM */
    for (i__ = 1; i__ <= 8; ++i__) {
	a2cmmn_1.cansto[i__ - 1] = pctem[i__ - 1];
/* L250: */
    }
    a2cmmn_1.j24[a2cmmn_1.iips - 1] = jsave;
    adyndp_(&ab[20], &c__1, &c_b3);
    return 0;
L260:
    if (a2cmmn_1.indir__[a2cmmn_1.iids - 1] == 1 || a2cmmn_1.itlon[
	    a2cmmn_1.iids - 1] != 0) {
	goto L270;
    }
    avsto_(tetem, a2cmmn_1.te);
    a2cmmn_1.nw = 0;
    astos_();
    atape_();
    return 0;
L270:
    astrup_();
    return 0;
} /* astup2_ */

#undef ab


