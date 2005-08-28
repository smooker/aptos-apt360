/* COMPU.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int compu_()
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
#define arr ((doublereal *)&a3fxd1_1)
#define irr ((integer *)&a3fxi1_1)
    extern /* Subroutine */ int compu2_(), compu1_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)

/* ...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 *** */
/* ******************************************************************** */

/* ...    COMPU SETS UP CUT VECTOR AND CALLS COMPU1, OR COMPU2 WHEN */
/* ...    WCORN IS TO BE ACCOMPLISHED,TO CALCULATE AN ALTERED */
/* ...    CUTTER POSITION FOR VTLAXS. */
/* *********************************************************************** */
/* ...    ESTABLISH CUT VECTOR */
    c5axis_1.xcv = a3fxd1_1.x2 - a3fxd1_1.x1;
    c5axis_1.ycv = a3fxd1_1.y2 - a3fxd1_1.y1;
    c5axis_1.zcv = c5axis_1.z2 - c5axis_1.z1;
/* Computing 2nd power */
    d__1 = c5axis_1.xcv;
/* Computing 2nd power */
    d__2 = c5axis_1.ycv;
/* Computing 2nd power */
    d__3 = c5axis_1.zcv;
    c5axis_1.dlngth += sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* ...    IS WCORN IN EFFECT */
    if (a5fxis_1.icorn1 != 0) {
	goto L10;
    } else {
	goto L40;
    }
L10:
    if (c5axis_1.dlngth + (float).05 - b5axis_1.tlnth1 >= 0.) {
	goto L20;
    } else {
	goto L40;
    }
/* ...    WCORN */
L20:
    compu2_();
    a5fxis_1.icorn1 = 0;
    goto L50;
/* ...    NO WCORN */
L40:
    compu1_();
L50:
    return 0;
} /* compu_ */

#undef lclprt
#undef nucltp
#undef irr
#undef arr


