#ifndef SATURN_SCHLYTER_MODEL_H
#define SATURN_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PeturbedKeplerOrbit.h"

class SaturnSchlyterOrbitalEphemeris
: public SpeciallyPeturbedKeplerOrbitalEphemeris< SaturnSchlyterOrbitalEphemeris >
{

public:

    SaturnSchlyterOrbitalEphemeris()
    : SpeciallyPeturbedKeplerOrbitalEphemeris( kxBaseElements, kxLinearPeturbations )
    {

    }

    EphemerisVector4 Peturb( const EphemerisVector4 xPosition, const double dT ) const;

    static double MeanAnomaly( const double dT )
    {
        return kxBaseElements.MeanAnomaly + kxBaseElements.LongitudeRate * dT;
    }

private:

    static const KeplerElements kxBaseElements;
    static const KeplerElements kxLinearPeturbations;

};

#endif
