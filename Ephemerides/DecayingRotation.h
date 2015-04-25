#ifndef DECAYING_ROTATION_H
#define DECAYING_ROTATION_H

#include "SimpleRotation.h"

#include "Maths/PDEMaths.h"
#include "Time/J2000.h"

class LinearDecayingRotation
: public RotationalEphemeris< LinearDecayingRotation >
{

public:

	LinearDecayingRotation(
		const PDE::Vector3& xRotationAxis, const PDE::Vector3& xZeroLongitudeAtEquatorJ2000,
		const double dPeriodInHoursJ2000, const double dDecayRatePerYear, const double dMaximumPeriod )
	: mxRotationAxis( xRotationAxis )
	, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquatorJ2000 )
	, mdRate( DayRateFromHourPeriod( dPeriodInHoursJ2000 ) )
	, mdMinimumRate( DayRateFromHourPeriod( dMaximumPeriod ) )
	, mdDecayRate( DecayRateFromHourPerYear( dPeriodInHoursJ2000, dDecayRatePerYear ) )
	{
	}

	PDE::Matrix3 EvaluateOrientation( const double dJDT ) const
	{
		return EvaluateOrientation( dJDT, mdRate, mdDecayRate, mdMinimumRate, mxRotationAxis, mxZeroLongitudeAtEquator );
	}

	static PDE::Matrix3 EvaluateOrientation(
		const double dJDT, const double dRate, const double dDecayRate,
		const double dMinimumRate, const PDE::Vector3& xAxis, const PDE::Vector3& xZeroLonLat )
	{
		const double dT = dJDT - J2000;
		double dActualRate = dRate + dT * dDecayRate;
		if( dActualRate < dMinimumRate )
		{
			dActualRate = dMinimumRate;
		}

		return SimpleRotation::EvaluateOrientation( dJDT, dActualRate, xAxis, xZeroLonLat );
	}

private:

	PDE::Vector3 mxRotationAxis;
	PDE::Vector3 mxZeroLongitudeAtEquator;
	double mdRate;
	double mdMinimumRate;
	double mdDecayRate;

};

#endif
