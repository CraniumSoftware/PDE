#ifndef SATURN_VSOP87_ORBIT_H
#define SATURN_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class SaturnVSOP87OrbitalEphemeris
: public VSOP87OrbitalEphemeris
{

public:

	SaturnVSOP87OrbitalEphemeris();

private:

	DECLARE_TERMS_LBR5;

};

#endif
