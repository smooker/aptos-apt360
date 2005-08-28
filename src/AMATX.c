/* AMATX.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static doublereal c_b21 = 180.;
static doublereal c_b23 = 1.;
static doublereal c_b25 = 90.;
static integer c__4 = 4;

/* Subroutine */ int amatx_(n)
integer *n;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double cos(), sin(), d_mod(), d_sign();

    /* Local variables */
    static integer i__, j, k, kk, lm, nn, ms;
    static doublereal sq;
    static integer ldf4;
    static doublereal con1, con2, con3;
    extern /* Subroutine */ int adot_();
    static doublereal temp;
    static integer next;
    extern /* Subroutine */ int amatm_(), anorm_();
    static integer intra, nomat, nxloc, inrot;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int across_(), azvect_(), ainvrt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* *********************************************************************** */
/* ...     SET STORING INDEX TO START OF DEFANS, AND PICKUP */
/* ...     INDEX TO START OF DEFTAB */
    ms = 0;
    lm = 1;
/* ...     SET FLAG TO INDICATE NO MATRIX PRODUCT */
    nomat = 0;
    intra = 0;
    inrot = 0;
    if (*n >= 7) {
	goto L10;
    }
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
    }
L10:
    if (*n < 31) {
	goto L800;
    }
    *n += -30;
    switch ((int)*n) {
	case 1:  goto L730;
	case 2:  goto L900;
	case 3:  goto L925;
	case 4:  goto L950;
    }

/* ...     SET FLAG TO MULTIPLY MATRICES AFTER NEXT ONE DEFINED */
L50:
    nomat = 1;
/* ...     SET STORING INDEX FOR SECOND MATRIX */
    ms = 12;
/* ...     SET PICKUP INDEX FOR SECOND MATRIX */
    lm = nxloc;
/* ...     BRANCH TO DEVELOP SECOND MATRIX */
    switch ((int)next) {
	case 1:  goto L870;
	case 2:  goto L300;
	case 3:  goto L200;
	case 4:  goto L205;
	case 5:  goto L400;
    }

/* ...     MATRIX/A1,B1,C1,D1,A2,B2,C2,D2,A3,B3,C3,D3 */

L100:
    for (k = 1; k <= 12; ++k) {
	defans[k - 1] = deftab[k];
/* L110: */
    }
    goto L1000;

/* ...     MATRIX/TRANSL,A,B, OR TRANSL,A,B,C */

L200:
    defans[ms + 11] = deftab[lm + 3];
    goto L210;
L205:
    defans[ms + 11] = (float)0.;
L210:
    defans[ms] = (float)1.;
/* ...   DEFANS(MS+2) = 0 */
/* ...   DEFANS(MS+3) = 0 */
    defans[ms + 3] = deftab[lm + 1];
/* ...   DEFANS(MS+5) = 0 */
    defans[ms + 5] = (float)1.;
/* ...   DEFANS(MS+7) = 0 */
    defans[ms + 7] = deftab[lm + 2];
/* ...   DEFANS(MS+9) = 0 */
/* ...   DEFANS(MS+10) = 0 */
    defans[ms + 10] = (float)1.;
    intra = 1;
/* ...     TEST FLAG TO SEE WHETHER TO GO TO TAKE MATRIX PRODUCT, */
/* ...     OR TO EXIT */
    if (nomat < 0) {
	goto L50;
    } else if (nomat == 0) {
	goto L1000;
    } else {
	goto L510;
    }

/* ...     MATRIX/XY-, YZ-, OR ZXROT,A */

L300:
    con1 = deftab[lm + 1] / (float)57.29577951289617;
    con2 = cos(con1);
    con3 = -sin(con1);
    inrot = 1;
/* ...     TEST FOR AN ANGLE OF ZERO OR AN INTEGRAL MULTIPLE OF 180 */
    temp = d_mod(&deftab[lm + 1], &c_b21);
    if (temp != (float)0.) {
	goto L310;
    }
/* ...     YES - SET SINE AND COSINE TO EXACT VALUES */
    con3 = (float)0.;
    con2 = d_sign(&c_b23, &con2);
    goto L320;
/* ...     ANGLE IS NOT MULTIPLE OF 180 - SEE IF 90 IS A FACTOR */
L310:
    temp = d_mod(&deftab[lm + 1], &c_b25);
    if (temp != (float)0.) {
	goto L320;
    }
/* ...     IT IS - SET SINE AND COSINE TO EXACT VALUES */
    con2 = (float)0.;
    con3 = d_sign(&c_b23, &con3);
L320:
    ldf4 = (lm << 1) - 1;
    if (idftab[OTHER_ENDIAN_S(ldf4 + 2)] == 38) {
	goto L360;
    }
    if (idftab[OTHER_ENDIAN_S(ldf4 + 2)] == 34) {
	goto L365;
    }
    if (idftab[OTHER_ENDIAN_S(ldf4 + 2)] - 42 != 0) {
	goto L393;
    } else {
	goto L370;
    }

/* ...  CALCULATE YZ ROT */

L360:
    defans[ms] = (float)1.;
    defans[ms + 5] = con2;
    defans[ms + 6] = con3;
    defans[ms + 9] = -con3;
    defans[ms + 10] = con2;
/* ...   DEFANS(MS+2,3,4,5,8,9,12) = 0 */
    goto L380;

/* ...  CALCULATE XYROT */

L365:
    defans[ms] = con2;
    defans[ms + 1] = con3;
    defans[ms + 4] = -con3;
    defans[ms + 5] = con2;
    defans[ms + 10] = (float)1.;
/* ...   DEFANS(3,4,7,8,9,10,12) = 0 */
    goto L380;

/* ...  CALCULATE ZXROT */

L370:
    defans[ms] = con2;
    defans[ms + 2] = -con3;
    defans[ms + 5] = (float)1.;
    defans[ms + 8] = con3;
    defans[ms + 10] = con2;
/* ...   DEFANS(MS+2,4,5,7,8,10,12) = 0 */
/* ...     TEST FLAG TO SEE WHETHER TO GO TO TAKE MATRIX PRODUCT, */
/* ...     OR TO EXIT */
L380:
    if (nomat < 0) {
	goto L50;
    } else if (nomat == 0) {
	goto L1000;
    } else {
	goto L510;
    }

L393:
    a1com_1.jsuber = 1003;
    goto L1000;

/* ...     MATRIX/SCALE,A */

L400:
    defans[ms] = deftab[lm + 1];
    defans[ms + 5] = deftab[lm + 1];
    defans[ms + 10] = deftab[lm + 1];
/* ...     TEST FLAG TO SEE WHETHER TO GO TO TAKE MATRIX PRODUCT, */
/* ...     OR TO EXIT */
    if (nomat < 0) {
	goto L50;
    } else if (nomat == 0) {
	goto L1000;
    } else {
	goto L510;
    }

/* ...     MATRIX/MAT1,MAT2 */

L500:
    for (j = 1; j <= 12; ++j) {
	atmaty_1.xmat1[j - 1] = deftab[j + 1];
/* L505: */
	atmaty_1.xmat2[j - 1] = deftab[j + 14];
    }
    goto L518;

/* ...     SET UP RESULTS OF VARIED DEFINITION FORMATS FOR PRODUCT */
L510:
    if (intra * inrot != 0) {
	goto L514;
    }
    for (j = 1; j <= 12; ++j) {
	atmaty_1.xmat1[j - 1] = defans[j - 1];
/* L512: */
	atmaty_1.xmat2[j - 1] = defans[j + 11];
    }
    goto L518;

L514:
    for (j = 1; j <= 12; ++j) {
	atmaty_1.xmat1[j - 1] = defans[j + 11];
/* L516: */
	atmaty_1.xmat2[j - 1] = defans[j - 1];
    }

L518:
    for (j = 1; j <= 3; ++j) {
	atmaty_1.xmat1[j + 11] = (float)0.;
	atmaty_1.xmat2[j + 11] = (float)0.;
/* L520: */
    }
    atmaty_1.xmat1[15] = (float)1.;
    atmaty_1.xmat2[15] = (float)1.;
    amatm_(&c__4);
    for (j = 1; j <= 12; ++j) {
	defans[j - 1] = atmaty_1.xmat3[j - 1];
/* L530: */
    }
    goto L1000;

/* ...     MATRIX/INVERS,MAT1 */

L600:
    for (j = 1; j <= 12; ++j) {
	atmaty_1.tmatx[j - 1] = deftab[j + 2];
/* L610: */
    }
L615:
    ainvrt_();
    for (j = 1; j <= 12; ++j) {
	defans[j - 1] = atmaty_1.xmat2[j - 1];
/* L620: */
    }
    goto L1000;

/* ...     MATRIX/PLN1,PLN2,PLN3 */

L730:
    for (j = 1; j <= 4; ++j) {
	atmaty_1.tmatx[j - 1] = deftab[j + 1];
	atmaty_1.tmatx[j + 3] = deftab[j + 6];
/* L740: */
	atmaty_1.tmatx[j + 7] = deftab[j + 11];
    }
    atmaty_1.tmatx[3] = -atmaty_1.tmatx[3];
    atmaty_1.tmatx[7] = -atmaty_1.tmatx[7];
    atmaty_1.tmatx[11] = -atmaty_1.tmatx[11];
    goto L615;

/* ...     PRODUCT OF TWO MATRICES DEFINED BY VARIOUS FORMATS */

L800:
    nn = (*n - 1) / 5;
/* ...     SET FLAG TO GET SECOND MATRIX FOR PRODUCT */
    nomat = -1;
    switch ((int)nn) {
	case 1:  goto L810;
	case 2:  goto L820;
	case 3:  goto L830;
	case 4:  goto L840;
	case 5:  goto L850;
    }

/* ...     COMPUTE BRANCHING INDEX FOR MATRIX FOLLOWING SYMBOLIC ONE */
L810:
    next = *n - 5;
/* ...     PREPARE PICKUP INDEX FOR SECOND MATRIX */
    nxloc = 14;
/* ...     GO TO MOVE SYMBOLIC MATRIX INTO DEFANS */
    goto L870;

/* ...     COMPUTE BRANCHING INDEX FOR MATRIX FOLLOWING */
/* ...     XY-, YZ-, OR ZXROT,A */
L820:
    next = *n - 10;
/* ...     PREPARE PICKUP INDEX FOR SECOND MATRIX */
    nxloc = 3;
    inrot = 1;
/* ...     GO TO COMPUTE MATRIX FROM GIVEN ROTATION */
    goto L300;


/* ...     COMPUTE BRANCHING INDEX FOR MATRIX FOLLOWING TRANSL,A,B,C */
L830:
    next = *n - 15;
/* ...     PREPARE PICKUP INDEX FOR SECOND MATRIX */
    nxloc = 5;
    intra = 1;
/* ...     GO TO COMPUTE MATRIX FROM GIVEN ORIGIN */
    goto L200;

/* ...     COMPUTE BRANCHING INDEX FOR MATRIX FOLLOWING TRANSL,A,B */
L840:
    next = *n - 20;
/* ...     PREPARE PICKUP INDEX FOR SECOND MATRIX */
    nxloc = 4;
    intra = 1;
/* ...     GO TO COMPUTE MATRIX FROM GIVEN ORIGIN */
    goto L205;

/* ...     COMPUTE BRANCHING INDEX FOR MATRIX FOLLOWING SCALE,A */
L850:
    next = *n - 25;
/* ...     PREPARE PICKUP INDEX FOR SECOND MATRIX */
    nxloc = 3;
/* ...     GO TO COMPUTE MATRIX FOR GIVEN SCALE */
    goto L400;

/* ...     MOVE SYMBOLIC MATRIX FROM DEFTAB TO DEFANS */
L870:
    for (j = 1; j <= 12; ++j) {
	defans[ms] = deftab[lm + 1];
	++ms;
/* L875: */
	++lm;
    }
/* ...     TEST FLAG TO SEE WHETHER THIS IS 1ST OR 2ND MATRIX FOR PRODUCT */
    if (nomat < 0) {
	goto L50;
    } else if (nomat == 0) {
	goto L1000;
    } else {
	goto L510;
    }

/* ...     MATRIX/PT1,VEC1,VEC2 */

L900:
    across_(&deftab[6], &deftab[10], &defans[8]);
    azvect_(&defans[8]);
    if (a1com_1.jsuber != 0) {
	goto L1000;
    }
    across_(&defans[8], &deftab[6], &defans[4]);
    for (j = 1; j <= 3; ++j) {
/* L905: */
	defans[j - 1] = deftab[j + 5];
    }
    for (j = 1; j <= 9; j += 4) {
	anorm_(&defans[j - 1], &defans[j - 1]);
	adot_(&defans[j - 1], &deftab[2], &defans[j + 2]);
/* L910: */
	defans[j + 2] = -defans[j + 2];
    }
    for (j = 1; j <= 12; ++j) {
/* L915: */
	atmaty_1.tmatx[j - 1] = defans[j - 1];
    }
    goto L615;

/* ...     MATRIX/MIRROR,XY-, YZ-, OR ZXPLAN,OPTIONAL ONE OR TWO */
/* ...            MORE MODIFIERS OF SAME TYPE AS FIRST ONE */

/* ...     INITIALIZE VALUES FOR THE MATRIX */
L925:
    defans[0] = (float)1.;
    defans[5] = (float)1.;
    defans[10] = (float)1.;
/* ...     ADJUST MATRIX ACCORDING TO INPUT MODIFIERS */
    kk = idftab[OTHER_ENDIAN_S(1)];
    i__1 = kk;
    for (j = 3; j <= i__1; ++j) {
	ldf4 = (j << 1) - 1;
	if (idftab[OTHER_ENDIAN_S(ldf4)] == 33) {
	    goto L930;
	}
	if (idftab[OTHER_ENDIAN_S(ldf4)] == 37) {
	    goto L935;
	}
	if (idftab[OTHER_ENDIAN_S(ldf4)] != 41) {
	    goto L393;
	}
/* ...     SET MATRIX VALUE FOR ZXPLAN */
	defans[5] = (float)-1.;
	goto L940;
/* ...     SET MATRIX VALUE FOR XYPLAN */
L930:
	defans[10] = (float)-1.;
	goto L940;
/* ...     SET MATRIX VALUE FOR YZPLAN */
L935:
	defans[0] = (float)-1.;
L940:
	;
    }
    goto L1000;

/* ...     MATRIX/MIRROR,PLANE OR LINE */

L950:
    deftab[6] = -deftab[6];
/* Computing 2nd power */
    d__1 = deftab[3];
/* Computing 2nd power */
    d__2 = deftab[4];
/* Computing 2nd power */
    d__3 = deftab[5];
    sq = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    k = 0;

    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    ++k;
	    defans[k - 1] = deftab[i__ + 2] * (float)-2. * deftab[j + 2];
	    if (i__ != j) {
		goto L965;
	    }
	    defans[k - 1] += sq;
L965:
	    ;
	}
    }

L1000:
    return 0;
} /* amatx_ */

#undef defans
#undef idftab
#undef deftab


