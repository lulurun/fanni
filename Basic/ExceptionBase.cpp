#include <stdio.h>
#include "fanni/ExceptionBase.h"

using namespace Fanni;

ExceptionBase::ExceptionBase(int lv, const char *pf, int pl, const char *m)
	 : level(lv), pref_func(pf), pref_line(pl)
{
	::sprintf(this->msg, m);
}

ExceptionBase::~ExceptionBase(){
}

const char * ExceptionBase::get_msg()const{
	return this->msg;
}
const char * ExceptionBase::get_func()const{
	return this->pref_func;
}
int ExceptionBase::get_line()const{
	return this->pref_line;
}

