      SUBROUTINE AGOUCK
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
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
     2J40 ,J43 ,J54 ,J103 ,ADUM(2100)
      COMMON/A2CMMN/ IER ,INSTR1 ,INSTR2 ,NWDS ,ICL ,
C
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
C...
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HAGOU,4HCK  /
      CALL ADYNDP(AB( 1),3,111100)
      KGAERR = 0
      JGR=0
C         DENOTE CUT VECTOR (UNITIZED) D2, LENGTH ZL
      CALL AVSUB(TE,TEK,D2)
      CALL AVLENG(D2,ZL)
      CALL AVNORM(D2,D2,IER)
C
      IF(IER)101,101,620
  101 CONTINUE
C***
C***
C      NOTE, GOUGE SURFACE IS AFTER LAST CS
      DIMENSION GOUG(1)
      EQUIVALENCE(ANG,COS1(1)),(IAX,I31)
      IS=IGS
      IIS = IIGS
      IT=IPS
      IIT = IIPS
C...
C
C         DETERMINE AXIS CONDITION
      IF(ISFTYP(IIPS)-3)210,231,210
  210 IF(MULTAX.GT.0) GO TO 250
  220 CALL AVDOT(TA,D2,ANS)
      IF(DABS(ANS).GE.QP0005) GO TO 232
C         TA PERPENDICULAR TO CUT VECTOR OR TE ON SURFACE
  231 IAX=0
      GO TO 400
C         TA OBLIQUE TO CUT VECTOR
  232 IAX=1
      GO TO 400
  250 CALL AVDOT(TA,TAK,ANS)
      IF(ANS.GT.QP4X95) GO TO 220
C         AXIS CHANGE DURING CUT
  233 IAX=2
      GO TO 400
C
C         PRELIMINARY TO AXIS CONDITION SETTING FOR DS
  300 IT=IDS
      IIT = IIDS
      IF(ISFTYP(IIDS)-3)310,231,310
C         IF TOOL END ON PS BUT NOT DS,GO THROUGH AXIS CONDITION ROUTINE
  310 IF(ISFTYP(IIPS)-3)400,210,400
C
C         SAVE AND ESTABLISH SYSTEM VARIABLES
  400 CONTINUE
C...
      DO 410 K=1,LSV
      L=IGS-1+K
      J=IT-1+K
  410 SP(L) = SP(J)
      DO 420 K=1,LISV
      L = IIGS -1 +K
      J = IIT -1 + K
  420 IAFL(L) = IAFL(J)
      CALL AVSTO(TA,SFVCT(IGS))
      CALL AVSTO(TE,VNDIR(IGS))
      JENT(IIGS)=0
      JTN(IIGS)=0
      IOPSET(IIGS)=0
      JU1(IIGS)=0
      JIOPS(IIGS)=0
C...
C         CONVERGENCE CRITERION FOR FIRST 10 ITERATIONS
      ANG = QP0005
C         INITIALIZE ITERATION COUNTER
      I=0
C
C
C         CONVERGENCE ROUTINE
 1000 CALL ACCURV(IS,IIS,SP(IS),SPK(IS),SN(IS))
C         IF IT PLANE, RESTORE SYSTEM VARIABLES AND TEST NEXT SURFACE
      IF(-ISIGCR(IIS))1010,1020,600
C         IF POINTS TOO CLOSE AFTER ONE OR MORE ITERATION,USE LAST GUESS
 1010 IF(I)1020,600,1230
 1020 CALL AVSTO(SP(IS),SPK(IS))
C
C         TE=PROJECTION OF CC ON CUT VECTOR
 1030 CALL AVSUB(CC(IS),TE,VTEM)
      CALL AVDOT(VTEM,D2,TEMP)
      CALL AVMULT(D2,TEMP,VTEM)
      CALL AVADD(TE,VTEM,TE)
C         IF PROJECTION NOT ON CUT VECTOR RESTORE SURFACE VARIABLES
C        AND TEST NEXT SURFACE
 1040 CALL AVSUB(TE,TEK,VTEM)
      CALL AVDOT(VTEM,D2,ZL1)
C...
      IF(ZL1)1044,1044,1042
 1042 IF(ZL-ZL1)1044,1044,1050
 1044 KGAERR = KGAERR + 1
      IF(KGAERR .GT. 10) CALL AERR(-881)
      GO TO 600
C
 1050 ISSTO=IT
      IISSTO = IIT
C...
      CALL AMIND
      IT=ISSTO
      IIT = IISSTO
C         CONVERGENCE WHEN TN (HENCE SN) PERPENDICULAR TO CUT VECTOR
      CALL AVDOT(SN(IS),D2,ANS)
C...
      IF(ANG.GE.DABS(ANS)) GO TO 1300
C
C         PREPARE FOR NEXT ITERATION
C         IF TENTH ITERATION, ASSUME SURFACE HAS LARGE DIMENSIONS
C        AND RELAX CONVERGENCE CRITERION
 1200 IF(9-I)1220,1210,1212
 1210 ANG = QP0047
 1212 I=I+1
C...
      GO TO 1000
C         IF FIFTEENTH ITERATION, GIVE UP AND USE LAST GUESS
 1220 IF(14-I)1230,1212,1212
 1230 KGAERR = KGAERR + 1
      IF(KGAERR .GT. 10) CALL AERR(-882)
C
C
 1300 GOUG(1) = DABS(S(IS))
C
C
C         SET RETURN VARIABLE
C...
      IF(QP8*TAU(IT) - GOUG(1)) 510,510,600
  510 IF(IT-IPS)522,522,524
  522 JGR=1
      GO TO 600
  524 JGR=JGR+2
C
C
C         RESTORE SYSTEM VARIBLES
  600 DO 610 K=1,3
      L=IGS-1+K
      TA(K)=SFVCT(L)
  610 TE(K)=VNDIR(L)
C...
C
C
      IF(IDS-IT)620,620,300
  620 CONTINUE
C...
      RETURN
       END

