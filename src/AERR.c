/* AERR.f -- translated by f2c (version 20000121).
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
    doublereal adum[75], eps1[1], eps2[1], eps3[1], eps4[1], eps6[1], eps8[1],
	     tau[1], tau1[1], tau2[1], aaadum[516];
    integer iiidum[5], isftyp[1], itlon[1], jjjdum[233];
    doublereal bbbdum[536];
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
    integer kdynfq[12], nkfq;
} a2dydp_;

#define a2dydp_1 a2dydp_

struct {
    doublereal svtau1, svtau2, svtau, sveps1, sveps8, sveps2, sveps3, sveps4, 
	    sveps6;
    integer mtau;
} taumd1_;

#define taumd1_1 taumd1_

struct {
    doublereal savtt, savto, savti, savt1, savt2, savt3, savt4, savt6, savt8;
    integer ismata, iismat, kchnge, kon, kst;
} taumd2_;

#define taumd2_1 taumd2_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;
static integer c__8 = 8;
static integer c__13000 = 13000;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c_b67 = 111111;
static integer c__9 = 9;

/* Subroutine */ int aerr_(karg)
integer *karg;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	real e_2;
	} equiv_15 = { {'*', '*', 'A', 'E', 'R', 'R', '*', '*'}, (float)0. };

#define ab ((real *)&equiv_15)

    static integer lnrec = 0;
    static integer lnw = 0;

    /* Format strings */
    static char fmt_1000[] = "(\0020\002/\002 ERROR OR WARNING NO. \002i5/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ii;
    static doublereal arg;
    static integer ker, ist, iarg, iswt;
    extern /* Subroutine */ int asec2_();
    static integer istx2;
    extern /* Subroutine */ int atape_();
    static integer isave[10], ibmsv;
    extern /* Subroutine */ int astor_(), asec2c_(), bdyndp_();
    static integer icount;
    extern /* Subroutine */ int atapwt_();

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 0, 0, fmt_1000, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*    INITIALIZE AMIND RETURN FLAG */
    a2cmmn_1.jmin = 0;
    if (*karg < 0) {
	goto L88881;
    } else if (*karg == 0) {
	goto L900;
    } else {
	goto L88882;
    }
L88881:
    if (icount >= 5) {
	goto L88882;
    }
    goto L88884;
L88882:
    if (taumd1_1.mtau != 1) {
	goto L88883;
    }
    a2cmmn_1.tau1[a2cmmn_1.ics - 1] = taumd1_1.svtau1;
    a2cmmn_1.tau2[a2cmmn_1.ics - 1] = taumd1_1.svtau2;
    a2cmmn_1.tau[a2cmmn_1.ics - 1] = taumd1_1.svtau;
    a2cmmn_1.eps1[a2cmmn_1.ics - 1] = taumd1_1.sveps1;
    a2cmmn_1.eps8[a2cmmn_1.ics - 1] = taumd1_1.sveps8;
    a2cmmn_1.eps2[a2cmmn_1.ics - 1] = taumd1_1.sveps2;
    a2cmmn_1.eps3[a2cmmn_1.ics - 1] = taumd1_1.sveps3;
    a2cmmn_1.eps4[a2cmmn_1.ics - 1] = taumd1_1.sveps4;
    a2cmmn_1.eps6[a2cmmn_1.ics - 1] = taumd1_1.sveps6;
    taumd1_1.mtau = 0;
L88883:
    if (taumd2_1.kchnge != 1) {
	goto L88884;
    }
    a2cmmn_1.tau[taumd2_1.ismata - 1] = taumd2_1.savtt;
    a2cmmn_1.tau1[taumd2_1.ismata - 1] = taumd2_1.savto;
    a2cmmn_1.tau2[taumd2_1.ismata - 1] = taumd2_1.savti;
    a2cmmn_1.eps1[taumd2_1.ismata - 1] = taumd2_1.savt1;
    a2cmmn_1.eps2[taumd2_1.ismata - 1] = taumd2_1.savt2;
    a2cmmn_1.eps3[taumd2_1.ismata - 1] = taumd2_1.savt3;
    a2cmmn_1.eps4[taumd2_1.ismata - 1] = taumd2_1.savt4;
    a2cmmn_1.eps6[taumd2_1.ismata - 1] = taumd2_1.savt6;
    a2cmmn_1.eps8[taumd2_1.ismata - 1] = taumd2_1.savt8;
    a2cmmn_1.itlon[taumd2_1.iismat - 1] = taumd2_1.kon;
    a2cmmn_1.isftyp[taumd2_1.iismat - 1] = taumd2_1.kst;
    taumd2_1.kchnge = 0;
/* ... */
L88884:
/*      DIMENSION AB(2), ISAVE(10) */
/*       DATA AB(1),AB(2)/4H**AE,4HRR*+/ */
/* ... */
/* ...             OUTPUT ANY POINTS IN BUFFER */
/* ... */
    iarg = *karg;
/* ...IARG=ACTUAL MESSAGE NUMBER */
    if (iarg < 0) {
	goto L10;
    } else if (iarg == 0) {
	goto L900;
    } else {
	goto L20;
    }
L10:
    if (a2cmmn_1.nw == lnw && a2cmmn_1.nrec == lnrec) {
	goto L30;
    }
    icount = 1;
    lnw = a2cmmn_1.nw;
    lnrec = a2cmmn_1.nrec;
    goto L31;
L20:
    isave[0] = iarg;
    a2cmmn_1.iautps = 0;
    icount = 1;
    ist = 1;
    goto L46;
L30:
    ++icount;
L31:
    isave[icount - 1] = iarg;
    if (icount - 6 >= 0) {
	goto L40;
    } else {
	goto L35;
    }
L35:
    if (a2cmmn_1.ivamax - 3 >= 0) {
	goto L44;
    } else {
	goto L900;
    }
L40:
    iarg = 2201;
    ++icount;
    isave[icount - 1] = iarg;
    if (a2cmmn_1.ivamax <= 2) {
	goto L45;
    }
L44:
    ist = icount;
    goto L46;
L45:
    ist = 1;
L46:
    atape_();
    a2cmmn_1.nw = 0;
    iswt = 0;
    if (a2cmmn_1.il != 0) {
	goto L400;
    }
    if (asistm_1.iclprt == 1) {
	goto L400;
    }
    if (iarg < 0) {
	goto L200;
    } else if (iarg == 0) {
	goto L900;
    } else {
	goto L300;
    }
L200:
    astor_(&c__1, &c__4, &arg, &c__8);
    ++asistm_1.nclrec;
    iswt = 1;
    atapwt_(&ataptb_1.cltape, &ker, &c__4, &asistm_1.nclrec, &c__1, &c__13000,
	     &c__1, &c__4, &c__1, &arg, &c__1, &arg, &c__0, &arg, &c__0);
    asistm_1.iclprt = -1;
/* ...    FLAG SECTION 3 */
    asistm_1.kflags[3] = 1;
    goto L400;
L300:
    asistm_1.iclprt = 1;
L400:
    i__1 = icount;
    for (ii = ist; ii <= i__1; ++ii) {
	++asistm_1.nclrec;
	astor_(&isave[ii - 1], &c__4, &arg, &c__8);
	atapwt_(&ataptb_1.cltape, &ker, &c__4, &asistm_1.nclrec, &c__1, &
		c__13000, &c__1, &c__3, &c__1, &arg, &c__1, &arg, &c__0, &arg,
		 &c__0);
/* L450: */
    }
    if (iswt != 0) {
	goto L500;
    } else {
	goto L590;
    }
L500:
    ++asistm_1.nclrec;
    astor_(&c__0, &c__4, &arg, &c__8);
    atapwt_(&ataptb_1.cltape, &ker, &c__4, &asistm_1.nclrec, &c__1, &c__13000,
	     &c__1, &c__4, &c__1, &arg, &c__1, &arg, &c__0, &arg, &c__0);
/*                OUTPUT ERROR COMMENT */
L590:
    if (iarg < 0) {
	goto L600;
    } else if (iarg == 0) {
	goto L900;
    } else {
	goto L610;
    }
L600:
    switch ((int)a2cmmn_1.ivamax) {
	case 1:  goto L900;
	case 2:  goto L900;
	case 3:  goto L750;
	case 4:  goto L800;
    }
L610:
    switch ((int)a2cmmn_1.ivamax) {
	case 1:  goto L850;
	case 2:  goto L750;
	case 3:  goto L750;
	case 4:  goto L800;
    }
L750:
    if (a2cmmn_1.i3 != 0) {
	goto L800;
    } else {
	goto L840;
    }
L800:
    a2dydp_1.nkfq = 1;
    ibmsv = a2dydp_1.kdynfq[0];
    a2dydp_1.kdynfq[0] = 1;
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    do_fio(&c__1, (char *)&iarg, (ftnlen)sizeof(integer));
    e_wsfe();
    bdyndp_(ab, &c__1, &c_b67);
    a2dydp_1.kdynfq[0] = ibmsv;
    a2dydp_1.nkfq = 1;
L840:
    if (iarg <= 0) {
	goto L900;
    } else {
	goto L850;
    }
L850:
    asistm_1.iwaven = 2;
    a2cmmn_1.irstrt = 1;
    icount = 0;
/* ...  UNRECOVERABLE ERROR FROM ASEC2 - TERMINATE. */
    if (iarg == 10 || iarg == 41) {
	asec2c_(&c__9, &istx2);
    }
    asec2_();
L900:
    return 0;
} /* aerr_ */

#undef ab


