      SUBROUTINE ATDL
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8(A-H,O-Z)
       COMMON /ATMATY/XMAT4(16),XMAT3(16),XMAT2(16),XMAT1(16),TMATX(16)
       COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      CALL ATFMVC(-1)
      SUM4=DEFSTO(4)*DEFSTO(4)+DEFSTO(5)*DEFSTO(5)+DEFSTO(6)*DEFSTO(6)
      IF(DABS(SUM4-1.D0).LE.1.D-13) GO TO 20
      SUM4=DSQRT(SUM4)
      DEFSTO(7)=DEFSTO(7)*SUM4
      SUM4=1.D0/SUM4
      DO 10 J=4,6
   10 DEFSTO(J)=DEFSTO(J)*SUM4
   20 SUM=DEFSTO(4)*TMATX(4)+DEFSTO(5)*TMATX(8)+DEFSTO(6)*TMATX(12)
      DEFSTO(7)=DEFSTO(7)+SUM
      RETURN
      END

