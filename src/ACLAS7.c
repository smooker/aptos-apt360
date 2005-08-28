/* ACLAS7.f -- translated by f2c (version 20000121).
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
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Subroutine */ int aclas7_()
{
    extern doublereal afull8_();
    extern /* Subroutine */ int aptput_();

    aptpp_1.inptp = a0con_1.k5;
    aptpp_1.jmode = a0con_1.k5;
    aptpp_1.pt[0] = afull8_(&a0con_1.k7, &aklas7_1.iisn);
    aptpp_1.pt[1] = afull8_(&aklas7_1.idvst, &aklas7_1.kfk);
    aptpp_1.pt[2] = aklas7_1.ppseq1;
    aptpp_1.pt[3] = aklas7_1.ppseq2;
    aptpp_1.pt[4] = aklas7_1.idis;
    aptput_();
    return 0;
} /* aclas7_ */

