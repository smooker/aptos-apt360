partno N/C 360  APT SAMPLE PART PROGRAM                                      010
$$PARTNO N/C 360  APT SAMPLE PART PROGRAM                                    010
      CLPRNT                                                                 012
print/on
$$debug/on
      $$NOPOST                                                               014
$$      MACHIN/TEST                                                          015
	
      SP   =  POINT/ 0, 0, 0                                                 020

      L1   =  LINE/ 4, 0, 0, 4, 8, 0                                         030
      PT   =  POINT/ 4.0, 8.0, 0                                             040
      L2   =  LINE/ PT, ATANGL, 45                                           050
      L3   =  LINE/ 8, 12, 0, 12, 12, 0                                      060
      L4   =  LINE/ 14, 5, 0, 14, 10, 0                                      070
      L5   =  LINE/ 0, 2, 0, 10, 2, 0                                        080
      C1   =  CIRCLE/ 12, 10, 0, 2.0                                         090
      C2   =  CIRCLE/ 14, 2, 0, 3.0                                          100
 $$     PRINT/3,ALL                                                         a011
      INTOL/ 0                                                               110
      OUTTOL/ .005                                                           120
      CUTTER/ .25                                                            130
      SPINDL/ 2000, CLW                                                      140
      COOLNT/ ON                                                             150
      FEDRAT/ 20.0                                                           160
      FROM/ SP                                                               170
      GO/ TO, L1                                                             180
      TLLFT, GOLFT/ L1, PAST, L2                                             190
      GORGT/ L2, PAST, L3                                                    200
      GORGT/ L3, TANTO, C1                                                   210
      GOFWD/ C1, TANTO, L4                                                   220
      GOFWD/L4, PAST, C2                                                     230
      GORGT/ C2, PAST, L5                                                    240
      GORGT/ L5, PAST, L1                                                    250
      GOTO/ SP                                                               260
      COOLNT/ OFF                                                            270
      SPINDL/ OFF                                                            280
      END                                                                    285
      FINI                                                                   290
