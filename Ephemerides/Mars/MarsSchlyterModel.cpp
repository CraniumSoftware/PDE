#include "MarsSchlyterModel.h"

#include "Time/J2000.h"

const KeplerElements MarsSchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 49.5574 ),
    PDE::Deg2Rad( 1.8497 ),
    PDE::Deg2Rad( 286.5016 ),
    1.523688,
    0.093405,
    PDE::Deg2Rad( 18.6021 ),
    PDE::Deg2Rad( 0.5240207766 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements MarsSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.0000211081 ),
    PDE::Deg2Rad( 0.0000000178 ),
    PDE::Deg2Rad( 0.0000292961 ),
    0.0,
    0.000000002516,
    0.0,
    0.0,
    0.0
};
