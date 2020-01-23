#pragma once

/**
* Generic types for most all compilers/platforms.
* Modelled from UnrealEngine's platform agnostic system.
*/
struct GenericPlatformTypes
{
	// Unsigned types.
	typedef unsigned char		uint8;
	typedef unsigned short int	uint16;
	typedef unsigned int		uint32;
	typedef unsigned long long	uint64;

	// Signed types.
	typedef signed char			int8;
	typedef signed short int	int16;
	typedef signed int			int32;
	typedef signed long long	int64;

	// Character types. These are especially useful for dealing with cpprestsdk.
	typedef char				ANSICHAR; // ANSI character, 8-bit fixed-width representation of a 7-bit character.
#if _WIN32
	typedef wchar_t				WIDECHAR; // A wide character, ?-bit fixed-width platform dependent.
#else
	typedef char16_t			WIDECHAR;
#endif
	typedef char8_t				CHAR8;
	typedef char16_t			CHAR16;
	typedef char32_t			CHAR32;
};

// Transfers platform types to global types.
typedef GenericPlatformTypes::uint8		uint8;
typedef GenericPlatformTypes::uint16	uint16;
typedef GenericPlatformTypes::uint32	uint32;
typedef GenericPlatformTypes::uint64	uint64;

typedef GenericPlatformTypes::int8		int8;
typedef GenericPlatformTypes::int16		int16;
typedef GenericPlatformTypes::int32		int32;
typedef GenericPlatformTypes::int64		int64;

typedef GenericPlatformTypes::ANSICHAR	ANSICHAR;
typedef GenericPlatformTypes::WIDECHAR	WIDECHAR;
typedef GenericPlatformTypes::CHAR8		CHAR8;
typedef GenericPlatformTypes::CHAR16	CHAR16;
typedef GenericPlatformTypes::CHAR32	CHAR32;
