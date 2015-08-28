#include "SimpleJupiterSatellites.h"

#include "Maths/PDEMaths.h"

// SE - TODO: ... get data from horizons and make a fit?

/*
const KeplerElements IoKeplerOrbitalEphemeris::kxElements =
{
};
*/

// SE - NOTE: no idea what the reference plane is... assume ecliptic?

// Source: JPL Horizons.
const KeplerElements AmaltheaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 249.02157 ),
    PDE::Rad2Deg( 2.015464116682605 ),
    PDE::Rad2Deg( 313.2507339673505 ),
    0.0001216519191149836,
    0.000248074833492421,
    PDE::Rad2Deg( 65.17184176554154 ),
    717.6869325429853,
    2456171.5,
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements LedaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 249.02157 ),
    PDE::Rad2Deg( 26.70534 ),
    PDE::Rad2Deg( 217.11857 ),
    0.0741038,
    0.1470003,
    PDE::Rad2Deg( 150.57874 ),
    1.50972268,
    2442320.5, // 1974-Sep-30
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements HimaliaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 64.19257 ),
    PDE::Rad2Deg( 30.24666 ),
    PDE::Rad2Deg( 321.24132 ),
    0.0760468,
    0.1665967,
    PDE::Rad2Deg( 71.55525 ),
    1.45238101,
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements ElaraKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 112.83775 ),
    PDE::Rad2Deg( 28.90366 ),
    PDE::Rad2Deg( 129.98928 ),
    0.0784653,
    0.2217152,
    PDE::Rad2Deg( 340.59927 ),
    1.38575310,
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements LysitheaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 22.16328 ),
    PDE::Rad2Deg( 27.81628 ),
    PDE::Rad2Deg( 28.92678 ),
    0.0785543,
    0.1046442,
    PDE::Rad2Deg( 227.21422 ),
    1.38339721,
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements AnankeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 331.30582 ),
    PDE::Rad2Deg( 146.96187 ),
    PDE::Rad2Deg( 58.72381 ),
    0.1403856,
    0.2524233,
    PDE::Rad2Deg( 144.19425 ),
    0.57905295,
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements CarmeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 74.27767 ),
    PDE::Rad2Deg( 166.33569 ),
    PDE::Rad2Deg( 313.48927 ),
    0.1480462,
    0.2630848,
    PDE::Rad2Deg( 125.52653 ),
    0.53469510,
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements PasiphaeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 315.66157 ),
    PDE::Rad2Deg( 140.03626 ),
    PDE::Rad2Deg( 173.13413 ),
    0.1561900,
    0.3801964,
    PDE::Rad2Deg( 276.60510 ),
    0.49342641,
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements SinopeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Rad2Deg( 269.90288 ),
    PDE::Rad2Deg( 157.95047 ),
    PDE::Rad2Deg( 301.07683 ),
    0.1583604,
    0.3699151,
    PDE::Rad2Deg( 92.16244 ),
    0.48331731,
    2447580.5, // 1989-Feb-23
};
