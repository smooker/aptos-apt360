      SUBROUTINE BDYNDP(CALNM,KZ,IDYNFQ)
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4  QN, QN1, QN2, AER1, AER2, BLA, CALNM, XNAME
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
      COMMON/ A2DYIN/ INDX1(10), INDX2(7,2), INDX3(15,2), XNAME(700)
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,
     1TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(9)
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
     4NREC      ,IRECNO    ,ITRFLG    ,NW        ,IDUMMY
C... A2CMMN END
      COMMON/A2DYDP/ KDYNFQ(12), NKFQ
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
     4QFIL(10)
      DIMENSION  NUM(12), BG(1), IBG(1), CALNM(2)
      EQUIVALENCE (BG(1), SP(1)), (IBG(1),IAFL(1))
      DATA QN,QN1,QN2,AER1,AER2,BLA/  4HARLM,4H201 ,4H299 ,4H**AE,
     14HRR**,4H    /
      DATA NUM/12*0/,NCALN/0/
C...       RESET CALL NO. FOR EACH CUT SEQUENCE
      IF(IDYNFQ.GE.0) GO TO 7
      IF(IDYNFQ.EQ.-2) GO TO 5
      IM = 1
      NCALN = 0
      GO TO 10
    5 IF(I3 .EQ. 0) GO TO 10
      WRITE(IOUTAP,6000) CALNM(1),CALNM(2)
 6000 FORMAT(1H ,'TRACE OF POSSIBLE LOOP  ',A4,A4)
      GO TO 10
    7 NCALN = NCALN + 1
C...     IS FREQUENCY FOR THIS LEVEL 0--IF SO RETURN
    8 IF(KDYNFQ(KZ)) 15,10,15
   10 RETURN
   15 IF(KDYNFQ(7).GT.0) GO TO 10
   20 KDIV = IDYNFQ
C...     HAS FREQUENCY BEEN RESET SINCE LAST CALL--IF SO RESET ITERATION
      IF(NKFQ)30,60,30
   30 DO 40 IQ=1,12
   40 NUM(IQ) = 0
   50 NKFQ = 0
   60 NUM(KZ) = NUM(KZ) - 1
   70 IF(NUM(KZ)) 80,80,75
   75 IF(KDYNFQ(KZ)) 10,10,90
   80 NUM(KZ)  = IABS(KDYNFQ(KZ))
   90 WRITE(IOUTAP,1000) CALNM(1),CALNM(2),NREC,NCLREC,NCALN,KZ,KND
C...     IF TRACE PRINT ONLY GO HOME
      IF(NUM(KZ).NE.IABS(KDYNFQ(KZ)))GO TO 10
  100 IF(KDYNFQ(KZ))10,10,110
  110 DO 999  IQ = 1,6
  120 KDIV1 = KDIV - 1000000/10**IQ
  130 IF(KDIV1)999,140,140
  140 KDIV = KDIV1
  150 GO TO(210,210,230,280,250,260),IQ
  210 M1 = 3
  211 IF(ICSCNT.GT.1) M1 = ICSCNT + 2
  212 GO TO 300
C...     FLOATING POINT FIXED COMMON
  230 INDX3(11,2) = NW
      GO TO 280
C...     PROBUF COMMON
  250 INDX3(14,2) = NWDS
      IF((( CALNM(1).EQ.QN).AND.((CALNM(2).GE.QN1).OR.(CALNM(2).LE.QN2))
     1).OR.((CALNM(1).EQ.AER1).AND.(CALNM(2).EQ.AER2))) INDX3(14,2) = 75
      GO TO 280
C...     CANSTO COMMON
  260 INDX3(15,2) = JTUSED
  280 M1 = 1
C...     SET UP OVERALL INDEXES
  300 MQ1 = INDX1(IQ)
  305 MQ21 = MQ1
  310 II = INDX2(IQ,2)
  320 IIQ = INDX2(IQ,1)
  330 IF((IQ.EQ.2).OR.(IQ.EQ.4)) GO TO 600
C...     DUMP FLOATING POINT COMMON
  400 MQ1 = MQ21
  410 MQ21 = MQ1 + INDX3(IIQ,1)
C...     VARIABLES HAVE FLOATING LIMIT
  420 IF(INDX3(IIQ,2)) 430,440,440
  430 MQ = INDX3(IIQ,1)/IABS(INDX3(IIQ,2))
      MQX = IABS(INDX3(IIQ,2))
      GO TO 450
  440 MQ = INDX3(IIQ,2)
      MQX = 1
  450 MQ20 = MQ1 + MQ - 1
C...     PRINT ONE OR FOUR VARIABLES PER LINE
  460 IF(INDX3(IIQ,1) + INDX3(IIQ,2))  510,470,510
C...     FOUR PER LINE
  470 MQXX = MQX/4
      DO  500  KQ =1,MQXX
  480 WRITE (IOUTAP,2000) XNAME(II),XNAME(II+1),BG(MQ1),XNAME(II+2),
     1 XNAME(II+3),BG(MQ1+1), XNAME(II+4),XNAME(II+5),BG(MQ1+2),
     2 XNAME(II+6),XNAME(II+7),BG(MQ1+3)
  490 MQ1 = MQ1 + 4
      II = II +8
  500 CONTINUE
      MQX = MQX - MQXX*4
      MQ20  = MQ1
      MQ = 1
      IF(MQX) 590,590,510
C...     ONE VARIABLE PER LINE
  510 IF(MQ)590,590,520
  520 DO 540  K = 1,MQX
      WRITE (IOUTAP,2000) XNAME(II),XNAME(II+1), (BG(IJ), BLA,BLA,
     1  IJ=MQ1,MQ20)
      II = II+2
      MQ1 = MQ1 + MQ
      MQ20 = MQ20 + MQ
  540 CONTINUE
  590 IIQ = IIQ + 1
      IF(IIQ.GE.INDX2(IQ+1,1)) GO TO 790
      GO TO 400
C...     DUMP INTEGER COMMON
  600 MQ1 = MQ21
  610 NQ = IABS(INDX3(IIQ,2))/7
      MQ21 = MQ1 + INDX3(IIQ,1)
  620 DO 650  KQ = 1,NQ
      WRITE(IOUTAP,3000) XNAME(II),XNAME(II+1),IBG(MQ1) ,XNAME(II+2),
     1 XNAME(II+3),IBG(MQ1+1),XNAME(II+4),XNAME(II+5),IBG(MQ1+2),
     2 XNAME(II+6),XNAME(II+7),IBG(MQ1+3), XNAME(II+8),XNAME(II+9),
     3 IBG(MQ1+4), XNAME(II+10), XNAME(II+11), IBG(MQ1+5), XNAME(II+12),
     4 XNAME(II+13),IBG(MQ1+6)
      II=II+14
      MQ1 = MQ1 + 7
  650 CONTINUE
      I2Q = IABS(INDX3(IIQ,2))- 7*NQ
      IF(I2Q.LE.0) GO TO 790
C...     PRINT ANY VARIABLES LEFT OVER
      DO 700  KQ = 1,I2Q
      WRITE(IOUTAP,3000) XNAME(II),XNAME(II+1), IBG(MQ1)
      II=II+2
      MQ1 = MQ1 + 1
  700 CONTINUE
  790  WRITE (IOUTAP,4000)
  800 M1 = M1 - 1
      IF(M1)999,999,310
  999 CONTINUE
      GO TO 10
 1000 FORMAT(1X,2A4,5X,7HNREC = ,I4,5X,9HNCLREC = ,I4,5X, 9HCALL NO. ,
     1 I5,5X,6HLEVEL ,I2,5X,4HISN ,I4/)
 2000 FORMAT(4(3X,A4,A4,   D20.13,1H,))
 3000 FORMAT(7(3X,A4,A4,   I6,1H,))
 4000 FORMAT(1H0)
C...
      END

