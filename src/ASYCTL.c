/* ASYCTL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal protap, dumtap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

static struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

static struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal deflst[1];
} adfprl_;

#define adfprl_1 adfprl_

static struct {
    doublereal defprg[16];
} adfprg_;

#define adfprg_1 adfprg_

static struct {
    doublereal zsur[4];
} azurf_;

#define azurf_1 azurf_

static struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

static struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;
static integer c__0 = 0;
static integer c__2 = 2;

/* Subroutine */ int asyctl_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_63 = { {' ', ' ', ' ', ' ', 'I', 'D', ' ', ' '}, 0. };

#define id (*(doublereal *)&equiv_63)

    static doublereal pratno[11] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };

    /* Format strings */
    static char fmt_1[] = "(\0020* * * PROCESSING DELETED -- REFER TO ERROR \
DIAGNOSTIC\rAT ISN \0021i4,\002 * * * * \002///)";
    static char fmt_65[] = "(\0020\002,i12)";
    static char fmt_66[] = "(i7,5z18/(7x,5z18))";
    static char fmt_110[] = "(1x,i5,2x,13a6,a2)";
    static char fmt_130[] = "(8x,13a6,a2)";
    static char fmt_210[] = "(\0020***** CARD NO.\0022x,a6,a2,\002,ISN\002i5\
/(\002 **** \002,10a8,\002 **** \002))";
    static char fmt_215[] = "(\002 \002)";
    static char fmt_1810[] = "(\0020******PTPP RECORD FORMAT INCORRECT\0023i\
6/\002 \002)";
    static char fmt_1910[] = "(\0020******SYSTEM TAPE ERROR,IOFLAG=\002i6\
/\002 \002)";

    /* System generated locals */
    integer i__1;
    static integer equiv_10[1];
    static doublereal equiv_12[2];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define vst4 ((integer *)&avst_1)
#define svec ((doublereal *)&adfprg_1)
#define iseq ((shortint *)equiv_12)
#define tvec ((doublereal *)&adfprg_1)
    static integer iisn, kret;
#define xlar ((doublereal *)&adfprg_1 + 12)
#define ylar ((doublereal *)&adfprg_1 + 12)
    static doublereal fnum;
#define tnor ((doublereal *)&adfprg_1 + 3)
#define xsml ((doublereal *)&adfprg_1 + 12)
#define ysml ((doublereal *)&adfprg_1 + 12)
#define ptpp ((doublereal *)&avst_1)
#define kvst ((shortint *)&avst_1)
    static integer name4;
#define ambda ((doublereal *)&adfprg_1 + 6)
#define v ((doublereal *)&adfprg_1 + 3)
#define nhalf (equiv_10)
    extern /* Subroutine */ int acls12_();
#define canon ((doublereal *)&avst_1)
    static shortint jdsav;
    static doublereal value;
#define svecn ((doublereal *)&adfprg_1 + 9)
#define puvec ((doublereal *)&adfprg_1 + 3)
#define c3 ((doublereal *)&adfprg_1)
#define iptpp ((integer *)&avst_1)
    static integer loops, nwrds;
#define punor ((doublereal *)&adfprg_1 + 6)
#define v1 ((doublereal *)&adfprg_1 + 3)
    extern /* Subroutine */ int aclas5_();
#define nhalf2 ((shortint *)equiv_10)
#define xynor ((doublereal *)&adfprg_1)
    extern /* Subroutine */ int adiagm_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    static integer ioflag;
    extern /* Subroutine */ int adfpre_();
#define cantap ((doublereal *)&ataptb_1 + 5)
#define xo ((doublereal *)&adfprg_1 + 9)
    static shortint iflush;
#define errtap ((doublereal *)&ataptb_1 + 9)
#define ptptap ((doublereal *)&ataptb_1 + 3)
#define jprotp ((integer *)&aprotp_1)
#define iscalr ((integer *)&ascalr_1)
    static integer nparts, kindxp;
    extern /* Subroutine */ int ataprd_(), arfsys_(), acpytp_(), aritap_(), 
	    atapop_(), ascntl_(), aseqal_();
#define ans ((doublereal *)&adfprg_1 + 6)
    static integer newrec;
    extern /* Subroutine */ int aserch_(), agtarg_();
    static integer istore;
    extern /* Subroutine */ int agtsub_(), asclpt_();
#define seq (equiv_12)
    extern /* Subroutine */ int azsurf_(), acalsp_();
    static integer igotit;
    extern /* Subroutine */ int arglst_();
    static integer ktm1;

    /* Fortran I/O blocks */
    static cilist io___37 = { 0, 0, 0, fmt_1, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_66, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_66, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_130, 0 };
    static cilist io___49 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_215, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_1810, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_1910, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* *    THIS SUBPROGRAM IS THE PASS 2 CONTROL FOR THE LANGUAGE TRANSLATOR */
/* *    IT PROCESSES THE PTPP META-LANGUAGE FILE OUTPUT OF PASS 1 */
/* *    PTPP CLASSES 0,1,2,7,8,10, AND 11 ARE PROCESSED DIRECTLY */
/* *    FOR ALL CLASSES, KLASTP=CLASS TYPE */
/* *    FOR ALL CLASSES EXCEPT 0,1,7, AND 8,KLASCT=PTPP WORDS IN CLASS */
/* *    FOR CLASSES 1 AND 7,KLASCT=ISN,FOR CLASS 8,FINI,DEBUG,PRINT FLAGS */
/* *    ASYCTL MAY BE RE-ENTERED BY RETURN CALL FROM SPECIAL PROGRAM */
/* *    IN THIS CASE ISPPRG FLAG MUST BE SET NON-ZERO */
/* *    THIS ROUTINE MAY SET JSUBER TO ERROR NUMBERS 402 AND 408 */



/* ... */
/*      DATA PRATNO/'REMARK  .. THI  S IS T  HE HEA  DING Y  OU GET   WHEN */
/*     1   NO PAR  TNO HA  S BEEN   GIVEN  '/ */
    for (a1pas2_.i__ = 1; a1pas2_.i__ <= 11; ++a1pas2_.i__) {
/* L9876: */
	adfsto_1.partno[a1pas2_.i__ - 1] = pratno[a1pas2_.i__ - 1];
    }

/*     CHECK ISPPRG TO SEE IF RE-ENTRY FROM SPECIAL PROGRAM */
    if (a1pas2_.ispprg != 0) {
	goto L35;
    }
/*     NO - FIRST TIME IN - INITIALIZE TABLE INDICES FOR PASS 2 */
    amxtab_1.maxtab = 6200;
    amxtab_1.maxvs = amxtab_1.maxvs1 + amxtab_1.maxvs2;
/* ..                                                                  D39 */
    iflush = (shortint) asistm_1.iwaven;
    if (iflush == 0) {
	goto L2;
    }
    io___37.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___37);
    do_fio(&c__1, (char *)&iflush, (ftnlen)sizeof(shortint));
    e_wsfe();
    asistm_1.iwaven = 1;
/* ..                                                                  D39 */
L2:
    a1pas2_.icansc = amxtab_1.maxvs + amxtab_1.maxptp + 1;
    a1pas2_.icanst = a1pas2_.icansc + amxtab_1.maxscl;
    a1pas2_.kanptr = a1pas2_.icanst + 50;
    loops = 0;
    a1pas2_.maxcan = 0;
    a1pas2_.kancnt = 0;
    a1pas2_.kango = 0;
    a1pas2_.kanmax = amxtab_1.maxtab - a1pas2_.kanptr - 200;
/*     INITIALIZE PASS 2 FLAGS */
    aprotp_1.jgorit = 0;
    aprotp_1.nowclt = 0;
    a1pas2_.iovrec = 0;
    aprotp_1.lstpsv = 0;
    nparts = 0;
    aprotp_1.incore = 0;
    a1com_1.refsys = 0.;
    a2cls7_1.ename = 0.;
    ascalr_1.nsurf = 0;
/*     FOR DEBUG/ON AND DEBUG/OFF */
    a1com_1.kdbug = 0;
/*     FOR PRINT/ON AND PRINT/OFF */
    a1pas2_.kprnt = 0;
/* ...     FOR CANON/ON AND CANON/OFF */
    adebug_1.kcandf = 0;
    a2cls7_1.isn = 0;
    a1pas2_.irecn = 1;
    a2cls7_1.ierec = 0;
    a1pas2_.lgerec = 0;
/*     SET NORMAL ZSURF PLANE */
    azurf_1.zsur[0] = 0.;
    azurf_1.zsur[1] = 0.;
    azurf_1.zsur[2] = 1.;
    azurf_1.zsur[3] = 0.;
/*     SET UP MATRIX AREAS */
    for (a1pas2_.i__ = 1; a1pas2_.i__ <= 15; ++a1pas2_.i__) {
	atmaty_1.xmat4[a1pas2_.i__ - 1] = 0.;
	atmaty_1.xmat3[a1pas2_.i__ - 1] = 0.;
	atmaty_1.xmat2[a1pas2_.i__ - 1] = 0.;
	atmaty_1.xmat1[a1pas2_.i__ - 1] = 0.;
/* L4: */
	atmaty_1.tmatx[a1pas2_.i__ - 1] = 0.;
    }
    atmaty_1.xmat4[15] = 1.;
    atmaty_1.xmat3[15] = 1.;
    atmaty_1.xmat2[15] = 1.;
    atmaty_1.xmat1[15] = 1.;
    atmaty_1.tmatx[15] = 1.;

/*     INITIALIZE INDXPT,INDEXS,AND KLASCT */
L5:
    a1com_1.indxpt = amxtab_1.maxvs + 1;
    kindxp = (a1com_1.indxpt << 1) - 1;
    a1pas2_.indexs = a1com_1.indxpt;
    a1pas2_.kptpct = 0;
    a1pas2_.klasct = 0;
/* ...  RESET LOOP ERROR FLAG IF THERE IS NOT A CURRENT LOOP IN PROCESS */
    if (loops == 0) {
	a1com_1.loop = 0;
    }
/*     READ RECORD FROM PTPP FILE */
    ataprd_(ptptap, &ioflag, &nwrds, &c__4, &a1pas2_.kptp, &c__1, &iptpp[OTHER_ENDIAN_S(kindxp - 1)],
	 &c__1, &iptpp[OTHER_ENDIAN_S(kindxp)], &c__1, &ptpp[a1com_1.indxpt], 
	    &c__0);
/*     CHECK I/O OPERATION */
    if (ioflag < 0) {
	goto L10;
    } else if (ioflag == 0) {
	goto L810;
    } else {
	goto L1800;
    }

/*     SHOULD HAVE TYPE 0 RECORD */
L10:
    if (iptpp[OTHER_ENDIAN_S(kindxp - 1)] != 0) {
	goto L1800;
    }
/* ..                                                                  D39 */
/* ..   GET BLOCK LENGTH  -- CONTAINED IN LOW ORDER 4 BYTES */
/* L20: */
    a1pas2_.kptpct = iptpp[OTHER_ENDIAN_S(kindxp)];
/* ...  SET ADDRESS OF LAST 8 BYTE ENTRY FOR THIS BLOCK */
    a1pas2_.kptpct = a1com_1.indxpt + a1pas2_.kptpct;

/* ..   PRINT PTPP BLOCK IF DEBUG IS ON */
    if (a1com_1.kdbug == 0) {
	goto L35;
    }
    io___43.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___43);
    do_fio(&c__1, (char *)&a1pas2_.kptp, (ftnlen)sizeof(integer));
    e_wsfe();
    io___44.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___44);
    do_fio(&c__1, (char *)&a1com_1.indxpt, (ftnlen)sizeof(integer));
    i__1 = a1pas2_.kptpct;
    for (a1pas2_.i__ = a1com_1.indxpt; a1pas2_.i__ <= i__1; ++a1pas2_.i__) 
	    {
	do_fio(&c__1, (char *)&ptpp[a1pas2_.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

/*     ENTRY POINT TO PROCESS PTPP CLASS - SET INDXPT TO NEXT CLASS ENTRY */
L35:
    a1com_1.indxpt = a1pas2_.indexs + a1pas2_.klasct;

/*     IS THIS PTPP BLOCK EXHAUSTED */
L40:
    if (a1com_1.indxpt >= a1pas2_.kptpct) {
	goto L5;
    }

/*     NO - PROCESS NEXT PTPP CLASS IN BLOCK */
    ++a1com_1.indxpt;
/* ...     CHECK FOR PTPP SEGMENTATION */
    if (nparts != 0) {
	goto L1020;
    }
L50:
    kindxp = (a1com_1.indxpt << 1) - 1;
/*     OBTAIN NO. OF WORDS IN PTPP CLASS (OR ISN FOR CLASSES 1 AND 7) */
/* ...                                   (MODE FLAG FOR CLASS 8)       D39 */
    a1pas2_.klasct = iptpp[OTHER_ENDIAN_S(kindxp)];
/*     OBTAIN PTPP CLASS AND BRANCH */
    a1pas2_.klastp = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
/*     SAVE CURRENT VALUE OF INDXPT */
    a1pas2_.indexs = a1com_1.indxpt;
/* ...     CLEAR ARGUMENT LIST CONTROL FLAGS */
    ascalr_1.iargtp = 0;
/*     SET INDXPT TO ITEM 2 OF PTPP CLASS FOR ALL ROUTINES */
    ++a1com_1.indxpt;
    kindxp += 2;
/* ...  BRANCH IF FLUSH MODE PREVAILS                                  D39 */
    if (iflush != 0) {
	goto L2400;
    }
/* ..   CHECK VALIDITY OF CLASS TYPE */
    if (a1pas2_.klastp <= 0) {
	goto L60;
    }
    if (a1pas2_.klastp > 20) {
	goto L60;
    }
    switch ((int)a1pas2_.klastp) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L300;
	case 15:  goto L300;
	case 16:  goto L1600;
	case 17:  goto L1700;
	case 18:  goto L2000;
	case 19:  goto L2250;
	case 20:  goto L2300;
    }

L60:
    a1com_1.jsuber = 6201;
    adiagm_();
    io___45.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___45);
    do_fio(&c__1, (char *)&a1com_1.indxpt, (ftnlen)sizeof(integer));
    e_wsfe();
    io___46.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___46);
    do_fio(&c__1, (char *)&amxtab_1.maxvs, (ftnlen)sizeof(integer));
    i__1 = a1pas2_.kptpct;
    for (a1pas2_.i__ = amxtab_1.maxvs; a1pas2_.i__ <= i__1; ++a1pas2_.i__) 
	    {
	do_fio(&c__1, (char *)&ptpp[a1pas2_.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L5;

/*     CLASS 1 - ORIGINAL INPUT STATEMENT WITH ISN - PRINT THEM OUT */
L100:
    a1pas2_.indexs = a1com_1.indxpt;
    a1com_1.indxpt += 13;
/*     IS ISN SAME AS LAST */
    if (a2cls7_1.isn == a1pas2_.klasct) {
	goto L120;
    }
/* ...    SAVE ISN AND CARD NO. */
    a2cls7_1.isn = a1pas2_.klasct;
    a2cls7_1.ppseq1 = ptpp[a1com_1.indxpt - 2];
    a2cls7_1.ppseq2 = ptpp[a1com_1.indxpt - 1];
    io___47.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___47);
    do_fio(&c__1, (char *)&a2cls7_1.isn, (ftnlen)sizeof(integer));
    i__1 = a1com_1.indxpt;
    for (a1pas2_.i__ = a1pas2_.indexs; a1pas2_.i__ <= i__1; ++a1pas2_.i__)
	     {
	do_fio(&c__1, (char *)&ptpp[a1pas2_.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
/*     PROCESS NEXT PTPP CLASS */
    goto L40;
/*     ISN SAME AS LAST - DO NOT PRINT */
L120:
    io___48.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___48);
    i__1 = a1com_1.indxpt;
    for (a1pas2_.i__ = a1pas2_.indexs; a1pas2_.i__ <= i__1; ++a1pas2_.i__)
	     {
	do_fio(&c__1, (char *)&ptpp[a1pas2_.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L40;

/*     CLASS 2 - ERROR DIAGNOSTICS FROM PASS 1 */
/*     CHECK FOR DIAGNOSTIC MESSAGE ONLY */
L200:
    if (iptpp[OTHER_ENDIAN_S(kindxp)] == 1) {
	goto L220;
    }
/*     YES - PRINT MESSAGE WITH ASSOCIATED ISN AND CARD SEQUENCE NUMBER */
    a1pas2_.indexs += 2;
    a1com_1.indxpt += iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    io___49.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___49);
    do_fio(&c__1, (char *)&a2cls7_1.ppseq1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.ppseq2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.isn, (ftnlen)sizeof(integer));
    i__1 = a1com_1.indxpt;
    for (a1pas2_.i__ = a1pas2_.indexs; a1pas2_.i__ <= i__1; ++a1pas2_.i__)
	     {
	do_fio(&c__1, (char *)&ptpp[a1pas2_.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    io___50.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___50);
    e_wsfe();
    goto L40;

/*     SET JSUBER EQUAL TO ERROR NUMBER */
L220:
    a1com_1.jsuber = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    a2cls7_1.isn = (i__1 = iptpp[OTHER_ENDIAN_S(kindxp + 2)], abs(i__1));
    a2cls7_1.ppseq1 = ptpp[a1com_1.indxpt + 1];
    a2cls7_1.ppseq2 = ptpp[a1com_1.indxpt + 2];
/*     IS A VARIABLE SYMBOL INVOLVED */
    if (a1pas2_.klasct == 4) {
	goto L230;
    }
/*     YES - SET ENAME */
    a1com_1.indxpt += 4;
    a2cls7_1.ename = ptpp[a1com_1.indxpt - 1];
/* ....  DO WE HAVE A SUBSCRIPT TO PRINT....BR TO 225 TO PROCESS IT IF SO */
    if (a1pas2_.klasct > 5) {
	goto L225;
    }
    goto L240;
/* .... SET UP TO OUTPUT THE SUBSCRIPT */
L225:
    ++a1com_1.indxpt;
    a1com_1.namsub = (integer) ptpp[a1com_1.indxpt - 1];
    goto L250;
L230:
    a2cls7_1.ename = 0.;
L240:
    a1com_1.namsub = 0;

/*     WRITE DIAGNOSTIC MESSAGE */
L250:
    adiagm_();
    goto L1900;

/* ...     CLASSES 3 AND 14 - SURFACE DEFINITIONS - USE ADFPRE (1204) */
L300:
    adfpre_();
/*     GO CHECK FOR ERRORS */
    goto L1900;

/* ...     CLASS 4 - REFSYS - USE ARFSYS (1205) */
L400:
    arfsys_();
    goto L1900;

/* ...     CLASS 5 - OUTPUT (PRINT, PUNCH, OR TITLES) - USE ACLAS5 (1213) */
L500:
    aclas5_();
    goto L1900;

/* ...     CLASS 6 - COPY ONTO PROTAP, 2000 THROUGH */
/* ...               9000 AND 11000 TYPE RECORDS - USE ACPYTP (1206) */
L600:
    acpytp_();
    goto L1900;

/*     CLASS 7 - INPUT CARD SEQUENCE WITH STATEMENT ID AND ISN */
/*     IF NO PROTAP RECORD TO BE OUTPUT,SAVE SEQ. NO. AND ISN FOR DIAG. */
L700:
    a2cls7_1.isn = abs(a1pas2_.klasct);
    iisn = a1pas2_.klasct;
    a1pas2_.klasct = 4;
/*     EXTRACT PROTAP RECORD FLAG(=1,NO REC. OUTPUT =2,OUTPUT PROTAP REC. */
    a1pas2_.i__ = iptpp[OTHER_ENDIAN_S(kindxp)];
/*     EXTRACT VST INDEX OF STATEMENT ID(0 IF NONE) */
    a1com_1.name__ = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    ++a1com_1.indxpt;
/*     SET CARD SEQUENCE NUMBER */
    a2cls7_1.ppseq1 = ptpp[a1com_1.indxpt - 1];
    ++a1com_1.indxpt;
    a2cls7_1.ppseq2 = ptpp[a1com_1.indxpt - 1];
/*     SET STATEMENT ID (0 IF NONE) */
    ++a1com_1.indxpt;
    aprotp_1.protp[2] = ptpp[a1com_1.indxpt - 1];
/* ...     RESET STORING INDEX FOR PARAMETER LIST DATA BLOCKS */
    ascalr_1.loctem = a1pas2_.icanst + 10;
/* ...     DO WE OUTPUT PROTAP RECORD */
    if (a1pas2_.i__ != 2) {
	goto L40;
    }
/*     YES - CHECK FOR VALID STATEMENT ID */
    if (a1com_1.name__ == 0) {
	goto L740;
    }
/*     PUT CURRENT PROTAP RECORD NUMBER IN VST SLOT */
/* L720: */
    name4 = (a1com_1.name__ << 2) - 3;
    kvst[OTHER_ENDIAN_W(name4 + 3)] = (shortint) a1pas2_.irecn;
/*     SET UP REMAINDER OF PROTAP RECORD */
L740:
    jprotp[OTHER_ENDIAN_S(0)] = 0;
    jprotp[OTHER_ENDIAN_S(1)] = 3;
    jprotp[OTHER_ENDIAN_S(2)] = 1000;
    jprotp[OTHER_ENDIAN_S(3)] = iisn;
    seq[0] = a2cls7_1.ppseq1;
    seq[1] = a2cls7_1.ppseq2;
   //iseq[OTHER_ENDIAN_8(3)] = iseq[OTHER_ENDIAN_8(4)];
	//endian macros not needed here -chars are already big endian, essentially.
   iseq[3] = iseq[4];
    aprotp_1.protp[3] = seq[0];
/*     OUTPUT PROTAP RECORD */
    aritap_();
    goto L1900;

/*     CLASS 8 - FINI,DEBUG/ON OR OFF,PRINT/ON OR OFF -- CHECK FOR FINI */
L800:
    if (a1pas2_.klasct != 0) {
	goto L820;
    }

/*     YES-WRAP UP */
L810:
    a1com_1.ifini = 1;
/*     WRITE FINI RECORD */
    jprotp[OTHER_ENDIAN_S(0)] = 0;
    jprotp[OTHER_ENDIAN_S(1)] = 1;
    jprotp[OTHER_ENDIAN_S(2)] = 14000;
    jprotp[OTHER_ENDIAN_S(3)] = 0;
    aritap_();
/* ...     IF LAST MOTION STATEMENT CONTAINED AN IMPLIED CHECK SURFACE, */
/* ...     OUTPUT DIAGNOSTIC */
    if (aprotp_1.jgorit == 0) {
	goto L812;
    }
    a1com_1.jsuber = 650;
    a2cls7_1.ename = 0.;
    a1com_1.namsub = 0;
    adiagm_();

L812:
    atapop_(&ataptb_1.protap, &c__2, &ioflag);
    atapop_(&ataptb_1.protap, &c__1, &ioflag);
    atapop_(ptptap, &c__1, &ioflag);
    if (asistm_1.iwaven == 0) {
	goto L814;
    }
    atapop_(errtap, &c__2, &ioflag);
L814:
    atapop_(cantap, &c__1, &ioflag);
    atapop_(errtap, &c__1, &ioflag);
/* L815: */
    ascntl_();

/* ...     SET INDXPT FOR NEXT CLASS */
L820:
    --a1com_1.indxpt;
/* ...     KLASCT =1,DEBUG/ON, =2,OFF, =3,PRINT/ON, =4,OFF, */
/* ...     =5,CANON/ON, =6,OFF */
    switch ((int)a1pas2_.klasct) {
	case 1:  goto L830;
	case 2:  goto L835;
	case 3:  goto L840;
	case 4:  goto L845;
	case 5:  goto L850;
	case 6:  goto L855;
    }

L830:
    a1com_1.kdbug = 1;
    goto L40;
L835:
    a1com_1.kdbug = 0;
    goto L40;
L840:
    a1pas2_.kprnt = 1;
    goto L40;
L845:
    a1pas2_.kprnt = 0;
    goto L40;
L850:
    adebug_1.kcandf = 1;
    goto L40;
L855:
    adebug_1.kcandf = 0;
    goto L40;

/* ...     CLASS 9 - OBTAIN - USE ASEQAL (1207) */
L900:
    aseqal_();
    goto L1900;

/*     CLASS 10 - JUMPTO/ID - SET PTPP INDEX AND CHECK RANGE */
/*     IF AN ERROR HAS OCURRED,DO NOT BRANCH */
L1000:
    if (a1com_1.loop != 0) {
	goto L35;
    }

L1010:
    if (ptpp[a1com_1.indxpt - 1] <= 0.) {
	goto L1030;
    } else {
	goto L1015;
    }
L1015:
    kindxp = (a1com_1.indxpt << 1) - 1;
/* ...  PICK UP VST LOCATION OF ID */
    newrec = (iptpp[OTHER_ENDIAN_S(kindxp)] << 1) - 1;
    if (kvst[OTHER_ENDIAN_W((newrec << 1) + 3)] != 8) {
	goto L1035;
    }
/* ...  GET INDEX POINTER */
    *nhalf = vst4[OTHER_ENDIAN_S(newrec + 2)];
    if (*nhalf <= 0) {
	goto L1035;
    }
    nparts = nhalf2[OTHER_ENDIAN_S(1)] + amxtab_1.maxvs;
/* ...  GET RECORD NUMBER */
    newrec = nhalf2[OTHER_ENDIAN_S(0)];
/* ...  IS PROPER RECORD NUMBER IN CORE */
    if (newrec != a1pas2_.kptp) {
	goto L1040;
    }
/* ...  RECORD IN CORE - SET POINTER */
L1020:
    a1com_1.indxpt = nparts;
    nparts = 0;
    if (a1com_1.indxpt <= 0) {
	goto L1030;
    }
    if (a1com_1.indxpt <= a1pas2_.kptpct) {
	goto L50;
    }
/* ..   PTPP INDEX IS OUT OF ALLOWABLE RANGE                           D49 */
L1030:
    a1com_1.jsuber = 408;
    goto L230;
/* ..                                                                  D49 */
/* ..   STMT I.D. GIVEN IS UNDEFINED - DELETE THIS STATEMENT */
L1035:
    a1com_1.jsuber = 403;
    if (a1pas2_.klastp != 11) {
	goto L230;
    }
/* ..   OUTPUT A POINTER TO THE STMT.I.D. IN ERROR */
    a2cls7_1.ename = id;
    a1com_1.namsub = a1com_1.indxpt - jdsav + 1;
    goto L250;
/* ..                                                                  D49 */
/* ...  GO GET PROPER PTPP RECORD */
L1040:
    aserch_(ptptap, &newrec, &ioflag);
/* ...  NOW GO READ IT IN CORE */
    if (ioflag >= 0) {
	goto L1800;
    } else {
	goto L5;
    }

/* ...     CLASS 11 - IF(V)  ID1, ID2, ID3 */
/* ...                SET PTPP INDEX AS V IS LT, EQ, OR GT 0 */
/*     IF AN ERROR HAS OCURRED,DO NOT BRANCH */
L1100:
    if (a1com_1.loop != 0) {
	goto L35;
    }
/*     OBTAIN PARAMETER VALUE - TEST FOR SCALAR */
    agtarg_(&value, &c__1, &kret);
/* .. DIAGNOSTICS PROCESSED IN AGTARG -- IF KRET=7 THEN GET NEXT STMT */
    if (kret == 7) {
	goto L35;
    }
    if (kret != 1) {
	goto L1130;
    }
    jdsav = (shortint) a1com_1.indxpt;

/*     TEST SCALAR VALUE - SET INDXPT ACCORDINGLY */
    if (abs(value) < (float)1e-5) {
	goto L1110;
    }
    if (value < 0.) {
	goto L1010;
    } else if (value == 0) {
	goto L1110;
    } else {
	goto L1120;
    }
L1110:
    ++a1com_1.indxpt;
    goto L1010;
L1120:
    a1com_1.indxpt += 2;
    goto L1010;

/* ...     PARAMETER WITHIN IF PARENTHESES NOT A SCALAR */
L1130:
    a1com_1.jsuber = 402;
    goto L250;

/* ...     CLASS 12 - COMPUTING EXPRESSION - USE ACLS12 (1214) */
/* ...     TEST FOR UNARY MINUS RECORD */
L1200:
    if (iptpp[OTHER_ENDIAN_S(kindxp)] != 1) {
	goto L1210;
    }
/* ...     RECORD SHOULD BE UNARY MINUS - CHECK OUT 'OPERATOR' */
    ktm1 = kindxp + (a1pas2_.klasct << 1);
    if (iptpp[OTHER_ENDIAN_S(ktm1 - 2)] == 15) {
	goto L1220;
    }

L1210:
    acls12_();
    goto L1900;

/* ...     UNARY MINUS RECORD FOUND - PICK UP INDEX TO RESULT STORAGE */
L1220:
    istore = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
/* ...     MOVE PTPP SCAN INDEX TO PARAMETER TO BE NEGATED */
    ++a1com_1.indxpt;
/* ...     GET SCALAR VALUE OF SYMBOL */
    agtarg_(&ascalr_1.scalr[istore - 1], &c__1, &a1pas2_.j);
/* ...     IF NO ERROR IN AGTSRF, MAKE SURE WE FOUND SCALAR */
    if (a1com_1.jsuber != 0) {
	goto L1250;
    }
    if (a1pas2_.j != 1) {
	goto L1230;
    }
/* ...     NEGATE VALUE OF SCALAR */
    ascalr_1.scalr[istore - 1] = -ascalr_1.scalr[istore - 1];
    goto L1900;

/* ...     SCALAR NOT FOUND - DISTINGUISH BETWEEN UNDEFINED SYMBOL */
/* ...     AND OTHER TYPES OF DATA */
L1230:
    if (a1pas2_.j != 3) {
	goto L1240;
    }
    a1com_1.jsuber = 101;
    goto L1250;
L1240:
    a1com_1.jsuber = 139;
/* ...     PUT ERROR CODE INTO SCALAR TABLE ENTRY */
L1250:
    ktm1 = (istore << 1) - 1;
    iscalr[OTHER_ENDIAN_S(ktm1 - 1)] = 0;
    iscalr[OTHER_ENDIAN_S(ktm1)] = 9;
    goto L1900;

/* ...     CLASS 13 - SCALAR EQUALS EXPRESSION */
/* ...     GET SCALAR INDEX OF NUMERIC VALUE TO BE ASSIGNED */
/* ...     TO THE SCALAR VARIABLE */
L1300:
    ktm1 = iptpp[OTHER_ENDIAN_S(kindxp)];
/* ...     TEST FOR PRESENCE IN PTPP RECORD OF VALUE TO BE ASSIGNED */
    if (ktm1 != 0) {
	goto L1310;
    }

/* ...     YES - PICK IT UP, AND MOVE SCAN INDICES PAST IT */
    fnum = ptpp[a1com_1.indxpt];
    ++a1com_1.indxpt;
    kindxp += 2;
    goto L1320;

/* ...     GET VALUE FROM SCALAR STORAGE */
L1310:
    fnum = ascalr_1.scalr[ktm1 - 1];

/* ...     GET SUBSCRIPT TYPE, VST INDEX, AND SYMBOL NAME */
L1320:
    a1com_1.namsub = iptpp[OTHER_ENDIAN_S(kindxp + 2)];
    a1com_1.name__ = iptpp[OTHER_ENDIAN_S(kindxp + 4)];
    a2cls7_1.ename = avst_1.vst[a1com_1.name__ - 1];
/* ...     GET SUBSCRIPT */
    a1com_1.indxpt += 2;
    agtsub_();
/* ...     IF NO ERROR, PLACE SCALAR IN CANON */
    if (a1com_1.jsuber != 0) {
	goto L250;
    }
    asclpt_(&fnum);
    goto L1900;

/* ...     CLASS 16 - ZSURF - USE AZSURF (1211) */
L1600:
    azsurf_();
    goto L1900;

/* ...     CLASS 17 - SPECIAL PROGRAM CALL - USE ACALSP (1212) */
L1700:
    acalsp_();
    goto L1900;

/*     RECORD FORMAT INCORRECT */
L1800:
    io___60.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___60);
    do_fio(&c__1, (char *)&a1pas2_.kptpct, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nwrds, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ioflag, (ftnlen)sizeof(integer));
    e_wsfe();
    asistm_1.iwaven = 1;
    goto L5;

/*     CHECK FOR ERRORS */
L1900:
    if (ioflag < 0) {
	goto L1920;
    }
/*     SYSTEM TAPE ERROR - PRINT IOFLAG */
    io___61.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___61);
    do_fio(&c__1, (char *)&ioflag, (ftnlen)sizeof(integer));
    e_wsfe();
    asistm_1.iwaven = 1;
    ioflag = 0;

/*     CHECK FOR SUBROUTINE ERROR */
L1920:
    if (a1com_1.jsuber == 0) {
	goto L35;
    }
    goto L250;

/* ...     CLASS 18 - CODES REQUIRED FOR IMPLIED CHECK SURFACE LOGIC */
L2000:
    if (a1pas2_.klasct != 0) {
	goto L2010;
    }
/* ...     IMPLIED CHECK SURFACE FOUND - SET FLAGS TO SAVE PROTAP */
/* ...     RECORDS UNTIL A USABLE DRIVE SURFACE APPEARS */
    aprotp_1.jgorit = 1;
    aprotp_1.incore = 0;
    aprotp_1.nowclt = 0;
    goto L35;

/* ...     SAVE MOTION COMMAND CODES IN CASE NEEDED FOR COMPUTATION */
/* ...     OF POSITION MODIFIER FOR FOLLOWING DS AS AN IMPLIED CS */
L2010:
    aprotp_1.savmot = ptpp[a1com_1.indxpt - 1];
    goto L35;

/* ...     CLASS 19 */
/* ...  SET UP LOOPS FLAG TO INDICATE LOOP MODE FOR SEGMENTATION */
L2250:
    igotit = iptpp[OTHER_ENDIAN_S(kindxp)];
    loops = 0;
    if (igotit == 1) {
	loops = 1;
    }
    goto L35;

/* ...     CLASS 20 - NESTED PARAMETER LIST - USE ARGLST (1208) */
L2300:
    arglst_();
    goto L1900;
/* ..                                                                  D39 */
/* .. */
/* ..   VST IS IN AN UNRECOVERABLE MESS  -- FLUSH THE PTPP */
/* ..       PRINT ONLY CLASS 1 AND CLASS 2 RECORDS */
/* ..   THAT IS, CARD IMAGE AND ERROR DIAGNOSTICS */
/* .. */
/* ...  KLASCT = 14 FOR CLASS 1,=4 FOR 7,=0 FOR 8                      D39 */
/* .. */
L2400:
    a1com_1.kdbug = 0;
    if (a1pas2_.klastp == 1) {
	goto L100;
    }
    if (a1pas2_.klastp == 2) {
	goto L200;
    }
    if (a1pas2_.klastp == 7) {
	a1pas2_.klasct = 4;
    }
    if (a1pas2_.klastp == 8) {
	a1pas2_.klasct = 0;
    }
    goto L35;
/* ...                                                                 D39 */
} /* asyctl_ */

#undef seq
#undef ans
#undef iscalr
#undef jprotp
#undef ptptap
#undef errtap
#undef xo
#undef cantap
#undef defans
#undef deftab
#undef xynor
#undef nhalf2
#undef v1
#undef punor
#undef iptpp
#undef c3
#undef puvec
#undef svecn
#undef canon
#undef nhalf
#undef v
#undef ambda
#undef kvst
#undef ptpp
#undef ysml
#undef xsml
#undef tnor
#undef ylar
#undef xlar
#undef tvec
#undef iseq
#undef svec
#undef vst4
#undef id


