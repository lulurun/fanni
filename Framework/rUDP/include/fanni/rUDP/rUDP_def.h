#ifndef _FANNI_RUDP_H_
#define _FANNI_RUDP_H_

#if defined(_WIN32) && defined(Fanni_DLL)
	#if defined(Fanni_RUDP_EXPORTS)
		#define Fanni_RUDP_API __declspec(dllexport)
	#else
		#define Fanni_RUDP_API __declspec(dllimport)
	#endif
#endif


#if !defined(Fanni_RUDP_API)
	#define Fanni_RUDP_API
#endif

#endif // _FANNI_RUDP_H_
