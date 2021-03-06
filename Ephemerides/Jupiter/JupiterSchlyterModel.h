#ifndef JUPITER_SCHLYTER_MODEL_H
#define JUPITER_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PerturbedKeplerOrbit.h"

class JupiterSchlyterOrbitalEphemeris
: public SpeciallyPerturbedKeplerOrbitalEphemeris< JupiterSchlyterOrbitalEphemeris >
{

public:

    JupiterSchlyterOrbitalEphemeris()
    : SpeciallyPerturbedKeplerOrbitalEphemeris( kxBaseElements, kxLinearPerturbations )
    {

    }

    EphemerisVector4 Perturb( const EphemerisVector4 xPosition, const double dT ) const;

    static double MeanAnomaly( const double dT )
    {
        return kxBaseElements.MeanAnomaly + kxBaseElements.LongitudeRate * dT;
    }
    
    static double EvaluatePeriod( const double )
    {
        return 2.0 * PDE::PiDouble / kxBaseElements.LongitudeRate;
    }

private:

    static const KeplerElements kxBaseElements;
    static const KeplerElements kxLinearPerturbations;

};

#endif
