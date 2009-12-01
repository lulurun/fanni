#ifndef Fanni_DynamicFactory_INCLUDED
#define Fanni_DynamicFactory_INCLUDED

#include "Poco/Foundation.h"
#include "Poco/Instantiator.h"
#include "Poco/Exception.h"
#include "Poco/Mutex.h"
#include <map>
#include <memory>

namespace Fanni {

template <class Base>
class FactoryTemplate
{
public:
	typedef AbstractInstantiator<Base> AbstractFactory;

	FactoryTemplate() {}

	~DynamicFactory() {
		for (typename FactoryMap::iterator it = _map.begin(); it != _map.end(); ++it) {
			delete it->second;
		}
	}
	
	Base* createInstance(const std::string& className) const
	{
		FastMutex::ScopedLock lock(_mutex);

		typename FactoryMap::const_iterator it = _map.find(className);
		if (it != _map.end())
			return it->second->createInstance();
		else
			throw NotFoundException(className);
	}
	
	template <class C> 
	void registerClass(const std::string& className)
		/// Registers the instantiator for the given class with the DynamicFactory.
		/// The DynamicFactory takes ownership of the instantiator and deletes
		/// it when it's no longer used.
		/// If the class has already been registered, an ExistsException is thrown
		/// and the instantiator is deleted.
	{
		registerClass(className, new Instantiator<C, Base>);
	}
	
	void registerClass(const std::string& className, AbstractFactory* pAbstractFactory)
		/// Registers the instantiator for the given class with the DynamicFactory.
		/// The DynamicFactory takes ownership of the instantiator and deletes
		/// it when it's no longer used.
		/// If the class has already been registered, an ExistsException is thrown
		/// and the instantiator is deleted.
	{
		poco_check_ptr (pAbstractFactory);

		FastMutex::ScopedLock lock(_mutex);

		std::auto_ptr<AbstractFactory> ptr(pAbstractFactory);
		typename FactoryMap::iterator it = _map.find(className);
		if (it == _map.end())
			_map[className] = ptr.release();
		else
			throw ExistsException(className);
	}
	
	void unregisterClass(const std::string& className)
		/// Unregisters the given class and deletes the instantiator
		/// for the class.
		/// Throws a NotFoundException if the class has not been registered.
	{
		FastMutex::ScopedLock lock(_mutex);

		typename FactoryMap::iterator it = _map.find(className);
		if (it != _map.end())
		{
			delete it->second;
			_map.erase(it);
		}
		else throw NotFoundException(className);
	}
	
	bool isClass(const std::string& className) const
		/// Returns true iff the given class has been registered.
	{
		FastMutex::ScopedLock lock(_mutex);

		return _map.find(className) != _map.end();
	}

private:
	DynamicFactory(const DynamicFactory&);
	DynamicFactory& operator = (const DynamicFactory&);

	typedef std::map<std::string, AbstractFactory*> FactoryMap;
	
	FactoryMap _map;
	mutable FastMutex _mutex;
};


} // namespace Fanni


#endif // Fanni_DynamicFactory_INCLUDED
