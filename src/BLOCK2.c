
/*  original fortran: 
      BLOCK DATA
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 2, MODIFICATION 0 ***
      INTEGER*2 I
      COMMON/ADATA1/A(12),J(2),I(42)
       DATA A/
C
C...       ANODEF,       BLANX,        BLANKS,
     1 4H  NO,4HDEFX,4H0000,4H0   ,4H    ,4H    ,
C
C...       SYN,          TLAXIS,       DUMMY,
     2 4H   S,4HYN  ,4HTLAX,4HIS  ,4H(IDU,4HMMY)/,
C
C...       PLENT
     3 J/   7,3/,
C
C...       LOOPST, LOOPND, MACRO,  NTRMAC, NCALL,  LAPTH,
     4 I/   1,11,   2,11,   1,14,   2,14,   1,7,   0,1540,
C
C...        JAPTH,  IPLUS,  NCOMMA,   IFF,  IC(1),  IC(2),
     5      0,1796, 0,260,  0,2308,   1,9,  0,2564, 0,260,
C
C...        IC(3),  IC(4),  IC(5),  IC(6),  IC(7),  IC(8),
     6      0,516,  0,1028, 0,1284, 0,2308, 0,1540, 0,1796,
C
C...        IC(9),  IC(10),  LLASS
     7      0,2052, 0,772,   3,6146/
       END
*/
/* BLOCK2.f -- translated by f2c (version 20000121).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct adata1_1_ {
    real a[12];
    integer j[2];
    shortint i__[42];
};

#define adata1_1 (*(struct adata1_1_ *) &adata1_)

/* Initialized data */
/*
struct {
    char e_1[48];
    integer e_2[2];
    shortint e_3[42];
    } adata1_ = { 
							//--aka:---
		{' ', ' ', 'N', 'O','D', 'E', 'F', 'X',	//anodef 
		'0', '0', '0', '0', '0', ' ', ' ', ' ', //blanx
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', //blanks
		' ', ' ', ' ', 'S', 'Y', 'N', ' ', ' ', //syn
		'T', 'L', 'A', 'X', 'I', 'S', ' ', ' ', //tlaxis
		'(', 'I', 'D', 'U', 'M', 'M', 'Y', ')'}, //dummy
		7, 3, //plent
		1, 11, //loopst
		2, 11, //loopnd
		1, 14,//macro
		2, 14,//ntrmac
		1, 7,//ncall
		0, 1540, //lapth
		0, 1796, //japth
		0, 260,//iplus
		0, 2308, //ncomma
		1, 9, //iff
		0, 2564,//ic(1)
		0, 260, //ic(2)
		0, 516, //ic(3)
		0, 1028, //ic(4)
		0, 1284, //ic(5)
		0, 2308, //ic(6)
		0, 1540, //ic(7)
		0, 1796,//ic(8)
		0, 2052, //ic(9)
		0, 772, //ic(10)
		3, 6146 }; //llass
*/
struct {
    char e_1[48];
    integer e_2[2];
    shortint e_3[42];
    } adata1_ = { 
							//--aka:---
		{' ', ' ', 'N', 'O','D', 'E', 'F', 'X',	//anodef 
		'0', '0', '0', '0', '0', ' ', ' ', ' ', //blanx
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', //blanks
		' ', ' ', ' ', 'S', 'Y', 'N', ' ', ' ', //syn
		'T', 'L', 'A', 'X', 'I', 'S', ' ', ' ', //tlaxis
		'(', 'I', 'D', 'U', 'M', 'M', 'Y', ')'}, //dummy
//next values are reversed for little endian format
		3, 7, //plent
		11, 1, //loopst
		11, 2, //loopnd
		14, 1,//macro
		14, 2,//ntrmac
		7, 1,//ncall
		1540, 0, //lapth
		1796, 0, //japth
		260, 0,//iplus
		2308, 0, //ncomma
		9, 1, //iff
		2564, 0,//ic(1)      0xa04
		260, 0, //ic(2) '+'  0x104
		516, 0, //ic(3)	'-'  0x204
		1028, 0, //ic(4)     0x404
		1284, 0, //ic(5)"**"? 0x504
		2308, 0, //ic(6) ',' 0x904
		1540, 0, //ic(7) '(' 0x604
		1796, 0,//ic(8)  ')' 0x704
		2052, 0, //ic(9) '=' 0x804
		772, 0, //ic(10) '/' 0x304
		6146 , 3}; //llass
