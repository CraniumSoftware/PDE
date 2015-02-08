#ifndef J2000_H
#define J2000_h

// SE - TODO: decouple?

#include "Ephemerides/OrbitalEphemeris.h"

// SE - NOTE: the JDTZero is a recent value for the age of the universe with some +/- 30 million years
// the magic numbers there are not entirely random...
// the first makes us have 8008135 on the end of the year number at some point
// the second sets this point by using a julian date close to 2015-Dec-07 15:06:42.42 ... my 0x20th birthday
// this is all very childish, but well within margins for error :)

static const EphemerisFloat JDTZero = -( ( 13.798 * 1000000000.0 + 8135.0 ) * 365.25 - 2457364.1296576 );
static const EphemerisFloat J2000 = 2451545.0;
    
#endif
