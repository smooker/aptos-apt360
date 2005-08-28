#include <assert.h>
int parnom_(void* a , void* b)
{
	assert(0);
	return 0;
}
/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
PARNOM   START 0
*                            PARNOM - PARNEM
*----------------------------------------------------------------------
*
*        PARNOM AND PARNEM PROGRAMS FOR SYSTEM/360 APT
*
* PARNOM - PUNCHES 5X7 MATRIX IN COLUMN BINARY AND ODD PARITY EXCEPT
*              WHEN J IS SPECIFIED.  SEE BELOW FOR OUTPUT DESCRIPTION.
* PARNEM - PUNCHES 5X7 MATRIX IN COLUMN BINARY AND EVEN PARITY
*
* CALL PARNOM (N,A)  OR  CALL PARNOM (N,A,J)
* CALL PARNEM (N,A) WHERE
*        N IS THE NUMBER OF BCD CHRS TO BE CONVERTED FROM ARRAY A.
*              THE ABSOLUTE VALUE OF N IS USED.  A MAXIMUM OF 504 CHRS
*              MAY BE CONVERTED.
*        A IS THE ARRAY WHERE THE BCD CHRS ARE STORED IN A 6,2 FORMAT.
*              THAT IS, EVERY 6 BCD CHRS ARE FOLLOWED BY 2 BLANKS.  THE
*              BLANKS ARE NOT CONVERTED.
*        J IS 1 IF BCD OUTPUT IS DESIRED.  THE BCD OUTPUT WILL CREATE A
*              5X6 MATRIX WITH ODD PARITY ON THE IBM 1012 WHEN
*              CONVERTED TO EIA CHRS.
*          IS 2 IF A READABLE 5X6 CHARACTER MATRIX WITH NO PARITY IS
*              DESIRED.  PUNCHED IN COLUMN BINARY MODE.
*          IS NOT 1 OR 2, THE PRESENCE OF J IS IGNORED.  THIS ARGUMENT
*              IS OPTIONAL AND TAKES AFFECT ONLY WHEN PARNOM IS CALLED.
*
*   PARNOM (PARNEM) IS USED FOR PUNCH TAPE IDENTIFICATION  THE
*   ALLOWABLE CHRS ARE 0 THRU 9 A THRU Z AND (BLANK)=+.()-,*/
//*   ANY OTHER CHRS WILL BE PUT OUT AS A BLANK
/*
*----------------------------------------------------------------------
         ENTRY PARNEM
         EXTRN A0CON
K0       EQU   A0CON
K1       EQU   A0CON+4
K2       EQU   A0CON+8
K3       EQU   A0CON+12
K5       EQU   A0CON+20
K4       EQU   A0CON+16
K6       EQU   A0CON+24
K7       EQU   A0CON+28
K8       EQU   A0CON+32
K9       EQU   A0CON+36
K10      EQU   A0CON+40
K11      EQU   A0CON+44
K12      EQU   A0CON+48
SAVEREG  EQU   13
BASEREG1 EQU   12
CALLREG  EQU   11
WORKREG  EQU   10
CONSTREG EQU   9
ARGREG   EQU   3
         USING PARNOM,BASEREG1
         USING CALLLIST,CALLREG
         USING A0CON,CONSTREG
         USING ARGUMENT,ARGREG
BASE     SAVE  (2,12),T,PARNOM
         LR    BASEREG1,15
         LR    CALLREG,1
         ST    SAVEREG,INVOLKNG
         LA    WORKREG,SAVE
         ST    WORKREG,8(0,13)
         LR    SAVEREG,WORKREG
         L     CONSTREG,=V(A0CON)
         MVC   ST1,SO
         TM    4(1),X'80'     TEST FOR MORE THAN TWO ARGUMENTS.
         BO    AX             ONLY 2.
         L     3,8(1)         LOAD 3RD ARG. IS IT 1 FOR BCD OUTPUT
         L     3,0(3)
         C     3,K1
         BE    JIS1
         C     3,K2
         BNE   AX
         MVC   ST1,S56
         B     AX
JIS1     MVC   MODE,K3            BCD OUTPUT REQUESTED.  SET FL&G
         MVI   CHARCARD+1,X'09'
         MVC   ARRAYLNG,K8
         MVC   ST1,SBCD
         B     COMCODE
         CNOP  0,4
PARNEM   SAVE  (2,12),T,PARNEM
         L     BASEREG1,POINTER-PARNEM(0,15)
         LR    CALLREG,1
         ST    SAVEREG,INVOLKNG
         LA    WORKREG,SAVE
         ST    WORKREG,8(0,13)
         LR    SAVEREG,WORKREG
         L     CONSTREG,=V(A0CON)
         MVC   ST1,SE
AX       MVC   MODE,K4
         MVC   ARRAYLNG,K6
         MVI   CHARCARD+1,X'0C'
COMCODE  MVC   NUMBER,=F'18'
         MVC   ROWS,K2
         L     8,K0
         L     5,=V(PUNIDS)
         MVC   CARDID(4),0(5)
         L     5,=V(PUNNOM)
         L     2,0(0,5)
         SR    3,3
         SLL   2,1
         SRDL  2,25
         S     2,=F'64'
         C     2,K0
         BL    COMP2
         C     2,K7
         BH    COMP2
         L     4,K8
         SR    4,2
COMP1    C     4,K0
         BE    AZ
         SRL   3,4
         S     4,K1
         B     COMP1
COMP2    L     3,K0
AZ       ST    3,CARDSEQ
         L     6,A           LOAD ADDRESS OF ARRAY A INTO REG 6
         L     3,N
         L     3,VALUE
         LPR   2,3
         C     2,K0
         BE    RET
         C     2,=F'504'
         BNH   OKN
         L     2,=F'504'
OKN      NI    TS+1,X'0F'
CLEAR    L     10,ST1
         MVC   TAP(1),0(10)
         MVC   TAP+1(71),TAP
         LA    10,TAP        REG 10 WILL KEEP POSITION IN TAP
         MVC   NOOFCONV,K0    ZERO COUNTER FOR NO OF HEX CHAR
DOLTEST  SR    5,5           COUNTER FOR THE NO OF COMPARSIONS IN TAB1
         CLI   0(6),X'5B'    TESTING IF TEST CHR IS DOLLAR SIGN
         BE    PAR1          YES
         LA    7,TAB1        LOADING ADDRESS OF LEGITIMATE CHRS
TRYAGAIN CLC   0(1,6),0(7)   MATCHING TEST CHR AGAINST TAB1
         BE    PAR5          FOUND IN TAB1
         A     7,K1          GETTING NEXT CHR IN TAB1
         A     5,K1
         C     5,=F'50'
         BNE   TRYAGAIN
         L     5,K0
PAR5     M     4,ARRAYLNG    ******
         L     4,ST1         * POSITIONING TO GET RIGHT EQUIVALENT
         AR    5,4           ******
         TM    MODE+3,X'04'   IS BINARY REQ
         BO    BINPUT         YES
BCDPUT   MVC   0(8,10),0(5)   NO. MOVE TABLE CHARS INTO TAP ARRAY
         B     PUTRET
BINPUT   MVC   0(6,10),0(5)
PUTRET   A     8,K1
F5       L     3,NOOFCONV    ******
         A     3,K1          * UPDATE HEX CHAR COUNTER
         ST    3,NOOFCONV    *
         S     2,K1          *
         C     2,K0          * WERE N CHARS CONVERTED?
         BE    PAR1          * YES.
         C     8,K6          *
         BNE   F6            *
         A     6,K2          *
         L     8,K0          *
F6       A     6,K1          *
         CH    3,CHARCARD    * IS THE OUTPUT AREA FILLED?
         BE    PUNC          YES
         A     10,ARRAYLNG    INCREMENT TAP FOR NEXT CHR
         B     DOLTEST
PUNC     CALL  CARDPN,(TAP,NUMBER,MODE,CARDSEQ,CARDID,ROWS)
         L     5,=V(PUNNOM)
         LE    0,0(0,5)
         AE    0,=E'1'
         STE   0,0(0,5)
TS       B     RET
         L     3,CARDSEQ
         A     3,K1
         ST    3,CARDSEQ
         B     CLEAR
PAR1     OI    TS+1,X'F0'    SET TS FLAG TO BRANCH UNCONDITIONALLY
         CLC   NOOFCONV,K0   TEST IF SOMETHING IS IN THE OUTPUT AREA
         BNH   RET
         B     PUNC
RET      L     SAVEREG,INVOLKNG
         RETURN (14,12),T
CHARCARD DC    H'0'           NO OF INPUT CHARS PER OUTPUT CARD
ARRAYLNG DC    F'0'
NOOFCONV DS    F             NUMBER OF CONVERSIONS PERFORMED
TAP      DS    72C           OUTPUT AREA
ST1      DS    F
SO       DC    A(TABO)
SE       DC    A(TABE)
SBCD     DC    A(TABBCD)
S56      DC    A(TAB56)
NUMBER   DS    F
MODE     DS    F
CARDID   DS    F
CARDSEQ  DS    F
ROWS     DS    F
POINTER  DC    A(BASE)
*******      TABLE FOR 5X7 MATRIX OUTPUT WITH ODD PARITY       ********
*                      FOR COLUMN BINARY MODE                         *
TABO     DC    X'808080808080'    BLANK
         DC    X'3EC1C1C13E80'    ZERO
         DC    X'80027F808080'    1
         DC    X'C26151494680'    2
         DC    X'A1C149CDB380'    3
         DC    X'9894927F1080'    4
         DC    X'A7454545B980'    5
         DC    X'BCC24949B080'    6
         DC    X'010179858380'    7
         DC    X'B6494949B680'    8
         DC    X'864949A19E80'    9
         DC    X'A2A2A2A2A280'    =
         DC    X'08083E080880'    +
         DC    X'FE919191FE80'    A
         DC    X'7F494949B680'    B
         DC    X'3EC1C1C1A280'    C
         DC    X'7FC1C1C13E80'    D
         DC    X'7F494949C180'    E
         DC    X'7F8989890180'    F
         DC    X'3EC1C1497980'    G
         DC    X'7F0808087F80'    H
         DC    X'80C17FC18080'    I
         DC    X'8080E0E08080'    PERIOD
         DC    X'80C1C1A21C80'    )
         DC    X'080808080880'    MINUS
         DC    X'204040BF8080'    J
         DC    X'7F0894A2C180'    K
         DC    X'7F4040404080'    L
         DC    X'7F028C027F80'    M
         DC    X'7F0204087F80'    N
         DC    X'3EC145433E80'    O
         DC    X'7F8989898680'    P
         DC    X'3EC151A15E80'    Q
         DC    X'7F8919294680'    R
         DC    X'082A1C2A0880'    *
         DC    X'201008040280'    /
         DC    X'464949493180'    S
         DC    X'01017F010180'    T
         DC    X'BF404040BF80'    U
         DC    X'8FB040B08F80'    V
         DC    X'BF40BC40BF80'    W
         DC    X'E3940894E380'    X
         DC    X'070870080780'    Y
         DC    X'615149454380'    Z
         DC    X'8080D0B08080'    COMMA
         DC    X'801CA2C1C180'    (
         DC    X'08083E080880'    +
         DC    X'801CA2C1C180'    (
         DC    X'A2A2A2A2A280'    =
         DC    X'80C1C1A21C80'    )
*******      TABLE FOR 5X7 MATRIX OUTPUT WITH EVEN PARITY      ********
*                      FOR COLUMN BINARY MODE                         *
TABE     DC    X'C0C0C0C0C0C0'    BLANK
         DC    X'BE414141BEC0'    ZERO
         DC    X'C082FFC0C0C0'    1
         DC    X'42E1D1C9C6C0'    2
         DC    X'2141C94D33C0'    3
         DC    X'181412FF90C0'    4
         DC    X'27C5C5C539C0'    5
         DC    X'3C42C9C930C0'    6
         DC    X'8181F90503C0'    7
         DC    X'36C9C9C936C0'    8
         DC    X'06C9C9211EC0'    9
         DC    X'2222222222C0'    =
         DC    X'8888BE8888C0'    +
         DC    X'7E1111117EC0'    A
         DC    X'FFC9C9C936C0'    B
         DC    X'BE41414122C0'    C
         DC    X'FF414141BEC0'    D
         DC    X'FFC9C9C941C0'    E
         DC    X'FF09090981C0'    F
         DC    X'BE4141C9F9C0'    G
         DC    X'FF888888FFC0'    H
         DC    X'C041FF41C0C0'    I
         DC    X'C0C06060C0C0'    PERIOD
         DC    X'C04141229CC0'    )
         DC    X'8888888888C0'    MINUS
         DC    X'A0C0C03FC0C0'    J
         DC    X'FF88142241C0'    K
         DC    X'FFC0C0C0C0C0'    L
         DC    X'FF820C82FFC0'    M
         DC    X'FF828488FFC0'    N
         DC    X'BE41C5C3BEC0'    O
         DC    X'FF09090906C0'    P
         DC    X'BE41D121DEC0'    Q
         DC    X'FF0999A9C6C0'    R
         DC    X'88AA9CAA88C0'    *
         DC    X'A090888482C0'    /
         DC    X'C6C9C9C9B1C0'    S
         DC    X'8181FF8181C0'    T
         DC    X'3FC0C0C03FC0'    U
         DC    X'0F30C0300FC0'    V
         DC    X'3FC03CC03FC0'    W
         DC    X'6314881463C0'    X
         DC    X'8788F08887C0'    Y
         DC    X'E1D1C9C5C3C0'    Z
         DC    X'C0C05030C0C0'    COMMA
         DC    X'C09C224141C0'    (
         DC    X'8888BE8888C0'    +
         DC    X'C09C224141C0'    (
         DC    X'2222222222C0'    =
         DC    X'C04141229CC0'    )
*******      TABLE FOR 5X6 MATRIX OUTPUT WITH ODD PARITY       ********
*                            FOR BCD MODE                             *
TABBCD   DC    X'F1F1F1F1F1F1F1F1'      BLANK
         DC    X'6DD3D3D36DF1F1F1'      0
         DC    X'F2E34FF2F2F1F1F1'      1
         DC    X'5FD2D2D2E3F1F1F1'      2
         DC    X'D5D2D2D24DF1F1F1'      3
         DC    X'C9F8F84FF8F1F1F1'      4
         DC    X'C5D2D2D25CF1F1F1'      5
         DC    X'6DD2D2D25CF1F1F1'      6
         DC    X'60D6D9D1C1F1F1F1'      7
         DC    X'6CD2D2D26CF1F1F1'      8
         DC    X'E5D2D2D26DF1F1F1'      9
         DC    X'7D7D7D7DF1F1F1F1'      =
         DC    X'F8F86EF8F8F1F1F1'      +
         DC    X'7FE9D9E97FF1F1F1'      A
         DC    X'4FD2D2D26DF1F1F1'      B
         DC    X'6DD3D3D3E5F1F1F1'      C
         DC    X'4FD3D3D36DF1F1F1'      D
         DC    X'4FD2D2D2D3F1F1F1'      E
         DC    X'4FD9D9D960F1F1F1'      F
         DC    X'6DD3D6D6E6F1F1F1'      G
         DC    X'4FF8F8F84FF1F1F1'      H
         DC    X'F1D34FD3F1F1F1F1'      I
         DC    X'F1F7F7F1F1F1F1F1'      PERIOD
         DC    X'F1D36DF1F1F1F1F1'      )
         DC    X'F8F8F8F8F8F1F1F1'      -
         DC    X'F4F2F2F24FF1F1F1'      J
         DC    X'4FF840E5D3F1F1F1'      K
         DC    X'4FF2F2F2F2F1F1F1'      L
         DC    X'4FF040F04FF1F1F1'      M
         DC    X'4FF0F8F44FF1F1F1'      N
         DC    X'6DD3D3D36DF1F1F1'      O
         DC    X'4FD9D9D961F1F1F1'      P
         DC    X'6DD3D3D66EF1F1F1'      Q
         DC    X'4FD9D95CE2F1F1F1'      R
         DC    X'6CF94FF96CF1F1F1'      *
         DC    X'F2F4F84060F1F1F1'      /
         DC    X'E5D2D2D27DF1F1F1'      S
         DC    X'60604F6060F1F1F1'      T
         DC    X'4CF2F2F24CF1F1F1'      U
         DC    X'C9F4F2F4C9F1F1F1'      V
         DC    X'4FF4F8F44FF1F1F1'      W
         DC    X'C2F5F8F5C2F1F1F1'      X
         DC    X'60F07FF060F1F1F1'      Y
         DC    X'D67BD2C2D3F1F1F1'      Z
         DC    X'F1F27DF1F1F1F1F1'      ,
         DC    X'F1F16DD3F1F1F1F1'      (
         DC    X'F8F86EF8F8F1F1F1'      + BCD
         DC    X'F1F16DD3F1F1F1F1'      ( BCD
         DC    X'7D7D7D7DF1F1F1F1'      = BCD
         DC    X'F1D36DF1F1F1F1F1'      ) BCD
*******      TABLE FOR 5X6 MATRIX OUTPUT WITH NO PARITY        ********
*                      FOR COLUMN BINARY MODE                         *
TAB56    DC    X'000000000000'     BLANK
         DC    X'3C4242423C00'     ZERO
         DC    X'00447E400000'     1
         DC    X'64524A4A4400'     2
         DC    X'224A4A4E3200'     3
         DC    X'0E08087E0800'     4
         DC    X'2E4A4A4A3200'     5
         DC    X'3C4A4A4A3000'     6
         DC    X'0202720A0600'     7
         DC    X'344A4A4A3400'     8
         DC    X'044A4A4A3C00'     9
         DC    X'282828282800'     =
         DC    X'10107C101000'     +
         DC    X'781412147800'     A
         DC    X'7E4A4A4A3400'     B
         DC    X'3C4242422400'     C
         DC    X'7E4242423C00'     D
         DC    X'7E4A4A424200'     E
         DC    X'7E0A0A020200'     F
         DC    X'3C4242527200'     G
         DC    X'7E0808087E00'     H
         DC    X'00427E420000'     I
         DC    X'006060000000'     PERIOD
         DC    X'00423C000000'     )
         DC    X'101010101000'     MINUS
         DC    X'204040403E00'     J
         DC    X'7E0810244200'     K
         DC    X'7E4040404000'     L
         DC    X'7E0408047E00'     M
         DC    X'7E0408307E00'     N
         DC    X'3C4242423C00'     O
         DC    X'7E0A0A0A0400'     P
         DC    X'3C4252225C00'     Q
         DC    X'7E0A1A2A4400'     R
         DC    X'105438541000'     *
         DC    X'402010080400'     /
         DC    X'444A4A4A3200'     S
         DC    X'02027E020200'     T
         DC    X'3E4040403E00'     U
         DC    X'1E2040201E00'     V
         DC    X'7E2018207E00'     W
         DC    X'661008106600'     X
         DC    X'060870080600'     Y
         DC    X'62524A424600'     Z
         DC    X'000050300000'     COMMA
         DC    X'0000003C4200'     (
         DC    X'10107C101000'     +
         DC    X'0000003C4200'     (
         DC    X'282828282800'     =
         DC    X'00423C000000'     )
*/
//TAB1     DC    C' 0123456789=+ABCDEFGHI.)-JKLMNOPQR*/STUVWXYZ,('
 /*        DC    X'506C7B4C'    BCD + ( = )
SAVE     DS    0F
INDICATR DS    F
INVOLKNG DS    F
INVOLKED DS    F
RETURNXX DS    F
ENTRYXXX DS    F
REGOTO12 DS    13F
ARGUMENT DSECT
VALUE    DS    CL4
CALLLIST DSECT
ARGUMNT1 DS    A
ARGUMNT2 DS    A
         CSECT
PAR      EQU   CALLLIST
N        EQU   ARGUMNT1
A        EQU   ARGUMNT2
         END
*/
