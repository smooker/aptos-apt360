#ifndef ASM_H
#define ASM_H
#include <stdio.h>
#include <assert.h>
#include <f2c.h>
#ifdef WIN32
#define fabs(x) (doublereal)abs(x)
#else
#include <math.h>
#endif


struct TapeHdr{
	integer irecn;//record number
	integer recordLength;
	integer hdr1,hdr2;
};

char* getFileName(doublereal* tapeType);

FILE* getFilePtr(doublereal* tapeType);

void setFilePtr(doublereal* tapeType, FILE* file);

#endif
