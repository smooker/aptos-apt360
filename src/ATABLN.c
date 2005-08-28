/* ATABLN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

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

static integer c__1 = 1;
static real c_b16 = (float)1.5707963;
static doublereal c_b41 = 1e-14;

/* Subroutine */ int atabln_()
{
    /* Format strings */
    static char fmt_1105[] = "";
    static char fmt_1106[] = "";
    static char fmt_1107[] = "";
    static char fmt_100[] = "(\0020\0028e14.6)";
    static char fmt_23[] = "(\0020TABCYL TANGENT LINE FAILURE\002)";
    static char fmt_6[] = "(\0020MORE THAN 1 POINT OF TANGENCY ON TABCYL\002)"
	    ;
    static char fmt_300[] = "(\002 \0022f14.6)";
    static char fmt_14[] = "(\0020TABCYL TANGENT LINE NOT FOUND\002)";
    static char fmt_410[] = "(\0020TABCYL NORMAL LINE NOT FOUND\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    double sqrt(), d_sign(), atan();
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6201)
    static integer i__, j;
    static doublereal r__[22], r1, x0, x1, y1, x2, y2, y0, aa[22];
#define id ((integer *)&avst_1 + 12402)
    static doublereal co[11], ra;
    static integer ii;
    static doublereal er, xa, ya, xb, yb;
    static integer it;
    static doublereal xc, yc, xd, yd;
    static integer nt, iz, nn;
    static doublereal x11, y11, ry, eq1, eq2;
    static integer ine[3], ite, ihu, kit;
    static doublereal tol, slp;
    static integer inz, izt;
    static doublereal equ2;
    static integer luck, ihut;
    static doublereal slop;
    static integer itry, k000fx, ifall;
    static doublereal delta;
    extern /* Subroutine */ int slite_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int aschtb_();
    static doublereal costha;
    static integer isense;
    static doublereal sintha, borslp;
    extern /* Subroutine */ int slitet_(), atrnro_(), apolyr_();

    /* Fortran I/O blocks */
    static cilist io___39 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_23, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_410, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_100, 0 };


    /* Assigned format variables */
    static char *it_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* .....CONSTRUCT A LINE THRU A POINT AND TANGENT OR NORMAL(AS SPECIFIED) */
/* .....TO A TABCYL IN THE XY-PLANE */

/*               *          *          *          *          * */
/* *********************************************************************** */

/* .....SAVE SENSE LIGHT 1 CONDITION */

    isense = 0;
    slitet_(&c__1, &k000fx);
    switch ((int)k000fx) {
	case 1:  goto L160;
	case 2:  goto L161;
    }
L160:
    isense = 1;

/* .....FIND ESTIMATED TABCYL INTERVAL OF TANGENT OR NORMAL POINT. */

L161:
    er = (float)0.;
    ihu = 7;
    itry = 0;
    nt = (id[OTHER_ENDIAN_S(13)] - 1) * 7 + 21;
    aschtb_(&ihu, &d__[nt - 1], &d__[nt], &er);
    if (er != 0.) {
	goto L1;
    } else {
	goto L2;
    }
L1:
    a1com_1.jsuber = 1005;
    goto L15;

/* .....TRANSLATE AND ROTATE INTO COORDINATE SYSTEM OF THE SELECTED */
/* .....TABCYL INTERVAL */

L12:
    if (itry - 7 >= 0) {
	goto L13;
    } else {
	goto L2;
    }
L2:
    ihut = ihu;
    if (id[OTHER_ENDIAN_S(9)] - 18 != 0) {
	goto L411;
    } else {
	goto L412;
    }
L411:
    ite = nt - 10;
    izt = 18;
    goto L413;
/* ...   THIS AREA COMPUTES ROTATION ANGL OF INTRVL AXIS TO BASIC AXIS */
L1100:
    xa = d__[ihu + 6] - d__[ihu - 1];
    ya = d__[ihu + 7] - d__[ihu];
    d__1 = xa * xa + ya * ya;
    costha = sqrt(d__1);
    sintha = ya / costha;
    costha = xa / costha;
    d__1 = costha - (float)1e-6;
    if (abs(d__1) <= 0.) {
	goto L1101;
    } else {
	goto L1103;
    }
L1101:
    d__1 = c_b16;
    ra = -d_sign(&d__1, &sintha);
L1102:
    switch ((int)it) {
	case 0: goto L1105;
	case 1: goto L1106;
	case 2: goto L1107;
    }
L1103:
    d__1 = sintha / costha;
    ra = -atan(d__1);
    if (costha < 0.) {
	goto L1104;
    } else if (costha == 0) {
	goto L1101;
    } else {
	goto L1102;
    }
L1104:
    ra += (float)3.14159265;
    goto L1102;
/* .....EXTENSION INTERVALS ARE INCLUDED IN THE NORMAL LINE SEARCH. */
L412:
    ite = nt - 3;
    izt = 12;
L413:
    iz = 1;
    it = 0;
    it_fmt = fmt_1105;
    goto L1100;
L1105:
    atrnro_(&xa, &ya, &xb, &yb, &ra, &iz);
    xc = d__[1] - d__[ihu - 1];
    yc = d__[2] - d__[ihu];
    atrnro_(&xc, &yc, &xd, &yd, &ra, &iz);

/* .....TEST TO SEE IF GIVEN POINT IS ON OR OFF TABCYL */

    tol = 1e-5;
    if (xb + tol - xd >= 0.) {
	goto L71;
    } else {
	goto L206;
    }
L71:
    if (xd + tol >= 0.) {
	goto L72;
    } else {
	goto L206;
    }
L72:
/* Computing 3rd power */
    d__1 = xd;
/* Computing 2nd power */
    d__2 = xd;
    equ2 = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * 
	    d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 
	    3] * xd);
    d__1 = yd - equ2;
    if (abs(d__1) - tol <= 0.) {
	goto L70;
    } else {
	goto L206;
    }
L206:
    if (id[OTHER_ENDIAN_S(9)] - 18 != 0) {
	goto L73;
    } else {
	goto L207;
    }
L70:
/* Computing 2nd power */
    d__1 = xd;
    slop = d__[ihu + 1] * (float)3. * (d__1 * d__1) + d__[ihu + 2] * (float)
	    2. * xd - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu 
	    + 3];
    if (id[OTHER_ENDIAN_S(9)] - 18 != 0) {
	goto L290;
    } else {
	goto L200;
    }
L290:
    if (slop != 0.) {
	goto L291;
    } else {
	goto L76;
    }
L291:
    if (abs(slop) - (float)1. >= 0.) {
	goto L76;
    } else {
	goto L74;
    }
L74:
    r1 = xd - (float)1. / slop;
    ry = yd - (float)1.;
    goto L79;
L76:
    r1 = xd - (float)1.;
    ry = yd - slop;
    goto L79;
L200:
    if (abs(slop) - (float)1e-6 >= 0.) {
	goto L202;
    } else {
	goto L201;
    }
L201:
    if (slop >= 0.) {
	goto L204;
    } else {
	goto L203;
    }
L203:
    borslp = (float)9999999.;
    goto L205;
L204:
    borslp = (float)-9999999.;
    goto L205;
L202:
    borslp = (float)-1. / slop;
L205:
    slop = borslp;
    goto L290;

/* .....CALCULATE COEFFICIENTS OF THE CUBIC EQUATION AND SOLVE FOR THE */
/* .....POINTS OF TANGENCY */

L73:
    aa[0] = d__[ihu + 1] * (float)2.;
    if (abs(aa[0]) - 1e-14 >= 0.) {
	goto L1237;
    } else {
	goto L1236;
    }
L1236:
    aa[0] = d_sign(&c_b41, aa);
L1237:
    aa[1] = d__[ihu + 2] - d__[ihu + 1] * (float)3. * xd;
    aa[2] = d__[ihu + 2] * (float)-2. * xd;
    aa[3] = yd + (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] 
	    * xd);
    for (i__ = 1; i__ <= 22; ++i__) {
/* L16: */
	r__[i__ - 1] = (float)0.;
    }
    ifall = 0;
    ii = 3;
    nn = 7;
    apolyr_(aa, &ii, &nn, r__, &ifall);

/* .....TEST DEBUG FLAG */

    if (a1com_1.kdbug != 0) {
	goto L99;
    } else {
	goto L21;
    }
L99:
    io___39.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&xa, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ya, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xb, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yb, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xc, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yc, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xd, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yd, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___40.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___40);
    do_fio(&c__1, (char *)&r__[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[5], (ftnlen)sizeof(doublereal));
    e_wsfe();

/* .....TEST FOR ERRORS */

L21:
    if (ifall - 1 >= 0) {
	goto L22;
    } else {
	goto L3;
    }
L22:
    io___41.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___41);
    e_wsfe();
    goto L1;

/* .....ROOTS FOUND OKAY, TEST THEIR POSITIONS WITH RESPECT TO THE */
/* .....BOUNDARY POINTS OF THE INTERVAL */

L3:
    kit = -1;
    luck = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	ine[i__ - 1] = 0;
	kit += 2;
	if (r__[kit] != 0.) {
	    goto L24;
	} else {
	    goto L30;
	}
L30:
	if (r__[kit - 1] - 1e-6 <= 0.) {
	    goto L24;
	} else {
	    goto L25;
	}
L25:
	if (r__[kit - 1] * (xb - r__[kit - 1]) >= 0.) {
	    goto L26;
	} else {
	    goto L24;
	}
L26:
	++luck;
	ine[i__ - 1] = kit;
L24:
	;
    }
    if ((i__1 = luck - 1) < 0) {
	goto L27;
    } else if (i__1 == 0) {
	goto L28;
    } else {
	goto L4;
    }

/* .....MULTIPLE TANGENCY POINTS IN THE INTERVAL */

L4:
    io___45.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___45);
    e_wsfe();
    kit = -1;
    iz = -1;
    it = 1;
    it_fmt = fmt_1106;
    goto L1100;
L1106:
    for (i__ = 1; i__ <= 3; ++i__) {
	kit += 2;
	if (ine[i__ - 1] != 0) {
	    goto L298;
	} else {
	    goto L301;
	}
L298:
	r1 = r__[kit - 1];
/* Computing 3rd power */
	d__1 = r1;
/* Computing 2nd power */
	d__2 = r1;
	ry = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * 
		d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[
		ihu + 3] * r1);
	atrnro_(&r1, &ry, &xa, &ya, &ra, &iz);
	r1 = xa + d__[ihu - 1];
	ry = ya + d__[ihu];
	io___46.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___46);
	do_fio(&c__1, (char *)&r1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ry, (ftnlen)sizeof(doublereal));
	e_wsfe();
L301:
	;
    }
    goto L1;

/* .....TEST FOR NORMAL LINE WHEN GIVEN POINT */
/* .....IS NOT A POINT ON THE TABCYL. */
/* .....CALCULATE COEFFICIENTS FOR A FIFTH ORDER EQUATION */
/* .....WHICH DEFINES A POINT ON THE TABCYL INTERVAL (CUBIC EQUATION) */
/* .....WHERE THE NORMAL TO THE INTERVAL PASSES THROUGH THE GIVEN POINT */

L207:
/* Computing 2nd power */
    d__1 = d__[ihu + 1];
    co[0] = d__1 * d__1 * (float)3.;
    co[1] = d__[ihu + 1] * (float)5. * d__[ihu + 2];
/* Computing 2nd power */
    d__1 = d__[ihu + 2];
    co[2] = d__[ihu + 1] * (float)4. * (-(d__[ihu + 1] * d__[ihu + 3] + d__[
	    ihu + 2]) * d__[ihu + 3]) + d__1 * d__1 * (float)2.;
    co[3] = d__[ihu + 2] * (float)3. * (-(d__[ihu + 1] * d__[ihu + 3] + d__[
	    ihu + 2]) * d__[ihu + 3]) - d__[ihu + 1] * (float)3. * yd;
/* Computing 2nd power */
    d__1 = -(d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu + 3];
    co[4] = d__1 * d__1 - d__[ihu + 2] * (float)2. * yd + (float)1.;
    co[5] = xd - yd * (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu 
	    + 3];
    co[6] = co[0] * (float)5.;
    co[7] = co[1] * (float)4.;
    co[8] = co[2] * (float)3.;
    co[9] = co[3] * (float)2.;
    co[10] = co[4];
/* .....(X11,Y11) IS THE END POINT OF THE INTERVAL BEING */
/* .....CONSIDERED THAT IS NEAREST TO THE SPECIFIED POINT. */
    atrnro_(&d__[nt - 1], &d__[nt], &x11, &y11, &ra, &iz);
    if (x11 < 0.) {
	goto L40;
    } else if (x11 == 0) {
	goto L44;
    } else {
	goto L41;
    }
L40:
    x11 = (float)0.;
    goto L44;
L41:
    if ((d__1 = x11 - xb * (float).5) < 0.) {
	goto L40;
    } else if (d__1 == 0) {
	goto L44;
    } else {
	goto L43;
    }
L43:
    x11 = xb;
/* .....NEWTON'S METHOD IS USED TO SOLVE THE FIFTH ORDER */
/* .....EQUATION. X11 IS THE INITIAL ESTIMATE OF THE ROOT. */
L44:
    for (j = 1; j <= 200; ++j) {
/* Computing 5th power */
	d__1 = x11, d__2 = d__1, d__1 *= d__1;
/* Computing 4th power */
	d__3 = x11, d__3 *= d__3;
/* Computing 3rd power */
	d__4 = x11;
/* Computing 2nd power */
	d__5 = x11;
	eq1 = co[0] * (d__2 * (d__1 * d__1)) + co[1] * (d__3 * d__3) + co[2] *
		 (d__4 * (d__4 * d__4)) + co[3] * (d__5 * d__5) + co[4] * x11 
		- co[5];
/* Computing 4th power */
	d__1 = x11, d__1 *= d__1;
/* Computing 3rd power */
	d__2 = x11;
/* Computing 2nd power */
	d__3 = x11;
	eq2 = co[6] * (d__1 * d__1) + co[7] * (d__2 * (d__2 * d__2)) + co[8] *
		 (d__3 * d__3) + co[9] * x11 + co[10];
	delta = -eq1 / eq2;
	if (abs(delta) - 3e-6 >= 0.) {
	    goto L46;
	} else {
	    goto L47;
	}
L46:
	x11 += delta;
/* L45: */
    }
    goto L27;
L47:
    if (x11 + 5e-6 >= 0.) {
	goto L112;
    } else {
	goto L27;
    }
L112:
    if (xb + 5e-6 - x11 >= 0.) {
	goto L113;
    } else {
	goto L27;
    }
L113:
/* Computing 3rd power */
    d__1 = x11;
/* Computing 2nd power */
    d__2 = x11;
    y11 = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * d__2)
	     - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] * 
	    x11);
    r1 = x11;
    ry = y11;
    goto L79;

/* .....TANGENCY POINT NOT FOUND OR NOT IN INTERVAL, */
/* .....SET UP FOR RE-TRY UNTIL 3 INTERVALS ON EACH SIDE OF THE INITIAL */
/* .....INTERVAL HAVE BEEN TRIED------A TOTAL OF 7 INTERVALS. */
/* .....  (EXTENSION INTERVALS ARE INCLUDED FOR NORMAL LINE ONLY.) */

L27:
    ++itry;
    switch ((int)itry) {
	case 1:  goto L29;
	case 2:  goto L900;
	case 3:  goto L904;
	case 4:  goto L905;
	case 5:  goto L906;
	case 6:  goto L907;
	case 7:  goto L13;
    }
L29:
    ihu += 7;
L902:
    if (ihu - ite >= 0) {
	goto L27;
    } else {
	goto L12;
    }
L900:
    ihu += -14;
L903:
    if (ihu - izt <= 0) {
	goto L27;
    } else {
	goto L12;
    }
L904:
    ihu += 21;
    goto L902;
L905:
    ihu += -28;
    goto L903;
L906:
    ihu += 35;
    goto L902;
L907:
    ihu += -42;
    goto L903;
L13:
    if (id[OTHER_ENDIAN_S(9)] - 18 != 0) {
	goto L409;
    } else {
	goto L408;
    }
L409:
    io___54.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___54);
    e_wsfe();
    goto L1;
L408:
    io___55.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___55);
    e_wsfe();
    goto L1;

/* .....TANGENCY POINT FOUND, CALCULATE SECOND COORDINATE AND TRANSFORM */
/* .....THE POINT BACK TO THE XY-PLANE */

L28:
    i__1 = luck;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ine[i__ - 1] != 0) {
	    goto L33;
	} else {
	    goto L32;
	}
L32:
	;
    }
L33:
    inz = ine[i__ - 1];
    r1 = r__[inz - 1];
/* L9: */
/* Computing 3rd power */
    d__1 = r1;
/* Computing 2nd power */
    d__2 = r1;
    ry = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * d__2) 
	    - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] * 
	    r1);
L79:
    iz = -1;
    it = 2;
    it_fmt = fmt_1107;
    goto L1100;
L1107:
    atrnro_(&r1, &ry, &xa, &ya, &ra, &iz);
/* L1110: */
    d__[4] = d__[ihu - 1] + xa;
    d__[5] = d__[ihu] + ya;
    d__[6] = (float)0.;

/* .....CALCULATE CANONICAL FORM OF A LINE THRU TWO POINTS IN */
/* .....THE XY-PLANE */

/* L1120: */
    defans[2] = (float)0.;
    x1 = d__[1];
    y1 = d__[2];
    x2 = d__[4];
    y2 = d__[5];
    if (x1 - x2 != 0.) {
	goto L1000;
    } else {
	goto L914;
    }
L1000:
    slp = (y1 - y2) / (x1 - x2);
    if (abs(slp) - (float)5e-6 >= 0.) {
	goto L912;
    } else {
	goto L910;
    }
L910:
    x0 = (float)0.;
    y0 = y1;
    defans[0] = (float)0.;
    defans[1] = (float)1.;
    defans[3] = y1;
    goto L15;
L912:
    if (abs(slp) - (float)5e3 >= 0.) {
	goto L914;
    } else {
	goto L916;
    }
L914:
    x0 = x1;
    y0 = (float)0.;
    defans[0] = (float)1.;
    defans[1] = (float)0.;
    defans[3] = x1;
    goto L15;
L916:
/* Computing 2nd power */
    d__2 = slp;
    d__1 = d__2 * d__2 + (float)1.;
    x0 = sqrt(d__1);
    defans[0] = -slp / x0;
    defans[1] = (float)1. / x0;
    defans[3] = defans[0] * x1 + defans[1] * y1;

/* .....TEST DEBUG FLAG */

/* L137: */
    if (a1com_1.kdbug != 0) {
	goto L165;
    } else {
	goto L15;
    }
L165:
    io___64.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___64);
    do_fio(&c__1, (char *)&r1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ry, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xa, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ya, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&d__[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&d__[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&d__[6], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&x0, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y0, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* .....RESTORE SENSE LIGHT 1 CONDITION */

L15:
    if (isense != 0) {
	goto L162;
    } else {
	goto L163;
    }
L162:
    isense = 0;
    slite_(&c__1);
L163:
    return 0;
} /* atabln_ */

#undef defans
#undef deftab
#undef id
#undef d__


