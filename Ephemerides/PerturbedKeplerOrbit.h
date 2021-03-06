#ifndef PERTURBED_KEPLER_ORBIT_H
#define PERTURBED_KEPLER_ORBIT_H

#include "KeplerOrbit.h"

class LinearPerturbedKeplerOrbitalEphemeris
: public OrbitalEphemeris< LinearPerturbedKeplerOrbitalEphemeris >
{

public:

    LinearPerturbedKeplerOrbitalEphemeris( const KeplerElements& xElements, const KeplerElements& xPerturbations )
    : mkxElements( xElements )
    , mkxPerturbations( xPerturbations )
    {

    }

    EphemerisVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        const double dT = static_cast< double >( xJDT - mkxElements.JDTZero );
        return Evaluate( mkxElements, mkxPerturbations, dT );
    }

    static EphemerisVector4 Evaluate(
        const KeplerElements xElements,
        const KeplerElements xPerturbations,
        const double dT )
    {
        return KeplerOrbitalEphemeris::Evaluate(
            xElements.LongitudeOfAscendingNode + xPerturbations.LongitudeOfAscendingNode * dT,
            xElements.Inclination + xPerturbations.Inclination * dT,
            xElements.ArgumentOfPerifocus + xPerturbations.ArgumentOfPerifocus * dT,
            xElements.SemiMajorAxis + xPerturbations.SemiMajorAxis * dT,
            xElements.Eccentricity + xPerturbations.Eccentricity * dT,
            xElements.MeanAnomaly + xPerturbations.MeanAnomaly * dT,
            xElements.LongitudeRate,
            dT );
    }

    double EvaluateSemiMajorAxis( const EphemerisFloat& xJDT ) const
    {
        return mkxElements.SemiMajorAxis
			+ mkxPerturbations.SemiMajorAxis * static_cast< double >( xJDT - mkxElements.JDTZero );
    }

    double EvaluateEccentricity( const EphemerisFloat& xJDT ) const
    {
        return mkxElements.Eccentricity
			+ mkxPerturbations.Eccentricity * static_cast< double >( xJDT - mkxElements.JDTZero );
    }

	double EvaluateArgumentOfPerifocus( const EphemerisFloat& xJDT ) const
	{
		return mkxElements.ArgumentOfPerifocus
			+ mkxPerturbations.ArgumentOfPerifocus * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateLongitudeOfAscendingNode( const EphemerisFloat& xJDT )
	{
		return mkxElements.LongitudeOfAscendingNode
			+ mkxPerturbations.LongitudeOfAscendingNode * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateTrueAnomaly( const EphemerisFloat& dT ) const
	{
		const double dSemiMajorAxis = EvaluateSemiMajorAxis( dT );
		const double dEccentricity = EvaluateEccentricity( dT );
		return KeplerOrbitalEphemeris::EvaluateTrueAnomaly(
			mkxElements.MeanAnomaly, mkxElements.LongitudeRate, dSemiMajorAxis, dEccentricity, dT );
	}
    
    double EvaluatePeriod( const EphemerisFloat& ) const
    {
        return 2.0 * PDE::PiDouble / mkxElements.LongitudeRate;
    }

private:

    const KeplerElements mkxElements;
    const KeplerElements mkxPerturbations;

};

template< class Implementation >
class SpeciallyPerturbedKeplerOrbitalEphemeris
: public OrbitalEphemeris< Implementation >
{

public:

    SpeciallyPerturbedKeplerOrbitalEphemeris( const KeplerElements& xElements, const KeplerElements& xPerturbations )
    : mkxElements( xElements )
    , mkxPerturbations( xPerturbations )
    {

    }

    EphemerisVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        const double dT = static_cast< double >( xJDT - mkxElements.JDTZero );
        return static_cast< const Implementation* >( this )->Perturb(
            LinearPerturbedKeplerOrbitalEphemeris::Evaluate( mkxElements, mkxPerturbations, dT ), dT );
    }

    EphemerisVector4 Perturb( const EphemerisVector4 xPosition, const double dT ) const
    {
        UNUSED( dT );
        return xPosition;
    }

	// SE - NOTE: copy and paste?!?!
	double EvaluateSemiMajorAxis( const EphemerisFloat& xJDT ) const
	{
		return mkxElements.SemiMajorAxis
			+ mkxPerturbations.SemiMajorAxis * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateEccentricity( const EphemerisFloat& xJDT ) const
	{
		return mkxElements.Eccentricity
			+ mkxPerturbations.Eccentricity * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateArgumentOfPerifocus( const EphemerisFloat& xJDT ) const
	{
		return mkxElements.ArgumentOfPerifocus
			+ mkxPerturbations.ArgumentOfPerifocus * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateLongitudeOfAscendingNode( const EphemerisFloat& xJDT )
	{
		return mkxElements.LongitudeOfAscendingNode
			+ mkxPerturbations.LongitudeOfAscendingNode * static_cast< double >( xJDT - mkxElements.JDTZero );
	}

	double EvaluateTrueAnomaly( const EphemerisFloat& dT ) const
	{
		const double dSemiMajorAxis = EvaluateSemiMajorAxis( dT );
		const double dEccentricity = EvaluateEccentricity( dT );
		return KeplerOrbitalEphemeris::EvaluateTrueAnomaly(
			mkxElements.MeanAnomaly, mkxElements.LongitudeRate, dSemiMajorAxis, dEccentricity, dT );
	}

private:

    const KeplerElements mkxElements;
    const KeplerElements mkxPerturbations;

};

#endif
