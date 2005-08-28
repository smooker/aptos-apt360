/* AZCOR.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal adum[720], te[3], tek[3], tel[3], tes[3], ta[3], tak[3], tal[3]
	    , pmove[3], ti[3], tik[3], til[3], u2[3], uvec[3], vtem[3], cmove[
	    3], ex[3], ey[3], ez[3], vnul[3], tm[3], dir[3], axis[3], axis1[3]
	    , axis2[3], axis3[3], refpnt[3], rgt[3], fwd[3], up[3], zlnorm[3],
	     zlpnt[3], tndir[3], va[3], tmvcmp[3], p1[3], p2[3], pnt[3], pnt1[
	    3], oldu1[3], ogle[3], rzero[3], tanmot[3], tlend1[3], v[3], cend[
	    3], delmot[3], d2[3], dnmot[3], ax4[3], a, b, c__, ra, hi, alpha, 
	    gamma, cagl, sagl, com1, com4, costh, ctocl, diam, dif, difout, 
	    dinc, dp, dpe, dpi, dpl, dpmax, dp1, dpcnt, dsmov, d1, d2a, el1, 
	    el2, fipnt, flipck, hafdia, hchord, offset, prod1, prod2, psi, 
	    radno, rc1, rdrm, rdrn, rone, rzerol, save1, siuth, tangl, theta, 
	    alp, eps7, vamax, vl, zdotc, zgamma, zign, zl, zl1, zl2, znpts, 
	    tolbnd, cendis, cenlen, chord, abcd[2], acard[2], save[6], cutdat[
	    7], tem[10], temp[20], tcdat[260], qequiv[20], bdum[52], probuf[
	    100], cansto[2000];
    integer ier, instr1, instr2, nwds, icl, nrec, irecno, itrflg, nw, idummy;
} a2cmmn_;

#define a2cmmn_1 a2cmmn_

struct {
    doublereal tlhite[1], tanhi[1], tanlo[1], umax[1], r1[1], corrad[1], 
	    tcont[1], tlinc[65];
} a2ctdf_;

#define a2ctdf_1 a2ctdf_

struct {
    doublereal q15x01, qp9x01, qp6x01, qp5x01, qp4x01, qp0001, qp001, qp01, 
	    qp1, q1p, q10p, q1000p, q1pe5, q1pe6, q1pe10, q1pe20, q1pe30, 
	    q1pe36, q1pe38, qp8x01, qp7x01, qp4x09, qp9, qp99, qp995, qp997, 
	    qp999, qp9999, qp4x95, qp5x95, qp6x9, qp7x9, qp6x05, qp5x05, 
	    qp4x05, qp0005, qp005, qp05, qp5, q5p, q4x045, qp0002, qp0047, 
	    qp017, q1rad, qp0349, qp125, qp6, qp2, qp2499, qp25, qp3, qp7, 
	    qp75, qp8, qp866, q1p01, q1p1, q1p2, q1p25, q1p5, q2p, q2p5, q3p, 
	    q3p5, q4p, q8p, q11p, q45p, q90p, q130p, q4500p, q9000p, qp02, 
	    qnul, qpie, qfil[9];
} a2fpc_;

#define a2fpc_1 a2fpc_

/* Table of constant values */

static integer c__725 = 725;

/* Subroutine */ int azcor_(point, ibmind)
doublereal *point;
integer *ibmind;
{
    /* Local variables */
    static doublereal ans;
#define cosl ((doublereal *)&a2ctdf_1 + 2)
#define sinl ((doublereal *)&a2ctdf_1 + 1)
    extern /* Subroutine */ int aerr_(), avadd_(), atape_();
    static doublereal dspec, denom;
    extern /* Subroutine */ int avdot_();
    static doublereal vspec[3];
    extern /* Subroutine */ int avsub_();
    static doublereal anmov;
    extern /* Subroutine */ int avsto_(), astos_();
#define tlldat ((doublereal *)&a2ctdf_1 + 6)
    extern /* Subroutine */ int avmult_();

/*      CORRECTS COMPUTED CUTTER LOCATION FOR Z VALUE */
/*     MORE ACCURATELY8 MOVES CUTTER UP OR DOWN ALONG ITS AXIS */
/*      UNTIL THE CUTTER END POINT IS IN A PLANE PARALLEL TO */
/*      THE PART SURVACE PLANE, AND WHICH PLANE ALSO CONTAINS THE */
/*      ORIGINAL CUTTER END POINT TE , WHERE THE CUTTER WAS AT THE */
/*      START OF I-D PROCESSING */

/*      POINT IS THE  POINT TO BE CORRECTED */
/*      IBMIND HAS THREE VALUES     -1   FOR FIRST TIME IN MEANS */
/*      COMPUTE ONLY THE PLANE VECTOR AND D VALUE */
/*      0 MEANS NOT LAST POINT ... CORRECT AND OUTPUT */
/*      1 MEANS IS LAST POINT ... CORRECT, OUTPUT, AND FLUSH BUFFER */


/*      BRANCH ON INPUT SWITCH */
    /* Parameter adjustments */
    --point;

    /* Function Body */
    if (*ibmind != -1) {
	goto L10;
    }
/*      INITIALIZATION BRANCH */

    avdot_(&point[1], &a2cmmn_1.cansto[4], &dspec);
/*     COMPUTES VALUE OF D FOR SPECIAL PLANE */
/*      CHECK THAT TOOL AXIS IS NOT PARALLEL TO PS PLANE */
    avdot_(a2cmmn_1.ta, &a2cmmn_1.cansto[4], &denom);
/*      DENOM WILL BE USED IN THE LATER CALCULATIONS */
/*      REVERSE IT, AS WE WANT THE VECTOR TO POINT IN */
/*      THE NEGATIVE TOOL AXIS DIRECTION WHEN OFFSETTINE TO THE PALEN */
    denom = -denom;
    if (abs(denom) < a2fpc_1.qp001) {
	aerr_(&c__725);
    }
/*      SET UP PLANE VECTOR */
    avsub_(a2cmmn_1.vnul, a2cmmn_1.ta, vspec);
    return 0;
/*      NON INITIALIZATION BRANCH ... MAJE CORRECTION */
L10:
/*      THE CALCULATION IS MUCH THE SAME AS IN DDPLANE */
/*      COMPUTE THE DIRECTED DISTANCE TO THE SPECIAL PLANE FROM THE */
/*      CURRENT CUTTER LOCATION AND MOVE THE CUTTER THAT MUCH ALONE THE T */
    avdot_(&point[1], &a2cmmn_1.cansto[4], &ans);
    anmov = (dspec - ans) / denom;
    avmult_(vspec, &anmov, a2cmmn_1.vtem);
    avsto_(a2cmmn_1.te, a2cmmn_1.tek);
    avadd_(&point[1], a2cmmn_1.vtem, a2cmmn_1.te);
/*      OUTPUT */
    astos_();
/*      FLUSH BUFFER IF TOLD TO DO SO */
    if (*ibmind == 0) {
	return 0;
    }
    a2cmmn_1.ier = -10;
    atape_();
    a2cmmn_1.nw = 0;
    return 0;
} /* azcor_ */

#undef tlldat
#undef sinl
#undef cosl


