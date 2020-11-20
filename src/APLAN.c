/* APLAN.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int aplan_(n)
integer *n;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static doublereal d__;
    static integer j;
#define v ((doublereal *)&adfprg_1 + 3)
#define c3 ((doublereal *)&adfprg_1)
#define v1 ((doublereal *)&adfprg_1 + 3)
    static doublereal v2[3];
#define xo ((doublereal *)&adfprg_1 + 9)
#define ans ((doublereal *)&adfprg_1 + 6)
    extern /* Subroutine */ int adot_();
#define svec ((doublereal *)&adfprg_1)
#define tvec ((doublereal *)&adfprg_1)
#define xlar ((doublereal *)&adfprg_1 + 12)
#define ylar ((doublereal *)&adfprg_1 + 12)
#define tnor ((doublereal *)&adfprg_1 + 3)
#define xsml ((doublereal *)&adfprg_1 + 12)
#define ysml ((doublereal *)&adfprg_1 + 12)
    static doublereal srss;
#define ambda ((doublereal *)&adfprg_1 + 6)
    extern /* Subroutine */ int anorm_();
#define svecn ((doublereal *)&adfprg_1 + 9)
#define puvec ((doublereal *)&adfprg_1 + 3)
#define punor ((doublereal *)&adfprg_1 + 6)
#define xynor ((doublereal *)&adfprg_1)
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int agenpl_(), azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  THIS ROUTINE CONTAINS PLANE DEFINITIONS */

/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L230;
	case 3:  goto L320;
	case 4:  goto L405;
	case 5:  goto L520;
	case 6:  goto L630;
	case 7:  goto L650;
	case 8:  goto L700;
    }

/* ...  DEFPRE ROUTINE FOR FOLLOWING FORMAT */
/* ...  P=PLANE/A B C D  COEFFICIENTS OF THE PLANE EQUATION */
/* ...  THIS ROUTINE IS LIMITED TO 5 PIECES OF DATA */

L100:
/* Computing 2nd power */
    d__1 = deftab[1];
/* Computing 2nd power */
    d__2 = deftab[2];
/* Computing 2nd power */
    d__3 = deftab[3];
    srss = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if (srss != 0.) {
	goto L102;
    } else {
	goto L495;
    }
L102:
    defans[0] = deftab[1] / srss;
    defans[1] = deftab[2] / srss;
    defans[2] = deftab[3] / srss;
    defans[3] = deftab[4] / srss;
    goto L900;

/* ...     PLANE/PT1,PT2,PT3 */

/* ...  SET UP VECTOR 1 AND VECTOR 2 FOR GENERAL PLANE ROUTINE, PT GIVEN */

L230:
    for (j = 1; j <= 3; ++j) {
	v1[j - 1] = deftab[j + 1] - deftab[j + 5];
	v2[j - 1] = deftab[j + 1] - deftab[j + 9];
/* L240: */
    }
    agenpl_(v1, v2, &deftab[2]);
    goto L900;

/* ...     PLANE/PT1,PARLEL,PLN1 */

L320:
    defans[0] = deftab[7];
    defans[1] = deftab[8];
    defans[2] = deftab[9];
    adot_(defans, &deftab[2], &defans[3]);
    goto L900;

/* ...     PLANE/PARLEL,PLN1,X-, Y-, OR ZLARGE OR SMALL,D */

L405:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 31) < 0) {
	goto L493;
    } else if (i__1 == 0) {
	goto L410;
    } else {
	goto L415;
    }
L410:
    if (deftab[3] < 0.) {
	goto L465;
    } else if (deftab[3] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L415:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 32) < 0) {
	goto L493;
    } else if (i__1 == 0) {
	goto L420;
    } else {
	goto L425;
    }
L420:
    if (deftab[3] < 0.) {
	goto L470;
    } else if (deftab[3] == 0) {
	goto L495;
    } else {
	goto L465;
    }
L425:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 35) < 0) {
	goto L493;
    } else if (i__1 == 0) {
	goto L430;
    } else {
	goto L435;
    }
L430:
    if (deftab[4] < 0.) {
	goto L465;
    } else if (deftab[4] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L435:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 36) < 0) {
	goto L493;
    } else if (i__1 == 0) {
	goto L440;
    } else {
	goto L445;
    }
L440:
    if (deftab[4] < 0.) {
	goto L470;
    } else if (deftab[4] == 0) {
	goto L495;
    } else {
	goto L465;
    }
L445:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 39) < 0) {
	goto L493;
    } else if (i__1 == 0) {
	goto L450;
    } else {
	goto L455;
    }
L450:
    if (deftab[5] < 0.) {
	goto L465;
    } else if (deftab[5] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L455:
    if (idftab[OTHER_ENDIAN_S(15)] - 40 != 0) {
	goto L493;
    } else {
	goto L460;
    }
L460:
    if (deftab[5] < 0.) {
	goto L470;
    } else if (deftab[5] == 0) {
	goto L495;
    } else {
	goto L465;
    }
L465:
    d__ = (float)-1.;
    goto L475;
L470:
    d__ = (float)1.;
L475:
    defans[0] = deftab[3] * d__;
    defans[1] = deftab[4] * d__;
    defans[2] = deftab[5] * d__;
    defans[3] = deftab[6] * d__ + deftab[8];
    goto L480;

L493:
    a1com_1.jsuber = 1003;
    goto L480;
L495:
    a1com_1.jsuber = 1005;
L480:
    goto L900;

/* ...     PLANE/PT1,PERPTO,VEC1 */

/* .... TEST FOR ZERO VECTOR */
L520:
    azvect_(&deftab[7]);
    if (a1com_1.jsuber != 0) {
	goto L530;
    } else {
	goto L525;
    }

/* ...     NORMALIZE THE GIVEN VECTOR, AND TAKE THE DOT */
/* ...        PRODUCT OF IT AND THE GIVEN POINT */
L525:
    anorm_(&deftab[7], defans);
    adot_(defans, &deftab[2], &defans[3]);
L530:
    goto L900;

/* ...     PLANE/PERPTO,PL1,PT1,PT2  (ORIGINAL FORMAT) */

/* ...  VECTOR V1 GIVEN, CALCULATE VECTOR V2 FOR GENERAL PLANE ROUTINE. */
L630:
    for (j = 1; j <= 3; ++j) {
	v2[j - 1] = deftab[j + 7] - deftab[j + 11];
/* L640: */
    }
    agenpl_(&deftab[3], v2, &deftab[8]);
    goto L900;

/* ...     PLANE/PT1,PT2,PERPTO,PL1  (ALTERNATE FORMAT) */

/* ...     ONE VECTOR GIVEN, COMPUTE SECOND FOR GENERAL PLANE ROUTINE */
L650:
    for (j = 1; j <= 3; ++j) {
	v2[j - 1] = deftab[j + 1] - deftab[j + 5];
/* L655: */
    }
    agenpl_(&deftab[11], v2, &deftab[2]);
    goto L900;

/* ...     PLANE/SYM PT.,PERPTO,SYM PL1,SYM PL2 */
L700:
    agenpl_(&deftab[7], &deftab[12], &deftab[2]);

L900:
    return 0;
} /* aplan_ */

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


