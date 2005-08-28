/* AMON5.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include "assert.h"

/* Common Block Declarations */

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;

/* Subroutine */ int amon5_(kret)
integer *kret;
{
    /* Initialized data */

    static struct {
	shortint e_1;
	} equiv_1 = { 0 };

    static struct {
	shortint e_1[2];
	integer e_2;
	} equiv_4 = { 2, 0xe02, 0 };

    static struct {
	shortint e_1[2];
	integer e_2;
	} equiv_5 = { 0, 0x904, 0 };


    /* System generated locals */
    integer i__1;
    static integer equiv_3[1];

    /* Local variables */
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
    static doublereal a;
    static integer i__, j;
#define canon ((doublereal *)&avst_1)
#define ktemp ((shortint *)equiv_3)
#define kterm ((shortint *)&equiv_4)
#define itemp (equiv_3)
#define iterm ((integer *)&equiv_4)
    extern /* Subroutine */ int aclas7_();
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_(), aifun8_();
    static integer jtemp1, jtemp2, ii, kn;
#define kcomma ((shortint *)&equiv_5)
#define icanon ((integer *)&avst_1)
#define jcomma ((integer *)&equiv_5)
    extern /* Subroutine */ int aptput_(), aprint_();
#define gat ((logical1 *)&equiv_1)
#define kat ((shortint *)&equiv_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*       INTEGER*2 KAT/0/,KTEMP(2),KTERM(2)/2,Z0E02/,KCOMMA(2)/0,Z0904/ */
/*     THIS ROUTINE PRE-PROCESSES THE INDIVIDUAL STATEMENTS RESULTING */
/*     FROM A MACRO CALL */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
/* .. */
/* ...  CHECK FOR ID TO ESTABLISH START OF NORMAL STATEMENT INFORMATION */
    if (ailmtb_1.jlment == 1) {
	goto L800;
    }
    if (ailmtb_1.iclass[1] != adata1_1.japth) {
	goto L800;
    }
/* L740: */
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(3)];
    switch ((int)*kat) {
	case 1:  goto L750;
	case 2:  goto L800;
	case 3:  goto L760;
    }
L750:
    a1com_1.name__ = ailmtb_1.elment[0];
    goto L770;
L760:
    a = ailmtb_1.elment[0];
    aifun8_(&a, &a1com_1.name__);
L770:
    avs1ck_(&j);
    if (a1com_1.jsuber == 0) {
	goto L775;
    }
L772:
    abreak_1.k = 3;
    goto L810;
L775:
    if (j == 3) {
	goto L780;
    }
    if (j == 4) {
	goto L780;
    }
    a1com_1.jsuber = 6;
    goto L998;
L780:
    aklas7_1.idis = a1com_1.name__;
    aklas7_1.idvst = a1com_1.namsub;
/* ...  ID FOUND */
    ktemp[OTHER_ENDIAN_S(1)] = (shortint) (a1com_1.indxpt - amxtab_1.maxvst);
    ktemp[OTHER_ENDIAN_S(0)] = (shortint) (aptpp_1.irecn + 1);
    jtemp1 = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 3;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = *itemp;
    goto L772;
/* ...  NO ID FOUND */
L800:
    abreak_1.k = 1;
    aklas7_1.idis = 0.;
    aklas7_1.idvst = 0;
L810:
//	assert(0);//check proper function here of macro
    if (ailmtb_1.iclass[abreak_1.k - 1] != SWTCH_ENDIAN_INT_SHRT(*iterm)) {
	goto L880;
    }

/* ...  TERMAC FOUND */
/* .. OUTPUT CLASS7 PTPP FOR IT AND RETURN TO THE PREVIOUS MODE OF PROCES */
/* L850: */
    aclas7_();
/* ...  DECREASE MACRO COUNT FOR NESTING */
    --amcstf_1.maccur;
/* ..  MACCUR EQUALS ZERO THEN PREVIOUS MODE WAS NOT MACRO EXEC. */
    if (amcstf_1.maccur != 0) {
	goto L870;
    }
    amcstf_1.idlocn = amcstf_1.isvid;
/* ...  NESTINGS COMPLETE - LAST MACRO FINISHED */
/* L860: */
    amcstf_1.macrd = 0;
    abreak_1.nrelcn = amxtab_1.maxvst + 1;
    *kret = 1;
/* .. NWONRD.NE.0 INDICATES TO RETURN TO LOOP EXEC. MODE */
    if (abreak_1.nwonrd != 0) {
	goto L998;
    }
/* .. FLUSH EXISTING PTPP TABLE AND RETURN TO NORMAL MODE PROCESSING */
    a1com_1.loop = 0;
    aptpp_1.jmode = 6;
    aptpp_1.inptp = 0;
    aptput_();
    goto L998;

/* ...  REINSTATE CALLING PROGRAM TO RESUME PROCESSING */
L870:
    abreak_1.kanlcn = amcstf_1.maclcn[amcstf_1.maccur - 1];
    jtemp1 = (abreak_1.kanlcn << 1) - 1;
    abreak_1.nrelcn = icanon[OTHER_ENDIAN_S(jtemp1 - 1)];
    abreak_1.nextcn = 1;
    jtemp1 = (amcstf_1.macstr[amcstf_1.maccur - 1] << 1) - 1;
    amcstf_1.nmacvr = icanon[OTHER_ENDIAN_S(jtemp1 + 2)];
    a1com_1.name__ = amcstf_1.macnam[amcstf_1.maccur - 1];
    avs1ck_(&j);
    amcstf_1.idlocn = amcstf_1.macids[amcstf_1.maccur - 1];
    aprint_(&c__4);
    *kret = 1;
    goto L998;

/* ...  STATEMENT WAS NOT A TERMAC */
L880:
    kn = abreak_1.k;
    jtemp2 = (abreak_1.k << 2) - 3;
    abreak_1.jsw1 = 0;

L890:
    jtemp1 = (kn << 2) - 3;
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 2)];
    if (*kat != 1) {
	goto L970;
    }
/* L900: */
    i__ = amcstf_1.macstr[amcstf_1.maccur - 1] + 3;
    jtemp1 = (i__ << 1) - 1;
    amcstf_1.nmacvr = icanon[OTHER_ENDIAN_S(jtemp1 - 4)];
/* ...  CHECK FOR MACRO VARIABLES IN STATEMENT */
    if (amcstf_1.nmacvr == 0) {
	goto L990;
    }

    i__1 = amcstf_1.nmacvr;
    for (ii = 1; ii <= i__1; ++ii) {
	if (ailmtb_1.elment[kn - 1] != canon[i__ - 1]) {
	    goto L960;
	}
/* ...  MACRO VARIABLE FOUND - MAKE SUBSTITUATION */
/* ...  IS THIS A CALL/   STATEMENT */
	gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp2 + 1)];
	if (*kat != 7) {
	    goto L950;
	}
/* ...     YES - IF VARIABLE FOLLOWS COMMA, IT STARTS A VARIABLE */
/* ...     ASSIGNMENT PHRASE - DO NOT SUBSTITUTE VALUE IN THIS CASE */
	//check macro function here:
//	assert(0);
	if (ailmtb_1.iclass[kn - 2] == SWTCH_ENDIAN_INT(*jcomma)) {
	    goto L960;
	}
L950:
	ailmtb_1.elment[kn - 1] = canon[i__ + 2];
	ailmtb_1.iclass[kn - 1] = icanon[OTHER_ENDIAN_S(jtemp1 + 8)];
	goto L970;
L960:
	i__ += 5;
/* L965: */
	jtemp1 += 10;
    }

L970:
    ++kn;
/* L980: */
    if (kn <= ailmtb_1.jlment) {
	goto L890;
    }

L990:
    aprint_(&c__1);
    *kret = 0;
L998:
    return 0;
} /* amon5_ */

#undef kat
#undef gat
#undef jcomma
#undef icanon
#undef kcomma
#undef lclas1
#undef iterm
#undef itemp
#undef kterm
#undef ktemp
#undef canon
#undef ivst
#undef ptpp


