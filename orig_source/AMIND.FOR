      SUBROUTINE AMIND
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
C
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
      COMMON/KK1083/K1083
      DIMENSION AB(34),TNIBM(3),SNIBM(3),U1IBM(3),TPIBM(3),SPIBM(3)
      DATA AB/    4HAMIN,4HD TP,4HAMIN,4HD 01,4HAMIN,4HD 02,4HAMIN,
     1            4HD 03,4HAMIN,4HD 04,4HAMIN,4HD 05,4HAMIN,4HD 06,
     2            4HAMIN,4HD 07,4HAMIN,4HD 08,4HAMIN,4HD EX,4HAMIN,
     3            4HD 09,4HAMIN,4HD 10,4HAMIN,4HD 11,4HAMIN,4HD 12,
     4            4HAMIN,4HD 13,4HAMIN,4H D14,4HAMIN,4HD 15    /
      SAVETH = TH(IS)
      ITLSEL=1
      KTMADJ = 0
22222 CONTINUE
C...KBESTS = 1 INDICATES WORK ONLY WITH BEST SEGMENT AFTER FAILING FIRST
C...25 ITERATIONS. BEST SEG SENT TO ATLNRM AS NEG VALUE IN IAMDCT.
      KBESTS = 0
      JMIN = 0
      IF(ITLON(IIS) .EQ. 0) TH(IS) = QNUL
       CALL ADYNDP(AB( 1),4,111100)
      ZIGN = Q1P
      NEWMAP = 0
      KSNTN = 0
10101 CONTINUE
      J=IS+2
      JTNMAP = 0
      J40 = 0
      KOUNT = 0
      K1083 = 0
      IAMDCT=0
      IF(NEWMAP.EQ.0) FLIPL=-QP3
      FLIPCK = QNUL
      CALL AVSTO(TN(IS),TNL(IS))
      IF(JENT(IIS))2,12,2
    2 CONTINUE
      IF((IFRL.EQ.1).AND.(IIS.EQ.IIDS).AND.((J24(IIS).EQ.7).OR.(J24(IIS)
     1.EQ.8))) CALL AVSTO(PMOVE,TN(IS))
      CALL AVNORM(TN(IS),TN(IS),IER)
      IF((IGO .GT. 2) .OR. (IER .NE. 0)) CALL AVSTO(TNL(IS),TN(IS))
       IF(JTLFLG(IIS).EQ.1) GO TO 3
      TEMP(1) = QP5 * CUTDAT(7)
      ANS = DMIN1(TEMP(1),CUTDAT(1))
      IF((J24(IIS) .EQ. 4) .AND.(RC(IS) .LT. QNUL)) GO TO 405
      IF(KTMADJ .EQ. 0) ANS = TEMP(1)
  405 CONTINUE
       DO 1 I=1,3
    1 TM(I) = TE(I) + ANS * TA(I)
      CALL AVSTO(TM,TP(IS))
      RC(IS)=RC1
       GO TO 403
    3  CALL AVMULT (TA,TLHITE(65),TP(IS))
       CALL AVADD (TP(IS),TE,TP(IS))
       RC(IS) = RC1
  403 Z(IS) = Q1P
      IF(IAFL(IIS))201,202,218
  201 ITSEG(IIS)=IBEGIN
      GO TO 251
C***
C***
C      NOTE DIFFICULTY HERE
C      HAS DO WITH SECTN2 MODIFICATION
C***
C***
C 218 TP(IS)=TE+SV(IS+130)
C     TP(IS+1)=TE(2)+SV(IS+131)
C     TP(IS+2)=TE(3)+SV(IS+132)
  218 CALL AVADD(TE,CUTH(IS),TP(IS))
       CALL ADYNDP(AB( 3),6,110000)
  251 IF(ITLON(IIS).EQ.0) CALL AVSTO(TE,TP(IS))
      CALL AJUNDD
      IF(JTN(IIS))4,6,4
    4 CALL AVSTO(SN(IS),TN(IS))
      GO TO 9
    6 CALL AVDOT(SN(IS),TN(IS),Z(IS))
      IF(DABS(Z(IS)).LT.QP005) GO TO 6000
 6005 CONTINUE
      Z(IS) = Z(IS)*S(IS)
      Z(IS) = -DSIGN(Q1P,PAST(IS)*Z(IS))
  445 CALL AVMULT(SN(IS),Z(IS),SN(IS))
      CALL AVSUB(VNUL,SN(IS),TN(IS))
      IF(TH(IS) .NE. QNUL) GO TO 9
      IF(ITLON(IIS).NE.0) GOTO 9
      CALL AVDOT(TN(IS),TA,ANS)
      IF(ANS.LT.QNUL) GOTO 9
      CALL AVSUB(VNUL,SN(IS),SN(IS))
      CALL AVSUB(VNUL,TN(IS),TN(IS))
      Z(IS) = -Z(IS)
    9 CALL AJUNDD
       CALL ADYNDP(AB( 5),6,110000)
      CALL ACCURV(IS,IIS,SP(IS),SPL(IS),SN(IS))
      IF(ITLON(IIS))90,338,90
   90 KJU1=JU1(IIS)
      JU1(IIS)=-99
      CALL AU1CMP
      JU1(IIS)=KJU1
      IF(JAP.NE.1) GO TO 92
      CALL AVDOT(U1(IS),TN(IS),ANS)
      IF(ANS.LT. QNUL) CALL AVSUB(VNUL,U1(IS),U1(IS))
   92 CALL AVSTO(U1(IS),OLDU1)
      GOTO  338
   12 CALL AVADD(VT(IS),TE,TP(IS))
      CALL AVMULT(TN(IS),TH(IS),VTEM)
      CALL AVADD(VTEM,TP(IS),TP(IS))
      IF(IAFL(IIS))9,212,9
  338 CONTINUE
  915 CONTINUE
   38 MAP = 0
  712 CALL ATLNRM(U1(IS))
       CALL ADYNDP(AB( 7),6,110000)
      CALL AVMULT(TN(IS),TH(IS),VTEM)
      CALL AVADD (TP(IS),VTEM,TP(IS))
   28 CALL AJUNDD
      IF(K1083 .EQ. 1) GO TO 30
      CALL AVDOT(TN(IS),SN(IS),FLIPCK)
      CALL ADYNDP(AB(9),12,111100)
      ANS=DBLE(FLOAT(JTN(IIS)-1))*FLIPCK
      IF(FLIPL.GT.ANS) GO TO 28801
      IF((MDIC.NE.10).OR.(RDRN.NE.QNUL)) GO TO 28801
      CALL AVSTO(SP(IS),SPIBM)
      SIBM=S(IS)
      IF(FLIPL.GT.DABS(FLIPCK)) GO TO 28801
      CALL AVSTO(TN(IS),TNIBM)
      CALL AVSTO(U1(IS),U1IBM)
      CALL AVSTO(SN(IS),SNIBM)
      FLIPL=ANS
      CALL AVSTO(TP(IS),TPIBM)
      KSEGA1 = ITSEG(IIS)
C...  IF STARTUP, S<3TAU, USE TIGHTER TEST(.6X9) FOR IAMDCT UP TO 22
28801 IF(ISTRUP .NE. 1) GO TO 28802
      IF(IAMDCT .GE. 23) GO TO 28802
      IF(DABS(S(IS)) .GE. Q3P*TAU(IS)) GO TO 28802
      IF(DABS(FLIPCK) - QP6X9) 29,41,41
28802 IF(DABS(FLIPCK) .GT. QP4X95) GO TO 41
   29 IAMDCT=IAMDCT+1
      IF(25-IAMDCT) 132,13111,32
  132 IF(JMINR) 131,131,30
   30 JMIN=1
      IF(JMINR)31,31,48
   31 IF(DABS(FLIPCK) - QP995) 131,131,341
  341 CALL AERR(-1004)
      GO TO 41
  131 CONTINUE
      IF(ISTRUP .NE. 1) GO TO 10541
      IF(NEWMAP .EQ. 0) GO TO 10541
      IF(ITLON(IIS) .NE. 0) GO TO 10541
      IF(KSNTN .NE. 0) GO TO 10541
      KSNTN = 1
      IOPSET(IIS) = 1
      GO TO 28
10541 CONTINUE
      IF(J40.EQ.1) GO TO 1311
      IF(JTLFLG(IIS).NE.1) GO TO 1311
      J40 = 1
      IAMDCT = 0
      GO TO 32
C...
13111 CALL AVSTO(TPIBM,TP(IS))
      CALL AVSTO(TNIBM,TN(IS))
      CALL AVSTO(U1IBM,U1(IS))
      CALL AVSTO(SNIBM,SN(IS))
      FLIPCK = FLIPL
      ZIGN = Q1P
C...
C...
C
      CALL AVDOT(SNIBM,TNIBM,ANS)
      IF(((DBLE(FLOAT(JTN(IIS)-1))*ANS).LT.QNUL).AND.(MAP.LE.0))GOTO 710
11111 CONTINUE
C...
C...
      CALL AMD2(IRET)
      IAMDCT = 25
      IF(IRET .EQ. 1) GO TO 712
      GO TO 30
   32 CALL ACCURV(IS,IIS,SP(IS),SPL(IS),SN(IS))
      CALL ADYNDP(AB(11),6,110000)
      IF(ITLON(IIS)) 91,38,91
   91 CALL AU1CMP
      IF(JU1(IIS))39,33,39
   39 CONTINUE
      GO TO 38
   33 CALL AVDOT(OLDU1,U1(IS),ANS)
      IF(ANS.GE.QNUL) GO TO 39
   34 CALL AVSUB(VNUL,U1(IS),OLDU1)
      CALL AVSTO(OLDU1,U1(IS))
   35 CALL AVDOT(SN(IS),SNL(IS),ANS)
      IF(ANS .GT. QP9) GO TO 39
      IOPSET(IIS)=-1
       CALL ADYNDP(AB(13),6,110000)
      CALL AJUNDD
      IOPSET(IIS)=0
      CALL ACCURV(IS,IIS,SP(IS),SPL(IS),SN(IS))
      GO TO 38
   41 IF(RDRN) 29,802,29
  802 IF(MDIC-10) 29,803,29
  803 IF(DBLE(FLOAT(JTN(IIS) - 1))*FLIPCK) 709,711,711
  709 IF(MAP) 710,710,7100
 7100 IF(JMINR.EQ. 1) GO TO 7101
      IF(NEWMAP.EQ.1) GO TO 131
12345 NEWMAP=1
      IF((J24(IIS).EQ.4).AND.(JTN(IIS).EQ.0)) GO TO 8000
      JENT(IIS) = 1
      JU1(IIS)=1-JU1(IIS)
      GO TO 10101
 7101 IF(NEWMAP .EQ. 0) GO TO 12345
      JMIN = 1
      IF(ITLON(IIS) .EQ. 0) TH(IS) = SAVETH
      RETURN
  710 IF(NEWMAP .EQ. 1) ZIGN = -Q1P
      MAP = 1
      FLIPCK = QNUL
      FLIPL = QNUL
      CALL AVSUB(VNUL,U1(IS),U1(IS))
      CALL AVSUB(VNUL,OLDU1,OLDU1)
      GO TO 712
  711 IF(JTN(IIS).NE.1) GO TO 7111
      IF(FLIPCK.GT.QNUL) GO TO 7111
      IF(JTNMAP.EQ.1) CALL AERR(1009)
C  CALL AERR(-1008) IS DELETED.  3-6-68
      JTNMAP = 1
      CALL AVSTO(TN(IS),TNL(IS))
      FLIPCK = QNUL
      FLIPL = QNUL
      GO TO 9
 7111 JMIN = 0
      IF(IPL(IIS))42,42,346
   42 TEMP(1)=TAU(IS)-EPS8(IS)
      IF(RC(IS))49,49,43
   49 IF(JTN(IIS))45,44,45
   43 IF(JTN(IIS))44,45,44
   44 TEMP(1) =  EPS8(IS)
   45 S(IS)=S(IS)-TAU2(IS)-TEMP(1)
       CALL ADYNDP(AB(15),6,110000)
  346 IF (IFRL .EQ. 0) GO TO 347
      IF (IAMDCT.GE.21) GO TO 347
      CALL ATLTST (ITLRET)
      IF(ITLRET .NE. 0) GO TO 29
  347 IF(JENT(IIS)) 215,46,215
  215 CALL AVSTO(TP(IS),TPK(IS))
      CALL AVSTO(SP(IS),SPK(IS))
      CALL AVSTO(SN(IS),SNK(IS))
      JENT(IIS)=0
      IF(IS.GT.IDS) GO TO 46
      CALL AVSTO(TN(IS),TNK(IS))
   46 CONTINUE
       CALL ADYNDP(AB(17),6,110000)
      IF(IOPSET(IIS))47,51,51
   47 IOPSET(IIS)=0
   51 CALL AVSUB(TP(IS),TE,VT(IS))
      CALL AVMULT(TN(IS),TH(IS),VTEM)
      CALL AVSUB(VT(IS),VTEM,VT(IS))
   48 CONTINUE
       CALL ADYNDP(AB(19),4,111100)
      IF(ITLON(IIS) .EQ. 0) TH(IS) = SAVETH
      RETURN
  202 IC = IPONTR(IIS) +4
  203 CALL AVSTO(CANSTO(IC),TN(IS))
      CALL AVDOT(TP(IS),CANSTO(IC),ANS)
      IF((PAST(IS)*(CANSTO(IC+3) - ANS)).LT.QNUL) GO TO 205
  302 SPAST(IS) = Q1P
  204 IF(ITLON(IIS)) 501,502,501
  502 CALL AVSTO(TE, TP(IS))
      GO TO 305
  501 IF(IPS -IS) 303,304,303
  304 TEMP(1) = QP5 * CUTDAT(7)
      ANS = DMIN1(TEMP(1),CUTDAT(1))
      IF(KTMADJ .EQ. 0) ANS = TEMP(1)
      CALL AVMULT(TN(IS),ANS,VTEM)
      CALL AVADD(TP(IS),VTEM,TP(IS))
       CALL ADYNDP(AB(21),6,110000)
      GO TO 305
  303 CALL AVMULT (TN(IS),CUTR(IS),VTEM)
      CALL AVADD(VTEM,CUTH(IS),VTEM)
      CALL AVADD(VTEM,TE,TP(IS))
C
  305 CALL AVDOT(TP(IS),CANSTO(IC),ANS)
      S(IS) = SPAST(IS)*(CANSTO(IC+3) - ANS)
       CALL ADYNDP(AB(23),6,110000)
      GO TO 206
  205 CALL AVSUB(VNUL,TN(IS),TN(IS))
      SPAST(IS) = -Q1P
      GO TO 204
  206 IF(JTN(IIS))207,208,207
  207  Z(IS) = SPAST(IS)
      CALL AVSTO(TN(IS),SN(IS))
      CALL AVSTO(TN(IS),U1(IS))
      GOTO209
  208 Z(IS) = -SPAST(IS)
      CALL AVSUB(VNUL,TN(IS),SN(IS))
  209 RC(IS)=RC1
       CALL ADYNDP(AB(25),6,110000)
      CALL AVSTO(SN(IS),SNL(IS))
      ISIGCR(IIS)=-1
  210 S(IS) = S(IS) - TH(IS)
      CALL AVMULT (TN(IS),TH(IS),VTEM)
      CALL AVADD(TP(IS),VTEM,TP(IS))
  213 SP(IS) = TP(IS) + S(IS)*TN(IS)
      SP(IS+1)=TP(IS+1)+S(IS)*TN(IS+1)
      SP(IS+2)=TP(IS+2)+S(IS)*TN(IS+2)
      CC(IS)=SP(IS)-RC(IS)*SN(IS)
      CC(IS+1)=SP(IS+1)-RC(IS)*SN(IS+1)
       CALL ADYNDP(AB(27),6,110000)
      CC(IS+2)=SP(IS+2)-RC(IS)*SN(IS+2)
      IF(JENT(IIS))211,46,211
  211 CALL AVSTO(SP(IS),SPL(IS))
      GOTO215
  212 IC = IPONTR(IIS) + 4
      IF(JTN(IIS))214,307,214
C
  307 CALL AVDOT(TP(IS),CANSTO(IC),ANS)
      S(IS) = SPAST(IS)*(CANSTO(IC+3)-ANS)
C
      CALL AVSTO(SP(IS),SPL(IS))
       CALL ADYNDP(AB(29),6,110000)
      GO TO 213
  214 CALL AVDOT(TN(IS),U1(IS),ANS)
      IF(ANS.LT.QNUL) GO TO 309
  308 CALL AVSTO(U1(IS),TN(IS))
      CALL AVMULT(TN(IS),TH(IS),VTEM)
      CALL AVADD (VTEM,VT(IS),VTEM)
      CALL AVADD(VTEM,TE,TP(IS))
      GO TO 307
  309 CALL AVSUB(VNUL,U1(IS),TN(IS))
      SPAST(IS) = - SPAST(IS)
      CALL AVSTO(SN(IS),SNL(IS))
      CALL AVSUB(VNUL,SN(IS),SN(IS))
      CALL AVSTO(TN(IS),U1(IS))
      Z(IS)=-Z(IS)
       CALL ADYNDP(AB(31),6,110000)
      QQ = CUTR(IS) + TH(IS)
      CALL AVMULT(TN(IS),QQ,VTEM)
      CALL AVADD(TE,CUTH(IS),TP(IS))
      CALL AVADD(TP(IS),VTEM,TP(IS))
       CALL ADYNDP(AB(33),6,110000)
      GO TO 307
 6000 KOUNT = KOUNT + 1
      IF(KOUNT.GT.10) GO TO 6005
      Z(IS) = Q1P
      CALL AVADD(TN(IS),SN(IS),TN(IS))
      CALL AVNORM(TN(IS),TN(IS),IER)
      GO TO 251
 1311 IF((ISTRUP.NE.1).OR.(KTMADJ.NE.0)) GO TO 1312
      KTMADJ = 1
      GO TO 22222
 8000 Z(IS)=-Z(IS)
      IAMDCT=0
      CALL AVSUB(VNUL,U1(IS),U1(IS))
      CALL AVSTO(U1(IS),OLDU1)
      GO TO 38
 1312 CALL AVDOT(TNIBM,SNIBM,FLIPCK)
      IF((FLIPL.EQ.-Q3P).OR.(DABS(FLIPCK).LT.QP995))CALL AERR(1002)
      IF(DABS(FLIPCK).LT.0.9995D0) CALL AERR(-1004)
      CALL AVSTO(TPIBM,TP(IS))
      CALL AVSTO(TNIBM,TN(IS))
      CALL AVSTO(SPIBM,SP(IS))
      CALL AVSTO(SNIBM,SN(IS))
      CALL AVSTO(U1IBM,U1(IS))
      S(IS)=SIBM
      GO TO 711
      END

