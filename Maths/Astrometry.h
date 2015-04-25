#ifndef ASTROMETRY_H
#define ASTROMETRY_H

#include "Maths/PDEVector.h"

// SE: a bunch of helpers for some astrometry tasks...

namespace PDE
{

// assumes J2000.0
Vector3 RADecToDirection( const double dRA, const double dDeclination );

}

#endif
