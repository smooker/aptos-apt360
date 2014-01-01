/* ALFTCN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <math.h> 
#include "f2c.h"
#include "endianmacs.h"
#ifdef WIN32
#include "isinf.h"
#endif

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__1 = 1;

doublereal alftcn_(m)
integer *m;
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val, d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer i__;
#define j ((integer *)&avst_1 + 12518)
    static integer k, l;
#define r__ ((doublereal *)&avst_1 + 6256)
#define a1 ((doublereal *)&avst_1 + 6243)
#define a2 ((doublereal *)&avst_1 + 6244)
#define a3 ((doublereal *)&avst_1 + 6245)
#define a4 ((doublereal *)&avst_1 + 6246)
#define b1 ((doublereal *)&avst_1 + 6247)
#define b2 ((doublereal *)&avst_1 + 6248)
#define b3 ((doublereal *)&avst_1 + 6249)
#define b4 ((doublereal *)&avst_1 + 6250)
#define c1 ((doublereal *)&avst_1 + 6251)
#define c2 ((doublereal *)&avst_1 + 6252)
#define c4 ((doublereal *)&avst_1 + 6254)
    static integer i1;
#define s1 ((doublereal *)&avst_1 + 6239)
#define s2 ((doublereal *)&avst_1 + 6240)
#define s3 ((doublereal *)&avst_1 + 6241)
#define s4 ((doublereal *)&avst_1 + 6242)
#define x1 ((doublereal *)&avst_1 + 6229)
#define y1 ((doublereal *)&avst_1 + 6230)
#define x2 ((doublereal *)&avst_1 + 6231)
#define y2 ((doublereal *)&avst_1 + 6232)
#define x3 ((doublereal *)&avst_1 + 6233)
#define y3 ((doublereal *)&avst_1 + 6234)
#define x4 ((doublereal *)&avst_1 + 6235)
#define y4 ((doublereal *)&avst_1 + 6236)
#define x5 ((doublereal *)&avst_1 + 6237)
#define y5 ((doublereal *)&avst_1 + 6238)
#define es ((doublereal *)&avst_1 + 6255)
#define cc3 ((doublereal *)&avst_1 + 6253)
#define len ((integer *)&avst_1 + 12558)
    static integer k000fx;
    extern /* Subroutine */ int dvchk_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
    extern /* Subroutine */ int agencn_();
#define defans ((doublereal *)&adfsto_1 + 3)
#define islope ((integer *)&avst_1 + 12516)

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* ...  LOFT CONIC ROUTINE FOR DEFPRE */
/* ...  UPON ENTERING THIS ROUTINE THE ACCUMULATOR WILL CONTAIN A FIXED */
/* ...  POINT NUMBER - 1,2,3,4,5 OR 6. */

/* ...  WHEN ACC. = 1, */
/* ...  LC = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5  $$ */

/* ...  WHEN ACC. = 2 */
/* ...  LC = LCONIC/5PT,SYM PT1,SYM PT2,SYM PT3,SYM PT4,SYM PT5 $$ */

/* ...  WHEN ACC. = 3 */
/* ...  LC = LCONIC/4PT1SL,X1,Y1,SLOPE VALUE,X2,Y2,X3,Y3,X4,Y4 $$ */

/* ...  WHEN ACC. = 4 */
/* ...  LC = LCONIC/4PT1SL,SYM PT1,SLOPE VALUE,SYM PT2,SYM PT3,SYM PT4 $$ */

/* ...  WHEN ACC. = 5 */
/* ...  LC = LCONIC/3PT2SL,X1,Y1,SLOPE 1,X2,Y2,SLOPE 2,X3,Y3 $$ */

/* ...  WHEN ACC. = 6 */
/* ...  LC = LCONIC/3PT2SL,SYM PT1,SLOPE 1,SYM PT2,SLOPE 2,SYM PT3 $$ */

/* *********************************************************************** */
    len[OTHER_ENDIAN_S(0)] = 12;
    len[OTHER_ENDIAN_S(1)] = 22;
    len[OTHER_ENDIAN_S(2)] = 11;
    len[OTHER_ENDIAN_S(3)] = 19;
    len[OTHER_ENDIAN_S(4)] = 10;
    len[OTHER_ENDIAN_S(5)] = 16;
/* L300: */
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L301;
	case 2:  goto L301;
    }
L301:
    if (idftab[OTHER_ENDIAN_S(1)] - len[OTHER_ENDIAN_S(*m - 1)] != 0) {
	goto L97;
    } else {
	goto L302;
    }
L302:
    switch ((int)*m) {
	case 1:  goto L303;
	case 2:  goto L312;
	case 3:  goto L305;
	case 4:  goto L306;
	case 5:  goto L307;
	case 6:  goto L308;
    }
L303:
    for (k = 3; k <= 12; ++k) {
/* L309: */
	deftab[k + 26] = deftab[k - 1];
    }
    goto L321;
L312:
    *j = 29;
    for (k = 3; k <= 19; k += 4) {
	for (i__ = 1; i__ <= 2; ++i__) {
	    l = k + i__;
	    ++(*j);
/* L313: */
	    deftab[*j - 1] = deftab[l - 1];
	}
    }
L321:
    *islope = 0;
    goto L310;
L305:
    *j = 29;
    for (k = 1; k <= 2; ++k) {
	for (l = 3; l <= 4; ++l) {
	    ++(*j);
/* L314: */
	    deftab[*j - 1] = deftab[l - 1];
	}
    }
    for (k = 6; k <= 11; ++k) {
/* L315: */
	deftab[k + 27] = deftab[k - 1];
    }
    deftab[39] = deftab[4];
    goto L320;
L306:
    *j = 29;
    for (k = 1; k <= 2; ++k) {
	for (i__ = 4; i__ <= 5; ++i__) {
	    ++(*j);
/* L318: */
	    deftab[*j - 1] = deftab[i__ - 1];
	}
    }
    *j = 33;
    for (k = 8; k <= 16; k += 4) {
	for (i__ = 1; i__ <= 2; ++i__) {
	    ++(*j);
	    i1 = k + i__;
/* L319: */
	    deftab[*j - 1] = deftab[i1 - 1];
	}
    }
    deftab[39] = deftab[6];
L320:
    *islope = 1;
    goto L310;
L307:
    *j = 29;
    for (k = 1; k <= 2; ++k) {
	for (i__ = 3; i__ <= 4; ++i__) {
	    ++(*j);
/* L322: */
	    deftab[*j - 1] = deftab[i__ - 1];
	}
    }
    deftab[33] = deftab[8];
    deftab[34] = deftab[9];
    *j = 35;
    for (k = 1; k <= 2; ++k) {
	for (i__ = 6; i__ <= 7; ++i__) {
	    ++(*j);
/* L323: */
	    deftab[*j - 1] = deftab[i__ - 1];
	}
    }
    deftab[39] = deftab[4];
    deftab[40] = deftab[7];
    goto L324;
L308:
    *j = 29;
    for (k = 1; k <= 2; ++k) {
	for (i__ = 4; i__ <= 5; ++i__) {
	    ++(*j);
/* L326: */
	    deftab[*j - 1] = deftab[i__ - 1];
	}
    }
    deftab[33] = deftab[13];
    deftab[34] = deftab[14];
    *j = 35;
    for (k = 1; k <= 2; ++k) {
	for (i__ = 9; i__ <= 10; ++i__) {
	    ++(*j);
/* L327: */
	    deftab[*j - 1] = deftab[i__ - 1];
	}
    }
    deftab[39] = deftab[6];
    deftab[40] = deftab[11];
L324:
    *islope = 2;
L310:
    if ((i__1 = *islope - 1) < 0) {
	goto L353;
    } else if (i__1 == 0) {
	goto L351;
    } else {
	goto L352;
    }

/* ...     5PT - CALCULATE ALL SLOPES */

L353:
//I believe the routine 'dvchk' was originally an assembly language routine
// to handle cases where the floating point value would overflow.  The 
//current routine called dvchk after a division to see if an overflow had 
//taken place and set the value of k000fx accordingly.  With the pseudo 
//numbers -inf and +inf,this is no longer necessary.

    *s1 = (*y2 - *y1) / (*x2 - *x1);
	if(isinf(*s1)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L328;
	case 2:  goto L351;
    }
L328:
    *s1 = (*y2 - *y1) / (d__1 = *y2 - *y1, abs(d__1)) * (float)1e5;
	if(isinf(*s1)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L98;
	case 2:  goto L351;
    }

/* ...     4PT1SL - CALCULATE 3 SLOPES */

L351:
    *s2 = (*y5 - *y4) / (*x5 - *x4);
	if(isinf(*s2)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L329;
	case 2:  goto L352;
    }
L329:
    *s2 = (*y5 - *y4) / (d__1 = *y5 - *y4, abs(d__1)) * (float)1e5;
	if(isinf(*s2)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L98;
	case 2:  goto L352;
    }

/* ...     3PT2SL - CALCULATE 2 SLOPES */

L352:
    *s3 = (*y4 - *y1) / (*x4 - *x1);
	if(isinf(*s3)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L330;
	case 2:  goto L331;
    }
L330:
    *s3 = (*y4 - *y1) / (d__1 = *y4 - *y1, abs(d__1)) * (float)1e5;
	if(isinf(*s3)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L98;
	case 2:  goto L331;
    }
L331:
    *s4 = (*y5 - *y2) / (*x5 - *x2);
	if(isinf(*s4)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L332;
	case 2:  goto L333;
    }
L332:
    *s4 = (*y5 - *y2) / (d__1 = *y5 - *y2, abs(d__1)) * (float)1e5;
	if(isinf(*s4)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L98;
	case 2:  goto L333;
    }
L333:
    *es = (float)1.;
    if (abs(*s1) - (float)1. <= 0.) {
	goto L335;
    } else {
	goto L334;
    }
L334:
/* Computing 2nd power */
    d__1 = *s1;
    *es = sqrt(d__1 * d__1 + (float)1.);
L335:
    *a1 = *s1 / *es;
    *b1 = (float)-1. / *es;
    if (abs(*b1) - (float)2e-5 >= 0.) {
	goto L337;
    } else {
	goto L336;
    }
L336:
    *b1 = (float)0.;
L337:
    *c1 = -(*a1) * *x1 - *b1 * *y1;
    *es = (float)1.;
    if (abs(*s2) - (float)1. <= 0.) {
	goto L339;
    } else {
	goto L338;
    }
L338:
/* Computing 2nd power */
    d__1 = *s2;
    *es = sqrt(d__1 * d__1 + (float)1.);
L339:
    *a2 = *s2 / *es;
    *b2 = (float)-1. / *es;
    if (abs(*b2) - (float)2e-5 >= 0.) {
	goto L341;
    } else {
	goto L340;
    }
L340:
    *b2 = (float)0.;
L341:
    *c2 = -(*a2) * *x5 - *b2 * *y5;
    *es = (float)1.;
    if (abs(*s3) - (float)1. <= 0.) {
	goto L343;
    } else {
	goto L342;
    }
L342:
/* Computing 2nd power */
    d__1 = *s3;
    *es = sqrt(d__1 * d__1 + (float)1.);
L343:
    *a3 = *s3 / *es;
    *b3 = (float)-1. / *es;
    if (abs(*b3) - (float)2e-5 >= 0.) {
	goto L345;
    } else {
	goto L344;
    }
L344:
    *b3 = (float)0.;
L345:
    *cc3 = -(*a3) * *x4 - *b3 * *y4;
    *es = (float)1.;
    if (abs(*s4) - (float)1. <= 0.) {
	goto L347;
    } else {
	goto L346;
    }
L346:
/* Computing 2nd power */
    d__1 = *s4;
    *es = sqrt(d__1 * d__1 + (float)1.);
L347:
    *a4 = *s4 / *es;
    *b4 = (float)-1. / *es;
    if (abs(*b4) - (float)2e-5 >= 0.) {
	goto L349;
    } else {
	goto L348;
    }
L348:
    *b4 = (float)0.;
L349:
    *c4 = -(*a4) * *x2 - *b4 * *y2;
    *r__ = -((*a1 * *x3 + *b1 * *y3 + *c1) * (*a2 * *x3 + *b2 * *y3 + *c2)) / 
	    ((*a3 * *x3 + *b3 * *y3 + *cc3) * (*a4 * *x3 + *b4 * *y3 + *c4));
	if(isinf(*r__)){k000fx=1;}else{k000fx=2;}
//    dvchk_(&k000fx);
    switch ((int)k000fx) {
	case 1:  goto L98;
	case 2:  goto L3490;
    }
L3490:
    if (*r__ != 0.) {
	goto L350;
    } else {
	goto L98;
    }

/* ...  SET UP DATA FOR GCON01 */

L350:
    deftab[1] = *a1 * *a2 + *r__ * *a3 * *a4;
    deftab[2] = *b1 * *a2 + *b2 * *a1 + *r__ * (*b3 * *a4 + *b4 * *a3);
    deftab[3] = *b1 * *b2 + *r__ * *b3 * *b4;
    deftab[4] = *c1 * *a2 + *c2 * *a1 + *r__ * (*cc3 * *a4 + *c4 * *a3);
    deftab[5] = *c1 * *b2 + *c2 * *b1 + *r__ * (*cc3 * *b4 + *c4 * *b3);
    deftab[6] = *c1 * *c2 + *r__ * *cc3 * *c4;
    agencn_(&c__1);
    goto L40;
L97:
    a1com_1.jsuber = 1001;
    goto L40;
L98:
    a1com_1.jsuber = 1005;
L40:
    ret_val = (doublereal) (*islope);
    return ret_val;
} /* alftcn_ */

#undef islope
#undef defans
#undef idftab
#undef deftab
#undef len
#undef cc3
#undef es
#undef y5
#undef x5
#undef y4
#undef x4
#undef y3
#undef x3
#undef y2
#undef x2
#undef y1
#undef x1
#undef s4
#undef s3
#undef s2
#undef s1
#undef c4
#undef c2
#undef c1
#undef b4
#undef b3
#undef b2
#undef b1
#undef a4
#undef a3
#undef a2
#undef a1
#undef r__
#undef j


