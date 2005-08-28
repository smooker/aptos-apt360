
#include "ASM.h"

FILE* proTape=0;
FILE* clTape= 0;
FILE* pocTape=0;
FILE* ploTape=0;
FILE* srfTape=0;
FILE* errTape=0;


char* getFileName(doublereal* tapeType)
{

	if(fabs(*tapeType-1.)<.001)return "pro.tap";
	else if(fabs(*tapeType-2.)<.001)return "cl.tap";
	else if(fabs(*tapeType-3.)<.001)return "srf.tap";
	else if(fabs(*tapeType-4.)<.001)return "poc.tap";
	else if(fabs(*tapeType-8.)<.001)return "plo.tap";
	else if(fabs(*tapeType-9.)<.001)return "err.tap";
	else assert(0);

		return 0;
}
FILE* getFilePtr(doublereal* tapeType)
{

	if(fabs(*tapeType-1.)<.001)return proTape;
	else if(fabs(*tapeType-2.)<.001)return clTape;
	else if(fabs(*tapeType-3.)<.001)return srfTape;
	else if(fabs(*tapeType-4.)<.001)return pocTape;
	else if(fabs(*tapeType-8.)<.001)return ploTape;
	else if(fabs(*tapeType-9.)<.001)return errTape;
	else assert(0);
	return 0;

}
void setFilePtr(doublereal* tapeType, FILE* file){

	if(fabs(*tapeType-1.)<.001)proTape=file;
	else if(fabs(*tapeType-2.)<.001)clTape=file;
	else if(fabs(*tapeType-3.)<.001)srfTape=file;
	else if(fabs(*tapeType-4.)<.001)pocTape=file;
	else if(fabs(*tapeType-8.)<.001)ploTape=file;
	else if(fabs(*tapeType-9.)<.001)errTape=file;
	else assert(0);

}








