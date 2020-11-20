/* ALSFPT.f -- translated by f2c (version 20000121).
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
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__6 = 6;
static integer c__1 = 1;

/* Subroutine */ int alsfpt_()
{
    /* Local variables */
    static integer m, n;
    static doublereal sub;
    static integer iret;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
    extern /* Subroutine */ int aserch_();
#define idfsto ((integer *)&adfsto_1)
    extern /* Subroutine */ int atapwt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*     THIS ROUTINE IS USED TO WRITE A LARGE SURFACE DEFINITION IN THE */
/*     SRFTAP FILE. */
/*     THE INPUT TO THE PROGRAM IS THE DEFSTO AND DEFTAB TABLES, AND THE */
/*     RECORD NO. IN LGEREC */

/*     POSITION THE FILE */
    ++a1pas2_1.lgerec;
    aserch_(&ataptb_1.srftap, &a1pas2_1.lgerec, &iret);
/*     WAS THERE AN ERROR */
    if (iret >= 0) {
	goto L10;
    }

/*     THERE WAS NO ERROR, FILE IS PROPERLY POSITIONED. GET SUBSCRIPT. */
    sub = (doublereal) idfsto[OTHER_ENDIAN_S(5)];
/*     GET NO. WORDS IN CANONICAL FORM. ADD 2 FOR CORRECT SRFTAP COUNT. */
    n = idftab[OTHER_ENDIAN_S(1)] - 1;
    m = n + 2;
/*     GET SURFACE TYPE */
    a1pas2_1.k = idfsto[OTHER_ENDIAN_S(0)];

/* ...     WRITE SRFTAP RECORD */
    atapwt_(&ataptb_1.srftap, &iret, &c__6, &a1pas2_1.lgerec, &c__1, &
	    a1pas2_1.k, &c__1, &m, &c__1, &a2cls7_1.einame, &c__1, &sub, &
	    c__1, &deftab[1], &n);
/* ...     TEST FOR AN ERROR IN WRITING THE RECORD */
    if (iret >= 0) {
	goto L20;
    } else {
	goto L25;
    }

/*  10 THERE WAS AN ERROR IN SEARCHING THE FILE. */
L10:
    a1com_1.jsuber = 73;
    --a1pas2_1.lgerec;
    goto L30;
/*  20 THERE WAS AN ERROR IN WRITING THEFILE. */
L20:
    a1com_1.jsuber = 74;
    --a1pas2_1.lgerec;
    goto L30;

/*     SET RECORD NO. AND LENGTH OF CANONICAL FORM */
L25:
    idfsto[OTHER_ENDIAN_S(6)] = 0;
    idfsto[OTHER_ENDIAN_S(7)] = a1pas2_1.lgerec;
    idfsto[OTHER_ENDIAN_S(8)] = 0;
    idfsto[OTHER_ENDIAN_S(9)] = n;

L30:
    return 0;
} /* alsfpt_ */

#undef idfsto
#undef idftab
#undef deftab


