#ifndef JUPITER_VSOP87_ORBIT_H
#define JUPITER_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class JupiterVSOP87DOrbitalEphemeris
: public VSOP87DOrbitalEphemeris
{

public:

	JupiterVSOP87DOrbitalEphemeris();

private:

	DECLARE_TERMS_LBR5;

};

#endif
