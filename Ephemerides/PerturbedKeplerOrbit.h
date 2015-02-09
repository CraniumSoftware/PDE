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
        return mkxElements.SemiMajorAxis + mkxPerturbations.SemiMajorAxis * static_cast< double >( xJDT - mkxElements.JDTZero );
    }

    double EvaluateEccentricity( const EphemerisFloat& xJDT ) const
    {
        return mkxElements.Eccentricity + mkxPerturbations.Eccentricity * static_cast< double >( xJDT - mkxElements.JDTZero );
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

private:

    const KeplerElements mkxElements;
    const KeplerElements mkxPerturbations;

};

#endif
