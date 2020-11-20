/* ASCAN.f -- translated by f2c (version 20000121).
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
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

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
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static doublereal c_b63 = 10.;

/* Subroutine */ int ascan_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_34 = { {' ', 'E', 'N', 'T', 'R', 'Y', ' ', ' '}, 0. };

#define ent (*(doublereal *)&equiv_34)


    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double pow_di();

    /* Local variables */
    static integer noel, numb, nvdl, ncpw, mexp, nexp, nout, iflp2;
    static doublereal a;
    static integer i__, n, itspl, nonum;
    static doublereal intry, aa;
    extern /* Subroutine */ int adiagp_();
    static doublereal flchar;
    extern /* Subroutine */ int abuild_(), atblkp_();
#define kclass ((shortint *)&ailmtb_1 + 2400)
    static integer iclerr, iclent, itsadp, nremrk, ksuber, lastnf, maybev, 
	    nf4, numone, notanx, itspnc;
    extern /* Subroutine */ int aextrc_();
    static integer noe, nvd;
    static doublereal flp1;
	iclerr=2564;
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/*       INTEGER ICLERR/2564/ */
/*     THIS PROGRAM BREAKS A PART PROGRAM STATEMENT (ONE OR MORE CARDS) */
/*     INTO THE VARIOUS LANGUAGE ELEMENTS - I.E., VARIABLE SYMBOLS, */
/*     VOCABULARY WORDS, FLOATING POINT NUMBERS, AND PUNCTUATION. */
/*     THE RESULTANT INFORMATION IS STORED IN THE ELMENT AND ICLASS */
/*     ARRAYS IN COMMON. */
/* .....                                                               D39 */
/* .. */
/*               *     DEFINITION OF VARIABLE NAMES          * */
/*     MORE    ON ENTRY  LESS THAN, EQUAL ZERO INDICATES NEW STATEMENT */
/*                       GREATER THAN ZERO INDICATES CONTINUATION */
/*             ON EXIT   0  INDICATES END OF LOGICAL STATEMENT FOUND */
/*                       +1 INDICATES A CONTINUATION ($) CARD */
/*     ILMENT     TABLE FOR STORING NEW STATEMENT WORDS */
/*     JLMENT     NUMBER OF ENTRIES IN THE  ILMENT  TABLE */
/*     ATYPE      ARRAY INDICATING TYPE OF WORD IN ILMENT  - AS FOLLOWS */
/*                    = 1  VARIABLE SYMBOL */
/*                    = 2  VOCABULARY */
/*                    = 3  NUMBER */
/*                    = 4  PUNCTUATION */
/*     BCLAS      CLASSIFICATION WORD, BASED ON ATYPE */
/*       ATYPE = 1  LEAVE BLANK */
/*             = 2  DOUBLE-ENTRY WORD  (CLASS,,SUBCLASS) */
/*             = 3  ACTUAL FLOATING POINT NUMBER */
/*             = 4  PUNCTUATION CODE 1 IS +, 2 IS -, 3 IS /, 4 IS * */
/*                  5 IS **, 6 IS (, 7 IS), 8 IS =, 9 IS , */
/*     CCODE      PROTAPE CODE (FROM XTABL) WHEN APPLICABLE */
/*     JSUBER     APT ERROR FLAG (SEE PART PROGRAMMING MANUAL) */
/*     INWORD     ARRAY CONTAINING ORIGINAL CARD IMAGE (STORED AS 14A6) */
/*     NCARDW     SUBSC. OF WORD IN INWORD WHICH IS BEING PROCESSED */
/*     JOE        WORD BEING PROCESSED     = INWORD(NCARDW) */
/*     NCINWD     SUBSC. OF CHARACTER IN INWORD(NCARDW) BEING PROCESSED */
/*     CHAR       ACTUAL CHARACTER (BCD) BEING PROCESSED */
/*     A          WORD BEING BUILT UP FOR THE ILMENT TABLE */
/*     NCPW       NUMBER OF CHARACTERS CURRENTLY IN  A */
/*     MAYBEV     =1 IF CURRENT WORD COULD BE A NO. OR VARIABLE SO FAR */
/*     NUMB       FLAG INDICATING A NUMBER IS BENG FORMED (IF SO, = 1) */
/*     MEXP       FLAG INDICATING AN EXPONENT IS BEING FORMED */
/*     ITSPNC     FLAG INDICATING PREVIOUS CHARACTER WAS PUNCTUATION */
/*     NF         FLAG SET BY SUBROUTINE TESTCH  (SEE BELOW) */
/*     LASTNF     PREVIOUS VALUE OF NF (NEEDED TO BUILD UP A ** ) */
/*     MDOLAR     INDICATES A $ WAS FOUND  - NOW CHECK FOR $$ */
/*     IFIRST     = 0  ON INITIAL ENTRY TO THE SCAN ROUTINE */
/*     NREMRK  = 1 IF A REMARK CARD WAS FOUND, OTHERWISE  NREMRK = 0 */
/*     ITSPL      FLAG INDICATING SIGN OF EXPONENT FOR FLOAT. PT. NO. */
/*     ITSADP     FLAG INDICATING DECIMAL PT. IN FLOAT. PT. NO. */
/*     NOE        NO. OF PLACES TO THE RIGHT OF THE DECIMAL POINT */
/*     NOEL       NO. OF PLACES TO THE LEFT OF THE DECIMAL POINT */
/*     NVD        NO. OF SIGNIFICANT DIGITS RIGHT OF THE DECIMAL POINT */
/*     NVDL       NO. OF SIGNIFICANT DIGITS LEFT OF THE DECIMAL POINT */
/*     NONUM      = 0 IF NOTHING BUT ZEROES FOUND IN THE INPUT NUMBER */
/*     NUMONE     CHAR. COUNT IN THE NUMBER (OR POSSIBLE VARIABLE) MODE */
/*     NOTANX     =1 IF NO. ALREADY PUT IN ELMENT TABLE, =0 IF NOT */
/*     NEXP       VALUE OF EXPONENT USED IN BUILDING UP NUMBER */
/*     NOUT       =1 IF FINISHED A CARD WHILE BUILDING UP A NUMBER */
/*               *          *          *          *          * */
/*             FUNCTIONS AND NAMES OF REQUIRED SUBROUTINES */
/*               *          *          *          *          * */
/*     EXTRCT(A,B)  EXTRACTS LEFT MOST CHARACTER FROM A AND STORES IT IN */
/*                  B. THE NEW LEFT-JUSTIFIED WORD IS STORED BACK IN A */
/*     BUILD(A,B)   SHIFTS A LEFT 6 BITS AND PUTS B IN LOCATIONS 30-35 */
/*     FIXFLD(A,B)  SETS FLAG ON COLS. 1-6  AS FOLLOWS */
/*                     -1  INDICATES A REMARK  - CARD IS THEN DELETED */
/*                      0  INDICATES THERE WAS NO FIXED FIELD WORD */
/*                     +1  INDICATES TITLES, PARTNO, PPRINT, OR INSERT */
/*     TBLKUP(W,B,C) SEARCHES XTABLE FOR W  - IF NOT IN XTABLE, B = 0 */
/*                   IF IN XTABLE, THEN B = CLASS,,SUB-CLASS.AND C IS THE */
/*                   PROTAP CODE (IF APPLICABLE) */
/*          IF    A = 0    , NF = 0          IF    A = 1-9  , NF = 1 */
/*          IF    A = $    , NF = 2          IF    A = BLANK, NF = 3 */
/*          IF    A = +    , NF = 4          IF    A = -    , NF = 5 */
/*          IF    A = *    , NF = 6          IF    A = .    , NF = 7 */
/*          IF    A = ,    , NF = 8          IF    A = (    , NF = 9 */
/*          IF    A = )    , NF = 10         IF    A = =    , NF = 11 */
/*          IF    A = /    , NF = 12         IF    A = E    , NF = 13 */
/*          IF    A = A THRU D   OR  F    THRU  Z  ,  THEN    NF = 14 */
/*     TABLEM     MAIN ROUTINE FOR CONSTRUCTING ATYPE, BCLAS, AND CCODE */
/*     SYNLKR     SEARCHES THE SYN TABLETO SEE IF VARIABLE NAME APPEARS */
/*               *          *          *          *          * */
/*         END OF PROSE  -  START OF CON */
/*               *          *          *          *          * */
    if (ainpot_1.ifirst != 0) {
	goto L20;
    }
/* ...  FIRST ENTRY FOR THIS PART PROGRAM */
    ainpot_1.ifirst = 1;
    goto L30;
L20:
    if (ainpot_1.more > 0) {
	goto L40;
    }

/* ...  FIRST ENTRY FOR THIS STATEMENT (NOT A CONTINUATION CARD) */
L30:
    itspl = 1;
    i__1 = amxtab_1.maxelm;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L31: */
	ailmtb_1.iclass[i__ - 1] = 0;
    }
    itsadp = 0;
    nremrk = 0;
    ksuber = 0;
    nf4 = 0;
    noe = 0;
    noel = 0;
    flp1 = 0.;
    iflp2 = 0;
    ascanc_1.mdolar = 0;
    nonum = 0;
    nvd = 0;
    nvdl = 0;
    lastnf = 0;
    maybev = 0;
    numone = 0;
    numb = 0;
    notanx = 0;
    ailmtb_1.jlment = 0;
    ncpw = 0;
    itspnc = 1;
    a = adata1_1.blanks;
    aa = adata1_1.blanks;
    mexp = 0;
    nexp = 0;
    ascanc_1.n72 = 0;
    ascanc_1.numcol = 0;

/* ...     DOES STATEMENT START WITH FIXED FIELD WORD */
    intry = ainpot_1.inword[0];
    atblkp_(&intry, &n, &c__1);
    if (n == 0) {
	goto L50;
    }
    ailmtb_1.iclass[0] = n + 2;
    if (kclass[OTHER_ENDIAN_S(0)] != 2) {
	goto L34;
    }

/* ...  FIX. FIELD WORD - REMARK */
/* ...     SET FLAG REQUESTING NEW STATEMENT */
/* L32: */
    ainpot_1.more = -1;
    nremrk = 1;
    goto L160;

/* ...  FIX. FIELD WORD - PARTNO,INSERT,TITLES,PPRINT */
L34:
    for (i__ = 2; i__ <= 12; ++i__) {
	ailmtb_1.elment[i__ - 1] = ainpot_1.inword[i__ - 1];
/* L36: */
	ailmtb_1.iclass[i__ - 1] = 3;
    }
    ailmtb_1.elment[0] = ainpot_1.inword[0];
    ailmtb_1.jlment = 12;
    ainpot_1.more = 0;
    goto L160;

/* ...     IF ELMENT TABLE OVERFLOW OCCURRED ON PREVIOUS LINE, RESET */
/* ...     STORING INDEX AND ADJUST OVERFLOW FLAG */
L40:
    if (ascanc_1.jskip <= 0) {
	goto L50;
    }
    ailmtb_1.jlment = 0;
    ascanc_1.jskip = -1;

/* ...     NOT A FIXED FIELD WORD - PROCESS NORMALLY */
L50:
    ascanc_1.numcol = 0;
    ascanc_1.n72 = 0;
    if (nremrk != 0) {
	goto L30;
    }
L60:

/* ...     GET NEXT NON-BLANK CHARACTER */
    aextrc_();
/* ...     TEST FOR END OF CARD FOUND (NF NEGATIVE) */
    if (ascanc_1.nf >= 0) {
	goto L170;
    }
/* ...     YES */
/* ...     TEST FOR CONTINUATION SIGN FOUND */
/* L90: */
    if (ascanc_1.mdolar == 1) {
	goto L100;
    }
/* ...  NO - NORMAL EXIT */
    ainpot_1.more = 0;
    goto L110;

/* ...  YES - CONTINUATION MODE. RETURN FOR MORE DATA */
L100:
    ascanc_1.mdolar = 0;
    ainpot_1.more = 1;
    goto L160;

L110:
    nout = 1;
/* ...  BRANCH IF FLOATING POINT NUMBER TO BE OUTPUT */
    if (numb == 1) {
	goto L420;
    }
/* ...     IF LAST CHARACTER NOT PUNCTUATION, SYMBOL STILL TO */
/* ...     BE ADDED TO ELMENT TABLE */
    if (itspnc == 1) {
	goto L111;
    }

/* ...  OUTPUT LAST ENTRY */
    ++ailmtb_1.jlment;
/* ...     TEST FOR ROOM IN TABLE */
    if (ailmtb_1.jlment > amxtab_1.maxelm) {
	goto L999;
    }
/* ...     YES - PUT LAST SYMBOL INTO IT */
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = 1;
    atblkp_(&a, &n, &c__0);
    ailmtb_1.elment[ailmtb_1.jlment - 1] = a;
    if (n == 0) {
	goto L111;
    }
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = n + 2;
L111:
    nout = 0;
L160:
    a1com_1.jsuber = ksuber;
    return 0;

/* ...     NOT END OF CARD - TEST CHARACTER FOR CONTINUATION */
L170:
    if (ascanc_1.nf != 2) {
	goto L210;
    }
/* ...    $  FOUND */
/* L180: */
    if (ascanc_1.mdolar == 1) {
	goto L200;
    }
/* ...  FIRST  $ FOUND - POSSIBLE CONTINUATION */
/* L190: */
    ascanc_1.mdolar = 1;
    goto L60;

/* ...     SECOND $ FOUND - END OF STATEMENT - IGNORE ANY */
/* ...     FURTHER MATERIAL ON THIS CARD */
L200:
    ainpot_1.more = 0;
    goto L110;

/* ...     IF $ FOUND PREVIOUSLY, CONTINUATION - IGNORE */
/* ...     ANY FURTHER MATERIAL ON THIS CARD */
L210:
    if (ascanc_1.mdolar == 1) {
	goto L100;
    }

    if (maybev != 1) {
	goto L215;
    }
/* ...  ENTRY COULD BE A VARIABLE NAME OR A NUMBER */
/* L211: */
    ++numone;
    if (numone <= 6) {
	goto L212;
    }
/* ...  TOO MANY SYMBOLS - MUST BE A NUMBER OR AN ERROR */
    maybev = 0;
    aa = adata1_1.blanks;
    goto L215;

/* ...  BUILD UP WORD */
L212:
    abuild_(&aa, &ascanc_1.char__);
/* ...  ALLOW AN E IN A NUMBER FOR BUILDING UP AN EXPONENT - JUST ONCE */
    if (mexp == 0) {
	goto L213;
    }
/* ...     ONE 'E' ALREADY FOUND - ALLOW NO MORE */
    if (ascanc_1.nf < 13) {
	goto L215;
    }
    goto L214;
/* ...     NO 'E' YET - ALLOW ONE IN THE NUMBER (NF = 13 FOR AN E) */
L213:
    if (ascanc_1.nf < 14) {
	goto L215;
    }
/* ...  ILLEGAL NUMBER STRUCTURE - MUST BE A VARIABLE NAME OR VOCABULARY */
L214:
    numb = 0;
    noe = 0;
    noel = 0;
    nvdl = 0;
    nvd = 0;
    a = aa;
    ncpw = numone;
    nonum = 0;
    nf4 = 1;
    itspl = 1;
    flp1 = 0.;
    itsadp = 0;
    mexp = 0;
    nexp = 0;
    iflp2 = 0;
/* .. IF A DECIMAL IS ENCOUNTERED AND IS EXPECTED BUILD UP A NUMBER */
/* .. IF PUNCTUATION IS NEITHER DECIMAL NOR EXPONENTIATION, OUTPUT */
/* .. THE PREVIOUS VAR. SYMBOL (IF APPLICABLE) AND SET FLAG INDICATING */
/* .. PUNC. CHAR. WAS THE TERMINATION OF PREV. ENTRY BEING BUILT UPOUTPUT */
/* ..   THE PUNCTUATION TO ICLASS/ELMENT TABLE */
L215:
    if (ascanc_1.nf != 7) {
	goto L220;
    }
/* .. DOES DE. BELONG TO A NUMBER BEING BUILT */
    if (numb != 0) {
	goto L340;
    }
/* ..  COULD THIS BE A NUMBER COMMENCING WITH A DECIMAL */
    if (itspnc == 1) {
	goto L280;
    }
/* ...     DECIMAL IS ALONE - WILL BE CHANGED TO AN ERROR CODE */
    goto L900;
/* .. */
/* ...     SET UP POSSIBLE PUNCTUATION CODE FOR ICLASS TABLE ENTRY */
L220:
    iclent = adata1_1.ic[ascanc_1.nf - 3];
/* ...     SEE IF CHARACTER JUST READ IS PUNCTUATION */
L222:
    if (ascanc_1.nf < 3) {
	goto L270;
    }
    if (ascanc_1.nf >= 13) {
	goto L270;
    }

/* ...     YES - TEST FOR NUMBER ALREADY BEING BUILT */
L225:
    if (numb != 1) {
	goto L230;
    }
/* ...     NUMBER BEING BUILT - MAKE SURE SOME DIGITS WERE GIVEN - IF */
/* ...     NOT, ERROR */
    if (iflp2 != 0) {
	goto L270;
    }

/* ...     NO DIGITS - OUTPUT AN ERROR CODE HERE... */
/* ...     INCREMENT ELMENT TABLE INDEX, AND TEST FOR ENOUGH SPACE */
    ++ailmtb_1.jlment;
    if (ailmtb_1.jlment > amxtab_1.maxelm) {
	goto L999;
    }
/* ...     OUTPUT THE ERROR CODE */
    ailmtb_1.elment[ailmtb_1.jlment - 1] = 0.;
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = iclerr;
    itspnc = 1;
    itsadp = 0;
    numb = 0;
/* ...     GO TO OUTPUT ERROR DIAGNOSTIC */
    goto L900;

/* ...     NUMBER NOT BEING BUILT */
L230:
    aa = adata1_1.blanks;
/* ...     SEE IF PREVIOUS CHARACTER WAS PUNCTUATION */
/* L240: */
    if (itspnc == 1) {
	goto L252;
    }
/* ...     IF ERROR FLAG SET, PRINT DIAGNOSTIC */
/* L250: */
    if (a1com_1.jsuber == 0) {
	goto L251;
    }
    adiagp_();
    ksuber = a1com_1.jsuber;
    a1com_1.jsuber = 0;
/* ..  SET FLAG TO INDICATE TERMINATING PUNCT. CHAR. JUST FOUND */
L251:
    itspnc = 1;
/* ...     IF NUMBER ALREADY PUT INTO ELMENT TABLE, GO TO */
/* ...     OUTPUT PUNCTUATION */
    if (notanx == 1) {
	goto L260;
    }

/* ..      OUTPUT PREVIOUS VARIABLE SYMBOL TO ICLASS/ELMENT TABLE */
    ++ailmtb_1.jlment;
    if (ailmtb_1.jlment > amxtab_1.maxelm) {
	goto L999;
    }
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = 1;
    atblkp_(&a, &n, &c__0);
    ailmtb_1.elment[ailmtb_1.jlment - 1] = a;
    if (n == 0) {
	goto L260;
    }
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = n + 2;
    goto L260;

/* ...     LAST ENTRY WAS PUNCTUATION */
L252:
    if (lastnf != 6) {
	goto L260;
    }
    if (ascanc_1.nf != 6) {
	goto L260;
    }
/* ...  OUTPUT A ** */
    iclent = adata1_1.ic[4];
    lastnf = 0;
    goto L265;

/* ...     OUTPUT THE PUNCTUATION */
L260:
    ++ailmtb_1.jlment;
    if (ailmtb_1.jlment > amxtab_1.maxelm) {
	goto L999;
    }
    notanx = 0;
    a = adata1_1.blanks;
    abuild_(&a, &ascanc_1.char__);
    lastnf = ascanc_1.nf;
L265:
    ailmtb_1.elment[ailmtb_1.jlment - 1] = 0.;
    a = adata1_1.blanks;
/* ...     ENTER THE PUNCTUATION TYPE CODE */
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = iclent;
    ncpw = 0;
    numone = 0;
    maybev = 0;
    goto L60;

/* ...     CHARACTER JUST FOUND IS NOT PUNCTUATION - IF PREVIOUS */
/* ...     CHARACTER PUNCTUATION, INITIALIZE FOR SYMBOL BUILD-UP */
L270:
    if (itspnc != 1) {
	goto L300;
    }
/* ...     INITIALIZE TO BEGIN NUMBER MODE */
L280:
    lastnf = 0;
    numb = 0;
    ncpw = 0;
    itspnc = 0;
/* ...  IS IT A DECIMAL POINT */
    if (ascanc_1.nf - 7 != 0) {
	goto L285;
    } else {
	goto L290;
    }
L285:
    if (ascanc_1.nf > 1) {
	goto L300;
    }
/* ...  CHARACTER WAS A NUMBER */
    maybev = 1;
    abuild_(&aa, &ascanc_1.char__);
L290:
    numb = 1;
    numone = 1;
/* ...  TRANSFER FOR NUMBER MODE */
L300:
    if (numb == 1) {
	goto L340;
    }
    if (nf4 == 0) {
	goto L310;
    }
    nf4 = 0;
    ncpw = numone;
    goto L60;

L310:
    if (ncpw < 6) {
	goto L330;
    }
/* ...  TOO MANY CHARACTERS IN A VARIABLE NAME. */
/* L320: */
    a1com_1.jsuber = 1;
    ksuber = a1com_1.jsuber;
    goto L60;

L330:
    ++ncpw;
/* L335: */
    abuild_(&a, &ascanc_1.char__);
    goto L60;

/* ...  BUILD UP NUMBER HERE */
/* ...     IF NUMERIC CHARACTER, SET FLAG TO INDICATE ONE READ */
L340:
    if (ascanc_1.nf > 1) {
	goto L342;
    }
    iflp2 = 1;
/* ...     SEE IF ANYTHING OTHER THAN ZEROES HAS BEEN PROCESSED */
L342:
    if (nonum != 0) {
	goto L345;
    }
/* ...  NO - TRANSFER IF THIS ENTRY IS A DECIMAL POINT */
    if (ascanc_1.nf == 7) {
	goto L485;
    }
    if (ascanc_1.nf != 0) {
	goto L344;
    }
    if (itsadp != 1) {
	goto L60;
    }
/* ...     ANOTHER ZERO TO RIGHT OF DECIMAL POINT - INCREMENT */
/* ...     VALUE OF NEGATIVE EXPONENT */
    ++noe;
    goto L60;

/* ...  SOMETHING OTHER THAN ZERO FOUND */
L344:
    nonum = 1;
L345:
    if (mexp < 0) {
	goto L350;
    } else if (mexp == 0) {
	goto L440;
    } else {
	goto L390;
    }
/* ...  PROCESS EXPONENTS */
L350:
    mexp = 1;
    if (ascanc_1.nf == 5) {
	goto L370;
    }
    if (ascanc_1.nf - 4 != 0) {
	goto L390;
    } else {
	goto L60;
    }
L370:
    itspl = 0;
    goto L60;
L390:
    if (ascanc_1.nf > 1) {
	goto L420;
    }
//    nexp = nexp * 10 + ascanc_1.ichar;
    nexp = nexp * 10 + ascanc_1.ichar-48;
    goto L60;

/* ...  CONVERT TO PROPER FLOATING POINT NUMBER */
L420:
    if (nonum != 0) {
	goto L425;
    }
    a = 0.;
    goto L435;
L425:
    a = flp1;
/* ...     IF AN 'E' EXPONENT GIVEN, INCORPORATE IT IN NUMBER */
    if (mexp == 0) {
	goto L435;
    }
/* ...     YES - ADJUST EXPONENT SIGN, IF NECESSARY */
    if (itspl == 1) {
	goto L430;
    }
    nexp = -nexp;
L430:
    a *= pow_di(&c_b63, &nexp);

/* ...  OUTPUT NUMBER, RESET FLAGS */
L435:
    noe = 0;
    noel = 0;
    nvdl = 0;
    nvd = 0;
    nonum = 0;
    itspl = 1;
    itsadp = 0;
    mexp = 0;
    nexp = 0;
/* L625: */
    ++ailmtb_1.jlment;
    if (ailmtb_1.jlment > amxtab_1.maxelm) {
	goto L999;
    }
/* L630: */
    flp1 = 0.;
    iflp2 = 0;
    ailmtb_1.elment[ailmtb_1.jlment - 1] = a;
    ailmtb_1.iclass[ailmtb_1.jlment - 1] = 3;
    numone = 0;
    ncpw = 0;
    a = adata1_1.blanks;
    aa = adata1_1.blanks;
    notanx = 1;
    numb = 0;
    if (ascanc_1.nf == 7) {
	goto L436;
    }
    if (ascanc_1.nf < 13) {
	goto L438;
    }
/* ...  BAD NUMBER FORMAT */
L436:
    a1com_1.jsuber = 4;
    ksuber = a1com_1.jsuber;
L438:
    if (nout == 1) {
	goto L111;
    }
    goto L222;

L440:
    if (ascanc_1.nf > 1) {
	goto L480;
    }
/* ...  PROCESS NUMERIC CHARACTER */
/* L450: */
    if (itsadp != 0) {
	goto L460;
    }
/* ...  ADD CHARACTER LEFT OF DECIAML POINT (INTEGER PART OF NUMBER) */
    ++noel;
    if (noel >= 17) {
	goto L505;
    }
//    flchar = (doublereal) ascanc_1.ichar;
	//subtract 48 to convert from ascii to int
    flchar = (doublereal) (ascanc_1.ichar-48);
    flp1 = flp1 * 10. + flchar;
    goto L60;

/* ...  ADD CHARACTER RIGHT OF DECIMAL POINT (FRACTIONAL PART OF NUMBER) */
L460:
    ++noel;
    ++noe;
    if (noel >= 17) {
	goto L505;
    }
//    flchar = (doublereal) ascanc_1.ichar;
    flchar = (doublereal) (ascanc_1.ichar-48);
    flp1 += flchar / pow_di(&c_b63, &noe);
    goto L60;

L480:
    if (ascanc_1.nf != 7) {
	goto L500;
    }
L485:
    if (itsadp == 1) {
	goto L900;
    }
/* ...  PROCESS DECIAML POINT */
    itsadp = 1;
    maybev = 0;
/* ..  GET NEXT  NON-BLANK CHARACTER */
    goto L60;

L500:
    if (ascanc_1.nf != 13) {
	goto L420;
    }
/* ...  SET EXPONENT FLAG */
/* .. AN 'E' IS FOUND IF NO PREVIOUS DECIMAL THEN OUTPUT AS VAR.SYMB. */
    if (itsadp == 0) {
	goto L214;
    }
    mexp = -1;
    goto L60;

L505:
    a1com_1.jsuber = 2;
/* L515: */
    ksuber = a1com_1.jsuber;
    goto L60;
/* .. */
/* ..  OUTPUT THE ERROR ELEMENT LOC. AS THE SUBSC. VAL OF  ENTRY */
/* ...     ILLEGAL ENTRY - A DECIMAL FOUND OUT OF CONTEXT - CHANGE TO */
/* ...     AN ERROR CODE */
L900:
    a1com_1.jsuber = 20;
    a1com_1.name__ = ent;
    aptpp_1.pt[6] = (doublereal) ailmtb_1.jlment;
    a1com_1.sum = 9;
    adiagp_();
    a1com_1.jsuber = 0;
    iclent = iclerr;
    lastnf = ascanc_1.nf;
/* ...     CHANGE NF CODE TO COMMA */
    ascanc_1.nf = 8;
    goto L225;
/* ...     ELMENT TABLE OVERFLOW */
L999:
    a1com_1.jsuber = 13;
    ascanc_1.jskip = 1;
    return 0;
} /* ascan_ */

#undef kclass
#undef ent


