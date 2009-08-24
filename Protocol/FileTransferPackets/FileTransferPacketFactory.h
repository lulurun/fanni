#ifndef FileTransferPACKETFACTORY_H_
#define FileTransferPACKETFACTORY_H_

#include "fanni/Serializable.h"
#include "fanni/SingletonTemplate.h"

#include "Packets/PacketFactory.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {

class FileTransferPacketFactory : public PacketFactory {
public:
    FileTransferPacketFactory();
    virtual ~FileTransferPacketFactory();
    virtual void init();
};

typedef Singleton<FileTransferPacketFactory> FileTransferPacketFactorySingleton;

PacketSerializer *CreateFileTransferPacketSerializer();

}

#endif /* FileTransferPACKETFACTORY_H_ */

