#ifndef PLANETARY_EPHEMERIS_H
#define PLANETARY_EPHEMERIS_H

// Planetary Ephemerides

// these models workout a position relative to some other body, or a barycentre
// they also allow providing information about the orbit

// we will eventually want something better than double precision for this...
// ... but for now live with that limitation, but use a macro (yuck!) so
// that its easy to change (typedef is a more restrictive hack than macros are)

#include "Maths/DPVector.h"

#define EphemerisVector4 DPVector4
#define EphemerisFloat double

template< class Implementation >
class OrbitalEphemeris
{

public:

    OrbitalEphemeris() {}

    // derived quantities from those exposed by Implementation
    EphemerisVector4 CalculatePosition( const EphemerisVector4& xObserver ) const
    {
        return static_cast< const Implementation* >( this )->EvaluateEphemeris( xObserver[ 3 ] );
    }
    
    double GetPeriapsis( const EphemerisVector4& xObserver ) const
    {
        const double dA = static_cast< const Implementation* >( this )->EvaluateSemiMajorAxis( xObserver[ 3 ] );
        const double dE = static_cast< const Implementation* >( this )->EvaluateEccentricity( xObserver[ 3 ] );
        return dA * ( 1.0 - dE );
    }

    double GetApoapsis( const EphemerisVector4& xObserver ) const
    {
        const double dA = static_cast< const Implementation* >( this )->EvaluateSemiMajorAxis( xObserver[ 3 ] );
        const double dE = static_cast< const Implementation* >( this )->EvaluateEccentricity( xObserver[ 3 ] );
        return dA * ( 1.0 + dE );
    }

    double GetEccentricity( const EphemerisVector4& xObserver ) const
    {
        return static_cast< const Implementation* >( this )->EvaluateEccentricity( xObserver[ 3 ] );
    }

protected:

    // helpers for spherical coordinate type stuff
    static double CalculateLongitude( const EphemerisVector4& xLocalCoordinates )
    {
        return Maths::Atan2(
            static_cast< double >( xLocalCoordinates.y() ),
            static_cast< double >( xLocalCoordinates.x() ) );
    }

    static double CalculateLatitude( const EphemerisVector4& xLocalCoordinates )
    {
        return Maths::Atan2(
            static_cast< double >( xLocalCoordinates.z() ),
            Maths::SquareRoot(
                static_cast< double >( xLocalCoordinates.x() ) * static_cast< double >( xLocalCoordinates.x() )
                + static_cast< double >( xLocalCoordinates.y() ) * static_cast< double >( xLocalCoordinates.y() ) ) );
    }

    static double CalculateRadius( const EphemerisVector4& xLocalCoordinates )
    {
        return Maths::SquareRoot(
            static_cast< double >( xLocalCoordinates.x() ) * static_cast< double >( xLocalCoordinates.x() )
            + static_cast< double >( xLocalCoordinates.y() ) * static_cast< double >( xLocalCoordinates.y() )
            + static_cast< double >( xLocalCoordinates.z() ) * static_cast< double >( xLocalCoordinates.z() ) );
    }

    static EphemerisVector4 PositionFromLatLonRad( const double dLatitude, const double dLongitude, const double dRadius )
    {
        const double dCosLatitude = Maths::Cos( dLatitude );
        return EphemerisVector4(
            dRadius * dCosLatitude * Maths::Cos( dLongitude ),
            dRadius * dCosLatitude * Maths::Sin( dLongitude ),
            dRadius * Maths::Sin( dLatitude ),
            0.0 );
    }

protected:

    HIDE_BUILT_IN_COPIES( OrbitalEphemeris );

};

#endif
