/* ASEC2B.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal adentc, adent, adummy, ans;
} a2burp_;

#define a2burp_1 a2burp_

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
	    qnul, qpie, qfil[9];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__2 = 2;
static integer c__8 = 8;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__312 = 312;

/* Subroutine */ int asec2b_(istx1, istx2)
integer *istx1, *istx2;
{
    /* Initialized data */

    static doublereal tabid[25] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static integer numid = 0;

    /* Format strings */
    static char fmt_610[] = "(\002 \002,\002ID TABLE FULL - CHECK FOR BAD MU\
LTI-CS OR TRANTO BRANCHING\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    static integer i__, kk;
#define sinl ((doublereal *)&a2ctdf_1 + 1)
#define cosl ((doublereal *)&a2ctdf_1 + 2)
#define ipro ((integer *)&a2cmmn_ + 2616)
#define ktem ((shortint *)&a2cmmn_ + 3824)//guessing on this one..think its referencing a int
    extern /* Subroutine */ int aerr_();
    static integer iik;
    extern /* Subroutine */ int atape_(), astor_(), astos_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int atlseg_(), aserch_(), cdyndp_(), arpdis_();
    static integer nummax;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 0, 0, fmt_610, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ... A2CMMN START */
/* ... A2CMMN END */
/*     ***** */
/*     ***** */
/*     ***** */
/* ... */
/* ... */
/* ...IF ISTX1=6078, CLASS=6000 AND SUBCLASS=7 OR 8 */
/*   CALLED FROM ASEC2 RIGHT AFTER ATAPRD(PROTAP...) */
    if (*istx1 == 6078) {
	goto L607;
    }
/* ... */
    switch ((int)*istx1) {
	case 1:  goto L6000;
	case 2:  goto L6300;
	case 3:  goto L8300;
	case 4:  goto L8000;
    }
/*      ALSO, DO NOT PROCESS INTOF RECORDS WHEN NOT RESTARTING */
L6300:
    if (a2cmmn_.instr2 == 7 || a2cmmn_.instr2 == 8) {
	goto L8300;
    }
    if (a2cmmn_.instr2 == 3) {
	goto L200;
    }
    goto L6000;
/*     MOTION DIRECTION FOR CUTSEQ INITIALIZE + READ PROTAP */
L8300:
    a2cmmn_.igtflg = 0;
    a2cmmn_.indir__[a2cmmn_.iips - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iids - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iics - 1] = 0;
    a2cmmn_.icscnt = 0;
    goto L200;



/*     6000 CLASS FLAGS + SWITCHES */
L6000:
    if (a2cmmn_.instr2 > 9) {
	aerr_(&c__2);
    }
    switch ((int)a2cmmn_.instr2) {
	case 1:  goto L6010;
	case 2:  goto L6020;
	case 3:  goto L6030;
	case 4:  goto L6040;
	case 5:  goto L6040;
	case 6:  goto L6060;
	case 7:  goto L607;
	case 8:  goto L607;
	case 9:  goto L6090;
    }

/*     -GET INTEGER FROM PROBUF     CUT,DNTCUT */
L6010:
    astor_(a2cmmn_.probuf, &c__8, &i__, &c__2);
/*     IF NOT MODE CHANGE, OUTPUT + IGNORE */
    if (i__ == a2cmmn_.icut) {
	goto L2000;
    }
    if (i__ != 0) {
	goto L6011;
    }
/*     CHANGE FROM DONT CUT TO CUT- OUTPUT POINT */
    a2cmmn_.nw = 0;
    a2cmmn_.icl = 5;
    astos_();
    a2cmmn_.icut = 0;
    atape_();
    goto L2000;
L6011:
    a2cmmn_.icut = 1;
    if (i__ == 2) {
	a2cmmn_.icut = -1;
    }
    ipro[OTHER_ENDIAN_S(1)] = 1;
    goto L2000;
/*     I3DCALC FLAG */
L6020:
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.i3dflg, &c__2);
    goto L2000;
/*     IFAR */
L6030:
    i__ = a2cmmn_.lisv * (a2cmmn_.icscnt + 2) + 1;
    a2burp_1.ans = a2cmmn_.probuf[0];
    iik = (integer) a2burp_1.ans;
    a2cmmn_.ifar[i__ - 1] = iik;
    goto L200;

/*     TOLERANCES */
L6040:
    i__1 = a2cmmn_.nwds;
    for (a2cmmn_.k = 1; a2cmmn_.k <= i__1; ++a2cmmn_.k) {
	i__ = a2cmmn_.lsv * (a2cmmn_.k - 1) + 1;
/*     INTOL OR OUTTOL */
	if (a2cmmn_.instr2 == 4) {
	    goto L6041;
	}
/*     OUTTOL */
	a2cmmn_.tau1[i__ - 1] = a2cmmn_.probuf[a2cmmn_.k - 1];
	goto L6045;
/*     INTOL */
L6041:
	a2cmmn_.tau2[i__ - 1] = -a2cmmn_.probuf[a2cmmn_.k - 1];

/*     SET UP OTHER EPSILONS */
L6045:
	a2cmmn_.tau[i__ - 1] = a2cmmn_.tau1[i__ - 1] - a2cmmn_.tau2[i__ - 
		1];
	a2cmmn_.eps1[i__ - 1] = a2fpc_1.qp1 * a2cmmn_.tau[i__ - 1];
	a2cmmn_.eps8[i__ - 1] = a2cmmn_.eps1[i__ - 1];
	a2cmmn_.eps2[i__ - 1] = a2fpc_1.q1p - a2cmmn_.eps1[i__ - 1];
	a2cmmn_.eps3[i__ - 1] = a2fpc_1.qp9 * a2cmmn_.eps1[i__ - 1];
	a2cmmn_.eps4[i__ - 1] = a2fpc_1.q2p * a2cmmn_.tau[i__ - 1];
/* L6049: */
	a2cmmn_.eps6[i__ - 1] = a2fpc_1.qp02 * a2cmmn_.eps1[i__ - 1];
    }
    a2cmmn_.cend[0] = a2fpc_1.qnul;
    goto L2000;

/*     CUTTER DEFINITION */
L6060:
    if (a2cmmn_.nwds != 3) {
	goto L6160;
    }
/*      OPTION CUTTER */
    a2cmmn_.ra = a2cmmn_.probuf[1];
    a2cmmn_.hi = a2cmmn_.probuf[2];
    a2burp_1.ans = a2cmmn_.probuf[0];
    a2cmmn_.k = (integer) a2burp_1.ans;
    a2cmmn_.jtlflg[a2cmmn_.iips - 1] = 0;
    a2cmmn_.jtlflg[a2cmmn_.iids - 1] = 0;
    if (a2cmmn_.k == 1) {
	a2cmmn_.jtlflg[a2cmmn_.iips - 1] = 1;
    }
    if (a2cmmn_.k == 2) {
	a2cmmn_.jtlflg[a2cmmn_.iids - 1] = 1;
    }
    goto L2000;
L6160:
    for (a2cmmn_.k = 1; a2cmmn_.k <= 7; ++a2cmmn_.k) {
/* L6061: */
	a2cmmn_.cutdat[a2cmmn_.k - 1] = a2fpc_1.qnul;
    }
    i__1 = a2cmmn_.nwds;
    for (a2cmmn_.k = 1; a2cmmn_.k <= i__1; ++a2cmmn_.k) {
/* L6062: */
	a2cmmn_.cutdat[a2cmmn_.k - 1] = a2cmmn_.probuf[a2cmmn_.k - 1];
    }
    atlseg_();
    a2cmmn_.icdefl = 1;
/*      TO INDICATE THAT THE CUTTER IS DEFINED */
    goto L2000;

/*     TRANTO */
L6070:
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.itrflg, &c__2);
    a2burp_1.adentc = a2cmmn_.probuf[1];
L6071:
    a2cmmn_.isrch = 2;
/*     SEE IF FWD OR BACKWARD TRANSFER */
/* L6072: */
    if (a2cmmn_.itrflg == 0) {
	goto L200;
    }
/*     NO, BACKWARD */
    aserch_(&ataptb_1.protap, &a2cmmn_.itrflg, &a2cmmn_.ier);
/*       INSERT ERROR FLAG TEST */
    goto L200;

/*     MULTI CS TRANSFER */
L6080:
    a2cmmn_.k = (a2cmmn_.icscnt + 1) * a2cmmn_.lsv + 1;
    a2cmmn_.ik = (a2cmmn_.icscnt + 1) * a2cmmn_.lisv + 1;
    astor_(a2cmmn_.probuf, &c__8, &a2cmmn_.icstr[a2cmmn_.ik - 1], &c__2);
    a2cmmn_.adcs[a2cmmn_.k - 1] = a2cmmn_.probuf[1];
    goto L200;

/*      DYNDMP  ---   SET  PARAMETERS */
L6090:

/* ...  SET DYNAMIC DUMPING FREQUENCIES */

    if (a2cmmn_.nwds < 2) {
	goto L200;
    }
    a2dydp_1.kdynfq[6] = 0;
    i__1 = a2cmmn_.nwds;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	a2burp_1.ans = a2cmmn_.probuf[i__ - 1];
	a2cmmn_.k = (integer) a2burp_1.ans;
	a2burp_1.ans = a2cmmn_.probuf[i__];
	if (a2cmmn_.k > 0) {
	    goto L6092;
	}
	kk = (integer) a2burp_1.ans;
	cdyndp_(&c__1, &kk);
	goto L6091;
L6092:
	a2dydp_1.kdynfq[a2cmmn_.k - 1] = (integer) a2burp_1.ans;
L6091:
	;
    }
    a2dydp_1.nkfq = 1;
    a2cmmn_.k = 0;
    for (i__ = 1; i__ <= 12; ++i__) {
	if (a2dydp_1.kdynfq[i__ - 1] == 0) {
	    goto L6093;
	}
	a2cmmn_.k = 1;
L6093:
	;
    }
    cdyndp_(&c__3, &a2cmmn_.k);
    goto L200;

/*     GO COMMAND */
/*     SET IGO */
L8000:
    a2cmmn_.igo = a2cmmn_.instr2;
    a2cmmn_.istrup = 0;
/*     IF CUTTER NOT DEFINED ERROR */
    if (a2cmmn_.icdefl == 0) {
	aerr_(&c__312);
    }
/* ... */
    arpdis_();
/* ... */
/*     SEE IF MULTICS */
    if (a2cmmn_.icscnt <= 1) {
	goto L8001;
    }
/*     SET UP INFO FOR TRANTO */
    a2burp_1.adentc = a2cmmn_.adcs[a2cmmn_.is - 1];
    a2cmmn_.itrflg = a2cmmn_.icstr[a2cmmn_.iis - 1];
    i__ = 1;
    goto L8002;
/*     NO T MULTI CS */
L8001:
    i__ = 0;
/*     RESET */
L8002:
    a2cmmn_.icscnt = 0;
    a2cmmn_.indir__[a2cmmn_.iips - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iids - 1] = 0;
    a2cmmn_.indir__[a2cmmn_.iics - 1] = 0;
    a2cmmn_.isvfl[a2cmmn_.iips - 1] = 0;
    a2cmmn_.isvfl[a2cmmn_.iids - 1] = 0;
    a2cmmn_.isvfl[a2cmmn_.iics - 1] = 0;
/*     RESET INTERSECTION COUNTER */
    i__1 = a2cmmn_.numsfs;
    for (a2cmmn_.k = 3; a2cmmn_.k <= i__1; ++a2cmmn_.k) {
	kk = (a2cmmn_.k - 1) * a2cmmn_.lisv + 1;
/* L8005: */
	a2cmmn_.ifar[kk - 1] = 1;
    }
/*     IF MULTICS, GO TO MULT CS TRANSFER AREA */
    if (i__ != 0) {
	goto L6071;
    }
    goto L200;
L200:
    *istx2 = a0con_1.k1;
    return 0;
L2000:
    *istx2 = a0con_1.k2;
    return 0;
/* *********************************************************************** */

/* ...UPON ENTRY, JUMP IS MADE TO 607 WHEN CLASS=6000 AND */
/*                                        SUBCLASS=7 ... TRANTO/ID  OR */
/*                                                = 8 ... MULTI-CS */
/* ...WHEN TEMP(1)=PROBUF(2) AND KTEM(4)=KND ARE EXECUTED, TEMP(1) WILL */
/*   CONTAIN ALPHAMERIC NAME ID IN FIRST 6 BYTES AND ISN IN LAST 2 BYTES */
/*   NOTE.EQUIVALENCE(TEMP(1),KTEM(1)) */
/*       KTEM(1)=FIRST 2 BYTES OF TEMP(1) */
/*       KTEM(2)=SECOND 2 BYTES OF TEMP(1) */
/*       KTEM(3)=THIRD 2 BYTES OF TEMP(1) */
/*       KTEM(4)=FOURTH 2 BYTES OF TEMP(1) */
/* ...IF CURRENT ID IN QUESTION IS ALREADY IN TABID, FORCE FWD TRANSFER. */
/* ...ID IS SAVED IN TABID ONLY WHEN SEC.1 SAYS IT IS A FWD TRANSFER. */

L607:
    a2cmmn_.temp[0] = a2cmmn_.probuf[1];
    ktem[OTHER_ENDIAN_S(3)] = (shortint) a2cmmn_.knd;
    nummax = min(numid,25);
    i__1 = nummax;
    for (a2cmmn_.k = 1; a2cmmn_.k <= i__1; ++a2cmmn_.k) {
	if (a2cmmn_.temp[0] != tabid[a2cmmn_.k - 1]) {
	    goto L608;
	}
/* ...IF ISTX1=6078, JUST RETURN. */
	if (*istx1 == 6078) {
	    goto L200;
	}
	a2cmmn_.probuf[0] = a2fpc_1.qnul;
	goto L615;
L608:
	;
    }
    if (a2cmmn_.probuf[0] > a2fpc_1.qnul) {
	goto L615;
    }
    ++numid;
    if (numid < 25) {
	goto L609;
    }
    io___12.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___12);
    e_wsfe();
L609:
    a2cmmn_.k = numid % 25;
    tabid[a2cmmn_.k - 1] = a2cmmn_.temp[0];
/* ...IF ISTX1=6078, JUST RETURN. */
L615:
    if (*istx1 == 6078) {
	goto L200;
    }
    if (a2cmmn_.instr2 == 7) {
	goto L6070;
    }
    goto L6080;
} /* asec2b_ */

#undef tlldat
#undef ktem
#undef ipro
#undef cosl
#undef sinl


