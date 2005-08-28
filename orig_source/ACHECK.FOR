      SUBROUTINE ACHECK
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
     4NREC      ,IRECNO    ,ITRFLG    ,NW        ,IDUMMY
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
      DIMENSION TESAV(3), VTSAV(3)
      DIMENSION AB(44)
      DIMENSION TISAVE(3)
      DATA AB( 1),AB( 2)/4HACHE,4HCKTP/,    AB( 3),AB( 4)/4HACHE,4HCK01/
     1,    AB( 5),AB( 6)/4HACHE,4HCK02/,    AB( 7),AB( 8)/4HACHE,4HCK03/
     2,    AB( 9),AB(10)/4HACHE,4HCK04/,    AB(11),AB(12)/4HACHE,4HCK05/
     3,    AB(13),AB(14)/4HACHE,4HCK06/,    AB(15),AB(16)/4HACHE,4HCK07/
     4,    AB(17),AB(18)/4HACHE,4HCK08/,    AB(19),AB(20)/4HACHE,4HCKEX/
     5,    AB(21),AB(22)/4HACHE,4HCK09/,    AB(23),AB(24)/4HACHE,4HCK10/
     6,    AB(25),AB(26)/4HACHE,4HCK11/,    AB(27),AB(28)/4HACHE,4HCK12/
     7,    AB(29),AB(30)/4HACHE,4HCK13/,    AB(31),AB(32)/4HACHE,4HCK14/
     8,    AB(33),AB(34)/4HACHE,4HCK15/,    AB(35),AB(36)/4HACHE,4HCK16/
     9,    AB(37),AB(38)/4HACHE,4HCK17/,    AB(39),AB(40)/4HACHE,4HCK18/
      DATA AB(41),AB(42)/  4HACHE,4HCK19/,AB(43),AB(44)/4HACHE,4HCK20/
C...
C...
C***ACHECK TP***
      CALL ADYNDP(AB( 1),3,111111)
      IF (ISFTYP(IIS) - 4) 400,401,401
  400 CALL AVMULT(TI,PAST(IS),TN(IS))
  401 IF(J20(IIS) - 1) 1,8,3
    1 JWR=0
      CALL AVSTO(TI,TISAVE)
C***ACHECK 01***
      CALL ADYNDP(AB( 3),5,110000)
      STCK(IS) = Q1PE6
      CSD(IS) = QNUL
      J20(IIS)=1
      J21(IIS)=1
      J22(IIS)=0
    2 IOPSET(IIS)=0
      IF(ICSCNT .GT. 1) GO TO 333
C... IF(PLANE PS,DS) AND (TO,CS), AND MOTION, LOOK ONLY +
      IF(ISTRUP .EQ. 1) GO TO 333
      IF(CSD(IS) .EQ. QNUL) GO TO 333
      IF((IPDPL .EQ. 1) .AND. (ISFTYP(IIS) .EQ. 1)) IOPSET(IIS) = 1
C...
  333 CONTINUE
C***ACHECK 02***
      CALL ADYNDP(AB( 5),5,110000)
      JTN(IIS)=1
      JU1(IIS)=1
      JIOPS(IIS)=0
C...
C...
      GO TO 9
    3 IF(DABS(TI(1)).GE. DABS(TI(2)))GO TO 9999
      IF(DABS(TI(3)).GE. DABS(TI(2)))GO TO 9998
      KAT = 2
      GO TO 9996
 9999 IF(DABS(TI(1)).GE. DABS(TI(3)))GO TO 9997
 9998 KAT = 3
      GO TO 9996
 9997 KAT = 1
 9996 CONTINUE
      CALL AVSTO(TEE(IS),VTEM)
      IF(TI(KAT) .GE. QNUL) GO TO 9995
      IF(VTEM(KAT) .GE. TE(KAT)) GO TO 7
      GO TO 9994
 9995 IF(VTEM(KAT) .LE. TE(KAT)) GO TO 7
 9994 CONTINUE
      CALL AVSUB(TEE(IS),TEK,VTEM)
      CALL AVDOT(VTEM,TIK,ANS)
C***ACHECK 03***
      CALL ADYNDP(AB( 7),5,110000)
      IF(ANS.GT.EPS1(IS)) GO TO 66
C.....................................ERROR -822
    4 CALL AERR(-822)
      S(IS) = Q3P*DP
      CSD(IS) = QNUL
C***ACHECK 04***
      CALL ADYNDP(AB( 9),5,110000)
      GOTO11
C...
C...
   66 J21(IIS)=0
      CALL AVSUB(TEE(IS),TEK,CMOVE)
      CALL AVSUB(TE,TEK,TEMP)
      CALL AVLENG(CMOVE,CSD(IS))
      CALL AVNORM(CMOVE,TEM,IER)
      CALL AVLENG (TEMP,VTEM)
      CALL AVNORM(TEMP,TEMP,IER)
      CSD(IS) = (CSD(IS)-VTEM(1))*(DPI/ZL)*Q1P1
C***ACHECK 05***
      CALL ADYNDP(AB(11),5,110000)
      IF(CSD(IS)-EPS1(IS))7,7,16
    7 CALL AVSTO(TEE(IS),TE)
      GO TO 18
C...
C...................................................SUBS ENTRY........
    8 S(IS)=S(IS)-DP
C***ACHECK 06***
      CALL ADYNDP(AB(13),5,110000)
      IF(J21(IIS).EQ.1) GO TO 1
      CALL AVDOT(TI,TISAVE,ANS)
      IF(DABS(ANS) .LE. QP866) GO TO 9
      IF((IPL(IIS).EQ.1).AND.(ITLON(IIS).EQ.0).AND.(MULTAX.EQ.2))GO TO 9
      IF((ISFTYP(IIS) .EQ. 4) .AND. (S(IS) .LT. (Q2P5 * DP))) GO TO 9
      IF((ISFTYP(IIS).EQ.4).AND.((J24(IIS).NE.7).OR.(J24(IIS).NE.8)))
     1 GO TO 9
      IF(J24(IIPS) .EQ. 3) GO TO 9
      IF(S(IS) - Q2P*DP)9,11,11
C                                      NORMAL DIST CALC TO CS
    9 JMINR=1
      JENT(IIS) = 1
      IREJCT = 0
C***ACHECK 07***
      CALL ADYNDP(AB(15),5,110000)
C...
   99 CALL AMIND
C...
C***ACHECK 08***
      CALL ADYNDP(AB(17),5,110000)
      JMINR=0
      IF(JMIN .NE. 0) GO TO 10
      IF(MULTAX .NE. 2) GO TO 1269
      IF(IPL(IIS) .NE. 1) GO TO 1269
      IF(ITLON(IIS) .NE. 0) GO TO 1269
      IF(DABS(S(IS)) .LT. (Q2P * DP)) GO TO 18
 1269 CONTINUE
      IF(JMIN)10,19,10
   10 S(IS) = QNUL
   11 J21(IIS)=0
   12 IF(CSD(IS)-EPS1(IS))13,15,15
   13 IF(ISTRUP)14,14,16
   14 CSD(IS) = Q2P*DPMX1(IS)
   15 IF(STCK(IS).LE.QNUL) GO TO 18
      IF((ISFTYP(IIS).GE.4).AND.(CSD(IS).LE.DP)) GO TO 18
   16 JCKR=0
C...
   17 CONTINUE
C***ACHECK EX***
      CALL ADYNDP(AB(19),3,111100)
      RETURN
C*********************************************************************
   18 J50(IIS)=1
C***ACHECK 09***
      CALL ADYNDP(AB(21),5,110000)
      J51(IIS)=1
      PLND1(IS) = QNUL
      NOTAN(IIS)=0
      JCKR=1
      GO TO 17
C...
   19 IF(ISFTYP(IIS) - 4) 190,22,22
  190 IF(J23(IIS)) 20,21,20
   20 STCK1(IS)=Z(IS)*S(IS)
      J23(IIS)=0
      IF(IREJCT .NE. 0) GO TO 21
      GO TO 22
C...
   21 STCK(IS)=STCK1(IS)*Z(IS)*S(IS)
   22 CALL AVDOT(SN(IS),TI,COS1(IS))
C...
C***ACHECK 10***
      CALL ADYNDP(AB(23),5,110000)
      IF(ISFTYP(IIS)-2)23,30,39
   23 IF(COS1(IS))24,25,25
   24 CALL AVSUB(VNUL ,TN(IS),TN(IS))
      J23(IIS)=1
      IREJCT = IREJCT + 1
      IF(IREJCT .GT. 6) GO TO 11
C...
C***ACHECK 11***
      CALL ADYNDP(AB(25),5,110000)
      GO TO 99
C...
   25 IF(EPS6(IS)-S(IS))26,26,32
   26 IF(COS1(IS))27,28,27
   27 CSD(IS) = DABS(S(IS)/COS1(IS))
C***ACHECK 12***
      CALL ADYNDP(AB(27),5,110000)
      IF(ISFTYP(IIS) .NE. 1) GO TO 29
      IF((IPDPL .EQ. 1) .AND. (S(IS) .GT. QNUL)) J21(IIS) = 0
      GO TO 29
C...
   28 CSD(IS) = DABS(S(IS))+TAU(IS)
   29 IF((IPDPL .EQ. 1) .AND. (J21(IIS) .EQ. 0)) GO TO 18
      IF(DP - CSD(IS))11,201,201
  201 IF(J50(IIS)) 202,18,18
  202 IF(TAU(IS) - CSD(IS)) 11,18,18
   30 IF(COS1(IS))31,31,24
   31 IF(EPS6(IS)-S(IS))32,32,26
   32 IF(J21(IIS)) 301,301,33
  301 IF (IPDPL) 15,15,18
   33 CALL AVSTO(TP(IS),TEMP)
      CALL AVSTO(TN(IS),TEMP(4))
      CALL AVMULT(TI,TAU(IS),VTEM)
      CALL AVADD(SP(IS),VTEM,TP(IS))
      IF((ISFTYP(IIS) .NE. 2).AND.(ICSCNT .LE. 1))CALL AVSTO(TE,TP(IS))
      CALL AVSTO(TI,TN(IS))
      IOP(IIS)=1
      TEMP(7)=S(IS)
C***ACHECK 13***
      CALL ADYNDP(AB(29),5,110000)
      IF(LIMFL(IIS))34,35,34
   34 CALL DDLIMT
      GO TO 36
C...
   35 CALL ADDST
   36 CALL AVSTO(TEMP,TP(IS))
      CALL AVSTO(TEMP(4),TN(IS))
      IF(IER)38,55,38
   38 CSD(IS) = QNUL
      S(IS) = DABS(S(IS))
      J23(IIS) = 1
      GO TO 12
C...
   39 IF(3-ISFTYP(IIS))40,23,40
   40 CPTST(IS) = QNUL
      CPLFL(IS) = QNUL
C...
C***ACHECK 14***
      CALL ADYNDP(AB(31),5,110000)
C...
      CALL ACPLAN
C...
C***ACHECK 15***
      CALL ADYNDP(AB(33),5,110000)
      IT=IT
      CSD(IS) = DABS(PLND(IS))
      IF(CSD(IS).LT.DABS(S(IS))) CSD(IS) = DABS(S(IS))
      IF(JCPR) 41,45,41
C...WARNING MESSAGE(-821)
   41 CALL AERR(-821)
      GO TO 11
   45 CONTINUE
      CALL AVDOT(TA,EZ,ANS)
      IF(DABS(ANS) .LT. QP4X95) GO TO 321
      IF(ICSCNT .LE. 1) GO TO 321
      IF((J24(IIT).NE.2) .OR. (J24(IIS).NE.2)) GO TO 321
      KIIT = IPONTR(IIT)
      KIIS = IPONTR(IIS)
      CALL AVDOT(TA,CANSTO(KIIT+7),ANS)
      IF(DABS(ANS) .LT. QP4X95) GO TO 321
      CALL AVDOT(TA,CANSTO(KIIS+7),ANS)
      IF(DABS(ANS) .LT. QP4X95) GO TO 321
      CALL AVSUB(CANSTO(KIIS+4),CANSTO(KIIT+4),VTEM)
      CALL AVCROS(TA,VTEM,VTEM)
      VTEM(3) = QNUL
      CALL AVNORM(VTEM,VTEM,IER)
      IF(IER .NE. 0) GO TO 321
      VTEM(3)=VTEM(1)*CANSTO(KIIT+4) + VTEM(2)*CANSTO(KIIT+5)
      ANS=VTEM(1)*TE(1) + VTEM(2)*TE(2) - VTEM(3)
      CSD(IS) = DABS(ANS)
  321 CONTINUE
C...USE SP OF THE TANGENT SURFACE TO COMPUTE STCKN
      IF(IPDPL.EQ.1) GO TO 18
C...
      CALL AVSTO(TE,TESAV)
      ITLSAV = ITLON(IIS)
      ITLON(IIS) =0
      CALL AVSTO(SP(IT),TE)
      SSAV = S(IS)
      CALL AVSTO(VT(IS),VTSAV)
      JENT(IIS) = 1
      JMINR = 1
C...
      CALL AMIND
C...
C***ACHECK 16***
      CALL ADYNDP(AB(35),5,110000)
      JMINR = 0
      CALL AVDOT(SN(IS),TI,COS1(IS))
      STCKN(IS) = S(IS)*COS1(IS)
      ITLON(IIS) = ITLSAV
      CALL AVSTO(VTSAV,VT(IS))
      CALL AVSTO(TESAV,TE)
      ANS = S(IS)
      S(IS) = SSAV
      SSAV = ANS
      IF(JMIN.NE.0) GO TO 11
C      SEE IF FIRST ENTRY OR IF CS NOT FORWAED YET
      IF(J22(IIS).EQ.0) GO TO 50
C...
C      NOT FIRST ENTRY
 4321 CONTINUE
C***ACHECK 17***
      CALL ADYNDP(AB(37),5,110000)
      IF(STCKN(IS).LT.QNUL) GO  TO 18
      IF(DABS(SSAV ).LT.DP) GO TO 18
      IF(DABS(PLND(IS)).LT.(Q2P*DP)) GO TO 18
      CALL AVDOT(TA,PLNV(IS),ANS)
      IF(DABS(ANS) .LT. QP4X05) GO TO 11
      IF(DABS(S(IS)).LT.(Q2P*DP)) GO TO 18
      GO TO 11
C...
   50 CONTINUE
C       FIRST ENTRY OR CS NOT AHEAD YET
C***ACHECK 18***
      CALL ADYNDP(AB(39),5,110000)
      IF((ICSCNT .GT. 1) .OR. (IFAR(IIS) .GT. 1)) GO TO 1234
      IF(IPL(IIT) .NE. 1) GO TO 1234
      IF(PLND(IS) .GE. (Q2P*DP)) GO TO 1234
      STCK2(IS) = STCKN(IS)
      J22(IIS) = 1
      GO TO 4321
 1234 CONTINUE
      IF(DABS(SSAV ).LT.QP001) GO TO11
      IF(DABS(COS1(IS)).LT.QP001) GO TO 11
      IF(DABS(SSAV).LT.DABS(TH(IS))) GO TO 56
      IF(STCKN(IS).LT.QNUL) GO TO 11
   56 CONTINUE
      STCK2(IS) = STCKN(IS)
      J22(IIS) = 1
      GO TO 11
C...
   52 IF(CSD(IS) - Q2P*DP)53,12,12
   53 CALL AVMULT(TI,ANS,CMOVE)
      IF(ANS .LT. CSD(IS)) CSD(IS) = CSD(IS) - ANS
C... WHEN PLANE (PS,DS), CSD = .9*S----S IS DIST FROM INITIAL SP TO
C... CS IN DIRECTION OF TI
      IF(IPDPL .EQ. 1) CSD(IS) = ANS
      CALL AVADD(TE,CMOVE,TE)
C***ACHECK 19***
      CALL ADYNDP(AB(41),5,110000)
      GO TO 18
C...
   55 CSD(IS) = DABS(TEMP(7)/COS1(IS)+S(IS)+TAU(IS))
      TEMP(8)=S(IS)
      ANS = QP9 * S(IS)
      IF(CSD(IS) - Q5P*DP)101,102,102
  101 S(IS)=CSD(IS)
      GO TO 152
C...
  102 S(IS) = Q5P*DP
C***ACHECK 20***
      CALL ADYNDP(AB(43),5,110000)
  152 IF(S(IS) - DABS(TEMP(7))) 153,52,52
  153 S(IS) = DABS(TEMP(7))
      GOTO52
       END

