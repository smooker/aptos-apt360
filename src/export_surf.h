#ifndef EXPORT_SURF_H
#define EXPORT_SURF_H

#include "config.h"
#ifdef HAVE_DXFLIB_DL_DXF_H 
#include <stdio.h>
#include <iostream>
#include <string>
#include <dxflib/dl_dxf.h>
#include <dxflib/dl_writer_ascii.h>

//this function in c++ to link with c++ dxf libs
#ifdef __cplusplus
	extern "C"{
#endif
		void export_surf(int* idfsto,double* canon);
		void export_surf_end();
#ifdef __cplusplus
	}
#endif

void export_point(double* canon);
void export_circle(double* canon);
void export_line(double* canon);


#endif
#endif


