/* AMON4.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include "assert.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

static struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

static struct {
    integer char__, n72, nf, ichar, numcol, mdolar, jskip;
} ascanc_;

#define ascanc_1 ascanc_

static struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;

/* Subroutine */ int amon4_()
{
    /* Initialized data */
    static struct {
	shortint e_1;
	} equiv_4 = { 0 };

    static struct {
	shortint e_1[4];
	integer e_2;
	} equiv_6 = { 1, 0xb02, 2, 0xb02, 0 };


    /* System generated locals */
    integer i__1;

    /* Local variables */
#define ptpp ((doublereal *)&avst_1)
    static integer i__, j, n;
#define iptpp ((integer *)&avst_1)
    static integer notqt;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    static integer jtemp1, ioflag;
#define kloopc ((shortint *)&equiv_6)
#define errtap ((doublereal *)&ataptb_1 + 9)
#define jinwrd ((integer *)&ainpot_1)
#define loopbg ((integer *)&equiv_6)
#define looptm ((integer *)&equiv_6 + 1)
    extern /* Subroutine */ int atapwt_();
    static integer nextpi;
    extern /* Subroutine */ int atapop_(), aptput_(), aprint_(), amatmv_();
#define gcl ((logical1 *)&equiv_4)
#define kcl ((shortint *)&equiv_4)
    static integer idm;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER*2 KCL/0/,KLOOPC(4)/1,Z0B02,2,Z0B02/ */
/* ...     THIS ROUTINE STORES STATEMENTS OF LOOP AND MACRO DEFINITIONS. */
/* ...     BLANKS ARE REMOVED FROM THE DATA IN INWORD, WHICH IS THEN */
/* ...     STORED ON AN EXTERNAL FILE IF PART OF A LOOP, AND IN PTPP IF */
/* ...     PART OF A MACRO. (MACROS ARE MOVED TO CANON WHEN TERMAC FOUND) */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */

/* ...    IS MACRO TOO LARGE - YES, SUPRESS ERROR PRINT THIS TIME */
    if (abreak_1.jsav == 1) {
	goto L665;
    }
/* L630: */
    n = 0;

/* ...     SET WORD COUNT FOR STORAGE OF SOURCE TEXT */
    n = 14;
/* ...     WORD COUNT INITIALIZED FOR FIXED-FIELD - SEE IF IT IS */
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(2)];
    if (*kcl == 1) {
	goto L635;
    }
    n = ascanc_1.numcol / 8 + 2;
    notqt = (n << 3) - 16;
    if (notqt != ascanc_1.numcol) {
	goto L633;
    }
    --n;
L633:
    ainpot_1.inword[n - 1] = ainpot_1.inword[12];
   ++n;
    ainpot_1.inword[n - 1] = ainpot_1.inword[13];

/* ...     DETERMINE WHETHER STATEMENT IS IN A LOOP OR A MACRO */
L635:
    if (amcstf_1.macrd >= 0) {
	goto L650;
    }
    j = abreak_1.nextnw + n;
/* L639: */
    if (j <= amxtab_1.mxptpp + amxtab_1.maxvst) {
	goto L662;
    }
    abreak_1.jsav = 1;
    a1com_1.jsuber = 18;
/* ...     SET FLAG TO CANCEL STORAGE OF MACRO */
    amacro_1.macerr = 1;
    goto L998;

/* ...     STORE STATEMENT OF LOOP AREA ON EXTERNAL FILE */
L650:
    jtemp1 = (n << 1) - 1;
    //jinwrd[OTHER_ENDIAN_S(jtemp1)] = aklas7_1.iisn;
    jinwrd[jtemp1] = aklas7_1.iisn;
    atapwt_(errtap, &ioflag, &c__4, &idm, &c__1, &idm, &c__1, &n, &c__1, 
	    ainpot_1.inword, &n);
/* ...     CHECK FOR ID - (THE POINTER K IS SET TO FIRST ENTRY IN ELMENT */
/* ...     TABLE EXCLUSIVE OF ID) */
    goto L665;

/* ...     STORE STATEMENT OF MACRO IN PTPP */
L662:
    jtemp1 = (abreak_1.nextnw << 1) - 1;
    iptpp[OTHER_ENDIAN_S(jtemp1 - 1)] = 0;
    iptpp[OTHER_ENDIAN_S(jtemp1)] = j + 1;
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nextpi = abreak_1.nextnw + i__;
/* L663: */
	ptpp[nextpi - 1] = ainpot_1.inword[i__ - 1];
    }
    abreak_1.nextnw = j + 1;
    jtemp1 = (j << 1) - 1;
    iptpp[OTHER_ENDIAN_S(jtemp1)] = aklas7_1.iisn;

L665:
    if (ailmtb_1.jlment <= 2) {
	goto L690;
    }
/* ...     TEST 2ND STATEMENT ELEMENT FOR RIGHT PAREN TERMINATING AN ID */
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(7)];
    if (*kcl != 4) {
	goto L690;
    }
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(6)];
    if (*kcl != 7) {
	goto L690;
    }
/* L680: */
    abreak_1.k = 3;
    goto L700;
L690:
    abreak_1.k = 1;

/* ...     TEST FOR LOOPST IN A MACRO DEFINITION - ERROR */
L700:
    if (ailmtb_1.iclass[abreak_1.k - 1] !=SWTCH_ENDIAN_INT_SHRT( *loopbg) ) {
	goto L702;
    }
    if (amcstf_1.macrd < 0) {
	goto L704;
    }

/* ...     TEST FOR LOOPND */
L702:
    if (ailmtb_1.iclass[abreak_1.k - 1] != SWTCH_ENDIAN_INT_SHRT(*looptm)) {
	goto L720;
    }
/* ...     LOOPND FOUND - IF THIS IS MACRO MODE, ERROR */
    if (amcstf_1.macrd == 0) {
	goto L706;
    }
L704:
    a1com_1.jsuber = 210;
    goto L998;
L706:
    amacro_1.nitems = j;
    abreak_1.lplocn = 1;
    if (abreak_1.jsav == 0) {
	goto L715;
    }
/* ...  LOOP TOO LARGE */
    abreak_1.nwonrd = 0;
    a1com_1.loop = 0;
    a1com_1.jsuber = abreak_1.jsav;
    abreak_1.jsav = 0;
    goto L998;

/* ...  SET FLAGS TO EXECUTE THE LOOP */
L715:
    abreak_1.nwonrd = 1;
    atapop_(errtap, &c__2, &ioflag);
    atapop_(errtap, &c__1, &ioflag);
    aptpp_1.jmode = 6;
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }

L720:
    if (abreak_1.jsw2 == 0) {
	goto L998;
    }
/* ...  MACRO WAS BEING PROCESSED */
    abreak_1.nextnw = amxtab_1.maxvst + 1;
    abreak_1.jsw2 = 0;
    amcstf_1.macrd = 0;
    a1com_1.loop = 0;
/* ...     IF ERROR IN MACRO DEFINITION, DO NOT STORE IN CANON */
    if (amacro_1.macerr != 0) {
	goto L998;
    }
/* L725: */
    amacro_1.nitems = j - amxtab_1.maxvst;
/* L730: */
    aprint_(&c__2);
    amacro_1.jwhat = 2;
/* ...  MOVE MACRO TO CANON */
    amatmv_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    aprint_(&c__3);
L998:
    return 0;
} /* amon4_ */

#undef kcl
#undef gcl
#undef looptm
#undef loopbg
#undef jinwrd
#undef errtap
#undef kloopc
#undef lclas1
#undef iptpp
#undef ptpp


