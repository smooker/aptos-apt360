/* ASEC2.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include <config.h>

/* Common Block Declarations */

struct {
    doublereal d1mod, f1mod, f1shot, d1shot, frate;
    integer ifmod;
} frd_;

#define frd_1 frd_

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
    integer k2flgs[10];
} s2flgs_;

#define s2flgs_1 s2flgs_

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

struct {
    doublereal adentc, adent, adummy, ans;
} a2burp_;

#define a2burp_1 a2burp_

/* Table of constant values */

static integer c__1 = 1;
static integer c_b4 = 111111;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__6 = 6;
static integer c__0 = 0;
static integer c__10 = 10;
static integer c__41 = 41;
static integer c__11 = 11;
static integer c__315 = 315;

/* Subroutine */ int asec2_()
{
    /* Initialized data */

    static struct {
	char e_1[16];
	real e_2;
	} equiv_16 = { {'A', 'S', 'E', 'C', '2', 'T', 'P', ' ', 'A', 'S', 'E',
		 'C', '2', '0', '1', ' '}, (float)0. };

#define ab ((real *)&equiv_16)

    static struct {
	char e_1[16];
	doublereal e_2;
	} equiv_17 = { {'(', 'I', 'D', 'U', ' ', ' ', ' ', ' ', 'M', 'M', 'Y',
		 ')', ' ', ' ', ' ', ' '}, 0. };

#define pdum ((doublereal *)&equiv_17)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
#define ipro ((integer *)&a2cmmn_ + 2616)
    static integer mxss;
    extern /* Subroutine */ int aerr_();
    static integer istx1, istx2;
    extern /* Subroutine */ int astuf_(), avsto_(), astor_(), avsub_(), 
	    asec2b_(), asec2d_(), asec2a_(), asec2c_(), a2ctrl_();
    static integer jjj;
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int adyndp_(), ataprd_(), atapwt_();
    static integer nrsave, junknw, junkmj, junkmi;
    extern /* Subroutine */ int aserch_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
L900:
    adyndp_(ab, &c__1, &c_b4);
/*      INITIALIZE VECTOR PACKAGE */

/*     MXSS IS MAXIMUM SURFACE STORAGE - SET TO 600 CELLS FOR CANON. FORM */
    mxss = 2000;
/*      SET CELL ADUMMY EQUAL TO BCD WORD IDUMMY  (USED TO DETECT IF NO */
/*     SURFACE DATA GIVEN IN INDIR OR SRFVCT STATEMENT */
/* ...    *** CHANGE REQUIRED FOR S/360  **** */
    a2burp_1.adummy = pdum[0];
    astuf_(&a2burp_1.adummy, &pdum[1]);
/*     ICRDCT IS NO OF CELLS TO STORE THE SEQUENCE FIELD */
    a2cmmn_.icrdct = 2;
/*     NUMSFS IS MAX. NO. OF SURFACES ALLOWED IF THIS NUMBER IS CHANGED, */
/*     THE DUMMY COMMON EXPANDING THE SURFACE VARIABLE BLOCKS SHOULD BE */
/*     INCREASED, ALLOWING 100 CELLS FOR EACH SURFA3E IN SURVAR AND 40 */
/*         PER SURFACE IN ISFVAR. */
    a2cmmn_.numsfs = 5;
/*     LSV AND LISV ARE THE BASIC LENGTHS OF THE TWO SURFACE BLOCKS */
    a2cmmn_.lsv = 100;
    a2cmmn_.lisv = 40;
    a2cmmn_.jam = 0;
    a2cmmn_.indir__[0] = 0;
    a2cmmn_.indir__[100] = 0;
    a2cmmn_.indir__[200] = 0;
    a2cmmn_.eps8[0] = a2cmmn_.eps1[0];
    a2cmmn_.eps8[100] = a2cmmn_.eps1[100];
    a2cmmn_.eps8[200] = a2cmmn_.eps1[200];
    a2cmmn_.eps8[300] = a2cmmn_.eps1[300];
    a2cmmn_.eps8[400] = a2cmmn_.eps1[400];
/*     ICSCNT IS THE NUMBER OF CHECK SURFACES CURRENTLY IN CORE */
    a2cmmn_.icscnt = 0;

/*     ICDEFL IS FLAG INDICATING WHETHER THE CUTTER HAS BEEN DEFINED */
/*     FIRST TIME IN THIS WILL BE INITIALIZED TO ZERO, BUT FOR ERROR RE- */
/*     START WE WISH TO SAVE THE STATUS */
    a2cmmn_.icdefs = a2cmmn_.icdefl;
    a2cmmn_.icdefl = 0;
/*     IGTFLG USED IN RESTART MODE TO SEE IF THERE IS A USABLE GO/COMAND. */
    a2cmmn_.igtflg = 0;
/*     JMINR TELLS THE MINIMUM DISTANCE ROUTINE TO RETURN RATHER THAN CAL */
/*     L AERR IF FAILURE ENCOUNTERED */
    a2cmmn_.jminr = 0;
    a2cmmn_.ifrl = 1;
/*     SEE IF ARE IN RESTART MODE IF SO, IPS WILL HAVE BEEN SET TO 1 */
    if (a2cmmn_.ips != 1) {
	goto L1;
    }
/*     MAY BE IN RESTART MODE, TEST IRSTRT */
    if (a2cmmn_.irstrt != 1) {
	goto L1;
    }
/*     YES, ARE IN RESTART, SET MODE FLAG ISRCH, RESET CUTTER DEF. STATUS */
/*     WIPE OUT NTH INTERSECTION COUNTERS AND GO READ MORE PROTAP */
    a2cmmn_.istrup = 0;
    a2cmmn_.isrch = 3;
    a2cmmn_.icdefl = a2cmmn_.icdefs;
    i__1 = a2cmmn_.numsfs;
    for (i__ = 3; i__ <= i__1; ++i__) {
	a2cmmn_.k = a2cmmn_.lisv * (i__ - 1) + 1;
/*     K SET TO INDEX THROUGH THE INTEGER SURFACE VARIABLE BLOCK */
/* L2: */
	a2cmmn_.ifar[a2cmmn_.k - 1] = 1;
    }
    goto L200;
/*     INITIALIZATION BRANCH */
L1:
    a2cmmn_.rc1 = a2fpc_1.q4500p;
/*     RADIUS OF CURVATURE OF PLANE */
    a2cmmn_.iautps = 0;
/*     NO AUTOPS/ */
    a2cmmn_.inops = 0;
/*     NO NOPS */
    a2cmmn_.ifl2 = 0;
/*     NO MULTI CS PROCESSING */
    a2cmmn_.mulout = 0;
/*     NO TOOL AXIS OUTPUT TO CLTAPE */
    a2cmmn_.icut = 0;
/*     NO DNTCUT/ */
    a2cmmn_.multax = 0;
    a2cmmn_.numax = 3;
    a2cmmn_.jap = 0;
/*                FIXED AXIS */
    a2cmmn_.il = 0;
    frd_1.ifmod = 0;
/*            CLPRINT CONDITION CODE */
    a2cmmn_.i3 = 0;
/*              DEBUG OPTION INDICATOR */
    a2cmmn_.ivamax = 2;
/*        SET DUMP OPTION FOR ERROR IGOUG = 0 */
/*     NO GOUGE CHECK DESIRED IOFSET = 0 */
/*     NOT STARTUP (WILL BE RESET LATER WHEN GET STARTUP) I3DFLG = 2 */
/*     2DCALC OR 3DCALC HAS NOT BEEN GIVEN, DETERMINE FROM THE DATA WHETH */
/*     ER 2-D ROUTE CAN BE USED ITRFLG = 0 */
/*     NOT TRANTO MODE ADENTC = QNUL */
/*     BCD NAME OF TRANTO ID */
    a2cmmn_.numpts = 400;
/*     MAX NO OF POINTS PER ELEMENTARY CUT SEQUENCE. */
/*     Pmove=0; */
    avsto_(a2cmmn_.vnul, a2cmmn_.pmove);
/*     ZERO OUT LAST MOVE NOT ALONG TOOL AXIS (SENSE OF DIREC) */
/* 	TA=0,TAK=0 (vectors) */
    avsto_(a2cmmn_.ez, a2cmmn_.ta);
    avsto_(a2cmmn_.ez, a2cmmn_.tak);
/*     ALSO TOOL AXIS AT START OF CUT */
    a2cmmn_.dpmax = a2fpc_1.q10p;
    a2cmmn_.jtused = 16;
/*     MAXIMUM ALLOWABLE MOVE EXCEPT WHEN PS+DS PLANES */
/*     SET UP INDEXES FOR THE SURACE VARIABLE BLOCKS */
/*     IXX FOR FLOATING POINT VARIABLES */
/*     IIXX FOR INTEGERS */
    a2cmmn_.ips = 1;
    a2cmmn_.iips = 1;
    a2cmmn_.ids = a2cmmn_.lsv + 1;
    a2cmmn_.iids = a2cmmn_.lisv + 1;
    a2cmmn_.ics = (a2cmmn_.lsv << 1) + 1;
    a2cmmn_.iics = (a2cmmn_.lisv << 1) + 1;
    a2cmmn_.igs = a2cmmn_.numsfs * a2cmmn_.lsv + 1;
    a2cmmn_.iigs = a2cmmn_.numsfs * a2cmmn_.lisv + 1;
/*     NOW SET UP TOLERANCES FOR ALL SURFACES */
    i__1 = a2cmmn_.numsfs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a2cmmn_.k = a2cmmn_.lsv * (i__ - 1) + 1;
	a2cmmn_.l = a2cmmn_.lisv * (i__ - 1) + 1;
/*     K TO INDEX FLOATING SURFACE VARIABLES, L TO INDEX INTEGERS */
	a2cmmn_.tau1[a2cmmn_.k - 1] = a2fpc_1.qp0005;
	a2cmmn_.tau2[a2cmmn_.k - 1] = a2fpc_1.qnul;
	a2cmmn_.tau[a2cmmn_.k - 1] = a2fpc_1.qp0005;
	a2cmmn_.eps1[a2cmmn_.k - 1] = a2fpc_1.qp4x05;
	a2cmmn_.eps2[a2cmmn_.k - 1] = a2fpc_1.qp4x95;
	a2cmmn_.eps3[a2cmmn_.k - 1] = a2fpc_1.q4x045;
	a2cmmn_.eps4[a2cmmn_.k - 1] = a2fpc_1.qp001;
	a2cmmn_.eps6[a2cmmn_.k - 1] = a2fpc_1.qp5x01;
	a2cmmn_.eps8[a2cmmn_.k - 1] = a2fpc_1.qp4x05;
/*     NO THICKNESS FOR ANY SURFACE */
	a2cmmn_.th[a2cmmn_.k - 1] = a2fpc_1.qnul;
/*     GO TO 1ST INTERSECTION OF CS */
	a2cmmn_.ifar[a2cmmn_.l - 1] = 1;
	a2cmmn_.lofs[a2cmmn_.l - 1] = 8;
	a2cmmn_.jtlflg[a2cmmn_.l - 1] = 0;
/*     ASSUME CANONICAL FORM IS 8 CELLS LONG */
/*     SET IPONTR(L) TO FIRST CELL OF CANONICAL FORM OF EACH SURFACE */
/* L3: */
	a2cmmn_.ipontr[a2cmmn_.l - 1] = (i__ - 1 << 3) + 1;
    }
/*     SET UP PART SURFACE AS XY PLANE, STORE CANONICAL FORM IN CANSTO */
/*     CELL1      SURFACE TYPE 3 FOR PLANE */
/*     CELL 2     6 WORDS TO FOLLOW */
/*     CELL 3     BCD NAME */
/*     CELL 4     SUBSCRIPT */
/*     CELL 5     X COMPONENT 0 */
/*     CELL 6     Y COMPONENT 0 */
/*     CELL 7     Z COMPONENT 1 */
/*     CELL 8     D VALUE     0 */
/* 	plane.... */
    astor_(&c__3, &c__4, a2cmmn_.cansto, &c__8);
/* 	6words to follow.... */
    astor_(&c__6, &c__4, &a2cmmn_.cansto[1], &c__8);
    astor_("XYPLAN      ", &c__8, &a2cmmn_.cansto[2], &c__8);
/* 	zero out canon values except for z component =1 */
    a2cmmn_.cansto[3] = a2fpc_1.qnul;
    a2cmmn_.cansto[4] = a2fpc_1.qnul;
    a2cmmn_.cansto[5] = a2fpc_1.qnul;
    a2cmmn_.cansto[6] = a2fpc_1.q1p;
    a2cmmn_.cansto[7] = a2fpc_1.qnul;
    a2cmmn_.j24[a2cmmn_.iips - 1] = 1;
/*     NOW MAKE FURTHER ASSUMPTIONS INITIALLY */
    a2cmmn_.isftyp[a2cmmn_.iips - 1] = 1;
    a2cmmn_.isftyp[a2cmmn_.iids - 1] = 1;
/*     ISFTYP =1,---(TO) FOR ALL SURFACES */
/*     NO SURFACE VECTORS GIVEN */
    a2cmmn_.isvfl[a2cmmn_.iips - 1] = 0;
    a2cmmn_.isvfl[a2cmmn_.iids - 1] = 0;
    a2cmmn_.isvfl[a2cmmn_.iics - 1] = 0;
/*     NO INDIR GIVEN */
    a2cmmn_.indir__[a2cmmn_.iips - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iids - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iics - 1] = 0;
/*     TOOL NOT ON ANY SURFACE */
    a2cmmn_.itlon[a2cmmn_.iips - 1] = 1;
    a2cmmn_.itlon[a2cmmn_.iids - 1] = 1;
/*     UNIT NORMAL CAN BE CALCULATED FROM OFF SURFACE POINT FOR PS */
    a2cmmn_.iunfl[a2cmmn_.iips - 1] = 1;
/*     ASSUME TOOL NORMAL FOR PS IS STRAIGHT DOWN (INITIAL GUESS) */
    avsub_(a2cmmn_.vnul, a2cmmn_.ez, &a2cmmn_.tn[a2cmmn_.ips - 1]);
/*     ASSUM TOOL NORMAL FOR CS IS ALONG X AXIS */
    avsto_(a2cmmn_.ex, &a2cmmn_.tn[a2cmmn_.ids - 1]);
/*     ASSUME NOT PAST PS */
    a2cmmn_.past[a2cmmn_.ips - 1] = a2fpc_1.q1p;
/*     PS IS PLANE */
    a2cmmn_.ipl[a2cmmn_.iips - 1] = 1;
/*     SET NORMAL MODE FLAG */
    a2cmmn_.isrch = 1;
    a2cmmn_.limfl[a2cmmn_.iips - 1] = 0;


/*     READ PROTAP(--FIRST 3 INTEGERS TO NREC, INSTR1, INSTR2. REST TO TH */
/*     E PROTAP BUFFER AREA PROBUF (100 CELLS LONG) */
L200:
    ataprd_(&ataptb_1.protap, &a2cmmn_.ier, &a2cmmn_.nwds, &c__4, &
	    a2cmmn_.nrec, &c__1, &a2cmmn_.instr1, &c__1, &a2cmmn_.instr2, &
	    c__1, a2cmmn_.probuf, &c__0);
    adyndp_(&ab[2], &c__1, &c_b4);

    if (a2cmmn_.ier >= 0) {
	aerr_(&c__10);
    }
/* ...6000,7(TRANTO/ID) OR 8(MULTI-CS)...GO TO ASEC2B AND MAKE */
/*   AN ENTRY IN TABID IF FWD TRANSFER. */
    if (a2cmmn_.instr1 != 6000) {
	goto L60;
    }
    if (a2cmmn_.instr2 == 7 || a2cmmn_.instr2 == 8) {
	goto L50;
    }
    goto L60;
L50:
    istx1 = 6078;
    asec2b_(&istx1, &istx2);
L60:
/* ... */
/*     SET UP INS1 FOR BRANCHING */
    a2cmmn_.ins1 = a2cmmn_.instr1 / 1000;
    if (a2cmmn_.ins1 < 1 || a2cmmn_.ins1 > 14) {
	goto L215;
    }
    if (a2cmmn_.ins1 == 14) {
	goto L14000;
    }
/*     BRANCH ON MODE FLAG ISRCH=1 NORMAL MODE */
/*     BRANCH ON MODE FLAG ISRCH=2 TRANTO */
/*     BRANCH ON MODE FLAG ISRCH=3 RESTART (ERROR ENCOUNTERED) */
    if (a2cmmn_.isrch == 1) {
	goto L10;
    }
    if (a2cmmn_.isrch == 2) {
	goto L20;
    }
    if (a2cmmn_.isrch == 3) {
	goto L30;
    }
/*     NORMAL MODE BRANCH ON RECORD TYPE */
L10:
    switch ((int)a2cmmn_.ins1) {
	case 1:  goto L1000;
	case 2:  goto L2000;
	case 3:  goto L3000;
	case 4:  goto L4000;
	case 5:  goto L5000;
	case 6:  goto L6000;
	case 7:  goto L7000;
	case 8:  goto L8000;
	case 9:  goto L9000;
	case 10:  goto L10000;
	case 11:  goto L11000;
	case 12:  goto L12000;
	case 13:  goto L13000;
	case 14:  goto L14000;
    }
L215:
    aerr_(&c__41);
/*     TRANTO BRANCH */
/*     IS THIS A 1000 TYPE CODE */
L20:
    if (a2cmmn_.ins1 != 1) {
	goto L200;
    }
/*     IS A 1000 TYPE -- PUT BCD ID INTO ADENT */
    a2burp_1.adent = a2cmmn_.probuf[0];
/*     SEE IF THIS IS THE ONE WE ARE LOOKING FOR */
    if (a2burp_1.adent == a2burp_1.adentc) {
	a2cmmn_.isrch = 1;
    }
    goto L1000;
/*     RESTART BRANCH */
L30:
    switch ((int)a2cmmn_.ins1) {
	case 1:  goto L1000;
	case 2:  goto L2000;
	case 3:  goto L3000;
	case 4:  goto L4000;
	case 5:  goto L5300;
	case 6:  goto L6300;
	case 7:  goto L7300;
	case 8:  goto L8300;
	case 9:  goto L9000;
	case 10:  goto L10000;
	case 11:  goto L11300;
	case 12:  goto L12000;
	case 13:  goto L13000;
	case 14:  goto L14000;
    }
L3000:
    istx1 = a0con_1.k1;
    asec2d_(&istx1, &istx2, &mxss);
L400:
    if (istx2 == a0con_1.k1) {
	goto L200;
    }
    goto L2000;
L5300:
    istx1 = a0con_1.k2;
L5900:
    asec2a_(&istx1, &istx2);
    goto L400;
L5000:
    istx1 = a0con_1.k1;
    goto L5900;
L6000:
    istx1 = a0con_1.k1;
L6900:
    asec2b_(&istx1, &istx2);
    goto L400;
L6300:
    istx1 = a0con_1.k2;
    goto L6900;
L8300:
    istx1 = a0con_1.k3;
    goto L6900;
L8000:
    istx1 = a0con_1.k4;
    goto L6900;
L7000:
    istx1 = a0con_1.k1;
L7900:
    asec2c_(&istx1, &istx2);
    goto L400;
L7300:
    istx1 = a0con_1.k2;
    goto L7900;
L9000:
    istx1 = a0con_1.k3;
    goto L7900;
L4000:
    istx1 = a0con_1.k4;
    goto L7900;
L10000:
    istx1 = a0con_1.k5;
    goto L7900;
L11000:
    istx1 = a0con_1.k6;
    goto L7900;
L11300:
    istx1 = a0con_1.k7;
    goto L7900;
L12000:
    istx1 = a0con_1.k8;
    goto L7900;
L13000:
    if (a2cmmn_.instr2 == 1) {
	goto L13100;
    }
    if (a2cmmn_.instr2 == 2) {
	goto L13200;
    }
    if (a2cmmn_.instr2 == 5) {
	goto L13500;
    }
    if (a2cmmn_.instr2 != 4) {
	goto L200;
    }
/* ...      STORE CURRENT CLTAPE PRINT CONDITION (ON/OFF) */
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.il, &c__4);
/* ...       PASS ON RECORD TO CLTAPE */
    goto L2000;
L13100:
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.i3, &c__4);
/* ...     SET DEBUG FLAG */
    goto L200;
L13200:
    asistm_1.iwaven = 2;
/* ...      RESTART IN SECTION 2 CAUSED BY SECTION ONE ERROR HERE */
    a2cmmn_.irstrt = 1;
/* ...   OUTPUT WARNING MESSAGE ABOUT RESTART--DO NOT ALLOW ANY DUMP */
/* *****JJJ = IVAMAX */
/* *****IVAMAX = 1 */
/* *****CALL AERR(-1) */
/* *****IVAMAX = JJJ */
    goto L900;
/* ...      SWITCH TO DAC ARELEM */
L13500:
//    if (ipro[OTHER_ENDIAN_S(1)] != 1) {
    if (ipro[1] != 1) {
	goto L200;
    }
    if (asistm_1.iwaven == 0) {
	goto L13504;
    }
    asistm_1.kflags[3] = 1;
    asistm_1.kflags[4] = 0;
L13504:
    s2flgs_1.k2flgs[0] = 1;
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    a2cmmn_.instr1, &c__1, &a2cmmn_.instr2, &c__1, a2cmmn_.probuf, 
	    &a2cmmn_.nwds);
    if (a2cmmn_.ier >= 0) {
	aerr_(&c__11);
    }

    a2ctrl_();
L14000:
    istx1 = a0con_1.k9;
    goto L7900;


/*     TYPE 1000, RECORD ID */
/*     SAVE ID OF CARD */
L1000:
    a2burp_1.adent = a2cmmn_.probuf[0];
    a2cmmn_.knd = a2cmmn_.instr2;
/*     SAVE SEQUENCE */
    for (i__ = 1; i__ <= 2; ++i__) {
/* L1001: */
	a2cmmn_.acard[i__ - 1] = a2cmmn_.probuf[i__];
    }
/*     INCREMENT CLTAPE RECORD NO + OUT PUT RECORD */
    if (a2cmmn_.isrch != 2) {
	goto L99999;
    }
    if (a2burp_1.adent != a2burp_1.adentc) {
	goto L1002;
    }
    a2cmmn_.isrch = 1;
    goto L99999;
L1002:
    if (a2cmmn_.itrflg <= 0) {
	goto L200;
    }
    aerr_(&c__315);


/*     POST PROCESSOR PARAMETERS - PAS ON */
L2000:
    if (a2cmmn_.instr2 == 1009) {
	goto L2001;
    }
L2002:
    if (a2cmmn_.ins1 != 3) {
	goto L99999;
    }
    nrsave = a2cmmn_.nrec + 1;
L99997:
    ataprd_(&ataptb_1.protap, &a2cmmn_.ier, &junknw, &c__3, &a2cmmn_.nrec, &
	    c__1, &junkmj, &c__1, &junkmi, &c__1);
    if (a2cmmn_.ier >= 0) {
	aerr_(&c__10);
    }
    if (junkmj == 14000) {
	goto L99998;
    }
    if (junkmj == 7000 || junkmj == 8000) {
	goto L99998;
    }
    goto L99997;
L99998:
    aserch_(&ataptb_1.protap, &nrsave, &a2cmmn_.ier);
    if (junkmj == 8000) {
	goto L99999;
    }
    goto L200;
L99999:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    a2cmmn_.instr1, &c__1, &a2cmmn_.instr2, &c__1, a2cmmn_.probuf, 
	    &a2cmmn_.nwds, &a2fpc_1.qnul, &c__1, &a2fpc_1.qnul, &c__1);
    if (a2cmmn_.ier >= 0) {
	aerr_(&c__11);
    }
    goto L200;
L2001:
    if (a2cmmn_.nwds == 1) {
	goto L2003;
    }
    i__1 = a2cmmn_.nwds;
    for (jjj = 1; jjj <= i__1; ++jjj) {
//	if (ipro[OTHER_ENDIAN_S((jjj << 1) - 2)] == 0) {
	if (ipro[(jjj << 1) - 2] == 0) {
	    goto L2007;
	}
/* L2006: */
    }
    if (a2cmmn_.nwds == 2) {
	goto L2005;
    }
    if (a2cmmn_.nwds != 3) {
	goto L2002;
    }
    frd_1.frate = a2cmmn_.probuf[0];
    frd_1.d1mod = a2cmmn_.probuf[1];
    frd_1.f1mod = a2cmmn_.probuf[2];
    a2cmmn_.nwds = 1;
    frd_1.ifmod = 1;
    goto L2002;
L2003:
    frd_1.frate = a2cmmn_.probuf[0];
L2007:
    frd_1.ifmod = 0;
    goto L2002;
L2005:
    frd_1.f1shot = a2cmmn_.probuf[1];
    frd_1.d1shot = a2cmmn_.probuf[0];
    if (frd_1.ifmod == 1) {
	frd_1.ifmod = 2;
    }
    if (frd_1.ifmod == 0) {
	frd_1.ifmod = -1;
    }
    goto L200;
} /* asec2_ */

#undef tlldat
#undef ipro
#undef cosl
#undef sinl
#undef pdum
#undef ab


