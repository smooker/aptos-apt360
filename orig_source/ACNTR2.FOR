      SUBROUTINE ACNTR2
C     *** THIS PROGRAM HAS BEEN ADDED FOR VERSION 4, MODIFICATION 2 ***
C  ***  AND PARTITIONED FOR FORTRAN H COMPILER (180K)               BHC
C
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4  AB
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
     2J40       ,J43       ,J54       ,J103      ,PROBUF(100)
C
      COMMON/A2CMMN/ ADUM(2000), IER, INSTR1 ,INSTR2 , NWDS ,ICL ,
     1NREC      ,IRECNO    ,ITRFLG    ,NW        ,IDUMMY
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
C...                                    NEXT 1 CARD FOR SPLIT.      BHC
      COMMON/ACENCM/ ICMVL, JTA, KOUNT, IRET, IIN, IOUT, TANANG, KAS905
      DIMENSION AB(46)
      DATA AB/    4HACEN,4HTRTP,4HACEN,4HTR01,4HACEN,4HTR02,4HACEN,
     1            4HTR03,4HACEN,4HTR04,4HACEN,4HTR05,4HACEN,4HTR06,
     2            4HACEN,4HTR07,4HACEN,4HTR08,4HACEN,4HTR09,4HACEN,
     3            4HTR10,4HACEN,4HTR11,4HACEN,4HTR12,4HACEN,4HTR13,
     4            4HACEN,4HTR14,4HACEN,4HTREX,4HACEN,4HTR15,4HACEN,
     5            4HTR16,4HACEN,4HTR17,4HACEN,4HTR18,4HACEN,4HTR19,
     6            4HACEN,4HTR20,4HACEN,4HTR21  /
C...                                    NEXT  7 CARDS FOR SPLIT.    BHC
C
C...    ACENTR PARTITIONED AT BHC TO USE 180K COMPILER.
C
C...    BRANCH BY IIN
C
      GOTO (50,72,91,302,8000), IIN
C
C...
   50 CONTINUE
C...  ****************************************************** 15 *****
      CALL ADYNDP(AB(33),5,110000)
C...
      CALL ACPLAN
C...
C...  ****************************************************** 16 *****
      CALL ADYNDP(AB(35),5,110000)
C...
      IT=IT
      IIT = IIT
  501 IF(JCPR) 6,555,6
C... TANGENT CS STOPPING POSITION COULD NOT BE DETERMINED.  *** 906 ***
    6 CALL AERR(906)
  555 JTA = 0
    5 IF(NOTAN(IIS))51,51,71
 51   IF  (PLNCS(IS))  52,53,53
   52 CALL AVSUB(VNUL,TN(IS),TN(IS))
      CALL ADYNDP(AB(37),5,110000)
      KOUNT = KOUNT + 1
      IF(KOUNT.GE.50) CALL AERR(-910)
      IF((ISTRUP.NE.1).OR.(NUMSUR.NE.3).OR.(ISFTYP(IICS).NE.4).OR.
     1 (KOUNT.LT.25)) GO TO 25
      JENT(IICS) = 1
      JTN(IICS) = 1
      GO TO 25
   53 CALL AVDOT(SN(IS),SN(IT),ANS)
      IF(DABS(ANS).GT.TANANG) GO TO 71
   55 IF(DABS(PLND(IS)) - EPS4(IS)) 56,56,59
   56 IF(J54)57,58,57
 57   J54=0
      GO TO 79
 58   J54=1
   59 J50(IIS)=0
      GO TO 6000
 6500 CONTINUE
      IF(Q1P5 - DABS(CPTST(IS))) 60,61,61
   60 ANS = Q1P
      IF(CPTST(IS).LT.QNUL) ANS = -Q1P
      CPTST(IS) = CPTST(IS) -ANS
      IF(PLND1(IS)) 62,61,62
 62   PLTST(IS)=PLND(IS)/PLND1(IS)
      CALL AVDOT(PLNV(IS),TNK(IS),ANS)
      IF(ANS.LT.QNUL) PLTST(IS)=-PLTST(IS)
      IF(QP9 - DABS(PLTST(IS))) 63,69,69
   63 IF(PLTST(IS))64,64,67
   64 PLTST(IS) = -QP9
   65 PLND(IS) = PLND(IS)*(Q1P - DABS(PLTST(IS)))
   66 PLND1(IS)=QNUL
      JCNT1=25
      CALL ADYNDP(AB(39),5,110000)
      GOTO70
   67 PLTST(IS) = QP9
   68 PLND(IS) = PLND(IS)/(Q1P - DABS(PLTST(IS)))
      GOTO66
   69 IF(PLTST(IS))65,65,68
   61 PLND1(IS)=PLND(IS)
      CALL AVSTO(PLNV(IS),TNK(IS))
   70 IF(JCNT2) 89,6800,101
  101 IF(ICMVL.EQ.0) JCNT2=JCNT2-1
      IF(JCNT2.GE.6) GO TO 1701
      IF(JS.NE.1) GO TO 1701
      IF(DABS(S(IS)).GT.EPS4(IS)) GO TO 1701
      CALL AVSTO(PLNV(IS),VTEM)
      ANS = PLND(IS)
      CALL AVSTO(TN(IS),PLNV(IS))
      PLND(IS) = QP5*S(IS)
      CALL AVSTO(VTEM,PLNV(IT))
      PLND(IT) = ANS
      GO TO 1701
   71 IF(DABS(PLND(IS))-EPS4(IS)) 72,72,59
   72 IF(IPL(IIS))75,75,366
   75 CONTINUE
      ANS = RC(IS)*S(IS)
      IF(JTN(IIS).EQ.0) ANS = -ANS
      CALL ADYNDP(AB(1),12,111111)
      IF(ANS) 73,765,74
   73 IF(DABS(S(IS)) - EPS8(IS) - QP5X05) 765,765,359
   74 IF(DABS(S(IS)) - (TAU(IS) - EPS8(IS) + QP5X05)) 765,765,359
  366 IF(ITLON(IIS) .NE. 0) GO TO 98765
      IF(DABS(S(IS)) .LT. TAU1(IS)) GO TO 766
      IF(DABS(S(IS)) .LT. DABS(TAU2(IS))) GO TO 766
      GO TO 359
98765 IF(S(IS))368,367,367
  367 IF(S(IS) - QP5X05 - TAU1(IS))765,765,359
  368 IF(S(IS) + QP5X05 - TAU2(IS))359,765,765
  359 IF(ISFTYP(IIS) -4) 2001,2002,2001
 2001 IF(NOTAN(IIS))1701,36,2002
 2002 IF(Q8P*TAU(IS) - DABS(S(IS))) 302,522,522
  522 IF(NOTAN(IIS))523,59,523
  523 NOTAN(IIS)=-1
      GO TO 1010
  765  CONTINUE
       CALL ATLTST(IRET)
       IF(IRET.EQ.0) GO TO766
       GO TO 359
  766 CONTINUE
       IF(NOTAN(IIS)) 41,41,201
  302 JCR=2
      CALL ADYNDP(AB(41),5,110000)
      GO TO 48
  201 J=3
      CALL ADYNDP(AB(43),5,110000)
      GO TO 4004
   79 CALL AVSUB(TP(IS),TP(IT),VTEM)
      CALL AVDOT(VTEM,TA,TEMP(2))
      CALLAVMULT(TA,TEMP(2),TEMP(3))
      CALL AVSUB(TP(IS),TEMP(3),TEMP(3))
      CALL AVSTO(TP(IT),TEMP(6))
      IF(IPL(IIT))81,81,83
   81 CALL AVSUB(TEMP(3),TE,VT(IT))
      CALL AVSTO(TN(IS),TN(IT))
   83 IF(IPL(IIS))84,84,85
   84 CALL AVSUB(VNUL,SN(IT),TN(IS))
      VT(IS)=TEMP(6)+TEMP(2)*TA(1)-TE(1)
      VT(IS+1)=TEMP(7)+TEMP(2)*TA(2)-TE(2)
      VT(IS+2)=TEMP(8)+TEMP(2)*TA(3)-TE(3)
   85 ANS = Q1P
      IF(CPTST(IS).LT.QNUL) ANS = -ANS
      CPTST(IS) = CPTST(IS) - ANS
      CALL ADYNDP(AB(45),5,110000)
      GOTO11
   91 KAS905 = KAS905 + 1
      IF(KAS905 .GT. 5) CALL AERR(-905)
      GOTO4001
C... 3 SURF ITERATION, TANTO OR PSTAN, AND PS OR DS TOL NOT MODIFIED.
C... BRANCHED TO HERE AFTER ENTRY AND INITIALIZATION OF SOME VARIABLES
C... IF ABOVE 3 CONDITIONS ARE MET.
 8000 CONTINUE
      ITS = IDS
      IF(IFL4(IIS).EQ.1) ITS = IPS
      IF(TAU1(IS).GE.TAU1(ITS)) GO TO 8050
      IF(TAU1(IS).EQ.QNUL) GO TO 8050
C...   CEND  = TOLERANCE MODIFICATION INDICATOR.
C...   CEND(1) = 1  PS OR DS TOLERANCE WAS MODIFIED BY ACENTR.
C...   CEND(1) NOT = 1  PS OR DS TOLERANCE WAS NOT MODIFIED.
C...   IF CEND(1)=1, CEND(2) AND CEND(3) CONTAIN THE VALUES OF TAU1 AND
C...   TAU2 BEFORE MODIFICATION.
C...
C...   CEND(1) SET TO 1 IF CS TAU1 IS LESS THAN DS(OR PS) TAU1 AND
C...   CS TAU1 IS NOT ZERO.
      CEND(1) = Q1P
      CEND(2) = TAU1(ITS)
      TAU1(ITS) = TAU1(IS)
 8050 IF(DABS(TAU2(IS)).GE.DABS(TAU2(ITS))) GO TO 8100
      IF(TAU2(IS).EQ.QNUL) GO TO 8100
      CEND(1) = CEND(1) + Q2P
      CEND(3) = TAU2(ITS)
      TAU2(ITS) = TAU2(IS)
 8100 IF(CEND(1).EQ.QNUL) GO TO 8001
C...  DS(OR PS) TOLERANCE HAS BEEN MODIFIED ... ADJUST EPS
      IF(IFL4(IIS).EQ.1) CEND(1) = -CEND(1)
      TAU(ITS) = TAU1(ITS)-TAU2(ITS)
      EPS1(ITS) = QP1* TAU(ITS)
      EPS8(ITS) = EPS1(ITS)
      EPS2(ITS) = Q1P - EPS1(ITS)
      EPS3(ITS) = QP9*EPS1(ITS)
      EPS4(ITS) = Q2P*TAU(ITS)
      EPS6(ITS) = QP02* EPS1(ITS)
      GO TO 8001
C...
 6000 CALL AVDOT(PLNV(IS),TI,ANS)
      ANS = ANS*PLND(IS)
      BNS = ANS
      IF(ANS.GT.QNUL) GO TO 6100
      IF(IABS(ITNFLG)-1) 6010,6020,6050
 6010 ITNFLG = -1
      GO TO 6050
 6020 IF(ITNFLG.LT.0) GO TO 6050
      ITNFLG = -2
 6050 IF(DABS(PLND(IS)).GT.PROBUF(17)) GO TO 6400
      CALL AVSTO(TE,PROBUF(11))
      CALL AVSTO(TA,PROBUF(14))
      PROBUF(17) = DABS(PLND(IS))
      GO TO 6400
 6100 IF(IABS(ITNFLG)-1) 6110,6120,6150
 6110 ITNFLG = 1
      GO TO 6150
 6120 IF(ITNFLG.GT.0) GO TO 6150
      ITNFLG = 2
 6150 IF(DABS(PLND(IS)).GT.PROBUF(7)) GO TO 6400
      CALL AVSTO(TE,PROBUF(1))
      CALL AVSTO(TA,PROBUF(4))
      PROBUF(7)=DABS(PLND(IS))
 6400 IF(JS.EQ.0) GO TO 6500
C      SPECIAL HALVING ALGORITHM
      JCNT1 = 25
      IF(BNS.GT.QNUL)  GO TO 6700
      CALL AVSUB(PROBUF(1),TE,VTEM)
      GO TO       6750
 6700 CALL AVSUB(PROBUF(11),TE,VTEM)
 6750 CALL AVLENG(VTEM,ANS)
      CALL AVNORM(VTEM,PLNV(IS),IER)
      PLND(IS) = QP5* ANS
      GO TO 70
 6800 IF(JS.EQ.1) GO TO 89
      IF(IABS(ITNFLG).LE.1) GO TO 89
      JS = 1
      JCNT2 = 25
      CALL AVSTO(PROBUF(1),TE)
      CALL AVSTO(PROBUF(4),TA)
      GO TO 11
C...    SET UP INDEX AND RETURN.        NEXT 23 CARDS FOR SPLIT.    BHC
   11 IOUT = 1
      GOTO 9000
   25 IOUT = 2
      GOTO 9000
   41 IOUT = 3
      GOTO 9000
   48 IOUT = 4
      GOTO 9000
   89 IOUT = 5
      GOTO 9000
 1010 IOUT = 6
      GOTO 9000
 1701 IOUT = 7
      GOTO 9000
 4001 IOUT = 8
      GOTO 9000
 4004 IOUT = 9
      GOTO 9000
 8001 IOUT = 10
      GOTO 9000
   36 IOUT = 11
 9000 RETURN
      END

