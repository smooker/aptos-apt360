/* ADELTA.f -- translated by f2c (version 20000121).
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
    integer kanas[27], j24[1], ifillr[212];
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

static integer c__3 = 3;
static integer c_b3 = 111100;
static integer c__5 = 5;
static integer c_b11 = 110000;

/* Subroutine */ int adelta_()
{
    /* Initialized data */

    static struct {
	char e_1[88];
	real e_2;
	} equiv_12 = { {'A', 'D', 'E', 'L', 'T', 'A', 'T', 'P', 'A', 'D', 'E',
		 'L', 'T', 'A', '0', '1', 'A', 'D', 'E', 'L', 'T', 'A', '0', 
		'2', 'A', 'D', 'E', 'L', 'T', 'A', '0', '3', 'A', 'D', 'E', 
		'L', 'T', 'A', '0', '4', 'A', 'D', 'E', 'L', 'T', 'A', '0', 
		'5', 'A', 'D', 'E', 'L', 'T', 'A', '0', '6', 'A', 'D', 'E', 
		'L', 'T', 'A', '0', '7', 'A', 'D', 'E', 'L', 'T', 'A', 'E', 
		'X', 'A', 'D', 'E', 'L', 'T', 'A', '0', '8', 'A', 'D', 'E', 
		'L', 'T', 'A', '0', '9'}, (float)0. };

#define ab ((real *)&equiv_12)


    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__;
    static doublereal aap, bap;
    static integer kap, k22222, ikap, ipsf, idsf;
    extern /* Subroutine */ int avsto_(), avsub_(), avdot_(), agouck_(), 
	    adyndp_();
    static integer ijklmn;
    extern /* Subroutine */ int accurv_();
    static doublereal dpsavr;
    extern /* Subroutine */ int avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
    adyndp_(ab, &c__3, &c_b3);
    k22222 = 0;
    ijklmn = 0;
    aap = a2cmmn_1.rc[a2cmmn_1.ips - 1];
    bap = a2cmmn_1.rc[a2cmmn_1.ids - 1];
    kap = a2cmmn_1.is;
    ikap = a2cmmn_1.iis;
    a2cmmn_1.dpe = a2fpc_1.q1pe10;
    a2cmmn_1.dpi = a2cmmn_1.dp;
/* Computing 2nd power */
    d__1 = a2cmmn_1.rc1;
    a2cmmn_1.rc1 = d__1 * d__1;
    a2cmmn_1.j = 0;
/*  SPECIAL BRANCH FOR NORMPS OR NORMDS */
    ipsf = 0;
    idsf = 0;
    if (a2cmmn_1.multax != 1) {
	goto L101;
    }
    if (a2cmmn_1.numax != 5) {
	goto L101;
    }
    if (a2cmmn_1.icc == 1) {
	ipsf = 1;
    }
    if (a2cmmn_1.icc == 2) {
	idsf = 1;
    }
/* 1.2      DO FOR PART SURFACE FIRST */
L101:
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;

/* 1.3      CALCULATE P1, P2, AND IK, CCURV INPUTS, AND ZL=DIST(P1,P2) */
L103:
    if (a2cmmn_1.is == a2cmmn_1.ips && ipsf == 1) {
	goto L1003;
    }
    if (a2cmmn_1.is == a2cmmn_1.ids && idsf == 1) {
	goto L1003;
    }
    goto L104;
L1003:
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], a2cmmn_1.p1);
    avsto_(&a2cmmn_1.spk[a2cmmn_1.is - 1], a2cmmn_1.p2);
    goto L106;
L104:
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.cutdat[1], a2cmmn_1.vtem)
	    ;
    avsub_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, a2cmmn_1.tem);
    avmult_(&a2cmmn_1.tnk[a2cmmn_1.is - 1], &a2cmmn_1.cutdat[1], 
	    a2cmmn_1.vtem);
    avsub_(&a2cmmn_1.tpk[a2cmmn_1.is - 1], a2cmmn_1.vtem, &a2cmmn_1.tem[3]);
    avsub_(a2cmmn_1.tem, a2cmmn_1.te, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.ta, &a2cmmn_1.prod1);
    avsub_(&a2cmmn_1.tem[3], a2cmmn_1.tek, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, a2cmmn_1.tak, &a2cmmn_1.prod2);
    a2cmmn_1.zl = a2fpc_1.qnul;
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= 3; ++a2cmmn_1.k) {
	a2cmmn_1.p1[a2cmmn_1.k - 1] = a2cmmn_1.te[a2cmmn_1.k - 1] + 
		a2cmmn_1.prod1 * a2cmmn_1.ta[a2cmmn_1.k - 1];
	a2cmmn_1.p2[a2cmmn_1.k - 1] = a2cmmn_1.tek[a2cmmn_1.k - 1] + 
		a2cmmn_1.prod2 * a2cmmn_1.tak[a2cmmn_1.k - 1];
/* L105: */
    }
L106:
    avsub_(a2cmmn_1.p1, a2cmmn_1.p2, a2cmmn_1.vtem);
    if (a2cmmn_1.jbr == 1) {
	avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    }
    if (ipsf == 1 && a2cmmn_1.is == a2cmmn_1.ips) {
	avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    }
    if (idsf == 1 && a2cmmn_1.is == a2cmmn_1.ids) {
	avsub_(a2cmmn_1.te, a2cmmn_1.tek, a2cmmn_1.vtem);
    }
    avdot_(a2cmmn_1.vtem, a2cmmn_1.vtem, &a2cmmn_1.zl);
    adyndp_(&ab[2], &c__5, &c_b11);
/* *** */
/* *** */
/*      DELETED */
/*     IK=IS+J */
/* *** */
/* *** */

/* 1.4      FIND RC=RADIUS OF CURVATURE ALONG NORMAL AT P1 */
    if (a2cmmn_1.j == 0) {
	accurv_(&a2cmmn_1.is, &a2cmmn_1.iis, a2cmmn_1.p1, a2cmmn_1.p2, &
		a2cmmn_1.sn[a2cmmn_1.is - 1]);
    }
    if (a2cmmn_1.j == 3) {
	accurv_(&a2cmmn_1.is, &a2cmmn_1.iis, a2cmmn_1.p1, a2cmmn_1.p2, &
		a2cmmn_1.snk[a2cmmn_1.is - 1]);
    }

    if ((d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(d__1)) - a2fpc_1.q45p != 0.)
	     {
	goto L301;
    } else {
	goto L302;
    }
L302:
    a2cmmn_1.d1 = a2fpc_1.q9000p;
    goto L303;
L301:
    a2cmmn_1.d1 = a2fpc_1.q2p * (d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(
	    d__1));

L303:
    adyndp_(&ab[4], &c__5, &c_b11);
    if (a2cmmn_1.is - a2cmmn_1.ips != 0) {
	goto L113;
    } else {
	goto L112;
    }
/* 1.7      STORE RESULTS IN D2A,ZL1, AND RETURN FOR LIKE CALC. FOR DS */
L112:
    a2cmmn_1.d2a = a2cmmn_1.d1;
    a2cmmn_1.zl1 = a2cmmn_1.zl;
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    goto L103;

/* 1.8      USE RESULTS OF SURFACE, PS OR DS, HAVING GREATEST CURVATURE */
L113:
    if (a2cmmn_1.d1 - a2cmmn_1.d2a <= 0.) {
	goto L115;
    } else {
	goto L114;
    }
/* 1.9      RESTORE PS RESULTS (MOST CONSERVATIVE AFTER ALL) */
L114:
    a2cmmn_1.d1 = a2cmmn_1.d2a;
    a2cmmn_1.zl = a2cmmn_1.zl1;
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    adyndp_(&ab[6], &c__5, &c_b11);
/* 1.10     UNSQUARE ZL AND CALCULATE DP (SAFE CUT VECTOR */
/* 1.10    LENGTH BASED ON SURFACE WITH MOST CURVATURE) */
L115:
    a2cmmn_1.zl = sqrt(a2cmmn_1.zl);
    a2cmmn_1.rc[a2cmmn_1.ips - 1] = aap;
    a2cmmn_1.rc[a2cmmn_1.ids - 1] = bap;
    a2cmmn_1.dp = sqrt(a2fpc_1.q4p * a2cmmn_1.tau[a2cmmn_1.is - 1] * (d__1 = 
	    a2cmmn_1.d1 - a2cmmn_1.tau[a2cmmn_1.is - 1], abs(d__1)));
/* 1.12     IF BEGINNING CUT VECTOR CANDIDATE BEING TESTED, STORE */
/* 1.12    CURRENT RESULTS (BASED ON NORMALS AT TERMINUS OF CUT VECTOR) */
/* 1.12    AND RETURN FOR CALCULATIONS BASED ON NORMALS AT ORIGIN OF */
/* 1.12    CUT VECTOR */
    if (a2cmmn_1.j12 <= 0) {
	goto L116;
    } else {
	goto L117;
    }
L116:
    a2cmmn_1.dpe = a2cmmn_1.dp;
    a2cmmn_1.zl2 = a2cmmn_1.zl;
    a2cmmn_1.j = 3;
    a2cmmn_1.j12 = 1;
    adyndp_(&ab[8], &c__5, &c_b11);
    goto L101;

/* 1.13     UNSQUARE RC1.  NO FURTHER USE FOR THIS VARIABLE. */
L117:
    a2cmmn_1.rc1 = sqrt(a2cmmn_1.rc1);

/* 1.14     COMPARE CUT VECTOR LENGHTS BASED ON NORMALS AT ORIGIN AND */
/* 1.14    TERMINUS OF CUT VECTOR.  IF BEGINNING CUT VECTOR CANDIDATE */
/* 1.14    NOT UNDER CONSIDERATION DPE IS RIDICULOUS--TRANSFER TO C1.15 */
    if (a2cmmn_1.dp - a2cmmn_1.dpe <= 0.) {
	goto L119;
    } else {
	goto L118;
    }
/* 1.15     RESTORE RESULTS BASED ON NORMALS AT TERMINUS */
/* 1.15    OF CUT VECTOR CANDIDATE */
L118:
    a2cmmn_1.dp = a2cmmn_1.dpe;
    a2cmmn_1.zl = a2cmmn_1.zl2;
    adyndp_(&ab[10], &c__5, &c_b11);

/* 1.16     PRESERVE UNTRUNCATED DP FOR USE IN ANOTHER PROGRAM */
L119:
    a2cmmn_1.dpl = a2cmmn_1.dp;

/* 2.1      TRUNCATE DP SO AS TO LIE BETWEEN TAU AND DPMAX */
    if ((d__1 = a2cmmn_1.dp - a2cmmn_1.dpmax) < 0.) {
	goto L122;
    } else if (d__1 == 0) {
	goto L125;
    } else {
	goto L121;
    }
L122:
    if (a2cmmn_1.dp - a2cmmn_1.tau[a2cmmn_1.is - 1] >= 0.) {
	goto L125;
    } else {
	goto L124;
    }
L124:
    a2cmmn_1.dp = a2cmmn_1.tau[a2cmmn_1.is - 1];
    adyndp_(&ab[12], &c__5, &c_b11);
    goto L125;
L121:
    a2cmmn_1.dp = a2cmmn_1.dpmax;

L125:
    if (a2cmmn_1.dp - a2cmmn_1.zl + a2cmmn_1.tau[a2cmmn_1.is - 1] >= 0.) {
	goto L151;
    } else {
	goto L130;
    }
L155:
    if (a2cmmn_1.dp - a2fpc_1.qp6 * a2cmmn_1.dpi + a2cmmn_1.tau[a2cmmn_1.is - 
	    1] >= 0.) {
	goto L127;
    } else {
	goto L129;
    }
/* 2.9      CUT VECTOR CANDIDATE MUCH TOO LONG.  REDUCE IT TO .6 OF ITS */
/* 2.9     CURRENT VALUE, SUBMIT TO ONE MORE TEST AND EXIT FAILING */
L129:
    a2cmmn_1.dp = a2fpc_1.qp6 * a2cmmn_1.dpi;
    adyndp_(&ab[14], &c__5, &c_b11);
    goto L127;
/* 2.10     BYPASS FURTHER DP MODIFICATION AND EXIT AT ONCE IF CS INVOLVED */
L130:
    if (a2cmmn_1.dp - a2cmmn_1.dpi <= 0.) {
	goto L841;
    } else {
	goto L141;
    }
L841:
    a2cmmn_1.dpi = a2cmmn_1.dp / a2cmmn_1.zl;
    goto L243;

/* 2.11     IF ZL EXCEEDS DPI REDUCE DP BY A FACTOR DPI/ZL */
L141:
    a2cmmn_1.dpi /= a2cmmn_1.zl;
L243:
    if (a2cmmn_1.dpi - a2fpc_1.qp6 <= 0.) {
	goto L244;
    } else {
	goto L143;
    }
L244:
    a2cmmn_1.dpi = a2fpc_1.qp6;
L143:
    a2cmmn_1.dp *= a2cmmn_1.dpi;

/* 2.14     REJECT CUT VECTOR CANDIDATE */
L145:
    a2cmmn_1.jdr = 1;
    i__ = (integer) (a2cmmn_1.dpcnt + a2fpc_1.qp01);
    if (i__ == 10) {
	goto L146;
    }
    if (i__ > 5) {
	goto L201;
    }
    if (a2cmmn_1.zl - dpsavr >= 0.) {
	goto L201;
    } else {
	goto L160;
    }
L146:
    if (a2cmmn_1.jbr == 0) {
	dpsavr = a2cmmn_1.dp;
    }
L201:
    a2cmmn_1.is = kap;
    a2cmmn_1.iis = ikap;
    if (k22222 != 0) {
	goto L99999;
    }
    ijklmn = a2cmmn_1.jbr + a2cmmn_1.jdr;
    if (ijklmn == 2 && a2cmmn_1.dpcnt <= a2fpc_1.q3p) {
	goto L157;
    }
L99999:
    adyndp_(&ab[16], &c__3, &c_b3);
    return 0;


/*         TENTATIVELY ACCEPT CUT VECTOR (MUST PASS GOUGCK YET) */
/* 2.16     CUT DP DOWN TO 2DPI IF IT EXCEEDS THIS NO.  THIS PREVENTS */
/* 2.16    WILD FLUCUATIONS OF THE DP CAUSED BY RAPID CHANGE */
/* 2.16    IN SURFACE CURVATURE ALSO PRESENTS POINT SPACING */
/* 2.16    TO POST PROCESSOR ADAPTABLE TO FEED RATES. */
L151:
    if (a2cmmn_1.dp - a2fpc_1.q2p * a2cmmn_1.dpi + a2cmmn_1.tau[a2cmmn_1.is - 
	    1] <= 0.) {
	goto L155;
    } else {
	goto L153;
    }
L153:
    a2cmmn_1.dp = a2fpc_1.q2p * a2cmmn_1.dpi;


    adyndp_(&ab[18], &c__5, &c_b11);
L127:
    if (a2cmmn_1.jckr == 1 && a2cmmn_1.j24[a2cmmn_1.iips - 1] == 2 && 
	    a2cmmn_1.d2a < a2fpc_1.q9000p) {
	goto L157;
    }
    if (a2cmmn_1.igoug <= 0) {
	goto L160;
    } else {
	goto L157;
    }
L157:
    if (ijklmn == 2 && a2cmmn_1.dpcnt <= a2fpc_1.q3p) {
	k22222 = 1;
    }
    agouck_();
/* 2.22     IF GOUGCK FAILS, REJECT CUT VECTOR AND REDUCE DP TO .75DP */
    if (a2cmmn_1.jgr != 0) {
	goto L159;
    } else {
	goto L160;
    }
L159:
    a2cmmn_1.dp = a2fpc_1.qp75 * a2cmmn_1.dp;
    adyndp_(&ab[20], &c__5, &c_b11);
    goto L145;

/* 2.23     ACCEPT CUT VECTOR CANDIDATE */
L160:
    a2cmmn_1.jdr = 0;
    goto L201;


} /* adelta_ */

#undef ab


