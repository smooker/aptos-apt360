      SUBROUTINE ASEQAL
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C     THIS ROUTINE PROCESSES PTPP CLASS 9 DATA(OBTAIN,SURFACE TYPE/S1,X,
C     Y,...)
C     THIS ROUTINE MAY SET JSUBER TO 152, 153, 154, OR 157
C
      IMPLICIT REAL*8(A-H,O-Z)
       INTEGER IERR(2)/0,9/
       DIMENSION DEFANS(82)
       DIMENSION PTPP(7200),CANON(7200)
       DIMENSION IDFSTO(164),IPTPP(14400)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/AVST/VST(7200)
      EQUIVALENCE(VST(1),PTPP(1),CANON(1))
       EQUIVALENCE (ERRCOD,IERR(1))
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
       EQUIVALENCE (DEFSTO(1),IDFSTO(1)),(PTPP(1),IPTPP(1))
C
C     GET SUBSCRIPT TYPE OF SCALAR VARIABLE BEING DEFINED
       KINDXP = 2*INDXPT - 1
       NAMSUB = IPTPP(KINDXP+1)
       INDXPT = INDXPT + 1
C     GET VST INDEX OF SCALAR VARIABLE
       I1 = IPTPP(KINDXP+3)
C     GET SUBSCRIPT
      CALL AGTSUB
C     CHECK FOR ERROR IN SUBSCRIPT DEFINITION.
      IF(JSUBER.NE.0) RETURN
      J1=NAMSUB
C
C     GET SURFACE TYPE GIVEN IN OBTAIN STATEMENT
       KINDXP = 2*INDXPT - 1
       IT = IPTPP(KINDXP)
C...     TEST FOR A LARGE SURFACE - IF SO, ERROR AT PRESENT
            IF(IT.GT.15) GO TO 60
C     GET RELATIVE INDEX OF PARAMETER WHICH DEFINES SCALAR VARIABLE
       KCP = IPTPP(KINDXP+1)
       INDXPT = INDXPT + 1
C     GET CANONICAL FORM OF REQUESTED SURFACE
       CALL AGTARG(DEFANS,82,N)
C...     IF ERROR ALREADY DIAGNOSED IN AGTARG, GO TO SET UP ERROR
C...     CODE FOR SYMBOL VST ENTRY
            IF(N.EQ.7) GO TO 70
C...     SEE IF S1 IS A SURFACE
            IF(N.NE.2) GO TO 30
C     S1 IS A SURFACE - DO SURFACE TYPES MATCH.
   10       IF(IDFSTO(1).NE.IT) GO TO 40
C     THE SURFACE TYPE IS CORRECT
C
C     IS PARAMETER INDEX WITHIN CANONICAL FORM LENGTH
            IF(KCP.GT.IDFSTO(2)) GO TO 50
C
C     RESTORE VST INDEX AND SUBSCRIPT OF SCALAR BEING DEFINED
   20  NAMSUB = J1
      NAME=I1
C     STORE THE SCALAR VARIABLE
      CALL ASCLPT(DEFSTO(KCP))
      RETURN
C
C     VARIABLE DOES NOT DEFINE A SURFACE
 30   JSUBER=152
       GO TO 70
C     SURFACE TYPES DO NOT MATCH
 40   JSUBER=153
       GO TO 70
C     PARAMETERS EXCEED LENGTH OF CANONICAL FORM
 50   JSUBER=154
       GO TO 70
C...     SURFACE IS A LARGE ONE
   60  JSUBER = 157
C
C...     SET UP ERROR CODE TO MAKE ASCLPT FLAG VST ENTRY FOR SYMBOL
C...     AS INCORRECTLY DEFINED
   70  KCP = 1
       DEFSTO(1) = ERRCOD
       GO TO 20
       END

