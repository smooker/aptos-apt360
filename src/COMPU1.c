/* COMPU1.f -- translated by f2c (version 20000121).
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

struct {
    doublereal xxxxta, yyyyta, zzzzta, chingx, chingy, chingz;
} tachck_;

#define tachck_1 tachck_

/* Subroutine */ int compu1_()
{
    /* Format strings */
    static char fmt_99994[] = "(\002 \002,\002******************************\
****************************************************************************\
*********\002)";
    static char fmt_99996[] = "(\002 \002,\002** WARNING ... REVERSAL IN TOO\
L AXIS VECTOR COMPONENT(S) DETECTED.       CHECK FOR INFLECTION IN CUTTER PA\
TH.    **\002)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sin(), cos();
    integer s_wsfe(), e_wsfe();

    /* Local variables */
#define arr ((doublereal *)&a3fxd1_1)
    static integer ier;
#define irr ((integer *)&a3fxi1_1)
    static doublereal tcos, tsin, tsin1;
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    extern /* Subroutine */ int avcros_(), avnorm_();
    static doublereal difxta, difyta, difzta;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 0, 0, fmt_99994, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_99996, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_99994, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* ******************************************************************** */

/* ...    COMPU1 COMPUTES THE ALTERED TOOL POSITION FOR VTLAXS. */
/* ...    IT IS CALLED FROM COMPU AND COMPU2. */
/* ...    THE TILT ANGLE IS PRORATED OVER THE TOTAL MOVE FROM */
/* ...    VTLAXS/ON TO OFF, OR FROM VTLAXS/ON TO WCORN AND FROM */
/* ...    WCORN TO VTLAXS/OFF. */
/* *********************************************************************** */
/* ******************************************************************** */

/* ...    PRORATE TILT ANGLE */
    c5axis_1.cang = c5axis_1.stang + c5axis_1.dlngth / c5axis_1.tlngth * 
	    c5axis_1.dang;
    tsin = sin(c5axis_1.cang);
    tsin = sin(c5axis_1.cang);
    tsin1 = abs(tsin);
    tsin1 = abs(tsin);
    tcos = cos(c5axis_1.cang);
    avcros_(&c5axis_1.zcv, &c5axis_1.zun, &c5axis_1.ztr);
    avnorm_(&c5axis_1.ztr, &c5axis_1.ztr, &ier);
    if (ier != 0) {
	goto L81;
    } else {
	goto L82;
    }
L81:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L40;
L82:
/* ...    IS CANG .GT. 80 DEGREES */
    if (abs(tcos) - .1736 <= 0.) {
	goto L5;
    } else {
	goto L90;
    }
L90:
/* ...    CALCULATE XYZ COORDINATES OF NEW CUTTER POSITION */
    if (c5axis_1.cradus != 0.) {
	goto L100;
    } else {
	goto L110;
    }
L100:
    c5axis_1.z__ = c5axis_1.cradus * (1. - tcos) + (c5axis_1.cutter - 
	    c5axis_1.cradus) * tsin1;
    goto L120;
L110:
    c5axis_1.z__ = (d__1 = c5axis_1.cutter * tsin, abs(d__1));
L120:
    if (c5axis_1.cang * c5axis_1.zun >= 0.) {
	goto L150;
    } else {
	goto L130;
    }
L130:
    if (c5axis_1.cradus != 0.) {
	goto L140;
    } else {
	goto L170;
    }
L140:
    c5axis_1.test = c5axis_1.cutter * (tcos - 2. / tcos + 1.) - 
	    c5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.) / tcos);
    goto L9;
L150:
    if (c5axis_1.cradus != 0.) {
	goto L160;
    } else {
	goto L8;
    }
L160:
    c5axis_1.test = c5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.) / tcos) + 
	    c5axis_1.cutter * (1. - tcos);
    goto L9;
L170:
    if (c5fxis_1.iabove != 0) {
	goto L3;
    } else {
	goto L6;
    }
L3:
    c5axis_1.z__ = -c5axis_1.z__;
    goto L8;
L5:
    c5fxis_1.jsuber = 20;
/* ...    ERROR 20- TILT ANGLE IS GREATER THAN 80 DEGREES. */
    goto L40;
L6:
    c5axis_1.test = -(c5axis_1.cutter * 2. / tcos - c5axis_1.cutter - 
	    c5axis_1.cutter * tcos);
    goto L9;
L8:
    c5axis_1.test = c5axis_1.cutter * (1. - tcos);
L9:
    c5axis_1.xdo = c5axis_1.test * c5axis_1.xtr;
    c5axis_1.ydo = c5axis_1.test * c5axis_1.ytr;
    c5axis_1.zdo = c5axis_1.test * c5axis_1.ztr;
    c5axis_1.xcc = a3fxd1_1.x2 + c5axis_1.xdo;
    c5axis_1.ycc = a3fxd1_1.y2 + c5axis_1.ydo;
    c5axis_1.zcc = c5axis_1.z2 + c5axis_1.z__;
/* ...    CALCULATE IJK COMPONENTS OF NEW TLAXIS VECTOR */
    c5axis_1.xtr = tcos * c5axis_1.xtr;
    c5axis_1.ytr = tcos * c5axis_1.ytr;
    if (c5axis_1.zun >= 0.) {
	goto L20;
    } else {
	goto L10;
    }
L10:
    c5axis_1.ztr = tsin;
    avcros_(&c5axis_1.zcv, &c5axis_1.ztr, &c5axis_1.zta);
    goto L30;
L20:
    c5axis_1.ztr = -tsin;
    avcros_(&c5axis_1.ztr, &c5axis_1.zcv, &c5axis_1.zta);
L30:
    avnorm_(&c5axis_1.zta, &c5axis_1.zta, &ier);
    if (tachck_1.xxxxta + tachck_1.yyyyta + tachck_1.zzzzta != 0.) {
	goto L99999;
    }
    tachck_1.xxxxta = c5axis_1.xta;
    tachck_1.yyyyta = c5axis_1.yta;
    tachck_1.zzzzta = c5axis_1.zta;
    goto L99997;
L99999:
    difxta = c5axis_1.xta - tachck_1.xxxxta;
    difyta = c5axis_1.yta - tachck_1.yyyyta;
    difzta = c5axis_1.zta - tachck_1.zzzzta;
    if (difxta * tachck_1.chingx < 0. && abs(difxta) > 1.745e-5) {
	goto L99998;
    }
    if (difyta * tachck_1.chingy < 0. && abs(difyta) > 1.745e-5) {
	goto L99998;
    }
    if (difzta * tachck_1.chingz < 0. && abs(difzta) > 1.745e-5) {
	goto L99998;
    }
    goto L99995;
L99998:
    io___12.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___12);
    e_wsfe();
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    e_wsfe();
    io___14.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___14);
    e_wsfe();
L99995:
    if (difxta > 9e-8) {
	tachck_1.chingx = 1.;
    }
    if (difyta > 9e-8) {
	tachck_1.chingy = 1.;
    }
    if (difzta > 9e-8) {
	tachck_1.chingz = 1.;
    }
    if (difxta < -9e-8) {
	tachck_1.chingx = -1.;
    }
    if (difyta < -9e-8) {
	tachck_1.chingy = -1.;
    }
    if (difzta < -9e-8) {
	tachck_1.chingz = -1.;
    }
    tachck_1.xxxxta = c5axis_1.xta;
    tachck_1.yyyyta = c5axis_1.yta;
    tachck_1.zzzzta = c5axis_1.zta;
L99997:
/* ... */
    if (ier != 0) {
	goto L31;
    } else {
	goto L32;
    }
L31:
    c5fxis_1.jsuber = 37;
    goto L40;
L32:
    a3fxd1_1.x1 = a3fxd1_1.x2;
    a3fxd1_1.y1 = a3fxd1_1.y2;
    c5axis_1.z1 = c5axis_1.z2;
L40:
    return 0;
} /* compu1_ */

#undef lclprt
#undef nucltp
#undef irr
#undef arr


