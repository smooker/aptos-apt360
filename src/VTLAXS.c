/* VTLAXS.f -- translated by f2c (version 20000121).
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
    integer is, ir, il, ie, jsuber, iabove, isuber;
} c5fxis_;

#define c5fxis_1 c5fxis_

struct {
    doublereal xxxxta, yyyyta, zzzzta, chingx, chingy, chingz;
} tachck_;

#define tachck_1 tachck_

/* Table of constant values */

static integer c__8 = 8;
static integer c__4 = 4;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;

/* Subroutine */ int vtlaxs_()
{
    /* Initialized data */

    static integer ibits = -1;
    static integer mask = -1;
    static integer ivtlon = 0;

    /* Format strings */
    static char fmt_91[] = "(\0020*****************  SECTION 3 5AXIS ERROR N\
UMBER \002,i5,\002  *******************\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(), sin(), cos();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, ix2;
#define arr ((doublereal *)&a3fxd1_1)
    static integer ier;
#define irr ((integer *)&a3fxi1_1)
    extern /* Subroutine */ int fp1p3_();
    static doublereal tcos, tsin;
    static integer inum;
    extern integer ixor_();
    static doublereal tsin1;
    static integer jflag;
    static doublereal arads;
    extern /* Subroutine */ int trcpm_();
    static integer itest;
    extern /* Subroutine */ int compu_(), trcpv_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    static integer lwtlxs;
    extern /* Subroutine */ int astore_(), aserch_(), taperd_(), tapeop_(), 
	    bufftp_(), avcros_(), avnorm_(), tapewt_(), clprnt_();

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 0, fmt_91, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ...    VTLAXS IS CALLED FROM ASECN3 WHEN A VTLAXS CLTAPE */
/* ...    RECORD IS ENCOUNTERED.  CONTROL IS RETAINED UNTIL */
/* ...    A VTLAXS/OFF IS ENCOUNTERED. */
/* ...    VTLAXS ALTERS CLTAPE POINTS AND TOOL AXIS VECTORS */
/* ...    BY PRORATING THE DIFFERENCE BETWEEN THE STARTING AND */
/* ...    ENDING ANGLES ALONG THE SUM OF CUT VECTORS FOR */
/* ...    SWARF CUTTING.  CORNER TRANSITION IS ACCOMPLISHED */
/* ...    BY WCORN. */
/* ******************************************************************** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ******************************************************************** */
/*      DATA IBITS/ZFFFFFFFF/, MASK/ZFFFFFFFF/, IVTLON/0/ */
/* ... */
    tachck_1.xxxxta = 0.;
    tachck_1.yyyyta = 0.;
    tachck_1.zzzzta = 0.;
    tachck_1.chingx = 0.;
    tachck_1.chingy = 0.;
    tachck_1.chingz = 0.;
    arads = 57.2957795131;
/* ...    PROCESS VTLAXS/ON AND INITIALIZE VARIABLES          ***** 1***** */
    c5fxis_1.jsuber = 0;
    a5fxis_1.icorn1 = 0;
    a5fxis_1.iflag1 = 0;
    a5fxis_1.iiii = a0con_1.k3;
    jflag = 0;
    c5fxis_1.ie = a3fxi1_1.irecno + a0con_1.k1;
    if (a3fxi1_1.i1 == 71) {
	goto L18;
    }
    ++a3fxi1_1.nurcno;
    if (ivtlon == 1) {
	goto L1000;
    }
/* L10: */
    c5fxis_1.jsuber = 15;
/* ...    ERROR 15 - A VTLAXS/OFF COMMAND WAS GIVEN WITHOUT A */
/* ...               PREVIOUS VTLAXS/ON COMMAND. */
    goto L990;
/*     INCOMPLETE VTLAXS/ON STATEMENT */
L15:
    c5fxis_1.jsuber = 40;
    ++a3fxi1_1.nurcno;
    goto L990;
L18:
    ivtlon = 1;
    if (a3fxi1_1.numwds < 6) {
	goto L15;
    }
/* L20: */
    itest = ibits;
    lwtlxs = 1;
/* ...    GET STARTING ANGLE */
    c5axis_1.stang = a3fxd1_1.tapsto[2] / arads;
    c5fxis_1.ir = a3fxi1_1.irecno;
/* ...    IS TILT RIGHT(24) OR LEFT */
    if (a3fxi1_1.i2 - 24 != 0) {
	goto L40;
    } else {
	goto L30;
    }
L30:
    c5axis_1.stang = -c5axis_1.stang;
/* ...    STORE HALF CUTTER DIAMETER AND CORNER RADIUS */
L40:
    c5axis_1.cutter = abs(a3fxd1_1.tapsto[3]) * .5;
    c5axis_1.cradus = a3fxd1_1.tapsto[4];
    if (c5axis_1.cradus - c5axis_1.cutter <= 1e-12) {
	goto L45;
    }
/* L41: */
    c5fxis_1.jsuber = 21;
/* ...    ERROR 21 - CORNER RADIUS IS GREATER THAN THE CUTTER RADIUS. */
    ++a3fxi1_1.nurcno;
    goto L990;
L45:
//    astore_(&a3fxd1_1.tapsto[5], &c__8, &a3fxi1_1.it, &c__4);
a3fxi1_.it=*((integer*)(&a3fxd1_.tapsto[5]));
/* ...    IS CUTTER ORIENTATION RIGHT(24) OR LEFT */
    if (a3fxi1_1.it - 24 != 0) {
	goto L50;
    } else {
	goto L60;
    }
L50:
    c5axis_1.zun = -1.;
    goto L70;
L60:
    c5axis_1.zun = 1.;
L70:
    c5axis_1.yun = 0.;
    c5axis_1.xun = 0.;
/* ...    LOOK FOR ZSMALL */
    if (a3fxi1_1.numwds - 7 >= 0) {
	goto L65;
    } else {
	goto L67;
    }
L65:
//    astore_(&a3fxd1_1.tapsto[6], &a0con_1.k8, &a3fxi1_1.it, &a0con_1.k4);
a3fxi1_.it=*((integer*)(&a3fxd1_.tapsto[6]));
    if (a3fxi1_1.it - 40 != 0) {
	goto L67;
    } else {
	goto L66;
    }
L66:
    if (c5axis_1.cradus != 0.) {
	goto L5005;
    } else {
	goto L5010;
    }
L5005:
    c5fxis_1.jsuber = 22;
/* ...    ERROR 22 - CORNER RADIUS MUST BE ZERO WHEN USING ZSMALL. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    SET IABOVE=1 FOR ZSMALL, =0 FOR NOT */
L5010:
    c5fxis_1.iabove = 1;
    goto L68;
L67:
    c5fxis_1.iabove = 0;
L68:
    c5axis_1.tlngth = 0.;
    c5axis_1.xd = 0.;
    c5axis_1.yd = 0.;
    c5axis_1.zd = 0.;
    c5fxis_1.is = ibits;
    if (a3fxi1_1.multax - 1 != 0) {
	goto L72;
    } else {
	goto L74;
    }
L72:
    c5fxis_1.jsuber = 19;
/* ...    ERROR 19 - A MULTAX COMMAND WAS NOT GIVEN IN THE PROGRAM. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ... */
/* ... */
/* ...    SEARCH FOR PREVIOUS MOTION RECORD ON CLTAPE         ***** 2***** */
L74:
    c5fxis_1.il = c5fxis_1.ir;
L80:
    --c5fxis_1.il;
    if (c5fxis_1.il <= 0) {
	goto L140;
    } else {
	goto L85;
    }
L85:
    aserch_(&ataptb_1.cltape, &c5fxis_1.il, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr != 0) {
	goto L100;
    } else {
	goto L90;
    }
L90:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    ++a3fxi1_1.nurcno;
    goto L990;
L100:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &a0con_1.k4,
	     &a3fxi1_1.irecno, &a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &
	    a3fxi1_1.instr2, &c__1, a3fxd1_1.tapsto, &a0con_1.k0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));

    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));

    if (a3fxi1_1.iretvr >= 0) {
	goto L110;
    } else {
	goto L120;
    }
L110:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    CHECK RECORD FOR TYPE - MOTION(5000),AUX(2000) */
L120:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L122;
    } else {
	goto L150;
    }
L122:
    if (a3fxi1_1.instr1 - 2000 != 0) {
	goto L130;
    } else {
	goto L124;
    }
/* ...    IS IT VTLAXS(1070) */
L124:
    if (a3fxi1_1.instr2 - 1070 != 0) {
	goto L141;
    } else {
	goto L126;
    }
/* ...    CHECK FOR OFF(72) */
L126:
    if (a3fxi1_1.i1 - 72 != 0) {
	goto L130;
    } else {
	goto L128;
    }
/* ...    PREVIOUS MOTION WAS IN VTLAXS SEQ. SET LWTLXS */
L128:
    lwtlxs = 0;
/* ...    BACKSPACE ANOTHER RECORD ON CLTAPE */
L130:
    if (c5fxis_1.il <= 0) {
	goto L140;
    } else {
	goto L80;
    }
L140:
    c5fxis_1.jsuber = 18;
/* ...    ERROR 18 - A VTLAXS COMMAND WAS GIVEN WITHOUT A */
/* ...               PREVIOUS MOTION OR FROM COMMAND. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    IS IT INDEX(1039) */
L141:
    if (a3fxi1_1.instr2 - 1039 != 0) {
	goto L130;
    } else {
	goto L142;
    }
L142:
    if (a3fxi1_1.i1 - a3fxi1_1.indxno[0] != 0) {
	goto L130;
    } else {
	goto L143;
    }
L143:
    if (a3fxi1_1.icopy <= 0) {
	goto L130;
    } else {
	goto L144;
    }
L144:
    asistm_1.iwaven = 1;
    asistm_1.indexx = 0;
    asistm_1.iplotr = 0;
    asistm_1.iclprt = 1;
    c5fxis_1.jsuber = 31;
/* ...    ERROR 31 - THE CURRENT COPY INDEX APPEARED BETWEEN A VTLAXS/ON */
/* ...               AND THE MOTION JUST PRIOR TO THE VTLAXS/ON. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    MOTION RECORD FOUND. PROCESS IT */
L150:
    i__ = a3fxi1_1.instr2;
    switch ((int)i__) {
	case 1:  goto L130;
	case 2:  goto L130;
	case 3:  goto L160;
	case 4:  goto L180;
	case 5:  goto L200;
	case 6:  goto L200;
    }
/* ...    FROM */
L160:
    c5axis_1.xstart = a3fxd1_1.tapsto[2] + c5axis_1.xd;
    c5axis_1.ystart = a3fxd1_1.tapsto[3] + c5axis_1.yd;
    c5axis_1.zstart = a3fxd1_1.tapsto[4] + c5axis_1.zd;
    itest = ixor_(&c5fxis_1.is, &mask);
    if (itest != a0con_1.k0) {
	goto L250;
    }
/* L170: */
    c5fxis_1.is = a3fxi1_1.irecno;
    a5fxis_1.ii = 3;
    goto L250;
/* ...    GODLTA */
L180:
    c5axis_1.xd = a3fxd1_1.tapsto[2] + c5axis_1.xd;
    c5axis_1.yd = a3fxd1_1.tapsto[3] + c5axis_1.yd;
    c5axis_1.zd = a3fxd1_1.tapsto[4] + c5axis_1.zd;
    itest = ixor_(&c5fxis_1.is, &mask);
    if (itest != a0con_1.k0) {
	goto L130;
    }
/* L190: */
    c5fxis_1.is = a3fxi1_1.irecno;
    a5fxis_1.ii = 3;
    goto L130;
/* ...    GOTO, CONT'D GOTO */
L200:
    itest = ixor_(&c5fxis_1.is, &mask);
    if (itest != a0con_1.k0) {
	goto L240;
    }
/* ...    SAVE RECORD NO. AND COORDINATES */
/* L230: */
    c5fxis_1.is = a3fxi1_1.irecno;
    a5fxis_1.ii = a3fxi1_1.numwds - 5;
L240:
    c5axis_1.xstart = a3fxd1_1.tapsto[a3fxi1_1.numwds - 6] + c5axis_1.xd;
    c5axis_1.ystart = a3fxd1_1.tapsto[a3fxi1_1.numwds - 5] + c5axis_1.yd;
    c5axis_1.zstart = a3fxd1_1.tapsto[a3fxi1_1.numwds - 4] + c5axis_1.zd;
/* ... */
/* ... */
/* ...    START PROCESSING CLTAPE RECORDS FOLLOWING VTLAXS/ON ***** 3***** */
/* ...    TO FIND TOTAL LENGTH OF CUT VECTORS AND TOTAL */
/* ...    ANGLE CHANGE */
L250:
    a3fxd1_1.x1 = c5axis_1.xstart;
    a3fxd1_1.y1 = c5axis_1.ystart;
    c5axis_1.z1 = c5axis_1.zstart;
    a5fxis_1.icm = c5fxis_1.is;
    a5fxis_1.icmi = a5fxis_1.ii;
    a5axis_1.xlm = c5axis_1.xstart;
    a5axis_1.ylm = c5axis_1.ystart;
    a5axis_1.zlm = c5axis_1.zstart;
    a5fxis_1.ilm = c5fxis_1.is;
    a5fxis_1.ilmi = a5fxis_1.ii;
    i__ = c5fxis_1.ir + 1;
    ix2 = ibits;
    aserch_(&ataptb_1.cltape, &i__, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L260;
    } else {
	goto L270;
    }
L260:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    ++a3fxi1_1.nurcno;
    goto L990;
L270:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &a0con_1.k4,
	     &a3fxi1_1.irecno, &a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &
	    a3fxi1_1.instr2, &a0con_1.k1, a3fxd1_1.tapsto, &a0con_1.k0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);

a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr < 0) {
	goto L290;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L282;
    } else {
	goto L280;
    }
L280:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...  ERROR 15  END OF DATA BEFORE VTLAXS/OFF */
L282:
    c5fxis_1.jsuber = 15;
    ++a3fxi1_1.nurcno;
    goto L990;
L290:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L300;
    } else {
	goto L320;
    }
L300:
    if (a3fxi1_1.instr1 - 2000 != 0) {
	goto L270;
    } else {
	goto L310;
    }
/* ...    IS IT VTLAXS(1070),WCORN(1071),TRACUT(1038),COPY(1040) */
L310:
    if (a3fxi1_1.instr2 - 1070 != 0) {
	goto L315;
    } else {
	goto L410;
    }
L315:
    if (a3fxi1_1.instr2 - 1071 != 0) {
	goto L316;
    } else {
	goto L1100;
    }
L316:
    if (a3fxi1_1.instr2 - 1038 != 0) {
	goto L318;
    } else {
	goto L317;
    }
L317:
    c5fxis_1.jsuber = 32;
/* ...    ERROR 32 - TRACUT WAS GIVEN BETWEEN A VTLAXS/ON AND */
/* ...               ITS CORRESPONDING VTLAXS/OFF. */
    ++a3fxi1_1.nurcno;
    goto L321;
L318:
    if (a3fxi1_1.instr2 - 1040 != 0) {
	goto L270;
    } else {
	goto L319;
    }
L319:
    c5fxis_1.jsuber = 33;
/* ...    ERROR 33 - COPY WAS GIVEN BETWEEN A VTLAXS/ON AND */
/* ...               ITS CORRESPONDING VTLAXS/OFF. */
    ++a3fxi1_1.nurcno;
L321:
    asistm_1.iwaven = 1;
    asistm_1.indexx = 0;
    asistm_1.iplotr = 0;
    asistm_1.iclprt = 1;
    c5fxis_1.ie = a3fxi1_1.irecno;
    goto L990;
/* ...    MOTION RECORD */
L320:
    i__ = a3fxi1_1.instr2;
    switch ((int)i__) {
	case 1:  goto L270;
	case 2:  goto L270;
	case 3:  goto L330;
	case 4:  goto L340;
	case 5:  goto L370;
	case 6:  goto L370;
    }
/* ...    FROM */
L330:
    c5fxis_1.jsuber = 17;
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    GODLTA */
L340:
    c5axis_1.xd = a3fxd1_1.tapsto[2];
    c5axis_1.yd = a3fxd1_1.tapsto[3];
    c5axis_1.zd = a3fxd1_1.tapsto[4];
    jflag = 1;
    itest = ixor_(&ix2, &mask);
    if (itest != a0con_1.k0) {
	goto L360;
    }
/* L350: */
    a3fxd1_1.x2 = a3fxd1_1.x1 + c5axis_1.xd;
    a3fxd1_1.y2 = a3fxd1_1.y1 + c5axis_1.yd;
    c5axis_1.z2 = c5axis_1.z1 + c5axis_1.zd;
    ix2 = a3fxi1_1.irecno;
L360:
    a5axis_1.xlm = a3fxd1_1.x1;
    a5axis_1.ylm = a3fxd1_1.y1;
    a5axis_1.zlm = c5axis_1.z1;
    a5fxis_1.ilm = a5fxis_1.icm;
    a5fxis_1.ilmi = a5fxis_1.icmi;
/* Computing 2nd power */
    d__1 = c5axis_1.xd;
/* Computing 2nd power */
    d__2 = c5axis_1.yd;
/* Computing 2nd power */
    d__3 = c5axis_1.zd;
    c5axis_1.tlngth += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    a3fxd1_1.x1 += c5axis_1.xd;
    a3fxd1_1.y1 += c5axis_1.yd;
    c5axis_1.z1 += c5axis_1.zd;
    a5fxis_1.icmi = 3;
    a5fxis_1.icm = a3fxi1_1.irecno;
    if (a5fxis_1.iflag1 != 0) {
	goto L365;
    } else {
	goto L270;
    }
L365:
    a5fxis_1.iflag1 = 0;
    a5axis_1.xp3 = a3fxd1_1.x1;
    a5axis_1.yp3 = a3fxd1_1.y1;
    a5axis_1.zp3 = c5axis_1.z1;
    a5fxis_1.ip3 = a5fxis_1.icm;
    a5fxis_1.ip3i = a5fxis_1.icmi;
    goto L270;
/* ...    GOTO, CONT'D GOTO */
L370:
    jflag = 1;
    itest = ixor_(&ix2, &mask);
    if (itest != a0con_1.k0) {
	goto L390;
    }
/* ...    SAVE POINT JUST AFTER VTLAXS/ON */
/* L380: */
    a3fxd1_1.x2 = a3fxd1_1.tapsto[2];
    a3fxd1_1.y2 = a3fxd1_1.tapsto[3];
    c5axis_1.z2 = a3fxd1_1.tapsto[4];
    ix2 = a3fxi1_1.irecno;
/* ...    CALCULATE TOTAL LENGTH OF MOVES */
L390:
    i__1 = a3fxi1_1.numwds;
    for (i__ = 3; i__ <= i__1; i__ += 6) {
	c5axis_1.xd = a3fxd1_1.tapsto[i__ - 1] - a3fxd1_1.x1;
	c5axis_1.yd = a3fxd1_1.tapsto[i__] - a3fxd1_1.y1;
	c5axis_1.zd = a3fxd1_1.tapsto[i__ + 1] - c5axis_1.z1;
/* Computing 2nd power */
	d__1 = c5axis_1.xd;
/* Computing 2nd power */
	d__2 = c5axis_1.yd;
/* Computing 2nd power */
	d__3 = c5axis_1.zd;
	c5axis_1.tlngth += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	a5fxis_1.ilmi = a5fxis_1.icmi;
	a5axis_1.xlm = a3fxd1_1.x1;
	a5axis_1.ylm = a3fxd1_1.y1;
	a5axis_1.zlm = c5axis_1.z1;
	a5fxis_1.ilm = a5fxis_1.icm;
	a3fxd1_1.x1 = a3fxd1_1.tapsto[i__ - 1];
	a3fxd1_1.y1 = a3fxd1_1.tapsto[i__];
	c5axis_1.z1 = a3fxd1_1.tapsto[i__ + 1];
	a5fxis_1.icmi = i__;
	a5fxis_1.icm = a3fxi1_1.irecno;
	if (a5fxis_1.iflag1 != 0) {
	    goto L395;
	} else {
	    goto L400;
	}
L395:
	a5fxis_1.iflag1 = 0;
	a5axis_1.xp3 = a3fxd1_1.x1;
	a5axis_1.yp3 = a3fxd1_1.y1;
	a5axis_1.zp3 = c5axis_1.z1;
	a5fxis_1.ip3 = a5fxis_1.icm;
	a5fxis_1.ip3i = a5fxis_1.icmi;
L400:
	;
    }
    goto L270;
/* ...    IS THIS VTLAXS/OFF(72) */
L410:
    if (a3fxi1_1.i1 - 72 != 0) {
	goto L420;
    } else {
	goto L430;
    }
L420:
    c5fxis_1.jsuber = 16;
/* ...    ERROR 16 - TWO VTLAXS/ON COMMANDS GIVEN WITHOUT A */
/* ...               VTLAXS/OFF BETWEEN THEM. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    VTLAXS/OFF. SAVE ENDING ANGLE */
L430:
    c5axis_1.endang = a3fxd1_1.tapsto[2] / arads;
    c5fxis_1.ie = a0con_1.k1 + a3fxi1_1.irecno;
/* ...    IS TILT RIGHT(24) OR LEFT */
    if (a3fxi1_1.i2 - 24 != 0) {
	goto L445;
    } else {
	goto L440;
    }
L440:
    c5axis_1.endang = -c5axis_1.endang;
/* ...    HAS WCORN BEEN ENCOUNTERED. 0=NO */
L445:
    if (a5fxis_1.icorn1 != 0) {
	goto L446;
    } else {
	goto L450;
    }
/* ...    WAS THERE MOTION AFTER WCORN. 0=YES */
L446:
    if (a5fxis_1.iflag1 != 0) {
	goto L456;
    } else {
	goto L4462;
    }
L4462:
    b5axis_1.tlnth2 = c5axis_1.tlngth;
    b5axis_1.wtlxs6 = c5axis_1.endang;
    c5axis_1.endang = b5axis_1.wcorn5;
/* ...    PROCESS THROUGH CORNER IN FP1P3 */
    fp1p3_();
    if (c5fxis_1.jsuber != 0) {
	goto L447;
    } else {
	goto L448;
    }
L447:
    ++a3fxi1_1.nurcno;
    goto L990;
L448:
    c5axis_1.tlngth = b5axis_1.tlnth1;
L450:
    c5axis_1.dang = c5axis_1.endang - c5axis_1.stang;
    c5axis_1.dlngth = 0.;
    if (jflag != 0) {
	goto L457;
    } else {
	goto L455;
    }
L455:
    c5fxis_1.jsuber = 23;
/* ...    ERROR 23 - NO MOTION BETWEEN A VTLAXS/ON AND VTLAXS/OFF. */
    ++a3fxi1_1.nurcno;
    goto L990;
L456:
    c5fxis_1.jsuber = 30;
/* ...    ERROR 30 - NO MOTION BETWEEN WCORN AND VTLAXS/OFF. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ... */
/* ... */
/* ...    PREPARE CLTAPE AND NUCLTP FOR POINT REVISION        ***** 4***** */
/* ... */
/* ...    UPDATE NUCLTP RECORD NUMBER TO MOTION JUST */
/* ...    PRIOR TO VTLAXS/ON */
L457:
    a3fxi1_1.nurcno = a3fxi1_1.nurcno - c5fxis_1.ir + c5fxis_1.is + 1;
/* ...    LOCATE CLTAPE TO MOTION RECORD JUST PRIOR TO VTLAXS/ON */
    aserch_(&ataptb_1.cltape, &c5fxis_1.is, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L460;
    } else {
	goto L470;
    }
L460:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L990;
/* ...    WRITE EOF ON NUCLTP */
L470:
    tapeop_(nucltp, &c__2, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L475;
    } else {
	goto L478;
    }
L475:
    c5fxis_1.jsuber = 34;
/* ...    ERROR 34  - MACHINE ERROR. */
    goto L990;
L478:
    aserch_(nucltp, &a3fxi1_1.nurcno, &a3fxi1_1.iretvr);
    if (a3fxi1_1.iretvr >= 0) {
	goto L475;
    } else {
	goto L490;
    }
/* ...    PUT NUCLTP IN WRITE MODE */
L490:
    bufftp_(nucltp, &c__1);
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &a0con_1.k4,
	     &a3fxi1_1.irecno, &a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &
	    a3fxi1_1.instr2, &a0con_1.k1, a3fxd1_1.tapsto, &a0con_1.k0);
//    astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
 //   astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L500;
    } else {
	goto L510;
    }
L500:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L990;
L510:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L520;
    } else {
	goto L530;
    }
L520:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L990;
/* ... */
/* ... */
/* ...    CALCULATE VTLAXS REVISION OF POINT JUST PRIOR       ***** 5***** */
/* ...    TO VTLAXS/ON */
L530:
    a3fxd1_1.x1 = c5axis_1.xstart;
    a3fxd1_1.y1 = c5axis_1.ystart;
    c5axis_1.z1 = c5axis_1.zstart;
    tsin = sin(c5axis_1.stang);
    tsin1 = abs(tsin);
    tcos = cos(c5axis_1.stang);
    c5axis_1.xcv = a3fxd1_1.x2 - a3fxd1_1.x1;
    c5axis_1.ycv = a3fxd1_1.y2 - a3fxd1_1.y1;
    c5axis_1.zcv = c5axis_1.z2 - c5axis_1.z1;
/* ...    GET CROSS PRODUCT OF FIRST CUT VECTOR AND */
/* ...    VERTICAL TLAXIS VECTOR */
    avcros_(&c5axis_1.zcv, &c5axis_1.zun, &c5axis_1.ztr);
/* ...    NORMALIZE IT */
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L5012;
    } else {
	goto L5011;
    }
L5012:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L990;
L5011:
/* ...    SET NEW Z */
    if (c5axis_1.cradus != 0.) {
	goto L5020;
    } else {
	goto L5030;
    }
L5020:
    c5axis_1.z__ = c5axis_1.cradus * (1. - tcos) + (c5axis_1.cutter - 
	    c5axis_1.cradus) * tsin1;
    goto L5040;
L5030:
    c5axis_1.z__ = (d__1 = c5axis_1.cutter * tsin, abs(d__1));
/* ...    IS STARTING ANGLE .GT. 80 DEGREES */
L5040:
    if (tcos - .1736 <= 0.) {
	goto L535;
    } else {
	goto L5050;
    }
/* ...    DETERMINE TILT DIRECTION-SURFACE ORIENTATION COMBINATION */
L5050:
    if (c5axis_1.stang * c5axis_1.zun >= 0.) {
	goto L5080;
    } else {
	goto L532;
    }
/* ...    LEFT-LEFT OR RIGHT-RIGHT */
L532:
    if (c5axis_1.cradus != 0.) {
	goto L5070;
    } else {
	goto L5060;
    }
L5060:
    if (c5fxis_1.iabove != 0) {
	goto L533;
    } else {
	goto L536;
    }
L5070:
    c5axis_1.test = c5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.) / tcos) - 
	    c5axis_1.cutter * (tcos - 2. / tcos + 1.);
    c5axis_1.test = -c5axis_1.test;
    goto L539;
/* ...    LEFT-RIGHT OR RIGHT-LEFT */
L5080:
    if (c5axis_1.cradus != 0.) {
	goto L5090;
    } else {
	goto L538;
    }
L5090:
    c5axis_1.test = c5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.) / tcos) + 
	    c5axis_1.cutter * (1. - tcos);
    goto L539;
/* ...    ZSMALL */
L533:
    c5axis_1.z__ = -c5axis_1.z__;
    goto L538;
L535:
    c5fxis_1.jsuber = 20;
/* ...    ERROR 20 - TILT ANGLE GREATER THAN 80 DEGREES. */
    goto L990;
/* ...    NOT ZSMALL */
L536:
    c5axis_1.test = -(c5axis_1.cutter * 2. / tcos - c5axis_1.cutter - 
	    c5axis_1.cutter * tcos);
    goto L539;
L538:
    c5axis_1.test = c5axis_1.cutter * (1. - tcos);
L539:
    c5axis_1.xdo = c5axis_1.test * c5axis_1.xtr;
    c5axis_1.ydo = c5axis_1.test * c5axis_1.ytr;
    c5axis_1.zdo = c5axis_1.test * c5axis_1.ztr;
    c5axis_1.xcc = a3fxd1_1.x1 + c5axis_1.xdo;
    c5axis_1.ycc = a3fxd1_1.y1 + c5axis_1.ydo;
    c5axis_1.zcc = c5axis_1.z1 + c5axis_1.z__;
    c5axis_1.xtr = tcos * c5axis_1.xtr;
    c5axis_1.ytr = tcos * c5axis_1.ytr;
    if (c5axis_1.zun >= 0.) {
	goto L554;
    } else {
	goto L552;
    }
L552:
    c5axis_1.ztr = tsin;
    avcros_(&c5axis_1.zcv, &c5axis_1.ztr, &c5axis_1.zta);
    goto L556;
L554:
    c5axis_1.ztr = -tsin;
    avcros_(&c5axis_1.ztr, &c5axis_1.zcv, &c5axis_1.zta);
L556:
    avnorm_(&c5axis_1.zta, &c5axis_1.zta, &ier);
    if (ier != 0) {
	goto L557;
    } else {
	goto L558;
    }
L557:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L990;
L558:
/* ...  RESET FOR BEGINNING OF VTLAXIS SEQUENCE */
    tachck_1.xxxxta = 0.;
    tachck_1.yyyyta = 0.;
    tachck_1.zzzzta = 0.;
    tachck_1.chingx = 0.;
    tachck_1.chingy = 0.;
    tachck_1.chingz = 0.;
    i__ = a3fxi1_1.instr2;
    switch ((int)i__) {
	case 1:  goto L540;
	case 2:  goto L540;
	case 3:  goto L550;
	case 4:  goto L590;
	case 5:  goto L630;
	case 6:  goto L630;
    }
L540:
    c5fxis_1.jsuber = 38;
/* ...    ERROR 38  - MACHINE ERROR. */
    goto L990;
/* ...    FROM */
L550:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = c5axis_1.xcc;
    a3fxd1_1.tapsto[3] = c5axis_1.ycc;
    a3fxd1_1.tapsto[4] = c5axis_1.zcc;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    CHECK FOR TRACUT OR COPY */
    trcpm_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L990;
    } else {
	goto L551;
    }
L551:
/* ...    WRITE ALTERED PRIOR POINT ON NUCLTP (FROM/PT) */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L580;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L560;
    } else {
	goto L570;
    }
L560:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L570:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L580:
    clprnt_();
    ++a3fxi1_1.nurcno;
    goto L710;
/* ...    GODLTA */
L590:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = a3fxd1_1.tapsto[2] - c5axis_1.xcc + a3fxd1_1.x1;
    a3fxd1_1.tapsto[3] = a3fxd1_1.tapsto[3] - c5axis_1.ycc + a3fxd1_1.y1;
    a3fxd1_1.tapsto[4] = a3fxd1_1.tapsto[4] - c5axis_1.zcc + c5axis_1.z1;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    CHECK FOR TRACUT OR COPY */
    trcpv_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L990;
    } else {
	goto L591;
    }
L591:
/* ...    WRITE ALTERED PRIOR POINT ON NUCLTP (GODLTA) */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L620;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L600;
    } else {
	goto L610;
    }
L600:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L610:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L620:
    clprnt_();
    ++a3fxi1_1.nurcno;
    goto L710;
/* ...    GOTO, CONTD GOTO */
L630:
    if (a3fxi1_1.numwds - 8 <= 0) {
	goto L675;
    } else {
	goto L635;
    }
/* ...    WAS PREVIOUS MULTI-POINT RECORD IN A VTLAXS SEQ. 0=YES */
L635:
    if (lwtlxs != 0) {
	goto L640;
    } else {
	goto L675;
    }
L640:
    a3fxi1_1.numwds += -6;
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    i__1 = a3fxi1_1.numwds;
    for (i__ = 3; i__ <= i__1; i__ += 6) {
/* ...    TRACUT-COPY CHECK */
	trcpm_(&i__);
	if (c5fxis_1.jsuber != 0) {
	    goto L990;
	} else {
	    goto L641;
	}
L641:
/* L645: */
	;
    }
/* ...    WRITE ALTERED PRIOR RECORD ON NUCLTP (GOTO) */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L670;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L650;
    } else {
	goto L660;
    }
L650:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L660:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L670:
    clprnt_();
    ++a3fxi1_1.nurcno;
/* ...    SINGLE POINT OR MULTI-POINT WITH VTLAXS */
L675:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = c5axis_1.xcc;
    a3fxd1_1.tapsto[3] = c5axis_1.ycc;
    a3fxd1_1.tapsto[4] = c5axis_1.zcc;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
    a3fxi1_1.numwds = 8;
/* ...    TRACUT-COPY CHECK */
    trcpm_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L990;
    } else {
	goto L676;
    }
L676:
/* ...    WRITE ALTERED PRIOR POINT RECORD ON NUCLTP(GOTO) */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L700;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L680;
    } else {
	goto L690;
    }
L680:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L690:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L700:
    clprnt_();
    ++a3fxi1_1.nurcno;
/* ...    COPY CLTAPE RECORDS THROUGH VTLAXS/ON */
L710:
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &a0con_1.k4,
	     &a3fxi1_1.irecno, &a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &
	    a3fxi1_1.instr2, &a0con_1.k1, a3fxd1_1.tapsto, &a0con_1.k0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L720;
    } else {
	goto L730;
    }
L720:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L990;
/* ...    ARE WE PAST VTLAXS/ON RECORD */
L730:
    if (a3fxi1_1.irecno - c5fxis_1.ir <= 0) {
	goto L760;
    } else {
	goto L820;
    }
L760:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
/* ...    COPY RECORD */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L790;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L770;
    } else {
	goto L780;
    }
L770:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L780:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L790:
    clprnt_();
    ++a3fxi1_1.nurcno;
    goto L710;
/* ... */
/* ... */
/* ...    PROCESS RECORDS AFTER VTLAXS/ON.                    ***** 6***** */
L800:
    a5fxis_1.iiii = a0con_1.k3;
    taperd_(&ataptb_1.cltape, &a3fxi1_1.iretvr, &a3fxi1_1.numwds, &a0con_1.k4,
	     &a3fxi1_1.irecno, &a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &
	    a3fxi1_1.instr2, &a0con_1.k1, a3fxd1_1.tapsto, &a0con_1.k0);
    //astore_(a3fxd1_1.tapsto, &c__8, &a3fxi1_1.i1, &c__4);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[0]));
    //astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.i2, &c__4);
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.iretvr >= 0) {
	goto L810;
    } else {
	goto L820;
    }
L810:
    c5fxis_1.jsuber = 35;
/* ...    ERROR 35  - MACHINE ERROR. */
    goto L990;
L820:
    if (a3fxi1_1.instr1 - 5000 != 0) {
	goto L830;
    } else {
	goto L880;
    }
L830:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
/* ...    WRITE NON-MOTION RECORD ON NUCLTP */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L860;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L840;
    } else {
	goto L850;
    }
L840:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L850:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L860:
    clprnt_();
    ++a3fxi1_1.nurcno;
    if (a3fxi1_1.instr1 - 2000 != 0) {
	goto L800;
    } else {
	goto L870;
    }
/* ...    IS IT VTLAXS(1070) OR INDEX(1039) */
L870:
    if (a3fxi1_1.instr2 - 1070 != 0) {
	goto L872;
    } else {
	goto L1000;
    }
L872:
    if (a3fxi1_1.instr2 - 1039 != 0) {
	goto L800;
    } else {
	goto L873;
    }
/* ...    INDEX...TEST FOR NOMORE(53) */
L873:
//    astore_(&a3fxd1_1.tapsto[1], &c__8, &a3fxi1_1.it, &c__4);
a3fxi1_.it=*((integer*)(&a3fxd1_.tapsto[1]));
    if (a3fxi1_1.it - 53 != 0) {
	goto L800;
    } else {
	goto L874;
    }
L874:
    if (a3fxi1_1.icopy <= 0) {
	goto L800;
    } else {
	goto L875;
    }
L875:
    if (a3fxi1_1.i1 - a3fxi1_1.indxno[0] != 0) {
	goto L800;
    } else {
	goto L876;
    }
L876:
    aserch_(&ataptb_1.cltape, a3fxi1_1.irecni, &a3fxi1_1.iretvr);
    goto L1000;
/* ... */
/* ...    PROCESS A MOTION RECORD */
L880:
    i__ = a3fxi1_1.instr2;
    switch ((int)i__) {
	case 1:  goto L830;
	case 2:  goto L830;
	case 3:  goto L890;
	case 4:  goto L900;
	case 5:  goto L940;
	case 6:  goto L940;
    }
/* ...    FROM */
L890:
    c5fxis_1.jsuber = 17;
/* ...    ERROR 17 - A FROM COMMAND WAS GIVEN BETWEEN A VTLAXS/ON */
/* ...               COMMAND AND ITS CORRESPONDING VTLAXS/OFF COMMAND. */
    goto L990;
/* ...    GODLTA */
L900:
    a3fxd1_1.x2 = a3fxd1_1.x1 + a3fxd1_1.tapsto[2];
    a3fxd1_1.y2 = a3fxd1_1.y1 + a3fxd1_1.tapsto[3];
    c5axis_1.z2 = c5axis_1.z1 + a3fxd1_1.tapsto[4];
/* ...    CALCULATE NEW CUTTER LOCATION AND TLAXIS (GODLTA) */
    compu_();
    if (c5fxis_1.jsuber != 0) {
	goto L990;
    } else {
	goto L902;
    }
L902:
    if (a3fxi1_1.irecno < 0) {
	goto L903;
    } else if (a3fxi1_1.irecno == 0) {
	goto L800;
    } else {
	goto L905;
    }
L903:
    a3fxi1_1.irecno = a0con_1.k1;
    goto L940;
L905:
    a3fxi1_1.irecno = a3fxi1_1.nurcno;
    a3fxd1_1.tapsto[2] = a3fxd1_1.tapsto[2] - c5axis_1.xcc + a3fxd1_1.x1;
    a3fxd1_1.tapsto[3] = a3fxd1_1.tapsto[3] - c5axis_1.ycc + a3fxd1_1.y1;
    a3fxd1_1.tapsto[4] = a3fxd1_1.tapsto[4] - c5axis_1.zcc + c5axis_1.z1;
    a3fxd1_1.tapsto[5] = c5axis_1.xta;
    a3fxd1_1.tapsto[6] = c5axis_1.yta;
    a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    TRACUT-COPY CHECK */
    trcpv_(&c__3);
    if (c5fxis_1.jsuber != 0) {
	goto L990;
    } else {
	goto L906;
    }
L906:
/* ...    WRITE REVISED POINT ON NUCLTP (GODLTA) */
    tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
	    a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
	    a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
    if (a3fxi1_1.iretvr < 0) {
	goto L930;
    } else if (a3fxi1_1.iretvr == 0) {
	goto L910;
    } else {
	goto L920;
    }
L910:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L920:
    c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
    goto L990;
L930:
    clprnt_();
    ++a3fxi1_1.nurcno;
    a3fxd1_1.x1 = a3fxd1_1.x2;
    a3fxd1_1.y1 = a3fxd1_1.y2;
    c5axis_1.z1 = c5axis_1.z2;
    goto L800;
/* ...    GOTO, CONTD GOTO */
L940:
    inum = a3fxi1_1.numwds;
    a3fxi1_1.numwds = 8;
    i__1 = inum;
    for (i__ = a5fxis_1.iiii; i__ <= i__1; i__ += 6) {
	a3fxd1_1.x2 = a3fxd1_1.tapsto[i__ - 1];
	a3fxd1_1.y2 = a3fxd1_1.tapsto[i__];
	c5axis_1.z2 = a3fxd1_1.tapsto[i__ + 1];
/* ...    CALCULATE NEW CUTTER LOCATION AND TLAXIS (GOTO) */
	compu_();
	if (c5fxis_1.jsuber != 0) {
	    goto L990;
	} else {
	    goto L942;
	}
L942:
	if (a3fxi1_1.irecno < 0) {
	    goto L943;
	} else if (a3fxi1_1.irecno == 0) {
	    goto L800;
	} else {
	    goto L945;
	}
L943:
	a3fxi1_1.irecno = a0con_1.k1;
	goto L940;
L945:
	a3fxi1_1.irecno = a3fxi1_1.nurcno;
	a3fxd1_1.tapsto[2] = c5axis_1.xcc;
	a3fxd1_1.tapsto[3] = c5axis_1.ycc;
	a3fxd1_1.tapsto[4] = c5axis_1.zcc;
	a3fxd1_1.tapsto[5] = c5axis_1.xta;
	a3fxd1_1.tapsto[6] = c5axis_1.yta;
	a3fxd1_1.tapsto[7] = c5axis_1.zta;
/* ...    TRACUT-COPY CHECK */
	trcpm_(&c__3);
	if (c5fxis_1.jsuber != 0) {
	    goto L990;
	} else {
	    goto L946;
	}
L946:
/* ...    WRITE REVISED POINT ON NUCLTP (GOTO) */
	tapewt_(nucltp, &a3fxi1_1.iretvr, &a0con_1.k4, &a3fxi1_1.irecno, &
		a0con_1.k1, &a3fxi1_1.instr1, &a0con_1.k1, &a3fxi1_1.instr2, &
		a0con_1.k1, a3fxd1_1.tapsto, &a3fxi1_1.numwds);
	if (a3fxi1_1.iretvr < 0) {
	    goto L970;
	} else if (a3fxi1_1.iretvr == 0) {
	    goto L950;
	} else {
	    goto L960;
	}
L950:
	c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
	goto L990;
L960:
	c5fxis_1.jsuber = 36;
/* ...    ERROR 36  - MACHINE ERROR. */
	goto L990;
L970:
	clprnt_();
	++a3fxi1_1.nurcno;
	a3fxd1_1.x1 = a3fxd1_1.x2;
	a3fxd1_1.y1 = a3fxd1_1.y2;
	c5axis_1.z1 = c5axis_1.z2;
/* L980: */
    }
    goto L800;
/* ... */
/* ... */
/* ...    ERROR OUTPUT AND NORMAL RETURN                      ***** 7***** */
/* ...    LOCATE CLTAPE AT VTLAXS/ON+1,TRACUT,OR COPY */
L990:
    aserch_(&ataptb_1.cltape, &c5fxis_1.ie, &a3fxi1_1.iretvr);
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&c5fxis_1.jsuber, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L1002;
L1000:
    ivtlon = 0;
L1002:
    --a3fxi1_1.nurcno;
    return 0;
/* ... */
/* ... */
/* ...    WCORN                                               ***** 8***** */
L1100:
    if (a5fxis_1.icorn1 != 0) {
	goto L1105;
    } else {
	goto L1110;
    }
L1105:
    c5fxis_1.jsuber = 24;
/* ...    ERROR 24 - THERE IS MORE THAN ONE WCORN BETWEEN A */
/* ...               VTLAXS/ON AND ITS VTLAXS/OFF. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    WAS THERE MOTION BETWEEN VTLAXS/ON AND WCORN. 0=NO */
L1110:
    if (jflag != 0) {
	goto L1113;
    } else {
	goto L1112;
    }
L1112:
    c5fxis_1.jsuber = 29;
/* ...    ERROR 29 - NO MOTION BETWEEN VTLAXS/ON AND WCORN. */
    ++a3fxi1_1.nurcno;
    goto L990;
/* ...    PROCESS WCORN RECORD */
L1113:
    a5fxis_1.iflag1 = 1;
    a5axis_1.xp1 = a5axis_1.xlm;
    a5axis_1.yp1 = a5axis_1.ylm;
    a5axis_1.zp1 = a5axis_1.zlm;
    a5fxis_1.ip1 = a5fxis_1.ilm;
    a5fxis_1.ip1i = a5fxis_1.ilmi;
    b5axis_1.tlnth1 = c5axis_1.tlngth;
    c5axis_1.tlngth = 0.;
    a5axis_1.xp2 = a3fxd1_1.x1;
    a5axis_1.yp2 = a3fxd1_1.y1;
    a5axis_1.zp2 = c5axis_1.z1;
    a5fxis_1.ip2 = a5fxis_1.icm;
    a5fxis_1.ip2i = a5fxis_1.icmi;
    a5fxis_1.icorn1 = a3fxi1_1.irecno;
    b5axis_1.wcorn8 = a3fxd1_1.tapsto[4];
    b5axis_1.wcorn5 = a3fxd1_1.tapsto[1] / arads;
    if (a3fxi1_1.i1 - 24 != 0) {
	goto L1120;
    } else {
	goto L1115;
    }
L1115:
    b5axis_1.wcorn5 = -b5axis_1.wcorn5;
L1120:
    b5axis_1.wcorn7 = abs(a3fxd1_1.tapsto[3]) / arads;
//    astore_(&a3fxd1_1.tapsto[2], &c__8, &a3fxi1_1.it, &c__4);
a3fxi1_.it=*((integer*)(&a3fxd1_.tapsto[2]));
    if (a3fxi1_1.it - 24 != 0) {
	goto L1140;
    } else {
	goto L1130;
    }
L1130:
    b5axis_1.wcorn7 = -b5axis_1.wcorn7;
/* ...   CHECK IF ZSMALL WAS SPECIFIED ON VTLAXS/ON STATEMENT */
L1140:
    if (c5fxis_1.iabove != 1) {
	goto L1141;
    }
/* ...   CHECK FOR WCORN/LEFT,,LEFT OR WCORN/RIGHT,,RIGHT */
    if (a3fxd1_1.tapsto[0] == a3fxd1_1.tapsto[2]) {
	goto L1141;
    }
/* ...   CHECK IF WCORN INITAL TILT ANGLE IS ZERO */
    if (a3fxd1_1.tapsto[1] == 0. && b5axis_1.wcorn7 * c5axis_1.zun >= 0.) {
	goto L1141;
    }
/* ...   CHECK IF WCORN TERMINAL TILT ANGLE IS ZERO */
    if (a3fxd1_1.tapsto[3] == 0. && b5axis_1.wcorn5 * c5axis_1.zun >= 0.) {
	goto L1141;
    }
/* ...   WCORN ERROR - ZSMALL EFFECT NOT SAME WHEN ENTERING AND */
/* ...                 EXITING FROM CORNER */
    c5fxis_1.jsuber = 41;
    ++a3fxi1_1.nurcno;
    goto L990;
L1141:
    if (a3fxi1_1.numwds > 5) {
	goto L1160;
    }
/* L1150: */
    b5axis_1.wcorn9 = 6.;
    goto L270;
L1160:
    b5axis_1.wcorn9 = (doublereal) ((integer) abs(a3fxd1_1.tapsto[5]));
    if (b5axis_1.wcorn9 < 3.) {
	b5axis_1.wcorn9 = 3.;
    }
    goto L270;
} /* vtlaxs_ */

#undef lclprt
#undef nucltp
#undef irr
#undef arr


