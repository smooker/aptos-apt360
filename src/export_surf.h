#ifndef EXPORT_SURF_H
#define EXPORT_SURF_H

#include "config.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

//	dump canon data values produced by the PRINT command into a binary file
//	usable by a post-processor
//
#ifdef __cplusplus
	extern "C"{
#endif
		void export_surf(int* idfsto, double* canon ,double* name, int* sub, int* canon_length);
		void export_surf_end();
#ifdef __cplusplus
	}
#endif
//enum is defined with the numbers apt360 stores in idfsto
enum Surfaces{ POINT=1, LINE, PLANE, CIRCLE, CYLINDER,ELLIPSE, HYPERBOLA, CONE, 
	GEN_CONIC, LOFT_CONIC, VECTOR,  MATRIX, SPHERE, QUADRIC, PATERN=18,
       	TABCYL, RULED_SURF=22
};

//	records will be written to a file with each record consisting of
//	a CanonDataRec and followed by the canon values of the entity
struct CanonDataRec{
	int size;
	Surfaces surfaceType;
	char name[7];	
	int subscript;
};
//then:
// double canon1, double canon2, etc.
  

//this just removes the spaces from the name to make it a more
//common c-string format
void compressName(char*);


#endif












