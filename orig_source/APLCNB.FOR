      SUBROUTINE APLCNB (*,*)
C     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 ***
      IMPLICIT REAL*8(A-H,O-Z)
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
      DIMENSION        AM(56)
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
      MUCNT =4
      GO TO 4001
C
C....   SECTION 4 9999 LINE INTERSECTION
C
 4010 IF(MUCNT.LE.0) RETURN 2
      MUCNT = MUCNT - 1
 4001 ICT = 10
      JSWK = 1
      GO TO (4011,4000,4013,4005), JSWL
 4000 TEM(1) = TSC
      UK= TSD
      WK= TSE
      JSWL = 1
      GO TO 4020
 4005 UK = -QP1
      WK = Q1P1
      GO TO 4019
 4011 UK = QP5
      WK = QP5
      GO TO 4019
 4013 UK = UC
      WK = WC
 4019 JSWL = 2
 4020 DL = UK * WRS - WK * URS
      EL = WK - WRS
      FL = UK - URS
      FLAG = DABS(EL) - DABS(FL)
      AQ = EL*EL +FL*(FL+(PHI-Q2P)*EL)
      BQ = DL*(EL - FL)
      CQ = DL
      IF(EL.EQ.QNUL.AND.FL.EQ.QNUL) GO TO 4010
      IF(FLAG) 4050,4050,4040
 4040 TEM(1) = EL * (-DL-FL)
      TEM(2) = EL*PHI + DL
      GO TO 4060
 4050 TEM(1) = (DL-FL)*FL
      TEM(2) = DL
 4060 BQ = BQ + TEM(1)*PHI*QP5
      CQ = CQ * TEM(2)
      IF(AQ) 4070,4090,4070
 4070 CURLYM = BQ * BQ - AQ * CQ
      IF(CURLYM) 5035,4110,4080
 4080 RCM = DSQRT(CURLYM)
      U1 = (RCM-BQ)/AQ
      U2 = (-RCM-BQ)/AQ
      GO TO 4130
 4090 IF(BQ.EQ.QNUL) RETURN 1
      U1 = -CQ*QP5 /BQ
      GO TO 4120
 4110 U1 = -BQ/AQ
 4120 U2 = U1
 4130 IF(FLAG.GT.QNUL) GO TO 4150
      W1 = (U1*EL + DL) / FL
      W2 = (U2* EL + DL) / FL
      GO TO 4210
 4150 W1 = U1
      W2 = U2
      U1 = (W1*FL-DL)/ EL
      U2 =(W2 * FL - DL) / EL
C
C
C...   SECTION 5 POINT SELECTION
C
 4210 TEM(1) = U1-W1
      TEM(2) = U2 - W2
      IF(PHI -Q4P ) 5020,5160,5015
 5015 TEM(1) = - TEM(1) - 1.D0
      TEM(2) = - TEM(2) -1.D0
 5020 IF(TEM(1).LE.QNUL)IF(TEM(2))5160,5160,5090
      IF(TEM(2).LE.QNUL)GO TO 5070
 5035 IF(PHI.GE.Q4P )GO TO 4010
 5040 JSWK = 2
      U1 = QNUL
      W2 = Q1P
      UPRM = QNUL
      WPRM = QNUL
      W1 = DL
      U2  = FL - W1
      IF(EL.EQ.QNUL.OR.U2*EL.LE.QNUL.OR.DABS(U2).LT.DABS(EL))GO TO 5075
      U2 =U2 /EL
      IF(FL.NE.QNUL.AND.W1*FL.LE.QNUL) GO TO 5065
 5070 UP = U2
      WP = W2
 5074 IF (JSWK-1) 5221,5221,5260
 5075 IF(FL.EQ.QNUL.OR.W1*FL.GT.QNUL)GO TO 4010
      W1 =W1/FL
 5090 UP = U1
      WP = W1
      GOTO 5074
 5065 W1 = W1 /FL
 5160 PI=(W2-W1)*(TSH-UKP*(W1+W2))+(U2-U1)*(TSI-WKP*(U1+U2))+ TSJ*
     1(U1*W1-U2*W2)
      IF(PI) 5090,5090,5070
 5221 TSA =WP-UP
      TSB =TSA+TSA
      DW=PHI-PHI*WP+TSB
      DU=PHI*UP+TSB
      U2 = DW * UP - DU * WP + PHI * UP
      W2  = Q2P * (DU * EL - DW * FL)
      IF(DABS(W2).LT.DABS(U2)) GO TO 5210
      U2 = U2/W2
      U1 = UP + U2 * FL
      W1 = WP + U2 * EL
      ICT = ICT -1
      IF(ICT) 5090,5210,5090
 5210 IF(TSA.LT.QNUL)SQPHI=-SQPHI
      IF(UP) 5240,5250,5240
 5250 WP = QNUL
      UPRM = QNUL
      WPRM = QNUL
      GO TO 5260
 5240 THETA = DABS((Q1P-WP)/UP)
      UPRM = -((SQPHI+Q2P)*UP)**2*DSQRT(THETA)*RHOCP
      WPRM = - THETA * UPRM
 5260 P(1) = DS * PB
      P(2) = ZLC + AC(1)*UP+CC*WP
      P(3) = HC + BC * WP + DC * UP
      IF(JSWK.EQ.1) GO TO 5280
      IF(UP) 5272,5274,5272
 5272 UP = Q1P
      GO TO 5280
 5274 WP = QNUL
 5280 IF(PHI.LT.Q4P .AND.UP.GT.WP) GO TO 5040
      TSA= WP-UP
      IF(PHI.GT.Q4P .AND.TSA.GT.Q1P ) GO TO 4010
      TSB= TSA+TSA
      RETURN
      END

