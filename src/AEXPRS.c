/* AEXPRS.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

/* Subroutine */ int aexprs_()
{
    /* Local variables */
    static integer n, it;
#define ipt ((integer *)&aptpp_1)
    extern /* Subroutine */ int aptlod_(), aptput_();

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* .. */

/* THIS SUBROUTINE CONTROLS THE OUTPUT OF A CLASS 12 PTPP RECORD.SJD */
/* .... */

/* ... */

/* ..SET APTLOD  PICK-UP INDEX TO THE FIRST ENTRY TO BE PROCESSED. */
    ++aprtab_1.istarp;
/* .. SET PTPP TRANSFER FLAG TO NORMAL MODE. */
    it = 5;
/* .. TRANSLATE AN ICLASS ENTRY INTO THE DESIRED PTPP CODED ENTRIES. */
L10:
    aptlod_();
    if (a1com_1.jsuber != 0) {
	goto L130;
    }
/* ... HAVE WE FOUND THE END OF THE NEST. */
    if (aprtab_1.istarp >= aprtab_1.iendp) {
	goto L20;
    }
/* ... NOT END OF NEST, IS THERE AN OVERFLOW OF PT BUFFER. */
    if (aptpp_1.inptp >= 298) {
	goto L80;
    }
/* ... A.O.K.    TRANSLATE NEXT ICLASS ENTRY */
    goto L10;
/* .. */
/* ...   END OF NEST IS FOUND.BRANCH ON JMODE SETTING,THAT IS 'IT'. */
L20:
    switch ((int)it) {
	case 1:  goto L60;
	case 2:  goto L60;
	case 3:  goto L60;
	case 4:  goto L998;
	case 5:  goto L70;
    }
/* .. */
/* ...     OUTPUT NUMBER OF WORDS IN PTPP RECORD, EXCLUDING FIRST ONE */
L30:
    ipt[OTHER_ENDIAN_S(1)] = n;
/* ... */
L40:
    aptpp_1.jmode = it;
    --aptpp_1.inptp;
    aptput_();
    if (a1com_1.jsuber != 0) {
	goto L130;
    }
    if (it >= 3) {
	goto L998;
    }
/* .. */
/* .. PREVIOUS MODE SETIING WAS 'OUTPUT 1ST PORTION'OR ' CONT. MODE' */
/* ..       SET 'IT' TO CONT. MODE. */
/* .. THIS IS CONTINUATION MODE. TRANS. REMAINING ICLASS ENTRIES. */
/* L50: */
    it = 2;
    aptpp_1.inptp = 1;
    goto L10;
/* .. */
/* ..  END OF NEST ENCOUNTERED WHILE  CONTINUATION OF PT BUFFER PREVAILS. */
L60:
    it = 3;
    aptpp_1.nw = aptpp_1.nw + aptpp_1.inptp - 1;
    goto L40;
/* .. */
/* .. END OF NEST IN NORMAL MODE. */
/* ..  CALCULATE LENGTH OF THIS PTPP RECORD. */
L70:
    n = aptpp_1.inptp - 2;
    goto L30;
/* .. */
/* .. */
/* .. OVERFLO OF PT BUFFER, BRANCH ON 'IT' SETTING. */
L80:
    switch ((int)it) {
	case 1:  goto L100;
	case 2:  goto L105;
	case 3:  goto L110;
	case 4:  goto L110;
	case 5:  goto L90;
    }
/* .. */
/* ..  PREVIOUS MODE SETTING WAS 'NORMAL'. SET 'IT' TO OUTPUT 1ST PORTION. */
L90:
    it = 1;
/* ...     INITIALIZE COUNT OF WORDS IN PTPP RECORD TO EXCLUDE FIRST WORD */
    aptpp_1.nw = aptpp_1.inptp - 2;
    goto L40;
/* .. */
/* .. SET 'IT' TO CONTINUATION MODE AND OUTPUT PT BUFFER. */
L100:
    it = 2;
L105:
    aptpp_1.nw = aptpp_1.nw + aptpp_1.inptp - 1;
    goto L40;
/* .. */
/* .. IMPOSSIBLE TO GET THIS ERROR SETTING----BUT JUST IN CASE.. */
L110:
    a1com_1.jsuber = 6128;
/* .. */
/* .. */
/* .. ERASE PTPP TABLE ENTRIES FOR THIS ERROR RECORD. */
/* ...    THAT IS, IF THERE WAS A CONTINUATION MODE PREVAILING. */
L130:
    if (it == 5) {
	goto L998;
    }
    it = 4;
    goto L40;
/* ... */
L998:
    return 0;
} /* aexprs_ */

#undef ipt


