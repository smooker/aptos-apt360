/* ADIAGM.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

static struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

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
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int adiagm_()
{
    /* Format strings */
    static char fmt_260[] = "(\0020***** CARD NO.\0022x,a6,a2,\002,ISN\002\
i5,\002,  ERROR NUMBER\002i5,\002, NAME = \002a8,\002(\002i4,\002)\002,10x\
,\002$$$$$$\002/\002 \002)";
    static char fmt_240[] = "(\0020***** CARD NO.\0022x,a6,a2,\002,ISN\002\
i5,\002,  ERROR NUMBER\002i5,31x,\002$$$$$$\002/\002 \002)";

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ioflag;
#define errtap ((doublereal *)&ataptb_1 + 9)
#define ptptap ((doublereal *)&ataptb_1 + 3)
    extern /* Subroutine */ int atapop_(), atapwt_();

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 0, 0, fmt_260, 0 };
    static cilist io___5 = { 0, 0, 0, fmt_240, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ...  THIS ROUTINE PRINTS ERROR MESSAGES AND */
/* ...  WRITES THE ERROR DIAGNOSTIC FILE FOR PASS THREE */


/*     WAS A VARIABLE SYMBOL INVOLVED */
    if (aprotp_1.nowclt == 0) {
	goto L200;
    }
    aprotp_1.nowclt = 0;
    atapop_(errtap, &c__1, &ioflag);
L200:
    if (a2cls7_1.ename == (float)0.) {
	goto L230;
    }
/*     YES - INCLUDE IT IN THE DIAGNOSTIC MESSAGE */
    io___4.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___4);
    do_fio(&c__1, (char *)&a2cls7_1.ppseq1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.ppseq2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.isn, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a1com_1.jsuber, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L250;
L230:
    io___5.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___5);
    do_fio(&c__1, (char *)&a2cls7_1.ppseq1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.ppseq2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a2cls7_1.isn, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a1com_1.jsuber, (ftnlen)sizeof(integer));
    e_wsfe();
/*     WRITE ERROR FILE RECORD */
L250:
    a2cls7_1.ierec += a0con_1.k1;
/* L270: */
    atapwt_(errtap, &ioflag, &a0con_1.k3, &a2cls7_1.ierec, &a0con_1.k1, &
	    a2cls7_1.isn, &a0con_1.k1, &a1com_1.jsuber, &a0con_1.k1);
/*     SET SYSTEM ERROR FLAG */
    asistm_1.iwaven = a0con_1.k1;
    a1com_1.loop = a0con_1.k1;
    a1com_1.jsuber = 0;
    a2cls7_1.ename = (float)0.;
    return 0;
} /* adiagm_ */

#undef ptptap
#undef errtap


