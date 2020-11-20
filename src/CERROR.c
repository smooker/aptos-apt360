/* CERROR.f -- translated by f2c (version 20000121).
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
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

static struct {
    doublereal amati1[16]	/* was [4][4] */, amati2[16]	/* was [4][4] 
	    */, amati3[16]	/* was [4][4] */, amatrx[12]	/* was [3][4] 
	    */, amtr[36], an1, an2, aname, ax, ax0, axvec[3], ay, ay0, cntm[
	    36], cntmat[12]	/* was [3][4] */, cont[3], count[3], cseqno[1]
	    , delx, dely, dx, dy, f0, origin[3], parray[20], partno[12], pnt[
	    3], pprint[12], ppt[6], pt0[3], ptt[6], ptu[3], seqno[1], sub[5], 
	    sub4[6], tapsto[250], titl[8], tl, tmatrx[12]	/* was [3][4] 
	    */, tntm[36], toolng, tramat[12]	/* was [3][4] */, vec[3], 
	    word, x0, x1, x2, x3, xnew, y0, y1, y2, y3, ynew;
} a3fxd1_;

#define a3fxd1_1 a3fxd1_

static struct {
    doublereal motion[8];
} a3fxd2_;

#define a3fxd2_1 a3fxd2_

static struct {
    integer iarrow, i1, i2, iclwas, icopy, idplot, idplsq, ifirst, igodlt, 
	    indn, instr1, instr2, ind2tb[160], indoff, indtab[160], indxno[3],
	     ipersp, ipl5ax, iploti, iplotx, iplwas, ipx, ipy, irecni[3], 
	    irecno, irectp, iret, iretvr, isubsc, iswmac, iswnoc, it, ithpnt, 
	    itrafl, itrunc, jarrow, jclprt, jcopy, jptsw, jsw, jtypsw, jvectr,
	     kclprt, kcopy, maxcop, multax, ncamra, nk, nntab, nrecno, ntab, 
	    numwds, nurcno, nx, nx0, nx1, nx2, nx4, nx5, nxp, ny, ny0, ny1, 
	    ny2, ny4, ny5, nyp, ifalms, iwarms, intseq;
} a3fxi1_;

#define a3fxi1_1 a3fxi1_

static struct {
    doublereal erc1[1600];
} errcon_;

#define errcon_1 errcon_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int cerror_()
{
    /* Initialized data */

    static shortint intcod[160] = { 10,314,41,-307,315,11,1401,303,302,12,13,
	    6,7,8,311,312,-9,502,503,504,505,401,402,403,404,405,406,407,408,
	    409,410,411,412,413,414,-415,-416,-821,-822,-823,841,842,843,-881,
	    -882,-901,902,903,904,-905,-906,907,1002,-1004,1021,-1022,1041,
	    1061,-1081,1082,1083,1401,1402,1201,2102,801,802,803,804,601,602,
	    603,3501,3502,3503,3504,3505,3506,3507,3508,3509,3510,33,34,36,35,
	    -37,38,39,30,31,44,40,42,43,701,703,704,-705,706,707,-708,-709,
	    -710,-711,712,850,851,852,853,854,855,856,-857,-858,859,860,730,
	    713,714,715,720,721,717,718,-725,724,725,2201,2,3,4,5,16,17,18,19,
	    861,740,417,-1601,3511,3512,3513,3514,3515,3516,3517,3518,45,-845,
	    -846,-1008,1009,1404,1501,3519,2202,-3520,-3521 };

    /* Format strings */
    static char fmt_30[] = "(\002 REC. NO. \002,i5,\002 CARD NO. \002,a8,\
\002 ISN \002,i5,\002**** SEC 2 ERROR CODE UNDEFINED. ERROR CODE IS\002,i6\
,\002 ****\002)";
    static char fmt_40[] = "(\002 REC. NO. \002,i5,\002 CARD NO. \002,a8,\
\002 ISN \002,i5,\002**** SEC 2 WARNING MESSAGE NO. \002,i6/\002 **** \002,1\
0a8,\002 ****\002)";
    static char fmt_50[] = "(\002 REC. NO. \002,i5,\002 CARD NO. \002,a8,\
\002 ISN \002,i5,\002**** SEC 2 FAILURE MESSAGE NO. \002,i6/\002 **** \002,1\
0a8,\002 ****\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, j, ii, kl;
    static shortint ix;
#define iy ((shortint *)&a3fxi1_1 + 706)
#define nucltp ((doublereal *)&ataptb_1 + 7)

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_50, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_30, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* L30: */
/* L40: */
/* L50: */
    ix = iy[OTHER_ENDIAN_S(1)];
    for (i__ = 1; i__ <= 160; ++i__) {
	if (ix != intcod[i__ - 1]) {
	    goto L10;
	}
/* L5: */
	ii = i__ * 10 - 9;
	j = ii + 9;
	if (intcod[i__ - 1] >= 0) {
	    goto L8;
	} else {
	    goto L7;
	}
L7:
	a3fxi1_1.iwarms += a0con_1.k1;
/*       WRITE (IOUTAP,40) IRECNO,SEQNO,INTSEQ,IX,(ERC1(I),I=II,J) */
	io___8.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___8);
	do_fio(&c__1, (char *)&a3fxi1_1.irecno, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a3fxd1_1.seqno[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a3fxi1_1.intseq, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(shortint));
	i__1 = j;
	for (kl = ii; kl <= i__1; ++kl) {
	    do_fio(&c__1, (char *)&errcon_1.erc1[kl - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	goto L15;
L8:
	a3fxi1_1.ifalms += a0con_1.k1;
/*       WRITE (IOUTAP,50) IRECNO,SEQNO,INTSEQ,IX,(ERC1(I),I=II,J) */
	io___10.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___10);
	do_fio(&c__1, (char *)&a3fxi1_1.irecno, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a3fxd1_1.seqno[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&a3fxi1_1.intseq, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(shortint));
	i__1 = j;
	for (kl = ii; kl <= i__1; ++kl) {
	    do_fio(&c__1, (char *)&errcon_1.erc1[kl - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	goto L15;
L10:
	;
    }
    io___11.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___11);
    do_fio(&c__1, (char *)&a3fxi1_1.irecno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxi1_1.intseq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(shortint));
    e_wsfe();
    if (ix >= 0) {
	goto L12;
    } else {
	goto L11;
    }
L11:
    ++a3fxi1_1.iwarms;
    goto L15;
L12:
    ++a3fxi1_1.ifalms;
L15:
    return 0;
} /* cerror_ */

#undef nucltp
#undef iy


