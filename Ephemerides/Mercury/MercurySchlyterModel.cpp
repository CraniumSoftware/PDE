#include "MercurySchlyterModel.h"

#include "Time/J2000.h"

const KeplerElements MercurySchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 48.3313 ),
    PDE::Deg2Rad( 7.0047 ),
    PDE::Deg2Rad( 29.1241 ),
    0.387098,
    0.205635,
    PDE::Deg2Rad( 168.6562 ),
    PDE::Deg2Rad( 4.0923344368 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements MercurySchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.0000324587 ),
    PDE::Deg2Rad( 0.00000005 ),
    PDE::Deg2Rad( 0.0000101444 ),
    0.0,
    0.000000000559,
    0.0,
    0.0,
    0.0
};
