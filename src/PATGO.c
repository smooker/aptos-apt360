/* PATGO.f -- translated by f2c (version 20000121).
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
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

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

struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__2 = 2;
static integer c__0 = 0;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/* Subroutine */ int patgo_()
{
    /* Initialized data */
#ifdef WORDS_BIGENDIAN
//original structure
    static struct {
	integer e_1[8];
	doublereal e_2;
	} equiv_40 = { 5000, 5, 2000, 1054, 0, 71, 0, 53, 0. };
#else//little endian
    static struct {
	integer e_1[8];
	doublereal e_2;
	} equiv_40 = { 5, 5000, 1054, 2000, 71, 0, 53, 0, 0. };

#endif

    /* Format strings */
    static char fmt_2020[] = "(\0020    FNUM =\002,f12.4,\002,  AVOIDZ =\002\
,f12.4,\002,  VOIDLS =\002,f12.4/\0020    IPTDAT\002,4x,5z12,2(/15x,5z12)\
/\0020    IPTFLG\002,4x,5z12,2(/15x,5z12)//)";

    /* System generated locals */
    integer i__1;
    static doublereal equiv_7[1];
    static integer equiv_21[15], equiv_36[15];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
#define fnum (equiv_7)
#define ptpp ((doublereal *)&avst_1)
#define numb1 (equiv_36 + 9)
#define numb2 (equiv_36 + 10)
#define canon ((doublereal *)&avst_1)
#define nomit (equiv_36 + 7)
#define ntain1 (equiv_36 + 6)
#define ntain2 (equiv_21 + 8)
#define jtemp1 (equiv_21 + 7)
#define nvoid2 (equiv_36 + 13)
#define nvoid1 (equiv_36 + 8)
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer jk;
#define defans ((doublereal *)&adfsto_1 + 3)
    static integer ioflag;
#define kdfans ((shortint *)&adfsto_1 + 12)
#define jprcod ((integer *)&equiv_40)
#define idfsto ((integer *)&adfsto_1)
#define jprotp ((integer *)&aprotp_1)
#define iptdat (equiv_21)
#define iptflg (equiv_36)
#define nopflg (equiv_36 + 6)
#define kreslt ((integer *)equiv_7 + OTHER_ENDIAN_S(1))
#define ipatyp (equiv_21)
#define numpts (equiv_21 + 1)
#define nocols (equiv_21 + 2)
#define nptcol (equiv_21 + 3)
#define iptlim (equiv_21 + 4)
#define nextyp (equiv_21 + 5)
#define incrpt (equiv_21 + 6)
#define nextpt (equiv_21 + 10)
#define jendpt (equiv_21 + 11)
#define icoord (equiv_21 + 12)
#define incord (equiv_21 + 13)
#define incout (equiv_21 + 14)
#define invers (equiv_36)
#define izgzag (equiv_36 + 1)
#define iavoid (equiv_36 + 2)
#define listyp (equiv_36 + 3)
#define loptyp (equiv_36 + 4)
#define ireflg (equiv_36 + 5)
#define jmithr (equiv_36 + 11)
#define itrflg (equiv_36 + 12)
#define gotype ((doublereal *)&equiv_40)
#define cyctyp ((doublereal *)&equiv_40 + 1)
#define cyclon ((doublereal *)&equiv_40 + 2)
#define cycoff ((doublereal *)&equiv_40 + 3)
    static doublereal patnam, voidls;
    static integer icolno;
    extern /* Subroutine */ int agtarg_();
    static integer inidir;
    static doublereal avoidz;
    static integer icoltm;
    extern /* Subroutine */ int aserch_(), ataprd_(), atrfrm_(), aritap_();
#define num ((integer *)equiv_7)

    /* Fortran I/O blocks */
    static cilist io___55 = { 0, 6, 0, fmt_2020, 0 };



/*       INTEGER JPRCOD(8)/5000,5,2000,1054,0,71,0,53/ */


/* ...     PUT LENGTH OF GOTO/...-TYPE RECORDS TO BE CREATED */
/* ...     INTO FIRST WORD OF PROTP AREA */
    jprotp[OTHER_ENDIAN_S(0)] = 0;
    jprotp[OTHER_ENDIAN_S(1)] = 6;
/* ...     PUT PATTERN NAME AND SUBSCRIPT INTO OUTPUT AREA FOR */
/* ...     POINTS TO BE WRITTEN ON THE PROTAP */
    aprotp_1.protp[2] = a2cls7_1.ename;
    aprotp_1.protp[3] = (doublereal) a1com_1.namsub;
/* ...     ALSO SAVE NAME FOR POSSIBLE RESTORATION AFTER 'AVOID' */
    patnam = a2cls7_1.ename;

/* ...     COMPUTE INDEX TO END OF STATEMENT IN PTPP */
    *iptlim = a1pas2_1.indexs + a1pas2_1.klasct;
/* ...     DETERMINE PATTERN TYPE AND NUMBER OF POINTS */
    *ipatyp = kdfans[OTHER_ENDIAN_W(8)];
/* ...     IF PARALLEL PATTERN, EXTRACT NUMBER OF COLUMNS */
    if (*ipatyp != 4) {
	goto L70;
    }
    *nocols = kdfans[OTHER_ENDIAN_W(11)];
/* ...     COMPUTE NUMBER OF POINTS IN PATTERN */
L70:
    *numpts = (kdfans[OTHER_ENDIAN_W(10)] - 1) / 3;
/* ...     INITIALIZE END POINT NUMBER OF PATTERN */
    *jendpt = *numpts;

/* ...     MOVE PATTERN TO DEFTAB AREA */
    for (jk = 1; jk <= 3; ++jk) {
/* L75: */
	adfsto_1.defsto[jk + 38] = defans[jk - 1];
    }

/* ...     INITIALIZE ALL FLAGS IN IPTFLG ARRAY TO ZERO */
/* L80: */
    for (*jtemp1 = 1; *jtemp1 <= 15; ++(*jtemp1)) {
/* L90: */
	iptflg[*jtemp1 - 1] = 0;
    }
/* ...     CLEAR FLAG INDICATING AN 'AVOID' CONDITION STILL INCOMPLETE */
    voidls = 0.;

/* ...     TEST FOR PATTERN DEFINED IN ANOTHER REFERENCE SYSTEM */
    if (adfsto_1.defsto[1] == a1com_1.refsys) {
	goto L95;
    }
/* ...     YES - SET FLAG TO INDICATE OUTPUT TO BE TRANSFORMED */
    *itrflg = 1;

/* ...     INITIALIZE INVERS FLAG FOR FORWARD DIRECTION (NO INVERS) */
L95:
    *invers = 1;
/* ...     INITIALIZE NEXT OUTPUT POINT NUMBER TO START OF PATTERN */
    *nextpt = 1;
/* ...     INITIALIZE PARLEL PATTERN COLUMN NUMBER FOR FORWARD DIRECTION */
    icolno = 1;
/* ...     INITIALIZE POINT NUMBER INCREMENT FOR FORWARD DIRECTION */
    *incrpt = 1;
/* ...     INITIALIZE OUTPUT SEQUENCE DIRECTION FLAG FOR FORWARD */
    *incout = 1;

/* ...     TEST FOR END OF PATTERN MODIFIER LIST */
L100:
    if (a1com_1.indxpt < *iptlim) {
	goto L105;
    }
/* ...     YES - SET NEXT MODIFIER TYPE FLAG TO SO INDICATE */
    *nextyp = 0;
    goto L300;

/* ...     NOT END OF LIST - GET NEXT PARAMETER */
L105:
    agtarg_(fnum, &c__1, nextyp);

/* ...     SEE IF NEXT PARAMETER IS A SCALAR */
L108:
    if (*nextyp != 1) {
	goto L110;
    }
/* ...     YES - MUST HAVE ALREADY READ A MODIFIER TO ESTABLISH */
/* ...     USE FOR SCALAR */
    if (*loptyp != 0) {
	goto L215;
    }
/* ...     HAVE NOT HAD A MODIFIER REQUIRING A SCALAR YET - ERROR */
    a1com_1.jsuber = 830;
    goto L2000;

/* ...     NO - MUST THEN BE A VOCABULARY WORD, OR ERROR */
L110:
    if (*nextyp == 5) {
	goto L115;
    }
/* ...     INCORRECT PARAMETER TYPE - ERROR */
L112:
    a1com_1.jsuber = 831;
    goto L2000;

/* ...     VOCABULARY WORD FOUND - IS IT 'OMIT' */
L115:
    if (*kreslt == 172) {
	goto L160;
    }
/* ...     NO - TRY 'RETAIN' */
    if (*kreslt == 171) {
	goto L160;
    }
/* ...     SEE IF IT IS 'AVOID' */
    if (*kreslt == 173) {
	goto L180;
    }
/* ...     IF IT IS NOT 'INVERS', 'ZIGZAG', OR 'CONST' THEN, ERROR */
    if (*kreslt == 6) {
	goto L130;
    }
/* ...     NOT INVERS... */
    if (*kreslt == 64) {
	goto L125;
    }
/* ...     ...OR CONST... */
    if (*kreslt == 170) {
	goto L120;
    }
/* ...     ...AND NOT ZIGZAG - ERROR */
L118:
    a1com_1.jsuber = 832;
    goto L2000;

/* ...     ZIGZAG RECOGNIZED - HAVE WE ALREADY FOUND ONE */
L120:
    if (*izgzag != 0) {
	goto L150;
    }
/* ...     NO - ARE WE OUTPUTTING A PARALLEL PATTERN */
    if (*ipatyp < 4) {
	goto L155;
    }
/* ...     YES - SET FLAG FOR ZIGZAG */
    *izgzag = 1;
/* ...     COMPUTE NUMBER OF POINTS/COLUMN */
    *nptcol = *numpts / *nocols;
/* ...     SET INITIAL OUTPUT SEQUENCE DIRECTION FLAG FOR ZIGZAG */
    inidir = 1;
/* ...     GO TO SEE WHETHER ANY OMIT/RETAIN OR AVOID MODIFIERS */
/* ...     HAVE ALREADY BEEN FOUND */
    goto L118;

/* ...     CONST RECOGNIZED - HAVE WE ALREADY FOUND ONE */
L125:
    if (*ireflg != 0) {
	goto L150;
    }
/* ...     NO - SET FLAG FOR IT */
    *ireflg = 1;
/* ...     IF INVERS FLAG SET, ADJUST REFERENCE POINT LIMITS FOR */
/* ...     REVERSED ORDER */
    if (*invers <= 0) {
	goto L135;
    }
/* ...     GO TO SEE WHETHER ANY OMIT/RETAIN OR AVOID MODIFIERS */
/* ...     HAVE ALREADY BEEN FOUND */
    goto L140;

/* ...     INVERS RECOGNIZED - HAVE WE ALREADY FOUND ONE */
L130:
    if (*invers < 0) {
	goto L150;
    }
/* ...     NO - SET FLAG FOR IT */
    *invers = -1;
/* ...     ADJUST PARLEL PATTERN COLUMN NUMBER FOR INVERS DIRECTION */
    icolno = *nocols;
/* ...     SET INITIAL OUTPUT SEQUENCE DIRECTION FLAG FOR INVERS OR */
/* ...     ZIGZAG, INVERS - THIS FLAG USED ONLY IN ZIGZAG OUTPUT */
    inidir = -1;
/* ...     SET WORKING OUTPUT SEQUENCE DIRECTION FLAG FOR INVERS */
    *incout = -1;
/* ...     IF POINT NUMBERS FOR OPERATIONS REFERENCED TO ORIGINAL */
/* ...     DEFINITION ORDER, ADJUST REFERENCE POINT LIMITS FOR INVERS */
    if (*ireflg == 0) {
	goto L140;
    }
L135:
    *nextpt = *numpts;
    *jendpt = 1;
/* ...     SET POINT NUMBER INCREMENT DIRECTION FOR INVERS */
    *incrpt = -1;

/* ...     ZIGZAG AND INVERS MODIFIERS MUST PRECEDE ANY OMIT/RETAIN */
/* ...     OR AVOID MODIFIERS USED - SEE IF ANY OF THE LATTER HAVE */
/* ...     ALREADY BEEN FOUND */
L140:
    if (*loptyp == 0) {
	goto L100;
    }

/* ...     OMIT/RETAIN OR AVOID MODIFIERS USED BEFORE ZIGZAG OR */
/* ...     INVERS - ERROR */
/* L145: */
    a1com_1.jsuber = 833;
    goto L2000;

/* ...     MORE THAN ONE ZIGZAG OR INVERS MODIFIER FOUND - ERROR */
L150:
    a1com_1.jsuber = 834;
    goto L2000;

/* ...     ZIGZAG MODIFIER FOUND FOR NON-PARALLEL PATTERN - ERROR */
L155:
    a1com_1.jsuber = 835;
    goto L2000;

/* ...     OMIT OR RETAIN FOUND - HAS TYPE OF OPERATION ALREADY */
/* ...     BEEN ESTABLISHED FOR OUTPUT OF THIS PATTERN */
L160:
    if (*listyp != 0) {
	goto L165;
    }
/* ...     NO - THIS MODIFIER ESTABLISHES IT */
    *listyp = *kreslt - 170;
    goto L175;

/* ...     OPERATION TYPE ALREADY SET - DOES THIS MODIFIER AGREE WITH IT */
L165:
    if (*listyp == *kreslt - 170) {
	goto L170;
    }
/* ...     OMIT/RETAIN MODIFIER FOUND DOES NOT AGREE WITH PREVIOUS ONES */
    a1com_1.jsuber = 811;
    goto L2000;

/* ...     OMIT OR RETAIN OPERATION - DO WE ALREADY HAVE ONE IN HOLD - */
/* ...     IF SO, GO TO OUTPUT POINTS ACCORDING TO ONE IN HOLD */
L170:
    if (*ntain1 != 0) {
	goto L300;
    }
    if (*nomit != 0) {
	goto L300;
    }
/* ...     NONE IN HOLD - SET FLAG TO INDICATE OPERATION TYPE */
L175:
    *loptyp = *listyp;
/* ...     CLEAR STORAGE FOR NUMBER OF OMIT POINT */
    *nomit = 0;
    goto L200;

/* ...     AVOID FOUND - DO WE ALREADY HAVE ONE IN HOLD */
L180:
    if (*nvoid1 == 0) {
	goto L190;
    }
/* ...     YES - IF A SPECIFIED RETAIN LIST IS BEING USED FOR OUTPUT, */
/* ...     MAKE SURE A RETAIN SEQUENCE IS IN PROCESS OR AVAILABLE */
    if (*listyp != 1) {
	goto L300;
    }
    if (*ntain2 != 0) {
	goto L300;
    } else {
	goto L450;
    }

/* ...     NONE IN HOLD - SET FLAG TO INDICATE OPERATION TYPE */
L190:
    *loptyp = 3;
/* ...     SET FLAG TO INDICATE AN AVOID MODIFIER HAS BEEN FOUND */
    *iavoid = 1;
/* ...     GET Z-INCREMENT FOR AVOID OPERATION - CHECK FOR END */
/* ...     OF MODIFIER LIST FIRST - ERROR IF FOUND HERE */
    if (a1com_1.indxpt >= *iptlim) {
	goto L210;
    }
    agtarg_(&avoidz, &c__1, nextyp);
/* ...     MAKE SURE IT IS A SCALAR */
    if (*nextyp != 1) {
	goto L210;
    }

/* ...     GET FIRST SCALAR FOLLOWING AN 'OMIT', 'RETAIN', OR 'AVOID,Z' - */
/* ...     CHECK FOR END OF MODIFIER LIST FIRST - ERROR IF FOUND HERE */
L200:
    if (a1com_1.indxpt >= *iptlim) {
	goto L210;
    }
/* ...     GET POINT NUMBER FOR OPERATION */
/* L205: */
    agtarg_(fnum, &c__1, nextyp);
/* ...     MAKE SURE IT IS A SCALAR */
    if (*nextyp == 1) {
	goto L220;
    }
/* ...     INSUFFICIENT OR INCORRECT DATA FOUND FOLLOWING 'OMIT', */
/* ...     'RETAIN', OR 'AVOID' */
L210:
    a1com_1.jsuber = 836;
    goto L2000;

/* ...     SCALAR FOUND, NOT FIRST ONE FOLLOWING A MODIFIER - IF AN */
/* ...     OPERATION OF TYPE INDICATED BY LAST MODIFIER ALREADY IN */
/* ...     HOLD, IGNORE THIS SCALAR FOR NOW, GO TO OUTPUT POINTS */
L215:
    if (nopflg[*loptyp - 1] != 0) {
	goto L300;
    }

/* ...     CONVERT POINT NUMBER TO INTEGER, AND SAVE IT WHILE */
/* ...     TESTING FOR A 'THRU' SEQUENCE */
L220:
    *numb1 = (integer) (*fnum);
/* ...     MAKE SURE POINT NUMBER IS WITHIN RANGE OF PATTERN */
    if (*numb1 <= 0) {
	goto L240;
    }
    if (*numb1 > *numpts) {
	goto L240;
    }

/* ...     TEST FOR END OF MODIFIER LIST */
    if (a1com_1.indxpt <= *iptlim) {
	goto L230;
    }
/* ...     YES - CLEAR PARAMETER TYPE FLAG TO INDICATE IT */
    *nextyp = 0;
    goto L275;

/* ...     NOT END OF MODIFIER LIST - GET NEXT ENTRY */
L230:
    agtarg_(fnum, &c__1, nextyp);
/* ...     IF SCALAR, NO 'THRU' SEQUENCE - GO TO OUTPUT POINTS */
    if (*nextyp == 1) {
	goto L275;
    }
/* ...     NOT SCALAR - MUST BE VOCABULARY, OR ERROR */
    if (*nextyp != 5) {
	goto L112;
    }
/* ...     IT IS - IF NOT 'THRU', GO TO OUTPUT POINTS */
    if (*kreslt != 152) {
	goto L275;
    }

/* ...     'THRU' FOUND - MUST BE FOLLOWED BY SCALAR - TEST FOR */
/* ...     END OF MODIFIER LIST FIRST */
    if (a1com_1.indxpt > *iptlim) {
	goto L210;
    }
/* ...     GET PARAMETER, AND TEST FOR SCALAR */
    agtarg_(fnum, &c__1, nextyp);
    if (*nextyp != 1) {
	goto L210;
    }
/* ...     CONVERT POINT NUMBER TO INTEGER */
    *numb2 = (integer) (*fnum);
/* ...     MAKE SURE IT IS WITHIN RANGE OF PATTERN */
    if (*numb2 <= 0) {
	goto L240;
    }
    if (*numb2 <= *numpts) {
	goto L250;
    }

/* ...     POINT NUMBER IS ZERO - ERROR */
L240:
    a1com_1.jsuber = 812;
    goto L2000;

/* ...     ORDER END POINT NUMBERS OF 'THRU' SEQUENCE ACCORDING TO */
/* ...     WHETHER OR NOT ORDER OF OUTPUT IS INVERTED FROM ORDER */
/* ...     OF REFERENCE NUMBER SEQUENCE */
L250:
    if ((i__1 = (*numb1 - *numb2) * *incrpt) < 0) {
	goto L270;
    } else if (i__1 == 0) {
	goto L210;
    } else {
	goto L260;
    }
/* ...     POINT NUMBER ORDER MUST BE REVERSED */
L260:
    *jtemp1 = *numb2;
    *numb2 = *numb1;
    *numb1 = *jtemp1;

/* ...     SEE WHETHER OUTPUT IS TO BE IN ZIGZAG ORDER - IF SO, AND IF */
/* ...     'CONST' HAS BEEN READ, POINT NUMBERS MUST BE IN SAME COLUMN */
L270:
    if (*izgzag == 0) {
	goto L280;
    }
    if (*ireflg == 0) {
	goto L280;
    }
    if (*numb2 / *nptcol == *numb1 / *nptcol) {
	goto L280;
    }
/* ...     LIMITS OF 'THRU' SEQUENCE NOT IN SAME COLUMN OF PARALLEL */
/* ...     PATTERN FOR 'ZIGZAG' OUTPUT */
    a1com_1.jsuber = 837;
    goto L2000;

/* ...     OPERATION JUST READ DOES NOT USE 'THRU' SEQUENCE - SET */
/* ...     2ND POINT NUMBER NEGATIVE */
L275:
    *numb2 = -1;

/* ...     BRANCH TO PUT POINT NUMBER(S) IN WORKING STORAGES FOR OUTPUT */
L280:
    if ((i__1 = *loptyp - 2) < 0) {
	goto L285;
    } else if (i__1 == 0) {
	goto L290;
    } else {
	goto L295;
    }

/* ...     RETAIN OPERATION */
L285:
    *ntain1 = *numb1;
    *ntain2 = *numb2;
    goto L298;

/* ...     OMIT OPERATION */
L290:
    *nomit = *numb1;
    *jmithr = *numb2;
    goto L298;

/* ...     AVOID OPERATION */
L295:
    *nvoid1 = *numb1;
    *nvoid2 = *numb2;

/* ...     IF END OF MODIFIER LIST HAS BEEN FOUND, GO TO OUTPUT POINTS */
L298:
    if (*nextyp == 0) {
	goto L300;
    }
/* ...     END OF LIST NOT FOUND YET - DETERMINE WHETHER OR NOT NEXT */
/* ...     ITEM OF LIST TO BE ANALYZED IS YET TO BE READ (HAS ALREADY */
/* ...     BEEN READ IF OPERATION JUST SET UP DOES NOT USE 'THRU' SEQ.) */
    if (*numb2 <= 0) {
	goto L108;
    } else {
	goto L100;
    }

/* ...     OUTPUT OR SKIP POINTS AS INDICATED BY MODIFIERS READ */

/* ...     INITIALIZE FOR COMPARISON OF OPERATION POINT TO PRESENT */
/* ...     POINT ON ASSUMPTION THAT OPERATION POINT NUMBERS ARE */
/* ...     REFERENCED TO ORDER OF OUTPUT */
L300:
    *jtemp1 = *incrpt;
/* ...     SEE IF OUTPUT IS IN ZIGZAG ORDER */
    if (*izgzag == 0) {
	goto L305;
    }
/* ...     YES - SEE IF OPERATION POINT NUMBERS REFERENCED TO */
/* ...     ORIGINAL DEFINITION */
    if (*ireflg == 0) {
	goto L305;
    }
/* ...     YES - COMPUTE COLUMN NUMBER FOR FIRST POINT SPECIFIED TO */
/* ...     BE OMITTED OR RETAINED */
    icoltm = (nopflg[*listyp - 1] - 1) / *nptcol + 1;
/* ...     IF FIRST POINT NOT IN SAME COLUMN AS NEXT POINT AVAILABLE */
/* ...     FOR OUTPUT, USE OVERALL DIRECTION SENSE (INVERS FLAG) FOR */
/* ...     COMPARISON OF SPECIFIED POINT WITH NEXT AVAILABLE POINT */
    if (icoltm == icolno) {
	goto L305;
    }
/* ...     POINTS ARE NOT IN SAME COLUMN */
    *jtemp1 = *invers;

/* ...     TEST FOR RETAIN OPERATION, EITHER SPECIFIED (LISTYP = 1) */
/* ...     OR IMPLIED (LISTYP = 0 WHEN NO OMIT OR RETAIN MODIFIERS */
/* ...     HAVE BEEN FOUND YET) */
L305:
    if ((i__1 = *listyp - 1) < 0) {
	goto L380;
    } else if (i__1 == 0) {
	goto L310;
    } else {
	goto L330;
    }

/* ...     RETAIN HAS BEEN SPECIFIED - ARE WE STARTING A SEQUENCE */
L310:
    if (*ntain2 == 0) {
	goto L390;
    }
/* ...     YES - DETERMINE WHETHER FIRST (OR ONLY) POINT TO BE RETAINED */
/* ...     IS, IS BEYOND, OR IS BEFORE (ERROR), NEXT POINT OF PATTERN */
    if ((i__1 = (*nextpt - *ntain1) * *jtemp1) < 0) {
	goto L320;
    } else if (i__1 == 0) {
	goto L325;
    } else {
	goto L450;
    }

/* ...     POINT TO BE RETAINED IS BEYOND NEXT POINT - SET NEXT POINT */
/* ...     NUMBER TO POINT TO BE RETAINED */
L320:
    *nextpt = *ntain1;
/* ...     IF MORE THAN ONE POINT TO BE RETAINED, MOVE LAST NUMBER */
/* ...     OF SEQUENCE TO NTAIN1 FOR LIMIT TEST */
L325:
    if (*ntain2 <= 0) {
	goto L390;
    }
    *ntain1 = *ntain2;
/* ...     GO TO COMPUTE COORDINATE PICK-UP INDEX FROM POINT NUMBER */
    goto L390;

/* ...     OMIT LIST BEING USED FOR OUTPUT - HAS NEXT POINT BEEN GIVEN - */
/* ...     IF NOT, TREAT AS IMPLIED RETAIN */
L330:
    if (*nomit == 0) {
	goto L380;
    }
/* ...     NEXT POINT OR SEQUENCE TO BE OMITTED GIVEN - DETERMINE */
/* ...     WHETHER IT IS, IS BEYOND, OR IS BEFORE (ERROR) NEXT POINT */
/* ...     OF PATTERN */
    if ((i__1 = (*nextpt - *nomit) * *jtemp1) < 0) {
	goto L350;
    } else if (i__1 == 0) {
	goto L340;
    } else {
	goto L450;
    }

/* ...     A POINT TO BE OMITTED IS NEXT POINT OF PATTERN */
L340:
    *nextpt += *incrpt;
/* ...     IS IT FIRST ONE OF A 'THRU' SEQUENCE */
    if (*jmithr <= 0) {
	goto L490;
    }
/* ...     YES - SET NEXT OUTPUT POINT INDEX TO FIRST POINT */
/* ...     BEYOND SEQUENCE */
    *nextpt = *jmithr + *incrpt;
/* ...     GO TO CLEAR 'OMIT' POINT STORAGES, AND RETURN TO PICK */
/* ...     UP ANY FURTHER MODIFIER DATA */
    goto L485;

/* ...     POINT TO BE OMITTED IS BEYOND NEXT POINT OF PATTERN - */
/* ...     SET TO OUTPUT POINTS UP TO POINT TO BE OMITTED */
L350:
    *ntain1 = *nomit - *incrpt;
/* ...     SEE IF THIS IS AN OMIT 'THRU' SEQUENCE */
    if (*jmithr <= 0) {
	goto L390;
    }
/* ...     YES - PUT NUMBER OF LAST POINT TO BE OMITTED INTO OMIT STORAGE */
    *nomit = *jmithr;
    goto L390;

/* ...     IMPLIED RETAIN - SET UP END POINT NUMBER OF PATTERN AS */
/* ...     END OF 'RETAIN' SEQUENCE */
L380:
    *ntain1 = *jendpt;

/* ...     SEE IF POINT NUMBERS FOR OPERATIONS REFERENCED TO */
/* ...     ORIGINAL DEFINITION ORDER */
L390:
    if (*ireflg != 0) {
	goto L392;
    }

/* ...     NO - SEE IF OUTPUT TO BE INVERSED, WITH OR WITHOUT ZIGZAG */
    if (*invers <= 0) {
	goto L394;
    }
/* ...     NO - SEE IF OUTPUT IS IN ZIGZAG ORDER */
    if (*izgzag != 0) {
	goto L450;
    }
/* ...     NO - OUTPUT ORDER AGREES WITH ORIGINAL DEFINITION... */

/* ...     COMPUTE STARTING COORDINATE PICK-UP INDEX FROM POINT NUMBER */
L392:
    *icoord = *nextpt * 3 - 1;
    goto L398;

/* ...     OUTPUT ORDER IS INVERTED - IS IT ALSO IN ZIGZAG */
L394:
    if (*izgzag != 0) {
	goto L450;
    }
/* ...     NO - COMPUTE STARTING COORDINATE PICK-UP INDEX FROM */
/* ...     INVERTED POINT NUMBER */
    *icoord = (*numpts + 1 - *nextpt) * 3 - 1;

/* ...     COMPUTE COORDINATE PICK-UP INCREMENT FROM POINT NO. INCREMENT */
L398:
    *incord = *incout * 3;
/* ...     CLEAR FLAG TO INDICATE OMIT/RETAIN SEQUENCE HAS BEEN STARTED */
    *ntain2 = 0;

/* ...     TEST FOR END OF IMMEDIATE SEQUENCE OF POINTS BEING OUTPUT */
L400:
    if ((*nextpt - *ntain1) * *incrpt <= 0) {
	goto L410;
    } else {
	goto L480;
    }

/* ...     NO - SEE WHETHER OR NOT PATTERN HAS BEEN READ FROM FILE YET */
L410:
    if (idfsto[OTHER_ENDIAN_S(78)] != 0) {
	goto L412;
    }
/* ...     NO - LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE */
    aserch_(&ataptb_1.srftap, &idfsto[OTHER_ENDIAN_S(79)], &ioflag);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (ioflag >= 0) {
	goto L2050;
    }
/* ...     READ IN PATTERN DEFINITION */
    ataprd_(&ataptb_1.srftap, &ioflag, jtemp1, &c__3, &jprotp[OTHER_ENDIAN_S(39)], &c__3, &
	    aprotp_1.protp[41], &c__2, &deftab[1], &c__0);
/* ...     TEST FOR ERROR WHEN READING IN PATTERN */
    if (ioflag >= 0) {
	goto L2060;
    }
/* ...     SET FLAG TO INDICATE THAT THIS RECORD IS IN CORE */
    idfsto[OTHER_ENDIAN_S(78)] = 1;

/* ...     PUT NEXT POINT TO BE OUTPUT INTO DEFSTO */
L412:
    idfsto[OTHER_ENDIAN_S(0)] = 1;
    adfsto_1.defsto[3] = deftab[*icoord - 1];
    adfsto_1.defsto[4] = deftab[*icoord];
    adfsto_1.defsto[5] = deftab[*icoord + 1];
/* ...     TEST FOR TRANSFORMATION OF OUTPUT */
    if (*itrflg == 0) {
	goto L415;
    }
/* ...     YES - DO IT */
    atrfrm_();

/* ...     TEST FOR ENTRY FROM PREVIOUS 'AVOID' AT THIS POINT */
L415:
    if (voidls == 0.) {
	goto L430;
    }

/* ...     YES - OUTPUT POINT COORDINATES AT PREVIOUS 'AVOID' */
/* ...     HEIGHT INCREMENT */
/* L420: */
    aprotp_1.protp[4] = adfsto_1.defsto[3];
    aprotp_1.protp[5] = adfsto_1.defsto[4];
    aprotp_1.protp[6] = adfsto_1.defsto[5] + voidls;
    aritap_();
/* ...     OUTPUT A 'CYCLE/ON' RECORD */
    jprotp[OTHER_ENDIAN_S(1)] = 2;
    aprotp_1.protp[1] = *cyctyp;
    aprotp_1.protp[2] = *cyclon;
    aritap_();
/* ...     RESTORE 'GOTO/' RECORD DATA */
    jprotp[OTHER_ENDIAN_S(1)] = 6;
    aprotp_1.protp[1] =*gotype;
    aprotp_1.protp[2] = patnam;
/* ...     CLEAR FLAG INDICATING AN 'AVOID' TO BE TERMINATED */
    voidls = 0.;

/* ...     OUTPUT THIS POINT */
L430:
    aprotp_1.protp[4] = adfsto_1.defsto[3];
    aprotp_1.protp[5] = adfsto_1.defsto[4];
    aprotp_1.protp[6] = adfsto_1.defsto[5];
    aritap_();
/* ...     INCREMENT POINT NUMBER AND COORDINATE PICK-UP INDEX */
    *nextpt += *incrpt;
    *icoord += *incord;

/* ...     TEST FOR AN 'AVOID' OPERATION */
    if (*nvoid1 == 0) {
	goto L400;
    }

/* ...     YES - DETERMINE WHETHER FIRST (OR ONLY) POINT TO BE 'AVOIDED' */
/* ...     IS, IS BEYOND, OR IS BEFORE POINT JUST OUTPUT */
    if ((i__1 = (*nextpt - *incrpt - *nvoid1) * *incrpt) < 0) {
	goto L400;
    } else if (i__1 == 0) {
	goto L460;
    } else {
	goto L450;
    }

/* ...     POINT NUMBER FOR OPERATION HAS ALREADY BEEN PASSED - ERROR */
L450:
    a1com_1.jsuber = 838;
    goto L2000;

/* ...     POINT JUST OUTPUT REQUIRES AN 'AVOID' OPERATION - OUTPUT */
/* ...     A 'CYCLE/NOMORE' RECORD */
L460:
    jprotp[OTHER_ENDIAN_S(1)] = 2;
    aprotp_1.protp[1] = *cyctyp;
    aprotp_1.protp[2] = *cycoff;
    aritap_();
/* ...     RESTORE 'GOTO/' RECORD DATA */
    jprotp[OTHER_ENDIAN_S(1)] = 6;
    aprotp_1.protp[1] = *gotype;
    aprotp_1.protp[2] = patnam;
/* ...     OUTPUT POINT AGAIN AT 'AVOID' HEIGHT INCREMENT */
    aprotp_1.protp[6] += avoidz;
    aritap_();
/* ...     SET FLAG TO INDICATE 'AVOID' CONDITION TO BE TERMINATED */
    voidls = avoidz;

/* ...     TEST FOR AN AVOID 'THRU' SEQUENCE */
    if (*nvoid2 <= 0) {
	goto L470;
    }
/* ...     YES - IS POINT JUST OUTPUT LAST ONE OF SEQUENCE */
    if (*nextpt - *incrpt == *nvoid2) {
	goto L470;
    }
/* ...     NO - INCREMENT INITIAL POINT NUMBER OF 'AVOID' SEQUENCE */
    *nvoid1 += *incrpt;
    goto L400;

/* ...     ONLY ONE POINT OR END OF SEQUENCE FOR 'AVOID' OPERATION - */
/* ...     CLEAR FLAG, AND GO TO TEST FOR FURTHER MODIFIER DATA */
L470:
    *nvoid1 = 0;
    goto L500;

/* ...     END OF PRESENT SEQUENCE OF POINTS FOR OUTPUT - TEST FOR */
/* ...     AN 'OMIT' POINT OR SEQUENCE FOLLOWING */
L480:
    if (*nomit == 0) {
	goto L495;
    }
/* ...     YES - SET NEXT OUTPUT POINT INDEX TO FIRST POINT BEYOND */
/* ...     OMITTED POINT OR SEQUENCE */
    *nextpt = *nomit + *incrpt;

/* ...     CLEAR 'OMIT' SEQUENCE STORAGES */
L485:
    *jmithr = 0;
L490:
    *nomit = 0;

/* ...     CLEAR OUTPUT LIMIT STORAGE */
L495:
    *ntain1 = 0;

/* ...     TEST FOR FURTHER MODIFIER DATA FOR OUTPUT OF PATTERN */
L500:
    if ((i__1 = *nextyp - 1) < 0) {
	goto L510;
    } else if (i__1 == 0) {
	goto L515;
    } else {
	goto L110;
    }
/* ...     NEXT PARAMETER IS SCALAR - SEE IF OPERATION OF SAME TYPE */
/* ...     ALREADY IN HOLD */
L515:
    if (nopflg[*loptyp - 1] == 0) {
	goto L220;
    }
/* ...     YES - SEE IF IT IS AVOID OPERATION */
    if (*loptyp != 3) {
	goto L300;
    }

/* ...     NO MORE MODIFIER DATA, OR TWO AVOIDS PENDING - */
/* ...     OMIT/RETAIN LIST NOT YET COMPLETED */
L510:
    if (*ntain1 != 0) {
	goto L400;
    }
/* ...     NO - TEST FOR END OF PATTERN */
    if ((*nextpt - *jendpt) * *incrpt <= 0) {
	goto L520;
    } else {
	goto L550;
    }
/* ...     NOT END OF PATTERN YET - IF EXPLICIT 'RETAIN' LIST GIVEN, */
/* ...     CONSIDER PATTERN FINISHED - OTHERWISE, SET UP 'RETAIN' */
/* ...     SEQUENCE TO COMPLETE PATTERN */
L520:
    if (*listyp != 1) {
	goto L380;
    }

/* ...     OUTPUT OF PATTERN COMPLETED - MAKE SURE NO 'AVOID' POINTS */
/* ...     WERE SPECIFIED BEYOND THE RANGE OF ANY 'RETAIN' */
L550:
    if (*nvoid1 != 0) {
	goto L450;
    }

L1000:
    return 0;

/* ...     ERROR FOUND - IF DEBUG FLAG ON, PRINT OUT WORKING */
/* ...     STORAGES BEFORE EXITING */
L2000:
    if (a1com_1.kdbug == 0) {
	goto L1000;
    }
/* L2010: */
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&(*fnum), (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avoidz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&voidls, (ftnlen)sizeof(doublereal));
    for (jk = 1; jk <= 15; ++jk) {
	do_fio(&c__1, (char *)&iptdat[jk - 1], (ftnlen)sizeof(integer));
    }
    for (jk = 1; jk <= 15; ++jk) {
	do_fio(&c__1, (char *)&iptflg[jk - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    goto L1000;

/* ...     ERROR IN SEARCH OF LARGE SURFACE FILE FOR PATTERN */
L2050:
    a1com_1.jsuber = 840;
    goto L2000;
/* ...     ERROR IN READING OF PATTERN FROM LARGE SURFACE FILE */
L2060:
    a1com_1.jsuber = 841;
    goto L2000;

} /* patgo_ */

#undef num
#undef cycoff
#undef cyclon
#undef cyctyp
#undef gotype
#undef itrflg
#undef jmithr
#undef ireflg
#undef loptyp
#undef listyp
#undef iavoid
#undef izgzag
#undef invers
#undef incout
#undef incord
#undef icoord
#undef jendpt
#undef nextpt
#undef incrpt
#undef nextyp
#undef iptlim
#undef nptcol
#undef nocols
#undef numpts
#undef ipatyp
#undef kreslt
#undef nopflg
#undef iptflg
#undef iptdat
#undef jprotp
#undef idfsto
#undef jprcod
#undef kdfans
#undef defans
#undef deftab
#undef nvoid1
#undef nvoid2
#undef jtemp1
#undef ntain2
#undef ntain1
#undef nomit
#undef canon
#undef numb2
#undef numb1
#undef ptpp
#undef fnum


