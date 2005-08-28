      SUBROUTINE AGENCN(N)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C               *          *          *          *         *
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
C***********************************************************************
      GO TO (100,200,200),N
C
C...  GC = GCONIC/A,B,C,D,E,F $$
C
  100 DEFANS(1) = DEFTAB(2)
      DEFANS(2) = DEFTAB(4)
C
C...  DEFANS(3) = 0.
C
      DEFANS(4) = DEFTAB(7)
C
C...  DEFANS(5) = 0.
C...  DEFANS(6) = 0.
C
      DEFANS(7) = DEFTAB(3)/2.0
      DEFANS(8) = DEFTAB(5)/2.0
      DEFANS(9) = DEFTAB(6)/2.0
C
C...  DEFANS(10) = 0.
C
      GO TO 240
  200 DEFANS(1) = DEFTAB(2)**2-DEFTAB(4)
      DEFANS(2) = 1.0
C
C...  DEFANS(3) = 0.
C
      DEFANS(4) = DEFTAB(3)**2-DEFTAB(6)
C
C...  DEFANS(5) = 0.
C...  DEFANS(6) = 0.
C
      DEFANS(7) = -DEFTAB(2)
      DEFANS(8) = (2.0*DEFTAB(2)*DEFTAB(3)-DEFTAB(5))/2.0
      DEFANS(9) = -DEFTAB(3)
C
C...  DEFANS(10) = 0.
C
            IF(IDFTAB(14).NE.4) GO TO 240
  150 DEFTAB(8) = DEFANS(1)
      DEFANS(1) = DEFANS(2)
      DEFANS(2) = DEFTAB(8)
      DEFTAB(8) = DEFANS(8)
      DEFANS(8) = DEFANS(9)
      DEFANS(9) = DEFTAB(8)
  240 RETURN
      END

