#ifndef VSOP87_ORBIT_H
#define VSOP87_ORBIT_H

#include "KeplerOrbit.h"

#define DECLARE_TERMS_LBR4 \
	static const VSOP87Term kaxL0[];  \
	static const VSOP87Term kaxL1[];  \
	static const VSOP87Term kaxL2[];  \
	static const VSOP87Term kaxL3[];  \
	static const VSOP87Term kaxL4[];  \
	\
	static const VSOP87Term kaxB0[];  \
	static const VSOP87Term kaxB1[];  \
	static const VSOP87Term kaxB2[];  \
	static const VSOP87Term kaxB3[];  \
	static const VSOP87Term kaxB4[];  \
	\
	static const VSOP87Term kaxR0[];  \
	static const VSOP87Term kaxR1[];  \
	static const VSOP87Term kaxR2[];  \
	static const VSOP87Term kaxR3[];  \
	static const VSOP87Term kaxR4[]

#define DECLARE_TERMS_LBR5 \
	static const VSOP87Term kaxL0[];  \
	static const VSOP87Term kaxL1[];  \
	static const VSOP87Term kaxL2[];  \
	static const VSOP87Term kaxL3[];  \
	static const VSOP87Term kaxL4[];  \
	static const VSOP87Term kaxL5[];  \
	\
	static const VSOP87Term kaxB0[];  \
	static const VSOP87Term kaxB1[];  \
	static const VSOP87Term kaxB2[];  \
	static const VSOP87Term kaxB3[];  \
	static const VSOP87Term kaxB4[];  \
	static const VSOP87Term kaxB5[];  \
	\
	static const VSOP87Term kaxR0[];  \
	static const VSOP87Term kaxR1[];  \
	static const VSOP87Term kaxR2[];  \
	static const VSOP87Term kaxR3[];  \
	static const VSOP87Term kaxR4[];  \
	static const VSOP87Term kaxR5[]

#define DECLARE_TERMS_XYZ4 \
    static const VSOP87Term kaxX0[];  \
    static const VSOP87Term kaxX1[];  \
    static const VSOP87Term kaxX2[];  \
    static const VSOP87Term kaxX3[];  \
    static const VSOP87Term kaxX4[];  \
    \
    static const VSOP87Term kaxY0[];  \
    static const VSOP87Term kaxY1[];  \
    static const VSOP87Term kaxY2[];  \
    static const VSOP87Term kaxY3[];  \
    static const VSOP87Term kaxY4[];  \
    \
    static const VSOP87Term kaxZ0[];  \
    static const VSOP87Term kaxZ1[];  \
    static const VSOP87Term kaxZ2[];  \
    static const VSOP87Term kaxZ3[];  \
    static const VSOP87Term kaxZ4[]

#define DECLARE_TERMS_XYZ5 \
    static const VSOP87Term kaxX0[];  \
    static const VSOP87Term kaxX1[];  \
    static const VSOP87Term kaxX2[];  \
    static const VSOP87Term kaxX3[];  \
    static const VSOP87Term kaxX4[];  \
    static const VSOP87Term kaxX5[];  \
    \
    static const VSOP87Term kaxY0[];  \
    static const VSOP87Term kaxY1[];  \
    static const VSOP87Term kaxY2[];  \
    static const VSOP87Term kaxY3[];  \
    static const VSOP87Term kaxY4[];  \
    static const VSOP87Term kaxY5[];  \
    \
    static const VSOP87Term kaxZ0[];  \
    static const VSOP87Term kaxZ1[];  \
    static const VSOP87Term kaxZ2[];  \
    static const VSOP87Term kaxZ3[];  \
    static const VSOP87Term kaxZ4[];  \
    static const VSOP87Term kaxZ5[]


#define INITIALISE_TERMS_LBR4() \
	VSOP87DOrbitalEphemeris( \
		kaxL0, sizeof( kaxL0 ) / sizeof( kaxL0[ 0 ] ), \
		kaxL1, sizeof( kaxL1 ) / sizeof( kaxL1[ 0 ] ), \
		kaxL2, sizeof( kaxL2 ) / sizeof( kaxL2[ 0 ] ), \
		kaxL3, sizeof( kaxL3 ) / sizeof( kaxL3[ 0 ] ), \
		kaxL4, sizeof( kaxL4 ) / sizeof( kaxL4[ 0 ] ), \
		0, 0, \
		kaxB0, sizeof( kaxB0 ) / sizeof( kaxB0[ 0 ] ), \
		kaxB1, sizeof( kaxB1 ) / sizeof( kaxB1[ 0 ] ), \
		kaxB2, sizeof( kaxB2 ) / sizeof( kaxB2[ 0 ] ), \
		kaxB3, sizeof( kaxB3 ) / sizeof( kaxB3[ 0 ] ), \
		kaxB4, sizeof( kaxB4 ) / sizeof( kaxB4[ 0 ] ), \
		0, 0, \
		kaxR0, sizeof( kaxR0 ) / sizeof( kaxR0[ 0 ] ), \
		kaxR1, sizeof( kaxR1 ) / sizeof( kaxR1[ 0 ] ), \
		kaxR2, sizeof( kaxR2 ) / sizeof( kaxR2[ 0 ] ), \
		kaxR3, sizeof( kaxR3 ) / sizeof( kaxR3[ 0 ] ), \
		kaxR4, sizeof( kaxR4 ) / sizeof( kaxR4[ 0 ] ), \
		0, 0 )

#define INITIALISE_TERMS_LBR5() \
	VSOP87DOrbitalEphemeris( \
		kaxL0, sizeof( kaxL0 ) / sizeof( kaxL0[ 0 ] ),	\
		kaxL1, sizeof( kaxL1 ) / sizeof( kaxL1[ 0 ] ),	\
		kaxL2, sizeof( kaxL2 ) / sizeof( kaxL2[ 0 ] ),	\
		kaxL3, sizeof( kaxL3 ) / sizeof( kaxL3[ 0 ] ),	\
		kaxL4, sizeof( kaxL4 ) / sizeof( kaxL4[ 0 ] ),	\
		kaxL5, sizeof( kaxL5 ) / sizeof( kaxL5[ 0 ] ),	\
		kaxB0, sizeof( kaxB0 ) / sizeof( kaxB0[ 0 ] ),	\
		kaxB1, sizeof( kaxB1 ) / sizeof( kaxB1[ 0 ] ),	\
		kaxB2, sizeof( kaxB2 ) / sizeof( kaxB2[ 0 ] ),	\
		kaxB3, sizeof( kaxB3 ) / sizeof( kaxB3[ 0 ] ),	\
		kaxB4, sizeof( kaxB4 ) / sizeof( kaxB4[ 0 ] ),	\
		kaxB5, sizeof( kaxB5 ) / sizeof( kaxB5[ 0 ] ),	\
		kaxR0, sizeof( kaxR0 ) / sizeof( kaxR0[ 0 ] ),	\
		kaxR1, sizeof( kaxR1 ) / sizeof( kaxR1[ 0 ] ),	\
		kaxR2, sizeof( kaxR2 ) / sizeof( kaxR2[ 0 ] ),	\
		kaxR3, sizeof( kaxR3 ) / sizeof( kaxR3[ 0 ] ),	\
		kaxR4, sizeof( kaxR4 ) / sizeof( kaxR4[ 0 ] ),	\
		kaxR5, sizeof( kaxR5 ) / sizeof( kaxR5[ 0 ] ) )

#define INITIALISE_TERMS_XYZ4() \
    VSOP87EOrbitalEphemeris( \
        kaxX0, sizeof( kaxX0 ) / sizeof( kaxX0[ 0 ] ), \
        kaxX1, sizeof( kaxX1 ) / sizeof( kaxX1[ 0 ] ), \
        kaxX2, sizeof( kaxX2 ) / sizeof( kaxX2[ 0 ] ), \
        kaxX3, sizeof( kaxX3 ) / sizeof( kaxX3[ 0 ] ), \
        kaxX4, sizeof( kaxX4 ) / sizeof( kaxX4[ 0 ] ), \
        0, 0, \
        kaxY0, sizeof( kaxY0 ) / sizeof( kaxY0[ 0 ] ), \
        kaxY1, sizeof( kaxY1 ) / sizeof( kaxY1[ 0 ] ), \
        kaxY2, sizeof( kaxY2 ) / sizeof( kaxY2[ 0 ] ), \
        kaxY3, sizeof( kaxY3 ) / sizeof( kaxY3[ 0 ] ), \
        kaxY4, sizeof( kaxY4 ) / sizeof( kaxY4[ 0 ] ), \
        0, 0, \
        kaxZ0, sizeof( kaxZ0 ) / sizeof( kaxZ0[ 0 ] ), \
        kaxZ1, sizeof( kaxZ1 ) / sizeof( kaxZ1[ 0 ] ), \
        kaxZ2, sizeof( kaxZ2 ) / sizeof( kaxZ2[ 0 ] ), \
        kaxZ3, sizeof( kaxZ3 ) / sizeof( kaxZ3[ 0 ] ), \
        kaxZ4, sizeof( kaxZ4 ) / sizeof( kaxZ4[ 0 ] ), \
        0, 0 )

#define INITIALISE_TERMS_XYZ5() \
    VSOP87EOrbitalEphemeris( \
        kaxX0, sizeof( kaxX0 ) / sizeof( kaxX0[ 0 ] ), \
        kaxX1, sizeof( kaxX1 ) / sizeof( kaxX1[ 0 ] ), \
        kaxX2, sizeof( kaxX2 ) / sizeof( kaxX2[ 0 ] ), \
        kaxX3, sizeof( kaxX3 ) / sizeof( kaxX3[ 0 ] ), \
        kaxX4, sizeof( kaxX4 ) / sizeof( kaxX4[ 0 ] ), \
        kaxX5, sizeof( kaxX5 ) / sizeof( kaxX5[ 0 ] ), \
        kaxY0, sizeof( kaxY0 ) / sizeof( kaxY0[ 0 ] ), \
        kaxY1, sizeof( kaxY1 ) / sizeof( kaxY1[ 0 ] ), \
        kaxY2, sizeof( kaxY2 ) / sizeof( kaxY2[ 0 ] ), \
        kaxY3, sizeof( kaxY3 ) / sizeof( kaxY3[ 0 ] ), \
        kaxY4, sizeof( kaxY4 ) / sizeof( kaxY4[ 0 ] ), \
        kaxY5, sizeof( kaxY5 ) / sizeof( kaxY5[ 0 ] ), \
        kaxZ0, sizeof( kaxZ0 ) / sizeof( kaxZ0[ 0 ] ), \
        kaxZ1, sizeof( kaxZ1 ) / sizeof( kaxZ1[ 0 ] ), \
        kaxZ2, sizeof( kaxZ2 ) / sizeof( kaxZ2[ 0 ] ), \
        kaxZ3, sizeof( kaxZ3 ) / sizeof( kaxZ3[ 0 ] ), \
        kaxZ4, sizeof( kaxZ4 ) / sizeof( kaxZ4[ 0 ] ), \
        kaxZ5, sizeof( kaxZ5 ) / sizeof( kaxZ5[ 0 ] ) )

struct VSOP87Term
{
	double mdA;
	double mdB;
	double mdC;
};

class VSOP87Model
{

public:

    static double EvaluateSeriesAA(
        const VSOP87Term* const pxX0, const int iX0Count,
        const VSOP87Term* const pxX1, const int iX1Count,
        const VSOP87Term* const pxX2, const int iX2Count,
        const VSOP87Term* const pxX3, const int iX3Count,
        const VSOP87Term* const pxX4, const int iX4Count,
        const VSOP87Term* const pxX5, const int iX5Count,
        const double dTM )
    {
        const VSOP87Term* const apxX[ ] = { pxX0, pxX1, pxX2, pxX3, pxX4, pxX5 };
        const int aiTermCounts[ ] = { iX0Count, iX1Count, iX2Count, iX3Count, iX4Count, iX5Count };
        double dResults[ 6 ] = { 0.0 };
        for( int i = 0; i < 5; ++i )
        {
            if( apxX[ i ] )
            {
                for( int j = 0; j < aiTermCounts[ i ]; ++j )
                {
                    const VSOP87Term& xTerm = apxX[ i ][ j ];
                    dResults[ i ] += xTerm.mdA * cos( xTerm.mdB + xTerm.mdC * dTM );
                }
            }
        }

        return ( ( ( ( ( dResults[ 5 ] * dTM
            + dResults[ 4 ] ) * dTM
            + dResults[ 3 ] ) * dTM
            + dResults[ 2 ] ) * dTM
            + dResults[ 1 ] ) * dTM + dResults[ 0 ] )
            / 100000000.0;
    }

    static double EvaluateSeries(
        const VSOP87Term* const pxX0, const int iX0Count,
        const VSOP87Term* const pxX1, const int iX1Count,
        const VSOP87Term* const pxX2, const int iX2Count,
        const VSOP87Term* const pxX3, const int iX3Count,
        const VSOP87Term* const pxX4, const int iX4Count,
        const VSOP87Term* const pxX5, const int iX5Count,
        const double dTM )
    {
        const VSOP87Term* const apxX[ ] = { pxX0, pxX1, pxX2, pxX3, pxX4, pxX5 };
        const int aiTermCounts[ ] = { iX0Count, iX1Count, iX2Count, iX3Count, iX4Count, iX5Count };
        double dResults[ 6 ] = { 0.0 };
        for( int i = 0; i < 5; ++i )
        {
            if( apxX[ i ] )
            {
                for( int j = 0; j < aiTermCounts[ i ]; ++j )
                {
                    const VSOP87Term& xTerm = apxX[ i ][ j ];
                    dResults[ i ] += xTerm.mdA * cos( xTerm.mdB + xTerm.mdC * dTM );
                }
            }
        }

        return ( ( ( ( ( dResults[ 5 ] * dTM
            + dResults[ 4 ] ) * dTM
            + dResults[ 3 ] ) * dTM
            + dResults[ 2 ] ) * dTM
            + dResults[ 1 ] ) * dTM + dResults[ 0 ] );
    }

    static EphemerisVector4 HeliocentricToBarycentricVSOP87E( const EphemerisVector4& xCoordinate );

};
class VSOP87DOrbitalEphemeris
: public OrbitalEphemeris< VSOP87DOrbitalEphemeris >
, public VSOP87Model
{

public:

	VSOP87DOrbitalEphemeris(
		const VSOP87Term* const pxL0, const int iL0Count,
		const VSOP87Term* const pxL1, const int iL1Count, 
		const VSOP87Term* const pxL2, const int iL2Count, 
		const VSOP87Term* const pxL3, const int iL3Count, 
		const VSOP87Term* const pxL4, const int iL4Count,
		const VSOP87Term* const pxL5, const int iL5Count,
		const VSOP87Term* const pxB0, const int iB0Count,
		const VSOP87Term* const pxB1, const int iB1Count,
		const VSOP87Term* const pxB2, const int iB2Count,
		const VSOP87Term* const pxB3, const int iB3Count,
		const VSOP87Term* const pxB4, const int iB4Count,
		const VSOP87Term* const pxB5, const int iB5Count, 
		const VSOP87Term* const pxR0, const int iR0Count,
		const VSOP87Term* const pxR1, const int iR1Count,
		const VSOP87Term* const pxR2, const int iR2Count,
		const VSOP87Term* const pxR3, const int iR3Count,
		const VSOP87Term* const pxR4, const int iR4Count,
		const VSOP87Term* const pxR5, const int iR5Count )
	: mpxL0( pxL0 ), mpxL1( pxL1 ), mpxL2( pxL2 ), mpxL3( pxL3 ), mpxL4( pxL4 ), mpxL5( pxL5 )
	, mpxB0( pxB0 ), mpxB1( pxB1 ), mpxB2( pxB2 ), mpxB3( pxB3 ), mpxB4( pxB4 ), mpxB5( pxB5 )
	, mpxR0( pxR0 ), mpxR1( pxR1 ), mpxR2( pxR2 ), mpxR3( pxR3 ), mpxR4( pxR4 ), mpxR5( pxR5 )
	, miL0Count( iL0Count ), miL1Count( iL1Count ), miL2Count( iL2Count ), miL3Count( iL3Count ), miL4Count( iL4Count ), miL5Count( iL5Count )
	, miB0Count( iB0Count ), miB1Count( iB1Count ), miB2Count( iB2Count ), miB3Count( iB3Count ), miB4Count( iB4Count ), miB5Count( iB5Count )
	, miR0Count( iR0Count ), miR1Count( iR1Count ), miR2Count( iR2Count ), miR3Count( iR3Count ), miR4Count( iR4Count ), miR5Count( iR5Count ) 
	{
	}

	DPVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
	{
		return Evaluate(
			static_cast< double >( xJDT - 2451545.0 ) / 365250.0 );
	}

	EphemerisVector4 Evaluate( const double dTM ) const
	{
		const double dLatitude = EvaluateLatitude( dTM );
		const double dLongitude = EvaluateLongitude( dTM );
		const double dRadius = EvaluateRadius( dTM );

        // SE - TODO: correct for not being barycentric
        return HeliocentricToBarycentricVSOP87E(
            EphemerisVector4(
                PositionFromLatLonRad( dLatitude, dLongitude, dRadius ).xyz(),
                dTM * 365250.0 + 2451545.0 ) );
	}

private:

	double EvaluateLongitude( const double dTM ) const
	{
		return EvaluateSeriesAA(
			mpxL0, miL0Count,
			mpxL1, miL1Count,
			mpxL2, miL2Count,
			mpxL3, miL3Count,
			mpxL4, miL4Count,
			mpxL5, miL5Count,
			dTM );
	}

	double EvaluateLatitude( const double dTM ) const
	{
		return EvaluateSeriesAA(
			mpxB0, miB0Count,
			mpxB1, miB1Count,
			mpxB2, miB2Count,
			mpxB3, miB3Count,
			mpxB4, miB4Count,
			mpxB5, miB5Count,
			dTM );
	}

	double EvaluateRadius( const double dTM ) const
	{
		return EvaluateSeriesAA(
			mpxR0, miR0Count,
			mpxR1, miR1Count,
			mpxR2, miR2Count,
			mpxR3, miR3Count,
			mpxR4, miR4Count,
			mpxR5, miR5Count,
			dTM );
	}

	const VSOP87Term* mpxL0;
	const VSOP87Term* mpxL1;
	const VSOP87Term* mpxL2;
	const VSOP87Term* mpxL3;
	const VSOP87Term* mpxL4;
	const VSOP87Term* mpxL5;
	const VSOP87Term* mpxB0;
	const VSOP87Term* mpxB1;
	const VSOP87Term* mpxB2;
	const VSOP87Term* mpxB3;
	const VSOP87Term* mpxB4;
	const VSOP87Term* mpxB5;
	const VSOP87Term* mpxR0;
	const VSOP87Term* mpxR1;
	const VSOP87Term* mpxR2;
	const VSOP87Term* mpxR3;
	const VSOP87Term* mpxR4;
	const VSOP87Term* mpxR5;
	int miL0Count;
	int miL1Count;
	int miL2Count;
	int miL3Count;
	int miL4Count;
	int miL5Count;
	int miB0Count;
	int miB1Count;
	int miB2Count;
	int miB3Count;
	int miB4Count;
	int miB5Count;
	int miR0Count;
	int miR1Count;
	int miR2Count;
	int miR3Count;
	int miR4Count;
	int miR5Count;

};

// SE - NOTE: sorry i am lazy, L = X, B = Y, R = z
class VSOP87EOrbitalEphemeris
: public OrbitalEphemeris< VSOP87EOrbitalEphemeris >
, public VSOP87Model
{

public:

    VSOP87EOrbitalEphemeris(
        const VSOP87Term* const pxL0, const int iL0Count,
        const VSOP87Term* const pxL1, const int iL1Count,
        const VSOP87Term* const pxL2, const int iL2Count,
        const VSOP87Term* const pxL3, const int iL3Count,
        const VSOP87Term* const pxL4, const int iL4Count,
        const VSOP87Term* const pxL5, const int iL5Count,
        const VSOP87Term* const pxB0, const int iB0Count,
        const VSOP87Term* const pxB1, const int iB1Count,
        const VSOP87Term* const pxB2, const int iB2Count,
        const VSOP87Term* const pxB3, const int iB3Count,
        const VSOP87Term* const pxB4, const int iB4Count,
        const VSOP87Term* const pxB5, const int iB5Count,
        const VSOP87Term* const pxR0, const int iR0Count,
        const VSOP87Term* const pxR1, const int iR1Count,
        const VSOP87Term* const pxR2, const int iR2Count,
        const VSOP87Term* const pxR3, const int iR3Count,
        const VSOP87Term* const pxR4, const int iR4Count,
        const VSOP87Term* const pxR5, const int iR5Count )
    : mpxL0( pxL0 ), mpxL1( pxL1 ), mpxL2( pxL2 ), mpxL3( pxL3 ), mpxL4( pxL4 ), mpxL5( pxL5 )
    , mpxB0( pxB0 ), mpxB1( pxB1 ), mpxB2( pxB2 ), mpxB3( pxB3 ), mpxB4( pxB4 ), mpxB5( pxB5 )
    , mpxR0( pxR0 ), mpxR1( pxR1 ), mpxR2( pxR2 ), mpxR3( pxR3 ), mpxR4( pxR4 ), mpxR5( pxR5 )
    , miL0Count( iL0Count ), miL1Count( iL1Count ), miL2Count( iL2Count ), miL3Count( iL3Count ), miL4Count( iL4Count ), miL5Count( iL5Count )
    , miB0Count( iB0Count ), miB1Count( iB1Count ), miB2Count( iB2Count ), miB3Count( iB3Count ), miB4Count( iB4Count ), miB5Count( iB5Count )
    , miR0Count( iR0Count ), miR1Count( iR1Count ), miR2Count( iR2Count ), miR3Count( iR3Count ), miR4Count( iR4Count ), miR5Count( iR5Count )
    {
    }

    DPVector4 EvaluateEphemeris( const EphemerisFloat& xJDT ) const
    {
        return Evaluate(
            static_cast< double >( xJDT - 2451545.0 ) / 365250.0 );
    }

    EphemerisVector4 Evaluate( const double dTM ) const
    {
        return EphemerisVector4( 
            EvaluateX( dTM ),
            EvaluateY( dTM ),
            EvaluateZ( dTM ),
            dTM * 365250.0 + 2451545.0 );
    }

private:

    double EvaluateX( const double dTM ) const
	{
		return EvaluateSeries(
			mpxL0, miL0Count,
			mpxL1, miL1Count,
			mpxL2, miL2Count,
			mpxL3, miL3Count,
			mpxL4, miL4Count,
			mpxL5, miL5Count,
			dTM );
	}

	double EvaluateY( const double dTM ) const
	{
		return EvaluateSeries(
			mpxB0, miB0Count,
			mpxB1, miB1Count,
			mpxB2, miB2Count,
			mpxB3, miB3Count,
			mpxB4, miB4Count,
			mpxB5, miB5Count,
			dTM );
	}

	double EvaluateZ( const double dTM ) const
	{
		return EvaluateSeries(
			mpxR0, miR0Count,
			mpxR1, miR1Count,
			mpxR2, miR2Count,
			mpxR3, miR3Count,
			mpxR4, miR4Count,
			mpxR5, miR5Count,
			dTM );
	}

    const VSOP87Term* mpxL0;
    const VSOP87Term* mpxL1;
    const VSOP87Term* mpxL2;
    const VSOP87Term* mpxL3;
    const VSOP87Term* mpxL4;
    const VSOP87Term* mpxL5;
    const VSOP87Term* mpxB0;
    const VSOP87Term* mpxB1;
    const VSOP87Term* mpxB2;
    const VSOP87Term* mpxB3;
    const VSOP87Term* mpxB4;
    const VSOP87Term* mpxB5;
    const VSOP87Term* mpxR0;
    const VSOP87Term* mpxR1;
    const VSOP87Term* mpxR2;
    const VSOP87Term* mpxR3;
    const VSOP87Term* mpxR4;
    const VSOP87Term* mpxR5;
    int miL0Count;
    int miL1Count;
    int miL2Count;
    int miL3Count;
    int miL4Count;
    int miL5Count;
    int miB0Count;
    int miB1Count;
    int miB2Count;
    int miB3Count;
    int miB4Count;
    int miB5Count;
    int miR0Count;
    int miR1Count;
    int miR2Count;
    int miR3Count;
    int miR4Count;
    int miR5Count;

};

#endif
