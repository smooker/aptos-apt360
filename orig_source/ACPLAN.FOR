      SUBROUTINE ACPLAN
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 ***
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
     2 J40, J43, J54, J103,ADUM(2100)
C
      COMMON/A2CMMN/ IER ,INSTR1 ,INSTR2 ,NWDS ,ICL ,
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
       DIMENSION AB(30)
       DATA AB(1),AB(2)/4HACPL,4HANTP/,AB(3),AB(4)/4HACPL,4HAN01/,
     1AB(5),AB(6)/4HACPL,4HAN02/,AB(7),AB(8)/4HACPL,4HAN03/,
     2AB(9),AB(10)/4HACPL,4HAN04/,AB(11),AB(12)/4HACPL,4HAN05/,
     3AB(13),AB(14)/4HACPL,4HAN06/,AB(15),AB(16)/4HACPL,4HANEX/,
     4AB(17),AB(18)/4HACPL,4HAN07/,AB(19),AB(20)/4HACPL,4HAN08/,
     5AB(21),AB(22)/4HACPL,4HAN09/,AB(23),AB(24)/4HACPL,4HAN10/,
     6AB(25),AB(26)/4HACPL,4HAN11/,AB(27),AB(28)/4HACPL,4HAN12/,
     7AB(29),AB(30)/4HACPL,4HAN13/
      CALL ADYNDP(AB(1),11,111111)
       CALL ADYNDP(AB( 1),4,111100)
C...
      TEMP(20)=RC(IS)
C...
C...  SEE IF THE CHECK SURFACE IS A PLANE
 1010 CALL AVCROS(SN(IS),SNK(IS),TEMP)
 1020 CALL AVNORM(TEMP,TEMP,IER)
C...  ********************************************************** 01 ***
       CALL ADYNDP(AB( 3),6,110000)
C...
 1030 IF(IER) 1040,1050,1040
 1050 CALL AVSUB(SP(IS),SPK(IS),VTEM)
      CALL AVDOT(TEMP,VTEM,TEMP1)
 1060  TEM(1)=SPK(IS)+TEMP1*TEMP(1)
      TEM(2)=SPK(IS+1)+TEMP1*TEMP(2)
      TEM(3)=SPK(IS+2)+TEMP1*TEMP(3)
       CALL ADYNDP(AB( 5),6,110000)
 1090 CALL ACCURV(IS,IIS,SP(IS),TEM,TN(IS))
C...
C........... TANTO (IFL4=0)  OR  PSTAN (IFL4=1) .....
 1120 IF(IFL4(IIS))1130,1140,1130
C...
C... **** PSTAN ****
 1130 IT = IPS
      IIT = IIPS
      ITT = IDS
      IITT = IIDS
C...  ********************************************************** 03 ***
       CALL ADYNDP(AB( 7),6,110000)
      GO TO 1150
C...
C...  THE CHECK SURFACE IS A PLANE.
 1040 CONTINUE
C...  SET CS RC = 4500 ... RETAIN OLD SIGN
      A = RC(IS)
      RC(IS) = RC1
      IF(A.LT.QNUL) RC(IS)= -RC1
      GO TO 1120
C...
C... **** TANTO ****
 1140 IT = IDS
      IIT = IIDS
      ITT = IPS
      IITT = IIPS
C...  ********************************************************** 04 ***
       CALL ADYNDP(AB( 9),6,110000)
C... COMPARE THE Z COMPONENT OF CURRENT SP AND THAT OF SP AT THE ORIGIN
C... OF CUT VECTOR (OF THE TANGENT SURFACE). IF THEY ARE CLOSE TOGETHER
C... TEM = TI. IF NOT, TEM = SN(PS) X SN(DS) .
 1150 IF(DABS(SP(IT+2) - SPK(IT+2)) - QP001) 2,1,1
    2 CALL AVSTO(TI,TEM)
      GO TO 5
C...
C... CROSS PART SN AND DRIVE SN
    1 CALL AVCROS(SN(IT),SN(ITT),TEM)
      CALL AVNORM(TEM,TEM,IER)
C... *********************************************************** 05 ***
       CALL ADYNDP(AB(11),6,110000)
C...
      IF(IER)2,3,2
    3 CALL AVDOT(TI,TEM,ANS)
      IF(ANS.GE.QNUL) GO TO 5
    4 CALL AVSUB(VNUL,TEM,TEM)
C...
C...
    5 ISIS=IS
      IISIS= IIS
      IS=IT
      IIS = IIT
C...
      TEMP(4)=S(IS)
C...
      CALL AVSTO(TP(IS),TEMP)
C...
C...  CALCULATE SP ON THE TANGENT SURFACE .....  FROM .05 UNIT AWAY
C...  FROM THE CURRENT TP IN OPPOSITE DIRECTION OF TI.
C...  TEM IS EQUIVALENT TO TI.
      FACTOR = QP05
   55 CALL AVMULT(TEM,FACTOR,VTEM)
      CALL AVSUB(TEMP,VTEM,TP(IS))
      CALL ADDST
      IF(IER .EQ. 0) GO TO 56
      FACTOR = FACTOR * QP5
      IF(FACTOR .GT. QP5X01) GO TO 55
      S(IS) = TEMP(4)
   56 CALL AVMULT(TN(IS),S(IS),VTEM)
      CALL AVADD(TP(IS),VTEM,TEM)
C...
C...  TEM NOW CONTAINS NEW SP CALCULATED ABOVE.
      CALL AVSTO(TEMP,TP(IS))
      S(IS)=TEMP(4)
      IS=ISIS
      IIS = IISIS
C...
C... PLNCS ... USED TO DETERMINE IF TANGENCY POINT HAS BEEN REACHED.
 1200 CALL AVDOT(TN(IT),TN(IS),PLNCS(IS))
C... *********************************************************** 06 ***
       CALL ADYNDP(AB(13),6,110000)
C...
 1210 IF(EPS2(IS) - DABS(PLNCS(IS))) 1220,1240,1240
C...
C... PRETTY NEAR THE TANGENCY POINT. SET DPLAN=TN(NON-TANGENT SURFACE)
 1220 IF (CPLFL(IS)) 1250,1230,1250
 1230 CALL AVSTO(TN(ITT),DPLAN(IS))
      GO TO 1250
C... NOT NEAR TANGENCY POINT YET. SET DPLAN=TN(CS)XTN(TANGENT SURFACE)
 1240 CALL AVCROS(TN(IS),TN(IT),DPLAN(IS))
C...
C...
C... IS TANGENT SURFACE A PLANE.
 1250 IF (IPL(IIT)) 1600,1260,1600
C...
C... TANGENT SURFACE IS A PLANE.
 1600 IF(DABS(RC(IS)) - Q4500P) 1610,1620,1620
C... CHECK SURFACE IS NOT A PLANE.
 1610 CALL AVSTO(TN(IT),TEMP)
      GO TO 1380
C...
C... BOTH TANGENT AND CHECK SURFACES APPEAR TO BE PLANES.
 1620 CPTST(IS) = -Q1P
      CPLFL(IS) = -Q1P
      PLND(IS) = S(IS)
      CALL AVSTO(TN(IS),PLNV(IS))
 9998 JCPR=0
 9999 RC(IS)=TEMP(20)
C... *********************************************************** EX ***
      CALL ADYNDP(AB(15),11,111100)
       CALL ADYNDP(AB(15),4,111100)
C.................. RETURN .......
      GO TO 5000
C...
C...
C... TANGENT SURFACE IS NOT A PLANE. CALL ACCURV. REMEMBER TEM IS THE
C... SP ON THE TANGENT SURFACE.
 1260 CALL ACCURV(IT,IIT,SP(IT),TEM,SN(IT))
 1310 IF(DABS(RC(IT)) - RC1) 1320,1600,1600
C...
 1320 IF (IPL(IIS)) 1340,1330,1340
C... CS IS A PLANE. TANGENT SURFACE IS NOT A PLANE.
 1340 CALL AVSTO(CC(IT),CC(IS))
      CALL AVSTO(TN(IS),TEMP)
C... *********************************************************** 07 ***
       CALL ADYNDP(AB(17),6,110000)
C... GO CALCULATE PLNV(ICS) *****
      GO TO 1380
C...
C... CHECK SURFACE IS NOT A PLANE. BUT IF RC(CS) > 4500, ASSUME IT IS.
 1330 IF(DABS(RC(IS)) - RC1) 1370,1340,1340
C...
C... BOTH CS AND TANGENT SURFACE NOT PLANES. SET TEMP=VECTOR BETWEEN
C... TWO RESPECTIVE CENTERS OF CURVATURE.
 1370 CALL AVSUB(CC(IT),CC(IS),TEMP)
      CALL AVNORM(TEMP,TEMP,IER)
C... *********************************************************** 08 ***
       CALL ADYNDP(AB(19),6,110000)
      IF(IER) 1340,1380,1340
C...
 1380 CALL AVCROS(TEMP,DPLAN(IS),PLNV(IS))
      CALL AVNORM(PLNV(IS),PLNV(IS),IER)
       CALL ADYNDP(AB(21),6,110000)
 1390 IF(IER)1400,1410,1400
 1410 CALL AVSUB(TP(IT),TE,TEMP)
 1420 CALL AVDOT(TEMP,TEMP,TEMP(4))
      CALL AVDOT(TEMP,TN(IT),TEMP(5))
      TEMP(5) = TEMP(5)*TEMP(5)
 1430 CALL AVDOT(TA,TN(IT),CPLFL(IS))
       CALL ADYNDP(AB(23),6,110000)
      IF(CPLFL(IS) - QP0001)1440,1445,1445
 1445 CALL AVSUB(CC(IS),TP(IT),VTEM)
      CALL AVDOT(VTEM,PLNV(IS),PLND(IS))
       CALL ADYNDP(AB(25),6,110000)
      GOTO 1510
 1440 IF(DABS(CPLFL(IS)) - EPS2(IS)) 1450,1450,1480
 1450 IF(QP5X01 - DABS(CPLFL(IS))) 1460,1460,1480
 1460 A = Q1P
      IF(CPLFL(IS).LT.QNUL) A = -Q1P
      TEMP1 =                    A*DSQRT((TEMP(4) - TEMP(5))/
     1                      (Q1P - CPLFL(IS)*CPLFL(IS)))
 1470 CALL AVMULT(TA,TEMP1,VTEM)
      CALL AVSUB(VTEM,TE,CMOVE)
       CALL ADYNDP(AB(27),6,110000)
      GO TO 1500
 1400 JCPR=1
      GOTO9999
 1480 CALL AVSUB(TP(IT),TE,VTEM)
      CALL AVDOT(TA,VTEM,TEMP1)
 1490 CMOVE(1) = -TE(1)-TEMP1*TA(1)
      CMOVE(2) = -TE(2)-TEMP1*TA(2)
      CMOVE(3) = -TE(3)-TEMP1*TA(3)
 15000PLND(IS) = (CC(IS)  +CMOVE(1))*PLNV(IS)
     1+(CC(IS+1)+CMOVE(2))*PLNV(IS+1)
     2+(CC(IS+2)+CMOVE(3))*PLNV(IS+2)
 1510 CPLFL(IS) = Q1P
 1520 CPTST(IS) = CPTST(IS)+CPLFL(IS)
       CALL ADYNDP(AB(29),6,110000)
 1530 IF(CPTST(IS)) 9998,1520,9998
 5000 RETURN
       END

