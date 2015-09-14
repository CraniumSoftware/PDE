#ifndef SIMPLE_SATURN_SATELLITES_H
#define SIMPLE_SATURN_SATELLITES_H

#include "Ephemerides/KeplerOrbit.h"

#define DECLARE_CRONOCENTRIC_KEPLER_MODEL( name ) \
class name##KeplerOrbitalEphemeris \
: public KeplerOrbitalEphemeris \
{ \
friend class name##PrecessingOrbitalEphemeris; \
public: \
name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
protected: \
static const KeplerElements kxElements; \
}

DECLARE_CRONOCENTRIC_KEPLER_MODEL( Mimas );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Enceladus );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Tethys );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Dione );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Rhea );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Titan );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Hyperion );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Iapetus );
DECLARE_CRONOCENTRIC_KEPLER_MODEL( Phoebe );

#undef DECLARE_CRONOCENTRIC_KEPLER_MODEL

#endif
