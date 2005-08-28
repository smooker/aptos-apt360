/* ADCLAR.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

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
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;

/* Subroutine */ int adclar_(ils, ilast)
integer *ils, *ilast;
{
    /* Format strings */
    static char fmt_65[] = "(\002 ILLEGAL ENTRY AT ELEMENT TABLE ENTRY NUM\
BER\002,i6)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer it;
    extern integer ibclas_(), amdtoa_(), aextra_(), iatype_();

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, fmt_65, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 1 *** */
    it = *ils + 2;
L10:
    if (iatype_(&it) != 4) {
	goto L40;
    }
/* ...  PUNCT. MUST BE UNARY PLUS OR MINUS, OR ALLOWABLE MULTIPLE COMMA */
    if (ailmtb_1.iclass[it - 1] == adata1_1.ic[1]) {
	goto L20;
    }
    if (ailmtb_1.iclass[it - 1] == adata1_1.ic[2]) {
	goto L20;
    }
    if (ailmtb_1.iclass[it - 1] != adata1_1.ic[5]) {
	goto L60;
    }
/* ...  FURTHER, MULTIPLE COMMAS ALLOWED ONLY FOR INDIRV AND INDIRP */
    i__1 = ibclas_(ils);
    if (aextra_(&i__1, &c__2) != 26) {
	goto L60;
    }
    i__1 = ibclas_(ils);
    if (amdtoa_(&i__1, &c__2) == 9) {
	goto L15;
    }
    i__1 = ibclas_(ils);
    if (amdtoa_(&i__1, &c__2) - 10 != 0) {
	goto L60;
    } else {
	goto L15;
    }
L20:
    ++it;
/* L30: */
    if (iatype_(&it) == 4) {
	goto L60;
    }
L40:
    if (it >= *ilast) {
	goto L70;
    }
    ++it;
/* ...  IS NEXT ENTRY PUNCTUATION */
    if (iatype_(&it) != 4) {
	goto L40;
    }
/* ...  YES  -  THEN  IT MUST BE A COMMA */
    if (ailmtb_1.iclass[it - 1] != adata1_1.ic[5]) {
	goto L60;
    }
/* ...  COMMA FOUND - CONTINUE VERIFYING STATEMENT */
L15:
    ++it;
    if (it <= *ilast) {
	goto L10;
    }
/* ...  A COMMA (SEPARATOR) IS EITHER MISSING OR INCORRECTLY USED */
L60:
    a1com_1.jsuber = 7;
    if (a1com_1.debug == 0) {
	return 0;
    }
    io___2.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___2);
    do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
    e_wsfe();
L70:
    return 0;
} /* adclar_ */

