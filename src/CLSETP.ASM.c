#include <assert.h>

#include <f2c.h>



extern void ataprd_(doublereal* tapeType, integer* ioflag, integer* nwrds, integer* param1, 

	integer* irecn, integer* param2, integer* hdr1, integer* param3, 

	integer* hdr2, integer* param4, integer* startAddress, integer* param5, 

	integer* param6, integer* param7, integer* deftab);







int clsetp_(void* a,void* b,void* c,void* d,void* e,void* f)

{

//	assert(0);

	return 0;

}

int clread_(integer* recNo,integer* wordCnt,doublereal* array,integer* M,integer* N)

{

	doublereal tapeType=2;

	integer param1=4;

	integer ioflag;

	integer class,subClass;

	*M=0;*N=0;

	ataprd_( &tapeType, &ioflag, wordCnt, &param1, recNo, 

		0, &class, 0, &subClass, 0, array, 0, 0, 0, 0);

	*wordCnt-=2;



	switch(class){

		case 1000:

			*M=6;

		break;

		case 2000:

			//*M=2;

			*M=1;



		break;

		case 3000:

		break;

		case 4000:

		break;

		case 5000:

			*M=3;

			*N=2;

		break;

		case 14000:

			*M=4;

		break;



	}

	return 0;

}



/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***

CLSETP   START 0

*                        CLSETP - CLREAD (FOR TAPE CLFILE)

*

*        CLSETP AND CLREAD PROGRAMS FOR SYSTEM/360 APT

*----------------------------------------------------------------------

* CALL CLSETP (KTAPE,B,NB,C,NC,ND) WHERE

*        KTAPE IS THE TAPE TO BE READ.

*        B IS THE ARRAY CONTAINING THE XCODES THE POST WILL PROCESS

*        C IS THE ARRAY CONTAINING THE AUXCODE THE POST WILL PROCESS

*        NB IS THE NUMBER OF XCODES IN ARRAY B

*        NC IS THE NUMBER OF AUXCODES IN ARRAY C

*        ND IS NOT USED ANYMORE. IT MAY BE DELETED FROM THE CALLING

*              SEQUENCE.

*----------------------------------------------------------------------

* CALL CLREAD (N1,N2,A,M,N) WHERE

*        N1 WILL BE THE CLTAPE RECORD NUMBER

*        N2 WILL BE THE WORD COUNT OF THE DATA STORED IN ARRAY A

*        A WILL BE THE ARRAY OF THE TRANSMITTED PARAMETERS

*        M IS THE CLASS OF THE DATA ENCOUNTERED

*        N WILL BE THE SUBCLASS OF THE DATA

*              IF M=1, THIS IS AN XCODE WITH NO PARAMETERS (2000)

*              IF M=2, THIS IS AN AUX-CODE WITH PARAMETERS (2000).

*              FOR M=1,2; N=J WHERE J IS THE J-TH COMMAND IN THE TABLE

*                   AS DEFINED BY THE CLSETP ROUTINE.

*              IF M=3, THIS IS THE DATA CLASS FOR 3-AXIS MACHINE (5000)

*              IF M=5, THIS IS THE DATA CLASS FOR 5-AXIS MACHINE (5000)

*                   N=1, 2, 3, OR 4 FOR GO TO, GO TO (CONT.), FROM,

*                   AND GO DELTA RESPECTIVELY

*              IF M=4, THEN AN EOF OR FINI (14000) HAS OCCURRED

*              IF M=6, THIS IS FOR PART PROGRAM SEQUENCE NO. (1000)

*              IF M=7, THIS IS FOR SURFACE TYPE.  ONLY CIRCLE DS WILL

*                   BE PASSED ON.  CANNON FORM OF CIRCLE WILL BE IN A.

*              IF M=8, THERE IS AN ARELEM ERROR CODE IN A.

*              IF M=9, MULTAX (9000) IS ON

*----------------------------------------------------------------------

*

         ENTRY CLREAD

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

SAVEREG  EQU   13

BASEREG1 EQU   12

BASEREG2 EQU   11

CALLREG  EQU   10

ARGREG   EQU   9

WORKREG  EQU   8

CONSTREG EQU   7

         USING CLSETP,BASEREG1

         USING CLSETP+4096,BASEREG2

         USING CALLLIST,CALLREG

         USING ARGUMENT,ARGREG

         USING A0CON,CONSTREG

BASE     SAVE  (2,12),T,CLSETP

         LR    BASEREG1,15

         L     BASEREG2,POINT2

         LR    CALLREG,1

         ST    SAVEREG,INVOLKNG

         LA    WORKREG,SAVE

         ST    WORKREG,8(0,13)

         LR    SAVEREG,WORKREG

         L     CONSTREG,=V(A0CON)

         L     3,KTAPE                   KTAPE ADDR (2 WORD BOUNDARY)

         ST    3,TOP1+12             ***********************

         ST    3,TOP3+12             *  DATA FILE ADDRESS  *

         ST    3,TOP5+12             *                     *

         ST    3,TOP6+12             ***********************

         MVC   BSAVE,B                  POST PROCESSOR X-CODES

         MVC   CSAVE,C                  POST PROCESSOR AUX-CODES

         MVC   MULAX,K0

         NI    CLFLG+1,X'0F'

SNIT     L     ARGREG,NB                NB ADDRESS

         L     3,VALUE

         LPR   8,3

         ST    8,NBSAVE

         L     ARGREG,NC                NC ADDRESS

         L     3,VALUE

         LPR   8,3

         ST    8,NCSAVE

         CNOP  0,4

TOP5     CALL  TAPEOP,(DUMMY,K1,IO)

         CNOP  0,4

TOP6     CALL  BUFFTP,(DUMMY,K2)

         L     SAVEREG,INVOLKNG

         RETURN (14,12),T

         CNOP  0,4

CLREAD   SAVE  (2,12),T,CLREAD

         L     BASEREG1,POINTER-CLREAD(0,15)

         L     BASEREG2,POINT2

         LR    CALLREG,1

         ST    SAVEREG,INVOLKNG

         LA    WORKREG,SAVE

         ST    WORKREG,8(0,13)

         LR    SAVEREG,WORKREG

         L     CONSTREG,=V(A0CON)

CLFLG    B     RET

         CNOP  0,4

TOP1     CALL  TAPERD,(DUMMY,IO,NWDS,K2,TAPSTO,K3,TAPSTO4,K0)

         L     3,IO

         C     3,K0

         BE    EOF

         BH    ERR2

PRO      L     ARGREG,N1

         MVC   VALUE(4),TAPSTO

         MVC   NVALUE,K0

         L     2,TAPSTO2

         SRDA  2,32

         D     2,=F'1000'

         ST    3,CLASS

         C     3,K0

         BNH   TOP1

         C     3,K2

         BL    SEQ

         BE    CODXX

         C     3,K4

         BL    SURF

         BE    TOP1

         C     3,K5

         BE    DATA

         C     3,K9

         BL    TOP1

         BE    MULTAX

         C     3,=F'13'

         BL    TOP1

         BE    AERR

         B     TOP1

SEQ      MVC   MVALUE,K6     CLASS 1000

         MVC   NVALUE,TAPSTO3        MOVE ISN TO SUBCLASS

         L     3,NWDS

         S     3,K1

         ST    3,NWDS

         MVC   TAPSTO4(8),TAPSTO4+8

CL1      LA    3,TAPSTO4

CL2      MVC   N2VALUE,NWDS

         CLC   N2VALUE,K0

         BE    EX

         CLC   N2VALUE,=F'252'

         BH    ERR1

         L     5,NWDS

         S     5,K1

         SLL   5,3           MULTIPLYING THE WORD COUNT BY 8

         AR    5,3           REG 5 HAS ENDING ADDR OF DATA TO BE MOVED

         L     4,K8

         L     6,A           REG 6 HAS STARTING ADDR OF A

CL5      MVC   0(8,6),0(3)

         A     6,K8

         BXLE  3,4,CL5

EX       L     ARGREG,N2

         MVC   VALUE,N2VALUE

         L     ARGREG,M

         MVC   VALUE,MVALUE

         L     ARGREG,N

         MVC   VALUE,NVALUE

RET      L     SAVEREG,INVOLKNG

         RETURN (14,12),T

SURF     CLC   TAPSTO4+12(4),K4       CLASS 3000

         BNE   TOP1

         CLC   TAPSTO3(4),K2

         BNE   TOP1

         MVC   MVALUE,K7

         L     3,NWDS

         S     3,K5

         ST    3,NWDS

         LA    3,TAPSTO4+40

         B     CL2

MULTAX   CLC   TAPSTO3(4),K2   CLASS 9000

         BNE   TOP1

         MVC   MVALUE,K9

         MVC   N2VALUE,K0

         MVC   MULAX,K0

         CLC   TAPSTO4+4(4),K1   TESTING IF MULTAX IS ON OR OFF

         BNE   EX            BRANCH IF MULTAX IS OFF

         MVC   MULAX,K1

         MVC   NVALUE,K1     SET SUBCLASS TO SHOW MULTAX IS ON

         B     EX

AERR     CLC   TAPSTO3(4),K3 CLASS 13000

         BNE   TOP1

         MVC   MVALUE,K8

         MVC   N2VALUE,K1

         L     6,A

         MVC   0(8,6),TAPSTO4

         B     EX

EOF      MVC   MVALUE,K4     CLASS 14000

         CNOP  0,4

TOP3     CALL  TAPEOP,(DUMMY,K1,IO)

         CNOP  0,4

         MVC   N2VALUE,K0

         OI    CLFLG+1,X'F0'                     (3 AXIS)

         B     EX

DATA     MVC   MVALUE,K3     CLASS 5000

         CLC   TAPSTO3(4),K3

         BL    TOP1

         BE    FROM

         CLC   TAPSTO3(4),K5

         BL    NEWF

         CLC   TAPSTO3(4),K6

         BL    GOTO

         BE    CONTN

         BH    TOP1

FROM     MVC   NVALUE,K3

NEXT     CLC   MULAX,K0

         BE    XNOR

         MVC   MVALUE,K5

XNOR     L     3,NWDS

         S     3,K2

         ST    3,NWDS

         LA    3,TAPSTO4+16

         B     CL2

NEWF     MVC   NVALUE,K4

XOR      MVC   NWDS,K3

         LA    3,TAPSTO4+16

         B     CL2

GOTO     MVC   NVALUE,K1

         B     NEXT

CONTN    MVC   NVALUE,K2

         B     NEXT

CODXX    MVC   MVALUE,K1     CLASS 2000

         L     2,TAPSTO3

         SRDA  2,32

         D     2,=F'1000'    DIVIDING THE SUBCLASS BY 1000

         C     3,K1          XCODES OR AUXCODES?

         BL    TABLEB        X-CODES, SO BRANCH

TABLEC   ST    2,REMSAVE     ******

         LR    3,2           * REG 3 HAS ADDRESS OF WORD CORRESPONDING

         M     2,K6          * TO THE VOCABULARY INTEGER

         LA    2,TAB2        *

         AR    3,2           ******

         L     5,NCSAVE    LOADING NO OF AUX-CODES IN ARRAY C IN REG 2

         S     5,K1

         M     4,K6

         L     2,CSAVE       STARTING ADDR FOR BXLE IS START OF ARRAY C

         AR    5,2           DETERMINING END OF AUXCODES IN CLSETP

         L     4,K6          INCREMENT FOR BXLE INSTRUCTION

TLUC     CLC   0(6,2),0(3)   COMPARE ARRAY C AGAINST WORD FROM TAB2

         BE    HITC

         BXLE  2,4,TLUC

         CLC   REMSAVE,K12

         BNE   TOP1

         LA    3,TAB2+204

         L     2,CSAVE

         MVC   REMSAVE,K0

         B     TLUC

HITC     S     2,CSAVE

         A     2,K6

         SRDA  2,32

         D     2,K6

         ST    3,NVALUE

         MVC   MVALUE,K2

         B     CL1

TABLEB   LR    3,2           ******

         M     2,K6          * REG 3 HAS ADDRESS OF WORD CORRESPONDING

         LA    2,TAB1        * TO THE VOCABULARY INTEGER

         AR    3,2           ******

         L     5,NBSAVE      LOADING NO OF X-CODES IN ARRAY B IN REG 2

         S     5,K1

         M     4,K6

         L     2,BSAVE       STARTING ADDR FOR BXLE IS START OF ARRAY B

         AR    5,2           DETERMINING END OF XCODES IN CLSETP

         L     4,K6          INCREMENT FOR BXLE INSTRUCTION

TLUB     CLC   0(6,2),0(3)   COMPARE ARRAY B AGAINST WORD FROM TAB1

         BE    HITB

         BXLE  2,4,TLUB

         B     TOP1

HITB     S     2,BSAVE

         A     2,K6

         SRDA  2,32

         D     2,K6

         ST    3,NVALUE      STORING J-TH POSITION INTO NVALUE

         MVC   N2VALUE,K0

         B     EX

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

POINTER  DC    A(BASE)

POINT2   DC    A(BASE+4096)

IOCOMMON DC    V(ATAPTB)

IOADDR   DC    F'0'

IBKOM    DC    V(IBCOM#)

AERRORAD DC    V(AERROR)

NWDS     DS    F

NREC     DS    F

IO       DS    F

REMSAVE  DS    F

MULAX    DS    F

TAB1     DC    C'000000'

*                  1     2     3     4     5

         DC    C'000END00STOPOPSTOP0ISTOP0RAPID'

*                 6     7     8     9     10

         DC    C'SWITCHRETRCT0DRESSPICKUPUNLOAD'

*                  11    12    13    14    15

         DC    C'0PENUPPENDWN00ZEROGOHOME0RESET'

*                  16    17    18    19    20

         DC    C'GOCLERDRAWLI0PROBY0PROBXULOCKX'

*                  21    22

         DC    C'0LOCKXFACEML'

TAB2     DC    C'000000'

*                  1     2     3     4     5

         DC    C'PLUNGE00HEAD00MODECLEARP0TMARK'

*                 6     7     8     9     10

         DC    C'REWINDCUTCOMREVERSFEDRAT0DELAY'

*                  11    12    13    14    15

         DC    C'000AIROPSKIPLEADER0PPLOTMACHIN'

*                  16    17    18    19    20

         DC    C'MCHTOLPIVOTZMCHFIN0SEQNOINTCOD'

*                  21    22    23    24    25

         DC    C'DISPLYAUXFUN0CHECK0POSTNTOOLNO'

*                  26    27    28    29    30

         DC    C'ROTABLORIGINSAFETYARCSLPCOOLNT'

*                  31    32    33    34    35

         DC    C'SPINDL00IFROTURRETDELETEROTHED'

*                  36    37    38    39    40

         DC    C'THREAD0TRANSTRACUT0INDEX00COPY'

*                  41    42    43    44    45

         DC    C'00PLOTOVPLOTLETTERPPRINTPARTNO'

*                  46    47    48    49    50

         DC    C'INSERTCAMERAPREFUNCOUPLE0PITCH'

*                  51    52    53    54    55

         DC    C'MDWRIT0MDENDASLOPE0CYCLELOADTL'

*                  56    57    58    59    60

         DC    C'SELCTLCLRSRF0DWELL0DRAFT0CLAMP'

*                  61    62    63    64    65

         DC    C'PLABELMAXDPMSLOWDNMAXVELLPRINT'

*                  66    67    68    69    70

         DC    C'MOVETOCORNFD000PBSREGBRKVTLAXS'

*                  71    72

         DC    C'0WCORNMAGTAP'

ERL1     DC    X'021A1F'

         DC    C' BLKSIZ FOR CLREAD IS TOO SMALL'

         DC    X'1E22'

ERL2     DC    X'021A14'

         DC    C' I/O ERROR IN CLREAD'

         DC    X'1E22'

BSAVE    DS    A

CSAVE    DS    A

NBSAVE   DS    F

NCSAVE   DS    F

DUMMY    DS    A

CLASS    DS    F

N2VALUE  DS    F

MVALUE   DS    F

NVALUE   DS    F

         CNOP  4,8

TAPSTO   DS    F

TAPSTO2  DS    F

TAPSTO3  DS    F

TAPSTO4  DS    252D

SAVE     DS    0F

INDICATR DS    F

INVOLKNG DS    F

INVOLKED DS    F

RETURNXX DS    F

ENTRYXXX DS    F

REGOTO12 DS    13F

CALLLIST DSECT

ARGUMNT1 DS    A

ARGUMNT2 DS    A

ARGUMNT3 DS    A

ARGUMNT4 DS    A

ARGUMNT5 DS    A

ARGUMNT6 DS    A

ARGUMENT DSECT

VALUE    DS    CL4

         CSECT

CLTAPE   EQU   CALLLIST      CLREAD CALL ARGUMENTS

N1       EQU   ARGUMNT1

N2       EQU   ARGUMNT2

A        EQU   ARGUMNT3

M        EQU   ARGUMNT4

N        EQU   ARGUMNT5

SETUP    EQU   CALLLIST      CLSETP CALL ARGUMENTS

KTAPE    EQU   ARGUMNT1

B        EQU   ARGUMNT2

NB       EQU   ARGUMNT3

C        EQU   ARGUMNT4

NC       EQU   ARGUMNT5

ND       EQU   ARGUMNT6

         END

*/

