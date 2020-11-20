/* ACANCK.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Subroutine */ int acanck_(it)
integer *it;
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__;
    static doublereal s;
    extern /* Subroutine */ int anorm_();
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int azvect_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ...  THIS ROUTINE CHECKS CANON DEFINITIONS FOR GEOMETRIC TYPES */
/*     LINE,PLANE,CIRCLE,CYLNDR, AND SPHERE. */
/* ...     ARGUMENT 'IT' IS THE GEOMETRIC SURFACE TYPE */


    if (*it <= 5) {
	goto L10;
    }
    if (*it - 13 != 0) {
	goto L90;
    } else {
	goto L50;
    }
L10:
    switch ((int)*it) {
	case 1:  goto L90;
	case 2:  goto L20;
	case 3:  goto L20;
	case 4:  goto L60;
	case 5:  goto L60;
    }

/*     LINE OR PLANE - NORMALIZE THE EQUATION */
L20:
/* Computing 2nd power */
    d__1 = defans[0];
/* Computing 2nd power */
    d__2 = defans[1];
/* Computing 2nd power */
    d__3 = defans[2];
    s = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    for (i__ = 1; i__ <= 3; ++i__) {
	defans[i__ - 1] /= s;
	if ((d__1 = defans[i__ - 1], abs(d__1)) - (float)1e-6 <= 0.) {
	    goto L30;
	} else {
	    goto L40;
	}
L30:
	defans[i__ - 1] = (float)0.;
L40:
	;
    }
    defans[3] /= s;

/*     CHECK FOR ZERO VECTOR - IF SO, JSUBER WILL BE SET */
    azvect_(defans);
    goto L90;

/*     SPHERE - SET UP TO CHECK RADIUS */
L50:
    defans[6] = defans[3];
    goto L70;

/*     CIRCLE OR CYLNDR - NORMALIZE AXIS VECTOR */
L60:
    anorm_(&defans[3], &defans[3]);

/*     CHECK FOR ZERO VECTOR - IF SO, JSUBER WILL BE SET */
    azvect_(&defans[3]);
/*     CHECK RADIUS */
L70:
    if (defans[6] > 0.) {
	goto L90;
    }

    a1com_1.jsuber = 1005;

L90:
    return 0;
} /* acanck_ */

#undef defans


