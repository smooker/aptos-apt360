/* APREPD.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal smat[12], xxxx1, xxxx2, xxxx3, xxxx4, ans1, ans2, ans3;
    integer ktr, kword, jmod2, jmod1, inkx, kmove, l1, l2, kfrnt, kadd, kadd1;
} aprbrk_;

#define aprbrk_1 aprbrk_

/* Table of constant values */

static integer c__0 = 0;
static integer c_n1 = -1;

/* Subroutine */ int aprepd_(jbr)
integer *jbr;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double d_sign(), atan(), sin(), cos();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6200)
    static doublereal sav1, sav2, sav3;
    extern doublereal afull8_();
#define deftab ((doublereal *)&avst_1 + 6200)
    static doublereal ageold;
    extern integer ideftb_();
    static doublereal halfpi, somepi;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 1 *** */


/*               *          *          *          *          * */
/* *********************************************************************** */
/*     DEFINE FUNCTIONS */

/* ...  DEFINE TANF SO THAT ITS MAXIMUM MAGNITUDE IS 10**9 */

    somepi = (float)3.1415926535897932;
    halfpi = somepi * (float).5;
    switch ((int)*jbr) {
	case 1:  goto L1075;
	case 2:  goto L1087;
	case 3:  goto L3000;
    }



/* ...  TRANSFORM IF NECESSARY AND CONVERT TO */
/* ...  NEW SYSTEM IF NECESSARY . */

L1075:
    switch ((int)aprbrk_1.jmod1) {
	case 1:  goto L1076;
	case 2:  goto L1076;
	case 3:  goto L1079;
	case 4:  goto L1083;
	case 5:  goto L1076;
	case 6:  goto L1076;
    }

/* ...  RTHETA , NOZ , XYZ , THETAR ROUTINE */

L1076:
    if (aprbrk_1.ktr != 0) {
	goto L1077;
    } else {
	goto L2000;
    }
L1077:
    aprbrk_1.inkx = 1;
    aprbrk_1.xxxx1 = d__[aprbrk_1.kadd1 - 1];
    aprbrk_1.xxxx2 = d__[aprbrk_1.kadd1];
    aprbrk_1.xxxx3 = (float)0.;
    aprbrk_1.xxxx4 = (float)1.;
L3000:
    aprbrk_1.ans1 = aprbrk_1.xxxx1 * aprbrk_1.smat[0] + aprbrk_1.xxxx2 * 
	    aprbrk_1.smat[1] + aprbrk_1.xxxx3 * aprbrk_1.smat[2] + 
	    aprbrk_1.xxxx4 * aprbrk_1.smat[3];
    aprbrk_1.ans2 = aprbrk_1.xxxx1 * aprbrk_1.smat[4] + aprbrk_1.xxxx2 * 
	    aprbrk_1.smat[5] + aprbrk_1.xxxx3 * aprbrk_1.smat[6] + 
	    aprbrk_1.xxxx4 * aprbrk_1.smat[7];
    aprbrk_1.ans3 = aprbrk_1.xxxx1 * aprbrk_1.smat[8] + aprbrk_1.xxxx2 * 
	    aprbrk_1.smat[9] + aprbrk_1.xxxx3 * aprbrk_1.smat[10] + 
	    aprbrk_1.xxxx4 * aprbrk_1.smat[11];
    switch ((int)aprbrk_1.inkx) {
	case 1:  goto L3001;
	case 2:  goto L3002;
	case 3:  goto L3003;
	case 4:  goto L3004;
	case 5:  goto L4001;
	case 6:  goto L4002;
    }
L3001:
    d__[aprbrk_1.kadd1 - 1] = aprbrk_1.ans1;
    d__[aprbrk_1.kadd1] = aprbrk_1.ans2;
    i__1 = aprbrk_1.kadd1 + 2;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L1078;
    } else {
	goto L2000;
    }
L1078:
    d__1 = aprbrk_1.smat[0] + aprbrk_1.smat[1] * d__[aprbrk_1.kadd1 + 1];
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[aprbrk_1.kadd1 + 1] = (aprbrk_1.smat[4] + aprbrk_1.smat[5] * d__[
	    aprbrk_1.kadd1 + 1]) / d_sign(&d__2, &d__1);
    goto L2000;

/* ...  NOY ROUTINE */

L1079:
    if (aprbrk_1.ktr != 0) {
	goto L1080;
    } else {
	goto L1082;
    }
L1080:
    aprbrk_1.inkx = 2;
    aprbrk_1.xxxx1 = d__[aprbrk_1.kadd1];
    aprbrk_1.xxxx2 = (float)0.;
    aprbrk_1.xxxx3 = d__[aprbrk_1.kadd1 - 1];
    aprbrk_1.xxxx4 = (float)1.;
    goto L3000;
L3002:
    d__[aprbrk_1.kadd1] = aprbrk_1.ans1;
    d__[aprbrk_1.kadd1 - 1] = aprbrk_1.ans3;
    i__1 = aprbrk_1.kadd1 + 2;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L1081;
    } else {
	goto L1082;
    }
L1081:
    d__1 = aprbrk_1.smat[10] + aprbrk_1.smat[8] * d__[aprbrk_1.kadd1 + 1];
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[aprbrk_1.kadd1 + 1] = (aprbrk_1.smat[2] + aprbrk_1.smat[0] * d__[
	    aprbrk_1.kadd1 + 1]) / d_sign(&d__2, &d__1);
L1082:
    sav1 = d__[aprbrk_1.kadd1];
    sav2 = d__[aprbrk_1.kadd1 - 1];
    d__[aprbrk_1.kadd1 - 1] = d__[1] * sav1 + d__[3] * sav2;
    d__[aprbrk_1.kadd1] = d__[4] * sav1 + d__[6] * sav2;
    i__1 = aprbrk_1.kadd1 + 2;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L3078;
    } else {
	goto L2000;
    }
L3078:
    ageold = atan(d__[aprbrk_1.kadd1 + 1]) + halfpi;
/* Computing MAX */
    d__3 = (d__1 = cos(ageold), abs(d__1));
    d__2 = max(d__3,1e-9);
    d__4 = cos(ageold);
    d__[aprbrk_1.kadd1 + 1] = sin(ageold) / d_sign(&d__2, &d__4);
    goto L2000;

/* ...  NOX ROUTINE */

L1083:
    if (aprbrk_1.ktr != 0) {
	goto L1084;
    } else {
	goto L1086;
    }
L1084:
    aprbrk_1.inkx = 3;
    aprbrk_1.xxxx1 = (float)0.;
    aprbrk_1.xxxx2 = d__[aprbrk_1.kadd1 - 1];
    aprbrk_1.xxxx3 = d__[aprbrk_1.kadd1];
    aprbrk_1.xxxx4 = (float)1.;
    goto L3000;
L3003:
    d__[aprbrk_1.kadd1 - 1] = aprbrk_1.ans2;
    d__[aprbrk_1.kadd1] = aprbrk_1.ans3;
    i__1 = aprbrk_1.kadd1 + 2;
    if (ideftb_(&i__1) + 1 != 0) {
	goto L1085;
    } else {
	goto L1086;
    }
L1085:
    d__1 = aprbrk_1.smat[5] + aprbrk_1.smat[6] * d__[aprbrk_1.kadd1 + 1];
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,1e-9);
    d__[aprbrk_1.kadd1 + 1] = (aprbrk_1.smat[9] + aprbrk_1.smat[10] * d__[
	    aprbrk_1.kadd1 + 1]) / d_sign(&d__2, &d__1);
L1086:
    sav1 = d__[aprbrk_1.kadd1 - 1];
    sav2 = d__[aprbrk_1.kadd1];
    d__[aprbrk_1.kadd1 - 1] = d__[2] * sav1 + d__[3] * sav2;
    d__[aprbrk_1.kadd1] = d__[5] * sav1 + d__[6] * sav2;
    goto L2000;

/* ...  XYZ ROUTINE */

L1087:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L1088;
    } else {
	goto L1089;
    }
L1088:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd - 1];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd];
    d__[aprbrk_1.kadd1 + 1] = d__[aprbrk_1.kadd + 1];
    aprbrk_1.kfrnt += -3;
    goto L1097;
L1089:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd + 1];
    d__[aprbrk_1.kadd1 + 1] = d__[aprbrk_1.kadd + 2];
    aprbrk_1.kfrnt += -4;

/* ...  TRANSFORM POINT AND SLOPE. CONVERT TO */
/* ...  U-V COORDINATE SYSTEM. */

L1097:
    if (aprbrk_1.ktr != 0) {
	goto L1098;
    } else {
	goto L1099;
    }
L1098:
    aprbrk_1.inkx = 4;
    aprbrk_1.xxxx1 = d__[aprbrk_1.kadd1 - 1];
    aprbrk_1.xxxx2 = d__[aprbrk_1.kadd1];
    aprbrk_1.xxxx3 = d__[aprbrk_1.kadd1 + 1];
    aprbrk_1.xxxx4 = (float)1.;
    goto L3000;
L3004:
    d__[aprbrk_1.kadd1 - 1] = aprbrk_1.ans1;
    d__[aprbrk_1.kadd1] = aprbrk_1.ans2;
    d__[aprbrk_1.kadd1 + 1] = aprbrk_1.ans3;
L1099:
    sav1 = d__[aprbrk_1.kadd1 - 1];
    sav2 = d__[aprbrk_1.kadd1];
    sav3 = d__[aprbrk_1.kadd1 + 1];
    d__[aprbrk_1.kadd1 - 1] = d__[1] * sav1 + d__[2] * sav2 + d__[3] * sav3;
    d__[aprbrk_1.kadd1] = d__[4] * sav1 + d__[5] * sav2 + d__[6] * sav3;
    d__[aprbrk_1.kadd1 + 1] = afull8_(&c__0, &c_n1);
L2000:
    *jbr = 1;
    goto L2500;
L4001:
    *jbr = 2;
    goto L2500;
L4002:
    *jbr = 3;
L2500:
    return 0;
} /* aprepd_ */

#undef deftab
#undef d__


