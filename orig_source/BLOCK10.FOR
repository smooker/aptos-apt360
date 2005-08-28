      BLOCK DATA
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      COMMON/ERRCON/ERC1(30),ERC2(30),ERC3(30),ERC4(30),ERC5(30),
     1ERC6(30),ERC7(30),ERC8(30),ERC9(30),ERC10(30),ERC11(30),ERC12(30),
     2 ERC13(30),ERC14(30),ERC15(30),ERC16(30),ERC17(30),ERC18(30),
     3 ERC19(30),ERC20(30),ERC21(30),ERC22(30),ERC23(30),ERC24(30),
     4 ERC25(30),ERC26(30),ERC27(30),ERC28(30),ERC29(30),ERC30(30),
     5 ERC31(30),ERC32(30),ERC33(30),ERC34(30),ERC35(30),ERC36(30),
     6 ERC37(30),ERC38(30),ERC39(30),ERC40(30),ERC41(30),ERC42(30),
     7 ERC43(30),ERC44(30),ERC45(30),ERC46(30),ERC47(30),ERC48(30),
     8 ERC49(30),ERC50(30),ERC51(30),ERC52(30),ERC53(30),ERC54(30)
      DATA ERC1  /'I/O ERROR WHILE READING PROTAPE DATA SET
     1                           ILLEGAL 13000 TYPE CODE ON PROTAPE DATA
     2 SET                                     ILLEGAL BRANCHING IN ASEC
     32...SEE COMPUTER PROGRAMMER                            '/
      DATA ERC2  /'CUT SEQUENCE APPEARS ON PROTAPE DATA SET
     1                           ERROR PROCESSING TRANTO...PROTAPE RECOR
     2D DOES NOT CONTAIN PROPER ID             I/O ERROR WRITING CLTAPE
     3DATA SET                                               '/
      DATA ERC3  /'ILLEGAL SURFACE TYPE ON PROTAPE DATA SET
     1                           EXCEEDED SURFACE STORAGE AVAILABLE
     2                                         EXCEEDED ALLOWED NUMBER O
     3F CHECK SURFACES                                       '/
      DATA ERC4  /'I/O ERROR FROM SUBROUTINE ASERCH
     1                           I/O ERROR READING SRFTAP DATA SET
     2                                         ZERO INDIRP
     3                                                       '/
      DATA ERC5  /'ZERO INDIRV
     1                           ZERO SRFVCT
     2                                         CUTTER NOT DEFINED PRIOR
     3TO START UP                                            '/
      DATA ERC6  /'CUTTER NOT DEFINED PRIOR TO MOTION SEQUENCE
     1                           FINI ENCOUNTERED WHILE PROCESSING TRANT
     2O OR MULTI-CS TRANSFER                   CUTTER OUT OF TOLERANCE O
     3F PS AT START OF CUT                                   '/
      DATA ERC7  /'CUTTER OUT OF TOLERANCE OF DS AT START OF CUT
     1                           FORWARD DIRECTION CAN NOT BE DETERMINED
     2                                         TI ORIENTATION CAN NOT BE
     3 DETERMINED...CHECK MOTION DIRECTION MODIFIER(GOLFT)   '/
      DATA ERC8  /'CUTTER DIA. NOT GREATER THAN ZERO
     1                           CUTTER HEIGHT NEG.
     2                                         CUTTER ANGLES (ALPHA + BE
     3TA) TOO LARGE                                          '/
      DATA ERC9  /'CUTTER ANGLE ALPHA NEG.
     1                           DIA., ALPHA AND HEIGHT OF CUTTER INCONS
     2ISTENT                                   CUTTER ANGLE BETA NEG.
     3                                                       '/
      DATA ERC10 /'CORNER CIRCLE RAD.OF CUTTER NEG.
     1                           CORNER CIRCLE CENTER INCONSISTENT WITH
     2UPPER LINE SEG. OF CUTTER                CORNER CIRCLE OF CUTTER I
     NTERCEPTS LOWER LINE SEG. AT UNACCEPTABLE ANGLE         '/
      DATA ERC11 /'CORNER CIRCLE OF CUTTER DOES NOT INTERSECT LOWER LINE
     1SEG.                       CORNER CIRCLE OF CUTTER DOES NOT INTERS
     2ECT UPPER LINE SEG.                      CORNER CIRCLE OF CUTTER I
     3NTERSECTS UPPER LINE SEG. AT UNACCEPTABLE ANGLE        '/
      DATA ERC12 /'NO UPPER LINE SEG. - CORNER CIRCLE MEETS LOWER LINE S
     1EG. INCORRECTLY            NO CUTTER SEG. DEFINED
     2                                         WARNING - NO LOWER LINE..
     3ANGLE OF CIRCLE TANGENT AT TA NOT EQUAL TO ALPHA       '/
      DATA ERC13 /'WARNING - NO UPPER LINE..ANGLE OF CIRCLE TANGENT AT U
     1PPER POINT NOT EQ TO BETA  WARNING - CPLAN FAILURE INCHECK
     2                                         WARNING - VECTOR TEK TO T
     3E DOTS NEGATIVE WITH TIK                               '/
      DATA ERC14 /'WARNING - COS1 NEGATIVE AFTER TN REVERSED
     1                           NUMPTS COUNT EXHAUSTED IN PLANE ROUTINE
     2                                         CENTR CSNR EXIT TAKEN DUR
     3ING PLANE ROUTINE ITERATION                            '/
      DATA ERC15 /'CENTR RESTARTS EXHAUSTED IN PLANE ROUTINE
     1                           WARNING - CANNOT FIND CRITICAL MIDDLE P
     2OINT..CUT VECTOR ACCEPTED                WARNING - CANNOT FIND TRI
     3AL MIDDLE CRITICAL POINT..LAST APPRO. USED             '/
      DATA ERC16 /'WARNING - PLANEX CONVERGENCE FAILURE IN CENTR
     1                           DP LESS THAN TAU IN CENTR - NO RESTART
     2AFTER PLANEX CONVERGENCEFAILURE          TINKR 5 - AXIS ITERATION
     3DOES NOT CONVERGE                                      '/
      DATA ERC17 /'TINKR CANNOT CALC. NEW TA
     1                           WARNING - RESTART - CS ITERATION COUNT
     2EXHAUSTED OR DP TOO SMALL                CPLAN FAILURE IN CENTR
     3                                                       '/
      DATA ERC18 /'5-AXIS RESTART COUNTER EXHAUSTED
     1                           AMIND ITERATION COUNTER (IAMDCT) EXCEED
     2ED                                       DIFFICULTY LINING UP TN A
     3ND SN                                                  '/
      DATA ERC19 /'CANNOT CALCULATE UNIT NORMAL AT SURFACE POINT
     1                           INITIAL PREFERRED DIRECTION DOES NOT IN
     2TERSECT THE SURFACE                      CANNOT CALCULATE U1 VECTO
     3R STARTING WITH TWO OR MORE DIRECTIONS                 '/
      DATA ERC20 /'CUTTER REFPNT AND SURFACE CENTER OVERLAP..USE PSEUDO
     1SURFACE                    WARNING - POINT FOUND ITERATION COUNTER
     2(MDIC) IN RADAR EXHAUSTED                ZERO TN
     3                                                       '/
      DATA ERC21 /'CANNOT FIND DIRECTION THAT INTERSECTS SURFACE
     1                           INVALID SURFACE TYPE
     2                                         RULED SURFACE ATTEMPTS TO
     3REFERENCE INVALID SURFACE TYPE                         '/
      DATA ERC22 /'INVALID SURFACE TYPE
     1                           I/O ERROR WRITING CLTAPE DATA SET
     2                                         DP ITERATION COUNT EXHAUS
     3TED                                                    '/
      DATA ERC23 /'CENTR CSR ITERATION FAILS IN ARLM3
     1                           NUMPTS COUNT EXHAUSTED IN ARLM3
     2                                         RESTART EXIT FROM CENTR
     3                                                       '/
      DATA ERC24 /'NOPS IN EFFECT BUT STARTUP NUMSUR UNEQUAL TO ONE
     1                           CENTR ITERATION FAILS TO CONVERGE FOR S
     2TARTUP                                   ILLEGAL PROTAPE DATA FOR
     3STARTUPS                                               '/
      DATA ERC25 /'POCKET INPUT CONTAINS DUPLICATE POINTS
     1                           POCKET INPUT CONTAINS COLINEAR POINTS
     2                                         POCKET INPUT POINTS ARE N
     3OT COPLANAR                                            '/
      DATA ERC26 /'POCKET INPUT POINTS DESCRIBE A CONCAVE FIGURE
     1                           I/O ERROR WRITING POCTAP DATA SET
     2                                         I/O ERROR READING POCTAP
     3DATA SET                                               '/
      DATA ERC27 /'TOOL AXIS + PLANE OF POCKET ANGLE IS LESS THAN 12 DEG
     1REES OR PTTYPE IS NEG.     I/O ERROR WRITING CLTAPE DATA SET FROM
     2APOCK                                    I/O ERROR BACKSPACING POC
     3TAP DATA SET                                           '/
      DATA ERC28 /'CUTTER RADIUS IS NEGATIVE OF ZERO IN APOCK
     1                           IMPROPER IDIR SPECIFICATION FOR OFFSET
     2                                         NO DIRECTED DISTANCE TO T
     3HE IS SUBSCRIPED SURFACE                 '/
      DATA ERC29 /'NO DIRECTED DISTANCE TO THE PS ALONG THE TOOL AXIS
     1                           AMOVE MOVEMENT CAUSED THE CUTTER TO CRO
     2SS THE SURFACE                           PART SURFACE MOVEMENT MOV
     2ED THE CUTTER OUT OF TOLERANCE OF THE DRIVE SURFACE    '/
      DATA ERC30 /'UNIT NORMAL ROUTINE FAILED IN AOFSET
     1                           SURFACE IS TANGENT TO INDIR VECTOR
     2                                         ITERATION COUNTER EXCEEDE
     3D                                                      '/
      DATA ERC31 /'CUTTER IMPROPERLY POSITIONED BY AOFSET BEFORE CALLING
     1AMOVE                      UNABLE TO NORMALIZE PLANE VECTOR (TI X
     2TA)                                      CUTTER IS RIGHT ON SURFAC
     3E - USE INDIR                                          '/
      DATA ERC32 /'UNABLE TO NORMALIZE PSUEDO PLANE VECTOR IN NOPS CASE
     1                           PS PLANE IS VERTICAL
     2                                         FORWARD DIRECTION (TI) HA
     3S NO XY PROJECTION                                     '/
      DATA ERC33 /'DS IS NOT LINE OR CIRCLE
     1                           DS PLANE IS HORIZONTAL
     2                                         RADIUS OF CIRCLE DS IS LE
     3SS THAN CUTTER RADIUS                                  '/
      DATA ERC34 /'CS IS NOT LINE OR CIRCLE
     1                           CS PLANE IS HORIZONTAL
     2                                         CS CIRCLE RADIUS IS LESS
     3THAN CUTTER RADIUS                                     '/
      DATA ERC35 /'CUTTER TOO CLOSE TO CS - THICK MAY BE APPLIED TO WRON
     1G SIDE OF SURFACE (LINE CS)CUTTER TOO CLOSE TO CS-THICK MAY BE APP
     2LIED TO WRONG SIDE OF SURF.(CIRCLE CS)   THICK CORRECTION CAUSES C
     3IRCLE CS RADIUS TO BE LESS THAN .01                    '/
      DATA ERC36 /'THICK CORRECTION CAUSES CIRCLE CS RADIUS TO BE NEGATI
     1VE                         NUMAX AND MULTAX SETTINGS ARE INCONSIST
     2ENT                                      ICC   (CONTROLLING SURFAC
     3E INDICATOR) IS NOT 1 OR 2                             '/
      DATA ERC37 /'THE PROGRAM INDICATES THE CONTROLLING SURFACE IS A RU
     1LED SURFACE, BUT IT IS NOT IMPOSSIBLE ANGLE SPECIFICATION - 4-AXIS
     2 CASE                                    THE PLANE IN WHICH TA IS
     3TO LIE IS TANGENT TO THE CONTROLLING SURFACE           '/
      DATA ERC38 /'NORMALIZATION FAILURE SETTING UP SPECIAL COORDINATE S
     |YSTEM                      NORMALIZATION FAILURE ON CANDIDATE TOOL
     2AXIS VECTOR                              ALPHA = 0  IN 4 AXIS CASE
     3 - MAY LEAD TO IMPOSSIBLE SPECIFICATION                '/
      DATA ERC39 /'SIGN CONVENTION ON ANGLE ALPHA BREAKS DOWN - WILL TRY
     1TO USE TI                  IMPOSSIBLE ANGLE SPECIFICATION 5-AXIS C
     2ASE                                      UNABLE TO NORMALIZE PSEUD
     2O PLANE 5-AXIS CASE                                    '/
      DATA ERC40 /'CUTTER RADIUS IS ZERO BUT TO OR PAST REQUIRED
     1                           DS AND/OR CS ARE NOT LINES OR CIRCLES
     2                                         NO POSSIBLE STOPPING POSI
     3TIONS FOUND                                            '/
      DATA ERC41 /'DS AND CS ARE BOTH LINES,BUT DO NOT INTERSECT
     1                           TANTO SPECIFIED FOR LINE-LINE CASE
     2                                         NO POSSIBLE TANTO POINT E
     3XISTS, BUT TANTO IS REQUIRED                           '/
      DATA ERC42 /'DS AND CS CIRCLES HAVE SAME CENTER
     1                           UNABLE TO NORMALIZE VECTOR BETWEEN CENT
     2ER OF DS AND CS CIRCLES                  ONLY ONE INTERSECTION FOU
     3ND WHEN THERE SHOULD BE TWO                            '/
      DATA ERC43 /'NONE OF THE POINTS FOUND MEETS THE REQUIREMENTS FOR T
     1HE FINAL OUTPUT POINT      PS PLANE IS TOO NEARLY VERTICAL
     2                                         AERR - FAILURE, NO. OF WA
     3RNING MESSAGES ALLOWED PER CUT SEQUENCE EXCEEDED       '/
      DATA ERC44 /'ASEC2 - ILLEGAL PROTAPE DATA SET FOR TLAXIS/. (ITEM 4
     1NOT 1.-5.).                ASEC2 - UNABLE TO NORMALIZE VECTOR GIVE
     2N IN TLAXIS/VECTOR                       ASEC2 - ILLEGAL ITEM 4 PA
     3RAMETER FOR NORMPS OR NORMDS.                          '/
      DATA ERC45 /'ASEC2 - ILLEGAL ITEM 4 PARAMETER FOR TLAXIS/ATANGL.
     1                           ASEC2 - ABS(ALPHA) GREATER THAN NINETY
     2DEGREES IN TLAXIS/ATANGL,N,ALPHA.        ASEC2 - ABS(GAM) GREATER
     3THAN 90 DEGREES IN TLAXIS/ATANGL,N,ALP,CUTANG,GAM.     '/
      DATA ERC46 /'ASEC2 - ILLEGAL NO. OF WORDS IN PROTAPE DATA SET FOR
     1TLAXIS/ATANGL,...          ASEC2 - UNABLE TO NORMALIZE SVECT IN TL
     2AXIS/ATANGL,N,ALPHA,SVECT                ATINKR - TI VECTOR DOES N
     3OT RESOLVE THE SIGN CONVENTION FAILURE ON ALPHA        '/
      DATA ERC47 /'PROCESSOR ERROR IN 2-D ROUTINE POINT SELECTION
     1                           ILLEGAL CUTTER--DIAMETER INCONSISTENT W
     2ITH CORNER RADIUS                        WARNING - CUTTER ON WRONG
     3SIDE OF DS OR DIRECTION IN ERROR                       '/
      DATA ERC48 /'EFFECTIVE RADIUS NEGATIVE IN POCKET INPUT
     1                           GIVEN POCKETING OFFSET IS NEGATIVE
     2                                         GIVEN POCKET FINISHING OF
     3FSET IS NEGATIVE                                       '/
      DATA ERC49 /'ONE OR MORE OF THE GIVEN POCKET FEEDRATES IS NEGATIVE
     1                           OVERRIDE INDICATOR NOT 0 OR 1 IN POCKET
     2                                         POINT TYPE INDICATOR NOT
     30 OR 1 IN POCKET                                       '/
      DATA ERC50 /'ERROR WHILE TESTING POCKET PARAMETERS
     1                           CUTTER WILL NOT FIT IN POCKET
     2                                         UNABLE TO SETUP PSUEDO DS
     3 FOR 2D STARTUP - TRY 3DCALC                           '/
      DATA ERC51 /'FINAL POINT FOUND IS NOT IN FWD DIRECTION
     1                           RESTART EXIT FROM CENTER IN APLANE
     2                                         WARNING    JTN CONVENTION
     3 VIOLATED                                              '/
      DATA ERC52 /'ATTEMPT TO CORRECT JTN VIOLATION FAILED
     1                           BAD CANONICAL FORM ON PROTAPE
     2                                         NORMAL DISTANCE CALCULATI
     3ON FAILURE                                             '/
      DATA ERC53 /'SURFACE USED AS THE BOTTOM OF POCKET IS NOT A PLANE
     1                           POSSIBLE LOOP
     2                                           WARNING. AUTOPS USED FO
     3R NON-VERTICAL TOOL WHEN TO OR PAST IN EFFECT FOR PS   '/
      DATA ERC54 /'CAUTION...CUTTER MAY BE GOUGING DS, WHICH WAS (TANTO)
     1 CS PREVIOUSLY.
     2
     3                                                       '/
      END

