/* AMON7.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

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

struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__7 = 7;

/* Subroutine */ int amon7_()
{
    /* Initialized data */

    static integer iequal = 0x804;
    static struct {
	shortint e_1;
	} equiv_2 = { 0 };


    /* System generated locals */
    integer i__1;
    static integer equiv_4[1];

    /* Local variables */
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
    static integer i__, j, l, m;
#define canon ((doublereal *)&avst_1)
#define ktemp ((shortint *)equiv_4)
#define itemp (equiv_4)
    extern /* Subroutine */ int aclas7_();
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_();
    static integer jtemp1, ii;
#define kk ((shortint *)equiv_4 +OTHER_ENDIAN_S(1))
    static integer ir;
#define icanon ((integer *)&avst_1)
    extern /* Subroutine */ int amatmv_(), aptput_();
    static integer imaxvs;
    extern /* Subroutine */ int aprint_();
#define gat ((logical1 *)&equiv_2)
#define kat ((shortint *)&equiv_2)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*       INTEGER*2 KAT/0/,KK,KTEMP(2) */
/* ...  THIS ROUTINE PROCESSES A MACRO CALL STATEMENT */
/* ...  OF THE FORMAT */
/* ...       CALL/MAC1,A=1,B,C=2,D=ON */
/*     THE MACRO NAME IS ENTERED IN THE NESTING TABLE. THE LOCATION IN */
/*     THE CALLING PROGRAM IS NOTED SO PROCESSING CAN BE RESTORED. */
/*     FINALLY, THE MACRO VARIABLE STATUS IS UPDATED */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
/*               *          *          *          *          * */
    if (alibry_1.isysmc != 1) {
	goto L1365;
    }
    alibry_1.isysmc = 0;
    amcstf_1.macrd = 1;
    a1com_1.loop = alibry_1.luup;
    abreak_1.nwonrd = alibry_1.nwunrd;
    a1com_1.name__ = alibry_1.segnam;
    avs1ck_(&j);
    if (a1com_1.jsuber != 0) {
	goto L1412;
    }
    if (j == 7) {
	goto L1505;
    }
    goto L1420;

L1365:
    aklas7_1.kfk = 2;
    aklas7_1.iisn = -aklas7_1.iisn;
    aclas7_();
/* L1370: */
    if (amcstf_1.maccur == 0) {
	goto L1390;
    }
/* ...  UPDATE MACRO NESTING DATA */
/* L1380: */
    amcstf_1.maclcn[amcstf_1.maccur - 1] = abreak_1.kanlcn;
    amcstf_1.macids[amcstf_1.maccur - 1] = amcstf_1.idlocn;
    jtemp1 = (abreak_1.kanlcn << 1) - 1;
    icanon[OTHER_ENDIAN_S(jtemp1 - 1)] = abreak_1.nrelcn;
    abreak_1.nrelcn = amxtab_1.maxvst + 1;
    ++amcstf_1.maccur;
    goto L1395;
L1390:
    amcstf_1.maccur = 1;
    amcstf_1.isvid = amcstf_1.idlocn;
L1395:
    a1com_1.name__ = ailmtb_1.elment[abreak_1.k + 1];
    if (ailmtb_1.iclass[abreak_1.k + 1] == 1) {
	goto L1397;
    }
    a1com_1.jsuber = 226;
    goto L998;
L1397:
    if (amcstf_1.maccur <= abreak_1.mxnest) {
	goto L1410;
    }
/* ...  MAXIMUM NESTING LEVEL FOR MACROS HAS BEEN EXCEEDED */
/* L1400: */
    a1com_1.jsuber = 231;
    a1com_1.sum = 1;
    goto L998;
L1410:
    avs1ck_(&j);
    if (a1com_1.jsuber == 0) {
	goto L1415;
    }
L1412:
    a1com_1.jsuber = 233;
    goto L998;
/* ...  BRANCH FOR SYSTEM MACROS */
L1415:
    if (j == 11) {
	goto L1430;
    }
    if (j == 7) {
	goto L1430;
    }
/* ...  *********************** ENABLE FOR NO LIBRY ********************* */
/* ...  IF (NOLIBR.NE.1) GO TO 1420 */
/* ...  IF (J.NE.1) GO TO 1420 */
/* ...  J = 11 */
/* ...  GO TO 1430 */
/* ...  INCORRECT MACRO NAME */
L1420:
    a1com_1.jsuber = 233;
    a1com_1.sum = 1;
    goto L998;
/* ...  ***************************************************************** */
/* ...  SET INDEX TO FIRST MACRO VARIABLE NAME IN ELMENT TABLE */
L1430:
    l = abreak_1.k + 4;
    m = 1;
L1440:
    if (l > ailmtb_1.jlment) {
	goto L1500;
    }

/* ...  CHECK FOR COMMA BEFORE MACRO VARIABLE NAME */
    if (ailmtb_1.iclass[l - 2] != adata1_1.ncomma) {
	goto L1490;
    }
    if (m > 50) {
	goto L1488;
    }
/* ...  CHECK FOR MACRO VARIABLE AFTER COMMA */
    if (ailmtb_1.iclass[l - 1] != 1) {
	goto L1494;
    }
/* ...  STORE MACRO VARIABLE NAME */
    alibry_1.amacvr[m - 1] = ailmtb_1.elment[l - 1];
/* ...  CHECK FOR EQUAL SIGN AFTER MACRO VARIABLE */
    if (ailmtb_1.iclass[l] != iequal) {
	goto L1492;
    }
/* ...  CHECK FOR PUNCTUATION AFTER EQUAL SIGN */
/* ...     OTHERWISE CAN HAVE ONLY UNSUBSCRIPTED SYMBOL, VOCAB, OR NUMBER */
    jtemp1 = (l << 2) - 3;
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 10)];
    if ((i__1 = *kat - 4) < 0) {
	goto L1480;
    } else if (i__1 == 0) {
	goto L1450;
    } else {
	goto L1445;
    }
/* ...  ILLEGAL EXPRESSION OR SUBSCRIPTED V S IN CALL STATEMENT */
L1445:
    a1com_1.jsuber = 232;
    goto L998;
/* ...  PUNCTUATION FOUND */
/* ...  MUST HAVE NUMBER AFTER PUNCTUATION ; OTHERWISE ERROR */
L1450:
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 14)];
    if (*kat != 3) {
	goto L1494;
    }
/* ...  NUMBER FOUND ; TEST IF PUNCTUATION IS OKAY */
/* ...                     PLUS,MINUS,OTHER */
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 9)];
    if ((i__1 = *kat - 2) < 0) {
	goto L1470;
    } else if (i__1 == 0) {
	goto L1460;
    } else {
	goto L1496;
    }
L1460:
    ailmtb_1.elment[l + 2] = -ailmtb_1.elment[l + 2];
/* ...  MOVE ELMENT INDEX PAST ARITHMETIC SIGN */
L1470:
    ++l;
/* ...  STORE ASSIGNED VALUE */
L1480:
    alibry_1.amacvl[m - 1] = ailmtb_1.elment[l + 1];
/* ...  SAVE ICLASS ENTRY */
    alibry_1.macicl[m - 1] = ailmtb_1.iclass[l + 1];
    ++m;
    l += 4;
    goto L1440;

/* ...  CALL STATEMENT HAS MORE THAN 50 MACRO VARIABLES */
L1488:
    a1com_1.jsuber = 205;
/* ...  IMPROPER PUNCTUATION - PROGRAM EXPECTED COMMA */
L1490:
    a1com_1.jsuber = 234;
    goto L998;
/* ...  NO EQUAL SIGN AFTER MACRO VARIABLE */
L1492:
    a1com_1.jsuber = 229;
    goto L998;
/* ...  FORMAT ERROR IN CALL STARTMENT */
L1494:
    a1com_1.jsuber = 253;
    goto L998;
/* ...  ILLEGAL PUNCTUATION WITH ASSIGNED VALUE */
L1496:
    a1com_1.jsuber = 235;
    goto L998;

/* ...  STORE NUMBER OF MACRO VARIABLES FOUND IN CALL STATEMENT */
L1500:
    alibry_1.ivarct = m - 1;
/* ...  CHECK IF SYSTEM MACRO DEFINITION HAS TO BE READ IN FROM APTMAC */
    if (j == 11) {
	goto L1590;
    }

/* ...  MACRO DEFINITION HAS ALREADY BEEN PROCESSED */
L1505:
    jtemp1 = (a1com_1.namsub << 1) - 1;
/* ...  GET I PARAMETER FROM VST ENTRY */
    i__ = ivst[OTHER_ENDIAN_S(jtemp1 + 1)];
/* ...  GET J PARAMETER FROM VST */
    *itemp = ivst[OTHER_ENDIAN_S(jtemp1 + 2)];
/* ...     LAST 2 BYTES OF J APRAMETER ARE IN KK */
    if (i__ == 10) {
	goto L1510;
    }
/* ...  MACRO NAME FOLLOWING CALL IS IMPROPERLY DEFINED */
    a1com_1.jsuber = 233;
    a1com_1.sum = 1;
    goto L998;
L1510:
    amacro_1.macvst = a1com_1.namsub;
/* ...  BRANCH IF MACRO IS IN CANON */
    if (*kk > 0) {
	goto L1520;
    }
/* ...  GET MACRO FROM OVERFLOW FILE AND PUT IN CANON */
    amacro_1.jwhat = 3;
    amatmv_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...  GET CANON INDEX FOR STARTING LOCATION OF THE MACRO */
    *itemp = ivst[OTHER_ENDIAN_S(jtemp1 + 2)];
/* ...  TEST IF IN MACRO EXECUTION OR LOOP EXCUTION MODE */
L1520:
    if (a1com_1.loop != 0) {
	goto L1530;
    }
    aptpp_1.jmode = 6;
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L998;
    }
/* ...  STORE STARTING LOCATION OF CURRENT MACRO */
L1530:
    amcstf_1.macstr[amcstf_1.maccur - 1] = *kk;
/* ...  STORE CURRENT MACRO NAME */
    amcstf_1.macnam[amcstf_1.maccur - 1] = a1com_1.name__;
/* ...  SET MACRO EXECUTION MODE */
    a1com_1.loop = 1;
/* ...  SET FLAG TO READ FROM CANON TO INWORD */
    amcstf_1.macrd = 1;
    jtemp1 = (*kk << 1) - 1;
    amcstf_1.nmacvr = icanon[OTHER_ENDIAN_S(jtemp1 + 2)];
    amcstf_1.idlocn = amacro_1.macvst + 2;
    amcstf_1.numids = icanon[OTHER_ENDIAN_S(jtemp1 + 3)];
/* ...  INITIALIZE IDS FOR THIS MACRO CALL - PUT IN NEW VST LOCATIONS */
    imaxvs = amxtab_1.maxvs1 + (amcstf_1.numids << 1);
/* ...  IS THERE ROOM IN THE VST FOR THIS INFORMATION */
    if (imaxvs + amxtab_1.maxvs2 < amxtab_1.maxvst) {
	goto L1540;
    }
    a1com_1.jsuber = 15;
    goto L998;
L1540:
    ir = amxtab_1.maxvs1 + 2;
/* ...  WERE THERE ANY IDS IN THIS MACRO */
    if (amcstf_1.numids <= 0) {
	goto L1550;
    }
    jtemp1 = (ir << 1) - 1;
    i__1 = amcstf_1.numids;
    for (ii = 1; ii <= i__1; ++ii) {
	avst_1.vst[ir - 1] = avst_1.vst[amcstf_1.idlocn - 1];
	ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 8;
	ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = 0;
	amcstf_1.idlocn += 2;
	jtemp1 += 4;
/* L1545: */
	ir += 2;
    }
/* ...  UPDATE ID POINTER AND VST TABLE LIMIT */
    amcstf_1.idlocn = amxtab_1.maxvs1 + 2;
    amxtab_1.maxvs1 = imaxvs;
L1550:
    abreak_1.kanlcn = *kk + 3 + amcstf_1.nmacvr * 5;
    i__ = *kk + 4;
    j = *kk + 6;
/* ...  MOVE MACRO VAR. STANDARD VALUE TO CURRENT VALUE SPOT */
    if (amcstf_1.nmacvr <= 0) {
	goto L1570;
    }
    i__1 = amcstf_1.nmacvr;
    for (ii = 1; ii <= i__1; ++ii) {
	canon[j - 1] = canon[i__ - 1];
	canon[j] = canon[i__];
	i__ += 5;
/* L1560: */
	j += 5;
    }
L1570:
    aprint_(&c__7);
    goto L1600;

/* ...  SYSTEM MACRO DEFINITION MUST BE READ IN FROM MACRO LIBRARY */
/* ...  BRANCH IF READ/2 IS NOT IN EFFECT */
L1590:
    if (alibry_1.irdmod == 0) {
	goto L1595;
    }
/* ...  A READ/2 CANNOT READ IN THE FIRST CALL TO A SYSTEM MACRO */
    a1com_1.jsuber = 38;
    goto L998;
L1595:
    amcstf_1.macrd = 0;
    alibry_1.luup = a1com_1.loop;
    a1com_1.loop = 0;
    alibry_1.nwunrd = abreak_1.nwonrd;
    abreak_1.nwonrd = 0;
    alibry_1.segnam = a1com_1.name__;
    alibry_1.irdmod = -1;
/* ...  INDICATE SYSTEM MACRO MUST BE READ IN */
    alibry_1.isysmc = 1;
/* ...  *********************** ENABLE FOR NO LIBRY ********************* */
/* ...  IF (NOLIBR.EQ.1) GO TO 998 */
/* ...  ***************************************************************** */
    avst_1.vst[a1com_1.namsub - 1] = adata1_1.blanks;
    goto L998;
/* ...  BRANCH IF CALL STATEMENT HAD NO MACRO VARIABLES */
L1600:
    if (alibry_1.ivarct == 0) {
	goto L998;
    }
    m = 1;
/* ...  CHECK IF MACRO VARIABLE IN MACRO DEFINITION */
L1605:
    i__ = 1;
L1610:
    if (i__ <= amcstf_1.nmacvr) {
	goto L1630;
    }
/* ...  MACRO VARIABLE WAS NOT FOUND IN THE MACRO DEFINITION */
/* L1620: */
    a1com_1.jsuber = 228;
    goto L998;
/* ...  SET J TO START OF MACRO VARIABLES IN CANON */
L1630:
    j = *kk + i__ * 5 - 2;
    if (canon[j - 1] == alibry_1.amacvr[m - 1]) {
	goto L1640;
    }
    ++i__;
    goto L1610;
/* ...  FOUND MATCHING MACRO VARIABLE NAME IN MACRO DEFINITION */
L1640:
    canon[j + 2] = alibry_1.amacvl[m - 1];
    jtemp1 = (j << 1) - 1;
    icanon[OTHER_ENDIAN_S(jtemp1 + 8)] = alibry_1.macicl[m - 1];
    ++m;
/* ...  BRANCH IF ALL MACRO VARIABLES IN CALL STATEMENT MOVED */
    if (m > alibry_1.ivarct) {
	goto L1650;
    }
    goto L1605;
/* ...  TEST IF ANY MACRO VARIABLES STILL HAVE NO VALUES */
L1650:
    i__ = 1;
L1660:
    if (i__ <= amcstf_1.nmacvr) {
	goto L1670;
    }
    goto L998;
L1670:
    j = *kk + i__ * 5 + 1;
    if (canon[j - 1] == adata1_1.anodef) {
	goto L1680;
    }
    ++i__;
    goto L1660;
/* ...  UNDEFINED MACRO VARIABLE */
L1680:
    a1com_1.jsuber = 230;
    goto L998;
L998:
    if (a1com_1.jsuber == 0) {
	goto L999;
    }
/* ...  ERROR ON THIS CARD - DELETE THE CALL AND DO NOT EXECUTE THE MACRO */
    --amcstf_1.maccur;
    abreak_1.nrelcn = amxtab_1.maxvst + 1;
    if (amcstf_1.maccur == 0) {
	goto L1000;
    }
    amcstf_1.idlocn = amcstf_1.macids[amcstf_1.maccur - 1];
    abreak_1.kanlcn = amcstf_1.maclcn[amcstf_1.maccur - 1];
    jtemp1 = (abreak_1.kanlcn << 1) - 1;
    abreak_1.nrelcn = icanon[OTHER_ENDIAN_S(jtemp1 - 1)];
L999:
    return 0;
/* .. */
L1000:
    amcstf_1.idlocn = amcstf_1.isvid;
    amcstf_1.macrd = 0;
    if (abreak_1.nwonrd == 0) {
	a1com_1.loop = 0;
    }
    goto L999;
} /* amon7_ */

#undef kat
#undef gat
#undef icanon
#undef kk
#undef lclas1
#undef itemp
#undef ktemp
#undef canon
#undef ivst
#undef ptpp


