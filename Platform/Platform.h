// Copyright (c) 2013-2014 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef PLATFORM_H
#define PLATFORM_H

// SE: thse don't seem to work as i intend :/
#if WIN
#pragma warning( disable : 4451 )
#pragma warning( disable : 4714 )
#endif

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
