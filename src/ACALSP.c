/* ACALSP.f -- translated by f2c (version 20000121).
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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

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

static integer c__0 = 0;

/* Subroutine */ int acalsp_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_13 = { {'A', 'C', 'A', 'L', 'L', 'S', 'P', 'G'}, 0. };

#define a (*(doublereal *)&equiv_13)


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ksec, kret;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
    static integer ipend, ipind;
#define iptpp ((integer *)&avst_1)
    static integer jtemp1, indend;
    extern /* Subroutine */ int agtarg_();
#define idfsto ((integer *)&adfsto_1)
#define jprotp ((integer *)&aprotp_1)
    extern /* Subroutine */ int adprnt_(), agetsp_(), aritap_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* *    THIS ROUTINE SETS UP THE SPECIAL PROGRAM PARAMETERS */
/* *    THE PARAMETERS ARE STORED IN THE PROTP ARRAY AND ARE OUTPUT AS A */
/* *    PROTAP RECORD IF THE SEC2 MODIFIER HAS BEEN GIVEN */
/* *    IF THE SEC1 MODIFIER HAS BEEN GIVEN, SUBROUTINE AGETSP IS CALLED */
/*     SET END OF PTPP DATA */
    indend = a1com_1.indxpt + a1pas2_1.klasct;
/*     SET END OF PROTP INDEX */
    ipend = 100;
/*     CHECK DEBUG FLAG - IF ON PRINT PTPP */
    if (a1com_1.kdbug == 0) {
	goto L10;
    }
    adebug_1.idebug[0] = 7;
    adebug_1.idebug[1] = a1com_1.indxpt;
    adebug_1.idebug[2] = a1pas2_1.klasct;
    adprnt_(&a);
/*     SET UP PROTP TABLE FOR INPUT TO SPECIAL PROGRAM */
/*     SET SPECIAL PROGRAM NAME IN PROTP TABLE */
L10:
    aprotp_1.protp[2] = ptpp[a1com_1.indxpt - 1];
    ++a1com_1.indxpt;
    jtemp1 = (a1com_1.indxpt << 1) - 1;
/*     SET PARAMETER TYPE INDICATOR CODE AND PROTAP CLASS */
    jprotp[OTHER_ENDIAN_S(2)] = 12000;
    jprotp[OTHER_ENDIAN_S(3)] = iptpp[OTHER_ENDIAN_S(jtemp1)];
/*     SET CODE FOR SEC1 OR SEC2 EXECUTION */
    ksec = iptpp[OTHER_ENDIAN_S(jtemp1 - 1)];
/*     SET INDXPT TO FIRST PARAMETER IN PTPP */
    ++a1com_1.indxpt;
/*     SET INDEX TO BEGINNING OF PROTP STORAGE */
    ipind = 4;
/*     CHECK PARAMETER LIST AND MOVE TO PROTP ARRAY */
/*     ANY MORE PARAMETERS */
L20:
    if (a1com_1.indxpt >= indend) {
	goto L50;
    }
/*     DO PARAMETERS HAVE NAMES ASSOCIATED WITH THEM */
    if (jprotp[OTHER_ENDIAN_S(3)] == 1) {
	goto L30;
    }
/*     YES - STORE NAME IN PROTP ARRAY FIRST - CHECK PROTP LIMITS */
    if (ipind > ipend) {
	goto L80;
    }
    aprotp_1.protp[ipind - 1] = ptpp[a1com_1.indxpt - 1];
/*     INCREMENT INDXPT TO PARAMETER */
    ++a1com_1.indxpt;
    ++ipind;
L30:
    if (ipind > ipend) {
	goto L80;
    }
/* ...     OBTAIN AND IDENTIFY TYPE OF PARAMETER */
    i__1 = ipend - ipind;
    agtarg_(&aprotp_1.protp[ipind], &i__1, &kret);
/* ...     BRANCH ON PARAMETER TYPE */
    if (kret - 6 >= 0) {
	goto L40;
    } else {
	goto L32;
    }
L32:
    switch ((int)kret) {
	case 1:  goto L38;
	case 2:  goto L34;
	case 3:  goto L100;
	case 4:  goto L80;
	case 5:  goto L38;
    }
/* ...     PARAMETER IS A SURFACE - PUT ITS TYPE CODE INTO PROTP RECORD */
L34:
    jtemp1 = (ipind << 1) - 1;
    jprotp[OTHER_ENDIAN_S(jtemp1)] = idfsto[OTHER_ENDIAN_S(0)];
    jprotp[OTHER_ENDIAN_S(jtemp1 - 1)] = 0;
/* ...     INCREMENT PROTP STORING INDEX PAST SURFACE */
    ipind = ipind + idfsto[OTHER_ENDIAN_S(1)] - 2;
    goto L20;
/* ...     PARAMETER IS A SCALAR OR A VOCABULARY WORD - MOVE */
/* ...     IT INTO WORD SKIPPED FOR POSSIBLE SURFACE TYPE CODE */
L38:
    aprotp_1.protp[ipind - 1] = aprotp_1.protp[ipind];
    ++ipind;
    goto L20;
L40:
    a1com_1.jsuber = 83;
    goto L100;
/*     SET NO. OF WORDS IN PROTP RECORD */
L50:
    jprotp[OTHER_ENDIAN_S(0)] = 0;
    jprotp[OTHER_ENDIAN_S(1)] = ipind - 2;
/*     ALL PARAMETERS STORED - CHECK DEBUG FOR PRINTING OF PROTP TABLE */
    if (a1com_1.kdbug == 0) {
	goto L60;
    }
    adebug_1.idebug[0] = 13;
    adebug_1.idebug[1] = ipind;
    adprnt_(&c__0);
/*     DO WE EXECUTE NOW OR LATER */
L60:
    if (ksec == 2) {
	goto L70;
    }
/*     NOW - GO TO AGETSP TO CHECK LIST AND EXECUTE */
/*     SET ENAME IN CASE NOT THERE */
    a2cls7_1.ename = aprotp_1.protp[2];
    agetsp_();
/*     SPECIAL PROGRAM MAY RETURN HERE */
    goto L100;
/*     WRITE PROTAP RECORD CONTAINING PARAMETERS FOR SEC2 SPECIAL PROGRAM */
L70:
    aritap_();
    goto L100;
/*     TOO MANY PARAMETERS */
L80:
    a1com_1.jsuber = 205;
L100:
    return 0;
} /* acalsp_ */

#undef jprotp
#undef idfsto
#undef iptpp
#undef canon
#undef ptpp
#undef a


