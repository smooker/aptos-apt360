//original 360 asm:
/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 ***
ARTIME   START 0
         ENTRY APTTIME
BASE     EQU   *
APTTIME  SAVE  (2,12),T
         USING BASE,2
         USING COM,3
         LR    2,15
         L     3,ADTIME
         LA    10,SAVEAREA
         ST    10,8(0,13)
         ST    13,SAVEAREA+4
         LR    13,10
         TIME  BIN
         ST    1,DATE
         O     0,FLPT
         ST    0,TEMP
         LD    0,TEMP
         AD    0,K0
         DD    0,CHUND
         STD   0,FLTIME
         TIME  DEC
         ST    0,CLOCKD
         UNPK  DATE1(8),DATE(4)   UNPACK TO F0F0F0FYFYFDFDFD
         MVC   DATE(2),DATE1+3
         MVC   DATE+2(1),PERIOD   DECIMAL POINT
         MVC   DATE+3(3),DATE1+5  DAY
         UNPK  CLOCKU(9),CLOCKD(5)  UNPACK TO FHFHFMFMFSFSFTFHF0
         MVC   CLOCK(2),CLOCKU  FHFH
         MVC   CLOCK+2(1),SLASH  FHFH/
         MVC   CLOCK+3(2),CLOCKU+2   FHFH/FMFM
         MVC   CLOCK+5(1),SLASH  FHFH/FMFM/
         MVC   CLOCK+6(2),CLOCKU+4  FHFH/FMFM/FSFS
         MVC   CLOCK+8(1),PERIOD  FHFH/FMFM/FSFS.
         MVC   CLOCK+9(2),CLOCKU+6  FHFH/FMFM/FSFS.FTFH
         L     13,SAVEAREA+4
         RETURN (14,12),T
         DS    0F
CLOCKD   DC    XL5'000000000F'
PERIOD   DC    XL1'4B'
SLASH    DC    XL2'6100'
FLPT     DC    XL4'46000000'
ADTIME   DC    V(ATIME)
SAVEAREA DC    18F'0'
DATE1    DC    D'0'
CLOCKU   DC    D'0'
TEMP     DC    D'0'
CHUND    DC    D'6000'
K0       DC    D'0'
COM      DSECT
FLTIME   DC    D'0'
DATE     DC    D'0'
CLOCK    DC    2D'0'
         END
*/
//end original 360 asm

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "f2c.h"
#include <assert.h>

/* Common Block Declarations */

struct {
    doublereal fltime, date, clock[2];
} atime_;

#define atime_1 atime_


int artime_()
{
	char array_dt[sizeof(doublereal)];
	char array_clck1[sizeof(doublereal)];
	char array_clck2[sizeof(doublereal)]={' ',' ',' ',' ',' ',' ',' ',' '};
	char array_temp[sizeof(doublereal)+1];

	time_t timer;
	struct tm timeStruct;
	time(&timer);

	timeStruct=*localtime(&timer);


	strftime(array_dt,sizeof(doublereal),"%d%b%y",&timeStruct);
	array_dt[7]=' ';//replace string-terminating zero


	sprintf(array_temp,"%2.2d:%2.2d:%2.2d",timeStruct.tm_hour,timeStruct.tm_min,timeStruct.tm_sec);
	memcpy(array_clck1,array_temp,sizeof(doublereal));	

	atime_1.date=*(doublereal*)array_dt;
	atime_1.clock[0]=*(doublereal*)array_clck1;
	atime_1.clock[1]=*(doublereal*)array_clck2;
	atime_.fltime=(doublereal)(timer)/60;

	return 0;
}

