#ifndef URANUS_VSOP87_ORBIT_H
#define URANUS_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class UranusVSOP87DOrbitalEphemeris
: public VSOP87DOrbitalEphemeris
{

public:

	UranusVSOP87DOrbitalEphemeris();

private:

	DECLARE_TERMS_LBR4;

};

#endif
