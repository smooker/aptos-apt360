/* ARPDIS.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
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
    integer kttry2;
} atanco_;

#define atanco_1 atanco_

struct {
    doublereal svtau1, svtau2, svtau, sveps1, sveps8, sveps2, sveps3, sveps4, 
	    sveps6;
    integer mtau;
} taumd1_;

#define taumd1_1 taumd1_

struct {
    integer j51ckp, j51ckd;
    doublereal rvrsu1[6];
} cntru1_;

#define cntru1_1 cntru1_

/* Table of constant values */

static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__2 = 2;
static integer c__802 = 802;

/* Subroutine */ int arpdis_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_17 = { {'A', 'R', 'P', 'D', 'I', 'S', 'T', 'P'}, (float)0. };

#define ab ((real *)&equiv_17)


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__, kk1, kk2;
    static doublereal ans;
    static integer kcyl;
    extern /* Subroutine */ int arlm3_();
    static integer icall, kfail, indic, kndic, kaeta;
    extern /* Subroutine */ int arlm2_(), aerr_();
    static integer itopt;
    extern /* Subroutine */ int avdot_(), avsto_(), addst_(), avsub_(), 
	    astup2_(), arepre_(), bdyndp_(), cdyndp_();
    static doublereal percen;
    static integer kcylcs;
    extern /* Subroutine */ int astrup_(), aofset_(), avnorm_();
    static integer kcspon, ktanpt;
    extern /* Subroutine */ int avcros_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ...  TO ACT AS A DISPATCHER AT AREPRE TIME,  CALL THE REQUIRED */
/* ...  COMPUTATION ROUTINES AND UPDATE PMOVE UPON RETURN. */
/* ... */
/* ... A2CMMN END */
    cntru1_1.j51ckp = 0;
    cntru1_1.j51ckd = 0;
/* ..... TO SET ADYNDP COUNTER TO ZERO ..... */
    bdyndp_(ab, &c__1, &c_n1);
/* ...... IFRL = 1 .... INFORMS AMIND THAT IT IS CALLED FROM AREPRE */
/* ...... IFRL = 0 .... OTHERWISE */
/* ............... */
    cdyndp_(&c__2, &c__1);
/* ....................................................................... */
    arepre_(&icall, &kk1, &kk2, &itopt, &percen);
    a2cmmn_.ifrl = 0;
/* .................................. */
    taumd1_1.mtau = 0;
    atanco_1.kttry2 = 0;
    kfail = 0;
    switch ((int)icall) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
    }
L1:
    if (atanco_1.kttry2 == 0) {
	goto L333;
    }
    if (a2cmmn_.ipl[a2cmmn_.iips - 1] == 1 && a2cmmn_.ipl[a2cmmn_.iids - 
	    1] == 1) {
	goto L333;
    }
    if ((d__1 = a2cmmn_.th[a2cmmn_.ips - 1], abs(d__1)) + (d__2 = 
	    a2cmmn_.th[a2cmmn_.ids - 1], abs(d__2)) + (d__3 = a2cmmn_.th[
	    a2cmmn_.ics - 1], abs(d__3)) != a2fpc_1.qnul) {
	goto L333;
    }
    if (a2cmmn_.icscnt > 1 || a2cmmn_.isftyp[a2cmmn_.iics - 1] != 4) {
	goto L333;
    }
    if (a2cmmn_.multax > 1) {
	goto L333;
    }
/* ... */
    indic = 41;
    kndic = 101;
    if (a2cmmn_.ifl4[a2cmmn_.iics - 1] == 1) {
	indic = 1;
    }
    if (indic == 1) {
	kndic = 1;
    }
    kaeta = 0;
    if (a2cmmn_.multax == 1 || a2cmmn_.itlon[indic - 1] == 0) {
	goto L888;
    }
/* ... */
L222:
    if (a2cmmn_.j24[indic - 1] == 2 && a2cmmn_.ipl[a2cmmn_.iics - 1] == 1) 
	    {
	goto L555;
    }
    if (a2cmmn_.ipl[indic - 1] == 1 && a2cmmn_.j24[a2cmmn_.iics - 1] == 2) 
	    {
	goto L444;
    }
    goto L333;
L444:
    kcylcs = a2cmmn_.ipontr[a2cmmn_.iics - 1];
    avdot_(&a2cmmn_.cansto[kcylcs + 6], a2cmmn_.ta, &ans);
    if (abs(ans) > a2fpc_1.qp6x9) {
	goto L891;
    }
/* ... */
/* ... */
    a2cmmn_.is = a2cmmn_.ics;
    a2cmmn_.iis = a2cmmn_.iics;
    avsto_(a2cmmn_.te, &a2cmmn_.tp[a2cmmn_.is - 1]);
    avsto_(a2cmmn_.ti, &a2cmmn_.tn[a2cmmn_.is - 1]);
/* ... */
    addst_();
    a2cmmn_.itlon[a2cmmn_.iics - 1] = 1;
    if (a2cmmn_.ier != 0) {
	goto L776;
    }
    if (a2cmmn_.cutdat[0] > a2cmmn_.cansto[kcylcs + 9]) {
	goto L333;
    }
    if (a2cmmn_.cutdat[6] > a2cmmn_.cansto[kcylcs + 9]) {
	goto L333;
    }
    goto L777;
/* ... */
L555:
    kcyl = a2cmmn_.ipontr[indic - 1];
    avdot_(&a2cmmn_.cansto[kcyl + 6], a2cmmn_.ta, &ans);
    if (abs(ans) > a2fpc_1.qp6x9) {
	goto L890;
    }
    if (a2cmmn_.rc[kndic - 1] >= a2fpc_1.qnul) {
	goto L777;
    }
/* ... */
L776:
    a2cmmn_.isftyp[a2cmmn_.iics - 1] = 1;
    a2cmmn_.past[a2cmmn_.ics - 1] = a2fpc_1.q1p;
    goto L778;
/* ... */
L777:
    a2cmmn_.isftyp[a2cmmn_.iics - 1] = 2;
    a2cmmn_.past[a2cmmn_.ics - 1] = -a2fpc_1.q1p;
    goto L778;
L333:
    arlm3_();
    a2cmmn_.ifrl = 1;
    goto L100;
/* .................................. */
/* ... */
L2:
    ans = a2cmmn_.cutdat[0];
    if (itopt == 4 && a2cmmn_.itlon[a2cmmn_.iids - 1] == 0) {
	ans = a2fpc_1.qnul;
    }
    arlm2_(&ans, &a2cmmn_.tn[a2cmmn_.ids - 1], &a2fpc_1.qnul, a2cmmn_.te, 
	    a2cmmn_.ti, &a2cmmn_.cansto[kk1 - 1], &a2cmmn_.cansto[kk2 - 1],
	     &itopt, &a2cmmn_.ifar[a2cmmn_.iics - 1], &a2cmmn_.tau[
	    a2cmmn_.ids - 1], &a2cmmn_.tau[a2cmmn_.ics - 1], &percen, &
	    a2dydp_1.kdynfq[7]);
    a2cmmn_.ifrl = 1;
    goto L100;
/* .................................. */
/* ... */
L3:
    astrup_();
    a2cmmn_.ifrl = 2;
    goto L100;
/* .................................. */
/* ... */
L4:
    astup2_();
    a2cmmn_.ifrl = 2;
    goto L100;
/* .................................. */
/* ... */
L5:
    aofset_();
    a2cmmn_.ifrl = 2;
/* ... */
/* .................................. */
/* ... */

/* ....................................................................... */
/* ...  UPON RETURN FROM ALL ROUTINES, AUTOPS AND NOPS FLAGS ARE SET TO */
/* ...  ZERO. ALSO RESET IFAR(IICS)=1  ..... IFAR IS THE PART PROGRAMMER */
/* ...  SPECIFIED INTERSECTION BETWEEN DS AND CS. */
/* ... */
/* ...  ALL RETURNS UPDATE PMOVE, WHICH REPRESENTS A UNIT VECTOR ALONG */
/* ...  THE LAST CUT VECTOR OF THE CUT SEQUENCE OR STARTUP MOTION. */
/* ...  IT WILL BE USED TO ESTABLISH THE FORWARD DIRECTION FOR THE NEXT */
/* ...  CUT SEQUENCE IF THE USUAL TECHNIQUE SHOULD FAIL. */
/* ...  *** PMOVE IS NOT TO BE UPDATED IF THE MOTION IS WITHIN TWO DEGREES */
/* ...      OF THE TOOL AXIS *** */
/* ... */
L100:
    if (taumd1_1.mtau == 0) {
	goto L999;
    }
    taumd1_1.mtau = 0;
    a2cmmn_.tau1[a2cmmn_.ics - 1] = taumd1_1.svtau1;
    a2cmmn_.tau2[a2cmmn_.ics - 1] = taumd1_1.svtau2;
    a2cmmn_.tau[a2cmmn_.ics - 1] = taumd1_1.svtau;
    a2cmmn_.eps1[a2cmmn_.ics - 1] = taumd1_1.sveps1;
    a2cmmn_.eps8[a2cmmn_.ics - 1] = taumd1_1.sveps8;
    a2cmmn_.eps2[a2cmmn_.ics - 1] = taumd1_1.sveps2;
    a2cmmn_.eps3[a2cmmn_.ics - 1] = taumd1_1.sveps3;
    a2cmmn_.eps4[a2cmmn_.ics - 1] = taumd1_1.sveps4;
    a2cmmn_.eps6[a2cmmn_.ics - 1] = taumd1_1.sveps6;
L999:
    ++kfail;
    if (kfail == 1 && atanco_1.kttry2 == 1) {
	goto L1;
    }
    if (kfail <= 1) {
	goto L4472;
    }
    if (a2cmmn_.jcr == 1) {
	goto L4472;
    }
    if (a2cmmn_.jcr == 0 && a2cmmn_.j20[a2cmmn_.iis - 1] == 2) {
	goto L4472;
    }
    aerr_(&c__802);
L4472:
    avsub_(a2cmmn_.te, a2cmmn_.tek, a2cmmn_.vtem);
/* ...  RESET INTERSECTION COUNTER FLAG TO 1 */
    a2cmmn_.l = a2cmmn_.icscnt + 2;
    i__1 = a2cmmn_.l;
    for (i__ = 3; i__ <= i__1; ++i__) {
	a2cmmn_.k = a2cmmn_.lisv * (i__ - 1) + 1;
	a2cmmn_.ifar[a2cmmn_.k - 1] = 1;
/* L402: */
    }
/* ... */
/* ...  UPDATE PMOVE  ......................... */
/* L405: */
    avnorm_(a2cmmn_.vtem, a2cmmn_.vtem, &a2cmmn_.ier);
    if (a2cmmn_.ier != 0) {
	goto L500;
    }
    avdot_(a2cmmn_.vtem, a2cmmn_.ta, &ans);
    if (abs(ans) > a2fpc_1.qp997) {
	goto L500;
    }
    avsto_(a2cmmn_.vtem, a2cmmn_.pmove);
L500:
/* ... */
    a2cmmn_.inops = 0;
    a2cmmn_.iautps = 0;
/* ... */
    taumd1_1.mtau = 0;
    return 0;
/* ... */
L888:
    if (a2cmmn_.itlon[indic - 1] == 0) {
	goto L666;
    }
    if (a2cmmn_.icc == 1 && indic == 1) {
	goto L666;
    }
    if (a2cmmn_.icc == 2 && indic == 41) {
	goto L666;
    }
    goto L222;
L666:

    if (a2cmmn_.ipl[a2cmmn_.iics - 1] != 1) {
	goto L889;
    }
    if (a2cmmn_.j24[indic - 1] != 2) {
	goto L333;
    }
    goto L890;
/* ... */
L889:
    if (a2cmmn_.j24[a2cmmn_.iics - 1] == 2 && a2cmmn_.ipl[indic - 1] == 1) 
	    {
	goto L891;
    }
    goto L333;
/* ... */
L890:
    kcspon = a2cmmn_.ipontr[a2cmmn_.iics - 1];
    ktanpt = a2cmmn_.ipontr[indic - 1];
/* ... */
    if (kaeta != 2) {
	goto L892;
    }
/* ... */
    kcspon = a2cmmn_.ipontr[indic - 1];
    ktanpt = a2cmmn_.ipontr[a2cmmn_.iics - 1];
/* ... */
L892:
    avcros_(&a2cmmn_.cansto[ktanpt + 6], &a2cmmn_.cansto[kcspon + 3], 
	    a2cmmn_.vtem);
    avnorm_(a2cmmn_.vtem, a2cmmn_.vtem, &a2cmmn_.ier);
    if (a2cmmn_.ier != 0) {
	goto L333;
    }
    avdot_(&a2cmmn_.cansto[ktanpt + 3], a2cmmn_.vtem, &ans);
/* ... */
    if (kaeta == 2) {
	kcspon = ktanpt;
    }
    a2cmmn_.itlon[a2cmmn_.iics - 1] = 0;
    a2cmmn_.isftyp[a2cmmn_.iics - 1] = 3;
/* ... */
    a2cmmn_.cansto[kcspon + 3] = a2cmmn_.vtem[0];
    a2cmmn_.cansto[kcspon + 4] = a2cmmn_.vtem[1];
    a2cmmn_.cansto[kcspon + 5] = a2cmmn_.vtem[2];
    a2cmmn_.cansto[kcspon + 6] = ans;
/* ... */
    goto L333;
/* ... */
L891:
    kaeta = 2;
/* ... */
    a2cmmn_.j24[a2cmmn_.iics - 1] = 1;
    a2cmmn_.ipl[a2cmmn_.iics - 1] = 1;
/* ... */
    goto L890;
/* ... */
L778:
    taumd1_1.svtau1 = a2cmmn_.tau1[a2cmmn_.ics - 1];
    taumd1_1.svtau2 = a2cmmn_.tau2[a2cmmn_.ics - 1];
    taumd1_1.svtau = a2cmmn_.tau[a2cmmn_.ics - 1];
    taumd1_1.sveps1 = a2cmmn_.eps1[a2cmmn_.ics - 1];
    taumd1_1.sveps8 = a2cmmn_.eps8[a2cmmn_.ics - 1];
    taumd1_1.sveps2 = a2cmmn_.eps2[a2cmmn_.ics - 1];
    taumd1_1.sveps3 = a2cmmn_.eps3[a2cmmn_.ics - 1];
    taumd1_1.sveps4 = a2cmmn_.eps4[a2cmmn_.ics - 1];
    taumd1_1.sveps6 = a2cmmn_.eps6[a2cmmn_.ics - 1];
/* ... */
    a2cmmn_.tau1[a2cmmn_.ics - 1] *= a2fpc_1.qp5;
    a2cmmn_.tau2[a2cmmn_.ics - 1] *= a2fpc_1.qp5;
    a2cmmn_.tau[a2cmmn_.ics - 1] = a2cmmn_.tau1[a2cmmn_.ics - 1] - 
	    a2cmmn_.tau2[a2cmmn_.ics - 1];
    a2cmmn_.eps1[a2cmmn_.ics - 1] = a2fpc_1.qp1 * a2cmmn_.tau[a2cmmn_.ics 
	    - 1];
    a2cmmn_.eps8[a2cmmn_.ics - 1] = a2cmmn_.eps1[a2cmmn_.ics - 1];
    a2cmmn_.eps2[a2cmmn_.ics - 1] = a2fpc_1.q1p - a2cmmn_.eps1[
	    a2cmmn_.ics - 1];
    a2cmmn_.eps3[a2cmmn_.ics - 1] = a2fpc_1.qp9 * a2cmmn_.eps1[
	    a2cmmn_.ics - 1];
    a2cmmn_.eps4[a2cmmn_.ics - 1] = a2fpc_1.q2p * a2cmmn_.tau[a2cmmn_.ics 
	    - 1];
    a2cmmn_.eps6[a2cmmn_.ics - 1] = a2fpc_1.qp02 * a2cmmn_.eps1[
	    a2cmmn_.ics - 1];
    taumd1_1.mtau = 1;
    goto L333;
} /* arpdis_ */

#undef ab


