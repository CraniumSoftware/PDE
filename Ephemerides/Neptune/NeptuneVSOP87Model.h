#ifndef NEPTUNE_VSOP87_ORBIT_H
#define NEPTUNE_VSOP87_ORBIT_H

#include "Ephemerides/VSOP87Orbit.h" 

class NeptuneVSOP87EOrbitalEphemeris
: public VSOP87EOrbitalEphemeris
{

public:

    NeptuneVSOP87EOrbitalEphemeris();

private:

    DECLARE_TERMS_XYZ4;

};

#endif
