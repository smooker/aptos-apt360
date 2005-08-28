/* AHELPR.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

/* Subroutine */ int ahelpr_(inill)
integer *inill;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, ip, kp, jp;
    extern /* Subroutine */ int avs1ck_(), adfpro_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/*     THIS ROUTINE REMOVES IMPLICIT NESTED PLANE DEFINITIONS FROM THE */
/*     ZSURF AND PSIS STATEMENTS */


/* ...     BRANCH ON TYPE OF FIRST ENTRY FOLLOWING SLASH */
    if (ailmtb_1.iclass[*inill + 1] == 6) {
	goto L2605;
    }
    if (ailmtb_1.iclass[*inill + 1] == 3) {
	goto L2602;
    }
    if (ailmtb_1.iclass[*inill + 1] == 1) {
	goto L2601;
    }
    if (ailmtb_1.iclass[*inill + 1] == 5) {
	goto L2602;
    }
    a1com_1.jsuber = 576;
    goto L2605;
/* ...  VARIABLE SYMBOL - MAY BE SURFACE NAME OR SCALAR */
L2601:
    a1com_1.name__ = ailmtb_1.elment[*inill + 1];
    avs1ck_(&j);
    if (j == 5) {
	goto L2602;
    }
    if (j != 8) {
	goto L2605;
    }
/* ...  SCALAR - MUST BE IMPLICIT PLANE DEFINITION */
L2602:
    aprtab_1.nmove = ailmtb_1.jlment - *inill;
/* ...  SETUP PSUEDO NESTED DEFN. */
    i__1 = aprtab_1.nmove;
    for (ip = 1; ip <= i__1; ++ip) {
	kp = ailmtb_1.jlment + 2 + ip;
	jp = *inill + ip;
	ailmtb_1.elment[kp - 1] = ailmtb_1.elment[jp - 1];
/* L2603: */
	ailmtb_1.iclass[kp - 1] = ailmtb_1.iclass[jp - 1];
    }
    aprtab_1.istarp = ailmtb_1.jlment + 2;
    aprtab_1.iendp = ailmtb_1.jlment + 3 + aprtab_1.nmove;
    ailmtb_1.elment[ailmtb_1.jlment + 1] = adata1_1.plent;
    ailmtb_1.iclass[ailmtb_1.jlment + 1] = adata1_1.llass;
    ailmtb_1.iclass[aprtab_1.iendp - 1] = adata1_1.japth;
/* ...  PROCESS NESTED DEFN. */
    adfpro_();
/* ...  ADJUST ELMENT TABLE POINTERS FOR NESTED DEFN. */
    ailmtb_1.elment[*inill + 1] = ailmtb_1.elment[ailmtb_1.jlment];
    ailmtb_1.iclass[*inill + 1] = 6;
    ailmtb_1.jlment = *inill + 2;
    aprtab_1.istarp = *inill;
    aprtab_1.iendp = ailmtb_1.jlment;
L2605:
    return 0;
} /* ahelpr_ */

