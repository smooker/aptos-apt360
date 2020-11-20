/* ASQILT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

/* Subroutine */ int asqilt_(nmovd)
integer *nmovd;
{
    /* System generated locals */
    integer i__1;
    static integer equiv_5[1];

integer debugg, debugg2;
    /* Local variables */
    static integer nfin;
#define natt ((logical1 *)equiv_5)
    static integer i__, j;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
#define lclas2 ((shortint *)&ailmtb_1 + 2400)
    static integer jlmen2;
    extern /* Subroutine */ int avs1ck_();
#define lpren1 ((logical1 *)&adata1_1 + 76)
//#define lpren2 ((shortint *)&adata1_1 + 39)
#define lpren2 ((shortint *)&adata1_1 + 38)
#define lment4 ((integer *)&ailmtb_1)
    static integer nfm;
#define nat (equiv_5)
    static integer icl1, icl2, nfm1;
#define nat1 ((shortint *)equiv_5 + OTHER_ENDIAN_S(0))
#define nat2 ((shortint *)equiv_5 + OTHER_ENDIAN_S(1))

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER LCLAS2*2(1200),LMENT4*4(1200) */
/* ...  THIS PROGRAM REMOVES EXPRESSIONS FROM THE LMENT TABLE AND SQEEZES */
/* ...  THE REMAINING TABLE */

/* ...     GET INDEX TO FIRST WORD FOLLOWING NEST TO BE REMOVED */
    nfm = aprtab_1.iendp + 1;
/* ...     GET INDEX TO FIRST WORD FOLLOWING CODE WHICH REPLACES NEST */
    nfin = aprtab_1.istarp + 1;

    jlmen2 = (ailmtb_1.jlment << 1) - 1;
    icl2 = (aprtab_1.istarp << 1) - 1;
    icl1 = (aprtab_1.istarp << 2) - 3;
    *nat = 0;

/* ...     BRANCH ON NEST TYPE */
    switch ((int)aprtab_1.itsq) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }

/* ...     COMPUTING EXPRESSION - DETERMINE WHETHER OR NOT IT IS */
/* ...     USED AS A SUBSCRIPT */
L100:
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 - 2)];
    if (*nat1 == 1) {
	goto L105;
    }

/* ...     NOT SUBSCRIPT - PUT CODE IN ICLASS FOR SCALAR IN WORK STORAGE */
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 5;
    goto L215;

/* ...     SUBSCRIPT - TEST FOR EXPRESSION */
L105:
    if (aprtab_1.iendp > aprtab_1.istarp + 2) {
	goto L110;
    }
/* ...     NO - IS IT A VARIABLE */
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
    if (*nat1 == 1) {
	goto L250;
    }
/* ...     NO - IS IT A SCALAR IN WORKING STORAGE */
    if (*nat1 == 5) {
	goto L270;
    }
/* ...     NO - NUMBER */
    goto L260;

/* ...     SUBSCRIPT IS AN EXPRESSION */
L110:
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 9;
    goto L218;

/* ...     ARGUMENT LIST - DETERMINE WHETHER OR NOT IT IS */
/* ...     USED AS A SUBSCRIPT */
L200:
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 - 2)];
    if (*nat1 != 1) {
	goto L205;
    }

/* ...     SUBSCRIPT - PUT CODE IN ICLASS FOR ARGUMENT LIST TYPE */
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 10;
    goto L218;

/* ...     NOT SUBSCRIPT - PUT CODE IN ICLASS FOR ARGUMENT LIST NEST */
L205:
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 11;

/* ...     GET INDEX TO FIRST WORD FOLLOWING CODE(S) WHICH REPLACE NEST */
/* ...  THE FOLLOWING CODE HANDLES THE IMPLICIT COMMA - IF A COMMA IS */
/* ...  REQUIRED IT IS ENTERED IN THE ELMENT TABLE. LEADING COMMA IS */
/* ...  PUT IN UNLESS PREVIOUS ENTRY IS VOCAB. WORD 'IF' OR PUNCTUATION */
/* .... OTHER THAN A RIGHT PARENTHESIS */
/* ...  TRAILING COMMA PUT IN IF NEXT ENTRY IS A LEFT PARENTHESIS */
/* ...     IF SUBSCRIPT BEING REMOVED, SKIP TESTS FOR LEADING COMMA */
L215:
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 - 2)];
    natt[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(icl1 - 3)];
/* ..IF PREVIOUS CODE IS VOC. WORD 'IF' OR AN ARITH. FUNCTION NO COMMAS */
    if (*nat1 != 2) {
	goto L216;
    }
    if (*nat2 == 19) {
	goto L218;
    }
    if (*nat2 == 9) {
	goto L220;
    }
/* ...     IF PREVIOUS CODE IS ANY PUNCTUATION EXCEPT A RIGHT PAREN- */
/* ...     THESIS, NO LEADING COMMA NEEDED FOR ENTRY REPLACING NEST */
L216:
    if (*nat1 != 4) {
	goto L217;
    }
    if (*nat2 != 7) {
	goto L218;
    }
/* ...     MOVE FIRST 2 WORDS OF NEST (WHICH NOW CONTAIN CODE(S) RE- */
/* ...     PLACING NEST) UP 1 WORD, AND INSERT A COMMA */
L217:
    ailmtb_1.elment[aprtab_1.istarp + 1] = ailmtb_1.elment[aprtab_1.istarp];
    ailmtb_1.elment[aprtab_1.istarp] = ailmtb_1.elment[aprtab_1.istarp - 1];
    ailmtb_1.iclass[aprtab_1.istarp + 1] = ailmtb_1.iclass[aprtab_1.istarp];
    ailmtb_1.iclass[aprtab_1.istarp] = ailmtb_1.iclass[aprtab_1.istarp - 1];
    ailmtb_1.iclass[aprtab_1.istarp - 1] = adata1_1.ncomma;
    ++nfin;

/* ...     IF FIRST WORD FOLLOWING NEST IS BEYOND END OF */
/* ...     STATEMENT, NO DATA TO BE MOVED */
L218:
    if (nfm > ailmtb_1.jlment) {
	goto L225;
    }
/* ...     IF ANOTHER NEST STARTS IMMEDIATELY FOLLOWING ONE BEING */
/* ...     REMOVED, MUST INSERT A COMMA PRECEDING IT */
    nfm1 = (nfm << 2) - 3;
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(nfm1 + 2)];
    if (*nat1 != 4) {
	goto L219;
    }
    natt[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(nfm1 + 1)];
    if (*nat2 != 6) {
	goto L220;
    }
L219:
    ailmtb_1.iclass[aprtab_1.iendp - 1] = adata1_1.ncomma;
    --nfm;

/* ...     MOVE PORTION OF STATEMENT FOLLOWING NEST DOWN TO */
/* ...     SQUEEZE OUT NEST */
L220:
    i__1 = ailmtb_1.jlment;
    for (i__ = nfm; i__ <= i__1; ++i__) {
	ailmtb_1.elment[nfin - 1] = ailmtb_1.elment[i__ - 1];
	ailmtb_1.iclass[nfin - 1] = ailmtb_1.iclass[i__ - 1];
/* L222: */
	++nfin;
    }

/* ...     COMPUTE DECREASE IN LENGTH OF STATEMENT */
L225:
    aprtab_1.nmove = ailmtb_1.jlment - nfin + 1;
    *nmovd = aprtab_1.nmove;
/* ...     ADJUST POINTER TO END OF STATEMENT */
    ailmtb_1.jlment = nfin - 1;
/* ...     ADJUST POINTERS FOR NEW LOCATIONS OF PARENTHESES */
    i__1 = jlmen2;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
/* ...     TEST FOR LEFT PARENTHESIS */
//debugg=SWTCH_ENDIAN_INT_SHRT(*lpren2);
debugg=*lpren2;
//debugg2=*lpren1;
//debugg2=lclas2[OTHER_ENDIAN_S(i__)];
	if (lclas2[OTHER_ENDIAN_S(i__)] != *lpren2) {
	    goto L240;
	}
/* ...     YES - IS ITS RIGHT PAREN BEYOND NEST JUST REMOVED */
	if (lment4[OTHER_ENDIAN_S(i__ - 1)] < nfm) {
	    goto L240;
	}
/* ...     YES - REDUCE POINTER TO RIGHT PAREN BY NMOVE */
	lment4[OTHER_ENDIAN_S(i__ - 1)] -= aprtab_1.nmove;
L240:
	;
    }
    aprtab_1.iendp -= aprtab_1.nmove;
    return 0;

/* ...  SUBSCRIPT IS A VARIABLE */
/* ...     SET VARIABLE AS SUBSCRIPT CODE FOR ICLASS */
L250:
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 7;
    a1com_1.name__ = ailmtb_1.elment[aprtab_1.istarp];
    avs1ck_(&j);

/* ...     PUT POINTER TO VST LOCATION OF VARIABLE IN WORD TO BE */
/* ...     STORED IN ELMENT */
/* L255: */
    lment4[OTHER_ENDIAN_S(icl2 - 1)] = 0;
    lment4[OTHER_ENDIAN_S(icl2)] = a1com_1.namsub;
    goto L218;

/* ...  SUBSCRIPT IS A NUMBER */
/* ...     SET NUMERIC SUBSCRIPT CODE FOR ICLASS */
L260:
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 8;
    goto L280;

/* ...     SUBSCRIPT IS A SCALAR IN WORKING STORAGE */
/* ...     SET EXPRESSION SUBSCRIPT CODE FOR ICLASS */
L270:
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 9;

/* ...     PUT DATA FOR SUBSCRIPT IN WORD TO BE STORED IN ELMENT */
L280:
    ailmtb_1.elment[aprtab_1.istarp - 1] = ailmtb_1.elment[aprtab_1.istarp];
    goto L218;

/* ...     NESTED GEOMETRIC DEFINITION OR SCALAR ASSIGNMENT */
L300:
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 5)];
    if (*nat1 != 24) {
	goto L320;
    }
/* ...     UNNAMED NESTED SURFACE DEFINITION */
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 6;
    goto L215;

/* ...     NAMED SURFACE OR SCALAR DEFINITION */
L320:
    ailmtb_1.elment[aprtab_1.istarp - 1] = ailmtb_1.elment[aprtab_1.istarp];
    ailmtb_1.iclass[aprtab_1.istarp - 1] = 0;
    lclas1[OTHER_ENDIAN_W(icl1 + 2)] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
/* ...     TEST FOR SUBSCRIPT */
    natt[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 10)];
    if (*nat1 == 7) {
	goto L330;
    }
    if (*nat1 == 8) {
	goto L330;
    }
    if (*nat1 != 9) {
	goto L215;
    }
/* ...     SUBSCRIPTED SURFACE OR SCALAR */
L330:
    ailmtb_1.elment[aprtab_1.istarp] = ailmtb_1.elment[aprtab_1.istarp + 1];
    ailmtb_1.iclass[aprtab_1.istarp] = ailmtb_1.iclass[aprtab_1.istarp + 1];
/* ...     GET INDEX TO FIRST WORD FOLLOWING CODES WHICH REPLACE NEST */
    nfin = aprtab_1.istarp + 2;
    goto L215;

} /* asqilt_ */

#undef nat2
#undef nat1
#undef nat
#undef lment4
#undef lpren2
#undef lpren1
#undef lclas2
#undef lclas1
#undef natt


