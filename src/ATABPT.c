/* ATABPT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b23 = 1.5707963;
static doublereal c_b41 = 1e-14;

/* Subroutine */ int atabpt_()
{
doublereal debugg;
//doublereal debugg2;

    /* Format strings */
    static char fmt_4[] = "(\0020TABCYL INTERSECTION POINT NOT FOUND\002)";
    static char fmt_1005[] = "";
    static char fmt_1006[] = "";
    static char fmt_1007[] = "";
    static char fmt_100[] = "(\0020\0028e14.6)";
    static char fmt_13[] = "(\0020TABCYL INTERSECTION POINT FAILURE\002)";
    static char fmt_20[] = "(\0020MORE THAN 1 INTERSECTION POINT ON TABCY\
L\002)";
    static char fmt_42[] = "(\0020CHECK THIS CIRCLE IT MAY OR MAY NOT BE THE\
 DESIRED ONE\002)";
    static char fmt_300[] = "(\002 \0022f14.6)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();
    double sqrt(), d_sign(), atan();
    integer do_fio();

    /* Local variables */
    static doublereal c__;
#define d__ ((doublereal *)&avst_1 + 6201)
    static integer i__;
    static doublereal r__[22], r1, aa[22], ba;
#define id ((integer *)&avst_1 + 12402)
    static integer ii;
    static doublereal ra, er, xa, ya, xb, yb;
    static integer it;
    static doublereal xf, yf, xd;
    static integer nn, nt, iz;
    static doublereal ry, rad;
    static integer ine[6], ido;
    static doublereal dis;
    static integer ite, ihu, kit, inz, izt, luck;
    static doublereal temp;
    static integer ihut, lout, k000fx, ifall;
    extern /* Subroutine */ int slite_();
    static integer ilout;
    static doublereal roots[6];
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int aschtb_(), chkret_();
    static doublereal costha;
    static integer isense;
    static doublereal sintha;
    static integer icirpt, icount;
    extern /* Subroutine */ int slitet_(), atrnro_(), apolyr_();
    static integer introt;

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_13, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___53 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_100, 0 };


    /* Assigned format variables */
    static char *it_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */


/* .....CONSTRUCT A POINT AS THE INTERSECTION OF A LINE AND A */
/* .....TABULATED CYLINDER IN THE XY-PLANE */

/* ..   ADD PROVISIONS TO ENABLE PRTPRGRMR TO GET THE INTER OF A CIRCLE */
/* ..   AND A TABCYL POINT/INTOF,SYMCIR,SYMTAB,SYMPNT */
/* ..   IF ICRPT IS NOT EQUAL ZERO WE LOOK FOR CIRCLE/TABCYL INTER. */
/* ... */
/*               *          *          *          *          * */
/* *********************************************************************** */

/* .....SAVE CONDITION OF SENSE LIGHT 1 */
    isense = 0;
    slitet_(&c__1, &k000fx);
    switch ((int)k000fx) {
	case 1:  goto L160;
	case 2:  goto L161;
    }
L160:
    isense = 1;

/* .....SET UP FOR FIRST TRY */

L161:
    er = 0.;
    icount = 1;
    icirpt = 0;
    lout = 0;
    ilout = 0;
    a1com_1.jsuber = 0;

/* .....TEST TO DETERMINE IF TABPNT IS BEING USED AS A SUBROUTINE OF TABCI */

    if (id[OTHER_ENDIAN_S(1)] - 27 != 0) {
	goto L149;
    } else {
	goto L151;
    }

/* .....YES, SET UP UPPER AND LOWER BOUNDARIES FOR RE-TRY PROCEDURE */

L151:
    ihu = id[OTHER_ENDIAN_S(3)];
    ihut = ihu;
    ite = (id[OTHER_ENDIAN_S(17)] - 1) * 7 + 20;
    izt = 14;
    goto L51;

/* .....NO, SEARCH FOR THE ESTIMATED INTERVAL IN WHICH THE INTERSECTION IS */
/* .....EXPECTED.    IF FOUND, SET UP UPPER AND LOWER BOUNDARIES FOR */
/* .....RE-TRY PROCEDURE. */

L149:
    if (id[OTHER_ENDIAN_S(3)] == 3002) {
	goto L150;
    }
    icirpt = 1;
    ihu = 11;
    nt = (id[OTHER_ENDIAN_S(21)] - 1) * 7 + 25;
    goto L2333;
L150:
    ihu = 8;
    nt = (id[OTHER_ENDIAN_S(15)] - 1) * 7 + 22;
L2333:
//debugg=d__[nt-1];
debugg=id[OTHER_ENDIAN_S(15)];
//debugg2=d__[nt];
    aschtb_(&ihu, &d__[nt - 1], &d__[nt], &er);
//debugg=d__[nt-1];
//debugg2=d__[nt];
    if (er != 0.) {
	goto L3;
    } else {
	goto L1510;
    }
L1510:
    ihut = ihu;
    ite = nt - 3;
    izt = 18;
    if (icirpt != 0) {
	goto L1234;
    }
L400:
    rad = 0.;
    chkret_(&ihu, &rad, &introt, d__);
    if (introt <= 0) {
	goto L31;
    } else {
	goto L51;
    }
L1234:
    izt = 21;
    goto L51;
L1:
    a1com_1.jsuber = 1005;
    goto L29;

/* .....TRANSLATE AND ROTATE INTO THE COORDINATE SYSTEM OF THE TABCYL */
/* .....INTERVAL. */

L3:
    if (id[OTHER_ENDIAN_S(1)] - 27 != 0) {
	goto L5;
    } else {
	goto L1;
    }
L5:
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    e_wsfe();
    goto L1;
/* ..   THIS AREA COMPUTES ROTATION ANGLE OF INTERVAL AXIS TO BASIC AXIS. */
L1000:
    xa = d__[ihu + 6] - d__[ihu - 1];
    ya = d__[ihu + 7] - d__[ihu];
    d__1 = xa * xa + ya * ya;
    costha = sqrt(d__1);
    sintha = ya / costha;
    costha = xa / costha;
    if (abs(costha) - 1e-6 <= 0.) {
	goto L1001;
    } else {
	goto L1003;
    }
L1001:
    ra = -d_sign(&c_b23, &sintha);
L1002:
    switch ((int)it) {
	case 0: goto L1005;
	case 1: goto L1006;
	case 2: goto L1007;
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
L52:
    if (icirpt == 0) {
	goto L400;
    }
L51:
    iz = 1;
    it = 0;
    it_fmt = fmt_1005;
    goto L1000;
L1005:
    atrnro_(&xa, &ya, &xb, &yb, &ra, &iz);
    if (icirpt != 0) {
	goto L210;
    }

//debugg=d__[2];
//debugg=d__[ihu - 1];
//debugg=d__[3];
//debugg=d__[ihu];
//debugg=d__[5];

    dis = -(d__[2] * d__[ihu - 1] + d__[3] * d__[ihu] - d__[5]);
    atrnro_(&d__[2], &d__[3], &xf, &yf, &ra, &iz);
    if (abs(yf) - 1e-7 <= 0.) {
	goto L60;
    } else {
	goto L61;
    }
/* .....CASE WHERE TRANSFORMED LINE IS VERTICAL */
L60:
    xd = dis / xf;
    if (xd + 5e-7 <= 0.) {
	goto L17;
    } else {
	goto L18;
    }
L18:
    d__1 = xd - xb;
    if (abs(d__1) - 5e-7 <= 0.) {
	goto L27;
    } else {
	goto L697;
    }
L697:
    if ((xd + 5e-7) * (xb + 5e-7 - xd) >= 0.) {
	goto L27;
    } else {
	goto L17;
    }
L61:
    ba = -(xf / yf);
    yf = dis / yf;
    goto L7;

/* ..   CALCULATE COEFFICIENTS OF POLYNOMIAL FOR APOLYR--CIRCLE/TABCYL */

L210:
    xa = d__[2] - d__[ihu - 1];
    ya = d__[3] - d__[ihu];
    atrnro_(&xa, &ya, &xf, &yf, &ra, &iz);
    aa[6] = xf * xf + yf * yf - d__[8] * d__[8];
    c__ = -(d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu + 3];
    aa[0] = d__[ihu + 1] * d__[ihu + 1];
L1235:
    if (abs(aa[0]) - 1e-14 >= 0.) {
	goto L1237;
    } else {
	goto L1236;
    }
L1236:
    aa[0] = d_sign(&c_b41, aa);
L1237:
    if (icirpt == 0) {
	goto L1238;
    }
    aa[1] = d__[ihu + 1] * d__[ihu + 2] * 2.;
    aa[2] = d__[ihu + 1] * 2. * c__ + d__[ihu + 2] * d__[ihu + 2];
    aa[3] = d__[ihu + 2] * 2. * c__ - yf * 2. * d__[ihu + 1];
    aa[4] = c__ * c__ - yf * 2. * d__[ihu + 2] + 1.;
    aa[5] = (yf * c__ + xf) * -2.;
    ii = 6;
    goto L33;

/* .....CALCULATE COEFFICIENTS OF CUBIC EQUATION AND SOLVE FOR THE POINTS */
/* .....OF INTERSECTION OF THE GIVEN LINE AND THE SELECTED TABCYL SEGMENT. */

L7:
    aa[0] = d__[ihu + 1];
    goto L1235;
L1238:
    aa[1] = d__[ihu + 2];
    aa[3] = -yf;
/* L30: */
    aa[2] = -(d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu + 3] - ba;
    ii = 3;
L33:
    for (i__ = 1; i__ <= 22; ++i__) {
/* L6: */
	r__[i__ - 1] = 0.;
    }
    ifall = 0;
    nn = 7;
    apolyr_(aa, &ii, &nn, r__, &ifall);

/* .....TEST DEBUG FLAG */

    if (a1com_1.kdbug != 0) {
	goto L99;
    } else {
	goto L11;
    }
L99:
    io___41.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___41);
    do_fio(&c__1, (char *)&xa, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ya, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xb, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yb, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dis, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xd, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xf, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yf, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___42.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___42);
    do_fio(&c__1, (char *)&r__[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&r__[5], (ftnlen)sizeof(doublereal));
    e_wsfe();

/* .....WAS THERE AN ERROR IN SOLVING FOR THE INTERSECTIONS */

L11:
    if (ifall - 1 >= 0) {
	goto L12;
    } else {
	goto L10;
    }

/* .....YES, WRITE COMMENT AND GO OUT ERROR EXIT. */

L12:
    io___43.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___43);
    e_wsfe();
    goto L1;

/* .....NO, TEST WHETHER POINTS ARE IN THE TABCYL SEGMENT */

L10:
    kit = -1;
    ido = 3;
    if (icirpt != 0) {
	ido = 6;
    }
    luck = 0;
    i__1 = ido;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ine[i__ - 1] = 0;
	kit += 2;
	if (r__[kit] != 0.) {
	    goto L15;
	} else {
	    goto L14;
	}
L14:
	if (r__[kit - 1] * (xb + 1e-7 - r__[kit - 1]) >= 0.) {
	    goto L16;
	} else {
	    goto L15;
	}
L16:
	++luck;
	ine[i__ - 1] = kit;
	roots[luck - 1] = r__[kit - 1];
L15:
	;
    }
    if ((i__1 = luck - 1) < 0) {
	goto L17;
    } else if (i__1 == 0) {
	goto L24;
    } else {
	goto L111;
    }
/* ... MORE THAN ONE POINT IN INTERVAL, TEST FOR MORE THAN 2 POINTS */
L111:
    if (luck - 2 <= 0) {
	goto L112;
    } else {
	goto L19;
    }
/* ... TWO POINTS IN INTERVAL, TEST THEIR CLOSENESS */
L112:
    if ((d__1 = (roots[0] - roots[1]) / d__[ihu + 3], abs(d__1)) > 5e-6) {
	goto L19;
    }
/* ... ROOTS ARE CLOSE, TEST FURTHER FOR CIRCLE CASE */
    if (ido != 6) {
	goto L113;
    }
    if ((d__1 = (roots[0] - roots[1]) / d__[8], abs(d__1)) > 5e-6) {
	goto L19;
    }
/* ... TAKE AVERAGE OF ROOTS */
L113:
    r1 = (roots[0] + roots[1]) / 2.;
    goto L28;
/* ... MORE THAN 1 POINT IN INTERVAL, PRINT THEM OUT AND */
/* .....GO OUT THE ERROR EXIT. */

L19:
    io___50.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___50);
    e_wsfe();
    if (id[OTHER_ENDIAN_S(1)] - 27 != 0) {
	goto L40;
    } else {
	goto L41;
    }
L41:
    io___51.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___51);
    e_wsfe();
L40:
    iz = -1;
    kit = -1;
    it = 1;
    it_fmt = fmt_1006;
    goto L1000;
L1006:
    i__1 = ido;
    for (i__ = 1; i__ <= i__1; ++i__) {
	kit += 2;
	if (ine[i__ - 1] != 0) {
	    goto L299;
	} else {
	    goto L301;
	}
L299:
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
	io___53.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___53);
	do_fio(&c__1, (char *)&r1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ry, (ftnlen)sizeof(doublereal));
	e_wsfe();
L301:
	;
    }
    if (id[OTHER_ENDIAN_S(1)] - 27 != 0) {
	goto L1;
    } else {
	goto L29;
    }

/* ..   IF NO INTERSECTIONS FOUND IN INTERVAL USE THIS RETRY PROCEDURE---- */
/* ..   IF ATABPT IS USED AS A TABCIR SUBROUTINE CONSIDER ALL INTERVALS,-- */
/* ..   OTHERWISE CONSIDER ANOTHER INTERVAL UNTIL 3 INTERVALS ON EITHER */
/* ..   SIDE OF THE ESTIMATED INTERVAL HAVE BEEN TRIED-- A TOTAL OF SEVEN */
/* ..   INTERVALS CONSIDERED HERE. */
/* ..   (EXTENSION INTERVALS ARE INCLUDED IN BOTH CASES */

L17:
L31:
    if (id[OTHER_ENDIAN_S(1)] == 27) {
	goto L32;
    }
    if (icount - 7 <= 0) {
	goto L32;
    } else {
	goto L3;
    }
L32:
    if (icount % 2 != 0) {
	goto L200;
    } else {
	goto L201;
    }
L200:
    ihu = ihut + (icount + 1) / 2 * 7;
/* L203: */
    ++icount;
    if (ihu - ite >= 0) {
	goto L240;
    } else {
	goto L52;
    }
L201:
    ihu = ihut - icount / 2 * 7;
    ++icount;
    if (ihu - izt <= 0) {
	goto L250;
    } else {
	goto L52;
    }
L240:
    lout = 1;
    goto L17;
L250:
    ilout = 1;
    if (lout - ilout != 0) {
	goto L17;
    } else {
	goto L3;
    }

/* .....IF ONE INTERSECTION FOUND IN INTERVAL, SELECT IT */

L24:
    i__1 = ido;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ine[i__ - 1] != 0) {
	    goto L25;
	} else {
	    goto L26;
	}
L26:
	;
    }
L25:
    inz = ine[i__ - 1];
    r1 = r__[inz - 1];
    goto L28;

/* .....SIMPLE CASE, TRANSFORMED LINE IS VERTICAL */

L27:
    r1 = xd;

/* .....CALCULATE THE SECOND COORDINATE AND ROTATE AND TRANSLATE BACK */
/* .....TO THE ORIGINAL COORDINATE FRAME. */

L28:
/* Computing 3rd power */
    d__1 = r1;
/* Computing 2nd power */
    d__2 = r1;
    ry = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * d__2) 
	    - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] * 
	    r1);

/* .....IS TABPNT BEING USED AS A SUBROUTINE OF TABCIR */

    if (id[OTHER_ENDIAN_S(1)] - 27 != 0) {
	goto L36;
    } else {
	goto L152;
    }

/* .....YES */

L152:
    d__[0] = r1;
    d__[1] = ry;
    id[OTHER_ENDIAN_S(5)] = ihu;
    goto L29;

/* .....NO, PUT POINT COORDINATES IN DEFANS BLOCK */

L36:
    iz = -1;
    it = 2;
    it_fmt = fmt_1007;
    goto L1000;
L1007:
    atrnro_(&r1, &ry, &xa, &ya, &ra, &iz);
/* L1010: */
    defans[0] = d__[ihu - 1] + xa;
    defans[1] = d__[ihu] + ya;
    defans[2] = 0.;

/* .....TEST DEBUG FLAG */

/* L1167: */
    if (a1com_1.kdbug != 0) {
	goto L165;
    } else {
	goto L29;
    }
L165:
    io___55.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&r1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ry, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&defans[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xa, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ya, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&temp, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* .....RESTORE SENSE LIGHT 1 CONDITION */

L29:
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
} /* atabpt_ */

#undef defans
#undef deftab
#undef id
#undef d__


