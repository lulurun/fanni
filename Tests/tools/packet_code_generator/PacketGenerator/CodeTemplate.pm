package CodeTemplate;

use strict;

# #######################
# PACKETCLASS_TEMPLATE
our $PacketClass_Template =<< "PACKETCLASS_TEMPLATE";
// {ClassName}
class {ClassName} : public {BaseClassName} {
public:

    // Block Class List
{BlockClassList}

    // {ClassName} Member List
{MemberList}

public:
    {ClassName}() {
{SetPacketInfo}
    };
    virtual ~{ClassName}() { };

    virtual void serialize(PacketBuffer &buffer) const {
{MemberListSerialize}
    }
    virtual void deserialize(PacketBuffer &buffer) {
{MemberListDeserialize}
    }
    virtual PacketBase *clone() const {
        return new {ClassName}(*this);
    }
    virtual PacketBase *clone(const PacketBase *packet) const {
        const {ClassName} *{ClassName}_packet = dynamic_cast<const {ClassName} *>(packet);
        if ({ClassName}_packet == NULL) {
            FatalException::throw_exception(EXP_Packet, EXP_PRE_MSG, "can not make a copy, packet type not matched");
        }
        return new {ClassName}(*{ClassName}_packet);
    }
};

PACKETCLASS_TEMPLATE

# #######################
# BLOCKCLASS_TEMPLATE
our $BlockClass_Template =<< "BLOCKCLASS_TEMPLATE";
class {ClassName} : public {BaseClassName} {
public:
    // {ClassName} Member List
{MemberList}

public:
    {ClassName}() {
{SetPacketInfo}
    };
    virtual ~{ClassName}() { };

    virtual void serialize(PacketBuffer &buffer) const {
{MemberListSerialize}
    }
    virtual void deserialize(PacketBuffer &buffer) {
{MemberListDeserialize}
    }
};

BLOCKCLASS_TEMPLATE

# #######################
# PACKETSID_H_TEMPLATE
our $PacketsID_H_Template =<< "PACKETSID_H_TEMPLATE";
#ifndef {IMPL_PREFIX}PACKET_ID_H_
#define {IMPL_PREFIX}PACKET_ID_H_

namespace Fanni {

{PacketIDEnum}

};

#endif // {IMPL_PREFIX}PACKET_ID_H

PACKETSID_H_TEMPLATE

# #######################
# PACKETS_H_TEMPLATE
our $Packets_H_Template =<< "PACKETS_H_TEMPLATE";
#ifndef {IMPL_PREFIX}PACKET_IMPL_H_
#define {IMPL_PREFIX}PACKET_IMPL_H_

#include "fanni/Exception.h"

#include "Packets/PacketBaseTypes.h"
#include "Packets/PacketBase.h"
#include "{IMPL_PREFIX}PacketsID.h"

namespace Fanni {

{PacketClasses}

};

#endif // {IMPL_PREFIX}PACKET_IMPL_H

PACKETS_H_TEMPLATE

# #######################
# PACKETFACTORY_CPP_TEMPLATE
our $PacketFactory_CPP_Template =<< "PACKETFACTORY_CPP_TEMPLATE";
#include "{IMPL_PREFIX}Packets.h"
#include "{IMPL_PREFIX}PacketFactory.h"

namespace Fanni {

{IMPL_PREFIX}PacketFactory::{IMPL_PREFIX}PacketFactory() {
{InitAllPackets}
}

{IMPL_PREFIX}PacketFactory::~{IMPL_PREFIX}PacketFactory() {}

PacketSerializer *Create{IMPL_PREFIX}PacketSerializer() {
    return new PacketSerializer({IMPL_PREFIX}PacketFactorySingleton::get());
}

}

PACKETFACTORY_CPP_TEMPLATE

# #######################
# PACKETFACTORY_H_TEMPLATE
our $PacketFactory_H_Template =<< "PACKETFACTORY_H_TEMPLATE";
#ifndef {IMPL_PREFIX}PACKETFACTORY_H_
#define {IMPL_PREFIX}PACKETFACTORY_H_

#include "fanni/SingletonTemplate.h"

#include "Packets/PacketFactory.h"
#include "Packets/PacketSerializer.h"

namespace Fanni {

class {IMPL_PREFIX}PacketFactory : public PacketFactory {
public:
    {IMPL_PREFIX}PacketFactory();
    virtual ~{IMPL_PREFIX}PacketFactory();
};

typedef Singleton<{IMPL_PREFIX}PacketFactory> {IMPL_PREFIX}PacketFactorySingleton;

PacketSerializer *Create{IMPL_PREFIX}PacketSerializer();

}

#endif /* {IMPL_PREFIX}PACKETFACTORY_H_ */

PACKETFACTORY_H_TEMPLATE

# ###################
# C# test data generation program
our $CSharp_TestProgram_Template =<< "CSHARPTESTPROGRAM_TEMPLATE";
using System;
using System.IO;
using System.Net;
using System.Collections.Generic;
using System.Text;
using OpenMetaverse;
using OpenMetaverse.Packets;

namespace PacketTest
{
    public class DefaultValues
    {
        static public uint IPAddressToLong(string IPAddr)
        {
            System.Net.IPAddress oIP = System.Net.IPAddress.Parse(IPAddr);
            byte[] byteIP = oIP.GetAddressBytes();


            uint ip = (uint)byteIP[3] << 24;
            ip += (uint)byteIP[2] << 16;
            ip += (uint)byteIP[1] << 8;
            ip += (uint)byteIP[0];

            return ip;
        }

        public static bool BOOL = true;
        public static float F32 = 0.12345f;
        public static double F64 = 0.67891234;
        public static byte[] Fixed4 = { 97, 98, 99, 100 };
        public static byte[] Fixed32 = {
                                           100, 101, 102, 103, 104, 105, 106, 107,
                                           110, 111, 112, 113, 114, 115, 116, 117,
                                           120, 121, 122, 123, 124, 125, 126, 127,
                                           130, 131, 132, 133, 134, 135, 136, 137,
					   };

        public static uint IPADDR = IPAddressToLong("127.0.0.1");
        public static ushort IPPORT = 8001;
        public static Quaternion LLQuaternion = new Quaternion(0f, 0f, 0f, 1f);
        public static UUID LLUUID = UUID.Parse("12345678-abcd-abcd-abcd-1234567890ab");
        public static Vector3 LLVector3 = new Vector3(1f, 2f, 3f);
        public static Vector3d LLVector3d = new Vector3d(0d, 1d, 0d);
        public static Vector4 LLVector4 = new Vector4(1f, 2f, 3f, 4f);
        public static short S16 = 4099;
        public static int S32 = 1024000;
        public static sbyte S8 = 97;
        public static ushort U16 = 8198;
        public static uint U32 = 9001234;
        public static ulong U64 = 123456789;
        public static byte U8 = 255;
        public static byte[] Variable1 = { 97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100 };
        public static byte[] Variable2 = {
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                             97, 98, 99, 100, 97, 98, 99, 100, 97, 98, 99, 100,
                                          };
        public static int variable_blocks_length = 5;

    }

    class TestDataGenerator
    {

        static StreamWriter w = new StreamWriter(@"libomv_generated_messages.txt");

{TestDataGen_FuncDef_List}

        static void Main(string[] args)
        {
{TestDataGen_FuncCall_List}
        }

        static void output(byte[] bytes_array)
        {
            w.WriteLine(ByteArrayToHexString(bytes_array));
        }

        static string ByteArrayToHexString(byte[] Bytes)
        {
            StringBuilder Result = new StringBuilder();
            string HexAlphabet = "0123456789ABCDEF";

            foreach (byte B in Bytes)
            {
                Result.Append(HexAlphabet[(int)(B >> 4)]);
                Result.Append(HexAlphabet[(int)(B & 0xF)]);
            }

            return Result.ToString();
        }

        static byte[] HexStringToByteArray(string Hex)
        {
            byte[] Bytes = new byte[Hex.Length / 2];
            int[] HexValue = new int[] { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
                                 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x0B, 0x0C, 0x0D,
					 0x0E, 0x0F };

            for (int x = 0, i = 0; i < Hex.Length; i += 2, x += 1)
            {
                Bytes[x] = (byte)(HexValue[Char.ToUpper(Hex[i + 0]) - '0'] << 4 |
                                  HexValue[Char.ToUpper(Hex[i + 1]) - '0']);
            }

            return Bytes;
        }
    }
}


CSHARPTESTPROGRAM_TEMPLATE

# ###################
# C# test data generation function
our $CSharp_DataGenFunction_Template =<< "CSHARP_DATAGENFUNCTION_TEMPLATE";
        static void {PacketName}_gen()
        {
            {PacketName}Packet packet = new {PacketName}Packet();
{Set_PacketData}
            output(packet.ToBytes());
        }
        
CSHARP_DATAGENFUNCTION_TEMPLATE

our $CSharp_BlockData_Template = << "CSHARP_BLOCKDATA_TEMPLATE";
            packet.{BlockName} = new {PacketName}Packet.{BlockName}Block[{BlockNumber}];
            for (int i = 0; i < {BlockNumber}; i++)
            {
                packet.{BlockName}[i] = new {PacketName}Packet.{BlockName}Block();
{BlockMemberAssignment}
	    }
CSHARP_BLOCKDATA_TEMPLATE


1;

