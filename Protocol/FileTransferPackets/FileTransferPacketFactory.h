#ifndef FileTransferPACKETFACTORY_H_
#define FileTransferPACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"

#include "Packets/PacketFactory.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {

class FileTransferPacketFactory : public PacketFactory {
public:
    FileTransferPacketFactory();
    virtual ~FileTransferPacketFactory();
};

typedef Singleton<FileTransferPacketFactory> FileTransferPacketFactorySingleton;

PacketSerializer *CreateFileTransferPacketSerializer();

}

#endif /* FileTransferPACKETFACTORY_H_ */

