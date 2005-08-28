/* APLCNB.f -- translated by f2c (version 20000121).
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

/* Subroutine */ int aplcnb_()
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
#define a ((doublereal *)&aplcnc_1 + 15)
#define b ((doublereal *)&aplcnc_1 + 23)
#define c__ ((doublereal *)&aplcnc_1 + 31)
#define d__ ((doublereal *)&a2cmmn_1 + 1408)
#define h__ ((doublereal *)&aplcnc_1 + 55)
#define p ((doublereal *)&aplcnc_1 + 157)
#define r__ ((doublereal *)&aplcnc_1 + 127)
#define t ((doublereal *)&aplcnc_1 + 12)
    static doublereal u1, u2, w1, w2;
#define ac ((doublereal *)&aplcnc_1 + 139)
#define bc ((doublereal *)&aplcnc_1 + 140)
#define cc ((doublereal *)&aplcnc_1 + 141)
#define dc ((doublereal *)&aplcnc_1 + 142)
#define cb ((doublereal *)&aplcnc_1 + 13)
#define hc ((doublereal *)&aplcnc_1 + 144)
#define am ((doublereal *)&aplcnc_1 + 15)
    static doublereal dl, el;
#define pb ((doublereal *)&aplcnc_1 + 14)
#define pc ((doublereal *)&aplcnc_1 + 164)
    static doublereal fl, aq, bq;
#define ds ((doublereal *)&aplcnc_1 + 138)
#define dt ((doublereal *)&aplcnc_1 + 136)
#define du ((doublereal *)&aplcnc_1 + 182)
#define uc ((doublereal *)&aplcnc_1 + 196)
#define dw ((doublereal *)&aplcnc_1 + 183)
#define wc ((doublereal *)&aplcnc_1 + 199)
    static doublereal cq, pi, uk;
#define rs ((doublereal *)&aplcnc_1 + 133)
#define un ((doublereal *)&aplcnc_1 + 160)
#define rv ((doublereal *)&aplcnc_1 + 130)
#define zl ((doublereal *)&aplcnc_1 + 47)
#define up ((doublereal *)&aplcnc_1 + 153)
#define wp ((doublereal *)&aplcnc_1 + 154)
    static doublereal wk;
#define dd1 ((doublereal *)&aplcnc_1 + 180)
#define dd2 ((doublereal *)&aplcnc_1 + 181)
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
    static integer ict;
    static doublereal rcm;
#define cbar ((doublereal *)&aplcnc_1 + 171)
    static doublereal flag__;
#define delp ((doublereal *)&aplcnc_1 + 167)
#define delr ((doublereal *)&aplcnc_1 + 174)
#define delm ((doublereal *)&aplcnc_1 + 177)
#define rhoc ((doublereal *)&aplcnc_1 + 145)
#define rlam ((doublereal *)&aplcnc_1 + 185)
#define zlcp ((doublereal *)&aplcnc_1 + 150)
    static integer jswk;
#define jswl ((integer *)&aplcnc_1 + 459)
#define uprm ((doublereal *)&aplcnc_1 + 155)
#define wprm ((doublereal *)&aplcnc_1 + 156)
#define deldt ((doublereal *)&aplcnc_1 + 137)
#define idcnt ((integer *)&aplcnc_1 + 454)
#define ipcer ((integer *)&aplcnc_1 + 456)
    static doublereal theta;
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
    static integer mucnt;
#define roots ((doublereal *)&aplcnc_1 + 71)
#define epsil4 ((doublereal *)&aplcnc_1 + 202)
#define iddcnt ((integer *)&aplcnc_1 + 455)
#define iuncnt ((integer *)&aplcnc_1 + 457)
#define rhomul ((doublereal *)&aplcnc_1 + 120)
    static doublereal curlym;
#define jroots ((integer *)&aplcnc_1 + 458)
#define zlmult ((doublereal *)&aplcnc_1 + 106)

/*     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 *** */





    mucnt = 4;
    goto L4001;

/* ....   SECTION 4 9999 LINE INTERSECTION */

L4010:
    if (mucnt <= 0) {
	return 2;
    }
    --mucnt;
L4001:
    ict = 10;
    jswk = 1;
    switch ((int)*jswl) {
	case 1:  goto L4011;
	case 2:  goto L4000;
	case 3:  goto L4013;
	case 4:  goto L4005;
    }
L4000:
    tem[0] = *tsc;
    uk = *tsd;
    wk = *tse;
    *jswl = 1;
    goto L4020;
L4005:
    uk = -a2fpc_1.qp1;
    wk = a2fpc_1.q1p1;
    goto L4019;
L4011:
    uk = a2fpc_1.qp5;
    wk = a2fpc_1.qp5;
    goto L4019;
L4013:
    uk = *uc;
    wk = *wc;
L4019:
    *jswl = 2;
L4020:
    dl = uk * *wrs - wk * *urs;
    el = wk - *wrs;
    fl = uk - *urs;
    flag__ = abs(el) - abs(fl);
    aq = el * el + fl * (fl + (*phi - a2fpc_1.q2p) * el);
    bq = dl * (el - fl);
    cq = dl;
    if (el == a2fpc_1.qnul && fl == a2fpc_1.qnul) {
	goto L4010;
    }
    if (flag__ <= 0.) {
	goto L4050;
    } else {
	goto L4040;
    }
L4040:
    tem[0] = el * (-dl - fl);
    tem[1] = el * *phi + dl;
    goto L4060;
L4050:
    tem[0] = (dl - fl) * fl;
    tem[1] = dl;
L4060:
    bq += tem[0] * *phi * a2fpc_1.qp5;
    cq *= tem[1];
    if (aq != 0.) {
	goto L4070;
    } else {
	goto L4090;
    }
L4070:
    curlym = bq * bq - aq * cq;
    if (curlym < 0.) {
	goto L5035;
    } else if (curlym == 0) {
	goto L4110;
    } else {
	goto L4080;
    }
L4080:
    rcm = sqrt(curlym);
    u1 = (rcm - bq) / aq;
    u2 = (-rcm - bq) / aq;
    goto L4130;
L4090:
    if (bq == a2fpc_1.qnul) {
	return 1;
    }
    u1 = -cq * a2fpc_1.qp5 / bq;
    goto L4120;
L4110:
    u1 = -bq / aq;
L4120:
    u2 = u1;
L4130:
    if (flag__ > a2fpc_1.qnul) {
	goto L4150;
    }
    w1 = (u1 * el + dl) / fl;
    w2 = (u2 * el + dl) / fl;
    goto L4210;
L4150:
    w1 = u1;
    w2 = u2;
    u1 = (w1 * fl - dl) / el;
    u2 = (w2 * fl - dl) / el;


/* ...   SECTION 5 POINT SELECTION */

L4210:
    tem[0] = u1 - w1;
    tem[1] = u2 - w2;
    if ((d__1 = *phi - a2fpc_1.q4p) < 0.) {
	goto L5020;
    } else if (d__1 == 0) {
	goto L5160;
    } else {
	goto L5015;
    }
L5015:
    tem[0] = -tem[0] - 1.;
    tem[1] = -tem[1] - 1.;
L5020:
    if (tem[0] <= a2fpc_1.qnul) {
	if (tem[1] <= 0.) {
	    goto L5160;
	} else {
	    goto L5090;
	}
    }
    if (tem[1] <= a2fpc_1.qnul) {
	goto L5070;
    }
L5035:
    if (*phi >= a2fpc_1.q4p) {
	goto L4010;
    }
L5040:
    jswk = 2;
    u1 = a2fpc_1.qnul;
    w2 = a2fpc_1.q1p;
    *uprm = a2fpc_1.qnul;
    *wprm = a2fpc_1.qnul;
    w1 = dl;
    u2 = fl - w1;
    if (el == a2fpc_1.qnul || u2 * el <= a2fpc_1.qnul || abs(u2) < abs(el)) {
	goto L5075;
    }
    u2 /= el;
    if (fl != a2fpc_1.qnul && w1 * fl <= a2fpc_1.qnul) {
	goto L5065;
    }
L5070:
    *up = u2;
    *wp = w2;
L5074:
    if (jswk - 1 <= 0) {
	goto L5221;
    } else {
	goto L5260;
    }
L5075:
    if (fl == a2fpc_1.qnul || w1 * fl > a2fpc_1.qnul) {
	goto L4010;
    }
    w1 /= fl;
L5090:
    *up = u1;
    *wp = w1;
    goto L5074;
L5065:
    w1 /= fl;
L5160:
    pi = (w2 - w1) * (*tsh - *ukp * (w1 + w2)) + (u2 - u1) * (*tsi - *wkp * (
	    u1 + u2)) + *tsj * (u1 * w1 - u2 * w2);
    if (pi <= 0.) {
	goto L5090;
    } else {
	goto L5070;
    }
L5221:
    *tsa = *wp - *up;
    *tsb = *tsa + *tsa;
    *dw = *phi - *phi * *wp + *tsb;
    *du = *phi * *up + *tsb;
    u2 = *dw * *up - *du * *wp + *phi * *up;
    w2 = a2fpc_1.q2p * (*du * el - *dw * fl);
    if (abs(w2) < abs(u2)) {
	goto L5210;
    }
    u2 /= w2;
    u1 = *up + u2 * fl;
    w1 = *wp + u2 * el;
    --ict;
    if (ict != 0) {
	goto L5090;
    } else {
	goto L5210;
    }
L5210:
    if (*tsa < a2fpc_1.qnul) {
	*sqphi = -(*sqphi);
    }
    if (*up != 0.) {
	goto L5240;
    } else {
	goto L5250;
    }
L5250:
    *wp = a2fpc_1.qnul;
    *uprm = a2fpc_1.qnul;
    *wprm = a2fpc_1.qnul;
    goto L5260;
L5240:
    theta = (d__1 = (a2fpc_1.q1p - *wp) / *up, abs(d__1));
/* Computing 2nd power */
    d__1 = (*sqphi + a2fpc_1.q2p) * *up;
    *uprm = -(d__1 * d__1) * sqrt(theta) * *rhocp;
    *wprm = -theta * *uprm;
L5260:
    p[0] = *ds * *pb;
    p[1] = *zlc + ac[0] * *up + *cc * *wp;
    p[2] = *hc + *bc * *wp + *dc * *up;
    if (jswk == 1) {
	goto L5280;
    }
    if (*up != 0.) {
	goto L5272;
    } else {
	goto L5274;
    }
L5272:
    *up = a2fpc_1.q1p;
    goto L5280;
L5274:
    *wp = a2fpc_1.qnul;
L5280:
    if (*phi < a2fpc_1.q4p && *up > *wp) {
	goto L5040;
    }
    *tsa = *wp - *up;
    if (*phi > a2fpc_1.q4p && *tsa > a2fpc_1.q1p) {
	goto L4010;
    }
    *tsb = *tsa + *tsa;
    return 0;
} /* aplcnb_ */

#undef zlmult
#undef jroots
#undef rhomul
#undef iuncnt
#undef iddcnt
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
#undef dd2
#undef dd1
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
#undef t
#undef r__
#undef p
#undef h__
#undef d__
#undef c__
#undef b
#undef a


