#pragma once

#ifdef _WIN32

typedef signed char       int8_t;
typedef unsigned char     uint8_t;
typedef signed char       int_least8_t;
typedef unsigned char     uint_least8_t;
typedef signed char       int_fast8_t;
typedef unsigned char     uint_fast8_t;

typedef signed short      int16_t;
typedef unsigned short    uint16_t;
typedef signed short      int_least16_t;
typedef unsigned short    uint_least16_t;
typedef signed short      int_fast16_t;
typedef unsigned short    uint_fast16_t;

typedef signed int        int32_t;
typedef unsigned int      uint32_t;
typedef signed int        int_least32_t;
typedef unsigned int      uint_least32_t;
typedef signed int        int_fast32_t;
typedef unsigned int      uint_fast32_t;

typedef signed __int64    int64_t;
typedef unsigned __int64  uint64_t;
typedef signed __int64    int_least64_t;
typedef unsigned __int64  uint_least64_t;
typedef signed __int64    int_fast64_t;
typedef unsigned __int64  uint_fast64_t;

#if _INTEGRAL_MAX_BITS >= 128
typedef signed __int128   int128_t;
typedef unsigned __int128 uint128_t;
typedef signed __int128   intmax_t;
typedef unsigned __int128 uintmax_t;
#else
typedef signed __int64    intmax_t;
typedef unsigned __int64  uintmax_t;
#endif

typedef signed int        intptr_t;
typedef unsigned int      uintptr_t;

#endif

