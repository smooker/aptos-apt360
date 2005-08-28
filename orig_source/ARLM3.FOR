      SUBROUTINE ARLM3
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
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
     2 J40,J43,J54,J103,PROBUF(100),CANSTO(2000),IER,INSTR1,INSTR2,
     3 NWDS , ICL , NREC ,IRECNO ,ITRFLG , NW , IDUMMY
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
      COMMON/ATANCO/KTTRY2
C***
      DIMENSION TEW(3),PSTN(3),DSTN(3),TAE(3)
C***
C***
       DIMENSION AB(40)
      DATA AB/    4HARLM,4H3 TP,4HARLM,4H3 01,4HARLM,4H3 02,4HARLM,
     1            4H3 03,4HARLM,4H3 04,4HARLM,4H3 05,4HARLM,4H3 06,
     2            4HARLM,4H3 07,4HARLM,4H3 08,4HARLM,4H3 09,4HARLM,
     3            4H3 10,4HARLM,4H3 11,4HARLM,4H3 12,4HARLM,4H3 13,
     4            4HARLM,4H3 14,4HARLM,4H3 15,4HARLM,4H3 16,4HARLM,
     5            4H3 17,4HARLM,4H3 18,4HARLM,4H3 EX    /
C...
C...
      ISSTOP = -100
      KSTOP = 0
C***ARLM3 TP***
       CALL ADYNDP (AB(1),1,111111)
      K805 = 0
C...
      K804 = 0
C      SET IFRL SO DD AND UN ROUTINES WILL CALL PROPER LS ROUTINE
      ICL=5
      JBR=0
C...NOGOOD..MC- WHEN 3 SURF ITER FAILS, THAT ICS IGNORED FOR NEXT TIME
C...THIS IS DONE JUST ONCE
      NOGOOD = 0
      IF(KTTRY2 .EQ. 1) GO TO 12
      I3STRY =0
      ICSRJ1 = 0
      ICSRJ2 = 0
      CSDSAV = Q130P
C...
      ILS1 = 1 + (2+ICSCNT)*LSV
      IILS1 = 1 + (2+ICSCNT)*LISV
C...
      NW=0
      NUMPT1=NUMPTS
      KGOTBE = 0
C...
      CALL AVSTO(TE,TEK)
      CALL AVSTO(TE,TEW)
      CALL AVSTO(TA,TAK)
      IPDPL = 0
      IF((IPL(IIPS).EQ.1).AND.(IPL(IIDS).EQ.1))  IPDPL=1
C...
    2 DO 3 I=1,3
      TIK(I)=TI(I)
      DO3K=ICS,ILS1,LSV
      L=K+I-1
    3 TN(L)=TI(I)
C...
  602 J12=0
      IS=ICS
      IIS = IICS
      J10=1
      DP=DPMAX
      DO601I=ICS,ILS1,LSV
  601 DPMX1(I)=DPMAX
C...
      DO 6601 I=IICS,IILS1,LISV
      J20(I)=0
      J23(I)=1
      J50(I) = -IPDPL
      J51(I) = 0
      ICHKCT(I) = 0
      NOTAN(I)=0
 6601 CONTINUE
C...
      CALL AVSTO(SP(IPS),SP(501))
      CALL AVSTO(SP(IDS),SP(504))
      IF(IPDPL) 207,203,207
C...
  207 CONTINUE
      CALL AVSTO(SP(501),SP(IPS))
      CALL AVSTO(SP(504),SP(IDS))
      CALL AVSTO(TAK,TA)
C...
    5 IF((IPDPL .EQ. 1) .AND. (ICHKCT(IIS) .EQ. 1)) GO TO 69696
C...
      IS = ICS
      IIS = IICS
      IWS=IS
      IIWS = IIS
      DP1 = Q1PE6
C...
    6 CALL AVSTO(TEW,TE)
C...
C***ARLM3 01***
       CALL ADYNDP (AB(3),2,111100)
      IF(ICSCNT .LE. 1) GO TO 7777
      J20(IIS) = 0
C...
 7777 CALL ACHECK
C...
C***ARLM3 02***
       CALL ADYNDP (AB(5),2,111100)
      J50(IIS) = (J50(IIS)+1)/2
C...
    8 IF(Q1P - CSD(IS))9,16,16
    9 IF(IPDPL)10,12,10
   12 IF(DP-CSD(IS))14,14,13
   14 IF(CSD(IS) - Q2P*DP)15,18,18
   15 DP = QP6*CSD(IS)
      GO TO 18
C...
   10 IF(CSD(IS).GT.DPMAX+DPMAX) GO TO 15
      IF(CSD(IS)-Q10P*DP) 11,11,18
   11 DP = QP9*CSD(IS)
      GO TO 18
C...
  203 CALL AVMULT(TI,QP125,VTEM)
      CALL AVADD(VTEM,TE,TE)
C...
C***ARLM3 03***
       CALL ADYNDP (AB(7),2,111100)
C...
      CALL ACENTR
C...
C***ARLM3 04***
       CALL ADYNDP (AB(9),2,111100)
      IF(JCR)205,206,205
  205 DP = QP01*DPMAX
      GO TO 207
C...
  206 CONTINUE
C***ARLM3 05***
       CALL ADYNDP (AB(11),2,111100)
C...
      CALL ADELTA
C...
C***ARLM3 06***
       CALL ADYNDP (AB(13),2,111100)
      IF(JDR)207,227,207
  227 IF(DPL-DPMAX)728,728,727
  728 DP=DPL
      GOTO 207
C...
  727 DP=DPMAX
      GO TO 207
C...
   16 IF(CSD(IS))12,17,12
   13 DP=CSD(IS)
      GO TO 18
C...
   17 DP=TAU(IS)
   18 CONTINUE
C...WINNING CS IS DETERMINED ON THE BASIS OF CSD...........
C...
  181 IF(CSD(IS).GE.CSDSAV) GO TO 20
C...
C...
   19 IF((ICSCNT .GT. 1) .AND. (IS .EQ. NOGOOD)) GO TO 20
      IWS = IS
      IIWS = IIS
      CSDSAV = CSD(IS)
      DP1=DP
C...
C...UP SURFACE SUBSCRIPT...EXAMINE CSD FOR THAT SURFACE...........
   20 IS=IS+LSV
      IIS = IIS+LISV
      IF(ILS1-IS)21,21,6
C...
   21 IS=IWS
      IIS = IIWS
      IF(NOGOOD .NE. 0) NOGOOD = 0
      DPCNT = Q10P
      IF(DP.GT.DP1) DP=DP1
      IF(DP.GT.DPMAX) DP=DPMAX
C...
      IF(J50(IIS))22,22,548
C...
  548 IF(IPDPL)22,48,22
C...
   22 CALL AVSTO(TE,TEL)
      JBR = 0
      IF(IPDPL)24,26,24
C...
C...
   26 CALL AVSTO(TEK,TES)
      IF((ICSCNT .GT. 1) .AND. (NUMPTS .EQ. NUMPT1)) DP = QP5 * DP
C...
   28 CALL AVSTO(TAK,TA)
      CALL AVMULT (TIK,DP,CMOVE)
      CALL AVADD(TES,CMOVE,TE)
C...
C...NOW TE MOVED BY DP, DO 2 SURF ITER OR CALL APLANE......
      IF(IPDPL)68,244,68
C...
  244 CONTINUE
C........ 2 SURF ITER    ...........
C***ARLM3 07***
       CALL ADYNDP (AB(15),2,111100)
C...
      CALL ACENTR
C...
C***ARLM3 08***
       CALL ADYNDP (AB(17),2,111100)
      IF(JCR)532,33,532
C......................................ERROR 804............
  532 K804 = K804 + 1
      IF(K804 .GT. 10) CALL AERR(804)
      DP = DP * QP75
      GO TO 28
C...
   32 J20(IIS)=1
      J21(IIS)=1
      CSD(IS) = QNUL
      STCK(IS) = Q1P
      CALL AVSTO(TEK,TE)
      CALL AVSTO(TAK,TA)
      J50(IIS)=0
      J51(IIS)=0
      IF(ICSCNT .LE. 1) GO TO 22
C...TEK CONTAINS MOST CURRENT PT IN TCDAT AND NEXT ITERATION DONE FROM
C...THIS POINT. TA ALSO RESTORED TO TAK.  NOTICE JUST BEFORE CALLING
C...CENTER TO DO 2 SURF ITERATION.
      NOGOOD = IS
      CSDSAV = Q130P
      GO TO 207
   24 CALL AVSTO(TE,TES)
      IF(((NUMPTS-NUMPT1).EQ.0).AND.(TH(ICS).NE.QNUL)) DP=QP6 * DP
      GO TO 28
C...
   33 J10=0
C***ARLM3 09***
       CALL ADYNDP (AB(19),2,111100)
C...
      CALL ADELTA
C...
C***ARLM3 10***
       CALL ADYNDP (AB(21),2,111100)
      IF(JDR)34,36,34
   34 IF(DPCNT - Q1P)35,77,35
   35 DPCNT = DPCNT - Q1P
      CALL AVSTO(TEK,TE)
      CALL AVSTO(TAK,TA)
      IF((DPCNT .LT. Q5P) .AND. (JBR .EQ. 1)) DP = DP * QP6
      GO TO 28
C...
   38 CALL AVDOT(TI,TIK,ANS)
      IF(ANS.GE.QNUL) GO TO 43
      CALL AVSUB(VNUL,TI,TI)
      GO TO 43
C...
   36 CALL AVCROS(SN(IPS),SN(IDS),TI)
      CALL AVNORM(TI,TI,IER)
      IF(IER)41,38,41
   41 CALL AVSUB(TE,TEK,TI)
      CALL AVNORM(TI,TI,IER)
   43 CONTINUE
C...
C***ARLM3 11***
       CALL ADYNDP (AB(23),2,111100)
      IF(I3STRY .GT. 4) GO TO 44
C...
      CALL ACHECK
C...
C***ARLM3 12***
       CALL ADYNDP (AB(25),2,111100)
      IF(JCKR.NE.0) GOTO 48
      CALL AVSUB(TE,TEK,VTEM)
      CALL AVLENG(VTEM,ANS)
      AFTR12 = ANS
      IF(ANS.GT.QP6X01) GOTO 44
C.....................................ERROR -805......
      CALL AERR(-805)
      GO TO 8000
C...
   48 CALL AVSTO(TE,TEE(IS))
      CALL AVSTO(TA,TAE)
C......... 3 SURF ITER       ...............
C***ARLM3 13***
       CALL ADYNDP (AB(27),2,111100)
C...
      CALL ACENTR
C...
C***ARLM3 14***
       CALL ADYNDP (AB(29),2,111100)
      IF(JCR-1)78,49,3332
   78 IF(ICSCNT-1)278,278,279
C..............................ERROR 802.........
  278 IF(ISFTYP(IIS) .NE. 4) CALL AERR(802)
      KTTRY2 = 1
      RETURN
C...
 3332 IF((TE(1)-TEE(IS))*TI(1)
     1                  +(TE(2)-TEE(IS+1))*TI(2)+(TE(3)-TEE(IS+2))*TI(3)
     2)3333,3333,332
 3333 S(IS) = QNUL
      CALL AVSTO(TEE(IS),TE)
      CALL AVSTO(TAE,TA)
      CALL AVSUB(TE,TEK,VTEM)
      CALL AVLENG(VTEM,ANS)
      IF(ANS.LT.QP5X01)   GO TO 332
      ISTO=IS
      IS=IPS
      IISTO = IIS
      IIS = IIPS
C...
      CALL AMIND
C...
      IS=IDS
      IIS = IIDS
C...
      CALL AMIND
C...
      IS=ISTO
      IIS = IISTO
      GO TO 44
C...
  279 S(IS) = Q5P*DP
      NOGOOD = IS
      CSDSAV = Q130P
      GO TO 207
C...
   44 CALL ASTOS
C...
 8000 IF(I3STRY .GT. 4) CSD(IS) = DP
      I3STRY = 0
      JBR=0
      ICSREJ = 0
      IF(NUMPT1)79,79,46
C........................ERROR 803.......
   79 CALL AERR(803)
C...
   46 NUMPT1=NUMPT1-1
      DO 47 I=1,3
      TEK(I)=TE(I)
      TAK(I)=TA(I)
      TIK(I)=TI(I)
      DO 47 K=IPS,ILS1,LSV
      J=K+I-1
      TPK(J)=TP(J)
      SPK(J)=SP(J)
   47 SNK(J)=SN(J)
      CALL AVSTO(TN(IPS),TNK(IPS))
      CALL AVSTO(TN(IDS),TNK(IDS))
      DP1=DP
      CSDSAV = Q130P
C..MULTI-CS AND LARGE CUTTER RELATIVE TO CIRCULAR DS, AVOID J20=2 LOGIC
      IF(ICSCNT .EQ. 1) GO TO 88801
      IF(J24(IIDS) .NE. 2) GO TO 88801
      K = IPONTR(IIDS) + 10
      IF(CUTDAT(1) .LT. (CANSTO(K)*Q5P)) GO TO 88801
      GO TO 802
88801 CONTINUE
      IF(J20(IIS)-2)802,801,802
  801 CALL AVSTO(TEE(IS),TE)
      CALL AVSTO(TAL,TA)
      TP(IPS)=PS1
      TP(IPS+1)=PS2
      TP(IPS+2)=PS3
      SN(IPS)=PS4
      SN(IPS+1)=PS5
      SN(IPS+2)=PS6
      TP(IDS)=DS1
      TP(IDS+1)=DS2
      TP(IDS+2)=DS3
      SN(IDS)=DS4
      SN(IDS+1)=DS5
      SN(IDS+2)=DS6
      CALL AVSTO(PSTN,TN(IPS))
      CALL AVSTO(DSTN,TN(IDS))
      GO TO 55
C..........
  802 IS=ICS
      IIS = IICS
      IWS = IS
      IIWS = IIS
      IF(ICSCNT-1) 12,12,851
  851 CALL AVSTO(TE,TEW)
      GO TO 6
   49 CALL AVSUB(TE,TEE(IS),VTEM)
      CALL AVDOT(VTEM,TI,ANS)
      CALL AVSTO(TE,TEE(IS))
      CALL AVSTO(TA,TAE)
      IF(ANS .LT. QNUL) GO TO 2468
      IF((IFAR(IIS) .GT. 1) .AND. ((NUMPTS - NUMPT1) .EQ. 0)) GO TO 2468
      GO TO 8624
 2468 CALL AVSUB(TE,TEK,VTEM)
      CALL AVLENG(VTEM,ANS)
      IF(DABS(ANS) .GT. (QP5 * TAU(IS)))GO TO 8624
      J50(IIS) = 0
      J51(IIS) = 0
      DP = Q4P * TAU(IS)
      GO TO 22
 8624 CONTINUE
      IWS = IS
      IIWS = IIS
      IS=ICS
      IIS = IICS
   52 IF(IS-ILS1) 50,54,54
   50 IF(IS-IWS)53,51,53
C...
   53 CALL AMIND
C...
  211 IF(ISFTYP(IIS)-4)212,219,212
  212 IF(J23(IIS).GT.0) GO TO 51
C...CHECK CSD ... DONE AFTER OK 3 SURF ITER TO ONE CS
      IF((ISFTYP(IIS) .EQ. 1) .AND. (S(IS) .LT. QNUL)) GO TO 9999
      IF((DABS(CSD(IS)-CSD(IWS))) .GT. (QP5*DP)) GO TO 51
      STCK(IS)=S(IS)*Z(IS)*STCK1(IS)
      IF(STCK(IS)) 9999,9999,51
 9999 J50(IIS) = 1
      J51(IIS) = 1
      IF(IWS .EQ. 201) ICSRJ1 = ICSRJ1 + 1
      IF(IWS .EQ. 301) ICSRJ2 = ICSRJ2 + 1
      IF((ICSRJ1 + ICSRJ2) .GT. 3) GO TO 51
      IF((ICSRJ1 .EQ. 0) .OR. (ICSRJ2 .EQ. 0)) GO TO 48
      CALL AVSUB(TEE(201),TEE(301),VTEM)
      CALL AVDOT(VTEM,TI,ANS)
      IF(ANS)4802,4802,4803
 4802 IWS = 201
      IIWS = 81
      GO TO 54
 4803 IWS = 301
      IIWS = 121
      GO TO 54
C...
  219 IF(J22(IIS))51,51,213
  213 J20(IIS) = 0
C...
      CALL ACHECK
C...
      IF(STCKN(IS) .GT. QNUL) GO TO 51
      GO TO 9999
   51 IS=IS+LSV
      IIS = IIS+LISV
      GO TO 52
   54 IS=IWS
      IIS = IIWS
      CALL AVSTO(TA,TAL)
      CALL AVCROS(SN(IPS),SN(IDS),TIL)
      CALL  AVNORM(TIL,TIL,IER)
      IF(IER) 805,808,805
  805 CALL AVSUB(TE,TEK,TIL)
      CALL AVNORM(TIL,TIL,IER)
C...
  808 PS1=TP(IPS)
      PS2=TP(IPS+1)
      PS3=TP(IPS+2)
      PS4=SN(IPS)
      PS5=SN(IPS+1)
      PS6=SN(IPS+2)
      DS1=TP(IDS)
      DS2=TP(IDS+1)
      DS3=TP(IDS+2)
      DS4=SN(IDS)
      DS5=SN(IDS+1)
      DS6=SN(IDS+2)
      CALL AVSTO(TN(IPS),PSTN)
      CALL AVSTO(TN(IDS),DSTN)
  55  CALL AVSUB(TE,TEK,V)
      CALL AVDOT(V,TIK,ANS)
      IF(ANS.GE.QNUL) GO TO 57
  332 S(IS) = Q5P*DP
      I3STRY = I3STRY + 1
      GO TO 32
C...
   57 CALL AVLENG(V,VL)
      IF((NUMPTS.EQ.NUMPT1).AND.(VL.LT.TAU1(IS)))GO TO 332
      IF(ISFTYP(IIS)-4)949,449,949
  949 CALL AVSUB(TE,TEK,VTEM)
      CALL AVNORM(VTEM,VTEM,IER)
      IF(IER .NE. 0) GO TO 449
      CALL AVDOT(VTEM,TN(IS),ANS)
      IF(DABS(ANS) .LT. QP017) GO TO 449
      IF(ANS * PAST(IS))401,449,449
  401 IF(IS .NE. ISSTOP) GO TO 400
      KSTOP = KSTOP + 1
      IF((ICSCNT.GT.1).AND.(JCR.EQ.1).AND.(KSTOP.GT.20)) GO TO 402
      GO TO 403
  402 ISSTOP = -100
      KSTOP = 0
      GO TO 449
  400 ISSTOP = IS
      KSTOP = 0
  403 J50(IIS) = 1
      J51(IIS) = 1
      NOTAN(IIS)=0
      PLND1(IS)=0
      CALL AVSUB(VNUL,TN(IS),TN(IS))
      GOTO 48
C...
  449 J10=1
C***ARLM3 15***
       CALL ADYNDP (AB(31),2,111100)
C...
      CALL ADELTA
C...
C***ARLM3 16***
       CALL ADYNDP (AB(33),2,111100)
      IF(JDR)58,63,58
   58 CSD(IS) = Q1P2*VL
C..................................ERROR -805......
C...
      K805 = K805 + 1
      IF(K805 .GT. 10) CALL AERR(-805)
      IF(DP-CSD(IS))61,61,59
   61 IF(CSD(IS) - Q2P*DP)62,60,60
   62 DP = QP6*CSD(IS)
      GO TO 60
C...
   59 DP=CSD(IS)
   60 DPCNT = Q10P
      J50(IIS)=0
      J51(IIS)=0
      J20(IIS)=2
      GO TO 22
C...
   63 IF(IFAR(IIS)-1)64,76,64
   64 IFAR(IIS)=IFAR(IIS)-1
      IF(IPDPL)66,65,66
   65 CALL ASTOS
C...
      CALL AVDOT(TI,TIL,TEMP)
C...
      A = TEMP(1)
      TEMP(1) = Q1P
      IF(A.LT.QNUL) TEMP(1) = -Q1P
      CALL AVMULT(TIL,TEMP,TI)
   66 CONTINUE
      CALL AVSTO(TE ,TEK)
      CALL AVSTO (TA,TAK)
      DO67I=1,3
   67 TEW(I) = Q3P*TAU(IS)*TI(I) + TE(I)
      GO TO 2
C...
C...
C...
   68 CONTINUE
C***ARLM3 17***
       CALL ADYNDP (AB(35),2,111100)
C...
      CALL APLANE
C...
      CSDSAV = Q130P
C***ARLM3 18***
       CALL ADYNDP (AB(37),2,111100)
      IF(JPR)604,603,69
  603 CALL AVSTO(TE,TEW)
      GO TO 5
C...
  604 CALL AVMULT(TI,QP5,TEW)
      CALL AVADD(TEW,TE,TEW)
C     ENSURE THAT  MOVEMENT DOES NOT VIOLATE ANOTHER CS
      IF(ICSCNT.LE.1) GO TO 602
      CALL AVSUB(TEW,TEK,VTEM)
      CALL AVLENG(VTEM,ANS)
      CSD(IS) = ANS
      DO 6022 II=1,ICSCNT
      KK = 201 + LSV*(II-1)
      IF(CSD(KK).GE.ANS) GO TO 6022
      ANS = CSD(KK) * QP9
      CALL AVMULT(TI,ANS,CMOVE)
      CALL AVADD(TEK,CMOVE,TEW)
 6022 CONTINUE
      GO TO 602
C...
   69 IF(KGOTBE .EQ. 1) GO TO 63
      IWS = IS
      IIWS = IIS
      IS=ICS
      IIS=IICS
   84 IF(ILS1-IS) 70,70,72
   70 IS=IWS
      IIS = IIWS
      GO TO 63
   73 IS=IS+LSV
      IIS = IIS+LISV
      GO TO 84
   72 IF(IS-IWS)75,73,75
C...
   75 CALL AMIND
C...
  214 IF(ISFTYP(IIS)-4)215,226,215
  215 IF(J23(IIS).GT.0) GO TO 73
      STCK(IS)=STCK1(IS)*Z(IS)*S(IS)
      IF(STCK(IS))74,74,73
   74 CALL AVSTO(TEL,TE)
      DP = Q1P1*CSD(IS)
      CALL AVSTO(SPL(IDS),SP(IDS))
      CALL AVSTO(SPL(IPS),SP(IPS))
      GO TO 68
C...
  226 IF(J22(IIS))73,73,216
  216 J20(IIS) = 0
C...
      CALL ACHECK
C...
      IF(STCKN(IS))74,74,73
   76 CONTINUE
      IF(MULTAX .NE. 1) GO TO 997
      IF(NUMPT1 .EQ. NUMPTS) GO TO 997
      IF(IPDPL .EQ. 1) GO TO 997
      IF(J24(IIPS) .NE. 8) GO TO 997
      IF(VL .LE. (AFTR12*Q1P5)) GO TO 997
      DP = AFTR12 * Q1P5
      GO TO 60
C...
  997 CALL ASTOS
      IER = -10
C...
      CALL ATAPE
C...
C***ARLM3 EX***
       CALL ADYNDP (AB(39),1,111111)
      NW = 0
      RETURN
C********************************************************************
C...
   77 CONTINUE
      IF(JBR.EQ.1) GO TO 907
C...................ERROR -805................
      CALL AERR(-805)
      DPCNT = DPCNT + Q10P
      JBR = 1
      GO TO 35
C...
  907 JBR = 0
C...................................ERROR 801............
      CALL AERR(801)
69696 CONTINUE
      KGOTBE = 1
      IF(IS .EQ. 201) GO TO 79797
      IS = 201
      IIS = 81
      GO TO 68
79797 IS = 301
      IIS = 121
      GO TO 68
      END

