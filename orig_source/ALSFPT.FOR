      SUBROUTINE ALSFPT
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
      IMPLICIT REAL*8(A-H,O-Z)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
       REAL*8 PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,TAPES2,
     1 TAPES3,TAPES4,PPNAME
       INTEGER PUNTAP
       COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,
     1 TAPES1,TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
       DIMENSION IDFTAB(2000),IDFSTO(170)
      EQUIVALENCE(VST(7200),DEFTAB(1000))
      COMMON/A2CLS7/PPSEQ1,PPSEQ2,ENAME,EINAME,IEREC,ISN
      COMMON/A1PAS2/I,J,K,L,MOVLGE,KANMAX,ICANST,IOVREC,KANPTR,MDFTAB,
     1KANCNT,KAUX,KDFCNT,IDEFP,KPRCNT,MDFPRE,IPREP,KOVFLP,KSRFCT,KOVCNT,
     2LSCAN,IOVFLO,MAXCAN,IREF,ICANSC,NAMSTA,KANGO,LASPTP,ISUB,
     3LCOMP,LGEREC,IRECN,JREC,JNUM,KANCUR,KANCOT,KDFENT,KANPAR,LGELOC,
     4IDTMOV,ISPPRG,INDEXS,KPTP,KPTPCT,KLASTP,KLASCT,KPRNT
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
       EQUIVALENCE (DEFTAB(1),IDFTAB(1)),(DEFSTO(1),IDFSTO(1))
C
C     THIS ROUTINE IS USED TO WRITE A LARGE SURFACE DEFINITION IN THE
C     SRFTAP FILE.
C     THE INPUT TO THE PROGRAM IS THE DEFSTO AND DEFTAB TABLES, AND THE
C     RECORD NO. IN LGEREC
C
C     POSITION THE FILE
      LGEREC = LGEREC + 1
      CALL ASERCH(SRFTAP,LGEREC,IRET)
C     WAS THERE AN ERROR
            IF(IRET.GE.0) GO TO 10
C
C     THERE WAS NO ERROR, FILE IS PROPERLY POSITIONED. GET SUBSCRIPT.
       SUB = IDFSTO(6)
C     GET NO. WORDS IN CANONICAL FORM. ADD 2 FOR CORRECT SRFTAP COUNT.
       N = IDFTAB(2) - 1
       M = N + 2
C     GET SURFACE TYPE
       K = IDFSTO(1)
C
C...     WRITE SRFTAP RECORD
       CALL ATAPWT(SRFTAP,IRET,6,LGEREC,1,K,1,M,1,EINAME,1,SUB,1
     1 ,DEFTAB(2),N)
C...     TEST FOR AN ERROR IN WRITING THE RECORD
            IF(IRET)  25, 20, 20
C
C  10 THERE WAS AN ERROR IN SEARCHING THE FILE.
   10 JSUBER=73
      LGEREC = LGEREC - 1
      GO TO 30
C  20 THERE WAS AN ERROR IN WRITING THEFILE.
   20 JSUBER=74
      LGEREC = LGEREC - 1
      GO TO 30
C
C     SET RECORD NO. AND LENGTH OF CANONICAL FORM
   25  IDFSTO(7) = 0
       IDFSTO(8) = LGEREC
       IDFSTO(9) = 0
       IDFSTO(10) = N
C
   30  RETURN
       END

