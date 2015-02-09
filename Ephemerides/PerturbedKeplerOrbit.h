#ifndef PETURBED_KEPLER_ORBIT_H
#define PETURBED_KEPLER_ORBIT_H

#include "KeplerOrbit.h"

class LinearPeturbedKeplerOrbitalEphemeris
: public OrbitalEphemeris< LinearPeturbedKeplerOrbitalEphemeris >
{

public:

    LinearPeturbedKeplerOrbitalEphemeris( const KeplerElements& xElements, const KeplerElements& xPeturbations )
    : mkxElements( xElements )
    , mkxPeturbations( xPeturbations )
    {

    }

    EphemerisVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        const double dT = static_cast< double >( xJDT - mkxElements.JDTZero );
        return Evaluate( mkxElements, mkxPeturbations, dT );
    }

    static EphemerisVector4 Evaluate(
        const KeplerElements xElements,
        const KeplerElements xPeturbations,
        const double dT )
    {
        return KeplerOrbitalEphemeris::Evaluate(
            xElements.LongitudeOfAscendingNode + xPeturbations.LongitudeOfAscendingNode * dT,
            xElements.Inclination + xPeturbations.Inclination * dT,
            xElements.ArgumentOfPerifocus + xPeturbations.ArgumentOfPerifocus * dT,
            xElements.SemiMajorAxis + xPeturbations.SemiMajorAxis * dT,
            xElements.Eccentricity + xPeturbations.Eccentricity * dT,
            xElements.MeanAnomaly + xPeturbations.MeanAnomaly * dT,
            xElements.LongitudeRate,
            dT );
    }

    double EvaluateSemiMajorAxis( const EphemerisFloat& xJDT ) const
    {
        return mkxElements.SemiMajorAxis + mkxPeturbations.SemiMajorAxis * static_cast< double >( xJDT - mkxElements.JDTZero );
    }

    double EvaluateEccentricity( const EphemerisFloat& xJDT ) const
    {
        return mkxElements.Eccentricity + mkxPeturbations.Eccentricity * static_cast< double >( xJDT - mkxElements.JDTZero );
    }

private:

    const KeplerElements mkxElements;
    const KeplerElements mkxPeturbations;

};

template< class Implementation >
class SpeciallyPeturbedKeplerOrbitalEphemeris
: public OrbitalEphemeris< Implementation >
{

public:

    SpeciallyPeturbedKeplerOrbitalEphemeris( const KeplerElements& xElements, const KeplerElements& xPeturbations )
    : mkxElements( xElements )
    , mkxPeturbations( xPeturbations )
    {

    }

    EphemerisVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        const double dT = static_cast< double >( xJDT - mkxElements.JDTZero );
        return static_cast< const Implementation* >( this )->Peturb(
            LinearPeturbedKeplerOrbitalEphemeris::Evaluate( mkxElements, mkxPeturbations, dT ), dT );
    }

    EphemerisVector4 Peturb( const EphemerisVector4 xPosition, const double dT ) const
    {
        UNUSED( dT );
        return xPosition;
    }

private:

    const KeplerElements mkxElements;
    const KeplerElements mkxPeturbations;

};

#endif
