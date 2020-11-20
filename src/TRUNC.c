/* TRUNC.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int trunc_(x11, y11, x22, y22)
doublereal *x11, *y11, *x22, *y22;
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    extern integer nxv_(), nyv_();
    static doublereal param;
    extern /* Subroutine */ int linev_(), arrow_();
#define nucltp ((doublereal *)&ataptb_1 + 7)

/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */
/* ... THIS ROUTINE WILL CHECK THE LINE SEGMENT TO SEE IF IT IS TOTALLY */
/* ... INSIDE THE PLOT FRAME.  IF THE LINE IS NOT, THEN THE ROUTINE WILL */
/* ... TRUNCATE IT AT THE FRAME EDGE AND,IF REQUESTED,WILL PUT */
/* ... AN ARROWHEAD ON THE END. */
/* ....******************************************************************* */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ....******************************************************************* */
    a3fxd1_1.x1 = *x11;
    a3fxd1_1.x2 = *x22;
    a3fxd1_1.y1 = *y11;
    a3fxd1_1.y2 = *y22;
    a3fxi1_1.itrunc = a0con_1.k0;
/* ... DOES THE LINE HAVE LENGTH */
    if ((d__1 = a3fxd1_1.x2 - a3fxd1_1.x1, abs(d__1)) + (d__2 = a3fxd1_1.y2 - 
	    a3fxd1_1.y1, abs(d__2)) != 0.) {
	goto L270;
    } else {
	goto L9999;
    }
/* ...  IS FIRST POINT RIGHT OF LEFT EDGE - LESS THAN MEANS NO. GO TRUNC. */
L270:
    if (a3fxd1_1.ptu[a3fxi1_1.ipx - 1] - a3fxd1_1.x1 >= 0.) {
	goto L275;
    } else {
	goto L1000;
    }
/* ...  IS FIRST POINT LEFT OF RIGHT EDGE - LESS THAN MEANS NO. GO TRUNC. */
L275:
    if (a3fxd1_1.x1 - a3fxd1_1.pt0[a3fxi1_1.ipx - 1] >= 0.) {
	goto L280;
    } else {
	goto L1000;
    }
/* ...  IS FIRST POINT BELOW TOP EDGE - LESS THAN MEANS NO. GO TRUNC. */
L280:
    if (a3fxd1_1.ptu[a3fxi1_1.ipy - 1] - a3fxd1_1.y1 >= 0.) {
	goto L285;
    } else {
	goto L1000;
    }
/* ...  IS FIRST POINT ABOVE BOTTOM EDGE - LESS THAN MEANS NO. GO TRUNC. */
L285:
    if (a3fxd1_1.y1 - a3fxd1_1.pt0[a3fxi1_1.ipy - 1] >= 0.) {
	goto L290;
    } else {
	goto L1000;
    }
/* ...  IS SECOND POINT RIGHT OF LEFT EDGE - LESS THAN MEANS NO. GO TRUNC. */
L290:
    if (a3fxd1_1.ptu[a3fxi1_1.ipx - 1] - a3fxd1_1.x2 >= 0.) {
	goto L295;
    } else {
	goto L1000;
    }
/* ...  IS SECOND POINT LEFT OF RIGHT EDGE - LESS THAN MEANS NO.GO TRUNC. */
L295:
    if (a3fxd1_1.x2 - a3fxd1_1.pt0[a3fxi1_1.ipx - 1] >= 0.) {
	goto L300;
    } else {
	goto L1000;
    }
/* ...  IS SECOND POINT BELOW TOP EDGE - LESS THAN MEANS NO. GO TRUNC. */
L300:
    if (a3fxd1_1.ptu[a3fxi1_1.ipy - 1] - a3fxd1_1.y2 >= 0.) {
	goto L305;
    } else {
	goto L1000;
    }
/* ...  IS SECOND POINT ABOVE BOTTOM EDGE - LESS THAN MEANS NO. GO TRUNC. */
L305:
    if (a3fxd1_1.y2 - a3fxd1_1.pt0[a3fxi1_1.ipy - 1] >= 0.) {
	goto L330;
    } else {
	goto L1000;
    }
/* ...  END POINTS ARE INSIDE FRAME - PLOT THE LINE SEGMENT. */
L330:
    a3fxi1_1.nx1 = nxv_(&a3fxd1_1.x1);
    a3fxi1_1.ny1 = nyv_(&a3fxd1_1.y1);
    a3fxi1_1.nx2 = nxv_(&a3fxd1_1.x2);
    a3fxi1_1.ny2 = nyv_(&a3fxd1_1.y2);
/* ... */
/* ...   PLOT A LINE SEGMENT */
    linev_(&a3fxi1_1.nx1, &a3fxi1_1.ny1, &a3fxi1_1.nx2, &a3fxi1_1.ny2);
/* ...  HAS THE LINE ALREADY BEEN TRUNCATED - EQUAL MEANS YES-GO PUT ARROW */
    if (a3fxi1_1.itrunc - a0con_1.k1 != 0) {
	goto L9999;
    } else {
	goto L8000;
    }
/* ...  HAS THE LINE BEEN TRUNCATED - LESS THAN MEANS NO. */
L1000:
    if (a3fxi1_1.itrunc - a0con_1.k1 >= 0) {
	goto L9999;
    } else {
	goto L1050;
    }
/* ...  LINE SEGMENT IS NOT COMPLETELY INSIDE OF FRAME...TRUNCATE IT. */
L1050:
    a3fxi1_1.itrunc = a0con_1.k1;
    a3fxd1_1.delx = a3fxd1_1.x2 - a3fxd1_1.x1;
    a3fxd1_1.dely = a3fxd1_1.y2 - a3fxd1_1.y1;
/* ...  DO WE CONSIDER THE Y LIMIT - EQUAL ZERO MEANS NO. CHECK X LIMIT. */
    if (a3fxd1_1.dely != 0.) {
	goto L1060;
    } else {
	goto L1160;
    }
/* ...  COMPARE LINE SEGMENT WITH UPPER EDGE. */
L1060:
    param = (a3fxd1_1.ptu[a3fxi1_1.ipy - 1] - a3fxd1_1.y1) / a3fxd1_1.dely;
/* ...  IF PARAM IS      MINUS THEN CHECK BOTTOM EDGE. */
    if (param >= 0.) {
	goto L1070;
    } else {
	goto L1110;
    }
/* ...  IF PARAM IS GREATER THAN 1 THEN CHECK BOTTOM EDGE. */
L1070:
    if (param - (float)1. <= 0.) {
	goto L1080;
    } else {
	goto L1110;
    }
/* ...  LINE PIERCES TOP EDGE - COMPUTE NEW X VALUE AT TOP EDGE. */
L1080:
    a3fxd1_1.xnew = a3fxd1_1.delx * param + a3fxd1_1.x1;
    a3fxd1_1.ynew = a3fxd1_1.ptu[a3fxi1_1.ipy - 1];
/* ...  WAS THE FIRST POINT ABOVE TOP EDGE -LT MEANS 2ND PT,GT MEANS 1STPT */
    if ((d__1 = a3fxd1_1.y1 - a3fxd1_1.ptu[a3fxi1_1.ipy - 1]) < 0.) {
	goto L1100;
    } else if (d__1 == 0) {
	goto L1110;
    } else {
	goto L1090;
    }
/* ...  SET FIRST POINT TO NEW VALUE AND COMPARE LINE WITH BOTTOM EDGE. */
L1090:
    a3fxd1_1.x1 = a3fxd1_1.xnew;
    a3fxd1_1.y1 = a3fxd1_1.ynew;
    goto L1105;
/* ...  SET SECOND POINT TO NEW VALUE AND COMPARE WITH BOTTOM EDGE. */
L1100:
    a3fxd1_1.x2 = a3fxd1_1.xnew;
    a3fxd1_1.y2 = a3fxd1_1.ynew;
L1105:
    a3fxd1_1.delx = a3fxd1_1.x2 - a3fxd1_1.x1;
    a3fxd1_1.dely = a3fxd1_1.y2 - a3fxd1_1.y1;
/* ...  COMPARE LINE SEGMENT WITH LOWER EDGE. */
L1110:
    param = (a3fxd1_1.pt0[a3fxi1_1.ipy - 1] - a3fxd1_1.y1) / a3fxd1_1.dely;
/* ...  IF PARAM IS MINUS THEN CHECK RIGHT EDGE. */
    if (param >= 0.) {
	goto L1120;
    } else {
	goto L1160;
    }
/* ...  IF PARAM IS GREATER THAN 1 THEN CHECK RIGHT EDGE. */
L1120:
    if (param - (float)1. <= 0.) {
	goto L1130;
    } else {
	goto L1160;
    }
/* ...  LINE PIERCES BOTTOM EDGE - COMPUTE NEW X VALUE AT BOTTOM EDGE */
L1130:
    a3fxd1_1.xnew = a3fxd1_1.delx * param + a3fxd1_1.x1;
    a3fxd1_1.ynew = a3fxd1_1.pt0[a3fxi1_1.ipy - 1];
/* ...  WAS FIRST POINTBELOW BOT. EDGE - LT MEANS 1ST PT. GT MEANS 2ND PT. */
    if ((d__1 = a3fxd1_1.y1 - a3fxd1_1.pt0[a3fxi1_1.ipy - 1]) < 0.) {
	goto L1140;
    } else if (d__1 == 0) {
	goto L1160;
    } else {
	goto L1150;
    }
/* ...  SET FIRST POINT TO NEW VALUE AND COMPARE WITH RIGHT EDGE. */
L1140:
    a3fxd1_1.x1 = a3fxd1_1.xnew;
    a3fxd1_1.y1 = a3fxd1_1.ynew;
    goto L1155;
/* ...  SET SECOND POINT TO NEW VALUE AND COMPARE WITH RIGHT EDGE. */
L1150:
    a3fxd1_1.x2 = a3fxd1_1.xnew;
    a3fxd1_1.y2 = a3fxd1_1.ynew;
L1155:
    a3fxd1_1.delx = a3fxd1_1.x2 - a3fxd1_1.x1;
    a3fxd1_1.dely = a3fxd1_1.y2 - a3fxd1_1.y1;
/* ...  DO WE CONSIDER THE X LIMIT - EQUAL ZERO MEANS NO. SEE IF PT IN FRM */
L1160:
    if (a3fxd1_1.delx != 0.) {
	goto L1170;
    } else {
	goto L270;
    }
/* ...  COMPARE LINE SEGMENT WITH RIGHT EDGE. */
L1170:
    param = (a3fxd1_1.ptu[a3fxi1_1.ipx - 1] - a3fxd1_1.x1) / a3fxd1_1.delx;
/* ...  IF PARAM IS MINUS THEN CHECK LEFT EDGE. */
    if (param >= 0.) {
	goto L1180;
    } else {
	goto L1220;
    }
/* ...  IF PARAM IS GREATER THAN 1 THEN CHECK LEFT EDGE. */
L1180:
    if (param - (float)1. <= 0.) {
	goto L1190;
    } else {
	goto L1220;
    }
/* ...  LINE PIERCES RIGHT EDGE - COMPUTE NEW Y VALUE AT RIGHT EDGE */
L1190:
    a3fxd1_1.xnew = a3fxd1_1.ptu[a3fxi1_1.ipx - 1];
    a3fxd1_1.ynew = a3fxd1_1.dely * param + a3fxd1_1.y1;
/* ...  WAS FIRST POINT RIGHT OF RIGHT EDGE -LT MEANS 2ND PT. GT MEANS 1ST */
    if ((d__1 = a3fxd1_1.x1 - a3fxd1_1.ptu[a3fxi1_1.ipx - 1]) < 0.) {
	goto L1210;
    } else if (d__1 == 0) {
	goto L1220;
    } else {
	goto L1200;
    }
/* ...  SET FIRST POINT TO NEW VALUE AND COMPARE WITH LEFT EDGE. */
L1200:
    a3fxd1_1.x1 = a3fxd1_1.xnew;
    a3fxd1_1.y1 = a3fxd1_1.ynew;
    goto L1215;
/* ...  SET SECOND POINT TO NEW VALUE AND COMPARE WITH LEFT EDGE. */
L1210:
    a3fxd1_1.x2 = a3fxd1_1.xnew;
    a3fxd1_1.y2 = a3fxd1_1.ynew;
L1215:
    a3fxd1_1.delx = a3fxd1_1.x2 - a3fxd1_1.x1;
    a3fxd1_1.dely = a3fxd1_1.y2 - a3fxd1_1.y1;
/* ...  COMPARE LINE SEGMENT WITH LEFT EDGE. */
L1220:
    param = (a3fxd1_1.pt0[a3fxi1_1.ipx - 1] - a3fxd1_1.x1) / a3fxd1_1.delx;
/* ...  IF PARAM IS MINUS THEN SEE IF LINE SEGMENT TOTALLY IN FRAME. */
    if (param >= 0.) {
	goto L1230;
    } else {
	goto L270;
    }
/* ...  IF PARAM GREATER THAN 1 THEN SEE IF LINE SEGMENT TOTALLY IN FRAME. */
L1230:
    if (param - (float)1. <= 0.) {
	goto L1240;
    } else {
	goto L270;
    }
/* ...  LINE PIERCES LEFT EDGE - COMPUTE NEW Y VALUE AT LEFT EDGE. */
L1240:
    a3fxd1_1.xnew = a3fxd1_1.pt0[a3fxi1_1.ipx - 1];
    a3fxd1_1.ynew = a3fxd1_1.dely * param + a3fxd1_1.y1;
/* ...  WAS FIRST POINT LEFT OF LEFT EDGE - LT MEANS 1ST PT. GT MEANS 2ND. */
    if ((d__1 = a3fxd1_1.x1 - a3fxd1_1.pt0[a3fxi1_1.ipx - 1]) < 0.) {
	goto L1250;
    } else if (d__1 == 0) {
	goto L270;
    } else {
	goto L1260;
    }
/* ...  SET FIRST POINT TO NEW VALUE AND CHECK IF SEGMENT INSIDE OF FRAME. */
L1250:
    a3fxd1_1.x1 = a3fxd1_1.xnew;
    a3fxd1_1.y1 = a3fxd1_1.ynew;
    goto L270;
/* ...  SET SECOND POINT TO NEW VALUE AND CHECK IF INSIDE OF FRAME. */
L1260:
    a3fxd1_1.x2 = a3fxd1_1.xnew;
    a3fxd1_1.y2 = a3fxd1_1.ynew;
    goto L270;
/* *********************************************************************** */
/* ... */
/* ...  LINE HAS BEEN TRUNCATED-PUT ARROW ON - IF IARROW IS NON-ZERO. */
L8000:
    if (a3fxi1_1.iarrow != 0) {
	goto L8020;
    } else {
	goto L9999;
    }
L8020:
    arrow_();
L9999:
    return 0;
} /* trunc_ */

#undef nucltp


