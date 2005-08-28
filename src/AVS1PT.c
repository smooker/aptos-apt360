/* AVS1PT.f -- translated by f2c (version 20000121).
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
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

/* Subroutine */ int avs1pt_(j)
integer *j;
{
    extern /* Subroutine */ int avs1ck_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
    avs1ck_(j);
    if (*j != a0con_1.k1) {
	goto L10;
    }
/*     SYMBOL UNDEFINED - IS THERE ROOM */
    if (amxtab_1.maxvs1 + amxtab_1.maxvs2 + 2 > amxtab_1.maxvst) {
	goto L10;
    }
/* ...     YES - ENTER NAME, SET NAMSUB */
    amxtab_1.maxvs1 += 2;
    avst_1.vst[amxtab_1.maxvs1 - 1] = a1com_1.name__;
    a1com_1.namsub = amxtab_1.maxvs1;
    return 0;
L10:
    if (*j == a0con_1.k7) {
	return 0;
    }
    *j += a0con_1.k1;
    return 0;
} /* avs1pt_ */

