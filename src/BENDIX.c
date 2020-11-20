/* BENDIX.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal fltime, date, clock[2];
} atime_;

#define atime_1 atime_

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

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__23 = 23;
static integer c__6 = 6;
static integer c__18 = 18;
static integer c__20 = 20;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__24 = 24;
static integer c__7 = 7;
static integer c__4 = 4;

/* Subroutine */ int bendix_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_49 = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, 0. };

#define literl (*(doublereal *)&equiv_49)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_50 = { {'T', 'E', 'S', 'T', ' ', 'F', ' ', ' ', 'O', 'R', ' ',
		 'P', 'A', 'R', ' ', ' ', 'N', 'O', 'M', '-', '-', '-', ' ', 
		' '}, 0. };

#define par ((doublereal *)&equiv_50)

    static struct {
	char e_1[4];
	integer e_2;
	} equiv_51 = { {'T', 'E', 'S', 'T'}, 0 };

#define itest (*(integer *)&equiv_51)

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_52 = { {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
		 'B', 'C', 'D', 'E', 'F', ' ', ' ', ' ', ' ', 'X', 'Y', 'Z', 
		'$'}, 0. };

#define punch ((doublereal *)&equiv_52)


    /* Format strings */
    static char fmt_101[] = "(\0021\002,\002PROCESSING HAS REACHED CONNECTOR\
 100\002)";
    static char fmt_105[] = "(//10x,\002OXCODE SHOULD = MCHTOL0SEQNOAUXFUNCO\
OLNTSPINDLPPRINTPARTNOPREFUN0CLAMP0TMARKREWINDFEDRATLEADERTURRETMACHIN\002)";
    static char fmt_110[] = "(/10x,\002OXCODE DOES   = \002,23a4)";
    static char fmt_115[] = "(/10x,\002XCODE  SHOULD = 000END00STOP0PENUPPEN\
DWN\002)";
    static char fmt_120[] = "(/10x,\002XCODE  DOES   = \002,6a4)";
    static char fmt_201[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 20\
0\002)";
    static char fmt_205[] = "(/10x,\002LITERAL VALUE  = \002,a8)";
    static char fmt_301[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 30\
0\002)";
    static char fmt_305[] = "(\002 THE MODULE 'CLSETP' HAS BEEN CALLED WITH \
THE FOLLOWING FORMAT- CALL CLSETP(CLTAPE,XCODE(1),6,OXCODE(1),23)\002)";
    static char fmt_401[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 40\
0\002)";
    static char fmt_405[] = "(/1x,\002AN ATTEMPT IS NOW MADE TO READ AND PRI\
NT THE C.L.TAPE. THIS WILL CONTINUE UNTILL A ''FINI'' IS ENCOUNTERED.\002)";
    static char fmt_415[] = "(1x,\002CLDATA,TYPE OF RECORD AND SUBTYPE ARE P\
RINTED AS 4 BYTE INTEGERS THE FIRST THREE WORDS OF 'CLDATA' ARE PRINTED IN H\
EX\002.,//)";
    static char fmt_421[] = "(1x,\002CLID = \002,i4,\002 NOWRDS = \002,i4\
,\002 TYPE = \002,i4,\002 SUBTYP = \002,i4,\002 CLDATA = \002,3z16)";
    static char fmt_427[] = "(1x,\002CLID = \002,i4,\002 NOWRDS = \002,i4\
,\002 TYPE = \002,i4,\002 SUBTYP = \002,i4)";
    static char fmt_429[] = "(20x,\002X = \002,f10.4,8x,\002Y = \002,f10.4,8\
x,\002Z = \002,f10.4)";
    static char fmt_501[] = "(//\002 PROCESSING HAS REACHED CONNECTOR 500\
\002)";
    static char fmt_505[] = "(10x,\002PARNOM HAS BEEN CALLED., PUNCHOUT SHOU\
LD BE 18 CHARACTERS INCLUDING BLANKS  (TEST FOR PARNOM---)\002)";
    static char fmt_601[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 60\
0\002)";
    static char fmt_605[] = "(1x,\002NNTAIN IS TESTED AS  IF(NNTAIN(A,X,B)) \
1,2,3 -------RESULTS ARE AS FOLLOWS\002)";
    static char fmt_611[] = "(50x,f6.2,\002 IS NOT BOUNDED BY \002,f5.2,\002\
 AND \002,f5.2)";
    static char fmt_621[] = "(50x,\002 STATES THAT \002,f5.2,\002 AND \002,f\
5.2,\002 ARE EQUAL \002)";
    static char fmt_631[] = "(50x,f6.2,\002 IS --- BOUNDED BY \002,f5.2,\002\
 AND \002,f5.2)";
    static char fmt_801[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 80\
0\002)";
    static char fmt_806[] = "(1x,\002PUNCHA HAS BEEN TESTED, CHECK CARD OUTP\
UT, SHOULD BE AS FOLLOWS '0123456789ABCDEFXYZ'.\002)";
    static char fmt_901[] = "(///\002 PROCESSING HAS REACHED CONNECTOR 90\
0\002)";
    static char fmt_905[] = "(1x,\002CONBCD HAS BEEN TESTED., SHOULD BE( 123\
4568), IS(\002,a8,\002)\002)";
    static char fmt_1000[] = "(10x,\002EXECUTION IS COMPLETE., SUPERNUMERARY\
 INSTRUCTION\rARE DELETED., ANIMADVERT IS NOT REQUIRED.....\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer clid;
    extern /* Subroutine */ int init_();
    static doublereal conv;
    static integer type__;
    static doublereal a, b;
    static integer i__, j, k;
    static doublereal x;
    static integer xcode[6];
    extern /* Subroutine */ int shift_();
    static doublereal conto, seqno;
    static integer ij;
    static doublereal cldata[256];
    extern /* Subroutine */ int conbcd_(), clread_(), puncha_();
    static integer oxcode[23];
    extern /* Subroutine */ int dispat_(), bufftp_(), tapeop_(), clsetp_(), 
	    parnom_(), punidn_();
    extern integer nntain_();
    static integer nowrds;
    extern /* Subroutine */ int punseq_();
    static integer subtyp;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___5 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___6 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___8 = { 0, 0, 0, fmt_115, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___10 = { 0, 0, 0, fmt_201, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_205, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_401, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_405, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_415, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_421, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_427, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_429, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_501, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_505, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_601, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_605, 0 };
    static cilist io___38 = { 0, 0, 0, fmt_611, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_621, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_631, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_801, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_806, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_901, 0 };
    static cilist io___47 = { 0, 0, 0, fmt_905, 0 };
    static cilist io___48 = { 0, 0, 0, fmt_1000, 0 };


/*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */

/*          A BLOCK OF NAMES AND VALUES FOR INTER-PROGRAM USE */
/*        APT SECTION-0 COMMON */



/*     D U M M Y   P O S T P R O C E S S O R   T O   T E S T   T H E */

/*     S / 3 6 0   A P T   S Y S T E M */






    bufftp_(&ataptb_1.cltape, &c__2);
    tapeop_(&ataptb_1.cltape, &c__1, &ij);




/* L100: */
    io___2.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___2);
    e_wsfe();

    init_(oxcode, "MCHTOL0SEQNOAUXFUNCOOLNTSPINDLPPRINTPARTNOPREFUN0CLAMP0TM\
ARKREWINDFEDRATLEADERTURRETMACHIN  ", &c__23, (ftnlen)92);
    init_(xcode, "000END00STOP0PENUPPENDWN", &c__6, (ftnlen)24);

    io___5.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___5);
    e_wsfe();

    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    for (i__ = 1; i__ <= 23; ++i__) {
	do_fio(&c__1, (char *)&oxcode[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();

    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    e_wsfe();

    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    for (i__ = 1; i__ <= 6; ++i__) {
	do_fio(&c__1, (char *)&xcode[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();


/*     END OF TESTING FOR POSTPROCESSOR MODULE   I N I T     ************ */



/* L200: */
    io___10.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___10);
    e_wsfe();


    for (i__ = 1; i__ <= 9; ++i__) {
	io___12.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___12);
	do_fio(&c__1, (char *)&literl, (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L210: */
	shift_(&literl, &c__1);
    }



/*     END OF TESTING FOR POSTPROCESSOR MODULE   S H I F T   ************ */



/* L300: */
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    e_wsfe();



    clsetp_(&ataptb_1.cltape, xcode, &c__6, oxcode, &c__23);
    io___14.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___14);
    e_wsfe();


/*     END OF TESTING FOR POSTPROCESSOR MODULE   C L S E T P ************ */



/* L400: */
    io___15.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___15);
    e_wsfe();



    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    e_wsfe();
/*     WRITE (IOUTAP,410) */
/* L410: */
//    io___17.ciunit = ataptb_1.ioutap;
 //   s_wsfe(&io___17);
  //  e_wsfe();


L420:
    clread_(&clid, &nowrds, cldata, &type__, &subtyp);
    if (type__ == 3) {
	goto L426;
    }

/*      WRITE (IOUTAP,421) (CLID,NOWRDS,TYPE,SUBTYP,(CLDATA(I),I=1,3)) */
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
//added code:
    do_fio(&c__1, (char *)&clid, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nowrds, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&type__, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&subtyp, (ftnlen)sizeof(integer));


    j = 1;
    k = nowrds+2;
    i__1 = k;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cldata[i__ - 1], (ftnlen)sizeof(doublereal));
    }


//end added code
    e_wsfe();
    goto L430;

L426:
    io___24.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___24);
    do_fio(&c__1, (char *)&clid, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nowrds, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&type__, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&subtyp, (ftnlen)sizeof(integer));
    e_wsfe();
    j = 1;
    k = 3;
L428:
    io___27.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___27);
    i__1 = k;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&cldata[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (j + 2 == nowrds) {
	goto L430;
    }
    j += 3;
    k = j + 2;
    goto L428;

L430:
    if (type__ != 4) {
	goto L420;
    }



/*     END OF TESTING FOR POSTPROCESSOR MODULE   C L R E A D  *********** */

/* L500: */
    io___28.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___28);
    e_wsfe();


    punidn_(&itest);
    seqno = 69.;
    punseq_(&seqno);
    parnom_(&c__18, par);
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    e_wsfe();



/*     END OF TESTING FOR POSTPROCESSOR MODULE   P A R N O M ************ */
/* L600: */
    io___33.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___33);
    e_wsfe();



    io___34.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___34);
    e_wsfe();

    a = (float)-5.;
    b = (float)5.;
    x = (float)-10.;

L606:
    if ((i__1 = nntain_(&a, &x, &b)) < 0) {
	goto L610;
    } else if (i__1 == 0) {
	goto L620;
    } else {
	goto L630;
    }

L610:
    io___38.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___38);
    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L650;

L620:
    io___39.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___39);
    do_fio(&c__1, (char *)&a, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L700;

L630:
    io___40.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___40);
    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&b, (ftnlen)sizeof(doublereal));
    e_wsfe();


L650:
    x += (float)1.;

    if (x - (float)10. <= 0.) {
	goto L606;
    } else {
	goto L700;
    }

L700:



/*     END OF TESTING FOR POSTPROCESSOR MODULE   N N T A I N  *********** */



/* L800: */
    io___41.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___41);
    e_wsfe();



    puncha_(&c__20, punch, &c_n1, &c__0);
    puncha_(&c__24, punch, &c__2, &c__0);
    puncha_(&c__24, punch, &c__1, &c__0);
/* L805: */
    io___43.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___43);
    e_wsfe();


/*     END OF TESTING FOR POSTPROCESSOR MODULE P U N C H A  ************* */

/* L900: */
    io___44.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___44);
    e_wsfe();


    conv = (float)123.456789;
    conto = (float)0.;

    conbcd_(&conv, &conto, &c__7, &c__4, &c__2);

    io___47.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___47);
    do_fio(&c__1, (char *)&conto, (ftnlen)sizeof(doublereal));
    e_wsfe();


/*     END OF TESTING FOR POSTPROCESSOR MODULE C O N B C D ************** */


    io___48.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___48);
    e_wsfe();



    tapeop_(&ataptb_1.cltape, &c__1, &ij);
    dispat_();
    return 0;

} /* bendix_ */

#undef punch
#undef itest
#undef par
#undef literl


/* Subroutine */ int burg_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002BURG WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___53 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___53);
    e_wsfe();
    dispat_();
    return 0;
} /* burg_ */

/* Subroutine */ int cincy_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002CINCY WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___54 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___54);
    e_wsfe();
    dispat_();
    return 0;
} /* cincy_ */

/* Subroutine */ int concrd_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002CONCRD WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___55 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___55);
    e_wsfe();
    dispat_();
    return 0;
} /* concrd_ */

/* Subroutine */ int dvlieg_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002DVLIEG WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___56 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___56);
    e_wsfe();
    dispat_();
    return 0;
} /* dvlieg_ */

/* Subroutine */ int dynpat_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002DYNPAT WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___57 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___57);
    e_wsfe();
    dispat_();
    return 0;
} /* dynpat_ */

/* Subroutine */ int ecs_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002ECS WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___58 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___58);
    e_wsfe();
    dispat_();
    return 0;
} /* ecs_ */

/* Subroutine */ int expost_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002EXPOST WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___59 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___59);
    e_wsfe();
    dispat_();
    return 0;
} /* expost_ */

/* Subroutine */ int fosdik_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002FOSDIK WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___60 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___60);
    e_wsfe();
    dispat_();
    return 0;
} /* fosdik_ */

/* Subroutine */ int gecent_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002GECENT WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___61 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___61);
    e_wsfe();
    dispat_();
    return 0;
} /* gecent_ */

/* Subroutine */ int milwak_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002MILWAK WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___62 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___62);
    e_wsfe();
    dispat_();
    return 0;
} /* milwak_ */

/* Subroutine */ int bencd_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002BENCD WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___63 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___63);
    e_wsfe();
    dispat_();
    return 0;
} /* bencd_ */

/* Subroutine */ int prattw_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002PRATTW WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___64 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___64);
    e_wsfe();
    dispat_();
    return 0;
} /* prattw_ */

/* Subroutine */ int probog_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002PROBOG WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___65 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___65);
    e_wsfe();
    dispat_();
    return 0;
} /* probog_ */

/* Subroutine */ int ptw4e_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002PTW4E WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___66 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___66);
    e_wsfe();
    dispat_();
    return 0;
} /* ptw4e_ */

/* Subroutine */ int sc4020_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002SC4020 WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___67 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___67);
    e_wsfe();
    dispat_();
    return 0;
} /* sc4020_ */

/* Subroutine */ int seczro_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002SECZRO WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___68 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___68);
    e_wsfe();
    dispat_();
    return 0;
} /* seczro_ */

/* Subroutine */ int suntrn_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002SUNTRN WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___69 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___69);
    e_wsfe();
    dispat_();
    return 0;
} /* suntrn_ */

/* Subroutine */ int trutra_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002TRUTRA WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___70 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___70);
    e_wsfe();
    dispat_();
    return 0;
} /* trutra_ */

/* Subroutine */ int trw_()
{
    /* Format strings */
    static char fmt_1[] = "(x,\002TRW WAS CALLED\002)";

    /* Builtin functions */
    integer s_wsfe(), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int dispat_();

    /* Fortran I/O blocks */
    static cilist io___71 = { 0, 6, 0, fmt_1, 0 };


    s_wsfe(&io___71);
    e_wsfe();
    dispat_();
    return 0;
} /* trw_ */

