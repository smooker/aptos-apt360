/* ADFPRE.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
#include "assert.h"
#include "config.h"

/* Common Block Declarations */

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
    doublereal dnsub;
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
    integer deflst[575];
} adfprl_;

#define adfprl_1 adfprl_

struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

struct {
    doublereal stable[23];
} a1stab_;

#define a1stab_1 a1stab_

/* Table of constant values */

static integer c__3 = 3;
static integer c__2 = 2;
static integer c__0 = 0;
static integer c__1 = 1;

/* Subroutine */ int adfpre_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_57 = { {'A', 'D', 'F', 'P', 'R', 'E', ' ', ' '}, 0. };

#define a1 (*(doublereal *)&equiv_57)

    static shortint kdirec[16] = { 7,8,10,13,19,22,24,24,26,26,31,42,48,49,
	    106,107 };
    static struct {
	integer e_1[4];
	doublereal e_2;
	} equiv_20 = { 8, 10, 0, 9, 0. };


    /* Format strings */
    static char fmt_225[] = "(\002 NESTED\002,8x,a6,i3,7f13.6/(24x,7f13.6))";
    static char fmt_235[] = "(\002 \002,a6,\002(\002,i4,\002)  \002,a6,i3,7f\
13.6/(24x,7f13.6))";

    /* System generated locals */
    integer i__1, i__2;
    static doublereal equiv_11[1];
    static integer equiv_16[3];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer n;
#define if__ ((shortint *)equiv_16 + OTHER_ENDIAN_S(0) )
    static integer ii, jj;
#define il ((integer *)equiv_11 + OTHER_ENDIAN_S(1))
#define in ((shortint *)equiv_16 + OTHER_ENDIAN_S(1))
#define it ((integer *)equiv_11 + OTHER_ENDIAN_S(0))
    static integer ls, nr, ns, iy;
#define nid ((shortint *)equiv_16 + OTHER_ENDIAN_S(3))
    static integer isc;
#define nil ((shortint *)equiv_16 + OTHER_ENDIAN_S(2))
    static integer jit, isl, ils, jtm, jtm2, jtm3, jdef;
#define idat ((integer *)&equiv_20)
#define karg ((shortint *)&ascalr_ + 726)
    static integer inpl, inpr;
#define ptpp ((doublereal *)&avst_)
#define ivst ((integer *)&avst_)
    static integer idfp1;
    extern /* Subroutine */ int aelp01_();
    static integer iread;
    extern /* Subroutine */ int aline_();
    static integer modef;
    extern /* Subroutine */ int aplan_();
#define canon ((doublereal *)&avst_)
    extern /* Subroutine */ int amatx_();
#define jtemp (equiv_16)
#define ktemp ((shortint *)equiv_16)
#define ptemp (equiv_11)
#define ifnxt ((shortint *)equiv_16 + OTHER_ENDIAN_S(4))
#define itray ((integer *)equiv_11)
#define iptpp ((integer *)&avst_)
    static doublereal stype;
    extern /* Subroutine */ int acone1_(), aqadr1_(), avs2ck_(), ahypr1_(), 
	    acanck_(), adiagm_();
#define deftab ((doublereal *)&avst_ + 6200)
    extern /* Subroutine */ int avecdf_();
#define idftab ((integer *)&avst_ + 12400)
    extern /* Subroutine */ int agencn_(), atabcr_();
#define defans ((doublereal *)&adfsto_ + 3)
#define kargpn ((shortint *)&ascalr_ + 727)
#define kdflst ((shortint *)&adfprl_)
#define idfsto ((integer *)&adfsto_)
#define knclus ((shortint *)&ascalr_ + 726)
#define jprotp ((integer *)&aprotp_)
#define kprotp ((shortint *)&aprotp_)
#define skipar ((doublereal *)&equiv_20)
#define errcod ((doublereal *)&equiv_20 + 1)
    static integer kindxp, iptlim;
    extern /* Subroutine */ int agtsub_(), agtarg_();
    static integer length;
    extern /* Subroutine */ int aserch_(), ataprd_(), adprnt_(), apoint_(), 
	    atabpt_(), azvalu_(), atabln_(), acircl_(), acylnd_(), alftcn_(), 
	    aspher_(), xloftx_(), patgen_(), aprepr_(), mshpre_(), arldsf_(), 
	    elmpre_(), acanpt_();

    /* Fortran I/O blocks */
    static cilist io___55 = { 0, 0, 0, fmt_225, 0 };
    static cilist io___56 = { 0, 0, 0, fmt_235, 0 };
#ifdef HAVE_DXFLIB_DL_DXF_H 
	extern 	void export_surf();
#endif
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */


/* ...  THIS SUBROUTINE SETS UP THE INPUT DATA IN DEFTAB */
/*     FOR ALL THE DEFINITION PREPROCESSOR ROUTINES, */
/*     AND CALLS THE PROPER GEOMETRIC DEFINITION BASED */
/*     ON THE INPUT PARAMETER TYPE LIST. IF NO SUCH */
/*     DEFINITION EXISTS, JSUBER IS SET TO 1000. */
/*     IF NO ERROR HAS OCURRED IN THE DEFINITION, */
/*     ACANPT IS CALLED TO STORE NAMED SURFACES. */
/*     UNNAMED SURFACES OTHER THAN LARGE SURFACES */
/*     ARE STORED IN SURFTB. LARGE SURFACES RESIDE */
/* ...  IN DEFTAB OR ON THE SRFTAP FILE. */

/*       INTEGER*2 KDIREC(16)/7,8,10,13,19,22,24,24,26,26 */
/*       INTEGER IDAT(4)/8,10,0,9/ */



    a1com_.jsv = 0;
    modef = 0;
/*     SET FLAG TO PUT LARGE SURFACE IN DEFTAB */
    a1pas2_1.idtmov = 0;
    a1pas2_1.lgeloc = 0;
    kindxp = (a1com_.indxpt << 1) - 1;
/* ...     COMPUTE LIMIT INDEX FOR SCAN OF DEFINITION */
    iptlim = a1pas2_1.indexs + a1pas2_1.klasct;
/* ...     SAVE FLAG INDICATING WHETHER SURFACE DEFINED OR READ */
    iread = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    ls = iptpp[OTHER_ENDIAN_S(kindxp + 1)];
/*     GET SUBSCRIPT TYPE */
    a1com_.namsub = iptpp[OTHER_ENDIAN_S(kindxp + 2)];
    a1com_.indxpt += 2;
/*     CHECK FOR NESTED, NAMELESS SURFACE */
    if (ls != 0) {
	goto L10;
    }

/*     NESTED, NAMELESS SURFACE - SAVE SURFTB INDEX */
    ascalr_.iscws = a1com_.namsub;
/*     SET ERROR NAME TO ZERO */
    a2cls7_1.einame = 0.;
    goto L15;

/*     NOT NESTED, NAMELESS - GET VST INDEX OF NAME */
L10:
    ls = iptpp[OTHER_ENDIAN_S(kindxp + 4)];
    a2cls7_1.ename = avst_.vst[ls - 1];
/*     SAVE NAME FOR POSSIBLE LATER ERRORS */
    a2cls7_1.einame = a2cls7_1.ename;
/*     GET SUBSCRIPT VALUE, IF ANY */
    agtsub_();
    if (a1com_.jsuber == 0) {
	goto L12;
    }
    a1com_.jsv = -1;
    adiagm_();
/* ...     SAVE SUBSCRIPT */
L12:
    ns = a1com_.namsub;
    a2cls7_1.dnsub = (doublereal) a1com_.namsub;

/*     GET SURFACE TYPE AND LENGTH OF CANONICAL FORM */
L15:
    *ptemp = ptpp[a1com_.indxpt - 1];
    ++a1com_.indxpt;
/*     MOVE DEFINITION PARAMETERS TO DEFTAB */
    a1pas2_1.idefp = 2;
    inpr = 2;

/* ...     TEST FOR CLASS 14 PTPP RECORD GENERATED BY ROUTINE AREAD - */
/* ...     IF SO, GO TO SET UP FOR CANON DEFINITION INPUT */
    if (a1pas2_1.klastp == 14) {
	goto L41;
    }

/* ...     PICK UP PARAMETERS, STACK DATA IN DEFTAB, AND BUILD */
/* ...     CODE STRING USED TO DETERMINE PROCESSING ROUTINE */
L20:
    if (*knclus == 2) {
	goto L22;
    }
    *knclus = 1;
    if (a1com_.indxpt > iptlim) {
	goto L105;
    }

/* ...     IF IN CANON REDEFINITION MODE, TEST PARAMETER FOR DOUBLE */
/* ...     COMMA CODE - IF IT IS, MOVE STORING INDEX UP ONE PARAMETER */
    if (modef != 1) {
	goto L22;
    }
    if (ptpp[a1com_.indxpt - 1] != *skipar) {
	//assert(0);//cause I don't know how skipar is supposed to work.
	goto L22;
    }
/* ...     MOVE SCANNING INDEX PAST DOUBLE COMMA CODE */
    ++a1com_.indxpt;
    goto L60;

L22:
    *kargpn = 1;
    jdef = (a1pas2_1.idefp << 1) - 1;
    i__1 = 1000 - a1pas2_1.idefp;
    agtarg_(&deftab[a1pas2_1.idefp], &i__1, &n);

/* ...     BRANCH ON DEFINITION MODE - NORMAL, OR CANON INPUT */
/* ...     OR REDEFINITION */
    if (modef == 0) {
	goto L24;
    }

/* ...     CANON INPUT OR REDEFINITION - PARAMETER MUST BE A SCALAR */
    if (n == 1) {
	goto L60;
    }
/* ...     IT IS NOT - ERROR */
    a1com_.jsuber = 83;
    goto L90;

/* ...     NORMAL DEFINITION - BRANCH ON PARAMETER TYPE */
L24:
    if ((i__1 = n - 6) < 0) {
	goto L26;
    } else if (i__1 == 0) {
	goto L28;
    } else {
	goto L92;
    }
L26:
    switch ((int)n) {
	case 1:  goto L35;
	case 2:  goto L30;
	case 3:  goto L86;
	case 4:  goto L28;
	case 5:  goto L40;
    }
/* ...     INVALID PARAMETER */
L28:
    a1com_.jsuber = 132;
    goto L90;

/* ...     SURFACE - PUT DEFTAB LOCATION AND SURFACE TYPE CODE INTO LIST */
L30:
    isc = idfsto[OTHER_ENDIAN_S(0)];
    idftab[OTHER_ENDIAN_S(jdef - 1)] = 0;
    idftab[OTHER_ENDIAN_S(jdef)] = isc + 3000;
    kprotp[OTHER_ENDIAN_W(inpr - 2)] = (shortint) (isc + 200);
    kprotp[OTHER_ENDIAN_W(inpr - 1)] = (shortint) a1pas2_1.idefp;
    isl = idfsto[OTHER_ENDIAN_S(1)] - 3;
/* ...     IF THIS IS A LARGE SURFACE, LENGTH IS IN IDFSTO(10) */
    if (isc < 50) {
	goto L32;
    }
    isl = idfsto[OTHER_ENDIAN_S(9)];
/*      SET LENGTH AND TYPE IN DEFTAB FOR LARGE SURFACES */
    idftab[OTHER_ENDIAN_S(jdef - 1)] = isl;
/* ...     INCREASE DEFTAB POINTER BY LENGTH OF CANONICAL FORM */
L32:
    a1pas2_1.idefp = a1pas2_1.idefp + isl + 1;
    goto L95;

/* ...     SCALAR - PUT DEFTAB LOCATION AND SCALAR CODE INTO LIST */
L35:
    kprotp[OTHER_ENDIAN_W(inpr - 2)] = 300;
    kprotp[OTHER_ENDIAN_W(inpr - 1)] = (shortint) a1pas2_1.idefp;
    goto L58;

/* ...     VOCABULARY - TEST CODE FOR SPECIAL VALUES... */
L40:
    isc = idftab[OTHER_ENDIAN_S(jdef + 2)];
/* ...     TEST FOR CANON */
    if (isc != 3099) {
	goto L50;
    }
/* ...     IT IS - IS MODIFIER FIRST INPUT PARAMETER */
    if (inpr != 2) {
	goto L43;
    }
/* ...    YES - SET FLAG FOR CANON DEFINITION */
L41:
    modef = -1;
    if (*it == 18) {
	goto L162;
    }
/* ... 'CANON' DEFINITION VALID IF RULED SURFACE READ IN */
    if (*it == 53 && a1pas2_1.klastp == 14) {
	goto L42;
    }
/* ...     IF DEFINING A LARGE SURFACE, ADJUST STORING INDEX */
    if (*it < 50) {
	goto L20;
    }
    if (*it > 54 || *it == 53) {
	goto L162;
    }
L42:
    a1pas2_1.idefp = 1;
    goto L20;

/* ...     CANON NOT FIRST PARAMETER - IF NOT SECOND, FOLLOWING A */
/* ...     SURFACE, TREAT STATEMENT AS NORMAL DEFINITION */
L43:
    if (inpr != 4) {
	goto L50;
    }
    if (kprotp[OTHER_ENDIAN_W(0)] >= 300) {
	goto L44;
    }
    if (kprotp[OTHER_ENDIAN_W(0)] > 200) {
	goto L45;
    }
L44:
    a1com_.jsuber = 79;
    goto L90;

/* ...     SEE IF TYPES OF INPUT SURFACE AND ONE BEING DEFINED MATCH */
L45:
    if (kprotp[OTHER_ENDIAN_W(0)] - 200 == *it) {
	goto L46;
    }
    a1com_.jsuber = 80;
    goto L90;

/* ...     SET FLAG FOR CANON REDEFINITION */
L46:
    modef = 1;
/* ...     SAVE LENGTH OF SURFACE FOR PARAMETER COUNT TESTS */
    length = a1pas2_1.idefp - 1;
/* ...     ADJUST STORING INDEX TO START REPLACING PARAMETERS */
    a1pas2_1.idefp = 2;
/* ...     IF LARGE SURFACE OR PATTERN BEING REDEFINED, PICK UP */
/* ...     LENGTHS - FOR PATTERN, ALSO READ IN ORIGINAL ONE */
    if (*it < 18) {
	goto L20;
    }
/* ...     LOCATE ORIGINAL DEFINITION ON LARGE SURFACE FILE */
/* L47: */
    aserch_(&ataptb_1.srftap, &idfsto[OTHER_ENDIAN_S(7)], &jtm);
/* ...     TEST FOR ERROR IN FILE SEARCH OPERATION */
    if (jtm < 0) {
	goto L48;
    }
    a1com_.jsuber = 840;
    goto L190;
/* ...     READ IN PATTERN DEFINITION */
L48:
    ataprd_(&ataptb_1.srftap, &jtm, &jtm2, &c__3, &idfsto[OTHER_ENDIAN_S(59)], &c__3, &
	    adfsto_.defsto[61], &c__2, &deftab[1], &c__0);
/* ...     TEST FOR ERROR READING IN PATTERN */
    if (jtm < 0) {
	goto L49;
    }
    a1com_.jsuber = 841;
    goto L190;
/* ...     GET LENGTHS OF CANON BLOCK AND DATA */
L49:
    *il = idfsto[OTHER_ENDIAN_S(1)];
    length = idfsto[OTHER_ENDIAN_S(9)] + 1;
    a1pas2_1.idefp = 1;
    goto L20;

/* ...     VOCAB. IS NOT CANON - TEST IT FOR DIRECTIONAL MODIFIER */
L50:
    for (a1pas2_1.j = 1; a1pas2_1.j <= 16; a1pas2_1.j += 2) {
	if ((i__1 = isc - kdirec[a1pas2_1.j - 1]) < 0) {
	    goto L55;
	} else if (i__1 == 0) {
	    goto L54;
	} else {
	    goto L52;
	}
L52:
	if (isc > kdirec[a1pas2_1.j]) {
	    goto L55;
	}
L54:
	isc = 121;
	goto L56;
L55:
	;
    }

/* ...     ADD CODE FOR VOCABULARY TO DEFINITION PATTERN LIST */
L56:
    kprotp[OTHER_ENDIAN_W(inpr - 2)] = (shortint) isc;
    kprotp[OTHER_ENDIAN_W(inpr - 1)] = (shortint) a1pas2_1.idefp;

/* ...     MOVE VOCABULARY WORD OR SCALAR TO PROPER POSITION */
L58:
    deftab[a1pas2_1.idefp - 1] = deftab[a1pas2_1.idefp];
    deftab[a1pas2_1.idefp] = 0.;

L60:
    ++a1pas2_1.idefp;
    goto L95;

/*     PARAMETER STRING TOO LONG */
L80:
    a1com_.jsuber = 84;
    goto L190;

/* ...     ILLEGAL FORMAT (PUNCTUATION FOUND) */
L86:
    a1com_.jsuber = 131;

/* ...     OUTPUT ERROR DIAGNOSTIC FOR THIS PARAMETER */
L90:
    if (a1com_.jsuber == 0) {
	goto L92;
    }
    adiagm_();
    if (a1com_.jsv != 0) {
	goto L95;
    }
L92:
    a1com_.jsv = 1;

/*     DO NOT BUILD UP LIST FOR LARGE SURFACES */
L95:
    if (*it < 50) {
	goto L98;
    }
    if (inpr > 6) {
	goto L20;
    }
L98:
    inpr += 2;
    goto L20;

/*     HAVE ANY PARAMETERS BEEN IN ERROR */
L105:
    if (a1com_.jsv != 0) {
	goto L190;
    }
/* ...     PUT LENGTH OF INPUT IN DEFTAB(1) */
    idftab[OTHER_ENDIAN_S(0)] = 0;
    idftab[OTHER_ENDIAN_S(1)] = a1pas2_1.idefp - 1;
    inpr += -2;
    if (a1com_.kdbug == 0) {
	goto L106;
    }

/*     DEBUG IS ON - PRINT DEFTAB AREA */
    adebug_1.idebug[0] = 5;
    adebug_1.idebug[1] = 1;
    adebug_1.idebug[2] = a1pas2_1.idefp;
    adprnt_(&a1);
    adebug_1.idebug[0] = 13;
    adebug_1.idebug[1] = (inpr + 3) / 4;
    adprnt_(&c__0);

/* ...     TEST FOR CANON DEFINITION OR REDEFINITION */
L106:
    if (modef < 0) {
	goto L107;
    } else if (modef == 0) {
	goto L108;
    } else {
	goto L109;
    }
/* ...     CANON DEFINITION - TEST FOR LARGE SURFACES */
L107:
    if (*it < 50) {
	goto L1075;
    }
    jit = *it - 49;
    switch ((int)jit) {
	case 1:  goto L1300;
	case 2:  goto L1300;
	case 3:  goto L1075;
	case 4:  goto L1305;
	case 5:  goto L1300;
    }

/* ...     NO - TEST FOR PROPER NUMBER OF PARAMETERS */
L1075:
    if (a1pas2_1.idefp + 1 - *il != 0) {
	goto L80;
    } else {
	goto L176;
    }

/* ...     IF DEFINITION UNNAMED (NESTED), OR IF CANON DEFINITION */
/* ...     FLAG ON, SKIP REDEFINITION TEST */
L108:
    if (ls == 0) {
	goto L110;
    }
    if (adebug_1.kcandf != 0) {
	goto L110;
    }
/* ...     TEST FOR ALREADY-DEFINED (OR ATTEMPTED) SYMBOL */
    a1com_.name__ = ls;
    a1com_.namsub = ns;
    avs2ck_(&a1pas2_1.j);
    if (a1pas2_1.j == 7) {
	goto L110;
    }
    if (a1pas2_1.j == 10) {
	goto L110;
    }
    a1com_.jsuber = 1002;
    goto L190;

/* ...     CANON REDEFINITION - TEST FOR TOO MANY INPUT PARAMETERS */
L109:
    if (a1pas2_1.idefp > length) {
	goto L80;
    }
/* ...     NO - BRANCH ON NORMAL OR LARGE SURFACE TYPE (OR PATTERN) */
/* ...     TO STORE IT */
    idftab[OTHER_ENDIAN_S(1)] = length;
    if (*it == 18) {
	goto L190;
    }
    if (*it - 50 >= 0) {
	goto L190;
    } else {
	goto L176;
    }

/* ...     GET SURFACE TYPE */
L110:
    isc = *it;
/* ...     IF DEFINING A LARGE SURFACE, SKIP INPUT FORMAT SEARCH, */
/* ...     AND GO TO SET CANON BLOCK LENGTH AND ADJUST BRANCHING INDEX */
    if (*it >= 50) {
	goto L165;
    }

/* ...     GET NUMBER OF DEFINITION FORMATS LISTED FOR THIS SURFACE */
/* ...     AND INDEX TO FIRST PARAMETER IN FORMAT LIST FOR THIS TYPE */
    jtemp[0] = adfprl_.deflst[isc - 1];
/* ...     IF NO FORMATS LISTED FOR THIS SURFACE TYPE, SKIP THE */
/* ...     SEARCH OPERATION */
    if (*in == 0) {
	goto L170;
    }

/*     LOOK THROUGH THIS DEFINITION LIST */
    i__1 = *in;
    for (jj = 1; jj <= i__1; ++jj) {
/*     GET NO. OF ITEMS IN LIST FOR THIS DEF. */
/* ...     AND NUMBER OF ITEMS IN DEFTAB FOR THIS DEFINITION */
	jtemp[1] = adfprl_.deflst[*if__ - 1];
	*nid = (shortint) (*nid + 1);
/*     GET ROUTINE BRANCHING INDEX */
/* ...     AND LOCATION OF NEXT DEFINITION IN THIS LIST */
	jtemp[2] = adfprl_.deflst[*if__];
	nr = ktemp[OTHER_ENDIAN_S(5)];
	*if__ = (shortint) (*if__ + 1);
/*     IS LENGTH OF DATA UNIQUE (NID.EQ.1, NO) */
	if (*nid == 1) {
	    goto L115;
	}
/* ...     SEE IF NO. OF WORDS USED IN DEFTAB MATCHES THIS FORMAT */
	if (*nid != idftab[OTHER_ENDIAN_S(1)]) {
	    goto L160;
	}
/* ...     YES - DO NO. OF ITEMS OF INPUT MATCH */
L115:
	if (*nil != inpr / 2) {
	    goto L160;
	}

/*     YES - CHECK LIST ITEM BY ITEM */
	*if__ = (shortint) (*if__ + 1);
	inpl = inpr / 2;
	i__2 = inpl;
	for (ii = 1; ii <= i__2; ++ii) {
L120:
	    jtm = (*if__ << 1) - 1;
	    jtm2 = (ii << 1) - 1;
	    if (adfprl_.deflst[*if__ - 1] > 0) {
		goto L140;
	    }
/* ...     SEVERAL PARAMETER TYPES POSSIBLE - CHECK ALL */
	    jtm3 = kdflst[OTHER_ENDIAN_S(jtm - 1)];
	    if (abs(jtm3) != kprotp[OTHER_ENDIAN_W(jtm2 - 1)]) {
		goto L125;
	    }
	    if (kdflst[OTHER_ENDIAN_S(jtm)] == 0) {
		goto L130;
	    }
	    if (kdflst[OTHER_ENDIAN_S(jtm)] == kprotp[OTHER_ENDIAN_W(jtm2)]) {
		goto L130;
	    }
L125:
	    *if__ = (shortint) (*if__ + 1);
	    goto L120;

/*     SURFACE TYPES MATCH - DISREGARD OTHER POSSIBILITIES */
L130:
	    *if__ = (shortint) (*if__ + 1);
	    if (adfprl_.deflst[*if__ - 1] < 0) {
		goto L130;
	    }
	    goto L150;

L140:
	    if (kdflst[OTHER_ENDIAN_S(jtm)] != 0) {
		goto L145;
	    }
/*     CHECK CODE ONLY - NOT LOCATION IN DEFTAB */
	    if (kdflst[OTHER_ENDIAN_S(jtm - 1)] != kprotp[OTHER_ENDIAN_W(jtm2 - 1)]) {
		goto L160;
	    }
	    goto L150;

L145:
	    if (adfprl_.deflst[*if__ - 1] != jprotp[OTHER_ENDIAN_S(ii - 1)]) {
		goto L160;
	    }
L150:
	    *if__ = (shortint) (*if__ + 1);
	}

/*     GOT HIM - ISC IS SURFACE CODE, NR IS SPECIFIC DEF. NO. */
	goto L170;
/*     SET LOCATION OF NEXT LIST FOR THIS DEF. */
L160:
	*if__ = *ifnxt;
    }

/*     METHOD OF DEFINITION UNKNOWN */
L162:
    a1com_.jsuber = 1000;
    goto L190;

/*     SET LENGTH TO 5 FOR LARGE SURFACE */
L165:
    *il = 5;
/* ...     DECREMENT ISC TO BRING IT WITHIN RANGE FOR BRANCHING */
/* ...     INDEX USE */
    isc += -31;

/*     CLEAR DEFANS AREA */
L170:
    for (jj = 1; jj <= 25; ++jj) {
/* L175: */
	defans[jj - 1] = 0.;
    }
/*     BRANCH TO VARIOUS SURFACE TYPE DEFINITIONS */
    switch ((int)isc) {
	case 1:  goto L1010;
	case 2:  goto L1020;
	case 3:  goto L1030;
	case 4:  goto L1040;
	case 5:  goto L1050;
	case 6:  goto L1060;
	case 7:  goto L1070;
	case 8:  goto L1080;
	case 9:  goto L1090;
	case 10:  goto L1100;
	case 11:  goto L1110;
	case 12:  goto L1120;
	case 13:  goto L1130;
	case 14:  goto L1140;
	case 15:  goto L1150;
	case 16:  goto L1160;
	case 17:  goto L1170;
	case 18:  goto L1175;
	case 19:  goto L1180;
	case 20:  goto L1190;
	case 21:  goto L1200;
	case 22:  goto L1210;
	case 23:  goto L1220;
    }
/* ...  POINTS */
L1010:
    if (nr == 11) {
	goto L1011;
    }
    apoint_(&nr);
    goto L180;
L1011:
    atabpt_();
    azvalu_();
    goto L180;
/* ...  LINES */
L1020:
    if (nr == 13) {
	goto L1021;
    }
    aline_(&nr);
    goto L180;
L1021:
    atabln_();
    goto L180;
/* ...  PLANES */
L1030:
    aplan_(&nr);
    goto L180;
/* ...  CIRCLES */
L1040:
    if (nr == 13) {
	goto L1041;
    }
    acircl_(&nr);
    goto L180;
L1041:
    atabcr_();
    goto L180;
/* ...  CYLINDERS */
L1050:
    acylnd_(&nr);
    goto L180;
/* ...  ELLIPSES */
L1060:
    aelp01_();
    goto L180;
/* ...  HYPERBOLAS */
L1070:
    ahypr1_();
    goto L180;
/* ...  CONES */
L1080:
    acone1_();
    goto L180;
/* ...  GENERAL CONIC */
L1090:
    agencn_(&nr);
    goto L180;
/* ...  LOFT CONICS */
L1100:
    alftcn_(&nr);
    goto L180;
/* ...  VECTORS */
L1110:
    avecdf_(&nr);
    goto L180;
/* ...  MATRICES */
L1120:
    amatx_(&nr);
    goto L180;
/* ...  SPHERES */
L1130:
    aspher_(&nr);
    goto L180;
/* ...  QUADRICS */
L1140:
    aqadr1_();
    goto L180;
/* ...  POLYCONIC */
L1150:
    a1com_.jsuber = 1000;
    goto L190;
/* ...  LOFT */
L1160:
    xloftx_(&nr);
    goto L190;
/* ...  TOOL */
L1170:
    a1com_.jsuber = 1000;
    goto L190;
/* ...     PATTERNS */
L1175:
    patgen_(il);
    goto L180;
/* ...  TABCYL */
L1180:
    idfp1 = a1pas2_1.idefp + 1;
    for (iy = idfp1; iy <= 1000; ++iy) {
/* L1185: */
	deftab[iy - 1] = 0.;
    }
    a1com_.namsub = ns;
    aprepr_();
    goto L180;
/* ...     MESH */
L1190:
    mshpre_();
    goto L190;
/* ...     CONIC SECTIONS */
L1200:
    a1com_.jsuber = 1000;
    goto L190;
/* ...     RULED SURFACE */
L1210:
    arldsf_();
    goto L190;
/* ...     ELMSRF FOR DAC */
L1220:
    elmpre_();
    goto L190;

/* ...     CANON DEFINITION OF TABCYL... */
/* ...     IF SURFACE NOT READ IN, CONVERT SECOND WORD TO INTEGER */
L1300:
    if (iread == 0) {
	goto L1305;
    }
    idftab[OTHER_ENDIAN_S(3)] = (integer) deftab[1];
    idftab[OTHER_ENDIAN_S(2)] = 0;
/* ...     SET LENGTH OF CANON BLOCK */
L1305:
    *il = 5;
/* ...     ADJUST LENGTH IN FIRST WORD */
    ++idftab[OTHER_ENDIAN_S(1)];
    goto L190;

/* ...     MOVE INPUT CANONICAL FORM TO DEFSTO AREA */
L176:
    i__1 = *il;
    for (a1pas2_1.j = 4; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
/* L178: */
	adfsto_.defsto[a1pas2_1.j - 1] = deftab[a1pas2_1.j - 2];
    }
/* ...     CHECK VALIDITY OF CANONICAL FORM */
    if (modef <= 0) {
	goto L180;
    }

    acanck_(it);

/* ...     RESTORE NAME AND SUBSCRIPT FOR ERROR DIAGNOSTICS */
L180:
L190:
    a2cls7_1.ename = a2cls7_1.einame;
    a1com_.namsub = ns;
    a1com_.name__ = ls;
/* ...     SEE IF THERE WAS AN ERROR IN THE DEFINITION */
    if (a1com_.jsv < 0) {
	goto L199;
    } else if (a1com_.jsv == 0) {
	goto L192;
    } else {
	goto L195;
    }
L192:
    if (a1com_.jsuber == 0) {
	goto L200;
    }

/*     YES, IS SURFACE NESTED, UNNAMED */
L195:
    if (ls == 0) {
	goto L198;
    }

/* ...     NO - TEST FOR SUBSCRIPT */
    if (a1com_.namsub != 0) {
	goto L196;
    }
    ++a1com_.name__;
    goto L197;
/* ...     YES - GET POINTER TO ENTRY IN SUBSCRIPT ARRAY */
L196:
    avs2ck_(&a1pas2_1.j);
/* ...     COMPUTE INDEX FOR STORAGE OF ERROR CODE */
L197:
    ils = (a1com_.name__ << 1) - 1;
    ivst[OTHER_ENDIAN_S(ils - 1)] = 9;
    goto L199;

/*       SET SURFTB NEST ERROR FLAG FOR NESTED, UNNAMED SURFACE */
L198:
    ascalr_.scalr[ascalr_.iscws - 1] = *errcod;
	//assert(0);//'cause I don't know how errcod works.
L199:
    return 0;

/* ...     PUT SURFACE TYPE AND LENGTH INTO 1ST WORD OF CANON ENTRY */
L200:
    adfsto_.defsto[0] = *ptemp;

/* ...     SEE WHETHER OR NOT THIS IS AN UNNAMED SURFACE (NESTED) */
    if (ls != 0) {
	goto L215;
    }

/* ...     YES, IT IS - SET UP 2ND AND 3RD WORDS OF CANON ENTRY */
    adfsto_.defsto[1] = 0.;
    adfsto_.defsto[2] = 0.;
    goto L217;

/* ...     SURFACE IS NAMED - SET UP 2ND AND 3RD WORDS OF CANON ENTRY */
L215:
    adfsto_.defsto[1] = a1com_.refsys;
    idfsto[OTHER_ENDIAN_S(4)] = ls;
    idfsto[OTHER_ENDIAN_S(5)] = ns;
/* ...     RESTORE VST INDEX AND SUBSCRIPT FOR SURFACE BEING DEFINED */
    a1com_.name__ = ls;
    a1com_.namsub = ns;
/* ...     PUT SURFACE IN CANON */
L217:
    acanpt_();
    if (a1com_.jsuber != 0) {
	goto L195;
    }

    if (a1com_.kdbug == 0) {
	goto L220;
    }
/* ...     IF DEFINING A LARGE SURFACE, SKIP TEST FOR POSSIBLE PRINTING */
L220:
    if (*it >= 50) {
	goto L250;
    }
/* ...     ALSO FOR PATTERNS FOR NOW */
    if (*it == 18) {
	goto L250;
    }
/* ...     NOT A LARGE SURFACE - SEE IF PRINT FLAG IS ON */
    if (a1pas2_1.kprnt == 0) {
	goto L250;
    }
/* ...     YES - PICK UP SURFACE TYPE, AND ADJUST LENGTH FOR PRINTING */
    stype = a1stab_.stable[*it - 1];
    *il += -3;

/* ...     SEE WHETHER OR NOT SURFACE IS NAMED */
    if (ls != 0) {
	goto L230;
    }

/* ...     NO, IT IS NOT - PRINT TYPE, LENGTH, AND CANONICAL FORM */
    io___55.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___55);
    do_fio(&c__1, (char *)&stype, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*il), (ftnlen)sizeof(integer));
    i__1 = *il;
    for (ii = 1; ii <= i__1; ++ii) {
	do_fio(&c__1, (char *)&defans[ii - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
	//added this to view surfaces in cad programs with dxf
#ifdef HAVE_DXFLIB_DL_DXF_H 
	export_surf(idfsto,adfsto_.defsto,&a2cls7_1.einame,&ns);
#endif
    goto L250;

/* ...     SURFACE IS NAMED - PRINT NAME, SUBSCRIPT, TYPE, LENGTH, */
/* ...     AND CANONICAL FORM */
L230:
    io___56.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___56);
    do_fio(&c__1, (char *)&a2cls7_1.einame, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&stype, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*il), (ftnlen)sizeof(integer));
    i__1 = *il;
    for (ii = 1; ii <= i__1; ++ii) {
	do_fio(&c__1, (char *)&defans[ii - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();

//	added this to view surfaces in cad programs with dxf
#ifdef HAVE_DXFLIB_DL_DXF_H 
	export_surf(idfsto,adfsto_.defsto,&a2cls7_1.einame,&ns);
#endif
L250:
    return 0;
} /* adfpre_ */

#undef errcod
#undef skipar
#undef kprotp
#undef jprotp
#undef knclus
#undef idfsto
#undef kdflst
#undef kargpn
#undef defans
#undef idftab
#undef deftab
#undef iptpp
#undef itray
#undef ifnxt
#undef ptemp
#undef ktemp
#undef jtemp
#undef canon
#undef ivst
#undef ptpp
#undef karg
#undef idat
#undef nil
#undef nid
#undef it
#undef in
#undef il
#undef if__
#undef a1


