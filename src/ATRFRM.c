/* ATRFRM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int atrfrm_()
{
    /* Format strings */
    static char fmt_20[] = "(\0020THIS SURFACE IS NOT TRANSFORMED, \002a6\
,\002 (\002i4,\002)\002/\002 \002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int atdl_();
#define kstyp ((integer *)&adfsto_1)
    extern /* Subroutine */ int acanck_(), atfmqd_(), atfmvc_();

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, fmt_20, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/*     CHECK SURFACE TYPE */
    if (*kstyp - 15 >= 0) {
	goto L10;
    } else {
	goto L30;
    }
L10:
    io___2.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___2);
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
L30:
    switch ((int)*kstyp) {
	case 1:  goto L300;
	case 2:  goto L100;
	case 3:  goto L100;
	case 4:  goto L200;
	case 5:  goto L200;
	case 6:  goto L400;
	case 7:  goto L400;
	case 8:  goto L200;
	case 9:  goto L400;
	case 10:  goto L400;
	case 11:  goto L500;
	case 12:  goto L10;
	case 13:  goto L300;
	case 14:  goto L400;
    }
/*     LINES AND PLANES */
L100:
    atdl_();
    goto L900;
/*     CIRCLE,CYLINDER,CONE */
L200:
    atfmvc_(&a0con_1.k1);
    atfmvc_(&a0con_1.k0);
    goto L900;
/*     POINT,SPHERE */
L300:
    atfmvc_(&a0con_1.k1);
    goto L900;
/*     QUADRICS */
L400:
    atfmqd_();
    goto L900;
/*     VECTORS */
L500:
    i__1 = -a0con_1.k1;
    atfmvc_(&i__1);

/* ...     CALL ROUTINE TO CHECK FOR PROPER NORMALIZATION OF */
/* ...     TRANSFORMED CANONICAL FORM */
L900:
    acanck_(kstyp);

    return 0;
} /* atrfrm_ */

#undef kstyp


