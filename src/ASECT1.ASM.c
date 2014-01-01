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

		if(fabs(*tapeType-2.)<.001){//pocket routine writes to cl tape

			tapeHdr.recordLength=*n+2;

			tapeHdr.hdr1=*hdr1;

			tapeHdr.hdr2=*hdr2;

			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;

			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//not used

			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//not used

			if(fwrite(deftab,sizeof(doublereal),*n,filePtr)!=*n)*ioflag=0;

		}else{//tabcyl

			tapeHdr.recordLength=*hdr2;

			tapeHdr.hdr1=*hdr1;

			tapeHdr.hdr2=*hdr2;

			if(fwrite(&tapeHdr ,sizeof(struct TapeHdr),1,filePtr)!=1)*ioflag=0;

			if(fwrite((doublereal*)startAddress,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//name

			if(fwrite((doublereal*)tcdat,sizeof(doublereal),1,filePtr)!=1)*ioflag=0;//subscript

			if(fwrite(deftab,sizeof(doublereal),*hdr2,filePtr)!=*hdr2)*ioflag=0;



		}

			return 0;



	}else {printf("in ASECT1:unknown error");exit(1);}

}

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

	return 0;



}

int aptout_()

{

	return 0;

}







