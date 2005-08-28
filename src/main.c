/* main.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include <stdio.h>

/* Common Block Declarations */

struct {
    real protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2, 
	    tapes3, tapes4;
    integer intape, ioutap;
    real puntap;
} ataptb_;

#define ataptb_1 ataptb_



/*    for f2c */
/* Main program */ MAIN__()
//(c main() is in f2c lib)
{
    extern /* Subroutine */ int acntrl_();
/* L10: */
	acntrl_();
	return 0;
} /* MAIN__ */

