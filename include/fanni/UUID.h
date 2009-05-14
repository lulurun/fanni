#ifndef _UUID_H_
#define _UUID_H_
#include <string>

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
	operator std::string();

	static const UUID Zero();
	static const UUID New();
};

};

#endif /* _UUID_H_ */
