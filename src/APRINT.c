/* APRINT.f -- translated by f2c (version 20000121).
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
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

struct {
    doublereal synb[100];
    integer insyn, maxsyn;
} asyntb_;

#define asyntb_1 asyntb_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

struct {
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

struct {
    doublereal elment[600];
    integer iclass[600], jlment;
} ailmtb_;

#define ailmtb_1 ailmtb_

struct {
    integer nextnw, nrelcn, kanlcn, locseq, nextcn, nwonrd, lplocn, jsw4, isn,
	     k, mxloop, jsw2, jsav, jsw1, maxmv, mxnest, inill, kf;
} abreak_;

#define abreak_1 abreak_

struct {
    doublereal scalr[180];
    integer iscws, nsurf, loctem, iargtp;
} ascalr_;

#define ascalr_1 ascalr_

struct {
    integer ilpcnt, irpcnt, ilvcnt;
} apartb_;

#define apartb_1 apartb_

struct {
    integer istarp, iendp, nmove, nl, itsq, lindx;
} aprtab_;

#define aprtab_1 aprtab_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

struct {
    integer limcan, lmdw, nitems, jwhat, macrec, macvst, macerr;
} amacro_;

#define amacro_1 amacro_

struct {
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal macnam[5];
    integer maccur, maclcn[5], macrd, macstr[5], nmacvr, numids, idlocn, 
	    macids[5], isvid;
} amcstf_;

#define amcstf_1 amcstf_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int aprint_(number)
integer *number;
{
    /* Format strings */
    static char fmt_11[] = "(\0020\002,4x,\002WORD\002,7x,\002ICLASS\002,1\
1x,\002ELMENT\002)";
    static char fmt_19[] = "(5x,i4,z9,z2,2x,z2,z20)";
    static char fmt_21[] = "(\0020    MACRO BEING STORED\002/(5x,5z20/))";
    static char fmt_31[] = "(\0020\002,\002    MACRO \002,a6,\002 - -\002,\
i3,\002 MACRO VARIABLES\002)";
    static char fmt_33[] = "(\002+\002,39x,\002, AS FOLLOWS -\002/7x,\002N\
AME\002,17x,\002NORMAL VALUE\002,27x,\002ASSIGNED VALUE\002)";
    static char fmt_35[] = "(6x,a6,2z20,4x,2z20)";
    static char fmt_36[] = "(\0020    SQUEEZED MACRO AT CANON(\002,i4,\002\
)\002//(\002+    \002,5z20/))";
    static char fmt_41[] = "(\0020    RETURNING TO MACRO \002,a6)";
    static char fmt_61[] = "(\0020\002,20x,i3,\002 MACRO VARIABLES\002)";
    static char fmt_71[] = "(\0020    MACRO \002,a6,\002 CALLED\002)";
    static char fmt_75[] = "(\002     LEVEL\002,i4,\002, KANLCN =\002,i6,\
\002, NMACVR =\002,i4,\002, MACSTR(\002,i2,\002) =\002,i6)";
    static char fmt_121[] = "(\0020\002,4x,\002VOCABULARY WORD, ICLASS TYP\
E\002,i4,\002,  SUBTYPE\002,i4)";
    static char fmt_91[] = "(\0020\002,10x,\002SYNONYM TABLE CONTENTS\002/(9\
x,a6,z20/))";

    /* System generated locals */
    integer i__1, i__2;
    static integer equiv_1[1];

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
    static integer i__, j, l, ll, mm, nn, ls, lp4, lbb;
#define vst2 ((shortint *)&avst_1)
    static integer jend;
#define ptpp ((doublereal *)&avst_1)
#define canon ((doublereal *)&avst_1)
#define gtemp ((logical1 *)equiv_1)
#define ktemp ((shortint *)equiv_1)
#define itemp (equiv_1)
#define icanon ((integer *)&avst_1)
    static integer jstart;

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___12 = { 0, 0, 0, fmt_19, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_35, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_36, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_61, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_35, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_71, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_91, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ********* */
/* ********* */
/* ********* */
/*  NOTE - - - IN ALL OF THE CALLS TO SUBROUTINE HEX, REFERENCES TO */
/*             PTPP ARE ACTUALLY REFERENCES TO CANON - THE RELATIVE INDEX */
/*             HAS BEEN ADJUSTED BY 2225 TO PERMIT THIS. */
/* ********* */
/* ********* */
/* ********* */

    if (a1com_1.debug == 0) {
	goto L999;
    }
    switch ((int)*number) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
    }

L1:
    jstart = 1;
    jend = ailmtb_1.jlment;
L10:
    io___10.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___10);
    e_wsfe();
    i__1 = jend;
    for (i__ = jstart; i__ <= i__1; ++i__) {
	*itemp = ailmtb_1.iclass[i__ - 1];
	gtemp[OTHER_ENDIAN_W(3)] = gtemp[OTHER_ENDIAN_W(2)];
/* L18: */
	io___12.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___12);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ktemp[OTHER_ENDIAN_S(0)], (ftnlen)sizeof(shortint));
	do_fio(&c__1, (char *)&ktemp[OTHER_ENDIAN_S(1)], (ftnlen)sizeof(shortint));
	do_fio(&c__1, (char *)&ailmtb_1.iclass[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&ailmtb_1.elment[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
    }
    goto L999;

L5:
    jstart = aprtab_1.istarp - 10;
    jend = aprtab_1.iendp + 5;
    if (jend <= ailmtb_1.jlment) {
	goto L51;
    }
    jend = ailmtb_1.jlment;
L51:
    if (jstart <= 0) {
	goto L1;
    } else {
	goto L10;
    }

L2:
    io___13.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___13);
    i__1 = amacro_1.nitems;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ptpp[j - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L999;

/* ...     GET SUBSCRIPT TO MACRO NAME IN VST */
L3:
    j = (amacro_1.macvst << 2) - 3;
    mm = vst2[OTHER_ENDIAN_W(j + 6)];
    nn = (mm << 1) - 1;
/* ...     GET NUMBER OF MACRO VARIABLES */
    j = icanon[OTHER_ENDIAN_S(nn + 2)];
    abreak_1.k = icanon[OTHER_ENDIAN_S(nn + 4)];
    io___17.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___17);
    do_fio(&c__1, (char *)&canon[mm - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
    e_wsfe();
    l = mm - 2;
/* ...     TEST FOR EXISTENCE OF MACRO VARIABLES */
    if (j == 0) {
	goto L37;
    }

    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    e_wsfe();
    j *= 5;
    i__1 = j;
    for (i__ = 1; i__ <= i__1; i__ += 5) {
	l = mm + 2 + i__;
/* L34: */
	io___20.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___20);
	do_fio(&c__1, (char *)&ptpp[l - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ptpp[l], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ptpp[l + 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ptpp[l + 2], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ptpp[l + 3], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

L37:
    l += 5;
    ll = l + abreak_1.k - 1;
    io___22.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___22);
    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
    i__1 = ll;
    for (j = l; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ptpp[j - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    goto L999;

L4:
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&amcstf_1.macnam[amcstf_1.maccur - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    goto L74;

L6:
    ls = amacro_1.lmdw / 5;
    io___25.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___25);
    do_fio(&c__1, (char *)&ls, (ftnlen)sizeof(integer));
    e_wsfe();
    if (amacro_1.lmdw == 0) {
	goto L999;
    }
    io___26.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___26);
    e_wsfe();
    lbb = amacro_1.limcan - 1;
    i__1 = ls;
    for (l = 1; l <= i__1; ++l) {
	lbb += 5;
	lp4 = lbb + 4;
	io___29.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___29);
	i__2 = lp4;
	for (j = lbb; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&ptpp[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
/* L62: */
    }
    goto L999;

L7:
    io___30.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___30);
    do_fio(&c__1, (char *)&amcstf_1.macnam[amcstf_1.maccur - 1], (ftnlen)
	    sizeof(doublereal));
    e_wsfe();
    if (amcstf_1.maccur <= 1) {
	goto L3;
    }

L74:
    io___31.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___31);
    do_fio(&c__1, (char *)&amcstf_1.maccur, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&abreak_1.kanlcn, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amcstf_1.nmacvr, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amcstf_1.maccur, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&amcstf_1.macstr[amcstf_1.maccur - 1], (ftnlen)
	    sizeof(integer));
    e_wsfe();
    if (*number == 4) {
	goto L999;
    }
    goto L3;

L8:
    io___32.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&aptpp_1.klass, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&aptpp_1.klastp, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L999;

L9:
    io___33.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___33);
    i__1 = asyntb_1.insyn;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&asyntb_1.synb[j - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L999;
L999:
    return 0;
} /* aprint_ */

#undef icanon
#undef itemp
#undef ktemp
#undef gtemp
#undef canon
#undef ptpp
#undef vst2


