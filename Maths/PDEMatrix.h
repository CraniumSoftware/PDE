// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PDE_MATRIX_H
#define PDE_MATRIX_H

// SE - trust the compiler to decide to not inline things we mark FORCE_INLINE because the template depth here
// is potentially much deeper than it looks at first glance and we want any old components to work...

#if WIN
#pragma warning( disable : 4714 )
#endif

#include "PDEMaths.h"
#include "PDEVector.h"

namespace PDE
{

template< class BaseType, int iComponentCount >
class MatrixBase
{

public:

	typedef BaseType ComponentType;

    static MatrixBase Identity;
	static MatrixBase Zero;
    
    MatrixBase() {}
    
    MatrixBase( const BaseType& xScalar )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = xScalar;
        }
    }
    
    MatrixBase( const MatrixBase& m )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = m[ i ];
        }
    }
    
    FORCE_INLINE MatrixBase& operator =( const MatrixBase& m )
    {
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = m[ i ];
        }
        
        return *this;
    }

	FORCE_INLINE MatrixBase operator -() const
    {
        MatrixBase xReturnValue = *this;
        for( int i = 0; i < iComponentCount; ++i )
        {
            maComponents[ i ] = -maComponents[ i ];
        }
        
        return xReturnValue;
    }

    FORCE_INLINE MatrixBase operator *( const MatrixBase& m ) const
    {
        MatrixBase xResult( Zero );
        for( int i = 0; i < iComponentCount; ++i )
        {
            for( int j = 0; j < iComponentCount; ++j )
            {
                xResult[ i ][ j ] = static_cast< BaseType >( 0.0 );
                for( int k = 0; k < iComponentCount; ++ k )
                {
                    xResult[ i ][ j ] += ( *this )[ i ][ k ] * m[ k ][ j ];
                }
            }
        }
        
        return xResult;
    }

    FORCE_INLINE VectorBase< BaseType, iComponentCount > operator *( const VectorBase< BaseType, iComponentCount >& v ) const
    {
        VectorBase< BaseType, iComponentCount > xResult( 0.0f );
        for( int i = 0; i < iComponentCount; ++i )
        {
            xResult[ i ] = v.Dot( maComponents[ i ] );
        }

        return xResult;
    }

    FORCE_INLINE MatrixBase operator *( const BaseType& x ) const
    {
		MatrixBase xResult( *this );
        for( int i = 0; i < iComponentCount; ++i )
        {
            xResult[ i ] *= x;
        }

        return xResult;
    }

    FORCE_INLINE MatrixBase operator /( const BaseType& x ) const
    {
        MatrixBase xResult( *this );
        for( int i = 0; i < iComponentCount; ++i )
        {
            xResult[ i ] /= x;
        }

        return xResult;
    }
    
    static FORCE_INLINE MatrixBase Diagonal( const BaseType& xScalar )
    {
        MatrixBase xReturnValue( Zero );
        
        for( int i = 0; i < iComponentCount; ++i )
        {
            xReturnValue[ i ][ i ] = xScalar;
        }
        
        return xReturnValue;
    }
    
    FORCE_INLINE VectorBase< BaseType, iComponentCount >& operator[]( const int i )
    {
        return maComponents[ i ];
    }
    
    FORCE_INLINE const VectorBase< BaseType, iComponentCount >& operator[]( const int i ) const
    {
        return maComponents[ i ];
    }
    
protected:

    VectorBase< BaseType, iComponentCount > maComponents[ iComponentCount ];
    
};

template< class BaseType, int iComponentCount >
MatrixBase< BaseType, iComponentCount > MatrixBase< BaseType, iComponentCount >::Identity =
    MatrixBase< BaseType, iComponentCount >::Diagonal( static_cast< BaseType >( 1.0 ) );

template< class BaseType, int iComponentCount >
MatrixBase< BaseType, iComponentCount > MatrixBase< BaseType, iComponentCount >::Zero =
    MatrixBase< BaseType, iComponentCount >::Diagonal( static_cast< BaseType >( 0.0 ) );

class Matrix3
: public MatrixBase< float, 3 >
{

public:

	typedef MatrixBase< float, 3 > BaseType;

	FORCE_INLINE Matrix3() {}

	FORCE_INLINE Matrix3( const MatrixBase& m )
    {
        for( int i = 0; i < 3; ++i )
        {
            maComponents[ i ] = m[ i ];
        }
    }

    FORCE_INLINE Matrix3( const Vector3& x, const Vector3& y, const Vector3& z )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
        maComponents[ 2 ] = z;
    }

	FORCE_INLINE Matrix3& operator =( const MatrixBase& m )
    {
        for( int i = 0; i < 3; ++i )
        {
            maComponents[ i ] = m[ i ];
        }

        return *this;
    }

    // SE - TODO: this could be done without copies using xor swaps
    void Transpose()
    {
        Vector3 xX = Vector3( maComponents[ 0 ][ 0 ], maComponents[ 1 ][ 0 ], maComponents[ 2 ][ 0 ] );
        Vector3 xY = Vector3( maComponents[ 0 ][ 1 ], maComponents[ 1 ][ 1 ], maComponents[ 2 ][ 1 ] );
        Vector3 xZ = Vector3( maComponents[ 0 ][ 2 ], maComponents[ 1 ][ 2 ], maComponents[ 2 ][ 2 ] );

        maComponents[ 0 ] = xX;
        maComponents[ 1 ] = xY;
        maComponents[ 2 ] = xZ;
    }
};

class Matrix4
: public MatrixBase< float, 4 >
{

public:

	typedef MatrixBase< float, 4 > BaseType;

	FORCE_INLINE Matrix4() {}

    FORCE_INLINE Matrix4( const Vector4& xComponent, const Vector4& yComponent, const Vector4& zComponent, const Vector4& wComponent )
    {
        maComponents[ 0 ] = xComponent;
        maComponents[ 1 ] = yComponent;
        maComponents[ 2 ] = zComponent;
        maComponents[ 3 ] = wComponent;
    }
    
	FORCE_INLINE Matrix4( const MatrixBase& m )
    {
        for( int i = 0; i < 4; ++i )
        {
            maComponents[ i ] = m[ i ];
        }
    }

	FORCE_INLINE Matrix4& operator =( const MatrixBase& m )
    {
        for( int i = 0; i < 4; ++i )
        {
            maComponents[ i ] = m[ i ];
        }
        
        return *this;
    }

	FORCE_INLINE Vector3 GetTranslation() const
	{
		return maComponents[ 3 ].xyz();
	}

	FORCE_INLINE void SetTranslation( const Vector3& xTranslation )
	{
		maComponents[ 3 ].xyz() = xTranslation;
	}

    FORCE_INLINE void SetUpper3x3( const Matrix3& xRotation )
	{
		for( int i = 0; i < 3; ++i )
        {
            maComponents[ i ].xyz() = xRotation[ i ];
        }
	}

    static FORCE_INLINE Matrix4 Orthographic( const ComponentType& xLeft, const ComponentType& xRight, const ComponentType& xBottom, const ComponentType& xTop, const ComponentType& xNear, const ComponentType& xFar )
    {
        Matrix4 xReturnValue = Identity;

        // SE - I named the variables to try and demystify the orthomatrix - it is just a scale and offset

        // SE: i think one of these x/y is flipped, but the matrix looks good...
        const ComponentType xScaleX = static_cast< ComponentType >( 2.0 ) / ( xRight - xLeft );
        const ComponentType xScaleY = static_cast< ComponentType >( 2.0 ) / ( xTop - xBottom );
        const ComponentType xScaleZ = static_cast< ComponentType >( 2.0 ) / ( xFar - xNear );

        xReturnValue[ 0 ][ 0 ] = xScaleX;
        xReturnValue[ 1 ][ 1 ] = xScaleY;
        xReturnValue[ 2 ][ 2 ] = xScaleZ;

        // this is just a translation to centre it - find the offset from the origin ( xRight + xLeft in X for example... ) then divide by dimension (width in X for example...)
        xReturnValue[ 3 ][ 0 ] = ( xRight + xLeft ) / ( xRight - xLeft );
        xReturnValue[ 3 ][ 1 ] = ( xTop + xBottom ) / ( xTop - xBottom );
        xReturnValue[ 3 ][ 2 ] = ( xFar + xNear ) / ( xFar - xNear ); // SE: pretty sure this is pointless... :/

        return xReturnValue;
    }

    static FORCE_INLINE Matrix4 Orthographic( const ComponentType& xSize, const ComponentType& xNear, const ComponentType& xFar )
    {
        return Orthographic( -xSize, xSize, -xSize, xSize, xNear, xFar );
    }


	static FORCE_INLINE Matrix4 Perspective( const ComponentType& xLeft, const ComponentType& xRight, const ComponentType& xBottom, const ComponentType& xTop, const ComponentType& xNear, const ComponentType& xFar )
	{
		Matrix4 xReturnValue = Zero;

		const ComponentType xTemp = static_cast< ComponentType >( 2.0 ) * xNear;
		const ComponentType xTemp2 = static_cast< ComponentType >( 1.0 ) / ( xRight - xLeft );
		const ComponentType xTemp3 = static_cast< ComponentType >( 1.0 ) / ( xTop - xBottom );
		const ComponentType xTemp4 = static_cast< ComponentType >( 1.0 ) / ( xFar - xNear );
    
		xReturnValue[ 0 ][ 0 ] = xTemp * xTemp2;

		xReturnValue[ 1 ][ 1 ] = xTemp * xTemp3;

		xReturnValue[ 2 ][ 0 ] = ( xRight + xLeft ) * xTemp2;
		xReturnValue[ 2 ][ 1 ] = ( xTop + xBottom ) * xTemp3;
		xReturnValue[ 2 ][ 2 ] = -xFar * xTemp4;
		xReturnValue[ 2 ][ 3 ] = static_cast< ComponentType >( -1.0 );
		
		xReturnValue[ 3 ][ 2 ] = -xFar * xNear * xTemp4;

		return xReturnValue;
	}


	static FORCE_INLINE Matrix4 Perspective( const ComponentType& xFOVY, const ComponentType& xAspect, const ComponentType& xNear, const ComponentType& xFar )
	{    
        const ComponentType xY = xNear * PDE::Tan( xFOVY * static_cast< ComponentType >( PDE::PiDouble / 360.0 ) );
		const ComponentType xX = xY * xAspect;
    
		return Perspective( -xX, xX, -xY, xY, xNear, xFar );
	}

	static FORCE_INLINE Matrix4 Translation( const Vector3& xTranslation )
	{
		Matrix4 xReturnValue = Identity;
		xReturnValue.SetTranslation( xTranslation );
		return xReturnValue;
	}

    static FORCE_INLINE Matrix4 LookAt( const Vector3& xFrom, const Vector3& xTo )
    {
        Matrix4 xReturnValue = Identity;
        xReturnValue.SetTranslation( xFrom );

        const Vector3 xDirection = ( xTo - xFrom ).Normalised();
        const Vector3 xRight = Vector3::Up.Cross( xDirection );
        const Vector3 xUp = xDirection.Cross( xRight ).Normalised();

        const Matrix3 xRotation( xRight, xUp, xDirection );

        xReturnValue.SetUpper3x3( xRotation );

        return xReturnValue;
    }

    static FORCE_INLINE Matrix3 Upper3x3( const Matrix4& xMatrix )
    {
        return Matrix3( xMatrix[ 0 ].xyz(), xMatrix[ 1 ].xyz(), xMatrix[ 2 ].xyz() );
    }

    FORCE_INLINE Matrix3 Upper3x3() const
    {
        return Upper3x3( *this );
    }

    static FORCE_INLINE Matrix4 FastTransformationInverse( const Matrix4& xMatrix )
    {
        Matrix3 xTopLeft = Upper3x3( xMatrix );
        Vector3 xTranslation = xTopLeft * -xMatrix.GetTranslation();

        xTopLeft.Transpose();

        Matrix4 xReturnValue;
        xReturnValue[ 0 ] = Vector4( xTopLeft[ 0 ], 0.0f );
        xReturnValue[ 1 ] = Vector4( xTopLeft[ 1 ], 0.0f );
        xReturnValue[ 2 ] = Vector4( xTopLeft[ 2 ], 0.0f );
        xReturnValue[ 3 ] = Vector4( xTranslation );

        return xReturnValue;
    }

    FORCE_INLINE Matrix4 FastTransformationInverse() const
    {
        return FastTransformationInverse( *this );
    }

    static FORCE_INLINE Matrix4 AxisAngleRotation( const Vector3& xAxis, const float fAngle )
    {
        if( fAngle == 0.0f )
        {
            return Identity;
        }

        // SE - TODO: this can be optimised a load...
        const float fXSquared = xAxis[ 0 ] * xAxis[ 0 ];
        const float fYSquared = xAxis[ 1 ] * xAxis[ 1 ];
        const float fZSquared = xAxis[ 2 ] * xAxis[ 2 ];
        const float fXY = xAxis[ 0 ] * xAxis[ 1 ];
        const float fYZ = xAxis[ 1 ] * xAxis[ 2 ];
        const float fZX = xAxis[ 2 ] * xAxis[ 0 ];
        const float fC = PDE::Cos( fAngle );
        const float fS = PDE::Sin( fAngle );

        // SE - TODO: test - nicked from GLToy...
        return Matrix4(
                            Vector4( fXSquared + ( 1.0f - fXSquared ) * fC,     fXY * ( 1.0f - fC ) - xAxis[ 2 ] * fS,       fZX * ( 1.0f - fC ) + xAxis[ 1 ] * fS, 0.0f ),

                            Vector4( fXY * ( 1.0f - fC ) + xAxis[ 2 ] * fS,     fYSquared + ( 1.0f - fYSquared ) * fC,       fYZ * ( 1.0f - fC ) - xAxis[ 0 ] * fS, 0.0f ),
                              
                            Vector4( fZX * ( 1.0f - fC ) - xAxis[ 1 ] * fS,     fYZ * ( 1.0f - fC ) + xAxis[ 0 ] * fS,       fZSquared + ( 1.0f - fZSquared ) * fC, 0.0f ),
                              
                            Vector4( 0.0f, 0.0f, 0.0f, 1.0f ) );
    }

	static FORCE_INLINE Vector3 RotateAxisAngle( const Vector3& xPosition, const Vector3& xAxis, const float fAngle )
	{
		return AxisAngleRotation( xAxis, fAngle ).Upper3x3() * xPosition;
	}

    float Determinant() const
    {
        return
            maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ] -
            maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ] -
            maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ] +
            maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ] +
            maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ] -
            maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ] -
            maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ] +
            maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ] +
            maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ] -
            maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ] -
            maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ] +
            maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ] +
            maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ] -
            maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ] -
            maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ] +
            maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ] +
            maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ] -
            maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ] -
            maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ] +
            maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ] +
            maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ] -
            maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ] -
            maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ] +
            maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ];
    }

    // SE: jesus wept...
    Matrix4 Inverse() const
    {
        const float fDet = Determinant();
        const Matrix4 xRet(
            Vector4(
                    - maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    + maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    - maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ]
                    + maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ]
                    - maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ]
                    + maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ],
                    
                    + maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    - maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    + maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ]
                    - maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ]
                    + maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ]
                    - maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ],

                    - maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    + maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    - maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    + maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    - maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ]
                    + maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ],

                    + maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    - maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ]
                    + maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    - maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ]
                    + maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ]
                    - maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ] ),
           Vector4(
                   + maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ]
                   - maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ],

                   - maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 2 ][ 3 ]
                   + maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 3 ][ 3 ],

                   + maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 3 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 3 ][ 3 ],
                   
                   - maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 2 ] * maComponents[ 2 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 2 ] * maComponents[ 2 ][ 3 ] ),
           Vector4(
                   - maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 3 ]
                   + maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 3 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 3 ],

                   + maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 3 ]
                   - maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 3 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 3 ],

                   - maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 3 ],

                   + maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 3 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 3 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 3 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 3 ] ),
           Vector4(
                   + maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ]
                   - maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ],

                   - maComponents[ 3 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 2 ][ 2 ]
                   + maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ]
                   - maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 3 ][ 2 ],
                   
                   + maComponents[ 3 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 3 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   - maComponents[ 3 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 3 ][ 2 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 3 ][ 2 ],
                   
                   - maComponents[ 2 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   + maComponents[ 1 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 0 ][ 2 ]
                   - maComponents[ 0 ][ 0 ] * maComponents[ 2 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   + maComponents[ 2 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 1 ][ 2 ]
                   - maComponents[ 1 ][ 0 ] * maComponents[ 0 ][ 1 ] * maComponents[ 2 ][ 2 ]
                   + maComponents[ 0 ][ 0 ] * maComponents[ 1 ][ 1 ] * maComponents[ 2 ][ 2 ] ) );
                           
        return ( fDet == 0.0f ) ? Matrix4::Zero : ( xRet / fDet );
    }
};

}

#endif
