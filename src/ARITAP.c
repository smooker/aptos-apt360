/* ARITAP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

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
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
	    numpst, numptr, iclprt, indexx, iplotr, kflags[9];
} asistm_;

#define asistm_1 asistm_

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

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;

/* Subroutine */ int aritap_()
{
    /* Initialized data */

    static integer i379 = 0;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer n, ij, ik, il, iret, nwds, inher2;
#define errtap ((doublereal *)&ataptb_1 + 9)
#define jprotp ((integer *)&aprotp_1)
#define jprosv ((integer *)&aprotp_1 + 204)
    extern /* Subroutine */ int atapwt_();
    static integer inhere;
    extern /* Subroutine */ int atapop_(), ataprd_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/* **** THIS ROUTINE WRITES A RECORD ON THE PROTAP. THE PROTP TABLE */
/*     CONTAINS THE DATA TO BE WRITTEN. */
/*     PROTP(1) CONTAINS NUMBER OF PARAMETERS TO BE WRITTEN. */
/* **** IRECN CONTAINS RECORD NO. */

/* ...     SEE IF RECORD IS TO BE WRITTEN ON PROTAP NOW */
    if (aprotp_1.jgorit <= 0) {
	goto L2;
    } else {
	goto L4;
    }

/* ...     YES - OUTPUT IT */
L2:
    i__1 = jprotp[OTHER_ENDIAN_S(1)] - 1;
    atapwt_(&ataptb_1.protap, &iret, &c__4, &a1pas2_1.irecn, &c__1, &jprotp[OTHER_ENDIAN_S(2)]
	    , &c__1, &jprotp[OTHER_ENDIAN_S(3)], &c__1, &aprotp_1.protp[2], &i__1);
/* ...     UPDATE PROTAP RECORD NUMBER */
    ++a1pas2_1.irecn;
/* ...     WAS THERE AN I/O ERROR */
    if (iret >= 0) {
	goto L150;
    }
    if (aprotp_1.jgorit >= 0) {
	goto L200;
    } else {
	goto L60;
    }

/* ...     NO - STORING RECORDS UNTIL IMPLICIT CHECK SURFACE */
/* ...     FOUND - INCREMENT COUNT OF RECORDS SAVED */
L4:
    ++aprotp_1.nowclt;

/* ...     TEST FOR STORING RECORDS IN CORE */
/* L6: */
    if (aprotp_1.incore != 0) {
	goto L30;
    }

/* ...     YES - TEST FOR ENOUGH SPACE FOR THIS RECORD */
    n = jprotp[OTHER_ENDIAN_S(1)] + 2;
    if (aprotp_1.lstpsv + n > 100) {
	goto L25;
    }

/* ...     YES - STORE IT AWAY */
    jprotp[OTHER_ENDIAN_S(0)] = n;
    i__1 = n;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	++aprotp_1.lstpsv;
/* L20: */
	aprotp_1.prosav[aprotp_1.lstpsv - 1] = aprotp_1.protp[a1pas2_1.i__ - 
		1];
    }
    goto L200;

/* ...  NO MORE ROOM TO STORE RECORDS IN CORE - USE ERRTAP */
L25:
    aprotp_1.incore = 1;
    inhere = 1;
    if (asistm_1.iwaven != 0) {
	goto L200;
    }
    atapop_(errtap, &c__1, &iret);
    if (iret >= 0) {
	goto L150;
    }
    a1pas2_1.k = aprotp_1.nowclt - 1;
/* ...     WRITE OUT RECORDS SAVED IN CORE ONTO ERRTAP */
    i__1 = a1pas2_1.k;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	inher2 = (inhere << 1) - 1;
	n = jprosv[OTHER_ENDIAN_S(inher2 - 1)];
	i__2 = jprosv[OTHER_ENDIAN_S(inher2)] - 1;
	atapwt_(errtap, &iret, &c__4, &a1pas2_1.i__, &c__1, &jprosv[OTHER_ENDIAN_S(inher2 + 
		1)], &c__1, &jprosv[OTHER_ENDIAN_S(inher2 + 2)], &c__1, &aprotp_1.prosav[
		inhere + 1], &i__2);
	if (iret >= 0) {
	    goto L150;
	}
/* L27: */
	inhere += n;
    }
/* ...     NOW GO TO SAVE LATEST RECORD */

/* ...     WRITE LATEST RECORD TO BE SAVED ON ERRTAP */
L30:
    if (asistm_1.iwaven != 0) {
	goto L200;
    }
    i__1 = jprotp[OTHER_ENDIAN_S(1)] - 1;
    atapwt_(errtap, &iret, &c__4, &aprotp_1.nowclt, &c__1, &jprotp[OTHER_ENDIAN_S(2)], &c__1, 
	    &jprotp[OTHER_ENDIAN_S(3)], &c__1, &aprotp_1.protp[2], &i__1);
/*     WAS THERE AN ERROR */
/* L40: */
    if (iret >= 0) {
	goto L150;
    }
    goto L200;

/* ...     NO - RETRIEVE SAVED PROTAP RECORDS, WRITE THEM OUT */

/* ...     ARE THEY ON THE ERROR FILE */
L60:
    if (aprotp_1.incore != 0) {
	goto L80;
    }

/* ...     NO - WRITE THEM OUT FROM CORE AREA */
    inhere = 1;
    i__1 = aprotp_1.nowclt;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	inher2 = (inhere << 1) - 1;
	n = jprosv[OTHER_ENDIAN_S(inher2 - 1)];
	i__2 = jprosv[OTHER_ENDIAN_S(inher2)] - 1;
	atapwt_(&ataptb_1.protap, &iret, &c__4, &a1pas2_1.irecn, &c__1, &
		jprosv[OTHER_ENDIAN_S(inher2 + 1)], &c__1, &jprosv[OTHER_ENDIAN_S(inher2 + 2)], &c__1, &
		aprotp_1.prosav[inhere + 1], &i__2);
	++a1pas2_1.irecn;
	if (iret >= 0) {
	    goto L150;
	}
/* L70: */
	inhere += n;
    }
    aprotp_1.lstpsv = 0;
    goto L200;

/* ...     SAVED PROTAP RECORDS SUPPOSED TO BE ON ERROR FILE */
/* ...     HAVE THERE BEEN ANY ERRORS */
L80:
    if (asistm_1.iwaven != 0) {
	goto L200;
    }

/* ...     NO - REWIND FILE, RETRIEVE RECORDS, WRITE ON PROTAP */
    atapop_(errtap, &c__1, &iret);
    if (iret >= 0) {
	goto L150;
    }

    i__1 = aprotp_1.nowclt;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	ataprd_(errtap, &iret, &nwds, &c__4, &ij, &c__1, &ik, &c__1, &il, &
		c__1, aprotp_1.protp, &c__0);
	if (iret >= 0) {
	    goto L150;
	}
	atapwt_(&ataptb_1.protap, &iret, &c__4, &a1pas2_1.irecn, &c__1, &ik, &
		c__1, &il, &c__1, aprotp_1.protp, &nwds);
	++a1pas2_1.irecn;
	if (iret >= 0) {
	    goto L150;
	}
/* L100: */
    }
    goto L200;

L150:
    a1com_1.jsuber = 302;
L200:
    if (i379 != 0) {
	return 0;
    }
    if (a1pas2_1.irecn <= 65365) {
	return 0;
    }
    a1com_1.jsuber = 379;
    i379 = 1;
    return 0;
} /* aritap_ */

#undef jprosv
#undef jprotp
#undef errtap


