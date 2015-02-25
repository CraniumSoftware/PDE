#ifndef SUN_VSOP87_ORBIT_H
#define SUN_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class SunVSOP87EOrbitalEphemeris
: public VSOP87EOrbitalEphemeris
{

public:

    SunVSOP87EOrbitalEphemeris();

private:

    DECLARE_TERMS_XYZ5;

};

#endif
