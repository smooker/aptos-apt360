      SUBROUTINE AHYPR1
C
C...  H = HYPERB/CENTER, SYM. PT. AT CENTER, LENGTH SEMI-MAJOR, $
C...             LENGTH SEMI-MINOR, ANGLE OF MAJOR AXIS WITH X-AXIS $$
C
      IMPLICIT REAL*8(A-H,O-Z)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
C
C     SET HYPERBOLA FLAG
      JSUBER=K1
      CALL AELP01
      RETURN
      END

