/* ANEST.f -- translated by f2c (version 20000121).
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
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int anest_()
{
    /* Initialized data */

    static struct {
	shortint e_1[2];
	} equiv_5 = { 0, 0 };


    /* System generated locals */
    integer i__1;

    /* Local variables */
#define vst4 ((integer *)&avst_1)
    static integer idum, j;
#define itype ((shortint *)&equiv_5 + 1)
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
#define lclas2 ((shortint *)&ailmtb_1 + 2400)
    extern /* Subroutine */ int avs1ck_();
#define lment4 ((integer *)&ailmtb_1)
#define itype1 ((logical1 *)&equiv_5)
    extern /* Subroutine */ int avs1pt_();
    static integer nbegin, iscloc;
    extern /* Subroutine */ int aprfix_();
#define ipunct ((shortint *)&equiv_5)
    extern /* Subroutine */ int aexprs_(), aptlod_(), aptput_();
    static integer ind;
#define kpt ((integer *)&aptpp_1)
    static integer ist, icl1, icl2, jsw3;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* .... */
/*       INTEGER LCLAS2*2(1200),LMENT4*4(1200) */
/*       INTEGER*2 ITYPE/0/,IPUNCT/0/ */

/* ...     THIS ROUTINE PROCESSES ALL ARITHMETIC ASSIGNMENT */
/* ...     STATEMENTS AND NESTS */
/* ... GENERATING THE CLASS 13 PTPP RECORD AND CALLING AEXPRS TO OUPUT THE */
/* ..CLASS 12 PTPP RECORD. */
/*  **      ***         ***          ***           ***MB*****   *SJD** */
/* 	f2c shutup data */

    iscloc = 0;

/* ...     LIMITS OF SCALAR DEFINITION STATEMENT OR NEST */
    ist = aprtab_1.istarp;
    ind = aprtab_1.iendp;

/* ...     TEST FOR SUBSCRIPT ON SYMBOL BEING DEFINED */
/* L510: */
    nbegin = aprtab_1.istarp + 1;
    icl1 = (nbegin << 2) - 3;
    jsw3 = 2;
/* ...     IF = SIGN IMMEDIATELY FOLLOWS SYMBOL, THERE IS NO SUBSCRIPT */
    itype1[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
    if (*ipunct == 8) {
	goto L550;
    }
/* ...     = SIGN NOT FOUND - IF ENTRY NOT SUBSCRIPT, ERROR */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 2)];
    if (*itype >= 7) {
	goto L540;
    }
    a1com_1.jsuber = 6134;
    goto L998;

/* ...     SKIP SUBSCRIPT */
L540:
    ++nbegin;
    icl1 += 4;
    jsw3 = 1;
L550:
    aprtab_1.istarp = nbegin;
    icl2 = (nbegin << 1) - 1;

/* ...     TEST FOR NUMBER IMMEDIATELY FOLLOWING = SIGN */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
    if (*itype != 3) {
	goto L560;
    }
/* ...     YES - IS IT ONLY PARAMETER IN STATEMENT */
    if (nbegin + 2 < aprtab_1.iendp) {
	goto L560;
    }
/* ...     YES - PUT NUMBER INTO PT ARRAY, AND GO TO PROCESS SYMBOL */
    aptpp_1.pt[2] = ailmtb_1.elment[aprtab_1.iendp - 2];
    goto L570;

/* ...     SET UP PTPP CLASS 12 RECORD HEADER */
L560:
    kpt[OTHER_ENDIAN_S(0)] = 12;
/* ...     TEST FOR ENOUGH ROOM IN TEMP. STORAGE TABLE FOR NEST RESULT */
    if (ascalr_1.iscws <= 180) {
	goto L565;
    }
    a1com_1.jsuber = 62;
    goto L2405;

/* ...     PUT INDEX TO STORAGE FOR NEST RESULT INTO PTPP AND ELMENT */
L565:
    kpt[OTHER_ENDIAN_S(2)] = ascalr_1.iscws;
    kpt[OTHER_ENDIAN_S(3)] = 0;
    iscloc = ascalr_1.iscws;
    ++ascalr_1.iscws;

/* ...     INITIALIZE STORING INDEX FOR COMPUTING EXPRESSION */
    aptpp_1.inptp = 3;
/* ...     SET FLAG TO ACCEPT COMPUTING OPERATORS */
    aprtab_1.itsq = 1;
/* ...     PROCESS THE EXPRESSION IN THE STATEMENT OR NEST */
    aexprs_();

/* ...     THE ONLY VALUE FOR JSUBER AT THIS POINT IS 62 - TOO MANY */
/* ...     SCALARS IN STORAGE - THE LIMIT IS 30 FOR A SINGLE STATEMENT */
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
L570:
    a1com_1.name__ = ailmtb_1.elment[ist - 1];
    avs1ck_(&j);
    switch ((int)jsw3) {
	case 1:  goto L2360;
	case 2:  goto L2280;
    }

/* ...     UNSUBSCRIPTED VARIABLE */
L2280:
    switch ((int)j) {
	case 1:  goto L2330;
	case 2:  goto L2370;
	case 3:  goto L2335;
	case 4:  goto L2380;
	case 5:  goto L2350;
	case 6:  goto L2320;
	case 7:  goto L2390;
	case 8:  goto L2320;
	case 9:  goto L2320;
    }
/* ... */
/* .. NO SUBSC. GIVEN FOR A VAR. THAT HAS APPREARED IN A RESERV STMT. */
L2320:
    a1com_1.jsuber = 105;
    goto L2405;

/* ...  ENTER IN VST, UPDATE SCALAR VARIABLE COUNTER */
L2330:
    avs1pt_(&j);
    if (j != 2) {
	goto L2335;
    }
/* ...  VST OVERFLOW PREVAILS */
    a1com_1.jsuber = 15;
    goto L2405;
/* ... */
/* .. VAR. ENTERED IN VST O.K. UPDATE SCALAR STORAGE TABLE */
/* ...  IS THERE ROOM FOR THE FINAL RESULTS  OF THIS DEF. */
L2335:
    ++amxtab_1.maxscl;
    icl2 = (a1com_1.namsub << 1) - 1;
    vst4[OTHER_ENDIAN_S(icl2 + 1)] = 2;
    vst4[OTHER_ENDIAN_S(icl2 + 2)] = amxtab_1.maxscl;
    if (amxtab_1.maxscl <= amxtab_1.maxslr) {
	goto L2350;
    }
/* ... */
/* .. PART PROG. CONTAINS MORE THAN 5,000 SCALAR DEFINITIONS */
L2340:
    a1com_1.jsuber = 14;
    goto L2405;

/* ...  SET UP DATA FOR PTPP CLASS 13 */
L2350:
    aptpp_1.inptp = 5;
    j = 5;
    if (iscloc != 0) {
	goto L2355;
    }
    aptpp_1.inptp = 6;
    j = 7;
L2355:
    kpt[OTHER_ENDIAN_S(j - 1)] = 2;
    kpt[OTHER_ENDIAN_S(j)] = 0;
    kpt[OTHER_ENDIAN_S(j + 1)] = 0;
    kpt[OTHER_ENDIAN_S(j + 2)] = a1com_1.namsub;
    goto L2430;

/* ...  SUBSCRIPTED VARIABLE */
L2360:
    switch ((int)j) {
	case 1:  goto L2370;
	case 2:  goto L2370;
	case 3:  goto L2380;
	case 4:  goto L2380;
	case 5:  goto L2370;
	case 6:  goto L2410;
	case 7:  goto L2390;
	case 8:  goto L2420;
	case 9:  goto L2400;
    }

/* ... SUBSCRIPT GIVEN FOR A VAR. NOT APPEARING IN A RESERV STMT, PRIOR */
L2370:
    a1com_1.jsuber = 108;
    goto L2405;

/* ... VAR. SYMB. IS A PREVIOUSLY DEFINED STATEMENT I.D. */
L2380:
    a1com_1.jsuber = 251;
    goto L2405;

/* ... VARIABLE IS A M A C R O  NAME */
L2390:
    a1com_1.jsuber = 211;
    goto L2405;

/* ... SCALAR ARRAY CONTAINS A SURFACE OR VISA VERSA */
L2400:
    a1com_1.jsuber = 106;
L2405:
    a1com_1.sum = 1;
/* ... */
/* ... OUTPUT NUMERIC SUBSCRIPT IF APPLICABLE */
    if (*itype != 8) {
	goto L998;
    }
    aptpp_1.pt[6] = ailmtb_1.elment[ist];
    a1com_1.sum = 9;
    goto L998;

/* ...  DIMENSIONED ONLY - SET AS A SCALAR */
L2410:
    aprfix_(&c__1, &idum);
    icl2 = (a1com_1.namsub << 1) - 1;
    amxtab_1.maxscl += (i__1 = vst4[OTHER_ENDIAN_S(icl2 + 2)], abs(i__1));
    if (amxtab_1.maxscl > amxtab_1.maxslr) {
	goto L2340;
    }
/* ...  FINISH PTPP CLASS 13 RECORD AND OUTPUT IT */
L2420:
    aprtab_1.istarp = ist;
    aptpp_1.inptp = 3;
    if (iscloc == 0) {
	aptpp_1.inptp = 4;
    }
    aptlod_();
/* ...     TEST FOR ERROR IN APTLOD */
    if (a1com_1.jsuber != 0) {
	goto L998;
    }


L2430:
    --aptpp_1.inptp;
    kpt[OTHER_ENDIAN_S(0)] = 13;
    kpt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 1;
    kpt[OTHER_ENDIAN_S(2)] = 0;
    kpt[OTHER_ENDIAN_S(3)] = iscloc;
    aptpp_1.jmode = 5;
    aptput_();

L998:
    aprtab_1.istarp = ist;
    aprtab_1.iendp = ind;
    return 0;
} /* anest_ */

#undef kpt
#undef ipunct
#undef itype1
#undef lment4
#undef lclas2
#undef lclas1
#undef itype
#undef vst4


