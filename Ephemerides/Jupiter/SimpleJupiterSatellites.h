#ifndef SIMPLE_JUPITER_SATELLITES_H
#define SIMPLE_JUPITER_SATELLITES_H

#include "Ephemerides/KeplerOrbit.h"

#define DECLARE_JOVICENTRIC_KEPLER_MODEL( name ) \
    class name##KeplerOrbitalEphemeris \
    : public KeplerOrbitalEphemeris \
    { \
        friend class name##PrecessingOrbitalEphemeris; \
    public: \
        name##KeplerOrbitalEphemeris() : KeplerOrbitalEphemeris( kxElements ) {} \
    protected: \
        static const KeplerElements kxElements; \
    }

DECLARE_JOVICENTRIC_KEPLER_MODEL( Metis );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Adrastea );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Amalthea );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Thebe );

DECLARE_JOVICENTRIC_KEPLER_MODEL( Io );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Europa );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Ganymede );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Callisto );

DECLARE_JOVICENTRIC_KEPLER_MODEL( Leda );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Himalia );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Elara );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Lysithea );

DECLARE_JOVICENTRIC_KEPLER_MODEL( Ananke );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Carme );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Pasiphae );
DECLARE_JOVICENTRIC_KEPLER_MODEL( Sinope );

/*
 S/1975 J 1      45.5  205.2  237.4  .191  .049  130.07 14.5   8   1975-2001
 J13 (Leda)      26.7  249.0  217.1  .147  .074  238.5  13.5  15
 J6 (Himalia)    30.2   64.2  321.2  .166  .076  247.9d  8.1 180
 J7 (Elara)      28.9  112.8  130.0  .221  .078  259.8d 10.0  75
 J10 (Lysithea)  27.8   22.2   28.9  .104  .079  260.2d 11.7  35
 S/2000 J 11     28.2  291.7  171.2  .208  .083  284.3d 16.0   4   5 Dec-31 Dec 00
 S/2000 J 5     149.1   35.5  103.4  .240  .136  1.63   15.5   5  23 Nov 00 - 14 Oct 01
 J12 (Ananke)   147.0  331.3   58.7  .252  .140  1.70   12.2  30
 S/2000 J 7     146.4  284.9  200.4  .148  .142  1.73   14.6   7  23 Nov 00 - 20 Dec 01
 S/2000 J 3     150.1  270.8   89.4  .302  .146  1.80   15.2   6  23 Nov 00 - 16 Nov 01
 J11 (Carme)    166.3   74.3  313.5  .263  .148  1.84   11.3  40
 S/2000 J 4     161.1  320.1  355.9  .323  .148  1.84   15.9   4  23 Nov 00 - 17 Nov 01
 S/2000 J 9     163.8  311.4  257.9  .189  .150  1.88   15.2   6  25 Nov 00 - 13 Oct 01
 S/2000 J 6     165.4  147.1  135.7  .257  .153  1.95   15.8   4  23 Nov 00 - 19 Dec 01
 J8 (Pasiphae)  140.0  315.7  173.1  .380  .156  2.00   10.3  50
 S/1999 J 1     143.8  282.8   56.9  .206  .157  2.02   14.2  10   1999-2000
 S/2000 J 10    166.1  140.6  253.4  .168  .158  2.03   15.2   5  26 Nov 00 - 13 Oct 01
 J9 (Sinope)    158.0  269.9  301.1  .370  .158  2.04   11.6  35
 S/2000 J 2     165.8   39.1  230.1  .317  .160  2.08   15.1   6  23 Nov 00 - 14 Oct 01
 S/2000 J 8     150.5  301.0  305.4  .567  .162  2.11   14.6   6  25 Nov 00 - 13 Oct 01
 */

#undef DECLARE_JOVICENTRIC_KEPLER_MODEL

#endif
