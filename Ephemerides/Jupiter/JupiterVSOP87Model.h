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

class JupiterVSOP87EOrbitalEphemeris
: public VSOP87EOrbitalEphemeris
{

public:

    JupiterVSOP87EOrbitalEphemeris();

private:

    DECLARE_TERMS_XYZ5;

};

#endif
