#include <assert.h>
int puncha_(void*a,void*b,void*c,void*d)
{
	assert(0);
	return 0;
}
/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
PUNCHA   START 0
***********************************************************************
*        PUNCHA    -    GENERATE NAS943 PUNCHED PAPER TAPE CODES FOR  *
*                       EBCDIC CHARACTERS.                            *
***********************************************************************
*        PUNCHB    -    SIMILAR TO PUNCHA EXCEPT THAT THE INPUT BCD   *
*                       (OR EBCDIC) CHARACTERS ARE PUNCHED OUT WITHOUT*
*                       CONVERSION.  THAT IS, ABCD WILL BE PUNCHED    *
*                       OUT AS ABCD.  EVERYTHING ELSE THAT APPLIES TO *
*                       PUNCHA APPLIES TO PUNCHB.                     *
***********************************************************************
***********************************************************************
*           USE    -    CALL PUNCHA (N,A,J,K) WHERE:                  *
*                       ..............................................*
*                  N....DEFINES THE NUMBER OF EBCDIC CHARACTERS IN    *
*                       THE ARRAY 'A' TO BE CONVERTED TO THE PUNCHED  *
*                       PAPER TAPE CODE.  THE ABSOLUTE VALUE OF 'N'   *
*                       IS ALWAYS USED.                               *
*                       ..............................................*
*                  A....DEFINES THE ARRAY WHERE THE 'N' EBCDIC        *
*                       CHARACTERS ARE STORED IN CORE. THE ARRAY IS   *
*                       ASSUMED TO BE STORED FORWARD IN CORE.         *
*                       ..............................................*
*                  J....DEFINES THE MODE OF PROCESSING FOR PUNCHA;    *
*                       THE FOLLOWING VALUES FOR 'J' ARE VALID:       *
*                  *    J)0....THE CARD BUFFER IS INITIALIZED WITH    *
*                              ZEROS AND A FIRST ENTRY CONDITION IS   *
*                              PRODUCED.                              *
*                  *    J=0....THE CONVERSION OF THE 'N' CHARACTERS IN*
*                              ARRAY 'A' WILL PROCEED NORMALLY.  IF A *
*                              FIRST ENTRY CONDITION EXISTS, THE      *
*                              IDENTIFICATION AND SEQUENCE FIELDS ARE *
*                              ASSUMED TO HAVE BEEN INITIALIZED BY    *
*                              THE POST PROCESSOR MODULES PUNIDN AND  *
*                              PUNSEQ RESPECTIVELY FOR USE IN PUNCHA. *
*                  *    J=1....THIS IS AN "END" COMMAND, THEREFORE    *
*                              THE REMAINDER OF THE PRESENT CARD IS   *
*                              FILLED WITH "SPACE CODES" (EBCDIC BLANK*
*                              CHARACTERS) AND THEN PUNCHED.          *
*                  *    J=2....THE "EOB" CHARACTER WILL NOT           *
*                              BE AUTOMATICALLY INSERTED WHEN 'N' IS  *
*                              EXHAUSTED.  ANY EOB CHARACTER FOUND    *
*                              IN THE INPUT ARRAY WILL BE CONVERTED   *
*                              AND PROCESSING OF THE INPUT ARRAY     *
*                              WILL CONTINUE.                         *
*                  *    J=3....THE FIRST CHARACTER IN THE ARRAY 'A' AS*
*                              DEFINED BY 'K' IS PUT INTO THE CARD    *
*                              BUFFER 'N' TIMES WITHOUT INSERTING AN  *
*                              "EOB" CHARACTER.                       *
*                  *    J=4....THE CONVERSION OF THE CHARACTERS IN    *
*                              ARRAY 'A' WILL TAKE PLACE UNTIL 'N' IS *
*                              EXHAUSTED, AND WILL NOT STOP ON        *
*                              ENCOUNTERING AN "EOB" CHARACTER.       *
*                              AN EOB WILL AUTOMATICALLY BE INSERTED  *
*                              WHEN N IS EXHAUSTED.  THE VALUE OF J   *
*                              WILL BE CHANGED TO ZERO IN THE PROGRAM *
*                              THAT CALLED PUNCHA WITH J=4.           *
*                       ..............................................*
*                  K....DEFINES PROCESSING FOR BLANKS AND PERIODS     *
*                       THE FOLLOWING VALUES FOR 'K' ARE VALID:       *
*                  *    K=-2...PERIODS AND BLANKS REDUCE N BY 1 BUT   *
*                              ARE OTHERWISE IGNORED.                 *
*                  *    K=-1...PERIODS ARE REDUCE N BY 1 BUT ARE      *
*                              OTHERWISE IGNORED.                     *
*                  *    K=0....(OR NOT SPECIFIED IN THE CALLING       *
*                              SEQUENCE TO PUNCHA), BLANK CHARACTERS  *
*                              IN ARRAY 'A' ARE IGNORED.              *
*                  *    K=X....(WHERE X IS A POSITIVE NUMBER),        *
*                              BLANK CHARACTERS WILL BE PROCESSED BY  *
*                              PUNCHA.                                *
*          NOTE    -    THE FOLLOWING TWO RULES APPLY TO THE USE OF   *
*                       THE FIELDS INITIALIZED BY PUNIDN AND PUNSEQ,  *
*                       PUNIDS AND PUNNOM RESPECTIVELY:               *
*                  *    PUNIDN AND PUNSEQ SHOULD BE USED PRIOR TO A   *
*                       FIRST ENTRY INTO PUNCHA WITH J=0.             *
*                  *    A SUBSEQUENT USE OF PUNCHA WITH J)0 WILL      *
*                       PRODUCE A FIRST ENTRY CONDITION AND THE ABOVE *
*                       RULE WILL AGAIN APPLY.                        *
***********************************************************************
***********************************************************************
         ENTRY PUNCHB
         EXTRN A0CON                   ******
K0       EQU   A0CON                   *
K1       EQU   A0CON+4                 *
K2       EQU   A0CON+8                 *
K3       EQU   A0CON+12                *
K4       EQU   A0CON+16                *
K5       EQU   A0CON+20                *COMMON/A0CON/
K6       EQU   A0CON+24                *
K7       EQU   A0CON+28                *
K8       EQU   A0CON+32                *
K9       EQU   A0CON+36                *
K10      EQU   A0CON+40                *
K11      EQU   A0CON+44                *
K12      EQU   A0CON+48                ******
FLOATING EQU   0                       ******
ARGREG   EQU   3                       *
CALLREG  EQU   4                       *
WORKREG  EQU   5                       *
CONSTREG EQU   6                       *
XR2      EQU   7                       *REGISTER SPECIFICATION
XR4      EQU   8                       *
XR6      EQU   9                       *
POINTER  EQU   10                      *
INDEX    EQU   11                      *
BASEREG  EQU   12                      *
SAVEREG  EQU   13                      ******
         EXTRN PUNIDS                  ******
         EXTRN PUNNOM                  *
         USING PUNCHA,BASEREG          *
         USING CALLLIST,CALLREG        *ESTABLISH ADDRESSABILITY
         USING ARGUMENT,ARGREG         *
         USING A0CON,CONSTREG          *
         USING ARRAY,1                 *
         USING TAP,INDEX               ******
BASE     BC    15,12(15)               ******
         DC    X'0740'                 *DEFINE THE NAME OF THE ROUTINE
         DC    C'PUNCHA'               ******
         SAVE  (1,12),T                *SAVE
         LR    BASEREG,15
         L     CONSTREG,COMMON
         MVC   TABLE(2),SNAS943
         MVC   MODE,K4
         MVC   BLANK(1),HEX10
         MVI   COL1EOB+1,X'80'
         B     START
         CNOP  0,4
PUNCHB   SAVE  (2,12),T,PUNCHB
         L     BASEREG,POINTR-PUNCHB(0,15)
         L     CONSTREG,COMMON
         MVC   TABLE(2),SBCD
         MVC   MODE,K3
         MVC   BLANK(1),HEX40
         MVI   COL1EOB+1,C'$'
START    LR    CALLREG,1
         ST    SAVEREG,INVOLKNG        *
         LA    WORKREG,SAVE            *SET-UP SAVE AREA LINKAGE
         ST    WORKREG,8(0,13)         *
         LR    SAVEREG,WORKREG         *
         L     INDEX,RESTART           ******
         MVC   NZEROFL,K1
         MVC   EOBADDED,K0
         MVC   TRANLATE+4(2),TABLE
         MVC   VALIDITY+4(2),TABLE
         TM    J,X'80'                 *
         BZ    PN1                     *TEST FOR FOURTH ARGUMENT 'K'
         MVC   KMODE,AKZERO            ******
PN2      EQU   *
         L     ARGREG,J                *
         L     WORKREG,VALUE           *
         ST    WORKREG,VALUEOFJ        *
BRANCH   EQU   *                       *
         C     WORKREG,K0              *
         BL    PN4A                    *
         CLC   VALUEOFJ(4),K1          *
         BNE   PN3                     ******
COLMN    EQU   *
* ONLY J=1 ENTERS COLMN
         L     XR6,K1
         L     XR2,FULLCARD            ******
         S     XR2,COUNT               *
         S     XR2,K2                  *
         STC   XR2,FILLTAP+1           *
         A     XR2,K2                  *
         MVC   TAP(1),BLANK            *
         C     XR2,K1                  *SPACE CODE INSERTION
         BE    FINI                    *
FILLTAP  EQU   *                       *
         MVC   TAP+1,TAP               *
FINI     EQU   *                       *
         BAL   XR4,PUNCH               ******
PN4      EQU   *
         XC    PUNDF,PUNDF             ******
EX       EQU   *                       *RETURN
         CLC   VALUEOFJ,K4             *
         BNE   RET                     *
         L     ARGREG,J                *
         XC    0(4,3),0(3)             *
RET      EQU   *                       *
         ST    INDEX,RESTART           *
         L     SAVEREG,INVOLKNG        *
         RETURN (14,12),T              ******
PN4A     EQU   *
* ONLY J LESS THAN ZERO ENTERS PN4A
         LA    INDEX,T1                ******
         A     INDEX,K1                *
         NI    T1,X'00'                *ZERO ARRAY 'TAP'
         MVC   TAP(72),T1              *
         B     PN4                     ******
PN3      EQU   *
         L     ARGREG,N                ******
         L     7,VALUE                 *
         LPR   XR6,7                   *
         C     XR6,K0                  *
         BE    EX                      *
         L     XR2,K0                  *
         L     POINTER,A               *
         CLI   PUNDF,X'00'             *
         BNE   P5N                     *
         L     ARGREG,NUMBER           *
         LE    FLOATING,VALUE          *
         AU    FLOATING,CONSTANT       *
         STE   FLOATING,CARDNO         *PRE-PUNCHA INITIALIZATION
         NI    CARDNO,X'00'            *
         LA    INDEX,T1                *
         A     INDEX,K1                *
         MVI   PUNDF,X'FF'             *
COL1EOB  MVI   TAP,X'80'
         MVC   COUNT,K1                *
         LA    INDEX,1(INDEX)          *
         B     P5N                     ******
PN5      EQU   *
         L     WORKREG,KMODE           ******
         BR    WORKREG                 *
KMINUS1  CLI   0(POINTER),X'4B'        * TEST FOR PERIOD TO BE DELETED
         BE    SKIP                    *
         B     INCLUDE                 *
KMINUS2  CLI   0(POINTER),X'4B'        ******
         BE    SKIP                    * TEST FOR PERIOD OR BLANK
KZERO    CLI   0(POINTER),X'40'        *
         BE    SKIP                    *
INCLUDE  EQU   *                       *
         AR    INDEX,XR2               *
         MVC   TAP,0(POINTER)          *
         CLI   TAP,C'$'                *
         BE    END                     *
         SR    INDEX,XR2               *
         LA    XR2,1(XR2)              *
SKIP     LA    POINTER,1(POINTER)      *
         CLC   VALUEOFJ,K0             *
         BNE   PN6                     *
         CLI   0(POINTER),C'$'         *OR DELETION LOOP
         BE    PN7                     *
PN6      EQU   *                       *
         A     XR2,COUNT               *
         C     XR2,FULLCARD            *
         BNL   PN8                     *
         S     XR2,COUNT               *
         BCT   XR6,PN5                 *
SKIPPED  EQU   *
         CLC   EOBADDED,K1
         BE    DOLEXIT
         CLC   VALUEOFJ,K4
         BE    ENDJOB
         CLC   NZEROFL,K1
         BNE   DOLEXIT
         CLC   VALUEOFJ,K0
         BNE   DOLEXIT
ENDJOB   AR    INDEX,XR2
         MVI   TAP,C'$'
         SR    INDEX,XR2
         LA    XR2,1(XR2)
         MVC   EOBADDED,K1
         L     XR6,K1
         B     PN6
DOLEXIT  L     WORKREG,COUNT
         AR    WORKREG,XR2             *
         ST    WORKREG,COUNT           *
         LA    XR4,EX                  *
         B     MERGE                   ******
PN8      EQU   *
         S     XR2,COUNT               ******
         S     XR6,K1                  *
         BAL   XR4,MERGE               *PUNCH A CARD
PN9      EQU   *
         LA    XR4,PN5                 *
         B     PUNCH                   ******
PN7      EQU   *
         L     XR6,K2                  ******
         A     XR2,COUNT               *
         C     XR2,FULLCARD            *
         BNL   PN8                     *END OF BLOCK INSERTION
         S     XR2,COUNT               *
         S     XR6,K1                  *
         AR    INDEX,XR2               *
         MVC   TAP,0(POINTER)          *
END      EQU   *                       *
         MVC   NZEROFL,K0
         SR    INDEX,XR2               *
         LA    XR2,1(XR2)              *
         LA    POINTER,1(POINTER)      ******
         CLC   VALUEOFJ,K0
         BNE   PN6
         L     XR6,K1
         B     PN6
PUNCH    EQU   *
         CALL  CARDPN,(TAP,EIGHTEEN,MODE,CARDNO,PUNIDS,K2)
         L     WORKREG,CARDNO          ******
         A     WORKREG,K1              *
         ST    WORKREG,CARDNO          *
         L     ARGREG,NUMBER           *
         LE    FLOATING,VALUE          *
         AE    FLOATING,FLOATONE       *
         STE   FLOATING,VALUE          *POST-CARDPN PROCESSING
         LA    INDEX,T1                *
         A     INDEX,K1                *
         MVI   TAP,X'00'               *
         MVC   TAP+1(71),TAP           *
         XC    COUNT,COUNT             *
         C     XR6,K0                  *
         BE    SKIPPED                 *
         BR    XR4                     ******
MERGE    EQU   *
         C     XR2,K0
         BC    8,0(0,XR4)
TRANLATE EQU   *
         TRT   TAP,NAS943              ******
         BC    7,STORECHR              *
         SR    2,2                     *
STORECHR STC   2,T1                    *
         CLI   T1,X'EE'                *
         BE    ERR                     *
         STC   2,TAP                   *FOR NAS-943
         LA    INDEX,1(INDEX)          *PAPER TAPE CHARACTERS
         BCT   XR2,TRANLATE  *
         BR    XR4                     ******
PN1      EQU   *
         L     ARGREG,K                ******
         L     WORKREG,VALUE           *
         C     WORKREG,MINUS2          *
         BNE   TESTMIN1                *
         MVC   KMODE,AKMINUS2          *
         B     PN2                     *
TESTMIN1 C     WORKREG,MINUS1          *
         BNE   TESTZERO                *
         MVC   KMODE,AKMINUS1          *
         B     PN2                     *
TESTZERO C     WORKREG,K0              *
         BNE   NUMERICK                *
         MVC   KMODE,AKZERO            *
         B     PN2                     *
NUMERICK MVC   KMODE,AINCLUDE          *
         B     PN2                     ******
P5N      EQU   *
* ONLY J=0,2,3,4 OR GREATER THAN 4 ENTERS HERE
         CLC   VALUEOFJ(4),K3
         BL    PN5
         CLC   VALUEOFJ(4),K4
         BE    PN5
RESET    EQU   *                       *
* ONLY J=3 OR GREATER THAN 4 ENTERS RESET
         CLC   VALUEOFJ(4),K3          *
         BNE   ERR1                    ******
P6N      EQU   *
         CLC   KMODE,AKZERO            ******
         BE    SEARCH                  *
         CLC   KMODE,AKMINUS2          *
         BE    DOTANBNK                *
         CLC   KMODE,AKMINUS1          *
         BE    DOTONLY                 *
         B     VALIDITY                *
         BNE   VALIDITY                *
SEARCH   EQU   *
         CLI   0(POINTER),C' '         *
         BNE   VALIDITY                *
         LA    POINTER,1(POINTER)      *
         B     SEARCH                  *
DOTANBNK EQU   *                       *
         CLI   0(POINTER),X'40'        *
         BE    NEXTCHAR                *
DOTONLY  CLI   0(POINTER),X'4B'        *
         BNE   VALIDITY                *
NEXTCHAR LA    POINTER,1(POINTER)      *
         CLC   KMODE,AKMINUS2          *
         BE    DOTANBNK                *
         B     DOTONLY                 *
VALIDITY EQU   *                       *
         TRT   0(1,POINTER),NAS943     *
         BC    7,STORE                 *
         SR    2,2                     *
STORE    STC   2,T1                    *
         CLI   T1,X'EE'                *
         BE    ERR                     *
LOOP     EQU   *                       *PROCESS THE FIRST CHARACTER
         AR    INDEX,XR2               *'N' TIMES
         MVC   TAP,T1                  *
         SR    INDEX,XR2               *
         LA    XR2,1(XR2)              *
         A     XR2,COUNT               *
         C     XR2,FULLCARD            *
         BNL   EXI                     *
         S     XR2,COUNT               *
         BCT   XR6,LOOP                *
         AR    INDEX,XR2               *
         L     WORKREG,COUNT           *
         AR    WORKREG,XR2             *
         ST    WORKREG,COUNT           *
         B     EX                      ******
EXI      EQU   *
         S     XR6,K1                  *
         L     XR2,K0                  ******
         LA    XR4,LOOP                *PUNCH A CARD
         B     PUNCH                   ******
ERR      EQU   *
         CLC   MODE,K3
         BNE   ERRA
         MVC   FOR+55(6),BNAME
ERRA     SR    4,4
         IC    4,0(1)             GET BAD INPUT CHARACTER
         SRDL  4,4
         LA    3,ILEGTAB
         AR    4,3
         MVC   FOR+32(1),0(4)
         SRL   5,28
         AR    5,3
         MVC   FOR+33(1),0(5)
         L     4,IOCOMMON
         L     3,84(0,4)
         ST    3,IOADDR
         CNOP  0,4
         L     15,IBKOM
         BAL   14,4(0,15)
         DC    XL1'1',AL3(IOADDR)
         DC    AL4(ERL)
         BAL   14,16(0,15)
ERREXIT  L     15,AERRORAD
         L     15,0(15)
         BR    15
ERR1     EQU   *
         CLC   MODE,K3
         BNE   ERR1A
         MVC   FOR1+26(6),BNAME
ERR1A    MVI   RETURNXX,X'00'
         L     WORKREG,RETURNXX        *
         CVD   WORKREG,PACKED          *
         UNPK  FOR1+48(8),PACKED       *
         OI    FOR1+55,X'F0'           *
         L     WORKREG,INVOLKNG        *
         LA    WORKREG,4(WORKREG)      *
         L     WORKREG,0(WORKREG)      *
         LA    WORKREG,16(WORKREG)     *INCORRECT CALLING SEQUENCE
         L     WORKREG,0(WORKREG)      *
         LA    WORKREG,6(WORKREG)      *
         MVC   FOR1+66(6),0(WORKREG)   *
         L     4,IOCOMMON
         L     3,84(0,4)
         ST    3,IOADDR
         CNOP  0,4
         L     15,IBKOM
         BAL   14,4(0,15)
         DC    XL1'1',AL3(IOADDR)
         DC    AL4(ERL1)
         BAL   14,16(0,15)
         B     ERREXIT
ERL      DC    X'021A3E'
FOR      DC    C' '
         DC    CL35'  THE FOLLOWING HEX CHARACTER      '
         DC    CL26'IS UNACCEPTABLE TO PUNCHA '
         DC    X'1E22'
         DS    0D
         DS    CL5
ERL1     DC    X'021A48'
FOR1     DC    C' '
         DC    CL35'BAD CALLING SEQUENCE FOR PUNCHA AT '
         DC    CL36'LOCATION                IN          '
         DC    X'1E22'
HEX10    DC    X'10'
HEX40    DC    X'40'
BLANK    DS    C
SNAS943  DC    S(NAS943)
SBCD     DC    S(BCD)
TABLE    DS    H
IOADDR   DC    F'0'
IOCOMMON DC    V(ATAPTB)
IBKOM    DC    V(IBCOM#)
AERRORAD DC    V(AERROR)
NZEROFL  DS    F                       IF EQUAL TO 0, $ ENCOUNTERED
VALUEOFJ DS    F                       ******
KMODE    DS    F                       *
COUNT    DS    F                       *
MODE     DS    F                       *
POINTR   DC    A(BASE)                 *
CARDNO   DS    F                       *
RESTART  DC    A(TAP)                  *
EIGHTEEN DC    F'18'                   *
FULLCARD DC    F'72'                   *PUNCHA CONSTANTS
FLOATONE DC    E'1'                    *
MINUS1   DC    F'-1'
MINUS2   DC    F'-2'
AKMINUS1 DC    A(KMINUS1)
AKMINUS2 DC    A(KMINUS2)
AKZERO   DC    A(KZERO)
AINCLUDE DC    A(INCLUDE)
ILEGTAB  DC    C'0123456789ABCDEF'   TRANSLATE TABLE FOR BAD INPUT
PACKED   DS    D                       *
COMMON   DC    A(A0CON)                *
NUMBER   DC    A(PUNNOM)               *
CONSTANT DC    X'46000000'             *
PUNDF    DC    X'00'                   ******
BNAME    DC    C'PUNCHB'
EOBADDED DC    F'0'
NAS943   EQU   *    NATIONAL AEROSPACE STANDARD - 943
* HEXADECIMAL    X0X1X2X3X4X5X6X7X8X9XAXBXCXDXEXF   X-VALUE CHARACTER
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     0
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     1
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     2
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     3
         DC    X'10EEEEEEEEEEEEEEEEEEEE6B2A0B705B'     4    BLANK.)(+|
         DC    X'70EEEEEEEEEEEEEEEEEEEE803E2A7AEE'     5    +$*);
         DC    X'4031EEEEEEEEEEEEEEEEEE3B0BEEEE00'     6    -/,(?
         DC    X'EEEEEEEEEEEEEEEEEEEE7C7F0EEE7FEE'     7    :=@=
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     8
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     9
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     A
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     B
         DC    X'EE616273647576676879EEEEEEEEEEEE'     C    ABCDEFGHI
         DC    X'EE515243544546575849EEEEEEEEEEEE'     D    JKLMNOPQR
         DC    X'EEEE3223342526373829EEEEEEEEEEEE'     E    STUVWXYZ
         DC    X'20010213041516070819EEEEEEEEEEEE'     F    0123456789
*
* THE PRESENCE OF A HEXADECIMAL 'EE' INDICATES AN INVALID CHARACTER
*
BCD      EQU   *
* HEXADECIMAL    X0X1X2X3X4X5X6X7X8X9XAXBXCXDXEXF   X-VALUE CHARACTER
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     0
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     1
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     2
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     3
         DC    X'40EEEEEEEEEEEEEEEEEEEE4B4C4D4E4F'     4    BLANK.)(+|
         DC    X'50EEEEEEEEEEEEEEEEEEEE5B5C5D5EEE'     5    +$*);
         DC    X'6061EEEEEEEEEEEEEEEEEE6B6CEEEE6F'     6    -/,(?
         DC    X'EEEEEEEEEEEEEEEEEEEE7A7B7CEE7EEE'     7    :=@=
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     8
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     9
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     A
         DC    X'EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE'     B
         DC    X'EEC1C2C3C4C5C6C7C8C9EEEEEEEEEEEE'     C    ABCDEFGHI
         DC    X'EED1D2D3D4D5D6D7D8D9EEEEEEEEEEEE'     D    JKLMNOPQR
         DC    X'EEEEE2E3E4E5E6E7E8E9EEEEEEEEEEEE'     E    STUVWXYZ
         DC    X'F0F1F2F3F4F5F6F7F8F9EEEEEEEEEEEE'     F    0123456789
*
* THE PRESENCE OF A HEXADECIMAL 'EE' INDICATES AN INVALID CHARACTER
*
SAVE     DS    0F                      ******
INDICATR DS    F                       *
INVOLKNG DS    F                       *
INVOLKED DS    F                       *SAVE AREA
RETURNXX DS    F                       *
ENTRYXX  DS    F                       *
REG0TO12 DS    13F                     ******
CALLLIST DSECT                         ******
ARGUMNT1 DS    A                       *
ARGUMNT2 DS    A                       *
ARGUMNT3 DS    A                       *
ARGUMNT4 DS    A                       *
ARGUMENT DSECT                         *
VALUE    DS    CL4                     *ARGUMENT INTERFACE
ARRAY    DSECT                         *
         DS    C                       *
PUNCHA   CSECT                         *
N        EQU   ARGUMNT1                *
A        EQU   ARGUMNT2                *
J        EQU   ARGUMNT3                *
K        EQU   ARGUMNT4                ******
         CNOP  2,4
         DS    C
T1       DC    X'00'
TAP      DC    72X'00'
         END
*/
