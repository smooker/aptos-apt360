/* AINT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal adum[82], tau1[1], tau2[1], afillr[516];
    integer idum[6], itlon[1], ifillr[233];
    doublereal bfllr[536];
    integer ifl2[7], iids, ics, iics;
    doublereal dummy[47], cscf[3], dscf[3], cftem[3], vtem[3], ptem1[3], 
	    ptem2[3], pt[18]	/* was [3][6] */, dot[6], fpnt[3], te2d[3], 
	    ti2d[3], cr, thds, thcs, tauds, taucs, percen, ans, res, pnttan[3]
	    , ex[3], ey[3], ez[3], vnul[3];
    integer icscf, idscf, itopt, n, idone, nrev, itfar, itc, ioc, ipc, intp, 
	    ier, nint, icase, itan;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

static struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

static struct {
    doublereal q15x01, qp9x01, qp6x01, qp5x01, qp4x01, qp0001, qp001, qp01, 
	    qp1, q1p, q10p, q1000p, q1pe5, q1pe6, q1pe10, q1pe20, q1pe30, 
	    q1pe36, q1pe38, qp8x01, qp7x01, qp4x09, qp9, qp99, qp995, qp997, 
	    qp999, qp9999, qp4x95, qp5x95, qp6x9, qp7x9, qp6x05, qp5x05, 
	    qp4x05, qp0005, qp005, qp05, qp5, q5p, q4x045, qp0002, qp0047, 
	    qp017, q1rad, qp0349, qp125, qp6, qp2, qp2499, qp25, qp3, qp7, 
	    qp75, qp8, qp866, q1p01, q1p1, q1p2, q1p25, q1p5, q2p, q2p5, q3p, 
	    q3p5, q4p, q8p, q11p, q45p, q90p, q130p, q4500p, q9000p, qp02, 
	    qnul, qpie, qfil[9];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__713 = 713;
static integer c__715 = 715;
static integer c__714 = 714;
static integer c__720 = 720;
static integer c__721 = 721;

/* Subroutine */ int aint_(itry)
integer *itry;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__, j;
    static doublereal bns, cns;
    extern /* Subroutine */ int aerr_(), avsub_(), avsto_(), accint_(), 
	    alcint_(), avleng_(), allint_();
    static doublereal onness;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */
/*     COMPUTES ALL POSSIBLE INTERSECTIONS - STORES THEM IN PT(1,1-6) AND */
/*     RETURNS NINT AS THE NUMBER FOUND */
/*      IF TANTO HAS BEEN SPECIFIED, SOLVES DIRECTLY FOR ANSWER */
/*      AND SETS NINT = -1 FOR SUCCESSFUL COMPUTATION */

/*      SET INDEX FOR DOO LOOPS */
    j = 3;
/* Computing MIN */
    d__2 = a2cmmn_.tau1[a2cmmn_.ics - 1], d__3 = (d__1 = a2cmmn_.tau2[
	    a2cmmn_.ics - 1], abs(d__1));
    a2cmmn_.ans = min(d__2,d__3) * a2fpc_1.qp99;
    if (a2cmmn_.cr <= a2cmmn_.ans) {
	j = 1;
    }

/*      ERROR IS TO OR PAST SPECIFIED IN CASE OF ZERO RADIUS CUTTER */

    if (j == 1 && (a2cmmn_.itopt == 1 || a2cmmn_.itopt == 3)) {
	a2cmmn_.itopt = 2;
    }

    a2cmmn_.nint = 0;
    a2cmmn_.itan = 0;
    if (a2cmmn_.icscf == 1 && a2cmmn_.idscf == 1) {
	a2cmmn_.icase = 1;
    }
    if (a2cmmn_.icscf == 2 && a2cmmn_.idscf == 1) {
	a2cmmn_.icase = 2;
    }
    if (a2cmmn_.icscf == 1 && a2cmmn_.idscf == 2) {
	a2cmmn_.icase = 3;
    }
    if (a2cmmn_.icscf == 2 && a2cmmn_.idscf == 2) {
	a2cmmn_.icase = 4;
    }
    if (a2cmmn_.icase == 0) {
	aerr_(&c__713);
    }
    if (a2cmmn_.itopt == 4) {
	goto L100;
    }
L1:
    switch ((int)a2cmmn_.icase) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
    }

/*     LINE DS, LINE CS */
L10:
    avsto_(a2cmmn_.cscf, a2cmmn_.cftem);
    a2cmmn_.cftem[2] += a2cmmn_.cr;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	allint_(a2cmmn_.dscf, a2cmmn_.cftem, a2cmmn_.ptem1);
	if (a2cmmn_.ier == 1) {
	    aerr_(&c__715);
	}
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
/* L11: */
	a2cmmn_.cftem[2] -= a2cmmn_.cr;
    }
    goto L46;

/*     DS LINE, CS CIRCLE */
L20:
    avsto_(a2cmmn_.cscf, a2cmmn_.cftem);
    a2cmmn_.cftem[2] += a2cmmn_.cr;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (a2cmmn_.cftem[2] <= a2fpc_1.qnul) {
	    goto L25;
	}
	alcint_(a2cmmn_.dscf, a2cmmn_.cftem, a2cmmn_.ptem1, a2cmmn_.ptem2,
		 &a2cmmn_.taucs);
	if (a2cmmn_.ier == 0) {
	    goto L25;
	}
	if (a2cmmn_.ier == 1) {
	    goto L23;
	}
	if (a2cmmn_.ier == 2) {
	    goto L24;
	}

/*     ONE INTERSECTION */
L23:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	avsto_(a2cmmn_.ptem1, a2cmmn_.pnttan);
	a2cmmn_.itan = 1;
	goto L25;


/*     TWO INTERSECTIONS */
L24:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	avsub_(a2cmmn_.ptem1, a2cmmn_.ptem2, a2cmmn_.vtem);
	avleng_(a2cmmn_.vtem, &a2cmmn_.ans);
	if (a2cmmn_.ans < a2cmmn_.tauds) {
	    goto L25;
	}
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem2, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	goto L25;

L25:
	a2cmmn_.cftem[2] -= a2cmmn_.cr;
/* L26: */
    }
    goto L46;

/*     DS CIRCLE,  CS LINE CASE */
L30:
    avsto_(a2cmmn_.cscf, a2cmmn_.cftem);
    a2cmmn_.cftem[2] += a2cmmn_.cr;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	alcint_(a2cmmn_.cftem, a2cmmn_.dscf, a2cmmn_.ptem1, a2cmmn_.ptem2,
		 &a2cmmn_.taucs);
	if (a2cmmn_.ier == 0) {
	    goto L35;
	}
	if (a2cmmn_.ier == 1) {
	    goto L33;
	}
	if (a2cmmn_.ier == 2) {
	    goto L34;
	}

/*     ONE INTERSECTION */
L33:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	if (a2cmmn_.itan == 0) {
	    goto L10001;
	}
	avsub_(a2cmmn_.ptem1, a2cmmn_.pnttan, a2cmmn_.vtem);
	a2cmmn_.vtem[2] = a2fpc_1.qnul;
	avleng_(a2cmmn_.vtem, &a2cmmn_.ans);
	if (a2cmmn_.ans > a2fpc_1.q2p * a2cmmn_.taucs) {
	    goto L10002;
	}
	if (a2fpc_1.qfil[8] < onness) {
	    goto L10001;
	}
	goto L35;
L10002:
	if (i__ != 2) {
	    goto L35;
	}
L10001:
	avsto_(a2cmmn_.ptem1, a2cmmn_.pnttan);
	a2cmmn_.itan = 1;
	onness = a2fpc_1.qfil[8];
	goto L35;

/*     TWO INTERSECTIONS */
L34:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	avsub_(a2cmmn_.ptem1, a2cmmn_.ptem2, a2cmmn_.vtem);
	avleng_(a2cmmn_.vtem, &a2cmmn_.ans);
	if (a2cmmn_.ans < a2cmmn_.tauds) {
	    goto L35;
	}
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem2, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);

L35:
	a2cmmn_.cftem[2] -= a2cmmn_.cr;
    }

    goto L46;

/*     CIRCLE-CIRCLE CASE */
L40:
    avsto_(a2cmmn_.cscf, a2cmmn_.cftem);
    a2cmmn_.cftem[2] += a2cmmn_.cr;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (a2cmmn_.itopt != 4) {
	    goto L41;
	}
	if (a2cmmn_.dscf[2] != a2cmmn_.cscf[2]) {
	    goto L41;
	}
/* Computing 2nd power */
	d__1 = a2cmmn_.dscf[0] - a2cmmn_.cscf[0];
	a2cmmn_.ans = d__1 * d__1;
/* Computing 2nd power */
	d__1 = a2cmmn_.dscf[1] - a2cmmn_.cscf[1];
	bns = d__1 * d__1;
	cns = sqrt(a2cmmn_.ans + bns);
	if (cns >= a2cmmn_.dscf[2]) {
	    goto L41;
	}
	if ((d__1 = cns - a2cmmn_.cr, abs(d__1)) > a2cmmn_.taucs) {
	    goto L41;
	}
	if (i__ < 3) {
	    goto L45;
	}
L41:
	if (a2cmmn_.cftem[2] < a2cmmn_.taucs) {
	    goto L45;
	}
	accint_(a2cmmn_.dscf, a2cmmn_.cftem, a2cmmn_.ptem1, a2cmmn_.ptem2,
		 &a2cmmn_.taucs);

	if (a2cmmn_.ier == 0) {
	    goto L45;
	}
	if (a2cmmn_.ier == 1) {
	    goto L43;
	}
	if (a2cmmn_.ier == 2) {
	    goto L44;
	}

/*     1 INTERSECTION */
L43:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	if (a2cmmn_.itan == 0) {
	    goto L10005;
	}
	avsub_(a2cmmn_.ptem1, a2cmmn_.pnttan, a2cmmn_.vtem);
	a2cmmn_.vtem[2] = a2fpc_1.qnul;
	avleng_(a2cmmn_.vtem, &a2cmmn_.ans);
	if (a2cmmn_.ans > a2fpc_1.q2p * a2cmmn_.taucs) {
	    goto L10006;
	}
	if (a2fpc_1.qfil[8] < onness) {
	    goto L10005;
	}
	goto L45;
L10006:
	if (i__ != 2) {
	    goto L45;
	}
L10005:
	if (i__ - 2 == 0 && a2cmmn_.itlon[a2cmmn_.iids - 1] != 0 || i__ - 2 
		!= 0 && a2cmmn_.itlon[a2cmmn_.iids - 1] == 0) {
	    goto L45;
	}
	avsto_(a2cmmn_.ptem1, a2cmmn_.pnttan);
	a2cmmn_.itan = 1;
	onness = a2fpc_1.qfil[8];
	goto L45;

/*     TWO  INTERSECTIONS */
L44:
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem1, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	avsub_(a2cmmn_.ptem1, a2cmmn_.ptem2, a2cmmn_.vtem);
	avleng_(a2cmmn_.vtem, &a2cmmn_.ans);
	if (a2cmmn_.ans < a2cmmn_.tauds) {
	    goto L45;
	}
	++a2cmmn_.nint;
	avsto_(a2cmmn_.ptem2, &a2cmmn_.pt[a2cmmn_.nint * 3 - 3]);
	goto L45;


L45:
	a2cmmn_.cftem[2] -= a2cmmn_.cr;
    }


L46:
    if (a2cmmn_.itopt == 4) {
	goto L200;
    }
    if (a2cmmn_.nint == 0) {
	goto L47;
    }
    *itry = 0;
    return 0;
L47:
    if (*itry == 3) {
	aerr_(&c__714);
    }
    return 0;
L100:
/* ... WHEN CR < TAUCS, J=1 ... BUT UNDER TANTO MODE(WHICH THIS BRANCH IS) */
/* ... RESET J TO 3 ... SO WILL GO THRU INTERSECTION CALCULATION 3 TIMES */
    j = 3;
/*      IF LINE LINE CASE AND TANTO SPECIFIED, ERROR */
    if (a2cmmn_.icase == 1) {
	aerr_(&c__720);
    }
    goto L1;
L200:
    if (a2cmmn_.itan == 1) {
	goto L201;
    }
    if (*itry == 3) {
	aerr_(&c__721);
    }
    return 0;
L201:
    *itry = 0;
    a2cmmn_.nint = -1;
    avsto_(a2cmmn_.pnttan, a2cmmn_.pt);
    return 0;
} /* aint_ */

