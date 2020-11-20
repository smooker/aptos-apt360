#include "endianmacs.h"
/* APTLOD.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int aptlod_()
{
    /* Initialized data */

    static struct {
	shortint e_1[2];
	} equiv_5 = { 0, 0 };


    /* Format strings */
    static char fmt_800[] = "(\0020   APTLOD\002,z12,z20,i3,3z12)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define ivst ((integer *)&avst_1)
    static integer nams4, inpt4;
#define itype ((shortint *)&equiv_5 + 1)
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_();
#define lment4 ((integer *)&ailmtb_1)
#define itype1 ((logical1 *)&equiv_5)
    extern /* Subroutine */ int avs1pt_();
    static integer jr, js;
#define ipunct ((shortint *)&equiv_5)
    static integer ipntyp;
#define ipt ((integer *)&aptpp_1)
    static integer icl1, icl2;

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, fmt_800, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* .... */
/* ...   THIS SUBROUTINE TAKES AN ICLASS/ELMENT ENTRY (THAT IS THE PARMS */
/* .. FOUND TO THE RIGHT OF THE MAJOR WORD--OR SLASH) AND CREATES THE */
/* ..  PTPP CODED ENTRIES (PICKUP INDEX IS ISTARP,OUTPUT INPTP) */
/* ***      ****       ****       ****MB****       ******      ***SJD*** */

/*       INTEGER*2 ITYPE/0/,IPUNCT/0/ */

/* ...     SAVE INDEX TO START OF PTPP ENTRY TO BE CONSTRUCTED */
    amotcm_1.now = aptpp_1.inptp;
/* ...     CLEAR FLAG USED TO DESCRIBE PUNCTUATION FOUND WITH A PARAMETER */
    ipntyp = 0;

/* ...     INITIALIZE FIRST 2 WORDS OF PTPP ENTRY TO ZERO */
L50:
    aptpp_1.pt[aptpp_1.inptp - 1] = (float)0.;
    aptpp_1.pt[aptpp_1.inptp] = (float)0.;
/* ...     COMPUTE PTPP INTEGER STORING INDEX */
/* L60: */
    inpt4 = (aptpp_1.inptp << 1) - 1;

/* ...     COMPUTE 1/2- AND 1/4-ENTRY PICK-UP INDEXES FOR ICLASS/ELMENT */
    icl2 = (aprtab_1.istarp << 1) - 1;
    icl1 = (aprtab_1.istarp << 2) - 3;

/* ...     GET TYPE OF ICLASS/ELMENT ENTRY */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 2)];
//    itype1[2] = lclas1[OTHER_ENDIAN_W(icl1 + 2)];
/* ...     IF NOT PUNCTUATION, CLEAR COMMA COUNTER */
    if (*itype == 4) {
	goto L80;
    }
    amotcm_1.ifurst = 0;
/* ...     BRANCH ON ENTRY TYPE */
L80:
    if (*itype == 11) {
	goto L550;
    }
    if (*itype > 0) {
	goto L90;
    }
    a1com_1.jsuber = 6133;
    goto L730;
L90:
    switch ((int)*itype) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
    }

/* ...     VARIABLE SYMBOL - PICK UP NAME */
L100:
    a1com_1.name__ = ailmtb_1.elment[aprtab_1.istarp - 1];
/* ...     DETERMINE CLASSIFICATION OF SYMBOL */
    avs1ck_(&jr);
/* .... */
    switch ((int)jr) {
	case 1:  goto L106;
	case 2:  goto L104;
	case 3:  goto L110;
	case 4:  goto L102;
	case 5:  goto L110;
	case 6:  goto L110;
	case 7:  goto L132;
	case 8:  goto L110;
	case 9:  goto L104;
    }
/* ... */
/* ...   SET UP THE PTPP ENTRY CODE FOR THIS STATEMENT I.D. */
L102:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 7;
/* ...     ALSO SET INDICATOR CODE */
    amotcm_1.jptind = 5;
    goto L120;

/* ...     SET PTPP ENTRY TYPE CODE FOR SURFACE */
L104:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 4;
/* ...     ALSO SET INDICATOR CODE */
    amotcm_1.jptind = 4;
    goto L120;

/* ...     UNDEFINED - PUT IT IN VST IF THERE IS ROOM */
L106:
    avs1pt_(&js);
    if (js != 2) {
	goto L108;
    }
/* ...  VST OVERFLOW NO ROOM TO ENTER THIS VARIABLE SYMBOL */
    a1com_1.jsuber = 15;
    a1com_1.sum = 1;
    goto L700;

/* ...     THERE WAS ROOM - SET VST ENTRY CODE TO REFERENCED */
L108:
    nams4 = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(nams4 + 1)] = 8;
    ivst[OTHER_ENDIAN_S(nams4 + 2)] = 0;

/* ...     SET PTPP ENTRY TYPE CODE FOR SCALAR */
L110:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 2;
/* ...     ALSO SET INDICATOR CODE */
    amotcm_1.jptind = 3;

/* ...     PUT VST INDEX TO SYMBOL INTO PTPP ENTRY */
L120:
    ipt[OTHER_ENDIAN_S(inpt4 + 2)] = a1com_1.namsub;
/* ...     TEST FOR FOLLOWING SUBSCRIPT */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
//    itype1[2] = lclas1[OTHER_ENDIAN_W(icl1 + 6)];
    if (*itype < 7) {
	goto L122;
    }
    if (*itype != 11) {
	goto L125;
    }

/* ...     NO SUBSCRIPT - SEE WHETHER SYMBOL REQUIRES ONE */
L122:
    if (jr < 6) {
	goto L700;
    }
/* ...     YES - ERROR */
/* .. NO SUBSCRIPT GIVEN FOR A VARIABLE THAT APPEARED IN A RESERV STMT. */
    a1com_1.jsuber = 105;
    a1com_1.sum = 1;
    goto L700;

/* ...     SUBSCRIPT FOUND - SEE WHETHER SYMBOL SHOULD HAVE ONE */
L125:
    if (jr >= 6) {
	goto L150;
    }
/* ...  SUBSCRIPT GIVEN FOR A VAR. SYMB. NOT GIVEN IN A RESERV STMT */
/* L130: */
    a1com_1.jsuber = 108;
    if (*itype != 8) {
	goto L135;
    }
/* ... OUTPUT THE NUMERIC SUBSCRIPT FOR THIS VAR. IN ERROR */
    aptpp_1.pt[6] = ailmtb_1.elment[aprtab_1.istarp];
    a1com_1.sum = 9;
    goto L170;
/* ....... */
/* ... VAR. IS A PREVIOUSLY DEFINED MACRO NAME      -- ERROR */
L132:
    a1com_1.jsuber = 211;
/* ...     SET INDICATOR CODE FOR ERROR ALSO */
    amotcm_1.jptind = 8;

/* ...     SET FLAG TO INCLUDE SYMBOL IN DIAGNOSTIC, AND OUTPUT IT */
L135:
    a1com_1.sum = 1;
    goto L170;

/* ...     SUBSCRIPT REQUIRED AND FOUND - BRANCH ON ITS TYPE */
L150:
    if ((i__1 = *itype - 8) < 0) {
	goto L155;
    } else if (i__1 == 0) {
	goto L160;
    } else {
	goto L165;
    }

/* ...     SUBSCRIPT IS VARIABLE SYMBOL - PUT CODE INTO PTPP */
L155:
    ipt[OTHER_ENDIAN_S(inpt4)] = 2;
/* ...     PUT VST INDEX TO SUBSCRIPT SYMBOL INTO PTPP */
    ipt[OTHER_ENDIAN_S(inpt4 + 1)] = lment4[OTHER_ENDIAN_S(icl2 + 2)];
    goto L170;

/* ...     SUBSCRIPT IS NUMBER - PUT CODE INTO PTPP */
L160:
    ipt[OTHER_ENDIAN_S(inpt4)] = 1;
/* ...     PUT VALUE OF SUBSCRIPT INTO THIRD WORD OF PTPP ENTRY */
    aptpp_1.pt[aptpp_1.inptp + 1] = ailmtb_1.elment[aprtab_1.istarp];
/* ...     INCREMENT PTPP STORING INDEX BY ONE TO ACCOUNT FOR */
/* ...     THE EXTRA WORD FOR THIS SUBSCRIPT IN THE PTPP ENTRY */
    ++aptpp_1.inptp;
    goto L170;

/* ...     SUBSCRIPT IS A COMPUTED EXPRESSION OR AN INCLUSIVE FORMAT - */
/* ...     TEST FOR EXPRESSION */
L165:
    if (*itype != 9) {
	goto L167;
    }
/* ...     YES - PUT CODE INTO PTPP */
    ipt[OTHER_ENDIAN_S(inpt4)] = 3;
/* ...     GO TO PUT SCALAR TABLE INDEX TO SUBSCRIPT VALUE INTO PTPP */
    goto L168;

/* ...     INCLUSIVE SUBSCRIPT FORMAT - PUT CODE INTO PTPP */
L167:
    ipt[OTHER_ENDIAN_S(inpt4)] = 4;
/* ...     PUT SCALAR TABLE INDEX TO SUBSCRIPT VALUE, OR INDEX TO */
/* ...     STORAGE FOR DATA BLOCK POINTER, INTO PTPP */
L168:
    ipt[OTHER_ENDIAN_S(inpt4 + 1)] = lment4[OTHER_ENDIAN_S(icl2 + 2)];

/* ...     INCREMENT ICLASS/ELMENT PICK-UP INDEX ONE TO ACCOUNT */
/* ...     FOR THE SUBSCRIPT ENTRY FOR THIS SYMBOL */
L170:
    ++aprtab_1.istarp;
    goto L700;

/* ...     VOCABULARY WORD - SET PTPP ENTRY TYPE CODE */
L200:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 6;
    amotcm_1.kreslt = lment4[OTHER_ENDIAN_S(icl2)];
/* ...     PICK UP VOCABULARY SUBTYPE */
/* L210: */
    amotcm_1.krslt2 = lment4[OTHER_ENDIAN_S(icl2 - 1)];
/* ...     SEE IF WORD IS MAJOR OR MINOR - INITIALIZE INDICATOR FOR MINOR */
    amotcm_1.jptind = 0;
itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
//    itype1[2] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
    if (*itype == 29) {
	goto L310;
    }
/* ...     MAJOR - SET INDICATOR */
    amotcm_1.jptind = 1;
/* ...     GO TO PUT PROTAP CLASS AND SUBCLASS CODES (IN ELMENT) */
/* ...     INTO THE 2ND WORD OF THIS PTPP ENTRY */
    goto L310;

/* ...     NUMBER - SET PTPP ENTRY TYPE CODE */
L300:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 1;
/* ...     ALSO SET INDICATOR CODE */
    amotcm_1.jptind = 2;

/* ...     PUT VALUE OF NUMBER, OR PROTAP CODES FOR A VOCABULARY */
/* ...     WORD, INTO 2ND WORD OF PTPP ENTRY */
L310:
    aptpp_1.pt[aptpp_1.inptp] = ailmtb_1.elment[aprtab_1.istarp - 1];
    goto L700;

/* ...     PUNCTUATION - SET INDICATOR FOR IT, AND PICK UP TYPE */
L400:
    amotcm_1.jptind = 9;
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
//    itype1[2] = lclas1[OTHER_ENDIAN_W(icl1 + 1)];
    amotcm_1.krslt2 = *itype;
/* ...     TEST FOR A COMMA */
    if (*itype != 9) {
	goto L430;
    }

/* ...     YES - IF THIS IS A COMPUTING EXPRESSION, ERROR */
    if (aprtab_1.itsq != 1) {
	goto L405;
    }
    a1com_1.jsuber = 7;
    goto L730;

/* ...     NO - IF COMMA IMMEDIATELY FOLLOWS A SIGN, ERROR */
L405:
    if (ipntyp <= 0) {
	goto L410;
    }
    ++aprtab_1.istarp;
    goto L735;

/* ...     IF SCANNING GEOMETRIC FORMAT, TEST FOR 2ND SUCCESSIVE COMMA */
L410:
    if (aprtab_1.itsq != 3) {
	goto L420;
    }
    if (amotcm_1.ifurst == 1) {
	goto L415;
    }
/* ...     NO - COUNT THIS COMMA, AND EXIT */
    amotcm_1.ifurst = 1;
    goto L730;

/* ...     SECOND CONSECUTIVE COMMA - SET TYPE CODE TO OUTPUT SPECIAL */
/* ...     PUNCTUATION ENTRY FOR IT */
L415:
    *itype = 10;
    goto L435;

/* ...     NO - TEST FOR AUTOMATIC PICK-UP OF ENTRY FOLLOWING COMMA - IF */
/* ...     NOT, JUST DELETE COMMA AND EXIT */
L420:
    if (aprtab_1.itsq - 4 != 0) {
	goto L730;
    } else {
	goto L425;
    }
/* ...     PICKING UP NEXT ENTRY - SET FLAG FOR COMMA FOUND, AND GO TO */
/* ...     SPACE PAST IT */
L425:
    ipntyp = -1;
    goto L440;

/* ...     NOT A COMMA - CLEAR COMMA COUNTER */
L430:
    amotcm_1.ifurst = 0;
/* ...     SET PTPP ENTRY TYPE CODE FOR PUNCTUATION */
L435:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 8;
/* ...     PUT PUNCTUATION CODE INTO PTPP ENTRY */
    ipt[OTHER_ENDIAN_S(inpt4)] = *itype;
/* ...     INCREMENT PTPP STORING INDEX BY ONE HERE FOR THIS PUNCTUATION */
/* ...     ENTRY, AND SKIP INCREMENTING OF THIS INDEX LATER */
    ++aptpp_1.inptp;
/* ...     IF NOT SCANNING A COMPUTING EXPRESSION, SEE IF THIS IS A SIGN */
    if (aprtab_1.itsq == 1) {
	goto L730;
    }
    if (*itype > 2) {
	goto L730;
    }
/* ...     SIGN FOUND - MAKE SURE IT IS NOT SECOND CONSECUTIVE ONE */
    if (ipntyp > 0) {
	goto L735;
    }
/* ...     SET FLAG FOR SIGN, SKIP IT, AND GO TO GET NEXT ENTRY, IF ANY */
    ipntyp = 1;

L440:
    ++aprtab_1.istarp;
/* ...     MAKE SURE THERE IS ANOTHER ENTRY - IF NOT, ERROR */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L50;
    }
    a1com_1.jsuber = 129;
    goto L745;

/* ...     NESTED COMPUTING EXPRESSION - SET PTPP ENTRY TYPE CODE */
L500:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 3;
/* ...     SET INDICATOR CODE FOR NUMBER */
    amotcm_1.jptind = 2;
/* ...     GO TO PUT INDEX TO STORAGE FOR VALUE OF EXPRESSION */
/* ...     INTO PTPP ENTRY */
    goto L610;

/* ...     NESTED ARGUMENT LIST - SET PTPP ENTRY TYPE CODE */
L550:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 9;
/* ...     GO TO PUT INDEX TO STORAGE FOR POINTER TO DATA BLOCK */
/* ...     INTO PTPP ENTRY */
    goto L610;

/* ...     NESTED SURFACE DEFINITION - SET PTPP ENTRY TYPE CODE */
L600:
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = 5;
/* ...     ALSO SET INDICATOR CODE */
    amotcm_1.jptind = 4;
/* ...     PUT INDEX TO LOCATION FOR STORAGE OF SURFACE, OR INDEX */
/* ...     TO STORAGE FOR VALUE OF EXPRESSION, INTO PTPP ENTRY */
L610:
    ipt[OTHER_ENDIAN_S(inpt4 + 2)] = lment4[OTHER_ENDIAN_S(icl2)];

/* ...     INCREMENT PTPP STORING INDEX FOR NORMAL 2-WORD ENTRY - IF 3RD */
/* ...     WORD WAS REQUIRED, STORING INDEX ALREADY INCREMENTED FOR IT */
L700:
    aptpp_1.inptp += 2;
/* ...     INCREMENT PICK-UP INDEX PAST ICLASS/ELMENT ENTRY JUST READ */
L730:
    ++aprtab_1.istarp;

/* ...     TEST FOR SIGN FOUND PRECEDING PARAMETER */
    if (ipntyp <= 0) {
	goto L740;
    }
/* ...     YES - PARAMETER MUST BE A SCALAR, OR ERROR */
    if (amotcm_1.jptind == 2) {
	goto L740;
    }
    if (amotcm_1.jptind == 3) {
	goto L740;
    }
L735:
    a1com_1.jsuber = 78;

/* ...     IF ERROR FLAG WAS SET IN THIS ROUTINE, ADJUST RETURN INDICATOR */
L740:
    if (a1com_1.jsuber == 0) {
	goto L750;
    }
L745:
    amotcm_1.jptind = 8;

/* ...     RETURN TO CALLING ROUTINE */
L750:
    if (a1com_1.debug == 0) {
	goto L900;
    }
    s_wsfe(&io___15);
    do_fio(&c__1, (char *)&ailmtb_1.iclass[aprtab_1.istarp - 2], (ftnlen)
	    sizeof(integer));
    do_fio(&c__1, (char *)&ailmtb_1.elment[aprtab_1.istarp - 2], (ftnlen)
	    sizeof(doublereal));
    do_fio(&c__1, (char *)&amotcm_1.jptind, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amotcm_1.kreslt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amotcm_1.krslt2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ipntyp, (ftnlen)sizeof(integer));
    e_wsfe();
L900:
    return 0;
} /* aptlod_ */

#undef ipt
#undef ipunct
#undef itype1
#undef lment4
#undef lclas1
#undef itype
#undef ivst


