/* TRCPV.f -- translated by f2c (version 20000121).
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
    integer is, ir, il, ie, jsuber, iabove;
} c5fxis_;

#define c5fxis_1 c5fxis_

/* Subroutine */ int trcpv_(i__)
integer *i__;
{
    /* Local variables */
    static integer ier;
#define arr ((doublereal *)&a3fxd1_1)
#define irr ((integer *)&a3fxi1_1)
    extern /* Subroutine */ int plot_(), tsfmvc_(), avnorm_();

/* ...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 *** */

/* ...    TRCPV CHECKS FOR TRACUT OR COPY IN EFFECT AT TIME OF */
/* ...    VTLAXS, AND CALLS FOR TRANSFORMATION OF VECTORS. */
/* ...    CALLED FROM VTLAXS WHEN PROCESSING A GODLTA RECORD. */
/* ...    ARGUMENT(I) IS SUBSCRIPT OF TAPSTO INDICATING */
/* ...    THE X COMPONENT OF VECTOR.  CHECKS FOR PLOTTING. */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ...    IF TRACUT OR COPY IS IN EFFECT, TRANSFORM VECTOR */
    if (a3fxi1_1.itrafl - 1 != 0) {
	goto L10;
    } else {
	goto L20;
    }
L10:
    if (a3fxi1_1.icopy != 0) {
	goto L20;
    } else {
	goto L30;
    }
L20:
    tsfmvc_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[*i__ - 1], &a3fxd1_1.tapsto[*
	    i__ - 1]);
    tsfmvc_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[*i__ + 2], &a3fxd1_1.tapsto[*
	    i__ + 2]);
    avnorm_(&a3fxd1_1.tapsto[*i__ + 2], &a3fxd1_1.tapsto[*i__ + 2], &ier);
    if (ier != 0) {
	goto L21;
    } else {
	goto L30;
    }
L21:
    c5fxis_1.jsuber = 37;
/* ...    ERROR 37  - MACHINE ERROR. */
    goto L40;
/* ...    CHECK FOR PLOTTING */
L30:
    plot_(&a3fxd1_1.tapsto[*i__ - 1]);
L40:
    return 0;
} /* trcpv_ */

#undef irr
#undef arr


