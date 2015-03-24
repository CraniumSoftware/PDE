// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDETrace.h"

#include <cstdarg>
#include <cstdlib>
#include <cstdio>

#include <windows.h>

extern "C" void PDETraceImplementation( const int iLevel, const char* const szTag, const char* const szFormatString, ... )
{
	UNUSED( iLevel );

	static char szBuffer[ 4096 ];
	static wchar_t wszExtraBuffer[ 4096 ];
	va_list xArgs;
	va_start( xArgs, szFormatString );
	vsnprintf( szBuffer, 4096, szFormatString, xArgs );
	va_end( xArgs );

	swprintf( wszExtraBuffer, 4096, L"[%S] %S\n", szTag, szBuffer );

	OutputDebugStringW( wszExtraBuffer );
}
