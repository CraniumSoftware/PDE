#include "EarthSimpleRotation.h"

// SE - NOTE: these are fictitious values.
const PDE::Vector3 EarthSimpleRotation::kxRotationAxis = PDE::Vector3( 0.0f, 0.0f, 1.0f );
const PDE::Vector3 EarthSimpleRotation::kxZeroLongitudeLatitudeJ2000 = PDE::Vector3( 1.0f, 0.0f, 0.0f );
const double EarthSimpleRotation::kdPeriod = 24.0;
