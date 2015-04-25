#ifndef PRECESSING_ROTATION_H
#define PRECESSING_ROTATION_H

#include "DecayingRotation.h"

// SE - NOTE: it feels like some composition should help here...
// ... the member declarations and initialisations are piling up.

class PrecessingRotation
: public RotationalEphemeris< PrecessingRotation >
{

public:

	PrecessingRotation(
		const PDE::Vector3& xPrecessionAxis, const PDE::Vector3& xRotationAxis,
		const PDE::Vector3& xZeroLongitudeAtEquatorJ2000,
		const double dPrecessionPeriodInHours, const double dPeriodInHoursJ2000,
		const double dDecayRatePerYear, const double dMaximumPeriod )
		: mxRotationAxis( xRotationAxis )
		, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquatorJ2000 )
		, mdPrecessionRate( DayRateFromHourPeriod( dPrecessionPeriodInHours ) )
		, mdRate( DayRateFromHourPeriod( dDecayRatePerYear ) )
		, mdMinimumRate( DayRateFromHourPeriod( dMaximumPeriod ) )
		, mdDecayRate( DecayRateFromHourPerYear( dPeriodInHoursJ2000, dDecayRatePerYear ) )
	{
	}

	PrecessingRotation(
		const PDE::Vector3& xPrecessionAxis, const PDE::Vector3& xRotationAxis,
		const PDE::Vector3& xZeroLongitudeAtEquatorJ2000,
		const double dPrecessionPeriodInHours, const double dPeriodInHoursJ2000 )
		: mxRotationAxis( xRotationAxis )
		, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquatorJ2000 )
		, mdPrecessionRate( DayRateFromHourPeriod( dPrecessionPeriodInHours ) )
		, mdRate( DayRateFromHourPeriod( dPeriodInHoursJ2000 ) )
		, mdMinimumRate( 0.0 )
		, mdDecayRate( 0.0 )
	{
	}

	static PDE::Matrix3 EvaluateOrientation(
		const double dJDT, const double dRate, const double dDecayRate,
		const double dMinimumRate, const PDE::Vector3& xAxis, const PDE::Vector3& xZeroLonLat, 
		const PDE::Vector3& xPrecessionAxis, const double dPrecessionRate )
	{
		const double dT = dJDT - J2000;
		const double dPrecessionAngle = 2.0 * PDE::PiDouble * PDE::Wrap( ( dJDT - J2000 ) * dPrecessionRate );
		const PDE::Vector3 xActualAxis = PDE::Matrix4::RotateAxisAngle( xAxis, xPrecessionAxis, dPrecessionAngle );

		return LinearDecayingRotation::EvaluateOrientation(
			dJDT, dRate, dDecayRate, dMinimumRate, xActualAxis, xZeroLonLat );
	}

private:

	PDE::Vector3 mxPrecessionAxis;
	PDE::Vector3 mxRotationAxis;
	PDE::Vector3 mxZeroLongitudeAtEquator;

	double mdPrecessionRate;
	double mdRate;
	double mdMinimumRate;
	double mdDecayRate;

};

#endif
