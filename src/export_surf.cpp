#include "config.h"
//#ifdef HAVE_DXFLIB_DL_DXF_H 
#include "export_surf.h"
#include <fstream>
using namespace std;
/*
DL_WriterA dxfWriter("print.dxf");
DL_Dxf dxfWrite;
DL_Attributes attrib("surfaces",7,0.001,"CONTINUOUS");
DL_Attributes attribText("text",4,0.001,"CONTINUOUS");
static bool start=true;
*/

//DL_TextData text(x,y,z,xa,ya,za,.02,1,0,0,0,"text","STANDARD",0);
//void export_surf(int* idfsto,double* canon)
//


std::ofstream printFile;
void export_surf(int* idfsto, double* canon ,double* name, int* sub,int* canonLength)
{

	static bool start=true;
	if(start==true)printFile.open("print.tap",std::ios::binary);
	if(!printFile){
		cerr<<"could not open file 'print.tap'"<<endl;
		return;
	}else start=false;

	CanonDataRec rec;
	rec.surfaceType=static_cast<Surfaces>(idfsto[1]);
//	cout<<"surface type: "<<rec.surfaceType<<endl;
	compressName(reinterpret_cast<char*>(name));	
	memcpy(rec.name,name,7);
	rec.subscript=*sub;
//	cout<<"subscript: "<<rec.subscript<<endl;
	rec.size=*canonLength;
//	cout<<"rec size: "<<rec.size<<endl;
	printFile.write(reinterpret_cast<char*>(&rec),sizeof(CanonDataRec));
	canon+=3;
	for(int i=0; i<*canonLength;++i){
		printFile.write(reinterpret_cast<char*>(canon),sizeof(double));
		//cout<<"canon: "<<*canon<<endl;
		++canon;
	}


/*enum Surfaces{ POINT=1, LINE, PLANE, CIRCLE, CYLINDER,ELLIPSE, HYPERBOLA, CONE, 
	GEN_CONIC, LOFT_CONIC, VECTOR,  MATRIX, SPHERE, QUADRIC, PATERN=18,
       	TABCYL, RULED_SURF=22
};

struct CanonDataRec{
	Surfaces surfaceType;
	std::vector<float>canon;
	std::string name;	
	int subscript;
};
*/







//DL_TextData text(x,y,z,xa,ya,za,.02,1,0,0,0,"text","STANDARD",0);
//DL_TextData text(0,0,0,.1,0,0,.18,1,0,0,0,"******text*****","STANDARD",0);
//
////void DL_Dxf::writeText(DL_WriterA& dw,
 //                      const DL_TextData& data,
  //                     const DL_Attributes& attrib) 

/*	if(start){
		dxfWrite.writeHeader(dxfWriter);
		dxfWriter.sectionEnd();
		dxfWriter.sectionEntities();
		start=false;	
		*/
//dxfWrite.writeText(dxfWriter,text,attribText);
/*
	}

	switch(idfsto[1]){
		case 1:
		export_point(canon,name,sub);
		break;	
		case 2:
		export_line(canon,name,sub);
		break;	
		case 4:
		export_circle(canon,name,sub);
		break;
		default:
	break;
	}
*/
}

//-----remove blanks----------------------------------------------------------
void compressName(char* name)
{
	char tmp[8]={0};
	int j=0,i=0;
	while(i<8){
		while(name[i]==' ')++i;
		tmp[j]=name[i];
		++i;++j;
	}
	memcpy(name,tmp,8);
}
//--------------------------------------------------------------------------
void export_surf_end()
{
	
	cout<<"closing printFile"<<endl;
	printFile.close();
	/*
		if(start==false){
			dxfWriter.sectionEnd();
			dxfWriter.dxfEOF();
		}
		*/
}
//--------------------------------------------------------------------------
/*
void export_point(double* canon,double* name, int* sub)
{

	DL_PointData ptdata;
	ptdata.x=canon[3];
	ptdata.y=canon[4];
	ptdata.z=canon[5];

	dxfWrite.writePoint(dxfWriter,
                    ptdata,attrib);


}


//--------------------------------------------------------------------------
void export_circle(double* canon,double* name, int* sub)
{
	
	DL_CircleData cirData(canon[3],canon[4],canon[5],canon[9]); 
	dxfWrite.writeCircle(dxfWriter, cirData,attrib);
	std::string str((char*)name);
	DL_TextData text(canon[3],canon[4],canon[5],.1,0,0,.045,1,0,0,0,str,"STANDARD",0);
	dxfWrite.writeText(dxfWriter,text,attribText);


}

//--------------------------------------------------------------------------
void export_line(double* canon,double* name, int* sub)
{

	DL_PointData lowerLeft(-100,-100,0);
	DL_PointData upperRight(100,100,0);
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
*/
//#endif




 
