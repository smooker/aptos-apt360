/* ASCLPT.f -- translated by f2c (version 20000121).
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
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

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
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Subroutine */ int asclpt_(a)
doublereal *a;
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_10 = { {'A', 'S', 'C', 'A', 'L', 'R', 'P', 'T'}, 0. };

#define a1 (*(doublereal *)&equiv_10)

    static struct {
	integer e_1[2];
	doublereal e_2;
	} equiv_2 = { 0, 9, 0. };


    /* Local variables */
#define ierr ((integer *)&equiv_2)
    static integer kret;
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
#define canon ((doublereal *)&avst_1)
    static integer jtemp;
    extern /* Subroutine */ int avs2ck_();
    static integer iv;
#define errcod ((doublereal *)&equiv_2)
    extern /* Subroutine */ int adprnt_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* *    THIS ROUTINE STORES SCALAR 'A' IN THE CANON SCALAR STORAGE AREA */
/* *    ICANSC IS THE BEGINNING OF SCALAR STORAGE INDEX */
/* *    NAME CONTAINS THE VST INDEX OF THE SCALAR SYMBOL */
/* *    NAMSUB CONTAINS THE SUBSCRIPT VALUE */

/*       INTEGER IERR(2)/0,9/ */

    a1pas2_1.i__ = a1com_1.name__;
/*     CHECK STATUS OF VARIABLE SYMBOL */
/*     AVS2CK SETS NAME TO VST INDEX FOR SUB. AND NON-SUB. VARIABLES */
    avs2ck_(&kret);
    jtemp = (a1com_1.name__ << 1) - 1;
/* ...     IF DATA TO BE STORED IS AN ERROR CODE, GO TO PUT ERROR CODE */
/* ...     IN VST ENTRY FOR SYMBOL */
    if (*a == *errcod) {
	goto L22;
    }
/* ...     TEST FOR DEFINED SCALAR VARIABLE */
    if (kret == 2) {
	goto L30;
    }
/* ...     SEE IF SYMBOL IS UNDEFINED IN PASS 2 - YES IF KRET = 7 */
    if (kret == 7) {
	goto L20;
    }
/*     SAVE SYMBOL FOR ERROR DIAGNOSTICS */
    a2cls7_1.ename = avst_1.vst[a1pas2_1.i__ - 1];
/* ...    IGNORE IF ERROR ALREADY DIAGNOSED */
    iv = (a1pas2_1.i__ << 1) - 1;
    if (ivst[OTHER_ENDIAN_S(iv + 1)] == 9) {
	goto L40;
    }
/*     VARIABLE IS ILL-DEFINED */
/* L5: */
    a1com_1.jsuber = 139;
    return 0;
/* ...     SEE IF AVAILABLE SCALAR STORAGE SPACE HAS BEEN EXCEEDED */
L20:
    if (a1pas2_1.icansc < a1pas2_1.icanst) {
	goto L25;
    }
/* ...     YES - SET ERROR FLAG */
    a1com_1.jsuber = 139;
/* ...     PUT CODE IN VST ENTRY FOR INCORRECTLY DEFINED */
L22:
    ivst[OTHER_ENDIAN_S(jtemp - 1)] = 9;
    return 0;

/* ...     SET VST REFERENCE TO DEFINED SCALAR VARIABLE */
L25:
    ivst[OTHER_ENDIAN_S(jtemp - 1)] = 2;
/* ...     PUT SCALAR STORAGE INDEX INTO VST */
    ivst[OTHER_ENDIAN_S(jtemp)] = a1pas2_1.icansc;
/* ...     INCREMENT SCALAR STORAGE INDEX FOR NEXT ENTRY */
    ++a1pas2_1.icansc;

/* ...     PICK UP INDEX TO SCALAR STORAGE LOCATION */
L30:
    a1pas2_1.j = ivst[OTHER_ENDIAN_S(jtemp)];
/*     STORE SCALAR VALUE IN CANON */
    canon[a1pas2_1.j - 1] = *a;
/*     IS DEBUG ON */
    if (a1com_1.kdbug == 0) {
	return 0;
    }
    adebug_1.idebug[0] = 8;
    adebug_1.idebug[1] = a1pas2_1.i__;
    adebug_1.idebug[2] = a1pas2_1.j;
    adprnt_(&a1);
L40:
    return 0;
} /* asclpt_ */

#undef errcod
#undef canon
#undef ivst
#undef ptpp
#undef ierr
#undef a1


