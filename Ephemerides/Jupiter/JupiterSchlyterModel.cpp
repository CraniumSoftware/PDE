#include "JupiterSchlyterModel.h"

#include "Ephemerides/Saturn/SaturnSchlyterModel.h"
#include "Time/J2000.h"

// based on work by Paul Schlyter - http://stjarnhimlen.se/

const KeplerElements JupiterSchlyterOrbitalEphemeris::kxBaseElements =
{
    PDE::Deg2Rad( 100.4542 ),
    PDE::Deg2Rad( 1.3030 ),
    PDE::Deg2Rad( 273.8777 ),
    5.20256,                                // SE - NOTE: this value is in AU
    0.048498,
    PDE::Deg2Rad( 19.8950 ),
    PDE::Deg2Rad( 0.0830853001 ),
    static_cast< double >( J2000 - 1.5 )    // SE - NOTE: these elements have an epoch of '0' Jan 2000, 1.5 days before J2000.0
};

const KeplerElements JupiterSchlyterOrbitalEphemeris::kxLinearPerturbations =
{
    PDE::Deg2Rad( 0.0000276854 ),
    PDE::Deg2Rad( 0.0000001557 ),
    PDE::Deg2Rad( 0.0000164505 ),
    0.0,
    0.000000004469,
    0.0,
    0.0,
    0.0
};

EphemerisVector4 JupiterSchlyterOrbitalEphemeris::Perturb( const EphemerisVector4 xPosition, const double dT ) const
{
    const double dEclipticLongitude = CalculateLongitude( xPosition );

    const double dMeanAnomalyJupiter = MeanAnomaly( dT );
    const double dMeanAnomalySaturn = SaturnSchlyterOrbitalEphemeris::MeanAnomaly( dT );

    const double dCorrectedLongitude = dEclipticLongitude + PDE::Deg2Rad(
        - 0.332 * PDE::Sin( 2.0 * dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn - PDE::Deg2Rad( 67.6 ) )
        - 0.056 * PDE::Sin( 2.0 * dMeanAnomalyJupiter - 2.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 21.0 ) )
        + 0.042 * PDE::Sin( 3.0 * dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 21.0 ) )
        - 0.036 * PDE::Sin( dMeanAnomalyJupiter - 2.0 * dMeanAnomalySaturn )
        + 0.022 * PDE::Cos( dMeanAnomalyJupiter - dMeanAnomalySaturn )
        + 0.023 * PDE::Sin( 2.0 * dMeanAnomalyJupiter - 3.0 * dMeanAnomalySaturn + PDE::Deg2Rad( 52.0 ) )
        - 0.016 * PDE::Sin( dMeanAnomalyJupiter - 5.0 * dMeanAnomalySaturn - PDE::Deg2Rad( 69.0 ) ) );

    return PositionFromLatLonRad( CalculateLatitude( xPosition ), dCorrectedLongitude, CalculateRadius( xPosition ) );
}

// SE - for testing this. here are some things from JPL HORIZONS:

/*

JDCT     Epoch Julian Date, Coordinate Time
EC     Eccentricity, e
QR     Periapsis distance, q (AU)
IN     Inclination w.r.t xy-plane, i (degrees)
OM     Longitude of Ascending Node, OMEGA, (degrees)
W      Argument of Perifocus, w (degrees)
Tp     Time of periapsis (Julian day number)
N      Mean motion, n (degrees/day)
MA     Mean anomaly, M (degrees)
TA     True anomaly, nu (degrees)
A      Semi-major axis, a (AU)
AD     Apoapsis distance (AU)
PR     Sidereal orbit period (day)

$$SOE
2451543.499305556 = A.D. 1999-Dec-30 23:59:00.0000 (CT)
EC= 4.760266146577531E-02 QR= 4.941881820320790E+00 IN= 1.304249095785330E+00
OM= 1.004855856879577E+02 W = 2.740404914152955E+02 Tp=  2451307.053390536923
N = 8.332254519130179E-02 MA= 1.970127543944724E+01 TA= 2.164867175746756E+01
A = 5.188886634150545E+00 AD= 5.435891447980300E+00 PR= 4.320559329692454E+03
2451543.500000000 = A.D. 1999-Dec-31 00:00:00.0000 (CT)
EC= 4.760266327510847E-02 QR= 4.941881817231745E+00 IN= 1.304249095529346E+00
OM= 1.004855857113374E+02 W = 2.740404896597826E+02 Tp=  2451307.053371944930
N = 8.332254503198587E-02 MA= 1.970133481378133E+01 TA= 2.164873680111101E+01
A = 5.188886640764779E+00 AD= 5.435891464297813E+00 PR= 4.320559337953529E+03
$$EOE

a good check is that the elements are very similar to the ones we use...

some state vectors:

*******************************************************************************
JDCT
X     Y     Z
VX    VY    VZ
LT    RG    RR
*******************************************************************************
$$SOE
2451544.499305556 = A.D. 1999-Dec-31 23:59:00.0000 (CT)
3.996324096215535E+00  2.932557167699681E+00 -1.016171415245803E-01
-4.558092395680070E-03  6.439351791957842E-03  7.536193377477587E-05
2.863447230701806E-02  4.957905189419349E+00  1.332205215082165E-04
2451544.500000000 = A.D. 2000-Jan-01 00:00:00.0000 (CT)
3.996320930871260E+00  2.932561639470049E+00 -1.016170891898448E-01
-4.558099114412832E-03  6.439346867046017E-03  7.536210451254523E-05
2.863447284133657E-02  4.957905281933733E+00  1.332209056792701E-04
$$EOE
*******************************************************************************
Coordinate system description:

Ecliptic and Mean Equinox of Reference Epoch

Reference epoch: J2000.0
xy-plane: plane of the Earth's orbit at the reference epoch
x-axis  : out along ascending node of instantaneous plane of the Earth's
orbit and the Earth's mean equator at the reference epoch
z-axis  : perpendicular to the xy-plane in the directional (+ or -) sense
of Earth's north pole at the reference epoch.

Symbol meaning [1 au=149597870.700 km, 1 day=86400.0 s]:

JDCT     Epoch Julian Date, Coordinate Time
X      x-component of position vector (AU)
Y      y-component of position vector (AU)
Z      z-component of position vector (AU)
VX     x-component of velocity vector (AU/day)
VY     y-component of velocity vector (AU/day)
VZ     z-component of velocity vector (AU/day)
LT     One-way down-leg Newtonian light-time (day)
RG     Range; distance from coordinate center (AU)
RR     Range-rate; radial velocity wrt coord. center (AU/day)

this doesn't seem to match what we get however...

*/
