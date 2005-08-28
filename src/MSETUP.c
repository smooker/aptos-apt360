/* MSETUP.f -- translated by f2c (version 20000121).
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

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int msetup_(m, n)
integer *m, *n;
{
    /* Format strings */
    static char fmt_1296[] = "(\002-***** INCORRECT NUMBER OF PARAMETERS IN \
THE COPY/...AT\rCARD NO. \002a8,\002 LAST CALL CARD \002a8,\002$$$$$$$$\002)";
    static char fmt_1297[] = "(\002-***** THE (N) VALUE IN THE COPY/ IS MINU\
S...........AT\rCARD NO. \002a8,\002 LAST CALL CARD \002a8,\002$$$$$$$$\002)";
    static char fmt_1410[] = "(\002-MIRROR,MIRROR ON THE WALL YOU ARE NOT AL\
LOWED AT ALL\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Builtin functions */
    double cos(), sin();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, j, k;
#define nucltp ((doublereal *)&ataptb_1 + 7)

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, fmt_1296, 0 };
    static cilist io___5 = { 0, 0, 0, fmt_1297, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_1410, 0 };


/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* *********************************************************************** */
    switch ((int)*m) {
	case 1:  goto L1250;
	case 2:  goto L1270;
	case 3:  goto L1280;
	case 4:  goto L1300;
	case 5:  goto L1400;
    }
/* ... NOTE...ALL MATRICES ARE STORED FROM CLTAPE COLUMNWISE */
/* ... THIS SECTION SETS UP THE TRANSL PARAMETERS... */
/* ... CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L1250:
    if ((i__1 = a3fxi1_1.numwds - a0con_1.k6) < 0) {
	goto L1251;
    } else if (i__1 == 0) {
	goto L1252;
    } else {
	goto L1292;
    }
L1251:
    if (a3fxi1_1.numwds - a0con_1.k5 >= 0) {
	goto L1252;
    } else {
	goto L1292;
    }
/* ... CHECK IF (N) IS ZERO OR MINUS */
L1252:
    if ((d__1 = a3fxd1_1.tapsto[a0con_1.k6 - 1]) < 0.) {
	goto L1293;
    } else if (d__1 == 0) {
	goto L1253;
    } else {
	goto L1254;
    }
L1253:
    a3fxd1_1.tapsto[a0con_1.k6 - 1] = (float)1.;
/* ... SET UP THE TRANSL  MATRIX */
L1254:
    i__1 = a0con_1.k3;
    i__2 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
/* L1260: */
	a3fxd1_1.amatrx[i__ + a0con_1.k4 * 3 - 4] = a3fxd1_1.tapsto[i__ + 1];
    }
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k1 * 3 - 4] = (float)1.;
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k2 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k3 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k1 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k2 * 3 - 4] = (float)1.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k3 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k1 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k2 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k3 * 3 - 4] = (float)1.;
    a3fxd1_1.count[0] = a3fxd1_1.tapsto[a0con_1.k6 - 1];
    goto L1500;
/* *********************************************************************** */
/* ... THIS SECTION SETS UP THE XYROT PARAMETERS... */
/* ... CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L1270:
    if ((i__2 = a3fxi1_1.numwds - a0con_1.k4) < 0) {
	goto L1271;
    } else if (i__2 == 0) {
	goto L1272;
    } else {
	goto L1292;
    }
L1271:
    if (a3fxi1_1.numwds - a0con_1.k3 >= 0) {
	goto L1272;
    } else {
	goto L1292;
    }
/* ... CHECK IF (N) IS ZERO OR MINUS */
L1272:
    if ((d__1 = a3fxd1_1.tapsto[a0con_1.k4 - 1]) < 0.) {
	goto L1293;
    } else if (d__1 == 0) {
	goto L1273;
    } else {
	goto L1274;
    }
L1273:
    a3fxd1_1.tapsto[a0con_1.k4 - 1] = (float)1.;
/* ... SET UP THE XYROT   MATRIX */
L1274:
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k1 * 3 - 4] = cos(a3fxd1_1.tapsto[
	    a0con_1.k3 - 1] / 57.29577951308232);
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k2 * 3 - 4] = -sin(a3fxd1_1.tapsto[
	    a0con_1.k3 - 1] / 57.29577951308232);
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k3 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k4 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k1 * 3 - 4] = sin(a3fxd1_1.tapsto[
	    a0con_1.k3 - 1] / 57.29577951308232);
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k2 * 3 - 4] = cos(a3fxd1_1.tapsto[
	    a0con_1.k3 - 1] / 57.29577951308232);
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k3 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k4 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k1 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k2 * 3 - 4] = (float)0.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k3 * 3 - 4] = (float)1.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k4 * 3 - 4] = (float)0.;
    a3fxd1_1.count[0] = a3fxd1_1.tapsto[a0con_1.k4 - 1];
    goto L1500;
/* ******************************************************************** */
/* ... THIS SECTION SETS UP THE SAME PARAMETERS */
/* ... CHECK IF THE CORRECT NUMBER OF PARAMETERS ARE PRESENT */
L1280:
    if ((i__2 = a3fxi1_1.numwds - a0con_1.k3) < 0) {
	goto L1281;
    } else if (i__2 == 0) {
	goto L1282;
    } else {
	goto L1292;
    }
L1281:
    if (a3fxi1_1.numwds - a0con_1.k2 >= 0) {
	goto L1282;
    } else {
	goto L1292;
    }
/* ... CHECK IF (N) IS ZERO OR MINUS */
L1282:
    if ((d__1 = a3fxd1_1.tapsto[a0con_1.k3 - 1]) < 0.) {
	goto L1293;
    } else if (d__1 == 0) {
	goto L1283;
    } else {
	goto L1284;
    }
L1283:
    a3fxd1_1.tapsto[a0con_1.k3 - 1] = (float)1.;
/* ... SET UP THE SAME    MATRIX */
L1284:
    i__2 = a0con_1.k3;
    i__1 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
	i__3 = a0con_1.k4;
	i__4 = a0con_1.k1;
	for (j = a0con_1.k1; i__4 < 0 ? j >= i__3 : j <= i__3; j += i__4) {
/* L1290: */
	    a3fxd1_1.amatrx[i__ + j * 3 - 4] = (float)0.;
	}
    }
    a3fxd1_1.amatrx[a0con_1.k1 + a0con_1.k1 * 3 - 4] = (float)1.;
    a3fxd1_1.amatrx[a0con_1.k2 + a0con_1.k2 * 3 - 4] = (float)1.;
    a3fxd1_1.amatrx[a0con_1.k3 + a0con_1.k3 * 3 - 4] = (float)1.;
    a3fxd1_1.count[0] = a3fxd1_1.tapsto[a0con_1.k3 - 1];
    goto L1500;
/* ... PRINT DIAGNOSTIC FOR INCORRECT NUMBER OF PARAMETERS IN A COPY */
L1292:
    io___4.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___4);
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_1.cseqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L1040;
/* ... PRINT DIAGNOSTIC   FOR ZERO OR MINUS INDEX VALUE */
L1293:
    io___5.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___5);
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_1.cseqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
/* L1295: */
    goto L1040;
/* ... THIS SECTION SETS UP THE MODIFY PARAMETERS... */
/* ... SET UP THE MODIFY  MATRIX */
L1300:
    k = 4;
    i__4 = a0con_1.k3;
    i__3 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__3 < 0 ? i__ >= i__4 : i__ <= i__4; i__ += i__3) 
	    {
	i__1 = a0con_1.k4;
	i__2 = a0con_1.k1;
	for (j = a0con_1.k1; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
	    k += a0con_1.k1;
/* L1310: */
	    a3fxd1_1.amatrx[i__ + j * 3 - 4] = a3fxd1_1.tapsto[k - 1];
	}
    }
    if (a3fxd1_1.tapsto[16] < 0.) {
	goto L1293;
    } else if (a3fxd1_1.tapsto[16] == 0) {
	goto L1311;
    } else {
	goto L1312;
    }
L1311:
    a3fxd1_1.tapsto[16] = (float)1.;
L1312:
    a3fxd1_1.count[0] = a3fxd1_1.tapsto[16];
    goto L1500;
/* *********************************************************************** */
/* ... THIS SECTION SETS UP THE MIRROR PARAMETERS...WHEN THERE IS ONE..... */
/* ... PRINT DIAGNOSTIC   FOR USING A MIRROR      MODIFIER */
L1400:
    io___7.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___7);
    e_wsfe();
    asistm_1.iclprt = a0con_1.k1;
/* L190: */
    *n = a0con_1.k1;
    goto L9999;
L1040:
    *n = a0con_1.k2;
    goto L9999;
L1500:
    *n = a0con_1.k3;
    a3fxd1_1.word = a3fxd1_1.count[0];
    j = (integer) a3fxd1_1.word;
    a3fxd1_1.word = (doublereal) j;
    a3fxd1_1.count[0] = a3fxd1_1.word;
    if (a3fxd1_1.count[0] == (float)0.) {
	a3fxd1_1.count[0] = (float)1.;
    }
L9999:
    return 0;
} /* msetup_ */

#undef nucltp


