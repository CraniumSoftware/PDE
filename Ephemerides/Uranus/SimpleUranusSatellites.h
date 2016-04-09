#ifndef SIMPLE_URANUS_SATELLITES_H
#define SIMPLE_URANUS_SATELLITES_H

#include "Ephemerides/KeplerOrbit.h"

#define DECLARE_URANOCENTRIC_KEPLER_MODEL( name ) \
class name##KeplerOrbitalEphemeris \
: public KeplerOrbitalEphemeris \
{ \
friend class name##PrecessingOrbitalEphemeris; \
public: \
name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
protected: \
static const KeplerElements kxElements; \
}

DECLARE_URANOCENTRIC_KEPLER_MODEL( Miranda );
DECLARE_URANOCENTRIC_KEPLER_MODEL( Ariel );
DECLARE_URANOCENTRIC_KEPLER_MODEL( Umbriel );
DECLARE_URANOCENTRIC_KEPLER_MODEL( Oberon );
DECLARE_URANOCENTRIC_KEPLER_MODEL( Titania );

#undef DECLARE_URANOCENTRIC_KEPLER_MODEL

#endif
