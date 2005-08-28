/* APTPUT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */
doublereal debug;
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
    doublereal pt[300];
    integer inptp, nw, jmode, klass, klastp, irecn, npt, npr;
} aptpp_;

#define aptpp_1 aptpp_

struct {
    doublereal ppseq1, ppseq2, idis;
    integer iisn, idvst, kfk;
} aklas7_;

#define aklas7_1 aklas7_

struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Table of constant values */

static integer c__1 = 1;
static integer c__4 = 4;

/* Subroutine */ int aptput_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_23 = { {'I', 'O', 'F', 'L', 'A', 'G', ' ', ' '}, 0. };

#define flag__ (*(doublereal *)&equiv_23)


    /* Format strings */
    static char fmt_333[] = "(\002 *** PTPP SEGMENTATION OCCURED JUST PRIOR \
TO ISN   \002,i6)";
    static char fmt_34[] = "(\002 PTPP(\002,i5,\002)\002,4(z9,z10,7x))";

    /* System generated locals */
    integer i__1, i__2;
    static integer equiv_1[1];

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static integer i__, j, k, in, max__;
#define ndx (equiv_1)
#define ipt ((integer *)&aptpp_)
    static integer nogo;
#define kndx ((shortint *)equiv_1)
    static integer jsav;
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
    static integer indxs;
#define iptpp ((integer *)&avst_1)
    static integer jtemp1, iptpp1, iptpp2;
    extern /* Subroutine */ int adiagp_();
    static integer ioflag;
    extern /* Subroutine */ int atapwt_();
#define ptptap ((doublereal *)&ataptb_1 + 3)

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 0, 0, fmt_333, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_34, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/* ..                                                                  D39 */
/*     NW CONTAINS TOTOAL NO. OF WPRDS IN PTPP CLASS (JMODE=3) */
/*     IT IS SET TO ZERO AFTER PROCESSING JMODE=3,4,OR 5 */
/*     INPTP CONTAINS NO. OF ITEMS TO BE MOVED TO PTPP */
/*     NPT AND NPR CONTAIN INFORMATION FOR SECOND ENTRY IN PTPP CLASS */
/*     JMODE=1 - BEGINNING CLASS OF DATA */
/*          =2 - CONTINUATION OF CLASS */
/*          =3 - TERMINATION OF CLASS */
/*          =4 - ERASE PTPP CLASS */
/*          =5 - COMPLETE CLASS OF DATA */
/*          =6 - FLUSH PTPP BUFFER */

    nogo = 0;
    if (aptpp_.jmode == 6) {
	goto L60;
    }
    if (aptpp_.jmode != 4) {
	goto L10;
    }

/*     RESET INDXPT */
L5:
    a1com_.indxpt = indxs;
    goto L80;

/*     IS NO. OF ENTRIES = 0 */
L10:
    if (aptpp_.inptp == 0) {
	goto L50;
    }
/*     SET BLOCK SIZE FOR NON-LOOP MODE */
    max__ = amxtab_.maxvst + 256;
/*     SET MAXIMUM PTPP SIZE */
    if (a1com_.loop != 0) {
	max__ = amxtab_.mxptpp + amxtab_.maxvst;
    }
/*     WILL DATA FIT */
L12:
    if (a1com_.indxpt + aptpp_.inptp <= amxtab_.mxptpp + amxtab_.maxvst) {
	goto L20;
    }

/* ...  LOOP TOO LARGE - CAN PART OF IT BE OUTPUT */
    if (nogo != 0) {
	goto L19;
    }

/* ...  RESET POINTERS TO OUTPUT PORTION OF LOOP */
    io___12.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___12);
    do_fio(&c__1, (char *)&aklas7_.iisn, (ftnlen)sizeof(integer));
    e_wsfe();
    nogo = a1com_.indxpt;
    a1com_.indxpt = indxs;
/* ...  GO WRITE IT OUT */
    goto L65;

L15:
    in = amxtab_.maxvst + 2;
/* ...  ANY RISIDUAL PART OF CURRENT PTPP CLASS TO MOVE */
    if (a1com_.indxpt == nogo) {
	goto L18;
    }
/* ...  YES - MOVE TO START OF PTPP */
    i__1 = nogo;
    for (i__ = a1com_.indxpt; i__ <= i__1; ++i__) {
	ptpp[in - 1] = ptpp[i__ - 1];
/* L17: */
	++in;
    }
/* ...  RESET POINTER */
L18:
    a1com_.indxpt = in;
/* ...  GO CHECK IF THERE IS ROOM FOR THIS PTPP CLASS BY ITSELF */
    goto L12;

/* ...  NOT ENOUGH ROOM FOR A SINGLE PTPP CLASS */
L19:
    a1com_.jsuber = 12;
    jsav = 12;
    goto L70;

L20:
    in = a1com_.indxpt;
/* ...  WAS THERE SEGMENTATION THIS GO AROUND */
    if (nogo == 0) {
	goto L25;
    }
/* ...  YES - - CHECK FOR A CLASS SEVEN PTPP RECORD */
    if (ipt[OTHER_ENDIAN_S(0)] != 7) {
	goto L25;
    }

/* ...  CLASS SEVEN FOUND....WAS THERE AN ID INVOLVED */
    if (aklas7_.idvst == 0) {
	goto L25;
    }
/* ...  YES - - UPDATE THE VST POINTER FOR THE ID TO REFLECT NEW RECORD */
    kndx[OTHER_ENDIAN_S(1)] = (shortint) (a1com_.indxpt - amxtab_.maxvst);
    kndx[OTHER_ENDIAN_S(0)] = (shortint) (aptpp_.irecn + 1);
    jtemp1 = (aklas7_.idvst << 1) - 1;
    ivst[OTHER_ENDIAN_S(jtemp1 + 1)] = 3;
    ivst[OTHER_ENDIAN_S(jtemp1 + 2)] = *ndx;
L25:
    i__1 = aptpp_.inptp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ptpp[in - 1] = aptpp_.pt[i__ - 1];
/* L30: */
	++in;
    }
    if (a1com_.debug == 0) {
	goto L35;
    }
    jtemp1 = in - 1;
    i__1 = jtemp1;
    for (k = a1com_.indxpt; k <= i__1; k += 4) {
	iptpp1 = (k << 1) - 1;
	iptpp2 = iptpp1 + 7;
	if (iptpp2 > jtemp1 << 1) {
	    iptpp2 = jtemp1 << 1;
	}
	io___20.ciunit = ataptb_1.ioutap;
	s_wsfe(&io___20);
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__2 = iptpp2;
	for (j = iptpp1; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&iptpp[OTHER_ENDIAN_S(j - 1)], (ftnlen)sizeof(integer));
	}
	e_wsfe();
/* L32: */
    }
L35:
    switch ((int)aptpp_.jmode) {
	case 1:  goto L40;
	case 2:  goto L50;
	case 3:  goto L50;
	case 4:  goto L5;
	case 5:  goto L45;
    }

/* ...     NEW OR COMPLETE CLASS - SAVE INDXPT */
L40:
    indxs = a1com_.indxpt;
    goto L50;

L45:
    indxs = in;
/*     UPDATE INDXPT */

L50:
    a1com_.indxpt = in;
/*     IS THIS END OF CLASS */
    if (aptpp_.jmode < 3) {
	return 0;
    }
    if (aptpp_.jmode != 3) {
	goto L55;
    }

/*     SET NO. OF WORDS IN PTPP CLASS */
    jtemp1 = (indxs << 1) - 1;
    iptpp[OTHER_ENDIAN_S(jtemp1)] = aptpp_.nw;
/*     IF NPT IS NON-ZERO, SET SECOND ENTRY IN PTPP */
    if (aptpp_.npt == 0) {
	goto L52;
    }
    iptpp[OTHER_ENDIAN_S(jtemp1 + 1)] = aptpp_.npt;
    iptpp[OTHER_ENDIAN_S(jtemp1 + 2)] = aptpp_.npr;
L52:
    aptpp_.npt = 0;
    indxs = in;

/*     YES - CHECK PTPP FOR OUTPUT */
L55:
    if (a1com_.indxpt <= max__) {
	goto L80;
    }
/*     FLUSH PTPP - IF ANYTHING */
L60:
    if (a1com_.indxpt == amxtab_.maxvst + 2) {
	return 0;
    }
L65:
    ++aptpp_.irecn;
	debug=*ptptap;
/*     SET PTPP CLASS 0 */
    iptpp1 = 0;
    iptpp2 = a1com_.indxpt - 2 - amxtab_.maxvst;
    atapwt_(ptptap, &ioflag, &c__4, &aptpp_.irecn, &c__1, &iptpp1, &c__1, &
	    iptpp2, &c__1, &ptpp[amxtab_.maxvst + 1], &iptpp2);
/* ...                                                                 D39 */
/* ..   IOFLAG  .LT.0--O.K.,.GE.0--IO ERROR, OUTPUT ERROR MESSAGE      D39 */
    if (ioflag >= 0) {
	goto L302;
    }
/*     DO WE UPDATE MAXPTP */
L66:
    if (a1com_.indxpt >= amxtab_.maxptp + amxtab_.maxvst) {
	amxtab_.maxptp = a1com_.indxpt - amxtab_.maxvst;
    }
/* ...  ARE WE IN THE PTPP SEGMENTATION MODE */
    if (nogo != 0) {
	goto L15;
    }
/*     RESET INDXPT */
L70:
    a1com_.indxpt = amxtab_.maxvst + 2;
    indxs = a1com_.indxpt;
L80:
    aptpp_.nw = 0;
    return 0;
/* .. */
/* ..   I/O ERROR WHILE WRITING A PTPP RECORD */
/* ..      OUTPUT THE VALUE OF IOFLAG AS THE SUBS. VAL OF V.S. IOFLAG  D39 */
/* ..   I.E.   CARD NO. XXX ISN XXX ERROR NO. XX  IOFLAG ( VAL ) */
L302:
    a1com_.jsuber = 302;
    a1com_.name__ = flag__;
    aptpp_.pt[6] = (doublereal) ioflag;
    a1com_.sum = 9;
    adiagp_();
/* ...  CONTINUE PROCESSING */
    a1com_.jsuber = 0;
    goto L66;
} /* aptput_ */

#undef ptptap
#undef iptpp
#undef ivst
#undef ptpp
#undef kndx
#undef ipt
#undef ndx
#undef flag__


