
#ifndef _FANNI_LLPackets_def_H_
#define _FANNI_LLPackets_def_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_LLPackets_EXPORTS)
		#define Fanni_LLPackets_API __declspec(dllexport)
	#else
		#define Fanni_LLPackets_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_LLPackets_API)
	#define Fanni_LLPackets_API
#endif

#endif // _FANNI_LLPackets_H_

