/* AMON8.f -- translated by f2c (version 20000121).
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
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    integer ilpcnt, irpcnt, lstnst;
} apartb_;

#define apartb_1 apartb_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Table of constant values */

static integer c__5 = 5;
static integer c__1 = 1;

/* Subroutine */ int amon8_()
{
    /* System generated locals */
    static integer equiv_4[2];

    /* Local variables */
    static integer iloc, indx2;
    extern /* Subroutine */ int anest_();
    static integer nxloc;
#define itype (equiv_4)
    static integer indxy;
#define lclas1 ((logical1 *)&ailmtb_ + 4800)
#define lclas2 ((shortint *)&ailmtb_ + 2400)
#define lment4 ((integer *)&ailmtb_)
#define itype1 ((logical1 *)equiv_4)
    extern /* Subroutine */ int adfpro_();
#define ipunct (equiv_4 + 1)
    static integer listno, ientry;
    extern /* Subroutine */ int aexprs_(), asqilt_(), aprint_();
    static integer keq;
#define ipt ((integer *)&aptpp_)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER LCLAS2*2(1200),LMENT4*4(1200) */
/*     THIS PROGRAM REMOVES NESTED COMPUTING AND/OR GEOMETRIC DEFINITIONS */
/*      IT VERIFIES THEIR EXISTANCE, PROCESSES THEM, THEN REMOVES THEM */
/*     FROM THE ELMENT TABLE, LEAVING A POINTER TO WORKING STORAGE IN THE */
/*     ELMENT TABLE ENTRY FOR THE LEFT PARENTHESIS OF THE NES */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */

    listno = 1;
    *itype = 0;
    *ipunct = 0;

/* ...     TEST FOR (MORE) NESTS IN THE STATEMENT */
L50:
    if (apartb_.lstnst != 0) {
	goto L70;
    }

/* ...     NO (MORE) NESTS - SET UP INDICES FOR FULL STATEMENT */
    indxy = abreak_1.inill - 1;
    aprtab_.iendp = ailmtb_.jlment + 1;
    ailmtb_.iclass[aprtab_.iendp - 1] = adata1_1.japth;
/* ...     SET INDICATOR TO SHOW STATEMENT BEING PROCESSED */
    apartb_.lstnst = -1;
    goto L80;

/* ...     THERE ARE MORE NESTS - SET UP INDICES FOR NEXT ONE */
L70:
    indxy = apartb_.lstnst;
    indx2 = (indxy << 1) - 1;
    aprtab_.iendp = lment4[OTHER_ENDIAN_S(indx2 - 1)];
/* ...     PUT POINTER TO FOLLOWING NEST (IF ANY) INTO NEST INDICATOR */
    apartb_.lstnst = lment4[OTHER_ENDIAN_S(indx2)];

L80:
    aprtab_.istarp = indxy + 1;
    ientry = aprtab_.istarp;
/* ...     DETERMINE THE TYPE OF THIS NEST */
    keq = 0;
    iloc = (indxy << 2) - 3;

L90:
    nxloc = iloc;
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(iloc + 6)];
/* ...     IF ICLASS TYPE GREATER THAN 6, IT IS MEANINGLESS */
    if (*itype > 6) {
	goto L1950;
    }
/* ...     BRANCH ON CODE TYPE */
    switch ((int)*itype) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L300;
	case 6:  goto L1880;
    }

/* ...     VARIABLE SYMBOL - CHECK FOR SUBSCRIPT */
L100:
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(iloc + 10)];
    if (*itype < 7) {
	goto L110;
    }
/* ...     SUBSCRIPT FOUND - SKIP IT */
    nxloc += 4;
    ++ientry;

/* ...     IF PUNCTUATION FOUND BEFORE VARIABLE, NOT LOOKING FOR = SIGN */
L110:
    if (keq != 0) {
	goto L300;
    }
/* ...     = SIGN FOLLOWING VARIABLE ACCEPTABLE - DO WE HAVE ONE */
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(nxloc + 10)];
    if (*itype != 4) {
	goto L1960;
    }
    itype1[OTHER_ENDIAN_W(7)] = lclas1[OTHER_ENDIAN_W(nxloc + 9)];
    if (*ipunct == 8) {
	goto L120;
    }
/* ...     NO = SIGN FOUND */
/* ...     IF STATEMENT BEING PROCESSED, MUST HAVE IT HERE, OR ERROR */
    if (apartb_.lstnst < 0) {
	goto L1955;
    }

/* ...     SEE IF ONLY ONE PARAMETER IN NEST */
    if (aprtab_.iendp > ientry + 1) {
	goto L310;
    }
/* ...     SINGLE VARIABLE, POSSIBLY SUBSCRIPTED - DOES NEST */
/* ...     IMMEDIATELY FOLLOW A VARIABLE */
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(iloc - 2)];
    if (*itype == 1) {
	goto L1850;
    }
/* ...     NO - IF NEST IS FUNCTION ARGUMENT, SET UP PARAMETER RECORD */
    if (*itype != 2) {
	goto L1874;
    }
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(iloc - 3)];
    if (*itype - 19 != 0) {
	goto L1874;
    } else {
	goto L1880;
    }

/* ...     = SIGN FOUND - TEST FOLLOWING ENTRY FOR SURFACE TYPE */
L120:
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(nxloc + 13)];
    if (*itype == 24) {
	goto L1872;
    }
/* ...     NO - SCALAR ASSIGNMENT */
    goto L1870;

/* ...     VOCABULARY - IF PROCESSING A STATEMENT, EXIT */
L200:
    if (apartb_.lstnst < 0) {
	goto L1920;
    }
/* ...     STARTING A NEST - IS VOCAB. AN ARITHMETIC FUNCTION */
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(nxloc + 5)];
    if (*itype == 19) {
	goto L1850;
    }
/* ...     NO - IS ANY OTHER VOCAB. ACCEPTABLE */
    if (keq != 0) {
	goto L1850;
    }
/* ...     YES - TEST FOR SURFACE TYPE */
    if (*itype == 24) {
	goto L1872;
    }
/* ...     NO - PARAMETER LIST */
    goto L1880;

/* ...     NUMBER OR COMPUTED EXPRESSION - TEST FOR COMMA FOLLOWING */
L300:
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(nxloc + 10)];
    if (*itype != 4) {
	goto L1970;
    }
    itype1[OTHER_ENDIAN_W(7)] = lclas1[OTHER_ENDIAN_W(nxloc + 9)];
L310:
    if (*ipunct != 9) {
	goto L1850;
    }
/* ...     YES - PARAMETER LIST */
    goto L1880;

/* ...     FIRST CODE IS PUNCTUATION - SET FLAG TO INDICATE IT */
L400:
    keq = 1;
/* ...     INCREMENT PICKUP INDEX TO NEXT ENTRY */
    iloc += 4;
    goto L90;

/* ...     NEST IS COMPUTING EXPRESSION OR SINGLE SCALAR */
L1850:
    aprtab_.istarp = indxy;
    aprtab_.itsq = 1;
    if (aprtab_.iendp > aprtab_.istarp + 2) {
	goto L1864;
    }
/* ...     SINGLE SCALAR - SUBSCRIPT IF PRECEDED BY VARIABLE SYMBOL */
    itype1[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(iloc - 2)];
    if (*itype == 1) {
	goto L1900;
    }

/* ...     SET UP PTPP CLASS 12 RECORD HEADER */
L1864:
    ipt[OTHER_ENDIAN_S(0)] = 12;
/* ...     TEST FOR SUFFICIENT ROOM IN SCALAR TABLE FOR NEST RESULT */
    if (ascalr_.iscws <= 180) {
	goto L1866;
    }
    a1com_1.jsuber = 62;
    goto L1920;

/* ...     PUT INDEX TO STORAGE FOR NEST RESULT INTO PTPP AND ELMENT */
L1866:
    ipt[OTHER_ENDIAN_S(2)] = ascalr_.iscws;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    lment4[OTHER_ENDIAN_S(indx2)] = ascalr_.iscws;
    lment4[OTHER_ENDIAN_S(indx2 - 1)] = 0;
    ++ascalr_.iscws;

/* ...     PROCESS NEST */
    aptpp_.inptp = 3;
    aexprs_();
/* ...     GO TO SQUEEZE THE ELMENT TABLE */
    goto L1900;

/* ...     SCALAR ASSIGNMENT NEST */
L1870:
    anest_();
    goto L1874;

/* ...     GEOMETRIC NEST */
L1872:
    aprtab_.itsq = 3;
    adfpro_();

/* ...     IF STATEMENT JUST PROCESSED, GO TO EXIT */
L1874:
    if (apartb_.lstnst < 0) {
	goto L1920;
    }

/* ...     IT WAS A NEST - SET FLAG TO INDICATE ASSIGNMENT TYPE */
    aprtab_.itsq = 3;
    goto L1900;

/* ...     NEST IS ARGUMENT LIST */
L1880:
    aprtab_.istarp = indxy;
    aprtab_.itsq = 2;

/* ...     SET UP PTPP CLASS 20 RECORD HEADER */
    ipt[OTHER_ENDIAN_S(0)] = 20;
/* ...     TEST FOR SUFFICIENT ROOM IN TABLE FOR DATA BLOCK INDEX */
    if (listno <= 10) {
	goto L1884;
    }
    a1com_1.jsuber = 70;
    goto L1920;

/* ...     PUT INDEX TO DATA BLOCK POINTER LOCATION INTO PTPP */
/* ...     AND ELMENT */
L1884:
    ipt[OTHER_ENDIAN_S(2)] = listno;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    lment4[OTHER_ENDIAN_S(indx2)] = listno;
    lment4[OTHER_ENDIAN_S(indx2 - 1)] = 0;
    ++listno;
/* ...     PROCESS THE NEST */
    aptpp_.inptp = 3;
    aexprs_();

L1900:
    if (a1com_1.jsuber != 0) {
	goto L1920;
    }
/* ...     REMOVE PROCESSED NEST FROM THE ELMENT TABLE */
    aprtab_.istarp = indxy;
    asqilt_(&aprtab_.nmove);
    aprint_(&c__5);
    aprtab_.lindx -= aprtab_.nmove;
    goto L50;

/* ...     ALL NESTS REMOVED */
/* ...     RESET SCALAR TABLE STORING INDEX */
L1920:
    ascalr_.iscws = 1;
    aprint_(&c__1);
    aprtab_.istarp = abreak_1.inill;
    aprtab_.iendp = ailmtb_.jlment;
/* L998: */
    return 0;

L1950:
    a1com_1.jsuber = 6110;
    goto L1920;
/* .. */
/* .. VARIABLE SYMBOL IS NOT FOLLOWED BY AN EQUAL SIGN */
L1955:
    a1com_1.sum = 1;
    a1com_1.name__ = ailmtb_.elment[abreak_1.inill - 1];
L1960:
    a1com_1.jsuber = 82;
    goto L1920;
/* .. */
/* ..    PUNCTUATION IS MISSING */
L1970:
    a1com_1.jsuber = 78;
    goto L1920;
} /* amon8_ */

#undef ipt
#undef ipunct
#undef itype1
#undef lment4
#undef lclas2
#undef lclas1
#undef itype


