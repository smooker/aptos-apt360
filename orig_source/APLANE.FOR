      SUBROUTINE APLANE
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
     2J40     ,J43     ,J54     ,J103
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
      COMMON/TAUMD2/               SAVTT,SAVTO,SAVTI,SAVT1,SAVT2,SAVT3,
     1SAVT4,SAVT6,SAVT8,ISMATA, IISMAT,KCHNGE, KON, KST
       DIMENSION AB(14)
      DATA AB( 1),AB( 2)/4HAPLA,4HNETP/,    AB( 3),AB( 4)/4HAPLA,4HNE01/
     1,    AB( 5),AB( 6)/4HAPLA,4HNE02/,    AB( 7),AB( 8)/4HAPLA,4HNE03/
     2,    AB( 9),AB(10)/4HAPLA,4HNE04/,    AB(11),AB(12)/4HAPLA,4HNE05/
     3,    AB(13),AB(14)/4HAPLA,4HNEEX/
      KDESPR = 0
      KTANSF = 0
      KCHNGE = 0
      KAERR = 0
      IF(ISFTYP(IIS) .NE. 4) GO TO 2222
      IF(TH(IS) .NE. QNUL) GO TO 2222
      KTANSF = 41
      IF(IFL4(IIS) .EQ. 1) KTANSF = 1
      IF(ITSEG(KTANSF) .NE. 9) GO TO 2222
C...PSTAN, TANTO, S TO TAN SURF CALCULATED FROM TE
      KCHNGE = 1
      KON = ITLON(IIS)
      KST = ISFTYP(IIS)
      ISMATA = IS
      IISMAT = IIS
C...
      SAVTT = TAU(IS)
      SAVTO = TAU1(IS)
      SAVTI = TAU2(IS)
      SAVT1 = EPS1(IS)
      SAVT2 = EPS2(IS)
      SAVT3 = EPS3(IS)
      SAVT4 = EPS4(IS)
      SAVT6 = EPS6(IS)
      SAVT8 = EPS8(IS)
C...
C...
      ITLON(IIS) = 0
      ISFTYP(IIS) = 3
C...
      TAU(IS) = TAU(IS) * QP001
      TAU1(IS) = TAU1(IS) * QP001
      TAU2(IS) = TAU2(IS) * QP001
      EPS1(IS) = EPS1(IS) * QP001
      EPS2(IS) = EPS2(IS) * QP001
      EPS3(IS) = EPS3(IS) * QP001
      EPS4(IS) = EPS4(IS) * QP001
      EPS6(IS) = EPS6(IS) * QP001
      EPS8(IS) = EPS8(IS) * QP001
 2222 CONTINUE
C***APLANE TP***
      CALL ADYNDP(AB(1),3,111100)
C...
    9 CALL ACHECK
      KER846 = 0
C...
      IF((KCHNGE .EQ. 1) .AND. (J50(IIS) .EQ. 1)) GO TO 1
C***APLANE 01***
       CALL ADYNDP (AB(3),5,110000)
C...
      IF(JCKR)1,14,1
C...
    1 CONTINUE
C***APLANE 02***
       CALL ADYNDP(AB(5),5,110000)
      IF(ICHKCT(IIS) .NE. 0) GO TO 125
C...
  320 CALL ACENTR
C...
      IF(JCR.EQ.2) GO TO 2
      IF(JCR)2,10,11
    2 IF(ISFTYP(IIS) -4) 12,4,4
   12 J21(IIS) = 1
      IF(JCR .NE. 2) CALL AVSTO(TEL,TE)
      IF(ICSCNT .GT. 1) GO TO 30
      IF((JCR .NE. 2) .OR. (ISFTYP(IIS) .NE. 1)) GO TO 310
C...  WARNING- RESTART EXIT FROM ACENTR IN APLANE
      KER846 = KER846 + 1
      IF(KER846 .GT. 1) GO TO 310
      IOP(IIS) = 1
      CALL AVSTO(TE,TP(IS))
      CALL AVSTO(TI,TN(IS))
      CALL ADDST
      ANS = S(IS) - CUTDAT(1)
      CALL AVMULT(TI,ANS,VTEM)
      CALL AVADD(TE,VTEM,TE)
      J50(IIS) = 1
      J51(IIS) = 1
      GO TO 320
  310 IF((JCKR .EQ. 1) .AND. (JCR .EQ. -1)) GO TO 311
C
C
C
      GO TO 312
  311 ANS = DP * QP1
      CALL AVMULT(TI,ANS,VTEM)
      CALL AVADD(TE,VTEM,TE)
      GO TO 9
  312 CALL AERR(-846)
      S(IS) = Q3P * DP
      CALL ADYNDP(AB(7),5,110000)
      IF(ICSCNT - 1) 15, 15, 30
   30 STCK(IS) = Q1PE6
      DP = DPMAX
      S(IS) = Q3P5*DP
      CSD(IS) = Q11P*DP
      ICHKCT(IIS) = 1
      GO TO 15
C..........
    4 DO 5 I=1,3
    5 CMOVE(I)=TAU(IS)*TI(I)+TEL(I)-TE(I)
      DPMX1(IS) = QP5*DPMX1(IS)
       TEMP(1)=DPMX1(IS)-TAU(IS)
C***APLANE 04***
      IF(TEMP(1))6,7,7
    6 KDESPR = KDESPR + 1
      IF(KDESPR .GE. 2) GO TO 62571
      IF(KTANSF .EQ. 0) GO TO 62571
      KWHICH = IDS
      IF(KTANSF .EQ. 1) KWHICH = IPS
      CALL AVDOT(TA,SN(KWHICH),ANS)
      IF(DABS(ANS) .GT. QP4X95) GO TO 62571
      CALL AVSTO(TE,TP(IS))
      CALL AVSTO(TI,TN(IS))
      CALL ADDST
      IF(IER .EQ. 0) GO TO 62571
      ISFTYP(IIS) = 1
      CALL AVSTO(TEK,TE)
      GO TO 9
62571 KAERR = 843
      GO TO 1111
C...
    7 CALL  AVADD(TE,CMOVE,TE)
      GO TO 9
C............
   10 KAERR = 842
      GO TO 1111
C...
   11 CALL AVSUB(TE,TEK,VTEM)
      CALL AVDOT(VTEM,TI,ANS)
C***APLANE 05***
       CALL ADYNDP (AB(11),5,110000)
      IF(ANS.LT.QNUL) GO TO 120
   13 IF(JCR-1)21,20,21
   21 JPR=-1
      GO TO 16
C...
   20 JPR=1
      GO TO 16
C...
   14 NUMPT1=NUMPT1-1
      IF(NUMPT1-1)15,17,15
   15 JPR=0
   16 CONTINUE
C***APLANE EX***
       CALL ADYNDP (AB(13),3,111100)
C...
 1111 IF(KCHNGE .EQ. 0) GO TO 3333
      ITLON(IIS) = KON
      ISFTYP(IIS) = KST
      TAU(IS) = SAVTT
      TAU1(IS) = SAVTO
      TAU2(IS) = SAVTI
      EPS1(IS) = SAVT1
      EPS2(IS) = SAVT2
      EPS3(IS) = SAVT3
      EPS4(IS) = SAVT4
      EPS6(IS) = SAVT6
      EPS8(IS) = SAVT8
      KCHNGE = 0
 3333 IF(KAERR .EQ. 0) RETURN
      CALL AERR(KAERR)
      RETURN
C...
   17 KAERR = 841
      GO TO 1111
C...
  120 CALL AERR(-845)
      GO TO 12
  125 ICHKCT(IIS) = 0
      GO TO 14
C**********NOTE TAU, EPS, ITLON, ISFTYP ADJUSTMENTS NOT MADE
C IN PSTAN, TANTO, AND -845 OR -846
      END

