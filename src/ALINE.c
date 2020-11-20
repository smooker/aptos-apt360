/* ALINE.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal defprg[16];
} adfprg_;

#define adfprg_1 adfprg_

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;

/* Subroutine */ int aline_(n)
integer *n;
{
    /* Format strings */
    static char fmt_556[] = "";
    static char fmt_557[] = "";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(), sin(), cos();

    /* Local variables */
    static integer j, k;
#define v ((doublereal *)&adfprg_1 + 3)
    static doublereal x, y;
#define c3 ((doublereal *)&adfprg_1)
#define v1 ((doublereal *)&adfprg_1 + 3)
#define xo ((doublereal *)&adfprg_1 + 9)
#define ans ((doublereal *)&adfprg_1 + 6)
    extern /* Subroutine */ int adot_();
#define svec ((doublereal *)&adfprg_1)
#define tvec ((doublereal *)&adfprg_1)
    static doublereal cnum;
#define xlar ((doublereal *)&adfprg_1 + 12)
#define ylar ((doublereal *)&adfprg_1 + 12)
#define tnor ((doublereal *)&adfprg_1 + 3)
#define xsml ((doublereal *)&adfprg_1 + 12)
#define ysml ((doublereal *)&adfprg_1 + 12)
    static doublereal xnum, ynum, c3len;
#define ambda ((doublereal *)&adfprg_1 + 6)
    extern /* Subroutine */ int aplan_();
    static doublereal denom;
    extern /* Subroutine */ int anorm_();
#define svecn ((doublereal *)&adfprg_1 + 9)
    static doublereal testa;
#define puvec ((doublereal *)&adfprg_1 + 3)
#define punor ((doublereal *)&adfprg_1 + 6)
#define xynor ((doublereal *)&adfprg_1)
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int agenpl_();
    static doublereal ctheta, cosgam;
    extern /* Subroutine */ int alngth_();
    static doublereal singam, cosalp, sinalp, stheta;

    /* Assigned format variables */
    static char *k_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  THIS ROUTINE CONTAINS LINE DEFINITIONS */

/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L310;
	case 4:  goto L405;
	case 5:  goto L510;
	case 6:  goto L1120;
	case 7:  goto L705;
	case 8:  goto L810;
	case 9:  goto L900;
	case 10:  goto L1050;
	case 11:  goto L1160;
	case 12:  goto L101;
	case 13:  goto L3000;
	case 14:  goto L2000;
	case 15:  goto L1000;
	case 16:  goto L1090;
    }

/* ...  DEFPRE ROUTINE FOR FOLLOWING FORMAT */
/* ...  L=LINE/XCOORD,YCOORD,ZCOORD,XCOORD,YCOORD,ZCOORD */
/* ...  THIS ROUTINE IS LIMITED TO 7 PIECES OF DATA */

L100:
    xynor[0] = (float)0.;
    xynor[1] = (float)0.;
    xynor[2] = (float)1.;
    for (j = 1; j <= 3; ++j) {
	v1[j - 1] = deftab[j] - deftab[j + 3];
/* L110: */
    }
    agenpl_(xynor, v1, &deftab[1]);
    goto L3000;

/* ...     LINE/X1,Y1,X2,Y2 */

L200:
    deftab[5] = deftab[4];
    deftab[4] = deftab[3];
    deftab[3] = (float)0.;
    deftab[6] = (float)0.;
    goto L100;

/* ...     LINE/PT1,PT2 */

L310:
    deftab[1] = deftab[2];
    deftab[2] = deftab[3];
    deftab[3] = deftab[4];
    deftab[4] = deftab[6];
    deftab[5] = deftab[7];
    deftab[6] = deftab[8];
    goto L100;

/* ...     LINE/PT1,RIGHT OR LEFT,TANTO,CIR1 */

/* ...  SET UP DATA REGION FOR COMPLIANCE WITH LINE05 ROUTINE */

L405:
    deftab[20] = deftab[14];
    deftab[19] = deftab[13];
    deftab[18] = deftab[12];
    deftab[17] = deftab[11];
    deftab[16] = deftab[10];
    deftab[15] = deftab[9];
    deftab[14] = deftab[8];
    deftab[11] = deftab[5];
    deftab[10] = deftab[18];
    deftab[9] = deftab[19];
    deftab[8] = deftab[18];
    deftab[7] = deftab[18];
    deftab[6] = deftab[4];
    deftab[5] = deftab[3];
    deftab[4] = deftab[2];
    deftab[1] = deftab[11];

/* ...     LINE/RIGHT OR LEFT,TANTO,CIR1,RIGHT OR LEFT,TANTO,CIR2 */

L510:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 8) < 0) {
	goto L593;
    } else if (i__1 == 0) {
	goto L515;
    } else {
	goto L525;
    }
L515:
    if ((i__1 = idftab[OTHER_ENDIAN_S(23)] - 8) < 0) {
	goto L593;
    } else if (i__1 == 0) {
	goto L540;
    } else {
	goto L520;
    }
L520:
    if (idftab[OTHER_ENDIAN_S(23)] - 24 != 0) {
	goto L593;
    } else {
	goto L545;
    }
L525:
    if (idftab[OTHER_ENDIAN_S(3)] - 24 != 0) {
	goto L593;
    } else {
	goto L530;
    }
L530:
    if ((i__1 = idftab[OTHER_ENDIAN_S(23)] - 24) < 0) {
	goto L535;
    } else if (i__1 == 0) {
	goto L540;
    } else {
	goto L593;
    }
L535:
    if (idftab[OTHER_ENDIAN_S(23)] - 8 != 0) {
	goto L593;
    } else {
	goto L545;
    }
L540:
    k = 0;
    k_fmt = fmt_556;
    goto L550;
L545:
    k = 1;
    k_fmt = fmt_557;
L550:
    for (j = 1; j <= 2; ++j) {
	c3[j - 1] = deftab[j + 13] - deftab[j + 3];
/* L555: */
    }
    c3[2] = (float)0.;
    alngth_(c3, &c3len);
    if (c3len <= 0.) {
	goto L595;
    } else {
	goto L5552;
    }
L5552:
/* Computing 2nd power */
    d__1 = c3len;
/* Computing 2nd power */
    d__2 = deftab[10] - deftab[20];
    testa = d__1 * d__1 - d__2 * d__2;
    if (testa >= 0.) {
	goto L5554;
    } else {
	goto L5553;
    }
L5553:
    if (abs(testa) - (float)1e-5 <= 0.) {
	goto L5554;
    } else {
	goto L595;
    }
L5554:
    if (c3len - (deftab[10] + deftab[20]) >= 0.) {
	goto L5556;
    } else {
	goto L5555;
    }
L5555:
    if (idftab[OTHER_ENDIAN_S(3)] - idftab[OTHER_ENDIAN_S(23)] != 0) {
	goto L595;
    } else {
	goto L5556;
    }
L5556:
    sinalp = (deftab[15] - deftab[5]) / c3len;
    cosalp = (deftab[14] - deftab[4]) / c3len;
    switch ((int)k) {
	case 0: goto L556;
	case 1: goto L557;
    }
L556:
    deftab[10] = -deftab[10];
L557:
    singam = (deftab[10] + deftab[20]) / c3len;
/* Computing 2nd power */
    d__1 = singam;
    if (d__1 * d__1 < (float)1.) {
	goto L558;
    }
    cosgam = (float)0.;
    goto L570;
L558:
/* Computing 2nd power */
    d__2 = singam;
    d__1 = (float)1. - d__2 * d__2;
    cosgam = sqrt(d__1);
    if ((i__1 = idftab[OTHER_ENDIAN_S(23)] - 8) < 0) {
	goto L593;
    } else if (i__1 == 0) {
	goto L570;
    } else {
	goto L560;
    }
L560:
    cosgam = -cosgam;
L570:
    defans[0] = singam * cosalp + cosgam * sinalp;
    defans[1] = sinalp * singam - cosgam * cosalp;
/* ...  DEFANS(3)= 0.0 */
    anorm_(defans, defans);
    defans[3] = defans[0] * deftab[14] + defans[1] * deftab[15] - deftab[20];
    goto L3000;

L593:
    a1com_1.jsuber = 1003;
    goto L3000;
L595:
    a1com_1.jsuber = 1005;
    goto L3000;

/* ...     LINE/INTOF,PLN1,PLN2 */

L101:
    xnum = deftab[3] * deftab[10] - deftab[8] * deftab[5];
    ynum = deftab[4] * deftab[10] - deftab[9] * deftab[5];
    cnum = deftab[6] * deftab[10] - deftab[11] * deftab[5];
/* Computing 2nd power */
    d__2 = xnum;
/* Computing 2nd power */
    d__3 = ynum;
    d__1 = d__2 * d__2 + d__3 * d__3;
    denom = sqrt(d__1);
    if (denom != 0.) {
	goto L102;
    } else {
	goto L595;
    }
L102:
    defans[0] = xnum / denom;
    defans[1] = ynum / denom;
/* ...     DEFANS(3) = 0.0 */
    defans[3] = cnum / denom;
    goto L3000;

/* ...     LINE/PT1,PARLEL,LN1 */

L705:
    aplan_(&c__3);
    goto L3000;

/* ...     LINE/PT1,PERPTO,LN1 */

L810:
    defans[0] = -deftab[8];
    defans[1] = deftab[7];
/* ...  DEFANS(3)= 0.0 */
    adot_(&deftab[2], defans, &defans[3]);
    goto L3000;

/* ...     LINE/PARLEL,LN1,X- OR YLARGE OR SMALL,D */

L900:
    if (idftab[OTHER_ENDIAN_S(15)] > 36) {
	goto L593;
    }
    aplan_(&c__4);
    goto L3000;

/* ...     LINE/ATANGL OR SLOPE,A,INTERC,X- OR YAXIS,B */

/*     TEST FOR YAXIS CODE */
L1000:
    if (idftab[OTHER_ENDIAN_S(9)] == 85) {
	goto L1040;
    }
/*     TEST FOR XAXIS CODE */
    if (idftab[OTHER_ENDIAN_S(9)] != 84) {
	goto L593;
    }

/*     SET UP X AND Y COORDINATES */
/* L1030: */
    x = deftab[5];
    y = (float)0.;
    goto L1070;

/*     SET UP Y COORDINATE */
L1040:
    y = deftab[5];
    goto L1060;

/* ...     LINE/ATANGL OR SLOPE,A,INTERC,B */

/*     SET UP Y COORDINATE */
L1050:
    y = deftab[4];
/*     SET UP X COORDINATE */
L1060:
    x = (float)0.;
/*     SET UP POINT ANGLE FORMAT */
L1070:
    deftab[5] = deftab[1];
    deftab[6] = deftab[2];
    deftab[2] = x;
    deftab[3] = y;
    deftab[4] = (float)0.;
    goto L1120;

/* ...     LINE/PT1,ATANGL OR SLOPE,A,X- OR YAXIS */

/*     TEST FOR XAXIS CODE */
L1090:
    if (idftab[OTHER_ENDIAN_S(15)] == 84) {
	goto L1120;
    }
/*     TEST FOR YAXIS CODE */
    if (idftab[OTHER_ENDIAN_S(15)] != 85) {
	goto L593;
    }

/*     SET UP YAXIS AS A LINE */
/* L1110: */
    deftab[8] = (float)1.;
    deftab[9] = (float)0.;
    goto L1130;

/* ...     LINE/PT1,ATANGL OR SLOPE,A */

/*     SET UP XAXIS AS A LINE */
L1120:
    deftab[8] = (float)0.;
    deftab[9] = (float)1.;

/*     SET UP DATA FOR LINE */
L1130:
    deftab[10] = (float)0.;
    deftab[11] = (float)0.;

/* ...     LINE/PT1,ATANGL OR SLOPE,A,LN1 */

/*     TEST FOR SLOPE CODE */
L1160:
    if (idftab[OTHER_ENDIAN_S(11)] == 47) {
	goto L1190;
    }
/*     TEST FOR ATANGL CODE */
    if (idftab[OTHER_ENDIAN_S(11)] != 1) {
	goto L593;
    }

/*     COMPUTE SINE AND COSINE OF ANGLE */
/* L1180: */
    deftab[6] /= (float)57.29577951289617;
    stheta = sin(deftab[6]);
    ctheta = cos(deftab[6]);
    goto L1200;

/*     COMPUTE SINE AND COSINE OF ANGLE */
L1190:
    stheta = deftab[6];
    ctheta = (float)1.;

/*     COMPUTE VECTOR NORMAL TO DESIRED LINE */
L1200:
    defans[0] = deftab[8] * ctheta - deftab[9] * stheta;
    defans[1] = deftab[9] * ctheta + deftab[8] * stheta;

/*     NORMALIZE VECTOR */
/* L1210: */
    anorm_(defans, defans);
    if (a1com_1.jsuber != 0) {
	goto L3000;
    }
/*     CALCULATE DISTANCE FROM ORIGIN TO LINE */
/* L1220: */
    adot_(defans, &deftab[2], &defans[3]);
    goto L3000;

/* ...     LINE/XAXIS OR YAXIS */

/*     TEST FOR XAXIS CODE */
L2000:
    if (idftab[OTHER_ENDIAN_S(3)] == 84) {
	goto L2030;
    }
/*     TEST FOR YAXIS CODE */
    if (idftab[OTHER_ENDIAN_S(3)] != 85) {
	goto L593;
    }

/*     SET YAXIS AS A LINE */
/* L2020: */
    defans[0] = (float)1.;
    goto L3000;

/*     SET UP XAXIS AS A LINE */
L2030:
    defans[1] = (float)1.;
L3000:
    return 0;
} /* aline_ */

#undef defans
#undef idftab
#undef deftab
#undef xynor
#undef punor
#undef puvec
#undef svecn
#undef ambda
#undef ysml
#undef xsml
#undef tnor
#undef ylar
#undef xlar
#undef tvec
#undef svec
#undef ans
#undef xo
#undef v1
#undef c3
#undef v


