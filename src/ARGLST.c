/* ARGLST.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

/* Table of constant values */

static integer c__10 = 10;
static integer c__1 = 1;

/* Subroutine */ int arglst_()
{
    /* Format strings */
    static char fmt_480[] = "(\0020  ARGLST\002,4z12/\002 \002,(6x,5z20\
/\002 \002))";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define canon ((doublereal *)&avst_1)
#define iptpp ((integer *)&avst_1)
    static integer jtemp1, jtemp2, jtemp3, jtemp4;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
#define defans ((doublereal *)&adfsto_1 + 3)
#define icanon ((integer *)&avst_1)
#define idfsto ((integer *)&adfsto_1)
#define length ((integer *)&adfsto_1 + OTHER_ENDIAN_S(1))
#define kreslt ((integer *)&adfsto_1 + OTHER_ENDIAN_S(7))
    static integer iptlim, kindxp, nstans, numarg;
    extern /* Subroutine */ int agtarg_();
    static integer iptype;

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 0, fmt_480, 0 };



/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */


/* ...     COMPUTE LIMIT INDEX FOR SCAN OF THIS LIST */
    iptlim = a1pas2_1.indexs + a1pas2_1.klasct;
/* ...     SAVE INDEX TO LOCATION IN CANON FOR STORAGE OF POINTER */
/* ...     TO 'CANONICAL FORM' OF THIS ARGUMENT LIST */
    kindxp = (a1com_1.indxpt << 1) - 1;
    nstans = (iptpp[OTHER_ENDIAN_S(kindxp - 1)] + a1pas2_1.icanst - 1 << 1) - 1;
/* ...     MOVE PICK-UP INDEX TO FIRST ENTRY TO BE IDENTIFIED */
    ++a1com_1.indxpt;

/* ...     INITIALIZE STORING INDEX AND ARGUMENT COUNT */
    jtemp1 = 1;
    numarg = 0;
/* ...     CLEAR LIST TYPE */
    jtemp2 = 0;
/* ...     CLEAR SPECIAL FORMAT FLAG */
    jtemp3 = 0;

/* ...     SET FLAG TO OBTAIN ONLY CANON BLOCK FOR LARGE SURFACES */
/* ...     AND PATTERNS */
    a1pas2_1.idtmov = 1;
/* ...     IDENTIFY NEXT ARGUMENT, AND INCREMENT COUNT */
L50:
    agtarg_(defans, &c__10, &iptype);
    ++numarg;

/* ...     IF SPECIAL FORMAT FLAG SET, BRANCH TO SPECIAL TESTS */
/* L60: */
    if (jtemp3 != 0) {
	goto L200;
    }

/* ...     TEST FOR VOCABULARY */
    if (iptype == 5) {
	goto L120;
    }

/* ...     ONLY OTHER ACCEPTABLE ENTRIES ARE SCALAR OR SURFACE */
    if ((i__1 = iptype - 3) < 0) {
	goto L70;
    } else if (i__1 == 0) {
	goto L65;
    } else {
	goto L500;
    }

/* ...     UNDEFINED SYMBOL - ERROR */
L65:
    a1com_1.jsuber = 101;
    goto L500;

/* ...     DETERMINE WHETHER ENTRY IS SCALAR OR SURFACE */
L70:
    if (iptype == 2) {
	goto L80;
    }

/* ...     SCALAR - ADD TO DATA BLOCK IN DEFTAB */
/* L75: */
    deftab[jtemp1 - 1] = defans[0];
    goto L90;

/* ...     SURFACE - STACK IN DEFTAB - STORE SURFACE TYPE CODE FIRST */
L80:
    jtemp4 = (jtemp1 << 1) - 1;
    idftab[OTHER_ENDIAN_S(jtemp4 - 1)] = 0;
    idftab[OTHER_ENDIAN_S(jtemp4)] = idfsto[OTHER_ENDIAN_S(0)];
/* ...     ADD SURFACE DATA TO BLOCK IN DEFTAB */
    i__1 = *length;
    for (a1pas2_1.j = 4; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	++jtemp1;
/* L85: */
	deftab[jtemp1 - 1] = defans[a1pas2_1.j - 4];
    }

/* ...     IF THIS IS FIRST ARGUMENT, SET LIST TYPE TO ITS TYPE */
L90:
    if (jtemp2 != 0) {
	goto L95;
    }
    jtemp2 = iptype;
    goto L100;

/* ...     NOT FIRST ARGUMENT - SEE WHETHER OR NOT TYPE OF THIS ONE */
/* ...     AGREES WITH THAT OF LIST SO FAR */
L95:
    if (iptype == jtemp2) {
	goto L100;
    }

/* ...     TYPES DO NOT MATCH - MAKE LIST TYPE UNDEFINED */
    jtemp2 = 3;

/* ...     INCREMENT STORING INDEX */
L100:
    ++jtemp1;

/* ...     IF NOT END OF LIST, RETURN FOR NEXT ARGUMENT */
L110:
    if (iptlim - a1com_1.indxpt >= 0) {
	goto L50;
    } else {
	goto L400;
    }

/* ...     ARGUMENT IS VOCABULARY */

/* ...     SEE WHETHER OR NOT MODIFIER IS 'THRU' OR 'ALL', INDICATING */
/* ...     INCLUSIVE SUBSCRIPT */
L120:
    if (*kreslt == 152) {
	goto L140;
    }
/* ...     TEST FOR 'ALL' */
L125:
    if (*kreslt == 51) {
	goto L150;
    }

/* ...     INCORRECT FORMAT - ERROR */
L130:
    a1com_1.jsuber = 274;
    goto L500;

/* ...     'THRU' FOUND - SHOULD BE FIRST ARGUMENT, OR ONLY ONE SCALAR */
/* ...     SO FAR - TEST COUNT, AND LIST TYPE CODE IF NECESSARY */
L140:
    if ((i__1 = jtemp1 - 2) < 0) {
	goto L142;
    } else if (i__1 == 0) {
	goto L145;
    } else {
	goto L130;
    }
/* ...     FIRST ARGUMENT - SET UP IMPLIED LOWEST VALUE OF ONE */
L142:
    deftab[0] = (float)1.;
    jtemp1 = 2;
    goto L160;
/* ...     SECOND ARGUMENT - CHECK LIST TYPE CODE FOR SCALAR */
L145:
    if (jtemp2 - 1 != 0) {
	goto L130;
    } else {
	goto L160;
    }

/* ...     'ALL' FOUND - IF FIRST ARGUMENT, SET UP LOWEST SUBSCRIPT VALUE */
L150:
    if ((i__1 = jtemp1 - 2) < 0) {
	goto L152;
    } else if (i__1 == 0) {
	goto L155;
    } else {
	goto L130;
    }
L152:
    deftab[0] = (float)1.;
/* ...     INDICATE HIGHEST SUBSCRIPT VALUE TO BE ARRAY SIZE */
L155:
    deftab[1] = (float)0.;
/* ...     SET STORING INDEX */
    jtemp1 = 3;

/* ...     SET INCLUSIVE SUBSCRIPT LIST TYPE, AND CLEAR */
/* ...     SUBSCRIPT INCREMENT FLAG */
L160:
    jtemp2 = 4;
    jtemp4 = 0;
/* ...     SET SPECIAL FORMAT FLAG, AND RETURN FOR NEXT ARGUMENT */
    jtemp3 = 1;
    goto L110;

/* ...     SPECIAL FORMAT - ONLY ONE NOW IS INCLUSIVE SUBSCRIPT NEST */
/* ...     DETERMINE TYPE OF INPUT ARGUMENT */
L200:
    if (iptype == 1) {
	goto L240;
    }
/* ...     NOT SCALAR - ONLY OTHER ACCEPTABLE ENTRY IS VOCABULARY */
    if (iptype != 5) {
	goto L130;
    }

/* ...     MODIFIER FOUND - BRANCH TO TESTS FOR 'ALL' AND 'INCR' */
/* ...     OR 'DECR' ON NUMBER COUNT */
    if ((i__1 = jtemp1 - 3) < 0) {
	goto L125;
    } else if (i__1 == 0) {
	goto L225;
    } else {
	goto L130;
    }

/* ...     TWO NUMBERS ALREADY IN LIST - TEST FOR 'INCR' OR 'DECR' */
L225:
    if (*kreslt != 66) {
	goto L230;
    }
/* ...     'INCR' FOUND - SET FLAG TO ACCEPT SUBSCRIPT INCREMENT */
    jtemp4 = 1;
    goto L110;
/* ...     NOT 'INCR' - TRY 'DECR' */
L230:
    if (*kreslt != 65) {
	goto L130;
    }
/* ...     YES - SET FLAG TO ACCEPT AND CHANGE SIGN OF SUBSCR. INCREMENT */
    jtemp4 = -1;
    goto L110;

/* ...     SCALAR FOUND - MUST ALREADY HAVE ONE OR TWO ENTRIES */
L240:
    if ((i__1 = jtemp1 - 3) < 0) {
	goto L255;
    } else if (i__1 == 0) {
	goto L245;
    } else {
	goto L130;
    }

/* ...     TWO ENTRIES - SEE IF SUBSCRIPT INCREMENT ACCEPTABLE */
L245:
    if (jtemp4 < 0) {
	goto L250;
    } else if (jtemp4 == 0) {
	goto L130;
    } else {
	goto L255;
    }
/* ...     INCREMENT IS A DECREMENT - CHANGE SIGN */
L250:
    defans[0] = -defans[0];

/* ...     ADD SCALAR INPUT TO INCLUSIVE SUBSCRIPT LIST */
L255:
    deftab[jtemp1 - 1] = defans[0];
    goto L100;

/* ...     END OF PARAMETER LIST... */
/* ...     BRANCH ON LIST TYPE FOR ANY SPECIAL PROCESSING */
L400:
    if ((i__1 = jtemp2 - 4) < 0) {
	goto L450;
    } else if (i__1 == 0) {
	goto L430;
    } else {
	goto L130;
    }

/* ...     TEST FOR ADEQUATE ENTRIES FOR INCLUSIVE SUBSCRIPT */
L430:
    if ((i__1 = jtemp1 - 4) < 0) {
	goto L432;
    } else if (i__1 == 0) {
	goto L440;
    } else {
	goto L436;
    }
L432:
    if ((i__1 = jtemp1 - 3) < 0) {
	goto L436;
    } else if (i__1 == 0) {
	goto L434;
    } else {
	goto L440;
    }
L434:
    if (jtemp4 == 0) {
	goto L438;
    }
L436:
    a1com_1.jsuber = 275;
    goto L500;

/* ...     LIMITS ONLY GIVEN - ADD IMPLIED INCREMENT TO DATA BLOCK */
L438:
    deftab[jtemp1 - 1] = (float)1.;

/* ...     CONVERT TO FIXED POINT FROM FLOATING POINT INPUT */
L440:
    for (a1pas2_1.j = 1; a1pas2_1.j <= 3; ++a1pas2_1.j) {
/* L442: */
	idftab[OTHER_ENDIAN_S(a1pas2_1.j - 1)] = (integer) deftab[a1pas2_1.j - 1];
    }
    jtemp1 = 3;


/* ...     TEST FOR SUFFICIENT SPACE FOR THIS DATA BLOCK IN STORAGE AREA */
L450:
    if (ascalr_1.loctem + jtemp1 <= a1pas2_1.icanst + 50) {
	goto L455;
    }
/* ...     THERE IS NOT SPACE - ERROR */
    a1com_1.jsuber = 272;
    goto L500;

/* ...     PUT INDEX TO LOCATION OF DATA BLOCK, AND TYPE OF ARGUMENT */
/* ...     LIST, INTO REFERENCE WORD AT START OF CANON */
L455:
    icanon[OTHER_ENDIAN_S(nstans - 1)] = ascalr_1.loctem;
    icanon[OTHER_ENDIAN_S(nstans)] = jtemp2;
/* ...     PUT LENGTH OF DATA, AND NUMBER OF ARGUMENTS, INTO FIRST */
/* ...     WORD OF DATA BLOCK */
    jtemp4 = (ascalr_1.loctem << 1) - 1;
    icanon[OTHER_ENDIAN_S(jtemp4 - 1)] = jtemp1;
    icanon[OTHER_ENDIAN_S(jtemp4)] = numarg;
    ++ascalr_1.loctem;

/* ...     MOVE SCALAR OR SURFACE STACK TO STORAGE AREA */
    i__1 = jtemp1;
    for (a1pas2_1.j = 2; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	canon[ascalr_1.loctem - 1] = deftab[a1pas2_1.j - 2];
/* L460: */
	++ascalr_1.loctem;
    }

/* L470: */
    if (a1com_1.kdbug == 0) {
	goto L490;
    }
    jtemp4 = icanon[OTHER_ENDIAN_S(nstans - 1)];
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&iptpp[OTHER_ENDIAN_S(kindxp - 1)], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nstans, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&icanon[OTHER_ENDIAN_S(nstans - 1)], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&icanon[OTHER_ENDIAN_S(nstans)], (ftnlen)sizeof(integer));
    i__1 = ascalr_1.loctem;
    for (a1pas2_1.j = jtemp4; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	do_fio(&c__1, (char *)&canon[a1pas2_1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

L490:
    return 0;

L500:
    icanon[OTHER_ENDIAN_S(nstans)] = 9;
    icanon[OTHER_ENDIAN_S(nstans - 1)] = 0;
    goto L490;
} /* arglst_ */

#undef kreslt
#undef length
#undef idfsto
#undef icanon
#undef defans
#undef idftab
#undef deftab
#undef iptpp
#undef canon


