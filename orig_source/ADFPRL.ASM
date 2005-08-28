*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
*     /ADFPRL/ PROGRAM
         PRINT ON,DATA
         DS    0F
ADFPRL   CSECT
*
*
*      INDEX TO THE FIRST LOCATION IN THIS TABLE AND THE NUMBER
*         OF DEFINITION FORMATS LISTED FOR EACH SURFACE TYPE
A        DC    Y((A10-A)/4+1,12)                  POINT
         DC    Y((A20-A)/4+1,17)                  LINE
         DC    Y((A30-A)/4+1,8)                   PLANE
         DC    Y((A40-A)/4+1,13)                  CIRCLE
         DC    Y((A50-A)/4+1,4)                   CYLINDER
         DC    Y((A60-A)/4+1,1)                   ELLIPS
         DC    Y((A70-A)/4+1,1)                   HYPERBOLA
         DC    Y((A80-A)/4+1,1)                   CONE
         DC    Y((A90-A)/4+1,3)                   GCONIC
         DC    Y((A100-A)/4+1,6)                  LCONIC
         DC    Y((A110-A)/4+1,12)                 VECTOR
         DC    Y((A120-A)/4+1,37)                 MATRIX
         DC    Y((A130-A)/4+1,6)                  SPHERE
         DC    Y((A140-A)/4+1,1)                  QADRIC
         DC    H'0,0'                             POLCON
         DC    Y((L100-A)/4+1,5)                  LOFT
         DC    H'0,0'              TOOL(17)
         DC    H'0,0'              PATERN(18)
         DC    Y((A160-A)/4+1,1)                  TABCYL
         DC    Y((A170-A)/4+1,1)                  MESH
         DC    Y((A180-A)/4+1,1)                  CONSEC
         DC    Y((A190-A)/4+1,1)                  RLDSRF
*
*
*   POINTS                                           APOINT   A1238000
*
*     P1 = POINT/X,Y
A10      DC    H'2,2'                             P1
         DC    Y((A101-A)/4+1,2)
         DC    H'300,2,300,3'
*
*     P1A = POINT/X,Y,Z
A101     DC    H'3,3'                             P1A
         DC    Y((A102-A)/4+1,1)
         DC    H'300,2,300,3,300,4'
*
*     P2 = POINT/INTOF,LN1,LN2
A102     DC    H'3,11'                            P2
         DC    Y((A103-A)/4+1,3)
         DC    H'5,2,202,3,202,8'
*
*     P3 = POINT/X- OR YLARGE OR SMALL ,  INTOF,LN1,CIR1
A103     DC    H'4,15'                            P3
         DC    Y((A104-A)/4+1,4)
         DC    H'121,2,5,3,202,4,204,9'
*
*     P4 = POINT/ X- OR YLARGE OR SMALL, INTOF,CIR1,CIR2
A104     DC    H'4,18'                            P4
         DC    Y((A105-A)/4+1,5)
         DC    H'121,2,5,3,204,4,204,12'
*
*     P5 = POINT/CIR1,ATANGL,A
A105     DC    H'3,10'                            P5
         DC    Y((A106-A)/4+1,6)
         DC    H'204,2,1,10,300,11'
*
*     P6 = POINT/CENTER,CIR1
A106     DC    H'2,9'                             P6
         DC    Y((A107-A)/4+1,7)
         DC    H'2,2,204,3'
*
*    P7 = POINT/ X- OR YLARGE OR SMALL, INTOF,LN1, ANY OF THE SURFACES$
*                           TAKING THE QUADRIC CANONICAL FORM
A107     DC    H'4,18'                            P7
         DC    Y((A108-A)/4+1,8)
         DC    H'121,2,5,3,202,4,-206,9,-207,9,-209,9,-210,9,214,9'
*
*     P8 = POINT/INTOF,PLN1,PLN2,PLN3
A108     DC    H'4,16'                            P8
         DC    Y((A109-A)/4+1,9)
         DC    H'5,2,203,3,203,8,203,13'
*
*     P9 = POINT/ RTHETA, XY- OR YZ OR ZXPLAN, R,A
*             OR
*     P9 = POINT/THETAR, XY- OR YZ- OR ZXPLAN, A,R
A109     DC    H'4,4'                             P9
         DC    Y((A111-A)/4+1,10)
         DC    H'121,2,121,3,300,4,300,5'
*
*     P10 = POINT/INTOF,LN1,TBC1,PT1
A111     DC    H'4,0'                             P10
         DC    Y((A112-A)/4+1,11)
         DC    H'5,2,202,3,250,8,201,0'
*
*     P11 = POINT/PAT1,N
A112     DC    H'2,0'
         DC    Y(0,12)
         DC    H'218,2,300,0'
*
*
*    LINES                                       ALINE     A1239000
*
*     L1 = LINE/X1,Y1,X2,Y2
A20      DC    H'4,4'                             L1
         DC    Y((A201-A)/4+1,2)
         DC    H'300,2,300,3,300,4,300,5'
*
*     L1A = LINE/PT1,PT2
A201     DC    H'2,8'                             L1A
         DC    Y((A202-A)/4+1,3)
         DC    H'201,2,201,6'
*
*     L1B = LINE/X1,Y1,Z1,X2,Y2,Z2
A202     DC    H'6,6'                             L1B
         DC    Y((A203-A)/4+1,1)
         DC    H'300,2,300,3,300,4'
         DC    H'300,5,300,6,300,7'
*
*     L2 = LINE/PT1, RIGHT OR LEFT, TANTO,CIR1
A203     DC    H'4,14'
         DC    Y((A204-A)/4+1,4)
         DC    H'201,2,121,6,27,7,204,8'
*
*     L3 = LINE/ RIGHT OR LEFT, TANTO,CIR1,RIGHT OR LEFT, TANTO,CIR2
A204     DC    H'6,20'                            L3
         DC    Y((A205-A)/4+1,5)
         DC    H'121,2,27,3,204,4'
         DC    H'121,12,27,13,204,14'
*
*     L4 = LINE/PT1,ATANGL OR SLOPE, A
A205     DC    H'3,6'                             L4
         DC    Y((A206-A)/4+1,6)
         DC    H'201,2,-1,6,47,6,300,7'
*
*     L5 = LINE/PT1,ATANGL OR SLOPE, A,LN1
A206     DC    H'4,11'                            L5
         DC    Y((A207-A)/4+1,11)
         DC    H'201,2,-1,6,47,6,300,7,202,8'
*
*     L6 = LINE/PT1,PARLEL,LN1
A207     DC    H'3,10'
         DC    Y((A208-A)/4+1,7)
         DC    H'201,2,17,6,202,7'
*
*     L7 = LINE/PT1,PERPTO,LN1
A208     DC    H'3,10'                            L7
         DC    Y((A209-A)/4+1,8)
         DC    H'201,2,18,6,202,7'
*
*     L8 = LINE/PARLEL,LN1, X- OR YLARGE OR SMALL, D
A209     DC    H'4,8'                             L8
         DC    Y((A210-A)/4+1,9)
         DC    H'17,2,202,3,121,8,300,9'
*
*     L9 = LINE/INTOF,PLN1,PLN2
A210     DC    H'3,11'                            L9
         DC    Y((A211-A)/4+1,12)
         DC    H'5,2,203,3,203,8'
*
*     L14A = LINE/ ATANGL OR SLOPE,A,INTERC,B
A211     DC    H'4,4'                             L10
         DC    Y((A212-A)/4+1,10)
         DC    H'-1,2,47,2,300,3,46,4,300,5'
*
*     L11 = LINE/PT1,TANTO,TBC1,PT2
A212     DC    H'4,0'                             L11
         DC    Y((A213-A)/4+1,13)
         DC    H'201,2,27,6,250,7,201,0'
*
*     L12 = LINE/PT1,PERPTO,TBC1,PT2
A213     DC    H'4,0'                             L12
         DC    Y((A214-A)/4+1,13)
         DC    H'201,2,18,6,250,7,201,0'
*
*      L13 = LINE/XAXIS OR YAXIS
A214     DC    H'1,1'
         DC    Y((A215-A)/4+1,14)
         DC    H'-84,2,85,2'
*
*     L14 = LINE/ATANGL OR SLOPE, A,INTERC, XAXIS OR YAXIS, B
A215     DC    H'5,5'
         DC    Y((A216-A)/4+1,15)
         DC    H'-1,2,47,2,300,3,46,4'
         DC    H'-84,5,85,5,300,6'
*
*     L15 = LINE/PNT1,ATANGL OR SLOPE, A,XAXIS OR YAXIS
A216     DC    H'4,7'
         DC    Y(0,16)
         DC    H'201,2,-1,6,47,6'
         DC    H'300,7,-84,8,85,8'
*
*
*   PLANES                               APLAN    A1240000
*
*     PL1 = PLANE/A,B,C,D
A30      DC    H'4,4'                             PL1
         DC    Y((A301-A)/4+1,1)
         DC    H'300,2,300,3,300,4,300,5'
*
*     PL2 = PLANE/PT1,PT2,PT3
A301     DC    H'3,12'                            PL2
         DC    Y((A302-A)/4+1,2)
         DC    H'201,2,201,6,201,10'
*
*     PL3 = PLANE/PT1,PARLEL,PLN1
A302     DC    H'3,10'                            PL3
         DC    Y((A303-A)/4+1,3)
         DC    H'201,2,17,6,203,7'
*
*     PL4 = PLANE/PARLEL,PLN1, X- OR Y- OR ZLARGE OR SMALL,D
A303     DC    H'4,8'                             PL4
         DC    Y((A304-A)/4+1,4)
         DC    H'17,2,203,3,121,8,300,9'
*
*     PL5 = PLANE/PT1,PERPTO,VEC1
A304     DC    H'3,9'                             PL5
         DC    Y((A305-A)/4+1,5)
         DC    H'201,2,18,6,211,7'
*
*     PL6 = PLANE/PERPTO,PLN1,PT1,PT2  (ORIGINAL FORMAT)
A305     DC    H'4,14'                            PL6
         DC    Y((A306-A)/4+1,6)
         DC    H'18,2,203,3,201,8,201,12'
*
*     PL7 = PLANE/PT1,PT2,PERPTO,PL1  (ALTERNATE FORMAT)
A306     DC    H'4,14'
         DC    Y((A307-A)/4+1,7)
         DC    H'201,2,201,6,18,10,203,11'
*
*     PL8 = PLANE/PT1,PERPTO,PL1,PL2
A307     DC    H'4,15'
         DC    Y(0,8)
         DC    H'201,2,18,6,203,7,203,12'
*
*
*   CIRCLES                                        ACIRCL   A1241000
*
*     C1 = CIRCLE/X,Y,Z,R
A40      DC    H'4,4'                             C1
         DC    Y((A401-A)/4+1,1)
         DC    H'300,2,300,3,300,4,300,5'
*
*     C1A = CIRCLE/X,Y,R
A401     DC    H'3,3'                             C1A
         DC    Y((A402-A)/4+1,2)
         DC    H'300,2,300,3,300,4'
*
*     C1B = CIRCLE/CENTER,PT1,RADIUS,R
A402     DC    H'4,7'                             C1B
         DC    Y((A403-A)/4+1,3)
         DC    H'2,2,201,3,23,7,300,8'
*
*     C1C = CIRCLE/CENTER,X,Y,Z,RADIUS,R
A403     DC    H'6,6'                             C1C
         DC    Y((A404-A)/4+1,4)
         DC    H'2,2,300,3,300,4'
         DC    H'300,5,23,6,300,7'
*
*     C2 = CIRCLE/CENTER,PT1,TANTO,LN1
A404     DC    H'4,11'                            C2
         DC    Y((A405-A)/4+1,5)
         DC    H'2,2,201,3,27,7,202,8'
*
*     C3 = CIRCLE/CENTER,PT1,PT2
A405     DC    H'3,9'                             C3
         DC    Y((A406-A)/4+1,6)
         DC    H'2,2,201,3,201,7'
*
*     C4 = CIRCLE/PT1,PT2,PT3
A406     DC    H'3,12'                            C4
         DC    Y((A407-A)/4+1,7)
         DC    H'201,2,201,6,201,10'
*
*     C5 = CIRCLE/CENTER,PT1,LARGE OR SMALL, TANTO, CIRCLE
A407     DC    H'5,15'
         DC    Y((A408-A)/4+1,8)
         DC    H'2,2,201,3,121,7,27,8,204,9'
*
*     C6 = CIRCLE/ X- OR YLARGE OR SMALL, LN1, X- OR YLARGE OR SMALL, $
*                  LN2,RADIUS,R
A408     DC    H'6,14'                            C6
         DC    Y((A409-A)/4+1,10)
         DC    H'121,2,202,3,121,8'
         DC    H'202,9,23,14,300,15'
*
*     C7 = CIRCLE/ TANTO,LN1, X- OR YLARGE OR SMALL, PT1,RADIUS,R
A409     DC    H'6,13'                            C7
         DC    Y((A410-A)/4+1,9)
         DC    H'27,2,202,3,121,8'
         DC    H'201,9,23,13,300,14'
*
*     C8 = CIRCLE/ X- OR YLARGE OR SMALL, LN1,X- OR YLARGE OR SMALL, $
*                 IN OR OUT,CIR1,RADIUS,R
A410     DC    H'7,18'                            C8
         DC    Y((A411-A)/4+1,12)
         DC    H'121,2,202,3,121,8'
         DC    H'121,9,204,10,23,18,300,19'
*
*     C9 = CIRCLE/ X- OR YLARGE OR SMALL,IN OR OUT,CIR1,IN OR OUT,  $
*                     CIR2,RADIUS,R
A411     DC    H'7,21'                            C9
         DC    Y((A412-A)/4+1,11)
         DC    H'121,2,121,3,204,4'
         DC    H'121,12,204,13,23,21'
         DC    H'300,22'
*
*     C10 = CIRCLE/TANTO,LN1, X- OR YLARGE OR SMALL,TBC1, X- OR YLARGE$
*                  OR SMALL,PT1,RADIUS,R
A412     DC    H'8,0'                             C10
         DC    Y(0,13)
         DC    H'27,2,202,3,121,8,250,9'
         DC    H'121,0,201,0,23,0,300,0'
*
*
*    CYLINDERS                                  ACYLND    A1242000
*
*     CYL2 = CYLINDER/PT1,DX,DY,DZ,R
A50      DC    H'5,8'
         DC    Y((A501-A)/4+1,1)
         DC    H'201,2,300,6,300,7,300,8,300,9'
*
*     CYL3 = CYLNDR/PT1,VEC1,R
A501     DC    H'3,9'
         DC    Y((A502-A)/4+1,2)
         DC    H'201,2,211,6,300,10'
*
*     CYL4 = CYLNDER/X,Y,Z,VEC1,R
A502     DC    H'5,8'
         DC    Y((A503-A)/4+1,3)
         DC    H'300,2,300,3,300,4,211,5,300,9'
*
*     CYL5 = CYLNDR/X,Y,Z,DX,DY,DZ,R
A503     DC    H'7,7'
         DC    Y(0,4)
         DC    H'300,2,300,3,300,4,300,5,300,6,300,7,300,8'
*
*
*        ELLIPSE                            AELP01    A1243000
*
*     ELL1 = ELLIPS/CENTER,PT1,M,N,ANG
A60      DC    H'5,8'                             ELLIPS
         DC    Y(0,1)
         DC    H'2,2,201,3,300,7,300,8,300,9'
*    HYPERBOLA                                   AHYPR1   A1244000
A70      DC    H'5,8'                             HYPERB
         DC    Y(0,1)
         DC    H'2,2,201,3,300,7,300,8,300,9'
*
*
*     CONE                                      ACONE1    A1245000
*
*     CON2 = CONE/PT1,VEC1,ANG
A80      DC    H'3,9'                             CONE
         DC    Y(0,1)
         DC    H'201,2,211,6,300,10'
*
*
*    GENERAL  CONICS                           AGENCN  A1246000
*
*     GC1 = GCONIC/A,B,C,D,E,F
A90      DC    H'6,6'                             GC1
         DC    Y((A901-A)/4+1,1)
         DC    H'300,2,300,3,300,4'
         DC    H'300,5,300,6,300,7'
*
*     GC2 = GCONIC/A,B,C,D,E
A901     DC    H'5,5'                             GC2
         DC    Y((A902-A)/4+1,2)
         DC    H'300,2,300,3,300,4,300,5,300,6'
*
*     GC3 = GCONIC/A,B,C,D,E,FUNOFY
A902     DC    H'6,6'                             GC3
         DC    Y(0,3)
         DC    H'300,2,300,3,300,4'
         DC    H'300,5,300,6,4,7'
*
*
*       LOFT CONICS           ALFTCN    A1247000
*
*     LCON1 = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5
A100     DC    H'11,11'                           LCON1
         DC    Y((A1001-A)/4+1,1)
         DC    H'45,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8,300,9'
         DC    H'300,10,300,11,300,12'
*
*     LCON2 = LCONIC/5PT,PT1,PT2,PT3,PT4,PT5
A1001    DC    H'6,21'                            LCON2
         DC    Y((A1002-A)/4+1,2)
         DC    H'45,2,201,3,201,7'
         DC    H'201,11,201,15,201,19'
*
*     LCON3 = LCONIC/4PT1SL,X1,Y1,,S1,X2,Y2,X3,Y3,X4,Y4
A1002    DC    H'10,10'                           LCON3
         DC    Y((A1003-A)/4+1,3)
         DC    H'44,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8'
         DC    H'300,9,300,10,300,11'
*
*     LCON4 = LCONIC/4PT1SL,PT1,S1,PT2,PT3,PT4
A1003    DC    H'6,18'                            LCON4
         DC    Y((A1004-A)/4+1,4)
         DC    H'44,2,201,3,300,7'
         DC    H'201,8,201,12,201,16'
*
*     LCON5 = LCONIC/3PT2SL,X1,Y1,S1,X2,Y2,S2,X3,Y3
A1004    DC    H'9,9'
         DC    Y((A1005-A)/4+1,5)
         DC    H'43,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8'
         DC    H'300,9,300,10'
*
*     LCON6 = LCONIC/3PT2SL,PT1,S1,PT2,S2,PT3
A1005    DC    H'6,15'                            LCON6
         DC    Y(0,6)
         DC    H'43,2,201,3,300,7'
         DC    H'201,8,300,12,201,13'
*
*
*      VECTORS                    AVECDF   A1248000
*
*     VC1 = VECTOR/A,B,C
A110     DC    H'3,3'                             VC1
         DC    Y((A1101-A)/4+1,1)
         DC    H'300,2,300,3,300,4'
*
*     VC2 = VECTOR/A,B,C,D,E,F
A1101    DC    H'6,6'                             VC2
         DC    Y((A1102-A)/4+1,2)
         DC    H'300,2,300,3,300,4'
         DC    H'300,5,300,6,300,7'
*
*     VC2A = VECTOR/PT1,PT2
A1102    DC    H'2,8'                             VC2A
         DC    Y((A1103-A)/4+1,3)
         DC    H'201,2,201,6'
*
*     VC3 = VECTOR/PERPTO,PLN1, POS- OR NEG- X OR Y OR Z
A1103    DC    H'3,7'                             VC3
         DC    Y((A1104-A)/4+1,4)
         DC    H'18,2,203,3,121,8'
*
*     VC4 = VECTOR/S,TIMES,VEC1 OR PT1
A1104    DC    H'3,6'                             VC4
         DC    Y((A1105-A)/4+1,5)
         DC    H'300,2,28,3,-211,4,201,4'
*
*     VC5 = VECTOR/VEC1 OR PT1,CROSS,VEC2 OR PT2
A1105    DC    H'3,9'                             VC5
         DC    Y((A1106-A)/4+1,6)
         DC    H'-211,2,201,2,3,6'
         DC    H'-211,7,201,7'
*
*     VC6 = VECTOR/UNIT,VEC1 OR PT1
A1106    DC    H'2,5'                             VC6
         DC    Y((A1107-A)/4+1,7)
         DC    H'30,2,-211,3,201,3'
*
*     VC6A = VECTOR/UNIT,A,B,C
A1107    DC    H'4,4'                             VC6A
         DC    Y((A1108-A)/4+1,8)
         DC    H'30,2,300,3,300,4,300,5'
*
*     VC7 = VECTOR/LENGTH,A,ATANGL,B, XY- OR YZ- OR ZXPLAN
A1108    DC    H'5,5'                             VC7
         DC    Y((A1109-A)/4+1,9)
         DC    H'9,2,300,3,1,4,300,5,121,6'
*
*     VC8 = VECTOR/PARLEL,INTOF,PLN1,PLN2, POS- OR NEG- X OR Y OR Z
A1109    DC    H'5,13'                            VC8
         DC    Y((A1110-A)/4+1,10)
         DC    H'17,2,5,3,203,4,203,9,121,14'
*
*     VC9 = VECTOR/VEC1 OR PT1,PLUS OR MINUS,VEC2 OR PT2
A1110    DC    H'3,9'                             VC9
         DC    Y((A1111-A)/4+1,6)
         DC    H'-211,2,201,2,121,6'
         DC    H'-211,7,201,7'
*
*  VC10=VECTOR/ATANGL,A,LN1,POS- OR NEGX OR Y OR X- OR YLARGE OR SMALL
A1111    DC    H'4,8'
         DC    Y(0,11)
         DC    H'1,2,300,3,202,4,121,9'
*
*
*    MATRICES                    AMATX  A1249000
*
*     SMAT1 = MATRIX/A,B,C,D,E,F,G,H,I,J,K,L
A120     DC    H'12,12'                           M1
         DC    Y((A1201-A)/4+1,1)
         DC    H'300,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8,300,9'
         DC    H'300,10,300,11,300,12,300,13'
*
*     SMAT2 = MATRIX/TRANSL,A,B,C
A1201    DC    H'4,4'                             M2
         DC    Y((A1202-A)/4+1,2)
         DC    H'29,2,300,3,300,4,300,5'
*
*     SMAT2A = MATRIX/TRANSL,A,B
A1202    DC    H'3,3'                             M2A
         DC    Y((A1203-A)/4+1,2)
         DC    H'29,2,300,3,300,4'
*
*     SMAT3 = MATRIX/XY- OR YZ- OR ZXROT, ANG
A1203    DC    H'2,2'                             M3
         DC    Y((A1204-A)/4+1,3)
         DC    H'121,2,300,3'
*
*     SMAT4 = MATRIX/ XY- OR YZ- OR ZXROT, ANG,TRANSL,A,B,C
A1204    DC    H'6,6'                             M4
         DC    Y((A1205-A)/4+1,13)
         DC    H'121,2,300,3,29,4'
         DC    H'300,5,300,6,300,7'
*
*     SMAT4A = MATRIX/ XY- OR YZ- OR ZXROT, ANG, TRANSL,A,B
A1205    DC    H'5,5'                             M4A
         DC    Y((A1206-A)/4+1,14)
         DC    H'121,2,300,3,29,4'
         DC    H'300,5,300,6'
*
*     SMAT5 = MATRIX/MAT1,MAT2
A1206    DC    H'2,26'                            M5
         DC    Y((A1207-A)/4+1,5)
         DC    H'212,2,212,15'
*
*     SMAT6 = MATRIX/INVERS,MAT1
A1207    DC    H'2,14'                            M6
         DC    Y((A1208-A)/4+1,6)
         DC    H'6,2,212,3'
*
*     SMAT7 = MATRIX/PLN1,PLN2,PLN3
A1208    DC    H'3,15'                            M7
         DC    Y((A1209-A)/4+1,31)
         DC    H'203,2,203,7,203,12'
*
*     SMAT8 = MATRIX/SCALE,A
A1209    DC    H'2,2'                             M8
         DC    Y((A1210-A)/4+1,4)
         DC    H'25,2,300,3'
*
*     SMAT9 = MATRIX/TRANSL,A,B,XY- OR YZ- OR ZXROT,ANG
A1210    DC    H'5,5'                             M9
         DC    Y((A1211-A)/4+1,22)
         DC    H'29,2,300,3,300,4,121,5,300,6'
*
*     SMAT10 = MATRIX/TRANSL,A,B,C, XY- OR YZ- OR ZXROT,ANG
A1211    DC    H'6,6'                             M10
         DC    Y((A1212-A)/4+1,17)
         DC    H'29,2,300,3,300,4,300,5,121,6,300,7'
*
*     SMAT11 = MATRIX/MX1, XY- OR YZ- OR ZXROT,ANG
A1212    DC    H'3,15'
         DC    Y((A1213-A)/4+1,7)
         DC    H'212,2,121,15,300,16'
*
*     SMAT12 = MATRIX/MX1,TRANSL,A,B,C
A1213    DC    H'5,17'
         DC    Y((A1214-A)/4+1,8)
         DC    H'212,2,29,15,300,16,300,17,300,18'
*
*     SMAT13 = MATRIX/MX1,TRANSL,A,B
A1214    DC    H'4,16'
         DC    Y((A1215-A)/4+1,9)
         DC    H'212,2,29,15,300,16,300,17'
*
*     SMAT14 = MATRIX/MX1,SCALE,A
A1215    DC    H'3,15'
         DC    Y((A1216-A)/4+1,10)
         DC    H'212,2,25,15,300,16'
*
*     SMAT15 = MATRIX/ XY- OR YZ- OR ZXROT,A,MX1
A1216    DC    H'3,15'
         DC    Y((A1217-A)/4+1,11)
         DC    H'121,2,300,3,212,4'
*
*     SMAT16 = MATRIX/ XY- OR YZ- OR ZXROT,ANG,XY- OR YZ- OR ZXROT,ANG2
A1217    DC    H'4,4'
         DC    Y((A1218-A)/4+1,12)
         DC    H'121,2,300,3,121,4,300,5'
*
*     SMAT17 = MATRIX/XY- OR YZ- OR ZXROT,ANG,SCALE,B
A1218    DC    H'4,4'
         DC    Y((A1219-A)/4+1,15)
         DC    H'121,2,300,3,25,4,300,5'
*
*     SMAT18 = MATRIX/TRANSL,A,B,C,MX1
A1219    DC    H'5,17'
         DC    Y((A1220-A)/4+1,16)
         DC    H'29,2,300,3,300,4,300,5,212,6'
*
*     SMAT19 = MATRIX/TRANSL,A,B,C,TRANSL,D,E,F
A1220    DC    H'8,8'
         DC    Y((A1221-A)/4+1,18)
         DC    H'29,2,300,3,300,4,300,5,29,6,300,7'
         DC    H'300,8,300,9'
*
*     SMAT20 = MATRIX/TRANSL,A,B,C,TRANSL,D,E
A1221    DC    H'7,7'
         DC    Y((A1222-A)/4+1,19)
         DC    H'29,2,300,3,300,4,300,5,29,6'
         DC    H'300,7,300,8'
*
*     SMAT21 = MATRIX/TRANSL,A,B,C,SCALE,D
A1222    DC    H'6,6'
         DC    Y((A1223-A)/4+1,20)
         DC    H'29,2,300,3,300,4,300,5,25,6,300,7'
*
*     SMAT22 = MATRIX/TRANSL,A,B,MX1
A1223    DC    H'4,16'
         DC    Y((A1224-A)/4+1,21)
         DC    H'29,2,300,3,300,4,212,5'
*
*     SMAT23 = MATRIX/TRANSL,A,B,TRANSL,C,D,E
A1224    DC    H'7,7'
         DC    Y((A1225-A)/4+1,23)
         DC    H'29,2,300,3,300,4,29,5,300,6'
         DC    H'300,7,300,8'
*
*     SMAT24 = MATRIX/TRANSL,A,B,TRANSL,C,D
A1225    DC    H'6,6'
         DC    Y((A1226-A)/4+1,24)
         DC    H'29,2,300,3,300,4,29,5,300,6,300,7'
*
*     SMAT25 = MATRIX/TRANSL,A,B,SCALE,C
A1226    DC    H'5,5'
         DC    Y((A1227-A)/4+1,25)
         DC    H'29,2,300,3,300,4,25,5,300,6'
*
*     SMAT26 = MATRIX/SCALE,A,MX1
A1227    DC    H'3,15'
         DC    Y((A1228-A)/4+1,26)
         DC    H'25,2,300,3,212,4'
*
*     SMAT27 = MATRIX/SCALE,A,XY- OR YZ- OR ZXROT,B
A1228    DC    H'4,4'
         DC    Y((A1229-A)/4+1,27)
         DC    H'25,2,300,3,121,4,300,5'
*
*     SMAT28 = MATRIX/SCALE,A,TRANSL,B,C,D
A1229    DC    H'6,6'
         DC    Y((A1230-A)/4+1,28)
         DC    H'25,2,300,3,29,4,300,5,300,6,300,7'
*
*     SMAT29 = MATRIX/SCALE,A,TRANSL,B,C
A1230    DC    H'5,5'
         DC    Y((A1231-A)/4+1,29)
         DC    H'25,2,300,3,29,4,300,5,300,6'
*
*     SMAT30 = MATRIX/SCALE,A,SCALE,B
A1231    DC    H'4,4'
         DC    Y((A1232-A)/4+1,30)
         DC    H'25,2,300,3,25,4,300,5'
*
*     SMAT31 = MATRIX/PT1,VEC1,VEC2
A1232    DC    H'3,12'
         DC    Y((A1233-A)/4+1,32)
         DC    H'201,2,211,6,211,10'
*
*     SMAT32 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN
A1233    DC    H'2,2'
         DC    Y((A1234-A)/4+1,33)
         DC    H'56,2,121,3'
*
*     SMAT33 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN,XY- OR YZ- OR ZXPLAN
A1234    DC    H'3,3'
         DC    Y((A1235-A)/4+1,33)
         DC    H'56,2,121,3,121,4'
*
*     SMAT34 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN,XY- OR YZ- OR $
*                     ZXPLAN, XY- OR YZ- OR ZXPLAN
A1235    DC    H'4,4'
         DC    Y((A1236-A)/4+1,33)
         DC    H'56,2,121,3,121,4,121,5'
*
*     SMAT35 = MATRIX/MIRROR,PLN1 OR LN1
A1236    DC    H'2,6'
         DC    Y(0,34)
         DC    H'56,2,-202,3,203,3'
*
*
*     SPHERES                                       ASPHER    A12500000
*
*     SP1 = SPHERE/X,Y,Z,R
A130     DC    H'4,4'                             SP1
         DC    Y((A1301-A)/4+1,1)
         DC    H'300,2,300,3,300,4,300,5'
*
*     SP2 = SPHERE/CENTER,PT1,RADIUS,R
A1301    DC    H'4,7'
         DC    Y((A1302-A)/4+1,2)
         DC    H'2,2,201,3,23,7,300,8'
*
*     SP3 = SPHERE/CENTER,PT1,PT2
A1302    DC    H'3,9'                             SP3
         DC    Y((A1303-A)/4+1,3)
         DC    H'2,2,201,3,201,7'
*
*     SP4 = SPHERE/CENTER,PT1,TANTO,PLN1
A1303    DC    H'4,11'                            SP4
         DC    Y((A1304-A)/4+1,4)
         DC    H'2,2,201,3,27,7,203,8'
*
*     SP5 = SPHERE/PT1,PT2,PT3,PT4
A1304    DC    H'4,16'                            SP5
         DC    Y((A1305-A)/4+1,5)
         DC    H'201,2,201,6,201,10,201,14'
*
*     SP6 = SPHERE/PT1,A
A1305    DC    H'2,5'                             SP6
         DC    Y(0,6)
         DC    H'201,2,300,6'
*
*
*      QUADRIC
*
A140     DC    H'10,10'                           QADR1
         DC    Y(0,1)
         DC    H'300,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8'
         DC    H'300,9,300,10,300,11'
*
*
*      POLCON
*
A150     DC    H'-0,2'
         DC    Y(0,1)
*
*
*      TABCYL
*
A160     DC    H'-0,2'
         DC    Y(0,1)
*
*
*      MESH
*
A170     DC    H'-0,2'
         DC    Y(0,1)
*
*
*      CONSEC
*
A180     DC    H'-0,2'
         DC    Y(0,0)
*
*
*      RULED SURF
*
A190     DC    H'-0,2'
         DC    Y(0,0)
*
*
*      LOFT
*
L100     DC    H'8,8'
         DC    Y((L101-A)/4+1,1)
         DC    H'300,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8,300,9'
*
L101     DC    H'7,10'
         DC    Y((L102-A)/4+1,2)
         DC    H'300,2,201,3,300,7,300,8'
         DC    H'300,9,300,10,300,11'
*
L102     DC    H'7,10'
         DC    Y((L103-A)/4+1,3)
         DC    H'300,2,300,3,300,4,201,5'
         DC    H'300,9,300,10,300,11'
*
L103     DC    H'6,12'
         DC    Y((L104-A)/4+1,4)
         DC    H'300,2,201,3,201,7'
         DC    H'300,11,300,12,300,13'
*
L104     DC    H'9,9'
         DC    Y(0,5)
         DC    H'300,2,300,3,300,4,300,5'
         DC    H'300,6,300,7,300,8,300,9,56,10'
*
*
        END

