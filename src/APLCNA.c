/* APLCNA.f -- translated by f2c (version 20000121).
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

static integer c__2080 = 2080;
static integer c__9100 = 9100;

/* Subroutine */ int aplcna_(iarg)
integer *iarg;
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
#define cbar ((doublereal *)&aplcnc_1 + 171)
    static doublereal area;
#define delp ((doublereal *)&aplcnc_1 + 167)
#define delr ((doublereal *)&aplcnc_1 + 174)
#define delm ((doublereal *)&aplcnc_1 + 177)
#define rhoc ((doublereal *)&aplcnc_1 + 145)
#define rlam ((doublereal *)&aplcnc_1 + 185)
#define zlcp ((doublereal *)&aplcnc_1 + 150)
    static doublereal sqds, epsr;
#define jswl ((integer *)&aplcnc_1 + 459)
#define uprm ((doublereal *)&aplcnc_1 + 155)
#define wprm ((doublereal *)&aplcnc_1 + 156)
    static integer jswp;
#define d__ ((doublereal *)&a2cmmn_1 + 1408)
#define a ((doublereal *)&aplcnc_1 + 15)
#define b ((doublereal *)&aplcnc_1 + 23)
#define c__ ((doublereal *)&aplcnc_1 + 31)
#define h__ ((doublereal *)&aplcnc_1 + 55)
    static integer i__, j;
#define p ((doublereal *)&aplcnc_1 + 157)
    static doublereal q[3];
#define r__ ((doublereal *)&aplcnc_1 + 127)
    static doublereal s[3];
#define t ((doublereal *)&aplcnc_1 + 12)
    static integer l;
    static doublereal v[3];
#define deldt ((doublereal *)&aplcnc_1 + 137)
    static integer k;
#define idcnt ((integer *)&aplcnc_1 + 454)
#define ipcer ((integer *)&aplcnc_1 + 456)
#define zlamc ((doublereal *)&aplcnc_1 + 170)
#define rhocp ((doublereal *)&aplcnc_1 + 152)
#define zlamn ((doublereal *)&aplcnc_1 + 163)
#define amult ((doublereal *)&aplcnc_1 + 78)
#define bmult ((doublereal *)&aplcnc_1 + 85)
#define cmult ((doublereal *)&aplcnc_1 + 92)
#define dmult ((doublereal *)&aplcnc_1 + 99)
#define rvlam ((doublereal *)&aplcnc_1 + 186)
#define trans ((doublereal *)&aplcnc_1)
#define sqphi ((doublereal *)&aplcnc_1 + 187)
#define hmult ((doublereal *)&aplcnc_1 + 113)
#define roots ((doublereal *)&aplcnc_1 + 71)
#define epsil4 ((doublereal *)&aplcnc_1 + 202)
#define ac ((doublereal *)&aplcnc_1 + 139)
#define bc ((doublereal *)&aplcnc_1 + 140)
#define cc ((doublereal *)&aplcnc_1 + 141)
#define dc ((doublereal *)&aplcnc_1 + 142)
#define cb ((doublereal *)&aplcnc_1 + 13)
#define hc ((doublereal *)&aplcnc_1 + 144)
#define am ((doublereal *)&aplcnc_1 + 15)
#define pb ((doublereal *)&aplcnc_1 + 14)
#define pc ((doublereal *)&aplcnc_1 + 164)
#define ds ((doublereal *)&aplcnc_1 + 138)
#define dt ((doublereal *)&aplcnc_1 + 136)
#define du ((doublereal *)&aplcnc_1 + 182)
#define uc ((doublereal *)&aplcnc_1 + 196)
#define dw ((doublereal *)&aplcnc_1 + 183)
#define wc ((doublereal *)&aplcnc_1 + 199)
    extern /* Subroutine */ int aplcnb_();
#define rs ((doublereal *)&aplcnc_1 + 133)
#define un ((doublereal *)&aplcnc_1 + 160)
    static doublereal zm[3];
#define rv ((doublereal *)&aplcnc_1 + 130)
#define zl ((doublereal *)&aplcnc_1 + 47)
#define up ((doublereal *)&aplcnc_1 + 153)
#define wp ((doublereal *)&aplcnc_1 + 154)
#define iddcnt ((integer *)&aplcnc_1 + 455)
#define dd1 ((doublereal *)&aplcnc_1 + 180)
#define dd2 ((doublereal *)&aplcnc_1 + 181)
#define iuncnt ((integer *)&aplcnc_1 + 457)
#define rhomul ((doublereal *)&aplcnc_1 + 120)
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
    static doublereal tsf, urv, wrv, wkh, tsg;

/*     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 *** */





    *iuncnt = 10;
    *iddcnt = 25;
    *jswl = 4;
L3000:
    for (i__ = 1; i__ <= 7; ++i__) {
	j = 7;
	jswp = 1;


/* ....    SECTION 3 POLCON CONTROL COMPUTATIONS */

	l = i__ * 7;
	k = l + i__;
	ac[i__ - 1] = am[k - 1];
	acp[i__ - 1] = amult[l - 1];
	goto L3001;
L3002:
	--l;
	acp[i__ - 1] = acp[i__ - 1] * *ds + amult[l - 1];
L3001:
	--k;
	ac[i__ - 1] = ac[i__ - 1] * *ds + am[k - 1];
	--j;
	if ((i__1 = j - 1) < 0) {
	    goto L3004;
	} else if (i__1 == 0) {
	    goto L3001;
	} else {
	    goto L3002;
	}
L3004:
	acp[i__ - 1] *= *ds;
    }
    if (*cc * *dc != ac[0] * *bc) {
	goto L37;
    }
    if (*cc != a2fpc_1.qnul) {
	goto L36;
    }
    *cc += a2fpc_1.qp5x01;
    ac[0] -= a2fpc_1.qp5x01;
    goto L37;
L36:
    *bc += a2fpc_1.qp5x01;
    *dc -= a2fpc_1.qp5x01;
L37:
    if (*jroots == 1) {
	goto L3050;
    }
    if (*ds <= 0.) {
	goto L3075;
    } else {
	goto L3085;
    }
L3075:
    *ds = a2fpc_1.q15x01;
    sqds = a2fpc_1.qp7x01;
    *iuncnt = 0;
    *iddcnt = 0;
    *jswl = 4;
    goto L3110;
L3085:
    sqds = sqrt(*ds);
L3110:
    *tsa = sqds * *fac;
    *tsb = *fac / sqds;
    for (i__ = 1; i__ <= 7; ++i__) {
	ac[i__ - 1] += roots[i__ - 1] * *tsa;
/* L3086: */
	acp[i__ - 1] += amult[i__ * 7 - 7] * *tsb;
    }
L3050:
    for (i__ = 1; i__ <= 7; ++i__) {
/* L3051: */
	acp[i__ - 1] = (acp[i__ - 1] + am[(i__ << 3) - 7]) / *pb;
    }
    if (*iarg != 0) {
	return 0;
    }
    *rhoc = max(*rhoc,.5000005);
    if ((d__1 = *rhoc - a2fpc_1.q1p, abs(d__1)) <= a2fpc_1.qp5x01) {
	*rhoc = a2fpc_1.qp6x9;
    }
    *sqphi = a2fpc_1.q1p / (a2fpc_1.q1p - *rhoc) - a2fpc_1.q2p;
/* Computing 2nd power */
    d__1 = *sqphi;
    *phi = d__1 * d__1;
    area = ac[0] * *bc - *cc * *dc;
    if (area == a2fpc_1.qnul) {
	area = a2fpc_1.qp7x01;
    }
    *tsc = ac[0] / area;
    *tsd = *bc / area;
    *tse = *cc / area;
    tsf = *dc / area;
    urv = *tsd * (rv[1] - *zlc) - *tse * (rv[2] - *hc);
    wrv = *tsc * (rv[2] - *hc) - tsf * (rv[1] - *zlc);
    *urs = *tsd * (rs[1] - *zlc) - *tse * (rs[2] - *hc);
    *wrs = *tsc * (rs[2] - *hc) - tsf * (rs[1] - *zlc);
    *uc = *tsd * (cbar[1] - *zlc) - *tse * (cbar[2] - *hc);
    *wc = *tsc * (cbar[2] - *hc) - tsf * (cbar[1] - *zlc);
    wkh = ac[0] * *cc + *bc * *dc;
/* Computing 2nd power */
    d__1 = *bc;
/* Computing 2nd power */
    d__2 = *cc;
    *ukp = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = ac[0];
/* Computing 2nd power */
    d__2 = *dc;
    *wkp = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = area;
    *tsc = (*wkp + wkh) / (d__1 * d__1);
    *tsd = *ukp * *tsc;
    *tse = -wkh * *tsc;
    tsf = urv + urv;
    tsg = wrv + wrv;
    *tsj = wkh + wkh;
    *tsh = tsf * wkh + tsg * *ukp;
    *tsi = tsg * wkh + tsf * *wkp;

/*      CALL APLCNB (&2080,&9100) */
/* 	TODO: fix this */
    aplcnb_(&c__2080, &c__9100);


/* ...    SECTION 6 ... UNIT NORMAL */

    q[2] = acp[5] + *bc * *wprm + *dc * *uprm + acp[1] * *wp + acp[3] * *up;
    q[1] = acp[4] + ac[0] * *uprm + *cc * *wprm + acp[0] * *up + acp[2] * *wp;
    q[0] = a2fpc_1.qnul;
    if (abs(q[1]) + abs(q[2]) < a2fpc_1.q1pe6) {
	q[0] = a2fpc_1.q1p;
    }
    s[0] = a2fpc_1.qnul;
    *du = *phi * *up + *tsb;
    *dw = *phi - *phi * *wp + *tsb;
    s[2] = *bc * *dw + *dc * *du;
    s[1] = ac[0] * *du + *cc * *dw;
    un[0] = s[1] * q[2] - s[2] * q[1];
    un[1] = s[2] * q[0];
    un[2] = -s[1] * q[0];
/* Computing 2nd power */
    d__1 = un[0];
/* Computing 2nd power */
    d__2 = un[1];
/* Computing 2nd power */
    d__3 = un[2];
    tem[0] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    tem[1] = a2fpc_1.qnul;
    *zlamn = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
	un[i__ - 1] /= tem[0];
	zm[i__ - 1] = p[i__ - 1] - rv[i__ - 1];
/* Computing 2nd power */
	d__1 = zm[i__ - 1];
	tem[1] += d__1 * d__1;
/* L6010: */
	*zlamn += zm[i__ - 1] * un[i__ - 1];
    }
    if (tem[1] <= a2fpc_1.qp0005) {
	goto L6020;
    }
    tem[0] = a2fpc_1.qnul;
    tem[1] = sqrt(tem[1]);
    for (i__ = 1; i__ <= 3; ++i__) {
	delm[i__ - 1] = zm[i__ - 1] / tem[1];
/* L6031: */
	tem[0] += un[i__ - 1] * delm[i__ - 1];
    }
    if (abs(tem[0]) >= .999) {
	goto L6020;
    }
    if (*iuncnt <= 0) {
	goto L9100;
    }
    --(*iuncnt);
L6051:
    if (jswp == 1) {
	goto L6070;
    }
    tem[0] = a2fpc_1.qnul;
    tem[1] = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
	delp[i__ - 1] = pc[i__ - 1] - p[i__ - 1];
/* Computing 2nd power */
	d__1 = delp[i__ - 1];
	tem[1] += d__1 * d__1;
/* L6061: */
	tem[0] += un[i__ - 1] * delp[i__ - 1];
    }
    tem[0] += tem[0];
    if (*jroots == 1) {
	goto L6063;
    }
    if (*ds > a2fpc_1.qp0001) {
	goto L6066;
    }
    epsr = a2fpc_1.qp7x01;
    goto L6067;
L6066:
    epsr = a2fpc_1.qp5x01;
    goto L6067;
L6063:
    epsr = a2fpc_1.qp4x01;
L6067:
/* Computing MIN */
    d__1 = tem[1], d__2 = abs(tem[0]);
    if (min(d__1,d__2) <= epsr) {
	goto L6071;
    }
    *zlamc = tem[1] / tem[0];
    goto L6072;
L6070:
    jswp = 2;
L6071:
    *zlamc = -a2fpc_1.q4500p;
L6072:
    tem[3] = a2fpc_1.qnul;
    *jswl = 3;
    for (i__ = 1; i__ <= 3; ++i__) {
	cbar[i__ - 1] = p[i__ - 1] + *zlamc * un[i__ - 1];
	v[i__ - 1] = rv[i__ - 1] - cbar[i__ - 1];
/* L6073: */
/* Computing 2nd power */
	d__1 = v[i__ - 1];
	tem[3] += d__1 * d__1;
    }
    if (tem[3] <= a2fpc_1.qp0001) {
	goto L6082;
    }
    tem[4] = a2fpc_1.qnul;
    tem[3] = sqrt(tem[3]);
    for (i__ = 1; i__ <= 3; ++i__) {
	v[i__ - 1] /= tem[3];
/* L6075: */
	tem[4] += v[i__ - 1] * un[i__ - 1];
    }
    tem[4] *= *zlamc;
    tem[0] = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
	if (tem[4] > a2fpc_1.qnul) {
	    v[i__ - 1] = -v[i__ - 1];
	}
/* L6079: */
	tem[0] += v[i__ - 1] * un[i__ - 1];
    }
    if (abs(tem[0]) < a2fpc_1.qp7) {
	goto L6082;
    }
    tem[0] = abs(*zlamc);
    for (i__ = 1; i__ <= 3; ++i__) {
	pc[i__ - 1] = p[i__ - 1];
/* L6081: */
	rs[i__ - 1] = cbar[i__ - 1] + tem[0] * v[i__ - 1];
    }
    goto L6120;
L6082:
    *jswl = 2;
    for (i__ = 1; i__ <= 3; ++i__) {
	pc[i__ - 1] = p[i__ - 1];
/* L6083: */
	rs[i__ - 1] = *zlamn * un[i__ - 1] + rv[i__ - 1];
    }
L6120:
    *ds = rs[0] / *pb;
    if (*jroots == 1 || *ds >= a2fpc_1.qnul) {
	goto L3000;
    }
    rs[0] = p[0] * .00990099;
    *fac = -(*fac);
    goto L6120;
L6020:
    *iuncnt = 10;


/* ...   SECTION 7 DIRECTED DISTANCE */

    tem[0] = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L7021: */
	tem[0] += delr[i__ - 1] * un[i__ - 1];
    }
    if (abs(tem[0]) < a2fpc_1.qp4x01) {
	goto L2080;
    }
    *rvlam = (*zlamn + *t) / tem[0];
    if (a2cmmn_1.iop[a2cmmn_1.iis - 1] != 0) {
	goto L7035;
    } else {
	goto L7070;
    }
L7070:
    *rlam += *rvlam;
    goto L7075;
L7035:
    if (abs(delr[0]) > a2fpc_1.qp4x01 && (d__1 = *pb / delr[0], abs(d__1)) < 
	    abs(*rvlam)) {
	goto L2080;
    }
    tem[0] = *rlam + *rvlam;
    if (tem[0] + a2fpc_1.qp01 >= 0.) {
	goto L7060;
    } else {
	goto L2080;
    }
L7060:
    *rlam = tem[0];
L7075:
    if ((d__1 = *zlamn + *t, abs(d__1)) > a2fpc_1.qp0001) {
	goto L7080;
    }
    if (a2cmmn_1.iop[a2cmmn_1.iis - 1] == 0 || *rlam >= a2fpc_1.qnul) {
	return 0;
    }
L7080:
    if (*iddcnt <= 0) {
	goto L9100;
    }
    --(*iddcnt);
    *zlamn = a2fpc_1.qnul;
    for (i__ = 1; i__ <= 3; ++i__) {
	rv[i__ - 1] = *rlam * delr[i__ - 1] + r__[i__ - 1];
/* L7091: */
	rs[i__ - 1] = rv[i__ - 1] - *t * un[i__ - 1];
    }
    goto L6051;
L2080:
    return 1;
L9100:
    return 2;
} /* aplcna_ */

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


