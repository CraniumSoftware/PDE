#include "SaturnSchlyterModel.h"

#include "Ephemerides/Jupiter/JupiterSchlyterModel.h"
#include "Time/J2000.h"

// based on work by Paul Schlyter - http://stjarnhimlen.se/

const KeplerElements SaturnSchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 113.6634 ),
    PDE::Deg2Rad( 2.4886 ),
    PDE::Deg2Rad( 339.3939 ),
    9.55475,                                // SE - NOTE: this value is in AU
    0.055546,
    PDE::Deg2Rad( 316.9670 ),
    PDE::Deg2Rad( 0.0334442282 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements SaturnSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.00002398 ),
    PDE::Deg2Rad( 0.0000001081 ),
    PDE::Deg2Rad( 0.0000297661 ),
    0.0,
    0.000000009499,
    0.0,
    0.0,
    0.0
};

// based on work by Paul Schlyter - http://stjarnhimlen.se/
EphemerisVector4 SaturnSchlyterOrbitalEphemeris::Perturb( const EphemerisVector4 xPosition, const double dT ) const
{
    const double dEclipticLongitude = CalculateLongitude( xPosition );
    const double dEclipticLatititude = CalculateLatitude( xPosition );

    const double dMeanAnomalyJupiter = JupiterSchlyterOrbitalEphemeris::MeanAnomaly( dT );
    const double dMeanAnomalySaturn = MeanAnomaly( dT );

    const double dCorrectedLongitude = dEclipticLongitude + PDE::Deg2Rad(
        + 0.812 * PDE::Sin( 2.0 * dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 67.6 ) )
        - 0.229 * PDE::Cos( 2.0 * dMeanAnomalyJupiter - 4.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 2.0 ) )
        + 0.119 * PDE::Sin( dMeanAnomalyJupiter - 2.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 3.0 ) )
        + 0.046 * PDE::Sin( 2.0 * dMeanAnomalyJupiter - 6.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 69.0 ) )
        + 0.014 * PDE::Sin( dMeanAnomalyJupiter - 3.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 32.0 ) ) );

    const double dCorrectedLatitude = dEclipticLatititude + PDE::Deg2Rad(
        - 0.020 * PDE::Cos( 2.0 * dMeanAnomalyJupiter - 4.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 2.0 ) )
        + 0.018 * PDE::Sin( 2.0* dMeanAnomalyJupiter - 6.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 49.0 ) ) );

    return PositionFromLatLonRad( dCorrectedLatitude, dCorrectedLongitude, CalculateRadius( xPosition ) );
}
