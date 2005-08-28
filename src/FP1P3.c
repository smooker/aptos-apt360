/* FP1P3.f -- translated by f2c (version 20000121).
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
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

struct {
    doublereal amati1[16]	/* was [4][4] */, amati2[16]	/* was [4][4] 
	    */, amati3[16]	/* was [4][4] */, amatrx[12]	/* was [3][4] 
	    */, amtr[36], an1, an2, aname, ax, ax0, axvec[3], ay, ay0, cntm[
	    36], cntmat[12]	/* was [3][4] */, cont[3], count[3], cseqno[1]
	    , delx, dely, dx, dy, f0, origin[3], parray[20], partno[12], pnt[
	    3], pprint[12], ppt[6], pt0[3], ptt[6], ptu[3], seqno[1], sub[5], 
	    sub4[6], tapsto[250], titl[8], tl, tmatrx[12]	/* was [3][4] 
	    */, tntm[36], toolng, tramat[12]	/* was [3][4] */, vec[3], 
	    word, x0, x1, x2, x3, xnew, y0, y1, y2, y3, ynew;
} a3fxd1_;

#define a3fxd1_1 a3fxd1_

struct {
    doublereal motion[8];
} a3fxd2_;

#define a3fxd2_1 a3fxd2_

struct {
    integer iarrow, i1, i2, iclwas, icopy, idplot, idplsq, ifirst, igodlt, 
	    indn, instr1, instr2, ind2tb[160], indoff, indtab[160], indxno[3],
	     ipersp, ipl5ax, iploti, iplotx, iplwas, ipx, ipy, irecni[3], 
	    irecno, irectp, iret, iretvr, isubsc, iswmac, iswnoc, it, ithpnt, 
	    itrafl, itrunc, jarrow, jclprt, jcopy, jptsw, jsw, jtypsw, jvectr,
	     kclprt, kcopy, maxcop, multax, ncamra, nk, nntab, nrecno, ntab, 
	    numwds, nurcno, nx, nx0, nx1, nx2, nx4, nx5, nxp, ny, ny0, ny1, 
	    ny2, ny4, ny5, nyp, ifalms, iwarms, intseq;
} a3fxi1_;

#define a3fxi1_1 a3fxi1_

struct {
    doublereal zp1, yp1, xp1, zp2, yp2, xp2, zp3, yp3, xp3, zp1b, yp1b, xp1b, 
	    zp1f, yp1f, xp1f, zp3f, yp3f, xp3f, zp3b, yp3b, xp3b, zlm, ylm, 
	    xlm, zta1, yta1, xta1, zta2, yta2, xta2, zta3, yta3, xta3, zdta, 
	    ydta, xdta, zta2i, yta2i, xta2i, zcv1, ycv1, xcv1, zcv3, ycv3, 
	    xcv3, zcv1p, ycv1p, xcv1p, zcv3p, ycv3p, xcv3p, zcv1i, ycv1i, 
	    xcv1i, zcv3i, ycv3i, xcv3i, zdcv, ydcv, xdcv, zcp, ycp, xcp, 
	    zcp1b, ycp1b, xcp1b, zcp1f, ycp1f, xcp1f, zcp3b, ycp3b, xcp3b;
} a5axis_;

#define a5axis_1 a5axis_

struct {
    doublereal zcp3f, ycp3f, xcp3f, zdp, ydp, xdp, zd01, yd01, xd01, zd03, 
	    yd03, xd03, zpl1, ypl1, xpl1, zpl3, ypl3, xpl3, wcorn5, wcorn7, 
	    wcorn8, wtlxs6, tlnth1, tlnth2, ai, alpha, csigma, cphi, sh, 
	    clamda, s1, s2, s3, ts, gamma, beta, delta, wcorn9, theta, s, 
	    zp2i, yp2i, xp2i;
} b5axis_;

#define b5axis_1 b5axis_

struct {
    integer ip1, ip1i, ip2, ip2i, ip3, ip3i, ip1b, ip1bi, ip1f, ip1fi, ip3f, 
	    ip3fi, ip3b, ip3bi, ilm, ilmi, ips, icorn1, icorn9, iflag, iflag1,
	     icm, icmi, ii, iiii, ifg, itcont, itc1;
} a5fxis_;

#define a5fxis_1 a5fxis_

struct {
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, cutter, test,
	     cradus;
} c5axis_;

#define c5axis_1 c5axis_

struct {
    integer is, ir, il, ie, jsuber, iabove;
} c5fxis_;

#define c5fxis_1 c5fxis_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__8 = 8;

/* Subroutine */ int fp1p3_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double acos(), cos(), sin(), sqrt();

    /* Local variables */
    static integer i__, is1, is3;
#define arr ((doublereal *)&a3fxd1_1)
    static integer ier;
#define irr ((integer *)&a3fxi1_1)
    static doublereal ccorn;
    extern /* Subroutine */ int avdot_();
    static doublereal scorn;
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    extern /* Subroutine */ int avnorm_(), avcros_(), aserch_(), taperd_(), 
	    astore_();

/* ...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 *** */
/* ******************************************************************** */

/* ...    FP1P3 IS CALLED FROM VTLAXS WHEN A WCORN HAS BEEN */
/* ...    ENCOUNTERED, TO PROCESS MOTION RECORDS THROUGH */
/* ...    CORNER TRANSITION, INSPECT THEM FOR PERMISSIBLE */
/* ...    WCORN CONDITIONS, AND SET UP CORNERING PARAMETERS */
/* ...    FOR LATER USE IN COMPU2. */
/* *********************************************************************** */
/* *********************************************************************** */
/* ******************************************************************** */
/* ... */
/* ... */
/* ...    INITIALIZE FP1P3 VARIABLES */
/* ...    P1=CLTAPE POINT 2 PRIOR TO WCORN COMMAND */
/* ...    P2=CLTAPE POINT JUST PRIOR TO WCORN COMMAND (CORNER POINT) */
/* ...    P3=CLTAPE POINT JUST AFTER WCORN COMMAND */
/* ...    IP1,2,3=TAPSTO INDEX FOR P1,P2,P3 */
/* ...    IP1,2,3I= IRECNO FOR P1,P2,P3 */
    a5fxis_1.ifg = 1;
    a5fxis_1.ips = 1;
    a5fxis_1.itcont = 0;
    a5fxis_1.itc1 = 0;
    a5axis_1.xp1b = a5axis_1.xp1;
    a5axis_1.yp1b = a5axis_1.yp1;
    a5axis_1.zp1b = a5axis_1.zp1;
    a5axis_1.xp1f = a5axis_1.xp2;
    a5axis_1.yp1f = a5axis_1.yp2;
    a5axis_1.zp1f = a5axis_1.zp2;
    a5axis_1.xp3b = a5axis_1.xp3;
    a5axis_1.yp3b = a5axis_1.yp3;
    a5axis_1.zp3b = a5axis_1.zp3;
    a5axis_1.xp3f = a5axis_1.xp2;
    a5axis_1.yp3f = a5axis_1.yp2;
    a5axis_1.zp3f = a5axis_1.zp2;
    a5fxis_1.ip1b = a5fxis_1.ip1;
    a5fxis_1.ip1f = a5fxis_1.ip2;
    a5fxis_1.ip3b = a5fxis_1.ip3;
    a5fxis_1.ip3f = a5fxis_1.ip2;
    a5fxis_1.ip1bi = a5fxis_1.ip1i;
    a5fxis_1.ip1fi = a5fxis_1.ip2i;
    a5fxis_1.ip3bi = a5fxis_1.ip3i;
    a5fxis_1.ip3fi = a5fxis_1.ip2i;
/* ...    GET INCOMING AND OUTGOING CUT VECTORS */
L10:
    a5axis_1.xcv1 = a5axis_1.xp2 - a5axis_1.xp1;
    a5axis_1.ycv1 = a5axis_1.yp2 - a5axis_1.yp1;
    a5axis_1.zcv1 = a5axis_1.zp2 - a5axis_1.zp1;
    a5axis_1.xcv3 = a5axis_1.xp3 - a5axis_1.xp2;
    a5axis_1.ycv3 = a5axis_1.yp3 - a5axis_1.yp2;
    a5axis_1.zcv3 = a5axis_1.zp3 - a5axis_1.zp2;
/* ...    NORMALIZE THEM */
L15:
    avnorm_(&a5axis_1.zcv1, &a5axis_1.zcv1, &ier);
    if (ier != 0) {
	goto L16;
    } else {
	goto L17;
    }
L16:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L17:
    avnorm_(&a5axis_1.zcv3, &a5axis_1.zcv3, &ier);
    if (ier != 0) {
	goto L18;
    } else {
	goto L19;
    }
L18:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L19:
/* ...    CROSS INCOMING VECTOR WITH VERTICAL TLAXIS VECTOR */
/* ...    AND NORMALIZE */
    avcros_(&c5axis_1.zun, &a5axis_1.zcv1, &c5axis_1.ztr);
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L21;
    } else {
	goto L22;
    }
L21:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L22:
    avdot_(&c5axis_1.ztr, &a5axis_1.zcv3, &c5axis_1.test);
    if (c5axis_1.test - (float).01 <= 0.) {
	goto L20;
    } else {
	goto L30;
    }
L20:
    c5fxis_1.jsuber = 25;
/* ...    ERROR 25 - THE CORNER TO BE CLEANED OUT IS GREATER */
/* ...               THAN 180 DEGREES. */
    goto L1200;
L30:
    a5axis_1.xlm = -a5axis_1.xcv1;
    a5axis_1.ylm = -a5axis_1.ycv1;
    a5axis_1.zlm = -a5axis_1.zcv1;
    avdot_(&a5axis_1.zlm, &a5axis_1.zcv3, &c5axis_1.test);
    b5axis_1.alpha = acos(c5axis_1.test) * (float).5;
    c5axis_1.xtr = -c5axis_1.zun * c5axis_1.xtr;
    c5axis_1.ytr = -c5axis_1.zun * c5axis_1.ytr;
    c5axis_1.ztr = -c5axis_1.zun * c5axis_1.ztr;
    c5axis_1.xdo = (float)0.;
    c5axis_1.ydo = (float)0.;
    c5axis_1.zdo = (float)1.;
/* ...    WCORN5=INCOMING ANGLE */
    ccorn = cos(b5axis_1.wcorn5);
    scorn = sin(b5axis_1.wcorn5);
    a5axis_1.xta1 = scorn * c5axis_1.xtr;
    a5axis_1.yta1 = scorn * c5axis_1.ytr;
    a5axis_1.zta1 = ccorn;
/*       TR = DO X CV3 */
    avcros_(&a5axis_1.zcv3, &c5axis_1.zdo, &c5axis_1.ztr);
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L31;
    } else {
	goto L32;
    }
L31:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L32:
/* ...    WCORN7=OUTGOING ANGLE */
    ccorn = cos(b5axis_1.wcorn7);
    scorn = sin(b5axis_1.wcorn7);
    a5axis_1.xta3 = scorn * c5axis_1.xtr;
    a5axis_1.yta3 = scorn * c5axis_1.ytr;
    a5axis_1.zta3 = ccorn;
/*      PL1 =  CV1 X TA1 */
    avcros_(&a5axis_1.zta1, &a5axis_1.zcv1, &b5axis_1.zpl1);
    avnorm_(&b5axis_1.zpl1, &b5axis_1.zpl1, &ier);
    if (ier != 0) {
	goto L33;
    } else {
	goto L34;
    }
L33:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L34:
/*      PL3 = CV3 X TA3 */
    avcros_(&a5axis_1.zta3, &a5axis_1.zcv3, &b5axis_1.zpl3);
    avnorm_(&b5axis_1.zpl3, &b5axis_1.zpl3, &ier);
    if (ier != 0) {
	goto L35;
    } else {
	goto L36;
    }
L35:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L36:
/*      TA2 = PL1 X PL3 */
    avcros_(&b5axis_1.zpl3, &b5axis_1.zpl1, &a5axis_1.zta2);
    avnorm_(&a5axis_1.zta2, &a5axis_1.zta2, &ier);
    if (ier != 0) {
	goto L37;
    } else {
	goto L38;
    }
L37:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L38:
    if (a5axis_1.zta2 >= 0.) {
	goto L50;
    } else {
	goto L40;
    }
/* ...    TA2 = CORNER TLAXIS VECTOR. MAKE POSZ. */
L40:
    a5axis_1.xta2 = -a5axis_1.xta2;
    a5axis_1.yta2 = -a5axis_1.yta2;
    a5axis_1.zta2 = -a5axis_1.zta2;
L50:
    avdot_(&a5axis_1.zta2, &c5axis_1.zdo, &b5axis_1.csigma);
/* ...    WCORN8=FLANGE HEIGHT */
    b5axis_1.sh = b5axis_1.wcorn8 / b5axis_1.csigma;
    if (a5fxis_1.ifg - 1 <= 0) {
	goto L60;
    } else {
	goto L220;
    }
/* ...    CHECK LEAN OF EXIT STIFFENER FOR BEGIN POINT CALC */
L60:
    a5fxis_1.ifg = 2;
    a5axis_1.xlm = -a5axis_1.xcv1;
    a5axis_1.ylm = -a5axis_1.ycv1;
    a5axis_1.zlm = -a5axis_1.zcv1;
    avdot_(&a5axis_1.zlm, &a5axis_1.zta2, &b5axis_1.cphi);
    if (b5axis_1.cphi - (float).002 <= 0.) {
	goto L70;
    } else {
	goto L90;
    }
L70:
    if (a5fxis_1.ips != 0) {
	goto L85;
    } else {
	goto L80;
    }
L80:
    is1 = 1;
    goto L1130;
L85:
    is1 = 1;
    a5fxis_1.ips = 0;
    goto L220;
/* ...    EXIT STIFFENER LEANS TOWARD ENTRANCE PATH. */
/* ...    FIND STARTING POSITION FOR CORNER CLEANOUT */
L90:
    b5axis_1.s1 = b5axis_1.sh * b5axis_1.cphi;
    is1 = 0;
    avdot_(&a5axis_1.zta1, &a5axis_1.zcv3, &b5axis_1.clamda);
    a5axis_1.xcv3p = a5axis_1.xcv3 - b5axis_1.clamda * a5axis_1.xta1;
    a5axis_1.ycv3p = a5axis_1.ycv3 - b5axis_1.clamda * a5axis_1.yta1;
    a5axis_1.zcv3p = a5axis_1.zcv3 - b5axis_1.clamda * a5axis_1.zta1;
    avnorm_(&a5axis_1.zcv3p, &a5axis_1.zcv3p, &ier);
    if (ier != 0) {
	goto L91;
    } else {
	goto L92;
    }
L91:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L92:
    avdot_(&a5axis_1.zcv3p, &a5axis_1.zlm, &c5axis_1.test);
/* L100: */
    b5axis_1.theta = acos(c5axis_1.test) * (float).5;
/* L120: */
    b5axis_1.s2 = c5axis_1.cutter * cos(b5axis_1.theta) / sin(b5axis_1.theta);
    b5axis_1.s3 = c5axis_1.cutter * cos(b5axis_1.alpha) / sin(b5axis_1.alpha);
    b5axis_1.s = b5axis_1.s1 + b5axis_1.s2 - b5axis_1.s3 + (float).1;
/* Computing 2nd power */
    d__1 = a5axis_1.xp2 - a5axis_1.xp1;
/* Computing 2nd power */
    d__2 = a5axis_1.yp2 - a5axis_1.yp1;
/* Computing 2nd power */
    d__3 = a5axis_1.zp2 - a5axis_1.zp1;
    c5axis_1.test = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if (b5axis_1.ts < 0.) {
	goto L130;
    } else if (b5axis_1.ts == 0) {
	goto L200;
    } else {
	goto L140;
    }
L130:
    if (b5axis_1.ts + (float).1 >= 0.) {
	goto L200;
    } else {
	goto L170;
    }
L140:
    a5fxis_1.ifg = 1;
    a5fxis_1.ips = 1;
    ++a5fxis_1.itc1;
    if (a5fxis_1.itc1 - 25 >= 0) {
	goto L160;
    } else {
	goto L370;
    }
L160:
    c5fxis_1.jsuber = 26;
/* ...    ERROR 26 - A SATISFACTORY STARTING POSITION FOR THE */
/* ...               CORNER CLEANOUT COULD NOT BE FOUND. */
    goto L1200;
L170:
    a5fxis_1.ifg = 1;
    a5fxis_1.ips = 1;
    ++a5fxis_1.itc1;
    if (a5fxis_1.itc1 - 25 >= 0) {
	goto L190;
    } else {
	goto L560;
    }
L190:
    c5fxis_1.jsuber = 26;
/* ...    ERROR 26 - A SATISFACTORY STARTING POSITION FOR THE */
/* ...               CORNER CLEANOUT COULD NOT BE FOUND. */
    goto L1200;
/* ...    BEGIN OR END POINT FOUND. */
L200:
    if (a5fxis_1.ips != 0) {
	goto L210;
    } else {
	goto L1130;
    }
L210:
    a5fxis_1.ips = 0;
    a5fxis_1.itc1 = 0;
/* ...    CHECK LEAN OF ENTRANCE STIFFENER FOR ENDING POINT CALC */
L220:
    ++a5fxis_1.itcont;
    if (a5fxis_1.itcont - 50 >= 0) {
	goto L230;
    } else {
	goto L240;
    }
L230:
    c5fxis_1.jsuber = 27;
/* ...    ERROR 27 - A SATISFACTORY STARTING AND ENDING POSITION */
/* ...               FOR THE CORNER CLEANOUT COULD NOT BE FOUND. */
    goto L1200;
L240:
    a5fxis_1.ifg = 1;
    avdot_(&a5axis_1.zcv3, &a5axis_1.zta2, &b5axis_1.cphi);
    if (b5axis_1.cphi - (float).002 <= 0.) {
	goto L242;
    } else {
	goto L250;
    }
L242:
    is3 = 1;
    goto L1130;
/* ...    ENTRANCE STIFFENER LEANS TOWARD EXIT PATH. */
/* ...    FIND ENDING POSITION FOR CORNER CLEANOUT */
L250:
    b5axis_1.s1 = b5axis_1.sh * b5axis_1.cphi;
    is3 = 0;
    avdot_(&a5axis_1.zta3, &a5axis_1.zcv1, &b5axis_1.clamda);
    a5axis_1.xcv1p = -a5axis_1.xcv1 + b5axis_1.clamda * a5axis_1.xta3;
    a5axis_1.ycv1p = -a5axis_1.ycv1 + b5axis_1.clamda * a5axis_1.yta3;
    a5axis_1.zcv1p = -a5axis_1.zcv1 + b5axis_1.clamda * a5axis_1.zta3;
    avnorm_(&a5axis_1.zcv1p, &a5axis_1.zcv1p, &ier);
    if (ier != 0) {
	goto L251;
    } else {
	goto L252;
    }
L251:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L252:
    avdot_(&a5axis_1.zcv1p, &a5axis_1.zcv3, &c5axis_1.test);
    b5axis_1.theta = acos(c5axis_1.test) * (float).5;
/* L270: */
    b5axis_1.s2 = c5axis_1.cutter * cos(b5axis_1.theta) / sin(b5axis_1.theta);
    b5axis_1.s3 = c5axis_1.cutter * cos(b5axis_1.alpha) / sin(b5axis_1.alpha);
    b5axis_1.s = b5axis_1.s1 + b5axis_1.s2 - b5axis_1.s3 + (float).1;
/* Computing 2nd power */
    d__1 = a5axis_1.xp2 - a5axis_1.xp3;
/* Computing 2nd power */
    d__2 = a5axis_1.yp2 - a5axis_1.yp3;
/* Computing 2nd power */
    d__3 = a5axis_1.zp2 - a5axis_1.zp3;
    c5axis_1.test = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if (b5axis_1.ts < 0.) {
	goto L280;
    } else if (b5axis_1.ts == 0) {
	goto L290;
    } else {
	goto L310;
    }
L280:
    if (b5axis_1.ts + (float).1 >= 0.) {
	goto L290;
    } else {
	goto L340;
    }
L290:
    if (a5fxis_1.ips != 0) {
	goto L300;
    } else {
	goto L1130;
    }
L300:
    a5fxis_1.ips = 0;
    a5fxis_1.itc1 = 0;
    goto L60;
L310:
    a5fxis_1.ips = 1;
    a5fxis_1.ifg = 2;
    ++a5fxis_1.itc1;
    --a5fxis_1.itcont;
    if (a5fxis_1.itc1 - 25 >= 0) {
	goto L330;
    } else {
	goto L750;
    }
L330:
    c5fxis_1.jsuber = 28;
/* ...    ERROR 28 - A SATISFACTORY ENDING POSITION FOR THE */
/* ...               CORNER CLEANOUT COULD NOT BE FOUND. */
    goto L1200;
L340:
    a5fxis_1.ips = 1;
    a5fxis_1.ifg = 2;
    ++a5fxis_1.itc1;
    --a5fxis_1.itcont;
    if (a5fxis_1.itc1 - 25 >= 0) {
	goto L360;
    } else {
	goto L940;
    }
L360:
    c5fxis_1.jsuber = 28;
/* ...    ERROR 28 - A SATISFACTORY ENDING POSITION FOR THE */
/* ...               CORNER CLEANOUT COULD NOT BE FOUND. */
    goto L1200;
/* ... */
/* ... */
/* ...    TEST FOR SUFFICIENT MOVE BETWEEN VTLAXS/ON AND */
/* ...    CORNER TO ACCOMPLISH CLEANOUT */
/* ...    FROM 140   (TS .GT. 0). ALTER AND REITERATE. */
L370:
    a5axis_1.xcp1b = a5axis_1.xp1 - a5axis_1.xp1b;
    a5axis_1.ycp1b = a5axis_1.yp1 - a5axis_1.yp1b;
    a5axis_1.zcp1b = a5axis_1.zp1 - a5axis_1.zp1b;
/* Computing 2nd power */
    d__1 = a5axis_1.xcp1b;
/* Computing 2nd power */
    d__2 = a5axis_1.ycp1b;
/* Computing 2nd power */
    d__3 = a5axis_1.zcp1b;
    c5axis_1.test += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if (b5axis_1.ts < 0.) {
	goto L380;
    } else if (b5axis_1.ts == 0) {
	goto L390;
    } else {
	goto L410;
    }
L380:
    if (b5axis_1.ts + (float).1 >= 0.) {
	goto L390;
    } else {
	goto L400;
    }
L390:
    a5axis_1.xp1 = a5axis_1.xp1b;
    a5axis_1.yp1 = a5axis_1.yp1b;
    a5axis_1.zp1 = a5axis_1.zp1b;
    goto L10;
L400:
    avnorm_(&a5axis_1.zcp1b, &a5axis_1.zcp1b, &ier);
    if (ier != 0) {
	goto L401;
    } else {
	goto L402;
    }
L401:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L402:
    b5axis_1.ts += (float).05;
    a5axis_1.xp1 = a5axis_1.xp1b - b5axis_1.ts * a5axis_1.xcp1b;
    a5axis_1.yp1 = a5axis_1.yp1b - b5axis_1.ts * a5axis_1.ycp1b;
    a5axis_1.zp1 = a5axis_1.zp1b - b5axis_1.ts * a5axis_1.zcp1b;
    goto L10;
/* ...    FROM 370   (TS .LT. -.1) LOOK AT PRIOR CLTAPE POINT */
L410:
/* Computing 2nd power */
    d__1 = a5axis_1.xp1f - a5axis_1.xp1b;
/* Computing 2nd power */
    d__2 = a5axis_1.yp1f - a5axis_1.yp1b;
/* Computing 2nd power */
    d__3 = a5axis_1.zp1f - a5axis_1.zp1b;
    b5axis_1.tlnth1 -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    a5axis_1.xp1 = a5axis_1.xp1b;
    a5axis_1.yp1 = a5axis_1.yp1b;
    a5axis_1.zp1 = a5axis_1.zp1b;
    c5fxis_1.il = a5fxis_1.ip1b;
    a5axis_1.xp1f = a5axis_1.xp1b;
    a5axis_1.yp1f = a5axis_1.yp1b;
    a5axis_1.zp1f = a5axis_1.zp1b;
    a5fxis_1.ip1f = a5fxis_1.ip1b;
    a5fxis_1.ip1fi = a5fxis_1.ip1bi;
    if (a5fxis_1.ip1bi - 6 <= 0) {
	goto L420;
    } else {
	goto L440;
    }
L420:
    --c5fxis_1.il;
    if (c5fxis_1.is - c5fxis_1.il <= 0) {
	goto L440;
    } else {
	goto L430;
    }
L430:
    c5fxis_1.jsuber = 29;
/* ...    ERROR 29 - INSUFFICIENT MOTION BETWEEN THE VTLAXS/ON */
/* ...               AND THE WCORN TO COMPLETE THE CORNER */
/* ...               CLEANOUT PROCESS. */
    goto L1200;
/* ...    NOT ENOUGH MOVE. BACK CLTAPE ONE RECORD AT A TIME, */
/* ...    CHECKING FOR SUFFICIENT MOVEMENT. */
L440:
    aserch_(&ataptb_1.cltape, &c5fxis_1.il, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L450;
    } else {
	goto L460;
    }
L450:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L1200;
L460:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L470;
    } else {
	goto L480;
    }
L470:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L480:
    if (a5fxis_1.ip1bi - 3 <= 0) {
	goto L510;
    } else {
	goto L490;
    }
L490:
    a5fxis_1.ip1bi += -6;
L500:
    a5axis_1.xp1b = a3fxd1_1.tapsto[a5fxis_1.ip1bi - 1];
    a5axis_1.yp1b = a3fxd1_1.tapsto[a5fxis_1.ip1bi];
    a5axis_1.zp1b = a3fxd1_1.tapsto[a5fxis_1.ip1bi + 1];
    goto L370;
L510:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L420;
    } else {
	goto L520;
    }
/* ...    MOTION RECORD */
L520:
    i__ = abs(a3fxi1_1.instr2);
    if ((i__1 = i__ - 6) < 0) {
	goto L530;
    } else if (i__1 == 0) {
	goto L540;
    } else {
	goto L420;
    }
L530:
    switch ((int)i__) {
	case 1:  goto L420;
	case 2:  goto L420;
	case 3:  goto L540;
	case 4:  goto L550;
	case 5:  goto L540;
    }
/* ...    FROM, GOTO */
L540:
    a5fxis_1.ip1b = a3fxi1_1.irecno;
    a5fxis_1.ip1bi = a3fxi1_1.numwds - 5;
    goto L500;
/* ...    GODLTA */
L550:
    a5fxis_1.ip1b = a3fxi1_1.irecno;
    a5fxis_1.ip1bi = 3;
    a5axis_1.xp1b -= a3fxd1_1.tapsto[2];
    a5axis_1.yp1b -= a3fxd1_1.tapsto[3];
    a5axis_1.zp1b -= a3fxd1_1.tapsto[4];
    goto L370;
/* ...    FROM 170 (TS .LT. 0). ALTER AND REITERATE. */
L560:
    a5axis_1.xcp1f = a5axis_1.xp1 - a5axis_1.xp1f;
    a5axis_1.ycp1f = a5axis_1.yp1 - a5axis_1.yp1f;
    a5axis_1.zcp1f = a5axis_1.zp1 - a5axis_1.zp1f;
/* Computing 2nd power */
    d__1 = a5axis_1.xcp1f;
/* Computing 2nd power */
    d__2 = a5axis_1.ycp1f;
/* Computing 2nd power */
    d__3 = a5axis_1.zcp1f;
    c5axis_1.test -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if ((d__1 = b5axis_1.ts + (float).1) < 0.) {
	goto L600;
    } else if (d__1 == 0) {
	goto L580;
    } else {
	goto L570;
    }
L570:
    if (b5axis_1.ts <= 0.) {
	goto L580;
    } else {
	goto L590;
    }
L580:
    a5axis_1.xp1 = a5axis_1.xp1f;
    a5axis_1.yp1 = a5axis_1.yp1f;
    a5axis_1.zp1 = a5axis_1.zp1f;
    goto L591;
L590:
    avnorm_(&a5axis_1.zcp1f, &a5axis_1.zcp1f, &ier);
    if (ier != 0) {
	goto L595;
    } else {
	goto L596;
    }
L595:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L596:
    b5axis_1.ts += (float).05;
    a5axis_1.xp1 = a5axis_1.xp1f + b5axis_1.ts * a5axis_1.xcp1f;
    a5axis_1.yp1 = a5axis_1.yp1f + b5axis_1.ts * a5axis_1.ycp1f;
    a5axis_1.zp1 = a5axis_1.zp1f + b5axis_1.ts * a5axis_1.zcp1f;
L591:
    if ((d__1 = a5axis_1.xp1 - a5axis_1.xp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L592;
    } else {
	goto L10;
    }
L592:
    if ((d__1 = a5axis_1.yp1 - a5axis_1.yp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L593;
    } else {
	goto L10;
    }
L593:
    if ((d__1 = a5axis_1.zp1 - a5axis_1.zp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L594;
    } else {
	goto L10;
    }
L594:
    a5axis_1.xcv1 = a5axis_1.xp2 - a5axis_1.xp1b;
    a5axis_1.ycv1 = a5axis_1.yp2 - a5axis_1.yp1b;
    a5axis_1.zcv1 = a5axis_1.zp2 - a5axis_1.zp1b;
    goto L15;
/* ...    FROM 560 (TS .LT. -.1) LOOK AT CLTAPE POINTS */
L600:
/* Computing 2nd power */
    d__1 = a5axis_1.xp1f - a5axis_1.xp1b;
/* Computing 2nd power */
    d__2 = a5axis_1.yp1f - a5axis_1.yp1b;
/* Computing 2nd power */
    d__3 = a5axis_1.zp1f - a5axis_1.zp1b;
    b5axis_1.tlnth1 += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    a5axis_1.xp1 = a5axis_1.xp1f;
    a5axis_1.yp1 = a5axis_1.yp1f;
    a5axis_1.zp1 = a5axis_1.zp1f;
    c5fxis_1.il = a5fxis_1.ip1f;
    a5axis_1.xp1b = a5axis_1.xp1f;
    a5axis_1.yp1b = a5axis_1.yp1f;
    a5axis_1.zp1b = a5axis_1.zp1f;
    a5fxis_1.ip1b = a5fxis_1.ip1f;
    a5fxis_1.ip1bi = a5fxis_1.ip1fi;
    aserch_(&ataptb_1.cltape, &c5fxis_1.il, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L610;
    } else {
	goto L620;
    }
L610:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L1200;
L620:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L630;
    } else {
	goto L640;
    }
L630:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L640:
    a5fxis_1.ip1fi += 6;
    if (a5fxis_1.ip1fi - a3fxi1_1.numwds >= 0) {
	goto L660;
    } else {
	goto L650;
    }
L650:
    a5axis_1.xp1f = a3fxd1_1.tapsto[a5fxis_1.ip1fi - 1];
    a5axis_1.yp1f = a3fxd1_1.tapsto[a5fxis_1.ip1fi];
    a5axis_1.zp1f = a3fxd1_1.tapsto[a5fxis_1.ip1fi + 1];
    goto L560;
L660:
    ++c5fxis_1.il;
    if (c5fxis_1.il - a5fxis_1.icorn1 >= 0) {
	goto L670;
    } else {
	goto L680;
    }
L670:
    c5fxis_1.jsuber = 29;
/* ...    ERROR 29  - MACHINE ERROR. */
    goto L1200;
L680:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L690;
    } else {
	goto L700;
    }
L690:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L700:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L660;
    } else {
	goto L710;
    }
L710:
    i__ = abs(a3fxi1_1.instr2);
    if ((i__1 = i__ - 6) < 0) {
	goto L720;
    } else if (i__1 == 0) {
	goto L730;
    } else {
	goto L660;
    }
L720:
    switch ((int)i__) {
	case 1:  goto L660;
	case 2:  goto L660;
	case 3:  goto L730;
	case 4:  goto L740;
	case 5:  goto L730;
    }
L730:
    a5fxis_1.ip1f = a3fxi1_1.irecno;
    a5fxis_1.ip1fi = 3;
    goto L650;
L740:
    a5fxis_1.ip1f = a3fxi1_1.irecno;
    a5fxis_1.ip1fi = 3;
    a5axis_1.xp1f += a3fxd1_1.tapsto[2];
    a5axis_1.yp1f += a3fxd1_1.tapsto[3];
    a5axis_1.zp1f += a3fxd1_1.tapsto[4];
    goto L560;
/* ...    FROM 310 (TS .GT. 0)  ENDING POINT CALCS.  ALTER */
/* ...    AND REITERATE */
L750:
    a5axis_1.xcp3b = a5axis_1.xp3 - a5axis_1.xp3b;
    a5axis_1.ycp3b = a5axis_1.yp3 - a5axis_1.yp3b;
    a5axis_1.zcp3b = a5axis_1.zp3 - a5axis_1.zp3b;
/* Computing 2nd power */
    d__1 = a5axis_1.xcp3b;
/* Computing 2nd power */
    d__2 = a5axis_1.ycp3b;
/* Computing 2nd power */
    d__3 = a5axis_1.zcp3b;
    c5axis_1.test += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if (b5axis_1.ts < 0.) {
	goto L760;
    } else if (b5axis_1.ts == 0) {
	goto L770;
    } else {
	goto L790;
    }
L760:
    if (b5axis_1.ts + (float).1 >= 0.) {
	goto L770;
    } else {
	goto L780;
    }
L770:
    a5axis_1.xp3 = a5axis_1.xp3b;
    a5axis_1.yp3 = a5axis_1.yp3b;
    a5axis_1.zp3 = a5axis_1.zp3b;
    goto L10;
L780:
    avnorm_(&a5axis_1.zcp3b, &a5axis_1.zcp3b, &ier);
    if (ier != 0) {
	goto L781;
    } else {
	goto L782;
    }
L781:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L782:
    b5axis_1.ts += (float).05;
    a5axis_1.xp3 = a5axis_1.xp3b - b5axis_1.ts * a5axis_1.xcp3b;
    a5axis_1.yp3 = a5axis_1.yp3b - b5axis_1.ts * a5axis_1.ycp3b;
    a5axis_1.zp3 = a5axis_1.zp3b - b5axis_1.ts * a5axis_1.zcp3b;
    goto L10;
/* ...    FROM 750 (TS .GT. 0) LOOK AT CLTAPE POINTS AFTER WCORN */
L790:
/* Computing 2nd power */
    d__1 = a5axis_1.xp3f - a5axis_1.xp3b;
/* Computing 2nd power */
    d__2 = a5axis_1.yp3f - a5axis_1.yp3b;
/* Computing 2nd power */
    d__3 = a5axis_1.zp3f - a5axis_1.zp3b;
    b5axis_1.tlnth2 -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    a5axis_1.xp3 = a5axis_1.xp3b;
    a5axis_1.yp3 = a5axis_1.yp3b;
    a5axis_1.zp3 = a5axis_1.zp3b;
    a5axis_1.xp3f = a5axis_1.xp3b;
    a5axis_1.yp3f = a5axis_1.yp3f;
    a5axis_1.zp3f = a5axis_1.zp3f;
    a5fxis_1.ip3f = a5fxis_1.ip3b;
    a5fxis_1.ip3fi = a5fxis_1.ip3bi;
    c5fxis_1.il = a5fxis_1.ip3b;
    aserch_(&ataptb_1.cltape, &c5fxis_1.il, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L800;
    } else {
	goto L810;
    }
L800:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L1200;
L810:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L820;
    } else {
	goto L830;
    }
L820:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L830:
    a5fxis_1.ip3bi += 6;
    if (a5fxis_1.ip3bi - a3fxi1_1.numwds >= 0) {
	goto L850;
    } else {
	goto L840;
    }
L840:
    a5axis_1.xp3b = a3fxd1_1.tapsto[a5fxis_1.ip3bi - 1];
    a5axis_1.yp3b = a3fxd1_1.tapsto[a5fxis_1.ip3bi];
    a5axis_1.zp3b = a3fxd1_1.tapsto[a5fxis_1.ip3bi + 1];
    goto L750;
L850:
    ++c5fxis_1.il;
    if (c5fxis_1.il - c5fxis_1.ie >= 0) {
	goto L860;
    } else {
	goto L870;
    }
L860:
    c5fxis_1.jsuber = 30;
/* ...    ERROR 30 - INSUFFICIENT MOTION BETWEEN THE WCORN */
/* ...               COMMAND AND THE VTLAXS/OFF TO COMPLETE */
/* ...               THE CORNER CLEANOUT PROCESS. */
    goto L1200;
L870:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L880;
    } else {
	goto L890;
    }
L880:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L890:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L850;
    } else {
	goto L900;
    }
L900:
    i__ = abs(a3fxi1_1.instr2);
    if ((i__1 = i__ - 6) < 0) {
	goto L910;
    } else if (i__1 == 0) {
	goto L920;
    } else {
	goto L850;
    }
L910:
    switch ((int)i__) {
	case 1:  goto L850;
	case 2:  goto L850;
	case 3:  goto L920;
	case 4:  goto L930;
	case 5:  goto L920;
    }
L920:
    a5fxis_1.ip3b = a3fxi1_1.irecno;
    a5fxis_1.ip3bi = 3;
    goto L840;
L930:
    a5fxis_1.ip3b = a3fxi1_1.irecno;
    a5fxis_1.ip3bi = 3;
    a5axis_1.xp3b += a3fxd1_1.tapsto[2];
    a5axis_1.yp3b += a3fxd1_1.tapsto[3];
    a5axis_1.zp3b += a3fxd1_1.tapsto[4];
    goto L750;
/* ...    FROM 340 (TS .LT. -1) ALTER AND REITERATE */
L940:
    b5axis_1.xcp3f = a5axis_1.xp3 - a5axis_1.xp3f;
    b5axis_1.ycp3f = a5axis_1.yp3 - a5axis_1.yp3f;
    b5axis_1.zcp3f = a5axis_1.zp3 - a5axis_1.zp3f;
/* Computing 2nd power */
    d__1 = b5axis_1.xcp3f;
/* Computing 2nd power */
    d__2 = b5axis_1.ycp3f;
/* Computing 2nd power */
    d__3 = b5axis_1.zcp3f;
    c5axis_1.test -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    b5axis_1.ts = b5axis_1.s - c5axis_1.test;
    if ((d__1 = b5axis_1.ts + (float).1) < 0.) {
	goto L980;
    } else if (d__1 == 0) {
	goto L960;
    } else {
	goto L950;
    }
L950:
    if (b5axis_1.ts <= 0.) {
	goto L960;
    } else {
	goto L970;
    }
L960:
    a5axis_1.xp3 = a5axis_1.xp3f;
    a5axis_1.yp3 = a5axis_1.yp3f;
    a5axis_1.zp3 = a5axis_1.zp3f;
    goto L971;
L970:
    avnorm_(&b5axis_1.zcp3f, &b5axis_1.zcp3f, &ier);
    if (ier != 0) {
	goto L975;
    } else {
	goto L976;
    }
L975:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L1200;
L976:
    b5axis_1.ts += (float).05;
    a5axis_1.xp3 = a5axis_1.xp3f + b5axis_1.ts * b5axis_1.xcp3f;
    a5axis_1.yp3 = a5axis_1.yp3f + b5axis_1.ts * b5axis_1.ycp3f;
    a5axis_1.zp3 = a5axis_1.zp3f + b5axis_1.ts * b5axis_1.zcp3f;
L971:
    if ((d__1 = a5axis_1.xp3 - a5axis_1.xp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L972;
    } else {
	goto L10;
    }
L972:
    if ((d__1 = a5axis_1.yp3 - a5axis_1.yp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L973;
    } else {
	goto L10;
    }
L973:
    if ((d__1 = a5axis_1.zp3 - a5axis_1.zp2, abs(d__1)) - (float)1e-4 <= 0.) {
	goto L974;
    } else {
	goto L10;
    }
L974:
    a5axis_1.xcv3 = a5axis_1.xp3b - a5axis_1.xp2;
    a5axis_1.ycv3 = a5axis_1.yp3b - a5axis_1.yp2;
    a5axis_1.zcv3 = a5axis_1.zp3b - a5axis_1.zp2;
    goto L15;
/* ...    FROM 940 (TS .LT. -.1) LOOK AT CLTAPE POINTS */
L980:
/* Computing 2nd power */
    d__1 = a5axis_1.xp3f - a5axis_1.xp3b;
/* Computing 2nd power */
    d__2 = a5axis_1.yp3f - a5axis_1.yp3b;
/* Computing 2nd power */
    d__3 = a5axis_1.zp3f - a5axis_1.zp3b;
    b5axis_1.tlnth2 += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    a5axis_1.xp3 = a5axis_1.xp3f;
    a5axis_1.yp3 = a5axis_1.yp3f;
    a5axis_1.zp3 = a5axis_1.zp3f;
    a5axis_1.xp3b = a5axis_1.xp3f;
    a5axis_1.yp3b = a5axis_1.yp3f;
    a5axis_1.zp3b = a5axis_1.zp3f;
    a5fxis_1.ip3b = a5fxis_1.ip3f;
    a5fxis_1.ip3bi = a5fxis_1.ip3fi;
    c5fxis_1.il = a5fxis_1.ip3f;
    if (a5fxis_1.ip3fi - 3 <= 0) {
	goto L990;
    } else {
	goto L1010;
    }
L990:
    --c5fxis_1.il;
    if (c5fxis_1.il - a5fxis_1.icorn1 <= 0) {
	goto L1000;
    } else {
	goto L1010;
    }
L1000:
    c5fxis_1.jsuber = 29;
/* ...    ERROR 29  - MACHINE ERROR. */
    goto L1200;
L1010:
    aserch_(&ataptb_1.cltape, &c5fxis_1.il, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L1020;
    } else {
	goto L1030;
    }
L1020:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L1200;
L1030:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L1040;
    } else {
	goto L1050;
    }
L1040:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L1200;
L1050:
    if (a5fxis_1.ip3fi - 3 <= 0) {
	goto L1080;
    } else {
	goto L1060;
    }
L1060:
    a5fxis_1.ip3fi += -6;
L1070:
    a5axis_1.xp3f = a3fxd1_1.tapsto[a5fxis_1.ip3fi - 1];
    a5axis_1.yp3f = a3fxd1_1.tapsto[a5fxis_1.ip3fi];
    a5axis_1.zp3f = a3fxd1_1.tapsto[a5fxis_1.ip3fi + 1];
    goto L940;
L1080:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L990;
    } else {
	goto L1090;
    }
L1090:
    i__ = abs(a3fxi1_1.instr2);
    if ((i__1 = i__ - 6) < 0) {
	goto L1100;
    } else if (i__1 == 0) {
	goto L1110;
    } else {
	goto L990;
    }
L1100:
    switch ((int)i__) {
	case 1:  goto L990;
	case 2:  goto L990;
	case 3:  goto L1110;
	case 4:  goto L1120;
	case 5:  goto L1110;
    }
L1110:
    a5fxis_1.ip3f = a3fxi1_1.irecno;
    a5fxis_1.ip3fi = a3fxi1_1.numwds - 5;
    goto L1070;
L1120:
    a5fxis_1.ip3f = a3fxi1_1.irecno;
    a5fxis_1.ip3fi = 3;
    a5axis_1.xp3f -= a3fxd1_1.tapsto[2];
    a5axis_1.yp3f -= a3fxd1_1.tapsto[3];
    a5axis_1.zp3f -= a3fxd1_1.tapsto[4];
    goto L940;
/* ... */
/* ... */
/* ...    BEGIN AND END POINTS FOUND.  RESET COMMON VARIABLES */
L1130:
    if (is1 != 0) {
	goto L1140;
    } else {
	goto L1160;
    }
L1140:
    if (a5fxis_1.ip1f - a5fxis_1.ip2 != 0) {
	goto L1145;
    } else {
	goto L1150;
    }
L1145:
    c5fxis_1.jsuber = 27;
/* ...    ERROR 27  - MACHINE ERROR. */
    goto L1200;
L1150:
    if (a5fxis_1.ip1fi - a5fxis_1.ip2i != 0) {
	goto L1145;
    } else {
	goto L1155;
    }
L1155:
    a5axis_1.xp1 = a5axis_1.xp1f;
    a5axis_1.yp1 = a5axis_1.yp1f;
    a5axis_1.zp1 = a5axis_1.zp1f;
    a5fxis_1.ip1 = a5fxis_1.ip1f;
    a5fxis_1.ip1i = a5fxis_1.ip1fi;
L1160:
    if (is3 != 0) {
	goto L1165;
    } else {
	goto L1190;
    }
L1165:
    if (a5fxis_1.ip3f - a5fxis_1.ip2 != 0) {
	goto L1170;
    } else {
	goto L1175;
    }
/* ...    ERROR 27  - MACHINE ERROR. */
L1170:
    c5fxis_1.jsuber = 27;
    goto L1200;
L1175:
    if (a5fxis_1.ip3fi - a5fxis_1.ip2i != 0) {
	goto L1170;
    } else {
	goto L1180;
    }
L1180:
    a5axis_1.xp3 = a5axis_1.xp3f;
    a5axis_1.yp3 = a5axis_1.yp3f;
    a5axis_1.zp3 = a5axis_1.zp3f;
    a5fxis_1.ip3 = a5fxis_1.ip3f;
    a5fxis_1.ip3i = a5fxis_1.ip3fi;
L1190:
/* Computing 2nd power */
    d__1 = a5axis_1.xp1f - a5axis_1.xp1;
/* Computing 2nd power */
    d__2 = a5axis_1.yp1f - a5axis_1.yp1;
/* Computing 2nd power */
    d__3 = a5axis_1.zp1f - a5axis_1.zp1;
    b5axis_1.tlnth1 -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* Computing 2nd power */
    d__1 = a5axis_1.xp3f - a5axis_1.xp3;
/* Computing 2nd power */
    d__2 = a5axis_1.yp3f - a5axis_1.yp3;
/* Computing 2nd power */
    d__3 = a5axis_1.zp3f - a5axis_1.zp3;
    b5axis_1.tlnth2 -= sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
L1200:
    return 0;
} /* fp1p3_ */

#undef lclprt
#undef nucltp
#undef irr
#undef arr


