#include "config.h"
#ifdef HAVE_DXFLIB_DL_DXF_H 
#include "export_surf.h"
using namespace std;
DL_WriterA dxfWriter("print.dxf");
DL_Dxf dxfWrite;
DL_Attributes attrib("surfaces",7,0.001,"CONTINUOUS");
static bool start=true;
void export_surf(int* idfsto,double* canon)
{
	
	if(start){
		dxfWrite.writeHeader(dxfWriter);
		dxfWriter.sectionEnd();
		dxfWriter.sectionEntities();
		start=false;	
	}

	switch(idfsto[1]){
		case 1:
		export_point(canon);
		break;	
		case 2:
		export_line(canon);
		break;	
		case 4:
		export_circle(canon);
		break;
		default:
	break;
	}

}
//--------------------------------------------------------------------------
void export_surf_end()
{
		if(start==false){
			dxfWriter.sectionEnd();
			dxfWriter.dxfEOF();
		}
}
//--------------------------------------------------------------------------
void export_point(double* canon)
{

	DL_PointData ptdata;
	ptdata.x=canon[3];
	ptdata.y=canon[4];
	ptdata.z=canon[5];

	dxfWrite.writePoint(dxfWriter,
                    ptdata,attrib);


}


//--------------------------------------------------------------------------
void export_circle(double* canon)
{
	
	DL_CircleData cirData(canon[3],canon[4],canon[5],canon[9]); 
	dxfWrite.writeCircle(dxfWriter, cirData,attrib);
}

//--------------------------------------------------------------------------
void export_line(double* canon)
{

	DL_PointData lowerLeft(-10000,-10000,0);
	DL_PointData upperRight(10000,10000,0);
	const double SMALL_DOUBLE=1e-10;

//		current limits:
//		 |-------|.upperRight
//		 |	 |
//     lowerLeft.|_______|

//convert normal form into points on the 
//current limits
//algorithm: considering the limits as a box, start 
//at one edge, say the right edge, and check for an 
//intersection inside the limits.  If one isn't found,
//check an adjacent side, say the top edge. If one isn't found,
//check the left side. If one still isn't found, then there are 
//no intersections with the box.
//Now check for the ending point.  Going in the same counter-
//clockwise direction, check the left ,bottom ,right,
//and top edge.
//If an intersection can't be found, than either an error occured
//or the line passes through the limit points only.
	double xs=upperRight.x;
	double ys;
	if(fabs(canon[4])>SMALL_DOUBLE){//guard against div /0
		ys=(canon[6]-xs*canon[3])/canon[4];	//derived from the normal form of a line
	}else ys=upperRight.x+1;//throw it out of range so the next checks fail

	if(ys<lowerLeft.y || ys>upperRight.y){//within limits?

		//no -ok, maybe the upper Right y limit works(top edge):
			ys=upperRight.y;
			if(fabs(canon[3])>SMALL_DOUBLE){
				xs=(canon[6]-ys*canon[4])/canon[3];
			}else xs=upperRight.x+1;
		if(xs<lowerLeft.x || xs>upperRight.x){//within limits?
			//no-ok, check the lower left x limit (left edge)
			xs=lowerLeft.x;
			if(fabs(canon[4])>SMALL_DOUBLE){
				ys=(canon[6]-xs*canon[3])/canon[4];	
			}//don't need to throw it out of range here; will have found a start pt. by now
			//if it's on the edges
			if(ys<lowerLeft.y || ys>upperRight.y){
				cerr<<"export_surf: warning- entity is out of bounds"<<endl;
//				exit(1);	
			}

		}
		
		
	}
	//now find the endpoint:
	double xe=lowerLeft.x;
	double ye;
	if(fabs(canon[4])>SMALL_DOUBLE){
		ye=(canon[6]-xe*canon[3])/canon[4];
	}else ye=lowerLeft.y-1;
	//try the left line limit:	
	if((ye<lowerLeft.y || ye>upperRight.y)
		||  (xe==xs && ye==ys)){//within limits? and not the start point?
		//ok, try the bottom line:
		ye=lowerLeft.y;

		if(fabs(canon[3])>SMALL_DOUBLE){
			xe=(canon[6]-ye*canon[4])/canon[3];
		}else xe=lowerLeft.x-1;

		if((xe<lowerLeft.x || xe>upperRight.x)
			||  (xe==xs && ye==ys)){//within limits? and not the start point?
			//ok, try the right line:
			xe=upperRight.x;
			if(fabs(canon[4])>SMALL_DOUBLE){
				ye=(canon[6]-xe*canon[3])/canon[4];
			}//else //ye=upperRight.y+1;
			if((ye<lowerLeft.y || ye>upperRight.y)
			||  (xe==xs && ye==ys)){//within limits? and not the start point?

				//ok, try the top line:
				ye=upperRight.y;
				if(fabs(canon[3])>SMALL_DOUBLE){
					xe=(canon[6]-ye*canon[4])/canon[3];
				}//else //ye=upperRight.y+1;
				if((xe<lowerLeft.x || xe>upperRight.x)
					||  (xe==xs && ye==ys)){//within limits? and not the start point?
					//give up
					cerr<<"export_surf: warning- entity is out of bounds"<<endl;
				//	exit(1);
				}
			}
		}
	}

	DL_LineData lineData(xs, ys, 0, xe, ye, 0);

	dxfWrite.writeLine(dxfWriter, lineData, attrib);


}
//--------------------------------------------------------------------------
#endif





