/* AINVRT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

/* Table of constant values */

static doublereal c_b8 = .66666666666666663;

/* Subroutine */ int ainvrt_()
{
    /* Format strings */
    static char fmt_100[] = "(\0020\002,\002** WARNING - ATTEMPTING TO APPLY\
 MATRIX WITH ZERO SCALE FACTOR - IMPROPER RESULTS **\002)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(), sqrt();
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    static integer j, k;
    static doublereal det;

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, fmt_100, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
    atmaty_1.xmat2[0] = atmaty_1.tmatx[0];
    atmaty_1.xmat2[1] = atmaty_1.tmatx[4];
    atmaty_1.xmat2[2] = atmaty_1.tmatx[8];
    atmaty_1.xmat2[4] = atmaty_1.tmatx[1];
    atmaty_1.xmat2[5] = atmaty_1.tmatx[5];
    atmaty_1.xmat2[6] = atmaty_1.tmatx[9];
    atmaty_1.xmat2[8] = atmaty_1.tmatx[2];
    atmaty_1.xmat2[9] = atmaty_1.tmatx[6];
    atmaty_1.xmat2[10] = atmaty_1.tmatx[10];
/* L10: */
    k = a0con_1.k0;
/* L11: */
    for (j = a0con_1.k4; j <= 12; j += 4) {
/* L12: */
	k += a0con_1.k1;
/* L13: */
	atmaty_1.xmat2[j - 1] = -(atmaty_1.tmatx[k - 1] * atmaty_1.tmatx[3] + 
		atmaty_1.tmatx[k + 3] * atmaty_1.tmatx[7] + atmaty_1.tmatx[k 
		+ 7] * atmaty_1.tmatx[11]);
    }
    det = atmaty_1.tmatx[0] * (atmaty_1.tmatx[5] * atmaty_1.tmatx[10] - 
	    atmaty_1.tmatx[9] * atmaty_1.tmatx[6]) - atmaty_1.tmatx[1] * (
	    atmaty_1.tmatx[4] * atmaty_1.tmatx[10] - atmaty_1.tmatx[6] * 
	    atmaty_1.tmatx[8]) + atmaty_1.tmatx[2] * (atmaty_1.tmatx[4] * 
	    atmaty_1.tmatx[9] - atmaty_1.tmatx[5] * atmaty_1.tmatx[8]);
    det = abs(det);
    if ((d__1 = det - 1., abs(d__1)) <= 1e-9) {
	goto L16;
    }
    if (det <= 1e-9) {
	goto L15;
    }
    det = pow_dd(&det, &c_b8);
    for (j = 1; j <= 12; ++j) {
/* L14: */
	atmaty_1.xmat2[j - 1] /= det;
    }
    det = sqrt(det);
    for (j = 4; j <= 12; j += 4) {
/* L144: */
	atmaty_1.xmat2[j - 1] /= det;
    }
    goto L16;
L15:
    io___4.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___4);
    e_wsfe();
L16:
    return 0;
} /* ainvrt_ */

