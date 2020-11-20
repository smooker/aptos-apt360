/* ACIRCL.f -- translated by f2c (version 20000121).
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

static integer c__4 = 4;
static integer c__3 = 3;
static integer c__5 = 5;

/* Subroutine */ int acircl_(n1)
integer *n1;
{
    /* Format strings */
    static char fmt_119[] = "";
    static char fmt_118[] = "";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static doublereal d__;
    static integer j, k, l, n, ik;
#define zsurr ((doublereal *)&adfprg_1 + 15)
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int asimeq_(), apoint_();

    /* Assigned format variables */
    static char *n_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*               *          *          *          *         * */
/* *********************************************************************** */
    switch ((int)*n1) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L102;
	case 4:  goto L400;
	case 5:  goto L106;
	case 6:  goto L109;
	case 7:  goto L163;
	case 8:  goto L112;
	case 9:  goto L831;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L901;
    }
/* ... */
/* ...  C1 = CIRCLE/XCOORD,YCOORD,ZCOORD,RADIUS OF CIRCLE $$ */
/* ... */
L100:
    defans[0] = deftab[1];
    defans[1] = deftab[2];
/* ...  DEFANS(3)= 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = deftab[4];
    goto L1240;

/* ...     CIRCLE/X,Y,R */

L200:
    defans[0] = deftab[1];
    defans[1] = deftab[2];

/* ...     DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = deftab[3];
    goto L1240;

/* ...     CIRCLE/CENTER,PT1,RADIUS,R */

L102:
    defans[0] = deftab[3];
    defans[1] = deftab[4];
/* ...  DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = deftab[7];
    goto L1240;

/* ...     CIRCLE/CENTER,X,Y,Z,RADIUS,R */

L400:
    defans[0] = deftab[2];
    defans[1] = deftab[3];
/* ...  DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = deftab[6];
    goto L1240;

/* ...     CIRCLE/CENTER,PT1,TANTO,LN1 */

L106:
    defans[0] = deftab[3];
    defans[1] = deftab[4];
/* ...  DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = (d__1 = deftab[3] * deftab[8] + deftab[4] * deftab[9] - 
	    deftab[11], abs(d__1));
    goto L1240;

/* ...     CIRCLE/CENTER,PT1,PT2 */

L109:
    defans[0] = deftab[3];
    defans[1] = deftab[4];
/* ...  DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;

/* ...  RADIUS = SQRT((X2-X1)**2 + (Y2-Y1)**2) */

/* Computing 2nd power */
    d__1 = deftab[7] - deftab[3];
/* Computing 2nd power */
    d__2 = deftab[8] - deftab[4];
    defans[6] = sqrt(d__1 * d__1 + d__2 * d__2);
    goto L1240;

/* ...     CIRCLE/PT1,LARGE OR SMALL,TANTO,CIR1 */

L112:
    if ((i__1 = idftab[OTHER_ENDIAN_S(13)] - 26) < 0) {
	goto L113;
    } else if (i__1 == 0) {
	goto L115;
    } else {
	goto L98;
    }
L113:
    if (idftab[OTHER_ENDIAN_S(13)] - 7 != 0) {
	goto L98;
    } else {
	goto L116;
    }
L115:
    n = 0;
    n_fmt = fmt_119;
    goto L120;
L116:
    n = 1;
    n_fmt = fmt_118;
L120:
/* Computing 2nd power */
    d__1 = deftab[9] - deftab[3];
/* Computing 2nd power */
    d__2 = deftab[10] - deftab[4];
    deftab[16] = sqrt(d__1 * d__1 + d__2 * d__2);
    defans[0] = deftab[3];
    defans[1] = deftab[4];
/* ...  DEFANS(3) = 0. */
/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    switch ((int)n) {
	case 0: goto L119;
	case 1: goto L118;
    }
L118:
    defans[6] = deftab[15] + deftab[16];
    goto L1240;
L119:
    defans[6] = (d__1 = deftab[15] - deftab[16], abs(d__1));
    goto L1240;

/* ...     CIRCLE/TANTO,LN1,X- OR YLARGE OR SMALL,PT1,RADIUS,R */

L831:
    defans[6] = deftab[13];
    deftab[39] = deftab[9] * deftab[3] + deftab[10] * deftab[4];
    if ((d__1 = deftab[39] - deftab[6], abs(d__1)) - (float)1e-5 <= 0.) {
	goto L832;
    } else {
	goto L833;
    }
L832:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 31) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L8321;
    } else {
	goto L8322;
    }
L8321:
    if (deftab[3] < 0.) {
	goto L834;
    } else if (deftab[3] == 0) {
	goto L97;
    } else {
	goto L835;
    }
L8322:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 32) < 0) {
	goto L97;
    } else if (i__1 == 0) {
	goto L8323;
    } else {
	goto L8324;
    }
L8323:
    if (deftab[3] < 0.) {
	goto L835;
    } else if (deftab[3] == 0) {
	goto L97;
    } else {
	goto L834;
    }
L8324:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 35) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L8325;
    } else {
	goto L8326;
    }
L8325:
    if (deftab[4] < 0.) {
	goto L834;
    } else if (deftab[4] == 0) {
	goto L97;
    } else {
	goto L835;
    }
L8326:
    if (idftab[OTHER_ENDIAN_S(15)] - 36 != 0) {
	goto L98;
    } else {
	goto L8327;
    }
L8327:
    if (deftab[4] < 0.) {
	goto L835;
    } else if (deftab[4] == 0) {
	goto L97;
    } else {
	goto L834;
    }
L833:
    if ((d__1 = deftab[39] - deftab[6]) < 0.) {
	goto L834;
    } else if (d__1 == 0) {
	goto L97;
    } else {
	goto L835;
    }
L834:
    deftab[6] -= deftab[13];
    goto L837;
L835:
    deftab[6] += deftab[13];
L837:
    deftab[1] = deftab[7];
    deftab[7] = deftab[6];
    deftab[6] = deftab[5];
    deftab[5] = deftab[4];
    deftab[4] = deftab[3];
    deftab[3] = deftab[2];
    deftab[12] = (float)0.;
    deftab[13] = (float)0.;
    deftab[14] = (float)1.;
    deftab[15] = defans[6];
    apoint_(&c__4);
    defans[2] = (float)0.;
/* ...  DEFANS(4)=0. */
/* ...  DEFANS(5)=0. */
/* L838: */
    defans[5] = (float)1.;
    goto L1240;

/* ...     CIRCLE/X- OR YLARGE OR SMALL,LN1,X- OR YLARGE OR   $ */
/* ...            SMALL,LN2,RADIUS,R */

L1000:
    *zsurr = (float)1.;
    k = 4;
L821:
    ik = (k << 1) - 5;
    if ((i__1 = idftab[OTHER_ENDIAN_S(ik)] - 32) < 0) {
	goto L811;
    } else if (i__1 == 0) {
	goto L814;
    } else {
	goto L812;
    }
L811:
    if (idftab[OTHER_ENDIAN_S(ik)] - 31 >= 0) {
	goto L817;
    } else {
	goto L98;
    }
L812:
    if ((i__1 = idftab[OTHER_ENDIAN_S(ik)] - 35) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L818;
    } else {
	goto L813;
    }
L813:
    if (idftab[OTHER_ENDIAN_S(ik)] - 36 != 0) {
	goto L98;
    } else {
	goto L819;
    }
L814:
    if ((d__1 = deftab[k - 1]) < 0.) {
	goto L815;
    } else if (d__1 == 0) {
	goto L97;
    } else {
	goto L816;
    }
L815:
    deftab[k + 2] += deftab[14];
    goto L820;
L816:
    deftab[k + 2] -= deftab[14];
    goto L820;
L817:
    if ((d__1 = deftab[k - 1]) < 0.) {
	goto L816;
    } else if (d__1 == 0) {
	goto L97;
    } else {
	goto L815;
    }
L818:
    if ((d__1 = deftab[k]) < 0.) {
	goto L816;
    } else if (d__1 == 0) {
	goto L97;
    } else {
	goto L815;
    }
L819:
    if ((d__1 = deftab[k]) < 0.) {
	goto L815;
    } else if (d__1 == 0) {
	goto L97;
    } else {
	goto L816;
    }
L820:
    if (*zsurr <= 0.) {
	goto L823;
    } else {
	goto L822;
    }
L822:
    *zsurr = (float)0.;
    k += 6;
    goto L821;
L823:
    *zsurr = deftab[14];
    for (j = 8; j <= 12; ++j) {
/* L824: */
	deftab[j - 1] = deftab[j];
    }
    apoint_(&c__3);

/* ...     DEFPRE ROUTINE PONT03 WILL STORE THE CIRCLE CENTER POINT */
/* ...  DEFANS(1) = X */
/* ...  DEFANS(2) = Y */
    defans[2] = (float)0.;

/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
    defans[6] = *zsurr;
    goto L1240;

/* ...     CIRCLE/PT1,PT2,PT3 */

L163:
    l = 96;
    for (k = 3; k <= 11; k += 4) {
	l += 4;
	deftab[l - 1] = deftab[k - 1];
	deftab[l] = deftab[k];
	deftab[l + 1] = (float)1.;
/* L164: */
/* Computing 2nd power */
	d__1 = deftab[k - 1];
/* Computing 2nd power */
	d__2 = deftab[k];
	deftab[l + 2] = d__1 * d__1 + d__2 * d__2;
    }
    asimeq_();
    if (a1com_1.jsuber != 0) {
	goto L1240;
    } else {
	goto L166;
    }
L166:
    defans[0] = deftab[111] / (float)2.;
    defans[1] = deftab[112] / (float)2.;
/* ...  DEFANS(3) = 0. */

/* ...  DEFANS(4) = 0. */
/* ...  DEFANS(5) = 0. */

    defans[5] = (float)1.;
/* Computing 2nd power */
    d__1 = deftab[111];
/* Computing 2nd power */
    d__2 = deftab[112];
    defans[6] = sqrt(d__1 * d__1 + d__2 * d__2 + deftab[113] * (float)4.) / (
	    float)2.;
    goto L1240;

/* ...     CIRCLE/X- OR YLARGE OR SMALL,IN OR OUT,CIR1,   $ */
/* ...            IN OR OUT,CIR2,RADIUS,R */

L1100:
    for (j = 1; j <= 10; j += 9) {
	ik = (j << 1) + 3;
	if ((i__1 = idftab[OTHER_ENDIAN_S(ik)] - 48) < 0) {
	    goto L98;
	} else if (i__1 == 0) {
	    goto L20;
	} else {
	    goto L10;
	}
L10:
	if (idftab[OTHER_ENDIAN_S(ik)] - 49 != 0) {
	    goto L98;
	} else {
	    goto L30;
	}
L20:
	deftab[j + 9] = (d__1 = deftab[j + 9] - deftab[21], abs(d__1));
/* L25: */
	goto L40;
L30:
	deftab[j + 9] += deftab[21];
L40:
	;
    }
    for (j = 1; j <= 8; ++j) {
	deftab[j + 10] = deftab[j + 11];
/* L50: */
    }
/* ...  DEFANS(3)=0 */
/* ...  DEFANS(4)=0 */
/* ...  DEFANS(5)=0 */
    defans[5] = (float)1.;
    defans[6] = deftab[21];
    apoint_(&c__5);
    goto L1240;

/* ...     CIRCLE/X- OR YLARGE OR SMALL,LN1,X- OR YLARGE OR   $ */
/* ...            SMALL,IN OR OUT,CIR1,RADIUS,R */

L901:
    if ((i__1 = idftab[OTHER_ENDIAN_S(17)] - 48) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L903;
    } else {
	goto L902;
    }
L902:
    if (idftab[OTHER_ENDIAN_S(17)] - 49 != 0) {
	goto L98;
    } else {
	goto L904;
    }
L903:
    d__ = (float)-1.;
    goto L905;
L904:
    d__ = (float)1.;
L905:
    deftab[16] = (d__1 = deftab[16] + d__ * deftab[18], abs(d__1));
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 31) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L909;
    } else {
	goto L906;
    }
L906:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 32) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L910;
    } else {
	goto L907;
    }
L907:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 35) < 0) {
	goto L98;
    } else if (i__1 == 0) {
	goto L911;
    } else {
	goto L908;
    }
L908:
    if (idftab[OTHER_ENDIAN_S(3)] - 36 != 0) {
	goto L98;
    } else {
	goto L912;
    }
L909:
    if (deftab[3] < 0.) {
	goto L914;
    } else if (deftab[3] == 0) {
	goto L97;
    } else {
	goto L913;
    }
L910:
    if (deftab[3] < 0.) {
	goto L913;
    } else if (deftab[3] == 0) {
	goto L97;
    } else {
	goto L914;
    }
L911:
    if (deftab[4] < 0.) {
	goto L914;
    } else if (deftab[4] == 0) {
	goto L97;
    } else {
	goto L913;
    }
L912:
    if (deftab[4] < 0.) {
	goto L913;
    } else if (deftab[4] == 0) {
	goto L97;
    } else {
	goto L914;
    }
L913:
    deftab[6] += deftab[18];
    goto L915;
L914:
    deftab[6] -= deftab[18];
L915:
    for (k = 1; k <= 8; ++k) {
/* L918: */
	deftab[k + 7] = deftab[k + 8];
    }
    deftab[1] = deftab[7];
    k = 7;
    for (j = 1; j <= 4; ++j) {
	deftab[k] = deftab[k - 1];
/* L919: */
	--k;
    }
    defans[5] = (float)1.;
    defans[6] = deftab[18];
    apoint_(&c__4);
    defans[2] = (float)0.;
    goto L1240;

L97:
    a1com_1.jsuber = 1005;
    goto L1240;
L98:
    a1com_1.jsuber = 1003;

L1240:
    return 0;
} /* acircl_ */

#undef defans
#undef idftab
#undef deftab
#undef zsurr


