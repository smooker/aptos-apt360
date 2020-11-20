/* AMON1.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include <ctype.h> 

/* Common Block Declarations */

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

static struct {
    doublereal pint[30];
    integer ifurst, jptind, now, jsub, kreslt, krslt2, nwds, its, next, 
	    multax;
} amotcm_;

#define amotcm_1 amotcm_

static struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

static struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

static struct {
    doublereal inword[14];
    integer more, ifirst;
} ainpot_;

#define ainpot_1 ainpot_

static struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

static struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

static struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

static struct {
    doublereal anodef, blanx, blanks, syn, tlaxis, dummy, plent;
    integer loopst, loopnd, macro, ntrmac, ncall, lapth, japth, iplus, ncomma,
	     iff, ic[10], llass;
} adata1_;

#define adata1_1 adata1_

static struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

static struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__4 = 4;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__15 = 15;

/* Subroutine */ int amon1_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_29 = { {'I', 'O', 'F', 'L', 'A', 'G', ' ', ' '}, 0. };

#define flag__ (*(doublereal *)&equiv_29)


    /* Format strings */
    static char fmt_40[] = "(13a6,a2)";
    static char fmt_188[] = "(\0020\002,i5,2x,13a6,a2//)";
    static char fmt_191[] = "(\0020\002,7x,13a6,a2//)";
    static char fmt_1100[] = "(////\002  * * * END OF APT PROCESSING * * * *\
 * *  \002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(), do_fio(), e_rsfe(), s_wsfe(), e_wsfe();

    /* Local variables */
    static integer i__, j, n, kk, idm;
#define ipt ((integer *)&aptpp_)
    static integer iier;
#define ivst ((integer *)&avst_1)
    static integer iptp1, iptp2;
    extern /* Subroutine */ int afini_();
#define canon ((doublereal *)&avst_1)
    static integer nwrds;
    static doublereal entry__;
    static integer jtemp1;
#define ippsq2 ((integer *)&aklas7_1 + 2)
    extern /* Subroutine */ int adiagp_(), achedt_(), apread_();
#define jblank ((integer *)&adata1_1 + 4)
    static integer ioflag;
#define icanon ((integer *)&avst_1)
#define errtap ((doublereal *)&ataptb_1 + 9)
#define ptptap ((doublereal *)&ataptb_1 + 3)
#define jinwrd ((integer *)&ainpot_)
    static integer kanlth;
    extern /* Subroutine */ int ataprd_();
    static integer lplngt;
    extern /* Subroutine */ int atblkp_(), atapwt_(), aptput_(), aptout_(), 
	    atapop_();

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 0, 1, fmt_40, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_188, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_191, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_1100, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

/*     THIS PROGRAM PUTS ONE CARD INTO THE INWORD ARRAY FOR PROCESSING */
/*     IF A LOOP IS BEING EXECUTED, THE DATA COMES FROM THE NEWONE ARRAY. */
/*     IF A MACRO IS BEING EXECUTED, THE DATA COMES FROM CANON */
/*     OTHERWISE, THE DATA IS READ FROM THE INPUT FILE */
/*          COMMON  STORAGE */
/*               *          *          *          *          * */
/* L40: */

    if (amcstf_1.macrd <= 0) {
	goto L110;
    }
/* ...  MACRO BEING EXECUTED - ADJUST POINTERS FROM CANON */
/* L80: */
    jtemp1 = (abreak_.kanlcn << 1) - 1;
    abreak_.nextcn = icanon[OTHER_ENDIAN_S(jtemp1)];
/* ...  GET LENGTH OF THIS ENTRY */
    kanlth = abs(abreak_.nextcn) - abreak_.nrelcn - 1;
    j = abreak_.kanlcn + 1;
/* ...  MOVE DATA */
    i__1 = kanlth;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ainpot_.inword[i__ - 1] = canon[j - 1];
/* L90: */
	++j;
    }
/* ...  ADJUST POINTERS FOR NEXT TIME */
    abreak_.kanlcn = abreak_.kanlcn + kanlth + 1;
    abreak_.locseq = kanlth - 1;
    abreak_.nrelcn = abs(abreak_.nextcn);
    goto L200;

L110:
    if (abreak_.nwonrd <= 0) {
	goto L180;
    }
/* ...  LOOP BEING EXECUTED */
/* L130: */
    ataprd_(errtap, &ioflag, &nwrds, &c__4, &idm, &c__1, &idm, &c__1, &lplngt,
	     &c__1, ainpot_.inword, &c__0);
    if (ioflag < 0) {
	goto L135;
    } else if (ioflag == 0) {
	goto L1220;
    } else {
	goto L1230;
    }
L135:
    if (abreak_.lplocn == 1) {
	goto L160;
    }
/* L150: */
    abreak_.jsw4 = 0;
/* ...  ADJUST POINTERS FOR NEXT TIME */
L160:
    abreak_.lplocn = 0;
    abreak_.locseq = lplngt - 1;
    goto L200;

/* ...  READ FROM PDS */
L165:
    apread_(ainpot_.inword, &alibry_1.irdmod, &alibry_1.segnam, &
	    a1com_1.jsuber);
    if (a1com_1.jsuber == 0) {
	goto L166;
    }
    if (a1com_1.jsuber != 36) {
	goto L998;
    }
    amcstf_1.maccur = 0;
    amcstf_1.macrd = 0;
    abreak_.nrelcn = amxtab_1.maxvst + 1;
    amcstf_1.idlocn = 0;
    if (abreak_.nwonrd != 0) {
	goto L998;
    }
    a1com_1.loop = 0;
    goto L998;
/* ...  IF APREAD HAS REACHED END OF MEMBER, READ FROM SYSIN */
L166:
    if (alibry_1.irdmod == 0) {
	goto L167;
    }
    goto L168;

/* ...  DATA COMES FROM INPUT FILE */
/* ...  CHECK IF READING FROM PDS */
L180:
    if (alibry_1.irdmod != 0) {
	goto L165;
    }
L167:
    io___19.ciunit = ataptb_1.intape;
    i__1 = s_rsfe(&io___19);
    if (i__1 != 0) {
	goto L1000;
    }
    for (i__ = 1; i__ <= 14; ++i__) {

	int i;
	char* temp;
	i__1 = do_fio(&c__1, (char *)&ainpot_.inword[i__ - 1], (ftnlen)
		sizeof(doublereal));
 	//-------convert to upper case----------------
	temp=(char*)&ainpot_.inword[i__ - 1];
	for (i=0;i<8;++i){
		temp[i]=(char)toupper((int)temp[i]);
	}
	//--------------------------------------------

	if (i__1 != 0) {
	    goto L1000;
	}
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L1000;
    }
/* ...     TEST FOR CONTINUATION CARD */
L168:
    if (ainpot_.more > 0) {
	goto L181;
    }
/* ...     NO - SEE IF STATEMENT STARTS WITH FIXED-FIELD WORD */
    entry__ = ainpot_.inword[0];
    atblkp_(&entry__, &n, &c__1);
    if (n != 0) {
	goto L182;
    }
/* ...     NOT FIXED-FIELD STATEMENT - TEST ALL CHARACTERS FOR VALID SET */
L181:
    achedt_(ainpot_.inword, &iier);
    if (iier != 0) {
	a1com_1.jsuber = iier;
    }
L182:
    abreak_.locseq = 13;
    if (ainpot_.more > 0) {
	goto L185;
    }
/* ...  UPDATE COUNTER FOR INTERNAL STATEMENT NUMBER */
    ++abreak_.isn;
    aklas7_1.iisn = abreak_.isn;

/* ...     IF DEBUG OUTPUT REQUESTED, WRITE A SOURCE RECORD */
L185:
    if (a1com_1.debug == 0) {
	goto L192;
    }
/* ...     TEST FOR CONTINUATION CARD */
    if (ainpot_.more > 0) {
	goto L190;
    }
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&abreak_.isn, (ftnlen)sizeof(integer));
    for (kk = 1; kk <= 14; ++kk) {
	do_fio(&c__1, (char *)&ainpot_.inword[kk - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L192;
/* ...     ISN SAME AS LAST - DO NOT PRINT */
L190:
    io___25.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___25);
    for (kk = 1; kk <= 14; ++kk) {
	do_fio(&c__1, (char *)&ainpot_.inword[kk - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();

/* ...     OUTPUT A CLASS ONE PTPP RECORD */
L192:
    for (i__ = 2; i__ <= 15; ++i__) {
/* L193: */
	aptpp_.pt[i__ - 1] = ainpot_.inword[i__ - 2];
    }
    ipt[OTHER_ENDIAN_S(0)] = 1;
    ipt[OTHER_ENDIAN_S(1)] = abreak_.isn;
    if (amcstf_1.macrd >= 0) {
	goto L195;
    }
    iptp1 = 0;
    iptp2 = 15;
    ++aptpp_.irecn;
    atapwt_(ptptap, &ioflag, &c__4, &aptpp_.irecn, &c__1, &iptp1, &c__1, &
	    iptp2, &c__1, aptpp_.pt, &c__15);
    if (ioflag < 0) {
	goto L199;
    }
/* ... TAPE WRITING ERROR, OUTPUT THE  ER. VALUE IN THE IOFLAG */
    goto L1250;

L195:
    aptpp_.inptp = 15;
    aptpp_.jmode = 5;
    aptput_();
    if (a1com_1.jsuber == 12) {
	goto L998;
    }
L199:
    jtemp1 = (abreak_.locseq << 1) - 1;
//    jinwrd[OTHER_ENDIAN_S(jtemp1 + 2)] = aklas7_1.iisn;
//	endian macro breaks here- stream of chars has the same endianess on both
    jinwrd[jtemp1 + 2] = aklas7_1.iisn;

/* ...  STORE SEQUENCE NUMBERS AND INTERNAL STATEMENT NUMBERS */
L200:
    if (ainpot_.more != 0) {
	goto L998;
    }
/* L210: */
    aklas7_1.ppseq1 = ainpot_.inword[abreak_.locseq - 1];
    aklas7_1.ppseq2 = ainpot_.inword[abreak_.locseq];
    //ippsq2[OTHER_ENDIAN_S(1)] = *jblank;
    ippsq2[1] = *jblank;
    jtemp1 = (abreak_.locseq << 1) - 1;
 //   aklas7_1.iisn = jinwrd[OTHER_ENDIAN_S(jtemp1 + 2)];
    aklas7_1.iisn = jinwrd[jtemp1 + 2];
L998:
    return 0;
/* .. */
/* ..  DID  FINI  TERMINATE PREVIOUS PART PARGOGRAM */
L1000:
    if (abreak_.isn != 0) {
	goto L1200;
    }
/* L1010: */
    io___28.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___28);
    e_wsfe();
    aptout_();
/* ... */
/* ..  IMPROPER TERMINATION OF PREVIOUS PART PROGR. MAYBE NO FINI FOUND */
/* ... OUTPUT A CLASS 2 PTPP  ERROR DIAGNOSTIC RECORD */
L1200:
    a1com_1.jsuber = 23;
    afini_();
    goto L998;

/* ..  LOOPND  MISSING -- THE EOF READ ON ERRTAP */
L1220:
    a1com_1.jsuber = 212;
    a1com_1.sum = 0;
    goto L1240;

/* ..   I/O ERROR WHILE READING LOOP FROM STORAGE FILE --LOOP EXEC. MODE */
/* . */
L1230:
    a1com_1.jsuber = 181;

/* ..   OUTPUT THE VAL. OF THE IOFLAG AND THE  INDICATOR IN THE */
/* .. COMMON VAR. SYM. 'NAME'  -- THE CLASS TWO PTPP PRINT OUT WILL BE */
/* ..          CARD NO. XXXX   ISN XXX  ERROR NO.    IOFLAG ( VAL ) */
L1235:
    a1com_1.name__ = flag__;
    aptpp_.pt[6] = (doublereal) ioflag;
    a1com_1.sum = 9;
/* .  IF DEFINING A MACRO RETURN TO CALLING PROGRAM--OTHERWISE TURN */
/* ..  OFF THE LOOP MODE AND OUTPUT THE PTPP CLASS 19 REC. FOR PASS TWO */
    if (amcstf_1.macrd != 0) {
	return 0;
    }
L1240:
    adiagp_();
/* ...    TURN OFF THE LOOP EXECUTION MODE --OUTPUT CLASS 19 FOR PASS 2 */
    a1com_1.loop = 0;
    abreak_.nwonrd = 0;
    abreak_.jsw4 = 1;
/* ...   REWIND THE LOOP STORAGE FILE */
    atapop_(errtap, &c__1, &ioflag);
    ipt[OTHER_ENDIAN_S(0)] = 19;
    ipt[OTHER_ENDIAN_S(1)] = 1;
    aptpp_.pt[1] = 0.;
    aptpp_.inptp = 2;
    aptpp_.jmode = 5;
    aptput_();
    return 0;

/* ..   I/O ERROR WRITING MACRO CLASS 1 RECORDS ONTO THE PTPTAP */
/*    MACRO DEFINITION MODE */
L1250:
    a1com_1.jsuber = 302;
    goto L1235;
} /* amon1_ */

#undef jinwrd
#undef ptptap
#undef errtap
#undef icanon
#undef jblank
#undef ippsq2
#undef canon
#undef ivst
#undef ipt
#undef flag__


