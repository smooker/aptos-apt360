" Vim syntax file
" Language:	Apt for S/360
" Version:	
" URL:		
" Last Change:	23Apr05
" Maintainer: Brent Muller <crotchet@sourceforge.net>	
" Usage:	
" Credits:
" 
if version < 600
  syntax clear
elseif exists("b:current_syntax")
  finish
endif

syn case ignore

"type 24:
syn keyword aptType point line circle plane cylndr ellips 
syn keyword aptType vector matrix patern qadric polcon loft mesh 
syn keyword aptType consec rldsrf hyperb cone gconic sphere 
syn keyword aptType tabcyl lconic tool elmsrf 
"type 12:
syn keyword aptType pocket
"type 16:
syn keyword aptType reserv 
"type 26:
syn keyword aptMotionType gofwd golft gorgt goup godown go goto from 
syn keyword aptMotionType indirp indirv offset srfvct godlta goback 

"type 29:
syn keyword aptMinorType AT IN ON TO UP ALL ARC BCD CAM CLW FAN IPM IPR LOW
syn keyword aptMinorType MED NOW NOX NOY NOZ OFF OUT PEN RED REV RPM SFM TAP
syn keyword aptMinorType TPI XYZ 5PT AUTO BLUE BORE BOTH CCLW DARK DASH DECR
syn keyword aptMinorType DEEP DOWN FACE FULL GRID HIGH INCR LAST LEFT LITE
syn keyword aptMinorType LOCK MAIN MILL MIST NEGX NEGY NEGZ NEXT OMIT OPEN
syn keyword aptMinorType PART PAST PLUS POSX POSY POSZ RAIL REAM REAR SAME
syn keyword aptMinorType SIDE STEP THRU TRAV TURN TYPE UNIT AAXIS AVOID BAXIS
syn keyword aptMinorType BLACK CAXIS CHUCK CONST CROSS DITTO DRILL DSTAN FLOOD
syn keyword aptMinorType FRONT GREEN INTOF LARGE LIGHT MINUS NIXIE PARAB PERSP
syn keyword aptMinorType PSTAN RANGE RIGHT SCALE SLOPE SMALL SOLID START TANDS
syn keyword aptMinorType TANON TANTO TIMES TWOPT XAXIS XYROT YAXIS YZROT ZAXIS
syn keyword aptMinorType ZXROT ADJUST ANTSPI ATANGL BINARY CENTER CIRCUL CIRLIN
syn keyword aptMinorType COLLET CUTANG DOTTED ENDARC FOURPT FUNOFY GAPLES HOLDER
syn keyword aptMinorType INTENS INTERC INVERS LENGTH LINCIR LINEAR MANUAL MAXIPM
syn keyword aptMinorType MAXRPM MEDIUM MIRROR MODIFY MULTRD NOMORE NORMAL NORMDS
syn keyword aptMinorType NORMPS OPTION PARLEL PERPTO PTNORM PTSLOP RADIUS RANDOM
syn keyword aptMinorType RETAIN ROTREF RTHETA SADDLE SCRIBE SETANG SETOOL SPLINE
syn keyword aptMinorType TAPKUL THETAR TRANSL TRFORM XCOORD XLARGE XSMALL XYPLAN
syn keyword aptMinorType XYVIEW YCOORD YLARGE YSMALL YZPLAN YZVIEW ZCOORD ZIGZAG
syn keyword aptMinorType ZLARGE ZSMALL ZXPLAN ZXVIEW 3PT2SL 4PT1SL



"type 19:
syn keyword aptFunction absf cosf numf sinf tanf anglf atanf distf  
syn keyword aptFunction dotf lnthf sqrtf atan2f log10f expf logf

"types 22,23:
syn keyword aptPostProc AIR END PBS HEAD IFRO MODE PLOT STOP ZERO CHECK CLAMP
syn keyword aptPostProc CYCLE DELAY DRAFT DRESS DWELL ISTOP LOCKX MDEND PENUP
syn keyword aptPostProc PITCH POSTN PPLOT PROBX PROBY RAPID RESET SEQNO TMARK
syn keyword aptPostProc TRANS WCORN ARCSLP ASLOPE AUXFUN CAMERA CLEARP CLRSRF
syn keyword aptPostProc COOLNT CORNFD COUPLE CUTCOM DELETE DISPLY DRAWLI FACEML
syn keyword aptPostProc FEDRAT GOCLER GOHOME INTCOD LEADER LETTER LOADTL LPRINT
syn keyword aptPostProc MAGTAP MAXDPM MAXVEL MCHFIN MCHTOL MDWRIT MOVETO OPSKIP
syn keyword aptPostProc OPSTOP ORIGIN OVPLOT PENDWN PICKUP PIVOTZ PLABEL PLUNGE
syn keyword aptPostProc PREFUN REGBRK RETRCT REVERS REWIND ROTABL ROTHED SAFETY
syn keyword aptPostProc SELCTL SLOWDN SPINDL SWITCH THREAD TOOLNO TURRET ULOCKX
syn keyword aptPostProc UNLOAD VTLAXS
"type 27:
syn keyword aptToolPos tlon tllft tlrgt tlndon tlofps tlonps 


"type 1:
syn match aptFixedField /^INSERT/ 
syn match aptFixedField /^titles/ 
syn match aptFixedField /^remark/ 
syn match aptFixedField /^pprint/ 
syn match aptFixedField /^partno/ 
syn match aptError /.\+partno.*/ 
syn match aptError /.\+titles.*/ 
syn match aptError /.\+remark.*/ 
syn match aptError /.\+pprint.*/ 
syn match aptError /.\+insert.*/ 




"identifier too long:
syn match aptError /[0-9a-z]\{7,\}/ 


"type 2:
syn keyword aptTlPathCntrl intol maxdp thick toler cutter numpts outtol tlaxis 
"types 9,7,18,21,14,10,11,8,20
syn keyword aptProgCntrl if call fini copy index macro jumpto loopst loopnd 
syn keyword aptProgCntrl termac tracut refsys tranto

"type 25:
syn keyword aptType25 dac cltv clprnt noplot nopost ptonly 

"type 3:
syn keyword aptType3 cut nops dmill autops bevels dntcut gougck multax ndtest 
syn keyword aptType3 2dcalc 3dcalc 

"type 33:
syn keyword aptType33 ltv mit cmit tancrv 
"type 4:
syn keyword aptType4 read print punch 
"type 15:
syn keyword aptTypeDebug dyndmp debug
"types 17,13,31,28,35,6,21,5,34,5:
syn keyword aptTypeMisc syn psis sec1 sec2 canon libry zsurf machin tuneup obtain 


syn match aptNumber	display "\<\d\+\(_\a\w*\)\=\>"
" floating point number, without a decimal point
syn match aptNumber	display	"\<\d\+[deq][-+]\=\d\+\(_\a\w*\)\=\>"
" floating point number, starting with a decimal point
syn match aptNumber	display	"\.\d\+\([deq][-+]\=\d\+\)\=\(_\a\w*\)\=\>"
" floating point number, no digits after decimal
syn match aptNumber	display	"\<\d\+\.\([deq][-+]\=\d\+\)\=\(_\a\w*\)\=\>"
" floating point number, e exponents
syn match aptNumber	display	"\<\d\+\.\d\+\([e][-+]\=\d\+\)\=\(_\a\w*\)\=\>"
" floating point number
syn match aptNumber	display	"\<\d\+\.\d\+\(e[-+]\=\d\+\)\=\(_\a\w*\)\=\>"

syn match aptComment /$$.*/ contains=aptLineId,aptError80
syn match aptComment /$.*/ contains=aptLineId,aptError80

syn region aptNoHilite start=/insert/ end=/$/ contains=aptFixedField,aptLineID 
syn region aptNoHilite start=/partno/ end=/$/ contains=aptFixedField,aptLineID 
syn region aptNoHilite start=/pprint/ end=/$/ contains=aptFixedField,aptLineID 
syn region aptNoHilite start=/titles/ end=/$/ contains=aptFixedField,aptLineID 
syn region aptComment start=/^remark/ end=/$/ contains=aptFixedField,aptLineID 


syn match aptLabel /^\s*[^($]\+)/
"Flag line ID
syn match aptLineID excludenl "^.\{73,}$"lc=72 contains=aptError80

"Flag over column 80
syn match aptError80 excludenl "^.\{80,}$"lc=80

	if version >= 508 || !exists("did_c_syn_inits")
	  if version < 508
	    let did_c_syn_inits = 1
	    command -nargs=+ HiLink hi link <args>
	  else
	    command -nargs=+ HiLink hi def link <args>
	  endif

	HiLink aptType 		Type 
	HiLink aptMotionType 	Statement 
	HiLink aptComment 	Comment
	HiLink aptError 	Error
	HiLink aptError80 	Error
	HiLink aptNumber 	Constant
	HiLink aptPostProc	Statement  
	HiLink aptMinorType	PreProc  
	HiLink aptFunction	Statement	
	HiLink aptToolPos 	Statement	
	HiLink aptFixedField 	Statement	
	HiLink aptTlPathCntrl 	Statement	
	HiLink aptProgCntrl 	Statement	
	HiLink aptType25 	Statement	
	HiLink aptType3 	Statement	
	HiLink aptType4 	Statement	
	HiLink aptTypeDebug 	Statement	
	HiLink aptTypeMisc 	Statement	
	HiLink aptLabel 	Statement	
	HiLink aptLineID 	Todo
	  delcommand HiLink
	endif






let b:current_syntax = "apt"

