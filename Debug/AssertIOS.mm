// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "Assert.h"

#include "Debug/Trace.h"
#include "Thread/ThreadingPrimitives.h"

#include <Foundation/Foundation.h>

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

// nasty little bit of Objective-C to satisfy super heavyweight and gold plated OS interface...

#import <UIKit/UIKit.h>

@class ViewController;

@interface NastyButtonDelegate : UIResponder <UIAlertViewDelegate>
{
    bool mbSkip;
    bool mbBreak;
    volatile bool mbDone;
}

-(id)init;
-(bool)getShouldBreak;
-(bool)getShouldSkip;
-(bool)isDone;

@end

@implementation NastyButtonDelegate

-(id)init
{
    if( self = [super init] )
    {
        mbSkip = false;
        mbBreak = false;
        mbDone = false;
    }

    return self;
}
-(bool)getShouldBreak
{
    return mbBreak;
}

-(bool)getShouldSkip
{
    return mbSkip;
}

-(bool)isDone
{
    return mbDone;
}

-(void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    UNUSED( alertView );
    
    mbBreak = ( buttonIndex == 0 );
    mbSkip = ( buttonIndex == 2 );
    
    LWSync();
    mbDone = true;
}

@end

namespace Debug
{

bool assertImplementation(
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
    
//    NSString* pxMessageString = [NSString stringWithCString: finalBuffer encoding:NSASCIIStringEncoding];
//    NastyButtonDelegate* pxDelegate = [[NastyButtonDelegate alloc] init];
//    UIAlertView* pxAlertView = [[UIAlertView alloc] initWithTitle:@"Assertion failed!"
//        message:pxMessageString delegate:pxDelegate
//        cancelButtonTitle:@"Break" otherButtonTitles:@"Ignore Once", @"Ignore Always", nil];
//    [pxAlertView show];
//    
//    while( ![pxDelegate isDone] )
//    {
//        Yield();
//        UIEvent* event = [UIApplication nextEventMatchingMask:UIAnyEventMask
//            untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
//        if (event) {
//            [NSApp sendEvent:event];
//            [NSApp updateWindows];
//        }
//    }
//    
//    if( [pxDelegate getShouldBreak] )
//    {
//        return true;
//    }
//    else if( [pxDelegate getShouldSkip] )
//    {
//        skip = true;
//    }
//    
//    // we need to stall on that dialog being done with :/
//    
//    [pxAlertView release];
//    [pxMessageString release];
//    [pxDelegate release];

	return false;
}

}
