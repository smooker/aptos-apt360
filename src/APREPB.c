/* APREPB.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Table of constant values */

static integer c__11 = 11;
static integer c__22 = 22;

/* Subroutine */ int aprepb_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double d_sign(), sqrt();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6200)
    static integer i__, j, k, l, n;
    static doublereal a1, b1, a2, b2, x2, x3, y2, y3;
    static integer mn;
    static doublereal dx1, dx2, dy2, dy1, dcl, dcp, sl1sq, sl2sq, dcmax;
#define deftab ((doublereal *)&avst_1 + 6200)
    extern integer ideftb_();
    static doublereal dcmaxp;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 3, MODIFICATION 0 *** */

/*               *          *          *          *          * */
/* *********************************************************************** */
/*     DEFINE FUNCTIONS */

/* ...  DEFINE TANF SO THAT ITS MAXIMUM MAGNITUDE IS 10**9 */


/* ...  SPLINE FIT */
/* ...  L=1,NO SLOPES */
/* ...  L=2,SLOPE GIVEN AT FIRST POINT ONLY */
/* ...  L=3,SLOPE GIVEN AT LAST POINT ONLY */
/* ...  L=4,SLOPE GIVEN AT FIRST AND LAST POINTS */


/* L8008: */
    k = ideftb_(&c__11) * 7 - 1;
    sl1sq = (float)0.;
    mn = 0;
    if (ideftb_(&c__22) + 1 != 0) {
	goto L2;
    } else {
	goto L3;
    }
L2:
    i__1 = k + 9;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L7;
    } else {
	goto L4;
    }
L4:
    l = 2;
    goto L991;
L7:
    l = 4;
    goto L991;
L3:
    i__1 = k + 9;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L9;
    } else {
	goto L998;
    }
L998:
    l = 1;
    goto L991;
L9:
    l = 3;
L991:
    n = 20;

/* ...  PASS CIRCLE THRU 3 PTS TO GET FIRST */
/* ...  APPROXIMATION FOR SLOPES. */
L8:
    d__1 = d__[n + 6] - d__[n - 1];
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    dx2 = d_sign(&d__2, &d__1);
    dy2 = d__[n + 7] - d__[n];
    sl2sq = dx2 * dx2 + dy2 * dy2;
/* L11: */
    d__[n + 3] = sqrt(sl2sq);
    d__[n + 2] = dy2 / dx2;
/* L13: */
    n += 7;
/* L14: */
    if (l - 5 != 0) {
	goto L15;
    } else {
	goto L17;
    }
L15:
    if (n - 27 != 0) {
	goto L16;
    } else {
	goto L17;
    }
L16:
    d__1 = sl1sq * dx2 + sl2sq * dx1;
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[n - 6] = (sl1sq * dy2 + sl2sq * dy1) / d_sign(&d__2, &d__1);
L17:
    if (n - k - 7 >= 0) {
	goto L24;
    } else {
	goto L18;
    }
L18:
    x2 = x3;
/* L19: */
    y2 = y3;
    dx1 = dx2;
    dy1 = dy2;
    sl1sq = sl2sq;
    goto L8;
L24:
    n = 27;
/* L25: */
    b1 = (d__[n + 1] - d__[n - 5]) / ((float)1. + d__[n + 1] * d__[n - 5]);
/* L26: */
    if (l - 1 != 0) {
	goto L27;
    } else {
	goto L28;
    }
L27:
    if (l - 3 != 0) {
	goto L31;
    } else {
	goto L28;
    }

/* ...  FIND SLOPE AT FIRST PT BY REFLECTING ANGLE FROMSECOND PT */

L28:
    a1 = -b1;
/* L29: */
    d__1 = (float)1. - d__[22] * a1;
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[21] = (d__[22] + a1) / d_sign(&d__2, &d__1);
/* L30: */
    goto L32;
L31:
    a1 = (d__[n - 6] - d__[n - 5]) / ((float)1. + d__[n - 6] * d__[n - 5]);
L32:
    a2 = (d__[n + 1] - d__[n + 2]) / ((float)1. + d__[n + 1] * d__[n + 2]);
/* L33: */
    if (n - k != 0) {
	goto L36;
    } else {
	goto L34;
    }
L34:
    if (l - 3 >= 0) {
	goto L36;
    } else {
	goto L38;
    }
L36:
    b2 = (d__[n + 8] - d__[n + 2]) / ((float)1. + d__[n + 8] * d__[n + 2]);
/* L37: */
    goto L40;
L38:
    b2 = -a2;
/* L39: */
    d__1 = (float)1. - d__[n + 2] * b2;
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[k + 8] = (d__[n + 2] + b2) / d_sign(&d__2, &d__1);

/* ...  CALCULATE DELTA CURVATURE AT EACH PT */

L40:
    d__[n + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[n + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[n - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
/* L41: */
    n += 7;
/* L42: */
    if (n - k - 7 >= 0) {
	goto L46;
    } else {
	goto L43;
    }
L43:
    a1 = a2;
/* L44: */
    b1 = b2;
/* L45: */
    goto L32;

/* ...  FIND MAX. DELTA CURVATURE */

L46:
    dcmaxp = (float)0.;
/* L47: */
    dcmax = (float)0.;
    dcl = (float).001;
/* L48: */
    n = 27;
L49:
    dcmax = (d__1 = d__[n + 4], abs(d__1));
/* L50: */
    if (dcmax - dcmaxp <= 0.) {
	goto L53;
    } else {
	goto L51;
    }
L51:
    dcmaxp = dcmax;
/* L52: */
    j = n;
L53:
    n += 7;
/* L54: */
    if (n - k - 7 >= 0) {
	goto L55;
    } else {
	goto L49;
    }

/* ...  CHECK MAX.D.C. WITH LIMIT(DCL),CHECK NO. OF */
/* ...    ITERATIONS(MN) WITH LIMIT(4*K) */

L55:
    if (dcmaxp - dcl <= 0.) {
	goto L8004;
    } else {
	goto L56;
    }
L56:
    if (mn - (k << 2) >= 0) {
	goto L8004;
    } else {
	goto L57;
    }

/* ...  ADJUST SLOPE AT POINT(D(J),D(J-1)) OF MAX.D.C. */
/* ...    ALSO,AT POINT(D(J-7),D(J-6)),AND POINT(D(J+7),D(D+8)) */

L57:
    a1 = (d__[j - 6] - d__[j - 5]) / ((float)1. + d__[j - 6] * d__[j - 5]);
/* L58: */
    b2 = (d__[j + 8] - d__[j + 2]) / ((float)1. + d__[j + 8] * d__[j + 2]);
/* L59: */
    a2 = (d__[j + 1] - d__[j + 2]) / ((float)1. + d__[j + 1] * d__[j + 2]);

/* ... DCP = APPROXIMATION FOR FIRST DERIVATIVE OF DELTA CURVATURE */
/* ... TO USE WITH NEWTONS METHOD FOR FINDING THE SLOPE WHICH MAKES */
/* ... DELTA CURVATURE APPROXIMATELY ZERO */

/* L60: */
    dcp = (d__[j - 4] + d__[j + 3]) * (float)-4. / (d__[j - 4] * d__[j + 3]);
/* L61: */
    i__ = 1;
L62:
    a2 -= d__[j + 4] / dcp;
/* L63: */
    d__1 = (float)1. - a2 * d__[j + 2];
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[j + 1] = (a2 + d__[j + 2]) / d_sign(&d__2, &d__1);
/* L64: */
    b1 = (d__[j + 1] - d__[j - 5]) / ((float)1. + d__[j + 1] * d__[j - 5]);
/* L65: */
    d__[j + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[j + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[j - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
/* L66: */
    if ((d__1 = d__[j + 4], abs(d__1)) - dcl <= 0.) {
	goto L70;
    } else {
	goto L67;
    }
L67:
    if (i__ - 5 >= 0) {
	goto L70;
    } else {
	goto L68;
    }
L68:
    ++i__;
/* L69: */
    goto L62;
L70:
    n = j - 7;
/* L71: */
    x2 = a2;
/* L72: */
    y2 = b2;
/* L73: */
    x3 = a1;
/* L74: */
    y3 = b1;

/* ...  INCREASE COUNTER */

/* L75: */
    ++mn;
/* L76: */
    if (n - 20 <= 0) {
	goto L83;
    } else {
	goto L77;
    }
L77:
    a2 = a1;
/* L78: */
    b2 = b1;
/* L79: */
    a1 = (d__[n - 6] - d__[n - 5]) / ((float)1. + d__[n - 6] * d__[n - 5]);
/* L80: */
    b1 = (d__[n + 1] - d__[n - 5]) / ((float)1. + d__[n + 1] * d__[n - 5]);
/* L81: */
    d__[n + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[n + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[n - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
/* L82: */
    goto L88;
L83:
    if (l - 1 != 0) {
	goto L84;
    } else {
	goto L85;
    }
L84:
    if (l - 3 != 0) {
	goto L88;
    } else {
	goto L85;
    }
L85:
    a1 = -b1;
/* L86: */
    d__1 = (float)1. - d__[22] * a1;
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[21] = (d__[22] + a1) / d_sign(&d__2, &d__1);
/* L87: */
    d__[j + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[j + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[j - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
L88:
    n = j + 7;
/* L89: */
    if (n - k - 7 >= 0) {
	goto L96;
    } else {
	goto L90;
    }
L90:
    a1 = x2;
/* L91: */
    b1 = y2;
/* L92: */
    a2 = (d__[n + 1] - d__[n + 2]) / ((float)1. + d__[n + 1] * d__[n + 2]);
/* L93: */
    b2 = (d__[n + 8] - d__[n + 2]) / ((float)1. + d__[n + 8] * d__[n + 2]);
/* L94: */
    d__[n + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[n + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[n - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
/* L95: */
    goto L46;
L96:
    if (l - 2 <= 0) {
	goto L97;
    } else {
	goto L46;
    }
L97:
    a1 = x3;
/* L98: */
    b1 = y3;
/* L99: */
    a2 = x2;
/* L100: */
    b2 = -a2;
/* L101: */
    d__1 = (float)1. - d__[j + 2] * b2;
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[k + 8] = (d__[j + 2] + b2) / d_sign(&d__2, &d__1);
/* L102: */
    d__[n + 4] = -((float)4. * a2 + (float)2. * b2) / (d__[j + 3] * sqrt(((
	    float)1. + a2 * a2) * ((float)1. + a2 * a2) * ((float)1. + a2 * 
	    a2))) - ((float)2. * a1 + (float)4. * b1) / (d__[j - 4] * sqrt(((
	    float)1. + b1 * b1) * ((float)1. + b1 * b1) * ((float)1. + b1 * 
	    b1)));
/* L103: */
    goto L46;
L8004:
    return 0;
} /* aprepb_ */

#undef deftab
#undef d__


