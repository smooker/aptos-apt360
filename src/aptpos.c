#include "../config.h"
#include <stdlib.h>
#include <f2c.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define QT(x) #x
#define QUOTE(x) QT(x)

#define DIRECTORY_PATH_SPACE 100
struct {
    doublereal ppname[20];
} apostp_;

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
    	    numpst, numptr, is3[3], kflags[9];
} asistm_;

int aptpos_(){

	
	char args[22][8]={{0}};
	int i,j,k,l;
	int decPt,sign;
	char* arg[22]={0};
	char fullpath[DIRECTORY_PATH_SPACE +9];
	char* prognm="/callpost";
	char* path=QUOTE(BINDIR);//configure replaces with actual value	

	strcpy(&args[0][0],"callpost");
	arg[0]=&args[0][0];
	for(i=1,j=0;j<(asistm_.numpst*2);i+=2,j+=2){
		memcpy(&args[i][0],&apostp_.ppname[j],6);
		//get rid of leading blanks:
		for(k=0,l=0;k<6;){
			while(args[i][k]==' '){
				++k;
			}
			while(args[i][k]!=0){
				args[i][l]=args[i][k];
				++k, ++l;
			}
			while(l<7){
				args[i][l]=0;
				++l;
			}
		}


		arg[i]=&args[i][0];
		//machine number:
		memcpy(&args[i+1][0],qecvt(apostp_.ppname[i],2,&decPt,&sign),8);
		//put a string terminating 0 at decimal pt:
		args[i+1][decPt]=0;
		arg[i+1]=&args[i+1][0];

	}
	export_surf_end();//close print.tap

	if(!fork()){
		if( (strlen(fullpath)) > (DIRECTORY_PATH_SPACE-1) ){
			fprintf(stderr,"error:directory path too long\n");	
			exit(1);
		}

		strcpy(fullpath,path);
		strcat(fullpath,prognm);
		execv(fullpath, arg);
		fprintf(stderr,"failed to start postprocessor script\ncheck that\
 script 'callpost' is installed in /usr/local/bin\n");
		
	}
	wait(0);
	return 0;

}


