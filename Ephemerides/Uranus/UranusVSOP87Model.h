#ifndef URANUS_VSOP87_ORBIT_H
#define URANUS_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class UranusVSOP87OrbitalEphemeris
: public VSOP87OrbitalEphemeris
{

public:

	UranusVSOP87OrbitalEphemeris();

private:

	DECLARE_TERMS_LBR4;

};

#endif
