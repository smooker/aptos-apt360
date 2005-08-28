/* ACANGT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, dumtap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__2 = 2;

/* Subroutine */ int acangt_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_18 = { {'A', 'C', 'A', 'N', 'G', 'E', 'T', '1'}, 0. };

#define a (*(doublereal *)&equiv_18)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_19 = { {'A', 'C', 'A', 'N', 'G', 'E', 'T', '2'}, 0. };

#define a1 (*(doublereal *)&equiv_19)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer lsc;
    static doublereal sub;
    static integer lsr, lst, idum, lcnt;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
    extern /* Subroutine */ int amatm_();
    static integer nsave;
    extern /* Subroutine */ int avs2ck_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
#define cantap ((doublereal *)&ataptb_1 + 5)
    extern integer amdtoa_();
#define idfsto ((integer *)&adfsto_1)
    extern integer aextra_();
    static doublereal ername;
    extern /* Subroutine */ int aserch_(), ataprd_(), acanpt_(), adprnt_();
    static integer nsubsv;
    extern /* Subroutine */ int atrfrm_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* **** THIS ROUTINE FINDS THE SURFACE REQUESTED AND PLACES IT IN A WORK */
/*     TABLE. IF THE SURFACE IS A LARGE SURFACE IT IS PLACED IN THE */
/*     DEFTAB TABLE, OTHERWISE IT IS PLACED IN THE DEFSTO TABLE. */
/*     THE PROGRAM EXPECTS THE VST INDEXOF THE SURFACE TO BE IN THE */
/*     VARIABLE NAME AND THE SUBSCRIPT  VALUE TO BE IN THE VARIABLE */
/*     NAMSUB. THE PROGRAM RESETS THE VARIABLE NAME TO THE ALPHAMERIC */
/*     NAME OF THE SYMBOL. IF THE SURFACE IS NOT DEFINED THE VARIABLE */
/*     NAMSTA IS SET TO NON-ZERO. */
/* *********                   *********                         ********* */
/* **** FLAGS USED BY THE ROUTINE **** */
/* **   MOVLGE=0 IF LARGE SURFACE NOT 0PERATED ON FOR THIS CALL. */
/* **   IREF =0 IF KRFSYS=0,OTHERWISE A REFSYS MATRIX IS TO BE OBTAINED */
/* **   NAMSTA =0 IF NO ERROR OCCURS */
/* **   ENAME-SYMBOL ASSOCIATED WITH THIS SURFACE */
/* **   I-INDICATES STORAGE AREA FOR SURFACE(CANON,DEFTAB,ETC.) */
/* **   J-INDEX TO STORAGE AREA */
/* **   NAMSUB-CONTAINS SUBSCRIPT VALUE,0 IF NONE */
/* **   LCOMP-RECORD NUMBER FOR LARGE SURFACE CURRENTLY BEING PROCESSED */
/* **   LGEREC-RECORD NUMBER FOR LARGE SURFACE CURRENTLY IN DEFTAB */
/* **   LSCAN-RECORD NUMBER OF LAST LARGESURFACE PLACED IN SRFTAP FILE */
/* **   DEFTAB(1)-NUMBER OF PARAMETERS INCANONICAL FORM OF LARGE SURFACE */
/* **   IDEFP-INDEX TO DEFTAB INDICATING STARTING LOCATION WHERE LARGE */
/*     SURFACE IS TO BE PLACED */
/* **   IOVREC-RECORD NUMBER FOR CURRENT RECORD IN CANON OVERFLOW AREA */
/* **   KOVFLP-INDEX TO START OF CANON OVERFLOW */
/* **   JREC-RECORD NUMBER OF CANTAP FILE WHERE THIS SURFACE IS LOCATED */
/* **   JNUM-RELATIVE LOCATION IN CANTAP RECORD FOR THIS SURFACE */
/* **   KANCUR-CURRENT CANTAP RECORD NO. IN OVERFLOW AREA */
/* **   KANCOT-LENGTH OF CANTAP RECORD READ INTO OVERFLOW AREA */
/* **   KSRFCT-NUMBER OF SURFACES IN CANTAP RECORD IN OVERFLOW AREA */
/* **   KANPAR-NUMBER OF PARAMETERS IN CANONICAL FORM */
/* **   LGELOC-CORE LOCATION WHERE LARGE SURFACE IS STORED */
/* **   IDTMOV-IF NON-ZERO AND SURFACE ISLARGE SURFACE, DO NOT MOVE LARGE */
/*     SURFACE TO DEFTAB. */

    a1pas2_1.movlge = a0con_1.k0;
    a1pas2_1.iref = a0con_1.k0;
/*     MOVE CURRENT REFSYS MATRIX TO XMAT1 */
/* L5: */
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 16; ++a1pas2_1.i__) {
/* L10: */
	atmaty_1.xmat1[a1pas2_1.i__ - 1] = atmaty_1.xmat4[a1pas2_1.i__ - 1];
    }
/*     GET VST NAME */
L20:
    ername = avst_1.vst[a1com_1.name__ - 1];
/*     GET VARIABLE TYPE (I) WITH AVS2CK */
    avs2ck_(&a1pas2_1.i__);
/*     GET J(SECOND 4 BYTES) OF VST SECOND ENTRY */
    a1pas2_1.j = aextra_(&avst_1.vst[a1com_1.name__ - 1], &a0con_1.k4);
/*     IS SYMBOL UNDEFINED OR INCORRECTLY DEFINED OR NOT PROCESSED */
    if (a1pas2_1.i__ < a0con_1.k7) {
	goto L80;
    }
/*     YES,SYMBOL IS UNDEFINED OR INCORRECTLY DEFINED OR NOT PROCESSED */
    goto L560;
/*  80 I CONTAINS TYPE OF VARIABLE,J CONTAINS TABLE INDEX, NAME CONTAINS */
/*     VST INDEX TO (I,J) */
L80:
    switch ((int)a1pas2_1.i__) {
	case 1:  goto L90;
	case 2:  goto L210;
	case 3:  goto L220;
	case 4:  goto L90;
	case 5:  goto L90;
	case 6:  goto L270;
    }

/*  90 SURFACE IS STORED IN CANON */
/*     GET LENGTH OF CANONICAL FORM */
L90:
    a1pas2_1.l = aextra_(&canon[a1pas2_1.j - 1], &a0con_1.k4);
/*  90 GET SURFACE TYPE */
    a1pas2_1.k = amdtoa_(&canon[a1pas2_1.j - 1], &a0con_1.k4);
    goto L180;

/*     GET RECORD NUMBER */
L105:
    a1pas2_1.lcomp = idfsto[OTHER_ENDIAN_S(7)];
/* ...     TEST FOR ENOUGH SPACE FOR SURFACE IN DEFTAB AREA */
    if (idfsto[OTHER_ENDIAN_S(9)] >= 1000 - a1pas2_1.idefp) {
	goto L420;
    }
    a1pas2_1.movlge = 1;
/* 130 GET LARGE SURFACE FROM LGESRF FILE */
/* L130: */
    aserch_(&ataptb_1.srftap, &a1pas2_1.lcomp, &a1pas2_1.namsta);
/*     ERROR FROM ASERCH */
    if (a1pas2_1.namsta < a0con_1.k0) {
	goto L150;
    }
/* 140 ASERCH RETURNED ERROR CONDITION */
L140:
    a1com_1.jsuber = 179;
    return 0;
/* 150 NO ERROR RETURNED BY ASERCH */
L150:
    ataprd_(&ataptb_1.srftap, &a1pas2_1.namsta, &lcnt, &a0con_1.k6, &lsr, &
	    a0con_1.k1, &lst, &a0con_1.k1, &lsc, &a0con_1.k1, &a2cls7_1.ename,
	     &a0con_1.k1, &sub, &a0con_1.k1, &deftab[a1pas2_1.idefp], &
	    a0con_1.k0);
/*     ERROR FROM ATAPRD */
    if (a1pas2_1.namsta < 0) {
	goto L170;
    }
/* 160 ERR0R RETURNED FROM ATAPRD */
L160:
    a1com_1.jsuber = 180;
    return 0;
/* 170 NO ERROR FOUND BY ATAPRD */
/*     SET LGELOC EQUAL TO INDEX FOR LARGE SURFACE IN DEFTAB */
L170:
    a1pas2_1.lgeloc = a1pas2_1.idefp;
    return 0;

L180:
    a1pas2_1.j -= a0con_1.k1;
/*     IS THIS REFSYS LOOP */
    if (a1pas2_1.iref != a0con_1.k0) {
	goto L380;
    }
/* 190 MOVE SURFACE FROM CANON TO DEFSTO,NOT A REFSYS LOOP */
/* L190: */
    i__1 = a1pas2_1.l;
    for (a1pas2_1.i__ = a0con_1.k1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	a1pas2_1.j += a0con_1.k1;
/* L200: */
	adfsto_1.defsto[a1pas2_1.i__ - 1] = canon[a1pas2_1.j - 1];
    }
/* ...     TEST FOR A LARGE SURFACE */
    if (a1pas2_1.k < 50) {
	goto L420;
    }
/* 100 THIS IS A LARGE SURFACE */
/* L100: */
    if (a1pas2_1.idtmov == a0con_1.k0) {
	goto L105;
    }
    goto L420;

/* 210 THIS SYMBOL REFERENCES A SCALAR */
L210:
    return 0;
/* 220 SYMBOL REFERENCES A STATEMENT ID,ERROR */
L220:
    a1com_1.jsuber = 111;
    goto L570;

/* 270 SURFACE IS IN CANTAP FILE */
/* ...     GET RELATIVE INDEX TO SURFACE IN RECORD */
L270:
    a1pas2_1.jnum = amdtoa_(&a1pas2_1.j, &c__2);
/* ...   GET NUMBER OF CANTAP RECORD CONTAINING SURFACE */
    a1pas2_1.jrec = aextra_(&a1pas2_1.j, &c__2);
/*     IS SURFACE IN CANON OVERFLOW AREA */
    if (a1pas2_1.jrec != a1pas2_1.kancur) {
	goto L290;
    }
/* 280 YES,SURFACE IS IN CANON OVERFLOW AREA */
L280:
    a1pas2_1.j = a1pas2_1.jnum + a1pas2_1.kovflp;
    goto L90;

/* ...     ANY INFORMATION TO BE SAVED FROM OVERFLOW AREA */
L290:
    if (a1pas2_1.kancnt == 0) {
	goto L310;
    }
/* ...  YES ... SAVE IT */
    a1pas2_1.kango = 1;
    acanpt_();
L310:
    a1pas2_1.j = a1pas2_1.kovflp;
    aserch_(cantap, &a1pas2_1.jrec, &a1pas2_1.namsta);
    if (a1pas2_1.namsta >= 0) {
	goto L140;
    }
    ataprd_(cantap, &a1pas2_1.namsta, &a1pas2_1.kancot, &a0con_1.k4, &
	    a1pas2_1.kancur, &a0con_1.k1, &a1pas2_1.ksrfct, &a0con_1.k1, &
	    idum, &a0con_1.k1, &canon[a1pas2_1.j - 1], &a0con_1.k0);
    if (a1pas2_1.namsta >= 0) {
	goto L160;
    }
    goto L280;

/* 380 MOVE MATRIX FROM CANON TO XMAT2 */
L380:
    a1pas2_1.j += a0con_1.k3;
    for (a1pas2_1.i__ = a0con_1.k1; a1pas2_1.i__ <= 12; ++a1pas2_1.i__) {
	++a1pas2_1.j;
/* L390: */
	atmaty_1.xmat2[a1pas2_1.i__ - 1] = canon[a1pas2_1.j - 1];
    }
/* L415: */
    adebug_1.idebug[0] = a0con_1.k1;
    goto L425;
L420:
    adebug_1.idebug[0] = a0con_1.k3;
    adebug_1.idebug[1] = a1pas2_1.l;
/*     IS DEBUG FLAG ON */
L425:
    if (a1com_1.kdbug == 0) {
	goto L426;
    }
    adprnt_(&a);
/* 426 REFSYS MATRIX MANIPULATION */
/*     HAS THE REFSYS MATRIX FOR THIS SURFACE BEEN OBTAINED */
L426:
    if (a1pas2_1.iref < 0) {
	goto L500;
    } else if (a1pas2_1.iref == 0) {
	goto L430;
    } else {
	goto L510;
    }

/* 430 GET THE RESYS MATRIX FOR THIS SURFACE */
/*     IS THE CURRENT MATRIX USED FOR THIS SURACE */
L430:
    if (adfsto_1.defsto[1] != a1com_1.refsys) {
	goto L450;
    }
/* 440 THE CURRENT MATRIX IS USED FOR THIS SURFACE */
/* L440: */
    return 0;
/* 450 THE CURRENT MATRIX IS NOT USED FOR THIS SURFACE */
/*     IS THE BASIC REFERENCE SYSTEM USED FOR THIS SURFACE */
L450:
    nsave = a1com_1.name__;
    nsubsv = a1com_1.namsub;
    if (adfsto_1.defsto[1] != 0.) {
	goto L470;
    }
/* 460 THE BASIC REFERENCE SYSTEM IS USED FOR THIS SURFACE */
/* L460: */
    a1pas2_1.j = 33;
    a1pas2_1.l = 48;
    goto L520;

/* 470 THE BASIC REFERENCE SYSTEM IS NOTUSED FOR THIS SURFACE */
L470:
    a1pas2_1.iref = a0con_1.k1;
    if (a1com_1.refsys == (float)0.) {
	a1pas2_1.iref = -a0con_1.k1;
    }
/* L480: */
    a1com_1.name__ = amdtoa_(&adfsto_1.defsto[1], &a0con_1.k4);
    a1com_1.namsub = aextra_(&adfsto_1.defsto[1], &a0con_1.k4);
/*     GO BACK THROUGH CANGET TO OBTAIN THE REFSYS MATRIX */
    goto L20;

/* 500 USE THE CURRENT MATRIX FOR THIS SURFACE */
L500:
    a1pas2_1.j = 17;
    a1pas2_1.l = 32;
    goto L520;
/* 510 THE CURRENT MATRIX IS NOT USED FOR THIS SURFACE */
L510:
    amatm_(&a0con_1.k4);
    a1pas2_1.l = 16;
    a1pas2_1.j = a0con_1.k1;
L520:
    a1pas2_1.k = a0con_1.k1;
    a1com_1.name__ = nsave;
    a1com_1.namsub = nsubsv;
    i__1 = a1pas2_1.l;
    for (a1pas2_1.i__ = a1pas2_1.j; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	atmaty_1.tmatx[a1pas2_1.k - 1] = atmaty_1.xmat3[a1pas2_1.i__ - 1];
/* L540: */
	++a1pas2_1.k;
    }
/* ...     IF PATTERN, DO NOT TRANSFORM TO PRESENT REFERENCE SYSTEM */
/* ...     NOW - POINTS OF PATTERN WILL BE TRANSFORMED AS USED LATER */
    if (idfsto[OTHER_ENDIAN_S(0)] == 18) {
	goto L542;
    }
    atrfrm_();
/*     IS DEBUG FLAG ON */
L542:
    if (a1com_1.kdbug == 0) {
	goto L546;
    }
/* L545: */
    adebug_1.idebug[0] = a0con_1.k3;
    adebug_1.idebug[1] = aextra_(adfsto_1.defsto, &a0con_1.k4);
    adprnt_(&a1);
L546:
    return 0;

/* 560 UNDEFINED SYMBOL */
L560:
    a1com_1.jsuber = 101;
L570:
    a2cls7_1.ename = ername;
    return 0;
} /* acangt_ */

#undef idfsto
#undef cantap
#undef defans
#undef deftab
#undef canon
#undef ptpp
#undef a1
#undef a


