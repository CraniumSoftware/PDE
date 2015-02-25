#include "EarthSchlyterModel.h"

#include "Time/J2000.h"

const KeplerElements EarthSchlyterOrbitalEphemeris::kxBaseElements =
{
    0.0,
    0.0,
    Maths::Deg2Rad( 282.9404 ),
    -1.0, // SE - NOTE: these elements are actually for the sun from earth, so this is -1AU (!)
    0.016709,
    Maths::Deg2Rad( 356.0470 ),
    Maths::Deg2Rad( 0.9856002585 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements EarthSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    0.0,
    0.0,
    Maths::Deg2Rad( 0.0000470935 ),
    0.0,
    0.000000001151,
    0.0,
    0.0,
    0.0
};
