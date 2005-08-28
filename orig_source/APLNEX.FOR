      SUBROUTINE APLNEX
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
      IMPLICIT REAL*8 (A-H,O-Z)
      REAL*4  AB
C...
C... TO CALCULATE A VECTOR, CMOVE, WHICH, IF APPLIED AT TE POSITION,
C... WILL MOVE THE CUTTER TO SIMULTANEOUS CONTACT WITH THREE PLANES.
C...           RETURN VARIALBE    JPXR = 0  CMOVE CALCULATION OK
C...                              JPXR = 1  UNABLE TO CALCULATE CMOVE
C...
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
     2 J40, J43, J54, J103 , ADUM(2100)
C
      COMMON/A2CMMN/ IER, INSTR1, INSTR2, NWDS , ICL ,
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
C...
      DIMENSION AB(2)
      DATA AB(1),AB(2)/4HAPLN,4HEXTP/
C...
C...
C... *********************************************************** TP ***
       CALL ADYNDP (AB(1),4,110000)
C...
C... UPON ENTRY, PLND AND PLNV TO A PLANE TANGENT TO THE SURFACE POINT
C... USED TO CALCULATE THE NORMAL DISTANCE WILL HAVE BEEN CALCULATED
C... FOR EACH (PS,DS,CS)
C...
C...
C... IF ANY TWO OF THE PLANES ARE PARALLEL,  JPXR = 1
C...
      CALL AVCROS(PLNV(IPS),PLNV(IDS),TEMP)
      CALL AVDOT(TEMP,PLNV(IS),TEMP)
      IF(QP5X01-DABS(TEMP(1))) 1,3,3
C...
C... CRAMER'S RULE IS USED TO CALCULATE CMOVE
C...               PLNV(PS) . CMOVE = PLND(PS)
C...               PLNV(DS) . CMOVE = PLND(DS)
C...               PLNV(CS) . CMOVE = PLND(CS)
C...
    1 CONTINUE
      TEMP(2)=PLNV(IPS)
      TEMP(3)=PLNV(IDS)
      TEMP(4)=PLNV(IS)
      TEMP(5)=PLNV(IPS+1)
      TEMP(6)=PLNV(IDS+1)
      TEMP(7)=PLNV(IS+1)
      TEMP(8)=PLNV(IPS+2)
      TEMP(9)=PLNV(IDS+2)
      TEMP(10)=PLNV(IS+2)
      TEMP(11)=PLND(IPS)
      TEMP(12)=PLND(IDS)
      TEMP(13)=PLND(IS)
C...
      CALL AVCROS(TEMP(5),TEMP(8),TEMP(14))
C...
       CMOVE(1)=(TEMP(11)*TEMP(14)+TEMP(12)*TEMP(15)+TEMP(13)*TEMP(16))/
     1 TEMP(1)
C...
      CALL AVCROS(TEMP(11),TEMP(8),TEMP(14))
      CMOVE(2)=(TEMP(2)*TEMP(14)+TEMP(3)*TEMP(15)+TEMP(4)*TEMP(16))/TEMP
     1(1)
C...
      CALL AVCROS(TEMP(5),TEMP(11),TEMP(14))
C...
      CMOVE(3)=(TEMP(2)*TEMP(14)+TEMP(3)*TEMP(15)+TEMP(4)*TEMP(16))/TEMP
     1(1)
C...
C... IF ANY TWO OF THE PLANES ARE WITHIN ONE DEGREE OF BEING PARALLEL,
C... ADJUST CALCULATED CMOVE, THE LENGTH OF CMOVE IS NOT ALLOWED TO
C... EXCEED THE SUM OF PLND'S.
C...
      IF(QP017 - DABS(TEMP(1)))4,5,5
C...
    4 JPXR = 0
    2 CONTINUE
C... *********************************************************** EX ***
C...
C...
      RETURN
C...
    5 CALL AVLENG(CMOVE, VTEM)
      CALL AVNORM(CMOVE,TEMP(2),IER)
      IF((IPL(IIPS)+IPL(IIDS)+IPL(IIS)).GE.2) GO TO 4
       TEMP(1) = DABS(PLND(IPS)) + DABS(PLND(IDS)) + DABS(PLND(IS))
       IF(TEMP(1)-VTEM(1)) 6,4,4
    6 CALL AVMULT(TEMP(2),TEMP,CMOVE)
      GO TO 4
C...
 3    JPXR = 1
      GO TO 2
       END

