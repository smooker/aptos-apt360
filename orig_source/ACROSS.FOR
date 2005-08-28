      SUBROUTINE ACROSS(A,B,C)
      REAL*8 A,B,C,C1,C2,C3
C
C...  TAKE THE CROSS PRODUCT OF TWO VECTORS... C = A X B
C
      DIMENSION A(3),B(3),C(3)
C
      C1  =A(2)*B(3)-A(3)*B(2)
      C2  =A(3)*B(1)-A(1)*B(3)
      C3  =A(1)*B(2)-A(2)*B(1)
      C(1)=C1
      C(2)=C2
      C(3)=C3
      RETURN
      END

