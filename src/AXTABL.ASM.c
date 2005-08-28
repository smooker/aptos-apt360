/*
* ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
*      XTABL - VOCABULARY TABLE
         PRINT ON,DATA
AXTABL   CSECT
XTAB1    DC    CL8'TITLES  '
         DC    H'1,1'
         DC    Y(XTAB2-XTAB1,LAST-XTAB1)
         DC    CL8'REMARK  '
         DC    H'1,2,0,0'
         DC    CL8'PPRINT  '
         DC    H'1,3,1044,2000'
         DC    CL8'PARTNO  '
         DC    H'1,4,1045,2000'
         DC    CL8'INSERT  '
         DC    H'1,5,1046,2000'
XTAB2    DC    CL8'    AT  '
         DC    H'29,175,0,175'
         DC    CL8'    GO  '
         DC    H'26,7,1,7000'
         DC    CL8'    IF  '
         DC    H'9,1,0,0'
         DC    CL8'    IN  '
         DC    H'29,48,0,48'
         DC    CL8'    ON  '
         DC    H'29,71,0,71'
         DC    CL8'    TO  '
         DC    H'29,69,0,69'
         DC    CL8'    UP  '
         DC    H'29,112,0,112'
         DC    CL8'   AIR  '
         DC    H'22,11,1011,2000'
         DC    CL8'   ALL  '
         DC    H'29,51,0,51'
         DC    CL8'   ARC  '
         DC    H'29,87,0,87'
         DC    CL8'   BCD  '
         DC    H'29,165,0,165'
         DC    CL8'   CAM  '
         DC    H'29,169,0,169'
         DC    CL8'   CLW  '
         DC    H'29,60,0,60'
         DC    CL8'   CUT  '
         DC    H'3,1,1,6000'
         DC    CL8'   DAC  '
         DC    H'25,6,0,0'
         DC    CL8'   END  '
         DC    H'23,1,1,2000'
         DC    CL8'   FAN  '
         DC    H'29,184,0,184'
         DC    CL8'   IPM  '
         DC    H'29,73,0,73'
         DC    CL8'   IPR  '
         DC    H'29,74,0,74'
         DC    CL8'   LOW  '
         DC    H'29,63,0,63'
         DC    CL8'   LTV  '
         DC    H'33,2,0,0'
         DC    CL8'   MED  '
         DC    H'29,136,0,136'
         DC    CL8'   MIT  '
         DC    H'33,3,0,0'
         DC    CL8'   NOW  '
         DC    H'29,161,0,161'
         DC    CL8'   NOX  '
         DC    H'29,14,0,14'
         DC    CL8'   NOY  '
         DC    H'29,15,0,15'
         DC    CL8'   NOZ  '
         DC    H'29,16,0,16'
         DC    CL8'   OFF  '
         DC    H'29,72,0,72'
         DC    CL8'   OUT  '
         DC    H'29,49,0,49'
         DC    CL8'   PBS  '
         DC    H'22,60,1068,2000'
         DC    CL8'   PEN  '
         DC    H'29,128,0,128'
         DC    CL8'   RED  '
         DC    H'29,131,0,131'
         DC    CL8'   REV  '
         DC    H'29,97,0,97'
         DC    CL8'   RPM  '
         DC    H'29,78,0,78'
         DC    CL8'   SFM  '
         DC    H'29,115,0,115'
         DC    CL8'   SYN  '
         DC    H'17,1,0,0'
         DC    CL8'   TAP  '
         DC    H'29,168,0,168'
         DC    CL8'   TPI  '
         DC    H'29,143,0,143'
         DC    CL8'   XYZ  '
         DC    H'29,108,0,108'
         DC    CL8'   5PT  '
         DC    H'29,45,0,45'
         DC    CL8'  ABSF  '
         DC    H'19,9,9,8'
         DC    CL8'  AUTO  '
         DC    H'29,88,0,88'
         DC    CL8'  BLUE  '
         DC    H'29,133,0,133'
         DC    CL8'  BORE  '
         DC    H'29,82,0,82'
         DC    CL8'  BOTH  '
         DC    H'29,83,0,83'
         DC    CL8'  CALL  '
         DC    H'7,1,0,0'
         DC    CL8'  CCLW  '
         DC    H'29,59,0,59'
         DC    CL8'  CLTV  '
         DC    H'25,5,0,0'
         DC    CL8'  CMIT  '
         DC    H'33,4,0,0'
         DC    CL8'  CONE  '
         DC    H'24,8,10,8'
         DC    CL8'  COPY  '
         DC    H'21,3,1040,2000'
         DC    CL8'  COSF  '
         DC    H'19,5,5,8'
         DC    CL8'  DARK  '
         DC    H'29,137,0,137'
         DC    CL8'  DASH  '
         DC    H'29,124,0,124'
         DC    CL8'  DECR  '
         DC    H'29,65,0,65'
         DC    CL8'  DEEP  '
         DC    H'29,153,0,153'
         DC    CL8'  DOTF  '
         DC    H'19,1,1,8'
         DC    CL8'  DOWN  '
         DC    H'29,113,0,113'
         DC    CL8'  EXPF  '
         DC    H'19,6,6,8'
         DC    CL8'  FACE  '
         DC    H'29,81,0,81'
         DC    CL8'  FINI  '
         DC    H'18,1,0,14000'
         DC    CL8'  FROM  '
         DC    H'26,11,3,5000'
         DC    CL8'  FULL  '
         DC    H'29,147,0,147'
         DC    CL8'  GOTO  '
         DC    H'26,13,5,5000'
         DC    CL8'  GOUP  '
         DC    H'26,5,5,8000'
         DC    CL8'  GRID  '
         DC    H'29,176,0,176'
         DC    CL8'  HEAD  '
         DC    H'22,2,1002,2000'
         DC    CL8'  HIGH  '
         DC    H'29,62,0,62'
         DC    CL8'  IFRO  '
         DC    H'22,31,1032,2000'
         DC    CL8'  INCR  '
         DC    H'29,66,0,66'
         DC    CL8'  LAST  '
         DC    H'29,52,0,52'
         DC    CL8'  LEFT  '
         DC    H'29,8,0,8'
         DC    CL8'  LINE  '
         DC    H'24,2,7,2'
         DC    CL8'  LITE  '
         DC    H'29,135,0,135'
         DC    CL8'  LOCK  '
         DC    H'29,114,0,114'
         DC    CL8'  LOFT  '
         DC    H'24,16,11,16'
         DC    CL8'  LOGF  '
         DC    H'19,7,7,8'
         DC    CL8'  MAIN  '
         DC    H'29,93,0,93'
         DC    CL8'  MESH  '
         DC    H'24,19,0,51'
         DC    CL8'  MILL  '
         DC    H'29,151,0,151'
         DC    CL8'  MIST  '
         DC    H'29,90,0,90'
         DC    CL8'  MODE  '
         DC    H'22,3,1003,2000'
         DC    CL8'  NEGX  '
         DC    H'29,11,0,11'
         DC    CL8'  NEGY  '
         DC    H'29,12,0,12'
         DC    CL8'  NEGZ  '
         DC    H'29,13,0,13'
         DC    CL8'  NEXT  '
         DC    H'29,162,0,162'
         DC    CL8'  NOPS  '
         DC    H'3,7,6,9000'
         DC    CL8'  NUMF  '
         DC    H'19,11,11,8'
         DC    CL8'  OMIT  '
         DC    H'29,172,0,172'
         DC    CL8'  OPEN  '
         DC    H'29,50,0,50'
         DC    CL8'  PART  '
         DC    H'29,166,0,166'
         DC    CL8'  PAST  '
         DC    H'29,70,0,70'
         DC    CL8'  PLOT  '
         DC    H'22,39,1041,2000'
         DC    CL8'  PLUS  '
         DC    H'29,19,0,19'
         DC    CL8'  POSX  '
         DC    H'29,20,0,20'
         DC    CL8'  POSY  '
         DC    H'29,21,0,21'
         DC    CL8'  POSZ  '
         DC    H'29,22,0,22'
         DC    CL8'  PSIS  '
         DC    H'13,1,4,3000'
         DC    CL8'  RAIL  '
         DC    H'29,93,0,93'
         DC    CL8'  READ  '
         DC    H'4,1,0,0'
         DC    CL8'  REAM  '
         DC    H'29,167,0,167'
         DC    CL8'  REAR  '
         DC    H'29,149,0,149'
         DC    CL8'  SAME  '
         DC    H'29,54,0,54'
         DC    CL8'  SEC1  '
         DC    H'31,1,0,0'
         DC    CL8'  SEC2  '
         DC    H'31,2,0,0'
         DC    CL8'  SIDE  '
         DC    H'29,94,0,94'
         DC    CL8'  SINF  '
         DC    H'19,4,4,8'
         DC    CL8'  STEP  '
         DC    H'29,92,0,92'
         DC    CL8'  STOP  '
         DC    H'23,2,2,2000'
         DC    CL8'  TANF  '
         DC    H'19,13,13,8'
         DC    CL8'  THRU  '
         DC    H'29,152,0,152'
         DC    CL8'  TLON  '
         DC    H'27,3,3,4000'
         DC    CL8'  TOOL  '
         DC    H'24,17,3,17'
         DC    CL8'  TRAV  '
         DC    H'29,154,0,154'
         DC    CL8'  TURN  '
         DC    H'29,80,0,80'
         DC    CL8'  TYPE  '
         DC    H'29,98,0,98'
         DC    CL8'  UNIT  '
         DC    H'29,30,0,30'
         DC    CL8'  ZERO  '
         DC    H'23,13,13,2000'
         DC    CL8' AAXIS  '
         DC    H'29,140,0,140'
         DC    CL8' ANGLF  '
         DC    H'19,10,10,8'
         DC    CL8' ATANF  '
         DC    H'19,8,8,8'
         DC    CL8' AVOID  '
         DC    H'29,173,0,173'
         DC    CL8' BAXIS  '
         DC    H'29,141,0,141'
         DC    CL8' BLACK  '
         DC    H'29,130,0,130'
         DC    CL8' CANON  '
         DC    H'28,1,0,3099'
         DC    CL8' CAXIS  '
         DC    H'29,142,0,142'
         DC    CL8' CHECK  '
         DC    H'22,22,1023,2000'
         DC    CL8' CHUCK  '
         DC    H'29,138,0,138'
         DC    CL8' CLAMP  '
         DC    H'22,52,1060,2000'
         DC    CL8' CONST  '
         DC    H'29,64,0,64'
         DC    CL8' CROSS  '
         DC    H'29,3,0,3'
         DC    CL8' CYCLE  '
         DC    H'22,46,1054,2000'
         DC    CL8' DEBUG  '
         DC    H'15,1,0,0'
         DC    CL8' DELAY  '
         DC    H'22,10,1010,2000'
         DC    CL8' DISTF  '
         DC    H'19,15,15,8'
         DC    CL8' DITTO  '
         DC    H'29,127,0,127'
         DC    CL8' DMILL  '
         DC    H'3,10,11,6000'
         DC    CL8' DRAFT  '
         DC    H'22,51,1059,2000'
         DC    CL8' DRESS  '
         DC    H'23,8,8,2000'
         DC    CL8' DRILL  '
         DC    H'29,163,0,163'
         DC    CL8' DSTAN  '
         DC    H'29,27,0,27'
         DC    CL8' DWELL  '
         DC    H'22,50,1058,2000'
         DC    CL8' FLOOD  '
         DC    H'29,89,0,89'
         DC    CL8' FRONT  '
         DC    H'29,148,0,148'
         DC    CL8' GOFWD  '
         DC    H'26,3,3,8000'
         DC    CL8' GOLFT  '
         DC    H'26,1,1,8000'
         DC    CL8' GORGT  '
         DC    H'26,2,2,8000'
         DC    CL8' GREEN  '
         DC    H'29,132,0,132'
         DC    CL8' INDEX  '
         DC    H'21,2,1039,2000'
         DC    CL8' INTOF  '
         DC    H'29,5,0,5'
         DC    CL8' INTOL  '
         DC    H'2,4,4,6000'
         DC    CL8' ISTOP  '
         DC    H'23,4,4,2000'
         DC    CL8' LARGE  '
         DC    H'29,7,0,7'
         DC    CL8' LIBRY  '
         DC    H'35,1,0,0'
         DC    CL8' LIGHT  '
         DC    H'29,100,0,100'
         DC    CL8' LNTHF  '
         DC    H'19,2,2,8'
         DC    CL8' LOCKX  '
         DC    H'23,21,21,2000'
         DC    CL8' MACRO  '
         DC    H'14,1,0,0'
         DC    CL8' MAXDP  '
         DC    H'2,3,3,9000'
         DC    CL8' MDEND  '
         DC    H'22,44,1052,2000'
         DC    CL8' MINUS  '
         DC    H'29,10,0,10'
         DC    CL8' NIXIE  '
         DC    H'29,99,0,99'
         DC    CL8' PARAB  '
         DC    H'29,77,0,77'
         DC    CL8' PENUP  '
         DC    H'23,11,11,2000'
         DC    CL8' PERSP  '
         DC    H'29,67,0,67'
         DC    CL8' PITCH  '
         DC    H'22,64,1050,2000'
         DC    CL8' PLANE  '
         DC    H'24,3,7,3'
         DC    CL8' POINT  '
         DC    H'24,1,6,1'
         DC    CL8' POSTN  '
         DC    H'22,23,1024,2000'
         DC    CL8' PPLOT  '
         DC    H'22,14,1014,2000'
         DC    CL8' PRINT  '
         DC    H'4,3,3,0'
         DC    CL8' PROBX  '
         DC    H'23,19,19,2000'
         DC    CL8' PROBY  '
         DC    H'23,18,18,2000'
         DC    CL8' PSTAN  '
         DC    H'29,146,0,146'
         DC    CL8' PUNCH  '
         DC    H'4,2,0,0'
         DC    CL8' RANGE  '
         DC    H'29,145,0,145'
         DC    CL8' RAPID  '
         DC    H'23,5,5,2000'
         DC    CL8' RESET  '
         DC    H'23,15,15,2000'
         DC    CL8' RIGHT  '
         DC    H'29,24,0,24'
         DC    CL8' SCALE  '
         DC    H'29,25,0,25'
         DC    CL8' SEQNO  '
         DC    H'22,18,1019,2000'
         DC    CL8' SLOPE  '
         DC    H'29,47,0,47'
         DC    CL8' SMALL  '
         DC    H'29,26,0,26'
         DC    CL8' SOLID  '
         DC    H'29,123,0,123'
         DC    CL8' SQRTF  '
         DC    H'19,3,3,8'
         DC    CL8' START  '
         DC    H'29,57,0,57'
         DC    CL8' TANDS  '
         DC    H'29,183,0,183'
         DC    CL8' TANON  '
         DC    H'29,109,0,109'
         DC    CL8' TANTO  '
         DC    H'29,27,0,27'
         DC    CL8' THICK  '
         DC    H'2,5,5,9000'
         DC    CL8' TIMES  '
         DC    H'29,28,0,28'
         DC    CL8' TLLFT  '
         DC    H'27,1,1,4000'
         DC    CL8' TLRGT  '
         DC    H'27,2,2,4000'
         DC    CL8' TMARK  '
         DC    H'22,5,1005,2000'
         DC    CL8' TOLER  '
         DC    H'2,2,2,6000'
         DC    CL8' TRANS  '
         DC    H'22,35,1037,2000'
         DC    CL8' TWOPT  '
         DC    H'29,102,0,102'
         DC    CL8' WCORN  '
         DC    H'22,63,1071,2000'
         DC    CL8' XAXIS  '
         DC    H'29,84,0,84'
         DC    CL8' XYROT  '
         DC    H'29,34,0,34'
         DC    CL8' YAXIS  '
         DC    H'29,85,0,85'
         DC    CL8' YZROT  '
         DC    H'29,38,0,38'
         DC    CL8' ZAXIS  '
         DC    H'29,86,0,86'
         DC    CL8' ZSURF  '
         DC    H'6,1,0,0'
         DC    CL8' ZXROT  '
         DC    H'29,42,0,42'
         DC    CL8'ADJUST  '
         DC    H'29,159,0,159'
         DC    CL8'ANTSPI  '
         DC    H'29,176,0,176'
         DC    CL8'ARCSLP  '
         DC    H'22,28,1029,2000'
         DC    CL8'ASLOPE  '
         DC    H'22,45,1053,2000'
         DC    CL8'ATANGL  '
         DC    H'29,1,0,1'
         DC    CL8'ATAN2F  '
         DC    H'19,14,14,8'
         DC    CL8'AUTOPS  '
         DC    H'3,5,7,9000'
         DC    CL8'AUXFUN  '
         DC    H'22,21,1022,2000'
         DC    CL8'BEVELS  '
         DC    H'3,10,2,6000'
         DC    CL8'BINARY  '
         DC    H'29,164,0,164'
         DC    CL8'CAMERA  '
         DC    H'22,36,1047,2000'
         DC    CL8'CENTER  '
         DC    H'29,2,0,2'
         DC    CL8'CIRCLE  '
         DC    H'24,4,10,4'
         DC    CL8'CIRCUL  '
         DC    H'29,75,0,75'
         DC    CL8'CIRLIN  '
         DC    H'29,126,0,126'
         DC    CL8'CLEARP  '
         DC    H'22,4,1004,2000'
         DC    CL8'CLPRNT  '
         DC    H'25,1,0,0'
         DC    CL8'CLRSRF  '
         DC    H'22,49,1057,2000'
         DC    CL8'COLLET  '
         DC    H'29,139,0,139'
         DC    CL8'CONSEC  '
         DC    H'24,20,0,52'
         DC    CL8'COOLNT  '
         DC    H'22,29,1030,2000'
         DC    CL8'CORNFD  '
         DC    H'22,59,1067,2000'
         DC    CL8'COUPLE  '
         DC    H'22,38,1049,2000'
         DC    CL8'CUTANG  '
         DC    H'29,160,0,160'
         DC    CL8'CUTCOM  '
         DC    H'22,7,1007,2000'
         DC    CL8'CUTTER  '
         DC    H'2,6,6,6000'
         DC    CL8'CYLNDR  '
         DC    H'24,5,10,5'
         DC    CL8'DELETE  '
         DC    H'22,12,1012,2000'
         DC    CL8'DISPLY  '
         DC    H'22,20,1021,2000'
         DC    CL8'DNTCUT  '
         DC    H'3,2,1,6000'
         DC    CL8'DOTTED  '
         DC    H'29,125,0,125'
         DC    CL8'DRAWLI  '
         DC    H'23,17,17,2000'
         DC    CL8'DYNDMP  '
         DC    H'15,2,9,6000'
         DC    CL8'ELLIPS  '
         DC    H'24,6,13,6'
         DC    CL8'ELMSRF  '
         DC    H'24,22,0,54'
         DC    CL8'ENDARC  '
         DC    H'29,58,0,58'
         DC    CL8'FACEML  '
         DC    H'23,22,22,2000'
         DC    CL8'FEDRAT  '
         DC    H'22,9,1009,2000'
         DC    CL8'FOURPT  '
         DC    H'29,101,0,101'
         DC    CL8'FUNOFY  '
         DC    H'29,4,0,4'
         DC    CL8'GAPLES  '
         DC    H'29,180,0,180'
         DC    CL8'GCONIC  '
         DC    H'24,9,13,9'
         DC    CL8'GOBACK  '
         DC    H'26,4,4,8000'
         DC    CL8'GOCLER  '
         DC    H'23,16,16,2000'
         DC    CL8'GODLTA  '
         DC    H'26,12,4,5000'
         DC    CL8'GODOWN  '
         DC    H'26,6,6,8000'
         DC    CL8'GOHOME  '
         DC    H'23,14,14,2000'
         DC    CL8'GOUGCK  '
         DC    H'3,4,8,9000'
         DC    CL8'HOLDER  '
         DC    H'29,157,0,157'
         DC    CL8'HYPERB  '
         DC    H'24,7,13,7'
         DC    CL8'INDIRP  '
         DC    H'26,9,1,5000'
         DC    CL8'INDIRV  '
         DC    H'26,10,2,5000'
         DC    CL8'INSERT  '
         DC    H'1,5,1046,2000'
         DC    CL8'INTCOD  '
         DC    H'22,19,1020,2000'
         DC    CL8'INTENS  '
         DC    H'29,134,0,134'
         DC    CL8'INTERC  '
         DC    H'29,46,0,46'
         DC    CL8'INVERS  '
         DC    H'29,6,0,6'
         DC    CL8'JUMPTO  '
         DC    H'10,1,0,0'
         DC    CL8'LCONIC  '
         DC    H'24,10,13,10'
         DC    CL8'LEADER  '
         DC    H'22,13,1013,2000'
         DC    CL8'LENGTH  '
         DC    H'29,9,0,9'
         DC    CL8'LETTER  '
         DC    H'22,41,1043,2000'
         DC    CL8'LINCIR  '
         DC    H'29,95,0,95'
         DC    CL8'LINEAR  '
         DC    H'29,76,0,76'
         DC    CL8'LOADTL  '
         DC    H'22,47,1055,2000'
         DC    CL8'LOG10F  '
         DC    H'19,12,12,8'
         DC    CL8'LOOPND  '
         DC    H'11,2,0,0'
         DC    CL8'LOOPST  '
         DC    H'11,1,0,0'
         DC    CL8'LPRINT  '
         DC    H'22,57,1065,2000'
         DC    CL8'MACHIN  '
         DC    H'21,4,1015,2000'
         DC    CL8'MAGTAP  '
         DC    H'22,64,1072,2000'
         DC    CL8'MANUAL  '
         DC    H'29,158,0,158'
         DC    CL8'MATRIX  '
         DC    H'24,12,15,12'
         DC    CL8'MAXDPM  '
         DC    H'22,54,1062,2000'
         DC    CL8'MAXIPM  '
         DC    H'29,96,0,96'
         DC    CL8'MAXRPM  '
         DC    H'29,79,0,79'
         DC    CL8'MAXVEL  '
         DC    H'22,56,1064,2000'
         DC    CL8'MCHFIN  '
         DC    H'22,17,1018,2000'
         DC    CL8'MCHTOL  '
         DC    H'22,15,1016,2000'
         DC    CL8'MDWRIT  '
         DC    H'22,43,1051,2000'
         DC    CL8'MEDIUM  '
         DC    H'29,61,0,61'
         DC    CL8'MIRROR  '
         DC    H'29,56,0,56'
         DC    CL8'MODIFY  '
         DC    H'29,55,0,55'
         DC    CL8'MOVETO  '
         DC    H'22,58,1066,2000'
         DC    CL8'MULTAX  '
         DC    H'3,3,2,9000'
         DC    CL8'MULTRD  '
         DC    H'29,119,0,119'
         DC    CL8'NDTEST  '
         DC    H'3,6,2,6000'
         DC    CL8'NOMORE  '
         DC    H'29,53,0,53'
         DC    CL8'NOPLOT  '
         DC    H'25,2,0,0'
         DC    CL8'NOPOST  '
         DC    H'25,3,0,0'
         DC    CL8'NORMAL  '
         DC    H'29,111,0,111'
         DC    CL8'NORMDS  '
         DC    H'29,182,0,87'
         DC    CL8'NORMPS  '
         DC    H'29,181,32767,4000'
         DC    CL8'NUMPTS  '
         DC    H'2,7,4,9000'
         DC    CL8'OBTAIN  '
         DC    H'5,1,0,0'
         DC    CL8'OFFSET  '
         DC    H'26,8,2,7000'
         DC    CL8'OPSKIP  '
         DC    H'22,42,1012,2000'
         DC    CL8'OPSTOP  '
         DC    H'23,3,3,2000'
         DC    CL8'OPTION  '
         DC    H'29,144,0,144'
         DC    CL8'ORIGIN  '
         DC    H'22,26,1027,2000'
         DC    CL8'OUTTOL  '
         DC    H'2,8,5,6000'
         DC    CL8'OVPLOT  '
         DC    H'22,40,1042,2000'
         DC    CL8'PARLEL  '
         DC    H'29,17,0,17'
         DC    CL8'PATERN  '
         DC    H'24,22,0,18'
         DC    CL8'PENDWN  '
         DC    H'23,12,12,2000'
         DC    CL8'PERPTO  '
         DC    H'29,18,0,18'
         DC    CL8'PICKUP  '
         DC    H'23,9,9,2000'
         DC    CL8'PIVOTZ  '
         DC    H'22,16,1017,2000'
         DC    CL8'PLABEL  '
         DC    H'22,53,1061,2000'
         DC    CL8'PLUNGE  '
         DC    H'22,1,1001,2000'
         DC    CL8'POCKET  '
         DC    H'12,1,1,11000'
         DC    CL8'POLCON  '
         DC    H'24,15,82,15'
         DC    CL8'PREFUN  '
         DC    H'22,37,1048,2000'
         DC    CL8'PTNORM  '
         DC    H'29,104,0,104'
         DC    CL8'PTONLY  '
         DC    H'25,4,0,0'
         DC    CL8'PTSLOP  '
         DC    H'29,103,0,103'
         DC    CL8'QADRIC  '
         DC    H'24,14,13,14'
         DC    CL8'RADIUS  '
         DC    H'29,23,0,23'
         DC    CL8'RANDOM  '
         DC    H'29,174,0,174'
         DC    CL8'REFSYS  '
         DC    H'8,1,0,0'
         DC    CL8'REGBRK  '
         DC    H'22,61,1069,2000'
         DC    CL8'RESERV  '
         DC    H'16,1,0,0'
         DC    CL8'RETAIN  '
         DC    H'29,171,0,171'
         DC    CL8'RETRCT  '
         DC    H'23,7,7,2000'
         DC    CL8'REVERS  '
         DC    H'22,8,1008,2000'
         DC    CL8'REWIND  '
         DC    H'22,6,1006,2000'
         DC    CL8'RLDSRF  '
         DC    H'24,21,0,53'
         DC    CL8'ROTABL  '
         DC    H'22,25,1026,2000'
         DC    CL8'ROTHED  '
         DC    H'22,33,1035,2000'
         DC    CL8'ROTREF  '
         DC    H'29,68,0,68'
         DC    CL8'RTHETA  '
         DC    H'29,106,0,106'
         DC    CL8'SADDLE  '
         DC    H'29,150,0,150'
         DC    CL8'SAFETY  '
         DC    H'22,27,1028,2000'
         DC    CL8'SCRIBE  '
         DC    H'29,129,0,129'
         DC    CL8'SELCTL  '
         DC    H'22,48,1056,2000'
         DC    CL8'SETANG  '
         DC    H'29,156,0,156'
         DC    CL8'SETOOL  '
         DC    H'29,155,0,155'
         DC    CL8'SLOWDN  '
         DC    H'22,55,1063,2000'
         DC    CL8'SPHERE  '
         DC    H'24,13,7,13'
         DC    CL8'SPINDL  '
         DC    H'22,30,1031,2000'
         DC    CL8'SPLINE  '
         DC    H'29,105,0,105'
         DC    CL8'SRFVCT  '
         DC    H'26,14,8,5000'
         DC    CL8'SWITCH  '
         DC    H'23,6,6,2000'
         DC    CL8'TABCYL  '
         DC    H'24,18,0,50'
         DC    CL8'TANCRV  '
         DC    H'33,5,0,0'
         DC    CL8'TAPKUL  '
         DC    H'29,91,0,91'
         DC    CL8'TERMAC  '
         DC    H'14,2,0,0'
         DC    CL8'THETAR  '
         DC    H'29,107,0,107'
         DC    CL8'THREAD  '
         DC    H'22,34,1036,2000'
         DC    CL8'TLAXIS  '
         DC    H'2,1,1,9000'
         DC    CL8'TLNDON  '
         DC    H'27,7,3,4000'
         DC    CL8'TLOFPS  '
         DC    H'27,6,6,4000'
         DC    CL8'TLONPS  '
         DC    H'27,5,5,4000'
         DC    CL8'TOOLNO  '
         DC    H'22,24,1025,2000'
         DC    CL8'TRACUT  '
         DC    H'21,1,1038,2000'
         DC    CL8'TRANSL  '
         DC    H'29,29,0,29'
         DC    CL8'TRANTO  '
         DC    H'20,1,7,6000'
         DC    CL8'TRFORM  '
         DC    H'29,110,0,110'
         DC    CL8'TUNEUP  '
         DC    H'34,1,0,0'
         DC    CL8'TURRET  '
         DC    H'22,32,1033,2000'
         DC    CL8'ULOCKX  '
         DC    H'23,20,20,2000'
         DC    CL8'UNLOAD  '
         DC    H'23,10,10,2000'
         DC    CL8'VECTOR  '
         DC    H'24,11,6,11'
         DC    CL8'VTLAXS  '
         DC    H'22,62,1070,2000'
         DC    CL8'XCOORD  '
         DC    H'29,116,0,116'
         DC    CL8'XLARGE  '
         DC    H'29,31,0,31'
         DC    CL8'XSMALL  '
         DC    H'29,32,0,32'
         DC    CL8'XYPLAN  '
         DC    H'29,33,0,33'
         DC    CL8'XYVIEW  '
         DC    H'29,120,0,120'
         DC    CL8'YCOORD  '
         DC    H'29,117,0,117'
         DC    CL8'YLARGE  '
         DC    H'29,35,0,35'
         DC    CL8'YSMALL  '
         DC    H'29,36,0,36'
         DC    CL8'YZPLAN  '
         DC    H'29,37,0,37'
         DC    CL8'YZVIEW  '
         DC    H'29,121,0,121'
         DC    CL8'ZCOORD  '
         DC    H'29,118,0,118'
         DC    CL8'ZIGZAG  '
         DC    H'29,170,0,170'
         DC    CL8'ZLARGE  '
         DC    H'29,39,0,39'
         DC    CL8'ZSMALL  '
         DC    H'29,40,0,40'
         DC    CL8'ZXPLAN  '
         DC    H'29,41,0,41'
         DC    CL8'ZXVIEW  '
         DC    H'29,122,0,122'
         DC    CL8'2DCALC  '
         DC    H'3,8,2,6000'
         DC    CL8'3DCALC  '
         DC    H'3,9,2,6000'
         DC    CL8'3PT2SL  '
         DC    H'29,43,0,43'
         DC    CL8'4PT1SL  '
         DC    H'29,44,0,44'
LAST     EQU   *
         END
*/
//first number: class
//second: 	sub-class
//third;	protap subclass
//last:		protap class
#include "AXTABL.ASM.h"

struct Keyword keyarray[]={
 {"TITLES  ",{1,1,0,0}}
,{"REMARK  ",{1,2,0,0}}
,{"PPRINT  ",{1,3,1044,2000}}
,{"PARTNO  ",{1,4,1045,2000}}
,{"INSERT  ",{1,5,1046,2000}}
,{"    AT  ",{29,175,0,175}}
,{"    GO  ",{26,7,1,7000}}
,{"    IF  ",{9,1,0,0}}
,{"    IN  ",{29,48,0,48}}
,{"    ON  ",{29,71,0,71}}
,{"    TO  ",{29,69,0,69}}
,{"    UP  ",{29,112,0,112}}
,{"   AIR  ",{22,11,1011,2000}}
,{"   ALL  ",{29,51,0,51}}
,{"   ARC  ",{29,87,0,87}}
,{"   BCD  ",{29,165,0,165}}
,{"   CAM  ",{29,169,0,169}}
,{"   CLW  ",{29,60,0,60}}
,{"   CUT  ",{3,1,1,6000}}
,{"   DAC  ",{25,6,0,0}}
,{"   END  ",{23,1,1,2000}}
,{"   FAN  ",{29,184,0,184}}
,{"   IPM  ",{29,73,0,73}}
,{"   IPR  ",{29,74,0,74}}
,{"   LOW  ",{29,63,0,63}}
,{"   LTV  ",{33,2,0,0}}
,{"   MED  ",{29,136,0,136}}
,{"   MIT  ",{33,3,0,0}}
,{"   NOW  ",{29,161,0,161}}
,{"   NOX  ",{29,14,0,14}}
,{"   NOY  ",{29,15,0,15}}
,{"   NOZ  ",{29,16,0,16}}
,{"   OFF  ",{29,72,0,72}}
,{"   OUT  ",{29,49,0,49}}
,{"   PBS  ",{22,60,1068,2000}}
,{"   PEN  ",{29,128,0,128}}
,{"   RED  ",{29,131,0,131}}
,{"   REV  ",{29,97,0,97}}
,{"   RPM  ",{29,78,0,78}}
,{"   SFM  ",{29,115,0,115}}
,{"   SYN  ",{17,1,0,0}}
,{"   TAP  ",{29,168,0,168}}
,{"   TPI  ",{29,143,0,143}}
,{"   XYZ  ",{29,108,0,108}}
,{"   5PT  ",{29,45,0,45}}
,{"  ABSF  ",{19,9,9,8}}
,{"  AUTO  ",{29,88,0,88}}
,{"  BLUE  ",{29,133,0,133}}
,{"  BORE  ",{29,82,0,82}}
,{"  BOTH  ",{29,83,0,83}}
,{"  CALL  ",{7,1,0,0}}
,{"  CCLW  ",{29,59,0,59}}
,{"  CLTV  ",{25,5,0,0}}
,{"  CMIT  ",{33,4,0,0}}
,{"  CONE  ",{24,8,10,8}}
,{"  COPY  ",{21,3,1040,2000}}
,{"  COSF  ",{19,5,5,8}}
,{"  DARK  ",{29,137,0,137}}
,{"  DASH  ",{29,124,0,124}}
,{"  DECR  ",{29,65,0,65}}
,{"  DEEP  ",{29,153,0,153}}
,{"  DOTF  ",{19,1,1,8}}
,{"  DOWN  ",{29,113,0,113}}
,{"  EXPF  ",{19,6,6,8}}
,{"  FACE  ",{29,81,0,81}}
,{"  FINI  ",{18,1,0,14000}}
,{"  FROM  ",{26,11,3,5000}}
,{"  FULL  ",{29,147,0,147}}
,{"  GOTO  ",{26,13,5,5000}}
,{"  GOUP  ",{26,5,5,8000}}
,{"  GRID  ",{29,176,0,176}}
,{"  HEAD  ",{22,2,1002,2000}}
,{"  HIGH  ",{29,62,0,62}}
,{"  IFRO  ",{22,31,1032,2000}}
,{"  INCR  ",{29,66,0,66}}
,{"  LAST  ",{29,52,0,52}}
,{"  LEFT  ",{29,8,0,8}}
,{"  LINE  ",{24,2,7,2}}
,{"  LITE  ",{29,135,0,135}}
,{"  LOCK  ",{29,114,0,114}}
,{"  LOFT  ",{24,16,11,16}}
,{"  LOGF  ",{19,7,7,8}}
,{"  MAIN  ",{29,93,0,93}}
,{"  MESH  ",{24,19,0,51}}
,{"  MILL  ",{29,151,0,151}}
,{"  MIST  ",{29,90,0,90}}
,{"  MODE  ",{22,3,1003,2000}}
,{"  NEGX  ",{29,11,0,11}}
,{"  NEGY  ",{29,12,0,12}}
,{"  NEGZ  ",{29,13,0,13}}
,{"  NEXT  ",{29,162,0,162}}
,{"  NOPS  ",{3,7,6,9000}}
,{"  NUMF  ",{19,11,11,8}}
,{"  OMIT  ",{29,172,0,172}}
,{"  OPEN  ",{29,50,0,50}}
,{"  PART  ",{29,166,0,166}}
,{"  PAST  ",{29,70,0,70}}
,{"  PLOT  ",{22,39,1041,2000}}
,{"  PLUS  ",{29,19,0,19}}
,{"  POSX  ",{29,20,0,20}}
,{"  POSY  ",{29,21,0,21}}
,{"  POSZ  ",{29,22,0,22}}
,{"  PSIS  ",{13,1,4,3000}}
,{"  RAIL  ",{29,93,0,93}}
,{"  READ  ",{4,1,0,0}}
,{"  REAM  ",{29,167,0,167}}
,{"  REAR  ",{29,149,0,149}}
,{"  SAME  ",{29,54,0,54}}
,{"  SEC1  ",{31,1,0,0}}
,{"  SEC2  ",{31,2,0,0}}
,{"  SIDE  ",{29,94,0,94}}
,{"  SINF  ",{19,4,4,8}}
,{"  STEP  ",{29,92,0,92}}
,{"  STOP  ",{23,2,2,2000}}
,{"  TANF  ",{19,13,13,8}}
,{"  THRU  ",{29,152,0,152}}
,{"  TLON  ",{27,3,3,4000}}
,{"  TOOL  ",{24,17,3,17}}
,{"  TRAV  ",{29,154,0,154}}
,{"  TURN  ",{29,80,0,80}}
,{"  TYPE  ",{29,98,0,98}}
,{"  UNIT  ",{29,30,0,30}}
,{"  ZERO  ",{23,13,13,2000}}
,{" AAXIS  ",{29,140,0,140}}
,{" ANGLF  ",{19,10,10,8}}
,{" ATANF  ",{19,8,8,8}}
,{" AVOID  ",{29,173,0,173}}
,{" BAXIS  ",{29,141,0,141}}
,{" BLACK  ",{29,130,0,130}}
,{" CANON  ",{28,1,0,3099}}
,{" CAXIS  ",{29,142,0,142}}
,{" CHECK  ",{22,22,1023,2000}}
,{" CHUCK  ",{29,138,0,138}}
,{" CLAMP  ",{22,52,1060,2000}}
,{" CONST  ",{29,64,0,64}}
,{" CROSS  ",{29,3,0,3}}
,{" CYCLE  ",{22,46,1054,2000}}
,{" DEBUG  ",{15,1,0,0}}
,{" DELAY  ",{22,10,1010,2000}}
,{" DISTF  ",{19,15,15,8}}
,{" DITTO  ",{29,127,0,127}}
,{" DMILL  ",{3,10,11,6000}}
,{" DRAFT  ",{22,51,1059,2000}}
,{" DRESS  ",{23,8,8,2000}}
,{" DRILL  ",{29,163,0,163}}
,{" DSTAN  ",{29,27,0,27}}
,{" DWELL  ",{22,50,1058,2000}}
,{" FLOOD  ",{29,89,0,89}}
,{" FRONT  ",{29,148,0,148}}
,{" GOFWD  ",{26,3,3,8000}}
,{" GOLFT  ",{26,1,1,8000}}
,{" GORGT  ",{26,2,2,8000}}
,{" GREEN  ",{29,132,0,132}}
,{" INDEX  ",{21,2,1039,2000}}
,{" INTOF  ",{29,5,0,5}}
,{" INTOL  ",{2,4,4,6000}}
,{" ISTOP  ",{23,4,4,2000}}
,{" LARGE  ",{29,7,0,7}}
,{" LIBRY  ",{35,1,0,0}}
,{" LIGHT  ",{29,100,0,100}}
,{" LNTHF  ",{19,2,2,8}}
,{" LOCKX  ",{23,21,21,2000}}
,{" MACRO  ",{14,1,0,0}}
,{" MAXDP  ",{2,3,3,9000}}
,{" MDEND  ",{22,44,1052,2000}}
,{" MINUS  ",{29,10,0,10}}
,{" NIXIE  ",{29,99,0,99}}
,{" PARAB  ",{29,77,0,77}}
,{" PENUP  ",{23,11,11,2000}}
,{" PERSP  ",{29,67,0,67}}
,{" PITCH  ",{22,64,1050,2000}}
,{" PLANE  ",{24,3,7,3}}
,{" POINT  ",{24,1,6,1}}
,{" POSTN  ",{22,23,1024,2000}}
,{" PPLOT  ",{22,14,1014,2000}}
,{" PRINT  ",{4,3,3,0}}
,{" PROBX  ",{23,19,19,2000}}
,{" PROBY  ",{23,18,18,2000}}
,{" PSTAN  ",{29,146,0,146}}
,{" PUNCH  ",{4,2,0,0}}
,{" RANGE  ",{29,145,0,145}}
,{" RAPID  ",{23,5,5,2000}}
,{" RESET  ",{23,15,15,2000}}
,{" RIGHT  ",{29,24,0,24}}
,{" SCALE  ",{29,25,0,25}}
,{" SEQNO  ",{22,18,1019,2000}}
,{" SLOPE  ",{29,47,0,47}}
,{" SMALL  ",{29,26,0,26}}
,{" SOLID  ",{29,123,0,123}}
,{" SQRTF  ",{19,3,3,8}}
,{" START  ",{29,57,0,57}}
,{" TANDS  ",{29,183,0,183}}
,{" TANON  ",{29,109,0,109}}
,{" TANTO  ",{29,27,0,27}}
,{" THICK  ",{2,5,5,9000}}
,{" TIMES  ",{29,28,0,28}}
,{" TLLFT  ",{27,1,1,4000}}
,{" TLRGT  ",{27,2,2,4000}}
,{" TMARK  ",{22,5,1005,2000}}
,{" TOLER  ",{2,2,2,6000}}
,{" TRANS  ",{22,35,1037,2000}}
,{" TWOPT  ",{29,102,0,102}}
,{" WCORN  ",{22,63,1071,2000}}
,{" XAXIS  ",{29,84,0,84}}
,{" XYROT  ",{29,34,0,34}}
,{" YAXIS  ",{29,85,0,85}}
,{" YZROT  ",{29,38,0,38}}
,{" ZAXIS  ",{29,86,0,86}}
,{" ZSURF  ",{6,1,0,0}}
,{" ZXROT  ",{29,42,0,42}}
,{"ADJUST  ",{29,159,0,159}}
,{"ANTSPI  ",{29,176,0,176}}
,{"ARCSLP  ",{22,28,1029,2000}}
,{"ASLOPE  ",{22,45,1053,2000}}
,{"ATANGL  ",{29,1,0,1}}
,{"ATAN2F  ",{19,14,14}}
,{"AUTOPS  ",{3,5,7,9000}}
,{"AUXFUN  ",{22,21,1022,2000}}
,{"BEVELS  ",{3,10,2,6000}}
,{"BINARY  ",{29,164,0,164}}
,{"CAMERA  ",{22,36,1047,2000}}
,{"CENTER  ",{29,2,0,2}}
,{"CIRCLE  ",{24,4,10,4}}
,{"CIRCUL  ",{29,75,0,75}}
,{"CIRLIN  ",{29,126,0,126}}
,{"CLEARP  ",{22,4,1004,2000}}
,{"CLPRNT  ",{25,1,0,0}}
,{"CLRSRF  ",{22,49,1057,2000}}
,{"COLLET  ",{29,139,0,139}}
,{"CONSEC  ",{24,20,0,52}}
,{"COOLNT  ",{22,29,1030,2000}}
,{"CORNFD  ",{22,59,1067,2000}}
,{"COUPLE  ",{22,38,1049,2000}}
,{"CUTANG  ",{29,160,0,160}}
,{"CUTCOM  ",{22,7,1007,2000}}
,{"CUTTER  ",{2,6,6,6000}}
,{"CYLNDR  ",{24,5,10,5}}
,{"DELETE  ",{22,12,1012,2000}}
,{"DISPLY  ",{22,20,1021,2000}}
,{"DNTCUT  ",{3,2,1,6000}}
,{"DOTTED  ",{29,125,0,125}}
,{"DRAWLI  ",{23,17,17,2000}}
,{"DYNDMP  ",{15,2,9,6000}}
,{"ELLIPS  ",{24,6,13,6}}
,{"ELMSRF  ",{24,22,0,54}}
,{"ENDARC  ",{29,58,0,58}}
,{"FACEML  ",{23,22,22,2000}}
,{"FEDRAT  ",{22,9,1009,2000}}
,{"FOURPT  ",{29,101,0,101}}
,{"FUNOFY  ",{29,4,0,4}}
,{"GAPLES  ",{29,180,0,180}}
,{"GCONIC  ",{24,9,13,9}}
,{"GOBACK  ",{26,4,4,8000}}
,{"GOCLER  ",{23,16,16,2000}}
,{"GODLTA  ",{26,12,4,5000}}
,{"GODOWN  ",{26,6,6,8000}}
,{"GOHOME  ",{23,14,14,2000}}
,{"GOUGCK  ",{3,4,8,9000}}
,{"HOLDER  ",{29,157,0,157}}
,{"HYPERB  ",{24,7,13,7}}
,{"INDIRP  ",{26,9,1,5000}}
,{"INDIRV  ",{26,10,2,5000}}
,{"INSERT  ",{1,5,1046,2000}}
,{"INTCOD  ",{22,19,1020,2000}}
,{"INTENS  ",{29,134,0,134}}
,{"INTERC  ",{29,46,0,46}}
,{"INVERS  ",{29,6,0,6}}
,{"JUMPTO  ",{10,1,0,0}}
,{"LCONIC  ",{24,10,13,10}}
,{"LEADER  ",{22,13,1013,2000}}
,{"LENGTH  ",{29,9,0,9}}
,{"LETTER  ",{22,41,1043,2000}}
,{"LINCIR  ",{29,95,0,95}}
,{"LINEAR  ",{29,76,0,76}}
,{"LOADTL  ",{22,47,1055,2000}}
,{"LOG10F  ",{19,12,12,8}}
,{"LOOPND  ",{11,2,0,0}}
,{"LOOPST  ",{11,1,0,0}}
,{"LPRINT  ",{22,57,1065,2000}}
,{"MACHIN  ",{21,4,1015,2000}}
,{"MAGTAP  ",{22,64,1072,2000}}
,{"MANUAL  ",{29,158,0,158}}
,{"MATRIX  ",{24,12,15,12}}
,{"MAXDPM  ",{22,54,1062,2000}}
,{"MAXIPM  ",{29,96,0,96}}
,{"MAXRPM  ",{29,79,0,79}}
,{"MAXVEL  ",{22,56,1064,2000}}
,{"MCHFIN  ",{22,17,1018,2000}}
,{"MCHTOL  ",{22,15,1016,2000}}
,{"MDWRIT  ",{22,43,1051,2000}}
,{"MEDIUM  ",{29,61,0,61}}
,{"MIRROR  ",{29,56,0,56}}
,{"MODIFY  ",{29,55,0,55}}
,{"MOVETO  ",{22,58,1066,2000}}
,{"MULTAX  ",{3,3,2,9000}}
,{"MULTRD  ",{29,119,0,119}}
,{"NDTEST  ",{3,6,2,6000}}
,{"NOMORE  ",{29,53,0,53}}
,{"NOPLOT  ",{25,2,0,0}}
,{"NOPOST  ",{25,3,0,0}}
,{"NORMAL  ",{29,111,0,111}}
,{"NORMDS  ",{29,182,0,87}}
,{"NORMPS  ",{29,181,32767,4000}}
,{"NUMPTS  ",{2,7,4,9000}}
,{"OBTAIN  ",{5,1,0,0}}
,{"OFFSET  ",{26,8,2,7000}}
,{"OPSKIP  ",{22,42,1012,2000}}
,{"OPSTOP  ",{23,3,3,2000}}
,{"OPTION  ",{29,144,0,144}}
,{"ORIGIN  ",{22,26,1027,2000}}
,{"OUTTOL  ",{2,8,5,6000}}
,{"OVPLOT  ",{22,40,1042,2000}}
,{"PARLEL  ",{29,17,0,17}}
,{"PATERN  ",{24,22,0,18}}
,{"PENDWN  ",{23,12,12,2000}}
,{"PERPTO  ",{29,18,0,18}}
,{"PICKUP  ",{23,9,9,2000}}
,{"PIVOTZ  ",{22,16,1017,2000}}
,{"PLABEL  ",{22,53,1061,2000}}
,{"PLUNGE  ",{22,1,1001,2000}}
,{"POCKET  ",{12,1,1,11000}}
,{"POLCON  ",{24,15,82,15}}
,{"PREFUN  ",{22,37,1048,2000}}
,{"PTNORM  ",{29,104,0,104}}
,{"PTONLY  ",{25,4,0,0}}
,{"PTSLOP  ",{29,103,0,103}}
,{"QADRIC  ",{24,14,13,14}}
,{"RADIUS  ",{29,23,0,23}}
,{"RANDOM  ",{29,174,0,174}}
,{"REFSYS  ",{8,1,0,0}}
,{"REGBRK  ",{22,61,1069,2000}}
,{"RESERV  ",{16,1,0,0}}
,{"RETAIN  ",{29,171,0,171}}
,{"RETRCT  ",{23,7,7,2000}}
,{"REVERS  ",{22,8,1008,2000}}
,{"REWIND  ",{22,6,1006,2000}}
,{"RLDSRF  ",{24,21,0,53}}
,{"ROTABL  ",{22,25,1026,2000}}
,{"ROTHED  ",{22,33,1035,2000}}
,{"ROTREF  ",{29,68,0,68}}
,{"RTHETA  ",{29,106,0,106}}
,{"SADDLE  ",{29,150,0,150}}
,{"SAFETY  ",{22,27,1028,2000}}
,{"SCRIBE  ",{29,129,0,129}}
,{"SELCTL  ",{22,48,1056,2000}}
,{"SETANG  ",{29,156,0,156}}
,{"SETOOL  ",{29,155,0,155}}
,{"SLOWDN  ",{22,55,1063,2000}}
,{"SPHERE  ",{24,13,7,13}}
,{"SPINDL  ",{22,30,1031,2000}}
,{"SPLINE  ",{29,105,0,105}}
,{"SRFVCT  ",{26,14,8,5000}}
,{"SWITCH  ",{23,6,6,2000}}
,{"TABCYL  ",{24,18,0,50}}
,{"TANCRV  ",{33,5,0,0}}
,{"TAPKUL  ",{29,91,0,91}}
,{"TERMAC  ",{14,2,0,0}}
,{"THETAR  ",{29,107,0,107}}
,{"THREAD  ",{22,34,1036,2000}}
,{"TLAXIS  ",{2,1,1,9000}}
,{"TLNDON  ",{27,7,3,4000}}
,{"TLOFPS  ",{27,6,6,4000}}
,{"TLONPS  ",{27,5,5,4000}}
,{"TOOLNO  ",{22,24,1025,2000}}
,{"TRACUT  ",{21,1,1038,2000}}
,{"TRANSL  ",{29,29,0,29}}
,{"TRANTO  ",{20,1,7,6000}}
,{"TRFORM  ",{29,110,0,110}}
,{"TUNEUP  ",{34,1,0,0}}
,{"TURRET  ",{22,32,1033,2000}}
,{"ULOCKX  ",{23,20,20,2000}}
,{"UNLOAD  ",{23,10,10,2000}}
,{"VECTOR  ",{24,11,6,11}}
,{"VTLAXS  ",{22,62,1070,2000}}
,{"XCOORD  ",{29,116,0,116}}
,{"XLARGE  ",{29,31,0,31}}
,{"XSMALL  ",{29,32,0,32}}
,{"XYPLAN  ",{29,33,0,33}}
,{"XYVIEW  ",{29,120,0,120}}
,{"YCOORD  ",{29,117,0,117}}
,{"YLARGE  ",{29,35,0,35}}
,{"YSMALL  ",{29,36,0,36}}
,{"YZPLAN  ",{29,37,0,37}}
,{"YZVIEW  ",{29,121,0,121}}
,{"ZCOORD  ",{29,118,0,118}}
,{"ZIGZAG  ",{29,170,0,170}}
,{"ZLARGE  ",{29,39,0,39}}
,{"ZSMALL  ",{29,40,0,40}}
,{"ZXPLAN  ",{29,41,0,41}}
,{"ZXVIEW  ",{29,122,0,122}}
,{"2DCALC  ",{3,8,2,6000}}
,{"3DCALC  ",{3,9,2,6000}}
,{"3PT2SL  ",{29,43,0,43}}
,{"4PT1SL  ",{29,44,0,44}}
,{0 ,{}}//mark end of array
};

