#ifndef _FANNI_Packets_H_
#define _FANNI_Packets_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_EXPORTS)
		#define Fanni_Packets_API __declspec(dllexport)
	#else
		#define Fanni_Packets_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_Packets_API)
	#define Fanni_Packets_API
#endif

#endif // _FANNI_Packets_H_
