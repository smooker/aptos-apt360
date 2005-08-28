/* AREPRE.f -- translated by f2c (version 20000121).
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
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[5];
} asistm_;

#define asistm_1 asistm_

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
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

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

/* Table of constant values */

static integer c__1 = 1;
static integer c_b8 = 111111;
static integer c__0 = 0;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__3 = 3;
static integer c_n3520 = -3520;
static integer c__502 = 502;
static integer c__503 = 503;
static integer c_n3521 = -3521;
static integer c_n1601 = -1601;

/* Subroutine */ int arepre_(icall, kk1, kk2, itopt, percen)
integer *icall, *kk1, *kk2, *itopt;
doublereal *percen;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_17 = { {'A', 'R', 'E', 'P', 'R', 'E', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_17)

    static doublereal prevds = 9.99;
    static doublereal prevsb = 9.99;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, ii, its;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int aerr_();
    static integer ibr;
    static doublereal ans;
    extern /* Subroutine */ int amind_();
    static integer kyo;
    extern /* Subroutine */ int avsto_(), astor_(), avsub_(), avdot_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    static doublereal dstnsv[6];
    static integer kpmvtn, lastds;
    extern /* Subroutine */ int adyndp_(), asetup_(), avmult_(), atltst_();
    static integer itlret;
    extern /* Subroutine */ int afwdsl_(), atisel_(), avcros_(), aroute_(), 
	    astsel_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ... A2CMMN START */
/* ... A2CMMN END */
/* ... */
    kpmvtn = 0;
    avsto_(&a2cmmn_.tn[a2cmmn_.ids - 1], dstnsv);
    avsto_(&a2cmmn_.tp[a2cmmn_.ids - 1], &dstnsv[3]);
/*                   LASTDS = 0  PREVIOUS AND CURRENT DS'S DIFFERENT */
/*                          = 1  PREVIOUS AND CURRENT DS'S IDENTICAL */
    lastds = 0;
    if (prevds == a2cmmn_.abcd[0] && prevsb == a2cmmn_.abcd[1]) {
	goto L10274;
    }

/*                             ABCD(1)=DS NAME, ABCD(2)=SUBSCRIPT */
    prevds = a2cmmn_.abcd[0];
    prevsb = a2cmmn_.abcd[1];
    goto L10275;
/*                   INDICATE PREVIOUS AND CURRENT DS'S ARE IDENTICAL. */
L10274:
    lastds = 1;
L10275:

/* ... */
    if (a2cmmn_.cend[0] == a2fpc_1.qnul) {
	goto L6000;
    }
    its = a2cmmn_.ids;
    if (a2cmmn_.cend[0] < a2fpc_1.qnul) {
	its = a2cmmn_.ips;
    }
    a2cmmn_.cend[0] = abs(a2cmmn_.cend[0]);
    if (a2cmmn_.cend[0] == a2fpc_1.q2p) {
	goto L5900;
    }
    a2cmmn_.tau1[its - 1] = a2cmmn_.cend[1];
L5900:
    if (a2cmmn_.cend[0] == a2fpc_1.q1p) {
	goto L5950;
    }
    a2cmmn_.tau2[its - 1] = a2cmmn_.cend[2];
L5950:
    a2cmmn_.cend[0] = a2fpc_1.qnul;
    a2cmmn_.tau[its - 1] = a2cmmn_.tau1[its - 1] - a2cmmn_.tau2[its - 1];
    a2cmmn_.eps1[its - 1] = a2fpc_1.qp1 * a2cmmn_.tau[its - 1];
    a2cmmn_.eps8[its - 1] = a2cmmn_.eps1[its - 1];
    a2cmmn_.eps2[its - 1] = a2fpc_1.q1p - a2cmmn_.eps1[its - 1];
    a2cmmn_.eps3[its - 1] = a2fpc_1.qp9 * a2cmmn_.eps1[its - 1];
    a2cmmn_.eps4[its - 1] = a2fpc_1.q2p * a2cmmn_.tau[its - 1];
    a2cmmn_.eps6[its - 1] = a2fpc_1.qp02 * a2cmmn_.eps1[its - 1];
L6000:
    adyndp_(ab, &c__1, &c_b8);
/*     SET ITLON FLAG FOR ALL SURFACES -0 FOR ON, 1 FOR OFFSET */
    a2cmmn_.l = a2cmmn_.icscnt + 2;
    a2cmmn_.itlon[a2cmmn_.iips - 1] = a2cmmn_.isftyp[a2cmmn_.iips - 1] - 
	    3;
    a2cmmn_.itlon[a2cmmn_.iids - 1] = a2cmmn_.isftyp[a2cmmn_.iids - 1] - 
	    3;
    if (a2cmmn_.icscnt <= 0) {
	goto L700;
    }
    i__1 = a2cmmn_.l;
    for (i__ = 3; i__ <= i__1; ++i__) {
	a2cmmn_.k = a2cmmn_.lisv * (i__ - 1) + 1;
	if ((i__2 = a2cmmn_.isftyp[a2cmmn_.k - 1] - 3) < 0) {
	    goto L601;
	} else if (i__2 == 0) {
	    goto L602;
	} else {
	    goto L1;
	}
L601:
	a2cmmn_.itlon[a2cmmn_.k - 1] = 1;
	goto L1;
L602:
	a2cmmn_.itlon[a2cmmn_.k - 1] = 0;
L1:
	;
    }
/*     SET IAFL FLAG FOR AMIND */
L700:
    i__1 = a2cmmn_.l;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a2cmmn_.k = a2cmmn_.lisv * (i__ - 1) + 1;
	a2cmmn_.iafl[a2cmmn_.k - 1] = -1;
	if (a2cmmn_.jtlflg[a2cmmn_.k - 1] != 1) {
	    goto L701;
	}
	a2ctdf_1.r1[64] = a2cmmn_.ra;
	a2ctdf_1.tlhite[64] = a2cmmn_.hi;
L701:
	;
    }
/* ... */
/*     ASSUME 2 DIMENSIONAL CASE UNLESS FIND OUT DIFFERENT */
    a2cmmn_.numdim = 0;
/*     TEST FOR 5 AXIS  -IF SO,SET UP SPECIAL CUTTER + TURN OFF NUMDIM */
    if (a2cmmn_.multax > 0) {
	goto L2;
    }
/*     NOT MULTAX, SEE IF START UP. IF NOT START UP, CALL ASETUP TO SET */
/*     NUMDIM AND SPECIAL FLAGS TO SPEEDUM + CONTROL CUTTER SEGMENT USAGE */
/*     IN SOME SPECIAL CASES */

    goto L3;

/*     SET UP SPECIAL CUTTER FOR 5 AXIS */
L2:
    a2cmmn_.numdim = 1;
/* ... */

/*     TEST FOR AUTOPS--IF SO, SETUP CANONICAL FORM */
L3:
    a2cmmn_.icl = 5;
    a2cmmn_.nw = 0;
    if (a2cmmn_.iautps != 1) {
	goto L4;
    }
/* ... */
/*     SET UP CAN. FORM */
    a2cmmn_.j24[a2cmmn_.iips - 1] = 1;
    a2cmmn_.ipontr[a2cmmn_.iips - 1] = 1;
    astor_(&c__0, &c__4, &a2cmmn_.cansto[3], &c__8);
    astor_(&c__3, &c__4, a2cmmn_.cansto, &c__8);
    astor_("PSIS        ", &c__8, &a2cmmn_.cansto[2], &c__8);
    avsto_(a2cmmn_.ez, &a2cmmn_.cansto[4]);
    a2cmmn_.cansto[7] = a2cmmn_.te[2];
    avsto_(a2cmmn_.ez, &a2cmmn_.tn[a2cmmn_.ips - 1]);
    a2cmmn_.tn[a2cmmn_.ips + 1] = -a2cmmn_.tn[a2cmmn_.ips + 1];
    a2cmmn_.ipl[a2cmmn_.iips - 1] = 1;
    if (a2cmmn_.itlon[a2cmmn_.iips - 1] == 0) {
	goto L4;
    }
    i__ = a2cmmn_.ivamax;
    a2cmmn_.ivamax = 3;
    if (abs(a2cmmn_.ta[2]) < a2fpc_1.q1p && a2cmmn_.cutdat[0] > 
	    a2fpc_1.qnul) {
	aerr_(&c_n3520);
    }
    a2cmmn_.isftyp[a2cmmn_.iips - 1] = 1;
    a2cmmn_.past[a2cmmn_.ips - 1] = a2fpc_1.q1p;
    a2cmmn_.ivamax = i__;


/*     SET NUMDIM = 1 IF CUTTER DOES NOT HAVE A VERTICAL SHANK */
L4:
    if (a2cmmn_.numdim == 0) {
	asetup_();
    }
    if (a2cmmn_.cutdat[5] != a2fpc_1.qnul) {
	a2cmmn_.numdim = 1;
    }
/*     SET UP SPECIAL PARAMETERS FOR USE WITH 2-D TYPE CASE (TO GET TOOL */
/*     POINT TO BE AT CUTTER HEIGHT AT LOWEST POINT O  FULL WIDTH */
    i__1 = a2cmmn_.l;
    for (a2cmmn_.k = 1; a2cmmn_.k <= i__1; ++a2cmmn_.k) {
	i__ = a2cmmn_.lsv * (a2cmmn_.k - 1) + 1;
	ii = a2cmmn_.lisv * (a2cmmn_.k - 1) + 1;
	if (a2cmmn_.iafl[ii - 1] < 0) {
	    goto L5;
	}
	a2cmmn_.it = a2cmmn_.itseg[ii - 1];
	avmult_(a2cmmn_.ta, &a2ctdf_1.tlhite[a2cmmn_.it - 1], &
		a2cmmn_.cuth[i__ - 1]);
	a2cmmn_.cutr[i__ - 1] = a2ctdf_1.corrad[a2cmmn_.it - 1] + 
		a2ctdf_1.r1[a2cmmn_.it - 1];
L5:
	;
    }
/* ... */


/*     BRANCH TO START UP IF APPROPRIATE */
    if (a2cmmn_.istrup == 1) {
	goto L10;
    }
    if (a2cmmn_.istrup == 2) {
	goto L11;
    }
/*     NOT START UP CHECK INITAL POSITION WITH RESPECT TO PS + DS */

/*     SET UP FOR PS, AND SET PAST = 19 (DOESNT MAKE SENSE TO GO PAST THE */
/*     PS OR DS) */
    a2cmmn_.is = a2cmmn_.ips;
    a2cmmn_.iis = a2cmmn_.iips;
    a2cmmn_.past[a2cmmn_.ips - 1] = a2fpc_1.q1p;
    a2cmmn_.past[a2cmmn_.ids - 1] = a2fpc_1.q1p;
    a2cmmn_.j6 = 0;
/*     J6 SET = 0 FOR PS, 1 FOR DS */

/*     NOW INITIALIZE AMIND */
L200:
    a2cmmn_.jap = 0;
    a2cmmn_.jminr = 0;
/* ... */
    a2cmmn_.jent[a2cmmn_.iis - 1] = 1;
    a2cmmn_.jtn[a2cmmn_.iis - 1] = 0;
    a2cmmn_.iopset[a2cmmn_.iis - 1] = 0;
    a2cmmn_.jiops[a2cmmn_.iis - 1] = 0;
    a2cmmn_.ju1[a2cmmn_.iis - 1] = 0;

L250:
/* ... */
    amind_();
    avsto_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.tpk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.sp[a2cmmn_.is - 1], &a2cmmn_.spk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.tnk[a2cmmn_.is - 1]);
/*     NOW TEST IF IN TOLERANCE */
    atltst_(&itlret);
    if (a2cmmn_.jmin == 1) {
	itlret = 1;
    }
/*     ITLRET RETURNED AS */
/*     0 - WITHIN TOLER */
/*     0 - WITHIN TOLER */
/*     1 - OUT OF TOLER */
/*     BRANCH ON J6 -0 FOR PS, 1 FOR DS */
    ibr = a2cmmn_.j6 + 1;
    switch ((int)ibr) {
	case 1:  goto L270;
	case 2:  goto L280;
    }
/*     PS - TEST IF WITHIN TOLER */
L270:
    if (itlret == 0) {
	goto L275;
    }
/* ... */
/* ...  OUT OF TOLER- IF JAP = 0 (FIRST TIME THROUGH, REVERSE + RETRY */
    if (a2cmmn_.jap == 0) {
	goto L287;
    }
    aerr_(&c__502);
/*     OUT OF TOLER OF PS */
/*     PS OK - CHECK DS */
L275:
    a2cmmn_.j6 = 1;
/* ... */
    a2cmmn_.is = a2cmmn_.ids;
    a2cmmn_.iis = a2cmmn_.iids;
    goto L200;
/*     DS - SEE IF WITHIN TOLER */
L280:
    if (itlret == 0) {
	goto L399;
    }
/* ... */
    if (kpmvtn == 1 && lastds != 1) {
	goto L1541;
    }
    if (kpmvtn == 1 && a2cmmn_.iafl[a2cmmn_.iis - 1] >= 0) {
	goto L1541;
    }
/*     OUT OF TOLER, SEE IF FIRST TIME IN */
    if (a2cmmn_.jap == 0) {
	goto L287;
    }
    if (kpmvtn > 1) {
	goto L1541;
    }
    ++kpmvtn;
    if (kpmvtn == 1) {
	goto L1542;
    }
    avsto_(dstnsv, &a2cmmn_.tn[a2cmmn_.is - 1]);
    avsto_(&dstnsv[3], &a2cmmn_.tp[a2cmmn_.is - 1]);
    avsub_(&a2cmmn_.tp[a2cmmn_.is - 1], a2cmmn_.te, &a2cmmn_.vt[
	    a2cmmn_.is - 1]);
    a2cmmn_.jent[a2cmmn_.iis - 1] = 0;
    goto L250;
L1542:
    avsto_(a2cmmn_.pmove, &a2cmmn_.tn[a2cmmn_.is - 1]);
    goto L200;
L1541:
    aerr_(&c__503);
/*     OUT OF TOLER ON DS */

/*     REVERSE + RETRY AMIND CALC */
L287:
    a2cmmn_.jap = 1;
/* ... */
/*     TO SHOW SECOND TIME IN */
/*     IF ON, REVERSE Z WHICH CONTROLS UN CALCULATION. IF OFFSET,REVERSE */
/*     RC - RADIUS OF CURVATURE */
    avdot_(&a2cmmn_.vt[a2cmmn_.is - 1], a2cmmn_.ta, &ans);
    avmult_(a2cmmn_.ta, &ans, &a2cmmn_.vt[a2cmmn_.is - 1]);
    avdot_(&a2cmmn_.tn[a2cmmn_.is - 1], &a2cmmn_.u1[a2cmmn_.is - 1], &ans)
	    ;
    ans += ans;
    avmult_(&a2cmmn_.u1[a2cmmn_.is - 1], &ans, a2cmmn_.vtem);
    avsub_(&a2cmmn_.tn[a2cmmn_.is - 1], a2cmmn_.vtem, &a2cmmn_.tn[
	    a2cmmn_.is - 1]);
    if (a2cmmn_.isftyp[a2cmmn_.iis - 1] == 3) {
	a2cmmn_.z__[a2cmmn_.is - 1] = -a2cmmn_.z__[a2cmmn_.is - 1];
    }
    if (a2cmmn_.isftyp[a2cmmn_.iis - 1] != 3) {
	a2cmmn_.rc[a2cmmn_.is - 1] = -a2cmmn_.rc[a2cmmn_.is - 1];
    }
    a2cmmn_.jminr = 1;
    goto L250;
/*     ESTABLISH FOREWARD DIRECTION */
L399:
    avsto_(&a2cmmn_.tp[a2cmmn_.is - 1], &a2cmmn_.tpk[a2cmmn_.is - 1]);
    avsto_(&a2cmmn_.sn[a2cmmn_.is - 1], &a2cmmn_.snk[a2cmmn_.is - 1]);
    a2cmmn_.jap = 0;
    i__ = a2cmmn_.ivamax;
    a2cmmn_.ivamax = 3;
    if (a2cmmn_.itlon[a2cmmn_.iids - 1] == 0) {
	goto L400;
    }
    if (a2cmmn_.jcnt3 != 30 || a2cmmn_.rc[a2cmmn_.is - 1] >= a2fpc_1.qnul) 
	    {
	goto L400;
    }
    ans = (d__1 = a2cmmn_.cutdat[0] - a2cmmn_.cutdat[1], abs(d__1));
    if (ans < a2fpc_1.qp6x05) {
	goto L400;
    }
    if (a2cmmn_.j24[a2cmmn_.iids - 1] != 2) {
	goto L401;
    }
    kyo = a2cmmn_.ipontr[a2cmmn_.iids - 1] + 7;
    avdot_(&a2cmmn_.cansto[kyo - 1], a2cmmn_.ta, &ans);
    ans = abs(ans);
    if (ans >= a2fpc_1.qp6x9 && a2cmmn_.cutdat[0] < a2cmmn_.cansto[kyo + 2])
	     {
	goto L400;
    }
L401:
    aerr_(&c_n3521);
L400:
    a2cmmn_.jcnt3 = 25;
    a2cmmn_.ivamax = i__;

    *percen = a2cmmn_.vtem[0];

    afwdsl_(&c__0);
/* ... */
/*     ESTABLISH TI TO DOT POSITIVELY ON FWD */
    atisel_(&c__0);
    avcros_(a2cmmn_.ti, &a2cmmn_.tn[a2cmmn_.ids - 1], a2cmmn_.vtem);
    avdot_(a2cmmn_.vtem, a2cmmn_.ta, &ans);
    ans *= a2cmmn_.ctocl;
    i__ = a2cmmn_.ivamax;
    a2cmmn_.ivamax = 3;
    if (ans < a2fpc_1.qnul) {
	aerr_(&c_n1601);
    }
    a2cmmn_.ivamax = i__;
    a2cmmn_.jap = 0;


/*     SELECT 2D OR 3D ROUTE */
    aroute_(&i__);
/*     I=2  FOR 2D */
/*      =3  FOR 3D */
    if (i__ == 2) {
	goto L300;
    }
    *icall = 1;
    return 0;


L10:
/* ... */
/*      SEE WHETHER 2D OR 3D ROUTE TO BE USED */
    astsel_(&i__);
/*     I RETURNED AS 2 OR 3 FOR 2 OR 3D ROUTE */
    if (i__ == 2) {
	*icall = 4;
    }
    if (i__ == 3) {
	*icall = 3;
    }
    return 0;
L11:
    *icall = 5;
    return 0;

L300:
/* L350: */
/*     SET UP CALL TO ARLM2 */
/*     CUTDAT(2) = CUTTER RADIUS */
/*     TH(IDS,ICS) = THICK FOR DS,CS */
/*     TE          = CUTTER LOCATION */
/*     TI          = AIMING DIRECTION */
/*     CANSTO(IPONTR(IIDS)) = 1ST CELL OF DS CANONICAL FORM */
/*     CANSTO(IPONTR(IICS)) = 1ST CELL OF CS CANONICAL FORM */
/*     ITOPT = 1,2,3,4 TO,ON,PAST,TANTO...IN...T H A T...O R D E R */
/*     IFAR(IICS) = INTERSECTION COUNTER */
/*     TAU(IDS,ICS) TOLERANCES ON PS,DS */
/*     PERCEN = PERCENTAGE OF DS TOLER USED AT TE LOCATION */
/*     (THIS USED ONLY IF DS IS CIRCLE) */
    *kk1 = a2cmmn_.ipontr[a2cmmn_.iids - 1];
    *kk2 = a2cmmn_.ipontr[a2cmmn_.iics - 1];

    *itopt = a2cmmn_.isftyp[a2cmmn_.iics - 1];
    if (a2cmmn_.isftyp[a2cmmn_.iics - 1] == 2) {
	*itopt = 3;
    }
    if (a2cmmn_.isftyp[a2cmmn_.iics - 1] == 3) {
	*itopt = 2;
    }
    *icall = 2;
    return 0;
} /* arepre_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


