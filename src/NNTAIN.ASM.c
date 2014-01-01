#include <assert.h>

int nntain_(void* a, void* b, void*c)

{

	assert(0);

	return 0;

}

/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***

NNTAIN   START 0

*---------------------------------------------------------------------

* IF (NNTAIN (A,B,C))1,2,3 WHERE

* A IS ONE LIMIT OF THE CLOSED INTERVAL

* B IS THE FLOATING POINT NUMBER TO BE TESTED TO SEE IF IT FALLS

*        IN THE CLOSED INTERVAL

* C IS THE OTHER LIMIT OF THE CLOSED INTERVAL

* A,B,C ARE DOUBLE PRECISION FLOATING POINT NUMBERS

* A NUMERIC REPLY OF -1,0, OR 1 WILL BE PLACED IN GPR0

*---------------------------------------------------------------------

BASEREG1 EQU   12

CALLREG  EQU   11

ARGREG   EQU   3

         USING NNTAIN,BASEREG1

         USING CALLLIST,CALLREG

         USING ARGUMENT,ARGREG

         SAVE  (2,12),T,NNTAIN

         LR    BASEREG1,15

         LR    CALLREG,1

         L     3,C

         LD    6,VALUE       LOAD C VALUE INTO REG 6

         L     3,A

         LD    2,VALUE       LOAD A VALUE INTO REG 2

         CDR   2,6           COMPARE A VALUE TO C VALUE

         BH    ABIG          A VALUE IS GREATER THAN C VALUE

         BE    ERROR         A VALUE IS EQUAL TO C VALUE

         LDR   4,2      PLACE MIN (A VALUE) INTO REG 4; MAX IS IN REG 6

ISCINR   L     3,B

         LD    2,VALUE

         CDR   2,4           COMPARING B VALUE TO LOWER LIMIT

         BL    NO

         CDR   2,6           COMPARING B VALUE TO HIGHER LIMIT

         BH    NO

         B     YES

ABIG     LDR   4,6           PLACING C VALUE (MIN) INTO REG 4

         LDR   6,2           PLACING A VALUE (MAX) INTO REG 6

         B     ISCINR

ERROR    L     0,=F'0'       A VALUE IS EQUAL TO C VALUE

         B     RET

YES      L     0,=F'1'       B VALUE IS IN THE CLOSED INTERVAL

         B     RET

NO       L     0,=F'-1'      B VALUE IS NOT IN THE CLOSED INTERVAL

RET      RETURN (1,12),T

ARGUMENT DSECT

VALUE    DS    A

CALLLIST DSECT

A        DS    A

B        DS    A

C        DS    A

         CSECT

         END

*/

