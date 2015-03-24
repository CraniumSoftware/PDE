#ifndef DP_VECTOR_H
#define DP_VECTOR_H

// double precision vector types using the Cerebro vector templates...

#include "Maths/PDEVector.h"

class DPVector2
: public PDE::VectorBase< double, 2 >
{

    typedef PDE::VectorBase< double, 2 > Base;

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

    double Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ] ); }
    double Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ] ); }

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
: public PDE::VectorBase< double, 3 >
{

    typedef PDE::VectorBase< double, 3 > Base;

public:

    static const DPVector3 Up;
    static const DPVector3 Down;
    static const DPVector3 Forward;
    static const DPVector3 Backward;
    static const DPVector3 Left;
    static const DPVector3 Right;

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

    DPVector3( const DPVector2& v, const double z = 0.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
    }

    double Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }
    double Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ] ); }

    static DPVector3 FromEllipsoid( const double dLongitude, const double dLatitude, const double dPolar, const double dEquatorial )
    {
        return DPVector3(
            dEquatorial * PDE::Sin( dLatitude ) * PDE::Cos( dLongitude ),
            dEquatorial * PDE::Sin( dLatitude ) * PDE::Sin( dLongitude ),
            dPolar * PDE::Cos( dLatitude ) );
    }

};

class DPVector4
: public PDE::VectorBase< double, 4 >
{

    typedef PDE::VectorBase< double, 4 > Base;

public:

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

    DPVector4( const DPVector3& v, const double w = 1.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = v[ 2 ];
        maComponents[ 3 ] = w;
    }

    DPVector4( const DPVector2& v, const double z = 0.0, const double w = 1.0 )
    {
        maComponents[ 0 ] = v[ 0 ];
        maComponents[ 1 ] = v[ 1 ];
        maComponents[ 2 ] = z;
        maComponents[ 3 ] = w;
    }

    double Max() const { return PDE::Max( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }
    double Min() const { return PDE::Min( maComponents[ 0 ], maComponents[ 1 ], maComponents[ 2 ], maComponents[ 3 ] ); }

};

#endif
