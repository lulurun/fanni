#include "fanni/Exception.h"
#include <stdio.h>
#include <stdarg.h>

using namespace Fanni;

// Warn
WarnException::WarnException(const char *pref_func,int pref_line,const char *m)
	 : ExceptionBase(LV_WARN, pref_func, pref_line, m)
{
}

void WarnException::throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...)
{
	va_list vl;
	va_start(vl, fmt_str);
	char m[EXCEPTION_MSG_LEN];
	::vsprintf(m, fmt_str, vl);
	va_end(vl);
	throw WarnException(pref_func , pref_line , m);
}

// Error
ErrorException::ErrorException(const char *pref_func, int pref_line, const char *m)
	: ExceptionBase(LV_ERROR, pref_func, pref_line, m)
{
}

void ErrorException::throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...)
{
	va_list vl;
	va_start(vl, fmt_str);
	char m[EXCEPTION_MSG_LEN];
	::vsprintf(m, fmt_str, vl);
	va_end(vl);
	throw ErrorException(pref_func, pref_line, m);
}

// Fatal
FatalException::FatalException(const char *pref_func, int pref_line, const char *m)
	: ExceptionBase(LV_FATAL, pref_func, pref_line, m)
{
}

void FatalException::throw_exception(EXP_CODE_TYPE code, const char *pref_func, int pref_line, const char *fmt_str, ...)
{
	va_list vl;
	va_start(vl, fmt_str);
	char m[EXCEPTION_MSG_LEN];
	::vsprintf(m, fmt_str, vl);
	va_end(vl);
	throw FatalException(pref_func, pref_line, m);
}

