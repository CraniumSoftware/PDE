#include "SimpleUranusSatellites.h"

#include "Maths/PDEMaths.h"

// Source: JPL Horizons osculating elements - these are a bit poo...

// SE - TODO: ... get data from horizons and make a fit?
const KeplerElements MirandaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 170.9460103073334 ),
    PDE::Deg2Rad( 94.77857984119674 ),
    PDE::Deg2Rad( 212.5868440096615 ),
    0.00008681901407812856,
    0.001230231924977131,
    PDE::Deg2Rad( 157.6156094711810 ),
    PDE::Deg2Rad( 254.5737179486985 ),
    2457388.5,
};

const KeplerElements ArielKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 167.6423071777273 ),
    PDE::Deg2Rad( 97.71236302845948 ),
    PDE::Deg2Rad( 118.2374164879954 ),
    0.0001276396566903116,
    0.000005956059261728208,
    PDE::Deg2Rad( 259.8168037791155 ),
    PDE::Deg2Rad( 142.8105740360522 ),
    2457388.5,
};

const KeplerElements UmbrielKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 167.6839018620668 ),
    PDE::Deg2Rad( 97.69628914545717 ),
    PDE::Deg2Rad( 35.87925981291052 ),
    0.0001778003916856419,
    0.0003984818946748888,
    PDE::Deg2Rad( 228.6245528556004 ),
    PDE::Deg2Rad( 86.86713787590800 ),
    2457388.5,
};

const KeplerElements OberonKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 167.7299698222889 ),
    PDE::Deg2Rad( 97.90845910983128 ),
    PDE::Deg2Rad( 188.0733081100501 ),
    0.0003900401478748398,
    0.0002237525186702863,
    PDE::Deg2Rad( 171.5960678083162 ),
    PDE::Deg2Rad( 26.73495172924977 ),
    2457388.5,
};

const KeplerElements TitaniaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 167.621081309228 ),
    PDE::Deg2Rad( 97.78872505437343 ),
    PDE::Deg2Rad( 270.1565814487489 ),
    0.0002917416496922828,
    0.0001508404932909069,
    PDE::Deg2Rad( 83.37657769175556 ),
    PDE::Deg2Rad( 41.32820390833963 ),
    2457388.5,
};
