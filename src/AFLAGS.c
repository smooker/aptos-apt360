/* AFLAGS.f -- translated by f2c (version 20000121).
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
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

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

static integer c__11 = 11;

/* Subroutine */ int aflags_()
{
    /* Initialized data */

    static integer islash = 0x304;
    static struct {
	shortint e_1[2];
	} equiv_4 = { 0, 0 };


    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
#define gcl ((logical1 *)&equiv_4)
#define kcl ((shortint *)&equiv_4 )
#define ksc ((shortint *)&equiv_4 + 1)
#define ipt ((integer *)&aptpp_1)
    static integer item5, major;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    static integer jtemp1, jtemp2, jtemp3;
    static doublereal xitem4;
    extern /* Subroutine */ int aswich_(), aptlod_();
#define klment ((shortint *)&ailmtb_1)
    static integer isubst;
    extern /* Subroutine */ int aptput_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER ISLASH/Z00000304/ */
/*       INTEGER*2 KLMENT(2400),KCL/0/,KSC/0/ */
/* 	DATA ISLASH/Z00000304/ */

/* ...     JTEMP3 IS A NUMBER COUNTER */



/* L10: */
    jtemp3 = 0;
    ipt[OTHER_ENDIAN_S(0)] = 6;
    aptpp_1.inptp = 4;
    aptpp_1.npt = 0;
    aptpp_1.jmode = 5;
/* ...     PICK UP A PTPP ENTRY AND EVALUATE */
/* L20: */
    aptlod_();
/* ...     RESET PTPP STORING INDEX TO START */
    aptpp_1.inptp = 4;
/* ...     0=MINOR MODIFIER, 1=VOCABULARY, */
/* ...     2=NUMBER, 3=SCALAR VARIABLE, 4=SURFACE, 5=STATEMENT I.D. */
/* ...     6=UNDEFINED(MAY BE I.D.), 7=SUBSCRIPTED VARIABLE, 8=ERROR */
    if (amotcm_1.jptind != 1) {
	goto L4020;
    }
/* ...     CONVERT VOCABULARY CODE FOR BRANCHING */
/* L70: */
    jtemp1 = amotcm_1.kreslt / 1000;
    major = amotcm_1.kreslt;
    isubst = amotcm_1.krslt2;
    ipt[OTHER_ENDIAN_S(4)] = amotcm_1.kreslt;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
/* ...     TEST BRANCH SWITCH RANGE */
    if (jtemp1 == 9) {
	goto L1560;
    }
    if (jtemp1 != 6) {
	goto L4020;
    }

/* ...     6000 CODE FOUND */

/* L780: */
    jtemp1 = (aprtab_1.istarp << 2) - 3;
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 - 3)];
    gcl[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(jtemp1 - 4)];
    if (isubst > 2) {
	goto L900;
    }
/* ...     TEST FOR DEBUG OR DYNDMP */
    if (*kcl != 15) {
	goto L785;
    }
/* ...     YES - IS IT DYNDMP */
    if (*ksc == 2) {
	goto L900;
    }
/* ...     TEST FOR TOLERANCE OR CUTTER */
L785:
    if (*kcl == 2) {
	goto L900;
    }
/* ...     TEST FOR BEVELS */
    if (*ksc == 10) {
	goto L900;
    }

/* ...    CUT,  DNTCUT,  2DCALC,  3DCALC,  NDTEST FOUND */
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
/* ...     TEST FOR DNTCUT */
    if (*ksc != 2) {
	goto L788;
    }
/* ...     YES - IF IT HAS A PARAMETER, MUST BE 'PRINT' */
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L786;
    } else if (i__1 == 0) {
	goto L4000;
    } else {
	goto L800;
    }
/* ...     TEST FOR SLASH */
L786:
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
    gcl[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(jtemp1 + 6)];
    if (*kcl != 2) {
	goto L3000;
    }
    if (klment[OTHER_ENDIAN_S(jtemp1 + 6)] != 0) {
	goto L3000;
    }
    if (klment[OTHER_ENDIAN_S(jtemp1 + 4)] != 3) {
	goto L3000;
    }
    if (aprtab_1.istarp + 1 - ailmtb_1.jlment != 0) {
	goto L4000;
    } else {
	goto L810;
    }

/* ...     TEST FOR CUT */
L788:
    if (*ksc == 1) {
	goto L790;
    }
/* ...     NO - TRY 2DCALC */
    if (*ksc == 8) {
	goto L790;
    }
/* ...     ...3DCALC */
    if (*ksc == 9) {
	goto L800;
    }
/* ...     MUST BE NDTEST */
    if (*ksc == 6) {
	goto L810;
    }
    goto L4020;
/* ...     CUT OR 2DCALC */
L790:
    aptpp_1.pt[4] = (float)0.;
    goto L820;
/* ...     DNTCUT OR 3DCALC */
L800:
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = 1;
    goto L820;
/* ...     NDTEST OR DNTCUT/PRINT */
L810:
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = 2;
L820:
    aptpp_1.inptp = 6;
    aptpp_1.npt = 1;
    goto L4980;

/* ...     TOLERANCE, CUTTER, DYNDMP, DMILL, OR BEVELS */
L900:
    aptpp_1.inptp = 4;
    aptpp_1.npt = 0;
    if (aprtab_1.istarp >= ailmtb_1.jlment) {
	goto L4000;
    }
/* ...     TEST FOR SLASH - IF FOUND, MOVE SCAN INDEX PAST IT */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
    ++aprtab_1.istarp;
/* ...     SET FLAG TO SKIP COMMAS IN APTLOD */
    aprtab_1.itsq = 4;
    aptlod_();
/* ...     TEST FOR VOCABULARY WORD */
    if (amotcm_1.jptind != 0) {
	goto L915;
    }
/* ...     YES - TEST FOR CUTTER STATEMENT - MAY START WITH 'OPTION' */
    if (isubst == 6) {
	goto L1200;
    }
/* ...     NO - IF NOT BEVELS OR DMILL, ERROR */
    if (*ksc - 10 != 0) {
	goto L4000;
    } else {
	goto L1120;
    }

L910:
    aptlod_();
L915:
    if (amotcm_1.jptind == 2) {
	goto L920;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L920:
    ++aptpp_1.npt;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L910;
    }
    if (*kcl != 15) {
	goto L925;
    }
    if (*ksc == 2) {
	goto L1320;
    }
L925:
    if ((i__1 = isubst - 6) < 0) {
	goto L930;
    } else if (i__1 == 0) {
	goto L1000;
    } else {
	goto L4980;
    }

/* ...     TOLERANCE STATEMENT */
L930:
    if (aptpp_1.npt > 4) {
	a1com_1.jsuber = 129;
    }
    if (aptpp_1.npt >= 4) {
	goto L950;
    }
    jtemp2 = aptpp_1.inptp - amotcm_1.now;
    for (i__ = aptpp_1.npt; i__ <= 3; ++i__) {
	aptpp_1.pt[aptpp_1.inptp - 1] = aptpp_1.pt[amotcm_1.now - 1];
	aptpp_1.pt[aptpp_1.inptp] = aptpp_1.pt[amotcm_1.now];
	if (jtemp2 == 2) {
	    goto L940;
	}
	aptpp_1.pt[aptpp_1.inptp + 1] = aptpp_1.pt[amotcm_1.now + 1];
L940:
	aptpp_1.inptp += jtemp2;
    }
L950:
    aptpp_1.npt = 4;
/* ...     TEST FOR INTOL OR OUTTOL STATEMENT */
    if (isubst == 4) {
	goto L4980;
    }
    if (isubst == 5) {
	goto L4980;
    }
/* ...     NO - IF NOT TOLER, SOMETHING WRONG */
    if (isubst != 2) {
	goto L4020;
    }

/* ...     TOLER STATEMENT */
/* ...     OUTPUT OUTTOL */
/* L960: */
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
    ipt[OTHER_ENDIAN_S(2)] = 4;
    ipt[OTHER_ENDIAN_S(3)] = 0;
    ipt[OTHER_ENDIAN_S(4)] = 6000;
    ipt[OTHER_ENDIAN_S(5)] = 5;
    --aptpp_1.inptp;
    aptput_();
/* ...     OUTPUT INTOL ZERO */
    ipt[OTHER_ENDIAN_S(5)] = 4;
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    aptpp_1.pt[4] = (float)0.;
    for (i__ = 3; i__ <= 7; i__ += 2) {
	aptpp_1.pt[i__ + 2] = aptpp_1.pt[i__];
/* L970: */
	aptpp_1.pt[i__ + 3] = aptpp_1.pt[i__ + 1];
    }
    aptpp_1.inptp = 12;
    goto L4994;

/* ...     CUTTER STATEMENT */
L1000:
    if (aptpp_1.npt <= 0) {
	goto L1100;
    }
    if (aptpp_1.npt == 1) {
	goto L4980;
    }
    if (aptpp_1.npt == 2) {
	goto L4980;
    }
    if (aptpp_1.npt == 7) {
	goto L4980;
    }
L1100:
    a1com_1.jsuber = 129;
    goto L4980;

/* ...     BEVELS OR DMILL STATEMENT... */
/* ...     MAKE SURE STATEMENT ONLY CONTAINS THE ONE PARAMETER */
L1120:
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L4000;
    }
    aptpp_1.npt = 1;
/* ...     TEST FOR DMILL */
    if (isubst == 11) {
	goto L1130;
    }
/* ...     NO - BEVELS - MODIFIER CAN ONLY BE 'OFF' OR 'ON' */
    if (amotcm_1.kreslt == 71) {
	goto L4980;
    }
    if (amotcm_1.kreslt - 72 != 0) {
	goto L4020;
    } else {
	goto L4980;
    }

/* ...     IT IS DMILL - MODIFIER MUST BE 'DSTAN', 'PSTAN', OR 'NOMORE' */
L1130:
    if (amotcm_1.kreslt == 27 || amotcm_1.kreslt == 146) {
	goto L4980;
    }
    if (amotcm_1.kreslt - 53 != 0) {
	goto L4020;
    } else {
	goto L4980;
    }

/* ...     CUTTER/OPTION */
L1200:
    if (amotcm_1.kreslt != 144) {
	goto L4020;
    }
/* L1210: */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L3000;
    }
    aptpp_1.inptp = 4;
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1220;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L1220:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L3000;
    }
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1250;
    }
    if (amotcm_1.jptind == 3) {
	goto L1250;
    }
    if (amotcm_1.jptind != 0) {
	goto L4000;
    }
/* L1230: */
    aptpp_1.pt[amotcm_1.now - 2] = (float)3.;
    jtemp1 = (amotcm_1.now << 1) - 1;
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 1;
    ipt[OTHER_ENDIAN_S(jtemp1)] = 0;
    aptpp_1.pt[amotcm_1.now + 1] = aptpp_1.pt[amotcm_1.now - 1];
    aptpp_1.pt[amotcm_1.now] = (float)0.;
    aptpp_1.pt[amotcm_1.now + 2] = (float)0.;
    aptpp_1.inptp = amotcm_1.now + 4;
    aptpp_1.npt = 3;
    goto L4980;

L1250:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L3000;
    }
    aptlod_();
    aptpp_1.npt = 3;
    if (amotcm_1.jptind == 2) {
	goto L4980;
    }
    if (amotcm_1.jptind - 3 != 0) {
	goto L4000;
    } else {
	goto L4980;
    }

/* ...     DYNDMP */
L1320:
    if (aptpp_1.npt < 2) {
	goto L3000;
    }
    if (aptpp_1.npt > 24) {
	goto L3000;
    }
    if (aptpp_1.npt / 2 << 1 != aptpp_1.npt) {
	goto L3000;
    }
    goto L4980;
/* ... */
/* ...     9000 CODE FOUND */
/* ... */
L1560:
    if (isubst < 1) {
	goto L4020;
    }
    if (isubst > 8) {
	goto L4020;
    }
    switch ((int)isubst) {
	case 1:  goto L1591;
	case 2:  goto L1575;
	case 3:  goto L1580;
	case 4:  goto L1580;
	case 5:  goto L1580;
	case 6:  goto L1570;
	case 7:  goto L1570;
	case 8:  goto L1572;
    }

/* ...     NOPS OR AUTOPS */
L1570:
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	a1com_1.jsuber = 129;
    }
    goto L4980;

/* ...     GOUGCK */
L1572:
    if (aprtab_1.istarp >= ailmtb_1.jlment) {
	goto L3000;
    }
    goto L1576;

/* ...     MULTAX */
L1575:
    if (amotcm_1.multax == 1) {
	goto L9999;
    }
L1576:
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    ipt[OTHER_ENDIAN_S(8)] = 0;
    ipt[OTHER_ENDIAN_S(9)] = 1;
    aptpp_1.inptp = 6;
    aptpp_1.npt = 1;
/* ...     IF GOUGCK, SKIP TEST FOR MULTAX WITH NO PARAMETERS */
    if (isubst == 8) {
	goto L1578;
    }
    if ((i__1 = aprtab_1.istarp - ailmtb_1.jlment) < 0) {
	goto L1578;
    } else if (i__1 == 0) {
	goto L4000;
    } else {
	goto L1577;
    }
L1577:
    amotcm_1.multax = 1;
    goto L1600;
/* ...     TEST FOR SLASH - IF FOUND, MOVE SCAN INDEX PAST IT */
L1578:
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
    ++aprtab_1.istarp;
/* ...     SET FLAG TO SKIP COMMAS IN APTLOD */
    aprtab_1.itsq = 4;
    aptlod_();
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L4000;
    }
/* ...     MUST BE VOCABULARY */
    if (amotcm_1.jptind == 0) {
	goto L1579;
    }
    if (amotcm_1.jptind - 8 != 0) {
	goto L3000;
    } else {
	goto L5000;
    }
/* ...     TEST FOR 'ON' */
L1579:
    if (amotcm_1.kreslt == 71) {
	goto L1600;
    }
    aptpp_1.pt[4] = (float)0.;
/* ...     WAS NOT 'ON' - IF NOT 'OFF', ERROR */
    if (amotcm_1.kreslt == 72) {
	goto L1600;
    }
    goto L4000;

/* ...     MAXDP, NUMPTS, OR THICK */
L1580:
    if (aprtab_1.istarp >= ailmtb_1.jlment) {
	goto L3000;
    }
/* ...     TEST FOR SLASH - IF FOUND, MOVE SCAN INDEX PAST IT */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
    ++aprtab_1.istarp;
/* ...     SET FLAG TO SKIP COMMAS IN APTLOD */
    aprtab_1.itsq = 4;
L1582:
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1585;
    }
    if (amotcm_1.jptind == 3) {
	goto L1585;
    }
    if (amotcm_1.jptind == 8) {
	goto L1585;
    }
    a1com_1.jsuber = 132;
L1585:
    ++aptpp_1.npt;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1582;
    }
    if (isubst == 5) {
	goto L1587;
    }

/* ...     MAXDP, OR NUMPTS */
    if (aptpp_1.npt == 1) {
	goto L4980;
    }
    a1com_1.jsuber = 129;
    aptpp_1.npt = 1;
    aptpp_1.inptp = 6;
    goto L1600;

/* ...  THICK/THPS,THDS,THCS1,THCS2 */
L1587:
    if (aptpp_1.npt > 4) {
	a1com_1.jsuber = 129;
    }
    if (aptpp_1.npt >= 4) {
	goto L1600;
    }
/* ...     FILL UP PARAMETERS */
    jtemp1 = aptpp_1.inptp - 1;
    for (i__ = aptpp_1.npt; i__ <= 4; ++i__) {
	i__1 = jtemp1;
	for (j = amotcm_1.now; j <= i__1; ++j) {
	    aptpp_1.pt[aptpp_1.inptp - 1] = aptpp_1.pt[j - 1];
/* L1588: */
	    ++aptpp_1.inptp;
	}
/* L1590: */
    }
    aptpp_1.npt = 4;
    goto L1600;

/* ...     TLAXIS */
L1591:
    if (aprtab_1.istarp >= ailmtb_1.jlment) {
	goto L4020;
    }
/* ...     TEST FOR SLASH - IF FOUND, MOVE SCAN INDEX PAST IT */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != islash) {
	goto L4040;
    }
    ++aprtab_1.istarp;
/* ...     SET FLAG TO SKIP COMMAS IN APTLOD */
    aprtab_1.itsq = 4;
    aptpp_1.npt = 1;
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind == 0) {
	goto L1595;
    }
    if (amotcm_1.jptind == 4) {
	goto L1592;
    }
    if (amotcm_1.jptind == 2) {
	goto L1593;
    }
    if (amotcm_1.jptind == 3) {
	goto L1593;
    }
    goto L4000;

/* ...     TLAXIS/VECT */
L1592:
    xitem4 = (float)1.;
    aswich_(&c__11);
    aptpp_1.npt = 2;
    goto L1599;

/* ...     TLAXIS/X,Y,Z */
L1593:
    xitem4 = (float)1.;

/* ...     CHECK FOR TLAXIS/1 */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L15945;
    }
/* ...     MOVE FIRST SCALAR UP TO MAKE ROOM FOR ZEROED NAME, SUBSCRIPT */
    jtemp1 = aptpp_1.inptp - 1;
    aptpp_1.inptp = 10;
    i__1 = jtemp1;
    for (j = amotcm_1.now; j <= i__1; ++j) {
	aptpp_1.pt[aptpp_1.inptp - 1] = aptpp_1.pt[j - 1];
/* L15931: */
	++aptpp_1.inptp;
    }
    ipt[OTHER_ENDIAN_S(10)] = 1;
    ipt[OTHER_ENDIAN_S(11)] = 0;
    aptpp_1.pt[6] = (float)0.;
    aptpp_1.pt[7] = aptpp_1.pt[5];
    aptpp_1.pt[8] = (float)0.;
    jtemp3 = 1;
L1594:
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L15941;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L15941:
    ++jtemp3;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1594;
    }
    aptpp_1.npt = 6;
    if (jtemp3 - 3 != 0) {
	goto L3000;
    } else {
	goto L1599;
    }

/* ...     TLAXIS/1 */
L15945:
    if (aptpp_1.pt[aptpp_1.inptp - 2] != (float)1.) {
	a1com_1.jsuber = 132;
    }
    xitem4 = (float)5.;
    aptpp_1.inptp = 6;
    goto L1599;

/* ...     TLAXIS/VOCABULARY */
L1595:
    xitem4 = (float)2.;
/* ...     TEST FOR NORMPS */
    item5 = 1;
    if (amotcm_1.kreslt != 4000) {
	goto L15951;
    }
    if (amotcm_1.krslt2 - 32767 != 0) {
	goto L4000;
    } else {
	goto L15952;
    }
/* ...     NOT NORMPS - TRY NORMDS */
L15951:
    item5 = 2;
    if (amotcm_1.kreslt != 87) {
	goto L15953;
    }
/* ...     NORMPS OR NORMDS - TEST FOR FURTHER PARAMETERS */
L15952:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L1596;
    }
    xitem4 = (float)9.;
    goto L1597;
/* ...     SEE IF MODIFIER IS PERPTO */
L15953:
    xitem4 = (float)8.;
    if (amotcm_1.kreslt == 18) {
	goto L1597;
    }
    xitem4 = (float)4.;
    if (amotcm_1.kreslt == 17) {
	goto L1597;
    }
    xitem4 = (float)3.;
    if (amotcm_1.kreslt == 1) {
	goto L1602;
    }
    item5 = 3;
/* ...     TRY TANDS (TLAXIS/TANDS) */
    xitem4 = (float)6.;
    if (amotcm_1.kreslt == 183) {
	goto L15954;
    }
/* ...     IF NOT FAN (TLAXIS/FAN), ERROR */
    xitem4 = (float)7.;
    if (amotcm_1.kreslt != 184) {
	goto L4020;
    }
/* ...     TEST FOR ANOTHER PARAMETER FOLLOWING TANDS OR FAN */
L15954:
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1597;
    }

/* ...     TLAXIS/NORMPS, NORMDS, TANDS, OR FAN */
L1596:
    ipt[OTHER_ENDIAN_S(10)] = 1;
    ipt[OTHER_ENDIAN_S(11)] = 0;
    ipt[OTHER_ENDIAN_S(12)] = 0;
    ipt[OTHER_ENDIAN_S(13)] = item5;
    aptpp_1.inptp = 8;
    aptpp_1.npt = 2;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	a1com_1.jsuber = 129;
    }
    goto L1599;

/* ...     TLAXIS/MODIFIER,LIST */
L1597:
    aptpp_1.inptp = 6;
    aptlod_();
    aptpp_1.npt = 2;
    if (xitem4 < (float)8.) {
	goto L1598;
    }
/* ...     TLAXIS/PERPTO, NORMPS, OR MORMDS, VECTOR... */
/* ...     TEST FOR SURFACE - IF NOT, ERROR */
    if (amotcm_1.jptind != 4) {
	goto L4000;
    }
/* ...     PUT VECTOR TYPE CODE INTO ENTRY */
    aswich_(&c__11);
/* ...     TEST FOR MORE DATA */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L1599;
    }
    aptlod_();
    aptpp_1.npt = 3;

/* ...     PARAMETER MUST BE A SCALAR */
L1598:
    if (amotcm_1.jptind == 2) {
	goto L1599;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }

L1599:
    ipt[OTHER_ENDIAN_S(6)] = 1;
    ipt[OTHER_ENDIAN_S(7)] = 0;
    aptpp_1.pt[4] = xitem4;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	a1com_1.jsuber = 129;
    }
/* ...     RETURN */
L1600:
    goto L4980;

/* ...     TLAXIS/ATANGL */
L1602:
    aptpp_1.inptp = 6;
    aptlod_();
    if (amotcm_1.jptind == 3) {
	goto L1603;
    }
    if (aptpp_1.pt[aptpp_1.inptp - 2] > (float)2.) {
	a1com_1.jsuber = 132;
    }
    if (aptpp_1.pt[aptpp_1.inptp - 2] < (float)1.) {
	a1com_1.jsuber = 132;
    }
    if (amotcm_1.jptind != 2) {
	goto L4000;
    }
L1603:
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L16031;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L16031:
    aptpp_1.npt = 3;
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L1599;
    }
    aptlod_();
    if (amotcm_1.jptind == 4) {
	goto L1610;
    }
    if (amotcm_1.jptind == 2) {
	goto L1620;
    }
    if (amotcm_1.jptind == 3) {
	goto L1620;
    }
    if (amotcm_1.jptind != 0) {
	goto L4000;
    }
/* L1604: */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L4000;
    }
/* L1605: */
    aptpp_1.inptp = amotcm_1.now;
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1607;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L1607:
    aptpp_1.npt = 4;
    goto L1599;

L1610:
    aswich_(&c__11);
    aptpp_1.npt = 4;
    goto L1599;

L1620:
    i__1 = aptpp_1.inptp;
    for (j = amotcm_1.now; j <= i__1; ++j) {
/* L1621: */
	aptpp_1.pt[j + 3] = aptpp_1.pt[j - 1];
    }
    aptpp_1.inptp += 4;
    jtemp1 = (amotcm_1.now << 1) - 1;
    ipt[OTHER_ENDIAN_S(jtemp1 - 1)] = 1;
    ipt[OTHER_ENDIAN_S(jtemp1)] = 0;
    aptpp_1.pt[amotcm_1.now] = (float)0.;
    aptpp_1.pt[amotcm_1.now + 1] = aptpp_1.pt[amotcm_1.now - 1];
    aptpp_1.pt[amotcm_1.now + 2] = (float)0.;
    jtemp3 = 1;
    aptpp_1.npt = 8;
L1622:
    aptlod_();
    if (amotcm_1.jptind == 2) {
	goto L1625;
    }
    if (amotcm_1.jptind != 3) {
	goto L4000;
    }
L1625:
    ++jtemp3;
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L1622;
    }
    if (jtemp3 - 3 != 0) {
	goto L3000;
    } else {
	goto L1599;
    }

/* ...     ERROR MESSAGES */
L3000:
    a1com_1.jsuber = 129;
    goto L5000;
/* ...     ILLEGAL FORMAT */
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
/* L4030: */
    goto L5000;
/* ...     MISSING SLASH */
L4040:
    a1com_1.jsuber = 155;
    goto L5000;

L4980:
    ipt[OTHER_ENDIAN_S(4)] = major;
    ipt[OTHER_ENDIAN_S(5)] = isubst;
/* L4990: */
    ipt[OTHER_ENDIAN_S(2)] = aptpp_1.npt;
    ipt[OTHER_ENDIAN_S(3)] = 0;
L4994:
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 2;
/* L4995: */
    --aptpp_1.inptp;
/* L4999: */
    aptpp_1.jmode = 5;
    aptput_();
L5000:
L9999:
    return 0;
} /* aflags_ */

#undef klment
#undef lclas1
#undef ipt
#undef ksc
#undef kcl
#undef gcl


