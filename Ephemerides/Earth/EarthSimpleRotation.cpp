#include "EarthSimpleRotation.h"

#include "Maths/Astrometry.h"

// SE - NOTE: these are fictitious values.
const PDE::Vector3 EarthSimpleRotation::kxRotationAxis = PDE::RADecToDirection( 0.0, PDE::Deg2Rad( 90.0 ) );
const PDE::Vector3 EarthSimpleRotation::kxZeroLongitudeLatitudeJ2000 = PDE::RADecToDirection( 0.0, 0.0 );
const double EarthSimpleRotation::kdPeriod = 24.0;
