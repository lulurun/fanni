#ifndef FP_EXCEPTION_H
#define FP_EXCEPTION_H

#include "fanni/Basic_def.h"
#include "fanni/ExceptionBase.h"

namespace Fanni{

enum{
	EXP_TEST = 1,
	EXP_UUID,
	EXP_Packet,
	EXP_FixedLengthBuffer,
	EXP_Network,
};
typedef int EXP_CODE_TYPE;

class Fanni_API WarnException :public ExceptionBase{
	protected:
		WarnException(const char *pref_func,int pref_line,const char *m);
	public:
		static void throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...) /*__attribute__((noreturn))*/;
};
class Fanni_API ErrorException :public ExceptionBase{
	protected:
		ErrorException(const char *pref_func, int pref_line, const char *m);
	public:
		static void throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...) /*__attribute__((noreturn))*/;
};
class Fanni_API FatalException :public ExceptionBase{
	protected:
		FatalException(const char *pref_func, int pref_line, const char *m);
	public:
		static void throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...) /*__attribute__((noreturn))*/;
};

}

#endif

