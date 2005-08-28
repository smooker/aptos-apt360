/* ASTORE.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

//n1=length of iarg1
//n2=length of iarg2
//store iarg1 into iarg2
/* Subroutine */ int astore_(iarg1, n1, iarg2, n2)
integer *iarg1, *n1, *iarg2, *n2;
{
 //   /* System generated locals */
//    integer i__1;

  //  /* Local variables */
 //   static integer i__, k, k1, k2, k3;

   // /* Parameter adjustments */
  //  --iarg2;
//    --iarg1;

    ///* Function Body */
 //   if (*n2 != 8) {
//	goto L10;
 //   }
  //  for (i__ = 1; i__ <= 2; ++i__) {
///* L5: */
//	iarg2[i__] = 0;
 //   }
  //  if (*n1 == 2) {
//	k2 = 2;
 //   }
  //  if (*n1 == 4) {
//	k2 = 2;
 //   }
  //  if (*n1 == 8) {
//	k2 = 1;
 //   }
  //  k1 = 1;
   // goto L20;
//L10:
 //   k1 = 2;
  //  k2 = 1;
//L20:
 //   k3 = 3 - max(k1,k2);
  //  if (*n2 == -4) {
//	k1 = 1;
 //   }
  //  i__1 = k3;
   // for (k = 1; k <= i__1; ++k) {
//	iarg2[k2] = iarg1[k1];
//	++k1;
//	++k2;
///* L30: */
 //   }
  //  return 0;
} /* astore_ */
