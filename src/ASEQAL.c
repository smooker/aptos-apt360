/* ASEQAL.f -- translated by f2c (version 20000121).
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
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__82 = 82;

/* Subroutine */ int aseqal_()
{
    /* Initialized data */
    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_1 = { 0, 9, 0. };


    /* Local variables */
#define ierr ((integer *)&equiv_1)
#define ptpp ((doublereal *)&avst_1)
    static integer n;
#define canon ((doublereal *)&avst_1)
    static integer i1, j1;
#define iptpp ((integer *)&avst_1)
    static integer it;
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int agtarg_();
#define errcod ((doublereal *)&equiv_1)
    extern /* Subroutine */ int agtsub_(), asclpt_();
#define idfsto ((integer *)&adfsto_1)
    static integer kindxp, kcp;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*     THIS ROUTINE PROCESSES PTPP CLASS 9 DATA(OBTAIN,SURFACE TYPE/S1,X, */
/*     Y,...) */
/*     THIS ROUTINE MAY SET JSUBER TO 152, 153, 154, OR 157 */

/*       INTEGER IERR(2)/0,9/ */

/*     GET SUBSCRIPT TYPE OF SCALAR VARIABLE BEING DEFINED */
    kindxp = 2 * a1com_1.indxpt - 1;
    a1com_1.namsub = iptpp[OTHER_ENDIAN_S(kindxp)];
    ++a1com_1.indxpt;
/*     GET VST INDEX OF SCALAR VARIABLE */
    i1 = iptpp[OTHER_ENDIAN_S(kindxp + 2)];
/*     GET SUBSCRIPT */
    agtsub_();
/*     CHECK FOR ERROR IN SUBSCRIPT DEFINITION. */
    if (a1com_1.jsuber != 0) {
	return 0;
    }
    j1 = a1com_1.namsub;

/*     GET SURFACE TYPE GIVEN IN OBTAIN STATEMENT */
    kindxp = (a1com_1.indxpt << 1) - 1;
    it = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
/* ...     TEST FOR A LARGE SURFACE - IF SO, ERROR AT PRESENT */
    if (it > 15) {
	goto L60;
    }
/*     GET RELATIVE INDEX OF PARAMETER WHICH DEFINES SCALAR VARIABLE */
    kcp = iptpp[OTHER_ENDIAN_S(kindxp)];
    ++a1com_1.indxpt;
/*     GET CANONICAL FORM OF REQUESTED SURFACE */
    agtarg_(defans, &c__82, &n);
/* ...     IF ERROR ALREADY DIAGNOSED IN AGTARG, GO TO SET UP ERROR */
/* ...     CODE FOR SYMBOL VST ENTRY */
    if (n == 7) {
	goto L70;
    }
/* ...     SEE IF S1 IS A SURFACE */
    if (n != 2) {
	goto L30;
    }
/*     S1 IS A SURFACE - DO SURFACE TYPES MATCH. */
/* L10: */
    if (idfsto[OTHER_ENDIAN_S(0)] != it) {
	goto L40;
    }
/*     THE SURFACE TYPE IS CORRECT */

/*     IS PARAMETER INDEX WITHIN CANONICAL FORM LENGTH */
    if (kcp > idfsto[OTHER_ENDIAN_S(1)]) {
	goto L50;
    }

/*     RESTORE VST INDEX AND SUBSCRIPT OF SCALAR BEING DEFINED */
L20:
    a1com_1.namsub = j1;
    a1com_1.name__ = i1;
/*     STORE THE SCALAR VARIABLE */
    asclpt_(&adfsto_1.defsto[kcp - 1]);
    return 0;

/*     VARIABLE DOES NOT DEFINE A SURFACE */
L30:
    a1com_1.jsuber = 152;
    goto L70;
/*     SURFACE TYPES DO NOT MATCH */
L40:
    a1com_1.jsuber = 153;
    goto L70;
/*     PARAMETERS EXCEED LENGTH OF CANONICAL FORM */
L50:
    a1com_1.jsuber = 154;
    goto L70;
/* ...     SURFACE IS A LARGE ONE */
L60:
    a1com_1.jsuber = 157;

/* ...     SET UP ERROR CODE TO MAKE ASCLPT FLAG VST ENTRY FOR SYMBOL */
/* ...     AS INCORRECTLY DEFINED */
L70:
    kcp = 1;
    adfsto_1.defsto[0] = *errcod;
    goto L20;
} /* aseqal_ */

#undef idfsto
#undef errcod
#undef defans
#undef iptpp
#undef canon
#undef ptpp
#undef ierr


