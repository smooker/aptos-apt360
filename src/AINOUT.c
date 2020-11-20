/* AINOUT.f -- translated by f2c (version 20000121).
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
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

/* Subroutine */ int ainout_()
{
    /* Initialized data */

    static integer islash = 772;

    /* System generated locals */
    integer i__1;
    static integer equiv_1[1];

    /* Local variables */
#define itemp (equiv_1)
    static integer inter;
    extern /* Subroutine */ int aptlod_(), aptput_();
#define ipt ((integer *)&aptpp_1)
#define izw ((shortint *)equiv_1 + OTHER_ENDIAN_S(0))

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*       INTEGER ISLASH/Z00000304/ */

    if (aprtab_1.istarp >= ailmtb_1.jlment - 1) {
	goto L129;
    }
    aptpp_1.jmode = 5;
    aptpp_1.inptp = 3;
    aptpp_1.npt = 0;
    ipt[OTHER_ENDIAN_S(0)] = 5;
    ipt[OTHER_ENDIAN_S(1)] = 0;
    aptpp_1.pt[1] = (float)0.;
    *itemp = ailmtb_1.iclass[aprtab_1.istarp - 1];
    if ((i__1 = *izw - 2) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L50;
    } else {
	goto L200;
    }

/* ...     TITLES */
L10:
    ++aprtab_1.istarp;
L15:
    aptlod_();
    ++aptpp_1.npt;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L15;
    }
    aptpp_1.npr = 3;
    goto L900;

/* ...     PUNCH/ */
L50:
    aptpp_1.npr = 2;
    if (ailmtb_1.iclass[aprtab_1.istarp] != islash){
	goto L155;
    }
    aprtab_1.istarp += 2;
/* L51: */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != 3) {
	goto L129;
    }
L55:
    aprtab_1.itsq = 4;
    if (ailmtb_1.elment[aprtab_1.istarp - 1] != (float)0.) {
	goto L90;
    }
/* ...     PUNCH/0 OR PRINT/0 */
/* L60: */
    if (aprtab_1.istarp < ailmtb_1.jlment) {
	a1com_1.jsuber = 129;
    }
    aptlod_();
    aptpp_1.npt = 1;
    goto L900;

/* ...     PUNCH/1-3 OR PRINT/1-3 */
L90:
    aptlod_();
    ++aptpp_1.npt;
/* ...     TEST FOR VOCABULARY WORD */
    if (amotcm_1.jptind == 0) {
	goto L500;
    }
/* ...     TEST FOR END OF LIST */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L100;
    }
/* ...     TEST FOR OVERFLOW OF PT BUFFER */
    if (aptpp_1.inptp - 298 >= 0) {
	goto L1000;
    } else {
	goto L90;
    }
L100:
    if (aptpp_1.npt <= 1) {
	goto L129;
    }
    goto L900;

/* ...     PRINT/ */
L200:
    aptpp_1.npr = 1;
    if (ailmtb_1.iclass[aprtab_1.istarp] != islash) {
	goto L155;
    }
    aprtab_1.istarp += 2;
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] == 3) {
	goto L55;
    }
/* ...     PRINT/ON OR /OFF */
    inter = 4;
    aptlod_();
    if (amotcm_1.jptind != 0) {
	goto L129;
    }
    if (amotcm_1.kreslt == 71) {
	inter = 3;
    }
    ipt[OTHER_ENDIAN_S(0)] = 8;
    ipt[OTHER_ENDIAN_S(1)] = inter;
    aptpp_1.inptp = 2;
    goto L990;

/* ...     PUNCH OR PRINT/1-3,ALL */
L500:
    if (aptpp_1.npt != 2) {
	goto L129;
    }
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L129;
    }
    if (amotcm_1.kreslt != 51) {
	goto L132;
    }

/* ...     OUTPUT PTPP 5 RECORD */
L900:
    if (aptpp_1.jmode == 5) {
	goto L910;
    }
    aptpp_1.jmode = 3;
    goto L990;
L910:
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    ipt[OTHER_ENDIAN_S(2)] = aptpp_1.npt;
    ipt[OTHER_ENDIAN_S(3)] = aptpp_1.npr;
L990:
    --aptpp_1.inptp;
    aptput_();
L999:
    return 0;

/* ...     PT BUFFER OVERFLOW */
L1000:
    if (aptpp_1.jmode != 2) {
	aptpp_1.jmode = 1;
    }
    --aptpp_1.inptp;
    aptput_();
    aptpp_1.jmode = 2;
    aptpp_1.inptp = 1;
    goto L90;

/* ...     MISSING SLASH */
L155:
    a1com_1.jsuber = 155;
    goto L999;
/* ..      ERROR */
L129:
    a1com_1.jsuber = 129;
    goto L999;
L132:
    a1com_1.jsuber = 132;
    goto L999;
} /* ainout_ */

#undef izw
#undef ipt
#undef itemp


