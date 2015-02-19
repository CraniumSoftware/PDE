#ifndef PRECESSING_KEPLER_ORBIT_H
#define PRECESSING_KEPLER_ORBIT_H

#include "PerturbedKeplerOrbit.h"

class PrecessingKeplerOrbitalEphemeris
: public LinearPerturbedKeplerOrbitalEphemeris
{

public:

    PrecessingKeplerOrbitalEphemeris( const KeplerElements& xElements, const double dApsidalPrecessionRate, const double dNodalPrecessionRate = 0.0 )
    : LinearPerturbedKeplerOrbitalEphemeris( xElements, RatesFromPrecession( dApsidalPrecessionRate, dNodalPrecessionRate ) )
    {
    }

private:

    static KeplerElements RatesFromPrecession( const double dApsidalPrecessionRate, const double dNodalPrecessionRate )
    {
        KeplerElements xElements =
        {
            dNodalPrecessionRate,
            0.0,
            dApsidalPrecessionRate,
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
