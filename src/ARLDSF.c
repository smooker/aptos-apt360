/* ARLDSF.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"

/* Common Block Declarations */

static struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

static struct {
    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,
	     tapes3, tapes4;
    integer intape, ioutap, puntap;
} ataptb_;

#define ataptb_1 ataptb_

static struct {
    doublereal vst[7200];
} avst_;

#define avst_1 avst_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int arldsf_()
{
    /* Initialized data */

    static integer kount[20] = { 4,5,5,8,8,11,11,8,11,11,4,0,5,11,0,0,0,0,0,0 
	    };

    /* Format strings */
    static char fmt_131[] = "";
    static char fmt_211[] = "";
    static char fmt_998[] = "(\002 ** RLDSRF **\002/(7x,5z18))";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), do_fio(), e_wsfe();

    /* Local variables */
    static doublereal a;
    static integer i__;
#define n ((integer *)&avst_1 + OTHER_ENDIAN_S(12401))
    static integer na, nb, nd, in, nn, ind, nna, nnb;
    static doublereal tmp[3];
    extern /* Subroutine */ int adot_();
    static doublereal atmp[3];
    static integer ncnt, iret;
    extern /* Subroutine */ int anorm_();
    static integer nstrt;
#define deftab ((doublereal *)&avst_1 + 6200)
#define idftab ((integer *)&avst_1 + 12400)
    extern /* Subroutine */ int across_();

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 0, 0, fmt_998, 0 };


    /* Assigned format variables */
    static char *iret_fmt;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 *** */

/* ...  RULED SURFACE PREPROCESSOR */



/* ...  MOVE DATA UP 30 LOCATIONS */

    in = *n - 1;
    i__1 = in;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nn = *n - i__ + 1;
/* L1: */
	deftab[nn + 29] = deftab[nn - 1];
    }
    *n += 30;
    for (i__ = 2; i__ <= 31; ++i__) {
/* L101: */
	deftab[i__ - 1] = (float)0.;
    }

/* ...  SCAN INPUT */

/* L2: */
    nstrt = 64;
    ncnt = 6;
L7:
    idftab[OTHER_ENDIAN_S(ncnt - 1)] = nstrt / 2;
    if ((i__1 = idftab[OTHER_ENDIAN_S(nstrt - 1)] - 3050) < 0) {
	goto L3;
    } else if (i__1 == 0) {
	goto L4;
    } else {
	goto L999;
    }

L3:
    if (idftab[OTHER_ENDIAN_S(nstrt - 2)] != 0) {
	goto L999;
    }
    if (idftab[OTHER_ENDIAN_S(nstrt - 1)] < 3001) {
	goto L999;
    }
    if (idftab[OTHER_ENDIAN_S(nstrt - 1)] > 3020) {
	goto L999;
    }
    nn = idftab[OTHER_ENDIAN_S(nstrt - 1)] - 3000;
    if (kount[nn - 1] <= 0) {
	goto L999;
    } else {
	goto L5;
    }
L5:
    nstrt += kount[nn - 1] << 1;
    goto L6;

L4:
    nstrt += idftab[OTHER_ENDIAN_S(nstrt - 2)] + 1 << 1;

L6:
    ncnt += 2;
    if ((i__1 = *n + 1 - nstrt / 2) < 0) {
	goto L999;
    } else if (i__1 == 0) {
	goto L8;
    } else {
	goto L7;
    }
L8:
    idftab[OTHER_ENDIAN_S(3)] = ncnt / 2 - 3;

/* ...  CHECK FOR PROPER FORMAT */


/* ...  RLDSRF/SURF,PNT,PNT,VCTR/PNT... */

    nn = idftab[OTHER_ENDIAN_S(5)] << 1;
    if (idftab[OTHER_ENDIAN_S(nn - 1)] - 3001 <= 0) {
	goto L999;
    } else {
	goto L9;
    }
L9:
    if (idftab[OTHER_ENDIAN_S(nn - 1)] - 3050 <= 0) {
	goto L10;
    } else {
	goto L999;
    }
L10:
    ind = 8;
    iret = 0;
    iret_fmt = fmt_131;
    goto L25;

L131:
    nn = idftab[OTHER_ENDIAN_S(13)] << 1;
    if ((i__1 = idftab[OTHER_ENDIAN_S(nn - 1)] - 3001) < 0) {
	goto L999;
    } else if (i__1 == 0) {
	goto L14;
    } else {
	goto L15;
    }
L15:
    if (idftab[OTHER_ENDIAN_S(nn - 1)] - 3050 <= 0) {
	goto L16;
    } else {
	goto L999;
    }

/* ...  IS FORMAT ... PNT */

L14:
    if (idftab[OTHER_ENDIAN_S(3)] - 5 != 0) {
	goto L999;
    } else {
	goto L211;
    }

/* ...  IS FORMAT ... SRF,PNT,PNT,VCTR/PNT */

L16:
    if (idftab[OTHER_ENDIAN_S(3)] - 8 != 0) {
	goto L999;
    } else {
	goto L18;
    }
L18:
    ind = 16;
    iret = 1;
    iret_fmt = fmt_211;
    goto L25;

/* ...     IF DEBUG FLAG ON, PRINT DEFTAB AREA */
L211:
    if (a1com_1.kdbug == 0) {
	goto L23;
    }
    io___12.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___12);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&deftab[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L23:
    return 0;
L999:
    a1com_1.jsuber = 1002;
    goto L211;

L25:
    nn = idftab[OTHER_ENDIAN_S(ind - 1)] << 1;
    if (idftab[OTHER_ENDIAN_S(nn - 1)] != 3001) {
	goto L999;
    }
    nn = idftab[OTHER_ENDIAN_S(ind + 1)] << 1;
    if (idftab[OTHER_ENDIAN_S(nn - 1)] != 3001) {
	goto L999;
    }
    nn = idftab[OTHER_ENDIAN_S(ind + 3)] << 1;
    if (idftab[OTHER_ENDIAN_S(nn - 1)] - 3011 != 0) {
	goto L28;
    } else {
	goto L29;
    }
L28:
    if (idftab[OTHER_ENDIAN_S(nn - 1)] != 3001) {
	goto L999;
    }

L29:
    nna = idftab[OTHER_ENDIAN_S(ind - 1)];
    nnb = idftab[OTHER_ENDIAN_S(ind + 1)];

/* ...  IS(P-Q)**2 .GT. 1.E-4 */

/* L30: */
    for (i__ = 1; i__ <= 3; ++i__) {
	na = nna + i__;
	nb = nnb + i__;
/* L31: */
	tmp[i__ - 1] = deftab[nb - 1] - deftab[na - 1];
    }
    adot_(tmp, tmp, &a);
    if (a - (float)1e-4 <= 0.) {
	goto L997;
    } else {
	goto L32;
    }
L997:
    a1com_1.jsuber = 701;
    goto L211;

/* ...  NORM  V */

L32:
    nd = nn / 2;
    if (idftab[OTHER_ENDIAN_S(nn - 1)] - 3001 != 0) {
	goto L42;
    } else {
	goto L43;
    }

/* ...  GENERATE  V */

L43:
    for (i__ = 1; i__ <= 3; ++i__) {
	na = nna + i__;
	nb = nd + i__;
/* L44: */
	atmp[i__ - 1] = deftab[nb - 1] - deftab[na - 1];
    }
    across_(tmp, atmp, atmp);
    across_(atmp, tmp, &deftab[nd]);
L42:
    anorm_(&deftab[nd], &deftab[nd]);

/* ...  IS NORM(P-Q) X V  .GT.  1.E-2 */

    anorm_(tmp, tmp);
    across_(tmp, &deftab[nd], atmp);
    adot_(atmp, atmp, &a);
    if (a - (float).01 <= 0.) {
	goto L996;
    } else {
	goto L33;
    }
L996:
    a1com_1.jsuber = 702;
    goto L211;
L33:
    switch ((int)iret) {
	case 0: goto L131;
	case 1: goto L211;
    }
} /* arldsf_ */

#undef idftab
#undef deftab
#undef n


