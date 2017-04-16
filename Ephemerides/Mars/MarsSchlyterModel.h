#ifndef MARS_SCHLYTER_MODEL_H
#define MARS_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PerturbedKeplerOrbit.h"

class MarsSchlyterOrbitalEphemeris
: public LinearPerturbedKeplerOrbitalEphemeris
{

public:

    MarsSchlyterOrbitalEphemeris()
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
