// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "Trace.h"

#include "Compiler/Compiler.h"

#include <cstdarg>
#include <cstdlib>
#include <cstdio>

// SE - HACK: why is the build system not removing this file?

#if !ANDROID

extern "C" void traceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... )
{
    UNUSED( iLevel );
    static char szBuffer[ 1024 ];
    va_list xArgs;
    va_start( xArgs, szFormatString );
    vsprintf( szBuffer/*, 1024*/, szFormatString, xArgs );
    va_end( xArgs );

    printf( "[%s] %s\n", szTag, szBuffer );
}

#endif
