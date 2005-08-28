      SUBROUTINE AREPRE(ICALL,KK1,KK2,ITOPT,PERCEN)
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
C
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,
     1TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(5)
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
     4QPIE       ,QFIL(9)
C...
      DATA PREVDS/9.99D0/, PREVSB/9.99D0/
      DIMENSION AB(2)
      DIMENSION DSTNSV(6)
      DATA AB(1),AB(2)/4HAREP,4HRE  /
      KPMVTN = 0
      CALL AVSTO(TN(IDS),DSTNSV)
      CALL AVSTO(TP(IDS),DSTNSV(4))
C                   LASTDS = 0  PREVIOUS AND CURRENT DS'S DIFFERENT
C                          = 1  PREVIOUS AND CURRENT DS'S IDENTICAL
      LASTDS = 0
      IF((PREVDS .EQ. ABCD(1)) .AND. (PREVSB .EQ. ABCD(2))) GOTO 10274
C
C                             ABCD(1)=DS NAME, ABCD(2)=SUBSCRIPT
      PREVDS = ABCD(1)
      PREVSB = ABCD(2)
      GOTO 10275
C                   INDICATE PREVIOUS AND CURRENT DS'S ARE IDENTICAL.
10274 LASTDS = 1
10275 CONTINUE
C
C...
      IF(CEND(1).EQ.QNUL) GO TO 6000
      ITS = IDS
      IF(CEND(1).LT.QNUL) ITS = IPS
      CEND(1) = DABS(CEND(1))
      IF(CEND(1).EQ.Q2P) GO TO 5900
      TAU1(ITS) = CEND(2)
 5900 IF(CEND(1).EQ.Q1P) GO TO 5950
      TAU2(ITS) = CEND(3)
 5950 CEND(1) = QNUL
      TAU(ITS) = TAU1(ITS) - TAU2(ITS)
      EPS1(ITS) = QP1* TAU(ITS)
      EPS8(ITS) = EPS1(ITS)
      EPS2(ITS) = Q1P - EPS1(ITS)
      EPS3(ITS) = QP9*EPS1(ITS)
      EPS4(ITS) = Q2P*TAU(ITS)
      EPS6(ITS) = QP02* EPS1(ITS)
 6000 CONTINUE
      CALL ADYNDP (AB(1),1,111111)
C     SET ITLON FLAG FOR ALL SURFACES -0 FOR ON, 1 FOR OFFSET
      L = ICSCNT+2
      ITLON(IIPS) = ISFTYP(IIPS) - 3
      ITLON(IIDS) = ISFTYP(IIDS) - 3
      IF (ICSCNT .LE. 0) GO TO 700
      DO 1 I=3,L
      K = 1+LISV*(I-1)
      IF(ISFTYP(K)-3) 601,602,1
  601 ITLON(K) = 1
      GO TO 1
  602 ITLON(K) = 0
    1 CONTINUE
C     SET IAFL FLAG FOR AMIND
  700 DO 701 I=1,L
      K = 1 + LISV*(I-1)
      IAFL(K) = -1
      IF(JTLFLG(K).NE.1) GO TO 701
      R1(65) = RA
      TLHITE(65) = HI
  701 CONTINUE
C...
C     ASSUME 2 DIMENSIONAL CASE UNLESS FIND OUT DIFFERENT
      NUMDIM = 0
C     TEST FOR 5 AXIS  -IF SO,SET UP SPECIAL CUTTER + TURN OFF NUMDIM
      IF(MULTAX.GT.0) GO TO 2
C     NOT MULTAX, SEE IF START UP. IF NOT START UP, CALL ASETUP TO SET
C     NUMDIM AND SPECIAL FLAGS TO SPEEDUM + CONTROL CUTTER SEGMENT USAGE
C     IN SOME SPECIAL CASES
C
      GO TO 3
C
C     SET UP SPECIAL CUTTER FOR 5 AXIS
    2 NUMDIM = 1
C...
C
C     TEST FOR AUTOPS--IF SO, SETUP CANONICAL FORM
    3 ICL = 5
      NW = 0
      IF(IAUTPS.NE.1) GO TO 4
C...
C     SET UP CAN. FORM
      J24(IIPS) = 1
      IPONTR(IIPS)=1
      CALL ASTOR(0,4,CANSTO(4),8)
      CALL ASTOR(3,4,CANSTO(1),8)
      CALL ASTOR(12HPSIS        ,8,CANSTO(3),8)
      CALL AVSTO(EZ,CANSTO(5))
      CANSTO(8) = TE(3)
      CALL AVSTO(EZ,TN(IPS))
      TN(IPS+2) = -TN(IPS+2)
      IPL(IIPS) = 1
      IF(ITLON(IIPS) .EQ. 0) GO TO 4
      I = IVAMAX
      IVAMAX = 3
      IF((DABS(TA(3)) .LT. Q1P) .AND. (CUTDAT(1) .GT. QNUL))
     1 CALL AERR(-3520)
      ISFTYP(IIPS) = 1
      PAST(IPS) = Q1P
      IVAMAX = I
C
C
C     SET NUMDIM = 1 IF CUTTER DOES NOT HAVE A VERTICAL SHANK
    4 IF(NUMDIM.EQ. 0) CALL ASETUP
      IF(CUTDAT(6) .NE. QNUL) NUMDIM=1
C     SET UP SPECIAL PARAMETERS FOR USE WITH 2-D TYPE CASE (TO GET TOOL
C     POINT TO BE AT CUTTER HEIGHT AT LOWEST POINT O  FULL WIDTH
      DO 5 K=1,L
      I=1+LSV*(K-1)
      II=1+LISV*(K-1)
      IF(IAFL(II).LT.0) GO TO 5
      IT = ITSEG(II)
      CALL AVMULT(TA,TLHITE(IT),CUTH(I))
      CUTR(I) = CORRAD(IT)+R1(IT)
    5 CONTINUE
C...
C
C
C     BRANCH TO START UP IF APPROPRIATE
      IF(ISTRUP.EQ.1) GO TO 10
       IF(ISTRUP.EQ.2) GO TO 11
C     NOT START UP CHECK INITAL POSITION WITH RESPECT TO PS + DS
C
C     SET UP FOR PS, AND SET PAST = 19 (DOESNT MAKE SENSE TO GO PAST THE
C     PS OR DS)
      IS = IPS
      IIS = IIPS
      PAST(IPS) = Q1P
      PAST(IDS) = Q1P
      J6 = 0
C     J6 SET = 0 FOR PS, 1 FOR DS
C
C     NOW INITIALIZE AMIND
  200 JAP = 0
      JMINR = 0
C...
      JENT(IIS) = 1
      JTN(IIS) = 0
      IOPSET(IIS) = 0
      JIOPS(IIS) = 0
      JU1(IIS) = 0
C
  250 CONTINUE
C...
      CALL AMIND
      CALL AVSTO(TP(IS),TPK(IS))
      CALL AVSTO(SP(IS),SPK(IS))
      CALL AVSTO(SN(IS),SNK(IS))
      CALL AVSTO(TN(IS),TNK(IS))
C     NOW TEST IF IN TOLERANCE
      CALL ATLTST(ITLRET)
      IF(JMIN.EQ.1) ITLRET = 1
C     ITLRET RETURNED AS
C     0 - WITHIN TOLER
C     0 - WITHIN TOLER
C     1 - OUT OF TOLER
C     BRANCH ON J6 -0 FOR PS, 1 FOR DS
      IBR = J6+1
      GO TO (270,280),IBR
C     PS - TEST IF WITHIN TOLER
  270 IF(ITLRET.EQ.0) GO TO 275
C...
C...  OUT OF TOLER- IF JAP = 0 (FIRST TIME THROUGH, REVERSE + RETRY
      IF(JAP.EQ.0) GO TO 287
      CALL AERR (502)
C     OUT OF TOLER OF PS
C     PS OK - CHECK DS
  275 J6 = 1
C...
      IS = IDS
      IIS = IIDS
      GO TO 200
C     DS - SEE IF WITHIN TOLER
  280 IF(ITLRET.EQ.0) GO TO 399
C...
      IF((KPMVTN .EQ. 1) .AND. (LASTDS .NE. 1)) GOTO 1541
      IF((KPMVTN .EQ. 1) .AND. (IAFL(IIS) .GE. 0)) GOTO 1541
C     OUT OF TOLER, SEE IF FIRST TIME IN
      IF(JAP.EQ.0) GO TO 287
      IF(KPMVTN .GT. 1) GO TO 1541
      KPMVTN = KPMVTN + 1
      IF(KPMVTN .EQ. 1) GO TO 1542
      CALL AVSTO(DSTNSV,TN(IS))
      CALL AVSTO(DSTNSV(4),TP(IS))
      CALL AVSUB(TP(IS),TE,VT(IS))
      JENT(IIS) = 0
      GO TO 250
 1542 CALL AVSTO(PMOVE,TN(IS))
      GO TO 200
 1541 CALL AERR(503)
C     OUT OF TOLER ON DS
C
C     REVERSE + RETRY AMIND CALC
  287 JAP = 1
C...
C     TO SHOW SECOND TIME IN
C     IF ON, REVERSE Z WHICH CONTROLS UN CALCULATION. IF OFFSET,REVERSE
C     RC - RADIUS OF CURVATURE
      CALL AVDOT(VT(IS),TA,ANS)
      CALL AVMULT(TA,ANS,VT(IS))
      CALL AVDOT(TN(IS),U1(IS),ANS)
      ANS=ANS+ANS
      CALL AVMULT(U1(IS),ANS,VTEM)
      CALL AVSUB(TN(IS),VTEM,TN(IS))
      IF(ISFTYP(IIS).EQ.3) Z(IS) = -Z(IS)
      IF(ISFTYP(IIS).NE.3) RC(IS) = -RC(IS)
      JMINR = 1
      GO TO 250
C     ESTABLISH FOREWARD DIRECTION
  399 CALL AVSTO(TP(IS),TPK(IS))
      CALL AVSTO(SN(IS),SNK(IS))
      JAP=0
      I = IVAMAX
      IVAMAX = 3
      IF(ITLON(IIDS) .EQ. 0) GO TO 400
      IF((JCNT3.NE.30).OR.(RC(IS).GE.QNUL)) GO TO 400
      ANS = DABS(CUTDAT(1) - CUTDAT(2))
      IF(ANS .LT. QP6X05) GO TO 400
      IF( J24(IIDS) .NE. 2) GO TO 401
      KYO = IPONTR(IIDS) + 7
      CALL AVDOT(CANSTO(KYO),TA,ANS)
      ANS = DABS(ANS)
      IF((ANS.GE.QP6X9).AND.(CUTDAT(1).LT.CANSTO(KYO+3))) GO TO 400
  401 CALL AERR(-3521)
  400 JCNT3 = 25
      IVAMAX = I
C
      PERCEN = VTEM(1)
C
      CALL AFWDSL(0)
C...
C     ESTABLISH TI TO DOT POSITIVELY ON FWD
      CALL ATISEL(0)
      CALL AVCROS(TI,TN(IDS),VTEM)
      CALL AVDOT(VTEM,TA,ANS)
      ANS = ANS*CTOCL
      I = IVAMAX
      IVAMAX=3
      IF(ANS.LT.QNUL) CALL AERR(-1601)
      IVAMAX = I
      JAP = 0
C
C
C     SELECT 2D OR 3D ROUTE
      CALL AROUTE(I)
C     I=2  FOR 2D
C      =3  FOR 3D
      IF(I.EQ.2) GO TO 300
      ICALL = 1
      RETURN
C
C
   10 CONTINUE
C...
C      SEE WHETHER 2D OR 3D ROUTE TO BE USED
      CALL ASTSEL(I)
C     I RETURNED AS 2 OR 3 FOR 2 OR 3D ROUTE
      IF(I.EQ.2) ICALL = 4
      IF(I.EQ.3) ICALL = 3
      RETURN
   11  ICALL = 5
       RETURN
C
  300 CONTINUE
  350 CONTINUE
C     SET UP CALL TO ARLM2
C     CUTDAT(2) = CUTTER RADIUS
C     TH(IDS,ICS) = THICK FOR DS,CS
C     TE          = CUTTER LOCATION
C     TI          = AIMING DIRECTION
C     CANSTO(IPONTR(IIDS)) = 1ST CELL OF DS CANONICAL FORM
C     CANSTO(IPONTR(IICS)) = 1ST CELL OF CS CANONICAL FORM
C     ITOPT = 1,2,3,4 TO,ON,PAST,TANTO...IN...T H A T...O R D E R
C     IFAR(IICS) = INTERSECTION COUNTER
C     TAU(IDS,ICS) TOLERANCES ON PS,DS
C     PERCEN = PERCENTAGE OF DS TOLER USED AT TE LOCATION
C     (THIS USED ONLY IF DS IS CIRCLE)
      KK1 = IPONTR(IIDS)
      KK2 = IPONTR(IICS)
C
      ITOPT = ISFTYP(IICS)
      IF(ISFTYP(IICS).EQ.2)ITOPT = 3
      IF(ISFTYP(IICS).EQ.3) ITOPT = 2
      ICALL = 2
      RETURN
      END

