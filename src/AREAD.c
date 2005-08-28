/* AREAD.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

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
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__2 = 2;
static integer c__7 = 7;
static integer c__0 = 0;
static integer c__14 = 14;

/* Subroutine */ int aread_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_23 = { {'(', 'E', 'N', 'D', 'P', 'C', 'H', ')'}, 0. };

#define endpch (*(doublereal *)&equiv_23)


    /* Format strings */
    static char fmt_60[] = "(9a8)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe();

    /* Local variables */
    static doublereal card[10];
    static integer iret;
    static doublereal subs;
    static integer type1, i__, j, m, comma, slash;
    extern doublereal afull8_();
    static integer ia;
    extern /* Subroutine */ int avs1pt_();
    static integer ie, jk;
    extern /* Subroutine */ int adiagp_();
    static integer in, kp;
    extern /* Subroutine */ int apread_();
    static integer no, is;
    extern integer aextra_();
    static integer ksuber;
    extern integer iatype_();
    extern /* Subroutine */ int aprfix_(), aptput_();
#define ipt ((integer *)&aptpp_1)

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 0, 0, fmt_60, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_60, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_60, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */

/* ...  THIS PROGRAM PROCESSES READ/1 OR READ/1,LIST STATEMENTS AND */
/* ...  GENERATES CLASS 14 OR CLASS 12 AND 13 PTPP ENTRIES AS THE */
/* ...  INPUT IS A SURFACE OR SCALAR DEFINITION, RESPECTIVELY. */




/*      INTEGER*4 TYPE1/Z00000001/ */
/*      INTEGER*4 SLASH/Z00000304/ */
/*      INTEGER*4 COMMA/Z00000904/ */
	type1=0x1;
	slash=0x304;
	comma=0x904;
/* ...  IF KSUBER IS NOT ZERO THEN ALL PUNCH BLOCK CARDS WILL FLUSH THRU */
/* ...  IN SEARCH OF THE ENDPCH CARD WHICH WILL CAUSE A RETURN TO CALLING */
/* ..    PROGRAM */
    ksuber = 0;
    a1com_1.name__ = (float)0.;
    subs = (float)0.;
    aptpp_1.npt = 0;
    abreak_1.inill += 2;
/* ...  TEST FOR THE REQUIRED SLASH FOLLOWING MAJ. WORD..READ. */
    if (ailmtb_1.iclass[abreak_1.inill - 2] != slash) {
	goto L2155;
    }
/*     MUST HAVE READ/1 OR READ/2 */
    if (iatype_(&abreak_1.inill) != 3) {
	goto L3000;
    }
    if (ailmtb_1.elment[abreak_1.inill - 1] == 1.) {
	goto L5;
    }
    if (ailmtb_1.elment[abreak_1.inill - 1] != 2.) {
	goto L3000;
    }
/* ...  BRANCH IF READ/2 ALREADY IN EFFECT */
    if (alibry_1.irdmod > 0) {
	goto L3030;
    }
/* ...  BRANCH IF A READ/2 STATEMENT WAS FOUND IN A LOOP OR MACRO */
    if (a1com_1.loop > 0) {
	goto L3037;
    }
/*     CHECK FOR COMMA AFTER READ/2 */
    if (ailmtb_1.iclass[abreak_1.inill] != comma) {
	goto L3000;
    }
/*     READ/2,MEMNAME - CHECK FOR MEMBER NAME */
    i__1 = abreak_1.inill + 2;
    if (iatype_(&i__1) != 1) {
	goto L3000;
    }
    if (abreak_1.inill + 2 != ailmtb_1.jlment) {
	goto L3040;
    }
/*     SAVE MEMBER NAME */
    alibry_1.segnam = ailmtb_1.elment[abreak_1.inill + 1];
/*     SET FLAG TO READ FROM PDS */
    alibry_1.irdmod = 1;
/*     RETURN - NEXT INPUT WILL COME FROM SEGMENT PDS */
    return 0;
L5:
    ++abreak_1.inill;
L10:
    a1com_1.name__ = (float)0.;
    subs = (float)0.;
    j = 0;
/* ..   BRANCH TO GET NAME VAR. FROM HEX CARD, (THAT IS, THERE IS NO */
/* ...  NAME VARIABLE TO BE GOTTEN FROM THE READ/1 STATEMENT) */
    kp = 0;
    if (abreak_1.inill > ailmtb_1.jlment) {
	goto L50;
    }
/* ...   CHECK FOR SEPARATING COMMA--READ/1,VAR1,VAR2,ETC...... */
    if (ailmtb_1.iclass[abreak_1.inill - 1] != comma) {
	goto L2000;
    }
    ++abreak_1.inill;
    if (abreak_1.inill > ailmtb_1.jlment) {
	goto L2000;
    }
/* ... CHECK FOR REQUIRED VAR.SYMBOL FOLLOWING THE COMMA */
    if (ailmtb_1.iclass[abreak_1.inill - 1] != type1) {
	goto L2000;
    }
/*     PICK UP SYMBOL IN LIST */
    a1com_1.name__ = ailmtb_1.elment[abreak_1.inill - 1];
    ++abreak_1.inill;
/*     SUBSCRIPT */
    ia = iatype_(&abreak_1.inill) - 6;
    if (ia < 1) {
	goto L50;
    }
    ++abreak_1.inill;
    switch ((int)ia) {
	case 1:  goto L15;
	case 2:  goto L20;
	case 3:  goto L30;
    }
/* ...   SCALAR SUBSCRIPT SET PTPP J INDICATOR TO 2 */
L15:
    j = 2;
    goto L40;
/* ... SUBSCRIPT IS NUMERIC,,SET SUBS TO THE VALUE */
L20:
    subs = ailmtb_1.elment[abreak_1.inill - 2];
    goto L50;
/* ...  SUBSCRIPT IS AN EXPRESSION SET PTPP INDICATOR TO 3 */
L30:
    j = 3;
/* .. SET WORKING STORAGE INDEX  THAT IS,  FLAG KP */
/*     THIS IS DONE FOR A SCALAR OR EXPRESSION SUBSCRIPT ONLY */
L40:
    kp = aextra_(&ailmtb_1.elment[abreak_1.inill - 2], &c__4);
/* ... */
/*     PICK UP DEFINITION */
/* ..  BELOW IS CARD ARRAY LAYOUT */
/*        CARD(1) = VAR. NAME  IN EBDIC ,, */
/* .       CARD(2) = FL. PT. SUBSCRIPT  - HEX REPRESENTATION */
/* .       CARD(3) = SURF TYPE, NO  - HEX */
/* .       CARD(4) = REFSYS FLAG - GENERALLY IS HEX ZEROES */
/* .       CARD(5) = 1ST FL.PT. PARAM  - HEX REP. */
/* .       CARD(6) = 2ND    '' */
/* .       CARD(7) = 3RD    ''      IF APPLICABLE */
/* .       CARD(8) = 4TH     ''      '' */
/* .       CARD(9) = 5TH    ''       '' */
/* .. THE SECOND CARD AS FOLLOWS */
/* .       CARD(1) = 6TH FL. PT. PARAM. IN HEX ,,IF APPLICABLE */
/* .       CARD(2) = 7TH   ''        '''       '' */
/* .       CARD(3) = 8TH   ''        '''       '' */
/* ..   AND SO ON AND SO FORTH UNTIL DEFINITION IS COMPLETED, */
/* ..  SE PART PROGRAMMERS GUIDE FOR LIST OF CANONICAL FORMS */
/* .. */
L50:
    if (alibry_1.irdmod != 1) {
	goto L53;
    }
    m = 1;
L51:
    alibry_1.irdmod = 2;
    apread_(card, &alibry_1.irdmod, &alibry_1.segnam, &a1com_1.jsuber);
    if (a1com_1.jsuber != 0) {
	goto L3035;
    }
    if (alibry_1.irdmod == 0) {
	goto L52;
    }
    alibry_1.irdmod = 1;
    switch ((int)m) {
	case 1:  goto L54;
	case 2:  goto L196;
	case 3:  goto L2026;
    }
L52:
    switch ((int)m) {
	case 1:  goto L53;
	case 2:  goto L195;
	case 3:  goto L2025;
    }
L53:
    io___13.ciunit = ataptb_1.intape;
    s_rsfe(&io___13);
    for (i__ = 1; i__ <= 9; ++i__) {
	do_fio(&c__1, (char *)&card[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsfe();
/*     IS THIS END OF DATA */
L54:
    if (card[0] == endpch) {
	goto L1000;
    }
/* ...   THIS IS NOT THE ENDPCH CARD, PROCESS HEX CARD IF NO ERROR EXISTS */
/* ...  FLUSH HEX CARDS IF ERROR CONDITION PREVAILS ON READ/1 STATEMENT */
    if (ksuber != 0) {
	goto L50;
    }
/*     IF NAME=0., NO SYMBOL IN LIST - USE SYMBOL IN DEF. */
/* L61: */
    if (a1com_1.name__ != (float)0.) {
	goto L70;
    }
/* L62: */
    a1com_1.name__ = card[0];
    subs = card[1];
L70:
    avs1pt_(&jk);
    no = aextra_(&card[2], &c__4);
/* ..  IF SUBSCRIPT IS NUMERIC THEN SET PTPP INDICATOR TO 1,(ALWAYS */
/*           A NUMERIC SUBSCRIPT  VALUE WHEN GIVEN ON HEX CARD) */
    if (subs != (float)0.) {
	j = 1;
    }
    if (j != 0) {
	goto L90;
    }
/* ... TEST NON-SUBSCRIPTED VARIABLE */
    switch ((int)jk) {
	case 1:  goto L100;
	case 2:  goto L2015;
	case 3:  goto L2107;
	case 4:  goto L100;
	case 5:  goto L2251;
	case 6:  goto L2109;
	case 7:  goto L2102;
	case 8:  goto L2105;
	case 9:  goto L2105;
	case 10:  goto L2105;
    }
/* ... TEST SUBSCRIPTED VARIABLES */
L90:
    switch ((int)jk) {
	case 1:  goto L2108;
	case 2:  goto L2015;
	case 3:  goto L2108;
	case 4:  goto L2108;
	case 5:  goto L2251;
	case 6:  goto L2108;
	case 7:  goto L2102;
	case 8:  goto L2105;
	case 9:  goto L2106;
	case 10:  goto L2106;
    }
/* ... */
/* ... */
/* .. INITIALIZE VST ENTRY FOR A DIMENSIONED SCLAR (DONE ONCE PER VAR.) */
L99:
    aprfix_(&c__1, &iret);
    amxtab_1.maxscl += (i__1 = aextra_(&avst_1.vst[a1com_1.namsub], &c__4), 
	    abs(i__1));
    goto L110;
/* ... */
/* ...DEFINE NAME...BRANCH IF FOR A SURFACE,OTHERWISE IT IS SCALAR ENTRY */
L100:
    if (no != 4) {
	goto L140;
    }
/* .. */
/* .. */
/* ...  UPDATE NON-SUBSCRIPTED SCALAR TABLE */
L101:
    ++amxtab_1.maxscl;
    avst_1.vst[a1com_1.namsub] = afull8_(&c__2, &amxtab_1.maxscl);
/* ... */
L110:
    aptpp_1.inptp = 5;
    aptpp_1.jmode = 5;
/* ...     SET UP CLASS 13 PTPP RECORD FOR SCALAR */
    aptpp_1.pt[1] = 0.;
    aptpp_1.pt[2] = card[4];
    ipt[OTHER_ENDIAN_S(6)] = 2;
    ipt[OTHER_ENDIAN_S(7)] = j;
    ipt[OTHER_ENDIAN_S(8)] = kp;
    ipt[OTHER_ENDIAN_S(9)] = a1com_1.namsub;
    if (j != 1) {
	goto L120;
    }
    aptpp_1.pt[5] = subs;
    aptpp_1.inptp = 6;
L120:
    ipt[OTHER_ENDIAN_S(0)] = 13;
    ipt[OTHER_ENDIAN_S(1)] = aptpp_1.inptp - 1;
    aptput_();
/* ...  READ NEXT DEFINITION */
    goto L10;
/* ... */
/* .. */
/* ... END OF SCALAR PROCESSING */
/* ..****         ******         *****         *****         **** */
/* .. */
/* ..          P R O C E S S     S U R F A C E */
/* .. */
/* ... INITITIALIZE VST ENTRY FOR A DIMENSIONED SURFACE */
L130:
    aprfix_(&c__2, &iret);
    goto L150;
/* .. */
/* ... NON-DIMENSIONED SURFACE..UPDATE VST INDEX */
L140:
    avst_1.vst[a1com_1.namsub] = afull8_(&c__7, &c__0);
/* .. */
/* .. OUTPUT PTPP CLASS 14 RECORD */
/* .. */
/* ..  NO  IS COUNT OF ENTRIES ASSOCIATED WITH THIS DEFINITION.. */
/* ..  FOR SCALARS AND NON-LARGE SURFACES THE VALUE REPRESENTS..3 HEADER */
/* ... ENTRIES ( ALWAYS ) PLUS THE NUMBER OF FL.PT. PARAMS IN THE DEF. */
L150:
    if (no != 5) {
	goto L160;
    }
/* ..  THIS IS A LARGE SURFACE DEFINITION */
/* ..    NO - IS EXACT NO.OF PARMS TO PROCESS,ADD 3 FOR HEDER INFO */
    no = aextra_(&card[3], &c__4) + 3;
/* .. */
L160:
    no += -3;
/* .. COMPUTE NW,,THE TOT. NO. OF 8-BYTE WD.S IN THIS PTPP CLASS 14 REC. */
/* ..   MUST BE 2 PTPP ENTRIES TO DESCRIBE EACH INPUT PARAMETER */
/* ..NO IS THE NO. OF INPUT PARAMETERS,,4 IS NO. OF ENTRIES FOR PTPP HDR, */
    aptpp_1.nw = (no << 1) + 4;
/* .. PTPP OUTPUT 1ST PORTION OF DATA TO PTPP FOR THIS SURF DEFINITION */
    aptpp_1.jmode = 1;
    aptpp_1.pt[0] = afull8_(&c__14, &c__0);
    aptpp_1.pt[1] = afull8_(&c__0, &no);
    aptpp_1.pt[2] = afull8_(&c__4, &j);
    aptpp_1.pt[3] = afull8_(&kp, &a1com_1.namsub);
    aptpp_1.pt[4] = card[2];
    aptpp_1.inptp = 6;
    if (j != 1) {
	goto L170;
    }
    aptpp_1.pt[4] = subs;
    aptpp_1.pt[5] = card[2];
    aptpp_1.inptp = 7;
    ++aptpp_1.nw;
L170:
    no += 4;
    is = 5;
    ie = 9;
    if (ie > no) {
	ie = no;
    }
    in = ie;
L180:
    i__1 = ie;
    for (j = is; j <= i__1; ++j) {
	aptpp_1.pt[aptpp_1.inptp - 1] = afull8_(&c__1, &c__0);
	aptpp_1.pt[aptpp_1.inptp] = card[j - 1];
/* L190: */
	aptpp_1.inptp += 2;
    }
    --aptpp_1.inptp;
    if (in == no) {
	goto L200;
    }
    aptput_();
    aptpp_1.jmode = 2;
    aptpp_1.inptp = 1;
    is = 1;
    in += 9;
    if (alibry_1.irdmod != 1) {
	goto L195;
    }
    m = 2;
    goto L51;
L195:
    io___21.ciunit = ataptb_1.intape;
    s_rsfe(&io___21);
    for (i__ = 1; i__ <= 9; ++i__) {
	do_fio(&c__1, (char *)&card[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsfe();
/*     IS THIS END OF DATA */
L196:
    if (card[0] == endpch) {
	goto L1000;
    }
    if (in < no) {
	goto L180;
    }
/*     LAST CARD FOR THIS DEFINITION */
    ie = no + 9 - in;
    in = no;
    goto L180;
/* ... THIS IS THE FINAL DATA TO BE MOVED TO PTPP FOR THIS SURF. DEF. */
L200:
    aptpp_1.jmode = 3;
    aptput_();
    goto L10;
/* .. */
/* .. IF READ ZARG. LIST IS NOT COMPLETED, PRINT 1ST DANGLING NAME AND */
/* ..   RETURN TO THE CALLING PROGRAM. */
L1000:
    if (a1com_1.name__ == (float)0.) {
	return 0;
    }
    a1com_1.jsuber = 2002;
    goto L2017;
/* ... */
/* .. I/O FORMAT ERROR, FLUSH REMAINING DATA CARDS */
/* .. */
L2000:
    a1com_1.jsuber = 2000;
    goto L2016;
/* .... */

/* .. VST OVFLO, OUTPUT OFFENDING VARIABLE AND FLUSH REMAINING DATA CARDS */
/* .. */
L2015:
    a1com_1.jsuber = 15;
L2016:
    ksuber = 1;
/* .. SUM = 9 INDICATES TO ADIAGP TO OUPUT  NAME AND SUBSCRIPT */
L2017:
    a1com_1.sum = 9;
/* ..  PT(6) IS THE NAME AND IS SET BY ADIAGP, SUBS VAL. MUST BE SET HERE */
    aptpp_1.pt[6] = subs;
/* .. SUM = 1 INDICATES  VARIABLE NAME WAS NOT SUBSCRIPTED */
    if (subs == (float)0.) {
	a1com_1.sum = 1;
    }
/* .. SUM = 0 INDICATES NO VARIABLE ASSOCIATED WITH THIS ERROR MESSAGE */
    if (a1com_1.name__ == (float)0.) {
	a1com_1.sum = 0;
    }
/* ..  OUTPUT CLASS2 PTPP RECORD....(ERROR DIAGNOSTIC) */
    adiagp_();
/* .. RESET VARIABLES TO PREVENT REDUNDANT ERROR MESSAGES FROM FUTHER */
/*     PROCESSING BY OTHER SUBROUTINES.. */
    a1com_1.jsuber = 0;
    a1com_1.name__ = (float)0.;
/* .. ALL ERROR MESSAGES HAVE BEEN PROCESSED, ARE THERE MORE DATA CARDS */
    if (card[0] == endpch) {
	return 0;
    }
/* ..  THERE ARE MORE DATA CDS...PROCESS OR FLUSH THEM ALL */
    if (ksuber != 0) {
	goto L50;
    }
/* .. PROCESS THEM..BUT DELETE THE ONES ASSOCIATED WITH THIS DEFINITION */
    if (no <= 8 && no != 5) {
	goto L10;
    }
/* ... ERROR VAR. WAS A SURF. DEF. OTHER THAN A POINT,VECTOR,LINE, */
/* ...  PLANE, OR SPHERE...DELETE THE ASSOCIATED PARAMETER CARDS. */
/* ...    THEN READ-IN NEXT HEX CARD AND PROCESS IT IN THE NORMAL MODE. */
/* .. */
/* .. */
/* ...ERROR  READ-LOOP  AREA */
/* .. */
/* ... CALC. NO. OF PARAMETERS FOR THIS SURF. DEF. */
/* ... FOR A LARGE SURF. CARD(4) IS THE EXACT NO. OF PARMS. TO BE GOTTEN */
/* ..  ADD 3 TO ALLOW FOR HEADER ENTRIES ASSOCIATED WITH THIS LRG.SURF. */
    if (no == 5) {
	no = aextra_(&card[3], &c__4) + 3;
    }
    in = 9;
/* ... ADD 1 TO PARM COUNT, THIS ALLOWS FOR FIELD ON CARD SET ASIDE FOR */
/* ..  REFSYS FLAG WHICH HAS NOT BEEN INCLUDED IN CAN.FORM LENGTH COUNT */
    ++no;
/* ... DESTRUCTIVE READ-IN  OF CARD ARRAY */
L2020:
    if (alibry_1.irdmod != 1) {
	goto L2025;
    }
    m = 3;
    goto L51;
L2025:
    io___22.ciunit = ataptb_1.intape;
    s_rsfe(&io___22);
    for (i__ = 1; i__ <= 9; ++i__) {
	do_fio(&c__1, (char *)&card[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsfe();
/* ..   ENDPCH STATEMENT TERMINATES READING OF HEX CARDS */
L2026:
    if (card[0] == endpch) {
	goto L1000;
    }
    no -= in;
/* ..   HAVE WE READ-IN THE LAST CARD ASSOCIATED WITH THIS DEFINITION */
    if (no <= in) {
	goto L10;
    }
/* ..  READ-IN NEXT CARD ASSOCIATED WITH THIS DEFINITION */
    goto L2020;
/* ... */
/* ....******           *****           ****       ****          *** */
/*          ERROR   MESSAGES */
/* .. */
/* ... */
/* .. O.K. IF VAR. IS DIMEN. BUT NOT USED,, ER.211 IF VAR IS MACRO NAME */
/* ..  TEST VST ENTRY TO SEE IF THIS IS A DIMENSIONED VAR.,BR. TO 2103 IF */
/* .. IT IS, OTHERWISE IT IS A MACRO NAME AND IS IN ERROR. */
L2102:
    if (aextra_(&avst_1.vst[a1com_1.namsub], &c__4) < 0) {
	goto L2103;
    }
    a1com_1.jsuber = 211;
    goto L2017;
/* ... DIMENSIONED ARRAY NOT USED,INITIALIZE VST ENTRY TO DIM.SURF. */
L2103:
    if (j == 0) {
	goto L2105;
    }
/* ... SUBSCRIPTED, SCALAR OR SURF.( BR. IF .SURF.) */
    if (no != 4) {
	goto L130;
    }
/* .. INITIALIZE VST ENTRY FOR A DIMEN.SCALAR */
    goto L99;
/* ... */
/* .. */
/* ... NO SUBSCRIPT VALUE GIVEN WITH INPUT VAR. AND IT NEEDS ONE */
L2105:
    a1com_1.jsuber = 105;
    goto L2017;
/* ... */
/* ... VST SHOWS A PREVIOUSLY DEFINED SCALAR OR SURF. (DIMENSIONED) */
/* .. BR TO NORM PROCESS THIS DIMENSIONED SCALAR IF VST ENTRY */
/* ...    SHOWS ARRAY IS  FOR SCALARS */
L2106:
    if (no == 4 && jk == 9) {
	goto L110;
    }
/* ... BR TO 150 TO NORMAL PROCESS THIS HEX DIMENSIONED SURF. VAR., IF */
/* ...  VST ENTRY SHOWS ARRAY IS FOR SURFACES */
    if (no != 4 && jk == 10) {
	goto L150;
    }
/* .. */
/* .. SCALAR ARRAY CONTAINS A SURFACE OR VISA VERSA */
/* .. */
    a1com_1.jsuber = 106;
    goto L2017;
/* ... */
/* .. */
/* .. NON-SUBSC. VAR. WAS A DEFINED SURF..O.K. IF CURRENT DEF. IS SAME */
L2107:
    if (no == 4) {
	goto L2110;
    }
/* .. THIS MUST BE A SURFACE DEF., OUTPUT A CLASS 14 PTPP REC. */
    goto L150;
/* ... */
/* ... */
/*     SUBSCRIPT FOUND FOR VAR. NAME WHICH WAS NOT GIVEN IN A RESERV STMT */
L2108:
    a1com_1.jsuber = 108;
    goto L2017;
/* ... */
/* ... */
/* ..NON-SUBSCR. VAR. WAS DEFINED A SCALAR,O.K. IF CURRENT DEF. IS SAME */
L2109:
    if (no == 4) {
	goto L101;
    }
/* ... ERROR..TRIED TO REDEFINE A SCALAR AS A SURFACE OR VISA VERSA */
L2110:
    a1com_1.jsuber = 2001;
    goto L2017;
/* ... */
/* ... */
/*        I/O FORMAT ERROR NO SLASH FOLLOWING MAJ.VOC.WORD READ */
/* ...   FLUSH REMAINING HEX DATA CARDS */
L2155:
    a1com_1.jsuber = 155;
    if ((doublereal) ailmtb_1.iclass[abreak_1.inill - 1] == 1.) {
	goto L2016;
    }
    goto L3035;
/* ... */
/* .. VAR. NAME IS A PREV. DEFINED STMT ID */
L2251:
    a1com_1.jsuber = 251;
    goto L2017;
L3000:
    card[0] = endpch;
    goto L2000;
/* ...  READ/2 CANNOT READ IN ANOTHER READ/2 STATEMENT */
L3030:
    a1com_1.jsuber = 30;
L3035:
    card[0] = endpch;
    goto L2016;
/* ...  A READ/2 STATEMENT WAS FOUND IN A LOOP OR MACRO */
L3037:
    a1com_1.jsuber = 37;
    goto L3035;
/* ...  TOO MANY ENTRIES ON READ/2 STATEMENT */
L3040:
    a1com_1.jsuber = 34;
    goto L3035;
} /* aread_ */

#undef ipt
#undef endpch


