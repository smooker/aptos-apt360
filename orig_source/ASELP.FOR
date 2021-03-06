      SUBROUTINE ASELP
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      IMPLICIT REAL*8 (A-H,O-Z)
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
C
C...  SELECTS FINAL POINT
C
C...  SET COUNTERS FOR TO,ON AND PAST, AND INITIALIZE IDONE FOR ADECIS
C
      IDONE = 0
    1 ITC = 0
      IOC = 0
      IPC = 0
C      SPECIAL CASE CHECK
C      (TANTO)
      IF(NINT.EQ.-1)  GO TO 100
C
C...  SEE IF CURRENTLY VIOLATING SURFACE
      IF((ICASE .EQ. 2) .AND. (NINT .EQ. 2)) GO TO 200
      GO TO 210
  200 IF(ITOPT .NE. 2 .AND. ITOPT .NE. 4) GO TO 150
  210 CALL AVIOL(TE2D,IVIOL)
      IF((ITOPT.EQ.1).AND.(IVIOL.EQ.0).AND.(CR.LT.TAUCS))TAUCS=CR*0.9D0
      IF((IDSCF .NE. 1) .OR. (NINT .NE. 6)) GO TO 300
      IF((DOT(1) .GE. 0.) .OR. (DOT(2) .GE. 0.)) GO TO 300
      IF((DOT(3) .LT. 0.) .OR. (IVIOL .NE. 0)) GO TO 300
      DOT(3) = -DOT(3)
  300 IF(ICASE .LT. 3) GO TO 5
      IF(CR.LE.0.D0) GO TO 5
      IF((ITOPT.EQ.2).OR.(ITOPT.EQ.4)) GO TO 5
      IF(NINT.NE.2) GO TO 5
      CALL AVMULT(TI2D,TAUCS,PTEM1)
      CALL AVADD  (PTEM1,TE2D,PTEM2)
      CALL AVADD(PTEM1,PTEM2,PTEM2)
      CALL AVIOL(PTEM2,IVIOL)
    5 CONTINUE
C     SET INTP      0 FOR NEXT IS TO
C                   1 FOR NEXT IS PAST
      INTP=0
      IF (IVIOL .EQ. 1) INTP=1
      IF(NINT .NE. 2) GO TO 9
      IF(ICASE .NE. 3) GO TO 9
      IF(ITOPT .EQ. 3) GO TO 9
      IF((ITOPT .EQ. 1) .AND. (IVIOL .EQ. 0)) GO TO 9
      ANS=CSCF(1)*(TE2D(1)-PT(1,1))+CSCF(2)*(TE2D(2)-PT(2,1))
      IF((DABS(ANS)-TAUCS) .GE. 0) GO TO 6
      ANS=CSCF(1)*TI2D(1)+CSCF(2)*TI2D(2)
    6 ANS=ANS*(CSCF(1)*(DSCF(1)-PT(1,1))+CSCF(2)*(DSCF(2)-PT(2,1)))
      INTP=0
      IF(ANS .LE. 0) INTP=1
    9 CONTINUE
C...  BEGIN EXAMINATION OF POINTS
C
      DO 50  I =1 ,NINT
C
C...  IF DS IS LINE AND DOT IS NEGATIVE, SKIP
C
      IF((IDSCF.EQ.1).AND.(DOT(I).LE.0.))GO TO 50
C
C...  SEE IF POINT IS AN ON  TYPE
C
      CALL AVIOL(PT(1,I),IVIOL)
      IF(IVIOL.EQ.1) GO TO 10
C
C...  NOT ON, CHECK TO,PAST
C
      IF(INTP.EQ.0) GO TO 20
      IF(INTP.EQ.1) GO TO 30
C
C...  ON
C
   10 IOC = IOC +1
      CALL ADECIS(2,IOC,IACC)
      IF(IACC.EQ.1) GO TO 80
      INTP = 1
      GOTO 50
C...  TO
C
   20 ITC =ITC+1
      INTP = 1
      CALL ADECIS(1,ITC,IACC)
      IF(IACC.EQ.1) GO TO 80
      GO TO 50
C
C...  PAST
C
   30 IPC =IPC +1
      INTP =0
      CALL ADECIS(3,IPC,IACC)
      IF(IACC.EQ.1) GO TO 80
      GO TO 50
C
C...  STORE FINAL POINT
   80 CALL AVSTO (PT(1,I),FPNT)
      RETURN
C
C...  LOOP END
C
   50 CONTINUE
C
C...  IF EVER FALL THROUGH, HAVE NOT   ACCEPTED ANY POINT
C      TEST FOR SPECIAL CASE ... IF SO, TRY AGAIN
      IF(ICASE.LT.3)               GO TO 99
      KK = MOD(NINT,2)
      IF(KK.NE.1) GO TO 99
      IF(ITFAR.NE.2) GO TO 99
      ITFAR = 1
      NREV = NREV + 1
      GO TO 1
   99 IF((ICASE.NE.1).OR.(ITOPT.NE.3).OR.(DOT(3).LE.0.D0))CALL AERR(724)
      CALL AVSTO(PT(1,3),FPNT)
      RETURN
  100 CALL AVSTO(PT(1,1),FPNT)
C
C...  CALL ADECIS TO SET REVOLUTION COUNTER NREV
      IDONE = 0
      CALL ADECIS(0,0,IACC)
      CALL AVSUB(TE2D,FPNT,VTEM)
      CALL AVLENG(VTEM,ANS)
      IF(ANS .LT. (TAUDS*0.5D0)) NREV = NREV + 1
      RETURN
  150 CONTINUE
      IF(N .GT. 1) GO TO 153
      IF((ITOPT.EQ. 1) .AND. (DOT(1) .GT. 0.D0)) GO TO 151
      IF((ITOPT.EQ. 3) .AND. (DOT(2) .GT. 0.D0)) GO TO 152
  153 CALL AERR(724)
  151 CALL AVSTO(PT(1,1),FPNT)
      RETURN
  152 CALL AVSTO(PT(1,2),FPNT)
      RETURN
      END

