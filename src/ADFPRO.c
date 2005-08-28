/* ADFPRO.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

/* Table of constant values */

static integer c__2 = 2;

/* Subroutine */ int adfpro_()
{
    /* Initialized data */

    static struct {
	shortint e_1;
	} equiv_2 = { 0 };


    /* Local variables */
    static integer idum, inpt;
#define ivst ((integer *)&avst_1)
    static integer inpt4, k, isave, ilast;
#define lment ((integer *)&ailmtb_1)
    static integer ksurf, j1;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_();
    static integer ia;
    extern /* Subroutine */ int avs1pt_(), adclar_();
    static integer jv, islash;
    extern /* Subroutine */ int aprfix_();
    static integer jlmsav;
    extern /* Subroutine */ int aptlod_(), aexprs_(), aptput_();
#define gat ((logical1 *)&equiv_2)
#define iat ((shortint *)&equiv_2)
#define ipt ((integer *)&aptpp_1)
short int debugg;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER ISLASH/Z00000304/ */
    islash=0x304;
/*       INTEGER*2 IAT/0/ */
/*     THIS SUBROUTINE OUTPUTS CLASS 3 PTPP RECORDS - SURFACE DEF. */
    *iat=0;
    jlmsav = ailmtb_1.jlment;
    inpt = 5;
    ksurf = (aprtab_1.istarp << 2) - 3;
	debugg=lclas1[OTHER_ENDIAN_W(ksurf + 2)];
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(ksurf + 2)];
    if (*iat != 4) {
	goto L5;
    }
    ++aprtab_1.istarp;
/* ...     SEE IF SURFACE IS NAMED */
L5:
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != 1) {
	goto L70;
    }

/*     YES - SET UP PTPP FOR NAMED SURFACE - CHECK SUBSCRIPT */
    j1 = 0;
    k = 0;
    a1com_1.name__ = ailmtb_1.elment[aprtab_1.istarp - 1];
    ++aprtab_1.istarp;
/* ...     TEST FOR SUBSCRIPT ON NAME */
    ksurf = (aprtab_1.istarp << 2) - 3;
	debugg=lclas1[OTHER_ENDIAN_W(ksurf + 2)];
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(ksurf + 2)];
    if (*iat <= 6) {
	goto L60;
    }
    ia = *iat - 6;
/* ...     SUBSCRIPTED - BRANCH ON TYPE */
    switch ((int)ia) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L340;
	case 5:  goto L340;
    }
/*     SYMBOLIC SUBSCRIPT */
L10:
    j1 = 2;
    goto L40;
/*     NUMERIC SUBSCRIPT */
L20:
    j1 = 1;
    aptpp_1.pt[4] = ailmtb_1.elment[aprtab_1.istarp - 1];
    inpt = 6;
    goto L50;
/*     COMPUTED SUBSCRIPT */
L30:
    j1 = 3;
L40:
    ksurf = (aprtab_1.istarp << 1) - 1;
    k = lment[OTHER_ENDIAN_S(ksurf)];
L50:
    ++aprtab_1.istarp;

/* ...     PUT SURFACE DEFINITION CODE AND SUBSCRIPT TYPE */
/* ...     INDICATOR INTO PTPP RECORD */
L60:
    ipt[OTHER_ENDIAN_S(4)] = 4;
    ipt[OTHER_ENDIAN_S(5)] = j1;
    avs1ck_(&jv);
    if (jv != 1) {
	goto L64;
    }

/* ...     SYMBOL NOT IN VST, SO NOT DIMENSIONED - IF IT */
/* ...     HAS A SUBSCRIPT, IT IS AN ERROR */
    if (*iat > 6) {
	goto L320;
    }
/* ...     ADD SYMBOL TO VST */
/* L63: */
    avs1pt_(&jv);
/* ...     TEST FOR VARIABLE SYMBOL TABLE OVERFLOW */
    if (jv - 1 != 0) {
	goto L290;
    } else {
	goto L67;
    }

/* ...     SYMBOL ALREADY IN VST - IF SUBSCRIPTED, ONLY UNDEFINED */
/* ...     OR DEFINED AS SURFACE ACCEPTABLE */
L64:
    if (*iat <= 6) {
	goto L66;
    }

    switch ((int)jv) {
	case 1:  goto L330;
	case 2:  goto L320;
	case 3:  goto L320;
	case 4:  goto L330;
	case 5:  goto L330;
	case 6:  goto L65;
	case 7:  goto L330;
	case 8:  goto L310;
	case 9:  goto L68;
    }
L65:
    aprfix_(&c__2, &idum);
    goto L68;

/* ...     NOT SUBSCRIPTED - MUST BE DEFINED AS SURFACE, OR REFERENCED */
L66:
    switch ((int)jv) {
	case 1:  goto L330;
	case 2:  goto L68;
	case 3:  goto L67;
	case 4:  goto L330;
	case 5:  goto L330;
	case 6:  goto L340;
	case 7:  goto L330;
	case 8:  goto L310;
	case 9:  goto L340;
    }

L67:
    ksurf = (a1com_1.namsub << 1) - 1;
    ivst[OTHER_ENDIAN_S(ksurf + 1)] = 7;
    ivst[OTHER_ENDIAN_S(ksurf + 2)] = 0;

L68:
    ipt[OTHER_ENDIAN_S(6)] = k;
    ipt[OTHER_ENDIAN_S(7)] = a1com_1.namsub;
    ++aprtab_1.istarp;
    aptpp_1.inptp = inpt;
    goto L90;

/*     NESTED, UNNAMED SURFACE - SET SURFTB INDEX */
L70:
    ipt[OTHER_ENDIAN_S(4)] = 0;
    ipt[OTHER_ENDIAN_S(5)] = ascalr_1.iscws;
    ailmtb_1.elment[aprtab_1.istarp - 2] = aptpp_1.pt[2];
/* ...     IS THERE ROOM FOR DEFINITION IN SURFACE TABLE */
/* L75: */
    ksurf = (aprtab_1.istarp << 1) - 1;
    if (ascalr_1.iscws + lment[OTHER_ENDIAN_S(ksurf - 1)] > 180) {
	goto L280;
    }
    ascalr_1.iscws += lment[OTHER_ENDIAN_S(ksurf - 1)];
/*     YES - PRESS ON */
/* L80: */
    aptpp_1.inptp = 4;

/* ...     PUT TYPE CODE (3) FOR SURFACE DEFINITION INTO PTPP RECORD */
L90:
    ipt[OTHER_ENDIAN_S(0)] = 3;
/* ...     PUT FLAG INTO 2ND WORD TO DISTINGUISH DEFINITION FROM */
/* ...     SURFACE READ IN (READ/1) */
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
/* ...     PUT SURFACE TYPE CODE AND LENGTH INTO PTPP RECORD */
    ksurf = (aprtab_1.istarp << 1) - 1;
    inpt4 = (aptpp_1.inptp << 1) - 1;
    ipt[OTHER_ENDIAN_S(inpt4 - 1)] = lment[OTHER_ENDIAN_S(ksurf)];
    ipt[OTHER_ENDIAN_S(inpt4)] = lment[OTHER_ENDIAN_S(ksurf - 1)];
/* ...     INCREMENT STORING INDEX, AND SAVE PICK-UP INDEX LOCATION */
    ++aptpp_1.inptp;
    inpt = aptpp_1.inptp;
    isave = aprtab_1.istarp;
/* ...     IF STATEMENT LACKS AT LEAST 2 MORE ELMENT ENTRIES, ERROR */
    if (aprtab_1.istarp + 2 > aprtab_1.iendp) {
	goto L350;
    }

/* ...     LOCATE SECOND ENTRY FOLLOWING SLASH */
    aprtab_1.istarp += 2;
    aprtab_1.itsq = 4;
    ailmtb_1.jlment = aprtab_1.iendp;
    aptlod_();
    if (aprtab_1.istarp + 1 > aprtab_1.iendp) {
	goto L120;
    }
    if (amotcm_1.jptind == 9) {
	goto L120;
    }
    aptlod_();
    aprtab_1.itsq = 3;
/* ...     SEE IF SECOND ENTRY IS VOCABULARY WORD 'CANON' */
    if (amotcm_1.jptind != 1) {
	goto L120;
    }
    if (amotcm_1.kreslt == 3099) {
	goto L130;
    }

/* ...     IT IS NOT - CHECK STATEMENT FOR ONLY COMMAS AS SEPARATORS */
L120:
    ilast = aprtab_1.iendp - 1;
    adclar_(&isave, &ilast);
    if (a1com_1.jsuber != 0) {
	goto L300;
    }

/* ...     RESTORE PICK-UP INDEX */
L130:
    aprtab_1.istarp = isave + 1;
    aptpp_1.inptp = inpt;
/* ...     MAKE SURE NEXT ICLASS ENTRY IS A SLASH */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L270;
    }

/* ...     ICLASS PICK-UP INDEX WILL BE MOVED PAST SLASH IN AEXPRS */
/* ...     CLEAR SUCCESSIVE COMMA FLAG FOR APTLOD */
    amotcm_1.ifurst = 0;
/* ...     CALL AEXPRS TO MOVE PARAMETERS FOLLOWING SLASH INTO PTPP, */
/* ...     AND OUTPUT RECORD */
    aexprs_();
L250:
    ailmtb_1.jlment = jlmsav;
    return 0;

/* ...     NO SLASH FOUND */
L270:
    a1com_1.jsuber = 155;
    goto L300;
/* ...     NOT ENOUGH STORAGE SPACE FOR UNNAMED SURFACE */
L280:
    a1com_1.jsuber = 62;
    goto L300;
/*     VST IS FULL */
L290:
    a1com_1.jsuber = 15;
L295:
    a1com_1.sum = 1;

/*     ABORT THIS PTPP CLASS */
L300:
    aptpp_1.jmode = 4;
    aptput_();
    goto L250;

/*     ATTEMPTING TO DEFINE SURFACE IN SCALAR ARRAY */
L310:
    a1com_1.jsuber = 106;
    goto L295;
/*     SUBSCRIPTED VARIABLE HAS NOT APPEARED IN A RESERV STATEMENT */
L320:
    a1com_1.jsuber = 108;
    goto L295;
/*     MULTIPLY DEFINED SYMBOL */
L330:
    a1com_1.jsuber = 1002;
    goto L295;
/*     NO SUBSCRIPT FOR DIMENSIONED VARIABLE SYMBOL */
L340:
    a1com_1.jsuber = 105;
    goto L295;
/* ...     NOT ENOUGH PARAMETERS */
L350:
    a1com_1.jsuber = 129;
    goto L295;

} /* adfpro_ */

#undef ipt
#undef iat
#undef gat
#undef lclas1
#undef lment
#undef ivst


