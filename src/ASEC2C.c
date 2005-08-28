/* ASEC2C.f -- translated by f2c (version 20000121).
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
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
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

static integer c__8 = 8;
static integer c__2 = 2;
static integer c__311 = 311;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__16 = 16;
static integer c__17 = 17;
static integer c__18 = 18;
static integer c__19 = 19;
static integer c__88 = 88;
static integer c_n9 = -9;
static integer c__1 = 1;
static integer c__0 = 0;

/* Subroutine */ int asec2c_(istx1, istx2)
integer *istx1, *istx2;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal ans;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int aerr_(), apock_(), astor_(), avsto_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int arpdis_(), avnorm_(), atapwt_(), atapop_(), 
	    acntrl_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     ***** */
/*     ***** */
/*     ***** */
/* ... */
/* ... */
/* ... */
    switch ((int)*istx1) {
	case 1:  goto L7000;
	case 2:  goto L7300;
	case 3:  goto L9000;
	case 4:  goto L4000;
	case 5:  goto L10000;
	case 6:  goto L11000;
	case 7:  goto L11300;
	case 8:  goto L12000;
	case 9:  goto L14000;
    }

/*     STARTUP */
/*     IS THERE A USABLE GO */
L7300:
    if (a2cmmn_1.igtflg > 0) {
	goto L7301;
    }
/*     NO USABLE GO */
    a2cmmn_1.igtflg = 0;
    a2cmmn_1.icscnt = 0;
    goto L200;
/*     YES, USABLE GO EXISTS */
L7301:
    a2cmmn_1.igtflg = 0;
    a2cmmn_1.isrch = 1;
/*     RESET MODE FLAG + PROCEED */
    goto L7000;
/*     SPECIAL PROGRAM - DO IT */
L11300:
    a2cmmn_1.igtflg = 0;
    a2cmmn_1.isrch = 1;
    goto L11000;
/*     4000 - TOOL POSITION */
/*     TLLFT,TLRGT,TLON,TLNDON,TLONPS,TLOFPS */
L4000:
    switch ((int)a2cmmn_1.instr2) {
	case 1:  goto L4001;
	case 2:  goto L4001;
	case 3:  goto L4003;
	case 4:  goto L4003;
	case 5:  goto L4005;
	case 6:  goto L4006;
    }

L4001:
    a2cmmn_1.isftyp[a2cmmn_1.iids - 1] = 1;
    a2cmmn_1.ctocl = -a2fpc_1.q1p;
    if (a2cmmn_1.instr2 == 2) {
	a2cmmn_1.ctocl = a2fpc_1.q1p;
    }
    a2cmmn_1.itlon[a2cmmn_1.iids - 1] = 1;
    goto L200;

L4003:
    a2cmmn_1.isftyp[a2cmmn_1.iids - 1] = 3;
    a2cmmn_1.itlon[a2cmmn_1.iids - 1] = 0;
    a2cmmn_1.ctocl = a2fpc_1.qnul;
    goto L200;

L4005:
    a2cmmn_1.isftyp[a2cmmn_1.iips - 1] = 3;
    a2cmmn_1.itlon[a2cmmn_1.iips - 1] = 0;
    goto L200;

L4006:
    a2cmmn_1.isftyp[a2cmmn_1.iips - 1] = 1;
    a2cmmn_1.itlon[a2cmmn_1.iips - 1] = 1;
    goto L200;
/*     STARTUP - SET UP NO. OF SURFACES */
L7000:
    astor_(a2cmmn_1.probuf, &c__8, &a2cmmn_1.numsur, &c__2);
/*     NO OFFSET. NO MULTICS */
    a2cmmn_1.istrup = a2cmmn_1.instr2;
    a2cmmn_1.ifl2 = 0;
/*     IF CUTTER NOT DEFINED ERROR */
    if (a2cmmn_1.icdefl == 0) {
	aerr_(&c__311);
    }
/* ... */
    arpdis_();
/* ... */
/*     RESET */
    a2cmmn_1.icscnt = 0;
    a2cmmn_1.indir__[a2cmmn_1.iips - 1] = 0;
    a2cmmn_1.indir__[a2cmmn_1.iids - 1] = 0;
    a2cmmn_1.indir__[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.isvfl[a2cmmn_1.iips - 1] = 0;
    a2cmmn_1.isvfl[a2cmmn_1.iids - 1] = 0;
    a2cmmn_1.isvfl[a2cmmn_1.iics - 1] = 0;
    goto L200;

/*     9000 - ARELEM PARAMETERS */
L9000:
    switch ((int)a2cmmn_1.instr2) {
	case 1:  goto L9010;
	case 2:  goto L9020;
	case 3:  goto L9030;
	case 4:  goto L9040;
	case 5:  goto L9050;
	case 6:  goto L9060;
	case 7:  goto L9070;
	case 8:  goto L9080;
    }

/*      TOOL AXIS */
L9010:
    ans = a2cmmn_1.probuf[0];
    a2cmmn_1.k = (integer) ans;
    if (a2cmmn_1.k < 1 || a2cmmn_1.k > 5) {
	aerr_(&c__2);
    }
    switch ((int)a2cmmn_1.k) {
	case 1:  goto L9011;
	case 2:  goto L9012;
	case 3:  goto L9013;
	case 4:  goto L9014;
	case 5:  goto L9015;
    }
/*      TLAXIS/ SFVCT */
L9011:
    avsto_(a2cmmn_1.ta, a2cmmn_1.tak);
    avnorm_(&a2cmmn_1.probuf[3], a2cmmn_1.ta, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__3);
    }
    a2cmmn_1.multax = 0;
    a2cmmn_1.numax = 3;
    a2cmmn_1.icc = 0;
    goto L200;
/*      NORMPS OR NORMDS */
L9012:
    astor_(&a2cmmn_1.probuf[1], &c__8, &a2cmmn_1.k, &c__4);
    if (a2cmmn_1.k < 1 || a2cmmn_1.k > 2) {
	aerr_(&c__4);
    }
    a2cmmn_1.icc = a2cmmn_1.k;
    a2cmmn_1.multax = 1;
    a2cmmn_1.numax = 5;
    goto L200;
/*      ATANGLE,K,ANG1(,SFVCT OR CUTANG,ANG2 */
L9013:
    ans = a2cmmn_1.probuf[1];
    a2cmmn_1.k = (integer) ans;
    if (a2cmmn_1.k < 1 || a2cmmn_1.k > 2) {
	aerr_(&c__5);
    }
    a2cmmn_1.icc = a2cmmn_1.k;
    a2cmmn_1.alp = a2cmmn_1.probuf[2];
    if (abs(a2cmmn_1.alp) > a2fpc_1.q90p) {
	aerr_(&c__16);
    }
    a2cmmn_1.alp = a2fpc_1.q1rad * a2cmmn_1.alp;
    if (a2cmmn_1.nwds > 3) {
	goto L9113;
    }
    a2cmmn_1.multax = 3;
    a2cmmn_1.numax = 5;
    a2cmmn_1.gamma = a2fpc_1.qnul;
    goto L200;
L9113:
    if (a2cmmn_1.nwds > 4) {
	goto L9213;
    }
/*      5 AXIS, GAMMA(CUTANG) GIVEN */
    a2cmmn_1.gamma = a2cmmn_1.probuf[3];
    if (abs(a2cmmn_1.gamma) > a2fpc_1.q90p) {
	aerr_(&c__17);
    }
    a2cmmn_1.gamma = a2fpc_1.q1rad * a2cmmn_1.gamma;
    a2cmmn_1.numax = 5;
    a2cmmn_1.multax = 3;
    goto L200;
/*      VECTOR GIVEN, 4 AXIS */
L9213:
    if (a2cmmn_1.nwds != 8) {
	aerr_(&c__18);
    }
    avnorm_(&a2cmmn_1.probuf[5], a2cmmn_1.ax4, &a2cmmn_1.ier);
    if (a2cmmn_1.ier == 1) {
	aerr_(&c__19);
    }
    a2cmmn_1.multax = 3;
    a2cmmn_1.numax = 4;
    goto L200;
/*      PARALLEL TO THE RELINGS OF A RULED SURFACE */
L9014:
    ans = a2cmmn_1.probuf[1];
    a2cmmn_1.icc = (integer) ans;
    a2cmmn_1.multax = 2;
    a2cmmn_1.numax = 5;
    goto L200;
/*      TURN OFF THE MULTI AXIS MODE */
L9015:
    a2cmmn_1.multax = 0;
    a2cmmn_1.icc = 0;
    a2cmmn_1.numax = 3;
    goto L200;

/*     MULTAX */
L9020:
    astor_(a2cmmn_1.probuf, &c__8, &a2cmmn_1.k, &c__2);
    if (a2cmmn_1.k == 1) {
	goto L9021;
    }
    a2cmmn_1.mulout = 0;
    goto L2000;
L9021:
    a2cmmn_1.mulout = 1;
    goto L2000;
/*     MAXDP */
L9030:
    a2cmmn_1.dpmax = a2cmmn_1.probuf[0];
    goto L200;
/*     NUMPTS */
L9040:
    ans = a2cmmn_1.probuf[0];
    a2cmmn_1.numpts = (integer) ans;
    goto L200;
/*     THICK */
L9050:
    i__1 = a2cmmn_1.nwds;
    for (a2cmmn_1.k = 1; a2cmmn_1.k <= i__1; ++a2cmmn_1.k) {
	i__ = (a2cmmn_1.k - 1) * a2cmmn_1.lsv + 1;
/* L9051: */
	a2cmmn_1.th[i__ - 1] = a2cmmn_1.probuf[a2cmmn_1.k - 1];
    }
    goto L200;
/*     NOPS */
L9060:
    a2cmmn_1.inops = 1;
    goto L200;

/*      AUTOPS */
L9070:
    a2cmmn_1.iautps = 1;
    a2cmmn_1.inops = 0;
    goto L200;
/*     GOUGE CHECK */
L9080:
    astor_(a2cmmn_1.probuf, &c__8, &a2cmmn_1.igoug, &c__2);
    goto L200;

L10000:
    aerr_(&c__88);
    goto L200;
/*     POCKET */
L11000:
    apock_();
    goto L200;


/*     12000 CODE FOR USER SUPPLIED ROUTINES - DATA IN PROBUF */
L12000:
/*     THE FOLLOWING CODE PROCESSES SPECIAL PROGRAM CALLS.A MAXIMUM OF 10 */
/*     DIFFERENT PROGRAMS ARE PROVIDED IN THIS SCHEME. MORE MAY BE ADDED */
/*     AT USER OPTION. */
/*     25 PARAMETERS ARE ALLOWED FOR ANY GIVEN ROUTINE */
/*     IN ORDER TO HOOK IN SUCH A SPECIAL ROUTINE, THE USER MUST */
/*        1) REMOVE THE C FROM COLUMN 1 ON THE CODE FOLLOWING */
/*        2) PROVIDE FOR PROPER OVERLAY OF HIS DECK WITH THE REST OF THE */
/*            ARITHMETIC ELEMENT */
/*        3) BE SURE TO INCLUDE NAMED COMMON A2SPEC IN HIS DECK */
/*        4) STUFF THE ALPH-MERIC NAME OF HIS ROUTINE INTO ARRAY SPNAME */
/*          (THIS CAN MOST EASILY BE DONE IN A2CTRL) */
/*           NOTE...THE C IN COLUMN 1 MUST ALSO BE REMOVED FROM THE */
/*     NAMED COMMON A2NAME IN A2CTRL */
/*     COMMON/A2NAME/SPNAME(10) */
/*     COMMON/A2SPEC/VNAME(25),VVALUE(25) */

/* ...  INSTR2 =1,2 PARAMETER VALUES ONLY OR PARAMETER NAMES AND VALUES */

/*     NWDS = TOTAL NO OF WORDS READ FROM PROTAPE INTO PROBUF...STARTS */
/*     WITH NAME OF ROUTINE TO BE CALLED */
/*     IF(NWDS.EQ.1) GO TO 12500 */
/*     STORE PARAMETERS */


/* ...  SEE IF JUST PARAMETERS OR NAMES ALSO GIVEN */
/*     GO TO (12020,12010), INSTR2 */

/*     NAMES AND VALUES - STUFF NAME INTO ARRAY VNAME */
/* L12010: */
/*     DO 12015 I = 2,NWDS,2 */
/*     K = I/2 */
/*     CALL ASTOR(PROBUF(I),8,VNAME(K),8) */
/*     NOW STUFF VALUE */

/*     CALL ASTOR(PROBUF(I+1),8,VVALUE(K),8) */
/* L12015: */
/*     GO TO 12500 */

/* ...  JUST VALUES */

/* L12020: */
/*     DO 12025 I = 2,NWDS,1 */

/*     STUFF VALUES */

/*     CALL ASTOR(PROBUF(I), 8,VVALUE(I),8) */

/* L12025: */

/* ...  NOW CALL IN ROUTINE */

/* L12500: */
/*     CALL ASTOR(PROBUF(1), 8,AN,8) */
/*     DO 12510 I = 1,10 */
/*     IF(AN.EQ.SPNAME(I)) GO TO 12550 */
/* L12510: */
/*     CALL AERR(20) */
/* L12550: */
/*     GO TO (12610,12620,12630,12640,12650,12660,12670,12680,12690,12700 */
/*    1),I */

/* L12610: */
/*     CALL XXXXXX */
/*     GO TO 200 */
/* L12620: */
/*     CALL XXXXXX */
/*     GO TO 200 */
/* L12630: */
/*     CALL */
/*     GO TO 200 */
/* L12640: */
/*     CALL */
/*     GO TO 200 */
/* L12650: */
/*     CALL */
/*     GO TO 200 */
/* L12660: */
/*     CALL */
/*     GO TO 200 */
/* L12670: */
/*     CALL */
/*     GO TO 200 */
/* L12680: */
/*     CALL */
/*     GO TO 200 */
/* L12690: */
/*     CALL */
/*     GO TO 200 */
/* L12700: */
/*     CALL */
/*     GO TO 200 */
    goto L200;
/*     FINI */
L14000:
    if (a2cmmn_1.isrch != 2) {
	goto L14001;
    }
    i__ = a2cmmn_1.ivamax;
    a2cmmn_1.ivamax = 4;
    aerr_(&c_n9);
    a2cmmn_1.ivamax = i__;
    asistm_1.iwaven = 2;
    goto L14002;
L14001:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_1.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    a2cmmn_1.instr1, &c__1, &a2cmmn_1.instr2, &c__1, a2cmmn_1.probuf, 
	    &c__0);
/*     REWIND CLTAPE,PROTAPE */
L14002:
    atapop_(&ataptb_1.cltape, &c__2, &a2cmmn_1.ier);
    atapop_(&ataptb_1.cltape, &c__1, &a2cmmn_1.ier);
    atapop_(&ataptb_1.protap, &c__1, &a2cmmn_1.ier);
    atapop_(&ataptb_1.srftap, &c__1, &a2cmmn_1.ier);
    atapop_(&ataptb_1.poctap, &c__1, &a2cmmn_1.ier);
/*     ZERO OUT IPS AS AN INITIALIZATION FLAG */
    a2cmmn_1.ips = 0;
/* ... */
    acntrl_();
/* ... */
    goto L2200;
L200:
    *istx2 = a0con_1.k1;
    goto L2200;
L2000:
    *istx2 = a0con_1.k2;
L2200:
    return 0;
} /* asec2c_ */

#undef tlldat
#undef cosl
#undef sinl


