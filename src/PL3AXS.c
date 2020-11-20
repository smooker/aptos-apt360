/* PL3AXS.f -- translated by f2c (version 20000121).
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

/* Table of constant values */

static integer c__38 = 38;

/* Subroutine */ int pl3axs_(pt)
doublereal *pt;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    extern integer nxv_(), nyv_();
    extern /* Subroutine */ int plot_(), plotv_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
    extern /* Subroutine */ int perspc_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... THIS SUBROUTINE IS CONCERNED WITH SETTING UP THE END POINTS OF THE */
/* ... LINE SEGMENT BEFORE GOING ON TO PLOT. */
/* ... IT WILL ALSO TAKE CARE OF DOING SPECIAL THINGS FOR GODLTA/ AND THE */
/* ... FIRST POINT WITHIN A PLOT AREA. */
/* ....******************************************************************* */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ....******************************************************************* */
/* ...  IS A PLOT IN EFFECT - IF NOT SAVE THE POINT AND RETURN. */
    /* Parameter adjustments */
    --pt;

    /* Function Body */
    if (a3fxi1_1.idplot != 0) {
	goto L1000;
    } else {
	goto L9000;
    }
/* ...  SAVE THE INPUT POINT   PPT(I) = PT(I) */
L1000:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1020: */
	a3fxd1_1.ppt[i__ - 1] = pt[i__];
    }
/* ...  CHECK IF PERSPECTIVE PLOTTING REQUIRED */
    if (a3fxi1_1.ipersp == 0) {
	goto L1030;
    }
/* ...  PUT POINT THRU THE PERSPECTIVE MATRIX. */
    perspc_(a3fxd1_1.ppt, a3fxd1_1.ppt);
/* ...  SHOULD THIS POINT BE PLOTTED - IF NOT SAVE IT AND RETURN. */
L1030:
    if (a3fxi1_1.iploti != 0) {
	goto L1040;
    } else {
	goto L9000;
    }
/* ...  IS THIS THE FIRST POINT WITHIN THE PLOT-IF SO SAVE AND PLOT AN O */
L1040:
    if ((i__1 = a3fxi1_1.ifirst - a0con_1.k1) < 0) {
	goto L1060;
    } else if (i__1 == 0) {
	goto L7000;
    } else {
	goto L1050;
    }
/* ...  TURN FIRST POINT FLAG OFF. */
L1050:
    a3fxi1_1.ifirst = a0con_1.k0;
/* ...  CHECK IF A GODLTA - IF NOT IT MUST BE A GOTO POINT. */
L1060:
    if (a3fxi1_1.igodlt <= 0) {
	goto L3000;
    } else {
	goto L1100;
    }
/* ...  IT IS A GODLTA - ADD COMPONENTS TO LAST POINT */
L1100:
    a3fxd1_1.ppt[a3fxi1_1.ipx - 1] = a3fxd1_1.x0 + a3fxd1_1.ppt[a3fxi1_1.ipx 
	    - 1];
    a3fxd1_1.ppt[a3fxi1_1.ipy - 1] = a3fxd1_1.y0 + a3fxd1_1.ppt[a3fxi1_1.ipy 
	    - 1];
/* ...  TURN OFF THE GODLTA FLAG. */
    a3fxi1_1.igodlt = a0con_1.k0;
/* ...  SET UP THE END POINTS OF LINE SEGMENT TO BE PLOTTED. */
L3000:
    a3fxd1_1.ptt[0] = a3fxd1_1.x0;
    a3fxd1_1.ptt[1] = a3fxd1_1.y0;
    a3fxd1_1.ptt[2] = a3fxd1_1.ppt[a3fxi1_1.ipx - 1];
    a3fxd1_1.ptt[3] = a3fxd1_1.ppt[a3fxi1_1.ipy - 1];
/* ...  PLOT THE LINE SEGMENT. */
    plot_(a3fxd1_1.ptt);
/* ...  GO TO SAVE THE POINT AND RETURN */
    goto L9000;
/* ...  THIS SECTION WILL PROCESS THE FIRST POINT WITHIN A PLOT AREA. */
L7000:
    a3fxd1_1.x0 = a3fxd1_1.ppt[a3fxi1_1.ipx - 1];
    a3fxd1_1.y0 = a3fxd1_1.ppt[a3fxi1_1.ipy - 1];
/* ...  CONVERT THE LOCATION TO RASTER COUNT. */
    a3fxi1_1.nx0 = nxv_(&a3fxd1_1.x0);
    a3fxi1_1.ny0 = nyv_(&a3fxd1_1.y0);
/* ...  CHECK IF X IS ON THE FRAME. */
    if (a3fxi1_1.nx0 != 0) {
	goto L7020;
    } else {
	goto L7050;
    }
/* ...  CHECK IF Y IS ON THE FRAME. */
L7020:
    if (a3fxi1_1.ny0 != 0) {
	goto L7040;
    } else {
	goto L7050;
    }
/* ...  IT IS ON THE FRAME - PLOT A CIRCLE AROUND THE POINT. */
L7040:
    plotv_(&a3fxi1_1.nx0, &a3fxi1_1.ny0, &c__38);
L7050:
    a3fxi1_1.ifirst = a0con_1.k2;
/* ...  SAVE THE PRESENT POINT AS A PREVIOUS POINT. */
L9000:
    a3fxd1_1.x0 = a3fxd1_1.ppt[a3fxi1_1.ipx - 1];
    a3fxd1_1.y0 = a3fxd1_1.ppt[a3fxi1_1.ipy - 1];
/* ... RETURN TO SECTN3 */
/* L9999: */
    return 0;
} /* pl3axs_ */

#undef nucltp


