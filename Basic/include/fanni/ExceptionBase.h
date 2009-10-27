#ifndef FP_EXCEPTION_BASE_H
#define FP_EXCEPTION_BASE_H

//#define EXP_PRE_MSG __PRETTY_FUNCTION__,__LINE__
#define EXP_PRE_MSG "",__LINE__
// MEMO @@@ !! should be enough, dont make message too long :)
#define EXCEPTION_MSG_LEN 1024

#include "fanni/Basic_def.h"

namespace Fanni{

class Fanni_API ExceptionBase{
	protected:
		enum{
			LV_WARN		= 1,
			LV_ERROR		= 2,
			LV_FATAL		= 3,
		};
		int 			level;
		const char *	pref_func;
		int 			pref_line;
		char	msg[EXCEPTION_MSG_LEN];

	protected:
		ExceptionBase(int level, const char *pf, int pl, const char *m);
		virtual ~ExceptionBase();
	public:
		const char *get_msg() const ;
		const char *get_func() const ;
		int 		get_line() const;
};

} // namespace

#endif

