/* AZSURF.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal zsur[4];
} azurf_;

#define azurf_1 azurf_

struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__4 = 4;

/* Subroutine */ int azsurf_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_5 = { {'A', 'Z', 'S', 'U', 'R', 'F', ' ', ' '}, 0. };

#define a (*(doublereal *)&equiv_5)


    /* Local variables */
    static integer j, n;
    extern /* Subroutine */ int agtarg_();
#define idfsto ((integer *)&adfsto_1)
    extern /* Subroutine */ int adprnt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* **** THIS ROUTINE PROCESSES PTPP CLASS 16 DATA(ZSURF/----). IT CALLS */
/*     AGTSRF TO MOVE THE SURFACE FROM CANON TO THE ZSUR TABLE */

/*     MOVE THE SURFACE */
    agtarg_(azurf_1.zsur, &c__4, &n);
/*     IS THE SURFACE DEFINED */
    if (n == 3) {
	goto L20;
    }

/*     THE SURFACE IS DEFINED. */
/*     IS THE DEFINITION REALLY A SURFACE */
    if (n != 2) {
	goto L10;
    }

/*     THE DEFINITION IS A SURFACE - CHECK FOR PLANE(SURFACE TYPE 3) */
    if (idfsto[OTHER_ENDIAN_S(0)] == 3) {
	goto L20;
    }

/*     THE SURFACE IS NOT A PLANE */
L10:
    a1com_1.jsuber = 26;
    for (j = 1; j <= 4; ++j) {
/* L15: */
	azurf_1.zsur[j - 1] = (float)0.;
    }
    goto L20;

/*     IS DEBUG ON */
L20:
    if (a1com_1.kdbug == 0) {
	return 0;
    }
    adebug_1.idebug[0] = 12;
    adprnt_(&a);
    return 0;
} /* azsurf_ */

#undef idfsto
#undef a


