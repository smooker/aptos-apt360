      SUBROUTINE APLAN (N)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C
C...  THIS ROUTINE CONTAINS PLANE DEFINITIONS
C
      IMPLICIT REAL*8(A-H,O-Z)
       DIMENSION DEFANS(82)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
       DIMENSION IDFTAB(2000)
      EQUIVALENCE(VST(7200),DEFTAB(1000))
       EQUIVALENCE (DEFTAB(1),IDFTAB(1))
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
      COMMON/ADFPRG/DEFPRG(16)
      DIMENSION TVEC(3),SVEC(3),XYNOR(3),C3(3),
     1TNOR(3),PUVEC(3),V(3),V1(3),PUNOR(3),AMBDA(3),ANS(3),
     2SVECN(3),XO(3),XLAR(3),XSML(3),YLAR(3),YSML(3)
      EQUIVALENCE(DEFPRG(16),TVEC(16),SVEC(16),XYNOR(16),C3(16),
     1TNOR(13),PUVEC(13),V(13),V1(13),PUNOR(10),AMBDA(10),ANS(10),
     2SVECN(7),XO(7),XLAR(4),XSML(4),YLAR(4),YSML(4))
      DIMENSION V2(3)
C***********************************************************************
       GO TO (100,230,320,405,520,630,650,700),N
C
C...  DEFPRE ROUTINE FOR FOLLOWING FORMAT
C...  P=PLANE/A B C D  COEFFICIENTS OF THE PLANE EQUATION
C...  THIS ROUTINE IS LIMITED TO 5 PIECES OF DATA
C
  100 SRSS=DSQRT((DEFTAB(2)**2)+(DEFTAB(3)**2)+(DEFTAB(4)**2))
      IF(SRSS)102,495,102
  102 DEFANS(1)=DEFTAB(2)/SRSS
      DEFANS(2)=DEFTAB(3)/SRSS
      DEFANS(3)=DEFTAB(4)/SRSS
      DEFANS(4)=DEFTAB(5)/SRSS
       GO TO 900
C
C...     PLANE/PT1,PT2,PT3
C
C...  SET UP VECTOR 1 AND VECTOR 2 FOR GENERAL PLANE ROUTINE, PT GIVEN
C
  230 DO 240 J=1,3
      V1(J)=DEFTAB(J+2)-DEFTAB(J+6)
      V2(J)=DEFTAB(J+2)-DEFTAB(J+10)
  240 CONTINUE
      CALL AGENPL(V1,V2,DEFTAB(3))
       GO TO 900
C
C...     PLANE/PT1,PARLEL,PLN1
C
  320 DEFANS(1)=DEFTAB(8)
      DEFANS(2)=DEFTAB(9)
      DEFANS(3)=DEFTAB(10)
      CALL ADOT(DEFANS,DEFTAB(3),DEFANS(4))
       GO TO 900
C
C...     PLANE/PARLEL,PLN1,X-, Y-, OR ZLARGE OR SMALL,D
C
  405       IF(IDFTAB(16)-31)  493, 410, 415
  410 IF(DEFTAB(4)) 465,495,470
  415       IF(IDFTAB(16)-32)  493, 420, 425
  420 IF(DEFTAB(4)) 470,495,465
  425       IF(IDFTAB(16)-35)  493, 430, 435
  430 IF(DEFTAB(5)) 465,495,470
  435       IF(IDFTAB(16)-36)  493, 440, 445
  440 IF(DEFTAB(5)) 470,495,465
  445       IF(IDFTAB(16)-39)  493, 450, 455
  450 IF(DEFTAB(6))465,495,470
  455       IF(IDFTAB(16)-40)  493, 460, 493
  460 IF(DEFTAB(6))470,495,465
  465 D=-1.0
      GO TO 475
  470 D=1.0
  475 DEFANS(1)=DEFTAB(4)*D
      DEFANS(2)=DEFTAB(5)*D
      DEFANS(3)=DEFTAB(6)*D
      DEFANS(4)=DEFTAB(7)*D+DEFTAB(9)
      GO TO 480
C
  493  JSUBER = 1003
      GO TO 480
  495  JSUBER = 1005
  480  GO TO 900
C
C...     PLANE/PT1,PERPTO,VEC1
C
C.... TEST FOR ZERO VECTOR
  520 CALL AZVECT(DEFTAB(8))
      IF(JSUBER)530,525,530
C
C...     NORMALIZE THE GIVEN VECTOR, AND TAKE THE DOT
C...        PRODUCT OF IT AND THE GIVEN POINT
  525 CALL ANORM(DEFTAB(8),DEFANS)
      CALL ADOT(DEFANS,DEFTAB(3),DEFANS(4))
  530  GO TO 900
C
C...     PLANE/PERPTO,PL1,PT1,PT2  (ORIGINAL FORMAT)
C
C...  VECTOR V1 GIVEN, CALCULATE VECTOR V2 FOR GENERAL PLANE ROUTINE.
  630 DO 640 J=1,3
      V2(J)=DEFTAB(J+8)-DEFTAB(J+12)
  640 CONTINUE
      CALL AGENPL(DEFTAB(4),V2,DEFTAB(9))
       GO TO 900
C
C...     PLANE/PT1,PT2,PERPTO,PL1  (ALTERNATE FORMAT)
C
C...     ONE VECTOR GIVEN, COMPUTE SECOND FOR GENERAL PLANE ROUTINE
  650  DO 655  J = 1,3
       V2(J) = DEFTAB(J+2) - DEFTAB(J+6)
  655  CONTINUE
       CALL AGENPL(DEFTAB(12),V2,DEFTAB(3))
       GO TO 900
C
C...     PLANE/SYM PT.,PERPTO,SYM PL1,SYM PL2
  700 CALL AGENPL(DEFTAB(8),DEFTAB(13),DEFTAB(3))
C
  900  RETURN
       END

