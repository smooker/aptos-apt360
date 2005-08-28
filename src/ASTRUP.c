/* ASTRUP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
static integer c_b3 = 111100;
static integer c__601 = 601;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__6 = 6;
static integer c__602 = 602;
static integer c__0 = 0;
static integer c_n10 = -10;
static integer c__603 = 603;

/* Subroutine */ int astrup_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_31 = { {'A', 'S', 'T', 'R', 'U', 'P', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_31)


    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_stop();

    /* Local variables */
    static integer i__, ia, ib, kk;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    extern /* Subroutine */ int aerr_(), avadd_();
    static integer ikk, ipls;
    extern /* Subroutine */ int amind_();
    static integer j24s;
    static doublereal ans;
    extern /* Subroutine */ int atape_();
    static integer nrc1;
    static doublereal pssav[9];
    static integer ipsfl;
    extern /* Subroutine */ int avsto_();
    static integer kboth, iexey;
    static doublereal sexey, zexey;
    extern /* Subroutine */ int addst_(), avdot_(), astor_(), astos_(), 
	    acheck_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    static doublereal spexey[3], tpexey[3], tnexey[3], snexey[3];
    extern /* Subroutine */ int adyndp_();
    static integer misind;
    static doublereal tempry;
    extern /* Subroutine */ int avmult_(), avnorm_();
    static integer iunfls, isftps, itlons;
    static doublereal athsav;
    extern /* Subroutine */ int acentr_(), avcros_();
    static integer inosav;
    extern /* Subroutine */ int ataprd_(), aserch_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ... */
/* ... A2CMMN START */
/* ... A2CMMN END */
/* ... */
/* ... */
/* ... */
/* ... */
/* ...  I ... INDEX USED TO SELECT SURFACES DURING  STEP ONE AND TWO. */
/* ...  IA ... INTERNAL COUNTER ... USED TO PROCESS INDIR(IF ANY).DURING */
/* ...  STEP ONE, IA IS INCREMENTED BY ONE EACH TIME A SURFACE WITH AN */
/* ...  INDIR IS ENCOUNTERED. DURING THE STEP TWO, IT IS DECREMENTED BY */
/* ...  ONE EACH TIME AN INDIR SURFACE IS PROCESSED. */
/* ...  IB ... INTERNAL BRANCHING INDICATOR */
/* ...       =1 DURING STEP ONE */
/* ...       =2 DURING STEP TWO */
/* ...       =3 DURING STEP THREE ... SPECIAL CASE WHEN INDIR VECTOR DOES */
/* ...          NOT PIERCE THE SURFACE. */
/* ...  TEMPRY ... USED TO STORE THE LARGEST NORMAL DISTANCE YET */
/* ...             ENCOUNTERED. USED WHEN AN INDIR VECTOR DOES NOT */
/* ...             PIERCE ITS ASSOCIATED SURFACE. */
/* ... */
/* ... */
/* ... */
/* ...  *************************************************  ASTRUPTP  **** */
    adyndp_(ab, &c__1, &c_b3);
/* ... */
    misind = 0;
    ipsfl = 0;
    avsto_(a2cmmn_1.te, a2cmmn_1.tek);
    a2cmmn_1.notan[a2cmmn_1.iics - 1] = 0;
/* ... */
/* ...  NUMAX=5 WHEN TLAXIS/NORMPS,NORMDS */
/* ...               TLAXIS/ATANGL,K,ANG1,SVECT(CUTANG,ANG2) */
/* ...               TLAXIS/PARLEL,K */
/* ...  FOR TLAXIS/SVECT, NUMAX=3 */
/* ... */
    if (a2cmmn_1.numax == 5) {
	goto L5000;
    }
/* ... */
/* ...  STATEMENT 9000 IS AERR(603) .. ILLEGAL PROTAP RECORD FOR STARTUP. */
/* ...  IF ONE-SURFACE STARTUP (GO/S1) AND NO NOPS, NUMSUR = 2. */
/* ...  IF ONE-SURFACE STARTUP(GO/S1) AND NOPS AND AUTOPS, NUMSUR = 2. */
/* ...  AFTER ASTRUP, ASTUP2, AND AOFSET OPERATION, IAUTPS=0,  INOPS=0. */
/* ...  BUT THESE TWO FLAGS ARE MAINTAINED AFTER ARLM3 AND ARLM2. */
/* ... */
L1000:
    if (a2cmmn_1.inops < 0) {
	goto L9000;
    } else if (a2cmmn_1.inops == 0) {
	goto L1075;
    } else {
	goto L1010;
    }
L1075:
    if (a2cmmn_1.numsur - 1 != 0) {
	goto L1070;
    } else {
	goto L1060;
    }
L1010:
    if ((i__1 = a2cmmn_1.numsur - 1) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1030;
    } else {
	goto L1020;
    }
/* ...  NOPS IN EFFECT, BUT STARTUP NUMBER OF SURFACES NOT = 1  ** 601 ** */
L1020:
    aerr_(&c__601);
/* ... */
/* ... */
L1030:
    if (a2cmmn_1.iautps < 0) {
	goto L9000;
    } else if (a2cmmn_1.iautps == 0) {
	goto L1070;
    } else {
	goto L1060;
    }
L1060:
    ++a2cmmn_1.numsur;
/* ... */
/* ...                     *** STEP ONE *** */
/* ... */
/* ...  EXAMINE ALL SURFACES IN THE ORDER DS, PS, CS.  DEFER ANY SURFACE */
/* ...  FOR WHICH INDIR VECTOR HAS BEEN GIVEN UNTIL STEP TWO. */
L1070:
    i__ = 0;
    ia = 1;
    ib = 1;
    tempry = a2fpc_1.qnul;
/* ... */
L1080:
    ++i__;
/* L1090: */
    if (a2cmmn_1.numsur - i__ >= 0) {
	goto L1100;
    } else {
	goto L1300;
    }
L1100:
    if ((i__1 = i__ - 2) < 0) {
	goto L1110;
    } else if (i__1 == 0) {
	goto L1120;
    } else {
	goto L1130;
    }
/* ... */
L1110:
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    goto L1140;
/* ... */
L1120:
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    goto L1140;
/* ... */
L1130:
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
/* ... */
/* ...  IF INDIR GIVEN DEFER EXAMINATION TILL STEP TWO */
/* ...  FOR SURFACES WITHOUT INDIR, DETERMINE THE SURFACE SIDE THE CUTTER */
/* ...  IS TO POSITION TO. -- TWO WAYS TO DO -- IF SFVCT GIVEN , ** A ** */
/* ...                                          IF NO SFVCT    , ** B ** */
L1140:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iis - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1160;
    } else {
	goto L1150;
    }
L1150:
    ++ia;
    goto L1080;
/* ... */
/* ... */
/* ... */
L1160:
/* L1161: */
    if ((i__1 = a2cmmn_1.isvfl[a2cmmn_1.iis - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1180;
    } else {
	goto L1170;
    }
/* ...  ** A **       SET TI=SFVCT AND CALL ACHECK */
/* ...           SFVCT CONTROLS SETTING OF Z WHICH WILL CONTROL THE SIDE */
/* ...           OF SURFACE THE SN POINTS TO, WHICH WILL CONTROL THE SIDE */
/* ...           OF SURFACE CUTTER WILL POSITION TO.  SFVCT POINTS FROM */
/* ...           TO SIDE OF THE SURFACE IN THE DIRECTION OF PAST SIDE */
/* ... */
L1170:
    avsto_(&a2cmmn_1.sfvct[a2cmmn_1.is - 1], a2cmmn_1.ti);
    avsto_(&a2cmmn_1.sfvct[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.j20[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.j23[a2cmmn_1.iis - 1] = 1;
    acheck_();
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] != 0.) {
	goto L1240;
    } else {
	goto L1210;
    }
/* ... */
/* ...  ** B **       CALL AMIND, WHICH SETS A VALUE OF Z BASED ON TM. */
/* ...           THE VALUE OF Z WHICH WILL CONTROL THE SIDE OF SURFACE */
/* ...           THE SN POINTS TO, WHICH WILL CONTROL THE SIDE OF SURFACE */
/* ...           CUTTER WILL POSITION TO.  TO SIDE OF SURFACE IS TO BE */
/* ...           THE SIDE TM IS INITIALLY ON, PAST SIDE IS THE OPPOSITE */
/* ...           SIDE. */
/* ... */
L1180:
    avsto_(a2cmmn_1.ex, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    kboth = 0;
    iexey = 0;
    sexey = a2fpc_1.q1pe38;
    if (a2cmmn_1.indir__[a2cmmn_1.iis - 1] + a2cmmn_1.isvfl[a2cmmn_1.iis - 1] 
	    == 0 && (a2cmmn_1.j24[a2cmmn_1.iis - 1] == 7 || a2cmmn_1.j24[
	    a2cmmn_1.iis - 1] == 8)) {
	kboth = 1;
    }
L1190:
    a2cmmn_1.jminr = 1;
    a2cmmn_1.iopset[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.jent[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.jtn[a2cmmn_1.iis - 1] = 0;
    a2cmmn_1.ju1[a2cmmn_1.iis - 1] = 1;
    a2cmmn_1.jiops[a2cmmn_1.iis - 1] = 0;
/* L1200: */
    amind_();
    if (a2cmmn_1.is == misind && a2cmmn_1.jmin == 0) {
	misind = -a2cmmn_1.is;
    }
    if (kboth == 0 && a2cmmn_1.jmin != 0) {
	goto L3150;
    }
    if (kboth == 0) {
	goto L1210;
    }
    ++iexey;
    if (iexey >= 2) {
	goto L77777;
    }
    if (a2cmmn_1.jmin != 0) {
	goto L77776;
    }
    sexey = a2cmmn_1.s[a2cmmn_1.is - 1];
    zexey = a2cmmn_1.z__[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.sn[a2cmmn_1.is - 1], snexey);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], tnexey);
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], tpexey);
    avsto_(&a2cmmn_1.sp[a2cmmn_1.is - 1], spexey);
L77776:
    avsto_(a2cmmn_1.ey, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    goto L1190;
/* ... */
L77777:
    if (a2cmmn_1.jmin != 0 && sexey == a2fpc_1.q1pe38) {
	goto L3150;
    }
    if (a2cmmn_1.jmin != 0) {
	goto L77775;
    }
    if (sexey == a2fpc_1.q1pe38) {
	goto L1210;
    }
    if (abs(sexey) >= (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1))) {
	goto L1210;
    }
L77775:
    avsto_(tnexey, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    avsto_(tpexey, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avsto_(spexey, &a2cmmn_1.sp[a2cmmn_1.is - 1]);
    a2cmmn_1.s[a2cmmn_1.is - 1] = sexey;
    a2cmmn_1.z__[a2cmmn_1.is - 1] = zexey;
    avsto_(snexey, &a2cmmn_1.sn[a2cmmn_1.is - 1]);
    a2cmmn_1.jminr = 0;
L1210:
    a2cmmn_1.csd[a2cmmn_1.is - 1] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(
	    d__1));
L1240:
    if (tempry - (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) <= 0.) {
	goto L1250;
    } else {
	goto L1260;
    }
L1250:
    tempry = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1));
L1260:
    switch ((int)ib) {
	case 1:  goto L1080;
	case 2:  goto L1310;
	case 3:  goto L1270;
    }
L1270:
    ib = 2;
    goto L1500;
/* ...                    *** STEP TWO *** */
/* ...           AGAIN EXAMINE EACH SURFACE (DS,PS,CS) -- THIS TIME */
/* ...           PROCESSING ONLY THOSE SURFACES WHICH HAVE INDIR VECTORS. */
L1300:
    i__ = 0;
    ib = 2;
L1310:
    --ia;
/* L1320: */
    if (ia < 0) {
	goto L9000;
    } else if (ia == 0) {
	goto L2000;
    } else {
	goto L1330;
    }
L1330:
    ++i__;
/* L1340: */
    if (a2cmmn_1.numsur - i__ >= 0) {
	goto L1350;
    } else {
	goto L9000;
    }
L1350:
    if ((i__1 = i__ - 2) < 0) {
	goto L1360;
    } else if (i__1 == 0) {
	goto L1370;
    } else {
	goto L1380;
    }
/* ... */
L1360:
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
    goto L1390;
/* ... */
L1370:
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    goto L1390;
/* ... */
L1380:
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
/* ... */
L1390:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iis - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1330;
    } else {
	goto L1400;
    }
/* ... */
/* ...  FOR EACH SURFACE WHICH HAS INDIR, PIERCE SURFACE WITH INDIR */
/* ...  VECTOR FROM TM (ADJUST FOR THICK) */
/* ... */
L1400:
    a2cmmn_1.temp[0] = a2fpc_1.qp5 * a2cmmn_1.cutdat[6];
    a2cmmn_1.vtem[0] = min(a2cmmn_1.temp[0],a2cmmn_1.cutdat[0]);
    if (a2cmmn_1.j24[a2cmmn_1.iis - 1] != 4 || a2cmmn_1.rc[a2cmmn_1.is - 1] >=
	     a2fpc_1.qnul) {
	a2cmmn_1.vtem[0] = a2cmmn_1.temp[0];
    }
    if (a2cmmn_1.jtlflg[a2cmmn_1.iis - 1] == 1) {
	a2cmmn_1.vtem[0] = a2ctdf_1.tlhite[64];
    }
    avmult_(a2cmmn_1.ta, a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.te, &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avmult_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], &a2cmmn_1.th[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1], &a2cmmn_1.tp[
	    a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1]);
    a2cmmn_1.iop[a2cmmn_1.iis - 1] = 1;
    addst_();
    if (a2cmmn_1.ier != 0) {
	misind = a2cmmn_1.is;
    }
    if (a2cmmn_1.ier != 0) {
	goto L1410;
    } else {
	goto L1430;
    }
/* ... */
/* ... */
/* ...  SORRY, INDIR VECTOR DOES NOT PIERCE THE SURFACE */
/* ...  MOVE CUTTER EXACTLY ALONG INDIR VECTOR BY LARGEST |S| YET COMPUTED */
L1410:
    ib = 3;
    goto L1160;
/* ... */
/* ... */
/* ...  ADDST SUCCESSFUL --- */
/* ...      MOVE THE CUTTER (TE) EXACTLY ALONG INDIR VECTOR BY AMOUNT */
/* ...      EQUAL TO      (1) DISTANCE TO PIERCE POINT IF ON CONDITION */
/* ...                   (2) ADJUSTED DISTANCE BY CUTDAT(1) FOR TO, PAST */
L1430:
    a2cmmn_1.temp[1] = a2cmmn_1.s[a2cmmn_1.is - 1];
    if (a2cmmn_1.isftyp[a2cmmn_1.iis - 1] - 3 != 0) {
	goto L1445;
    } else {
	goto L1440;
    }
L1445:
    a2cmmn_1.temp[1] -= a2cmmn_1.cutdat[0];
L1440:
    a2cmmn_1.temp[4] = a2cmmn_1.temp[1] - a2cmmn_1.tau[a2cmmn_1.is - 1];
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] + a2cmmn_1.ipl[a2cmmn_1.iids - 1] + 
	    a2cmmn_1.ipl[a2cmmn_1.iics - 1] == 3) {
	a2cmmn_1.temp[4] *= a2fpc_1.qp75;
    }
    if (abs(misind) != a2cmmn_1.is) {
	goto L87878;
    }
    a2cmmn_1.temp[4] = (d__1 = a2cmmn_1.s[a2cmmn_1.is - 1], abs(d__1)) * 
	    a2fpc_1.qp75;
L87878:
    misind = 0;
    avmult_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], &a2cmmn_1.temp[4], 
	    a2cmmn_1.vtem);
    avadd_(a2cmmn_1.te, a2cmmn_1.vtem, a2cmmn_1.te);
    goto L1160;
/* ... */
L1500:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - tempry <= 0.) {
	goto L1510;
    } else {
	goto L1520;
    }
L1510:
    a2cmmn_1.temp[1] = tempry;
    goto L1440;
/* ... */
L1520:
    if (a2cmmn_1.csd[a2cmmn_1.is - 1] - a2fpc_1.q10p >= 0.) {
	goto L1510;
    } else {
	goto L1530;
    }
L1530:
    a2cmmn_1.temp[1] = a2cmmn_1.csd[a2cmmn_1.is - 1];
    goto L1440;
/* ...                    *** STEP THREE *** */
/* ... */
/* ...  ** ACENTR WILL BE USED TO MOVE THE CUTTER INTO PROPER POSITION */
/* ...     WITH RESPECT TO THE SURFACE(S). */
/* ...  -- THERE ARE 3 MAJOR CASES -- NUMSUR = 1, 2, OR 3 */
/* ...     IF NUMSUR = 3, SET J50,J51=1 , CALL ACENTR AND DO 3 SURF ITER */
/* ...************************************ */
L2000:
    if ((i__1 = a2cmmn_1.numsur - 2) < 0) {
	goto L2010;
    } else if (i__1 == 0) {
	goto L3000;
    } else {
	goto L3120;
    }
/* ...                               *** ONE-SURFACE STARTUP *** */
/* ...     SET UP PSEUDO PS AND CS , CALL ACENTR TO DO 3 SURF. ITERATION */
/* ...  SET DIR = VINDIR(IDS) (IF GIVEN)  OR TN(IDS) */
/* ...  EXAMINE DIR. ASSUME ITS COMPONENTS ARE DX,DY,DZ */
/* ...   (1) IF DX COMPONENT NOT ZERO (|DX| > .0001) */
/* ...       PLNV(ICS)=(DY,-DX,0) NORMALIZED */
/* ...       PLNV(IPS)=(DZ,0,-DX) NORMALIZED */
/* ...   (2) IF DX IS ZERO BUT DY IS NOT ZERO. */
/* ...       PLNV(ICS)=(DY,-DX,0) NORMALIZED */
/* ...       PLNV(IPS)=(0,DZ,-DY) NORMALIZED */
/* ...   (3) IF DX AND DY ARE BOTH ZERO. */
/* ...       PLNV(ICS)=(DZ,0,-DX) NORMALIZED */
/* ...       PLNV(IPS)=(0,DZ,-DY) NORMALIZED */
/* ...  AFTER THE PLANE VECTORS HAVE BEEN SETUP, THE D VALUES ARE */
/* ...  CALCULATED SO THE PLANES PASS THROUGH THE TEK LOCATION, AND THE */
/* ...  CANONICAL FORMS ARE STORED IN THE CANSTO ARRAY. SAVE AND RESET */
/* ...  FLAGS AND SWITCHES AND CALL ACENTR TO DO THREE SURF ITERATION. */
/* ... */
L2010:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iids - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L2030;
    } else {
	goto L2020;
    }
L2020:
    avsto_(&a2cmmn_1.vndir[a2cmmn_1.ids - 1], a2cmmn_1.dir);
    goto L2040;
/* ... */
L2030:
    avsto_(&a2cmmn_1.tn[a2cmmn_1.ids - 1], a2cmmn_1.dir);
L2040:
    if (abs(a2cmmn_1.dir[0]) - a2fpc_1.qp0001 <= 0.) {
	goto L2050;
    } else {
	goto L2080;
    }
L2050:
    if (abs(a2cmmn_1.dir[1]) - a2fpc_1.qp0001 <= 0.) {
	goto L2170;
    } else {
	goto L2130;
    }
L2080:
    a2cmmn_1.plnv[a2cmmn_1.ics - 1] = a2cmmn_1.dir[1];
    a2cmmn_1.plnv[a2cmmn_1.ics] = -a2cmmn_1.dir[0];
    a2cmmn_1.plnv[a2cmmn_1.ics + 1] = a2fpc_1.qnul;
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
    goto L2150;
/* ... */
L2100:
    a2cmmn_1.plnv[a2cmmn_1.ips - 1] = a2fpc_1.qnul;
    a2cmmn_1.plnv[a2cmmn_1.ips] = a2cmmn_1.dir[2];
    a2cmmn_1.plnv[a2cmmn_1.ips + 1] = -a2cmmn_1.dir[1];
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.plnv[a2cmmn_1.ips - 1]
	    , &a2cmmn_1.ier);
/* ... */
/* ... */
L2110:
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], a2cmmn_1.tek, &a2cmmn_1.plnd[
	    a2cmmn_1.ips - 1]);
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], a2cmmn_1.tek, &a2cmmn_1.plnd[
	    a2cmmn_1.ics - 1]);
/* L2120: */
    a2cmmn_1.ic = a2cmmn_1.ipontr[a2cmmn_1.iips - 1];
    for (ikk = 1; ikk <= 9; ++ikk) {
/* L2121: */
	pssav[ikk - 1] = a2cmmn_1.cansto[ikk - 1];
    }
    iunfls = a2cmmn_1.iunfl[a2cmmn_1.iips - 1];
    ipls = a2cmmn_1.ipl[a2cmmn_1.iips - 1];
    isftps = a2cmmn_1.isftyp[a2cmmn_1.iips - 1];
    itlons = a2cmmn_1.itlon[a2cmmn_1.iips - 1];
    j24s = a2cmmn_1.j24[a2cmmn_1.iips - 1];
    ipsfl = 1;
    astor_(&c__3, &c__4, &a2cmmn_1.cansto[a2cmmn_1.ic - 1], &c__8);
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.cansto[a2cmmn_1.ic + 3]
	    );
    a2cmmn_1.cansto[a2cmmn_1.ic + 6] = a2cmmn_1.plnd[a2cmmn_1.ips - 1];
    athsav = a2cmmn_1.th[a2cmmn_1.ips - 1];
    a2cmmn_1.th[a2cmmn_1.ips - 1] = 0.;
    a2cmmn_1.iunfl[a2cmmn_1.iips - 1] = 1;
    a2cmmn_1.ipl[a2cmmn_1.iips - 1] = 1;
    a2cmmn_1.isftyp[a2cmmn_1.iips - 1] = 3;
    a2cmmn_1.itlon[a2cmmn_1.iips - 1] = 0;
    a2cmmn_1.jent[a2cmmn_1.iips - 1] = 1;
    a2cmmn_1.jtn[a2cmmn_1.iips - 1] = 0;
    a2cmmn_1.iopset[a2cmmn_1.iips - 1] = 0;
    a2cmmn_1.ju1[a2cmmn_1.iips - 1] = 1;
    a2cmmn_1.jiops[a2cmmn_1.iips - 1] = 0;
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.tn[a2cmmn_1.ips - 1]);
    a2cmmn_1.past[a2cmmn_1.ips - 1] = a2fpc_1.q1p;
    a2cmmn_1.j24[a2cmmn_1.iips - 1] = 1;
    goto L3110;
/* ... */
/* ... */
L2130:
    a2cmmn_1.plnv[a2cmmn_1.ics - 1] = a2cmmn_1.dir[1];
    a2cmmn_1.plnv[a2cmmn_1.ics] = -a2cmmn_1.dir[0];
    a2cmmn_1.plnv[a2cmmn_1.ics + 1] = a2fpc_1.qnul;
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
    goto L2100;
/* ... */
L2150:
    a2cmmn_1.plnv[a2cmmn_1.ips - 1] = a2cmmn_1.dir[2];
    a2cmmn_1.plnv[a2cmmn_1.ips] = a2fpc_1.qnul;
    a2cmmn_1.plnv[a2cmmn_1.ips + 1] = -a2cmmn_1.dir[0];
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.plnv[a2cmmn_1.ips - 1]
	    , &a2cmmn_1.ier);
    goto L2110;
/* ... */
L2170:
    a2cmmn_1.plnv[a2cmmn_1.ics - 1] = a2cmmn_1.dir[2];
    a2cmmn_1.plnv[a2cmmn_1.ics] = a2fpc_1.qnul;
    a2cmmn_1.plnv[a2cmmn_1.ics + 1] = -a2cmmn_1.dir[0];
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
/* ... */
/* L2190: */
    a2cmmn_1.plnv[a2cmmn_1.ips - 1] = a2fpc_1.qnul;
    a2cmmn_1.plnv[a2cmmn_1.ips] = a2cmmn_1.dir[2];
    a2cmmn_1.plnv[a2cmmn_1.ips + 1] = -a2cmmn_1.dir[1];
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ips - 1], &a2cmmn_1.plnv[a2cmmn_1.ips - 1]
	    , &a2cmmn_1.ier);
    goto L2110;
/* ... */
/* ...                               *** TWO-SURFACE STARTUP *** */
/* ...     IF EITHER NO INDIR VECTORS OR TWO INDIR VECTORS GIVEN , SET */
/* ...     J50,J51=0 AND CALL ACENTR TO DO TWO-SURFACE ITERATION */
/* ...     IF ONLY ONE INDIR GIVEN, SET UP A PSEUDO CS AND TEST IT. IF IT */
/* ...     LOOKS GOOD, DO 3-SURF. ITERATION , IF IT DOES NOT LOOK GOOD, */
/* ...     DO TWO-SURFACE ITERATION. */
/* ...  THE THIRD SURFACE IN A TWO-SURF STARTUP IS SETUP AS FOLLOWS. */
/* ...      DIR = VINDIR(IS) */
/* ...      PLNV(ICS) = TN(IPS) X TN(IDS) */
/* ...      PLNV(ICS) = PLNV(ICS) X DIR   .... PLNV(ICS) IS NOW NORMAL */
/* ...          TO A PLANE WHICH CONTAINS THE TANGENT VECTOR TO THE PS */
/* ...          AND DS AND THE DIR VECTOR. */
/* ...  NORMALIZE PLNV(ICS). IF NORMALIZATION FAILURE OCCURS, GO DO THE */
/* ...  TWO-SURFACE ITERATION.  NOW, HAVING SETUP THIS PLANE, EXAMINE THE */
/* ...  PS AND DS. IF NEITHER IS A PLANE, IGNORE THE SPECIAL PLANE AND DO */
/* ...  A TWO-SURFACE ITERATION. IF EITHER OR BOTH ARE PLANES, EXAMINE */
/* ...  THE PLANE VECTOR AND THE PSEUDO PLANE VECTOR. IF THEIR DOT PRODUCT */
/* ...  IS LESS THAN .9999 (WHICH MEANS THAT THE TWO PLANES ARE NOT */
/* ...  PARALLEL) STORE THE THIRD PLANE AS THE CS AND DO THE THREE-SURF */
/* ...  ITERATION. THE D VALUE OF THE PLANE IS SETUP SO IT PASSES THROUGH */
/* ...  THE TEK LOCATION, WHICH IS THE CUTTER LOCATION BEFORE ANY OF THE */
/* ...  INTERIM INDIR MOVES. SET FLAGS FOR THE THIRD SURFACE AND GO DO */
/* ...  THREE SURFACE ITERATION. */
/* ... */
L3000:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iids - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L3030;
    } else {
	goto L3010;
    }
L3010:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iips - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L3050;
    } else {
	goto L3020;
    }
/* ... */
L3020:
    a2cmmn_1.j50[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.j51[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
/* ... */
    acentr_();
/* ... */
/* ...  JCR=0 INDICATES SUCCESSFUL ACENTR TWO-SURFACE ITERATION */
    if (a2cmmn_1.jcr != 0) {
	goto L3150;
    } else {
	goto L9999;
    }
/* ... */
L3030:
    if ((i__1 = a2cmmn_1.indir__[a2cmmn_1.iips - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L3020;
    } else {
	goto L3040;
    }
L3040:
    a2cmmn_1.is = a2cmmn_1.ips;
    a2cmmn_1.iis = a2cmmn_1.iips;
    goto L3060;
/* ... */
L3050:
    a2cmmn_1.is = a2cmmn_1.ids;
    a2cmmn_1.iis = a2cmmn_1.iids;
L3060:
    avsto_(&a2cmmn_1.vndir[a2cmmn_1.is - 1], a2cmmn_1.dir);
    avcros_(&a2cmmn_1.tn[a2cmmn_1.ips - 1], &a2cmmn_1.tn[a2cmmn_1.ids - 1], &
	    a2cmmn_1.plnv[a2cmmn_1.ics - 1]);
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L3020;
    } else {
	goto L3065;
    }
L3065:
    avcros_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], a2cmmn_1.dir, &a2cmmn_1.plnv[
	    a2cmmn_1.ics - 1]);
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
    if (a2cmmn_1.ier != 0) {
	goto L3020;
    } else {
	goto L3070;
    }
L3070:
    avcros_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], a2cmmn_1.dir, &a2cmmn_1.plnv[
	    a2cmmn_1.ics - 1]);
/* L3080: */
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.plnv[a2cmmn_1.ics - 1]
	    , &a2cmmn_1.ier);
/* L3090: */
    if (a2cmmn_1.ier != 0) {
	goto L3020;
    } else {
	goto L4100;
    }
L4100:
    if (a2cmmn_1.ipl[a2cmmn_1.iips - 1] != 0) {
	goto L4107;
    } else {
	goto L4105;
    }
L4105:
    if (a2cmmn_1.ipl[a2cmmn_1.iids - 1] != 0) {
	goto L4108;
    } else {
	goto L3020;
    }
L4107:
    a2cmmn_1.k = a2cmmn_1.ips;
    kk = a2cmmn_1.iips;
    goto L4109;
/* ... */
L4108:
    a2cmmn_1.k = a2cmmn_1.ids;
    kk = a2cmmn_1.iids;
L4109:
    a2cmmn_1.ic = a2cmmn_1.ipontr[kk - 1];
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.k - 1], &a2cmmn_1.cansto[a2cmmn_1.ic + 3], 
	    &ans);
    if (abs(ans) <= a2fpc_1.qp9999) {
	goto L3020;
    }
/* L3100: */
    avdot_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], a2cmmn_1.tek, &a2cmmn_1.plnd[
	    a2cmmn_1.ics - 1]);
L3110:
    a2cmmn_1.ic = a2cmmn_1.ipontr[a2cmmn_1.iics - 1];
    astor_(&c__3, &c__4, &a2cmmn_1.cansto[a2cmmn_1.ic - 1], &c__8);
    astor_(&c__6, &c__4, &a2cmmn_1.cansto[a2cmmn_1.ic], &c__8);
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.cansto[a2cmmn_1.ic + 3]
	    );
    a2cmmn_1.cansto[a2cmmn_1.ic + 6] = a2cmmn_1.plnd[a2cmmn_1.ics - 1];
    a2cmmn_1.j24[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.iunfl[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.ipl[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.jent[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.jtn[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.iopset[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.ju1[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.jiops[a2cmmn_1.iics - 1] = 0;
    avsto_(&a2cmmn_1.plnv[a2cmmn_1.ics - 1], &a2cmmn_1.tn[a2cmmn_1.ics - 1]);
    a2cmmn_1.past[a2cmmn_1.ics - 1] = a2fpc_1.q1p;
    a2cmmn_1.itlon[a2cmmn_1.iics - 1] = 0;
    a2cmmn_1.isftyp[a2cmmn_1.iics - 1] = 3;
    a2cmmn_1.iafl[a2cmmn_1.iics - 1] = -1;
/* ... */
/* .......................*** 3-SURF STARTUP ***............... */
L3120:
    a2cmmn_1.j50[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.j51[a2cmmn_1.iics - 1] = 1;
    a2cmmn_1.dp = a2fpc_1.qnul;
/* L3130: */
    a2cmmn_1.is = a2cmmn_1.ics;
    a2cmmn_1.iis = a2cmmn_1.iics;
    a2cmmn_1.icscnt = 1;
/* ... */
/* L3140: */
    acentr_();
/* ... */
/* ...  JCR=1 INDICATES SUCCESSFUL ACENTR THREE SURFACE ITERATION */
/* ... */
    if (a2cmmn_1.jcr - 1 != 0) {
	goto L3150;
    } else {
	goto L9999;
    }
/* ... */
/* ...  CENTR ITERATION FAILS TO CONVERGE FOR STARTUP           ** 602 ** */
L3150:
    aerr_(&c__602);
/* ... */
/* ... */
L9999:
    a2cmmn_1.icl = 5;
    astos_();
    atape_();
    a2cmmn_1.nw = 0;
L9998:
    if (ipsfl == 1) {
	goto L5030;
    }
/* ...  *************************************************  ASTRUPEX  **** */
/* ... */
/* ... */
    return 0;
/* ... */
L5000:
/*      LOOK AHEAD ON PROTAPE FOR NEXT GOXXX TO GIVE MEANING TO LEAD ANG */
/* ...  IF FINI IS ENCOUNTERED BEFORE GOXXX, ASSUME GORGT(IGO=2), */
/* ...  RE-POSITION PROTAP AND RETURN TO NORMAL FLOW. */
/* ...  (MAJOR 8000 = MOTION COMMANDS ....(1)GOLFT, (2)GORGT, (3)GOFWD, */
/* ...  (4)GOBACK, (5)GOUP, (6)GODWN) */
    inosav = a2cmmn_1.nrec + 1;
L5001:
    ataprd_(&ataptb_1.protap, &a2cmmn_1.ier, &a2cmmn_1.nwds, &c__4, &nrc1, &
	    c__1, &a2cmmn_1.instr1, &c__1, &a2cmmn_1.instr2, &c__1, 
	    a2cmmn_1.probuf, &c__0);
    if (a2cmmn_1.instr1 == 14000) {
	goto L5010;
    }
    if (a2cmmn_1.instr1 != 8000) {
	goto L5001;
    }
    a2cmmn_1.igo = a2cmmn_1.instr2;
    goto L5020;
L5010:
    a2cmmn_1.igo = 2;
/* ...                                                          ** -10 ** */
    aerr_(&c_n10);
/* ... */
/* ...  POSITION PROTAP TO (NREC + 1) BEFORE RETURNING TO NORMAL FLOW. */
L5020:
    aserch_(&ataptb_1.protap, &inosav, &a2cmmn_1.ier);
    goto L1000;
/* ... */
/* ... */
L5030:
    for (ikk = 1; ikk <= 9; ++ikk) {
/* L5031: */
	a2cmmn_1.cansto[ikk - 1] = pssav[ikk - 1];
    }
    a2cmmn_1.iunfl[a2cmmn_1.iips - 1] = iunfls;
    a2cmmn_1.ipl[a2cmmn_1.iips - 1] = ipls;
    a2cmmn_1.isftyp[a2cmmn_1.iips - 1] = isftps;
    a2cmmn_1.itlon[a2cmmn_1.iips - 1] = itlons;
    a2cmmn_1.j24[a2cmmn_1.iips - 1] = j24s;
    ipsfl = 0;
    a2cmmn_1.th[a2cmmn_1.ips - 1] = athsav;
    goto L9998;
/* ... */
/* ...  ILLEGAL PROTAP DATASET RECORD FOR STARTUP        *** 603 *** */
L9000:
    aerr_(&c__603);
    s_stop("", (ftnlen)0);
} /* astrup_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ab


