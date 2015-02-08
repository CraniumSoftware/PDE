// Copyright (c) 2013-2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef COMPILER_H
#define COMPILER_H

#include "Platform/Platform.h"

#ifndef TEST
#define TEST ( 0 )
#endif

#ifndef NULL
#if HACKILY_REMOVE_STB_WARNINGS
#define NULL (unsigned long long)( 0 )
#else
#define NULL ( 0 )
#endif
#endif

#if defined( _DEBUG ) && !defined( DEBUG )
#define DEBUG ( 1 )
#elif !defined( DEBUG )
#define DEBUG ( 0 )
#endif

#ifdef _MSC_VER
#define COMPILER_MS ( 1 )
#else
#define COMPILER_MS ( 0 )
#endif

// SE - NOTE: this might actually be one of the Apple clangs
// not sure its worth detecting them both, and what to call the case that works with both...
#ifdef __GNUC__
#define COMPILER_GCC ( 1 )
#else
#define COMPILER_GCC ( 0 )
#endif

#if COMPILER_MS

#define FORCE_INLINE __forceinline

#pragma warning( disable : 4451 )
#pragma warning( disable : 4706 ) // i like assigning in loop conditions...

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define snprintf _snprintf

#elif COMPILER_GCC

#define FORCE_INLINE inline
#define __FUNCSIG__ __PRETTY_FUNCTION__

#define _stricmp strcasecmp

#define _malloca alloca
#define _freea( ... )

#define sprintf_s sprintf
#define vsnprintf_s vsnprintf
#define vswprintf_s vswprintf

#else // if !COMPILER_MS

#define FORCE_INLINE inline

#define _stricmp strcasecmp

#define _malloca alloca
#define _freea( ... )

#endif

#if COMPILER_MS
#define UNUSED( x ) (void)( x )
#else
#define UNUSED( x ) (void)((void*)( &x ))
#endif

#define HIDE_BUILT_IN_COPIES( type ) private: type& operator=( const type& ) { return *this; } type( const type& ) {}

#if !WIN
#define _countof( x ) ((int)( sizeof( x ) / sizeof( x[ 0 ] ) ))
#endif

#endif
