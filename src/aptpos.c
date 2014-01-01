#include <stdlib.h>
#include <f2c.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#ifdef WIN32
#include <process.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#endif
#include "config.h"

#define QT(x) #x
#define QUOTE(x) QT(x)

#ifdef WIN32
#define DIRECTORY_PATH_SPACE _MAX_PATH
#else
#define DIRECTORY_PATH_SPACE 100
#endif

struct {
    doublereal ppname[20];
} apostp_;

struct {
    integer iptnly, itrcut, iwaven, kflag1, ltvmit, nclrec, nopost, noplot, 
    	    numpst, numptr, is3[3], kflags[9];
} asistm_;

struct {
    doublereal name__, krfsys;
    integer sum, jsuber, namsub, debug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

int aptpos_()
{
#ifdef WIN32
#define APTPOSARGLEN _MAX_PATH
#else
#define APTPOSARGLEN 8
#endif
#define ARGCOUNT 22
	char args[ARGCOUNT][APTPOSARGLEN+2]={{0}};
	int i,j,k,l;
	char* arg[ARGCOUNT]={0};
	char fullpath[DIRECTORY_PATH_SPACE +9] = { 0 };
#ifdef WIN32
	int len1, len2, cnt;
	char *psz;
#define CMDLINEBUFFERLEN (_MAX_PATH+256)
	char cmdLineBuffer[CMDLINEBUFFERLEN+2] = { 0 };
	char pathName[_MAX_PATH+2] = { 0 };
	char prognm[] = "callpost.bat";
#else
	char prognm[] = "/callpost";
	char* path=QUOTE(BINDIR);//configure replaces with actual value	
#endif

	i = 0;
	strcpy(args[i], prognm);
	arg[i] = args[i];

	for(i=1, j=0; j < (asistm_.numpst*2); i+=2, j+=2)
	{
		memcpy(args[i],&apostp_.ppname[j],6);
		//get rid of leading blanks:
		for(k=0,l=0;k<6;)
		{
			while(args[i][k]==' ')
			{
				++k;
			}
			while(args[i][k]!=0)
			{
				args[i][l]=args[i][k];
				++k, ++l;
			}
			while(l<7)
			{
				args[i][l]=0;
				++l;
			}
		}

		arg[i]=args[i];

		//machine number:
#ifdef WIN32
	    _snprintf(args[i+1], 8, "%i", (int)apostp_.ppname[i]);
		arg[i+1]=args[i+1];
#else
	    snprintf(args[i+1], 8, "%i", (int)apostp_.ppname[i]);
		arg[i+1]=args[i+1];
#endif
	}

	export_surf_end();//close print.tap

#ifdef WIN32
// For Windows, to invoke post there are at least two options:
//
//	1 - invoke post exe directly
//	2 - invoke a script file
//
//	Tested (1) and it works ok, but (2) gives a level of indirection and follows
//	crochet's original concept of invoking a shell script.
//
// For Windows, 'fullpath' needs to specify the name of an executable with either:
//
//		- prefixed with a full path
//		- reside in a folder specified in the PATH environment variable
//
// To invoke a Windows 'script' file (.BAT), the executable will be 'cmd.exe'
// To invoke a Javascript, the executable would be 'jscript.exe'
//
// We'll use a bat file named: CALLPOST.BAT
//
// For 'cmd.exe', we need to pass '/c' as the first arg.
//
// The 2nd arg needs to be a quoted string that contains what we'd enter at the command
// line if we were typing the invocation.
//
// When we get here, 'args' will contain the arglist from the MACHIN stmt.
//
// We need to concatenate these along with the name of the BAT file into a single string,
// which we can then use to reset the content of the args buffer(s) and the arg array.
//
// We can use just the bat file name here *if* we put the bat file's folder name
// in the PATH environment variable. Assuming we put our postprocessors in the
// same folder, we'll want to update the PATH env var anyway.
//
// One mod from the Linux version, we'll pass the cltape full path name as an arg
// to the postprocessor.
//
// So our command line should look like:
//
//	"callpost.bat <folder-name>\cl.tap MMPOST 1"
//
//	<folder-name> will actually be something like: C:\src\aptos\apt360\examples
	
	strcpy (fullpath, "\\windows\\system32\\cmd.exe");

	len1 = 0;
	len2 = 0;

	for (cnt = 0, i = 0; i < ARGCOUNT; i++, cnt++) // get arg count and total strlen
	{
		len1 = strlen(args[i]); // compute length of this arg

		if (0 == len1)
		{
			break;	// stop when we hit empty element
		}

		len2 += (len1 + 1); // accumulate total length plus one for the blank
	}

// clfile will be in the current working directory, so get the current working
// directory name and concat the clfile name to it so we have a full path name
// to the clfile.

	getcwd(pathName, _MAX_PATH);
	psz = pathName + strlen(pathName);
	strcat(psz, "\\cl.tap");

	len2 += strlen(pathName) + 1;

	if (len2 > CMDLINEBUFFERLEN)
	{
		fprintf(stderr,"[%s %d] ***** ERROR CMDLINE TOO LONG %d LIMIT %d *****\n",
			__FILE__, __LINE__, len2, CMDLINEBUFFERLEN);
	}

	psz = cmdLineBuffer;	// start building the cmd line string

	psz += sprintf(psz, "\"%s", prognm); // bat file name

	psz += sprintf(psz, " %s", pathName);	// cl file name

	for (i = 1; i < cnt; i++) // concatenate the machin parameters on to the cmd line
	{
		psz += sprintf(psz, " %s", args[i]);
	}

	strcat(psz, "\"");	// append terminating quote	- cmd line buffer complete

	arg[0] = "/c";		// cmd.exe parameter, execute next arg then exit
	arg[1] = cmdLineBuffer;		// name of bat file w/ bat file arg list
	arg[2] = 0;

// If debug is enabled then emit content to stdout.

	if (a1com_1.debug > 0)
	{
		fprintf(stdout, "[%s.%d] %s\n", __FILE__, __LINE__, fullpath);

		for (i=0; i<2; i++)
		{
			fprintf(stdout, "[%s.%d] %s\n", __FILE__, __LINE__, arg[i]);
		}
	}

// Let's flush the output buffers before we launch the process or we may lose stuff.

	fflush(stdout);
	fflush(stderr);

// Try to launch the batfile.

	if (_execv(fullpath, arg) == -1)
	{
		fprintf(stderr,"failed to launch postprocessor script\ncheck that script '%s' is in expected folder, errno = (%d, 0x%-.8X)\n", arg[0], errno, errno);
	}
#else
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
#endif
	return 0;

}


