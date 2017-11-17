// Copyright (c) 2013-2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PDE_VECTOR_H
#define PDE_VECTOR_H

#include "PDEMaths.h"
#include "PDEMathsOperator.h"

#if COMPILER_MS
// SE: this is desirable - so much inlining happened that something became a constant :)
#pragma warning( disable: 4127 )
#endif

// SE - TODO: alignment and faster copies...

namespace PDE
{

template< class BaseType, int iComponentCount >
class VectorBase
{

public:

	typedef BaseType ComponentType;
	static VectorBase Zero;
    static VectorBase One;

    VectorBase() {}
    
    VectorBase( const BaseType& xScalar )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = xScalar;
        }
    }
    
    VectorBase( const VectorBase& v )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = v.maComponents[ i ];
        }
    }
    
    VectorBase& operator =( const VectorBase& v )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = v.maComponents[ i ];
        }
        
        return *this;
    }
    
    bool ApproximatelyEquals( const VectorBase& xOther, const BaseType& dAmount ) const
    {
        VectorBase xDifference = ( *this - xOther ) / this->Magnitude();
        for( int i = 0; i < iComponentCount; ++i )
        {
            if( PDE::Abs( xDifference[ i ] ) > dAmount )
            {
                return false;
            }
        }
        
        return true;
    }

    bool operator ==( const VectorBase& v ) const
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            if( maComponents[ i ] != v.maComponents[ i ] )
            {
                return false;
            }
        }

        return true;
    }

    bool operator !=( const VectorBase& v ) const
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            if( maComponents[ i ] != v.maComponents[ i ] )
            {
                return true;
            }
        }

        return false;
    }
    
	VECTOR_COMPONENT_WISE_UNARY_OPERATOR( VectorBase, BaseType, += )
	VECTOR_COMPONENT_WISE_UNARY_OPERATOR( VectorBase, BaseType, -= )
	VECTOR_COMPONENT_WISE_UNARY_OPERATOR( VectorBase, BaseType, *= )
	VECTOR_COMPONENT_WISE_UNARY_OPERATOR( VectorBase, BaseType, /= )
    
	VECTOR_COMPONENT_WISE_BINARY_OPERATOR_FROM_UNARY( VectorBase, BaseType, +, += )
	VECTOR_COMPONENT_WISE_BINARY_OPERATOR_FROM_UNARY( VectorBase, BaseType, -, -= )
	VECTOR_COMPONENT_WISE_BINARY_OPERATOR_FROM_UNARY( VectorBase, BaseType, *, *= )
	VECTOR_COMPONENT_WISE_BINARY_OPERATOR_FROM_UNARY( VectorBase, BaseType, /, /= )
    
	COMMUTATIVE_PRE_OPERATOR( BaseType, VectorBase, + )
	COMMUTATIVE_PRE_OPERATOR( BaseType, VectorBase, * )
    
    FORCE_INLINE VectorBase operator -() const
    {
        VectorBase xReturnValue = *this;
        for( int i = 0; i < iComponentCount; ++i )
        {
            xReturnValue[ i ] = -maComponents[ i ];
        }
        
        return xReturnValue;
    }

    FORCE_INLINE VectorBase operator +() const
    {
        return *this;
    }
    
    // ... what was i thinking!?!?
    /*
    friend FORCE_INLINE VectorBase operator /( const BaseType& x, const VectorBase& v )
    {
        return v * ( 1.0f / x );
    }
    */

    friend FORCE_INLINE VectorBase operator -( const BaseType& x, const VectorBase& v )
    {
        return VectorBase( x ) - v;
    }
    
    FORCE_INLINE BaseType& operator[]( const int i ) { return maComponents[ i ]; }
    FORCE_INLINE const BaseType& operator[]( const int i ) const { return maComponents[ i ]; }
    
    BaseType Dot( const VectorBase& v ) const
    {
        BaseType xReturnValue = static_cast< BaseType >( 0.0 );
        VectorBase xTemp = *this * v;
        for( int i = 0; i < iComponentCount; ++i )
        {
            xReturnValue += xTemp[ i ];
        }
        return xReturnValue;
    }
    
    BaseType MagnitudeSquared() const { return this->Dot( *this ); }
    BaseType Magnitude() const { return PDE::SquareRoot( MagnitudeSquared() ); }

	VectorBase Normalised() const { return *this / Magnitude(); }
    VectorBase NormalisedFast() const { return *this * PDE::FastInvSqrt( MagnitudeSquared() ); }
    VectorBase NormalisedFaster() const { return *this * PDE::FasterInvSqrt( MagnitudeSquared() ); }

    FORCE_INLINE VectorBase< BaseType, 3 >& xyz() { return *reinterpret_cast< VectorBase< BaseType, 3 >* >( this ); }
	FORCE_INLINE const VectorBase< BaseType, 3 >& xyz() const { return *reinterpret_cast< const VectorBase< BaseType, 3 >* >( this ); }
    FORCE_INLINE VectorBase< BaseType, 2 >& xy() { return *reinterpret_cast< VectorBase< BaseType, 2 >* >( this ); }
	FORCE_INLINE const VectorBase< BaseType, 2 >& xy() const { return *reinterpret_cast< const VectorBase< BaseType, 2 >* >( this ); }
    FORCE_INLINE VectorBase< BaseType, 2 > xz() const
    {
        VectorBase< BaseType, 2 > xReturnValue( xy() );
        
        xReturnValue[ 1 ] = maComponents[ 2 ];
        
        return xReturnValue;
    }

    VectorBase< BaseType, 3 > Cross( const VectorBase< BaseType, 3 >& xOther ) const
    {
        VectorBase< BaseType, 3 > xReturnValue;

        xReturnValue[ 0 ] = maComponents[ 1 ] * xOther[ 2 ] - maComponents[ 2 ] * xOther[ 1 ];
        xReturnValue[ 1 ] = maComponents[ 2 ] * xOther[ 0 ] - maComponents[ 0 ] * xOther[ 2 ];
        xReturnValue[ 2 ] = maComponents[ 0 ] * xOther[ 1 ] - maComponents[ 1 ] * xOther[ 0 ];
        
        return xReturnValue;
    }

    FORCE_INLINE BaseType& x() { return maComponents[ 0 ]; }
    FORCE_INLINE BaseType& y() { return maComponents[ 1 ]; }
    FORCE_INLINE BaseType& z() { return maComponents[ 2 ]; }
    FORCE_INLINE BaseType& w() { return maComponents[ 3 ]; }
    
    FORCE_INLINE const BaseType& x() const { return maComponents[ 0 ]; }
    FORCE_INLINE const BaseType& y() const { return maComponents[ 1 ]; }
    FORCE_INLINE const BaseType& z() const { return maComponents[ 2 ]; }
    FORCE_INLINE const BaseType& w() const { return maComponents[ 3 ]; }

    template< class MatrixType >
    VectorBase MatrixMultiply( const MatrixType& xMatrix ) const
    {
        VectorBase xReturnValue;
        for( int i = 0; i < iComponentCount; ++i )
        {
            xReturnValue[ i ] = 0.0f;

            // V_i = V^j M^i_j
            for( int j = 0; j < iComponentCount; ++j )
            {
                xReturnValue[ i ] += maComponents[ j ] * xMatrix[ j ][ i ];
            }
        }
        
        return xReturnValue;
    }
    
protected:

    BaseType maComponents[ iComponentCount ];

};

template< class BaseType, int iComponentCount >
VectorBase< BaseType, iComponentCount > VectorBase< BaseType, iComponentCount >::Zero =
    VectorBase< BaseType, iComponentCount >( static_cast< BaseType >( 0.0 ) );
template< class BaseType, int iComponentCount >
VectorBase< BaseType, iComponentCount > VectorBase< BaseType, iComponentCount >::One =
    VectorBase< BaseType, iComponentCount >( static_cast< BaseType >( 1.0 ) );

class Vector2
: public VectorBase< float, 2 >
{

	typedef VectorBase< float, 2 > Base;

public:

    Vector2( const float x = 0.0f, const float y = 0.0f )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
    }

    Vector2( const Base& xOther )
    {
        maComponents[ 0 ] = xOther[ 0 ];
        maComponents[ 1 ] = xOther[ 1 ];
    }
    
    float Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ] ); }
    float Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ] ); }

	Vector2 xx() const { return Vector2( maComponents[ 0 ] ); }
	Vector2 yy() const { return Vector2( maComponents[ 1 ] ); }
	Vector2 yx() const { return Vector2( maComponents[ 1 ], maComponents[ 0 ] ); }
    
    Vector2 FastRotate90CCW() const
    {
        return Vector2( -maComponents[ 1 ], maComponents[ 0 ] );
    }

    Vector2 FastRotate90CW() const
    {
        return Vector2( maComponents[ 1 ], -maComponents[ 0 ] );
    }
    
	//USE_BASE_OPERATORS( Base )

};

class Vector3
: public VectorBase< float, 3 >
{
    
	typedef VectorBase< float, 3 > Base;

public:
    
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Forward;
	static const Vector3 Backward;
	static const Vector3 Left;
	static const Vector3 Right;

	Vector3( const Base& v )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
    }

    Vector3( const float x = 0.0f, const float y = 0.0f, const float z = 0.0f )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
        maComponents[ 2 ] = z;
    }
    
    Vector3( const Vector2& v, const float z = 0.0f )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
    }

	static Vector3 RandomDirection();
	static Vector3 RandomNormalisedDirection();

	float Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }
	float Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }

    static Vector3 FromEllipsoid( const float fLon, const float fLat, float fPolar, float fEquatorial )
    {
        return Vector3(
                       fEquatorial * PDE::Sin( fLat ) * PDE::Cos( fLon ),
                       fEquatorial * PDE::Sin( fLat ) * PDE::Sin( fLon ),
                       fPolar * PDE::Cos( fLat )
        );
    }
    
	//USE_BASE_OPERATORS( Base )
    
};

class Vector4
: public VectorBase< float, 4 >
{
    
	typedef VectorBase< float, 4 > Base;

public:

	static const Vector4 White;
	static const Vector4 Black;
	static const Vector4 Transparent;
	static const Vector4 Red;
	static const Vector4 Green;
	static const Vector4 Blue;
    
	Vector4( const Base& v )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
		maComponents[ 3 ] = v[ 3 ];
    }

    Vector4( const float x = 0.0f, const float y = 0.0f, const float z = 0.0f, const float w = 1.0f )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
        maComponents[ 2 ] = z;
        maComponents[ 3 ] = w;
    }
    
    Vector4( const Vector3& v, const float w = 1.0f )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
        maComponents[ 3 ] = w;
    }

    Vector4( const Vector2& v, const float z = 0.0f , const float w = 1.0f )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
        maComponents[ 3 ] = w;
    }

    float Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }
    float Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }
    
    unsigned int RGBA() const
    {
        return ( static_cast< unsigned int >( maComponents[ 0 ] * 255.0f ) << 24 )
            | ( static_cast< unsigned int >( maComponents[ 1 ] * 255.0f ) << 16 )
            | ( static_cast< unsigned int >( maComponents[ 2 ] * 255.0f ) << 8 )
            | static_cast< unsigned int >( maComponents[ 3 ] * 255.0f );
    }
    
    static Vector4 FromRGB( const unsigned char uR, const unsigned char uG, const unsigned char uB )
    {
        return Vector4( static_cast< float >( uR ) / 255.0f,
            static_cast< float >( uG ) / 255.0f,
            static_cast< float >( uB ) / 255.0f );
    }

	//USE_BASE_OPERATORS( Base )
    
};

}

#endif

