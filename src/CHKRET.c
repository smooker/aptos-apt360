/* CHKRET.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int chkret_(ihu, rad, intrct, d__)
integer *ihu;
doublereal *rad;
integer *intrct;
doublereal *d__;
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal px[6], py[6], bo1, bo2, bo3, bo4, bo5, bo6, bo7, bo8, 
	    sl1x, sl1y, sl2y, sl2x, delx, dely, bplin, value, toler;
    static integer minus, iplus;
    static doublereal x1plin, y1plin, xpline, ypline, slplin;
    static integer ivertl;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 3, MODIFICATION 0 *** */

/*     THIS SUBROUTINE IS A TABCYL INTERVAL SCREENING TECHNIQUE THAT */
/*     CONSTRUCTS A RECTANGLE AROUND THE INTERVAL BEING CONSIDERED. */
/*     FOR TABPNT THE SECOND ARGUMENT (RAD) IS ZERO,FOR TABCIR, IT IS SET */
/*     EQUAL TO THE RADIUS OF THE CIRCLE. */

    /* Parameter adjustments */
    --d__;

    /* Function Body */
    toler = (float)1e-6;
    ivertl = 0;
    minus = 0;
    iplus = 0;
/* L400: */
    dely = d__[*ihu + 8] - d__[*ihu + 1];
    delx = d__[*ihu + 7] - d__[*ihu];
    sl1y = dely / d__[*ihu + 4];
    sl1x = delx / d__[*ihu + 4];
    sl2y = sl1x;
    sl2x = -sl1y;
    bo1 = (*rad + toler) * sl1x;
    bo2 = (*rad + toler) * sl1y;
    bo3 = (d__1 = d__[*ihu + 5], abs(d__1)) + *rad + toler;
    bo4 = bo3 * sl2x;
    bo5 = bo3 * sl2y;
    bo6 = (d__1 = d__[*ihu + 6], abs(d__1)) + *rad + toler;
    bo7 = bo6 * sl2x;
    bo8 = bo6 * sl2y;
    px[4] = d__[*ihu] - bo1;
    py[4] = d__[*ihu + 1] - bo2;
    px[0] = px[4] + bo4;
    py[0] = py[4] + bo5;
    px[3] = px[4] - bo7;
    py[3] = py[4] - bo8;
    px[5] = d__[*ihu + 7] + bo1;
    py[5] = d__[*ihu + 8] + bo2;
    px[1] = px[5] + bo4;
    py[1] = py[5] + bo5;
    px[2] = px[5] - bo7;
    py[2] = py[5] - bo8;
    xpline = d__[3] * d__[6];
    if (abs(d__[4]) - (float)1e-7 <= 0.) {
	goto L1;
    } else {
	goto L2;
    }
L1:
    ivertl = 1;
    goto L3;
L2:
    slplin = -d__[3] / d__[4];
    x1plin = d__[3] * d__[6];
    y1plin = d__[4] * d__[6];
    bplin = y1plin - slplin * x1plin;
L3:
    for (i__ = 1; i__ <= 4; ++i__) {
	if (ivertl <= 0) {
	    goto L5;
	} else {
	    goto L6;
	}
L5:
	ypline = slplin * px[i__ - 1] + bplin;
	value = py[i__ - 1] - ypline;
	goto L4;
L6:
	value = px[i__ - 1] - xpline;
L4:
	if (value < 0.) {
	    goto L11;
	} else if (value == 0) {
	    goto L12;
	} else {
	    goto L13;
	}
L11:
	minus = 1;
	goto L10;
L13:
	iplus = 1;
L10:
	;
    }
/* L14: */
    if (minus - iplus != 0) {
	goto L15;
    } else {
	goto L12;
    }

/*     THE APPROPRIATE LINE, THAT IS, THE ACTUAL LINE FOR TABPNT OR THE */
/*     RADIUS PARALLEL LINE FOR TABCIR DOES NOT INTERSECT THE RECTANGLE */
/*     THUS THIS INTERVAL IS ELIMINATED FROM FURTHER CONSIDERATION. */

L15:
    *intrct = 0;
    goto L16;

/*     THE APPROPRIATE LINE DOES INTERSECT THE RECTANGLE SO THIS INTERVAL */
/*     MUST BE EXAMINED FURTHER */

L12:
    *intrct = 1;
L16:
    return 0;
} /* chkret_ */

