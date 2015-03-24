// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PDE_TRACE_H
#define PDE_TRACE_H

#include "../Compiler/Compiler.h"

#if COMPILER_MS // Microsoft compiler has to be different...

	#define PDE_DEBUG_TRACE( szTag, szFormatString, ... ) \
		PDE_DEBUG_TRACE_LEVEL( 0, szTag, szFormatString, __VA_ARGS__ );
	#define PDE_DEBUG_WARNING( szTag, szFormatString, ... ) \
		PDE_DEBUG_TRACE_LEVEL( 1, szTag, szFormatString, __VA_ARGS__ );
	#define PDE_DEBUG_ERROR( szTag, szFormatString, ... ) \
		PDE_DEBUG_TRACE_LEVEL( 2, szTag, szFormatString, __VA_ARGS__ );

#else

	#define PDE_DEBUG_TRACE( szTag, szFormatString, args... ) \
		PDE_DEBUG_TRACE_LEVEL( 0, szTag, szFormatString, ## args );
	#define PDE_DEBUG_WARNING( szTag, szFormatString, args... ) \
		PDE_DEBUG_TRACE_LEVEL( 1, szTag, szFormatString, ## args );
	#define PDE_DEBUG_ERROR( szTag, szFormatString, args... ) \
		PDE_DEBUG_TRACE_LEVEL( 2, szTag, szFormatString, ## args );

#endif

#if !DEBUG

	#if COMPILER_MS // Microsoft compiler has to be different...

		#define PDE_DEBUG_TRACE_LEVEL( level, szTag, szFormatString, ... )

	#else

		#define PDE_DEBUG_TRACE_LEVEL( level, szTag, szFormatString, args... )

	#endif

#else

	#if COMPILER_MS // Microsoft compiler has to be different...

		#define PDE_DEBUG_TRACE_LEVEL( level, szTag, szFormatString, ... ) \
			PDETraceImplementation( level, szTag, szFormatString, __VA_ARGS__ );

	#else

		#define PDE_DEBUG_TRACE_LEVEL( level, szTag, szFormatString, args... ) \
			PDETraceImplementation( level, szTag, szFormatString, ## args );

	#endif

#endif

#ifdef __cplusplus
extern "C"
#endif
void PDETraceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... );

#define DEBUG_MARKER PDE_DEBUG_TRACE( "Debug", "line %d in %s", __LINE__, __FILE__ )

#endif
