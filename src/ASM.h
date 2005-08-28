#ifndef ASM_H
#define ASM_H
#include <f2c.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>


struct TapeHdr{
	integer irecn;//record number
	integer recordLength;
	integer hdr1,hdr2;
};

char* getFileName(doublereal* tapeType);

FILE* getFilePtr(doublereal* tapeType);

void setFilePtr(doublereal* tapeType, FILE* file);

#endif
