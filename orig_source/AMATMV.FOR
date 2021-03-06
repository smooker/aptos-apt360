      SUBROUTINE AMATMV
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8(A-H,O-Z)
      REAL*8 INWORD,NEWONE,NAME,IDIS,MACNAM,KRFSYS
      INTEGER PUNTAP
      INTEGER AMATOD,AEXTRA,AMDTOA,AEXTRD,AEXCH,DEBUG,SUM
       COMMON/ATAPTB/PROTAP,DUMTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1
     1 ,TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
       EQUIVALENCE (CANTAP,SRFTAP)
      COMMON/A1COM/NAME,KRFSYS,SUM,JSUBER,NAMSUB,DEBUG,INDXPT,LOOP,IFINI
      COMMON/AMCSTF/MACNAM(5),MACCUR,MACLCN(5),MACRD,MACSTR(5),NMACVR
     1 ,NUMIDS,IDLOCN,MACIDS(5),ISVID
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/AMXTAB/MAXTAB,MAXVS1,MAXVS2,MAXPTP,MAXSCL,MAXVS,
     1MAXVST,MXPTPP,MXCAN,MXSRCN,MAXSLR,MAXELM,MAXPOT
      COMMON/AVST/VST(7200)
      EQUIVALENCE(PTPP(1),VST(1),CANON(1))
      DIMENSION PTPP(1),CANON(1)
      COMMON/AMACRO/LIMCAN,LMDW,NITEMS,JWHAT,MACREC,MACVST,MACERR
      DIMENSION STUFF(3)
      COMMON/ALIBRY/AMACVR(50),AMACVL(50),MACICL(50),DEFNAM,SEGNAM
     1 ,IVARCT,ISYSMC,IRDMOD,LUUP,NWUNRD,NOLIBR
C
      LOOK = 0
      GOTO(400,10,100,70),JWHAT
 10   LMD=LMDW/K5
      STUFF(1) = DEFNAM
      STUFF(2)=AFULL8(MACVST,LMD)
      STUFF(3) = AFULL8(NUMIDS,NITEMS)
      L=LMDW+NITEMS+K3
C...  PRINT OUT EXTENT OF CANON FOR THIS MACRO
      WRITE (IOUTAP,15) DEFNAM,L
  15  FORMAT(' THE MACRO  ',A8,' USES ',I6,'  LOCATIONS IN CANON ')
C     WILL IT FIT IN CANON
            IF(LIMCAN+L.LE.MAXTAB) GO TO 20
C...     SEE IF IT WILL FIT IN CANON AT ALL
            IF(L.GT.MAXTAB-MAXVST-MXPTPP) GO TO 295
      CALL ASERCH(CANTAP,MACREC,IOFLAG)
      IF(IOFLAG.GE.K0) GOTO 1760
      CALL ATAPWT(CANTAP,IOFLAG,K4,MACREC,K1,IDT,1,IDT,1,STUFF,3)
      IF(IOFLAG.GE.K0) GOTO 1770
C     UPDATE VST
      VST(MACVST+1) = AFULL8(10,AMATOD(MACREC,2))
      MACREC=MACREC+K1
      CALL ATAPWT(CANTAP,IOFLAG,K5,MACREC,K1,IDT,1,IDT,1,CANON(LIMCAN+4)
     1,LMDW  , PTPP(MAXVST+1),NITEMS)
      MACREC = MACREC + 1
      IF(IOFLAG.GE.K0) GOTO 1770
      RETURN
 20   J=LIMCAN
      DO 30 I=K1,3
      J=J+K1
 30   CANON(J)=STUFF(I)
      J=J+LMDW
      DO 50 I=K1,NITEMS
      J=J+K1
      LAD = MAXVST + I
 50   CANON(J)= PTPP (LAD)
C     UPDATE  VST
      VST(MACVST+1) = AFULL8(K10,LIMCAN+1)
C     UPDATE CANON LIMIT
      LIMCAN=LIMCAN+L
 60   RETURN
C     SEARCH MACLIB FOR SYSTEM MACRO
 70   CALL ATAPOP(MACLIB,K1,IOFLAG)
      CALL ASERCH(MACLIB,NAME,IOFLAG)
      IF(IOFLAG.EQ.K1) GO TO 80
      IF(IOFLAG.GT.K1) GO TO 1790
C     GET ID RECORD
      CALL ATAPRD(MACLIB,IOFLAG,NWRDS,K4,NREC,K1,IDT,1,IDT,1,STUFF,3)
      LIBMAC=K1
      GOTO 110
C     NOT THERE
 80   JSUBER=101
      RETURN
C     EXTRACT MACRO RECORD NUMBER
  100 CONTINUE
      IF(JWHAT.EQ.1) GO TO 60
      NREC = AMDTOA(AEXTRA(VST(MACVST+1),4),2)
C     GET ID RECORD
      CALL ASERCH(CANTAP,NREC,IOFLAG)
      IF(IOFLAG.GE.K0) GO TO 1790
      CALL ATAPRD(CANTAP,IOFLAG,NWRDS,K4,NREC,K1,IDT,1,IDT,1,STUFF,3)
      LIBMAC=K0
 110  IF(IOFLAG.GE.K0) GO TO 1800
C     COMPUTE LENGTH OF MACRO
      L=K5*AEXTRA(STUFF(2),K4)+AEXTRA(STUFF(3),K4)+K3
      NITEMS=L-K3
C     WILL THE MACRO FIT IN CANON
      IF(LIMCAN+L.GT.MAXTAB) GO TO 170
C     YES,IT WILL - CHECK JWHAT FLAG FOR MACRO VARIABLE CALL
      J=LIMCAN
      DO 130 I=K1,3
      J=J+K1
 130  CANON(J)=STUFF(I)
      J=J+K1
C     CHECK LIBMAC TO READ FROM PROPER DATA SET
      IF(LIBMAC.EQ.K0) GO TO 140
C     READ FROM SYSTEM MACRO LIBRARY
      CALL ATAPRD(MACLIB,IOFLAG,NWRDS,K4,NREC,K1,IDT,1,IDT,1,CANON(J),
     1 NITEMS  )
      CALL AVS1PT(KRET)
      IF(KRET.EQ.K1)  GO TO 150
      IF(KRET.EQ.K2)  GO TO 160
      JSUBER = 1002
      SUM = 1
      RETURN
  160 JSUBER = 15
      SUM = 1
      RETURN
C     READ FROM CANTAP
 140  CALL ATAPRD(CANTAP,IOFLAG,NWRDS,K4,NREC,K1,IDT,1,IDT,1,CANON(J),
     1 NITEMS )
 150  IF(IOFLAG.GE.K0) GO TO 1800
C     SET LOCATION OF MACRO
      LMDW=LIMCAN+K1
C     UPDATE LIMCAN
      LIMCAN=LIMCAN+L
C     UPDATE VST
      NVST=AEXTRA(VST(NAMSUB+1),K4)
      CALL AGETR(AEXTRD(NVST,K2)+LMDW,VST(NAMSUB+1),K3)
      RETURN
C     MAKE ROOM
  170 MSTARC = MAXVST + MXPTPP
 175  MSTART=MSTARC+K1
      LEGRM=K0
 180  ANAME=CANON(MSTART)
C     EXTRACT VST INDEX
      M=AMDTOA(CANON(MSTART+1),K4)
      N=AEXTRA(CANON(MSTART+1),K4)
      LEG=K5*N+AEXTRA(CANON(MSTART+2),K4)+K3
C     CURRENT MACRO
      K=MACCUR-K1
      IF(K.EQ.K0) GO TO 190
      DO 185 I=K1,K
      IF(MACNAM(I).EQ.ANAME) GO TO 280
 185  CONTINUE
C     NOT CURRENT
 190  LIVE=K0
C     IS IT OUT ON FILE
      NVST=AEXTRA(VST(M+1),K4)
       IQ = AMDTOA(NVST,2)
      IF(IQ.NE.0) GO TO 210
C     NO  - MOVE IT OUT - ARE WE AT END OF CANTAP
      IF(LOOK.NE.K0) GO TO 200
C     NO - GET US THERE
      CALL ASERCH(CANTAP,MACREC,IOFLAG)
      IF(IOFLAG.GE.K0) GO TO 1760
      LOOK=K1
C     UPDATE VST TO SHOW MACRO IS ON FILE
  200 IQ = MACREC
      CALL ATAPWT(CANTAP,IOFLAG,K4,MACREC,K1,IDT,1,IDT,1,CANON(MSTART),
     1 3)
      IF(IOFLAG.GE.K0) GO TO 1770
      MACREC=MACREC+K1
      CALL ATAPWT(CANTAP,IOFLAG,K4,MACREC,K1,IDT,1,IDT,1,
     1 CANON(MSTART+3),LEG-3)
      MACREC = MACREC + 1
      IF(IOFLAG.GE.K0) GO TO 1770
 210  LEGRM=LEGRM+LEG
      MSTART=MSTART+LEG
      CALL AGETR(AMATOD(IQ,2),VST(M+1),3)
C     IS THERE ROOM WITHOUT THIS MACRO
      IF(LIMCAN-LEGRM+L.LE.MAXTAB) GO TO 215
C     NO - LOOK FOR MORE
      IF(MSTART.LE.LIMCAN) GO TO 180
      JSUBER = 178
      RETURN
  215 IF(MSTART.LE.LIMCAN) GO TO 220
      LIMCAN = LIMCAN - LEGRM
      GO TO 100
C     SQUEEZE CANON
  220 KM = MSTARC
      DO 230 I=MSTART,LIMCAN
      KM = KM + 1
 230  CANON(KM)=CANON(I)
C     UPDATE TABLES
      LIMCAN=LIMCAN-LEGRM
      KM=MSTARC+K1
 240  ANAME=CANON(KM)
      M=AMDTOA(CANON(KM+1),K4)+K1
      N=AEXTRA(CANON(KM+1),K4)
      LEGM=K5*N+AEXTRA(CANON(KM+2),K4)+K3
C     UPDATE VST
      NVST=AEXTRA(VST(M),K4)
      CALL AGETR(AEXTRD(NVST,K2)+KM,VST(M),K3)
C     IS THIS CURRENT MACRO
      IF(K.EQ.K0) GO TO 260
      DO 250 I=K1,K
      IF(MACNAM(I).EQ.ANAME) GO TO 270
 250  CONTINUE
 260  KM=KM+LEGM
C     ARE WE FINIDHED
      IF(KM.LT.LIMCAN) GO TO 240
C     YES - CHECK FOR A LIVE ONE - IF NOT, READ IN MACRO
      IF(LIVE.EQ.0) GO TO 100
C     YES - SKIP OVER
      GO TO 290
C     UPDATE NESTED MACRO TABLE
 270  MACLCN(I)=MACLCN(I)-LEGRM
      MACSTR(I)=KM
      GOTO 260
C     SKIP OVER ACTIVE MACRO - IS THERE ANY SQUEEZING TO DO
 280  IF(LEGRM.NE.K0) GOTO 300
C     NO - ALTER CANON STARTING LOCATION
 290  MSTARC=MSTARC+LEG
C     CHECK FOR CANON FULL OF LIVE ONES
      IF(MSTARC.LT.LIMCAN) GO TO 175
C     YES - NO ROOM -JSUBER IT
  295  JSUBER = 178
      NAME=VST(MACVST)
      SUM = 1
      RETURN
C     HERE IS A LIVE ONE
 300  LIVE = K1
      GOTO 220
C     GET ROOM FOR MACRO VARIABLES
  400 L = LMDW+3
      GOTO 170
 1760 JSUBER=176
      RETURN
 1770 JSUBER=177
      RETURN
 1790 JSUBER=179
      RETURN
 1800 JSUBER = 180
      RETURN
      END

