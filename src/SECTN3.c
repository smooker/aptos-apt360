/* SECTN3.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include <math.h>
#include <assert.h>
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

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b77 = .33333333333333331;

/* Subroutine */ int sectn3_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_43 = { {'P', 'A', 'R', 'T', 'N', 'O', ' ', ' '}, 0. };

#define q000hl (*(doublereal *)&equiv_43)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_44 = { {' ', 'N', 'O', 'T', ' ', 'G', ' ', ' '}, 0. };

#define q001hl (*(doublereal *)&equiv_44)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_45 = { {'I', 'V', 'E', 'N', ' ', ' ', ' ', ' '}, 0. };

#define q002hl (*(doublereal *)&equiv_45)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_46 = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0. };

#define q003hl (*(doublereal *)&equiv_46)


    /* Format strings */
    static char fmt_2[] = "(\0021.....SECTION 3....\002)";
    static char fmt_2009[] = "(\002 ***** NO TRANSFORMATION OR COPY HAS BEEN\
 PERFORMED DUE TO ERRORS --- CHECK PRINTOUT FOR ERROR COMMENTS.\002)";
    static char fmt_60[] = "(//\002 ***** READ ERROR IN SECTN3 ON CLFILE\002)"
	    ;
    static char fmt_111[] = "(\002-END OF SECTN3\002)";
    static char fmt_116[] = "(//\002 ***** CHECK CLTAPE PRINTOUT FOR PROGRAM\
 ERROR COMMENTS*****NO OF SECTION 2 FAILURES ARE \002,i5,\002 WARNINGS ARE\
 \002,i5)";
    static char fmt_180[] = "(\002 END OF NUCLTP SENSED BEFORE THIS RECORD W\
RITTEN.\002)";
    static char fmt_9018[] = "(\002 DUPLICATE INDEX NUMBERS NOT ALLOWED\002/)"
	    ;
    static char fmt_948[] = "(\002- THE INDEX TABLE HAS OVERFLOWED. TOO MANY\
 INDEX/N INSTRUCTIONS IN THIS PART PROGRAM.\002)";
    static char fmt_957[] = "(\002 ****FOLLOWING COPY NOT PERFORMED  N EQUAL\
S ZERO****\002)";
    static char fmt_990[] = "(\002 TOO MANY NESTED COPIES                   \
    \002)";
    static char fmt_1050[] = "(\002-INCORRECT MODIFIER IN A COPY INSTRUCTIO\
N\002)";
    static char fmt_1116[] = "(\002-THE NO. OF TIMES THRU THIS COPY WOULD EX\
CEED (N),CHECK PART PROGRAM FOR ILLEGAL TRANSFER INTO COPY LOOP\002)";
    static char fmt_1118[] = "(\002 COUNT = \002i5,\002INDXNO = \002i5,\002C\
ARD NO. \002a8,\002LAST CALL CARD NO. \002a8)";
    static char fmt_1247[] = "(\0020\002,15x,\002***** THIS COMPLETES COPY\
/\002i4,\002*****\002)";
    static char fmt_1190[] = "(\002 INDEX/\002i6,\002 NOT DEFINED.\002)";
    static char fmt_1249[] = "(\0020\002,15x,\002***** THIS COMPLETES PASS N\
O. \002i4,\002 THRU THIS COPY,BACK TO INDEX/ \002i4,\002*****\002)";
    static char fmt_1248[] = "(\0020\002,15x,\002***** THIS STARTS PASS NO. \
  1. THRU THIS COPY, BACK TO INDEX/\002i4,\002*****\002)";
    static char fmt_1590[] = "(\002-***** ERROR IN COPY LOGIC ******\002)";
    static char fmt_1591[] = "(\002 COUNT = \002i4,\002INDXNO = \002i5,\002 \
SEQNO = \0022a4)";
    static char fmt_1592[] = "(\0021CNTM\002/(\0020\00212x,4d16.7))";
    static char fmt_1593[] = "(\0021TMATRX\002/(\0020\00212x,4d16.7))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();
    double pow_dd();

    /* Local variables */
    static integer i__, j, n;
    static doublereal ps, xv, yv;
    static integer kkk;
#define arr ((doublereal *)&a3fxd1_)
#define irr ((integer *)&a3fxi1_)
    extern integer nxv_(), nyv_();
#define idac ((integer *)&a3fxd1_ + 492)
    static integer jjjj;
    extern /* Subroutine */ int type5_();
    static integer khold, ipltr;
    static doublereal dummy;
    extern /* Subroutine */ int multm_(), tapech_(), aserch_();
#define nucltp ((doublereal *)&ataptb_1 + 7)
#define lclprt ((integer *)&asistm_1 + 1)
    extern /* Subroutine */ int tapeop_(), bufftp_(), taperd_(), astore_(), 
	    framev_(), acntrl_(), clprnt_(), tapewt_(), tsfmpt_(), tsfmvc_(), 
	    vtlaxs_(), printv_(), prtset_(), tracut_(), matmov_(), msetup_(), 
	    pltset_();

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_2009, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_60, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_111, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_2009, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_116, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_9018, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_948, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_957, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_990, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_1116, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_1118, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_1247, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_1190, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_1249, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_1248, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_1590, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_1591, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_1592, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_1593, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* ...  PRINT WHAT SECTION THIS IS */
/* L1: */
    io___10.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___10);
    e_wsfe();
    for (i__ = 1; i__ <= 580; ++i__) {
/* L2003: */
	arr[i__ - 1] = 0.;
    }
    for (i__ = 1; i__ <= 392; ++i__) {
/* L2004: */
	irr[i__ - 1] = 0;
    }
    if (asistm_1.itrcut <= 0) {
	goto L2006;
    } else {
	goto L2005;
    }
L2005:
    asistm_1.indexx = a0con_1.k1;
L2006:
    a3fxd1_.f0 = 0.;
    *lclprt = a0con_1.k0;
    a3fxi1_.iwarms = a0con_1.k0;
    a3fxi1_.ifalms = a0con_1.k0;
/* ...   ZERO INDEX ARRAYS */
    for (i__ = a0con_1.k1; i__ <= 160; ++i__) {
	a3fxi1_.ind2tb[i__ - 1] = a0con_1.k0;
/* L7: */
	a3fxi1_.indtab[i__ - 1] = a0con_1.k0;
    }
/* ...  TEST FOR CLPRNT FLAG */
    if (asistm_1.iclprt < 0) {
	goto L11;
    } else if (asistm_1.iclprt == 0) {
	goto L12;
    } else {
	goto L6;
    }
L11:
    asistm_1.iclprt = a0con_1.k1;
    a3fxi1_.jclprt = a0con_1.k0;
    goto L12;
L6:
    a3fxi1_.jclprt = a0con_1.k1;
    a3fxi1_.kclprt = a0con_1.k1;
    *lclprt = a0con_1.k2;
L12:
    ipltr = asistm_1.iplotr;
    a3fxd1_.partno[0] = q000hl;
    a3fxd1_.partno[1] = q001hl;
    a3fxd1_.partno[2] = q002hl;
    for (i__ = 4; i__ <= 12; ++i__) {
/* L10: */
	a3fxd1_.partno[i__ - 1] = q003hl;
    }
/* ...  HAS THERE BEEN A SECTION II ERROR */
    if (asistm_1.iwaven != 0) {
	goto L3;
    } else {
	goto L4;
    }
/* ...  SAVE INDEXX IN INDOFF AND TURN INDEXX OFF */
L3:
    a3fxi1_.indoff = asistm_1.indexx;
    asistm_1.indexx = a0con_1.k0;
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    e_wsfe();
/* ...  IS THERE A TRACUT OR COPY IN EFFECT - IF SO DELAY PLOTTING */
L4:
    if (asistm_1.indexx <= 0) {
	goto L8;
    } else {
	goto L5;
    }
/* ...  SET FLAGS */
L5:
    a3fxi1_.iplwas = asistm_1.iplotr;
    asistm_1.iplotr = a0con_1.k0;
L8:
    a3fxi1_.icopy = a0con_1.k0;
    a3fxi1_.irecno = a0con_1.k0;
    a3fxi1_.nurcno = a0con_1.k0;
    a3fxd1_.count[a0con_1.k1 - 1] = a3fxd1_.f0;
    a3fxi1_.ntab = a0con_1.k1;
    a3fxi1_.nntab = a0con_1.k1;
    a3fxi1_.maxcop = a0con_1.k3;
    a3fxi1_.iploti = a0con_1.k0;
    a3fxi1_.idplot = a0con_1.k0;
    a3fxi1_.iclwas = a0con_1.k0;
    a3fxi1_.itrafl = a0con_1.k0;
    a3fxi1_.multax = a0con_1.k0;
    a3fxi1_.ncamra = a0con_1.k0;
    a3fxi1_.ifirst = a0con_1.k0;
    a3fxi1_.igodlt = a0con_1.k0;
    a3fxi1_.iarrow = a0con_1.k0;
    a3fxi1_.ipl5ax = a0con_1.k0;
    a3fxi1_.jvectr = a0con_1.k0;
    a3fxd1_.toolng = 5.;
    a3fxi1_.ipersp = a0con_1.k0;
    jjjj = a0con_1.k0;
/* ... REWIND CLTAPE */
    tapeop_(&ataptb_1.cltape, &a0con_1.k1, &a3fxi1_.iret);
/* ... CONNECT A BUFFER   FOR READING THE CLTAPE */
    bufftp_(&ataptb_1.cltape, &a0con_1.k2);
/* ... WILL THERE BE A TRACUT OR COPY - IF SO CREATE A NEW CLTAPE */
    if (asistm_1.indexx != 0) {
	goto L20;
    } else {
	goto L40;
    }
/* ... REWIND NUCLTP- A   TRACUT OR COPY IS TO BE DONE */
L20:
    tapeop_(nucltp, &a0con_1.k1, &a3fxi1_.iret);
/* ... CONNECT A BUFFER   FOR WRITING THE NUCLTP */
    bufftp_(nucltp, &a0con_1.k1);
/* ******************************************************************** */
/* ... READ A RECORD FROM THE CLTAPE */
L40:
    taperd_(&ataptb_1.cltape, &a3fxi1_.iretvr, &a3fxi1_.numwds, &a0con_1.k4,
	     &a3fxi1_.irecno, &a0con_1.k1, &a3fxi1_.instr1, &a0con_1.k1, &
	    a3fxi1_.instr2, &a0con_1.k1, a3fxd1_.tapsto, &a0con_1.k0);

/*
    astore_(&a3fxd1_.tapsto[a0con_1.k1 - 1], &a0con_1.k8, &a3fxi1_.i1, &
	    a0con_1.k4);
    astore_(&a3fxd1_.tapsto[a0con_1.k2 - 1], &a0con_1.k8, &a3fxi1_.i2, &
	    a0con_1.k4);
*/
//replacing the two lines above with:
//a3fxi1_.i1=rint(a3fxd1_.tapsto[a0con_1.k1 - 1]);
a3fxi1_.i1=*((integer*)(&a3fxd1_.tapsto[a0con_1.k1 - 1]));
a3fxi1_.i2=*((integer*)(&a3fxd1_.tapsto[a0con_1.k2 - 1]));
/* ******************************************************************** */
/* ... WAS THE RETURN FROMTAPERD ALL RIGHT */
    if (a3fxi1_.iretvr < 0) {
	goto L120;
    } else if (a3fxi1_.iretvr == 0) {
	goto L70;
    } else {
	goto L50;
    }
L50:
    io___15.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___15);
    e_wsfe();
/* ...  TURN OFF FLAG FOR POSTPROCESSING */
    asistm_1.kflags[4] = 0;
/* ... PREPARE FOR END OF FILE EXIT FROM SECTN3 */
/* ... REWIND CLTAPE */
L70:
    tapeop_(&ataptb_1.cltape, &a0con_1.k1, &a3fxi1_.iret);
/* ... HAS THERE BEEN A TRACUT OR COPY - IF SO PUTEOF ON NEW CLTAPE */
/* L90: */
    if (asistm_1.indexx != 0) {
	goto L92;
    } else {
	goto L110;
    }
/* ... WRITE END-OF.FILE  ON NUCLTP */
L92:
    tapeop_(nucltp, &a0con_1.k2, &a3fxi1_.iret);
/* ... REWIND NUCLTP */
    tapeop_(nucltp, &a0con_1.k1, &a3fxi1_.iret);
/* ... MAKE NUCLTP INTO   CLTAPE */
    tapech_(&ataptb_1.cltape, nucltp);
/* *********************************************************************** */
/* ... THIS IS THE LOGICAL END OF THE CLTAPE PROCESSOR. RETURN TO SYSTEM */
/* ... CONTROL */
/* ... SHOULD PLOTTING BE DONE AFTER A TRACUT OR  COPY */
L110:
    if (a3fxi1_.iplwas <= 0) {
	goto L112;
    } else {
	goto L113;
    }
/* ... NO - END UP */
L112:
    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    e_wsfe();
/* ... HAS THERE BEEN PLOTTING - IF SO THEN CLEAR PLOT SYSTEM BUFFERS */
    if (asistm_1.iplotr - a0con_1.k1 != 0) {
	goto L117;
    } else {
	goto L114;
    }
/* ... CLEAR PLOT BUFFERS AND GET A NEW FRAME */
L114:
    framev_();
/* ... HAS THERE BEEN AN ARELEM ERROR - IF SO THEN PRINT STATEMENT */
L117:
    if (asistm_1.iwaven <= 0) {
	goto L93;
    } else {
	goto L2010;
    }
L2010:
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    e_wsfe();
    if (a3fxi1_.ifalms <= 0) {
	goto L93;
    } else {
	goto L115;
    }
/* ... YES-PRINT WARNING  TO PART PROGRAMMER */
/* ... HAS THERE BEEN AN ARELEM- WARNING ERROR- IF SO PRINT STATEMENT */
L93:
    if (a3fxi1_.iwarms != 0) {
	goto L115;
    } else {
	goto L118;
    }
L115:
    io___18.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___18);
    do_fio(&c__1, (char *)&a3fxi1_.ifalms, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.iwarms, (ftnlen)sizeof(integer));
    e_wsfe();
/* ... SET INDEXX TO ITS  PREVIOUS STATE */
    asistm_1.indexx = a3fxi1_.indoff;
/* ... RETURN TO APT SYSTEM CONTROL */
L118:
    asistm_1.iplotr = ipltr;
    if (asistm_1.iwaven - a0con_1.k2 != 0) {
	goto L119;
    } else {
	goto L109;
    }
L109:
    asistm_1.iwaven = a0con_1.k0;
L119:
    acntrl_();
/* ... INDEXX IS ON AND   PLOTTING IS WANTED SO */
/* ... INITIALIZE TO TURN OFF TRACUT,COPY AND CL  PRINTING */
L113:
    asistm_1.iplotr = a3fxi1_.iplwas;
    a3fxi1_.iplwas = a0con_1.k0;
    asistm_1.iclprt = 0;
    asistm_1.indexx = a0con_1.k0;
    a3fxi1_.itrafl = a0con_1.k0;
/* ... REWIND THE NUCLTP  AND PROCESS IT FOR      PLOTTING */
    goto L8;
/* *********************************************************************** */
L120:
    if (a3fxi1_.instr1 != 1000) {
	goto L121;
    }
    a3fxi1_.intseq = a3fxi1_.instr2;
    a3fxd1_.seqno[0] = a3fxd1_.tapsto[1];
    goto L125;
/* ...  IS THIS CLPRNT/- IF SO SET PRINT FLAGS */
L121:
    if (a3fxi1_.instr1 == 13000) {
	goto L678;
    }
/* ... IS THIS MULTAX - IF SO SET THE MULTAX FLAG */
    if (a3fxi1_.instr1 == 9000) {
	goto L310;
    }
/* ... WILL THERE BE A TRACUT OR COPY */
L125:
    if (asistm_1.indexx - a0con_1.k1 != 0) {
	goto L130;
    } else {
	goto L131;
    }
/* ... WILL THERE BE A PLOT - IF SO THEN ENTER SECTN3 */
/* ...                        IF NOT A TRACUT,COPY,OR PLOT THE MAYBE CLPRT */
L130:
    if (asistm_1.iplotr - a0con_1.k1 != 0) {
	goto L191;
    } else {
	goto L131;
    }
L131:
    if (asistm_1.iclprt - a0con_1.k1 != 0) {
	goto L140;
    } else {
	goto L132;
    }
L132:
    if (a3fxi1_.jclprt - a0con_1.k1 != 0) {
	goto L140;
    } else {
	goto L133;
    }
L133:
    if (a3fxi1_.kclprt != 0) {
	goto L140;
    } else {
	goto L134;
    }
L134:
    clprnt_();
    a3fxi1_.nrecno = a3fxi1_.irecno;
/* ... COMPUTE IRECTP FOR MAJOR RECORD TYPE */
L140:
    a3fxi1_.irectp = a3fxi1_.instr1 / 1000;
/* ******************************************************************** */
/* ... BRANCH ACCORDING TO RECORD TYPE */
    switch ((int)a3fxi1_.irectp) {
	case 1:  goto L150;
	case 2:  goto L600;
	case 3:  goto L210;
	case 4:  goto L150;
	case 5:  goto L400;
	case 6:  goto L1800;
	case 7:  goto L150;
	case 8:  goto L150;
	case 9:  goto L310;
	case 10:  goto L150;
	case 11:  goto L150;
	case 12:  goto L150;
	case 13:  goto L150;
	case 14:  goto L150;
    }
/* ... THIS IS THE COMMON RETURN POINT FOR ALL SECTIONS OF THE CLTAPE */
/* ... PROCESSOR AND THE POINT AT WHICH THE NEW RECORDS ARE WRITTEN ON */
/* ... THE NUCLTP AND PRINTED IF ICLPRT = 1. */
/* ... IS TRACUT OR COPY  IN EFFECT */
L150:
    if (asistm_1.indexx - a0con_1.k1 != 0) {
	goto L190;
    } else {
	goto L160;
    }
/* ... INCREMENT THE RECORD NUMBER */
L160:
    a3fxi1_.nurcno += a0con_1.k1;
/* ... WRITE A RECORD ON THE NEW CLTAPE */
    tapewt_(nucltp, &a3fxi1_.iretvr, &a0con_1.k4, &a3fxi1_.nurcno, &
	    a0con_1.k1, &a3fxi1_.instr1, &a0con_1.k1, &a3fxi1_.instr2, &
	    a0con_1.k1, a3fxd1_.tapsto, &a3fxi1_.numwds);
/* ... WAS THE RETURN FROMTAPEWT ALL RIGHT */
    if (a3fxi1_.iretvr < 0) {
	goto L190;
    } else if (a3fxi1_.iretvr == 0) {
	goto L170;
    } else {
	goto L50;
    }
/* ... END OF TAPE BRANCH - WRITE COMMENT */
L170:
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    e_wsfe();
    goto L70;
/* ... YES - CHECK FOR    CLPRNT */
L190:
    if (a3fxi1_.kclprt != 0) {
	goto L191;
    } else {
	goto L202;
    }
L191:
    if (asistm_1.iclprt - a0con_1.k1 != 0) {
	goto L202;
    } else {
	goto L192;
    }
L192:
    if (a3fxi1_.jclprt - a0con_1.k1 != 0) {
	goto L202;
    } else {
	goto L200;
    }
/* ... PRINT THE PRESENT RECORD IF ICLPRT IS ON */
L200:
    clprnt_();
    a3fxi1_.nrecno = a3fxi1_.irecno;
/* ... GO READ ANOTHER RECORD FROM CLTAPE */
/* ... IS THIS RECORD FINI - IF SO CHECK FOR A PLOT IN EFFECT BY GOING TO */
/* ... THE INDEX/N AREA. */
/* ... IS THIS A FINI */
L202:
    if (a3fxi1_.instr1 - 14000 != 0) {
	goto L40;
    } else {
	goto L205;
    }
/* ... MAKE INTO AN ALL */
/* ...  STORE AN INDEX/-1 IN INDEX TABLES */
L205:
    a3fxd1_.tapsto[a0con_1.k1 - 1] = -1.;
    goto L900;
/* ... END OF MAIN SECTION OF CLPROS CONTROL...... */
/* *********************************************************************** */
/* ... SETUP INFORMATION FOR CIRCLE SURFACE TYPE MACHINE INTERPOLATION.. */
/* ... IS THIS RECORD A CIRCLE - IF NOT READ ANOTHER RECORD */
L210:
    if ((i__1 = a3fxi1_.i2 - a0con_1.k4) < 0) {
	goto L300;
    } else if (i__1 == 0) {
	goto L230;
    } else {
	goto L212;
    }
/* .. . IS THIS RECORD A CYLINDER, IF SO TREAT AS CIRCLE */
L212:
    if (a3fxi1_.i2 - a0con_1.k5 != 0) {
	goto L300;
    } else {
	goto L230;
    }
/* ... IS THERE A COPY OR TRACUT IN EFFECT - IF SO TRANSFORM THE CENTER */
/* ... POINT AND VECTOR OF THE CIRCLE */
/* ... IS COPY IN EFFECT */
L230:
    if (a3fxi1_.icopy <= 0) {
	goto L240;
    } else {
	goto L250;
    }
/* ... IS TRACUT IN EFFECT */
L240:
    if (a3fxi1_.itrafl - a0con_1.k1 != 0) {
	goto L300;
    } else {
	goto L250;
    }
/* ... YES-TRANSFORM THE  CENTER */
L250:
    tsfmpt_(a3fxd1_.tmatrx, &a3fxd1_.tapsto[a0con_1.k6 - 1], &
	    a3fxd1_.tapsto[a0con_1.k6 - 1]);
/* ... TRANSFORM THE VECTOR */
    tsfmvc_(a3fxd1_.tmatrx, &a3fxd1_.tapsto[a0con_1.k9 - 1], &
	    a3fxd1_.tapsto[a0con_1.k9 - 1]);
/* ... GET SCALE FACTOR IF ANY AND TRANSFORM THE RADIUS */
    ps = a3fxd1_.tmatrx[0] * a3fxd1_.tmatrx[4] * a3fxd1_.tmatrx[8] + 
	    a3fxd1_.tmatrx[3] * a3fxd1_.tmatrx[7] * a3fxd1_.tmatrx[2] + 
	    a3fxd1_.tmatrx[6] * a3fxd1_.tmatrx[1] * a3fxd1_.tmatrx[5] - 
	    a3fxd1_.tmatrx[6] * a3fxd1_.tmatrx[4] * a3fxd1_.tmatrx[2] - 
	    a3fxd1_.tmatrx[0] * a3fxd1_.tmatrx[7] * a3fxd1_.tmatrx[5] - 
	    a3fxd1_.tmatrx[3] * a3fxd1_.tmatrx[1] * a3fxd1_.tmatrx[8];
    d__1 = abs(ps);
    dummy = pow_dd(&d__1, &c_b77);
    if (dummy <= 1.00001) {
	goto L300;
    }
    a3fxd1_.tapsto[11] *= dummy;
L300:
    goto L150;
/* *********************************************************************** */
/* ...  IF MULTIPLE AXIS IS USED THIS SECTION WILL SET MLTFLG = 1. */
/* ... IS THIS A MULTAX */
L310:
    if (a3fxi1_.instr2 - a0con_1.k2 != 0) {
	goto L321;
    } else {
	goto L318;
    }
L318:
    if (a3fxi1_.i1 <= 0) {
	goto L319;
    } else {
	goto L320;
    }
L319:
    a3fxi1_.multax = a0con_1.k0;
    goto L321;
/* ... YES - SET FLAG */
L320:
    a3fxi1_.multax = a0con_1.k1;
L321:
    if (asistm_1.iclprt - a0con_1.k1 != 0) {
	goto L330;
    } else {
	goto L322;
    }
L322:
    if (a3fxi1_.jclprt - a0con_1.k1 != 0) {
	goto L330;
    } else {
	goto L323;
    }
L323:
    if (a3fxi1_.kclprt != 0) {
	goto L330;
    } else {
	goto L324;
    }
L324:
    clprnt_();
    a3fxi1_.nrecno = a3fxi1_.irecno;
L330:
    goto L150;
/* *********************************************************************** */
L400:
    type5_(&kkk);
/* ... PRINT THIS RECORD */
    switch ((int)kkk) {
	case 1:  goto L150;
	case 2:  goto L1550;
    }
/* ... THIS IS THE END OF THE POINTS RECORD BRANCH.... */
/* *********************************************************************** */
/* ... THIS SECTION SENSES THE TRACUT,INDEX,COPY, AND PLOT... */
/* ... SUBTYP 1038 IS TRACUT ,1039 IS INDEX,1040 IS COPY,1041 IS PLOT, */
/* ... 1042 IS OVPLOT AND 1047 IS CAMERA */
L600:
    a3fxi1_.jsw = a3fxi1_.instr2 - 1037;
/* ...  IS THIS A VTLAXS/ COMMAND */
    if (a3fxi1_.instr2 - 1070 != 0) {
	goto L601;
    } else {
	goto L627;
    }
/* ... IS JSW POSITIVE */
L601:
    if (a3fxi1_.jsw <= 0) {
	goto L150;
    } else {
	goto L602;
    }
/* ... YES-IS JSW LESS    THAN ELEVEN */
L602:
    if (a3fxi1_.jsw - a0con_1.k10 <= 0) {
	goto L605;
    } else {
	goto L150;
    }
/* ... GO TO (TRACUT,INDEX,COPY,PLOT,OVPLOT,LETTER,PPRINT,PARTNO,CAMERA ) */
L605:
    switch ((int)a3fxi1_.jsw) {
	case 1:  goto L700;
	case 2:  goto L900;
	case 3:  goto L950;
	case 4:  goto L610;
	case 5:  goto L610;
	case 6:  goto L620;
	case 7:  goto L630;
	case 8:  goto L650;
	case 9:  goto L150;
	case 10:  goto L660;
    }
/* ... IS SECTN 0 PLOT FLAG ON - IF NOT GO READ A RECORD. */
L610:
    if (asistm_1.iplotr - a0con_1.k1 != 0) {
	goto L150;
    } else {
	goto L1600;
    }
/* ... IS THIS THE INNER PLOT OF A NEST - IF SO GO READ A RECORD. */
L620:
    if (a3fxi1_.idplot - a0con_1.k2 != 0) {
	goto L625;
    } else {
	goto L150;
    }
/* ... LETTER - SET UP PARAMETERS FOR THE FOLLOWING PPRINT. */
L625:
    a3fxd1_.word = a3fxd1_.tapsto[3];
    n = (integer) a3fxd1_.word;
    xv = a3fxd1_.tapsto[a0con_1.k1 - 1];
    a3fxi1_.nx = nxv_(&xv);
    yv = a3fxd1_.tapsto[a0con_1.k2 - 1];
    a3fxi1_.ny = nyv_(&yv);
    jjjj = a0con_1.k1;
    goto L150;
/* ...  PROCESS THE VTLAXS */
L627:
    if (asistm_1.iptnly >= 0) {
	goto L628;
    }
    if (a3fxi1_.irecno + asistm_1.iptnly <= 0) {
	goto L150;
    }
    asistm_1.iptnly = -asistm_1.iptnly;
L628:
    if (asistm_1.iplotr != 0) {
	goto L150;
    }
    vtlaxs_();
    goto L202;
/* ... IS THIS THE INNER PLOT OF A NEST - IF SO GO READ A RECORD. */
L630:
    if (a3fxi1_.idplot - a0con_1.k2 != 0) {
	goto L632;
    } else {
	goto L150;
    }
/* ... PPRINT - SAVE THE BCD TEXT. */
L632:
    i__1 = a3fxi1_.numwds;
    i__2 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
/* L635: */
	a3fxd1_.pprint[i__ - 1] = a3fxd1_.tapsto[i__ - 1];
    }
/* ... IS A PLOT IN EFFECT - IF NOT GO READ A RECORD. */
    if (asistm_1.iplotr - a0con_1.k1 != 0) {
	goto L150;
    } else {
	goto L640;
    }
/* ... HAS THERE BEEN A LETTER - IF SO THEN PLOT THE BCD TEXT. */
L640:
    if (jjjj != 0) {
	goto L645;
    } else {
	goto L150;
    }
L645:
    printv_(&n, a3fxd1_.pprint, &a3fxi1_.nx, &a3fxi1_.ny);
    jjjj = a0con_1.k0;
    goto L150;
/* ... SAVE THE PARTNO BCD TEXT - TO BE PLOTTED IN THE SETUPP SUBROUTINE */
L650:
    i__2 = a3fxi1_.numwds;
    i__1 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
/* L655: */
	a3fxd1_.partno[i__ - 1] = a3fxd1_.tapsto[i__ - 1];
    }
    goto L150;
/* ...   IS THE MODIFIER BOTH */
/* ... CAMERA - IS THE MODIFIER BOTH(83). - IF SO SET NCAMRA TO BOTH CAMRA */
L660:
    if (a3fxi1_.i1 - 83 != 0) {
	goto L665;
    } else {
	goto L670;
    }
/* ... NO  - SET FOR ONE  CAMERA */
L665:
    a3fxd1_.word = a3fxd1_.tapsto[0];
    a3fxi1_.ncamra = (integer) a3fxd1_.word;
    goto L150;
/* ... YES - SET FOR BOTH CAMERAS */
L670:
    a3fxi1_.ncamra = a0con_1.k3;
    goto L150;
/* *********************************************************************** */
L678:
    khold = asistm_1.kflags[6];
    asistm_1.kflags[6] = 1;
    if (idac[OTHER_ENDIAN_S(1)] == 1 && a3fxi1_.instr2 == 5) {
	goto L40;
    }
    asistm_1.kflags[6] = 0;
    if (a3fxd1_.tapsto[0] == 0. && a3fxi1_.instr2 == 5) {
	goto L40;
    }
    asistm_1.kflags[6] = khold;
    prtset_(&kkk);
    switch ((int)kkk) {
	case 1:  goto L40;
	case 2:  goto L125;
    }
/* *********************************************************************** */
L700:
    if (asistm_1.iptnly >= 0) {
	goto L710;
    }
    if (a3fxi1_.irecno + asistm_1.iptnly <= 0) {
	goto L150;
    }
    asistm_1.iptnly = -asistm_1.iptnly;
L710:
    tracut_(&kkk);
    goto L150;
/* *********************************************************************** */
/* ... THIS SECTION PROCESSES THE INDEX INSTRUCTION... */
/* ... IT ALSO SETS PLOT FLAGS AND TESTS TO SEE IF THE PRESENT INDEX IS */
/* ...   FOR A PLOT */
/* ...    NOTE... INDEX STORED IN TABLE AS FIXED PT AND TESTED FIXED */
/* ...    NOTE... INDEX RECORD NO STORED IN TABLE AS FIXED */
/* ...  IS THE INDEX TABLE FULL */
/* ...  INDEX/N,NOMORE,  COMPLETES COPY,  NOMORE = 53 */
L900:
    a3fxd1_.word = a3fxd1_.tapsto[0];
    a3fxi1_.it = (integer) a3fxd1_.word;
    if (a3fxi1_.i2 - 53 != 0) {
	goto L9000;
    } else {
	goto L9200;
    }
L9200:
    if (asistm_1.iplotr <= 0) {
	goto L9202;
    } else {
	goto L150;
    }
L9202:
    if (a3fxi1_.nntab - 160 >= 0) {
	goto L947;
    } else {
	goto L9210;
    }
/*     SEE IF INDEX/N,M IS IN IND2TB */
L9210:
    i__1 = a3fxi1_.nntab;
    i__2 = a0con_1.k2;
    for (i__ = a0con_1.k1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
	if (a3fxi1_.it - a3fxi1_.ind2tb[i__ - 1] != 0) {
	    goto L9220;
	} else {
	    goto L9250;
	}
L9220:
	;
    }
    a3fxi1_.ind2tb[a3fxi1_.nntab - 1] = a3fxi1_.it;
    a3fxi1_.ind2tb[a3fxi1_.nntab] = a3fxi1_.irecno;
    a3fxi1_.nntab += a0con_1.k2;
    goto L9011;
/*     IS THIS INDEX/I,NOMORE LEGITIMATE.  IF YES, GO TO 9251 */
L9250:
    if (a3fxi1_.irecno - a3fxi1_.ind2tb[i__] != 0) {
	goto L9016;
    } else {
	goto L9251;
    }
/*     IS THE INDEX/I,NOMORE FOR THE COPY IN EFFECT.  IF YES, GO TO 9230 */
L9251:
    if (a3fxi1_.it - a3fxi1_.indxno[0] != 0) {
	goto L150;
    } else {
	goto L9230;
    }
/*     IF NOT THE SAME, MUST BE NORMAL COPY */
L9230:
    aserch_(&ataptb_1.cltape, &a3fxi1_.irecni[a0con_1.k1 - 1], &
	    a3fxi1_.iret);
    goto L150;
/*     NOTE....INDEX STORED IN TABLE AS FIXED PT, AND TESTED FIXED */
/*     NOTE....INDEX RECORD NUMBER STORED IN TABLE AS FIXED */
L9000:
    if (a3fxi1_.ntab - 160 >= 0) {
	goto L947;
    } else {
	goto L901;
    }
/* ... NO - SEARCH THE    TABLE FOR SAME VALUE */
L901:
    i__2 = a3fxi1_.ntab;
    i__1 = a0con_1.k2;
    for (i__ = a0con_1.k1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
/* ... COMPARE INDEX NO.  WITH TABLE */
	if (a3fxi1_.it - a3fxi1_.indtab[i__ - 1] != 0) {
	    goto L9010;
	} else {
	    goto L9014;
	}
L9010:
	;
    }
    goto L9017;
/* ...   CHECK FOR DUPLICATE INDEX NUMBERS ON FIRST PASS ONLY */
L9014:
    if (asistm_1.iplotr - 1 >= 0) {
	goto L9011;
    } else {
	goto L9015;
    }
L9015:
    if (a3fxi1_.irecno - a3fxi1_.indtab[i__] != 0) {
	goto L9016;
    } else {
	goto L9011;
    }
L9016:
    if (asistm_1.iptnly >= 0) {
	goto L9019;
    }
    if (a3fxi1_.irecno + asistm_1.iptnly <= 0) {
	goto L150;
    }
    asistm_1.iptnly = -asistm_1.iptnly;
L9019:
    io___27.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___27);
    e_wsfe();
    goto L945;
/* ... NOT FOUND SO SAVE */
L9017:
    a3fxi1_.indtab[a3fxi1_.ntab - 1] = a3fxi1_.it;
    a3fxi1_.indtab[a3fxi1_.ntab] = a3fxi1_.irecno;
    a3fxi1_.ntab += a0con_1.k2;
/* ... IS PLOT REQUESTED */
L9011:
    if (asistm_1.iplotr <= 0) {
	goto L946;
    } else {
	goto L902;
    }
/* ... IS A PLOT NOW IN   EFFECT */
L902:
    if ((i__1 = a3fxi1_.idplot - a0con_1.k1) < 0) {
	goto L910;
    } else if (i__1 == 0) {
	goto L920;
    } else {
	goto L905;
    }
/* ... DOES THIS INDEX NO.AGREE WITH PREVIOUS PLOTCOMMAND NO. */
L905:
    if (a3fxi1_.iplotx - a3fxi1_.it != 0) {
	goto L910;
    } else {
	goto L935;
    }
/* ... DOES THIS REC. NO. AGREE WITH LAST ONE     PRINTED */
L910:
    if (a3fxi1_.nrecno - a3fxi1_.irecno <= 0) {
	goto L915;
    } else {
	goto L940;
    }
/* ... IS CLPRNT WANTED */
L915:
    if (asistm_1.iclprt != 0) {
	goto L917;
    } else {
	goto L916;
    }
/* ... TURN PRINTING ON */
L916:
    asistm_1.iclprt = a3fxi1_.iclwas;
L917:
    a3fxi1_.iclwas = a0con_1.k0;
    goto L946;
/* ... DOES THIS REC. NO. AGREE WITH LAST ONE     PRINTED */
L920:
    if (a3fxi1_.nrecno - a3fxi1_.irecno <= 0) {
	goto L925;
    } else {
	goto L930;
    }
/* ... IS CLPRNT WANTED */
L925:
    if (asistm_1.iclprt != 0) {
	goto L927;
    } else {
	goto L926;
    }
/* ... TURN PRINTING ON */
L926:
    asistm_1.iclprt = a3fxi1_.iclwas;
L927:
    a3fxi1_.iclwas = a0con_1.k0;
    goto L942;
/* ... HAS PRINT BEEN OFF */
L930:
    if (a3fxi1_.iclwas != 0) {
	goto L933;
    } else {
	goto L932;
    }
L932:
    a3fxi1_.iclwas = asistm_1.iclprt;
L933:
    asistm_1.iclprt = a0con_1.k0;
    goto L942;
/* ... HAS PRINT BEEN OFF */
L935:
    if (a3fxi1_.iclwas != 0) {
	goto L938;
    } else {
	goto L936;
    }
/* ... RESTORE PRINTING   MODE */
L936:
    a3fxi1_.iclwas = asistm_1.iclprt;
/* ... TURN PRINTING OFF */
L938:
    asistm_1.iclprt = a0con_1.k0;
/* ... TURN PLOT FRAME OFF */
    a3fxi1_.idplot = a0con_1.k0;
/* ... GO FIND NESTED PLOTCOMMAND */
    aserch_(&ataptb_1.cltape, &a3fxi1_.idplsq, &a3fxi1_.iret);
/* ...  IS THIS A FINI */
    if (a3fxi1_.instr1 - 14000 != 0) {
	goto L150;
    } else {
	goto L40;
    }
/* ...  IS ICLWAS ZERO */
L940:
    if (a3fxi1_.iclwas != 0) {
	goto L943;
    } else {
	goto L941;
    }
/* ...  SAVE ICLPRT AND   TURN IT OFF */
L941:
    a3fxi1_.iclwas = asistm_1.iclprt;
L943:
    asistm_1.iclprt = a0con_1.k0;
    goto L946;
/* ...  IS THIS INDEX/    FOR A PLOT/ */
L942:
    if (a3fxi1_.iplotx - a3fxi1_.it != 0) {
	goto L946;
    } else {
	goto L944;
    }
/* ...  TURN OFF PLOT     FLAGS */
L944:
    a3fxi1_.idplot = a0con_1.k0;
    a3fxi1_.iploti = a0con_1.k0;
/* ... IS THIS A FINI */
L946:
    if (a3fxi1_.instr1 - 14000 != 0) {
	goto L150;
    } else {
	goto L70;
    }
/* ... INDEX TABLE FILLED TURN OFF PLOT AND COPY  TURN ON CLPRNT */
L947:
    io___28.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___28);
    e_wsfe();
L945:
    asistm_1.iwaven = a0con_1.k1;
    a3fxi1_.iplwas = a0con_1.k0;
    asistm_1.iplotr = a0con_1.k0;
    asistm_1.iclprt = a0con_1.k1;
    a3fxi1_.iclwas = a0con_1.k0;
    asistm_1.indexx = a0con_1.k0;
/* ... IS THIS A FINI */
    if (a3fxi1_.instr1 - 14000 != 0) {
	goto L9208;
    } else {
	goto L9209;
    }
/* ... ADJUST INDEX TABLE AND PROCEED WITH FINI */
L9209:
    a3fxi1_.nntab -= a0con_1.k2;
    goto L9210;
L9208:
    if (a3fxi1_.jclprt <= 0) {
	goto L951;
    } else {
	goto L949;
    }
L949:
    if (a3fxi1_.kclprt <= 0) {
	goto L150;
    } else {
	goto L952;
    }
L951:
    a3fxi1_.jclprt = a0con_1.k1;
L952:
    a3fxi1_.kclprt = a0con_1.k0;
    goto L200;
/* *********************************************************************** */
/* ... THIS SECTION PROCESSES THE COPY INSTRUCTION.THE PROGRAM IS SETUP */
/* ... TO PERFORM THREE LEVELS OF NESTED COPIES. THE ONLY LIMITATION ON */
/* ... THIS IS MAXCOP AND THE AMOUNT OF STORAGE PROVIDED FOR AMATRX,CNTMAT */
/* ... COUNT,INDXNO AND IRECNI. */
/* ... FOR EACH ADDITIONAL NEST AMATRX AND CNTMAT EACH MUST BE INCREASED */
/* ... BY 12. COUNT,INDXNO, AND IRECNI EACH MUST BE INCREASED BY 1... */
/* ... ALSO MAXCOP MUST BE INCREASED BY 1.. */
/* ... AMATRX IS THE MATRIX DEFINED BY EACH COPY AS IT IS SENSED AND IS */
/* ... SET UP BY XYROT,SAME OR MODIFY INSTRUCTIONS. */
/* ... CNTMAT IS THE CURRENT RESULTANT COPY MATRIX. */
/* ... */
/* ... TRAMAT IS THE MATRIX CREATED BY A TRACUT INSTRUCTION. */
/* ... COUNT IS THE NUMBER OF TIMES A COPY IS TO LOOP. */
/* ... TMATRX IS THE COMBINATION OF ALL MATRICES PRESENTLY IN EFFECT. */
/* ... INDXNO IS THE NUMBER OF THE COPY JUST SETUP(ITPSTO(4)). */
/* ... IRECNI IS THE RECORD NUMBER OF THE CURRENT  COPY. */
/* ... IRECNO IS THE RECORD NUMBER OF THE INSTRUCTION JUST READ. */
L950:
    if (asistm_1.iptnly >= 0) {
	goto L953;
    }
    if (a3fxi1_.irecno + asistm_1.iptnly <= 0) {
	goto L150;
    }
    asistm_1.iptnly = -asistm_1.iptnly;
/* ... IS A COPY OR TRACUTWANTED */
L953:
    if (asistm_1.indexx - 1 != 0) {
	goto L150;
    } else {
	goto L955;
    }
/* ... IS A COPY IN EFFECT */
L955:
    if (a3fxi1_.i2 == 29 && a3fxd1_.tapsto[5] == 0.) {
	goto L956;
    }
    if (a3fxi1_.i2 == 34 && a3fxd1_.tapsto[3] == 0.) {
	goto L956;
    }
    if (a3fxi1_.i2 == 54 && a3fxd1_.tapsto[2] == 0.) {
	goto L956;
    }
    if (a3fxi1_.i2 == 55 && a3fxd1_.tapsto[16] == 0.) {
	goto L956;
    }
    if (a3fxi1_.icopy < 0) {
	goto L1550;
    } else if (a3fxi1_.icopy == 0) {
	goto L1030;
    } else {
	goto L960;
    }
L956:
    io___29.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___29);
    e_wsfe();
    goto L150;
/* ... HAS THE MAXIMUM    NUMBER OF COPIES BEEN   EXCEEDED */
L960:
    if (a3fxi1_.maxcop - a3fxi1_.icopy >= 0) {
	goto L970;
    } else {
	goto L980;
    }
/* ... IS THIS THE CORRECT COPY */
L970:
    if (a3fxi1_.irecno - a3fxi1_.irecni[a0con_1.k1 - 1] != 0) {
	goto L1000;
    } else {
	goto L1100;
    }
/* ... TOO MANY NESTED    COPIES */
L980:
    io___30.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___30);
    e_wsfe();
    goto L945;
/* ... NO....THEN PUSH DOWN */
/* ... THIS SECTION IS THE PUSH DOWN FOR AMATRX,CNTMAT,COUNT AND INDXNO... */
/* ... AND IRECNI */
/* ... MORE THAN ONE COPY PUSHDOWN MATRICES */
L1000:
    a3fxi1_.jcopy = a3fxi1_.icopy * a0con_1.k12;
    i__1 = a3fxi1_.jcopy;
    i__2 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
	a3fxi1_.kcopy = a3fxi1_.jcopy - i__ + a0con_1.k1;
	a3fxd1_.amtr[a3fxi1_.kcopy + 11] = a3fxd1_.amtr[a3fxi1_.kcopy - 1]
		;
	a3fxd1_.tntm[a3fxi1_.kcopy + 11] = a3fxd1_.tntm[a3fxi1_.kcopy - 1]
		;
/* L1010: */
	a3fxd1_.cntm[a3fxi1_.kcopy + 11] = a3fxd1_.cntm[a3fxi1_.kcopy - 1]
		;
    }
/* ... MORE THAN ONE COPY PUSHDOWN FLAGS */
    i__2 = a3fxi1_.icopy;
    i__1 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
	a3fxi1_.kcopy = a3fxi1_.icopy - i__ + a0con_1.k1;
	a3fxd1_.count[a3fxi1_.kcopy] = a3fxd1_.count[a3fxi1_.kcopy - 1];
	a3fxd1_.cont[a3fxi1_.kcopy] = a3fxd1_.cont[a3fxi1_.kcopy - 1];
	a3fxi1_.indxno[a3fxi1_.kcopy] = a3fxi1_.indxno[a3fxi1_.kcopy - 1];
/* L1020: */
	a3fxi1_.irecni[a3fxi1_.kcopy] = a3fxi1_.irecni[a3fxi1_.kcopy - 1];
    }
L1030:
    a3fxi1_.icopy += a0con_1.k1;
/* ... FIND TRANSL, XYROT, SAME, MODIFY, OR MIRROR IN THAT ORDER */
/* ... IS THIS A TRANSL */
    if ((i__1 = a3fxi1_.i2 - 29) < 0) {
	goto L1040;
    } else if (i__1 == 0) {
	goto L1250;
    } else {
	goto L1035;
    }
/* ... IS THIS A XYROT */
L1035:
    if (a3fxi1_.i2 - 34 != 0) {
	goto L1060;
    } else {
	goto L1270;
    }
/* ... INCORRECT MODIFIER IN A COPY */
L1040:
    io___31.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___31);
    e_wsfe();
/* ... TURN OFF COPY,PLOT,TRACUT-TURN ON CLPRNT */
/* L1041: */
    goto L945;
/* ... IS THIS A SAME */
L1060:
    if (a3fxi1_.i2 - 54 != 0) {
	goto L1070;
    } else {
	goto L1280;
    }
/* ... IS THIS A MODIFY */
L1070:
    if (a3fxi1_.i2 - 55 != 0) {
	goto L1080;
    } else {
	goto L1300;
    }
/* ... IS THIS A MIRROR */
L1080:
    if (a3fxi1_.i2 - 56 != 0) {
	goto L1090;
    } else {
	goto L1400;
    }
L1090:
    goto L1040;
/* *********************************************************************** */
/* ... PROPER COPY HAS BEEN FOUND */
L1100:
    a3fxd1_.count[0] += -1.;
    a3fxd1_.cont[0] += 1.;
/* ... HAS THE PRESENT COPY LOOP BEEN COMPLETED. */
/* L1110: */
    if ((d__1 = a3fxd1_.count[a0con_1.k1 - 1]) < 0.) {
	goto L1115;
    } else if (d__1 == 0) {
	goto L1112;
    } else {
	goto L1150;
    }
/* ...  IS THERE MORE THANONE COPY */
L1112:
    if ((i__1 = a3fxi1_.icopy - a0con_1.k1) < 0) {
	goto L1550;
    } else if (i__1 == 0) {
	goto L1113;
    } else {
	goto L1120;
    }
/* ... IS A TRACUT IN     EFFECT */
L1113:
    if (a3fxi1_.itrafl - a0con_1.k1 != 0) {
	goto L1145;
    } else {
	goto L1114;
    }
/* ... MOVE THE TRACUT    MATRIX */
L1114:
    matmov_(a3fxd1_.tramat, a3fxd1_.tmatrx);
    goto L1145;
/* ... NO. OF TIMES THRU  THIS COPY WOULD EXCEED  (N). */
L1115:
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    e_wsfe();
/* L1117: */
    a3fxd1_.word = a3fxd1_.count[0];
    a3fxi1_.it = (integer) a3fxd1_.word;
    io___33.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___33);
    do_fio(&c__1, (char *)&a3fxi1_.it, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.indxno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&c__1, (char *)&a3fxd1_.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    do_fio(&c__1, (char *)&a3fxd1_.cseqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
/* ... TURN OFF COPY,PLOT,TRACUT - TURN ON CLPRNT */
    asistm_1.iwaven = a0con_1.k1;
    asistm_1.indexx = a0con_1.k0;
    asistm_1.iplotr = a0con_1.k0;
    asistm_1.iclprt = a0con_1.k1;
    goto L70;
/* ... YES.---THEN PUSH UP AMATRX,CNTMAT,COUNT,INDXNO, AND IRECNI. */
L1120:
    a3fxi1_.jcopy = a3fxi1_.icopy * a0con_1.k12;
    i__1 = a3fxi1_.jcopy;
    i__2 = a0con_1.k1;
    for (i__ = a0con_1.k1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) 
	    {
	a3fxd1_.amtr[i__ - 1] = a3fxd1_.amtr[i__ + 11];
	a3fxd1_.tntm[i__ - 1] = a3fxd1_.tntm[i__ + 11];
/* L1130: */
	a3fxd1_.cntm[i__ - 1] = a3fxd1_.cntm[i__ + 11];
    }
    matmov_(a3fxd1_.amtr, a3fxd1_.amatrx);
    matmov_(a3fxd1_.cntm, a3fxd1_.cntmat);
    matmov_(a3fxd1_.tntm, a3fxd1_.tmatrx);
    if (a3fxi1_.icopy == 2) {
	goto L1134;
    }
    multm_(a3fxd1_.cntm, &a3fxd1_.cntm[12], a3fxd1_.tmatrx);
    goto L1136;
L1134:
    matmov_(a3fxd1_.cntm, a3fxd1_.tmatrx);
L1136:
    if (a3fxi1_.itrafl != 1) {
	goto L1138;
    }
    multm_(a3fxd1_.tmatrx, a3fxd1_.tramat, a3fxd1_.tmatrx);
L1138:
    i__2 = a3fxi1_.icopy;
    for (i__ = 1; i__ <= i__2; ++i__) {
	a3fxd1_.count[i__ - 1] = a3fxd1_.count[i__];
	a3fxd1_.cont[i__ - 1] = a3fxd1_.cont[i__];
	a3fxi1_.indxno[i__ - 1] = a3fxi1_.indxno[i__];
/* L1140: */
	a3fxi1_.irecni[i__ - 1] = a3fxi1_.irecni[i__];
    }
L1145:
    a3fxi1_.icopy -= a0con_1.k1;
/* ... IS CLPRNT WANTED */
    if (asistm_1.iclprt != 0) {
	goto L1146;
    } else {
	goto L150;
    }
L1146:
    if (a3fxi1_.jclprt != 0) {
	goto L1147;
    } else {
	goto L150;
    }
/* ... YES-PRINT WHAT COPYTHIS IS */
L1147:
    a3fxd1_.word = a3fxd1_.tapsto[0];
    a3fxi1_.it = (integer) a3fxd1_.word;
    io___34.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___34);
    do_fio(&c__1, (char *)&a3fxi1_.it, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L150;
/* ... NO....THEN UPDATE TMATRX */
/* ... IS THIS A SAME */
L1150:
    if (a3fxi1_.i2 - 54 != 0) {
	goto L1160;
    } else {
	goto L1170;
    }
/* ... NO-UPDATE MATRICES */
L1160:
    multm_(a3fxd1_.amatrx, a3fxd1_.tmatrx, a3fxd1_.tmatrx);
L1170:
    multm_(a3fxd1_.amatrx, a3fxd1_.cntmat, a3fxd1_.cntmat);
L1175:
    matmov_(a3fxd1_.amatrx, a3fxd1_.amtr);
    matmov_(a3fxd1_.cntmat, a3fxd1_.cntm);
    matmov_(a3fxd1_.tmatrx, a3fxd1_.tntm);
/* ... SEARCH FOR THE     MATCHING INDEX NO. */
    i__2 = a3fxi1_.ntab;
    for (i__ = 1; i__ <= i__2; i__ += 2) {
	if (a3fxi1_.indxno[a0con_1.k1 - 1] - a3fxi1_.indtab[i__ - 1] != 0) {
	    goto L1180;
	} else {
	    goto L1200;
	}
L1180:
	;
    }
/* ... ERROR EXIT */
    io___35.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___35);
    do_fio(&c__1, (char *)&a3fxi1_.indxno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    integer));
    e_wsfe();
/* ... TURN OFF PLOT,COPY,TRACUT-TURN ON CLPRNT */
    goto L945;
/* ... THIS IS THE PROPER INDEX----GO FIND IT ON THE CLTAPE... */
L1200:
    aserch_(&ataptb_1.cltape, &a3fxi1_.indtab[i__], &a3fxi1_.iret);
    a3fxi1_.indn = a3fxi1_.indxno[a0con_1.k1 - 1];
/* ...  IS CLPRNT WANTED */
    if (asistm_1.iclprt - a0con_1.k1 != 0) {
	goto L1245;
    } else {
	goto L1211;
    }
L1211:
    if (a3fxi1_.jclprt - a0con_1.k1 != 0) {
	goto L1245;
    } else {
	goto L1212;
    }
L1212:
    if (a3fxi1_.kclprt - a0con_1.k1 != 0) {
	goto L1220;
    } else {
	goto L1215;
    }
L1215:
    clprnt_();
    a3fxi1_.nrecno = a3fxi1_.irecno;
/* ...  IS THIS THE START OF A COPY */
L1220:
    if (a3fxd1_.cont[0] != 0.) {
	goto L1230;
    } else {
	goto L1240;
    }
/* ...PRINT-THIS COMPLETESPASS NO.--- THRU THIS   COPY */
L1230:
    a3fxd1_.word = a3fxd1_.cont[0];
    a3fxi1_.it = (integer) a3fxd1_.word;
    io___36.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___36);
    do_fio(&c__1, (char *)&a3fxi1_.it, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.indn, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L1245;
/* ...PRINT-THIS STARTS   PASS NO. 1  THRU THIS   COPY */
L1240:
    io___37.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___37);
    do_fio(&c__1, (char *)&a3fxi1_.indn, (ftnlen)sizeof(integer));
    e_wsfe();
/* ...  READ THE NEXT     CLTAPE RECORD */
L1245:
    taperd_(&ataptb_1.cltape, &a3fxi1_.iretvr, &a3fxi1_.numwds, &a0con_1.k4,
	     &a3fxi1_.irecno, &a0con_1.k1, &a3fxi1_.instr1, &a0con_1.k1, &
	    a3fxi1_.instr2, &a0con_1.k1, a3fxd1_.tapsto, &a0con_1.k0);
    astore_(&a3fxd1_.tapsto[a0con_1.k1 - 1], &a0con_1.k8, &a3fxi1_.i1, &
	    a0con_1.k4);
    astore_(&a3fxd1_.tapsto[a0con_1.k2 - 1], &a0con_1.k8, &a3fxi1_.i2, &
	    a0con_1.k4);
/* *********************************************************************** */
    goto L321;
/* *********************************************************************** */
L1250:
    msetup_(&a0con_1.k1, &i__);
    goto L1499;
L1270:
    msetup_(&a0con_1.k2, &i__);
    goto L1499;
L1280:
    msetup_(&a0con_1.k3, &i__);
    goto L1499;
L1300:
    msetup_(&a0con_1.k4, &i__);
    goto L1499;
L1400:
    msetup_(&a0con_1.k5, &i__);
L1499:
    switch ((int)i__) {
	case 1:  goto L190;
	case 2:  goto L1040;
	case 3:  goto L1500;
    }
/* ... THE TRANSL,XYROT,SAME,MODIFY,OR MIRROR TYPE COPY HAS BEEN SET UP... */
L1500:
    a3fxi1_.irecni[a0con_1.k1 - 1] = a3fxi1_.irecno;
    a3fxd1_.word = a3fxd1_.tapsto[0];
    a3fxi1_.indxno[0] = (integer) a3fxd1_.word;
    a3fxd1_.cont[0] = 0.;
    matmov_(a3fxd1_.amatrx, a3fxd1_.cntmat);
    matmov_(a3fxd1_.cntmat, a3fxd1_.tmatrx);
/* ... IS THERE MORE THAN ONE COPY IN EFFECT */
    if (a3fxi1_.icopy - a0con_1.k1 <= 0) {
	goto L1530;
    } else {
	goto L1510;
    }
/* ... UPDATE THE TMATRX IF THERE IS MORE THAN ONE COPY IN EFFECT */
L1510:
    i__2 = a3fxi1_.icopy;
    i__1 = a0con_1.k1;
    for (i__ = a0con_1.k2; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += i__1) 
	    {
	multm_(a3fxd1_.tmatrx, &a3fxd1_.cntm[i__ * 12 - 12], 
		a3fxd1_.tmatrx);
/* L1520: */
    }
/* ... IS A TRACUT IN     EFFECT */
L1530:
    if (a3fxi1_.itrafl - a0con_1.k1 != 0) {
	goto L1175;
    } else {
	goto L1540;
    }
/* ... UPDATE TMATRX IF THERE IS A TRACUT IN EFFECT */
L1540:
    multm_(a3fxd1_.tmatrx, a3fxd1_.tramat, a3fxd1_.tmatrx);
    goto L1175;
/* ... PRINT DIAGNOSTIC   FOR ERROR IN COPY LOGIC */
L1550:
    io___38.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___38);
    e_wsfe();
    a3fxd1_.word = a3fxd1_.count[0];
    a3fxi1_.it = (integer) a3fxd1_.word;
    io___39.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&a3fxi1_.it, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&a3fxi1_.indxno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&c__1, (char *)&a3fxd1_.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    io___40.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___40);
    i__1 = a0con_1.k3;
    for (i__ = a0con_1.k1; i__ <= i__1; ++i__) {
	i__2 = a0con_1.k4;
	for (j = a0con_1.k1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&a3fxd1_.cntmat[i__ + j * 3 - 4], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_wsfe();
    io___42.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___42);
    i__2 = a0con_1.k3;
    for (i__ = a0con_1.k1; i__ <= i__2; ++i__) {
	i__1 = a0con_1.k4;
	for (j = a0con_1.k1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&a3fxd1_.tmatrx[i__ + j * 3 - 4], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_wsfe();
    goto L70;
L1600:
    pltset_();
    goto L150;
/* ... THIS SECTION WILL SAVE THE CUTTER LENGTH TO BE USED IF THERE IS */
/* ... 5 AXIS PLOTTING. IF THE LENGTH IS ZERO IN THE CUTTER COMMAND THEN */
/* ... SET IT TO 5. */
/* ... IS THIS A CUTTER   COMMAND */
L1800:
    if (a3fxi1_.instr2 != 6) {
	goto L150;
    }
    if (a3fxi1_.numwds == 7) {
	goto L1850;
    }
    if (a3fxi1_.numwds == 1) {
	goto L1840;
    }
    if (a3fxd1_.tapsto[1] <= 5.) {
	goto L1840;
    }
    a3fxd1_.toolng = a3fxd1_.tapsto[1];
    goto L150;
/* ... SET TO 5 INCH      LENGTH */
L1840:
    a3fxd1_.toolng = 5.;
    goto L150;
/* ... CUTTER LENGTH HAS BEEN SPECIFIED - SAVE IT. */
L1850:
    a3fxd1_.toolng = a3fxd1_.tapsto[a0con_1.k7 - 1];
    goto L150;
} /* sectn3_ */

#undef lclprt
#undef nucltp
#undef idac
#undef irr
#undef arr
#undef q003hl
#undef q002hl
#undef q001hl
#undef q000hl


