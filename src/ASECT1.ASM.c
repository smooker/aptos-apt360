#include <assert.h>
#include <stdio.h>
#include <f2c.h>
#include "ASM.h"

extern void ataprd_(doublereal* tapeType, integer* ioflag, integer* nwrds, integer* param1, 
	integer* irecn, integer* param2, integer* hdr1, integer* param3, 
	integer* hdr2, integer* param4, integer* startAddress, integer* param5);


//--------TODO lots of ad hoc garbage in this routine----------------------


int atapwt_(doublereal* tapeType, integer* ioflag, integer* param1, integer* irecn,
	integer* param2, integer* hdr1, integer* param3, integer* hdr2,
	integer* param4, integer* startAddress, integer* lengthOfRecord, integer* tcdat, integer* nw,
	integer* deftab, integer* n)
{
	struct TapeHdr tapeHdr;
	FILE* filePtr=0;
	filePtr=getFilePtr(tapeType);
	if(!filePtr){
		printf("ASECT1.ASM.c: in atapwt: could not write to file \n");
		exit(1);
	}
	tapeHdr.irecn=*irecn;
	if(*param1==3){
		tapeHdr.recordLength=0;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
		if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1){
			*ioflag=0; 
			return 0;
		}
		return 0;
	} else if(*param1==4){

		tapeHdr.recordLength=*lengthOfRecord;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
		if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1){
			*ioflag=0; 
			return 0;
		}
		if(fwrite(startAddress ,sizeof(doublereal),*lengthOfRecord,filePtr)!=*lengthOfRecord)*ioflag=0;
		else *ioflag=-1;

		return 0;
	} else if(*param1==5){
		tapeHdr.recordLength=*nw + 2;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
		if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1){
			*ioflag=0; 
			return 0;
		}
		if(   (fwrite(startAddress ,sizeof(doublereal),2,filePtr)==2) &&
 			(fwrite(tcdat ,sizeof(doublereal),*nw,filePtr)==*nw) ) *ioflag=-1;
		else *ioflag=0;//probably should just exit here--if this flag set to zero, the program loops

		return 0;

	} else if(*param1==6){
			tapeHdr.recordLength=*n+2;
			tapeHdr.hdr1=*hdr1;
			tapeHdr.hdr2=*hdr2;
			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;
			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name
			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript
			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;
			return 0;

	}else {printf("in ASECT1:unknown error");exit(1);}
}




/*
int atapwt_(doublereal* tapeType, integer* ioflag, integer* param1, integer* irecn,
	integer* param2, integer* hdr1, integer* param3, integer* hdr2,
	integer* param4, integer* startAddress, integer* lengthOfRecord, integer* tcdat, integer* nw,
	integer* deftab, integer* n)
{
	struct TapeHdr tapeHdr;
	int debug;
	FILE* filePtr=0;
	filePtr=getFilePtr(tapeType);
	if(!filePtr){
		filePtr=fopen(getFileName(tapeType),"ab");
		freopen(getFileName(tapeType),"r+b",filePtr);
		if(!filePtr){
			printf("in atapwt: could not open file ");
			printf(getFileName(tapeType));
			printf("\n");
			return 0;
		}
		setFilePtr(tapeType,filePtr);
	}
	debug=ftell(filePtr);
	tapeHdr.irecn=*irecn;
	if(*param1==3){
		tapeHdr.recordLength=0;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	else if(*param1==5){
		tapeHdr.recordLength=*nw + 2;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	else if(*param1==6){
		if(fabs(*tapeType-3.)<.001){
			tapeHdr.recordLength=*hdr2;
			tapeHdr.hdr1=*hdr1;
			tapeHdr.hdr2=*deftab;
			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;
			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name
			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript
			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;
			return 0;
		}else if(fabs(*tapeType-2.)<.001){
			tapeHdr.recordLength=*n;
			tapeHdr.hdr1=*hdr1;
			tapeHdr.hdr2=*hdr2;
			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;
			//if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name
			//if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript
			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;
			return 0;
		}else{
			printf("****************************in section**********************\n");
			tapeHdr.recordLength=*hdr2;
			tapeHdr.hdr1=*hdr1;//ename
		}
	}
	else {
		tapeHdr.recordLength=*lengthOfRecord;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	

	if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1){
		*ioflag=0; 
		return 0;
	}

	debug=ftell(filePtr);
	if(*param1==3)return 0;

	if(*param1==5) {

		if(   (fwrite(startAddress ,sizeof(doublereal),2,filePtr)==2) &&
 			(fwrite(tcdat ,sizeof(doublereal),*nw,filePtr)==*nw) ) *ioflag=-1;
		else *ioflag=0;//probably should just exit here--if this flag set to zero, the program loops

	}else if(*param1==6) {
		if(fwrite(deftab,sizeof(doublereal),*hdr2,filePtr)!=*hdr2)*ioflag=0;
		else *ioflag=-1;
	
	}else {
		if(fwrite(startAddress ,sizeof(doublereal),*lengthOfRecord,filePtr)!=*lengthOfRecord)*ioflag=0;
		else *ioflag=-1;
	}

	debug=ftell(filePtr);
	fflush(filePtr); //debug only
	debug=ftell(filePtr);
	return 0;
}
*/
/*
//--------TODO lots of ad hoc garbage in this routine----------------------

int atapwt_(doublereal* tapeType, integer* ioflag, integer* param1, integer* irecn,
	integer* param2, integer* hdr1, integer* param3, integer* hdr2,
	integer* param4, integer* startAddress, integer* lengthOfRecord, integer* tcdat, integer* nw,
	integer* deftab, integer* n)
{
	struct TapeHdr tapeHdr;
	int debug;
	FILE* filePtr=0;
	filePtr=getFilePtr(tapeType);
	if(!filePtr){
		filePtr=fopen(getFileName(tapeType),"ab");
		freopen(getFileName(tapeType),"r+b",filePtr);
		if(!filePtr){
			printf("in atapwt: could not open file ");
			printf(getFileName(tapeType));
			printf("\n");
			return 0;
		}
		setFilePtr(tapeType,filePtr);
	}
	debug=ftell(filePtr);
	tapeHdr.irecn=*irecn;
	if(*param1==3){
		tapeHdr.recordLength=0;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	else if(*param1==5){
		tapeHdr.recordLength=*nw + 2;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	else if(*param1==6){
		if(fabs(*tapeType-3.)<.001){
			tapeHdr.recordLength=*hdr2;
			tapeHdr.hdr1=*hdr1;
			tapeHdr.hdr2=*deftab;
			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;
			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name
			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript
			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;
			return 0;
		}else if(fabs(*tapeType-2.)<.001){
			tapeHdr.recordLength=*n;
			tapeHdr.hdr1=*hdr1;
			tapeHdr.hdr2=*hdr2;
			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;
//			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name
//			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript
			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;
			return 0;
		}else{
			tapeHdr.recordLength=*hdr2;
			tapeHdr.hdr1=*hdr1;//ename
		}
	}
	else {
		tapeHdr.recordLength=*lengthOfRecord;
		tapeHdr.hdr1=*hdr1;
		tapeHdr.hdr2=*hdr2;
	}
	

	if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1){
		*ioflag=0; 
		return 0;
	}

	debug=ftell(filePtr);
	if(*param1==3)return 0;

	if(*param1==5) {

		if(   (fwrite(startAddress ,sizeof(doublereal),2,filePtr)==2) &&
 			(fwrite(tcdat ,sizeof(doublereal),*nw,filePtr)==*nw) ) *ioflag=-1;
		else *ioflag=0;//probably should just exit here--if this flag set to zero, the program loops

	}else if(*param1==6) {
		if(fwrite(deftab,sizeof(doublereal),*hdr2,filePtr)!=*hdr2)*ioflag=0;
		else *ioflag=-1;
	
	}else {
		if(fwrite(startAddress ,sizeof(doublereal),*lengthOfRecord,filePtr)!=*lengthOfRecord)*ioflag=0;
		else *ioflag=-1;
	}

	debug=ftell(filePtr);
	fflush(filePtr); //debug only
	debug=ftell(filePtr);
	return 0;
}
*/
//------------------------------
int tapech_(doublereal* replacedTape,doublereal* replacementTape)
{
	remove(getFileName(replacedTape));
	rename( getFileName(replacementTape),getFileName(replacedTape));
	return 0;
}
//------------------------------
int bufftp_(void* a,void* b)
{
//	assert(0);
	return 0;
}
//------------------------------
int search_(void* a,void* b, void* c)
{
//	assert(0);
	return 0;
}
//------------------------------
//param=1: rewind
//param=2: write eof
int atapop_(doublereal* tapeType,integer* param, integer* errFlag)
{
	FILE* file=getFilePtr(tapeType);
	if(!file){
		file=fopen(getFileName(tapeType),"ab");
		freopen(getFileName(tapeType),"r+b",file);
		setFilePtr(tapeType, file);
		return 0;
	}else{//file is open 
		if(*param==1)rewind(file);
		else if(*param==2)fputc(EOF ,file);
		else assert(0);
	}
	return 0;
}
//------------------------------
int dvchk_(integer* a)
{
	*a=1;
	return 0;
}
//------------------------------
int tapewt_(doublereal* a,integer* b,integer* c,integer* d,integer* e,integer* f,
		integer* g,integer* h,integer* i,integer* j,integer* k,integer* l)
{
	atapwt_(a,b,c,d,e,f,g,h,i,j,k,0,0,0,0);

	return 0;
}
//------------------------------
int taperd_(doublereal* tapeType, integer* ioflag, integer* nwrds, integer* param1, 
	integer* irecn, integer* param2, integer* hdr1, integer* param3, 
	integer* hdr2, integer* param4, integer* startAddress, integer* param5)

{
	ataprd_(tapeType, ioflag, nwrds, param1, irecn, param2, hdr1, param3, 
	hdr2, param4, startAddress, param5);
	return 0;
}
//------------------------------
int tapeop_ (doublereal* tapeType,integer* param, integer* errFlag)
{

	atapop_(tapeType,param, errFlag);

//	remove(getFileName(tapeType));
	return 0;

//	assert(0);
}
int aptout_()
{
//	assert(0);
	return 0;
}





/*
*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 2 ***
ASECT1 START 0
         ENTRY ATAPRD
         ENTRY ATAPOP
         ENTRY ATAPWT
         ENTRY ASERCH
         ENTRY ABUFTP
         ENTRY ATAPXC
         ENTRY ACRDPN
         ENTRY TAPERD
         ENTRY TAPEOP
         ENTRY TAPEWT
         ENTRY BUFFTP
         ENTRY IBCOM#
         ENTRY PDUMP,DUMP
         ENTRY TAPECH
         ENTRY CARDPN
         ENTRY SYSCOMON
         ENTRY ACNTRL
         ENTRY APTOUT
         ENTRY DVCHK,OVERFL
         ENTRY DCOS,DSIN,IHCERRM
         SAVE  (2,12),T,ASECT1
         USING ASECT1,12
         LR    12,15
         LA    10,SAVEAREA
         ST    10,8(0,13)
         ST    13,SAVEAREA+4
         LR    13,10
         MVC   ATAPRDAD(76),20(1)
         LM    2,6,0(1)
         LM    7,11,SYSCOMON
         MVC   0(92,7),0(2)     ATAPTB
         MVC   0(56,8),0(3)  A0CON
         MVC   0(88,9),0(4)  ASISTM
         MVC   0(160,10),0(5)  APOSTP
         STM   2,6,SECT0COM
         CALL  ASCNTL
         USING ACNTRL,12
ACNTRL   LR    12,15
         LM    2,6,SECT0COM
         LM    7,11,SYSCOMON
         MVC   0(92,2),0(7)
         MVC   0(56,3),0(8)
         MVC   0(88,4),0(9)
         MVC   0(160,5),0(10)
         SR    15,15
RET      L     13,SAVEAREA+4
         L     14,12(0,13)
         RETURN (0,12),T
SECT0COM DC    5F'0'
         USING APTOUT,15
APTOUT   L     12,ACNTRLAD
         L     1,RETAD
         BR    1
ACNTRLAD DC    A(ACNTRL)
RETAD    DC    A(RET)
         USING IHCERRM,15
IHCERRM  L     15,CERRMAD
         BR    15
         DS    0F
         USING IBCOM#,15
IBCOM#   B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         B     IBADD
         DS    H
         BAL   1,EX               INST. ADD.+4 INTO GR1
         BAL   1,EX               .
         BAL   1,EX               .
         BAL   1,EX               .
         BAL   1,EX               .
         BAL   1,EX               .
         BAL   1,EX               .
         BAL   1,EX               .
IBADD    LR    1,14               INST. ADD.+4 INTO GR1
EX       SL    1,FOUR             INST. ADD.
         L     15,AIBCOM     SET REAL IBCOM# ADDRESS IN 15
         BR    1                  EXEC. INST. AGAIN
         USING PDUMP,15
PDUMP    L     15,PDUMPAD
         BR    15
         USING *,15
DUMP     L     15,DUMPAD
         BR    15
         USING *,15
DVCHK    L     15,DVCHKAD
         BR    15
         USING *,15
OVERFL   L     15,OVERFLAD
         BR    15
         USING TAPERD,15
TAPERD   L     15,ATAPRDAD
         BR    15
         USING TAPEOP,15
TAPEOP   L     15,ATAPOPAD
         BR    15
         USING TAPEWT,15
TAPEWT   L     15,ATAPWTAD
         BR    15
         USING SEARCH,15
SEARCH   L     15,ASERCHAD
         BR    15
         USING BUFFTP,15
BUFFTP   L     15,ABUFTPAD
         BR    15
         USING TAPECH,15
TAPECH   L     15,ATAPXCAD
         BR    15
         USING CARDPN,15
CARDPN   L     15,ACRDPNAD
         BR    15
         USING DCOS,15
DCOS     L     15,DCOSAD
         BR    15
         USING DSIN,15
DSIN     L     15,DSINAD
         BR    15
IBSAVE   DS    16F
FOUR     DC    F'4'
ZERO     DC    H'0'
SYSCOMON DC    V(ATAPTB)
         DC    V(A0CON)
         DC    V(ASISTM)
         DC    V(APOSTP)
         DC    F'0'
ATAPRDAD DC    F'0'
ATAPOPAD DC    F'0'
ATAPWTAD DC    F'0'
ASERCHAD DC    F'0'
ABUFTPAD DC    F'0'
ATAPXCAD DC    F'0'
ACRDPNAD DC    F'0'
AIBCOM   DC    F'0'
PDUMPAD  DC    F'0'
DUMPAD   DC    F'0'
DVCHKAD  DC    F'0'
OVERFLAD DC    F'0'
DCOSAD   DC    F'0'
DSINAD   DC    F'0'
         DC    4F'0'
CERRMAD  DC    F'0'
SAVEAREA DC    18F'0'
ATAPRD   EQU   TAPERD
ATAPOP   EQU   TAPEOP
ATAPWT   EQU   TAPEWT
ASERCH   EQU   SEARCH
ABUFTP   EQU   BUFFTP
ATAPXC   EQU   TAPECH
ACRDPN   EQU   CARDPN
         END
*/
