      SUBROUTINE ACLAS5
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
C
C
C...  PASS TWO PROGRAM FOR PUNCH, PRINT, TITLES
C
      IMPLICIT REAL*8(A-H,O-Z)
       INTEGER*2 KNCLUS,KARGPN,KARG(2)
       DIMENSION PTPP(7200)
       DIMENSION IDFSTO(170),IDFTAB(2000)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
       REAL*8 PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,TAPES1,TAPES2,
     1 TAPES3,TAPES4,PPNAME
       INTEGER PUNTAP
       COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,
     1 TAPES1,TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
      COMMON/AMXTAB/MAXTAB,MAXVS1,MAXVS2,MAXPTP,MAXSCL,MAXVS,
     1MAXVST,MXPTPP,MXCAN,MXSRCN,MAXSLR,MAXELM,MAXPOT
      COMMON/ASCALR/SCALR(180),ISCWS,NSURF,LOCTEM,IARGTP
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
       DIMENSION IVST(14400),IPTPP(14400)
      EQUIVALENCE(VST(1),PTPP(1))
       EQUIVALENCE (VST(1),IVST(1)),(PTPP(1),IPTPP(1))
      EQUIVALENCE(VST(7200),DEFTAB(1000))
       EQUIVALENCE (IARGTP,KNCLUS,KARG(1)),(KARGPN,KARG(2))
      COMMON/A2CLS7/PPSEQ1,PPSEQ2,ENAME,EINAME,IEREC,ISN
      COMMON/A1PAS2/I,J,K,L,MOVLGE,KANMAX,ICANST,IOVREC,KANPTR,MDFTAB,
     1KANCNT,KAUX,KDFCNT,IDEFP,KPRCNT,MDFPRE,IPREP,KOVFLP,KSRFCT,KOVCNT,
     2LSCAN,IOVFLO,MAXCAN,IREF,ICANSC,NAMSTA,KANGO,LASPTP,ISUB,
     3LCOMP,LGEREC,IRECN,JREC,JNUM,KANCUR,KANCOT,KDFENT,KANPAR,LGELOC,
     4IDTMOV,ISPPRG,INDEXS,KPTP,KPTPCT,KLASTP,KLASCT,KPRNT
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
       COMMON/APROTP/PROTP(102),PROSAV(102),NOWCLT,LSTPSV,INCORE
     1 ,JGORIT,SAVMOT
       EQUIVALENCE (DEFSTO(1),IDFSTO(1)),(DEFTAB(1),IDFTAB(1))
C
      COMMON/A1STAB/STABLE(23)
C
C
       DATA RIGHT,SCALAR/8H RIGHT  ,8HSCALAR  /
      DATA BLANK/8H        /
      DATA ENDPCH,ENDSEQ/'(ENDPCH)',ZFFFFFFFFFFFFFFFF/
C
      IDEFP=4
      JSV=0
       KINDXP = 2*INDXPT - 1
       MM = IPTPP(KINDXP) - 1
       NN = IPTPP(KINDXP+1)
       INDXPT = INDXPT + 1
      GO TO (100,101,300),NN
C     PRINT/ - SET IDTMOV TO PRECLUDE FETCHING LARGE SURFACE
  100 IDTMOV=1
      GO TO 102
C     PUNCH/ - SET IDTMOV TO FETCH LARGE SURFACE
  101 IDTMOV=0
C     GET PRINTED OUTPUT FORMAT TYPE
  102  CALL AGTARG(TYPE,1,KRET)
            IF(KRET.NE.1) GO TO 140
      ITYPE=TYPE
      GOTO(170,150,160,155),ITYPE
C     PRINT/0
 110  WRITE(IOUTAP,120)
  120 FORMAT(1H1,60X)
      GOTO 900
C     PRINT/1
  130 IF(IL.EQ.5)GO TO 132
      IL=IL-1
      WRITE(IOUTAP,131) (DEFSTO(I),I=1,IL)
  131 FORMAT(7Z17)
      GO TO 199
  132 WRITE(IOUTAP,131) DEFTAB(5)
      GO TO 199
C     FORMAT ERROR IN PRINT/ OR PUNCH/
 140  JSUBER=2000
      GOTO 900
C     PRINT/2
  150  IDFLG = 0
      GO TO 170
C     PRINT/4 - SET IDTMOV TO FETCH LARGE SURFACE
  155 IDTMOV=0
C     PRINT/3
  160  IDFLG = 1
C     CHECK FOR ALL MODIFIER
  170  KINDXP = 2*INDXPT - 1
            IF(IPTPP(KINDXP).NE.6) GO TO 171
       INDXPT = INDXPT + 1
            IF(IPTPP(KINDXP+3).NE.51) GO TO 140
       INDXPT = INDXPT - 2
       GO TO 180
C
  171  KALL = 0
 1171  KINDXP = 2*INDXPT - 1
       I = IPTPP(KINDXP)
      IF(I .NE. 2) GO TO 172
       I = 2*IPTPP(KINDXP+3) - 1
            IF(IVST(I+2).NE.8) GO TO 172
      INDXPT = INDXPT + 2
      GO TO 195
C
  172 IF(NN.EQ.2)GO TO 200
       KNCLUS = 1
  173  NSURF = 1
       CALL AGTARG(DEFTAB(5),1000,KRET)
            IF(KRET.EQ.8) GO TO 193
            IF(KRET.GT.3) GO TO 199
       IL = IDFSTO(2) + 1
      IF(KRET.EQ.1)IL=5
      IC=IL-4
      IF(ITYPE.EQ.1)GO TO 130
      IF(IDFLG.NE.0) GOTO 196
  191 WRITE(IOUTAP,192)(DEFTAB(I),I=5,IL)
 192  FORMAT(24X7F13.6)
      GOTO 199
  196       IF(KRET.EQ.2) GO TO 1196
      STYPE=SCALAR
      GOTO 197
 1196 IF(IL.EQ.6)GO TO 199
       KTYPE = IDFSTO(1)
      STYPE=STABLE(KTYPE)
  197 WRITE(IOUTAP,198)ENAME,NAMSUB,STYPE,IC,(DEFTAB(I),I=5,IL)
 198  FORMAT(1H A8,1H(I4,1H)2X,A6,I3,7F13.6/(24X7F13.6))
  199 IF(ITYPE.EQ.4)GO TO 230
 1991 IF(KALL.NE.0)GO TO 185
            IF(KNCLUS.EQ.2) GO TO 173
      MM=MM-1
      IF(MM.EQ.0)GO TO 189
      GO TO 1171
 193  WRITE(IOUTAP,194) ENAME,NAMSUB
 194  FORMAT(1H A8,1H(I4,')  SYMBOL DEFINED INCORRECTLY OR REFERENCED PR
     1IOR TO DEFINITION  '          )
 195  JSUBER = 0
      GO TO 1991
C
  180  KALL = 1
      SAVE1=PTPP(INDXPT)
      SAVE2=PTPP(INDXPT+1)
      SAVE3=PTPP(INDXPT+2)
       IVSTCT = 2
       ISUBCT = 0
       INDXST = INDXPT
C
  181  IVSTCT = IVSTCT + 2
            IF(IVSTCT.GT.MAXVS1) GO TO 187
            IF(VST(IVSTCT).GE.0.0D0) GO TO 183
       JTEMP1 = 2*IVSTCT - 1
       ISUBCT = IABS(IVST(JTEMP1+1))
       ISUB = 1
  182  NAME = IVSTCT - 1
      NAMSUB=ISUB
      ENAME=VST(NAME)
      CALL AVS2CK(J)
      IF(J .EQ. 7) GO TO 195
            IF(J.GT.6) GO TO 193
C     IS THIS A STATEMENT ID
            IF(J.EQ.3) GO TO 181
            IF(J.NE.2) J = 4
       KINDXP = 2*INDXPT - 1
       IPTPP(KINDXP) = J
       IPTPP(KINDXP+1) = 1
       IPTPP(KINDXP+2) = 0
       IPTPP(KINDXP+3) = IVSTCT - 1
      ADUM = ISUB
      PTPP(INDXPT+2)=ADUM
      GOTO 172
C
  183  NAME = IVSTCT - 1
      NAMSUB=0
      ENAME=VST(NAME)
      CALL AVS2CK(J)
      IF(J .EQ. 7) GO TO 195
            IF(J.GT.6) GO TO 193
C     IS THIS A STATEMENT ID
            IF(J.EQ.3) GO TO 186
            IF(J.NE.2) J = 4
       KINDXP = 2*INDXPT - 1
       IPTPP(KINDXP) = J
       IPTPP(KINDXP+1) = 0
       IPTPP(KINDXP+2) = 0
       IPTPP(KINDXP+3) = IVSTCT - 1
      GOTO 172
C
 185  INDXPT=INDXST
            IF(ISUBCT.EQ.0) GO TO 181
       ISUB = ISUB + 1
            IF(ISUB.GT.ISUBCT) GO TO 181
      GOTO 182
C
 186  WRITE(IOUTAP,188) ENAME,NAMSUB
 188  FORMAT(1H A8,1H(I4,18H)  STATEMENT I.D.     )
C
  187  PTPP(INDXST) = SAVE1
      PTPP(INDXST+1)=SAVE2
      PTPP(INDXST+2)=SAVE3
C     CHECK FOR PUNCH/N,ALL OR PRINT/4
  189 IF(NN.EQ.2.OR.ITYPE.EQ.4) GO TO 245
      GO TO 900
C
C     PUNCH/1
  200 II=1
  205  KINDXP = 2*INDXPT - 1
       J1 = IPTPP(KINDXP)
            IF(J1.EQ.4) GO TO 210
            IF(J1.EQ.2) GO TO 210
C     UNNAMED PARAMETER
      JSUBER=2005
      ENAME=0.0D0
      GOTO 220
C
  210  KNCLUS = 1
  212  CALL AGTARG(DEFTAB(5),1000,KRET)
            IF(KRET.LT.3) GO TO 230
C     OUTPUT ERROR DIAGNOSTIC FOR THIS PARAMETER
      JSUBER=101
  220  JSV = 1
      CALL ADIAGM
      GOTO 240
C
 230  DEFTAB(1)=ENAME
      ADUM = NAMSUB
      DEFTAB(2) = ADUM
C     CHECK FOR SCALAR BEING OUTPUT
      IF(KRET.NE.1)GO TO 2301
C     YES - SHOULD IT BE OUTPUT
      IF(ITYPE.EQ.3)              GO TO 240
C     YES - SET LENGTH
       IDFSTO(1) = 0
       IDFSTO(2) = 4
       GO TO 2302
C...     SHOULD WE OUTPUT SURFACES
 2301       IF(ITYPE.EQ.2) GO TO 240
 2302  DEFTAB(3) = DEFSTO(1)
      DEFTAB(4) = 0.0D0
       IL = IDFSTO(2) + 1
C     CHECK FOR LARGE SURFACE
      IF(IL.NE.6) GOTO 231
C     LARGE SURFACE - SET LENGTH
      DEFTAB(4)=DEFSTO(5)
       IL = IDFTAB(8) + 4
 231  IS=1
      IC=0
 232  IE=IS+8
      IF(IE.GT.IL)GOTO 236
 233  WRITE(PUNTAP,234) (DEFTAB(J),J=IS,IE),ENAME,IC
 234  FORMAT(9A8,A6,I2)
      IF(IE.GE.IL) GOTO 240
      IC=IC+1
      IS=IS+9
      GOTO 232
 236  IL1=IL+1
      DO 238 JJ=IL1,IE
 238  DEFTAB(JJ)=BLANK
      GOTO 233
  240       IF(ITYPE.EQ.4) GO TO 1991
            IF(KNCLUS.EQ.2) GO TO 212
      II=II+1
      IF(II.LE.MM)GO TO 205
C     CHECK FOR ALL MODIFIER
      IF(KALL.EQ.1)GO TO 185
C     OUTPUT END OF PUNCH DATA CARD
  245 WRITE(PUNTAP,250) ENDPCH,ENDSEQ
 250  FORMAT(A8,64X,A8)
      GOTO 900
C     TITLES
  300  J1 = INDXPT + 1
      IF(PTPP(J1).NE.RIGHT) GOTO 320
       J1 = J1 + 2
       J2 = 10
  305  DO 310  I = 1,J2
      PROTP(I)=PTPP(J1)
  310  J1 = J1 + 2
            IF(J2.NE.10) GO TO 330
       WRITE (IOUTAP,315) (PROTP(J1),J1=1,J2)
  315 FORMAT (1H+66X10A6)
      GO TO 900
  320  J2 = 11
      GOTO 305
  330  WRITE (IOUTAP,335) (PROTP(J1),J1=1,J2)
 335  FORMAT (1H 11A6)
  900 RETURN
      END

