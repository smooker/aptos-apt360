      SUBROUTINE ASTUP2
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
      DIMENSION APNT(3),DCTEM(8),PCTEM(8),TETEM(3)
C...             SET UP PSUDO DS AS PLANE,EITHER ALONG VINDIR OR MINDIST
      DIMENSION AB(22)
      DATA AB(1),AB(2)/4HASTU,4HP2TP/,AB(3),AB(4)/4HASTU,4HP201/,
     1AB(5),AB(6)/4HASTU,4HP202/,      AB(7),AB(8)/4HASTU,4HP203/,
     2AB(9),AB(10)/4HASTU,4HP204/,     AB(11),AB(12)/4HASTU,4HP205/,
     3AB(13),AB(14)/4HASTU,4HP206/,    AB(15),AB(16)/4HASTU,4HP207/,
     4AB(17),AB(18)/4HASTU,4HP208/,    AB(19),AB(20)/4HASTU,4HP209/,
     5AB(21),AB(22)/4HASTU,4HP2EX/
       CALL ADYNDP(AB( 1),1,111111)
      IF(INDIR(IIDS).NE.1) GO TO 20
   10 CONTINUE
       CALL ADYNDP(AB( 3),9,110000)
      CALL AVSTO(VNDIR(IDS),TI)
      IF(DABS(TI(3)).GT.QP995) GO  TO 270
      KI = IPONTR(IIDS)
      ANS = Q1P
      GO TO 100
   20 CONTINUE
       CALL ADYNDP(AB( 5),9,110000)
C     NO INDIR
      K=IPONTR(IIDS)
      KI=K
      CALL ASTOR(CANSTO(K),8,I,2)
      IF((I.NE.2).AND.(I.NE.3)) GO TO 40
C...             PLANE
   30 CONTINUE
       CALL ADYNDP(AB( 7),9,110000)
      CALL AVSTO(CANSTO(K+4),TI)
      CALL AVDOT(TE,TI,ANS)
      ANS=CANSTO(K+7)-ANS
      IF(ANS.LT.QNUL) CALL AVSUB(VNUL,TI,TI)
      ANS = DABS(ANS)
C...             TI NOW SET TO POINT TOWARD PLANE
       GO TO 90
C...             CIRCLE
   40 CONTINUE
       CALL ADYNDP(AB( 9),9,110000)
      CALL AVSUB(TE,CANSTO(K+4),VTEM)
      VTEM(3)=QNUL
      CALL AVNORM(VTEM,VTEM,IER)
      CALL AVMULT(VTEM,CANSTO(K+10),APNT)
      CALL AVADD(APNT,CANSTO(K+4),APNT)
C...             APNT IS MINIMUM DISTANCE POINT ON SURFACE - USE IT TO
C                SET UP THE AIMING DIRECTION TI
      CALL AVSUB(APNT,TE,TI)
      TI(3) = QNUL
       CALL AVLENG(TI,ANS,IER)
      CALL AVNORM(TI,TI,IER)
      IF(IER.EQ.1) CALL AERR(40)
   90  IF(ANS.GT. CUTDAT(1)          ) GO TO 100
       IF(ISFTYP(IIDS).NE.1) GO TO 100
       ISFTYP(IIDS) = 2
       CALL AVSUB(VNUL,TI,TI)
C
C
C...             USE DCTEM TO STORE PSUDO DS CANONICAL FORM
  100 CONTINUE
      IF(ITLON(IIDS).NE.0) ANS = DABS(ANS) - CUTDAT(1)
      IWITOL = 0
      IF(DABS(ANS).LE.TAU(IDS)) IWITOL = 1
       CALL ADYNDP(AB(11),9,110000)
      CALL ASTOR(3,4,DCTEM(1),8)
      CALL ASTOR(6,4,DCTEM(2),8)
C...   **TROUBLE FOR S/360 ****
      CALL ASTOR(12HDSGO        ,8,DCTEM(3),8)
      CALL ASTOR(0,4,DCTEM(4),8)
      CALL AVCROS(TI,TA,DCTEM(5))
      CALL AVNORM(DCTEM(5),DCTEM(5),IER)
      IF(IER.EQ.1) CALL AERR(45)
      DCTEM(8)=QNUL
C
C...             IF NOPS NOT GIVEN, GET PROPERLY POSITIONED TO PS...IF
C                NOPS WAS GIVEN, SET UP PSUDO PS PLANE
      IF(INOPS.NE.1) GO TO 120
C                NOPS WAS GIVEN
  110 CONTINUE
       CALL ADYNDP(AB(13),9,110000)
      CALL AVCROS(TI,TA,VTEM)
      CALL AVCROS(TI,VTEM,PCTEM(5))
      CALL AVNORM(PCTEM(5),PCTEM(5),IER)
      IF(IER.EQ.1) CALL AERR(42)
C...             SET UP PS CANONICAL FORM
      CALL ASTOR(3,4,PCTEM(1),8)
      CALL ASTOR(6,4,PCTEM(2),8)
      CALL ASTOR(12HPSGO        ,8,PCTEM(3),8)
      CALL ASTOR(0,4,PCTEM(4),8)
      PCTEM(8) = QNUL
      CALL AVSTO(TE,TETEM)
      GO TO 200
C
C
  120 CONTINUE
C                NOPS NOT GIVEN-POSITION CUTTER TO PS PLANE BY
C                VERTICAL MOTION ONLY
C
C
      IF(ITLON(IIPS).EQ.0) GO TO 140
C
  130 CONTINUE
C                CUTTER IS NOT TO BE ON PS-COMPUTE MINIMUM DISTANCE SO
C                TOOL POINT CAN BE USED
      CALL AVSTO(TE,TP(IPS))
      CALL AVSUB(VNUL,EZ,TN(IPS))
C                INITIAL VALUES OF TP AND TN SET-NOW INITIALIZE AMIND
      IS = IPS
      IIS = IIPS
      JENT(IIS) = 1
      JTN(IIS)=1
      IOPSET(IIS)=0
C                NOTE JTN SET FOR TOOL NORMAL CONTROL IN AMIND
      JIOPS(IIS)=0
      JU1(IIS)=0
      CALL AMIND
C                AMIND HAS NOW ITERATED AROUND AND FOUND A MINIMUM DIST.
C                IT PRESUMABLY HAS MODIFIED TP AND IN SUCH THAT TN LINES
C                UP PARALLEL OR ANTI-PARALLEL TO THE PLANE PS NORMAL.
C                IT SHOULD STILL BE IN A GENERALLY DOWNWARD DIRECTION,
C                AS TN WAS INITIALLY IN THE -Z DIRECTION. IF THE CUTTER
C                HAS TO BE MOVED DOWN,S THE MINIMUM DISTANCE SHOULD BE
C                POSITIVE. IF UPWARD MOTION IS REQUIRED, S SHOULD BE NEG
C
C                TP SHOULD NOW BE THE POINT ON THE CUTTER WHICH IS
C                CLOSEST TO THE PLANE, IF THE PLANE IS BELOW THE
C                CUTTER OR FURTHERS FROM THE PLANE IF THE PLANE IS ABOVE
C                THE CUTTER. IN EITHER CASE IT TIS THE DESIRED POINT OF
C                CONTACT BETWEEN CUTTER AND PS PLANE
C
      GO TO 150
  140 CONTINUE
       CALL ADYNDP(AB(15),9,110000)
C                CUTTER IS TO BE ON PS USE DIRECTED DISTANCE ROUTINE TO
C                SEE HOW MUCH TO MOVE IT. DDST LOOKS FROM TP IN DIRECT-
C                ION TN. S IS RETURNED AS THE DIRECTED DISTANCE, POS. IF
C                FORWARD ALONG TN, NEG IF BACK ALONG TN..
C
C                SET UP TP FOR ON CASE...FOR OFFSET CASE TP HAS BEEN
C                COMPUTED IN AMIND
      CALL AVSTO(TE,TP(IPS))
      IS = IPS
      IIS = IIPS
C
  150 CONTINUE
      IOP(IIS) = 0
      CALL AVSUB(VNUL,EZ,TN(IS))
      CALL ADDST
      IF(IER.EQ.1) CALL AERR(43)
      IF(PAST(IPS).LT.QNUL) GO TO 270
      IF((ITLON(IIPS).NE.0).AND.(S(IPS).LT.QNUL).AND.(DABS(S(IPS)).GT.
     1 (QP5*CUTDAT(7)))) GO TO 270
C
C                SET UP CUTTER LOCATION FOR ARLM2 INPUT. DO NOT WANT TO
C                USE TE AS IT MIGHT MESS UP PMOVE COMPUTATUION
      CALL AVMULT(TN(IS),S(IS),VTEM)
      CALL AVADD(TE,VTEM,TETEM)
C
C
C                STORE PS CANONICAL FORM IN PCTEM SO BOOKS WILL BE KEPT
C                STRAIGHT.
C                THE PROBLEM IS THAT THE 2D ROUTE REFERENCES THE PS CAN-
C                ONICAL FORM DIRECTLY-
C                THEREFORE WE HAVE TO FOOL IT IN NOPS CASES BY LOADING
C                A PSUDOPS AND RESTORING THE REAL ONE LATER
C
      DO 155 I=1,8
      PCTEM(I) = CANSTO(I)
  155 CONTINUE
C
      GO TO 200
C
  200 CONTINUE
       CALL ADYNDP(AB(17),9,110000)
C                SET UP TO,ON,PAST,TANTO FOR ARLM2
C                KTOPT =  1,2,3,4 FOR TO,ON,PAST,TANTO
C                HOWEVER IN 3D ROUTE, ISFTYP = 1,2,3,4 FOR TO,PAST,ON,
C                TANTO..
C
      KTOPT = ISFTYP(IIDS)
      IF(ISFTYP(IIDS).EQ.2) KTOPT=3
      IF(ISFTYP(IIDS).EQ.3) KTOPT=2
C
      IF(IWITOL.EQ.1) GO TO 260
C                LOAD PS CANONICAL FORM
      JSAVE = J24(IIPS)
      J24(IIPS) = 1
      DO 205  I=1,8
      TEMP(I)=CANSTO(I)
      CANSTO(I)=PCTEM(I)
      PCTEM(I)=TEMP(I)
  205 CONTINUE
C                CALL ARLM2
       CALL ADYNDP(AB(19),9,110000)
      CALL ARLM2(CUTDAT(1),VNUL,QNUL,TETEM,TI,DCTEM,CANSTO(KI),KTOPT,
     11,EPS1(IDS),TAU(IDS),QNUL,KDYNFQ(9))
C
C                RESTORE PS CANONICAL FORM
      DO 250  I=1,8
      CANSTO(I)=PCTEM(I)
  250 CONTINUE
      J24(IIPS) = JSAVE
       CALL ADYNDP(AB(21),1,111111)
      RETURN
  260 IF((INDIR(IIDS).EQ.1).OR.(ITLON(IIDS).NE.0)) GO TO 270
      CALL AVSTO(TETEM,TE)
      NW = 0
      CALL ASTOS
      CALL ATAPE
      RETURN
  270 CALL ASTRUP
      RETURN
      END

