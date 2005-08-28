/* IDEFTB.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Table of constant values */

static integer c__4 = 4;

integer ideftb_(i__)
integer *i__;
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define deftab ((doublereal *)&avst_1 + 6200)
    extern integer aextra_();

    ret_val = aextra_(&deftab[*i__ - 1], &c__4);
    return ret_val;
} /* ideftb_ */

#undef deftab


