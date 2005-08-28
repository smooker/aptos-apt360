/* AZVECT.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal refsys;
    integer name__, name1, jsuber, jsv, namsub, kdbug, indxpt, loop, ifini;
} a1com_;

#define a1com_1 a1com_

/* Subroutine */ int azvect_(v)
doublereal *v;
{
/*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 1 *** */
/* ...  THIS ROUTINE CHECKS THE X,Y,Z COMPONENTS */
/*     OF A VECTOR FOR SOME ABSOLUTE VALUE LESS THAN .000001 */
/*     IF SUCH IS THE CASE FOR ALL COMPONENTS, */
/* ...  JSUBER IS SET TO 1005 */

    /* Parameter adjustments */
    --v;

    /* Function Body */
    if (abs(v[1]) - (float)1e-6 <= 0.) {
	goto L10;
    } else {
	goto L40;
    }
L10:
    if (abs(v[2]) - (float)1e-6 <= 0.) {
	goto L20;
    } else {
	goto L40;
    }
L20:
    if (abs(v[3]) - (float)1e-6 <= 0.) {
	goto L30;
    } else {
	goto L40;
    }
L30:
    a1com_1.jsuber = 1005;
L40:
    return 0;
} /* azvect_ */

