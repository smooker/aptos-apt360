      SUBROUTINE AQADR1
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C
C...  Q = QADRIC/A,B,C,F,G,H,P,Q,R,D $$
C
      IMPLICIT REAL*8(A-H,O-Z)
       DIMENSION DEFANS(82)
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
      EQUIVALENCE(VST(7200),DEFTAB(1000))
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
C
       DO 10  K = 1,3
 10   DEFANS(K) = DEFTAB(K+1)
      DEFANS(4) = DEFTAB(11)
       DO 20  K = 5,10
 20   DEFANS(K) = DEFTAB(K)/2.0
      RETURN
      END

