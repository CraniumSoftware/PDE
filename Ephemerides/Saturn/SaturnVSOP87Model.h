#ifndef SATURN_VSOP87_ORBIT_H
#define SATURN_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class SaturnVSOP87DOrbitalEphemeris
: public VSOP87DOrbitalEphemeris
{

public:

	SaturnVSOP87DOrbitalEphemeris();

private:

	DECLARE_TERMS_LBR5;

};

#endif
