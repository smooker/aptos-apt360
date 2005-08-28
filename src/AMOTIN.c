/* AMOTIN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

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
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

/* Table of constant values */

static integer c__100 = 100;

/* Subroutine */ int amotin_()
{
    /* Initialized data */

    static integer islash = 0x304;
    static integer minmod[10] = { 69,1,70,2,71,3,27,4,146,8 };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ipat, iuse;
#define ivst ((integer *)&avst_1)
    static integer i__, j, k, idcnt, major, minor, jtool;
    extern /* Subroutine */ int avs1ck_(), aifun8_();
    static integer jtemp1, jtemp2, jtemp3;
    extern /* Subroutine */ int avs1pt_();
    static integer it;
    extern /* Subroutine */ int aswich_(), aptlod_();
    static integer numcom, isubst, numsrf;
    extern /* Subroutine */ int aptput_();
    static integer ntsurf;
#define ipt ((integer *)&aptpp_1)
    static integer jvs, izw;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/*       INTEGER ISLASH/Z00000304/ */
/*       INTEGER MINMOD(10)/69,1,70,2,71,3,27,4,146,8/ */

/* ...     JTEMP3 IS A NUMBER COUNTER */
/* L10: */
    jtemp3 = 0;
/* ...     INITIALIZE FLAG TO CHECK NUMBER OF SCALARS IN STATEMENT */
    ipat = 1;
    jtool = 0;
    ipt[OTHER_ENDIAN_S(0)] = 6;
    aptpp_1.inptp = 4;
    aptpp_1.npt = 0;
    aptpp_1.jmode = 5;

/* ...     PICK UP A PTPP ENTRY AND EVALUATE */
L20:
    aptlod_();
/* ...     RESET PTPP STORING INDEX TO START */
    aptpp_1.inptp = 4;
/* ...     0=MINOR MODIFIER, 1=VOCABULARY, */
/* ...     2=NUMBER, 3=SCALAR VARIABLE, 4=SURFACE, 5=STATEMENT I.D. */
/* ...     6=UNDEFINED(MAY BE I.D.), 7=SUBSCRIPTED VARIABLE, 8=ERROR */
    if (amotcm_1.jptind == 1) {
	goto L70;
    }
    if (amotcm_1.jptind - 8 != 0) {
	goto L110;
    } else {
	goto L5000;
    }
/* ...     CONVERT VOCABULARY CODE FOR BRANCHING */
L70:
    jtemp1 = amotcm_1.kreslt / 1000;
    major = amotcm_1.kreslt;
    isubst = amotcm_1.krslt2;
    ipt[OTHER_ENDIAN_S(4)] = amotcm_1.kreslt;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
/* ...     TEST BRANCH SWITCH RANGE */
    if (jtemp1 <= 0) {
	goto L110;
    }
    if (jtemp1 >= 9) {
	goto L110;
    }
/* ...     TEST FOR TOOL POSITION INDICATOR */
    if (jtemp1 == 4) {
	goto L260;
    }
/* ...     NO - TEST FOR FURTHER DATA - ERROR IF NONE */
    if (aprtab_1.istarp + 1 > ailmtb_1.jlment) {
	goto L3000;
    }
/* ...     TEST FOR SLASH FOLLOWING MAJOR WORD */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
/* ...     YES - MOVE SCANNING INDEX PAST IT */
    ++aprtab_1.istarp;

/* ...     BRANCH ON PROTAP THOUSAND CODE (4 THROUGH 9, 1-3 ILLEGAL HERE) */
/* L100: */
    switch ((int)jtemp1) {
	case 1:  goto L110;
	case 2:  goto L110;
	case 3:  goto L1600;
	case 4:  goto L260;
	case 5:  goto L330;
	case 6:  goto L110;
	case 7:  goto L1650;
	case 8:  goto L1645;
    }
L110:
    a1com_1.jsuber = 133;
/* L120: */
    goto L5000;

/* ...     4000 CODE FOUND */

/* ...     PUT 4000 CODE INTO PROTAP RECORD BLOCK */
L260:
    if (jtool == 1) {
	goto L4000;
    }
    ipt[OTHER_ENDIAN_S(1)] = 2;
    aptpp_1.pt[1] = 0.;
    aptpp_1.inptp = 3;
    aptput_();
    jtool = 1;
    aprtab_1.itsq = 4;
    if (aprtab_1.istarp - ailmtb_1.jlment <= 0) {
	goto L20;
    } else {
	goto L5000;
    }
/* ... */
/* ...     5000 CODE FOUND */
/* ... */
L330:
    aprtab_1.itsq = 0;
/* L340: */
    numcom = 1;
L345:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L560;
    }

/* ...     PICK UP NEXT PARAMETER */
    aptlod_();
/* ...     TEST FOR PUNCTUATION */
    if (amotcm_1.jptind != 9) {
	goto L390;
    }
/* ...     YES - ONLY COMMA ACCEPTABLE */
    if (amotcm_1.krslt2 - 9 != 0) {
	goto L4000;
    } else {
	goto L755;
    }

/* ...     IF OUTPUTTING PATTERN, SKIP INSERTION AND SURFACE TYPE TESTS */
L390:
    if (ipat == 0) {
	goto L555;
    }
/* ...     CHECK FOR INSERTING IDUMMY OR ZERO */
    if (amotcm_1.jptind == 4) {
	goto L490;
    }
/* ...     IF MODIFIER WORD FOUND, ASSUMED TO BE OUTPUTTING PATTERN */
    if (amotcm_1.jptind == 0) {
	goto L515;
    }
    if (jtemp3 == 0) {
	goto L410;
    }
    if (jtemp3 != 3) {
	goto L405;
    }
    if (isubst < 3) {
	goto L410;
    }
    if (isubst > 5) {
	goto L410;
    }
    goto L490;
L405:
    if (jtemp3 != 6) {
	goto L490;
    }
/* ...     MUST MOVE PARAMETER UP AND INSERT ZEROS IN LOCATIONS FOR */
/* ...     SURFACE NAME AND SUBSCRIPT PRECEDING IT... */
L410:
    i__1 = aptpp_1.inptp;
    for (j = amotcm_1.now; j <= i__1; ++j) {
/* L430: */
	aptpp_1.pt[j + 3] = aptpp_1.pt[j - 1];
    }
    jtemp1 = (amotcm_1.now << 1) - 1;
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 1;
    ipt[OTHER_ENDIAN_S(jtemp1)] = 0;
    aptpp_1.pt[amotcm_1.now] = 0.;
    aptpp_1.pt[amotcm_1.now + 1] = aptpp_1.pt[amotcm_1.now - 1];
    aptpp_1.pt[amotcm_1.now + 2] = 0.;
    aptpp_1.inptp += 4;
    amotcm_1.now += 4;
    aptpp_1.npt += 2;
L490:

/* ...     ONLY A NUMBER OR A SURFACE IS ALLOWED(JPTIND=2,3,4) */
    switch ((int)amotcm_1.jptind) {
	case 1:  goto L4020;
	case 2:  goto L500;
	case 3:  goto L500;
	case 4:  goto L520;
	case 5:  goto L4000;
	case 6:  goto L4000;
	case 7:  goto L4000;
	case 8:  goto L5000;
    }

L500:
    ++jtemp3;
    goto L555;

/* ...     VOCAB. FOUND IN GOTO/ - SET FLAG TO BLOCK CHECK ON */
/* ...     NUMBER OF SCALARS IN STATEMENT - PATTERN OUTPUT MAY INCLUDE */
/* ...     INDEFINITE NUMBER OF POINT NUMBER REFERENCES */
L515:
    ipat = 0;
    goto L555;

L520:
    jtemp3 += 3;
    it = 11;
/* ...     CHECK IF POINT OR VECTOR */
    if (isubst / 2 << 1 == isubst) {
	goto L550;
    }
    if (isubst == 1) {
	goto L540;
    }
    if (jtemp3 >= 6) {
	goto L550;
    }
L540:
    it = 1;
/* ...     PACK A DATA TYPE CODE INTO PTPP ENTRY */
L550:
    aswich_(&it);
L555:
    ++aptpp_1.npt;
/* ...     IF PREVIOUS ELEMENT PICKED UP WAS NOT COMMA, ERROR */
    if (numcom != 1) {
	goto L4030;
    }
/* ...     IT WAS COMMA - CLEAR FLAG FOR IT */
    numcom = 0;
/* ...     BACK FOR NEXT PARAMETER */
    goto L345;

/* ...     CHECK NUMBER OF SCALARS IN STATEMENT IF NO VOCABULARY */
/* ...     WORDS WERE FOUND, INDICATING PATTERN OUTPUT */
L560:
    if (ipat == 0) {
	goto L4990;
    }
    if (jtemp3 <= 0) {
	goto L3000;
    }
    if (jtemp3 > 10) {
	goto L3000;
    }
    if (isubst < 3) {
	goto L570;
    }
    if (isubst > 5) {
	goto L570;
    }
    if (jtemp3 > 7) {
	goto L3000;
    }
L570:
    switch ((int)jtemp3) {
	case 1:  goto L650;
	case 2:  goto L680;
	case 3:  goto L750;
	case 4:  goto L600;
	case 5:  goto L3000;
	case 6:  goto L750;
	case 7:  goto L600;
	case 8:  goto L3000;
	case 9:  goto L750;
	case 10:  goto L600;
    }

/* ...     FEED RATE INDICATED */
/* ...     SAVE 5000 PT RECORD */
L600:
    for (k = 1; k <= 30; ++k) {
/* L610: */
	amotcm_1.pint[k - 1] = aptpp_1.pt[k - 1];
    }

/* ...     STORE 2000 CODE */
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 1;
    ipt[OTHER_ENDIAN_S(4)] = 2000;
    ipt[OTHER_ENDIAN_S(5)] = 1009;
    jtemp1 = amotcm_1.now;
    jtemp2 = aptpp_1.inptp - amotcm_1.now;
    i__1 = jtemp2;
    for (k = 1; k <= i__1; ++k) {
	aptpp_1.pt[k + 2] = aptpp_1.pt[jtemp1 - 1];
/* L615: */
	++jtemp1;
    }
    ipt[OTHER_ENDIAN_S(1)] = jtemp2 + 2;
    aptpp_1.inptp = jtemp2 + 3;
    aptput_();
/* ...  BRING BACK 5000 RECORD */
    aptpp_1.inptp = amotcm_1.now;
    for (k = 1; k <= 30; ++k) {
/* L620: */
	aptpp_1.pt[k - 1] = amotcm_1.pint[k - 1];
    }

/* ...     CHECK FOR GODLTA/I,FDR */
    if (isubst != 4) {
	goto L720;
    }
    if (jtemp3 != 2) {
	goto L720;
    }
/* ... ONE SCALAR PARAMETER GIVEN...MUST BE GODLTA */
L650:
    if (isubst != 4) {
	goto L3000;
    }
/* ...     SPECIAL GODLTA/I - CONSTRUCT RECORD FOR IT */
    aptpp_1.npt = 3;
    aptpp_1.pt[4] = adata1_1.tlaxis;
    goto L4980;

/* ...     TWO SCALAR PARAMETERS GIVEN... */
/* ...     TEST FOR GODLTA/I,FDR */
L680:
    if (isubst == 4) {
	goto L600;
    }
/* ...     NO - TEST FOR FROM AND GOTO */
    if (isubst == 3) {
	goto L750;
    }
    if (isubst - 5 != 0) {
	goto L3000;
    } else {
	goto L750;
    }

/* ...     STATEMENT ENDED IN FEED RATE, THOUGH NOT GODLTA/I,FDR... */
/* ...     DECREMENT SCALAR AND PARAMETER COUNTERS TO DROP FEED RATE */
L720:
    --aptpp_1.npt;
    --jtemp3;

/* ...     FILL UP WITH ZEROS IF NEEDED, INDIRP, INDIRV, SRFVCT */
L750:
    if (isubst <= 2) {
	goto L760;
    }
    if (isubst == 8) {
	goto L760;
    }
    goto L4980;

/* ...     TEST FOR FOLLOWING ANOTHER COMMA */
L755:
    if (numcom > 0) {
	goto L758;
    }
/* ...     FIRST ONE - ONLY COUNT IT, UNLESS IT IS RIGHT AFTER SLASH */
    if (jtemp3 == 0) {
	goto L758;
    }
    numcom = 1;
    goto L345;

/* ...     SECOND (OR LATER) COMMA - CHECK FOR INDIRV, INDIRP, SRFVCT */
L758:
    if (isubst <= 2) {
	goto L760;
    }
    if (isubst != 8) {
	goto L3000;
    }

L760:
    if (jtemp3 > 9) {
	a1com_1.jsuber = 129;
    }
    if (jtemp3 >= 9) {
	goto L4980;
    }
    jtemp1 = (aptpp_1.inptp << 1) - 1;
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 1;
    ipt[OTHER_ENDIAN_S(jtemp1)] = 0;
    aptpp_1.pt[aptpp_1.inptp] = adata1_1.dummy;
    aptpp_1.pt[aptpp_1.inptp + 1] = aptpp_1.pt[aptpp_1.inptp - 1];
    aptpp_1.pt[aptpp_1.inptp + 2] = 0.;
    aptpp_1.inptp += 4;
    for (i__ = 1; i__ <= 6; i__ += 2) {
	aptpp_1.pt[aptpp_1.inptp - 1] = aptpp_1.pt[aptpp_1.inptp - 3];
	aptpp_1.pt[aptpp_1.inptp] = 0.;
/* L765: */
	aptpp_1.inptp += 2;
    }
    aptpp_1.npt += 5;
    jtemp3 += 3;
    if (amotcm_1.jptind == 9) {
	goto L345;
    }
    goto L760;

/* ...     PSIS STATEMENT... */
/* ...     VERIFY SUBTYPE */
L1600:
    if (amotcm_1.krslt2 != 4) {
	goto L4000;
    }
/* ...     SET USAGE FLAGS */
    minor = 0;
    iuse = 4;
/* ...     GET PARAMETER */
    aptpp_1.inptp = 6;
    aptlod_();
/* ...     MAKE SURE IT IS A SURFACE */
    if (amotcm_1.jptind == 4) {
	goto L1780;
    }
/* ...     IT IS NOT - ERROR */
    if (amotcm_1.jptind == 8) {
	goto L5000;
    }
    a1com_1.jsuber = 576;
    goto L5000;

/* ...     7000 OR 8000 CODE FOUND */
/* ... */
L1645:
    minor = 0;
    goto L1655;
L1650:
    minor = 1;
L1655:
    aprtab_1.itsq = 4;
    ipt[OTHER_ENDIAN_S(0)] = 18;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    aptpp_1.pt[1] = aptpp_1.pt[2];
    aptpp_1.inptp = 2;
    aptput_();
    ipt[OTHER_ENDIAN_S(0)] = 6;
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind == 4) {
	goto L1680;
    }
    if (amotcm_1.jptind != 0) {
	goto L4000;
    }

/* ...     MINOR MODIFIER */
/* L1660: */
    if (major == 7000) {
	goto L1670;
    }
    a1com_1.jsuber = 135;
    goto L9999;

L1670:
    for (k = 1; k <= 9; k += 2) {
	if (amotcm_1.kreslt == minmod[k - 1]) {
	    goto L1675;
	}
/* L1672: */
    }
    goto L4000;
L1675:
    minor = minmod[k];
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind != 4) {
	goto L4000;
    }
/* ...     FIRST SURFACE */
L1680:
    numsrf = 1;

/* ...     OUTPUT 3000 CODE NEW */
/* L1700: */
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = minor;
    aswich_(&c__100);
    ipt[OTHER_ENDIAN_S(4)] = 3000;
    ipt[OTHER_ENDIAN_S(5)] = 2;
    ipt[OTHER_ENDIAN_S(2)] = 2;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    --aptpp_1.inptp;
    aptput_();

/* ...     CHECK OFFSET/, GO/, GO.../ */
    if (major == 8000) {
	goto L1800;
    }

    ntsurf = 3;
    if (isubst == 1) {
	goto L1740;
    }

/* ...     OFFSET */
    ntsurf = 2;
    goto L1740;

/* ...     FEED RATE GIVEN */
L1710:
    i__1 = aptpp_1.inptp;
    for (k = amotcm_1.now; k <= i__1; ++k) {
/* L1715: */
	aptpp_1.pt[k - 3] = aptpp_1.pt[k - 1];
    }
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 4;
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(4)] = 2000;
    ipt[OTHER_ENDIAN_S(5)] = 1009;
    aptpp_1.inptp += -3;
    aptput_();

/* ...     OUTPUT 7000 CODE */
L1730:
    ipt[OTHER_ENDIAN_S(1)] = 4;
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(4)] = 7000;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = numsrf;
    aptpp_1.inptp = 5;
    goto L4999;

/* ...     GO/STATEMENT */
L1740:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L1730;
    }
    minor = 1;
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind == 0) {
	goto L1760;
    }
    if (amotcm_1.jptind == 4) {
	goto L1770;
    }
    if (amotcm_1.jptind == 2) {
	goto L1750;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }

/* ...     FEED RATE GIVEN */
L1750:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L1710;
    }
    a1com_1.jsuber = 129;
    goto L1710;

/* ...     MINOR MODIFIER */
L1760:
    for (k = 1; k <= 9; k += 2) {
	if (amotcm_1.kreslt == minmod[k - 1]) {
	    goto L1765;
	}
/* L1762: */
    }
    goto L4000;
L1765:
    minor = minmod[k];
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind != 4) {
	goto L4000;
    }
/* ...     SURFACE */
L1770:
    ++numsrf;
    if (numsrf <= ntsurf) {
	goto L1775;
    }
    a1com_1.jsuber = 129;
    goto L1730;

/* ...     OUTPUT 3000 CODE */
L1775:
    if (numsrf == 2) {
	iuse = 1;
    }
    if (numsrf == 3) {
	iuse = 3;
    }
/* ...     CHECK SURFACE USE */
/* ...     OUTPUT 3000 CODE */
L1780:
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = minor;
    aswich_(&c__100);
    ipt[OTHER_ENDIAN_S(4)] = 3000;
    ipt[OTHER_ENDIAN_S(5)] = iuse;
    ipt[OTHER_ENDIAN_S(2)] = 2;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    --aptpp_1.inptp;
    aptput_();
    if (iuse != 4) {
	goto L1740;
    }
/* ...     PSIS - MAKE SURE THERE ARE NO MORE PARAMETERS */
    if (aprtab_1.istarp - ailmtb_1.jlment <= 0) {
	goto L4000;
    } else {
	goto L5000;
    }

L1800:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L2000;
    }
    idcnt = 0;
L1805:
    minor = 1;
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind == 4) {
	goto L1900;
    }
    if (amotcm_1.jptind == 2) {
	goto L1830;
    }
    if (amotcm_1.jptind == 3) {
	goto L1830;
    }
    if (amotcm_1.jptind != 0) {
	goto L4000;
    }
    for (k = 1; k <= 9; k += 2) {
	if (amotcm_1.kreslt == minmod[k - 1]) {
	    goto L1815;
	}
/* L1812: */
    }
    goto L4000;
L1815:
    minor = minmod[k];
    aptpp_1.inptp = 6;
    aptlod_();

/* L1820: */
    if (amotcm_1.jptind == 4) {
	goto L1900;
    }
    if (amotcm_1.jptind == 2) {
	goto L1830;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }

/* ...     NUMBER FOUND */
L1830:
    i__1 = aptpp_1.inptp;
    for (k = amotcm_1.now; k <= i__1; ++k) {
/* L1835: */
	aptpp_1.pt[k - 3] = aptpp_1.pt[k - 1];
    }
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 4;
    if (aprtab_1.istarp < ailmtb_1.jlment) {
	goto L1860;
    }
    aptpp_1.inptp += -3;

/* ...     OUTPUT FEED RATE RECORD */
L1840:
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(4)] = 2000;
    ipt[OTHER_ENDIAN_S(5)] = 1009;
    aptput_();
    if (numsrf >= 2) {
	goto L2010;
    }
    goto L2000;

/* ...     IS IT INTOF */
L1860:
    aptlod_();
    if (amotcm_1.jptind != 0) {
	goto L4000;
    }
    if (amotcm_1.kreslt != 5) {
	goto L4000;
    }

/* ...     OUTPUT 6000 RECORD FOR INTOF COUNT */
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(4)] = 6000;
    ipt[OTHER_ENDIAN_S(5)] = 3;
    aptpp_1.inptp += -5;
    aptput_();
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind != 4) {
	goto L4000;
    }

/* ...     SURFACE FOUND */
L1900:
    ++numsrf;

/* ...     OUTPUT 3000 CODE */
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = minor;
    aswich_(&c__100);
    ipt[OTHER_ENDIAN_S(4)] = 3000;
    ipt[OTHER_ENDIAN_S(5)] = 3;
    ipt[OTHER_ENDIAN_S(2)] = 2;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    --aptpp_1.inptp;
    aptput_();
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1910;
    }
    if (numsrf < 3) {
	goto L2010;
    }
    a1com_1.jsuber = 129;
    goto L2010;

/* ...  STATEMENT ID OR FEEDRATE */
L1910:
    aptpp_1.inptp = 4;
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1915;
    }
    if (amotcm_1.jptind == 3) {
	goto L1913;
    }
    jtemp1 = ipt[OTHER_ENDIAN_S(9)];
    a1com_1.name__ = avst_1.vst[jtemp1 - 1];
    if (amotcm_1.jptind == 5) {
	goto L1920;
    }
    if (amotcm_1.jptind == 6) {
	goto L1920;
    }
/* ...     IF ERROR FLAG SET IN APTLOD, SIMPLY EXIT */
    if (amotcm_1.jptind == 8) {
	goto L2010;
    }
    a1com_1.jsuber = 132;
    goto L2010;

L1913:
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L1920;
    } else if (i__1 == 0) {
	goto L4000;
    } else {
	goto L1914;
    }
L1914:
    if (numsrf <= 2) {
	goto L1916;
    }
    if (idcnt - numsrf + 1 >= 0) {
	goto L1916;
    } else {
	goto L1920;
    }

/* ...     NUMBER */
L1915:
    if (aprtab_1.istarp < ailmtb_1.jlment) {
	goto L1918;
    }
    if (numsrf == 3) {
	goto L1918;
    }
L1916:
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    --aptpp_1.inptp;
    goto L1840;

/* ...     MAKE SURE AN EXPRESSION IS NOT BEING USED AS AN I.D. */
L1918:
    if (ipt[OTHER_ENDIAN_S(6)] != 3) {
	goto L1919;
    }
    a1com_1.jsuber = 453;
    goto L5000;

/* ...     CONVERT NUMBER TO I.D. SYMBOL */
L1919:
    aifun8_(&aptpp_1.pt[4], &a1com_1.name__);

L1920:
    avs1ck_(&jvs);
    jtemp1 = (a1com_1.namsub << 1) - 1;
    switch ((int)jvs) {
	case 1:  goto L1930;
	case 2:  goto L4000;
	case 3:  goto L1940;
	case 4:  goto L1950;
	case 5:  goto L4000;
	case 6:  goto L4000;
	case 7:  goto L4000;
	case 8:  goto L4000;
	case 9:  goto L4000;
    }
L1930:
    avs1pt_(&jvs);
    jtemp1 = (a1com_1.namsub << 1) - 1;
    if (jvs == 1) {
	goto L1935;
    }
    a1com_1.jsuber = 15;
    a1com_1.sum = 1;
    goto L9999;

L1935:
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 8;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = 0;
L1940:
L1950:
    aptpp_1.klass = 20;
    izw = 1;
/* ...  SET TO FORWARD TRANSFER FOR PASS TWO IF SUCH IS THE CASE */
    if (ivst[OTHER_ENDIAN_S(jtemp1 + 2)] == 0) {
	izw = 0;
    }
/* ...     OUTPUT 6000 CODE TRANTO */
/* L1960: */
    ipt[OTHER_ENDIAN_S(6)] = 7;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = izw;
    ipt[OTHER_ENDIAN_S(9)] = a1com_1.namsub;
    ipt[OTHER_ENDIAN_S(4)] = 6000;
    ipt[OTHER_ENDIAN_S(5)] = 8;
    ipt[OTHER_ENDIAN_S(2)] = 1;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(1)] = 5;
    aptpp_1.pt[5] = avst_1.vst[a1com_1.namsub - 1];
    aptpp_1.inptp = 6;
    aptput_();
/* ...     COUNT STATEMENT ID */
    ++idcnt;
/* L1990: */
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1805;
    }
    if (numsrf <= 2) {
	a1com_1.jsuber = 129;
    }
    goto L2010;

/* ...     8000 RECORD */
L2000:
    ipt[OTHER_ENDIAN_S(0)] = 18;
    ipt[OTHER_ENDIAN_S(1)] = 0;
    aptpp_1.inptp = 1;
    aptput_();
    ipt[OTHER_ENDIAN_S(0)] = 6;
/* ...     SAVE 8000 RECORD */
L2010:
    ipt[OTHER_ENDIAN_S(4)] = major;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
    aptpp_1.pt[1] = 0.;
    ipt[OTHER_ENDIAN_S(1)] = 2;
    aptpp_1.inptp = 3;
/* L2020: */
    goto L4999;

/* ...     ERROR MESSAGES */

L3000:
    a1com_1.jsuber = 129;
    goto L5000;
/* ...     ILLEGAL FORMAT */
/* ...     IF ERROR FLAG SET IN APTLOD, SIMPLY EXIT */
L4000:
    if (amotcm_1.jptind == 8) {
	goto L5000;
    }
    a1com_1.jsuber = 132;
/* L4010: */
    goto L5000;
/* ...     IMPROPER VOCABULARY CODE */
L4020:
    a1com_1.jsuber = 133;
    goto L5000;
/* ...     IMPROPER PUNCTUATION (NOT A COMMA) BETWEEN PARAMETERS */
L4030:
    a1com_1.jsuber = 7;
    goto L5000;
/* ...     MISSING SLASH */
L4040:
    a1com_1.jsuber = 155;
    goto L5000;

L4980:
    ipt[OTHER_ENDIAN_S(4)] = major;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
L4990:
    ipt[OTHER_ENDIAN_S(2)] = aptpp_1.npt;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
/* L4995: */
    --aptpp_1.inptp;
L4999:
    aptpp_1.jmode = 5;
    aptput_();
L5000:
L9999:
    return 0;
} /* amotin_ */

#undef ipt
#undef ivst


