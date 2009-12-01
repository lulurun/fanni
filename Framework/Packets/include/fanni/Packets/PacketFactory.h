#ifndef PACKETFACTORY_H_
#define PACKETFACTORY_H_

#include <map>
#include <memory>
#include "Poco/Instantiator.h"
#include "Poco/Mutex.h"
#include "fanni/SingletonTemplate.h"
#include "fanni/Packets/Packets_def.h"
#include "fanni/Packets/PacketHeader.h"
#include "fanni/Packets/PacketBase.h"

namespace Fanni {

class Fanni_Packets_API PacketFactory {
private:
	PacketFactory(const PacketFactory&);
	PacketFactory& operator = (const PacketFactory&);

	typedef Poco::AbstractInstantiator<PacketBase> AbstractFactory;
	typedef std::map<PacketHeader::PACKET_ID_TYPE, AbstractFactory*> FactoryMap;
	FactoryMap _map;
	mutable Poco::FastMutex _mutex;

	void registerClass(const PacketHeader::PACKET_ID_TYPE &packet_id, AbstractFactory* pAbstractFactory) {
		Poco::FastMutex::ScopedLock lock(_mutex);
		std::auto_ptr<AbstractFactory> ptr(pAbstractFactory);
		FactoryMap::iterator it = _map.find(packet_id);
		if (it == _map.end())
			_map[packet_id] = ptr.release();
		else
			throw Poco::ExistsException();
	}

public:
	PacketFactory() {};
	virtual ~PacketFactory() {
			for (FactoryMap::iterator it = _map.begin(); it != _map.end(); ++it) {
			delete it->second;
		}
	};

	PacketBase *createPacket(const PacketHeader::PACKET_ID_TYPE &packet_id) const {
		//Poco::FastMutex::ScopedLock lock(_mutex);
		FactoryMap::const_iterator it = _map.find(packet_id);
		if (it != _map.end())
			return it->second->createInstance();
		else
			throw Poco::NotFoundException();
	};

	template<class C>
	void registerPacket(const PacketHeader::PACKET_ID_TYPE &packet_id) {
		registerClass(packet_id, new Poco::Instantiator<C, PacketBase>);
	};

	void unregisterClass(const PacketHeader::PACKET_ID_TYPE &packet_id) {
		Poco::FastMutex::ScopedLock lock(_mutex);
		FactoryMap::iterator it = _map.find(packet_id);
		if (it != _map.end())
		{
			delete it->second;
			_map.erase(it);
		}
		else throw Poco::NotFoundException();
	}
	
	bool isClass(const PacketHeader::PACKET_ID_TYPE &packet_id) const
		/// Returns true iff the given class has been registered.
	{
		Poco::FastMutex::ScopedLock lock(_mutex);
		return _map.find(packet_id) != _map.end();
	}

};

typedef Singleton<PacketFactory> PacketFactorySingleton;

}

#endif /* PACKETFACTORY_H_ */
