// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef BREAKPOINT_H
#define BREAKPOINT_H

#include "Compiler/Compiler.h"

#if ( WIN ) || defined( _WIN32 )

#define Breakpoint() __debugbreak()

#elif ( ANDROID ) || ( IOS ) || ( OSX )

// SE - TODO: work out why hardware breakpoints are so inconsistent for iOS

#if __OBJC__
#include <signal.h>
#else
#include <csignal>
#endif

#define Breakpoint() do { raise( SIGTRAP ); } while( false )

#else

#include <csignal>

#define Breakpoint() do { raise( SIGTRAP ); } while( false )

#endif

#endif
