#include "SimpleDwarfModels.h"

#define PERIOD_TO_RATE( period ) ( 360.0 / ( period ) )

// NOTE: order of parameters in the struct..
/*
struct KeplerElements
{
    double LongitudeOfAscendingNode;
    double Inclination;
    double ArgumentOfPerifocus;
    double SemiMajorAxis;
    double Eccentricity;
    double MeanAnomaly;
    double LongitudeRate;
    double JDTZero;
};
*/

// 1 Ceres
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 33 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements CeresKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 80.32926547452543 ),
    PDE::Deg2Rad( 10.59338616262872 ),
    PDE::Deg2Rad( 72.52203270043788 ),
    2.7675059144057,
    0.07582276595896797,
    PDE::Deg2Rad( 95.98917578768719 ),
    PERIOD_TO_RATE( 1681.633163085685 / 365.25 ),
    2457000.5 // 2014-Dec-09 00:00
};

// precession from AstDyS-2
const double CeresPrecessingOrbitalEphemeris::kdNodalPrecessionAS = -59.170034;
const double CeresPrecessingOrbitalEphemeris::kdApsidalPrecessionAS = 59.070272;

// 4 Vesta
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 33 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements VestaKeplerOrbitalEphemeris::kxElements =
{
	PDE::Deg2Rad( 103.8513672233257 ),
    PDE::Deg2Rad( 7.140427316529066 ),
    PDE::Deg2Rad( 151.1985275178533 ),
    2.361793227026224,
    0.08874017002173754,
    PDE::Deg2Rad( 20.86384148999364 ),
    0.2715446587223504,
    2457000.5 // 2014-Dec-09 00:00
};

// 2 Pallas
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 26 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements PallasKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 173.0962475866183 ),
    PDE::Deg2Rad( 34.84099788068097 ),
    PDE::Deg2Rad( 309.9303277309815 ),
    2.771606108489468,
    0.2312736282433415,
    PDE::Deg2Rad( 78.22870368538561 ),
    0.2136027349980301,
    2457000.5 // 2014-Dec-09 00:00
};

// 2060 Chiron (95P/Chiron)
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 106 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements ChironKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 209.278046346615 ),
    PDE::Deg2Rad( 6.938362251723268 ),
    PDE::Deg2Rad( 339.3496505888005 ),
    13.63836664932805,
    0.3820988964285049,
    PDE::Deg2Rad( 134.5261255528466 ),
    0.01956863493817369,
    2457000.5 // 2014-Dec-09 00:00
};

// 10199 Chariklo
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 25 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements CharikloKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 300.380270540307 ),
    PDE::Deg2Rad( 23.4113880236017 ),
    PDE::Deg2Rad( 241.7647170228786 ),
    15.76469431785065,
    0.1719643906229938,
    PDE::Deg2Rad( 63.09347765741995 ),
    0.01574619925589365,
    2457000.5 // 2014-Dec-09 00:00
};

// 134340 Pluto (Pluto-Charon barycentre actually...)
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 0 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements PlutoKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 110.3769579554089 ),
    PDE::Deg2Rad( 17.089000919562 ),
    PDE::Deg2Rad( 112.5971416774872 ),
    39.4450697257358,
    0.250248713478499,
    PDE::Deg2Rad( 25.24718971218841 ),
    0.003978459870000909,
    2457000.5 // 2014-Dec-09 00:00
};


// 136199 Eris
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 50 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements ErisKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 35.9529997103582 ),
    PDE::Deg2Rad( 44.04471305778247 ),
    PDE::Deg2Rad( 150.9754924561936 ),
    67.78065340534698,
    0.4406853397111101,
    PDE::Deg2Rad( 204.1677628412649 ),
    0.001766222639304477,
    2457000.5 // 2014-Dec-09 00:00
};

// 90377 Sedna
// source JPL small body database viewed on 2015-Aug-08
// reference: JPL 23 - /heliocentric/ coordinates with J2000.0 ecliptic
const KeplerElements SednaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 144.5452006003131 ),
    PDE::Deg2Rad( 11.92863849477524 ),
    PDE::Deg2Rad( 311.2877949215967 ),
    524.434127467771,
    0.8549069895921635,
    PDE::Deg2Rad( 358.1631284022692 ),
    0.00008206682948862652,
    2457000.5 // 2014-Dec-09 00:00
};

// Haumea
// Ixion
// Makemake
// Varuna
// Quaoar
// Salacia
// Orcus
// Makemake
// 2007 OR_10

#undef PERIOD_TO_RATE
