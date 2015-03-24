// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDEVector.h"
#include "PDEMatrix.h"
#include "PDEMaths.h"

namespace PDE
{

const Vector3 Vector3::Up( 0.0f, 1.0f, 0.0f );
const Vector3 Vector3::Down( 0.0f, -1.0f, 0.0f );
const Vector3 Vector3::Left( 1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Right( -1.0f, 0.0f, 0.0f );
const Vector3 Vector3::Forward( 0.0f, 0.0f, -1.0f );
const Vector3 Vector3::Backward( 0.0f, 0.0f, 1.0f );

const Vector4 Vector4::White( 1.0f, 1.0f, 1.0f, 1.0f );
const Vector4 Vector4::Black( 0.0f, 0.0f, 0.0f, 1.0f );
const Vector4 Vector4::Transparent( 0.0f, 0.0f, 0.0f, 0.0f );
const Vector4 Vector4::Red( 1.0f, 0.0f, 0.0f, 1.0f );
const Vector4 Vector4::Green( 0.0f, 1.0f, 0.0f, 1.0f );
const Vector4 Vector4::Blue( 0.0f, 0.0f, 1.0f, 1.0f );

/*
Vector3 Vector3::MatrixMultiply( const Matrix3& xMatrix ) const
{
    Vector3 xReturnValue;
    for( int i = 0; i < 3; ++i )
    {
        xReturnValue[ i ] = 0.0f;

        // V_i = V^j M^i_j
        for( int j = 0; j < 3; ++j )
        {
            xReturnValue[ i ] += maComponents[ j ] * xMatrix[ i ][ j ];
        }
    }

    return xReturnValue;
}
*/

Vector3 Vector3::RandomDirection()
{
    return Vector3( PDE::PRNGRange( -1.0f, 1.0f ), PDE::PRNGRange( -1.0f, 1.0f ), PDE::PRNGRange( -1.0f, 1.0f ) );
}

Vector3 Vector3::RandomNormalisedDirection()
{
    return Vector3( PDE::PRNGRange( -1.0f, 1.0f ), PDE::PRNGRange( -1.0f, 1.0f ), PDE::PRNGRange( -1.0f, 1.0f ) ).Normalised();
}

}
