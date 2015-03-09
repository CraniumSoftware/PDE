// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDETrace.h"

#include <cstdarg>
#include <cstdlib>

#include <android/log.h>

extern "C" void PDETraceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... )
{
	static char szBuffer[ 1024 ];
	va_list xArgs;
	va_start( xArgs, szFormatString );
	vsprintf( szBuffer, szFormatString, xArgs );
	va_end( xArgs );
	
	android_LogPriority level = ANDROID_LOG_INFO;
	switch( iLevel )
	{
		case 0: level = ANDROID_LOG_INFO; break;
		case 1: level = ANDROID_LOG_WARN; break;
		case 2: level = ANDROID_LOG_ERROR; break;
	}

	__android_log_print( level, szTag, "%s", szBuffer );
}
