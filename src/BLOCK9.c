/* BLOCK9.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */
/*
struct {
    doublereal b1[18], b2[18], b3[18], b4[18], b5[18], b6[18], b7[18], b8[18],
	     b9[18], b10[18];
} parm1_;
*/

struct {
    char b1[8*18], b2[8*18], b3[8*18], b4[8*18], b5[8*18], b6[8*18], b7[8*18], b8[8*18],
	     b9[8*18], b10[8*18];
} parm1_={
//b1:
"ATANGL  CENTER   CROSS  FUNOFY   INTOF  INVERS   LARGE    LEFT  \
LENGTH   MINUS    NEGX    NEGY    NEGZ     NOX     NOY   NOZ  PARLEL  PERPTO  ",

//b2:
"  PLUS    POSX    POSY    POSZ  RADIUS   RIGHT   SCALE   SMALL   TANTO\
   TIMES  TRANSL    UNIT  XLARGE  XSMALL  XYPLAN  XYROT   YLARGE  YSMALL  ",

//b3:
"YZPLAN   YZROT  ZLARGE  ZSMALL  ZXPLAN   ZXROT  3PT2SL  4PT1SL     5PT  \
INTERC   SLOPE      IN     OUT    OPEN     ALL  LAST    NOMORE    SAME  ",

//b4:
"MODIFY  MIRROR   START  ENDARC    CCLW     CLW  MEDIUM    HIGH     LOW   \
CONST    DECR    INCR   PERSP  ROTREF      TO  PAST      ON     OFF  ",

//b5:
"   IPM     IPR  CIRCUL  LINEAR   PARAB     RPM  MAXRPM    TURN    FACE    \
BORE    BOTH   XAXIS   YAXIS   ZAXIS  NORMDS  AUTO    FLOOD    MIST  ",

//b6:
"TAPKUL    STEP    RAIL    SIDE  LINCIR  MAXIPM     REV    TYPE   NIXIE   \
LIGHT  FOURPT   TWOPT  PTSLOP  PTNORM  SPLINERTHETA  THETAR     XYZ  ",

//b7:
" TANON  TRFORM  NORMAL      UP    DOWN    LOCK     SFM  XCOORD  YCOORD  \
ZCOORD  MULTRD  XYVIEW  YZVIEW  ZXVIEW   SOLID  DASH  DOTTED  CIRLIN  ",

//b8:
" DITTO     PEN  SCRIBE   BLACK     RED   GREEN    BLUE  INTENS    LITE     \
MED    DARK   CHUCK  COLLET   AAXIS   BAXIS CAXIS     TPI  OPTION  ",

//b9:
" RANGE   PSTAN    FULL   FRONT    REAR  SADDLE    MILL    THRU    DEEP    \
TRAV  SETOOL  SETANG  HOLDER  MANUAL  ADJUSTCUTANG     NOW    NEXT  ",

//b10:
" DRILL  BINARY     BCD    PART    REAM     TAP     CAM  ZIGZAG  RETAIN    \
OMIT   AVOID  RANDOM      AT  ANTSPI                  GAPLES  " 
};



#define parm1_1 parm1_
/*
struct {
    doublereal a1[22];
} posta1_;
*/
struct {
    char a1[8*22];
} posta1_={
"END     STOP    OPSTOP  ISTOP   RAPID   SWITCH  RETRCT  DRESS   \
PICKUP  UNLOAD  PENUP   PENDWN  ZERO    GOHOME  RESET   GOCLER  DRAWLI  \
PROBY   PROBX   ULOCKX  LOCKX   FACEML  "
};


#define posta1_1 posta1_
/*
struct {
    doublereal c1[18], c2[18], c3[18], c4[18];
} postp1_;
*/

struct {
    char c1[8*18], c2[8*18], c3[8*18], c4[8*18];
} postp1_={
"PLUNGE  HEAD    MODE    CLEARP  TMARK   REWIND  CUTCOM  REVERS  \
FEDRAT  DELAY   AIR     DELETE  LEADER  PPLOT   MACHINMCHTOL  PIVOTZ  MCHFIN  ",

"SEQNO   INTCOD  DISPLY  AUXFUN  CHECK   POSTN   TOOLNO  ROTABL  ORIGIN\
  SAFETY  ARCSLP  COOLNT  SPINDL  IFRO    TURRET        ROTHED  THREAD  ",

"TRANS   TRACUT  INDEX   COPY    PLOT    OVPLOT  LETTER  \
PPRINT  PARTNO  INSERT  CAMERA  PREFUN  COUPLE  PITCH   MDWRITMDEND   ASLOPE    CYCLE   ",

"LOADTL  SELCTL  CLRSRF  DWELL   DRAFT   CLAMP   PLABEL  MAXDPM  SLOWDN  MAXVEL  \
LPRINT  MOVETO  CORNFD  PBS       REGBRKVTLAXS  WCORN   MAGTAP  "
};


#define postp1_1 postp1_

/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 *** */
/*      DATA A1   /'END     STOP    OPSTOP  ISTOP   RAPID   SWITCH  RETRCT */
/*     1  DRESS   PICKUP  UNLOAD  PENUP   PENDWN  ZERO    GOHOME  RESET */
/*     2GOCLER  DRAWLI  PROBY   PROBX   ULOCKX  LOCKX   FACEML  '/ */


/*      DATA B1   /'ATANGL  CENTER   CROSS  FUNOFY   INTOF  INVERS   LARGE */
/*     1    LEFT  LENGTH   MINUS    NEGX    NEGY    NEGZ     NOX     NOY */
/*     2   NOZ  PARLEL  PERPTO  '/ */
/*      DATA B2   /'  PLUS    POSX    POSY    POSZ  RADIUS   RIGHT   SCALE */
/*     1   SMALL   TANTO   TIMES  TRANSL    UNIT  XLARGE  XSMALL  XYPLAN */
/*     2 XYROT  YLARGE  YSMALL  '/ */
/*      DATA B3   /'YZPLAN   YZROT  ZLARGE  ZSMALL  ZXPLAN   ZXROT  3PT2SL */
/*     1  4PT1SL     5PT  INTERC   SLOPE      IN     OUT    OPEN     ALL */
/*     2  LAST  NOMORE    SAME  '/ */
/*      DATA B4   /'MODIFY  MIRROR   START  ENDARC    CCLW     CLW  MEDIUM */
/*     1    HIGH     LOW   CONST    DECR    INCR   PERSP  ROTREF      TO */
/*     2  PAST      ON     OFF  '/ */
/*      DATA B5   /'   IPM     IPR  CIRCUL  LINEAR   PARAB     RPM  MAXRPM */
/*     1    TURN    FACE    BORE    BOTH   XAXIS   YAXIS   ZAXIS  NORMDS */
/*     2  AUTO   FLOOD    MIST  '/ */
/*      DATA B6   /'TAPKUL    STEP    RAIL    SIDE  LINCIR  MAXIPM     REV */
/*     1    TYPE   NIXIE   LIGHT  FOURPT   TWOPT  PTSLOP  PTNORM  SPLINE */
/*     2RTHETA  THETAR     XYZ  '/ */
/*      DATA B7   /' TANON  TRFORM  NORMAL      UP    DOWN    LOCK     SFM */
/*     1  XCOORD  YCOORD  ZCOORD  MULTRD  XYVIEW  YZVIEW  ZXVIEW   SOLID */
/*     2  DASH  DOTTED  CIRLIN  '/ */
/*      DATA B8   /' DITTO     PEN  SCRIBE   BLACK     RED   GREEN    BLUE */
/*     1  INTENS    LITE     MED    DARK   CHUCK  COLLET   AAXIS   BAXIS */
/*     2 CAXIS     TPI  OPTION  '/ */
/*      DATA B9   /' RANGE   PSTAN    FULL   FRONT    REAR  SADDLE    MILL */
/*     1    THRU    DEEP    TRAV  SETOOL  SETANG  HOLDER  MANUAL  ADJUST */
/*     2CUTANG     NOW    NEXT  '/ */
/*      DATA B10   /' DRILL  BINARY     BCD    PART    REAM     TAP     CA */
/*     1M  ZIGZAG  RETAIN    OMIT   AVOID  RANDOM      AT  ANTSPI */
/*     2                 GAPLES  '/ */
/*      DATA C1   /'PLUNGE  HEAD    MODE    CLEARP  TMARK   REWIND  CUTCOM */
/*     1  REVERS  FEDRAT  DELAY   AIR     DELETE  LEADER  PPLOT   MACHIN */
/*     2MCHTOL  PIVOTZ  MCHFIN  '/ */
/*      DATA C2   /'SEQNO   INTCOD  DISPLY  AUXFUN  CHECK   POSTN   TOOLNO */
/*     1  ROTABL  ORIGIN  SAFETY  ARCSLP  COOLNT  SPINDL  IFRO    TURRET */
/*     2        ROTHED  THREAD  '/ */

/*      DATA C3   /'TRANS   TRACUT  INDEX   COPY    PLOT    OVPLOT  LETTER */
/*     1  PPRINT  PARTNO  INSERT  CAMERA  PREFUN  COUPLE  PITCH   MDWRIT */
/*     2MDEND   ASLOPE  CYCLE   '/ */


/*      DATA C4   /'LOADTL  SELCTL  CLRSRF  DWELL   DRAFT   CLAMP   PLABEL */
/*     1  MAXDPM  SLOWDN  MAXVEL  LPRINT  MOVETO  CORNFD  PBS     REGBRK */
/*     2VTLAXS  WCORN   MAGTAP  '/ */

