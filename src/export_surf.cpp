#include "config.h"
#include "export_surf.h"
#include <fstream>
using namespace std;
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
	compressName(reinterpret_cast<char*>(name));	
	memcpy(rec.name,name,7);
	rec.subscript=*sub;
	rec.size=*canonLength;
	printFile.write(reinterpret_cast<char*>(&rec),sizeof(CanonDataRec));
	canon+=3;
	for(int i=0; i<*canonLength;++i){
		printFile.write(reinterpret_cast<char*>(canon),sizeof(double));
		++canon;
	}
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
	tmp[j]=0;
	memcpy(name,tmp,8);
}
//--------------------------------------------------------------------------
void export_surf_end()
{
	
	printFile.close();
	
}
//--------------------------------------------------------------------------




 
