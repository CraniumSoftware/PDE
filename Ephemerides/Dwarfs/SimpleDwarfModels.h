#ifndef SIMPLE_DWARF_MODELS_H
#define SIMPLE_DWARF_MODELS_H

#include "Ephemerides/KeplerOrbit.h"
#include "Ephemerides/PrecessingKeplerOrbit.h"

// SE - NOTE: not all of these are really dwarf planets, or it is unknown...
// for instance, Chiron and Chariklo are probably too small to be in hydrostatic
// equilibrium, Vesta is a lumpy mess and most of the TNOs have never been resolved to
// discs...
// ... but all of these are interesting objects for various reasons, so its worth spending
// a bit more time on their positions and properties than the remaining solar system bodies

// SE - TODO: some efficient way to solve the barycentric/heliocentric conversion...

#define DECLARE_HELIOCENTRIC_KEPLER_MODEL( name ) \
class name##KeplerOrbitalEphemeris \
: public KeplerOrbitalEphemeris \
{ \
    friend class name##PrecessingOrbitalEphemeris; \
public: \
	name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
protected: \
	static const KeplerElements kxElements; \
}

#define DECLARE_PRECESSING_HELIOCENTRIC_KEPLER_MODEL( name ) \
class name##PrecessingOrbitalEphemeris \
: public PrecessingKeplerOrbitalEphemeris \
{ \
public: \
	name##PrecessingOrbitalEphemeris() \
	: PrecessingKeplerOrbitalEphemeris( \
		name##KeplerOrbitalEphemeris::kxElements, \
		kdNodalPrecessionAS / ( 365.25 * 3600.0 ), \
		kdApsidalPrecessionAS / ( 365.25 * 3600.0 ) ) \
	{ \
	} \
protected: \
	static const double kdNodalPrecessionAS; \
	static const double kdApsidalPrecessionAS; \
}

DECLARE_HELIOCENTRIC_KEPLER_MODEL( Ceres );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Vesta );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Pallas );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Chiron );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Chariklo );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Pluto );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Eris );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Sedna );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Haumea );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Ixion );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Makemake );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Varuna );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Quaoar );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Salacia );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Orcus );
DECLARE_HELIOCENTRIC_KEPLER_MODEL( Unnamed2007OR10 ); // fucking astronomers...

DECLARE_PRECESSING_HELIOCENTRIC_KEPLER_MODEL( Ceres );

#undef DECLARE_HELIOCENTRIC_KEPLER_MODEL
#undef DECLARE_PRECESSING_HELIOCENTRIC_KEPLER_MODEL

#endif
