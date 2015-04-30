#include "MoonSchlyterModel.h"

#include "EarthSchlyterModel.h"

#include "Time/J2000.h"

/*

N = 125.1228 - 0.0529538083 * d
i = 5.1454
w = 318.0634 + 0.1643573223 * d
a = 60.2666  (Earth radii)
e = 0.054900
M = 115.3654 + 13.0649929509 * d

*/
const double kdEarthRadiiAU = 6371.009 / 149597870.7;

const KeplerElements MoonSchlyterOrbitalEphemeris::kxBaseElements =
{
	PDE::Deg2Rad( 125.1228 ),
	PDE::Deg2Rad( 5.1454 ),
	PDE::Deg2Rad( 282.9404 ),
	-60.2666 * kdEarthRadiiAU,
	0.054900,
	PDE::Deg2Rad( 115.3654 ),
	PDE::Deg2Rad( 13.0649929509 ),
	static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements MoonSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
	PDE::Deg2Rad( -0.0529538083 ),
	0.0,
	PDE::Deg2Rad( 0.1643573223 ),
	0.0,
	0.0,
	0.0,
	0.0,
	0.0
};

EphemerisVector4 MoonSchlyterOrbitalEphemeris::Perturb( const EphemerisVector4 xPosition, const double dT ) const
{
	const double dEclipticLongitude = CalculateLongitude( xPosition );
	const double dEclipticLatitude = CalculateLatitude( xPosition );

	const double dMeanAnomalyMoon = MeanAnomaly( dT );
	const double dMeanAnomalyEarth = EarthSchlyterOrbitalEphemeris::MeanAnomaly( dT );

	EarthSchlyterOrbitalEphemeris xEarthEphemeris;
	MoonSchlyterOrbitalEphemeris xMoonEphemeris;
	const double dArgumentOfPerifocusEarth = xEarthEphemeris.EvaluateArgumentOfPerifocus( dT );
	//const double dTrueAnomalyEarth = xEarthEphemeris.EvaluateTrueAnomaly( dT );

	const double dLongitudeOfAscendingNodeMoon = xMoonEphemeris.EvaluateLongitudeOfAscendingNode( dT );
	const double dArgumentOfPerifocusMoon = xMoonEphemeris.EvaluateArgumentOfPerifocus( dT );
	//const double dTrueAnomalyMoon = xMoonEphemeris.EvaluateTrueAnomaly( dT );

	const double dLongitudeSun = dMeanAnomalyEarth + dArgumentOfPerifocusEarth;
	const double dLongitudeMoon = dMeanAnomalyMoon + dArgumentOfPerifocusMoon + dLongitudeOfAscendingNodeMoon;

	const double dElongationMoon = dLongitudeMoon - dLongitudeSun;
	const double dArgumentOfLatitudeMoon = dLongitudeMoon - dLongitudeOfAscendingNodeMoon;

	// D = elongation moon
	// F = latitude thing
	const double dCorrectedLongitude = dEclipticLongitude
		- 1.274 * PDE::Sin( dMeanAnomalyEarth - 2.0 * dElongationMoon )	// evection
		+ 0.658 * PDE::Sin( 2.0 * dElongationMoon )						// variation
		- 0.186 * PDE::Sin( dMeanAnomalyEarth )							// yearly equation
		- 0.059 * PDE::Sin( 2.0 * ( dMeanAnomalyMoon - dElongationMoon ) )
		- 0.057 * PDE::Sin( dMeanAnomalyMoon - 2.0 * dElongationMoon + dMeanAnomalyEarth )
		+ 0.053 * PDE::Sin( dMeanAnomalyMoon + 2.0 * dElongationMoon )
		+ 0.046 * PDE::Sin( 2.0 * dElongationMoon - dMeanAnomalyEarth )
		+ 0.041 * PDE::Sin( dMeanAnomalyMoon - dMeanAnomalyEarth )
		- 0.035 * PDE::Sin( dElongationMoon )							// parallactic equation
		- 0.031 * PDE::Sin( dMeanAnomalyMoon + dMeanAnomalyEarth )
		- 0.015 * PDE::Sin( 2.0 * ( dArgumentOfLatitudeMoon - dElongationMoon ) )
		+ 0.011 * PDE::Sin( dMeanAnomalyMoon - 4.0 * dElongationMoon );

	const double dCorrectedLatitude = dEclipticLatitude
		- 0.173 * PDE::Sin( dArgumentOfLatitudeMoon - 2.0 * dElongationMoon )
		- 0.055 * PDE::Sin( dMeanAnomalyMoon - dArgumentOfLatitudeMoon - 2.0 * dElongationMoon )
		- 0.046 * PDE::Sin( dMeanAnomalyMoon + dArgumentOfLatitudeMoon - 2.0 * dElongationMoon )
		+ 0.033 * PDE::Sin( dArgumentOfLatitudeMoon + 2.0 * dElongationMoon )
		+ 0.017 * PDE::Sin( 2.0 * dMeanAnomalyMoon + dArgumentOfLatitudeMoon );

    const double dCorrectedDistance = xPosition.xyz().Magnitude()
        - 0.58 * kdEarthRadiiAU * PDE::Cos( dMeanAnomalyMoon - 2.0 * dElongationMoon )
        - 0.46 * kdEarthRadiiAU * PDE::Cos( 2.0 * dElongationMoon );
        ;

    return PositionFromLatLonRad( dCorrectedLatitude, dCorrectedLongitude, dCorrectedDistance );
}
