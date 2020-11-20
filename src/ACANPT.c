/* ACANPT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal protap, dumtap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

static struct {
    doublereal scalr[30], surftb[150];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;

/* Subroutine */ int acanpt_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_14 = { {'A', 'C', 'A', 'N', 'P', 'U', 'T', ' '}, 0. };

#define a (*(doublereal *)&equiv_14)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ii;
#define vst4 ((integer *)&avst_1)
    static integer ierr;
#define ptpp ((doublereal *)&avst_1)
    static integer name2;
#define nams2 ((shortint *)&a1com_1 + 12)
#define canon ((doublereal *)&avst_1)
    static integer kurnt;
    extern /* Subroutine */ int avs2ck_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
#define cantap ((doublereal *)&ataptb_1 + 5)
#define idfsto ((integer *)&adfsto_1)
    extern /* Subroutine */ int alsfpt_(), aserch_(), atapwt_(), adprnt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* **   THIS ROUTINE PLACES A SURFACE DEFINITION INTO THE CANON TABLE. THE */
/*     DEFTAB AND TABCYL DEFPRE OVERLAY AREAS ARE USED AS AUXILIARY CANON */
/*     STORAGE AFTER THE LAST REFERENCE TO A LARGE SURFACE IN THE PART */
/*     PROGRAM. THE INPUT TO THE ROUTINE IS THE DEFSTO TABLE FOR A NORMAL */
/*     SURFACE, THE DEFTAB TABLE FOR A LARGE SURFACE AND THE DEFSTO TABLE */
/*     , THE SURFACE NAME IN THE VARIABLE NAME, AND THE SUBSCRIPT VALUE */
/*     IN THE VARIABLE NAMSUB. */

/* **** FLAGS USED BY THE ROUTINE**** */
/* *    MAXTAB-MAXIMUM TABLE SIZE OF VST, PTPP, AND CANON. */
/* *    MOVLGE-0 IF LARGE SURFACE NOT PROCESSED THIS TIME. */
/* *    ICANST-INDEX TO START OF CANON=MAXVS+MAXPTP+1 */
/* *    KANPTR-INDEX TO LAST CANON ENTRY+1 */
/* *    KANMAX-MAXIMUM SIZE OF PRIMARY CANON AREA=MAXTAB-ICANST-199. */
/*     KANMAX=KANCNT IF CANON OVERFLOW IS USED. */
/* *    IOVFLO-SIZE OF CANON OVERFLOW AREA, ORIGINALLY=200. IF OVERFLOW */
/*     OCCURS  IOVFLO=MAXTAB-KANCNT-MAXVS-MAXPTP */
/* *    KANCNT-NUMBER OF ENTRIES IN CANON OR NUMBER OF ENTRIES IN CANON */
/*     OVERFLOW WHEN USED. */
/* *    MDFTAB-MAXIMUM SIZE OF DEFTAB AREA, =1000 */
/* *    KDFCNT-NUMBER OF ENTRIES IN DEFTAB AUXILIARY CANON. */
/* *    IDEFP-INDEX TO LAST DEFTAB AUXILIARY CANON ENTRY+1, ORIGINALLY=39 */
/* *    MDFPRE-SIZE OF TABCYL DEFPRE AUXILIARY CANON. */
/* *    IPREP-INDEX TO NEXT AVAILABLE LOCATION IN TABCYL DEFPRE AUXILIARY */
/*     CANON. */
/* *    KOVFLP-INDEX TO START OF CANON OVER FLOW AREA. */
/* *    KSRFCT-NO. OF SURFACES IN CANON OVERFLOW AREA. */
/* *    IOVREC- CURRENT RECORD NO. IN CANON OVERFLOW AREA. */
/* *    LSCAN-NO. OF LAST RECORD PLACED IN CANTAP FILE. */
/* *    KLREF-NO. OF TIMES LARGE SURFACE HAS BEEN PROCESSED BY PHASE 2. */
/* *    LASPTP-NO. OF TIMES LARGE SURFACE IS USED IN PART PROGRAM. */

/* ...     TEST FOR WRITING OUT PRESENT RECORD TO MAKE ROOM FOR OLD ONE */
    if (a1pas2_1.kango != 0) {
	goto L225;
    }

    a1pas2_1.movlge = 0;
/* ...     GET LENGTH OF CANONICAL DEFINITION */
    a1pas2_1.l = idfsto[OTHER_ENDIAN_S(1)];
/* ...     CHECK FOR LARGE SURFACE OR PATTERN */
    if (idfsto[OTHER_ENDIAN_S(0)] == 18) {
	goto L1;
    }
    if (idfsto[OTHER_ENDIAN_S(0)] < 50) {
	goto L30;
    }

/* ...     THIS IS A LARGE SURFACE */
L1:
    a1pas2_1.movlge = 1;

/* ...     TEST FOR NEXT RECORD NO. ALREADY ASSIGNED TO MATERIAL IN */
/* ...     CANON OVERFLOW AREA */
    if (a1pas2_1.iovrec == 0) {
	goto L20;
    }
    if (a1pas2_1.kancnt == 0) {
	goto L20;
    }
/* ...     YES - SET FLAG TO RETURN HERE AFTER CLEARING OVERFLOW BUFFER */
    a1pas2_1.kango = -1;
    goto L225;

/* ...     WRITE LARGE SURFACE CANONICAL FORM ONTO FILE */
L20:
    alsfpt_();
    a1pas2_1.kango = 0;
    if (a1com_1.jsuber != 0) {
	return 0;
    }
/* ...  TEST FOR UNNAMED SURFACE */
L30:
    if (idfsto[OTHER_ENDIAN_S(4)] == 0) {
	goto L300;
    }
/* ...  CHECK STATUS OF VARIABLE SYMBOL */
    avs2ck_(&a1pas2_1.j);
    name2 = (a1com_1.name__ << 1) - 1;
/* ...  HAS SURFACE BEEN PREVIOUSLY DEFINED, STORED IN CANON */
    if (a1pas2_1.j != 1) {
	goto L40;
    }

    kurnt = vst4[OTHER_ENDIAN_S(name2)];
    if (adfsto_1.defsto[0] != canon[kurnt - 1]) {
	goto L45;
    }
    i__1 = a1pas2_1.l;
    for (a1pas2_1.i__ = 2; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	canon[kurnt] = adfsto_1.defsto[a1pas2_1.i__ - 1];
/* L35: */
	++kurnt;
    }
    goto L265;

/* ...     IS VARIABLE A SURFACE IN OVERFLOW FILE */
L40:
    if (a1pas2_1.j == 6) {
	goto L210;
    }
/* ...     NO - TEST FOR NOT YET PROCESSED IN PASS 2 */
    if (a1pas2_1.j == 7) {
	goto L60;
    }

/*     VARIABLE ILL-DEFINED */
    a1com_1.jsuber = 139;
    return 0;
L45:
    a1com_1.jsuber = 1006;
    return 0;

/*     UPDATE NO. ENTRIES IN ALL CANON STORAGE */
L60:
    a1pas2_1.maxcan += a1pas2_1.l;
/*     CAN THIS SURFACE BE PLACED IN PRIMARY CANON */
    if (a1pas2_1.maxcan > a1pas2_1.kanmax) {
	goto L190;
    }
/*  80 YES, THIS SURFACE CAN BE PLACED IN PRIMARY CANON. SET NAMSUB= */
/*     CURRENT CANON INDEX. */
/* L80: */
    a1com_1.namsub = a1pas2_1.kanptr;
/*     UPDATE NUMBER OF ENTRIES IN CANON */
    a1pas2_1.kancnt += a1pas2_1.l;
/*     SET J TO INDICATE CANON FOR VST ENTRY */
    a1pas2_1.j = 1;
    adebug_1.idebug[0] = 4;
    adebug_1.idebug[1] = a1com_1.namsub;
    goto L240;

/*     CANON OVERFLOW PROCESSING IS NECESSARY */
/* 190 IS THIS THE FIRST TIME FOR CANON OVERFLOW PROCESSING */
L190:
    if (a1pas2_1.iovrec != 0) {
	goto L210;
    }

/* 200 THIS IS THE FIRST TIME FOR CANON OVERFLOW PROCESSING */
/* L200: */
    a1pas2_1.kanmax = a1pas2_1.kancnt;
    a1pas2_1.kancnt = 0;
    a1pas2_1.iovflo = amxtab_1.maxtab - a1pas2_1.kanptr + 1;
    a1pas2_1.ksrfct = 0;
    a1pas2_1.kancur = 1;
    a1pas2_1.iovrec = 1;
/*     SET INDEX FOR FIRST LOCATION IN OVERFLOW AREA */
    a1pas2_1.kovflp = a1pas2_1.kanptr;

/* 210 SET RELATIVE INDEX IN CANON OVERFLOW */
L210:
    a1com_1.namsub = a1pas2_1.kanptr - a1pas2_1.kovflp;
/*     SET J TO INDICATE CANTAP IN VST ENTRY */
    a1pas2_1.j = 6;
    adebug_1.idebug[0] = 4;
/*     UPDATE ENTRIES IN OVERFLOW STORAGE */
    a1pas2_1.kancnt += a1pas2_1.l;
/*     DOES THIS ENTRY CAUSE CANON OVERFLOW  SIZE  TO BE EXCEEDED */
    if (a1pas2_1.kancnt <= a1pas2_1.iovflo) {
	goto L230;
    }
/* 220 THIS ENTRY CAUSES CANON OVERFLOW SIZE TO BE EXCEEDED. PLACE CANON */
/*     OVERFLOW AREA IN CANTAP FILE AND SET CANTAP RECORD NUMBER. */
/* L220: */
/*     UPDATE RECORD NUMBER IN OVERFLOW AREA. */
    a1pas2_1.kancnt -= a1pas2_1.l;

/* ...     POSITION FILE FOR WRITING OF NEXT RECORD */
L225:
    ++a1pas2_1.lgerec;
    aserch_(cantap, &a1pas2_1.lgerec, &a1pas2_1.namsta);
    atapwt_(cantap, &ierr, &c__4, &a1pas2_1.lgerec, &c__1, &a1pas2_1.ksrfct, &
	    c__1, &a1pas2_1.kancnt, &c__1, &canon[a1pas2_1.kovflp - 1], &
	    a1pas2_1.kancnt);
    if (ierr >= 0) {
	a1com_1.jsuber = 177;
    }
    a1pas2_1.kanptr = a1pas2_1.kovflp;
    a1pas2_1.kancnt = 0;
    a1pas2_1.ksrfct = 0;
/* ...     BRANCH ON FLAG INDICATING REASON FOR CLEARING OF BUFFER */
    if (a1pas2_1.kango < 0) {
	goto L20;
    } else if (a1pas2_1.kango == 0) {
	goto L228;
    } else {
	goto L280;
    }

L228:
    a1pas2_1.kancnt = a1pas2_1.l;
    a1com_1.namsub = 0;
/* 230 PLACE THIS SURFACE IN CANON OVERFLOW */
L230:
    ++a1pas2_1.ksrfct;
    adebug_1.idebug[1] = a1pas2_1.kanptr;
/* 240 MOVE SURFACE FROM DEFSTO TO CANON */
L240:
    i__1 = a1pas2_1.l;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	canon[a1pas2_1.kanptr - 1] = adfsto_1.defsto[a1pas2_1.i__ - 1];
/* L250: */
	++a1pas2_1.kanptr;
    }

/* ...     IS SURFACE ON OVERFLOW FILE */
    if (a1pas2_1.j != 6) {
	goto L262;
    }
/* ...     YES - MUST PACK INDEX WITHIN OVERFLOW RECORD, AND RECORD */
/* ...     NO., AS 2-BYTE ENTRIES TO GO INTO LOW-ORDER 4 BYTES OF */
/* ...     VST CODE WORD FOR SURFACE */
    nams2[OTHER_ENDIAN_S(0)] = (shortint) a1com_1.namsub;
    nams2[OTHER_ENDIAN_S(1)] = (shortint) (a1pas2_1.lgerec + 1);
/* ...     UPDATE VST ENTRY TO DEFINED SYMBOL */
L262:
    vst4[OTHER_ENDIAN_S(name2 - 1)] = a1pas2_1.j;
    vst4[OTHER_ENDIAN_S(name2)] = a1com_1.namsub;

    a1pas2_1.kancur = a1pas2_1.lgerec + 1;
/*     IS DEBUG FLAG ON */
L265:
    if (a1com_1.kdbug != 0) {
	goto L270;
    } else {
	goto L280;
    }
/* 270 DEBUG FLAG IS ON */
L270:
    adebug_1.idebug[2] = a1pas2_1.l;
    adprnt_(&a);
/*     WRITE DEFSTO AREA */
    adebug_1.idebug[0] = 3;
    adebug_1.idebug[1] = a1pas2_1.l;
    adprnt_(&c__0);
L280:
    a1pas2_1.kango = 0;
L290:
    return 0;
/* ...  PUT CANON ENTRY FOR SURFACE IN TEMPORARY STORAGE */
L300:
    i__1 = a1pas2_1.l;
    for (ii = 1; ii <= i__1; ++ii) {
	ascalr_1.scalr[ascalr_1.iscws - 1] = adfsto_1.defsto[ii - 1];
/* L310: */
	++ascalr_1.iscws;
    }
    goto L290;
} /* acanpt_ */

#undef idfsto
#undef cantap
#undef defans
#undef deftab
#undef canon
#undef nams2
#undef ptpp
#undef vst4
#undef a


