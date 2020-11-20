/* APAREN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    integer ilpcnt, irpcnt, lstnst;
} apartb_;

#define apartb_1 apartb_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

/* Subroutine */ int aparen_()
{
    /* System generated locals */
    integer i__1;
    static shortint equiv_2[1];

    /* Local variables */
    static integer j, jk, indx2;
#define lment ((integer *)&ailmtb_1)
#define itype (equiv_2)
    static integer indxy;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
#define itype1 ((logical1 *)equiv_2)
    static integer nstopn;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*     PAREN ANALYZES AND EXTRACTS NESTING INFORMATION FROM STATEMENT */
/*     BETWEEN THE ARGUMENTS SUPPLIED */

/*     INITIALIZE */
    apartb_.lstnst = 0;
    *itype = 0;
    nstopn = 0;
    apartb_.ilpcnt = 0;
    apartb_.irpcnt = 0;
    indxy = aprtab_.istarp;
    j = (aprtab_.istarp << 2) - 3;

    i__1 = aprtab_.iendp;
    for (jk = aprtab_.istarp; jk <= i__1; ++jk) {
	itype1[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(j + 2)];
	if (*itype != 4) {
	    goto L90;
	}
	itype1[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(j + 1)];
	if (*itype == 7) {
	    goto L50;
	}
	if (*itype != 6) {
	    goto L90;
	}

/* ...     LEFT PARENTHESIS FOUND - COMPUTE INDEX TO TWO 4-BYTE */
/* ...     ELMENT ENTRIES */
	indx2 = (indxy << 1) - 1;
/* ...     PUT INDEX TO PRECEDING NEST INTO LAST 4 BYTES OF ELMENT ENTRY */
	lment[OTHER_ENDIAN_S(indx2)] = apartb_.lstnst;
/* ...     SAVE INDEX TO THIS LATEST NEST */
	apartb_.lstnst = indxy;
/* ...     RESET OPEN NEST POINTER TO THIS NEST */
	nstopn = indxy;
/* ...     INCREMENT LEFT PARENTHESIS COUNTER */
	++apartb_.ilpcnt;
	goto L90;

/* ...     RIGHT PARENTHESIS FOUND - INCREMENT ITS COUNTER */
L50:
	++apartb_.irpcnt;
/* ...     DO WE HAVE AN OPEN NEST */
	if (nstopn == 0) {
	    goto L90;
	}
/* ...     YES - PUT POINTER TO THIS RIGHT PAREN INTO ELMENT ENTRY */
/* ...     FOR START OF THIS NEST */
	indx2 = (nstopn << 1) - 1;
	lment[OTHER_ENDIAN_S(indx2 - 1)] = indxy;

/* ...     RESET OPEN NEST INDEX TO PREVIOUS NEST, IF THERE WAS ONE */
L70:
	nstopn = lment[OTHER_ENDIAN_S(indx2)];
/* ...     IF OPEN NEST INDEX IS ZERO, ALL NESTS SO FAR HAVE BEEN */
/* ...     CLOSED - GO TO CONTINUE SEARCH FOR NESTS */
	if (nstopn == 0) {
	    goto L90;
	}

/* ...     ALL NESTS NOT YET CHECKED FOR CLOSURE - CHECK THIS ONE */
	indx2 = (nstopn << 1) - 1;
	if (lment[OTHER_ENDIAN_S(indx2 - 1)] != 0) {
	    goto L70;
	}
/* ...     OPEN NEST INDEX PROPERLY RESET */

L90:
	++indxy;
/* L100: */
	j += 4;
    }

    return 0;
} /* aparen_ */

#undef itype1
#undef lclas1
#undef itype
#undef lment


