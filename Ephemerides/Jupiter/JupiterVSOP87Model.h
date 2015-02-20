#ifndef JUPITER_VSOP87_ORBIT_H
#define JUPITER_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class JupiterVSOP87OrbitalEphemeris
: public VSOP87OrbitalEphemeris
{

public:

	JupiterVSOP87OrbitalEphemeris();

private:

	DECLARE_TERMS_LBR5;

};

#endif
