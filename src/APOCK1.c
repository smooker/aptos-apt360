/* APOCK1.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

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
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int apock1_()
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, iscal, nscal, nsurf, icomma;
    extern /* Subroutine */ int aswich_();
    static integer islash=0x304;
    extern /* Subroutine */ int aptlod_(), aptput_();
#define ipt ((integer *)&aptpp_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*       INTEGER ISLASH/Z00000304/,ICOMMA/Z00000904/ */

/* ...     MAKE SURE AT THIS POINT THAT THERE IS AT LEAST ONE PARAMETER */
/* ...     FOLLOWING SLASH - NOT ENOUGH IF ONLY ONE, BUT FURTHER TESTS */
/* ...     MADE LATER */
	icomma=0x904;
    if (aprtab_1.istarp + 1 < ailmtb_1.jlment) {
	goto L100;
    }
/* ...     TEST FOR SLASH */
L100:
    if (ailmtb_1.iclass[aprtab_1.istarp] == islash) {
	goto L110;
    }
    a1com_1.jsuber = 155;
    goto L999;

/* ...     MOVE SCANNING INDEX PAST SLASH */
L110:
    aprtab_1.istarp += 2;

    aptpp_1.inptp = 4;
    aptpp_1.jmode = 5;
    ipt[OTHER_ENDIAN_S(4)] = 11000;
    ipt[OTHER_ENDIAN_S(5)] = 3;

/* ...     FIRST EIGHT ENTRIES ARE FLAGS DESCRIBING CHARACTERISTICS OF */
/* ...     POCKETING OPERATION TO BE DONE - MUST ALL BE SCALARS */
    for (j = 1; j <= 8; ++j) {
	aptlod_();
	if (amotcm_1.jptind == 2) {
	    goto L115;
	}
	if (amotcm_1.jptind != 3) {
	    goto L158;
	}
L115:
	if (aprtab_1.istarp >= ailmtb_1.jlment) {
	    goto L210;
	}
/* ...     TEST FOR COMMA FOLLOWING PARAMETER - IF NOT, ERROR */
	if (ailmtb_1.iclass[aprtab_1.istarp - 1] != icomma) {
	    goto L158;
	}
	++aprtab_1.istarp;
/* L120: */
    }

    aptpp_1.npt = 8;
    --aprtab_1.istarp;
/* ...     INITIALIZE SCALAR AND SURFACE COUNTERS */
    nscal = 0;
    nsurf = 0;
/* ...     SET FLAG FOR AUTOMATIC COMMA PICK-UP */
    aprtab_1.itsq = 4;

/* ...     TEST FOR END OF STATEMENT */
L140:
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L150;
    } else if (i__1 == 0) {
	goto L210;
    } else {
	goto L200;
    }
/* ...     NO - GET NEXT PARAMETER */
L150:
    aptlod_();
    ++aptpp_1.npt;
/* ...     TEST FOR SURFACE */
    if (amotcm_1.jptind != 4) {
	goto L155;
    }
/* ...     YES - PACK A TYPE CODE FOR A POINT IN PTPP ENTRY */
    aswich_(&c__1);
    goto L170;
/* ...     NOT A SURFACE - IF NOT SCALAR, ERROR */
L155:
    if (amotcm_1.jptind == 2) {
	goto L160;
    }
    if (amotcm_1.jptind == 3) {
	goto L160;
    }
/* ...     IF ERROR ALREADY DIAGNOSED IN APTLOD, JUST EXIT */
L158:
    if (amotcm_1.jptind == 8) {
	goto L999;
    }
    a1com_1.jsuber = 376;
    goto L999;
/* ...     PARAMETER IS A SCALAR */
L160:
    ++nscal;
    goto L180;
/* ...     PARAMETER IS A SURFACE */
L170:
    ++nsurf;
    if (nscal / 3 * 3 != nscal) {
	goto L210;
    }
L180:
    if (aptpp_1.inptp - 298 >= 0) {
	goto L210;
    } else {
	goto L140;
    }

/* ...     END OF STATEMENT REACHED - TEST FOR PROPER NO. OF PARAMETERS */
L200:
    iscal = nscal / 3;
    if (iscal * 3 != nscal) {
	goto L210;
    }
    if (nsurf + iscal < 3) {
	goto L210;
    }
    if (nsurf + iscal <= 21) {
	goto L220;
    }
L210:
    a1com_1.jsuber = 377;
    goto L999;

L220:
    ipt[OTHER_ENDIAN_S(0)] = 6;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    ipt[OTHER_ENDIAN_S(2)] = aptpp_1.npt;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    --aptpp_1.inptp;
    aptput_();

L999:
    return 0;

} /* apock1_ */

#undef ipt


