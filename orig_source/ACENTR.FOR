      SUBROUTINE ACENTR
C...  TO ITERATE THE CUTTER INTO A POSITION WITHIN THE SPECIFIED
C...  TOLERANCE OF TWO OR THREE SURFACES.
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
      COMMON/ACENCM/ ICMVL, JTA, KOUNT, IRET, IIN, IOUT, TANANG, KAS905
      COMMON/CNTRU1/J51CKP, J51CKD, RVRSU1(6)
      DIMENSION SVU1TN(3), SVU1TP(3)
      DIMENSION AB(46)
      DATA AB/    4HACEN,4HTRTP,4HACEN,4HTR01,4HACEN,4HTR02,4HACEN,
     1            4HTR03,4HACEN,4HTR04,4HACEN,4HTR05,4HACEN,4HTR06,
     2            4HACEN,4HTR07,4HACEN,4HTR08,4HACEN,4HTR09,4HACEN,
     3            4HTR10,4HACEN,4HTR11,4HACEN,4HTR12,4HACEN,4HTR13,
     4            4HACEN,4HTR14,4HACEN,4HTREX,4HACEN,4HTR15,4HACEN,
     5            4HTR16,4HACEN,4HTR17,4HACEN,4HTR18,4HACEN,4HTR19,
     6            4HACEN,4HTR20,4HACEN,4HTR21  /
C...
C...  ****************************************************** TP *****
      K51CKP = 0
      K51CKD = 0
      CALL ADYNDP(AB( 1),3,111100)
      KFL602 = 0
      JW6 = 0
      CMVLST = Q1PE38
      KAS905 = 0
      J51CKP = 0
      J51CKD = 0
      JTRC = 10
      KOUNT = 0
      ITNFLG = 0
      JS = 0
      PROBUF(7) = Q1PE6
      PROBUF(17) = Q1PE6
      IF((J51(IIS).EQ.1).AND.(ISFTYP(IIS).EQ.4).AND.(CEND(1).EQ.QNUL))
     1  GO TO  8000
 8001 CONTINUE
      JTKF =0
C... TANANG....CONVERGENCE CRITERIA FOR TOOL NORMALS IN TANGENT CS CASE
      TANANG = Q1P - QP5*TAU(IS)
      IF(TANANG.GT.QP4X95) TANANG = QP4X95
      IF(TANANG .LT. QP999) TANANG = QP4X95
C... CPLFL .. INDICATOR FROM ACPLAN ... =0 TO INITIALIZE ACPLAN
C...          = -1 IF BOTH CS AND TANGENT SURFACE APPEAR TO BE PLANES.
C...          = +1 IN ALL OTHER CASES.
      CPLFL(IS) = QNUL
C... CPTST .. COUNTER WHICH CONTROLS CALLING OF ACPLAN BY ACENTR.
C...          ACPLAN IS CALLED EVERY OTHER PASS THRU 3 SURF ITERATION
      CPTST(IS) = QNUL
C...          J54 ... SWITCH TO ALTERNATE PLND CALCULATION IN TANGENT CS
      J54=0
      JTA = 1
C...
 1010 JCNT1=25
      JCNT2=25
      JCNT3=25
C...
   11 ISSTO=IS
      IISSTO = IIS
      IS=IPS
      IIS = IIPS
C...  ****************************************************** 01 *****
      CALL ADYNDP(AB( 3),5,110000)
      JMINR = 1
      IF(ISTRUP .EQ. 0) JMINR = 0
      NFLUNK = 0
      REDUCE = DP
      IF(JCNT3 .EQ. 10) GO TO 70002
  512 CALL AMIND
      GO TO 70001
70000 IS = IDS
      IIS = IIDS
C...  ****************************************************** 02 *****
      CALL ADYNDP(AB( 5),5,110000)
      JMINR = 1
      IF(ISTRUP .EQ. 0) JMINR = 0
      NFLUNK = 0
      REDUCE = DP
C...
  514 CALL AMIND
C...
70001 IF(JMIN .EQ. 0) GO TO 99999
70002 NFLUNK = NFLUNK + 1
C
      IF(NFLUNK .GT. 4) CALL AERR(902)
      REDUCE = QP5 * REDUCE
      CALL AVMULT(TIK,REDUCE,VTEM)
      CALL AVADD(TEK,VTEM,TE)
      CALL AVSTO(TNK(IS),TN(IS))
      CALL AVSTO(TPK(IS),TP(IS))
      GO TO 514
C
C
99999 IF((K51CKP .GT. 5) .OR. (K51CKD .GT. 5)) GO TO 99998
      IF((J24(IIS) .NE. 2) .OR. (RC(IS) .GT. QNUL)) GO TO 99998
      IF(ISTRUP .EQ. 1) GO TO 99998
      CALL AVSTO(TN(IS),SVU1TN)
      CALL AVSTO(TP(IS),SVU1TP)
      AA2 = S(IS)
      I = IOP(IIS)
C
      CALL AVSUB(TP(IS),TE,VTEM)
      CALL AVDOT(TA,VTEM,ANS)
      CALL AVMULT(TA,ANS,VTEM)
      CALL AVADD(TE,VTEM,TP(IS))
      CALL AVSTO(U1(IS),TN(IS))
      IOP(IIS) = 0
      CALL ADDST
      IF(IER .NE. 0) GO TO 99997
      IF(S(IS) .GE. QNUL) GO TO 99997
      IF(IS .EQ. IDS) GO TO 99996
      J51CKP = IPS
      CALL AVSUB(VNUL,U1(IS),RVRSU1)
      K51CKP = K51CKP + 1
      GO TO 512
99996 J51CKD = IDS
      CALL AVSUB(VNUL,U1(IS),RVRSU1(4))
      K51CKD = K51CKD + 1
      GO TO 514
99997 CALL AVSTO(SVU1TN,TN(IS))
      CALL AVSTO(SVU1TP,TP(IS))
      S(IS) = AA2
      IOP(IIS) = I
99998 IF(IS .EQ. IPS) GO TO 70000
      IS = ISSTO
      IIS = IISSTO
      JMINR = 0
C
   12 CALL AVSTO(SN(IPS),PLNV(IPS))
      PLND(IPS) = S(IPS)
      CALL AVSTO(SN(IDS),PLNV(IDS))
      PLND(IDS) = S(IDS)
      CALL AVDOT(PLNV(IPS),TN(IPS),ANS)
      IF(ANS.LT.QNUL) CALL AVSUB(VNUL,PLNV(IPS),PLNV(IPS))
      CALL AVDOT(PLNV(IDS),TN(IDS),ANS)
      IF(ANS.LT.QNUL) CALL AVSUB(VNUL,PLNV(IDS),PLNV(IDS))
C...
      J51CKP = 0
      J51CKD = 0
      K51CKP = 0
      K51CKD = 0
   13 IF(J50(IIS))15,15,25
C...
C... TWO SURFACE ITERATION  ..... NOTE  J = 1
   15 J=1
C*****
C     NOTE INDEXING-----
C*****
C... THIS LOOP CHECKS TO SEE IF S(IPS) AND S(IDS) ARE BOTH LESS THAN OR
C... EQUAL TO .1 OF TOLERANCE.  IF SO, YOU WILL SEE TWO ACENTR03 ON THE
C... DYNDMP LISTING. THEN CALL ATLTST TO VERIFY.
C... ONLY OTHER EXIT FROM THIS LOOP IS TO 4005. THIS HAPPENS WHEN ONE
C... OR BOTH SURFACE(S) DOES NOT MEET ABOVE TEST. THEN SETUP PSEUDO
C... CS PLANE, CALL APLNEX TO MOVE THE CUTTER CLOSER TO TWO SURFACES.
C... IF APLNEX OPERATION IS SUCCESSFUL, CALL AMIND FOR PS AND DS, DO
C... THE TOLERANCE TEST, IF OK, SET JCR=0 AND RETURN. IF NOT, TRY THE
C... ITERATION OVER(MAX. 25 TIMES).
 4004 DO 4011 I=IPS,IDS,LSV
      K =((I-IPS)/LSV )*LISV  + 1
C... JS SET = TO 0 AT ENTRY. AND SET = TO 1 WHEN JCNT2(COUNTER FOR
C... TANGENT CS LOOP) IS EXHAUSTED.
      IF(JS.EQ.1) GO TO 4011
      IF(IPL(K))4012,4012,4003
 4012 IF(DABS(S(I)) - TAU(I)) 4011,4005,4005
 4003 IF(ITLON(K) .NE. 0) GO TO 13579
      IF(DABS(S(I)) .LT. TAU1(I)) GO TO 4011
      IF(DABS(S(I)) .LT. DABS(TAU2(I))) GO TO 4011
      GO TO 4005
13579 IF(S(I))4006,4011,4007
 4006 IF(S(I) - QP1*TAU2(I) + QP5X01)4005,4011,4011
 4007 IF(S(I) - QP1*TAU1(I) - QP5X01)4011,4011,4005
 4011 CALL ADYNDP(AB( 7),5,110000)
C...
       ITOL = 0
       ISAVE = IS
       IISAVE = IIS
C...
       IS = IPS
       IIS = IIPS
       CALL ATLTST(IRET)
C...
       ITOL = ITOL+ IRET
C...
       IS = IDS
       IIS = IIDS
       CALL ATLTST(IRET)
C...
       ITOL = ITOL +IRET
       IS = ISAVE
       IIS = IISAVE
C...
       IF (ITOL.NE.0) GO TO 4005
C... WITHIN TOLERANCE OF PS AND DS.  ** SMILE **
C... REMEMBER J=1 WHEN J50=0
       GO TO (25,72,41),J
C... OUT OF TOLERANCE OF PS OR DS(OR BOTH)
 4005 GO TO(17,2036,302),J
   17 CALL AVCROS(PLNV(IPS),PLNV(IDS),PLNV(IS))
      CALL AVNORM(PLNV(IS),PLNV(IS),IER)
      PLND(IS) = QNUL
      CALL ADYNDP(AB( 9),5,110000)
      IF(MULTAX.EQ.0) GO TO 1701
 1751 CALL ATINKR
      JW6=1
      IF(JTR) 1756,1752,1701
 1752 IF(JTA) 1753,1754,1753
 1753 JTA = 0
      GO TO 11
 1754 JTA = 1
 1701 CALL APLNEX
 1711 IF(JPXR) 20,188,20
   20 IF(DABS(S(IPS)) - DABS(S(IDS))) 21,23,23
 23   I=IPS
   22 CALL AVMULT(TN(I),S(I),CMOVE)
      CALL ADYNDP(AB(11),5,110000)
      GO TO 24
 21   I=IDS
      GO TO 22
   24 CMOVE(1) = QP9*CMOVE(1) + PLND(IS)*PLNV(IS)
      CMOVE(2) = QP9*CMOVE(2) + PLND(IS)*PLNV(IS+1)
      CMOVE(3) = QP9*CMOVE(3) + PLND(IS)*PLNV(IS+2)
      GO TO 18
  188 IF(JCNT1-10) 189,191,18
  189 IF(JCNT1-5) 190,191,18
  190 IF(JCNT1-3) 18,191,18
  191 CALL AVMULT(CMOVE,QP5,CMOVE)
   18 CONTINUE
      ICMVL = 0
      CALL AVLENG(CMOVE,ANS)
      IF((JAM.EQ.1).AND.(IPDPL.EQ.1)) GO TO 618
      IF((ANS .LE. DPMAX) .OR. (ANS .GE. CMVLST)) GO TO 618
      CMVLST = ANS
      CALL AVNORM(CMOVE,CMOVE,IER)
      CALL AVMULT(CMOVE,DPMAX,CMOVE)
      ICMVL = 1
  618 CALL AVADD(TE,CMOVE,TE)
      CALL ADYNDP(AB(13),5,110000)
      CALL AVSUB(TE,TEK,VTEM)
      CALL AVLENG(VTEM,ANS)
      IF((ICSCNT .GT. 1) .AND. (J51(IIS) .EQ. 1) .AND.
     1   (ANS .GE. (100.0D0 * DP))) GO TO 4001
      IF(JCNT1)19,10,19
   19 IF(ICMVL .EQ.0) JCNT1=JCNT1-1
      GOTO11
C
C     C2A
 1756 CALL AERR(-906)
      JTRC = JTRC - 1
      IF(JTRC) 1755,1755,1701
C...
 1755 CALL AERR(907)
C...
   10 IF((ISTRUP .NE. 1) .OR. (NUMSUR .NE. 2)) GO TO 97531
      IF((IPL(IIPS) + IPL(IIDS)) .EQ. 2) GO TO 97531
      IF((ISFTYP(IIPS) + ISFTYP(IIDS)) .NE. 2) GO TO 97531
      IF(KFL602 .NE. 0) GO TO 97531
      CALL AVDOT(SN(IPS),SN(IDS),ANS)
      IF(DABS(ANS) .LT. QP9999) GO TO 97531
      KFL602 = 1
      IF(IPL(IIDS) .EQ. 1) GO TO 97530
      KKPLNE = IPS
      KKNONE = IDS
      GO TO 97529
97530 KKPLNE = IDS
      KKNONE = IPS
97529 CALL AVSUB(SP(KKPLNE),CC(KKNONE),VTEM)
      CALL AVDOT(VTEM,SN(KKPLNE),ANS)
      IF(ANS .LT. QNUL) CALL AVSUB(VNUL,SN(KKPLNE),VTEM)
      CALL AVMULT(VTEM,RC(KKNONE),VTEM)
      CALL AVADD(CC(KKNONE),VTEM,VTEM)
      CALL AVSUB(VTEM,TEK,VTEM)
      CALL AVADD(TEK,VTEM,TE)
      GO TO 11
97531 IF((ICSCNT .GT. 1) .AND. (J51(IIS) .NE. 0)) GO TO 4001
C
      IF(JAM)87,870,87
  870 EPS8(IPS)=Q2P*EPS8(IPS)
      EPS8(IDS) = Q2P*EPS8(IDS)
      EPS8(IS)  = Q2P*EPS8(IS)
      JAM=1
      JCNT1=25
      CALL ADYNDP(AB(15),5,110000)
      CALL AERR(-901)
      GO TO 11
 87   IF (J51(IIS))  4001,88,4001
   88 DP = QP6*DP
      IF(DP - DABS(TAU(IS))) 89,4001,4001
   89 IF(JCNT1)90,90,91
   90 CALL AERR(902)
   25 IF(J51(IIS))26,4002,26
C...  3 SURFACE ITERATION BEGINS ....
 26   JMINR = 1
C...  ****************************************************** 08 *****
      CALL ADYNDP(AB(17),5,110000)
C...
      CALL AMIND
C...
C...  ****************************************************** 09 *****
      CALL ADYNDP(AB(19),5,110000)
      JMINR=0
      IF(JMIN)29,29,87
 29   IF(ISFTYP(IIS)-4) 30,50,30
   30 IF(NOTAN(IIS))31,31,9
    9 GOTO50
C...
   31 PLND(IS)=S(IS)
      CALL AVSTO (SN(IS),PLNV(IS))
      CALL AVDOT(PLNV(IS),TN(IS),ANS)
      IF(ANS.LT.QNUL) CALL AVSUB(VNUL,PLNV(IS),PLNV(IS))
   34 J=2
      CALL ADYNDP(AB(21),5,110000)
      GO TO 4004
 2036 IF(NOTAN(IIS)) 1701,36,36
   36 CALL AVDOT(SN(IS),SN(IPS),ANS)
      IF(DABS(ANS) .LE. QP9999) GO TO 37
  139 IF(DABS(S(IS)) - DP) 39,37,37
   39 IFL4(IIS)=1
      IF((IPL(IIPS) + IPL(IIS)) .EQ. 2) GO TO 1701
      GOTO40
   37 CALL AVDOT(SN(IS),SN(IDS),ANS)
      IF(DABS(ANS) .LE. QP9999) GO TO 1701
  138 IF(DABS(S(IS))-DP) 38,1701,1701
   38 IFL4(IIS)=0
      IF((IPL(IIDS) + IPL(IIS)) .EQ. 2) GO TO 1701
   40 NOTAN(IIS)=1
      CALL ADYNDP(AB(23),5,110000)
      GO TO 11
 4002 JCR=0
      GO TO 4101
 4001 JCR=-1
      GOTO47
 41   JCR=1
 4101 IF(MULTAX.EQ.0) GO TO 47
42      CONTINUE
C...  ****************************************************** 12 *****
      CALL ADYNDP(AB(25),5,110000)
C...
      CALL ATINKR
C...
C...  ****************************************************** 13 *****
      CALL ADYNDP(AB(27),5,110000)
C...
      JW6 = 1
      IF(JTR)43,44,47
C... COULD NOT DETERMINE NEW TA DURING 5-AXIS CALCULATION.  *** 904 ***
   43 CALL AERR(904)
   44 IF(JCNT3)46,45,45
C... 5-AXIS ITERATION DID NOT CONVERGE.                     *** 903 ***
 46   CALL AERR(903)
C...
 45   JCNT3=JCNT3-1
      JCNT2=25
      JCNT1=25
C...  ****************************************************** 14 *****
      CALL ADYNDP(AB(29),5,110000)
C...
      GOTO11
C...
 47   IF (J51(IIS))  48,49,48
 48   J50(IIS) = 0
      J51(IIS) = 0
   49 IF(JAM)1001,1000,1001
 1001 JAM=0
      EPS8(IPS)=EPS1(IPS)
      EPS8(IDS)=EPS1(IDS)
      EPS8(IS)=EPS1(IS)
 1000 NOTAN(IIS)=0
C...  ****************************************************** EX *****
      CALL ADYNDP(AB(31),3,111100)
C....
      RETURN
C...
C...                NEXT 15 CARDS FOR SPLIT.  BHC
C...  ACENTR PARTITIONED AT BHC TO USE 180K COMPILER
C...  SET UP BRANCHING INDEX 'IIN', THEN CALL ACNTR2
C
   50 IIN = 1
      GO TO 9000
C...
   72 IIN = 2
      GO TO 9000
   91 IIN = 3
      GO TO 9000
  302 IIN = 4
      GO TO 9000
 8000 IIN = 5
 9000 CALL ACNTR2
      GOTO (11,25,41,48,89,1010,1701,4001,4004,8001,36),IOUT
      END

