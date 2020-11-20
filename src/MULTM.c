/* MULTM.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int multm_(amat1, amat2, amat3)
doublereal *amat1, *amat2, *amat3;
{
    /* Local variables */
    static integer i__, j, k;
#define nucltp ((doublereal *)&ataptb_1 + 7)

/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ...   THE MULTM SUBROUTINE WILL FIND THE PRODUCT OF TWO 3 X 4 MATRICES. */
/* ...        USE... CALL MULTM (MATRIX 1 , MATRIX 2 , MATRIX 3) */
/* ...      WHERE... MATRIX 3 = MATRIX 1 * MATRIX  2 */
/* ....******************************************************************* */
    /* Parameter adjustments */
    amat3 -= 4;
    amat2 -= 4;
    amat1 -= 4;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    a3fxd1_1.amati1[i__ + (j << 2) - 5] = amat1[i__ + j * 3];
/* L5: */
	    a3fxd1_1.amati2[i__ + (j << 2) - 5] = amat2[i__ + j * 3];
	}
    }
    i__ = 4;
    for (j = 1; j <= 3; ++j) {
	a3fxd1_1.amati1[i__ + (j << 2) - 5] = (float)0.;
/* L10: */
	a3fxd1_1.amati2[i__ + (j << 2) - 5] = (float)0.;
    }
    a3fxd1_1.amati1[15] = 1.;
    a3fxd1_1.amati2[15] = 1.;
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    a3fxd1_1.amati3[i__ + (j << 2) - 5] = (float)0.;
	    for (k = 1; k <= 4; ++k) {
		a3fxd1_1.amati3[i__ + (j << 2) - 5] += a3fxd1_1.amati1[i__ + (
			k << 2) - 5] * a3fxd1_1.amati2[k + (j << 2) - 5];
/* L20: */
	    }
	}
    }
    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    amat3[i__ + j * 3] = a3fxd1_1.amati3[i__ + (j << 2) - 5];
/* L30: */
	}
    }
    return 0;
} /* multm_ */

#undef nucltp


