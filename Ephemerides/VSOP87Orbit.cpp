#include "VSOP87Orbit.h"

#include "Sun/SunVSOP87Model.h"

static SunVSOP87EOrbitalEphemeris xSolarEphemeris;

EphemerisVector4 VSOP87Model::HeliocentricToBarycentricVSOP87E( const EphemerisVector4& xCoordinate )
{
    return EphemerisVector4( xCoordinate.xyz() - xSolarEphemeris.EvaluateEphemeris( xCoordinate.w() ).xyz(), xCoordinate.w() );
}
