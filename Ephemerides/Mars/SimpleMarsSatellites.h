#ifndef SIMPLE_MARS_SATELLITES_H
#define SIMPLE_MARS_SATELLITES_H

#include "Ephemerides/KeplerOrbit.h"

#define DECLARE_AREOCENTRIC_KEPLER_MODEL( name ) \
class name##KeplerOrbitalEphemeris \
: public KeplerOrbitalEphemeris \
{ \
friend class name##PrecessingOrbitalEphemeris; \
public: \
name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
protected: \
static const KeplerElements kxElements; \
}

DECLARE_AREOCENTRIC_KEPLER_MODEL( Phobos );
DECLARE_AREOCENTRIC_KEPLER_MODEL( Deimos );

#undef DECLARE_AREOCENTRIC_KEPLER_MODEL

#endif
