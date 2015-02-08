// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef ASSERT_H
#define ASSERT_H

#include <Compiler/Compiler.h>
#include <Debug/Breakpoint.h>

static const bool kbDeprecatedFunctionality = false;

namespace Debug
{

bool assertImplementation(
	bool& skip,
	const char* const file, const int line, const char* const funcsig,
	const char* const conditionString, const char* const formatString, ... );

}

#if DEBUG

#if COMPILER_MS || COMPILER_GCC

// allow debugAssert( false, ... )
#if COMPILER_MS
#pragma warning( disable : 4127 )
#endif

#define debugAssert( condition, ... ) \
	\
	do \
	{ \
		static bool lsSkip = false; \
		if( !( condition ) && !lsSkip \
			&& Debug::assertImplementation( \
				lsSkip, \
				__FILE__, __LINE__, __FUNCSIG__, \
				#condition, __VA_ARGS__ ) ) \
		{ \
			Breakpoint(); \
		} \
	} while( false )

#else

#warning debugAssert macro unimplemented for this compiler!!

#define debugAssert( ... )

#endif

#else

#define debugAssert( ... )

#endif

#endif