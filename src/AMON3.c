/* AMON3.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

union {
    struct {
	doublereal elment[600];
	integer iclass[600], jlment;
    } _1;
    struct {
	doublereal eqv_pad[1800];
    } _2;
} ailmtb_;

#define ailmtb_1 (ailmtb_._1)
#define ailmtb_2 (ailmtb_._2)

static struct {
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

static struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

/* Subroutine */ int amon3_()
{
    /* Local variables */
#define ivst ((integer *)&avst_1)
//#define icls1 ((integer *)&ailmtb_1 + 1200)
#define icls1 ((logical1 *)&ailmtb_1 + 4800)
    static doublereal a;
    static integer j;
    extern /* Subroutine */ int avs1ck_(), aifun8_();
    static integer iat, isb;
	logical1 debugg;
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/*      LOGICAL*1 ICLS1(2400) */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */

/* L460: */
    if (ailmtb_1.jlment <= 2) {
	goto L600;
    }
debugg=icls1[OTHER_ENDIAN_W(7)];
    if (icls1[OTHER_ENDIAN_W(7)] != 4) {
	goto L600;
    }
/* L470: */
    if (icls1[OTHER_ENDIAN_W(6)] != 7) {
	goto L600;
    }
/* L480: */
    abreak_1.k = 3;
    iat = icls1[OTHER_ENDIAN_W(3)];
/* L490: */
    switch ((int)iat) {
	case 1:  goto L520;
	case 2:  goto L500;
	case 3:  goto L530;
	case 4:  goto L510;
    }
L500:
    a1com_1.jsuber = 17;
    goto L998;
L510:
    a1com_1.jsuber = 78;
    goto L998;
L520:
    a1com_1.name__ = ailmtb_1.elment[0];
    goto L540;
L530:
    a = ailmtb_1.elment[0];
    aifun8_(&a, &a1com_1.name__);

/* ...     SEE IF THERE ALREADY ARE ENTRIES IN VST FOR THIS SYMBOL */
L540:
    avs1ck_(&j);
    if (a1com_1.namsub == 0) {
	goto L570;
    }
/* ...     YES - SEE IF PREVIOUS USAGE WAS AS A STATEMENT LABEL */
    if (j == 3) {
	goto L560;
    }
    if (j == 4) {
	goto L560;
    }
/* ...     PREVIOUSLY DEFINED SYMBOL BEING USED AS STATEMENT ID */
    a1com_1.jsuber = 3;
    a1com_1.sum = 1;
    goto L998;
/* ...     YES - SEE IF PREVIOUS USAGE WAS WITHIN THIS LOOP OR MACRO */
L560:
    if (a1com_1.namsub < amcstf_1.idlocn) {
	goto L570;
    }
/* ...     DOUBLY-DEFINED STATEMENT ID */
    a1com_1.jsuber = 6;
    a1com_1.sum = 1;
    goto L998;

/* ...     ANY PREVIOUS USAGE NOT WITHIN THIS LOOP OR MACRO - PUT */
/* ...     ENTRY FOR THIS ID INTO VST */
/* ...     TEST FOR ROOM FOR IT */
L570:
    if (amxtab_1.maxvs1 + amxtab_1.maxvs2 + 2 <= amxtab_1.maxvst) {
	goto L575;
    }
/* ...     VST FULL - NO ROOM FOR THIS ENTRY - ERROR */
    a1com_1.jsuber = 15;
    a1com_1.sum = 1;
    goto L998;

L575:
    amxtab_1.maxvs1 += 2;
    avst_1.vst[amxtab_1.maxvs1 - 1] = a1com_1.name__;

    a1com_1.namsub = amxtab_1.maxvs1;
/* ... */
/* L580: */
    isb = (a1com_1.namsub + 1 << 1) - 1;
    ivst[OTHER_ENDIAN_S(isb - 1)] = 8;
    ivst[OTHER_ENDIAN_S(isb)] = 0;
    a1com_1.jsuber = 0;
    ++amcstf_1.numids;
    if (abreak_1.nwonrd <= 0) {
	goto L998;
    }
/* L590: */
    a1com_1.jsuber = 201;
    a1com_1.sum = 1;
    goto L998;
L600:
    abreak_1.k = 1;
L998:
    return 0;
} /* amon3_ */

#undef icls1
#undef ivst


