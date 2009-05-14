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
        return new {ClassName}();
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
# PACKET_H_TEMPLATE
our $Packet_H_Template =<< "PACKET_H_TEMPLATE";
#ifndef PACKET_IMPL_H_
#define PACKET_IMPL_H_

#include "PacketBaseTypes.h"
#include "PacketBase.h"

namespace Fanni {

{PacketIDEnum}

{PacketClasses}

};

#endif // PACKET_IMPL_H

PACKET_H_TEMPLATE

# #######################
# PACKETFACTORY_CPP_TEMPLATE
our $PacketFactory_CPP_Template =<< "PACKETFACTORY_CPP_TEMPLATE";
#include <tr1/unordered_map>
#include "Packets.h"
#include "PacketBase.h"
#include "PacketFactory.h"

using namespace std;
using namespace Fanni;

typedef tr1::unordered_map<PacketHeader::PACKET_ID_TYPE, const PacketBase*> PACKET_MAP_TYPE;
static PACKET_MAP_TYPE PacketList;

PacketFactory::PacketFactory() {}
PacketFactory::~PacketFactory() {}

void PacketFactory::init() {
{InitAllPackets}
}

PacketBase *PacketFactory::createPacket(PacketHeader::PACKET_ID_TYPE packet_id) const {
    PacketBase *ret = NULL;
    PACKET_MAP_TYPE::const_iterator it = PacketList.find(packet_id);
    if(it != PacketList.end()){
	ret = it->second->clone();
	//TODO @@@ implement "clone" instead of simply create a new!!!
    }
    return ret;
}

PacketFactory *PacketFactory::GetInstance() {
    static PacketFactory *factory;
    if (factory == NULL){
	factory = new PacketFactory();
	factory->init();
    }
    return factory;
}

PACKETFACTORY_CPP_TEMPLATE

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

