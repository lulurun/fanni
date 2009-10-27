#ifndef _FANNI_Basic_H_
#define _FANNI_Basic_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_EXPORTS)
		#define Fanni_API __declspec(dllexport)
	#else
		#define Fanni_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_API)
	#define Fanni_API
#endif

#endif // _FANNI_Basic_H_
