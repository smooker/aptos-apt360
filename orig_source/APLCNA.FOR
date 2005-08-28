      SUBROUTINE APLCNA (IARG,*,*)
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
      IUNCNT = 10
      IDDCNT = 25
      JSWL = 4
 3000 DO 3004 I=1,7
      J = 7
      JSWP = 1
C
C
C....    SECTION 3 POLCON CONTROL COMPUTATIONS
C
      L = 7*I
      K=L+I
      AC(I)=AM(K)
      ACP(I) = AMULT(L)
      GO TO 3001
 3002 L = L-1
      ACP(I) = ACP(I) *DS + AMULT(L)
 3001 K = K-1
      AC(I)=AC(I)*DS +AM(K)
      J = J-1
      IF(J-1) 3004,3001,3002
 3004 ACP(I) = ACP(I) * DS
      IF(CC*DC.NE.AC(1)*BC) GO TO 37
      IF(CC.NE.QNUL) GOTO 36
      CC=CC+QP5X01
      AC(1)=AC(1)-QP5X01
      GOTO 37
   36 BC=BC+QP5X01
      DC=DC-QP5X01
 37   IF(JROOTS.EQ.1) GO TO 3050
      IF(DS) 3075,3075,3085
 3075 DS = Q15X01
      SQDS =QP7X01
      IUNCNT = 0
      IDDCNT = 0
      JSWL = 4
      GO TO 3110
 3085 SQDS = DSQRT(DS)
 3110 TSA=SQDS*FAC
      TSB=FAC/SQDS
      DO 3086 I=1,7
      AC(I)=AC(I)+ROOTS(I)*TSA
 3086 ACP(I)=ACP(I)+AMULT(7*I-6)*TSB
 3050 DO 3051 I=1,7
 3051 ACP(I)=( ACP(I)+ AM(8*I-6))/PB
      IF(IARG.NE.0) RETURN
      RHOC =                DMAX1(RHOC,.5000005D0)
      IF(DABS(RHOC-Q1P ).LE.QP5X01)  RHOC = QP6X9
      SQPHI= Q1P/(Q1P -RHOC)-Q2P
      PHI = SQPHI **2
      AREA = AC(1) * BC -CC * DC
      IF(AREA.EQ.QNUL)AREA=QP7X01
      TSC=AC(1)/AREA
      TSD= BC /AREA
      TSE= CC/AREA
      TSF= DC/AREA
      URV= TSD*(RV(2)-ZLC)-TSE*(RV(3)-HC)
      WRV= TSC*(RV(3)-HC) -TSF*(RV(2)-ZLC)
      URS= TSD*(RS(2)-ZLC)-TSE*(RS(3)-HC)
      WRS= TSC*(RS(3)-HC)-TSF*(RS(2)-ZLC)
      UC= TSD*(CBAR(2)-ZLC)-TSE*(CBAR(3)-HC)
      WC= TSC*(CBAR(3)-HC)-TSF*(CBAR(2)-ZLC)
      WKH= AC(1)*CC+BC*DC
      UKP=BC**2+CC**2
      WKP=AC(1)**2+DC**2
      TSC=(WKP+WKH) / AREA**2
      TSD= UKP* TSC
      TSE= -WKH* TSC
      TSF=URV+URV
      TSG=WRV+WRV
      TSJ =WKH+WKH
      TSH = TSF*WKH+TSG*UKP
      TSI = TSG*WKH+TSF*WKP
C
      CALL APLCNB (&2080,&9100)
C
C
C...    SECTION 6 ... UNIT NORMAL
C
      Q(3)= ACP(6)+BC*WPRM+DC*UPRM+ACP(2)*WP+ACP(4)*UP
      Q(2)= ACP(5)+AC(1)*UPRM+ CC*WPRM+ACP(1)*UP+ACP(3)*WP
      Q(1) = QNUL
      IF(DABS(Q(2))+DABS(Q(3)).LT.Q1PE6) Q(1)=Q1P
      S(1) = QNUL
      DU= PHI*UP+TSB
      DW= PHI-PHI*WP+TSB
      S(3) = BC*DW + DC*DU
      S(2) = AC(1)*DU + CC*DW
      UN(1) = S(2)*Q(3)-S(3)*Q(2)
      UN(2) = S(3)*Q(1)
      UN(3) = -S(2)*Q(1)
      TEM(1) = DSQRT(UN(1)**2+ UN(2)**2+UN(3)**2)
      TEM(2) = QNUL
      ZLAMN = QNUL
      DO 6010 I = 1,3
      UN(I) = UN(I)/ TEM(1)
      ZM(I) = P(I) - RV(I)
      TEM(2) = TEM(2) + ZM(I)** 2
 6010 ZLAMN = ZLAMN + ZM(I) * UN(I)
      IF(TEM(2).LE.QP0005) GOTO 6020
      TEM(1) = QNUL
      TEM(2) = DSQRT(TEM(2))
      DO 6031 I = 1,3
      DELM(I) = ZM(I)/TEM(2)
 6031 TEM(1) = TEM(1) + UN(I)*DELM(I)
      IF(DABS(TEM(1)).GE..999D0) GO TO 6020
      IF(IUNCNT.LE.0) GO TO 9100
      IUNCNT = IUNCNT - 1
 6051 IF(JSWP.EQ.1) GO TO 6070
      TEM(1) = QNUL
      TEM(2) = QNUL
      DO 6061 I = 1,3
      DELP(I) = PC(I) - P(I)
      TEM(2) = TEM(2) + DELP(I)**2
 6061 TEM(1) = TEM(1) +UN(I)*DELP(I)
      TEM(1) = TEM(1)+TEM(1)
      IF(JROOTS.EQ.1) GO TO 6063
      IF(DS.GT.QP0001) GO TO 6066
      EPSR =     QP7X01
      GO TO 6067
 6066 EPSR = QP5X01
      GO TO 6067
 6063 EPSR = QP4X01
 6067 IF(DMIN1(TEM(2),DABS(TEM(1))).LE.EPSR) GO TO 6071
      ZLAMC = TEM(2) / TEM(1)
      GO TO 6072
 6070 JSWP = 2
 6071 ZLAMC = -Q4500P
 6072 TEM(4) = QNUL
      JSWL = 3
      DO 6073 I = 1,3
      CBAR(I) = P(I) + ZLAMC * UN(I)
      V(I) = RV(I) - CBAR(I)
 6073 TEM(4) = TEM(4) + V(I)**2
      IF(TEM(4).LE.QP0001) GO TO 6082
      TEM(5) = QNUL
      TEM(4) = DSQRT(TEM(4))
      DO 6075 I =1,3
      V(I) = V(I) / TEM(4)
 6075 TEM(5) = TEM(5) +V(I)*UN(I)
      TEM(5)= TEM(5)* ZLAMC
      TEM(1) = QNUL
      DO 6079 I= 1,3
      IF(TEM(5).GT.QNUL)V(I)=-V(I)
 6079 TEM(1) = TEM(1) + V(I) *UN(I)
      IF(DABS(TEM(1)).LT. QP7) GO TO 6082
      TEM(1) = DABS(ZLAMC)
      DO 6081 I = 1,3
      PC(I) = P(I)
 6081 RS(I) = CBAR(I) + TEM(1) * V(I)
      GO TO 6120
 6082 JSWL = 2
      DO 6083 I = 1,3
      PC(I)=P(I)
 6083 RS(I) = ZLAMN * UN(I) + RV(I)
 6120 DS = RS(1)/PB
      IF(JROOTS.EQ.1.OR.DS.GE.QNUL)GO TO 3000
      RS(1) =P(1) *  .990099D-2
      FAC = - FAC
      GO TO 6120
 6020 IUNCNT = 10
C
C
C ...   SECTION 7 DIRECTED DISTANCE
C
      TEM(1) = QNUL
      DO 7021 I = 1,3
 7021 TEM(1) = TEM(1) + DELR(I) * UN(I)
      IF(DABS(TEM(1)).LT.QP4X01) GO TO 2080
      RVLAM = (ZLAMN + T) / TEM(1)
      IF(IOP(IIS)) 7035,7070,7035
 7070 RLAM=RLAM+RVLAM
      GO TO 7075
 7035 IF(DABS(DELR(1)).GT.QP4X01.AND.DABS(PB/DELR(1)).LT.DABS(RVLAM))
     1 GO TO 2080
      TEM(1) = RLAM + RVLAM
      IF(TEM(1) + QP01) 2080,7060,7060
 7060 RLAM = TEM(1)
 7075 IF(DABS(ZLAMN+T).GT.QP0001) GO TO 7080
      IF(IOP(IIS).EQ.0.OR.RLAM.GE.QNUL) RETURN
 7080 IF(IDDCNT.LE.0) GO TO 9100
      IDDCNT = IDDCNT - 1
      ZLAMN = QNUL
      DO 7091  I = 1,3
      RV(I) = RLAM * DELR(I) + R(I)
 7091 RS(I) =  RV(I) - T * UN(I)
      GO TO 6051
 2080 RETURN 1
 9100 RETURN 2
      END

