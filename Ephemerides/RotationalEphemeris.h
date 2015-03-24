#ifndef ROTATIONAL_EPHEMERIS_H
#define ROTATIONAL_EPHEMERIS_H

// the idea is that models using this template will work out the orientation of
// a body relative to the ICRF J2000.0

#include "Maths/PDEMatrix.h"

template< class Implementation >
class RotationalEphemeris
{

public:

	RotationalEphemeris() {}

	// SE - NOTE: these two vectors come from the orientation matrix,
	// or vice versa...
	PDE::Vector3 CalculateNorthPole( const double dJDT ) const
	{
		const Matrix3 xOrientation = CalculateOrientation( dJDT );
		return xOrientation[ 2 ];
	}

	PDE::Vector3 CalculateZeroLongitudeAtEquator( const double dJDT ) const
	{
		const Matrix3 xOrientation = CalculateOrientation( dJDT );
		return xOrientation[ 1 ];
	}

	PDE::Matrix3 CalculateOrientation( const double dJDT ) const
	{
		return static_cast< const Implementation* >( this )->EvaluateOrientation( dJDT );
	}

protected:

	static double DayRateFromHourPeriod( const double dPeriod )
	{
		return 24.0 / dPeriod;
	}

private:

};

#endif
