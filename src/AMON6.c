/* AMON6.f -- translated by f2c (version 20000121).
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
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__6 = 6;

/* Subroutine */ int amon6_()
{
    /* Initialized data */

    static struct {
	shortint e_1[2];
	integer e_2;
	} equiv_0 = { 0, 0x304, 0 };

    static struct {
	shortint e_1;
	} equiv_2 = { 0 };

    static struct {
	shortint e_1[2];
	integer e_2;
	} equiv_3 = { 0, 0x804, 0 };

    static struct {
	shortint e_1[2];
	integer e_2;
	} equiv_4 = { 0, 0x904, 0 };


    /* System generated locals */
    integer i__1;

    /* Local variables */
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
    static integer j, l, m;
#define keqal ((shortint *)&equiv_3)
#define canon ((doublereal *)&avst_1)
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    static integer jtemp1;
    extern /* Subroutine */ int avs1pt_();
    static integer kl;
#define jcomma ((integer *)&equiv_4)
#define kcomma ((shortint *)&equiv_4)
#define icanon ((integer *)&avst_1)
#define iequal ((integer *)&equiv_3)
#define kslash ((shortint *)&equiv_0)
#define jslash ((integer *)&equiv_0)
    extern /* Subroutine */ int aptput_();
    static integer icomma;
    extern /* Subroutine */ int amatmv_(), aprint_();
#define gat ((logical1 *)&equiv_2)
#define kat ((shortint *)&equiv_2)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*       INTEGER*2 KAT/0/,KEQAL(2)/0,Z0804/,KCOMMA(2)/0,Z0904/ */
/*       INTEGER*2 KSLASH(2)/0,Z0304/ */
/*     THIS PROGRAM PROCESSES THE FIRST STATEMENT OF A MACRO DEFINITION */
/*        MAC1 = MACRO/A=1,B=ON,C,D */
/*     THE MACRO VARIABLES AND STANDARD VALUES, IF ANY, ARE PUT IN CANON. */
/*     SUBSEQUENTLY, THE SQUEEZED MACRO WILL BE PUT IN CANON FOLLOWING */
/*     THE MACRO VARIABLE INFORMATION */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
    abreak_1.jsav = 0;
    amacro_1.macerr = 0;
    aptpp_1.jmode = 6;
    aptpp_1.inptp = 0;
/* ...  MOVE PT DATA TO PTPP TABLE AREA */
    aptput_();
/* ... BRANCH IF NOT IN MACRO OR LOOP MODE */
    if (abreak_1.nwonrd == 0) {
	goto L1080;
    }
/* ... LOOP MODE IS ON- ILLEGAL TO DEFINE A MACRO AT THIS TIME */
    a1com_1.jsuber = 201;
/* ... * * * */
/* ... FOR THIS ERROR EXIT TURN OFF MACRO AND LOOP MODE FLAGS */
    abreak_1.nwonrd = 0;
    a1com_1.loop = 0;
/* ... * * * */
    goto L998;
L1080:
    if (ailmtb_1.iclass[abreak_1.k] ==SWTCH_ENDIAN_INT_SHRT( *iequal)) {
	goto L1110;
    }
/* ...  MUST BE AN = SIGN AFTER MACRO NAME */
L1100:
    a1com_1.jsuber = 203;
    goto L998;
/* ... IS MACRO NAME A VARIABLE SYMBOL */
L1110:
    if (ailmtb_1.iclass[abreak_1.k - 1] == 1) {
	goto L1130;
    }
/* ...  MACRO NAME MUST BE A VARIABLE SYMBOL */
/* L1120: */
    a1com_1.jsuber = 204;
    goto L998;
L1130:
    a1com_1.name__ = ailmtb_1.elment[abreak_1.k - 1];
/* ... MOVE MACRO NAME INTO VST TABLE */
    avs1pt_(&j);
/* ... TEST  IF MACRO NAME WAS PLACED SUCCESSFULLY INTO VST */
    if (j == 1) {
	goto L1150;
    }
/* ...  MACRO NAME NOT UNIQUE */
/* L1140: */
    a1com_1.jsuber = 202;
    a1com_1.sum = 1;
    goto L998;
L1150:
    amacro_1.macvst = a1com_1.namsub;
    jtemp1 = (amacro_1.macvst << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 8;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = 0;
    alibry_1.defnam = a1com_1.name__;
    amcstf_1.idlocn = amxtab_1.maxvs1 + 2;
    amcstf_1.numids = 0;
/* ...  CHECK FOR MACRO VARIABLES */
    m = amacro_1.limcan + 4;
    if (abreak_1.k + 3 >= ailmtb_1.jlment) {
	goto L1210;
    }

    l = abreak_1.k + 3;
    if (ailmtb_1.iclass[l - 1] != SWTCH_ENDIAN_INT_SHRT(*jslash)) {
	goto L1100;
    }
    if (l == ailmtb_1.jlment) {
	goto L1190;
    }
    icomma = 1;

    i__1 = ailmtb_1.jlment;
    for (kl = l; kl <= i__1; ++kl) {
	if (ailmtb_1.iclass[kl - 1] !=SWTCH_ENDIAN_INT_SHRT( *jcomma)) {
	    goto L1175;
	}
	++icomma;

L1175:
	;
    }
    amacro_1.lmdw = icomma * 5;
    if (amacro_1.limcan + 3 + amacro_1.lmdw < amxtab_1.maxtab) {
	goto L1180;
    }
/* ...  NOT ENOUGH ROOM IN CANON TO STORE MACRO VARIABLES. */
    amacro_1.jwhat = 1;
    amatmv_();
    m = amacro_1.limcan + 4;

/* ...  ROOM IN CANON FOR MACRO VARAIBLES */
L1180:
    if (l < ailmtb_1.jlment) {
	goto L1220;
    }
L1190:
    if (amcstf_1.macrd == 0) {
	goto L1210;
    }
/* ...  CANNOT NEST MACRO DEFINITIONS - ONLY THE CALLS */
/* L1200: */
    a1com_1.jsuber = 201;
    a1com_1.sum = 1;
    goto L998;

/* ...     SET FLAGS FOR DEFINING A MACRO */
L1210:
    amcstf_1.macrd = -1;
    a1com_1.loop = 1;
    amacro_1.lmdw = m - amacro_1.limcan - 4;
    aprint_(&c__6);
    goto L998;

/* ...  PROCESS MACRO VARIABLES */
L1220:
    if (ailmtb_1.iclass[l] == 1) {
	goto L1240;
    }
L1230:
    a1com_1.jsuber = 207;
    goto L998;
/* ...     PUT MACRO VARIABLE SYMBOL INTO MACRO HEADING */
L1240:
    canon[m - 1] = ailmtb_1.elment[l];
/* ...     IF SYMBOL IS LAST ENTRY IN STATEMENT, NO NORMAL VALUE */
    if (ailmtb_1.jlment == l + 1) {
	goto L1280;
    }
/* ...     NOT LAST ENTRY - NEXT MUST BE EITHER COMMA OR = SIGN */
    if (ailmtb_1.iclass[l + 1] == SWTCH_ENDIAN_INT_SHRT(*jcomma)) {
	goto L1280;
    }
/* ...     NOT COMMA - TRY = SIGN - IF NOT, ERROR */
    if (ailmtb_1.iclass[l + 1] != SWTCH_ENDIAN_INT_SHRT(*iequal)) {
	goto L1230;
    }
/* ...     = SIGN FOUND... */
    jtemp1 = (l << 2) - 3;
/* ...     TEST ENTRY FOLLOWING = FOR PUNCTUATION */
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 14)];
    if ((i__1 = *kat - 4) < 0) {
	goto L1260;
    } else if (i__1 == 0) {
	goto L1250;
    } else {
	goto L1230;
    }
/* ...     PUNCTUATION FOUND - ONLY SIGN OF FOLLOWING NUMBER */
/* ...     ACCEPTABLE - TEST FOR NUMBER */
L1250:
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 18)];
    if (*kat != 3) {
	goto L1230;
    }
/* ...     NUMBER FOUND - TEST FOR SIGN - IF MINUS, NEGATE NUMBER */
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 13)];
    if ((i__1 = *kat - 2) < 0) {
	goto L1255;
    } else if (i__1 == 0) {
	goto L1252;
    } else {
	goto L1275;
    }
L1252:
    ailmtb_1.elment[l + 3] = -ailmtb_1.elment[l + 3];
L1255:
    ++l;
/* ...     STORE NORMAL VALUE FOR MACRO VARIABLE */
L1260:
    canon[m] = ailmtb_1.elment[l + 2];
    jtemp1 = (m << 1) - 1;
    icanon[OTHER_ENDIAN_S(jtemp1 + 4)] = ailmtb_1.iclass[l + 2];
    l += 4;
    goto L1290;

/* ...     ILLEGAL PUNCTUATION IN MACRO VARIABLE NORMAL ASSIGNMENT */
L1275:
    a1com_1.jsuber = 214;
    goto L998;

/* ...     NO NORMAL VALUE GIVEN - ENTER NODEFX */
L1280:
    canon[m] = adata1_1.anodef;
    l += 2;
L1290:
    m += 5;
    if (m - amacro_1.limcan - 4 <= abreak_1.maxmv * 5) {
	goto L1180;
    }
/* ... MACRO CALL STATEMENT EXCEEDS LIMIT OF 50 VARIABLES */
/* L1300: */
    a1com_1.jsuber = 205;
L998:
    return 0;
} /* amon6_ */

#undef kat
#undef gat
#undef jslash
#undef kslash
#undef iequal
#undef icanon
#undef kcomma
#undef jcomma
#undef lclas1
#undef canon
#undef keqal
#undef ivst
#undef ptpp


