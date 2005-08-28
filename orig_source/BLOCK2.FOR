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

