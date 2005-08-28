      SUBROUTINE ASTOS
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
C     ASTOS SUBROUTINE STORES SPECIFIED POINT (AND TLAXIS IF MULTIAXIS)
C     IN TCDAT. IF TCDAT IS FULL, IT IS WRITTEN ON CLTAPE BY ATAPE
C     AND RESTARTED.
      COMMON/A2CMMN/ADUM(720),TE(3),TEK(3),TEL(3),TES(3),TA(3),
     1TAK(3)    ,TAL(3)    ,PMOVE(3)  ,TI(3)     ,TIK(3)    ,TIL(3)    ,
     2U2(3)     ,UVEC(3)   ,VTEM(3)   ,CMOVE(3)  ,EX(3)     ,EY(3)     ,
     3EZ(3)     ,VNUL(3)   ,TM(3)     ,DIR(3)    ,AXIS(3)   ,AXIS1(3)  ,
     4AXIS2(3)  ,AXIS3(3)  ,REFPNT(3) ,RGT(3)    ,FWD(3)    ,UP(3)     ,
     5ZLNORM(3) ,ZLPNT(3)  ,TNDIR(3)  ,VA(3)     ,TMVCMP(3) ,P1(3)     ,
     6P2(3)     ,PNT(3)    ,PNT1(3)   ,OLDU1(3)  ,OGLE(3)   ,RZERO(3)  ,
     7TANMOT(3) ,TLEND1(3) ,V(3)      ,CEND(3)   ,DELMOT(3) ,D2(3)     ,
     8DNMOT(3)  ,AX4(3)    ,A         ,B         ,C         ,RA        ,
     9HI        ,ALPHA     ,GAMMA     ,CAGL      ,SAGL      ,COM1
      COMMON/A2CMMN/ COM4 ,COSTH ,CTOCL ,DIAM , DIF ,
     1DIFOUT    ,DINC      ,DP        ,DPE       ,DPI       ,DPL       ,
     2DPMAX     ,DP1       ,DPCNT     ,DSMOV     ,D1        ,D2A       ,
     3EL1       ,EL2       ,FIPNT     ,FLIPCK    ,HAFDIA    ,HCHORD    ,
     4OFFSET    ,PROD1     ,PROD2     ,PSI       ,RADNO     ,RC1       ,
     5RDRM      ,RDRN      ,RONE      ,RZEROL    ,SAVE1     ,SIUTH     ,
     6TANGL     ,THETA     ,ALP       ,EPS7      ,VAMAX     ,VL        ,
     7ZDOTC     ,ZGAMMA    ,ZIGN      ,ZL        ,ZL1       ,ZL2       ,
     8ZNPTS     ,TOLBND    ,CENDIS    ,CENLEN    ,CHORD     ,
     9           ABCD(2)   ,ACARD(2)  ,SAVE(6)   ,CUTDAT(7) ,TEM(10)
      COMMON/A2CMMN/ TEMP(20) ,TCDAT(260) ,QEQUIV(20)
      COMMON/A2CMMN/ IS ,IIS ,IT ,IIT ,IPS ,
     1IIPS      ,IDS       ,IIDS      ,ICS       ,IICS      ,IGS       ,
     2IIGS      ,ICDEFL    ,ICDEFS    ,IAUTPS    ,IGO       ,ICRDCT    ,
     3ICUT      ,IGTFLG    ,INOPS     ,ISRCH     ,IOFSET    ,ISTRUP    ,
     4I3DFLG    ,MULOUT    ,MULTAX    ,NUMAX     ,NUMSFS    ,NUMSUR    ,
     5IGOUG     ,IPDPL     ,NUMDIM    ,IRSTRT    ,ICSCNT    ,I3        ,
     6I31       ,J         ,JA        ,JL        ,JS        ,JT        ,
     7KC        ,KND       ,KR        ,L         ,INCFS     ,NP        ,
     8IBEGIN    ,           IFAR1     ,IK        ,INS1      ,ITNFLG    ,
     9IVAMAX    ,IWS       ,IIWS      ,IZ        ,NEXT1     ,NEXT2
      COMMON/A2CMMN/ NPTS ,NUMPT1 ,JAM ,JAP ,JTUSED ,
     1IFRL      ,N         ,M         ,MDIC      ,JBR       ,JCKR      ,
     2JCPR      ,JCR       ,JDR       ,JGR       ,JMIN      ,JMINR     ,
     3JPR       ,JPXR      ,JTR       ,JCNT1     ,JCNT2     ,JCNT3     ,
     4JSW       ,JTKF      ,LISV      ,LSV       ,IPT       ,JFIND     ,
     5IC        ,ICC       ,IL        ,K         ,NUMPTS    ,IAMDCT    ,
     6IFL2      ,J5        ,J6        ,JW6       ,J10       ,J12       ,
     7 J13, J40, J43, J54, J103, BDUM(2100)
      COMMON/A2CMMN/ IER, INSTR1, INSTR2, NWDS, ICL,
     1NREC      ,IRECNO    ,ITRFLG    ,NW        ,IDUMMY
      COMMON/A2DYDP/ KDYNFQ(12), NKFQ
C     PROGRAM
      DIMENSION AB(2)
       DATA AB(1),AB(2)/4HASTO,4HSTP /
      CALL BDYNDP(AB(1),5,-1)
      CALL CDYNDP(2,1)
       CALL ADYNDP (AB(1),5,001100)
      IF (NW-240) 181, 180, 180
  180 CALL ATAPE
C
  181 CALL AVSTO(TE,TCDAT(NW+1))
      NW= NW+3
C        2Q65 MESSES WITH KFLAG3 HERE
      IF(KDYNFQ(7).LE.(NW/(3+3*MULOUT))) KDYNFQ(7)= 0
C     THIS ZEROES OUT KDYNFQ(7) AFTER THE NUMBER OF POINTS SPECIFIED
C     HAVE BEEN COMPUTED. KDYNFQ(7).NE.0  INHIBITS DYNAMIC DUMPING
  184 IF(MULOUT)182,183,182
  182 CALL AVSTO(TA,TCDAT(NW+1))
      NW=NW+3
  183 RETURN
       END

