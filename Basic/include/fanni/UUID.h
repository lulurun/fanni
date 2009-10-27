#ifndef __UUIDXX_HH__
#define __UUIDXX_HH__

#include "Poco/UUID.h"
#include "Poco/UUIDGenerator.h"
#include "fanni/SingletonTemplate.h"

namespace Fanni {

typedef Poco::UUID UUID;

class UUIDGenerator {
private:
	UUID zero_uuid;

public:
	const UUID &Zero() {
		return this->zero_uuid;
	}
	inline const UUID Create() {
		return Poco::UUIDGenerator::defaultGenerator().create();
	}
};

typedef Singleton<UUIDGenerator> UUIDGeneratorSingleton;

}

#endif /* __UUIDXX_HH__ */
