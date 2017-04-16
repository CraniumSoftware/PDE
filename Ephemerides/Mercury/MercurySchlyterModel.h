#ifndef MERCURY_SCHLYTER_MODEL_H
#define MERCURY_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PerturbedKeplerOrbit.h"

class MercurySchlyterOrbitalEphemeris
: public LinearPerturbedKeplerOrbitalEphemeris
{

public:

    MercurySchlyterOrbitalEphemeris()
    : LinearPerturbedKeplerOrbitalEphemeris( kxBaseElements, kxLinearPerturbations )
    {

    }

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
