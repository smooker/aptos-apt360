/* AGENPL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int agenpl_(v1, v2, pt)
doublereal *v1, *v2, *pt;
{
    /* Local variables */
    static doublereal vn[3];
    extern /* Subroutine */ int adot_(), anorm_();
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int across_(), azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ...  THIS ROUTINE ESTABLISHES A PLANE DEFINITION IN THE NORMAL FORM, */
/*     AX + BY + CZ = D */
/* ...  FROM TWO NON-PARALLEL VECTORS AND A POINT ON THE PLANE */
/* ...  CALCULATE NORMAL TO PLANE BY CROSSING V1 AND V2 */
    /* Parameter adjustments */
    --pt;
    --v2;
    --v1;

    /* Function Body */
    across_(&v1[1], &v2[1], vn);
/* ...  CHECK FOR ZERO VECTOR - IF SO, JSUBER IS SET */
    azvect_(vn);
/* ...  NORMALIZE NORMAL - SAVE IN DEFANS */
    anorm_(vn, defans);
/* ...  CALCULATE D VALUE */
    adot_(defans, &pt[1], &defans[3]);
    return 0;
} /* agenpl_ */

#undef defans


