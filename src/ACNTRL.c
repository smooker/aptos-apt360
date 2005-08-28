/* ACNTRL.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include <config.h>

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
static integer c__2 = 2;

/* Subroutine */ int acntrl_()
{
    /* Format strings */
    static char fmt_9003[] = "(////,42x,\002ELAPSED TIME IS \002,f12.5,1x\
,\002MINUTES\002/\0020\002,70x)";
    static char fmt_9400[] = "(9x,\002APT SECTION 0 ERROR COMMENT\002/x,\002\
CLTAPE COULD NOT BE POSITIONED TO RECORD NO. (\002,i6,\002) FOR ABOVE PART P\
ROGRAM\002/\002 NUMBER OF RECORDS ON CLTAPE IS \002,i6)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, iret, isect;
    static doublereal clock1;
    extern /* Subroutine */ int a2ctrl_(), sectn3_(), tapech_(), search_(), 
	    inital_(), artime_(), bufftp_(), ascntl_();
#define iclprt ((integer *)&asistm_1 + 10)
#define indexx ((integer *)&asistm_1 + 11)
    extern /* Subroutine */ int aptpos_();
#define iplotr ((integer *)&asistm_1 + 12)

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, fmt_9003, 0 };
    static cilist io___9 = { 0, 0, 0, fmt_9400, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*     *          *          *          *          *          * */
/*     *          *          *          *          *          * */
/*     SECTION ZERO NAMED COMMON */
/*     *          *          *          *          *          * */
/*     *          *          *          *          *          * */
/*     END OF SECTION ZERO COMMON AND EQUIVALENCE STATEMENTS */
/*     *          *          *          *          *          * */

/* 9000 IS THIS A NEW PART PROGRAM */
L9000:
    if (asistm_1.kflags[5] == a0con_1.iblank) {
	goto L9002;
    }

/*  Initialize: set globals to zero, print out time */
L9001:
    inital_();
/*     GET SECTION 1 */
/* 	parse, calculate canon forms */
    isect = 1;
    goto L9510;

/* ...     OBTAIN AND PRINT ELAPSED TIME IN LAST SECTION */
L9002:
    clock1 = atime_1.fltime;
    artime_();
    clock1 = atime_1.fltime - clock1;
    io___6.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___6);
    do_fio(&c__1, (char *)&clock1, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* ...     IF IWAVEN = 0, NO ERROR. IF IT = 1, ERRORS IN ONE OF */
/* ...     SECTIONS 1, 3, OR 4. IF IT = 2, SECTION 2 ERRORS FOUND */
    if ((i__1 = asistm_1.iwaven - 1) < 0) {
	goto L9200;
    } else if (i__1 == 0) {
	exit(1);
//	goto L9001;
    } else {
	goto L9100;
    }

/* ...     SECTION 2 ERRORS FOUND - SEE IF AN AUXILIARY SEC. 2 IS TO */
/* ...     BE EXECUTED */
L9100:
    if (asistm_1.ltvmit == 0) {
	goto L9110;
    }

/* ...     AUXILIARY SECTION 2 DESIRED - SET FLAGS FOR IT */
    asistm_1.kflags[2] = 1;
    asistm_1.ltvmit = 0;
    goto L9114;

/* 9110 NO AUXILIARY SECTION 2 TO BE EXECUTED. DO NOT POST PROCESS. */
L9110:
    asistm_1.kflags[4] = 0;
    asistm_1.kflags[2] = 0;
/* 9114 HAS CLPRNT/ON OR /OFF BEEN REQUESTED */
L9114:
    if (*iclprt != 0) {
	goto L9116;
    } else {
	goto L9115;
    }
/* ...     TURN ON CLFILE PRINT FLAG */
L9115:
    *iclprt = 1;
L9116:
    isect = 4;
    goto L9530;

/* ...     IF SECTION 1 JUST PROCESSED, ADJUST FLAGS AS NECESSARY FOR */
/* ...     LATER SECTIONS */
L9200:
    if (isect > 1) {
	goto L9450;
    }

/* ...     CHECK FLAGS FOR POSSIBLE SECTION 3 PROCESSING */
    if (asistm_1.noplot != 0) {
	goto L9302;
    } else {
	goto L9303;
    }
/* 9302 VOID PLOTTING */
L9302:
    *iplotr = 0;
/* ...     CHECK PLOT, CLPRNT, AND COPY */
L9303:
    for (i__ = 1; i__ <= 3; ++i__) {
	if (asistm_1.is3[i__ - 1] == 0) {
	    goto L9310;
	}
/* 9305 TURN ON SECTION 3 PROCESSING */
/* L9305: */
	asistm_1.kflags[3] = 1;
L9310:
	;
    }
    if (asistm_1.itrcut != 0) {
	goto L9315;
    } else {
	goto L9320;
    }
L9315:
    asistm_1.kflags[3] = 1;
/* ...     SEE IF SECTION 4 IS TO BE PROCESSED */
L9320:
    if (asistm_1.nopost != 0) {
	goto L9325;
    } else {
	goto L9326;
    }
/* 9325 NO EXECUTION OF SECTION 4 */
L9325:
    asistm_1.kflags[4] = 0;

/* 9326 CHECK PTONLY/N PROCESSING */
/*     IPTNLY=0 NORMAL */
/*     IPTNLY=1 SKIP SECTION 2 AND EXCHANGE DATASETS */
/*     IPTNLY=2 SKIP SECTION 2 AND DO NOT EXCHANGE DATASETS */
/*     IPTNLY=3 DO NOT SKIP SECTION 2.POSITION CLTAPE AT */
/*              RECORD NO. NCLREC */
/*     *          *          *          *          *          * */
L9326:
    i__ = asistm_1.iptnly + 1;
    switch ((int)i__) {
	case 1:  goto L9450;
	case 2:  goto L9360;
	case 3:  goto L9370;
	case 4:  goto L9380;
    }
L9360:
    tapech_(&ataptb_1.protap, &ataptb_1.cltape);
    tapech_(&ataptb_1.protap, &ataptb_1.tapes2);
/*     TURN OFF SECTION 2 PROCESSING */
L9370:
    asistm_1.kflags[1] = 0;
    asistm_1.kflags[2] = 0;
    goto L9450;
L9380:
    bufftp_(&ataptb_1.cltape, &c__2);
    search_(&ataptb_1.cltape, &asistm_1.nclrec, &iret);
    asistm_1.iptnly = -asistm_1.nclrec;
    if (iret < 0) {
	goto L9450;
    }
/* 9390 SECTION ZERO ERROR COMMENT */
/* L9390: */
    --iret;
    io___9.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___9);
    do_fio(&c__1, (char *)&asistm_1.nclrec, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iret, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L9001;

/* ...     CLEAR FLAG FOR SECTION JUST EXECUTED, AND MOVE INDICATOR */
/* ...     PAST IT */
L9450:
    asistm_1.kflags[isect - 1] = 0;
    ++isect;
/* ...     SEARCH FOR NEXT SECTION TO BE EXECUTED */
    for (i__ = isect; i__ <= 5; ++i__) {
	if (asistm_1.kflags[i__ - 1] == 1) {
	    goto L9500;
	}
/* L9460: */
    }
/* ...     PROCESSING COMPLETE FOR THIS PART PROGRAM */
	exit(0);
    goto L9001;


/* ...     NEXT SECTION TO BE EXECUTED FOUND - SAVE THE INDICATOR, AND */
/* ...     BRANCH TO OBTAIN THE DESIRED SECTION */
L9500:
    isect = i__;
    switch ((int)isect) {
	case 1:  goto L9510;
	case 2:  goto L9520;
	case 3:  goto L9525;
	case 4:  goto L9530;
	case 5:  goto L9540;
    }

/* ...     GET SECTION 1 */
/* 	parse, set canon forms */
L9510:
    ascntl_();
/* 	print out time, errors, etc. goto the next section: */
    goto L9000;

/* 	same as above, only for sec. 2 */
/* ...     GET STANDARD SECTION 2 */
/* 	cut vectors, tool motion: */
L9520:
	//finish the dxf file, if any
#ifdef HAVE_DXFLIB_DL_DXF_H 
	export_surf_end();
#endif
    a2ctrl_();
/* 	print out time, errors, etc. goto the next section: */
    goto L9000;

/* ...     GET AUXILIARY SECTION 2... */

/* ...     TURN ON FLAG FOR SECTION 3 TO RECOGNIZE AUXILIARY PRINT */
L9525:
    asistm_1.kflags[6] = 1;
/* ...     CALL STATEMENT TO ENTRY NAME FOR AUX. SEC. 2 GOES HERE */
/* ...     THE NEXT CARD SHOULD BE - */
/* ...     GO TO 9000 */
    goto L9520;

/* ...     GET SECTION 3 */
L9530:
    sectn3_();
/* 	print out time, errors, etc. goto the next section: */
    goto L9000;

/* ...     GET SECTION 4 */
L9540:
    aptpos_();
/* 	print out time, errors, etc. goto the next section: */
    goto L9000;

} /* acntrl_ */

#undef iplotr
#undef indexx
#undef iclprt


