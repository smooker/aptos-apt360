#ifndef ENDIANMACS_H
#define ENDIANMACS_H

	//The original IBM code was for a big-endian machine.
	//The code is littered with places where variables of 
	//one type are cast to another type, or arrays of 
	//one type are indexed as the type of another.
	//These macros are for dealing with those occurances.
	
  #ifdef WORDS_BIGENDIAN
	//define macros to nothing; code is ok as is
	#define OTHER_ENDIAN_W(x) 
	#define OTHER_ENDIAN_S(x)
	#define OTHER_ENDIAN_8(x)
	#define SWTCH_ENDIAN_INT(x) 
	#define SWTCH_ENDIAN_INT_SHRT(x) 
	#define SWTCH_ENDIAN_INT_CHAR(x)
	#define SWTCH_ENDIAN_DOUBLE(x) 
	#define SWTCH_ENDIAN_INT_SHRT_HG(x)
	#define SWTCH_ENDIAN_INT_SHRT_LW(x)
  #else  //machine is little-endian
//
	//for arrays sliced 4 times,eg, integer arrays
	//addressed as bytes
	#define OTHER_ENDIAN_W(x) (((x)/4)*4+(3-(x)%4)) 

	//for arrays sliced 2 times,eg, integer arrays
	//addressed as if short ints
	#define OTHER_ENDIAN_S(x) (((x)/2)*2+(1-(x)%2)) 

	//for arrays sliced 8 times,eg, double arrays
	//addressed as if chars 
	#define OTHER_ENDIAN_8(x) (((x)/8)*8+(7-(x)%8)) 


	//-----switch endianness of individual types
	#define SWTCH_ENDIAN_INT(x) (  			\
			((x)<<24) |  			\
			(((x)<<8) & 0x00ff0000 ) | 	\
			(((x)>>8) & 0x0000ff00)|	\
			(((x)>>24) )		 	\
			)

	#define SWTCH_ENDIAN_INT_SHRT(x) (  			\
			((x)<<16) |  			\
			((x)>>16) 		 	\
			)

	#define SWTCH_ENDIAN_INT_CHAR(x) (  			\
			((x)<<8) |  			\
			((x)>>8) 		 	\
			)
	#define SWTCH_ENDIAN_DOUBLE(x) 				\
			(				\
			(((long long int)(x))<<32) |  			\
			(((long long int)(x))>>32) 		 	\
			)

	#define SWTCH_ENDIAN_INT_SHRT_HG(x) ( \
					(((x)>>8)& 0xff) | \
					(((x)<< 8)& 0xff00)| \
					((x)& 0xffff0000 )\
					)
	#define SWTCH_ENDIAN_INT_SHRT_LW(x) ( \
					(((x)>>8)&  0x00ff0000) | \
					(((x)<< 8)& 0xff000000)| \
					((x)& 0xffff )\
					)

  #endif
#endif
