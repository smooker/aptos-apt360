/* ATFMQD.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__4 = 4;

/* Subroutine */ int atfmqd_()
{
    static integer j;
    extern /* Subroutine */ int amatm_(), ainvrt_(), atrpos_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
    atmaty_1.xmat1[0] = adfsto_1.defsto[3];
    atmaty_1.xmat1[1] = adfsto_1.defsto[9];
    atmaty_1.xmat1[2] = adfsto_1.defsto[8];
    atmaty_1.xmat1[3] = adfsto_1.defsto[10];
    atmaty_1.xmat1[4] = adfsto_1.defsto[9];
    atmaty_1.xmat1[5] = adfsto_1.defsto[4];
    atmaty_1.xmat1[6] = adfsto_1.defsto[7];
    atmaty_1.xmat1[7] = adfsto_1.defsto[11];
    atmaty_1.xmat1[8] = adfsto_1.defsto[8];
    atmaty_1.xmat1[9] = adfsto_1.defsto[7];
    atmaty_1.xmat1[10] = adfsto_1.defsto[5];
    atmaty_1.xmat1[11] = adfsto_1.defsto[12];
    atmaty_1.xmat1[12] = adfsto_1.defsto[10];
    atmaty_1.xmat1[13] = adfsto_1.defsto[11];
    atmaty_1.xmat1[14] = adfsto_1.defsto[12];
    atmaty_1.xmat1[15] = adfsto_1.defsto[6];
    ainvrt_();
    atmaty_1.xmat2[12] = (float)0.;
    atmaty_1.xmat2[13] = (float)0.;
    atmaty_1.xmat2[14] = (float)0.;
    atmaty_1.xmat2[15] = (float)1.;
    amatm_(&c__4);
    atrpos_(&c__4);
    for (j = 1; j <= 16; ++j) {
/* L10: */
	atmaty_1.xmat2[j - 1] = atmaty_1.xmat3[j - 1];
    }
    amatm_(&c__4);
    adfsto_1.defsto[3] = atmaty_1.xmat3[0];
    adfsto_1.defsto[4] = atmaty_1.xmat3[5];
    adfsto_1.defsto[5] = atmaty_1.xmat3[10];
    adfsto_1.defsto[6] = atmaty_1.xmat3[15];
    adfsto_1.defsto[7] = atmaty_1.xmat3[6];
    adfsto_1.defsto[8] = atmaty_1.xmat3[2];
    adfsto_1.defsto[9] = atmaty_1.xmat3[1];
    adfsto_1.defsto[10] = atmaty_1.xmat3[3];
    adfsto_1.defsto[11] = atmaty_1.xmat3[7];
    adfsto_1.defsto[12] = atmaty_1.xmat3[11];
    atmaty_1.xmat2[12] = (float)0.;
    atmaty_1.xmat2[13] = (float)0.;
    atmaty_1.xmat2[14] = (float)0.;
    atmaty_1.xmat2[15] = (float)1.;
    return 0;
} /* atfmqd_ */

