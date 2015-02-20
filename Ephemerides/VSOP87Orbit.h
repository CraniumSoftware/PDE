#ifndef VSOP87_ORBIT_H
#define VSOP87_ORBIT_H

#include "KeplerOrbit.h"

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

#define INITIALISE_TERMS_LBR5() \
	VSOP87OrbitalEphemeris(								\
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

struct VSOP87Term
{
	double mdA;
	double mdB;
	double mdC;
};

class VSOP87OrbitalEphemeris
: public OrbitalEphemeris< VSOP87OrbitalEphemeris >
{

public:

	VSOP87OrbitalEphemeris(
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

	EphemerisVector4 Evaluate( const double dTCenturies ) const
	{
		const double dLatitude = EvaluateLatitude( dTCenturies );
		const double dLongitude = EvaluateLongitude( dTCenturies );
		const double dRadius = EvaluateRadius( dTCenturies );

		return PositionFromLatLonRad( dLatitude, dLongitude, dRadius );
	}

private:

	double EvaluateLongitude( const double dTCenturies ) const
	{
		return EvaluateSeries(
			mpxL0, miL0Count,
			mpxL1, miL1Count,
			mpxL2, miL2Count,
			mpxL3, miL3Count,
			mpxL4, miL4Count,
			mpxL5, miL5Count,
			dTCenturies );
	}

	double EvaluateLatitude( const double dTCenturies ) const
	{
		return EvaluateSeries(
			mpxB0, miB0Count,
			mpxB1, miB1Count,
			mpxB2, miB2Count,
			mpxB3, miB3Count,
			mpxB4, miB4Count,
			mpxB5, miB5Count,
			dTCenturies );
	}

	double EvaluateRadius( const double dTCenturies ) const
	{
		return EvaluateSeries(
			mpxR0, miR0Count,
			mpxR1, miR1Count,
			mpxR2, miR2Count,
			mpxR3, miR3Count,
			mpxR4, miR4Count,
			mpxR5, miR5Count,
			dTCenturies );
	}

	static double EvaluateSeries(
		const VSOP87Term* const pxX0, const int iX0Count,
		const VSOP87Term* const pxX1, const int iX1Count,
		const VSOP87Term* const pxX2, const int iX2Count,
		const VSOP87Term* const pxX3, const int iX3Count,
		const VSOP87Term* const pxX4, const int iX4Count,
		const VSOP87Term* const pxX5, const int iX5Count,
		const double dTCenturies )
	{
		const VSOP87Term* const apxX[] = { pxX0, pxX1, pxX2, pxX3, pxX4, pxX5 };
		const int aiTermCounts[] = { iX0Count, iX1Count, iX2Count, iX3Count, iX4Count, iX5Count };
		double dResults[ 6 ] = { 0.0 };
		for( int i = 0; i < 5; ++i )
		{
			if( apxX[ i ] )
			{
				for( int j = 0; j < aiTermCounts[ i ]; ++j )
				{
					const VSOP87Term& xTerm = apxX[ i ][ j ];
					dResults[ i ] += xTerm.mdA * cos( xTerm.mdB + xTerm.mdC * dTCenturies );
				}
			}
		}

		return ( ( ( ( ( dResults[ 5 ] * dTCenturies
			+ dResults[ 4 ] ) * dTCenturies
			+ dResults[ 3 ] ) * dTCenturies
			+ dResults[ 2 ] ) * dTCenturies
			+ dResults[ 1 ] ) * dTCenturies + dResults[ 0 ] )
				/ 100000000.0;
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
