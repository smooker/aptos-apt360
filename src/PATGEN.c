/* PATGEN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

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
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kfdcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal zsur[4];
} azurf_;

#define azurf_1 azurf_

struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

/* Table of constant values */

static integer c__4 = 4;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__1 = 1;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* Subroutine */ int patgen_(il)
integer *il;
{
    /* Format strings */
    static char fmt_5010[] = "(\0020  PATGEN\002,i8,3z20//)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_8[1];

    /* Builtin functions */
    double sqrt(), cos(), sin();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static doublereal d__;
    static integer m, n, jj, kk, ll;
    static doublereal si, vx, vy, vz, rad;
    static integer dir;
    static doublereal pts;
    static integer ilim;
    static doublereal xcen, ycen, dist;
    static integer ilow;
#define ptpp ((doublereal *)&avst_1)
    static integer npts, nopt1, nopt2;
#define canon ((doublereal *)&avst_1)
#define iodat ((integer *)equiv_8)
    static doublereal radcv, theta, stang, xdcos;
#define kmove ((integer *)&avst_1 + OTHER_ENDIAN_S(12401))
    static doublereal ydcos, xincr, yincr, zincr, zdcos;
    static integer jtemp1, nmsrf1, nmsrf2, nmsrf3, nmsrf4;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
    static doublereal endang;
#define defans ((doublereal *)&adfsto_1 + 3)
#define ioflag ((integer *)equiv_8)
#define kdfans ((shortint *)&adfsto_1 + 12)
    extern integer aextra_();
#define idfsto ((integer *)&adfsto_1)
#define fildat (equiv_8)
#define irecno ((integer *)equiv_8 + 1)
    static doublereal totang;
    extern /* Subroutine */ int aserch_(), ataprd_();
    static integer ispcol, norows, nocols;

    /* Fortran I/O blocks */
    static cilist io___53 = { 0, 0, 0, fmt_5010, 0 };



/*  TO GENERATE A SERIES OF POINTS IN A PATTERN */
/*  IL IS TOTAL NO OF LOCATIONS PLUS 3 */


/* ...     TEST FOR NESTED, UNNAMED, PATTERN - IF SO, ERROR */
    if (a2cls7_1.einame == 0.) {
	goto L820;
    }

    nmsrf1 = idftab[OTHER_ENDIAN_S(3)];
    nmsrf2 = idftab[OTHER_ENDIAN_S(5)];
    nmsrf4 = idftab[OTHER_ENDIAN_S(1)];

/* ...     MOVE INPUT DATA TO REAR OF DEFTAB AREA */
    i__1 = *kmove;
    for (a1pas2_1.j = 4; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	ilim = 1002 - a1pas2_1.j;
	ilow = *kmove + 4 - a1pas2_1.j;
/* L5: */
	deftab[ilim] = deftab[ilow - 1];
    }

/* ...     TEST FOR PARLEL PATTERN */
/* L10: */
    if (nmsrf1 == 17) {
	goto L4000;
    }
/* ...     NO - TEST FOR CIRCUL */
    if (nmsrf1 == 75) {
	goto L2000;
    }
/* ...     TRY LINEAR */
    if (nmsrf1 == 76) {
	goto L1000;
    }
/* ...     HOW ABOUT ARC */
    if (nmsrf1 == 87) {
	goto L2000;
    }
/* ...     IF NOT RANDOM... */
    if (nmsrf1 == 174) {
	goto L3000;
    }
/* ...     ...OR GRID, FORMAT IS INCORRECT */
    if (nmsrf1 == 176) {
	goto L4000;
    }

L800:
    a1com_1.jsuber = 800;
    return 0;
L801:
    a1com_1.jsuber = 801;
    return 0;
L802:
    a1com_1.jsuber = 802;
    return 0;
L820:
    a1com_1.jsuber = 820;
    return 0;

/* ***      LINEAR */
/* ...     FIRST PARAMETER MUST BE A POINT */
L1000:
    if (nmsrf2 != 3001) {
	goto L800;
    }
/* ...     IT IS - MAKE SURE THERE IS SPACE FOR IT */
    if (ilim < 3) {
	goto L802;
    }
/* ...     MOVE IT TO OUTPUT AREA */
    deftab[1] = deftab[ilim];
    deftab[2] = deftab[ilim + 1];
    deftab[3] = deftab[ilim + 2];
    a1pas2_1.j = 5;
/* ...     SEE IF 2ND PARAMETER IS A POINT */
    nmsrf3 = aextra_(&deftab[ilim + 3], &c__4);
    if (nmsrf3 == 3001) {
	goto L1002;
    }
/* ...     NO - IF NOT VECTOR, ERROR */
    if (nmsrf3 == 3011) {
	goto L1004;
    }
    goto L800;

/*         COMPUTE VECTOR SPACING */
L1002:
    xincr = (deftab[ilim + 4] - deftab[ilim]) / (deftab[ilim + 7] - 1.);
    yincr = (deftab[ilim + 5] - deftab[ilim + 1]) / (deftab[ilim + 7] - 1.);
    zincr = (deftab[ilim + 6] - deftab[ilim + 2]) / (deftab[ilim + 7] - 1.);
    goto L1005;

/* ...     PICK UP VECTOR FOR INCREMENTING POINTS */
L1004:
    xincr = deftab[ilim + 4];
    yincr = deftab[ilim + 5];
    zincr = deftab[ilim + 6];

L1005:
    nmsrf1 = aextra_(&deftab[ilim + 7], &c__4);
/* ...     SEE IF 3RD PARAMETER IS 'INCR' */
    if (nmsrf1 == 66) {
	goto L1009;
    }

/* ...     NO... */
/* ...     SET PICK-UP INDEX TO END OF INPUT DATA */
    a1pas2_1.i__ = 999;
    npts = (integer) deftab[ilim + 7];
    n = npts - 1;
    ilim = a1pas2_1.i__;
    goto L1015;

L1009:
/* Computing 2nd power */
    d__1 = deftab[ilim + 4];
/* Computing 2nd power */
    d__2 = deftab[ilim + 5];
/* Computing 2nd power */
    d__3 = deftab[ilim + 6];
    dist = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    xdcos = deftab[ilim + 4] / dist;
    ydcos = deftab[ilim + 5] / dist;
    zdcos = deftab[ilim + 6] / dist;
    ilim += 8;
    a1pas2_1.i__ = ilim;

/* ...     INITIALLY ASSUME NO. AFTER 'INCR' IS NO. OF POINTS TO COMPUTE */
L1010:
    n = (integer) deftab[a1pas2_1.i__];
/* ...     INITIALLY PREPARE TO PICK UP 3RD WORD AFTER 'INCR' */
/* ...     AS DISTANCE BETWEEN POINTS */
    a1pas2_1.l = 3;

/* ...     IF 2ND ENTRY AFTER 'INCR' CAN BE 'AT', MUST HAVE AT */
/* ...     LEAST 3 ENTRIES AFTER 'INCR' */
    if (a1pas2_1.i__ + 2 > 999) {
	goto L1013;
    }
    nmsrf1 = aextra_(&deftab[a1pas2_1.i__ + 1], &a0con_1.k4);
/* ...     SEE IF 2ND ENTRY AFTER 'INCR' IS 'AT' */
    if (nmsrf1 == 175) {
	goto L1011;
    }
/* ...     NO - SET TO COMPUTE SINGLE POINT */
L1013:
    n = 1;
    a1pas2_1.l = 1;

/* ...     SET IL TO PICK UP DISTANCE BETWEEN POINTS */
L1011:
    *il = a1pas2_1.i__ + a1pas2_1.l;
/* ...     COMPUTE COMPONENTS OF INCREMENT TO NEXT POINT */
    xincr = deftab[*il - 1] * xdcos;
    yincr = deftab[*il - 1] * ydcos;
    zincr = deftab[*il - 1] * zdcos;

/* ...     COMPUTE NUMBER OF POINTS REQUIRED AT GIVEN INCREMENT */
L1015:
    i__1 = n;
    for (m = 1; m <= i__1; ++m) {
/* ...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE */
	if (a1pas2_1.j + 2 >= ilim) {
	    goto L802;
	}
	deftab[a1pas2_1.j - 1] = deftab[a1pas2_1.j - 4] + xincr;
	deftab[a1pas2_1.j] = deftab[a1pas2_1.j - 3] + yincr;
	deftab[a1pas2_1.j + 1] = deftab[a1pas2_1.j - 2] + zincr;
	a1pas2_1.j += 3;
/* L1012: */
    }

/*         WAS RECORD JUST PROCESSED AN ( AT ) */
    if (nmsrf1 == 175) {
	a1pas2_1.i__ += 2;
    }
    ++a1pas2_1.i__;
    ilim = a1pas2_1.i__;
/* ...     TEST FOR END OF STATEMENT */
    if (999 <= a1pas2_1.i__) {
	goto L1020;
    }

/* ...     NO - SEE IF NEXT PARAMETER IS WORD 'INCR' */
    if (aextra_(&deftab[a1pas2_1.i__], &c__4) == 66) {
	++a1pas2_1.i__;
    }
    goto L1010;

/* ...     FINISHED... */
L1020:
    kdfans[OTHER_ENDIAN_W(8)] = 1;
    kdfans[OTHER_ENDIAN_W(10)] = (shortint) (a1pas2_1.j - 1);
/* ...     SET IL TO LENGTH OF CANONICAL FORM */
    *il = a1pas2_1.j - 1;
    goto L5000;

/*         CIRCULAR OR ARC */
/* ...     FIRST PARAMETER MUST BE A CIRCLE */
L2000:
    if (nmsrf2 != 3004) {
	goto L800;
    }
    radcv = .017453292519943295;
/*         STARTING ANGLE */
    stang = deftab[ilim + 7] * radcv;
    xcen = deftab[ilim];
    ycen = deftab[ilim + 1];
    rad = deftab[ilim + 6];
    deftab[1] = xcen + rad * cos(stang);
    deftab[2] = ycen + rad * sin(stang);
    deftab[3] = (azurf_1.zsur[3] - azurf_1.zsur[0] * deftab[1] - azurf_1.zsur[
	    1] * deftab[2]) / azurf_1.zsur[2];
    a1pas2_1.j = 5;

/* ...     TEST FOR DIRECTION-OF-ROTATION INDICATOR AFTER STARTING ANGLE */
    dir = aextra_(&deftab[ilim + 8], &c__4);
    if (dir == 59 || dir == 60) {
	goto L2010;
    }

/*         ASSUME DEFTAB(12) EQUAL ENDING ANGLE */
    endang = deftab[ilim + 8] * radcv;
/* ...     DIRECTION-OF-ROTATION INDICATOR MUST FOLLOW ENDING ANGLE */
    dir = aextra_(&deftab[ilim + 9], &c__4);
    if (dir == 59 || dir == 60) {
	goto L2003;
    }
    goto L800;

/* ...     SET D INITIALLY FOR POSITIVE ROTATION ANGLE */
L2003:
    d__ = 1.;
/* ...     IF DIRECTION INDICATOR WAS 'CLW', SET D FOR NEGATIVE ANGLE */
    if (dir == 60) {
	d__ = -d__;
    }
/* ...     COMPUTE TOTAL ARC OF PATTERN */
    totang = endang - stang;
/* ...     COMPARE SIGN OF TOTAL INCREMENT WITH INDICATED ROTATION */
/* ...     DIRECTION, AND ADJUST FOR DIRECTION IF NECESSARY */
    if (totang * d__ > 0.) {
	goto L2005;
    }
/* ...     TOTAL INCREMENT IS IN WRONG DIRECTION - ADJUST IT */
    totang += d__ * 6.2831853072;

/*         NUMBER OF LOCATIONS */
L2005:
    pts = deftab[ilim + 10];
    si = totang / (pts - 1.);
    d__ = 1.;
/* ...     GET NUMBER OF POINTS TO BE DEVELOPED */
    npts = (integer) (pts - 1.);
/* ...     INITIALIZE ANGLE FOR POINTS TO BE DEVELOPED */
    theta = stang;
    a1pas2_1.i__ = 1000;
    ilim = a1pas2_1.i__;
    goto L2020;

L2002:
    kdfans[OTHER_ENDIAN_W(8)] = 2;
    kdfans[OTHER_ENDIAN_W(10)] = (shortint) (a1pas2_1.j - 1);
/* ...     SET IL TO LENGTH OF CANONICAL FORM */
    *il = a1pas2_1.j - 1;
    goto L5000;

/*              INCREMENT */
L2010:
    nmsrf2 = aextra_(&deftab[ilim + 9], &c__4);
/* ...     MUST HAVE 'INCR' FOLLOWING DIRECTION-OF-ROTATION INDICATOR */
/* ...     WHEN ONLY STARTING ANGLE GIVEN */
    if (nmsrf2 != 66) {
	goto L800;
    }
    a1pas2_1.i__ = ilim + 11;
/* ...     SET D INITIALLY FOR POSITIVE ROTATION ANGLE */
    d__ = 1.;
/* ...     IF DIRECTION INDICATOR WAS 'CLW', SET D FOR NEGATIVE ANGLE */
    if (dir == 60) {
	d__ = -d__;
    }
    theta = stang;

/* ...     SEE IF ENOUGH ENTRIES STILL REMAIN TO HAVE AN 'AT' */
L2011:
    if (a1pas2_1.i__ + 2 > 999) {
	goto L2015;
    }
/* ...     TEST FOR 'AT' FOLLOWING ENTRY ABOUT TO BE USED */
    nmsrf3 = aextra_(&deftab[a1pas2_1.i__], &c__4);
    if (nmsrf3 == 175) {
	goto L2012;
    }

/* ...     NO - SINGLE POINT ONLY TO DEVELOP FROM THIS ENTRY */
L2015:
    si = deftab[a1pas2_1.i__ - 1] * radcv;
    ++a1pas2_1.i__;
    npts = 1;
    goto L2020;

/*              INCREMENT WITH AT */
/* ...     PICK UP NUMBER OF POINTS TO BE DEVELOPED */
L2012:
    npts = (integer) deftab[a1pas2_1.i__ - 1];
    si = deftab[a1pas2_1.i__ + 1] * radcv;
/* ...     INCREMENT INPUT PICK-UP INDEX */
    a1pas2_1.i__ += 3;

/* ...     COMPUTE REQUIRED POINTS */
L2020:
    i__1 = npts;
    for (a1pas2_1.k = 1; a1pas2_1.k <= i__1; ++a1pas2_1.k) {
/* ...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE */
	if (a1pas2_1.j + 2 >= ilim) {
	    goto L802;
	}
/* ...     NO - INCREMENT ANGLE FOR NEXT POINT */
	theta = d__ * si + theta;
/* ...     COMPUTE POINT */
	deftab[a1pas2_1.j - 1] = xcen + rad * cos(theta);
	deftab[a1pas2_1.j] = ycen + rad * sin(theta);
	deftab[a1pas2_1.j + 1] = (azurf_1.zsur[3] - azurf_1.zsur[0] * deftab[
		a1pas2_1.j - 1] - azurf_1.zsur[1] * deftab[a1pas2_1.j]) / 
		azurf_1.zsur[2];
/* ...     INCREMENT STORING INDEX FOR NEXT POINT */
	a1pas2_1.j += a0con_1.k3;
/* L2013: */
    }
    ilim = a1pas2_1.i__;

/* ...     TEST FOR END OF STATEMENT */
    if (999 >= a1pas2_1.i__) {
	goto L2011;
    }
    goto L2002;

/*         RANDOM */
L3000:
    a1pas2_1.i__ = a0con_1.k3;
    jj = a0con_1.k2;
    goto L3002;
/* ...     ONLY POINTS OR PATTERNS ACCEPTABLE AS INPUT */
/* ...     TO 'RANDOM' PATTERN */
L3001:
    nmsrf2 = aextra_(&deftab[ilim - 1], &c__4);
L3002:
    if (nmsrf2 == 3018) {
	goto L3010;
    }
    if (nmsrf2 != 3001) {
	goto L800;
    }

/* ...     POINT INPUT */
/* ...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE */
    if (jj + 2 >= ilim) {
	goto L802;
    }
    deftab[jj - 1] = deftab[ilim];
    deftab[jj] = deftab[ilim + 1];
    deftab[jj + 1] = deftab[ilim + 2];
/* ...     INCREMENT INPUT PICK-UP INDEX */
    ilim += 4;
/* ...     INCREMENT STORING INDEX */
    jj += a0con_1.k3;
    goto L3012;

/* ...     PATTERN... */
/* ...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE */
L3010:
    if (jj + aextra_(&deftab[ilim + 1], &c__4) >= ilim) {
	goto L802;
    }
/* ...     NO - LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE */
    *fildat = deftab[ilim];
    aserch_(&ataptb_1.srftap, irecno, ioflag);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (*ioflag >= 0) {
	goto L5200;
    }
/* ...     READ IN PATTERN DEFINITION */
    ataprd_(&ataptb_1.srftap, ioflag, &jtemp1, &c__3, idfsto, &c__3, &
	    adfsto_1.defsto[9], &c__2, &deftab[jj - 1], &c__0);
/* ...     TEST FOR ERROR WHEN READING IN PATTERN */
    if (*ioflag >= 0) {
	goto L5210;
    }
/* ...     INCREMENT STORING INDEX */
    jj += aextra_(&deftab[ilim + 1], &c__4);
/* ...     INCREMENT INPUT PICK-UP INDEX */
    ilim += 4;
/* L3011: */
/* ...     TEST FOR END OF STATEMENT */
L3012:
    if (ilim < 999) {
	goto L3001;
    }

    kdfans[OTHER_ENDIAN_W(8)] = 3;
    kdfans[OTHER_ENDIAN_W(10)] = (shortint) (jj - 1);
/* ...     SET IL TO LENGTH OF CANONICAL FORM */
    *il = jj - 1;
    goto L5000;

/*         PARALLELOGRAM */
/* ...     FIRST PARAMETER OF INPUT MUST BE LINEAR PATTERN */
L4000:
    if (nmsrf2 != 3018) {
	goto L800;
    }
    defans[0] = deftab[ilim + 2];
    if (kdfans[OTHER_ENDIAN_W(0)] != 1) {
	goto L801;
    }
/* ...     EXTRACT NUMBER OF POINTS IN FIRST LINEAR PATTERN */
    nopt1 = (kdfans[OTHER_ENDIAN_W(2)] - 1) / 3;

/* ...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE */
    if (aextra_(&deftab[ilim + 1], &c__4) + 1 >= ilim) {
	goto L802;
    }
/* ...     NO - LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE */
    *fildat = deftab[ilim];
    aserch_(&ataptb_1.srftap, irecno, ioflag);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (*ioflag >= 0) {
	goto L5200;
    }
/* ...     READ IN PATTERN DEFINITION */
    ataprd_(&ataptb_1.srftap, ioflag, &jtemp1, &c__3, idfsto, &c__3, &
	    adfsto_1.defsto[9], &c__2, &deftab[1], &c__0);
/* ...     TEST FOR ERROR WHEN READING IN PATTERN */
    if (*ioflag >= 0) {
	goto L5210;
    }
    jj = aextra_(&deftab[ilim + 1], &c__4) + 2;

/* ...     INITIALIZE FLAG TO INDICATE COLUMN SPACING FOR PARLEL */
/* ...     PATTERN BEING OBTAINED FROM SPECIFIED INCREMENTS */
    ispcol = 0;
/* ...     NUMBER OF ROWS FOR PARLEL PATTERN = NUMBER OF */
/* ...     POINTS IN FIRST LINEAR PATTERN */
    norows = nopt1;
/* ...     INITIALIZE NUMBER OF COLUMNS IN PARLEL PATTERN */
    nopt2 = 1;
    ilim += 4;
    nmsrf2 = aextra_(&deftab[ilim - 1], &c__4);
/* ...     TEST FOR VECTOR AS 2ND INPUT PARAMETER */
    if (nmsrf2 != 3011) {
	goto L4008;
    }

/* ...     VECTOR FOUND - COMPUTE ITS LENGTH */
    ll = ilim;
/* Computing 2nd power */
    d__1 = deftab[ll];
/* Computing 2nd power */
    d__2 = deftab[ll + 1];
/* Computing 2nd power */
    d__3 = deftab[ll + 2];
    dist = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* ...     TEST FOR 'INCR' TYPE SPACING */
    nmsrf3 = aextra_(&deftab[ilim + 3], &c__4);
    if (nmsrf3 == 66) {
	goto L4015;
    }

/* ...     NO - PICK UP NUMBER OF POINTS TO BE DEVELOPED */
    nopt2 = (integer) deftab[ilim + 3];
/* ...     MAKE SURE THIS IS END OF STATEMENT - IF NOT, ERROR */
    if (ilim + 4 != 999) {
	goto L800;
    }
/* ...     PICK UP INCREMENTAL SPACING FOR POINTS */
    xincr = deftab[ilim];
    yincr = deftab[ilim + 1];
    zincr = deftab[ilim + 2];
/* ...     COMPUTE NUMBER OF COLUMNS TO BE ADDED TO PARLEL PATTERN */
    nocols = nopt2 - 1;
/* ...     SET FLAG TO INDICATE SPACING OF COLUMNS BEING OBTAINED */
/* ...     FROM A VECTOR AND A SINGLE COUNT ONLY */
    ispcol = -1;
    ilim = 999;
    goto L4040;

/* ...     COMPUTE PARALLEL PATTERN WITH 'INCR' */
L4015:
    ilim += 5;
/* ...     IF NO INPUT DATA FOLLOWING 'INCR', ERROR - INCORRECT FORMAT */
    if (ilim > 999) {
	goto L800;
    }
    vx = deftab[ll];
    vy = deftab[ll + 1];
    vz = deftab[ll + 2];

/* ...     INITIALIZE COUNTER TO DEVELOP ONE COLUMN ONLY */
L4020:
    nocols = 1;
/* ...     SEE IF ENOUGH ENTRIES STILL REMAIN TO HAVE AN 'AT' */
    if (ilim + 2 > 999) {
	goto L4022;
    }
/* ...     SEE IF THIS IS A REPEATED INCREMENT 'AT' COMMON SPACING */
/* L4021: */
    nmsrf3 = aextra_(&deftab[ilim], &c__4);
    if (nmsrf3 != 175) {
	goto L4022;
    }

/* ...     PROCESS INCR WITH 'AT' */
    nocols = (integer) deftab[ilim - 1];
    ilim += 2;
    goto L4022;

/* ...     2ND PARAMETER OF INPUT WAS NOT A VECTOR - MUST THEN BE */
/* ...     LINEAR PATTERN, OR ERROR */
L4008:
    if (nmsrf2 != 3018) {
	goto L800;
    }
    defans[0] = deftab[ilim + 2];
    if (kdfans[OTHER_ENDIAN_W(0)] != 1) {
	goto L801;
    }

    *fildat = deftab[ilim];
/* ...     TEST FOR SUFFICIENT ROOM IN WORKING STORAGE FOR 2ND PATTERN */
    if (jj > 999 - aextra_(&deftab[ilim + 1], &c__4)) {
	goto L802;
    }
/* ...     YES - SET ILIM DOWN TO MAKE ROOM FOR PATTERN */
    ilim = 1003 - aextra_(&deftab[ilim + 1], &c__4);
/* ...     LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE */
    aserch_(&ataptb_1.srftap, irecno, ioflag);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (*ioflag >= 0) {
	goto L5200;
    }
/* ...     READ IN PATTERN DEFINITION */
    ataprd_(&ataptb_1.srftap, ioflag, &jtemp1, &c__3, idfsto, &c__3, &
	    adfsto_1.defsto[9], &c__2, &deftab[ilim - 4], &c__0);
/* ...     TEST FOR ERROR WHEN READING IN PATTERN */
    if (*ioflag >= 0) {
	goto L5210;
    }
/* ...     SET FLAG TO INDICATE SPACING OF COLUMNS BEING OBTAINED */
/* ...     FROM A LINEAR PATTERN */
    vx = deftab[ilim - 4];
    vy = deftab[ilim - 3];
    vz = deftab[ilim - 2];
    ispcol = 1;

/* ...     SET COUNTER TO DEVELOP ONE COLUMN AT A TIME */
L4012:
    nocols = 1;
/* ...     NOT FINISHED YET - COMPUTE NEXT INCREMENT */
    xincr = deftab[ilim - 1] - vx;
    yincr = deftab[ilim] - vy;
    zincr = deftab[ilim + 1] - vz;
    vx = deftab[ilim - 1];
    vy = deftab[ilim];
    vz = deftab[ilim + 1];
/* ...     INCREMENT PICK-UP INDEX TO NEXT POINT */
    ilim += 3;
    goto L4018;

/* ...     COMPUTE NEXT INCREMENT FROM INPUT VECTOR AND DISTANCE */
/*         DEFTAB(I) IS THE DESIRED SPACING */
L4022:
    xincr = deftab[ilim - 1] * vx / dist;
    yincr = deftab[ilim - 1] * vy / dist;
    zincr = deftab[ilim - 1] * vz / dist;
    ++ilim;

/* ...     INCREMENT NUMBER OF COLUMNS FOR PARLEL PATTERN */
L4018:
    nopt2 += nocols;

L4040:
    i__1 = nocols;
    for (m = 1; m <= i__1; ++m) {
	kk = jj - a0con_1.k1;
	i__2 = norows;
	for (a1pas2_1.l = 1; a1pas2_1.l <= i__2; ++a1pas2_1.l) {
/* ...     TEST FOR OVERFLOW OF DEFANS AREA */
	    if (jj + 2 >= ilim) {
		goto L802;
	    }
/* ...     NO - COMPUTE NEXT POINT */
	    deftab[jj - 1] = deftab[kk - 3] + xincr;
	    deftab[jj] = deftab[kk - 2] + yincr;
	    deftab[jj + 1] = deftab[kk - 1] + zincr;
	    jj += a0con_1.k3;
/* L4023: */
	    kk -= a0con_1.k3;
	}
/* L4024: */
    }

/* ...     TEST FOR END OF STATEMENT */
    if (ilim > 999) {
	goto L4030;
    }

/* ...     NO - BRANCH ON ISPCOL SETTING TO OBTAIN POSITION OF NEXT COL. */
    if (ispcol < 0) {
	goto L4030;
    } else if (ispcol == 0) {
	goto L4020;
    } else {
	goto L4012;
    }

/* ...     NOPT2 IS TOTAL NUMBER OF COLUMNS IN A PARLEL PATTERN (USED */
/* ...     IN POINT EXTRACTION) */
L4030:
    kdfans[OTHER_ENDIAN_W(8)] = 4;
    kdfans[OTHER_ENDIAN_W(10)] = (shortint) (jj - 1);
    kdfans[OTHER_ENDIAN_W(11)] = (shortint) nopt2;
/* ...     SET IL TO LENGTH OF CANONICAL FORM */
    *il = jj - 1;

/* ...     PUT LENGTH OF PATTERN INTO CANON RECORD, AND WRITE DATA */
/* ...     ONTO LARGE SURFACE FILE */
L5000:
    idftab[OTHER_ENDIAN_S(1)] = *il;
    *il = 6;

    if (a1com_1.kdbug == 0) {
	goto L5100;
    }
    io___53.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___53);
    do_fio(&c__1, (char *)&(*il), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&defans[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[2], (ftnlen)sizeof(doublereal));
    e_wsfe();

L5100:
    return 0;

/* ...     ERROR IN SEARCH OF LARGE SURFACE FILE FOR PATTERN */
L5200:
    a1com_1.jsuber = 840;
    goto L5100;
/* ...     ERROR IN READING OF PATTERN FROM LARGE SURFACE FILE */
L5210:
    a1com_1.jsuber = 841;
    goto L5100;

} /* patgen_ */

#undef irecno
#undef fildat
#undef idfsto
#undef kdfans
#undef ioflag
#undef defans
#undef idftab
#undef deftab
#undef kmove
#undef iodat
#undef canon
#undef ptpp


