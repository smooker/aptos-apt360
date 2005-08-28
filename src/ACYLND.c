/* ACYLND.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int acylnd_(n)
integer *n;
{
    /* Local variables */
    static integer k;
    static doublereal sam[7];
    static integer inp, inv;
    extern /* Subroutine */ int anorm_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*               *          *          *          *         * */
/* *********************************************************************** */
    switch ((int)*n) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }

/* ...  CYL = CYLNDR/POINT,I,J,K,R */
L10:
    inp = 3;
L15:
    inv = 6;
    goto L100;

/* ...  CYL = CYLNDR/POINT,VECTOR,R */
L20:
    inp = 3;
    inv = 7;
    goto L100;

/* ...  CYL = CYLNDR/X,Y,Z,VECTOR,R */
L30:
    inp = 2;
    goto L15;

/* ...  CYL = CYLNDR/X,Y,Z,I,J,K,R */
L40:
    inp = 2;
    inv = 5;

L100:
    for (k = 1; k <= 3; ++k) {
	defans[k - 1] = deftab[inp - 1];
/* L150: */
	++inp;
    }
    for (k = 4; k <= 7; ++k) {
	defans[k - 1] = deftab[inv - 1];
	sam[k - 4] = defans[k - 1];
/* L170: */
	++inv;
    }
/* L240: */
    azvect_(sam);
    anorm_(sam, &defans[3]);
    return 0;
} /* acylnd_ */

#undef defans
#undef deftab


