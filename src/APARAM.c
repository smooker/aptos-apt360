/* APARAM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
/* Common Block Declarations */
static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Table of constant values */

static integer c__12 = 12;

/* Subroutine */ int aparam_()
{
    /* Initialized data */

    static shortint icopy[12] = { 29,6,34,4,38,4,42,4,54,3,55,4 };
    static struct {
	shortint e_1;
	} equiv_4 = { 0 };


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer jdum;
#define ivst ((integer *)&avst_1)
    static integer j;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
#define lclas2 ((shortint *)&ailmtb_1 + 2400)
    static integer jtemp1, jtemp2;
#define lment4 ((integer *)&ailmtb_1)
#define cl ((shortint *)&equiv_4)
    static shortint sc;
    static integer it, jt;
    static doublereal signeg;
    extern /* Subroutine */ int aswich_();
    static integer islash;
    extern /* Subroutine */ int aptlod_(), aptput_();
#define gcl ((logical1 *)&equiv_4)
#define ipt ((integer *)&aptpp_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER*2 LCLAS2(1200),CL/0/,SC */
/*       INTEGER *2 ICOPY(12)/29,6,34,4,38,4,42,4,54,3,55,4/ */
/*       INTEGER ISLASH/Z00000304/ */
/*       REAL*8 SIGNEG/Z0000000800000002/ */
/* 	f2c shutup data */
	islash=0x304;
	signeg=0x800000002;
    jtemp1 = 2 * aprtab_1.istarp - 1;
    ipt[OTHER_ENDIAN_S(4)] = lment4[OTHER_ENDIAN_S(jtemp1)];
    ipt[OTHER_ENDIAN_S(5)] = lment4[OTHER_ENDIAN_S(jtemp1 - 1)];
    sc = lclas2[OTHER_ENDIAN_S(jtemp1 - 1)];
    jtemp2 = (aprtab_1.istarp << 2) - 3;
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp2 + 1)];
//    gcl[OTHER_ENDIAN_W(0)] = lclas1[OTHER_ENDIAN_W(jtemp2 + 1)];
    ipt[OTHER_ENDIAN_S(0)] = 6;
    jt = 0;
    it = 0;
    aptpp_1.npt = 0;
    aptpp_1.jmode = 5;
    aptpp_1.nw = -1;
    aptpp_1.inptp = 4;
    aprtab_1.itsq = 0;
    ++aprtab_1.istarp;
/* ...     TEST FOR PARTNO, PPRINT, INSERT */
    if (*cl == 1) {
	goto L45;
    }
/* ...     NO - TEST FOR POST PROC. COMMANDS WITH OR WITHOUT PARAMETERS */
    if ((i__1 = *cl - 23) < 0) {
	goto L10;
    } else if (i__1 == 0) {
	goto L5;
    } else {
	goto L15;
    }

/* ...     SINGLE-WORD POST PROCESSOR COMMAND - TEST FOR PARAMETERS - */
/* ...     IF SO, ERROR */
L5:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L190;
    }
    a1com_1.jsuber = 505;
    goto L990;

/* ...     POST PROCESSOR COMMANDS WITH PARAMETERS */
/* ...     IF NO PARAMETERS GIVEN, TREAT AS SINGLE-WORD COMMAND */
L10:
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L20;
    } else if (i__1 == 0) {
	goto L15;
    } else {
	goto L190;
    }
/* ...     SLASH (ASSUMED) BUT NO PARAMETERS - ERROR */
L15:
    a1com_1.jsuber = 129;
    goto L990;
/* ...     TEST FOR SLASH */
L20:
    if ((ailmtb_1.iclass[aprtab_1.istarp - 1]) == islash) {
	goto L30;
    }
    a1com_1.jsuber = 155;
    goto L990;

/* ...     MOVE SCANNING INDEX PAST SLASH */
L30:
    ++aprtab_1.istarp;
/* ...     SET FLAG FOR AUTOMATIC SKIPPING OF COMMAS */
    aprtab_1.itsq = 4;
/* ...     TEST FOR TRACUT, INDEX, COPY, OR MACHIN */
    if ((i__1 = *cl - 21) < 0) {
	goto L15;
    } else if (i__1 == 0) {
	goto L120;
    } else {
	goto L40;
    }
/* ...     IF EITHER VTLAXS OR WCORN, SET FLAG TO CALL SECTION 3 */
L40:
    if (sc == 62) {
	asistm_1.indexx = 1;
    }
    if (sc == 63) {
	asistm_1.indexx = 1;
    }
/* ...     IF REQUIRED, SET FLAG FOR PLOTTING IN SECTION 3 */
    if (sc == 39) {
	asistm_1.iplotr = 1;
    }
/*      CHECK FOR TRANS STATEMENT TO  ALLOW FOR A MATRIX */
    if (sc == 35) {
	goto L700;
    }
/* ...  CHECK FOR CLRSRF OR CLEARP */
    if (sc == 49) {
	jt = 150;
    }
    if (sc == 4) {
	jt = 3;
    }
L45:
    sc = 5;

L50:
    aptlod_();
    aswich_(&jt);
L55:
    if (amotcm_1.jptind == 0) {
	goto L70;
    }
    switch ((int)amotcm_1.jptind) {
	case 1:  goto L70;
	case 2:  goto L110;
	case 3:  goto L110;
	case 4:  goto L100;
	case 5:  goto L460;
	case 6:  goto L110;
	case 7:  goto L110;
	case 8:  goto L990;
	case 9:  goto L460;
    }

/* ...     VOCABULARY WORD */
L70:
    jtemp1 = (aptpp_1.inptp << 1) - 1;
    if (ipt[OTHER_ENDIAN_S(jtemp1 - 2)] <= 0) {
	goto L460;
    }
/* ...    NUMBER OF ALLOWABLE POSTPROCESSOR MINOR WORDS EXCEEDED? */
    if (ipt[OTHER_ENDIAN_S(jtemp1 - 2)] <= 400) {
	goto L110;
    }
    goto L460;
/* .. */
/* ...     SURFACE DEFINITION, NAMED OR UNNAMED - CHECK ACCEPTABILITY */
L100:
    if (jt != 0) {
	goto L110;
    }

/* ...     NO SURFACE VALID IN THIS STATEMENT */
/* L105: */
    a1com_1.jsuber = 501;
    a1com_1.sum = 1;
    goto L990;

L110:
    ++aptpp_1.npt;
/* ...     TEST FOR END OF STATEMENT */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L190;
    }
/* ...     NO - TEST FOR OVERFLOW OF PT BUFFER */
    if (aptpp_1.inptp >= 297) {
	goto L195;
    }
    goto L50;

/* ...     TRACUT, INDEX, COPY, OR MACHIN STATEMENT - DETERFMINE WHICH */
L120:
    switch ((int)sc) {
	case 1:  goto L150;
	case 2:  goto L260;
	case 3:  goto L340;
	case 4:  goto L300;
    }

/*     TRACUT */
L150:
    aptlod_();
/* ...     CHECK NUMBER OF PARAMETERS - ONLY ONE LEGAL */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L15;
    }
/* ...     SEE IF PARAMETER WAS 'NOMORE' */
    if (amotcm_1.jptind != 0) {
	goto L155;
    }
    if (amotcm_1.kreslt - 53 != 0) {
	goto L160;
    } else {
	goto L180;
    }
/* ...     NO - MUST BE SURFACE - PERMIT SYMBOLIC SCALAR FOR */
/* ...     POSSIBLE UNDEFINED */
L155:
    if (amotcm_1.jptind == 4) {
	goto L170;
    }
    if (amotcm_1.jptind == 3) {
	goto L170;
    }
/* ...     IF ERROR FLAG SET IN APTLOD, SIMPLY EXIT */
    if (amotcm_1.jptind == 8) {
	goto L995;
    }
L160:
    a1com_1.jsuber = 506;
    goto L990;
L170:
    aswich_(&c__12);
L180:
    asistm_1.itrcut = 1;
    aptpp_1.npt = 1;

/* ...     OUTPUT (POSSIBLE PARTIAL) PTPP RECORD, AND EXIT IF FINISHED */
L190:
    it = 1;
L195:
    --aptpp_1.inptp;
    aptpp_1.nw += aptpp_1.inptp;
/* ...     TEST FOR END OF POST PROCESSOR COMMAND */
    if (it == 0) {
	goto L205;
    }
/* ...     YES - IF PTPP RECORD ALREADY STARTED, SET FOR TERMINATION */
    if (aptpp_1.jmode != 5) {
	goto L200;
    }
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.nw;
    ipt[OTHER_ENDIAN_S(2)] = aptpp_1.npt;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    goto L220;
L200:
    aptpp_1.jmode = 3;
    goto L220;

/* ...     NOT END - RECORD MUST BE CONTINUED... */
/* ...     IF THIS IS START OF RECORD, ADJUST MODE FLAG */
L205:
    if (aptpp_1.jmode != 5) {
	goto L210;
    }
    aptpp_1.jmode = 1;
    goto L220;
/* ...     NO - SET FLAG FOR CONTINUATION */
L210:
    aptpp_1.jmode = 2;

L220:
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L990;
    }
    aptpp_1.inptp = 1;
/* ...     IF PTPP RECORD NOT COMPLETED, RETURN TO CONTINUE SCAN */
    if (aptpp_1.jmode >= 3) {
	goto L995;
    }
    switch ((int)sc) {
	case 1:  goto L15;
	case 2:  goto L15;
	case 3:  goto L390;
	case 4:  goto L50;
	case 5:  goto L50;
    }

/* ...     INDEX */
L260:
    aptlod_();
    aptpp_1.npt = 1;
/* ...     TEST FIRST PARAMETER FOR SCALAR */
    if (amotcm_1.jptind == 2) {
	goto L265;
    }
    if (amotcm_1.jptind == 3) {
	goto L265;
    }
/* ...     IF ERROR FLAG SET IN APTLOD, SIMPLY EXIT */
    if (amotcm_1.jptind == 8) {
	goto L995;
    }
/* .. */
/* ..  FIRST PARAMETER HASNT A SCALAR VALUE */
    a1com_1.jsuber = 83;
    goto L990;

L265:
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L270;
    } else if (i__1 == 0) {
	goto L15;
    } else {
	goto L290;
    }
L270:
    aptlod_();
/* ...     SECOND PARAMETER CAN ONLY BE 'NOMORE' */
    if (amotcm_1.jptind != 0) {
	goto L460;
    }
    if (amotcm_1.kreslt != 53) {
	goto L460;
    }
/* ...     TEST FOR MORE PARAMETERS IN STATEMENT - IF SO, ERROR */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L15;
    }
    aptpp_1.npt = 2;
/* .. */
L290:
    asistm_1.indexx = 1;
    goto L190;
/* ... */
/*     MACHIN */
L300:
    aptlod_();
    if (amotcm_1.jptind == 1) {
	goto L306;
    }
    if (amotcm_1.jptind != 3) {
	goto L460;
    }
/* ...     MAKE SURE THERE IS NO SUBSCRIPT */
    if (ipt[OTHER_ENDIAN_S(7)] != 0) {
	goto L460;
    }
/* ...     ALSO THAT IT IS UNDEFINED */
    jtemp1 = (ipt[OTHER_ENDIAN_S(9)] << 1) - 1;
    if (ivst[OTHER_ENDIAN_S(jtemp1 + 1)] != 8) {
	goto L460;
    }
    ipt[OTHER_ENDIAN_S(6)] = 6;
    jtemp2 = ipt[OTHER_ENDIAN_S(9)];
    aptpp_1.pt[4] = avst_1.vst[jtemp2 - 1];
L306:
    if (asistm_1.numpst < 10) {
	goto L310;
    }
    a1com_1.jsuber = 504;
    goto L990;
L310:
    ++asistm_1.numpst;
    apostp_1.ppname[asistm_1.numptr - 1] = aptpp_1.pt[aptpp_1.inptp - 2];
    asistm_1.numptr += 2;
    aptpp_1.npt = 1;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L315;
    }
    apostp_1.ppname[asistm_1.numptr - 2] = (float)1.;
    goto L190;
/* ...     NEXT ENTRY MUST BE A NUMBER */
L315:
    aptlod_();
    if (amotcm_1.jptind != 2) {
	goto L460;
    }
    apostp_1.ppname[asistm_1.numptr - 2] = aptpp_1.pt[aptpp_1.inptp - 2];
/* ...     SEE IF MACHINE NUMBER HAD A NEGATIVE SIGN PREFIXED */
    if (aptpp_1.pt[aptpp_1.inptp - 4] != signeg) {
	goto L110;
    }
/* ...     YES - CHANGE ITS SIGN IN PPNAME ENTRY */
    apostp_1.ppname[asistm_1.numptr - 2] = -apostp_1.ppname[asistm_1.numptr - 
	    2];
    goto L110;

/*    COPY */
L340:
    aptlod_();
/* ...     FIRST PARAMETER MUST BE A SCALAR */
    if (amotcm_1.jptind == 2) {
	goto L350;
    }
    if (amotcm_1.jptind != 3) {
	goto L460;
    }
/* ...     IF NO MORE PARAMETERS, ERROR */
L350:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L390;
    }
    aptlod_();
/* ...     SECOND PARAMETER MUST BE A MODIFIER */
    if (amotcm_1.jptind != 0) {
	goto L460;
    }
/* ...     SAVE THE MODIFIER CODE - NEEDED FOR TESTING LATER ALSO */
    jdum = amotcm_1.kreslt;
/* ...     IF NO MORE PARAMETERS, ERROR */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L400;
    }
L390:
    a1com_1.jsuber = 507;
    goto L990;

L400:
    asistm_1.indexx = 1;
    aptlod_();
/* ...     IF MODIFIER WAS 'MODIFY', PACK MATRIX TYPE CODE WITH LATEST */
/* ...     PARAMETER, AND MAKE SURE PARAMETER IS A SURFACE */
    if (amotcm_1.kreslt != 55) {
	goto L380;
    }
    aswich_(&c__12);
    if (amotcm_1.jptind - 4 != 0) {
	goto L460;
    } else {
	goto L420;
    }

/* ...     FOR ALL OTHER MODIFIERS, THIRD PARAMETER MUST BE SCALAR */
L380:
    if (amotcm_1.jptind == 2) {
	goto L420;
    }
    if (amotcm_1.jptind != 3) {
	goto L460;
    }
L420:
    aptpp_1.npt = 3;

/* ...     TEST FOR END OF STATEMENT */
L430:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L470;
    }
/* ...     NO - GET NEXT PARAMETER - MUST BE A SCALAR */
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L440;
    }
    if (amotcm_1.jptind != 3) {
	goto L460;
    }
/* ...     INCREMENT PARAMETER COUNT, AND GO TO TEST FOR END */
L440:
    ++aptpp_1.npt;
    goto L430;

/* ...     INCORRECT PARAMETER TYPE FOUND */
/* ...     IF ERROR FLAG SET IN APTLOD, SIMPLY EXIT */
L460:
    if (amotcm_1.jptind == 8) {
	goto L995;
    }
    a1com_1.jsuber = 503;
    goto L990;

/* ...     END OF COPY STATEMENT - CHECK NUMBER OF PARAMETERS */
L470:
    for (j = 1; j <= 12; j += 2) {
	if (jdum == icopy[j - 1]) {
	    goto L490;
	}
/* L480: */
    }
    goto L460;
L490:
    if (aptpp_1.npt != icopy[j]) {
	goto L390;
    }
    goto L190;

/*      PROCESS TRANS/ STATEMENT */
L700:
    sc = 5;
    aptlod_();
/* ...     IF PARAMETER IS A SURFACE, PACK MATRIX TYPE CODE IN ITS */
/* ...     PTPP ENTRY */
    if (amotcm_1.jptind != 4) {
	goto L55;
    }
    aswich_(&c__12);
    goto L55;

/* ...     ERROR EXIT - ERASE ANY PORTION OF RECORD ALREADY OUTPUT */
L990:
    if (aptpp_1.jmode == 5) {
	goto L995;
    }
    aptpp_1.jmode = 4;
    aptput_();

L995:
    return 0;
} /* aparam_ */

#undef ipt
#undef gcl
#undef cl
#undef lment4
#undef lclas2
#undef lclas1
#undef ivst


