#ifndef KEPLER_ORBIT_H
#define KEPLER_ORBIT_H

#include "OrbitalEphemeris.h"

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

// use some expanded matrix rotations from the Paul Schlyter excellent guide
// to calculating rough planetary positions...

#define USE_SCHLYTER_MATHS ( 1 )

class KeplerOrbitalEphemeris
: public OrbitalEphemeris< KeplerOrbitalEphemeris >
{

public:

    KeplerOrbitalEphemeris( const KeplerElements& xElements )
    : mkxElements( xElements )
    {
    }

    DPVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        return Evaluate(
            mkxElements.LongitudeOfAscendingNode,
            mkxElements.Inclination,
            mkxElements.ArgumentOfPerifocus,
            mkxElements.SemiMajorAxis,
            mkxElements.Eccentricity,
            mkxElements.MeanAnomaly,
            mkxElements.LongitudeRate,
            static_cast< double >( xJDT - mkxElements.JDTZero ) );
    }

    double EvaluateSemiMajorAxis( const EphemerisFloat& ) const
    {
        return mkxElements.SemiMajorAxis;
    }

    double EvaluateEccentricity( const EphemerisFloat& ) const
    {
        return mkxElements.Eccentricity;
    }

	double EvaluateArgumentOfPerifocus( const EphemerisFloat& ) const
	{
		return mkxElements.ArgumentOfPerifocus;
	}

    double EvaluatePeriod( const EphemerisFloat& ) const
    {
        return 2.0 * PDE::PiDouble / mkxElements.LongitudeRate;
    }

	static double EvaluateTrueAnomaly(
		const double dMeanAnomaly, const double dLongitudeRate,
		const double dSemiMajorAxis, const double dEccentricity, const EphemerisFloat& dT )
	{
		const double dMeanAnomalyAtT = dMeanAnomaly + dLongitudeRate * dT;
		const EphemerisVector4 xPositionInPlane = EvaluatePositionInPlane( dEccentricity, dSemiMajorAxis,
			KeplerOrbitalEphemeris::EccentricAnomaly< 5 >( dMeanAnomalyAtT, dEccentricity ) );

		return PDE::Atan2( xPositionInPlane.y(), xPositionInPlane.x() );
	}

	double EvaluateTrueAnomaly( const EphemerisFloat& dT ) const
	{
		return EvaluateTrueAnomaly(
			mkxElements.MeanAnomaly, mkxElements.LongitudeRate,
			mkxElements.SemiMajorAxis, mkxElements.Eccentricity, dT );
	}

    static EphemerisVector4 Evaluate(
        const double dLongitudeOfAscendingNode,
        const double dInclination,
        const double dArgumentOfPerifocus,
        const double dSemiMajorAxis,
        const double dEccentricity,
        const double dMeanAnomaly,
        const double dLongitudeRate,
        const double dT )
    {
        // work out the position relative to the orbit
        const double dMeanAnomalyAtT = dMeanAnomaly + dLongitudeRate * dT;
        const EphemerisVector4 xPositionInPlane = EvaluatePositionInPlane( dEccentricity, dSemiMajorAxis,
            KeplerOrbitalEphemeris::EccentricAnomaly< 5 >( dMeanAnomalyAtT, dEccentricity ) );

        // SE - TODO: debug this, the step-by-step version made sense in my head at least...
#if USE_SCHLYTER_MATHS
        // SE - NOTE: for clarity map everything to the variables used by Paul Schlyter
        const EphemerisFloat r = xPositionInPlane.xy().Magnitude();
        const EphemerisFloat v = PDE::Atan2( xPositionInPlane.y(), xPositionInPlane.x() );
        const EphemerisFloat N = dLongitudeOfAscendingNode;
        const EphemerisFloat i = dInclination;
        const EphemerisFloat w = dArgumentOfPerifocus;
        return EphemerisVector4(
            r * ( cos( N ) * cos( v + w ) - sin( N ) * sin( v + w ) * cos( i ) ),
            r * ( sin( N ) * cos( v + w ) + cos( N ) * sin( v + w ) * cos( i ) ),
            r * sin( v + w ) * sin( i ),
            xPositionInPlane.w() );
#else
        // rotate into the space described by the remaining orbital elements
        const double dCosW = PDE::Cos( dArgumentOfPerifocus );
        const double dSinW = PDE::Sin( dArgumentOfPerifocus );
        const double dCosI = PDE::Cos( dInclination );
        const double dSinI = PDE::Sin( dInclination );
        const double dCosN = PDE::Cos( dLongitudeOfAscendingNode );
        const double dSinN = PDE::Sin( dLongitudeOfAscendingNode );

        // rotate the periapse to the right place relative to the nodes
        const EphemerisVector4 xRotatedToPeriapse(
            xPositionInPlane.x() * dCosW + xPositionInPlane.y() * dSinW,
            xPositionInPlane.y() * dCosW - xPositionInPlane.x() * dSinW,
            xPositionInPlane.z(), xPositionInPlane.w() );

        // rotate about the nodes
        const EphemerisVector4 xInclined(
            xRotatedToPeriapse.x(),
            xRotatedToPeriapse.y() * dCosI + xRotatedToPeriapse.z() * dSinI,
            xRotatedToPeriapse.z() * dCosI - xRotatedToPeriapse.y() * dSinI,
            xRotatedToPeriapse.w() );

        // finally, rotate so that the nodes point the right way in our reference frame
        return EphemerisVector4(
            xInclined.x() * dCosN + xInclined.y() * dSinN,
            xInclined.y() * dCosN - xInclined.x() * dSinN,
            xInclined.z(), xInclined.w() );
#endif
    }

protected:

    template< int Iterations >
    static inline double EccentricAnomaly( const double dMeanAnomaly, const double dEccentricity )
    {
        // solve Kepler's equation: M = E - e sin E
        //
        // this simple numerical approach is very stable, if a little expensive
        //
        double dEccentricAnomaly = dMeanAnomaly + 0.85 * dEccentricity * PDE::Sign( PDE::Sin( dMeanAnomaly ) );
        for( int i = 0; i < Iterations; ++i )
        {
            dEccentricAnomaly += ( dEccentricity * PDE::Sin( dEccentricAnomaly ) + dMeanAnomaly - dEccentricAnomaly ) / ( 1.0 - dEccentricity * PDE::Cos( dEccentricAnomaly ) );
        }

        return dEccentricAnomaly;
    }

    static EphemerisVector4 EvaluatePositionInPlane( const double dEccentricity, const double dSemiMajorAxis, const double dParameter )
    {
        return EphemerisVector4(
            ( dEccentricity <= 1.0 )
            ? ( dSemiMajorAxis * ( PDE::Cos( dParameter ) - dEccentricity ) )
            : ( -dSemiMajorAxis * ( dEccentricity - PDE::Cosh( dParameter ) ) ),
            ( dEccentricity <= 1.0 )
            ? ( dSemiMajorAxis * PDE::SquareRoot( 1.0 - dEccentricity * dEccentricity ) * PDE::Sin( dParameter ) )
            : ( -dSemiMajorAxis * PDE::SquareRoot( dEccentricity * dEccentricity - 1.0 ) * PDE::Sinh( dParameter ) )
            , 0.0, 0.0 );
    }

    const KeplerElements mkxElements;

};

#endif
