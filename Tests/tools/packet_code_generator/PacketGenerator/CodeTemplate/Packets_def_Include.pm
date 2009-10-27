package CodeTemplate::Packets_def_Include;

use strict;

our $Template = << "CODE_TEMPALTE";

#ifndef _FANNI_{IMPL_PREFIX}Packets_def_H_
#define _FANNI_{IMPL_PREFIX}Packets_def_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_{IMPL_PREFIX}Packets_EXPORTS)
		#define Fanni_{IMPL_PREFIX}Packets_API __declspec(dllexport)
	#else
		#define Fanni_{IMPL_PREFIX}Packets_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_{IMPL_PREFIX}Packets_API)
	#define Fanni_{IMPL_PREFIX}Packets_API
#endif

#endif // _FANNI_{IMPL_PREFIX}Packets_H_

CODE_TEMPALTE

1;

