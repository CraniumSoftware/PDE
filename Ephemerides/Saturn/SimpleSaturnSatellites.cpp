#include "SimpleSaturnSatellites.h"

#include "Maths/PDEMaths.h"

// Source: JPL Horizons osculating elements - these are a bit poo...

// SE - TODO: ... get data from horizons and make a fit?

const KeplerElements MimasKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 172.8195430256500 ),
    PDE::Deg2Rad( 28.26331709426426 ),
    PDE::Deg2Rad( 164.7238222543176 ),
    0.001243383354946876,
    0.01721672187668573,
    PDE::Deg2Rad( 146.2476268047056 ),
    PDE::Deg2Rad( 380.0485075866404 ),
    2457357.5,
};

const KeplerElements EnceladusKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 169.5403864930999 ),
    PDE::Deg2Rad( 28.05353047432844 ),
    PDE::Deg2Rad( 279.8773559504135 ),
    0.001593684797397002,
    0.003490668641596399,
    PDE::Deg2Rad( 231.3274628214938 ),
    PDE::Deg2Rad( 261.9045163062615 ),
    2457357.5,
};

const KeplerElements TethysKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 170.7273971890666 ),
    PDE::Deg2Rad( 27.11013986128690 ),
    PDE::Deg2Rad( 135.2466160642357 ),
    0.001971785413155788,
    0.0008930148781933422,
    PDE::Deg2Rad( 5.151629237952450 ),
    PDE::Deg2Rad( 190.3081347389100 ),
    2457357.5,
};

const KeplerElements DioneKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 169.5727617713781 ),
    PDE::Deg2Rad( 28.03181958137696 ),
    PDE::Deg2Rad( 316.9871895202594 ),
    0.002524419594672638,
    0.002182368533512025,
    PDE::Deg2Rad( 86.72349887553153 ),
    PDE::Deg2Rad( 131.3725699221209 ),
    2457357.5,
};

const KeplerElements RheaKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 169.8450010905685 ),
    PDE::Deg2Rad( 27.72910764221532 ),
    PDE::Deg2Rad( 183.4749662173673 ),
    0.003524169714896815,
    0.0008120887236221020,
    PDE::Deg2Rad( 66.84252503214131 ),
    PDE::Deg2Rad( 79.64568468579830 ),
    2457357.5,
};

const KeplerElements TitanKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 169.1214075143673 ),
    PDE::Deg2Rad( 27.69762932105365 ),
    PDE::Deg2Rad( 172.6134982086283 ),
    0.0008620661440651730,
    0.008168240306914140,
    PDE::Deg2Rad( 344.0053191123051 ),
    PDE::Deg2Rad( 22.57382861540970 ),
    2457357.5,
};

const KeplerElements HyperionKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 169.0027491039836 ),
    PDE::Deg2Rad( 26.99658544103995 ),
    PDE::Deg2Rad( 244.6440144557191 ),
    0.009915886085161314,
    0.1112336199702701,
    PDE::Deg2Rad( 78.75694821952330 ),
    PDE::Deg2Rad( 16.87521441735059 ),
    2457357.5,
};

const KeplerElements IapetusKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 138.9813686556323 ),
    PDE::Deg2Rad( 17.07888466737910 ),
    PDE::Deg2Rad( 230.0364086757111 ),
    0.02383088504980740,
    0.02882213432591505,
    PDE::Deg2Rad( 305.1434552831972 ),
    PDE::Deg2Rad( 4.529361905651579 ),
    2457357.5,
};

const KeplerElements PhoebeKeplerOrbitalEphemeris::kxElements =
{
    PDE::Deg2Rad( 268.1760002803331 ),
    PDE::Deg2Rad( 173.1055006933195 ),
    PDE::Deg2Rad( 78.51919615136495 ),
    0.08639423543872794,
    0.1472971080767609,
    PDE::Deg2Rad( 251.1107233929098 ),
    PDE::Deg2Rad( 0.6561746460595884 ),
    2457357.5,
};
