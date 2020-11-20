/* ACCALL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Table of constant values */

static integer c__17 = 17;

/* Subroutine */ int accall_()
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer it, jv;
#define ipt ((integer *)&aptpp_1)
    extern doublereal afull8_();
    extern integer ibclas_(), amdtoa_();
    extern /* Subroutine */ int aptlod_();
    extern integer aextra_(), iatype_();
    extern /* Subroutine */ int aptput_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*     SET UP CLASS 17 PTPP - SPECIAL PROGRAM CALL */
    aptpp_1.jmode = 5;
    aptpp_1.nw = -a0con_1.k1;
    aptpp_1.npt = 0;
    aprtab_1.itsq = 0;
    aptpp_1.pt[0] = afull8_(&c__17, &a0con_1.k0);
/*     PICK UP SPECIAL PROGRAM NAME */
    aptpp_1.pt[1] = ailmtb_1.elment[aprtab_1.istarp - 4];
    it = 0;
/*     CHECK FORMAT OF PARAMETERS (IF ANY) */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L20;
    }
    jv = aprtab_1.istarp + 2;
    if (jv > ailmtb_1.jlment) {
	goto L10;
    }
    if (iatype_(&jv) != a0con_1.k4) {
	goto L10;
    }
    if (ibclas_(&jv) != a0con_1.k8) {
	goto L10;
    }
    it = a0con_1.k2;
    goto L20;
L10:
    it = a0con_1.k1;
/*     SET SEC1 OR SEC2 CALL */
L20:
    i__1 = aprtab_1.istarp - 1;
    jv = ibclas_(&i__1);
    if (aextra_(&jv, &a0con_1.k2) != 31) {
	goto L60;
    }
    i__1 = amdtoa_(&jv, &a0con_1.k2);
    aptpp_1.pt[2] = afull8_(&i__1, &it);
    aptpp_1.inptp = a0con_1.k4;
/*     SET UP PARAMETER LIST (IF ANY) */
    if (aprtab_1.istarp > ailmtb_1.jlment) {
	goto L40;
    }

L25:
    if (iatype_(&aprtab_1.istarp) != 4) {
	goto L90;
    }
    if (ibclas_(&aprtab_1.istarp) != 9) {
	goto L90;
    }
    ++aprtab_1.istarp;
    if (it == a0con_1.k1) {
	goto L30;
    }
/*     SET ALPHAMERIC NAME */
    if (iatype_(&aprtab_1.istarp) != 1) {
	goto L60;
    }
    aptpp_1.pt[aptpp_1.inptp - 1] = ailmtb_1.elment[aprtab_1.istarp - 1];
    ++aprtab_1.istarp;
    ++aptpp_1.inptp;
/* ...     CHECK FOR = SIGN */
    if (iatype_(&aprtab_1.istarp) != 4) {
	goto L100;
    }
    if (ibclas_(&aprtab_1.istarp) != 8) {
	goto L100;
    }
    ++aprtab_1.istarp;

/* ... MOVE PARAMETER TO PT */
L30:
    aptlod_();
/* ...     CHECK FOR PARAMETER IN ERROR */
    if (a1com_1.jsuber != 0) {
	goto L110;
    }
    if (aprtab_1.istarp <= ailmtb_1.jlment) {
	goto L50;
    }
/*     SET PTPP JMODE FOR FINAL PARAMETER */
L40:
    if (aptpp_1.jmode != 5) {
	aptpp_1.jmode = 3;
    }
    --aptpp_1.inptp;
    aptpp_1.nw += aptpp_1.inptp;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.nw;
    goto L115;
L50:
    if (aptpp_1.inptp <= 296) {
	goto L25;
    }
    if (aptpp_1.jmode == 5) {
	aptpp_1.jmode = 1;
    }
    aptput_();
    aptpp_1.jmode = 2;
    aptpp_1.inptp = a0con_1.k1;
    goto L25;
/*     INCORRECT FORMAT FOR SPECIAL PROGRAM CALL */
L60:
    a1com_1.jsuber = 226;
    goto L110;
/*     ILLEGAL VARIABLE SYMBOL - ID OR MACRO NAME */
/*     NO COMMA */
L90:
    a1com_1.jsuber = 234;
    goto L110;
/*     NO = SIGN */
L100:
    a1com_1.jsuber = 229;
/*     ABORT THIS PTPP CLASS */
L110:
    aptpp_1.jmode = a0con_1.k4;
L115:
    aptput_();
    return 0;
} /* accall_ */

#undef ipt


