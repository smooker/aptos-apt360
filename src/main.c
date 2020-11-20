/* main.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"
#include <stdio.h>
#ifdef WIN32
#include "getopt.win.h"
#else
#include <getopt.h>
#endif
#ifdef HAVE_CONFIG_H
	#include "../config.h"	
#endif

/* Common Block Declarations */

static struct {
    real protap, cantap, cltape, poctap, plotap, srftap, tapes1, tapes2, 
	    tapes3, tapes4;
    integer intape, ioutap;
    real puntap;
} ataptb_;

#define ataptb_1 ataptb_

extern int xargc;
extern char **xargv;
int nopost_flag = 0;

void parse_args(void) {
    /* http://www.gnu.org/software/libc/manual/html_node/
             Getopt-Long-Option-Example.html#Getopt-Long-Option-Example
    */
    /* getopt_long stores the option index here. */
    int option_index = 0;
    int c;
    while (1) {
        static struct option long_options[] = {
            /* long opt with no argument */
            {"nopost", no_argument, &nopost_flag, 1},
            {0, 0, 0, 0}
        };
        c = getopt_long(xargc, xargv, "",
                long_options, &option_index);
        /* Detect the end of the options */
        if (c == -1)
            break;
        switch(c) {
            case 0:
                break;
            default:
                abort();
        }
    }
}
/*    for f2c */
/* Main program */ MAIN__()
//(c main() is in f2c lib)
{
    extern /* Subroutine */ int acntrl_();
/* L10: */
        parse_args();

#ifdef HAVE_CONFIG_H
	printf("\nAptos Version:\n");
	printf(PACKAGE_STRING);
	printf("\nreport bugs to ");
	printf(PACKAGE_BUGREPORT);
	printf("\n\n");
#endif
	acntrl_();
	return 0;
} /* MAIN__ */

