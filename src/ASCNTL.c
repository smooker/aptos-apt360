/* ASCNTL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__0 = 0;

/* Subroutine */ int ascntl_()
{
    /* Format strings */
    static char fmt_99[] = "(\0020\002,42x\002TABLE USAGE DURING INPUT TRANS\
LATION\002//34x\002PASS ONE\00238x\002PASS TWO\002/33x\002ALLOCATED     USE\
D\00223x\002DYNAMIC ALLOCATION\002/26x\002VST\0027x,i4,7x,i4,23x\002VST\0021\
1x,i4,/26x\002PTPP\0026x,i4,7x,i4,23x\002PTPP\00210x,i4/26x\002SCALARS\00214\
x,i4,23x\002SCALARS\0027x,i4/26x\002CANON\0025x,i4,7x,i4,23x\002CANON\0029x,\
i4///)";
    static char fmt_199[] = "(\0020***** ISN 1, ERROR NUMBER\002,i5,\002 ***\
**\002)";
    static char fmt_3[] = "(7x,a6,2z18,6x,a6,2z18)";
    static char fmt_9[] = "(////\002 THE CONTENTS OF THE VARIABLE SYMBOL TAB\
LE ARE AS FOLLOWS \002//)";
    static char fmt_10[] = "(////\002 THE CONTENTS OF THE PROTAP ARE AS FOLL\
OWS  \002//)";
    static char fmt_12[] = "(7x,3i10)";
    static char fmt_200[] = "(7x,5z18)";
    static char fmt_14[] = "(////\002 DUMP OF LARGE SURFACE FILE... NUMBER O\
F SURFACES IS \002i4)";
    static char fmt_25[] = "(\0021\002,70x)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ic, jj, jt, ifw[3];
#define ivst ((integer *)&avst_1)
    static integer isprg, jtest, nwrds, jtemp1, ioflag, ilmcan;
    extern /* Subroutine */ int amontr_();
    static integer imxvst, imxscl, lsurft;
    extern /* Subroutine */ int asyctl_(), ataprd_(), atapop_(), acntrl_();

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_199, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_9, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_25, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* *    THIS IS THE CONTROL PROGRAM FOR SECTION 1, THE LANGUAGE TRANSLATOR */


    if (a1com_1.ifini < 0) {
	goto L2;
    } else if (a1com_1.ifini == 0) {
	goto L1;
    } else {
	goto L8;
    }
L1:
    asistm_1.iwaven = 0;
    ainpot_1.ifirst = 0;
    ainpot_1.more = 0;
/* 	call monitor- read a source program, parse */
    amontr_();

L2:
    isprg = 0;
    ilmcan = amacro_1.limcan - amxtab_1.maxvst - amxtab_1.mxptpp;
    ++amxtab_1.maxvs1;
    imxvst = amxtab_1.maxvs1 + amxtab_1.maxvs2;
    imxscl = amxtab_1.maxscl;
/* ...     IF INSUFFICIENT SPACE LEFT IN CANON, ADJUST SCALAR */
/* ...     STORAGE LIMIT INDEX TO PROVIDE MINIMUM CANON STORAGE */
    ic = imxvst + amxtab_1.maxptp + amxtab_1.maxscl;
    if (ic <= 5900) {
	goto L220;
    }
    amxtab_1.maxscl = amxtab_1.maxscl + 5900 - ic;

L220:
    lsurft = 6200 - imxvst - amxtab_1.maxptp - amxtab_1.maxscl;
    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    do_fio(&c__1, (char *)&amxtab_1.maxvst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.maxvs1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&imxvst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.mxptpp, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.maxptp, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.maxptp, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&imxscl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.maxscl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amxtab_1.mxcan, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ilmcan, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&lsurft, (ftnlen)sizeof(integer));
    e_wsfe();

/* ...     IF SCALAR STORAGE HAS BEEN REDUCED, OUTPUT A DIAGNOSTIC FOR */
/* ...     INSUFFICIENT SPACE */
    if (imxscl <= amxtab_1.maxscl) {
	goto L100;
    }
    a1com_1.jsuber = 14;
    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    do_fio(&c__1, (char *)&a1com_1.jsuber, (ftnlen)sizeof(integer));
    e_wsfe();
    a1com_1.jsuber = 0;
    asistm_1.iwaven = 1;

/* ...     DUMP VST IF DEBUG HAS BEEN REQUESTED WHEN FINI */
/* ...     FOUND */
L100:
    if (a1com_1.kdbug == 0) {
	goto L4;
    }
    i__1 = amxtab_1.maxvs1;
    for (jj = 1; jj <= i__1; jj += 4) {
	io___11.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___11);
	do_fio(&c__1, (char *)&avst_1.vst[jj - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avst_1.vst[jj + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj + 2], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
/* L110: */
    }
/*     INITIALIZE VST1 AND VST2 TO UNDEFINED SYMBOL */
L4:
    i__1 = amxtab_1.maxvs1;
    for (a1pas2_1.i__ = 2; a1pas2_1.i__ <= i__1; a1pas2_1.i__ += 2) {
	jtemp1 = (a1pas2_1.i__ << 1) - 1;
	jtest = ivst[OTHER_ENDIAN_S(jtemp1 - 1)];
/* ...  IS THIS FOR A SUBSCRIPTED VARIABLE */
	if (jtest < 0) {
	    goto L5;
	}
	jt = 7;
	if (jtest != 10) {
	    goto L42;
	}
/* ...  MACRO NAME - SET VST FOR CROSS-REFERENCED FOR PASS TWO */
L41:
	jt = 8;
	goto L44;
L42:
	if (jtest != 3) {
	    goto L44;
	}
/* ...  SET VST FOR A STATEMENT ID FOR PASS TWO */
	avst_1.vst[a1pas2_1.i__ - 2] = 0.;
	goto L41;
L44:
	ivst[OTHER_ENDIAN_S(jtemp1 - 1)] = jt;
L5:
	;
    }
    a1pas2_1.j = amxtab_1.maxvs1 + 1;
    a1pas2_1.k = amxtab_1.maxvs1 + amxtab_1.maxvs2;
    i__1 = a1pas2_1.k;
    for (a1pas2_1.i__ = a1pas2_1.j; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	jtemp1 = (a1pas2_1.i__ << 1) - 1;
/* L7: */
	ivst[OTHER_ENDIAN_S(jtemp1 - 1)] = 7;
    }
    asyctl_();
    return 0;
L8:
    if (a1com_1.kdbug == 0) {
	goto L20;
    }
    io___15.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___15);
    e_wsfe();
    i__1 = a1pas2_1.kanptr;
    for (jj = 1; jj <= i__1; jj += 4) {
	io___16.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___16);
	do_fio(&c__1, (char *)&avst_1.vst[jj - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&avst_1.vst[jj + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj + 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&avst_1.vst[jj + 2], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
/* L210: */
    }
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    e_wsfe();
L11:
    ataprd_(&ataptb_1.protap, &ioflag, &nwrds, &c__2, ifw, &c__3, avst_1.vst, 
	    &c__0);
    if (ioflag >= 0) {
	goto L13;
    }
    io___21.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___21);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 3; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&ifw[a1pas2_1.i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    e_wsfe();
    io___22.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___22);
    i__1 = nwrds;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&avst_1.vst[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    if (ifw[1] == 14000) {
	goto L13;
    }
    goto L11;
L13:
    atapop_(&ataptb_1.protap, &c__1, &ioflag);
    if (a1pas2_1.lgerec == 0) {
	goto L20;
    }
    atapop_(&ataptb_1.srftap, &c__1, &ioflag);
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&a1pas2_1.lgerec, (ftnlen)sizeof(integer));
    e_wsfe();
    i__1 = a1pas2_1.lgerec;
    for (a1pas2_1.j = 1; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	ataprd_(&ataptb_1.srftap, &ioflag, &nwrds, &c__2, ifw, &c__3, 
		avst_1.vst, &c__0);
	if (ioflag >= 0) {
	    goto L16;
	}
	io___24.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___24);
	for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 3; ++a1pas2_1.i__) {
	    do_fio(&c__1, (char *)&ifw[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsfe();
/* L15: */
	io___25.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___25);
	i__2 = nwrds;
	for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__2; ++a1pas2_1.i__) {
	    do_fio(&c__1, (char *)&avst_1.vst[a1pas2_1.i__ - 1], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
    }
L16:
    atapop_(&ataptb_1.srftap, &c__1, &ioflag);
L20:
    a1com_1.ifini = 0;
    io___26.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___26);
    e_wsfe();
/* ...  THE FOLLOWING STATEMENT SETS NOPOST IF NO MACHIN/ WAS GIVEN */
    if (asistm_1.numpst == 0) {
	asistm_1.nopost = 1;
    }
    acntrl_();
/*     THIS RETURN IS NEVER EXECUTED */
    return 0;
} /* ascntl_ */

#undef ivst


