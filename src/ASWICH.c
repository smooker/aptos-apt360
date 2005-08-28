/* ASWICH.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

/* Subroutine */ int aswich_(it)
integer *it;
{
    /* System generated locals */
    static doublereal equiv_1[1];

    /* Local variables */
#define i__ ((integer *)equiv_1 + OTHER_ENDIAN_S(0))
#define j ((integer *)equiv_1 + OTHER_ENDIAN_S(1))
#define ipt ((integer *)&aptpp_1)
#define temp (equiv_1)
#define itemp ((integer *)equiv_1)
    static integer jtemp1;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ...     IF DATA TO BE PACKED IN ENTRY IS ZERO, JUST EXIT */
    if (*it == 0) {
	goto L200;
    }
/* ...     PICK UP PTPP ENTRY TYPE CODES */
    *temp = aptpp_1.pt[amotcm_1.now - 1];
    jtemp1 = (amotcm_1.now << 1) - 1;
/* ...     BRANCH ON ENTRY TYPE CODE TO APPROPRIATE TESTS */
    if (*i__ >= 6) {
	goto L200;
    }
    switch ((int)*i__) {
	case 1:  goto L200;
	case 2:  goto L50;
	case 3:  goto L200;
	case 4:  goto L75;
	case 5:  goto L80;
    }

/* ...     CHANGE SCALAR TYPE CODE TO SURFACE, SINCE A SURFACE TYPE IS */
/* ...     BEING PACKED */
L50:
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 4;
/* ...     TEST FOR VARIABLE SYMBOL OR EXPRESSION AS SUBSCRIPT */
L75:
    if (*j == 2) {
	goto L90;
    }
    if (*j == 3) {
	goto L90;
    }
L80:
    ipt[OTHER_ENDIAN_S(jtemp1 + 1)] = *it;
    return 0;
L90:
    ipt[OTHER_ENDIAN_S(jtemp1 + 3)] = 0;
    ipt[OTHER_ENDIAN_S(jtemp1 + 4)] = *it;
    ++aptpp_1.inptp;
L200:
    return 0;
} /* aswich_ */

#undef itemp
#undef temp
#undef ipt
#undef j
#undef i__


