       SUBROUTINE ASEC2D (ISTX1,ISTX2,MXSS)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8 (A-H,O-Z)
       COMMON/A2BURP/  ADENTC,ADENT,ADUMMY,ANS
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,
     1TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(9)
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
      COMMON/A2CTDF/        TLHITE(1) ,TANHI(1)  ,TANLO(1)  ,UMAX(1)   ,
     1R1(1)     ,CORRAD(1) ,TCONT(1)  ,TLINC(65)
      DIMENSION  SINL(1), COSL(1), TLLDAT(1)
      EQUIVALENCE(SINL(1),TANHI(1)), (COSL(1),TANLO(1)), (TLLDAT(1),
     1TCONT(1))
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
      DIMENSION TANTOC(2)
C     *****
C     *****
       IF (ISTX1.GT.K1) GO TO 200
C
C     SURFACE CANONICAL FORM
 3000 GOTO(3010,3020,3030,3010),INSTR2
C     I31 = 1,2,3,4...N FOR PS,DS,CS,CS1,CS2...CSN.
C     IT = IPS,IDS,ICS,ETC
C     IIT = IIPS,IIDS,IICS,ECT
 3010 I31 = 1
      IT = IPS
      IIT = IIPS
C     TURN OFF AUTOPS AND NOPS FLAGS
      IAUTPS = 0
      INOPS = 0
      GOTO 3025
C     C DRIVE SURFACE
 3020 I31 = 2
      IT = IDS
      IIT = IIDS
C     SET UP BCD NAME + SUBSCRIPT
      ABCD(1) = PROBUF(4)
      ABCD(2) = PROBUF(5)
      IF((ABCD(1).EQ. TANTOC(1)).AND.(ABCD(2).EQ.TANTOC(2)))JCNT3=30
      GO TO 3025
3030  CONTINUE
C      INCREASE CHECK SURFACE COUNT
      ICSCNT = ICSCNT+1
      I31 = ICSCNT+2
      IT = ICS + (ICSCNT-1)*LSV
      IIT = IICS + (ICSCNT-1)*LISV
C      SET IFL4 FLAG FOR PS OR DS TANGENCY
C      SET TOOL ON CONDITION APPROPRIATELY
C...    *** IDQ MUST BE 2 BYTE ON S/360  ****
      CALL ASTOR(PROBUF(1),8,IDQ,2)
      IF(IDQ.EQ.4) GO TO 3031
      IF(IDQ.EQ.8) GO TO 3036
      CALL ASTOR(PROBUF(1),8,ISFTYP(IIT),2)
C     NOT TANGENCY CASE
      GO TO 3025
C      TANTO
3031   IFL4(IIT)=0
      ITLON(IIT)=0
      IF(ISFTYP(IIDS).NE.3) ITLON(IIT)=1
      TANTOC(1) = PROBUF(4)
      TANTOC(2) = PROBUF(5)
      GO TO 3025
C      PST AN
3036    IFL4(IIT)=1
      CALL ASTOR(4,4,PROBUF(1),8)
      ITLON(IIT)=0
      IF(ISFTYP(IIPS).NE.3) ITLON(IIT) = 1
      GO TO 3025
C
C     EXAMINE SURFACE USE INDICATOR AND SET PAST = -1. IF PAST SPECIFIED
 3025 PAST(IT) = Q1P
      CALL ASTOR(PROBUF(1),8,IDQ,2)
      IF(IDQ.EQ.2) PAST(IT) = -Q1P
C...IF ON,DS   CTOCL=0         -1,TLLFT       +1,TLRGT
      IF((I31 .EQ. 2) .AND. (IDQ .EQ. 3)) CTOCL = QNUL
C     SET ISTYPE TO THE TYPE OF SURFACE---PLANE,SPHERE,ETC
C...    *** ISTYPE MUST BE 2 BYTE ON S/360  ****
      CALL ASTOR(PROBUF(2),8,ISTYPE,2)
C     CHECK FOR VALID SURFACE TYPE AND SET J = NO OF WORDS REQUIRED TO S
C     TORE CANONICAL FORM FOR SMALL SURFACES, J=WORD COUNTER FROM PROTAP
C     (3RD ELEMENT IN PROBUF) +2. FOR LARGE SURFACES, J= PROBUF(7)+4
C
      IF(ISTYPE.GT.1) GOTO 3040
C     ERROR
 3039 CALL AERR(1401)
 3040 IF(ISTYPE.GT.10) GOTO 3050
C     LESS THAN 10-SMALL SURFACE
      II = 9
 3045 GO TO (30459,30451,30451,30452,30452,30453,30453,30454,30453,30453
     1,30459,30459,30455,30453,30456),ISTYPE
30451 II = 1
      GO TO 30459
30452 II = 2
      GO TO 30459
30453 II = 3
      GO TO 30459
30454 II = 4
      GO TO 30459
30455 II = 5
      GO TO 30459
30456 II = 6
C*******************************************************************W.L.
C*******************************************************************W.L.
30459 J24(IIT) = II
 3047 CALL ASTOR (PROBUF(3),8,INCFS,2)
C     INCFS IS 2 LESS THAN REQUIRED LENGTH OF CANONICAL FORM
      J = INCFS+2
      IF(ISTYPE.EQ.15)  J=J+49
      GOTO 3060
C     NOT LESS THAN 10 TEST FOR SPHERE AND QUADRIC
 3050 IF(ISTYPE.EQ.13) GOTO 3045
C     SPHERE = 13
C     QUADRIC = 14
      IF(ISTYPE.EQ.14) GOTO 3045
      IF(ISTYPE.EQ.15) GO TO 3045
C*******************************************************************W.L.
C     LOFT=16
      IF(ISTYPE.EQ.16)  GOTO 3700
C      POLCON
C     MUST BE LARGE SURFACE OR ERROR
C     TEST FOR TABCYL (ONLY LARGE SURFACE ALLOWED CURRENTLY)
      IF(ISTYPE.EQ.50) GOTO 3046
      IF(ISTYPE.EQ.53) GO TO 3046
C*******************************************************************W.L.
C     ERROR
      GO TO 3039
 3046 CALL ASTOR(PROBUF(7),8,INCFS,2)
C     ADD 4 TO GET TYPE, WORDS TO FOLLOW, NAME AND SUBSCRIPT
      J = INCFS + 5
      IF ( ISTYPE.EQ.50) J24(IIT) = 7
      IF (ISTYPE.EQ.53) J24(IIT) = 8
C*******************************************************************W.L.
C
C
 3060 CONTINUE
C     COMPUTE JA=INCREMENTAL NO OF LOCATIONS TO STORE THIS CANONICAL
C     FORM  ALL SURFACE LENGTHS ASSUME D = 8 INITIALLY
      JA = J-LOFS(IIT)
C     FOR PART AND DRIVE SURFACES, IF JA=0 WE MAY STORE CANONICAL FORM
C     WITHOUT FURTHER TESTS
      IF((JA.EQ.0).AND.(I31.LE.2)) GOTO 3500
C     SEE IF WE HAVE EXCEEDED ALLOWED NUMBER OF SURFACES
      IF(I31.GT.NUMSFS) CALL AERR(302)
C     IF STORING CS, DONT WORRY ABOUT STORAGE
      IF(I31.GE.3) GOTO 3500
C     WORKING WITH PS OR DS
      GOTO(3061,3062),I31
C     PART SURFACE, SEE WHICH WAY TO MOVE SURFACES FIRST
 3061 IF(JA.GT.0) GOTO 3070
C     LESS SPACE REQUIRED FOR PRESENT PS - RELOCATE DS UP + RESET IPONTR
      CALL ABKKPR(2,JA)
C     NOW RELOCATE DS - PS AND DS BRANCH USE THIS CALL -SIGN OF JA SELEC
 3062 CALL ABKKPR(3,JA)
      GOTO 3500
 3070 CONTINUE
C     PS REQUIRES MORE SPACE THAN PREV. RELOCATE CS FIRST
      CALL ABKKPR(3,JA)
      CALL ABKKPR(2,JA)
C
C
C     JUST ABOUT READY TO STORE SURFACE---SEE IF THERE IS ENOUGH ROOM
C     MXSS (=600) IS MAX NO OF CELLS FOR SURFACE STORAGE
C     JTUSED = CELLS WHICH WOULD BE USED AFTER STORAGE OF PRESENT SURF.
C     ZERO OUT JTUSED AND SET LDS(IIT) TO LENGTH OF SURFACE
 3500 JTUSED = 0
      LOFS(IIT)=J
C     FOR PS OR DS, CHECK LENGTH ONLY OF PS AND DS FOR CS, CHECK ALL
      IF(I31.GT.2) GOTO 3501
C     PS OR DS
      JTUSED = LOFS(IIPS) +LOFS(IIDS)
      GOTO 3502
C     CS
 3501 DO 3503 I=1,I31
      K=(I-1)*40
      IPONTR(K+1) = JTUSED + 1
3503  JTUSED = JTUSED + LOFS(K+1)
C     TEST FOR OVERFLOW
3502  IF(JTUSED.GT.MXSS) CALL AERR(303)
C     SPACE OK-SET UP LOCCAN AS POINTER TO FIRST CELL IN BLOCK FOR THE
C     CURRENT CANONICAL FORM
      LOCCAN = IPONTR(IIT)
C     TEST FOR LARGE SURFACE
      IF(ISTYPE.GT.49) GOTO 3505
C     SMALL SURFACE
      DO 3504 I=1,J
      CANSTO(LOCCAN)=PROBUF(I+1)
 3504 LOCCAN = LOCCAN+1
      GOTO 3600
C     LARGE SURFACE
 3505 CANSTO(LOCCAN) = PROBUF(2)
3506  LOCCAN = LOCCAN +2
C     GET RECORD NO FOR SURF TAPE
      CALL ASTOR(PROBUF(6),8,IRECNO,4)
      CALLASERCH(SRFTAP,IRECNO,IER)
      IF(IER.GE.0) CALL AERR(12)
      CALL ATAPRD(SRFTAP,IER,NWDS,4,IRECNO,1,IRECNO,1,IRECNO,1,CANSTO(LO
     1CCAN),0)
      IF(IER.GE.0) CALL AERR(13)
      CALL ASTOR(NWDS,4,CANSTO(LOCCAN-1),8)
C
C     SET FLAGS + SWITCHES - ZERO OUT PLANE AND UN FLAGS
 3600 CONTINUE
      IPL(IIT) = 0
      IUNFL(IIT) = 0
      LIMFL(IIT) = 0
      IF((ISTYPE.LT.6).OR.(ISTYPE.EQ.13)) IUNFL(IIT)=1
      IF((ISTYPE.EQ.3).OR.(ISTYPE.EQ.2)) IPL(IIT) = 1
      IF(IDQ.NE.0) ISFTYP(IIT) = IDQ
      GOTO 200
C     LOFT
 3700 CALL APTLFT
  200  ISTX2 = K1
      IF((ISTYPE.EQ.4).OR.(ISTYPE.EQ.5)) ISTX2 = 2
      IF(INSTR2.NE.2) ISTX2 = 1
       RETURN
       END

