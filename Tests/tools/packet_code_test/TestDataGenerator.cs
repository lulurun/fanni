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

        static void FileInfo_gen()
        {
            FileInfoPacket packet = new FileInfoPacket();
                packet.FileInfo.Size = DefaultValues.S32;
                packet.FileInfo.Name = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void FileInfoReply_gen()
        {
            FileInfoReplyPacket packet = new FileInfoReplyPacket();
                packet.FileInfo.TransferID = DefaultValues.LLUUID;
                packet.FileInfo.Name = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void FileData_gen()
        {
            FileDataPacket packet = new FileDataPacket();
                packet.FileData.TransferID = DefaultValues.LLUUID;
                packet.FileData.DataNumber = DefaultValues.S32;
                packet.FileData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void PacketAck_gen()
        {
            PacketAckPacket packet = new PacketAckPacket();
            packet.Packets = new PacketAckPacket.PacketsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Packets[i] = new PacketAckPacket.PacketsBlock();
                packet.Packets[i].ID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void UseCircuitCode_gen()
        {
            UseCircuitCodePacket packet = new UseCircuitCodePacket();
                packet.CircuitCode.Code = DefaultValues.U32;
                packet.CircuitCode.SessionID = DefaultValues.LLUUID;
                packet.CircuitCode.ID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void CloseCircuit_gen()
        {
            CloseCircuitPacket packet = new CloseCircuitPacket();

            output(packet.ToBytes());
        }
        


        static void Main(string[] args)
        {
            FileInfo_gen();
            FileInfoReply_gen();
            FileData_gen();
            PacketAck_gen();
            UseCircuitCode_gen();
            CloseCircuit_gen();

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


