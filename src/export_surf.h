#ifndef EXPORT_SURF_H
#define EXPORT_SURF_H

#include "config.h"
#ifdef HAVE_DXFLIB_DL_DXF_H 
#include <stdio.h>
#include <iostream>
#include <string>
#include <dxflib/dl_dxf.h>
#include <dxflib/dl_writer_ascii.h>
#include <vector>

//this function in c++ to link with c++ dxf libs
#ifdef __cplusplus
	extern "C"{
#endif
//		void export_surf(int* idfsto,double* canon);
		void export_surf(int* idfsto, double* canon ,double* name, int* sub);

		void export_surf_end();
#ifdef __cplusplus
	}
#endif
//enum is defined with the numbers apt360 stores in idfsto
enum Surfaces{ POINT=1, LINE, PLANE, CIRCLE, CYLINDER,ELLIPSE, HYPERBOLA, CONE, 
	GEN_CONIC, LOFT_CONIC, VECTOR,  MATRIX, SPHERE, QUADRIC, PATERN=18,
       	TABCYL, RULED_SURF=22
};
struct CanonDataRec{
	Surfaces surfaceType;
	std::vector<float>canon;
	std::string name;	
	int subscript;
};




void export_point(double* canon, double* name, int* sub);
void export_circle(double* canon, double* name, int* sub);
void export_line(double* canon, double* name, int* sub);


#endif
#endif












