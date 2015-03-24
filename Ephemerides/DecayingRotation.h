#ifndef DECAYING_ROTATION_H
#define DECAYING_ROTATION_H

#include "SimpleRotation.h"

#include "Maths/PDEMaths.h"
#include "Time/J2000.h"

class LinearDecayingRotation
: public RotationalEphemeris< SimpleRotation >
{

public:

	LinearDecayingRotation(
		const PDE::Vector3& xRotationAxis, const PDE::Vector3& xZeroLongitudeAtEquatorJ2000,
		const double dPeriodInHoursJ2000, const double dDecayRatePerYear, const double dMaximumPeriod )
	: mxRotationAxis( xRotationAxis )
	, mxZeroLongitudeAtEquator( xZeroLongitudeAtEquatorJ2000 )
	, mdRate( DayRateFromHourPeriod( dDecayRatePerYear ) )
	, mdMinimumRate( DayRateFromHourPeriod( dMaximumPeriod ) )
	, mdDecayRate( DecayRateFromHourPerYear( dPeriodInHoursJ2000, dDecayRatePerYear ) )
	{
	}

	PDE::Matrix3 EvaluateOrientation( const double dJDT ) const
	{
		const double dT = dJDT - J2000;
		double dActualRate = mdRate + dT * mdDecayRate;
		if( dActualRate < mdMinimumRate )
		{
			dActualRate = mdMinimumRate;
		}

		return SimpleRotation::EvaluateOrientation( dJDT, dActualRate, mxRotationAxis, mxZeroLongitudeAtEquator );
	}

	static double DecayRateFromHourPerYear( const double dPeriodHours, const double dHoursPerYear )
	{
		const double dNextYearPeriod = dPeriodHours + dHoursPerYear;
		const double dRate0 = DayRateFromHourPeriod( dPeriodHours );
		const double dRate1 = DayRateFromHourPeriod( dNextYearPeriod );

		return ( dRate1 - dRate0 ) / 365.25;
	}

private:

	PDE::Vector3 mxRotationAxis;
	PDE::Vector3 mxZeroLongitudeAtEquator;
	double mdRate;
	double mdMinimumRate;
	double mdDecayRate;
};

#endif
