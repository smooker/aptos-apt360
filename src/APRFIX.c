/* APRFIX.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

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
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

/* Subroutine */ int aprfix_(iop, iret)
integer *iop, *iret;
{
    /* Local variables */
    static integer inh, inl;
#define ivst ((integer *)&avst_1)


/* ...  IOP=1, SET 4 BYTE INTEGER COMBINATION OF VST(NAMSUB+1) TO (-,-) */
/*            TO REPRESENT A DIMENSIONED SCALAR VARIABLE */
/* ...  IOP=2, SET 4 BYTE INTEGER COMBINATION OF VST(NAMSUB+1) TO (-,+) */
/*            TO REPRESENT A DIMENSIONED SURFACE VARIABLE */
/* ...  IOP=3, SET IRET=1, IF VST(NAMSUB+1) REPRESENTS DIM. SCALAR VAR. */
/*            SET IRET=2, IF VST(NAMSUB+1) REPRESENTS DIM. SURFACE VAR. */
/*            SET IRET=0, IF NEITHER CASE APPLIES */


    inl = a0con_1.k2 * (a1com_1.namsub + 1);
    inh = inl - a0con_1.k1;
    switch ((int)*iop) {
	case 1:  goto L20;
	case 2:  goto L10;
	case 3:  goto L30;
    }
L10:
    ivst[OTHER_ENDIAN_S(inl - 1)] = -ivst[OTHER_ENDIAN_S(inl - 1)];
    ivst[OTHER_ENDIAN_S(inh - 1)] = -ivst[OTHER_ENDIAN_S(inh - 1)];
    return 0;
L20:
    ivst[OTHER_ENDIAN_S(inh - 1)] = -ivst[OTHER_ENDIAN_S(inh - 1)];
    return 0;
L30:
    if (ivst[OTHER_ENDIAN_S(inh - 1)] >= 0) {
	goto L40;
    } else {
	goto L50;
    }
L40:
    *iret = 0;
    return 0;
L50:
    *iret = a0con_1.k1;
    if (ivst[OTHER_ENDIAN_S(inl - 1)] <= 0) {
	goto L60;
    } else {
	goto L70;
    }
L60:
    return 0;
L70:
    *iret = a0con_1.k2;
    return 0;
} /* aprfix_ */

#undef ivst


