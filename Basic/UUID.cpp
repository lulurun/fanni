#include <cctype> // for isxdigit ...
#include <cstring> // for isxdigit ...

#include "fanni/UUID.h"
#include "fanni/Exception.h"

// TODO @@@ temporary for UUID::New
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace Fanni;

// constructor
UUID::UUID(){
	::memset(this->data, 0, UUID_SIZE);
}

UUID::UUID(const UUID &uuid) {
	::memcpy(this->data, uuid.data, UUID_SIZE);
}

UUID::UUID(const UUID_DATA_TYPE &uuid) {
	::memcpy(this->data, uuid, UUID_SIZE);
}

UUID::UUID(const std::string &data) {
	this->parse(data);
}

UUID::~UUID(){};

// operator
bool UUID::operator==(const UUID &uuid) {
	return ::memcmp(this->data, uuid.data, UUID_SIZE) ? false : true;
}

UUID::operator const UUID_DATA_TYPE&() const {
	return this->data;
}

UUID::operator unsigned char *(){
	return &this->data[0];
}

UUID::operator std::string() {
	return this->toString();
}


// member function
const string UUID::toString() const {
	static const char *fmt_uuid_string = "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x";
	char out_str[UUID_STRING_SIZE];
	::snprintf(out_str, UUID_STRING_SIZE, fmt_uuid_string,
			this->data[0], this->data[1], this->data[2], this->data[3],
			this->data[4], this->data[5], this->data[6], this->data[7],
			this->data[8], this->data[9], this->data[10], this->data[11],
			this->data[12], this->data[13], this->data[14], this->data[15]);
	string out(out_str);
	return out;
};

void remove_string(string &s, const string& p) {
	size_t n = p.length();
	for(size_t i=s.find(p); i!=string::npos; i=s.find(p))
		s.erase(i, n);
}

void UUID::parse(const std::string &data) {
	string parse_data = data;
	remove_string(parse_data, "-");
	if (parse_data.size() != UUID_STRING_SIZE) {
		ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG, "bad uuid string format: size");
	}
	// check "isxdigit"
	const char *cp = parse_data.c_str();
	for (size_t i=0; i < UUID_STRING_SIZE; i++,cp++) {
		if (!isxdigit(*cp)) {
			ErrorException::throw_exception(Fanni::EXP_UUID, EXP_PRE_MSG, "bad uuid string format: isxdigit");
		}
	}
	// copy
	size_t i=0;
	const char *data_ptr = parse_data.c_str();
	while(i<UUID_SIZE) {
		char c1 = *data_ptr;
		data_ptr++;
		char c2 = *data_ptr;
		data_ptr++;
		this->data[i] = (c1 << 4) + c2;
		i++;
	}
}

const UUID UUID::Zero() {
	UUID uuid;
	return uuid;
}


const UUID UUID::New() {
	// TODO @@@ fix me first - use real UUID !!!
	srand(time(NULL));
	UUID_DATA_TYPE _uuid;
	for(size_t i=0; i<UUID_SIZE; i++) {
		_uuid[i] = rand() % 256;
	}
	UUID ret(_uuid);
	return ret;
}

