       SUBROUTINE ASEC2B (ISTX1,ISTX2)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4  AB
       COMMON /A2BURP/ ADENTC,ADENT,ADUMMY,ANS
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
     4QPIE       ,QFIL(9)
C     *****
C     *****
      DIMENSION IPRO(1)
      EQUIVALENCE (IPRO(1),PROBUF(1))
C     *****
      INTEGER*2 KTEM(4)
      EQUIVALENCE (TEMP(1),KTEM(1))
      REAL*8 TABID(25)
      DATA TABID/25*0.D0/,NUMID/0/
C...
C...
C...IF ISTX1=6078, CLASS=6000 AND SUBCLASS=7 OR 8
C   CALLED FROM ASEC2 RIGHT AFTER ATAPRD(PROTAP...)
      IF(ISTX1 .EQ. 6078) GO TO 607
C...
       GO TO (6000,6300,8300,8000),ISTX1
C      ALSO, DO NOT PROCESS INTOF RECORDS WHEN NOT RESTARTING
 6300 IF((INSTR2.EQ.7).OR.(INSTR2.EQ.8)) GO TO 8300
      IF(INSTR2.EQ.3) GO TO 200
      GO TO 6000
C     MOTION DIRECTION FOR CUTSEQ INITIALIZE + READ PROTAP
 8300 IGTFLG = 0
      INDIR (IIPS) = 0
      INDIR (IIDS) = 0
      INDIR (IICS) = 0
      ICSCNT = 0
      GOTO 200
C
C
C
C     6000 CLASS FLAGS + SWITCHES
 6000 IF(INSTR2 .GT. 9) CALL AERR(2)
      GOTO(6010,6020,6030,6040,6040,6060,607,607,6090),INSTR2
C
C     -GET INTEGER FROM PROBUF     CUT,DNTCUT
 6010 CALL ASTOR(PROBUF(1),8,I,2)
C     IF NOT MODE CHANGE, OUTPUT + IGNORE
      IF(I.EQ.ICUT) GOTO 2000
      IF(I.NE.0) GO TO 6011
C     CHANGE FROM DONT CUT TO CUT- OUTPUT POINT
      NW = 0
      ICL = 5
      CALL ASTOS
      ICUT = 0
      CALL ATAPE
      GO TO 2000
 6011 ICUT = 1
      IF(I.EQ.2) ICUT = -1
      IPRO(2) = 1
      GO TO 2000
C     I3DCALC FLAG
 6020 CALL ASTOR(PROBUF(1),8,I3DFLG,2)
      GOTO 2000
C     IFAR
 6030 I = 1 + LISV*(ICSCNT + 2)
      ANS= PROBUF(1)
      IIK = ANS
      IFAR(I) = IIK
      GO TO 200
C
C     TOLERANCES
 6040 DO 6049 K=1,NWDS
      I=1+LSV*(K-1)
C     INTOL OR OUTTOL
      IF(INSTR2.EQ.4) GOTO 6041
C     OUTTOL
      TAU1(I)=PROBUF(K)
      GOTO 6045
C     INTOL
 6041 TAU2(I)=-PROBUF(K)
C
C     SET UP OTHER EPSILONS
 6045 TAU(I)=TAU1(I)-TAU2(I)
      EPS1(I) = QP1*TAU(I)
      EPS8(I)=EPS1(I)
      EPS2(I) = Q1P - EPS1(I)
      EPS3(I) = QP9*EPS1(I)
      EPS4(I) = Q2P*TAU(I)
 6049 EPS6(I) = QP02*EPS1(I)
      CEND(1) = QNUL
      GOTO 2000
C
C     CUTTER DEFINITION
 6060 IF(NWDS.NE.3) GO TO 6160
C      OPTION CUTTER
      RA = PROBUF(2)
      HI = PROBUF(3)
      ANS = PROBUF(1)
      K = ANS
      JTLFLG(IIPS) =0
      JTLFLG(IIDS) = 0
      IF(K.EQ.1) JTLFLG(IIPS) = 1
      IF(K.EQ.2) JTLFLG(IIDS) = 1
      GO TO 2000
 6160 DO 6061 K=1,7
 6061 CUTDAT(K) = QNUL
      DO 6062 K=1,NWDS
6062  CUTDAT(K)=PROBUF(K)
      CALLATLSEG
      ICDEFL=1
C      TO INDICATE THAT THE CUTTER IS DEFINED
      GOTO 2000
C
C     TRANTO
 6070 CALL ASTOR(PROBUF(1),8,ITRFLG,2)
      ADENTC = PROBUF(2)
 6071 ISRCH=2
C     SEE IF FWD OR BACKWARD TRANSFER
 6072 IF(ITRFLG.EQ.0) GO TO 200
C     NO, BACKWARD
      CALLASERCH(PROTAP,ITRFLG,IER)
C       INSERT ERROR FLAG TEST
      GOTO 200
C
C     MULTI CS TRANSFER
 6080 K = 1 + (ICSCNT+1)*LSV
      IK = 1 + (ICSCNT +1)*LISV
      CALL ASTOR(PROBUF(1),8,ICSTR(IK),2)
      ADCS(K)=PROBUF(2)
      GOTO 200
C
C      DYNDMP  ---   SET  PARAMETERS
 6090 CONTINUE
C
C...  SET DYNAMIC DUMPING FREQUENCIES
C
      IF(NWDS.LT.2) GO TO 200
      KDYNFQ(7) = 0
      DO 6091 I=1,NWDS,2
      ANS = PROBUF(I)
      K =  ANS
      ANS = PROBUF(I+1)
      IF(K.GT.0) GO TO 6092
      KK = ANS
      CALL CDYNDP(1,KK)
      GO TO 6091
 6092 CONTINUE
      KDYNFQ(K) = ANS
 6091 CONTINUE
      NKFQ = 1
      K=0
      DO 6093 I=1,12
      IF(KDYNFQ(I).EQ.0) GO TO 6093
      K=1
 6093 CONTINUE
      CALL CDYNDP(3,K)
      GO TO 200
C
C     GO COMMAND
C     SET IGO
 8000 IGO = INSTR2
      ISTRUP = 0
C     IF CUTTER NOT DEFINED ERROR
      IF(ICDEFL.EQ.0) CALL AERR(312)
C...
      CALL ARPDIS
C...
C     SEE IF MULTICS
      IF(ICSCNT.LE.1) GOTO 8001
C     SET UP INFO FOR TRANTO
      ADENTC = ADCS(IS)
      ITRFLG = ICSTR(IIS)
      I = 1
      GOTO 8002
C     NO T MULTI CS
 8001 I = 0
C     RESET
 8002 ICSCNT = 0
      INDIR(IIPS) = 0
      INDIR(IIDS) = 0
      INDIR(IICS) = 0
      ISVFL(IIPS) = 0
      ISVFL(IIDS) = 0
      ISVFL(IICS) = 0
C     RESET INTERSECTION COUNTER
      DO 8005 K=3,NUMSFS
      KK = 1+(K-1)*LISV
 8005 IFAR(KK) = 1
C     IF MULTICS, GO TO MULT CS TRANSFER AREA
      IF(I.NE.0) GO TO 6071
      GOTO 200
  200 ISTX2 = K1
       RETURN
 2000 ISTX2 = K2
       RETURN
C***********************************************************************
C
C...UPON ENTRY, JUMP IS MADE TO 607 WHEN CLASS=6000 AND
C                                        SUBCLASS=7 ... TRANTO/ID  OR
C                                                = 8 ... MULTI-CS
C...WHEN TEMP(1)=PROBUF(2) AND KTEM(4)=KND ARE EXECUTED, TEMP(1) WILL
C   CONTAIN ALPHAMERIC NAME ID IN FIRST 6 BYTES AND ISN IN LAST 2 BYTES
C   NOTE.EQUIVALENCE(TEMP(1),KTEM(1))
C       KTEM(1)=FIRST 2 BYTES OF TEMP(1)
C       KTEM(2)=SECOND 2 BYTES OF TEMP(1)
C       KTEM(3)=THIRD 2 BYTES OF TEMP(1)
C       KTEM(4)=FOURTH 2 BYTES OF TEMP(1)
C...IF CURRENT ID IN QUESTION IS ALREADY IN TABID, FORCE FWD TRANSFER.
C...ID IS SAVED IN TABID ONLY WHEN SEC.1 SAYS IT IS A FWD TRANSFER.
C
  607 TEMP(1) = PROBUF(2)
      KTEM(4)=KND
      NUMMAX=MIN0(NUMID,25)
      DO 608 K=1,NUMMAX
      IF(TEMP(1) .NE. TABID(K)) GO TO 608
C...IF ISTX1=6078, JUST RETURN.
      IF(ISTX1 .EQ. 6078) GO TO 200
      PROBUF(1)=QNUL
      GO TO 615
  608 CONTINUE
      IF(PROBUF(1) .GT. QNUL) GO TO 615
      NUMID = NUMID + 1
      IF(NUMID .LT. 25) GO TO 609
      WRITE(IOUTAP,610)
  610 FORMAT(1H ,'ID TABLE FULL - CHECK FOR BAD MULTI-CS OR TRANTO BRANC
     1HING')
  609 K=MOD(NUMID,25)
      TABID(K)=TEMP(1)
C...IF ISTX1=6078, JUST RETURN.
  615 IF(ISTX1 .EQ. 6078) GO TO 200
      IF(INSTR2 .EQ. 7) GO TO 6070
      GO TO 6080
      END

