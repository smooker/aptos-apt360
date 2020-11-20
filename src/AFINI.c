/* AFINI.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

static struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

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
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

static struct {
    doublereal alib[126], segnam, dum1;
    integer irdmod, ia1[3];
} alibry_;

#define alibry_1 alibry_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, mx[8];
} amxtab_;

#define amxtab_1 amxtab_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Table of constant values */

static integer c__1 = 1;
static integer c__10 = 10;
static integer c__2 = 2;

/* Subroutine */ int afini_()
{
    /* Builtin functions */
    /* Subroutine */ int s_stop();

    /* Local variables */
    static integer ic;
    static shortint ibr;
#define ipt ((integer *)&aptpp_1)
#define icls1 ((logical1 *)&ailmtb_1 + 4800)
    extern /* Subroutine */ int amon2_(), aclas7_(), adiagp_(), apread_();
    static integer ioflag;
#define errtap ((doublereal *)&ataptb_1 + 9)
#define ptptap ((doublereal *)&ataptb_1 + 3)
    extern /* Subroutine */ int atapop_(), aptput_(), ascntl_();

/* .. */
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* .. */
/* .. */
/* .. */
/* ...     TEST FOR TERMINATION OF A PROGRAM WITHOUT A FINI */
    if (a1com_1.jsuber == 23) {
	goto L520;
    }

/* .. OUTPUT THE CLASS 7 FOR THE FINI */
    aklas7_1.kfk = 2;
    aclas7_();
/* . */
/* .. PROCESS THE STATEMENT I.D. IF ANY */
    amon2_();
    if (a1com_1.jsuber == 0) {
	goto L100;
    }
    ibr = 1;
    goto L600;
/* . */
/* .. PROCESSING A MACRO IS ILLEGAL */
L100:
    if (amcstf_1.macrd == 0) {
	goto L200;
    }
    a1com_1.jsuber = 1600;
    ibr = 2;
    goto L600;
/* .. */
/* .. EXEC A LOOP IS ILLEGAL TOO */
L200:
    if (abreak_1.nwonrd == 0) {
	goto L300;
    }
    a1com_1.jsuber = 1601;
    ibr = 2;
    goto L600;
/* .. */
/* ..  ONLY NORMAL PROCESSING MODE IS ACCEPTABLE */
L300:
    if (a1com_1.loop == 0) {
	goto L400;
    }
    a1com_1.jsuber = 6102;
    ibr = 2;
    goto L600;
/* .. */
/* ..  FINI MUST BE BY ITSELF OR WITH A STMT.I.D., ONLY */
L400:
    if (ailmtb_1.jlment == 1) {
	goto L700;
    }
    if (ailmtb_1.jlment != 3) {
	goto L510;
    }
/*      IF(ICLS1(7).NE.7) GOTO 510 */
    if (ailmtb_1.iclass[6] != 7) {
	goto L510;
    }
/*       IF(ICLS1(8).EQ.4) GOTO 700 */
    if (ailmtb_1.iclass[7] == 4) {
	goto L700;
    }
/* .. */
/* ..  FINI INPUT WITH AN ILLEGAL FORMAT */
L510:
    a1com_1.jsuber = 23;
L520:
    ibr = 3;
/* .. */
L600:
    adiagp_();
    switch ((int)ibr) {
	case 1:  goto L100;
	case 2:  goto L400;
	case 3:  goto L700;
    }
/* .. */
/* .. CLOSE THE MACRO AND SEGMENT LIBRARIES, REWIND LOOP STORAGE AND */
/* .. THE CANON OVERFLO FILE */
/* .. */
L700:
    atapop_(&ataptb_1.cantap, &c__1, &ioflag);
    atapop_(errtap, &c__1, &ioflag);
    apread_(ainpot_1.inword, &c__10, &alibry_1.segnam, &a1com_1.jsuber);
    alibry_1.irdmod = 0;
/* .. */
/* .. HAVE WE BUILT TABLES IN PASS1 THAT EXCEEDED THE ALLOWABLE SIZE */
/* . */
    ic = amxtab_1.maxvs1 + 1 + amxtab_1.maxvs2 + amxtab_1.maxptp + 
	    amxtab_1.maxscl;
    if (ic <= 5900) {
	goto L800;
    }
/* .. */
/* .. THE TABLE SIZE WAS EXCEEDED */
    a1com_1.jsuber = 40;
    adiagp_();
/* .. */
/* ..   OUTPUT THE CLASS 8 PTPP RECORD -- MUST BE THE LAST REC. THEREON */
/* .. */
L800:
    ipt[OTHER_ENDIAN_S(0)] = 8;
    ipt[OTHER_ENDIAN_S(1)] = 0;
    aptpp_1.inptp = 1;
    aptpp_1.jmode = 5;
    aptput_();
/* .. MOVE THE PTPP TABLE TO THE PTPP STORAGE FILE -- PTPTAP */
    aptpp_1.jmode = 6;
    aptput_();
/* .. WRITE THE END OF FILE AND REWIND THE PTPTAP FILE */
    atapop_(ptptap, &c__2, &ioflag);
    atapop_(ptptap, &c__1, &ioflag);
/* .. */
/* .. INDICATE TO THE SECTION 1 CONTROL PROGRAM THAT PASS ONE PROCESSING */
/* .. IS COMPLETED */
    a1com_1.ifini = -1;
    ascntl_();
    s_stop("", (ftnlen)0);
} /* afini_ */

#undef ptptap
#undef errtap
#undef icls1
#undef ipt


