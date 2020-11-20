/* APREPR.f -- translated by f2c (version 20000121).
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

static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;
static integer c_n1 = -1;
static integer c__11 = 11;
static integer c__22 = 22;

/* Subroutine */ int aprepr_()
{
    /* Format strings */
    static char fmt_2003[] = "(\0020NUMBER OF TABCYL POINTS IS GREATER THAN \
139  \002)";
    static char fmt_300[] = "(\0020\002,10x,\002DIRECTIONAL DISCONTINUITY OF\
 TABCYL AT U- \002,\002AND V-COORDINATES\002,f14.6,\002,\002,f14.6//)";
    static char fmt_8117[] = "(\0020EXTENSION INTERSECTION U=\002f15.8,5x\
,\002V=\002f15.8)";
/*
    static char fmt_8130[] = "(\0020DATA STORAGE=\002i5/\0020ROTATION MATRI\
X\002/\0020\0023f15.8/\0020\0023f15.8/\0020\0023f15.8/\0020NUMBER OF POINTS\
=\002i5/1x,\002       U               V             A              B\r      \
     LENGTH           MAX            MIN\002/(\002 \0027f15.8))";
*/
//removed the "\r" to make this format correctly.  Not sure why....

    static char fmt_8130[] = "(\0020DATA STORAGE=\002i5/\0020ROTATION MATRI\
X\002/\0020\0023f15.8/\0020\0023f15.8/\0020\0023f15.8/\0020NUMBER OF POINTS\
=\002i5/1x,\002       U               V             A              B      \
     LENGTH           MAX            MIN\002/(\002 \0027f15.8))";


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11;

    /* Builtin functions */
    double sqrt(), cos(), sin(), d_sign();
    integer s_wsfe(), e_wsfe();
    double atan();
    integer do_fio();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6200)
    static doublereal g, h__;
    static integer i__, j, n;
    static doublereal s[4], t[4], u[4], v[4], x, y;
    static integer i3, l3, m1;
    static doublereal x2, y2, cb[4], an, bn;
    static integer n12, ik;
    static doublereal sb;
    static integer mm[7];
    static doublereal ro, sq[4], tu, se2, pp1, pp2, pp3, den;
    static integer jbr;
    static doublereal pig, ext, tlu, tlv, tem1, tem3, tem2, sav1, tem4;
    static integer icv1, icv11, iset;
    static doublereal temp, sinn, coss;
    static integer jsww;
    static doublereal svse2, delta, ajold;
    extern doublereal afull8_();
#define deftab ((doublereal *)&avst_1 + 6200)
    static doublereal ageold;
    extern integer ideftb_();
    static doublereal halfpi;
    extern /* Subroutine */ int aprepa_(), aprepc_(), aprepd_(), aprepb_();
    static doublereal rdtodg, somepi;
    static integer idummy, kptctr;
    static doublereal uslope, vslope;
    static integer numpts;

    /* Fortran I/O blocks */
    static cilist io___17 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_8117, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_8130, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*               *          *          *          *          * */
/* *********************************************************************** */
/*     DEFINE FUNCTIONS */

/* ...  DEFINE TANF SO THAT ITS MAXIMUM MAGNITUDE IS 10**9 */




    somepi = (float)3.1415926535897932;
    rdtodg = (float)57.295779513082321;
    iset = 0;
    i__1 = ideftb_(&c__1) - 1;
    d__[0] = afull8_(&c__0, &i__1);
    halfpi = somepi * (float).5;
    if (ideftb_(&c__2) == 3099) {
	goto L10;
    }
    aprbrk_1.kword = 2;
    kptctr = 1;
    aprbrk_1.ktr = 0;
    aprepa_(&jbr);
    if (a1com_1.jsuber != 0) {
	return 0;
    }
    if (jbr < 0) {
	goto L3000;
    } else if (jbr == 0) {
	goto L1034;
    } else {
	goto L1033;
    }
L4001:
    pp1 = aprbrk_1.ans1;
    pp2 = aprbrk_1.ans2;
    pp3 = aprbrk_1.ans3;
    aprbrk_1.inkx = 6;
    aprbrk_1.xxxx1 = (float)0.;
    aprbrk_1.xxxx2 = (float)0.;
    aprbrk_1.xxxx3 = (float)0.;
    aprbrk_1.xxxx4 = (float)1.;
    goto L3000;
L4002:
    d__[7] = pp1 - aprbrk_1.ans1;
    d__[8] = pp2 - aprbrk_1.ans2;
    d__[9] = pp3 - aprbrk_1.ans3;
L1033:
    aprbrk_1.kword += 4;
    d__1 = d__[7] * d__[7] + d__[8] * d__[8] + d__[9] * d__[9];
    pig = sqrt(d__1);
    d__[7] /= pig;
    d__[8] /= pig;
    d__[9] /= pig;

/* ...  CALCULATE ROTATION MATRIX */

L1034:
    if (abs(d__[9]) > (float).707) {
	goto L1036;
    }
/* L1035: */
    d__1 = (float)1. - d__[9] * d__[9];
    d__[6] = -sqrt(d__1);
    d__[5] = d__[8] * d__[9] / (-d__[6]);
    d__[4] = d__[7] * d__[9] / (-d__[6]);
    d__[3] = (float)0.;
    d__[2] = -d__[7] / (-d__[6]);
    d__[1] = d__[8] / (-d__[6]);
    goto L1037;
L1036:
    d__1 = (float)1. - d__[8] * d__[8];
    d__[5] = sqrt(d__1);
    d__[6] = -d__[8] * d__[9] / d__[5];
    d__[4] = -d__[7] * d__[8] / d__[5];
    d__[3] = -d__[7] / d__[5];
    d__[2] = (float)0.;
    d__[1] = d__[9] / d__[5];
L1037:
    aprbrk_1.kfrnt = ideftb_(&c__1) - aprbrk_1.kword;
    d__[11] = afull8_(&c__0, &c__0);

/* ...  ARE POINTS ALL CONVERTED */

L2001:
    if (aprbrk_1.kfrnt <= 0) {
	goto L2004;
    } else {
	goto L1039;
    }

/* ...  MOVE POINTS TO CANNONICAL FORM AND */
/* ...  CONVERT TO XYZ IF NECESSARY */

L1039:
    aprbrk_1.kadd = 996 - aprbrk_1.kfrnt;
    aprbrk_1.kadd1 = kptctr * 7 + 13;
    for (i3 = 1; i3 <= 7; ++i3) {
	l3 = aprbrk_1.kadd1 - 1 + i3;
	d__[l3 - 1] = (float)0.;
/* L1043: */
    }
    switch ((int)aprbrk_1.jmod1) {
	case 1:  goto L1040;
	case 2:  goto L1045;
	case 3:  goto L1050;
	case 4:  goto L1055;
	case 5:  goto L1087;
	case 6:  goto L22;
    }

/* ...  THETAR ROUTINE */

L22:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L23;
    } else {
	goto L1042;
    }
L23:
    sav1 = d__[aprbrk_1.kadd - 1];
    d__[aprbrk_1.kadd - 1] = d__[aprbrk_1.kadd];
    d__[aprbrk_1.kadd] = sav1;
    goto L1041;

/* ...  RTHETA ROUTINE */

L1040:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L1041;
    } else {
	goto L1042;
    }
L1041:
    d__1 = d__[aprbrk_1.kadd] / rdtodg;
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd - 1] * cos(d__1);
    d__1 = d__[aprbrk_1.kadd] / rdtodg;
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd - 1] * sin(d__1);
    aprbrk_1.kfrnt += -2;
    goto L1060;
L1042:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd + 1];
    aprbrk_1.kfrnt += -4;
    goto L1060;

/* ...  NOZ ROUTINE */

L1045:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L1046;
    } else {
	goto L1042;
    }
L1046:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd - 1];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd];
    aprbrk_1.kfrnt += -2;
    goto L1060;

/* ...  NOY ROUTINE */

L1050:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L1046;
    } else {
	goto L1051;
    }
L1051:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd + 2];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd];
    aprbrk_1.kfrnt += -4;
    goto L1060;

/* ...  NOX ROUTINE */

L1055:
    if (ideftb_(&aprbrk_1.kadd) - 3001 != 0) {
	goto L1046;
    } else {
	goto L1056;
    }
L1056:
    d__[aprbrk_1.kadd1 - 1] = d__[aprbrk_1.kadd + 1];
    d__[aprbrk_1.kadd1] = d__[aprbrk_1.kadd + 2];
    aprbrk_1.kfrnt += -4;
L1060:
    aprbrk_1.kadd = 996 - aprbrk_1.kfrnt;

/* ...  MOVE AND CONVERT SLOPES TO CANNONICAL FORMS */

    switch ((int)aprbrk_1.jmod2) {
	case 1:  goto L1075;
	case 2:  goto L1061;
	case 3:  goto L1070;
	case 4:  goto L1071;
	case 5:  goto L1061;
    }

/* ...  TWOPT AND SPLINE ROUTINE */

L1061:
    if (ideftb_(&aprbrk_1.kadd) - 47 != 0) {
	goto L1062;
    } else {
	goto L1067;
    }
L1062:
    if (ideftb_(&aprbrk_1.kadd) - 111 != 0) {
	goto L1063;
    } else {
	goto L1068;
    }
L1063:
    d__[aprbrk_1.kadd1 + 1] = afull8_(&c__0, &c_n1);
    goto L1075;
L1067:
    d__[aprbrk_1.kadd1 + 1] = d__[aprbrk_1.kadd];
    aprbrk_1.kfrnt += -2;
    goto L1075;
L1068:
    ageold = (d__[aprbrk_1.kadd] - (float)90.) / rdtodg;
/* Computing MAX */
    d__3 = (d__1 = cos(ageold), abs(d__1));
    d__2 = max(d__3,1e-9);
    d__4 = cos(ageold);
    d__[aprbrk_1.kadd1 + 1] = sin(ageold) / d_sign(&d__2, &d__4);
    aprbrk_1.kfrnt += -2;
    goto L1075;

/* ...  PTSLOP ROUTINE */

L1070:
    d__[aprbrk_1.kadd1 + 1] = d__[aprbrk_1.kadd - 1];
    --aprbrk_1.kfrnt;
    goto L1075;

/* ...  PTNORM ROUTINE */

L1071:
    ageold = (d__[aprbrk_1.kadd - 1] - (float)90.) / rdtodg;
/* Computing MAX */
    d__3 = (d__1 = cos(ageold), abs(d__1));
    d__2 = max(d__3,1e-9);
    d__4 = cos(ageold);
    d__[aprbrk_1.kadd1 + 1] = sin(ageold) / d_sign(&d__2, &d__4);
    --aprbrk_1.kfrnt;
L1075:
    jbr = 1;
L3001:
    aprepd_(&jbr);
    switch ((int)jbr) {
	case 1:  goto L2000;
	case 2:  goto L4001;
	case 3:  goto L4002;
    }
L2000:
    ++kptctr;

/* ...  CHECK POINT COUNTER */

    if ((i__1 = kptctr - 139) < 0) {
	goto L2001;
    } else if (i__1 == 0) {
	goto L3057;
    } else {
	goto L2002;
    }
L3057:
    if (aprbrk_1.kfrnt <= 0) {
	goto L2004;
    } else {
	goto L2002;
    }
L2002:
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    e_wsfe();
    a1com_1.jsuber = 1001;
    return 0;
L2004:
    d__[10] = afull8_(&c__0, &kptctr);
    i__1 = kptctr * 7 + 12;
    d__[0] = afull8_(&c__0, &i__1);

/* ...    BRING IN TITLE FROM COMMON */

/* L3023: */

/* 1962    PREPRO        3/31/66  1Q66 */
    mm[0] = 0;

/* ...    GO TO...4PT,2PT,PTNORM,PTSLOPE, OR SPLINE */

    switch ((int)aprbrk_1.jmod2) {
	case 1:  goto L8005;
	case 2:  goto L8006;
	case 3:  goto L8004;
	case 4:  goto L8004;
	case 5:  goto L8008;
    }
/* ...  IF TABCYL IS ALREADY IN CANONICAL FORM , */
/* ...  MOVE BACK ONE LOCATION AND ADD HEADING. */

L10:
    n12 = ideftb_(&c__1) - 1;
    i__1 = n12;
    for (i__ = 1; i__ <= i__1; ++i__) {
	d__[i__] = d__[i__ + 1];
/* L12: */
    }
    idummy = (integer) d__[10];
    d__[10] = afull8_(&c__0, &idummy);
    goto L8129;

/*     PTNORM,PTSLOPE */
/* ...  SLOPES ARE ALL GIVEN */
/* ...  SB=SLOPE AT FIRST PT OF TABCYL */
/* ...  SE2=SLOPE AT END PT */

L8004:
    sb = d__[21];
    m1 = ideftb_(&c__11) * 7 + 8;
    se2 = d__[m1 - 1];
    if (aprbrk_1.jmod2 - 5 >= 0) {
	goto L9986;
    } else {
	goto L8020;
    }

/* ...  FOR SPLINE FIT ONLY......... */
/* ...  WRITE OUT FIXED INFORMATION ABOUT TABCYL POINTS */

L9986:
    aprepc_();
    goto L8020;

/* ...  FOUR POINT METHOD */

/* ...     M1 POINTS TO U-COORD. OF INTERVAL BETWEEN (N-1)TH AND */
/* ...     (N-2)TH INPUT POINTS, WHERE NTH IS LAST INPUT POINT */
L8005:
    m1 = ideftb_(&c__11) * 7 - 8;
    d__[12] = (float)0.;
    d__[13] = (float)0.;
    n = 1;
    goto L8007;

/* ...  2PT...CHECK FOR SLOPES AT FIRST AND LAST POINTS */

L8006:
    if (ideftb_(&c__22) + 1 != 0) {
	goto L8011;
    } else {
	goto L8012;
    }
L8011:
    sb = d__[21];
    goto L8014;

/* ...  SLOPE PASSES CIRCLE THRU 3 PTS,AND FINDS */

L8012:
/* Computing 2nd power */
    d__2 = d__[26] - d__[19];
/* Computing 2nd power */
    d__3 = d__[27] - d__[20];
/* Computing 2nd power */
    d__4 = d__[33] - d__[19];
/* Computing 2nd power */
    d__5 = d__[34] - d__[20];
    d__1 = (d__2 * d__2 + d__3 * d__3) * (d__[33] - d__[19]) - (d__4 * d__4 + 
	    d__5 * d__5) * (d__[26] - d__[19]);
/* Computing 2nd power */
    d__6 = d__[26] - d__[19];
/* Computing 2nd power */
    d__7 = d__[27] - d__[20];
/* Computing 2nd power */
    d__8 = d__[33] - d__[19];
/* Computing 2nd power */
    d__9 = d__[34] - d__[20];
/* Computing MAX */
    d__11 = abs(d__1);
    d__10 = max(d__11,1e-9);
    sb = ((d__6 * d__6 + d__7 * d__7) * (d__[34] - d__[20]) - (d__8 * d__8 + 
	    d__9 * d__9) * (d__[27] - d__[20])) / d_sign(&d__10, &d__1);
    d__[21] = sb;
L8014:
    m1 = ideftb_(&c__11) * 7 + 8;
    if (ideftb_(&m1) + 1 != 0) {
	goto L8016;
    } else {
	goto L8018;
    }
L8016:
    se2 = d__[m1 - 1];
    goto L8020;
L8018:
/* Computing 2nd power */
    d__2 = d__[m1 - 10] - d__[m1 - 3];
/* Computing 2nd power */
    d__3 = d__[m1 - 9] - d__[m1 - 2];
/* Computing 2nd power */
    d__4 = d__[m1 - 17] - d__[m1 - 3];
/* Computing 2nd power */
    d__5 = d__[m1 - 16] - d__[m1 - 2];
    d__1 = (d__2 * d__2 + d__3 * d__3) * (d__[m1 - 17] - d__[m1 - 3]) - (d__4 
	    * d__4 + d__5 * d__5) * (d__[m1 - 10] - d__[m1 - 3]);
/* Computing 2nd power */
    d__6 = d__[m1 - 10] - d__[m1 - 3];
/* Computing 2nd power */
    d__7 = d__[m1 - 9] - d__[m1 - 2];
/* Computing 2nd power */
    d__8 = d__[m1 - 17] - d__[m1 - 3];
/* Computing 2nd power */
    d__9 = d__[m1 - 16] - d__[m1 - 2];
/* Computing MAX */
    d__11 = abs(d__1);
    d__10 = max(d__11,1e-9);
    se2 = ((d__6 * d__6 + d__7 * d__7) * (d__[m1 - 16] - d__[m1 - 2]) - (d__8 
	    * d__8 + d__9 * d__9) * (d__[m1 - 9] - d__[m1 - 2])) / d_sign(&
	    d__10, &d__1);
    d__[m1 - 1] = se2;
L8020:
    m1 = ideftb_(&c__11) * 7 - 6;
    n = 2;
L8007:
    i__1 = m1;
    for (i__ = 13; i__ <= i__1; i__ += 7) {
	g = d__[i__ + 6];
	h__ = d__[i__ + 7];
	ik = i__;

/* ...    TRANSLATE ORIGIN TO D(I+7),D(I+8) */

	for (i3 = 1; i3 <= 4; ++i3) {
	    s[i3 - 1] = d__[ik - 1] - g;
	    t[i3 - 1] = d__[ik] - h__;
/* L9010: */
	    ik += 7;
	}

/* ...    ROTATE X AXIS UP TO D(I+14),D(I+15) */

/* Computing 2nd power */
	d__2 = s[2];
/* Computing 2nd power */
	d__3 = t[2];
	d__1 = d__2 * d__2 + d__3 * d__3;
	ro = sqrt(d__1);
	sinn = t[2] / ro;
	coss = s[2] / ro;
/* Computing MAX */
	d__3 = abs(s[2]);
	d__2 = max(d__3,1e-9);
	d__1 = t[2] / d_sign(&d__2, &s[2]);
	ro = atan(d__1);
	if (s[2] >= 0.) {
	    goto L9014;
	} else {
	    goto L9012;
	}
L9012:
	ro += (float)3.14159265;
L9014:
	d__[i__ + 11] = ro;

/* ... PASS THRU ROTATION MATRIX */

	for (i3 = 1; i3 <= 4; ++i3) {
	    u[i3 - 1] = s[i3 - 1] * coss + t[i3 - 1] * sinn;
	    v[i3 - 1] = -s[i3 - 1] * sinn + t[i3 - 1] * coss;
/* Computing 2nd power */
	    d__1 = u[i3 - 1];
	    sq[i3 - 1] = d__1 * d__1;
	    cb[i3 - 1] = u[i3 - 1] * sq[i3 - 1];
/* L9011: */
	}

/* ...  GO TO(4-PT,2-PT-SLOPE) */

/* L9015: */
	switch ((int)n) {
	    case 1:  goto L9114;
	    case 2:  goto L9050;
	}

/* ...  FOR FIRST AND LAST INTERVALS DEFINE NEW PT. */

L9114:
	if (i__ - 13 <= 0) {
	    goto L9111;
	} else {
	    goto L9211;
	}
L9111:
	u[0] = (d__[40] - g) * coss + (d__[41] - h__) * sinn;
/* Computing 2nd power */
	d__1 = u[0];
	sq[0] = d__1 * d__1;
	cb[0] = sq[0] * u[0];
	v[0] = (d__[40] - g) * (-sinn) + (d__[41] - h__) * coss;
L9211:
	if (i__ - m1 >= 0) {
	    goto L9311;
	} else {
	    goto L9025;
	}
L9311:
	n = m1 - 7;
	u[3] = (d__[n - 1] - g) * coss + (d__[n] - h__) * sinn;
/* Computing 2nd power */
	d__1 = u[3];
	sq[3] = d__1 * d__1;
	cb[3] = sq[3] * u[3];
	v[3] = (d__[n - 1] - g) * (-sinn) + (d__[n] - h__) * coss;

/* ...  CRAMERS RULE USED FOR SOLVING CUBIC THRU 4-PTS. */

L9025:
	den = (cb[0] - sq[2] * u[0]) * (sq[3] - u[2] * u[3]) - (cb[3] - sq[2] 
		* u[3]) * (sq[0] - u[2] * u[0]);
	an = v[0] * (sq[3] - u[2] * u[3]) - v[3] * (sq[0] - u[2] * u[0]);
	bn = v[3] * (cb[0] - sq[2] * u[0]) - v[0] * (cb[3] - sq[2] * u[3]);
/* Computing MAX */
	d__2 = abs(den);
	d__1 = max(d__2,1e-9);
	d__[i__ + 8] = an / d_sign(&d__1, &den);
/* Computing MAX */
	d__2 = abs(den);
	d__1 = max(d__2,1e-9);
	d__[i__ + 9] = bn / d_sign(&d__1, &den);
	d__[i__ + 10] = -d__[i__ + 8] * sq[2] - d__[i__ + 9] * u[2];
	t[0] = (d__[i__ + 8] * (float)2. * u[2] + d__[i__ + 9]) * u[2];

/* ...     SET SLOPES AT END POINTS = FIRST DERIVATIVE OF CUBIC */
/* ...     PASSING THROUGH RESPECTIVE END INTERVALS */

/* ...     IF CUBIC JUST COMPUTED FOR 1ST INTERVAL BETWEEN INPUT */
/* ...     POINTS, COMPUTE SLOPE AT 1ST INPUT POINT FOR EXTENSION */
	if (i__ != 13) {
	    goto L9030;
	}
	d__1 = atan(d__[23]) + d__[24];
/* Computing MAX */
	d__4 = (d__2 = cos(d__1), abs(d__2));
	d__3 = max(d__4,1e-9);
	d__5 = cos(d__1);
	sb = sin(d__1) / d_sign(&d__3, &d__5);

/* ...     IF CUBIC JUST COMPUTED FOR LAST INTERVAL BEWTEEN INPUT */
/* ...     POINTS, COMPUTE SLOPE AT LAST INPUT POINT FOR EXTENSION */
L9030:
	if (i__ != m1) {
	    goto L9059;
	}
	d__1 = d__[m1 + 8] * (float)3. * sq[2] + d__[m1 + 9] * (float)2. * u[
		2] + d__[m1 + 10];
	d__2 = atan(d__1) + d__[m1 + 11];
/* Computing MAX */
	d__5 = (d__3 = cos(d__2), abs(d__3));
	d__4 = max(d__5,1e-9);
	d__6 = cos(d__2);
	se2 = sin(d__2) / d_sign(&d__4, &d__6);
	goto L9059;

/* ...     TWOPT FORMAT - SEE IF SLOPE GIVEN AT ORIGIN OF SEGMENT */
L9050:
	i__2 = i__ + 9;
	if (ideftb_(&i__2) + 1 != 0) {
	    goto L9056;
	} else {
	    goto L9055;
	}

/* ...     SLOPE AT ORIGIN POINT OF SEGMENT NOT GIVEN - COMPUTE IT */
L9055:
/* Computing 2nd power */
	d__2 = v[0];
	d__1 = sq[0] + d__2 * d__2 - u[2] * u[0];
/* Computing MAX */
	d__4 = abs(d__1);
	d__3 = max(d__4,1e-9);
	s[0] = -u[2] * v[0] / d_sign(&d__3, &d__1);
	goto L250;

/* ...     SLOPE GIVEN - ROTATE IT INTO LOCAL SYSTEM */
L9056:
	s[0] = (-t[2] + d__[i__ + 8] * s[2]) / (s[2] + d__[i__ + 8] * t[2]);

/* ...     FOR ALL INTERVALS EXCEPT BEGINNING EXTENSION, SET UP */
/* ...     COMPONENTS OF INITIAL SLOPE VECTOR IN UV-SYSTEM, USING */
/* ...     U-COMPONENT OF VECTOR AT END OF PREVIOUS INTERVAL TO INDICATE */
/* ...     PROPER QUADRANT FOR NEW INITIAL VECTOR */
L250:
	if (i__ <= 13) {
	    goto L9060;
	}
	uslope = (float)1.;
	vslope = d__[i__ + 8];
	if (tu >= (float)0.) {
	    goto L280;
	}
	uslope = -uslope;
	vslope = -vslope;

/* ...     SEE IF U-COMPONENT OF SLOPE VECTOR ROTATED INTO LOCAL SYSTEM */
/* ...     OF INTERVAL IS NEGATIVE - IF SO, INDICATES TABCYL WILL BE */
/* ...     DISCONTINUOUS AT START OF THIS INTERVAL - ERROR */
L280:
	if (coss * uslope + sinn * vslope >= (float)0.) {
	    goto L9060;
	}

/* ...     TABCYL IS DISCONTINUOUS - OUTPUT DIAGNOSTIC MESSAGE */
	io___44.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___44);
	do_fio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&h__, (ftnlen)sizeof(doublereal));
	e_wsfe();

/* ...     CHECK FOR ENDING SLOPE */
L9060:
	i__2 = i__ + 16;
	if (ideftb_(&i__2) != -1) {
	    goto L9058;
	}
/* ...     SLOPE AT END OF INTERVAL NOT GIVEN - COMPUTE IT */
/* L9057: */
/* Computing 2nd power */
	d__2 = v[3];
	d__1 = sq[3] + d__2 * d__2 - u[2] * u[3];
/* Computing MAX */
	d__4 = abs(d__1);
	d__3 = max(d__4,1e-9);
	t[0] = u[2] * v[3] / d_sign(&d__3, &d__1);
	goto L9075;

/* ...  SLOPE GIVEN-ROTATE IT */

L9058:
	t[0] = (-t[2] + d__[i__ + 15] * s[2]) / (s[2] + d__[i__ + 15] * t[2]);

/* ...  D(I+9)=A,D(I+10)=B,COEFICIENTS OF CUBIC,D(I+11)=SEGMENT LENGTH */
L9075:
	d__[i__ + 8] = (t[0] + s[0]) / sq[2];
	d__[i__ + 9] = (s[0] * (float)-2. - t[0]) / u[2];
L9059:
	d__[i__ + 10] = u[2];

/* ...     COMPUTE A POINT .05 OF THE INTERVAL LENGTH BEFORE ITS FINAL */
/* ...     POINT, FOR COMPUTING A VECTOR TO INDICATE THE PROPER QUADRANT */
/* ...     FOR THE INITIAL SLOPE VECTOR OF THE FOLLOWING INTERVAL */
	tlu = d__[i__ + 10] * (float).95;
/* Computing 3rd power */
	d__1 = tlu;
/* Computing 2nd power */
	d__2 = tlu;
	tlv = d__[i__ + 8] * (d__1 * (d__1 * d__1)) + d__[i__ + 9] * (d__2 * 
		d__2) - (d__[i__ + 8] * d__[i__ + 10] + d__[i__ + 9]) * (d__[
		i__ + 10] * tlu);
/* ...     ROTATE THE U-COORDINATE OF THIS POINT FROM THE INTERVAL */
/* ...     REFERENCE SYSTEM TO THE TABCYL UV-SYSTEM, AND COMPUTE THE */
/* ...     U-COMPONENT OF THE VECTOR TO THE INTERVAL END POINT */
	tu = s[2] - (coss * tlu - sinn * tlv);

/* ...     COMPUTE MAXIMUM AND MINIMUM VALUES FOR THE INTERVAL */
/* L907: */
	s[0] = -d__[i__ + 10] * (d__[i__ + 8] * d__[i__ + 10] + d__[i__ + 9]);
	if ((d__1 = d__[i__ + 8], abs(d__1)) - (float)1e-7 <= 0.) {
	    goto L9061;
	} else {
	    goto L9062;
	}
L9061:
	d__[i__ + 8] = (float)0.;
	if ((d__1 = d__[i__ + 9], abs(d__1)) - (float)1e-7 <= 0.) {
	    goto L9063;
	} else {
	    goto L9064;
	}
L9063:
	d__[i__ + 9] = (float)0.;
	d__[i__ + 11] = (float)0.;
	d__[i__ + 12] = (float)0.;
	goto L9079;
L9064:
/* Computing 2nd power */
	d__1 = s[0];
	d__[i__ + 11] = -(d__1 * d__1) / d__[i__ + 9] * (float).25 / d__[i__ 
		+ 10];
/* ...   IN ST. NO. 9064 DIV'N BY D(I+11)FOR CORRECT MAX-MIN ITTRI NOTIFYD */

	if (d__[i__ + 11] <= 0.) {
	    goto L9065;
	} else {
	    goto L9066;
	}
L9066:
	d__[i__ + 12] = (float)0.;
	goto L9079;
L9065:
	d__[i__ + 12] = d__[i__ + 11];
	d__[i__ + 11] = (float)0.;
	goto L9079;
L9062:
/* Computing 2nd power */
	d__1 = d__[i__ + 9];
	temp = d__1 * d__1;
	tem1 = d__[i__ + 8] * (float)3. * s[0];
	d__1 = temp - tem1;
	tem3 = (temp - tem1) * sqrt(d__1) * (float)2.;
	tem2 = d__[i__ + 9] * (temp * (float)2. - tem1 * (float)3.);
	tem4 = tem2 + d_sign(&tem3, &tem2);
/* Computing 2nd power */
	d__1 = s[0];
	tem3 = d__1 * d__1 * (tem1 * (float)1.3333333 - temp);
/* Computing 2nd power */
	d__1 = d__[i__ + 8];
	temp = tem4 / (d__1 * d__1 * (float)27.);
	tem1 = tem3 / tem4;
	if (s[0] <= 0.) {
	    goto L9067;
	} else {
	    goto L9068;
	}
L9067:
	if (t[0] >= 0.) {
	    goto L9069;
	} else {
	    goto L9068;
	}
L9069:
	d__[i__ + 11] = (float)0.;
	goto L9070;
L9068:
	if (tem2 <= 0.) {
	    goto L9071;
	} else {
	    goto L9072;
	}
L9072:
	d__[i__ + 11] = temp / u[2];
	goto L9070;
L9071:
	d__[i__ + 11] = tem1 / u[2];
L9070:
	if (s[0] >= 0.) {
	    goto L9074;
	} else {
	    goto L9073;
	}
L9074:
	if (t[0] <= 0.) {
	    goto L9076;
	} else {
	    goto L9073;
	}
L9076:
	d__[i__ + 12] = (float)0.;
	goto L9079;
L9073:
	d__[i__ + 11] = -d__[i__ + 11];
	if (tem2 <= 0.) {
	    goto L9077;
	} else {
	    goto L9078;
	}
L9078:
	d__[i__ + 12] = tem1 / u[2];
	goto L9079;
L9077:
	d__[i__ + 12] = temp / u[2];
L9079:
	;
    }
/* .....EXTEND TABCYL 10INS.AT BOTH ENDS USE DOT PRDT TO FIND DIRECTION */
    ext = (float)10.;
    aprbrk_1.l2 = ideftb_(&c__11) * 7 + 6;
    x = d__[aprbrk_1.l2 - 8];
    y = d__[aprbrk_1.l2 - 7];
    jsww = 0;
L8050:
/* Computing 2nd power */
    d__2 = se2;
    d__1 = d__2 * d__2 + (float)1.;
    t[0] = (float)1. / sqrt(d__1);
    delta = ext * t[0];

/* ...  X2,Y2=PT AT END OF EXTENSION */
/* ...  X,Y=PT AT BEGINNING OF EXTENSION */

    x2 = d__[aprbrk_1.l2 - 1] + delta;
    if (abs(delta) - (float)5e-6 <= 0.) {
	goto L8052;
    } else {
	goto L8054;
    }
L8052:
    x2 = d__[aprbrk_1.l2 - 1];
    y2 = d__[aprbrk_1.l2] + (float)10.;
    if ((x - d__[aprbrk_1.l2 - 1]) * (x2 - d__[aprbrk_1.l2 - 1]) + (y - d__[
	    aprbrk_1.l2]) * (y2 - d__[aprbrk_1.l2]) <= 0.) {
	goto L8046;
    } else {
	goto L8053;
    }
L8053:
    y2 = d__[aprbrk_1.l2] - (float)10.;
    goto L8046;
L8054:
    y2 = d__[aprbrk_1.l2] + se2 * delta;
    if ((x - d__[aprbrk_1.l2 - 1]) * (x2 - d__[aprbrk_1.l2 - 1]) + (y - d__[
	    aprbrk_1.l2]) * (y2 - d__[aprbrk_1.l2]) <= 0.) {
	goto L8046;
    } else {
	goto L8045;
    }
L8045:
    x2 = d__[aprbrk_1.l2 - 1] - delta;
    y2 = d__[aprbrk_1.l2] - se2 * delta;
/* ...  JSWW=0 - LAST INTERVAL */
/* ...  JSWW=1 - FIRST INTERVAL */
L8046:
    if (jsww <= 0) {
	goto L8047;
    } else {
	goto L8049;
    }
L8047:
    d__[aprbrk_1.l2 + 6] = x2;
    d__[aprbrk_1.l2 + 7] = y2;

/* ...  CUBIC IS DEGENERATE IN EXTENSION INTERVALS */

    d__[aprbrk_1.l2 + 5] = (float)0.;
    d__[aprbrk_1.l2 + 4] = (float)0.;
    d__[aprbrk_1.l2 + 2] = (float)0.;
    d__[aprbrk_1.l2 + 1] = (float)0.;
/* L8048: */
    svse2 = se2;
    se2 = sb;
    aprbrk_1.l2 = 20;
    x = d__[26];
    y = d__[27];
    jsww = 1;
    goto L8050;
L8049:
    se2 = svse2;
    d__[12] = x2;
    d__[13] = y2;
    d__[18] = (float)0.;
    d__[17] = (float)0.;
    d__[15] = (float)0.;
    d__[14] = (float)0.;

/* ...  WHEN NECESSARY STATEMENTS 8100 TO 8100+8 PROVIDE AUTOMATIC DECREA */
/* ...  SE IN EXTENSION LENGTHS TO AVOID INTERSECTION */

    aprbrk_1.l2 = ideftb_(&c__11) * 7 - 1;
    d__1 = sb - se2;
    if (abs(d__1) - (float)5e-6 >= 0.) {
	goto L8110;
    } else {
	goto L8120;
    }

/* ...  X,Y=PT OF INTERSECTION OF EXTENSIONS */
/* ...  IS IT BEYOND 10 INCHES AWAY FROM ENDS OF TABCYL */
/* ...  N0,DECREASE EXTENSION LENGTHS */
/* ...  YES,TRANSFER OUT */

L8110:
    x = (d__[aprbrk_1.l2 + 7] - d__[13] + sb * d__[12] - se2 * d__[
	    aprbrk_1.l2 + 6]) / (sb - se2);
    y = sb * (x - d__[12]) + d__[13];
/* Computing 2nd power */
    d__1 = x - d__[19];
/* Computing 2nd power */
    d__2 = y - d__[20];
    if (d__1 * d__1 + d__2 * d__2 - (float)100. >= 0.) {
	goto L8111;
    } else {
	goto L8112;
    }
L8111:
/* Computing 2nd power */
    d__1 = x - d__[aprbrk_1.l2 + 6];
/* Computing 2nd power */
    d__2 = y - d__[aprbrk_1.l2 + 7];
    if (d__1 * d__1 + d__2 * d__2 - (float)100. >= 0.) {
	goto L8120;
    } else {
	goto L8112;
    }
L8112:
    if ((d__[aprbrk_1.l2 - 1] - d__[aprbrk_1.l2 + 6]) * (x - d__[aprbrk_1.l2 
	    + 6]) + (d__[aprbrk_1.l2] - d__[aprbrk_1.l2 + 7]) * (y - d__[
	    aprbrk_1.l2 + 7]) <= 0.) {
	goto L8113;
    } else {
	goto L8120;
    }
L8113:
    if ((d__[26] - d__[19]) * (x - d__[19]) + (d__[27] - d__[20]) * (y - d__[
	    20]) <= 0.) {
	goto L8114;
    } else {
	goto L8120;
    }
L8114:
    d__[aprbrk_1.l2 + 13] = x - (x - d__[aprbrk_1.l2 + 6]) * (float).01;
    d__[aprbrk_1.l2 + 14] = y - (y - d__[aprbrk_1.l2 + 7]) * (float).01;
    d__[12] = x - (x - d__[19]) * (float).01;
    d__[13] = y - (y - d__[20]) * (float).01;
/* L8115: */
    io___60.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___60);
    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
    e_wsfe();
L8120:
/* Computing 2nd power */
    d__2 = d__[aprbrk_1.l2 + 13] - d__[aprbrk_1.l2 + 6];
/* Computing 2nd power */
    d__3 = d__[aprbrk_1.l2 + 14] - d__[aprbrk_1.l2 + 7];
    d__1 = d__2 * d__2 + d__3 * d__3;
    d__[aprbrk_1.l2 + 10] = sqrt(d__1);
/* Computing 2nd power */
    d__2 = d__[19] - d__[12];
/* Computing 2nd power */
    d__3 = d__[20] - d__[13];
    d__1 = d__2 * d__2 + d__3 * d__3;
    d__[16] = sqrt(d__1);
    i__1 = ideftb_(&c__11) + 1;
    d__[10] = afull8_(&c__0, &i__1);
    i__1 = ideftb_(&c__1) + 2;
    d__[0] = afull8_(&c__0, &i__1);
L8129:
    numpts = ideftb_(&c__11) * 7 + 7;
    icv1 = ideftb_(&c__1);
    icv11 = ideftb_(&c__11);
    io___64.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___64);
    do_fio(&c__1, (char *)&icv1, (ftnlen)sizeof(integer));
    for (i__ = 2; i__ <= 10; ++i__) {
	do_fio(&c__1, (char *)&d__[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    do_fio(&c__1, (char *)&icv11, (ftnlen)sizeof(integer));
    i__1 = numpts;
    for (i__ = 13; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&d__[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L799;
L8008:
    aprepb_();
    goto L8004;
L799:
    ageold = d__[10];
    ajold = d__[11];
    j = 12;
    for (i__ = 1; i__ <= 9; ++i__) {
	d__[j - 1] = d__[j - 3];
/* L7777: */
	--j;
    }
    d__[1] = ageold;
    d__[2] = ajold;
    return 0;
L1087:
    jbr = 2;
    goto L3001;
L3000:
    jbr = 3;
    goto L3001;
} /* aprepr_ */

#undef deftab
#undef d__


