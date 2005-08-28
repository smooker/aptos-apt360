/* CLPRNT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include "stdio.h"

/* Common Block Declarations */

struct {
    doublereal parm[180];
} parm1_;

#define parm1_1 parm1_

struct {
    doublereal posta[22];
} posta1_;

#define posta1_1 posta1_

struct {
    doublereal postp[72];
} postp1_;

#define postp1_1 postp1_

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
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

struct {
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

struct {
    doublereal motion[8];
} a3fxd2_;

#define a3fxd2_1 a3fxd2_

struct {
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__14000 = 14000;

/* Subroutine */ int clprnt_()
{
    /* Format strings */
    static char fmt_770[] = "(4x,3z10/(4x,5z18))";
    static char fmt_192[] = "(\002 \002,83x,\002RECNO \002,i5,\002 CARD \002\
,a8,\002 ISN \002,i5)";
    static char fmt_135[] = "(\002 \002,67x,\002** CALL CARD ** \002,\002REC\
NO \002,i5,\002 CARD \002,a8,\002 ISN \002,i5)";
    static char fmt_271[] = "(5x,a8)";
    static char fmt_272[] = "(2x,a8,11a6)";
    static char fmt_274[] = "(5x,a8,\002/\002,a8,\002(\002,i5,\002)\002,4(f1\
3.7,\002,\002)/(29x,4(f13.7,\002,\002)))";
    static char fmt_275[] = "(5x,a8,\002/\002,f5.0,\002,\002,a8,4(\002,\002,\
f12.6))";
    static char fmt_276[] = "(5x,a8,\002/\002,f5.0,\002,\002,a8,\002,\002,\
a8,\002(\002,i5,\002)\002,f5.0/29x,4(f13.7,\002,\002)/(29x,4(f13.7,\002,\002\
)))";
    static char fmt_277[] = "(\0020TARRAY\002/(5z18))";
    static char fmt_380[] = "(\002 \002,14x,\002SURFACE DATA - \002,2a8,\002\
 ** \002,a8,\002(\002,i5,\002) ** \002,a8,\002 **\002,/22x,\002CANON FORM IS \
\002,6(f13.7,\002,\002)/(36x,6(f13.7,\002,\002)))";
    static char fmt_9997[] = "(\002 \002,14x,\002SURFACE DATA - \002,2a8,\
\002 ** \002,a8,\002(\002,i5,\002) ** \002,a8,\002 **\002)";
    static char fmt_401[] = "(\002 \002,14x,\002TOOL ORIENTATION IS \002,a8)";
    static char fmt_580[] = "(\002 \002,14x,\002$$$ \002,2a8,\002,\002,f10.4)"
	    ;
    static char fmt_9999[] = "(\002 \002,14x,\002*** \002,a8,f10.4,2(\002\
,\002,f10.4))";
    static char fmt_9998[] = "(\002 \002,14x,\002*** \002,2a8,\002(\002,i5\
,\002) ... \002,f10.4,2(\002,\002,f10.4))";
    static char fmt_581[] = "(\002 \002,14x,\002*** \002,2a8,\002(\002,i5\
,\002)\002/(38x,3f15.7))";
    static char fmt_582[] = "(\002 \002,14x,\002*** \002,2a8,\002(\002,i5\
,\002)\002/(20x,6f15.7))";
    static char fmt_583[] = "(\002 \002,14x,\002*** \002,a8,2(a8,\002(\002,i\
5,\002),\002),a8,\002(\002,i5,\002)\002/27x,a8,\002(\002,i5,\002) =\002,3(f1\
1.5,\002,\002))";
    static char fmt_9996[] = "(\002 \002,14x,a8)";
    static char fmt_681[] = "(\002 \002,12x,a10,i6,a10)";
    static char fmt_682[] = "(\002 \002,12x,a10,8(f10.6))";
    static char fmt_683[] = "(\002 \002,12x,a10,i16,7(f10.4))";
    static char fmt_790[] = "(\002 \002,14x,\002START UP INSTRUCTION - \002,\
a8,i5,\002 SURFACES\002)";
    static char fmt_890[] = "(\002 \002,14x,\002MOTION INSTRUCTION IS \002,a\
8)";
    static char fmt_980[] = "(\002 \002,14x,2a8)";
    static char fmt_981[] = "(\002 \002,14x,a8,6f10.4)";
    static char fmt_982[] = "(\002 \002,14x,2a8,\002,\002,a8)";
    static char fmt_983[] = "(\002 \002,14x,2a8,\002(\002,i5,\002)\002,3f10.\
6)";
    static char fmt_984[] = "(\002 \002,14x,2a8,\002,\002,a8,\002,\002,f9.4\
,\002,\002,a8,\002(\002,i5,\002)\002,3f9.4)";
    static char fmt_985[] = "(\002 \002,14x,2a8,\002,\002,a8,\002,\002,f9.4\
,\002,\002,a8,\002,\002,f9.4)";
    static char fmt_986[] = "(\002 \002,14x,a8,i1)";
    static char fmt_988[] = "(\002 \002,14x,2a8,\002,\002,a8,\002,\002,f9.4)";
    static char fmt_1001[] = "(\002 \002,1x,\002REGION\002/(5x,4z18))";
    static char fmt_1101[] = "(\002 \002,14x,\002** POCKET **  PARAMETERS AR\
E --\002/(29x,4f12.6))";
    static char fmt_1201[] = "(\002 \002,14x,\002** SPECIAL PROGRAM. CALL/\
 \002,a8/(41x,4f12.6))";
    static char fmt_1202[] = "(\002 \002,14x,\002** SPECIAL PROGRAM. CALL/\
 \002,a8/(41x,2(a8,\002 = \002,f12.6)))";
    static char fmt_1306[] = "(\002 \002,14x,2a8)";
    static char fmt_3510[] = "(\002 \002,1x,\002** FINI **\002)";
    static char fmt_debug[] = "(\002 \002,1x,\002** FORMAT BUG **\002)";

    /* System generated locals */
    integer i__1;
    static doublereal equiv_2[1];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define itas ((integer *)equiv_2)
    static doublereal paps;
#define taps (equiv_2)
    static integer nkom;
    static doublereal word1[3];
    static integer i__, j, n;
    //static doublereal aq[14];
    static integer ij[3], jj, kl, ip;
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define ita ((integer *)&a3fxd1_ + 492)
    static doublereal tarray[24], tap[8];//, aq6[12], aq1[6], tap[8], aq2[12], aq3[8], 
//	    aq4[6], aq5[6], aq7[8], aqq[2], aq8[16], aq9[21];
    static integer iii, nt1, nt2, nt4;
    extern /* Subroutine */ int cerror_(), lerror_();
    static integer irs1;
    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_770, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_192, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_135, 0 };
    static cilist io___11 = { 0, 0, 0, fmt_271, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_271, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_272, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_274, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_275, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_276, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_277, 0 };

    static cilist io___31 = { 0, 0, 0, (char *)tarray, 0 };
    static cilist io___32 = { 0, 0, 0, (char *)tarray, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_380, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_580, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_581, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_582, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_583, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_9996, 0 };
    static cilist io___50 = { 0, 0, 0, fmt_681, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_682, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_681, 0 };
    static cilist io___53 = { 0, 0, 0, fmt_683, 0 };
    static cilist io___54 = { 0, 0, 0, fmt_790, 0 };
    static cilist io___55 = { 0, 0, 0, fmt_890, 0 };
    static cilist io___57 = { 0, 0, 0, fmt_980, 0 };
    static cilist io___60 = { 0, 0, 0, fmt_980, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_981, 0 };
    static cilist io___62 = { 0, 0, 0, fmt_982, 0 };
    static cilist io___63 = { 0, 0, 0, fmt_983, 0 };
    static cilist io___64 = { 0, 0, 0, fmt_984, 0 };
    static cilist io___65 = { 0, 0, 0, fmt_985, 0 };
    static cilist io___66 = { 0, 0, 0, fmt_986, 0 };
    static cilist io___67 = { 0, 0, 0, fmt_988, 0 };
    static cilist io___68 = { 0, 0, 0, fmt_1001, 0 };
    static cilist io___69 = { 0, 0, 0, fmt_1101, 0 };
    static cilist io___70 = { 0, 0, 0, fmt_1201, 0 };
    static cilist io___71 = { 0, 0, 0, fmt_1202, 0 };
    static cilist io___73 = { 0, 0, 0, fmt_1306, 0 };
    static cilist io___75 = { 0, 0, 0, fmt_3510, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ...   THIS ROUTINE PRINTS ANYONE OF THE 14 RECORD TYPES POSSIBLE ON THE */
/* ...   CLTAPE AS IT APPEARS ON ENTRY IN TAPSTO(COMMON) */
/* ...                    NUMWDS = THE NUMBER OF WORDS READ BY CLREAD */
/* ...                    JTYPSW = THE RECORD TYPE INTERGER DIVDED BY 1000 */
/* ...                    TAPSTO = THE BLOCK READ FROM CLTAPE */
/* ...           SEQNO = THE INPUT CARDS SEQUENCE NUMBER */
/* ...           CSEQNO = THE INPUT SEQUENCE NUMBER OF A MACRO CALL */
/* ******************************************************************** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ...******************************************************************** */

/*       DATA AQ/'CUT     DNTCUT  2DCALC  3DCALC  NDTEST  INTOF   INTOL/ */
/*     1OUTTOL/ CUTTER/ TRANTO/ CSTRANTODYNDMP/ GO/     OFFSET/ '/ */

//following is not f2c generated...
	static char aqC[]="CUT     DNTCUT  2DCALC  3DCALC  NDTEST  INTOF   INTOL/  \
OUTTOL/ CUTTER/ TRANTO/ CSTRANTODYNDMP/ GO/     OFFSET/ ";
#define  aq ((doublereal *)&aqC)

/*       DATA AQ1/'  GOLFT/  GORGT/  GOFWD/ GOBACK/   GOUP/  GODWN/'/ */
	static char aq1C[]="  GOLFT/  GORGT/  GOFWD/ GOBACK/   GOUP/  GODWN/";
#define  aq1 ((doublereal *)&aq1C)

/*       DATA AQ2/'DEBUG/OFF       DEBUG/ON        SECT. 2 RESTART CLPRNT */
/*     1/OFF     CLPRNT/ON       CLPRNT/OPTION   '/ */
	static char aq2C[]= "DEBUG/OFF       DEBUG/ON        SECT. 2 RESTART CLPRNT\
/OFF     CLPRNT/ON       CLPRNT/OPTION   " ;
#define  aq2 ((doublereal *)&aq2C)

/*       DATA AQ3/'TLAXIS  MULTAX  MAXDP   NUMPTS  THICK   NOPS    AUTOPS */
/*     1 GOUGCK  '/ */
	static char aq3C[]="TLAXIS  MULTAX  MAXDP   NUMPTS  THICK   NOPS    AUTOPS GOUGCK  ";
#define  aq3 ((doublereal *)&aq3C)

/*       DATA AQ4/'OFF     ON      NORMPS  NORMDS  PSCONTRLDSCONTRL'/ */
static char aq4C[]="OFF     ON      NORMPS  NORMDS  PSCONTRLDSCONTRL";
#define  aq4 ((doublereal *)&aq4C)

/*       DATA AQ5/'  TLLFT   TLRGT    TLON          TLONPS  TLOFPS '/ */
static char aq5C[]="  TLLFT   TLRGT    TLON          TLONPS  TLOFPS ";
#define  aq5 ((doublereal *)&aq5C)

/*       DATA AQ7/'INDIRP/ INDIRV/ FROM/   GODLTA/ GO---/  SRFCNTD/ */
/*     1 SRFVCT/'/ */
static char aq7C[]="INDIRP/ INDIRV/ FROM/   GODLTA/ GO---/  SRFCNTD/       SRFVCT/";
#define  aq7 ((doublereal *)&aq7C)

/*       DATA AQ8/' TLAXIS  NONAME (  PS  )(  DS  )(  CS  )( PSIS )( REGPS */
/*     1)IMPL. TO   TO     PAST     ON    TANTO  SOME HOWSOME HOWSOME HOW */
/*     2PSTAN  '/ */
static char aq8C[]=" TLAXIS  NONAME (  PS  )(  DS  )(  CS  )( PSIS )( REGPS\
      )IMPL. TO   TO     PAST     ON    TANTO  SOME HOWSOME HOWSOME HOW      PSTAN  ";
#define  aq8 ((doublereal *)&aq8C)

/*       DATA AQ9/' POINT    LINE   PLANE   CIRCLE CYLINDER ELLIPSE HYPERB */
/*     1   CONE   GCONIC  LCONIC  VECTOR  MATRIX  SPHERE  QADRIC  POLCON */
/*     2 LOFT    TOOL   TABCYL   MESH   CONSEC  RLDSRF '/ */
static char aq9C[]=" POINT    LINE   PLANE   CIRCLE CYLINDER ELLIPSE HYPERB\
        CONE   GCONIC  LCONIC  VECTOR  MATRIX  SPHERE  QADRIC  POLCON\
     LOFT    TOOL   TABCYL   MESH   CONSEC  RLDSRF ";
#define  aq9 ((doublereal *)&aq9C)



//  DATA AQ6/(9H0REC. NO.,I6,9H CARD NO.,A9,3H , ,A6,1H/,     (34X,      )      A8    F10.4   ,1H,,          '
static char aq6C[]= "(9H0REC. NO.,I6,9H CARD NO.,A9,3H , ,A6,1H/,\
     (34X,      )      A8    F10.4   ,1H,,          ";
#define  aq6 ((doublereal *)&aq6C)

/*        DATA AQQ/'(1H ,4X,A6,1H/, '/ */
//static char aqqC[]="(\002 \002,4X,A6,\002/\002, ";
static char aqqC[]="(1H ,4X,A6,1H/, ";

#define  aqq ((doublereal *)&aqqC)


    if (irs1 != 1000) {
	goto L771;
    }
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    do_fio(&c__1, (char *)&a3fxi1_.irecno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.instr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.instr2, (ftnlen)sizeof(integer));
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
L771:
/* L772: */
    if (asistm_.indexx - 1 >= 0) {
	goto L773;
    } else {
	goto L779;
    }
L773:
    iii = a3fxi1_.irecno;
    a3fxi1_.irecno = a3fxi1_.nurcno;
    if (a3fxi1_.kclprt != 0) {
	goto L779;
    } else {
	goto L774;
    }
L774:
    ++a3fxi1_.irecno;
L779:
    a3fxi1_.jtypsw = a3fxi1_.instr1 / 1000;
    switch ((int)a3fxi1_.jtypsw) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L3500;
    }
/* ...  THE FOLLOWING INSTRUCTIONS SAVE ORIGINAL INPUT SEQUENCE NUMBER */
L100:
    if (a3fxi1_.instr2 >= 0) {
	goto L110;
    } else {
	goto L120;
    }
L110:
    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    do_fio(&c__1, (char *)&a3fxi1_.irecno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxi1_.instr2, (ftnlen)sizeof(integer));
    e_wsfe();
    a3fxd1_.seqno[0] = a3fxd1_.tapsto[1];
    goto L139;
L120:
    a3fxi1_.instr2 = abs(a3fxi1_.instr2);
    a3fxd1_.cseqno[0] = a3fxd1_.tapsto[1];
    io___10.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___10);
    do_fio(&c__1, (char *)&a3fxi1_.irecno, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.cseqno[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxi1_.instr2, (ftnlen)sizeof(integer));
    e_wsfe();
L139:
    a3fxi1_.intseq = a3fxi1_.instr2;
/* L140: */
    goto L4000;
/* ...   THE FOLLOWING INSTRUCTINS OUTPUT THE AUXILIARY COMMANDS... */
L200:
    if (a3fxi1_.numwds != 0) {
	goto L201;
    } else {
	goto L202;
    }
L202:
    if (a3fxi1_.instr2 > 1000) {
	goto L203;
    }
    io___11.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___11);
    do_fio(&c__1, (char *)&posta1_1.posta[a3fxi1_.instr2 - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    goto L4000;
L203:
    j = a3fxi1_.instr2 - 1000;
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L201:
    j = a3fxi1_.instr2 - 1000;
    if (j < 44) {
	goto L204;
    }
    if (j > 46) {
	goto L204;
    }
    io___14.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___14);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    for (i__ = 1; i__ <= 11; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

    goto L4000;
L204:
    if (j != 20) {
	goto L205;
    }
    if (a3fxd1_.tapsto[0] == (float)12345.) {
	irs1 = 1000;
    }
    if (a3fxd1_.tapsto[0] == (float)54321.) {
	irs1 = 0;
    }
/* L273: */
L205:
    if (j != 37) {
	goto L207;
    }
    if (a3fxi1_.numwds != 14) {
	goto L207;
    }
L206:
    a3fxd1_.word = a3fxd1_.tapsto[1];
    jj = (integer) a3fxd1_.word;
    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj, (ftnlen)sizeof(integer));
    for (i__ = 3; i__ <= 14; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

    goto L4000;

L207:
    if (j != 38) {
	goto L208;
    }
    if (a3fxi1_.numwds == 14) {
	goto L206;
    }
L208:
    if (j != 40) {
	goto L220;
    }
    jj = ita[OTHER_ENDIAN_S(3)];
    if (a3fxi1_.numwds == 17) {
	goto L209;
    }
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[jj - 1], (ftnlen)sizeof(doublereal));
    i__1 = a3fxi1_.numwds;
    for (i__ = 3; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
L209:
    a3fxd1_.word = a3fxd1_.tapsto[3];
    n = (integer) a3fxd1_.word;
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[jj - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[16], (ftnlen)sizeof(doublereal));
    for (i__ = 5; i__ <= 16; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;


L220:
//format for keyword and slash,eg DELAY/
//1H ,4X,A6,1H/, 
    for (i__ = 1; i__ <= 2; ++i__) {
/* L221: */
	tarray[i__ - 1] = aqq[i__ - 1];
    }
//fill approx. 177 bytes with spaces:
    for (i__ = 3; i__ <= 24; ++i__) {
/* L222: */
	tarray[i__ - 1] = aq6[11];
    }
    ip = 3;
    nt1 = 1;
    nt2 = 1;
    kl = 0;
    if (j != 15) {
	goto L224;
    }
    tap[0] = a3fxd1_.tapsto[0];
    tarray[2] = aq6[8];
    ip = 4;
    nt1 = 2;
    nt2 = 2;
    kl = 1;
L224:
    nt4 = 2;
L225:
    if (nt2 > a3fxi1_.numwds) {
	goto L226;
    }
    *taps = a3fxd1_.tapsto[nt2 - 1];
    ++nt2;
    if (kl > 6) {
	goto L227;
    }
    if (itas[OTHER_ENDIAN_S(0)] == 0) {
	goto L228;
    }
L230:
    kl += 2;
    paps = aq6[9];// F10.4,
    goto L229;
L228:
    if (itas[OTHER_ENDIAN_S(1)] != 0) {
	goto L231;
    } else {
	goto L230;
    }
L227:
    if (kl == 8) {
	goto L232;
    }
    if (itas[OTHER_ENDIAN_S(0)] != 0) {
	goto L232;
    }
    if (itas[OTHER_ENDIAN_S(1)] == 0) {
	goto L232;
    }
L231:
    jj = itas[OTHER_ENDIAN_S(1)];
    *taps = parm1_1.parm[jj - 1];
    paps = aq6[8];
    ++kl;
L229:
    tap[nt1 - 1] = *taps;
    ++nt1;
    if (nt4 == 2) {
	goto L233;
    }
    if (ip - 2 != 0) {
	goto L234;
    } else {
	goto L235;
    }
L233:
    if (ip == 3) {
	goto L235;
    }
L234:
    tarray[ip - 1] = aq6[10];
    tarray[ip] = paps;
    ip += 2;
    goto L225;
L235:
    tarray[ip - 1] = paps;
    ++ip;
    goto L225;
L226:
    nt4 += 2;
L232:
    tarray[ip - 1] = aq6[7];
    --nt1;
    if (irs1 != 1000) {
	goto L239;
    }
    io___30.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___30);
    i__1 = ip;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&tarray[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L239:
    switch ((int)nt4) {
	case 1:  goto L253;
	case 2:  goto L236;
	case 3:  goto L253;
	case 4:  goto L236;
    }
L253:
    io___31.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___31);
    i__1 = nt1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&tap[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L237;
L236:
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&postp1_1.postp[j - 1], (ftnlen)sizeof(doublereal));
    i__1 = nt1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&tap[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L237:
    if (nt4 > 2) {
	goto L4000;
    }
    kl = 0;
    nt1 = 1;
    --nt2;
    nt4 = 1;
    tarray[0] = aq6[6];
    i__1 = ip;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L238: */
	tarray[i__ - 1] = aq6[11];
    }
    ip = 2;
    goto L225;
/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE SURFACE DATA... */
L300:
    jj = ita[OTHER_ENDIAN_S(3)];
    if (jj > 17) {
	jj += -32;
    }
    a3fxd1_.word = a3fxd1_.tapsto[4];
    j = (integer) a3fxd1_.word;
    a3fxd1_.word = a3fxd1_.tapsto[3];
    if (a3fxd1_.word == (float)0.) {
	a3fxd1_.word = aq8[1];
    }
    kl = ita[OTHER_ENDIAN_S(1)] + 8;
    if (a3fxi1_.numwds == 5) {
	goto L310;
    }
    io___34.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___34);
    do_fio(&c__1, (char *)&aq9[jj - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq8[a3fxi1_.instr2 + 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.word, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&aq8[kl - 1], (ftnlen)sizeof(doublereal));
    i__1 = a3fxi1_.numwds;
    for (i__ = 6; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
L310:
    io___36.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___36);
    do_fio(&c__1, (char *)&aq9[jj - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq8[a3fxi1_.instr2 + 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.word, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&aq8[kl - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L400:
    io___37.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___37);
    do_fio(&c__1, (char *)&aq5[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();

    goto L4000;
/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE CUTTER LOCATIONS... */
L500:
    switch ((int)a3fxi1_.instr2) {
	case 1:  goto L510;
	case 2:  goto L510;
	case 3:  goto L530;
	case 4:  goto L540;
	case 5:  goto L530;
	case 6:  goto L530;
	case 7:  goto L4000;
	case 8:  goto L510;
    }
L540:
    if (a3fxi1_.numwds != 3) {
	goto L541;
    }
    io___39.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&aq8[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L541:
    if (a3fxd1_.tapsto[0] != 0.) {
	goto L543;
    } else {
	goto L542;
    }
L542:
    io___41.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___41);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[4], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L543:
    a3fxd1_.word = a3fxd1_.tapsto[1];
    j = (integer) a3fxd1_.word;
    io___42.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___42);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[4], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L530:
    a3fxd1_.word = a3fxd1_.tapsto[1];
    j = (integer) a3fxd1_.word;
    a3fxd1_.word = a3fxd1_.tapsto[0];
    if (ita[OTHER_ENDIAN_S(0)] == 0) {
	a3fxd1_.word = aq8[1];
    }
    if (a3fxi1_.multax != 0) {
	goto L532;
    } else {
	goto L531;
    }
L531:
    io___43.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___43);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.word, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    i__1 = a3fxi1_.numwds;
    for (i__ = 3; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

    goto L4000;
L532:
    io___44.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___44);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.word, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    i__1 = a3fxi1_.numwds;
    for (i__ = 3; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

    goto L4000;


L510:
    j = 1;
    for (i__ = 1; i__ <= 11; i__ += 5) {
	word1[j - 1] = a3fxd1_.tapsto[i__ - 1];
	a3fxd1_.word = a3fxd1_.tapsto[i__];
	jj = (integer) a3fxd1_.word;
	ij[j - 1] = jj;
	if (a3fxd1_.tapsto[i__ - 1] == (float)0.) {
	    word1[j - 1] = aq8[1];
	}
/* L511: */
	++j;
    }
    io___47.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___47);
    do_fio(&c__1, (char *)&aq7[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    for (i__ = 1; i__ <= 3; ++i__) {
	do_fio(&c__1, (char *)&word1[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ij[i__ - 1], (ftnlen)sizeof(integer));
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	do_fio(&c__1, (char *)&word1[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ij[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ * 5 - 3], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ * 5 - 2], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ * 5 - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
/* ...  THE FOLLOWING FLAGS ARE SPECIAL FLAGS FOR ARELEM SECTION */
L600:
    n = a3fxi1_.instr2 + 3;
    switch ((int)a3fxi1_.instr2) {
	case 1:  goto L610;
	case 2:  goto L620;
	case 3:  goto L630;
	case 4:  goto L640;
	case 5:  goto L640;
	case 6:  goto L660;
	case 7:  goto L670;
	case 8:  goto L670;
	case 9:  goto L640;
    }
L610:
    n = a3fxi1_.i1 + 1;
L611:
    io___48.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___48);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L620:
    n = a3fxi1_.i1 + 3;
    goto L611;
L630:
    a3fxd1_.word = a3fxd1_.tapsto[0];
    j = (integer) a3fxd1_.word;
    io___50.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___50);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L4000;
L640:
    io___51.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___51);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
L670:
    io___52.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___52);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxi1_.i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L660:
    if (ita[OTHER_ENDIAN_S(0)] != 0) {
	goto L640;
    }
    if (ita[OTHER_ENDIAN_S(1)] == 0) {
	goto L640;
    }
    io___53.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___53);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ita[OTHER_ENDIAN_S(1)], (ftnlen)sizeof(integer));
    i__1 = a3fxi1_.numwds;
    for (i__ = 2; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

    goto L4000;


L700:
    n = a3fxi1_.instr2 + 12;
    io___54.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___54);
    do_fio(&c__1, (char *)&aq[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ita[OTHER_ENDIAN_S(1)], (ftnlen)sizeof(integer));
    e_wsfe();
    goto L4000;

L800:
    io___55.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&aq1[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();

    goto L4000;
/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE AXIS MODE (3AXIS OR 5AXIS). */
L900:
    switch ((int)a3fxi1_.instr2) {
	case 1:  goto L910;
	case 2:  goto L920;
	case 3:  goto L930;
	case 4:  goto L930;
	case 5:  goto L930;
	case 6:  goto L960;
	case 7:  goto L960;
	case 8:  goto L920;
    }
L920:
    n = ita[OTHER_ENDIAN_S(1)] + 1;
L921:
    io___57.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___57);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&aq4[n - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L960:
    io___60.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___60);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L4000;
L930:
    io___61.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___61);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;

L910:
    a3fxd1_.word = a3fxd1_.tapsto[0];
    n = (integer) a3fxd1_.word;
    switch ((int)n) {
	case 1:  goto L911;
	case 2:  goto L912;
	case 3:  goto L913;
	case 4:  goto L914;
	case 5:  goto L917;
    }
L912:
    n = ita[OTHER_ENDIAN_S(3)] + 2;
    goto L921;
L914:
    a3fxd1_.word = a3fxd1_.tapsto[1] + 4.;
    n = (integer) a3fxd1_.word;
    io___62.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___62);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[16], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq4[n - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L911:
    a3fxd1_.word = a3fxd1_.tapsto[2];
    j = (integer) a3fxd1_.word;
    a3fxd1_.word = a3fxd1_.tapsto[1];
    if (a3fxd1_.word == (float)0.) {
	a3fxd1_.word = aq8[1];
    }
    io___63.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___63);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.word, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[5], (ftnlen)sizeof(doublereal));
    e_wsfe();

    goto L4000;

L913:
    a3fxd1_.word = a3fxd1_.tapsto[1] + 4.;
    n = (integer) a3fxd1_.word;
    if (a3fxi1_.numwds == 3) {
	goto L918;
    }
    if (a3fxi1_.numwds == 4) {
	goto L915;
    }
    a3fxd1_.word = a3fxd1_.tapsto[4];
    j = (integer) a3fxd1_.word;
    io___64.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___64);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq4[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[6], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[7], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;

L915:
    io___65.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___65);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq4[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[159], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[3], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;

L917:
    io___66.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___66);
    do_fio(&c__1, (char *)&aq3[a3fxi1_.instr2 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxi1_.instr2, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L4000;
L918:
    io___67.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___67);
    do_fio(&c__1, (char *)&aq3[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&parm1_1.parm[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq4[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.tapsto[2], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;

/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE REGION FLAGS... */
L1000:
    io___68.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___68);
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE SPECIAL ROUTINE PARAMETERS. */
L1100:
    io___69.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___69);
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;

/* ...   THE FOLLOWING INSTRUCTIONS OUTPUT THE SPECIAL PROGRAMS... */
L1200:
    if (a3fxi1_.instr2 == 2) {
	goto L1210;
    }
    io___70.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___70);
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;
L1210:
    io___71.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___71);
    i__1 = a3fxi1_.numwds;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&a3fxd1_.tapsto[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L4000;

L1300:
    switch ((int)a3fxi1_.instr2) {
	case 1:  goto L1301;
	case 2:  goto L1302;
	case 3:  goto L1303;
	case 4:  goto L1304;
    }
L1303:
    a3fxi1_.it = ita[OTHER_ENDIAN_S(1)];
    if (asistm_.kflags[6] != 0) {
	goto L1350;
    }
    cerror_();
    goto L4000;
L1350:
    nkom = (integer) a3fxd1_.tapsto[0];
    lerror_(&nkom);
    goto L4000;
L1301:
    n = (ita[OTHER_ENDIAN_S(1)] + 1 << 1) - 1;
L1305:
    io___73.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___73);
    do_fio(&c__1, (char *)&aq2[n - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&aq2[n], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L4000;
L1302:
    n = 5;
    goto L1305;
L1304:
    n = (ita[OTHER_ENDIAN_S(1)] + 3 << 1) + 1;
    goto L1305;
/* ...  THE FOLLOWING INSTRUCTIONS OUTPUT THE FINI */
L3500:
    io___75.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___75);
    e_wsfe();
    if (asistm_.kflags[6] == 0) {
	goto L4000;
    }
/* L3520: */
    if (asistm_.iwaven <= 0) {
	goto L4000;
    } else {
	goto L3530;
    }
L3530:
    lerror_(&c__14000);
/* ...  THIS IS THE COMMON RETURN POINT OF THIS SUBROUTINE */
L4000:
    if (asistm_.indexx - 1 >= 0) {
	goto L4001;
    } else {
	goto L4002;
    }
L4001:
    a3fxi1_.irecno = iii;
L4002:
    return 0;
/* ...  END OF CLPRNT SUBROUTINE */
} /* clprnt_ */

#undef ita
#undef nucltp
#undef taps
#undef itas


