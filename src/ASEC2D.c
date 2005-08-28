/* ASEC2D.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal adentc, adent, adummy, ans;
} a2burp_;

#define a2burp_1 a2burp_

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
static integer c__4 = 4;
static integer c__1401 = 1401;
static integer c__302 = 302;
static integer c__3 = 3;
static integer c__303 = 303;
static integer c__12 = 12;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__13 = 13;

/* Subroutine */ int asec2d_(istx1, istx2, mxss)
integer *istx1, *istx2, *mxss;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, ii;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    static integer idq;
    extern /* Subroutine */ int aerr_(), astor_();
    static integer loccan;
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    static doublereal tantoc[2];
    static integer istype;
    extern /* Subroutine */ int abkkpr_(), aserch_(), ataprd_(), aptlft_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     ***** */
/*     ***** */
    if (*istx1 > a0con_1.k1) {
	goto L200;
    }

/*     SURFACE CANONICAL FORM */
/* L3000: */
    switch ((int)a2cmmn_.instr2) {
	case 1:  goto L3010;
	case 2:  goto L3020;
	case 3:  goto L3030;
	case 4:  goto L3010;
    }
/*     I31 = 1,2,3,4...N FOR PS,DS,CS,CS1,CS2...CSN. */
/*     IT = IPS,IDS,ICS,ETC */
/*     IIT = IIPS,IIDS,IICS,ECT */
L3010:
    a2cmmn_.i31 = 1;
    a2cmmn_.it = a2cmmn_.ips;
    a2cmmn_.iit = a2cmmn_.iips;
/*     TURN OFF AUTOPS AND NOPS FLAGS */
    a2cmmn_.iautps = 0;
    a2cmmn_.inops = 0;
    goto L3025;
/*     C DRIVE SURFACE */
L3020:
    a2cmmn_.i31 = 2;
    a2cmmn_.it = a2cmmn_.ids;
    a2cmmn_.iit = a2cmmn_.iids;
/*     SET UP BCD NAME + SUBSCRIPT */
    a2cmmn_.abcd[0] = a2cmmn_.probuf[3];
    a2cmmn_.abcd[1] = a2cmmn_.probuf[4];
    if (a2cmmn_.abcd[0] == tantoc[0] && a2cmmn_.abcd[1] == tantoc[1]) {
	a2cmmn_.jcnt3 = 30;
    }
    goto L3025;
L3030:
/*      INCREASE CHECK SURFACE COUNT */
    ++a2cmmn_.icscnt;
    a2cmmn_.i31 = a2cmmn_.icscnt + 2;
    a2cmmn_.it = a2cmmn_.ics + (a2cmmn_.icscnt - 1) * a2cmmn_.lsv;
    a2cmmn_.iit = a2cmmn_.iics + (a2cmmn_.icscnt - 1) * a2cmmn_.lisv;
/*      SET IFL4 FLAG FOR PS OR DS TANGENCY */
/*      SET TOOL ON CONDITION APPROPRIATELY */
/* ...    *** IDQ MUST BE 2 BYTE ON S/360  **** */
    astor_(a2cmmn_.probuf, &c__8, &idq, &c__2);
    if (idq == 4) {
	goto L3031;
    }
    if (idq == 8) {
	goto L3036;
    }
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.isftyp[a2cmmn_.iit - 1], &c__2);
/*     NOT TANGENCY CASE */
    goto L3025;
/*      TANTO */
L3031:
    a2cmmn_.ifl4[a2cmmn_.iit - 1] = 0;
    a2cmmn_.itlon[a2cmmn_.iit - 1] = 0;
    if (a2cmmn_.isftyp[a2cmmn_.iids - 1] != 3) {
	a2cmmn_.itlon[a2cmmn_.iit - 1] = 1;
    }
    tantoc[0] = a2cmmn_.probuf[3];
    tantoc[1] = a2cmmn_.probuf[4];
    goto L3025;
/*      PST AN */
L3036:
    a2cmmn_.ifl4[a2cmmn_.iit - 1] = 1;
    astor_(&c__4, &c__4, a2cmmn_.probuf, &c__8);
    a2cmmn_.itlon[a2cmmn_.iit - 1] = 0;
    if (a2cmmn_.isftyp[a2cmmn_.iips - 1] != 3) {
	a2cmmn_.itlon[a2cmmn_.iit - 1] = 1;
    }
    goto L3025;

/*     EXAMINE SURFACE USE INDICATOR AND SET PAST = -1. IF PAST SPECIFIED */
L3025:
    a2cmmn_.past[a2cmmn_.it - 1] = a2fpc_1.q1p;
    astor_(a2cmmn_.probuf, &c__8, &idq, &c__2);
    if (idq == 2) {
	a2cmmn_.past[a2cmmn_.it - 1] = -a2fpc_1.q1p;
    }
/* ...IF ON,DS   CTOCL=0         -1,TLLFT       +1,TLRGT */
    if (a2cmmn_.i31 == 2 && idq == 3) {
	a2cmmn_.ctocl = a2fpc_1.qnul;
    }
/*     SET ISTYPE TO THE TYPE OF SURFACE---PLANE,SPHERE,ETC */
/* ...    *** ISTYPE MUST BE 2 BYTE ON S/360  **** */
    astor_(&a2cmmn_.probuf[1], &c__8, &istype, &c__2);
/*     CHECK FOR VALID SURFACE TYPE AND SET J = NO OF WORDS REQUIRED TO S */
/*     TORE CANONICAL FORM FOR SMALL SURFACES, J=WORD COUNTER FROM PROTAP */
/*     (3RD ELEMENT IN PROBUF) +2. FOR LARGE SURFACES, J= PROBUF(7)+4 */

    if (istype > 1) {
	goto L3040;
    }
/*     ERROR */
L3039:
    aerr_(&c__1401);
L3040:
    if (istype > 10) {
	goto L3050;
    }
/*     LESS THAN 10-SMALL SURFACE */
    ii = 9;
L3045:
    switch ((int)istype) {
	case 1:  goto L30459;
	case 2:  goto L30451;
	case 3:  goto L30451;
	case 4:  goto L30452;
	case 5:  goto L30452;
	case 6:  goto L30453;
	case 7:  goto L30453;
	case 8:  goto L30454;
	case 9:  goto L30453;
	case 10:  goto L30453;
	case 11:  goto L30459;
	case 12:  goto L30459;
	case 13:  goto L30455;
	case 14:  goto L30453;
	case 15:  goto L30456;
    }
L30451:
    ii = 1;
    goto L30459;
L30452:
    ii = 2;
    goto L30459;
L30453:
    ii = 3;
    goto L30459;
L30454:
    ii = 4;
    goto L30459;
L30455:
    ii = 5;
    goto L30459;
L30456:
    ii = 6;
/* *******************************************************************W.L. */
/* *******************************************************************W.L. */
L30459:
    a2cmmn_.j24[a2cmmn_.iit - 1] = ii;
/* L3047: */
    astor_(&a2cmmn_.probuf[2], &c__8, &a2cmmn_.incfs, &c__2);
/*     INCFS IS 2 LESS THAN REQUIRED LENGTH OF CANONICAL FORM */
    a2cmmn_.j = a2cmmn_.incfs + 2;
    if (istype == 15) {
	a2cmmn_.j += 49;
    }
    goto L3060;
/*     NOT LESS THAN 10 TEST FOR SPHERE AND QUADRIC */
L3050:
    if (istype == 13) {
	goto L3045;
    }
/*     SPHERE = 13 */
/*     QUADRIC = 14 */
    if (istype == 14) {
	goto L3045;
    }
    if (istype == 15) {
	goto L3045;
    }
/* *******************************************************************W.L. */
/*     LOFT=16 */
    if (istype == 16) {
	goto L3700;
    }
/*      POLCON */
/*     MUST BE LARGE SURFACE OR ERROR */
/*     TEST FOR TABCYL (ONLY LARGE SURFACE ALLOWED CURRENTLY) */
    if (istype == 50) {
	goto L3046;
    }
    if (istype == 53) {
	goto L3046;
    }
/* *******************************************************************W.L. */
/*     ERROR */
    goto L3039;
L3046:
    astor_(&a2cmmn_.probuf[6], &c__8, &a2cmmn_.incfs, &c__2);
/*     ADD 4 TO GET TYPE, WORDS TO FOLLOW, NAME AND SUBSCRIPT */
    a2cmmn_.j = a2cmmn_.incfs + 5;
    if (istype == 50) {
	a2cmmn_.j24[a2cmmn_.iit - 1] = 7;
    }
    if (istype == 53) {
	a2cmmn_.j24[a2cmmn_.iit - 1] = 8;
    }
/* *******************************************************************W.L. */


L3060:
/*     COMPUTE JA=INCREMENTAL NO OF LOCATIONS TO STORE THIS CANONICAL */
/*     FORM  ALL SURFACE LENGTHS ASSUME D = 8 INITIALLY */
    a2cmmn_.ja = a2cmmn_.j - a2cmmn_.lofs[a2cmmn_.iit - 1];
/*     FOR PART AND DRIVE SURFACES, IF JA=0 WE MAY STORE CANONICAL FORM */
/*     WITHOUT FURTHER TESTS */
    if (a2cmmn_.ja == 0 && a2cmmn_.i31 <= 2) {
	goto L3500;
    }
/*     SEE IF WE HAVE EXCEEDED ALLOWED NUMBER OF SURFACES */
    if (a2cmmn_.i31 > a2cmmn_.numsfs) {
	aerr_(&c__302);
    }
/*     IF STORING CS, DONT WORRY ABOUT STORAGE */
    if (a2cmmn_.i31 >= 3) {
	goto L3500;
    }
/*     WORKING WITH PS OR DS */
    switch ((int)a2cmmn_.i31) {
	case 1:  goto L3061;
	case 2:  goto L3062;
    }
/*     PART SURFACE, SEE WHICH WAY TO MOVE SURFACES FIRST */
L3061:
    if (a2cmmn_.ja > 0) {
	goto L3070;
    }
/*     LESS SPACE REQUIRED FOR PRESENT PS - RELOCATE DS UP + RESET IPONTR */
    abkkpr_(&c__2, &a2cmmn_.ja);
/*     NOW RELOCATE DS - PS AND DS BRANCH USE THIS CALL -SIGN OF JA SELEC */
L3062:
    abkkpr_(&c__3, &a2cmmn_.ja);
    goto L3500;
L3070:
/*     PS REQUIRES MORE SPACE THAN PREV. RELOCATE CS FIRST */
    abkkpr_(&c__3, &a2cmmn_.ja);
    abkkpr_(&c__2, &a2cmmn_.ja);


/*     JUST ABOUT READY TO STORE SURFACE---SEE IF THERE IS ENOUGH ROOM */
/*     MXSS (=600) IS MAX NO OF CELLS FOR SURFACE STORAGE */
/*     JTUSED = CELLS WHICH WOULD BE USED AFTER STORAGE OF PRESENT SURF. */
/*     ZERO OUT JTUSED AND SET LDS(IIT) TO LENGTH OF SURFACE */
L3500:
    a2cmmn_.jtused = 0;
    a2cmmn_.lofs[a2cmmn_.iit - 1] = a2cmmn_.j;
/*     FOR PS OR DS, CHECK LENGTH ONLY OF PS AND DS FOR CS, CHECK ALL */
    if (a2cmmn_.i31 > 2) {
	goto L3501;
    }
/*     PS OR DS */
    a2cmmn_.jtused = a2cmmn_.lofs[a2cmmn_.iips - 1] + a2cmmn_.lofs[
	    a2cmmn_.iids - 1];
    goto L3502;
/*     CS */
L3501:
    i__1 = a2cmmn_.i31;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a2cmmn_.k = (i__ - 1) * 40;
	a2cmmn_.ipontr[a2cmmn_.k] = a2cmmn_.jtused + 1;
/* L3503: */
	a2cmmn_.jtused += a2cmmn_.lofs[a2cmmn_.k];
    }
/*     TEST FOR OVERFLOW */
L3502:
    if (a2cmmn_.jtused > *mxss) {
	aerr_(&c__303);
    }
/*     SPACE OK-SET UP LOCCAN AS POINTER TO FIRST CELL IN BLOCK FOR THE */
/*     CURRENT CANONICAL FORM */
    loccan = a2cmmn_.ipontr[a2cmmn_.iit - 1];
/*     TEST FOR LARGE SURFACE */
    if (istype > 49) {
	goto L3505;
    }
/*     SMALL SURFACE */
    i__1 = a2cmmn_.j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a2cmmn_.cansto[loccan - 1] = a2cmmn_.probuf[i__];
/* L3504: */
	++loccan;
    }
    goto L3600;
/*     LARGE SURFACE */
L3505:
    a2cmmn_.cansto[loccan - 1] = a2cmmn_.probuf[1];
/* L3506: */
    loccan += 2;
/*     GET RECORD NO FOR SURF TAPE */
    astor_(&a2cmmn_.probuf[5], &c__8, &a2cmmn_.irecno, &c__4);
    aserch_(&ataptb_1.srftap, &a2cmmn_.irecno, &a2cmmn_.ier);
    if (a2cmmn_.ier >= 0) {
	aerr_(&c__12);
    }
    ataprd_(&ataptb_1.srftap, &a2cmmn_.ier, &a2cmmn_.nwds, &c__4, &
	    a2cmmn_.irecno, &c__1, &a2cmmn_.irecno, &c__1, &a2cmmn_.irecno,
	     &c__1, &a2cmmn_.cansto[loccan - 1], &c__0);
    if (a2cmmn_.ier >= 0) {
	aerr_(&c__13);
    }
    astor_(&a2cmmn_.nwds, &c__4, &a2cmmn_.cansto[loccan - 2], &c__8);

/*     SET FLAGS + SWITCHES - ZERO OUT PLANE AND UN FLAGS */
L3600:
    a2cmmn_.ipl[a2cmmn_.iit - 1] = 0;
    a2cmmn_.iunfl[a2cmmn_.iit - 1] = 0;
    a2cmmn_.limfl[a2cmmn_.iit - 1] = 0;
    if (istype < 6 || istype == 13) {
	a2cmmn_.iunfl[a2cmmn_.iit - 1] = 1;
    }
    if (istype == 3 || istype == 2) {
	a2cmmn_.ipl[a2cmmn_.iit - 1] = 1;
    }
    if (idq != 0) {
	a2cmmn_.isftyp[a2cmmn_.iit - 1] = idq;
    }
    goto L200;
/*     LOFT */
L3700:
    aptlft_();
L200:
    *istx2 = a0con_1.k1;
    if (istype == 4 || istype == 5) {
	*istx2 = 2;
    }
    if (a2cmmn_.instr2 != 2) {
	*istx2 = 1;
    }
    return 0;
} /* asec2d_ */

#undef tlldat
#undef cosl
#undef sinl


