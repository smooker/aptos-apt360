      SUBROUTINE ARLDS
      IMPLICIT REAL*8 (A-H,O-Z)
C     *** THIS PROGRAM REPLACED FOR VERSION 4, MODIFICATION 2 ***
C2433  RULED SURFACE FOR SYSTEM/360 SECTION 2
C     COMMON, DIMENSION AND EQUIVALENCE FOR ARLDSR
C... A2CMMN START
      COMMON/A2CMMN/ SP(3) ,SN(3)     ,TP(3)     ,TN(3)     ,SNK(3)    ,
     1SNL(3)    ,SPK(3)    ,SPL(3)    ,TNK(3)    ,TNL(3)    ,TPK(3)    ,
     2TPL(3)    ,PLNV(3)   ,CC(3)     ,U1(3)     ,CUTH(3)   ,SFVCT(3)  ,
     3VNDIR(3)  ,VMD(3)    ,VT(3)     ,TEE(3)    ,SLX(3)    ,DPLAN(3)  ,
     4S(1)      ,RC(1)     ,PLND(1)   ,TH(1)     ,CSD(1)    ,Z(1)      ,
     5EPS1(1)   ,EPS2(1)   ,EPS3(1)   ,EPS4(1)   ,EPS6(1)   ,EPS8(1)   ,
     6TAU(1)    ,TAU1(1)   ,TAU2(1)   ,STCK(1)   ,STCKN(1)  ,STCK1(1)  ,
     7STCK2(1)  ,COS1(1)   ,DPMX1(1)  ,CPLFL(1)  ,CPTST(1)  ,PLNCS(1)  ,
     8PLND1(1)  ,PLTST(1)  ,PAST(1)   ,SPAST(1)  ,ADCS(1)   ,H(1)      ,
     9CUTR(1) ,AFILLR(500) ,IAFL(1)   ,IPONTR(1) ,IFAR(1)   ,IPL(1)
      COMMON/A2CMMN/IUNFL(1),ISFTYP(1),ITLON(1)  ,ISVFL(1)  ,IFL4(1)   ,
     1IOP(1)    ,IOPSET(1) ,JIOPS(1)  ,NOTAN(1)  ,JENT(1)   ,JU1(1)    ,
     2ISIGCR(1) ,ITSEG(1)  ,JTLFLG(1) ,LOFS(1)   ,LIMFL(1)  ,ICSTR(1)  ,
     3JTN(1)    ,ICHKCT(1) ,J20(1)    ,J21(1)    ,J22(1)    ,J23(1)    ,
     4 J24(1), J50(1), J51(1), INDIR(1), IFILLR(209), ADUM(536) ,
     5IS        ,IIS       ,IT        ,IIT       ,IPS       ,IIPS      ,
     6IDS       ,IIDS      ,ICS       ,IICS      ,IGS       ,IIGS      ,
     7ICDEFL    ,ICDEFS    ,IAUTPS    ,IGO       ,ICRDCT    ,ICUT      ,
     8IGTFLG    ,INOPS     ,ISRCH     ,IOFSET    ,ISTRUP    ,I3DFLG    ,
     9MULOUT    ,MULTAX    ,NUMAX     ,NUMSFS    ,NUMSUR    ,IGOUG
      COMMON/A2CMMN/ IPDPL ,NUMDIM    ,IRSTRT    ,ICSCNT    ,I3        ,
     1I31       ,J         ,JA        ,JL        ,JS        ,JT        ,
     2KC        ,KND       ,KR        ,L         ,INCFS     ,NP        ,
     3IBEGIN    ,IFAR1     ,IK        ,INS1      ,ITNFLG    ,IVAMAX    ,
     4IWS       ,IIWS      ,IZ        ,NEXT1     ,NEXT2     ,NPTS      ,
     5NUMPT1    ,JAM       ,JAP       ,JTUSED    ,IFRL      ,N         ,
     6M         ,MDIC      ,JBR       ,JCKR      ,JCPR      ,JCR       ,
     7JDR       ,JGR       ,JMIN      ,JMINR     ,JPR       ,JPXR      ,
     8JTR       ,JCNT1     ,JCNT2     ,JCNT3     ,JSW       ,JTKF      ,
     9LISV      ,LSV       ,IPT       ,JFIND     ,IC        ,ICC
      COMMON/A2CMMN/  IL   ,K         ,NUMPTS    ,IAMDCT    ,IFL2      ,
     1J5        ,J6        ,JW6       ,J10       ,J12       ,J13       ,
     2J40       ,J43       ,J54       ,J103      ,PROBUF(100)          ,
     3CANSTO(2000) , IER   ,INSTR1    ,INSTR2    ,NWDS      ,ICL       ,
     4NREC      ,IRECNO    ,ITRFLG    ,NW        ,IDUMMY
C... A2CMMN END
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
C     VARIABLES NOT IN SECTION 2 COMMON
      DIMENSION VNUL(3)
      DIMENSION P(1),W(1),F(1),PP(1),WP(1),VP(1),IFST(1),ZN(1),SL(1),
     1R3(1),R2(1),R(1),DELTA(1),ZLAMBD(1)
      EQUIVALENCE(CANSTO(1),P(1),W(1),F(1),PP(1),WP(1),VP(1))
      EQUIVALENCE (CANSTO(18),R2(3),R3(6),R(9),SL(12),ZN(15),ZLAMBD(16),
     1DELTA(17))
C     VARIABLES NOT IN COMMON
      DIMENSION Q1(3),W1(3),V1(3),Q2(3),W2(3),V2(3),D(3),P0(3),CP(3),
     1X(3),Y(3),U(3),E(3),DC(3),DCP(3),SC(3),DV(3),DVP(3)
     1,FC(3) , UT1(3) , T1(3) , S1(3) , A(3) , B(3)
      DIMENSION SAVESP(3)
C
C     STORE TOOL NORMAL LOCALLY
C
  100 D(1) = TN(IS  )
      D(2) = TN(IS+1)
      D(3) = TN(IS+2)
C
C     STORE TOOL POINT LOCALLY
C
      P0(1) = TP(IS  )
      P0(2) = TP(IS+1)
      P0(3) = TP(IS+2)
C
C     SAVE
C
      ICSS = IC
      IOPS = IOP(IIS)
      J24SS = J24(IIS)
      CALL AVSTO(SP(IS),SAVESP)
C
C     INITIALIZE
C
      IOP(IIS) =  1
      IGUESS = 0
      LOOP = 25
      EP2 = 1.D-5
C
C     COMPUTE VARIABLE SUBSCRIPTS
C
C200  **** CARDS 1240 - 1370 360 VERSION
  200 CALL ASTOR(CANSTO(IC+3),8,IC1,2)
      LSD=IC+IC1+4
      CALL ASTOR(CANSTO(IC+4),8,IC1,2)
      LS1M3=IC+IC1-1
      CALL ASTOR(CANSTO(IC+5),8,IC1,2)
      LP=IC+IC1+2
      CALL ASTOR(CANSTO(IC+6),8,IC1,2)
      LW=IC+IC1+2
      CALL ASTOR(CANSTO(IC+7),8,IC1,2)
      LV=IC+IC1+2
      CALL ASTOR(CANSTO(IC+8),8,IC1,2)
      LS2M3=IC+IC1-1
C
C     COMPUTE UNIT VECTOR DV  PARALEL TO CHORD(1)
C
      Q1(1) = P(LP)
      Q1(2) = P(LP+1)
      Q1(3) = P(LP+2)
      W1(1) = W(LW)-Q1(1)
      W1(2) = W(LW+1)-Q1(2)
      W1(3) = W(LW+2)-Q1(3)
      CALL AVNORM(W1,DV,IER)
C
C     STORE LENGTH OF DV  IN EP5
C
      CALL AVLENG(W1,EP5)
C
C     STORE VECTOR (1) LOCALLY
C
      V1(1) = F(LV)
      V1(2) = F(LV+1)
      V1(3) = F(LV+2)
C
C     BRANCH TO 201 IF POINT AND CURVE FORMAT (FORMAT A )
C     202 IF TWO CURVE FORMAT (FORMAT B )
C
      CALL ASTOR(CANSTO(IC+3),8,IC1,2)
      IF(IC1-5) 202,201,202
C
C     FORMAT A  STORE POINT IN CP AND ZERO OUT DCP
C
  201 CP(1) = PP(LS2M3+3)
      CP(2) = PP(LS2M3+4)
      CP(3) = PP(LS2M3+5)
      DCP(1) = 0.D0
      DCP(2) = 0.D0
      DCP(3) = 0.D0
C
      GO TO 300
C
C     FORMAT B  COMPUTE VARIABLE SUBSCRIPTS FOR SECOND CURVE
C
C202  **** CARDS 1530 - 1580 360 VERSION
  202 CALL ASTOR(CANSTO(IC+9),8,IC1,2)
      LPP=IC+IC1+2
      CALL ASTOR(CANSTO(IC+10),8,IC1,2)
      LWP=IC+IC1+2
      CALL ASTOR(CANSTO(IC+11),8,IC1,2)
      LVP=IC+IC1+2
C
C     COMPUTE UNIT VECTOR DVP PARALEL TO CHORD(2)
C
      Q2(1) = PP(LPP)
      Q2(2) = PP(LPP+1)
      Q2(3) = PP(LPP+2)
      W2(1) = WP(LWP)   -Q2(1)
      W2(2) = WP(LWP+1) -Q2(2)
      W2(3) = WP(LWP+2) -Q2(3)
      CALL AVNORM(W2,DVP,IER)
C
C     STORE LENGTH OF DVP IN EP6
C
      CALL AVLENG(W2,EP6)
C
C     STORE VECTOR(2) LOCALLY
C
      V2(1) = VP(LVP)
      V2(2) = VP(LVP+1)
      V2(3) = VP(LVP+2)
C
C     IF FIRST ENTRY,CHOOSE FIRST SET OF PARAMETERS DELTA,LAMBDA
C     FROM TABLE AT 1000,OTHERWISE USE THE LAST  COMPUTED PARAMETERS
C
300   IF(CANSTO(LSD)) 400,1000,400
C
C     TAKE DOT PRODUCT OF TOOL NORMAL AND SURFACE NORMAL
C
  400 G = D(1)*ZN(LSD)+D(2)*ZN(LSD+1)+D(3)*ZN(LSD+2)
C
C     IF COSINE OF ANGLE LESS THAN .01,CHOOSE NEW PARAMETERS
C
      IF(DABS(G)-1.D-2) 1100,1100,401
C
C     SUM IS THE DISTANCE BETWEEN THE POINT OF INTERSECTION OF TOOL
C     NORMAL WITH THE PLANE AND THE SURFACE POINT
C     SIGMA IS THE COSINE OF THE ANGLE BETWEEN TOOL NORMAL AND
C     NORMALIZED(TOOL POINT-SURFACE POINT)
C
  401 X(1)=P0(1)-R(LSD)
      X(2)=P0(2)-R(LSD+1)
      X(3)=P0(3)-R(LSD+2)
      XLL=(-X(1)*ZN(LSD)-X(2)*ZN(LSD+1)-X(3)*ZN(LSD+2))/G
      CALL AVNORM(X,A,IER)
      X(1)=X(1)+XLL*D(1)
      X(2)=X(2)+XLL*D(2)
      X(3)=X(3)+XLL*D(3)
      SUM = DABS(X(1))+DABS(X(2))+DABS(X(3))
      SIGMA = DABS(A(1)*D(1)+A(2)*D(2)+A(3)*D(3))
C
C     DECLARE CONVERGENCE IF EITHER ANGLE OR DISTANCE IS LESS THAN
C     TEST QUANTITIES(510) OTHERWISE(600)
C
      IF(SIGMA - .99995D0) 509,509,510
 509  IF(SUM-EP2)510,510,600
C
C     TEST FOR SIGN OF DIRECTED DISTANCE
C
  510 IF(IOPS)512,512,511
  511 IF(XLL)513,512,512
C
C     COMPUTATIONS SUCCESSFUL STORE DATA FOR RETURN
C
  512 IER = 0
      S(IS) = XLL
      SN(IS) = ZN(LSD)
      SN(IS+1) = ZN(LSD+1)
      SN(IS+2) = ZN(LSD+2)
      SLX(IS  ) = SL(LSD  )
      SLX(IS+1) = SL(LSD+1)
      SLX(IS+2) = SL(LSD+2)
      GO TO 1600
C
C     UNABLE TO COMPUTE DIRECTED DISTANCE
C
  513 IER = 1
      GO TO 1600
C
C     UPDATE COUNTER  PICK UP NEW PARMATERS (1100)IF COUNTER EXHAUSTED
C
  600 LOOP = LOOP-1
      IF (LOOP) 1100,1100,700
C
C     ALPH AND BETA ARE LINEAR CORRECTION TO DELTA AND LAMBDA
C
  700 CSL = R3(LSD)**2+R3(LSD+1)**2+R3(LSD+2)**2
      CSM = R3(LSD)*R2(LSD)+R3(LSD+1)*R2(LSD+1)+R3(LSD+2)*R2(LSD+2)
      CSN = R2(LSD)**2+R2(LSD+1)**2+R2(LSD+2)**2
      SMA = R3(LSD)*X(1)+R3(LSD+1)*X(2)+R3(LSD+2)*X(3)
      SMB = R2(LSD)*X(1)+R2(LSD+1)*X(2)+R2(LSD+2)*X(3)
      DELT = CSL*CSN-CSM**2
      IF(1.D-5 - DELT)701,1100,1100
  701 ALPH = (SMA*CSN-SMB*CSM)/DELT
      BETA = (SMB*CSL-SMA*CSM)/DELT
      DELTA(LSD) = DELTA(LSD)+.8*ALPH
      ZLAMBD(LSD) = ZLAMBD(LSD)+.8*BETA
  800 CONTINUE
C
C     PROCESS ONE CURVE IF FORMAT A(920),TWO CURVES OTHERWISE (910)
C
900   CALL ASTOR(CANSTO(ICSS+3),8,IC1,2)
      IF(IC1-5) 920,920,910
C
C FIND POINT CP AND DERIV WRT DELTA DCP ON 2ND COMPONENT SURFACE
C
  910 DO 911 I=1,3
      X(I)=Q2(I)+DELTA(LSD)*W2(I)
  911 B(I)=DVP(I)
      TN(IS  ) = V2(1)
      TN(IS+1) = V2(2)
      TN(IS+2) = V2(3)
      EP = EP6
      IC = LS2M3
      CALL AVCROS(V2,DVP,SC)
      CALL AVNORM(SC,FC,IER)
      CALL AVLENG(SC,SIGN1)
      IF (IER) 1100,27,1100
   27 GO TO 930
  915 CP(1) = E(1)
      CP(2) = E(2)
      CP(3) = E(3)
      DCP(1) = DC(1)
      DCP(2) = DC(2)
      DCP(3) = DC(3)
C
C FIND POINT E AND DERIV WRT DELTA DC ON 1ST COMPONENT SURFACE
C
  920 DO 921 I=1,3
      X(I)=Q1(I)+DELTA(LSD)*W1(I)
  921 B(I)=DV(I)
      TN(IS  ) = V1(1)
      TN(IS+1) = V1(2)
      TN(IS+2) = V1(3)
      IC = LS1M3
      EP = EP5
      CALL AVCROS(V1,DV,SC)
      CALL AVNORM(SC,FC,IER)
      CALL AVLENG(SC,SIGN1)
      IF (IER) 1100,930,1100
C
  930 TP(IS  ) = X(1)
      TP(IS+1) = X(2)
      TP(IS+2) = X(3)
8000  CALL ADDSTR
      IF(IOP(IIS).EQ.1) GOTO 8001
      IOP(IIS) = 1
      IF(IER) 933,933,1100
8001  IF(IER.EQ.0) GOTO 933
      IOP(IIS) = 0
      GOTO 8000
  933 E(1) = TP(IS  )+S(IS)*TN(IS  )
      E(2) = TP(IS+1)+S(IS)*TN(IS+1)
      E(3) = TP(IS+2)+S(IS)*TN(IS+2)
      SP(IS)=E(1)
      SP(IS+1)=E(2)
      SP(IS+2)=E(3)
C     ******************************************************************
C     CODE THRU 10000 ADDED TO SET PROPER J24(IIS) SWICH FOR CALL
C     TO ANRMAL R.E. LYMAN 3/24/69
      CALL ASTOR(CANSTO(IC+2),8,IC1,2)
      IC1 = IC1 - 3000
      IF(IC1.LE.0) GOTO 9040
      IF(IC1-15)9030,9100,9000
9000  IF(IC1-50)9040,9020,9010
9010  IF(IC1-53)9020,9100,9040
9020  IC1 = IC1 - 34
9030  GOTO(9040,9050,9050,9060,9060,9070,9070,9080,9070,9070,9040,9040,
     *9090,9070,9100,9110,9040,9040,9100),IC1
9040  CALL AERR(1401)
9050  J24(IIS) = 1
      GOTO 10000
9060  J24(IIS) = 2
      GOTO 10000
9070  J24(IIS) = 3
      GOTO 10000
9080  J24(IIS) = 4
      GOTO 10000
9090  J24(IIS) = 5
      GOTO 10000
9100  CALL AERR(1402)
9110  J24(IIS) = 7
10000 CONTINUE
C     ******************************************************************
C     SET IPONTR(IIS) TO PICK UP CORRECT IC IN ANRMAL
      IPNTRS=IPONTR(IIS)
      IPONTR(IIS)=IC-1
      CALL ANRMAL
C     RESTORE IPONTR(IIS)
      IPONTR(IIS)=IPNTRS
      CALL AVCROS(FC,SN(IS),UT1)
      CALL AVNORM(UT1,T1,IER)
      DOT=T1(1)*B(1)+T1(2)*B(2)+T1(3)*B(3)
      IF (DOT) 17,17,18
 18   SIG=1.0
      GO TO 19
 17   SIG=-1.0
19    CALL AVCROS(T1,TN(IS),S1)
      CALL AVNORM(S1,UT1,IER)
      CALL AVLENG(S1,SIGN2)
      DO 951 I=1,3
 951  DC(I)=T1(I)*SIG*SIGN1*EP/SIGN2
      IF(IC-LS2M3) 980,915,980
C
C
C
C     R3 AND R2 ARE PARTIAL DERIVATIVES WRT DELTA AND LAMBDA RESPECTIVEL
C
  980 R3(LSD) = DC(1)+ZLAMBD(LSD)*(DCP(1)-DC(1))
      R3(LSD+1) = DC(2)+ZLAMBD(LSD)*(DCP(2)-DC(2))
      R3(LSD+2) = DC(3)+ZLAMBD(LSD)*(DCP(3)-DC(3))
      R2(LSD) = CP(1)-E(1)
      R2(LSD+1) = CP(2)-E(2)
      R2(LSD+2) = CP(3)-E(3)
      CALL AVNORM(R3(LSD),ZN(LSD),IER)
      IF(IER)981,981 ,1100
981   CALL AVNORM(R2(LSD),SL(LSD),IER)
      IF(IER)982,982 ,1100
982   CALL AVCROS(ZN(LSD),SL(LSD),SC)
C
C     ZN(LSD) CONTAINS THE SURFACE NORMAL
C
      CALL AVNORM(SC,ZN(LSD),IER)
      IF(IER)983,983 ,1100
C
C     R(LSD) CONTAINS THE SURFACE POINT
C
  983 R(LSD)   =  E(1)+ZLAMBD(LSD)*R2(LSD)
      R(LSD+1) =  E(2)+ZLAMBD(LSD)*R2(LSD+1)
      R(LSD+2) =  E(3)+ZLAMBD(LSD)*R2(LSD+2)
      GO TO 400
C
C     SET IFST=1 TO INDICATE SUBSEQUENT ENTRIES
C
1000  CANSTO(LSD) = Q1P
 1100 LOOP = 25
C
C     THE CHOICE OF PARAMETERS ISMADE BASED ON THE VALUE OF IGUESS
C
      IGUESS = IGUESS+1
1200  ZLAMBD(LSD) =.5D0
      IF(IGUESS-7) 1210,1210,1209
 1209 IER = 1
      GO TO 1600
 1210  GO TO(1216,1217,1213,1212,1211,1214,1215),IGUESS
1211  DELTA(LSD) = .5D0
      GO TO 800
1212  DELTA(LSD) = .999D0
      GO TO 800
1213  DELTA(LSD) = .001D0
      GO TO 800
1214  DELTA(LSD) = .75D0
      GO TO 800
1215  DELTA(LSD) = .25D0
      GO TO 800
1216  DELTA(LSD) = -.2D0
       GO TO 800
1217  DELTA(LSD) = 1.2D0
       GO TO 800
 1600 TP(IS  ) = P0(1)
      TP(IS+1) = P0(2)
      TP(IS+2) = P0(3)
      TN(IS  ) = D(1)
      TN(IS+1) = D(2)
      TN(IS+2) = D(3)
      CALL AVSTO(SAVESP,SP(IS))
      IOP(IIS) = IOPS
      IC = ICSS
      J24(IIS) = J24SS
 1700 RETURN
       END

