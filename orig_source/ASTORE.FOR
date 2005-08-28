      SUBROUTINE ASTORE(IARG1,N1,IARG2,N2)
      INTEGER*4  IARG1(2), IARG2(2)
      IF(N2.NE.8) GO TO 10
      DO 5  I=1,2
   5  IARG2(I) = 0
      IF(N1.EQ.2)  K2 = 2
      IF(N1.EQ.4)  K2 = 2
      IF(N1.EQ.8)  K2 = 1
      K1 = 1
      GO TO 20
   10 K1 = 2
      K2 = 1
   20 K3 = 3 - MAX0(K1,K2)
      IF(N2.EQ.-4)  K1 = 1
      DO 30 K=1,K3
      IARG2(K2) = IARG1(K1)
      K1 = K1 + 1
      K2 = K2 + 1
   30 CONTINUE
      RETURN
      END

