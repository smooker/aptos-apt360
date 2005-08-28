      SUBROUTINE ATAPE
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4 AB
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,
     1TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(9)
      COMMON/FRD/D1MOD,F1MOD,F1SHOT,D1SHOT,FRATE,IFMOD
C... A2CMMN START
      COMMON/A2CMMN/ADUM(720) ,TE(3) ,
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
     2J40 ,J43 ,J54 ,J103 ,BDUM(2100) ,IER ,INSTR1 ,INSTR2 ,NWDS ,ICL ,
     3NREC ,IRECNO  ,ITRFLG ,NW ,IDUMMY
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
C     ATAPE SUBROUTINE WRITES CODE AND SPECIFIED NUMBER OF TOOL CENTERS
C     (AND TLAXIS IF MULTIAXIS) ON CLTAPE. NO OUTPUT IF DNTCUT HAS BEEN
C     GIVEN.  ALSO WRITES AUX FEDRAT(IF GIVEN) DWORK AWAY FROM CS.
C     PROGRAM
      DIMENSION AB(2),TEFR(3),TEBASE(3)
       DATA AB(1),AB(2)/4HATAP,4HETP /
      CALL ADYNDP(AB(1),5,000000)
      IF(ICUT)200,9999,190
 9999 IF(IER .NE. -10) GO TO 187
      IF(IFMOD.EQ.0) GO TO 187
      IF(INS1 .EQ. 8) GO TO 300
  187 CONTINUE
  185 IF (NW) 186, 190, 186
  186 NCLREC=NCLREC+1
      IF(IFMOD .EQ. 0) GO TO 400
      IF(INS1 .EQ. 8) GO TO 500
  400 CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT,NW,A,0
     1)
      IF (IER) 189, 195, 195
  189 ICL=6
C
C
      CALL AVSTO(TE,TEFR)
  190 NW = 0
      RETURN
  195 CALL AERR (2102)
      RETURN
  200 CONTINUE
      WRITE(IOUTAP,201) KND,ABCD(1),ABCD(2)
  201 FORMAT(' DNTCUT POINTS FOR ISN ',I5,' DS IS ',A6,A6)
      IF(MULOUT.EQ.1) GO TO 250
      WRITE(IOUTAP,202) (TCDAT(IKK),IKK=1,NW)
  202 FORMAT(' ',15X,3(F15.8,4X))
      GO TO 190
  250 WRITE(IOUTAP,252) (TCDAT(IKK),IKK=1,NW)
  252 FORMAT(' ',15X,6(F15.8,4X))
      GO TO 190
  300 CONTINUE
      IER=0
      IF(IFMOD.EQ.1) GO TO 299
      DWORK=D1SHOT
      FWORK=F1SHOT
      GO TO 298
  299 DWORK=D1MOD
      FWORK=F1MOD
  298 CONTINUE
      DSMIN=Q1PE36
      INCRMT = 3 + 3*MULOUT
  301 CALL AVSTO(TEFR,TEBASE)
      DSM=QNUL
      DO 305 KOUNT=1,NW,INCRMT
      KEEP=KOUNT
      CALL AVSUB(TCDAT(KOUNT),TEBASE,VTEM)
      CALL AVLENG(VTEM,ANS)
      DSM=DSM+ANS
      IF(DSM.GT.DSMIN) GO TO 350
  305 CALL AVSTO(TCDAT(KOUNT),TEBASE)
      IF(DSM.GT.DWORK) GO TO 310
  306 NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,4,NCLREC,1,2000,1,1009,1,FWORK,1)
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT,NW)
  307 NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,4,NCLREC,1,2000,1,1009,1,FRATE,1)
      IF(IFMOD.EQ.-1) IFMOD=0
      IF(IFMOD.EQ.2) IFMOD=1
      GO TO 189
  310 DSMIN = DSM - DWORK
      GO TO 301
  350 ANS = ANS - DSM + DSMIN
      CALL AVNORM(VTEM,VTEM,IER)
      CALL AVMULT(VTEM,ANS,VTEM)
      CALL AVADD(VTEM,TEBASE,TCDAT(250))
      IF(MULOUT.EQ.1)CALL AVSTO(TCDAT(KEEP+3),TCDAT(253))
      IF(KEEP.NE.1) GO TO 360
      IF(ANS .EQ. QNUL) GO TO 306
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT(250),
     1INCRMT)
      ICL=6
      GO TO 306
  360 NCLREC=NCLREC+1
      KKK = KEEP-1
      IF(ANS .EQ. QNUL) GO TO 610
      CALL ATAPWT(CLTAPE,IER,6,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT(1),
     1KKK,TCDAT(250),INCRMT)
      GO TO 700
  610 CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT(1),KKK
     1)
  700 ICL=6
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,4,NCLREC,1,2000,1,1009,1,FWORK,1)
      KKK = NW - KKK
      NCLREC=NCLREC+1
      CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT(KEEP),
     1KKK)
      GO TO 307
C ... OUTPUT ONLY 10 POINTS,MAKE ADJUSTMENTS AND RETURN
  500 CONTINUE
      CALL ATAPWT(CLTAPE,IER,5,NCLREC,1,5000,1,ICL,1,ABCD,2,TCDAT(1),30)
      IF(IER)510,195,195
  510 NW=NW-30
      ICL = 6
      I = 28
      IF(MULOUT .NE. 0) I=25
      CALL AVSTO(TCDAT(I),TEFR)
      DO 520 I=1,210
      TCDAT(I) = TCDAT(I + 30)
  520 CONTINUE
      RETURN
      END

