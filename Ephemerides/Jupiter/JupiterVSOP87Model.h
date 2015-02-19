#ifndef JUPITER_VSOP87_ORBIT_H
#define JUPITER_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h"

class JupiterVSOP87OrbitalEphemeris
: public VSOP87OrbitalEphemeris
{

public:

	JupiterVSOP87OrbitalEphemeris();

private:

	static const VSOP87Term kaxL0[];
	static const VSOP87Term kaxL1[];
	static const VSOP87Term kaxL2[];
	static const VSOP87Term kaxL3[];
	static const VSOP87Term kaxL4[];
	static const VSOP87Term kaxL5[];

	static const VSOP87Term kaxB0[];
	static const VSOP87Term kaxB1[];
	static const VSOP87Term kaxB2[];
	static const VSOP87Term kaxB3[];
	static const VSOP87Term kaxB4[];
	static const VSOP87Term kaxB5[];

	static const VSOP87Term kaxR0[];
	static const VSOP87Term kaxR1[];
	static const VSOP87Term kaxR2[];
	static const VSOP87Term kaxR3[];
	static const VSOP87Term kaxR4[];
	static const VSOP87Term kaxR5[];

};

#endif
