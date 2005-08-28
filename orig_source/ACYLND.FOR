      SUBROUTINE ACYLND(N)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C               *          *          *          *         *
      IMPLICIT REAL*8(A-H,O-Z)
       DIMENSION DEFANS(82)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
      EQUIVALENCE(VST(7200),DEFTAB(1000))
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
      DIMENSION SAM(7)
C***********************************************************************
      GO TO (10,20,30,40),N
C
C...  CYL = CYLNDR/POINT,I,J,K,R
   10 INP = 3
   15 INV = 6
      GO TO 100
C
C...  CYL = CYLNDR/POINT,VECTOR,R
   20 INP = 3
      INV = 7
      GO TO 100
C
C...  CYL = CYLNDR/X,Y,Z,VECTOR,R
   30 INP = 2
      GO TO 15
C
C...  CYL = CYLNDR/X,Y,Z,I,J,K,R
   40 INP = 2
      INV = 5
C
  100 DO 150 K = 1,3
      DEFANS(K) = DEFTAB(INP)
  150 INP = INP + 1
      DO 170 K = 4,7
      DEFANS(K) = DEFTAB(INV)
      SAM(K-3) = DEFANS(K)
  170 INV = INV + 1
  240 CALL AZVECT(SAM)
      CALL ANORM(SAM      ,DEFANS(4))
      RETURN
      END

