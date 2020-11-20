/* ADPRNT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal xmat4[16], xmat3[16], xmat2[16], xmat1[16], tmatx[16];
} atmaty_;

#define atmaty_1 atmaty_

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal zsur[4];
} azurf_;

#define azurf_1 azurf_

static struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

static struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int adprnt_(ititle)
integer *ititle;
{
    /* Format strings */
    static char fmt_10[] = "(\0020\002,39x,\002*********DEBUG PRINT FOR \002\
,a4,a4,\002 *********\002)";
    static char fmt_35[] = "(\0020\002,58x,\002XMAT1-4\002/(36x,4f12.9))";
    static char fmt_45[] = "(\0020\002,58x,\002TMATX\002/(36x,4f12.9))";
    static char fmt_55[] = "(\0020\002,57x,\002DEFSTO\002/4x,3z20,3f16.9/(16\
x,6f16.9))";
    static char fmt_65[] = "(\0020\002,58x,\002CANON\002/4x,3z20,3f16.9/(16x\
,6f16.9))";
    static char fmt_75[] = "(\0020\002,57x,\002DEFTAB\002/(11x,5z20))";
    static char fmt_95[] = "(\0020\002,50x,\002PTPP FROM\002,i5/(11x,5z20))";
    static char fmt_105[] = "(\0020\002,58x,\002VST1\002/43x,a6,z20,f16.9)";
    static char fmt_175[] = "(\0020\002,58x,\002ZSUR\002/(30x,4f16.9))";
    static char fmt_185[] = "(\0020\002,58x,\002IRECN\002,i12)";
    static char fmt_190[] = "(7x,5z18)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer id, ii, id1, id2;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
#define deftab ((doublereal *)&avst_1 + 6200)

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_35, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_45, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_55, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_95, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_175, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_185, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_190, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* **** THIS ROUTINE IS CALLED TO PRINT VARIOUS TABLES WHEN DEBUG FLAG IS */
/*     ON. THE INPUT IS THE VARIABLE ITITLE AND THE COMMON BLOCK ADEBUG. */
/*     IF ITITLE IS NON-ZERO IT CONTAINSTHE NAME OF THE PROGRAM WHICH */
/*     REQUESTED THE PRINTING. */
/*     THE FOLLOWING IS PRINTED FOR IDEBUG(1) */
/*     =1, THEXMAT1-XMAT4 AND TMATX AREAS */
/*     =2, THE  TMATX AREA. */
/*     =3,THE DEFSTO AREA FROM DEFSTO(1)THRU DEFSTO(IDEBUG(2)). */
/*     =4, THE CANON AREA FROM CANON(IDEBUG(2)) THRU CANON(IDEBUG(3)). */
/*     =5, THE DEFTAB AREA FROM DEFTAB(IDEBUG(2)) THRU DEFTAB(IDEBUG(3) */
/*     +IDEBUG(2)). */
/*     =6, THE TABCYL DEFPRE AREA FROM DEFPRE(IDEBUG(2)) THRU DEFPRE */
/*     (IDEBUG(3)+IDEBUG(2)). */
/*     =7, THE PTPP FROM PTPP(IDEBUG(2))THRU PTPP(IDEBUG(3)+IDEBUG(2)). */
/*     =8, THE VST1 AREA. THE VST1 AREA IS PRINTED IN PAIRS. IDEBUG(2) */
/*     CONTAINS THE INDEX TO THE FIRST PAIR AND IDEBUG(2) CONTAINS THE */
/*     NUMBER OF PAIRS. */
/*     =9,THE VST2 AREA FROM VST(IDEBUG(2)) THRU VST(IDEBUG(3)+IDEBUG(2)) */
/*     =10,THE SURFTB FROM SURFTB(IDEBUG(2) THRU SURFTB(IDEBUG(3)+ */
/*     IDEBUG(2)). */
/*     =11, THE SCALR AREA FROM SCALR(I DEBUG(2))THRU SCALR(IDEBUG(3)+ */
/*     IDEBUG(2)). */
/*     =12,ZSUR AREA */
/*     =13,PROTP AND IRECN */
/*     IF IDEBUG(1) IS NOT IN THE INTEGER SET(1,13) ITITLE = NEGATIVE */

/*     TITLE FOR DEBUG PRINT */
    /* Parameter adjustments */
    --ititle;

    /* Function Body */
    if (ititle[1] == 0) {
	goto L20;
    }
    io___4.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___4);
    do_fio(&c__1, (char *)&ititle[1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ititle[2], (ftnlen)sizeof(integer));
    e_wsfe();
L20:
    if (adebug_1.idebug[0] > 13) {
	goto L140;
    }
    if (adebug_1.idebug[0] < 0) {
	goto L140;
    }
    a1pas2_1.k = adebug_1.idebug[1] + adebug_1.idebug[2] - 1;
    id = adebug_1.idebug[0];
    id1 = adebug_1.idebug[1];
    id2 = id1 + (adebug_1.idebug[2] << 1) - 1;
    switch ((int)id) {
	case 1:  goto L30;
	case 2:  goto L40;
	case 3:  goto L50;
	case 4:  goto L60;
	case 5:  goto L70;
	case 6:  goto L80;
	case 7:  goto L90;
	case 8:  goto L100;
	case 9:  goto L150;
	case 10:  goto L150;
	case 11:  goto L150;
	case 12:  goto L170;
	case 13:  goto L180;
    }

L30:
    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 64; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&atmaty_1.xmat4[a1pas2_1.i__ - 1], (ftnlen)
		sizeof(doublereal));
    }
    e_wsfe();
L40:
    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 16; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&atmaty_1.tmatx[a1pas2_1.i__ - 1], (ftnlen)
		sizeof(doublereal));
    }
    e_wsfe();
    goto L150;

L50:
    io___10.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___10);
    i__1 = id1;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&adfsto_1.defsto[a1pas2_1.i__ - 1], (ftnlen)
		sizeof(doublereal));
    }
    e_wsfe();
    goto L150;

L60:
    io___11.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___11);
    i__1 = a1pas2_1.k;
    for (a1pas2_1.i__ = id1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&canon[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L150;

L70:
    io___12.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___12);
    i__1 = a1pas2_1.k;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&deftab[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L150;

L80:
    goto L150;

L90:
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    do_fio(&c__1, (char *)&id1, (ftnlen)sizeof(integer));
    i__1 = a1pas2_1.k;
    for (a1pas2_1.i__ = id1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&ptpp[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L150;

L100:
    id2 = adebug_1.idebug[2];
    io___14.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___14);
    do_fio(&c__1, (char *)&avst_1.vst[id1 - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avst_1.vst[id1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&canon[id2 - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L150;

L140:

L150:
    return 0;

L170:
    io___15.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___15);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&azurf_1.zsur[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L150;

L180:
    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    do_fio(&c__1, (char *)&a1pas2_1.irecn, (ftnlen)sizeof(integer));
    e_wsfe();
    if (id1 == 0) {
	goto L150;
    }
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    i__1 = id1;
    for (ii = 1; ii <= i__1; ++ii) {
	do_fio(&c__1, (char *)&aprotp_1.protp[ii - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L150;

} /* adprnt_ */

#undef deftab
#undef canon
#undef ptpp


