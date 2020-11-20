/* TYPE5.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int type5_(kkk)
integer *kkk;
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, ll;
    static doublereal vun;
    extern /* Subroutine */ int arrow_(), pl3axs_(), pl5axs_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
    extern /* Subroutine */ int tsfmvc_(), tsfmpt_();

/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* *********************************************************************** */
/* ... THIS SECTION WILL PROCESS THE POINTS RECORDS */
/* ... IT WILL TRANSFORM THE POINTS IF A TRACUT OR COPY IS IN EFFECT */
/* ... IT WILL ALSO PLOT THE TOOL PATH IF THE PLOTTING ROUTINES ARE IN */
/* ... THE SYSTEM AND IF REQUESTED IT WILL PLOT THE TOOL AXIS VECTOR  FOR */
/* ... A 5 AXIS PART PROGRAM */
/* ... IS IT AN INDIRV OR INDIRP - IF SO IGNORE IT AND READ ANOTHER RECORD */
/* L400: */
    if (a3fxi1_1.instr2 - a0con_1.k2 <= 0) {
	goto L150;
    } else {
	goto L402;
    }
/* ... IS IT A GODLTA - IF SO CHECK FOR TRACUT OR COPY IF NOT GO TO POINTS */
L402:
    if (a3fxi1_1.instr2 - a0con_1.k4 != 0) {
	goto L430;
    } else {
	goto L404;
    }
/* ... IS TRACUT IN EFFECTIF SO TRANSFORM GODLTA  IF NOT CHECK FOR A COPY */
L404:
    if (a3fxi1_1.itrafl - a0con_1.k1 != 0) {
	goto L406;
    } else {
	goto L408;
    }
/* ... IS A COPY IN EFFECT - IF SO TRANSFORM GODLTA VECTOR */
L406:
    if (a3fxi1_1.icopy < 0) {
	goto L1550;
    } else if (a3fxi1_1.icopy == 0) {
	goto L410;
    } else {
	goto L408;
    }
/* ... TRANSFORM GODLTA */
L408:
    tsfmvc_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[a0con_1.k3 - 1], &
	    a3fxd1_1.tapsto[a0con_1.k3 - 1]);
/* ... HAS THE SECTN0 PLOT FLAG BEEN SET - IF NOT GO PRINT THIS RECORD */
L410:
    if (asistm_1.iplotr <= 0) {
	goto L150;
    } else {
	goto L412;
    }
/* ... LET THE THE PLOT SUBROUTINES KNOW THERE IS A GO DLTA/ IN EFFECT */
L412:
    a3fxi1_1.igodlt = a0con_1.k1;
    a3fxi1_1.jarrow = a0con_1.k1;
/* ... PLOT THE GO DLTA VECTOR */
    pl3axs_(&a3fxd1_1.tapsto[a0con_1.k3 - 1]);
/* ... IS 5 AXIS PLOTTING IN EFFECT - IF NOT CHECK FOR AN ARROW */
    if (a3fxi1_1.ipl5ax <= 0) {
	goto L416;
    } else {
	goto L414;
    }
/* ... SET SWITCH FOR NO ARROW BECAUSE TOOL AXIS IS BEING PLOTTED */
L414:
    a3fxi1_1.jarrow = a0con_1.k0;
/* ... PLOT THE TOOL AXIS VECTOR */
    pl5axs_(&a3fxd1_1.tapsto[a0con_1.k3 - 1]);
/* ... CHECK PLOT FLAGS TO SEE IF AN ARROW SHOULD BE PLOTED - IF NOT READ */
L416:
    if (asistm_1.iplotr <= 0) {
	goto L150;
    } else {
	goto L418;
    }
/* ... IS A PLOT/ COMMAND IN EFFECT - IF NOT GO PRINT THIS RECORD */
L418:
    if (a3fxi1_1.idplot <= 0) {
	goto L150;
    } else {
	goto L420;
    }
/* ... IS AN ARROW WANTED */
L420:
    if (a3fxi1_1.iarrow <= 0) {
	goto L150;
    } else {
	goto L422;
    }
/* ... HAS LINE GONE OFF  THE FRAME */
L422:
    if (a3fxi1_1.itrunc <= 0) {
	goto L424;
    } else {
	goto L150;
    }
/* ... NO - PLOT AN ARROW */
L424:
    a3fxi1_1.jarrow = a0con_1.k1;
    arrow_();
    goto L150;
/* ... RECORD IS A GO TO POINT - CHECK FOR THREE OR FIVE AXIS */
L430:
    if (a3fxi1_1.multax <= 0) {
	goto L432;
    } else {
	goto L450;
    }
/* ... IT IS 3 AXIS - CHECK FOR TRACUT */
L432:
    i__1 = a3fxi1_1.numwds;
    i__2 = a0con_1.k3;
    for (i__ = a0con_1.k3; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
	ll = i__;
	if (a3fxi1_1.itrafl <= 0) {
	    goto L434;
	} else {
	    goto L436;
	}
/* ... CHECK FOR COPY */
L434:
	if (a3fxi1_1.icopy < 0) {
	    goto L1550;
	} else if (a3fxi1_1.icopy == 0) {
	    goto L438;
	} else {
	    goto L436;
	}
/* ... COPY OR TRACUT IS IN EFFECT THEN TRANSFORM THE POINTS */
L436:
	tsfmpt_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[i__ - 1], &a3fxd1_1.tapsto[
		i__ - 1]);
/* ... CHECK IF SECTN0 PLOT FLAG IS ON - IF IT IS THEN PLOT THE LINE */
L438:
	if (asistm_1.iplotr <= 0) {
	    goto L442;
	} else {
	    goto L439;
	}
/* ... SET THE ARROW SWITCH IN CASE LINE IS TRUNCATED AND PLOT THE LINE */
/* ... IS AN ARROW WANTED */
L439:
	if (a3fxi1_1.iarrow <= 0) {
	    goto L441;
	} else {
	    goto L440;
	}
/* ... YES - SET THE FLAG */
L440:
	a3fxi1_1.jarrow = a0con_1.k1;
/* ... PLOT THE LINE SEGMENT */
L441:
	pl3axs_(&a3fxd1_1.tapsto[i__ - 1]);
L442:
	;
    }
/* ... CHECK FOR ARROW ON LAST POINT OF POINTS RECORD */
    goto L480;
/* ... POINTS ARE 5AXIS - PROCESS AND CHECK FOR COPY,TRACUT AND PLOT */
L450:
    i__2 = a3fxi1_1.numwds;
    i__1 = a0con_1.k6;
    for (i__ = a0con_1.k3; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
	ll = i__;
/* ... CHECK FOR A TRACUT - IF SO TRANSFORM POINTS AND TOOL AXIS VECTORS */
	if (a3fxi1_1.itrafl <= 0) {
	    goto L452;
	} else {
	    goto L454;
	}
/* ... CHECK FOR COPY - IF SO TRANSFORM POINTS AND TOOL AXIS VECTORS */
L452:
	if (a3fxi1_1.icopy < 0) {
	    goto L1550;
	} else if (a3fxi1_1.icopy == 0) {
	    goto L456;
	} else {
	    goto L454;
	}
/* ... COPY OR TRACUT IS IN EFFECT - TRANSFORM POINTS AND TOOL AXIS VECTOR */
L454:
	tsfmpt_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[i__ - 1], &a3fxd1_1.tapsto[
		i__ - 1]);
	tsfmvc_(a3fxd1_1.tmatrx, &a3fxd1_1.tapsto[i__ + 2], &a3fxd1_1.tapsto[
		i__ + 2]);
/* ... NORMALIZE  THE     TRANSFORMED VECTOR */
	vun = sqrt(a3fxd1_1.tapsto[i__ + 2] * a3fxd1_1.tapsto[i__ + 2] + 
		a3fxd1_1.tapsto[i__ + 3] * a3fxd1_1.tapsto[i__ + 3] + 
		a3fxd1_1.tapsto[i__ + 4] * a3fxd1_1.tapsto[i__ + 4]);
	a3fxd1_1.tapsto[i__ + 2] /= vun;
	a3fxd1_1.tapsto[i__ + 3] /= vun;
	a3fxd1_1.tapsto[i__ + 4] /= vun;
/* ... IS THE SECTN0 PLOT FLAG SET - IF SO PLOT THE TOOL PATH */
L456:
	if (asistm_1.iplotr <= 0) {
	    goto L460;
	} else {
	    goto L4561;
	}
/* ...  IS AN ARROWHEAD   WANTED */
L4561:
	if (a3fxi1_1.iarrow <= 0) {
	    goto L4571;
	} else {
	    goto L457;
	}
/* ...  SET LOWER LEVEL   ARROW FLAG */
L457:
	a3fxi1_1.jarrow = a0con_1.k1;
/* ...  PLOT TOOL END PATH */
L4571:
	pl3axs_(&a3fxd1_1.tapsto[i__ - 1]);
/* ... IS THE 5 AXIS PLOT IN EFFECT - IF SO PLOT THE TOOL AXIS VECTOR */
	if (a3fxi1_1.ipl5ax <= 0) {
	    goto L460;
	} else {
	    goto L458;
	}
/* ... SET THE ARROW FLAG TO NOT PUT AN ARROW ON THE AXIS VECTOR */
L458:
	a3fxi1_1.jarrow = a0con_1.k0;
/* ...  PLOT THE TOOL AXISVECTOR */
	pl5axs_(&a3fxd1_1.tapsto[i__ - 1]);
L460:
	;
    }
/* ... PUT AN ARROW ON THE LAST POINT OF RECORD OF POINTS IF PLOT IS ON */
L480:
    if (asistm_1.iplotr <= 0) {
	goto L150;
    } else {
	goto L482;
    }
/* ... IS A PLOT IN EFFECT - IF SO CHECK IF FIRST POINT-IF NOT GO PRINT */
L482:
    if (a3fxi1_1.idplot <= 0) {
	goto L150;
    } else {
	goto L484;
    }
/* ... DO NOT PUT AN ARROW ON THE FIRST POINT IN APLOT SEQUENCE. */
L484:
    if (a3fxi1_1.ifirst - a0con_1.k2 != 0) {
	goto L486;
    } else {
	goto L490;
    }
/* ... NOT FIRST POINT WITHIN A PLOT-SO CHECK IF ARROW IS REQUIRED */
L486:
    if (a3fxi1_1.iarrow - a0con_1.k1 != 0) {
	goto L491;
    } else {
	goto L488;
    }
/* ... HAS ARROW BEEN PUT ON BY TRUNC */
L488:
    if (a3fxi1_1.itrunc - a0con_1.k1 != 0) {
	goto L489;
    } else {
	goto L491;
    }
/* ... SET ARROW FLAG AND PLOT */
L489:
    a3fxi1_1.jarrow = a0con_1.k1;
/* ...  PLOT THE ARROWHEAD */
    arrow_();
    goto L491;
/* ... TURN OFF FIRST POINT FLAG */
L490:
    a3fxi1_1.ifirst = a0con_1.k0;
/* ... IS 5AXIS PLOT ON - IF SO BE SURE VECTOR IS PUT ON LAST POINT */
L491:
    if (a3fxi1_1.ipl5ax <= 0) {
	goto L150;
    } else {
	goto L492;
    }
/* ... SET FLAGS FOR A TOOL AXIS VECTOR BUT NO ARROW ON THE VECTOR */
L492:
    a3fxi1_1.jvectr = a0con_1.k1;
    a3fxi1_1.jarrow = a0con_1.k0;
/* ...  PLOT THE TOOL AXISVECTOR */
    pl5axs_(&a3fxd1_1.tapsto[ll - 1]);
L150:
    *kkk = a0con_1.k1;
    goto L9999;
L1550:
    *kkk = a0con_1.k2;
L9999:
    return 0;
} /* type5_ */

#undef nucltp


