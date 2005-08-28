      SUBROUTINE AFWDSL(III)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
C...  TO SELECT THE FORWARD DIRECTION  (FWD)
C...      III = 0  ALLOW ERROR EXIT TO AERR
C...      III = 1  DISABLE ERROR EXIT TO AERR
C...  AFWDSL IS USED PRIMARILY BY AREPRE TO SET UP THE FORWARD DIRECTION
C...  OF MOTION BUT IS ALSO USED BY ATINKR IN CERTAIN MULTI-AXIS STARTUP
C...  CASES. WHEN CALLED FROM ATINKR, THE ERROR EXIT IS DISABLED.
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
C... A2CMMN START
      COMMON/A2CMMN/ADUM(720) , TE(3) ,
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
     2 J40 , J43 , J54 , J103
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
     4QFIL(10)
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HAFWD,4HSL  /
C
      CALL ADYNDP(AB(1),5,001100)
C
      CALL AVSUB(TE,TEK,FWD)
      ITRY = 1
    1 CALL AVNORM(FWD,FWD,IER1)
      CALL AVCROS(FWD,TA,RGT)
      CALL AVNORM(RGT,RGT,IER2)
      CALL AVCROS(TA,RGT,FWD)
      CALL AVNORM(FWD,FWD,IER1)
    2 CALL AVCROS(RGT,FWD,UP)
      CALL AVNORM (UP,UP,IER3)
      IF((IER1+IER2+IER3).EQ.0) GO TO 10
C...
C...                     FORWARD DIRECTION CAN NOT BE DETERMINED (504)
      IF((ITRY.NE.1).AND.(III.NE.1)) CALL AERR(504)
      IF(ITRY.NE.1) RETURN
      ITRY = 2
C...  IF ANY OF THE NORMALIZATIONS FAIL, TRY THE SAME STEPS USING PMOVE
C...  AS THE INITIAL FWD. IF THIS SECOND TRY FAILS, CALL AERR(504).
      CALL AVSTO(PMOVE,FWD)
      GO TO 1
C
C
C
   10 CONTINUE
C
C...  COMMON CELL IGO IS SET AS SHOWN IN THE FOLLOWING TABLE BELOW.
C...  IT IS USED AS A BRANCHING INDICATOR TO SET THE TRUE FORWARD
C...  DIRECTION AS INDICATED.
C...              IGO        FWD
C...  GOLFT        1     FWD = -RGT
C...  GORGT        2     FWD =  RGT
C...  GOFWD        3     FWD =  FWD
C...  GOBACK       4     FWD = -FWD
C...  GOUP         5     FWD =  UP
C...  GODOWN       6     FWD = -UP
C...
      GO TO (100,200,300,400,500,600),IGO
  100 CALL AVSUB(VNUL,RGT,FWD)
      GO TO 300
  200 CALL AVSTO(RGT,FWD)
C............................
  300 RETURN
  400 CALL AVSUB(VNUL,FWD,FWD)
      GO TO 300
  500 CALL AVSTO(UP,FWD)
      GO TO 300
  600 CALL AVSUB (VNUL,UP,FWD)
      GO TO 300
      END

