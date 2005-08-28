      SUBROUTINE APOCKB
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,
     1TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/APOSTP/PPNAME(20)
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(9)
C... A2CMMN START
      COMMON/A2CMMN/ADUM(720), TE(3) ,
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
      DIMENSION XI(3,22),Q(3,21),U(3,21),W(3,20),BL(20),
     1XIPRIM(3,21),VPRIM(3,20),UPRIM(3,20),T(3),WD(3),Y(3),PTINT(3),
     2CTEMP(3,20),CROSTO(3),UCRSTO(3),TCRSTO(3),COR(3,20),KTAB(20)
      DIMENSION POCDAT(69),QONE(3),WONE(3),FRONE(1),FRTWO(1),FRTHRE(1)
      COMMON/A2POK8/ADDEM1,ADDEM2,BL    ,COSVA ,CROSTO,CTEMP ,CUTRAD,
     1DCOV  ,DELDST,DIST  ,DUMMY ,OFCSTO,OFFSTO,PHITMP,PTINT ,QONE  ,
     2Q     ,RTEST ,SIN2VA,SPHIO2,T     ,TCRSTO,U     ,UCRSTO,UPRIM ,
     3VPRIM ,W     ,WD    ,WONE  ,XI    ,XIPRIM,X1    ,X2    ,X3    ,
     4Y
      COMMON/A2POCK/IPCERR,IWDCNT,NWD,IBM1,IBM2,IBM3,IBM4,IBM6
      COMMON/A2POK2/     JONE,    NC,NCORIG,  JTWO,  JTHR,  JFOU,  KALC,
     1     MOVE,  INIT,NCUTBK,NPLUS1,NLESS1,ICRSTO,  KTAB,KUTBAC,KOLAPS,
     2    JSAVE, INTER,  KONE,  KTWO,JDUMMY,   NUM, ITEST,   KT1,   KT2,
     3    KOVER
C     EQUIVALENCE FOR POCKET
      EQUIVALENCE(PROBUF(1),POCDAT(1)),
     1(POCDAT(2),RADEFF),(POCDAT(3),OFSETC),(POCDAT(4),OFSETF),
     2(POCDAT(5),FRONE(1)),(POCDAT(6),FRTWO(1)),(POCDAT(7),FRTHRE(1)),
     3(POCDAT(8),OVRIDE),(POCDAT(9),PTTYPE),(POCDAT(10),COR(1,1))
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HPOCK,4HET  /
C
C
 1611 CALL ATAPWT(CLTAPE,IPCERR,4,NCLREC,1,2000,1,1009,1,FRONE(1),1,Q1P,
     10,Q1P,0)
      IF (IPCERR.LT.0)GO TO 1630
 1620 CALL AERR(3508)
 1630 CALL ASERCH(POCTAP,IBM1,IPCERR)
      IF (IPCERR.LT.0)GO TO 1640
      CALL AERR(3509)
 1640 CALL ATAPRD(POCTAP,IPCERR,IBM4,4,IBM1,1,IBM2,1,IBM3,1,TCDAT(1),0)
      IF(IPCERR.LT.0) GO TO 1650
      CALL AERR(3506)
 1650 CONTINUE
 1660 IBM1=IBM1-1
      IBM3=1
      NCLREC=NCLREC+1
      IF (MULOUT.EQ.1)GO TO 1670
      NWD=3
      GO TO 1680
 1670 NWD=6
 1680 CALL ATAPWT(CLTAPE,IPCERR,6,NCLREC,1,5000,1,5,1,AB(1),1,0,1,
     1TCDAT(IBM3),NWD)
      IF (IPCERR.LT.0)GO TO 1690
      CALL AERR(3508)
 1690 IBM2=IBM2-1
      IBM3=IBM3+NWD
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IPCERR,4,NCLREC,1,2000,1,1009,1,FRTWO(1),1,Q1P,
     10,Q1P,0)
      IF(IPCERR.LT.0) GO TO 1700
      CALL AERR(3508)
 1700 IF (IBM1.EQ.0)GO TO 1760
 1710 IF (IBM2.EQ.0)GO TO 1730
 1720 IBM4=IBM2*NWD
      CALL ATAPWT(CLTAPE,IPCERR,6,NCLREC,1,5000,1,5,1,AB(1),1,0,1,
     1TCDAT(IBM3),IBM4)
      IF (IPCERR.LT.0)GO TO 1730
      CALL AERR(3508)
 1730 CALL ASERCH(POCTAP,IBM1,IPCERR)
      IF (IPCERR.LT.0)GO TO 1740
      CALL AERR(3509)
 1740 CALL ATAPRD(POCTAP,IPCERR,IBM4,4,IBM1,1,IBM2,1,IBM3,1,TCDAT(1),0)
      IF (IPCERR.LT.0)GO TO 1750
      CALL AERR(3506)
 1750 IBM3=1
      IBM1=IBM1-1
      GO TO 1700
 1760 IF(IBM2.LE.(NCORIG+1)) GO TO 1775
      IBM4 = (IBM2-1-NCORIG)*NWD
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IPCERR,6,NCLREC,1,5000,1,5,1,AB(1),1,0,1,
     1TCDAT(IBM3),IBM4)
      IF (IPCERR.LT.0)GO TO 1770
      CALL AERR(3508)
 1770 IBM3=IBM3+IBM4
      GO TO 1780
 1775 IBM4 = IBM2*NWD
      GO TO 1785
 1780 IBM4 = (NCORIG+1)*NWD
 1785 NCLREC = NCLREC  + 1
      CALL ATAPWT(CLTAPE,IPCERR,4,NCLREC,1,2000,1,1009,1,FRTHRE(1),1,Q1P
     1,0,Q1P,0)
      IF (IPCERR.LT.0)GO TO 1790
      CALL AERR(3508)
 1790 NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IPCERR,6,NCLREC,1,5000,1,5,1,AB(1),1,0,1,
     1TCDAT(IBM3),IBM4)
      INDX = IBM3 + IBM4 - 3 - 3*MULOUT
      CALL AVSTO(TCDAT(INDX),TE)
      IF (IPCERR.LT.0)GO TO 1800
      CALL AERR(3508)
 1800 RETURN
      END

