/*

*  ASMBLR

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***

*

IBCLAS   START 0

*      *

*      * INTEGER FUNCTION IBCLAS(N)

*      * FUNCTION RETURN VARIABLE CONTAINS IN ITS 2TH AND 4TH BYTES

*      * THE 2ND AND 3TH BYTES OF ICLASS(N)

*      *

         ENTRY IBCLAS

         EXTRN AILMTB

*      *

         USING *,15

         L     1,0(0,1)           ADDRESS OF N

         L     1,0(0,1)            N IN GR1

         SR    0,0                 ZERO GR0

         SLL   1,2                 MULTIPLY FOR INTEGER*4 ARRAY

         A     1,ICLASS            ADD COMMON AREA ADDRESS

         IC    0,1(1)              INSERT 2ND BYTE OF ICLASS(N)

         SLL   0,16                INTO 2ND BYTE OF FUNC. RETURN VAR.

         IC    0,2(1)              INSERT 3RD BYTE INTO 4TH BYTE

         BCR   15,14               RETURN

ICLASS   DC    A(AILMTB+4796)      A(ICLASS-4)

         END

*/

#include <assert.h>

#include <f2c.h>



struct {

    doublereal elment[600];

    integer iclass[600], jlment;

} ailmtb_;

    

#define ailmtb_1 ailmtb_

integer ibclas_(integer* n)

{

//	assert(0);

	integer iclassn, byte4,byte2,ret; 

	//get the word at n:

	iclassn = ailmtb_1.iclass[*n-1];

	ret=0;

	byte2=iclassn & 0x00ff0000;

	byte4=(iclassn & 0x0000ff00)>>8;

	ret = byte4+byte2;



	return ret;

}



