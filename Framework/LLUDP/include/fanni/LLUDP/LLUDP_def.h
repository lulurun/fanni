#ifndef _FANNI_LLUDP_H_
#define _FANNI_LLUDP_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_LLUDP_EXPORTS)
		#define Fanni_LLUDP_API __declspec(dllexport)
	#else
		#define Fanni_LLUDP_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_LLUDP_API)
	#define Fanni_LLUDP_API
#endif

#endif // _FANNI_LLUDP_H_
