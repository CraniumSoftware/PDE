#include "Astrometry.h"

#include "Maths/PDEMaths.h"
#include "Maths/PDEMatrix.h"
#include "Maths/DPVector.h"

namespace PDE
{

Vector3 RADecToDirection( const double dRA, const double dDeclination )
{
    const Vector3 xEquatorial(
        static_cast< float >( PDE::Cos( dRA ) * PDE::Cos( dDeclination ) ),
        static_cast< float >( PDE::Sin( dRA ) * PDE::Cos( dDeclination ) ),
        static_cast< float >( PDE::Sin( dDeclination ) ) );

    // rotate it by the obliquity of the ecliptic at J2000.0...
    static const float kfObliquity = PDE::Deg2Rad( 23.4392794f ); // 4444444444....
    return Matrix4::RotateAxisAngle( xEquatorial, Vector3::Left, kfObliquity );
}

}
