#ifndef SIMPLE_URANUS_SATELLITES_H
#define SIMPLE_URANUS_SATELLITES_H

#include "Ephemerides/KeplerOrbit.h"

#define DECLARE_NEPTUNOCENTRIC_KEPLER_MODEL( name ) \
class name##KeplerOrbitalEphemeris \
: public KeplerOrbitalEphemeris \
{ \
friend class name##PrecessingOrbitalEphemeris; \
public: \
name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
protected: \
static const KeplerElements kxElements; \
}

DECLARE_NEPTUNOCENTRIC_KEPLER_MODEL( Proteus );
DECLARE_NEPTUNOCENTRIC_KEPLER_MODEL( Larissa );
DECLARE_NEPTUNOCENTRIC_KEPLER_MODEL( Triton );
DECLARE_NEPTUNOCENTRIC_KEPLER_MODEL( Nereid );

#undef DECLARE_URANOCENTRIC_KEPLER_MODEL

#endif
