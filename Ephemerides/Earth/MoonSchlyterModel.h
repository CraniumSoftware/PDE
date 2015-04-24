#ifndef MOON_SCHLYTER_MODEL_H
#define MOON_SCHLYTER_MODEL_H

// based on work by Paul Schlyter - http://stjarnhimlen.se/

#include "Ephemerides/PerturbedKeplerOrbit.h"

class MoonSchlyterOrbitalEphemeris
: public SpeciallyPerturbedKeplerOrbitalEphemeris< MoonSchlyterOrbitalEphemeris >
{

public:

	MoonSchlyterOrbitalEphemeris()
	: SpeciallyPerturbedKeplerOrbitalEphemeris( kxBaseElements, kxLinearPerturbations )
	{

	}

	EphemerisVector4 Perturb( const EphemerisVector4 xPosition, const double dT ) const;

	static double MeanAnomaly( const double dT )
	{
		return kxBaseElements.MeanAnomaly + kxBaseElements.LongitudeRate * dT;
	}

private:

	static const KeplerElements kxBaseElements;
	static const KeplerElements kxLinearPerturbations;

};

#endif
