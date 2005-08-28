      BLOCK DATA
      IMPLICIT REAL*8 (A-H,O-Z)
C     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4,MODIFICATION 4 ***
      COMMON/A0CON/K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,IBLANK
      COMMON/ASISTM/IPTNLY,ITRCUT,IWAVEN,KFLAG1,LTVMIT,NCLREC,NOPOST,
     1NOPLOT,NUMPST,NUMPTR,ICLPRT,INDEXX,IPLOTR,KFLAGS(9)
      COMMON/A2FPC / Q15X01,QP9X01    ,QP6X01    ,QP5X01    ,QP4X01    ,
     1QP0001    ,QP001     ,QP01      ,QP1       ,Q1P       ,Q10P      ,
     2Q1000P    ,Q1PE5     ,Q1PE6     ,Q1PE10    ,Q1PE20    ,Q1PE30    ,
     3Q1PE36    ,Q1PE38    ,QP8X01    ,QP7X01    ,
     4QP4X09    ,QP9       ,QP99      ,QP995     ,QP997     ,QP999     ,
     5QP9999    ,QP4X95    ,QP5X95    ,QP6X9     ,QP7X9     ,
     6QP6X05    ,QP5X05    ,QP4X05    ,QP0005    ,QP005     ,QP05      ,
     7QP5       ,Q5P       ,                                 Q4X045    ,
     8QP0002    ,QP0047    ,QP017     ,Q1RAD     ,QP0349    ,QP125     ,
     9QP6       ,QP2       ,QP2499    ,QP25      ,QP3
C
      COMMON/A2CMMN/ VAR(3413)
      DIMENSION  SURV(600), ISRV(240), FXCM(536), IFX2(104),
     1  PBFR(100), SSTO(2000), IFX4(10)
      EQUIVALENCE (VAR(1),SURV(1))
      EQUIVALENCE (VAR(601),ISRV(1))
      EQUIVALENCE (VAR(721),FXCM(1))
      EQUIVALENCE (VAR(1257),IFX2(1))
      EQUIVALENCE (VAR(1309),PBFR(1))
      EQUIVALENCE (VAR(1409),SSTO(1))
      EQUIVALENCE (VAR(3409),IFX4(1))
      DATA SURV/600*0.D+0/
      DATA ISRV/240*0/
      DATA FXCM/536*0.D+0/
      DATA IFX2/104*0/
      DATA PBFR/100*0.D+0/
      DATA SSTO/2000*0.D+0/
      DATA IFX4/10*0/
C
      COMMON/A2DYDP/ KDYNFQ(12), NKFQ
      COMMON/ A2CTDF / VAR3(72)
      COMMON/A2FPC / QP7   ,QP75      ,QP8       ,QP866     ,Q1P01     ,
     1Q1P1      ,Q1P2      ,Q1P25     ,Q1P5      ,Q2P       ,Q2P5      ,
     2Q3P       ,Q3P5      ,Q4P       ,Q8P       ,Q11P      ,Q45P      ,
     3Q90P      ,Q130P     ,Q4500P    ,Q9000P    ,QP02      ,QNUL      ,
     4QPIE      ,Q100P     ,QFIL(8)
C...    ************ Q100P ONLY IN ATLTST AND ASEGMT ******************
      DATA       Q15X01    ,QP9X01    ,QP6X01    ,QP5X01    ,QP4X01    /
     1           1.D-16    ,1.D-10    ,1.D-7     ,1.D-6     ,1.D-5    /,
     2QP0001    ,QP001     ,QP01      ,QP1       ,Q1P       ,Q10P      /
     31.D-4     ,1.D-3     ,1.D-2     ,1.D-1     ,1.D+0     ,1.D+1    /,
     4Q1000P    ,Q1PE5     ,Q1PE6     ,Q1PE10    ,Q1PE20    ,Q1PE30    /
     51.D+3     ,1.D+5     ,1.D+6     ,1.D+10    ,1.D+20    ,1.D+30   /,
     6Q1PE36    ,Q1PE38    ,QP8X01    ,QP7X01    /
     71.D+36    ,1.D+38    ,1.D-9     ,1.D-8    /,
     8QP4X09    ,QP9       ,QP99      ,QP995     ,QP997     ,QP999     /
     99.D-5     ,9.D-1     ,9.9D-1    ,9.95D-1   ,9.97D-1   ,9.99D-1   /
      DATA       QP9999    ,QP4X95    ,QP5X95    ,QP6X9     ,QP7X9     /
     1           9.999D-1  ,9.9995D-1 ,9.99995D-1,9.99999D-1,9.999999D-1
     2/,QP6X05  ,QP5X05    ,QP4X05    ,QP0005    ,QP005     ,QP05      /
     35.D-7     ,5.D-6     ,5.D-5     ,5.D-4     ,5.D-3     ,5.D-2    /,
     4QP5       ,Q5P       ,                                 Q4X045    /
     55.D-1     ,5.D+0     ,                                 4.5D-5   /,
     6QP0002    ,QP0047    ,QP017     ,Q1RAD     ,QP0349    ,QP125     /
     72.D-4     ,4.7D-3    ,1.7D-2    ,1.74532925D-2,3.49D-2,1.25D-1  /,
     8QP6       ,QP2       ,QP2499    ,QP25      ,QP3       /
     96.D-1     ,2.D-1     ,2.499D-1  ,2.5D-1    ,3.D-1     /
      DATA       QP7       ,QP75      ,QP8       ,QP866     ,Q1P01     /
     1           7.D-1     ,7.5D-1    ,8.D-1     ,8.66D-1   ,1.01D+0  /,
     2Q1P1      ,Q1P2      ,Q1P25     ,Q1P5      ,Q2P       ,Q2P5      /
     31.1D+0    ,1.2D+0    ,1.25D+0   ,1.5D+0    ,2.D+0     ,2.5D+0   /,
     4Q3P       ,Q3P5      ,Q4P       ,Q8P       ,Q11P      ,Q45P      /
     53.D+0     ,3.5D+0    ,4.D+0     ,8.D+0     ,11.D+0    ,45.D+0   /,
     6Q90P      ,Q130P     ,Q4500P    ,Q9000P    ,QP02      ,QNUL      /
     79.D1      ,1.3D2     ,4.5D3     ,9.D3      ,2.D-2     ,0.D+0    /
      DATA       QPIE      ,Q100P     /
     1           3.14159D+0,100.D+0   /
      DATA KDYNFQ,NKFQ/12*0,0/
      DATA VAR3/72*0.D+0/
      DATA K0,K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12 /
     1 0,1,2,3,4,5,6,7,8,9,10,11,12 /
      COMMON/S2FLGS/K2FLGS(10)
      DATA K2FLGS/10*0/
      END

