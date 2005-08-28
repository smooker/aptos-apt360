/* PRTSET.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int prtset_(kkk)
integer *kkk;
{
    /* Local variables */
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    extern /* Subroutine */ int clprnt_();

/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ...   SET PRINT FLAGS */
/* ...      ICLPRT = 0   NO PRINTING THIS PASS */
/* ...      ICLPRT = 1   PRINTING THIS PASS */
/* ...      JCLPRT = 0   DO NOT PRINT THIS STATEMENT */
/* ...      JCLPRT = 1   PRINT THIS STATEMENT */
/* ...      KCLPRT = 0   PRINT BEFORE NUCLTP TRANSFORMATIONS */
/* ...      KCLPRT = 1   PRINT  AFTER NUCLTP TRANSFORMATIONS */
/* L678: */
    if (asistm_1.iwaven != 0) {
	goto L688;
    }
    if (*lclprt - a0con_1.k2 >= 0) {
	goto L685;
    } else {
	goto L679;
    }
L679:
    if (a3fxi1_1.instr2 - a0con_1.k4 != 0) {
	goto L125;
    } else {
	goto L680;
    }
L680:
    if (a3fxi1_1.i1 >= 0) {
	goto L681;
    } else {
	goto L688;
    }
L681:
    a3fxi1_1.it = a3fxi1_1.i1 + a0con_1.k1;
/* L682: */
    if (a3fxi1_1.it - a0con_1.k3 <= 0) {
	goto L683;
    } else {
	goto L688;
    }
L683:
    switch ((int)a3fxi1_1.it) {
	case 1:  goto L684;
	case 2:  goto L685;
	case 3:  goto L686;
    }
L684:
    a3fxi1_1.jclprt = a0con_1.k0;
    goto L687;
L685:
    a3fxi1_1.jclprt = a0con_1.k1;
    a3fxi1_1.kclprt = a0con_1.k1;
    goto L687;
L686:
    a3fxi1_1.jclprt = a0con_1.k1;
    a3fxi1_1.kclprt = a0con_1.k0;
L687:
    clprnt_();
    a3fxi1_1.nrecno = a3fxi1_1.irecno;
/* L40: */
    *kkk = a0con_1.k1;
    goto L9999;
L688:
    a3fxi1_1.jclprt = a0con_1.k1;
    a3fxi1_1.kclprt = a0con_1.k0;
L125:
    *kkk = a0con_1.k2;
L9999:
    return 0;
} /* prtset_ */

#undef lclprt
#undef nucltp


