/* AMON2.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include "assert.h"

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

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

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

static struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

/* Subroutine */ int amon2_()
{
    /* Initialized data */

    static struct {
	shortint e_1;
	} equiv_1 = { 0 };

    static struct {
	shortint e_1[4];
	integer e_2;
	} equiv_3 = { 0, 0x704, 1, 0xb02, 0 };


    /* Local variables */
#define ivst ((integer *)&avst_1)
    static doublereal a;
#define i2vst ((shortint *)&avst_1)
    static integer j;
#define lclas1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int avs1ck_(), aifun8_();
    static shortint is;
#define loopcd ((integer *)&equiv_3 + 1)
#define irpren ((integer *)&equiv_3)
#define krpren ((shortint *)&equiv_3)
#define gat ((logical1 *)&equiv_1)
#define iat ((shortint *)&equiv_1)
    static shortint isb;
    static integer ndx;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*       INTEGER*2 KRPREN(4)/0,Z0704,1,Z0B02/,IAT/0/ */
/*     THIS ROUTINE DETECTS AND STORES STATEMENT IDS */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
/* ..                                                                  D39 */
/* ...                                                                 D39 */
/* L320: */
    gat[OTHER_ENDIAN_S(1)] = lclas1[OTHER_ENDIAN_W(3)];
    if (*iat != 4) {
	goto L340;
    }
/* ...  STATEMENT CANNOT BEGIN WITH PUNCTUATION */
L330:
    a1com_1.jsuber = 5;
    goto L998;
/* ... */
L340:
    if (ailmtb_1.jlment <= 2) {
	goto L450;
    }
    if (ailmtb_1.iclass[1] !=SWTCH_ENDIAN_INT_SHRT(*irpren)) {
	goto L450;
    }
/* ...  SECOND ENTRY IS A ), MUST BE AN ID */
//	assert(0);//verify loopcd works endian wise
    if (ailmtb_1.iclass[2] !=SWTCH_ENDIAN_INT_SHRT(*loopcd)) {
	goto L355;
    }
    if (a1com_1.loop != 0) {
	goto L355;
    }
    abreak_1.k = 3;
    goto L998;
/* ... */
L355:
    switch ((int)*iat) {
	case 1:  goto L400;
	case 2:  goto L370;
	case 3:  goto L390;
	case 4:  goto L330;
    }
/* ... */
/* ...  VOCAB. WORD ILLEGAL HERE */
L370:
    a1com_1.jsuber = 17;
    goto L998;
/* ... */
/* ...  FLOATING PT. NO. - STORE AS PURE NUMERIC ID */
L390:
    a = ailmtb_1.elment[0];
    aifun8_(&a, &a1com_1.name__);
    ailmtb_1.elment[0] = a1com_1.name__;
    ailmtb_1.iclass[0] = 1;
    goto L410;
/* ... */
/* ...  VARIABLE SYMBOL WHICH IS AN ID */
L400:
    a1com_1.name__ = ailmtb_1.elment[0];

/* ...     SYMBOL IS AN ID - SEE IF THERE ALREADY ARE ENTRIES */
/* ...     IN VST FOR IT */
L410:
    avs1ck_(&j);
    if (j > 4) {
	goto L425;
    }
    switch ((int)j) {
	case 1:  goto L415;
	case 2:  goto L425;
	case 3:  goto L440;
	case 4:  goto L430;
    }
/* .. */
/* ..   ENTER NAME INTO  VST */
L415:
    amxtab_1.maxvs1 += 2;
    if (amxtab_1.maxvs1 >= amxtab_1.maxvst) {
	goto L420;
    }
    avst_1.vst[amxtab_1.maxvs1 - 1] = a1com_1.name__;
    a1com_1.namsub = amxtab_1.maxvs1;
    goto L440;
/* ..                                                                  D39 */
/* ...     VST FULL - ENTRY COULD NOT BE MADE - ERROR */
L420:
    a1com_1.jsuber = 15;
    a1com_1.sum = 1;
    goto L998;
L425:
    a1com_1.jsuber = 3;
    a1com_1.sum = 1;
    goto L998;
/* ..                                                                  D39 */
/* ..   DUPLICATE STMT I.D.                                            D39 */
L430:
    if (a1com_1.namsub < amcstf_1.idlocn) {
	goto L415;
    }
    is = (shortint) (a1com_1.namsub + 1 << 1);
    a1com_1.jsuber = 6;
    ivst[OTHER_ENDIAN_S(is - 1)] = 0;
    a1com_1.sum = 1;
    asistm_1.iwaven = abreak_1.isn;
/* ..   DUPLICATE STMT I.D. - FLUSH PASS 2 PROCESSING  IWAVEN.NE.0     D39 */
    goto L445;
/* ... */

/* ...  SET VST STATUS FOR CROSS - REFERENCED ONLY */
L440:
    ndx = a1com_1.indxpt - amxtab_1.maxvst;
    is = (shortint) ((a1com_1.namsub + 1 << 1) - 1);
    isb = (shortint) ((is + 1 << 1) - 1);
    ivst[OTHER_ENDIAN_S(is - 1)] = 3;
    i2vst[OTHER_ENDIAN_W(isb - 1)] = (shortint) (aptpp_1.irecn + 1);
    i2vst[OTHER_ENDIAN_W(isb)] = (shortint) ndx;
/* ... */
L445:
    aklas7_1.idis = a1com_1.name__;
    abreak_1.k = 3;
    aklas7_1.idvst = a1com_1.namsub;
/* ...  ID FOUND - GO HOME */
    goto L998;
/* ... */
/* ...  STORE ID DATA FOR CLASS SEVEN PTPP DATA */
L450:
    aklas7_1.idis = 0.;
    aklas7_1.idvst = 0;
    abreak_1.k = 1;
L998:
    return 0;
} /* amon2_ */

#undef iat
#undef gat
#undef krpren
#undef irpren
#undef loopcd
#undef lclas1
#undef i2vst
#undef ivst


