#ifndef SIMPLE_ROTATION_H
#define SIMPLE_ROTATION_H

#include "RotationalEphemeris.h"

#include "Maths/PDEMaths.h"
#include "Time/J2000.h"

class SimpleRotation
: public RotationalEphemeris< SimpleRotation >
{

public:

	SimpleRotation(
		const PDE::Vector3& xRotationAxis, const PDE::Vector3& xZeroLongitudeAtEquatorJ2000,
		const double dPeriodInHours )
	: mxRotationAxis( xRotationAxis )
	, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquatorJ2000 )
	, mdRate( DayRateFromHourPeriod( dPeriodInHours ) )
	{
	}

	PDE::Matrix3 EvaluateOrientation( const double dJDT ) const
	{
		return EvaluateOrientation( dJDT, mdRate, mxRotationAxis, mxZeroLongitudeAtEquator );
	}

	static PDE::Matrix3 EvaluateOrientation(
		const double dJDT, const double dRate, const PDE::Vector3& xAxis, const PDE::Vector3& xZeroLonLat )
	{
		const double dAngle = 2.0 * PDE::PiDouble * PDE::Wrap( ( dJDT - J2000 ) * dRate );
		const PDE::Vector3 xZeroNow = PDE::Matrix4::RotateAxisAngle(
			xZeroLonLat, xAxis, static_cast< float >( dAngle ) ).Normalised();
		const PDE::Vector3 xLeft = xZeroNow.Cross( xAxis ).Normalised();

		// SE - NOTE: this is based on the idea that the xy-plane is the equator
		// ... it might need permuting etc. we shall discover with tests...
		return PDE::Matrix3( xLeft, xZeroNow, xAxis );
	}

private:

	PDE::Vector3 mxRotationAxis;
	PDE::Vector3 mxZeroLongitudeAtEquator;
	double mdRate;
};

#endif
