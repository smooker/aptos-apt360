/* ADDTB.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
/* Common Block Declarations */

static struct {
    doublereal saka[3413];
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

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

static integer c__8 = 8;
static integer c__4 = 4;
static integer c_n1501 = -1501;

/* Subroutine */ int addtb_()
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4, d__5;
    static doublereal equiv_22[3], equiv_26[11];

    /* Builtin functions */
    double sqrt(), d_sign(), atan(), sin(), cos();

    /* Local variables */
#define d__ ((doublereal *)&a2cmmn_1 + 1408)
    static integer i__, j, k, l, m, n;
    static doublereal p, q;
#define s ((doublereal *)&a2cmmn_1 + 69)
#define u (equiv_22)
    static doublereal v[3];
#define x (equiv_22)
    static doublereal a1, b1, c1;
#define g2 (equiv_26 + 3)
#define h2 (equiv_26 + 2)
    static integer i1;
#define ic ((integer *)&a2cmmn_1 + 2599)
#define is ((integer *)&a2cmmn_1 + 2512)
#define tn ((doublereal *)&a2cmmn_1 + 9)
    static doublereal un;
#define tp ((doublereal *)&a2cmmn_1 + 6)
    static doublereal up, vp, vn, sq;
#define acf (equiv_26 + 2)
#define bcf (equiv_26 + 3)
#define ccf (equiv_26 + 4)
#define seg (equiv_26)
#define ier ((integer *)&a2cmmn_1 + 6816)
    static integer kkk;
#define iis ((integer *)&a2cmmn_1 + 2513)
#define tem ((doublereal *)&a2cmmn_1 + 946)
#define iop ((integer *)&a2cmmn_1 + 1209)
    static doublereal ans;
#define upp (equiv_26 + 9)
#define vpp (equiv_26 + 10)
    static doublereal unn, vnn;
#define aibm ((doublereal *)&a2cmmn_1)
#define ibma ((integer *)&a2cmmn_1 + 1200)
#define bibm ((doublereal *)&a2cmmn_1 + 720)
#define ibmc ((integer *)&a2cmmn_1 + 2512)
#define ibmb ((integer *)&a2cmmn_1 + 6816)
#define iseg ((integer *)equiv_26)
    extern /* Subroutine */ int aerr_();
#define sinn (equiv_26 + 5)
#define coss (equiv_26 + 6)
    static integer nwds;
    static doublereal vint, gsign;
    extern /* Subroutine */ int avdot_();
    static doublereal slope;
    extern /* Subroutine */ int astor_();
    static integer nmbseg, intend;
#define cansto ((doublereal *)&a2cmmn_1 + 1408)
    static doublereal savpar[9], sqroot;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* ..   COMOON AND EQUIVALENCE TO REST OFARITHMETIC ELEMENT */
/*           ...NOTE...  DIMENSION NUMBERS ARE ARBITRARY */





/* ...  COMMON,DIMENSION,EQUIVALENCE FOR THIS ROUTINE ONLY */


/* ...  DEFINITIONS OF ARITHMETIC STATEMENT FUNCTIONS */


/* ...  INITIALIZE DIRECTED DISTANCE */

    s[*is - 1] = a2fpc_1.q1pe38;
    iseg[OTHER_ENDIAN_S(3)] = iop[(*iis - 1)];
    *ier = 0;

/* ...  TRANSFORM TOOL POINT AND TOOL NORMAL INTO U-V-W COORD. SYSTEM */
    avdot_(&d__[*ic + 4], &tp[*is - 1], &up);
    avdot_(&d__[*ic + 7], &tp[*is - 1], &vp);
    avdot_(&d__[*ic + 4], &tn[*is - 1], &un);
    avdot_(&d__[*ic + 7], &tn[*is - 1], &vn);

/* ...  CHECK TO SEE IF TOOL NORMAL IS PARALLEL TO AXIS OF TABCYL */

    if (abs(un) + abs(vn) - a2fpc_1.qp5x01 <= 0.) {
	goto L1002;
    } else {
	goto L600;
    }

/* ...  SET INDEXES AND BEGIN EXAMINING TABCYL SEGMENTS */

L600:
    astor_(&cansto[*ic + 2], &c__8, &nwds, &c__4);
//nwds here means number of points in the definition
//*ic - offset into cansto to start of definition
//14-rotation matrix definition and first extension segment 
//2 - ?
//7-number of floats defining segment
    nwds = *ic + 14 + (nwds - 2) * 7;
//nwds now means offset of the end of the record 
    if (a2fpc_1.q1pe5 * abs(un) - abs(vn) >= 0.) {
	goto L101;
    } else {
	goto L102;
    }
L102:
    i1 = 2;
    goto L103;
L101:
    i1 = 1;
    p = vn / un;
    q = vp - p * up;
L103:
    astor_(&cansto[*ic + 3], &c__8, &i__, &c__4);
    i__ += -13;
    if (i__ - 14 >= 0) {
	goto L105;
    } else {
	goto L104;
    }
L104:
    i__ = 14;
L105:
    nmbseg = i__ + *ic;
//nmbseg is the starting offset of the segment definitions
L550:
    i__1 = nwds;
    for (i__ = nmbseg; i__ <= i__1; i__ += 7) {

/* ...  STORE CANONICAL INFORMATION FOR SEGMENT IN SEG(K) */

	*h2 = d__[i__ - 1] - d__[i__ + 6];
	*g2 = d__[i__ + 7] - d__[i__];
	switch ((int)i1) {
	    case 1:  goto L128;
	    case 2:  goto L129;
	}
L128:
	tem[0] = p * *h2;
	if ((d__1 = d__[i__ + 4]) < 0.) {
	    goto L111;
	} else if (d__1 == 0) {
	    goto L112;
	} else {
	    goto L113;
	}
L111:
	u[0] = d__[i__ - 1] + *g2 * d__[i__ + 4];
	v[0] = *h2 * d__[i__ + 4] + d__[i__];
	u[1] = u[0] - *h2;
	v[1] = v[0] + *g2;
	tem[1] = p * u[0] + q;
	if ((d__1 = tem[1] - v[0]) < 0.) {
	    goto L114;
	} else if (d__1 == 0) {
	    goto L150;
	} else {
	    goto L117;
	}
L114:
	if (tem[1] - tem[0] - v[1] >= 0.) {
	    goto L150;
	} else {
	    goto L115;
	}
L115:
	v[2] = *h2 * d__[i__ + 5] - d__[i__];
	tem[1] = (*g2 * d__[i__ + 5] - d__[i__ - 1]) * p - v[2] - q;
	if (-tem[1] >= 0.) {
	    goto L150;
	} else {
	    goto L116;
	}
L116:
	if (*g2 + tem[1] + tem[0] <= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L117:
	if (v[1] - tem[1] + tem[0] >= 0.) {
	    goto L150;
	} else {
	    goto L118;
	}
L118:
	v[2] = *h2 * d__[i__ + 5] - d__[i__];
	tem[1] = (*g2 * d__[i__ + 5] - d__[i__ - 1]) * p - v[2] - q;
	if (tem[1] >= 0.) {
	    goto L150;
	} else {
	    goto L119;
	}
L119:
	if (-tem[1] - tem[0] - *g2 <= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L112:
	if ((d__1 = p * d__[i__ - 1] + q - d__[i__]) < 0.) {
	    goto L120;
	} else if (d__1 == 0) {
	    goto L150;
	} else {
	    goto L121;
	}
L120:
	if (p * d__[i__ + 6] - d__[i__ + 7] + q >= 0.) {
	    goto L150;
	} else {
	    goto L115;
	}
L121:
	if (p * d__[i__ + 6] + q - d__[i__ + 7] <= 0.) {
	    goto L150;
	} else {
	    goto L118;
	}
L113:
	v[0] = *h2 * d__[i__ + 4] - d__[i__];
	tem[1] = (*g2 * d__[i__ + 4] - d__[i__ - 1]) * p - v[0] - q;
	if ((d__1 = -tem[1]) < 0.) {
	    goto L122;
	} else if (d__1 == 0) {
	    goto L150;
	} else {
	    goto L135;
	}
L122:
	if (-tem[1] - tem[0] - *g2 >= 0.) {
	    goto L150;
	} else {
	    goto L123;
	}
L123:
	if (p * d__[i__ - 1] + q - d__[i__] + a2fpc_1.qp6x01 >= 0.) {
	    goto L150;
	} else {
	    goto L124;
	}
L124:
	if (p * d__[i__ + 6] + q - d__[i__ + 7] >= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L135:
	if (*g2 + tem[1] + tem[0] >= 0.) {
	    goto L150;
	} else {
	    goto L136;
	}
L136:
	if (p * d__[i__ - 1] + q - d__[i__] <= 0.) {
	    goto L150;
	} else {
	    goto L137;
	}
L137:
	if (p * d__[i__ + 6] + q - d__[i__ + 7] <= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L129:
	u[0] = (d__1 = d__[i__ + 4], abs(d__1)) * *g2 - d__[i__ - 1] + up;
	u[2] = *g2 * d__[i__ + 5] - d__[i__ - 1] + up;
/* Computing MIN */
	d__1 = a2fpc_1.qp9x01 * d__[i__ + 3];
	ans = min(d__1,a2fpc_1.qp9x01);
	if (u[0] < 0.) {
	    goto L141;
	} else if (u[0] == 0) {
	    goto L150;
	} else {
	    goto L144;
	}
L141:
	if (u[0] + *h2 >= 0.) {
	    goto L150;
	} else {
	    goto L142;
	}
L142:
	if (u[2] >= 0.) {
	    goto L150;
	} else {
	    goto L143;
	}
L143:
	if (-u[2] - *h2 <= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L144:
	if (-u[0] - *h2 + ans >= 0.) {
	    goto L150;
	} else {
	    goto L145;
	}
L145:
	if (-u[2] >= 0.) {
	    goto L150;
	} else {
	    goto L146;
	}
L146:
	if (u[2] + *h2 - ans <= 0.) {
	    goto L150;
	} else {
	    goto L1000;
	}
L150:
	*sinn = *g2 / d__[i__ + 3];
	*coss = -(*h2) / d__[i__ + 3];
	*h2 = up - d__[i__ - 1];
	*g2 = vp - d__[i__];
	*upp = *h2 * *coss + *g2 * *sinn;
	*vpp = -(*h2) * *sinn + *g2 * *coss;
	unn = un * *coss + vn * *sinn;
	vnn = -un * *sinn + vn * *coss;

/* ...  TEST FOR INTERSECTION OF DIRECTED LINE WITH RECTANGLE */
/* ...  SURROUNDING TABCYL SEGMENT */

	if (a2fpc_1.q1pe5 * abs(unn) - abs(vnn) <= 0.) {
	    goto L603;
	} else {
	    goto L604;
	}
L603:
	j = 2;
L501:
	seg[2] = d__[i__ + 1];
	seg[3] = d__[i__ + 2];
	seg[4] = -d__[i__ + 3] * (seg[2] * d__[i__ + 3] + seg[3]);
	switch ((int)j) {
	    case 1:  goto L609;
	    case 2:  goto L502;
	}
L502:
	seg[7] = ((*acf * *upp + *bcf) * *upp + *ccf) * *upp;
	tem[1] = seg[7] - *vpp;
	tem[0] = tem[1] * tem[1];
	if (tem[0] - s[*is - 1] >= 0.) {
	    goto L1000;
	} else {
	    goto L503;
	}
L503:
	seg[8] = *upp;
	if (tem[1] * vnn >= 0.) {
	    goto L506;
	} else {
	    goto L504;
	}
L504:
	if (iop[(*iis - 1)] <= 0) {
	    goto L505;
	} else {
	    goto L1000;
	}
L505:
	gsign = -a2fpc_1.q1p;
	goto L507;
L506:
	gsign = a2fpc_1.q1p;
L507:
	iseg[OTHER_ENDIAN_S(1)] = i__;
	s[*is - 1] = tem[0];
	for (n = 1; n <= 9; ++n) {
/* L508: */
	    savpar[n - 1] = seg[n + 1];
	}
	iseg[OTHER_ENDIAN_S(3)] = -1;
	switch ((int)j) {
	    case 1:  goto L51;
	    case 2:  goto L1000;
	}
L604:
	slope = vnn / unn;
	if (abs(slope) - a2fpc_1.qp5x01 <= 0.) {
	    goto L605;
	} else {
	    goto L4419;
	}
L605:
	slope = a2fpc_1.qnul;
L4419:
	sqroot = d__[i__ + 3];
	j = 1;
	if (iseg[OTHER_ENDIAN_S(3)] != 0) {
	    goto L509;
	} else {
	    goto L501;
	}
L509:
	tem[0] = a2fpc_1.qnul;
	v[0] = sqroot * d__[i__ + 5];
	v[1] = sqroot * (d__1 = d__[i__ + 4], abs(d__1));
	if (-(*upp) >= 0.) {
	    goto L4420;
	} else {
	    goto L4429;
	}
L4429:
	if (*upp - sqroot >= 0.) {
	    goto L4430;
	} else {
	    goto L4431;
	}
L4431:
	if ((d__1 = v[0] - *vpp) < 0.) {
	    goto L4434;
	} else if (d__1 == 0) {
	    goto L501;
	} else {
	    goto L4432;
	}
L4434:
	if (*vpp - v[1] <= 0.) {
	    goto L501;
	} else {
	    goto L4435;
	}
L4430:
	tem[0] = sqroot;
L4420:
	tem[1] = *vpp + slope * (tem[0] - *upp);
/* L4421: */
	if ((d__1 = v[0] - tem[1]) < 0.) {
	    goto L4426;
	} else if (d__1 == 0) {
	    goto L4424;
	} else {
	    goto L4432;
	}
L4426:
	if (v[1] - tem[1] >= 0.) {
	    goto L4424;
	} else {
	    goto L4435;
	}
L4435:
	j = 2;
L4432:
	tem[0] = (v[j - 1] - *vpp) / slope + *upp;
/* L4425: */
	tem[1] = v[j - 1];
L4424:
/* Computing 2nd power */
	d__1 = tem[0] - *upp;
/* Computing 2nd power */
	d__2 = tem[1] - *vpp;
	tem[2] = d__1 * d__1 + d__2 * d__2;

/* ...  IF DIRECTED DISTANCE TO RECTANGLE IS LESS THAN DIR. DIST. */
/* ...  TO CUBIC OF LAST SEGMENT,GO AHEAD AND CALC. DIR. DIST. */
/* ...  TO CUBIC FOR THIS SEGMENT */

	if (tem[2] - s[*is - 1] >= 0.) {
	    goto L1000;
	} else {
	    goto L4436;
	}
L4436:
	j = 1;
	if (iop[(*iis - 1)] <= 0) {
	    goto L501;
	} else {
	    goto L4437;
	}
L4437:
	if (unn * (*upp - tem[0]) + vnn * (*vpp - tem[1]) <= 0.) {
	    goto L501;
	} else {
	    goto L1000;
	}

/* ...  CALC. DIRECTED DISTANCE TO CUBIC OF SEGMENT */

/* ...  J IS SET TO KEEP A RECORD OF THE NUMBER OF INTERSECTIONS WITH */
/* ...  THE CUBIC */

L609:
	vint = *vpp - slope * *upp;
	if (a2fpc_1.qp5x01 - abs(vint) >= 0.) {
	    goto L618;
	} else {
	    goto L612;
	}

/* ...  TEST FOR DEGENERATE CASES OF CUBIC */

L612:
	if (seg[2] != 0.) {
	    goto L630;
	} else {
	    goto L613;
	}
L613:
	if (seg[3] != 0.) {
	    goto L616;
	} else {
	    goto L617;
	}

/* ...  DOES DIRECTED LINE CROSS U AXIS WITHIN SEGMENT */

L614:
	if (vint * slope >= 0.) {
	    goto L635;
	} else {
	    goto L615;
	}
L615:
	if (vint / slope + sqroot + a2fpc_1.qp5x01 * sqroot <= 0.) {
	    goto L635;
	} else {
	    goto L5041;
	}

/* ...  DEGENERATE CUBIC ---- QUADRATIC EQUATION */

L616:
	c1 = -vint;
	a1 = seg[3];
	b1 = seg[4] - slope;
/* L622: */
	j = 0;
	goto L623;

/* ...  DEGENERATE CUBIC ---- LINEAR EQUATION */

L617:
	x[0] = -vint / slope;
	goto L48;

/* ...  FACTOR OUT THE ROOT,X=0,AND CREATE THE RESULTING QUADRATIC */

L618:
	x[0] = a2fpc_1.qnul;
	c1 = seg[4];
	b1 = seg[3];
L643:
	a1 = seg[2];

/* ...  SOLVE THE QUADRATIC EQUATION FOR ROOTS */

L623:
/* Computing 2nd power */
	d__1 = b1;
	sq = d__1 * d__1 - a2fpc_1.q4p * a1 * c1;
	if (abs(sq) - a2fpc_1.qp6x01 <= 0.) {
	    goto L624;
	} else {
	    goto L625;
	}
L624:
	if (abs(a1) - a2fpc_1.qp5x01 <= 0.) {
	    goto L62400;
	} else {
	    goto L62401;
	}
L62400:
	x[1] = a2fpc_1.q1pe20;
	goto L62402;
L62401:
	x[1] = -b1 / (a2fpc_1.q2p * a1);

/* ...  K IS SET TO KEEP A RECORD OF THE NUMBER OF ROOTS */
/* ...  OF THE QUADRATIC, 0=0 ROOTS, 2=1 ROOT, 3=2 ROOTS */

L62402:
	k = 2;
	goto L629;
L625:
	if (sq <= 0.) {
	    goto L621;
	} else {
	    goto L627;
	}
L621:
	k = 0;
	goto L629;
L627:
	d__1 = sqrt(sq);
	sq = -b1 - d_sign(&d__1, &b1);
	x[1] = a2fpc_1.q2p * c1 / sq;
	if (abs(a1) - a2fpc_1.qp5x01 <= 0.) {
	    goto L6271;
	} else {
	    goto L6272;
	}
L6271:
	x[2] = a2fpc_1.q1pe20;
	goto L6273;
L6272:
	x[2] = sq / (a2fpc_1.q2p * a1);
L6273:
	k = 3;
L629:
	if (j >= 0) {
	    goto L631;
	} else {
	    goto L614;
	}

/* ...  REJECT ROOTS NOT IN SEGMENT AND UPDATE RECORDS */

L631:
	n = 1;
L750:
	++n;
	if (n - k <= 0) {
	    goto L751;
	} else {
	    goto L752;
	}
L751:
	if ((d__1 = x[n - 1]) < 0.) {
	    goto L750;
	} else if (d__1 == 0) {
	    goto L634;
	} else {
	    goto L633;
	}
L633:
	if (x[n - 1] - sqroot <= 0.) {
	    goto L634;
	} else {
	    goto L750;
	}
L634:
	x[j] = x[n - 1];
	++j;
	goto L750;
L752:
	if (j <= 0) {
	    goto L1000;
	} else {
	    goto L48;
	}

/* ...  TRUE CUBIC, PREPARE TO DETERMINE ROOT */

/* ...  DIFFERENTIATE CUBIC AND SOLVE FOR MAX AND MIN POINTS */

L630:
	j = -1;
/* L620: */
	a1 = a2fpc_1.q3p * seg[2];
	b1 = a2fpc_1.q2p * seg[3];
	c1 = seg[4] - slope;
	goto L623;

/* ...  ELIMINATE MAX AND MIN POINTS NOT IN THE SEGMENT */

L635:
	n = 1;
L753:
	++n;
	if (n - k <= 0) {
	    goto L754;
	} else {
	    goto L1000;
	}
L754:
	if (x[n - 1] <= 0.) {
	    goto L753;
	} else {
	    goto L637;
	}
L637:
	if (x[n - 1] - sqroot <= 0.) {
	    goto L638;
	} else {
	    goto L753;
	}

/* ...  LOOK FOR TANGENCY AND MULTIPLE INTERSECTION CASES */

L638:
	tem[0] = ((*acf * x[n - 1] + *bcf) * x[n - 1] + (*ccf - slope)) * x[n 
		- 1] - vint;
	if (abs(tem[0]) - a2fpc_1.qp4x01 >= 0.) {
	    goto L640;
	} else {
	    goto L639;
	}

/* ...  TANGENCY */

L639:
	x[0] = x[n - 1];
	j = 1;
	goto L48;
L641:
	j = 1;
L642:
	b1 = seg[2] * x[0] + seg[3];
	c1 = b1 * x[0] + seg[4] - slope;
	goto L643;

/* ...  IS THERE A POSSIBLE MULTIPLE INTERSECTION */

L640:
	if (vint * tem[0] >= 0.) {
	    goto L5041;
	} else {
	    goto L753;
	}

/* ...  CALCULATE VALUE OF X WHICH WILL ASSURE CONVERGENCE TO A ROOT */

L5041:
	if (k - 2 <= 0) {
	    goto L5090;
	} else {
	    goto L5050;
	}
L5090:
	x[0] = a2fpc_1.qp5 * sqroot;
	goto L5100;
L5050:
	for (j = 1; j <= 2; ++j) {
/* L5060: */
	    tem[j - 1] = ((*acf * x[j] + *bcf) * x[j] + (*ccf - slope)) * x[j]
		     - vint;
	}
	if (tem[0] * tem[1] >= 0.) {
	    goto L5062;
	} else {
	    goto L5061;
	}
L5061:
	x[0] = (x[1] + x[2]) * a2fpc_1.qp5;
	goto L5100;
L5062:
	if (abs(tem[0]) - abs(tem[1]) >= 0.) {
	    goto L5064;
	} else {
	    goto L5063;
	}
L5063:
	x[0] = a2fpc_1.q1p2 * x[2] - a2fpc_1.qp2 * x[1];
	goto L5100;
L5064:
	x[0] = a2fpc_1.q1p2 * x[1] - a2fpc_1.qp2 * x[2];

/* ...  ITERATE FOR ROOT OF CUBIC */

L5100:
/* Computing MIN */
	d__1 = max(x[0],a2fpc_1.qnul);
	x[0] = min(d__1,sqroot);
	tem[0] = a2fpc_1.q3p * seg[2];
	tem[1] = a2fpc_1.q2p * seg[3];
	tem[2] = seg[4] - slope;
/* ... SET SPECIAL END OF INTERVAL SWITCH TO INITIAL(OFF) POSITION */
	intend = 0;
	for (m = 1; m <= 100; ++m) {
	    tem[3] = (tem[0] * x[0] + tem[1]) * x[0] + tem[2];
	    if (abs(tem[3]) - 1e-20 >= 0.) {
		goto L4009;
	    } else {
		goto L4008;
	    }
L4008:
	    x[0] += a2fpc_1.qp5x01;
	    goto L5200;
L4009:
	    tem[3] = (((*acf * x[0] + *bcf) * x[0] + (*ccf - slope)) * x[0] - 
		    vint) / tem[3];

/* ...  ACCEPT ROOT WHEN CORRECTION TERM IS LESS THAN .000001*X */

	    if (abs(tem[3]) - a2fpc_1.qp5x01 * abs(x[0]) >= 0.) {
		goto L5110;
	    } else {
		goto L5101;
	    }
/* ... TEST TO SEE IF X(1) IS IN RANGE OF INTERVAL */
L5101:
	    if (x[0] >= a2fpc_1.qnul && x[0] <= sqroot) {
		goto L5300;
	    }
/* ... NO,  OUT OF RANGE -- SEE IF SPECIAL END SWITCH ON */
	    if (intend != 0) {
		goto L5300;
	    }
/* ... TURN ON END SWITCH -- TRY ONE MORE TIME IF OUTNESS IS VERY SMALL */
	    intend = 1;
/* ... SET X(1) JUST INSIDE OF INTERVAL */
	    if (x[0] <= 0.) {
		goto L5102;
	    } else {
		goto L5103;
	    }
/* ... LOW END */
L5102:
	    x[0] = a2fpc_1.qp9x01;
	    goto L5200;
/* ... HIGH END */
L5103:
	    x[0] = sqroot - a2fpc_1.qp9x01;
	    goto L5200;
L5110:
	    x[0] -= tem[3];
L5200:
	    ;
	}
	aerr_(&c_n1501);
	goto L1000;

/* ...  IF THE ROOT IS WITHIN THE SEGMENT, */
/* ...  FACTOR OUT THE ROOT X,FOUND BY ITERATION, AND SOLVE */
/* ...  THE RESULTING QUADRATIC */

L5300:
	if (x[0] < 0.) {
	    goto L636;
	} else if (x[0] == 0) {
	    goto L641;
	} else {
	    goto L644;
	}
L636:
	j = 0;
	goto L642;
L644:
	if (x[0] - sqroot <= 0.) {
	    goto L641;
	} else {
	    goto L636;
	}
L48:
	l = j;
	k = 1;

/* ...  USING U COORD. OF INTERSECTION POINT,SOLVE CUBIC FOR V COORD. */

L514:
	seg[7] = ((*acf * x[k - 1] + *bcf) * x[k - 1] + *ccf) * x[k - 1];

/* ...  CALCULATE DIR. DIST. TO CUBIC AND TEST AGAINST PRESENT VALUE */

/* Computing 2nd power */
	d__1 = x[k - 1] - *upp;
/* Computing 2nd power */
	d__2 = seg[7] - *vpp;
	tem[0] = d__1 * d__1 + d__2 * d__2;
	if (tem[0] - s[*is - 1] >= 0.) {
	    goto L51;
	} else {
	    goto L49;
	}
L49:
	seg[8] = x[k - 1];
	j = 1;
	if ((x[k - 1] - *upp) * unn + (seg[7] - *vpp) * vnn >= 0.) {
	    goto L506;
	} else {
	    goto L50;
	}
L50:
	if (iop[(*iis - 1)] <= 0) {
	    goto L505;
	} else {
	    goto L51;
	}
L51:
	++k;
	if (l - k >= 0) {
	    goto L514;
	} else {
	    goto L1000;
	}
L1000:
	;
    }
    if (nmbseg - *ic - 14 != 0) {
	goto L510;
    } else {
	goto L511;
    }
L510:
    nwds = nmbseg - 7;
    nmbseg = *ic + 14;
    goto L550;
L511:
    if (iseg[OTHER_ENDIAN_S(3)] >= 0) {
	goto L1002;
    } else {
	goto L9000;
    }
/* ...  CALCULATE SURFACE NORMAL IN U-V-W COORD. SYSTEM */

L9000:
    tem[2] = atan((a2fpc_1.q3p * savpar[0] * savpar[6] + a2fpc_1.q2p * savpar[
	    1]) * savpar[6] + savpar[2]);
/* L513: */
    tem[3] = sin(tem[2]);
    tem[4] = cos(tem[2]);
    tem[0] = -savpar[3] * tem[4] - savpar[4] * tem[3];
    tem[1] = savpar[4] * tem[4] - savpar[3] * tem[3];
    k = *ic;
    for (i__ = 1; i__ <= 3; ++i__) {
	tem[i__ + 6] = d__[k + 4] * tem[0] + d__[k + 7] * tem[1];
/* L9001: */
	++k;
    }

/* ...  SAVE SEGMENT INDEX */

    kkk = iseg[OTHER_ENDIAN_S(1)] - *ic - 1;
    astor_(&kkk, &c__4, &d__[*ic + 3], &c__8);

/* ...  CALCULATE 3D DIRECTED DISTANCE */
/* Computing 2nd power */
    d__2 = savpar[7] - savpar[6];
/* Computing 2nd power */
    d__3 = savpar[8] - savpar[5];
/* Computing 2nd power */
    d__4 = un;
/* Computing 2nd power */
    d__5 = vn;
    d__1 = sqrt((d__2 * d__2 + d__3 * d__3) / (d__4 * d__4 + d__5 * d__5));
    s[*is - 1] = d_sign(&d__1, &gsign);
L29:
    return 0;

/* ...  UNABLE TO FIND DIRECTED DISTANCE */
L1002:
    *ier = 1;
    goto L29;
} /* addtb_ */

#undef cansto
#undef coss
#undef sinn
#undef iseg
#undef ibmb
#undef ibmc
#undef bibm
#undef ibma
#undef aibm
#undef vpp
#undef upp
#undef iop
#undef tem
#undef iis
#undef ier
#undef seg
#undef ccf
#undef bcf
#undef acf
#undef tp
#undef tn
#undef is
#undef ic
#undef h2
#undef g2
#undef x
#undef u
#undef s
#undef d__


