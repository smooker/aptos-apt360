/* AVECDF.f -- translated by f2c (version 20000121).
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

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int avecdf_(n)
integer *n;
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double cos(), sin();

    /* Local variables */
    static doublereal a, d__;
    static integer j, k, m;
    static doublereal q, s, con1, con2, con3, cosa, sina;
    extern /* Subroutine */ int anorm_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int apoint_(), across_(), azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*               *          *          *          *          * */
/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L320;
	case 4:  goto L405;
	case 5:  goto L510;
	case 6:  goto L610;
	case 7:  goto L710;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1020;
	case 11:  goto L1030;
    }
/* ... */
/* ...  DEFPRE ROUTINE FOR FOLLOWING FORMAT */
/* ...     VECTOR/DX,DY,DZ */
/* ... */
L100:
    apoint_(&c__1);
    goto L2000;

/* ...     VECTOR/X1,Y1,Z1,X2,Y2,Z2 */

L200:
    for (j = 1; j <= 3; ++j) {
	defans[j - 1] = deftab[j + 3] - deftab[j];
/* L210: */
    }
    goto L2000;

/* ...     VECTOR/PT1,PT2 */

L320:
    for (j = 1; j <= 3; ++j) {
	defans[j - 1] = deftab[j + 5] - deftab[j + 1];
/* L330: */
    }
    goto L2000;

/* ...     VECTOR/PERPTO,PLN1,POS- OR NEGX, Y, OR Z */

L405:
    defans[0] = deftab[3];
    defans[1] = deftab[4];
    defans[2] = deftab[5];

/* ...  CHECK FOR NEGX MODIFIER */

    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 11) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L430;
    } else {
	goto L410;
    }

/* ...  CHECK FOR NEGY MODIFIER */

/* ...  CHECK FOR NEGZ MODIFIER */

L410:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 13) < 0) {
	goto L435;
    } else if (i__1 == 0) {
	goto L440;
    } else {
	goto L420;
    }

/* ...  CHECK FOR POSX MODIFIER */

L420:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 20) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L445;
    } else {
	goto L425;
    }

/* ...  CHECK FOR POSY MODIFIER */

/* ...  CHECK FOR POSZ MODIFIER */

L425:
    if ((i__1 = idftab[OTHER_ENDIAN_S(15)] - 22) < 0) {
	goto L450;
    } else if (i__1 == 0) {
	goto L455;
    } else {
	goto L993;
    }
L430:
    if (deftab[3] < 0.) {
	goto L470;
    } else if (deftab[3] == 0) {
	goto L495;
    } else {
	goto L460;
    }
L435:
    if (deftab[4] < 0.) {
	goto L470;
    } else if (deftab[4] == 0) {
	goto L495;
    } else {
	goto L460;
    }
L440:
    if (deftab[5] < 0.) {
	goto L470;
    } else if (deftab[5] == 0) {
	goto L495;
    } else {
	goto L460;
    }
L445:
    if (deftab[3] < 0.) {
	goto L460;
    } else if (deftab[3] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L450:
    if (deftab[4] < 0.) {
	goto L460;
    } else if (deftab[4] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L455:
    if (deftab[5] < 0.) {
	goto L460;
    } else if (deftab[5] == 0) {
	goto L495;
    } else {
	goto L470;
    }
L460:
    defans[0] = -defans[0];
    defans[1] = -defans[1];
    defans[2] = -defans[2];
    goto L470;

L495:
    a1com_1.jsuber = 1005;
L470:
    goto L2000;

/* ...     VECTOR/S,TIMES,VEC1 OR PT1 */

L510:
    for (k = 1; k <= 3; ++k) {
	defans[k - 1] = deftab[k + 3] * deftab[1];
/* L520: */
    }
    goto L2000;

/* ...     VECTOR/VEC1 OR PT1,CROSS OR PLUS OR MINUS,VEC2 OR PT2 */

L610:
    if ((i__1 = idftab[OTHER_ENDIAN_S(11)] - 3) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L675;
    } else {
	goto L620;
    }
L620:
    if ((i__1 = idftab[OTHER_ENDIAN_S(11)] - 10) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L640;
    } else {
	goto L630;
    }
L630:
    if (idftab[OTHER_ENDIAN_S(11)] - 19 != 0) {
	goto L993;
    } else {
	goto L650;
    }
L640:
    d__ = (float)-1.;
    goto L660;
L650:
    d__ = (float)1.;
L660:
    for (k = 1; k <= 3; ++k) {
	defans[k - 1] = deftab[k + 1] + deftab[k + 6] * d__;
/* L670: */
    }
    goto L680;
L675:
    across_(&deftab[2], &deftab[7], defans);
L680:
    goto L2000;

/* ...     VECTOR/UNIT,VEC1 OR PT1 */

L710:
    anorm_(&deftab[3], defans);
    goto L2000;

/* ...     VECTOR/UNIT,DX,DY,DZ */

L800:
    anorm_(&deftab[2], defans);
    goto L2000;

/* ...     VECTOR/LENGTH,A,ATANGL,B,XY-, YZ-, OR ZXPLAN */

L900:
    con1 = deftab[4] / (float)57.29577951289617;
    con2 = deftab[2] * cos(con1);
    con3 = deftab[2] * sin(con1);
    if ((i__1 = idftab[OTHER_ENDIAN_S(11)] - 33) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L930;
    } else {
	goto L910;
    }
L910:
    if ((i__1 = idftab[OTHER_ENDIAN_S(11)] - 37) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L940;
    } else {
	goto L920;
    }
L920:
    if (idftab[OTHER_ENDIAN_S(11)] - 41 != 0) {
	goto L993;
    } else {
	goto L950;
    }

/* ...  SET-UP VECTOR TO XYPLANE */

L930:
    defans[0] = con2;
    defans[1] = con3;
/* ...  DEFANS(3)= 0.0 */
    goto L960;

/* ...  SET-UP VECTOR TO YZPLANE */

/* ...  DEFANS(1)= 0.0 */
L940:
    defans[1] = con2;
    defans[2] = con3;
    goto L960;

/* ...  SET-UP VECTOR TO ZXPLANE */

L950:
    defans[0] = con3;
/* ...  DEFANS(2)= 0.0 */
    defans[2] = con2;
    goto L960;

L993:
    a1com_1.jsuber = 1003;
L960:
    goto L2000;

/* ...     VECTOR/PARLEL,INTOF,PLN1,PLN2,POS- OR NEGX, Y, OR Z */

/* ...     SET UP DEFTAB TO LOOK AS IF PERPTO A PLANE, SO TREAT IT */

L1020:
    deftab[2] = deftab[3];
    across_(&deftab[4], &deftab[9], &deftab[17]);
    anorm_(&deftab[17], &deftab[3]);
    deftab[7] = deftab[13];
    goto L405;

/* ...     VECTOR/ATANGL,A,LN1,(POS- OR NEGX OR Y, OR X- OR */
/* ...            YLARGE OR SMALL) */

/* ...     CONVERT ANGLE FROM DEGREES TO RADIANS */
L1030:
    a = deftab[2] * (float).0174532925;
/* ...     COMPUTE VECTOR FROM ANGLE */
    sina = sin(a);
    cosa = cos(a);
    defans[0] = deftab[4] * sina + deftab[5] * cosa;
    defans[1] = deftab[5] * sina - deftab[4] * cosa;
/* ...     DETERMINE MODIFIER (POSX OR XLARGE, NEGX OR XSMALL, */
/* ...     POSY OR YLARGE, NEGY OR YSMALL) */
    m = idftab[OTHER_ENDIAN_S(17)];
    s = (float)1.;
    if (m == 20) {
	goto L1040;
    }
    if (m == 31) {
	goto L1040;
    }
    if (m == 21) {
	goto L1050;
    }
    if (m == 35) {
	goto L1050;
    }
    s = (float)-1.;
    if (m == 11) {
	goto L1040;
    }
    if (m == 32) {
	goto L1040;
    }
    if (m == 12) {
	goto L1050;
    }
    if (m - 36 != 0) {
	goto L993;
    } else {
	goto L1050;
    }

L1040:
    q = defans[0];
    goto L1055;
L1050:
    q = defans[1];

L1055:
    if (q * s <= 0.) {
	goto L1060;
    } else {
	goto L1065;
    }
/* ...     MUST INVERT THE VECTOR */
L1060:
    defans[0] = -defans[0];
    defans[1] = -defans[1];
L1065:
    defans[2] = (float)0.;
    azvect_(defans);
L2000:
    return 0;
} /* avecdf_ */

#undef defans
#undef idftab
#undef deftab


