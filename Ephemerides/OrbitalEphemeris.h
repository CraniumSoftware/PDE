#ifndef PLANETARY_EPHEMERIS_H
#define PLANETARY_EPHEMERIS_H

// Planetary Ephemerides

// these models workout a position relative to some other body, or a barycentre
// they also allow providing information about the orbit

// we will eventually want something better than double precision for this...
// ... but for now live with that limitation, but use a macro (yuck!) so
// that its easy to change (typedef is a more restrictive hack than macros are)

#include "Maths/DPVector.h"

#ifndef EphemerisVector4

#define EphemerisVector4 DPVector4
#define EphemerisFloat double

#endif

template< class Implementation, const bool bCorrectForLightTime = true >
class OrbitalEphemeris
{

public:

    OrbitalEphemeris() {}

    // derived quantities from those exposed by Implementation
    EphemerisVector4 CalculatePosition( const EphemerisVector4& xObserver ) const
    {
        if( bCorrectForLightTime )
        {
            return CalculatePositionCorrectedForLightTime( xObserver );
        }
        else
        {
            return CalculateNoLightTimePosition( xObserver );
        }
    }

    EphemerisVector4 CalculateNoLightTimePosition( const EphemerisVector4& xObserver ) const
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
        return PDE::Atan2(
            static_cast< double >( xLocalCoordinates.y() ),
            static_cast< double >( xLocalCoordinates.x() ) );
    }

    static double CalculateLatitude( const EphemerisVector4& xLocalCoordinates )
    {
        return PDE::Atan2(
            static_cast< double >( xLocalCoordinates.z() ),
            PDE::SquareRoot(
                static_cast< double >( xLocalCoordinates.x() ) * static_cast< double >( xLocalCoordinates.x() )
                + static_cast< double >( xLocalCoordinates.y() ) * static_cast< double >( xLocalCoordinates.y() ) ) );
    }

    static double CalculateRadius( const EphemerisVector4& xLocalCoordinates )
    {
        return PDE::SquareRoot(
            static_cast< double >( xLocalCoordinates.x() ) * static_cast< double >( xLocalCoordinates.x() )
            + static_cast< double >( xLocalCoordinates.y() ) * static_cast< double >( xLocalCoordinates.y() )
            + static_cast< double >( xLocalCoordinates.z() ) * static_cast< double >( xLocalCoordinates.z() ) );
    }

    static EphemerisVector4 PositionFromLatLonRad( const double dLatitude, const double dLongitude, const double dRadius )
    {
        const double dCosLatitude = PDE::Cos( dLatitude );
        return dRadius * EphemerisVector4(
            dCosLatitude * PDE::Cos( dLongitude ),
            dCosLatitude * PDE::Sin( dLongitude ),
            PDE::Sin( dLatitude ),
            0.0 );
    }

private:

    static EphemerisFloat TimeFromDistance( const EphemerisFloat& xDistance )
    {
        static const double kdLightSpeedMS = 299792458.0;
        static const double kdAUM = 149597870700.0;
        static const double kdDayS = 86400.0;

        const double kdConversionFactor = kdAUM / ( 299792458.0 * kdDayS );

        return xDistance * static_cast< EphemerisFloat >( kdConversionFactor );
    }

    EphemerisVector4 CalculatePositionCorrectedForLightTime( const EphemerisVector4& xObserver ) const
    {
        EphemerisVector4 xGuess = static_cast< const Implementation* >( this )->EvaluateEphemeris( xObserver[ 3 ] );
        // take distance and convert to time...
        
        // SE - TODO: something to iterate until a desired precision is reached
        for( int i = 0; i < 2; ++i )
        {
            const EphemerisFloat xDistance = ( xObserver.xyz() - xGuess.xyz() ).Magnitude();
            const EphemerisFloat xTimeDifference = TimeFromDistance( xDistance );
            const EphemerisFloat xJDT = xObserver[ 3 ] - xTimeDifference;
            xGuess = static_cast< const Implementation* >( this )->EvaluateEphemeris( xJDT );
        }

        return xGuess;
    }

    HIDE_BUILT_IN_COPIES( OrbitalEphemeris );

};

#endif
