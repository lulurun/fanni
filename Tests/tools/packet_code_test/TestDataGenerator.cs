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
        
        static void EconomyDataRequest_gen()
        {
            EconomyDataRequestPacket packet = new EconomyDataRequestPacket();

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
        
        static void ClassifiedInfoRequest_gen()
        {
            ClassifiedInfoRequestPacket packet = new ClassifiedInfoRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.ClassifiedID = DefaultValues.LLUUID;

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
        
        static void DirPopularQuery_gen()
        {
            DirPopularQueryPacket packet = new DirPopularQueryPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.QueryData.QueryID = DefaultValues.LLUUID;
                packet.QueryData.QueryFlags = DefaultValues.U32;

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
        
        static void ParcelObjectOwnersRequest_gen()
        {
            ParcelObjectOwnersRequestPacket packet = new ParcelObjectOwnersRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.ParcelData.LocalID = DefaultValues.S32;

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
        
        static void TeleportLandmarkRequest_gen()
        {
            TeleportLandmarkRequestPacket packet = new TeleportLandmarkRequestPacket();
                packet.Info.AgentID = DefaultValues.LLUUID;
                packet.Info.SessionID = DefaultValues.LLUUID;
                packet.Info.LandmarkID = DefaultValues.LLUUID;

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
        
        static void RegionHandshakeReply_gen()
        {
            RegionHandshakeReplyPacket packet = new RegionHandshakeReplyPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.RegionInfo.Flags = DefaultValues.U32;

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
        
        static void RequestPayPrice_gen()
        {
            RequestPayPricePacket packet = new RequestPayPricePacket();
                packet.ObjectData.ObjectID = DefaultValues.LLUUID;

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
        
        static void AvatarNotesUpdate_gen()
        {
            AvatarNotesUpdatePacket packet = new AvatarNotesUpdatePacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.Data.TargetID = DefaultValues.LLUUID;
                packet.Data.Notes = DefaultValues.Variable2;

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
        
        static void LeaveGroupRequest_gen()
        {
            LeaveGroupRequestPacket packet = new LeaveGroupRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;

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
        
        static void GroupActiveProposalsRequest_gen()
        {
            GroupActiveProposalsRequestPacket packet = new GroupActiveProposalsRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.TransactionData.TransactionID = DefaultValues.LLUUID;

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
        
        static void GroupRoleMembersRequest_gen()
        {
            GroupRoleMembersRequestPacket packet = new GroupRoleMembersRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;
                packet.GroupData.GroupID = DefaultValues.LLUUID;
                packet.GroupData.RequestID = DefaultValues.LLUUID;

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
        
        static void AgentWearablesRequest_gen()
        {
            AgentWearablesRequestPacket packet = new AgentWearablesRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

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
        
        static void AgentDataUpdateRequest_gen()
        {
            AgentDataUpdateRequestPacket packet = new AgentDataUpdateRequestPacket();
                packet.AgentData.AgentID = DefaultValues.LLUUID;
                packet.AgentData.SessionID = DefaultValues.LLUUID;

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
            EconomyDataRequest_gen();
            AvatarPickerRequest_gen();
            PlacesQuery_gen();
            DirFindQuery_gen();
            DirPlacesQuery_gen();
            DirClassifiedQuery_gen();
            ClassifiedInfoRequest_gen();
            ClassifiedInfoUpdate_gen();
            ClassifiedDelete_gen();
            ClassifiedGodDelete_gen();
            DirLandQuery_gen();
            DirPopularQuery_gen();
            ParcelInfoRequest_gen();
            ParcelObjectOwnersRequest_gen();
            GroupNoticesListRequest_gen();
            GroupNoticeRequest_gen();
            TeleportRequest_gen();
            TeleportLocationRequest_gen();
            TeleportLandmarkRequest_gen();
            StartLure_gen();
            TeleportLureRequest_gen();
            TeleportCancel_gen();
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
            RequestRegionInfo_gen();
            RegionInfo_gen();
            GodUpdateRegionInfo_gen();
            RegionHandshakeReply_gen();
            TransferRequest_gen();
            TransferInfo_gen();
            TransferPacket_gen();
            TransferAbort_gen();
            RequestXfer_gen();
            SendXferPacket_gen();
            ConfirmXferPacket_gen();
            AbortXfer_gen();
            RequestPayPrice_gen();
            GodKickUser_gen();
            EjectUser_gen();
            FreezeUser_gen();
            AvatarPropertiesRequest_gen();
            AvatarPropertiesUpdate_gen();
            AvatarInterestsUpdate_gen();
            AvatarNotesUpdate_gen();
            EventInfoRequest_gen();
            EventNotificationAddRequest_gen();
            EventNotificationRemoveRequest_gen();
            EventGodDelete_gen();
            PickInfoUpdate_gen();
            PickDelete_gen();
            PickGodDelete_gen();
            ScriptDialogReply_gen();
            ForceScriptControlRelease_gen();
            RevokePermissions_gen();
            ParcelPropertiesRequest_gen();
            ParcelPropertiesRequestByID_gen();
            ParcelPropertiesUpdate_gen();
            ParcelReturnObjects_gen();
            ParcelSetOtherCleanTime_gen();
            ParcelDisableObjects_gen();
            ParcelSelectObjects_gen();
            EstateCovenantRequest_gen();
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
            ParcelAccessListUpdate_gen();
            ParcelDwellRequest_gen();
            ParcelGodMarkAsContent_gen();
            ViewerStartAuction_gen();
            UUIDNameRequest_gen();
            UUIDGroupNameRequest_gen();
            GetScriptRunning_gen();
            ScriptRunningReply_gen();
            SetScriptRunning_gen();
            ScriptReset_gen();
            CompleteAgentMovement_gen();
            AgentMovementComplete_gen();
            LogoutRequest_gen();
            ImprovedInstantMessage_gen();
            RetrieveInstantMessages_gen();
            FindAgent_gen();
            RequestGodlikePowers_gen();
            GodlikeMessage_gen();
            EstateOwnerMessage_gen();
            GenericMessage_gen();
            MuteListRequest_gen();
            UpdateMuteListEntry_gen();
            RemoveMuteListEntry_gen();
            CopyInventoryFromNotecard_gen();
            UpdateInventoryItem_gen();
            MoveInventoryItem_gen();
            CopyInventoryItem_gen();
            RemoveInventoryItem_gen();
            ChangeInventoryItemFlags_gen();
            CreateInventoryFolder_gen();
            UpdateInventoryFolder_gen();
            MoveInventoryFolder_gen();
            RemoveInventoryFolder_gen();
            FetchInventoryDescendents_gen();
            FetchInventory_gen();
            RemoveInventoryObjects_gen();
            PurgeInventoryDescendents_gen();
            UpdateTaskInventory_gen();
            RemoveTaskInventory_gen();
            MoveTaskInventory_gen();
            RequestTaskInventory_gen();
            DeRezObject_gen();
            RezObject_gen();
            RezObjectFromNotecard_gen();
            AcceptFriendship_gen();
            DeclineFriendship_gen();
            TerminateFriendship_gen();
            OfferCallingCard_gen();
            AcceptCallingCard_gen();
            DeclineCallingCard_gen();
            RezScript_gen();
            CreateInventoryItem_gen();
            CreateLandmarkForEvent_gen();
            RegionHandleRequest_gen();
            MoneyTransferRequest_gen();
            MoneyBalanceRequest_gen();
            ActivateGestures_gen();
            DeactivateGestures_gen();
            UseCachedMuteList_gen();
            GrantUserRights_gen();
            SetStartLocationRequest_gen();
            SoundTrigger_gen();
            AssetUploadRequest_gen();
            AssetUploadComplete_gen();
            CreateGroupRequest_gen();
            UpdateGroupInfo_gen();
            GroupRoleChanges_gen();
            JoinGroupRequest_gen();
            EjectGroupMemberRequest_gen();
            LeaveGroupRequest_gen();
            InviteGroupRequest_gen();
            GroupProfileRequest_gen();
            GroupAccountSummaryRequest_gen();
            GroupAccountDetailsRequest_gen();
            GroupAccountTransactionsRequest_gen();
            GroupActiveProposalsRequest_gen();
            GroupVoteHistoryRequest_gen();
            StartGroupProposal_gen();
            GroupProposalBallot_gen();
            GroupMembersRequest_gen();
            ActivateGroup_gen();
            SetGroupContribution_gen();
            SetGroupAcceptNotices_gen();
            GroupRoleDataRequest_gen();
            GroupRoleMembersRequest_gen();
            GroupTitlesRequest_gen();
            GroupTitleUpdate_gen();
            GroupRoleUpdate_gen();
            AgentWearablesRequest_gen();
            AgentIsNowWearing_gen();
            AgentCachedTexture_gen();
            AgentDataUpdateRequest_gen();
            ViewerEffect_gen();
            CreateTrustedCircuit_gen();
            DenyTrustedCircuit_gen();
            RezSingleAttachmentFromInv_gen();
            RezMultipleAttachmentsFromInv_gen();
            DetachAttachmentIntoInv_gen();
            CreateNewOutfitAttachments_gen();
            UserInfoRequest_gen();
            UserInfoReply_gen();
            UpdateUserInfo_gen();
            InitiateDownload_gen();
            MapLayerRequest_gen();
            MapBlockRequest_gen();
            MapNameRequest_gen();
            MapItemRequest_gen();
            SendPostcard_gen();
            LandStatRequest_gen();
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


