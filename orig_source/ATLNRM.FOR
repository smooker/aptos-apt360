      SUBROUTINE ATLNRM(U1VAR)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
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
     4J24(1)    ,J50(1)    ,J51(1)    ,INDIR(1) ,IFILLR(209),TE(3)     ,
     5TEK(3)    ,TEL(3)    ,TES(3)    ,TA(3)     ,TAK(3)    ,TAL(3)    ,
     6PMOVE(3)  ,TI(3)     ,TIK(3)    ,TIL(3)    ,U2(3)     ,UVEC(3)   ,
     7VTEM(3)   ,CMOVE(3)  ,EX(3)     ,EY(3)     ,EZ(3)     ,VNUL(3)   ,
     8TM(3)     ,DIR(3)    ,AXIS(3)   ,AXIS1(3)  ,AXIS2(3)  ,AXIS3(3)  ,
     9REFPNT(3) ,RGT(3)    ,FWD(3)    ,UP(3)     ,ZLNORM(3) ,ZLPNT(3)
      COMMON/A2CMMN/TNDIR(3), VA(3)   ,TMVCMP(3) ,P1(3)     ,P2(3)     ,
     1PNT(3)    ,PNT1(3)   ,OLDU1(3)  ,OGLE(3)   ,RZERO(3)  ,TANMOT(3) ,
     2TLEND1(3) ,V(3)      ,CEND(3)   ,DELMOT(3) ,D2(3)     ,DNMOT(3)  ,
     3AX4(3)    ,A         ,B         ,C         ,RA        ,HI        ,
     4ALPHA     ,GAMMA     ,CAGL      ,SAGL      ,COM1      ,COM4      ,
     5COSTH     ,CTOCL     ,DIAM      ,DIF       ,DIFOUT    ,DINC      ,
     6DP        ,DPE       ,DPI       ,DPL       ,DPMAX     ,DP1       ,
     7DPCNT     ,DSMOV     ,D1        ,D2A       ,EL1       ,EL2       ,
     8FIPNT     ,FLIPCK    ,HAFDIA    ,HCHORD    ,OFFSET    ,PROD1     ,
     9PROD2     ,PSI       ,RADNO     ,RC1       ,RDRM      ,RDRN
      COMMON/A2CMMN/ RONE  ,RZEROL    ,SAVE1     ,SIUTH     ,TANGL     ,
     1THETA     ,ALP       ,EPS7      ,VAMAX     ,VL        ,ZDOTC     ,
     2ZGAMMA    ,ZIGN      ,ZL        ,ZL1       ,ZL2       ,ZNPTS     ,
     3TOLBND    ,CENDIS    ,CENLEN    ,CHORD     ,ABCD(2)   ,ACARD(2)  ,
     4SAVE(6)   ,CUTDAT(7) ,TEM(10)   ,TEMP(20)  ,TCDAT(260),QEQUIV(20),
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
     4NREC      ,IRECNO     ,ITRFLG    ,NW        ,ITLSEL
C... A2CMMN END
      COMMON/A2CTDF/        TLHITE(1) ,TANHI(1)  ,TANLO(1)  ,UMAX(1)   ,
     1R1(1)     ,CORRAD(1) ,TCONT(1)  ,TLINC(65)
      DIMENSION  SINL(1), COSL(1), TLLDAT(1)
      EQUIVALENCE(SINL(1),TANHI(1)), (COSL(1),TANLO(1)), (TLLDAT(1),
     1TCONT(1))
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
      IF((MULTAX .NE. 1) .OR. (ICC .NE. 1)) GO TO 61871
      IF((ISTRUP .NE. 1) .OR. (IS .NE. IPS)) GO TO 61871
      IF(JAM .NE. 1) GO TO 61871
      CALL AVSTO(TE,TP(IS))
      CALL AVSUB(VNUL,TA,TN(IS))
      GO TO 39
61871 CONTINUE
C...........
      DIMENSION ZLN(3,7), ZLP(3,7), ZENDIS(7), ITZ(7), AB(2)
      DATA AB(1),AB(2)/4HATLN,4HRM  /
      LSIDE=0
      DIMENSION  U1VAR(1), CAJ24(3)
      CALL ADYNDP(AB(1),4,111111)
      KSEGA1 = 0
      KSEGUP = 0
      KSEGLO = 0
C...KBESTS = 1 INDICATES WORK ONLY WITH BEST SEGMENT AFTER FAILING FIRST
C...25 ITERATIONS. BEST SEG SENT HERE AS NEG VALUE IN IAMDCT.
      KBESTS = 0
      IF(IAMDCT .GE. 0) GO TO 12345
      KBESTS = 1
      KSEGA1 = - IAMDCT
      IAMDCT=0
      KSEGUP = KSEGA1 + 8
      KSEGLO = KSEGA1 - 8
12345 CONTINUE
      KOUNT = 0
      KKKKKK = 0
      IF(J24(IIS) .NE. 2) GO TO 99999
      KSAKA = IPONTR(IIS)
      CALL AVSTO(CANSTO(KSAKA+7),CAJ24)
      CALL AVDOT(TA,CAJ24,ANS)
      ANS = DABS(ANS)
      IF((ANS .LT. QP9999) .AND. (ANS .GT. QP0047)) KKKKKK = 1
99999 CONTINUE
      J = IS + 2
      JFIND = 1
      IT = IBEGIN
      CALL AVSTO(U1VAR,UVEC)
      IF(ITLON(IIS).EQ.0) GO TO 1
  451 IF(IAFL(IIS) + JTLFLG(IIS)) 403,404,401
  403 IF(IPT) 84,1,84
  404 IF(R1(65)) 405,406,405
  405 IF(JTLFLG(IIS).EQ.1) GO TO 1000
      TEMP(1) = Q1P
      TEMP(2) = Q1P
      GO TO 407
  401 CALL AVMULT(UVEC,CUTR(IS),TP(IS))
      CALL AVADD(TP(IS),CUTH(IS),TP(IS))
      CALL AVADD(TP(IS),TE,TP(IS))
      CALL AVSTO(UVEC,TN(IS))
C.....*****
      GO TO 39
  406 TEMP(2) = QNUL
  407  QQK = TEMP(1)*R1(65)
      CALL AVMULT(UVEC,QQK,VTEM)
      CALL AVMULT(TA,TLHITE(65),TP(IS))
      CALL AVADD(VTEM,TP(IS),VTEM)
      CALL AVADD(VTEM,TE,TP(IS))
      GO TO 408
   84 TCONT(65) = -Q1P
   85 N = 8
C.....*****
C...DETERMINE IF CUTTER MIDPOINT IS INSIDE OR OUTSIDE OF SURFACE
   11 ANS = QP5 * CUTDAT(7)
      CALL AVMULT(TA,ANS,VTEM)
      CALL AVADD(VTEM,TE,VTEM)
      CALL AVSUB(CC(IS),VTEM,VTEM)
      CALL AVLENG(VTEM,ANS)
      ANS = DABS(RC(IS)) - ANS
      ITN = 1
      IF(ANS .LT. QNUL) ITN = -1
C...ITN NOW SET TO INDICATE IF CUTTER MIDPOINT IS
C    INSIDE OR OUTSIDE THE SURFACE
C.....*****
   13 IF(TCONT(IT)) 700,42,14
   14 K = 1
      IF(KBESTS .EQ. 0) GO TO 14444
      IF(IT .GT. KSEGUP) GO TO 42
      IF(IT .LT. KSEGLO) GO TO 42
14444 CONTINUE
      DO 15 I=IS,J
      REFPNT(K) = TE(K) + R1(IT)*UVEC(K)+TLHITE(IT)*TA(K)
      OGLE(K)=CC(I)-REFPNT(K)
   15 K = K+1
      IF(ISIGCR(IIS) .NE. 1) GO TO 14001
C
      CALL AVDOT(OGLE,SN(IS),ANS)
      IF(ANS.LT.QNUL) GO TO 14002
      CALL AVSTO(SN(IS),OGLE)
      GO TO 14001
14002 CALL AVSUB(VNUL,SN(IS),OGLE)
14001 CONTINUE
      CALL AVNORM(OGLE,U2,IER)
C.....*****
      IF(IER.NE.0) GO TO 42
  155 IF(TLINC(IT)) 40,16,40
   40 CORRAD(IT) = QNUL
      DO 41 I=1,3
      U2(I) = COSL(IT)*UVEC(I) + SINL(IT)*TA(I)
   41 CORRAD(IT) = CORRAD(IT) + OGLE(I)*U2(I)
      IF(ISIGCR(IIS) .NE. 1) GO TO 45
      CALL AVDOT( U2,SN(IS),ANS)
      IF(DABS(ANS) .GE. QP4X01) GO TO 42
      CALL AVSUB(REFPNT,SP(IS),VTEM)
      CALL AVDOT(VTEM,SN(IS),ANS)
      CORRAD(IT)=QNUL
      K=IS
      DO 46 I=1,3
      CORRAD(IT)=CORRAD(IT)+(SP(K)+ANS*SN(K)-REFPNT(I))*U2(I)
   46 K=K+1
   45 IF(CORRAD(IT)+QP5X01) 42,43,43
   42 IT = IT+N
      GO TO 13
   16 IF((IPL(IIS).EQ.0) .AND. (ISIGCR(IIS).LE.0)) GO TO 1667
      CALL AVDOT(OGLE,SN(IS),ANS)
      IF(ANS) 1665,1667,1664
 1664 CALL AVSTO(SN(IS),OGLE)
      GO TO 1666
 1665 CALL AVSUB(VNUL,SN(IS),OGLE)
 1666 CALL AVSTO(OGLE,U2)
 1667 CALL AVDOT(OGLE,TA,COM1)
      CALL AVDOT(OGLE,OGLE,COM4)
      COM4=COM4-COM1*COM1
C.....*****
      IF(COM4) 18,18,19
   18 IF(IT-57) 21,101,21
  101 TANGL = -Q1PE30
      CALL AVSTO(TA,U2)
C.....*****
      GO TO 25
    1 TEMP(2) = QNUL
      CALL AVSTO(TE,TP(IS))
  408 CALL AVSUB(CC(IS),TP(IS),TN(IS))
      ZZLL = TEMP(1)*TEMP(2) + Q4P
      LL = ZZLL
      CALL AVNORM(TN(IS),TN(IS),IER)
C.....*****
      IF(J24(IIS).EQ.2) GO TO 4448
      IF(IER.EQ.0) GO TO 8
    3 IF(TEMP(2)) 409,409,410
  409 CALL AERR(1061)
  410 TEMP(LL) = -Q1P
      GO TO 417
    8 IF(TEMP(2)) 411,411,412
  411 IF(JTN(IIS)) 413,413,414
  413 CALL AVDOT(TN(IS),SN(IS),ANS)
      IF(ANS) 39,39,340
  414 CALL AVDOT(TN(IS),TNL(IS),ANS)
      IF(ANS) 340,39,39
  340 CALL AVSUB(VNUL,TN(IS),TN(IS))
      GO TO 39
  412 IF(JTN(IIS).GT.0) GO TO 416
  415 CALL AVDOT(TN(IS),SN(IS),ANS)
      TEMP(LL) = DABS(ANS)
      GO TO 417
  416 CALL AVDOT(TN(IS),TNL(IS),ANS)
      TEMP(LL) = DABS(ANS)
  417  IF (TEMP(1)) 418,420,420
  418 IF( TEMP(3) - TEMP(5)) 419,411,411
  419 TEMP(1) = Q1P
      GO TO 406
  420 TEMP(1) = -Q1P
      GO TO 407
   19 COM4 = DSQRT(COM4)
      IF(DABS(COM1/COM4) - Q1000P) 20,18,18
   20 TANGL = -COM1/COM4
      GO TO 22
   21 TANGL = Q1PE30
      CALL AVSUB(VNUL,TA,U2)
      GO TO 25
   22 CALL AVDOT(UVEC,OGLE,ANS)
      IF(ANS) 23,25,25
   23 TANGL = -TANGL
      DO 24 I=1,3
   24 U2(I) = -U2(I)
   25 CONTINUE
C.....*****
      IF(TANLO(IT)-TANGL)26,28,28
   26 IF(JTN(IIS)) 27,42,27
   27 N=-8
      GO TO 42
   28 IF(TANHI(IT)-TANGL) 29,29,42
   29 CALL AVSTO(U2,ZLNORM)
   31 CALL AVMULT(U2,CORRAD(IT),VTEM)
      CALL AVADD(REFPNT,VTEM,ZLPNT)
C.....*****
C
      IF(JTN(IIS).GT.0) GO TO 237
   33 KOUNT = KOUNT + 1
C...STORE TENTATIVE TP,TN,IT, AND GO TO EXAMINE NEXT SEGMENT
      CALL AVSTO(ZLNORM,ZLN(1,KOUNT))
      CALL AVSTO(ZLPNT,ZLP(1,KOUNT))
      CALL AVSUB(CC(IS),ZLPNT,VTEM)
      CALL AVLENG(VTEM,ANS)
C.....*****
      CENDIS = DABS(RC(IS)) - ANS
      IF(ISIGCR(IIS).NE.1) GO TO 333
      CALL AVSUB(SP(IS),ZLPNT,VTEM)
      CALL AVDOT(VTEM,ZLNORM,CENDIS)
  333 ZENDIS(KOUNT)=CENDIS
C
   36 JFIND = -1
C
C.....*****
      ITZ(KOUNT) = IT
C.....*****
      GO TO 42
  237 CALL AVDOT(TNL(IS),ZLNORM,ANS)
      AA1 = -Q1P
      IF(ANS)601,33,33
  601 CALL AVDOT(TNL(IS),TA,ANS)
      IF(DABS(ANS)-QP9999)33,33,603
  603 IF(KOUNT .GT. 0) GO TO 42
      IF(IT - 57) 604,605,604
  604 IT = 57
      ITSEG(IIS) = 57
      CALL AVMULT(U1(IS),R1(IT),VTEM)
      CALL AVMULT(TA,TLHITE(IT),TP(IS))
      CALL AVADD(TE,VTEM,VTEM)
      CALL AVADD(VTEM,TP(IS),TP(IS))
      GO TO 39
  605 ITSEG(IIS) = IBEGIN
      CALL AVSTO(TE,TP(IS))
      GO TO 39
   39 CONTINUE
C.....*****
      RETURN
   43 IF(CORRAD(IT)-UMAX(IT)) 44,42,42
   44 CALL AVMULT(UVEC,SINL(IT),ZLNORM)
      CALL AVMULT(TA,COSL(IT),VTEM)
      CALL AVSUB(ZLNORM,VTEM,ZLNORM)
      IF(CORRAD(IT).LT.QP01*UMAX(IT)) GO TO 31
      IF(IPL(IIS).EQ.1) CORRAD(IT) = UMAX(IT)
      GO TO 31
  700 IF(JFIND .LT. 0) GO TO 650
      IF(KBESTS .EQ. 0) GO TO 701
      IF(IT .GT. KSEGUP) GO TO 650
      IF(IT .LT. KSEGLO) GO TO 650
  701 TEMP(1) = Q2P*   (DFLOAT(JTN(IIS))) - Q1P
      CALL AVMULT(SN(IS),TEMP,TN(IS))
      CALL AVDOT(TA,TN(IS),ANS)
      COM1 = -ANS
      COM4 = DSQRT(DABS(Q1P - (COM1 * COM1)))
      IF(COM4 - QP001) 702,702,703
  702 IF(COM1) 604,605,605
  703 TANGL = COM1/COM4
      IT = IBEGIN
  704 IF(TCONT(IT)) 3,705,706
  705 IT = IT+8
      GO TO 704
  706 IF(TLINC(IT)) 705,707,705
  707 IF(TANGL-TANHI(IT)) 705,708,708
  708 CALL AVMULT(TA,TLHITE(IT),VTEM)
      CALL AVADD(TE,VTEM,TP(IS))
      CALL AVMULT(UVEC,R1(IT),VTEM)
      CALL AVADD(VTEM,TP(IS),TP(IS))
      CALL AVMULT(TN(IS),CORRAD(IT),VTEM)
      CALL AVADD(VTEM,TP(IS),TP(IS))
      GO TO 39
 1000  CONTINUE
      IF(J40.EQ.1) GO TO 2000
 2010 CONTINUE
C.....*****
       CALL AVMULT(UVEC,R1(65),VTEM)
       CALL AVMULT(TA,TLHITE(65),TP(IS))
       CALL AVADD (VTEM,TP(IS),VTEM)
       CALL AVADD (VTEM,TE,TP(IS))
      IF(IAMDCT.LT.20) GO TO 1001
      CALL AVMULT(SN(IS),RC(IS),VTEM)
      CALL AVSUB(SP(IS),VTEM,CC(IS))
 1001 CONTINUE
       CALL AVSUB (TP(IS),CC(IS),TN(IS))
       CALL AVNORM(TN(IS),TN(IS),IER)
       IF(IER.NE.0) GO TO 1005
 1002  CALL AVDOT(TN(IS),UVEC,ANS)
       IF(ANS.LT.QNUL) CALL AVSUB(VNUL,TN(IS),TN(IS))
       GO TO 39
 1005  CONTINUE
C.....*****
       CALL AVSTO (SN(IS),TN(IS))
       GO TO 1002
 4448 CALL AVDOT(TN(IS),SN(IS),ANS)
      IF(DABS(ANS).LT.QP01) CALL AVSTO(SN(IS),TN(IS))
      GO TO 8
 2000 CALL AVCROS(SN(IS),TA,VTEM)
      CALL AVCROS(TA,VTEM,TN(IS))
      CALL AVNORM(TN(IS),VTEM,IER)
      IF(IER.EQ.1) GO TO 2010
      CALL AVDOT(TN(IS),SN(IS),ANS)
      CALL AVSTO(SN(IS),TN(IS))
      IF((JTN(IIS).EQ.1).AND.(ANS.GT.QNUL)) GO TO 2020
      IF((JTN(IIS).EQ.0).AND.(ANS.LT.QNUL)) GO TO 2020
      CALL AVSUB(VNUL,VTEM,VTEM)
      CALL AVSUB(VNUL,TN(IS),TN(IS))
 2020 CALL AVMULT(VTEM,RA,VTEM)
      CALL AVMULT(TA,HI,TP(IS))
      CALL AVADD(TP(IS),TE,TP(IS))
      CALL AVADD(TP(IS),VTEM,TP(IS))
      GO TO 39
  650 CONTINUE
C... IF ONLY ONE LINE-UP, STORE ZLNORM,ZLPNT,ITSEG AND EXIT
      IF(KOUNT .GT. 1) GO TO 655
      KAMIN = 1
      IF(LSIDE.GT.0) GO TO 685
      LSIDE=1
      CALL AVDOT(SN(IS),TA,ANS)
      IF(DABS(ANS).LT.0.98D0) GO TO 685
      CALL AVDOT(ZLN(1,1),TN(IS),ANS)
      IF(ANS.GE.QNUL) GO TO 685
      CALL AVSUB(VNUL,UVEC,UVEC)
      IT=IBEGIN
      GO TO 13
C SEE IF ALL LINE-UP TOOL POINTS ON THE SAME SIDE OF THE SURFACE
C     KSIDE = 1      ALL ON SAME SIDE OF SURFACE
C    KSIDE = -1    ALL NOT ON SAME SIDE OF SURFACE
  655 KSIDE = 1
      IF(ISTRUP .EQ. 0) GO TO 675
      DO 665 KKK=2,KOUNT
      IF((ZENDIS(KKK)*ZENDIS(1)) .LT. QNUL) KSIDE=-1
  665 CONTINUE
  675 IF(KSIDE .LT. 0) GO TO 690
C... LINE-UP TOOL POINTS ALL ON THE SAME SIDE
      KAMAX = 1
      KAMIN = 1
      DO 680 J=2,KOUNT
      IF(DABS(ZENDIS(J)).GT.DABS(ZENDIS(KAMAX)))KAMAX=J
      IF(DABS(ZENDIS(J)).LT.DABS(ZENDIS(KAMIN)))KAMIN=J
  680 CONTINUE
      IF(ISTRUP .EQ. 0) GO TO 685
      IF((ZENDIS(1)*(DFLOAT(ITN))*ZIGN) .GE. QNUL) GO TO 685
  696 CALL AVSTO(ZLN(1,KAMAX),TN(IS))
      CALL AVSTO(ZLP(1,KAMAX),TP(IS))
      ITSEG(IIS) = ITZ(KAMAX)
      J = KAMAX
      GO TO 39393
  685 CALL AVSTO(ZLN(1,KAMIN),TN(IS))
      CALL AVSTO(ZLP(1,KAMIN),TP(IS))
      ITSEG(IIS) = ITZ(KAMIN)
      J = KAMIN
      GO TO 39393
C ... LINE-UP TOOL POINTS NOT ALL ON SAME SIDE
  690 KAMAX=1
      KAMIN=1
      DO 695 JJ=2,KOUNT
      IF(ZENDIS(JJ) .GT. ZENDIS(KAMAX)) KAMAX=JJ
      IF(ZENDIS(JJ) .LT. ZENDIS(KAMIN)) KAMIN=JJ
  695 CONTINUE
      IF(((DFLOAT(ITN)) * ZIGN) .GT. QNUL) GO TO 685
      GO TO 696
39393 IF(KOUNT .NE. 2) GO TO 39
      IF(IPL(IIS) .NE. 1) GO TO 39
      IF(IS .NE. IPS) GO TO 39
      IF(JTN(IIS) .NE. 0) GO TO 39
      CALL AVDOT(TN(IS),SN(IS),ANS)
      IF(ANS .LT. QNUL) GO TO 39
      IF(J .EQ. 1) JJ = 2
      IF(J .EQ. 2) JJ = 1
      CALL AVSTO(ZLN(1,JJ),TN(IS))
      CALL AVSTO(ZLP(1,JJ),TP(IS))
      ITSEG(IIS) = ITZ(JJ)
      GO TO 39
      END

