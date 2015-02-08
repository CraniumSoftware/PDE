#include "JupiterSchlyterModel.h"

#include "Ephemerides/Saturn/SaturnSchlyterModel.h"
#include "Time/J2000.h"

// based on work by Paul Schlyter - http://stjarnhimlen.se/

const KeplerElements JupiterSchlyterOrbitalEphemeris::kxBaseElements =
{
    Maths::Deg2Rad( 100.4542 ),
    Maths::Deg2Rad( 1.3030 ),
    Maths::Deg2Rad( 273.8777 ),
    5.20256,                                // SE - NOTE: this value is in AU
    0.048498,
    Maths::Deg2Rad( 19.8950 ),
    Maths::Deg2Rad( 0.0830853001 ),
    static_cast< double >( J2000 )
};

const KeplerElements JupiterSchlyterOrbitalEphemeris::kxLinearPeturbations =
{
    Maths::Deg2Rad( 0.0000276854 ),
    Maths::Deg2Rad( 0.0000001557 ),
    Maths::Deg2Rad( 0.0000164505 ),
    0.0,
    0.000000004469,
    0.0,
    0.0,
    0.0
};

EphemerisVector4 JupiterSchlyterOrbitalEphemeris::Peturb( const EphemerisVector4 xPosition, const double dT ) const
{
    const double dEclipticLongitude = CalculateLongitude( xPosition );

    const double dMeanAnomalyJupiter = MeanAnomaly( dT );
    const double dMeanAnomalySaturn = SaturnSchlyterOrbitalEphemeris::MeanAnomaly( dT );

    const double dCorrectedLongitude = dEclipticLongitude + Maths::Deg2Rad(
        - 0.332 * Maths::Sin( 2.0 * dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn - Maths::Deg2Rad( 67.6 ) )
        - 0.056 * Maths::Sin( 2.0 * dMeanAnomalyJupiter - 2.0 * dMeanAnomalySaturn + Maths::Deg2Rad( 21.0 ) )
        + 0.042 * Maths::Sin( 3.0 * dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn + Maths::Deg2Rad( 21.0 ) )
        - 0.036 * Maths::Sin( dMeanAnomalyJupiter - 2.0 * dMeanAnomalySaturn )
        + 0.022 * Maths::Cos( dMeanAnomalyJupiter - dMeanAnomalySaturn )
        + 0.023 * Maths::Sin( 2.0 * dMeanAnomalyJupiter - 3.0 * dMeanAnomalySaturn + Maths::Deg2Rad( 52.0 ) )
        - 0.016 * Maths::Sin( dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn - Maths::Deg2Rad( 69.0 ) ) );

    return PositionFromLatLonRad( CalculateLatitude( xPosition ), dCorrectedLongitude, CalculateRadius( xPosition ) );
}
