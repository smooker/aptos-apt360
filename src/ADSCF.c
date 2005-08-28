/* ADSCF.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal dummy[1308], cscf[3], dscf[3], cftem[3], vtem[3], ptem1[3], 
	    ptem2[3], pt[18]	/* was [3][6] */, dot[6], fpnt[3], te2d[3], 
	    ti2d[3], cr, thds, thcs, tauds, taucs, percen, ans, res, pnttan[3]
	    , ex[3], ey[3], ez[3], vnul[3];
    integer icscf, idscf, itopt, n, idone, nrev, itfar, itc, ioc, ipc, intp, 
	    ier, nint, icase, itan;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

struct {
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

static integer c__8 = 8;
static integer c__2 = 2;
static integer c__703 = 703;
static integer c__704 = 704;
static integer c_n705 = -705;

/* Subroutine */ int adscf_(canst)
doublereal *canst;
{
    static integer i__;
    extern /* Subroutine */ int aerr_(), avsub_(), astor_(), avsto_(), 
	    avleng_(), avnorm_();

/* *** */
/*     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER */
/*     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH */
/* *** */
/*     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN */
/*     STREAM ARITHMETIC ELEMENT */
/*     ALSO EX,EY,EZ,VNUL */
/* ...  SET        IDSCF = 1 FOR LINE DS */
/*                      = 2 FOR CIRCLE DS */

/*     SET UP DSCF(1) = A                          IN EQUATION AX+BY=D */
/*            DSCF(2) = B                          OR */
/*            DSCF(3) = D,R                        (X-A)**2+(Y-B)**2 =R*2 */


/*     CELL1      surface type 2,3 - line, plane, 3,4,circle cylinder? */
/*     CELL 2    record length */
/*     CELL 3     name */
/*     CELL 4    subscript */
/*     CELL 5     X COMPONENT 0 */
/*     CELL 6     Y COMPONENT 0 */
/*     CELL 7     Z COMPONENT 1 */
/*     CELL 8     D VALUE     0 */
/* ...  PICK UP FIRST CELL OF CANONICAL FORM */

    /* Parameter adjustments */
    --canst;

    /* Function Body */
    astor_(&canst[1], &c__8, &i__, &c__2);

/* ...  TEST FOR LINE */
    a2cmmn_.idscf = 0;
    if (i__ == 2 || i__ == 3) {
	a2cmmn_.idscf = 1;
    }

/* ...  TEST FOR CIRCLE */

    if (i__ == 4 || i__ == 5) {
	a2cmmn_.idscf = 2;
    }

/* ...  CHECK CANONICAL FORM */

    if (a2cmmn_.idscf == 0) {
	aerr_(&c__703);
    }

/* ...  BRANCH TO LINE OR CIRCLE AREA */

    switch ((int)a2cmmn_.idscf) {
	case 1:  goto L10;
	case 2:  goto L20;
    }

/* ...  LINE */

L10:
    avsto_(&canst[5], a2cmmn_.dscf);
/* 	zero out D */
    a2cmmn_.dscf[2] = a2fpc_1.qnul;
/* 	normalize the vector */
    avnorm_(a2cmmn_.dscf, a2cmmn_.dscf, &a2cmmn_.ier);
    if (a2cmmn_.ier == 1) {
	aerr_(&c__704);
    }
/* 	calculate d */
/* 	D=AX+BY */
    a2cmmn_.dscf[2] = a2cmmn_.dscf[0] * a2cmmn_.te2d[0] + a2cmmn_.dscf[1] 
	    * a2cmmn_.te2d[1];
    return 0;

/* ...  CIRCLE */
/* 	subtract tool end */
L20:
    avsub_(a2cmmn_.te2d, &canst[5], a2cmmn_.vtem);
    a2cmmn_.vtem[2] = a2fpc_1.qnul;
    avsto_(&canst[5], a2cmmn_.dscf);
    avleng_(a2cmmn_.vtem, &a2cmmn_.dscf[2]);
    if (a2cmmn_.dscf[2] <= a2cmmn_.tauds) {
	aerr_(&c_n705);
    }
    return 0;
} /* adscf_ */

