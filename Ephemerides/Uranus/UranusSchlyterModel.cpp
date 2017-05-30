#include "UranusSchlyterModel.h"

#include "Ephemerides/Jupiter/JupiterSchlyterModel.h"
#include "Ephemerides/Saturn/SaturnSchlyterModel.h"
#include "Time/J2000.h"

// based on work by Paul Schlyter - http://stjarnhimlen.se/

const KeplerElements UranusSchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 74.0005 ),
    PDE::Deg2Rad( 0.7733 ),
    PDE::Deg2Rad( 96.6612 ),
    19.18171,                               // SE - NOTE: this value is in AU
    0.047318,
    PDE::Deg2Rad( 142.5905 ),
    PDE::Deg2Rad( 0.011725806 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements UranusSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.000013978 ),
    PDE::Deg2Rad( 0.000000019 ),
    PDE::Deg2Rad( 0.000030565 ),
    0.0000000155,
    0.00000000745,
    0.0,
    0.0,
    0.0
};

// based on work by Paul Schlyter - http://stjarnhimlen.se/
EphemerisVector4 UranusSchlyterOrbitalEphemeris::Perturb( const EphemerisVector4 xPosition, const double dT ) const
{
    const double dEclipticLongitude = CalculateLongitude( xPosition );

    const double dMeanAnomalyJupiter = JupiterSchlyterOrbitalEphemeris::MeanAnomaly( dT );
    const double dMeanAnomalySaturn = SaturnSchlyterOrbitalEphemeris::MeanAnomaly( dT );
    const double dMeanAnomalyUranus = MeanAnomaly( dT );

    const double dCorrectedLongitude = dEclipticLongitude + PDE::Deg2Rad(
        + 0.040 * PDE::Sin( dMeanAnomalySaturn - 2.0 * dMeanAnomalyUranus + PDE::Deg2Rad( 6.0 ) )
        + 0.035 * PDE::Sin( dMeanAnomalySaturn - 3.0 * dMeanAnomalyUranus + PDE::Deg2Rad( 33.0 ) )
        - 0.015 * PDE::Sin( dMeanAnomalyJupiter - dMeanAnomalyUranus + PDE::Deg2Rad( 20.0 ) ) );

    return PositionFromLatLonRad( CalculateLatitude( xPosition ), dCorrectedLongitude, CalculateRadius( xPosition ) );
}
