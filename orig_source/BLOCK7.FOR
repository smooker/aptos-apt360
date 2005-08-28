      BLOCK DATA
      COMMON/ A2DYIN/ INDX1(10), INDX2(7,2), INDX3(15,2),
     1 X1(72),X2(72),X3(72),X4(72),X5(72),X6(72),X7(72),X8(72),X9(72),
     2 X10(52)
      DATA X1/
     1     4HSP  ,4H    ,4HSN  ,4H    ,4HTP  ,4H    ,4HTN  ,4H    ,
     1     4HSNK ,4H    ,4HSNL ,4H    ,4HSPK ,4H    ,4HSPL ,4H    ,
     1     4HTNK ,4H    ,4HTNL ,4H    ,4HTPK ,4H    ,4HTPL ,4H    ,
     1     4HPLNV,4H    ,4HCC  ,4H    ,4HU1  ,4H    ,4HCUTH,4H    ,
     1     4HSFVC,4HT   ,4HVNDI,4HR   ,4HVMD ,4H    ,4HVT  ,4H    ,
     1     4HTEE ,4H    ,4HSLX ,4H    ,4HDPLA,4HN   ,4HS   ,4H    ,
     1     4HRC  ,4H    ,4HPLND,4H    ,4HTH  ,4H    ,4HCSD ,4H    ,
     1     4HZ   ,4H    ,4HEPS1,4H    ,4HEPS2,4H    ,4HEPS3,4H    ,
     1     4HEPS4,4H    ,4HEPS6,4H    ,4HEPS8,4H    ,4HTAU ,4H    /
      DATA X2/
     1     4HTAU1,4H    ,4HTAU2,4H    ,4HSTCK,4H    ,4HSTCK,4HN   ,
     1     4HSTCK,4H1   ,4HSTCK,4H2   ,4HCOS1,4H    ,4HDPMX,4H1   ,
     1     4HCPLF,4HL   ,4HCPTS,4HT   ,4HPLNC,4HS   ,4HPLND,4H1   ,
     1     4HPLTS,4HT   ,4HPAST,4H    ,4HSPAS,4HT   ,4HADCS,4H    ,
     1     4HH   ,4H    ,4HCUTR,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4HIAFL,
     1     4H    ,4HIPON,4HTR  ,4HIFAR,4H    ,4HIPL ,4H    ,4HIUNF,
     1     4HL   ,4HISFT,4HYP  ,4HITLO,4HN   ,4HISVF,4HL   ,4HIFL4,
     1     4H    ,4HIOP ,4H    ,4HIOPS,4HET  ,4HJIOP,4HS   ,4HNOTA/
      DATA X3/
     1     4HN   ,4HJENT,4H    ,4HJU1 ,4H    ,4HISIG,4HCR  ,4HITSE,
     1     4HG   ,4HJTLF,4HLG  ,4HLOFS,4H    ,4HLIMF,4HL   ,4HICST,
     1     4HR   ,4HJTN ,4H    ,4HICHK,4HCT  ,4HJ20 ,4H    ,4HJ21 ,
     1     4H    ,4HJ22 ,4H    ,4HJ23 ,4H    ,4HJ24 ,4H    ,4HJ50 ,
     1     4H    ,4HJ51 ,4H    ,4HINDI,4HR   ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4HTE  ,
     1     4H    ,4HTEK ,4H    ,4HTEL ,4H    ,4HTES ,4H    ,4HTA  ,
     1     4H    ,4HTAK ,4H    ,4HTAL ,4H    ,4HPMOV,4HE   ,4HTI  /
      DATA X4/
     1     4H    ,4HTIK ,4H    ,4HTIL ,4H    ,4HU2  ,4H    ,4HUVEC,
     1     4H    ,4HVTEM,4H    ,4HCMOV,4HE   ,4HEX  ,4H    ,4HEY  ,
     1     4H    ,4HEZ  ,4H    ,4HVNUL,4H    ,4HTM  ,4H    ,4HDIR ,
     1     4H    ,4HAXIS,4H    ,4HAXIS,4H1   ,4HAXIS,4H2   ,4HAXIS,
     1     4H3   ,4HREFP,4HNT  ,4HRGT ,4H    ,4HFWD ,4H    ,4HUP  ,
     1     4H    ,4HZLNO,4HRM  ,4HZLPN,4HT   ,4HTNDI,4HR   ,4HVA  ,
     1     4H    ,4HTMVC,4HMP  ,4HP1  ,4H    ,4HP2  ,4H    ,4HPNT ,
     1     4H    ,4HPNT1,4H    ,4HOLDU,4H1   ,4HOGLE,4H    ,4HRZER,
     1     4HO   ,4HTANM,4HOT  ,4HTLEN,4HD1  ,4HV   ,4H    ,4HCEND/
      DATA X5/
     1     4H    ,4HDELM,4HOT  ,4HD2  ,4H    ,4HDNMO,4HT   ,4HAX4 ,
     1     4H    ,4HA   ,4H    ,4HB   ,4H    ,4HC   ,4H    ,4HRA  ,
     1     4H    ,4HHI  ,4H    ,4HALPH,4HA   ,4HGAMM,4HA   ,4HCAGL,
     1     4H    ,4HSAGL,4H    ,4HCOM1,4H    ,4HCOM4,4H    ,4HCOST,
     1     4HH   ,4HCTOC,4HL   ,4HDIAM,4H    ,4HDIF ,4H    ,4HDIFO,
     1     4HUT  ,4HDINC,4H    ,4HDP  ,4H    ,4HDPE ,4H    ,4HDPI ,
     1     4H    ,4HDPL ,4H    ,4HDPMA,4HX   ,4HDP1 ,4H    ,4HDPCN,
     1     4HT   ,4HDSMO,4HV   ,4HD1  ,4H    ,4HD2A ,4H    ,4HEL1 ,
     1     4H    ,4HEL2 ,4H    ,4HFIPN,4HT   ,4HFLIP,4HCK  ,4HHAFD/
      DATA X6/
     1     4HIA  ,4HHCHO,4HRD  ,4HOFFS,4HET  ,4HPROD,4H1   ,4HPROD,
     1     4H2   ,4HPSI ,4H    ,4HRADN,4HO   ,4HRC1 ,4H    ,4HRDRM,
     1     4H    ,4HRDRN,4H    ,4HRONE,4H    ,4HRZER,4HOL  ,4HSAVE,
     1     4H1   ,4HSIUT,4HH   ,4HTANG,4HL   ,4HTHET,4HA   ,4HALP ,
     1     4H    ,4HEPS7,4H    ,4HVAMA,4HX   ,4HVL  ,4H    ,4HZLDO,
     1     4HTC  ,4HZGAM,4HMA  ,4HZIGN,4H    ,4HZL  ,4H    ,4HZL1 ,
     1     4H    ,4HZL2 ,4H    ,4HZNPT,4HS   ,4HTOLB,4HND  ,4HCEND,
     1     4HIS  ,4HCENL,4HEN  ,4HCHOR,4HD   ,4HABCD,4H    ,4HACAR,
     1     4HD   ,4HSAVE,4H    ,4HCUTD,4HAT  ,4HTEM ,4H    ,4HTEMP/
      DATA X7/
     1     4H    ,4HTCDA,4HT   ,4HQEQU,4HIV  ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4HIS  ,4H    ,4HIIS ,4H    ,4HIT  ,
     1     4H    ,4HIIT ,4H    ,4HIPS ,4H    ,4HIIPS,4H    ,4HIDS ,
     1     4H    ,4HIIDS,4H    ,4HICS ,4H    ,4HIICS,4H    ,4HIGS ,
     1     4H    ,4HIIGS,4H    ,4HICDE,4HFL  ,4HICDE,4HFS  ,4HIAUT,
     1     4HPS  ,4HIGO ,4H    ,4HICRD,4HCT  ,4HICUT,4H    ,4HIGTF,
     1     4HLG  ,4HINOP,4HS   ,4HISRC,4HH   ,4HIOFS,4HET  ,4HISTR/
      DATA X8/
     1     4HUP  ,4HI3DF,4HLG  ,4HMULO,4HUT  ,4HMULT,4HAX  ,4HNUMA,
     1     4HX   ,4HNUMS,4HFS  ,4HNUMS,4HUR  ,4HIGOU,4HG   ,4HIPDP,
     1     4HL   ,4HNUMD,4HIM  ,4HIRST,4HRT  ,4HICSC,4HNT  ,4HI3  ,
     1     4H    ,4HI31 ,4H    ,4HJ   ,4H    ,4HJA  ,4H    ,4HJL  ,
     1     4H    ,4HJS  ,4H    ,4HJT  ,4H    ,4HKC  ,4H    ,4HKND ,
     1     4H    ,4HKR  ,4H    ,4HL   ,4H    ,4HINCF,4HS   ,4HNP  ,
     1     4H    ,4HIBEG,4HIN  ,4HIFAR,4H1   ,4HIK  ,4H    ,4HINS1,
     1     4H    ,4HITNF,4HLG  ,4HIVAM,4HAX  ,4HIWS ,4H    ,4HIIWS,
     1     4H    ,4HIZ  ,4H    ,4HNEXT,4H1   ,4HNEXT,4H2   ,4HNPTS/
      DATA X9/
     1     4H    ,4HNUMP,4HT1  ,4HJAM ,4H    ,4HJAP ,4H    ,4HJTUS,
     1     4HED  ,4HIFRL,4H    ,4HN   ,4H    ,4HM   ,4H    ,4HMDIC,
     1     4H    ,4HJBR ,4H    ,4HJCKR,4H    ,4HJCPR,4H    ,4HJCR ,
     1     4H    ,4HJDR ,4H    ,4HJGR ,4H    ,4HJMIN,4H    ,4HJMIN,
     1     4HR   ,4HJPR ,4H    ,4HJPXR,4H    ,4HJTR ,4H    ,4HJCNT,
     1     4H1   ,4HJCNT,4H2   ,4HJCNT,4H3   ,4HJSW ,4H    ,4HJTKF,
     1     4H    ,4HLISV,4H    ,4HLSV ,4H    ,4HIPT ,4H    ,4HJFIN,
     1     4HD   ,4HIC  ,4H    ,4HICC ,4H    ,4HIL  ,4H    ,4HK   ,
     1     4H    ,4HNUMP,4HTS  ,4HIAMD,4HCT  ,4HIFL2,4H    ,4HJ5  /
      DATA X10/
     1     4H    ,4HJ6  ,4H    ,4HJW6 ,4H    ,4HJ10 ,4H    ,4HJ12 ,
     1     4H    ,4HJ13 ,4H    ,4HJ40 ,4H    ,4HJ43 ,4H    ,4HJ54 ,
     1     4H    ,4HJ103,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4HPROB,
     1     4HUF  ,4HCANS,4HTO  ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,4H    ,
     1     4H    ,4H    ,4H    ,4H    /
      DATA INDX1 /  1,   1, 721,1313,1309,1409,1408,0,0,0/
      DATA INDX2 /  1,  3,  4, 13,  14,  15,  0,  1, 120, 200, 460, 680,
     1682,  0/
      DATA  INDX3 / 69,  31,  40, 147,  62,   4,   6,   7,  10,  20,
     1            260,  20, 104, 100, 600, -23, -31, 31, -49, -62,  -2,
     2              6,   7,  10,  20,   0,  20, 104,   0,   0/
      END
