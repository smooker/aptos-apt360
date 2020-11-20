/* COMPU2.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

static struct {
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

static struct {
    doublereal motion[8];
} a3fxd2_;

#define a3fxd2_1 a3fxd2_

static struct {
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

static struct {
    doublereal zp1, yp1, xp1, zp2, yp2, xp2, zp3, yp3, xp3, zp1b, yp1b, xp1b, 
	    zp1f, yp1f, xp1f, zp3f, yp3f, xp3f, zp3b, yp3b, xp3b, zlm, ylm, 
	    xlm, zta1, yta1, xta1, zta2, yta2, xta2, zta3, yta3, xta3, zdta, 
	    ydta, xdta, zta2i, yta2i, xta2i, zcv1, ycv1, xcv1, zcv3, ycv3, 
	    xcv3, zcv1p, ycv1p, xcv1p, zcv3p, ycv3p, xcv3p, zcv1i, ycv1i, 
	    xcv1i, zcv3i, ycv3i, xcv3i, zdcv, ydcv, xdcv, zcp, ycp, xcp, 
	    zcp1b, ycp1b, xcp1b, zcp1f, ycp1f, xcp1f, zcp3b, ycp3b, xcp3b;
} a5axis_;

#define a5axis_1 a5axis_

static struct {
    doublereal zcp3f, ycp3f, xcp3f, zdp, ydp, xdp, zd01, yd01, xd01, zd03, 
	    yd03, xd03, zpl1, ypl1, xpl1, zpl3, ypl3, xpl3, wcorn5, wcorn7, 
	    wcorn8, wtlxs6, tlnth1, tlnth2, ai, alpha, csigma, cphi, sh, 
	    clamda, s1, s2, s3, ts, gamma, beta, delta, wcorn9, theta, s, 
	    zp2i, yp2i, xp2i;
} b5axis_;

#define b5axis_1 b5axis_

static struct {
    integer ip1, ip1i, ip2, ip2i, ip3, ip3i, ip1b, ip1bi, ip1f, ip1fi, ip3f, 
	    ip3fi, ip3b, ip3bi, ilm, ilmi, ips, icorn1, icorn9, iflag, iflag1,
	     icm, icmi, ii, iiii, ifg, itcont, itc1;
} a5fxis_;

#define a5fxis_1 a5fxis_

static struct {
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, cutter, test,
	     cradus;
} c5axis_;

#define c5axis_1 c5axis_

static struct {
    integer is, ir, il, ie, jsuber, iabove;
} c5fxis_;

#define c5fxis_1 c5fxis_

static struct {
    doublereal xxxxta, yyyyta, zzzzta, chingx, chingy, chingz;
} tachck_;

#define tachck_1 tachck_

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__8 = 8;

/* Subroutine */ int compu2_()
{
    /* Format strings */
    static char fmt_182[] = "(\0020**************************************\
\002/,\002 TOOL AXIS TILT ANGLE AT CORNER VERTEX IN X-Z PLANE = \002,f12.6\
,\002 DEGREES\002)";
    static char fmt_188[] = "(\002 TOOL AXIS TILT ANGLE AT CORNER VERTEX IN \
Y-Z PLANE = \002,f12.6,\002 DEGREES\002)";
    static char fmt_191[] = "(\002 **************************************\
\002)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double cos(), atan();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define arr ((doublereal *)&a3fxd1_1)
    static integer ier;
#define irr ((integer *)&a3fxi1_1)
    static doublereal xp1a, yp1a, zp1a, xp3a, yp3a, zp3a, xp2a, yp2a, zp2a;
    extern /* Subroutine */ int trcpm_();
    static doublereal wcorn;
    extern /* Subroutine */ int compu1_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    extern /* Subroutine */ int avnorm_(), avcros_(), corner_(), tapewt_(), 
	    clprnt_(), taperd_(), astore_(), aserch_();

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 0, 0, fmt_182, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_188, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_191, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ******************************************************************** */

/* ...    COMPU2 COMPUTES THE TOOL POSITIONS FOR CORNER CLEAN-OUT */
/* ...    (WCORN). */
/* *********************************************************************** */
/* ******************************************************************** */
/* ... */
/* ...     OBTAIN CORNER CLEAN-OUT BEGIN POSITION             ***** 1***** */
    c5axis_1.dlngth = c5axis_1.tlngth;
    c5axis_1.xcv = a5axis_1.xcv1;
    c5axis_1.ycv = a5axis_1.ycv1;
    c5axis_1.zcv = a5axis_1.zcv1;
    a3fxd1_1.x2 = a5axis_1.xp1;
    a3fxd1_1.y2 = a5axis_1.yp1;
    c5axis_1.z2 = a5axis_1.zp1;
    compu1_();
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L10;
    }
L10:
    a5axis_1.xta1 = c5axis_1.xta;
    a5axis_1.yta1 = c5axis_1.yta;
    a5axis_1.zta1 = c5axis_1.zta;
    c5axis_1.ztr = 0.;
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L11;
    } else {
	goto L12;
    }
L11:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L12:
    c5axis_1.test = c5axis_1.cutter / cos((abs(c5axis_1.cang))) - 
	    c5axis_1.cutter;
    xp1a = a5axis_1.xp1 - c5axis_1.test * c5axis_1.xtr;
    yp1a = a5axis_1.yp1 - c5axis_1.test * c5axis_1.ytr;
    zp1a = a5axis_1.zp1 - c5axis_1.test * c5axis_1.ztr;
/* ... */
/* ...     OBTAIN CORNER CLEAN-OUT ENDING POSITION            ***** 2***** */
    a3fxd1_1.x2 = a5axis_1.xp3;
    a3fxd1_1.y2 = a5axis_1.yp3;
    c5axis_1.z2 = a5axis_1.zp3;
    c5axis_1.stang = b5axis_1.wcorn7;
    c5axis_1.dlngth = 0.;
    c5axis_1.xcv = a5axis_1.xcv3;
    c5axis_1.ycv = a5axis_1.ycv3;
    c5axis_1.zcv = a5axis_1.zcv3;
    tachck_1.xxxxta = 0.;
    tachck_1.yyyyta = 0.;
    tachck_1.zzzzta = 0.;
    tachck_1.chingx = 0.;
    tachck_1.chingy = 0.;
    tachck_1.chingz = 0.;
    compu1_();
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L20;
    }
L20:
    a5axis_1.xta3 = c5axis_1.xta;
    a5axis_1.yta3 = c5axis_1.yta;
    a5axis_1.zta3 = c5axis_1.zta;
    c5axis_1.ztr = 0.;
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L21;
    } else {
	goto L22;
    }
L21:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L22:
    c5axis_1.test = c5axis_1.cutter / cos((abs(c5axis_1.cang))) - 
	    c5axis_1.cutter;
    xp3a = a5axis_1.xp3 - c5axis_1.test * c5axis_1.xtr;
    yp3a = a5axis_1.yp3 - c5axis_1.test * c5axis_1.ytr;
    zp3a = a5axis_1.zp3 - c5axis_1.test * c5axis_1.ztr;
/* ... */
/* ...     OBTAIN TLAXIS IN CORNER (TA2 = PL3 X PL1)          ***** 3***** */
    avcros_(&a5axis_1.zta1, &a5axis_1.zcv1, &b5axis_1.zpl1);
    avnorm_(&b5axis_1.zpl1, &b5axis_1.zpl1, &ier);
    if (ier != 0) {
	goto L23;
    } else {
	goto L24;
    }
L23:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L24:
    avcros_(&a5axis_1.zta3, &a5axis_1.zcv3, &b5axis_1.zpl3);
    avnorm_(&b5axis_1.zpl3, &b5axis_1.zpl3, &ier);
    if (ier != 0) {
	goto L25;
    } else {
	goto L26;
    }
L25:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L26:
    avcros_(&b5axis_1.zpl3, &b5axis_1.zpl1, &a5axis_1.zta2);
    avnorm_(&a5axis_1.zta2, &a5axis_1.zta2, &ier);
    if (ier != 0) {
	goto L27;
    } else {
	goto L28;
    }
L27:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L28:
/* ...     MAKE TA2 POSZ */
    if (a5axis_1.zta2 >= 0.) {
	goto L40;
    } else {
	goto L30;
    }
L30:
    a5axis_1.xta2 = -a5axis_1.xta2;
    a5axis_1.yta2 = -a5axis_1.yta2;
    a5axis_1.zta2 = -a5axis_1.zta2;
/* ... */
/* ...    OBTAIN CUTTER LOCATION IN CORNER                    ***** 4***** */
L40:
    if (abs(a5axis_1.zcv1) - 1e-4 <= 0.) {
	goto L35;
    } else {
	goto L31;
    }
L31:
    b5axis_1.s1 = a5axis_1.ycv1 / a5axis_1.xcv1;
    if (abs(a5axis_1.xcv3) - 1e-4 <= 0.) {
	goto L32;
    } else {
	goto L33;
    }
L32:
    xp2a = xp3a;
    goto L34;
L33:
    b5axis_1.s3 = a5axis_1.ycv3 / a5axis_1.xcv3;
    xp2a = (yp3a - yp1a + b5axis_1.s1 * xp1a - b5axis_1.s3 * xp3a) / (
	    b5axis_1.s1 - b5axis_1.s3);
L34:
    yp2a = b5axis_1.s1 * (xp2a - xp1a) + yp1a;
    goto L36;
L35:
    xp2a = xp1a;
    b5axis_1.s3 = a5axis_1.ycv3 / a5axis_1.xcv3;
    yp2a = b5axis_1.s3 * (xp2a - xp3a) + yp3a;
L36:
    zp2a = zp1a;
/* ... */
/* ... */
/* ...    BEGIN MOVE INTO CORNER                              ***** 5***** */
/* L38: */
    b5axis_1.ai = 0.;
    b5axis_1.xp2i = xp2a - xp1a;
    b5axis_1.yp2i = yp2a - yp1a;
    b5axis_1.zp2i = zp2a - zp1a;
    a5axis_1.xta2i = a5axis_1.xta2 - a5axis_1.xta1;
    a5axis_1.yta2i = a5axis_1.yta2 - a5axis_1.yta1;
    a5axis_1.zta2i = a5axis_1.zta2 - a5axis_1.zta1;
/* ... */
/* ...    IF VERY SMALL CHANGE,GO DIRECTLY TO CORNER POSITION */
    if (abs(b5axis_1.xp2i) - 5e-4 <= 0.) {
	goto L41;
    } else {
	goto L47;
    }
L41:
    if (abs(b5axis_1.yp2i) - 5e-4 <= 0.) {
	goto L42;
    } else {
	goto L47;
    }
L42:
    if (abs(b5axis_1.zp2i) - 5e-4 <= 0.) {
	goto L43;
    } else {
	goto L47;
    }
L43:
    if (abs(a5axis_1.xta2i) - 5e-4 <= 0.) {
	goto L44;
    } else {
	goto L47;
    }
L44:
    if (abs(a5axis_1.yta2i) - 5e-4 <= 0.) {
	goto L45;
    } else {
	goto L47;
    }
L45:
    if (abs(a5axis_1.zta2i) - 5e-4 <= 0.) {
	goto L46;
    } else {
	goto L47;
    }
L46:
    b5axis_1.ai = b5axis_1.wcorn9 + 1.;
    b5axis_1.xp2i = xp2a;
    b5axis_1.yp2i = yp2a;
    b5axis_1.zp2i = zp2a;
    a5axis_1.xta2i = a5axis_1.xta2;
    a5axis_1.yta2i = a5axis_1.yta2;
    a5axis_1.zta2i = a5axis_1.zta2;
    goto L140;
/* ... */
/* ...    ITERATE INTO CORNER */
L47:
    wcorn = b5axis_1.wcorn9;
L48:
    c5axis_1.test = 1. / wcorn;
    b5axis_1.xdp = c5axis_1.test * b5axis_1.xp2i;
    b5axis_1.ydp = c5axis_1.test * b5axis_1.yp2i;
    b5axis_1.zdp = c5axis_1.test * b5axis_1.zp2i;
    a5axis_1.xdta = c5axis_1.test * a5axis_1.xta2i;
    a5axis_1.ydta = c5axis_1.test * a5axis_1.yta2i;
    a5axis_1.zdta = c5axis_1.test * a5axis_1.zta2i;
/* ...    WHEN CHANGE IS SMALL, GO DIRECTLY INTO CORNER */
    if (abs(b5axis_1.xdp) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L50;
    }
L50:
    if (abs(b5axis_1.ydp) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L51;
    }
L51:
    if (abs(b5axis_1.zdp) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L52;
    }
L52:
    if (abs(a5axis_1.xdta) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L53;
    }
L53:
    if (abs(a5axis_1.ydta) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L54;
    }
L54:
    if (abs(a5axis_1.zdta) - 5e-4 >= 0.) {
	goto L56;
    } else {
	goto L55;
    }
L55:
    wcorn += -1.;
    if (wcorn - .1 <= 0.) {
	goto L46;
    } else {
	goto L48;
    }
L56:
    b5axis_1.xp2i = xp1a + b5axis_1.ai * b5axis_1.xdp;
    b5axis_1.yp2i = yp1a + b5axis_1.ai * b5axis_1.ydp;
    b5axis_1.zp2i = zp1a + b5axis_1.ai * b5axis_1.zdp;
/* L130: */
    a5axis_1.xta2i = a5axis_1.xta1 + b5axis_1.ai * a5axis_1.xdta;
    a5axis_1.yta2i = a5axis_1.yta1 + b5axis_1.ai * a5axis_1.ydta;
    a5axis_1.zta2i = a5axis_1.zta1 + b5axis_1.ai * a5axis_1.zdta;
    avnorm_(&a5axis_1.zta2i, &a5axis_1.zta2i, &ier);
    if (ier != 0) {
	goto L131;
    } else {
	goto L132;
    }
L131:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L132:
/* ...    OBTAIN ITERATIVE CUTTER POSITION */
L140:
    corner_();
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L150;
    }
L150:
    b5axis_1.ai += 1.;
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = c5axis_1.xcc;
    a3fxd1_1.tapsto[3] = c5axis_1.ycc;
    a3fxd1_1.tapsto[4] = c5axis_1.zcc;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    CHECK FOR TRACUT AND COPY */
    trcpm_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L151;
    }
L151:
/* ...    OUTPUT NUCLTP RECORD */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &c__4, &a3fxi1_1.irecno, &c__1, &
	    a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2, &c__1, a3fxd1_1.tapsto, 
	    &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L180;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L160;
    } else {
	goto L170;
    }
L160:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L170:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L180:
    clprnt_();
    ++a3fxi1_1.nurcno;
    if (b5axis_1.ai - .9 - wcorn >= 0.) {
	goto L181;
    } else {
	goto L56;
    }
/* ... */
/* ... */
/* ...    CORNER POSITION ATTAINED.                           ***** 6***** */
/* ...    PRINT INFO ABOUT IT */
L181:
    b5axis_1.ai = atan(a5axis_1.xta2 / a5axis_1.zta2) * 57.2957795131;
    c5axis_1.test = atan(a5axis_1.yta2 / a5axis_1.zta2) * 57.2957795131;
    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    do_fio(&c__1, (char *)&b5axis_1.ai, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L187: */
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    do_fio(&c__1, (char *)&c5axis_1.test, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* L190: */
    io___18.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___18);
    e_wsfe();
/* ... */
/* ... */
/* ...    COPY NON-MOTION CLTAPE RECORDS UP TO ONE            ***** 7***** */
/* ...    CONTAINING ENDING POSITION. */
L196:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
//    astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L200;
    } else {
	goto L210;
    }
L200:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L440;
L210:
    if (a3fxi1_1.irecno - a5fxis_1.ip3b >= 0) {
	goto L220;
    } else {
	goto L240;
    }
L220:
    aserch_(&ataptb_1.cltape, &a5fxis_1.ip3b, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L230;
    } else {
	goto L290;
    }
L230:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L440;
L240:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L250;
    } else {
	goto L196;
    }
L250:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    tapewt_(nucltp, &a3fxi1_1.iretvr, &c__4, &a3fxi1_1.irecno, &c__1, &
	    a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2, &c__1, a3fxd1_1.tapsto, 
	    &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L280;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L270;
    } else {
	goto L260;
    }
L260:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L270:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L280:
    clprnt_();
    ++a3fxi1_1.nurcno;
    goto L196;
/* ... */
/* ... */
/* ...    START CLIMB OUT.                                    ***** 8***** */
L290:
    b5axis_1.ai = 1.;
    a3fxi1_1.numwds = 8;
    b5axis_1.xp2i = xp3a - xp2a;
    b5axis_1.yp2i = yp3a - yp2a;
    b5axis_1.zp2i = zp3a - zp2a;
    a5axis_1.xta2i = a5axis_1.xta3 - a5axis_1.xta2;
    a5axis_1.yta2i = a5axis_1.yta3 - a5axis_1.yta2;
    a5axis_1.zta2i = a5axis_1.zta3 - a5axis_1.zta2;
/* ...    IF VERY SMALL CHANGE, GO TO ENDING POSITION DIRECTLY */
    if (abs(b5axis_1.xp2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L291;
    }
L291:
    if (abs(b5axis_1.yp2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L292;
    }
L292:
    if (abs(b5axis_1.zp2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L293;
    }
L293:
    if (abs(a5axis_1.xta2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L294;
    }
L294:
    if (abs(a5axis_1.yta2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L295;
    }
L295:
    if (abs(a5axis_1.zta2i) - 5e-4 >= 0.) {
	goto L296;
    } else {
	goto L350;
    }
/* ... */
/* ...    ITERATE TO ENDING POSITION */
L296:
    wcorn = b5axis_1.wcorn9;
L297:
    c5axis_1.test = 1. / wcorn;
    b5axis_1.xdp = c5axis_1.test * b5axis_1.xp2i;
    b5axis_1.ydp = c5axis_1.test * b5axis_1.yp2i;
    b5axis_1.zdp = c5axis_1.test * b5axis_1.zp2i;
    a5axis_1.xdta = c5axis_1.test * a5axis_1.xta2i;
    a5axis_1.ydta = c5axis_1.test * a5axis_1.yta2i;
    a5axis_1.zdta = c5axis_1.test * a5axis_1.zta2i;
/* ...    WHEN CHANGE IS SMALL, GO DIRECTLY TO ENDING POSITION */
    if (abs(b5axis_1.xdp) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L301;
    }
L301:
    if (abs(b5axis_1.ydp) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L302;
    }
L302:
    if (abs(b5axis_1.zdp) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L303;
    }
L303:
    if (abs(a5axis_1.xdta) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L304;
    }
L304:
    if (abs(a5axis_1.ydta) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L305;
    }
L305:
    if (abs(a5axis_1.zdta) - 5e-4 >= 0.) {
	goto L308;
    } else {
	goto L306;
    }
L306:
    wcorn += -1.;
    if (wcorn - .1 <= 0.) {
	goto L350;
    } else {
	goto L297;
    }
L308:
    a5axis_1.xta2i = a5axis_1.xta2 + b5axis_1.ai * a5axis_1.xdta;
    a5axis_1.yta2i = a5axis_1.yta2 + b5axis_1.ai * a5axis_1.ydta;
    a5axis_1.zta2i = a5axis_1.zta2 + b5axis_1.ai * a5axis_1.zdta;
    b5axis_1.xp2i = xp2a + b5axis_1.ai * b5axis_1.xdp;
    b5axis_1.yp2i = yp2a + b5axis_1.ai * b5axis_1.ydp;
    b5axis_1.zp2i = zp2a + b5axis_1.ai * b5axis_1.zdp;
    avnorm_(&a5axis_1.zta2i, &a5axis_1.zta2i, &ier);
    if (ier != 0) {
	goto L311;
    } else {
	goto L312;
    }
L311:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L440;
L312:
/* ...    OBTAIN ITERATIVE CUTTER POSITION */
    corner_();
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L310;
    }
L310:
    b5axis_1.ai += 1.;
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = c5axis_1.xcc;
    a3fxd1_1.tapsto[3] = c5axis_1.ycc;
    a3fxd1_1.tapsto[4] = c5axis_1.zcc;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    CHECK FOR TRACUT AND COPY */
    trcpm_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L440;
    } else {
	goto L319;
    }
L319:
/* ...    OUTPUT NUCLTP RECORD */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &c__4, &a3fxi1_1.irecno, &c__1, &
	    a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2, &c__1, a3fxd1_1.tapsto, 
	    &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L340;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L320;
    } else {
	goto L330;
    }
L320:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L330:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L440;
L340:
    clprnt_();
    ++a3fxi1_1.nurcno;
    if (b5axis_1.ai - wcorn - .01 <= 0.) {
	goto L308;
    } else {
	goto L350;
    }
/* ... */
/* ... */
/* ...    CLEAN-OUT FINISHED.                                 ***** 9***** */
/* ...    RESET COMMON VARIABLES */
L350:
    a3fxd1_1.x1 = a5axis_1.xp3;
    a3fxd1_1.y1 = a5axis_1.yp3;
    c5axis_1.z1 = a5axis_1.zp3;
    c5axis_1.stang = b5axis_1.wcorn7;
    c5axis_1.dlngth = 0.;
    c5axis_1.tlngth = b5axis_1.tlnth2;
    c5axis_1.dang = b5axis_1.wtlxs6 - c5axis_1.stang;
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &c__4, &
	    a3fxi1_1.irecno, &c__1, &a3fxi1_1.instr1, &c__1, &a3fxi1_1.instr2,
	     &c__1, a3fxd1_1.tapsto, &c__0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L360;
    } else {
	goto L370;
    }
L360:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L440;
L370:
    if ((d__1 = a5axis_1.xp3 - a5axis_1.xp3b, abs(d__1)) - .05 <= 0.) {
	goto L380;
    } else {
	goto L430;
    }
L380:
    if ((d__1 = a5axis_1.yp3 - a5axis_1.yp3b, abs(d__1)) - .05 <= 0.) {
	goto L390;
    } else {
	goto L430;
    }
L390:
    if ((d__1 = a5axis_1.zp3 - a5axis_1.zp3b, abs(d__1)) - .05 <= 0.) {
	goto L400;
    } else {
	goto L430;
    }
L400:
    a5fxis_1.ip3bi += 6;
    if (a5fxis_1.ip3bi - a3fxi1_1.numwds >= 0) {
	goto L420;
    } else {
	goto L430;
    }
L420:
    a3fxi1_1.irecno = 0;
    goto L440;
L430:
    a5fxis_1.iiii = a5fxis_1.ip3bi;
    a3fxi1_1.irecno = -1;
L440:
    return 0;
} /* compu2_ */

#undef lclprt
#undef nucltp
#undef irr
#undef arr


