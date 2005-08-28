/* ATAPE.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal d1mod, f1mod, f1shot, d1shot, frate;
    integer ifmod;
} frd_;

#define frd_1 frd_

struct {
    doublereal adum[720], te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3]
	    , pmove[3], ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[
	    3], ex[3], ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3]
	    , axis2[3], axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3],
	     zlpnt[3], tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[
	    3], oldu1[3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[
	    3], delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
	    gamma, cagl, sagl, com1, com4, costh, ctocl, diam, dif, difout, 
	    dinc, dp, dpe, dpi, dpl, dpmax, dp1, dpcnt, dsmov, d1, d2a, el1, 
	    el2, fipnt, flipck, hafdia, hchord, offset, prod1, prod2, psi, 
	    radno, rc1, rdrm, rdrn, rone, rzerol, save1, siuth, tangl, theta, 
	    alp, eps7, vamax, vl, zdotc, zgamma, zign, zl, zl1, zl2, znpts, 
	    tolbnd, cendis, cenlen, chord, abcd[2], acard[2], save[6], cutdat[
	    7], tem[10], temp[20], tcdat[260], qequiv[20];
    integer is, iis, it, iit, ips, iips, ids, iids, ics, iics, igs, iigs, 
	    icdefl, icdefs, iautps, igo, icrdct, icut, igtflg, inops, isrch, 
	    iofset, istrup, i3dflg, mulout, multax, numax, numsfs, numsur, 
	    igoug, ipdpl, numdim, irstrt, icscnt, i3, i31, j, ja, jl, js, jt, 
	    kc, knd, kr, l, incfs, np, ibegin, ifar1, ik, ins1, itnflg, 
	    ivamax, iws, iiws, iz, next1, next2, npts, numpt1, jam, jap, 
	    jtused, ifrl, n, m, mdic, jbr, jckr, jcpr, jcr, jdr, jgr, jmin, 
	    jminr, jpr, jpxr, jtr, jcnt1, jcnt2, jcnt3, jsw, jtkf, lisv, lsv, 
	    ipt, jfind, ic, icc, il, k, numpts, iamdct, ifl2, j5, j6, jw6, 
	    j10, j12, j13, j40, j43, j54, j103;
    doublereal bdum[2100];
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

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

static integer c__5 = 5;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__5000 = 5000;
static integer c__2 = 2;
static integer c__2102 = 2102;
static integer c__4 = 4;
static integer c__2000 = 2000;
static integer c__1009 = 1009;
static integer c__6 = 6;
static integer c__30 = 30;

/* Subroutine */ int atape_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_18 = { {'A', 'T', 'A', 'P', 'E', 'T', 'P', ' '}, (float)0. };

#define ab ((real *)&equiv_18)


    /* Format strings */
    static char fmt_201[] = "(\002 DNTCUT POINTS FOR ISN \002,i5,\002 DS IS\
 \002,a6,a6)";
    static char fmt_202[] = "(\002 \002,15x,3(f15.8,4x))";
    static char fmt_252[] = "(\002 \002,15x,6(f15.8,4x))";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, ikk;
    static doublereal dsm, ans;
    static integer kkk, keep;
    static doublereal tefr[3];
    extern /* Subroutine */ int aerr_(), avadd_();
    static doublereal dsmin, dwork, fwork;
    extern /* Subroutine */ int avsto_(), avsub_();
    static integer kount;
    static doublereal tebase[3];
    extern /* Subroutine */ int adyndp_(), atapwt_();
    static integer incrmt;
    extern /* Subroutine */ int avleng_(), avnorm_(), avmult_();

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___4 = { 0, 0, 0, fmt_202, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_252, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     ATAPE SUBROUTINE WRITES CODE AND SPECIFIED NUMBER OF TOOL CENTERS */
/*     (AND TLAXIS IF MULTIAXIS) ON CLTAPE. NO OUTPUT IF DNTCUT HAS BEEN */
/*     GIVEN.  ALSO WRITES AUX FEDRAT(IF GIVEN) DWORK AWAY FROM CS. */
/*     PROGRAM */
    adyndp_(ab, &c__5, &c__0);
    if (a2cmmn_.icut < 0) {
	goto L200;
    } else if (a2cmmn_.icut == 0) {
	goto L9999;
    } else {
	goto L190;
    }
L9999:
    if (a2cmmn_.ier != -10) {
	goto L187;
    }
    if (frd_1.ifmod == 0) {
	goto L187;
    }
    if (a2cmmn_.ins1 == 8) {
	goto L300;
    }
L187:
/* L185: */
    if (a2cmmn_.nw != 0) {
	goto L186;
    } else {
	goto L190;
    }
L186:
    ++asistm_1.nclrec;
    if (frd_1.ifmod == 0) {
	goto L400;
    }
    if (a2cmmn_.ins1 == 8) {
	goto L500;
    }
L400:
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, 
	    a2cmmn_.tcdat, &a2cmmn_.nw, &a2cmmn_.a, &c__0);
    if (a2cmmn_.ier >= 0) {
	goto L195;
    } else {
	goto L189;
    }
L189:
    a2cmmn_.icl = 6;


    avsto_(a2cmmn_.te, tefr);
L190:
    a2cmmn_.nw = 0;
    return 0;
L195:
    aerr_(&c__2102);
    return 0;
L200:
    io___3.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___3);
    do_fio(&c__1, (char *)&a2cmmn_.knd, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a2cmmn_.abcd[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cmmn_.abcd[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (a2cmmn_.mulout == 1) {
	goto L250;
    }
    io___4.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___4);
    i__1 = a2cmmn_.nw;
    for (ikk = 1; ikk <= i__1; ++ikk) {
	do_fio(&c__1, (char *)&a2cmmn_.tcdat[ikk - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L190;
L250:
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    i__1 = a2cmmn_.nw;
    for (ikk = 1; ikk <= i__1; ++ikk) {
	do_fio(&c__1, (char *)&a2cmmn_.tcdat[ikk - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L190;
L300:
    a2cmmn_.ier = 0;
    if (frd_1.ifmod == 1) {
	goto L299;
    }
    dwork = frd_1.d1shot;
    fwork = frd_1.f1shot;
    goto L298;
L299:
    dwork = frd_1.d1mod;
    fwork = frd_1.f1mod;
L298:
    dsmin = a2fpc_1.q1pe36;
    incrmt = a2cmmn_.mulout * 3 + 3;
L301:
    avsto_(tefr, tebase);
    dsm = a2fpc_1.qnul;
    i__1 = a2cmmn_.nw;
    i__2 = incrmt;
    for (kount = 1; i__2 < 0 ? kount >= i__1 : kount <= i__1; kount += i__2) {
	keep = kount;
	avsub_(&a2cmmn_.tcdat[kount - 1], tebase, a2cmmn_.vtem);
	avleng_(a2cmmn_.vtem, &ans);
	dsm += ans;
	if (dsm > dsmin) {
	    goto L350;
	}
/* L305: */
	avsto_(&a2cmmn_.tcdat[kount - 1], tebase);
    }
    if (dsm > dwork) {
	goto L310;
    }
L306:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    c__2000, &c__1, &c__1009, &c__1, &fwork, &c__1);
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, 
	    a2cmmn_.tcdat, &a2cmmn_.nw);
L307:
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    c__2000, &c__1, &c__1009, &c__1, &frd_1.frate, &c__1);
    if (frd_1.ifmod == -1) {
	frd_1.ifmod = 0;
    }
    if (frd_1.ifmod == 2) {
	frd_1.ifmod = 1;
    }
    goto L189;
L310:
    dsmin = dsm - dwork;
    goto L301;
L350:
    ans = ans - dsm + dsmin;
    avnorm_(a2cmmn_.vtem, a2cmmn_.vtem, &a2cmmn_.ier);
    avmult_(a2cmmn_.vtem, &ans, a2cmmn_.vtem);
    avadd_(a2cmmn_.vtem, tebase, &a2cmmn_.tcdat[249]);
    if (a2cmmn_.mulout == 1) {
	avsto_(&a2cmmn_.tcdat[keep + 2], &a2cmmn_.tcdat[252]);
    }
    if (keep != 1) {
	goto L360;
    }
    if (ans == a2fpc_1.qnul) {
	goto L306;
    }
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, &
	    a2cmmn_.tcdat[249], &incrmt);
    a2cmmn_.icl = 6;
    goto L306;
L360:
    ++asistm_1.nclrec;
    kkk = keep - 1;
    if (ans == a2fpc_1.qnul) {
	goto L610;
    }
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__6, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, 
	    a2cmmn_.tcdat, &kkk, &a2cmmn_.tcdat[249], &incrmt);
    goto L700;
L610:
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, 
	    a2cmmn_.tcdat, &kkk);
L700:
    a2cmmn_.icl = 6;
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__4, &asistm_1.nclrec, &c__1, &
	    c__2000, &c__1, &c__1009, &c__1, &fwork, &c__1);
    kkk = a2cmmn_.nw - kkk;
    ++asistm_1.nclrec;
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, &
	    a2cmmn_.tcdat[keep - 1], &kkk);
    goto L307;
/* ... OUTPUT ONLY 10 POINTS,MAKE ADJUSTMENTS AND RETURN */
L500:
    atapwt_(&ataptb_1.cltape, &a2cmmn_.ier, &c__5, &asistm_1.nclrec, &c__1, &
	    c__5000, &c__1, &a2cmmn_.icl, &c__1, a2cmmn_.abcd, &c__2, 
	    a2cmmn_.tcdat, &c__30);
    if (a2cmmn_.ier >= 0) {
	goto L195;
    } else {
	goto L510;
    }
L510:
    a2cmmn_.nw += -30;
    a2cmmn_.icl = 6;
    i__ = 28;
    if (a2cmmn_.mulout != 0) {
	i__ = 25;
    }
    avsto_(&a2cmmn_.tcdat[i__ - 1], tefr);
    for (i__ = 1; i__ <= 210; ++i__) {
	a2cmmn_.tcdat[i__ - 1] = a2cmmn_.tcdat[i__ + 29];
/* L520: */
    }
    return 0;
} /* atape_ */

#undef ab


