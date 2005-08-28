/* TRACUT.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int tracut_(kkk)
integer *kkk;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k;
    extern /* Subroutine */ int multm_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
    extern /* Subroutine */ int matmov_();

/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ... THIS SECTION PROCESSES THE TRACUT INSTRUCTION... */
/* ... IS INDEXX ON */
/* L700: */
    if (asistm_1.indexx - a0con_1.k1 != 0) {
	goto L150;
    } else {
	goto L705;
    }
/* ... IS THE MODIFIER NOMORE - IF SO TURN OFF THE TRACUT FLAG. */
L705:
    if (a3fxi1_1.i1 - 53 != 0) {
	goto L720;
    } else {
	goto L710;
    }
/* ... TURN OFF TRACUT    FLAG */
L710:
    a3fxi1_1.itrafl = a0con_1.k0;
    goto L800;
/* ... TURN ON TRACUT FLAG */
L720:
    a3fxi1_1.itrafl = a0con_1.k1;
/* ... STORE TRACUT MATRIX FROM TAPE AND STORE BY COLUMNS */
    k = a0con_1.k2;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    k += a0con_1.k1;
/* L730: */
	    a3fxd1_1.tramat[i__ + j * 3 - 4] = a3fxd1_1.tapsto[k - 1];
	}
    }
/* ... MOVE COPY MATRIX */
L800:
    matmov_(a3fxd1_1.cntmat, a3fxd1_1.tmatrx);
/* ... IS A COPY IN EFFECT */
    if ((i__1 = a3fxi1_1.icopy - a0con_1.k1) < 0) {
	goto L810;
    } else if (i__1 == 0) {
	goto L850;
    } else {
	goto L830;
    }
/* ... IS THIS A NOMORE */
L810:
    if (a3fxi1_1.i1 - 53 != 0) {
	goto L820;
    } else {
	goto L870;
    }
/* ... MOVE THE TRACUT    MATRIX */
L820:
    matmov_(a3fxd1_1.tramat, a3fxd1_1.tmatrx);
    goto L870;
/* ... UPDATE THE TMATRX IF THERE IS MORE THAN ONE COPY IN EFFECT */
L830:
    i__1 = a3fxi1_1.icopy;
    i__2 = a0con_1.k1;
    for (i__ = a0con_1.k2; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
	multm_(a3fxd1_1.tmatrx, &a3fxd1_1.cntm[i__ * 12 - 12], 
		a3fxd1_1.tmatrx);
/* L840: */
    }
/* ... IS THIS A NOMORE */
L850:
    if (a3fxi1_1.i1 - 53 != 0) {
	goto L860;
    } else {
	goto L870;
    }
/* ... MULTIPLY TMATRX AND TRAMAT */
L860:
    multm_(a3fxd1_1.tmatrx, a3fxd1_1.tramat, a3fxd1_1.tmatrx);
L150:
    *kkk = a0con_1.k1;
    goto L9999;
L870:
    *kkk = a0con_1.k2;
L9999:
    return 0;
} /* tracut_ */

#undef nucltp


