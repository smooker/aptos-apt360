

#include <assert.h>

#include <stdio.h>

#include <f2c.h>

//    adyndp_(ab, &c__1, &c_b4);

/* Subroutine */ int bdyndp_();



void adyndp_(char* ab, integer c1, integer c2)

{

//	printf("in adyndp.......");

//	printf("%s\n",ab);

//	bdyndp_(ab,c1,c2);

//	assert(0);

}

void cdyndp_()

{

//	printf("in cdyndp.......\n");

//	assert(0);

}



/*

*     ASMBLR

*...  *** THIS PROGRAM CREATED FOR VERSION 4, MODIFICATION 0 ***

ADYNDP   START 0

         ENTRY CDYNDP

         USING ADYNDP,15

         ST    2,SAVEREG2

         L     2,COUNT

         BCT   2,UNDERMAX

         B     HITLIMIT           BRANCH IF HIT MAX NUMBER OF CALLS

         DC    X'C1C4E8D5C4D74040'

UNDERMAX ST    2,COUNT

         L     2,SAVEREG2

SWITCH1  BCR   15,14              RETURN IF BDYNDP NOT TO BE CALLED

         L     15,=V(BDYNDP)

         BR    15                 CALL BDYNDP

HITLIMIT BC    0,TEST51

         OI    HITLIMIT+1,X'F0'   TURN HITLIMIT BRANCH ON

         MVC   FIFTYONE,=F'51'    INITIALIZE TO 51

TEST51   L     2,FIFTYONE

         BCT   2,UNDER51

         B     CALLAERR           BRANCH IF MAX NUMBER + 50

UNDER51  ST    2,FIFTYONE

         MVC   ARGLIST(8),0(1)

         LA    1,ARGLIST

         L     2,SAVEREG2

         L     15,=V(BDYNDP)

         BR    15                 CALL BDYNDP

CALLAERR L     2,SAVEREG2

         MVC   COUNT(4),MAXCALLS

         NI    HITLIMIT+1,X'0F'

         LA    1,AERRARG

         L     15,=V(AERR)

         BR    15                 CALL AERR

         CNOP  0,4

CDYNDP   SAVE  (14,12),T,*

         L     15,START-CDYNDP(0,15)

         L     2,0(1)

         L     2,0(2)             GET VALUE OF FIRST ARGUMENT

         C     2,=F'2'

         BL    SETMAX             BRANCH IF FIRST ARGUMENT IS 1

         BE    SETCOUNT           BRANCH IF FIRST ARGUMENT IS 2

         L     2,4(1)             FIRST ARGUMENT MUST BE 3

         L     2,0(2)             GET VALUE OF SECOND ARGUMENT

         LTR   2,2

         BC    8,SETOFF           BRANCH IF SECOND ARGUMENT IS 0

         NI    SWITCH1+1,X'0F'    SET SWITCH1 TO CALL BDYNDP

         B     DONE

SETOFF   OI    SWITCH1+1,X'F0'    SET SWITCH1 TO RETURN

DONE     RETURN (14,12),T

SETMAX   L     2,4(1)

         MVC   MAXCALLS(4),0(2)   STORE 2ND ARGUMENT IN MAXCALLS

         RETURN (14,12),T

SETCOUNT MVC   COUNT(4),MAXCALLS  RESET MAX NUMBER OF CALLS

         NI    HITLIMIT+1,X'0F'   TURN HITLIMIT BRANCH OFF

         RETURN (14,12),T

MINUSTWO DC    F'-2'

FIFTYONE DC    F'51'

COUNT    DC    F'500000'

MAXCALLS DC    F'500000'

ARGLIST  DC    2F'0'

         DC    X'80',AL3(MINUSTWO)

AERRARG  DC    X'80',AL3(K2202)

K2202    DC    F'2202'

SAVEREG2 DC    F'0'

START    DC    A(ADYNDP)

         END

*/

