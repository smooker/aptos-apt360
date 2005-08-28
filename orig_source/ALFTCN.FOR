      FUNCTION ALFTCN(M)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C
C...  LOFT CONIC ROUTINE FOR DEFPRE
C...  UPON ENTERING THIS ROUTINE THE ACCUMULATOR WILL CONTAIN A FIXED
C...  POINT NUMBER - 1,2,3,4,5 OR 6.
C
C...  WHEN ACC. = 1,
C...  LC = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5  $$
C
C...  WHEN ACC. = 2
C...  LC = LCONIC/5PT,SYM PT1,SYM PT2,SYM PT3,SYM PT4,SYM PT5 $$
C
C...  WHEN ACC. = 3
C...  LC = LCONIC/4PT1SL,X1,Y1,SLOPE VALUE,X2,Y2,X3,Y3,X4,Y4 $$
C
C...  WHEN ACC. = 4
C...  LC = LCONIC/4PT1SL,SYM PT1,SLOPE VALUE,SYM PT2,SYM PT3,SYM PT4 $$
C
C...  WHEN ACC. = 5
C...  LC = LCONIC/3PT2SL,X1,Y1,SLOPE 1,X2,Y2,SLOPE 2,X3,Y3 $$
C
C...  WHEN ACC. = 6
C...  LC = LCONIC/3PT2SL,SYM PT1,SLOPE 1,SYM PT2,SLOPE 2,SYM PT3 $$
C
      IMPLICIT REAL*8(A-H,O-Z)
       DIMENSION DEFANS(82)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,KDBUG,INDXPT,
     1 LOOP,IFINI
      COMMON/AVST/VST(7200)
      DIMENSION DEFTAB(1000)
       DIMENSION IDFTAB(2000)
      EQUIVALENCE(VST(7200),DEFTAB(1000))
       EQUIVALENCE (DEFTAB(1),IDFTAB(1))
      COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
      EQUIVALENCE(DEFSTO(4),DEFANS(1))
C***********************************************************************
      EQUIVALENCE (DEFTAB(30),X1),(DEFTAB(31),Y1),(DEFTAB(32),X2),
     1(DEFTAB(33),Y2),(DEFTAB(34),X3),(DEFTAB(35),Y3),(DEFTAB(36),X4),
     2(DEFTAB(37),Y4),(DEFTAB(38),X5),(DEFTAB(39),Y5),(DEFTAB(40),S1),
     3(DEFTAB(41),S2),(DEFTAB(42),S3),(DEFTAB(43),S4),(DEFTAB(44),A1),
     4(DEFTAB(45),A2),(DEFTAB(46),A3),(DEFTAB(47),A4),(DEFTAB(48),B1),
     5(DEFTAB(49),B2),(DEFTAB(50),B3),(DEFTAB(51),B4),(DEFTAB(52),C1),
     6(DEFTAB(53),C2),(DEFTAB(54),CC3),(DEFTAB(55),C4),(DEFTAB(56),ES),
     7(DEFTAB(57),R),               (DEFTAB(59),ISLOPE),(DEFTAB(60),J)
      DIMENSION  LEN(6)
      EQUIVALENCE (DEFTAB(80),LEN(1))
      LEN(1) = 12
      LEN(2) = 22
      LEN(3) = 11
      LEN(4) = 19
      LEN(5) = 10
      LEN(6) = 16
  300 CALL DVCHK (K000FX)
       GO TO(301,301),K000FX
  301       IF(IDFTAB(2)-LEN(M))  97, 302, 97
  302 GO TO (303,312,305,306,307,308), M
  303 DO 309 K = 3,12
  309 DEFTAB(K+27) = DEFTAB(K)
      GO TO 321
  312 J = 29
      DO 313 K=3,19,4
      DO 313 I= 1,2
      L = K+I
      J = J+1
  313 DEFTAB(J) = DEFTAB(L)
  321 ISLOPE = 0
      GO TO 310
  305 J = 29
      DO 314 K= 1,2
      DO 314 L= 3,4
      J = J+1
  314 DEFTAB(J) = DEFTAB(L)
      DO 315 K = 6,11
  315 DEFTAB(K+28) = DEFTAB(K)
      DEFTAB(40) = DEFTAB(5)
      GO TO 320
  306 J = 29
      DO 318 K = 1,2
      DO 318 I = 4,5
      J = J+1
  318 DEFTAB(J) = DEFTAB(I)
      J = 33
      DO 319 K = 8,16,4
      DO 319 I = 1,2
      J = J+1
      I1 = K+I
  319 DEFTAB(J) = DEFTAB(I1)
      DEFTAB(40) = DEFTAB(7)
  320 ISLOPE = 1
      GO TO 310
  307 J = 29
      DO 322 K = 1,2
      DO 322 I = 3,4
      J = J+1
  322 DEFTAB(J) = DEFTAB(I)
      DEFTAB(34)=DEFTAB(9)
      DEFTAB(35)=DEFTAB(10)
      J = 35
      DO 323 K = 1,2
      DO 323 I=6,7
      J = J+1
  323 DEFTAB(J) = DEFTAB(I)
      DEFTAB(40) = DEFTAB(5)
      DEFTAB(41) = DEFTAB(8)
      GO TO 324
  308 J = 29
      DO 326 K = 1,2
      DO 326 I = 4,5
      J = J+1
  326 DEFTAB(J) = DEFTAB(I)
      DEFTAB(34)=DEFTAB(14)
      DEFTAB(35)=DEFTAB(15)
      J = 35
      DO 327 K = 1,2
      DO 327 I=9,10
      J = J+1
  327 DEFTAB(J) = DEFTAB(I)
      DEFTAB(40) = DEFTAB(7)
      DEFTAB(41)=DEFTAB(12)
  324 ISLOPE = 2
  310 IF(ISLOPE - 1) 353,351,352
C
C...     5PT - CALCULATE ALL SLOPES
C
  353 S1 = (Y2 - Y1)/(X2 - X1)
      CALL DVCHK (K000FX)
       GO TO(328,351),K000FX
  328  S1 = ((Y2 - Y1)/DABS(Y2 - Y1))*100000.0
      CALL DVCHK (K000FX)
       GO TO(98,351),K000FX
C
C...     4PT1SL - CALCULATE 3 SLOPES
C
  351 S2 = (Y5 - Y4)/(X5 - X4)
      CALL DVCHK (K000FX)
       GO TO(329,352),K000FX
  329  S2 = ((Y5 - Y4)/DABS(Y5 - Y4))*100000.0
      CALL DVCHK (K000FX)
       GO TO(98,352),K000FX
C
C...     3PT2SL - CALCULATE 2 SLOPES
C
  352 S3 = (Y4 - Y1)/(X4 - X1)
      CALL DVCHK (K000FX)
       GO TO(330,331),K000FX
  330  S3 = ((Y4 - Y1)/DABS(Y4 - Y1))*100000.0
      CALL DVCHK (K000FX)
       GO TO(98,331),K000FX
  331 S4 = (Y5 - Y2)/(X5 - X2)
      CALL DVCHK (K000FX)
       GO TO(332,333),K000FX
  332  S4 = ((Y5 - Y2)/DABS(Y5 - Y2))*100000.0
      CALL DVCHK (K000FX)
       GO TO(98,333),K000FX
  333 ES = 1.0
            IF(DABS(S1) - 1.0)  335, 335, 334
  334  ES = DSQRT(S1**2 + 1.0)
  335 A1 = S1/ES
      B1 = -1.0/ES
            IF(DABS(B1) - .00002)  336, 337, 337
  336 B1 = 0.0
  337 C1 = -A1*X1 - B1*Y1
      ES = 1.0
            IF(DABS(S2) - 1.0)  339, 339, 338
  338  ES = DSQRT(S2**2 + 1.0)
  339 A2 = S2/ES
      B2 = -1.0/ES
            IF(DABS(B2) - .00002)  340, 341, 341
  340 B2 = 0.0
  341 C2 = -A2*X5 -  B2*Y5
      ES = 1.0
            IF(DABS(S3) - 1.0)  343, 343, 342
  342  ES = DSQRT(S3**2 + 1.0)
  343 A3 = S3/ES
      B3 = -1.0/ES
            IF(DABS(B3) - .00002)  344, 345, 345
  344 B3 = 0.0
  345 CC3 = -A3*X4 - B3*Y4
      ES= 1.0
            IF(DABS(S4) - 1.0)  347, 347, 346
  346  ES = DSQRT(S4**2 + 1.0)
  347 A4 = S4/ES
       B4=-1.0/ES
            IF(DABS(B4) - .00002)  348, 349, 349
  348 B4 = 0.0
  349 C4 = -A4*X2 - B4*Y2
      R = -((A1*X3 + B1*Y3 + C1)*(A2*X3 + B2*Y3 + C2))/((A3*X3 + B3*Y3
     1    + CC3)*(A4*X3 + B4*Y3 + C4))
      CALL DVCHK (K000FX)
       GO TO(98,3490),K000FX
 3490 IF(R) 350,98,350
C
C...  SET UP DATA FOR GCON01
C
  350 DEFTAB(2) = A1*A2 + R*A3*A4
      DEFTAB(3) = B1*A2 + B2*A1 + R*(B3*A4 + B4*A3)
      DEFTAB(4) = B1*B2 + R*B3*B4
      DEFTAB(5) = C1*A2 + C2*A1 + R*(CC3*A4 + C4*A3)
      DEFTAB(6) = C1*B2 + C2*B1 + R*(CC3*B4 + C4*B3)
      DEFTAB(7) = C1*C2 + R*CC3*C4
       CALL AGENCN(1)
      GO TO 40
   97  JSUBER = 1001
      GO TO 40
   98  JSUBER = 1005
   40 ALFTCN = ISLOPE
      RETURN
      END

