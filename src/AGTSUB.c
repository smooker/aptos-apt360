/* AGTSUB.f -- translated by f2c (version 20000121).
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
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

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

/* Subroutine */ int agtsub_()
{
    /* Format strings */
    static char fmt_500[] = "(\0020 AGTSUB\002,z20)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer ik, iv, ktm;
#define karg ((shortint *)&ascalr_1 + 726)
    static doublereal adum;
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
#define canon ((doublereal *)&avst_1)
    static integer ivtem;
#define iptpp ((integer *)&avst_1)
    static integer jtemp1;
#define icanon ((integer *)&avst_1)
#define kargpn ((shortint *)&ascalr_1 + 727)
#define knclus ((shortint *)&ascalr_1 + 726)
    static integer kindxp, locsub;

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 6, 0, fmt_500, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* **** THIS ROUTINE OBTAINS THE SUBSCRIPT VALUE FOR A VARIABLE. THE PTPP */
/*     INDEX,THE VARIABLE INDXPT, AND THE VARIABLE NAMSUB ARE THE INPUT. */
/*     NAMSUB=0,1,2, OR 3. */
/*     =0, NO SUBSCRIPT. */
/*     =1, SUBSCRIPT IS FLOATING POINT VARIABLE LOCATED IN PTPP(INDXPT+1) */
/*     =2, THE FIRST 4 BYTES OF PTPP(INDXPT)   CONTAIN THE VST INDEX OF */
/*        THE SUBSCRIPT. */
/*     =3, THE HIGH ORDER 4 BYTES OF PTPP(INDXPT)   CONTAIN THE SCALR */
/*        TABLE INDEX OF THE SUBSCRIPT. */
/*     NAMSUB IS SET EQUAL TO THE SUBSCRIPT VALUE AND INDXPT IS UPDATED. */
/* *******                    ****       ****                      ******* */

/* ...     SEE WHETHER OR NOT WE HAVE A SUBSCRIPT */
    if (a1com_1.namsub == 0) {
	goto L140;
    }

    kindxp = (a1com_1.indxpt << 1) - 1;
/* ...     GET INDEX TO SUBSCRIPT LOCATION FOR ALL BUT NUMERIC SUBSCRIPT */
    a1pas2_1.k = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
/*       GET VST INDEX OF SYMBOL BEING SUBSCRIPTED */
    iv = iptpp[OTHER_ENDIAN_S(kindxp)];
    switch ((int)a1com_1.namsub) {
	case 1:  goto L20;
	case 2:  goto L40;
	case 3:  goto L30;
	case 4:  goto L60;
    }

/*  20 SUBSCRIPT RESIDES IN PTPP(INDXPT+1) */
L20:
    ++a1com_1.indxpt;
    adum = ptpp[a1com_1.indxpt - 1];
    goto L50;

/*  30 SUBSCRIPT RESIDES IN SCALR(K) */
L30:
    adum = ascalr_1.scalr[a1pas2_1.k - 1];
    goto L50;

/*  40 K CONTAINS THE VST INDEX OF THE SUBSCRIPT */
L40:
    ++a1pas2_1.k;
    ktm = (a1pas2_1.k << 1) - 1;
/*     CHECK FOR DEFINED SCALAR VARIABLE */
    if (ivst[OTHER_ENDIAN_S(ktm - 1)] == 2) {
	goto L45;
    }

/*     SUBSCRIPT NOT DEFINED SCALAR - ERROR */
L42:
    --a1pas2_1.k;
    a2cls7_1.ename = avst_1.vst[a1pas2_1.k - 1];
    a1com_1.namsub = 0;
    a1com_1.jsuber = 83;
    goto L140;

L45:
    a1com_1.namsub = ivst[OTHER_ENDIAN_S(ktm)];
    ktm = (a1com_1.namsub << 1) - 1;
    if (icanon[OTHER_ENDIAN_S(ktm)] != 9) {
	goto L48;
    }
    if (icanon[OTHER_ENDIAN_S(ktm - 1)] == 0) {
	goto L42;
    }
L48:
    adum = canon[a1com_1.namsub - 1];
    if (a1com_1.kdbug == 0) {
	goto L50;
    }
    s_wsfe(&io___13);
    do_fio(&c__1, (char *)&canon[a1com_1.namsub - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
L50:
    a1com_1.namsub = (integer) adum;

L52:
    ++a1com_1.indxpt;
/*       GET MAXIMUM SIZE OF RESERV ARRAY */
L55:
    ivtem = (iv << 1) - 1;
    ik = (i__1 = ivst[OTHER_ENDIAN_S(ivtem + 2)], abs(i__1));
/*       DOES NAMSUB EXCEED THE SIZE */
    if (a1com_1.namsub > ik) {
	goto L110;
    }
/*       IS NAMSUB ZERO OR NEGATIVE */
    if (a1com_1.namsub < 1) {
	goto L110;
    }
    goto L150;

/* ...     SUBSCRIPT IS AN INCLUSIVE FORMAT */
/* ...     DETERMINE WHETHER OR NOT THIS IS THE FIRST ENCOUNTER */
/* ...     WITH THIS SUBSCRIPT, AND, IF SO, WHETHER OR NOT THIS */
/* ...     TYPE OF SUBSCRIPT IS ACCEPTABLE AT PRESENT */
L60:
    if ((i__1 = *knclus - 1) < 0) {
	goto L100;
    } else if (i__1 == 0) {
	goto L65;
    } else {
	goto L75;
    }

/* ...     INITIAL ENCOUNTER, WHICH IS ACCEPTABLE - COMPUTE */
/* ...     INDEX TO REFERENCE WORD FOR ARGUMENT LIST DATA BLOCK */
L65:
    jtemp1 = ((a1pas2_1.k + a1pas2_1.icanst - 1) << 1) - 1;
/* ...     MAKE SURE DATA BLOCK IS INCLUSIVE SUBSCRIPT FORMAT */
    if (icanon[OTHER_ENDIAN_S(jtemp1)] != 4) {
	goto L105;
    }
/* ...     PICK UP INDEX TO SUBSCRIPT DATA BLOCK */
    locsub = (icanon[OTHER_ENDIAN_S(jtemp1 - 1)] << 1) + 1;
/* ...     SET CONTROL FLAG TO INDICATE INCLUSIVE SUBSCRIPT IN PROCESS */
    *knclus = 2;

/* ...     IF FINAL SUBSCRIPT NOT GIVEN, SET TO SIZE OF ARRAY */
    if (icanon[OTHER_ENDIAN_S(locsub)] != 0) {
	goto L70;
    }
/* ...     PICK UP INDEX TO VST ENTRY FOR SYMBOL */
    jtemp1 = (iptpp[OTHER_ENDIAN_S(kindxp)] << 1) - 1;
/* ...     GET SIZE OF ARRAY, AND PUT IT INTO SUBSCRIPT DATA BLOCK */
    icanon[OTHER_ENDIAN_S(locsub)] = (i__1 = ivst[OTHER_ENDIAN_S(jtemp1 + 2)], abs(i__1));
/* ...     IF SUBSCRIPT INCREMENT IS NEGATIVE, REVERSE LIMIT */
/* ...     VALUES IN DATA BLOCK */
L70:
    if ((i__1 = icanon[OTHER_ENDIAN_S(locsub + 1)]) < 0) {
	goto L72;
    } else if (i__1 == 0) {
	goto L100;
    } else {
	goto L80;
    }
L72:
    jtemp1 = icanon[OTHER_ENDIAN_S(locsub - 1)];
    icanon[OTHER_ENDIAN_S(locsub - 1)] = icanon[OTHER_ENDIAN_S(locsub)];
    icanon[OTHER_ENDIAN_S(locsub)] = jtemp1;
    goto L80;

/* ...     INCREMENT SUBSCRIPT VALUE (IN STARTING LIMIT LOCATION) */
L75:
    icanon[OTHER_ENDIAN_S(locsub - 1)] += icanon[OTHER_ENDIAN_S(locsub + 1)];
/* ...     PUT SUBSCRIPT VALUE INTO NAMSUB */
L80:
    a1com_1.namsub = icanon[OTHER_ENDIAN_S(locsub - 1)];
/* ...     COMPARE NEXT SUBSCRIPT VALUE WITH LIMIT TO DETERMINE */
/* ...     WHETHER OR NOT THIS VALUE IS THE LAST ONE */
    if (icanon[OTHER_ENDIAN_S(locsub + 1)] * (icanon[OTHER_ENDIAN_S(locsub - 1)] + icanon[OTHER_ENDIAN_S(locsub + 1)] - 
	    icanon[OTHER_ENDIAN_S(locsub)]) > 0) {
	goto L85;
    }

/* ...     THIS IS NOT LAST SUBSCRIPT VALUE - SET INDXPT BACK TO */
/* ...     START OF THIS ENTRY */
    --a1com_1.indxpt;
    goto L55;

/* ...     LAST SUBSCRIPT - CLEAR CONTROL FLAG */
L85:
    *knclus = 0;
    goto L52;


L100:
    a1com_1.jsuber = 103;
    goto L140;
L105:
    a1com_1.jsuber = 109;
    goto L140;
L110:
    a1com_1.jsuber = 104;
    ++a1com_1.indxpt;
    goto L140;

L140:
    ++a1com_1.indxpt;
    *knclus = 0;
L150:
    return 0;

} /* agtsub_ */

#undef knclus
#undef kargpn
#undef icanon
#undef iptpp
#undef canon
#undef ivst
#undef ptpp
#undef karg


