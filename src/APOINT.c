/* APOINT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <math.h>
#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal defprg[16];
} adfprg_;

#define adfprg_1 adfprg_

/* Table of constant values */

static integer c__3 = 3;
static integer c__2 = 2;
static integer c__0 = 0;

/* Subroutine */ int apoint_(n)
integer *n;
{
    /* Format strings */
    static char fmt_855[] = "";
    static char fmt_860[] = "";
    static char fmt_865[] = "";
    static char fmt_870[] = "";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(), cos(), sin();

    /* Local variables */
    static doublereal a, b, c__, d__;
    static integer i__, j, k;
    static doublereal t;
#define v ((doublereal *)&adfprg_1 + 3)
#define c3 ((doublereal *)&adfprg_1)
#define v1 ((doublereal *)&adfprg_1 + 3)
    static doublereal dd, tm, tp;
#define xo ((doublereal *)&adfprg_1 + 9)
    static doublereal rad;
#define ans ((doublereal *)&adfprg_1 + 6)
    extern /* Subroutine */ int adot_();
    static doublereal save;
#define svec ((doublereal *)&adfprg_1)
#define tvec ((doublereal *)&adfprg_1)
    static doublereal slen, temp;
#define xlar ((doublereal *)&adfprg_1 + 12)
#define ylar ((doublereal *)&adfprg_1 + 12)
#define tnor ((doublereal *)&adfprg_1 + 3)
#define xsml ((doublereal *)&adfprg_1 + 12)
#define ysml ((doublereal *)&adfprg_1 + 12)
    static doublereal sumr;
    static integer k000fx;
#define ambda ((doublereal *)&adfprg_1 + 6)
    static doublereal r1sqr, r2sqr, diffr;
    extern /* Subroutine */ int dvchk_(), anorm_();
#define svecn ((doublereal *)&adfprg_1 + 9)
    static integer jtemp;
#define puvec ((doublereal *)&adfprg_1 + 3)
    static doublereal const__;
    static integer itype;
#define punor ((doublereal *)&adfprg_1 + 6)
#define xynor ((doublereal *)&adfprg_1)
    static integer jtemp1;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
    static integer ioflag;
    extern /* Subroutine */ int aserch_();
    static doublereal ctheta;
    extern /* Subroutine */ int ataprd_(), alngth_(), asimeq_();
#define idfsto ((integer *)&adfsto_1)
    extern /* Subroutine */ int across_(), atrfrm_(), azvalu_();
    static doublereal slensq;

    /* Assigned format variables */
    static char *k_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */


/* ...  THIS ROUTINE CONTAINS THE FIRST TEN POINT DEFINITIONS */

/* *********************************************************************** */

    switch ((int)*n) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L320;
	case 4:  goto L405;
	case 5:  goto L520;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L802;
	case 9:  goto L915;
	case 10:  goto L1000;
	case 11:  goto L925;
	case 12:  goto L1200;
    }

/* ...  POINT/X,Y,Z */

L100:
    defans[0] = deftab[1];
    defans[1] = deftab[2];
    defans[2] = deftab[3];
    goto L925;

/* ...  POINT/X,Y */

L200:
    defans[0] = deftab[1];
    defans[1] = deftab[2];
    azvalu_();
    goto L925;

/* ...     POINT/INTOF,LN1,LN2 */

L320:
    deftab[13] = (float)0.;
    deftab[14] = (float)0.;
    deftab[15] = (float)1.;
    deftab[16] = (float)0.;
    itype = 0;
    goto L918;

/* ...     POINT/X- OR YLARGE OR SMALL,INTOF,LN1,CIR1 */

/* ...  THIS ROUTINE ESTABLISHES A POINT BY THE INTERSECTION OF A LINE */
/* ...  AND CIRCLE OR A PLANE AND A CYLINDER. */

L405:
    adot_(&deftab[4], &deftab[4], &ctheta);
    if (ctheta != 0.) {
	goto L410;
    } else {
	goto L995;
    }
L410:
    adot_(&deftab[9], &deftab[4], &temp);
    dd = deftab[7] - temp;
    temp = abs(dd) - deftab[15];
    if (abs(temp) - (float)1e-5 <= 0.) {
	goto L412;
    } else {
	goto L413;
    }
L412:
    t = (float)0.;
    dd = abs(dd) * deftab[15] / dd;
    goto L460;
L413:
    if (temp >= 0.) {
	goto L995;
    } else {
	goto L415;
    }
L415:
/* Computing 2nd power */
    d__1 = deftab[15];
/* Computing 2nd power */
    d__2 = dd;
    t = sqrt(d__1 * d__1 - d__2 * d__2);
    across_(&deftab[4], &deftab[12], tvec);
    anorm_(tvec, tnor);
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 31) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L420;
    } else {
	goto L425;
    }
L420:
    if (tnor[0] < 0.) {
	goto L455;
    } else if (tnor[0] == 0) {
	goto L995;
    } else {
	goto L460;
    }
L425:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 32) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L430;
    } else {
	goto L435;
    }
L430:
    if (tnor[0] < 0.) {
	goto L460;
    } else if (tnor[0] == 0) {
	goto L995;
    } else {
	goto L455;
    }
L435:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 35) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L440;
    } else {
	goto L445;
    }
L440:
    if (tnor[1] < 0.) {
	goto L455;
    } else if (tnor[1] == 0) {
	goto L995;
    } else {
	goto L460;
    }
L445:
    if (idftab[OTHER_ENDIAN_S(3)] - 36 != 0) {
	goto L993;
    } else {
	goto L450;
    }
L450:
    if (tnor[1] < 0.) {
	goto L460;
    } else if (tnor[1] == 0) {
	goto L995;
    } else {
	goto L455;
    }
L455:
    tnor[0] = -tnor[0];
    tnor[1] = -tnor[1];
    tnor[2] = -tnor[2];
L460:
    defans[0] = deftab[9] + dd * deftab[4] + tnor[0] * t;
    defans[1] = deftab[10] + dd * deftab[5] + tnor[1] * t;
    azvalu_();
    goto L925;

/* ...     POINT/X- OR YLARGE OR SMALL,INTOF,CIR1,CIR2 */

L520:
    for (j = 1; j <= 2; ++j) {
	svec[j - 1] = deftab[j + 11] - deftab[j + 3];
/* L525: */
    }
    svec[2] = (float)0.;
    alngth_(svec, &slen);
    if (slen - (float)1e-5 >= 0.) {
	goto L5251;
    } else {
	goto L995;
    }
L5251:
    sumr = deftab[10] + deftab[18];
    diffr = (d__1 = deftab[10] - deftab[18], abs(d__1));
    if ((d__1 = slen - diffr, abs(d__1)) - (float)1e-5 <= 0.) {
	goto L5255;
    } else {
	goto L5254;
    }
L5254:
    if ((d__1 = slen - sumr, abs(d__1)) - (float)1e-5 <= 0.) {
	goto L5252;
    } else {
	goto L5253;
    }
/* ...     IF FIRST CIRCLE INPUT IS THE SMALLER, CHANGE SIGN OF */
/* ...     DISTANCE BETWEEN CENTERS TO REVERSE VECTOR IN */
/* ...     COMPUTATION OF POINT LOCATION */
L5255:
    if (deftab[10] < deftab[18]) {
	slen = -slen;
    }
L5252:
    defans[0] = deftab[4] + deftab[10] * (deftab[12] - deftab[4]) / slen;
    defans[1] = deftab[5] + deftab[10] * (deftab[13] - deftab[5]) / slen;
    goto L585;
L5253:
    if (slen - sumr >= 0.) {
	goto L995;
    } else {
	goto L526;
    }
L526:
/* Computing 2nd power */
    d__1 = slen;
/* Computing 2nd power */
    d__2 = deftab[10] - deftab[18];
    if (d__1 * d__1 - d__2 * d__2 >= 0.) {
	goto L527;
    } else {
	goto L995;
    }
L527:
    anorm_(svec, svecn);
/* Computing 2nd power */
    d__1 = deftab[10];
    r1sqr = d__1 * d__1;
/* Computing 2nd power */
    d__1 = deftab[18];
    r2sqr = d__1 * d__1;
/* Computing 2nd power */
    d__1 = slen;
    slensq = d__1 * d__1;
    d__ = (r1sqr - r2sqr + slensq) / (slen * (float)2.);
    across_(&deftab[7], svecn, puvec);
    anorm_(puvec, punor);
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 31) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L530;
    } else {
	goto L535;
    }
L530:
    if (punor[0] < 0.) {
	goto L565;
    } else if (punor[0] == 0) {
	goto L995;
    } else {
	goto L570;
    }
L535:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 32) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L540;
    } else {
	goto L545;
    }
L540:
    if (punor[0] < 0.) {
	goto L570;
    } else if (punor[0] == 0) {
	goto L995;
    } else {
	goto L565;
    }
L545:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 35) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L550;
    } else {
	goto L555;
    }
L550:
    if (punor[1] < 0.) {
	goto L565;
    } else if (punor[1] == 0) {
	goto L995;
    } else {
	goto L570;
    }
L555:
    if (idftab[OTHER_ENDIAN_S(3)] - 36 != 0) {
	goto L993;
    } else {
	goto L560;
    }
L560:
    if (punor[1] < 0.) {
	goto L570;
    } else if (punor[1] == 0) {
	goto L995;
    } else {
	goto L565;
    }
L565:
    punor[0] = -punor[0];
    punor[1] = -punor[1];
    punor[2] = -punor[2];
L570:
    for (j = 1; j <= 3; ++j) {
/* Computing 2nd power */
	d__1 = d__;
	defans[j - 1] = deftab[j + 3] + svecn[j - 1] * d__ + punor[j - 1] * 
		sqrt(r1sqr - d__1 * d__1);
/* L575: */
    }
L585:
    azvalu_();
    goto L925;

/* ...     POINT/CIR1,ATANGL,A */

L600:
    const__ = deftab[10] / (float)57.29577951289617;
    defans[0] = deftab[2] + deftab[8] * cos(const__);
    defans[1] = deftab[3] + deftab[8] * sin(const__);
    azvalu_();
    goto L925;

/* ...     POINT/CENTER,CIR1 */

L700:
    defans[0] = deftab[3];
    defans[1] = deftab[4];
    azvalu_();
    goto L925;

/* ...     POINT/RTHETA,XY-, YZ-, OR ZXPLAN,R,A */

L1000:
    if (idftab[OTHER_ENDIAN_S(3)] == 106) {
	goto L1010;
    }
    if (idftab[OTHER_ENDIAN_S(3)] != 107) {
	goto L993;
    }
    save = deftab[3];
    deftab[3] = deftab[4];
    deftab[4] = save;
L1010:
    a = deftab[3] * cos(deftab[4] / (float)57.29577951289617);
    b = deftab[3] * sin(deftab[4] / (float)57.29577951289617);
    if ((i__1 = idftab[OTHER_ENDIAN_S(5)] - 33) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L110;
    } else {
	goto L101;
    }
L101:
    if ((i__1 = idftab[OTHER_ENDIAN_S(5)] - 37) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L120;
    } else {
	goto L102;
    }
L102:
    if (idftab[OTHER_ENDIAN_S(5)] - 41 != 0) {
	goto L993;
    } else {
	goto L130;
    }
L110:
    defans[0] = a;
    defans[1] = b;
/* ... DEFANS(3)=0 */
    goto L925;
L120:
    defans[1] = a;
    defans[2] = b;
/* ... DEFANS(1)=0 */
    goto L925;
L130:
    defans[2] = a;
    defans[0] = b;
/* ... DEFANS(2)=0 */
    goto L925;

/* ...     POINT/X- OR YLARGE OR SMALL,INTOF,LN1,ANY OF THE */
/* ...           SURFACES WITH THE QUADRIC CANONICAL FORM */

L802:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 31) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L805;
    } else {
	goto L810;
    }
L805:
    k = 0;
    k_fmt = fmt_855;
    goto L838;
L810:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 32) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L815;
    } else {
	goto L820;
    }
L815:
    k = 1;
    k_fmt = fmt_860;
    goto L838;
L820:
    if ((i__1 = idftab[OTHER_ENDIAN_S(3)] - 35) < 0) {
	goto L993;
    } else if (i__1 == 0) {
	goto L825;
    } else {
	goto L830;
    }
L825:
    k = 2;
    k_fmt = fmt_865;
    goto L838;
L830:
    if (idftab[OTHER_ENDIAN_S(3)] - 36 != 0) {
	goto L993;
    } else {
	goto L835;
    }
L835:
    k = 3;
    k_fmt = fmt_870;
L838:
    xynor[0] = (float)0.;
    xynor[1] = (float)0.;
    xynor[2] = (float)1.;

/* ...  CALCULATE  AMBDA,MU,NU */

    across_(&deftab[4], xynor, v);
    anorm_(v, ambda);
    for (j = 1; j <= 3; ++j) {
	xo[j - 1] = deftab[j + 3] * deftab[7];
/* L839: */
    }

/* ...  CALCULATE T  FOR A,B,C TERMS IN QUARDRATIC FORMULA */

/* Computing 2nd power */
    d__1 = ambda[0];
/* Computing 2nd power */
    d__2 = ambda[1];
    a = deftab[9] * (d__1 * d__1) + deftab[10] * (d__2 * d__2) + deftab[15] * 
	    (float)2. * ambda[0] * ambda[1];
    b = deftab[9] * (float)2. * xo[0] * ambda[0] + deftab[10] * (float)2. * 
	    xo[1] * ambda[1] + deftab[15] * (float)2. * ambda[0] * xo[1] + 
	    deftab[16] * (float)2. * ambda[0] + deftab[17] * (float)2. * 
	    ambda[1] + deftab[15] * (float)2. * xo[0] * ambda[1];
/* Computing 2nd power */
    d__1 = xo[0];
/* Computing 2nd power */
    d__2 = xo[1];
    c__ = deftab[9] * (d__1 * d__1) + deftab[10] * (d__2 * d__2) + deftab[15] 
	    * (float)2. * xo[0] * xo[1] + deftab[16] * (float)2. * xo[0] + (
	    deftab[17] * (float)2. * xo[1] + deftab[12]);
/* Computing 2nd power */
    d__1 = b;
    if (d__1 * d__1 - a * (float)4. * c__ >= 0.) {
	goto L840;
    } else {
	goto L995;
    }
L840:
/* Computing 2nd power */
    d__1 = b;
    rad = sqrt(d__1 * d__1 - a * (float)4. * c__);
    if (a != 0.) {
	goto L841;
    } else {
	goto L842;
    }
L842:
    tp = -c__ / b;
if(isinf(tp)){k000fx=1;}else{k000fx=2;}
  //  dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L995;
	case 2:  goto L8420;
    }
L8420:
    tm = tp;
    goto L843;
L841:
    tp = (-b + rad) / (a * (float)2.);
    tm = (-b - rad) / (a * (float)2.);
L843:
    for (i__ = 1; i__ <= 3; ++i__) {
	defans[i__ - 1] = xo[i__ - 1] + ambda[i__ - 1] * tp;
/* L845: */
    }
    for (i__ = 4; i__ <= 6; ++i__) {
	defans[i__ - 1] = xo[i__ - 4] + ambda[i__ - 4] * tm;
/* L850: */
    }
    for (j = 1; j <= 3; ++j) {
	ans[j - 1] = defans[j - 1] - defans[j + 2];
/* L852: */
    }
/* ...  ZERO OUT VECTOR ARRAYS */
    for (i__ = 1; i__ <= 3; ++i__) {
	xlar[i__ - 1] = (float)0.;
	xsml[i__ - 1] = (float)0.;
	ylar[i__ - 1] = (float)0.;
/* L853: */
	ysml[i__ - 1] = (float)0.;
    }
    switch ((int)k) {
	case 0: goto L855;
	case 1: goto L860;
	case 2: goto L865;
	case 3: goto L870;
    }
L855:
    xlar[0] = (float)1.;
/* ...  XLAR(2)=0.0 */
/* ...  XLAR(3)=0.0 */
    adot_(ans, xlar, &temp);
    goto L872;
L860:
    xsml[0] = (float)-1.;
/* ...  XSML(2)=0.0 */
/* ...  XSML(3)=0.0 */
    adot_(ans, xsml, &temp);
    goto L872;
/* ...  YLAR(1)=0.0 */
L865:
    ylar[1] = (float)1.;
/* ...  YLAR(3)=0.0 */
    adot_(ans, ylar, &temp);
    goto L872;
/* ...  YSML(1)=0.0 */
L870:
    ysml[1] = (float)-1.;
/* ...  YSML(3)=0.0 */
    adot_(ans, ysml, &temp);
L872:
    if (temp >= 0.) {
	goto L885;
    } else {
	goto L875;
    }
L875:
    for (i__ = 1; i__ <= 3; ++i__) {
	defans[i__ - 1] = defans[i__ + 2];
/* L880: */
    }
L885:
    azvalu_();
    goto L925;

/* ...     POINT/INTOF,PLN1,PLN2,PLN3 */

L915:
    itype = 1;
L918:
    for (i__ = 1; i__ <= 4; ++i__) {
	deftab[i__ + 98] = deftab[i__ + 2];
	deftab[i__ + 102] = deftab[i__ + 7];
/* L920: */
	deftab[i__ + 106] = deftab[i__ + 12];
    }
    asimeq_();
    if (a1com_1.jsuber != 0) {
	goto L925;
    }
    defans[0] = deftab[111];
    defans[1] = deftab[112];
    defans[2] = deftab[113];
    if (itype != 0) {
	goto L925;
    }
    azvalu_();
    goto L925;

L993:
    a1com_1.jsuber = 1003;
    goto L925;
L995:
    a1com_1.jsuber = 1005;
    goto L925;

/* ...     POINT/PATTERN,N */

/* ...     PICK UP POINT NUMBER GIVEN AFTER PATTERN, CONVERT TO INTEGER */
L1200:
    jtemp = (integer) deftab[5];
/* ...     COMPUTE PICK-UP INDEX FROM POINT NUMBER */
    jtemp = jtemp * 3 - 2;
/* ...     LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE */
    aserch_(&ataptb_1.srftap, &idftab[OTHER_ENDIAN_S(5)], &ioflag);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (ioflag < 0) {
	goto L1210;
    }
    a1com_1.jsuber = 840;
    goto L925;
/* ...     DEFINITION FOUND - READ IT IN */
L1210:
    ataprd_(&ataptb_1.srftap, &ioflag, &jtemp1, &c__3, idftab, &c__3, &
	    adfsto_1.defsto[9], &c__2, deftab, &c__0);
/* ...     TEST FOR ERROR WHEN READING IN PATTERN */
    if (ioflag < 0) {
	goto L1215;
    }
    a1com_1.jsuber = 841;
    goto L925;
/* ...    IS POINT NUMBER WITHIN RANGE OF PATTERN */
L1215:
    if (jtemp <= jtemp1) {
	goto L1220;
    }
    a1com_1.jsuber = 154;
    goto L925;
/* ...     PICK UP DESIRED POINT FROM PATTERN */
L1220:
    defans[0] = deftab[jtemp - 1];
    defans[1] = deftab[jtemp];
    defans[2] = deftab[jtemp + 1];
/* ...     TEST FOR PATTERN DEFINED IN ANOTHER REFERENCE SYSTEM */
    if (adfsto_1.defsto[1] == a1com_1.refsys) {
	goto L925;
    }
/* ...     YES, IT WAS - TRANSFORM POINT */
    idfsto[OTHER_ENDIAN_S(0)] = 1;
    atrfrm_();

L925:
    return 0;
} /* apoint_ */

#undef idfsto
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


