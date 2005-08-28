/* PL5AXS.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int pl5axs_(pt)
doublereal *pt;
{
    /* Local variables */
    static integer i__, k;
    extern /* Subroutine */ int plot_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
    extern /* Subroutine */ int perspc_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... THIS ROUTINE IS USED TO PLOT A REPRESENTATION OF THE TOOL AXIS */
/* ... VECTOR ONTO EVERY ITHPNT POINT AND IF THE JVECTR FLAG IS SET WILL */
/* ... PUT A VECTOR ON THE IMMEDIATE POINT. */
/* ....******************************************************************* */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ....******************************************************************* */
/* ...  IS A PLOT IN EFFECT - ZERO MEANS NO,RETURN. */
    /* Parameter adjustments */
    --pt;

    /* Function Body */
    if (a3fxi1_1.idplot != 0) {
	goto L1000;
    } else {
	goto L9999;
    }
/* ...  SAVE THE INPUT POINT */
L1000:
    for (i__ = 1; i__ <= 6; ++i__) {
/* L1020: */
	a3fxd1_1.ppt[i__ - 1] = pt[i__];
    }
/* ...  CHECK IF PERSPECTIVE PLOTTING REQUIRED */
    if (a3fxi1_1.ipersp == 0) {
	goto L1030;
    }
/* ... TRANSFORM POINT    FOR PERSPECTIVE */
    perspc_(a3fxd1_1.ppt, a3fxd1_1.ppt);
/* ...  IS THE VECTOR FLAG SET - IF SO THEN PLOT THE TOOL AXIS VECTOR */
L1030:
    if (a3fxi1_1.jvectr <= 0) {
	goto L2000;
    } else {
	goto L3000;
    }
/* ...  ADD ONE TO I - CAUSES A TOOL VECTOR TO BE PLOTTED EVERY ITH POINT. */
L2000:
    ++k;
/* ...  IS I = ITHPNT - IF SO THEN PLOT THE TOOL AXIS VECTOR. */
    if (a3fxi1_1.ithpnt != k) {
	goto L9999;
    }
/* ...  SET UP THE END POINTS FOR THE TOOL AXIS VECTOR. */
L3000:
    a3fxd1_1.ptt[0] = a3fxd1_1.ppt[a3fxi1_1.ipx - 1];
    a3fxd1_1.ptt[1] = a3fxd1_1.ppt[a3fxi1_1.ipy - 1];
    a3fxd1_1.ptt[2] = a3fxd1_1.ppt[a3fxi1_1.ipx + 2] * (a3fxd1_1.toolng * (
	    float).3) + a3fxd1_1.ppt[a3fxi1_1.ipx - 1];
    a3fxd1_1.ptt[3] = a3fxd1_1.ppt[a3fxi1_1.ipy + 2] * (a3fxd1_1.toolng * (
	    float).3) + a3fxd1_1.ppt[a3fxi1_1.ipy - 1];
    a3fxi1_1.jarrow = a0con_1.k0;
/* ... PLOT THE TOOL AXIS VECTOR */
    plot_(a3fxd1_1.ptt);
    a3fxd1_1.ptt[0] = a3fxd1_1.ptt[2] + a3fxd1_1.toolng * (float).1 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipx + 2];
    a3fxd1_1.ptt[1] = a3fxd1_1.ptt[3] + a3fxd1_1.toolng * (float).1 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipy + 2];
    a3fxd1_1.ptt[2] = a3fxd1_1.ptt[0] + a3fxd1_1.toolng * (float).2 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipx + 2];
    a3fxd1_1.ptt[3] = a3fxd1_1.ptt[1] + a3fxd1_1.toolng * (float).2 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipy + 2];
    a3fxi1_1.jarrow = a0con_1.k0;
    plot_(a3fxd1_1.ptt);
    a3fxd1_1.ptt[0] = a3fxd1_1.ptt[2] + a3fxd1_1.toolng * (float).1 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipx + 2];
    a3fxd1_1.ptt[1] = a3fxd1_1.ptt[3] + a3fxd1_1.toolng * (float).1 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipy + 2];
    a3fxd1_1.ptt[2] = a3fxd1_1.ptt[0] + a3fxd1_1.toolng * (float).3 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipx + 2];
    a3fxd1_1.ptt[3] = a3fxd1_1.ptt[1] + a3fxd1_1.toolng * (float).3 * 
	    a3fxd1_1.ppt[a3fxi1_1.ipy + 2];
    a3fxi1_1.jarrow = a0con_1.k0;
    plot_(a3fxd1_1.ptt);
/* ...  A TOOL AXIS VECTOR HAS BEEN PLOTTED-SET THE COUNTER(I) BACK */
    k = 0;
    a3fxi1_1.jvectr = a0con_1.k0;
L9999:
    return 0;
} /* pl5axs_ */

#undef nucltp


