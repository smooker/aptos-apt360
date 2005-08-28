/* APLCN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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

struct {
    doublereal sp[3], sn[3], tp[3], tn[3], ahold[57], zmvmag[1], bhold[30], 
	    afillr[500];
    integer ihold[9], iop[1], ihold1[21], ifillr[209];
    doublereal chold[39], vtem[3], dhold[12], vnul[3], ehold[111], dpmax, 
	    fhold[367];
    integer is, iis, ihold2[85], ic, ihold3[16];
    doublereal probuf[100], cansto[2000];
    integer ier, ihold4[9];
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

struct {
    doublereal poldat[127], calc[100];
    integer ipolcm[12];
} aplcnc_;

#define aplcnc_1 aplcnc_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2100 = 2100;
static integer c__0 = 0;
static integer c__2080 = 2080;
static integer c__9100 = 9100;

/* Subroutine */ int aplcn_(jundd)
integer *jundd;
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
#define cbar ((doublereal *)&aplcnc_1 + 171)
#define delp ((doublereal *)&aplcnc_1 + 167)
#define delr ((doublereal *)&aplcnc_1 + 174)
#define delm ((doublereal *)&aplcnc_1 + 177)
#define rhoc ((doublereal *)&aplcnc_1 + 145)
#define rlam ((doublereal *)&aplcnc_1 + 185)
    static integer ians, item;
#define zlcp ((doublereal *)&aplcnc_1 + 150)
    static integer jswh;
#define jswl ((integer *)&aplcnc_1 + 459)
#define uprm ((doublereal *)&aplcnc_1 + 155)
#define wprm ((doublereal *)&aplcnc_1 + 156)
#define d__ ((doublereal *)&a2cmmn_1 + 1408)
#define a ((doublereal *)&aplcnc_1 + 15)
#define b ((doublereal *)&aplcnc_1 + 23)
#define c__ ((doublereal *)&aplcnc_1 + 31)
#define h__ ((doublereal *)&aplcnc_1 + 55)
    static integer i__, j;
#define p ((doublereal *)&aplcnc_1 + 157)
#define r__ ((doublereal *)&aplcnc_1 + 127)
#define t ((doublereal *)&aplcnc_1 + 12)
#define deldt ((doublereal *)&aplcnc_1 + 137)
#define idcnt ((integer *)&aplcnc_1 + 454)
#define ipcer ((integer *)&aplcnc_1 + 456)
#define zlamc ((doublereal *)&aplcnc_1 + 170)
#define rhocp ((doublereal *)&aplcnc_1 + 152)
    extern /* Subroutine */ int avdot_();
#define zlamn ((doublereal *)&aplcnc_1 + 163)
#define amult ((doublereal *)&aplcnc_1 + 78)
#define bmult ((doublereal *)&aplcnc_1 + 85)
#define cmult ((doublereal *)&aplcnc_1 + 92)
#define dmult ((doublereal *)&aplcnc_1 + 99)
#define rvlam ((doublereal *)&aplcnc_1 + 186)
#define trans ((doublereal *)&aplcnc_1)
#define sqphi ((doublereal *)&aplcnc_1 + 187)
#define hmult ((doublereal *)&aplcnc_1 + 113)
    static doublereal znlam;
    extern /* Subroutine */ int avsto_();
#define roots ((doublereal *)&aplcnc_1 + 71)
#define epsil4 ((doublereal *)&aplcnc_1 + 202)
#define ac ((doublereal *)&aplcnc_1 + 139)
#define bc ((doublereal *)&aplcnc_1 + 140)
#define cc ((doublereal *)&aplcnc_1 + 141)
#define dc ((doublereal *)&aplcnc_1 + 142)
#define cb ((doublereal *)&aplcnc_1 + 13)
#define hc ((doublereal *)&aplcnc_1 + 144)
#define am ((doublereal *)&aplcnc_1 + 15)
    static integer ih;
#define pb ((doublereal *)&aplcnc_1 + 14)
#define pc ((doublereal *)&aplcnc_1 + 164)
    static doublereal dr[3];
#define ds ((doublereal *)&aplcnc_1 + 138)
#define dt ((doublereal *)&aplcnc_1 + 136)
#define du ((doublereal *)&aplcnc_1 + 182)
#define uc ((doublereal *)&aplcnc_1 + 196)
#define dw ((doublereal *)&aplcnc_1 + 183)
#define wc ((doublereal *)&aplcnc_1 + 199)
    static integer kk;
    extern /* Subroutine */ int aplcna_();
#define rs ((doublereal *)&aplcnc_1 + 133)
#define un ((doublereal *)&aplcnc_1 + 160)
#define rv ((doublereal *)&aplcnc_1 + 130)
#define zl ((doublereal *)&aplcnc_1 + 47)
#define up ((doublereal *)&aplcnc_1 + 153)
#define wp ((doublereal *)&aplcnc_1 + 154)
#define iddcnt ((integer *)&aplcnc_1 + 455)
#define dd1 ((doublereal *)&aplcnc_1 + 180)
#define dd2 ((doublereal *)&aplcnc_1 + 181)
#define iuncnt ((integer *)&aplcnc_1 + 457)
    static integer jtrans;
#define rhomul ((doublereal *)&aplcnc_1 + 120)
    static integer kk1, kk2;
#define jroots ((integer *)&aplcnc_1 + 458)
#define zlmult ((doublereal *)&aplcnc_1 + 106)
#define fac ((doublereal *)&aplcnc_1 + 203)
#define acp ((doublereal *)&aplcnc_1 + 146)
#define bcp ((doublereal *)&aplcnc_1 + 147)
#define ccp ((doublereal *)&aplcnc_1 + 148)
#define dcp ((doublereal *)&aplcnc_1 + 149)
#define hcp ((doublereal *)&aplcnc_1 + 151)
#define phi ((doublereal *)&aplcnc_1 + 184)
#define tem ((doublereal *)&aplcnc_1 + 204)
#define rho ((doublereal *)&aplcnc_1 + 63)
#define zlc ((doublereal *)&aplcnc_1 + 143)
#define tsa ((doublereal *)&aplcnc_1 + 188)
#define tsb ((doublereal *)&aplcnc_1 + 189)
#define tsc ((doublereal *)&aplcnc_1 + 190)
#define tsd ((doublereal *)&aplcnc_1 + 191)
#define tse ((doublereal *)&aplcnc_1 + 192)
#define tsh ((doublereal *)&aplcnc_1 + 193)
#define tsi ((doublereal *)&aplcnc_1 + 194)
#define tsj ((doublereal *)&aplcnc_1 + 195)
#define ukp ((doublereal *)&aplcnc_1 + 197)
#define urs ((doublereal *)&aplcnc_1 + 198)
#define wkp ((doublereal *)&aplcnc_1 + 200)
#define wrs ((doublereal *)&aplcnc_1 + 201)
    static doublereal ans;

/*     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 *** */
/* 2350 POLYCONIC,  SYSTEM/360 SECTION 2 APT */
/*     JUNDD=1 FOR UNIT NORMAL          JUNDD=2 FOR DIRECTED DISTANCE */
/*     TEST IF FIRST TIME IN FOR THIS SURFACE */





    ans = d__[a2cmmn_1.ic - 1];
    ians = (integer) (ans + a2fpc_1.qp01);
    if (ians - 130 != 0) {
	goto L100;
    } else {
	goto L200;
    }
/*      IF FIRST TIME, CALCULATE 1ST DERIVATIVE COEFF. */
L100:
    i__ = a2cmmn_1.ic + 83;
    j = a2cmmn_1.ic + 21;
    tem[0] = a2fpc_1.q2p;
L101:
    for (kk = 1; kk <= 7; ++kk) {
	kk1 = (kk - 1) * 7;
	kk2 = kk - 1 << 3;
	d__[i__ + kk1 - 1] = tem[0] * d__[j + kk2 - 1];
/* L111: */
    }

    ++i__;
    ++j;
    tem[0] += a2fpc_1.q1p;
    item = (integer) (tem[0] + a2fpc_1.qp01);
    if (item - 8 != 0) {
	goto L101;
    } else {
	goto L102;
    }
/*      IF SQUARE ROOT TERMS, CALC COEFF */
L102:
    *jroots = (integer) ((d__1 = d__[a2cmmn_1.ic + 2], abs(d__1)) + 
	    a2fpc_1.qp01);
    if (*jroots != 2) {
	goto L105;
    }
/* L103: */
    i__ = a2cmmn_1.ic + 82;
    j = a2cmmn_1.ic + 75;
L104:
    d__[i__ - 1] = d__[j - 1] / a2fpc_1.q2p;
    i__ += 7;
    ++j;
    if (j - a2cmmn_1.ic - 82 != 0) {
	goto L104;
    } else {
	goto L105;
    }
/*      SET CANONICAL FORM LEG TO 130 */
L105:
    d__[a2cmmn_1.ic - 1] = a2fpc_1.q130p;


/*      END OF FIRST TIME ONLY CALC */

L200:
    *jroots = (integer) ((d__1 = d__[a2cmmn_1.ic + 2], abs(d__1)) + 
	    a2fpc_1.qp01);
/*      NAME = BLOCK1(IC+1) */
/*      TRANSFER CANONICAL FORM FROM CANSTO TO POLDAT */
    j = a2cmmn_1.ic + 4;
    for (i__ = 1; i__ <= 127; ++i__) {
	aplcnc_1.poldat[i__ - 1] = d__[j - 1];
/* L201: */
	++j;
    }


/* ...  SECTION 1 ... ENTRY */

    jtrans = 2;
    if (trans[0] == 0. && trans[1] == 0. && trans[2] == 0.) {
	jtrans = 1;
    }
    if (*jundd == 1) {
	if (jtrans - 1 <= 0) {
	    goto L8050;
	} else {
	    goto L8051;
	}
    }
    jswh = 1;
    if (jtrans == 2) {
	goto L1085;
    }
/* L1080: */
    for (i__ = 1; i__ <= 3; ++i__) {
	ih = a2cmmn_1.is - 1 + i__;
	delr[i__ - 1] = a2cmmn_1.tn[ih - 1];
/* L1021: */
	r__[i__ - 1] = a2cmmn_1.tp[ih - 1];
    }
    goto L1090;
L1085:
    for (i__ = 1; i__ <= 3; ++i__) {
	ih = a2cmmn_1.is - 1 + i__;
	a2cmmn_1.vtem[i__ - 1] = a2cmmn_1.tp[ih - 1];
/* L1075: */
	dr[i__ - 1] = a2cmmn_1.tn[ih - 1];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ih = i__ << 2;
	avdot_(a2cmmn_1.vtem, &trans[ih - 4], &r__[i__ - 1]);
	r__[i__ - 1] += trans[ih - 1];
/* L1095: */
	avdot_(dr, &trans[ih - 4], &delr[i__ - 1]);
    }
L1090:
    r__[0] -= *cb;


/* ...  SECTION 2  D SELECTION */

L2000:
    *rlam = a2fpc_1.qnul;
    *fac = a2fpc_1.q1p;
    *idcnt = 5;
    for (i__ = 1; i__ <= 3; ++i__) {
	rs[i__ - 1] = r__[i__ - 1];
	cbar[i__ - 1] = r__[i__ - 1];
/* L2010: */
	rv[i__ - 1] = r__[i__ - 1];
    }
    *ds = rs[0] / *pb;
    if (*ds <= a2fpc_1.q1p) {
	goto L2030;
    }
    *ds = a2fpc_1.q1p;
    *deldt = -a2fpc_1.qp25;
    goto L2060;
L2030:
    if (*ds >= 0.) {
	goto L2110;
    } else {
	goto L2040;
    }
L2040:
    *ds = a2fpc_1.qp0001;
    *deldt = a2fpc_1.qp25;
L2060:
    *dt = a2fpc_1.qnul;
/* ...    INITIALIZE AC(I) */
/* 	&'s could be address I guess.. */
/*      CALL APLCNA (1,&2100,&2100) */
    aplcna_(&c__1, &c__2100, &c__2100);
    goto L2100;
L2110:
    if (*ds <= a2fpc_1.qp5) {
	goto L2150;
    }
    *dt = a2fpc_1.q1p25;
    *deldt = -a2fpc_1.qp25;
    goto L2180;
L2150:
    *ds = max(*ds,a2fpc_1.qp0001);
    *dt = -a2fpc_1.qp2499;
    *deldt = a2fpc_1.qp25;
    goto L2180;
/* L2080: */
    *dt += *deldt;
    *ds = *dt;
L2100:
    if (abs(delr[0]) < a2fpc_1.qp5x01) {
	goto L2220;
    }
    *rvlam = (*pb * *ds - rv[0]) / delr[0];
    for (i__ = 1; i__ <= 3; ++i__) {
	rs[i__ - 1] = *rvlam * delr[i__ - 1] + rv[i__ - 1];
/* L2211: */
	rv[i__ - 1] = rs[i__ - 1];
    }
    goto L2270;
L2220:
    if (*ds != *dt && *jroots == 2 && *deldt > a2fpc_1.qnul) {
	goto L9100;
    }
/* Computing 2nd power */
    d__1 = *zlc - rv[1];
/* Computing 2nd power */
    d__2 = *hc - rv[2];
    znlam = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = *zlc + ac[0] + *cc - rv[1];
/* Computing 2nd power */
    d__2 = *hc + *bc + *dc - rv[2];
    *rvlam = d__1 * d__1 + d__2 * d__2;
    *rvlam = sqrt((max(znlam,*rvlam)));
    for (i__ = 1; i__ <= 3; ++i__) {
	rv[i__ - 1] += *rvlam * delr[i__ - 1];
/* L2261: */
	rs[i__ - 1] = rv[i__ - 1] - *t * un[i__ - 1];
    }
    *ds = rs[0] / *pb;
L2270:
    *rlam += *rvlam;
    *dt = *ds;
    if (*idcnt <= 0) {
	goto L9100;
    }
    --(*idcnt);

/* 2180 CALL APLCNA (0,&2080,&9100) */
/* 	not sure what the &'s are for */
L2180:
    aplcna_(&c__0, &c__2080, &c__9100);


/* ... SECTION 8 ACCEPTANCE TESTS AND NORMAL EXIT */

    tem[0] = a2cmmn_1.dpmax / *pb;
    if (*ds + tem[0] < a2fpc_1.qnul || a2fpc_1.q1p + tem[0] < *ds) {
	goto L9100;
    }
    if (a2cmmn_1.iop[a2cmmn_1.iis - 1] != 0) {
	goto L8070;
    } else {
	goto L8080;
    }
L9100:
    a2cmmn_1.ier = 1;
    goto L9200;
L8050:
    avsto_(un, &a2cmmn_1.sn[a2cmmn_1.is - 1]);
    goto L8160;
L8051:
    a2cmmn_1.sn[a2cmmn_1.is - 1] = un[0] * trans[0] + un[1] * trans[4] + un[2]
	     * trans[8];
    a2cmmn_1.sn[a2cmmn_1.is] = un[0] * trans[1] + un[1] * trans[5] + un[2] * 
	    trans[9];
    a2cmmn_1.sn[a2cmmn_1.is + 1] = un[0] * trans[2] + un[1] * trans[6] + un[2]
	     * trans[10];
    goto L8160;
L8070:
    a2cmmn_1.zmvmag[a2cmmn_1.is - 1] = *rvlam;
    goto L8160;
L8080:
    if (jswh == 2) {
	goto L8100;
    }
    *dd1 = *rlam;
    if (*rlam != a2fpc_1.q1pe20) {
	goto L8094;
    }
    delr[0] = -delr[0];
    delr[1] = -delr[1];
    delr[2] = -delr[2];
    jswh = 2;
    goto L2000;
L8094:
    *rlam = a2fpc_1.q1pe20;
L8100:
    *dd2 = *rlam;
    a2cmmn_1.zmvmag[a2cmmn_1.is - 1] = -(*dd2);
    if (*dd1 == a2fpc_1.q1pe20) {
	if (*dd2 - a2fpc_1.q1pe20 != 0.) {
	    goto L8160;
	} else {
	    goto L9100;
	}
    }
    if (*dd2 == a2fpc_1.q1pe20 || abs(*dd1) <= abs(*dd2)) {
	a2cmmn_1.zmvmag[a2cmmn_1.is - 1] = *dd1;
    }
L8160:
    a2cmmn_1.ier = 0;
L9200:
    return 0;
} /* aplcn_ */

#undef wrs
#undef wkp
#undef urs
#undef ukp
#undef tsj
#undef tsi
#undef tsh
#undef tse
#undef tsd
#undef tsc
#undef tsb
#undef tsa
#undef zlc
#undef rho
#undef tem
#undef phi
#undef hcp
#undef dcp
#undef ccp
#undef bcp
#undef acp
#undef fac
#undef zlmult
#undef jroots
#undef rhomul
#undef iuncnt
#undef dd2
#undef dd1
#undef iddcnt
#undef wp
#undef up
#undef zl
#undef rv
#undef un
#undef rs
#undef wc
#undef dw
#undef uc
#undef du
#undef dt
#undef ds
#undef pc
#undef pb
#undef am
#undef hc
#undef cb
#undef dc
#undef cc
#undef bc
#undef ac
#undef epsil4
#undef roots
#undef hmult
#undef sqphi
#undef trans
#undef rvlam
#undef dmult
#undef cmult
#undef bmult
#undef amult
#undef zlamn
#undef rhocp
#undef zlamc
#undef ipcer
#undef idcnt
#undef deldt
#undef t
#undef r__
#undef p
#undef h__
#undef c__
#undef b
#undef a
#undef d__
#undef wprm
#undef uprm
#undef jswl
#undef zlcp
#undef rlam
#undef rhoc
#undef delm
#undef delr
#undef delp
#undef cbar


