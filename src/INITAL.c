/* INITAL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal fltime, date, clock[2];
} atime_;

#define atime_1 atime_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, is3[3], kflags[9];
} asistm_;

#define asistm_1 asistm_

struct {
    doublereal ppname[20];
} apostp_;

#define apostp_1 apostp_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int inital_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_7 = { {'B', 'E', 'N', 'D', 'I', 'X', ' ', ' '}, 0. };

#define inname__ (*(doublereal *)&equiv_7)


    /* Format strings */
    static char fmt_30[] = "(\0021\002,6x,\002N/C 360 APT VERSION 4, MODIFIC\
ATION 4\002,5x,\002DATE= \002,a8,\002 TIME OF DAY IN HRS./MIN./SEC IS \002,a\
8,a3////)";

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer iret, i__;
#define ia ((integer *)&asistm_1)
#define ip ((integer *)&apostp_1)
    extern /* Subroutine */ int afresh_(), artime_(), tapeop_();

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_30, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 4 *** */

/*     *          *          *          *          *          * */
/*     SECTION ZERO TYPE STATEMENTS */
/*     *          *          *          *          *          * */
/*     SECTION ZERO NAMED COMMON */
/*     *          *          *          *          *          * */
/*     *          *          *          *          *          * */
/*     END OF SECTION ZERO COMMON AND EQUIVALENCE STATEMENTS */
/*     *          *          *          *          *          * */
/*     REWIND UTILITY DATASETS */
    afresh_();
    tapeop_(&ataptb_1.protap, &c__1, &iret);
    tapeop_(&ataptb_1.cltape, &c__1, &iret);
    tapeop_(&ataptb_1.poctap, &c__1, &iret);
    tapeop_(&ataptb_1.srftap, &c__1, &iret);
    tapeop_(&ataptb_1.tapes4, &c__1, &iret);
    //afresh_();originally here
/*     ZERO SYSTEM COMMON */
    for (i__ = 1; i__ <= 22; ++i__) {
	ia[i__ - 1] = 0;
/* L10: */
    }
    for (i__ = 1; i__ <= 40; ++i__) {
	ip[OTHER_ENDIAN_S(i__ - 1)] = a0con_1.iblank;
/* L20: */
    }
    asistm_1.kflags[5] = a0con_1.iblank;
/*     TURN ON SECTION 1 */
    asistm_1.kflags[0] = a0con_1.k1;
/*     TURN ON SECTION 2 */
    asistm_1.kflags[1] = a0con_1.k1;
/*     TURN ON SECTION 4 */
    asistm_1.kflags[4] = a0con_1.k1;
    asistm_1.numptr = a0con_1.k1;
    asistm_1.numpst = a0con_1.k0;
    apostp_1.ppname[0] = inname__;
    artime_();
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    do_fio(&c__1, (char *)&atime_1.date, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atime_1.clock[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&atime_1.clock[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
/* 	original format: */
/*     1A6,' TIME OF DAY IN HRS./MIN./SEC IS ',A8,A3 ////) */
    return 0;
} /* inital_ */

#undef ip
#undef ia
#undef inname__


