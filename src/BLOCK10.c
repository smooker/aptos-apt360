/* BLOCK10.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */
/*
static struct {
    doublereal erc1[30], erc2[30], erc3[30], erc4[30], erc5[30], erc6[30], 
	    erc7[30], erc8[30], erc9[30], erc10[30], erc11[30], erc12[30], 
	    erc13[30], erc14[30], erc15[30], erc16[30], erc17[30], erc18[30], 
	    erc19[30], erc20[30], erc21[30], erc22[30], erc23[30], erc24[30], 
	    erc25[30], erc26[30], erc27[30], erc28[30], erc29[30], erc30[30], 
	    erc31[30], erc32[30], erc33[30], erc34[30], erc35[30], erc36[30], 
	    erc37[30], erc38[30], erc39[30], erc40[30], erc41[30], erc42[30], 
	    erc43[30], erc44[30], erc45[30], erc46[30], erc47[30], erc48[30], 
	    erc48[30], erc50[30], erc51[30], erc52[30], erc53[30], erc54[30];
} errcon_;
*/
static struct {
    char erc1[30*8], erc2[30*8], erc3[30*8], erc4[30*8], erc5[30*8], erc6[30*8], 
	    erc7[30*8], erc8[30*8], erc9[30*8], erc10[30*8], erc11[30*8], erc12[30*8], 
	    erc13[30*8], erc14[30*8], erc15[30*8], erc16[30*8], erc17[30*8], erc18[30*8], 
	    erc19[30*8], erc20[30*8], erc21[30*8], erc22[30*8], erc23[30*8], erc24[30*8], 
	    erc25[30*8], erc26[30*8], erc27[30*8], erc28[30*8], erc29[30*8], erc30[30*8], 
	    erc31[30*8], erc32[30*8], erc33[30*8], erc34[30*8], erc35[30*8], erc36[30*8], 
	    erc37[30*8], erc38[30*8], erc39[30*8], erc40[30*8], erc41[30*8], erc42[30*8], 
	    erc43[30*8], erc44[30*8], erc45[30*8], erc46[30*8], erc47[30*8], erc48[30*8], 
	    erc49[30*8], erc50[30*8], erc51[30*8], erc52[30*8], erc53[30*8], erc54[30*8];
} errcon_={

//       ERC1:
"\
I/O ERROR WHILE READING PROTAPE DATA SET                                        \
ILLEGAL 13000 TYPE CODE ON PROTAPE DATA SET                                     \
ILLEGAL BRANCHING IN ASEC  2...SEE COMPUTER PROGRAMMER                          ", 

//      ERC2:  
"\
CUT SEQUENCE APPEARS ON PROTAPE DATA SET                                        \
ERROR PROCESSING TRANTO...PROTAPE RECORD DOES NOT CONTAIN PROPER ID             \
I/O ERROR WRITING CLTAPE DATA SET                                               ", 
//      ERC3:
"\
ILLEGAL SURFACE TYPE ON PROTAPE DATA SET                                        \
EXCEEDED SURFACE STORAGE AVAILABLE                                              \
EXCEEDED ALLOWED NUMBER OF CHECK SURFACES                                       ", 
     // ERC4:  
"\
I/O ERROR FROM SUBROUTINE ASERCH                                                \
I/O ERROR READING SRFTAP DATA SET                                               \
ZERO INDIRP                                                                     ", 
      //ERC5 :
"\
ZERO INDIRV                                                                     \
ZERO SRFVCT                                                                     \
CUTTER NOT DEFINED PRIOR TO START UP                                            ", 
//      ERC6:
"\
CUTTER NOT DEFINED PRIOR TO MOTION SEQUENCE                                     \
FINI ENCOUNTERED WHILE PROCESSING TRANTO OR MULTI-CS TRANSFER                   \
CUTTER OUT OF TOLERANCE OF PS AT START OF CUT                                   ", 
//       ERC7:
"\
CUTTER OUT OF TOLERANCE OF DS AT START OF CUT                                   \
FORWARD DIRECTION CAN NOT BE DETERMINED                                         \
TI ORIENTATION CAN NOT BE DETERMINED...CHECK MOTION DIRECTION MODIFIER(GOLFT)   ", 
 //      ERC8:
"\
CUTTER DIA. NOT GREATER THAN ZERO                                               \
CUTTER HEIGHT NEG.                                                              \
CUTTER ANGLES (ALPHA + BETA) TOO LARGE                                          ", 
  //     ERC9:
"\
CUTTER ANGLE ALPHA NEG.                                                         \
DIA., ALPHA AND HEIGHT OF CUTTER INCONSISTENT                                   \
CUTTER ANGLE BETA NEG.                                                          ", 
//       ERC10:
"\
CORNER CIRCLE RAD.OF CUTTER NEG.                                                \
CORNER CIRCLE CENTER INCONSISTENT WITH UPPER LINE SEG. OF CUTTER                \
CORNER CIRCLE OF CUTTER INTERCEPTS LOWER LINE SEG. AT UNACCEPTABLE ANGLE        ", 
//       ERC11:
"\
CORNER CIRCLE OF CUTTER DOES NOT INTERSECT LOWER LINE SEG.                      \
CORNER CIRCLE OF CUTTER DOES NOT INTERSECT UPPER LINE SEG.                      \
CORNER CIRCLE OF CUTTER INTERSECTS UPPER LINE SEG. AT UNACCEPTABLE ANGLE        ", 
 //      ERC12:
"\
NO UPPER LINE SEG. - CORNER CIRCLE MEETS LOWER LINE SEG. INCORRECTLY            \
NO CUTTER SEG. DEFINED                                                          \
WARNING - NO LOWER LINE..ANGLE OF CIRCLE TANGENT AT TA NOT EQUAL TO ALPHA       ", 
//       ERC13:
"\
WARNING - NO UPPER LINE..ANGLE OF CIRCLE TANGENT AT UPPER POINT NOT EQ TO BETA  \
WARNING - CPLAN FAILURE INCHECK                                                 \
WARNING - VECTOR TEK TO TE DOTS NEGATIVE WITH TIK                               ", 
//       ERC14:
"\
WARNING - COS1 NEGATIVE AFTER TN REVERSED                                       \
NUMPTS COUNT EXHAUSTED IN PLANE ROUTINE                                         \
CENTR CSNR EXIT TAKEN DURING PLANE ROUTINE ITERATION                            ", 
//      ERC15:
"\
CENTR RESTARTS EXHAUSTED IN PLANE ROUTINE                                       \
WARNING - CANNOT FIND CRITICAL MIDDLE POINT..CUT VECTOR ACCEPTED                \
WARNING - CANNOT FIND TRIAL MIDDLE CRITICAL POINT..LAST APPRO. USED             ", 
 //      ERC16:
"\
WARNING - PLANEX CONVERGENCE FAILURE IN CENTR                                   \
DP LESS THAN TAU IN CENTR - NO RESTART AFTER PLANEX CONVERGENCE FAILURE         \
TINKR 5 - AXIS ITERATION DOES NOT CONVERGE                                      ", 
//       ERC17:
"\
TINKR CANNOT CALC. NEW TA                                                       \
WARNING - RESTART - CS ITERATION COUNT EXHAUSTED OR DP TOO SMALL                \
CPLAN FAILURE IN CENTR                                                          ", 
 //      ERC18:
"\
5-AXIS RESTART COUNTER EXHAUSTED                                                \
AMIND ITERATION COUNTER (IAMDCT) EXCEEDED                                       \
DIFFICULTY LINING UP TN AND SN                                                  ", 
//       ERC19:
"\
CANNOT CALCULATE UNIT NORMAL AT SURFACE POINT                                   \
INITIAL PREFERRED DIRECTION DOES NOT INTERSECT THE SURFACE                      \
CANNOT CALCULATE U1 VECTOR STARTING WITH TWO OR MORE DIRECTIONS                 ", 
//       ERC20:
"\
CUTTER REFPNT AND SURFACE CENTER OVERLAP..USE PSEUDO SURFACE                    \
WARNING - POINT FOUND ITERATION COUNTER (MDIC) IN RADAR EXHAUSTED               \
ZERO TN                                                                         ", 
//       ERC21:
"\
CANNOT FIND DIRECTION THAT INTERSECTS SURFACE                                   \
INVALID SURFACE TYPE                                                            \
RULED SURFACE ATTEMPTS TO REFERENCE INVALID SURFACE TYPE                        ", 
//       ERC22:
"\
INVALID SURFACE TYPE                                                            \
I/O ERROR WRITING CLTAPE DATA SET                                               \
DP ITERATION COUNT EXHAUSTED                                                    ", 
//       ERC23:
"\
CENTR CSR ITERATION FAILS IN ARLM3                                              \
NUMPTS COUNT EXHAUSTED IN ARLM3                                                 \
RESTART EXIT FROM CENTR                                                         ", 
//       ERC24:
"\
NOPS IN EFFECT BUT STARTUP NUMSUR UNEQUAL TO ONE                                \
CENTR ITERATION FAILS TO CONVERGE FOR STARTUP                                   \
ILLEGAL PROTAPE DATA FOR STARTUPS                                               ", 
//       ERC25:
"\
POCKET INPUT CONTAINS DUPLICATE POINTS                                          \
POCKET INPUT CONTAINS COLINEAR POINTS                                           \
POCKET INPUT POINTS ARE NOT COPLANAR                                            ", 
//       ERC26:
"\
POCKET INPUT POINTS DESCRIBE A CONCAVE FIGURE                                   \
I/O ERROR WRITING POCTAP DATA SET                                               \
I/O ERROR READING POCTAP DATA SET                                               ", 
//       ERC27:
"\
TOOL AXIS + PLANE OF POCKET ANGLE IS LESS THAN 12 DEGREES OR PTTYPE IS NEG.     \
I/O ERROR WRITING CLTAPE DATA SET FROM APOCK                                    \
I/O ERROR BACKSPACING POC TAP DATA SET                                          ", 
//       ERC28:
"\
CUTTER RADIUS IS NEGATIVE OF ZERO IN APOCK                                      \
IMPROPER IDIR SPECIFICATION FOR OFFSET                                          \
NO DIRECTED DISTANCE TO THE IS SUBSCRIPTED SURFACE                              ", 
//       ERC29:
"\
NO DIRECTED DISTANCE TO THE PS ALONG THE TOOL AXIS                              \
AMOVE MOVEMENT CAUSED THE CUTTER TO CROSS THE SURFACE                           \
PART SURFACE MOVEMENT MOVED THE CUTTER OUT OF TOLERANCE OF THE DRIVE SURFACE    ", 
//       ERC30:
"\
UNIT NORMAL ROUTINE FAILED IN AOFSET                                            \
SURFACE IS TANGENT TO INDIR VECTOR                                              \
ITERATION COUNTER EXCEEDED                                                      ", 
//       ERC31:
"\
CUTTER IMPROPERLY POSITIONED BY AOFSET BEFORE CALLING AMOVE                     \
UNABLE TO NORMALIZE PLANE VECTOR (TI X TA)                                      \
CUTTER IS RIGHT ON SURFACE - USE INDIR                                          ", 
//       ERC32:
"\
UNABLE TO NORMALIZE PSUEDO PLANE VECTOR IN NOPS CASE                            \
PS PLANE IS VERTICAL                                                            \
FORWARD DIRECTION (TI) HAS NO XY PROJECTION                                     ", 
//       ERC33:
"\
DS IS NOT LINE OR CIRCLE                                                        \
DS PLANE IS HORIZONTAL                                                          \
RADIUS OF CIRCLE DS IS LESS THAN CUTTER RADIUS                                  ", 
//       ERC34:
"\
CS IS NOT LINE OR CIRCLE                                                        \
CS PLANE IS HORIZONTAL                                                          \
CS CIRCLE RADIUS IS LESS THAN CUTTER RADIUS                                     ", 
//       ERC35:
"\
CUTTER TOO CLOSE TO CS - THICK MAY BE APPLIED TO WRONG SIDE OF SURFACE (LINE CS)\
CUTTER TOO CLOSE TO CS-THICK MAY BE APPLIED TO WRONG SIDE OF SURF.(CIRCLE CS)   \
THICK CORRECTION CAUSES CIRCLE CS RADIUS TO BE LESS THAN .01                    ", 
//       ERC36:
"\
THICK CORRECTION CAUSES CIRCLE CS RADIUS TO BE NEGATIVE                         \
NUMAX AND MULTAX SETTINGS ARE INCONSISTENT                                      \
ICC   (CONTROLLING SURFACE INDICATOR) IS NOT 1 OR 2                             ", 
//       ERC37:
"\
THE PROGRAM INDICATES THE CONTROLLING SURFACE IS A RULED SURFACE, BUT IT IS NOT \
IMPOSSIBLE ANGLE SPECIFICATION - 4-AXIS CASE                                    \
THE PLANE IN WHICH TA IS TO LIE IS TANGENT TO THE CONTROLLING SURFACE           ", 
//       ERC38:
"\
NORMALIZATION FAILURE SETTING UP SPECIAL COORDINATE SYSTEM                      \
NORMALIZATION FAILURE ON CANDIDATE TOOL AXIS VECTOR                             \
ALPHA = 0  IN 4 AXIS CASE - MAY LEAD TO IMPOSSIBLE SPECIFICATION                ", 
//       ERC39:
"\
SIGN CONVENTION ON ANGLE ALPHA BREAKS DOWN - WILL TRY TO USE TI                 \
IMPOSSIBLE ANGLE SPECIFICATION 5-AXIS CASE                                      \
UNABLE TO NORMALIZE PSEUDO PLANE 5-AXIS CASE                                    ", 
//       ERC40:
"\
CUTTER RADIUS IS ZERO BUT TO OR PAST REQUIRED                                   \
DS AND/OR CS ARE NOT LINES OR CIRCLES                                           \
NO POSSIBLE STOPPING POSITIONS FOUND                                            ", 
//       ERC41:
"\
DS AND CS ARE BOTH LINES,BUT DO NOT INTERSECT                                   \
TANTO SPECIFIED FOR LINE-LINE CASE                                              \
NO POSSIBLE TANTO POINT EXISTS, BUT TANTO IS REQUIRED                           ", 
//       ERC42:
"\
DS AND CS CIRCLES HAVE SAME CENTER                                              \
UNABLE TO NORMALIZE VECTOR BETWEEN CENTER OF DS AND CS CIRCLES                  \
ONLY ONE INTERSECTION FOUND WHEN THERE SHOULD BE TWO                            ", 
//       ERC43:
"\
NONE OF THE POINTS FOUND MEETS THE REQUIREMENTS FOR THE FINAL OUTPUT POINT      \
PS PLANE IS TOO NEARLY VERTICAL                                                 \
AERR - FAILURE, NO. OF WARNING MESSAGES ALLOWED PER CUT SEQUENCE EXCEEDED       ", 
//       ERC44:
"\
ASEC2 - ILLEGAL PROTAPE DATA SET FOR TLAXIS/. (ITEM 4 NOT 1.-5.).               \
ASEC2 - UNABLE TO NORMALIZE VECTOR GIVEN IN TLAXIS/VECTOR                       \
ASEC2 - ILLEGAL ITEM 4 PARAMETER FOR NORMPS OR NORMDS.                          ", 
//       ERC45:
"\
ASEC2 - ILLEGAL ITEM 4 PARAMETER FOR TLAXIS/ATANGL.                             \
ASEC2 - ABS(ALPHA) GREATER THAN NINETY DEGREES IN TLAXIS/ATANGL,N,ALPHA.        \
ASEC2 - ABS(GAM) GREATER THAN 90 DEGREES IN TLAXIS/ATANGL,N,ALP,CUTANG,GAM.     ", 
//       ERC46:
"\
ASEC2 - ILLEGAL NO. OF WORDS IN PROTAPE DATA SET FOR TLAXIS/ATANGL,...          \
ASEC2 - UNABLE TO NORMALIZE SVECT IN TLAXIS/ATANGL,N,ALPHA,SVECT                \
ATINKR - TI VECTOR DOES NOT RESOLVE THE SIGN CONVENTION FAILURE ON ALPHA        ", 
//       ERC47:
"\
PROCESSOR ERROR IN 2-D ROUTINE POINT SELECTION                                  \
ILLEGAL CUTTER--DIAMETER INCONSISTENT WITH CORNER RADIUS                        \
WARNING - CUTTER ON WRONG SIDE OF DS OR DIRECTION IN ERROR                      ", 
//       ERC48:
"\
EFFECTIVE RADIUS NEGATIVE IN POCKET INPUT                                       \
GIVEN POCKETING OFFSET IS NEGATIVE                                              \
GIVEN POCKET FINISHING OFFSET IS NEGATIVE                                       ", 
//       ERC49:
"\
ONE OR MORE OF THE GIVEN POCKET FEEDRATES IS NEGATIVE                           \
OVERRIDE INDICATOR NOT 0 OR 1 IN POCKET                                         \
POINT TYPE INDICATOR NOT 0 OR 1 IN POCKET                                       ", 
//       ERC50:
"\
ERROR WHILE TESTING POCKET PARAMETERS                                           \
CUTTER WILL NOT FIT IN POCKET                                                   \
UNABLE TO SETUP PSUEDO DS FOR 2D STARTUP - TRY 3DCALC                           ", 
//       ERC51:
"\
FINAL POINT FOUND IS NOT IN FWD DIRECTION                                       \
RESTART EXIT FROM CENTER IN APLANE                                              \
WARNING    JTN CONVENTION VIOLATED                                              ", 
//       ERC52:
"\
ATTEMPT TO CORRECT JTN VIOLATION FAILED                                         \
BAD CANONICAL FORM ON PROTAPE                                                   \
NORMAL DISTANCE CALCULATION FAILURE                                             ", 
//       ERC53:
"\
SURFACE USED AS THE BOTTOM OF POCKET IS NOT A PLANE                             \
POSSIBLE LOOP                                                                   \
WARNING. AUTOPS USED FOR NON-VERTICAL TOOL WHEN TO OR PAST IN EFFECT FOR PS     ", 
 //      ERC54:
"\
CAUTION...CUTTER MAY BE GOUGING DS, WHICH WAS (TANTO) CS PREVIOUSLY.            \
                                                                                \
                                                                                ", 
};

#define errcon_1 errcon_












/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 *** */
/*      DATA ERC1  /'I/O ERROR WHILE READING PROTAPE DATA SET */
/*     1                           ILLEGAL 13000 TYPE CODE ON PROTAPE DATA */
/*     2 SET                                     ILLEGAL BRANCHING IN ASEC */
/*     32...SEE COMPUTER PROGRAMMER                            '/ */
/*      DATA ERC2  /'CUT SEQUENCE APPEARS ON PROTAPE DATA SET */
/*     1                           ERROR PROCESSING TRANTO...PROTAPE RECOR */
/*     2D DOES NOT CONTAIN PROPER ID             I/O ERROR WRITING CLTAPE */
/*     3DATA SET                                               '/ */
/*      DATA ERC3  /'ILLEGAL SURFACE TYPE ON PROTAPE DATA SET */
/*     1                           EXCEEDED SURFACE STORAGE AVAILABLE */
/*     2                                         EXCEEDED ALLOWED NUMBER O */
/*     3F CHECK SURFACES                                       '/ */
/*      DATA ERC4  /'I/O ERROR FROM SUBROUTINE ASERCH */
/*     1                           I/O ERROR READING SRFTAP DATA SET */
/*     2                                         ZERO INDIRP */
/*     3                                                       '/ */
/*      DATA ERC5  /'ZERO INDIRV */
/*     1                           ZERO SRFVCT */
/*     2                                         CUTTER NOT DEFINED PRIOR */
/*     3TO START UP                                            '/ */
/*      DATA ERC6  /'CUTTER NOT DEFINED PRIOR TO MOTION SEQUENCE */
/*     1                           FINI ENCOUNTERED WHILE PROCESSING TRANT */
/*     2O OR MULTI-CS TRANSFER                   CUTTER OUT OF TOLERANCE O */
/*     3F PS AT START OF CUT                                   '/ */
/*      DATA ERC7  /'CUTTER OUT OF TOLERANCE OF DS AT START OF CUT */
/*     1                           FORWARD DIRECTION CAN NOT BE DETERMINED */
/*     2                                         TI ORIENTATION CAN NOT BE */
/*     3 DETERMINED...CHECK MOTION DIRECTION MODIFIER(GOLFT)   '/ */
/*      DATA ERC8  /'CUTTER DIA. NOT GREATER THAN ZERO */
/*     1                           CUTTER HEIGHT NEG. */
/*     2                                         CUTTER ANGLES (ALPHA + BE */
/*     3TA) TOO LARGE                                          '/ */
/*      DATA ERC9  /'CUTTER ANGLE ALPHA NEG. */
/*     1                           DIA., ALPHA AND HEIGHT OF CUTTER INCONS */
/*     2ISTENT                                   CUTTER ANGLE BETA NEG. */
/*     3                                                       '/ */
/*      DATA ERC10 /'CORNER CIRCLE RAD.OF CUTTER NEG. */
/*     1                           CORNER CIRCLE CENTER INCONSISTENT WITH */
/*     2UPPER LINE SEG. OF CUTTER                CORNER CIRCLE OF CUTTER I */
/*     NTERCEPTS LOWER LINE SEG. AT UNACCEPTABLE ANGLE         '/ */
/*      DATA ERC11 /'CORNER CIRCLE OF CUTTER DOES NOT INTERSECT LOWER LINE */
/*     1SEG.                       CORNER CIRCLE OF CUTTER DOES NOT INTERS */
/*     2ECT UPPER LINE SEG.                      CORNER CIRCLE OF CUTTER I */
/*     3NTERSECTS UPPER LINE SEG. AT UNACCEPTABLE ANGLE        '/ */
/*      DATA ERC12 /'NO UPPER LINE SEG. - CORNER CIRCLE MEETS LOWER LINE S */
/*     1EG. INCORRECTLY            NO CUTTER SEG. DEFINED */
/*     2                                         WARNING - NO LOWER LINE.. */
/*     3ANGLE OF CIRCLE TANGENT AT TA NOT EQUAL TO ALPHA       '/ */
/*      DATA ERC13 /'WARNING - NO UPPER LINE..ANGLE OF CIRCLE TANGENT AT U */
/*     1PPER POINT NOT EQ TO BETA  WARNING - CPLAN FAILURE INCHECK */
/*     2                                         WARNING - VECTOR TEK TO T */
/*     3E DOTS NEGATIVE WITH TIK                               '/ */
/*      DATA ERC14 /'WARNING - COS1 NEGATIVE AFTER TN REVERSED */
/*     1                           NUMPTS COUNT EXHAUSTED IN PLANE ROUTINE */
/*     2                                         CENTR CSNR EXIT TAKEN DUR */
/*     3ING PLANE ROUTINE ITERATION                            '/ */
/*      DATA ERC15 /'CENTR RESTARTS EXHAUSTED IN PLANE ROUTINE */
/*     1                           WARNING - CANNOT FIND CRITICAL MIDDLE P */
/*     2OINT..CUT VECTOR ACCEPTED                WARNING - CANNOT FIND TRI */
/*     3AL MIDDLE CRITICAL POINT..LAST APPRO. USED             '/ */
/*      DATA ERC16 /'WARNING - PLANEX CONVERGENCE FAILURE IN CENTR */
/*     1                           DP LESS THAN TAU IN CENTR - NO RESTART */
/*     2AFTER PLANEX CONVERGENCEFAILURE          TINKR 5 - AXIS ITERATION */
/*     3DOES NOT CONVERGE                                      '/ */
/*      DATA ERC17 /'TINKR CANNOT CALC. NEW TA */
/*     1                           WARNING - RESTART - CS ITERATION COUNT */
/*     2EXHAUSTED OR DP TOO SMALL                CPLAN FAILURE IN CENTR */
/*     3                                                       '/ */
/*      DATA ERC18 /'5-AXIS RESTART COUNTER EXHAUSTED */
/*     1                           AMIND ITERATION COUNTER (IAMDCT) EXCEED */
/*     2ED                                       DIFFICULTY LINING UP TN A */
/*     3ND SN                                                  '/ */
/*      DATA ERC19 /'CANNOT CALCULATE UNIT NORMAL AT SURFACE POINT */
/*     1                           INITIAL PREFERRED DIRECTION DOES NOT IN */
/*     2TERSECT THE SURFACE                      CANNOT CALCULATE U1 VECTO */
/*     3R STARTING WITH TWO OR MORE DIRECTIONS                 '/ */
/*      DATA ERC20 /'CUTTER REFPNT AND SURFACE CENTER OVERLAP..USE PSEUDO */
/*     1SURFACE                    WARNING - POINT FOUND ITERATION COUNTER */
/*     2(MDIC) IN RADAR EXHAUSTED                ZERO TN */
/*     3                                                       '/ */
/*      DATA ERC21 /'CANNOT FIND DIRECTION THAT INTERSECTS SURFACE */
/*     1                           INVALID SURFACE TYPE */
/*     2                                         RULED SURFACE ATTEMPTS TO */
/*     3REFERENCE INVALID SURFACE TYPE                         '/ */
/*      DATA ERC22 /'INVALID SURFACE TYPE */
/*     1                           I/O ERROR WRITING CLTAPE DATA SET */
/*     2                                         DP ITERATION COUNT EXHAUS */
/*     3TED                                                    '/ */
/*      DATA ERC23 /'CENTR CSR ITERATION FAILS IN ARLM3 */
/*     1                           NUMPTS COUNT EXHAUSTED IN ARLM3 */
/*     2                                         RESTART EXIT FROM CENTR */
/*     3                                                       '/ */
/*      DATA ERC24 /'NOPS IN EFFECT BUT STARTUP NUMSUR UNEQUAL TO ONE */
/*     1                           CENTR ITERATION FAILS TO CONVERGE FOR S */
/*     2TARTUP                                   ILLEGAL PROTAPE DATA FOR */
/*     3STARTUPS                                               '/ */
/*      DATA ERC25 /'POCKET INPUT CONTAINS DUPLICATE POINTS */
/*     1                           POCKET INPUT CONTAINS COLINEAR POINTS */
/*     2                                         POCKET INPUT POINTS ARE N */
/*     3OT COPLANAR                                            '/ */
/*      DATA ERC26 /'POCKET INPUT POINTS DESCRIBE A CONCAVE FIGURE */
/*     1                           I/O ERROR WRITING POCTAP DATA SET */
/*     2                                         I/O ERROR READING POCTAP */
/*     3DATA SET                                               '/ */
/*      DATA ERC27 /'TOOL AXIS + PLANE OF POCKET ANGLE IS LESS THAN 12 DEG */
/*     1REES OR PTTYPE IS NEG.     I/O ERROR WRITING CLTAPE DATA SET FROM */
/*     2APOCK                                    I/O ERROR BACKSPACING POC */
/*     3TAP DATA SET                                           '/ */
/*      DATA ERC28 /'CUTTER RADIUS IS NEGATIVE OF ZERO IN APOCK */
/*     1                           IMPROPER IDIR SPECIFICATION FOR OFFSET */
/*     2                                         NO DIRECTED DISTANCE TO T */
/*     3HE IS SUBSCRIPED SURFACE                 '/ */
/*      DATA ERC29 /'NO DIRECTED DISTANCE TO THE PS ALONG THE TOOL AXIS */
/*     1                           AMOVE MOVEMENT CAUSED THE CUTTER TO CRO */
/*     2SS THE SURFACE                           PART SURFACE MOVEMENT MOV */
/*     2ED THE CUTTER OUT OF TOLERANCE OF THE DRIVE SURFACE    '/ */
/*      DATA ERC30 /'UNIT NORMAL ROUTINE FAILED IN AOFSET */
/*     1                           SURFACE IS TANGENT TO INDIR VECTOR */
/*     2                                         ITERATION COUNTER EXCEEDE */
/*     3D                                                      '/ */
/*      DATA ERC31 /'CUTTER IMPROPERLY POSITIONED BY AOFSET BEFORE CALLING */
/*     1AMOVE                      UNABLE TO NORMALIZE PLANE VECTOR (TI X */
/*     2TA)                                      CUTTER IS RIGHT ON SURFAC */
/*     3E - USE INDIR                                          '/ */
/*      DATA ERC32 /'UNABLE TO NORMALIZE PSUEDO PLANE VECTOR IN NOPS CASE */
/*     1                           PS PLANE IS VERTICAL */
/*     2                                         FORWARD DIRECTION (TI) HA */
/*     3S NO XY PROJECTION                                     '/ */
/*      DATA ERC33 /'DS IS NOT LINE OR CIRCLE */
/*     1                           DS PLANE IS HORIZONTAL */
/*     2                                         RADIUS OF CIRCLE DS IS LE */
/*     3SS THAN CUTTER RADIUS                                  '/ */
/*      DATA ERC34 /'CS IS NOT LINE OR CIRCLE */
/*     1                           CS PLANE IS HORIZONTAL */
/*     2                                         CS CIRCLE RADIUS IS LESS */
/*     3THAN CUTTER RADIUS                                     '/ */
/*      DATA ERC35 /'CUTTER TOO CLOSE TO CS - THICK MAY BE APPLIED TO WRON */
/*     1G SIDE OF SURFACE (LINE CS)CUTTER TOO CLOSE TO CS-THICK MAY BE APP */
/*     2LIED TO WRONG SIDE OF SURF.(CIRCLE CS)   THICK CORRECTION CAUSES C */
/*     3IRCLE CS RADIUS TO BE LESS THAN .01                    '/ */
/*      DATA ERC36 /'THICK CORRECTION CAUSES CIRCLE CS RADIUS TO BE NEGATI */
/*     1VE                         NUMAX AND MULTAX SETTINGS ARE INCONSIST */
/*     2ENT                                      ICC   (CONTROLLING SURFAC */
/*     3E INDICATOR) IS NOT 1 OR 2                             '/ */
/*      DATA ERC37 /'THE PROGRAM INDICATES THE CONTROLLING SURFACE IS A RU */
/*     1LED SURFACE, BUT IT IS NOT IMPOSSIBLE ANGLE SPECIFICATION - 4-AXIS */
/*     2 CASE                                    THE PLANE IN WHICH TA IS */
/*     3TO LIE IS TANGENT TO THE CONTROLLING SURFACE           '/ */
/*      DATA ERC38 /'NORMALIZATION FAILURE SETTING UP SPECIAL COORDINATE S */
/*     |YSTEM                      NORMALIZATION FAILURE ON CANDIDATE TOOL */
/*     2AXIS VECTOR                              ALPHA = 0  IN 4 AXIS CASE */
/*     3 - MAY LEAD TO IMPOSSIBLE SPECIFICATION                '/ */
/*      DATA ERC39 /'SIGN CONVENTION ON ANGLE ALPHA BREAKS DOWN - WILL TRY */
/*     1TO USE TI                  IMPOSSIBLE ANGLE SPECIFICATION 5-AXIS C */
/*     2ASE                                      UNABLE TO NORMALIZE PSEUD */
/*     2O PLANE 5-AXIS CASE                                    '/ */
/*      DATA ERC40 /'CUTTER RADIUS IS ZERO BUT TO OR PAST REQUIRED */
/*     1                           DS AND/OR CS ARE NOT LINES OR CIRCLES */
/*     2                                         NO POSSIBLE STOPPING POSI */
/*     3TIONS FOUND                                            '/ */
/*      DATA ERC41 /'DS AND CS ARE BOTH LINES,BUT DO NOT INTERSECT */
/*     1                           TANTO SPECIFIED FOR LINE-LINE CASE */
/*     2                                         NO POSSIBLE TANTO POINT E */
/*     3XISTS, BUT TANTO IS REQUIRED                           '/ */
/*      DATA ERC42 /'DS AND CS CIRCLES HAVE SAME CENTER */
/*     1                           UNABLE TO NORMALIZE VECTOR BETWEEN CENT */
/*     2ER OF DS AND CS CIRCLES                  ONLY ONE INTERSECTION FOU */
/*     3ND WHEN THERE SHOULD BE TWO                            '/ */
/*      DATA ERC43 /'NONE OF THE POINTS FOUND MEETS THE REQUIREMENTS FOR T */
/*     1HE FINAL OUTPUT POINT      PS PLANE IS TOO NEARLY VERTICAL */
/*     2                                         AERR - FAILURE, NO. OF WA */
/*     3RNING MESSAGES ALLOWED PER CUT SEQUENCE EXCEEDED       '/ */
/*      DATA ERC44 /'ASEC2 - ILLEGAL PROTAPE DATA SET FOR TLAXIS/. (ITEM 4 */
/*     1NOT 1.-5.).                ASEC2 - UNABLE TO NORMALIZE VECTOR GIVE */
/*     2N IN TLAXIS/VECTOR                       ASEC2 - ILLEGAL ITEM 4 PA */
/*     3RAMETER FOR NORMPS OR NORMDS.                          '/ */
/*      DATA ERC45 /'ASEC2 - ILLEGAL ITEM 4 PARAMETER FOR TLAXIS/ATANGL. */
/*     1                           ASEC2 - ABS(ALPHA) GREATER THAN NINETY */
/*     2DEGREES IN TLAXIS/ATANGL,N,ALPHA.        ASEC2 - ABS(GAM) GREATER */
/*     3THAN 90 DEGREES IN TLAXIS/ATANGL,N,ALP,CUTANG,GAM.     '/ */
/*      DATA ERC46 /'ASEC2 - ILLEGAL NO. OF WORDS IN PROTAPE DATA SET FOR */
/*     1TLAXIS/ATANGL,...          ASEC2 - UNABLE TO NORMALIZE SVECT IN TL */
/*     2AXIS/ATANGL,N,ALPHA,SVECT                ATINKR - TI VECTOR DOES N */
/*     3OT RESOLVE THE SIGN CONVENTION FAILURE ON ALPHA        '/ */
/*      DATA ERC47 /'PROCESSOR ERROR IN 2-D ROUTINE POINT SELECTION */
/*     1                           ILLEGAL CUTTER--DIAMETER INCONSISTENT W */
/*     2ITH CORNER RADIUS                        WARNING - CUTTER ON WRONG */
/*     3SIDE OF DS OR DIRECTION IN ERROR                       '/ */
/*      DATA ERC48 /'EFFECTIVE RADIUS NEGATIVE IN POCKET INPUT */
/*     1                           GIVEN POCKETING OFFSET IS NEGATIVE */
/*     2                                         GIVEN POCKET FINISHING OF */
/*     3FSET IS NEGATIVE                                       '/ */
/*      DATA ERC49 /'ONE OR MORE OF THE GIVEN POCKET FEEDRATES IS NEGATIVE */
/*     1                           OVERRIDE INDICATOR NOT 0 OR 1 IN POCKET */
/*     2                                         POINT TYPE INDICATOR NOT */
/*     30 OR 1 IN POCKET                                       '/ */
/*      DATA ERC50 /'ERROR WHILE TESTING POCKET PARAMETERS */
/*     1                           CUTTER WILL NOT FIT IN POCKET */
/*     2                                         UNABLE TO SETUP PSUEDO DS */
/*     3 FOR 2D STARTUP - TRY 3DCALC                           '/ */
/*      DATA ERC51 /'FINAL POINT FOUND IS NOT IN FWD DIRECTION */
/*     1                           RESTART EXIT FROM CENTER IN APLANE */
/*     2                                         WARNING    JTN CONVENTION */
/*     3 VIOLATED                                              '/ */
/*      DATA ERC52 /'ATTEMPT TO CORRECT JTN VIOLATION FAILED */
/*     1                           BAD CANONICAL FORM ON PROTAPE */
/*     2                                         NORMAL DISTANCE CALCULATI */
/*     3ON FAILURE                                             '/ */
/*      DATA ERC53 /'SURFACE USED AS THE BOTTOM OF POCKET IS NOT A PLANE */
/*     1                           POSSIBLE LOOP */
/*     2                                           WARNING. AUTOPS USED FO */
/*     3R NON-VERTICAL TOOL WHEN TO OR PAST IN EFFECT FOR PS   '/ */
/*      DATA ERC54 /'CAUTION...CUTTER MAY BE GOUGING DS, WHICH WAS (TANTO) */
/*     1 CS PREVIOUSLY. */
/*     2 */
/*     3                                                       '/ */

