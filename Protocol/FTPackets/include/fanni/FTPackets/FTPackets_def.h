
#ifndef _FANNI_FTPackets_def_H_
#define _FANNI_FTPackets_def_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_FTPackets_EXPORTS)
		#define Fanni_FTPackets_API __declspec(dllexport)
	#else
		#define Fanni_FTPackets_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_FTPackets_API)
	#define Fanni_FTPackets_API
#endif

#endif // _FANNI_FTPackets_H_

