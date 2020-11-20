/* APREPC.f -- translated by f2c (version 20000121).
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
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

/* Table of constant values */

static integer c__11 = 11;
static integer c__1 = 1;
static doublereal c_b59 = .5;
static real c_b60 = (float)0.;

/* Subroutine */ int aprepc_()
{
    /* Format strings */
    static char fmt_1102[] = "(\002 TABULATED CYLINDER   \002,a6,\002(\002,i\
5,\002)\002)";
    static char fmt_1109[] = "(\0020 NUM        THETA        RADIUS         \
 X-C0RD\r      Y-CORD      SEG LENGTH       SEG ANGLE      EXT ANGLE \002)";
    static char fmt_1110[] = "(\002 \002i4,f15.4,4f15.6,2f15.4)";
    static char fmt_1111[] = "(\0020 NUM     SLOPE        NORMAL      ALPHA \
  TANGENT A   TANGENT B     CURV A    DELTA CURV\002)";
    static char fmt_1112[] = "(\002 \002i4,f12.5,2f12.4,2f12.7,f10.4,f13.4)";
    static char fmt_1103[] = "(\0020\00216x,f7.4,3(18x,f7.4),14x,f7.4)";
    static char fmt_1104[] = "(\002    CURVATURE    .+......................\
..+........................+........................+.......................\
.+.\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(), d_sign(), atan();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static doublereal cmin, cmax, conv, a, b;
#define d__ ((doublereal *)&avst_1 + 6200)
    static integer i__, j, k, l, m[7];
    static doublereal r__, tablx[8];
    static integer i1, i2, j2, m1;
    static doublereal ca[139], curti1, ga, curti2, curti4, al, curti5;
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer kk;
    static doublereal ta, tb, xa;
    static integer mm[7], kl;
    static doublereal th[139];
    extern integer ideftb_();
    static doublereal xl[139];
    static integer idoodl;
    static doublereal center, ga1, curvrg, phi, fmt[106], for__[12], cen1, 
	    cen2;

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 0, 0, fmt_1102, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_1109, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_1110, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_1102, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_1111, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_1112, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_1102, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_1103, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_1104, 0 };
    static cilist io___51 = { 0, 0, 0, (char *)fmt, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_1104, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 *** */

/*               *          *          *          *          * */
/*      DATA FOR/'(I4,F1  0.6,    4X,     1HX     1H*     1H+     1H0 */
/*     11H$     1H=     1H.     1H      1H.)    '  / */
/* *********************************************************************** */
/*     DEFINE FUNCTIONS */

/* ...  DEFINE TANF SO THAT ITS MAXIMUM MAGNITUDE IS 10**9 */
//not f2c generated:
char for__C[]="(I4,F1  0.6,    4X,     1HX     1H*     1H+     1H0      11H$     1H=     1H.     1H      1H.)    ";
#define for__ ((doublereal *)&for__C)


    xa = (float)0.;
    ga = (float)0.;
/* L9986: */
    conv = (float)57.295779513082321;
    kk = ideftb_(&c__11) - 1;
    i__1 = kk;
    for (j = 1; j <= i__1; ++j) {
	k = j * 7 + 13;
	a = d__[k - 1];
	b = d__[k];
	d__1 = a * a + b * b;
	r__ = sqrt(d__1);
/* Computing MAX */
	d__3 = abs(a);
	d__2 = max(d__3,1e-9);
	d__1 = b / d_sign(&d__2, &a);
	th[j - 1] = atan(d__1) * conv;
/* Computing 2nd power */
	d__2 = d__[k + 6] - d__[k - 1];
/* Computing 2nd power */
	d__3 = d__[k + 7] - d__[k];
	d__1 = d__2 * d__2 + d__3 * d__3;
	xl[j - 1] = sqrt(d__1);
	ga1 = ga;
	ga = atan(d__[k + 2]) * conv;
	if (j - 1 != 0) {
	    goto L175;
	} else {
	    goto L176;
	}
L175:
	if (j - kk != 0) {
	    goto L179;
	} else {
	    goto L176;
	}
L176:
	xa = (float)0.;
	goto L182;
L179:
	xa = ga - ga1;
L182:
	if (a1com_1.kdbug != 0) {
	    goto L183;
	} else {
	    goto L184;
	}
L183:
	if (j - 1 != 0) {
	    goto L186;
	} else {
	    goto L185;
	}
L185:
	io___15.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___15);
	do_fio(&c__1, (char *)&a2cls7_1.einame, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
	e_wsfe();
	io___16.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___16);
	e_wsfe();
L186:
	io___17.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___17);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&th[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&r__, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&d__[k + 3], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ga, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xa, (ftnlen)sizeof(doublereal));
	e_wsfe();
L184:
	;
    }

/* ...  WRITE OUT RESULTS OF CURVATURE MATCHING */

    i__1 = kk;
    for (j = 1; j <= i__1; ++j) {
	k = j * 7 + 13;
/* Computing MAX */
	d__4 = (d__1 = d__[k + 1], abs(d__1));
	d__3 = max(d__4,1e-9);
	d__2 = (float)-1. / d_sign(&d__3, &d__[k + 1]);
	phi = atan(d__2) * conv;
	al = phi - th[j - 1];
	if (j - kk != 0) {
	    goto L1861;
	} else {
	    goto L1862;
	}
L1861:
	ta = (d__[k + 1] - d__[k + 2]) / (d__[k + 1] * d__[k + 2] + (float)1.)
		;
	tb = (d__[k + 8] - d__[k + 2]) / (d__[k + 8] * d__[k + 2] + (float)1.)
		;
	goto L1863;
L1862:
	ta = (float)0.;
	tb = (float)0.;
	d__[k + 4] = (float)0.;
L1863:
/* Computing 2nd power */
	d__2 = ta;
/* Computing 3rd power */
	d__1 = (float)1. + d__2 * d__2;
	ca[j - 1] = -((float)4. * ta + (float)2. * tb) / (xl[j - 1] * sqrt(
		d__1 * (d__1 * d__1)));
	if (a1com_1.kdbug != 0) {
	    goto L1864;
	} else {
	    goto L189;
	}
L1864:
	if (j - 1 != 0) {
	    goto L188;
	} else {
	    goto L187;
	}
L187:
	io___23.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___23);
	do_fio(&c__1, (char *)&a2cls7_1.einame, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
	e_wsfe();
	io___24.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___24);
	e_wsfe();
L188:
	io___25.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___25);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&d__[k + 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&al, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ta, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tb, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ca[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&d__[k + 4], (ftnlen)sizeof(doublereal));
	e_wsfe();
L189:
	;
    }

/* ...  PLOT THE (MATCHED) CURVATURE AT EACH TABCYL POINT */

    for (i__ = 1; i__ <= 7; ++i__) {
/* L190: */
	m[i__ - 1] = 0;
    }
    tablx[0] = (float)0.;
    tablx[1] = (float).1;
    tablx[2] = (float).2;
    tablx[3] = (float).5;
    tablx[4] = (float)1.;
    tablx[5] = (float)2.;
    tablx[6] = (float)5.;
    tablx[7] = (float)10.;
    kl = kk - 1;
    i__1 = kk;
    for (j = 1; j <= i__1; ++j) {
	if (j - 1 <= 0) {
	    goto L219;
	} else {
	    goto L223;
	}
L219:
	io___30.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___30);
	do_fio(&c__1, (char *)&a2cls7_1.einame, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
	e_wsfe();
/* L112: */
	cmin = (float)1e10;
	cmax = (float)-1e10;
	i__2 = kl;
	for (l = 1; l <= i__2; ++l) {
/* Computing MIN */
	    d__1 = cmin, d__2 = ca[l - 1];
	    cmin = min(d__1,d__2);
/* L105: */
/* Computing MAX */
	    d__1 = cmax, d__2 = ca[l - 1];
	    cmax = max(d__1,d__2);
	}
	cen2 = (cmax - cmin) / (float)2.;
	for (l = 1; l <= 7; ++l) {
	    if (cen2 - tablx[l - 1] >= 0.) {
		goto L107;
	    } else {
		goto L106;
	    }
L107:
	    ;
	}
	l = 8;
L106:
	curvrg = tablx[l - 1];
	cen1 = (float)10. / curvrg;
	center = cen2 + cmin;
	idoodl = (integer) (center * cen1 + d_sign(&c_b59, &center));
	center = (doublereal) idoodl;
	center /= cen1;
	d__1 = c_b60;
	m[6] = (integer) ((float)50. * (d__1 - center) / curvrg + (float)
		51.50001);
	curti1 = center - curvrg;
	curti2 = center - curvrg * (float).5;
	curti4 = center + curvrg * (float).5;
	curti5 = center + curvrg;
	io___43.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___43);
	do_fio(&c__1, (char *)&curti1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&curti2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&center, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&curti4, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&curti5, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___44.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___44);
	e_wsfe();
L223:
	m[1] = (integer) ((float)50. * (ca[j - 1] - center) / curvrg + (float)
		51.50001);

/* ...  GRAPH SUBROUTINE */

/* L7911: */
	for (i__ = 1; i__ <= 3; ++i__) {
/* L7901: */
	    fmt[i__ - 1] = for__[i__ - 1];
	}
	fmt[3] = for__[9];
	for (i__ = 5; i__ <= 105; ++i__) {
/* L7902: */
	    fmt[i__ - 1] = for__[10];
	}
	fmt[105] = for__[11];
	for (i__ = 1; i__ <= 7; ++i__) {
	    if ((i__2 = m[i__ - 1]) < 0) {
		goto L7909;
	    } else if (i__2 == 0) {
		goto L7912;
	    } else {
		goto L7905;
	    }
L7909:
	    mm[i__ - 1] = 5;
	    goto L7903;
L7912:
	    mm[i__ - 1] = 0;
	    goto L7903;
L7905:
	    mm[i__ - 1] = m[i__ - 1];
	    if (mm[i__ - 1] > 101) {
		mm[i__ - 1] = 101;
	    }
	    mm[i__ - 1] += 4;
L7903:
	    ;
	}
	for (i__ = 1; i__ <= 6; ++i__) {
	    i1 = i__ + 1;
	    for (i2 = i1; i2 <= 7; ++i2) {
		if (mm[i__ - 1] - mm[i2 - 1] != 0) {
		    goto L7904;
		} else {
		    goto L7906;
		}
L7906:
		mm[i2 - 1] = 0;
L7904:
		;
	    }
	}
	for (i__ = 1; i__ <= 7; ++i__) {
	    if (mm[i__ - 1] <= 0) {
		goto L7907;
	    } else {
		goto L7908;
	    }
L7908:
	    j2 = mm[i__ - 1];
	    k = i__ + 3;
	    fmt[j2 - 1] = for__[k - 1];
L7907:
	    ;
	}
	io___51.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___51);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ca[j - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L209: */
    }
    io___52.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___52);
    e_wsfe();
    m1 = ideftb_(&c__11) * 6 + 9;
/* L8020: */
    return 0;
} /* aprepc_ */

#undef deftab
#undef d__


