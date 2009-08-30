/*
 **  OSSP uuid - Universally Unique Identifier
 **  Copyright (c) 2004-2008 Ralf S. Engelschall <rse@engelschall.com>
 **  Copyright (c) 2004-2008 The OSSP Project <http://www.ossp.org/>
 **
 **  This file is part of OSSP uuid, a library for the generation
 **  of UUIDs which can found at http://www.ossp.org/pkg/lib/uuid/
 **
 **  Permission to use, copy, modify, and distribute this software for
 **  any purpose with or without fee is hereby granted, provided that
 **  the above copyright notice and this permission notice appear in all
 **  copies.
 **
 **  THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 **  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 **  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 **  IN NO EVENT SHALL THE AUTHORS AND COPYRIGHT HOLDERS AND THEIR
 **  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 **  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 **  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 **  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 **  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 **  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 **  OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 **  SUCH DAMAGE.
 **
 **  uuid++.hh: library C++ API definition
 */

#ifndef __UUIDXX_HH__
#define __UUIDXX_HH__

/* required C API header */
#include <stdlib.h>
#include "uuid.h"

/* UUID object class */
class uuid {
public:
	/* construction & destruction */
	uuid(); /* standard constructor */
	uuid(const uuid &_obj); /* copy     constructor */
	uuid(const uuid_t *_obj); /* import   constructor */
	uuid(const void *_bin); /* import   constructor */
	uuid(const char *_str); /* import   constructor */
	~uuid(); /* destructor */

	/* copying & cloning */
	uuid &operator=(const uuid &_obj); /* copy   assignment operator */
	uuid &operator=(const uuid_t *_obj); /* import assignment operator */
	uuid &operator=(const void *_bin); /* import assignment operator */
	uuid &operator=(const char *_str); /* import assignment operator */
	uuid clone(void); /* regular method */

	/* content generation */
	void load(const char *_name); /* regular method */
	void make(unsigned int _mode, ...); /* regular method */

	/* content comparison */
	int isnil(void); /* regular method */
	int compare(const uuid &_obj); /* regular method */
	int operator==(const uuid &_obj); /* comparison operator */
	int operator!=(const uuid &_obj); /* comparison operator */
	int operator<(const uuid &_obj); /* comparison operator */
	int operator<=(const uuid &_obj); /* comparison operator */
	int operator>(const uuid &_obj); /* comparison operator */
	int operator>=(const uuid &_obj); /* comparison operator */

	/* content importing & exporting */
	void import(const void *_bin); /* regular method */
	void import(const char *_str); /* regular method */
	void *binary(void) const; /* regular method */
	char *string(void) const; /* regular method */
	char *integer(void) const; /* regular method */
	char *summary(void) const; /* regular method */

	unsigned long version(void) const; /* regular method */

private:
	uuid_t *ctx;
};

/* UUID exception class */
class uuid_error_t {
public:
	uuid_error_t() {
		code(UUID_RC_OK);
	}
	;
	uuid_error_t(uuid_rc_t _code) {
		code(_code);
	}
	;
	~uuid_error_t() {
	}
	;
	void code(uuid_rc_t _code) {
		rc = _code;
	}
	;
	uuid_rc_t code(void) {
		return rc;
	}
	;
	char *string(void) {
		return uuid_error(rc);
	}
	;

private:
	uuid_rc_t rc;
};

// ==============-
// fanni uuid wrapper
#include <string>
#include "fanni/SingletonTemplate.h"

namespace Fanni {

class UUID {
public:
	const static size_t UUID_SIZE = 16;
	const static size_t UUID_STRING_SIZE = 32;
	const static size_t UUID_STD_STRING_SIZE = 36;
	typedef unsigned char UUID_DATA_TYPE[UUID_SIZE];

private:
	UUID_DATA_TYPE data;

public:
	UUID();
	UUID(const UUID_DATA_TYPE &data);
	UUID(const UUID &uuid);
	UUID(const std::string &data);
	~UUID();
	bool operator==(const UUID &uuid);
	void parse(const std::string &data);
	const std::string toString() const;
	operator const UUID_DATA_TYPE&() const;
	operator unsigned char *();
};

class UUIDGenerator {
private:
	UUID zero_uuid;
	uuid ossp_uuid_generator;
public:
	UUIDGenerator();
	const UUID &Zero();
	const UUID Create();
};

typedef Singleton<UUIDGenerator> UUIDGeneratorSingleton;

}

#endif /* __UUIDXX_HH__ */
