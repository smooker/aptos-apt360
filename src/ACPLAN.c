/* ACPLAN.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

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
    doublereal adum[2100];
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
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

static integer c__11 = 11;
static integer c_b3 = 111111;
static integer c__4 = 4;
static integer c_b5 = 111100;
static integer c__6 = 6;
static integer c_b9 = 110000;

/* Subroutine */ int acplan_()
{
    /* Initialized data */

    static struct {
	char e_1[120];
	real e_2;
	} equiv_9 = { {'A', 'C', 'P', 'L', 'A', 'N', 'T', 'P', 'A', 'C', 'P', 
		'L', 'A', 'N', '0', '1', 'A', 'C', 'P', 'L', 'A', 'N', '0', 
		'2', 'A', 'C', 'P', 'L', 'A', 'N', '0', '3', 'A', 'C', 'P', 
		'L', 'A', 'N', '0', '4', 'A', 'C', 'P', 'L', 'A', 'N', '0', 
		'5', 'A', 'C', 'P', 'L', 'A', 'N', '0', '6', 'A', 'C', 'P', 
		'L', 'A', 'N', 'E', 'X', 'A', 'C', 'P', 'L', 'A', 'N', '0', 
		'7', 'A', 'C', 'P', 'L', 'A', 'N', '0', '8', 'A', 'C', 'P', 
		'L', 'A', 'N', '0', '9', 'A', 'C', 'P', 'L', 'A', 'N', '1', 
		'0', 'A', 'C', 'P', 'L', 'A', 'N', '1', '1', 'A', 'C', 'P', 
		'L', 'A', 'N', '1', '2', 'A', 'C', 'P', 'L', 'A', 'N', '1', 
		'3'}, (float)0. };

#define ab ((real *)&equiv_9)


    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt();

    /* Local variables */
    static integer itt;
    static doublereal temp1;
    static integer iitt;
    static doublereal ans;
    static integer isis;
    extern /* Subroutine */ int avadd_(), avsub_(), avdot_(), avsto_();
    static integer iisis;
    extern /* Subroutine */ int addst_();
    static doublereal factor;
    extern /* Subroutine */ int adyndp_(), avcros_(), avnorm_(), accurv_(), 
	    avmult_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/* ... A2CMMN START */

    adyndp_(ab, &c__11, &c_b3);
    adyndp_(ab, &c__4, &c_b5);
/* ... */
    a2cmmn_1.temp[19] = a2cmmn_1.rc[a2cmmn_1.is - 1];
/* ... */
/* ...  SEE IF THE CHECK SURFACE IS A PLANE */
/* L1010: */
    avcros_(&a2cmmn_1.sn[a2cmmn_1.is - 1], &a2cmmn_1.snk[a2cmmn_1.is - 1], 
	    a2cmmn_1.temp);
/* L1020: */
    avnorm_(a2cmmn_1.temp, a2cmmn_1.temp, &a2cmmn_1.ier);
/* ...  ********************************************************** 01 *** */
    adyndp_(&ab[2], &c__6, &c_b9);
/* ... */
/* L1030: */
    if (a2cmmn_1.ier != 0) {
	goto L1040;
    } else {
	goto L1050;
    }
/* 	not a plane.. */
L1050:
    avsub_(&a2cmmn_1.sp[a2cmmn_1.is - 1], &a2cmmn_1.spk[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avdot_(a2cmmn_1.temp, a2cmmn_1.vtem, &temp1);
/* L1060: */
    a2cmmn_1.tem[0] = a2cmmn_1.spk[a2cmmn_1.is - 1] + temp1 * a2cmmn_1.temp[0]
	    ;
    a2cmmn_1.tem[1] = a2cmmn_1.spk[a2cmmn_1.is] + temp1 * a2cmmn_1.temp[1];
    a2cmmn_1.tem[2] = a2cmmn_1.spk[a2cmmn_1.is + 1] + temp1 * a2cmmn_1.temp[2]
	    ;
    adyndp_(&ab[4], &c__6, &c_b9);
/* L1090: */
    accurv_(&a2cmmn_1.is, &a2cmmn_1.iis, &a2cmmn_1.sp[a2cmmn_1.is - 1], 
	    a2cmmn_1.tem, &a2cmmn_1.tn[a2cmmn_1.is - 1]);
/* ... */
/* ........... TANTO (IFL4=0)  OR  PSTAN (IFL4=1) ..... */
L1120:
    if (a2cmmn_1.ifl4[a2cmmn_1.iis - 1] != 0) {
	goto L1130;
    } else {
	goto L1140;
    }
/* ... */
/* ... **** PSTAN **** */
L1130:
    a2cmmn_1.it = a2cmmn_1.ips;
    a2cmmn_1.iit = a2cmmn_1.iips;
    itt = a2cmmn_1.ids;
    iitt = a2cmmn_1.iids;
/* ...  ********************************************************** 03 *** */
    adyndp_(&ab[6], &c__6, &c_b9);
    goto L1150;
/* ... */
/* ...  THE CHECK SURFACE IS A PLANE. */
L1040:
/* ...  SET CS RC = 4500 ... RETAIN OLD SIGN */
    a2cmmn_1.a = a2cmmn_1.rc[a2cmmn_1.is - 1];
    a2cmmn_1.rc[a2cmmn_1.is - 1] = a2cmmn_1.rc1;
    if (a2cmmn_1.a < a2fpc_1.qnul) {
	a2cmmn_1.rc[a2cmmn_1.is - 1] = -a2cmmn_1.rc1;
    }
    goto L1120;
/* ... */
/* ... **** TANTO **** */
L1140:
    a2cmmn_1.it = a2cmmn_1.ids;
    a2cmmn_1.iit = a2cmmn_1.iids;
    itt = a2cmmn_1.ips;
    iitt = a2cmmn_1.iips;
/* ...  ********************************************************** 04 *** */
    adyndp_(&ab[8], &c__6, &c_b9);
/* ... COMPARE THE Z COMPONENT OF CURRENT SP AND THAT OF SP AT THE ORIGIN */
/* ... OF CUT VECTOR (OF THE TANGENT SURFACE). IF THEY ARE CLOSE TOGETHER */
/* ... TEM = TI. IF NOT, TEM = SN(PS) X SN(DS) . */
L1150:
    if ((d__1 = a2cmmn_1.sp[a2cmmn_1.it + 1] - a2cmmn_1.spk[a2cmmn_1.it + 1], 
	    abs(d__1)) - a2fpc_1.qp001 >= 0.) {
	goto L1;
    } else {
	goto L2;
    }
L2:
    avsto_(a2cmmn_1.ti, a2cmmn_1.tem);
    goto L5;
/* ... */
/* ... CROSS PART SN AND DRIVE SN */
L1:
    avcros_(&a2cmmn_1.sn[a2cmmn_1.it - 1], &a2cmmn_1.sn[itt - 1], 
	    a2cmmn_1.tem);
    avnorm_(a2cmmn_1.tem, a2cmmn_1.tem, &a2cmmn_1.ier);
/* ... *********************************************************** 05 *** */
    adyndp_(&ab[10], &c__6, &c_b9);
/* ... */
    if (a2cmmn_1.ier != 0) {
	goto L2;
    } else {
	goto L3;
    }
L3:
    avdot_(a2cmmn_1.ti, a2cmmn_1.tem, &ans);
    if (ans >= a2fpc_1.qnul) {
	goto L5;
    }
/* L4: */
    avsub_(a2cmmn_1.vnul, a2cmmn_1.tem, a2cmmn_1.tem);
/* ... */
/* ... */
L5:
    isis = a2cmmn_1.is;
    iisis = a2cmmn_1.iis;
    a2cmmn_1.is = a2cmmn_1.it;
    a2cmmn_1.iis = a2cmmn_1.iit;
/* ... */
    a2cmmn_1.temp[3] = a2cmmn_1.s[a2cmmn_1.is - 1];
/* ... */
    avsto_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.temp);
/* ... */
/* ...  CALCULATE SP ON THE TANGENT SURFACE .....  FROM .05 UNIT AWAY */
/* ...  FROM THE CURRENT TP IN OPPOSITE DIRECTION OF TI. */
/* ...  TEM IS EQUIVALENT TO TI. */
    factor = a2fpc_1.qp05;
L55:
    avmult_(a2cmmn_1.tem, &factor, a2cmmn_1.vtem);
    avsub_(a2cmmn_1.temp, a2cmmn_1.vtem, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    addst_();
    if (a2cmmn_1.ier == 0) {
	goto L56;
    }
    factor *= a2fpc_1.qp5;
    if (factor > a2fpc_1.qp5x01) {
	goto L55;
    }
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2cmmn_1.temp[3];
L56:
    avmult_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.s[a2cmmn_1.is - 1], 
	    a2cmmn_1.vtem);
    avadd_(&a2cmmn_1.tp[a2cmmn_1.is - 1], a2cmmn_1.vtem, a2cmmn_1.tem);
/* ... */
/* ...  TEM NOW CONTAINS NEW SP CALCULATED ABOVE. */
    avsto_(a2cmmn_1.temp, &a2cmmn_1.tp[a2cmmn_1.is - 1]);
    a2cmmn_1.s[a2cmmn_1.is - 1] = a2cmmn_1.temp[3];
    a2cmmn_1.is = isis;
    a2cmmn_1.iis = iisis;
/* ... */
/* ... PLNCS ... USED TO DETERMINE IF TANGENCY POINT HAS BEEN REACHED. */
/* L1200: */
    avdot_(&a2cmmn_1.tn[a2cmmn_1.it - 1], &a2cmmn_1.tn[a2cmmn_1.is - 1], &
	    a2cmmn_1.plncs[a2cmmn_1.is - 1]);
/* ... *********************************************************** 06 *** */
    adyndp_(&ab[12], &c__6, &c_b9);
/* ... */
/* L1210: */
    if (a2cmmn_1.eps2[a2cmmn_1.is - 1] - (d__1 = a2cmmn_1.plncs[a2cmmn_1.is - 
	    1], abs(d__1)) >= 0.) {
	goto L1240;
    } else {
	goto L1220;
    }
/* ... */
/* ... PRETTY NEAR THE TANGENCY POINT. SET DPLAN=TN(NON-TANGENT SURFACE) */
L1220:
    if (a2cmmn_1.cplfl[a2cmmn_1.is - 1] != 0.) {
	goto L1250;
    } else {
	goto L1230;
    }
L1230:
    avsto_(&a2cmmn_1.tn[itt - 1], &a2cmmn_1.dplan[a2cmmn_1.is - 1]);
    goto L1250;
/* ... NOT NEAR TANGENCY POINT YET. SET DPLAN=TN(CS)XTN(TANGENT SURFACE) */
L1240:
    avcros_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.tn[a2cmmn_1.it - 1], &
	    a2cmmn_1.dplan[a2cmmn_1.is - 1]);
/* ... */
/* ... */
/* ... IS TANGENT SURFACE A PLANE. */
L1250:
    if (a2cmmn_1.ipl[a2cmmn_1.iit - 1] != 0) {
	goto L1600;
    } else {
	goto L1260;
    }
/* ... */
/* ... TANGENT SURFACE IS A PLANE. */
L1600:
    if ((d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(d__1)) - a2fpc_1.q4500p >= 
	    0.) {
	goto L1620;
    } else {
	goto L1610;
    }
/* ... CHECK SURFACE IS NOT A PLANE. */
L1610:
    avsto_(&a2cmmn_1.tn[a2cmmn_1.it - 1], a2cmmn_1.temp);
    goto L1380;
/* ... */
/* ... BOTH TANGENT AND CHECK SURFACES APPEAR TO BE PLANES. */
L1620:
    a2cmmn_1.cptst[a2cmmn_1.is - 1] = -a2fpc_1.q1p;
    a2cmmn_1.cplfl[a2cmmn_1.is - 1] = -a2fpc_1.q1p;
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = a2cmmn_1.s[a2cmmn_1.is - 1];
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], &a2cmmn_1.plnv[a2cmmn_1.is - 1]);
L9998:
    a2cmmn_1.jcpr = 0;
L9999:
    a2cmmn_1.rc[a2cmmn_1.is - 1] = a2cmmn_1.temp[19];
/* ... *********************************************************** EX *** */
    adyndp_(&ab[14], &c__11, &c_b5);
    adyndp_(&ab[14], &c__4, &c_b5);
/* .................. RETURN ....... */
    goto L5000;
/* ... */
/* ... */
/* ... TANGENT SURFACE IS NOT A PLANE. CALL ACCURV. REMEMBER TEM IS THE */
/* ... SP ON THE TANGENT SURFACE. */
L1260:
    accurv_(&a2cmmn_1.it, &a2cmmn_1.iit, &a2cmmn_1.sp[a2cmmn_1.it - 1], 
	    a2cmmn_1.tem, &a2cmmn_1.sn[a2cmmn_1.it - 1]);
/* L1310: */
    if ((d__1 = a2cmmn_1.rc[a2cmmn_1.it - 1], abs(d__1)) - a2cmmn_1.rc1 >= 0.)
	     {
	goto L1600;
    } else {
	goto L1320;
    }
/* ... */
L1320:
    if (a2cmmn_1.ipl[a2cmmn_1.iis - 1] != 0) {
	goto L1340;
    } else {
	goto L1330;
    }
/* ... CS IS A PLANE. TANGENT SURFACE IS NOT A PLANE. */
L1340:
    avsto_(&a2cmmn_1.cc[a2cmmn_1.it - 1], &a2cmmn_1.cc[a2cmmn_1.is - 1]);
    avsto_(&a2cmmn_1.tn[a2cmmn_1.is - 1], a2cmmn_1.temp);
/* ... *********************************************************** 07 *** */
    adyndp_(&ab[16], &c__6, &c_b9);
/* ... GO CALCULATE PLNV(ICS) ***** */
    goto L1380;
/* ... */
/* ... CHECK SURFACE IS NOT A PLANE. BUT IF RC(CS) > 4500, ASSUME IT IS. */
L1330:
    if ((d__1 = a2cmmn_1.rc[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.rc1 >= 0.)
	     {
	goto L1340;
    } else {
	goto L1370;
    }
/* ... */
/* ... BOTH CS AND TANGENT SURFACE NOT PLANES. SET TEMP=VECTOR BETWEEN */
/* ... TWO RESPECTIVE CENTERS OF CURVATURE. */
L1370:
    avsub_(&a2cmmn_1.cc[a2cmmn_1.it - 1], &a2cmmn_1.cc[a2cmmn_1.is - 1], 
	    a2cmmn_1.temp);
    avnorm_(a2cmmn_1.temp, a2cmmn_1.temp, &a2cmmn_1.ier);
/* ... *********************************************************** 08 *** */
    adyndp_(&ab[18], &c__6, &c_b9);
    if (a2cmmn_1.ier != 0) {
	goto L1340;
    } else {
	goto L1380;
    }
/* ... */
L1380:
    avcros_(a2cmmn_1.temp, &a2cmmn_1.dplan[a2cmmn_1.is - 1], &a2cmmn_1.plnv[
	    a2cmmn_1.is - 1]);
    avnorm_(&a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.plnv[a2cmmn_1.is - 1], 
	    &a2cmmn_1.ier);
    adyndp_(&ab[20], &c__6, &c_b9);
/* L1390: */
    if (a2cmmn_1.ier != 0) {
	goto L1400;
    } else {
	goto L1410;
    }
L1410:
    avsub_(&a2cmmn_1.tp[a2cmmn_1.it - 1], a2cmmn_1.te, a2cmmn_1.temp);
/* L1420: */
    avdot_(a2cmmn_1.temp, a2cmmn_1.temp, &a2cmmn_1.temp[3]);
    avdot_(a2cmmn_1.temp, &a2cmmn_1.tn[a2cmmn_1.it - 1], &a2cmmn_1.temp[4]);
    a2cmmn_1.temp[4] *= a2cmmn_1.temp[4];
/* L1430: */
    avdot_(a2cmmn_1.ta, &a2cmmn_1.tn[a2cmmn_1.it - 1], &a2cmmn_1.cplfl[
	    a2cmmn_1.is - 1]);
    adyndp_(&ab[22], &c__6, &c_b9);
    if (a2cmmn_1.cplfl[a2cmmn_1.is - 1] - a2fpc_1.qp0001 >= 0.) {
	goto L1445;
    } else {
	goto L1440;
    }
L1445:
    avsub_(&a2cmmn_1.cc[a2cmmn_1.is - 1], &a2cmmn_1.tp[a2cmmn_1.it - 1], 
	    a2cmmn_1.vtem);
    avdot_(a2cmmn_1.vtem, &a2cmmn_1.plnv[a2cmmn_1.is - 1], &a2cmmn_1.plnd[
	    a2cmmn_1.is - 1]);
    adyndp_(&ab[24], &c__6, &c_b9);
    goto L1510;
L1440:
    if ((d__1 = a2cmmn_1.cplfl[a2cmmn_1.is - 1], abs(d__1)) - a2cmmn_1.eps2[
	    a2cmmn_1.is - 1] <= 0.) {
	goto L1450;
    } else {
	goto L1480;
    }
L1450:
    if (a2fpc_1.qp5x01 - (d__1 = a2cmmn_1.cplfl[a2cmmn_1.is - 1], abs(d__1)) 
	    <= 0.) {
	goto L1460;
    } else {
	goto L1480;
    }
L1460:
    a2cmmn_1.a = a2fpc_1.q1p;
    if (a2cmmn_1.cplfl[a2cmmn_1.is - 1] < a2fpc_1.qnul) {
	a2cmmn_1.a = -a2fpc_1.q1p;
    }
    temp1 = a2cmmn_1.a * sqrt((a2cmmn_1.temp[3] - a2cmmn_1.temp[4]) / (
	    a2fpc_1.q1p - a2cmmn_1.cplfl[a2cmmn_1.is - 1] * a2cmmn_1.cplfl[
	    a2cmmn_1.is - 1]));
/* L1470: */
    avmult_(a2cmmn_1.ta, &temp1, a2cmmn_1.vtem);
    avsub_(a2cmmn_1.vtem, a2cmmn_1.te, a2cmmn_1.cmove);
    adyndp_(&ab[26], &c__6, &c_b9);
    goto L1500;
L1400:
    a2cmmn_1.jcpr = 1;
    goto L9999;
L1480:
    avsub_(&a2cmmn_1.tp[a2cmmn_1.it - 1], a2cmmn_1.te, a2cmmn_1.vtem);
    avdot_(a2cmmn_1.ta, a2cmmn_1.vtem, &temp1);
/* L1490: */
    a2cmmn_1.cmove[0] = -a2cmmn_1.te[0] - temp1 * a2cmmn_1.ta[0];
    a2cmmn_1.cmove[1] = -a2cmmn_1.te[1] - temp1 * a2cmmn_1.ta[1];
    a2cmmn_1.cmove[2] = -a2cmmn_1.te[2] - temp1 * a2cmmn_1.ta[2];
L1500:
    a2cmmn_1.plnd[a2cmmn_1.is - 1] = (a2cmmn_1.cc[a2cmmn_1.is - 1] + 
	    a2cmmn_1.cmove[0]) * a2cmmn_1.plnv[a2cmmn_1.is - 1] + (
	    a2cmmn_1.cc[a2cmmn_1.is] + a2cmmn_1.cmove[1]) * a2cmmn_1.plnv[
	    a2cmmn_1.is] + (a2cmmn_1.cc[a2cmmn_1.is + 1] + a2cmmn_1.cmove[2]) 
	    * a2cmmn_1.plnv[a2cmmn_1.is + 1];
L1510:
    a2cmmn_1.cplfl[a2cmmn_1.is - 1] = a2fpc_1.q1p;
L1520:
    a2cmmn_1.cptst[a2cmmn_1.is - 1] += a2cmmn_1.cplfl[a2cmmn_1.is - 1];
    adyndp_(&ab[28], &c__6, &c_b9);
/* L1530: */
    if (a2cmmn_1.cptst[a2cmmn_1.is - 1] != 0.) {
	goto L9998;
    } else {
	goto L1520;
    }
L5000:
    return 0;
} /* acplan_ */

#undef ab


