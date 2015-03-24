// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDEAssert.h"

#include "Debug/Trace.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

namespace Debug
{

bool PDEAssertImplementation(
	bool& skip,
	const char* const file, const int line, const char* const funcsig,
	const char* const conditionString, const char* const formatString, ... )
{
	UNUSED( skip );
	static char formatBuffer[ 1024 ];
	static char messageBuffer[ 1024 ];
	static char finalBuffer[ 2048 ];

	sprintf( messageBuffer, "Assertion failed: %s\r\n\r\nFile %s, line %d\r\n\r\nFunction %s", conditionString, file, line, funcsig );

	va_list args;
	va_start( args, formatString );
	vsprintf( formatBuffer, formatString, args );
	va_end( args );

	sprintf( finalBuffer, "%s\r\n\r\n%s", messageBuffer, formatBuffer );

	debugError( "Debug", "%s : %s", messageBuffer, formatBuffer );

	/*
	switch( AssertMessageBox( finalBuffer, L"Assertion failed!" ) )
	{
	case IDABORT:
		return true;
	case IDIGNORE:
		skip = true;
	case IDRETRY:
		break;
	}
	 */

	return false;
}

}
