/* ASPHER.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

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
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int aspher_(n)
integer *n;
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static doublereal a;
    static integer i__, j, k, l;
    extern /* Subroutine */ int adot_(), aplan_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int asimeq_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*               *          *          *          *         * */
/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L181;
	case 3:  goto L184;
	case 4:  goto L187;
	case 5:  goto L800;
	case 6:  goto L600;
    }
/* ... */
/* ...  S = SPHERE/XCOORD,YCOORD,ZCOORD, RADIUS VALUE $$ */
/* ... */
L100:
    for (k = 1; k <= 4; ++k) {
/* L180: */
	defans[k - 1] = deftab[k];
    }
    goto L540;

/* ...     SPHERE/CENTER,PT1,RADIUS,R */

L181:
    for (k = 1; k <= 3; ++k) {
/* L182: */
	defans[k - 1] = deftab[k + 2];
    }
    defans[3] = deftab[7];
    goto L540;

/* ...     SPHERE/CENTER,PT1,PT2 */

L184:
    for (k = 1; k <= 3; ++k) {
/* L185: */
	defans[k - 1] = deftab[k + 2];
    }

/* ...  RADIUS = SQRTF((X2-X1)**2 + (Y2-Y1)**2 + (Z2-Z1)**2) */

/* Computing 2nd power */
    d__2 = deftab[7] - deftab[3];
/* Computing 2nd power */
    d__3 = deftab[8] - deftab[4];
/* Computing 2nd power */
    d__4 = deftab[9] - deftab[5];
    d__1 = d__2 * d__2 + d__3 * d__3 + d__4 * d__4;
    defans[3] = sqrt(d__1);
    goto L540;

/* ...     SPHERE/CENTER,PT1,TANTO,PLN1 */

L187:
    for (k = 1; k <= 3; ++k) {
/* L188: */
	defans[k - 1] = deftab[k + 2];
    }
    d__1 = deftab[3] * deftab[8] + deftab[4] * deftab[9] + deftab[5] * deftab[
	    10] - deftab[11];
    defans[3] = abs(d__1);
    goto L540;

/* ...     SPHERE/PT1,PT2,PT3,PT4 */

L800:
/* Computing 2nd power */
    d__1 = deftab[14];
/* Computing 2nd power */
    d__2 = deftab[15];
/* Computing 2nd power */
    d__3 = deftab[16];
    deftab[199] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    l = 96;
    for (k = 3; k <= 11; k += 4) {
	l += 4;
	deftab[l - 1] = deftab[k - 1] - deftab[14];
	deftab[l] = deftab[k] - deftab[15];
	deftab[l + 1] = deftab[k + 1] - deftab[16];
/* Computing 2nd power */
	d__1 = deftab[k - 1];
/* Computing 2nd power */
	d__2 = deftab[k];
/* Computing 2nd power */
	d__3 = deftab[k + 1];
	deftab[l + 2] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3 - deftab[199];
/* L801: */
    }
    aplan_(&a0con_1.k2);
    if (a1com_1.jsuber != 0) {
	goto L540;
    } else {
	goto L802;
    }
L802:
    for (k = 3; k <= 5; ++k) {
/* L803: */
	deftab[k - 1] = deftab[k + 11];
    }
    for (k = 1; k <= 4; ++k) {
/* L804: */
	deftab[k + 48] = defans[k - 1];
    }
    for (j = 1; j <= 3; ++j) {
/* L8040: */
	defans[j - 1] = deftab[j + 5] - deftab[j + 1];
    }
/* L805: */
    adot_(&deftab[49], defans, &deftab[48]);
    if (deftab[48] != 0.) {
	goto L806;
    } else {
	goto L97;
    }
L806:
    asimeq_();
    if (a1com_1.jsuber != 0) {
	goto L540;
    } else {
	goto L807;
    }
L807:
    deftab[114] = deftab[111] * deftab[14] + deftab[112] * deftab[15] + 
	    deftab[113] * deftab[16] - deftab[199];
    for (k = 1; k <= 3; ++k) {
/* L808: */
	defans[k - 1] = deftab[k + 110] / (float)2.;
    }
/* Computing 2nd power */
    d__1 = deftab[111];
/* Computing 2nd power */
    d__2 = deftab[112];
/* Computing 2nd power */
    d__3 = deftab[113];
    a = d__1 * d__1 + d__2 * d__2 + d__3 * d__3 - deftab[114] * (float)4.;
    if (a != 0.) {
	goto L809;
    } else {
	goto L97;
    }
L809:
    defans[3] = sqrt(a) / (float)2.;
    goto L540;

/* ...     SPHERE/PT1,A */

/* ...  PROCESS  SP6 = SPHERE/POINT,R */
L600:
    for (i__ = 3; i__ <= 6; ++i__) {
/* L605: */
	defans[i__ - 3] = deftab[i__ - 1];
    }
    goto L540;

L97:
    a1com_1.jsuber = 1005;

L540:
    return 0;
} /* aspher_ */

#undef defans
#undef deftab


