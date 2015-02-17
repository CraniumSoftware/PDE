#include "VenusSchlyterModel.h"

#include "Time/J2000.h"

const KeplerElements VenusSchlyterOrbitalEphemeris::kxBaseElements =
{
    Maths::Deg2Rad( 76.6799 ),
    Maths::Deg2Rad( 3.3946 ),
    Maths::Deg2Rad( 54.8910 ),
    0.723330,
    0.006773,
    Maths::Deg2Rad( 48.0052 ),
    Maths::Deg2Rad( 1.6021302244 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements VenusSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    Maths::Deg2Rad( 0.000024659 ),
    Maths::Deg2Rad( 0.0000000275 ),
    Maths::Deg2Rad( 0.0000138374 ),
    0.0,
    0.000000001302,
    0.0,
    0.0,
    0.0
};
