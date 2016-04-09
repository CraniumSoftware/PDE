#include "SimpleNeptuneSatellites.h"

#include "Maths/PDEMaths.h"

// Source: JPL Horizons osculating elements - these are a bit poo...

// SE - TODO: ... get data from horizons and make a fit?
const KeplerElements ProteusKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 48.67923049824508 ),
    PDE::Deg2Rad( 29.00262210722058 ),
    PDE::Deg2Rad( 100.8095396037377 ),
    0.0007865990868922024,
    0.0002969708815082389,
    PDE::Deg2Rad( 179.5259162411381 ),
    PDE::Deg2Rad( 320.6199341130576 ),
    2457540.5,
};

const KeplerElements LarissaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 49.41272720157301 ),
    PDE::Deg2Rad( 28.57731031221357 ),
    PDE::Deg2Rad( 25.11418622954386 ),
    0.0004919267440762348,
    0.001032904896286922,
    PDE::Deg2Rad( 115.8641275424695 ),
    PDE::Deg2Rad( 648.2910505758381 ),
    2457540.5,
};

const KeplerElements TritonKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 220.1188526644335 ),
    PDE::Deg2Rad( 129.4592345664539 ),
    PDE::Deg2Rad( 131.6920439923858 ),
    0.002371464901244356,
    0.00002433520357203326,
    PDE::Deg2Rad( 14.29235576990990 ),
    PDE::Deg2Rad( 61.25491968330106 ),
    2457540.5,
};

const KeplerElements NereidKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 318.6861131773234 ),
    PDE::Deg2Rad( 5.061002234094499 ),
    PDE::Deg2Rad( 297.6077044818942 ),
    0.03685245829053791,
    0.7457700346078655,
    PDE::Deg2Rad( 89.63360234002462 ),
    PDE::Deg2Rad( 0.9998180718772826 ),
    2457540.5,
};
