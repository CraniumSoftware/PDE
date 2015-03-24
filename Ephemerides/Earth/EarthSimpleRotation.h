#ifndef EARTH_SIMPLE_ROTATION
#define EARTH_SIMPLE_ROTATION

#include "Ephemerides/SimpleRotation.h"

class EarthSimpleRotation
: public SimpleRotation
{

public:

	EarthSimpleRotation()
	: SimpleRotation( kxRotationAxis, kxZeroLongitudeLatitudeJ2000, kdPeriod )
	{
	}

private:

	static const PDE::Vector3 kxRotationAxis;
	static const PDE::Vector3 kxZeroLongitudeLatitudeJ2000;
	static const double kdPeriod;

};

#endif
