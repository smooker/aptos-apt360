/*

*  ASMBLR

*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***

SETMIN   START 0

*              SETMIN-CHKMIN PROGRAMS FOR SYSTEM/360 APT

*----------------------------------------------------------------------

*

* CALL SETMIN (N,A1,J1,A2,J2,.........AN,JN) WHERE

*        N IS THE NUMBER OF PAIRS A2,J2  N CANNOT BE GREATER THAN 20

*        A2 IS THE NAME OF ARRAY 2 IN WHICH ARE STORED BCD MINOR WORDS.

*        J2 IS THE NUMBER OF ELEMENTS STORED IN A2

*----------------------------------------------------------------------

* CALL CHKMIN (X,K,M) WHERE

*        X IS THE VARIABLE TO BE INTERROGATED (8 BYTES)

*        K IS THE RETURN CODE INDICATING WHAT X IS (4 BYTE INTEGER)

*        M IS THE M-TH ARRAY IN SETMIN WHICH X WILL BE COMPARED AGAINST

*              (4 BYTE INTEGER)

*----------------------------------------------------------------------

*

         ENTRY CHKMIN

         EXTRN A0CON

K0       EQU   A0CON

K1       EQU   A0CON+4

K2       EQU   A0CON+8

K3       EQU   A0CON+12

K4       EQU   A0CON+16

K5       EQU   A0CON+20

K6       EQU   A0CON+24

K7       EQU   A0CON+28

K8       EQU   A0CON+32

K9       EQU   A0CON+36

K10      EQU   A0CON+40

K11      EQU   A0CON+44

K12      EQU   A0CON+48

BASEREG1 EQU   12

CALLREG  EQU   11

CONSTREG EQU   10

ARGREG   EQU   3

         USING SETMIN,BASEREG1

         USING CALLLIST,CALLREG

         USING ARGUMENT,ARGREG

         USING A0CON,CONSTREG

BASE     SAVE  (2,12),T,SETMIN

         LR    BASEREG1,15

         LR    CALLREG,1

         L     CONSTREG,=V(A0CON)

         L     3,N

         L     3,VALUE

         C     3,=F'20'      COMPARING N TO THE MAXIMUM ALLOWED

         BH    ERR1

         ST    3,JX          STORING N VALUE FOR CHKMIN PROGRAM

         L     4,K0          REG 4 IS USED FOR PAIRS COUNTER

         LA    6,TABSET      TABSET IS AREA TO STORE PAIRS

         LA    8,A1          LOAD ADDR OF THE L(A1) INTO REG 8

LP1      L     5,0(0,8)      LOAD THE LOCATION OF AN INTO REG 5

         ST    5,0(0,6)      STORE THE LOCATION OF AN INTO TABSET

         L     7,4(0,8)      LOAD THE LOCATION OF JN INTO REG 7

         L     2,0(0,7)

         LPR   7,2

         ST    7,4(0,6)      STORE JN'S VALUE INTO THE BYTE AFTER AN

         A     4,K1          INCREMENT PAIR COUNTER BY 1

         C     4,JX          DO WE HAVE ALL PAIRS?

         BE    RET           YES

         A     8,K8          NO, BUMP TO GET NEXT PAIR OF ADCONS

         A     6,K8          BUMP TO GET NEXT 2 SPACES IN TABSET

         B     LP1

RET      RETURN (14,12),T

         CNOP 0,4

CHKMIN   SAVE  (2,12),T,CHKMIN

         L     BASEREG1,POINTER-CHKMIN(0,15)

         LR    CALLREG,1

         L     CONSTREG,=V(A0CON)

         L     4,K           K'S ADDRESS IN REG 4

         L     3,X

         MVC   XVALUE(8),VALUE

         CLC   XVALUE(4),K0

         BNE   C1

         CLC   XVALUE+4(4),K0

         BNE   C2

C1       MVC   0(4,4),=F'-1' MAKING K = -1

         B     EX

C2       MVC   0(4,4),K0

         L     3,XVALUE+4    ******

         C     3,K0          *

         BL    EX            *

         C     3,=F'180'     *

         BH    EX            * GETTING THE BCD WORD CORRESPONDING TO

         M     2,K6          * THE VOCABULARY INTEGER.  REG 2

         S     3,K6          * WILL HAVE IT'S ADDRESS

         LA    2,TA          *

         AR    2,3           ******

         MVC   MINI(6),0(2)

C3       L     3,M

         L     3,VALUE       M VALUE IS IN REG 3

         C     3,JX

         BH    ERR2

         C     3,K0

         BNH   ERR2

CS1      S     3,K1

         SLL   3,3

         LA    5,TABSET

         AR    5,3

         L     6,4(0,5)

         L     5,0(0,5)

         SR    7,7

CS2      A     7,K1

         CLC   MINI(6),0(5)

         BE    CS3

         CR    7,6

         BE    TRYMAIN

         A     5,K6

         B     CS2

TRYMAIN   CLC   MINI(6),WORDRAIL

         BNE   EX

         MVC   MINI(6),WORDMAIN

         B     C3

ERR1     L     4,IOCOMMON

         L     3,84(0,4)

         ST    3,IOADDR

         CNOP  0,4

         L     15,IBKOM

         BAL   14,4(0,15)

         DC    XL1'1',AL3(IOADDR)

         DC    AL4(ERL1)

         BAL   14,16(0,15)

ERREXIT  L     15,AERRORAD

         L     15,0(15)

         BR    15

ERR2     L     4,IOCOMMON

         L     3,84(0,4)

         ST    3,IOADDR

         CNOP  0,4

         L     15,IBKOM

         BAL   14,4(0,15)

         DC    XL1'1',AL3(IOADDR)

         DC    AL4(ERL2)

         BAL   14,16(0,15)

         B     ERREXIT

CS3      ST    7,0(4)

EX       RETURN (14,12),T

ERL1     DC    X'021A27'

         DC    C' SETMIN CALLED WITH TOO MANY PARAMETERS'

         DC    X'1E22'

ERL2     DC    X'021A27'

         DC    C' THIRD PARAMETER IN CHKMIN IS TOO LARGE'

         DC    X'1E22'

MINI     DS    CL6

WORDRAIL DC    C'00RAIL'

WORDMAIN DC    C'00MAIN'

IOCOMMON DC    V(ATAPTB)

IOADDR   DC    F'0'

IBKOM    DC    V(IBCOM#)

AERRORAD DC    V(AERROR)

JX       DS    F

TABSET   DS    40F

XVALUE   DS    D

POINTER  DC    A(BASE)

*                  1     2     3     4     5

TA       DC    C'ATANGLCENTER0CROSSFUNOFY0INTOF'

*                  6     7     8     9     10

         DC    C'INVERS0LARGE00LEFTLENGTH0MINUS'

*                  11    12    13    14    15

         DC    C'00NEGX00NEGY00NEGZ000NOX000NOY'

*                  16    17    18    19    20

         DC    C'000NOZPARLELPERPTO00PLUS00POSX'

*                  21    22    23    24    25

         DC    C'00POSY00POSZRADIUS0RIGHT0SCALE'

*                  26    27    28    29    30

         DC    C'0SMALL0TANTO0TIMESTRANSL00UNIT'

*                  31    32    33    34    35

         DC    C'XLARGEXSMALLXYPLAN0XYROTYLARGE'

*                  36    37    38    39    40

         DC    C'YSMALLYZPLAN0YZROTZLARGEZSMALL'

*                  41    42    43    44    45

         DC    C'ZXPLAN0ZXROT3PT2SL4PT1SL0005PT'

*                  46    47    48    49    50

         DC    C'INTERC0SLOPE0000IN000OUT00OPEN'

*                  51    52    53    54    55

         DC    C'000ALL00LASTNOMORE00SAMEMODIFY'

*                  56    57    58    59    60

         DC    C'MIRROR0STARTENDARC00CCLW000CLW'

*                  61    62    63    64    65

         DC    C'MEDIUM00HIGH000LOW0CONST00DECR'

*                  66    67    68    69    70

         DC    C'00INCR0PERSPROTREF0000TO00PAST'

*                  71    72    73    74    75

         DC    C'0000ON000OFF000IPM000IPRCIRCUL'

*                  76    77    78    79    80

         DC    C'LINEAR0PARAB000RPMMAXRPM00TURN'

*                  81    82    83    84    85

         DC    C'00FACE00BORE00BOTH0XAXIS0YAXIS'

*                  86    87    88    89    90

         DC    C'0ZAXISNORMDS00AUTO0FLOOD00MIST'

*                  91    92    93    94    95

         DC    C'TAPKUL00STEP00RAIL00SIDELINCIR'

*                  96    97    98    99    100

         DC    C'MAXIPM000REV00TYPE0NIXIE0LIGHT'

*                  101   102   103   104   105

         DC    C'FOURPT0TWOPTPTSLOPPTNORMSPLINE'

*                  106   107   108   109   110

         DC    C'RTHETATHETAR000XYZ0TANONTRFORM'

*                  111   112   113   114   115

         DC    C'NORMAL0000UP00DOWN00LOCK000SFM'

*                  116   117   118   119   120

         DC    C'XCOORDYCOORDZCOORDMULTRDXYVIEW'

*                  121   122   123   124   125

         DC    C'YZVIEWZXVIEW0SOLID00DASHDOTTED'

*                  126   127   128   129   130

         DC    C'CIRLIN0DITTO000PENSCRIBE0BLACK'

*                  131   132   133   134   135

         DC    C'000RED0GREEN00BLUEINTENS00LITE'

*                  136   137   138   139   140

         DC    C'000MED00DARK0CHUCKCOLLET0AAXIS'

*                  141   142   143   144   145

         DC    C'0BAXIS0CAXIS000TPIOPTION0RANGE'

*                  146   147   148   149   150

         DC    C'0PSTAN00FULL0FRONT00REARSADDLE'

*                  151   152   153   154   155

         DC    C'00MILL00THRU00DEEP00TRAVSETOOL'

*                  156   157   158   159   160

         DC    C'SETANGHOLDERMANUALADJUSTCUTANG'

*                  161   162   163   164   165

         DC    C'000NOW00NEXT0DRILLBINARY000BCD'

*                  166   167   168   169   170

         DC    C'00PART00REAM000TAP000CAMZIGZAG'

*                  171   172   173   174   175

         DC    C'RETAIN00OMIT0AVOIDRANDOM0000AT'

*                  176   177   178   179   180

         DC    C'ANTSPI000000000000000000GAPLES'

SAVE     DS    0F

INDICATR DS    F

INVOLKNG DS    F

INVOLKED DS    F

RETURNXX DS    F

ENTRYXXX DS    F

REGOTO12 DS    13F

CALLLIST DSECT

ARGMNT1  DS    A

ARGMNT2  DS    A

ARGMNT3  DS    A

ARGMNT4  DS    A

ARGMNT5  DS    A

ARGMNT6  DS    A

ARGMNT7  DS    A

ARGMNT8  DS    A

ARGMNT9  DS    A

ARGMNT10 DS    A

ARGMNT11 DS    A

ARGMNT12 DS    A

ARGMNT13 DS    A

ARGMNT14 DS    A

ARGMNT15 DS    A

ARGMNT16 DS    A

ARGMNT17 DS    A

ARGMNT18 DS    A

ARGMNT19 DS    A

ARGMNT20 DS    A

ARGMNT21 DS    A

ARGUMENT DSECT

VALUE    DS    CL4

         CSECT

SET      EQU   CALLLIST

N        EQU   ARGMNT1

A1       EQU   ARGMNT2

J1       EQU   ARGMNT3

A2       EQU   ARGMNT4

J2       EQU   ARGMNT5

A3       EQU   ARGMNT6

J3       EQU   ARGMNT7

A4       EQU   ARGMNT8

J4       EQU   ARGMNT9

A5       EQU   ARGMNT10

J5       EQU   ARGMNT11

A6       EQU   ARGMNT12

J6       EQU   ARGMNT13

A7       EQU   ARGMNT14

J7       EQU   ARGMNT15

A8       EQU   ARGMNT16

J8       EQU   ARGMNT17

A9       EQU   ARGMNT18

J9       EQU   ARGMNT19

A10      EQU   ARGMNT20

J10      EQU   ARGMNT21

CHK      EQU   CALLLIST

X        EQU   ARGMNT1

K        EQU   ARGMNT2

M        EQU   ARGMNT3

         END

*/

