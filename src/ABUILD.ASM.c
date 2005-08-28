/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
ABUILD   START 0
*      *
*      * ABUILD(A,ICHAR)
*      * SHIFTS DATA IN DOUBLE WORD 'A' LEFT 8 BITS
*      * AND INSERTS THE 8-BIT CODE WHICH IS RIGHT JUSTIFIED
*      * IN 'ICHAR' INTO THE SIXTH BYTE OF 'A'.
*      *
         ENTRY ABUILD
         PRINT ON
*      *
         LR    0,2                SAVE GR2
         LM    1,2,0(1)           A(A) IN GR1, A(ICHAR) IN GR2
         MVC   0(5,1),1(1)        SHIFT LEFT
         MVC   5(1,1),3(2)        INSERT CHARACTER
         LR    2,0                RESTORE GR2
         BCR   15,14              RETURN
         END
*/
#include <f2c.h>
#include <assert.h>
#include <stdio.h>

int abuild_(doublereal* a , integer* ichar)
{
	unsigned long long int space=' ';
	unsigned long long int b=0; 
	unsigned long long int* a_=(unsigned long long int*)a;

	*a_>>=8;
		
	*a_&=0xffff00ffffffffff ;
	b+=*ichar;
	b<<=40;
	space<<=56;
	*a_+=b;
	*a_+=space;
	
	return 0;
}

	//printf("before shift, *a_: 0x%x\n",*a_);
	//printf("after +char, *a_: 0x%x\n",*a_);
//	*a_&=0xffffffffff00ffff ;
	//printf("after and, *a_: 0x%x\n",*a_);
	//printf("*ichar : 0x%x\n",*ichar);
	//*a_<<=8;
//	char_<<=16;
	//char_>>=16;
	//printf("char after shift: 0x%x\n",char_);
	//*char_&=0x0000ff0000;
	//printf("char after and: 0x%x\n",char_);
	//printf("after shift, *a_: 0x%x\n",*a_);
