#include "ProfileTimer.h"

// SE - for now... just do this dumbly and trust that we have very modern C++
// ... there are platform implementations in Cerebro that I can nick if this
// becomes a genuine problem

#include <chrono>

double GetProfileTimer()
{
    // SE - NOTE: would it have hurt so much to not nest these things to the
    // point where this code is dominated by type names?

    // do not change this with using namespace. that thing is dangerous.

    auto xTime = std::chrono::high_resolution_clock::now();
    auto xDuration = xTime.time_since_epoch();

    const double dNanoseconds = static_cast< double >( std::chrono::duration_cast< std::chrono::nanoseconds >( xDuration ).count() );

    return dNanoseconds / ( 1000.0 * 1000.0 * 1000.0 );
}
