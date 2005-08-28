/* AVS1CK.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal vst[2750], ptpp[2225], canon[2225];
} avst_;

#define avst_1 avst_

struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

/* Subroutine */ int avs1ck_(j)
integer *j;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer n;
#define vst4 ((integer *)&avst_1)
    static integer kret, nams4;
    extern /* Subroutine */ int aprfix_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */


/*     THIS ROUTINE INTERROGATES THE VST FOR THE BCD ENTRY GIVEN IN NAMEZ */
/*     IF NAME IS FOUND IN THE VST, NAMSUB IS SET TO THE RELATIVE LOCATIO */
/*     N IN THE VST FOR NAME. IN NOT , NAMSUB=0 */
/*     THE ENTRY TYPE IS EXAMINED, AND THE RETURN VARIABLE J SET THUSLY */
/*         J     TYPE OF ENTRY */
/*         1    SYMBOL NOT DEFINED */
/*         2    DEFINED AS A SURFACE */
/*         3    SYMBOL HAS BEEN CROSS-REFERENCED ONLY */
/*         4    SYMBOL IS A STATEMENT ID */
/*         5    DEFINED AS A SCALAR */
/*         6    DIMENSIONED BUT NOT USED */
/*         7    SYMBOL IS A MACRO NAME */
/*         8    SYMBOL IS DIMENSIONED AND FIRST USED AS A SCALAR */
/*         9    SYMBOL IS DIMENSIONED AND FIRST USED AS A SURFACE */
doublereal debugg1, debugg2;
/* ...     NAMSUB INITIALLY ZERO - SET TO VST INDEX IF SYMBOL FOUND */
    a1com_1.namsub = 0;

/* ...     LOOK FOR NAME IN VST */
    i__1 = amxtab_1.maxvs1;
    for (n = 1; n <= i__1; n += 2) {
	debugg1=avst_1.vst[n - 1];
	debugg2=a1com_1.name__;
	if (avst_1.vst[n - 1] != a1com_1.name__) {
	    goto L10;
	}
/* ...     SYMBOL FOUND - SET NAMSUB TO POINT TO 2ND WORD FOR IT IN VST */
	a1com_1.namsub = n;
L10:
	;
    }
    if (a1com_1.namsub != 0) {
	goto L20;
    }
/* ...     IT WAS NOT FOUND */
/* L15: */
    *j = a0con_1.k1;
    return 0;

/* ...     IT WAS FOUND... */
L20:
    nams4 = (a1com_1.namsub << 1) - 1;
/* ...     SEE IF IT IS DIMENSIONED BUT NOT YET USED */
    if (vst4[OTHER_ENDIAN_S(nams4 + 2)] < 0) {
	goto L70;
    }
/* ...     NO - HOW ABOUT DIMENSIONED AND USED */
    *j = vst4[OTHER_ENDIAN_S(nams4 + 1)];
    if (*j < a0con_1.k0) {
	goto L70;
    }
/* ...     JUST NOT DIMENSIONED - IS IT DEFINED BUT NOT PROCESSED */
    if (*j == a0con_1.k7) {
	goto L30;
    }
/* ...     NO - TEST FOR REFERENCED BUT NOT DEFINED */
    if (*j == a0con_1.k8) {
	goto L35;
    }
    goto L40;
L30:
    *j = a0con_1.k2;
    return 0;
L35:
    *j = a0con_1.k3;
    return 0;

/* ...     IS IT A STATEMENT ID */
L40:
    if (*j == a0con_1.k3) {
	goto L50;
    }
/* ...     NO - IS IT A SCALAR */
    if (*j == a0con_1.k2) {
	goto L60;
    }
/* ...  IF IT IS A SYSTEM MACRO WHICH IS NOT YET DEFINED, RETURN */
    if (*j == 11) {
	return 0;
    }
    *j = a0con_1.k7;
    return 0;
L50:
    *j = a0con_1.k4;
    return 0;
L60:
    *j = a0con_1.k5;
    return 0;

/*     DIMENSIONED VARIABLE */
L70:
    aprfix_(&a0con_1.k3, &kret);
    if ((i__1 = kret - a0con_1.k1) < 0) {
	goto L80;
    } else if (i__1 == 0) {
	goto L90;
    } else {
	goto L100;
    }
/* ...     USE NOT YET ESTABLISHED */
L80:
    *j = a0con_1.k6;
    return 0;
/* ...     SCALAR ARRAY */
L90:
    *j = a0con_1.k8;
    return 0;
/* ...     SURFACE ARRAY */
L100:
    *j = a0con_1.k9;
    return 0;
} /* avs1ck_ */

#undef vst4


