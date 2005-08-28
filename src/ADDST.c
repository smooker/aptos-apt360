/* ADDST.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal sp[3], sn[3], tp[3], tn[3], snk[3], snl[3], spk[3], spl[3], 
	    tnk[3], tnl[3], tpk[3], tpl[3], plnv[3], cc[3], u1[3], cuth[3], 
	    sfvct[3], vndir[3], vmd[3], vt[3], tee[3], slx[3], dplan[3], s[1],
	     rc[1], plnd[1], th[1], csd[1], z__[1], eps1[1], eps2[1], eps3[1],
	     eps4[1], eps6[1], eps8[1], tau[1], tau1[1], tau2[1], stck[1], 
	    stckn[1], stck1[1], stck2[1], cos1[1], dpmx1[1], cplfl[1], cptst[
	    1], plncs[1], plnd1[1], pltst[1], past[1], spast[1], adcs[1], h__[
	    1], cutr[1], afillr[500];
    integer iafl[1], ipontr[1], ifar[1], ipl[1], iunfl[1], isftyp[1], itlon[1]
	    , isvfl[1], ifl4[1], iop[1], iopset[1], jiops[1], notan[1], jent[
	    1], ju1[1], isigcr[1], itseg[1], jtlflg[1], lofs[1], limfl[1], 
	    icstr[1], jtn[1], ichkct[1], j20[1], j21[1], j22[1], j23[1], j24[
	    1], j50[1], j51[1], indir__[1], ifillr[209];
    doublereal te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3], pmove[3],
	     ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[3], ex[3], 
	    ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3], axis2[3],
	     axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3], zlpnt[3], 
	    tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[3], oldu1[
	    3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[3], 
	    delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
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
    doublereal probuf[100], cansto[2000];
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
static integer c__11 = 11;
static integer c__1401 = 1401;
static integer c__2 = 2;

/* Subroutine */ int addst_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_11 = { {'A', 'D', 'D', 'S', 'T', ' ', ' ', ' '}, (float)0. };

#define ab ((real *)&equiv_11)


    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Local variables */
    static integer i__, jj, ii;
    static doublereal dum[10];
#define bloc1 ((doublereal *)&a2cmmn_ + 1408)
    static doublereal dum1[10], dum2[3], dum3[3];
    extern /* Subroutine */ int aerr_();
    static integer iii;
    extern /* Subroutine */ int addtb_(), aquad_(), aplcn_(), arlds_(), 
	    adyndp_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */


/* ****** */
/* ****** */
    adyndp_(ab, &c__5, &c__11);
    a2cmmn_.ic = a2cmmn_.ipontr[a2cmmn_.iis - 1] + 1;
    jj = a2cmmn_.j24[a2cmmn_.iis - 1];
    switch ((int)jj) {
	case 1:  goto L20;
	case 2:  goto L40;
	case 3:  goto L60;
	case 4:  goto L60;
	case 5:  goto L130;
	case 6:  goto L150;
	case 7:  goto L160;
	case 8:  goto L200;
	case 9:  goto L10;
    }
L10:
    aerr_(&c__1401);
/* *** */
/* ***** DDPLAN */
/* *** */
L20:
    dum[0] = bloc1[a2cmmn_.ic + 2] * a2cmmn_.tn[a2cmmn_.is - 1] + bloc1[
	    a2cmmn_.ic + 3] * a2cmmn_.tn[a2cmmn_.is] + bloc1[a2cmmn_.ic + 
	    4] * a2cmmn_.tn[a2cmmn_.is + 1];
    if (abs(dum[0]) - a2fpc_1.qp6x01 <= 0.) {
	goto L21;
    } else {
	goto L22;
    }
L21:
    a2cmmn_.ier = 1;
    goto L1000;
L22:
    a2cmmn_.s[a2cmmn_.is - 1] = (bloc1[a2cmmn_.ic + 5] - (a2cmmn_.tp[
	    a2cmmn_.is - 1] * bloc1[a2cmmn_.ic + 2] + a2cmmn_.tp[
	    a2cmmn_.is] * bloc1[a2cmmn_.ic + 3] + a2cmmn_.tp[a2cmmn_.is + 
	    1] * bloc1[a2cmmn_.ic + 4])) / dum[0];
    if (a2cmmn_.s[a2cmmn_.is - 1] >= 0.) {
	goto L24;
    } else {
	goto L23;
    }
L23:
    if (a2cmmn_.iop[a2cmmn_.iis - 1] != 0) {
	goto L21;
    } else {
	goto L24;
    }
L24:
    a2cmmn_.ier = 0;
    goto L1000;
/* *** */
/* ***** DDCYLN */
/* *** */
L40:
    dum[0] = a2cmmn_.tn[a2cmmn_.is - 1] * bloc1[a2cmmn_.ic + 5] + 
	    a2cmmn_.tn[a2cmmn_.is] * bloc1[a2cmmn_.ic + 6] + a2cmmn_.tn[
	    a2cmmn_.is + 1] * bloc1[a2cmmn_.ic + 7];
    a2cmmn_.a = a2fpc_1.q1p - dum[0] * dum[0];
    dum[1] = a2cmmn_.tp[a2cmmn_.is - 1] - bloc1[a2cmmn_.ic + 2];
    dum[2] = a2cmmn_.tp[a2cmmn_.is] - bloc1[a2cmmn_.ic + 3];
    dum[3] = a2cmmn_.tp[a2cmmn_.is + 1] - bloc1[a2cmmn_.ic + 4];
    dum[4] = dum[1] * bloc1[a2cmmn_.ic + 5] + dum[2] * bloc1[a2cmmn_.ic + 6]
	     + dum[3] * bloc1[a2cmmn_.ic + 7];
    a2cmmn_.b = a2cmmn_.tn[a2cmmn_.is - 1] * dum[1] + a2cmmn_.tn[
	    a2cmmn_.is] * dum[2] + a2cmmn_.tn[a2cmmn_.is + 1] * dum[3] - 
	    dum[0] * dum[4];
/* Computing 2nd power */
    d__1 = dum[1];
/* Computing 2nd power */
    d__2 = dum[2];
/* Computing 2nd power */
    d__3 = dum[3];
/* Computing 2nd power */
    d__4 = dum[4];
/* Computing 2nd power */
    d__5 = bloc1[a2cmmn_.ic + 8];
    a2cmmn_.c__ = d__1 * d__1 + d__2 * d__2 + d__3 * d__3 - d__4 * d__4 - 
	    d__5 * d__5;
    aquad_();
    goto L1000;
/* *** */
/* ***** DDQUAD */
/* *** */
L60:
    ii = a2cmmn_.ic + 2;
    for (i__ = 1; i__ <= 10; ++i__) {
	iii = ii + i__;
	dum1[i__ - 1] = bloc1[iii - 1];
/* L65: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ii = a2cmmn_.is + i__ - 1;
	dum2[i__ - 1] = a2cmmn_.tn[ii - 1];
	dum3[i__ - 1] = a2cmmn_.tp[ii - 1];
/* L70: */
    }
    if (a2cmmn_.j24[a2cmmn_.iis - 1] != 3) {
	goto L80;
    }
/* Computing 2nd power */
    d__1 = dum2[0];
/* Computing 2nd power */
    d__2 = dum2[1];
/* Computing 2nd power */
    d__3 = dum2[2];
    a2cmmn_.a = a2fpc_1.q2p * (dum1[5] * dum2[2] * dum2[0] + dum1[6] * dum2[
	    0] * dum2[1] + dum1[4] * dum2[1] * dum2[2]) + d__1 * d__1 * dum1[
	    0] + d__2 * d__2 * dum1[1] + d__3 * d__3 * dum1[2];
    a2cmmn_.b = (dum1[0] * dum2[0] + dum1[6] * dum2[1] + dum1[5] * dum2[2]) *
	     dum3[0] + (dum1[6] * dum2[0] + dum1[1] * dum2[1] + dum1[4] * 
	    dum2[2]) * dum3[1] + (dum1[5] * dum2[0] + dum1[4] * dum2[1] + 
	    dum1[2] * dum2[2]) * dum3[2] + dum2[0] * dum1[7] + dum2[1] * dum1[
	    8] + dum2[2] * dum1[9];
/* Computing 2nd power */
    d__1 = dum3[0];
/* Computing 2nd power */
    d__2 = dum3[1];
/* Computing 2nd power */
    d__3 = dum3[2];
    a2cmmn_.c__ = a2fpc_1.q2p * (dum1[5] * dum3[2] * dum3[0] + dum1[6] * 
	    dum3[0] * dum3[1] + dum1[4] * dum3[1] * dum3[2] + dum3[0] * dum1[
	    7] + dum3[1] * dum1[8] + dum3[2] * dum1[9]) + d__1 * d__1 * dum1[
	    0] + d__2 * d__2 * dum1[1] + d__3 * d__3 * dum1[2] + dum1[3];
    aquad_();
    goto L1000;
/* *** */
/* ***** DDCONE */
/* *** */
L80:
/* Computing 2nd power */
    d__1 = dum1[6];
    dum[5] = d__1 * d__1;
    dum[0] = dum2[0] * dum1[3] + dum2[1] * dum1[4] + dum2[2] * dum1[5];
/* Computing 2nd power */
    d__1 = dum[0];
    a2cmmn_.a = d__1 * d__1 - dum[5];
    dum[1] = dum3[0] - dum1[0];
    dum[2] = dum3[1] - dum1[1];
    dum[3] = dum3[2] - dum1[2];
    dum[4] = dum[1] * dum1[3] + dum[2] * dum1[4] + dum[3] * dum1[5];
    a2cmmn_.b = dum[0] * dum[4] - dum[5] * (dum2[0] * dum[1] + dum2[1] * dum[
	    2] + dum2[2] * dum[3]);
/* Computing 2nd power */
    d__1 = dum[4];
/* Computing 2nd power */
    d__2 = dum[1];
/* Computing 2nd power */
    d__3 = dum[2];
/* Computing 2nd power */
    d__4 = dum[3];
    a2cmmn_.c__ = d__1 * d__1 - dum[5] * (d__2 * d__2 + d__3 * d__3 + d__4 * 
	    d__4);
    aquad_();
/*     IF(((-----SP(IS)--------)-(---VERTEX--))*AXISVEC)81,81,1000 */
L82:
    dum[6] = (dum3[0] + a2cmmn_.s[a2cmmn_.is - 1] * dum2[0] - dum1[0]) * 
	    dum1[3] + (dum3[1] + a2cmmn_.s[a2cmmn_.is - 1] * dum2[1] - dum1[
	    1]) * dum1[4] + (dum3[2] + a2cmmn_.s[a2cmmn_.is - 1] * dum2[2] 
	    - dum1[2]) * dum1[5];
    if (dum[6] <= 0.) {
	goto L81;
    } else {
	goto L1000;
    }
/*     THE ONLY ACCEPTABLE LOCI FOR SP(IS) ARE ELEMENT LINES MAKING AN */
/*     ANGLE OF LESS THAN 90 DEGREES WITH THE CONE AXIS VECTOR */
/* ...         QUAD MAY HAVE RETURNED WRONG S--CHECK OTHER RESULT */
L81:
    if (a2cmmn_.difout != 0.) {
	goto L83;
    } else {
	goto L84;
    }
/* ...         OTHER RESULT USABLE--TRY IT */
L83:
    a2cmmn_.s[a2cmmn_.is - 1] = a2cmmn_.difout;
    a2cmmn_.difout = a2fpc_1.qnul;
    goto L82;
/* ...         NEITHER RESULT ACCEPTABLE -- NO DIRECTED DISTANCE */
L84:
    a2cmmn_.ier = 1;
    goto L1000;
/* *** */
/* ***** DDSPHR */
/* *** */
L130:
    a2cmmn_.a = a2fpc_1.q1p;
    dum[0] = a2cmmn_.tp[a2cmmn_.is - 1] - bloc1[a2cmmn_.ic + 2];
    dum[1] = a2cmmn_.tp[a2cmmn_.is] - bloc1[a2cmmn_.ic + 3];
    dum[2] = a2cmmn_.tp[a2cmmn_.is + 1] - bloc1[a2cmmn_.ic + 4];
    a2cmmn_.b = dum[0] * a2cmmn_.tn[a2cmmn_.is - 1] + dum[1] * a2cmmn_.tn[
	    a2cmmn_.is] + dum[2] * a2cmmn_.tn[a2cmmn_.is + 1];
/* Computing 2nd power */
    d__1 = dum[0];
/* Computing 2nd power */
    d__2 = dum[1];
/* Computing 2nd power */
    d__3 = dum[2];
/* Computing 2nd power */
    d__4 = bloc1[a2cmmn_.ic + 5];
    a2cmmn_.c__ = d__1 * d__1 + d__2 * d__2 + d__3 * d__3 - d__4 * d__4;
    aquad_();
    goto L1000;
L150:
    aplcn_(&c__2);
    goto L1000;
L160:
    addtb_();
    goto L1000;
L200:
    arlds_();
    goto L1000;
L1000:

    return 0;
} /* addst_ */

#undef bloc1
#undef ab


