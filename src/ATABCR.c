/* ATABCR.f -- translated by f2c (version 20000121).
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

static doublereal c_b33 = 1.5707963;
static doublereal c_b100 = 0.;
static integer c__1 = 1;

/* Subroutine */ int atabcr_()
{
    /* Format strings */
    static char fmt_11[] = "(\0020TABCYL MODIFIER INDETERMINANT\002)";
    static char fmt_1005[] = "";
    static char fmt_1006[] = "";
    static char fmt_330[] = "";
    static char fmt_1007[] = "";
    static char fmt_1008[] = "";
    static char fmt_44[] = "(\0020TABCYL TANGENT CIRCLE NOT FOUND\002)";
    static char fmt_100[] = "(\0020\0028e14.6)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();
    double sqrt(), d_sign(), atan(), cos(), sin();
    integer do_fio();

    /* Local variables */
#define d__ ((doublereal *)&avst_1 + 6201)
    static integer i__;
    static doublereal cc;
#define id ((integer *)&avst_1 + 12402)
    static doublereal ra, er, xa, x11, y11, ya;
    static integer it;
    static doublereal xf, yf, xi;
    static integer nt, iz;
    static doublereal xn[11], yn[11], px, py, xp, yp, rad, xaa, yaa, xbb, ybb,
	     dis;
    static integer ihu, itl, ntz, imod;
    static doublereal simd;
    static integer more;
    static doublereal dnor;
    static integer itfr;
    static doublereal vmod[8]	/* was [4][2] */;
    static integer less;
    static doublereal dotp;
    static integer inum, ihut;
    static doublereal dist, uint;
    static integer lout, itry;
    static doublereal savd6, delta, diamt, clope, bplin;
    static integer isave;
    static doublereal dmove;
    static integer imore, ilast, iless;
    static doublereal deltx, slope, toler, xcomp, ycomp, xlong, ylong;
    static integer ilout;
    static doublereal xaxis, yaxis;
    static integer kount;
    static doublereal xfnor, yfnor, xmove, ymove, xtest, d3save, d6save;
    static integer ibacfg;
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer icheck;
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int aschtb_();
    static integer idecrs;
    extern /* Subroutine */ int atabpt_();
    static doublereal costha;
    extern /* Subroutine */ int chkret_();
    static integer incres;
    static doublereal sintha, savxbb, vecnrl[11], epsiln, radsqr, dpvalu, 
	    cslope;
    static integer icount, itbpnt, ihuint;
    extern /* Subroutine */ int atrnro_();
    static doublereal xiplin, yiplin, slplin, xlenth;
    static integer introt, iontst, ifirst;
    static doublereal slopet, vecnrx, vecnry, xstart, axisxv, xintrs[11], 
	    yintrs[11], axisyv, sauint;

    /* Fortran I/O blocks */
    static cilist io___32 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___104 = { 0, 0, 0, fmt_44, 0 };
    static cilist io___109 = { 0, 0, 0, fmt_100, 0 };


    /* Assigned format variables */
    static char *it_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* .....CONSTRUCT A CIRCLE, OF GIVEN RADIUS, TANGENT TO A LINE AND A */
/* .....TABULATED CYLINDER IN THE XY-PLANE.   THE LINE AND TABCYL DO NOT */
/* ...  NECESSARILY HAVE TO INTERSECT. THE TANGENT POINT MAY BE */
/* .....IN EITHER OF THE EXTENSION INTERVALS. */

/*               *          *          *          *          * */
/* *********************************************************************** */

/* .....INITIALIZE */

    a1com_1.jsuber = 0;
    toler = 2.5e-5;

/* ...    INUM=1 IF RADIUS PARALLEL LINE INTERSECTS TABCYL, */
/* ...    2 IF DIA. + TOL. PARALLEL LINE INTERSECTS, */
/* ...    3 IF LINE + TOL. INTERSECTS */

    inum = 0;

/* ...    IBACFG=0 IF DIRECTION OF SEARCH IS FWD,1 IF BACKWARD */
/* ... */
    ibacfg = 0;

/* ...    ICOUNT IS COUNTER ON TABCYL INTERVALS SEARCHED */

    icount = 1;
    icheck = 0;
    iontst = 0;
    itbpnt = 0;
    vmod[0] = 1.;
    vmod[1] = -1.;
    vmod[2] = 0.;
    vmod[3] = 0.;
    vmod[4] = 0.;
    vmod[5] = 0.;
    vmod[6] = 1.;
    vmod[7] = -1.;

/* .....CHECK FOR NEGATIVE (D-TERM) IN LINE CANONICAL FORM. */

    if (d__[5] >= 0.) {
	goto L921;
    } else {
	goto L920;
    }

/* .....IF SO, CHANGE SIGNS OF D-, I-, AND J-TERMS IN LINE CANONICAL FORM. */

L920:
    d__[5] = -d__[5];
    d__[2] = -d__[2];
    d__[3] = -d__[3];
L921:
    er = 0.;

/* .....FIND TABCYL INTERVAL WHERE THE POINT OF TANGENCY OF THE CIRCLE */
/* .....AND TABCYL IS ESTIMATED TO BE. */

    ihu = 9;
    ilout = 0;
    lout = 0;
    nt = (id[OTHER_ENDIAN_S(17)] - 1) * 7 + 24;
    rad = d__[nt + 3];
    radsqr = rad * rad;
    epsiln = rad * 2e-5;
    delta = 1e-5 / rad;
    diamt = rad * 2. + toler;
    itry = 0;
    ntz = nt - 2;
    aschtb_(&ihu, &d__[nt - 1], &d__[nt], &er);
    ihut = ihu;
    itl = nt - 4;
    itfr = 14;
    d6save = d__[5];
    if (er != 0.) {
	goto L1;
    } else {
	goto L2;
    }

/* .....IF ERROR, SET FLAG AND GO OUT. */

L1:
    a1com_1.jsuber = 1005;
    goto L51;
/* ...  THIS TEST CHECKS FOR THE DEFINITION */
/*     CIRCLE/ON,LN,TANTO,TAB,MOD,NEARPT,RADIUS,R */
/* ...  IF SO SKIP THE CODING TO CONSTRUCT A PARALLEL LINE */
L2:
    if (id[OTHER_ENDIAN_S(1)] - 71 != 0) {
	goto L7001;
    } else {
	goto L7000;
    }
L7000:
    savd6 = d__[5];
    iontst = id[OTHER_ENDIAN_S(1)];
    goto L102;

/* .....EXAMINE MOD 1 AND SET A LINE PARALLEL TO THE GIVEN LINE, ON */
/* .....WHICH THE CENTER OF THE TANGENT CIRCLE WILL LIE. */

L7001:
    if (id[OTHER_ENDIAN_S(13)] - 31 != 0) {
	goto L4;
    } else {
	goto L3;
    }
L3:
    imod = 1;
    goto L9;
L4:
    if (id[OTHER_ENDIAN_S(13)] - 32 != 0) {
	goto L6;
    } else {
	goto L5;
    }
L5:
    imod = 2;
    goto L9;
L6:
    if (id[OTHER_ENDIAN_S(13)] - 35 != 0) {
	goto L8;
    } else {
	goto L7;
    }
L7:
    imod = 3;
    goto L9;
L8:
    if (id[OTHER_ENDIAN_S(13)] - 36 != 0) {
	goto L10;
    } else {
	goto L90;
    }
L90:
    imod = 4;
L9:
    xtest = d__[2] * vmod[imod - 1] + d__[3] * vmod[imod + 3];
    if (abs(xtest) - 1e-7 <= 0.) {
	goto L10;
    } else {
	goto L12;
    }

/* .....IF MODIFIER 1 IS IN ERROR */

L10:
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    e_wsfe();
    goto L1;
L12:
    if (xtest < 0.) {
	goto L13;
    } else if (xtest == 0) {
	goto L10;
    } else {
	goto L14;
    }
L13:
    d__[5] = abs(d__[5]) - abs(rad);
    savd6 = d__[5];
    goto L102;
L14:
    d__[5] = abs(d__[5]) + abs(rad);
    savd6 = d__[5];
L102:
    d3save = d__[2];
    inum = 1;
/* L15: */
    id[OTHER_ENDIAN_S(1)] = 27;
    id[OTHER_ENDIAN_S(3)] = ihu;

/* .....IHUINT=INDEX LOCATING INTERVAL IN WHICH INTERSECTION */
/* .....ACTUALLY OCCURS */
    ihuint = 0;

/* .....UINT= X COORD. IN LOCAL SYSTEM OF INTERSECTION POINT */
/* .....OF PARALLEL LINE AND TABCYL */

    uint = 0.;
/* L41: */
    ihu = ihut;
    d__[2] = d3save;
    iz = 1;
    it = 0;
    it_fmt = fmt_1005;
    goto L1000;
L1005:
    atrnro_(&xaa, &yaa, &xbb, &ybb, &ra, &iz);

/* .....TABCYL MODIFIER ACCEPTANCE CRITERION */
    if (id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 31 != 0) {
	goto L17;
    } else {
	goto L16;
    }
L16:
    dpvalu = 1.;
    goto L504;

/* .....THIS AREA COMPUTES ROTATION ANGLE OF INTERVAL AXIS TO BASIC AXIS */

L1000:
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
    d__1 = xaa * xaa + yaa * yaa;
    costha = sqrt(d__1);
    sintha = yaa / costha;
    costha = xaa / costha;
    if (abs(costha) - 1e-6 <= 0.) {
	goto L1001;
    } else {
	goto L1003;
    }
L1001:
    ra = -d_sign(&c_b33, &sintha);
L1002:
    switch ((int)it) {
	case 0: goto L1005;
	case 1: goto L1006;
	case 2: goto L330;
	case 3: goto L1007;
	case 4: goto L1008;
    }
L1003:
    d__1 = sintha / costha;
    ra = -atan(d__1);
    if (costha < 0.) {
	goto L1004;
    } else if (costha == 0) {
	goto L1001;
    } else {
	goto L1002;
    }
L1004:
    ra += 3.14159265;
    goto L1002;
L17:
    if (id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 32 != 0) {
	goto L19;
    } else {
	goto L18;
    }
L18:
    dpvalu = -1.;
L504:
    xaxis = 1.;
    yaxis = 0.;
    goto L22;
L19:
    if (id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 35 != 0) {
	goto L21;
    } else {
	goto L20;
    }
L20:
    dpvalu = 1.;
    goto L505;
L21:
    if (id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 36 != 0) {
	goto L10;
    } else {
	goto L91;
    }
L91:
    dpvalu = -1.;
L505:
    xaxis = 0.;
    yaxis = 1.;
L22:
L31:
    chkret_(&ihu, &rad, &introt, d__);
    if (introt <= 0) {
	goto L42;
    } else {
	goto L400;
    }
L400:
    dis = -(d__[2] * d__[ihu - 1] + d__[3] * d__[ihu] - savd6);
    atrnro_(&d__[2], &d__[3], &xf, &yf, &ra, &iz);
    xiplin = xf * dis;
    yiplin = yf * dis;

/* ...  CHECK FOR VERTICAL PARALLEL LINE IN LOCAL SYSTEM */

    if (abs(yf) - 1e-7 <= 0.) {
	goto L500;
    } else {
	goto L501;
    }
L500:
    slplin = 9e7;
    goto L502;
L501:
    slplin = -xf / yf;
L502:
    bplin = yiplin - slplin * xiplin;
/* .....DELETED CHECK FOR VERTICAL PLANE AND CALCULATION OF Y INTERCEPT */

    kount = 1;
    icheck = 0;

/* .....DIVISION OF TABCYL INTERVAL INTO 10 EQUAL PARTS */

L64:
    if (ibacfg <= 0) {
	goto L105;
    } else {
	goto L106;
    }
L106:
    xstart = xbb;
    xlenth = -xbb;
    goto L107;
L105:
    xstart = 0.;
    xlenth = xbb;
L107:
    kount = 2;
    goto L67;
L866:
    isave = i__ - 1;

/* .....SUBDIVISION OF LIKELY DIVISION. */

/* L65: */
    if (kount - 2 >= 0) {
	goto L103;
    } else {
	goto L64;
    }
L103:
    if (kount - 12 <= 0) {
	goto L66;
    } else {
	goto L42;
    }
L66:
    d__1 = xn[isave] - xn[isave - 1];
    xlenth = abs(d__1);
L633:
    xstart = xn[isave - 1];
    if (ibacfg <= 0) {
	goto L111;
    } else {
	goto L109;
    }
L109:
    xlenth = -xlenth;
L111:
    ++kount;
L67:
    deltx = xlenth / 10.;

/* .....IF LENGTH OF NORMAL VECTOR FROM TABCYL TO PLINE IS LESS THAN R */
/* .....RADSQR MORE=0,WHEN ONE IS FOUND GREATER THAN RADSQR MORE=2 */

/* L671: */
    more = 0;

/* .....INDEX OF FIRST VECTOR IN PROPER DIRECTION */

    ifirst = -1;

/* .....INDEX OF LAST VECTOR IN PROPER DIRECTION */

    ilast = -4;

/* .....LESS=5 UNTIL NORMAL VECTOR IS FOUND LESS THAN RADSQR,THEN LESS=1 */

    less = 5;
    iless = 0;
    imore = 0;
    for (i__ = 1; i__ <= 11; ++i__) {
	xi = (doublereal) (i__ - 1);
	xn[i__ - 1] = xstart + xi * deltx;
/* Computing 3rd power */
	d__1 = xn[i__ - 1];
/* Computing 2nd power */
	d__2 = xn[i__ - 1];
	yn[i__ - 1] = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (
		d__2 * d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * 
		(d__[ihu + 3] * xn[i__ - 1]);
/* Computing 2nd power */
	d__1 = xn[i__ - 1];
	slope = d__[ihu + 1] * 3. * (d__1 * d__1) + d__[ihu + 2] * 2. * xn[
		i__ - 1] - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[
		ihu + 3];

/* .....ALTERED INTERSECTION CALC TO USE LINES IN FORM AX+BY=D */

	slopet = sqrt(slope * slope + 1.);
	xfnor = 1. / slopet;
	yfnor = slope / slopet;
	dnor = xfnor * xn[i__ - 1] + yfnor * yn[i__ - 1];
	simd = xf * yfnor - yf * xfnor;
	if (abs(simd) - 1e-6 <= 0.) {
	    goto L79;
	} else {
	    goto L68;
	}
L68:
	xintrs[i__ - 1] = (yfnor * dis - yf * dnor) / simd;
	yintrs[i__ - 1] = (xfnor * dis - xf * dnor) / (xfnor * yf - xf * 
		yfnor);
/* L25: */
	vecnrx = xintrs[i__ - 1] - xn[i__ - 1];
	vecnry = yintrs[i__ - 1] - yn[i__ - 1];
	cc = (doublereal) iz;
	axisxv = xaxis * cos(ra) - cc * yaxis * sin(ra);
	axisyv = cc * xaxis * sin(ra) + yaxis * cos(ra);

/* .....CHECK TO SEE IF TABCYL MODIFIER IS ACCEPTABLE FOR THIS NORMAL */

	dotp = vecnrx * axisxv + vecnry * axisyv;
	if (dpvalu * dotp - 1e-5 <= 0.) {
	    goto L79;
	} else {
	    goto L80;
	}

/* .....LENGTH OF NORMAL VECTOR FROM TABCYL POINT TO PLINE */

L80:
/* Computing 2nd power */
	d__1 = vecnrx;
/* Computing 2nd power */
	d__2 = vecnry;
	vecnrl[i__ - 1] = d__1 * d__1 + d__2 * d__2;
	if (ifirst <= 0) {
	    goto L183;
	} else {
	    goto L184;
	}
L183:
	ifirst = i__;
L184:
	ilast = i__;

/* .....HAVE WE FOUND LOCATION OF CIRCLE CENTER */

	d__1 = vecnrl[i__ - 1] - radsqr;
	if (abs(d__1) - epsiln <= 0.) {
	    goto L83;
	} else {
	    goto L82;
	}
L82:
	if ((d__1 = vecnrl[i__ - 1] - radsqr) < 0.) {
	    goto L85;
	} else if (d__1 == 0) {
	    goto L83;
	} else {
	    goto L86;
	}
L85:
	less = 1;
	iless = i__;
	goto L876;
L86:
	more = 2;
	imore = i__;

/* .....DO WE HAVE ONE VECTOR GREATER AND ONE SMALLER THAN RADSQR */

L876:
	if (more - less <= 0) {
	    goto L84;
	} else {
	    goto L890;
	}

/* .....YES-ARE THEY ADJACENT */

L890:
	if ((i__1 = iless - imore, abs(i__1)) - 1 <= 0) {
	    goto L878;
	} else {
	    goto L84;
	}

/* .....YES-HAVE SUBDIVISIONS BECOME SMALL ENOUGH TO ASSUME */
/* .....PERPENDICULARITY */

/* 878 IF(ABS(XN(1)-XN(2))-1.0E-7)6070,6070,866 */
L878:
	if ((d__1 = xn[0] - xn[1], abs(d__1)) - 1e-7 <= 0.) {
	    goto L5500;
	} else {
	    goto L866;
	}
L79:
	vecnrl[i__ - 1] = -1.;
L84:
	;
    }
/* ...  UTILIZE TABPNT SUBROUTINE TO FIND THE INTERSECTION OF THE PARALLEL */
/* ...  LINE AND THE TABCYL. */

    if (itbpnt != 0) {
	goto L867;
    } else {
	goto L440;
    }
L440:
    atabpt_();
    itbpnt = 1;
    if (a1com_1.jsuber != 0) {
	goto L621;
    } else {
	goto L600;
    }
L600:
    ihuint = id[OTHER_ENDIAN_S(5)];
    uint = d__[0];
    a1com_1.jsuber = 0;
    sauint = uint;
/* Computing 2nd power */
    d__2 = d__[ihuint + 6] - d__[ihuint - 1];
/* Computing 2nd power */
    d__3 = d__[ihuint + 7] - d__[ihuint];
    d__1 = d__2 * d__2 + d__3 * d__3;
    savxbb = sqrt(d__1);
    d__[2] = d3save;

/* .....IS THIS INTERVAL WITHIN ONE ON EITHER SIDE OF */
/* .....INTERVAL OF INTERSECTION */

L867:
    if ((i__1 = ihu - ihuint, abs(i__1)) - 7 <= 0) {
	goto L800;
    } else {
	goto L621;
    }

/* .....IT IS WITHIN ONE-IS IT BEFORE,IN,OR AFTER THE INTERSECTION */
/* .....INTERVAL */

L800:
    if ((i__1 = ihu - ihuint) < 0) {
	goto L809;
    } else if (i__1 == 0) {
	goto L801;
    } else {
	goto L802;
    }
L809:
    if (abs(sauint) - 1e-6 <= 0.) {
	goto L803;
    } else {
	goto L621;
    }
L803:
    uint = xbb;
    goto L602;
L801:
    uint = sauint;
    goto L602;
L802:
    if ((d__1 = sauint - savxbb, abs(d__1)) - 1e-6 <= 0.) {
	goto L806;
    } else {
	goto L621;
    }
L806:
    uint = 0.;
L602:
/* Computing 2nd power */
    d__1 = uint;
    cslope = d__[ihu + 1] * 3. * (d__1 * d__1) + d__[ihu + 2] * 2. * uint - (
	    d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu + 3];

/* .....TEST FOR LINE PERPENDICULAR TO TABCYL */

    slopet = sqrt(cslope * cslope + 1.);
    xfnor = cslope / slopet;

/* .....XFNOR AND YFNOR ARE DIR. COSINES OF TANGENT LINE AT UINT */

    yfnor = -1. / slopet;

/* .....COSTHA IS COSINE OF ANGLE BETWEEN PLINE AND TANGENT LINE */

    d__1 = xfnor * xf + yfnor * yf;
    costha = abs(d__1);
    if (costha - min(.001,delta) <= 0.) {
	goto L6070;
    } else {
	goto L6073;
    }

/* .....LINE NOT PERPENDICULAR TO TABCYL */

L6073:
    if (icheck - 1 != 0) {
	goto L6074;
    } else {
	goto L603;
    }
L6074:
    if (kount - 12 <= 0) {
	goto L180;
    } else {
	goto L42;
    }

/* .....LINE PERPENDICULAR TO TABCYL */

L6070:
    if (abs(d__[3]) - 1e-7 <= 0.) {
	goto L651;
    } else {
	goto L650;
    }
L651:
    xcomp = 0.;
    ycomp = rad;
    clope = 9999999.;
    goto L652;
L650:
    clope = -d__[2] / d__[3];
/* Computing 2nd power */
    d__1 = clope;
    xcomp = sqrt(radsqr / (d__1 * d__1 + 1.));
    d__1 = clope * xcomp;
    ycomp = abs(d__1);
L652:
    iz = -1;
    it = 1;
    it_fmt = fmt_1006;
    goto L1000;
L1006:
    atrnro_(&uint, &c_b100, &px, &py, &ra, &iz);
    if ((i__1 = id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 32) < 0) {
	goto L608;
    } else if (i__1 == 0) {
	goto L609;
    } else {
	goto L610;
    }
L608:
    defans[0] = d__[ihu - 1] + px + xcomp;
    defans[1] = d__[ihu] + py + d_sign(&ycomp, &clope);
    goto L613;
L609:
    defans[0] = d__[ihu - 1] + px - xcomp;
    defans[1] = d__[ihu] + py - d_sign(&ycomp, &clope);
    goto L613;
L610:
    if ((i__1 = id[OTHER_ENDIAN_S((ntz << 1) - 1)] - 36) < 0) {
	goto L611;
    } else if (i__1 == 0) {
	goto L612;
    } else {
	goto L613;
    }
L611:
    defans[0] = d__[ihu - 1] + px + d_sign(&xcomp, &clope);
    defans[1] = d__[ihu] + py + ycomp;
    goto L613;
L612:
    defans[0] = d__[ihu - 1] + px - d_sign(&xcomp, &clope);
    defans[1] = d__[ihu] + py - ycomp;
    goto L613;

/* ...  THIS SECTION IS FOR THE CASE WHERE THE RADIUS OF CURVATURE OF THE */
/* ...  TABCYL IS SMALL,AND THE NORMALS FROM POINTS VERY CLOSE TOGETHER */
/* ...  ON THE TABCYL HIT THE STRAIGHT LINE UPON WHICH THE CIRCLE CENTER */
/* ...  IS TO LIE AT POINTS THAT ARE A SIGNIFICANT DISTANCE APART. */
L5500:
    d__1 = xn[0] - d__[0];
    if (abs(d__1) - (float)1e-7 <= 0.) {
	goto L6070;
    } else {
	goto L5501;
    }
L5501:
/* Computing 2nd power */
    d__1 = slplin;
    xp = (xn[i__ - 1] + slplin * (yn[i__ - 1] - bplin)) / (d__1 * d__1 + 1.);
/* Computing 2nd power */
    d__1 = slplin;
    yp = (slplin * (xn[i__ - 1] + slplin * yn[i__ - 1]) + bplin) / (d__1 * 
	    d__1 + 1.);
/* Computing 2nd power */
    d__1 = xn[i__ - 1] - xp;
/* Computing 2nd power */
    d__2 = yn[i__ - 1] - yp;
    dist = d__1 * d__1 + d__2 * d__2;
    dmove = radsqr - dist;
/* Computing 2nd power */
    d__1 = slplin;
    xmove = sqrt(dmove / (d__1 * d__1 + 1.));
    d__1 = slplin * xmove;
    ymove = abs(d__1);
    if (imore - iless <= 0) {
	goto L5502;
    } else {
	goto L5503;
    }
L5502:
    xlong = xintrs[i__ - 2];
    ylong = yintrs[i__ - 2];
    goto L5505;
L5503:
    xlong = xintrs[i__ - 1];
    ylong = yintrs[i__ - 1];
L5505:
    if (xlong - xp <= 0.) {
	goto L26;
    } else {
	goto L27;
    }
L26:
    xintrs[i__ - 1] = xp - xmove;
    goto L28;
L27:
    xintrs[i__ - 1] = xp + xmove;
L28:
    if (ylong - yp <= 0.) {
	goto L29;
    } else {
	goto L30;
    }
L29:
    yintrs[i__ - 1] = yp - ymove;
    goto L83;
L30:
    yintrs[i__ - 1] = yp + ymove;
    goto L83;
/* .....CHECK FOR A HUMP OR VALLEY WHERE THE SUCCESSIVE VECTOR LENGTHS */
/* .....CHANGE FROM INCREASING TO DECREASING OR VICE VERSA */

L621:
    incres = 0;
    idecrs = 0;
    a1com_1.jsuber = 0;
/* L199: */
    for (i__ = 1; i__ <= 11; ++i__) {
	if (i__ - 9 <= 0) {
	    goto L622;
	} else {
	    goto L42;
	}
L622:
	if (vecnrl[i__ - 1] >= 0.) {
	    goto L625;
	} else {
	    goto L630;
	}
L625:
	if (vecnrl[i__] >= 0.) {
	    goto L6251;
	} else {
	    goto L630;
	}
L6251:
	if (vecnrl[i__ + 1] >= 0.) {
	    goto L6252;
	} else {
	    goto L630;
	}
L6252:
	if ((d__1 = vecnrl[i__] - vecnrl[i__ - 1]) < 0.) {
	    goto L626;
	} else if (d__1 == 0) {
	    goto L630;
	} else {
	    goto L627;
	}
L626:
	idecrs = 1;
	goto L6271;
L627:
	incres = 1;
L6271:
	if ((d__1 = vecnrl[i__ + 1] - vecnrl[i__]) < 0.) {
	    goto L628;
	} else if (d__1 == 0) {
	    goto L630;
	} else {
	    goto L629;
	}
L628:
	idecrs = 1;
	goto L6291;
L629:
	incres = 1;
L6291:
	if (incres - idecrs != 0) {
	    goto L630;
	} else {
	    goto L631;
	}
L630:
	;
    }
    goto L42;
L631:
    if (kount - 12 <= 0) {
	goto L632;
    } else {
	goto L42;
    }
L632:
    if (kount - 12 >= 0) {
	goto L196;
    } else {
	goto L634;
    }
L634:
    d__1 = xn[i__ + 1] - xn[i__ - 1];
    xlenth = abs(d__1);
    isave = i__;
    goto L633;

/* .....SUBDIVIDE BETWEEN ADJACENT GOOD AND BAD VECTORS */

L180:
    if (ifirst <= 0) {
	goto L603;
    } else {
	goto L186;
    }
L186:
    if ((d__1 = vecnrl[ifirst - 1] - vecnrl[ilast - 1]) < 0.) {
	goto L181;
    } else if (d__1 == 0) {
	goto L193;
    } else {
	goto L185;
    }
L182:
    if (ifirst - 1 <= 0) {
	goto L196;
    } else {
	goto L187;
    }
L187:
    if (ifirst - 11 >= 0) {
	goto L196;
    } else {
	goto L188;
    }
L188:
    i__ = ifirst - 1;
    goto L632;
L185:
    if (less - 1 != 0) {
	goto L189;
    } else {
	goto L182;
    }
L189:
    if (ilast - 11 >= 0) {
	goto L196;
    } else {
	goto L190;
    }
L190:
    i__ = ilast - 1;
    goto L632;
L181:
    if (less - 1 != 0) {
	goto L182;
    } else {
	goto L189;
    }
L193:
    if (ifirst - 1 <= 0) {
	goto L191;
    } else {
	goto L194;
    }
L194:
    if (ilast - 11 >= 0) {
	goto L192;
    } else {
	goto L188;
    }
L191:
    i__ = 2;
L195:
    if (kount - 12 >= 0) {
	goto L196;
    } else {
	goto L866;
    }
L196:
    if (icheck - 1 >= 0) {
	goto L42;
    } else {
	goto L197;
    }
L197:
    icheck = 1;
    kount = 1;
    goto L64;
L192:
    i__ = 11;
    goto L195;
L618:
    if (kount - 12 <= 0) {
	goto L619;
    } else {
	goto L42;
    }

/* .....SUBDIVIDE AROUND THE INTERSECTION OF PARALLEL LINE AND TABCYL */

L619:
    if (i__ - 2 <= 0) {
	goto L720;
    } else {
	goto L721;
    }
L720:
    isave = i__ - 1;
L724:
    d__1 = xn[isave + 1] - xn[isave - 1];
    xlenth = abs(d__1);
    goto L633;
L721:
    isave = i__ - 2;
    if (i__ - 11 >= 0) {
	goto L724;
    } else {
	goto L722;
    }
L722:
    d__1 = xn[isave + 2] - xn[isave - 1];
    xlenth = abs(d__1);
    goto L633;
L603:
    for (i__ = 2; i__ <= 11; ++i__) {
	if (ibacfg <= 0) {
	    goto L604;
	} else {
	    goto L606;
	}
L604:
	if (uint - 1e-6 - xn[i__ - 1] <= 0.) {
	    goto L618;
	} else {
	    goto L605;
	}
L606:
	if (uint + 1e-6 - xn[i__ - 1] >= 0.) {
	    goto L618;
	} else {
	    goto L605;
	}
L605:
	;
    }

/* .....SET-UP RE-TRY IN ANOTHER INTERVAL UNTIL 3 INTERVALS ON EACH SIDE */
/* .....OF THE ESTIMATED INTERVAL HAVE BEEN TRIED----A TOTAL OF 7 */
/* .....INTERVALS.(EXTENSION INTERVALS ARE INCLUDED) */

L42:
    if (icount - 7 >= 0) {
	goto L43;
    } else {
	goto L422;
    }
L422:
    iz = -1;
    it = 2;
    it_fmt = fmt_330;
    goto L1000;
L330:
    if (icount % 2 != 0) {
	goto L300;
    } else {
	goto L301;
    }
L300:
    ihu = ihut + (icount + 1) / 2 * 7;
    ibacfg = 0;
    ++icount;
    if (ihu - itl >= 0) {
	goto L340;
    } else {
	goto L72;
    }
L301:
    ihu = ihut - icount / 2 * 7;
    ibacfg = 1;
    ++icount;
    if (ihu - itfr <= 0) {
	goto L350;
    } else {
	goto L72;
    }
L340:
    lout = 1;
    goto L330;
L350:
    ilout = 1;
    if (lout - ilout != 0) {
	goto L330;
    } else {
	goto L43;
    }
L43:
    io___104.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___104);
    e_wsfe();
    goto L1;
L72:
    iz = 1;
    it = 3;
    it_fmt = fmt_1007;
    goto L1000;
L1007:
    atrnro_(&xaa, &yaa, &xbb, &ybb, &ra, &iz);
    goto L31;
L83:
    x11 = xintrs[i__ - 1];
    y11 = yintrs[i__ - 1];

/* .....CENTER FOUND PUT IT BACK INTO ORIGINAL COORDINATE SYSTEM AND PUT */
/* .....CANONICAL FORM OF CIRCLE IN DEFANS BLOCK. */

/* L50: */
    iz = -1;
    it = 4;
    it_fmt = fmt_1008;
    goto L1000;
L1008:
    atrnro_(&x11, &y11, &xa, &ya, &ra, &iz);
    defans[0] = d__[ihu - 1] + xa;
    defans[1] = d__[ihu] + ya;
L613:
    defans[2] = 0.;
    defans[3] = 0.;
    defans[4] = 0.;
    defans[5] = 1.;
    defans[6] = rad;

/* .....TEST DEBUG FLAG */

    if (a1com_1.kdbug != 0) {
	goto L1009;
    } else {
	goto L51;
    }
L1009:
    io___109.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___109);
    do_fio(&c__1, (char *)&defans[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[6], (ftnlen)sizeof(doublereal));
    e_wsfe();
L51:
    return 0;
} /* atabcr_ */

#undef defans
#undef deftab
#undef id
#undef d__


