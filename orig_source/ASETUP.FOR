      SUBROUTINE  ASETUP
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4  AB
C     SETS SPECIAL ITERATION FLAGS FOR
C     MINIMUM DISTANCE AND SETS NUMDIM
C... A2CMMN START
      COMMON/A2CMMN/ADUM(600), IAFL(1), IPONTR(1), IFAR(1) , IPL(1)
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
     3 CANSTO(2000)
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
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HASET,4HUP  /
C
      CALL ADYNDP (AB(1),5,111100)
C     SET UP TO TEST PS
      IF(ISTRUP.GT.0) GO TO 7
      IC = IPONTR(IIPS)
      N = IPS
      IN = IIPS
      CALL ASTOR(CANSTO(IC),8,ISTYPE,2)
      ANS = QNUL
      IF(ISTYPE.GT.3) GO TO 5
C     PLANE TEST AXIS
      CALL AVDOT(TA,CANSTO(5),ANS)
      IF (ANS) 33,5,34
   33 CALL AVSUB(VNUL,CANSTO(5),VTEM)
      GO TO 36
   34 CALL AVSTO (CANSTO(5), VTEM)
   36 CALL AVMULT (VTEM,CUTDAT(1),VTEM)
      CALL AVMULT (TA, CUTDAT(1), TEMP)
      CALL AVSUB (VTEM,TEMP,VTEM)
      CALL AVLENG (VTEM,VTEM(1))
      IF(VTEM(1) - .000025) 3,5,5
C     NOT NORMAL TO CUTTER
    5 CONTINUE
      IF(DABS(ANS).LE.QP2) NUMDIM = 1
      GO TO 7
C
C     IS NORMAL
    3 IAFL(IN) = 0
      ITSEG(IN) = 9
      GO TO 7
C
C     SET FOR DS
    7 N = IDS
      IN = IIDS
    1 K = IPONTR(IN)
      CALL ASTOR(CANSTO(K),8,I,2)
      IF((I.EQ.2).OR.(I.EQ.3)) GO TO 20
      IF((I.EQ.4).OR.(I.EQ.5)) GOTO 40
      IF((I.EQ.6).OR.(I.EQ.7).OR.(I.EQ.9).OR.(I.EQ.10)) GOTO 60
C
C     NOT A SPECIAL CASE GO LOOP
      NUMDIM = 1
      IF(I.NE.50) GO TO 100
      CALL AVDOT(TA,CANSTO(K+12),ANS)
      IF(DABS(ANS).LT.QP7X9) GO TO 100
      GO TO 84
   20 CONTINUE
C     PLANE
      CALL AVDOT(TA,CANSTO(K+4),ANS)
      IF(DABS(ANS).GT.QP6X01) GO TO 99
      IF((DABS(TA(1)).GT.QP6X01).OR.(DABS(TA(2)).GT.QP6X01))GO TO 99
      IAFL(IN) = 0
      GO TO 85
C
C     SEG SETTER AREA
   84 IAFL(IN) = 1
   85 ITSEG(IN) = 33
      IF(TLLDAT(41).NE.QNUL) ITSEG (IN) = 41
      IF(TLLDAT(53).NE.QNUL) ITSEG (IN) = 57
      IF(ITLON(IN).EQ.0)ITSEG(IN)=9
      GO TO 100
C     CIRCLE, CYLINDER
   40 CALL AVDOT(TA,CANSTO(K+7),ANS)
      IF(DABS(ANS).LE.QP7X9) GO TO 99
      GO TO 84
   60 NUMDIM = 1
      IF((DABS(CANSTO(K+6)) +DABS(CANSTO(K+8)) + DABS(CANSTO(K+9)) +
     1 DABS(CANSTO(K+13))).GT. QNUL) GO TO 100
      IF(TA(3).NE.Q1P) GO TO 100
      GO TO 84
C
   99 NUMDIM = 1
C
C
  100 N = N+LSV
      IN = IN + LISV
      IF(N.LE.((ICSCNT+2)*LSV)) GO TO 1
C
C
C
      RETURN
      END

