// Copyright (c) 2013-2014, 2016 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PLATFORM_H
#define PLATFORM_H

#if !defined( WINRT )
#define WINRT ( 0 )
#endif

#if !defined( WP )
#define WP ( 0 )
#endif

#if !defined( IOS )
#define IOS ( 0 )
#endif

#if !defined ( APPLE_WATCH )
#define APPLE_WATCH ( 0 )
#endif

#if !WINRT && !WP && ( defined( _WIN32 ) || defined( WIN32 ) ) && !defined( WIN )
#define WIN ( 1 )
#elif !defined( WIN )
#define WIN ( 0 )
#endif

#if ( ( defined( __ANDROID__ ) || defined( __ANDROID_API__ ) ) && !defined( ANDROID ) )
#define ANDROID ( 1 )
#elif !defined( ANDROID )
#define ANDROID ( 0 )
#endif

#if ( ( defined( __linux__ ) ) && !defined( LINUX ) )
#define LINUX ( 1 )
#elif !defined( LINUX )
#define LINUX ( 0 )
#endif

#if ( ( defined( __APPLE__ ) && defined( __MACH__ ) ) && !defined( OSX ) && !defined( APPLE_WATCH ) )
#define OSX ( 1 )
#elif !defined( OSX )
#define OSX ( 0 )
#endif

// SE - TODO: really?
#if !( defined( WP ) )
#if defined( WINAPI_FAMILY ) && ( WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP )
#define WP ( 1 )
#else
#define WP ( 0 )
#endif
#endif

#if WIN

// windows specifics...

#pragma warning( disable : 4451 ) // some windows universal bullshit about marshalling and refs
#pragma warning( disable : 4514 ) // unused inline function
#pragma warning( disable : 4626 ) // operator = was implicitly deleted (in two minds about this, but its a nuisance, and we know about this...)
#pragma warning( disable : 4710 ) // function marked inline was not inlined
#pragma warning( disable : 4714 ) // function marked for forced inlining was not inlined
#pragma warning( disable : 4820 ) // padding for C struct layout rules was added (how the fuck is that a warning?!?)
#pragma warning( disable : 5027 ) // the move flavour of operator = was implicitly deleted (in two minds about this, but its a nuisance, and we know about this...)

// make sure we build for windows 7. annoying, but necessary to do this and make sure its included before any windows.h etc.
// constants from MSDN:
//#define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0
//#define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000
//#define _WIN32_WINNT_WINXP                  0x0501 // Windows XP
//#define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003
//#define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista
//#define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista
//#define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008
//#define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista
//#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7
//#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8
//#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1
//#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10
//#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10

#define WINVER				0x0601
#define _WIN32_WINNT		0x0601
#endif

// SE: not sure this is the best place for this...
#if !( defined( HACKILY_REMOVE_STB_WARNINGS ) )
#define HACKILY_REMOVE_STB_WARNINGS ( 1 ) // should that be zero? i don't like warnings from third party stuff...
#endif

#if WIN

static const char* const kszPlatformName = "Windows Desktop 32-bit";

#elif WINRT

static const char* const kszPlatformName = "Windows 8 Metro";

#elif IOS

static const char* const kszPlatformName = "iOS";

#elif OSX

static const char* const kszPlatformName = "MacOS X";

#elif ANDROID

static const char* const kszPlatformName = "Android";

#elif LINUX

static const char* const kszPlatformName = "Linux";

#elif WP

static const char* const kszPlatformName = "Windows Phone";

#elif APPLE_WATCH

static const char* const kszPlatformName = "Apple Watch";

#else

#error Unrecognised platform!

#endif

#endif
