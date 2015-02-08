#ifndef DP_VECTOR_H
#define DP_VECTOR_H

// double precision vector types using the Cerebro vector templates...

#include "Maths/Vector.h"

class DPVector2
: public VectorBase< double, 2 >
{

    typedef VectorBase< double, 2 > Base;

public:

    DPVector2( const double x = 0.0, const double y = 0.0 )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
    }

    DPVector2( const Base& xOther )
    {
        maComponents[ 0 ] = xOther[ 0 ];
        maComponents[ 1 ] = xOther[ 1 ];
    }

    double Max() const { return Maths::Max( maComponents[ 0 ], maComponents[ 1 ] ); }
    double Min( ) const { return Maths::Min( maComponents[ 0 ], maComponents[ 1 ] ); }

    DPVector2 xx() const { return DPVector2( maComponents[ 0 ] ); }
    DPVector2 yy() const { return DPVector2( maComponents[ 1 ] ); }
    DPVector2 yx() const { return DPVector2( maComponents[ 1 ], maComponents[ 0 ] ); }

    DPVector2 FastRotate90CCW() const
    {
        return DPVector2( -maComponents[ 1 ], maComponents[ 0 ] );
    }

    DPVector2 FastRotate90CW() const
    {
        return DPVector2( maComponents[ 1 ], -maComponents[ 0 ] );
    }

};

class DPVector3
: public VectorBase< double, 3 >
{

    typedef VectorBase< double, 3 > Base;

public:

    static const Vector3 Up;
    static const Vector3 Down;
    static const Vector3 Forward;
    static const Vector3 Backward;
    static const Vector3 Left;
    static const Vector3 Right;

    DPVector3( const Base& v )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
    }

    DPVector3( const double x = 0.0, const double y = 0.0, const double z = 0.0 )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
        maComponents[ 2 ] = z;
    }

    DPVector3( const Vector2& v, const double z = 0.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
    }

    double Max() const { return Maths::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }
    double Min() const { return Maths::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }

    static DPVector3 FromEllipsoid( const double dLongitude, const double dLatitude, const double dPolar, const double dEquatorial )
    {
        return DPVector3(
            dEquatorial * Maths::Sin( dLatitude ) * Maths::Cos( dLongitude ),
            dEquatorial * Maths::Sin( dLatitude ) * Maths::Sin( dLongitude ),
            dPolar * Maths::Cos( dLatitude ) );
    }

};

class DPVector4
: public VectorBase< double, 4 >
{

    typedef VectorBase< double, 4 > Base;

public:

    static const Vector4 White;
    static const Vector4 Black;
    static const Vector4 Transparent;
    static const Vector4 Red;
    static const Vector4 Green;
    static const Vector4 Blue;

    DPVector4( const Base& v )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
        maComponents[ 3 ] = v[ 3 ];
    }

    DPVector4( const double x = 0.0, const double y = 0.0, const double z = 0.0, const double w = 1.0 )
    {
        maComponents[ 0 ] = x;
        maComponents[ 1 ] = y;
        maComponents[ 2 ] = z;
        maComponents[ 3 ] = w;
    }

    DPVector4( const Vector3& v, const double w = 1.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
        maComponents[ 3 ] = w;
    }

    DPVector4( const Vector2& v, const double z = 0.0, const double w = 1.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
        maComponents[ 3 ] = w;
    }

    double Max() const { return Maths::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }
    double Min() const { return Maths::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }

};

#endif
