       SUBROUTINE ARGLST
C
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
C
       IMPLICIT REAL*8(A-H,O-Z)
       REAL*8 PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,
     1 TAPES1,TAPES2,TAPES3,TAPES4,PPNAME
       INTEGER PUNTAP
       COMMON/AVST/VST(7200)
       COMMON/ADFSTO/DEFSTO(85),PARTNO(11)
       COMMON/A1COM/REFSYS,NAME,NAME1,JSUBER,JSV,NAMSUB,
     1 KDBUG,INDXPT,LOOP,IFINI
       COMMON/A1PAS2/I,J,K,L,MOVLGE,KANMAX,ICANST,IOVREC,KANPTR,
     1 MDFTAB,KANCNT,KAUX,KDFCNT,IDEFP,KPRCNT,MDFPRE,IPREP,KOVFLP,
     2 KSRFCT,KOVCNT,LSCAN,IOVFLO,MAXCAN,IREF,ICANSC,NAMSTA,KANGO,
     3 LASPTP,ISUB,LCOMP,LGEREC,IRECN,JREC,JNUM,KANCUR,KANCOT,
     4 KDFENT,KANPAR,LGELOC,IDTMOV,ISPPRG,INDEXS,KPTP,KPTPCT,
     5 KLASTP,KLASCT,KPRNT
      COMMON/ASCALR/SCALR(180),ISCWS,NSURF,LOCTEM,IARGTP
       COMMON/ATAPTB/PROTAP,CANTAP,CLTAPE,POCTAP,PLOTAP,SRFTAP,
     1 TAPES1,TAPES2,TAPES3,TAPES4,INTAPE,IOUTAP,PUNTAP
       DIMENSION CANON(7200),ICANON(14400),IPTPP(14400)
       DIMENSION DEFANS(82),IDFSTO(170)
       DIMENSION DEFTAB(1000),IDFTAB(2000)
       EQUIVALENCE (VST(1),CANON(1),ICANON(1),IPTPP(1))
       EQUIVALENCE(VST(7200),DEFTAB(1000))
       EQUIVALENCE (DEFTAB(1),IDFTAB(1))
       EQUIVALENCE (DEFSTO(1),IDFSTO(1)),(DEFSTO(4),DEFANS(1))
       EQUIVALENCE (IDFSTO(2),LENGTH)
       EQUIVALENCE (IDFSTO(8),KRESLT)
C
C...     COMPUTE LIMIT INDEX FOR SCAN OF THIS LIST
       IPTLIM = INDEXS + KLASCT
C...     SAVE INDEX TO LOCATION IN CANON FOR STORAGE OF POINTER
C...     TO 'CANONICAL FORM' OF THIS ARGUMENT LIST
       KINDXP = 2*INDXPT - 1
       NSTANS = 2*(IPTPP(KINDXP)+ICANST-1) - 1
C...     MOVE PICK-UP INDEX TO FIRST ENTRY TO BE IDENTIFIED
       INDXPT = INDXPT + 1
C
C...     INITIALIZE STORING INDEX AND ARGUMENT COUNT
       JTEMP1 = 1
       NUMARG = 0
C...     CLEAR LIST TYPE
       JTEMP2 = 0
C...     CLEAR SPECIAL FORMAT FLAG
       JTEMP3 = 0
C
C...     SET FLAG TO OBTAIN ONLY CANON BLOCK FOR LARGE SURFACES
C...     AND PATTERNS
       IDTMOV = 1
C...     IDENTIFY NEXT ARGUMENT, AND INCREMENT COUNT
   50  CALL AGTARG(DEFANS(1),10,IPTYPE)
       NUMARG = NUMARG + 1
C
C...     IF SPECIAL FORMAT FLAG SET, BRANCH TO SPECIAL TESTS
   60       IF(JTEMP3.NE.0) GO TO 200
C
C...     TEST FOR VOCABULARY
            IF(IPTYPE.EQ.5) GO TO 120
C
C...     ONLY OTHER ACCEPTABLE ENTRIES ARE SCALAR OR SURFACE
            IF(IPTYPE-3)  70, 65, 500
C
C...     UNDEFINED SYMBOL - ERROR
   65  JSUBER = 101
       GO TO 500
C
C...     DETERMINE WHETHER ENTRY IS SCALAR OR SURFACE
   70       IF(IPTYPE.EQ.2) GO TO 80
C
C...     SCALAR - ADD TO DATA BLOCK IN DEFTAB
   75  DEFTAB(JTEMP1) = DEFANS(1)
       GO TO 90
C
C...     SURFACE - STACK IN DEFTAB - STORE SURFACE TYPE CODE FIRST
   80  JTEMP4 = 2*JTEMP1 - 1
       IDFTAB(JTEMP4) = 0
       IDFTAB(JTEMP4+1) = IDFSTO(1)
C...     ADD SURFACE DATA TO BLOCK IN DEFTAB
       DO 85  J = 4,LENGTH
       JTEMP1 = JTEMP1 + 1
   85  DEFTAB(JTEMP1) = DEFANS(J-3)
C
C...     IF THIS IS FIRST ARGUMENT, SET LIST TYPE TO ITS TYPE
   90       IF(JTEMP2.NE.0) GO TO 95
       JTEMP2 = IPTYPE
       GO TO 100
C
C...     NOT FIRST ARGUMENT - SEE WHETHER OR NOT TYPE OF THIS ONE
C...     AGREES WITH THAT OF LIST SO FAR
   95       IF(IPTYPE.EQ.JTEMP2) GO TO 100
C
C...     TYPES DO NOT MATCH - MAKE LIST TYPE UNDEFINED
       JTEMP2 = 3
C
C...     INCREMENT STORING INDEX
  100  JTEMP1 = JTEMP1 + 1
C
C...     IF NOT END OF LIST, RETURN FOR NEXT ARGUMENT
  110       IF(IPTLIM-INDXPT)  400, 50, 50
C
C...     ARGUMENT IS VOCABULARY
C
C...     SEE WHETHER OR NOT MODIFIER IS 'THRU' OR 'ALL', INDICATING
C...     INCLUSIVE SUBSCRIPT
  120       IF(KRESLT.EQ.152) GO TO 140
C...     TEST FOR 'ALL'
  125       IF(KRESLT.EQ.51) GO TO 150
C
C...     INCORRECT FORMAT - ERROR
  130  JSUBER = 274
       GO TO 500
C
C...     'THRU' FOUND - SHOULD BE FIRST ARGUMENT, OR ONLY ONE SCALAR
C...     SO FAR - TEST COUNT, AND LIST TYPE CODE IF NECESSARY
  140       IF(JTEMP1-2)  142, 145, 130
C...     FIRST ARGUMENT - SET UP IMPLIED LOWEST VALUE OF ONE
  142  DEFTAB(1) = 1.0
       JTEMP1 = 2
       GO TO 160
C...     SECOND ARGUMENT - CHECK LIST TYPE CODE FOR SCALAR
  145       IF(JTEMP2-1)  130, 160, 130
C
C...     'ALL' FOUND - IF FIRST ARGUMENT, SET UP LOWEST SUBSCRIPT VALUE
  150       IF(JTEMP1-2)  152, 155, 130
  152  DEFTAB(1) = 1.0
C...     INDICATE HIGHEST SUBSCRIPT VALUE TO BE ARRAY SIZE
  155  DEFTAB(2) = 0.0
C...     SET STORING INDEX
       JTEMP1 = 3
C
C...     SET INCLUSIVE SUBSCRIPT LIST TYPE, AND CLEAR
C...     SUBSCRIPT INCREMENT FLAG
  160  JTEMP2 = 4
       JTEMP4 = 0
C...     SET SPECIAL FORMAT FLAG, AND RETURN FOR NEXT ARGUMENT
       JTEMP3 = 1
       GO TO 110
C
C...     SPECIAL FORMAT - ONLY ONE NOW IS INCLUSIVE SUBSCRIPT NEST
C...     DETERMINE TYPE OF INPUT ARGUMENT
  200       IF(IPTYPE.EQ.1) GO TO 240
C...     NOT SCALAR - ONLY OTHER ACCEPTABLE ENTRY IS VOCABULARY
            IF(IPTYPE.NE.5) GO TO 130
C
C...     MODIFIER FOUND - BRANCH TO TESTS FOR 'ALL' AND 'INCR'
C...     OR 'DECR' ON NUMBER COUNT
            IF(JTEMP1-3)  125, 225, 130
C
C...     TWO NUMBERS ALREADY IN LIST - TEST FOR 'INCR' OR 'DECR'
  225       IF(KRESLT.NE.66) GO TO 230
C...     'INCR' FOUND - SET FLAG TO ACCEPT SUBSCRIPT INCREMENT
       JTEMP4 = 1
       GO TO 110
C...     NOT 'INCR' - TRY 'DECR'
  230       IF(KRESLT.NE.65) GO TO 130
C...     YES - SET FLAG TO ACCEPT AND CHANGE SIGN OF SUBSCR. INCREMENT
       JTEMP4 = -1
       GO TO 110
C
C...     SCALAR FOUND - MUST ALREADY HAVE ONE OR TWO ENTRIES
  240       IF(JTEMP1-3)  255, 245, 130
C
C...     TWO ENTRIES - SEE IF SUBSCRIPT INCREMENT ACCEPTABLE
  245       IF(JTEMP4)  250, 130, 255
C...     INCREMENT IS A DECREMENT - CHANGE SIGN
  250  DEFANS(1) = -DEFANS(1)
C
C...     ADD SCALAR INPUT TO INCLUSIVE SUBSCRIPT LIST
  255  DEFTAB(JTEMP1) = DEFANS(1)
       GO TO 100
C
C...     END OF PARAMETER LIST...
C...     BRANCH ON LIST TYPE FOR ANY SPECIAL PROCESSING
  400       IF(JTEMP2-4)  450, 430, 130
C
C...     TEST FOR ADEQUATE ENTRIES FOR INCLUSIVE SUBSCRIPT
  430       IF(JTEMP1-4)  432, 440, 436
  432       IF(JTEMP1-3)  436, 434, 440
  434       IF(JTEMP4.EQ.0) GO TO 438
  436  JSUBER = 275
       GO TO 500
C
C...     LIMITS ONLY GIVEN - ADD IMPLIED INCREMENT TO DATA BLOCK
  438  DEFTAB(JTEMP1) = 1.0
C
C...     CONVERT TO FIXED POINT FROM FLOATING POINT INPUT
  440  DO 442  J = 1,3
  442  IDFTAB(J) = DEFTAB(J)
       JTEMP1 = 3
C
C
C...     TEST FOR SUFFICIENT SPACE FOR THIS DATA BLOCK IN STORAGE AREA
  450       IF(LOCTEM+JTEMP1.LE.ICANST+50) GO TO 455
C...     THERE IS NOT SPACE - ERROR
       JSUBER = 272
       GO TO 500
C
C...     PUT INDEX TO LOCATION OF DATA BLOCK, AND TYPE OF ARGUMENT
C...     LIST, INTO REFERENCE WORD AT START OF CANON
  455  ICANON(NSTANS) = LOCTEM
       ICANON(NSTANS+1) = JTEMP2
C...     PUT LENGTH OF DATA, AND NUMBER OF ARGUMENTS, INTO FIRST
C...     WORD OF DATA BLOCK
       JTEMP4 = 2*LOCTEM - 1
       ICANON(JTEMP4) = JTEMP1
       ICANON(JTEMP4+1) = NUMARG
       LOCTEM = LOCTEM + 1
C
C...     MOVE SCALAR OR SURFACE STACK TO STORAGE AREA
       DO 460  J = 2,JTEMP1
       CANON(LOCTEM) = DEFTAB(J-1)
  460  LOCTEM = LOCTEM + 1
C
  470       IF(KDBUG.EQ.0) GO TO 490
       JTEMP4 = ICANON(NSTANS)
       WRITE (IOUTAP,480) IPTPP(KINDXP),NSTANS,ICANON(NSTANS)
     1 ,ICANON(NSTANS+1),(CANON(J),J=JTEMP4,LOCTEM)
  480  FORMAT (9H0  ARGLST,4Z12/1H ,(6X,5Z20/1H ))
C
  490  RETURN
C
  500  ICANON(NSTANS+1) = 9
       ICANON(NSTANS) = 0
       GO TO 490
       END

