      SUBROUTINE AVIOL(PA,IVIOL)
      IMPLICIT REAL*8 (A-H,O-Z)
C
      DIMENSION PA(1)
C***
C     SPECIAL COMMON FOR 2 DIMENSIONAL PACKAGE-- USES PROTAPE BUFFER
C     READ AREA WHICH IS AVAILABLE AT ARLM2 TIME AS SCRATCH
C***
C     NOTE... VARIABLES IER,VTEM,VNUL ARE NOT THE SAME AS IN THE MAIN
C     STREAM ARITHMETIC ELEMENT
C     ALSO EX,EY,EZ,VNUL
      COMMON/A2CMMN/DUMMY(1308) ,CSCF(3) ,DSCF(3) ,CFTEM(3) , VTEM(3) ,
     1PTEM1(3)  ,PTEM2(3)  ,PT(3,6)   ,DOT(6)    ,FPNT(3)   ,TE2D(3)   ,
     2TI2D(3)   ,CR        ,THDS      ,THCS      ,TAUDS     ,TAUCS     ,
     3PERCEN    ,ANS       ,RES       ,PNTTAN(3) ,EX(3)     ,EY(3)     ,
     4EZ(3)     ,VNUL(3)   ,
     5ICSCF     ,IDSCF     ,ITOPT     ,N         ,IDONE     ,NREV      ,
     6ITFAR     ,ITC       ,IOC       ,IPC       ,INTP      ,IER       ,
     7NINT      ,ICASE     ,ITAN
      COMMON/A2DYDP/ KDYNFQ(12), NKFQ
      COMMON/A2FPC / Q15X01,QP9X01    ,QP6X01    ,QP5X01    ,QP4X01    ,
     1QP0001    ,QP001     ,QP01      ,QP1       ,Q1P       ,Q10P      ,
     2Q1000P    ,Q1PE5     ,Q1PE6     ,Q1PE10    ,Q1PE20    ,Q1PE30    ,
     3Q1PE36    ,Q1PE38    ,QP8X01    ,QP7X01    ,
     4QP4X09    ,QP9       ,QP99      ,QP995     ,QP997     ,QP999     ,
     5QP9999    ,QP4X95    ,QP5X95    ,QP6X9     ,QP7X9     ,
     6QP6X05    ,QP5X05    ,QP4X05    ,QP0005    ,QP005     ,QP05      ,
     7QP5       ,Q5P       ,                                 Q4X045    ,
     8QP0002    ,QP0047    ,QP017     ,Q1RAD     ,QP0349    ,QP125     ,
     9QP6       ,QP2       ,QP2499    ,QP25      ,QP3
      COMMON/A2FPC / QP7   ,QP75      ,QP8       ,QP866     ,Q1P01     ,
     1Q1P1      ,Q1P2      ,Q1P25     ,Q1P5      ,Q2P       ,Q2P5      ,
     2Q3P       ,Q3P5      ,Q4P       ,Q8P       ,Q11P      ,Q45P      ,
     3Q90P      ,Q130P     ,Q4500P    ,Q9000P    ,QP02      ,QNUL      ,
     4QPIE       ,QFIL(9)
C
C...  CHECK WHETHER CUTTER VIOLATES SURFACE AT GIVEN POINT
C
C
C...  BRANCH ON SURFACE TYPE
C
      GO TO (10,20),ICSCF
C
C...  LINE
C.
   10 RES = CSCF(1)*PA(1) +CSCF(2)*PA(2) - CSCF(3)
      GO TO 30
C
C...  CIRCLE
C
   20 RES = DSQRT((CSCF(1)-PA(1))**2 +(CSCF(2)-PA(2))**2) - CSCF(3)
      GO TO 30
C
C...  TEST RES, WHICH IS MINIMUM DISTANCE, AGAINST CUTTER RADIUS
C
   30 CFTEM(1) = DMAX1(DABS(CR - TAUCS),(CR*QP01))
      IF(CR .LE. QNUL) CFTEM(1) = TAUCS
      IF(DABS(RES) .GT. CFTEM(1)) GO TO 35
C
C...  YES,IN VIOLATION
C
      IVIOL = 1
      RETURN
C
C...  VIOLATION DOES EXIST
C
   35 IVIOL =0
      IF(DABS(RES).LT.QP6X01) IVIOL=1
      KK = 3
      DO 88 I=KK,3
      PA(I) = QNUL
   88 CONTINUE
      RETURN
      END

