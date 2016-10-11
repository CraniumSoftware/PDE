// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PDE_TRACE_H
#define PDE_TRACE_H

#include "../Compiler/Compiler.h"

#define PDE_DEBUG_TRACE( szTag, ... ) \
	PDE_DEBUG_TRACE_LEVEL( 0, szTag,  __VA_ARGS__ );
#define PDE_DEBUG_WARNING( szTag, ... ) \
	PDE_DEBUG_TRACE_LEVEL( 1, szTag,  __VA_ARGS__ );
#define PDE_DEBUG_ERROR( szTag, ... ) \
	PDE_DEBUG_TRACE_LEVEL( 2, szTag,  __VA_ARGS__ );

#if !DEBUG

	#define PDE_DEBUG_TRACE_LEVEL( level, szTag, ... )


#else

	#define PDE_DEBUG_TRACE_LEVEL( level, szTag, ... ) \
		PDETraceImplementation( level, szTag, __VA_ARGS__ );

#endif

#ifdef __cplusplus
extern "C"
#endif
void PDETraceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... );

#define DEBUG_MARKER PDE_DEBUG_TRACE( "Debug", "line %d in %s", __LINE__, __FILE__ )

#endif
