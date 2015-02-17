#ifndef EARTH_SCHLYTER_MODEL_H
#define EARTH_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PerturbedKeplerOrbit.h"

class EarthSchlyterOrbitalEphemeris
: public LinearPerturbedKeplerOrbitalEphemeris
{

public:

    EarthSchlyterOrbitalEphemeris()
    : LinearPerturbedKeplerOrbitalEphemeris( kxBaseElements, kxLinearPerturbations )
    {

    }

    static double MeanAnomaly( const double dT )
    {
        return kxBaseElements.MeanAnomaly + kxBaseElements.LongitudeRate * dT;
    }

private:

    static const KeplerElements kxBaseElements;
    static const KeplerElements kxLinearPerturbations;

};

#endif
