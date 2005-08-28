/* AOBTAN.f -- translated by f2c (version 20000121).
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
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int aobtan_()
{
    /* System generated locals */
    integer i__1;
    static shortint equiv_3[2];

    /* Local variables */
    static integer iloc, idum;
#define ivst ((integer *)&avst_1)
#define lment ((integer *)&ailmtb_1)
#define itype (equiv_3 + 1)
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_();
    static integer jtemp1;
#define itype1 ((logical1 *)equiv_3)
    static integer nn, jx, icomma;
    extern /* Subroutine */ int aptlod_(), aprfix_();
#define ipunct (equiv_3)
    extern /* Subroutine */ int aptput_();
    static integer loc;
#define ipt ((integer *)&aptpp_1)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*       INTEGER ICOMMA/Z00000904/ */
/*     PROCESSES THE OBTAIN STATEMENT */
/*     OUTPUT- PTPP TABLE CLASS 9 DATA, 1 ENTRY FOR EACH PARAMETER */
/*     NN - POSITION OF PARAMETER IN CANONICAL FORM */
/*     NT - NO. OF 8-BYTE WORDS MINUS 1 FOR PTPP ENTRY */
    icomma=0x904;
    *itype = 0;
    *ipunct = 0;
    iloc = (abreak_1.inill + 2 << 2) - 3;
/* ...     WORD FOLLOWING OBTAIN MUST BE VOCABULARY, A SURFACE TYPE */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(iloc + 2)];
    if (*itype != 2) {
	goto L4;
    }
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(iloc + 1)];
    if (*itype == 24) {
	goto L6;
    }
L4:
    a1com_1.jsuber = 153;
    goto L999;
/* ...     SAVE SURFACE TYPE IN PT FOR RECORDS TO BE BUILT */
L6:
    jtemp1 = (abreak_1.inill << 1) - 1;
    ipt[OTHER_ENDIAN_S(16)] = lment[OTHER_ENDIAN_S(jtemp1 + 4)];

/* ...     SURFACE MUST BE EITHER A VARIABLE SYMBOL OR NESTED */
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(iloc + 10)];
    if (*itype == 1) {
	goto L10;
    }
    if (*itype == 6) {
	goto L10;
    }
/* ...     IT IS NOT */
    a1com_1.jsuber = 156;
    goto L999;

/* ...     IT IS - CONSTRUCT PTPP ENTRY FOR IT */
L10:
    aprtab_1.istarp = abreak_1.inill + 4;
    aptpp_1.inptp = 10;
    aptlod_();

/*     PARAMETER VARIABLE */
/* L70: */
    nn = 3;
/*     ALL PARAMETER DONE */
L80:
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L999;
    }
/*     NO */
/*     IS PARAMETER A COMMA */
    if (ailmtb_1.iclass[aprtab_1.istarp - 1] != icomma) {
	goto L100;
    }

/*     PARAMETER IS A COMMA */
    ++nn;
/* L90: */
    ++aprtab_1.istarp;
    goto L80;

/*     PARAMETER IS NO COMMA */
/*     PTPP ITEM  3 */
L100:
    ipt[OTHER_ENDIAN_S(17)] = nn;
/* ...     MAKE SURE PARAMETER IS A VARIABLE SYMBOL */
    iloc = (aprtab_1.istarp << 2) - 3;
    itype1[OTHER_ENDIAN_S(3)] = lclas1[OTHER_ENDIAN_W(iloc + 2)];
    if (*itype == 1) {
	goto L110;
    }
/*     PARAMETER NOT A VARIABLE SYMBOL */
    a1com_1.jsuber = 156;
    goto L999;

/* ...     PARAMETER IS A VARIABLE SYMBOL */
L110:
    loc = aprtab_1.istarp;
/* ...     CONSTRUCT PTPP ENTRY FOR SYMBOL */
    aptpp_1.inptp = 2;
    aptlod_();

    a1com_1.name__ = ailmtb_1.elment[loc - 1];
    avs1ck_(&jx);
    jtemp1 = (a1com_1.namsub << 1) - 1;
    switch ((int)jx) {
	case 1:  goto L111;
	case 2:  goto L111;
	case 3:  goto L112;
	case 4:  goto L111;
	case 5:  goto L115;
	case 6:  goto L114;
	case 7:  goto L111;
	case 8:  goto L115;
	case 9:  goto L111;
    }
L111:
    a1com_1.jsuber = 1002;
    a1com_1.sum = 1;
    goto L999;
/*     UPDATE VST */
L112:
    ++amxtab_1.maxscl;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 2;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = amxtab_1.maxscl;
L113:
    if (amxtab_1.maxscl <= amxtab_1.maxslr) {
	goto L115;
    }
/*     TOO MANY SCALAR VARIABLES */
    a1com_1.jsuber = 15;
    goto L999;
L114:
    aprfix_(&c__1, &idum);
/*     UPDATE MAXSCL */
    amxtab_1.maxscl += (i__1 = ivst[OTHER_ENDIAN_S(jtemp1 + 2)], abs(i__1));
    goto L113;

/* ...     MOVE SURFACE ENTRY TO PROPER POSITION IN PTPP */
L115:
    aptpp_1.pt[aptpp_1.inptp - 1] = aptpp_1.pt[8];
    aptpp_1.pt[aptpp_1.inptp] = aptpp_1.pt[9];
    aptpp_1.pt[aptpp_1.inptp + 1] = aptpp_1.pt[10];
    aptpp_1.pt[aptpp_1.inptp + 2] = aptpp_1.pt[11];
/*     PTPP ITEM  1 */
    aptpp_1.inptp += 2;
    if (ipt[OTHER_ENDIAN_S(19)] != 1) {
	goto L160;
    }
    ++aptpp_1.inptp;
L160:
    ipt[OTHER_ENDIAN_S(0)] = 9;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 1;
/* ...     PUT RECORD INTO PTPP */
    aptpp_1.jmode = 5;
    aptput_();
    goto L80;

/*     EXIT */
L999:
    return 0;
} /* aobtan_ */

#undef ipt
#undef ipunct
#undef itype1
#undef lclas1
#undef itype
#undef lment
#undef ivst


