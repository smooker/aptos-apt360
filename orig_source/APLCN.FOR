      SUBROUTINE APLCN(  JUNDD)
C     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 ***
      IMPLICIT REAL*8(A-H,O-Z)
C2350 POLYCONIC,  SYSTEM/360 SECTION 2 APT
C     JUNDD=1 FOR UNIT NORMAL          JUNDD=2 FOR DIRECTED DISTANCE
C     TEST IF FIRST TIME IN FOR THIS SURFACE
C
      COMMON/A2FPC / Q15X01,QP9X01    ,QP6X01    ,QP5X01    ,QP4X01    ,
     1QP0001    ,QP001     ,QP01      ,QP1       ,Q1P       ,Q10P      ,
     2Q1000P    ,Q1PE5     ,Q1PE6     ,Q1PE10    ,Q1PE20    ,Q1PE30    ,
     3Q1PE36    ,Q1PE38    ,QP8X01    ,QP7X01    ,
     4QP4X09    ,QP9       ,QP99      ,QP995     ,QP997     ,QP999     ,
     5QP9999    ,QP4X95    ,QP5X95    ,QP6X9     ,QP7X9     ,
     6QP6X05    ,QP5X05    ,QP4X05    ,QP0005    ,QP005     ,QP05      ,
     7QP5       ,Q5P       ,                                 Q4X045    ,
     8QP0002    ,QP0047    ,QP017     ,Q1RAD     ,QP0349    ,QP125     ,
     9QP6       ,QP2       ,QP2499    ,QP25      ,QP3
      COMMON/A2FPC / QP7   ,QP75      ,QP8       ,QP866     ,Q1P01     ,
     1Q1P1      ,Q1P2      ,Q1P25     ,Q1P5      ,Q2P       ,Q2P5      ,
     2Q3P       ,Q3P5      ,Q4P       ,Q8P       ,Q11P      ,Q45P      ,
     3Q90P      ,Q130P     ,Q4500P    ,Q9000P    ,QP02      ,QNUL      ,
     4QPIE       ,QFIL(9)
      COMMON/A2CMMN/ SP(3), SN(3), TP(3), TN(3), AHOLD(57),ZMVMAG(1),
     1    BHOLD(30), AFILLR(500),
     2    IHOLD(9), IOP(1), IHOLD1(21), IFILLR(209),
     3    CHOLD(39), VTEM(3), DHOLD(12), VNUL(3), EHOLD(111),
     4       DPMAX, FHOLD(367),
     5    IS, IIS, IHOLD2(85), IC, IHOLD3(16),
     6    PROBUF(100),
     7    CANSTO(2000),
     8    IER, IHOLD4(9)
      DIMENSION TEM(12),D(2000)
      EQUIVALENCE (CANSTO(1),D(1))
      DIMENSION AC(7),ACP(7)
      DIMENSION DR(3), AM(56)
      DIMENSION RS(3),RV(3),UN(3),Q(3),S(3),ZM(3),PC(3),CBAR(3)
      DIMENSION AMULT(7),BMULT(7),CMULT(7),DMULT(7),ZLMULT(7),
     1 HMULT(7),RHOMUL (7),V(3)
      DIMENSION DELP(3),DELR(3),R(3),TRANS(12),P(3),DELM(3),
     1 A(8),B(8),C(8)     ,ZL(8),H(8),RHO(8),ROOTS(7)
      COMMON/APLCNC/ POLDAT(127), CALC(100), IPOLCM(12)
      EQUIVALENCE (CALC(1),R(1)),(CALC(4),RV(1)),(CALC(7),RS(1)),
     1(CALC(10),DT),(CALC(11),DELDT),(CALC(12),DS),(CALC(13),AC(1)),
     2(CALC(14),BC),(CALC(15),CC),(CALC(16),DC),(CALC(17),ZLC),
     3(CALC(18),HC),(CALC(19),RHOC),(CALC(20),ACP(1)),
     4(CALC(21),BCP),(CALC(22),CCP),(CALC(23),DCP),
     5 (CALC(24),ZLCP),(CALC(25),HCP),(CALC(26),RHOCP),
     6 (CALC(27),UP),(CALC(28),WP),(CALC(29),UPRM),
     7 (CALC(30),WPRM),(CALC(31),P(1)),(CALC(34),UN(1)),
     8 (CALC(37),ZLAMN),(CALC(38),PC(1)),(CALC(41),DELP(1))
      EQUIVALENCE (CALC(44),ZLAMC),(CALC(45),CBAR(1)),
     1(CALC(48),DELR(1)),(CALC(51),DELM(1)),(CALC(54),DD1),
     2 (CALC(55),DD2   ), (CALC(56),DU    ), (CALC(57),DW    ),
     3 (CALC(58),PHI   ), (CALC(59),RLAM  ), (CALC(60),RVLAM ),
     4 (CALC(61),SQPHI ), (CALC(62),TSA   ), (CALC(63),TSB   ),
     5 (CALC(64),TSC   ), (CALC(65),TSD   ), (CALC(66),TSE   ),
     6 (CALC(67),TSH   ), (CALC(68),TSI   ), (CALC(69),TSJ   ),
     7 (CALC(70),UC    ), (CALC(71),UKP   ), (CALC(72),URS   ),
     8 (CALC(73),WC    ), (CALC(74),WKP   ), (CALC(75),WRS   ),
     9 (CALC(76),EPSIL4), (CALC(77),FAC   ), (CALC(78),TEM(1))
C
      EQUIVALENCE (IPOLCM(1),IDCNT ),(IPOLCM(2),IDDCNT),
     1 (IPOLCM( 3),IPCER ), (IPOLCM( 4),IUNCNT), (IPOLCM( 5),JROOTS),
     2 (IPOLCM( 6),JSWL  )
C
      EQUIVALENCE (POLDAT(1),TRANS(1)),(POLDAT(13),T),(POLDAT(14),CB),
     1 (POLDAT(15),PB),(POLDAT(16),A( 1)),(POLDAT(24),B(1)),
     2 (POLDAT(32),C(1)),(POLDAT(48),ZL(1)),(POLDAT(56),H(1)),
     3 (POLDAT(64),RHO(1)),(POLDAT(72),ROOTS(1)),(POLDAT(79),AMULT(1)),
     4 (POLDAT(86),BMULT(1)),(POLDAT(93),CMULT(1)),
     5 (POLDAT(100),DMULT(1)),(POLDAT(107),ZLMULT(1)),
     6 (POLDAT(114),HMULT(1)),(POLDAT(121),RHOMUL(1)),
     7 (POLDAT(16),AM(1))
C
C
      ANS = D(IC)
      IANS = ANS + QP01
      IF(IANS-130) 100,200,100
C      IF FIRST TIME, CALCULATE 1ST DERIVATIVE COEFF.
  100 I=IC+83
      J=IC+ 21
      TEM(1) =Q2P
  101 CONTINUE
      DO 111 KK=1,7
      KK1 = (KK-1)*7
      KK2 = (KK-1)*8
      D(I+KK1) = TEM(1)*D(J+KK2)
  111 CONTINUE
C
      I = I + 1
      J = J +1
      TEM(1) = TEM(1) + Q1P
      ITEM = TEM(1) + QP01
      IF(ITEM-8) 101,102,101
C      IF SQUARE ROOT TERMS, CALC COEFF
  102 JROOTS = DABS(D(IC+3)) + QP01
      IF(JROOTS.NE.2) GO TO 105
  103 I = IC+82
      J = IC + 75
  104 D(I)= D(J)/Q2P
      I = I+7
      J= J + 1
      IF(J-IC-82) 104,105,104
C      SET CANONICAL FORM LEG TO 130
  105 D(IC) = Q130P
C
C
C      END OF FIRST TIME ONLY CALC
C
  200 JROOTS = DABS(D(IC+3)) + QP01
C      NAME = BLOCK1(IC+1)
C      TRANSFER CANONICAL FORM FROM CANSTO TO POLDAT
      J = IC+4
      DO 201 I=1,127
      POLDAT(I)=D(J)
  201 J = J+1
C
C
C...  SECTION 1 ... ENTRY
C
      JTRANS = 2
      IF(TRANS(1).EQ.0.D0.AND.TRANS(2).EQ.0.D0.AND.TRANS(3).EQ.0.D0)
     1    JTRANS=1
      IF(JUNDD.EQ.1)   IF (JTRANS-1) 8050,8050,8051
      JSWH = 1
      IF (JTRANS .EQ. 2)  GOTO 1085
 1080 DO 1021 I=1,3
      IH = IS-1+I
      DELR(I) = TN(IH)
 1021 R(I) = TP(IH)
      GO TO 1090
 1085 DO 1075 I=1,3
      IH = IS-1+I
      VTEM(I)=TP(IH)
 1075 DR(I)=TN(IH)
      DO 1095 I=1,3
      IH=I*4
      CALL AVDOT(VTEM,TRANS(IH-3), R(I))
      R(I) =  R(I)+ TRANS(IH)
 1095 CALL AVDOT(DR,TRANS(IH-3),DELR(I))
 1090 R(1)=R(1)-CB
C
C
C...  SECTION 2  D SELECTION
C
 2000 RLAM = QNUL
      FAC=Q1P
      IDCNT = 5
      DO 2010 I=1,3
      RS(I) = R(I)
      CBAR (I) = R(I)
 2010 RV(I) = R(I)
      DS = RS(1)/PB
      IF(DS.LE.Q1P )GO TO 2030
      DS=Q1P
      DELDT = -QP25
      GO TO 2060
 2030 IF(DS) 2040,2110,2110
 2040 DS = QP0001
      DELDT = QP25
 2060 DT = QNUL
C...    INITIALIZE AC(I)
      CALL APLCNA (1,&2100,&2100)
      GO TO 2100
 2110 IF(DS.LE.QP5 ) GO TO 2150
      DT = Q1P25
      DELDT = -QP25
      GO TO 2180
 2150 DS=DMAX1(DS,QP0001)
      DT = -QP2499
      DELDT = QP25
      GO TO 2180
 2080 DT = DT + DELDT
      DS = DT
 2100 IF(DABS(DELR(1)).LT.QP5X01) GO TO 2220
      RVLAM = (PB * DS - RV(1))/DELR(1)
       DO 2211 I = 1,3
      RS(I) = RVLAM * DELR(I) + RV(I)
 2211 RV(I) = RS(I)
      GO TO 2270
 2220 IF(DS.NE.DT.AND.JROOTS.EQ.2.AND.DELDT.GT.QNUL)GO TO 9100
      ZNLAM = (ZLC-RV(2))**2 +(HC-RV(3))**2
      RVLAM =(ZLC + AC(1) + CC - RV(2))**2 +(HC+BC+DC-RV(3))**2
      RVLAM=DSQRT(DMAX1(ZNLAM,RVLAM))
      DO 2261 I=1,3
      RV(I) = RV(I) + RVLAM*DELR(I)
 2261 RS(I) = RV(I) - T*UN(I)
      DS = RS(1) /PB
 2270 RLAM = RLAM + RVLAM
      DT = DS
      IF(IDCNT.LE.0) GO TO 9100
      IDCNT = IDCNT -1
C
 2180 CALL APLCNA (0,&2080,&9100)
C
C
C ... SECTION 8 ACCEPTANCE TESTS AND NORMAL EXIT
C
      TEM(1) = DPMAX  / PB
      IF(DS+TEM(1).LT.QNUL.OR. Q1P  +TEM(1).LT.DS  )GO TO 9100
      IF(IOP(IIS)) 8070,8080,8070
 9100 IER =1
      GO TO 9200
 8050 CALL AVSTO (UN,SN(IS))
      GO TO 8160
 8051 SN(IS) = UN(1)*TRANS(1)+UN(2)*TRANS(5)+UN(3)*TRANS(9)
      SN(IS+1) = UN(1)*TRANS(2)+UN(2)*TRANS(6)+UN(3)*TRANS(10)
      SN(IS+2) = UN(1)*TRANS(3)+UN(2)*TRANS(7)+ UN(3)*TRANS(11)
      GO TO 8160
 8070 ZMVMAG(IS) = RVLAM
      GO TO 8160
 8080 IF(JSWH.EQ.2) GO TO 8100
      DD1 = RLAM
      IF(RLAM.NE.Q1PE20 )GO TO 8094
      DELR(1)= -DELR(1)
      DELR(2)= -DELR(2)
      DELR(3)= -DELR(3)
      JSWH = 2
      GO TO 2000
 8094 RLAM = Q1PE20
 8100 DD2 = RLAM
      ZMVMAG(IS)=-DD2
      IF(DD1.EQ.Q1PE20) IF(DD2-Q1PE20) 8160,9100,8160
      IF(DD2.EQ.Q1PE20.OR.DABS(DD1).LE.DABS(DD2))ZMVMAG (IS)=DD1
 8160 IER = 0
 9200 CONTINUE
      RETURN
      END

