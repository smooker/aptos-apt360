/* BDYNDP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer indx1[10], indx2[14]	/* was [7][2] */, indx3[30]	/* 
	    was [15][2] */;
    real xname[700];
} a2dyin_;

#define a2dyin_1 a2dyin_

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap;
    doublereal puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
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

static struct {
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

static struct {
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

static struct {
    doublereal q15x01, qp9x01, qp6x01, qp5x01, qp4x01, qp0001, qp001, qp01, 
	    qp1, q1p, q10p, q1000p, q1pe5, q1pe6, q1pe10, q1pe20, q1pe30, 
	    q1pe36, q1pe38, qp8x01, qp7x01, qp4x09, qp9, qp99, qp995, qp997, 
	    qp999, qp9999, qp4x95, qp5x95, qp6x9, qp7x9, qp6x05, qp5x05, 
	    qp4x05, qp0005, qp005, qp05, qp5, q5p, q4x045, qp0002, qp0047, 
	    qp017, q1rad, qp0349, qp125, qp6, qp2, qp2499, qp25, qp3, qp7, 
	    qp75, qp8, qp866, q1p01, q1p1, q1p2, q1p25, q1p5, q2p, q2p5, q3p, 
	    q3p5, q4p, q8p, q11p, q45p, q90p, q130p, q4500p, q9000p, qp02, 
	    qnul, qfil[10];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__1 = 1;
static integer c__10 = 10;

/* Subroutine */ int bdyndp_(calnm, kz, idynfq)
real *calnm;
integer *kz, *idynfq;
{
    /* Initialized data */

    static struct {
	char e_1[4];
	real e_2;
	} equiv_38 = { {'R', 'R', '*', '*'}, (float)0. };

#define aer2 (*(real *)&equiv_38)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_39 = { {' ', ' ', ' ', ' '}, (float)0. };

#define bla (*(real *)&equiv_39)

    static integer num[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
    static integer ncaln = 0;
    static struct {
	char e_1[4];
	real e_2;
	} equiv_40 = { {'A', 'R', 'L', 'M'}, (float)0. };

#define qn (*(real *)&equiv_40)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_41 = { {'2', '0', '1', ' '}, (float)0. };

#define qn1 (*(real *)&equiv_41)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_42 = { {'2', '9', '9', ' '}, (float)0. };

#define qn2 (*(real *)&equiv_42)

    static struct {
	char e_1[4];
	real e_2;
	} equiv_43 = { {'*', '*', 'A', 'E'}, (float)0. };

#define aer1 (*(real *)&equiv_43)


    /* Format strings */
    static char fmt_6000[] = "(\002 \002,\002TRACE OF POSSIBLE LOOP  \002,a4\
,a4)";
    static char fmt_1000[] = "(1x,2a4,5x,\002NREC = \002,i4,5x,\002NCLREC =\
 \002,i4,5x,\002CALL NO. \002,i5,5x,\002LEVEL \002,i2,5x,\002ISN \002,i4/)";
    static char fmt_2000[] = "(4(3x,a4,a4,d20.13,\002,\002))";
    static char fmt_3000[] = "(7(3x,a4,a4,i6,\002,\002))";
    static char fmt_4000[] = "(\0020\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe(), pow_ii();

    /* Local variables */
    static integer m1;
#define bg ((doublereal *)&a2cmmn_1)
    static integer im, iq, ii, mq, kq, ij, nq, mq1, i2q;
#define ibg ((integer *)&a2cmmn_1 + 1200)
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
    static integer kdiv, kdiv1, mq21, iiq, mqx, mq20, mqxx;
#define tlldat ((doublereal *)&a2ctdf_1 + 6)

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 0, 0, fmt_6000, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_4000, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
    /* Parameter adjustments */
    --calnm;

    /* Function Body */
/* ...       RESET CALL NO. FOR EACH CUT SEQUENCE */
    if (*idynfq >= 0) {
	goto L7;
    }
    if (*idynfq == -2) {
	goto L5;
    }
    im = 1;
    ncaln = 0;
    goto L10;
L5:
    if (a2cmmn_1.i3 == 0) {
	goto L10;
    }
    io___15.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___15);
    do_fio(&c__1, (char *)&calnm[1], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&calnm[2], (ftnlen)sizeof(real));
    e_wsfe();
    goto L10;
L7:
    ++ncaln;
/* ...     IS FREQUENCY FOR THIS LEVEL 0--IF SO RETURN */
/* L8: */
    if (a2dydp_1.kdynfq[*kz - 1] != 0) {
	goto L15;
    } else {
	goto L10;
    }
L10:
    return 0;
L15:
    if (a2dydp_1.kdynfq[6] > 0) {
	goto L10;
    }
/* L20: */
    kdiv = *idynfq;
/* ...     HAS FREQUENCY BEEN RESET SINCE LAST CALL--IF SO RESET ITERATION */
    if (a2dydp_1.nkfq != 0) {
	goto L30;
    } else {
	goto L60;
    }
L30:
    for (iq = 1; iq <= 12; ++iq) {
/* L40: */
	num[iq - 1] = 0;
    }
/* L50: */
    a2dydp_1.nkfq = 0;
L60:
    --num[*kz - 1];
/* L70: */
    if (num[*kz - 1] <= 0) {
	goto L80;
    } else {
	goto L75;
    }
L75:
    if (a2dydp_1.kdynfq[*kz - 1] <= 0) {
	goto L10;
    } else {
	goto L90;
    }
L80:
    num[*kz - 1] = (i__1 = a2dydp_1.kdynfq[*kz - 1], abs(i__1));
L90:
    io___18.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___18);
    do_fio(&c__1, (char *)&calnm[1], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&calnm[2], (ftnlen)sizeof(real));
    do_fio(&c__1, (char *)&a2cmmn_1.nrec, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&asistm_1.nclrec, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ncaln, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*kz), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a2cmmn_1.knd, (ftnlen)sizeof(integer));
    e_wsfe();
/* ...     IF TRACE PRINT ONLY GO HOME */
    if (num[*kz - 1] != (i__1 = a2dydp_1.kdynfq[*kz - 1], abs(i__1))) {
	goto L10;
    }
/* L100: */
    if (a2dydp_1.kdynfq[*kz - 1] <= 0) {
	goto L10;
    } else {
	goto L110;
    }
L110:
    for (iq = 1; iq <= 6; ++iq) {
/* L120: */
	kdiv1 = kdiv - 1000000 / pow_ii(&c__10, &iq);
/* L130: */
	if (kdiv1 >= 0) {
	    goto L140;
	} else {
	    goto L999;
	}
L140:
	kdiv = kdiv1;
/* L150: */
	switch ((int)iq) {
	    case 1:  goto L210;
	    case 2:  goto L210;
	    case 3:  goto L230;
	    case 4:  goto L280;
	    case 5:  goto L250;
	    case 6:  goto L260;
	}
L210:
	m1 = 3;
/* L211: */
	if (a2cmmn_1.icscnt > 1) {
	    m1 = a2cmmn_1.icscnt + 2;
	}
/* L212: */
	goto L300;
/* ...     FLOATING POINT FIXED COMMON */
L230:
	a2dyin_1.indx3[25] = a2cmmn_1.nw;
	goto L280;
/* ...     PROBUF COMMON */
L250:
	a2dyin_1.indx3[28] = a2cmmn_1.nwds;
	if (calnm[1] == qn && (calnm[2] >= qn1 || calnm[2] <= qn2) || calnm[1]
		 == aer1 && calnm[2] == aer2) {
	    a2dyin_1.indx3[28] = 75;
	}
	goto L280;
/* ...     CANSTO COMMON */
L260:
	a2dyin_1.indx3[29] = a2cmmn_1.jtused;
L280:
	m1 = 1;
/* ...     SET UP OVERALL INDEXES */
L300:
	mq1 = a2dyin_1.indx1[iq - 1];
/* L305: */
	mq21 = mq1;
L310:
	ii = a2dyin_1.indx2[iq + 6];
/* L320: */
	iiq = a2dyin_1.indx2[iq - 1];
/* L330: */
	if (iq == 2 || iq == 4) {
	    goto L600;
	}
/* ...     DUMP FLOATING POINT COMMON */
L400:
	mq1 = mq21;
/* L410: */
	mq21 = mq1 + a2dyin_1.indx3[iiq - 1];
/* ...     VARIABLES HAVE FLOATING LIMIT */
/* L420: */
	if (a2dyin_1.indx3[iiq + 14] >= 0) {
	    goto L440;
	} else {
	    goto L430;
	}
L430:
	mq = a2dyin_1.indx3[iiq - 1] / (i__1 = a2dyin_1.indx3[iiq + 14], abs(
		i__1));
	mqx = (i__1 = a2dyin_1.indx3[iiq + 14], abs(i__1));
	goto L450;
L440:
	mq = a2dyin_1.indx3[iiq + 14];
	mqx = 1;
L450:
	mq20 = mq1 + mq - 1;
/* ...     PRINT ONE OR FOUR VARIABLES PER LINE */
/* L460: */
	if (a2dyin_1.indx3[iiq - 1] + a2dyin_1.indx3[iiq + 14] != 0) {
	    goto L510;
	} else {
	    goto L470;
	}
/* ...     FOUR PER LINE */
L470:
	mqxx = mqx / 4;
	i__1 = mqxx;
	for (kq = 1; kq <= i__1; ++kq) {
/* L480: */
	    io___30.ciunit = ataptb_1.ioutap;
	    s_wsfe(&io___30);
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&bg[mq1 - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 2], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&bg[mq1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 3], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 4], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&bg[mq1 + 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 5], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 6], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&bg[mq1 + 2], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L490: */
	    mq1 += 4;
	    ii += 8;
/* L500: */
	}
	mqx -= mqxx << 2;
	mq20 = mq1;
	mq = 1;
	if (mqx <= 0) {
	    goto L590;
	} else {
	    goto L510;
	}
/* ...     ONE VARIABLE PER LINE */
L510:
	if (mq <= 0) {
	    goto L590;
	} else {
	    goto L520;
	}
L520:
	i__1 = mqx;
	for (a2cmmn_1.k = 1; a2cmmn_1.k <= i__1; ++a2cmmn_1.k) {
	    io___31.ciunit = ataptb_1.ioutap;
	    s_wsfe(&io___31);
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii], (ftnlen)sizeof(real));
	    i__2 = mq20;
	    for (ij = mq1; ij <= i__2; ++ij) {
		do_fio(&c__1, (char *)&bg[ij - 1], (ftnlen)sizeof(doublereal))
			;
		do_fio(&c__1, (char *)&bla, (ftnlen)sizeof(real));
		do_fio(&c__1, (char *)&bla, (ftnlen)sizeof(real));
	    }
	    e_wsfe();
	    ii += 2;
	    mq1 += mq;
	    mq20 += mq;
/* L540: */
	}
L590:
	++iiq;
	if (iiq >= a2dyin_1.indx2[iq]) {
	    goto L790;
	}
	goto L400;
/* ...     DUMP INTEGER COMMON */
L600:
	mq1 = mq21;
/* L610: */
	nq = (i__1 = a2dyin_1.indx3[iiq + 14], abs(i__1)) / 7;
	mq21 = mq1 + a2dyin_1.indx3[iiq - 1];
/* L620: */
	i__1 = nq;
	for (kq = 1; kq <= i__1; ++kq) {
	    io___34.ciunit = ataptb_1.ioutap;
	    s_wsfe(&io___34);
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 - 1)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 2], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 3], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 4], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 + 1)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 5], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 6], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 + 2)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 7], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 8], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 + 3)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 9], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 10], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 + 4)], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 11], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii + 12], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 + 5)], (ftnlen)sizeof(integer));
	    e_wsfe();
	    ii += 14;
	    mq1 += 7;
/* L650: */
	}
	i2q = (i__1 = a2dyin_1.indx3[iiq + 14], abs(i__1)) - nq * 7;
	if (i2q <= 0) {
	    goto L790;
	}
/* ...     PRINT ANY VARIABLES LEFT OVER */
	i__1 = i2q;
	for (kq = 1; kq <= i__1; ++kq) {
	    io___36.ciunit = ataptb_1.ioutap;
	    s_wsfe(&io___36);
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&c__1, (char *)&a2dyin_1.xname[ii], (ftnlen)sizeof(real));
	    do_fio(&c__1, (char *)&ibg[OTHER_ENDIAN_S(mq1 - 1)], (ftnlen)sizeof(integer));
	    e_wsfe();
	    ii += 2;
	    ++mq1;
/* L700: */
	}
L790:
	io___37.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___37);
	e_wsfe();
/* L800: */
	--m1;
	if (m1 <= 0) {
	    goto L999;
	} else {
	    goto L310;
	}
L999:
	;
    }
    goto L10;
/* ... */
} /* bdyndp_ */

#undef tlldat
#undef cosl
#undef sinl
#undef ibg
#undef bg
#undef aer1
#undef qn2
#undef qn1
#undef qn
#undef bla
#undef aer2


