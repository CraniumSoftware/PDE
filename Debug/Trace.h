// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef Engine_Trace_h
#define Engine_Trace_h

#include "../Compiler/Compiler.h"

#if COMPILER_MS // Microsoft compiler has to be different...

	#define debugTrace( szTag, szFormatString, ... ) \
		debugTraceLevel( 0, szTag, szFormatString, __VA_ARGS__ );
	#define debugWarning( szTag, szFormatString, ... ) \
		debugTraceLevel( 1, szTag, szFormatString, __VA_ARGS__ );
	#define debugError( szTag, szFormatString, ... ) \
		debugTraceLevel( 2, szTag, szFormatString, __VA_ARGS__ );

#else

	#define debugTrace( szTag, szFormatString, args... ) \
		debugTraceLevel( 0, szTag, szFormatString, ## args );
	#define debugWarning( szTag, szFormatString, args... ) \
		debugTraceLevel( 1, szTag, szFormatString, ## args );
	#define debugError( szTag, szFormatString, args... ) \
		debugTraceLevel( 2, szTag, szFormatString, ## args );

#endif

#if !DEBUG

	#if COMPILER_MS // Microsoft compiler has to be different...

		#define debugTraceLevel( level, szTag, szFormatString, ... )

	#else

		#define debugTraceLevel( level, szTag, szFormatString, args... )

	#endif

#else

	#if COMPILER_MS // Microsoft compiler has to be different...

		#define debugTraceLevel( level, szTag, szFormatString, ... ) \
			traceImplementation( level, szTag, szFormatString, __VA_ARGS__ );

	#else

		#define debugTraceLevel( level, szTag, szFormatString, args... ) \
			traceImplementation( level, szTag, szFormatString, ## args );

	#endif

#endif

#ifdef __cplusplus
extern "C"
#endif
void traceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... );

#define DEBUG_MARKER debugTrace( "Debug", "line %d in %s", __LINE__, __FILE__ )

#endif
