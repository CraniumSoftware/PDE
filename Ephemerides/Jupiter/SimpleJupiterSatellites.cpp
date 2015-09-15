#include "SimpleJupiterSatellites.h"

#include "Maths/PDEMaths.h"

// SE - TODO: ... get data from horizons and make a fit?

/*
const KeplerElements IoKeplerOrbitalEphemeris::kxElements =
{
};
*/

// Source: JPL Horizons osculating elements - these are relative to the ecliptic
// for certain... because thats what i asked for :)
const KeplerElements MetisKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 336.4005150234270 ),
    PDE::Deg2Rad( 2.230949860674993 ),
    PDE::Deg2Rad( 123.2624202368908 ),
    0.0008620661440651730,
    0.007946059897956641,
    PDE::Deg2Rad( 359.1454862030957 ),
    PDE::Deg2Rad( 1203.102420759774 ),
    2456171.5,
};

// Source: JPL Horizons osculating elements - these are relative to the ecliptic
// for certain... because thats what i asked for :)
const KeplerElements AdrasteaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 337.9367720657275 ),
    PDE::Deg2Rad( 2.279436226180493 ),
    PDE::Deg2Rad( 98.26438988098714 ),
    0.0008681044460624248,
    0.006580796501884345,
    PDE::Deg2Rad( 356.7485100936312 ),
    PDE::Deg2Rad( 1190.571587148306 ),
    2456171.5,
};

// Source: JPL Horizons osculating elements - these are relative to the ecliptic
// for certain... because thats what i asked for :)
const KeplerElements AmaltheaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 329.0107309027490 ),
    PDE::Deg2Rad( 2.015464116682605 ),
    PDE::Deg2Rad( 313.2507339673505 ),
    0.001216519191149836,
    0.00248074833492421,
    PDE::Deg2Rad( 65.17184176554154 ),
    PDE::Deg2Rad( 717.6869325429853 ),
    2456171.5,
};

// Source: JPL Horizons osculating elements - these are relative to the ecliptic
// for certain... because thats what i asked for :)
const KeplerElements ThebeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 350.8153645274925 ),
    PDE::Deg2Rad( 3.116498381975071 ),
    PDE::Deg2Rad( 351.2737497067845 ),
    0.001486538950497333,
    0.01611031342897255,
    PDE::Deg2Rad( 130.8476360249211 ),
    PDE::Deg2Rad( 531.3112906518649 ),
    2456171.5,
};

// Source: JPL Horizons osculating elements - these are relative to the ecliptic
// for certain... because thats what i asked for :)
const KeplerElements IoKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 337.2145512233379 ),
    PDE::Deg2Rad( 2.201269687356567 ),
    PDE::Deg2Rad( 98.32070501224331 ),
    0.002821049635725075,
    0.003752318988860653,
    PDE::Deg2Rad( 122.2240177752877 ),
    PDE::Deg2Rad( 203.2270727974874 ),
    2457357.5,
};

// SE - NOTE: no idea what the reference plane is... assume ecliptic?

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements LedaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 249.02157 ),
    PDE::Deg2Rad( 26.70534 ),
    PDE::Deg2Rad( 217.11857 ),
    0.0741038,
    0.1470003,
    PDE::Deg2Rad( 150.57874 ),
    PDE::Deg2Rad( 1.50972268 ),
    2442320.5, // 1974-Sep-30
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements HimaliaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 64.19257 ),
    PDE::Deg2Rad( 30.24666 ),
    PDE::Deg2Rad( 321.24132 ),
    0.0760468,
    0.1665967,
    PDE::Deg2Rad( 71.55525 ),
    PDE::Deg2Rad( 1.45238101 ),
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements ElaraKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 112.83775 ),
    PDE::Deg2Rad( 28.90366 ),
    PDE::Deg2Rad( 129.98928 ),
    0.0784653,
    0.2217152,
    PDE::Deg2Rad( 340.59927 ),
    PDE::Deg2Rad( 1.38575310 ),
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements LysitheaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 22.16328 ),
    PDE::Deg2Rad( 27.81628 ),
    PDE::Deg2Rad( 28.92678 ),
    0.0785543,
    0.1046442,
    PDE::Deg2Rad( 227.21422 ),
    PDE::Deg2Rad( 1.38339721 ),
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements AnankeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 331.30582 ),
    PDE::Deg2Rad( 146.96187 ),
    PDE::Deg2Rad( 58.72381 ),
    0.1403856,
    0.2524233,
    PDE::Deg2Rad( 144.19425 ),
    PDE::Deg2Rad( 0.57905295 ),
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements CarmeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 74.27767 ),
    PDE::Deg2Rad( 166.33569 ),
    PDE::Deg2Rad( 313.48927 ),
    0.1480462,
    0.2630848,
    PDE::Deg2Rad( 125.52653 ),
    PDE::Deg2Rad( 0.53469510 ),
    2447580.5, // 1989-Feb-23
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements PasiphaeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 315.66157 ),
    PDE::Deg2Rad( 140.03626 ),
    PDE::Deg2Rad( 173.13413 ),
    0.1561900,
    0.3801964,
    PDE::Rad2Deg( 276.60510 ),
    PDE::Deg2Rad( 0.49342641 ),
    2451540.5, // 1999-Dec-28
};

// Source: http://www.projectpluto.com/jsats.htm 2015-Aug-16
const KeplerElements SinopeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 269.90288 ),
    PDE::Deg2Rad( 157.95047 ),
    PDE::Deg2Rad( 301.07683 ),
    0.1583604,
    0.3699151,
    PDE::Deg2Rad( 92.16244 ),
    PDE::Deg2Rad( 0.48331731 ),
    2447580.5, // 1989-Feb-23
};
