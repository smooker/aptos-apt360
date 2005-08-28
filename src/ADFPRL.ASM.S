/*
*/
.nolist

.global adfprl_
adfprl_:

/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
*
*     /ADFPRL/ PROGRAM
         PRINT ON,DATA
         DS    0F
ADFPRL   CSECT
*/

 #     INDEX TO THE FIRST LOCATION IN THIS TABLE AND THE NUMBER
 #        OF DEFINITION FORMATS LISTED FOR EACH SURFACE TYPE
A:        .short    12,(A10-A)/4+1		     #POINT
          .short    17,(A20-A)/4+1                    #LINE
          .short    8,(A30-A)/4+1	 	     #PLANE
          .short    13,(A40-A)/4+1                   #CIRCLE
         .short     4,(A50-A)/4+1                   #CYLINDER
         .short    1,(A60-A)/4+1                     #ELLIPS
         .short     1,(A70-A)/4+1                   #HYPERBOLA
         .short    1,(A80-A)/4+1                     #CONE
         .short    3,(A90-A)/4+1                     #GCONIC
         .short    6,(A100-A)/4+1                    #LCONIC
         .short    12,(A110-A)/4+1                   #  #VECTOR
         .short    37,(A120-A)/4+1                   #MATRIX
         .short    6,(A130-A)/4+1                    #SPHERE
         .short    1,(A140-A)/4+1                    #QADRIC
         .short    0,0                              #POLCON
         .short    5,(L100-A)/4+1                    #LOFT
         .short    0,0              #TOOL(17)
         .short    0,0              #PATERN(18)
         .short    1,(A160-A)/4+1                  #TABCYL
         .short    1,(A170-A)/4+1                  #MESH
         .short    1,(A180-A)/4+1                  #CONSEC
         .short    1,(A190-A)/4+1                  #RLDSRF


#   POINTS                                           APOINT   A1238000

#     P1 = POINT/X,Y
A10:     .short   2,2                             #P1
         .short    2,(A101-A)/4+1
         .short   2,300,3,300
#     P1A = POINT/X,Y,Z
A101:    .short  3,3                             #P1A
         .short   1,(A102-A)/4+1
         .short   2,300,3,300,4,300

#     P2 = POINT/INTOF,LN1,LN2
A102:    .short    11,3                            #P2
         .short    3,(A103-A)/4+1
         .short    2,5,3,202,8,202

#     P3 = POINT/X- OR YLARGE OR SMALL ,  INTOF,LN1,CIR1
A103:    .short    15,4                            #P3
         .short    4,(A104-A)/4+1
         .short     2,121,3,5,4,202,9,204

#     P4 = POINT/ X- OR YLARGE OR SMALL, INTOF,CIR1,CIR2
A104:    .short     18,4                            #P4
         .short    5,(A105-A)/4+1
         .short     2,121,3,5,4,204,12,204

#     P5 = POINT/CIR1,ATANGL,A
A105:    .short    10,3                            #P5
         .short    6,(A106-A)/4+1
         .short     2,204,10,1,11,300

#     P6 = POINT/CENTER,CIR1
A106:    .short    9,2                             #P6
         .short    7,(A107-A)/4+1
         .short     2,2,3,204

#    P7 = POINT/ X- OR YLARGE OR SMALL, INTOF,LN1, ANY OF THE SURFACES$
#                           TAKING THE QUADRIC CANONICAL FORM
A107:    .short    18,4                            #P7
         .short    8,(A108-A)/4+1
         .short     2,121,3,5,4,202,9,-206,9,-207,9,-209,9,-210,9,214

#     P8 = POINT/INTOF,PLN1,PLN2,PLN3
A108:    .short    16,4                            #P8
         .short    9,(A109-A)/4+1
         .short     2,5,3,203,8,203,13,203
#     P9 = POINT/ RTHETA, XY- OR YZ OR ZXPLAN, R,A
#             OR
#     P9 = POINT/THETAR, XY- OR YZ- OR ZXPLAN, A,R

A109:    .short    4,4                             #P9
         .short    10,(A111-A)/4+1
         .short     2,121,3,121,4,300,5,300

#     P10 = POINT/INTOF,LN1,TBC1,PT1
A111:    .short    0,4                             #P10
         .short    11,(A112-A)/4+1
         .short     2,5,3,202,8,250,0,201

#     P11 = POINT/PAT1,N
A112:    .short    0,2
         .short    12,0
         .short     2,218,0,300
#    LINES                                       ALINE     A1239000

#     L1 = LINE/X1,Y1,X2,Y2
A20:      .short    4,4                  #           L1
         .short    2,(A201-A)/4+1
         .short     2,300,3,300,4,300,5,300

#     L1A = LINE/PT1,PT2
A201:     .short    8,2                #             L1A
         .short    3,(A202-A)/4+1
         .short     2,201,6,201

#     L1B = LINE/X1,Y1,Z1,X2,Y2,Z2
A202:     .short    6,6                            # L1B
         .short    1,(A203-A)/4+1
         .short     2,300,3,300,4,300
         .short     5,300,6,300,7,300

#     L2 = LINE/PT1, RIGHT OR LEFT, TANTO,CIR1
A203:     .short    14,4
         .short    4,(A204-A)/4+1
         .short     2,201,6,121,7,27,8,204

#     L3 = LINE/ RIGHT OR LEFT, TANTO,CIR1,RIGHT OR LEFT, TANTO,CIR2
A204:     .short    20,6                            #L3
         .short    5,(A205-A)/4+1
         .short     2,121,3,27,4,204
         .short     12,121,13,27,14,204

#     L4 = LINE/PT1,ATANGL OR SLOPE, A
A205:     .short    6,3                             #L4
         .short    6,(A206-A)/4+1
         .short     2,201,6,-1,6,47,7,300

#     L5 = LINE/PT1,ATANGL OR SLOPE, A,LN1
A206:     .short    11,4                            #L5
         .short    11,(A207-A)/4+1
         .short     2,201,6,-1,6,47,7,300,8,202
#     L6 = LINE/PT1,PARLEL,LN1
A207:     .short    10,3
         .short    7,(A208-A)/4+1
         .short     2,201,6,17,7,202

#     L7 = LINE/PT1,PERPTO,LN1
A208:     .short    10,3                            #L7
         .short    8,(A209-A)/4+1
         .short     2,201,6,18,7,202

#     L8 = LINE/PARLEL,LN1, X- OR YLARGE OR SMALL, D
A209:     .short    8,4                             #L8
         .short    9,(A210-A)/4+1
         .short     2,17,3,202,8,121,9,300

#     L9 = LINE/INTOF,PLN1,PLN2
A210:     .short    11,3                            #L9
         .short    12,(A211-A)/4+1
         .short     2,5,3,203,8,203

#     L14A = LINE/ ATANGL OR SLOPE,A,INTERC,B
A211:     .short    4,4                             #L10
         .short    10,(A212-A)/4+1
         .short     2,-1,2,47,3,300,4,46,5,300

#     L11 = LINE/PT1,TANTO,TBC1,PT2
A212:     .short    0,4                             #L11
         .short    13,(A213-A)/4+1
         .short     2,201,6,27,7,250,0,201

#     L12 = LINE/PT1,PERPTO,TBC1,PT2
A213:     .short    0,4                             #L12
         .short    13,(A214-A)/4+1
         .short     2,201,6,18,7,250,0,201

#      L13 = LINE/XAXIS OR YAXIS
A214:     .short    1,1
         .short    14,(A215-A)/4+1
         .short     2,-84,2,85

#     L14 = LINE/ATANGL OR SLOPE, A,INTERC, XAXIS OR YAXIS, B
A215:     .short    5,5
         .short    15,(A216-A)/4+1
         .short     2,-1,2,47,3,300,4,46
         .short     5,-84,5,85,6,300

#     L15 = LINE/PNT1,ATANGL OR SLOPE, A,XAXIS OR YAXIS
A216:     .short    7,4
         .short    16,0
         .short     2,201,6,-1,6,47
         .short     7,300,8,-84,8,85


#   PLANES                               APLAN    A1240000

#     PL1 = PLANE/A,B,C,D
A30:      .short    4,4                             #PL1
         .short    1,(A301-A)/4+1
         .short     2,300,3,300,4,300,5,300

#     PL2 = PLANE/PT1,PT2,PT3
A301:     .short    12,3                            #PL2
         .short    2,(A302-A)/4+1
         .short     2,201,6,201,10,201
#     PL3 = PLANE/PT1,PARLEL,PLN1
A302:     .short    10,3                            #PL3
         .short    3,(A303-A)/4+1
         .short     2,201,6,17,7,203

#     PL4 = PLANE/PARLEL,PLN1, X- OR Y- OR ZLARGE OR SMALL,D
A303:     .short    8,4                             #PL4
         .short    4,(A304-A)/4+1
         .short     2,17,3,203,8,121,9,300

#     PL5 = PLANE/PT1,PERPTO,VEC1
A304:     .short    9,3                             #PL5
         .short    5,(A305-A)/4+1
         .short     2,201,6,18,7,211

#     PL6 = PLANE/PERPTO,PLN1,PT1,PT2  (ORIGINAL FORMAT)
A305:     .short    14,4                            #PL6
         .short    6,(A306-A)/4+1
         .short     2,18,3,203,8,201,12,201

#     PL7 = PLANE/PT1,PT2,PERPTO,PL1  (ALTERNATE FORMAT)
A306:     .short    14,4
         .short    7,(A307-A)/4+1
         .short     2,201,6,201,10,18,11,203

#     PL8 = PLANE/PT1,PERPTO,PL1,PL2
A307:     .short    15,4
         .short    0,8
         .short     2,201,6,18,7,203,12,203


#   CIRCLES                                        ACIRCL   A1241000

#     C1 = CIRCLE/X,Y,Z,R
A40:      .short    4,4                             #C1
         .short    1,(A401-A)/4+1
         .short     2,300,3,300,4,300,5,300

#     C1A = CIRCLE/X,Y,R
A401:     .short    3,3                             #C1A
         .short     2,(A402-A)/4+1
         .short     2,300,3,300,4,300

#     C1B = CIRCLE/CENTER,PT1,RADIUS,R
A402:     .short     7,4                             #C1B
         .short     3,(A403-A)/4+1
	  .short    2,2,3,201,7,23,8,300

#     C1C = CIRCLE/CENTER,X,Y,Z,RADIUS,R
A403:     .short    6,6                             #C1C
         .short     4,(A404-A)/4+1
         .short     2,2,3,300,4,300
         .short     5,300,6,23,7,300
#     C2 = CIRCLE/CENTER,PT1,TANTO,LN1
A404:     .short    11,4                            #C2
         .short     5,(A405-A)/4+1
         .short     2,2,3,201,7,27,8,202

#     C3 = CIRCLE/CENTER,PT1,PT2
A405:     .short    9,3                             #C3
         .short    6,(A406-A)/4+1
         .short     2,2,3,201,7,201

#     C4 = CIRCLE/PT1,PT2,PT3
A406:     .short     12,3                            #C4
         .short    7,(A407-A)/4+1
         .short     2,201,6,201,10,201

#     C5 = CIRCLE/CENTER,PT1,LARGE OR SMALL, TANTO, CIRCLE
A407:     .short    15,5
         .short    8,(A408-A)/4+1
         .short     2,2,3,201,7,121,8,27,9,204

#     C6 = CIRCLE/ X- OR YLARGE OR SMALL, LN1, X- OR YLARGE OR SMALL, $
#                  LN2,RADIUS,R
A408:     .short    14,6                            #C6
         .short    10,(A409-A)/4+1
         .short     2,121,3,202,8,121
         .short     9,202,14,23,15,300

#     C7 = CIRCLE/ TANTO,LN1, X- OR YLARGE OR SMALL, PT1,RADIUS,R
A409:     .short    13,6                            #C7
         .short    9,(A410-A)/4+1
         .short     2,27,3,202,8,121
         .short     9,201,13,23,14,300

#     C8 = CIRCLE/ X- OR YLARGE OR SMALL, LN1,X- OR YLARGE OR SMALL, $
#                 IN OR OUT,CIR1,RADIUS,R
A410:     .short    18,7                            #C8
         .short     12,(A411-A)/4+1
         .short     2,121,3,202,8,121
         .short     9,121,10,204,18,23,19,300

#     C9 = CIRCLE/ X- OR YLARGE OR SMALL,IN OR OUT,CIR1,IN OR OUT,  $
#                     CIR2,RADIUS,R
A411:     .short    21,7                            #C9
         .short     11,(A412-A)/4+1
         .short     2,121,3,121,4,204
         .short     12,121,13,204,21,23
         .short     22,300

#     C10 = CIRCLE/TANTO,LN1, X- OR YLARGE OR SMALL,TBC1, X- OR YLARGE$
#                  OR SMALL,PT1,RADIUS,R
A412:     .short    0,8                             #C10
         .short     13,0
         .short     2,27,3,202,8,121,9,250
         .short     0,121,0,201,0,23,0,300


#    CYLINDERS                                  ACYLND    A1242000

#     CYL2 = CYLINDER/PT1,DX,DY,DZ,R
#A50      .short    5,8
A50:      .short    8,5
#         .short    ((A501-A)/4+1,1)
         .short     1,(A501-A)/4+1
#         .short    201,2,300,6,300,7,300,8,300,9
         .short     2,201,6,300,7,300,8,300,9,300

#     CYL3 = CYLNDR/PT1,VEC1,R
#A501     .short    3,9
A501:     .short    9,3
#         .short    Y((A502-A)/4+1,2)
         .short    2,(A502-A)/4+1
#         .short    201,2,211,6,300,10
         .short     2,201,6,211,10,300

#     CYL4 = CYLNDER/X,Y,Z,VEC1,R
#A502     .short    5,8
A502:     .short    8,5
#         .short    ((A503-A)/4+1,3)
         .short    3,(A503-A)/4+1
#         .short    300,2,300,3,300,4,211,5,300,9
         .short     2,300,3,300,4,300,5,211,9,300

#     CYL5 = CYLNDR/X,Y,Z,DX,DY,DZ,R
#A503     .short    7,7
A503:     .short    7,7
#         .short    (0,4)
         .short    4,0
#         .short    300,2,300,3,300,4,300,5,300,6,300,7,300,8
         .short     2,300,3,300,4,300,5,300,6,300,7,300,8,300


#        ELLIPSE                            AELP01    A1243000

#     ELL1 = ELLIPS/CENTER,PT1,M,N,ANG
#A60      .short    5,8                             ELLIPS
A60:      .short    8,5                             #ELLIPS
#         .short    (0,1)
         .short    1,0
#         .short    2,2,201,3,300,7,300,8,300,9
         .short     2,2,3,201,7,300,8,300,9,300
#    HYPERBOLA                                   AHYPR1   A1244000
#A70      .short    5,8                             HYPERB
A70:      .short    8,5                             #HYPERB
#         .short    (0,1)
         .short    1,0
#         .short    2,2,201,3,300,7,300,8,300,9
         .short     2,2,3,201,7,300,8,300,9,300


#     CONE                                      ACONE1    A1245000

#     CON2 = CONE/PT1,VEC1,ANG
#A80      .short    3,9                             CONE
A80:      .short    9,3                             #CONE
#         .short    (0,1)
         .short    1,0
#         .short    201,2,211,6,300,10
         .short     2,201,6,211,10,300


#    GENERAL  CONICS                           AGENCN  A1246000

#     GC1 = GCONIC/A,B,C,D,E,F
#A90      .short    6,6                             GC1
A90:      .short    6,6                             #GC1
#         .short    ((A901-A)/4+1,1)
         .short    1,(A901-A)/4+1
#         .short    300,2,300,3,300,4
         .short     2,300,3,300,4,300
#         .short    300,5,300,6,300,7

#     GC2 = GCONIC/A,B,C,D,E
#A901     .short    5,5                             GC2
A901:     .short    5,5                             #GC2
#         .short    ((A902-A)/4+1,2)
         .short    2,(A902-A)/4+1
#         .short    300,2,300,3,300,4,300,5,300,6
         .short     2,300,3,300,4,300,5,300,6,300

#     GC3 = GCONIC/A,B,C,D,E,FUNOFY
#A902     .short    6,6                             GC3
A902:     .short    6,6                             #GC3
#         .short    (0,3)
         .short    3,0
#         .short    300,2,300,3,300,4
         .short     2,300,3,300,4,300
#         .short    300,5,300,6,4,7
         .short     5,300,6,300,7,4


#       LOFT CONICS           ALFTCN    A1247000

#     LCON1 = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5
A100:     .short    11,11                           #LCON1
         .short    1,(A1001-A)/4+1
#         .short    45,2,300,3,300,4,300,5
         .short     2,45,3,300,4,300,5,300
#         .short    300,6,300,7,300,8,300,9
         .short     6,300,7,300,8,300,9,300
#         .short    300,10,300,11,300,12
         .short     10,300,11,300,12,300

#     LCON2 = LCONIC/5PT,PT1,PT2,PT3,PT4,PT5
#A1001    .short    6,21                            LCON2
A1001:    .short    21,6                            #LCON2
#         .short    ((A1002-A)/4+1,2)
         .short     2,(A1002-A)/4+1
#         .short    45,2,201,3,201,7
         .short     2,45,3,201,7,201
#         .short    201,11,201,15,201,19
         .short     11,201,15,201,19,201

#     LCON3 = LCONIC/4PT1SL,X1,Y1,,S1,X2,Y2,X3,Y3,X4,Y4
#A1002    .short    10,10                           LCON3
A1002:    .short    10,10                           #LCON3
#         .short    ((A1003-A)/4+1,3)
         .short    3,(A1003-A)/4+1
#         .short    44,2,300,3,300,4,300,5
         .short     2,44,3,300,4,300,5,300
#         .short    300,6,300,7,300,8
         .short     6,300,7,300,8,300
#         .short    300,9,300,10,300,11
         .short     9,300,10,300,11,300

#     LCON4 = LCONIC/4PT1SL,PT1,S1,PT2,PT3,PT4
#A1003    .short    6,18                            LCON4
A1003:    .short    18,6                            #LCON4
#         .short    ((A1004-A)/4+1,4)
         .short    4,(A1004-A)/4+1
#         .short    44,2,201,3,300,7
         .short     2,44,3,201,7,300
#         .short    201,8,201,12,201,16
         .short     8,201,12,201,16,201

#     LCON5 = LCONIC/3PT2SL,X1,Y1,S1,X2,Y2,S2,X3,Y3
#A1004    .short    9,9
A1004:    .short    9,9
#         .short    ((A1005-A)/4+1,5)
         .short    5,(A1005-A)/4+1
#         .short    43,2,300,3,300,4,300,5
         .short     2,43,3,300,4,300,5,300
#         .short    300,6,300,7,300,8
         .short     6,300,7,300,8,300
#         .short    300,9,300,10
         .short     9,300,10,300

#     LCON6 = LCONIC/3PT2SL,PT1,S1,PT2,S2,PT3
#A1005    .short    6,15                            LCON6
A1005:    .short     15,6                            #LCON6
#         .short    (0,6)
         .short    6,0
#         .short    43,2,201,3,300,7
         .short     2,43,3,201,7,300
#         .short    201,8,300,12,201,13
         .short     8,201,12,300,13,201


#      VECTORS                    AVECDF   A1248000

#     VC1 = VECTOR/A,B,C
#A110     .short    3,3                             VC1
A110:     .short    3,3                             #VC1
#         .short    ((A1101-A)/4+1,1)
         .short    1,(A1101-A)/4+1
#         .short    300,2,300,3,300,4
         .short     2,300,3,300,4,300

#     VC2 = VECTOR/A,B,C,D,E,F
#A1101    .short    6,6                             VC2
A1101:    .short    6,6                             #VC2
#         .short    ((A1102-A)/4+1,2)
         .short    2,(A1102-A)/4+1
#         .short    300,2,300,3,300,4
         .short     2,300,3,300,4,300
#         .short    300,5,300,6,300,7
         .short     5,300,6,300,7,300

#     VC2A = VECTOR/PT1,PT2
#A1102    .short    2,8                             VC2A
A1102:    .short    8,2                             #VC2A
#         .short    ((A1103-A)/4+1,3)
         .short    3,(A1103-A)/4+1
#         .short    201,2,201,6
         .short     2,201,6,201

#     VC3 = VECTOR/PERPTO,PLN1, POS- OR NEG- X OR Y OR Z
#A1103    .short    3,7                             VC3
A1103:    .short    7,3                             #VC3
#         .short    ((A1104-A)/4+1,4)
         .short    4,(A1104-A)/4+1
#         .short    18,2,203,3,121,8
         .short     2,18,3,203,8,121

#     VC4 = VECTOR/S,TIMES,VEC1 OR PT1
#A1104    .short    3,6                             VC4
A1104:    .short    6,3                             #VC4
#         .short    ((A1105-A)/4+1,5)
         .short     5,(A1105-A)/4+1
#         .short    300,2,28,3,-211,4,201,4
         .short     2,300,3,28,4,-211,4,201

#     VC5 = VECTOR/VEC1 OR PT1,CROSS,VEC2 OR PT2
#A1105    .short    3,9                             VC5
A1105:    .short    9,3                             #VC5
#         .short    ((A1106-A)/4+1,6)
         .short    6,(A1106-A)/4+1
#         .short    -211,2,201,2,3,6
         .short     2,-211,2,201,6,3
#         .short    -211,7,201,7
         .short     7,-211,7,201

#     VC6 = VECTOR/UNIT,VEC1 OR PT1
#A1106    .short    2,5                             VC6
A1106:    .short    5,2                             #VC6
#         .short    ((A1107-A)/4+1,7)
         .short     7,(A1107-A)/4+1
#         .short    30,2,-211,3,201,3
         .short     2,30,3,-211,3,201

#     VC6A = VECTOR/UNIT,A,B,C
#A1107    .short    4,4                             VC6A
A1107:    .short    4,4                             #VC6A
#         .short    ((A1108-A)/4+1,8)
         .short    8,(A1108-A)/4+1
#         .short    30,2,300,3,300,4,300,5
         .short     2,30,3,300,4,300,5,300

#     VC7 = VECTOR/LENGTH,A,ATANGL,B, XY- OR YZ- OR ZXPLAN
#A1108    .short    5,5                             VC7
A1108:    .short    5,5                             #VC7
#         .short    ((A1109-A)/4+1,9)
         .short    9,(A1109-A)/4+1
#         .short    9,2,300,3,1,4,300,5,121,6
         .short     2,9,3,300,4,1,5,300,6,121

#     VC8 = VECTOR/PARLEL,INTOF,PLN1,PLN2, POS- OR NEG- X OR Y OR Z
#A1109    .short    5,13                            VC8
A1109:    .short    13,5                            #VC8
#         .short    ((A1110-A)/4+1,10)
         .short    10,(A1110-A)/4+1
#         .short    17,2,5,3,203,4,203,9,121,14
         .short     2,17,3,5,4,203,9,203,14,121

#     VC9 = VECTOR/VEC1 OR PT1,PLUS OR MINUS,VEC2 OR PT2
#A1110    .short    3,9                             VC9
A1110:    .short    9,3                             #VC9
#         .short    ((A1111-A)/4+1,6)
         .short    6,(A1111-A)/4+1
#         .short    -211,2,201,2,121,6
         .short     2,-211,2,201,6,121
#         .short    -211,7,201,7
         .short     7,-211,7,201

#  VC10=VECTOR/ATANGL,A,LN1,POS- OR NEGX OR Y OR X- OR YLARGE OR SMALL
#A1111    .short    4,8
A1111:    .short    8,4
#         .short    (0,11)
         .short    11,0
#         .short    1,2,300,3,202,4,121,9
         .short     2,1,3,300,4,202,9,121


#    MATRICES                    AMATX  A1249000

#     SMAT1 = MATRIX/A,B,C,D,E,F,G,H,I,J,K,L
#A120     .short    12,12                           M1
A120:     .short    12,12                           #M1
#         .short    ((A1201-A)/4+1,1)
         .short     1,(A1201-A)/4+1
#         .short    300,2,300,3,300,4,300,5
         .short     2,300,3,300,4,300,5,300
#         .short    300,6,300,7,300,8,300,9
         .short     6,300,7,300,8,300,9,300
#         .short    300,10,300,11,300,12,300,13
         .short     10,300,11,300,12,300,13,300

#     SMAT2 = MATRIX/TRANSL,A,B,C
#A1201    .short    4,4                             M2
A1201:    .short    4,4                             #M2
#         .short    ((A1202-A)/4+1,2)
         .short    2,(A1202-A)/4+1
#         .short    29,2,300,3,300,4,300,5
         .short     2,29,3,300,4,300,5,300

#     SMAT2A = MATRIX/TRANSL,A,B
#A1202    .short    3,3                             M2A
A1202:    .short    3,3                             #M2A
#         .short    ((A1203-A)/4+1,2)
         .short    2,(A1203-A)/4+1
#         .short    29,2,300,3,300,4
         .short     2,29,3,300,4,300

#     SMAT3 = MATRIX/XY- OR YZ- OR ZXROT, ANG
#A1203    .short    2,2                             M3
A1203:    .short    2,2                             #M3
#         .short    ((A1204-A)/4+1,3)
         .short    3,(A1204-A)/4+1
#         .short    121,2,300,3
         .short     2,121,3,300

#     SMAT4 = MATRIX/ XY- OR YZ- OR ZXROT, ANG,TRANSL,A,B,C
#A1204    .short    6,6                             M4
A1204:    .short    6,6                             #M4
#         .short    ((A1205-A)/4+1,13)
         .short    13,(A1205-A)/4+1
#         .short    121,2,300,3,29,4
         .short     2,121,3,300,4,29
#         .short    300,5,300,6,300,7
         .short     5,300,6,300,7,300

#     SMAT4A = MATRIX/ XY- OR YZ- OR ZXROT, ANG, TRANSL,A,B
#A1205    .short    5,5                             M4A
A1205:    .short    5,5                             #M4A
#         .short    ((A1206-A)/4+1,14)
         .short    14,(A1206-A)/4+1
#         .short    121,2,300,3,29,4
         .short     2,121,3,300,4,29
#         .short    300,5,300,6
         .short     5,300,6,300

#     SMAT5 = MATRIX/MAT1,MAT2
#A1206    .short    2,26                            M5
A1206:    .short    26,2                            #M5
#         .short    ((A1207-A)/4+1,5)
         .short    5,(A1207-A)/4+1
#         .short    212,2,212,15
         .short     2,212,15,212

#     SMAT6 = MATRIX/INVERS,MAT1
#A1207    .short    2,14                            M6
A1207:    .short    14,2                            #M6
#         .short    ((A1208-A)/4+1,6)
         .short     6,(A1208-A)/4+1
#         .short    6,2,212,3
         .short     2,6,3,212

#     SMAT7 = MATRIX/PLN1,PLN2,PLN3
#A1208    .short    3,15                            M7
A1208:    .short    15,3                            #M7
#         .short    ((A1209-A)/4+1,31)
         .short    31,(A1209-A)/4+1
#         .short    203,2,203,7,203,12
         .short     2,203,7,203,12,203

#     SMAT8 = MATRIX/SCALE,A
#A1209    .short    2,2                             M8
A1209:    .short    2,2                             #M8
#         .short    ((A1210-A)/4+1,4)
         .short    4,(A1210-A)/4+1
#         .short    25,2,300,3
         .short     2,25,3,300

#     SMAT9 = MATRIX/TRANSL,A,B,XY- OR YZ- OR ZXROT,ANG
#A1210    .short    5,5                             M9
A1210:    .short    5,5                             #M9
#         .short    ((A1211-A)/4+1,22)
         .short     22,(A1211-A)/4+1
#         .short    29,2,300,3,300,4,121,5,300,6
         .short     2,29,3,300,4,300,5,121,6,300

#     SMAT10 = MATRIX/TRANSL,A,B,C, XY- OR YZ- OR ZXROT,ANG
#A1211    .short    6,6                             M10
A1211:    .short    6,6                             #M10
#         .short    ((A1212-A)/4+1,17)
         .short    17,(A1212-A)/4+1
#         .short    29,2,300,3,300,4,300,5,121,6,300,7
         .short     2,29,3,300,4,300,5,300,6,121,7,300

#     SMAT11 = MATRIX/MX1, XY- OR YZ- OR ZXROT,ANG
#A1212    .short    3,15
A1212:    .short    15,3
#         .short    ((A1213-A)/4+1,7)
         .short    7,(A1213-A)/4+1
#         .short    212,2,121,15,300,16
         .short     2,212,15,121,16,300

#     SMAT12 = MATRIX/MX1,TRANSL,A,B,C
#A1213    .short    5,17
A1213:    .short    17,5
#         .short    ((A1214-A)/4+1,8)
         .short    8,(A1214-A)/4+1
#         .short    212,2,29,15,300,16,300,17,300,18
         .short     2,212,15,29,16,300,17,300,18,300

#     SMAT13 = MATRIX/MX1,TRANSL,A,B
#A1214    .short    4,16
A1214:    .short    16,4
#         .short    ((A1215-A)/4+1,9)
         .short    9,(A1215-A)/4+1
#         .short    212,2,29,15,300,16,300,17
         .short     2,212,15,29,16,300,17,300

#     SMAT14 = MATRIX/MX1,SCALE,A
#A1215    .short    3,15
A1215:    .short    15,3
#         .short    ((A1216-A)/4+1,10)
         .short    10,(A1216-A)/4+1
#         .short    212,2,25,15,300,16
         .short     2,212,15,25,16,300

#     SMAT15 = MATRIX/ XY- OR YZ- OR ZXROT,A,MX1
#A1216    .short    3,15
A1216:    .short    15,3
#         .short    ((A1217-A)/4+1,11)
         .short    11,(A1217-A)/4+1
#         .short    121,2,300,3,212,4
         .short     2,121,3,300,4,212

#     SMAT16 = MATRIX/ XY- OR YZ- OR ZXROT,ANG,XY- OR YZ- OR ZXROT,ANG2
#A1217    .short    4,4
A1217:    .short    4,4
#         .short    ((A1218-A)/4+1,12)
         .short    12,(A1218-A)/4+1
#         .short    121,2,300,3,121,4,300,5
         .short     2,121,3,300,4,121,5,300

#     SMAT17 = MATRIX/XY- OR YZ- OR ZXROT,ANG,SCALE,B
#A1218    .short    4,4
A1218:    .short    4,4
#         .short    Y((A1219-A)/4+1,15)
         .short    15,(A1219-A)/4+1
#         .short    121,2,300,3,25,4,300,5
         .short     2,121,3,300,4,25,5,300

#     SMAT18 = MATRIX/TRANSL,A,B,C,MX1
#A1219    .short    5,17
A1219:    .short    17,5
#         .short    ((A1220-A)/4+1,16)
         .short    16,(A1220-A)/4+1
#         .short    29,2,300,3,300,4,300,5,212,6
         .short     2,29,3,300,4,300,5,300,6,212

#     SMAT19 = MATRIX/TRANSL,A,B,C,TRANSL,D,E,F
#A1220    .short    8,8
A1220:    .short    8,8
#         .short    ((A1221-A)/4+1,18)
         .short    18,(A1221-A)/4+1
#         .short    29,2,300,3,300,4,300,5,29,6,300,7
         .short     2,29,3,300,4,300,5,300,6,29,7,300
#         .short    300,8,300,9
         .short     8,300,9,300

#     SMAT20 = MATRIX/TRANSL,A,B,C,TRANSL,D,E
#A1221    .short    7,7
A1221:    .short    7,7
#         .short    ((A1222-A)/4+1,19)
         .short    19,(A1222-A)/4+1
#         .short    29,2,300,3,300,4,300,5,29,6
         .short     2,29,3,300,4,300,5,300,6,29
#         .short    300,7,300,8
         .short     7,300,8,300

#     SMAT21 = MATRIX/TRANSL,A,B,C,SCALE,D
#A1222    .short    6,6
A1222:    .short    6,6
#         .short    ((A1223-A)/4+1,20)
         .short    20,(A1223-A)/4+1
#         .short    29,2,300,3,300,4,300,5,25,6,300,7
         .short     2,29,3,300,4,300,5,300,6,25,7,300

#     SMAT22 = MATRIX/TRANSL,A,B,MX1
#A1223    .short    4,16
A1223:    .short    16,4
#         .short    ((A1224-A)/4+1,21)
         .short    21,(A1224-A)/4+1
#         .short    29,2,300,3,300,4,212,5
         .short     2,29,3,300,4,300,5,212

#     SMAT23 = MATRIX/TRANSL,A,B,TRANSL,C,D,E
#A1224    .short    7,7
A1224:    .short    7,7
#        .short    ((A1225-A)/4+1,23)
         .short    23,(A1225-A)/4+1
#         .short    29,2,300,3,300,4,29,5,300,6
         .short     2,29,3,300,4,300,5,29,6,300
#         .short    300,7,300,8
         .short     7,300,8,300

#     SMAT24 = MATRIX/TRANSL,A,B,TRANSL,C,D
#A1225    .short    6,6
A1225:    .short    6,6
#         .short    ((A1226-A)/4+1,24)
         .short    24,(A1226-A)/4+1
#         .short    29,2,300,3,300,4,29,5,300,6,300,7
         .short     2,29,3,300,4,300,5,29,6,300,7,300

#     SMAT25 = MATRIX/TRANSL,A,B,SCALE,C
#A1226    .short    5,5
A1226:    .short    5,5
#         .short    ((A1227-A)/4+1,25)
         .short    25,(A1227-A)/4+1
#         .short    29,2,300,3,300,4,25,5,300,6
         .short     2,29,3,300,4,300,5,25,6,300

#     SMAT26 = MATRIX/SCALE,A,MX1
#A1227    .short    3,15
A1227:    .short    15,3
#         .short    ((A1228-A)/4+1,26)
         .short    26,(A1228-A)/4+1
#         .short    25,2,300,3,212,4
         .short     2,25,3,300,4,212

#     SMAT27 = MATRIX/SCALE,A,XY- OR YZ- OR ZXROT,B
#A1228    .short    4,4
A1228:    .short    4,4
#         .short    ((A1229-A)/4+1,27)
         .short    27,(A1229-A)/4+1
#         .short    25,2,300,3,121,4,300,5
         .short     2,25,3,300,4,121,5,300

#     SMAT28 = MATRIX/SCALE,A,TRANSL,B,C,D
#A1229    .short    6,6
A1229:    .short    6,6
#         .short    ((A1230-A)/4+1,28)
         .short     28,(A1230-A)/4+1
#         .short    25,2,300,3,29,4,300,5,300,6,300,7
         .short     2,25,3,300,4,29,5,300,6,300,7,300

#     SMAT29 = MATRIX/SCALE,A,TRANSL,B,C
#A1230    .short    5,5
A1230:    .short    5,5
#         .short    ((A1231-A)/4+1,29)
         .short    29,(A1231-A)/4+1
#         .short    25,2,300,3,29,4,300,5,300,6
         .short     2,25,3,300,4,29,5,300,6,300

#     SMAT30 = MATRIX/SCALE,A,SCALE,B
#A1231    .short    4,4
A1231:    .short    4,4
#         .short    ((A1232-A)/4+1,30)
         .short    30,(A1232-A)/4+1
#         .short    25,2,300,3,25,4,300,5
         .short     2,25,3,300,4,25,5,300

#     SMAT31 = MATRIX/PT1,VEC1,VEC2
#A1232    .short    3,12
A1232:    .short    12,3
#         .short    ((A1233-A)/4+1,32)
         .short    32,(A1233-A)/4+1
#         .short    201,2,211,6,211,10
         .short     2,201,6,211,10,211

#     SMAT32 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN
#A1233    .short    2,2
A1233:    .short    2,2
#         .short    ((A1234-A)/4+1,33)
         .short    33,(A1234-A)/4+1
#         .short    56,2,121,3
         .short     2,56,3,121

#     SMAT33 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN,XY- OR YZ- OR ZXPLAN
#A1234    .short    3,3
A1234:    .short    3,3
#         .short    ((A1235-A)/4+1,33)
         .short    33,(A1235-A)/4+1
#         .short    56,2,121,3,121,4
         .short     2,56,3,121,4,121

#     SMAT34 = MATRIX/MIRROR,XY- OR YZ- OR ZXPLAN,XY- OR YZ- OR $
#                     ZXPLAN, XY- OR YZ- OR ZXPLAN
#A1235    .short    4,4
A1235:    .short    4,4
#         .short    ((A1236-A)/4+1,33)
         .short    33,(A1236-A)/4+1
#         .short    56,2,121,3,121,4,121,5
         .short     2,56,3,121,4,121,5,121

#     SMAT35 = MATRIX/MIRROR,PLN1 OR LN1
#A1236    .short    2,6
A1236:    .short    6,2
#         .short    (0,34)
         .short     34,0
#         .short    56,2,-202,3,203,3
         .short     2,56,3,-202,3,203


#     SPHERES                                       ASPHER    A12500000

#     SP1 = SPHERE/X,Y,Z,R
#A130     .short    4,4                             SP1
A130:     .short    4,4                             #SP1
#         .short    ((A1301-A)/4+1,1)
         .short     1,(A1301-A)/4+1
#         .short    300,2,300,3,300,4,300,5
         .short     2,300,3,300,4,300,5,300

#     SP2 = SPHERE/CENTER,PT1,RADIUS,R
#A1301    .short    4,7
A1301:    .short    7,4
#         .short    ((A1302-A)/4+1,2)
         .short     2,(A1302-A)/4+1
#         .short    2,2,201,3,23,7,300,8
         .short     2,2,3,201,7,23,8,300

#     SP3 = SPHERE/CENTER,PT1,PT2
#A1302    .short    3,9                             SP3
A1302:    .short    9,3                             #SP3
#         .short    ((A1303-A)/4+1,3)
         .short    3,(A1303-A)/4+1
#         .short    2,2,201,3,201,7
         .short     2,2,3,201,7,201

#     SP4 = SPHERE/CENTER,PT1,TANTO,PLN1
#A1303    .short    4,11                            SP4
A1303:    .short    11,4                            #SP4
#         .short    ((A1304-A)/4+1,4)
         .short    4,(A1304-A)/4+1
#         .short    2,2,201,3,27,7,203,8
         .short     2,2,3,201,7,27,8,203

#     SP5 = SPHERE/PT1,PT2,PT3,PT4
#A1304    .short    4,16                            SP5
A1304:    .short    16,4                            #SP5
#         .short    ((A1305-A)/4+1,5)
         .short    5,(A1305-A)/4+1
#         .short    201,2,201,6,201,10,201,14
         .short     2,201,6,201,10,201,14,201

#     SP6 = SPHERE/PT1,A
#A1305    .short    2,5                             SP6
A1305:    .short    5,2                             #SP6
#         .short    (0,6)
         .short    6,0
#         .short    201,2,300,6
         .short     2,201,6,300


#      QUADRIC

#A140     .short    10,10                           QADR1
A140:     .short    10,10                           #QADR1
#         .short    (0,1)
         .short    1,0
#         .short    300,2,300,3,300,4,300,5
         .short     2,300,3,300,4,300,5,300
#         .short    300,6,300,7,300,8
         .short     6,300,7,300,8,300
#         .short    300,9,300,10,300,11
         .short     9,300,10,300,11,300


#      POLCON

#A150     .short    -0,2
A150:     .short    2,-0
#         .short    (0,1)
         .short    1,0


#      TABCYL

#A160     .short    -0,2
A160:     .short    2,-0
#         .short    (0,1)
         .short     1,0


#      MESH

#A170     .short    -0,2
A170:     .short    2,-0
#         .short    (0,1)
         .short    1,0


#      CONSEC

#A180     .short    -0,2
A180:     .short    2,-0
#         .short    (0,0)
         .short    0,0


#      RULED SURF

#A190     .short    -0,2
A190:     .short    2,-0
#         .short    (0,0)
         .short    0,0


#      LOFT

#L100     .short    8,8
L100:     .short    8,8
#         .short    ((L101-A)/4+1,1)
         .short    1,(L101-A)/4+1
#         .short    300,2,300,3,300,4,300,5
         .short     2,300,3,300,4,300,5,300
#         .short    300,6,300,7,300,8,300,9
         .short     6,300,7,300,8,300,9,300

#L101     .short    7,10
L101:     .short    10,7
#         .short    ((L102-A)/4+1,2)
         .short    2,(L102-A)/4+1
#         .short    300,2,201,3,300,7,300,8
         .short     2,300,3,201,7,300,8,300
#         .short    300,9,300,10,300,11
         .short     9,300,10,300,11,300

#L102     .short    7,10
L102:     .short    10,7
#         .short    ((L103-A)/4+1,3)
         .short    3,(L103-A)/4+1
#         .short    300,2,300,3,300,4,201,5
         .short     2,300,3,300,4,300,5,201
#         .short    300,9,300,10,300,11
         .short     9,300,10,300,11,300

#L103     .short    6,12
L103:     .short    12,6
#         .short    ((L104-A)/4+1,4)
         .short    4,(L104-A)/4+1
#         .short    300,2,201,3,201,7
         .short     2,300,3,201,7,201
#         .short    300,11,300,12,300,13
         .short     11,300,12,300,13,300

#L104     .short    9,9
L104:     .short    9,9
#         .short    (0,5)
         .short    5,0
#         .short    300,2,300,3,300,4,300,5
         .short     2,300,3,300,4,300,5,300
#         .short    300,6,300,7,300,8,300,9,56,10
         .short     6,300,7,300,8,300,9,300,10,56


#        END
.end
