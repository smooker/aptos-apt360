/* APREPA.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
    doublereal smat[12], xxxx1, xxxx2, xxxx3, xxxx4, ans1, ans2, ans3;
    integer ktr, kword, jmod2, jmod1, inkx, kmove, l1, l2, kfrnt, kadd, kadd1;
} aprbrk_;

#define aprbrk_1 aprbrk_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__18 = 18;

/* Subroutine */ int aprepa_(jbr)
integer *jbr;
{
    /* Format strings */
    static char fmt_1008[] = "(\0020TABCYL MODIFIER 2 INVALID\002)";
    static char fmt_1020[] = "(\0020TABCYL MODIFIER 1 INVALID\002)";
    static char fmt_1029[] = "(\0020TABCYL AXIS VECTOR GIVEN INCORRECTLY WIT\
H XYZ FORMAT\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6200)
    static integer i1, i2;
#define deftab ((doublereal *)&avst_1 + 6200)
    extern integer ideftb_();

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, fmt_1008, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___7 = { 0, 0, 0, fmt_1029, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 *** */

/*               *          *          *          *          * */

/* ...  IF TRANSFORM IS NECESSARY , SET INDICATOR */
/* ...  AND BRING IN MATRIX. */

    if (ideftb_(&c__4) - 110 != 0) {
	goto L1002;
    } else {
	goto L1000;
    }
L1000:
    aprbrk_1.ktr = 1;
    aprbrk_1.kword += 14;
    for (i1 = 1; i1 <= 12; ++i1) {
	aprbrk_1.smat[i1 - 1] = d__[i1 + 4];
/* L1001: */
    }

/* ...  MOVE POINTS TO REAR OF AREA */

L1002:
    aprbrk_1.kmove = ideftb_(&c__1);
    i__1 = aprbrk_1.kmove;
    for (i2 = 1; i2 <= i__1; ++i2) {
	aprbrk_1.l1 = 996 - i2;
	aprbrk_1.l2 = ideftb_(&c__1) + 2 - i2;
	d__[aprbrk_1.l1 - 1] = d__[aprbrk_1.l2 - 1];
/* L1038: */
    }

/* ...  DETERMINE CUBIC METHOD */
/* ...  DETERMINE CUBIC METHOD AND SET JMOD2 */
/* ...  EQUAL TO 1 FOR FOURPT , 2 FOR TWOPT , */
/* ...  3 FOR PTSLOP , 4 FOR PTNORM , AND 5 FOR */
/* ...  SPLINE . ERROR IF NONE OF ABOVE . */

    if (ideftb_(&c__3) - 101 != 0) {
	goto L1003;
    } else {
	goto L1009;
    }
L1003:
    if (ideftb_(&c__3) - 102 != 0) {
	goto L1004;
    } else {
	goto L1010;
    }
L1004:
    if (ideftb_(&c__3) - 103 != 0) {
	goto L1005;
    } else {
	goto L1011;
    }
L1005:
    if (ideftb_(&c__3) - 104 != 0) {
	goto L1006;
    } else {
	goto L1012;
    }
L1006:
    if (ideftb_(&c__3) - 105 != 0) {
	goto L1007;
    } else {
	goto L1013;
    }
L1007:
    io___5.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___5);
    e_wsfe();
    a1com_1.jsuber = 1003;
    return 0;
L1009:
    aprbrk_1.jmod2 = 1;
    goto L1014;
L1010:
    aprbrk_1.jmod2 = 2;
    goto L1014;
L1011:
    aprbrk_1.jmod2 = 3;
    goto L1014;
L1012:
    aprbrk_1.jmod2 = 4;
    goto L1014;
L1013:
    aprbrk_1.jmod2 = 5;

/* ...  DETERMINE HOW POINTS DEFINED AND ROTATION MATRIX */
/* ...  JMOD1 EQUALS 1 FOR RTHETA , 2 FOR NOZ , 3 FOR */
/* ...  NOY , 4 FOR NOX , 5 FOR XYZ , AND 6 FOR */
/* ...  THETAR . ERROR IF OTHER . */

L1014:
    if (ideftb_(&c__2) - 106 != 0) {
	goto L1015;
    } else {
	goto L1021;
    }
L1015:
    if (ideftb_(&c__2) - 16 != 0) {
	goto L1016;
    } else {
	goto L1022;
    }
L1016:
    if (ideftb_(&c__2) - 15 != 0) {
	goto L1017;
    } else {
	goto L1024;
    }
L1017:
    if (ideftb_(&c__2) - 14 != 0) {
	goto L1018;
    } else {
	goto L1025;
    }
L1018:
    if (ideftb_(&c__2) - 108 != 0) {
	goto L20;
    } else {
	goto L1026;
    }
L20:
    if (ideftb_(&c__2) - 107 != 0) {
	goto L1019;
    } else {
	goto L21;
    }
L1019:
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    e_wsfe();
    a1com_1.jsuber = 1003;
    return 0;
L1021:
    aprbrk_1.jmod1 = 1;
    goto L1023;
L21:
    aprbrk_1.jmod1 = 6;
    goto L1023;
L1022:
    aprbrk_1.jmod1 = 2;
L1023:
    d__[7] = (float)0.;
    d__[8] = (float)0.;
    d__[9] = (float)1.;
    goto L1034;
L1024:
    aprbrk_1.jmod1 = 3;
    d__[7] = (float)0.;
    d__[8] = (float)1.;
    d__[9] = (float)0.;
    goto L1034;
L1025:
    aprbrk_1.jmod1 = 4;
    d__[7] = (float)1.;
    d__[8] = (float)0.;
    d__[9] = (float)0.;
    goto L1034;
L1026:
    aprbrk_1.jmod1 = 5;
    if (aprbrk_1.ktr != 0) {
	goto L1031;
    } else {
	goto L1027;
    }
L1027:
    if (ideftb_(&c__4) - 3011 != 0) {
	goto L1028;
    } else {
	goto L1030;
    }
L1028:
    io___7.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___7);
    e_wsfe();
    a1com_1.jsuber = 1003;
    return 0;
L1030:
    d__[7] = d__[4];
    d__[8] = d__[5];
    d__[9] = d__[6];
    goto L1033;
L1031:
    if (ideftb_(&c__18) - 3011 != 0) {
	goto L1028;
    } else {
	goto L1032;
    }
L1032:
    d__[7] = d__[18];
    d__[8] = d__[19];
    d__[9] = d__[20];
    aprbrk_1.inkx = 5;
    aprbrk_1.xxxx1 = d__[7];
    aprbrk_1.xxxx2 = d__[8];
    aprbrk_1.xxxx3 = d__[9];
    aprbrk_1.xxxx4 = (float)1.;
    *jbr = -1;
    return 0;
L1034:
    *jbr = 0;
    return 0;
L1033:
    *jbr = 1;
    return 0;
} /* aprepa_ */

#undef deftab
#undef d__


