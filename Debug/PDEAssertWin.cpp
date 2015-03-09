// Copyright (c) 2013, 2015 Cranium Software

// ... but permission given for use in this project in accordance
// with the license of this project

#include "PDEAssert.h"

#if WINRT || WP

#include <Windows.h>

#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
extern "C" HMODULE __stdcall GetModuleHandleW( const wchar_t* const lpModuleName );
#endif

#else

#include <windows.h>

#endif

template< class T >
static inline T GetWin32Function( const wchar_t* const moduleName, const char* const functionName )
{
	const HMODULE moduleHandle = GetModuleHandleW( moduleName );
	if( moduleHandle )
	{
		return reinterpret_cast< T >( GetProcAddress( moduleHandle, functionName ) );
	}
	else
	{
		return NULL;
	}
}

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

// SE - NOTE: this assert dialog uses Win32 APIs which are forbidden under WinRT to work...

// uses MessageBoxW, with a hook on activation to change the text on the buttons

static HHOOK s_hookHandle = NULL;

static int __stdcall CBTHook( const int code, const int firstParameter, const int secondParameter )
{
	static int ( __stdcall *GetDlgItem )( const HWND hWnd, const int nDlgItem ) =
		GetWin32Function<
		int ( __stdcall * )( const HWND, const int )
		>( L"user32.dll", "GetDlgItem" );
	static int ( __stdcall *SetDlgItemText )( const HWND hWnd, const int nDlgItem, const char* const lpCaption ) =
		GetWin32Function<
		int ( __stdcall * )( const HWND, const int, const char* const )
		>( L"user32.dll", "SetDlgItemTextA" );
	static int ( __stdcall *CallNextHookEx )( const HHOOK hookHandle, const int code, const int firstParameter, const int secondParameter ) =
		GetWin32Function<
		int ( __stdcall * )( const HHOOK, const int, const int, const int )
		>( L"user32.dll", "CallNextHookEx" );
	static int ( __stdcall *UnhookWindowsHookEx )( const HHOOK hookHandle ) =
		GetWin32Function<
		int ( __stdcall * )( const HHOOK )
		>( L"user32.dll", "UnhookWindowsHookEx" );

	const HWND dialogHandle = reinterpret_cast< HWND >( firstParameter );

	if( code == 5/*HCBT_ACTIVATE*/ )
	{
		if( GetDlgItem( dialogHandle, IDABORT ) )
		{
			SetDlgItemText( dialogHandle, IDABORT, "Break" );
		}

		if( GetDlgItem( dialogHandle, IDRETRY ) )
		{
			SetDlgItemText( dialogHandle, IDRETRY, "Ignore Once" );
		}

		if( GetDlgItem( dialogHandle, IDIGNORE ) )
		{
			SetDlgItemText( dialogHandle, IDIGNORE, "Ignore Always" );
		}

		UnhookWindowsHookEx( s_hookHandle );
	}
	else
	{
		CallNextHookEx( s_hookHandle, code, firstParameter, secondParameter );
	}

	return 0;
}


static FORCE_INLINE int AssertMessageBox( const wchar_t* const lpText, const wchar_t* const lpCaption )
{
	typedef int ( __stdcall *HookFunction )( const int, const int, const int );

	static HHOOK ( __stdcall *SetWindowsHookEx )( const int idHook, HookFunction lpfn, const HINSTANCE hMod, const unsigned int dwThreadId ) =
		GetWin32Function<
		HHOOK ( __stdcall * )( const int, HookFunction, const HINSTANCE, const unsigned int )
		>( L"user32.dll", "SetWindowsHookExW" );

	static int ( __stdcall *MessageBox )( const HWND hWnd, const wchar_t* const lpText, const wchar_t* const lpCaption, const unsigned int uType ) =
		GetWin32Function<
		int ( __stdcall * )( const HWND, const wchar_t* const, const wchar_t* const, const unsigned int )
		>( L"user32.dll", "MessageBoxW" );

	s_hookHandle = SetWindowsHookEx( 5/*WH_CBT*/, CBTHook, NULL, GetCurrentThreadId() );

	return MessageBox( NULL, lpText, lpCaption, 2/*MB_ABORTRETRYIGNORE*/ | 0x1000/*MB_SYSTEMMODAL*/ | 0x10000/*MB_SETFOREGROUND*/ );
}

namespace Debug
{

bool PDEAssertImplementation(
	bool& skip,
	const char* const file, const int line, const char* const funcsig,
	const char* const conditionString, const char* const formatString, ... )
{
	static LPCRITICAL_SECTION pCriticalSection = NULL;
	static CRITICAL_SECTION criticalSection;
	if( !pCriticalSection )
	{
		pCriticalSection = &criticalSection;
		InitializeCriticalSectionEx( pCriticalSection, 30, 0 );
	}

	EnterCriticalSection( pCriticalSection );

	static char formatBuffer[ 1024 ];
	static char messageBuffer[ 1024 ];
	static wchar_t finalBuffer[ 2048 ];

	sprintf_s( messageBuffer, "Assertion failed: %s\r\n\r\nFile %s, line %d\r\n\r\nFunction %s", conditionString, file, line, funcsig );

	va_list args;
	va_start( args, formatString );
	vsprintf_s( formatBuffer, formatString, args );
	va_end( args );

	swprintf_s( finalBuffer, L"%S\r\n\r\n%S", messageBuffer, formatBuffer );

	switch( AssertMessageBox( finalBuffer, L"Assertion failed!" ) )
	{
	case IDABORT:
		LeaveCriticalSection( pCriticalSection );
		return true;
	case IDIGNORE: // SE - no break due to intentional fall-through
		skip = true;
	case IDRETRY:
		break;
	}

	LeaveCriticalSection( pCriticalSection );

	return false;
}

}
