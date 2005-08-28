/* AVS2CK.f -- translated by f2c (version 20000121).
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
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Subroutine */ int avs2ck_(jk)
integer *jk;
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
#define kvst ((shortint *)&avst_1)
#define canon ((doublereal *)&avst_1)
    static integer namtem;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* **** THIS ROUTINE CHECKS THE STATUS OFA VARIABLE SYMBOL IN THE VST. THE */
/*     INPUT TO THE ROUTINE IS THE VST, THE INDEX TO THE VST IN THE */
/*     VARIABLENAME AND THE SUBSCRIPT VALUE IN THE VARIABLE NAMSUB. JK IS */
/*     THE RETURN VARIABLE SET AS FOLLOWS */
/*     =1, SURFACE IN CANON TABLE */
/*     =2, SCALAR IN CANON TABLE */
/*     =3, STATEMENT ID */
/*     =4, SURFACE IN DEFTAB CANON */
/*     =5, SURFACE IN DEFPRE CANON */
/*     =6, SURFACE IN CANTAP FILE */
/*     =7, HAS NOT BEEN PROCESSED IN PHASE 2 */
/*     =8, UNDEFINED BUT CROSS REFERENCED */
/*     =9, INCORRECTLY DEFINED */
/*     =10, SUBSCRIPT EXCEEDS ALLOWABLE RANGE */
/*     =11, OTHER ERRORS */


/*     UPDATE VST INDEX */
    ++a1com_1.name__;
/*     IS THE SYMBOL SUBSCRIPTED */
    if (a1com_1.namsub == 0) {
	goto L10;
    }

/*     THE SYMBOL IS SUBSCRIPTED. */
/*     GET MAXIMUM SIZE OF RESERV ARRAY */
    namtem = (a1com_1.name__ << 1) - 1;
/* ...     MAKE SURE ARRAY HAS AT LEAST ONE DEFINED ENTRY */
    if (ivst[OTHER_ENDIAN_S(namtem - 1)] < 0) {
	goto L5;
    }
/* ...     IT DOES NOT - SET RETURN VARIABLE FOR UNDEFINED, AND EXIT */
    *jk = 7;
    goto L15;

/* ...     THERE IS AT LEAST ONE ENTRY - COMPUTE INDEX TO DESCRIPTOR */
/* ...     FOR DESIRED SUBSCRIPT VALUE */
L5:
    a1com_1.name__ = (i__1 = ivst[OTHER_ENDIAN_S(namtem - 1)], abs(i__1)) + a1com_1.namsub + 
	    amxtab_1.maxvs1;

/* ...     PICK UP THE TYPE CODE FOR THIS (POSSIBLY SUBSCRIPTED) SYMBOL */
L10:
    namtem = (a1com_1.name__ << 2) - 3;
    *jk = kvst[OTHER_ENDIAN_W(namtem)];
    if (*jk == 8) {
	*jk = 7;
    }
L15:
    return 0;
} /* avs2ck_ */

#undef canon
#undef kvst
#undef ivst
#undef ptpp


