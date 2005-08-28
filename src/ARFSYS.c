/* ARFSYS.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__16 = 16;

/* Subroutine */ int arfsys_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_12 = { {'A', 'R', 'E', 'F', 'S', 'Y', 'S', ' '}, 0. };

#define a (*(doublereal *)&equiv_12)


    /* Local variables */
    static integer i__, n, l1;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
#define iptpp ((integer *)&avst_1)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int agtarg_();
#define idfsto ((integer *)&adfsto_1)
    extern /* Subroutine */ int adprnt_();
    static integer kindxp;
    extern /* Subroutine */ int ainvrt_();
#define irfsys ((integer *)&a1com_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* **** THIS ROUTINE PROCESSES PTPP CLASS 4 DATA(REFSYS/SMAT 0R */
/*     REFSYS/NOMORE) */
/*     THE INPUT IS THE PTPP AND ITS INDEX, INDXPT, THE VARIABLE KRFSYS, */
/*     AND THE CANON TABLES. */

/*     GET VST INDEX OF MATRIX */
    kindxp = 2 * a1com_1.indxpt - 1;
    l1 = iptpp[OTHER_ENDIAN_S(kindxp + 2)];
/*     IS THIS REFSYS/NOMORE */
    if (iptpp[OTHER_ENDIAN_S(kindxp - 1)] != 0) {
	goto L5;
    }
/*     YES */
    a1com_1.refsys = (float)0.;
    goto L50;

/*     GET THE MATRIX */
L5:
    agtarg_(atmaty_1.tmatx, &c__16, &n);
/* ...     TEST FOR SURFACE */
    if (n == 2) {
	goto L6;
    }
/* ...     NO - SEE IF AN ERROR HAS ALREADY BEEN DIAGNOSED */
    if (n - 7 != 0) {
	goto L8;
    } else {
	goto L70;
    }
/*     THE SYMBOL IS DEFINED, GET TYPE. */
/*     IS THE SYMBOL A MATRIX */
L6:
    if (idfsto[OTHER_ENDIAN_S(0)] == 12) {
	goto L10;
    }

/*     THE SYMBOL IS NOT A MATRIX */
L8:
    a1com_1.jsuber = 651;
    goto L50;

/*  10 THE SYMBOL IS A MATRIX. INVERT THE MATRIX. SET KRFSYS. */
L10:
    irfsys[OTHER_ENDIAN_S(0)] = l1;
    irfsys[OTHER_ENDIAN_S(1)] = a1com_1.namsub;
    ainvrt_();
    for (i__ = 1; i__ <= 16; ++i__) {
/* L20: */
	atmaty_1.xmat4[i__ - 1] = atmaty_1.xmat2[i__ - 1];
    }
/* L30: */
    goto L50;

/*  50 IS DEBUG FLAG ON */
L50:
    if (a1com_1.kdbug != 0) {
	goto L60;
    } else {
	goto L70;
    }
/*     DEBUG FLAG IS ON. */
L60:
    adebug_1.idebug[0] = 1;
/*     PRINT MATRIX AREAS */
    adprnt_(&a);

L70:
    return 0;
} /* arfsys_ */

#undef irfsys
#undef idfsto
#undef defans
#undef iptpp
#undef canon
#undef ptpp
#undef a


