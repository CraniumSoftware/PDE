// Copyright (c) 2013 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#ifndef CPU_H
#define CPU_H

#include "Compiler/Compiler.h"

#if COMPILER_MS

#ifdef _M_ARM
#define CPU_ARMV7 ( 1 )
#else
#define CPU_ARMV7 ( 0 )
#endif

#ifdef _M_X64
#define CPU_X64 ( 1 )
#else
#define CPU_X64 ( 0 )
#endif

#ifdef _M_IX86
#define CPU_X86 ( 1 )
#else
#define CPU_X86 ( 0 )
#endif

#define CPU_ARM64 ( 0 )
#define CPU_MIPS ( 0 )

#elif COMPILER_GCC

#ifdef __arm__
#if __LP64__
#define CPU_ARM64 ( 1 )
#define CPU_ARMV7 ( 0 )
#else
#define CPU_ARM64 ( 0 )
#define CPU_ARMV7 ( 1 )
#endif
#else
#define CPU_ARM64 ( 0 )
#define CPU_ARMV7 ( 0 )
#endif

#ifdef __x86_64__
#define CPU_X64 ( 1 )
#else
#define CPU_X64 ( 0 )
#endif

#ifdef __i386__
#define CPU_X86 ( 1 )
#else
#define CPU_X86 ( 0 )
#endif

#ifdef __mips__
#define CPU_MIPS ( 1 )
#else
#define CPU_MIPS ( 0 )
#endif

#else

#define CPU_ARMV7 ( 0 )
#define CPU_ARM64 ( 0 )
#define CPU_X86 ( 1 )
#define CPU_X64 ( 0 )
#define CPU_MIPS ( 0 )

#endif

#define CPU_32BIT ( !( CPU_X64 ) && !( CPU_ARM64 ) )
#define CPU_64BIT ( ( CPU_X64 ) || ( CPU_ARM64 ) )

#endif
