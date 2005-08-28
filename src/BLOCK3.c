/* BLOCK3.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct a1com_1_ {
    doublereal name__, krfsys;
    real sum;
    integer jsuber, namsub;
    real debug;
    integer indxpt, loop, ifini;
};

#define a1com_1 (*(struct a1com_1_ *) &a1com_)

/* Initialized data */

struct {
    doublereal fill_1[5];
    integer e_2;
    } a1com_ = { {0}, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

