      SUBROUTINE ARPDIS
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
C
C...  TO ACT AS A DISPATCHER AT AREPRE TIME,  CALL THE REQUIRED
C...  COMPUTATION ROUTINES AND UPDATE PMOVE UPON RETURN.
C...
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
      COMMON/A2CMMN/ SP(3) ,SN(3)     ,TP(3)     ,TN(3)     ,SNK(3)    ,
     1SNL(3)    ,SPK(3)    ,SPL(3)    ,TNK(3)    ,TNL(3)    ,TPK(3)    ,
     2TPL(3)    ,PLNV(3)   ,CC(3)     ,U1(3)     ,CUTH(3)   ,SFVCT(3)  ,
     3VNDIR(3)  ,VMD(3)    ,VT(3)     ,TEE(3)    ,SLX(3)    ,DPLAN(3)  ,
     4S(1)      ,RC(1)     ,PLND(1)   ,TH(1)     ,CSD(1)    ,Z(1)      ,
     5EPS1(1)   ,EPS2(1)   ,EPS3(1)   ,EPS4(1)   ,EPS6(1)   ,EPS8(1)   ,
     6TAU(1)    ,TAU1(1)   ,TAU2(1)   ,STCK(1)   ,STCKN(1)  ,STCK1(1)  ,
     7STCK2(1)  ,COS1(1)   ,DPMX1(1)  ,CPLFL(1)  ,CPTST(1)  ,PLNCS(1)  ,
     8PLND1(1)  ,PLTST(1)  ,PAST(1)   ,SPAST(1)  ,ADCS(1)   ,H(1)      ,
     9CUTR(1), AFILLR(500), IAFL(1), IPONTR(1), IFAR(1), IPL(1)
      COMMON/A2CMMN/IUNFL(1),ISFTYP(1), ITLON(1), ISVFL(1), IFL4(1),
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
      COMMON/ATANCO/KTTRY2
      COMMON/TAUMD1/     SVTAU1,SVTAU2,SVTAU,SVEPS1,SVEPS8,SVEPS2,SVEPS3
     1,SVEPS4,SVEPS6,MTAU
      COMMON/CNTRU1/J51CKP, J51CKD, RVRSU1(6)
      J51CKP = 0
      J51CKD = 0
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HARPD,4HISTP/
C..... TO SET ADYNDP COUNTER TO ZERO .....
      CALL BDYNDP(AB(1),1,-1)
C...... IFRL = 1 .... INFORMS AMIND THAT IT IS CALLED FROM AREPRE
C...... IFRL = 0 .... OTHERWISE
C...............
      CALL CDYNDP(2,1)
C.......................................................................
      CALL AREPRE(ICALL,KK1,KK2,ITOPT,PERCEN)
      IFRL = 0
C..................................
      MTAU = 0
      KTTRY2 = 0
      KFAIL = 0
      GO TO (1,2,3,4,5) , ICALL
    1 IF(KTTRY2 .EQ. 0) GO TO 333
      IF((IPL(IIPS) .EQ. 1) .AND. (IPL(IIDS) .EQ. 1)) GO TO 333
      IF((DABS(TH(IPS))+DABS(TH(IDS))+DABS(TH(ICS))).NE.QNUL) GO TO 333
      IF((ICSCNT .GT. 1) .OR. (ISFTYP(IICS) .NE. 4)) GO TO 333
      IF(MULTAX .GT. 1) GO TO 333
C...
      INDIC = 41
      KNDIC = 101
      IF(IFL4(IICS) .EQ. 1) INDIC = 1
      IF(INDIC .EQ. 1) KNDIC = 1
      KAETA = 0
      IF((MULTAX .EQ. 1) .OR. (ITLON(INDIC) .EQ. 0)) GO TO 888
C...
  222 IF((J24(INDIC) .EQ. 2) .AND. (IPL(IICS) .EQ. 1)) GO TO 555
      IF((IPL(INDIC) .EQ. 1) .AND. (J24(IICS) .EQ. 2)) GO TO 444
      GO TO 333
  444 KCYLCS = IPONTR(IICS)
      CALL AVDOT(CANSTO(KCYLCS+7),TA,ANS)
      IF(DABS(ANS) .GT. QP6X9) GO TO 891
C...
C...
      IS = ICS
      IIS = IICS
      CALL AVSTO(TE,TP(IS))
      CALL AVSTO(TI,TN(IS))
C...
      CALL ADDST
      ITLON(IICS) = 1
      IF(IER .NE. 0) GO TO 776
      IF(CUTDAT(1) .GT. CANSTO(KCYLCS+10)) GO TO 333
      IF(CUTDAT(7) .GT. CANSTO(KCYLCS+10)) GO TO 333
      GO TO 777
C...
  555 KCYL = IPONTR(INDIC)
      CALL AVDOT(CANSTO(KCYL+7),TA,ANS)
      IF(DABS(ANS) .GT. QP6X9) GO TO 890
      IF(RC(KNDIC) .GE. QNUL) GO TO 777
C...
  776 ISFTYP(IICS) = 1
      PAST(ICS) = Q1P
      GO TO 778
C...
  777 ISFTYP(IICS) = 2
      PAST(ICS) = -Q1P
      GO TO 778
  333 CONTINUE
      CALL ARLM3
      IFRL = 1
      GO TO 100
C..................................
C...
    2 CONTINUE
      ANS = CUTDAT(1)
      IF((ITOPT.EQ.4).AND.(ITLON(IIDS).EQ.0)) ANS = QNUL
      CALL ARLM2(ANS,TN(IDS),QNUL,TE,TI,CANSTO(KK1),CANSTO(KK2)
     1,ITOPT,IFAR(IICS),TAU(IDS),TAU(ICS),PERCEN,KDYNFQ(8))
      IFRL = 1
      GO TO 100
C..................................
C...
    3 CALL ASTRUP
      IFRL = 2
      GO TO 100
C..................................
C...
    4 CALL ASTUP2
      IFRL = 2
      GO TO 100
C..................................
C...
    5 CALL AOFSET
      IFRL = 2
C...
C..................................
C...
C
C.......................................................................
C...  UPON RETURN FROM ALL ROUTINES, AUTOPS AND NOPS FLAGS ARE SET TO
C...  ZERO. ALSO RESET IFAR(IICS)=1  ..... IFAR IS THE PART PROGRAMMER
C...  SPECIFIED INTERSECTION BETWEEN DS AND CS.
C...
C...  ALL RETURNS UPDATE PMOVE, WHICH REPRESENTS A UNIT VECTOR ALONG
C...  THE LAST CUT VECTOR OF THE CUT SEQUENCE OR STARTUP MOTION.
C...  IT WILL BE USED TO ESTABLISH THE FORWARD DIRECTION FOR THE NEXT
C...  CUT SEQUENCE IF THE USUAL TECHNIQUE SHOULD FAIL.
C...  *** PMOVE IS NOT TO BE UPDATED IF THE MOTION IS WITHIN TWO DEGREES
C...      OF THE TOOL AXIS ***
C...
  100 CONTINUE
      IF(MTAU .EQ. 0) GO TO 999
      MTAU = 0
      TAU1(ICS) = SVTAU1
      TAU2(ICS) = SVTAU2
      TAU(ICS) = SVTAU
      EPS1(ICS) = SVEPS1
      EPS8(ICS) = SVEPS8
      EPS2(ICS) = SVEPS2
      EPS3(ICS) = SVEPS3
      EPS4(ICS) = SVEPS4
      EPS6(ICS) = SVEPS6
  999 CONTINUE
      KFAIL = KFAIL + 1
      IF((KFAIL .EQ. 1) .AND. (KTTRY2 .EQ. 1)) GO TO 1
      IF(KFAIL .LE. 1) GO TO 4472
      IF(JCR .EQ. 1) GO TO 4472
      IF((JCR .EQ. 0) .AND. (J20(IIS) .EQ. 2)) GO TO 4472
      CALL AERR(802)
 4472 CALL AVSUB(TE,TEK,VTEM)
C...  RESET INTERSECTION COUNTER FLAG TO 1
      L = ICSCNT + 2
      DO 402 I = 3,L
      K = 1+LISV*(I-1)
      IFAR(K) = 1
  402 CONTINUE
C...
C...  UPDATE PMOVE  .........................
  405 CALL AVNORM(VTEM,VTEM,IER)
      IF(IER.NE.0) GO TO 500
      CALL AVDOT(VTEM,TA,ANS)
      IF(DABS(ANS).GT.QP997) GO TO 500
      CALL AVSTO(VTEM,PMOVE)
  500 CONTINUE
C...
      INOPS=0
      IAUTPS=0
C...
      MTAU = 0
      RETURN
C...
  888 IF(ITLON(INDIC) .EQ. 0) GO TO 666
      IF((ICC .EQ. 1) .AND. (INDIC .EQ. 1)) GO TO 666
      IF((ICC .EQ. 2) .AND. (INDIC .EQ. 41)) GO TO 666
      GO TO 222
  666 CONTINUE
C
      IF(IPL(IICS) .NE. 1) GO TO 889
      IF(J24(INDIC) .NE. 2) GO TO 333
      GO TO 890
C...
  889 IF((J24(IICS) .EQ. 2) .AND. (IPL(INDIC) .EQ. 1)) GO TO 891
      GO TO 333
C...
  890 KCSPON = IPONTR(IICS)
      KTANPT = IPONTR(INDIC)
C...
      IF(KAETA .NE. 2) GO TO 892
C...
      KCSPON = IPONTR(INDIC)
      KTANPT = IPONTR(IICS)
C...
  892 CALL AVCROS(CANSTO(KTANPT+7),CANSTO(KCSPON+4),VTEM)
      CALL AVNORM(VTEM,VTEM,IER)
      IF(IER .NE. 0) GO TO 333
      CALL AVDOT(CANSTO(KTANPT+4),VTEM,ANS)
C...
      IF(KAETA .EQ. 2) KCSPON = KTANPT
      ITLON(IICS) = 0
      ISFTYP(IICS) = 3
C...
      CANSTO(KCSPON+4) = VTEM(1)
      CANSTO(KCSPON+5) = VTEM(2)
      CANSTO(KCSPON+6) = VTEM(3)
      CANSTO(KCSPON+7) = ANS
C...
      GO TO 333
C...
  891 KAETA = 2
C...
      J24(IICS) = 1
      IPL(IICS) = 1
C...
      GO TO 890
C...
  778 SVTAU1 = TAU1(ICS)
      SVTAU2 = TAU2(ICS)
      SVTAU = TAU(ICS)
      SVEPS1 = EPS1(ICS)
      SVEPS8 = EPS8(ICS)
      SVEPS2 = EPS2(ICS)
      SVEPS3 = EPS3(ICS)
      SVEPS4 = EPS4(ICS)
      SVEPS6 = EPS6(ICS)
C...
      TAU1(ICS) = TAU1(ICS) * QP5
      TAU2(ICS) = TAU2(ICS) * QP5
      TAU(ICS) = TAU1(ICS) - TAU2(ICS)
      EPS1(ICS) = QP1 * TAU(ICS)
      EPS8(ICS) = EPS1(ICS)
      EPS2(ICS) = Q1P - EPS1(ICS)
      EPS3(ICS) = QP9 * EPS1(ICS)
      EPS4(ICS) = Q2P * TAU(ICS)
      EPS6(ICS) = QP02 * EPS1(ICS)
      MTAU = 1
      GO TO 333
      END

