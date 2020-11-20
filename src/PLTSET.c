/* PLTSET.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

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

static integer c__100 = 100;
static integer c__1 = 1;

/* Subroutine */ int pltset_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_9 = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 0. };

#define q003hl (*(doublereal *)&equiv_9)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_10 = { {'*', ' ', 'X', ' ', '*', ' ', ' ', ' '}, 0. };

#define q004hl (*(doublereal *)&equiv_10)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_11 = { {'*', ' ', 'Z', ' ', '*', ' ', ' ', ' '}, 0. };

#define q005hl (*(doublereal *)&equiv_11)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_12 = { {'*', ' ', ' ', 'Y', ' ', '*', ' ', ' '}, 0. };

#define q006hl (*(doublereal *)&equiv_12)


    /* Format strings */
    static char fmt_1749[] = "(\002-LOWER CORNER OF PLOT FRAME IS ALGEBRAICL\
Y LARGER THAN UPPER CORNER. THIS FRAME DELETED. CARD NO. \0022a4)";
    static char fmt_1748[] = "(\002-\00215x,\002****** INCORRECT OR NO VIEW \
GIVEN IN A PLOT INSTRUCTION ----CARD NO. \0022a4,4x,\002$$$$$$$$\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define nucltp ((doublereal *)&ataptb_1 + 7)
    static doublereal pltall;
    extern /* Subroutine */ int setupp_(), printv_();

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 0, 0, fmt_1749, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_1748, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/* *********************************************************************** */
/* *********************************************************************** */
/* ...******************************************************************** */
/* *********************************************************************** */
/* ... */
/* ... THIS SECTION DETERMINES THE PLOT PARAMETERS AND SETS UP THE VIEW */
/* ... REQUESTED.IT ALSO CHECKS THE PLOT COMMAND TO SEE IF ARROWS, TOOL */
/* ... AXIS VECTORS OR PERSPECTIVE VIEWS HAVE BEEN REQUESTED. */
/* ... IF ARROW WANTED SET IARROW TO 1- NORMAL CASE 1S IARROW = 1 */
/* ... IF TOOL AXIS VECTORS WANTED SET IPL5AX T0 1- NORMAL CASE IPL5AX=0 */
/* ... IF PERSPECTIVE WANTED SET IPERSP=1***THIS FEATURE IS NOT NOW */
/* ... PROVIDED BUT THE HIGH LEVEL LOGIC IS PROVIDED */
/* ... */
/* ... IS SECTN0 PLOT FLAG SET - IF NOT THEN PRINT THE RECORD */
/* L1600: */
    if (asistm_1.iplotr <= 0) {
	goto L150;
    } else {
	goto L1602;
    }
/* ... IF IDPLOT IS 2 THEN A NESTED PLOT HAS BEEN READ-DO NOT PROCESS YET */
L1602:
    if (a3fxi1_1.idplot - a0con_1.k2 != 0) {
	goto L1604;
    } else {
	goto L150;
    }
/* ... IF IDPLOT IS LESS THAN 1 THEN PROCESS THE PLOT INSTRUCTIN. */
/* ... IF IDPLOT IS EQUAL TO 1 THEN SAVE THE INDEX AND RECORD NUMBERS. */
L1604:
    if (a3fxi1_1.idplot - a0con_1.k1 >= 0) {
	goto L1700;
    } else {
	goto L1606;
    }
/* ... IDPLOT IS 0 SO SET FLAGS */
/* ... SET IDPLOT TO 1 BECAUSE A PLOT OR OVPLOT HAS JUST BEEN READ. */
L1606:
    a3fxi1_1.idplot = a0con_1.k1;
/* ... SET FLAG TO INDICATE FIRST POINT WITHIN PLOT AREA. */
    a3fxi1_1.ifirst = a0con_1.k1;
/* ... SET THE LOW LEVEL PLOT FLAG TO ALLOW THE SUBROUTINE PLOT TO WORK. */
    a3fxi1_1.iploti = a0con_1.k1;
/* ... SAVE THE INDEX NUMBER FOR CHECKING IN THE INDEX SECTION. */
/* ... IT IS USED TO TURN PRINTING ON AND OFF WHEN NESTED PLOTS ARE USED. */
    pltall = a3fxd1_1.tapsto[a0con_1.k1 - 1];
    if (a3fxi1_1.i1 - 51 != 0) {
	goto L1605;
    } else {
	goto L1607;
    }
L1607:
    pltall = -1.;
L1605:
    a3fxi1_1.iplotx = (integer) pltall;
/* ... IF IT IS AN OVPLOT THEN SKIP THE SETUP PROCEDURE. 1042 IS OVPLOT. */
/* L1609: */
    if (a3fxi1_1.instr2 - 1042 != 0) {
	goto L1608;
    } else {
	goto L150;
    }
/* ... THE INSTRUCTION IS A PLOT - SET UP FRAME AND VIEW PARAMETERS. */
L1608:
    a3fxd1_1.pt0[a0con_1.k1 - 1] = a3fxd1_1.tapsto[a0con_1.k3 - 1];
    a3fxd1_1.pt0[a0con_1.k2 - 1] = a3fxd1_1.tapsto[a0con_1.k4 - 1];
    a3fxd1_1.pt0[a0con_1.k3 - 1] = a3fxd1_1.tapsto[a0con_1.k5 - 1];
    a3fxd1_1.ptu[a0con_1.k1 - 1] = a3fxd1_1.tapsto[a0con_1.k6 - 1];
    a3fxd1_1.ptu[a0con_1.k2 - 1] = a3fxd1_1.tapsto[a0con_1.k7 - 1];
    a3fxd1_1.ptu[a0con_1.k3 - 1] = a3fxd1_1.tapsto[a0con_1.k8 - 1];
/* ... CHECK WHAT PLANE VIEW HAS BEEN REQUESTED. */
/* ... IS IT XYPLAN.- IF IT IS GO SET IT UP.- IF NOT CHECK FOR YZPLAN. */
    if ((i__1 = a3fxi1_1.i2 - 33) < 0) {
	goto L1730;
    } else if (i__1 == 0) {
	goto L1660;
    } else {
	goto L1610;
    }
/* ... IS IT YZPLAN - IF SO SET IT UP - IF NOT CHECK FOR ZXPLAN. */
L1610:
    if (a3fxi1_1.i2 - 37 != 0) {
	goto L1611;
    } else {
	goto L1650;
    }
/* ... IS IT ZXPLAN - IF SO SET IT UP - IF NOT CHECK FOR PERSPECTIVE. */
L1611:
    if ((i__1 = a3fxi1_1.i2 - 41) < 0) {
	goto L1730;
    } else if (i__1 == 0) {
	goto L1640;
    } else {
	goto L1612;
    }
/* ... THE NEXT INSTRUCTION SHOULD TEST TAPSTO(2)  FOR THE MODIFIER PERSPC */
L1612:
    goto L1614;
/* ... SET IPERSP EQUAL TO 0 BECAUSE IT IS NOT OPERATIVE-SHOULD BE SET TO */
/* ... ONE WHEN PERSPECTIVE IS CODED. */
L1614:
    a3fxi1_1.ipersp = a0con_1.k0;
/* ... CHECK THE FRAME PARAMETERS - IF DIFFERENCES ARE ZERO THEN ERROR */
    if (a3fxd1_1.tapsto[a0con_1.k6 - 1] - a3fxd1_1.tapsto[a0con_1.k3 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1616;
    }
L1616:
    if (a3fxd1_1.tapsto[a0con_1.k7 - 1] - a3fxd1_1.tapsto[a0con_1.k4 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1618;
    }
L1618:
    if (a3fxd1_1.tapsto[a0con_1.k8 - 1] - a3fxd1_1.tapsto[a0con_1.k5 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1620;
    }
/* ... INITIALIZE FOR AN  XYPLAN VIEW */
L1620:
    a3fxi1_1.ipx = a0con_1.k1;
    a3fxi1_1.ipx = a0con_1.k2;
    a3fxd1_1.an1 = q003hl;
    a3fxd1_1.an2 = q003hl;
    goto L1670;
/* ... SET UP THE PARAMETERS FOR THE ZX PLANE VIEW-FIRST CHECK FRAME SIZE */
L1640:
    if (a3fxd1_1.tapsto[a0con_1.k6 - 1] - a3fxd1_1.tapsto[a0con_1.k3 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1642;
    }
L1642:
    if (a3fxd1_1.tapsto[a0con_1.k8 - 1] - a3fxd1_1.tapsto[a0con_1.k5 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1644;
    }
/* ... IPX AND IPY ARE SUBSCRIPTS USED TO PICK TWO OF THE 3 COORDINATES */
L1644:
    a3fxi1_1.ipx = a0con_1.k1;
    a3fxi1_1.ipy = a0con_1.k3;
/* ... THE FOLLOWING STATEMENTS ARE USED TO LABEL THE PLOT FRAME. */
    a3fxd1_1.an1 = q004hl;
    a3fxd1_1.an2 = q005hl;
/* ... GO CHECK FOR 5AXIS AND ARROWS */
    goto L1670;
/* ... CHECK THE FRAME SIZE - IF 0 OR MINUS CONSIDER AN ERROR. */
L1650:
    if (a3fxd1_1.tapsto[a0con_1.k7 - 1] - a3fxd1_1.tapsto[a0con_1.k4 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1652;
    }
L1652:
    if (a3fxd1_1.tapsto[a0con_1.k8 - 1] - a3fxd1_1.tapsto[a0con_1.k5 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1654;
    }
/* ... SET UP SUBSCRIPTS AND LABELS FOR THE YZ PLANE VIEW. */
L1654:
    a3fxi1_1.ipx = a0con_1.k2;
    a3fxi1_1.ipy = a0con_1.k3;
    a3fxd1_1.an1 = q006hl;
    a3fxd1_1.an2 = q005hl;
/* ... GO CHECK FOR 5AXIS AND ARROWS. */
    goto L1670;
/* ... CHECK THE FRAME FOR XY - IF 0 MINUS CONSIDER AN ERROR. */
L1660:
    if (a3fxd1_1.tapsto[a0con_1.k6 - 1] - a3fxd1_1.tapsto[a0con_1.k3 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1662;
    }
L1662:
    if (a3fxd1_1.tapsto[a0con_1.k7 - 1] - a3fxd1_1.tapsto[a0con_1.k4 - 1] <= 
	    0.) {
	goto L1720;
    } else {
	goto L1664;
    }
/* ... SET UP SUBSCRIPTS AND LABELS FOR THE XY PLANE VIEW. */
L1664:
    a3fxi1_1.ipx = a0con_1.k1;
    a3fxi1_1.ipy = a0con_1.k2;
    a3fxd1_1.an1 = q004hl;
    a3fxd1_1.an2 = q006hl;
/* ... IF THE NUMBER OF WORDS IN THE RECORD IS EQUAL TO OR GREATER THAN. */
/* ... 12 THEN CHECK FOR 5 AXIS AND/OR ARROW. */
/* ... IS 5AXIS AND/OR    ARROW REQUESTED */
L1670:
    if ((i__1 = a3fxi1_1.numwds - a0con_1.k9) < 0) {
	goto L1688;
    } else if (i__1 == 0) {
	goto L1676;
    } else {
	goto L1672;
    }
/* ... NUMWDS IS GREATER THAN 12 SO CHECK FOR ARROW - 0 = NO ARROW. */
L1672:
    if (a3fxd1_1.tapsto[a0con_1.k10 - 1] != 0.) {
	goto L1676;
    } else {
	goto L1674;
    }
/* ... SET ARROW FLAG FOR NO ARROW. */
L1674:
    a3fxi1_1.iarrow = a0con_1.k0;
    goto L1678;
/* ... SET ARROW FLAG FOR ARROW - TESTED IN THE ARROW SUBROUTINE. */
L1676:
    a3fxi1_1.iarrow = a0con_1.k1;
/* ... CHECK FOR 5AXIS PLOT. */
L1678:
    if (a3fxd1_1.tapsto[a0con_1.k9 - 1] != 0.) {
	goto L1680;
    } else {
	goto L1690;
    }
/* ... CHECK IF NORMAL 5AXIS OR IF WE SHOULD CHANGE THE NUMBER OF VECTORS. */
/* ... PER POINTS RECORD - NORMAL IS 10. */
L1680:
    if (a3fxd1_1.tapsto[a0con_1.k9 - 1] - (float)5. != 0.) {
	goto L1684;
    } else {
	goto L1682;
    }
/* ... SET COUNT FOR THE ITH POINT IN EACH RECORD. */
L1682:
    a3fxi1_1.ithpnt = a0con_1.k9;
    goto L1686;
L1684:
    a3fxi1_1.ithpnt = (integer) a3fxd1_1.tapsto[a0con_1.k9 - 1];
/* ... SET 5AXIS PLOT FLAG. */
L1686:
    a3fxi1_1.ipl5ax = a0con_1.k1;
    goto L1692;
/* ...    ARROW WANTED BUT NO 5 AXIS PLOT. */
L1688:
    a3fxi1_1.iarrow = a0con_1.k1;
L1690:
    a3fxi1_1.ipl5ax = a0con_1.k0;
/* ... GO SET UP THE PARAMETERS FOR THE LOWER LEVEL ROUTINES. */
L1692:
    setupp_();
    if (a3fxi1_1.iploti != 0) {
	goto L1694;
    } else {
	goto L150;
    }
/* ... LABEL THE PLOT FRAME WITH THE VIEW LABELS. */
L1694:
    printv_(&a0con_1.k6, &a3fxd1_1.an1, &c__100, &a0con_1.k10);
    printv_(&a0con_1.k6, &a3fxd1_1.an2, &a0con_1.k10, &c__100);
/* ... PARAMETERS ARE ALL SET FOR PLOTTING - GO PRINT THE RECORD. */
    goto L150;
/* ... A NESTED PLOT HAS BEEN FOUND -SET IDPLOT AND SAVE THE RECORD NUMBER */
L1700:
    a3fxi1_1.idplot = a0con_1.k2;
    a3fxi1_1.idplsq = a3fxi1_1.irecno;
/* ... RETURN TO PRINT THIS RECORD. */
    goto L150;
/* ... ERROR COMMENT AREA */
L1720:
    io___7.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___7);
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
/* ... SET IPLOTI SO THIS FRAME WILL NOT BE PLOTTED. */
L1725:
    a3fxi1_1.iploti = a0con_1.k0;
/* ... GO PRINT THIS RECORD. */
    goto L150;
L1730:
    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    do_fio(&c__1, (char *)&a3fxd1_1.seqno[a0con_1.k1 - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
    goto L1725;
L150:
    return 0;
} /* pltset_ */

#undef nucltp
#undef q006hl
#undef q005hl
#undef q004hl
#undef q003hl


