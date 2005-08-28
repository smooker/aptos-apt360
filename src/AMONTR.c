
/* AMONTR.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
//integer debuggg;
//integer debuggg2;
/* Common Block Declarations */
struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

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
    integer ilpcnt, irpcnt, ilvcnt;
} apartb_;

#define apartb_1 apartb_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

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
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

struct {
    doublereal synb[100];
    integer insyn, maxsyn;
} asyntb_;

#define asyntb_1 asyntb_

struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

struct {
    integer char__, n72, nf, ichar, numcol, mdolar, jskip;
} ascanc_;

#define ascanc_1 ascanc_

struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;

/* Subroutine */ int amontr_()
{
    /* Initialized data */

    static integer islash = 0x00000304;

    /* Format strings */
    static char fmt_2478[] = "(\0020\002,10x,z12,z20)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define vst4 ((integer *)&avst_1)
    static integer kend, lcls, kret;
    extern /* Subroutine */ int amon1_(), amon2_(), amon3_(), amon4_(), 
	    amon5_(), amon6_(), amon7_(), amon8_();
    static integer i__;
    extern /* Subroutine */ int ascan_(), afini_(), amon10_(), amon11_();
#define glass ((integer1 *)&aptpp_1 + 2412)
    static integer nmore;
    extern /* Subroutine */ int aclas7_();
#define lclas1 ((integer1 *)&ailmtb_1 + 4800)
#define lment4 ((integer *)&ailmtb_1)
    extern /* Subroutine */ int adiagp_(), adclar_();
    extern integer ibclas_(), aextra_();
#define glastp ((integer1 *)&aptpp_1 + 2416)
    static integer nmacro, itermf, iscwsl, mitebe;
    extern /* Subroutine */ int aprint_();
    extern integer iatype_();
    extern /* Subroutine */ int aptput_();
    static integer jinill;
    extern /* Subroutine */ int aparen_();
    static integer klment, kat;
#define ipt ((integer *)&aptpp_1)

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 0, 0, fmt_2478, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*      INTEGER CHAR,IPT*4(600) */
/*         INTEGER LMENT4*4(1200),VST4*4(1400) */
/*       LOGICAL*1 GLASS(4),GLASTP(4),LCLAS1(2400) */
/*       INTEGER ISLASH/Z00000304/ */
/*     THIS PROGRAM IS THE MAIN CONTROL FOR SECTION ONE, PASS ONE */
/*     IT TAKES A PART PROGRAM FROM THE INPUT FILE AND PRODUCES THE PTPP */
/*     META-LANGUAGE FOR PASS TWO. IT FURTHER IS RESPONSIBLE FOR MAKING */
/*     LANGUAGE CHECKS WHENEVER THE CONTEXT CAN BE ESTABLISHED. */
/*               *          *          *          *          * */
/*                DEFINITION OF PROGRAM VARIABLE NAMES */
/*               *          *          *          *          * */
/*     CANLCN  -    POINTER IN CANON */
/*     CANLTH  -    LENGTH OF ENTRY IN CANON */
/*     DWORK   -    SCRATCH ARRAY USED WHEN WORKING WITH ELMENT TABLE */
/*     ELMENT  -    ARRAY CONTAINING PART PROGRAM STATEMENT BROKEN UP */
/*                  INTO INDIVIDUAL LANGUAGE COMPONENTS */
/*     IATYPE  -    ARRAY CONTAINING CODE FOR TYPE OF ENTRY IN ELMENT */
/*                   1 - VARIABLE SYMBOL */
/*                   2 - VOCABULARY */
/*                   3 - FLOATING POINT NUMBER */
/*                   4 - PUNCTUATION */
/*                   5 - VARIABLE IN WORKING STORAGE (SCALR ARRAY) */
/*                   6 - SURFACE IN WORKING STORAGE  (SURFTB ARRAY) */
/*                   7 - SUBSCRIPT WHICH IS A VARIABLE SYMBOL */
/*                   8 - SUBSCRIPT WHICH IS A FLOATING POINT NUMBER */
/*                   9 - SUBSCRIPT WHICH IS AN EXPRESSION */
/*     IBCLAS  -    ARRAY CONTAINING CLASSIFICATIONS OF VOCABULARY WORDS */
/*     IDFRST  -    VST ENTRY FOR FIRST MACRO ID */
/*     IDIS    -    STATEMENT ID FOR CURRENT PART PROGRAM STATEMENT */
/*     IDVST   -    VST ENTRY FOR CURRENT STATEMENT ID */
/*     IDM      -    NUMBER OF IDS IN CURRENT MACRO */
/*     IENDP   -    FINAL LOCATION OF NEST TO BE PROCESSED */
/*     IFIRST  -    INITIALIZE MONITOR FLAGS IF IFIRST = 0(FIRST ENTRY) */
/*     IISN    -    SAME AS ISN */
/*     ILP     -    SAME AS IPAREA */
/*     INDXPT  -    PTPP INDEX */
/*     INILL   -    INDEX TO ITEM BEING PROCESSED IN ELMENT TABLE */
/*     INP     -    TOTAL NUMBER OF ITEMS IN POTTY ARRAY */
/*     INPOT   -    TOTAL NUMBER OF ITEMS IN IPOTTY ARRAY */
/*     INPTP   -    TOTAL NUMBER OF ITEMS IN PTPP (WORDS,NOT ENTRIES) */
/*     INWORD  -    INPUT ARRAY TO SCAN PROGRAM */
/*     IPAREA  -    INDEX OF LEFT PARENTHESIS IN ELMENT ARRAY */
/*     IPAREB  -    INDEX OF RIGHT PARENTHESIS IN ELMENT ARRAY */
/*     IPAREC  -    NESTING LEVEL IN ELMENT ARRAY */
/*     IPT     -    INPUT ARRAY FOR PTPPUT SUBROUTINE */
/*     IRP     -    SAME AS IPAREB */
/*     ISN      -    INTERNAL STATEMENT NUMBER ASSIGNED BY MONITOR */
/*     LMDW    -    NUMBER OF LOCATIONS USED TO STORE MACRO VARIABLE INF. */
/*     ISTARP  -    STARTING LOCATION OF NEST TO BE PROCESSED */
/*     JLMENT  -    TOTAL NUMBER OF ENTRIES IN ELMENT TABLE */
/*     JSW1    -    SET = 1 IF THERE WERE MACRO VARIABLES IN STATEMENT */
/*     JSW2    -    SET = 1 WHEN A TERMAC IS FOUND AT MACRO DEFN. TIME */
/*     JSW3    -    =1 IF VARIABLE IS SUBSCRIPTED, OTHERWISE = 2 */
/*     LASTCN   -    LAST LOCATION USED IN CANON FOR MACROS (IF NEGATIVE, */
/*                   IT IS A RECORD NUMBER OVERFLOW FILE) */
/*     LEV     -    SAME AS IPAREC */
/*     LIMCAN  -    CURRENT UPPER LIMIT BEING USED IN CANON */
/*     LOCSEQ  -    INDEX OF FIRST WORD OF SEQUENCE FIELD */
/*     LOOP     -    FLAG INDICATING MACRO OR LOOP MODE(= 0 MEANS OFF) */
/*     LPLOCN  -    POINTER IN NEWONE ARRAY */
/*     LPLNGT  -    LENGTH OF ENTRY IN NEWONE ARRAY */
/*     MACCUR  -    CURRENT MACRO NUMBER BEING PROCESSED (LEVEL COUNT) */
/*     MACLCN  -    LOCATION IN MACRO WHERE PROCESSING IS TO RESUME */
/*     MACNAM  -    MACRO NAMES IN NEST */
/*     MACRD   -  MACRO MODE FLAG */
/*           .LT.0  READING FROM INWORD INTO NEWONE (MACRO DEFINITION) */
/*           .EQ.0  NOT IN MACRO MODE */
/*           .GT.0  READING FROM CANON INTO INWORD (PROCESS A MACRO CALL) */
/*     MACSTR  -    STARTING LOCATION IN CANON FOR CURRENT MACRO */
/*     MORPOT  -  FLAG SET IF MORE INF. IS NEEDED IN POTTY ARRAY */
/*     MXLOOP  -    MAXIMUM LENGTH OF LOOP IN NEWONE ARRAY */
/*     NEWONE  -    ARRAY FOR TEMP. STORAGE OF SQUEEZED LOOPS AND MACROS */
/*     NEXTCN   -    NEXT LOCATION IN CANON */
/*     NEXTNW   -    NEXT LOCATION IN NEWONE */
/*     NID     -    COUNT OF STATEMENT IDS */
/*     NMACRO  -    NUMBER OF MACROS IN PART PROGRAM */
/*     NMACVR  -    NUMBER OF MACRO VARIABLES */
/*     NOLIBR  -  =0, LIBRY/LIST STATEMENT REQUIRED FOR SYSTEM MACROS */
/*                =1, NO LIBRY/LIST STATEMENT REQUIRED FOR SYSTEM MACROS */
/*     NWONRD  -  LOOP MODE FLAG CONTROLLING USE OF NEWONE ARRAY */
/*           .LT.0 READING FROM INWORD INTO NEWONE (SQUEEZE, STORE LOOP) */
/*           .EQ.0  NOT IN LOOP MODE */
/*           .GT.0  READING FROM NEWONE INTO INWORD (PROCESSING LOOP) */
/*     PPSEQ1  -    FIRST 6 CHARACTERS OF SEQUENCE NO. (LEFT JUSTIFIED) */
/*     PPSEQ2  -    LAST 2 CHARACTERS OF SEQUENCE NO.  (LEFT JUSTIFIED) */
/*     PT      -    TEMPORARY ARRAY FOR PTPP */
/*     NRELCN  -    RELATIVE LOCN. MACRO COUNTER */
/*     ISCWS   -    SCALR TABLE INDEX */
/*     MAXSCL  -    NUMBER OF SCALAR VARIABLES */
/*     JSW4    -    LOOPST FLAG */
/*     NSURF   -    NESTED SURFACE TABLE INDEX */
/*     KDUM    -    TERMAC PATTERN WORD */
/*     MORE    -    SET TO NON-ZERO WHEN CONTINUATION CARDS REQUIRED */
/*     JSUBER  -    ERROR FLAG */
/*     NAMSUB  -    VST INDEX */
/*     KDMY    -    LOOPND PATTERN WORD */
/*     NODEFX  -  BCD WORD NODEFX */
/*     MAXMV   -  MAXIMUM NO. OF MACRO VARIABLES */
/*     MXNEST  -   MAXIMUM ALLOWABLE LEVEL OF MACRO NESTS */
/*     LOC     -  VST LOCATION COUNTER */
/*     LIMLEV  -  HIGHEST LEVEL OF NEST IN PART PGM. STATEMENT */
/*     INDX    -  NESTING POINTER */
/*     INDXY   -  NESTING POINTER */
/*     LINDX   -  NESTING POINTER */
/*     ITSQ    -  FLAG FOR ASQILT */
/*     ISTRT   -  ELMENT TABLE INDEX */
/*     MAXSLR  -  MAX. NO. OF SCALAR VARIABLES */
/*     KLASS   -  VOCABULARY CLASS */
/*     KLASTP  -  VOCABULARY SUBCLASS */
/*     MAXVS2  -    MAX. SIZE OF VST2 */
/*     INSYN   -    NO. OF ENTRIES IN THE SYN TABLE */
/*     MAXSYN  -    MAX. NO. OF ENTRIES IN THE SYN TABLE */
/*     JGORIT  -    IMPLICIT CHECK SURFACE FLAG */
/*               *          *          *          *          * */
/*               *          *          *          *          * */
/*        SUBROUTINES CALLED BY THE PASS ONE MONITOR */
/*               *          *          *          *          * */
/*               *          *          *          *          * */
/*     AEXPRS  -    PROCESSES ARITH. EXPRESSION FROM ELMENT TABLE */
/*     ACCALL  -    PREPARES PTPP CLASS 17 ENTRIES (SPECIAL PROGRAM CALL) */
/*     ADCLAR  -    SETS UP PTPP POINTER FOR STATEMENT ID */
/*     ADFPRO  -    PREPARES PTPP CLASS 3 (GEOMETRIC SURFAC DEFINITIONS) */
/*     ADIAGP  -    SETS UP PTPP CLASS 2  (DIAGNOSTIC PR2NT) */
/*     ADTEST  -    UPDATES PTPP POINTERS FOR STATEMENT ID */
/*     AFINI   -    COMPUTES TABLE SIZES, WRITES PTPP CLASS 8, CLOSES */
/*                  FILES, ETC. */
/*     AIFUN8  -    CONVERTS FLOATING PT. NUMBER TO BCD */
/*     AINOUT  -    PROCESSES INPUT/OUTPUT AND PREPARES PTPP CLASS E */
/*     AMATMV  -    MOVES A MACRO FROM NEWONE TO CANON */
/*     AMOTIN  -    PREPARES PTPP CLASS 6 FOR MOTION COMMANDS (GOUP, */
/*                  GORGT,ETC.) AND ARELEM PARAMETERS (CUTTER,TOLER,--) */
/*     ANEST   -    SETS UP PROCESSING FOR NESTED DEFINITIONS */
/*     AOBTAN  -    SETS UP PTPP CLASS 9  (OBTAIN) */
/*     APAREN  -    DETERMINES NESTING LEVELS FROM ELMENT TABLE */
/*     APOCK   -    PROCESSES POCKET AND PSIS (SETS UP PTPP CLASS 6) */
/*     APARAM  -    PROCESSES POST PROCESSOR WORDS (SETS UP PTPP CLASS 6) */
/*     APOTLD  -    PREPARES IPOTTY AND POTTY ARRAYS FROM ELMENT TABLE */
/*     APTLD1  -    MAKES ONE ENTRY IN POTTY AND IPOTTY FROM ELMENT TABLE */
/*     APTPUT  -    TRANSFERS AN ARRAY TO THE PTPP TABLE */
/*     AREAD   -    READS CANONICAL FORMS IN TO CORE */
/*     ARFSOS  -    PREPARES PTPP CLASS 4 (REFSYS) */
/*     ASCAN   -    SETS UP ELMENT TABLE FROM INPUT PART PGM. STATEMENT */
/*     ASQEEZ  -    REMOVES BLANKS FROM INPUT PART PROGRAM STATEMENT */
/*     ASQILT  -    REMOVES NESTED DEFINITIONS AND SQUEEZES ELMENT TABLE */
/*     ASWICH  -    MOVES ONE ENTRY FROM POTTY AND IPOTTY TO PTPP TABLE */
/*     AVS1CK  -    CHECKS VST AGAINST THE BCD WORD STORED IN NAME */
/*     AVS1PT  -    ENTERS THE VARIABLE STORED IN NAME IN THE VST */
/*     AZSRF   -    PREPARES PTPP CLASS 16 (ZSURF) */
/*     APRFIX  -    STORES AND ADJUSTS PREFIX IN VST */
/*     APRINT  -    DYNDMP UTILITY TASK SUPERVISOR AND SEQ. SCHEDULER */
/*     ACLAS7  -    PREPARES PTPP CLASS 7  (SEQUENCE NO. AND ID INF.) */
/*     ATABLM  -    CLASSIFIES A WORD */
/*     ANSRF   -    CHECKS FOR EXISTANCE OF A NESTED SURFACE DEFINITION */
/*     AREGPR  -    PROCESSES REGION STATEMENTS */
/*     ADIAGP  -    PREPARES PTPP CLASS 2  (DIAGNOSTICS) */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
    if (ainpot_1.ifirst != a0con_1.k0) {
	goto L60;
    }
/* ...  FIRST ENTRY FOR THIS PART PROGRAM  - INITIALIZE */
/* L50: */
    nmacro = a0con_1.k0;
    amxtab_1.maxvst = 2750;
    amxtab_1.maxvs1 = a0con_1.k1;
    amxtab_1.mxptpp = 2225;
    amotcm_1.multax = 0;
    amxtab_1.maxptp = 0;
    amxtab_1.maxvs2 = a0con_1.k1;
    amxtab_1.mxcan = 2225;
    amxtab_1.mxsrcn = 100;
    amxtab_1.maxslr = 5000;
    amxtab_1.maxelm = 600;
    i__1 = amxtab_1.maxvst;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L55: */
	avst_1.vst[i__ - 1] = 0.;
    }
    alibry_1.irdmod = 0;
    itermf = 0;
    alibry_1.nolibr = 0;
    alibry_1.isysmc = 0;
    abreak_1.isn = a0con_1.k0;
    ascanc_1.jskip = a0con_1.k0;
    amcstf_1.idlocn = a0con_1.k0;
    abreak_1.nwonrd = a0con_1.k0;
    amcstf_1.macrd = 0;
    a1com_1.sum = 0;
    abreak_1.nextnw = amxtab_1.maxvst + 1;
    abreak_1.mxloop = 600;
    a1com_1.debug = a0con_1.k0;
    asyntb_1.insyn = a0con_1.k0;
    aptpp_1.irecn = a0con_1.k0;
    a1com_1.jsuber = a0con_1.k0;
    amacro_1.limcan = amxtab_1.maxvst + amxtab_1.mxptpp;
    asyntb_1.maxsyn = 100;
    amxtab_1.maxtab = 7200;
    nmacro = a0con_1.k0;
    abreak_1.nrelcn = amxtab_1.maxvst + 1;
    aptpp_1.nw = a0con_1.k0;
    amacro_1.macrec = 1;
    abreak_1.jsav = a0con_1.k0;
    ascalr_1.iscws = a0con_1.k1;
    amxtab_1.maxscl = a0con_1.k0;
    abreak_1.maxmv = 50;
    abreak_1.mxnest = a0con_1.k5;
    abreak_1.nextcn = a0con_1.k1;
    a1com_1.loop = a0con_1.k0;
    a1com_1.indxpt = amxtab_1.maxvst + 2;
    amcstf_1.maccur = a0con_1.k0;
    abreak_1.lplocn = 0;
    abreak_1.jsw2 = a0con_1.k0;
    abreak_1.jsw4 = a0con_1.k1;

L60:
    ascalr_1.nsurf = 1;
    ascalr_1.iscws = 1;
    iscwsl = 1;
/* ...  GO GET A CARD */
    amon1_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }

/* ...  BREAK UP CARD AND PUT IN ELMENT TABLE */
/* L220: */
    ascan_();
/* ...     TEST FOR CONTINUATION */
    if (ainpot_1.more > 0) {
	goto L235;
    }
/* ...     NEXT CARD NOT CONTINUATION - THIS IS LAST CARD OF STATEMENT */
    nmore = 0;
/* ...     IF NO MATERIAL FOUND ON CARD, GO TO GET NEXT ONE */
    if (ailmtb_1.jlment == 0) {
	goto L228;
    }
/* ...     TEST FOR **FINI** RECOGNITION */
    goto L5000;
L225:
    if (ascanc_1.jskip == 0) {
	goto L230;
    }
/* ...  THERE WAS AN ELMENT TABLE OVERFLOW - DELETE PROCESSING */
L228:
    ascanc_1.jskip = 0;
    goto L60;
L230:
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L260;
    }

/* ...     STATEMENT CONTINUED ON FOLLOWING CARD(S) */
L235:
    if (abreak_1.jsav != 0) {
	goto L60;
    }
    if (nmore != 0) {
	goto L240;
    }
/* ...     FIRST CARD OF CONTINUED STATEMENT */
    nmore = 1;
    mitebe = abreak_1.nextnw;
    if (amcstf_1.macrd >= 0) {
	goto L250;
    } else {
	goto L610;
    }

L240:
    if (ascanc_1.jskip == 0) {
	goto L245;
    }
/* ...  ELMENT TABLE OVERFLOW */
    abreak_1.nextnw = mitebe;
    goto L255;

L245:
    if (amcstf_1.macrd >= 0) {
	goto L250;
    } else {
	goto L630;
    }

L250:
    if (abreak_1.nwonrd < 0) {
	goto L630;
    }
L255:
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L60;
    }

/* ...     PRINT OUT ICLASS AND ELMENT ARRAYS IF DEBUG FLAG SET */
L260:
//	a1com_1.debug=1;//**
	//a1com_1.debug=2;//**
    aprint_(&c__1);
/* ...     TEST FOR STATEMENT ENDING IN PUNCTUATION */
    if (iatype_(&ailmtb_1.jlment) != a0con_1.k4) {
	goto L280;
    }
/* ...    YES - ONLY ) AND / PERMITTED TO TERMINATE STATEMENT */
    if (ibclas_(&ailmtb_1.jlment) == a0con_1.k7) {
	goto L280;
    }
    if (ibclas_(&ailmtb_1.jlment) == a0con_1.k3) {
	goto L280;
    }
/* ...     ILLEGAL PUNCTUATION TERMINATING STATEMENT */
L270:
    a1com_1.jsuber = 11;
    goto L998;
L280:
    if (a1com_1.loop == 0) {
	goto L320;
    }
/* L290: */
    if (amcstf_1.macrd < 0) {
	goto L460;
    } else if (amcstf_1.macrd == 0) {
	goto L300;
    } else {
	goto L740;
    }
L300:
    if (abreak_1.nwonrd < 0) {
	goto L460;
    } else if (abreak_1.nwonrd == 0) {
	goto L310;
    } else {
	goto L320;
    }
/* .. PROCESSING ERROR, FORCE END OF PASS1 PROCESSING */
L310:
    a1com_1.jsuber = 6102;
    adiagp_();
    goto L5050;
/* ... */
/* ...  PROCESS STATEMENT ID, IF ANY */
L320:
    amon2_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    if (abreak_1.k + 1 == ailmtb_1.jlment) {
	goto L270;
    }
    goto L1010;
L460:
    amon3_();
    if (abreak_1.k + 1 == ailmtb_1.jlment) {
	goto L270;
    }
    if (a1com_1.jsuber == 0) {
	goto L610;
    }
    adiagp_();

/* ...     TEST FOR 'TERMAC' AT TIME MACRO IS DEFINED */
L610:
    if (ibclas_(&abreak_1.k) != adata1_1.ntrmac) {
	goto L630;
    }
/* ...     'TERMAC' FOUND - MAKE SURE A MACRO IS BEING */
/* ...     DEFINED - OTHERWISE ERROR */
    itermf = 1;
    if (amcstf_1.macrd < 0) {
	goto L620;
    }
    itermf = 0;
    a1com_1.jsuber = 209;
    goto L998;
/* ...     SET FLAG FOR TERMAC FOUND */
L620:
    abreak_1.jsw2 = 1;
/* ...  PROCESS TERMAC */
L630:
    amon4_();
/* ...  BRANCH IF READING FROM SYSTEM MACRO LIBRARY */
    if (itermf != 1) {
	goto L635;
    }
    itermf = 0;
    if ((i__1 = alibry_1.irdmod + 1) < 0) {
	goto L650;
    } else if (i__1 == 0) {
	goto L640;
    } else {
	goto L635;
    }
L635:
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L60;
    }
L640:
    alibry_1.irdmod = 0;
    if (a1com_1.jsuber == 0) {
	goto L645;
    }
    adiagp_();
L645:
    amon7_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L60;
    }

/* ...     INCREMENT SYSTEM MACRO NAME SCANNING INDEX */
L650:
    amxtab_1.maxpot += 2;
/* ...     TEST FOR ALL SYSTEM MACROS READ IN FROM LIBRARY */
    if (amxtab_1.maxpot > amxtab_1.maxvs) {
	goto L660;
    }
/* ...     NO - PICK UP NAME OF NEXT TO BE READ */
    alibry_1.segnam = avst_1.vst[amxtab_1.maxpot - 1];
    avst_1.vst[amxtab_1.maxpot - 1] = adata1_1.blanks;
    goto L60;
/* ...     ALL MACROS READ IN - CANCEL FLAG FOR OPERATION */
L660:
    alibry_1.irdmod = 0;
    goto L60;

/* ...     MACRO BEING EXECUTED... */
/* ...     SUBSTITUTE VALUES FOR MACRO VARIABLES */
L740:
    amon5_(&kret);
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...     IF TERMAC JUST PROCESSED, GO TO GET NEXT STATEMENT */
    if (kret == 1) {
	goto L60;
    }

/* ...     MUST HAVE AT LEAST 3 CODES IF STATEMENT IS 'SYM = MACRO...' */
L1010:
    if (ailmtb_1.jlment < abreak_1.k + 2) {
	goto L1020;
    }
/* ...     TEST FOR START OF MACRO */
    i__1 = abreak_1.k + 2;
    if (ibclas_(&i__1) == adata1_1.macro) {
	goto L1080;
    }
/* ...     TEST FOR START OF LOOP */
L1020:
    if (ibclas_(&abreak_1.k) != adata1_1.loopst) {
	goto L1310;
    }

/* ...     LOOPST FOUND - ARE WE ALREADY PROCESSING (NOT DEFINING) A LOOP */
/* L1030: */
    if (abreak_1.jsw4 != 0) {
	goto L1050;
    }
/* ...     YES - ERROR */
/* L1040: */
    a1com_1.jsuber = 206;
    goto L998;
/* ...     IF IN NORMAL MODE, SET UP TO DEFINE A LOOP */
L1050:
    if (a1com_1.loop == 1) {
	goto L1070;
    }

/* ...  SET UP TO READ IN LOOP */
/* L1060: */
    abreak_1.nwonrd = -1;
    amcstf_1.numids = 0;
    amcstf_1.idlocn = amxtab_1.maxvs1 + 2;
    a1com_1.loop = 1;
/* L1065: */
    aptpp_1.jmode = 6;
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* .. SET LOOP FLAG FOR PASS TWO */
    ipt[OTHER_ENDIAN_S(0)] = 19;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    ipt[OTHER_ENDIAN_S(2)] = 0;
    ipt[OTHER_ENDIAN_S(3)] = 1;
    aptpp_1.inptp = 2;
    aptpp_1.jmode = 5;
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    goto L460;

L1070:
    aklas7_1.kfk = 2;
    aclas7_();
    goto L60;

/* ...  PROCESS MACRO DEFINITION STATEMENT (A=MACRO/ ETC.) */
L1080:
    amon6_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L60;
    }

L1310:
    if (ibclas_(&abreak_1.k) != adata1_1.ncall) {
	goto L1750;
    }

/* ...  PROCESSING A CALL */
/* L1320: */
    i__1 = abreak_1.k + 1;
    if (iatype_(&i__1) == a0con_1.k4) {
	goto L1340;
    }
/* ...  MUST BE A / */
L1330:
    a1com_1.jsuber = 227;
    goto L998;
L1340:
    i__1 = abreak_1.k + 1;
    if (ibclas_(&i__1) != a0con_1.k3) {
	goto L1330;
    }
/* L1350: */
    if (abreak_1.k + 4 > ailmtb_1.jlment) {
	goto L1370;
    }
    i__1 = abreak_1.k + 4;
    kat = iatype_(&i__1);
/* L1360: */
    switch ((int)kat) {
	case 1:  goto L1370;
	case 2:  goto L1730;
	case 3:  goto L1740;
	case 4:  goto L1740;
    }

/* ...     PROCESS A MACRO CALL */
L1370:
    amon7_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    } else {
	goto L60;
    }

/* ...  SPECIAL PROGRAM CALL - PROCESS LATER */
/* ...     TEST FOR VOCAB. WORDS 'SEC1', 'SEC2' - NOT */
/* ...     PERMITTED AT THIS TIME */
L1730:
    i__2 = abreak_1.k + 4;
    i__1 = ibclas_(&i__2);
    if (aextra_(&i__1, &a0con_1.k2) == 31) {
	goto L1750;
    }

L1740:
    a1com_1.jsuber = 226;
    goto L998;

/* ...  OUTPUT A PTPP CLASS 7 FOR THIS STATEMENT */
L1750:
    abreak_1.kf = abreak_1.k;
    abreak_1.inill = abreak_1.k;
    aprtab_1.istarp = abreak_1.k;
    jinill = (aprtab_1.istarp << 2) - 3;
    aprtab_1.iendp = ailmtb_1.jlment;
/* ...     STATEMENT MUST START WITH VARIABLE SYMBOL OR VOCAB. WORD */
    if (ailmtb_1.iclass[abreak_1.inill - 1] == 1) {
	goto L1751;
    }
    aptpp_1.klass = 0;
    glass[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(jinill + 2)];
    if (aptpp_1.klass == 2) {
	goto L1753;
    }
/* ...     IT DID NOT - ERROR */
    a1com_1.jsuber = 5;
    goto L998;

/* ...     STATEMENT STARTS WITH VOCABULARY WORD - EXTRACT TYPE CODE */
L1753:
    i__1 = ibclas_(&abreak_1.inill);
    aptpp_1.klass = aextra_(&i__1, &a0con_1.k2);
    if (aptpp_1.klass != 7) {
	goto L1754;
    }
    aklas7_1.iisn = -aklas7_1.iisn;
L1754:
    switch ((int)aptpp_1.klass) {
	case 1:  goto L2450;
	case 2:  goto L1752;
	case 3:  goto L1752;
	case 4:  goto L1751;
	case 5:  goto L1751;
	case 6:  goto L1751;
	case 7:  goto L1752;
	case 8:  goto L1751;
	case 9:  goto L1751;
	case 10:  goto L1751;
	case 11:  goto L1751;
	case 12:  goto L1752;
	case 13:  goto L1752;
	case 14:  goto L1759;
	case 15:  goto L1759;
	case 16:  goto L1751;
	case 17:  goto L1751;
	case 18:  goto L1752;
	case 19:  goto L1759;
	case 20:  goto L1752;
	case 21:  goto L1752;
	case 22:  goto L1752;
	case 23:  goto L1752;
	case 24:  goto L1759;
	case 25:  goto L1759;
	case 26:  goto L1752;
	case 27:  goto L1752;
	case 28:  goto L1759;
	case 29:  goto L1759;
	case 30:  goto L1759;
	case 31:  goto L1759;
	case 32:  goto L1752;
	case 33:  goto L1759;
	case 34:  goto L1759;
	case 35:  goto L1785;
    }
L1751:
    aklas7_1.kfk = 1;
    goto L1755;
L1752:
    aklas7_1.kfk = 2;
L1755:
    aclas7_();

/* ...  CHECK FOR PARENTHESIS */
L1759:
    aparen_();
    if ((i__1 = apartb_1.ilpcnt - apartb_1.irpcnt) < 0) {
	goto L1780;
    } else if (i__1 == 0) {
	goto L1760;
    } else {
	goto L1770;
    }
L1770:
    a1com_1.jsuber = 10;
    goto L998;
L1780:
    a1com_1.jsuber = 9;
    goto L998;
L1785:
    klment = 0;
    goto L2500;

/* ...     TEST TYPE OF FIRST ENTRY IN STATEMENT TO DETERMINE WHETHER */
/* ...     OR NOT IT IS AN ASSIGNMENT STATEMENT */
L1760:
    if (ailmtb_1.iclass[abreak_1.inill - 1] == 1) {
	goto L1800;
    }
/* ...     NOT AN ASSIGNMENT - TEST FOR NESTS IN THE STATEMENT */
    if (apartb_1.ilpcnt == 0) {
	goto L1980;
    }
/* ...     PROCESS NESTS AND ASSIGNMENT STATEMENTS */
L1800:
    amon8_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...     IF FIRST WORD OF STATEMENT IS VOCAB., IT IS NOT YET PROCESSED */
L1980:
    aptpp_1.klass = 0;
    glass[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(jinill + 2)];
    if (aptpp_1.klass != 2) {
	goto L60;
    }

L2450:
    abreak_1.k = abreak_1.inill;
    klment = ailmtb_1.jlment;
L2460:
    aprtab_1.istarp = abreak_1.inill;

/* ...     EXTRACT ICLASS TYPE AND SUBTYPE CODES FROM VOCAB. ENTRY */
    aptpp_1.klass = 0;
    aptpp_1.klastp = 0;
    glass[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(jinill + 1)];
    glastp[OTHER_ENDIAN_W(3)] = lclas1[OTHER_ENDIAN_W(jinill)];
    aprint_(&c__8);

/* ...     BRANCH ON VOCABULARY CLASS CODE TO AMON10 OR AMON11 - */
/* ...     THESE 2 ROUTINES CALL APPROPRIATE PROGRAMS TO PROCESS */
/* ...     THE VARIOUS TYPES OF STATEMENTS */
    if (aptpp_1.klass == 3) {
	goto L2470;
    }
    if (aptpp_1.klass == 23) {
	goto L2470;
    }
    if (aptpp_1.klass == 25) {
	goto L2470;
    }
    if (aptpp_1.klass != 27) {
	goto L2480;
    }
L2470:
    if (klment == abreak_1.k) {
	goto L2480;
    }
    if (ailmtb_1.iclass[abreak_1.k] != adata1_1.ncomma) {
	goto L2480;
    }
    ailmtb_1.jlment = abreak_1.k;
    if (a1com_1.debug == 0) {
	goto L2490;
    }
    io___18.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___18);
    do_fio(&c__1, (char *)&ailmtb_1.iclass[abreak_1.k - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&c__1, (char *)&ailmtb_1.elment[abreak_1.k - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L2490;
L2480:
    klment = 0;
/* ...  CHECK FOR OBTAIN STATEMENT */
L2490:
    if (aptpp_1.klass == 5) {
	goto L2495;
    }
/* ...  NOT OBTAIN - CHECK FOR FIXED FIELD WORDS */
    if (aptpp_1.klass == 1) {
	goto L2495;
    }
/* ...   NOT FIXED FIELD -   CHECK FOR MORE THAN ONE ENTRY */
    if (abreak_1.inill == ailmtb_1.jlment) {
	goto L2494;
    }
/* ...  MORE THAN ONE ENTRY - BRANCH OUT IF IT IS AN IF STATEMENT */
    if (aptpp_1.klass == 9) {
	goto L2495;
    }
/* ...     NOT 'IF' STATEMENT - VERIFY THAT SLASH FOLLOWS IF A MAJOR WORD */
    if (aptpp_1.klass == 29) {
	goto L2492;
    }

//	debuggg=SWTCH_ENDIAN_INT_SHRT( SWTCH_ENDIAN_INT_SHRT_LW(islash));
//	debuggg=SWTCH_ENDIAN_INT_SHRT( (islash));

//	debuggg2=ailmtb_1.iclass[abreak_1.inill] ;
    if (ailmtb_1.iclass[abreak_1.inill] == islash) {
	goto L2492;
    }
/* ...  ILLEGAL STATEMENT FORMAT  -  PUNCTUATION ERROR */
/* L2491: */
    a1com_1.jsuber = 155;
    goto L998;
L2492:
    if (abreak_1.inill + 2 >= ailmtb_1.jlment) {
	goto L2494;
    }
/* ...     CHECK FOR TYPE CODE OF INDIRV, INDIRP, AND SRFVCT STATEMENTS */
    if (aptpp_1.klass != 26) {
	goto L2493;
    }
/* ...     IT IS THE RIGHT TYPE - CHECK FOR INDIVIDUAL SUBTYPES */
    if (aptpp_1.klastp == 9) {
	goto L2500;
    }
/* ...     NOT INDIRP - TRY INDIRV... */
    if (aptpp_1.klastp == 10) {
	goto L2500;
    }
/* ...     ...AND SRFVCT */
    if (aptpp_1.klastp == 14) {
	goto L2500;
    }
/* ...     MAKE SURE A COMMA IS THE ONLY PUNCTUATION USED AS A SEPARATOR */
L2493:
    adclar_(&abreak_1.inill, &ailmtb_1.jlment);
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
L2494:
    if (aptpp_1.klass > 10) {
	goto L2500;
    }
L2495:
    amon10_();
    goto L2510;

L2500:
    amon11_();
L2510:
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    if (klment <= 0) {
	goto L60;
    }
    abreak_1.inill += 2;
    jinill += 8;
    abreak_1.k = abreak_1.inill;
    if (iatype_(&abreak_1.k) != 2) {
	goto L997;
    }
    ailmtb_1.jlment = klment;
    goto L2460;

L997:
    a1com_1.jsuber = 81;
L998:
    adiagp_();
    goto L60;

/* .. */
/* ... TEST FOR FINI, CAN NOT RECOGNIZE IF MISSPELLED */
L5000:
    kend = ailmtb_1.jlment << 2;
/* .. */
    i__1 = kend;
    for (lcls = 3; lcls <= i__1; lcls += 4) {
	if (lclas1[OTHER_ENDIAN_W(lcls - 1)] == 18) {
	    goto L5020;
	}
/* .. */
L5010:
	;
    }
    goto L225;
/* .. IS THIS  A VOCABULARY WORD */
L5020:
    if (lclas1[OTHER_ENDIAN_W(lcls)] != 2) {
	goto L5010;
    }
/* .. THIS IS A FINI    ,, IT MAY HAVE A STMT. I.D. */
    amon2_();
    if (a1com_1.jsuber == 0) {
	goto L5045;
    }
    adiagp_();
/* .. DEFINING A LOOP OR MACRO */
L5045:
    if (amcstf_1.macrd == 0) {
	goto L5050;
    }
    a1com_1.jsuber = 16;
    adiagp_();
/* .. IS FINI THE ONLY ENTRY FOR THIS STATEMENT */
L5050:
    if (ailmtb_1.jlment == 1) {
	goto L5060;
    }
    if (ailmtb_1.jlment != 3) {
	goto L5070;
    }
    if (lclas1[OTHER_ENDIAN_W(6)] != 7) {
	goto L5070;
    }
    if (lclas1[OTHER_ENDIAN_W(7)] != 4) {
	goto L5070;
    }
L5060:
    afini_();
/* .. */
/* ..    ILLEGAL   F I N I  FORMAT */
L5070:
    a1com_1.jsuber = 23;
    adiagp_();
    goto L5060;
} /* amontr_ */

#undef ipt
#undef glastp
#undef lment4
#undef lclas1
#undef glass
#undef vst4

