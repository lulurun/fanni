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

        static void TestMessage_gen()
        {
            TestMessagePacket packet = new TestMessagePacket();
                packet.TestBlock1.Test1 = DefaultValues.U32;
            packet.NeighborBlock = new TestMessagePacket.NeighborBlockBlock[4];
            for (int i = 0; i < 4; i++)
            {
                packet.NeighborBlock[i] = new TestMessagePacket.NeighborBlockBlock();
                packet.NeighborBlock[i].Test0 = DefaultValues.U32;
                packet.NeighborBlock[i].Test1 = DefaultValues.U32;
                packet.NeighborBlock[i].Test2 = DefaultValues.U32;

	    }

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
        
        static void OpenCircuit_gen()
        {
            OpenCircuitPacket packet = new OpenCircuitPacket();
                packet.CircuitInfo.IP = DefaultValues.IPADDR;
                packet.CircuitInfo.Port = DefaultValues.IPPORT;

            output(packet.ToBytes());
        }
        
        static void CloseCircuit_gen()
        {
            CloseCircuitPacket packet = new CloseCircuitPacket();

            output(packet.ToBytes());
        }
        
        static void StartPingCheck_gen()
        {
            StartPingCheckPacket packet = new StartPingCheckPacket();
                packet.PingID.PingID = DefaultValues.U8;
                packet.PingID.OldestUnacked = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void CompletePingCheck_gen()
        {
            CompletePingCheckPacket packet = new CompletePingCheckPacket();
                packet.PingID.PingID = DefaultValues.U8;

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
        
        static void TelehubInfo_gen()
        {
            TelehubInfoPacket packet = new TelehubInfoPacket();
                packet.TelehubBlock.ObjectID = DefaultValues.LLUUID;
                packet.TelehubBlock.ObjectName = DefaultValues.Variable1;
                packet.TelehubBlock.TelehubPos = DefaultValues.LLVector3;
                packet.TelehubBlock.TelehubRot = DefaultValues.LLQuaternion;
            packet.SpawnPointBlock = new TelehubInfoPacket.SpawnPointBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.SpawnPointBlock[i] = new TelehubInfoPacket.SpawnPointBlockBlock();
                packet.SpawnPointBlock[i].SpawnPointPos = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void EconomyDataRequest_gen()
        {
            EconomyDataRequestPacket packet = new EconomyDataRequestPacket();

            output(packet.ToBytes());
        }
        
        static void EconomyData_gen()
        {
            EconomyDataPacket packet = new EconomyDataPacket();
                packet.Info.ObjectCapacity = DefaultValues.S32;
                packet.Info.ObjectCount = DefaultValues.S32;
                packet.Info.PriceEnergyUnit = DefaultValues.S32;
                packet.Info.PriceObjectClaim = DefaultValues.S32;
                packet.Info.PricePublicObjectDecay = DefaultValues.S32;
                packet.Info.PricePublicObjectDelete = DefaultValues.S32;
                packet.Info.PriceParcelClaim = DefaultValues.S32;
                packet.Info.PriceParcelClaimFactor = DefaultValues.F32;
                packet.Info.PriceUpload = DefaultValues.S32;
                packet.Info.PriceRentLight = DefaultValues.S32;
                packet.Info.TeleportMinPrice = DefaultValues.S32;
                packet.Info.TeleportPriceExponent = DefaultValues.F32;
                packet.Info.EnergyEfficiency = DefaultValues.F32;
                packet.Info.PriceObjectRent = DefaultValues.F32;
                packet.Info.PriceObjectScaleFactor = DefaultValues.F32;
                packet.Info.PriceParcelRent = DefaultValues.S32;
                packet.Info.PriceGroupCreate = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void AvatarPickerRequest_gen()
        {
            AvatarPickerRequestPacket packet = new AvatarPickerRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.QueryID = DefaultValues.LLUUID;
                packet.Data.Name = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AvatarPickerReply_gen()
        {
            AvatarPickerReplyPacket packet = new AvatarPickerReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.QueryID = DefaultValues.LLUUID;
            packet.Data = new AvatarPickerReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new AvatarPickerReplyPacket.DataBlock();
                packet.Data[i].AvatarID = DefaultValues.LLUUID;
                packet.Data[i].FirstName = DefaultValues.Variable1;
                packet.Data[i].LastName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void PlacesQuery_gen()
        {
            PlacesQueryPacket packet = new PlacesQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.QueryID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;
                packet.QueryData.QueryText = DefaultValues.Variable1;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.Category = DefaultValues.S8;
                packet.QueryData.SimName = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void PlacesReply_gen()
        {
            PlacesReplyPacket packet = new PlacesReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.QueryID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;
            packet.QueryData = new PlacesReplyPacket.QueryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryData[i] = new PlacesReplyPacket.QueryDataBlock();
                packet.QueryData[i].OwnerID = DefaultValues.LLUUID;
                packet.QueryData[i].Name = DefaultValues.Variable1;
                packet.QueryData[i].Desc = DefaultValues.Variable1;
                packet.QueryData[i].ActualArea = DefaultValues.S32;
                packet.QueryData[i].BillableArea = DefaultValues.S32;
                packet.QueryData[i].Flags = DefaultValues.U8;
                packet.QueryData[i].GlobalX = DefaultValues.F32;
                packet.QueryData[i].GlobalY = DefaultValues.F32;
                packet.QueryData[i].GlobalZ = DefaultValues.F32;
                packet.QueryData[i].SimName = DefaultValues.Variable1;
                packet.QueryData[i].SnapshotID = DefaultValues.LLUUID;
                packet.QueryData[i].Dwell = DefaultValues.F32;
                packet.QueryData[i].Price = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirFindQuery_gen()
        {
            DirFindQueryPacket packet = new DirFindQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryText = DefaultValues.Variable1;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.QueryStart = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void DirPlacesQuery_gen()
        {
            DirPlacesQueryPacket packet = new DirPlacesQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryText = DefaultValues.Variable1;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.Category = DefaultValues.S8;
                packet.QueryData.SimName = DefaultValues.Variable1;
                packet.QueryData.QueryStart = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void DirPlacesReply_gen()
        {
            DirPlacesReplyPacket packet = new DirPlacesReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
            packet.QueryData = new DirPlacesReplyPacket.QueryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryData[i] = new DirPlacesReplyPacket.QueryDataBlock();
                packet.QueryData[i].QueryID = DefaultValues.LLUUID;

	    }
            packet.QueryReplies = new DirPlacesReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirPlacesReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].ParcelID = DefaultValues.LLUUID;
                packet.QueryReplies[i].Name = DefaultValues.Variable1;
                packet.QueryReplies[i].ForSale = DefaultValues.BOOL;
                packet.QueryReplies[i].Auction = DefaultValues.BOOL;
                packet.QueryReplies[i].Dwell = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirPeopleReply_gen()
        {
            DirPeopleReplyPacket packet = new DirPeopleReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirPeopleReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirPeopleReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].AgentID = DefaultValues.LLUUID;
                packet.QueryReplies[i].FirstName = DefaultValues.Variable1;
                packet.QueryReplies[i].LastName = DefaultValues.Variable1;
                packet.QueryReplies[i].Group = DefaultValues.Variable1;
                packet.QueryReplies[i].Online = DefaultValues.BOOL;
                packet.QueryReplies[i].Reputation = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirEventsReply_gen()
        {
            DirEventsReplyPacket packet = new DirEventsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirEventsReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirEventsReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].OwnerID = DefaultValues.LLUUID;
                packet.QueryReplies[i].Name = DefaultValues.Variable1;
                packet.QueryReplies[i].EventID = DefaultValues.U32;
                packet.QueryReplies[i].Date = DefaultValues.Variable1;
                packet.QueryReplies[i].UnixTime = DefaultValues.U32;
                packet.QueryReplies[i].EventFlags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirGroupsReply_gen()
        {
            DirGroupsReplyPacket packet = new DirGroupsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirGroupsReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirGroupsReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].GroupID = DefaultValues.LLUUID;
                packet.QueryReplies[i].GroupName = DefaultValues.Variable1;
                packet.QueryReplies[i].Members = DefaultValues.S32;
                packet.QueryReplies[i].SearchOrder = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirClassifiedQuery_gen()
        {
            DirClassifiedQueryPacket packet = new DirClassifiedQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryText = DefaultValues.Variable1;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.Category = DefaultValues.U32;
                packet.QueryData.QueryStart = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void DirClassifiedReply_gen()
        {
            DirClassifiedReplyPacket packet = new DirClassifiedReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirClassifiedReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirClassifiedReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].ClassifiedID = DefaultValues.LLUUID;
                packet.QueryReplies[i].Name = DefaultValues.Variable1;
                packet.QueryReplies[i].ClassifiedFlags = DefaultValues.U8;
                packet.QueryReplies[i].CreationDate = DefaultValues.U32;
                packet.QueryReplies[i].ExpirationDate = DefaultValues.U32;
                packet.QueryReplies[i].PriceForListing = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void AvatarClassifiedReply_gen()
        {
            AvatarClassifiedReplyPacket packet = new AvatarClassifiedReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.TargetID = DefaultValues.LLUUID;
            packet.Data = new AvatarClassifiedReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new AvatarClassifiedReplyPacket.DataBlock();
                packet.Data[i].ClassifiedID = DefaultValues.LLUUID;
                packet.Data[i].Name = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ClassifiedInfoRequest_gen()
        {
            ClassifiedInfoRequestPacket packet = new ClassifiedInfoRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ClassifiedInfoReply_gen()
        {
            ClassifiedInfoReplyPacket packet = new ClassifiedInfoReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;
                packet.Data.CreatorID = DefaultValues.LLUUID;
                packet.Data.CreationDate = DefaultValues.U32;
                packet.Data.ExpirationDate = DefaultValues.U32;
                packet.Data.Category = DefaultValues.U32;
                packet.Data.Name = DefaultValues.Variable1;
                packet.Data.Desc = DefaultValues.Variable2;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.ParentEstate = DefaultValues.U32;
                packet.Data.SnapshotID = DefaultValues.LLUUID;
                packet.Data.SimName = DefaultValues.Variable1;
                packet.Data.PosGlobal = DefaultValues.LLVector3d;
                packet.Data.ParcelName = DefaultValues.Variable1;
                packet.Data.ClassifiedFlags = DefaultValues.U8;
                packet.Data.PriceForListing = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ClassifiedInfoUpdate_gen()
        {
            ClassifiedInfoUpdatePacket packet = new ClassifiedInfoUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;
                packet.Data.Category = DefaultValues.U32;
                packet.Data.Name = DefaultValues.Variable1;
                packet.Data.Desc = DefaultValues.Variable2;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.ParentEstate = DefaultValues.U32;
                packet.Data.SnapshotID = DefaultValues.LLUUID;
                packet.Data.PosGlobal = DefaultValues.LLVector3d;
                packet.Data.ClassifiedFlags = DefaultValues.U8;
                packet.Data.PriceForListing = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ClassifiedDelete_gen()
        {
            ClassifiedDeletePacket packet = new ClassifiedDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ClassifiedGodDelete_gen()
        {
            ClassifiedGodDeletePacket packet = new ClassifiedGodDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;
                packet.Data.QueryID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void DirLandQuery_gen()
        {
            DirLandQueryPacket packet = new DirLandQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.SearchType = DefaultValues.U32;
                packet.QueryData.Price = DefaultValues.S32;
                packet.QueryData.Area = DefaultValues.S32;
                packet.QueryData.QueryStart = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void DirLandReply_gen()
        {
            DirLandReplyPacket packet = new DirLandReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirLandReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirLandReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].ParcelID = DefaultValues.LLUUID;
                packet.QueryReplies[i].Name = DefaultValues.Variable1;
                packet.QueryReplies[i].Auction = DefaultValues.BOOL;
                packet.QueryReplies[i].ForSale = DefaultValues.BOOL;
                packet.QueryReplies[i].SalePrice = DefaultValues.S32;
                packet.QueryReplies[i].ActualArea = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void DirPopularQuery_gen()
        {
            DirPopularQueryPacket packet = new DirPopularQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void DirPopularReply_gen()
        {
            DirPopularReplyPacket packet = new DirPopularReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
            packet.QueryReplies = new DirPopularReplyPacket.QueryRepliesBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.QueryReplies[i] = new DirPopularReplyPacket.QueryRepliesBlock();
                packet.QueryReplies[i].ParcelID = DefaultValues.LLUUID;
                packet.QueryReplies[i].Name = DefaultValues.Variable1;
                packet.QueryReplies[i].Dwell = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelInfoRequest_gen()
        {
            ParcelInfoRequestPacket packet = new ParcelInfoRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ParcelID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ParcelInfoReply_gen()
        {
            ParcelInfoReplyPacket packet = new ParcelInfoReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.OwnerID = DefaultValues.LLUUID;
                packet.Data.Name = DefaultValues.Variable1;
                packet.Data.Desc = DefaultValues.Variable1;
                packet.Data.ActualArea = DefaultValues.S32;
                packet.Data.BillableArea = DefaultValues.S32;
                packet.Data.Flags = DefaultValues.U8;
                packet.Data.GlobalX = DefaultValues.F32;
                packet.Data.GlobalY = DefaultValues.F32;
                packet.Data.GlobalZ = DefaultValues.F32;
                packet.Data.SimName = DefaultValues.Variable1;
                packet.Data.SnapshotID = DefaultValues.LLUUID;
                packet.Data.Dwell = DefaultValues.F32;
                packet.Data.SalePrice = DefaultValues.S32;
                packet.Data.AuctionID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelObjectOwnersRequest_gen()
        {
            ParcelObjectOwnersRequestPacket packet = new ParcelObjectOwnersRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelObjectOwnersReply_gen()
        {
            ParcelObjectOwnersReplyPacket packet = new ParcelObjectOwnersReplyPacket();
            packet.Data = new ParcelObjectOwnersReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new ParcelObjectOwnersReplyPacket.DataBlock();
                packet.Data[i].OwnerID = DefaultValues.LLUUID;
                packet.Data[i].IsGroupOwned = DefaultValues.BOOL;
                packet.Data[i].Count = DefaultValues.S32;
                packet.Data[i].OnlineStatus = DefaultValues.BOOL;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupNoticesListRequest_gen()
        {
            GroupNoticesListRequestPacket packet = new GroupNoticesListRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupNoticesListReply_gen()
        {
            GroupNoticesListReplyPacket packet = new GroupNoticesListReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.Data = new GroupNoticesListReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new GroupNoticesListReplyPacket.DataBlock();
                packet.Data[i].NoticeID = DefaultValues.LLUUID;
                packet.Data[i].Timestamp = DefaultValues.U32;
                packet.Data[i].FromName = DefaultValues.Variable2;
                packet.Data[i].Subject = DefaultValues.Variable2;
                packet.Data[i].HasAttachment = DefaultValues.BOOL;
                packet.Data[i].AssetType = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupNoticeRequest_gen()
        {
            GroupNoticeRequestPacket packet = new GroupNoticeRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupNoticeID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TeleportRequest_gen()
        {
            TeleportRequestPacket packet = new TeleportRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Info.RegionID = DefaultValues.LLUUID;
                packet.Info.Position = DefaultValues.LLVector3;
                packet.Info.LookAt = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void TeleportLocationRequest_gen()
        {
            TeleportLocationRequestPacket packet = new TeleportLocationRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Info.RegionHandle = DefaultValues.U64;
                packet.Info.Position = DefaultValues.LLVector3;
                packet.Info.LookAt = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void TeleportLocal_gen()
        {
            TeleportLocalPacket packet = new TeleportLocalPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.LocationID = DefaultValues.U32;
                packet.Info.Position = DefaultValues.LLVector3;
                packet.Info.LookAt = DefaultValues.LLVector3;
                packet.Info.TeleportFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void TeleportLandmarkRequest_gen()
        {
            TeleportLandmarkRequestPacket packet = new TeleportLandmarkRequestPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.SessionID = DefaultValues.LLUUID;
                packet.Info.LandmarkID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TeleportProgress_gen()
        {
            TeleportProgressPacket packet = new TeleportProgressPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Info.TeleportFlags = DefaultValues.U32;
                packet.Info.Message = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void TeleportFinish_gen()
        {
            TeleportFinishPacket packet = new TeleportFinishPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.LocationID = DefaultValues.U32;
                packet.Info.SimIP = DefaultValues.IPADDR;
                packet.Info.SimPort = DefaultValues.IPPORT;
                packet.Info.RegionHandle = DefaultValues.U64;
                packet.Info.SeedCapability = DefaultValues.Variable2;
                packet.Info.SimAccess = DefaultValues.U8;
                packet.Info.TeleportFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void StartLure_gen()
        {
            StartLurePacket packet = new StartLurePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Info.LureType = DefaultValues.U8;
                packet.Info.Message = DefaultValues.Variable1;
            packet.TargetData = new StartLurePacket.TargetDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.TargetData[i] = new StartLurePacket.TargetDataBlock();
                packet.TargetData[i].TargetID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void TeleportLureRequest_gen()
        {
            TeleportLureRequestPacket packet = new TeleportLureRequestPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.SessionID = DefaultValues.LLUUID;
                packet.Info.LureID = DefaultValues.LLUUID;
                packet.Info.TeleportFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void TeleportCancel_gen()
        {
            TeleportCancelPacket packet = new TeleportCancelPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TeleportStart_gen()
        {
            TeleportStartPacket packet = new TeleportStartPacket();
                packet.Info.TeleportFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void TeleportFailed_gen()
        {
            TeleportFailedPacket packet = new TeleportFailedPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.Reason = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void Undo_gen()
        {
            UndoPacket packet = new UndoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.ObjectData = new UndoPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new UndoPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void Redo_gen()
        {
            RedoPacket packet = new RedoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.ObjectData = new RedoPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new RedoPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void UndoLand_gen()
        {
            UndoLandPacket packet = new UndoLandPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AgentPause_gen()
        {
            AgentPausePacket packet = new AgentPausePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AgentResume_gen()
        {
            AgentResumePacket packet = new AgentResumePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AgentUpdate_gen()
        {
            AgentUpdatePacket packet = new AgentUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.BodyRotation = DefaultValues.LLQuaternion;
                packet.AgentData.HeadRotation = DefaultValues.LLQuaternion;
                packet.AgentData.State = DefaultValues.U8;
                packet.AgentData.CameraCenter = DefaultValues.LLVector3;
                packet.AgentData.CameraAtAxis = DefaultValues.LLVector3;
                packet.AgentData.CameraLeftAxis = DefaultValues.LLVector3;
                packet.AgentData.CameraUpAxis = DefaultValues.LLVector3;
                packet.AgentData.Far = DefaultValues.F32;
                packet.AgentData.ControlFlags = DefaultValues.U32;
                packet.AgentData.Flags = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void ChatFromViewer_gen()
        {
            ChatFromViewerPacket packet = new ChatFromViewerPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ChatData.Message = DefaultValues.Variable2;
                packet.ChatData.Type = DefaultValues.U8;
                packet.ChatData.Channel = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void AgentThrottle_gen()
        {
            AgentThrottlePacket packet = new AgentThrottlePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.CircuitCode = DefaultValues.U32;
                packet.Throttle.GenCounter = DefaultValues.U32;
                packet.Throttle.Throttles = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AgentFOV_gen()
        {
            AgentFOVPacket packet = new AgentFOVPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.CircuitCode = DefaultValues.U32;
                packet.FOVBlock.GenCounter = DefaultValues.U32;
                packet.FOVBlock.VerticalAngle = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void AgentHeightWidth_gen()
        {
            AgentHeightWidthPacket packet = new AgentHeightWidthPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.CircuitCode = DefaultValues.U32;
                packet.HeightWidthBlock.GenCounter = DefaultValues.U32;
                packet.HeightWidthBlock.Height = DefaultValues.U16;
                packet.HeightWidthBlock.Width = DefaultValues.U16;

            output(packet.ToBytes());
        }
        
        static void AgentSetAppearance_gen()
        {
            AgentSetAppearancePacket packet = new AgentSetAppearancePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.U32;
                packet.AgentData.Size = DefaultValues.LLVector3;
            packet.WearableData = new AgentSetAppearancePacket.WearableDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.WearableData[i] = new AgentSetAppearancePacket.WearableDataBlock();
                packet.WearableData[i].CacheID = DefaultValues.LLUUID;
                packet.WearableData[i].TextureIndex = DefaultValues.U8;

	    }
                packet.ObjectData.TextureEntry = DefaultValues.Variable2;
            packet.VisualParam = new AgentSetAppearancePacket.VisualParamBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.VisualParam[i] = new AgentSetAppearancePacket.VisualParamBlock();
                packet.VisualParam[i].ParamValue = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentAnimation_gen()
        {
            AgentAnimationPacket packet = new AgentAnimationPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.AnimationList = new AgentAnimationPacket.AnimationListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AnimationList[i] = new AgentAnimationPacket.AnimationListBlock();
                packet.AnimationList[i].AnimID = DefaultValues.LLUUID;
                packet.AnimationList[i].StartAnim = DefaultValues.BOOL;

	    }
            packet.PhysicalAvatarEventList = new AgentAnimationPacket.PhysicalAvatarEventListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.PhysicalAvatarEventList[i] = new AgentAnimationPacket.PhysicalAvatarEventListBlock();
                packet.PhysicalAvatarEventList[i].TypeData = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentRequestSit_gen()
        {
            AgentRequestSitPacket packet = new AgentRequestSitPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TargetObject.TargetID = DefaultValues.LLUUID;
                packet.TargetObject.Offset = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void AgentSit_gen()
        {
            AgentSitPacket packet = new AgentSitPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AgentQuitCopy_gen()
        {
            AgentQuitCopyPacket packet = new AgentQuitCopyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.FuseBlock.ViewerCircuitCode = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void RequestImage_gen()
        {
            RequestImagePacket packet = new RequestImagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.RequestImage = new RequestImagePacket.RequestImageBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.RequestImage[i] = new RequestImagePacket.RequestImageBlock();
                packet.RequestImage[i].Image = DefaultValues.LLUUID;
                packet.RequestImage[i].DiscardLevel = DefaultValues.S8;
                packet.RequestImage[i].DownloadPriority = DefaultValues.F32;
                packet.RequestImage[i].Packet = DefaultValues.U32;
                packet.RequestImage[i].Type = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void ImageNotInDatabase_gen()
        {
            ImageNotInDatabasePacket packet = new ImageNotInDatabasePacket();
                packet.ImageID.ID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RebakeAvatarTextures_gen()
        {
            RebakeAvatarTexturesPacket packet = new RebakeAvatarTexturesPacket();
                packet.TextureData.TextureID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void SetAlwaysRun_gen()
        {
            SetAlwaysRunPacket packet = new SetAlwaysRunPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AlwaysRun = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ObjectAdd_gen()
        {
            ObjectAddPacket packet = new ObjectAddPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.ObjectData.PCode = DefaultValues.U8;
                packet.ObjectData.Material = DefaultValues.U8;
                packet.ObjectData.AddFlags = DefaultValues.U32;
                packet.ObjectData.PathCurve = DefaultValues.U8;
                packet.ObjectData.ProfileCurve = DefaultValues.U8;
                packet.ObjectData.PathBegin = DefaultValues.U16;
                packet.ObjectData.PathEnd = DefaultValues.U16;
                packet.ObjectData.PathScaleX = DefaultValues.U8;
                packet.ObjectData.PathScaleY = DefaultValues.U8;
                packet.ObjectData.PathShearX = DefaultValues.U8;
                packet.ObjectData.PathShearY = DefaultValues.U8;
                packet.ObjectData.PathTwist = DefaultValues.S8;
                packet.ObjectData.PathTwistBegin = DefaultValues.S8;
                packet.ObjectData.PathRadiusOffset = DefaultValues.S8;
                packet.ObjectData.PathTaperX = DefaultValues.S8;
                packet.ObjectData.PathTaperY = DefaultValues.S8;
                packet.ObjectData.PathRevolutions = DefaultValues.U8;
                packet.ObjectData.PathSkew = DefaultValues.S8;
                packet.ObjectData.ProfileBegin = DefaultValues.U16;
                packet.ObjectData.ProfileEnd = DefaultValues.U16;
                packet.ObjectData.ProfileHollow = DefaultValues.U16;
                packet.ObjectData.BypassRaycast = DefaultValues.U8;
                packet.ObjectData.RayStart = DefaultValues.LLVector3;
                packet.ObjectData.RayEnd = DefaultValues.LLVector3;
                packet.ObjectData.RayTargetID = DefaultValues.LLUUID;
                packet.ObjectData.RayEndIsIntersection = DefaultValues.U8;
                packet.ObjectData.Scale = DefaultValues.LLVector3;
                packet.ObjectData.Rotation = DefaultValues.LLQuaternion;
                packet.ObjectData.State = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void ObjectDelete_gen()
        {
            ObjectDeletePacket packet = new ObjectDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Force = DefaultValues.BOOL;
            packet.ObjectData = new ObjectDeletePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDeletePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDuplicate_gen()
        {
            ObjectDuplicatePacket packet = new ObjectDuplicatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.SharedData.Offset = DefaultValues.LLVector3;
                packet.SharedData.DuplicateFlags = DefaultValues.U32;
            packet.ObjectData = new ObjectDuplicatePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDuplicatePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDuplicateOnRay_gen()
        {
            ObjectDuplicateOnRayPacket packet = new ObjectDuplicateOnRayPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.RayStart = DefaultValues.LLVector3;
                packet.AgentData.RayEnd = DefaultValues.LLVector3;
                packet.AgentData.BypassRaycast = DefaultValues.BOOL;
                packet.AgentData.RayEndIsIntersection = DefaultValues.BOOL;
                packet.AgentData.CopyCenters = DefaultValues.BOOL;
                packet.AgentData.CopyRotates = DefaultValues.BOOL;
                packet.AgentData.RayTargetID = DefaultValues.LLUUID;
                packet.AgentData.DuplicateFlags = DefaultValues.U32;
            packet.ObjectData = new ObjectDuplicateOnRayPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDuplicateOnRayPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void MultipleObjectUpdate_gen()
        {
            MultipleObjectUpdatePacket packet = new MultipleObjectUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new MultipleObjectUpdatePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new MultipleObjectUpdatePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Type = DefaultValues.U8;
                packet.ObjectData[i].Data = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void RequestMultipleObjects_gen()
        {
            RequestMultipleObjectsPacket packet = new RequestMultipleObjectsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new RequestMultipleObjectsPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new RequestMultipleObjectsPacket.ObjectDataBlock();
                packet.ObjectData[i].CacheMissType = DefaultValues.U8;
                packet.ObjectData[i].ID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectPosition_gen()
        {
            ObjectPositionPacket packet = new ObjectPositionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectPositionPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectPositionPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Position = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectScale_gen()
        {
            ObjectScalePacket packet = new ObjectScalePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectScalePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectScalePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Scale = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectRotation_gen()
        {
            ObjectRotationPacket packet = new ObjectRotationPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectRotationPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectRotationPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Rotation = DefaultValues.LLQuaternion;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectFlagUpdate_gen()
        {
            ObjectFlagUpdatePacket packet = new ObjectFlagUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.ObjectLocalID = DefaultValues.U32;
                packet.AgentData.UsePhysics = DefaultValues.BOOL;
                packet.AgentData.IsTemporary = DefaultValues.BOOL;
                packet.AgentData.IsPhantom = DefaultValues.BOOL;
                packet.AgentData.CastsShadows = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ObjectClickAction_gen()
        {
            ObjectClickActionPacket packet = new ObjectClickActionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectClickActionPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectClickActionPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].ClickAction = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectImage_gen()
        {
            ObjectImagePacket packet = new ObjectImagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectImagePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectImagePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].MediaURL = DefaultValues.Variable1;
                packet.ObjectData[i].TextureEntry = DefaultValues.Variable2;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectMaterial_gen()
        {
            ObjectMaterialPacket packet = new ObjectMaterialPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectMaterialPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectMaterialPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Material = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectShape_gen()
        {
            ObjectShapePacket packet = new ObjectShapePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectShapePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectShapePacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].PathCurve = DefaultValues.U8;
                packet.ObjectData[i].ProfileCurve = DefaultValues.U8;
                packet.ObjectData[i].PathBegin = DefaultValues.U16;
                packet.ObjectData[i].PathEnd = DefaultValues.U16;
                packet.ObjectData[i].PathScaleX = DefaultValues.U8;
                packet.ObjectData[i].PathScaleY = DefaultValues.U8;
                packet.ObjectData[i].PathShearX = DefaultValues.U8;
                packet.ObjectData[i].PathShearY = DefaultValues.U8;
                packet.ObjectData[i].PathTwist = DefaultValues.S8;
                packet.ObjectData[i].PathTwistBegin = DefaultValues.S8;
                packet.ObjectData[i].PathRadiusOffset = DefaultValues.S8;
                packet.ObjectData[i].PathTaperX = DefaultValues.S8;
                packet.ObjectData[i].PathTaperY = DefaultValues.S8;
                packet.ObjectData[i].PathRevolutions = DefaultValues.U8;
                packet.ObjectData[i].PathSkew = DefaultValues.S8;
                packet.ObjectData[i].ProfileBegin = DefaultValues.U16;
                packet.ObjectData[i].ProfileEnd = DefaultValues.U16;
                packet.ObjectData[i].ProfileHollow = DefaultValues.U16;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectExtraParams_gen()
        {
            ObjectExtraParamsPacket packet = new ObjectExtraParamsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectExtraParamsPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectExtraParamsPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].ParamType = DefaultValues.U16;
                packet.ObjectData[i].ParamInUse = DefaultValues.BOOL;
                packet.ObjectData[i].ParamSize = DefaultValues.U32;
                packet.ObjectData[i].ParamData = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectOwner_gen()
        {
            ObjectOwnerPacket packet = new ObjectOwnerPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.HeaderData.Override = DefaultValues.BOOL;
                packet.HeaderData.OwnerID = DefaultValues.LLUUID;
                packet.HeaderData.GroupID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectOwnerPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectOwnerPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectGroup_gen()
        {
            ObjectGroupPacket packet = new ObjectGroupPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectGroupPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectGroupPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectBuy_gen()
        {
            ObjectBuyPacket packet = new ObjectBuyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.CategoryID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectBuyPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectBuyPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].SaleType = DefaultValues.U8;
                packet.ObjectData[i].SalePrice = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void BuyObjectInventory_gen()
        {
            BuyObjectInventoryPacket packet = new BuyObjectInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.ItemID = DefaultValues.LLUUID;
                packet.Data.FolderID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void DerezContainer_gen()
        {
            DerezContainerPacket packet = new DerezContainerPacket();
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.Delete = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ObjectPermissions_gen()
        {
            ObjectPermissionsPacket packet = new ObjectPermissionsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.HeaderData.Override = DefaultValues.BOOL;
            packet.ObjectData = new ObjectPermissionsPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectPermissionsPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Field = DefaultValues.U8;
                packet.ObjectData[i].Set = DefaultValues.U8;
                packet.ObjectData[i].Mask = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectSaleInfo_gen()
        {
            ObjectSaleInfoPacket packet = new ObjectSaleInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectSaleInfoPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectSaleInfoPacket.ObjectDataBlock();
                packet.ObjectData[i].LocalID = DefaultValues.U32;
                packet.ObjectData[i].SaleType = DefaultValues.U8;
                packet.ObjectData[i].SalePrice = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectName_gen()
        {
            ObjectNamePacket packet = new ObjectNamePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectNamePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectNamePacket.ObjectDataBlock();
                packet.ObjectData[i].LocalID = DefaultValues.U32;
                packet.ObjectData[i].Name = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDescription_gen()
        {
            ObjectDescriptionPacket packet = new ObjectDescriptionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectDescriptionPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDescriptionPacket.ObjectDataBlock();
                packet.ObjectData[i].LocalID = DefaultValues.U32;
                packet.ObjectData[i].Description = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectCategory_gen()
        {
            ObjectCategoryPacket packet = new ObjectCategoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectCategoryPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectCategoryPacket.ObjectDataBlock();
                packet.ObjectData[i].LocalID = DefaultValues.U32;
                packet.ObjectData[i].Category = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectSelect_gen()
        {
            ObjectSelectPacket packet = new ObjectSelectPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectSelectPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectSelectPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDeselect_gen()
        {
            ObjectDeselectPacket packet = new ObjectDeselectPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectDeselectPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDeselectPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectAttach_gen()
        {
            ObjectAttachPacket packet = new ObjectAttachPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AttachmentPoint = DefaultValues.U8;
            packet.ObjectData = new ObjectAttachPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectAttachPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].Rotation = DefaultValues.LLQuaternion;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDetach_gen()
        {
            ObjectDetachPacket packet = new ObjectDetachPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectDetachPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDetachPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDrop_gen()
        {
            ObjectDropPacket packet = new ObjectDropPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectDropPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDropPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectLink_gen()
        {
            ObjectLinkPacket packet = new ObjectLinkPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectLinkPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectLinkPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDelink_gen()
        {
            ObjectDelinkPacket packet = new ObjectDelinkPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectDelinkPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectDelinkPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectGrab_gen()
        {
            ObjectGrabPacket packet = new ObjectGrabPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.LocalID = DefaultValues.U32;
                packet.ObjectData.GrabOffset = DefaultValues.LLVector3;
            packet.SurfaceInfo = new ObjectGrabPacket.SurfaceInfoBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.SurfaceInfo[i] = new ObjectGrabPacket.SurfaceInfoBlock();
                packet.SurfaceInfo[i].UVCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].STCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].FaceIndex = DefaultValues.S32;
                packet.SurfaceInfo[i].Position = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Normal = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Binormal = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectGrabUpdate_gen()
        {
            ObjectGrabUpdatePacket packet = new ObjectGrabUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;
                packet.ObjectData.GrabOffsetInitial = DefaultValues.LLVector3;
                packet.ObjectData.GrabPosition = DefaultValues.LLVector3;
                packet.ObjectData.TimeSinceLast = DefaultValues.U32;
            packet.SurfaceInfo = new ObjectGrabUpdatePacket.SurfaceInfoBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.SurfaceInfo[i] = new ObjectGrabUpdatePacket.SurfaceInfoBlock();
                packet.SurfaceInfo[i].UVCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].STCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].FaceIndex = DefaultValues.S32;
                packet.SurfaceInfo[i].Position = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Normal = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Binormal = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectDeGrab_gen()
        {
            ObjectDeGrabPacket packet = new ObjectDeGrabPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.LocalID = DefaultValues.U32;
            packet.SurfaceInfo = new ObjectDeGrabPacket.SurfaceInfoBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.SurfaceInfo[i] = new ObjectDeGrabPacket.SurfaceInfoBlock();
                packet.SurfaceInfo[i].UVCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].STCoord = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].FaceIndex = DefaultValues.S32;
                packet.SurfaceInfo[i].Position = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Normal = DefaultValues.LLVector3;
                packet.SurfaceInfo[i].Binormal = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectSpinStart_gen()
        {
            ObjectSpinStartPacket packet = new ObjectSpinStartPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ObjectSpinUpdate_gen()
        {
            ObjectSpinUpdatePacket packet = new ObjectSpinUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;
                packet.ObjectData.Rotation = DefaultValues.LLQuaternion;

            output(packet.ToBytes());
        }
        
        static void ObjectSpinStop_gen()
        {
            ObjectSpinStopPacket packet = new ObjectSpinStopPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ObjectExportSelected_gen()
        {
            ObjectExportSelectedPacket packet = new ObjectExportSelectedPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.RequestID = DefaultValues.LLUUID;
                packet.AgentData.VolumeDetail = DefaultValues.S16;
            packet.ObjectData = new ObjectExportSelectedPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectExportSelectedPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ModifyLand_gen()
        {
            ModifyLandPacket packet = new ModifyLandPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ModifyBlock.Action = DefaultValues.U8;
                packet.ModifyBlock.BrushSize = DefaultValues.U8;
                packet.ModifyBlock.Seconds = DefaultValues.F32;
                packet.ModifyBlock.Height = DefaultValues.F32;
            packet.ParcelData = new ModifyLandPacket.ParcelDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParcelData[i] = new ModifyLandPacket.ParcelDataBlock();
                packet.ParcelData[i].LocalID = DefaultValues.S32;
                packet.ParcelData[i].West = DefaultValues.F32;
                packet.ParcelData[i].South = DefaultValues.F32;
                packet.ParcelData[i].East = DefaultValues.F32;
                packet.ParcelData[i].North = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void VelocityInterpolateOn_gen()
        {
            VelocityInterpolateOnPacket packet = new VelocityInterpolateOnPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void VelocityInterpolateOff_gen()
        {
            VelocityInterpolateOffPacket packet = new VelocityInterpolateOffPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void StateSave_gen()
        {
            StateSavePacket packet = new StateSavePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.DataBlock.Filename = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void ReportAutosaveCrash_gen()
        {
            ReportAutosaveCrashPacket packet = new ReportAutosaveCrashPacket();
                packet.AutosaveData.PID = DefaultValues.S32;
                packet.AutosaveData.Status = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void SimWideDeletes_gen()
        {
            SimWideDeletesPacket packet = new SimWideDeletesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.DataBlock.TargetID = DefaultValues.LLUUID;
                packet.DataBlock.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void RequestObjectPropertiesFamily_gen()
        {
            RequestObjectPropertiesFamilyPacket packet = new RequestObjectPropertiesFamilyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.RequestFlags = DefaultValues.U32;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TrackAgent_gen()
        {
            TrackAgentPacket packet = new TrackAgentPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TargetData.PreyID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ViewerStats_gen()
        {
            ViewerStatsPacket packet = new ViewerStatsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.IP = DefaultValues.IPADDR;
                packet.AgentData.StartTime = DefaultValues.U32;
                packet.AgentData.RunTime = DefaultValues.F32;
                packet.AgentData.SimFPS = DefaultValues.F32;
                packet.AgentData.FPS = DefaultValues.F32;
                packet.AgentData.AgentsInView = DefaultValues.U8;
                packet.AgentData.Ping = DefaultValues.F32;
                packet.AgentData.MetersTraveled = DefaultValues.F64;
                packet.AgentData.RegionsVisited = DefaultValues.S32;
                packet.AgentData.SysRAM = DefaultValues.U32;
                packet.AgentData.SysOS = DefaultValues.Variable1;
                packet.AgentData.SysCPU = DefaultValues.Variable1;
                packet.AgentData.SysGPU = DefaultValues.Variable1;
                packet.DownloadTotals.World = DefaultValues.U32;
                packet.DownloadTotals.Objects = DefaultValues.U32;
                packet.DownloadTotals.Textures = DefaultValues.U32;
            packet.NetStats = new ViewerStatsPacket.NetStatsBlock[2];
            for (int i = 0; i < 2; i++)
            {
                packet.NetStats[i] = new ViewerStatsPacket.NetStatsBlock();
                packet.NetStats[i].Bytes = DefaultValues.U32;
                packet.NetStats[i].Packets = DefaultValues.U32;
                packet.NetStats[i].Compressed = DefaultValues.U32;
                packet.NetStats[i].Savings = DefaultValues.U32;

	    }
                packet.FailStats.SendPacket = DefaultValues.U32;
                packet.FailStats.Dropped = DefaultValues.U32;
                packet.FailStats.Resent = DefaultValues.U32;
                packet.FailStats.FailedResends = DefaultValues.U32;
                packet.FailStats.OffCircuit = DefaultValues.U32;
                packet.FailStats.Invalid = DefaultValues.U32;
            packet.MiscStats = new ViewerStatsPacket.MiscStatsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.MiscStats[i] = new ViewerStatsPacket.MiscStatsBlock();
                packet.MiscStats[i].Type = DefaultValues.U32;
                packet.MiscStats[i].Value = DefaultValues.F64;

	    }

            output(packet.ToBytes());
        }
        
        static void ScriptAnswerYes_gen()
        {
            ScriptAnswerYesPacket packet = new ScriptAnswerYesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.TaskID = DefaultValues.LLUUID;
                packet.Data.ItemID = DefaultValues.LLUUID;
                packet.Data.Questions = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void UserReport_gen()
        {
            UserReportPacket packet = new UserReportPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ReportData.ReportType = DefaultValues.U8;
                packet.ReportData.Category = DefaultValues.U8;
                packet.ReportData.Position = DefaultValues.LLVector3;
                packet.ReportData.CheckFlags = DefaultValues.U8;
                packet.ReportData.ScreenshotID = DefaultValues.LLUUID;
                packet.ReportData.ObjectID = DefaultValues.LLUUID;
                packet.ReportData.AbuserID = DefaultValues.LLUUID;
                packet.ReportData.AbuseRegionName = DefaultValues.Variable1;
                packet.ReportData.AbuseRegionID = DefaultValues.LLUUID;
                packet.ReportData.Summary = DefaultValues.Variable1;
                packet.ReportData.Details = DefaultValues.Variable2;
                packet.ReportData.VersionString = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AlertMessage_gen()
        {
            AlertMessagePacket packet = new AlertMessagePacket();
                packet.AlertData.Message = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AgentAlertMessage_gen()
        {
            AgentAlertMessagePacket packet = new AgentAlertMessagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AlertData.Modal = DefaultValues.BOOL;
                packet.AlertData.Message = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void MeanCollisionAlert_gen()
        {
            MeanCollisionAlertPacket packet = new MeanCollisionAlertPacket();
            packet.MeanCollision = new MeanCollisionAlertPacket.MeanCollisionBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.MeanCollision[i] = new MeanCollisionAlertPacket.MeanCollisionBlock();
                packet.MeanCollision[i].Victim = DefaultValues.LLUUID;
                packet.MeanCollision[i].Perp = DefaultValues.LLUUID;
                packet.MeanCollision[i].Time = DefaultValues.U32;
                packet.MeanCollision[i].Mag = DefaultValues.F32;
                packet.MeanCollision[i].Type = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void ViewerFrozenMessage_gen()
        {
            ViewerFrozenMessagePacket packet = new ViewerFrozenMessagePacket();
                packet.FrozenData.Data = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void HealthMessage_gen()
        {
            HealthMessagePacket packet = new HealthMessagePacket();
                packet.HealthData.Health = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void ChatFromSimulator_gen()
        {
            ChatFromSimulatorPacket packet = new ChatFromSimulatorPacket();
                packet.ChatData.FromName = DefaultValues.Variable1;
                packet.ChatData.SourceID = DefaultValues.LLUUID;
                packet.ChatData.OwnerID = DefaultValues.LLUUID;
                packet.ChatData.SourceType = DefaultValues.U8;
                packet.ChatData.ChatType = DefaultValues.U8;
                packet.ChatData.Audible = DefaultValues.U8;
                packet.ChatData.Position = DefaultValues.LLVector3;
                packet.ChatData.Message = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void SimStats_gen()
        {
            SimStatsPacket packet = new SimStatsPacket();
                packet.Region.RegionX = DefaultValues.U32;
                packet.Region.RegionY = DefaultValues.U32;
                packet.Region.RegionFlags = DefaultValues.U32;
                packet.Region.ObjectCapacity = DefaultValues.U32;
            packet.Stat = new SimStatsPacket.StatBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Stat[i] = new SimStatsPacket.StatBlock();
                packet.Stat[i].StatID = DefaultValues.U32;
                packet.Stat[i].StatValue = DefaultValues.F32;

	    }
                packet.PidStat.PID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void RequestRegionInfo_gen()
        {
            RequestRegionInfoPacket packet = new RequestRegionInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RegionInfo_gen()
        {
            RegionInfoPacket packet = new RegionInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RegionInfo.SimName = DefaultValues.Variable1;
                packet.RegionInfo.EstateID = DefaultValues.U32;
                packet.RegionInfo.ParentEstateID = DefaultValues.U32;
                packet.RegionInfo.RegionFlags = DefaultValues.U32;
                packet.RegionInfo.SimAccess = DefaultValues.U8;
                packet.RegionInfo.MaxAgents = DefaultValues.U8;
                packet.RegionInfo.BillableFactor = DefaultValues.F32;
                packet.RegionInfo.ObjectBonusFactor = DefaultValues.F32;
                packet.RegionInfo.WaterHeight = DefaultValues.F32;
                packet.RegionInfo.TerrainRaiseLimit = DefaultValues.F32;
                packet.RegionInfo.TerrainLowerLimit = DefaultValues.F32;
                packet.RegionInfo.PricePerMeter = DefaultValues.S32;
                packet.RegionInfo.RedirectGridX = DefaultValues.S32;
                packet.RegionInfo.RedirectGridY = DefaultValues.S32;
                packet.RegionInfo.UseEstateSun = DefaultValues.BOOL;
                packet.RegionInfo.SunHour = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void GodUpdateRegionInfo_gen()
        {
            GodUpdateRegionInfoPacket packet = new GodUpdateRegionInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RegionInfo.SimName = DefaultValues.Variable1;
                packet.RegionInfo.EstateID = DefaultValues.U32;
                packet.RegionInfo.ParentEstateID = DefaultValues.U32;
                packet.RegionInfo.RegionFlags = DefaultValues.U32;
                packet.RegionInfo.BillableFactor = DefaultValues.F32;
                packet.RegionInfo.PricePerMeter = DefaultValues.S32;
                packet.RegionInfo.RedirectGridX = DefaultValues.S32;
                packet.RegionInfo.RedirectGridY = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void NearestLandingRegionUpdated_gen()
        {
            NearestLandingRegionUpdatedPacket packet = new NearestLandingRegionUpdatedPacket();
                packet.RegionData.RegionHandle = DefaultValues.U64;

            output(packet.ToBytes());
        }
        
        static void RegionHandshake_gen()
        {
            RegionHandshakePacket packet = new RegionHandshakePacket();
                packet.RegionInfo.RegionFlags = DefaultValues.U32;
                packet.RegionInfo.SimAccess = DefaultValues.U8;
                packet.RegionInfo.SimName = DefaultValues.Variable1;
                packet.RegionInfo.SimOwner = DefaultValues.LLUUID;
                packet.RegionInfo.IsEstateManager = DefaultValues.BOOL;
                packet.RegionInfo.WaterHeight = DefaultValues.F32;
                packet.RegionInfo.BillableFactor = DefaultValues.F32;
                packet.RegionInfo.CacheID = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainBase0 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainBase1 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainBase2 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainBase3 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainDetail0 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainDetail1 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainDetail2 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainDetail3 = DefaultValues.LLUUID;
                packet.RegionInfo.TerrainStartHeight00 = DefaultValues.F32;
                packet.RegionInfo.TerrainStartHeight01 = DefaultValues.F32;
                packet.RegionInfo.TerrainStartHeight10 = DefaultValues.F32;
                packet.RegionInfo.TerrainStartHeight11 = DefaultValues.F32;
                packet.RegionInfo.TerrainHeightRange00 = DefaultValues.F32;
                packet.RegionInfo.TerrainHeightRange01 = DefaultValues.F32;
                packet.RegionInfo.TerrainHeightRange10 = DefaultValues.F32;
                packet.RegionInfo.TerrainHeightRange11 = DefaultValues.F32;
                packet.RegionInfo2.RegionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RegionHandshakeReply_gen()
        {
            RegionHandshakeReplyPacket packet = new RegionHandshakeReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RegionInfo.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void CoarseLocationUpdate_gen()
        {
            CoarseLocationUpdatePacket packet = new CoarseLocationUpdatePacket();
            packet.Location = new CoarseLocationUpdatePacket.LocationBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Location[i] = new CoarseLocationUpdatePacket.LocationBlock();
                packet.Location[i].X = DefaultValues.U8;
                packet.Location[i].Y = DefaultValues.U8;
                packet.Location[i].Z = DefaultValues.U8;

	    }
                packet.Index.You = DefaultValues.S16;
                packet.Index.Prey = DefaultValues.S16;
            packet.AgentData = new CoarseLocationUpdatePacket.AgentDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AgentData[i] = new CoarseLocationUpdatePacket.AgentDataBlock();
                packet.AgentData[i].AgentID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ImageData_gen()
        {
            ImageDataPacket packet = new ImageDataPacket();
                packet.ImageID.ID = DefaultValues.LLUUID;
                packet.ImageID.Codec = DefaultValues.U8;
                packet.ImageID.Size = DefaultValues.U32;
                packet.ImageID.Packets = DefaultValues.U16;
                packet.ImageData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void ImagePacket_gen()
        {
            ImagePacketPacket packet = new ImagePacketPacket();
                packet.ImageID.ID = DefaultValues.LLUUID;
                packet.ImageID.Packet = DefaultValues.U16;
                packet.ImageData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void LayerData_gen()
        {
            LayerDataPacket packet = new LayerDataPacket();
                packet.LayerID.Type = DefaultValues.U8;
                packet.LayerData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void ObjectUpdate_gen()
        {
            ObjectUpdatePacket packet = new ObjectUpdatePacket();
                packet.RegionData.RegionHandle = DefaultValues.U64;
                packet.RegionData.TimeDilation = DefaultValues.U16;
            packet.ObjectData = new ObjectUpdatePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectUpdatePacket.ObjectDataBlock();
                packet.ObjectData[i].ID = DefaultValues.U32;
                packet.ObjectData[i].State = DefaultValues.U8;
                packet.ObjectData[i].FullID = DefaultValues.LLUUID;
                packet.ObjectData[i].CRC = DefaultValues.U32;
                packet.ObjectData[i].PCode = DefaultValues.U8;
                packet.ObjectData[i].Material = DefaultValues.U8;
                packet.ObjectData[i].ClickAction = DefaultValues.U8;
                packet.ObjectData[i].Scale = DefaultValues.LLVector3;
                packet.ObjectData[i].ObjectData = DefaultValues.Variable1;
                packet.ObjectData[i].ParentID = DefaultValues.U32;
                packet.ObjectData[i].UpdateFlags = DefaultValues.U32;
                packet.ObjectData[i].PathCurve = DefaultValues.U8;
                packet.ObjectData[i].ProfileCurve = DefaultValues.U8;
                packet.ObjectData[i].PathBegin = DefaultValues.U16;
                packet.ObjectData[i].PathEnd = DefaultValues.U16;
                packet.ObjectData[i].PathScaleX = DefaultValues.U8;
                packet.ObjectData[i].PathScaleY = DefaultValues.U8;
                packet.ObjectData[i].PathShearX = DefaultValues.U8;
                packet.ObjectData[i].PathShearY = DefaultValues.U8;
                packet.ObjectData[i].PathTwist = DefaultValues.S8;
                packet.ObjectData[i].PathTwistBegin = DefaultValues.S8;
                packet.ObjectData[i].PathRadiusOffset = DefaultValues.S8;
                packet.ObjectData[i].PathTaperX = DefaultValues.S8;
                packet.ObjectData[i].PathTaperY = DefaultValues.S8;
                packet.ObjectData[i].PathRevolutions = DefaultValues.U8;
                packet.ObjectData[i].PathSkew = DefaultValues.S8;
                packet.ObjectData[i].ProfileBegin = DefaultValues.U16;
                packet.ObjectData[i].ProfileEnd = DefaultValues.U16;
                packet.ObjectData[i].ProfileHollow = DefaultValues.U16;
                packet.ObjectData[i].TextureEntry = DefaultValues.Variable2;
                packet.ObjectData[i].TextureAnim = DefaultValues.Variable1;
                packet.ObjectData[i].NameValue = DefaultValues.Variable2;
                packet.ObjectData[i].Data = DefaultValues.Variable2;
                packet.ObjectData[i].Text = DefaultValues.Variable1;
                packet.ObjectData[i].TextColor = DefaultValues.Fixed4;
                packet.ObjectData[i].MediaURL = DefaultValues.Variable1;
                packet.ObjectData[i].PSBlock = DefaultValues.Variable1;
                packet.ObjectData[i].ExtraParams = DefaultValues.Variable1;
                packet.ObjectData[i].Sound = DefaultValues.LLUUID;
                packet.ObjectData[i].OwnerID = DefaultValues.LLUUID;
                packet.ObjectData[i].Gain = DefaultValues.F32;
                packet.ObjectData[i].Flags = DefaultValues.U8;
                packet.ObjectData[i].Radius = DefaultValues.F32;
                packet.ObjectData[i].JointType = DefaultValues.U8;
                packet.ObjectData[i].JointPivot = DefaultValues.LLVector3;
                packet.ObjectData[i].JointAxisOrAnchor = DefaultValues.LLVector3;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectUpdateCompressed_gen()
        {
            ObjectUpdateCompressedPacket packet = new ObjectUpdateCompressedPacket();
                packet.RegionData.RegionHandle = DefaultValues.U64;
                packet.RegionData.TimeDilation = DefaultValues.U16;
            packet.ObjectData = new ObjectUpdateCompressedPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectUpdateCompressedPacket.ObjectDataBlock();
                packet.ObjectData[i].UpdateFlags = DefaultValues.U32;
                packet.ObjectData[i].Data = DefaultValues.Variable2;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectUpdateCached_gen()
        {
            ObjectUpdateCachedPacket packet = new ObjectUpdateCachedPacket();
                packet.RegionData.RegionHandle = DefaultValues.U64;
                packet.RegionData.TimeDilation = DefaultValues.U16;
            packet.ObjectData = new ObjectUpdateCachedPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectUpdateCachedPacket.ObjectDataBlock();
                packet.ObjectData[i].ID = DefaultValues.U32;
                packet.ObjectData[i].CRC = DefaultValues.U32;
                packet.ObjectData[i].UpdateFlags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ImprovedTerseObjectUpdate_gen()
        {
            ImprovedTerseObjectUpdatePacket packet = new ImprovedTerseObjectUpdatePacket();
                packet.RegionData.RegionHandle = DefaultValues.U64;
                packet.RegionData.TimeDilation = DefaultValues.U16;
            packet.ObjectData = new ImprovedTerseObjectUpdatePacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ImprovedTerseObjectUpdatePacket.ObjectDataBlock();
                packet.ObjectData[i].Data = DefaultValues.Variable1;
                packet.ObjectData[i].TextureEntry = DefaultValues.Variable2;

	    }

            output(packet.ToBytes());
        }
        
        static void KillObject_gen()
        {
            KillObjectPacket packet = new KillObjectPacket();
            packet.ObjectData = new KillObjectPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new KillObjectPacket.ObjectDataBlock();
                packet.ObjectData[i].ID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void CrossedRegion_gen()
        {
            CrossedRegionPacket packet = new CrossedRegionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RegionData.SimIP = DefaultValues.IPADDR;
                packet.RegionData.SimPort = DefaultValues.IPPORT;
                packet.RegionData.RegionHandle = DefaultValues.U64;
                packet.RegionData.SeedCapability = DefaultValues.Variable2;
                packet.Info.Position = DefaultValues.LLVector3;
                packet.Info.LookAt = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void SimulatorViewerTimeMessage_gen()
        {
            SimulatorViewerTimeMessagePacket packet = new SimulatorViewerTimeMessagePacket();
                packet.TimeInfo.UsecSinceStart = DefaultValues.U64;
                packet.TimeInfo.SecPerDay = DefaultValues.U32;
                packet.TimeInfo.SecPerYear = DefaultValues.U32;
                packet.TimeInfo.SunDirection = DefaultValues.LLVector3;
                packet.TimeInfo.SunPhase = DefaultValues.F32;
                packet.TimeInfo.SunAngVelocity = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void EnableSimulator_gen()
        {
            EnableSimulatorPacket packet = new EnableSimulatorPacket();
                packet.SimulatorInfo.Handle = DefaultValues.U64;
                packet.SimulatorInfo.IP = DefaultValues.IPADDR;
                packet.SimulatorInfo.Port = DefaultValues.IPPORT;

            output(packet.ToBytes());
        }
        
        static void DisableSimulator_gen()
        {
            DisableSimulatorPacket packet = new DisableSimulatorPacket();

            output(packet.ToBytes());
        }
        
        static void ConfirmEnableSimulator_gen()
        {
            ConfirmEnableSimulatorPacket packet = new ConfirmEnableSimulatorPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TransferRequest_gen()
        {
            TransferRequestPacket packet = new TransferRequestPacket();
                packet.TransferInfo.TransferID = DefaultValues.LLUUID;
                packet.TransferInfo.ChannelType = DefaultValues.S32;
                packet.TransferInfo.SourceType = DefaultValues.S32;
                packet.TransferInfo.Priority = DefaultValues.F32;
                packet.TransferInfo.Params = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void TransferInfo_gen()
        {
            TransferInfoPacket packet = new TransferInfoPacket();
                packet.TransferInfo.TransferID = DefaultValues.LLUUID;
                packet.TransferInfo.ChannelType = DefaultValues.S32;
                packet.TransferInfo.TargetType = DefaultValues.S32;
                packet.TransferInfo.Status = DefaultValues.S32;
                packet.TransferInfo.Size = DefaultValues.S32;
                packet.TransferInfo.Params = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void TransferPacket_gen()
        {
            TransferPacketPacket packet = new TransferPacketPacket();
                packet.TransferData.TransferID = DefaultValues.LLUUID;
                packet.TransferData.ChannelType = DefaultValues.S32;
                packet.TransferData.Packet = DefaultValues.S32;
                packet.TransferData.Status = DefaultValues.S32;
                packet.TransferData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void TransferAbort_gen()
        {
            TransferAbortPacket packet = new TransferAbortPacket();
                packet.TransferInfo.TransferID = DefaultValues.LLUUID;
                packet.TransferInfo.ChannelType = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void RequestXfer_gen()
        {
            RequestXferPacket packet = new RequestXferPacket();
                packet.XferID.ID = DefaultValues.U64;
                packet.XferID.Filename = DefaultValues.Variable1;
                packet.XferID.FilePath = DefaultValues.U8;
                packet.XferID.DeleteOnCompletion = DefaultValues.BOOL;
                packet.XferID.UseBigPackets = DefaultValues.BOOL;
                packet.XferID.VFileID = DefaultValues.LLUUID;
                packet.XferID.VFileType = DefaultValues.S16;

            output(packet.ToBytes());
        }
        
        static void SendXferPacket_gen()
        {
            SendXferPacketPacket packet = new SendXferPacketPacket();
                packet.XferID.ID = DefaultValues.U64;
                packet.XferID.Packet = DefaultValues.U32;
                packet.DataPacket.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void ConfirmXferPacket_gen()
        {
            ConfirmXferPacketPacket packet = new ConfirmXferPacketPacket();
                packet.XferID.ID = DefaultValues.U64;
                packet.XferID.Packet = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AbortXfer_gen()
        {
            AbortXferPacket packet = new AbortXferPacket();
                packet.XferID.ID = DefaultValues.U64;
                packet.XferID.Result = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void AvatarAnimation_gen()
        {
            AvatarAnimationPacket packet = new AvatarAnimationPacket();
                packet.Sender.ID = DefaultValues.LLUUID;
            packet.AnimationList = new AvatarAnimationPacket.AnimationListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AnimationList[i] = new AvatarAnimationPacket.AnimationListBlock();
                packet.AnimationList[i].AnimID = DefaultValues.LLUUID;
                packet.AnimationList[i].AnimSequenceID = DefaultValues.S32;

	    }
            packet.AnimationSourceList = new AvatarAnimationPacket.AnimationSourceListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AnimationSourceList[i] = new AvatarAnimationPacket.AnimationSourceListBlock();
                packet.AnimationSourceList[i].ObjectID = DefaultValues.LLUUID;

	    }
            packet.PhysicalAvatarEventList = new AvatarAnimationPacket.PhysicalAvatarEventListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.PhysicalAvatarEventList[i] = new AvatarAnimationPacket.PhysicalAvatarEventListBlock();
                packet.PhysicalAvatarEventList[i].TypeData = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void AvatarAppearance_gen()
        {
            AvatarAppearancePacket packet = new AvatarAppearancePacket();
                packet.Sender.ID = DefaultValues.LLUUID;
                packet.Sender.IsTrial = DefaultValues.BOOL;
                packet.ObjectData.TextureEntry = DefaultValues.Variable2;
            packet.VisualParam = new AvatarAppearancePacket.VisualParamBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.VisualParam[i] = new AvatarAppearancePacket.VisualParamBlock();
                packet.VisualParam[i].ParamValue = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void AvatarSitResponse_gen()
        {
            AvatarSitResponsePacket packet = new AvatarSitResponsePacket();
                packet.SitObject.ID = DefaultValues.LLUUID;
                packet.SitTransform.AutoPilot = DefaultValues.BOOL;
                packet.SitTransform.SitPosition = DefaultValues.LLVector3;
                packet.SitTransform.SitRotation = DefaultValues.LLQuaternion;
                packet.SitTransform.CameraEyeOffset = DefaultValues.LLVector3;
                packet.SitTransform.CameraAtOffset = DefaultValues.LLVector3;
                packet.SitTransform.ForceMouselook = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void SetFollowCamProperties_gen()
        {
            SetFollowCamPropertiesPacket packet = new SetFollowCamPropertiesPacket();
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;
            packet.CameraProperty = new SetFollowCamPropertiesPacket.CameraPropertyBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.CameraProperty[i] = new SetFollowCamPropertiesPacket.CameraPropertyBlock();
                packet.CameraProperty[i].Type = DefaultValues.S32;
                packet.CameraProperty[i].Value = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void ClearFollowCamProperties_gen()
        {
            ClearFollowCamPropertiesPacket packet = new ClearFollowCamPropertiesPacket();
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void CameraConstraint_gen()
        {
            CameraConstraintPacket packet = new CameraConstraintPacket();
                packet.CameraCollidePlane.Plane = DefaultValues.LLVector4;

            output(packet.ToBytes());
        }
        
        static void ObjectProperties_gen()
        {
            ObjectPropertiesPacket packet = new ObjectPropertiesPacket();
            packet.ObjectData = new ObjectPropertiesPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectPropertiesPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectID = DefaultValues.LLUUID;
                packet.ObjectData[i].CreatorID = DefaultValues.LLUUID;
                packet.ObjectData[i].OwnerID = DefaultValues.LLUUID;
                packet.ObjectData[i].GroupID = DefaultValues.LLUUID;
                packet.ObjectData[i].CreationDate = DefaultValues.U64;
                packet.ObjectData[i].BaseMask = DefaultValues.U32;
                packet.ObjectData[i].OwnerMask = DefaultValues.U32;
                packet.ObjectData[i].GroupMask = DefaultValues.U32;
                packet.ObjectData[i].EveryoneMask = DefaultValues.U32;
                packet.ObjectData[i].NextOwnerMask = DefaultValues.U32;
                packet.ObjectData[i].OwnershipCost = DefaultValues.S32;
                packet.ObjectData[i].SaleType = DefaultValues.U8;
                packet.ObjectData[i].SalePrice = DefaultValues.S32;
                packet.ObjectData[i].AggregatePerms = DefaultValues.U8;
                packet.ObjectData[i].AggregatePermTextures = DefaultValues.U8;
                packet.ObjectData[i].AggregatePermTexturesOwner = DefaultValues.U8;
                packet.ObjectData[i].Category = DefaultValues.U32;
                packet.ObjectData[i].InventorySerial = DefaultValues.S16;
                packet.ObjectData[i].ItemID = DefaultValues.LLUUID;
                packet.ObjectData[i].FolderID = DefaultValues.LLUUID;
                packet.ObjectData[i].FromTaskID = DefaultValues.LLUUID;
                packet.ObjectData[i].LastOwnerID = DefaultValues.LLUUID;
                packet.ObjectData[i].Name = DefaultValues.Variable1;
                packet.ObjectData[i].Description = DefaultValues.Variable1;
                packet.ObjectData[i].TouchName = DefaultValues.Variable1;
                packet.ObjectData[i].SitName = DefaultValues.Variable1;
                packet.ObjectData[i].TextureID = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ObjectPropertiesFamily_gen()
        {
            ObjectPropertiesFamilyPacket packet = new ObjectPropertiesFamilyPacket();
                packet.ObjectData.RequestFlags = DefaultValues.U32;
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;
                packet.ObjectData.OwnerID = DefaultValues.LLUUID;
                packet.ObjectData.GroupID = DefaultValues.LLUUID;
                packet.ObjectData.BaseMask = DefaultValues.U32;
                packet.ObjectData.OwnerMask = DefaultValues.U32;
                packet.ObjectData.GroupMask = DefaultValues.U32;
                packet.ObjectData.EveryoneMask = DefaultValues.U32;
                packet.ObjectData.NextOwnerMask = DefaultValues.U32;
                packet.ObjectData.OwnershipCost = DefaultValues.S32;
                packet.ObjectData.SaleType = DefaultValues.U8;
                packet.ObjectData.SalePrice = DefaultValues.S32;
                packet.ObjectData.Category = DefaultValues.U32;
                packet.ObjectData.LastOwnerID = DefaultValues.LLUUID;
                packet.ObjectData.Name = DefaultValues.Variable1;
                packet.ObjectData.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void RequestPayPrice_gen()
        {
            RequestPayPricePacket packet = new RequestPayPricePacket();
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void PayPriceReply_gen()
        {
            PayPriceReplyPacket packet = new PayPriceReplyPacket();
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;
                packet.ObjectData.DefaultPayPrice = DefaultValues.S32;
            packet.ButtonData = new PayPriceReplyPacket.ButtonDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ButtonData[i] = new PayPriceReplyPacket.ButtonDataBlock();
                packet.ButtonData[i].PayButton = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void KickUser_gen()
        {
            KickUserPacket packet = new KickUserPacket();
                packet.TargetBlock.TargetIP = DefaultValues.IPADDR;
                packet.TargetBlock.TargetPort = DefaultValues.IPPORT;
                packet.UserInfo.AgentID = DefaultValues.LLUUID;
                packet.UserInfo.SessionID = DefaultValues.LLUUID;
                packet.UserInfo.Reason = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void KickUserAck_gen()
        {
            KickUserAckPacket packet = new KickUserAckPacket();
                packet.UserInfo.SessionID = DefaultValues.LLUUID;
                packet.UserInfo.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void GodKickUser_gen()
        {
            GodKickUserPacket packet = new GodKickUserPacket();
                packet.UserInfo.GodID = DefaultValues.LLUUID;
                packet.UserInfo.GodSessionID = DefaultValues.LLUUID;
                packet.UserInfo.AgentID = DefaultValues.LLUUID;
                packet.UserInfo.KickFlags = DefaultValues.U32;
                packet.UserInfo.Reason = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void EjectUser_gen()
        {
            EjectUserPacket packet = new EjectUserPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.TargetID = DefaultValues.LLUUID;
                packet.Data.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void FreezeUser_gen()
        {
            FreezeUserPacket packet = new FreezeUserPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.TargetID = DefaultValues.LLUUID;
                packet.Data.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AvatarPropertiesRequest_gen()
        {
            AvatarPropertiesRequestPacket packet = new AvatarPropertiesRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AvatarID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AvatarPropertiesReply_gen()
        {
            AvatarPropertiesReplyPacket packet = new AvatarPropertiesReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.AvatarID = DefaultValues.LLUUID;
                packet.PropertiesData.ImageID = DefaultValues.LLUUID;
                packet.PropertiesData.FLImageID = DefaultValues.LLUUID;
                packet.PropertiesData.PartnerID = DefaultValues.LLUUID;
                packet.PropertiesData.AboutText = DefaultValues.Variable2;
                packet.PropertiesData.FLAboutText = DefaultValues.Variable1;
                packet.PropertiesData.BornOn = DefaultValues.Variable1;
                packet.PropertiesData.ProfileURL = DefaultValues.Variable1;
                packet.PropertiesData.CharterMember = DefaultValues.Variable1;
                packet.PropertiesData.Flags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AvatarInterestsReply_gen()
        {
            AvatarInterestsReplyPacket packet = new AvatarInterestsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.AvatarID = DefaultValues.LLUUID;
                packet.PropertiesData.WantToMask = DefaultValues.U32;
                packet.PropertiesData.WantToText = DefaultValues.Variable1;
                packet.PropertiesData.SkillsMask = DefaultValues.U32;
                packet.PropertiesData.SkillsText = DefaultValues.Variable1;
                packet.PropertiesData.LanguagesText = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AvatarGroupsReply_gen()
        {
            AvatarGroupsReplyPacket packet = new AvatarGroupsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.AvatarID = DefaultValues.LLUUID;
            packet.GroupData = new AvatarGroupsReplyPacket.GroupDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.GroupData[i] = new AvatarGroupsReplyPacket.GroupDataBlock();
                packet.GroupData[i].GroupPowers = DefaultValues.U64;
                packet.GroupData[i].AcceptNotices = DefaultValues.BOOL;
                packet.GroupData[i].GroupTitle = DefaultValues.Variable1;
                packet.GroupData[i].GroupID = DefaultValues.LLUUID;
                packet.GroupData[i].GroupName = DefaultValues.Variable1;
                packet.GroupData[i].GroupInsigniaID = DefaultValues.LLUUID;

	    }
                packet.NewGroupData.ListInProfile = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void AvatarPropertiesUpdate_gen()
        {
            AvatarPropertiesUpdatePacket packet = new AvatarPropertiesUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.PropertiesData.ImageID = DefaultValues.LLUUID;
                packet.PropertiesData.FLImageID = DefaultValues.LLUUID;
                packet.PropertiesData.AboutText = DefaultValues.Variable2;
                packet.PropertiesData.FLAboutText = DefaultValues.Variable1;
                packet.PropertiesData.AllowPublish = DefaultValues.BOOL;
                packet.PropertiesData.MaturePublish = DefaultValues.BOOL;
                packet.PropertiesData.ProfileURL = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AvatarInterestsUpdate_gen()
        {
            AvatarInterestsUpdatePacket packet = new AvatarInterestsUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.PropertiesData.WantToMask = DefaultValues.U32;
                packet.PropertiesData.WantToText = DefaultValues.Variable1;
                packet.PropertiesData.SkillsMask = DefaultValues.U32;
                packet.PropertiesData.SkillsText = DefaultValues.Variable1;
                packet.PropertiesData.LanguagesText = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AvatarNotesReply_gen()
        {
            AvatarNotesReplyPacket packet = new AvatarNotesReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.TargetID = DefaultValues.LLUUID;
                packet.Data.Notes = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void AvatarNotesUpdate_gen()
        {
            AvatarNotesUpdatePacket packet = new AvatarNotesUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.TargetID = DefaultValues.LLUUID;
                packet.Data.Notes = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void AvatarPicksReply_gen()
        {
            AvatarPicksReplyPacket packet = new AvatarPicksReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.TargetID = DefaultValues.LLUUID;
            packet.Data = new AvatarPicksReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new AvatarPicksReplyPacket.DataBlock();
                packet.Data[i].PickID = DefaultValues.LLUUID;
                packet.Data[i].PickName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void EventInfoRequest_gen()
        {
            EventInfoRequestPacket packet = new EventInfoRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void EventInfoReply_gen()
        {
            EventInfoReplyPacket packet = new EventInfoReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;
                packet.EventData.Creator = DefaultValues.Variable1;
                packet.EventData.Name = DefaultValues.Variable1;
                packet.EventData.Category = DefaultValues.Variable1;
                packet.EventData.Desc = DefaultValues.Variable2;
                packet.EventData.Date = DefaultValues.Variable1;
                packet.EventData.DateUTC = DefaultValues.U32;
                packet.EventData.Duration = DefaultValues.U32;
                packet.EventData.Cover = DefaultValues.U32;
                packet.EventData.Amount = DefaultValues.U32;
                packet.EventData.SimName = DefaultValues.Variable1;
                packet.EventData.GlobalPos = DefaultValues.LLVector3d;
                packet.EventData.EventFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void EventNotificationAddRequest_gen()
        {
            EventNotificationAddRequestPacket packet = new EventNotificationAddRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void EventNotificationRemoveRequest_gen()
        {
            EventNotificationRemoveRequestPacket packet = new EventNotificationRemoveRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void EventGodDelete_gen()
        {
            EventGodDeletePacket packet = new EventGodDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryText = DefaultValues.Variable1;
                packet.QueryData.QueryFlags = DefaultValues.U32;
                packet.QueryData.QueryStart = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void PickInfoReply_gen()
        {
            PickInfoReplyPacket packet = new PickInfoReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.PickID = DefaultValues.LLUUID;
                packet.Data.CreatorID = DefaultValues.LLUUID;
                packet.Data.TopPick = DefaultValues.BOOL;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.Name = DefaultValues.Variable1;
                packet.Data.Desc = DefaultValues.Variable2;
                packet.Data.SnapshotID = DefaultValues.LLUUID;
                packet.Data.User = DefaultValues.Variable1;
                packet.Data.OriginalName = DefaultValues.Variable1;
                packet.Data.SimName = DefaultValues.Variable1;
                packet.Data.PosGlobal = DefaultValues.LLVector3d;
                packet.Data.SortOrder = DefaultValues.S32;
                packet.Data.Enabled = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void PickInfoUpdate_gen()
        {
            PickInfoUpdatePacket packet = new PickInfoUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.PickID = DefaultValues.LLUUID;
                packet.Data.CreatorID = DefaultValues.LLUUID;
                packet.Data.TopPick = DefaultValues.BOOL;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.Name = DefaultValues.Variable1;
                packet.Data.Desc = DefaultValues.Variable2;
                packet.Data.SnapshotID = DefaultValues.LLUUID;
                packet.Data.PosGlobal = DefaultValues.LLVector3d;
                packet.Data.SortOrder = DefaultValues.S32;
                packet.Data.Enabled = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void PickDelete_gen()
        {
            PickDeletePacket packet = new PickDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.PickID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void PickGodDelete_gen()
        {
            PickGodDeletePacket packet = new PickGodDeletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.PickID = DefaultValues.LLUUID;
                packet.Data.QueryID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ScriptQuestion_gen()
        {
            ScriptQuestionPacket packet = new ScriptQuestionPacket();
                packet.Data.TaskID = DefaultValues.LLUUID;
                packet.Data.ItemID = DefaultValues.LLUUID;
                packet.Data.ObjectName = DefaultValues.Variable1;
                packet.Data.ObjectOwner = DefaultValues.Variable1;
                packet.Data.Questions = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ScriptControlChange_gen()
        {
            ScriptControlChangePacket packet = new ScriptControlChangePacket();
            packet.Data = new ScriptControlChangePacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new ScriptControlChangePacket.DataBlock();
                packet.Data[i].TakeControls = DefaultValues.BOOL;
                packet.Data[i].Controls = DefaultValues.U32;
                packet.Data[i].PassToAgent = DefaultValues.BOOL;

	    }

            output(packet.ToBytes());
        }
        
        static void ScriptDialog_gen()
        {
            ScriptDialogPacket packet = new ScriptDialogPacket();
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.FirstName = DefaultValues.Variable1;
                packet.Data.LastName = DefaultValues.Variable1;
                packet.Data.ObjectName = DefaultValues.Variable1;
                packet.Data.Message = DefaultValues.Variable2;
                packet.Data.ChatChannel = DefaultValues.S32;
                packet.Data.ImageID = DefaultValues.LLUUID;
            packet.Buttons = new ScriptDialogPacket.ButtonsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Buttons[i] = new ScriptDialogPacket.ButtonsBlock();
                packet.Buttons[i].ButtonLabel = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ScriptDialogReply_gen()
        {
            ScriptDialogReplyPacket packet = new ScriptDialogReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.ChatChannel = DefaultValues.S32;
                packet.Data.ButtonIndex = DefaultValues.S32;
                packet.Data.ButtonLabel = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void ForceScriptControlRelease_gen()
        {
            ForceScriptControlReleasePacket packet = new ForceScriptControlReleasePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RevokePermissions_gen()
        {
            RevokePermissionsPacket packet = new RevokePermissionsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.ObjectPermissions = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void LoadURL_gen()
        {
            LoadURLPacket packet = new LoadURLPacket();
                packet.Data.ObjectName = DefaultValues.Variable1;
                packet.Data.ObjectID = DefaultValues.LLUUID;
                packet.Data.OwnerID = DefaultValues.LLUUID;
                packet.Data.OwnerIsGroup = DefaultValues.BOOL;
                packet.Data.Message = DefaultValues.Variable1;
                packet.Data.URL = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void ScriptTeleportRequest_gen()
        {
            ScriptTeleportRequestPacket packet = new ScriptTeleportRequestPacket();
                packet.Data.ObjectName = DefaultValues.Variable1;
                packet.Data.SimName = DefaultValues.Variable1;
                packet.Data.SimPosition = DefaultValues.LLVector3;
                packet.Data.LookAt = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void ParcelOverlay_gen()
        {
            ParcelOverlayPacket packet = new ParcelOverlayPacket();
                packet.ParcelData.SequenceID = DefaultValues.S32;
                packet.ParcelData.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void ParcelPropertiesRequest_gen()
        {
            ParcelPropertiesRequestPacket packet = new ParcelPropertiesRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.SequenceID = DefaultValues.S32;
                packet.ParcelData.West = DefaultValues.F32;
                packet.ParcelData.South = DefaultValues.F32;
                packet.ParcelData.East = DefaultValues.F32;
                packet.ParcelData.North = DefaultValues.F32;
                packet.ParcelData.SnapSelection = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ParcelPropertiesRequestByID_gen()
        {
            ParcelPropertiesRequestByIDPacket packet = new ParcelPropertiesRequestByIDPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.SequenceID = DefaultValues.S32;
                packet.ParcelData.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelProperties_gen()
        {
            ParcelPropertiesPacket packet = new ParcelPropertiesPacket();
                packet.ParcelData.RequestResult = DefaultValues.S32;
                packet.ParcelData.SequenceID = DefaultValues.S32;
                packet.ParcelData.SnapSelection = DefaultValues.BOOL;
                packet.ParcelData.SelfCount = DefaultValues.S32;
                packet.ParcelData.OtherCount = DefaultValues.S32;
                packet.ParcelData.PublicCount = DefaultValues.S32;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.OwnerID = DefaultValues.LLUUID;
                packet.ParcelData.IsGroupOwned = DefaultValues.BOOL;
                packet.ParcelData.AuctionID = DefaultValues.U32;
                packet.ParcelData.ClaimDate = DefaultValues.S32;
                packet.ParcelData.ClaimPrice = DefaultValues.S32;
                packet.ParcelData.RentPrice = DefaultValues.S32;
                packet.ParcelData.AABBMin = DefaultValues.LLVector3;
                packet.ParcelData.AABBMax = DefaultValues.LLVector3;
                packet.ParcelData.Bitmap = DefaultValues.Variable2;
                packet.ParcelData.Area = DefaultValues.S32;
                packet.ParcelData.Status = DefaultValues.U8;
                packet.ParcelData.SimWideMaxPrims = DefaultValues.S32;
                packet.ParcelData.SimWideTotalPrims = DefaultValues.S32;
                packet.ParcelData.MaxPrims = DefaultValues.S32;
                packet.ParcelData.TotalPrims = DefaultValues.S32;
                packet.ParcelData.OwnerPrims = DefaultValues.S32;
                packet.ParcelData.GroupPrims = DefaultValues.S32;
                packet.ParcelData.OtherPrims = DefaultValues.S32;
                packet.ParcelData.SelectedPrims = DefaultValues.S32;
                packet.ParcelData.ParcelPrimBonus = DefaultValues.F32;
                packet.ParcelData.OtherCleanTime = DefaultValues.S32;
                packet.ParcelData.ParcelFlags = DefaultValues.U32;
                packet.ParcelData.SalePrice = DefaultValues.S32;
                packet.ParcelData.Name = DefaultValues.Variable1;
                packet.ParcelData.Desc = DefaultValues.Variable1;
                packet.ParcelData.MusicURL = DefaultValues.Variable1;
                packet.ParcelData.MediaURL = DefaultValues.Variable1;
                packet.ParcelData.MediaID = DefaultValues.LLUUID;
                packet.ParcelData.MediaAutoScale = DefaultValues.U8;
                packet.ParcelData.GroupID = DefaultValues.LLUUID;
                packet.ParcelData.PassPrice = DefaultValues.S32;
                packet.ParcelData.PassHours = DefaultValues.F32;
                packet.ParcelData.Category = DefaultValues.U8;
                packet.ParcelData.AuthBuyerID = DefaultValues.LLUUID;
                packet.ParcelData.SnapshotID = DefaultValues.LLUUID;
                packet.ParcelData.UserLocation = DefaultValues.LLVector3;
                packet.ParcelData.UserLookAt = DefaultValues.LLVector3;
                packet.ParcelData.LandingType = DefaultValues.U8;
                packet.ParcelData.RegionPushOverride = DefaultValues.BOOL;
                packet.ParcelData.RegionDenyAnonymous = DefaultValues.BOOL;
                packet.ParcelData.RegionDenyIdentified = DefaultValues.BOOL;
                packet.ParcelData.RegionDenyTransacted = DefaultValues.BOOL;
                packet.AgeVerificationBlock.RegionDenyAgeUnverified = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ParcelPropertiesUpdate_gen()
        {
            ParcelPropertiesUpdatePacket packet = new ParcelPropertiesUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.Flags = DefaultValues.U32;
                packet.ParcelData.ParcelFlags = DefaultValues.U32;
                packet.ParcelData.SalePrice = DefaultValues.S32;
                packet.ParcelData.Name = DefaultValues.Variable1;
                packet.ParcelData.Desc = DefaultValues.Variable1;
                packet.ParcelData.MusicURL = DefaultValues.Variable1;
                packet.ParcelData.MediaURL = DefaultValues.Variable1;
                packet.ParcelData.MediaID = DefaultValues.LLUUID;
                packet.ParcelData.MediaAutoScale = DefaultValues.U8;
                packet.ParcelData.GroupID = DefaultValues.LLUUID;
                packet.ParcelData.PassPrice = DefaultValues.S32;
                packet.ParcelData.PassHours = DefaultValues.F32;
                packet.ParcelData.Category = DefaultValues.U8;
                packet.ParcelData.AuthBuyerID = DefaultValues.LLUUID;
                packet.ParcelData.SnapshotID = DefaultValues.LLUUID;
                packet.ParcelData.UserLocation = DefaultValues.LLVector3;
                packet.ParcelData.UserLookAt = DefaultValues.LLVector3;
                packet.ParcelData.LandingType = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void ParcelReturnObjects_gen()
        {
            ParcelReturnObjectsPacket packet = new ParcelReturnObjectsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.ReturnType = DefaultValues.U32;
            packet.TaskIDs = new ParcelReturnObjectsPacket.TaskIDsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.TaskIDs[i] = new ParcelReturnObjectsPacket.TaskIDsBlock();
                packet.TaskIDs[i].TaskID = DefaultValues.LLUUID;

	    }
            packet.OwnerIDs = new ParcelReturnObjectsPacket.OwnerIDsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.OwnerIDs[i] = new ParcelReturnObjectsPacket.OwnerIDsBlock();
                packet.OwnerIDs[i].OwnerID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelSetOtherCleanTime_gen()
        {
            ParcelSetOtherCleanTimePacket packet = new ParcelSetOtherCleanTimePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.OtherCleanTime = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelDisableObjects_gen()
        {
            ParcelDisableObjectsPacket packet = new ParcelDisableObjectsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.ReturnType = DefaultValues.U32;
            packet.TaskIDs = new ParcelDisableObjectsPacket.TaskIDsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.TaskIDs[i] = new ParcelDisableObjectsPacket.TaskIDsBlock();
                packet.TaskIDs[i].TaskID = DefaultValues.LLUUID;

	    }
            packet.OwnerIDs = new ParcelDisableObjectsPacket.OwnerIDsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.OwnerIDs[i] = new ParcelDisableObjectsPacket.OwnerIDsBlock();
                packet.OwnerIDs[i].OwnerID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelSelectObjects_gen()
        {
            ParcelSelectObjectsPacket packet = new ParcelSelectObjectsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.ReturnType = DefaultValues.U32;
            packet.ReturnIDs = new ParcelSelectObjectsPacket.ReturnIDsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ReturnIDs[i] = new ParcelSelectObjectsPacket.ReturnIDsBlock();
                packet.ReturnIDs[i].ReturnID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void EstateCovenantRequest_gen()
        {
            EstateCovenantRequestPacket packet = new EstateCovenantRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void EstateCovenantReply_gen()
        {
            EstateCovenantReplyPacket packet = new EstateCovenantReplyPacket();
                packet.Data.CovenantID = DefaultValues.LLUUID;
                packet.Data.CovenantTimestamp = DefaultValues.U32;
                packet.Data.EstateName = DefaultValues.Variable1;
                packet.Data.EstateOwnerID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ForceObjectSelect_gen()
        {
            ForceObjectSelectPacket packet = new ForceObjectSelectPacket();
                packet._Header.ResetList = DefaultValues.BOOL;
            packet.Data = new ForceObjectSelectPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new ForceObjectSelectPacket.DataBlock();
                packet.Data[i].LocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelBuyPass_gen()
        {
            ParcelBuyPassPacket packet = new ParcelBuyPassPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelDeedToGroup_gen()
        {
            ParcelDeedToGroupPacket packet = new ParcelDeedToGroupPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelReclaim_gen()
        {
            ParcelReclaimPacket packet = new ParcelReclaimPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelClaim_gen()
        {
            ParcelClaimPacket packet = new ParcelClaimPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;
                packet.Data.IsGroupOwned = DefaultValues.BOOL;
                packet.Data.Final = DefaultValues.BOOL;
            packet.ParcelData = new ParcelClaimPacket.ParcelDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParcelData[i] = new ParcelClaimPacket.ParcelDataBlock();
                packet.ParcelData[i].West = DefaultValues.F32;
                packet.ParcelData[i].South = DefaultValues.F32;
                packet.ParcelData[i].East = DefaultValues.F32;
                packet.ParcelData[i].North = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelJoin_gen()
        {
            ParcelJoinPacket packet = new ParcelJoinPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.West = DefaultValues.F32;
                packet.ParcelData.South = DefaultValues.F32;
                packet.ParcelData.East = DefaultValues.F32;
                packet.ParcelData.North = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void ParcelDivide_gen()
        {
            ParcelDividePacket packet = new ParcelDividePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.West = DefaultValues.F32;
                packet.ParcelData.South = DefaultValues.F32;
                packet.ParcelData.East = DefaultValues.F32;
                packet.ParcelData.North = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void ParcelRelease_gen()
        {
            ParcelReleasePacket packet = new ParcelReleasePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelBuy_gen()
        {
            ParcelBuyPacket packet = new ParcelBuyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;
                packet.Data.IsGroupOwned = DefaultValues.BOOL;
                packet.Data.RemoveContribution = DefaultValues.BOOL;
                packet.Data.LocalID = DefaultValues.S32;
                packet.Data.Final = DefaultValues.BOOL;
                packet.ParcelData.Price = DefaultValues.S32;
                packet.ParcelData.Area = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelGodForceOwner_gen()
        {
            ParcelGodForceOwnerPacket packet = new ParcelGodForceOwnerPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.OwnerID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelAccessListRequest_gen()
        {
            ParcelAccessListRequestPacket packet = new ParcelAccessListRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.SequenceID = DefaultValues.S32;
                packet.Data.Flags = DefaultValues.U32;
                packet.Data.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ParcelAccessListReply_gen()
        {
            ParcelAccessListReplyPacket packet = new ParcelAccessListReplyPacket();
                packet.Data.AgentID = DefaultValues.LLUUID;
                packet.Data.SequenceID = DefaultValues.S32;
                packet.Data.Flags = DefaultValues.U32;
                packet.Data.LocalID = DefaultValues.S32;
            packet.List = new ParcelAccessListReplyPacket.ListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.List[i] = new ParcelAccessListReplyPacket.ListBlock();
                packet.List[i].ID = DefaultValues.LLUUID;
                packet.List[i].Time = DefaultValues.S32;
                packet.List[i].Flags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelAccessListUpdate_gen()
        {
            ParcelAccessListUpdatePacket packet = new ParcelAccessListUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.Flags = DefaultValues.U32;
                packet.Data.LocalID = DefaultValues.S32;
                packet.Data.TransactionID = DefaultValues.LLUUID;
                packet.Data.SequenceID = DefaultValues.S32;
                packet.Data.Sections = DefaultValues.S32;
            packet.List = new ParcelAccessListUpdatePacket.ListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.List[i] = new ParcelAccessListUpdatePacket.ListBlock();
                packet.List[i].ID = DefaultValues.LLUUID;
                packet.List[i].Time = DefaultValues.S32;
                packet.List[i].Flags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void ParcelDwellRequest_gen()
        {
            ParcelDwellRequestPacket packet = new ParcelDwellRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;
                packet.Data.ParcelID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ParcelDwellReply_gen()
        {
            ParcelDwellReplyPacket packet = new ParcelDwellReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.LocalID = DefaultValues.S32;
                packet.Data.ParcelID = DefaultValues.LLUUID;
                packet.Data.Dwell = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void ParcelGodMarkAsContent_gen()
        {
            ParcelGodMarkAsContentPacket packet = new ParcelGodMarkAsContentPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void ViewerStartAuction_gen()
        {
            ViewerStartAuctionPacket packet = new ViewerStartAuctionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;
                packet.ParcelData.SnapshotID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void UUIDNameRequest_gen()
        {
            UUIDNameRequestPacket packet = new UUIDNameRequestPacket();
            packet.UUIDNameBlock = new UUIDNameRequestPacket.UUIDNameBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.UUIDNameBlock[i] = new UUIDNameRequestPacket.UUIDNameBlockBlock();
                packet.UUIDNameBlock[i].ID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void UUIDNameReply_gen()
        {
            UUIDNameReplyPacket packet = new UUIDNameReplyPacket();
            packet.UUIDNameBlock = new UUIDNameReplyPacket.UUIDNameBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.UUIDNameBlock[i] = new UUIDNameReplyPacket.UUIDNameBlockBlock();
                packet.UUIDNameBlock[i].ID = DefaultValues.LLUUID;
                packet.UUIDNameBlock[i].FirstName = DefaultValues.Variable1;
                packet.UUIDNameBlock[i].LastName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void UUIDGroupNameRequest_gen()
        {
            UUIDGroupNameRequestPacket packet = new UUIDGroupNameRequestPacket();
            packet.UUIDNameBlock = new UUIDGroupNameRequestPacket.UUIDNameBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.UUIDNameBlock[i] = new UUIDGroupNameRequestPacket.UUIDNameBlockBlock();
                packet.UUIDNameBlock[i].ID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void UUIDGroupNameReply_gen()
        {
            UUIDGroupNameReplyPacket packet = new UUIDGroupNameReplyPacket();
            packet.UUIDNameBlock = new UUIDGroupNameReplyPacket.UUIDNameBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.UUIDNameBlock[i] = new UUIDGroupNameReplyPacket.UUIDNameBlockBlock();
                packet.UUIDNameBlock[i].ID = DefaultValues.LLUUID;
                packet.UUIDNameBlock[i].GroupName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void ChildAgentUpdate_gen()
        {
            ChildAgentUpdatePacket packet = new ChildAgentUpdatePacket();
                packet.AgentData.RegionHandle = DefaultValues.U64;
                packet.AgentData.ViewerCircuitCode = DefaultValues.U32;
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AgentPos = DefaultValues.LLVector3;
                packet.AgentData.AgentVel = DefaultValues.LLVector3;
                packet.AgentData.Center = DefaultValues.LLVector3;
                packet.AgentData.Size = DefaultValues.LLVector3;
                packet.AgentData.AtAxis = DefaultValues.LLVector3;
                packet.AgentData.LeftAxis = DefaultValues.LLVector3;
                packet.AgentData.UpAxis = DefaultValues.LLVector3;
                packet.AgentData.ChangedGrid = DefaultValues.BOOL;
                packet.AgentData.Far = DefaultValues.F32;
                packet.AgentData.Aspect = DefaultValues.F32;
                packet.AgentData.Throttles = DefaultValues.Variable1;
                packet.AgentData.LocomotionState = DefaultValues.U32;
                packet.AgentData.HeadRotation = DefaultValues.LLQuaternion;
                packet.AgentData.BodyRotation = DefaultValues.LLQuaternion;
                packet.AgentData.ControlFlags = DefaultValues.U32;
                packet.AgentData.EnergyLevel = DefaultValues.F32;
                packet.AgentData.GodLevel = DefaultValues.U8;
                packet.AgentData.AlwaysRun = DefaultValues.BOOL;
                packet.AgentData.PreyAgent = DefaultValues.LLUUID;
                packet.AgentData.AgentAccess = DefaultValues.U8;
                packet.AgentData.AgentTextures = DefaultValues.Variable2;
                packet.AgentData.ActiveGroupID = DefaultValues.LLUUID;
            packet.GroupData = new ChildAgentUpdatePacket.GroupDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.GroupData[i] = new ChildAgentUpdatePacket.GroupDataBlock();
                packet.GroupData[i].GroupID = DefaultValues.LLUUID;
                packet.GroupData[i].GroupPowers = DefaultValues.U64;
                packet.GroupData[i].AcceptNotices = DefaultValues.BOOL;

	    }
            packet.AnimationData = new ChildAgentUpdatePacket.AnimationDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AnimationData[i] = new ChildAgentUpdatePacket.AnimationDataBlock();
                packet.AnimationData[i].Animation = DefaultValues.LLUUID;
                packet.AnimationData[i].ObjectID = DefaultValues.LLUUID;

	    }
            packet.GranterBlock = new ChildAgentUpdatePacket.GranterBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.GranterBlock[i] = new ChildAgentUpdatePacket.GranterBlockBlock();
                packet.GranterBlock[i].GranterID = DefaultValues.LLUUID;

	    }
            packet.NVPairData = new ChildAgentUpdatePacket.NVPairDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.NVPairData[i] = new ChildAgentUpdatePacket.NVPairDataBlock();
                packet.NVPairData[i].NVPairs = DefaultValues.Variable2;

	    }
            packet.VisualParam = new ChildAgentUpdatePacket.VisualParamBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.VisualParam[i] = new ChildAgentUpdatePacket.VisualParamBlock();
                packet.VisualParam[i].ParamValue = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void ChildAgentAlive_gen()
        {
            ChildAgentAlivePacket packet = new ChildAgentAlivePacket();
                packet.AgentData.RegionHandle = DefaultValues.U64;
                packet.AgentData.ViewerCircuitCode = DefaultValues.U32;
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ChildAgentPositionUpdate_gen()
        {
            ChildAgentPositionUpdatePacket packet = new ChildAgentPositionUpdatePacket();
                packet.AgentData.RegionHandle = DefaultValues.U64;
                packet.AgentData.ViewerCircuitCode = DefaultValues.U32;
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AgentPos = DefaultValues.LLVector3;
                packet.AgentData.AgentVel = DefaultValues.LLVector3;
                packet.AgentData.Center = DefaultValues.LLVector3;
                packet.AgentData.Size = DefaultValues.LLVector3;
                packet.AgentData.AtAxis = DefaultValues.LLVector3;
                packet.AgentData.LeftAxis = DefaultValues.LLVector3;
                packet.AgentData.UpAxis = DefaultValues.LLVector3;
                packet.AgentData.ChangedGrid = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ChildAgentDying_gen()
        {
            ChildAgentDyingPacket packet = new ChildAgentDyingPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ChildAgentUnknown_gen()
        {
            ChildAgentUnknownPacket packet = new ChildAgentUnknownPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GetScriptRunning_gen()
        {
            GetScriptRunningPacket packet = new GetScriptRunningPacket();
                packet.Script.ObjectID = DefaultValues.LLUUID;
                packet.Script.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ScriptRunningReply_gen()
        {
            ScriptRunningReplyPacket packet = new ScriptRunningReplyPacket();
                packet.Script.ObjectID = DefaultValues.LLUUID;
                packet.Script.ItemID = DefaultValues.LLUUID;
                packet.Script.Running = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void SetScriptRunning_gen()
        {
            SetScriptRunningPacket packet = new SetScriptRunningPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Script.ObjectID = DefaultValues.LLUUID;
                packet.Script.ItemID = DefaultValues.LLUUID;
                packet.Script.Running = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ScriptReset_gen()
        {
            ScriptResetPacket packet = new ScriptResetPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Script.ObjectID = DefaultValues.LLUUID;
                packet.Script.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ScriptSensorRequest_gen()
        {
            ScriptSensorRequestPacket packet = new ScriptSensorRequestPacket();
                packet.Requester.SourceID = DefaultValues.LLUUID;
                packet.Requester.RequestID = DefaultValues.LLUUID;
                packet.Requester.SearchID = DefaultValues.LLUUID;
                packet.Requester.SearchPos = DefaultValues.LLVector3;
                packet.Requester.SearchDir = DefaultValues.LLQuaternion;
                packet.Requester.SearchName = DefaultValues.Variable1;
                packet.Requester.Type = DefaultValues.S32;
                packet.Requester.Range = DefaultValues.F32;
                packet.Requester.Arc = DefaultValues.F32;
                packet.Requester.RegionHandle = DefaultValues.U64;
                packet.Requester.SearchRegions = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void ScriptSensorReply_gen()
        {
            ScriptSensorReplyPacket packet = new ScriptSensorReplyPacket();
                packet.Requester.SourceID = DefaultValues.LLUUID;
            packet.SensedData = new ScriptSensorReplyPacket.SensedDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.SensedData[i] = new ScriptSensorReplyPacket.SensedDataBlock();
                packet.SensedData[i].ObjectID = DefaultValues.LLUUID;
                packet.SensedData[i].OwnerID = DefaultValues.LLUUID;
                packet.SensedData[i].GroupID = DefaultValues.LLUUID;
                packet.SensedData[i].Position = DefaultValues.LLVector3;
                packet.SensedData[i].Velocity = DefaultValues.LLVector3;
                packet.SensedData[i].Rotation = DefaultValues.LLQuaternion;
                packet.SensedData[i].Name = DefaultValues.Variable1;
                packet.SensedData[i].Type = DefaultValues.S32;
                packet.SensedData[i].Range = DefaultValues.F32;

	    }

            output(packet.ToBytes());
        }
        
        static void CompleteAgentMovement_gen()
        {
            CompleteAgentMovementPacket packet = new CompleteAgentMovementPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.CircuitCode = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void AgentMovementComplete_gen()
        {
            AgentMovementCompletePacket packet = new AgentMovementCompletePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.Position = DefaultValues.LLVector3;
                packet.Data.LookAt = DefaultValues.LLVector3;
                packet.Data.RegionHandle = DefaultValues.U64;
                packet.Data.Timestamp = DefaultValues.U32;
                packet.SimData.ChannelVersion = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void LogoutRequest_gen()
        {
            LogoutRequestPacket packet = new LogoutRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void LogoutReply_gen()
        {
            LogoutReplyPacket packet = new LogoutReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.InventoryData = new LogoutReplyPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new LogoutReplyPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ImprovedInstantMessage_gen()
        {
            ImprovedInstantMessagePacket packet = new ImprovedInstantMessagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MessageBlock.FromGroup = DefaultValues.BOOL;
                packet.MessageBlock.ToAgentID = DefaultValues.LLUUID;
                packet.MessageBlock.ParentEstateID = DefaultValues.U32;
                packet.MessageBlock.RegionID = DefaultValues.LLUUID;
                packet.MessageBlock.Position = DefaultValues.LLVector3;
                packet.MessageBlock.Offline = DefaultValues.U8;
                packet.MessageBlock.Dialog = DefaultValues.U8;
                packet.MessageBlock.ID = DefaultValues.LLUUID;
                packet.MessageBlock.Timestamp = DefaultValues.U32;
                packet.MessageBlock.FromAgentName = DefaultValues.Variable1;
                packet.MessageBlock.Message = DefaultValues.Variable2;
                packet.MessageBlock.BinaryBucket = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void RetrieveInstantMessages_gen()
        {
            RetrieveInstantMessagesPacket packet = new RetrieveInstantMessagesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void FindAgent_gen()
        {
            FindAgentPacket packet = new FindAgentPacket();
                packet.AgentBlock.Hunter = DefaultValues.LLUUID;
                packet.AgentBlock.Prey = DefaultValues.LLUUID;
                packet.AgentBlock.SpaceIP = DefaultValues.IPADDR;
            packet.LocationBlock = new FindAgentPacket.LocationBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.LocationBlock[i] = new FindAgentPacket.LocationBlockBlock();
                packet.LocationBlock[i].GlobalX = DefaultValues.F64;
                packet.LocationBlock[i].GlobalY = DefaultValues.F64;

	    }

            output(packet.ToBytes());
        }
        
        static void RequestGodlikePowers_gen()
        {
            RequestGodlikePowersPacket packet = new RequestGodlikePowersPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RequestBlock.Godlike = DefaultValues.BOOL;
                packet.RequestBlock.Token = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GrantGodlikePowers_gen()
        {
            GrantGodlikePowersPacket packet = new GrantGodlikePowersPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GrantData.GodLevel = DefaultValues.U8;
                packet.GrantData.Token = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GodlikeMessage_gen()
        {
            GodlikeMessagePacket packet = new GodlikeMessagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
                packet.MethodData.Method = DefaultValues.Variable1;
                packet.MethodData.Invoice = DefaultValues.LLUUID;
            packet.ParamList = new GodlikeMessagePacket.ParamListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParamList[i] = new GodlikeMessagePacket.ParamListBlock();
                packet.ParamList[i].Parameter = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void EstateOwnerMessage_gen()
        {
            EstateOwnerMessagePacket packet = new EstateOwnerMessagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
                packet.MethodData.Method = DefaultValues.Variable1;
                packet.MethodData.Invoice = DefaultValues.LLUUID;
            packet.ParamList = new EstateOwnerMessagePacket.ParamListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParamList[i] = new EstateOwnerMessagePacket.ParamListBlock();
                packet.ParamList[i].Parameter = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void GenericMessage_gen()
        {
            GenericMessagePacket packet = new GenericMessagePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
                packet.MethodData.Method = DefaultValues.Variable1;
                packet.MethodData.Invoice = DefaultValues.LLUUID;
            packet.ParamList = new GenericMessagePacket.ParamListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParamList[i] = new GenericMessagePacket.ParamListBlock();
                packet.ParamList[i].Parameter = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void MuteListRequest_gen()
        {
            MuteListRequestPacket packet = new MuteListRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MuteData.MuteCRC = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void UpdateMuteListEntry_gen()
        {
            UpdateMuteListEntryPacket packet = new UpdateMuteListEntryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MuteData.MuteID = DefaultValues.LLUUID;
                packet.MuteData.MuteName = DefaultValues.Variable1;
                packet.MuteData.MuteType = DefaultValues.S32;
                packet.MuteData.MuteFlags = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void RemoveMuteListEntry_gen()
        {
            RemoveMuteListEntryPacket packet = new RemoveMuteListEntryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MuteData.MuteID = DefaultValues.LLUUID;
                packet.MuteData.MuteName = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void CopyInventoryFromNotecard_gen()
        {
            CopyInventoryFromNotecardPacket packet = new CopyInventoryFromNotecardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.NotecardData.NotecardItemID = DefaultValues.LLUUID;
                packet.NotecardData.ObjectID = DefaultValues.LLUUID;
            packet.InventoryData = new CopyInventoryFromNotecardPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new CopyInventoryFromNotecardPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void UpdateInventoryItem_gen()
        {
            UpdateInventoryItemPacket packet = new UpdateInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
            packet.InventoryData = new UpdateInventoryItemPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new UpdateInventoryItemPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].CallbackID = DefaultValues.U32;
                packet.InventoryData[i].CreatorID = DefaultValues.LLUUID;
                packet.InventoryData[i].OwnerID = DefaultValues.LLUUID;
                packet.InventoryData[i].GroupID = DefaultValues.LLUUID;
                packet.InventoryData[i].BaseMask = DefaultValues.U32;
                packet.InventoryData[i].OwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupMask = DefaultValues.U32;
                packet.InventoryData[i].EveryoneMask = DefaultValues.U32;
                packet.InventoryData[i].NextOwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupOwned = DefaultValues.BOOL;
                packet.InventoryData[i].TransactionID = DefaultValues.LLUUID;
                packet.InventoryData[i].Type = DefaultValues.S8;
                packet.InventoryData[i].InvType = DefaultValues.S8;
                packet.InventoryData[i].Flags = DefaultValues.U32;
                packet.InventoryData[i].SaleType = DefaultValues.U8;
                packet.InventoryData[i].SalePrice = DefaultValues.S32;
                packet.InventoryData[i].Name = DefaultValues.Variable1;
                packet.InventoryData[i].Description = DefaultValues.Variable1;
                packet.InventoryData[i].CreationDate = DefaultValues.S32;
                packet.InventoryData[i].CRC = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void UpdateCreateInventoryItem_gen()
        {
            UpdateCreateInventoryItemPacket packet = new UpdateCreateInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SimApproved = DefaultValues.BOOL;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
            packet.InventoryData = new UpdateCreateInventoryItemPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new UpdateCreateInventoryItemPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].CallbackID = DefaultValues.U32;
                packet.InventoryData[i].CreatorID = DefaultValues.LLUUID;
                packet.InventoryData[i].OwnerID = DefaultValues.LLUUID;
                packet.InventoryData[i].GroupID = DefaultValues.LLUUID;
                packet.InventoryData[i].BaseMask = DefaultValues.U32;
                packet.InventoryData[i].OwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupMask = DefaultValues.U32;
                packet.InventoryData[i].EveryoneMask = DefaultValues.U32;
                packet.InventoryData[i].NextOwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupOwned = DefaultValues.BOOL;
                packet.InventoryData[i].AssetID = DefaultValues.LLUUID;
                packet.InventoryData[i].Type = DefaultValues.S8;
                packet.InventoryData[i].InvType = DefaultValues.S8;
                packet.InventoryData[i].Flags = DefaultValues.U32;
                packet.InventoryData[i].SaleType = DefaultValues.U8;
                packet.InventoryData[i].SalePrice = DefaultValues.S32;
                packet.InventoryData[i].Name = DefaultValues.Variable1;
                packet.InventoryData[i].Description = DefaultValues.Variable1;
                packet.InventoryData[i].CreationDate = DefaultValues.S32;
                packet.InventoryData[i].CRC = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void MoveInventoryItem_gen()
        {
            MoveInventoryItemPacket packet = new MoveInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Stamp = DefaultValues.BOOL;
            packet.InventoryData = new MoveInventoryItemPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new MoveInventoryItemPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].NewName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void CopyInventoryItem_gen()
        {
            CopyInventoryItemPacket packet = new CopyInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.InventoryData = new CopyInventoryItemPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new CopyInventoryItemPacket.InventoryDataBlock();
                packet.InventoryData[i].CallbackID = DefaultValues.U32;
                packet.InventoryData[i].OldAgentID = DefaultValues.LLUUID;
                packet.InventoryData[i].OldItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].NewFolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].NewName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void RemoveInventoryItem_gen()
        {
            RemoveInventoryItemPacket packet = new RemoveInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.InventoryData = new RemoveInventoryItemPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new RemoveInventoryItemPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void ChangeInventoryItemFlags_gen()
        {
            ChangeInventoryItemFlagsPacket packet = new ChangeInventoryItemFlagsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.InventoryData = new ChangeInventoryItemFlagsPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new ChangeInventoryItemFlagsPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].Flags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void SaveAssetIntoInventory_gen()
        {
            SaveAssetIntoInventoryPacket packet = new SaveAssetIntoInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.InventoryData.ItemID = DefaultValues.LLUUID;
                packet.InventoryData.NewAssetID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void CreateInventoryFolder_gen()
        {
            CreateInventoryFolderPacket packet = new CreateInventoryFolderPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.FolderData.FolderID = DefaultValues.LLUUID;
                packet.FolderData.ParentID = DefaultValues.LLUUID;
                packet.FolderData.Type = DefaultValues.S8;
                packet.FolderData.Name = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void UpdateInventoryFolder_gen()
        {
            UpdateInventoryFolderPacket packet = new UpdateInventoryFolderPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.FolderData = new UpdateInventoryFolderPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new UpdateInventoryFolderPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;
                packet.FolderData[i].ParentID = DefaultValues.LLUUID;
                packet.FolderData[i].Type = DefaultValues.S8;
                packet.FolderData[i].Name = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void MoveInventoryFolder_gen()
        {
            MoveInventoryFolderPacket packet = new MoveInventoryFolderPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Stamp = DefaultValues.BOOL;
            packet.InventoryData = new MoveInventoryFolderPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new MoveInventoryFolderPacket.InventoryDataBlock();
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].ParentID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void RemoveInventoryFolder_gen()
        {
            RemoveInventoryFolderPacket packet = new RemoveInventoryFolderPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.FolderData = new RemoveInventoryFolderPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new RemoveInventoryFolderPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void FetchInventoryDescendents_gen()
        {
            FetchInventoryDescendentsPacket packet = new FetchInventoryDescendentsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.InventoryData.FolderID = DefaultValues.LLUUID;
                packet.InventoryData.OwnerID = DefaultValues.LLUUID;
                packet.InventoryData.SortOrder = DefaultValues.S32;
                packet.InventoryData.FetchFolders = DefaultValues.BOOL;
                packet.InventoryData.FetchItems = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void InventoryDescendents_gen()
        {
            InventoryDescendentsPacket packet = new InventoryDescendentsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.FolderID = DefaultValues.LLUUID;
                packet.AgentData.OwnerID = DefaultValues.LLUUID;
                packet.AgentData.Version = DefaultValues.S32;
                packet.AgentData.Descendents = DefaultValues.S32;
            packet.FolderData = new InventoryDescendentsPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new InventoryDescendentsPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;
                packet.FolderData[i].ParentID = DefaultValues.LLUUID;
                packet.FolderData[i].Type = DefaultValues.S8;
                packet.FolderData[i].Name = DefaultValues.Variable1;

	    }
            packet.ItemData = new InventoryDescendentsPacket.ItemDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ItemData[i] = new InventoryDescendentsPacket.ItemDataBlock();
                packet.ItemData[i].ItemID = DefaultValues.LLUUID;
                packet.ItemData[i].FolderID = DefaultValues.LLUUID;
                packet.ItemData[i].CreatorID = DefaultValues.LLUUID;
                packet.ItemData[i].OwnerID = DefaultValues.LLUUID;
                packet.ItemData[i].GroupID = DefaultValues.LLUUID;
                packet.ItemData[i].BaseMask = DefaultValues.U32;
                packet.ItemData[i].OwnerMask = DefaultValues.U32;
                packet.ItemData[i].GroupMask = DefaultValues.U32;
                packet.ItemData[i].EveryoneMask = DefaultValues.U32;
                packet.ItemData[i].NextOwnerMask = DefaultValues.U32;
                packet.ItemData[i].GroupOwned = DefaultValues.BOOL;
                packet.ItemData[i].AssetID = DefaultValues.LLUUID;
                packet.ItemData[i].Type = DefaultValues.S8;
                packet.ItemData[i].InvType = DefaultValues.S8;
                packet.ItemData[i].Flags = DefaultValues.U32;
                packet.ItemData[i].SaleType = DefaultValues.U8;
                packet.ItemData[i].SalePrice = DefaultValues.S32;
                packet.ItemData[i].Name = DefaultValues.Variable1;
                packet.ItemData[i].Description = DefaultValues.Variable1;
                packet.ItemData[i].CreationDate = DefaultValues.S32;
                packet.ItemData[i].CRC = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void FetchInventory_gen()
        {
            FetchInventoryPacket packet = new FetchInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.InventoryData = new FetchInventoryPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new FetchInventoryPacket.InventoryDataBlock();
                packet.InventoryData[i].OwnerID = DefaultValues.LLUUID;
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void FetchInventoryReply_gen()
        {
            FetchInventoryReplyPacket packet = new FetchInventoryReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
            packet.InventoryData = new FetchInventoryReplyPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new FetchInventoryReplyPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;
                packet.InventoryData[i].FolderID = DefaultValues.LLUUID;
                packet.InventoryData[i].CreatorID = DefaultValues.LLUUID;
                packet.InventoryData[i].OwnerID = DefaultValues.LLUUID;
                packet.InventoryData[i].GroupID = DefaultValues.LLUUID;
                packet.InventoryData[i].BaseMask = DefaultValues.U32;
                packet.InventoryData[i].OwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupMask = DefaultValues.U32;
                packet.InventoryData[i].EveryoneMask = DefaultValues.U32;
                packet.InventoryData[i].NextOwnerMask = DefaultValues.U32;
                packet.InventoryData[i].GroupOwned = DefaultValues.BOOL;
                packet.InventoryData[i].AssetID = DefaultValues.LLUUID;
                packet.InventoryData[i].Type = DefaultValues.S8;
                packet.InventoryData[i].InvType = DefaultValues.S8;
                packet.InventoryData[i].Flags = DefaultValues.U32;
                packet.InventoryData[i].SaleType = DefaultValues.U8;
                packet.InventoryData[i].SalePrice = DefaultValues.S32;
                packet.InventoryData[i].Name = DefaultValues.Variable1;
                packet.InventoryData[i].Description = DefaultValues.Variable1;
                packet.InventoryData[i].CreationDate = DefaultValues.S32;
                packet.InventoryData[i].CRC = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void BulkUpdateInventory_gen()
        {
            BulkUpdateInventoryPacket packet = new BulkUpdateInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.TransactionID = DefaultValues.LLUUID;
            packet.FolderData = new BulkUpdateInventoryPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new BulkUpdateInventoryPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;
                packet.FolderData[i].ParentID = DefaultValues.LLUUID;
                packet.FolderData[i].Type = DefaultValues.S8;
                packet.FolderData[i].Name = DefaultValues.Variable1;

	    }
            packet.ItemData = new BulkUpdateInventoryPacket.ItemDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ItemData[i] = new BulkUpdateInventoryPacket.ItemDataBlock();
                packet.ItemData[i].ItemID = DefaultValues.LLUUID;
                packet.ItemData[i].CallbackID = DefaultValues.U32;
                packet.ItemData[i].FolderID = DefaultValues.LLUUID;
                packet.ItemData[i].CreatorID = DefaultValues.LLUUID;
                packet.ItemData[i].OwnerID = DefaultValues.LLUUID;
                packet.ItemData[i].GroupID = DefaultValues.LLUUID;
                packet.ItemData[i].BaseMask = DefaultValues.U32;
                packet.ItemData[i].OwnerMask = DefaultValues.U32;
                packet.ItemData[i].GroupMask = DefaultValues.U32;
                packet.ItemData[i].EveryoneMask = DefaultValues.U32;
                packet.ItemData[i].NextOwnerMask = DefaultValues.U32;
                packet.ItemData[i].GroupOwned = DefaultValues.BOOL;
                packet.ItemData[i].AssetID = DefaultValues.LLUUID;
                packet.ItemData[i].Type = DefaultValues.S8;
                packet.ItemData[i].InvType = DefaultValues.S8;
                packet.ItemData[i].Flags = DefaultValues.U32;
                packet.ItemData[i].SaleType = DefaultValues.U8;
                packet.ItemData[i].SalePrice = DefaultValues.S32;
                packet.ItemData[i].Name = DefaultValues.Variable1;
                packet.ItemData[i].Description = DefaultValues.Variable1;
                packet.ItemData[i].CreationDate = DefaultValues.S32;
                packet.ItemData[i].CRC = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void RequestInventoryAsset_gen()
        {
            RequestInventoryAssetPacket packet = new RequestInventoryAssetPacket();
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.AgentID = DefaultValues.LLUUID;
                packet.QueryData.OwnerID = DefaultValues.LLUUID;
                packet.QueryData.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void InventoryAssetResponse_gen()
        {
            InventoryAssetResponsePacket packet = new InventoryAssetResponsePacket();
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.AssetID = DefaultValues.LLUUID;
                packet.QueryData.IsReadable = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void RemoveInventoryObjects_gen()
        {
            RemoveInventoryObjectsPacket packet = new RemoveInventoryObjectsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.FolderData = new RemoveInventoryObjectsPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new RemoveInventoryObjectsPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;

	    }
            packet.ItemData = new RemoveInventoryObjectsPacket.ItemDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ItemData[i] = new RemoveInventoryObjectsPacket.ItemDataBlock();
                packet.ItemData[i].ItemID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void PurgeInventoryDescendents_gen()
        {
            PurgeInventoryDescendentsPacket packet = new PurgeInventoryDescendentsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.InventoryData.FolderID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void UpdateTaskInventory_gen()
        {
            UpdateTaskInventoryPacket packet = new UpdateTaskInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.UpdateData.LocalID = DefaultValues.U32;
                packet.UpdateData.Key = DefaultValues.U8;
                packet.InventoryData.ItemID = DefaultValues.LLUUID;
                packet.InventoryData.FolderID = DefaultValues.LLUUID;
                packet.InventoryData.CreatorID = DefaultValues.LLUUID;
                packet.InventoryData.OwnerID = DefaultValues.LLUUID;
                packet.InventoryData.GroupID = DefaultValues.LLUUID;
                packet.InventoryData.BaseMask = DefaultValues.U32;
                packet.InventoryData.OwnerMask = DefaultValues.U32;
                packet.InventoryData.GroupMask = DefaultValues.U32;
                packet.InventoryData.EveryoneMask = DefaultValues.U32;
                packet.InventoryData.NextOwnerMask = DefaultValues.U32;
                packet.InventoryData.GroupOwned = DefaultValues.BOOL;
                packet.InventoryData.TransactionID = DefaultValues.LLUUID;
                packet.InventoryData.Type = DefaultValues.S8;
                packet.InventoryData.InvType = DefaultValues.S8;
                packet.InventoryData.Flags = DefaultValues.U32;
                packet.InventoryData.SaleType = DefaultValues.U8;
                packet.InventoryData.SalePrice = DefaultValues.S32;
                packet.InventoryData.Name = DefaultValues.Variable1;
                packet.InventoryData.Description = DefaultValues.Variable1;
                packet.InventoryData.CreationDate = DefaultValues.S32;
                packet.InventoryData.CRC = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void RemoveTaskInventory_gen()
        {
            RemoveTaskInventoryPacket packet = new RemoveTaskInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.InventoryData.LocalID = DefaultValues.U32;
                packet.InventoryData.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void MoveTaskInventory_gen()
        {
            MoveTaskInventoryPacket packet = new MoveTaskInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.FolderID = DefaultValues.LLUUID;
                packet.InventoryData.LocalID = DefaultValues.U32;
                packet.InventoryData.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RequestTaskInventory_gen()
        {
            RequestTaskInventoryPacket packet = new RequestTaskInventoryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.InventoryData.LocalID = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void ReplyTaskInventory_gen()
        {
            ReplyTaskInventoryPacket packet = new ReplyTaskInventoryPacket();
                packet.InventoryData.TaskID = DefaultValues.LLUUID;
                packet.InventoryData.Serial = DefaultValues.S16;
                packet.InventoryData.Filename = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void DeRezObject_gen()
        {
            DeRezObjectPacket packet = new DeRezObjectPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentBlock.GroupID = DefaultValues.LLUUID;
                packet.AgentBlock.Destination = DefaultValues.U8;
                packet.AgentBlock.DestinationID = DefaultValues.LLUUID;
                packet.AgentBlock.TransactionID = DefaultValues.LLUUID;
                packet.AgentBlock.PacketCount = DefaultValues.U8;
                packet.AgentBlock.PacketNumber = DefaultValues.U8;
            packet.ObjectData = new DeRezObjectPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new DeRezObjectPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void DeRezAck_gen()
        {
            DeRezAckPacket packet = new DeRezAckPacket();
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;
                packet.TransactionData.Success = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void RezObject_gen()
        {
            RezObjectPacket packet = new RezObjectPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.RezData.FromTaskID = DefaultValues.LLUUID;
                packet.RezData.BypassRaycast = DefaultValues.U8;
                packet.RezData.RayStart = DefaultValues.LLVector3;
                packet.RezData.RayEnd = DefaultValues.LLVector3;
                packet.RezData.RayTargetID = DefaultValues.LLUUID;
                packet.RezData.RayEndIsIntersection = DefaultValues.BOOL;
                packet.RezData.RezSelected = DefaultValues.BOOL;
                packet.RezData.RemoveItem = DefaultValues.BOOL;
                packet.RezData.ItemFlags = DefaultValues.U32;
                packet.RezData.GroupMask = DefaultValues.U32;
                packet.RezData.EveryoneMask = DefaultValues.U32;
                packet.RezData.NextOwnerMask = DefaultValues.U32;
                packet.InventoryData.ItemID = DefaultValues.LLUUID;
                packet.InventoryData.FolderID = DefaultValues.LLUUID;
                packet.InventoryData.CreatorID = DefaultValues.LLUUID;
                packet.InventoryData.OwnerID = DefaultValues.LLUUID;
                packet.InventoryData.GroupID = DefaultValues.LLUUID;
                packet.InventoryData.BaseMask = DefaultValues.U32;
                packet.InventoryData.OwnerMask = DefaultValues.U32;
                packet.InventoryData.GroupMask = DefaultValues.U32;
                packet.InventoryData.EveryoneMask = DefaultValues.U32;
                packet.InventoryData.NextOwnerMask = DefaultValues.U32;
                packet.InventoryData.GroupOwned = DefaultValues.BOOL;
                packet.InventoryData.TransactionID = DefaultValues.LLUUID;
                packet.InventoryData.Type = DefaultValues.S8;
                packet.InventoryData.InvType = DefaultValues.S8;
                packet.InventoryData.Flags = DefaultValues.U32;
                packet.InventoryData.SaleType = DefaultValues.U8;
                packet.InventoryData.SalePrice = DefaultValues.S32;
                packet.InventoryData.Name = DefaultValues.Variable1;
                packet.InventoryData.Description = DefaultValues.Variable1;
                packet.InventoryData.CreationDate = DefaultValues.S32;
                packet.InventoryData.CRC = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void RezObjectFromNotecard_gen()
        {
            RezObjectFromNotecardPacket packet = new RezObjectFromNotecardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.RezData.FromTaskID = DefaultValues.LLUUID;
                packet.RezData.BypassRaycast = DefaultValues.U8;
                packet.RezData.RayStart = DefaultValues.LLVector3;
                packet.RezData.RayEnd = DefaultValues.LLVector3;
                packet.RezData.RayTargetID = DefaultValues.LLUUID;
                packet.RezData.RayEndIsIntersection = DefaultValues.BOOL;
                packet.RezData.RezSelected = DefaultValues.BOOL;
                packet.RezData.RemoveItem = DefaultValues.BOOL;
                packet.RezData.ItemFlags = DefaultValues.U32;
                packet.RezData.GroupMask = DefaultValues.U32;
                packet.RezData.EveryoneMask = DefaultValues.U32;
                packet.RezData.NextOwnerMask = DefaultValues.U32;
                packet.NotecardData.NotecardItemID = DefaultValues.LLUUID;
                packet.NotecardData.ObjectID = DefaultValues.LLUUID;
            packet.InventoryData = new RezObjectFromNotecardPacket.InventoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InventoryData[i] = new RezObjectFromNotecardPacket.InventoryDataBlock();
                packet.InventoryData[i].ItemID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void AcceptFriendship_gen()
        {
            AcceptFriendshipPacket packet = new AcceptFriendshipPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TransactionBlock.TransactionID = DefaultValues.LLUUID;
            packet.FolderData = new AcceptFriendshipPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new AcceptFriendshipPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void DeclineFriendship_gen()
        {
            DeclineFriendshipPacket packet = new DeclineFriendshipPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TransactionBlock.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void FormFriendship_gen()
        {
            FormFriendshipPacket packet = new FormFriendshipPacket();
                packet.AgentBlock.SourceID = DefaultValues.LLUUID;
                packet.AgentBlock.DestID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void TerminateFriendship_gen()
        {
            TerminateFriendshipPacket packet = new TerminateFriendshipPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ExBlock.OtherID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void OfferCallingCard_gen()
        {
            OfferCallingCardPacket packet = new OfferCallingCardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentBlock.DestID = DefaultValues.LLUUID;
                packet.AgentBlock.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AcceptCallingCard_gen()
        {
            AcceptCallingCardPacket packet = new AcceptCallingCardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TransactionBlock.TransactionID = DefaultValues.LLUUID;
            packet.FolderData = new AcceptCallingCardPacket.FolderDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.FolderData[i] = new AcceptCallingCardPacket.FolderDataBlock();
                packet.FolderData[i].FolderID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void DeclineCallingCard_gen()
        {
            DeclineCallingCardPacket packet = new DeclineCallingCardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.TransactionBlock.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RezScript_gen()
        {
            RezScriptPacket packet = new RezScriptPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.UpdateBlock.ObjectLocalID = DefaultValues.U32;
                packet.UpdateBlock.Enabled = DefaultValues.BOOL;
                packet.InventoryBlock.ItemID = DefaultValues.LLUUID;
                packet.InventoryBlock.FolderID = DefaultValues.LLUUID;
                packet.InventoryBlock.CreatorID = DefaultValues.LLUUID;
                packet.InventoryBlock.OwnerID = DefaultValues.LLUUID;
                packet.InventoryBlock.GroupID = DefaultValues.LLUUID;
                packet.InventoryBlock.BaseMask = DefaultValues.U32;
                packet.InventoryBlock.OwnerMask = DefaultValues.U32;
                packet.InventoryBlock.GroupMask = DefaultValues.U32;
                packet.InventoryBlock.EveryoneMask = DefaultValues.U32;
                packet.InventoryBlock.NextOwnerMask = DefaultValues.U32;
                packet.InventoryBlock.GroupOwned = DefaultValues.BOOL;
                packet.InventoryBlock.TransactionID = DefaultValues.LLUUID;
                packet.InventoryBlock.Type = DefaultValues.S8;
                packet.InventoryBlock.InvType = DefaultValues.S8;
                packet.InventoryBlock.Flags = DefaultValues.U32;
                packet.InventoryBlock.SaleType = DefaultValues.U8;
                packet.InventoryBlock.SalePrice = DefaultValues.S32;
                packet.InventoryBlock.Name = DefaultValues.Variable1;
                packet.InventoryBlock.Description = DefaultValues.Variable1;
                packet.InventoryBlock.CreationDate = DefaultValues.S32;
                packet.InventoryBlock.CRC = DefaultValues.U32;

            output(packet.ToBytes());
        }
        
        static void CreateInventoryItem_gen()
        {
            CreateInventoryItemPacket packet = new CreateInventoryItemPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.InventoryBlock.CallbackID = DefaultValues.U32;
                packet.InventoryBlock.FolderID = DefaultValues.LLUUID;
                packet.InventoryBlock.TransactionID = DefaultValues.LLUUID;
                packet.InventoryBlock.NextOwnerMask = DefaultValues.U32;
                packet.InventoryBlock.Type = DefaultValues.S8;
                packet.InventoryBlock.InvType = DefaultValues.S8;
                packet.InventoryBlock.WearableType = DefaultValues.U8;
                packet.InventoryBlock.Name = DefaultValues.Variable1;
                packet.InventoryBlock.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void CreateLandmarkForEvent_gen()
        {
            CreateLandmarkForEventPacket packet = new CreateLandmarkForEventPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.EventData.EventID = DefaultValues.U32;
                packet.InventoryBlock.FolderID = DefaultValues.LLUUID;
                packet.InventoryBlock.Name = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void RegionHandleRequest_gen()
        {
            RegionHandleRequestPacket packet = new RegionHandleRequestPacket();
                packet.RequestBlock.RegionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RegionIDAndHandleReply_gen()
        {
            RegionIDAndHandleReplyPacket packet = new RegionIDAndHandleReplyPacket();
                packet.ReplyBlock.RegionID = DefaultValues.LLUUID;
                packet.ReplyBlock.RegionHandle = DefaultValues.U64;

            output(packet.ToBytes());
        }
        
        static void MoneyTransferRequest_gen()
        {
            MoneyTransferRequestPacket packet = new MoneyTransferRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MoneyData.SourceID = DefaultValues.LLUUID;
                packet.MoneyData.DestID = DefaultValues.LLUUID;
                packet.MoneyData.Flags = DefaultValues.U8;
                packet.MoneyData.Amount = DefaultValues.S32;
                packet.MoneyData.AggregatePermNextOwner = DefaultValues.U8;
                packet.MoneyData.AggregatePermInventory = DefaultValues.U8;
                packet.MoneyData.TransactionType = DefaultValues.S32;
                packet.MoneyData.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void MoneyBalanceRequest_gen()
        {
            MoneyBalanceRequestPacket packet = new MoneyBalanceRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.MoneyData.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void MoneyBalanceReply_gen()
        {
            MoneyBalanceReplyPacket packet = new MoneyBalanceReplyPacket();
                packet.MoneyData.AgentID = DefaultValues.LLUUID;
                packet.MoneyData.TransactionID = DefaultValues.LLUUID;
                packet.MoneyData.TransactionSuccess = DefaultValues.BOOL;
                packet.MoneyData.MoneyBalance = DefaultValues.S32;
                packet.MoneyData.SquareMetersCredit = DefaultValues.S32;
                packet.MoneyData.SquareMetersCommitted = DefaultValues.S32;
                packet.MoneyData.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void RoutedMoneyBalanceReply_gen()
        {
            RoutedMoneyBalanceReplyPacket packet = new RoutedMoneyBalanceReplyPacket();
                packet.TargetBlock.TargetIP = DefaultValues.IPADDR;
                packet.TargetBlock.TargetPort = DefaultValues.IPPORT;
                packet.MoneyData.AgentID = DefaultValues.LLUUID;
                packet.MoneyData.TransactionID = DefaultValues.LLUUID;
                packet.MoneyData.TransactionSuccess = DefaultValues.BOOL;
                packet.MoneyData.MoneyBalance = DefaultValues.S32;
                packet.MoneyData.SquareMetersCredit = DefaultValues.S32;
                packet.MoneyData.SquareMetersCommitted = DefaultValues.S32;
                packet.MoneyData.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void ActivateGestures_gen()
        {
            ActivateGesturesPacket packet = new ActivateGesturesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
            packet.Data = new ActivateGesturesPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new ActivateGesturesPacket.DataBlock();
                packet.Data[i].ItemID = DefaultValues.LLUUID;
                packet.Data[i].AssetID = DefaultValues.LLUUID;
                packet.Data[i].GestureFlags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void DeactivateGestures_gen()
        {
            DeactivateGesturesPacket packet = new DeactivateGesturesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
            packet.Data = new DeactivateGesturesPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new DeactivateGesturesPacket.DataBlock();
                packet.Data[i].ItemID = DefaultValues.LLUUID;
                packet.Data[i].GestureFlags = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void MuteListUpdate_gen()
        {
            MuteListUpdatePacket packet = new MuteListUpdatePacket();
                packet.MuteData.AgentID = DefaultValues.LLUUID;
                packet.MuteData.Filename = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void UseCachedMuteList_gen()
        {
            UseCachedMuteListPacket packet = new UseCachedMuteListPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GrantUserRights_gen()
        {
            GrantUserRightsPacket packet = new GrantUserRightsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.Rights = new GrantUserRightsPacket.RightsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Rights[i] = new GrantUserRightsPacket.RightsBlock();
                packet.Rights[i].AgentRelated = DefaultValues.LLUUID;
                packet.Rights[i].RelatedRights = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void ChangeUserRights_gen()
        {
            ChangeUserRightsPacket packet = new ChangeUserRightsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
            packet.Rights = new ChangeUserRightsPacket.RightsBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Rights[i] = new ChangeUserRightsPacket.RightsBlock();
                packet.Rights[i].AgentRelated = DefaultValues.LLUUID;
                packet.Rights[i].RelatedRights = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void OnlineNotification_gen()
        {
            OnlineNotificationPacket packet = new OnlineNotificationPacket();
            packet.AgentBlock = new OnlineNotificationPacket.AgentBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AgentBlock[i] = new OnlineNotificationPacket.AgentBlockBlock();
                packet.AgentBlock[i].AgentID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void OfflineNotification_gen()
        {
            OfflineNotificationPacket packet = new OfflineNotificationPacket();
            packet.AgentBlock = new OfflineNotificationPacket.AgentBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AgentBlock[i] = new OfflineNotificationPacket.AgentBlockBlock();
                packet.AgentBlock[i].AgentID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void SetStartLocationRequest_gen()
        {
            SetStartLocationRequestPacket packet = new SetStartLocationRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.StartLocationData.SimName = DefaultValues.Variable1;
                packet.StartLocationData.LocationID = DefaultValues.U32;
                packet.StartLocationData.LocationPos = DefaultValues.LLVector3;
                packet.StartLocationData.LocationLookAt = DefaultValues.LLVector3;

            output(packet.ToBytes());
        }
        
        static void SoundTrigger_gen()
        {
            SoundTriggerPacket packet = new SoundTriggerPacket();
                packet.SoundData.SoundID = DefaultValues.LLUUID;
                packet.SoundData.OwnerID = DefaultValues.LLUUID;
                packet.SoundData.ObjectID = DefaultValues.LLUUID;
                packet.SoundData.ParentID = DefaultValues.LLUUID;
                packet.SoundData.Handle = DefaultValues.U64;
                packet.SoundData.Position = DefaultValues.LLVector3;
                packet.SoundData.Gain = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void AttachedSound_gen()
        {
            AttachedSoundPacket packet = new AttachedSoundPacket();
                packet.DataBlock.SoundID = DefaultValues.LLUUID;
                packet.DataBlock.ObjectID = DefaultValues.LLUUID;
                packet.DataBlock.OwnerID = DefaultValues.LLUUID;
                packet.DataBlock.Gain = DefaultValues.F32;
                packet.DataBlock.Flags = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void AttachedSoundGainChange_gen()
        {
            AttachedSoundGainChangePacket packet = new AttachedSoundGainChangePacket();
                packet.DataBlock.ObjectID = DefaultValues.LLUUID;
                packet.DataBlock.Gain = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void PreloadSound_gen()
        {
            PreloadSoundPacket packet = new PreloadSoundPacket();
            packet.DataBlock = new PreloadSoundPacket.DataBlockBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.DataBlock[i] = new PreloadSoundPacket.DataBlockBlock();
                packet.DataBlock[i].ObjectID = DefaultValues.LLUUID;
                packet.DataBlock[i].OwnerID = DefaultValues.LLUUID;
                packet.DataBlock[i].SoundID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void AssetUploadRequest_gen()
        {
            AssetUploadRequestPacket packet = new AssetUploadRequestPacket();
                packet.AssetBlock.TransactionID = DefaultValues.LLUUID;
                packet.AssetBlock.Type = DefaultValues.S8;
                packet.AssetBlock.Tempfile = DefaultValues.BOOL;
                packet.AssetBlock.StoreLocal = DefaultValues.BOOL;
                packet.AssetBlock.AssetData = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void AssetUploadComplete_gen()
        {
            AssetUploadCompletePacket packet = new AssetUploadCompletePacket();
                packet.AssetBlock.UUID = DefaultValues.LLUUID;
                packet.AssetBlock.Type = DefaultValues.S8;
                packet.AssetBlock.Success = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void CreateGroupRequest_gen()
        {
            CreateGroupRequestPacket packet = new CreateGroupRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.Name = DefaultValues.Variable1;
                packet.GroupData.Charter = DefaultValues.Variable2;
                packet.GroupData.ShowInList = DefaultValues.BOOL;
                packet.GroupData.InsigniaID = DefaultValues.LLUUID;
                packet.GroupData.MembershipFee = DefaultValues.S32;
                packet.GroupData.OpenEnrollment = DefaultValues.BOOL;
                packet.GroupData.AllowPublish = DefaultValues.BOOL;
                packet.GroupData.MaturePublish = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void CreateGroupReply_gen()
        {
            CreateGroupReplyPacket packet = new CreateGroupReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.ReplyData.GroupID = DefaultValues.LLUUID;
                packet.ReplyData.Success = DefaultValues.BOOL;
                packet.ReplyData.Message = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void UpdateGroupInfo_gen()
        {
            UpdateGroupInfoPacket packet = new UpdateGroupInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.Charter = DefaultValues.Variable2;
                packet.GroupData.ShowInList = DefaultValues.BOOL;
                packet.GroupData.InsigniaID = DefaultValues.LLUUID;
                packet.GroupData.MembershipFee = DefaultValues.S32;
                packet.GroupData.OpenEnrollment = DefaultValues.BOOL;
                packet.GroupData.AllowPublish = DefaultValues.BOOL;
                packet.GroupData.MaturePublish = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void GroupRoleChanges_gen()
        {
            GroupRoleChangesPacket packet = new GroupRoleChangesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.RoleChange = new GroupRoleChangesPacket.RoleChangeBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.RoleChange[i] = new GroupRoleChangesPacket.RoleChangeBlock();
                packet.RoleChange[i].RoleID = DefaultValues.LLUUID;
                packet.RoleChange[i].MemberID = DefaultValues.LLUUID;
                packet.RoleChange[i].Change = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void JoinGroupRequest_gen()
        {
            JoinGroupRequestPacket packet = new JoinGroupRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void JoinGroupReply_gen()
        {
            JoinGroupReplyPacket packet = new JoinGroupReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.Success = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void EjectGroupMemberRequest_gen()
        {
            EjectGroupMemberRequestPacket packet = new EjectGroupMemberRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
            packet.EjectData = new EjectGroupMemberRequestPacket.EjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.EjectData[i] = new EjectGroupMemberRequestPacket.EjectDataBlock();
                packet.EjectData[i].EjecteeID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void EjectGroupMemberReply_gen()
        {
            EjectGroupMemberReplyPacket packet = new EjectGroupMemberReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.EjectData.Success = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void LeaveGroupRequest_gen()
        {
            LeaveGroupRequestPacket packet = new LeaveGroupRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void LeaveGroupReply_gen()
        {
            LeaveGroupReplyPacket packet = new LeaveGroupReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.Success = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void InviteGroupRequest_gen()
        {
            InviteGroupRequestPacket packet = new InviteGroupRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
            packet.InviteData = new InviteGroupRequestPacket.InviteDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.InviteData[i] = new InviteGroupRequestPacket.InviteDataBlock();
                packet.InviteData[i].InviteeID = DefaultValues.LLUUID;
                packet.InviteData[i].RoleID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupProfileRequest_gen()
        {
            GroupProfileRequestPacket packet = new GroupProfileRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupProfileReply_gen()
        {
            GroupProfileReplyPacket packet = new GroupProfileReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.Name = DefaultValues.Variable1;
                packet.GroupData.Charter = DefaultValues.Variable2;
                packet.GroupData.ShowInList = DefaultValues.BOOL;
                packet.GroupData.MemberTitle = DefaultValues.Variable1;
                packet.GroupData.PowersMask = DefaultValues.U64;
                packet.GroupData.InsigniaID = DefaultValues.LLUUID;
                packet.GroupData.FounderID = DefaultValues.LLUUID;
                packet.GroupData.MembershipFee = DefaultValues.S32;
                packet.GroupData.OpenEnrollment = DefaultValues.BOOL;
                packet.GroupData.Money = DefaultValues.S32;
                packet.GroupData.GroupMembershipCount = DefaultValues.S32;
                packet.GroupData.GroupRolesCount = DefaultValues.S32;
                packet.GroupData.AllowPublish = DefaultValues.BOOL;
                packet.GroupData.MaturePublish = DefaultValues.BOOL;
                packet.GroupData.OwnerRole = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupAccountSummaryRequest_gen()
        {
            GroupAccountSummaryRequestPacket packet = new GroupAccountSummaryRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void GroupAccountSummaryReply_gen()
        {
            GroupAccountSummaryReplyPacket packet = new GroupAccountSummaryReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;
                packet.MoneyData.StartDate = DefaultValues.Variable1;
                packet.MoneyData.Balance = DefaultValues.S32;
                packet.MoneyData.TotalCredits = DefaultValues.S32;
                packet.MoneyData.TotalDebits = DefaultValues.S32;
                packet.MoneyData.ObjectTaxCurrent = DefaultValues.S32;
                packet.MoneyData.LightTaxCurrent = DefaultValues.S32;
                packet.MoneyData.LandTaxCurrent = DefaultValues.S32;
                packet.MoneyData.GroupTaxCurrent = DefaultValues.S32;
                packet.MoneyData.ParcelDirFeeCurrent = DefaultValues.S32;
                packet.MoneyData.ObjectTaxEstimate = DefaultValues.S32;
                packet.MoneyData.LightTaxEstimate = DefaultValues.S32;
                packet.MoneyData.LandTaxEstimate = DefaultValues.S32;
                packet.MoneyData.GroupTaxEstimate = DefaultValues.S32;
                packet.MoneyData.ParcelDirFeeEstimate = DefaultValues.S32;
                packet.MoneyData.NonExemptMembers = DefaultValues.S32;
                packet.MoneyData.LastTaxDate = DefaultValues.Variable1;
                packet.MoneyData.TaxDate = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void GroupAccountDetailsRequest_gen()
        {
            GroupAccountDetailsRequestPacket packet = new GroupAccountDetailsRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void GroupAccountDetailsReply_gen()
        {
            GroupAccountDetailsReplyPacket packet = new GroupAccountDetailsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;
                packet.MoneyData.StartDate = DefaultValues.Variable1;
            packet.HistoryData = new GroupAccountDetailsReplyPacket.HistoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.HistoryData[i] = new GroupAccountDetailsReplyPacket.HistoryDataBlock();
                packet.HistoryData[i].Description = DefaultValues.Variable1;
                packet.HistoryData[i].Amount = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupAccountTransactionsRequest_gen()
        {
            GroupAccountTransactionsRequestPacket packet = new GroupAccountTransactionsRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void GroupAccountTransactionsReply_gen()
        {
            GroupAccountTransactionsReplyPacket packet = new GroupAccountTransactionsReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.MoneyData.RequestID = DefaultValues.LLUUID;
                packet.MoneyData.IntervalDays = DefaultValues.S32;
                packet.MoneyData.CurrentInterval = DefaultValues.S32;
                packet.MoneyData.StartDate = DefaultValues.Variable1;
            packet.HistoryData = new GroupAccountTransactionsReplyPacket.HistoryDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.HistoryData[i] = new GroupAccountTransactionsReplyPacket.HistoryDataBlock();
                packet.HistoryData[i].Time = DefaultValues.Variable1;
                packet.HistoryData[i].User = DefaultValues.Variable1;
                packet.HistoryData[i].Type = DefaultValues.S32;
                packet.HistoryData[i].Item = DefaultValues.Variable1;
                packet.HistoryData[i].Amount = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupActiveProposalsRequest_gen()
        {
            GroupActiveProposalsRequestPacket packet = new GroupActiveProposalsRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupActiveProposalItemReply_gen()
        {
            GroupActiveProposalItemReplyPacket packet = new GroupActiveProposalItemReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;
                packet.TransactionData.TotalNumItems = DefaultValues.U32;
            packet.ProposalData = new GroupActiveProposalItemReplyPacket.ProposalDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ProposalData[i] = new GroupActiveProposalItemReplyPacket.ProposalDataBlock();
                packet.ProposalData[i].VoteID = DefaultValues.LLUUID;
                packet.ProposalData[i].VoteInitiator = DefaultValues.LLUUID;
                packet.ProposalData[i].TerseDateID = DefaultValues.Variable1;
                packet.ProposalData[i].StartDateTime = DefaultValues.Variable1;
                packet.ProposalData[i].EndDateTime = DefaultValues.Variable1;
                packet.ProposalData[i].AlreadyVoted = DefaultValues.BOOL;
                packet.ProposalData[i].VoteCast = DefaultValues.Variable1;
                packet.ProposalData[i].Majority = DefaultValues.F32;
                packet.ProposalData[i].Quorum = DefaultValues.S32;
                packet.ProposalData[i].ProposalText = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupVoteHistoryRequest_gen()
        {
            GroupVoteHistoryRequestPacket packet = new GroupVoteHistoryRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupVoteHistoryItemReply_gen()
        {
            GroupVoteHistoryItemReplyPacket packet = new GroupVoteHistoryItemReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;
                packet.TransactionData.TotalNumItems = DefaultValues.U32;
                packet.HistoryItemData.VoteID = DefaultValues.LLUUID;
                packet.HistoryItemData.TerseDateID = DefaultValues.Variable1;
                packet.HistoryItemData.StartDateTime = DefaultValues.Variable1;
                packet.HistoryItemData.EndDateTime = DefaultValues.Variable1;
                packet.HistoryItemData.VoteInitiator = DefaultValues.LLUUID;
                packet.HistoryItemData.VoteType = DefaultValues.Variable1;
                packet.HistoryItemData.VoteResult = DefaultValues.Variable1;
                packet.HistoryItemData.Majority = DefaultValues.F32;
                packet.HistoryItemData.Quorum = DefaultValues.S32;
                packet.HistoryItemData.ProposalText = DefaultValues.Variable2;
            packet.VoteItem = new GroupVoteHistoryItemReplyPacket.VoteItemBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.VoteItem[i] = new GroupVoteHistoryItemReplyPacket.VoteItemBlock();
                packet.VoteItem[i].CandidateID = DefaultValues.LLUUID;
                packet.VoteItem[i].VoteCast = DefaultValues.Variable1;
                packet.VoteItem[i].NumVotes = DefaultValues.S32;

	    }

            output(packet.ToBytes());
        }
        
        static void StartGroupProposal_gen()
        {
            StartGroupProposalPacket packet = new StartGroupProposalPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ProposalData.GroupID = DefaultValues.LLUUID;
                packet.ProposalData.Quorum = DefaultValues.S32;
                packet.ProposalData.Majority = DefaultValues.F32;
                packet.ProposalData.Duration = DefaultValues.S32;
                packet.ProposalData.ProposalText = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void GroupProposalBallot_gen()
        {
            GroupProposalBallotPacket packet = new GroupProposalBallotPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ProposalData.ProposalID = DefaultValues.LLUUID;
                packet.ProposalData.GroupID = DefaultValues.LLUUID;
                packet.ProposalData.VoteCast = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void GroupMembersRequest_gen()
        {
            GroupMembersRequestPacket packet = new GroupMembersRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupMembersReply_gen()
        {
            GroupMembersReplyPacket packet = new GroupMembersReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;
                packet.GroupData.MemberCount = DefaultValues.S32;
            packet.MemberData = new GroupMembersReplyPacket.MemberDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.MemberData[i] = new GroupMembersReplyPacket.MemberDataBlock();
                packet.MemberData[i].AgentID = DefaultValues.LLUUID;
                packet.MemberData[i].Contribution = DefaultValues.S32;
                packet.MemberData[i].OnlineStatus = DefaultValues.Variable1;
                packet.MemberData[i].AgentPowers = DefaultValues.U64;
                packet.MemberData[i].Title = DefaultValues.Variable1;
                packet.MemberData[i].IsOwner = DefaultValues.BOOL;

	    }

            output(packet.ToBytes());
        }
        
        static void ActivateGroup_gen()
        {
            ActivateGroupPacket packet = new ActivateGroupPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void SetGroupContribution_gen()
        {
            SetGroupContributionPacket packet = new SetGroupContributionPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;
                packet.Data.Contribution = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void SetGroupAcceptNotices_gen()
        {
            SetGroupAcceptNoticesPacket packet = new SetGroupAcceptNoticesPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.GroupID = DefaultValues.LLUUID;
                packet.Data.AcceptNotices = DefaultValues.BOOL;
                packet.NewData.ListInProfile = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void GroupRoleDataRequest_gen()
        {
            GroupRoleDataRequestPacket packet = new GroupRoleDataRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupRoleDataReply_gen()
        {
            GroupRoleDataReplyPacket packet = new GroupRoleDataReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;
                packet.GroupData.RoleCount = DefaultValues.S32;
            packet.RoleData = new GroupRoleDataReplyPacket.RoleDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.RoleData[i] = new GroupRoleDataReplyPacket.RoleDataBlock();
                packet.RoleData[i].RoleID = DefaultValues.LLUUID;
                packet.RoleData[i].Name = DefaultValues.Variable1;
                packet.RoleData[i].Title = DefaultValues.Variable1;
                packet.RoleData[i].Description = DefaultValues.Variable1;
                packet.RoleData[i].Powers = DefaultValues.U64;
                packet.RoleData[i].Members = DefaultValues.U32;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupRoleMembersRequest_gen()
        {
            GroupRoleMembersRequestPacket packet = new GroupRoleMembersRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupRoleMembersReply_gen()
        {
            GroupRoleMembersReplyPacket packet = new GroupRoleMembersReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.RequestID = DefaultValues.LLUUID;
                packet.AgentData.TotalPairs = DefaultValues.U32;
            packet.MemberData = new GroupRoleMembersReplyPacket.MemberDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.MemberData[i] = new GroupRoleMembersReplyPacket.MemberDataBlock();
                packet.MemberData[i].RoleID = DefaultValues.LLUUID;
                packet.MemberData[i].MemberID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupTitlesRequest_gen()
        {
            GroupTitlesRequestPacket packet = new GroupTitlesRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.RequestID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupTitlesReply_gen()
        {
            GroupTitlesReplyPacket packet = new GroupTitlesReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.RequestID = DefaultValues.LLUUID;
            packet.GroupData = new GroupTitlesReplyPacket.GroupDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.GroupData[i] = new GroupTitlesReplyPacket.GroupDataBlock();
                packet.GroupData[i].Title = DefaultValues.Variable1;
                packet.GroupData[i].RoleID = DefaultValues.LLUUID;
                packet.GroupData[i].Selected = DefaultValues.BOOL;

	    }

            output(packet.ToBytes());
        }
        
        static void GroupTitleUpdate_gen()
        {
            GroupTitleUpdatePacket packet = new GroupTitleUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
                packet.AgentData.TitleRoleID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void GroupRoleUpdate_gen()
        {
            GroupRoleUpdatePacket packet = new GroupRoleUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;
            packet.RoleData = new GroupRoleUpdatePacket.RoleDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.RoleData[i] = new GroupRoleUpdatePacket.RoleDataBlock();
                packet.RoleData[i].RoleID = DefaultValues.LLUUID;
                packet.RoleData[i].Name = DefaultValues.Variable1;
                packet.RoleData[i].Description = DefaultValues.Variable1;
                packet.RoleData[i].Title = DefaultValues.Variable1;
                packet.RoleData[i].Powers = DefaultValues.U64;
                packet.RoleData[i].UpdateType = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void LiveHelpGroupRequest_gen()
        {
            LiveHelpGroupRequestPacket packet = new LiveHelpGroupRequestPacket();
                packet.RequestData.RequestID = DefaultValues.LLUUID;
                packet.RequestData.AgentID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void LiveHelpGroupReply_gen()
        {
            LiveHelpGroupReplyPacket packet = new LiveHelpGroupReplyPacket();
                packet.ReplyData.RequestID = DefaultValues.LLUUID;
                packet.ReplyData.GroupID = DefaultValues.LLUUID;
                packet.ReplyData.Selection = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void AgentWearablesRequest_gen()
        {
            AgentWearablesRequestPacket packet = new AgentWearablesRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AgentWearablesUpdate_gen()
        {
            AgentWearablesUpdatePacket packet = new AgentWearablesUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.U32;
            packet.WearableData = new AgentWearablesUpdatePacket.WearableDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.WearableData[i] = new AgentWearablesUpdatePacket.WearableDataBlock();
                packet.WearableData[i].ItemID = DefaultValues.LLUUID;
                packet.WearableData[i].AssetID = DefaultValues.LLUUID;
                packet.WearableData[i].WearableType = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentIsNowWearing_gen()
        {
            AgentIsNowWearingPacket packet = new AgentIsNowWearingPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.WearableData = new AgentIsNowWearingPacket.WearableDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.WearableData[i] = new AgentIsNowWearingPacket.WearableDataBlock();
                packet.WearableData[i].ItemID = DefaultValues.LLUUID;
                packet.WearableData[i].WearableType = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentCachedTexture_gen()
        {
            AgentCachedTexturePacket packet = new AgentCachedTexturePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.S32;
            packet.WearableData = new AgentCachedTexturePacket.WearableDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.WearableData[i] = new AgentCachedTexturePacket.WearableDataBlock();
                packet.WearableData[i].ID = DefaultValues.LLUUID;
                packet.WearableData[i].TextureIndex = DefaultValues.U8;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentCachedTextureResponse_gen()
        {
            AgentCachedTextureResponsePacket packet = new AgentCachedTextureResponsePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.SerialNum = DefaultValues.S32;
            packet.WearableData = new AgentCachedTextureResponsePacket.WearableDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.WearableData[i] = new AgentCachedTextureResponsePacket.WearableDataBlock();
                packet.WearableData[i].TextureID = DefaultValues.LLUUID;
                packet.WearableData[i].TextureIndex = DefaultValues.U8;
                packet.WearableData[i].HostName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentDataUpdateRequest_gen()
        {
            AgentDataUpdateRequestPacket packet = new AgentDataUpdateRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void AgentDataUpdate_gen()
        {
            AgentDataUpdatePacket packet = new AgentDataUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.FirstName = DefaultValues.Variable1;
                packet.AgentData.LastName = DefaultValues.Variable1;
                packet.AgentData.GroupTitle = DefaultValues.Variable1;
                packet.AgentData.ActiveGroupID = DefaultValues.LLUUID;
                packet.AgentData.GroupPowers = DefaultValues.U64;
                packet.AgentData.GroupName = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void GroupDataUpdate_gen()
        {
            GroupDataUpdatePacket packet = new GroupDataUpdatePacket();
            packet.AgentGroupData = new GroupDataUpdatePacket.AgentGroupDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.AgentGroupData[i] = new GroupDataUpdatePacket.AgentGroupDataBlock();
                packet.AgentGroupData[i].AgentID = DefaultValues.LLUUID;
                packet.AgentGroupData[i].GroupID = DefaultValues.LLUUID;
                packet.AgentGroupData[i].AgentPowers = DefaultValues.U64;
                packet.AgentGroupData[i].GroupTitle = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentGroupDataUpdate_gen()
        {
            AgentGroupDataUpdatePacket packet = new AgentGroupDataUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
            packet.GroupData = new AgentGroupDataUpdatePacket.GroupDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.GroupData[i] = new AgentGroupDataUpdatePacket.GroupDataBlock();
                packet.GroupData[i].GroupID = DefaultValues.LLUUID;
                packet.GroupData[i].GroupPowers = DefaultValues.U64;
                packet.GroupData[i].AcceptNotices = DefaultValues.BOOL;
                packet.GroupData[i].GroupInsigniaID = DefaultValues.LLUUID;
                packet.GroupData[i].Contribution = DefaultValues.S32;
                packet.GroupData[i].GroupName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void AgentDropGroup_gen()
        {
            AgentDropGroupPacket packet = new AgentDropGroupPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.GroupID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void ViewerEffect_gen()
        {
            ViewerEffectPacket packet = new ViewerEffectPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.Effect = new ViewerEffectPacket.EffectBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Effect[i] = new ViewerEffectPacket.EffectBlock();
                packet.Effect[i].ID = DefaultValues.LLUUID;
                packet.Effect[i].AgentID = DefaultValues.LLUUID;
                packet.Effect[i].Type = DefaultValues.U8;
                packet.Effect[i].Duration = DefaultValues.F32;
                packet.Effect[i].Color = DefaultValues.Fixed4;
                packet.Effect[i].TypeData = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void CreateTrustedCircuit_gen()
        {
            CreateTrustedCircuitPacket packet = new CreateTrustedCircuitPacket();
                packet.DataBlock.EndPointID = DefaultValues.LLUUID;
                packet.DataBlock.Digest = DefaultValues.Fixed32;

            output(packet.ToBytes());
        }
        
        static void DenyTrustedCircuit_gen()
        {
            DenyTrustedCircuitPacket packet = new DenyTrustedCircuitPacket();
                packet.DataBlock.EndPointID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void RequestTrustedCircuit_gen()
        {
            RequestTrustedCircuitPacket packet = new RequestTrustedCircuitPacket();

            output(packet.ToBytes());
        }
        
        static void RezSingleAttachmentFromInv_gen()
        {
            RezSingleAttachmentFromInvPacket packet = new RezSingleAttachmentFromInvPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ObjectData.ItemID = DefaultValues.LLUUID;
                packet.ObjectData.OwnerID = DefaultValues.LLUUID;
                packet.ObjectData.AttachmentPt = DefaultValues.U8;
                packet.ObjectData.ItemFlags = DefaultValues.U32;
                packet.ObjectData.GroupMask = DefaultValues.U32;
                packet.ObjectData.EveryoneMask = DefaultValues.U32;
                packet.ObjectData.NextOwnerMask = DefaultValues.U32;
                packet.ObjectData.Name = DefaultValues.Variable1;
                packet.ObjectData.Description = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void RezMultipleAttachmentsFromInv_gen()
        {
            RezMultipleAttachmentsFromInvPacket packet = new RezMultipleAttachmentsFromInvPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.HeaderData.CompoundMsgID = DefaultValues.LLUUID;
                packet.HeaderData.TotalObjects = DefaultValues.U8;
                packet.HeaderData.FirstDetachAll = DefaultValues.BOOL;
            packet.ObjectData = new RezMultipleAttachmentsFromInvPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new RezMultipleAttachmentsFromInvPacket.ObjectDataBlock();
                packet.ObjectData[i].ItemID = DefaultValues.LLUUID;
                packet.ObjectData[i].OwnerID = DefaultValues.LLUUID;
                packet.ObjectData[i].AttachmentPt = DefaultValues.U8;
                packet.ObjectData[i].ItemFlags = DefaultValues.U32;
                packet.ObjectData[i].GroupMask = DefaultValues.U32;
                packet.ObjectData[i].EveryoneMask = DefaultValues.U32;
                packet.ObjectData[i].NextOwnerMask = DefaultValues.U32;
                packet.ObjectData[i].Name = DefaultValues.Variable1;
                packet.ObjectData[i].Description = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void DetachAttachmentIntoInv_gen()
        {
            DetachAttachmentIntoInvPacket packet = new DetachAttachmentIntoInvPacket();
                packet.ObjectData.AgentID = DefaultValues.LLUUID;
                packet.ObjectData.ItemID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void CreateNewOutfitAttachments_gen()
        {
            CreateNewOutfitAttachmentsPacket packet = new CreateNewOutfitAttachmentsPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.HeaderData.NewFolderID = DefaultValues.LLUUID;
            packet.ObjectData = new CreateNewOutfitAttachmentsPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new CreateNewOutfitAttachmentsPacket.ObjectDataBlock();
                packet.ObjectData[i].OldItemID = DefaultValues.LLUUID;
                packet.ObjectData[i].OldFolderID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void UserInfoRequest_gen()
        {
            UserInfoRequestPacket packet = new UserInfoRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

            output(packet.ToBytes());
        }
        
        static void UserInfoReply_gen()
        {
            UserInfoReplyPacket packet = new UserInfoReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.UserData.IMViaEMail = DefaultValues.BOOL;
                packet.UserData.DirectoryVisibility = DefaultValues.Variable1;
                packet.UserData.EMail = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void UpdateUserInfo_gen()
        {
            UpdateUserInfoPacket packet = new UpdateUserInfoPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.UserData.IMViaEMail = DefaultValues.BOOL;
                packet.UserData.DirectoryVisibility = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void InitiateDownload_gen()
        {
            InitiateDownloadPacket packet = new InitiateDownloadPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.FileData.SimFilename = DefaultValues.Variable1;
                packet.FileData.ViewerFilename = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void SystemMessage_gen()
        {
            SystemMessagePacket packet = new SystemMessagePacket();
                packet.MethodData.Method = DefaultValues.Variable1;
                packet.MethodData.Invoice = DefaultValues.LLUUID;
                packet.MethodData.Digest = DefaultValues.Fixed32;
            packet.ParamList = new SystemMessagePacket.ParamListBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ParamList[i] = new SystemMessagePacket.ParamListBlock();
                packet.ParamList[i].Parameter = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void MapLayerRequest_gen()
        {
            MapLayerRequestPacket packet = new MapLayerRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
                packet.AgentData.EstateID = DefaultValues.U32;
                packet.AgentData.Godlike = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void MapLayerReply_gen()
        {
            MapLayerReplyPacket packet = new MapLayerReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
            packet.LayerData = new MapLayerReplyPacket.LayerDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.LayerData[i] = new MapLayerReplyPacket.LayerDataBlock();
                packet.LayerData[i].Left = DefaultValues.U32;
                packet.LayerData[i].Right = DefaultValues.U32;
                packet.LayerData[i].Top = DefaultValues.U32;
                packet.LayerData[i].Bottom = DefaultValues.U32;
                packet.LayerData[i].ImageID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void MapBlockRequest_gen()
        {
            MapBlockRequestPacket packet = new MapBlockRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
                packet.AgentData.EstateID = DefaultValues.U32;
                packet.AgentData.Godlike = DefaultValues.BOOL;
                packet.PositionData.MinX = DefaultValues.U16;
                packet.PositionData.MaxX = DefaultValues.U16;
                packet.PositionData.MinY = DefaultValues.U16;
                packet.PositionData.MaxY = DefaultValues.U16;

            output(packet.ToBytes());
        }
        
        static void MapNameRequest_gen()
        {
            MapNameRequestPacket packet = new MapNameRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
                packet.AgentData.EstateID = DefaultValues.U32;
                packet.AgentData.Godlike = DefaultValues.BOOL;
                packet.NameData.Name = DefaultValues.Variable1;

            output(packet.ToBytes());
        }
        
        static void MapBlockReply_gen()
        {
            MapBlockReplyPacket packet = new MapBlockReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
            packet.Data = new MapBlockReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new MapBlockReplyPacket.DataBlock();
                packet.Data[i].X = DefaultValues.U16;
                packet.Data[i].Y = DefaultValues.U16;
                packet.Data[i].Name = DefaultValues.Variable1;
                packet.Data[i].Access = DefaultValues.U8;
                packet.Data[i].RegionFlags = DefaultValues.U32;
                packet.Data[i].WaterHeight = DefaultValues.U8;
                packet.Data[i].Agents = DefaultValues.U8;
                packet.Data[i].MapImageID = DefaultValues.LLUUID;

	    }

            output(packet.ToBytes());
        }
        
        static void MapItemRequest_gen()
        {
            MapItemRequestPacket packet = new MapItemRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
                packet.AgentData.EstateID = DefaultValues.U32;
                packet.AgentData.Godlike = DefaultValues.BOOL;
                packet.RequestData.ItemType = DefaultValues.U32;
                packet.RequestData.RegionHandle = DefaultValues.U64;

            output(packet.ToBytes());
        }
        
        static void MapItemReply_gen()
        {
            MapItemReplyPacket packet = new MapItemReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.Flags = DefaultValues.U32;
                packet.RequestData.ItemType = DefaultValues.U32;
            packet.Data = new MapItemReplyPacket.DataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.Data[i] = new MapItemReplyPacket.DataBlock();
                packet.Data[i].X = DefaultValues.U32;
                packet.Data[i].Y = DefaultValues.U32;
                packet.Data[i].ID = DefaultValues.LLUUID;
                packet.Data[i].Extra = DefaultValues.S32;
                packet.Data[i].Extra2 = DefaultValues.S32;
                packet.Data[i].Name = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void SendPostcard_gen()
        {
            SendPostcardPacket packet = new SendPostcardPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.AgentData.AssetID = DefaultValues.LLUUID;
                packet.AgentData.PosGlobal = DefaultValues.LLVector3d;
                packet.AgentData.To = DefaultValues.Variable1;
                packet.AgentData.From = DefaultValues.Variable1;
                packet.AgentData.Name = DefaultValues.Variable1;
                packet.AgentData.Subject = DefaultValues.Variable1;
                packet.AgentData.Msg = DefaultValues.Variable2;
                packet.AgentData.AllowPublish = DefaultValues.BOOL;
                packet.AgentData.MaturePublish = DefaultValues.BOOL;

            output(packet.ToBytes());
        }
        
        static void ParcelMediaCommandMessage_gen()
        {
            ParcelMediaCommandMessagePacket packet = new ParcelMediaCommandMessagePacket();
                packet.CommandBlock.Flags = DefaultValues.U32;
                packet.CommandBlock.Command = DefaultValues.U32;
                packet.CommandBlock.Time = DefaultValues.F32;

            output(packet.ToBytes());
        }
        
        static void ParcelMediaUpdate_gen()
        {
            ParcelMediaUpdatePacket packet = new ParcelMediaUpdatePacket();
                packet.DataBlock.MediaURL = DefaultValues.Variable1;
                packet.DataBlock.MediaID = DefaultValues.LLUUID;
                packet.DataBlock.MediaAutoScale = DefaultValues.U8;
                packet.DataBlockExtended.MediaType = DefaultValues.Variable1;
                packet.DataBlockExtended.MediaDesc = DefaultValues.Variable1;
                packet.DataBlockExtended.MediaWidth = DefaultValues.S32;
                packet.DataBlockExtended.MediaHeight = DefaultValues.S32;
                packet.DataBlockExtended.MediaLoop = DefaultValues.U8;

            output(packet.ToBytes());
        }
        
        static void LandStatRequest_gen()
        {
            LandStatRequestPacket packet = new LandStatRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RequestData.ReportType = DefaultValues.U32;
                packet.RequestData.RequestFlags = DefaultValues.U32;
                packet.RequestData.Filter = DefaultValues.Variable1;
                packet.RequestData.ParcelLocalID = DefaultValues.S32;

            output(packet.ToBytes());
        }
        
        static void LandStatReply_gen()
        {
            LandStatReplyPacket packet = new LandStatReplyPacket();
                packet.RequestData.ReportType = DefaultValues.U32;
                packet.RequestData.RequestFlags = DefaultValues.U32;
                packet.RequestData.TotalObjectCount = DefaultValues.U32;
            packet.ReportData = new LandStatReplyPacket.ReportDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ReportData[i] = new LandStatReplyPacket.ReportDataBlock();
                packet.ReportData[i].TaskLocalID = DefaultValues.U32;
                packet.ReportData[i].TaskID = DefaultValues.LLUUID;
                packet.ReportData[i].LocationX = DefaultValues.F32;
                packet.ReportData[i].LocationY = DefaultValues.F32;
                packet.ReportData[i].LocationZ = DefaultValues.F32;
                packet.ReportData[i].Score = DefaultValues.F32;
                packet.ReportData[i].TaskName = DefaultValues.Variable1;
                packet.ReportData[i].OwnerName = DefaultValues.Variable1;

	    }

            output(packet.ToBytes());
        }
        
        static void Error_gen()
        {
            ErrorPacket packet = new ErrorPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.Data.Code = DefaultValues.S32;
                packet.Data.Token = DefaultValues.Variable1;
                packet.Data.ID = DefaultValues.LLUUID;
                packet.Data.System = DefaultValues.Variable1;
                packet.Data.Message = DefaultValues.Variable2;
                packet.Data.Data = DefaultValues.Variable2;

            output(packet.ToBytes());
        }
        
        static void ObjectIncludeInSearch_gen()
        {
            ObjectIncludeInSearchPacket packet = new ObjectIncludeInSearchPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
            packet.ObjectData = new ObjectIncludeInSearchPacket.ObjectDataBlock[DefaultValues.variable_blocks_length];
            for (int i = 0; i < DefaultValues.variable_blocks_length; i++)
            {
                packet.ObjectData[i] = new ObjectIncludeInSearchPacket.ObjectDataBlock();
                packet.ObjectData[i].ObjectLocalID = DefaultValues.U32;
                packet.ObjectData[i].IncludeInSearch = DefaultValues.BOOL;

	    }

            output(packet.ToBytes());
        }
        


        static void Main(string[] args)
        {
            TestMessage_gen();
            PacketAck_gen();
            OpenCircuit_gen();
            CloseCircuit_gen();
            StartPingCheck_gen();
            CompletePingCheck_gen();
            UseCircuitCode_gen();
            TelehubInfo_gen();
            EconomyDataRequest_gen();
            EconomyData_gen();
            AvatarPickerRequest_gen();
            AvatarPickerReply_gen();
            PlacesQuery_gen();
            PlacesReply_gen();
            DirFindQuery_gen();
            DirPlacesQuery_gen();
            DirPlacesReply_gen();
            DirPeopleReply_gen();
            DirEventsReply_gen();
            DirGroupsReply_gen();
            DirClassifiedQuery_gen();
            DirClassifiedReply_gen();
            AvatarClassifiedReply_gen();
            ClassifiedInfoRequest_gen();
            ClassifiedInfoReply_gen();
            ClassifiedInfoUpdate_gen();
            ClassifiedDelete_gen();
            ClassifiedGodDelete_gen();
            DirLandQuery_gen();
            DirLandReply_gen();
            DirPopularQuery_gen();
            DirPopularReply_gen();
            ParcelInfoRequest_gen();
            ParcelInfoReply_gen();
            ParcelObjectOwnersRequest_gen();
            ParcelObjectOwnersReply_gen();
            GroupNoticesListRequest_gen();
            GroupNoticesListReply_gen();
            GroupNoticeRequest_gen();
            TeleportRequest_gen();
            TeleportLocationRequest_gen();
            TeleportLocal_gen();
            TeleportLandmarkRequest_gen();
            TeleportProgress_gen();
            TeleportFinish_gen();
            StartLure_gen();
            TeleportLureRequest_gen();
            TeleportCancel_gen();
            TeleportStart_gen();
            TeleportFailed_gen();
            Undo_gen();
            Redo_gen();
            UndoLand_gen();
            AgentPause_gen();
            AgentResume_gen();
            AgentUpdate_gen();
            ChatFromViewer_gen();
            AgentThrottle_gen();
            AgentFOV_gen();
            AgentHeightWidth_gen();
            AgentSetAppearance_gen();
            AgentAnimation_gen();
            AgentRequestSit_gen();
            AgentSit_gen();
            AgentQuitCopy_gen();
            RequestImage_gen();
            ImageNotInDatabase_gen();
            RebakeAvatarTextures_gen();
            SetAlwaysRun_gen();
            ObjectAdd_gen();
            ObjectDelete_gen();
            ObjectDuplicate_gen();
            ObjectDuplicateOnRay_gen();
            MultipleObjectUpdate_gen();
            RequestMultipleObjects_gen();
            ObjectPosition_gen();
            ObjectScale_gen();
            ObjectRotation_gen();
            ObjectFlagUpdate_gen();
            ObjectClickAction_gen();
            ObjectImage_gen();
            ObjectMaterial_gen();
            ObjectShape_gen();
            ObjectExtraParams_gen();
            ObjectOwner_gen();
            ObjectGroup_gen();
            ObjectBuy_gen();
            BuyObjectInventory_gen();
            DerezContainer_gen();
            ObjectPermissions_gen();
            ObjectSaleInfo_gen();
            ObjectName_gen();
            ObjectDescription_gen();
            ObjectCategory_gen();
            ObjectSelect_gen();
            ObjectDeselect_gen();
            ObjectAttach_gen();
            ObjectDetach_gen();
            ObjectDrop_gen();
            ObjectLink_gen();
            ObjectDelink_gen();
            ObjectGrab_gen();
            ObjectGrabUpdate_gen();
            ObjectDeGrab_gen();
            ObjectSpinStart_gen();
            ObjectSpinUpdate_gen();
            ObjectSpinStop_gen();
            ObjectExportSelected_gen();
            ModifyLand_gen();
            VelocityInterpolateOn_gen();
            VelocityInterpolateOff_gen();
            StateSave_gen();
            ReportAutosaveCrash_gen();
            SimWideDeletes_gen();
            RequestObjectPropertiesFamily_gen();
            TrackAgent_gen();
            ViewerStats_gen();
            ScriptAnswerYes_gen();
            UserReport_gen();
            AlertMessage_gen();
            AgentAlertMessage_gen();
            MeanCollisionAlert_gen();
            ViewerFrozenMessage_gen();
            HealthMessage_gen();
            ChatFromSimulator_gen();
            SimStats_gen();
            RequestRegionInfo_gen();
            RegionInfo_gen();
            GodUpdateRegionInfo_gen();
            NearestLandingRegionUpdated_gen();
            RegionHandshake_gen();
            RegionHandshakeReply_gen();
            CoarseLocationUpdate_gen();
            ImageData_gen();
            ImagePacket_gen();
            LayerData_gen();
            ObjectUpdate_gen();
            ObjectUpdateCompressed_gen();
            ObjectUpdateCached_gen();
            ImprovedTerseObjectUpdate_gen();
            KillObject_gen();
            CrossedRegion_gen();
            SimulatorViewerTimeMessage_gen();
            EnableSimulator_gen();
            DisableSimulator_gen();
            ConfirmEnableSimulator_gen();
            TransferRequest_gen();
            TransferInfo_gen();
            TransferPacket_gen();
            TransferAbort_gen();
            RequestXfer_gen();
            SendXferPacket_gen();
            ConfirmXferPacket_gen();
            AbortXfer_gen();
            AvatarAnimation_gen();
            AvatarAppearance_gen();
            AvatarSitResponse_gen();
            SetFollowCamProperties_gen();
            ClearFollowCamProperties_gen();
            CameraConstraint_gen();
            ObjectProperties_gen();
            ObjectPropertiesFamily_gen();
            RequestPayPrice_gen();
            PayPriceReply_gen();
            KickUser_gen();
            KickUserAck_gen();
            GodKickUser_gen();
            EjectUser_gen();
            FreezeUser_gen();
            AvatarPropertiesRequest_gen();
            AvatarPropertiesReply_gen();
            AvatarInterestsReply_gen();
            AvatarGroupsReply_gen();
            AvatarPropertiesUpdate_gen();
            AvatarInterestsUpdate_gen();
            AvatarNotesReply_gen();
            AvatarNotesUpdate_gen();
            AvatarPicksReply_gen();
            EventInfoRequest_gen();
            EventInfoReply_gen();
            EventNotificationAddRequest_gen();
            EventNotificationRemoveRequest_gen();
            EventGodDelete_gen();
            PickInfoReply_gen();
            PickInfoUpdate_gen();
            PickDelete_gen();
            PickGodDelete_gen();
            ScriptQuestion_gen();
            ScriptControlChange_gen();
            ScriptDialog_gen();
            ScriptDialogReply_gen();
            ForceScriptControlRelease_gen();
            RevokePermissions_gen();
            LoadURL_gen();
            ScriptTeleportRequest_gen();
            ParcelOverlay_gen();
            ParcelPropertiesRequest_gen();
            ParcelPropertiesRequestByID_gen();
            ParcelProperties_gen();
            ParcelPropertiesUpdate_gen();
            ParcelReturnObjects_gen();
            ParcelSetOtherCleanTime_gen();
            ParcelDisableObjects_gen();
            ParcelSelectObjects_gen();
            EstateCovenantRequest_gen();
            EstateCovenantReply_gen();
            ForceObjectSelect_gen();
            ParcelBuyPass_gen();
            ParcelDeedToGroup_gen();
            ParcelReclaim_gen();
            ParcelClaim_gen();
            ParcelJoin_gen();
            ParcelDivide_gen();
            ParcelRelease_gen();
            ParcelBuy_gen();
            ParcelGodForceOwner_gen();
            ParcelAccessListRequest_gen();
            ParcelAccessListReply_gen();
            ParcelAccessListUpdate_gen();
            ParcelDwellRequest_gen();
            ParcelDwellReply_gen();
            ParcelGodMarkAsContent_gen();
            ViewerStartAuction_gen();
            UUIDNameRequest_gen();
            UUIDNameReply_gen();
            UUIDGroupNameRequest_gen();
            UUIDGroupNameReply_gen();
            ChildAgentUpdate_gen();
            ChildAgentAlive_gen();
            ChildAgentPositionUpdate_gen();
            ChildAgentDying_gen();
            ChildAgentUnknown_gen();
            GetScriptRunning_gen();
            ScriptRunningReply_gen();
            SetScriptRunning_gen();
            ScriptReset_gen();
            ScriptSensorRequest_gen();
            ScriptSensorReply_gen();
            CompleteAgentMovement_gen();
            AgentMovementComplete_gen();
            LogoutRequest_gen();
            LogoutReply_gen();
            ImprovedInstantMessage_gen();
            RetrieveInstantMessages_gen();
            FindAgent_gen();
            RequestGodlikePowers_gen();
            GrantGodlikePowers_gen();
            GodlikeMessage_gen();
            EstateOwnerMessage_gen();
            GenericMessage_gen();
            MuteListRequest_gen();
            UpdateMuteListEntry_gen();
            RemoveMuteListEntry_gen();
            CopyInventoryFromNotecard_gen();
            UpdateInventoryItem_gen();
            UpdateCreateInventoryItem_gen();
            MoveInventoryItem_gen();
            CopyInventoryItem_gen();
            RemoveInventoryItem_gen();
            ChangeInventoryItemFlags_gen();
            SaveAssetIntoInventory_gen();
            CreateInventoryFolder_gen();
            UpdateInventoryFolder_gen();
            MoveInventoryFolder_gen();
            RemoveInventoryFolder_gen();
            FetchInventoryDescendents_gen();
            InventoryDescendents_gen();
            FetchInventory_gen();
            FetchInventoryReply_gen();
            BulkUpdateInventory_gen();
            RequestInventoryAsset_gen();
            InventoryAssetResponse_gen();
            RemoveInventoryObjects_gen();
            PurgeInventoryDescendents_gen();
            UpdateTaskInventory_gen();
            RemoveTaskInventory_gen();
            MoveTaskInventory_gen();
            RequestTaskInventory_gen();
            ReplyTaskInventory_gen();
            DeRezObject_gen();
            DeRezAck_gen();
            RezObject_gen();
            RezObjectFromNotecard_gen();
            AcceptFriendship_gen();
            DeclineFriendship_gen();
            FormFriendship_gen();
            TerminateFriendship_gen();
            OfferCallingCard_gen();
            AcceptCallingCard_gen();
            DeclineCallingCard_gen();
            RezScript_gen();
            CreateInventoryItem_gen();
            CreateLandmarkForEvent_gen();
            RegionHandleRequest_gen();
            RegionIDAndHandleReply_gen();
            MoneyTransferRequest_gen();
            MoneyBalanceRequest_gen();
            MoneyBalanceReply_gen();
            RoutedMoneyBalanceReply_gen();
            ActivateGestures_gen();
            DeactivateGestures_gen();
            MuteListUpdate_gen();
            UseCachedMuteList_gen();
            GrantUserRights_gen();
            ChangeUserRights_gen();
            OnlineNotification_gen();
            OfflineNotification_gen();
            SetStartLocationRequest_gen();
            SoundTrigger_gen();
            AttachedSound_gen();
            AttachedSoundGainChange_gen();
            PreloadSound_gen();
            AssetUploadRequest_gen();
            AssetUploadComplete_gen();
            CreateGroupRequest_gen();
            CreateGroupReply_gen();
            UpdateGroupInfo_gen();
            GroupRoleChanges_gen();
            JoinGroupRequest_gen();
            JoinGroupReply_gen();
            EjectGroupMemberRequest_gen();
            EjectGroupMemberReply_gen();
            LeaveGroupRequest_gen();
            LeaveGroupReply_gen();
            InviteGroupRequest_gen();
            GroupProfileRequest_gen();
            GroupProfileReply_gen();
            GroupAccountSummaryRequest_gen();
            GroupAccountSummaryReply_gen();
            GroupAccountDetailsRequest_gen();
            GroupAccountDetailsReply_gen();
            GroupAccountTransactionsRequest_gen();
            GroupAccountTransactionsReply_gen();
            GroupActiveProposalsRequest_gen();
            GroupActiveProposalItemReply_gen();
            GroupVoteHistoryRequest_gen();
            GroupVoteHistoryItemReply_gen();
            StartGroupProposal_gen();
            GroupProposalBallot_gen();
            GroupMembersRequest_gen();
            GroupMembersReply_gen();
            ActivateGroup_gen();
            SetGroupContribution_gen();
            SetGroupAcceptNotices_gen();
            GroupRoleDataRequest_gen();
            GroupRoleDataReply_gen();
            GroupRoleMembersRequest_gen();
            GroupRoleMembersReply_gen();
            GroupTitlesRequest_gen();
            GroupTitlesReply_gen();
            GroupTitleUpdate_gen();
            GroupRoleUpdate_gen();
            LiveHelpGroupRequest_gen();
            LiveHelpGroupReply_gen();
            AgentWearablesRequest_gen();
            AgentWearablesUpdate_gen();
            AgentIsNowWearing_gen();
            AgentCachedTexture_gen();
            AgentCachedTextureResponse_gen();
            AgentDataUpdateRequest_gen();
            AgentDataUpdate_gen();
            GroupDataUpdate_gen();
            AgentGroupDataUpdate_gen();
            AgentDropGroup_gen();
            ViewerEffect_gen();
            CreateTrustedCircuit_gen();
            DenyTrustedCircuit_gen();
            RequestTrustedCircuit_gen();
            RezSingleAttachmentFromInv_gen();
            RezMultipleAttachmentsFromInv_gen();
            DetachAttachmentIntoInv_gen();
            CreateNewOutfitAttachments_gen();
            UserInfoRequest_gen();
            UserInfoReply_gen();
            UpdateUserInfo_gen();
            InitiateDownload_gen();
            SystemMessage_gen();
            MapLayerRequest_gen();
            MapLayerReply_gen();
            MapBlockRequest_gen();
            MapNameRequest_gen();
            MapBlockReply_gen();
            MapItemRequest_gen();
            MapItemReply_gen();
            SendPostcard_gen();
            ParcelMediaCommandMessage_gen();
            ParcelMediaUpdate_gen();
            LandStatRequest_gen();
            LandStatReply_gen();
            Error_gen();
            ObjectIncludeInSearch_gen();

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


