/* ACPYTP.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "endianmacs.h"
doublereal debug_;
/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, iblank;
} a0con_;

#define a0con_1 a0con_

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

struct {
    integer idebug[3], kcandf;
} adebug_;

#define adebug_1 adebug_

/* Table of constant values */

static integer c__4 = 4;
static integer c__0 = 0;
static integer c__3000 = 3000;
static integer c__3 = 3;
static integer c__2 = 2;

/* Subroutine */ int acpytp_()
{
    /* Initialized data */

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_24 = { {'A', 'C', 'O', 'P', 'Y', 'T', 'A', 'P'}, 0. };

#define a (*(doublereal *)&equiv_24)


    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer m, i1, j1, ke, ii, jk, in, mn, it, klj, npt, kont;
#define ptpp ((doublereal *)&avst_1)
#define kvst ((shortint *)&avst_1)
#define canon ((doublereal *)&avst_1)
    extern /* Subroutine */ int patgo_();
    static integer jtool, jupit;
    extern doublereal afull8_();
    extern /* Subroutine */ int adiagm_();
#define deftab ((doublereal *)&avst_1 + 6200)
#define defans ((doublereal *)&adfsto_1 + 3)
    extern integer amdtoa_();
    extern /* Subroutine */ int agtarg_();
    extern integer aextra_(), astype_();
    static integer irectp, indsav;
    extern /* Subroutine */ int azvalu_(), adprnt_(), aritap_();
    static integer motsav;

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */

/* **** THIS ROUTINE PROCESSES PTPP CLASS  6 DATA AND BUILDS THE PROTP */
/*     TABLE FOR RITAPE TO PLACE AS A RECORD IN THE PROTAP FILE. THE */
/*     INPUT TO THE ROUTINE CONSISTS OF THE PTPP AND ITS INDEX, INDXPT, */
/*     THE SCALR TABLE, THE SURFTB TABLE, AND THE CANON TABLES. */
/* ****              ****                     ****                    **** */
    in = a1com_1.indxpt;
    ke = a0con_1.k2;
/*     SET IDTMOV NON-ZERO TO PRECLUDE MOVING LARGE SURFACES TO DEFTAB */
    a1pas2_1.idtmov = a0con_1.k1;
/*     INITIALIZE PROTP COUNTER */
    jk = a0con_1.k3;
/*     GET NO. PARAMETERS IN PTPP */
    npt = amdtoa_(&ptpp[a1com_1.indxpt - 1], &a0con_1.k4);
//	altered above original line because of endian stuff:
//     npt=((integer *)&avst_1)[(a1com_1.indxpt-1)<<1];

    a1com_1.indxpt += a0con_1.k1;

    i1 = amdtoa_(&ptpp[a1com_1.indxpt - 1], &a0con_1.k4);
    j1 = aextra_(&ptpp[a1com_1.indxpt - 1], &a0con_1.k4);

/*     SET PROTAP CLASS AND SUBCLASS */
    aprotp_1.protp[1] = ptpp[a1com_1.indxpt - 1];
    ++a1com_1.indxpt;

/* ...     COMPUTE BRANCHING NUMBER FROM PROTAP RECORD TYPE */
    irectp = i1 / 1000;
/* ...     BRANCH FOR INDIVIDUAL PROCESSING */
    if (irectp - 11 >= 0) {
	goto L10;
    } else {
	goto L2;
    }
L2:
    switch ((int)irectp) {
	case 1:  goto L160;
	case 2:  goto L302;
	case 3:  goto L10;
	case 4:  goto L304;
	case 5:  goto L305;
	case 6:  goto L306;
	case 7:  goto L10;
	case 8:  goto L10;
	case 9:  goto L10;
	case 10:  goto L200;
    }

/* ...     POST PROCESSOR COMMAND */
L302:
    if (j1 != 1045) {
	goto L10;
    }
/* ...     STORE THE LAST PARTNO FOR USE AS HEADING IN TABCYL ROUTINES */
    kont = a1com_1.indxpt + 1;
    for (klj = 1; klj <= 11; ++klj) {
	adfsto_1.partno[klj - 1] = ptpp[kont - 1];
/* L7: */
	kont += 2;
    }
    goto L10;

/* ...     TEST FOR TRANTO OR MULTIPLE CS BRANCH */
L306:
    if (j1 == 7) {
	goto L170;
    }
    if (j1 == 8) {
	goto L170;
    }

L10:
    if (npt <= 0) {
	goto L130;
    }

    i__1 = npt;
    for (ii = 1; ii <= i__1; ++ii) {
/*     GET EXPECTED SURFACE TYPE IF IT EXISTS */
	it = astype_(&a1com_1.indxpt);
	indsav = a1com_1.indxpt;
/*     GET THE SURFACE OR SCALAR REFERENCED BY THE PTPP ENTRY. */
	m = 83;
	agtarg_(defans, &m, &mn);
/*     IS THE VARIABLE DEFINED */
	if (mn != a0con_1.k3) {
	    goto L20;
	}
/*     THE VARIABLE IS UNDEFINED, JSUBER HAS BEEN SET BY ACANGT. */
	goto L110;

/*  20 IS THE VARIABLE A SURFACE */
L20:
	if (mn == a0con_1.k2) {
	    goto L30;
	}

/*     THE VARIABLE IS NOT A SURFACE. */
/* ...     TEST FOR ENOUGH ROOM FOR ENTRY IN PROTP AREA */
	if (jk > 102) {
	    goto L95;
	}
	aprotp_1.protp[jk - 1] = defans[0];
	jk += a0con_1.k1;
/*      CHECK FOR FROM/X,Y  OR  GOTO/X,Y */
	if (i1 != 5000) {
	    goto L120;
	}
	if (j1 == 3) {
	    goto L25;
	}
	if (j1 != 5) {
	    goto L120;
	}
/* ...     NO VOCABULARY WORDS ALLOWED IN FROM AND GOTO STATEMENTS */
	if (mn != 5) {
	    goto L25;
	}
	a1com_1.jsuber = 133;
	goto L405;
L25:
	if (jk != 7) {
	    goto L120;
	}
	if (npt != 4) {
	    goto L120;
	}
/*      YES - GET Z VALUE */
	defans[0] = aprotp_1.protp[4];
	defans[1] = aprotp_1.protp[5];
	azvalu_();
	aprotp_1.protp[6] = defans[2];
	++jk;
	goto L120;

/* ...     VARIABLE IS A SURFACE - SET INDXPT TO PROPER LOCATION IN PTPP */
L30:
	if (aextra_(&ptpp[indsav - 1], &c__4) < 2) {
	    goto L32;
	}
	++a1com_1.indxpt;

/* ...     EXTRACT TYPE FROM CANONICAL FORM */
L32:
	a1pas2_1.k = amdtoa_(adfsto_1.defsto, &c__4);
/* ...     SEE IF IT IS A PATTERN */
	if (a1pas2_1.k != 18) {
	    goto L34;
	}

/* ...     PATTERN FOUND - MAKE SURE STATEMENT IS A GOTO/... */
/* ...     CHECK PROTP CLASS... */
	if (irectp != 5) {
	    goto L100;
	}
/* ...     ...AND SUBCLASS CODES */
	if (j1 != 5) {
	    goto L100;
	}
/* ...     PATTERN IS VALID - CALL ROUTINE TO OUTPUT IT, THEN EXIT */
	patgo_();
	return 0;

/* ...     SURFACE IS NOT PATTERN - GET LENGTH OF CANONICAL FORM */
L34:
	a1pas2_1.l = aextra_(adfsto_1.defsto, &c__4);
/* ...     TEST FOR ENOUGH ROOM FOR ENTRY IN PROTP AREA */
	if (jk + a1pas2_1.l - 1 > 102) {
	    goto L95;
	}
/* ...     CAN EXPECTED SURFACE TYPE BE DETERMINED */
	if (it == 100) {
	    goto L40;
	}
	if (it == 150) {
	    goto L35;
	}
/*     YES - IS THIS SURFACE THE EXPECTED TYPE */
	if (a1pas2_1.k != it) {
	    goto L100;
	}
	goto L45;

/*      SURFACE CANNOT BE POINT, VECTOR, MATRIX, OR LARGE SURFACE */
L35:
	if (a1pas2_1.k >= 50) {
	    goto L100;
	}
/*     SURFACE CANNOT BE POINT, VECTOR, OR MATRIX */
L40:
	if (a1pas2_1.k == a0con_1.k1) {
	    goto L100;
	}
	if (a1pas2_1.k == a0con_1.k11) {
	    goto L100;
	}
	if (a1pas2_1.k == a0con_1.k12) {
	    goto L100;
	}

/*     SURFACE IS THE EXPECTED TYPE - CHECK FOR 3000 TYPE PROTAP RECORD */
L45:
	if (i1 != 3000) {
	    goto L50;
	}
/*     3000 TYPE - STORE SURFACE TYPE AND LENGTH OF CANONICAL FORM */
	aprotp_1.protp[jk - 1] = afull8_(&a0con_1.k0, &a1pas2_1.k);
	jk += a0con_1.k1;
	i__2 = a1pas2_1.l - 1;
	aprotp_1.protp[jk - 1] = afull8_(&a0con_1.k0, &i__2);
	jk += a0con_1.k1;
	goto L60;

/*     IS THIS A 5000 TYPE PROTAP RECORD */
L50:
	if (i1 != 5000) {
	    goto L60;
	}

/*     YES - IS THIS FROM, GODLTA, OR GOTO */
	if (j1 < a0con_1.k3) {
	    goto L60;
	}
	if (j1 > a0con_1.k5) {
	    goto L60;
	}
/*     YES - CHECK FOR SYMBOLIC TOOL AXIS VECTOR */
	if (jk == a0con_1.k8) {
	    goto L70;
	}

/*      IS THIS AN 11000 TYPE PROTAPE RECORD  (POCKET) */
L60:
	if (i1 == 11000) {
	    goto L70;
	}
/*     NO - STORE NAME AND SUBSCRIPT(ZEROS IF NESTED) */
	aprotp_1.protp[jk - 1] = a2cls7_1.ename;
	jk += a0con_1.k1;
	aprotp_1.protp[jk - 1] = (doublereal) a1com_1.namsub;
	jk += a0con_1.k1;
/*     IS THIS A LARGE SURFACE */
	if (a1pas2_1.l != a0con_1.k5) {
	    goto L70;
	}
/*     YES - STORE SRFTAP RECORD NO. AND LENGTH OF CANONICAL FORM */
	aprotp_1.protp[jk - 1] = adfsto_1.defsto[3];
	jk += a0con_1.k1;
	aprotp_1.protp[jk - 1] = adfsto_1.defsto[4];
	jk += a0con_1.k1;
	goto L120;

/*     MOVE CANONICAL FORM TO PROTP */
L70:
	i__2 = a1pas2_1.l;
	for (a1pas2_1.i__ = 4; a1pas2_1.i__ <= i__2; ++a1pas2_1.i__) {
	    aprotp_1.protp[jk - 1] = adfsto_1.defsto[a1pas2_1.i__ - 1];
/* L80: */
	    ++jk;
	}
	goto L120;

/* ...     PROTP AREA OVERFLOW - ERROR */
L95:
	a1com_1.jsuber = 378;
	goto L110;

/*     SURFACE IS NOT EXPECTED TYPE */
L100:
	a1com_1.jsuber = 1006;

/*     OUTPUT DIAGNOSTIC MESSAGE FOR THIS PARAMETER */
L110:
	if (a1com_1.jsuber == 0) {
	    goto L115;
	}
	adiagm_();
L115:
	ke = a0con_1.k1;
L120:
	;
    }

/*     SET NO. OF WORDS IN PROTP */
L130:
    jk -= a0con_1.k1;
    i__1 = jk - a0con_1.k1;
    aprotp_1.protp[0] = afull8_(&a0con_1.k0, &i__1);

    if (a1com_1.kdbug == 0) {
	goto L140;
    }
/*     DEBUG FLAG IS ON - PRINT PTPP AND PROTP */
    adebug_1.idebug[0] = a0con_1.k7;
    adebug_1.idebug[1] = in;
    adebug_1.idebug[2] = a1pas2_1.klasct;
    adprnt_(&a);
    adebug_1.idebug[0] = 13;
    adebug_1.idebug[1] = jk;
    adprnt_(&a0con_1.k0);
/* ...     IS THIS A SURFACE RECORD (3000 TYPE) */
L140:
    if (irectp != 3) {
	goto L145;
    }
/* ...     YES - IS IMPLIED CHECK SURFACE NEEDED */
    if (aprotp_1.jgorit == 1) {
	goto L340;
    }
/* ...     HAVE THERE BEEN ERRORS */
L145:
    switch ((int)ke) {
	case 1:  goto L160;
	case 2:  goto L150;
    }
/* ...     NO - OUTPUT PROTAP RECORD */
L150:
    aritap_();
L160:
    return 0;

/*     TRANTO/ID */
L170:
    if (amdtoa_(&ptpp[a1com_1.indxpt - 1], &a0con_1.k4) != a0con_1.k7) {
	goto L190;
    }
    a1com_1.indxpt += a0con_1.k1;
    a1pas2_1.l = (aextra_(&ptpp[a1com_1.indxpt - 1], &c__4) << 2) - 3;
    aprotp_1.protp[2] = (float)0.;
    ++a1com_1.indxpt;
    aprotp_1.protp[3] = ptpp[a1com_1.indxpt - 1];
/* ...  GET PROTAPE RECORD NUMBER, IF ALREADY PROCESSED */
    a1pas2_1.j = kvst[a1pas2_1.l + 3];
    if (a1pas2_1.j == 0) {
	goto L180;
    }
/*     SET PROTAP REC. NO. FOR BACKWARD TRANSFER */
    aprotp_1.protp[2] = afull8_(&a0con_1.k0, &a1pas2_1.j);
L180:
    jk += a0con_1.k2;
    goto L130;

L190:
    a1com_1.jsuber = 453;
    ke = a0con_1.k1;
    goto L130;

/*     STATEMENT DOES NOT GENERATE PROTAP RECORD */
L200:
    a1com_1.jsuber = 456;
    ke = a0con_1.k1;
    goto L130;

/* ...     TOOL POSITION (4000 TYPE) - IF LEFT, RIGHT, OR ON, SAVE IT */
L304:
    if (j1 >= 4) {
	goto L130;
    }
    jtool = j1;
    goto L130;

/* ...     5000 TYPE RECORD - IF FROM, GOTO, OR GODLTA, AND */
/* ...     IMPLIED CHECK SURFACE NEEDED, ERROR */
L305:
    if (j1 <= 2) {
	goto L10;
    }
    if (j1 == 8) {
	goto L10;
    }
    if (aprotp_1.jgorit != 0) {
	goto L400;
    } else {
	goto L10;
    }
L400:
    a1com_1.jsuber = 137;
    aprotp_1.jgorit = 0;
L405:
    adiagm_();
    goto L160;

/* ...     IMPLIED CS NEEDED - IF THIS MOTION IS START-UP, ERROR */
L340:
    if (amdtoa_(&aprotp_1.savmot, &c__4) != 8000) {
	goto L400;
    }
    motsav = aextra_(&aprotp_1.savmot, &c__4);
/* ...     IF THIS MOTION IS GOUP OR GODOWN, ERROR */
    if (motsav < 5) {
	goto L350;
    }
    a1com_1.jsuber = 136;
    goto L405;

/* ...     CONSTRUCT AND OUTPUT CHECK SURFACE RECORD FOR IMPLIED CS */
/* ...     IS THIS MOTION GOLFT OR GORGT */
L350:
    if (motsav <= 2) {
	goto L352;
    }
/* ...     NO - SET INDICATOR FOR DS AND CS TANGENT */
    jupit = 4;
    goto L360;
/* ...     YES - WAS LAST TOOL POSITION ON */
L352:
    if (jtool != 3) {
	goto L354;
    }
/* ...     YES - SET INDICATOR FOR ON CS */
    jupit = 3;
    goto L360;
/* ...     TOOL NOT ON - SET INDICATOR INITIALLY FOR TO CS - MAY */
/* ...     BE ALTERED LATER */
L354:
    jupit = 1;
/* ...     WAS LAST TOOL POSITION LEFT */
    if (jtool == 1) {
	goto L356;
    }
/* ...     NO - MUST BE RIGHT - IF THIS MOTION GOLFT, SET */
/* ...     INDICATOR FOR PAST CS */
    if (motsav == 1) {
	jupit = 2;
    }
    goto L360;
/* ...     LAST TOOL POSITION WAS LEFT - IF THIS MOTION GORGT, */
/* ...     SET INDICATOR FOR PAST CS */
L356:
    if (motsav == 2) {
	jupit = 2;
    }

/* ...     PUT SURFACE CONDITION INDICATOR INTO CS RECORD */
L360:
    aprotp_1.protp[2] = afull8_(&c__0, &jupit);
    aprotp_1.protp[1] = afull8_(&c__3000, &c__3);
    aprotp_1.jgorit = -1;
/* ...     HAVE THERE BEEN ANY ERRORS */
    switch ((int)ke) {
	case 1:  goto L370;
	case 2:  goto L365;
    }
L365:
    aritap_();
/* ...     CLEAR IMPLIED CHECK SURFACE FLAG */
L370:
    aprotp_1.jgorit = 0;
/* ...     SET SURFACE USE CODE BACK TO DRIVE SURFACE */
    aprotp_1.protp[1] = afull8_(&c__3000, &c__2);
    aprotp_1.protp[2] = (float)0.;
    goto L145;

} /* acpytp_ */

#undef defans
#undef deftab
#undef canon
#undef kvst
#undef ptpp
#undef a


