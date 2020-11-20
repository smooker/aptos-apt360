/* AMATMV.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

static struct {
    doublereal protap, dumtap, cltape, poctap, plotap, srftap, tapes1, tapes2,
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

static struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

static struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

static struct {
    doublereal amacvr[50], amacvl[50];
    integer macicl[50];
    doublereal defnam, segnam;
    integer ivarct, isysmc, irdmod, luup, nwunrd, nolibr;
} alibry_;

#define alibry_1 alibry_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__10 = 10;
static integer c__2 = 2;
static integer c__4 = 4;

/* Subroutine */ int amatmv_()
{
    /* Format strings */
    static char fmt_15[] = "(\002 THE MACRO  \002,a8,\002 USES \002,i6,\002 \
 LOCATIONS IN CANON \002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, j, k, l, m, n, km, iq, lad, leg, lmd, idt, legm, nrec,
	     live, look, kret;
#define ptpp ((doublereal *)&avst_1)
    static integer nvst;
    static doublereal aname;
#define canon ((doublereal *)&avst_1)
    extern /* Subroutine */ int agetr_();
    static integer legrm;
    static doublereal stuff[3];
    static integer nwrds;
    extern doublereal afull8_();
    extern /* Subroutine */ int avs1pt_();
    static integer maclib, libmac, ioflag;
    extern integer amatod_(), amdtoa_();
#define cantap ((doublereal *)&ataptb_1 + 5)
    extern /* Subroutine */ int aserch_(), ataprd_();
    extern integer aextra_(), aextrd_();
    extern /* Subroutine */ int atapwt_(), atapop_();
    static integer mstarc, mstart;

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 0, 0, fmt_15, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */

    look = 0;
    switch ((int)amacro_1.jwhat) {
	case 1:  goto L400;
	case 2:  goto L10;
	case 3:  goto L100;
	case 4:  goto L70;
    }
L10:
    lmd = amacro_1.lmdw / a0con_1.k5;
    stuff[0] = alibry_1.defnam;
    stuff[1] = afull8_(&amacro_1.macvst, &lmd);
    stuff[2] = afull8_(&amcstf_1.numids, &amacro_1.nitems);
    l = amacro_1.lmdw + amacro_1.nitems + a0con_1.k3;
/* ...  PRINT OUT EXTENT OF CANON FOR THIS MACRO */
    io___8.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___8);
    do_fio(&c__1, (char *)&alibry_1.defnam, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
    e_wsfe();
/*     WILL IT FIT IN CANON */
    if (amacro_1.limcan + l <= amxtab_1.maxtab) {
	goto L20;
    }
/* ...     SEE IF IT WILL FIT IN CANON AT ALL */
    if (l > amxtab_1.maxtab - amxtab_1.maxvst - amxtab_1.mxptpp) {
	goto L295;
    }
    aserch_(cantap, &amacro_1.macrec, &ioflag);
    if (ioflag >= a0con_1.k0) {
	goto L1760;
    }
    atapwt_(cantap, &ioflag, &a0con_1.k4, &amacro_1.macrec, &a0con_1.k1, &idt,
	     &c__1, &idt, &c__1, stuff, &c__3);
    if (ioflag >= a0con_1.k0) {
	goto L1770;
    }
/*     UPDATE VST */
    i__1 = amatod_(&amacro_1.macrec, &c__2);
    avst_1.vst[amacro_1.macvst] = afull8_(&c__10, &i__1);
    amacro_1.macrec += a0con_1.k1;
    atapwt_(cantap, &ioflag, &a0con_1.k5, &amacro_1.macrec, &a0con_1.k1, &idt,
	     &c__1, &idt, &c__1, &canon[amacro_1.limcan + 3], &amacro_1.lmdw, 
	    &ptpp[amxtab_1.maxvst], &amacro_1.nitems);
    ++amacro_1.macrec;
    if (ioflag >= a0con_1.k0) {
	goto L1770;
    }
    return 0;
L20:
    j = amacro_1.limcan;
    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
	j += a0con_1.k1;
/* L30: */
	canon[j - 1] = stuff[i__ - 1];
    }
    j += amacro_1.lmdw;
    i__1 = amacro_1.nitems;
    for (i__ = a0con_1.k1; i__ <= i__1; ++i__) {
	j += a0con_1.k1;
	lad = amxtab_1.maxvst + i__;
/* L50: */
	canon[j - 1] = ptpp[lad - 1];
    }
/*     UPDATE  VST */
    i__1 = amacro_1.limcan + 1;
    avst_1.vst[amacro_1.macvst] = afull8_(&a0con_1.k10, &i__1);
/*     UPDATE CANON LIMIT */
    amacro_1.limcan += l;
L60:
    return 0;
/*     SEARCH MACLIB FOR SYSTEM MACRO */
L70:
    atapop_(&maclib, &a0con_1.k1, &ioflag);
    aserch_(&maclib, &a1com_1.name__, &ioflag);
    if (ioflag == a0con_1.k1) {
	goto L80;
    }
    if (ioflag > a0con_1.k1) {
	goto L1790;
    }
/*     GET ID RECORD */
    ataprd_(&maclib, &ioflag, &nwrds, &a0con_1.k4, &nrec, &a0con_1.k1, &idt, &
	    c__1, &idt, &c__1, stuff, &c__3);
    libmac = a0con_1.k1;
    goto L110;
/*     NOT THERE */
L80:
    a1com_1.jsuber = 101;
    return 0;
/*     EXTRACT MACRO RECORD NUMBER */
L100:
    if (amacro_1.jwhat == 1) {
	goto L60;
    }
    i__1 = aextra_(&avst_1.vst[amacro_1.macvst], &c__4);
    nrec = amdtoa_(&i__1, &c__2);
/*     GET ID RECORD */
    aserch_(cantap, &nrec, &ioflag);
    if (ioflag >= a0con_1.k0) {
	goto L1790;
    }
    ataprd_(cantap, &ioflag, &nwrds, &a0con_1.k4, &nrec, &a0con_1.k1, &idt, &
	    c__1, &idt, &c__1, stuff, &c__3);
    libmac = a0con_1.k0;
L110:
    if (ioflag >= a0con_1.k0) {
	goto L1800;
    }
/*     COMPUTE LENGTH OF MACRO */
    l = a0con_1.k5 * aextra_(&stuff[1], &a0con_1.k4) + aextra_(&stuff[2], &
	    a0con_1.k4) + a0con_1.k3;
    amacro_1.nitems = l - a0con_1.k3;
/*     WILL THE MACRO FIT IN CANON */
    if (amacro_1.limcan + l > amxtab_1.maxtab) {
	goto L170;
    }
/*     YES,IT WILL - CHECK JWHAT FLAG FOR MACRO VARIABLE CALL */
    j = amacro_1.limcan;
    for (i__ = a0con_1.k1; i__ <= 3; ++i__) {
	j += a0con_1.k1;
/* L130: */
	canon[j - 1] = stuff[i__ - 1];
    }
    j += a0con_1.k1;
/*     CHECK LIBMAC TO READ FROM PROPER DATA SET */
    if (libmac == a0con_1.k0) {
	goto L140;
    }
/*     READ FROM SYSTEM MACRO LIBRARY */
    ataprd_(&maclib, &ioflag, &nwrds, &a0con_1.k4, &nrec, &a0con_1.k1, &idt, &
	    c__1, &idt, &c__1, &canon[j - 1], &amacro_1.nitems);
    avs1pt_(&kret);
    if (kret == a0con_1.k1) {
	goto L150;
    }
    if (kret == a0con_1.k2) {
	goto L160;
    }
    a1com_1.jsuber = 1002;
    a1com_1.sum = 1;
    return 0;
L160:
    a1com_1.jsuber = 15;
    a1com_1.sum = 1;
    return 0;
/*     READ FROM CANTAP */
L140:
    ataprd_(cantap, &ioflag, &nwrds, &a0con_1.k4, &nrec, &a0con_1.k1, &idt, &
	    c__1, &idt, &c__1, &canon[j - 1], &amacro_1.nitems);
L150:
    if (ioflag >= a0con_1.k0) {
	goto L1800;
    }
/*     SET LOCATION OF MACRO */
    amacro_1.lmdw = amacro_1.limcan + a0con_1.k1;
/*     UPDATE LIMCAN */
    amacro_1.limcan += l;
/*     UPDATE VST */
    nvst = aextra_(&avst_1.vst[a1com_1.namsub], &a0con_1.k4);
    i__1 = aextrd_(&nvst, &a0con_1.k2) + amacro_1.lmdw;
    agetr_(&i__1, &avst_1.vst[a1com_1.namsub], &a0con_1.k3);
    return 0;
/*     MAKE ROOM */
L170:
    mstarc = amxtab_1.maxvst + amxtab_1.mxptpp;
L175:
    mstart = mstarc + a0con_1.k1;
    legrm = a0con_1.k0;
L180:
    aname = canon[mstart - 1];
/*     EXTRACT VST INDEX */
    m = amdtoa_(&canon[mstart], &a0con_1.k4);
    n = aextra_(&canon[mstart], &a0con_1.k4);
    leg = a0con_1.k5 * n + aextra_(&canon[mstart + 1], &a0con_1.k4) + 
	    a0con_1.k3;
/*     CURRENT MACRO */
    k = amcstf_1.maccur - a0con_1.k1;
    if (k == a0con_1.k0) {
	goto L190;
    }
    i__1 = k;
    for (i__ = a0con_1.k1; i__ <= i__1; ++i__) {
	if (amcstf_1.macnam[i__ - 1] == aname) {
	    goto L280;
	}
/* L185: */
    }
/*     NOT CURRENT */
L190:
    live = a0con_1.k0;
/*     IS IT OUT ON FILE */
    nvst = aextra_(&avst_1.vst[m], &a0con_1.k4);
    iq = amdtoa_(&nvst, &c__2);
    if (iq != 0) {
	goto L210;
    }
/*     NO  - MOVE IT OUT - ARE WE AT END OF CANTAP */
    if (look != a0con_1.k0) {
	goto L200;
    }
/*     NO - GET US THERE */
    aserch_(cantap, &amacro_1.macrec, &ioflag);
    if (ioflag >= a0con_1.k0) {
	goto L1760;
    }
    look = a0con_1.k1;
/*     UPDATE VST TO SHOW MACRO IS ON FILE */
L200:
    iq = amacro_1.macrec;
    atapwt_(cantap, &ioflag, &a0con_1.k4, &amacro_1.macrec, &a0con_1.k1, &idt,
	     &c__1, &idt, &c__1, &canon[mstart - 1], &c__3);
    if (ioflag >= a0con_1.k0) {
	goto L1770;
    }
    amacro_1.macrec += a0con_1.k1;
    i__1 = leg - 3;
    atapwt_(cantap, &ioflag, &a0con_1.k4, &amacro_1.macrec, &a0con_1.k1, &idt,
	     &c__1, &idt, &c__1, &canon[mstart + 2], &i__1);
    ++amacro_1.macrec;
    if (ioflag >= a0con_1.k0) {
	goto L1770;
    }
L210:
    legrm += leg;
    mstart += leg;
    i__1 = amatod_(&iq, &c__2);
    agetr_(&i__1, &avst_1.vst[m], &c__3);
/*     IS THERE ROOM WITHOUT THIS MACRO */
    if (amacro_1.limcan - legrm + l <= amxtab_1.maxtab) {
	goto L215;
    }
/*     NO - LOOK FOR MORE */
    if (mstart <= amacro_1.limcan) {
	goto L180;
    }
    a1com_1.jsuber = 178;
    return 0;
L215:
    if (mstart <= amacro_1.limcan) {
	goto L220;
    }
    amacro_1.limcan -= legrm;
    goto L100;
/*     SQUEEZE CANON */
L220:
    km = mstarc;
    i__1 = amacro_1.limcan;
    for (i__ = mstart; i__ <= i__1; ++i__) {
	++km;
/* L230: */
	canon[km - 1] = canon[i__ - 1];
    }
/*     UPDATE TABLES */
    amacro_1.limcan -= legrm;
    km = mstarc + a0con_1.k1;
L240:
    aname = canon[km - 1];
    m = amdtoa_(&canon[km], &a0con_1.k4) + a0con_1.k1;
    n = aextra_(&canon[km], &a0con_1.k4);
    legm = a0con_1.k5 * n + aextra_(&canon[km + 1], &a0con_1.k4) + a0con_1.k3;
/*     UPDATE VST */
    nvst = aextra_(&avst_1.vst[m - 1], &a0con_1.k4);
    i__1 = aextrd_(&nvst, &a0con_1.k2) + km;
    agetr_(&i__1, &avst_1.vst[m - 1], &a0con_1.k3);
/*     IS THIS CURRENT MACRO */
    if (k == a0con_1.k0) {
	goto L260;
    }
    i__1 = k;
    for (i__ = a0con_1.k1; i__ <= i__1; ++i__) {
	if (amcstf_1.macnam[i__ - 1] == aname) {
	    goto L270;
	}
/* L250: */
    }
L260:
    km += legm;
/*     ARE WE FINIDHED */
    if (km < amacro_1.limcan) {
	goto L240;
    }
/*     YES - CHECK FOR A LIVE ONE - IF NOT, READ IN MACRO */
    if (live == 0) {
	goto L100;
    }
/*     YES - SKIP OVER */
    goto L290;
/*     UPDATE NESTED MACRO TABLE */
L270:
    amcstf_1.maclcn[i__ - 1] -= legrm;
    amcstf_1.macstr[i__ - 1] = km;
    goto L260;
/*     SKIP OVER ACTIVE MACRO - IS THERE ANY SQUEEZING TO DO */
L280:
    if (legrm != a0con_1.k0) {
	goto L300;
    }
/*     NO - ALTER CANON STARTING LOCATION */
L290:
    mstarc += leg;
/*     CHECK FOR CANON FULL OF LIVE ONES */
    if (mstarc < amacro_1.limcan) {
	goto L175;
    }
/*     YES - NO ROOM -JSUBER IT */
L295:
    a1com_1.jsuber = 178;
    a1com_1.name__ = avst_1.vst[amacro_1.macvst - 1];
    a1com_1.sum = 1;
    return 0;
/*     HERE IS A LIVE ONE */
L300:
    live = a0con_1.k1;
    goto L220;
/*     GET ROOM FOR MACRO VARIABLES */
L400:
    l = amacro_1.lmdw + 3;
    goto L170;
L1760:
    a1com_1.jsuber = 176;
    return 0;
L1770:
    a1com_1.jsuber = 177;
    return 0;
L1790:
    a1com_1.jsuber = 179;
    return 0;
L1800:
    a1com_1.jsuber = 180;
    return 0;
} /* amatmv_ */

#undef cantap
#undef canon
#undef ptpp


