/* ACLS12.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

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
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

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
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

/* Table of constant values */

static integer c__1 = 1;
static integer c__85 = 85;

/* Subroutine */ int acls12_()
{
    /* Format strings */
    static char fmt_1[] = "(\002 \002,30i4)";
    static char fmt_400[] = "(\002 FINAL RESULT FROM  ACLS12  IS\002,f16.7//)"
	    ;

    /* System generated locals */
    integer i__1;
    doublereal d__1;
    static doublereal equiv_3[1];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();
    double pow_di(), pow_dd(), sqrt(), sin(), cos(), exp(), log(), atan(), 
	    d_lg10(), tan(), atan2();

    /* Local variables */
    static integer l8, nt, ipt, jpt;
    static shortint lst, narg;
    extern /* Subroutine */ int adot_();
    static integer isnd;
#define fnum (equiv_3)
    static doublereal temp;
#define ksto ((integer *)&avst_1 + 12400)
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
    static integer isign;
#define kfnum ((integer *)equiv_3)
    static integer iopno;
#define store ((doublereal *)&avst_1 + 6200)
#define iptpp ((integer *)&avst_1)
    static integer jtemp1;
    extern /* Subroutine */ int acanck_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
#define kdfans ((shortint *)&adfsto_1 + 12)
#define iscalr ((integer *)&ascalr_1)
#define jopsto ((shortint *)&avst_1 + 24960)
#define ioprnd ((integer *)&adfsto_1)
#define oprand ((doublereal *)&avst_1 + 6210)
//original big endian:
//#define kstype ((integer *)equiv_3)
//#define kreslt ((integer *)equiv_3 + 1)
#define kstype ((integer *)equiv_3 +1 )
#define kreslt ((integer *)equiv_3)

    static integer istore, iptlim;
    extern /* Subroutine */ int agtarg_(), alngth_();

    /* Fortran I/O blocks */
    static cilist io___23 = { 0, 0, 0, fmt_1, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_400, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ... */
/* ..   THIS PASS TWO SUBROUTINE PROCESSES A CLASS 12 PTPP RECORD. */
/* ..    ( ARITHMETIC OPERATIONS AND ARITHMETIC FUNCTION STATEMENTS) */
/* ********        *******       ****MB****             *******SJD*** */


/* ...     INITIALIZE STORAGE FOR SUMMATION OF TERMS TO ZERO */
    oprand[0] = (float)0.;
/* ...     SET UP ADDITION OPERATOR FOR SUMMATION OF FIRST TERM */
    jopsto[OTHER_ENDIAN_W(3)] = 1;
/* ...     INITIALIZE OPERATOR-OPERAND COUNT TO ZERO */
    iopno = 0;
/* ... GET STORING INDEX TO SCALR TABLE FOR FINAL RESULTS */
    ipt = (a1com_1.indxpt << 1) - 1;
    istore = iptpp[OTHER_ENDIAN_S(ipt - 1)];
/* ... INCREMENT PTPP PICK-UP INDEX TO LOC. OF FIRST PARAMETER */
    ++a1com_1.indxpt;
/* .. FIRST SET LOCATION OF LAST 8-BYTE ENTRY FOR THIS PTPP RECORD */
    iptlim = iptpp[OTHER_ENDIAN_S(ipt - 2)] + (a1com_1.indxpt - 2);
/* ... FIRST ENTRY IS EXPECTED TO BE A SCALAR OR VOC. WORD ONLY */
/* ...     IF DEBUG OUTPUT DESIRED, PRINT PTPP RECORD */
    if (a1com_1.kdbug == 0) {
	goto L110;
    }
    nt = ipt - 2;
    nt = nt;
    isnd = iptlim << 1;
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
    i__1 = isnd;
    for (a1pas2_1.i__ = nt; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&iptpp[OTHER_ENDIAN_S(a1pas2_1.i__ - 1)], (ftnlen)sizeof(
		integer));
    }
    e_wsfe();
    goto L110;
/* ... */
/* ...         ***                ****               ****         **** */
/* ... */
/* ...   EXPECTING AN ARITHMETIC OPERATOR */
/* ... */
L100:
    *fnum = ptpp[a1com_1.indxpt - 1];
/* .... */
/* ... INCREMENT PTPP PICK-UP  INDEX TO NEXT ENTRY */
    ++a1com_1.indxpt;
/* ...  ILLEGAL IF NOT PUNCTUATION PTPP CODE */
    if (*kstype != 8) {
	goto L900;
    }
/* ... */
/* ...     CHECK IT FOR VALID RANGE */
    if (*kreslt <= 0) {
	goto L900;
    }
    if (*kreslt > 5) {
	goto L900;
    }

/* ...     SAVE OPERATOR IN LAST WORD OF OPERATION STACK FOR LATER TESTS */
    jopsto[OTHER_ENDIAN_W(3)] = (shortint) (*kreslt);

/* C. */
/* .. */
/* ...         ***                ****               ****         **** */
/* ...     TEST FOR END OF EXPRESSION - ILLEGAL AT THIS POINT - */
/* ...     OPERATOR LEFT DANGLING */
L110:
    if (a1com_1.indxpt > iptlim) {
	goto L910;
    }
/* ..  GET THE  EXPECTED  O P E R A N D */
    agtarg_(fnum, &c__1, &jpt);
    if (a1com_1.jsuber != 0) {
	goto L1000;
    }
/* ... */
/* ...     TEST FOR VOCABULARY WORD OR SCALAR - ONLY USABLE ENTRIES */
    switch ((int)jpt) {
	case 1:  goto L120;
	case 2:  goto L970;
	case 3:  goto L910;
	case 4:  goto L970;
	case 5:  goto L500;
	case 6:  goto L985;
	case 7:  goto L1000;
    }
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */

/* ...     INCREMENT OPERATOR COUNT */
L120:
    ++iopno;
/* .. */
/* ...     TEST FOR FOUR OR MORE OPERATIONS IN HOLD */
L125:
    if (iopno < 4) {
	goto L200;
    }

/* ...     FOUR OR MORE OPERATIONS IN HOLD - EXPONENTIATION SERIES - */
/* ...     IF LAST OPERATOR EXPON., SAVE ITS OPERAND UNTIL NON-EXPON. */
/* ...     OPERATOR FOUND - OTHERWISE EVALUATE LATEST EXPONENTIATION */
/* L140: */
    if (jopsto[OTHER_ENDIAN_W(3)] != 5) {
	goto L150;
    }
/* ...     OPERATOR IS EXPON. - MAKE SURE THERE IS ROOM FOR THIS */
/* ...     OPERAND IN STACK */
    if (iopno - 39 <= 0) {
	goto L350;
    } else {
	goto L930;
    }

/* ...     LAST OPERATOR NOT EXPON. - START EVALUATING SAVED EXPONENT- */
/* ...     IATION SEQUENCE */

/* ...     DETERMINE WHETHER OR NOT EXPONENT IS AN INTEGER */
L150:
    temp = oprand[iopno - 1];
    if ((d__1 = (integer) temp - temp, abs(d__1)) - (float)1e-6 > (float)0.) {
	goto L160;
    }

/* ...     YES, IT IS */
    jtemp1 = (integer) oprand[iopno - 1];
    oprand[iopno - 2] = pow_di(&oprand[iopno - 2], &jtemp1);
    goto L170;

/* ...     EXPONENT IS NOT AN INTEGER - IF VALUE TO BE EXPONENTIATED */
/* ...     IS NEGATIVE, ERROR */
L160:
    if (oprand[iopno - 2] < (float)0.) {
	goto L180;
    }
/* ...     VALUE TO BE RAISED TO A POWER IS POSITIVE - EXPONENTIATE */
    oprand[iopno - 2] = pow_dd(&oprand[iopno - 2], &oprand[iopno - 1]);

/* ...     DECREMENT OPERATOR COUNT, AND GO TO TEST FOR REDUCTION */
/* ...     OF STACK TO ACCEPTABLE LEVEL */
L170:
    --iopno;
    goto L125;

/* ...     NEGATIVE VALUE TO BE RAISED TO A NON-INTEGRAL POWER - ERROR */
L180:
    a1com_1.jsuber = 68;
    goto L1000;

/* ...     ADD NEWEST OPERATOR TO STACK USING COUNT OF */
/* ...     OPERATORS AS AN INDEX */
L200:
    jopsto[OTHER_ENDIAN_W(iopno - 1)] = jopsto[OTHER_ENDIAN_W(3)];
/* ...     LESS THAN FOUR OPERATIONS IN HOLD - BRANCH TO SPECIFIC */
/* ...     PROCESSING DEPENDING UPON NUMBER OF OPERATIONS */
    if ((i__1 = iopno - 2) < 0) {
	goto L350;
    } else if (i__1 == 0) {
	goto L300;
    } else {
	goto L210;
    }

/* ...     THREE OPERATIONS IN HOLD - IF LATEST IS EXPONENTIATION, SAVE */
/* ...     ITS OPERAND UNTIL NON-EXPONENTIATION OPERATOR FOUND */
L210:
    if (jopsto[OTHER_ENDIAN_W(3)] == 5) {
	goto L350;
    }

/* ...     LATEST NOT EXPONENTIATION - PERFORM PREVIOUS */
/* ...     OPERATION (MULTIPLY, DIVIDE, OR EXPONENTIATE) */
/* L220: */
    if ((i__1 = jopsto[OTHER_ENDIAN_W(1)] - 4) < 0) {
	goto L230;
    } else if (i__1 == 0) {
	goto L240;
    } else {
	goto L250;
    }

/* ...     DIVIDE FIRST OPERAND BY SECOND */
/* ...     MAKE SURE DIVISOR IS NOT ZERO - IF SO, ERROR */
L230:
    if (oprand[2] == 0.) {
	goto L940;
    }
    oprand[1] /= oprand[2];
    goto L270;

/* ...     MULTIPLY FIRST OPERAND BY SECOND */
L240:
    oprand[1] *= oprand[2];
    goto L270;

/* ...     RAISE FIRST OPERAND TO POWER INDICATED BY SECOND OPERAND */
/* ...     DETERMINE WHETHER OR NOT EXPONENT IS AN INTEGER */
L250:
    temp = oprand[2];
    if ((d__1 = (integer) temp - temp, abs(d__1)) - (float)1e-6 > (float)0.) {
	goto L260;
    }
/* ...     YES, IT IS */
    jtemp1 = (integer) oprand[2];
    oprand[1] = pow_di(&oprand[1], &jtemp1);
    goto L270;

/* ...     EXPONENT IS NOT AN INTEGER - IF VALUE TO BE EXPONENTIATED */
/* ...     IS NEGATIVE, ERROR */
L260:
    if (oprand[1] < (float)0.) {
	goto L180;
    }
/* ...     VALUE TO BE RAISED TO A POWER IS POSITIVE - EXPONENTIATE */
    oprand[1] = pow_dd(&oprand[1], &oprand[2]);

/* ...     MOVE THIRD OPERATOR TO SECOND POSITION IN STACK */
L270:
    jopsto[OTHER_ENDIAN_W(1)] = jopsto[OTHER_ENDIAN_W(2)];
/* ...     DECREMENT OPERATOR COUNT, AND GO TO TEST SECOND OPERATOR */
/* ...     FOR ADDITION OR SUBTRACTION */
    --iopno;

/* ...     TWO OPERATIONS IN HOLD - IF SECOND IS ADDITION OR */
/* ...     SUBTRACTION, COMBINE FIRST OPERAND WITH TERM SUMMATION */
/* ...     ACCORDING TO FIRST OPERATOR */
L300:
    if (jopsto[OTHER_ENDIAN_W(1)] > 2) {
	goto L350;
    }

/* ...     BRANCH ON OPERATOR TO ADD THIS TERM TO OR SUBTRACT IT */
/* ...     FROM TOTAL SUMMATION */
    if (jopsto[OTHER_ENDIAN_W(0)] == 2) {
	goto L310;
    }

/* ...     ADD TERM JUST COMPLETED TO TOTAL SUMMATION */
    oprand[0] += oprand[1];
    goto L320;

/* ...     SUBTRACT TERM JUST COMPLETED FROM TOTAL SUMMATION */
L310:
    oprand[0] -= oprand[1];

/* ...     MOVE SECOND OPERATOR TO FIRST POSITION IN STACK */
L320:
    jopsto[OTHER_ENDIAN_W(0)] = jopsto[OTHER_ENDIAN_W(1)];
/* ...     DECREMENT OPERATOR COUNT */
    --iopno;

/* ...     PUT LATEST OPERAND OBTAINED INTO HOLDING STACK */
L350:
    oprand[iopno] = *fnum;

/* ...     TEST FOR END OF STATEMENT - IF NOT, GO TO GET NEXT OPERATOR */
    if (a1com_1.indxpt <= iptlim) {
	goto L100;
    }
/* ...     IT IS - TEST FOR COMPLETION OF EVALUATION AND SUMMATION */
/* ...     OF TERMS */
    if (iopno != 1) {
	goto L360;
    }
/* ...     ONE OPERATOR IN HOLD - MAKE SURE IT IS A DUMMY OPERATOR, */
/* ...     NOT ONE OF THOSE INPUT */
    if (jopsto[OTHER_ENDIAN_W(0)] == 0) {
	goto L370;
    }

/* ...     NO - SET UP A ZERO OPERATOR TO FORCE COMPLETION OF THE */
/* ...     COMPUTATION, AND RETURN THROUGH EVALUATION LOOP UNTIL DONE */
L360:
    jopsto[OTHER_ENDIAN_W(3)] = 0;
    goto L120;

/* .. */
/* ..   OUTPUT FINAL RESULT OF THIS EXPRESSION */
L370:
    ascalr_1.scalr[istore - 1] = oprand[0];
    if (a1com_1.kdbug == 0) {
	goto L410;
    }
/* ...     IF DEBUG OUTPUT DESIRED, PRINT RESULT OF COMPUTATION */
    io___27.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___27);
    do_fio(&c__1, (char *)&ascalr_1.scalr[istore - 1], (ftnlen)sizeof(
	    doublereal));
    e_wsfe();
L410:
    return 0;
/* .. */
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. */
/* .. VOCABULARY WORD CAN ONLY BE A COMPUTING FUNCTION(PROTAP CLASS 8) */
L500:
    if (*kreslt == 8) {
	goto L501;
    }
    if (*kreslt != 2) {
	goto L955;
    }
    isign = *kreslt;
/* ...     MAKE SURE CODE IS WITHIN ALLOWABLE RANGE */
/* .. VOC. CODES TO KEEP IN MIND  -- LINE 7,2--CONE 10,8--REFSYS 1,8,0,0 */
L501:
    if (*kstype > 15) {
	goto L920;
    }
    if (*kstype < 1) {
	goto L920;
    }
/* .. IT IS  -- SAVE VOC. SUBCLASS TYPE FOR LATER */
/* ...     BRANCHING TO SPECIFIC FUNCTION PROCESSING */
    jtemp1 = *kstype;

/* ...     COMPUTING FUNCTIONS AVAILABLE ARE ORDERED AS FOLLOWS - */
/* ...           1.  DOTF   (VECTOR OR POINT, VECTOR OR POINT) */
/* ...           2.  LNTHF  (VECTOR OR POINT) */
/* ...           3.  SQRTF  (SCALAR) */
/* ...           4.  SINF   (SCALAR) */
/* ...           5.  COSF   (SCALAR) */
/* ...           6.  EXPF   (SCALAR) */
/* ...           7.  LOGF   (SCALAR) */
/* ...           8.  ATANF  (SCALAR) */
/* ...           9.  ABSF   (SCALAR) */
/* ...          10.  ANGLF  (CIRCLE, POINT) */
/* ...          11.  NUMF   (PATTERN) */
/* ...          12.  LOG10F (SCALAR) */
/* ..           13.  TANF   (SCALAR) */
/* ..           14.  ATAN2F (SIN,COS) */
/* ...          15.  DISTF  (LINE OR PLANE, LINE OR PLANE) */
/* .. */
/* .. */

/* .. */
/* ... FUNCTIONS MUST BE FOLLOWED BY A NEST ENTRY */
/* .. CODES FOR NESTS ARE AS FOLLOWS ........ */
/* .. 3 SCALAR IN WORKING STORAGE,,5 SURF. IN WORKING STORAGE,,9 ARG.LIST */
    ipt = (a1com_1.indxpt << 1) - 1;
    if (iptpp[OTHER_ENDIAN_S(ipt - 1)] == 3) {
	goto L520;
    }
    if (iptpp[OTHER_ENDIAN_S(ipt - 1)] == 5) {
	goto L520;
    }
    if (iptpp[OTHER_ENDIAN_S(ipt - 1)] != 9) {
	goto L950;
    }
/* ... SET PTPP INDEX TO POINT TO THE NEXT AVAILABLE SLOT */
    a1com_1.indxpt += 2;
/* ..   GET POINTER TO REFERENCE WORD IN CANON */
    ipt = ((iptpp[OTHER_ENDIAN_S(ipt + 2)] + a1pas2_1.icanst - 1) << 1) - 1;
/* .. SAVE ARG. LIST TYPE...1 ALL SCALARS, 2 ALL SURF.,,3 MIXED, 9 ERROR */
    lst = (shortint) iptpp[OTHER_ENDIAN_S(ipt)];
    if (lst == 9) {
	goto L1000;
    }
/* .. */
/* ..  GET ADDRESS OF ARGUMENT STRING IN CANON */
    ipt = iptpp[OTHER_ENDIAN_S(ipt - 1)];
    ipt = (ipt << 1) - 1;
/* .. */
/* ..   NUMBER OF INPUT ARGUMENTS */
    narg = (shortint) iptpp[OTHER_ENDIAN_S(ipt)];
    if (narg > 2) {
	goto L945;
    }
    if (narg < 1) {
	goto L945;
    }
/* .. SET LOC. OF FIRST 8-BYTE ENTRY IN CANON FOR THIS STRING */
    l8 = (ipt + 1) / 2 + 1;
/* ...  PICK UP NO. OF 8-BYTES WORDS TO BE MOVED FROM CANON */
    nt = iptpp[OTHER_ENDIAN_S(ipt - 1)] - 1;
/* ..  ONLY ALL SURF. OR ALL SCALAR INPUT ARGUMENTS ALLOWED */
    if (lst < 1) {
	goto L970;
    }
    if (lst >= 3) {
	goto L970;
    }
/* ..  PROCESS SINGLE INPUT ARGUMENTS, SCLAR */
    if (narg != 1) {
	goto L510;
    }
    if (lst != 1) {
	goto L502;
    }
/* ..  USING THE PROPER FUNCTION FOR A SINGLE SCALAR ARGUMENT */
    if (jtemp1 <= 2) {
	goto L979;
    }
    if (jtemp1 >= 14) {
	goto L945;
    }
    if (jtemp1 == 10) {
	goto L979;
    }
    if (jtemp1 == 11) {
	goto L979;
    }
/* .. SET FNUM TO SCALAR VALUE, AND BRANCH TO PROCESSING AREA */
    *fnum = canon[l8 - 1];
    goto L535;
/* .. */
/* .. SINGLE SURFACE INPUT ARGUMENT, LEGAL ON LNTHF OR NUMF */
/* .. SET SURFACE PARAMETERS INTO DEFST/DEFANS AREA */
L502:
    ioprnd[OTHER_ENDIAN_S(0)] = iptpp[OTHER_ENDIAN_S(ipt + 2)];
    ioprnd[OTHER_ENDIAN_S(1)] = 0;
    isnd = nt + 4;
    ++l8;
/* ... */
    i__1 = isnd;
    for (a1pas2_1.i__ = 4; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	adfsto_1.defsto[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L504: */
	++l8;
    }
/* .. */
/* .. BRANCH TO PROCESSING AREA */
    if (jtemp1 == 2) {
	goto L580;
    }
    if (jtemp1 == 11) {
	goto L700;
    }
    goto L970;
/* ... */
/* .. 2 INPUT ARG., ATAN2F REQUIRES SCALARS */
/* .. 2 SURFACES FOR DOTF, ANGLF, OR DISTF */
L510:
    if (jtemp1 == 14) {
	goto L690;
    }
    if (lst != 2) {
	goto L970;
    }
    if (jtemp1 == 1) {
	goto L540;
    }
    if (jtemp1 == 10) {
	goto L720;
    }
    if (jtemp1 == 15) {
	goto L740;
    }
/* .. */
/* ...     PROCESSOR ERROR */
/* L514: */
    a1com_1.jsuber = 6214;
    goto L1000;
/* .. */
/* .. */
/* .. A DEFINED SURFACE IS AN ACCEPTABLE ARG. FOR LNTHF OR NUMF ONLY */
L520:
    agtarg_(&adfsto_1.defsto[3], &c__85, &jpt);
    if (a1com_1.jsuber != 0) {
	goto L1000;
    }
    if (jpt == 7) {
	goto L1000;
    }
    if (jpt == 1) {
	goto L530;
    }
    if (jpt != 2) {
	goto L970;
    }
    if (jtemp1 == 2) {
	goto L580;
    }
    if (jtemp1 == 11) {
	goto L700;
    }
    goto L945;
/* ... */
/* .. TEST FOR FUNCTIONS REQUIRING SCALAR ARGUMENT AS INPUT */
/* .. */
L530:
    *fnum = adfsto_1.defsto[3];
L535:
    switch ((int)jtemp1) {
	case 1:  goto L979;
	case 2:  goto L979;
	case 3:  goto L600;
	case 4:  goto L610;
	case 5:  goto L620;
	case 6:  goto L630;
	case 7:  goto L640;
	case 8:  goto L650;
	case 9:  goto L660;
	case 10:  goto L979;
	case 11:  goto L979;
	case 12:  goto L670;
	case 13:  goto L680;
	case 14:  goto L945;
	case 15:  goto L979;
    }
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* ..       D O T F */
/* ... */
/* .. STORE FIRST SURFACE TO DOTF, ONLY A VECTOR OR POINT IS ALLOWABLE */
L540:
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	store[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L550: */
	++l8;
    }
/* .. */
/* ..  ERROR IF SURFACE CODES DO NOT MATCH */
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	adfsto_1.defsto[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L560: */
	++l8;
    }
/* .. */
    if (adfsto_1.defsto[0] != store[0]) {
	goto L980;
    }
/* .. */
/* .. */
    adot_(&store[1], &adfsto_1.defsto[1], fnum);
/* .. */
    goto L585;
/* .. */
/* .. */
/* ...  L N T H F */
/* .. */
L580:
    if (ioprnd[OTHER_ENDIAN_S(0)] == 1) {
	goto L581;
    }
    if (ioprnd[OTHER_ENDIAN_S(0)] != 11) {
	goto L970;
    }
L581:
    alngth_(&adfsto_1.defsto[3], fnum);
/* .. */
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. IS A NEG. SIGN PENDING */
L585:
    if (isign == 2) {
	*fnum = -(*fnum);
    }
    isign = 0;
/* .. */
/* .. IF THIS PTPP RECORD IS A COMPUTING EXPRESSION  -- PLACE FNUM IN */
/* .. THE OPERAND STACK AND GET THE ARITHMETIC OPERATOR (VIA BR TO 120) */
/* .. */
    goto L120;
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. */
/* .. */
/* ...           S Q U A R E  R O O T */
/* ...     TEST FOR NEGATIVE OR ZERO ARGUMENT - IF NEGATIVE, ERROR */
L600:
    if (*fnum < 0.) {
	goto L602;
    } else if (*fnum == 0) {
	goto L585;
    } else {
	goto L605;
    }
L602:
    a1com_1.jsuber = 67;
    *fnum = abs(*fnum);
L605:
    *fnum = sqrt(*fnum);
    goto L585;

/* ...           S I N E */
L610:
    *fnum = sin(*fnum * (float).01745329252);
    goto L585;

/* ...           C O S I N E */
L620:
    *fnum = cos(*fnum * (float).01745329252);
    goto L585;

/* ...           E X P O N E N T I A T I O N */
L630:
    *fnum = exp(*fnum);
    goto L585;

/* ...           L O G A R I T H M */
L640:
    *fnum = log(*fnum);
    goto L585;

/* ...           A R C T A N G E N T */
L650:
    *fnum = atan(*fnum) * (float)57.29577951289617;
    goto L585;

/* ...           A B S O L U T E  V A L U E */
L660:
    *fnum = abs(*fnum);
    goto L585;

/* ... */
/* ..          L O G 1 0 F (SCALAR) */
/* .. */
L670:
    *fnum = d_lg10(fnum);
/* .. */
    goto L585;
/* .. */
/* .. */
/* ...         T A N F  (SCALAR) */
/* .. */
L680:
    *fnum = tan(*fnum / (float)57.29577951289617);
/* .. */
    goto L585;
/* .. */
/* .. */
/* .. */
/* ...      A T A N 2 F (SIN,COS) */
/* .. */
/* ...   ERROR BRANCH IF NOT SCALAR LIST  INPUT ARGUMENTS */
L690:
    if (lst != 1) {
	goto L970;
    }
/* .. STORE THE TWO INPUT SCALARS */
    store[0] = canon[l8 - 1];
    adfsto_1.defsto[0] = canon[l8];
/* .. */
    *fnum = atan2(store[0], adfsto_1.defsto[0]);
    *fnum *= (float)57.29577951289617;
/* .. */
    goto L585;
/* .. */
/* .. */
/* ...        N U M F (PATTERN) */
/* ..   IS THE INPUT SURFACE THE REQUIRED PATTERN */
L700:
    if (ioprnd[OTHER_ENDIAN_S(0)] != 18) {
	goto L970;
    }
/* .. */
/* ..     YES  IT  IS */
/* .. */
    *fnum = (doublereal) ((kdfans[OTHER_ENDIAN_W(10)] - 1) / 3);
/* .. */
    goto L585;
/* .. */
/* .. */
/* ...       A N G L F (CIRCLE, POINT) */
/* .. */
/* ... */
/* ..  STORE FIRST ARGUMENT,, ERROR IF NOT A CIRCLE */
L720:
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 8; ++a1pas2_1.i__) {
	store[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L730: */
	++l8;
    }
/* .. */
    if (ksto[OTHER_ENDIAN_S(1)] != 4) {
	goto L980;
    }
/* .. SECOND ARGUMENT MUST BE A POINT */
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	adfsto_1.defsto[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L735: */
	++l8;
    }
/* .. */
    if (ioprnd[OTHER_ENDIAN_S(1)] != 1) {
	goto L970;
    }
/* .. */
/*        POINT MUST NOT BE CONGRUENT WITH CENTER OF CIRCLE */
    if ((d__1 = store[1] - adfsto_1.defsto[1], abs(d__1)) > 1e-6) {
	goto L737;
    }
    if ((d__1 = store[2] - adfsto_1.defsto[2], abs(d__1)) <= 1e-6) {
	goto L970;
    }
L737:
/* .. */
    *fnum = atan2(adfsto_1.defsto[2] - store[2], adfsto_1.defsto[1] - store[1]
	    );
    *fnum *= (float)57.29577951289617;
    if (*fnum < 0.) {
	*fnum += (float)360.;
    }
/* .. BRANCH TO PLACE FNUM INTO OPERAND STACK. */
    goto L585;
/* .. */
/* ...       D I S T F ( LINE, LINE) */
/* ..                  (PLANE,PLANE) */
/* .. */
/* .. PUT SURFACES INTO NORMAL FORM USING ACANCK (ARG IN DEFANS), THEN */
/* .. SET UP 1ST SURFACE CANON FORM INTO STORE ARRAY, 2ND INTO DEFSTO */
/* .. */
L740:
    store[0] = canon[l8 - 1];
    ++l8;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	defans[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L742: */
	++l8;
    }
    acanck_(&ksto[OTHER_ENDIAN_S(1)]);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
/* L745: */
	store[a1pas2_1.i__] = defans[a1pas2_1.i__ - 1];
    }
/* .. */
    adfsto_1.defsto[0] = canon[l8 - 1];
    ++l8;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
	defans[a1pas2_1.i__ - 1] = canon[l8 - 1];
/* L747: */
	++l8;
    }
    acanck_(&ioprnd[OTHER_ENDIAN_S(1)]);
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= 4; ++a1pas2_1.i__) {
/* L750: */
	adfsto_1.defsto[a1pas2_1.i__] = defans[a1pas2_1.i__ - 1];
    }
/* .. */
/* .. DO WE HAVE A LINE OR PLANE */
    if (ksto[OTHER_ENDIAN_S(1)] == 2) {
	goto L755;
    }
    if (ksto[OTHER_ENDIAN_S(1)] != 3) {
	goto L970;
    }
/* .. */
/* ...  DO INPUT SURFACE CODES MATCH */
L755:
    if (ksto[OTHER_ENDIAN_S(1)] != ioprnd[OTHER_ENDIAN_S(1)]) {
	goto L980;
    }
/* .. */
/* ..  ARE THE VECTORS PARRALLEL */
    adot_(&store[1], &adfsto_1.defsto[1], fnum);
    if ((d__1 = abs(*fnum) - 1., abs(d__1)) > 1e-8) {
	goto L970;
    }
/* ..     ARE DIRECTIONS OPPOSITE OR THE SAME */
    if (*fnum >= 0.) {
	goto L760;
    } else {
	goto L765;
    }
/* .. */
/* .. DIRECTION ARE THE SAME */
L760:
    *fnum = (d__1 = store[4] - adfsto_1.defsto[4], abs(d__1));
    goto L585;
/* .. */
/* .. DIRECTIONS ARE OPPOSITE */
L765:
    *fnum = (d__1 = store[4] + adfsto_1.defsto[4], abs(d__1));
    goto L585;
/* .. */
/* .. */
/* ...         ***                ****               ****         **** */
/* .. */
/* .. */
/* ... */
/* .. */

/* ...     ILLEGAL OR NO PUNCTUATION FOUND WHERE OPERATOR REQUIRED */
L900:
    a1com_1.jsuber = 54;
    goto L1000;
/* .. */

/* ...     EXPRESSION ENDED WITH OPERATOR NOT FOLLOWED BY OPERAND */
L910:
    a1com_1.jsuber = 53;
    goto L1000;

/* ...     OPERAND WAS NOT A SCALAR OR A LEGAL VOCABULARY WORD */
L920:
    a1com_1.jsuber = 61;
    goto L1000;

/* ...     MORE CONSECUTIVE EXPONENTIATION OPERATIONS THAN ALLOWABLE */
L930:
    a1com_1.jsuber = 56;
    goto L1000;

/* ...     ATTEMPT MADE TO DIVIDE BY ZERO VALUE */
L940:
    a1com_1.jsuber = 63;
    goto L1000;
/* .. */
/* .. */
/* ...  IMPROPER NUMBER OF ARGUMENTS GIVEN FOR THIS ARITHMETIC FUNCTION */
L945:
    a1com_1.jsuber = 65;
    goto L1000;
/* .. */
/* .. */

/* ...     NO NEST FOUND IMMEDIATELY FOLLOWING A COMPUTING FUNCTION */
L950:
    a1com_1.jsuber = 59;
    goto L1000;

/* ..   ILLEGAL USE OF A VOCABULARY WORD */
L955:
    a1com_1.jsuber = 76;
    goto L1000;

/* .. */
/* .. */
/* .. ILLEGAL ARGUMENT GIVEN FOR AN ARITHMETIC FUNCTION */
L970:
    a1com_1.jsuber = 66;
    goto L1000;
/* .. */
/* .. */
/* .. PARAMETER SHOULD HAVE BEEN A SURFACE */
L979:
    a1com_1.jsuber = 79;
    goto L1000;
/* .. */
/* .. */
/* .. SURFACE CODES DO NOT MATCH. */
L980:
    a1com_1.jsuber = 80;
    goto L1000;
/* ... */
/* ..  VARIABLE IS A PREVIOUSLY DEFINED STATEMENT I.D. */
L985:
    a1com_1.jsuber = 251;
    a2cls7_1.ename = *fnum;
    goto L1000;
/* ... */
/* ... */
/* ... ERROR RETURN PUT SPECIAL CODE INTO SCALAR RESULTS SLOT */
/* ... */
L1000:
    istore = (istore << 1) - 1;
    iscalr[OTHER_ENDIAN_S(istore - 1)] = 0;
    iscalr[OTHER_ENDIAN_S(istore)] = 9;
    return 0;
} /* acls12_ */

#undef kreslt
#undef kstype
#undef oprand
#undef ioprnd
#undef jopsto
#undef iscalr
#undef kdfans
#undef defans
#undef deftab
#undef iptpp
#undef store
#undef kfnum
#undef canon
#undef ptpp
#undef ksto
#undef fnum


