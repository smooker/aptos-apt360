//first number: class
//second: 	sub-class
//last:		protap
#ifndef AXTABL_H
#define AXTABL_H
#include "f2c.h"

struct ClassRef{
	shortint classId;
	shortint subClass;
	shortint proTapSubClass;
	shortint proTapClass;
};

struct Keyword{
	char* word;
	struct ClassRef data;
};

#endif

