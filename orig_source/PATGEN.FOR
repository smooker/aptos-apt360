C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
C
      SUBROUTINE PATGEN (IL)
C
C  TO GENERATE A SERIES OF POINTS IN A PATTERN
C  IL IS TOTAL NO OF LOCATIONS PLUS 3
C
      IMPLICIT REAL*8(A-H,O-Z)
       INTEGER*2 KDFANS(12)
      INTEGER AEXTRA,AMDTOA,DIR
       INTEGER PUNTAP
      DIMENSION DEFANS(82),PTPP(7200),CANON(7200),DEFTAB(1000)
      COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
       COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP
     1, TAPES1,TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
       COMMON/AVST/VST(7200)
      COMMON/A1PAS2/I,J,K,L,MOVLGE,KANMAX,ICANST,IOVREC,KANPTR,MDFTAB,
     1KANCNT,KAUX,KFDCNT,IDEFP,KPRCNT,MDFPRE,IPREP,KOVFLP,KSRFCT,KOVCNT,
     2LSCAN,IOVFLO,MAXCAN,IREF,ICANSC,NAMSTA,KANGO,LASPTP,ISUB,
     3LCOMP,LGEREC,IRECN,JREC,JNUM,KANCUR,KANCOT,KDFENT,KANPAR,LGELOC,
     4IDTMOV,ISPPRG,INDEXS,KPTP,KPTPCT,KLASTP,KLASCT,KPRNT
      COMMON/A2CLS7/PPSEQ1,PPSEQ2,ENAME,EINAME,IEREC,ISN
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
       COMMON/AZURF/ZSUR(4)
      COMMON/APROTP/PROTP(102),PROSAV(102),NOWCLT,LSTPSV,INCORE
     1,JGORIT,SAVMOT
       DIMENSION IODAT(2),IDFSTO(170)
      EQUIVALENCE(VST(1),PTPP(1),CANON(1))
      EQUIVALENCE(VST(7200),DEFTAB(1000))
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
       EQUIVALENCE (DEFSTO(1),IDFSTO(1))
       EQUIVALENCE (DEFANS(1),KDFANS(1))
       DIMENSION IDFTAB(2000)
       EQUIVALENCE (DEFTAB(1),IDFTAB(1)),(IDFTAB(2),KMOVE)
       EQUIVALENCE (IODAT(1),IOFLAG,FILDAT),(IODAT(2),IRECNO)
C
C...     TEST FOR NESTED, UNNAMED, PATTERN - IF SO, ERROR
       IF( EINAME .EQ. 0.0D0 ) GO TO 820
C
       NMSRF1 = IDFTAB(4)
       NMSRF2 = IDFTAB(6)
       NMSRF4 = IDFTAB(2)
C
C...     MOVE INPUT DATA TO REAR OF DEFTAB AREA
       DO 5  J = 4,KMOVE
       ILIM = 1002 - J
       ILOW = KMOVE + 4 - J
    5  DEFTAB(ILIM+1) = DEFTAB(ILOW)
C
C...     TEST FOR PARLEL PATTERN
   10 IF(  NMSRF1  .EQ.  17  ) GO TO 4000
C...     NO - TEST FOR CIRCUL
      IF(  NMSRF1  .EQ.  75  ) GO TO 2000
C...     TRY LINEAR
      IF(  NMSRF1  .EQ.  76  ) GO TO 1000
C...     HOW ABOUT ARC
      IF(  NMSRF1  .EQ.  87  ) GO TO 2000
C...     IF NOT RANDOM...
      IF(  NMSRF1  .EQ.  174 ) GO TO 3000
C...     ...OR GRID, FORMAT IS INCORRECT
            IF(NMSRF1.EQ.176) GO TO 4000
C
  800 JSUBER=800
      RETURN
  801 JSUBER=801
      RETURN
  802 JSUBER=802
      RETURN
  820 JSUBER = 820
      RETURN
C
C***      LINEAR
C...     FIRST PARAMETER MUST BE A POINT
 1000 IF(  NMSRF2  .NE.  3001 ) GO TO 800
C...     IT IS - MAKE SURE THERE IS SPACE FOR IT
            IF(ILIM.LT.3) GO TO 802
C...     MOVE IT TO OUTPUT AREA
       DEFTAB(2) = DEFTAB(ILIM+1)
       DEFTAB(3) = DEFTAB(ILIM+2)
       DEFTAB(4) = DEFTAB(ILIM+3)
       J = 5
C...     SEE IF 2ND PARAMETER IS A POINT
       NMSRF3 = AEXTRA(DEFTAB(ILIM+4),4)
      IF(  NMSRF3  .EQ.  3001 ) GO TO 1002
C...     NO - IF NOT VECTOR, ERROR
            IF(NMSRF3.EQ.3011) GO TO 1004
      GO TO 800
C
C         COMPUTE VECTOR SPACING
 1002  XINCR = (DEFTAB(ILIM+5)-DEFTAB(ILIM+1))/(DEFTAB(ILIM+8)-1.0D0)
       YINCR = (DEFTAB(ILIM+6)-DEFTAB(ILIM+2))/(DEFTAB(ILIM+8)-1.0D0)
       ZINCR = (DEFTAB(ILIM+7)-DEFTAB(ILIM+3))/(DEFTAB(ILIM+8)-1.0D0)
       GO TO 1005
C
C...     PICK UP VECTOR FOR INCREMENTING POINTS
 1004  XINCR = DEFTAB(ILIM+5)
       YINCR = DEFTAB(ILIM+6)
       ZINCR = DEFTAB(ILIM+7)
C
 1005  NMSRF1 = AEXTRA(DEFTAB(ILIM+8),4)
C...     SEE IF 3RD PARAMETER IS 'INCR'
      IF( NMSRF1 .EQ. 66 ) GO TO 1009
C
C...     NO...
C...     SET PICK-UP INDEX TO END OF INPUT DATA
       I = 999
       NPTS = DEFTAB(ILIM+8)
       N = NPTS - 1
       ILIM = I
       GO TO 1015
C
 1009  DIST = DSQRT(DEFTAB(ILIM+5)**2 + DEFTAB(ILIM+6)**2 +
     1        DEFTAB(ILIM+7)**2)
       XDCOS = DEFTAB(ILIM+5)/DIST
       YDCOS = DEFTAB(ILIM+6)/DIST
       ZDCOS = DEFTAB(ILIM+7)/DIST
       ILIM = ILIM + 8
       I = ILIM
C
C...     INITIALLY ASSUME NO. AFTER 'INCR' IS NO. OF POINTS TO COMPUTE
 1010 N=DEFTAB(I+1)
C...     INITIALLY PREPARE TO PICK UP 3RD WORD AFTER 'INCR'
C...     AS DISTANCE BETWEEN POINTS
       L = 3
C
C...     IF 2ND ENTRY AFTER 'INCR' CAN BE 'AT', MUST HAVE AT
C...     LEAST 3 ENTRIES AFTER 'INCR'
            IF(I+2.GT.999) GO TO 1013
      NMSRF1 = AEXTRA(DEFTAB(I+2),K4)
C...     SEE IF 2ND ENTRY AFTER 'INCR' IS 'AT'
      IF( NMSRF1 .EQ. 175) GO TO 1011
C...     NO - SET TO COMPUTE SINGLE POINT
 1013  N = 1
       L = 1
C
C...     SET IL TO PICK UP DISTANCE BETWEEN POINTS
 1011 IL = I + L
C...     COMPUTE COMPONENTS OF INCREMENT TO NEXT POINT
       XINCR = DEFTAB(IL)*XDCOS
       YINCR = DEFTAB(IL)*YDCOS
       ZINCR = DEFTAB(IL)*ZDCOS
C
C...     COMPUTE NUMBER OF POINTS REQUIRED AT GIVEN INCREMENT
 1015  DO 1012  M = 1,N
C...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE
            IF(J+2.GE.ILIM) GO TO 802
       DEFTAB(J) = DEFTAB(J-3) + XINCR
       DEFTAB(J+1) = DEFTAB(J-2) + YINCR
       DEFTAB(J+2) = DEFTAB(J-1) + ZINCR
       J = J + 3
 1012 CONTINUE
C
C         WAS RECORD JUST PROCESSED AN ( AT )
            IF(NMSRF1.EQ.175)  I = I + 2
       I = I + 1
       ILIM = I
C...     TEST FOR END OF STATEMENT
            IF(999.LE.I) GO TO 1020
C
C...     NO - SEE IF NEXT PARAMETER IS WORD 'INCR'
            IF(AEXTRA(DEFTAB(I+1),4).EQ.66) I = I + 1
       GO TO 1010
C
C...     FINISHED...
 1020  KDFANS(9) = 1
       KDFANS(11) = J - 1
C...     SET IL TO LENGTH OF CANONICAL FORM
       IL = J - 1
       GO TO 5000
C
C         CIRCULAR OR ARC
C...     FIRST PARAMETER MUST BE A CIRCLE
 2000       IF(NMSRF2.NE.3004) GO TO 800
      RADCV = .017453292519943295D0
C         STARTING ANGLE
      STANG = DEFTAB(ILIM+8)*RADCV
       XCEN = DEFTAB(ILIM+1)
       YCEN = DEFTAB(ILIM+2)
       RAD = DEFTAB(ILIM+7)
       DEFTAB(2) = XCEN + RAD*DCOS(STANG)
       DEFTAB(3) = YCEN + RAD*DSIN(STANG)
       DEFTAB(4) = (ZSUR(4)-ZSUR(1)*DEFTAB(2)-ZSUR(2)*DEFTAB(3))/
     1 ZSUR(3)
      J=5
C
C...     TEST FOR DIRECTION-OF-ROTATION INDICATOR AFTER STARTING ANGLE
       DIR = AEXTRA(DEFTAB(ILIM+9),4)
      IF( DIR .EQ. 59 .OR. DIR .EQ. 60 ) GO TO 2010
C
C         ASSUME DEFTAB(12) EQUAL ENDING ANGLE
      ENDANG = DEFTAB(ILIM+9)*RADCV
C...     DIRECTION-OF-ROTATION INDICATOR MUST FOLLOW ENDING ANGLE
       DIR = AEXTRA(DEFTAB(ILIM+10),4)
      IF(DIR.EQ.59.OR.DIR.EQ.60) GO TO 2003
       GO TO 800
C
C...     SET D INITIALLY FOR POSITIVE ROTATION ANGLE
 2003 D = 1.0D0
C...     IF DIRECTION INDICATOR WAS 'CLW', SET D FOR NEGATIVE ANGLE
      IF( DIR .EQ. 60 ) D = -D
C...     COMPUTE TOTAL ARC OF PATTERN
      TOTANG = ENDANG - STANG
C...     COMPARE SIGN OF TOTAL INCREMENT WITH INDICATED ROTATION
C...     DIRECTION, AND ADJUST FOR DIRECTION IF NECESSARY
            IF(TOTANG*D.GT.0.0D0) GO TO 2005
C...     TOTAL INCREMENT IS IN WRONG DIRECTION - ADJUST IT
      TOTANG = TOTANG +D*6.2831853072D0
C
C         NUMBER OF LOCATIONS
 2005  PTS = DEFTAB(ILIM+11)
      SI = TOTANG/(PTS - 1.0D0)
       D = 1.0D0
C...     GET NUMBER OF POINTS TO BE DEVELOPED
       NPTS = PTS - 1.0D0
C...     INITIALIZE ANGLE FOR POINTS TO BE DEVELOPED
       THETA = STANG
       I = 1000
       ILIM = I
       GO TO 2020
C
 2002  KDFANS(9) = 2
       KDFANS(11) = J - 1
C...     SET IL TO LENGTH OF CANONICAL FORM
       IL = J - 1
       GO TO 5000
C
C              INCREMENT
 2010  NMSRF2 = AEXTRA(DEFTAB(ILIM+10),4)
C...     MUST HAVE 'INCR' FOLLOWING DIRECTION-OF-ROTATION INDICATOR
C...     WHEN ONLY STARTING ANGLE GIVEN
      IF( NMSRF2 .NE. 66 ) GO TO 800
       I = ILIM + 11
C...     SET D INITIALLY FOR POSITIVE ROTATION ANGLE
       D = 1.0D0
C...     IF DIRECTION INDICATOR WAS 'CLW', SET D FOR NEGATIVE ANGLE
      IF( DIR .EQ. 60 ) D = -D
       THETA = STANG
C
C...     SEE IF ENOUGH ENTRIES STILL REMAIN TO HAVE AN 'AT'
 2011       IF(I+2.GT.999) GO TO 2015
C...     TEST FOR 'AT' FOLLOWING ENTRY ABOUT TO BE USED
       NMSRF3 = AEXTRA(DEFTAB(I+1),4)
      IF( NMSRF3 .EQ. 175) GO TO 2012
C
C...     NO - SINGLE POINT ONLY TO DEVELOP FROM THIS ENTRY
 2015 SI = DEFTAB(I)*RADCV
       I = I + 1
       NPTS = 1
       GO TO 2020
C
C              INCREMENT WITH AT
C...     PICK UP NUMBER OF POINTS TO BE DEVELOPED
 2012 NPTS = DEFTAB(I)
      SI = DEFTAB(I+2)*RADCV
C...     INCREMENT INPUT PICK-UP INDEX
       I = I + 3
C
C...     COMPUTE REQUIRED POINTS
 2020  DO 2013  K = 1,NPTS
C...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE
            IF(J+2.GE.ILIM) GO TO 802
C...     NO - INCREMENT ANGLE FOR NEXT POINT
      THETA = D*SI + THETA
C...     COMPUTE POINT
       DEFTAB(J) = XCEN + RAD*DCOS(THETA)
       DEFTAB(J+1) = YCEN + RAD*DSIN(THETA)
       DEFTAB(J+2) = (ZSUR(4)-ZSUR(1)*DEFTAB(J)-ZSUR(2)*DEFTAB(J+1))/
     1 ZSUR(3)
C...     INCREMENT STORING INDEX FOR NEXT POINT
      J = J + K3
 2013 CONTINUE
       ILIM = I
C
C...     TEST FOR END OF STATEMENT
            IF(999.GE.I) GO TO 2011
       GO TO 2002
C
C         RANDOM
 3000 I = K3
      JJ = K2
       GO TO 3002
C...     ONLY POINTS OR PATTERNS ACCEPTABLE AS INPUT
C...     TO 'RANDOM' PATTERN
 3001  NMSRF2 = AEXTRA(DEFTAB(ILIM),4)
 3002       IF(NMSRF2.EQ.3018) GO TO 3010
            IF(NMSRF2.NE.3001) GO TO 800
C
C...     POINT INPUT
C...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE
            IF(JJ+2.GE.ILIM) GO TO 802
       DEFTAB(JJ) = DEFTAB(ILIM+1)
       DEFTAB(JJ+1) = DEFTAB(ILIM+2)
       DEFTAB(JJ+2) = DEFTAB(ILIM+3)
C...     INCREMENT INPUT PICK-UP INDEX
       ILIM = ILIM + 4
C...     INCREMENT STORING INDEX
      JJ = JJ + K3
       GO TO 3012
C
C...     PATTERN...
C...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE
 3010       IF(JJ+AEXTRA(DEFTAB(ILIM+2),4).GE.ILIM) GO TO 802
C...     NO - LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE
       FILDAT = DEFTAB(ILIM+1)
       CALL ASERCH(SRFTAP,IRECNO,IOFLAG)
C...     TEST FOR ERROR IN FILE SEARCH OPERATION
            IF(IOFLAG.GE.0) GO TO 5200
C...     READ IN PATTERN DEFINITION
       CALL ATAPRD(SRFTAP,IOFLAG,JTEMP1,3,IDFSTO(1),3,DEFSTO(10),2
     1, DEFTAB(JJ),0)
C...     TEST FOR ERROR WHEN READING IN PATTERN
            IF(IOFLAG.GE.0) GO TO 5210
C...     INCREMENT STORING INDEX
       JJ = JJ + AEXTRA(DEFTAB(ILIM+2),4)
C...     INCREMENT INPUT PICK-UP INDEX
       ILIM = ILIM + 4
 3011  CONTINUE
C...     TEST FOR END OF STATEMENT
 3012       IF(ILIM.LT.999) GO TO 3001
C
       KDFANS(9) = 3
       KDFANS(11) = JJ - 1
C...     SET IL TO LENGTH OF CANONICAL FORM
       IL = JJ - 1
       GO TO 5000
C
C         PARALLELOGRAM
C...     FIRST PARAMETER OF INPUT MUST BE LINEAR PATTERN
 4000 IF( NMSRF2 .NE. 3018 ) GO TO 800
       DEFANS(1) = DEFTAB(ILIM+3)
            IF(KDFANS(1).NE.1) GO TO 801
C...     EXTRACT NUMBER OF POINTS IN FIRST LINEAR PATTERN
       NOPT1 = (KDFANS(3)-1)/3
C
C...     TEST FOR OVERFLOW OF AVAILABLE DEFINITION SPACE
            IF(AEXTRA(DEFTAB(ILIM+2),4)+1.GE.ILIM) GO TO 802
C...     NO - LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE
       FILDAT = DEFTAB(ILIM+1)
       CALL ASERCH(SRFTAP,IRECNO,IOFLAG)
C...     TEST FOR ERROR IN FILE SEARCH OPERATION
            IF(IOFLAG.GE.0) GO TO 5200
C...     READ IN PATTERN DEFINITION
       CALL ATAPRD(SRFTAP,IOFLAG,JTEMP1,3,IDFSTO(1),3,DEFSTO(10),2
     1, DEFTAB(2),0)
C...     TEST FOR ERROR WHEN READING IN PATTERN
            IF(IOFLAG.GE.0) GO TO 5210
       JJ = AEXTRA(DEFTAB(ILIM+2),4) + 2
C
C...     INITIALIZE FLAG TO INDICATE COLUMN SPACING FOR PARLEL
C...     PATTERN BEING OBTAINED FROM SPECIFIED INCREMENTS
       ISPCOL = 0
C...     NUMBER OF ROWS FOR PARLEL PATTERN = NUMBER OF
C...     POINTS IN FIRST LINEAR PATTERN
       NOROWS = NOPT1
C...     INITIALIZE NUMBER OF COLUMNS IN PARLEL PATTERN
       NOPT2 = 1
       ILIM = ILIM + 4
       NMSRF2 = AEXTRA(DEFTAB(ILIM),4)
C...     TEST FOR VECTOR AS 2ND INPUT PARAMETER
      IF(NMSRF2 .NE. 3011 ) GO TO 4008
C
C...     VECTOR FOUND - COMPUTE ITS LENGTH
       LL = ILIM
       DIST = DSQRT(DEFTAB(LL+1)**2+DEFTAB(LL+2)**2+DEFTAB(LL+3)**2)
C...     TEST FOR 'INCR' TYPE SPACING
       NMSRF3 = AEXTRA(DEFTAB(ILIM+4),4)
      IF( NMSRF3 .EQ. 66 ) GO TO 4015
C
C...     NO - PICK UP NUMBER OF POINTS TO BE DEVELOPED
       NOPT2 = DEFTAB(ILIM+4)
C...     MAKE SURE THIS IS END OF STATEMENT - IF NOT, ERROR
            IF(ILIM+4.NE.999) GO TO 800
C...     PICK UP INCREMENTAL SPACING FOR POINTS
       XINCR = DEFTAB(ILIM+1)
       YINCR = DEFTAB(ILIM+2)
       ZINCR = DEFTAB(ILIM+3)
C...     COMPUTE NUMBER OF COLUMNS TO BE ADDED TO PARLEL PATTERN
       NOCOLS = NOPT2 - 1
C...     SET FLAG TO INDICATE SPACING OF COLUMNS BEING OBTAINED
C...     FROM A VECTOR AND A SINGLE COUNT ONLY
       ISPCOL = -1
       ILIM = 999
       GO TO 4040
C
C...     COMPUTE PARALLEL PATTERN WITH 'INCR'
 4015  ILIM = ILIM + 5
C...     IF NO INPUT DATA FOLLOWING 'INCR', ERROR - INCORRECT FORMAT
            IF(ILIM.GT.999) GO TO 800
       VX = DEFTAB(LL+1)
       VY = DEFTAB(LL+2)
       VZ = DEFTAB(LL+3)
C
C...     INITIALIZE COUNTER TO DEVELOP ONE COLUMN ONLY
 4020  NOCOLS = 1
C...     SEE IF ENOUGH ENTRIES STILL REMAIN TO HAVE AN 'AT'
            IF(ILIM+2.GT.999) GO TO 4022
C...     SEE IF THIS IS A REPEATED INCREMENT 'AT' COMMON SPACING
 4021  NMSRF3 = AEXTRA(DEFTAB(ILIM+1),4)
            IF(NMSRF3.NE.175) GO TO 4022
C
C...     PROCESS INCR WITH 'AT'
       NOCOLS = DEFTAB(ILIM)
       ILIM = ILIM + 2
       GO TO 4022
C
C...     2ND PARAMETER OF INPUT WAS NOT A VECTOR - MUST THEN BE
C...     LINEAR PATTERN, OR ERROR
 4008       IF(NMSRF2.NE.3018) GO TO 800
       DEFANS(1) = DEFTAB(ILIM+3)
            IF(KDFANS(1).NE.1) GO TO 801
C
       FILDAT = DEFTAB(ILIM+1)
C...     TEST FOR SUFFICIENT ROOM IN WORKING STORAGE FOR 2ND PATTERN
            IF(JJ.GT.999-AEXTRA(DEFTAB(ILIM+2),4)) GO TO 802
C...     YES - SET ILIM DOWN TO MAKE ROOM FOR PATTERN
       ILIM = 1003 - AEXTRA(DEFTAB(ILIM+2),4)
C...     LOCATE PATTERN DEFINITION ON LARGE SURFACE FILE
       CALL ASERCH(SRFTAP,IRECNO,IOFLAG)
C...     TEST FOR ERROR IN FILE SEARCH OPERATION
            IF(IOFLAG.GE.0) GO TO 5200
C...     READ IN PATTERN DEFINITION
       CALL ATAPRD(SRFTAP,IOFLAG,JTEMP1,3,IDFSTO(1),3,DEFSTO(10),2
     1, DEFTAB(ILIM-3),0)
C...     TEST FOR ERROR WHEN READING IN PATTERN
            IF(IOFLAG.GE.0) GO TO 5210
C...     SET FLAG TO INDICATE SPACING OF COLUMNS BEING OBTAINED
C...     FROM A LINEAR PATTERN
       VX = DEFTAB(ILIM-3)
       VY = DEFTAB(ILIM-2)
       VZ = DEFTAB(ILIM-1)
       ISPCOL = 1
C
C...     SET COUNTER TO DEVELOP ONE COLUMN AT A TIME
 4012  NOCOLS = 1
C...     NOT FINISHED YET - COMPUTE NEXT INCREMENT
       XINCR = DEFTAB(ILIM) - VX
       YINCR = DEFTAB(ILIM+1) - VY
       ZINCR = DEFTAB(ILIM+2) - VZ
       VX = DEFTAB(ILIM)
       VY = DEFTAB(ILIM+1)
       VZ = DEFTAB(ILIM+2)
C...     INCREMENT PICK-UP INDEX TO NEXT POINT
       ILIM = ILIM + 3
       GO TO 4018
C
C...     COMPUTE NEXT INCREMENT FROM INPUT VECTOR AND DISTANCE
C         DEFTAB(I) IS THE DESIRED SPACING
 4022  XINCR = DEFTAB(ILIM)*VX/DIST
       YINCR = DEFTAB(ILIM)*VY/DIST
       ZINCR = DEFTAB(ILIM)*VZ/DIST
       ILIM = ILIM + 1
C
C...     INCREMENT NUMBER OF COLUMNS FOR PARLEL PATTERN
 4018  NOPT2 = NOPT2 + NOCOLS
C
 4040  DO 4024  M = 1,NOCOLS
      KK =JJ - K1
      DO 4023 L=1,NOROWS
C...     TEST FOR OVERFLOW OF DEFANS AREA
            IF(JJ+2.GE.ILIM) GO TO 802
C...     NO - COMPUTE NEXT POINT
       DEFTAB(JJ) = DEFTAB(KK-2) + XINCR
       DEFTAB(JJ+1) = DEFTAB(KK-1) + YINCR
       DEFTAB(JJ+2) = DEFTAB(KK) + ZINCR
      JJ = JJ + K3
 4023 KK = KK - K3
 4024 CONTINUE
C
C...     TEST FOR END OF STATEMENT
            IF(ILIM.GT.999) GO TO 4030
C
C...     NO - BRANCH ON ISPCOL SETTING TO OBTAIN POSITION OF NEXT COL.
            IF(ISPCOL)  4030, 4020, 4012
C
C...     NOPT2 IS TOTAL NUMBER OF COLUMNS IN A PARLEL PATTERN (USED
C...     IN POINT EXTRACTION)
 4030  KDFANS(9) = 4
       KDFANS(11) = JJ - 1
       KDFANS(12) = NOPT2
C...     SET IL TO LENGTH OF CANONICAL FORM
       IL = JJ - 1
C
C...     PUT LENGTH OF PATTERN INTO CANON RECORD, AND WRITE DATA
C...     ONTO LARGE SURFACE FILE
 5000  IDFTAB(2) = IL
       IL = 6
C
            IF(KDBUG.EQ.0) GO TO 5100
       WRITE (IOUTAP,5010) IL,DEFANS(1),DEFANS(2),DEFANS(3)
 5010  FORMAT (9H0  PATGEN,I8,3Z20//)
C
 5100  RETURN
C
C...     ERROR IN SEARCH OF LARGE SURFACE FILE FOR PATTERN
 5200  JSUBER = 840
       GO TO 5100
C...     ERROR IN READING OF PATTERN FROM LARGE SURFACE FILE
 5210  JSUBER = 841
       GO TO 5100
C
       END

