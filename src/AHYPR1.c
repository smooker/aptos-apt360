/* AHYPR1.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int ahypr1_()
{
    extern /* Subroutine */ int aelp01_();


/* ...  H = HYPERB/CENTER, SYM. PT. AT CENTER, LENGTH SEMI-MAJOR, $ */
/* ...             LENGTH SEMI-MINOR, ANGLE OF MAJOR AXIS WITH X-AXIS $$ */


/*     SET HYPERBOLA FLAG */
    a1com_1.jsuber = a0con_1.k1;
    aelp01_();
    return 0;
} /* ahypr1_ */

