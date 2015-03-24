// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDEMaths.h"

#include "PDEMatrix.h"
//#include "Maths/NaNCheck.h"
//#include "Maths/Random.h"
//#include "Maths/Ray.h"
//#include "Maths/Sphere.h"
//#include "Maths/Quaternion.h"
#include "PDEVector.h"

#include "Debug/PDETrace.h"
//#include "UnitTest/UnitTest.h"

namespace PDE
{

unsigned int suLastSeed = 0;

#if 0

template < class T >
bool VectorSubtractionIsAdditiveInverse()
{
	const float EPSILON = 0.0001f;
    T xTest( 3.0 );
    
	return static_cast< float >( ( xTest - xTest ).MagnitudeSquared() ) < EPSILON; //-V501
}

template < class T >
bool VectorNormalisedVectorHasLengthOne()
{
	const float EPSILON = 0.0001f;
    T xTest( 17.0 );
    
	return Abs( static_cast< float >( ( xTest.Normalised() ).MagnitudeSquared() ) - 1.0f ) < EPSILON;
}

bool UnitRandomVector2()
{
	const float EPSILON = 0.001f;
	for( int i = 0; i < 100; ++i )
	{
		if( Abs( Random::UnitVector2().MagnitudeSquared() - 1.0f ) > EPSILON )
		{
			return false;
		}
	}

	return true;
}

bool UnitRandomVector3()
{
	const float EPSILON = 0.001f;
	for( int i = 0; i < 100; ++i )
	{
		if( Abs( Random::UnitVector3().MagnitudeSquared() - 1.0f ) > EPSILON )
		{
			return false;
		}
	}

	return true;
}

bool UnitRandomVector4()
{
	const float EPSILON = 0.001f;
	for( int i = 0; i < 100; ++i )
	{
		if( Abs( Random::UnitVector4().MagnitudeSquared() - 1.0f ) > EPSILON )
		{
			return false;
		}
	}

	return true;
}

template < class T >
bool SmoothStepConstraints()
{
	const float EPSILON = 0.0001f;
    const T xZero = SmoothStep( static_cast< T >( 0.0 ) );
	const T xMid = SmoothStep( static_cast< T >( 0.5 ) );
	const T xOne = SmoothStep( static_cast< T >( 1.0 ) );
    
	return ( Abs( static_cast< float >( xZero ) - 0.0f ) < EPSILON )
		&& ( Abs( static_cast< float >( xMid ) - 0.5f ) < EPSILON )
		&& ( Abs( static_cast< float >( xOne ) - 1.0f ) < EPSILON );
}

template < class T >
bool SmootherStepConstraints()
{
	const float EPSILON = 0.0001f;
    const T xZero = SmootherStep( static_cast< T >( 0.0 ) );
	const T xMid = SmootherStep( static_cast< T >( 0.5 ) );
	const T xOne = SmootherStep( static_cast< T >( 1.0 ) );
    
	return ( Abs( static_cast< float >( xZero ) - 0.0f ) < EPSILON )
		&& ( Abs( static_cast< float >( xMid ) - 0.5f ) < EPSILON )
		&& ( Abs( static_cast< float >( xOne ) - 1.0f ) < EPSILON );
}

bool NaNCheckTest()
{
    static const unsigned int uValue = 0x78000000;
    // cppcheck-suppress invalidPointerCast
    return IsNaN( *reinterpret_cast< const float* >( &uValue ) )
	
		// MS compiler refuses to let me divide by zero in this genuine case where I want to...
#if !COMPILER_MS
		&& IsNaN( 1.0f / 0.0f )
#endif

		;
}

template< class T >
bool VectorDivideTest()
{
	const float EPSILON = 0.0001f;
	for( int i = 0; i < 100; ++i )
	{
		const typename T::ComponentType xTestValue1 = static_cast< typename T::ComponentType >( Maths::PRNGRange( -10.0f, 10.0f ) ); //-V656
		const typename T::ComponentType xTestValue2 = static_cast< typename T::ComponentType >( Maths::PRNGRange( -10.0f, 10.0f ) ); //-V656

		T xTest( xTestValue1 );
		xTest /= xTestValue2;

		if( Abs( xTest[ 0 ] - ( xTestValue1 / xTestValue2 ) ) > EPSILON )
		{
			return false;
		}
	}

	return true;
}

template< class T >
bool MatrixDivideTest()
{
	const float EPSILON = 0.0001f;
	for( int i = 0; i < 100; ++i )
	{
		const typename T::ComponentType xTestValue1 = static_cast< typename T::ComponentType >( Maths::PRNGRange( -10.0f, 10.0f ) ); //-V656
		const typename T::ComponentType xTestValue2 = static_cast< typename T::ComponentType >( Maths::PRNGRange( -10.0f, 10.0f ) ); //-V656

		T xTest( xTestValue1 );
		xTest = xTest / xTestValue2;

		if( Abs( xTest[ 0 ][ 0 ] - ( xTestValue1 / xTestValue2 ) ) > EPSILON )
		{
			return false;
		}
	}

	return true;
}

bool MatrixInverseTest()
{
	const float EPSILON = 0.001f;
	for( int i = 0; i < 100; ++i )
	{
		const Matrix4 xTest(
			Vector4( Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ) ),
			Vector4( Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ) ),
			Vector4( Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ) ),
			Vector4( Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ), Maths::PRNGRange( -1.0f, 1.0f ) ) );

		const Matrix4 xShouldBeIdentity = xTest * xTest.Inverse();
		for( int j = 0; j < 4; ++j )
		{
			for( int k = 0; k < 4; ++k )
			{
				if( Abs( xShouldBeIdentity[ j ][ k ] - Matrix4::Identity[ j ][ k ] ) > EPSILON )
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool RaytraceSphereTest1()
{
    return Sphere( Vector3::Zero, 1.0f ).RayCast( Ray( Vector3::Zero, Vector3::One ) ).Hit;
}

bool RaytraceSphereTest2()
{
    return Sphere( Vector3::Zero, 1.0f ).RayCast( Ray( Vector3::Up * 2.0f, Vector3::Down ) ).Hit;
}

bool RaytraceSphereTest3()
{
    return Sphere( Vector3::Forward * 2.0f, 1.0f ).RayCast( Ray( Vector3::Zero, Vector3::Forward ) ).Hit;
}

void RegisterUnitTests()
{
	UnitTest::Add( VectorSubtractionIsAdditiveInverse< Vector2 >, "Vector2 subtraction is additive inverse" );
	UnitTest::Add( VectorSubtractionIsAdditiveInverse< Vector3 >, "Vector3 subtraction is additive inverse" );
	UnitTest::Add( VectorSubtractionIsAdditiveInverse< Vector4 >, "Vector4 subtraction is additive inverse" );
	UnitTest::Add( VectorSubtractionIsAdditiveInverse< Quaternion >, "Quaternion subtraction is additive inverse" );
	UnitTest::Add( VectorNormalisedVectorHasLengthOne< Vector2 >, "Normalised Vector2 has unit Magnitude" );
	UnitTest::Add( VectorNormalisedVectorHasLengthOne< Vector3 >, "Normalised Vector3 has unit Magnitude" );
	UnitTest::Add( VectorNormalisedVectorHasLengthOne< Vector4 >, "Normalised Vector4 has unit Magnitude" );
	UnitTest::Add( UnitRandomVector2, "Random unit Vector2 has unit Magnitude" );
	UnitTest::Add( UnitRandomVector3, "Random unit Vector3 has unit Magnitude" );
	UnitTest::Add( UnitRandomVector4, "Random unit Vector4 has unit Magnitude" );
	UnitTest::Add( VectorDivideTest< Vector2 >, "Vector2 scalar division first component is correct" );
	UnitTest::Add( VectorDivideTest< Vector3 >, "Vector3 scalar division first component is correct" );
	UnitTest::Add( VectorDivideTest< Vector4 >, "Vector4 scalar division first component is correct" );
	UnitTest::Add( MatrixDivideTest< Matrix3 >, "Matrix3 scalar division first component is correct" );
	UnitTest::Add( MatrixDivideTest< Matrix4 >, "Matrix4 scalar division first component is correct" );
	UnitTest::Add( SmoothStepConstraints< double >, "Smooth step function meets constraints" );
	UnitTest::Add( SmootherStepConstraints< double >, "Smoother step function meets constraints" );
    UnitTest::Add( RaytraceSphereTest1, "Unit sphere hit by ray from origin" );
    UnitTest::Add( RaytraceSphereTest2, "Unit sphere hit by ray from above" );
    UnitTest::Add( RaytraceSphereTest3, "Unit sphere in front of origin hit by ray facing forwards" );
    UnitTest::Add( NaNCheckTest, "Test NaN checker against IEEE QNaN and 1.0f / 0.0f" );
	UnitTest::Add( MatrixInverseTest, "Matrix inverse works" );
}

#endif

}
