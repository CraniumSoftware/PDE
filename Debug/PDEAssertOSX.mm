// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDEAssert.h"

#include "Debug/PDETrace.h"

#include <Foundation/Foundation.h>

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
	static char formatBuffer[ 1024 ];
	static char messageBuffer[ 1024 ];
	static char finalBuffer[ 2048 ];

	sprintf( messageBuffer, "Assertion failed: %s\r\n\r\nFile %s, line %d\r\n\r\nFunction %s", conditionString, file, line, funcsig );

	va_list args;
	va_start( args, formatString );
	vsprintf( formatBuffer, formatString, args );
	va_end( args );

	sprintf( finalBuffer, "%s\r\n\r\n%s", messageBuffer, formatBuffer );

	PDE_DEBUG_ERROR( "Debug", "%s : %s", messageBuffer, formatBuffer );
    
    CFStringRef xHeader = CFSTR( "Assertion failed!" );
    CFStringRef xMessage = CFStringCreateWithCString( 0, finalBuffer, NSUTF8StringEncoding );
        
    CFOptionFlags result;
    CFUserNotificationDisplayAlert(
        0,
        kCFUserNotificationNoteAlertLevel,
        NULL, NULL, NULL,
        xHeader, xMessage,
        CFSTR( "Break" ),
        CFSTR( "Ignore Once" ),
        CFSTR( "Ignore Always" ),
        &result );
    
    //Clean up the strings
    CFRelease( xHeader );
    CFRelease( xMessage );
    
    //Convert the result
    if( result == kCFUserNotificationDefaultResponse )
    {
        return true;
    }
    else if( result == kCFUserNotificationOtherResponse )
    {
        skip = true;
    }
//    else if( result == kCFUserNotificationAlternateResponse )
//    {
//    }
//    else
//    {
//        // ...
//    }

	return false;
}

}
