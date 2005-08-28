PARTNO N/C 360  APT SAMPLE PART PROGRAM                                      010
      CLPRNT                                                                 012
      NOPOST                                                                 014
      SP   =  POINT/ 0, 0, 0                                                 020
      L1   =  LINE/ 4, 0, 0, 4, 8, 0                                         030
      PT   =  POINT/ 4.0, 8.0, 0                                             040
      L2   =  LINE/ PT, ATANGL, 45                                           050
      L3   = LINE/ 8, 12, 0, 12, 12, 0                                       060
      L4   =  LINE/ 14, 5, 0, 14, 10, 0                                      070
      L5   =  LINE/ 0, 2, 0, 10, 2, 0                                        080
      C1   =  CIRCLE/ 12, 10, 0, 2.0                                         090
      C2   =  CIRCLE/ 14, 2, 0, 3.0                                          100
      INTOL/ 0                                                               110
      OUTTOL/ .005                                                           120
      CUTTER/ .25                                                            130
      SPINDL/ 2000, CLW                                                      140
      COOLNT/ ON                                                             150
      FEDRAT/ 20.0                                                           160
      FROM/ SP                                                               170
      GO/ TO, L1                                                             180
      TLLFT, GOLFT/ L1, PAST, L2                                             190
      GORGT/ L2, PAST, L3                                                    200
      GORGT/ L3, TANTO, C1                                                   210
      GOFWD/ C1, TANTO, L4                                                   220
      GOFWD/L4, PAST, C2                                                     230
      GORGT/ C2, PAST, L5                                                    240
     GORGT/ L5, PAST, L1                                                     250
      GOTO/ SP                                                               260
      COOLNT/ OFF                                                            270
      SPINDL/ OFF                                                            280
      END                                                                    285
      FINI                                                                   290
PARTNO  SYSTEM VERIFICATION TEST PART FOR SYSTEM/360 APT                TEST0000
REMARK THIS IS IBM TEST CASE A281                                       TEST0010
RESERV/TP,28,ZDCL,1,N,20,PNT,3                                          TEST0020
TP(1) =POINT/60.85,25.475                                               TEST0030
TP(2) =POINT/61,24.746                                                  TEST0040
TP(3) =POINT/62,23.61627                                                TEST0050
TP(4) =POINT/63,23.143                                                  TEST0060
TP(5) =POINT/64,22.883                                                  TEST0070
TP(6) =POINT/65,22.744                                                  TEST0080
TP(7) =POINT/66,22.681                                                  TEST0090
TP(8) =POINT/67,22.675                                                  TEST0100
TP(9) =POINT/68,22.712                                                  TEST0110
TP(10)=POINT/69,22.789                                                  TEST0120
TP(11)=POINT/70,22.904                                                  TEST0130
TP(12)=POINT/71,23.052714                                               TEST0140
TP(13)=POINT/72,23.228                                                  TEST0150
TP(14)=POINT/73,23.423216                                               TEST0160
TP(15)=POINT/74,23.634                                                  TEST0170
TP(16)=POINT/75,23.85562                                                TEST0180
TP(17)=POINT/76,24.081                                                  TEST0190
TP(18)=POINT/77,24.303143                                               TEST0200
TP(19)=POINT/78,24.516                                                  TEST0210
TP(20)=POINT/79,24.715105                                               TEST0220
TP(21)=POINT/80,24.9                                                    TEST0230
TP(22)=POINT/81,25.069079                                               TEST0240
TP(23)=POINT/82,25.214                                                  TEST0250
TP(24)=POINT/83,25.327541                                               TEST0260
TP(25)=POINT/84,25.412                                                  TEST0270
TP(26)=POINT/85,25.470112                                               TEST0280
TP(27)=POINT/86,25.498                                                  TEST0290
TP(28)=POINT/86.79,25.5                                                 TEST0300
   MHB=TABCYL/NOZ,SPLINE,TP(1),SLOPE,1000000,TP(2),TP(3),TP(4),TP(5),  $TEST0310
      TP(6),TP(7),TP(8),TP(9),TP(10),TP(11),TP(12),TP(13),TP(14),TP(15)$TEST0320
      ,TP(16),TP(17),TP(18),TP(19),TP(20),TP(21),TP(22),TP(23),TP(24), $TEST0330
      TP(25),TP(26),TP(27),TP(28),SLOPE,0                               TEST0340
PNT(1)=POINT/79.764,-.238                                               TEST0350
PNT(2)=POINT/86.79,0                                                    TEST0360
PNT(3)=POINT/83.373,-.069                                               TEST0370
ZDCL(1)=LCONIC/3PT2SL,PNT(1),.0699268,PNT(2),0,PNT(3)                   TEST0380
   XAX=LINE/0,0,1,0                                                     TEST0390
   BL0=LINE/0,1,0,0                                                     TEST0400
    YN=LINE/86.79,0,86.79,1                                             TEST0410
   Y4A=LINE/(POINT/79.764,-.238),ATANGL,94                              TEST0420
    P1=POINT/INTOF,Y4A,XAX                                              TEST0430
    P2=POINT/INTOF,Y4A,YN                                               TEST0440
 LTEMP=LINE/(POINT/INTOF,BL0,XAX),ATANGL,-1                             TEST0450
    PL=PLANE/0,0,1,0                                                    TEST0460
 SETPT=POINT/0,-3,0                                                     TEST0470
       CLPRNT                                                           TEST0480
       NOPOST                                                           TEST0490
       CUTTER/0                                                         TEST0500
    P7=POINT/INTOF,YN,XAX                                               TEST0510
  GOGO=MACRO/                                                           TEST0520
       FROM/SETPT                                                       TEST0530
       GO/ON,BL0,ON,PL,ON,XAX                                           TEST0540
  TLON,GORGT/XAX,ON,CTEMP                                               TEST0550
       GOLFT/CTEMP,ON,LTEMP                                             TEST0560
       GOFWD/CTEMP,ON,LTEMP                                             TEST0570
       GOTO/SETPT                                                       TEST0580
       TERMAC                                                           TEST0590
FANSTA=MACRO/MV1,MV2,KF,Q                                               TEST0600
REMARK THIS MACRO DEFINES CENTER AND RADIUS OF RADIAL STATIONS IN NOSE  TEST0610
$$     COWL DUCT TRANSITION, AND COORDINATES OF POINTS ON STA CONTOURS  TEST0620
$$     MV1=YN VALUE                                                     TEST0630
$$     MV2=CALL SEQUENCE IDENTITY                                       TEST0640
$$    MAXIMUM SIMULTANIOUS CALLS OF THIS MACRO IS 20                    TEST0650
       IF(MV1-79.764)6,6,4                                              TEST0660
4)     IF(MV1-86.79)5A,5A,6                                             TEST0670
5A)    IF(MV2-20)5,5,6A                                                 TEST0680
5) LYN=LINE/(LINE/MV1,0,MV1,1),CANON                                    TEST0690
    P3=POINT/(POINT/INTOF,LYN,XAX),CANON                                TEST0700
  LFAN=LINE/(LINE/P3,P2),CANON                                          TEST0710
       OBTAIN,POINT/(POINT/YLARGE,INTOF,LFAN,ZDCL(1)),XX,YY             TEST0720
   P4 =POINT/(POINT/INTOF,LYN,MHB,TP(KF)),CANON                         TEST0730
    V2=VECTOR/(VECTOR/P3,P4),CANON                                      TEST0740
  RAD2=LNTHF(V2)                                                        TEST0750
N(MV2)=LINE/CANON,0,YY,XX,RAD2                                          TEST0760
       OBTAIN,POINT/P3,3X                                               TEST0770
       OBTAIN,POINT/P7,7X,7Y                                            TEST0780
       OBTAIN,POINT/P2,,2Y                                              TEST0790
  CTAN=(7X-3X)/(7Y-2Y)                                                  TEST0800
  CANG=ATANF(CTAN)                                                      TEST0810
    M2=MATRIX/(MATRIX/YZROT,-CANG,TRANSL,0,YY,XX),CANON                 TEST0820
 CTEMP=CIRCLE/(CIRCLE/0,0,RAD2),CANON                                   TEST0830
       IF(Q-1)ID,7,7                                                    TEST0840
ID)    IF(MV2-1)6A,5B,5C                                                TEST0850
5B)    PRINT/0                                                          TEST0860
TITLES                               XN           ZN           YN       TEST0870
TITLES RIGHT RADIUS                                                     TEST0880
TITLES                                                                  TEST0890
5C)    PRINT/2,N(MV2)                                                   TEST0900
       JUMPTO/7                                                         TEST0910
6)     PRINT/2,MV1                                                      TEST0920
TITLES MV1 OUTSIDE FAN AREA                                             TEST0930
       JUMPTO/7                                                         TEST0940
6A)    PRINT/2,MV2                                                      TEST0950
TITLES MV2 EXCEEDED MACRO LIMIT                                         TEST0960
7)     R=1                                                              TEST0970
       TERMAC                                                           TEST0980
       PRINT/0                                                          TEST0990
    MO=MACRO/                                                           TEST1000
TRACUT/M2                                                               TEST1010
       CALL/GOGO                                                        TEST1020
TRACUT/NOMORE                                                           TEST1030
       TERMAC                                                           TEST1040
       A=80                                                             TEST1050
       B=2                                                              TEST1060
       C=21                                                             TEST1070
       LOOPST                                                           TEST1080
       PRINT/0                                                          TEST1090
TITLES                               XN           ZN           YN       TEST1100
TITLES                                                                  TEST1110
ID10)  CALL/FANSTA,MV1=A,MV2=B,KF=C,Q=1                                 TEST1120
 PTEMP=POINT/(POINT/YLARGE,INTOF,BL0,CTEMP),CANON                       TEST1130
       OBTAIN,POINT/PTEMP,UPX,UPY,UPZ                                   TEST1140
       DIS=UPY*SINF(CANG)                                               TEST1150
  UPYP=XX-DIS                                                           TEST1160
  LPYP=XX+DIS                                                           TEST1170
  DIS2=UPY*COSF(CANG)                                                   TEST1180
  UPZP=DIS2-ABSF(YY)                                                    TEST1190
   SUM=DIS2+ABSF(YY)                                                    TEST1200
  LPZP=-SUM                                                             TEST1210
  UPRO=POINT/CANON,UPX,UPZP,UPYP                                        TEST1220
       PRINT/3,UPRO                                                     TEST1230
 PTEMP=POINT/(POINT/YSMALL,INTOF,BL0,CTEMP),CANON                       TEST1240
       OBTAIN,POINT/PTEMP,LPX,LPY,LPZ                                   TEST1250
  LPRO=POINT/CANON,LPX,LPZP,LPYP                                        TEST1260
       PRINT/3,LPRO                                                     TEST1270
    IF(A-86.79)ID13,ID12,ID13                                           TEST1280
ID13) C=C+1                                                             TEST1290
       A=A+1                                                            TEST1300
       B=B+1                                                            TEST1310
       IF(A-86)ID10,ID10,ID11                                           TEST1320
ID11)  A=86.79                                                          TEST1330
       JUMPTO/ID10                                                      TEST1340
ID12)  LOOPND                                                           TEST1350
       PRINT/0                                                          TEST1360
       CALL/FANSTA,MV1=79.959,MV2=1,KF=20,Q=0                           TEST1370
       CALL/MO                                                          TEST1380
       CALL/FANSTA,MV1=81.0,MV2=2,KF=22,Q=0                             TEST1390
       CALL/MO                                                          TEST1400
       CALL/FANSTA,MV1=83.372,MV2=3,KF=24,Q=0                           TEST1410
       CALL/MO                                                          TEST1420
       CALL/FANSTA,MV1=85.5,MV2=4,KF=26,Q=0                             TEST1430
       CALL/MO                                                          TEST1440
       CALL/FANSTA,MV1=86.79,MV2=5,KF=27,Q=0                            TEST1450
       CALL/MO                                                          TEST1460
FINI                                                                    TEST1470

