//original 360 assembler:

/*

*  ASMBLR

AFRESH   START 0

*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***

         USING *,15

         SAVE  (2,3),,AFRESH

         LM    2,3,ATAPTBAD     REG 2 = A(ATAPTB)   REG 3 = A(AFRESHTB)

         MVC   0(92,2),0(3)     REFRESH ATAPTB COMMON BLOCK

         RETURN (2,3)

ATAPTBAD DC    V(ATAPTB)

         DC    A(AFRESHTB)

AFRESHTB DS    0D

PROTAP   DC    XL8'01'

CANTAP   DC    XL8'02'

CLTAPE   DC    XL8'02'

POCTAP   DC    XL8'04'

PLOTAP   DC    XL8'08'

SRFTAP   DC    XL8'03'

TAPES1   DC    XL8'03'

TAPES2   DC    XL8'01'

TAPES3   DC    XL8'04'

TAPES4   DC    XL8'09'

INTAPE   DC    F'0005'

IOUTAP   DC    F'0006'

PUNTAP   DC    F'0007'

         END

*/

//end 360 asm



#include "f2c.h"



#include <assert.h>

#include <stdio.h>

/* Common Block Declarations */

static struct {

    doublereal protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2,

	     tapes3, tapes4;

    integer intape, ioutap, puntap;

} ataptb_;



#define ataptb_1 ataptb_



int afresh_()

{

	remove("poc.tap");

	remove("srf.tap");

	remove("plo.tap");

	remove("err.tap");

	remove("cl.tap");

	remove("pro.tap");

	remove("print.tap");

	//remove("cl.dxf");

	//remove("print.dxf");

	//remove("cl_print.dxf");





	ataptb_1.protap=1.;

	ataptb_1.cantap=2.;

	ataptb_1.cltape=2.;

	ataptb_1.poctap=4.;

	ataptb_1.plotap=8.;

	ataptb_1.srftap=3.;

	ataptb_1.tapes1=3.;

	ataptb_1.tapes2=1.;

	ataptb_1.tapes3=4.;

	ataptb_1.tapes4=9.;



	ataptb_1.intape=5 ;

	ataptb_1.ioutap=6 ;

	ataptb_1.puntap=7 ;

	//ie,read(5,.. write(6,...etc

	return 0;

}



