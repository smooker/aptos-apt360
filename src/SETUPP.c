/* SETUPP.f -- translated by f2c (version 20000121).
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

static integer c__66 = 66;
static integer c__250 = 250;
static integer c__1000 = 1000;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c_n1 = -1;
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__1023 = 1023;

/* Subroutine */ int setupp_()
{
    /* Format strings */
    static char fmt_9100[] = "(\002-FRAME SIZE IS LESS THAN ZERO IN WIDTH OR\
 LENGTH - CARD\rNO. \002a6,a2,\002 LAST CALL CARD NO. \002a6,a2)";
    static char fmt_9031[] = "(\002 NO CAMRA CARD\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, j, m, n;
    static doublereal dc;
    static integer ierr;
    extern /* Subroutine */ int linev_(), arrow_(), dxdyv_(), grid1v_(), 
	    pl3axs_(), cmload_(), camrav_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
    extern /* Subroutine */ int framev_(), printv_(), xscalv_(), yscalv_();

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_9100, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_9031, 0 };


/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* ... */
/* ... THIS SUBROUTINE IS USED TO SET UP THE NECESSARY DATA TO DESCRIBE */
/* ... THE PLOT FRAME AND SCALING EQUATIONS TO BE USED BY THE LOWER LEVEL */
/* ... PLOTTING SUBROUTINES */
/* ******************************************************************** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ...******************************************************************** */
/* ... IS CAMERA ONE      REQUESTED */
    if ((i__1 = a3fxi1_1.ncamra - a0con_1.k1) < 0) {
	goto L9030;
    } else if (i__1 == 0) {
	goto L18;
    } else {
	goto L12;
    }
/* ... IS CAMERA ONE OR   BOTH REQUESTED */
L12:
    if (a3fxi1_1.ncamra - a0con_1.k2 <= 0) {
	goto L16;
    } else {
	goto L19;
    }
/* ...  SET NCAMRA = 35MM. */
L16:
    a3fxi1_1.ncamra = 35;
    goto L19;
/* ...  SET NCAMRA = 9X9 CAMERA. */
L18:
    a3fxi1_1.ncamra = a0con_1.k9;
/* ...  SELECT THE CAMERA TO BE USED FOR THIS FRAME. */
L19:
    cmload_(&a3fxi1_1.ncamra);
    camrav_(&a3fxi1_1.ncamra);
/* ...  GET A CLEAN FRAME TO PLOT ON. */
    framev_();
/* ...  PRINT THE PARTNO ON THE PLOT FRAME. */
    printv_(&c__66, a3fxd1_1.partno, &c__250, &c__1000);
/* ...  IS PERSPECTIVE IN EFFECT - EQUAL IS NO. */
    if (a3fxi1_1.ipersp != 0) {
	goto L1000;
    } else {
	goto L30;
    }
/* ...  SET UP GRID ACCORDING TO INPUT DATA OF FRAME SIZE. */
L30:
    dc = (float)60.;
/* ... DEFINE GRID SIZE   AND LABELS FOR GRID1V */
    dxdyv_(&c__1, &a3fxd1_1.pt0[a3fxi1_1.ipx - 1], &a3fxd1_1.ptu[a3fxi1_1.ipx 
	    - 1], &a3fxd1_1.dx, &n, &i__, &a3fxi1_1.nx, &dc, &ierr);
/* ... WAS THERE AN ERROR RETURN */
    if (ierr <= 0) {
	goto L40;
    } else {
	goto L9000;
    }
/* ... DEFINE GRID SIZE   AND LABELS FOR GRID1V */
L40:
    dxdyv_(&c__2, &a3fxd1_1.pt0[a3fxi1_1.ipy - 1], &a3fxd1_1.ptu[a3fxi1_1.ipy 
	    - 1], &a3fxd1_1.dy, &m, &j, &a3fxi1_1.ny, &dc, &ierr);
/* ... WAS THERE AN ERROR RETURN */
    if (ierr <= 0) {
	goto L50;
    } else {
	goto L9000;
    }
/* ...  LET GRID1V SET UP AND PLOT THE GRID ACCORDING TO PARAMS FROM DXDYV */
L50:
    i__1 = -n;
    i__2 = -m;
    grid1v_(&c__2, &a3fxd1_1.pt0[a3fxi1_1.ipx - 1], &a3fxd1_1.ptu[
	    a3fxi1_1.ipx - 1], &a3fxd1_1.pt0[a3fxi1_1.ipy - 1], &a3fxd1_1.ptu[
	    a3fxi1_1.ipy - 1], &a3fxd1_1.dx, &a3fxd1_1.dy, &i__1, &i__2, &
	    c_n1, &c_n1, &c__4, &c__4);
    goto L9999;
/* ...  THIS AREA WILL SET UP PERSPECTIVE TRANSFORMATION EQUATIONS. */
L1000:
    goto L3000;
/* ...******************************************************************** */
/* ...  SCALE FOR X BETWEEN INPUT DATA AND CRT TUBE. */
L3000:
    xscalv_(&a3fxd1_1.pt0[a3fxi1_1.ipx - 1], &a3fxd1_1.ptu[a3fxi1_1.ipx - 1], 
	    &c__0, &c__0);
/* ...  SCALE FOR Y BETWEEN INPUT DATA AND CRT TUBE. */
    yscalv_(&a3fxd1_1.pt0[a3fxi1_1.ipy - 1], &a3fxd1_1.ptu[a3fxi1_1.ipy - 1], 
	    &c__0, &c__0);
/* ...  PUT AXIS VECTORS ON PLOT FRAME AT THE ORIGIN OF THE INPUT DATA */
    a3fxd1_1.origin[0] = (float)0.;
    a3fxd1_1.origin[1] = (float)0.;
    a3fxd1_1.origin[2] = (float)0.;
    a3fxi1_1.jarrow = a0con_1.k0;
    a3fxi1_1.ifirst = a0con_1.k1;
/* ...  INITIALIZE USING THE ORIGIN. */
    pl3axs_(a3fxd1_1.origin);
/* ...  PLOT THE X AXIS VECTOR. */
    a3fxd1_1.axvec[0] = (float)1.;
    a3fxd1_1.axvec[1] = (float)0.;
    a3fxd1_1.axvec[2] = (float)0.;
    a3fxi1_1.jarrow = a0con_1.k1;
    a3fxi1_1.ifirst = a0con_1.k0;
    pl3axs_(a3fxd1_1.axvec);
/* ...  IF THE TRUNC ROUTINE PUT AN ARROW ON THE LINE-THEN BYPASS ARROW. */
    if (a3fxi1_1.itrunc <= 0) {
	goto L3020;
    } else {
	goto L3040;
    }
/* ...  TRUNC DID NOT PLOT ARROW SO DO IT NOW. */
L3020:
    arrow_();
/* ...  BACK TO ORIGIN - SET JARROW SO NO ARROW CAN BE PLOTTED BY TRUNC. */
L3040:
    a3fxi1_1.jarrow = a0con_1.k0;
    pl3axs_(a3fxd1_1.origin);
/* ...  SET UP THE Y AXIS VECTOR. */
    a3fxd1_1.axvec[0] = (float)0.;
    a3fxd1_1.axvec[1] = (float)1.;
    a3fxi1_1.jarrow = a0con_1.k1;
/* ...  PLOT THE Y AXIS */
    pl3axs_(a3fxd1_1.axvec);
/* ...  IF THE TRUNC ROUTINE PUT AN ARROW ON THE LINE-THEN BYPASS ARROW. */
    if (a3fxi1_1.itrunc <= 0) {
	goto L3060;
    } else {
	goto L3080;
    }
/* ...  TRUNC DID NOT PLOT ARROW SO DO IT NOW. */
L3060:
    arrow_();
/* ...  BACK TO ORIGIN - SET JARROW SO NO ARROW CAN BE PLOTTED BY TRUNC. */
L3080:
    a3fxi1_1.jarrow = a0con_1.k0;
    pl3axs_(a3fxd1_1.origin);
/* ...  SET UP THE Z AXIS VECTOR. */
    a3fxd1_1.axvec[1] = (float)0.;
    a3fxd1_1.axvec[2] = (float)1.;
    a3fxi1_1.jarrow = a0con_1.k1;
/* ...  PLOT THE Z AXIS. */
    pl3axs_(a3fxd1_1.axvec);
/* ...  IF THE TRUNC ROUTINE PUT AN ARROW ON THE LINE-THEN BYPASS ARROW. */
    if (a3fxi1_1.itrunc <= 0) {
	goto L3100;
    } else {
	goto L3120;
    }
/* ...  TRUNC DID NOT PLOT ARROW SO DO IT NOW. */
L3100:
    arrow_();
/* ... PUT A FRAME AROUND THE PICTURE. */
/* ...  PLOT LEFT FRAME EDGE. */
L3120:
    linev_(&c__0, &c__0, &c__0, &c__1023);
/* ...  PLOT UPPER FRAME EDGE. */
    linev_(&c__0, &c__1023, &c__1023, &c__1023);
/* ...  PLOT RIGHT FRAME EDGE. */
    linev_(&c__1023, &c__1023, &c__1023, &c__0);
/* ...  PLOT BOTTOM FRAME EDGE. */
    linev_(&c__1023, &c__0, &c__0, &c__0);
/* ...  RETURN TO CALLING ROUTINE - PERSPECTIVE HAS BEEN SET UP. */
    goto L9999;
/* ...  FRAME SIZE IS LESS THAN ZERO IN WIDTH OR LENGTH OR BOTH. */
L9000:
    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_1.cseqno[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_1.cseqno[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L9900;
L9030:
    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    e_wsfe();
L9900:
    a3fxi1_1.iploti = a0con_1.k0;
L9999:
    return 0;
/* ... FORMAT STATEMENTS */
} /* setupp_ */

#undef nucltp


