/* AMON11.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[6];
} asistm_;

#define asistm_1 asistm_

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
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    doublereal synb[100];
    integer insyn, maxsyn;
} asyntb_;

#define asyntb_1 asyntb_

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
    integer ilpcnt, irpcnt, ilvcnt;
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
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

static struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__9 = 9;

/* Subroutine */ int amon11_()
{
    /* Initialized data */

    static struct {
	char e_1[112];
	doublereal e_2;
	} equiv_37 = { {'!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ',
		 ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' '}, 0. };

#define aliber ((doublereal *)&equiv_37)

    static struct {
	char e_1[56];
	doublereal e_2;
	} equiv_38 = { {'!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ',
		 ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0. };

#define awrong ((doublereal *)&equiv_38)

    static struct {
	char e_1[56];
	doublereal e_2;
	} equiv_39 = { {'!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ',
		 ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0. };

#define anerr ((doublereal *)&equiv_39)

    static struct {
	shortint e_1;
	} equiv_4 = { 0 };


    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
#define gbrn ((logical1 *)&equiv_4)
#define jbrn ((shortint *)&equiv_4)
    static integer ngot;
#define ivst ((integer *)&avst_1)
    static integer lmen4;
    static doublereal a;
    static integer i__, j, n, slash;
#define ksynb ((shortint *)&asyntb_1)
    static integer ijazz;
    extern /* Subroutine */ int aclas7_();
    static integer insto;
    extern /* Subroutine */ int apock1_();
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
#define lclas2 ((shortint *)&ailmtb_1 + 2400)
    extern /* Subroutine */ int avs1ck_(), aifun8_();
#define lment2 ((shortint *)&ailmtb_1)
    static integer jtemp1;
    extern /* Subroutine */ int avs1pt_(), adiagp_();
    static integer jf, in;
    extern integer amdtoa_(), aextra_();
#define errtap ((doublereal *)&ataptb_1 + 9)
    static integer icomma;
    extern /* Subroutine */ int aptput_(), atapop_();
    static integer ioflag;
    extern /* Subroutine */ int ahelpr_(), amotin_(), aflags_();
    extern integer ibclas_();
    static integer nv, nn, it;
#define ipt ((integer *)&aptpp_1)
    extern /* Subroutine */ int aprint_();
    static integer npj, nky;
    extern /* Subroutine */ int aparam_(), aptlod_(), aregpr_();
    static integer mvsave, izw, mpsave, mcsave, icl2;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*       INTEGER*2 JBRN/0/,KSYNB(400),LCLAS2(1200),LMENT2(2400) */
/*     THIS PROGRAM PROCESSES VOCABULARY CLASSES 11 THRU 32 */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
/*      DIMENSION AWRONG(7),ANERR(7),ALIBER(14) */
/*      DATA ALIBER/' THE LIBRY STATEMENT WITHIN A SEGMENT READ WILL CAUSE */
/*     1 THE SYSTEM MACROS TO BE   READ IN AT TIME OF FIRST CALL   '/ */
/*      DATA AWRONG/' THIS VOCABULARY WORD NOT IMPLEMENTED IN THIS PROCESS */
/*     1OR '/ */
/*      DATA  ANERR/' INCORRECT TUNEUP FORMAT.  MUST BE TUNEUP/VST,PTPP,CA */
/*     1NON'/ */

/*       INTEGER SLASH/Z00000304/,ICOMMA/Z00000904/ */
	slash=0x304;
	icomma=0x904;
/* ...  SET FLAG JBRN EQUAL VOC.CLASS AND BRANCH ON VALUE */
    *jbrn = (shortint) (aptpp_1.klass - 10);
/* ...    THE BRANCH ON JBRN < 0 IS NEVER TAKEN. THE STATEMENT PREVENTS */
/*       COMPILER ERROR WHEN LIBRY PROCESS STATEMENTS ARE DISABLED */
    if (*jbrn < 0) {
	goto L8000;
    }
    switch ((int)*jbrn) {
	case 1:  goto L3320;
	case 2:  goto L3340;
	case 3:  goto L3345;
	case 4:  goto L3330;
	case 5:  goto L3360;
	case 6:  goto L3570;
	case 7:  goto L3760;
	case 8:  goto L3950;
	case 9:  goto L4000;
	case 10:  goto L4010;
	case 11:  goto L4170;
	case 12:  goto L4170;
	case 13:  goto L4170;
	case 14:  goto L4000;
	case 15:  goto L4180;
	case 16:  goto L4295;
	case 17:  goto L4295;
	case 18:  goto L4300;
	case 19:  goto L4000;
	case 20:  goto L4000;
	case 21:  goto L4000;
	case 22:  goto L4325;
	case 23:  goto L5000;
	case 24:  goto L6000;
	case 25:  goto L7000;
    }

/* ...     LOOPST - LOOPND (CLASS 11) */
L3320:
    switch ((int)aptpp_1.klastp) {
	case 1:  goto L3330;
	case 2:  goto L3337;
    }
/* ...  LOOPND - RESET FLAGS AND RETURN FOR MORE INPUT */
L3337:
    if (a1com_1.loop != 0) {
	goto L3338;
    }
/* ...  LOOPND FOUND WITHOUT A CORRESPONDING LOOPST */
    a1com_1.jsuber = 208;
    goto L998;
/* ...  THIS IS THE END OF LOOP MODE - TURN MODE FLAG OFF */
L3338:
    a1com_1.loop = 0;
    abreak_1.nwonrd = 0;
/* ...     TURN OFF LOOP MODE FLAG FOR PASS TWO */
    ipt[OTHER_ENDIAN_S(0)] = 19;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    aptpp_1.pt[1] = (float)0.;
    aptpp_1.inptp = 2;
    aptpp_1.jmode = 5;
    aptput_();
    abreak_1.jsw4 = 1;
/* ...  REWIND ERRTAP */
    atapop_(errtap, &c__1, &ioflag);
    goto L60;

L3330:
    a1com_1.jsuber = 209;
    goto L998;

/* ...     POCKET (CLASS 12) */
L3340:
    apock1_();
    goto L60;

/* ...     PSIS (CLASS 13) */
/* ...     CHECK FOR IMPLICIT NESTED PLANE DEFINITION */
L3345:
    ahelpr_(&abreak_1.inill);
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    amotin_();
    goto L60;

/* ...     DEBUG, DYNDMP (CLASS 15) */
L3360:
    switch ((int)aptpp_1.klastp) {
	case 1:  goto L3500;
	case 2:  goto L3370;
    }
/* ...  DYNDMP */
L3370:
    aklas7_1.kfk = 2;
/* ...  GENERATE A PTPP CLASS 7 RECORD */
    aclas7_();
/* ...  TRANSFER DYNDMP STATEMENT FROM ELMENT TO IPOTTY */
/* ...  GENERATE A CLASS 6 PTPP RECORD AND SET UP ARELEM FLAGS */
    aflags_();
    goto L998;
/* ...  DEBUG */
L3500:
    aklas7_1.kfk = 1;
    aclas7_();
/* ...  SET LOCATION OF SLASH */
    n = abreak_1.inill + 1;
    nky = n + 3;
/* ...  SET UP FLAG TO OUPUT A DEBUG RECORD FOR A SINGLE SECTION ONLY */
    ngot = 1;
/* ...  IS 1ST PARAMETER FOLLOWING SLASH APT MODIFIER ON  OR OFF */
    i__2 = n + 1;
    i__1 = ibclas_(&i__2);
    if (aextra_(&i__1, &c__2) == 29) {
	goto L3530;
    }
    i__2 = n + 1;
    i__1 = ibclas_(&i__2);
    if (aextra_(&i__1, &c__2) != 31) {
	goto L3550;
    }
/* ...  STATEMENT IS OF THE FORM  DEBUG/SECX, ON  -DETERMINE VALUE OF X */
/* ...  BRANCH IF DEBUG IS FOR SECTION 1 */
    i__2 = n + 1;
    i__1 = ibclas_(&i__2);
    if (amdtoa_(&i__1, &c__2) == 1) {
	goto L3535;
    }
    i__2 = n + 1;
    i__1 = ibclas_(&i__2);
    if (amdtoa_(&i__1, &a0con_1.k2) != a0con_1.k2) {
	goto L3550;
    }
/* .... OUTPUT SECTION TWO DEBUG FLAG */
/* ...  TEST 2ND PARAM FOR ON OR OFF CONDITION */
L3510:
    i__1 = ibclas_(&nky);
    if (aextra_(&i__1, &c__2) != 29) {
	goto L3550;
    }
/* ...  BRANCH IF OFF SPECIFIED */
    i__1 = ibclas_(&nky);
    if (amdtoa_(&i__1, &c__2) == 72) {
	goto L3515;
    }
/* ...  ONLY MINOR MODIFIER  ON  ALLOWED */
    i__1 = ibclas_(&nky);
    if (amdtoa_(&i__1, &c__2) != 71) {
	goto L3550;
    }
/* .... SET SWITCH FOR ON */
    izw = 1;
    goto L3520;
/* .... SET SWITCH FOR OFF */
L3515:
    izw = 0;
/* ..   SET UP PTPP INTEGER PARAMETERS  PTPP(1) = C,N */
L3520:
    ipt[OTHER_ENDIAN_S(0)] = 6;
    ipt[OTHER_ENDIAN_S(1)] = 4;
/* ...  PTPP(2) = NPT,NPR */
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 1;
/* ...  PTPP(3) = CL,SC */
    ipt[OTHER_ENDIAN_S(4)] = 13000;
    ipt[OTHER_ENDIAN_S(5)] = 1;
/* ...  PTPP(4) = I,J DESCRIBE 1ST PARAM TO RITE OF SLASH */
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
/* ...  PTPP(5) = K,L DESCRIBE 1ST PARAM TO RITE OF SLASH */
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = izw;
/* ...  SET INPUT VAR. TO APTPUT TO INDICATE A NORMAL TYPE OF MOVE TO PTPP */
    aptpp_1.jmode = 5;
    aptpp_1.inptp = 5;
L3525:
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
    --ngot;
    if (ngot <= 0) {
	goto L60;
    } else {
	goto L3510;
    }

/* .... OUTPUT DEBUG FLAG FOR BOTH SECTIONS */
L3530:
    ngot = 2;
/* ...  SET POINTER TO PROCESS PARAMETER THAT IMMEDIATELY FOLLOWS SLASH */
    nky += -2;
/* ...  ONLY MODIFIER WORD ON OR OFF ALLOWABLE */
L3535:
    i__1 = ibclas_(&nky);
    if (aextra_(&i__1, &a0con_1.k2) != 29) {
	goto L3550;
    }
    i__1 = ibclas_(&nky);
    if (amdtoa_(&i__1, &a0con_1.k2) == 72) {
	goto L3540;
    }
/* ...  ON IS ONLY ALLOWABLE PARAMETER NOW */
    i__1 = ibclas_(&nky);
    if (amdtoa_(&i__1, &c__2) != 71) {
	goto L3550;
    }
/* .... SET DEBUG ON FOR SECTION ONE */
    a1com_1.debug = 1;
/* ...  SET UP A CLASS 8 PTPP RECORD  FOR DEBUG SECTION 1 */
    ipt[OTHER_ENDIAN_S(1)] = 1;
    goto L3545;
/* .... SET DEBUG OFF FOR SECTION ONE */
L3540:
    a1com_1.debug = 0;
/* ...  SET UP A CLASS 8 PTPP RECORD - DEBUG -DEBUG/SEC1,OFF */
    ipt[OTHER_ENDIAN_S(1)] = 2;
L3545:
    ipt[OTHER_ENDIAN_S(0)] = 8;
    n = 1;
/* ...  NO. OF 8 BYTE WORDS IN PT TO BE MOVED TO PTPP */
    aptpp_1.inptp = 1;
/* ...  CALL APTPUT TO MOVE STMT IN PT TO THE PTPP TABLE */
    goto L3525;
/* ...  ILLEGAL DEBUG FORMAT */
L3550:
    a1com_1.jsuber = 22;
    goto L998;

/* ...     RESERV (CLASS 16) */
L3570:
    if (a1com_1.loop == 0) {
	goto L3590;
    }
/* ...  RESERV NOT ALLOWED IN A LOOP OR MACRO */
/* L3580: */
    a1com_1.jsuber = 252;
    goto L998;
/* ...  CHECK FORMAT FOR SLASH FOLLOWING MAJ. WD. */
L3590:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
/* ...  SET LOC. OF 1ST PARAMETER FOLLOWING SLASH */
/* L3610: */
    n = abreak_1.inill + 2;
    jtemp1 = (n << 2) - 3;
    gbrn[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 2)];
/* ...  CHECK ORDER - IS IT A,50 OR 50,A */
L3620:
    switch ((int)*jbrn) {
	case 1:  goto L3640;
	case 2:  goto L3630;
	case 3:  goto L3670;
    }
/* ...  ONLY A VAR. SYMB. OR A NUMBER IS ACCEPTABLE */
L3630:
    a1com_1.jsuber = 253;
    goto L998;
/* ...  FORMAT MUST BE  RESERV/A,X  -ILLEGAL IF X IS NOT A FL.PT.NO. */
L3640:
    if (ailmtb_1.iclass[n + 1] == 3) {
	goto L3660;
    }
/* ...  VALUE NOT FOUND - FORMAT ERROR EXISTS */
/* L3650: */
    a1com_1.jsuber = 255;
    goto L998;
/* ...  LEGAL FORMAT  -  PROCESS RESERV/A,50 */
/* ...     NV IS SET EQUAL VAR.NAME, AND, NN IS SET EQUAL NUMERIC NUMBER */
L3660:
    nv = n;
    nn = n + 2;
    goto L3700;
/* ...  1ST PARAMETER IS A NUMBER - 2ND  MUST BE A VAR.SYMBOL */
L3670:
    if (ailmtb_1.iclass[n + 1] == 1) {
	goto L3690;
    }
/* ...  DID NOT FIND PROPER ARRAY NAME */
/* L3680: */
    a1com_1.jsuber = 254;
    goto L998;
/* ...  LEGAL FORMAT  -  PROCESS  RESERV/50,A */
L3690:
    nv = n + 2;
    nn = n;
/* ...  CHECK FOR COMMA SEPARATING PARAMETERS */
L3700:
    if (ailmtb_1.iclass[n] == icomma) {
	goto L3730;
    }
/* ...  NO COMMA */
L3710:
    a1com_1.jsuber = 7;
    goto L998;
/* ...  ENTER NAME IN VST */
L3730:
    a1com_1.name__ = ailmtb_1.elment[nv - 1];
/* ...     MAKE SURE THIS IS A VARIABLE SYMBOL */
    if (ailmtb_1.iclass[nv - 1] == 1) {
	goto L3735;
    }
    a1com_1.jsuber = 253;
    goto L3748;
L3735:
    avs1pt_(&j);
    if (j == 1) {
	goto L3750;
    }
/* L3740: */
    a1com_1.jsuber = 256;
L3745:
    a1com_1.sum = 1;
L3748:
    adiagp_();
    goto L3755;
/* ...     TEST FOR ROOM FOR ARRAY */
L3750:
    it = (integer) ailmtb_1.elment[nn - 1];
    if (amxtab_1.maxvs1 + amxtab_1.maxvs2 + it > amxtab_1.maxvst) {
	goto L3756;
    }
/* ...     UPDATE VST REFERENCE */
    jtemp1 = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = amxtab_1.maxvs2;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = -it;
    amxtab_1.maxvs2 += it;
L3755:
    n += 4;
    if (n <= ailmtb_1.jlment) {
	goto L3620;
    }
    goto L60;
/* ...     NOT ENOUGH ROOM FOR ARRAY */
L3756:
    a1com_1.jsuber = 15;
    goto L3745;

/* ...     SYN (CLASS 17) */
L3760:
    if (a1com_1.loop == 0) {
	goto L3780;
    }
/* ...  SYN NOT ALLOWED IN LOOP OR MACRO */
/* L3770: */
    a1com_1.jsuber = 353;
    goto L998;
/* ...  FORMAT CHECK -IS SLASH FOLLOWING MAJ WORD  SYN */
L3780:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
/* ...  SET POINTER TO LOC. OF SLASH */
/* L3800: */
    n = abreak_1.inill + 1;
L3810:
    if (n < ailmtb_1.jlment) {
	goto L3820;
    }
/* ...  PRINT OUT SYN TABLE */
    aprint_(&c__9);
    goto L60;
/* ...  PROCESS A SYN PAIRED ENTRY */
L3820:
    ++n;
    if (n < ailmtb_1.jlment) {
	goto L3840;
    }
/* L3830: */
    a1com_1.jsuber = 351;
    goto L998;
/* ...  CHECK ORDER - IS IT VAR. SYMBOL, VOCAB. OR VOCAB, VAR. SYMBOL */
L3840:
    jtemp1 = (n << 2) - 3;
    gbrn[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 2)];
    if ((i__1 = *jbrn - 2) < 0) {
	goto L3855;
    } else if (i__1 == 0) {
	goto L3880;
    } else {
	goto L3850;
    }
L3850:
    a1com_1.jsuber = 19;
    goto L3940;
/* ...  MUST BE SYMBOL, VOCAB. */
L3855:
    gbrn[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 10)];
    if (*jbrn == 2) {
	goto L3870;
    }
/* L3860: */
    a1com_1.jsuber = 356;
    goto L3940;
L3870:
    j = 0;
    goto L3910;
/* ...  MUST BE VOCAB., SYMBOL */
L3880:
    if (ailmtb_1.iclass[n + 1] != 1) {
	goto L3900;
    }
/* L3890: */
    j = 2;
    goto L3910;
L3900:
    a1com_1.jsuber = 355;
    goto L3940;
L3910:
    if (asyntb_1.insyn + 2 <= asyntb_1.maxsyn) {
	goto L3930;
    }
/* ...  SYN TABLE OVERFLOW */
/* L3920: */
    a1com_1.jsuber = 354;
    goto L998;
/* ...  ENTER IN SYN TABLE */
L3930:
    npj = n + j;
    asyntb_1.synb[asyntb_1.insyn] = ailmtb_1.elment[npj - 1];
    insto = (asyntb_1.insyn << 2) - 3;
    icl2 = (n + 2 - j << 1) - 1;
    lmen4 = (icl2 << 1) - 1;
    gbrn[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(lmen4 + 1)];
    ksynb[OTHER_ENDIAN_W(insto + 7)] = *jbrn;
    ksynb[OTHER_ENDIAN_W(insto + 8)] = lclas2[OTHER_ENDIAN_S(icl2 - 1)];
    ksynb[OTHER_ENDIAN_W(insto + 9)] = lment2[OTHER_ENDIAN_S(lmen4)];
    ksynb[OTHER_ENDIAN_W(insto + 10)] = lment2[OTHER_ENDIAN_S(lmen4 + 2)];
    asyntb_1.insyn += 2;
L3940:
    n += 3;
    goto L3810;

/* ...     FINI (CLASS 18) */
/* ...  SHOULD HAVE BEEN PROCESSED BY SUBROUTINE  ASCAN */
/* ..  PROCESSOR ERROR */
L3950:
    a1com_1.jsuber = 6113;
    return 0;
/* .. */
/* .. */
/* ...  ILLEGAL USE OF COMPUTING FUNCTION,MODIFIER, VOCAB. WORD, ETC. */
L4000:
    a1com_1.jsuber = 76;
    goto L998;

/* ...     TRANTO (CLASS 20) */
L4010:
    n = abreak_1.inill + 1;
/* ...  CHECK FOR SLASH */
    if (ailmtb_1.iclass[n - 1] != slash) {
	goto L7070;
    }
/* L4040: */
    ++n;
/* ...  CHECK ID TYPE */
    jtemp1 = (n << 2) - 3;
    gbrn[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 2)];
    switch ((int)*jbrn) {
	case 1:  goto L4070;
	case 2:  goto L4050;
	case 3:  goto L4060;
    }
L4050:
    a1com_1.jsuber = 453;
    goto L998;
/* ...  NUMERIC ID */
L4060:
    a = ailmtb_1.elment[n - 1];
    aifun8_(&a, &a1com_1.name__);
    goto L4080;
/* ...  VARIABLE ID */
L4070:
    a1com_1.name__ = ailmtb_1.elment[n - 1];
/* ...  IS ID ALREADY IN VST */
L4080:
    avs1ck_(&j);
    switch ((int)j) {
	case 1:  goto L4100;
	case 2:  goto L4090;
	case 3:  goto L4130;
	case 4:  goto L4130;
    }
L4090:
    a1com_1.jsuber = 3;
    a1com_1.sum = 1;
    goto L998;
/* ...  NO - ENTER IN VST */
L4100:
    avs1pt_(&j);
    if (j == 1) {
	goto L4120;
    }
/* L4110: */
    a1com_1.jsuber = 404;
    a1com_1.sum = 1;
    goto L998;
L4120:
    jtemp1 = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 8;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = 0;
L4130:
    if (n == ailmtb_1.jlment) {
	goto L4150;
    }
/* L4140: */
    a1com_1.jsuber = 409;
    goto L998;
/* ...  OUTPUT A PTPP CLASS 6 RECORD FOR A PROTAP 6000 RECORD */
L4150:
    jf = 1;
/* ...  SET TO FORWARD TRANSFER FOR PASS TWO IF SUCH IS THE CASE */
    jtemp1 = (a1com_1.namsub << 1) - 1;
    if (ivst[OTHER_ENDIAN_S(jtemp1 + 2)] == 0) {
	jf = 0;
    }
    ipt[OTHER_ENDIAN_S(0)] = 6;
    ipt[OTHER_ENDIAN_S(1)] = 5;
/* ...  NPT, NPR */
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 1;
/* ...  PROTAP CLASS, SUBCLASS CODE */
    ipt[OTHER_ENDIAN_S(4)] = 6000;
    ipt[OTHER_ENDIAN_S(5)] = 7;
/* ...  PARAMETER INDICATING A STATEMENT ID */
    ipt[OTHER_ENDIAN_S(6)] = 7;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = jf;
    ipt[OTHER_ENDIAN_S(9)] = a1com_1.namsub;
    aptpp_1.pt[5] = avst_1.vst[a1com_1.namsub - 1];
    aptpp_1.inptp = 6;
/* ...  INPUT ARG TO APTPUT INDICATES NORM TRANSFER OF A COMPLETE STATEMEN */
/* ...   IN TEMP. BUFFER  PT  TO PTPP TABLE */
    aptpp_1.jmode = 5;
    aptput_();
    goto L60;

/* ...     POST PROCESSOR PARAMETERS (CLASSES 21-23) */
L4170:
    aparam_();
    goto L60;

/* ...     SYSTEM FLAGS (CLASS 25) */
/* ...  CLPRNT, NOPOST, NOPLOT, PTONLY, CLTV, BRANCH ON SUBCLASS */
L4180:
    switch ((int)aptpp_1.klastp) {
	case 1:  goto L4200;
	case 2:  goto L4210;
	case 3:  goto L4220;
	case 4:  goto L4230;
	case 5:  goto L4280;
	case 6:  goto L4201;
    }

/* ....  CLPRNT STATEMENT */
L4200:
    if (abreak_1.inill < ailmtb_1.jlment) {
	goto L4201;
    }
/* ....  CLPRNT   (THIS FORM TAKES PRECEDENT OVER THE OTHER OPTIONS) */
/* ...  CLPRNT = PRINT ENTIRE INPUT TO POSTPROCESSOR */
    asistm_1.iclprt = 1;
    goto L60;
/* ...  FORMAT CHECK - IS THERE A SLASH FOLLOWING MAJ.WORD */
L4201:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
    aprtab_1.istarp += 2;
    aclas7_();
    aptpp_1.inptp = 10;
    aptlod_();
    if (amotcm_1.jptind == 0) {
	goto L4203;
    }
/* ....  ENTRY SHOULD BE A VOCABULARY MINOR MODIFIER */
L4212:
    a1com_1.jsuber = 81;
    goto L998;
L4203:
    if (amotcm_1.kreslt == 71) {
	goto L4204;
    }
    if (amotcm_1.kreslt == 72) {
	goto L4205;
    }
    if (aptpp_1.klastp == 6) {
	goto L4213;
    }
    if (amotcm_1.kreslt == 144) {
	goto L4206;
    }
/* ....  ILLEGAL VOCABULARY WORD IF NONE OF THE ABOVE MODIFIERS USED */
L4213:
    a1com_1.jsuber = 76;
    goto L998;
/* ....  CLPRNT/ON */
L4204:
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = 1;
    goto L4207;
/* ....  CLPRNT/OFF */
L4205:
    aptpp_1.pt[4] = (float)0.;
    goto L4207;
/* ....  CLPRNT/OPTION */
L4206:
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = 2;
/* ....  OUTPUT CLASS 6 PTPP RECORD */
L4207:
    ipt[OTHER_ENDIAN_S(0)] = 6;
    ipt[OTHER_ENDIAN_S(1)] = 4;
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 1;
    ipt[OTHER_ENDIAN_S(4)] = 13000;
    if (aptpp_1.klastp == 6) {
	goto L4208;
    }
    ipt[OTHER_ENDIAN_S(5)] = 4;
    if (asistm_1.iclprt != 1) {
	asistm_1.iclprt = -1;
    }
    goto L4209;
L4208:
    ipt[OTHER_ENDIAN_S(5)] = 5;
L4209:
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    aptpp_1.inptp = 5;
    aptpp_1.jmode = 5;
    aptput_();
    goto L60;

/* ...  NOPLOT - SUPPRESS EXECUTION OF ALL PLOT STATEMENTS IN PART PROGRAM */
L4210:
    asistm_1.noplot = 1;
    goto L60;

/* ...  NOPOST - SUPPRESS EXECUTION OF ALL SPECIFIED POSTPROCESSORS */
L4220:
    asistm_1.nopost = 1;
    goto L60;

/* ...  PTONLY - CHECK FORMAT FOR SLASH */
L4230:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
/* L4250: */
    if (ailmtb_1.elment[abreak_1.inill + 1] <= (float)3.) {
	goto L4270;
    }
/* L4260: */
    a1com_1.jsuber = 553;
    goto L998;
/* ...  IPTNLY EQUALS PARAMETER VALUE 1,2 OR 3 */
L4270:
    asistm_1.iptnly = (integer) ailmtb_1.elment[abreak_1.inill + 1];
/* ...     IF PTONLY/3, PICK UP 'N' FOLLOWING SUBCODE */
    if (asistm_1.iptnly != 3) {
	goto L60;
    }
    if (abreak_1.inill + 4 == ailmtb_1.jlment) {
	goto L4272;
    }
L4271:
    a1com_1.jsuber = 129;
    goto L998;
/* ...     MAKE SURE PARAMETER GIVEN IS A NUMBER */
L4272:
    if (ailmtb_1.iclass[abreak_1.inill + 3] != 3) {
	goto L7090;
    }
    asistm_1.nclrec = (integer) ailmtb_1.elment[abreak_1.inill + 3];
    goto L60;

/* ...  VOC. CLASS 25, SUBCLASS 5 - AUX. ARELEM IS TO BE USED */
L4280:
    if (ailmtb_1.jlment == 3) {
	goto L4284;
    }
/* ...  CLTV */
    asistm_1.kflags[1] = 0;
    asistm_1.kflags[2] = 1;
    goto L60;
/* ...  CLTV/OPTION */
L4284:
    asistm_1.ltvmit = 1;
    goto L60;

/* ...     MOTION, DIRECTION, AND TOOL POSITION COMMANDS (CLASSES 26, 27) */
L4295:
    amotin_();
    goto L60;

/* ...     PROCESS CANON/ON OR CANON/OFF STATEMENT (CLASS 28) */
/* ...     TEST FOR SLASH */
L4300:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
/* ...     YES - MUST BE FOLLOWED BY ON OR OFF */
    aprtab_1.istarp = abreak_1.inill + 2;
    aptpp_1.inptp = 4;
    aptlod_();
    if (amotcm_1.jptind != 0) {
	goto L4212;
    }
    if (amotcm_1.kreslt == 72) {
	goto L4302;
    }
    if (amotcm_1.kreslt != 71) {
	goto L4213;
    }
/* ...     CANON/ON */
    ipt[OTHER_ENDIAN_S(1)] = 5;
    goto L4303;
/* ...     CANON/OFF */
L4302:
    ipt[OTHER_ENDIAN_S(1)] = 6;
L4303:
    ipt[OTHER_ENDIAN_S(0)] = 8;
    aptpp_1.inptp = 1;

    aptpp_1.jmode = 5;
    aptput_();
    goto L998;

/* ...     REGION, ENDREG (CLASS 32) */
/* ...     AREGPR IS ONLY A DUMMY SUBROUTINE AT PRESENT */
L4325:
    aregpr_();
    goto L998;

/* ...     WARNING MESSAGE FOR INACTIVE VOCAB. WORDS (CLASS 33) */
L5000:
    ipt[OTHER_ENDIAN_S(0)] = 2;
    ipt[OTHER_ENDIAN_S(1)] = 8;
    ipt[OTHER_ENDIAN_S(2)] = 7;
    ipt[OTHER_ENDIAN_S(3)] = 2;
    for (i__ = 3; i__ <= 9; ++i__) {
/* L5010: */
	aptpp_1.pt[i__ - 1] = awrong[i__ - 3];
    }
    aptpp_1.inptp = 9;
    aptpp_1.jmode = 5;
    aptput_();
    goto L998;

/* ...     TUNEUP (CLASS 34) */
/* ...  SAVE CURRENT TABLE LIMITS IN CASE OF ERROR ON TUNEUP CARD */
L6000:
    mvsave = amxtab_1.maxvst;
    mpsave = amxtab_1.mxptpp;
    mcsave = amxtab_1.mxcan;
/* ...  IF CANON IS IN USE, TUNEUP CANNOT BE SPECIFIED */
    if (amacro_1.limcan > amxtab_1.maxvst + amxtab_1.mxptpp) {
	goto L6070;
    }
/* ...  FLUSH OUT PTPP SO THE ORIGIN CAN BE RELOCATED */
    aptpp_1.jmode = 6;
    aptput_();
/* ...  PROCESS ENTRIES - FORMAT IS         TUNEUP/VST,PTPP,CANON */
    for (i__ = 1; i__ <= 5; i__ += 2) {
	in = abreak_1.inill + i__ + 1;
/* ...  PARAMETERS MUST BE NUMERIC */
	if (ailmtb_1.iclass[in - 1] != 3) {
	    goto L6070;
	}
	ijazz = (integer) ailmtb_1.elment[in - 1];
	if ((i__1 = i__ - 3) < 0) {
	    goto L6010;
	} else if (i__1 == 0) {
	    goto L6020;
	} else {
	    goto L6030;
	}
/* ...  CHANGE VST MAXIMUM LENGTH */
L6010:
	amxtab_1.maxvst = ijazz;
	goto L6050;
/* ...  CHANGE PTPP MAXIMUM LENGTH */
L6020:
	amxtab_1.mxptpp = ijazz;
	goto L6050;
/* ...  CHANGE CANON MAXIMUM LENGTH */
L6030:
	amxtab_1.mxcan = ijazz;
	if (amxtab_1.mxcan < 1300) {
	    goto L6070;
	}
	if (amxtab_1.maxvst + amxtab_1.mxptpp + amxtab_1.mxcan > 
		amxtab_1.maxtab) {
	    goto L6070;
	}
L6050:
	;
    }
    if (in != ailmtb_1.jlment) {
	goto L6070;
    }
    abreak_1.nextnw = amxtab_1.maxvst + 1;
    amacro_1.limcan = amxtab_1.maxvst + amxtab_1.mxptpp;
    a1com_1.indxpt = amxtab_1.maxvst + 2;
    abreak_1.nrelcn = amxtab_1.maxvst + 1;
    goto L998;
/* ...  INCORRECT TUNEUP CARD - OUTPUT WARNING MESSAGE AND IGNORE CARD */
L6070:
    ipt[OTHER_ENDIAN_S(0)] = 2;
    ipt[OTHER_ENDIAN_S(1)] = 8;
    ipt[OTHER_ENDIAN_S(2)] = 7;
    ipt[OTHER_ENDIAN_S(3)] = 2;
    for (i__ = 3; i__ <= 9; ++i__) {
/* L6080: */
	aptpp_1.pt[i__ - 1] = anerr[i__ - 3];
    }
    aptpp_1.inptp = 9;
    aptpp_1.jmode = 5;
/* ...  RESET TABLE LIMITS TO ASSUMED VALUES */
    amxtab_1.maxvst = mvsave;
    amxtab_1.mxptpp = mpsave;
    amxtab_1.mxcan = mcsave;
    aptput_();
    goto L998;

/*     ENCOUNTERED LIBRY STATEMENT */

L7000:
    if (ailmtb_1.iclass[abreak_1.inill] != slash) {
	goto L7070;
    }
    if (abreak_1.inill + 2 > ailmtb_1.jlment) {
	goto L4271;
    }
/* ...     SAVE INDEX TO VST LOCATION OF FIRST NAME IN THIS STATEMENT */
    amxtab_1.maxpot = amxtab_1.maxvs1 + 2;
/* ...     INCREMENT ELMENT SCANNING INDEX TO (NEXT) SYSTEM MACRO NAME */
L7010:
    abreak_1.inill += 2;
/* ...  CHECK FOR VARIABLE SYMBOL IN ELMENT TABLE */
    if (ailmtb_1.iclass[abreak_1.inill - 1] != 1) {
	goto L7080;
    }
    a1com_1.name__ = ailmtb_1.elment[abreak_1.inill - 1];
/* ...  IS THERE ROOM IN VST FOR MACRO NAME */
    if (amxtab_1.maxvs1 + 2 > amxtab_1.maxvst) {
	goto L7060;
    }
/* ...  PLACE SYSTEM MACRO NAME IN VST */
    avs1pt_(&j);
/* L7020: */
    jtemp1 = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 11;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = 0;
    if (abreak_1.inill >= ailmtb_1.jlment) {
	goto L7030;
    }
    if (ailmtb_1.iclass[abreak_1.inill] != adata1_1.ncomma) {
	goto L3710;
    }
    goto L7010;
/* ...     SAVE INDEX TO VST ENTRY FOR LAST SYSTEM MACRO NAME */
L7030:
    amxtab_1.maxvs = amxtab_1.maxvs1;
/* ...  **********DISABLE TO READ SYSTEM MACROS WHEN FIRST CALLED********* */
/* ...     TEST FOR SEGMENT READ MODE */
    if (alibry_1.irdmod != 0) {
	goto L8000;
    }
/* ...     PICK UP FIRST SYSTEM MACRO NAME, AND SET FLAG TO READ IT IN */
    alibry_1.segnam = avst_1.vst[amxtab_1.maxpot - 1];
    avst_1.vst[amxtab_1.maxpot - 1] = adata1_1.blanks;
    alibry_1.irdmod = -2;
/* ...  ****************************************************************** */
    goto L998;
/* ...     VST FULL */
L7060:
    a1com_1.jsuber = 15;
    goto L998;
/* ...     NO SLASH FOUND */
L7070:
    a1com_1.jsuber = 155;
    goto L998;
/* ...  VARIABLE SYMBOL NOT FOUND */
L7080:
    a1com_1.jsuber = 156;
    goto L998;
/* ...  IMPROPER PUNCTUATION */
L7090:
    a1com_1.jsuber = 132;
    goto L998;

/* ...     WARNING MSG FOR LIBRY STATEMENT IN SEGMENT READ */
L8000:
    ipt[OTHER_ENDIAN_S(0)] = 2;
    ipt[OTHER_ENDIAN_S(1)] = 15;
    ipt[OTHER_ENDIAN_S(2)] = 14;
    ipt[OTHER_ENDIAN_S(3)] = 2;
    for (i__ = 3; i__ <= 16; ++i__) {
/* L8010: */
	aptpp_1.pt[i__ - 1] = aliber[i__ - 3];
    }
    aptpp_1.inptp = 16;
    aptpp_1.jmode = 5;
    aptput_();

L60:
L998:
    return 0;
} /* amon11_ */

#undef ipt
#undef errtap
#undef lment2
#undef lclas2
#undef lclas1
#undef ksynb
#undef ivst
#undef jbrn
#undef gbrn
#undef anerr
#undef awrong
#undef aliber


