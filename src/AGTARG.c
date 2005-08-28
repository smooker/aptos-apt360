/* AGTARG.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

struct {
    doublereal stable[23];
} a1stab_;

#define a1stab_1 a1stab_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Table of constant values */

static integer c__6 = 6;
static integer c__1 = 1;
static integer c__0 = 0;

/* Subroutine */ int agtarg_(a, m, n)
doublereal *a;
integer *m, *n;
{
    /* Initialized data */

    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_6 = { 0, 9, 0. };


    /* Format strings */
    static char fmt_1011[] = "(\002 \002,\002 * * AGTARG PRINT * * \002)";
    static char fmt_1025[] = "(t1,\002+\002,t25,\002 SCALAR VALUE IS \002,f1\
4.8//)";
    static char fmt_1035[] = "(t1,\002+\002,t25,\002 SURFACE NAME, TYPE AND \
LENGTH \002,a6,3x,a8,i4,/(5x,5f14.8/))";
    static char fmt_1037[] = "(t1,\002+\002,t25,\002 EXPECTED CANON LENTH \
IS \002,i4,\002 ACTUAL LENGTH IS \002,i4,\002 NAME \002,a8,3x,a8/(5x,5f14.8/\
))";
    static char fmt_1045[] = "(t1,\002+\002,t25,\002 PUNCT. OR VOC. CODES\
 \002,i4,\002,\002,i2,//)";
    static char fmt_1055[] = "(t1,\002+\002,t25,\002 STATEMENT I.D. IS \002,\
a6//)";
    static char fmt_1065[] = "(t1,\002+\002,t25,\002 ERROR DIAGNOSTIC HAS BE\
EN OUTPUT \002//)";

    /* System generated locals */
    integer i__1;
    static doublereal equiv_7[1];

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
#define karg ((shortint *)&ascalr_1 + 726)
    static integer leng, lcnt, iret;
#define isto ((integer *)&adfsto_1)
#define ptpp ((doublereal *)&avst_1)
    static shortint ityp;
#define ivst ((integer *)&avst_1)
    static integer iname;
#define ifans ((integer *)&adfsto_1 + 6)
    static integer isign;
#define iptpp ((integer *)&avst_1)
    extern /* Subroutine */ int avs2ck_();
#define aa (equiv_7)
#define ia ((integer *)equiv_7)
    extern /* Subroutine */ int adiagm_();
    static shortint jk;
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer iv;
#define defans ((doublereal *)&adfsto_1 + 3)
    extern /* Subroutine */ int acangt_();
    static integer kt;
#define iercod ((integer *)&equiv_6)
#define kargpn ((shortint *)&ascalr_1 + 727)
#define knclus ((shortint *)&ascalr_1 + 726)
#define errcod ((doublereal *)&equiv_6)
    extern /* Subroutine */ int agtsub_(), aserch_(), ataprd_();
    static doublereal typsrf;
    extern /* Subroutine */ int azvalu_();
    static integer lsc;
    static doublereal sub;
    static integer ipt, lsr, lst;

    /* Fortran I/O blocks */
    static cilist io___28 = { 0, 0, 0, fmt_1011, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_1025, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_1035, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_1037, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_1045, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_1055, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_1065, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER IERCOD(2)/0,9/ */
/* .. */
/* .. */
    /* Parameter adjustments */
    --a;

    /* Function Body */
/* .. */
/* ... THIS SUBROUTINE CREATED FOR VERSION 4 MODIFICATION LEVEL 0 */
/* .. */
/* ..      ***        ***         ***     ***SJD**     ****      *** */
/* .. */
/* ..   A  IS AN 8-BYTE WORD WHERE DESIRED  ENTRY IS STORED */
/* ..   M  IS THE NUMBER OF 8-BYTE WORDS MAKING UP THE RETURN ENTRY */
/* ..   N  IS THE RETURN FLAG INDICATING THE TYPE OF ENTRY IN  'A' */
/* .    1    A SCALAR PLACED IN A */
/* ..   2   SURFACE PLACED IN AN ARRAY  (DEFSTO/DEFANS) */
/* ..   3   PUNCTUATION FOUND */
/* .    4   CANONICAL FORM EXCEEDS M. M NUMBER OF PARMS PLACED IN OUTPUT */
/* ..   5   VOCABULARY WORD   (PROTAP CODES PLACED IN  A) */
/* ..   6   STATEMENT I.D. */
/* .    7   ERROR */
/* ... */
/* ..   INITIALIZE ENTRY VAR. CODES */
/* .... I  IS THE PTPP CODE 1--8 ( FL.PT.NO.,VAR.SYMB.,SURF..ETC),, */
/* ..  WHEN I = 9 AN ARGUEMENT LIST HAS BEEN ENCOUNTERED OUT OF CONTEXT. */
/* ..   L   IS THE VST INDEX TO THE VARIABLE SYMBOL BEING PROCESSED */
/* ..   NAMSUB   IS INITIALIZED TO THE SUBSCRIPT TYPE ,,VAL. 0--3 */
/* ..   IPT IS THE ENTRY PICK UP INDEX, POINTS TO 4-BYTE ENTRIES */
/* .. */
    a2cls7_1.ename = (float)0.;
/* ..  SET FLAG INDICATING SIGN ASSIGNMENT IS PENDING */
    isign = 0;
    jk = 0;
L50:
    ipt = (a1com_1.indxpt << 1) - 1;
    a1pas2_1.i__ = iptpp[OTHER_ENDIAN_S(ipt - 1)];
    a1com_1.namsub = iptpp[OTHER_ENDIAN_S(ipt)];
    a1pas2_1.l = iptpp[OTHER_ENDIAN_S(ipt + 2)];
    ++a1com_1.indxpt;
/* .. */
/* ..   BRANCH ON ENTRY TYPE CODE */
/* ... BR. TO ASSIGN SCALAR A SIGN IF APPLICABLE */
    if (isign != 0) {
	goto L810;
    }
    switch ((int)a1pas2_1.i__) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L500;
	case 5:  goto L550;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L1210;
    }
/* ... */
/* ...         ***                ****               ****         **** */
/* .. */
/* ..    FLOATING POINT NUMBER */
L100:
    a[1] = ptpp[a1com_1.indxpt - 1];
    goto L405;
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* ..     NAMED SCALAR */
L200:
    a2cls7_1.ename = avst_1.vst[a1pas2_1.l - 1];
/* ...   CALL AGTSUB TO PLACE VALUE OF SUBSCRIPT INTO VST */
/* L210: */
    agtsub_();
    if (a1com_1.jsuber != 0) {
	goto L980;
    }
/* .. */
/* .. AVS2CK  USES 'NAME' AS THE VST INDEX */
/* ..  L  IS INDEX TO  SCALAR WORKING STORAGE WHERE SCALAR VALUE IS FOUND */
    a1com_1.name__ = a1pas2_1.l;
    avs2ck_(&iret);
/* ..  SET UP A POINTER TO 4-BYTE WORDS */
    iname = (a1com_1.name__ << 1) - 1;
/* .. */
    switch ((int)iret) {
	case 1:  goto L501;
	case 2:  goto L220;
	case 3:  goto L230;
	case 4:  goto L501;
	case 5:  goto L501;
	case 6:  goto L501;
	case 7:  goto L920;
	case 8:  goto L920;
	case 9:  goto L985;
	case 10:  goto L930;
	case 11:  goto L900;
    }
/* .. */
/* .. */
/* ..     SCALAR VARIABLE IS NOT INERROR, OUTPUT ITS VALUE */
L220:
    a1pas2_1.l = ivst[OTHER_ENDIAN_S(iname)];
    a[1] = ptpp[a1pas2_1.l - 1];
/* ..   AGTSUB INCREMENTS THE PICK UP INDEX ONE TOO MANY PLACES, OFFSET IT */
    --a1com_1.indxpt;
    goto L400;
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* ..  VARIABLE IS DEFINED AS A STATEMENT I.D. */
/* ..      RESET PICK UP INDEX TO SAVE DESIRED PICK UP LOCATION */
L230:
    a1com_1.indxpt += -2;
    goto L700;
/* .. */
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* ..   AN EXPRESSION IS FOUND  GET THE VALUE OF IT */
L300:

    a[1] = ascalr_1.scalr[a1pas2_1.l - 1];

    goto L400;
/* ... */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. ASSIGN SCALAR ITS SIGN AS FOLLOWS.... */
/* ..   NEG. SCALAR PRECEEDED BY A MINUS, CHANGE VALUE TO POSITIVE */
/*     POS. SCALAR PRECEEDED BY A MINUS, CHANGE VALUE TO NEGATIVE */
/*     A NEG. OR POS. SCALAR PRECEEDED BY A PLUS SIGN IS NOT CHANGED */
/* .. */
/* .. SCALAR FOUND  IS A SIGN PENDING */
L400:
    *aa = a[1];
    if (*aa == *errcod) {
	goto L985;
    }
L405:
    *n = 1;
    if (isign == 2) {
	goto L420;
    }
/* .. */
L410:
    ++a1com_1.indxpt;
    goto L990;
/* .. */
/* ..  CHANGE SIGN */
L420:
    a[1] = -a[1];
    goto L410;
/* .. */
/* .. */
/* ..***      ***              ***              ***                  *** */
/* .. */
/* ..   GET A    NAMED  SURFACE     VIA SUBROUTINE  ACANGT */
/* .. */
/* .. */
L500:
    if (*m == 1) {
	goto L910;
    }
    a2cls7_1.ename = avst_1.vst[a1pas2_1.l - 1];
/* ... GET SUBSCRIPT VALUE INTO VST, INCREMENT INDXPT TO NEXT PARAMETER */
    agtsub_();
    if (a1com_1.jsuber != 0) {
	goto L980;
    }
/* ... AVS2CHK USES 'NAME' AS THE VST INDEX, L CONTAINS INDEX */
/* ... AVS2CHK IS CALLED VIA ACANGT */
    a1com_1.name__ = a1pas2_1.l;
/* ...    DO NOT PROCESS IF PARAMETER IS IN ERROR - TEST FOR ERROR CODE */
    iv = (a1com_1.name__ << 1) - 1;
    if (ivst[OTHER_ENDIAN_S(iv + 1)] == 9) {
	goto L985;
    }
    acangt_();
    if (a1com_1.jsuber != 0) {
	goto L980;
    }
/* .. FOR A NORMAL SURFACE */
/* ..  THE CANONICAL FORM IN DEFSTO/DEFANS ALREADY VIA --ACANGT -- */
L501:
    leng = isto[OTHER_ENDIAN_S(1)] - 3;
    ityp = (shortint) isto[OTHER_ENDIAN_S(0)];
    if (ityp < 50) {
	goto L520;
    }
/* ...     SEE IF DEFINITION RETRIEVAL FROM SRFTAP WAS SUPPRESSED */
/* L505: */
    if (a1pas2_1.idtmov != 0) {
	goto L520;
    }
/* ...     NO - SEE WHETHER THERE WAS ENOUGH ROOM FOR IT - IF NOT, */
/* ...     IT WAS NOT READ IN */
    if (isto[OTHER_ENDIAN_S(9)] - *m >= 0) {
	goto L503;
    } else {
	goto L504;
    }

L520:
    if (leng > *m) {
	jk = (shortint) (*m);
    }
/* ...     MOVE THE FLOATING POINT PARAMETERS TO THE OUTPUT ARRAY */
/* ...     FOR NORMAL SURFACES ONLY */
    if (jk != 0) {
	leng = *m;
    }
    i__1 = leng;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
/* L525: */
	a[a1pas2_1.i__] = defans[a1pas2_1.i__ - 1];
    }
    if (jk == 0) {
	goto L504;
    }
/* ... THERE IS AN OVERFLO  ON EXPECTED CAN. LENGTH */
L503:
    *n = 4;
    goto L990;
/* .. */
/* ..  A SURFACE HAS BEEN OUTPUT VIA THE SPECIFIED ARRAY 'A' */
L504:
    *n = 2;
    goto L990;
/* .. */
/* .. */
/* ..   *       *       *      NESTED UNNAMED SURFACES  *    *     * */

/* ..      INCREMENT PICK-UP INDEX TO POINT TO NEXT PTPP ENTRY */
L550:
    ++a1com_1.indxpt;
    if (ascalr_1.scalr[a1pas2_1.l - 1] == *errcod) {
	goto L985;
    }
    if (ascalr_1.scalr[a1pas2_1.l - 1] != (float)0.) {
	goto L555;
    }
/* ...  SURFACE NOT DEFINED ON SRFTB */
    a1com_1.jsuber = 152;
    goto L980;
/* .. */
/* .. */
L555:
    adfsto_1.defsto[0] = ascalr_1.scalr[a1pas2_1.l - 1];
    leng = isto[OTHER_ENDIAN_S(1)];
/* .. FOR NORMAL SURFACES THE COMPLETE CANONICAL FORM IN ON SURFTB */
/* ..  FOR  PATERN, TABCYL, RLDSRF  ........ */
/* ..     THE HEADER DATA ONLY IS ON THE SURFTB, PLACED INTO DEFSTO(1)--5 */
/* .. THE FLOATING POINT PARAMETERS ARE ON THE SRFTAP FILE, COMMENCING */
/* ..  AT THE LOCATION INDEX GIVEN IN THE LO-ORD 4-BYTES OF DEFSTO(4) */
/* ..   CALL IT LCOMP */

    ++a1pas2_1.l;
    i__1 = leng;
    for (a1pas2_1.i__ = 2; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	adfsto_1.defsto[a1pas2_1.i__ - 1] = ascalr_1.scalr[a1pas2_1.l - 1];
/* L560: */
	++a1pas2_1.l;
    }
/* ..   BRANCH TO 501 TO PLACE THE NORMAL SURF. PARMS. INTO THE OUPUT AREA */
    ityp = (shortint) isto[OTHER_ENDIAN_S(0)];
    if (ityp <= 17) {
	goto L501;
    }
/* . **    **   TEST FOR NON-STANDARD /360 SURFACE CODES  **      ** */
    if (ityp >= 50) {
	goto L565;
    }
/* .. */
/* ..   MUST BE A USER IMPLEMENTED SURFACE */
    a1com_1.jsuber = 1002;
    goto L980;
/* .. */

/* ...     SEE IF DEFINITION RETRIEVAL FROM SRFTAP WAS SUPPRESSED */
L565:
    if (a1pas2_1.idtmov != 0) {
	goto L501;
    }
/* ...     NO - PICK UP THE SRFTAP RECORD NUMBER */
/* L570: */
    a1pas2_1.lcomp = ifans[OTHER_ENDIAN_S(1)];
/* ... IS SURFACE ALREADY IN CORE */
    if (a1pas2_1.lgerec != a1pas2_1.lcomp) {
	goto L580;
    }
/* .. YES IT IS IN CORE, IS IT IN THE PROPER LOCATION */
    if (a1pas2_1.idefp == a1pas2_1.lgeloc) {
	goto L504;
    }
/* ...     NO - TEST FOR ENOUGH SPACE FOR SURFACE IN DEFTAB AREA */
    if (ifans[OTHER_ENDIAN_S(3)] >= 1000 - a1pas2_1.idefp) {
	goto L503;
    }
/* ...     YES - READ IT IN */
L580:
    aserch_(&ataptb_1.srftap, &a1pas2_1.lcomp, &a1pas2_1.namsta);
    if (a1pas2_1.namsta >= 0) {
	goto L585;
    }
    ataprd_(&ataptb_1.srftap, &a1pas2_1.namsta, &lcnt, &c__6, &lsr, &c__1, &
	    lst, &c__1, &lsc, &c__1, &a2cls7_1.ename, &c__1, &sub, &c__1, &
	    deftab[a1pas2_1.idefp], &c__0);
    if (a1pas2_1.namsta >= 0) {
	goto L587;
    }
/* .. SET CORE LOCATION OF LARGE SURF. PARAMETERS ARE IN DEFTAB ARRAY */
    a1pas2_1.lgeloc = a1pas2_1.idefp;
    goto L504;
/* .. */
/* .. */
/* ..    SRFTAP COULD NOT BE POSITIONED PROPERLY TO BEGIN READING */
L585:
    a1com_1.jsuber = 179;
    goto L980;
/* .. */
/* ..   I/O ERROR WHILE READING UNNAMED LARGE SURFACE FROM SRFTAP */
L587:
    a1com_1.jsuber = 180;
    goto L980;
/* .. */
/* ..*** ***       ***       ***      ***   END OF SURFACE PROCESSING** */
/* .. */
/* .. */
/* ... VOCABULARY WORD */
L600:
    *n = 5;
    a[1] = ptpp[a1com_1.indxpt - 1];
/* .. A COMPUTING FUNCTION MAY BE PRECEEDED BY A + OR - */
    if (isign == 0) {
	goto L410;
    }
    *aa = a[1];
    if (ia[OTHER_ENDIAN_S(1)] != 8) {
	goto L940;
    }
    if (isign != 2) {
	goto L410;
    }
/* .. INDICATE TO ACLS12 THAT FUNCTION SIGN IS TO BE CHANGED */
    ia[OTHER_ENDIAN_S(1)] = isign;
    a[1] = *aa;
    goto L410;
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. STATEMENT I.D. */
L700:
    if (isign != 0) {
	goto L960;
    }
/* .. */
    *n = 6;
    a[1] = avst_1.vst[a1pas2_1.l - 1];
    goto L410;
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. PUNCTUATION FOUND */
/* ... */
L800:
    *n = 3;
    --a1com_1.indxpt;
    a1com_1.jsuber = 0;
    isign = a1com_1.namsub;
/* .. CHECK FOR PUNCTUATION ( NON-ARITHMETIC CODES) */
    if (isign < 6) {
	goto L805;
    }
/* .. WE HAVE PUNCTUATION,,COMMA,PERIOD,PARENS ONLY */
    a[1] = ptpp[a1com_1.indxpt - 1];
    goto L410;
/* .. */
/* ...    ONLY A PLUS OR MINUS SIGN FOLLOWED BY A SCALR IS ACCEPTABLE */
L805:
    if (isign > 2) {
	goto L950;
    }
/* .. */
/* ..  GET THAT SCALAR */
    ++a1com_1.indxpt;
    goto L50;
/* .. */
/* .. */
/* .. */
/* .. EXPECTING A SCALAR VALUE */
L810:
    switch ((int)a1pas2_1.i__) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L970;
	case 5:  goto L970;
	case 6:  goto L600;
	case 7:  goto L960;
	case 8:  goto L950;
    }
/* .. */
/* .. */
/* ..   **            **        **       ***              **             * */
/* .. */
/* .. */
/* .. */
/* ..  ILLEGAL V.S. USED IN A COMPUTING EXPRESSION */
L900:
    a1com_1.jsuber = 61;
    goto L980;
/* .. */
/* .. */
/* .. PARAMETER IS NOT A SCALAR VALUE */
L910:
    a1com_1.jsuber = 83;
    goto L980;
/* .. */
/* .. */
/* ...     UNDEFINED SYMBOL - TEST FOR OUTPUT OF DIAGNOSTIC HERE */
L920:
    if (ascalr_1.nsurf == 0) {
	goto L925;
    }
/* ...     NO - SET RETURN VARIABLE, AND EXIT */
    *n = 8;
    goto L990;
L925:
    a1com_1.jsuber = 101;
    goto L980;
/* .. */
/* .. */
/* ..  SUBSCRIPT EXCEEDS THE RESERV AREA */
L930:
    a1com_1.jsuber = 2004;
    goto L980;
/* .. */
/* .. */
/* .. ILLEGAL USE OF A VOCABULARY WORD */
L940:
    a1com_1.jsuber = 76;
    goto L980;
/* .. */
/* .. */
/* ... DOUBLE PUNCTUATION */
L950:
    a1com_1.jsuber = 54;
    goto L980;
/* .. */
/* .. */
/* ..  ILLEGAL USE OF A STATEMENT I.D. */
L960:
    a1com_1.jsuber = 52;
    goto L980;
/* .. */
/* .. */
/* ..  ILLEGAL USE OF A SURFACE */
L970:
    a1com_1.jsuber = 51;
    goto L980;
/* .. */
/* .. */
/* ..C.. OUTPUT AN ERROR MESSAGE THEN RETURN FOR FURTHER PROCESSING */
L980:
    adiagm_();
L985:
    *n = 7;
/* ...   **      **   EXIT ROUTINE  **   **        **   ** */
/* ..         RESET VARIABLES AND FLAGS */
L990:
    a1com_1.jsuber = 0;
    isign = 0;
/* .. */
/* .. RESET FLAG THAT ALLOWS ACCEPTANCE OF AN INCLUSIVE SUBSCRIPT */
/* ..  IF NOT PROCESSING ONE */
    if (*knclus != 2) {
	*knclus = 0;
    }
    ascalr_1.nsurf = 0;
    if (a1com_1.kdbug != 0) {
	goto L1010;
    }
L1000:
    return 0;
L1010:
    io___28.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___28);
    e_wsfe();
/* .. BRANCH ON OUTPUT TYPE CODES */
    switch ((int)*n) {
	case 1:  goto L1020;
	case 2:  goto L1030;
	case 3:  goto L1040;
	case 4:  goto L1030;
	case 5:  goto L1040;
	case 6:  goto L1050;
	case 7:  goto L1060;
    }
/* .. */
/* .. SCALAR */
L1020:
    io___29.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___29);
    do_fio(&c__1, (char *)&a[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1000;
/* .. */
/* ..  SURFACE */
L1030:
    leng = isto[OTHER_ENDIAN_S(1)] - 3;
    kt = isto[OTHER_ENDIAN_S(0)];
    if (leng != 2) {
	goto L1032;
    }
    kt += -31;
    leng = ifans[OTHER_ENDIAN_S(3)];
L1032:
    typsrf = a1stab_1.stable[kt - 1];
    if (*n == 4) {
	goto L1036;
    }
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&typsrf, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&leng, (ftnlen)sizeof(integer));
    i__1 = leng;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&defans[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L1000;
L1036:
    io___33.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___33);
    do_fio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&leng, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&typsrf, (ftnlen)sizeof(doublereal));
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 20; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&defans[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L1000;
/* .. */
/* ..  PUNCTUATION OR VOCABULARY WORD CODES */
L1040:
    *aa = a[1];
    io___34.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___34);
    do_fio(&c__1, (char *)&ia[OTHER_ENDIAN_S(0)], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ia[OTHER_ENDIAN_S(1)], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L1000;
/* .. */
/* .. STATEMENT I.D. */
L1050:
    io___35.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___35);
    do_fio(&c__1, (char *)&a[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1000;
/* .. */
/* .. ERROR--DIAGNOSTIC HAS BEEN OUTPUT */
L1060:
    io___36.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___36);
    e_wsfe();
    goto L1000;
/* ... */
/* ... */
/* ... */
/* ... */
/* ... */
/*   NESTED PARAMETER LIST FOUND - CAN ONLY BE USED AS A POINT DEF. */
/* ..    IS IT ACCEPTABLE */
L1210:
    if (*kargpn != 0) {
	goto L1220;
    }
/* .    NO ERROR */
L1215:
    a1com_1.jsuber = 253;
    goto L980;

/* ..   IT IS ACCEPTABLE - COMPUTE 4-BYTE INDEX TO REFERENCE WORD */
L1220:
    ipt = ((a1pas2_1.l + a1pas2_1.icanst - 1) << 1) - 1;
    ++a1com_1.indxpt;
/* ..   TEST FOR A SCALAR LIST */
    if (iptpp[OTHER_ENDIAN_S(ipt)] != 1) {
	goto L1215;
    }
/* ..   IT IS - PICK UP INDEX TO ARGUMENT LIST DATA BLOCK */
    a1pas2_1.l = iptpp[OTHER_ENDIAN_S(ipt - 1)];
/* ... COMPUTE INDEX TO PICK UP NUMBER OF ARGUMENTS */
    ipt = (a1pas2_1.l << 1) - 1;

/* ..  MOVE FIRST THREE SCALARS OF LIS ( THAT IS THE MAX. ACCEPTABLE) TO */
/* ..  THE DEFANS ARRAY */
    defans[0] = ptpp[a1pas2_1.l];
    defans[1] = ptpp[a1pas2_1.l + 1];
    defans[2] = ptpp[a1pas2_1.l + 2];
/* .. BRANCH ON ARGUMENT COUNT -- IF MORE THAN THREE IS AN ERROR */
    if ((i__1 = iptpp[OTHER_ENDIAN_S(ipt)] - 3) < 0) {
	goto L1230;
    } else if (i__1 == 0) {
	goto L1235;
    } else {
	goto L1215;
    }

/* ..   ONLY TWO COORDINATES GIVEN  -- COMPUTE THE Z-COORDINATE */
L1230:
    azvalu_();

/* ..   PUT TYPE AND LENGTH CODES FOR POINT INTO DEFSTO(1) */
L1235:
    isto[OTHER_ENDIAN_S(0)] = 1;
    isto[OTHER_ENDIAN_S(1)] = 6;
    goto L501;
} /* agtarg_ */

#undef errcod
#undef knclus
#undef kargpn
#undef iercod
#undef defans
#undef deftab
#undef ia
#undef aa
#undef iptpp
#undef ifans
#undef ivst
#undef ptpp
#undef isto
#undef karg


