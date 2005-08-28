      SUBROUTINE ANORM(A,B)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 ***
      IMPLICIT REAL*8(A-H,O-Z)
      REAL*8 A,B
C
C...  NORMALIZE VECTOR A, AND STORE IN B
C
      DIMENSION A(3),B(3)
C
      S=DSQRT(A(1)**2+A(2)**2+A(3)**2)
      DO 20 I=1,3
      B(I)=A(I)/S
            IF(DABS(B(I))-.000001)  10, 10, 20
 10   B(I)=0.
 20   CONTINUE
      RETURN
      END

