// Copyright (c) 2013-2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef MATHS_H
#define MATHS_H

#include "Compiler/Compiler.h"
#include "Hardware/CPU.h"
#include "Debug/Assert.h"

#include <ciso646>
#include <cmath>
#include <limits>

#if defined( _LIBCPP_VERSION ) || COMPILER_MS
#include <type_traits>
#else
#include <tr1/type_traits>
#endif

namespace PDE
{

static const float PiFloat = 3.1415926535897932384f;
static const double PiDouble = 3.1415926535897932384;

#define UNARY_MATHS_FUNCTION( ourName, theirNamef, theirName, theirNamel ) \
template< class RealType > \
static FORCE_INLINE RealType ourName( const RealType x ) \
{ \
    UNUSED( x ); \
	debugAssert( std::numeric_limits< RealType >::has_quiet_NaN, "Type used for " #ourName " doesn't support quiet NAN" ); \
    return std::numeric_limits< RealType >::has_quiet_NaN ? std::numeric_limits< RealType >::quiet_NaN() : 0; \
} \
\
template<> \
FORCE_INLINE float ourName< float >( const float x ) \
{ \
    return theirNamef( x ); \
} \
\
template<> \
FORCE_INLINE double ourName< double >( const double x ) \
{ \
    return theirName( x ); \
} \
\
template<> \
FORCE_INLINE long double ourName< long double >( const long double x ) \
{ \
	return theirNamel( x ); \
} \

#define BINARY_MATHS_FUNCTION( ourName, theirNamef, theirName, theirNamel ) \
template< class RealType > \
static FORCE_INLINE RealType ourName( const RealType x, const RealType y ) \
{ \
    UNUSED( x ); \
	UNUSED( y ); \
	debugAssert( std::numeric_limits< RealType >::has_quiet_NaN, "Type used for " #ourName " doesn't support quiet NAN" ); \
    return std::numeric_limits< RealType >::has_quiet_NaN ? std::numeric_limits< RealType >::quiet_NaN() : 0; \
} \
\
template<> \
FORCE_INLINE float ourName< float >( const float x, const float y ) \
{ \
    return theirNamef( x, y ); \
} \
\
template<> \
FORCE_INLINE double ourName< double >( const double x, const double y ) \
{ \
    return theirName( x, y ); \
} \
\
template<> \
FORCE_INLINE long double ourName< long double >( const long double x, const long double y ) \
{ \
	return theirNamel( x, y ); \
} \

#define UNARY_MATHS_FUNCTION_NODEFAULT( ourName, theirNamef, theirName, theirNamel ) \
\
template<> \
FORCE_INLINE float ourName< float >( const float x ) \
{ \
    return theirNamef( x ); \
} \
\
template<> \
FORCE_INLINE double ourName< double >( const double x ) \
{ \
    return theirName( x ); \
} \
\
template<> \
FORCE_INLINE long double ourName< long double >( const long double x ) \
{ \
	return theirNamel( x ); \
} \

#define BINARY_MATHS_FUNCTION_NODEFAULT( ourName, theirNamef, theirName, theirNamel ) \
\
template<> \
FORCE_INLINE float ourName< float >( const float x, const float y ) \
{ \
    return theirNamef( x, y ); \
} \
\
template<> \
FORCE_INLINE double ourName< double >( const double x, const double y ) \
{ \
    return theirName( x, y ); \
} \
\
template<> \
FORCE_INLINE long double ourName< long double >( const long double x, const long double y ) \
{ \
    return theirNamel( x, y ); \
} \

#if ANDROID
#define sqrtl sqrt
#define powl pow
#define sinl sin
#define cosl cos
#define floorl floor
#define ceill ceil
#define tanl tan
#define sinhl sinh
#define coshl cosh
#define tanhl tanh
#define fabsl fabs
#define asinl asin
#define acosl acos
#define atanl atan
#define atan2l atan2
#define asinhl asinh
#define acoshl acosh
#define atanhl atanh
#define expl exp
#define logl log
#define log10l log10
#define fmodl fmod
#endif

template < class T > static inline T SquareRoot( const T xValue ) { return static_cast< T >( Maths::SquareRoot( static_cast< double >( xValue ) ) ); }

UNARY_MATHS_FUNCTION( Abs, fabsf, fabs, fabsl )
UNARY_MATHS_FUNCTION( Floor, floorf, floor, floorl )
UNARY_MATHS_FUNCTION( Ceil, ceilf, ceil, ceill )
UNARY_MATHS_FUNCTION_NODEFAULT( SquareRoot, sqrtf, sqrt, sqrtl )
UNARY_MATHS_FUNCTION( Sin, sinf, sin, sinl )
UNARY_MATHS_FUNCTION( Cos, cosf, cos, cosl )
UNARY_MATHS_FUNCTION( Tan, tanf, tan, tanl )
UNARY_MATHS_FUNCTION( Sinh, sinhf, sinh, sinhl )
UNARY_MATHS_FUNCTION( Cosh, coshf, cosh, coshl )
UNARY_MATHS_FUNCTION( Tanh, tanhf, tanh, tanhl )
UNARY_MATHS_FUNCTION( Exp, expf, exp, expl )
UNARY_MATHS_FUNCTION( Log, logf, log, logl )
UNARY_MATHS_FUNCTION( Log10, log10f, log10, log10l )
UNARY_MATHS_FUNCTION( Asin, asinf, asin, asinl )
UNARY_MATHS_FUNCTION( Acos, acosf, acos, acosl )
UNARY_MATHS_FUNCTION( Atan, atanf, atan, atanl )
    
BINARY_MATHS_FUNCTION( Pow, powf, pow, powl )
BINARY_MATHS_FUNCTION( Mod, fmodf, fmod, fmodl )
BINARY_MATHS_FUNCTION( Atan2, atan2f, atan2, atan2l )

template < class T >
static FORCE_INLINE T Frac( const T& xParameter )
{
    return xParameter - Floor( xParameter );
}

template < class T >
static FORCE_INLINE T Sign( const T& xParameter )
{
    return ( xParameter > 0 ) ? T( 1 ) : T( ( xParameter < 0 ) ? -1 : 0 );
}

template < class T >
static FORCE_INLINE T Square( const T& xParameter )
{
    return xParameter * xParameter;
}
    
// SE - NOTE: x86/x64 have intrinsics that use the lookup table instructions
// ... but even without that the pointer aliasing makes doing the div and sqrt
// faster on modern implementations of these architectures
static FORCE_INLINE float FasterInvSqrt( const float f )
{
#if CPU_X86 || CPU_X64
    return 1.0f / SquareRoot( f );
#else
    int i = *reinterpret_cast< const int* >( &f );
    i = 0x5F375A84 - ( i >> 1 );
    return *reinterpret_cast< float* >( &i );
#endif
}

static FORCE_INLINE float FastInvSqrt( const float f )
{
#if CPU_X86 || CPU_X64
    return 1.0f / SquareRoot( f );
#else
    const float fHalf = 0.5f * f;
    const float fApproximation = FasterInvSqrt( f );
    return fApproximation * ( 1.5f - fHalf * fApproximation * fApproximation );
#endif
}

template < class T > static FORCE_INLINE int FloorToInt( const T xValue ) { return static_cast< int >( Floor( xValue ) ); }
template < class T > static FORCE_INLINE int CeilToInt( const T xValue ) { return static_cast< int >( Ceil( xValue ) ); }

template < class T > static FORCE_INLINE T Max( const T xValue1, const T xValue2 ) { return ( xValue1 > xValue2 ) ? xValue1 : xValue2; }
template < class T > static FORCE_INLINE T Max( const T xValue1, const T xValue2, const T xValue3 ) { return Max( xValue1, Max( xValue2, xValue3 ) ); }
template < class T > static FORCE_INLINE T Max( const T xValue1, const T xValue2, const T xValue3, const T xValue4 ) { return Max( Max( xValue1, xValue2 ), Max( xValue3, xValue4 ) ); }
template < class T > static FORCE_INLINE T Min( const T xValue1, const T xValue2 ) { return ( xValue1 < xValue2 ) ? xValue1 : xValue2; }
template < class T > static FORCE_INLINE T Min( const T xValue1, const T xValue2, const T xValue3 ) { return Min( xValue1, Min( xValue2, xValue3 ) ); }
template < class T > static FORCE_INLINE T Min( const T xValue1, const T xValue2, const T xValue3, const T xValue4 ) { return Min( Min( xValue1, xValue2 ), Min( xValue3, xValue4 ) ); }
template < class T > static FORCE_INLINE T Clamp( const T xValue, const T xMin = 0.0, const T xMax = 1.0 ) { return Min( xMax, Max( xValue, xMin ) ); }

static FORCE_INLINE float Wrap( const float fValue, const float fMin = 0.0f, const float fMax = 1.0f )
{
	debugAssert( fMax > fMin, "Minimum is greater than maximum!" );

	const float fRange = fMax - fMin;
	float fReturnValue = ( fValue - fMin ) / fRange;
	// lazy - avoiding library floating point mod
	const float fIntegerPart = Floor( fReturnValue );
	fReturnValue -= fIntegerPart;
	fReturnValue *= fRange;
	return fReturnValue + fMin;
}

static FORCE_INLINE unsigned int Wrap( const unsigned int uValue, const unsigned int uMin = 0, const unsigned int uMax = 1 )
{
	debugAssert( uMax > uMin, "Minimum is greater than maximum!" );
	return uMin + ( ( uValue - uMin ) % ( uMax - uMin ) );
}

template < class T >
static FORCE_INLINE T SmoothStep( const T& xParameter )
{
	return ( static_cast< T >( 3.0 ) - static_cast< T >( 2.0 ) * xParameter ) * xParameter * xParameter;
}

template < class T >
static FORCE_INLINE T SmootherStep( const T& xParameter )
{
	return ( ( static_cast< T >( 6.0 ) * xParameter - static_cast< T >( 15.0 ) ) * xParameter + static_cast< T >( 10.0 ) ) * xParameter * xParameter * xParameter;
}

template < class T >
static FORCE_INLINE T Lerp( const T& xValue1, const T& xValue2, const float fAmount )
{
	return xValue1 + ( xValue2 - xValue1 ) * fAmount;
}

template < class T >
static FORCE_INLINE T ClampedLerp( const T& xValue1, const T& xValue2, const float fAmount )
{
	return Lerp( xValue1, xValue2, Clamp( fAmount ) );
}

template < class T >
static FORCE_INLINE T CosineInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return Lerp( xValue1, xValue2, 0.5f * ( 1.0f - Cos( PiFloat * fAmount ) ) );
}

template < class T >
static FORCE_INLINE T SmoothStepInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return Lerp( xValue1, xValue2, SmoothStep( fAmount ) );
}

template < class T >
static FORCE_INLINE T SmootherStepInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return Lerp( xValue1, xValue2, SmootherStep( fAmount ) );
}

template < class T >
static FORCE_INLINE T ClampedCosineInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return CosineInterpolate( xValue1, xValue2, Clamp( fAmount ) );
}

template < class T >
static FORCE_INLINE T ClampedSmoothStepInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return SmoothStepInterpolate( xValue1, xValue2, Clamp( fAmount ) );
}

template < class T >
static FORCE_INLINE T ClampedSmootherStepInterpolate( const T& xValue1, const T& xValue2, const float fAmount )
{
	return SmootherStepInterpolate( xValue1, xValue2, Clamp( fAmount ) );
}
        
template < class T >
static FORCE_INLINE T CubicInterpolate( const T& xValue1, const T& xValue2, const T& xValue3, const T& xValue4, const float fAmount )
{
	const T xA = xValue4 - xValue3 + xValue2 - xValue1;
	const T xB = xValue1 - xValue2 - xA;
	const T xC = xValue3 - xValue1;
	const T xD = xValue2;

	return ( ( xA * fAmount + xB ) * fAmount + xC ) * fAmount + xD;
}

template < class T >
static FORCE_INLINE T CatmullRomInterpolate( const T& xValue1, const T& xValue2, const T& xValue3, const T& xValue4, const float fAmount )
{
	const T xA = 0.5f * xValue4 - 1.5f * xValue3 + 1.5f * xValue2 - 0.5f * xValue1;
	const T xB = xValue1 - 2.5f * xValue2 + 2.0f * xValue3 - 0.5f * xValue4;
	const T xC = 0.5f * ( xValue3 - xValue1 );
	const T xD = xValue2;

	return ( ( xA * fAmount + xB ) * fAmount + xC ) * fAmount + xD;
}

template < class T >
static FORCE_INLINE T ClampedCubicInterpolate( const T& xValue1, const T& xValue2, const T& xValue3, const T& xValue4, const float fAmount )
{
	return CubicInterpolate( xValue1, xValue2, xValue3, xValue4, Clamp( fAmount ) );
}

template < class T >
static FORCE_INLINE T ClampedCatmullRomInterpolate( const T& xValue1, const T& xValue2, const T& xValue3, const T& xValue4, const float fAmount )
{
	return CatmullRomInterpolate( xValue1, xValue2, xValue3, xValue4, Clamp( fAmount ) );
}

static FORCE_INLINE float Deg2Rad( const float fDegrees )
{
	return ( PiFloat / 180.f ) * fDegrees;
}

static FORCE_INLINE float Rad2Deg( const float fDegrees )
{
	return ( 180.f / PiFloat ) * fDegrees;
}

static FORCE_INLINE double Deg2Rad( const double fDegrees )
{
    return ( PiDouble / 180.0 ) * fDegrees;
}

static FORCE_INLINE double Rad2Deg( const double fDegrees )
{
    return ( 180.0 / PiDouble ) * fDegrees;
}

extern unsigned int suLastSeed;
   
static inline unsigned int SetRandomSeed( const unsigned int uSeed )
{
    return ( suLastSeed = uSeed );
}
    
static inline unsigned int NextPRNGSeed()
{
	
	
	// SE - TODO: proper seeding
	/*
	if( s_last == 0 )
	{
		s_last = ( unsigned int )( Time.realtimeSinceStartup * 100000.0 );
	}
	*/

	suLastSeed = ( suLastSeed * 16807 + 2147483647 ) & 0xFFFFFFFF;
	suLastSeed = ( suLastSeed ^ ( ( suLastSeed & 0xFFFF ) << 16 ) ); // mix up the bits a bit...
	return suLastSeed;
}

// SE - follows the broken seeming pattern of unity random range generators where
// ints drop the highest value so they generate valid array indices if a = 0 and b = <size of array>
static inline float PRNGRange( float a, float b )
{
	const float offset = static_cast< float >( static_cast< double >( NextPRNGSeed() ) / static_cast< double >( 0xFFFFFFFF ) ) * ( b - a );
	return a + offset;
}

static inline int PRNGRange( int a, int b )
{
	const int offset = static_cast< int >( Floor( static_cast< float >( static_cast< double >( NextPRNGSeed() ) / static_cast< double >( 0xFFFFFFFF ) ) * static_cast< float >( b - a ) ) );
	return a + offset;
}

void RegisterUnitTests();

}

#endif
