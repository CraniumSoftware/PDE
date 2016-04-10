#include "SimpleMarsSatellites.h"

#include "Maths/PDEMaths.h"

// Source: JPL Horizons osculating elements - these are a bit poo...

// SE - TODO: ... get data from horizons and make a fit?
const KeplerElements PhobosKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 84.23566721051388 ),
    PDE::Deg2Rad( 27.59637161156688 ),
    PDE::Deg2Rad( 74.28143347197008 ),
    0.000062694413457396,
    0.01500912502173397,
    PDE::Deg2Rad( 87.95198911650512 ),
    PDE::Deg2Rad( 1127.900492408475 ),
    2457540.5,
};

const KeplerElements DeimosKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 78.67850339283348 ),
    PDE::Deg2Rad( 25.72642770087603 ),
    PDE::Deg2Rad( 308.2798542483124 ),
    0.0001568152232546999,
    0.0002275406044330242,
    PDE::Deg2Rad( 321.6462787910933 ),
    PDE::Deg2Rad( 285.1209426657056 ),
    2457540.5,
};


