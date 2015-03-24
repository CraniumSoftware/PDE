#ifndef SIMPLE_ROTATION_H
#define SIMPLE_ROTATION_H

#include "RotationalEphemeris.h"

#include "Maths/PDEMaths.h"
#include "Time/J2000.h"

class SimpleRotation
: public RotationalEphemeris< SimpleRotation >
{

public:

	SimpleRotation( const PDE::Vector3& xRotationAxis, const PDE::Vector3& xZeroLongitudeAtEquator, const double dPeriodInHours )
	: mxRotationAxis( xRotationAxis )
	, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquator )
	, mdRate( DayRateFromHourPeriod( dPeriodInHours ) )
	{
	}

	PDE::Matrix3 EvaluateOrientation( const double dJDT ) const
	{
		const double dAngle = 2.0 * PDE::PiDouble * PDE::Wrap( ( dJDT - J2000 ) * mdRate );
		const PDE::Vector3 xZeroNow = PDE::Matrix4::RotateAxisAngle(
			mxZeroLongitudeAtEquator, mxRotationAxis, static_cast< float >( dAngle ) ).Normalised();
		const PDE::Vector3 xLeft = xZeroNow.Cross( mxRotationAxis ).Normalised();

		// SE - NOTE: this is based on the idea that the xy-plane is the equator
		// ... it might need permuting etc. we shall discover with tests...
		return PDE::Matrix3( xLeft, xZeroNow, mxRotationAxis );
	}

private:

	static double DayRateFromHourPeriod( const double dPeriod )
	{
		return 24.0 / dPeriod;
	}

	PDE::Vector3 mxRotationAxis;
	PDE::Vector3 mxZeroLongitudeAtEquator;
	double mdRate;
};

#endif
