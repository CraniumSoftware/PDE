#ifndef JUPITER_SCHLYTER_MODEL_H
#define JUPITER_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PeturbedKeplerOrbit.h"

class JupiterSchlyterOrbitalEphemeris
: public SpeciallyPeturbedKeplerOrbitalEphemeris< JupiterSchlyterOrbitalEphemeris >
{

public:

    JupiterSchlyterOrbitalEphemeris()
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
