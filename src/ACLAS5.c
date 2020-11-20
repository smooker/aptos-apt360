/* ACLAS5.f -- translated by f2c (version 20000121).
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
    integer maxtab, maxvs1, maxvs2, maxptp, maxscl, maxvs, maxvst, mxptpp, 
	    mxcan, mxsrcn, maxslr, maxelm, maxpot;
} amxtab_;

#define amxtab_1 amxtab_

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
    doublereal ppseq1, ppseq2, ename, einame;
    integer ierec, isn;
} a2cls7_;

#define a2cls7_1 a2cls7_

static struct {
    integer i__, j, k, l, movlge, kanmax, icanst, iovrec, kanptr, mdftab, 
	    kancnt, kaux, kdfcnt, idefp, kprcnt, mdfpre, iprep, kovflp, 
	    ksrfct, kovcnt, lscan, iovflo, maxcan, iref, icansc, namsta, 
	    kango, lasptp, isub, lcomp, lgerec, irecn, jrec, jnum, kancur, 
	    kancot, kdfent, kanpar, lgeloc, idtmov, ispprg, indexs, kptp, 
	    kptpct, klastp, klasct, kprnt;
} a1pas2_;

#define a1pas2_1 a1pas2_

static struct {
    doublereal defsto[85], partno[11];
} adfsto_;

#define adfsto_1 adfsto_

static struct {
    doublereal protp[102], prosav[102];
    integer nowclt, lstpsv, incore, jgorit;
    doublereal savmot;
} aprotp_;

#define aprotp_1 aprotp_

static struct {
    doublereal stable[23];
} a1stab_;

#define a1stab_1 a1stab_

/* Table of constant values */

static integer c__1 = 1;
static integer c__1000 = 1000;

/* Subroutine */ int aclas5_()
{
    /* Format strings */
    static char fmt_120[] = "(\0021\002,60x)";
    static char fmt_131[] = "(7z17)";
    static char fmt_192[] = "(24x7f13.6)";
    static char fmt_198[] = "(\002 \002a8,\002(\002i4,\002)\0022x,a6,i3,7f13\
.6/(24x7f13.6))";
    static char fmt_194[] = "(\002 \002a8,\002(\002i4,\002)  SYMBOL DEFINED \
INCORRECTLY OR REFERENCED PRIOR TO DEFINITION  \002)";
    static char fmt_188[] = "(\002 \002a8,\002(\002i4,\002)  STATEMENT I.D.\
 \002)";
    static char fmt_234[] = "(9a8,a6,i2)";
    static char fmt_250[] = "(a8,64x,a8)";
    static char fmt_315[] = "(\002+\00266x10a6)";
    static char fmt_335[] = "(\002 \00211a6)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(), e_wsfe(), do_fio();

    /* Local variables */
#define karg ((shortint *)&ascalr_1 + 726)
    static integer kall;
    static doublereal adum;
    static integer kret;
    static doublereal type__;
#define ptpp ((doublereal *)&avst_1)
#define ivst ((integer *)&avst_1)
    static doublereal save1, save2, save3;
    static integer idflg;
    static doublereal blank, right;
    static integer itype, j1;
#define iptpp ((integer *)&avst_1)
    static integer ktype, j2;
    static doublereal stype;
    extern /* Subroutine */ int avs2ck_();
    static integer jtemp1, ic, ie, ii;
    extern /* Subroutine */ int adiagm_();
    static integer jj;
#define deftab ((doublereal *)&avst_1 + 6200)
    static integer il;
#define idftab ((integer *)&avst_1 + 12400)
    static integer mm, nn, is;
    static doublereal endpch;
#define kargpn ((shortint *)&ascalr_1 + 727)
#define idfsto ((integer *)&adfsto_1)
#define knclus ((shortint *)&ascalr_1 + 726)
    static integer kindxp;
    extern /* Subroutine */ int agtarg_();
    static doublereal scalar;
    static integer ivstct, isubct, indxst, il1;
    static doublereal endseq;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 0, 0, fmt_120, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_131, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_131, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_192, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_198, 0 };
    static cilist io___28 = { 0, 0, 0, fmt_194, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_188, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_234, 0 };
    static cilist io___46 = { 0, 0, 0, fmt_250, 0 };
    static cilist io___51 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___52 = { 0, 0, 0, fmt_335, 0 };


/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */


/* ...  PASS TWO PROGRAM FOR PUNCH, PRINT, TITLES */



/* 	f2c didn't like these */
/*       DATA RIGHT,SCALAR/8H RIGHT  ,8HSCALAR  / */
/*      DATA BLANK/8H        / */
/*      DATA ENDPCH,ENDSEQ/'(ENDPCH)',ZFFFFFFFFFFFFFFFF/ */

	static char rightC[]="RIGHT   ";
	static char scalarC[]="SCALAR  ";
	static char blankC[]="        ";
	static char endpchC[]="(ENDPCH)";
	static long long int endseqL=0xffffffffffffffff;

	right=*((doublereal*)&rightC);
	scalar=*((doublereal*)&scalarC);
	blank=*((doublereal*)&blankC);
	endpch=*((doublereal*)&endpchC);
	endseq=*(doublereal*)&endseqL;


    a1pas2_1.idefp = 4;
    a1com_1.jsv = 0;
    kindxp = (a1com_1.indxpt << 1) - 1;
    mm = iptpp[OTHER_ENDIAN_S(kindxp - 1)] - 1;
    nn = iptpp[OTHER_ENDIAN_S(kindxp)];
    ++a1com_1.indxpt;
    switch ((int)nn) {
	case 1:  goto L100;
	case 2:  goto L101;
	case 3:  goto L300;
    }
/*     PRINT/ - SET IDTMOV TO PRECLUDE FETCHING LARGE SURFACE */
L100:
    a1pas2_1.idtmov = 1;
    goto L102;
/*     PUNCH/ - SET IDTMOV TO FETCH LARGE SURFACE */
L101:
    a1pas2_1.idtmov = 0;
/*     GET PRINTED OUTPUT FORMAT TYPE */
L102:
    agtarg_(&type__, &c__1, &kret);
    if (kret != 1) {
	goto L140;
    }
    itype = (integer) type__;
    switch ((int)itype) {
	case 1:  goto L170;
	case 2:  goto L150;
	case 3:  goto L160;
	case 4:  goto L155;
    }
/*     PRINT/0 */
/* L110: */
    io___16.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___16);
    e_wsfe();
    goto L900;
/*     PRINT/1 */
L130:
    if (il == 5) {
	goto L132;
    }
    --il;
    io___18.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___18);
    i__1 = il;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&adfsto_1.defsto[a1pas2_1.i__ - 1], (ftnlen)
		sizeof(doublereal));
    }
    e_wsfe();
    goto L199;
L132:
    io___19.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&deftab[4], (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L199;
/*     FORMAT ERROR IN PRINT/ OR PUNCH/ */
L140:
    a1com_1.jsuber = 2000;
    goto L900;
/*     PRINT/2 */
L150:
    idflg = 0;
    goto L170;
/*     PRINT/4 - SET IDTMOV TO FETCH LARGE SURFACE */
L155:
    a1pas2_1.idtmov = 0;
/*     PRINT/3 */
L160:
    idflg = 1;
/*     CHECK FOR ALL MODIFIER */
L170:
    kindxp = (a1com_1.indxpt << 1) - 1;
    if (iptpp[OTHER_ENDIAN_S(kindxp - 1)] != 6) {
	goto L171;
    }
    ++a1com_1.indxpt;
    if (iptpp[OTHER_ENDIAN_S(kindxp + 2)] != 51) {
	goto L140;
    }
    a1com_1.indxpt += -2;
    goto L180;

L171:
    kall = 0;
L1171:
    kindxp = (a1com_1.indxpt << 1) - 1;
    a1pas2_1.i__ = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    if (a1pas2_1.i__ != 2) {
	goto L172;
    }
    a1pas2_1.i__ = (iptpp[OTHER_ENDIAN_S(kindxp + 2)] << 1) - 1;
    if (ivst[OTHER_ENDIAN_S(a1pas2_1.i__ + 1)] != 8) {
	goto L172;
    }
    a1com_1.indxpt += 2;
    goto L195;

L172:
    if (nn == 2) {
	goto L200;
    }
    *knclus = 1;
L173:
    ascalr_1.nsurf = 1;
    agtarg_(&deftab[4], &c__1000, &kret);
    if (kret == 8) {
	goto L193;
    }
    if (kret > 3) {
	goto L199;
    }
    il = idfsto[OTHER_ENDIAN_S(1)] + 1;
    if (kret == 1) {
	il = 5;
    }
    ic = il - 4;
    if (itype == 1) {
	goto L130;
    }
    if (idflg != 0) {
	goto L196;
    }
/* L191: */
    io___23.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___23);
    i__1 = il;
    for (a1pas2_1.i__ = 5; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&deftab[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L199;
L196:
    if (kret == 2) {
	goto L1196;
    }
    stype = scalar;
    goto L197;
L1196:
    if (il == 6) {
	goto L199;
    }
    ktype = idfsto[OTHER_ENDIAN_S(0)];
    stype = a1stab_1.stable[ktype - 1];
L197:
    io___27.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___27);
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&stype, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
    i__1 = il;
    for (a1pas2_1.i__ = 5; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	do_fio(&c__1, (char *)&deftab[a1pas2_1.i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
L199:
    if (itype == 4) {
	goto L230;
    }
L1991:
    if (kall != 0) {
	goto L185;
    }
    if (*knclus == 2) {
	goto L173;
    }
    --mm;
    if (mm == 0) {
	goto L189;
    }
    goto L1171;
L193:
    io___28.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___28);
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
    e_wsfe();
L195:
    a1com_1.jsuber = 0;
    goto L1991;

L180:
    kall = 1;
    save1 = ptpp[a1com_1.indxpt - 1];
    save2 = ptpp[a1com_1.indxpt];
    save3 = ptpp[a1com_1.indxpt + 1];
    ivstct = 2;
    isubct = 0;
    indxst = a1com_1.indxpt;

L181:
    ivstct += 2;
    if (ivstct > amxtab_1.maxvs1) {
	goto L187;
    }
    if (avst_1.vst[ivstct - 1] >= 0.) {
	goto L183;
    }
    jtemp1 = (ivstct << 1) - 1;
    isubct = (i__1 = ivst[OTHER_ENDIAN_S(jtemp1)], abs(i__1));
    a1pas2_1.isub = 1;
L182:
    a1com_1.name__ = ivstct - 1;
    a1com_1.namsub = a1pas2_1.isub;
    a2cls7_1.ename = avst_1.vst[a1com_1.name__ - 1];
    avs2ck_(&a1pas2_1.j);
    if (a1pas2_1.j == 7) {
	goto L195;
    }
    if (a1pas2_1.j > 6) {
	goto L193;
    }
/*     IS THIS A STATEMENT ID */
    if (a1pas2_1.j == 3) {
	goto L181;
    }
    if (a1pas2_1.j != 2) {
	a1pas2_1.j = 4;
    }
    kindxp = (a1com_1.indxpt << 1) - 1;
    iptpp[OTHER_ENDIAN_S(kindxp - 1)] = a1pas2_1.j;
    iptpp[OTHER_ENDIAN_S(kindxp)] = 1;
    iptpp[OTHER_ENDIAN_S(kindxp + 1)] = 0;
    iptpp[OTHER_ENDIAN_S(kindxp + 2)] = ivstct - 1;
    adum = (doublereal) a1pas2_1.isub;
    ptpp[a1com_1.indxpt + 1] = adum;
    goto L172;

L183:
    a1com_1.name__ = ivstct - 1;
    a1com_1.namsub = 0;
    a2cls7_1.ename = avst_1.vst[a1com_1.name__ - 1];
    avs2ck_(&a1pas2_1.j);
    if (a1pas2_1.j == 7) {
	goto L195;
    }
    if (a1pas2_1.j > 6) {
	goto L193;
    }
/*     IS THIS A STATEMENT ID */
    if (a1pas2_1.j == 3) {
	goto L186;
    }
    if (a1pas2_1.j != 2) {
	a1pas2_1.j = 4;
    }
    kindxp = (a1com_1.indxpt << 1) - 1;
    iptpp[OTHER_ENDIAN_S(kindxp - 1)] = a1pas2_1.j;
    iptpp[OTHER_ENDIAN_S(kindxp)] = 0;
    iptpp[OTHER_ENDIAN_S(kindxp + 1)] = 0;
    iptpp[OTHER_ENDIAN_S(kindxp + 2)] = ivstct - 1;
    goto L172;

L185:
    a1com_1.indxpt = indxst;
    if (isubct == 0) {
	goto L181;
    }
    ++a1pas2_1.isub;
    if (a1pas2_1.isub > isubct) {
	goto L181;
    }
    goto L182;

L186:
    io___37.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___37);
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&a1com_1.namsub, (ftnlen)sizeof(integer));
    e_wsfe();

L187:
    ptpp[indxst - 1] = save1;
    ptpp[indxst] = save2;
    ptpp[indxst + 1] = save3;
/*     CHECK FOR PUNCH/N,ALL OR PRINT/4 */
L189:
    if (nn == 2 || itype == 4) {
	goto L245;
    }
    goto L900;

/*     PUNCH/1 */
L200:
    ii = 1;
L205:
    kindxp = (a1com_1.indxpt << 1) - 1;
    j1 = iptpp[OTHER_ENDIAN_S(kindxp - 1)];
    if (j1 == 4) {
	goto L210;
    }
    if (j1 == 2) {
	goto L210;
    }
/*     UNNAMED PARAMETER */
    a1com_1.jsuber = 2005;
    a2cls7_1.ename = 0.;
    goto L220;

L210:
    *knclus = 1;
L212:
    agtarg_(&deftab[4], &c__1000, &kret);
    if (kret < 3) {
	goto L230;
    }
/*     OUTPUT ERROR DIAGNOSTIC FOR THIS PARAMETER */
    a1com_1.jsuber = 101;
L220:
    a1com_1.jsv = 1;
    adiagm_();
    goto L240;

L230:
    deftab[0] = a2cls7_1.ename;
    adum = (doublereal) a1com_1.namsub;
    deftab[1] = adum;
/*     CHECK FOR SCALAR BEING OUTPUT */
    if (kret != 1) {
	goto L2301;
    }
/*     YES - SHOULD IT BE OUTPUT */
    if (itype == 3) {
	goto L240;
    }
/*     YES - SET LENGTH */
    idfsto[OTHER_ENDIAN_S(0)] = 0;
    idfsto[OTHER_ENDIAN_S(1)] = 4;
    goto L2302;
/* ...     SHOULD WE OUTPUT SURFACES */
L2301:
    if (itype == 2) {
	goto L240;
    }
L2302:
    deftab[2] = adfsto_1.defsto[0];
    deftab[3] = 0.;
    il = idfsto[OTHER_ENDIAN_S(1)] + 1;
/*     CHECK FOR LARGE SURFACE */
    if (il != 6) {
	goto L231;
    }
/*     LARGE SURFACE - SET LENGTH */
    deftab[3] = adfsto_1.defsto[4];
    il = idftab[OTHER_ENDIAN_S(7)] + 4;
L231:
    is = 1;
    ic = 0;
L232:
    ie = is + 8;
    if (ie > il) {
	goto L236;
    }
L233:
    io___42.ciunit = ataptb_1.puntap;
    s_wsfe(&io___42);
    i__1 = ie;
    for (a1pas2_1.j = is; a1pas2_1.j <= i__1; ++a1pas2_1.j) {
	do_fio(&c__1, (char *)&deftab[a1pas2_1.j - 1], (ftnlen)sizeof(
		doublereal));
    }
    do_fio(&c__1, (char *)&a2cls7_1.ename, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
    if (ie >= il) {
	goto L240;
    }
    ++ic;
    is += 9;
    goto L232;
L236:
    il1 = il + 1;
    i__1 = ie;
    for (jj = il1; jj <= i__1; ++jj) {
/* L238: */
	deftab[jj - 1] = blank;
    }
    goto L233;
L240:
    if (itype == 4) {
	goto L1991;
    }
    if (*knclus == 2) {
	goto L212;
    }
    ++ii;
    if (ii <= mm) {
	goto L205;
    }
/*     CHECK FOR ALL MODIFIER */
    if (kall == 1) {
	goto L185;
    }
/*     OUTPUT END OF PUNCH DATA CARD */
L245:
    io___46.ciunit = ataptb_1.puntap;
    s_wsfe(&io___46);
    do_fio(&c__1, (char *)&endpch, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&endseq, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L900;
/*     TITLES */
L300:
    j1 = a1com_1.indxpt + 1;
    if (ptpp[j1 - 1] != right) {
	goto L320;
    }
    j1 += 2;
    j2 = 10;
L305:
    i__1 = j2;
    for (a1pas2_1.i__ = 1; a1pas2_1.i__ <= i__1; ++a1pas2_1.i__) {
	aprotp_1.protp[a1pas2_1.i__ - 1] = ptpp[j1 - 1];
/* L310: */
	j1 += 2;
    }
    if (j2 != 10) {
	goto L330;
    }
    io___51.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___51);
    i__1 = j2;
    for (j1 = 1; j1 <= i__1; ++j1) {
	do_fio(&c__1, (char *)&aprotp_1.protp[j1 - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    goto L900;
L320:
    j2 = 11;
    goto L305;
L330:
    io___52.ciunit = ataptb_1.ioutap;
    s_wsfe(&io___52);
    i__1 = j2;
    for (j1 = 1; j1 <= i__1; ++j1) {
	do_fio(&c__1, (char *)&aprotp_1.protp[j1 - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
L900:
    return 0;
} /* aclas5_ */

#undef knclus
#undef idfsto
#undef kargpn
#undef idftab
#undef deftab
#undef iptpp
#undef ivst
#undef ptpp
#undef karg


