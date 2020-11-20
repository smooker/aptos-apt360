/* ADIAGP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

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
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__2 = 2;

/* Subroutine */ int adiagp_()
{
    /* Local variables */
#define kpt ((integer *)&aptpp_1)
    static integer ioflag;
#define errtap ((doublereal *)&ataptb_1 + 9)
#define ptptap ((doublereal *)&ataptb_1 + 3)
    extern /* Subroutine */ int aptput_(), atapwt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */


/* ... SUM  - INPUT FLAG SET BY CALLING PROG..0 INDICATES DIAG. NO. ONLY */
/* ... JSUBER MUST BE SET BY CALLING PROG... 1 - INDICATES A VAR. SYMB. */
/* ...  IS TO BE OUTPUT,  NAME AND JSUBER SET BY CALLING PROG.. */
/* ...  9 - INDICATES A SUBSCRIPTED VAR. SYMB. IN ERROR..JSUBER, NAME */
/* ... AND PT(7) ARE SET BY CALLING PROG.,,(PT(7) IS SUBSCRIPT VALUE) */
/* ..   MACERR -- .NE.0  ERROR DURING LOOP OR MACRO DEFINITION MODE    D39 */
/* .. */
    if (abreak_1.nwonrd < 0) {
	amacro_1.macerr = 1;
    }
    if (a1com_1.sum == 9) {
	goto L90;
    }
    abreak_1.kf = 4;
    if (a1com_1.sum == 0) {
	goto L10;
    }

/*     VARIABLE SYMBOL INVOLVED - OUTPUT THE NAME */
    abreak_1.kf = 5;
L9:
    aptpp_1.pt[5] = a1com_1.name__;
    a1com_1.sum = 0;

L10:
    kpt[OTHER_ENDIAN_S(0)] = 2;
    kpt[OTHER_ENDIAN_S(1)] = abreak_1.kf;
    kpt[OTHER_ENDIAN_S(2)] = a1com_1.jsuber;
    kpt[OTHER_ENDIAN_S(3)] = 1;
    kpt[OTHER_ENDIAN_S(4)] = 0;
    kpt[OTHER_ENDIAN_S(5)] = aklas7_1.iisn;
    aptpp_1.pt[3] = aklas7_1.ppseq1;
    aptpp_1.pt[4] = aklas7_1.ppseq2;
    ++abreak_1.kf;

/* ...     TEST FOR DEFINING A MACRO - SPECIAL CASE */
    if (amcstf_1.macrd < 0) {
	goto L20;
    }

/* ...     NO... */
    aptpp_1.inptp = abreak_1.kf;
    aptpp_1.jmode = 5;
    aptput_();
    goto L30;

/* ...     DEFINING A MACRO... */
/* ...     INCREMENT PTPP RECORD NUMBER */
L20:
    ++aptpp_1.irecn;
/* ...     WRITE DIAGNOSTIC OUT IMMEDIATELY */
    atapwt_(ptptap, &ioflag, &c__4, &aptpp_1.irecn, &c__1, &c__0, &c__1, &
	    c__2, &c__1, aptpp_1.pt, &abreak_1.kf);
/* ...     SET FLAG INDICATING BAD MACRO DEFINITION */
    amacro_1.macerr = 1;

L30:
    a1com_1.jsuber = 0;
    return 0;
/* ... OUTPUT SUBSCRIPTED VAR.., PT(7) IS SET BY CALLING PROG. */
/* ...   KF IS THE LENGTH OF PT ENTRIES LESS THE HEADER ENTRY */
L90:
    abreak_1.kf = 6;
    goto L9;
} /* adiagp_ */

#undef ptptap
#undef errtap
#undef kpt


