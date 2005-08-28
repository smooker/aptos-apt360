/* ASTYPE.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

integer astype_(indxpt)
integer *indxpt;
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer ij, jk;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
    extern integer amdtoa_(), aextra_();

/* **** THIS IS A FUNCTION SUBROUTINE WHICH EXAMINES THE PTPP ENTRY FOR A */
/*     SURFACE TYPE. IF ONE EXISTS IT ISPLACED IN THE CALLING VARIABLE */
/*     LOCATION.  THE INPUT IS THE PTPP AND THE CALLING SEQUENCE. */
/*     I=ASTYPE(INDXPT) */
/*     IF NO SURFACE TYPE EXISTS I IS SET TO ZERO. */
/*     GET HIGH ORDER 4 BYTES OF PTPP(INDXPT). */
    ij = amdtoa_(&ptpp[*indxpt - 1], &a0con_1.k4);
    if (ij == a0con_1.k5) {
	goto L10;
    }
    if (ij == a0con_1.k4) {
	goto L20;
    }
/*     PTPP DOES NOT CONTAIN EXPECTED SURFACE TYPE. */
    ret_val = a0con_1.k0;
    return ret_val;
/*  10 EXPECTED SURFACE TYPE IS IN 4 HIGH ORDER BYTES OF PTPP(INDXPT+1) */
L10:
    ret_val = amdtoa_(&ptpp[*indxpt], &a0con_1.k4);
    return ret_val;
/*  20 GET 4 LOW ORDER BYTES OF PTPP(INDXPT) */
L20:
    jk = aextra_(&ptpp[*indxpt - 1], &a0con_1.k4);
    if (jk < a0con_1.k2) {
	goto L10;
    }
/*     EXPECTED SURFACE TYPE IN 4 LOW ORDER BYTES OF PTPP(INDXPT+2) */
    ret_val = aextra_(&ptpp[*indxpt + 1], &a0con_1.k4);
    return ret_val;
} /* astype_ */

#undef canon
#undef ptpp


