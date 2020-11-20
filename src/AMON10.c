/* AMON10.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

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

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int amon10_()
{
    /* System generated locals */
    integer i__1;
    static shortint equiv_2[2];

    /* Local variables */
    static doublereal a;
    static integer i__, j, l, n, jf;
    static doublereal em;
    static integer kb1, kb2, kb3, nid;
#define ipt ((integer *)&aptpp_1)
    static integer icl1, next;
    extern /* Subroutine */ int aread_();
#define itype (equiv_2 + 1)
    extern /* Subroutine */ int aclas7_();
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_(), aifun8_();
    static integer jtemp1;
#define lment4 ((integer *)&ailmtb_1)
#define itype1 ((logical1 *)equiv_2)
    extern /* Subroutine */ int accall_(), aflags_(), aparam_(), aobtan_();
    static integer icomma=0x904;
    extern /* Subroutine */ int atblkp_(), ahelpr_();
    static integer islash=0x304;
#define ipunct (equiv_2)
    extern /* Subroutine */ int ainout_(), aptlod_(), aptput_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*       INTEGER ISLASH/Z00000304/,ICOMMA/Z00000904/ */
/*     THIS PROGRAM PROCESSES VOCABULARY CLASSES ONE THRU TEN */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
    icl1 = (abreak_1.k + 1 << 2) - 3;
//    *ipunct = 0;
    ipunct[0] = 0;
    ipunct[1] = 0;

/* ...     BRANCH ON CLASS OF VOCABULARY WORD WHICH BEGINS STATEMENT */
    switch ((int)aptpp_1.klass) {
	case 1:  goto L2470;
	case 2:  goto L2550;
	case 3:  goto L2550;
	case 4:  goto L2565;
	case 5:  goto L2595;
	case 6:  goto L2605;
	case 7:  goto L2610;
	case 8:  goto L2755;
	case 9:  goto L2760;
	case 10:  goto L3150;
    }

/* ...     VOCAB. CLASS 1 - FIXED FIELD STATEMENT */
L2470:
    atblkp_(ainpot_1.inword, &n, &c__1);
    ailmtb_1.elment[0] = ainpot_1.inword[0];
    if (n != 0) {
	goto L2520;
    }

/* ...  MUST BE IN COLS. 1-6 */
    a1com_1.jsuber = 21;
    goto L998;

/* ...     BRANCH ON VOCABULARY SUBTYPE TO APPROPRIATE PROCESSING */
L2520:
    switch ((int)aptpp_1.klastp) {
	case 1:  goto L2530;
	case 2:  goto L60;
	case 3:  goto L2540;
	case 4:  goto L2540;
	case 5:  goto L2540;
    }

/* ...  PROCESS TITLES */
L2530:
    aklas7_1.kfk = 1;
    aclas7_();
    ainout_();
    goto L60;

/* ...  PROCESS PARTNO, INSERT, PPRINT */
L2540:
    aklas7_1.kfk = 2;
    aclas7_();
    aparam_();
    goto L60;

/* ...     ARELEM PARAMETERS (VOCAB. CLASSES 2 AND 3) */
L2550:
    aflags_();
    goto L60;

/* ...     INPUT/OUTPUT COMMANDS (VOCAB. CLASS 4) */
L2565:
    switch ((int)aptpp_1.klastp) {
	case 1:  goto L2570;
	case 2:  goto L2580;
	case 3:  goto L2580;
    }

/* ...  PROCESS READ */
L2570:
    aread_();
/* ... PTPP CLASS 2 RECORDS WHERE PROCESSED BY ERROR LOOP IN SUBRTN AREAD */
    return 0;

/* ...  PROCESS PUNCH, PRINT */
L2580:
    ainout_();
    goto L60;

/* ...     PROCESS OBTAIN (VOCAB. CLASS 5) */
L2595:
    aobtan_();
    goto L60;

/* ...     PROCESS ZSURF (VOCAB. CLASS 6) */
/* ...     TEST FOR DATA IN STATEMENT FOLLOWING SLASH */
L2605:
    if (abreak_1.k + 2 > ailmtb_1.jlment) {
	goto L3410;
    }
/* ...     YES - MAKE SURE SLASH FOLLOWED VOCABULARY WORD */
    itype1[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
//    if (*ipunct != 3) {
    if (SWTCH_ENDIAN_INT_SHRT(*((int*)ipunct)) != 3) {
	goto L3400;
    }
    ahelpr_(&abreak_1.inill);
/* ...     TEST FOR ERROR IN AHELPR */
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...     INITIALIZE INDEXES, AND MOVE DATA IN STATEMENT TO PTPP */
    aprtab_1.istarp = abreak_1.k + 2;
    aptpp_1.inptp = 2;
    aptlod_();
/* ...     TEST FOR ERROR IN APTLOD */
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...     IF NOT END OF STATEMENT, ERROR */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L3410;
    }
/* ...  OUTPUT CLASS 16 PTPP RECORD FOR ZSURF */
    --aptpp_1.inptp;
    ipt[OTHER_ENDIAN_S(0)] = 16;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 1;
    aptpp_1.jmode = 5;
    aptput_();
    goto L60;

/* ...     SPECIAL PROGRAM CALL (VOCAB. CLASS 7) */
L2610:
    if (ailmtb_1.iclass[abreak_1.inill + 1] == 1) {
	goto L2630;
    }
/* L2620: */
    a1com_1.jsuber = 12345;
    goto L998;
L2630:
    aprtab_1.istarp = abreak_1.inill + 5;
    accall_();
    goto L60;

/* ...     PROCESS REFSYS (VOCAB. CLASS 8) */
/* ...     TEST FOR DATA IN STATEMENT FOLLOWING SLASH */
L2755:
    if (abreak_1.k + 2 > ailmtb_1.jlment) {
	goto L3410;
    }
/* ...     INITIALIZE INDICES, AND MOVE DATA IN STATEMENT TO PTPP */
    aprtab_1.istarp = abreak_1.k + 2;
    aptpp_1.inptp = 2;
    aptlod_();
/* ...     TEST FOR ERROR IN APTLOD */
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...     IF NOT END OF STATEMENT, ERROR */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L3410;
    }
/* ...     TEST STATEMENT ENTRY FOR VARIABLE SYMBOL OR VOCABULARY */
    itype1[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
//    if ((i__1 = *ipunct - 2) < 0) {
    if ((i__1 = SWTCH_ENDIAN_INT_SHRT(*((int*)ipunct)) - 2) < 0) {
	goto L2758;
    } else if (i__1 == 0) {
	goto L2757;
    } else {
	goto L2756;
    }
L2757:
    if (ipt[OTHER_ENDIAN_S(5)] == 53) {
	goto L2761;
    }
/* ...  SHOULD HAVE BEEN VOCABULARY WORD NOMORE */
L2756:
    a1com_1.jsuber = 651;
    goto L998;
/* ...  PREPARE PTPP CLASS 4 RECORD */
L2761:
    ipt[OTHER_ENDIAN_S(0)] = 4;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    aptpp_1.pt[1] = (float)0.;
    aptpp_1.inptp = 2;
    goto L2759;
L2758:
    --aptpp_1.inptp;
    ipt[OTHER_ENDIAN_S(0)] = 4;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 1;
L2759:
    aptpp_1.jmode = 5;
    aptput_();
    goto L60;

/* ...     'IF' STATEMENT (VOCAB. CLASS 9) */
L2760:
    if (a1com_1.loop != 0) {
	goto L2780;
    }
/* ...  IF STATEMENT ALLOWED ONLY IN A LOOP OR MACRO */
/* L2770: */
    a1com_1.jsuber = 407;
    goto L998;
L2780:
    n = abreak_1.inill + 1;
    next = 4;
    jtemp1 = (n << 2) - 3;
    itype1[OTHER_ENDIAN_W(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 2)];
/* ...  CHECK CONTENTS OF IF EXPRESSION AND SETUP PTPP WORDS I,J,K,L */
//    switch ((int)*ipunct) {
    switch (SWTCH_ENDIAN_INT_SHRT(*((int*)ipunct)) ) {
	case 1:  goto L2820;
	case 2:  goto L2790;
	case 3:  goto L2800;
	case 4:  goto L2790;
	case 5:  goto L2810;
    }

L2790:
    a1com_1.jsuber = 402;
    goto L998;

/* ...  FLOATING POINT NUMBER */
L2800:
    j = 0;
    abreak_1.k = 0;
    em = ailmtb_1.elment[n - 1];
    goto L2920;

/* ...  EXPRESSSION */
L2810:
    i__ = 3;
    j = 0;
    abreak_1.k = 0;
    jtemp1 = (n << 1) - 1;
    l = lment4[OTHER_ENDIAN_S(jtemp1)];
    goto L2910;

/* ...  VARIABLE SYMBOL */
L2820:
    a1com_1.name__ = ailmtb_1.elment[n - 1];
    avs1ck_(&j);
    if (j == 5) {
	goto L2840;
    }
    if (j != 8) {
	goto L2790;
    }

/* ...  CHECK FOR SUBSCRIPT */
L2840:
    i__ = 2;
    l = a1com_1.namsub;
    if (ailmtb_1.iclass[n] == 8) {
	goto L2880;
    }
    jtemp1 = (n << 1) - 1;
    abreak_1.k = lment4[OTHER_ENDIAN_S(jtemp1 + 2)];
    if (ailmtb_1.iclass[n] == 9) {
	goto L2890;
    }
    if (ailmtb_1.iclass[n] != 7) {
	goto L2900;
    }
/* ...     SUBSCRIPT IS A VARIABLE SYMBOL */
    j = 2;
    goto L2925;

/* ...  SUBSCRIPT IS A NUMBER */
L2880:
    j = 1;
    abreak_1.k = 0;
    em = ailmtb_1.elment[n];
    goto L2920;

/* ...  SUBSCRIPT IS AN EXPRESSION */
L2890:
    j = 3;
    goto L2925;

/* ...  NO SUBSCRIPT */
L2900:
    j = 0;
    abreak_1.k = 0;
L2910:
    ++n;
    goto L2930;

L2920:
    next = 5;
L2925:
    n += 2;
/* ...  PTPP WORDS FOR CONTENTS OF IF EXPRESSION */
    aptpp_1.pt[3] = em;
L2930:
    ipt[OTHER_ENDIAN_S(2)] = i__;
    ipt[OTHER_ENDIAN_S(3)] = j;
    ipt[OTHER_ENDIAN_S(4)] = abreak_1.k;
    ipt[OTHER_ENDIAN_S(5)] = l;
    nid = 0;
L2940:
    if (ailmtb_1.iclass[n - 1] == 3) {
	goto L2960;
    }
/* L2950: */
    a1com_1.name__ = ailmtb_1.elment[n - 1];
    goto L2970;

/* ...  NUMERIC STATEMENT ID */
L2960:
    a = ailmtb_1.elment[n - 1];
    aifun8_(&a, &a1com_1.name__);

/* ...  IS ID ALREADY IN VST */
L2970:
    avs1ck_(&j);
    if (a1com_1.jsuber != 0) {
	return 0;
    }
/* ...     IF ID NOT WITHIN PRESENT LOOP OR MACRO, ERROR */
    if (a1com_1.namsub < amcstf_1.idlocn) {
	goto L3242;
    }
    if (j != 1) {
	goto L3010;
    }

/* ...  ERROR */
L2980:
    a1com_1.jsuber = 403;
    a1com_1.sum = 1;
    goto L998;

/* ...  UPDATE PTPP REFERENCES TO THIS ID */
L3010:
    jf = a1com_1.namsub;
/* L3020: */
    ++nid;
    switch ((int)nid) {
	case 1:  goto L3030;
	case 2:  goto L3040;
	case 3:  goto L3050;
    }

/* ...  FIRST ID */
L3030:
    kb1 = jf;
    goto L3060;
/* ...  SECOND ID */
L3040:
    kb2 = jf;
    goto L3060;
/* ...  THIRD ID */
L3050:
    kb3 = jf;
L3060:
    ++n;
    if (n >= ailmtb_1.jlment) {
	goto L3120;
    }
/* ...     TEST FOR COMMA PRECEDING NEXT ID */
    if (ailmtb_1.iclass[n - 1] == icomma) {
	goto L3100;
    }
/* ...  FORMAT ERROR */
/* L3080: */
    a1com_1.jsuber = 78;
    goto L998;

L3100:
    ++n;
    if (nid - 3 >= 0) {
	goto L3300;
    } else {
	goto L2940;
    }

L3120:
    if (nid != 3) {
	goto L3300;
    }

/* ...  OUTPUT PTPP CLASS 11 RECORD */
/* L3140: */
    ipt[OTHER_ENDIAN_S(0)] = 11;
    ipt[OTHER_ENDIAN_S(1)] = next + 1;
    jtemp1 = (next << 1) - 1;
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 0;
    ipt[OTHER_ENDIAN_S(jtemp1)] = kb1;
    ipt[OTHER_ENDIAN_S(jtemp1 + 1)] = 0;
    ipt[OTHER_ENDIAN_S(jtemp1 + 2)] = kb2;
    ipt[OTHER_ENDIAN_S(jtemp1 + 3)] = 0;
    ipt[OTHER_ENDIAN_S(jtemp1 + 4)] = kb3;
    aptpp_1.jmode = 5;
    aptpp_1.inptp = next + 2;
    aptput_();
    goto L60;

/* ...     PROCESS 'JUMPTO' (VOCAB. CLASS 10) */
L3150:
    if (a1com_1.loop != 0) {
	goto L3170;
    }
/* L3160: */
    a1com_1.jsuber = 407;
    goto L998;
L3170:
    n = abreak_1.inill + 1;
    if (ailmtb_1.iclass[n - 1] != islash) {
	goto L3400;
    }

/* L3200: */
    ++n;
    if (ailmtb_1.iclass[n - 1] == 1) {
	goto L3220;
    }
    if (ailmtb_1.iclass[n - 1] == 3) {
	goto L3230;
    }
/* L3210: */
    a1com_1.jsuber = 403;
    goto L998;

/* ...  VARIABLE SYMBOL ID */
L3220:
    a1com_1.name__ = ailmtb_1.elment[n - 1];
    goto L3240;

/* ...  NUMERIC ID */
L3230:
    a = ailmtb_1.elment[n - 1];
    aifun8_(&a, &a1com_1.name__);

/* ...  IS ID ALREADY IN VST */
L3240:
    avs1ck_(&j);
    if (a1com_1.jsuber != 0) {
	return 0;
    }
/* ...     IF ID NOT WITHIN PRESENT LOOP OR MACRO, ERROR */
    if (a1com_1.namsub >= amcstf_1.idlocn) {
	goto L3245;
    }
L3242:
    a1com_1.jsuber = 406;
    a1com_1.sum = 1;
    goto L998;

L3245:
    switch ((int)j) {
	case 1:  goto L2980;
	case 2:  goto L3250;
	case 3:  goto L3290;
	case 4:  goto L3290;
    }
L3250:
    a1com_1.jsuber = 3;
    a1com_1.sum = 1;
    goto L998;

L3290:
    if (n == ailmtb_1.jlment) {
	goto L3310;
    }
L3300:
    a1com_1.jsuber = 409;
    a1com_1.sum = 1;
    goto L998;

/* ...     OUTPUT CLASS 10 PTPP RECORD */
L3310:
    ipt[OTHER_ENDIAN_S(0)] = 10;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    ipt[OTHER_ENDIAN_S(2)] = 0;
    ipt[OTHER_ENDIAN_S(3)] = a1com_1.namsub;
    aptpp_1.inptp = 2;
    aptpp_1.jmode = 5;
    aptput_();
    goto L998;

/* ...     FORMAT ERROR - NO SLASH FOUND */
L3400:
    a1com_1.jsuber = 155;
    goto L998;

/* ...     INCORRECT AMOUNT OF DATA IN STATEMENT */
L3410:
    a1com_1.jsuber = 129;

L60:

L998:
    return 0;
} /* amon10_ */

#undef ipunct
#undef itype1
#undef lment4
#undef lclas1
#undef itype
#undef ipt


