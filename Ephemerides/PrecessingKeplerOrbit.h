#ifndef PRECESSING_KEPLER_ORBIT_H
#define PRECESSING_KEPLER_ORBIT_H

#include "PerturbedKeplerOrbit.h"

class PrecessingKeplerOrbitalEphemeris
: public LinearPerturbedKeplerOrbitalEphemeris
{

public:

    PrecessingKeplerOrbitalEphemeris( const KeplerElements& xElements, const double dPrecessionRate )
    : LinearPerturbedKeplerOrbitalEphemeris( xElements, RatesFromPrecession( dPrecessionRate ) )
    {
    }

private:

    static KeplerElements RatesFromPrecession( const double dPrecessionRate )
    {
        KeplerElements xElements =
        {
            0.0,
            0.0,
            dPrecessionRate,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0
        };

        return xElements;
    }

};



#endif
