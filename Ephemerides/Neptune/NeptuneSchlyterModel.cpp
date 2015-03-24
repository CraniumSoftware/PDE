#include "NeptuneSchlyterModel.h"

#include "Time/J2000.h"

// based on work by Paul Schlyter - http://stjarnhimlen.se/

const KeplerElements NeptuneSchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 131.7806 ),
    PDE::Deg2Rad( 1.7700 ),
    PDE::Deg2Rad( 272.8461 ),
    30.05826,                               // SE - NOTE: this value is in AU
    0.008606,
    PDE::Deg2Rad( 260.2471 ),
    PDE::Deg2Rad( 0.005995147 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements NeptuneSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.000030173 ),
    PDE::Deg2Rad( 0.000000255 ),
    PDE::Deg2Rad( 0.000006027 ),
    0.00000003313,
    0.00000000215,
    0.0,
    0.0,
    0.0
};

EphemerisVector4 NeptuneSchlyterOrbitalEphemeris::Perturb( const EphemerisVector4 xPosition, const double dT ) const
{
    UNUSED( dT );
    return xPosition;
}
