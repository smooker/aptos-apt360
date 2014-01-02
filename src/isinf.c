
#ifdef WIN32

#include <float.h> // brings in '_isnan' which we use to implement an 'isinf' function
#include <f2c.h>

int isinf(doublereal x)
{
	return (!_isnan(x) && _isnan(x - x));
}

#endif

