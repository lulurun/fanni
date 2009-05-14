#ifndef PACKET_IMPL_H_
#define PACKET_IMPL_H_

#include "PacketBaseTypes.h"
#include "PacketBase.h"

namespace Fanni {

typedef enum {
	 TestMessage_ID = 0xffff0001,
	 PacketAck_ID = 0xFFFFFFFB,
	 OpenCircuit_ID = 0xFFFFFFFC,
	 CloseCircuit_ID = 0xFFFFFFFD,
	 StartPingCheck_ID = 0x00000001,
	 CompletePingCheck_ID = 0x00000002,
	 AddCircuitCode_ID = 0xffff0002,
	 UseCircuitCode_ID = 0xffff0003,
	 NeighborList_ID = 0x00000003,
	 AvatarTextureUpdate_ID = 0xffff0004,
	 SimulatorMapUpdate_ID = 0xffff0005,
	 SimulatorSetMap_ID = 0xffff0006,
	 SubscribeLoad_ID = 0xffff0007,
	 UnsubscribeLoad_ID = 0xffff0008,
	 SimulatorReady_ID = 0xffff0009,
	 TelehubInfo_ID = 0xffff000a,
	 SimulatorPresentAtLocation_ID = 0xffff000b,
	 SimulatorLoad_ID = 0xffff000c,
	 SimulatorShutdownRequest_ID = 0xffff000d,
	 RegionPresenceRequestByRegionID_ID = 0xffff000e,
	 RegionPresenceRequestByHandle_ID = 0xffff000f,
	 RegionPresenceResponse_ID = 0xffff0010,
	 UpdateSimulator_ID = 0xffff0011,
	 LogDwellTime_ID = 0xffff0012,
	 FeatureDisabled_ID = 0xffff0013,
	 LogFailedMoneyTransaction_ID = 0xffff0014,
	 UserReportInternal_ID = 0xffff0015,
	 SetSimStatusInDatabase_ID = 0xffff0016,
	 SetSimPresenceInDatabase_ID = 0xffff0017,
	 EconomyDataRequest_ID = 0xffff0018,
	 EconomyData_ID = 0xffff0019,
	 AvatarPickerRequest_ID = 0xffff001a,
	 AvatarPickerRequestBackend_ID = 0xffff001b,
	 AvatarPickerReply_ID = 0xffff001c,
	 PlacesQuery_ID = 0xffff001d,
	 PlacesReply_ID = 0xffff001e,
	 DirFindQuery_ID = 0xffff001f,
	 DirFindQueryBackend_ID = 0xffff0020,
	 DirPlacesQuery_ID = 0xffff0021,
	 DirPlacesQueryBackend_ID = 0xffff0022,
	 DirPlacesReply_ID = 0xffff0023,
	 DirPeopleReply_ID = 0xffff0024,
	 DirEventsReply_ID = 0xffff0025,
	 DirGroupsReply_ID = 0xffff0026,
	 DirClassifiedQuery_ID = 0xffff0027,
	 DirClassifiedQueryBackend_ID = 0xffff0028,
	 DirClassifiedReply_ID = 0xffff0029,
	 AvatarClassifiedReply_ID = 0xffff002a,
	 ClassifiedInfoRequest_ID = 0xffff002b,
	 ClassifiedInfoReply_ID = 0xffff002c,
	 ClassifiedInfoUpdate_ID = 0xffff002d,
	 ClassifiedDelete_ID = 0xffff002e,
	 ClassifiedGodDelete_ID = 0xffff002f,
	 DirLandQuery_ID = 0xffff0030,
	 DirLandQueryBackend_ID = 0xffff0031,
	 DirLandReply_ID = 0xffff0032,
	 DirPopularQuery_ID = 0xffff0033,
	 DirPopularQueryBackend_ID = 0xffff0034,
	 DirPopularReply_ID = 0xffff0035,
	 ParcelInfoRequest_ID = 0xffff0036,
	 ParcelInfoReply_ID = 0xffff0037,
	 ParcelObjectOwnersRequest_ID = 0xffff0038,
	 ParcelObjectOwnersReply_ID = 0xffff0039,
	 GroupNoticesListRequest_ID = 0xffff003a,
	 GroupNoticesListReply_ID = 0xffff003b,
	 GroupNoticeRequest_ID = 0xffff003c,
	 GroupNoticeAdd_ID = 0xffff003d,
	 TeleportRequest_ID = 0xffff003e,
	 TeleportLocationRequest_ID = 0xffff003f,
	 TeleportLocal_ID = 0xffff0040,
	 TeleportLandmarkRequest_ID = 0xffff0041,
	 TeleportProgress_ID = 0xffff0042,
	 DataHomeLocationRequest_ID = 0xffff0043,
	 DataHomeLocationReply_ID = 0xffff0044,
	 TeleportFinish_ID = 0xffff0045,
	 StartLure_ID = 0xffff0046,
	 TeleportLureRequest_ID = 0xffff0047,
	 TeleportCancel_ID = 0xffff0048,
	 TeleportStart_ID = 0xffff0049,
	 TeleportFailed_ID = 0xffff004a,
	 Undo_ID = 0xffff004b,
	 Redo_ID = 0xffff004c,
	 UndoLand_ID = 0xffff004d,
	 AgentPause_ID = 0xffff004e,
	 AgentResume_ID = 0xffff004f,
	 AgentUpdate_ID = 0x00000004,
	 ChatFromViewer_ID = 0xffff0050,
	 AgentThrottle_ID = 0xffff0051,
	 AgentFOV_ID = 0xffff0052,
	 AgentHeightWidth_ID = 0xffff0053,
	 AgentSetAppearance_ID = 0xffff0054,
	 AgentAnimation_ID = 0x00000005,
	 AgentRequestSit_ID = 0x00000006,
	 AgentSit_ID = 0x00000007,
	 AgentQuitCopy_ID = 0xffff0055,
	 RequestImage_ID = 0x00000008,
	 ImageNotInDatabase_ID = 0xffff0056,
	 RebakeAvatarTextures_ID = 0xffff0057,
	 SetAlwaysRun_ID = 0xffff0058,
	 ObjectAdd_ID = 0x00ff0001,
	 ObjectDelete_ID = 0xffff0059,
	 ObjectDuplicate_ID = 0xffff005a,
	 ObjectDuplicateOnRay_ID = 0xffff005b,
	 MultipleObjectUpdate_ID = 0x00ff0002,
	 RequestMultipleObjects_ID = 0x00ff0003,
	 ObjectPosition_ID = 0x00ff0004,
	 ObjectScale_ID = 0xffff005c,
	 ObjectRotation_ID = 0xffff005d,
	 ObjectFlagUpdate_ID = 0xffff005e,
	 ObjectClickAction_ID = 0xffff005f,
	 ObjectImage_ID = 0xffff0060,
	 ObjectMaterial_ID = 0xffff0061,
	 ObjectShape_ID = 0xffff0062,
	 ObjectExtraParams_ID = 0xffff0063,
	 ObjectOwner_ID = 0xffff0064,
	 ObjectGroup_ID = 0xffff0065,
	 ObjectBuy_ID = 0xffff0066,
	 BuyObjectInventory_ID = 0xffff0067,
	 DerezContainer_ID = 0xffff0068,
	 ObjectPermissions_ID = 0xffff0069,
	 ObjectSaleInfo_ID = 0xffff006a,
	 ObjectName_ID = 0xffff006b,
	 ObjectDescription_ID = 0xffff006c,
	 ObjectCategory_ID = 0xffff006d,
	 ObjectSelect_ID = 0xffff006e,
	 ObjectDeselect_ID = 0xffff006f,
	 ObjectAttach_ID = 0xffff0070,
	 ObjectDetach_ID = 0xffff0071,
	 ObjectDrop_ID = 0xffff0072,
	 ObjectLink_ID = 0xffff0073,
	 ObjectDelink_ID = 0xffff0074,
	 ObjectGrab_ID = 0xffff0075,
	 ObjectGrabUpdate_ID = 0xffff0076,
	 ObjectDeGrab_ID = 0xffff0077,
	 ObjectSpinStart_ID = 0xffff0078,
	 ObjectSpinUpdate_ID = 0xffff0079,
	 ObjectSpinStop_ID = 0xffff007a,
	 ObjectExportSelected_ID = 0xffff007b,
	 ModifyLand_ID = 0xffff007c,
	 VelocityInterpolateOn_ID = 0xffff007d,
	 VelocityInterpolateOff_ID = 0xffff007e,
	 StateSave_ID = 0xffff007f,
	 ReportAutosaveCrash_ID = 0xffff0080,
	 SimWideDeletes_ID = 0xffff0081,
	 RequestObjectPropertiesFamily_ID = 0x00ff0005,
	 TrackAgent_ID = 0xffff0082,
	 ViewerStats_ID = 0xffff0083,
	 ScriptAnswerYes_ID = 0xffff0084,
	 UserReport_ID = 0xffff0085,
	 AlertMessage_ID = 0xffff0086,
	 AgentAlertMessage_ID = 0xffff0087,
	 MeanCollisionAlert_ID = 0xffff0088,
	 ViewerFrozenMessage_ID = 0xffff0089,
	 HealthMessage_ID = 0xffff008a,
	 ChatFromSimulator_ID = 0xffff008b,
	 SimStats_ID = 0xffff008c,
	 RequestRegionInfo_ID = 0xffff008d,
	 RegionInfo_ID = 0xffff008e,
	 GodUpdateRegionInfo_ID = 0xffff008f,
	 NearestLandingRegionRequest_ID = 0xffff0090,
	 NearestLandingRegionReply_ID = 0xffff0091,
	 NearestLandingRegionUpdated_ID = 0xffff0092,
	 TeleportLandingStatusChanged_ID = 0xffff0093,
	 RegionHandshake_ID = 0xffff0094,
	 RegionHandshakeReply_ID = 0xffff0095,
	 CoarseLocationUpdate_ID = 0x00ff0006,
	 ImageData_ID = 0x00000009,
	 ImagePacket_ID = 0x0000000a,
	 LayerData_ID = 0x0000000b,
	 ObjectUpdate_ID = 0x0000000c,
	 ObjectUpdateCompressed_ID = 0x0000000d,
	 ObjectUpdateCached_ID = 0x0000000e,
	 ImprovedTerseObjectUpdate_ID = 0x0000000f,
	 KillObject_ID = 0x00000010,
	 CrossedRegion_ID = 0x00ff0007,
	 SimulatorViewerTimeMessage_ID = 0xffff0096,
	 EnableSimulator_ID = 0xffff0097,
	 DisableSimulator_ID = 0xffff0098,
	 ConfirmEnableSimulator_ID = 0x00ff0008,
	 TransferRequest_ID = 0xffff0099,
	 TransferInfo_ID = 0xffff009a,
	 TransferPacket_ID = 0x00000011,
	 TransferAbort_ID = 0xffff009b,
	 RequestXfer_ID = 0xffff009c,
	 SendXferPacket_ID = 0x00000012,
	 ConfirmXferPacket_ID = 0x00000013,
	 AbortXfer_ID = 0xffff009d,
	 AvatarAnimation_ID = 0x00000014,
	 AvatarAppearance_ID = 0xffff009e,
	 AvatarSitResponse_ID = 0x00000015,
	 SetFollowCamProperties_ID = 0xffff009f,
	 ClearFollowCamProperties_ID = 0xffff00a0,
	 CameraConstraint_ID = 0x00000016,
	 ObjectProperties_ID = 0x00ff0009,
	 ObjectPropertiesFamily_ID = 0x00ff000a,
	 RequestPayPrice_ID = 0xffff00a1,
	 PayPriceReply_ID = 0xffff00a2,
	 KickUser_ID = 0xffff00a3,
	 KickUserAck_ID = 0xffff00a4,
	 GodKickUser_ID = 0xffff00a5,
	 SystemKickUser_ID = 0xffff00a6,
	 EjectUser_ID = 0xffff00a7,
	 FreezeUser_ID = 0xffff00a8,
	 AvatarPropertiesRequest_ID = 0xffff00a9,
	 AvatarPropertiesRequestBackend_ID = 0xffff00aa,
	 AvatarPropertiesReply_ID = 0xffff00ab,
	 AvatarInterestsReply_ID = 0xffff00ac,
	 AvatarGroupsReply_ID = 0xffff00ad,
	 AvatarPropertiesUpdate_ID = 0xffff00ae,
	 AvatarInterestsUpdate_ID = 0xffff00af,
	 AvatarNotesReply_ID = 0xffff00b0,
	 AvatarNotesUpdate_ID = 0xffff00b1,
	 AvatarPicksReply_ID = 0xffff00b2,
	 EventInfoRequest_ID = 0xffff00b3,
	 EventInfoReply_ID = 0xffff00b4,
	 EventNotificationAddRequest_ID = 0xffff00b5,
	 EventNotificationRemoveRequest_ID = 0xffff00b6,
	 EventGodDelete_ID = 0xffff00b7,
	 PickInfoReply_ID = 0xffff00b8,
	 PickInfoUpdate_ID = 0xffff00b9,
	 PickDelete_ID = 0xffff00ba,
	 PickGodDelete_ID = 0xffff00bb,
	 ScriptQuestion_ID = 0xffff00bc,
	 ScriptControlChange_ID = 0xffff00bd,
	 ScriptDialog_ID = 0xffff00be,
	 ScriptDialogReply_ID = 0xffff00bf,
	 ForceScriptControlRelease_ID = 0xffff00c0,
	 RevokePermissions_ID = 0xffff00c1,
	 LoadURL_ID = 0xffff00c2,
	 ScriptTeleportRequest_ID = 0xffff00c3,
	 ParcelOverlay_ID = 0xffff00c4,
	 ParcelPropertiesRequest_ID = 0x00ff000b,
	 ParcelPropertiesRequestByID_ID = 0xffff00c5,
	 ParcelProperties_ID = 0x00000017,
	 ParcelPropertiesUpdate_ID = 0xffff00c6,
	 ParcelReturnObjects_ID = 0xffff00c7,
	 ParcelSetOtherCleanTime_ID = 0xffff00c8,
	 ParcelDisableObjects_ID = 0xffff00c9,
	 ParcelSelectObjects_ID = 0xffff00ca,
	 EstateCovenantRequest_ID = 0xffff00cb,
	 EstateCovenantReply_ID = 0xffff00cc,
	 ForceObjectSelect_ID = 0xffff00cd,
	 ParcelBuyPass_ID = 0xffff00ce,
	 ParcelDeedToGroup_ID = 0xffff00cf,
	 ParcelReclaim_ID = 0xffff00d0,
	 ParcelClaim_ID = 0xffff00d1,
	 ParcelJoin_ID = 0xffff00d2,
	 ParcelDivide_ID = 0xffff00d3,
	 ParcelRelease_ID = 0xffff00d4,
	 ParcelBuy_ID = 0xffff00d5,
	 ParcelGodForceOwner_ID = 0xffff00d6,
	 ParcelAccessListRequest_ID = 0xffff00d7,
	 ParcelAccessListReply_ID = 0xffff00d8,
	 ParcelAccessListUpdate_ID = 0xffff00d9,
	 ParcelDwellRequest_ID = 0xffff00da,
	 ParcelDwellReply_ID = 0xffff00db,
	 RequestParcelTransfer_ID = 0xffff00dc,
	 UpdateParcel_ID = 0xffff00dd,
	 RemoveParcel_ID = 0xffff00de,
	 MergeParcel_ID = 0xffff00df,
	 LogParcelChanges_ID = 0xffff00e0,
	 CheckParcelSales_ID = 0xffff00e1,
	 ParcelSales_ID = 0xffff00e2,
	 ParcelGodMarkAsContent_ID = 0xffff00e3,
	 ViewerStartAuction_ID = 0xffff00e4,
	 StartAuction_ID = 0xffff00e5,
	 ConfirmAuctionStart_ID = 0xffff00e6,
	 CompleteAuction_ID = 0xffff00e7,
	 CancelAuction_ID = 0xffff00e8,
	 CheckParcelAuctions_ID = 0xffff00e9,
	 ParcelAuctions_ID = 0xffff00ea,
	 UUIDNameRequest_ID = 0xffff00eb,
	 UUIDNameReply_ID = 0xffff00ec,
	 UUIDGroupNameRequest_ID = 0xffff00ed,
	 UUIDGroupNameReply_ID = 0xffff00ee,
	 ChatPass_ID = 0xffff00ef,
	 EdgeDataPacket_ID = 0x00000018,
	 SimStatus_ID = 0x00ff000c,
	 ChildAgentUpdate_ID = 0x00000019,
	 ChildAgentAlive_ID = 0x0000001a,
	 ChildAgentPositionUpdate_ID = 0x0000001b,
	 ChildAgentDying_ID = 0xffff00f0,
	 ChildAgentUnknown_ID = 0xffff00f1,
	 AtomicPassObject_ID = 0x0000001c,
	 KillChildAgents_ID = 0xffff00f2,
	 GetScriptRunning_ID = 0xffff00f3,
	 ScriptRunningReply_ID = 0xffff00f4,
	 SetScriptRunning_ID = 0xffff00f5,
	 ScriptReset_ID = 0xffff00f6,
	 ScriptSensorRequest_ID = 0xffff00f7,
	 ScriptSensorReply_ID = 0xffff00f8,
	 CompleteAgentMovement_ID = 0xffff00f9,
	 AgentMovementComplete_ID = 0xffff00fa,
	 DataServerLogout_ID = 0xffff00fb,
	 LogoutRequest_ID = 0xffff00fc,
	 LogoutReply_ID = 0xffff00fd,
	 ImprovedInstantMessage_ID = 0xffff00fe,
	 RetrieveInstantMessages_ID = 0xffff00ff,
	 FindAgent_ID = 0xffff0100,
	 RequestGodlikePowers_ID = 0xffff0101,
	 GrantGodlikePowers_ID = 0xffff0102,
	 GodlikeMessage_ID = 0xffff0103,
	 EstateOwnerMessage_ID = 0xffff0104,
	 GenericMessage_ID = 0xffff0105,
	 MuteListRequest_ID = 0xffff0106,
	 UpdateMuteListEntry_ID = 0xffff0107,
	 RemoveMuteListEntry_ID = 0xffff0108,
	 CopyInventoryFromNotecard_ID = 0xffff0109,
	 UpdateInventoryItem_ID = 0xffff010a,
	 UpdateCreateInventoryItem_ID = 0xffff010b,
	 MoveInventoryItem_ID = 0xffff010c,
	 CopyInventoryItem_ID = 0xffff010d,
	 RemoveInventoryItem_ID = 0xffff010e,
	 ChangeInventoryItemFlags_ID = 0xffff010f,
	 SaveAssetIntoInventory_ID = 0xffff0110,
	 CreateInventoryFolder_ID = 0xffff0111,
	 UpdateInventoryFolder_ID = 0xffff0112,
	 MoveInventoryFolder_ID = 0xffff0113,
	 RemoveInventoryFolder_ID = 0xffff0114,
	 FetchInventoryDescendents_ID = 0xffff0115,
	 InventoryDescendents_ID = 0xffff0116,
	 FetchInventory_ID = 0xffff0117,
	 FetchInventoryReply_ID = 0xffff0118,
	 BulkUpdateInventory_ID = 0xffff0119,
	 RequestInventoryAsset_ID = 0xffff011a,
	 InventoryAssetResponse_ID = 0xffff011b,
	 RemoveInventoryObjects_ID = 0xffff011c,
	 PurgeInventoryDescendents_ID = 0xffff011d,
	 UpdateTaskInventory_ID = 0xffff011e,
	 RemoveTaskInventory_ID = 0xffff011f,
	 MoveTaskInventory_ID = 0xffff0120,
	 RequestTaskInventory_ID = 0xffff0121,
	 ReplyTaskInventory_ID = 0xffff0122,
	 DeRezObject_ID = 0xffff0123,
	 DeRezAck_ID = 0xffff0124,
	 RezObject_ID = 0xffff0125,
	 RezObjectFromNotecard_ID = 0xffff0126,
	 TransferInventory_ID = 0xffff0127,
	 TransferInventoryAck_ID = 0xffff0128,
	 AcceptFriendship_ID = 0xffff0129,
	 DeclineFriendship_ID = 0xffff012a,
	 FormFriendship_ID = 0xffff012b,
	 TerminateFriendship_ID = 0xffff012c,
	 OfferCallingCard_ID = 0xffff012d,
	 AcceptCallingCard_ID = 0xffff012e,
	 DeclineCallingCard_ID = 0xffff012f,
	 RezScript_ID = 0xffff0130,
	 CreateInventoryItem_ID = 0xffff0131,
	 CreateLandmarkForEvent_ID = 0xffff0132,
	 EventLocationRequest_ID = 0xffff0133,
	 EventLocationReply_ID = 0xffff0134,
	 RegionHandleRequest_ID = 0xffff0135,
	 RegionIDAndHandleReply_ID = 0xffff0136,
	 MoneyTransferRequest_ID = 0xffff0137,
	 MoneyTransferBackend_ID = 0xffff0138,
	 MoneyBalanceRequest_ID = 0xffff0139,
	 MoneyBalanceReply_ID = 0xffff013a,
	 RoutedMoneyBalanceReply_ID = 0xffff013b,
	 ActivateGestures_ID = 0xffff013c,
	 DeactivateGestures_ID = 0xffff013d,
	 MuteListUpdate_ID = 0xffff013e,
	 UseCachedMuteList_ID = 0xffff013f,
	 GrantUserRights_ID = 0xffff0140,
	 ChangeUserRights_ID = 0xffff0141,
	 OnlineNotification_ID = 0xffff0142,
	 OfflineNotification_ID = 0xffff0143,
	 SetStartLocationRequest_ID = 0xffff0144,
	 SetStartLocation_ID = 0xffff0145,
	 NetTest_ID = 0xffff0146,
	 SetCPURatio_ID = 0xffff0147,
	 SimCrashed_ID = 0xffff0148,
	 NameValuePair_ID = 0xffff0149,
	 RemoveNameValuePair_ID = 0xffff014a,
	 UpdateAttachment_ID = 0xffff014b,
	 RemoveAttachment_ID = 0xffff014c,
	 SoundTrigger_ID = 0x0000001d,
	 AttachedSound_ID = 0x00ff000d,
	 AttachedSoundGainChange_ID = 0x00ff000e,
	 PreloadSound_ID = 0x00ff000f,
	 AssetUploadRequest_ID = 0xffff014d,
	 AssetUploadComplete_ID = 0xffff014e,
	 EmailMessageRequest_ID = 0xffff014f,
	 EmailMessageReply_ID = 0xffff0150,
	 InternalScriptMail_ID = 0x00ff0010,
	 ScriptDataRequest_ID = 0xffff0151,
	 ScriptDataReply_ID = 0xffff0152,
	 CreateGroupRequest_ID = 0xffff0153,
	 CreateGroupReply_ID = 0xffff0154,
	 UpdateGroupInfo_ID = 0xffff0155,
	 GroupRoleChanges_ID = 0xffff0156,
	 JoinGroupRequest_ID = 0xffff0157,
	 JoinGroupReply_ID = 0xffff0158,
	 EjectGroupMemberRequest_ID = 0xffff0159,
	 EjectGroupMemberReply_ID = 0xffff015a,
	 LeaveGroupRequest_ID = 0xffff015b,
	 LeaveGroupReply_ID = 0xffff015c,
	 InviteGroupRequest_ID = 0xffff015d,
	 InviteGroupResponse_ID = 0xffff015e,
	 GroupProfileRequest_ID = 0xffff015f,
	 GroupProfileReply_ID = 0xffff0160,
	 GroupAccountSummaryRequest_ID = 0xffff0161,
	 GroupAccountSummaryReply_ID = 0xffff0162,
	 GroupAccountDetailsRequest_ID = 0xffff0163,
	 GroupAccountDetailsReply_ID = 0xffff0164,
	 GroupAccountTransactionsRequest_ID = 0xffff0165,
	 GroupAccountTransactionsReply_ID = 0xffff0166,
	 GroupActiveProposalsRequest_ID = 0xffff0167,
	 GroupActiveProposalItemReply_ID = 0xffff0168,
	 GroupVoteHistoryRequest_ID = 0xffff0169,
	 GroupVoteHistoryItemReply_ID = 0xffff016a,
	 StartGroupProposal_ID = 0xffff016b,
	 GroupProposalBallot_ID = 0xffff016c,
	 TallyVotes_ID = 0xffff016d,
	 GroupMembersRequest_ID = 0xffff016e,
	 GroupMembersReply_ID = 0xffff016f,
	 ActivateGroup_ID = 0xffff0170,
	 SetGroupContribution_ID = 0xffff0171,
	 SetGroupAcceptNotices_ID = 0xffff0172,
	 GroupRoleDataRequest_ID = 0xffff0173,
	 GroupRoleDataReply_ID = 0xffff0174,
	 GroupRoleMembersRequest_ID = 0xffff0175,
	 GroupRoleMembersReply_ID = 0xffff0176,
	 GroupTitlesRequest_ID = 0xffff0177,
	 GroupTitlesReply_ID = 0xffff0178,
	 GroupTitleUpdate_ID = 0xffff0179,
	 GroupRoleUpdate_ID = 0xffff017a,
	 LiveHelpGroupRequest_ID = 0xffff017b,
	 LiveHelpGroupReply_ID = 0xffff017c,
	 AgentWearablesRequest_ID = 0xffff017d,
	 AgentWearablesUpdate_ID = 0xffff017e,
	 AgentIsNowWearing_ID = 0xffff017f,
	 AgentCachedTexture_ID = 0xffff0180,
	 AgentCachedTextureResponse_ID = 0xffff0181,
	 AgentDataUpdateRequest_ID = 0xffff0182,
	 AgentDataUpdate_ID = 0xffff0183,
	 GroupDataUpdate_ID = 0xffff0184,
	 AgentGroupDataUpdate_ID = 0xffff0185,
	 AgentDropGroup_ID = 0xffff0186,
	 LogTextMessage_ID = 0xffff0187,
	 ViewerEffect_ID = 0x00ff0011,
	 CreateTrustedCircuit_ID = 0xffff0188,
	 DenyTrustedCircuit_ID = 0xffff0189,
	 RequestTrustedCircuit_ID = 0xffff018a,
	 RezSingleAttachmentFromInv_ID = 0xffff018b,
	 RezMultipleAttachmentsFromInv_ID = 0xffff018c,
	 DetachAttachmentIntoInv_ID = 0xffff018d,
	 CreateNewOutfitAttachments_ID = 0xffff018e,
	 UserInfoRequest_ID = 0xffff018f,
	 UserInfoReply_ID = 0xffff0190,
	 UpdateUserInfo_ID = 0xffff0191,
	 ParcelRename_ID = 0xffff0192,
	 InitiateDownload_ID = 0xffff0193,
	 SystemMessage_ID = 0xffff0194,
	 MapLayerRequest_ID = 0xffff0195,
	 MapLayerReply_ID = 0xffff0196,
	 MapBlockRequest_ID = 0xffff0197,
	 MapNameRequest_ID = 0xffff0198,
	 MapBlockReply_ID = 0xffff0199,
	 MapItemRequest_ID = 0xffff019a,
	 MapItemReply_ID = 0xffff019b,
	 SendPostcard_ID = 0xffff019c,
	 RpcChannelRequest_ID = 0xffff019d,
	 RpcChannelReply_ID = 0xffff019e,
	 RpcScriptRequestInbound_ID = 0xffff019f,
	 RpcScriptRequestInboundForward_ID = 0xffff01a0,
	 RpcScriptReplyInbound_ID = 0xffff01a1,
	 ScriptMailRegistration_ID = 0xffff01a2,
	 ParcelMediaCommandMessage_ID = 0xffff01a3,
	 ParcelMediaUpdate_ID = 0xffff01a4,
	 LandStatRequest_ID = 0xffff01a5,
	 LandStatReply_ID = 0xffff01a6,
	 Error_ID = 0xffff01a7,
	 ObjectIncludeInSearch_ID = 0xffff01a8,
} PacketID;


// TestMessagePacket
class TestMessagePacket : public PacketBase {
public:

    // Block Class List
    class TestBlock1Block : public PacketSerializable {
    public:
        // TestBlock1Block Member List
        SerializableU32 Test1;
    public:
        TestBlock1Block() {};
        virtual ~TestBlock1Block() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Test1.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Test1.deserialize(buffer);
        }
    };
    class NeighborBlockBlock : public PacketSerializable {
    public:
        // NeighborBlockBlock Member List
        SerializableU32 Test0;
        SerializableU32 Test1;
        SerializableU32 Test2;
    public:
        NeighborBlockBlock() {};
        virtual ~NeighborBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Test0.serialize(buffer);
            Test1.serialize(buffer);
            Test2.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Test0.deserialize(buffer);
            Test1.deserialize(buffer);
            Test2.deserialize(buffer);
        }
    };
    // TestMessagePacket Member List
    TestBlock1Block TestBlock1;
    MultipleSerializable<NeighborBlockBlock, 4> NeighborBlock;

public:
    TestMessagePacket() {
        this->setID(TestMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TestMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TestBlock1.serialize(buffer);
        NeighborBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TestBlock1.deserialize(buffer);
        NeighborBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TestMessagePacket();
    }
};

// PacketAckPacket
class PacketAckPacket : public PacketBase {
public:

    // Block Class List
    class PacketsBlock : public PacketSerializable {
    public:
        // PacketsBlock Member List
        SerializableU32 ID;
    public:
        PacketsBlock() {};
        virtual ~PacketsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // PacketAckPacket Member List
    VariableSerializable<PacketsBlock> Packets;

public:
    PacketAckPacket() {
        this->setID(PacketAck_ID);
    };
    virtual ~PacketAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Packets.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Packets.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PacketAckPacket();
    }
};

// OpenCircuitPacket
class OpenCircuitPacket : public PacketBase {
public:

    // Block Class List
    class CircuitInfoBlock : public PacketSerializable {
    public:
        // CircuitInfoBlock Member List
        SerializableIPADDR IP;
        SerializableIPPORT Port;
    public:
        CircuitInfoBlock() {};
        virtual ~CircuitInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IP.serialize(buffer);
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IP.deserialize(buffer);
            Port.deserialize(buffer);
        }
    };
    // OpenCircuitPacket Member List
    CircuitInfoBlock CircuitInfo;

public:
    OpenCircuitPacket() {
        this->setID(OpenCircuit_ID);
    };
    virtual ~OpenCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CircuitInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CircuitInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OpenCircuitPacket();
    }
};

// CloseCircuitPacket
class CloseCircuitPacket : public PacketBase {
public:

    // Block Class List
    // CloseCircuitPacket Member List

public:
    CloseCircuitPacket() {
        this->setID(CloseCircuit_ID);
    };
    virtual ~CloseCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new CloseCircuitPacket();
    }
};

// StartPingCheckPacket
class StartPingCheckPacket : public PacketBase {
public:

    // Block Class List
    class PingIDBlock : public PacketSerializable {
    public:
        // PingIDBlock Member List
        SerializableU8 PingID;
        SerializableU32 OldestUnacked;
    public:
        PingIDBlock() {};
        virtual ~PingIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PingID.serialize(buffer);
            OldestUnacked.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PingID.deserialize(buffer);
            OldestUnacked.deserialize(buffer);
        }
    };
    // StartPingCheckPacket Member List
    PingIDBlock PingID;

public:
    StartPingCheckPacket() {
        this->setID(StartPingCheck_ID);
    };
    virtual ~StartPingCheckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        PingID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        PingID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartPingCheckPacket();
    }
};

// CompletePingCheckPacket
class CompletePingCheckPacket : public PacketBase {
public:

    // Block Class List
    class PingIDBlock : public PacketSerializable {
    public:
        // PingIDBlock Member List
        SerializableU8 PingID;
    public:
        PingIDBlock() {};
        virtual ~PingIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PingID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PingID.deserialize(buffer);
        }
    };
    // CompletePingCheckPacket Member List
    PingIDBlock PingID;

public:
    CompletePingCheckPacket() {
        this->setID(CompletePingCheck_ID);
    };
    virtual ~CompletePingCheckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        PingID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        PingID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CompletePingCheckPacket();
    }
};

// AddCircuitCodePacket
class AddCircuitCodePacket : public PacketBase {
public:

    // Block Class List
    class CircuitCodeBlock : public PacketSerializable {
    public:
        // CircuitCodeBlock Member List
        SerializableU32 Code;
        SerializableUUID SessionID;
        SerializableUUID AgentID;
    public:
        CircuitCodeBlock() {};
        virtual ~CircuitCodeBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
            SessionID.serialize(buffer);
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
            SessionID.deserialize(buffer);
            AgentID.deserialize(buffer);
        }
    };
    // AddCircuitCodePacket Member List
    CircuitCodeBlock CircuitCode;

public:
    AddCircuitCodePacket() {
        this->setID(AddCircuitCode_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AddCircuitCodePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CircuitCode.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CircuitCode.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AddCircuitCodePacket();
    }
};

// UseCircuitCodePacket
class UseCircuitCodePacket : public PacketBase {
public:

    // Block Class List
    class CircuitCodeBlock : public PacketSerializable {
    public:
        // CircuitCodeBlock Member List
        SerializableU32 Code;
        SerializableUUID SessionID;
        SerializableUUID ID;
    public:
        CircuitCodeBlock() {};
        virtual ~CircuitCodeBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
            SessionID.serialize(buffer);
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
            SessionID.deserialize(buffer);
            ID.deserialize(buffer);
        }
    };
    // UseCircuitCodePacket Member List
    CircuitCodeBlock CircuitCode;

public:
    UseCircuitCodePacket() {
        this->setID(UseCircuitCode_ID);
    };
    virtual ~UseCircuitCodePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CircuitCode.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CircuitCode.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UseCircuitCodePacket();
    }
};

// NeighborListPacket
class NeighborListPacket : public PacketBase {
public:

    // Block Class List
    class NeighborBlockBlock : public PacketSerializable {
    public:
        // NeighborBlockBlock Member List
        SerializableIPADDR IP;
        SerializableIPPORT Port;
        SerializableIPADDR PublicIP;
        SerializableIPPORT PublicPort;
        SerializableUUID RegionID;
        SerializableVariable1 Name;
        SerializableU8 SimAccess;
    public:
        NeighborBlockBlock() {};
        virtual ~NeighborBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IP.serialize(buffer);
            Port.serialize(buffer);
            PublicIP.serialize(buffer);
            PublicPort.serialize(buffer);
            RegionID.serialize(buffer);
            Name.serialize(buffer);
            SimAccess.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IP.deserialize(buffer);
            Port.deserialize(buffer);
            PublicIP.deserialize(buffer);
            PublicPort.deserialize(buffer);
            RegionID.deserialize(buffer);
            Name.deserialize(buffer);
            SimAccess.deserialize(buffer);
        }
    };
    // NeighborListPacket Member List
    MultipleSerializable<NeighborBlockBlock, 4> NeighborBlock;

public:
    NeighborListPacket() {
        this->setID(NeighborList_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~NeighborListPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        NeighborBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        NeighborBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NeighborListPacket();
    }
};

// AvatarTextureUpdatePacket
class AvatarTextureUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableBool TexturesChanged;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TexturesChanged.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TexturesChanged.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID CacheID;
        SerializableU8 TextureIndex;
        SerializableVariable1 HostName;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CacheID.serialize(buffer);
            TextureIndex.serialize(buffer);
            HostName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CacheID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
            HostName.deserialize(buffer);
        }
    };
    class TextureDataBlock : public PacketSerializable {
    public:
        // TextureDataBlock Member List
        SerializableUUID TextureID;
    public:
        TextureDataBlock() {};
        virtual ~TextureDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureID.deserialize(buffer);
        }
    };
    // AvatarTextureUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;
    VariableSerializable<TextureDataBlock> TextureData;

public:
    AvatarTextureUpdatePacket() {
        this->setID(AvatarTextureUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarTextureUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
        TextureData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
        TextureData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarTextureUpdatePacket();
    }
};

// SimulatorMapUpdatePacket
class SimulatorMapUpdatePacket : public PacketBase {
public:

    // Block Class List
    class MapDataBlock : public PacketSerializable {
    public:
        // MapDataBlock Member List
        SerializableU32 Flags;
    public:
        MapDataBlock() {};
        virtual ~MapDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
        }
    };
    // SimulatorMapUpdatePacket Member List
    MapDataBlock MapData;

public:
    SimulatorMapUpdatePacket() {
        this->setID(SimulatorMapUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorMapUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MapData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MapData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorMapUpdatePacket();
    }
};

// SimulatorSetMapPacket
class SimulatorSetMapPacket : public PacketBase {
public:

    // Block Class List
    class MapDataBlock : public PacketSerializable {
    public:
        // MapDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableS32 Type;
        SerializableUUID MapImage;
    public:
        MapDataBlock() {};
        virtual ~MapDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            Type.serialize(buffer);
            MapImage.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            Type.deserialize(buffer);
            MapImage.deserialize(buffer);
        }
    };
    // SimulatorSetMapPacket Member List
    MapDataBlock MapData;

public:
    SimulatorSetMapPacket() {
        this->setID(SimulatorSetMap_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorSetMapPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MapData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MapData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorSetMapPacket();
    }
};

// SubscribeLoadPacket
class SubscribeLoadPacket : public PacketBase {
public:

    // Block Class List
    // SubscribeLoadPacket Member List

public:
    SubscribeLoadPacket() {
        this->setID(SubscribeLoad_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SubscribeLoadPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new SubscribeLoadPacket();
    }
};

// UnsubscribeLoadPacket
class UnsubscribeLoadPacket : public PacketBase {
public:

    // Block Class List
    // UnsubscribeLoadPacket Member List

public:
    UnsubscribeLoadPacket() {
        this->setID(UnsubscribeLoad_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~UnsubscribeLoadPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new UnsubscribeLoadPacket();
    }
};

// SimulatorReadyPacket
class SimulatorReadyPacket : public PacketBase {
public:

    // Block Class List
    class SimulatorBlockBlock : public PacketSerializable {
    public:
        // SimulatorBlockBlock Member List
        SerializableVariable1 SimName;
        SerializableU8 SimAccess;
        SerializableU32 RegionFlags;
        SerializableUUID RegionID;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
    public:
        SimulatorBlockBlock() {};
        virtual ~SimulatorBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            SimAccess.serialize(buffer);
            RegionFlags.serialize(buffer);
            RegionID.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            SimAccess.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            RegionID.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
        }
    };
    class TelehubBlockBlock : public PacketSerializable {
    public:
        // TelehubBlockBlock Member List
        SerializableBool HasTelehub;
        SerializableVector3 TelehubPos;
    public:
        TelehubBlockBlock() {};
        virtual ~TelehubBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            HasTelehub.serialize(buffer);
            TelehubPos.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            HasTelehub.deserialize(buffer);
            TelehubPos.deserialize(buffer);
        }
    };
    // SimulatorReadyPacket Member List
    SimulatorBlockBlock SimulatorBlock;
    TelehubBlockBlock TelehubBlock;

public:
    SimulatorReadyPacket() {
        this->setID(SimulatorReady_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~SimulatorReadyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimulatorBlock.serialize(buffer);
        TelehubBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimulatorBlock.deserialize(buffer);
        TelehubBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorReadyPacket();
    }
};

// TelehubInfoPacket
class TelehubInfoPacket : public PacketBase {
public:

    // Block Class List
    class TelehubBlockBlock : public PacketSerializable {
    public:
        // TelehubBlockBlock Member List
        SerializableUUID ObjectID;
        SerializableVariable1 ObjectName;
        SerializableVector3 TelehubPos;
        SerializableQuaternion TelehubRot;
    public:
        TelehubBlockBlock() {};
        virtual ~TelehubBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ObjectName.serialize(buffer);
            TelehubPos.serialize(buffer);
            TelehubRot.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ObjectName.deserialize(buffer);
            TelehubPos.deserialize(buffer);
            TelehubRot.deserialize(buffer);
        }
    };
    class SpawnPointBlockBlock : public PacketSerializable {
    public:
        // SpawnPointBlockBlock Member List
        SerializableVector3 SpawnPointPos;
    public:
        SpawnPointBlockBlock() {};
        virtual ~SpawnPointBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SpawnPointPos.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SpawnPointPos.deserialize(buffer);
        }
    };
    // TelehubInfoPacket Member List
    TelehubBlockBlock TelehubBlock;
    VariableSerializable<SpawnPointBlockBlock> SpawnPointBlock;

public:
    TelehubInfoPacket() {
        this->setID(TelehubInfo_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TelehubInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TelehubBlock.serialize(buffer);
        SpawnPointBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TelehubBlock.deserialize(buffer);
        SpawnPointBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TelehubInfoPacket();
    }
};

// SimulatorPresentAtLocationPacket
class SimulatorPresentAtLocationPacket : public PacketBase {
public:

    // Block Class List
    class SimulatorPublicHostBlockBlock : public PacketSerializable {
    public:
        // SimulatorPublicHostBlockBlock Member List
        SerializableIPPORT Port;
        SerializableIPADDR SimulatorIP;
        SerializableU32 GridX;
        SerializableU32 GridY;
    public:
        SimulatorPublicHostBlockBlock() {};
        virtual ~SimulatorPublicHostBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Port.serialize(buffer);
            SimulatorIP.serialize(buffer);
            GridX.serialize(buffer);
            GridY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Port.deserialize(buffer);
            SimulatorIP.deserialize(buffer);
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
        }
    };
    class NeighborBlockBlock : public PacketSerializable {
    public:
        // NeighborBlockBlock Member List
        SerializableIPADDR IP;
        SerializableIPPORT Port;
    public:
        NeighborBlockBlock() {};
        virtual ~NeighborBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IP.serialize(buffer);
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IP.deserialize(buffer);
            Port.deserialize(buffer);
        }
    };
    class SimulatorBlockBlock : public PacketSerializable {
    public:
        // SimulatorBlockBlock Member List
        SerializableVariable1 SimName;
        SerializableU8 SimAccess;
        SerializableU32 RegionFlags;
        SerializableUUID RegionID;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
    public:
        SimulatorBlockBlock() {};
        virtual ~SimulatorBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            SimAccess.serialize(buffer);
            RegionFlags.serialize(buffer);
            RegionID.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            SimAccess.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            RegionID.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
        }
    };
    class TelehubBlockBlock : public PacketSerializable {
    public:
        // TelehubBlockBlock Member List
        SerializableBool HasTelehub;
        SerializableVector3 TelehubPos;
    public:
        TelehubBlockBlock() {};
        virtual ~TelehubBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            HasTelehub.serialize(buffer);
            TelehubPos.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            HasTelehub.deserialize(buffer);
            TelehubPos.deserialize(buffer);
        }
    };
    // SimulatorPresentAtLocationPacket Member List
    SimulatorPublicHostBlockBlock SimulatorPublicHostBlock;
    MultipleSerializable<NeighborBlockBlock, 4> NeighborBlock;
    SimulatorBlockBlock SimulatorBlock;
    VariableSerializable<TelehubBlockBlock> TelehubBlock;

public:
    SimulatorPresentAtLocationPacket() {
        this->setID(SimulatorPresentAtLocation_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorPresentAtLocationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimulatorPublicHostBlock.serialize(buffer);
        NeighborBlock.serialize(buffer);
        SimulatorBlock.serialize(buffer);
        TelehubBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimulatorPublicHostBlock.deserialize(buffer);
        NeighborBlock.deserialize(buffer);
        SimulatorBlock.deserialize(buffer);
        TelehubBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorPresentAtLocationPacket();
    }
};

// SimulatorLoadPacket
class SimulatorLoadPacket : public PacketBase {
public:

    // Block Class List
    class SimulatorLoadBlock : public PacketSerializable {
    public:
        // SimulatorLoadBlock Member List
        SerializableF32 TimeDilation;
        SerializableS32 AgentCount;
        SerializableBool CanAcceptAgents;
    public:
        SimulatorLoadBlock() {};
        virtual ~SimulatorLoadBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TimeDilation.serialize(buffer);
            AgentCount.serialize(buffer);
            CanAcceptAgents.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TimeDilation.deserialize(buffer);
            AgentCount.deserialize(buffer);
            CanAcceptAgents.deserialize(buffer);
        }
    };
    class AgentListBlock : public PacketSerializable {
    public:
        // AgentListBlock Member List
        SerializableU32 CircuitCode;
        SerializableU8 X;
        SerializableU8 Y;
    public:
        AgentListBlock() {};
        virtual ~AgentListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CircuitCode.serialize(buffer);
            X.serialize(buffer);
            Y.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CircuitCode.deserialize(buffer);
            X.deserialize(buffer);
            Y.deserialize(buffer);
        }
    };
    // SimulatorLoadPacket Member List
    SimulatorLoadBlock SimulatorLoad;
    VariableSerializable<AgentListBlock> AgentList;

public:
    SimulatorLoadPacket() {
        this->setID(SimulatorLoad_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorLoadPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimulatorLoad.serialize(buffer);
        AgentList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimulatorLoad.deserialize(buffer);
        AgentList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorLoadPacket();
    }
};

// SimulatorShutdownRequestPacket
class SimulatorShutdownRequestPacket : public PacketBase {
public:

    // Block Class List
    // SimulatorShutdownRequestPacket Member List

public:
    SimulatorShutdownRequestPacket() {
        this->setID(SimulatorShutdownRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorShutdownRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new SimulatorShutdownRequestPacket();
    }
};

// RegionPresenceRequestByRegionIDPacket
class RegionPresenceRequestByRegionIDPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableUUID RegionID;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
        }
    };
    // RegionPresenceRequestByRegionIDPacket Member List
    VariableSerializable<RegionDataBlock> RegionData;

public:
    RegionPresenceRequestByRegionIDPacket() {
        this->setID(RegionPresenceRequestByRegionID_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RegionPresenceRequestByRegionIDPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionPresenceRequestByRegionIDPacket();
    }
};

// RegionPresenceRequestByHandlePacket
class RegionPresenceRequestByHandlePacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // RegionPresenceRequestByHandlePacket Member List
    VariableSerializable<RegionDataBlock> RegionData;

public:
    RegionPresenceRequestByHandlePacket() {
        this->setID(RegionPresenceRequestByHandle_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RegionPresenceRequestByHandlePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionPresenceRequestByHandlePacket();
    }
};

// RegionPresenceResponsePacket
class RegionPresenceResponsePacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableUUID RegionID;
        SerializableU64 RegionHandle;
        SerializableIPADDR InternalRegionIP;
        SerializableIPADDR ExternalRegionIP;
        SerializableIPPORT RegionPort;
        SerializableF64 ValidUntil;
        SerializableVariable1 Message;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            RegionHandle.serialize(buffer);
            InternalRegionIP.serialize(buffer);
            ExternalRegionIP.serialize(buffer);
            RegionPort.serialize(buffer);
            ValidUntil.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            InternalRegionIP.deserialize(buffer);
            ExternalRegionIP.deserialize(buffer);
            RegionPort.deserialize(buffer);
            ValidUntil.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // RegionPresenceResponsePacket Member List
    VariableSerializable<RegionDataBlock> RegionData;

public:
    RegionPresenceResponsePacket() {
        this->setID(RegionPresenceResponse_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionPresenceResponsePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionPresenceResponsePacket();
    }
};

// UpdateSimulatorPacket
class UpdateSimulatorPacket : public PacketBase {
public:

    // Block Class List
    class SimulatorInfoBlock : public PacketSerializable {
    public:
        // SimulatorInfoBlock Member List
        SerializableUUID RegionID;
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableU8 SimAccess;
    public:
        SimulatorInfoBlock() {};
        virtual ~SimulatorInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            SimAccess.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            SimAccess.deserialize(buffer);
        }
    };
    // UpdateSimulatorPacket Member List
    SimulatorInfoBlock SimulatorInfo;

public:
    UpdateSimulatorPacket() {
        this->setID(UpdateSimulator_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~UpdateSimulatorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimulatorInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimulatorInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateSimulatorPacket();
    }
};

// LogDwellTimePacket
class LogDwellTimePacket : public PacketBase {
public:

    // Block Class List
    class DwellInfoBlock : public PacketSerializable {
    public:
        // DwellInfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableF32 Duration;
        SerializableVariable1 SimName;
        SerializableU32 RegionX;
        SerializableU32 RegionY;
        SerializableU8 AvgAgentsInView;
        SerializableU8 AvgViewerFPS;
    public:
        DwellInfoBlock() {};
        virtual ~DwellInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Duration.serialize(buffer);
            SimName.serialize(buffer);
            RegionX.serialize(buffer);
            RegionY.serialize(buffer);
            AvgAgentsInView.serialize(buffer);
            AvgViewerFPS.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Duration.deserialize(buffer);
            SimName.deserialize(buffer);
            RegionX.deserialize(buffer);
            RegionY.deserialize(buffer);
            AvgAgentsInView.deserialize(buffer);
            AvgViewerFPS.deserialize(buffer);
        }
    };
    // LogDwellTimePacket Member List
    DwellInfoBlock DwellInfo;

public:
    LogDwellTimePacket() {
        this->setID(LogDwellTime_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LogDwellTimePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DwellInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DwellInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogDwellTimePacket();
    }
};

// FeatureDisabledPacket
class FeatureDisabledPacket : public PacketBase {
public:

    // Block Class List
    class FailureInfoBlock : public PacketSerializable {
    public:
        // FailureInfoBlock Member List
        SerializableVariable1 ErrorMessage;
        SerializableUUID AgentID;
        SerializableUUID TransactionID;
    public:
        FailureInfoBlock() {};
        virtual ~FailureInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ErrorMessage.serialize(buffer);
            AgentID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ErrorMessage.deserialize(buffer);
            AgentID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    // FeatureDisabledPacket Member List
    FailureInfoBlock FailureInfo;

public:
    FeatureDisabledPacket() {
        this->setID(FeatureDisabled_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~FeatureDisabledPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        FailureInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        FailureInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FeatureDisabledPacket();
    }
};

// LogFailedMoneyTransactionPacket
class LogFailedMoneyTransactionPacket : public PacketBase {
public:

    // Block Class List
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
        SerializableU32 TransactionTime;
        SerializableS32 TransactionType;
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableU8 Flags;
        SerializableS32 Amount;
        SerializableIPADDR SimulatorIP;
        SerializableU32 GridX;
        SerializableU32 GridY;
        SerializableU8 FailureType;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            TransactionTime.serialize(buffer);
            TransactionType.serialize(buffer);
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            Flags.serialize(buffer);
            Amount.serialize(buffer);
            SimulatorIP.serialize(buffer);
            GridX.serialize(buffer);
            GridY.serialize(buffer);
            FailureType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            TransactionTime.deserialize(buffer);
            TransactionType.deserialize(buffer);
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            Flags.deserialize(buffer);
            Amount.deserialize(buffer);
            SimulatorIP.deserialize(buffer);
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
            FailureType.deserialize(buffer);
        }
    };
    // LogFailedMoneyTransactionPacket Member List
    TransactionDataBlock TransactionData;

public:
    LogFailedMoneyTransactionPacket() {
        this->setID(LogFailedMoneyTransaction_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LogFailedMoneyTransactionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogFailedMoneyTransactionPacket();
    }
};

// UserReportInternalPacket
class UserReportInternalPacket : public PacketBase {
public:

    // Block Class List
    class ReportDataBlock : public PacketSerializable {
    public:
        // ReportDataBlock Member List
        SerializableU8 ReportType;
        SerializableU8 Category;
        SerializableUUID ReporterID;
        SerializableVector3 ViewerPosition;
        SerializableVector3 AgentPosition;
        SerializableUUID ScreenshotID;
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableUUID LastOwnerID;
        SerializableUUID CreatorID;
        SerializableUUID RegionID;
        SerializableUUID AbuserID;
        SerializableVariable1 AbuseRegionName;
        SerializableUUID AbuseRegionID;
        SerializableVariable1 Summary;
        SerializableVariable2 Details;
        SerializableVariable1 VersionString;
    public:
        ReportDataBlock() {};
        virtual ~ReportDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            Category.serialize(buffer);
            ReporterID.serialize(buffer);
            ViewerPosition.serialize(buffer);
            AgentPosition.serialize(buffer);
            ScreenshotID.serialize(buffer);
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            LastOwnerID.serialize(buffer);
            CreatorID.serialize(buffer);
            RegionID.serialize(buffer);
            AbuserID.serialize(buffer);
            AbuseRegionName.serialize(buffer);
            AbuseRegionID.serialize(buffer);
            Summary.serialize(buffer);
            Details.serialize(buffer);
            VersionString.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            Category.deserialize(buffer);
            ReporterID.deserialize(buffer);
            ViewerPosition.deserialize(buffer);
            AgentPosition.deserialize(buffer);
            ScreenshotID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            LastOwnerID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            RegionID.deserialize(buffer);
            AbuserID.deserialize(buffer);
            AbuseRegionName.deserialize(buffer);
            AbuseRegionID.deserialize(buffer);
            Summary.deserialize(buffer);
            Details.deserialize(buffer);
            VersionString.deserialize(buffer);
        }
    };
    // UserReportInternalPacket Member List
    ReportDataBlock ReportData;

public:
    UserReportInternalPacket() {
        this->setID(UserReportInternal_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UserReportInternalPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ReportData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ReportData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserReportInternalPacket();
    }
};

// SetSimStatusInDatabasePacket
class SetSimStatusInDatabasePacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID RegionID;
        SerializableVariable1 HostName;
        SerializableS32 X;
        SerializableS32 Y;
        SerializableS32 PID;
        SerializableS32 AgentCount;
        SerializableS32 TimeToLive;
        SerializableVariable1 Status;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            HostName.serialize(buffer);
            X.serialize(buffer);
            Y.serialize(buffer);
            PID.serialize(buffer);
            AgentCount.serialize(buffer);
            TimeToLive.serialize(buffer);
            Status.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            HostName.deserialize(buffer);
            X.deserialize(buffer);
            Y.deserialize(buffer);
            PID.deserialize(buffer);
            AgentCount.deserialize(buffer);
            TimeToLive.deserialize(buffer);
            Status.deserialize(buffer);
        }
    };
    // SetSimStatusInDatabasePacket Member List
    DataBlock Data;

public:
    SetSimStatusInDatabasePacket() {
        this->setID(SetSimStatusInDatabase_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SetSimStatusInDatabasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetSimStatusInDatabasePacket();
    }
};

// SetSimPresenceInDatabasePacket
class SetSimPresenceInDatabasePacket : public PacketBase {
public:

    // Block Class List
    class SimDataBlock : public PacketSerializable {
    public:
        // SimDataBlock Member List
        SerializableUUID RegionID;
        SerializableVariable1 HostName;
        SerializableU32 GridX;
        SerializableU32 GridY;
        SerializableS32 PID;
        SerializableS32 AgentCount;
        SerializableS32 TimeToLive;
        SerializableVariable1 Status;
    public:
        SimDataBlock() {};
        virtual ~SimDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            HostName.serialize(buffer);
            GridX.serialize(buffer);
            GridY.serialize(buffer);
            PID.serialize(buffer);
            AgentCount.serialize(buffer);
            TimeToLive.serialize(buffer);
            Status.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            HostName.deserialize(buffer);
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
            PID.deserialize(buffer);
            AgentCount.deserialize(buffer);
            TimeToLive.deserialize(buffer);
            Status.deserialize(buffer);
        }
    };
    // SetSimPresenceInDatabasePacket Member List
    SimDataBlock SimData;

public:
    SetSimPresenceInDatabasePacket() {
        this->setID(SetSimPresenceInDatabase_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SetSimPresenceInDatabasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetSimPresenceInDatabasePacket();
    }
};

// EconomyDataRequestPacket
class EconomyDataRequestPacket : public PacketBase {
public:

    // Block Class List
    // EconomyDataRequestPacket Member List

public:
    EconomyDataRequestPacket() {
        this->setID(EconomyDataRequest_ID);
    };
    virtual ~EconomyDataRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new EconomyDataRequestPacket();
    }
};

// EconomyDataPacket
class EconomyDataPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableS32 ObjectCapacity;
        SerializableS32 ObjectCount;
        SerializableS32 PriceEnergyUnit;
        SerializableS32 PriceObjectClaim;
        SerializableS32 PricePublicObjectDecay;
        SerializableS32 PricePublicObjectDelete;
        SerializableS32 PriceParcelClaim;
        SerializableF32 PriceParcelClaimFactor;
        SerializableS32 PriceUpload;
        SerializableS32 PriceRentLight;
        SerializableS32 TeleportMinPrice;
        SerializableF32 TeleportPriceExponent;
        SerializableF32 EnergyEfficiency;
        SerializableF32 PriceObjectRent;
        SerializableF32 PriceObjectScaleFactor;
        SerializableS32 PriceParcelRent;
        SerializableS32 PriceGroupCreate;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectCapacity.serialize(buffer);
            ObjectCount.serialize(buffer);
            PriceEnergyUnit.serialize(buffer);
            PriceObjectClaim.serialize(buffer);
            PricePublicObjectDecay.serialize(buffer);
            PricePublicObjectDelete.serialize(buffer);
            PriceParcelClaim.serialize(buffer);
            PriceParcelClaimFactor.serialize(buffer);
            PriceUpload.serialize(buffer);
            PriceRentLight.serialize(buffer);
            TeleportMinPrice.serialize(buffer);
            TeleportPriceExponent.serialize(buffer);
            EnergyEfficiency.serialize(buffer);
            PriceObjectRent.serialize(buffer);
            PriceObjectScaleFactor.serialize(buffer);
            PriceParcelRent.serialize(buffer);
            PriceGroupCreate.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectCapacity.deserialize(buffer);
            ObjectCount.deserialize(buffer);
            PriceEnergyUnit.deserialize(buffer);
            PriceObjectClaim.deserialize(buffer);
            PricePublicObjectDecay.deserialize(buffer);
            PricePublicObjectDelete.deserialize(buffer);
            PriceParcelClaim.deserialize(buffer);
            PriceParcelClaimFactor.deserialize(buffer);
            PriceUpload.deserialize(buffer);
            PriceRentLight.deserialize(buffer);
            TeleportMinPrice.deserialize(buffer);
            TeleportPriceExponent.deserialize(buffer);
            EnergyEfficiency.deserialize(buffer);
            PriceObjectRent.deserialize(buffer);
            PriceObjectScaleFactor.deserialize(buffer);
            PriceParcelRent.deserialize(buffer);
            PriceGroupCreate.deserialize(buffer);
        }
    };
    // EconomyDataPacket Member List
    InfoBlock Info;

public:
    EconomyDataPacket() {
        this->setID(EconomyData_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EconomyDataPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EconomyDataPacket();
    }
};

// AvatarPickerRequestPacket
class AvatarPickerRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVariable1 Name;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
        }
    };
    // AvatarPickerRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarPickerRequestPacket() {
        this->setID(AvatarPickerRequest_ID);
    };
    virtual ~AvatarPickerRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPickerRequestPacket();
    }
};

// AvatarPickerRequestBackendPacket
class AvatarPickerRequestBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID QueryID;
        SerializableU8 GodLevel;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            QueryID.serialize(buffer);
            GodLevel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            QueryID.deserialize(buffer);
            GodLevel.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVariable1 Name;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
        }
    };
    // AvatarPickerRequestBackendPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarPickerRequestBackendPacket() {
        this->setID(AvatarPickerRequestBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarPickerRequestBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPickerRequestBackendPacket();
    }
};

// AvatarPickerReplyPacket
class AvatarPickerReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID AvatarID;
        SerializableVariable1 FirstName;
        SerializableVariable1 LastName;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AvatarID.serialize(buffer);
            FirstName.serialize(buffer);
            LastName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AvatarID.deserialize(buffer);
            FirstName.deserialize(buffer);
            LastName.deserialize(buffer);
        }
    };
    // AvatarPickerReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    AvatarPickerReplyPacket() {
        this->setID(AvatarPickerReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarPickerReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPickerReplyPacket();
    }
};

// PlacesQueryPacket
class PlacesQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS8 Category;
        SerializableVariable1 SimName;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            SimName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            SimName.deserialize(buffer);
        }
    };
    // PlacesQueryPacket Member List
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    QueryDataBlock QueryData;

public:
    PlacesQueryPacket() {
        this->setID(PlacesQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~PlacesQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PlacesQueryPacket();
    }
};

// PlacesReplyPacket
class PlacesReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID QueryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID OwnerID;
        SerializableVariable1 Name;
        SerializableVariable1 Desc;
        SerializableS32 ActualArea;
        SerializableS32 BillableArea;
        SerializableU8 Flags;
        SerializableF32 GlobalX;
        SerializableF32 GlobalY;
        SerializableF32 GlobalZ;
        SerializableVariable1 SimName;
        SerializableUUID SnapshotID;
        SerializableF32 Dwell;
        SerializableS32 Price;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            ActualArea.serialize(buffer);
            BillableArea.serialize(buffer);
            Flags.serialize(buffer);
            GlobalX.serialize(buffer);
            GlobalY.serialize(buffer);
            GlobalZ.serialize(buffer);
            SimName.serialize(buffer);
            SnapshotID.serialize(buffer);
            Dwell.serialize(buffer);
            Price.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            ActualArea.deserialize(buffer);
            BillableArea.deserialize(buffer);
            Flags.deserialize(buffer);
            GlobalX.deserialize(buffer);
            GlobalY.deserialize(buffer);
            GlobalZ.deserialize(buffer);
            SimName.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            Dwell.deserialize(buffer);
            Price.deserialize(buffer);
        }
    };
    // PlacesReplyPacket Member List
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    VariableSerializable<QueryDataBlock> QueryData;

public:
    PlacesReplyPacket() {
        this->setID(PlacesReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~PlacesReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PlacesReplyPacket();
    }
};

// DirFindQueryPacket
class DirFindQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirFindQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirFindQueryPacket() {
        this->setID(DirFindQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirFindQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirFindQueryPacket();
    }
};

// DirFindQueryBackendPacket
class DirFindQueryBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS32 QueryStart;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            QueryStart.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            QueryStart.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    // DirFindQueryBackendPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirFindQueryBackendPacket() {
        this->setID(DirFindQueryBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirFindQueryBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirFindQueryBackendPacket();
    }
};

// DirPlacesQueryPacket
class DirPlacesQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS8 Category;
        SerializableVariable1 SimName;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            SimName.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            SimName.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirPlacesQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPlacesQueryPacket() {
        this->setID(DirPlacesQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPlacesQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPlacesQueryPacket();
    }
};

// DirPlacesQueryBackendPacket
class DirPlacesQueryBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS8 Category;
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableBool Godlike;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirPlacesQueryBackendPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPlacesQueryBackendPacket() {
        this->setID(DirPlacesQueryBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPlacesQueryBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPlacesQueryBackendPacket();
    }
};

// DirPlacesReplyPacket
class DirPlacesReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableBool ForSale;
        SerializableBool Auction;
        SerializableF32 Dwell;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            ForSale.serialize(buffer);
            Auction.serialize(buffer);
            Dwell.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            ForSale.deserialize(buffer);
            Auction.deserialize(buffer);
            Dwell.deserialize(buffer);
        }
    };
    // DirPlacesReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<QueryDataBlock> QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirPlacesReplyPacket() {
        this->setID(DirPlacesReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPlacesReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPlacesReplyPacket();
    }
};

// DirPeopleReplyPacket
class DirPeopleReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID AgentID;
        SerializableVariable1 FirstName;
        SerializableVariable1 LastName;
        SerializableVariable1 Group;
        SerializableBool Online;
        SerializableS32 Reputation;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            FirstName.serialize(buffer);
            LastName.serialize(buffer);
            Group.serialize(buffer);
            Online.serialize(buffer);
            Reputation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            FirstName.deserialize(buffer);
            LastName.deserialize(buffer);
            Group.deserialize(buffer);
            Online.deserialize(buffer);
            Reputation.deserialize(buffer);
        }
    };
    // DirPeopleReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirPeopleReplyPacket() {
        this->setID(DirPeopleReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPeopleReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPeopleReplyPacket();
    }
};

// DirEventsReplyPacket
class DirEventsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID OwnerID;
        SerializableVariable1 Name;
        SerializableU32 EventID;
        SerializableVariable1 Date;
        SerializableU32 UnixTime;
        SerializableU32 EventFlags;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            Name.serialize(buffer);
            EventID.serialize(buffer);
            Date.serialize(buffer);
            UnixTime.serialize(buffer);
            EventFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            EventID.deserialize(buffer);
            Date.deserialize(buffer);
            UnixTime.deserialize(buffer);
            EventFlags.deserialize(buffer);
        }
    };
    // DirEventsReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirEventsReplyPacket() {
        this->setID(DirEventsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirEventsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirEventsReplyPacket();
    }
};

// DirGroupsReplyPacket
class DirGroupsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID GroupID;
        SerializableVariable1 GroupName;
        SerializableS32 Members;
        SerializableF32 SearchOrder;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            GroupName.serialize(buffer);
            Members.serialize(buffer);
            SearchOrder.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            GroupName.deserialize(buffer);
            Members.deserialize(buffer);
            SearchOrder.deserialize(buffer);
        }
    };
    // DirGroupsReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirGroupsReplyPacket() {
        this->setID(DirGroupsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirGroupsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirGroupsReplyPacket();
    }
};

// DirClassifiedQueryPacket
class DirClassifiedQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableU32 Category;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirClassifiedQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirClassifiedQueryPacket() {
        this->setID(DirClassifiedQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirClassifiedQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirClassifiedQueryPacket();
    }
};

// DirClassifiedQueryBackendPacket
class DirClassifiedQueryBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableU32 Category;
        SerializableU32 EstateID;
        SerializableBool Godlike;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            Category.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            Category.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirClassifiedQueryBackendPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirClassifiedQueryBackendPacket() {
        this->setID(DirClassifiedQueryBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirClassifiedQueryBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirClassifiedQueryBackendPacket();
    }
};

// DirClassifiedReplyPacket
class DirClassifiedReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID ClassifiedID;
        SerializableVariable1 Name;
        SerializableU8 ClassifiedFlags;
        SerializableU32 CreationDate;
        SerializableU32 ExpirationDate;
        SerializableS32 PriceForListing;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            Name.serialize(buffer);
            ClassifiedFlags.serialize(buffer);
            CreationDate.serialize(buffer);
            ExpirationDate.serialize(buffer);
            PriceForListing.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            Name.deserialize(buffer);
            ClassifiedFlags.deserialize(buffer);
            CreationDate.deserialize(buffer);
            ExpirationDate.deserialize(buffer);
            PriceForListing.deserialize(buffer);
        }
    };
    // DirClassifiedReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirClassifiedReplyPacket() {
        this->setID(DirClassifiedReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirClassifiedReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirClassifiedReplyPacket();
    }
};

// AvatarClassifiedReplyPacket
class AvatarClassifiedReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID TargetID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TargetID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TargetID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableVariable1 Name;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // AvatarClassifiedReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    AvatarClassifiedReplyPacket() {
        this->setID(AvatarClassifiedReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarClassifiedReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarClassifiedReplyPacket();
    }
};

// ClassifiedInfoRequestPacket
class ClassifiedInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
        }
    };
    // ClassifiedInfoRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedInfoRequestPacket() {
        this->setID(ClassifiedInfoRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ClassifiedInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedInfoRequestPacket();
    }
};

// ClassifiedInfoReplyPacket
class ClassifiedInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableUUID CreatorID;
        SerializableU32 CreationDate;
        SerializableU32 ExpirationDate;
        SerializableU32 Category;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID ParcelID;
        SerializableU32 ParentEstate;
        SerializableUUID SnapshotID;
        SerializableVariable1 SimName;
        SerializableVector3d PosGlobal;
        SerializableVariable1 ParcelName;
        SerializableU8 ClassifiedFlags;
        SerializableS32 PriceForListing;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            CreatorID.serialize(buffer);
            CreationDate.serialize(buffer);
            ExpirationDate.serialize(buffer);
            Category.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            ParcelID.serialize(buffer);
            ParentEstate.serialize(buffer);
            SnapshotID.serialize(buffer);
            SimName.serialize(buffer);
            PosGlobal.serialize(buffer);
            ParcelName.serialize(buffer);
            ClassifiedFlags.serialize(buffer);
            PriceForListing.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            CreationDate.deserialize(buffer);
            ExpirationDate.deserialize(buffer);
            Category.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            ParcelID.deserialize(buffer);
            ParentEstate.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            SimName.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            ParcelName.deserialize(buffer);
            ClassifiedFlags.deserialize(buffer);
            PriceForListing.deserialize(buffer);
        }
    };
    // ClassifiedInfoReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedInfoReplyPacket() {
        this->setID(ClassifiedInfoReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ClassifiedInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedInfoReplyPacket();
    }
};

// ClassifiedInfoUpdatePacket
class ClassifiedInfoUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableU32 Category;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID ParcelID;
        SerializableU32 ParentEstate;
        SerializableUUID SnapshotID;
        SerializableVector3d PosGlobal;
        SerializableU8 ClassifiedFlags;
        SerializableS32 PriceForListing;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            Category.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            ParcelID.serialize(buffer);
            ParentEstate.serialize(buffer);
            SnapshotID.serialize(buffer);
            PosGlobal.serialize(buffer);
            ClassifiedFlags.serialize(buffer);
            PriceForListing.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            Category.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            ParcelID.deserialize(buffer);
            ParentEstate.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            ClassifiedFlags.deserialize(buffer);
            PriceForListing.deserialize(buffer);
        }
    };
    // ClassifiedInfoUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedInfoUpdatePacket() {
        this->setID(ClassifiedInfoUpdate_ID);
    };
    virtual ~ClassifiedInfoUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedInfoUpdatePacket();
    }
};

// ClassifiedDeletePacket
class ClassifiedDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
        }
    };
    // ClassifiedDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedDeletePacket() {
        this->setID(ClassifiedDelete_ID);
    };
    virtual ~ClassifiedDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedDeletePacket();
    }
};

// ClassifiedGodDeletePacket
class ClassifiedGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ClassifiedID;
        SerializableUUID QueryID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ClassifiedID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ClassifiedID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    // ClassifiedGodDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ClassifiedGodDeletePacket() {
        this->setID(ClassifiedGodDelete_ID);
    };
    virtual ~ClassifiedGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClassifiedGodDeletePacket();
    }
};

// DirLandQueryPacket
class DirLandQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
        SerializableU32 SearchType;
        SerializableS32 Price;
        SerializableS32 Area;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
            SearchType.serialize(buffer);
            Price.serialize(buffer);
            Area.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            SearchType.deserialize(buffer);
            Price.deserialize(buffer);
            Area.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // DirLandQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirLandQueryPacket() {
        this->setID(DirLandQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirLandQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirLandQueryPacket();
    }
};

// DirLandQueryBackendPacket
class DirLandQueryBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
        SerializableU32 SearchType;
        SerializableS32 Price;
        SerializableS32 Area;
        SerializableS32 QueryStart;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
            SearchType.serialize(buffer);
            Price.serialize(buffer);
            Area.serialize(buffer);
            QueryStart.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            SearchType.deserialize(buffer);
            Price.deserialize(buffer);
            Area.deserialize(buffer);
            QueryStart.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    // DirLandQueryBackendPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirLandQueryBackendPacket() {
        this->setID(DirLandQueryBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirLandQueryBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirLandQueryBackendPacket();
    }
};

// DirLandReplyPacket
class DirLandReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableBool Auction;
        SerializableBool ForSale;
        SerializableS32 SalePrice;
        SerializableS32 ActualArea;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            Auction.serialize(buffer);
            ForSale.serialize(buffer);
            SalePrice.serialize(buffer);
            ActualArea.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            Auction.deserialize(buffer);
            ForSale.deserialize(buffer);
            SalePrice.deserialize(buffer);
            ActualArea.deserialize(buffer);
        }
    };
    // DirLandReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirLandReplyPacket() {
        this->setID(DirLandReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirLandReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirLandReplyPacket();
    }
};

// DirPopularQueryPacket
class DirPopularQueryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
        }
    };
    // DirPopularQueryPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPopularQueryPacket() {
        this->setID(DirPopularQuery_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPopularQueryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPopularQueryPacket();
    }
};

// DirPopularQueryBackendPacket
class DirPopularQueryBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableU32 QueryFlags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryFlags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    // DirPopularQueryBackendPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;

public:
    DirPopularQueryBackendPacket() {
        this->setID(DirPopularQueryBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPopularQueryBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPopularQueryBackendPacket();
    }
};

// DirPopularReplyPacket
class DirPopularReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class QueryRepliesBlock : public PacketSerializable {
    public:
        // QueryRepliesBlock Member List
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableF32 Dwell;
    public:
        QueryRepliesBlock() {};
        virtual ~QueryRepliesBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            Dwell.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            Dwell.deserialize(buffer);
        }
    };
    // DirPopularReplyPacket Member List
    AgentDataBlock AgentData;
    QueryDataBlock QueryData;
    VariableSerializable<QueryRepliesBlock> QueryReplies;

public:
    DirPopularReplyPacket() {
        this->setID(DirPopularReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DirPopularReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        QueryData.serialize(buffer);
        QueryReplies.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        QueryData.deserialize(buffer);
        QueryReplies.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DirPopularReplyPacket();
    }
};

// ParcelInfoRequestPacket
class ParcelInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ParcelID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
        }
    };
    // ParcelInfoRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelInfoRequestPacket() {
        this->setID(ParcelInfoRequest_ID);
    };
    virtual ~ParcelInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelInfoRequestPacket();
    }
};

// ParcelInfoReplyPacket
class ParcelInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ParcelID;
        SerializableUUID OwnerID;
        SerializableVariable1 Name;
        SerializableVariable1 Desc;
        SerializableS32 ActualArea;
        SerializableS32 BillableArea;
        SerializableU8 Flags;
        SerializableF32 GlobalX;
        SerializableF32 GlobalY;
        SerializableF32 GlobalZ;
        SerializableVariable1 SimName;
        SerializableUUID SnapshotID;
        SerializableF32 Dwell;
        SerializableS32 SalePrice;
        SerializableS32 AuctionID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            OwnerID.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            ActualArea.serialize(buffer);
            BillableArea.serialize(buffer);
            Flags.serialize(buffer);
            GlobalX.serialize(buffer);
            GlobalY.serialize(buffer);
            GlobalZ.serialize(buffer);
            SimName.serialize(buffer);
            SnapshotID.serialize(buffer);
            Dwell.serialize(buffer);
            SalePrice.serialize(buffer);
            AuctionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            ActualArea.deserialize(buffer);
            BillableArea.deserialize(buffer);
            Flags.deserialize(buffer);
            GlobalX.deserialize(buffer);
            GlobalY.deserialize(buffer);
            GlobalZ.deserialize(buffer);
            SimName.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            Dwell.deserialize(buffer);
            SalePrice.deserialize(buffer);
            AuctionID.deserialize(buffer);
        }
    };
    // ParcelInfoReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelInfoReplyPacket() {
        this->setID(ParcelInfoReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelInfoReplyPacket();
    }
};

// ParcelObjectOwnersRequestPacket
class ParcelObjectOwnersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelObjectOwnersRequestPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelObjectOwnersRequestPacket() {
        this->setID(ParcelObjectOwnersRequest_ID);
    };
    virtual ~ParcelObjectOwnersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelObjectOwnersRequestPacket();
    }
};

// ParcelObjectOwnersReplyPacket
class ParcelObjectOwnersReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID OwnerID;
        SerializableBool IsGroupOwned;
        SerializableS32 Count;
        SerializableBool OnlineStatus;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            Count.serialize(buffer);
            OnlineStatus.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            Count.deserialize(buffer);
            OnlineStatus.deserialize(buffer);
        }
    };
    // ParcelObjectOwnersReplyPacket Member List
    VariableSerializable<DataBlock> Data;

public:
    ParcelObjectOwnersReplyPacket() {
        this->setID(ParcelObjectOwnersReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelObjectOwnersReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelObjectOwnersReplyPacket();
    }
};

// GroupNoticesListRequestPacket
class GroupNoticesListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // GroupNoticesListRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    GroupNoticesListRequestPacket() {
        this->setID(GroupNoticesListRequest_ID);
    };
    virtual ~GroupNoticesListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticesListRequestPacket();
    }
};

// GroupNoticesListReplyPacket
class GroupNoticesListReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID NoticeID;
        SerializableU32 Timestamp;
        SerializableVariable2 FromName;
        SerializableVariable2 Subject;
        SerializableBool HasAttachment;
        SerializableU8 AssetType;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NoticeID.serialize(buffer);
            Timestamp.serialize(buffer);
            FromName.serialize(buffer);
            Subject.serialize(buffer);
            HasAttachment.serialize(buffer);
            AssetType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NoticeID.deserialize(buffer);
            Timestamp.deserialize(buffer);
            FromName.deserialize(buffer);
            Subject.deserialize(buffer);
            HasAttachment.deserialize(buffer);
            AssetType.deserialize(buffer);
        }
    };
    // GroupNoticesListReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    GroupNoticesListReplyPacket() {
        this->setID(GroupNoticesListReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~GroupNoticesListReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticesListReplyPacket();
    }
};

// GroupNoticeRequestPacket
class GroupNoticeRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupNoticeID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupNoticeID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupNoticeID.deserialize(buffer);
        }
    };
    // GroupNoticeRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    GroupNoticeRequestPacket() {
        this->setID(GroupNoticeRequest_ID);
    };
    virtual ~GroupNoticeRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticeRequestPacket();
    }
};

// GroupNoticeAddPacket
class GroupNoticeAddPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class MessageBlockBlock : public PacketSerializable {
    public:
        // MessageBlockBlock Member List
        SerializableUUID ToGroupID;
        SerializableUUID ID;
        SerializableU8 Dialog;
        SerializableVariable1 FromAgentName;
        SerializableVariable2 Message;
        SerializableVariable2 BinaryBucket;
    public:
        MessageBlockBlock() {};
        virtual ~MessageBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ToGroupID.serialize(buffer);
            ID.serialize(buffer);
            Dialog.serialize(buffer);
            FromAgentName.serialize(buffer);
            Message.serialize(buffer);
            BinaryBucket.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ToGroupID.deserialize(buffer);
            ID.deserialize(buffer);
            Dialog.deserialize(buffer);
            FromAgentName.deserialize(buffer);
            Message.deserialize(buffer);
            BinaryBucket.deserialize(buffer);
        }
    };
    // GroupNoticeAddPacket Member List
    AgentDataBlock AgentData;
    MessageBlockBlock MessageBlock;

public:
    GroupNoticeAddPacket() {
        this->setID(GroupNoticeAdd_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~GroupNoticeAddPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MessageBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MessageBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupNoticeAddPacket();
    }
};

// TeleportRequestPacket
class TeleportRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID RegionID;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // TeleportRequestPacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;

public:
    TeleportRequestPacket() {
        this->setID(TeleportRequest_ID);
    };
    virtual ~TeleportRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportRequestPacket();
    }
};

// TeleportLocationRequestPacket
class TeleportLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU64 RegionHandle;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // TeleportLocationRequestPacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;

public:
    TeleportLocationRequestPacket() {
        this->setID(TeleportLocationRequest_ID);
    };
    virtual ~TeleportLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLocationRequestPacket();
    }
};

// TeleportLocalPacket
class TeleportLocalPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableU32 LocationID;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
        SerializableU32 TeleportFlags;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            LocationID.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
            TeleportFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            LocationID.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
            TeleportFlags.deserialize(buffer);
        }
    };
    // TeleportLocalPacket Member List
    InfoBlock Info;

public:
    TeleportLocalPacket() {
        this->setID(TeleportLocal_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportLocalPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLocalPacket();
    }
};

// TeleportLandmarkRequestPacket
class TeleportLandmarkRequestPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID LandmarkID;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            LandmarkID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            LandmarkID.deserialize(buffer);
        }
    };
    // TeleportLandmarkRequestPacket Member List
    InfoBlock Info;

public:
    TeleportLandmarkRequestPacket() {
        this->setID(TeleportLandmarkRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TeleportLandmarkRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLandmarkRequestPacket();
    }
};

// TeleportProgressPacket
class TeleportProgressPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU32 TeleportFlags;
        SerializableVariable1 Message;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TeleportFlags.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TeleportFlags.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // TeleportProgressPacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;

public:
    TeleportProgressPacket() {
        this->setID(TeleportProgress_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportProgressPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportProgressPacket();
    }
};

// DataHomeLocationRequestPacket
class DataHomeLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableU32 KickedFromEstateID;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            KickedFromEstateID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            KickedFromEstateID.deserialize(buffer);
        }
    };
    // DataHomeLocationRequestPacket Member List
    InfoBlock Info;

public:
    DataHomeLocationRequestPacket() {
        this->setID(DataHomeLocationRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DataHomeLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DataHomeLocationRequestPacket();
    }
};

// DataHomeLocationReplyPacket
class DataHomeLocationReplyPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableU64 RegionHandle;
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            RegionHandle.serialize(buffer);
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // DataHomeLocationReplyPacket Member List
    InfoBlock Info;

public:
    DataHomeLocationReplyPacket() {
        this->setID(DataHomeLocationReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~DataHomeLocationReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DataHomeLocationReplyPacket();
    }
};

// TeleportFinishPacket
class TeleportFinishPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableU32 LocationID;
        SerializableIPADDR SimIP;
        SerializableIPPORT SimPort;
        SerializableU64 RegionHandle;
        SerializableVariable2 SeedCapability;
        SerializableU8 SimAccess;
        SerializableU32 TeleportFlags;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            LocationID.serialize(buffer);
            SimIP.serialize(buffer);
            SimPort.serialize(buffer);
            RegionHandle.serialize(buffer);
            SeedCapability.serialize(buffer);
            SimAccess.serialize(buffer);
            TeleportFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            LocationID.deserialize(buffer);
            SimIP.deserialize(buffer);
            SimPort.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            SeedCapability.deserialize(buffer);
            SimAccess.deserialize(buffer);
            TeleportFlags.deserialize(buffer);
        }
    };
    // TeleportFinishPacket Member List
    InfoBlock Info;

public:
    TeleportFinishPacket() {
        this->setID(TeleportFinish_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportFinishPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportFinishPacket();
    }
};

// StartLurePacket
class StartLurePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU8 LureType;
        SerializableVariable1 Message;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LureType.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LureType.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    class TargetDataBlock : public PacketSerializable {
    public:
        // TargetDataBlock Member List
        SerializableUUID TargetID;
    public:
        TargetDataBlock() {};
        virtual ~TargetDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
        }
    };
    // StartLurePacket Member List
    AgentDataBlock AgentData;
    InfoBlock Info;
    VariableSerializable<TargetDataBlock> TargetData;

public:
    StartLurePacket() {
        this->setID(StartLure_ID);
    };
    virtual ~StartLurePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Info.serialize(buffer);
        TargetData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Info.deserialize(buffer);
        TargetData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartLurePacket();
    }
};

// TeleportLureRequestPacket
class TeleportLureRequestPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID LureID;
        SerializableU32 TeleportFlags;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            LureID.serialize(buffer);
            TeleportFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            LureID.deserialize(buffer);
            TeleportFlags.deserialize(buffer);
        }
    };
    // TeleportLureRequestPacket Member List
    InfoBlock Info;

public:
    TeleportLureRequestPacket() {
        this->setID(TeleportLureRequest_ID);
    };
    virtual ~TeleportLureRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLureRequestPacket();
    }
};

// TeleportCancelPacket
class TeleportCancelPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // TeleportCancelPacket Member List
    InfoBlock Info;

public:
    TeleportCancelPacket() {
        this->setID(TeleportCancel_ID);
    };
    virtual ~TeleportCancelPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportCancelPacket();
    }
};

// TeleportStartPacket
class TeleportStartPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableU32 TeleportFlags;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TeleportFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TeleportFlags.deserialize(buffer);
        }
    };
    // TeleportStartPacket Member List
    InfoBlock Info;

public:
    TeleportStartPacket() {
        this->setID(TeleportStart_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportStartPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportStartPacket();
    }
};

// TeleportFailedPacket
class TeleportFailedPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableUUID AgentID;
        SerializableVariable1 Reason;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Reason.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Reason.deserialize(buffer);
        }
    };
    // TeleportFailedPacket Member List
    InfoBlock Info;

public:
    TeleportFailedPacket() {
        this->setID(TeleportFailed_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportFailedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportFailedPacket();
    }
};

// UndoPacket
class UndoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // UndoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    UndoPacket() {
        this->setID(Undo_ID);
    };
    virtual ~UndoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UndoPacket();
    }
};

// RedoPacket
class RedoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // RedoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    RedoPacket() {
        this->setID(Redo_ID);
    };
    virtual ~RedoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RedoPacket();
    }
};

// UndoLandPacket
class UndoLandPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // UndoLandPacket Member List
    AgentDataBlock AgentData;

public:
    UndoLandPacket() {
        this->setID(UndoLand_ID);
    };
    virtual ~UndoLandPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UndoLandPacket();
    }
};

// AgentPausePacket
class AgentPausePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    // AgentPausePacket Member List
    AgentDataBlock AgentData;

public:
    AgentPausePacket() {
        this->setID(AgentPause_ID);
    };
    virtual ~AgentPausePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentPausePacket();
    }
};

// AgentResumePacket
class AgentResumePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    // AgentResumePacket Member List
    AgentDataBlock AgentData;

public:
    AgentResumePacket() {
        this->setID(AgentResume_ID);
    };
    virtual ~AgentResumePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentResumePacket();
    }
};

// AgentUpdatePacket
class AgentUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableQuaternion BodyRotation;
        SerializableQuaternion HeadRotation;
        SerializableU8 State;
        SerializableVector3 CameraCenter;
        SerializableVector3 CameraAtAxis;
        SerializableVector3 CameraLeftAxis;
        SerializableVector3 CameraUpAxis;
        SerializableF32 Far;
        SerializableU32 ControlFlags;
        SerializableU8 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            BodyRotation.serialize(buffer);
            HeadRotation.serialize(buffer);
            State.serialize(buffer);
            CameraCenter.serialize(buffer);
            CameraAtAxis.serialize(buffer);
            CameraLeftAxis.serialize(buffer);
            CameraUpAxis.serialize(buffer);
            Far.serialize(buffer);
            ControlFlags.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            BodyRotation.deserialize(buffer);
            HeadRotation.deserialize(buffer);
            State.deserialize(buffer);
            CameraCenter.deserialize(buffer);
            CameraAtAxis.deserialize(buffer);
            CameraLeftAxis.deserialize(buffer);
            CameraUpAxis.deserialize(buffer);
            Far.deserialize(buffer);
            ControlFlags.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // AgentUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    AgentUpdatePacket() {
        this->setID(AgentUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentUpdatePacket();
    }
};

// ChatFromViewerPacket
class ChatFromViewerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ChatDataBlock : public PacketSerializable {
    public:
        // ChatDataBlock Member List
        SerializableVariable2 Message;
        SerializableU8 Type;
        SerializableS32 Channel;
    public:
        ChatDataBlock() {};
        virtual ~ChatDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Message.serialize(buffer);
            Type.serialize(buffer);
            Channel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Message.deserialize(buffer);
            Type.deserialize(buffer);
            Channel.deserialize(buffer);
        }
    };
    // ChatFromViewerPacket Member List
    AgentDataBlock AgentData;
    ChatDataBlock ChatData;

public:
    ChatFromViewerPacket() {
        this->setID(ChatFromViewer_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ChatFromViewerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ChatData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ChatData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChatFromViewerPacket();
    }
};

// AgentThrottlePacket
class AgentThrottlePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class ThrottleBlock : public PacketSerializable {
    public:
        // ThrottleBlock Member List
        SerializableU32 GenCounter;
        SerializableVariable1 Throttles;
    public:
        ThrottleBlock() {};
        virtual ~ThrottleBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            Throttles.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            Throttles.deserialize(buffer);
        }
    };
    // AgentThrottlePacket Member List
    AgentDataBlock AgentData;
    ThrottleBlock Throttle;

public:
    AgentThrottlePacket() {
        this->setID(AgentThrottle_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentThrottlePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Throttle.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Throttle.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentThrottlePacket();
    }
};

// AgentFOVPacket
class AgentFOVPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class FOVBlockBlock : public PacketSerializable {
    public:
        // FOVBlockBlock Member List
        SerializableU32 GenCounter;
        SerializableF32 VerticalAngle;
    public:
        FOVBlockBlock() {};
        virtual ~FOVBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            VerticalAngle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            VerticalAngle.deserialize(buffer);
        }
    };
    // AgentFOVPacket Member List
    AgentDataBlock AgentData;
    FOVBlockBlock FOVBlock;

public:
    AgentFOVPacket() {
        this->setID(AgentFOV_ID);
    };
    virtual ~AgentFOVPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FOVBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FOVBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentFOVPacket();
    }
};

// AgentHeightWidthPacket
class AgentHeightWidthPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    class HeightWidthBlockBlock : public PacketSerializable {
    public:
        // HeightWidthBlockBlock Member List
        SerializableU32 GenCounter;
        SerializableU16 Height;
        SerializableU16 Width;
    public:
        HeightWidthBlockBlock() {};
        virtual ~HeightWidthBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GenCounter.serialize(buffer);
            Height.serialize(buffer);
            Width.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GenCounter.deserialize(buffer);
            Height.deserialize(buffer);
            Width.deserialize(buffer);
        }
    };
    // AgentHeightWidthPacket Member List
    AgentDataBlock AgentData;
    HeightWidthBlockBlock HeightWidthBlock;

public:
    AgentHeightWidthPacket() {
        this->setID(AgentHeightWidth_ID);
    };
    virtual ~AgentHeightWidthPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeightWidthBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeightWidthBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentHeightWidthPacket();
    }
};

// AgentSetAppearancePacket
class AgentSetAppearancePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
        SerializableVector3 Size;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
            Size.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
            Size.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID CacheID;
        SerializableU8 TextureIndex;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CacheID.serialize(buffer);
            TextureIndex.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CacheID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureEntry.deserialize(buffer);
        }
    };
    class VisualParamBlock : public PacketSerializable {
    public:
        // VisualParamBlock Member List
        SerializableU8 ParamValue;
    public:
        VisualParamBlock() {};
        virtual ~VisualParamBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParamValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParamValue.deserialize(buffer);
        }
    };
    // AgentSetAppearancePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;
    ObjectDataBlock ObjectData;
    VariableSerializable<VisualParamBlock> VisualParam;

public:
    AgentSetAppearancePacket() {
        this->setID(AgentSetAppearance_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentSetAppearancePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
        ObjectData.serialize(buffer);
        VisualParam.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        VisualParam.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentSetAppearancePacket();
    }
};

// AgentAnimationPacket
class AgentAnimationPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AnimationListBlock : public PacketSerializable {
    public:
        // AnimationListBlock Member List
        SerializableUUID AnimID;
        SerializableBool StartAnim;
    public:
        AnimationListBlock() {};
        virtual ~AnimationListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AnimID.serialize(buffer);
            StartAnim.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AnimID.deserialize(buffer);
            StartAnim.deserialize(buffer);
        }
    };
    class PhysicalAvatarEventListBlock : public PacketSerializable {
    public:
        // PhysicalAvatarEventListBlock Member List
        SerializableVariable1 TypeData;
    public:
        PhysicalAvatarEventListBlock() {};
        virtual ~PhysicalAvatarEventListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TypeData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TypeData.deserialize(buffer);
        }
    };
    // AgentAnimationPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<AnimationListBlock> AnimationList;
    VariableSerializable<PhysicalAvatarEventListBlock> PhysicalAvatarEventList;

public:
    AgentAnimationPacket() {
        this->setID(AgentAnimation_ID);
    };
    virtual ~AgentAnimationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AnimationList.serialize(buffer);
        PhysicalAvatarEventList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AnimationList.deserialize(buffer);
        PhysicalAvatarEventList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentAnimationPacket();
    }
};

// AgentRequestSitPacket
class AgentRequestSitPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TargetObjectBlock : public PacketSerializable {
    public:
        // TargetObjectBlock Member List
        SerializableUUID TargetID;
        SerializableVector3 Offset;
    public:
        TargetObjectBlock() {};
        virtual ~TargetObjectBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Offset.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Offset.deserialize(buffer);
        }
    };
    // AgentRequestSitPacket Member List
    AgentDataBlock AgentData;
    TargetObjectBlock TargetObject;

public:
    AgentRequestSitPacket() {
        this->setID(AgentRequestSit_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentRequestSitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TargetObject.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TargetObject.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentRequestSitPacket();
    }
};

// AgentSitPacket
class AgentSitPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentSitPacket Member List
    AgentDataBlock AgentData;

public:
    AgentSitPacket() {
        this->setID(AgentSit_ID);
    };
    virtual ~AgentSitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentSitPacket();
    }
};

// AgentQuitCopyPacket
class AgentQuitCopyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FuseBlockBlock : public PacketSerializable {
    public:
        // FuseBlockBlock Member List
        SerializableU32 ViewerCircuitCode;
    public:
        FuseBlockBlock() {};
        virtual ~FuseBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ViewerCircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ViewerCircuitCode.deserialize(buffer);
        }
    };
    // AgentQuitCopyPacket Member List
    AgentDataBlock AgentData;
    FuseBlockBlock FuseBlock;

public:
    AgentQuitCopyPacket() {
        this->setID(AgentQuitCopy_ID);
    };
    virtual ~AgentQuitCopyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FuseBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FuseBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentQuitCopyPacket();
    }
};

// RequestImagePacket
class RequestImagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestImageBlock : public PacketSerializable {
    public:
        // RequestImageBlock Member List
        SerializableUUID Image;
        SerializableS8 DiscardLevel;
        SerializableF32 DownloadPriority;
        SerializableU32 Packet;
        SerializableU8 Type;
    public:
        RequestImageBlock() {};
        virtual ~RequestImageBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Image.serialize(buffer);
            DiscardLevel.serialize(buffer);
            DownloadPriority.serialize(buffer);
            Packet.serialize(buffer);
            Type.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Image.deserialize(buffer);
            DiscardLevel.deserialize(buffer);
            DownloadPriority.deserialize(buffer);
            Packet.deserialize(buffer);
            Type.deserialize(buffer);
        }
    };
    // RequestImagePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RequestImageBlock> RequestImage;

public:
    RequestImagePacket() {
        this->setID(RequestImage_ID);
    };
    virtual ~RequestImagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestImage.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestImage.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestImagePacket();
    }
};

// ImageNotInDatabasePacket
class ImageNotInDatabasePacket : public PacketBase {
public:

    // Block Class List
    class ImageIDBlock : public PacketSerializable {
    public:
        // ImageIDBlock Member List
        SerializableUUID ID;
    public:
        ImageIDBlock() {};
        virtual ~ImageIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // ImageNotInDatabasePacket Member List
    ImageIDBlock ImageID;

public:
    ImageNotInDatabasePacket() {
        this->setID(ImageNotInDatabase_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ImageNotInDatabasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ImageID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ImageID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImageNotInDatabasePacket();
    }
};

// RebakeAvatarTexturesPacket
class RebakeAvatarTexturesPacket : public PacketBase {
public:

    // Block Class List
    class TextureDataBlock : public PacketSerializable {
    public:
        // TextureDataBlock Member List
        SerializableUUID TextureID;
    public:
        TextureDataBlock() {};
        virtual ~TextureDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureID.deserialize(buffer);
        }
    };
    // RebakeAvatarTexturesPacket Member List
    TextureDataBlock TextureData;

public:
    RebakeAvatarTexturesPacket() {
        this->setID(RebakeAvatarTextures_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RebakeAvatarTexturesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TextureData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TextureData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RebakeAvatarTexturesPacket();
    }
};

// SetAlwaysRunPacket
class SetAlwaysRunPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool AlwaysRun;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AlwaysRun.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AlwaysRun.deserialize(buffer);
        }
    };
    // SetAlwaysRunPacket Member List
    AgentDataBlock AgentData;

public:
    SetAlwaysRunPacket() {
        this->setID(SetAlwaysRun_ID);
    };
    virtual ~SetAlwaysRunPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetAlwaysRunPacket();
    }
};

// ObjectAddPacket
class ObjectAddPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU8 PCode;
        SerializableU8 Material;
        SerializableU32 AddFlags;
        SerializableU8 PathCurve;
        SerializableU8 ProfileCurve;
        SerializableU16 PathBegin;
        SerializableU16 PathEnd;
        SerializableU8 PathScaleX;
        SerializableU8 PathScaleY;
        SerializableU8 PathShearX;
        SerializableU8 PathShearY;
        SerializableS8 PathTwist;
        SerializableS8 PathTwistBegin;
        SerializableS8 PathRadiusOffset;
        SerializableS8 PathTaperX;
        SerializableS8 PathTaperY;
        SerializableU8 PathRevolutions;
        SerializableS8 PathSkew;
        SerializableU16 ProfileBegin;
        SerializableU16 ProfileEnd;
        SerializableU16 ProfileHollow;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableU8 RayEndIsIntersection;
        SerializableVector3 Scale;
        SerializableQuaternion Rotation;
        SerializableU8 State;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PCode.serialize(buffer);
            Material.serialize(buffer);
            AddFlags.serialize(buffer);
            PathCurve.serialize(buffer);
            ProfileCurve.serialize(buffer);
            PathBegin.serialize(buffer);
            PathEnd.serialize(buffer);
            PathScaleX.serialize(buffer);
            PathScaleY.serialize(buffer);
            PathShearX.serialize(buffer);
            PathShearY.serialize(buffer);
            PathTwist.serialize(buffer);
            PathTwistBegin.serialize(buffer);
            PathRadiusOffset.serialize(buffer);
            PathTaperX.serialize(buffer);
            PathTaperY.serialize(buffer);
            PathRevolutions.serialize(buffer);
            PathSkew.serialize(buffer);
            ProfileBegin.serialize(buffer);
            ProfileEnd.serialize(buffer);
            ProfileHollow.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            Scale.serialize(buffer);
            Rotation.serialize(buffer);
            State.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PCode.deserialize(buffer);
            Material.deserialize(buffer);
            AddFlags.deserialize(buffer);
            PathCurve.deserialize(buffer);
            ProfileCurve.deserialize(buffer);
            PathBegin.deserialize(buffer);
            PathEnd.deserialize(buffer);
            PathScaleX.deserialize(buffer);
            PathScaleY.deserialize(buffer);
            PathShearX.deserialize(buffer);
            PathShearY.deserialize(buffer);
            PathTwist.deserialize(buffer);
            PathTwistBegin.deserialize(buffer);
            PathRadiusOffset.deserialize(buffer);
            PathTaperX.deserialize(buffer);
            PathTaperY.deserialize(buffer);
            PathRevolutions.deserialize(buffer);
            PathSkew.deserialize(buffer);
            ProfileBegin.deserialize(buffer);
            ProfileEnd.deserialize(buffer);
            ProfileHollow.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            Scale.deserialize(buffer);
            Rotation.deserialize(buffer);
            State.deserialize(buffer);
        }
    };
    // ObjectAddPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectAddPacket() {
        this->setID(ObjectAdd_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectAddPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectAddPacket();
    }
};

// ObjectDeletePacket
class ObjectDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Force;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Force.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Force.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDeletePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDeletePacket() {
        this->setID(ObjectDelete_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeletePacket();
    }
};

// ObjectDuplicatePacket
class ObjectDuplicatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class SharedDataBlock : public PacketSerializable {
    public:
        // SharedDataBlock Member List
        SerializableVector3 Offset;
        SerializableU32 DuplicateFlags;
    public:
        SharedDataBlock() {};
        virtual ~SharedDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Offset.serialize(buffer);
            DuplicateFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Offset.deserialize(buffer);
            DuplicateFlags.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDuplicatePacket Member List
    AgentDataBlock AgentData;
    SharedDataBlock SharedData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDuplicatePacket() {
        this->setID(ObjectDuplicate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDuplicatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        SharedData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        SharedData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDuplicatePacket();
    }
};

// ObjectDuplicateOnRayPacket
class ObjectDuplicateOnRayPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableBool BypassRaycast;
        SerializableBool RayEndIsIntersection;
        SerializableBool CopyCenters;
        SerializableBool CopyRotates;
        SerializableUUID RayTargetID;
        SerializableU32 DuplicateFlags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            CopyCenters.serialize(buffer);
            CopyRotates.serialize(buffer);
            RayTargetID.serialize(buffer);
            DuplicateFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            CopyCenters.deserialize(buffer);
            CopyRotates.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            DuplicateFlags.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDuplicateOnRayPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDuplicateOnRayPacket() {
        this->setID(ObjectDuplicateOnRay_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDuplicateOnRayPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDuplicateOnRayPacket();
    }
};

// MultipleObjectUpdatePacket
class MultipleObjectUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Type;
        SerializableVariable1 Data;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Type.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Type.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // MultipleObjectUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    MultipleObjectUpdatePacket() {
        this->setID(MultipleObjectUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MultipleObjectUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MultipleObjectUpdatePacket();
    }
};

// RequestMultipleObjectsPacket
class RequestMultipleObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU8 CacheMissType;
        SerializableU32 ID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CacheMissType.serialize(buffer);
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CacheMissType.deserialize(buffer);
            ID.deserialize(buffer);
        }
    };
    // RequestMultipleObjectsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    RequestMultipleObjectsPacket() {
        this->setID(RequestMultipleObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestMultipleObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestMultipleObjectsPacket();
    }
};

// ObjectPositionPacket
class ObjectPositionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVector3 Position;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Position.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Position.deserialize(buffer);
        }
    };
    // ObjectPositionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectPositionPacket() {
        this->setID(ObjectPosition_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPositionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPositionPacket();
    }
};

// ObjectScalePacket
class ObjectScalePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVector3 Scale;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Scale.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Scale.deserialize(buffer);
        }
    };
    // ObjectScalePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectScalePacket() {
        this->setID(ObjectScale_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectScalePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectScalePacket();
    }
};

// ObjectRotationPacket
class ObjectRotationPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectRotationPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectRotationPacket() {
        this->setID(ObjectRotation_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectRotationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectRotationPacket();
    }
};

// ObjectFlagUpdatePacket
class ObjectFlagUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 ObjectLocalID;
        SerializableBool UsePhysics;
        SerializableBool IsTemporary;
        SerializableBool IsPhantom;
        SerializableBool CastsShadows;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            ObjectLocalID.serialize(buffer);
            UsePhysics.serialize(buffer);
            IsTemporary.serialize(buffer);
            IsPhantom.serialize(buffer);
            CastsShadows.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            ObjectLocalID.deserialize(buffer);
            UsePhysics.deserialize(buffer);
            IsTemporary.deserialize(buffer);
            IsPhantom.deserialize(buffer);
            CastsShadows.deserialize(buffer);
        }
    };
    // ObjectFlagUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    ObjectFlagUpdatePacket() {
        this->setID(ObjectFlagUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectFlagUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectFlagUpdatePacket();
    }
};

// ObjectClickActionPacket
class ObjectClickActionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 ClickAction;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            ClickAction.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            ClickAction.deserialize(buffer);
        }
    };
    // ObjectClickActionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectClickActionPacket() {
        this->setID(ObjectClickAction_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectClickActionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectClickActionPacket();
    }
};

// ObjectImagePacket
class ObjectImagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableVariable1 MediaURL;
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            MediaURL.serialize(buffer);
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            MediaURL.deserialize(buffer);
            TextureEntry.deserialize(buffer);
        }
    };
    // ObjectImagePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectImagePacket() {
        this->setID(ObjectImage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectImagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectImagePacket();
    }
};

// ObjectMaterialPacket
class ObjectMaterialPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Material;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Material.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Material.deserialize(buffer);
        }
    };
    // ObjectMaterialPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectMaterialPacket() {
        this->setID(ObjectMaterial_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectMaterialPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectMaterialPacket();
    }
};

// ObjectShapePacket
class ObjectShapePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 PathCurve;
        SerializableU8 ProfileCurve;
        SerializableU16 PathBegin;
        SerializableU16 PathEnd;
        SerializableU8 PathScaleX;
        SerializableU8 PathScaleY;
        SerializableU8 PathShearX;
        SerializableU8 PathShearY;
        SerializableS8 PathTwist;
        SerializableS8 PathTwistBegin;
        SerializableS8 PathRadiusOffset;
        SerializableS8 PathTaperX;
        SerializableS8 PathTaperY;
        SerializableU8 PathRevolutions;
        SerializableS8 PathSkew;
        SerializableU16 ProfileBegin;
        SerializableU16 ProfileEnd;
        SerializableU16 ProfileHollow;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            PathCurve.serialize(buffer);
            ProfileCurve.serialize(buffer);
            PathBegin.serialize(buffer);
            PathEnd.serialize(buffer);
            PathScaleX.serialize(buffer);
            PathScaleY.serialize(buffer);
            PathShearX.serialize(buffer);
            PathShearY.serialize(buffer);
            PathTwist.serialize(buffer);
            PathTwistBegin.serialize(buffer);
            PathRadiusOffset.serialize(buffer);
            PathTaperX.serialize(buffer);
            PathTaperY.serialize(buffer);
            PathRevolutions.serialize(buffer);
            PathSkew.serialize(buffer);
            ProfileBegin.serialize(buffer);
            ProfileEnd.serialize(buffer);
            ProfileHollow.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            PathCurve.deserialize(buffer);
            ProfileCurve.deserialize(buffer);
            PathBegin.deserialize(buffer);
            PathEnd.deserialize(buffer);
            PathScaleX.deserialize(buffer);
            PathScaleY.deserialize(buffer);
            PathShearX.deserialize(buffer);
            PathShearY.deserialize(buffer);
            PathTwist.deserialize(buffer);
            PathTwistBegin.deserialize(buffer);
            PathRadiusOffset.deserialize(buffer);
            PathTaperX.deserialize(buffer);
            PathTaperY.deserialize(buffer);
            PathRevolutions.deserialize(buffer);
            PathSkew.deserialize(buffer);
            ProfileBegin.deserialize(buffer);
            ProfileEnd.deserialize(buffer);
            ProfileHollow.deserialize(buffer);
        }
    };
    // ObjectShapePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectShapePacket() {
        this->setID(ObjectShape_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectShapePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectShapePacket();
    }
};

// ObjectExtraParamsPacket
class ObjectExtraParamsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU16 ParamType;
        SerializableBool ParamInUse;
        SerializableU32 ParamSize;
        SerializableVariable1 ParamData;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            ParamType.serialize(buffer);
            ParamInUse.serialize(buffer);
            ParamSize.serialize(buffer);
            ParamData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            ParamType.deserialize(buffer);
            ParamInUse.deserialize(buffer);
            ParamSize.deserialize(buffer);
            ParamData.deserialize(buffer);
        }
    };
    // ObjectExtraParamsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectExtraParamsPacket() {
        this->setID(ObjectExtraParams_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectExtraParamsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectExtraParamsPacket();
    }
};

// ObjectOwnerPacket
class ObjectOwnerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableBool Override;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Override.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Override.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectOwnerPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectOwnerPacket() {
        this->setID(ObjectOwner_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectOwnerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectOwnerPacket();
    }
};

// ObjectGroupPacket
class ObjectGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectGroupPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectGroupPacket() {
        this->setID(ObjectGroup_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGroupPacket();
    }
};

// ObjectBuyPacket
class ObjectBuyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID CategoryID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            CategoryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            CategoryID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
        }
    };
    // ObjectBuyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectBuyPacket() {
        this->setID(ObjectBuy_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectBuyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectBuyPacket();
    }
};

// BuyObjectInventoryPacket
class BuyObjectInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableUUID FolderID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    // BuyObjectInventoryPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    BuyObjectInventoryPacket() {
        this->setID(BuyObjectInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~BuyObjectInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new BuyObjectInventoryPacket();
    }
};

// DerezContainerPacket
class DerezContainerPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableBool Delete;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            Delete.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            Delete.deserialize(buffer);
        }
    };
    // DerezContainerPacket Member List
    DataBlock Data;

public:
    DerezContainerPacket() {
        this->setID(DerezContainer_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DerezContainerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DerezContainerPacket();
    }
};

// ObjectPermissionsPacket
class ObjectPermissionsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableBool Override;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Override.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Override.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableU8 Field;
        SerializableU8 Set;
        SerializableU32 Mask;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Field.serialize(buffer);
            Set.serialize(buffer);
            Mask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Field.deserialize(buffer);
            Set.deserialize(buffer);
            Mask.deserialize(buffer);
        }
    };
    // ObjectPermissionsPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectPermissionsPacket() {
        this->setID(ObjectPermissions_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPermissionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPermissionsPacket();
    }
};

// ObjectSaleInfoPacket
class ObjectSaleInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
        }
    };
    // ObjectSaleInfoPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectSaleInfoPacket() {
        this->setID(ObjectSaleInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSaleInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSaleInfoPacket();
    }
};

// ObjectNamePacket
class ObjectNamePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVariable1 Name;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // ObjectNamePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectNamePacket() {
        this->setID(ObjectName_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectNamePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectNamePacket();
    }
};

// ObjectDescriptionPacket
class ObjectDescriptionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // ObjectDescriptionPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDescriptionPacket() {
        this->setID(ObjectDescription_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDescriptionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDescriptionPacket();
    }
};

// ObjectCategoryPacket
class ObjectCategoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableU32 Category;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Category.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Category.deserialize(buffer);
        }
    };
    // ObjectCategoryPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectCategoryPacket() {
        this->setID(ObjectCategory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectCategoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectCategoryPacket();
    }
};

// ObjectSelectPacket
class ObjectSelectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectSelectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectSelectPacket() {
        this->setID(ObjectSelect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSelectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSelectPacket();
    }
};

// ObjectDeselectPacket
class ObjectDeselectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDeselectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDeselectPacket() {
        this->setID(ObjectDeselect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectDeselectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeselectPacket();
    }
};

// ObjectAttachPacket
class ObjectAttachPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU8 AttachmentPoint;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AttachmentPoint.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AttachmentPoint.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectAttachPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectAttachPacket() {
        this->setID(ObjectAttach_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectAttachPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectAttachPacket();
    }
};

// ObjectDetachPacket
class ObjectDetachPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDetachPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDetachPacket() {
        this->setID(ObjectDetach_ID);
    };
    virtual ~ObjectDetachPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDetachPacket();
    }
};

// ObjectDropPacket
class ObjectDropPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDropPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDropPacket() {
        this->setID(ObjectDrop_ID);
    };
    virtual ~ObjectDropPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDropPacket();
    }
};

// ObjectLinkPacket
class ObjectLinkPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectLinkPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectLinkPacket() {
        this->setID(ObjectLink_ID);
    };
    virtual ~ObjectLinkPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectLinkPacket();
    }
};

// ObjectDelinkPacket
class ObjectDelinkPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // ObjectDelinkPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectDelinkPacket() {
        this->setID(ObjectDelink_ID);
    };
    virtual ~ObjectDelinkPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDelinkPacket();
    }
};

// ObjectGrabPacket
class ObjectGrabPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
        SerializableVector3 GrabOffset;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            GrabOffset.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            GrabOffset.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectGrabPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;

public:
    ObjectGrabPacket() {
        this->setID(ObjectGrab_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGrabPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGrabPacket();
    }
};

// ObjectGrabUpdatePacket
class ObjectGrabUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableVector3 GrabOffsetInitial;
        SerializableVector3 GrabPosition;
        SerializableU32 TimeSinceLast;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            GrabOffsetInitial.serialize(buffer);
            GrabPosition.serialize(buffer);
            TimeSinceLast.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            GrabOffsetInitial.deserialize(buffer);
            GrabPosition.deserialize(buffer);
            TimeSinceLast.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectGrabUpdatePacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;

public:
    ObjectGrabUpdatePacket() {
        this->setID(ObjectGrabUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectGrabUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectGrabUpdatePacket();
    }
};

// ObjectDeGrabPacket
class ObjectDeGrabPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 LocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    class SurfaceInfoBlock : public PacketSerializable {
    public:
        // SurfaceInfoBlock Member List
        SerializableVector3 UVCoord;
        SerializableVector3 STCoord;
        SerializableS32 FaceIndex;
        SerializableVector3 Position;
        SerializableVector3 Normal;
        SerializableVector3 Binormal;
    public:
        SurfaceInfoBlock() {};
        virtual ~SurfaceInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UVCoord.serialize(buffer);
            STCoord.serialize(buffer);
            FaceIndex.serialize(buffer);
            Position.serialize(buffer);
            Normal.serialize(buffer);
            Binormal.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UVCoord.deserialize(buffer);
            STCoord.deserialize(buffer);
            FaceIndex.deserialize(buffer);
            Position.deserialize(buffer);
            Normal.deserialize(buffer);
            Binormal.deserialize(buffer);
        }
    };
    // ObjectDeGrabPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;
    VariableSerializable<SurfaceInfoBlock> SurfaceInfo;

public:
    ObjectDeGrabPacket() {
        this->setID(ObjectDeGrab_ID);
    };
    virtual ~ObjectDeGrabPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
        SurfaceInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
        SurfaceInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectDeGrabPacket();
    }
};

// ObjectSpinStartPacket
class ObjectSpinStartPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectSpinStartPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinStartPacket() {
        this->setID(ObjectSpinStart_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinStartPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinStartPacket();
    }
};

// ObjectSpinUpdatePacket
class ObjectSpinUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableQuaternion Rotation;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            Rotation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            Rotation.deserialize(buffer);
        }
    };
    // ObjectSpinUpdatePacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinUpdatePacket() {
        this->setID(ObjectSpinUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinUpdatePacket();
    }
};

// ObjectSpinStopPacket
class ObjectSpinStopPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectSpinStopPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    ObjectSpinStopPacket() {
        this->setID(ObjectSpinStop_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectSpinStopPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectSpinStopPacket();
    }
};

// ObjectExportSelectedPacket
class ObjectExportSelectedPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID RequestID;
        SerializableS16 VolumeDetail;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            RequestID.serialize(buffer);
            VolumeDetail.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            RequestID.deserialize(buffer);
            VolumeDetail.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ObjectExportSelectedPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectExportSelectedPacket() {
        this->setID(ObjectExportSelected_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectExportSelectedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectExportSelectedPacket();
    }
};

// ModifyLandPacket
class ModifyLandPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ModifyBlockBlock : public PacketSerializable {
    public:
        // ModifyBlockBlock Member List
        SerializableU8 Action;
        SerializableU8 BrushSize;
        SerializableF32 Seconds;
        SerializableF32 Height;
    public:
        ModifyBlockBlock() {};
        virtual ~ModifyBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Action.serialize(buffer);
            BrushSize.serialize(buffer);
            Seconds.serialize(buffer);
            Height.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Action.deserialize(buffer);
            BrushSize.deserialize(buffer);
            Seconds.deserialize(buffer);
            Height.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ModifyLandPacket Member List
    AgentDataBlock AgentData;
    ModifyBlockBlock ModifyBlock;
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    ModifyLandPacket() {
        this->setID(ModifyLand_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ModifyLandPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ModifyBlock.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ModifyBlock.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ModifyLandPacket();
    }
};

// VelocityInterpolateOnPacket
class VelocityInterpolateOnPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // VelocityInterpolateOnPacket Member List
    AgentDataBlock AgentData;

public:
    VelocityInterpolateOnPacket() {
        this->setID(VelocityInterpolateOn_ID);
    };
    virtual ~VelocityInterpolateOnPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new VelocityInterpolateOnPacket();
    }
};

// VelocityInterpolateOffPacket
class VelocityInterpolateOffPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // VelocityInterpolateOffPacket Member List
    AgentDataBlock AgentData;

public:
    VelocityInterpolateOffPacket() {
        this->setID(VelocityInterpolateOff_ID);
    };
    virtual ~VelocityInterpolateOffPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new VelocityInterpolateOffPacket();
    }
};

// StateSavePacket
class StateSavePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableVariable1 Filename;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Filename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Filename.deserialize(buffer);
        }
    };
    // StateSavePacket Member List
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;

public:
    StateSavePacket() {
        this->setID(StateSave_ID);
    };
    virtual ~StateSavePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StateSavePacket();
    }
};

// ReportAutosaveCrashPacket
class ReportAutosaveCrashPacket : public PacketBase {
public:

    // Block Class List
    class AutosaveDataBlock : public PacketSerializable {
    public:
        // AutosaveDataBlock Member List
        SerializableS32 PID;
        SerializableS32 Status;
    public:
        AutosaveDataBlock() {};
        virtual ~AutosaveDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PID.serialize(buffer);
            Status.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PID.deserialize(buffer);
            Status.deserialize(buffer);
        }
    };
    // ReportAutosaveCrashPacket Member List
    AutosaveDataBlock AutosaveData;

public:
    ReportAutosaveCrashPacket() {
        this->setID(ReportAutosaveCrash_ID);
    };
    virtual ~ReportAutosaveCrashPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AutosaveData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AutosaveData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ReportAutosaveCrashPacket();
    }
};

// SimWideDeletesPacket
class SimWideDeletesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // SimWideDeletesPacket Member List
    AgentDataBlock AgentData;
    DataBlockBlock DataBlock;

public:
    SimWideDeletesPacket() {
        this->setID(SimWideDeletes_ID);
    };
    virtual ~SimWideDeletesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimWideDeletesPacket();
    }
};

// RequestObjectPropertiesFamilyPacket
class RequestObjectPropertiesFamilyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 RequestFlags;
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestFlags.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestFlags.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    // RequestObjectPropertiesFamilyPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    RequestObjectPropertiesFamilyPacket() {
        this->setID(RequestObjectPropertiesFamily_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestObjectPropertiesFamilyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestObjectPropertiesFamilyPacket();
    }
};

// TrackAgentPacket
class TrackAgentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TargetDataBlock : public PacketSerializable {
    public:
        // TargetDataBlock Member List
        SerializableUUID PreyID;
    public:
        TargetDataBlock() {};
        virtual ~TargetDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PreyID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PreyID.deserialize(buffer);
        }
    };
    // TrackAgentPacket Member List
    AgentDataBlock AgentData;
    TargetDataBlock TargetData;

public:
    TrackAgentPacket() {
        this->setID(TrackAgent_ID);
    };
    virtual ~TrackAgentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TargetData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TargetData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TrackAgentPacket();
    }
};

// ViewerStatsPacket
class ViewerStatsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableIPADDR IP;
        SerializableU32 StartTime;
        SerializableF32 RunTime;
        SerializableF32 SimFPS;
        SerializableF32 FPS;
        SerializableU8 AgentsInView;
        SerializableF32 Ping;
        SerializableF64 MetersTraveled;
        SerializableS32 RegionsVisited;
        SerializableU32 SysRAM;
        SerializableVariable1 SysOS;
        SerializableVariable1 SysCPU;
        SerializableVariable1 SysGPU;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            IP.serialize(buffer);
            StartTime.serialize(buffer);
            RunTime.serialize(buffer);
            SimFPS.serialize(buffer);
            FPS.serialize(buffer);
            AgentsInView.serialize(buffer);
            Ping.serialize(buffer);
            MetersTraveled.serialize(buffer);
            RegionsVisited.serialize(buffer);
            SysRAM.serialize(buffer);
            SysOS.serialize(buffer);
            SysCPU.serialize(buffer);
            SysGPU.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            IP.deserialize(buffer);
            StartTime.deserialize(buffer);
            RunTime.deserialize(buffer);
            SimFPS.deserialize(buffer);
            FPS.deserialize(buffer);
            AgentsInView.deserialize(buffer);
            Ping.deserialize(buffer);
            MetersTraveled.deserialize(buffer);
            RegionsVisited.deserialize(buffer);
            SysRAM.deserialize(buffer);
            SysOS.deserialize(buffer);
            SysCPU.deserialize(buffer);
            SysGPU.deserialize(buffer);
        }
    };
    class DownloadTotalsBlock : public PacketSerializable {
    public:
        // DownloadTotalsBlock Member List
        SerializableU32 World;
        SerializableU32 Objects;
        SerializableU32 Textures;
    public:
        DownloadTotalsBlock() {};
        virtual ~DownloadTotalsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            World.serialize(buffer);
            Objects.serialize(buffer);
            Textures.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            World.deserialize(buffer);
            Objects.deserialize(buffer);
            Textures.deserialize(buffer);
        }
    };
    class NetStatsBlock : public PacketSerializable {
    public:
        // NetStatsBlock Member List
        SerializableU32 Bytes;
        SerializableU32 Packets;
        SerializableU32 Compressed;
        SerializableU32 Savings;
    public:
        NetStatsBlock() {};
        virtual ~NetStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Bytes.serialize(buffer);
            Packets.serialize(buffer);
            Compressed.serialize(buffer);
            Savings.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Bytes.deserialize(buffer);
            Packets.deserialize(buffer);
            Compressed.deserialize(buffer);
            Savings.deserialize(buffer);
        }
    };
    class FailStatsBlock : public PacketSerializable {
    public:
        // FailStatsBlock Member List
        SerializableU32 SendPacket;
        SerializableU32 Dropped;
        SerializableU32 Resent;
        SerializableU32 FailedResends;
        SerializableU32 OffCircuit;
        SerializableU32 Invalid;
    public:
        FailStatsBlock() {};
        virtual ~FailStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SendPacket.serialize(buffer);
            Dropped.serialize(buffer);
            Resent.serialize(buffer);
            FailedResends.serialize(buffer);
            OffCircuit.serialize(buffer);
            Invalid.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SendPacket.deserialize(buffer);
            Dropped.deserialize(buffer);
            Resent.deserialize(buffer);
            FailedResends.deserialize(buffer);
            OffCircuit.deserialize(buffer);
            Invalid.deserialize(buffer);
        }
    };
    class MiscStatsBlock : public PacketSerializable {
    public:
        // MiscStatsBlock Member List
        SerializableU32 Type;
        SerializableF64 Value;
    public:
        MiscStatsBlock() {};
        virtual ~MiscStatsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Type.serialize(buffer);
            Value.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Type.deserialize(buffer);
            Value.deserialize(buffer);
        }
    };
    // ViewerStatsPacket Member List
    AgentDataBlock AgentData;
    DownloadTotalsBlock DownloadTotals;
    MultipleSerializable<NetStatsBlock, 2> NetStats;
    FailStatsBlock FailStats;
    VariableSerializable<MiscStatsBlock> MiscStats;

public:
    ViewerStatsPacket() {
        this->setID(ViewerStats_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ViewerStatsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        DownloadTotals.serialize(buffer);
        NetStats.serialize(buffer);
        FailStats.serialize(buffer);
        MiscStats.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        DownloadTotals.deserialize(buffer);
        NetStats.deserialize(buffer);
        FailStats.deserialize(buffer);
        MiscStats.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerStatsPacket();
    }
};

// ScriptAnswerYesPacket
class ScriptAnswerYesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableS32 Questions;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            Questions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Questions.deserialize(buffer);
        }
    };
    // ScriptAnswerYesPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ScriptAnswerYesPacket() {
        this->setID(ScriptAnswerYes_ID);
    };
    virtual ~ScriptAnswerYesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptAnswerYesPacket();
    }
};

// UserReportPacket
class UserReportPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ReportDataBlock : public PacketSerializable {
    public:
        // ReportDataBlock Member List
        SerializableU8 ReportType;
        SerializableU8 Category;
        SerializableVector3 Position;
        SerializableU8 CheckFlags;
        SerializableUUID ScreenshotID;
        SerializableUUID ObjectID;
        SerializableUUID AbuserID;
        SerializableVariable1 AbuseRegionName;
        SerializableUUID AbuseRegionID;
        SerializableVariable1 Summary;
        SerializableVariable2 Details;
        SerializableVariable1 VersionString;
    public:
        ReportDataBlock() {};
        virtual ~ReportDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            Category.serialize(buffer);
            Position.serialize(buffer);
            CheckFlags.serialize(buffer);
            ScreenshotID.serialize(buffer);
            ObjectID.serialize(buffer);
            AbuserID.serialize(buffer);
            AbuseRegionName.serialize(buffer);
            AbuseRegionID.serialize(buffer);
            Summary.serialize(buffer);
            Details.serialize(buffer);
            VersionString.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            Category.deserialize(buffer);
            Position.deserialize(buffer);
            CheckFlags.deserialize(buffer);
            ScreenshotID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            AbuserID.deserialize(buffer);
            AbuseRegionName.deserialize(buffer);
            AbuseRegionID.deserialize(buffer);
            Summary.deserialize(buffer);
            Details.deserialize(buffer);
            VersionString.deserialize(buffer);
        }
    };
    // UserReportPacket Member List
    AgentDataBlock AgentData;
    ReportDataBlock ReportData;

public:
    UserReportPacket() {
        this->setID(UserReport_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UserReportPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ReportData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ReportData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserReportPacket();
    }
};

// AlertMessagePacket
class AlertMessagePacket : public PacketBase {
public:

    // Block Class List
    class AlertDataBlock : public PacketSerializable {
    public:
        // AlertDataBlock Member List
        SerializableVariable1 Message;
    public:
        AlertDataBlock() {};
        virtual ~AlertDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Message.deserialize(buffer);
        }
    };
    // AlertMessagePacket Member List
    AlertDataBlock AlertData;

public:
    AlertMessagePacket() {
        this->setID(AlertMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AlertMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AlertData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AlertData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AlertMessagePacket();
    }
};

// AgentAlertMessagePacket
class AgentAlertMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class AlertDataBlock : public PacketSerializable {
    public:
        // AlertDataBlock Member List
        SerializableBool Modal;
        SerializableVariable1 Message;
    public:
        AlertDataBlock() {};
        virtual ~AlertDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Modal.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Modal.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // AgentAlertMessagePacket Member List
    AgentDataBlock AgentData;
    AlertDataBlock AlertData;

public:
    AgentAlertMessagePacket() {
        this->setID(AgentAlertMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AgentAlertMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AlertData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AlertData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentAlertMessagePacket();
    }
};

// MeanCollisionAlertPacket
class MeanCollisionAlertPacket : public PacketBase {
public:

    // Block Class List
    class MeanCollisionBlock : public PacketSerializable {
    public:
        // MeanCollisionBlock Member List
        SerializableUUID Victim;
        SerializableUUID Perp;
        SerializableU32 Time;
        SerializableF32 Mag;
        SerializableU8 Type;
    public:
        MeanCollisionBlock() {};
        virtual ~MeanCollisionBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Victim.serialize(buffer);
            Perp.serialize(buffer);
            Time.serialize(buffer);
            Mag.serialize(buffer);
            Type.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Victim.deserialize(buffer);
            Perp.deserialize(buffer);
            Time.deserialize(buffer);
            Mag.deserialize(buffer);
            Type.deserialize(buffer);
        }
    };
    // MeanCollisionAlertPacket Member List
    VariableSerializable<MeanCollisionBlock> MeanCollision;

public:
    MeanCollisionAlertPacket() {
        this->setID(MeanCollisionAlert_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MeanCollisionAlertPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MeanCollision.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MeanCollision.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MeanCollisionAlertPacket();
    }
};

// ViewerFrozenMessagePacket
class ViewerFrozenMessagePacket : public PacketBase {
public:

    // Block Class List
    class FrozenDataBlock : public PacketSerializable {
    public:
        // FrozenDataBlock Member List
        SerializableBool Data;
    public:
        FrozenDataBlock() {};
        virtual ~FrozenDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // ViewerFrozenMessagePacket Member List
    FrozenDataBlock FrozenData;

public:
    ViewerFrozenMessagePacket() {
        this->setID(ViewerFrozenMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ViewerFrozenMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        FrozenData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        FrozenData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerFrozenMessagePacket();
    }
};

// HealthMessagePacket
class HealthMessagePacket : public PacketBase {
public:

    // Block Class List
    class HealthDataBlock : public PacketSerializable {
    public:
        // HealthDataBlock Member List
        SerializableF32 Health;
    public:
        HealthDataBlock() {};
        virtual ~HealthDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Health.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Health.deserialize(buffer);
        }
    };
    // HealthMessagePacket Member List
    HealthDataBlock HealthData;

public:
    HealthMessagePacket() {
        this->setID(HealthMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~HealthMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        HealthData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        HealthData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new HealthMessagePacket();
    }
};

// ChatFromSimulatorPacket
class ChatFromSimulatorPacket : public PacketBase {
public:

    // Block Class List
    class ChatDataBlock : public PacketSerializable {
    public:
        // ChatDataBlock Member List
        SerializableVariable1 FromName;
        SerializableUUID SourceID;
        SerializableUUID OwnerID;
        SerializableU8 SourceType;
        SerializableU8 ChatType;
        SerializableU8 Audible;
        SerializableVector3 Position;
        SerializableVariable2 Message;
    public:
        ChatDataBlock() {};
        virtual ~ChatDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromName.serialize(buffer);
            SourceID.serialize(buffer);
            OwnerID.serialize(buffer);
            SourceType.serialize(buffer);
            ChatType.serialize(buffer);
            Audible.serialize(buffer);
            Position.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromName.deserialize(buffer);
            SourceID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            SourceType.deserialize(buffer);
            ChatType.deserialize(buffer);
            Audible.deserialize(buffer);
            Position.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // ChatFromSimulatorPacket Member List
    ChatDataBlock ChatData;

public:
    ChatFromSimulatorPacket() {
        this->setID(ChatFromSimulator_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ChatFromSimulatorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ChatData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ChatData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChatFromSimulatorPacket();
    }
};

// SimStatsPacket
class SimStatsPacket : public PacketBase {
public:

    // Block Class List
    class RegionBlock : public PacketSerializable {
    public:
        // RegionBlock Member List
        SerializableU32 RegionX;
        SerializableU32 RegionY;
        SerializableU32 RegionFlags;
        SerializableU32 ObjectCapacity;
    public:
        RegionBlock() {};
        virtual ~RegionBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionX.serialize(buffer);
            RegionY.serialize(buffer);
            RegionFlags.serialize(buffer);
            ObjectCapacity.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionX.deserialize(buffer);
            RegionY.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            ObjectCapacity.deserialize(buffer);
        }
    };
    class StatBlock : public PacketSerializable {
    public:
        // StatBlock Member List
        SerializableU32 StatID;
        SerializableF32 StatValue;
    public:
        StatBlock() {};
        virtual ~StatBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            StatID.serialize(buffer);
            StatValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            StatID.deserialize(buffer);
            StatValue.deserialize(buffer);
        }
    };
    class PidStatBlock : public PacketSerializable {
    public:
        // PidStatBlock Member List
        SerializableS32 PID;
    public:
        PidStatBlock() {};
        virtual ~PidStatBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PID.deserialize(buffer);
        }
    };
    // SimStatsPacket Member List
    RegionBlock Region;
    VariableSerializable<StatBlock> Stat;
    PidStatBlock PidStat;

public:
    SimStatsPacket() {
        this->setID(SimStats_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimStatsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Region.serialize(buffer);
        Stat.serialize(buffer);
        PidStat.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Region.deserialize(buffer);
        Stat.deserialize(buffer);
        PidStat.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimStatsPacket();
    }
};

// RequestRegionInfoPacket
class RequestRegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // RequestRegionInfoPacket Member List
    AgentDataBlock AgentData;

public:
    RequestRegionInfoPacket() {
        this->setID(RequestRegionInfo_ID);
    };
    virtual ~RequestRegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestRegionInfoPacket();
    }
};

// RegionInfoPacket
class RegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
        SerializableU32 RegionFlags;
        SerializableU8 SimAccess;
        SerializableU8 MaxAgents;
        SerializableF32 BillableFactor;
        SerializableF32 ObjectBonusFactor;
        SerializableF32 WaterHeight;
        SerializableF32 TerrainRaiseLimit;
        SerializableF32 TerrainLowerLimit;
        SerializableS32 PricePerMeter;
        SerializableS32 RedirectGridX;
        SerializableS32 RedirectGridY;
        SerializableBool UseEstateSun;
        SerializableF32 SunHour;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionFlags.serialize(buffer);
            SimAccess.serialize(buffer);
            MaxAgents.serialize(buffer);
            BillableFactor.serialize(buffer);
            ObjectBonusFactor.serialize(buffer);
            WaterHeight.serialize(buffer);
            TerrainRaiseLimit.serialize(buffer);
            TerrainLowerLimit.serialize(buffer);
            PricePerMeter.serialize(buffer);
            RedirectGridX.serialize(buffer);
            RedirectGridY.serialize(buffer);
            UseEstateSun.serialize(buffer);
            SunHour.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            SimAccess.deserialize(buffer);
            MaxAgents.deserialize(buffer);
            BillableFactor.deserialize(buffer);
            ObjectBonusFactor.deserialize(buffer);
            WaterHeight.deserialize(buffer);
            TerrainRaiseLimit.deserialize(buffer);
            TerrainLowerLimit.deserialize(buffer);
            PricePerMeter.deserialize(buffer);
            RedirectGridX.deserialize(buffer);
            RedirectGridY.deserialize(buffer);
            UseEstateSun.deserialize(buffer);
            SunHour.deserialize(buffer);
        }
    };
    // RegionInfoPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    RegionInfoPacket() {
        this->setID(RegionInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionInfoPacket();
    }
};

// GodUpdateRegionInfoPacket
class GodUpdateRegionInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 EstateID;
        SerializableU32 ParentEstateID;
        SerializableU32 RegionFlags;
        SerializableF32 BillableFactor;
        SerializableS32 PricePerMeter;
        SerializableS32 RedirectGridX;
        SerializableS32 RedirectGridY;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            EstateID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionFlags.serialize(buffer);
            BillableFactor.serialize(buffer);
            PricePerMeter.serialize(buffer);
            RedirectGridX.serialize(buffer);
            RedirectGridY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            EstateID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            BillableFactor.deserialize(buffer);
            PricePerMeter.deserialize(buffer);
            RedirectGridX.deserialize(buffer);
            RedirectGridY.deserialize(buffer);
        }
    };
    // GodUpdateRegionInfoPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    GodUpdateRegionInfoPacket() {
        this->setID(GodUpdateRegionInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GodUpdateRegionInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodUpdateRegionInfoPacket();
    }
};

// NearestLandingRegionRequestPacket
class NearestLandingRegionRequestPacket : public PacketBase {
public:

    // Block Class List
    class RequestingRegionDataBlock : public PacketSerializable {
    public:
        // RequestingRegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RequestingRegionDataBlock() {};
        virtual ~RequestingRegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // NearestLandingRegionRequestPacket Member List
    RequestingRegionDataBlock RequestingRegionData;

public:
    NearestLandingRegionRequestPacket() {
        this->setID(NearestLandingRegionRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~NearestLandingRegionRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RequestingRegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RequestingRegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NearestLandingRegionRequestPacket();
    }
};

// NearestLandingRegionReplyPacket
class NearestLandingRegionReplyPacket : public PacketBase {
public:

    // Block Class List
    class LandingRegionDataBlock : public PacketSerializable {
    public:
        // LandingRegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        LandingRegionDataBlock() {};
        virtual ~LandingRegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // NearestLandingRegionReplyPacket Member List
    LandingRegionDataBlock LandingRegionData;

public:
    NearestLandingRegionReplyPacket() {
        this->setID(NearestLandingRegionReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~NearestLandingRegionReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        LandingRegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        LandingRegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NearestLandingRegionReplyPacket();
    }
};

// NearestLandingRegionUpdatedPacket
class NearestLandingRegionUpdatedPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // NearestLandingRegionUpdatedPacket Member List
    RegionDataBlock RegionData;

public:
    NearestLandingRegionUpdatedPacket() {
        this->setID(NearestLandingRegionUpdated_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~NearestLandingRegionUpdatedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NearestLandingRegionUpdatedPacket();
    }
};

// TeleportLandingStatusChangedPacket
class TeleportLandingStatusChangedPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // TeleportLandingStatusChangedPacket Member List
    RegionDataBlock RegionData;

public:
    TeleportLandingStatusChangedPacket() {
        this->setID(TeleportLandingStatusChanged_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TeleportLandingStatusChangedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TeleportLandingStatusChangedPacket();
    }
};

// RegionHandshakePacket
class RegionHandshakePacket : public PacketBase {
public:

    // Block Class List
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableU32 RegionFlags;
        SerializableU8 SimAccess;
        SerializableVariable1 SimName;
        SerializableUUID SimOwner;
        SerializableBool IsEstateManager;
        SerializableF32 WaterHeight;
        SerializableF32 BillableFactor;
        SerializableUUID CacheID;
        SerializableUUID TerrainBase0;
        SerializableUUID TerrainBase1;
        SerializableUUID TerrainBase2;
        SerializableUUID TerrainBase3;
        SerializableUUID TerrainDetail0;
        SerializableUUID TerrainDetail1;
        SerializableUUID TerrainDetail2;
        SerializableUUID TerrainDetail3;
        SerializableF32 TerrainStartHeight00;
        SerializableF32 TerrainStartHeight01;
        SerializableF32 TerrainStartHeight10;
        SerializableF32 TerrainStartHeight11;
        SerializableF32 TerrainHeightRange00;
        SerializableF32 TerrainHeightRange01;
        SerializableF32 TerrainHeightRange10;
        SerializableF32 TerrainHeightRange11;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionFlags.serialize(buffer);
            SimAccess.serialize(buffer);
            SimName.serialize(buffer);
            SimOwner.serialize(buffer);
            IsEstateManager.serialize(buffer);
            WaterHeight.serialize(buffer);
            BillableFactor.serialize(buffer);
            CacheID.serialize(buffer);
            TerrainBase0.serialize(buffer);
            TerrainBase1.serialize(buffer);
            TerrainBase2.serialize(buffer);
            TerrainBase3.serialize(buffer);
            TerrainDetail0.serialize(buffer);
            TerrainDetail1.serialize(buffer);
            TerrainDetail2.serialize(buffer);
            TerrainDetail3.serialize(buffer);
            TerrainStartHeight00.serialize(buffer);
            TerrainStartHeight01.serialize(buffer);
            TerrainStartHeight10.serialize(buffer);
            TerrainStartHeight11.serialize(buffer);
            TerrainHeightRange00.serialize(buffer);
            TerrainHeightRange01.serialize(buffer);
            TerrainHeightRange10.serialize(buffer);
            TerrainHeightRange11.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionFlags.deserialize(buffer);
            SimAccess.deserialize(buffer);
            SimName.deserialize(buffer);
            SimOwner.deserialize(buffer);
            IsEstateManager.deserialize(buffer);
            WaterHeight.deserialize(buffer);
            BillableFactor.deserialize(buffer);
            CacheID.deserialize(buffer);
            TerrainBase0.deserialize(buffer);
            TerrainBase1.deserialize(buffer);
            TerrainBase2.deserialize(buffer);
            TerrainBase3.deserialize(buffer);
            TerrainDetail0.deserialize(buffer);
            TerrainDetail1.deserialize(buffer);
            TerrainDetail2.deserialize(buffer);
            TerrainDetail3.deserialize(buffer);
            TerrainStartHeight00.deserialize(buffer);
            TerrainStartHeight01.deserialize(buffer);
            TerrainStartHeight10.deserialize(buffer);
            TerrainStartHeight11.deserialize(buffer);
            TerrainHeightRange00.deserialize(buffer);
            TerrainHeightRange01.deserialize(buffer);
            TerrainHeightRange10.deserialize(buffer);
            TerrainHeightRange11.deserialize(buffer);
        }
    };
    class RegionInfo2Block : public PacketSerializable {
    public:
        // RegionInfo2Block Member List
        SerializableUUID RegionID;
    public:
        RegionInfo2Block() {};
        virtual ~RegionInfo2Block() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
        }
    };
    // RegionHandshakePacket Member List
    RegionInfoBlock RegionInfo;
    RegionInfo2Block RegionInfo2;

public:
    RegionHandshakePacket() {
        this->setID(RegionHandshake_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionHandshakePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionInfo.serialize(buffer);
        RegionInfo2.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionInfo.deserialize(buffer);
        RegionInfo2.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionHandshakePacket();
    }
};

// RegionHandshakeReplyPacket
class RegionHandshakeReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionInfoBlock : public PacketSerializable {
    public:
        // RegionInfoBlock Member List
        SerializableU32 Flags;
    public:
        RegionInfoBlock() {};
        virtual ~RegionInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
        }
    };
    // RegionHandshakeReplyPacket Member List
    AgentDataBlock AgentData;
    RegionInfoBlock RegionInfo;

public:
    RegionHandshakeReplyPacket() {
        this->setID(RegionHandshakeReply_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RegionHandshakeReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionHandshakeReplyPacket();
    }
};

// CoarseLocationUpdatePacket
class CoarseLocationUpdatePacket : public PacketBase {
public:

    // Block Class List
    class LocationBlock : public PacketSerializable {
    public:
        // LocationBlock Member List
        SerializableU8 X;
        SerializableU8 Y;
        SerializableU8 Z;
    public:
        LocationBlock() {};
        virtual ~LocationBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            X.serialize(buffer);
            Y.serialize(buffer);
            Z.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            X.deserialize(buffer);
            Y.deserialize(buffer);
            Z.deserialize(buffer);
        }
    };
    class IndexBlock : public PacketSerializable {
    public:
        // IndexBlock Member List
        SerializableS16 You;
        SerializableS16 Prey;
    public:
        IndexBlock() {};
        virtual ~IndexBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            You.serialize(buffer);
            Prey.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            You.deserialize(buffer);
            Prey.deserialize(buffer);
        }
    };
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // CoarseLocationUpdatePacket Member List
    VariableSerializable<LocationBlock> Location;
    IndexBlock Index;
    VariableSerializable<AgentDataBlock> AgentData;

public:
    CoarseLocationUpdatePacket() {
        this->setID(CoarseLocationUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CoarseLocationUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Location.serialize(buffer);
        Index.serialize(buffer);
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Location.deserialize(buffer);
        Index.deserialize(buffer);
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CoarseLocationUpdatePacket();
    }
};

// ImageDataPacket
class ImageDataPacket : public PacketBase {
public:

    // Block Class List
    class ImageIDBlock : public PacketSerializable {
    public:
        // ImageIDBlock Member List
        SerializableUUID ID;
        SerializableU8 Codec;
        SerializableU32 Size;
        SerializableU16 Packets;
    public:
        ImageIDBlock() {};
        virtual ~ImageIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Codec.serialize(buffer);
            Size.serialize(buffer);
            Packets.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Codec.deserialize(buffer);
            Size.deserialize(buffer);
            Packets.deserialize(buffer);
        }
    };
    class ImageDataBlock : public PacketSerializable {
    public:
        // ImageDataBlock Member List
        SerializableVariable2 Data;
    public:
        ImageDataBlock() {};
        virtual ~ImageDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // ImageDataPacket Member List
    ImageIDBlock ImageID;
    ImageDataBlock ImageData;

public:
    ImageDataPacket() {
        this->setID(ImageData_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ImageDataPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ImageID.serialize(buffer);
        ImageData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ImageID.deserialize(buffer);
        ImageData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImageDataPacket();
    }
};

// ImagePacketPacket
class ImagePacketPacket : public PacketBase {
public:

    // Block Class List
    class ImageIDBlock : public PacketSerializable {
    public:
        // ImageIDBlock Member List
        SerializableUUID ID;
        SerializableU16 Packet;
    public:
        ImageIDBlock() {};
        virtual ~ImageIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Packet.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Packet.deserialize(buffer);
        }
    };
    class ImageDataBlock : public PacketSerializable {
    public:
        // ImageDataBlock Member List
        SerializableVariable2 Data;
    public:
        ImageDataBlock() {};
        virtual ~ImageDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // ImagePacketPacket Member List
    ImageIDBlock ImageID;
    ImageDataBlock ImageData;

public:
    ImagePacketPacket() {
        this->setID(ImagePacket_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ImagePacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ImageID.serialize(buffer);
        ImageData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ImageID.deserialize(buffer);
        ImageData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImagePacketPacket();
    }
};

// LayerDataPacket
class LayerDataPacket : public PacketBase {
public:

    // Block Class List
    class LayerIDBlock : public PacketSerializable {
    public:
        // LayerIDBlock Member List
        SerializableU8 Type;
    public:
        LayerIDBlock() {};
        virtual ~LayerIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Type.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Type.deserialize(buffer);
        }
    };
    class LayerDataBlock : public PacketSerializable {
    public:
        // LayerDataBlock Member List
        SerializableVariable2 Data;
    public:
        LayerDataBlock() {};
        virtual ~LayerDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // LayerDataPacket Member List
    LayerIDBlock LayerID;
    LayerDataBlock LayerData;

public:
    LayerDataPacket() {
        this->setID(LayerData_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LayerDataPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        LayerID.serialize(buffer);
        LayerData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        LayerID.deserialize(buffer);
        LayerData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LayerDataPacket();
    }
};

// ObjectUpdatePacket
class ObjectUpdatePacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU16 TimeDilation;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            TimeDilation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            TimeDilation.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ID;
        SerializableU8 State;
        SerializableUUID FullID;
        SerializableU32 CRC;
        SerializableU8 PCode;
        SerializableU8 Material;
        SerializableU8 ClickAction;
        SerializableVector3 Scale;
        SerializableVariable1 ObjectData;
        SerializableU32 ParentID;
        SerializableU32 UpdateFlags;
        SerializableU8 PathCurve;
        SerializableU8 ProfileCurve;
        SerializableU16 PathBegin;
        SerializableU16 PathEnd;
        SerializableU8 PathScaleX;
        SerializableU8 PathScaleY;
        SerializableU8 PathShearX;
        SerializableU8 PathShearY;
        SerializableS8 PathTwist;
        SerializableS8 PathTwistBegin;
        SerializableS8 PathRadiusOffset;
        SerializableS8 PathTaperX;
        SerializableS8 PathTaperY;
        SerializableU8 PathRevolutions;
        SerializableS8 PathSkew;
        SerializableU16 ProfileBegin;
        SerializableU16 ProfileEnd;
        SerializableU16 ProfileHollow;
        SerializableVariable2 TextureEntry;
        SerializableVariable1 TextureAnim;
        SerializableVariable2 NameValue;
        SerializableVariable2 Data;
        SerializableVariable1 Text;
        SerializableFixed<4> TextColor;
        SerializableVariable1 MediaURL;
        SerializableVariable1 PSBlock;
        SerializableVariable1 ExtraParams;
        SerializableUUID Sound;
        SerializableUUID OwnerID;
        SerializableF32 Gain;
        SerializableU8 Flags;
        SerializableF32 Radius;
        SerializableU8 JointType;
        SerializableVector3 JointPivot;
        SerializableVector3 JointAxisOrAnchor;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            State.serialize(buffer);
            FullID.serialize(buffer);
            CRC.serialize(buffer);
            PCode.serialize(buffer);
            Material.serialize(buffer);
            ClickAction.serialize(buffer);
            Scale.serialize(buffer);
            ObjectData.serialize(buffer);
            ParentID.serialize(buffer);
            UpdateFlags.serialize(buffer);
            PathCurve.serialize(buffer);
            ProfileCurve.serialize(buffer);
            PathBegin.serialize(buffer);
            PathEnd.serialize(buffer);
            PathScaleX.serialize(buffer);
            PathScaleY.serialize(buffer);
            PathShearX.serialize(buffer);
            PathShearY.serialize(buffer);
            PathTwist.serialize(buffer);
            PathTwistBegin.serialize(buffer);
            PathRadiusOffset.serialize(buffer);
            PathTaperX.serialize(buffer);
            PathTaperY.serialize(buffer);
            PathRevolutions.serialize(buffer);
            PathSkew.serialize(buffer);
            ProfileBegin.serialize(buffer);
            ProfileEnd.serialize(buffer);
            ProfileHollow.serialize(buffer);
            TextureEntry.serialize(buffer);
            TextureAnim.serialize(buffer);
            NameValue.serialize(buffer);
            Data.serialize(buffer);
            Text.serialize(buffer);
            TextColor.serialize(buffer);
            MediaURL.serialize(buffer);
            PSBlock.serialize(buffer);
            ExtraParams.serialize(buffer);
            Sound.serialize(buffer);
            OwnerID.serialize(buffer);
            Gain.serialize(buffer);
            Flags.serialize(buffer);
            Radius.serialize(buffer);
            JointType.serialize(buffer);
            JointPivot.serialize(buffer);
            JointAxisOrAnchor.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            State.deserialize(buffer);
            FullID.deserialize(buffer);
            CRC.deserialize(buffer);
            PCode.deserialize(buffer);
            Material.deserialize(buffer);
            ClickAction.deserialize(buffer);
            Scale.deserialize(buffer);
            ObjectData.deserialize(buffer);
            ParentID.deserialize(buffer);
            UpdateFlags.deserialize(buffer);
            PathCurve.deserialize(buffer);
            ProfileCurve.deserialize(buffer);
            PathBegin.deserialize(buffer);
            PathEnd.deserialize(buffer);
            PathScaleX.deserialize(buffer);
            PathScaleY.deserialize(buffer);
            PathShearX.deserialize(buffer);
            PathShearY.deserialize(buffer);
            PathTwist.deserialize(buffer);
            PathTwistBegin.deserialize(buffer);
            PathRadiusOffset.deserialize(buffer);
            PathTaperX.deserialize(buffer);
            PathTaperY.deserialize(buffer);
            PathRevolutions.deserialize(buffer);
            PathSkew.deserialize(buffer);
            ProfileBegin.deserialize(buffer);
            ProfileEnd.deserialize(buffer);
            ProfileHollow.deserialize(buffer);
            TextureEntry.deserialize(buffer);
            TextureAnim.deserialize(buffer);
            NameValue.deserialize(buffer);
            Data.deserialize(buffer);
            Text.deserialize(buffer);
            TextColor.deserialize(buffer);
            MediaURL.deserialize(buffer);
            PSBlock.deserialize(buffer);
            ExtraParams.deserialize(buffer);
            Sound.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Gain.deserialize(buffer);
            Flags.deserialize(buffer);
            Radius.deserialize(buffer);
            JointType.deserialize(buffer);
            JointPivot.deserialize(buffer);
            JointAxisOrAnchor.deserialize(buffer);
        }
    };
    // ObjectUpdatePacket Member List
    RegionDataBlock RegionData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectUpdatePacket() {
        this->setID(ObjectUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectUpdatePacket();
    }
};

// ObjectUpdateCompressedPacket
class ObjectUpdateCompressedPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU16 TimeDilation;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            TimeDilation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            TimeDilation.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 UpdateFlags;
        SerializableVariable2 Data;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UpdateFlags.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UpdateFlags.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // ObjectUpdateCompressedPacket Member List
    RegionDataBlock RegionData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectUpdateCompressedPacket() {
        this->setID(ObjectUpdateCompressed_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ObjectUpdateCompressedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectUpdateCompressedPacket();
    }
};

// ObjectUpdateCachedPacket
class ObjectUpdateCachedPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU16 TimeDilation;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            TimeDilation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            TimeDilation.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ID;
        SerializableU32 CRC;
        SerializableU32 UpdateFlags;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            CRC.serialize(buffer);
            UpdateFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            CRC.deserialize(buffer);
            UpdateFlags.deserialize(buffer);
        }
    };
    // ObjectUpdateCachedPacket Member List
    RegionDataBlock RegionData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectUpdateCachedPacket() {
        this->setID(ObjectUpdateCached_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ObjectUpdateCachedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectUpdateCachedPacket();
    }
};

// ImprovedTerseObjectUpdatePacket
class ImprovedTerseObjectUpdatePacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU16 TimeDilation;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            TimeDilation.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            TimeDilation.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableVariable1 Data;
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
            TextureEntry.deserialize(buffer);
        }
    };
    // ImprovedTerseObjectUpdatePacket Member List
    RegionDataBlock RegionData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ImprovedTerseObjectUpdatePacket() {
        this->setID(ImprovedTerseObjectUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ImprovedTerseObjectUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImprovedTerseObjectUpdatePacket();
    }
};

// KillObjectPacket
class KillObjectPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // KillObjectPacket Member List
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    KillObjectPacket() {
        this->setID(KillObject_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~KillObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new KillObjectPacket();
    }
};

// CrossedRegionPacket
class CrossedRegionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableIPADDR SimIP;
        SerializableIPPORT SimPort;
        SerializableU64 RegionHandle;
        SerializableVariable2 SeedCapability;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimIP.serialize(buffer);
            SimPort.serialize(buffer);
            RegionHandle.serialize(buffer);
            SeedCapability.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimIP.deserialize(buffer);
            SimPort.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            SeedCapability.deserialize(buffer);
        }
    };
    class InfoBlock : public PacketSerializable {
    public:
        // InfoBlock Member List
        SerializableVector3 Position;
        SerializableVector3 LookAt;
    public:
        InfoBlock() {};
        virtual ~InfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Position.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // CrossedRegionPacket Member List
    AgentDataBlock AgentData;
    RegionDataBlock RegionData;
    InfoBlock Info;

public:
    CrossedRegionPacket() {
        this->setID(CrossedRegion_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CrossedRegionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionData.serialize(buffer);
        Info.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionData.deserialize(buffer);
        Info.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CrossedRegionPacket();
    }
};

// SimulatorViewerTimeMessagePacket
class SimulatorViewerTimeMessagePacket : public PacketBase {
public:

    // Block Class List
    class TimeInfoBlock : public PacketSerializable {
    public:
        // TimeInfoBlock Member List
        SerializableU64 UsecSinceStart;
        SerializableU32 SecPerDay;
        SerializableU32 SecPerYear;
        SerializableVector3 SunDirection;
        SerializableF32 SunPhase;
        SerializableVector3 SunAngVelocity;
    public:
        TimeInfoBlock() {};
        virtual ~TimeInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UsecSinceStart.serialize(buffer);
            SecPerDay.serialize(buffer);
            SecPerYear.serialize(buffer);
            SunDirection.serialize(buffer);
            SunPhase.serialize(buffer);
            SunAngVelocity.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UsecSinceStart.deserialize(buffer);
            SecPerDay.deserialize(buffer);
            SecPerYear.deserialize(buffer);
            SunDirection.deserialize(buffer);
            SunPhase.deserialize(buffer);
            SunAngVelocity.deserialize(buffer);
        }
    };
    // SimulatorViewerTimeMessagePacket Member List
    TimeInfoBlock TimeInfo;

public:
    SimulatorViewerTimeMessagePacket() {
        this->setID(SimulatorViewerTimeMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimulatorViewerTimeMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TimeInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TimeInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimulatorViewerTimeMessagePacket();
    }
};

// EnableSimulatorPacket
class EnableSimulatorPacket : public PacketBase {
public:

    // Block Class List
    class SimulatorInfoBlock : public PacketSerializable {
    public:
        // SimulatorInfoBlock Member List
        SerializableU64 Handle;
        SerializableIPADDR IP;
        SerializableIPPORT Port;
    public:
        SimulatorInfoBlock() {};
        virtual ~SimulatorInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Handle.serialize(buffer);
            IP.serialize(buffer);
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Handle.deserialize(buffer);
            IP.deserialize(buffer);
            Port.deserialize(buffer);
        }
    };
    // EnableSimulatorPacket Member List
    SimulatorInfoBlock SimulatorInfo;

public:
    EnableSimulatorPacket() {
        this->setID(EnableSimulator_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EnableSimulatorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimulatorInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimulatorInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EnableSimulatorPacket();
    }
};

// DisableSimulatorPacket
class DisableSimulatorPacket : public PacketBase {
public:

    // Block Class List
    // DisableSimulatorPacket Member List

public:
    DisableSimulatorPacket() {
        this->setID(DisableSimulator_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~DisableSimulatorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new DisableSimulatorPacket();
    }
};

// ConfirmEnableSimulatorPacket
class ConfirmEnableSimulatorPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ConfirmEnableSimulatorPacket Member List
    AgentDataBlock AgentData;

public:
    ConfirmEnableSimulatorPacket() {
        this->setID(ConfirmEnableSimulator_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ConfirmEnableSimulatorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ConfirmEnableSimulatorPacket();
    }
};

// TransferRequestPacket
class TransferRequestPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 SourceType;
        SerializableF32 Priority;
        SerializableVariable2 Params;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            SourceType.serialize(buffer);
            Priority.serialize(buffer);
            Params.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            SourceType.deserialize(buffer);
            Priority.deserialize(buffer);
            Params.deserialize(buffer);
        }
    };
    // TransferRequestPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferRequestPacket() {
        this->setID(TransferRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferRequestPacket();
    }
};

// TransferInfoPacket
class TransferInfoPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 TargetType;
        SerializableS32 Status;
        SerializableS32 Size;
        SerializableVariable2 Params;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            TargetType.serialize(buffer);
            Status.serialize(buffer);
            Size.serialize(buffer);
            Params.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            TargetType.deserialize(buffer);
            Status.deserialize(buffer);
            Size.deserialize(buffer);
            Params.deserialize(buffer);
        }
    };
    // TransferInfoPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferInfoPacket() {
        this->setID(TransferInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferInfoPacket();
    }
};

// TransferPacketPacket
class TransferPacketPacket : public PacketBase {
public:

    // Block Class List
    class TransferDataBlock : public PacketSerializable {
    public:
        // TransferDataBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
        SerializableS32 Packet;
        SerializableS32 Status;
        SerializableVariable2 Data;
    public:
        TransferDataBlock() {};
        virtual ~TransferDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
            Packet.serialize(buffer);
            Status.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
            Packet.deserialize(buffer);
            Status.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // TransferPacketPacket Member List
    TransferDataBlock TransferData;

public:
    TransferPacketPacket() {
        this->setID(TransferPacket_ID);
    };
    virtual ~TransferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferPacketPacket();
    }
};

// TransferAbortPacket
class TransferAbortPacket : public PacketBase {
public:

    // Block Class List
    class TransferInfoBlock : public PacketSerializable {
    public:
        // TransferInfoBlock Member List
        SerializableUUID TransferID;
        SerializableS32 ChannelType;
    public:
        TransferInfoBlock() {};
        virtual ~TransferInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransferID.serialize(buffer);
            ChannelType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransferID.deserialize(buffer);
            ChannelType.deserialize(buffer);
        }
    };
    // TransferAbortPacket Member List
    TransferInfoBlock TransferInfo;

public:
    TransferAbortPacket() {
        this->setID(TransferAbort_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferAbortPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransferInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransferInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferAbortPacket();
    }
};

// RequestXferPacket
class RequestXferPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableVariable1 Filename;
        SerializableU8 FilePath;
        SerializableBool DeleteOnCompletion;
        SerializableBool UseBigPackets;
        SerializableUUID VFileID;
        SerializableS16 VFileType;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Filename.serialize(buffer);
            FilePath.serialize(buffer);
            DeleteOnCompletion.serialize(buffer);
            UseBigPackets.serialize(buffer);
            VFileID.serialize(buffer);
            VFileType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Filename.deserialize(buffer);
            FilePath.deserialize(buffer);
            DeleteOnCompletion.deserialize(buffer);
            UseBigPackets.deserialize(buffer);
            VFileID.deserialize(buffer);
            VFileType.deserialize(buffer);
        }
    };
    // RequestXferPacket Member List
    XferIDBlock XferID;

public:
    RequestXferPacket() {
        this->setID(RequestXfer_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestXferPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestXferPacket();
    }
};

// SendXferPacketPacket
class SendXferPacketPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableU32 Packet;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Packet.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Packet.deserialize(buffer);
        }
    };
    class DataPacketBlock : public PacketSerializable {
    public:
        // DataPacketBlock Member List
        SerializableVariable2 Data;
    public:
        DataPacketBlock() {};
        virtual ~DataPacketBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Data.deserialize(buffer);
        }
    };
    // SendXferPacketPacket Member List
    XferIDBlock XferID;
    DataPacketBlock DataPacket;

public:
    SendXferPacketPacket() {
        this->setID(SendXferPacket_ID);
    };
    virtual ~SendXferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
        DataPacket.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
        DataPacket.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SendXferPacketPacket();
    }
};

// ConfirmXferPacketPacket
class ConfirmXferPacketPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableU32 Packet;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Packet.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Packet.deserialize(buffer);
        }
    };
    // ConfirmXferPacketPacket Member List
    XferIDBlock XferID;

public:
    ConfirmXferPacketPacket() {
        this->setID(ConfirmXferPacket_ID);
    };
    virtual ~ConfirmXferPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ConfirmXferPacketPacket();
    }
};

// AbortXferPacket
class AbortXferPacket : public PacketBase {
public:

    // Block Class List
    class XferIDBlock : public PacketSerializable {
    public:
        // XferIDBlock Member List
        SerializableU64 ID;
        SerializableS32 Result;
    public:
        XferIDBlock() {};
        virtual ~XferIDBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Result.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Result.deserialize(buffer);
        }
    };
    // AbortXferPacket Member List
    XferIDBlock XferID;

public:
    AbortXferPacket() {
        this->setID(AbortXfer_ID);
    };
    virtual ~AbortXferPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        XferID.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        XferID.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AbortXferPacket();
    }
};

// AvatarAnimationPacket
class AvatarAnimationPacket : public PacketBase {
public:

    // Block Class List
    class SenderBlock : public PacketSerializable {
    public:
        // SenderBlock Member List
        SerializableUUID ID;
    public:
        SenderBlock() {};
        virtual ~SenderBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    class AnimationListBlock : public PacketSerializable {
    public:
        // AnimationListBlock Member List
        SerializableUUID AnimID;
        SerializableS32 AnimSequenceID;
    public:
        AnimationListBlock() {};
        virtual ~AnimationListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AnimID.serialize(buffer);
            AnimSequenceID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AnimID.deserialize(buffer);
            AnimSequenceID.deserialize(buffer);
        }
    };
    class AnimationSourceListBlock : public PacketSerializable {
    public:
        // AnimationSourceListBlock Member List
        SerializableUUID ObjectID;
    public:
        AnimationSourceListBlock() {};
        virtual ~AnimationSourceListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    class PhysicalAvatarEventListBlock : public PacketSerializable {
    public:
        // PhysicalAvatarEventListBlock Member List
        SerializableVariable1 TypeData;
    public:
        PhysicalAvatarEventListBlock() {};
        virtual ~PhysicalAvatarEventListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TypeData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TypeData.deserialize(buffer);
        }
    };
    // AvatarAnimationPacket Member List
    SenderBlock Sender;
    VariableSerializable<AnimationListBlock> AnimationList;
    VariableSerializable<AnimationSourceListBlock> AnimationSourceList;
    VariableSerializable<PhysicalAvatarEventListBlock> PhysicalAvatarEventList;

public:
    AvatarAnimationPacket() {
        this->setID(AvatarAnimation_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarAnimationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Sender.serialize(buffer);
        AnimationList.serialize(buffer);
        AnimationSourceList.serialize(buffer);
        PhysicalAvatarEventList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Sender.deserialize(buffer);
        AnimationList.deserialize(buffer);
        AnimationSourceList.deserialize(buffer);
        PhysicalAvatarEventList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarAnimationPacket();
    }
};

// AvatarAppearancePacket
class AvatarAppearancePacket : public PacketBase {
public:

    // Block Class List
    class SenderBlock : public PacketSerializable {
    public:
        // SenderBlock Member List
        SerializableUUID ID;
        SerializableBool IsTrial;
    public:
        SenderBlock() {};
        virtual ~SenderBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            IsTrial.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            IsTrial.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableVariable2 TextureEntry;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureEntry.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureEntry.deserialize(buffer);
        }
    };
    class VisualParamBlock : public PacketSerializable {
    public:
        // VisualParamBlock Member List
        SerializableU8 ParamValue;
    public:
        VisualParamBlock() {};
        virtual ~VisualParamBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParamValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParamValue.deserialize(buffer);
        }
    };
    // AvatarAppearancePacket Member List
    SenderBlock Sender;
    ObjectDataBlock ObjectData;
    VariableSerializable<VisualParamBlock> VisualParam;

public:
    AvatarAppearancePacket() {
        this->setID(AvatarAppearance_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarAppearancePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Sender.serialize(buffer);
        ObjectData.serialize(buffer);
        VisualParam.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Sender.deserialize(buffer);
        ObjectData.deserialize(buffer);
        VisualParam.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarAppearancePacket();
    }
};

// AvatarSitResponsePacket
class AvatarSitResponsePacket : public PacketBase {
public:

    // Block Class List
    class SitObjectBlock : public PacketSerializable {
    public:
        // SitObjectBlock Member List
        SerializableUUID ID;
    public:
        SitObjectBlock() {};
        virtual ~SitObjectBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    class SitTransformBlock : public PacketSerializable {
    public:
        // SitTransformBlock Member List
        SerializableBool AutoPilot;
        SerializableVector3 SitPosition;
        SerializableQuaternion SitRotation;
        SerializableVector3 CameraEyeOffset;
        SerializableVector3 CameraAtOffset;
        SerializableBool ForceMouselook;
    public:
        SitTransformBlock() {};
        virtual ~SitTransformBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AutoPilot.serialize(buffer);
            SitPosition.serialize(buffer);
            SitRotation.serialize(buffer);
            CameraEyeOffset.serialize(buffer);
            CameraAtOffset.serialize(buffer);
            ForceMouselook.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AutoPilot.deserialize(buffer);
            SitPosition.deserialize(buffer);
            SitRotation.deserialize(buffer);
            CameraEyeOffset.deserialize(buffer);
            CameraAtOffset.deserialize(buffer);
            ForceMouselook.deserialize(buffer);
        }
    };
    // AvatarSitResponsePacket Member List
    SitObjectBlock SitObject;
    SitTransformBlock SitTransform;

public:
    AvatarSitResponsePacket() {
        this->setID(AvatarSitResponse_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarSitResponsePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SitObject.serialize(buffer);
        SitTransform.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SitObject.deserialize(buffer);
        SitTransform.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarSitResponsePacket();
    }
};

// SetFollowCamPropertiesPacket
class SetFollowCamPropertiesPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    class CameraPropertyBlock : public PacketSerializable {
    public:
        // CameraPropertyBlock Member List
        SerializableS32 Type;
        SerializableF32 Value;
    public:
        CameraPropertyBlock() {};
        virtual ~CameraPropertyBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Type.serialize(buffer);
            Value.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Type.deserialize(buffer);
            Value.deserialize(buffer);
        }
    };
    // SetFollowCamPropertiesPacket Member List
    ObjectDataBlock ObjectData;
    VariableSerializable<CameraPropertyBlock> CameraProperty;

public:
    SetFollowCamPropertiesPacket() {
        this->setID(SetFollowCamProperties_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SetFollowCamPropertiesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
        CameraProperty.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
        CameraProperty.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetFollowCamPropertiesPacket();
    }
};

// ClearFollowCamPropertiesPacket
class ClearFollowCamPropertiesPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // ClearFollowCamPropertiesPacket Member List
    ObjectDataBlock ObjectData;

public:
    ClearFollowCamPropertiesPacket() {
        this->setID(ClearFollowCamProperties_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ClearFollowCamPropertiesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ClearFollowCamPropertiesPacket();
    }
};

// CameraConstraintPacket
class CameraConstraintPacket : public PacketBase {
public:

    // Block Class List
    class CameraCollidePlaneBlock : public PacketSerializable {
    public:
        // CameraCollidePlaneBlock Member List
        SerializableVector4 Plane;
    public:
        CameraCollidePlaneBlock() {};
        virtual ~CameraCollidePlaneBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Plane.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Plane.deserialize(buffer);
        }
    };
    // CameraConstraintPacket Member List
    CameraCollidePlaneBlock CameraCollidePlane;

public:
    CameraConstraintPacket() {
        this->setID(CameraConstraint_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CameraConstraintPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CameraCollidePlane.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CameraCollidePlane.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CameraConstraintPacket();
    }
};

// ObjectPropertiesPacket
class ObjectPropertiesPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU64 CreationDate;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableS32 OwnershipCost;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableU8 AggregatePerms;
        SerializableU8 AggregatePermTextures;
        SerializableU8 AggregatePermTexturesOwner;
        SerializableU32 Category;
        SerializableS16 InventorySerial;
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID FromTaskID;
        SerializableUUID LastOwnerID;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableVariable1 TouchName;
        SerializableVariable1 SitName;
        SerializableVariable1 TextureID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            CreationDate.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            OwnershipCost.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            AggregatePerms.serialize(buffer);
            AggregatePermTextures.serialize(buffer);
            AggregatePermTexturesOwner.serialize(buffer);
            Category.serialize(buffer);
            InventorySerial.serialize(buffer);
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            FromTaskID.serialize(buffer);
            LastOwnerID.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            TouchName.serialize(buffer);
            SitName.serialize(buffer);
            TextureID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            CreationDate.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            OwnershipCost.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            AggregatePerms.deserialize(buffer);
            AggregatePermTextures.deserialize(buffer);
            AggregatePermTexturesOwner.deserialize(buffer);
            Category.deserialize(buffer);
            InventorySerial.deserialize(buffer);
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            FromTaskID.deserialize(buffer);
            LastOwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            TouchName.deserialize(buffer);
            SitName.deserialize(buffer);
            TextureID.deserialize(buffer);
        }
    };
    // ObjectPropertiesPacket Member List
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectPropertiesPacket() {
        this->setID(ObjectProperties_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPropertiesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPropertiesPacket();
    }
};

// ObjectPropertiesFamilyPacket
class ObjectPropertiesFamilyPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 RequestFlags;
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableS32 OwnershipCost;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableU32 Category;
        SerializableUUID LastOwnerID;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestFlags.serialize(buffer);
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            OwnershipCost.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Category.serialize(buffer);
            LastOwnerID.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestFlags.deserialize(buffer);
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            OwnershipCost.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Category.deserialize(buffer);
            LastOwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // ObjectPropertiesFamilyPacket Member List
    ObjectDataBlock ObjectData;

public:
    ObjectPropertiesFamilyPacket() {
        this->setID(ObjectPropertiesFamily_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ObjectPropertiesFamilyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectPropertiesFamilyPacket();
    }
};

// RequestPayPricePacket
class RequestPayPricePacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
        }
    };
    // RequestPayPricePacket Member List
    ObjectDataBlock ObjectData;

public:
    RequestPayPricePacket() {
        this->setID(RequestPayPrice_ID);
    };
    virtual ~RequestPayPricePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestPayPricePacket();
    }
};

// PayPriceReplyPacket
class PayPriceReplyPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ObjectID;
        SerializableS32 DefaultPayPrice;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            DefaultPayPrice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            DefaultPayPrice.deserialize(buffer);
        }
    };
    class ButtonDataBlock : public PacketSerializable {
    public:
        // ButtonDataBlock Member List
        SerializableS32 PayButton;
    public:
        ButtonDataBlock() {};
        virtual ~ButtonDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PayButton.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PayButton.deserialize(buffer);
        }
    };
    // PayPriceReplyPacket Member List
    ObjectDataBlock ObjectData;
    VariableSerializable<ButtonDataBlock> ButtonData;

public:
    PayPriceReplyPacket() {
        this->setID(PayPriceReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~PayPriceReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
        ButtonData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
        ButtonData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PayPriceReplyPacket();
    }
};

// KickUserPacket
class KickUserPacket : public PacketBase {
public:

    // Block Class List
    class TargetBlockBlock : public PacketSerializable {
    public:
        // TargetBlockBlock Member List
        SerializableIPADDR TargetIP;
        SerializableIPPORT TargetPort;
    public:
        TargetBlockBlock() {};
        virtual ~TargetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetIP.serialize(buffer);
            TargetPort.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetIP.deserialize(buffer);
            TargetPort.deserialize(buffer);
        }
    };
    class UserInfoBlock : public PacketSerializable {
    public:
        // UserInfoBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableVariable2 Reason;
    public:
        UserInfoBlock() {};
        virtual ~UserInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Reason.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Reason.deserialize(buffer);
        }
    };
    // KickUserPacket Member List
    TargetBlockBlock TargetBlock;
    UserInfoBlock UserInfo;

public:
    KickUserPacket() {
        this->setID(KickUser_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~KickUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TargetBlock.serialize(buffer);
        UserInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TargetBlock.deserialize(buffer);
        UserInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new KickUserPacket();
    }
};

// KickUserAckPacket
class KickUserAckPacket : public PacketBase {
public:

    // Block Class List
    class UserInfoBlock : public PacketSerializable {
    public:
        // UserInfoBlock Member List
        SerializableUUID SessionID;
        SerializableU32 Flags;
    public:
        UserInfoBlock() {};
        virtual ~UserInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // KickUserAckPacket Member List
    UserInfoBlock UserInfo;

public:
    KickUserAckPacket() {
        this->setID(KickUserAck_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~KickUserAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UserInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UserInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new KickUserAckPacket();
    }
};

// GodKickUserPacket
class GodKickUserPacket : public PacketBase {
public:

    // Block Class List
    class UserInfoBlock : public PacketSerializable {
    public:
        // UserInfoBlock Member List
        SerializableUUID GodID;
        SerializableUUID GodSessionID;
        SerializableUUID AgentID;
        SerializableU32 KickFlags;
        SerializableVariable2 Reason;
    public:
        UserInfoBlock() {};
        virtual ~UserInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GodID.serialize(buffer);
            GodSessionID.serialize(buffer);
            AgentID.serialize(buffer);
            KickFlags.serialize(buffer);
            Reason.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GodID.deserialize(buffer);
            GodSessionID.deserialize(buffer);
            AgentID.deserialize(buffer);
            KickFlags.deserialize(buffer);
            Reason.deserialize(buffer);
        }
    };
    // GodKickUserPacket Member List
    UserInfoBlock UserInfo;

public:
    GodKickUserPacket() {
        this->setID(GodKickUser_ID);
    };
    virtual ~GodKickUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UserInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UserInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodKickUserPacket();
    }
};

// SystemKickUserPacket
class SystemKickUserPacket : public PacketBase {
public:

    // Block Class List
    class AgentInfoBlock : public PacketSerializable {
    public:
        // AgentInfoBlock Member List
        SerializableUUID AgentID;
    public:
        AgentInfoBlock() {};
        virtual ~AgentInfoBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // SystemKickUserPacket Member List
    VariableSerializable<AgentInfoBlock> AgentInfo;

public:
    SystemKickUserPacket() {
        this->setID(SystemKickUser_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SystemKickUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentInfo.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentInfo.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SystemKickUserPacket();
    }
};

// EjectUserPacket
class EjectUserPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // EjectUserPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    EjectUserPacket() {
        this->setID(EjectUser_ID);
    };
    virtual ~EjectUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EjectUserPacket();
    }
};

// FreezeUserPacket
class FreezeUserPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableU32 Flags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // FreezeUserPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    FreezeUserPacket() {
        this->setID(FreezeUser_ID);
    };
    virtual ~FreezeUserPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FreezeUserPacket();
    }
};

// AvatarPropertiesRequestPacket
class AvatarPropertiesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID AvatarID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AvatarID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AvatarID.deserialize(buffer);
        }
    };
    // AvatarPropertiesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AvatarPropertiesRequestPacket() {
        this->setID(AvatarPropertiesRequest_ID);
    };
    virtual ~AvatarPropertiesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesRequestPacket();
    }
};

// AvatarPropertiesRequestBackendPacket
class AvatarPropertiesRequestBackendPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID AvatarID;
        SerializableU8 GodLevel;
        SerializableBool WebProfilesDisabled;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            AvatarID.serialize(buffer);
            GodLevel.serialize(buffer);
            WebProfilesDisabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            AvatarID.deserialize(buffer);
            GodLevel.deserialize(buffer);
            WebProfilesDisabled.deserialize(buffer);
        }
    };
    // AvatarPropertiesRequestBackendPacket Member List
    AgentDataBlock AgentData;

public:
    AvatarPropertiesRequestBackendPacket() {
        this->setID(AvatarPropertiesRequestBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarPropertiesRequestBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesRequestBackendPacket();
    }
};

// AvatarPropertiesReplyPacket
class AvatarPropertiesReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID AvatarID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            AvatarID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            AvatarID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableUUID ImageID;
        SerializableUUID FLImageID;
        SerializableUUID PartnerID;
        SerializableVariable2 AboutText;
        SerializableVariable1 FLAboutText;
        SerializableVariable1 BornOn;
        SerializableVariable1 ProfileURL;
        SerializableVariable1 CharterMember;
        SerializableU32 Flags;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ImageID.serialize(buffer);
            FLImageID.serialize(buffer);
            PartnerID.serialize(buffer);
            AboutText.serialize(buffer);
            FLAboutText.serialize(buffer);
            BornOn.serialize(buffer);
            ProfileURL.serialize(buffer);
            CharterMember.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ImageID.deserialize(buffer);
            FLImageID.deserialize(buffer);
            PartnerID.deserialize(buffer);
            AboutText.deserialize(buffer);
            FLAboutText.deserialize(buffer);
            BornOn.deserialize(buffer);
            ProfileURL.deserialize(buffer);
            CharterMember.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // AvatarPropertiesReplyPacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarPropertiesReplyPacket() {
        this->setID(AvatarPropertiesReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarPropertiesReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesReplyPacket();
    }
};

// AvatarInterestsReplyPacket
class AvatarInterestsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID AvatarID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            AvatarID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            AvatarID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableU32 WantToMask;
        SerializableVariable1 WantToText;
        SerializableU32 SkillsMask;
        SerializableVariable1 SkillsText;
        SerializableVariable1 LanguagesText;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            WantToMask.serialize(buffer);
            WantToText.serialize(buffer);
            SkillsMask.serialize(buffer);
            SkillsText.serialize(buffer);
            LanguagesText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            WantToMask.deserialize(buffer);
            WantToText.deserialize(buffer);
            SkillsMask.deserialize(buffer);
            SkillsText.deserialize(buffer);
            LanguagesText.deserialize(buffer);
        }
    };
    // AvatarInterestsReplyPacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarInterestsReplyPacket() {
        this->setID(AvatarInterestsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarInterestsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarInterestsReplyPacket();
    }
};

// AvatarGroupsReplyPacket
class AvatarGroupsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID AvatarID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            AvatarID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            AvatarID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableU64 GroupPowers;
        SerializableBool AcceptNotices;
        SerializableVariable1 GroupTitle;
        SerializableUUID GroupID;
        SerializableVariable1 GroupName;
        SerializableUUID GroupInsigniaID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupPowers.serialize(buffer);
            AcceptNotices.serialize(buffer);
            GroupTitle.serialize(buffer);
            GroupID.serialize(buffer);
            GroupName.serialize(buffer);
            GroupInsigniaID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupPowers.deserialize(buffer);
            AcceptNotices.deserialize(buffer);
            GroupTitle.deserialize(buffer);
            GroupID.deserialize(buffer);
            GroupName.deserialize(buffer);
            GroupInsigniaID.deserialize(buffer);
        }
    };
    class NewGroupDataBlock : public PacketSerializable {
    public:
        // NewGroupDataBlock Member List
        SerializableBool ListInProfile;
    public:
        NewGroupDataBlock() {};
        virtual ~NewGroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ListInProfile.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ListInProfile.deserialize(buffer);
        }
    };
    // AvatarGroupsReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<GroupDataBlock> GroupData;
    NewGroupDataBlock NewGroupData;

public:
    AvatarGroupsReplyPacket() {
        this->setID(AvatarGroupsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarGroupsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        NewGroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        NewGroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarGroupsReplyPacket();
    }
};

// AvatarPropertiesUpdatePacket
class AvatarPropertiesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableUUID ImageID;
        SerializableUUID FLImageID;
        SerializableVariable2 AboutText;
        SerializableVariable1 FLAboutText;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
        SerializableVariable1 ProfileURL;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ImageID.serialize(buffer);
            FLImageID.serialize(buffer);
            AboutText.serialize(buffer);
            FLAboutText.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
            ProfileURL.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ImageID.deserialize(buffer);
            FLImageID.deserialize(buffer);
            AboutText.deserialize(buffer);
            FLAboutText.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
            ProfileURL.deserialize(buffer);
        }
    };
    // AvatarPropertiesUpdatePacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarPropertiesUpdatePacket() {
        this->setID(AvatarPropertiesUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarPropertiesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPropertiesUpdatePacket();
    }
};

// AvatarInterestsUpdatePacket
class AvatarInterestsUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class PropertiesDataBlock : public PacketSerializable {
    public:
        // PropertiesDataBlock Member List
        SerializableU32 WantToMask;
        SerializableVariable1 WantToText;
        SerializableU32 SkillsMask;
        SerializableVariable1 SkillsText;
        SerializableVariable1 LanguagesText;
    public:
        PropertiesDataBlock() {};
        virtual ~PropertiesDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            WantToMask.serialize(buffer);
            WantToText.serialize(buffer);
            SkillsMask.serialize(buffer);
            SkillsText.serialize(buffer);
            LanguagesText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            WantToMask.deserialize(buffer);
            WantToText.deserialize(buffer);
            SkillsMask.deserialize(buffer);
            SkillsText.deserialize(buffer);
            LanguagesText.deserialize(buffer);
        }
    };
    // AvatarInterestsUpdatePacket Member List
    AgentDataBlock AgentData;
    PropertiesDataBlock PropertiesData;

public:
    AvatarInterestsUpdatePacket() {
        this->setID(AvatarInterestsUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AvatarInterestsUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PropertiesData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PropertiesData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarInterestsUpdatePacket();
    }
};

// AvatarNotesReplyPacket
class AvatarNotesReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableVariable2 Notes;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Notes.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Notes.deserialize(buffer);
        }
    };
    // AvatarNotesReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarNotesReplyPacket() {
        this->setID(AvatarNotesReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarNotesReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarNotesReplyPacket();
    }
};

// AvatarNotesUpdatePacket
class AvatarNotesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TargetID;
        SerializableVariable2 Notes;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetID.serialize(buffer);
            Notes.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetID.deserialize(buffer);
            Notes.deserialize(buffer);
        }
    };
    // AvatarNotesUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    AvatarNotesUpdatePacket() {
        this->setID(AvatarNotesUpdate_ID);
    };
    virtual ~AvatarNotesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarNotesUpdatePacket();
    }
};

// AvatarPicksReplyPacket
class AvatarPicksReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID TargetID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TargetID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TargetID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableVariable1 PickName;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            PickName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            PickName.deserialize(buffer);
        }
    };
    // AvatarPicksReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    AvatarPicksReplyPacket() {
        this->setID(AvatarPicksReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AvatarPicksReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AvatarPicksReplyPacket();
    }
};

// EventInfoRequestPacket
class EventInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventInfoRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventInfoRequestPacket() {
        this->setID(EventInfoRequest_ID);
    };
    virtual ~EventInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventInfoRequestPacket();
    }
};

// EventInfoReplyPacket
class EventInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
        SerializableVariable1 Creator;
        SerializableVariable1 Name;
        SerializableVariable1 Category;
        SerializableVariable2 Desc;
        SerializableVariable1 Date;
        SerializableU32 DateUTC;
        SerializableU32 Duration;
        SerializableU32 Cover;
        SerializableU32 Amount;
        SerializableVariable1 SimName;
        SerializableVector3d GlobalPos;
        SerializableU32 EventFlags;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
            Creator.serialize(buffer);
            Name.serialize(buffer);
            Category.serialize(buffer);
            Desc.serialize(buffer);
            Date.serialize(buffer);
            DateUTC.serialize(buffer);
            Duration.serialize(buffer);
            Cover.serialize(buffer);
            Amount.serialize(buffer);
            SimName.serialize(buffer);
            GlobalPos.serialize(buffer);
            EventFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
            Creator.deserialize(buffer);
            Name.deserialize(buffer);
            Category.deserialize(buffer);
            Desc.deserialize(buffer);
            Date.deserialize(buffer);
            DateUTC.deserialize(buffer);
            Duration.deserialize(buffer);
            Cover.deserialize(buffer);
            Amount.deserialize(buffer);
            SimName.deserialize(buffer);
            GlobalPos.deserialize(buffer);
            EventFlags.deserialize(buffer);
        }
    };
    // EventInfoReplyPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventInfoReplyPacket() {
        this->setID(EventInfoReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EventInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventInfoReplyPacket();
    }
};

// EventNotificationAddRequestPacket
class EventNotificationAddRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventNotificationAddRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventNotificationAddRequestPacket() {
        this->setID(EventNotificationAddRequest_ID);
    };
    virtual ~EventNotificationAddRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventNotificationAddRequestPacket();
    }
};

// EventNotificationRemoveRequestPacket
class EventNotificationRemoveRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventNotificationRemoveRequestPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;

public:
    EventNotificationRemoveRequestPacket() {
        this->setID(EventNotificationRemoveRequest_ID);
    };
    virtual ~EventNotificationRemoveRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventNotificationRemoveRequestPacket();
    }
};

// EventGodDeletePacket
class EventGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableVariable1 QueryText;
        SerializableU32 QueryFlags;
        SerializableS32 QueryStart;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            QueryText.serialize(buffer);
            QueryFlags.serialize(buffer);
            QueryStart.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            QueryText.deserialize(buffer);
            QueryFlags.deserialize(buffer);
            QueryStart.deserialize(buffer);
        }
    };
    // EventGodDeletePacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    QueryDataBlock QueryData;

public:
    EventGodDeletePacket() {
        this->setID(EventGodDelete_ID);
    };
    virtual ~EventGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventGodDeletePacket();
    }
};

// PickInfoReplyPacket
class PickInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableUUID CreatorID;
        SerializableBool TopPick;
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID SnapshotID;
        SerializableVariable1 User;
        SerializableVariable1 OriginalName;
        SerializableVariable1 SimName;
        SerializableVector3d PosGlobal;
        SerializableS32 SortOrder;
        SerializableBool Enabled;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            CreatorID.serialize(buffer);
            TopPick.serialize(buffer);
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            SnapshotID.serialize(buffer);
            User.serialize(buffer);
            OriginalName.serialize(buffer);
            SimName.serialize(buffer);
            PosGlobal.serialize(buffer);
            SortOrder.serialize(buffer);
            Enabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            TopPick.deserialize(buffer);
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            User.deserialize(buffer);
            OriginalName.deserialize(buffer);
            SimName.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            SortOrder.deserialize(buffer);
            Enabled.deserialize(buffer);
        }
    };
    // PickInfoReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickInfoReplyPacket() {
        this->setID(PickInfoReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~PickInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickInfoReplyPacket();
    }
};

// PickInfoUpdatePacket
class PickInfoUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableUUID CreatorID;
        SerializableBool TopPick;
        SerializableUUID ParcelID;
        SerializableVariable1 Name;
        SerializableVariable2 Desc;
        SerializableUUID SnapshotID;
        SerializableVector3d PosGlobal;
        SerializableS32 SortOrder;
        SerializableBool Enabled;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            CreatorID.serialize(buffer);
            TopPick.serialize(buffer);
            ParcelID.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            SnapshotID.serialize(buffer);
            PosGlobal.serialize(buffer);
            SortOrder.serialize(buffer);
            Enabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            TopPick.deserialize(buffer);
            ParcelID.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            SortOrder.deserialize(buffer);
            Enabled.deserialize(buffer);
        }
    };
    // PickInfoUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickInfoUpdatePacket() {
        this->setID(PickInfoUpdate_ID);
    };
    virtual ~PickInfoUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickInfoUpdatePacket();
    }
};

// PickDeletePacket
class PickDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
        }
    };
    // PickDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickDeletePacket() {
        this->setID(PickDelete_ID);
    };
    virtual ~PickDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickDeletePacket();
    }
};

// PickGodDeletePacket
class PickGodDeletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID PickID;
        SerializableUUID QueryID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            PickID.serialize(buffer);
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            PickID.deserialize(buffer);
            QueryID.deserialize(buffer);
        }
    };
    // PickGodDeletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    PickGodDeletePacket() {
        this->setID(PickGodDelete_ID);
    };
    virtual ~PickGodDeletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PickGodDeletePacket();
    }
};

// ScriptQuestionPacket
class ScriptQuestionPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableVariable1 ObjectName;
        SerializableVariable1 ObjectOwner;
        SerializableS32 Questions;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ObjectName.serialize(buffer);
            ObjectOwner.serialize(buffer);
            Questions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ObjectName.deserialize(buffer);
            ObjectOwner.deserialize(buffer);
            Questions.deserialize(buffer);
        }
    };
    // ScriptQuestionPacket Member List
    DataBlock Data;

public:
    ScriptQuestionPacket() {
        this->setID(ScriptQuestion_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptQuestionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptQuestionPacket();
    }
};

// ScriptControlChangePacket
class ScriptControlChangePacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableBool TakeControls;
        SerializableU32 Controls;
        SerializableBool PassToAgent;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TakeControls.serialize(buffer);
            Controls.serialize(buffer);
            PassToAgent.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TakeControls.deserialize(buffer);
            Controls.deserialize(buffer);
            PassToAgent.deserialize(buffer);
        }
    };
    // ScriptControlChangePacket Member List
    VariableSerializable<DataBlock> Data;

public:
    ScriptControlChangePacket() {
        this->setID(ScriptControlChange_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptControlChangePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptControlChangePacket();
    }
};

// ScriptDialogPacket
class ScriptDialogPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableVariable1 FirstName;
        SerializableVariable1 LastName;
        SerializableVariable1 ObjectName;
        SerializableVariable2 Message;
        SerializableS32 ChatChannel;
        SerializableUUID ImageID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            FirstName.serialize(buffer);
            LastName.serialize(buffer);
            ObjectName.serialize(buffer);
            Message.serialize(buffer);
            ChatChannel.serialize(buffer);
            ImageID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            FirstName.deserialize(buffer);
            LastName.deserialize(buffer);
            ObjectName.deserialize(buffer);
            Message.deserialize(buffer);
            ChatChannel.deserialize(buffer);
            ImageID.deserialize(buffer);
        }
    };
    class ButtonsBlock : public PacketSerializable {
    public:
        // ButtonsBlock Member List
        SerializableVariable1 ButtonLabel;
    public:
        ButtonsBlock() {};
        virtual ~ButtonsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ButtonLabel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ButtonLabel.deserialize(buffer);
        }
    };
    // ScriptDialogPacket Member List
    DataBlock Data;
    VariableSerializable<ButtonsBlock> Buttons;

public:
    ScriptDialogPacket() {
        this->setID(ScriptDialog_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ScriptDialogPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
        Buttons.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
        Buttons.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptDialogPacket();
    }
};

// ScriptDialogReplyPacket
class ScriptDialogReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableS32 ChatChannel;
        SerializableS32 ButtonIndex;
        SerializableVariable1 ButtonLabel;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ChatChannel.serialize(buffer);
            ButtonIndex.serialize(buffer);
            ButtonLabel.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ChatChannel.deserialize(buffer);
            ButtonIndex.deserialize(buffer);
            ButtonLabel.deserialize(buffer);
        }
    };
    // ScriptDialogReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ScriptDialogReplyPacket() {
        this->setID(ScriptDialogReply_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ScriptDialogReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptDialogReplyPacket();
    }
};

// ForceScriptControlReleasePacket
class ForceScriptControlReleasePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ForceScriptControlReleasePacket Member List
    AgentDataBlock AgentData;

public:
    ForceScriptControlReleasePacket() {
        this->setID(ForceScriptControlRelease_ID);
    };
    virtual ~ForceScriptControlReleasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ForceScriptControlReleasePacket();
    }
};

// RevokePermissionsPacket
class RevokePermissionsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ObjectID;
        SerializableU32 ObjectPermissions;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ObjectPermissions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ObjectPermissions.deserialize(buffer);
        }
    };
    // RevokePermissionsPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    RevokePermissionsPacket() {
        this->setID(RevokePermissions_ID);
    };
    virtual ~RevokePermissionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RevokePermissionsPacket();
    }
};

// LoadURLPacket
class LoadURLPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVariable1 ObjectName;
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableBool OwnerIsGroup;
        SerializableVariable1 Message;
        SerializableVariable1 URL;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectName.serialize(buffer);
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            OwnerIsGroup.serialize(buffer);
            Message.serialize(buffer);
            URL.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectName.deserialize(buffer);
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            OwnerIsGroup.deserialize(buffer);
            Message.deserialize(buffer);
            URL.deserialize(buffer);
        }
    };
    // LoadURLPacket Member List
    DataBlock Data;

public:
    LoadURLPacket() {
        this->setID(LoadURL_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LoadURLPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LoadURLPacket();
    }
};

// ScriptTeleportRequestPacket
class ScriptTeleportRequestPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVariable1 ObjectName;
        SerializableVariable1 SimName;
        SerializableVector3 SimPosition;
        SerializableVector3 LookAt;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectName.serialize(buffer);
            SimName.serialize(buffer);
            SimPosition.serialize(buffer);
            LookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectName.deserialize(buffer);
            SimName.deserialize(buffer);
            SimPosition.deserialize(buffer);
            LookAt.deserialize(buffer);
        }
    };
    // ScriptTeleportRequestPacket Member List
    DataBlock Data;

public:
    ScriptTeleportRequestPacket() {
        this->setID(ScriptTeleportRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptTeleportRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptTeleportRequestPacket();
    }
};

// ParcelOverlayPacket
class ParcelOverlayPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 SequenceID;
        SerializableVariable2 Data;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // ParcelOverlayPacket Member List
    ParcelDataBlock ParcelData;

public:
    ParcelOverlayPacket() {
        this->setID(ParcelOverlay_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelOverlayPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelOverlayPacket();
    }
};

// ParcelPropertiesRequestPacket
class ParcelPropertiesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 SequenceID;
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
        SerializableBool SnapSelection;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
            SnapSelection.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
            SnapSelection.deserialize(buffer);
        }
    };
    // ParcelPropertiesRequestPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesRequestPacket() {
        this->setID(ParcelPropertiesRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesRequestPacket();
    }
};

// ParcelPropertiesRequestByIDPacket
class ParcelPropertiesRequestByIDPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 SequenceID;
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelPropertiesRequestByIDPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesRequestByIDPacket() {
        this->setID(ParcelPropertiesRequestByID_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesRequestByIDPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesRequestByIDPacket();
    }
};

// ParcelPropertiesPacket
class ParcelPropertiesPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 RequestResult;
        SerializableS32 SequenceID;
        SerializableBool SnapSelection;
        SerializableS32 SelfCount;
        SerializableS32 OtherCount;
        SerializableS32 PublicCount;
        SerializableS32 LocalID;
        SerializableUUID OwnerID;
        SerializableBool IsGroupOwned;
        SerializableU32 AuctionID;
        SerializableS32 ClaimDate;
        SerializableS32 ClaimPrice;
        SerializableS32 RentPrice;
        SerializableVector3 AABBMin;
        SerializableVector3 AABBMax;
        SerializableVariable2 Bitmap;
        SerializableS32 Area;
        SerializableU8 Status;
        SerializableS32 SimWideMaxPrims;
        SerializableS32 SimWideTotalPrims;
        SerializableS32 MaxPrims;
        SerializableS32 TotalPrims;
        SerializableS32 OwnerPrims;
        SerializableS32 GroupPrims;
        SerializableS32 OtherPrims;
        SerializableS32 SelectedPrims;
        SerializableF32 ParcelPrimBonus;
        SerializableS32 OtherCleanTime;
        SerializableU32 ParcelFlags;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Desc;
        SerializableVariable1 MusicURL;
        SerializableVariable1 MediaURL;
        SerializableUUID MediaID;
        SerializableU8 MediaAutoScale;
        SerializableUUID GroupID;
        SerializableS32 PassPrice;
        SerializableF32 PassHours;
        SerializableU8 Category;
        SerializableUUID AuthBuyerID;
        SerializableUUID SnapshotID;
        SerializableVector3 UserLocation;
        SerializableVector3 UserLookAt;
        SerializableU8 LandingType;
        SerializableBool RegionPushOverride;
        SerializableBool RegionDenyAnonymous;
        SerializableBool RegionDenyIdentified;
        SerializableBool RegionDenyTransacted;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestResult.serialize(buffer);
            SequenceID.serialize(buffer);
            SnapSelection.serialize(buffer);
            SelfCount.serialize(buffer);
            OtherCount.serialize(buffer);
            PublicCount.serialize(buffer);
            LocalID.serialize(buffer);
            OwnerID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            AuctionID.serialize(buffer);
            ClaimDate.serialize(buffer);
            ClaimPrice.serialize(buffer);
            RentPrice.serialize(buffer);
            AABBMin.serialize(buffer);
            AABBMax.serialize(buffer);
            Bitmap.serialize(buffer);
            Area.serialize(buffer);
            Status.serialize(buffer);
            SimWideMaxPrims.serialize(buffer);
            SimWideTotalPrims.serialize(buffer);
            MaxPrims.serialize(buffer);
            TotalPrims.serialize(buffer);
            OwnerPrims.serialize(buffer);
            GroupPrims.serialize(buffer);
            OtherPrims.serialize(buffer);
            SelectedPrims.serialize(buffer);
            ParcelPrimBonus.serialize(buffer);
            OtherCleanTime.serialize(buffer);
            ParcelFlags.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            MusicURL.serialize(buffer);
            MediaURL.serialize(buffer);
            MediaID.serialize(buffer);
            MediaAutoScale.serialize(buffer);
            GroupID.serialize(buffer);
            PassPrice.serialize(buffer);
            PassHours.serialize(buffer);
            Category.serialize(buffer);
            AuthBuyerID.serialize(buffer);
            SnapshotID.serialize(buffer);
            UserLocation.serialize(buffer);
            UserLookAt.serialize(buffer);
            LandingType.serialize(buffer);
            RegionPushOverride.serialize(buffer);
            RegionDenyAnonymous.serialize(buffer);
            RegionDenyIdentified.serialize(buffer);
            RegionDenyTransacted.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestResult.deserialize(buffer);
            SequenceID.deserialize(buffer);
            SnapSelection.deserialize(buffer);
            SelfCount.deserialize(buffer);
            OtherCount.deserialize(buffer);
            PublicCount.deserialize(buffer);
            LocalID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            AuctionID.deserialize(buffer);
            ClaimDate.deserialize(buffer);
            ClaimPrice.deserialize(buffer);
            RentPrice.deserialize(buffer);
            AABBMin.deserialize(buffer);
            AABBMax.deserialize(buffer);
            Bitmap.deserialize(buffer);
            Area.deserialize(buffer);
            Status.deserialize(buffer);
            SimWideMaxPrims.deserialize(buffer);
            SimWideTotalPrims.deserialize(buffer);
            MaxPrims.deserialize(buffer);
            TotalPrims.deserialize(buffer);
            OwnerPrims.deserialize(buffer);
            GroupPrims.deserialize(buffer);
            OtherPrims.deserialize(buffer);
            SelectedPrims.deserialize(buffer);
            ParcelPrimBonus.deserialize(buffer);
            OtherCleanTime.deserialize(buffer);
            ParcelFlags.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            MusicURL.deserialize(buffer);
            MediaURL.deserialize(buffer);
            MediaID.deserialize(buffer);
            MediaAutoScale.deserialize(buffer);
            GroupID.deserialize(buffer);
            PassPrice.deserialize(buffer);
            PassHours.deserialize(buffer);
            Category.deserialize(buffer);
            AuthBuyerID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            UserLocation.deserialize(buffer);
            UserLookAt.deserialize(buffer);
            LandingType.deserialize(buffer);
            RegionPushOverride.deserialize(buffer);
            RegionDenyAnonymous.deserialize(buffer);
            RegionDenyIdentified.deserialize(buffer);
            RegionDenyTransacted.deserialize(buffer);
        }
    };
    class AgeVerificationBlockBlock : public PacketSerializable {
    public:
        // AgeVerificationBlockBlock Member List
        SerializableBool RegionDenyAgeUnverified;
    public:
        AgeVerificationBlockBlock() {};
        virtual ~AgeVerificationBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionDenyAgeUnverified.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionDenyAgeUnverified.deserialize(buffer);
        }
    };
    // ParcelPropertiesPacket Member List
    ParcelDataBlock ParcelData;
    AgeVerificationBlockBlock AgeVerificationBlock;

public:
    ParcelPropertiesPacket() {
        this->setID(ParcelProperties_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
        AgeVerificationBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
        AgeVerificationBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesPacket();
    }
};

// ParcelPropertiesUpdatePacket
class ParcelPropertiesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 Flags;
        SerializableU32 ParcelFlags;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Desc;
        SerializableVariable1 MusicURL;
        SerializableVariable1 MediaURL;
        SerializableUUID MediaID;
        SerializableU8 MediaAutoScale;
        SerializableUUID GroupID;
        SerializableS32 PassPrice;
        SerializableF32 PassHours;
        SerializableU8 Category;
        SerializableUUID AuthBuyerID;
        SerializableUUID SnapshotID;
        SerializableVector3 UserLocation;
        SerializableVector3 UserLookAt;
        SerializableU8 LandingType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Flags.serialize(buffer);
            ParcelFlags.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Desc.serialize(buffer);
            MusicURL.serialize(buffer);
            MediaURL.serialize(buffer);
            MediaID.serialize(buffer);
            MediaAutoScale.serialize(buffer);
            GroupID.serialize(buffer);
            PassPrice.serialize(buffer);
            PassHours.serialize(buffer);
            Category.serialize(buffer);
            AuthBuyerID.serialize(buffer);
            SnapshotID.serialize(buffer);
            UserLocation.serialize(buffer);
            UserLookAt.serialize(buffer);
            LandingType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Flags.deserialize(buffer);
            ParcelFlags.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Desc.deserialize(buffer);
            MusicURL.deserialize(buffer);
            MediaURL.deserialize(buffer);
            MediaID.deserialize(buffer);
            MediaAutoScale.deserialize(buffer);
            GroupID.deserialize(buffer);
            PassPrice.deserialize(buffer);
            PassHours.deserialize(buffer);
            Category.deserialize(buffer);
            AuthBuyerID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            UserLocation.deserialize(buffer);
            UserLookAt.deserialize(buffer);
            LandingType.deserialize(buffer);
        }
    };
    // ParcelPropertiesUpdatePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelPropertiesUpdatePacket() {
        this->setID(ParcelPropertiesUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelPropertiesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelPropertiesUpdatePacket();
    }
};

// ParcelReturnObjectsPacket
class ParcelReturnObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class TaskIDsBlock : public PacketSerializable {
    public:
        // TaskIDsBlock Member List
        SerializableUUID TaskID;
    public:
        TaskIDsBlock() {};
        virtual ~TaskIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
        }
    };
    class OwnerIDsBlock : public PacketSerializable {
    public:
        // OwnerIDsBlock Member List
        SerializableUUID OwnerID;
    public:
        OwnerIDsBlock() {};
        virtual ~OwnerIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
        }
    };
    // ParcelReturnObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<TaskIDsBlock> TaskIDs;
    VariableSerializable<OwnerIDsBlock> OwnerIDs;

public:
    ParcelReturnObjectsPacket() {
        this->setID(ParcelReturnObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelReturnObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        TaskIDs.serialize(buffer);
        OwnerIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        TaskIDs.deserialize(buffer);
        OwnerIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReturnObjectsPacket();
    }
};

// ParcelSetOtherCleanTimePacket
class ParcelSetOtherCleanTimePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableS32 OtherCleanTime;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            OtherCleanTime.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            OtherCleanTime.deserialize(buffer);
        }
    };
    // ParcelSetOtherCleanTimePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelSetOtherCleanTimePacket() {
        this->setID(ParcelSetOtherCleanTime_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelSetOtherCleanTimePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelSetOtherCleanTimePacket();
    }
};

// ParcelDisableObjectsPacket
class ParcelDisableObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class TaskIDsBlock : public PacketSerializable {
    public:
        // TaskIDsBlock Member List
        SerializableUUID TaskID;
    public:
        TaskIDsBlock() {};
        virtual ~TaskIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
        }
    };
    class OwnerIDsBlock : public PacketSerializable {
    public:
        // OwnerIDsBlock Member List
        SerializableUUID OwnerID;
    public:
        OwnerIDsBlock() {};
        virtual ~OwnerIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
        }
    };
    // ParcelDisableObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<TaskIDsBlock> TaskIDs;
    VariableSerializable<OwnerIDsBlock> OwnerIDs;

public:
    ParcelDisableObjectsPacket() {
        this->setID(ParcelDisableObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelDisableObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        TaskIDs.serialize(buffer);
        OwnerIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        TaskIDs.deserialize(buffer);
        OwnerIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDisableObjectsPacket();
    }
};

// ParcelSelectObjectsPacket
class ParcelSelectObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableU32 ReturnType;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ReturnType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ReturnType.deserialize(buffer);
        }
    };
    class ReturnIDsBlock : public PacketSerializable {
    public:
        // ReturnIDsBlock Member List
        SerializableUUID ReturnID;
    public:
        ReturnIDsBlock() {};
        virtual ~ReturnIDsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReturnID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReturnID.deserialize(buffer);
        }
    };
    // ParcelSelectObjectsPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;
    VariableSerializable<ReturnIDsBlock> ReturnIDs;

public:
    ParcelSelectObjectsPacket() {
        this->setID(ParcelSelectObjects_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelSelectObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
        ReturnIDs.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
        ReturnIDs.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelSelectObjectsPacket();
    }
};

// EstateCovenantRequestPacket
class EstateCovenantRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // EstateCovenantRequestPacket Member List
    AgentDataBlock AgentData;

public:
    EstateCovenantRequestPacket() {
        this->setID(EstateCovenantRequest_ID);
    };
    virtual ~EstateCovenantRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EstateCovenantRequestPacket();
    }
};

// EstateCovenantReplyPacket
class EstateCovenantReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID CovenantID;
        SerializableU32 CovenantTimestamp;
        SerializableVariable1 EstateName;
        SerializableUUID EstateOwnerID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CovenantID.serialize(buffer);
            CovenantTimestamp.serialize(buffer);
            EstateName.serialize(buffer);
            EstateOwnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CovenantID.deserialize(buffer);
            CovenantTimestamp.deserialize(buffer);
            EstateName.deserialize(buffer);
            EstateOwnerID.deserialize(buffer);
        }
    };
    // EstateCovenantReplyPacket Member List
    DataBlock Data;

public:
    EstateCovenantReplyPacket() {
        this->setID(EstateCovenantReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EstateCovenantReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EstateCovenantReplyPacket();
    }
};

// ForceObjectSelectPacket
class ForceObjectSelectPacket : public PacketBase {
public:

    // Block Class List
    class HeaderBlock : public PacketSerializable {
    public:
        // HeaderBlock Member List
        SerializableBool ResetList;
    public:
        HeaderBlock() {};
        virtual ~HeaderBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ResetList.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ResetList.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ForceObjectSelectPacket Member List
    HeaderBlock Header;
    VariableSerializable<DataBlock> Data;

public:
    ForceObjectSelectPacket() {
        this->setID(ForceObjectSelect_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ForceObjectSelectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Header.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Header.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ForceObjectSelectPacket();
    }
};

// ParcelBuyPassPacket
class ParcelBuyPassPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelBuyPassPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelBuyPassPacket() {
        this->setID(ParcelBuyPass_ID);
    };
    virtual ~ParcelBuyPassPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelBuyPassPacket();
    }
};

// ParcelDeedToGroupPacket
class ParcelDeedToGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelDeedToGroupPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelDeedToGroupPacket() {
        this->setID(ParcelDeedToGroup_ID);
    };
    virtual ~ParcelDeedToGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDeedToGroupPacket();
    }
};

// ParcelReclaimPacket
class ParcelReclaimPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelReclaimPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelReclaimPacket() {
        this->setID(ParcelReclaim_ID);
    };
    virtual ~ParcelReclaimPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReclaimPacket();
    }
};

// ParcelClaimPacket
class ParcelClaimPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool IsGroupOwned;
        SerializableBool Final;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            Final.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            Final.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelClaimPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    ParcelClaimPacket() {
        this->setID(ParcelClaim_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelClaimPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelClaimPacket();
    }
};

// ParcelJoinPacket
class ParcelJoinPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelJoinPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelJoinPacket() {
        this->setID(ParcelJoin_ID);
    };
    virtual ~ParcelJoinPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelJoinPacket();
    }
};

// ParcelDividePacket
class ParcelDividePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableF32 West;
        SerializableF32 South;
        SerializableF32 East;
        SerializableF32 North;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            West.serialize(buffer);
            South.serialize(buffer);
            East.serialize(buffer);
            North.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            West.deserialize(buffer);
            South.deserialize(buffer);
            East.deserialize(buffer);
            North.deserialize(buffer);
        }
    };
    // ParcelDividePacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelDividePacket() {
        this->setID(ParcelDivide_ID);
    };
    virtual ~ParcelDividePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDividePacket();
    }
};

// ParcelReleasePacket
class ParcelReleasePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelReleasePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelReleasePacket() {
        this->setID(ParcelRelease_ID);
    };
    virtual ~ParcelReleasePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelReleasePacket();
    }
};

// ParcelBuyPacket
class ParcelBuyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool IsGroupOwned;
        SerializableBool RemoveContribution;
        SerializableS32 LocalID;
        SerializableBool Final;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            IsGroupOwned.serialize(buffer);
            RemoveContribution.serialize(buffer);
            LocalID.serialize(buffer);
            Final.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            IsGroupOwned.deserialize(buffer);
            RemoveContribution.deserialize(buffer);
            LocalID.deserialize(buffer);
            Final.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 Price;
        SerializableS32 Area;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Price.serialize(buffer);
            Area.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Price.deserialize(buffer);
            Area.deserialize(buffer);
        }
    };
    // ParcelBuyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    ParcelDataBlock ParcelData;

public:
    ParcelBuyPacket() {
        this->setID(ParcelBuy_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelBuyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelBuyPacket();
    }
};

// ParcelGodForceOwnerPacket
class ParcelGodForceOwnerPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID OwnerID;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelGodForceOwnerPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelGodForceOwnerPacket() {
        this->setID(ParcelGodForceOwner_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelGodForceOwnerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelGodForceOwnerPacket();
    }
};

// ParcelAccessListRequestPacket
class ParcelAccessListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 SequenceID;
        SerializableU32 Flags;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SequenceID.serialize(buffer);
            Flags.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SequenceID.deserialize(buffer);
            Flags.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    // ParcelAccessListRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelAccessListRequestPacket() {
        this->setID(ParcelAccessListRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelAccessListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAccessListRequestPacket();
    }
};

// ParcelAccessListReplyPacket
class ParcelAccessListReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID AgentID;
        SerializableS32 SequenceID;
        SerializableU32 Flags;
        SerializableS32 LocalID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SequenceID.serialize(buffer);
            Flags.serialize(buffer);
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SequenceID.deserialize(buffer);
            Flags.deserialize(buffer);
            LocalID.deserialize(buffer);
        }
    };
    class ListBlock : public PacketSerializable {
    public:
        // ListBlock Member List
        SerializableUUID ID;
        SerializableS32 Time;
        SerializableU32 Flags;
    public:
        ListBlock() {};
        virtual ~ListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Time.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Time.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ParcelAccessListReplyPacket Member List
    DataBlock Data;
    VariableSerializable<ListBlock> List;

public:
    ParcelAccessListReplyPacket() {
        this->setID(ParcelAccessListReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelAccessListReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
        List.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
        List.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAccessListReplyPacket();
    }
};

// ParcelAccessListUpdatePacket
class ParcelAccessListUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 Flags;
        SerializableS32 LocalID;
        SerializableUUID TransactionID;
        SerializableS32 SequenceID;
        SerializableS32 Sections;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
            LocalID.serialize(buffer);
            TransactionID.serialize(buffer);
            SequenceID.serialize(buffer);
            Sections.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
            LocalID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            SequenceID.deserialize(buffer);
            Sections.deserialize(buffer);
        }
    };
    class ListBlock : public PacketSerializable {
    public:
        // ListBlock Member List
        SerializableUUID ID;
        SerializableS32 Time;
        SerializableU32 Flags;
    public:
        ListBlock() {};
        virtual ~ListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            Time.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            Time.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ParcelAccessListUpdatePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    VariableSerializable<ListBlock> List;

public:
    ParcelAccessListUpdatePacket() {
        this->setID(ParcelAccessListUpdate_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ParcelAccessListUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        List.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        List.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAccessListUpdatePacket();
    }
};

// ParcelDwellRequestPacket
class ParcelDwellRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
        SerializableUUID ParcelID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ParcelID.deserialize(buffer);
        }
    };
    // ParcelDwellRequestPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelDwellRequestPacket() {
        this->setID(ParcelDwellRequest_ID);
    };
    virtual ~ParcelDwellRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDwellRequestPacket();
    }
};

// ParcelDwellReplyPacket
class ParcelDwellReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 LocalID;
        SerializableUUID ParcelID;
        SerializableF32 Dwell;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ParcelID.serialize(buffer);
            Dwell.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ParcelID.deserialize(buffer);
            Dwell.deserialize(buffer);
        }
    };
    // ParcelDwellReplyPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ParcelDwellReplyPacket() {
        this->setID(ParcelDwellReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelDwellReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelDwellReplyPacket();
    }
};

// RequestParcelTransferPacket
class RequestParcelTransferPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID TransactionID;
        SerializableU32 TransactionTime;
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableUUID OwnerID;
        SerializableU8 Flags;
        SerializableS32 TransactionType;
        SerializableS32 Amount;
        SerializableS32 BillableArea;
        SerializableS32 ActualArea;
        SerializableBool Final;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            TransactionTime.serialize(buffer);
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            OwnerID.serialize(buffer);
            Flags.serialize(buffer);
            TransactionType.serialize(buffer);
            Amount.serialize(buffer);
            BillableArea.serialize(buffer);
            ActualArea.serialize(buffer);
            Final.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            TransactionTime.deserialize(buffer);
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Flags.deserialize(buffer);
            TransactionType.deserialize(buffer);
            Amount.deserialize(buffer);
            BillableArea.deserialize(buffer);
            ActualArea.deserialize(buffer);
            Final.deserialize(buffer);
        }
    };
    // RequestParcelTransferPacket Member List
    DataBlock Data;

public:
    RequestParcelTransferPacket() {
        this->setID(RequestParcelTransfer_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RequestParcelTransferPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestParcelTransferPacket();
    }
};

// UpdateParcelPacket
class UpdateParcelPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableU64 RegionHandle;
        SerializableUUID OwnerID;
        SerializableBool GroupOwned;
        SerializableU8 Status;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableVariable1 MusicURL;
        SerializableF32 RegionX;
        SerializableF32 RegionY;
        SerializableS32 ActualArea;
        SerializableS32 BillableArea;
        SerializableBool ShowDir;
        SerializableBool IsForSale;
        SerializableU8 Category;
        SerializableUUID SnapshotID;
        SerializableVector3 UserLocation;
        SerializableS32 SalePrice;
        SerializableUUID AuthorizedBuyerID;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            RegionHandle.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupOwned.serialize(buffer);
            Status.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            MusicURL.serialize(buffer);
            RegionX.serialize(buffer);
            RegionY.serialize(buffer);
            ActualArea.serialize(buffer);
            BillableArea.serialize(buffer);
            ShowDir.serialize(buffer);
            IsForSale.serialize(buffer);
            Category.serialize(buffer);
            SnapshotID.serialize(buffer);
            UserLocation.serialize(buffer);
            SalePrice.serialize(buffer);
            AuthorizedBuyerID.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            Status.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            MusicURL.deserialize(buffer);
            RegionX.deserialize(buffer);
            RegionY.deserialize(buffer);
            ActualArea.deserialize(buffer);
            BillableArea.deserialize(buffer);
            ShowDir.deserialize(buffer);
            IsForSale.deserialize(buffer);
            Category.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            UserLocation.deserialize(buffer);
            SalePrice.deserialize(buffer);
            AuthorizedBuyerID.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // UpdateParcelPacket Member List
    ParcelDataBlock ParcelData;

public:
    UpdateParcelPacket() {
        this->setID(UpdateParcel_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateParcelPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateParcelPacket();
    }
};

// RemoveParcelPacket
class RemoveParcelPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
        }
    };
    // RemoveParcelPacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    RemoveParcelPacket() {
        this->setID(RemoveParcel_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RemoveParcelPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveParcelPacket();
    }
};

// MergeParcelPacket
class MergeParcelPacket : public PacketBase {
public:

    // Block Class List
    class MasterParcelDataBlock : public PacketSerializable {
    public:
        // MasterParcelDataBlock Member List
        SerializableUUID MasterID;
    public:
        MasterParcelDataBlock() {};
        virtual ~MasterParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MasterID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MasterID.deserialize(buffer);
        }
    };
    class SlaveParcelDataBlock : public PacketSerializable {
    public:
        // SlaveParcelDataBlock Member List
        SerializableUUID SlaveID;
    public:
        SlaveParcelDataBlock() {};
        virtual ~SlaveParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SlaveID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SlaveID.deserialize(buffer);
        }
    };
    // MergeParcelPacket Member List
    MasterParcelDataBlock MasterParcelData;
    VariableSerializable<SlaveParcelDataBlock> SlaveParcelData;

public:
    MergeParcelPacket() {
        this->setID(MergeParcel_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~MergeParcelPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MasterParcelData.serialize(buffer);
        SlaveParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MasterParcelData.deserialize(buffer);
        SlaveParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MergeParcelPacket();
    }
};

// LogParcelChangesPacket
class LogParcelChangesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableUUID OwnerID;
        SerializableBool IsOwnerGroup;
        SerializableS32 ActualArea;
        SerializableS8 Action;
        SerializableUUID TransactionID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            OwnerID.serialize(buffer);
            IsOwnerGroup.serialize(buffer);
            ActualArea.serialize(buffer);
            Action.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            IsOwnerGroup.deserialize(buffer);
            ActualArea.deserialize(buffer);
            Action.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    // LogParcelChangesPacket Member List
    AgentDataBlock AgentData;
    RegionDataBlock RegionData;
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    LogParcelChangesPacket() {
        this->setID(LogParcelChanges_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~LogParcelChangesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RegionData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RegionData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogParcelChangesPacket();
    }
};

// CheckParcelSalesPacket
class CheckParcelSalesPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // CheckParcelSalesPacket Member List
    VariableSerializable<RegionDataBlock> RegionData;

public:
    CheckParcelSalesPacket() {
        this->setID(CheckParcelSales_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CheckParcelSalesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CheckParcelSalesPacket();
    }
};

// ParcelSalesPacket
class ParcelSalesPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableUUID BuyerID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            BuyerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            BuyerID.deserialize(buffer);
        }
    };
    // ParcelSalesPacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    ParcelSalesPacket() {
        this->setID(ParcelSales_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelSalesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelSalesPacket();
    }
};

// ParcelGodMarkAsContentPacket
class ParcelGodMarkAsContentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // ParcelGodMarkAsContentPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ParcelGodMarkAsContentPacket() {
        this->setID(ParcelGodMarkAsContent_ID);
    };
    virtual ~ParcelGodMarkAsContentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelGodMarkAsContentPacket();
    }
};

// ViewerStartAuctionPacket
class ViewerStartAuctionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableS32 LocalID;
        SerializableUUID SnapshotID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            SnapshotID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
        }
    };
    // ViewerStartAuctionPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    ViewerStartAuctionPacket() {
        this->setID(ViewerStartAuction_ID);
    };
    virtual ~ViewerStartAuctionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerStartAuctionPacket();
    }
};

// StartAuctionPacket
class StartAuctionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableUUID SnapshotID;
        SerializableVariable1 Name;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            SnapshotID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            SnapshotID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // StartAuctionPacket Member List
    AgentDataBlock AgentData;
    ParcelDataBlock ParcelData;

public:
    StartAuctionPacket() {
        this->setID(StartAuction_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~StartAuctionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartAuctionPacket();
    }
};

// ConfirmAuctionStartPacket
class ConfirmAuctionStartPacket : public PacketBase {
public:

    // Block Class List
    class AuctionDataBlock : public PacketSerializable {
    public:
        // AuctionDataBlock Member List
        SerializableUUID ParcelID;
        SerializableU32 AuctionID;
    public:
        AuctionDataBlock() {};
        virtual ~AuctionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            AuctionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            AuctionID.deserialize(buffer);
        }
    };
    // ConfirmAuctionStartPacket Member List
    AuctionDataBlock AuctionData;

public:
    ConfirmAuctionStartPacket() {
        this->setID(ConfirmAuctionStart_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ConfirmAuctionStartPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AuctionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AuctionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ConfirmAuctionStartPacket();
    }
};

// CompleteAuctionPacket
class CompleteAuctionPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
        }
    };
    // CompleteAuctionPacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    CompleteAuctionPacket() {
        this->setID(CompleteAuction_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CompleteAuctionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CompleteAuctionPacket();
    }
};

// CancelAuctionPacket
class CancelAuctionPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
        }
    };
    // CancelAuctionPacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    CancelAuctionPacket() {
        this->setID(CancelAuction_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CancelAuctionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CancelAuctionPacket();
    }
};

// CheckParcelAuctionsPacket
class CheckParcelAuctionsPacket : public PacketBase {
public:

    // Block Class List
    class RegionDataBlock : public PacketSerializable {
    public:
        // RegionDataBlock Member List
        SerializableU64 RegionHandle;
    public:
        RegionDataBlock() {};
        virtual ~RegionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
        }
    };
    // CheckParcelAuctionsPacket Member List
    VariableSerializable<RegionDataBlock> RegionData;

public:
    CheckParcelAuctionsPacket() {
        this->setID(CheckParcelAuctions_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CheckParcelAuctionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RegionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RegionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CheckParcelAuctionsPacket();
    }
};

// ParcelAuctionsPacket
class ParcelAuctionsPacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableUUID WinnerID;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            WinnerID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            WinnerID.deserialize(buffer);
        }
    };
    // ParcelAuctionsPacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    ParcelAuctionsPacket() {
        this->setID(ParcelAuctions_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelAuctionsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelAuctionsPacket();
    }
};

// UUIDNameRequestPacket
class UUIDNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // UUIDNameRequestPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;

public:
    UUIDNameRequestPacket() {
        this->setID(UUIDNameRequest_ID);
    };
    virtual ~UUIDNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDNameRequestPacket();
    }
};

// UUIDNameReplyPacket
class UUIDNameReplyPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
        SerializableVariable1 FirstName;
        SerializableVariable1 LastName;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            FirstName.serialize(buffer);
            LastName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            FirstName.deserialize(buffer);
            LastName.deserialize(buffer);
        }
    };
    // UUIDNameReplyPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;

public:
    UUIDNameReplyPacket() {
        this->setID(UUIDNameReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~UUIDNameReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDNameReplyPacket();
    }
};

// UUIDGroupNameRequestPacket
class UUIDGroupNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    // UUIDGroupNameRequestPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;

public:
    UUIDGroupNameRequestPacket() {
        this->setID(UUIDGroupNameRequest_ID);
    };
    virtual ~UUIDGroupNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDGroupNameRequestPacket();
    }
};

// UUIDGroupNameReplyPacket
class UUIDGroupNameReplyPacket : public PacketBase {
public:

    // Block Class List
    class UUIDNameBlockBlock : public PacketSerializable {
    public:
        // UUIDNameBlockBlock Member List
        SerializableUUID ID;
        SerializableVariable1 GroupName;
    public:
        UUIDNameBlockBlock() {};
        virtual ~UUIDNameBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            GroupName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            GroupName.deserialize(buffer);
        }
    };
    // UUIDGroupNameReplyPacket Member List
    VariableSerializable<UUIDNameBlockBlock> UUIDNameBlock;

public:
    UUIDGroupNameReplyPacket() {
        this->setID(UUIDGroupNameReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~UUIDGroupNameReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UUIDNameBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UUIDNameBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UUIDGroupNameReplyPacket();
    }
};

// ChatPassPacket
class ChatPassPacket : public PacketBase {
public:

    // Block Class List
    class ChatDataBlock : public PacketSerializable {
    public:
        // ChatDataBlock Member List
        SerializableS32 Channel;
        SerializableVector3 Position;
        SerializableUUID ID;
        SerializableUUID OwnerID;
        SerializableVariable1 Name;
        SerializableU8 SourceType;
        SerializableU8 Type;
        SerializableF32 Radius;
        SerializableU8 SimAccess;
        SerializableVariable2 Message;
    public:
        ChatDataBlock() {};
        virtual ~ChatDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Channel.serialize(buffer);
            Position.serialize(buffer);
            ID.serialize(buffer);
            OwnerID.serialize(buffer);
            Name.serialize(buffer);
            SourceType.serialize(buffer);
            Type.serialize(buffer);
            Radius.serialize(buffer);
            SimAccess.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Channel.deserialize(buffer);
            Position.deserialize(buffer);
            ID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Name.deserialize(buffer);
            SourceType.deserialize(buffer);
            Type.deserialize(buffer);
            Radius.deserialize(buffer);
            SimAccess.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // ChatPassPacket Member List
    ChatDataBlock ChatData;

public:
    ChatPassPacket() {
        this->setID(ChatPass_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ChatPassPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ChatData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ChatData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChatPassPacket();
    }
};

// EdgeDataPacketPacket
class EdgeDataPacketPacket : public PacketBase {
public:

    // Block Class List
    class EdgeDataBlock : public PacketSerializable {
    public:
        // EdgeDataBlock Member List
        SerializableU8 LayerType;
        SerializableU8 Direction;
        SerializableVariable2 LayerData;
    public:
        EdgeDataBlock() {};
        virtual ~EdgeDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LayerType.serialize(buffer);
            Direction.serialize(buffer);
            LayerData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LayerType.deserialize(buffer);
            Direction.deserialize(buffer);
            LayerData.deserialize(buffer);
        }
    };
    // EdgeDataPacketPacket Member List
    EdgeDataBlock EdgeData;

public:
    EdgeDataPacketPacket() {
        this->setID(EdgeDataPacket_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EdgeDataPacketPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        EdgeData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        EdgeData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EdgeDataPacketPacket();
    }
};

// SimStatusPacket
class SimStatusPacket : public PacketBase {
public:

    // Block Class List
    class SimStatusBlock : public PacketSerializable {
    public:
        // SimStatusBlock Member List
        SerializableBool CanAcceptAgents;
        SerializableBool CanAcceptTasks;
    public:
        SimStatusBlock() {};
        virtual ~SimStatusBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CanAcceptAgents.serialize(buffer);
            CanAcceptTasks.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CanAcceptAgents.deserialize(buffer);
            CanAcceptTasks.deserialize(buffer);
        }
    };
    // SimStatusPacket Member List
    SimStatusBlock SimStatus;

public:
    SimStatusPacket() {
        this->setID(SimStatus_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SimStatusPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SimStatus.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SimStatus.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimStatusPacket();
    }
};

// ChildAgentUpdatePacket
class ChildAgentUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU32 ViewerCircuitCode;
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableVector3 AgentPos;
        SerializableVector3 AgentVel;
        SerializableVector3 Center;
        SerializableVector3 Size;
        SerializableVector3 AtAxis;
        SerializableVector3 LeftAxis;
        SerializableVector3 UpAxis;
        SerializableBool ChangedGrid;
        SerializableF32 Far;
        SerializableF32 Aspect;
        SerializableVariable1 Throttles;
        SerializableU32 LocomotionState;
        SerializableQuaternion HeadRotation;
        SerializableQuaternion BodyRotation;
        SerializableU32 ControlFlags;
        SerializableF32 EnergyLevel;
        SerializableU8 GodLevel;
        SerializableBool AlwaysRun;
        SerializableUUID PreyAgent;
        SerializableU8 AgentAccess;
        SerializableVariable2 AgentTextures;
        SerializableUUID ActiveGroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            ViewerCircuitCode.serialize(buffer);
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AgentPos.serialize(buffer);
            AgentVel.serialize(buffer);
            Center.serialize(buffer);
            Size.serialize(buffer);
            AtAxis.serialize(buffer);
            LeftAxis.serialize(buffer);
            UpAxis.serialize(buffer);
            ChangedGrid.serialize(buffer);
            Far.serialize(buffer);
            Aspect.serialize(buffer);
            Throttles.serialize(buffer);
            LocomotionState.serialize(buffer);
            HeadRotation.serialize(buffer);
            BodyRotation.serialize(buffer);
            ControlFlags.serialize(buffer);
            EnergyLevel.serialize(buffer);
            GodLevel.serialize(buffer);
            AlwaysRun.serialize(buffer);
            PreyAgent.serialize(buffer);
            AgentAccess.serialize(buffer);
            AgentTextures.serialize(buffer);
            ActiveGroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            ViewerCircuitCode.deserialize(buffer);
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AgentPos.deserialize(buffer);
            AgentVel.deserialize(buffer);
            Center.deserialize(buffer);
            Size.deserialize(buffer);
            AtAxis.deserialize(buffer);
            LeftAxis.deserialize(buffer);
            UpAxis.deserialize(buffer);
            ChangedGrid.deserialize(buffer);
            Far.deserialize(buffer);
            Aspect.deserialize(buffer);
            Throttles.deserialize(buffer);
            LocomotionState.deserialize(buffer);
            HeadRotation.deserialize(buffer);
            BodyRotation.deserialize(buffer);
            ControlFlags.deserialize(buffer);
            EnergyLevel.deserialize(buffer);
            GodLevel.deserialize(buffer);
            AlwaysRun.deserialize(buffer);
            PreyAgent.deserialize(buffer);
            AgentAccess.deserialize(buffer);
            AgentTextures.deserialize(buffer);
            ActiveGroupID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableU64 GroupPowers;
        SerializableBool AcceptNotices;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            GroupPowers.serialize(buffer);
            AcceptNotices.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            GroupPowers.deserialize(buffer);
            AcceptNotices.deserialize(buffer);
        }
    };
    class AnimationDataBlock : public PacketSerializable {
    public:
        // AnimationDataBlock Member List
        SerializableUUID Animation;
        SerializableUUID ObjectID;
    public:
        AnimationDataBlock() {};
        virtual ~AnimationDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Animation.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Animation.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    class GranterBlockBlock : public PacketSerializable {
    public:
        // GranterBlockBlock Member List
        SerializableUUID GranterID;
    public:
        GranterBlockBlock() {};
        virtual ~GranterBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GranterID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GranterID.deserialize(buffer);
        }
    };
    class NVPairDataBlock : public PacketSerializable {
    public:
        // NVPairDataBlock Member List
        SerializableVariable2 NVPairs;
    public:
        NVPairDataBlock() {};
        virtual ~NVPairDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NVPairs.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NVPairs.deserialize(buffer);
        }
    };
    class VisualParamBlock : public PacketSerializable {
    public:
        // VisualParamBlock Member List
        SerializableU8 ParamValue;
    public:
        VisualParamBlock() {};
        virtual ~VisualParamBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParamValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParamValue.deserialize(buffer);
        }
    };
    // ChildAgentUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<GroupDataBlock> GroupData;
    VariableSerializable<AnimationDataBlock> AnimationData;
    VariableSerializable<GranterBlockBlock> GranterBlock;
    VariableSerializable<NVPairDataBlock> NVPairData;
    VariableSerializable<VisualParamBlock> VisualParam;

public:
    ChildAgentUpdatePacket() {
        this->setID(ChildAgentUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ChildAgentUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        AnimationData.serialize(buffer);
        GranterBlock.serialize(buffer);
        NVPairData.serialize(buffer);
        VisualParam.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        AnimationData.deserialize(buffer);
        GranterBlock.deserialize(buffer);
        NVPairData.deserialize(buffer);
        VisualParam.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChildAgentUpdatePacket();
    }
};

// ChildAgentAlivePacket
class ChildAgentAlivePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU32 ViewerCircuitCode;
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            ViewerCircuitCode.serialize(buffer);
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            ViewerCircuitCode.deserialize(buffer);
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ChildAgentAlivePacket Member List
    AgentDataBlock AgentData;

public:
    ChildAgentAlivePacket() {
        this->setID(ChildAgentAlive_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ChildAgentAlivePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChildAgentAlivePacket();
    }
};

// ChildAgentPositionUpdatePacket
class ChildAgentPositionUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableU64 RegionHandle;
        SerializableU32 ViewerCircuitCode;
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableVector3 AgentPos;
        SerializableVector3 AgentVel;
        SerializableVector3 Center;
        SerializableVector3 Size;
        SerializableVector3 AtAxis;
        SerializableVector3 LeftAxis;
        SerializableVector3 UpAxis;
        SerializableBool ChangedGrid;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionHandle.serialize(buffer);
            ViewerCircuitCode.serialize(buffer);
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AgentPos.serialize(buffer);
            AgentVel.serialize(buffer);
            Center.serialize(buffer);
            Size.serialize(buffer);
            AtAxis.serialize(buffer);
            LeftAxis.serialize(buffer);
            UpAxis.serialize(buffer);
            ChangedGrid.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionHandle.deserialize(buffer);
            ViewerCircuitCode.deserialize(buffer);
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AgentPos.deserialize(buffer);
            AgentVel.deserialize(buffer);
            Center.deserialize(buffer);
            Size.deserialize(buffer);
            AtAxis.deserialize(buffer);
            LeftAxis.deserialize(buffer);
            UpAxis.deserialize(buffer);
            ChangedGrid.deserialize(buffer);
        }
    };
    // ChildAgentPositionUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    ChildAgentPositionUpdatePacket() {
        this->setID(ChildAgentPositionUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ChildAgentPositionUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChildAgentPositionUpdatePacket();
    }
};

// ChildAgentDyingPacket
class ChildAgentDyingPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ChildAgentDyingPacket Member List
    AgentDataBlock AgentData;

public:
    ChildAgentDyingPacket() {
        this->setID(ChildAgentDying_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ChildAgentDyingPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChildAgentDyingPacket();
    }
};

// ChildAgentUnknownPacket
class ChildAgentUnknownPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // ChildAgentUnknownPacket Member List
    AgentDataBlock AgentData;

public:
    ChildAgentUnknownPacket() {
        this->setID(ChildAgentUnknown_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ChildAgentUnknownPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChildAgentUnknownPacket();
    }
};

// AtomicPassObjectPacket
class AtomicPassObjectPacket : public PacketBase {
public:

    // Block Class List
    class TaskDataBlock : public PacketSerializable {
    public:
        // TaskDataBlock Member List
        SerializableUUID TaskID;
        SerializableBool AttachmentNeedsSave;
    public:
        TaskDataBlock() {};
        virtual ~TaskDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            AttachmentNeedsSave.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            AttachmentNeedsSave.deserialize(buffer);
        }
    };
    // AtomicPassObjectPacket Member List
    TaskDataBlock TaskData;

public:
    AtomicPassObjectPacket() {
        this->setID(AtomicPassObject_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AtomicPassObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TaskData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TaskData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AtomicPassObjectPacket();
    }
};

// KillChildAgentsPacket
class KillChildAgentsPacket : public PacketBase {
public:

    // Block Class List
    class IDBlockBlock : public PacketSerializable {
    public:
        // IDBlockBlock Member List
        SerializableUUID AgentID;
    public:
        IDBlockBlock() {};
        virtual ~IDBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // KillChildAgentsPacket Member List
    IDBlockBlock IDBlock;

public:
    KillChildAgentsPacket() {
        this->setID(KillChildAgents_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~KillChildAgentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        IDBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        IDBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new KillChildAgentsPacket();
    }
};

// GetScriptRunningPacket
class GetScriptRunningPacket : public PacketBase {
public:

    // Block Class List
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // GetScriptRunningPacket Member List
    ScriptBlock Script;

public:
    GetScriptRunningPacket() {
        this->setID(GetScriptRunning_ID);
    };
    virtual ~GetScriptRunningPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GetScriptRunningPacket();
    }
};

// ScriptRunningReplyPacket
class ScriptRunningReplyPacket : public PacketBase {
public:

    // Block Class List
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableBool Running;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            Running.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Running.deserialize(buffer);
        }
    };
    // ScriptRunningReplyPacket Member List
    ScriptBlock Script;

public:
    ScriptRunningReplyPacket() {
        this->setID(ScriptRunningReply_ID);
    };
    virtual ~ScriptRunningReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptRunningReplyPacket();
    }
};

// SetScriptRunningPacket
class SetScriptRunningPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
        SerializableBool Running;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
            Running.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
            Running.deserialize(buffer);
        }
    };
    // SetScriptRunningPacket Member List
    AgentDataBlock AgentData;
    ScriptBlock Script;

public:
    SetScriptRunningPacket() {
        this->setID(SetScriptRunning_ID);
    };
    virtual ~SetScriptRunningPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetScriptRunningPacket();
    }
};

// ScriptResetPacket
class ScriptResetPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ScriptBlock : public PacketSerializable {
    public:
        // ScriptBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID ItemID;
    public:
        ScriptBlock() {};
        virtual ~ScriptBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // ScriptResetPacket Member List
    AgentDataBlock AgentData;
    ScriptBlock Script;

public:
    ScriptResetPacket() {
        this->setID(ScriptReset_ID);
    };
    virtual ~ScriptResetPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Script.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Script.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptResetPacket();
    }
};

// ScriptSensorRequestPacket
class ScriptSensorRequestPacket : public PacketBase {
public:

    // Block Class List
    class RequesterBlock : public PacketSerializable {
    public:
        // RequesterBlock Member List
        SerializableUUID SourceID;
        SerializableUUID RequestID;
        SerializableUUID SearchID;
        SerializableVector3 SearchPos;
        SerializableQuaternion SearchDir;
        SerializableVariable1 SearchName;
        SerializableS32 Type;
        SerializableF32 Range;
        SerializableF32 Arc;
        SerializableU64 RegionHandle;
        SerializableU8 SearchRegions;
    public:
        RequesterBlock() {};
        virtual ~RequesterBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
            RequestID.serialize(buffer);
            SearchID.serialize(buffer);
            SearchPos.serialize(buffer);
            SearchDir.serialize(buffer);
            SearchName.serialize(buffer);
            Type.serialize(buffer);
            Range.serialize(buffer);
            Arc.serialize(buffer);
            RegionHandle.serialize(buffer);
            SearchRegions.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
            RequestID.deserialize(buffer);
            SearchID.deserialize(buffer);
            SearchPos.deserialize(buffer);
            SearchDir.deserialize(buffer);
            SearchName.deserialize(buffer);
            Type.deserialize(buffer);
            Range.deserialize(buffer);
            Arc.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            SearchRegions.deserialize(buffer);
        }
    };
    // ScriptSensorRequestPacket Member List
    RequesterBlock Requester;

public:
    ScriptSensorRequestPacket() {
        this->setID(ScriptSensorRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ScriptSensorRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Requester.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Requester.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptSensorRequestPacket();
    }
};

// ScriptSensorReplyPacket
class ScriptSensorReplyPacket : public PacketBase {
public:

    // Block Class List
    class RequesterBlock : public PacketSerializable {
    public:
        // RequesterBlock Member List
        SerializableUUID SourceID;
    public:
        RequesterBlock() {};
        virtual ~RequesterBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
        }
    };
    class SensedDataBlock : public PacketSerializable {
    public:
        // SensedDataBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableVector3 Position;
        SerializableVector3 Velocity;
        SerializableQuaternion Rotation;
        SerializableVariable1 Name;
        SerializableS32 Type;
        SerializableF32 Range;
    public:
        SensedDataBlock() {};
        virtual ~SensedDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            Position.serialize(buffer);
            Velocity.serialize(buffer);
            Rotation.serialize(buffer);
            Name.serialize(buffer);
            Type.serialize(buffer);
            Range.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            Position.deserialize(buffer);
            Velocity.deserialize(buffer);
            Rotation.deserialize(buffer);
            Name.deserialize(buffer);
            Type.deserialize(buffer);
            Range.deserialize(buffer);
        }
    };
    // ScriptSensorReplyPacket Member List
    RequesterBlock Requester;
    VariableSerializable<SensedDataBlock> SensedData;

public:
    ScriptSensorReplyPacket() {
        this->setID(ScriptSensorReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ScriptSensorReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Requester.serialize(buffer);
        SensedData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Requester.deserialize(buffer);
        SensedData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptSensorReplyPacket();
    }
};

// CompleteAgentMovementPacket
class CompleteAgentMovementPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 CircuitCode;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            CircuitCode.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            CircuitCode.deserialize(buffer);
        }
    };
    // CompleteAgentMovementPacket Member List
    AgentDataBlock AgentData;

public:
    CompleteAgentMovementPacket() {
        this->setID(CompleteAgentMovement_ID);
    };
    virtual ~CompleteAgentMovementPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CompleteAgentMovementPacket();
    }
};

// AgentMovementCompletePacket
class AgentMovementCompletePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableVector3 Position;
        SerializableVector3 LookAt;
        SerializableU64 RegionHandle;
        SerializableU32 Timestamp;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Position.serialize(buffer);
            LookAt.serialize(buffer);
            RegionHandle.serialize(buffer);
            Timestamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Position.deserialize(buffer);
            LookAt.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            Timestamp.deserialize(buffer);
        }
    };
    class SimDataBlock : public PacketSerializable {
    public:
        // SimDataBlock Member List
        SerializableVariable2 ChannelVersion;
    public:
        SimDataBlock() {};
        virtual ~SimDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ChannelVersion.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ChannelVersion.deserialize(buffer);
        }
    };
    // AgentMovementCompletePacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    SimDataBlock SimData;

public:
    AgentMovementCompletePacket() {
        this->setID(AgentMovementComplete_ID);
    };
    virtual ~AgentMovementCompletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        SimData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        SimData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentMovementCompletePacket();
    }
};

// DataServerLogoutPacket
class DataServerLogoutPacket : public PacketBase {
public:

    // Block Class List
    class UserDataBlock : public PacketSerializable {
    public:
        // UserDataBlock Member List
        SerializableUUID AgentID;
        SerializableIPADDR ViewerIP;
        SerializableBool Disconnect;
        SerializableUUID SessionID;
    public:
        UserDataBlock() {};
        virtual ~UserDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            ViewerIP.serialize(buffer);
            Disconnect.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            ViewerIP.deserialize(buffer);
            Disconnect.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // DataServerLogoutPacket Member List
    UserDataBlock UserData;

public:
    DataServerLogoutPacket() {
        this->setID(DataServerLogout_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~DataServerLogoutPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        UserData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        UserData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DataServerLogoutPacket();
    }
};

// LogoutRequestPacket
class LogoutRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // LogoutRequestPacket Member List
    AgentDataBlock AgentData;

public:
    LogoutRequestPacket() {
        this->setID(LogoutRequest_ID);
    };
    virtual ~LogoutRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogoutRequestPacket();
    }
};

// LogoutReplyPacket
class LogoutReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // LogoutReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    LogoutReplyPacket() {
        this->setID(LogoutReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~LogoutReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogoutReplyPacket();
    }
};

// ImprovedInstantMessagePacket
class ImprovedInstantMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MessageBlockBlock : public PacketSerializable {
    public:
        // MessageBlockBlock Member List
        SerializableBool FromGroup;
        SerializableUUID ToAgentID;
        SerializableU32 ParentEstateID;
        SerializableUUID RegionID;
        SerializableVector3 Position;
        SerializableU8 Offline;
        SerializableU8 Dialog;
        SerializableUUID ID;
        SerializableU32 Timestamp;
        SerializableVariable1 FromAgentName;
        SerializableVariable2 Message;
        SerializableVariable2 BinaryBucket;
    public:
        MessageBlockBlock() {};
        virtual ~MessageBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromGroup.serialize(buffer);
            ToAgentID.serialize(buffer);
            ParentEstateID.serialize(buffer);
            RegionID.serialize(buffer);
            Position.serialize(buffer);
            Offline.serialize(buffer);
            Dialog.serialize(buffer);
            ID.serialize(buffer);
            Timestamp.serialize(buffer);
            FromAgentName.serialize(buffer);
            Message.serialize(buffer);
            BinaryBucket.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromGroup.deserialize(buffer);
            ToAgentID.deserialize(buffer);
            ParentEstateID.deserialize(buffer);
            RegionID.deserialize(buffer);
            Position.deserialize(buffer);
            Offline.deserialize(buffer);
            Dialog.deserialize(buffer);
            ID.deserialize(buffer);
            Timestamp.deserialize(buffer);
            FromAgentName.deserialize(buffer);
            Message.deserialize(buffer);
            BinaryBucket.deserialize(buffer);
        }
    };
    // ImprovedInstantMessagePacket Member List
    AgentDataBlock AgentData;
    MessageBlockBlock MessageBlock;

public:
    ImprovedInstantMessagePacket() {
        this->setID(ImprovedInstantMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ImprovedInstantMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MessageBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MessageBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ImprovedInstantMessagePacket();
    }
};

// RetrieveInstantMessagesPacket
class RetrieveInstantMessagesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // RetrieveInstantMessagesPacket Member List
    AgentDataBlock AgentData;

public:
    RetrieveInstantMessagesPacket() {
        this->setID(RetrieveInstantMessages_ID);
    };
    virtual ~RetrieveInstantMessagesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RetrieveInstantMessagesPacket();
    }
};

// FindAgentPacket
class FindAgentPacket : public PacketBase {
public:

    // Block Class List
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID Hunter;
        SerializableUUID Prey;
        SerializableIPADDR SpaceIP;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Hunter.serialize(buffer);
            Prey.serialize(buffer);
            SpaceIP.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Hunter.deserialize(buffer);
            Prey.deserialize(buffer);
            SpaceIP.deserialize(buffer);
        }
    };
    class LocationBlockBlock : public PacketSerializable {
    public:
        // LocationBlockBlock Member List
        SerializableF64 GlobalX;
        SerializableF64 GlobalY;
    public:
        LocationBlockBlock() {};
        virtual ~LocationBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GlobalX.serialize(buffer);
            GlobalY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GlobalX.deserialize(buffer);
            GlobalY.deserialize(buffer);
        }
    };
    // FindAgentPacket Member List
    AgentBlockBlock AgentBlock;
    VariableSerializable<LocationBlockBlock> LocationBlock;

public:
    FindAgentPacket() {
        this->setID(FindAgent_ID);
    };
    virtual ~FindAgentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentBlock.serialize(buffer);
        LocationBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentBlock.deserialize(buffer);
        LocationBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FindAgentPacket();
    }
};

// RequestGodlikePowersPacket
class RequestGodlikePowersPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestBlockBlock : public PacketSerializable {
    public:
        // RequestBlockBlock Member List
        SerializableBool Godlike;
        SerializableUUID Token;
    public:
        RequestBlockBlock() {};
        virtual ~RequestBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Godlike.serialize(buffer);
            Token.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Godlike.deserialize(buffer);
            Token.deserialize(buffer);
        }
    };
    // RequestGodlikePowersPacket Member List
    AgentDataBlock AgentData;
    RequestBlockBlock RequestBlock;

public:
    RequestGodlikePowersPacket() {
        this->setID(RequestGodlikePowers_ID);
    };
    virtual ~RequestGodlikePowersPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestGodlikePowersPacket();
    }
};

// GrantGodlikePowersPacket
class GrantGodlikePowersPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GrantDataBlock : public PacketSerializable {
    public:
        // GrantDataBlock Member List
        SerializableU8 GodLevel;
        SerializableUUID Token;
    public:
        GrantDataBlock() {};
        virtual ~GrantDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GodLevel.serialize(buffer);
            Token.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GodLevel.deserialize(buffer);
            Token.deserialize(buffer);
        }
    };
    // GrantGodlikePowersPacket Member List
    AgentDataBlock AgentData;
    GrantDataBlock GrantData;

public:
    GrantGodlikePowersPacket() {
        this->setID(GrantGodlikePowers_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~GrantGodlikePowersPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GrantData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GrantData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GrantGodlikePowersPacket();
    }
};

// GodlikeMessagePacket
class GodlikeMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // GodlikeMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;

public:
    GodlikeMessagePacket() {
        this->setID(GodlikeMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GodlikeMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GodlikeMessagePacket();
    }
};

// EstateOwnerMessagePacket
class EstateOwnerMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // EstateOwnerMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;

public:
    EstateOwnerMessagePacket() {
        this->setID(EstateOwnerMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EstateOwnerMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EstateOwnerMessagePacket();
    }
};

// GenericMessagePacket
class GenericMessagePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // GenericMessagePacket Member List
    AgentDataBlock AgentData;
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;

public:
    GenericMessagePacket() {
        this->setID(GenericMessage_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GenericMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GenericMessagePacket();
    }
};

// MuteListRequestPacket
class MuteListRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableU32 MuteCRC;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteCRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteCRC.deserialize(buffer);
        }
    };
    // MuteListRequestPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    MuteListRequestPacket() {
        this->setID(MuteListRequest_ID);
    };
    virtual ~MuteListRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MuteListRequestPacket();
    }
};

// UpdateMuteListEntryPacket
class UpdateMuteListEntryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableUUID MuteID;
        SerializableVariable1 MuteName;
        SerializableS32 MuteType;
        SerializableU32 MuteFlags;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteID.serialize(buffer);
            MuteName.serialize(buffer);
            MuteType.serialize(buffer);
            MuteFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteID.deserialize(buffer);
            MuteName.deserialize(buffer);
            MuteType.deserialize(buffer);
            MuteFlags.deserialize(buffer);
        }
    };
    // UpdateMuteListEntryPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    UpdateMuteListEntryPacket() {
        this->setID(UpdateMuteListEntry_ID);
    };
    virtual ~UpdateMuteListEntryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateMuteListEntryPacket();
    }
};

// RemoveMuteListEntryPacket
class RemoveMuteListEntryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableUUID MuteID;
        SerializableVariable1 MuteName;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MuteID.serialize(buffer);
            MuteName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MuteID.deserialize(buffer);
            MuteName.deserialize(buffer);
        }
    };
    // RemoveMuteListEntryPacket Member List
    AgentDataBlock AgentData;
    MuteDataBlock MuteData;

public:
    RemoveMuteListEntryPacket() {
        this->setID(RemoveMuteListEntry_ID);
    };
    virtual ~RemoveMuteListEntryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveMuteListEntryPacket();
    }
};

// CopyInventoryFromNotecardPacket
class CopyInventoryFromNotecardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class NotecardDataBlock : public PacketSerializable {
    public:
        // NotecardDataBlock Member List
        SerializableUUID NotecardItemID;
        SerializableUUID ObjectID;
    public:
        NotecardDataBlock() {};
        virtual ~NotecardDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NotecardItemID.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NotecardItemID.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    // CopyInventoryFromNotecardPacket Member List
    AgentDataBlock AgentData;
    NotecardDataBlock NotecardData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    CopyInventoryFromNotecardPacket() {
        this->setID(CopyInventoryFromNotecard_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CopyInventoryFromNotecardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        NotecardData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        NotecardData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CopyInventoryFromNotecardPacket();
    }
};

// UpdateInventoryItemPacket
class UpdateInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableU32 CallbackID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CallbackID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CallbackID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    UpdateInventoryItemPacket() {
        this->setID(UpdateInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateInventoryItemPacket();
    }
};

// UpdateCreateInventoryItemPacket
class UpdateCreateInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableBool SimApproved;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SimApproved.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SimApproved.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableU32 CallbackID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID AssetID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CallbackID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            AssetID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CallbackID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            AssetID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateCreateInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    UpdateCreateInventoryItemPacket() {
        this->setID(UpdateCreateInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateCreateInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateCreateInventoryItemPacket();
    }
};

// MoveInventoryItemPacket
class MoveInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Stamp;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Stamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Stamp.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableVariable1 NewName;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            NewName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            NewName.deserialize(buffer);
        }
    };
    // MoveInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    MoveInventoryItemPacket() {
        this->setID(MoveInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoveInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveInventoryItemPacket();
    }
};

// CopyInventoryItemPacket
class CopyInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 CallbackID;
        SerializableUUID OldAgentID;
        SerializableUUID OldItemID;
        SerializableUUID NewFolderID;
        SerializableVariable1 NewName;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CallbackID.serialize(buffer);
            OldAgentID.serialize(buffer);
            OldItemID.serialize(buffer);
            NewFolderID.serialize(buffer);
            NewName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CallbackID.deserialize(buffer);
            OldAgentID.deserialize(buffer);
            OldItemID.deserialize(buffer);
            NewFolderID.deserialize(buffer);
            NewName.deserialize(buffer);
        }
    };
    // CopyInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    CopyInventoryItemPacket() {
        this->setID(CopyInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CopyInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CopyInventoryItemPacket();
    }
};

// RemoveInventoryItemPacket
class RemoveInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RemoveInventoryItemPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    RemoveInventoryItemPacket() {
        this->setID(RemoveInventoryItem_ID);
    };
    virtual ~RemoveInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryItemPacket();
    }
};

// ChangeInventoryItemFlagsPacket
class ChangeInventoryItemFlagsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableU32 Flags;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ChangeInventoryItemFlagsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    ChangeInventoryItemFlagsPacket() {
        this->setID(ChangeInventoryItemFlags_ID);
    };
    virtual ~ChangeInventoryItemFlagsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChangeInventoryItemFlagsPacket();
    }
};

// SaveAssetIntoInventoryPacket
class SaveAssetIntoInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID NewAssetID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            NewAssetID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            NewAssetID.deserialize(buffer);
        }
    };
    // SaveAssetIntoInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    SaveAssetIntoInventoryPacket() {
        this->setID(SaveAssetIntoInventory_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~SaveAssetIntoInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SaveAssetIntoInventoryPacket();
    }
};

// CreateInventoryFolderPacket
class CreateInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // CreateInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    FolderDataBlock FolderData;

public:
    CreateInventoryFolderPacket() {
        this->setID(CreateInventoryFolder_ID);
    };
    virtual ~CreateInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateInventoryFolderPacket();
    }
};

// UpdateInventoryFolderPacket
class UpdateInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // UpdateInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;

public:
    UpdateInventoryFolderPacket() {
        this->setID(UpdateInventoryFolder_ID);
    };
    virtual ~UpdateInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateInventoryFolderPacket();
    }
};

// MoveInventoryFolderPacket
class MoveInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableBool Stamp;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Stamp.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Stamp.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
        }
    };
    // MoveInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    MoveInventoryFolderPacket() {
        this->setID(MoveInventoryFolder_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoveInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveInventoryFolderPacket();
    }
};

// RemoveInventoryFolderPacket
class RemoveInventoryFolderPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // RemoveInventoryFolderPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;

public:
    RemoveInventoryFolderPacket() {
        this->setID(RemoveInventoryFolder_ID);
    };
    virtual ~RemoveInventoryFolderPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryFolderPacket();
    }
};

// FetchInventoryDescendentsPacket
class FetchInventoryDescendentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID OwnerID;
        SerializableS32 SortOrder;
        SerializableBool FetchFolders;
        SerializableBool FetchItems;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            OwnerID.serialize(buffer);
            SortOrder.serialize(buffer);
            FetchFolders.serialize(buffer);
            FetchItems.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            SortOrder.deserialize(buffer);
            FetchFolders.deserialize(buffer);
            FetchItems.deserialize(buffer);
        }
    };
    // FetchInventoryDescendentsPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    FetchInventoryDescendentsPacket() {
        this->setID(FetchInventoryDescendents_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~FetchInventoryDescendentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FetchInventoryDescendentsPacket();
    }
};

// InventoryDescendentsPacket
class InventoryDescendentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID FolderID;
        SerializableUUID OwnerID;
        SerializableS32 Version;
        SerializableS32 Descendents;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            FolderID.serialize(buffer);
            OwnerID.serialize(buffer);
            Version.serialize(buffer);
            Descendents.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            FolderID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Version.deserialize(buffer);
            Descendents.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    class ItemDataBlock : public PacketSerializable {
    public:
        // ItemDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID AssetID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        ItemDataBlock() {};
        virtual ~ItemDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            AssetID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            AssetID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // InventoryDescendentsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    VariableSerializable<ItemDataBlock> ItemData;

public:
    InventoryDescendentsPacket() {
        this->setID(InventoryDescendents_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~InventoryDescendentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
        ItemData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
        ItemData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InventoryDescendentsPacket();
    }
};

// FetchInventoryPacket
class FetchInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID OwnerID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OwnerID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OwnerID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // FetchInventoryPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    FetchInventoryPacket() {
        this->setID(FetchInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~FetchInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FetchInventoryPacket();
    }
};

// FetchInventoryReplyPacket
class FetchInventoryReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID AssetID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            AssetID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            AssetID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // FetchInventoryReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    FetchInventoryReplyPacket() {
        this->setID(FetchInventoryReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~FetchInventoryReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FetchInventoryReplyPacket();
    }
};

// BulkUpdateInventoryPacket
class BulkUpdateInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID TransactionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
        SerializableUUID ParentID;
        SerializableS8 Type;
        SerializableVariable1 Name;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            ParentID.serialize(buffer);
            Type.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Type.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    class ItemDataBlock : public PacketSerializable {
    public:
        // ItemDataBlock Member List
        SerializableUUID ItemID;
        SerializableU32 CallbackID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID AssetID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        ItemDataBlock() {};
        virtual ~ItemDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            CallbackID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            AssetID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            CallbackID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            AssetID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // BulkUpdateInventoryPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    VariableSerializable<ItemDataBlock> ItemData;

public:
    BulkUpdateInventoryPacket() {
        this->setID(BulkUpdateInventory_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~BulkUpdateInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
        ItemData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
        ItemData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new BulkUpdateInventoryPacket();
    }
};

// RequestInventoryAssetPacket
class RequestInventoryAssetPacket : public PacketBase {
public:

    // Block Class List
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableUUID AgentID;
        SerializableUUID OwnerID;
        SerializableUUID ItemID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            AgentID.serialize(buffer);
            OwnerID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            AgentID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RequestInventoryAssetPacket Member List
    QueryDataBlock QueryData;

public:
    RequestInventoryAssetPacket() {
        this->setID(RequestInventoryAsset_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RequestInventoryAssetPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestInventoryAssetPacket();
    }
};

// InventoryAssetResponsePacket
class InventoryAssetResponsePacket : public PacketBase {
public:

    // Block Class List
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
        SerializableUUID AssetID;
        SerializableBool IsReadable;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
            AssetID.serialize(buffer);
            IsReadable.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
            AssetID.deserialize(buffer);
            IsReadable.deserialize(buffer);
        }
    };
    // InventoryAssetResponsePacket Member List
    QueryDataBlock QueryData;

public:
    InventoryAssetResponsePacket() {
        this->setID(InventoryAssetResponse_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~InventoryAssetResponsePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        QueryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        QueryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InventoryAssetResponsePacket();
    }
};

// RemoveInventoryObjectsPacket
class RemoveInventoryObjectsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    class ItemDataBlock : public PacketSerializable {
    public:
        // ItemDataBlock Member List
        SerializableUUID ItemID;
    public:
        ItemDataBlock() {};
        virtual ~ItemDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RemoveInventoryObjectsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<FolderDataBlock> FolderData;
    VariableSerializable<ItemDataBlock> ItemData;

public:
    RemoveInventoryObjectsPacket() {
        this->setID(RemoveInventoryObjects_ID);
    };
    virtual ~RemoveInventoryObjectsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FolderData.serialize(buffer);
        ItemData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FolderData.deserialize(buffer);
        ItemData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveInventoryObjectsPacket();
    }
};

// PurgeInventoryDescendentsPacket
class PurgeInventoryDescendentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID FolderID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // PurgeInventoryDescendentsPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    PurgeInventoryDescendentsPacket() {
        this->setID(PurgeInventoryDescendents_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~PurgeInventoryDescendentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PurgeInventoryDescendentsPacket();
    }
};

// UpdateTaskInventoryPacket
class UpdateTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class UpdateDataBlock : public PacketSerializable {
    public:
        // UpdateDataBlock Member List
        SerializableU32 LocalID;
        SerializableU8 Key;
    public:
        UpdateDataBlock() {};
        virtual ~UpdateDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            Key.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            Key.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    UpdateDataBlock UpdateData;
    InventoryDataBlock InventoryData;

public:
    UpdateTaskInventoryPacket() {
        this->setID(UpdateTaskInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UpdateData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UpdateData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateTaskInventoryPacket();
    }
};

// RemoveTaskInventoryPacket
class RemoveTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RemoveTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    RemoveTaskInventoryPacket() {
        this->setID(RemoveTaskInventory_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RemoveTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveTaskInventoryPacket();
    }
};

// MoveTaskInventoryPacket
class MoveTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID FolderID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            FolderID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // MoveTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    MoveTaskInventoryPacket() {
        this->setID(MoveTaskInventory_ID);
    };
    virtual ~MoveTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoveTaskInventoryPacket();
    }
};

// RequestTaskInventoryPacket
class RequestTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableU32 LocalID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            LocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            LocalID.deserialize(buffer);
        }
    };
    // RequestTaskInventoryPacket Member List
    AgentDataBlock AgentData;
    InventoryDataBlock InventoryData;

public:
    RequestTaskInventoryPacket() {
        this->setID(RequestTaskInventory_ID);
    };
    virtual ~RequestTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RequestTaskInventoryPacket();
    }
};

// ReplyTaskInventoryPacket
class ReplyTaskInventoryPacket : public PacketBase {
public:

    // Block Class List
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID TaskID;
        SerializableS16 Serial;
        SerializableVariable1 Filename;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            Serial.serialize(buffer);
            Filename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            Serial.deserialize(buffer);
            Filename.deserialize(buffer);
        }
    };
    // ReplyTaskInventoryPacket Member List
    InventoryDataBlock InventoryData;

public:
    ReplyTaskInventoryPacket() {
        this->setID(ReplyTaskInventory_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ReplyTaskInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ReplyTaskInventoryPacket();
    }
};

// DeRezObjectPacket
class DeRezObjectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID GroupID;
        SerializableU8 Destination;
        SerializableUUID DestinationID;
        SerializableUUID TransactionID;
        SerializableU8 PacketCount;
        SerializableU8 PacketNumber;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Destination.serialize(buffer);
            DestinationID.serialize(buffer);
            TransactionID.serialize(buffer);
            PacketCount.serialize(buffer);
            PacketNumber.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Destination.deserialize(buffer);
            DestinationID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            PacketCount.deserialize(buffer);
            PacketNumber.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
        }
    };
    // DeRezObjectPacket Member List
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    DeRezObjectPacket() {
        this->setID(DeRezObject_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~DeRezObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AgentBlock.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AgentBlock.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeRezObjectPacket();
    }
};

// DeRezAckPacket
class DeRezAckPacket : public PacketBase {
public:

    // Block Class List
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
        SerializableBool Success;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            Success.deserialize(buffer);
        }
    };
    // DeRezAckPacket Member List
    TransactionDataBlock TransactionData;

public:
    DeRezAckPacket() {
        this->setID(DeRezAck_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~DeRezAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeRezAckPacket();
    }
};

// RezObjectPacket
class RezObjectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RezDataBlock : public PacketSerializable {
    public:
        // RezDataBlock Member List
        SerializableUUID FromTaskID;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableBool RayEndIsIntersection;
        SerializableBool RezSelected;
        SerializableBool RemoveItem;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
    public:
        RezDataBlock() {};
        virtual ~RezDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromTaskID.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            RezSelected.serialize(buffer);
            RemoveItem.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromTaskID.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            RezSelected.deserialize(buffer);
            RemoveItem.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // RezObjectPacket Member List
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    InventoryDataBlock InventoryData;

public:
    RezObjectPacket() {
        this->setID(RezObject_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezObjectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RezData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RezData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezObjectPacket();
    }
};

// RezObjectFromNotecardPacket
class RezObjectFromNotecardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RezDataBlock : public PacketSerializable {
    public:
        // RezDataBlock Member List
        SerializableUUID FromTaskID;
        SerializableU8 BypassRaycast;
        SerializableVector3 RayStart;
        SerializableVector3 RayEnd;
        SerializableUUID RayTargetID;
        SerializableBool RayEndIsIntersection;
        SerializableBool RezSelected;
        SerializableBool RemoveItem;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
    public:
        RezDataBlock() {};
        virtual ~RezDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromTaskID.serialize(buffer);
            BypassRaycast.serialize(buffer);
            RayStart.serialize(buffer);
            RayEnd.serialize(buffer);
            RayTargetID.serialize(buffer);
            RayEndIsIntersection.serialize(buffer);
            RezSelected.serialize(buffer);
            RemoveItem.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromTaskID.deserialize(buffer);
            BypassRaycast.deserialize(buffer);
            RayStart.deserialize(buffer);
            RayEnd.deserialize(buffer);
            RayTargetID.deserialize(buffer);
            RayEndIsIntersection.deserialize(buffer);
            RezSelected.deserialize(buffer);
            RemoveItem.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
        }
    };
    class NotecardDataBlock : public PacketSerializable {
    public:
        // NotecardDataBlock Member List
        SerializableUUID NotecardItemID;
        SerializableUUID ObjectID;
    public:
        NotecardDataBlock() {};
        virtual ~NotecardDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NotecardItemID.serialize(buffer);
            ObjectID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NotecardItemID.deserialize(buffer);
            ObjectID.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
        }
    };
    // RezObjectFromNotecardPacket Member List
    AgentDataBlock AgentData;
    RezDataBlock RezData;
    NotecardDataBlock NotecardData;
    VariableSerializable<InventoryDataBlock> InventoryData;

public:
    RezObjectFromNotecardPacket() {
        this->setID(RezObjectFromNotecard_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezObjectFromNotecardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RezData.serialize(buffer);
        NotecardData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RezData.deserialize(buffer);
        NotecardData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezObjectFromNotecardPacket();
    }
};

// TransferInventoryPacket
class TransferInventoryPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlockBlock : public PacketSerializable {
    public:
        // InfoBlockBlock Member List
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableUUID TransactionID;
    public:
        InfoBlockBlock() {};
        virtual ~InfoBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableUUID InventoryID;
        SerializableS8 Type;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            InventoryID.serialize(buffer);
            Type.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            InventoryID.deserialize(buffer);
            Type.deserialize(buffer);
        }
    };
    // TransferInventoryPacket Member List
    InfoBlockBlock InfoBlock;
    VariableSerializable<InventoryBlockBlock> InventoryBlock;

public:
    TransferInventoryPacket() {
        this->setID(TransferInventory_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferInventoryPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        InfoBlock.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        InfoBlock.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferInventoryPacket();
    }
};

// TransferInventoryAckPacket
class TransferInventoryAckPacket : public PacketBase {
public:

    // Block Class List
    class InfoBlockBlock : public PacketSerializable {
    public:
        // InfoBlockBlock Member List
        SerializableUUID TransactionID;
        SerializableUUID InventoryID;
    public:
        InfoBlockBlock() {};
        virtual ~InfoBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            InventoryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            InventoryID.deserialize(buffer);
        }
    };
    // TransferInventoryAckPacket Member List
    InfoBlockBlock InfoBlock;

public:
    TransferInventoryAckPacket() {
        this->setID(TransferInventoryAck_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~TransferInventoryAckPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        InfoBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        InfoBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TransferInventoryAckPacket();
    }
};

// AcceptFriendshipPacket
class AcceptFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // AcceptFriendshipPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    VariableSerializable<FolderDataBlock> FolderData;

public:
    AcceptFriendshipPacket() {
        this->setID(AcceptFriendship_ID);
    };
    virtual ~AcceptFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AcceptFriendshipPacket();
    }
};

// DeclineFriendshipPacket
class DeclineFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // DeclineFriendshipPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;

public:
    DeclineFriendshipPacket() {
        this->setID(DeclineFriendship_ID);
    };
    virtual ~DeclineFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeclineFriendshipPacket();
    }
};

// FormFriendshipPacket
class FormFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID SourceID;
        SerializableUUID DestID;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
        }
    };
    // FormFriendshipPacket Member List
    AgentBlockBlock AgentBlock;

public:
    FormFriendshipPacket() {
        this->setID(FormFriendship_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~FormFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new FormFriendshipPacket();
    }
};

// TerminateFriendshipPacket
class TerminateFriendshipPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ExBlockBlock : public PacketSerializable {
    public:
        // ExBlockBlock Member List
        SerializableUUID OtherID;
    public:
        ExBlockBlock() {};
        virtual ~ExBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OtherID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OtherID.deserialize(buffer);
        }
    };
    // TerminateFriendshipPacket Member List
    AgentDataBlock AgentData;
    ExBlockBlock ExBlock;

public:
    TerminateFriendshipPacket() {
        this->setID(TerminateFriendship_ID);
    };
    virtual ~TerminateFriendshipPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ExBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ExBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new TerminateFriendshipPacket();
    }
};

// OfferCallingCardPacket
class OfferCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID DestID;
        SerializableUUID TransactionID;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            DestID.serialize(buffer);
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            DestID.deserialize(buffer);
            TransactionID.deserialize(buffer);
        }
    };
    // OfferCallingCardPacket Member List
    AgentDataBlock AgentData;
    AgentBlockBlock AgentBlock;

public:
    OfferCallingCardPacket() {
        this->setID(OfferCallingCard_ID);
    };
    virtual ~OfferCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AgentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AgentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OfferCallingCardPacket();
    }
};

// AcceptCallingCardPacket
class AcceptCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    class FolderDataBlock : public PacketSerializable {
    public:
        // FolderDataBlock Member List
        SerializableUUID FolderID;
    public:
        FolderDataBlock() {};
        virtual ~FolderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
        }
    };
    // AcceptCallingCardPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;
    VariableSerializable<FolderDataBlock> FolderData;

public:
    AcceptCallingCardPacket() {
        this->setID(AcceptCallingCard_ID);
    };
    virtual ~AcceptCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
        FolderData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
        FolderData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AcceptCallingCardPacket();
    }
};

// DeclineCallingCardPacket
class DeclineCallingCardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class TransactionBlockBlock : public PacketSerializable {
    public:
        // TransactionBlockBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionBlockBlock() {};
        virtual ~TransactionBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // DeclineCallingCardPacket Member List
    AgentDataBlock AgentData;
    TransactionBlockBlock TransactionBlock;

public:
    DeclineCallingCardPacket() {
        this->setID(DeclineCallingCard_ID);
    };
    virtual ~DeclineCallingCardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeclineCallingCardPacket();
    }
};

// RezScriptPacket
class RezScriptPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class UpdateBlockBlock : public PacketSerializable {
    public:
        // UpdateBlockBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableBool Enabled;
    public:
        UpdateBlockBlock() {};
        virtual ~UpdateBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            Enabled.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            Enabled.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // RezScriptPacket Member List
    AgentDataBlock AgentData;
    UpdateBlockBlock UpdateBlock;
    InventoryBlockBlock InventoryBlock;

public:
    RezScriptPacket() {
        this->setID(RezScript_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezScriptPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UpdateBlock.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UpdateBlock.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezScriptPacket();
    }
};

// CreateInventoryItemPacket
class CreateInventoryItemPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableU32 CallbackID;
        SerializableUUID FolderID;
        SerializableUUID TransactionID;
        SerializableU32 NextOwnerMask;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU8 WearableType;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CallbackID.serialize(buffer);
            FolderID.serialize(buffer);
            TransactionID.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            WearableType.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CallbackID.deserialize(buffer);
            FolderID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            WearableType.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // CreateInventoryItemPacket Member List
    AgentDataBlock AgentData;
    InventoryBlockBlock InventoryBlock;

public:
    CreateInventoryItemPacket() {
        this->setID(CreateInventoryItem_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateInventoryItemPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateInventoryItemPacket();
    }
};

// CreateLandmarkForEventPacket
class CreateLandmarkForEventPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    class InventoryBlockBlock : public PacketSerializable {
    public:
        // InventoryBlockBlock Member List
        SerializableUUID FolderID;
        SerializableVariable1 Name;
    public:
        InventoryBlockBlock() {};
        virtual ~InventoryBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FolderID.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FolderID.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // CreateLandmarkForEventPacket Member List
    AgentDataBlock AgentData;
    EventDataBlock EventData;
    InventoryBlockBlock InventoryBlock;

public:
    CreateLandmarkForEventPacket() {
        this->setID(CreateLandmarkForEvent_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateLandmarkForEventPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        EventData.serialize(buffer);
        InventoryBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        EventData.deserialize(buffer);
        InventoryBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateLandmarkForEventPacket();
    }
};

// EventLocationRequestPacket
class EventLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableU32 EventID;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EventID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EventID.deserialize(buffer);
        }
    };
    // EventLocationRequestPacket Member List
    QueryDataBlock QueryData;
    EventDataBlock EventData;

public:
    EventLocationRequestPacket() {
        this->setID(EventLocationRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EventLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        QueryData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        QueryData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventLocationRequestPacket();
    }
};

// EventLocationReplyPacket
class EventLocationReplyPacket : public PacketBase {
public:

    // Block Class List
    class QueryDataBlock : public PacketSerializable {
    public:
        // QueryDataBlock Member List
        SerializableUUID QueryID;
    public:
        QueryDataBlock() {};
        virtual ~QueryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            QueryID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            QueryID.deserialize(buffer);
        }
    };
    class EventDataBlock : public PacketSerializable {
    public:
        // EventDataBlock Member List
        SerializableBool Success;
        SerializableUUID RegionID;
        SerializableVector3 RegionPos;
    public:
        EventDataBlock() {};
        virtual ~EventDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Success.serialize(buffer);
            RegionID.serialize(buffer);
            RegionPos.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Success.deserialize(buffer);
            RegionID.deserialize(buffer);
            RegionPos.deserialize(buffer);
        }
    };
    // EventLocationReplyPacket Member List
    QueryDataBlock QueryData;
    EventDataBlock EventData;

public:
    EventLocationReplyPacket() {
        this->setID(EventLocationReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~EventLocationReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        QueryData.serialize(buffer);
        EventData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        QueryData.deserialize(buffer);
        EventData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EventLocationReplyPacket();
    }
};

// RegionHandleRequestPacket
class RegionHandleRequestPacket : public PacketBase {
public:

    // Block Class List
    class RequestBlockBlock : public PacketSerializable {
    public:
        // RequestBlockBlock Member List
        SerializableUUID RegionID;
    public:
        RequestBlockBlock() {};
        virtual ~RequestBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
        }
    };
    // RegionHandleRequestPacket Member List
    RequestBlockBlock RequestBlock;

public:
    RegionHandleRequestPacket() {
        this->setID(RegionHandleRequest_ID);
    };
    virtual ~RegionHandleRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RequestBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RequestBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionHandleRequestPacket();
    }
};

// RegionIDAndHandleReplyPacket
class RegionIDAndHandleReplyPacket : public PacketBase {
public:

    // Block Class List
    class ReplyBlockBlock : public PacketSerializable {
    public:
        // ReplyBlockBlock Member List
        SerializableUUID RegionID;
        SerializableU64 RegionHandle;
    public:
        ReplyBlockBlock() {};
        virtual ~ReplyBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionID.serialize(buffer);
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionID.deserialize(buffer);
            RegionHandle.deserialize(buffer);
        }
    };
    // RegionIDAndHandleReplyPacket Member List
    ReplyBlockBlock ReplyBlock;

public:
    RegionIDAndHandleReplyPacket() {
        this->setID(RegionIDAndHandleReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RegionIDAndHandleReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ReplyBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ReplyBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RegionIDAndHandleReplyPacket();
    }
};

// MoneyTransferRequestPacket
class MoneyTransferRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableU8 Flags;
        SerializableS32 Amount;
        SerializableU8 AggregatePermNextOwner;
        SerializableU8 AggregatePermInventory;
        SerializableS32 TransactionType;
        SerializableVariable1 Description;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            Flags.serialize(buffer);
            Amount.serialize(buffer);
            AggregatePermNextOwner.serialize(buffer);
            AggregatePermInventory.serialize(buffer);
            TransactionType.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            Flags.deserialize(buffer);
            Amount.deserialize(buffer);
            AggregatePermNextOwner.deserialize(buffer);
            AggregatePermInventory.deserialize(buffer);
            TransactionType.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // MoneyTransferRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    MoneyTransferRequestPacket() {
        this->setID(MoneyTransferRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyTransferRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyTransferRequestPacket();
    }
};

// MoneyTransferBackendPacket
class MoneyTransferBackendPacket : public PacketBase {
public:

    // Block Class List
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID TransactionID;
        SerializableU32 TransactionTime;
        SerializableUUID SourceID;
        SerializableUUID DestID;
        SerializableU8 Flags;
        SerializableS32 Amount;
        SerializableU8 AggregatePermNextOwner;
        SerializableU8 AggregatePermInventory;
        SerializableS32 TransactionType;
        SerializableUUID RegionID;
        SerializableU32 GridX;
        SerializableU32 GridY;
        SerializableVariable1 Description;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            TransactionTime.serialize(buffer);
            SourceID.serialize(buffer);
            DestID.serialize(buffer);
            Flags.serialize(buffer);
            Amount.serialize(buffer);
            AggregatePermNextOwner.serialize(buffer);
            AggregatePermInventory.serialize(buffer);
            TransactionType.serialize(buffer);
            RegionID.serialize(buffer);
            GridX.serialize(buffer);
            GridY.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            TransactionTime.deserialize(buffer);
            SourceID.deserialize(buffer);
            DestID.deserialize(buffer);
            Flags.deserialize(buffer);
            Amount.deserialize(buffer);
            AggregatePermNextOwner.deserialize(buffer);
            AggregatePermInventory.deserialize(buffer);
            TransactionType.deserialize(buffer);
            RegionID.deserialize(buffer);
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // MoneyTransferBackendPacket Member List
    MoneyDataBlock MoneyData;

public:
    MoneyTransferBackendPacket() {
        this->setID(MoneyTransferBackend_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyTransferBackendPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyTransferBackendPacket();
    }
};

// MoneyBalanceRequestPacket
class MoneyBalanceRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID TransactionID;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // MoneyBalanceRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    MoneyBalanceRequestPacket() {
        this->setID(MoneyBalanceRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyBalanceRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyBalanceRequestPacket();
    }
};

// MoneyBalanceReplyPacket
class MoneyBalanceReplyPacket : public PacketBase {
public:

    // Block Class List
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID TransactionID;
        SerializableBool TransactionSuccess;
        SerializableS32 MoneyBalance;
        SerializableS32 SquareMetersCredit;
        SerializableS32 SquareMetersCommitted;
        SerializableVariable1 Description;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TransactionID.serialize(buffer);
            TransactionSuccess.serialize(buffer);
            MoneyBalance.serialize(buffer);
            SquareMetersCredit.serialize(buffer);
            SquareMetersCommitted.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            TransactionSuccess.deserialize(buffer);
            MoneyBalance.deserialize(buffer);
            SquareMetersCredit.deserialize(buffer);
            SquareMetersCommitted.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // MoneyBalanceReplyPacket Member List
    MoneyDataBlock MoneyData;

public:
    MoneyBalanceReplyPacket() {
        this->setID(MoneyBalanceReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~MoneyBalanceReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MoneyBalanceReplyPacket();
    }
};

// RoutedMoneyBalanceReplyPacket
class RoutedMoneyBalanceReplyPacket : public PacketBase {
public:

    // Block Class List
    class TargetBlockBlock : public PacketSerializable {
    public:
        // TargetBlockBlock Member List
        SerializableIPADDR TargetIP;
        SerializableIPPORT TargetPort;
    public:
        TargetBlockBlock() {};
        virtual ~TargetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetIP.serialize(buffer);
            TargetPort.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetIP.deserialize(buffer);
            TargetPort.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID TransactionID;
        SerializableBool TransactionSuccess;
        SerializableS32 MoneyBalance;
        SerializableS32 SquareMetersCredit;
        SerializableS32 SquareMetersCommitted;
        SerializableVariable1 Description;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            TransactionID.serialize(buffer);
            TransactionSuccess.serialize(buffer);
            MoneyBalance.serialize(buffer);
            SquareMetersCredit.serialize(buffer);
            SquareMetersCommitted.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            TransactionID.deserialize(buffer);
            TransactionSuccess.deserialize(buffer);
            MoneyBalance.deserialize(buffer);
            SquareMetersCredit.deserialize(buffer);
            SquareMetersCommitted.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // RoutedMoneyBalanceReplyPacket Member List
    TargetBlockBlock TargetBlock;
    MoneyDataBlock MoneyData;

public:
    RoutedMoneyBalanceReplyPacket() {
        this->setID(RoutedMoneyBalanceReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RoutedMoneyBalanceReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TargetBlock.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TargetBlock.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RoutedMoneyBalanceReplyPacket();
    }
};

// ActivateGesturesPacket
class ActivateGesturesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID AssetID;
        SerializableU32 GestureFlags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            AssetID.serialize(buffer);
            GestureFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            AssetID.deserialize(buffer);
            GestureFlags.deserialize(buffer);
        }
    };
    // ActivateGesturesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    ActivateGesturesPacket() {
        this->setID(ActivateGestures_ID);
    };
    virtual ~ActivateGesturesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ActivateGesturesPacket();
    }
};

// DeactivateGesturesPacket
class DeactivateGesturesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID ItemID;
        SerializableU32 GestureFlags;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            GestureFlags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            GestureFlags.deserialize(buffer);
        }
    };
    // DeactivateGesturesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    DeactivateGesturesPacket() {
        this->setID(DeactivateGestures_ID);
    };
    virtual ~DeactivateGesturesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DeactivateGesturesPacket();
    }
};

// MuteListUpdatePacket
class MuteListUpdatePacket : public PacketBase {
public:

    // Block Class List
    class MuteDataBlock : public PacketSerializable {
    public:
        // MuteDataBlock Member List
        SerializableUUID AgentID;
        SerializableVariable1 Filename;
    public:
        MuteDataBlock() {};
        virtual ~MuteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Filename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Filename.deserialize(buffer);
        }
    };
    // MuteListUpdatePacket Member List
    MuteDataBlock MuteData;

public:
    MuteListUpdatePacket() {
        this->setID(MuteListUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~MuteListUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MuteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MuteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MuteListUpdatePacket();
    }
};

// UseCachedMuteListPacket
class UseCachedMuteListPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // UseCachedMuteListPacket Member List
    AgentDataBlock AgentData;

public:
    UseCachedMuteListPacket() {
        this->setID(UseCachedMuteList_ID);
    };
    virtual ~UseCachedMuteListPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UseCachedMuteListPacket();
    }
};

// GrantUserRightsPacket
class GrantUserRightsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RightsBlock : public PacketSerializable {
    public:
        // RightsBlock Member List
        SerializableUUID AgentRelated;
        SerializableS32 RelatedRights;
    public:
        RightsBlock() {};
        virtual ~RightsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentRelated.serialize(buffer);
            RelatedRights.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentRelated.deserialize(buffer);
            RelatedRights.deserialize(buffer);
        }
    };
    // GrantUserRightsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RightsBlock> Rights;

public:
    GrantUserRightsPacket() {
        this->setID(GrantUserRights_ID);
    };
    virtual ~GrantUserRightsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Rights.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Rights.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GrantUserRightsPacket();
    }
};

// ChangeUserRightsPacket
class ChangeUserRightsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class RightsBlock : public PacketSerializable {
    public:
        // RightsBlock Member List
        SerializableUUID AgentRelated;
        SerializableS32 RelatedRights;
    public:
        RightsBlock() {};
        virtual ~RightsBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentRelated.serialize(buffer);
            RelatedRights.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentRelated.deserialize(buffer);
            RelatedRights.deserialize(buffer);
        }
    };
    // ChangeUserRightsPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RightsBlock> Rights;

public:
    ChangeUserRightsPacket() {
        this->setID(ChangeUserRights_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ChangeUserRightsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Rights.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Rights.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ChangeUserRightsPacket();
    }
};

// OnlineNotificationPacket
class OnlineNotificationPacket : public PacketBase {
public:

    // Block Class List
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID AgentID;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // OnlineNotificationPacket Member List
    VariableSerializable<AgentBlockBlock> AgentBlock;

public:
    OnlineNotificationPacket() {
        this->setID(OnlineNotification_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~OnlineNotificationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OnlineNotificationPacket();
    }
};

// OfflineNotificationPacket
class OfflineNotificationPacket : public PacketBase {
public:

    // Block Class List
    class AgentBlockBlock : public PacketSerializable {
    public:
        // AgentBlockBlock Member List
        SerializableUUID AgentID;
    public:
        AgentBlockBlock() {};
        virtual ~AgentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // OfflineNotificationPacket Member List
    VariableSerializable<AgentBlockBlock> AgentBlock;

public:
    OfflineNotificationPacket() {
        this->setID(OfflineNotification_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~OfflineNotificationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new OfflineNotificationPacket();
    }
};

// SetStartLocationRequestPacket
class SetStartLocationRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class StartLocationDataBlock : public PacketSerializable {
    public:
        // StartLocationDataBlock Member List
        SerializableVariable1 SimName;
        SerializableU32 LocationID;
        SerializableVector3 LocationPos;
        SerializableVector3 LocationLookAt;
    public:
        StartLocationDataBlock() {};
        virtual ~StartLocationDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimName.serialize(buffer);
            LocationID.serialize(buffer);
            LocationPos.serialize(buffer);
            LocationLookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimName.deserialize(buffer);
            LocationID.deserialize(buffer);
            LocationPos.deserialize(buffer);
            LocationLookAt.deserialize(buffer);
        }
    };
    // SetStartLocationRequestPacket Member List
    AgentDataBlock AgentData;
    StartLocationDataBlock StartLocationData;

public:
    SetStartLocationRequestPacket() {
        this->setID(SetStartLocationRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~SetStartLocationRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        StartLocationData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        StartLocationData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetStartLocationRequestPacket();
    }
};

// SetStartLocationPacket
class SetStartLocationPacket : public PacketBase {
public:

    // Block Class List
    class StartLocationDataBlock : public PacketSerializable {
    public:
        // StartLocationDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID RegionID;
        SerializableU32 LocationID;
        SerializableU64 RegionHandle;
        SerializableVector3 LocationPos;
        SerializableVector3 LocationLookAt;
    public:
        StartLocationDataBlock() {};
        virtual ~StartLocationDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            RegionID.serialize(buffer);
            LocationID.serialize(buffer);
            RegionHandle.serialize(buffer);
            LocationPos.serialize(buffer);
            LocationLookAt.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            RegionID.deserialize(buffer);
            LocationID.deserialize(buffer);
            RegionHandle.deserialize(buffer);
            LocationPos.deserialize(buffer);
            LocationLookAt.deserialize(buffer);
        }
    };
    // SetStartLocationPacket Member List
    StartLocationDataBlock StartLocationData;

public:
    SetStartLocationPacket() {
        this->setID(SetStartLocation_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~SetStartLocationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        StartLocationData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        StartLocationData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetStartLocationPacket();
    }
};

// NetTestPacket
class NetTestPacket : public PacketBase {
public:

    // Block Class List
    class NetBlockBlock : public PacketSerializable {
    public:
        // NetBlockBlock Member List
        SerializableIPPORT Port;
    public:
        NetBlockBlock() {};
        virtual ~NetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Port.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Port.deserialize(buffer);
        }
    };
    // NetTestPacket Member List
    NetBlockBlock NetBlock;

public:
    NetTestPacket() {
        this->setID(NetTest_ID);
    };
    virtual ~NetTestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        NetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        NetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NetTestPacket();
    }
};

// SetCPURatioPacket
class SetCPURatioPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU8 Ratio;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Ratio.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Ratio.deserialize(buffer);
        }
    };
    // SetCPURatioPacket Member List
    DataBlock Data;

public:
    SetCPURatioPacket() {
        this->setID(SetCPURatio_ID);
    };
    virtual ~SetCPURatioPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetCPURatioPacket();
    }
};

// SimCrashedPacket
class SimCrashedPacket : public PacketBase {
public:

    // Block Class List
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 RegionX;
        SerializableU32 RegionY;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RegionX.serialize(buffer);
            RegionY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RegionX.deserialize(buffer);
            RegionY.deserialize(buffer);
        }
    };
    class UsersBlock : public PacketSerializable {
    public:
        // UsersBlock Member List
        SerializableUUID AgentID;
    public:
        UsersBlock() {};
        virtual ~UsersBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    // SimCrashedPacket Member List
    DataBlock Data;
    VariableSerializable<UsersBlock> Users;

public:
    SimCrashedPacket() {
        this->setID(SimCrashed_ID);
    };
    virtual ~SimCrashedPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        Data.serialize(buffer);
        Users.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        Data.deserialize(buffer);
        Users.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SimCrashedPacket();
    }
};

// NameValuePairPacket
class NameValuePairPacket : public PacketBase {
public:

    // Block Class List
    class TaskDataBlock : public PacketSerializable {
    public:
        // TaskDataBlock Member List
        SerializableUUID ID;
    public:
        TaskDataBlock() {};
        virtual ~TaskDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    class NameValueDataBlock : public PacketSerializable {
    public:
        // NameValueDataBlock Member List
        SerializableVariable2 NVPair;
    public:
        NameValueDataBlock() {};
        virtual ~NameValueDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NVPair.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NVPair.deserialize(buffer);
        }
    };
    // NameValuePairPacket Member List
    TaskDataBlock TaskData;
    VariableSerializable<NameValueDataBlock> NameValueData;

public:
    NameValuePairPacket() {
        this->setID(NameValuePair_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~NameValuePairPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TaskData.serialize(buffer);
        NameValueData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TaskData.deserialize(buffer);
        NameValueData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new NameValuePairPacket();
    }
};

// RemoveNameValuePairPacket
class RemoveNameValuePairPacket : public PacketBase {
public:

    // Block Class List
    class TaskDataBlock : public PacketSerializable {
    public:
        // TaskDataBlock Member List
        SerializableUUID ID;
    public:
        TaskDataBlock() {};
        virtual ~TaskDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
        }
    };
    class NameValueDataBlock : public PacketSerializable {
    public:
        // NameValueDataBlock Member List
        SerializableVariable2 NVPair;
    public:
        NameValueDataBlock() {};
        virtual ~NameValueDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NVPair.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NVPair.deserialize(buffer);
        }
    };
    // RemoveNameValuePairPacket Member List
    TaskDataBlock TaskData;
    VariableSerializable<NameValueDataBlock> NameValueData;

public:
    RemoveNameValuePairPacket() {
        this->setID(RemoveNameValuePair_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RemoveNameValuePairPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TaskData.serialize(buffer);
        NameValueData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TaskData.deserialize(buffer);
        NameValueData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveNameValuePairPacket();
    }
};

// UpdateAttachmentPacket
class UpdateAttachmentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AttachmentBlockBlock : public PacketSerializable {
    public:
        // AttachmentBlockBlock Member List
        SerializableU8 AttachmentPoint;
    public:
        AttachmentBlockBlock() {};
        virtual ~AttachmentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AttachmentPoint.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AttachmentPoint.deserialize(buffer);
        }
    };
    class OperationDataBlock : public PacketSerializable {
    public:
        // OperationDataBlock Member List
        SerializableBool AddItem;
        SerializableBool UseExistingAsset;
    public:
        OperationDataBlock() {};
        virtual ~OperationDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AddItem.serialize(buffer);
            UseExistingAsset.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AddItem.deserialize(buffer);
            UseExistingAsset.deserialize(buffer);
        }
    };
    class InventoryDataBlock : public PacketSerializable {
    public:
        // InventoryDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID FolderID;
        SerializableUUID CreatorID;
        SerializableUUID OwnerID;
        SerializableUUID GroupID;
        SerializableU32 BaseMask;
        SerializableU32 OwnerMask;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableBool GroupOwned;
        SerializableUUID AssetID;
        SerializableS8 Type;
        SerializableS8 InvType;
        SerializableU32 Flags;
        SerializableU8 SaleType;
        SerializableS32 SalePrice;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableS32 CreationDate;
        SerializableU32 CRC;
    public:
        InventoryDataBlock() {};
        virtual ~InventoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            FolderID.serialize(buffer);
            CreatorID.serialize(buffer);
            OwnerID.serialize(buffer);
            GroupID.serialize(buffer);
            BaseMask.serialize(buffer);
            OwnerMask.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            GroupOwned.serialize(buffer);
            AssetID.serialize(buffer);
            Type.serialize(buffer);
            InvType.serialize(buffer);
            Flags.serialize(buffer);
            SaleType.serialize(buffer);
            SalePrice.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            CreationDate.serialize(buffer);
            CRC.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            FolderID.deserialize(buffer);
            CreatorID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            GroupID.deserialize(buffer);
            BaseMask.deserialize(buffer);
            OwnerMask.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            GroupOwned.deserialize(buffer);
            AssetID.deserialize(buffer);
            Type.deserialize(buffer);
            InvType.deserialize(buffer);
            Flags.deserialize(buffer);
            SaleType.deserialize(buffer);
            SalePrice.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            CreationDate.deserialize(buffer);
            CRC.deserialize(buffer);
        }
    };
    // UpdateAttachmentPacket Member List
    AgentDataBlock AgentData;
    AttachmentBlockBlock AttachmentBlock;
    OperationDataBlock OperationData;
    InventoryDataBlock InventoryData;

public:
    UpdateAttachmentPacket() {
        this->setID(UpdateAttachment_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateAttachmentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AttachmentBlock.serialize(buffer);
        OperationData.serialize(buffer);
        InventoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AttachmentBlock.deserialize(buffer);
        OperationData.deserialize(buffer);
        InventoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateAttachmentPacket();
    }
};

// RemoveAttachmentPacket
class RemoveAttachmentPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class AttachmentBlockBlock : public PacketSerializable {
    public:
        // AttachmentBlockBlock Member List
        SerializableU8 AttachmentPoint;
        SerializableUUID ItemID;
    public:
        AttachmentBlockBlock() {};
        virtual ~AttachmentBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AttachmentPoint.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AttachmentPoint.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RemoveAttachmentPacket Member List
    AgentDataBlock AgentData;
    AttachmentBlockBlock AttachmentBlock;

public:
    RemoveAttachmentPacket() {
        this->setID(RemoveAttachment_ID);
    };
    virtual ~RemoveAttachmentPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        AttachmentBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        AttachmentBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RemoveAttachmentPacket();
    }
};

// SoundTriggerPacket
class SoundTriggerPacket : public PacketBase {
public:

    // Block Class List
    class SoundDataBlock : public PacketSerializable {
    public:
        // SoundDataBlock Member List
        SerializableUUID SoundID;
        SerializableUUID OwnerID;
        SerializableUUID ObjectID;
        SerializableUUID ParentID;
        SerializableU64 Handle;
        SerializableVector3 Position;
        SerializableF32 Gain;
    public:
        SoundDataBlock() {};
        virtual ~SoundDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SoundID.serialize(buffer);
            OwnerID.serialize(buffer);
            ObjectID.serialize(buffer);
            ParentID.serialize(buffer);
            Handle.serialize(buffer);
            Position.serialize(buffer);
            Gain.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SoundID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            ParentID.deserialize(buffer);
            Handle.deserialize(buffer);
            Position.deserialize(buffer);
            Gain.deserialize(buffer);
        }
    };
    // SoundTriggerPacket Member List
    SoundDataBlock SoundData;

public:
    SoundTriggerPacket() {
        this->setID(SoundTrigger_ID);
    };
    virtual ~SoundTriggerPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        SoundData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        SoundData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SoundTriggerPacket();
    }
};

// AttachedSoundPacket
class AttachedSoundPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID SoundID;
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableF32 Gain;
        SerializableU8 Flags;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SoundID.serialize(buffer);
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            Gain.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SoundID.deserialize(buffer);
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            Gain.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // AttachedSoundPacket Member List
    DataBlockBlock DataBlock;

public:
    AttachedSoundPacket() {
        this->setID(AttachedSound_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AttachedSoundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AttachedSoundPacket();
    }
};

// AttachedSoundGainChangePacket
class AttachedSoundGainChangePacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID ObjectID;
        SerializableF32 Gain;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            Gain.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            Gain.deserialize(buffer);
        }
    };
    // AttachedSoundGainChangePacket Member List
    DataBlockBlock DataBlock;

public:
    AttachedSoundGainChangePacket() {
        this->setID(AttachedSoundGainChange_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AttachedSoundGainChangePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AttachedSoundGainChangePacket();
    }
};

// PreloadSoundPacket
class PreloadSoundPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID ObjectID;
        SerializableUUID OwnerID;
        SerializableUUID SoundID;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            OwnerID.serialize(buffer);
            SoundID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            SoundID.deserialize(buffer);
        }
    };
    // PreloadSoundPacket Member List
    VariableSerializable<DataBlockBlock> DataBlock;

public:
    PreloadSoundPacket() {
        this->setID(PreloadSound_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~PreloadSoundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new PreloadSoundPacket();
    }
};

// AssetUploadRequestPacket
class AssetUploadRequestPacket : public PacketBase {
public:

    // Block Class List
    class AssetBlockBlock : public PacketSerializable {
    public:
        // AssetBlockBlock Member List
        SerializableUUID TransactionID;
        SerializableS8 Type;
        SerializableBool Tempfile;
        SerializableBool StoreLocal;
        SerializableVariable2 AssetData;
    public:
        AssetBlockBlock() {};
        virtual ~AssetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            Type.serialize(buffer);
            Tempfile.serialize(buffer);
            StoreLocal.serialize(buffer);
            AssetData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            Type.deserialize(buffer);
            Tempfile.deserialize(buffer);
            StoreLocal.deserialize(buffer);
            AssetData.deserialize(buffer);
        }
    };
    // AssetUploadRequestPacket Member List
    AssetBlockBlock AssetBlock;

public:
    AssetUploadRequestPacket() {
        this->setID(AssetUploadRequest_ID);
    };
    virtual ~AssetUploadRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AssetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AssetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AssetUploadRequestPacket();
    }
};

// AssetUploadCompletePacket
class AssetUploadCompletePacket : public PacketBase {
public:

    // Block Class List
    class AssetBlockBlock : public PacketSerializable {
    public:
        // AssetBlockBlock Member List
        SerializableUUID UUID;
        SerializableS8 Type;
        SerializableBool Success;
    public:
        AssetBlockBlock() {};
        virtual ~AssetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            UUID.serialize(buffer);
            Type.serialize(buffer);
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            UUID.deserialize(buffer);
            Type.deserialize(buffer);
            Success.deserialize(buffer);
        }
    };
    // AssetUploadCompletePacket Member List
    AssetBlockBlock AssetBlock;

public:
    AssetUploadCompletePacket() {
        this->setID(AssetUploadComplete_ID);
    };
    virtual ~AssetUploadCompletePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AssetBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AssetBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AssetUploadCompletePacket();
    }
};

// EmailMessageRequestPacket
class EmailMessageRequestPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID ObjectID;
        SerializableVariable1 FromAddress;
        SerializableVariable1 Subject;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            FromAddress.serialize(buffer);
            Subject.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            FromAddress.deserialize(buffer);
            Subject.deserialize(buffer);
        }
    };
    // EmailMessageRequestPacket Member List
    DataBlockBlock DataBlock;

public:
    EmailMessageRequestPacket() {
        this->setID(EmailMessageRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EmailMessageRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EmailMessageRequestPacket();
    }
};

// EmailMessageReplyPacket
class EmailMessageReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID ObjectID;
        SerializableU32 More;
        SerializableU32 Time;
        SerializableVariable1 FromAddress;
        SerializableVariable1 Subject;
        SerializableVariable2 Data;
        SerializableVariable1 MailFilter;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectID.serialize(buffer);
            More.serialize(buffer);
            Time.serialize(buffer);
            FromAddress.serialize(buffer);
            Subject.serialize(buffer);
            Data.serialize(buffer);
            MailFilter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectID.deserialize(buffer);
            More.deserialize(buffer);
            Time.deserialize(buffer);
            FromAddress.deserialize(buffer);
            Subject.deserialize(buffer);
            Data.deserialize(buffer);
            MailFilter.deserialize(buffer);
        }
    };
    // EmailMessageReplyPacket Member List
    DataBlockBlock DataBlock;

public:
    EmailMessageReplyPacket() {
        this->setID(EmailMessageReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EmailMessageReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EmailMessageReplyPacket();
    }
};

// InternalScriptMailPacket
class InternalScriptMailPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableVariable1 From;
        SerializableUUID To;
        SerializableVariable1 Subject;
        SerializableVariable2 Body;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            From.serialize(buffer);
            To.serialize(buffer);
            Subject.serialize(buffer);
            Body.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            From.deserialize(buffer);
            To.deserialize(buffer);
            Subject.deserialize(buffer);
            Body.deserialize(buffer);
        }
    };
    // InternalScriptMailPacket Member List
    DataBlockBlock DataBlock;

public:
    InternalScriptMailPacket() {
        this->setID(InternalScriptMail_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~InternalScriptMailPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InternalScriptMailPacket();
    }
};

// ScriptDataRequestPacket
class ScriptDataRequestPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableU64 Hash;
        SerializableS8 RequestType;
        SerializableVariable2 Request;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Hash.serialize(buffer);
            RequestType.serialize(buffer);
            Request.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Hash.deserialize(buffer);
            RequestType.deserialize(buffer);
            Request.deserialize(buffer);
        }
    };
    // ScriptDataRequestPacket Member List
    VariableSerializable<DataBlockBlock> DataBlock;

public:
    ScriptDataRequestPacket() {
        this->setID(ScriptDataRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptDataRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptDataRequestPacket();
    }
};

// ScriptDataReplyPacket
class ScriptDataReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableU64 Hash;
        SerializableVariable2 Reply;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Hash.serialize(buffer);
            Reply.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Hash.deserialize(buffer);
            Reply.deserialize(buffer);
        }
    };
    // ScriptDataReplyPacket Member List
    VariableSerializable<DataBlockBlock> DataBlock;

public:
    ScriptDataReplyPacket() {
        this->setID(ScriptDataReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptDataReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptDataReplyPacket();
    }
};

// CreateGroupRequestPacket
class CreateGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableVariable1 Name;
        SerializableVariable2 Charter;
        SerializableBool ShowInList;
        SerializableUUID InsigniaID;
        SerializableS32 MembershipFee;
        SerializableBool OpenEnrollment;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
            Charter.serialize(buffer);
            ShowInList.serialize(buffer);
            InsigniaID.serialize(buffer);
            MembershipFee.serialize(buffer);
            OpenEnrollment.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
            Charter.deserialize(buffer);
            ShowInList.deserialize(buffer);
            InsigniaID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
            OpenEnrollment.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // CreateGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    CreateGroupRequestPacket() {
        this->setID(CreateGroupRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~CreateGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateGroupRequestPacket();
    }
};

// CreateGroupReplyPacket
class CreateGroupReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class ReplyDataBlock : public PacketSerializable {
    public:
        // ReplyDataBlock Member List
        SerializableUUID GroupID;
        SerializableBool Success;
        SerializableVariable1 Message;
    public:
        ReplyDataBlock() {};
        virtual ~ReplyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Success.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Success.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // CreateGroupReplyPacket Member List
    AgentDataBlock AgentData;
    ReplyDataBlock ReplyData;

public:
    CreateGroupReplyPacket() {
        this->setID(CreateGroupReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~CreateGroupReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ReplyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ReplyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateGroupReplyPacket();
    }
};

// UpdateGroupInfoPacket
class UpdateGroupInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableVariable2 Charter;
        SerializableBool ShowInList;
        SerializableUUID InsigniaID;
        SerializableS32 MembershipFee;
        SerializableBool OpenEnrollment;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Charter.serialize(buffer);
            ShowInList.serialize(buffer);
            InsigniaID.serialize(buffer);
            MembershipFee.serialize(buffer);
            OpenEnrollment.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Charter.deserialize(buffer);
            ShowInList.deserialize(buffer);
            InsigniaID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
            OpenEnrollment.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // UpdateGroupInfoPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    UpdateGroupInfoPacket() {
        this->setID(UpdateGroupInfo_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~UpdateGroupInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateGroupInfoPacket();
    }
};

// GroupRoleChangesPacket
class GroupRoleChangesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RoleChangeBlock : public PacketSerializable {
    public:
        // RoleChangeBlock Member List
        SerializableUUID RoleID;
        SerializableUUID MemberID;
        SerializableU32 Change;
    public:
        RoleChangeBlock() {};
        virtual ~RoleChangeBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            MemberID.serialize(buffer);
            Change.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            MemberID.deserialize(buffer);
            Change.deserialize(buffer);
        }
    };
    // GroupRoleChangesPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RoleChangeBlock> RoleChange;

public:
    GroupRoleChangesPacket() {
        this->setID(GroupRoleChanges_ID);
    };
    virtual ~GroupRoleChangesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RoleChange.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RoleChange.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleChangesPacket();
    }
};

// JoinGroupRequestPacket
class JoinGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // JoinGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    JoinGroupRequestPacket() {
        this->setID(JoinGroupRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~JoinGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new JoinGroupRequestPacket();
    }
};

// JoinGroupReplyPacket
class JoinGroupReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableBool Success;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Success.deserialize(buffer);
        }
    };
    // JoinGroupReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    JoinGroupReplyPacket() {
        this->setID(JoinGroupReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~JoinGroupReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new JoinGroupReplyPacket();
    }
};

// EjectGroupMemberRequestPacket
class EjectGroupMemberRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class EjectDataBlock : public PacketSerializable {
    public:
        // EjectDataBlock Member List
        SerializableUUID EjecteeID;
    public:
        EjectDataBlock() {};
        virtual ~EjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EjecteeID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EjecteeID.deserialize(buffer);
        }
    };
    // EjectGroupMemberRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<EjectDataBlock> EjectData;

public:
    EjectGroupMemberRequestPacket() {
        this->setID(EjectGroupMemberRequest_ID);
    };
    virtual ~EjectGroupMemberRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        EjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        EjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EjectGroupMemberRequestPacket();
    }
};

// EjectGroupMemberReplyPacket
class EjectGroupMemberReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class EjectDataBlock : public PacketSerializable {
    public:
        // EjectDataBlock Member List
        SerializableBool Success;
    public:
        EjectDataBlock() {};
        virtual ~EjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Success.deserialize(buffer);
        }
    };
    // EjectGroupMemberReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    EjectDataBlock EjectData;

public:
    EjectGroupMemberReplyPacket() {
        this->setID(EjectGroupMemberReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~EjectGroupMemberReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        EjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        EjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new EjectGroupMemberReplyPacket();
    }
};

// LeaveGroupRequestPacket
class LeaveGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // LeaveGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    LeaveGroupRequestPacket() {
        this->setID(LeaveGroupRequest_ID);
    };
    virtual ~LeaveGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LeaveGroupRequestPacket();
    }
};

// LeaveGroupReplyPacket
class LeaveGroupReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableBool Success;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Success.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Success.deserialize(buffer);
        }
    };
    // LeaveGroupReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    LeaveGroupReplyPacket() {
        this->setID(LeaveGroupReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LeaveGroupReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LeaveGroupReplyPacket();
    }
};

// InviteGroupRequestPacket
class InviteGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class InviteDataBlock : public PacketSerializable {
    public:
        // InviteDataBlock Member List
        SerializableUUID InviteeID;
        SerializableUUID RoleID;
    public:
        InviteDataBlock() {};
        virtual ~InviteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            InviteeID.serialize(buffer);
            RoleID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            InviteeID.deserialize(buffer);
            RoleID.deserialize(buffer);
        }
    };
    // InviteGroupRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<InviteDataBlock> InviteData;

public:
    InviteGroupRequestPacket() {
        this->setID(InviteGroupRequest_ID);
    };
    virtual ~InviteGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        InviteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        InviteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InviteGroupRequestPacket();
    }
};

// InviteGroupResponsePacket
class InviteGroupResponsePacket : public PacketBase {
public:

    // Block Class List
    class InviteDataBlock : public PacketSerializable {
    public:
        // InviteDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID InviteeID;
        SerializableUUID GroupID;
        SerializableUUID RoleID;
        SerializableS32 MembershipFee;
    public:
        InviteDataBlock() {};
        virtual ~InviteDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            InviteeID.serialize(buffer);
            GroupID.serialize(buffer);
            RoleID.serialize(buffer);
            MembershipFee.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            InviteeID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RoleID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
        }
    };
    // InviteGroupResponsePacket Member List
    InviteDataBlock InviteData;

public:
    InviteGroupResponsePacket() {
        this->setID(InviteGroupResponse_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~InviteGroupResponsePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        InviteData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        InviteData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InviteGroupResponsePacket();
    }
};

// GroupProfileRequestPacket
class GroupProfileRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    // GroupProfileRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupProfileRequestPacket() {
        this->setID(GroupProfileRequest_ID);
    };
    virtual ~GroupProfileRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupProfileRequestPacket();
    }
};

// GroupProfileReplyPacket
class GroupProfileReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableVariable1 Name;
        SerializableVariable2 Charter;
        SerializableBool ShowInList;
        SerializableVariable1 MemberTitle;
        SerializableU64 PowersMask;
        SerializableUUID InsigniaID;
        SerializableUUID FounderID;
        SerializableS32 MembershipFee;
        SerializableBool OpenEnrollment;
        SerializableS32 Money;
        SerializableS32 GroupMembershipCount;
        SerializableS32 GroupRolesCount;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
        SerializableUUID OwnerRole;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Name.serialize(buffer);
            Charter.serialize(buffer);
            ShowInList.serialize(buffer);
            MemberTitle.serialize(buffer);
            PowersMask.serialize(buffer);
            InsigniaID.serialize(buffer);
            FounderID.serialize(buffer);
            MembershipFee.serialize(buffer);
            OpenEnrollment.serialize(buffer);
            Money.serialize(buffer);
            GroupMembershipCount.serialize(buffer);
            GroupRolesCount.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
            OwnerRole.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Name.deserialize(buffer);
            Charter.deserialize(buffer);
            ShowInList.deserialize(buffer);
            MemberTitle.deserialize(buffer);
            PowersMask.deserialize(buffer);
            InsigniaID.deserialize(buffer);
            FounderID.deserialize(buffer);
            MembershipFee.deserialize(buffer);
            OpenEnrollment.deserialize(buffer);
            Money.deserialize(buffer);
            GroupMembershipCount.deserialize(buffer);
            GroupRolesCount.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
            OwnerRole.deserialize(buffer);
        }
    };
    // GroupProfileReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupProfileReplyPacket() {
        this->setID(GroupProfileReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupProfileReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupProfileReplyPacket();
    }
};

// GroupAccountSummaryRequestPacket
class GroupAccountSummaryRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountSummaryRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountSummaryRequestPacket() {
        this->setID(GroupAccountSummaryRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountSummaryRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountSummaryRequestPacket();
    }
};

// GroupAccountSummaryReplyPacket
class GroupAccountSummaryReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
        SerializableVariable1 StartDate;
        SerializableS32 Balance;
        SerializableS32 TotalCredits;
        SerializableS32 TotalDebits;
        SerializableS32 ObjectTaxCurrent;
        SerializableS32 LightTaxCurrent;
        SerializableS32 LandTaxCurrent;
        SerializableS32 GroupTaxCurrent;
        SerializableS32 ParcelDirFeeCurrent;
        SerializableS32 ObjectTaxEstimate;
        SerializableS32 LightTaxEstimate;
        SerializableS32 LandTaxEstimate;
        SerializableS32 GroupTaxEstimate;
        SerializableS32 ParcelDirFeeEstimate;
        SerializableS32 NonExemptMembers;
        SerializableVariable1 LastTaxDate;
        SerializableVariable1 TaxDate;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
            StartDate.serialize(buffer);
            Balance.serialize(buffer);
            TotalCredits.serialize(buffer);
            TotalDebits.serialize(buffer);
            ObjectTaxCurrent.serialize(buffer);
            LightTaxCurrent.serialize(buffer);
            LandTaxCurrent.serialize(buffer);
            GroupTaxCurrent.serialize(buffer);
            ParcelDirFeeCurrent.serialize(buffer);
            ObjectTaxEstimate.serialize(buffer);
            LightTaxEstimate.serialize(buffer);
            LandTaxEstimate.serialize(buffer);
            GroupTaxEstimate.serialize(buffer);
            ParcelDirFeeEstimate.serialize(buffer);
            NonExemptMembers.serialize(buffer);
            LastTaxDate.serialize(buffer);
            TaxDate.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
            StartDate.deserialize(buffer);
            Balance.deserialize(buffer);
            TotalCredits.deserialize(buffer);
            TotalDebits.deserialize(buffer);
            ObjectTaxCurrent.deserialize(buffer);
            LightTaxCurrent.deserialize(buffer);
            LandTaxCurrent.deserialize(buffer);
            GroupTaxCurrent.deserialize(buffer);
            ParcelDirFeeCurrent.deserialize(buffer);
            ObjectTaxEstimate.deserialize(buffer);
            LightTaxEstimate.deserialize(buffer);
            LandTaxEstimate.deserialize(buffer);
            GroupTaxEstimate.deserialize(buffer);
            ParcelDirFeeEstimate.deserialize(buffer);
            NonExemptMembers.deserialize(buffer);
            LastTaxDate.deserialize(buffer);
            TaxDate.deserialize(buffer);
        }
    };
    // GroupAccountSummaryReplyPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountSummaryReplyPacket() {
        this->setID(GroupAccountSummaryReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountSummaryReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountSummaryReplyPacket();
    }
};

// GroupAccountDetailsRequestPacket
class GroupAccountDetailsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountDetailsRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountDetailsRequestPacket() {
        this->setID(GroupAccountDetailsRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountDetailsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountDetailsRequestPacket();
    }
};

// GroupAccountDetailsReplyPacket
class GroupAccountDetailsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
        SerializableVariable1 StartDate;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
            StartDate.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
            StartDate.deserialize(buffer);
        }
    };
    class HistoryDataBlock : public PacketSerializable {
    public:
        // HistoryDataBlock Member List
        SerializableVariable1 Description;
        SerializableS32 Amount;
    public:
        HistoryDataBlock() {};
        virtual ~HistoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Description.serialize(buffer);
            Amount.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Description.deserialize(buffer);
            Amount.deserialize(buffer);
        }
    };
    // GroupAccountDetailsReplyPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
    VariableSerializable<HistoryDataBlock> HistoryData;

public:
    GroupAccountDetailsReplyPacket() {
        this->setID(GroupAccountDetailsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountDetailsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
        HistoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
        HistoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountDetailsReplyPacket();
    }
};

// GroupAccountTransactionsRequestPacket
class GroupAccountTransactionsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
        }
    };
    // GroupAccountTransactionsRequestPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;

public:
    GroupAccountTransactionsRequestPacket() {
        this->setID(GroupAccountTransactionsRequest_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountTransactionsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountTransactionsRequestPacket();
    }
};

// GroupAccountTransactionsReplyPacket
class GroupAccountTransactionsReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class MoneyDataBlock : public PacketSerializable {
    public:
        // MoneyDataBlock Member List
        SerializableUUID RequestID;
        SerializableS32 IntervalDays;
        SerializableS32 CurrentInterval;
        SerializableVariable1 StartDate;
    public:
        MoneyDataBlock() {};
        virtual ~MoneyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            IntervalDays.serialize(buffer);
            CurrentInterval.serialize(buffer);
            StartDate.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            IntervalDays.deserialize(buffer);
            CurrentInterval.deserialize(buffer);
            StartDate.deserialize(buffer);
        }
    };
    class HistoryDataBlock : public PacketSerializable {
    public:
        // HistoryDataBlock Member List
        SerializableVariable1 Time;
        SerializableVariable1 User;
        SerializableS32 Type;
        SerializableVariable1 Item;
        SerializableS32 Amount;
    public:
        HistoryDataBlock() {};
        virtual ~HistoryDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Time.serialize(buffer);
            User.serialize(buffer);
            Type.serialize(buffer);
            Item.serialize(buffer);
            Amount.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Time.deserialize(buffer);
            User.deserialize(buffer);
            Type.deserialize(buffer);
            Item.deserialize(buffer);
            Amount.deserialize(buffer);
        }
    };
    // GroupAccountTransactionsReplyPacket Member List
    AgentDataBlock AgentData;
    MoneyDataBlock MoneyData;
    VariableSerializable<HistoryDataBlock> HistoryData;

public:
    GroupAccountTransactionsReplyPacket() {
        this->setID(GroupAccountTransactionsReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupAccountTransactionsReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MoneyData.serialize(buffer);
        HistoryData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MoneyData.deserialize(buffer);
        HistoryData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupAccountTransactionsReplyPacket();
    }
};

// GroupActiveProposalsRequestPacket
class GroupActiveProposalsRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // GroupActiveProposalsRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;

public:
    GroupActiveProposalsRequestPacket() {
        this->setID(GroupActiveProposalsRequest_ID);
    };
    virtual ~GroupActiveProposalsRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupActiveProposalsRequestPacket();
    }
};

// GroupActiveProposalItemReplyPacket
class GroupActiveProposalItemReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
        SerializableU32 TotalNumItems;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            TotalNumItems.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            TotalNumItems.deserialize(buffer);
        }
    };
    class ProposalDataBlock : public PacketSerializable {
    public:
        // ProposalDataBlock Member List
        SerializableUUID VoteID;
        SerializableUUID VoteInitiator;
        SerializableVariable1 TerseDateID;
        SerializableVariable1 StartDateTime;
        SerializableVariable1 EndDateTime;
        SerializableBool AlreadyVoted;
        SerializableVariable1 VoteCast;
        SerializableF32 Majority;
        SerializableS32 Quorum;
        SerializableVariable1 ProposalText;
    public:
        ProposalDataBlock() {};
        virtual ~ProposalDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            VoteID.serialize(buffer);
            VoteInitiator.serialize(buffer);
            TerseDateID.serialize(buffer);
            StartDateTime.serialize(buffer);
            EndDateTime.serialize(buffer);
            AlreadyVoted.serialize(buffer);
            VoteCast.serialize(buffer);
            Majority.serialize(buffer);
            Quorum.serialize(buffer);
            ProposalText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            VoteID.deserialize(buffer);
            VoteInitiator.deserialize(buffer);
            TerseDateID.deserialize(buffer);
            StartDateTime.deserialize(buffer);
            EndDateTime.deserialize(buffer);
            AlreadyVoted.deserialize(buffer);
            VoteCast.deserialize(buffer);
            Majority.deserialize(buffer);
            Quorum.deserialize(buffer);
            ProposalText.deserialize(buffer);
        }
    };
    // GroupActiveProposalItemReplyPacket Member List
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    VariableSerializable<ProposalDataBlock> ProposalData;

public:
    GroupActiveProposalItemReplyPacket() {
        this->setID(GroupActiveProposalItemReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupActiveProposalItemReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionData.serialize(buffer);
        ProposalData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionData.deserialize(buffer);
        ProposalData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupActiveProposalItemReplyPacket();
    }
};

// GroupVoteHistoryRequestPacket
class GroupVoteHistoryRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
        }
    };
    // GroupVoteHistoryRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    TransactionDataBlock TransactionData;

public:
    GroupVoteHistoryRequestPacket() {
        this->setID(GroupVoteHistoryRequest_ID);
    };
    virtual ~GroupVoteHistoryRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        TransactionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        TransactionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupVoteHistoryRequestPacket();
    }
};

// GroupVoteHistoryItemReplyPacket
class GroupVoteHistoryItemReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class TransactionDataBlock : public PacketSerializable {
    public:
        // TransactionDataBlock Member List
        SerializableUUID TransactionID;
        SerializableU32 TotalNumItems;
    public:
        TransactionDataBlock() {};
        virtual ~TransactionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TransactionID.serialize(buffer);
            TotalNumItems.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TransactionID.deserialize(buffer);
            TotalNumItems.deserialize(buffer);
        }
    };
    class HistoryItemDataBlock : public PacketSerializable {
    public:
        // HistoryItemDataBlock Member List
        SerializableUUID VoteID;
        SerializableVariable1 TerseDateID;
        SerializableVariable1 StartDateTime;
        SerializableVariable1 EndDateTime;
        SerializableUUID VoteInitiator;
        SerializableVariable1 VoteType;
        SerializableVariable1 VoteResult;
        SerializableF32 Majority;
        SerializableS32 Quorum;
        SerializableVariable2 ProposalText;
    public:
        HistoryItemDataBlock() {};
        virtual ~HistoryItemDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            VoteID.serialize(buffer);
            TerseDateID.serialize(buffer);
            StartDateTime.serialize(buffer);
            EndDateTime.serialize(buffer);
            VoteInitiator.serialize(buffer);
            VoteType.serialize(buffer);
            VoteResult.serialize(buffer);
            Majority.serialize(buffer);
            Quorum.serialize(buffer);
            ProposalText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            VoteID.deserialize(buffer);
            TerseDateID.deserialize(buffer);
            StartDateTime.deserialize(buffer);
            EndDateTime.deserialize(buffer);
            VoteInitiator.deserialize(buffer);
            VoteType.deserialize(buffer);
            VoteResult.deserialize(buffer);
            Majority.deserialize(buffer);
            Quorum.deserialize(buffer);
            ProposalText.deserialize(buffer);
        }
    };
    class VoteItemBlock : public PacketSerializable {
    public:
        // VoteItemBlock Member List
        SerializableUUID CandidateID;
        SerializableVariable1 VoteCast;
        SerializableS32 NumVotes;
    public:
        VoteItemBlock() {};
        virtual ~VoteItemBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CandidateID.serialize(buffer);
            VoteCast.serialize(buffer);
            NumVotes.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CandidateID.deserialize(buffer);
            VoteCast.deserialize(buffer);
            NumVotes.deserialize(buffer);
        }
    };
    // GroupVoteHistoryItemReplyPacket Member List
    AgentDataBlock AgentData;
    TransactionDataBlock TransactionData;
    HistoryItemDataBlock HistoryItemData;
    VariableSerializable<VoteItemBlock> VoteItem;

public:
    GroupVoteHistoryItemReplyPacket() {
        this->setID(GroupVoteHistoryItemReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupVoteHistoryItemReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        TransactionData.serialize(buffer);
        HistoryItemData.serialize(buffer);
        VoteItem.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        TransactionData.deserialize(buffer);
        HistoryItemData.deserialize(buffer);
        VoteItem.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupVoteHistoryItemReplyPacket();
    }
};

// StartGroupProposalPacket
class StartGroupProposalPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ProposalDataBlock : public PacketSerializable {
    public:
        // ProposalDataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 Quorum;
        SerializableF32 Majority;
        SerializableS32 Duration;
        SerializableVariable1 ProposalText;
    public:
        ProposalDataBlock() {};
        virtual ~ProposalDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Quorum.serialize(buffer);
            Majority.serialize(buffer);
            Duration.serialize(buffer);
            ProposalText.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Quorum.deserialize(buffer);
            Majority.deserialize(buffer);
            Duration.deserialize(buffer);
            ProposalText.deserialize(buffer);
        }
    };
    // StartGroupProposalPacket Member List
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;

public:
    StartGroupProposalPacket() {
        this->setID(StartGroupProposal_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~StartGroupProposalPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ProposalData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ProposalData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new StartGroupProposalPacket();
    }
};

// GroupProposalBallotPacket
class GroupProposalBallotPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ProposalDataBlock : public PacketSerializable {
    public:
        // ProposalDataBlock Member List
        SerializableUUID ProposalID;
        SerializableUUID GroupID;
        SerializableVariable1 VoteCast;
    public:
        ProposalDataBlock() {};
        virtual ~ProposalDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ProposalID.serialize(buffer);
            GroupID.serialize(buffer);
            VoteCast.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ProposalID.deserialize(buffer);
            GroupID.deserialize(buffer);
            VoteCast.deserialize(buffer);
        }
    };
    // GroupProposalBallotPacket Member List
    AgentDataBlock AgentData;
    ProposalDataBlock ProposalData;

public:
    GroupProposalBallotPacket() {
        this->setID(GroupProposalBallot_ID);
    };
    virtual ~GroupProposalBallotPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ProposalData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ProposalData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupProposalBallotPacket();
    }
};

// TallyVotesPacket
class TallyVotesPacket : public PacketBase {
public:

    // Block Class List
    // TallyVotesPacket Member List

public:
    TallyVotesPacket() {
        this->setID(TallyVotes_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~TallyVotesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new TallyVotesPacket();
    }
};

// GroupMembersRequestPacket
class GroupMembersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupMembersRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupMembersRequestPacket() {
        this->setID(GroupMembersRequest_ID);
    };
    virtual ~GroupMembersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupMembersRequestPacket();
    }
};

// GroupMembersReplyPacket
class GroupMembersReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
        SerializableS32 MemberCount;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
            MemberCount.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
            MemberCount.deserialize(buffer);
        }
    };
    class MemberDataBlock : public PacketSerializable {
    public:
        // MemberDataBlock Member List
        SerializableUUID AgentID;
        SerializableS32 Contribution;
        SerializableVariable1 OnlineStatus;
        SerializableU64 AgentPowers;
        SerializableVariable1 Title;
        SerializableBool IsOwner;
    public:
        MemberDataBlock() {};
        virtual ~MemberDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Contribution.serialize(buffer);
            OnlineStatus.serialize(buffer);
            AgentPowers.serialize(buffer);
            Title.serialize(buffer);
            IsOwner.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Contribution.deserialize(buffer);
            OnlineStatus.deserialize(buffer);
            AgentPowers.deserialize(buffer);
            Title.deserialize(buffer);
            IsOwner.deserialize(buffer);
        }
    };
    // GroupMembersReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<MemberDataBlock> MemberData;

public:
    GroupMembersReplyPacket() {
        this->setID(GroupMembersReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupMembersReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        MemberData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        MemberData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupMembersReplyPacket();
    }
};

// ActivateGroupPacket
class ActivateGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    // ActivateGroupPacket Member List
    AgentDataBlock AgentData;

public:
    ActivateGroupPacket() {
        this->setID(ActivateGroup_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ActivateGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ActivateGroupPacket();
    }
};

// SetGroupContributionPacket
class SetGroupContributionPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableS32 Contribution;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            Contribution.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            Contribution.deserialize(buffer);
        }
    };
    // SetGroupContributionPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    SetGroupContributionPacket() {
        this->setID(SetGroupContribution_ID);
    };
    virtual ~SetGroupContributionPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetGroupContributionPacket();
    }
};

// SetGroupAcceptNoticesPacket
class SetGroupAcceptNoticesPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableUUID GroupID;
        SerializableBool AcceptNotices;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            AcceptNotices.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            AcceptNotices.deserialize(buffer);
        }
    };
    class NewDataBlock : public PacketSerializable {
    public:
        // NewDataBlock Member List
        SerializableBool ListInProfile;
    public:
        NewDataBlock() {};
        virtual ~NewDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ListInProfile.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ListInProfile.deserialize(buffer);
        }
    };
    // SetGroupAcceptNoticesPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;
    NewDataBlock NewData;

public:
    SetGroupAcceptNoticesPacket() {
        this->setID(SetGroupAcceptNotices_ID);
    };
    virtual ~SetGroupAcceptNoticesPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
        NewData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
        NewData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SetGroupAcceptNoticesPacket();
    }
};

// GroupRoleDataRequestPacket
class GroupRoleDataRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupRoleDataRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupRoleDataRequestPacket() {
        this->setID(GroupRoleDataRequest_ID);
    };
    virtual ~GroupRoleDataRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleDataRequestPacket();
    }
};

// GroupRoleDataReplyPacket
class GroupRoleDataReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
        SerializableS32 RoleCount;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
            RoleCount.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
            RoleCount.deserialize(buffer);
        }
    };
    class RoleDataBlock : public PacketSerializable {
    public:
        // RoleDataBlock Member List
        SerializableUUID RoleID;
        SerializableVariable1 Name;
        SerializableVariable1 Title;
        SerializableVariable1 Description;
        SerializableU64 Powers;
        SerializableU32 Members;
    public:
        RoleDataBlock() {};
        virtual ~RoleDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            Name.serialize(buffer);
            Title.serialize(buffer);
            Description.serialize(buffer);
            Powers.serialize(buffer);
            Members.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            Name.deserialize(buffer);
            Title.deserialize(buffer);
            Description.deserialize(buffer);
            Powers.deserialize(buffer);
            Members.deserialize(buffer);
        }
    };
    // GroupRoleDataReplyPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;
    VariableSerializable<RoleDataBlock> RoleData;

public:
    GroupRoleDataReplyPacket() {
        this->setID(GroupRoleDataReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~GroupRoleDataReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
        RoleData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
        RoleData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleDataReplyPacket();
    }
};

// GroupRoleMembersRequestPacket
class GroupRoleMembersRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupRoleMembersRequestPacket Member List
    AgentDataBlock AgentData;
    GroupDataBlock GroupData;

public:
    GroupRoleMembersRequestPacket() {
        this->setID(GroupRoleMembersRequest_ID);
    };
    virtual ~GroupRoleMembersRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleMembersRequestPacket();
    }
};

// GroupRoleMembersReplyPacket
class GroupRoleMembersReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
        SerializableUUID RequestID;
        SerializableU32 TotalPairs;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
            TotalPairs.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
            TotalPairs.deserialize(buffer);
        }
    };
    class MemberDataBlock : public PacketSerializable {
    public:
        // MemberDataBlock Member List
        SerializableUUID RoleID;
        SerializableUUID MemberID;
    public:
        MemberDataBlock() {};
        virtual ~MemberDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            MemberID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            MemberID.deserialize(buffer);
        }
    };
    // GroupRoleMembersReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<MemberDataBlock> MemberData;

public:
    GroupRoleMembersReplyPacket() {
        this->setID(GroupRoleMembersReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~GroupRoleMembersReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        MemberData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        MemberData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleMembersReplyPacket();
    }
};

// GroupTitlesRequestPacket
class GroupTitlesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    // GroupTitlesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    GroupTitlesRequestPacket() {
        this->setID(GroupTitlesRequest_ID);
    };
    virtual ~GroupTitlesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupTitlesRequestPacket();
    }
};

// GroupTitlesReplyPacket
class GroupTitlesReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
        SerializableUUID RequestID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
            RequestID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
            RequestID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableVariable1 Title;
        SerializableUUID RoleID;
        SerializableBool Selected;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Title.serialize(buffer);
            RoleID.serialize(buffer);
            Selected.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Title.deserialize(buffer);
            RoleID.deserialize(buffer);
            Selected.deserialize(buffer);
        }
    };
    // GroupTitlesReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<GroupDataBlock> GroupData;

public:
    GroupTitlesReplyPacket() {
        this->setID(GroupTitlesReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupTitlesReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupTitlesReplyPacket();
    }
};

// GroupTitleUpdatePacket
class GroupTitleUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
        SerializableUUID TitleRoleID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
            TitleRoleID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
            TitleRoleID.deserialize(buffer);
        }
    };
    // GroupTitleUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    GroupTitleUpdatePacket() {
        this->setID(GroupTitleUpdate_ID);
    };
    virtual ~GroupTitleUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupTitleUpdatePacket();
    }
};

// GroupRoleUpdatePacket
class GroupRoleUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    class RoleDataBlock : public PacketSerializable {
    public:
        // RoleDataBlock Member List
        SerializableUUID RoleID;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
        SerializableVariable1 Title;
        SerializableU64 Powers;
        SerializableU8 UpdateType;
    public:
        RoleDataBlock() {};
        virtual ~RoleDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RoleID.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
            Title.serialize(buffer);
            Powers.serialize(buffer);
            UpdateType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RoleID.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
            Title.deserialize(buffer);
            Powers.deserialize(buffer);
            UpdateType.deserialize(buffer);
        }
    };
    // GroupRoleUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<RoleDataBlock> RoleData;

public:
    GroupRoleUpdatePacket() {
        this->setID(GroupRoleUpdate_ID);
    };
    virtual ~GroupRoleUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RoleData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RoleData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupRoleUpdatePacket();
    }
};

// LiveHelpGroupRequestPacket
class LiveHelpGroupRequestPacket : public PacketBase {
public:

    // Block Class List
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableUUID RequestID;
        SerializableUUID AgentID;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            AgentID.deserialize(buffer);
        }
    };
    // LiveHelpGroupRequestPacket Member List
    RequestDataBlock RequestData;

public:
    LiveHelpGroupRequestPacket() {
        this->setID(LiveHelpGroupRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LiveHelpGroupRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RequestData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RequestData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LiveHelpGroupRequestPacket();
    }
};

// LiveHelpGroupReplyPacket
class LiveHelpGroupReplyPacket : public PacketBase {
public:

    // Block Class List
    class ReplyDataBlock : public PacketSerializable {
    public:
        // ReplyDataBlock Member List
        SerializableUUID RequestID;
        SerializableUUID GroupID;
        SerializableVariable1 Selection;
    public:
        ReplyDataBlock() {};
        virtual ~ReplyDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RequestID.serialize(buffer);
            GroupID.serialize(buffer);
            Selection.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RequestID.deserialize(buffer);
            GroupID.deserialize(buffer);
            Selection.deserialize(buffer);
        }
    };
    // LiveHelpGroupReplyPacket Member List
    ReplyDataBlock ReplyData;

public:
    LiveHelpGroupReplyPacket() {
        this->setID(LiveHelpGroupReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LiveHelpGroupReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ReplyData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ReplyData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LiveHelpGroupReplyPacket();
    }
};

// AgentWearablesRequestPacket
class AgentWearablesRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentWearablesRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AgentWearablesRequestPacket() {
        this->setID(AgentWearablesRequest_ID);
    };
    virtual ~AgentWearablesRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentWearablesRequestPacket();
    }
};

// AgentWearablesUpdatePacket
class AgentWearablesUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID AssetID;
        SerializableU8 WearableType;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            AssetID.serialize(buffer);
            WearableType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            AssetID.deserialize(buffer);
            WearableType.deserialize(buffer);
        }
    };
    // AgentWearablesUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;

public:
    AgentWearablesUpdatePacket() {
        this->setID(AgentWearablesUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentWearablesUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentWearablesUpdatePacket();
    }
};

// AgentIsNowWearingPacket
class AgentIsNowWearingPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID ItemID;
        SerializableU8 WearableType;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            WearableType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            WearableType.deserialize(buffer);
        }
    };
    // AgentIsNowWearingPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;

public:
    AgentIsNowWearingPacket() {
        this->setID(AgentIsNowWearing_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentIsNowWearingPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentIsNowWearingPacket();
    }
};

// AgentCachedTexturePacket
class AgentCachedTexturePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableS32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID ID;
        SerializableU8 TextureIndex;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            TextureIndex.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
        }
    };
    // AgentCachedTexturePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;

public:
    AgentCachedTexturePacket() {
        this->setID(AgentCachedTexture_ID);
    };
    virtual ~AgentCachedTexturePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentCachedTexturePacket();
    }
};

// AgentCachedTextureResponsePacket
class AgentCachedTextureResponsePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableS32 SerialNum;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            SerialNum.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            SerialNum.deserialize(buffer);
        }
    };
    class WearableDataBlock : public PacketSerializable {
    public:
        // WearableDataBlock Member List
        SerializableUUID TextureID;
        SerializableU8 TextureIndex;
        SerializableVariable1 HostName;
    public:
        WearableDataBlock() {};
        virtual ~WearableDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TextureID.serialize(buffer);
            TextureIndex.serialize(buffer);
            HostName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TextureID.deserialize(buffer);
            TextureIndex.deserialize(buffer);
            HostName.deserialize(buffer);
        }
    };
    // AgentCachedTextureResponsePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<WearableDataBlock> WearableData;

public:
    AgentCachedTextureResponsePacket() {
        this->setID(AgentCachedTextureResponse_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~AgentCachedTextureResponsePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        WearableData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        WearableData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentCachedTextureResponsePacket();
    }
};

// AgentDataUpdateRequestPacket
class AgentDataUpdateRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // AgentDataUpdateRequestPacket Member List
    AgentDataBlock AgentData;

public:
    AgentDataUpdateRequestPacket() {
        this->setID(AgentDataUpdateRequest_ID);
    };
    virtual ~AgentDataUpdateRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentDataUpdateRequestPacket();
    }
};

// AgentDataUpdatePacket
class AgentDataUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableVariable1 FirstName;
        SerializableVariable1 LastName;
        SerializableVariable1 GroupTitle;
        SerializableUUID ActiveGroupID;
        SerializableU64 GroupPowers;
        SerializableVariable1 GroupName;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            FirstName.serialize(buffer);
            LastName.serialize(buffer);
            GroupTitle.serialize(buffer);
            ActiveGroupID.serialize(buffer);
            GroupPowers.serialize(buffer);
            GroupName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            FirstName.deserialize(buffer);
            LastName.deserialize(buffer);
            GroupTitle.deserialize(buffer);
            ActiveGroupID.deserialize(buffer);
            GroupPowers.deserialize(buffer);
            GroupName.deserialize(buffer);
        }
    };
    // AgentDataUpdatePacket Member List
    AgentDataBlock AgentData;

public:
    AgentDataUpdatePacket() {
        this->setID(AgentDataUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentDataUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentDataUpdatePacket();
    }
};

// GroupDataUpdatePacket
class GroupDataUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentGroupDataBlock : public PacketSerializable {
    public:
        // AgentGroupDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
        SerializableU64 AgentPowers;
        SerializableVariable1 GroupTitle;
    public:
        AgentGroupDataBlock() {};
        virtual ~AgentGroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
            AgentPowers.serialize(buffer);
            GroupTitle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
            AgentPowers.deserialize(buffer);
            GroupTitle.deserialize(buffer);
        }
    };
    // GroupDataUpdatePacket Member List
    VariableSerializable<AgentGroupDataBlock> AgentGroupData;

public:
    GroupDataUpdatePacket() {
        this->setID(GroupDataUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~GroupDataUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentGroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentGroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new GroupDataUpdatePacket();
    }
};

// AgentGroupDataUpdatePacket
class AgentGroupDataUpdatePacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class GroupDataBlock : public PacketSerializable {
    public:
        // GroupDataBlock Member List
        SerializableUUID GroupID;
        SerializableU64 GroupPowers;
        SerializableBool AcceptNotices;
        SerializableUUID GroupInsigniaID;
        SerializableS32 Contribution;
        SerializableVariable1 GroupName;
    public:
        GroupDataBlock() {};
        virtual ~GroupDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GroupID.serialize(buffer);
            GroupPowers.serialize(buffer);
            AcceptNotices.serialize(buffer);
            GroupInsigniaID.serialize(buffer);
            Contribution.serialize(buffer);
            GroupName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GroupID.deserialize(buffer);
            GroupPowers.deserialize(buffer);
            AcceptNotices.deserialize(buffer);
            GroupInsigniaID.deserialize(buffer);
            Contribution.deserialize(buffer);
            GroupName.deserialize(buffer);
        }
    };
    // AgentGroupDataUpdatePacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<GroupDataBlock> GroupData;

public:
    AgentGroupDataUpdatePacket() {
        this->setID(AgentGroupDataUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentGroupDataUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        GroupData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        GroupData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentGroupDataUpdatePacket();
    }
};

// AgentDropGroupPacket
class AgentDropGroupPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID GroupID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            GroupID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            GroupID.deserialize(buffer);
        }
    };
    // AgentDropGroupPacket Member List
    AgentDataBlock AgentData;

public:
    AgentDropGroupPacket() {
        this->setID(AgentDropGroup_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~AgentDropGroupPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new AgentDropGroupPacket();
    }
};

// LogTextMessagePacket
class LogTextMessagePacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID FromAgentId;
        SerializableUUID ToAgentId;
        SerializableF64 GlobalX;
        SerializableF64 GlobalY;
        SerializableU32 Time;
        SerializableVariable2 Message;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            FromAgentId.serialize(buffer);
            ToAgentId.serialize(buffer);
            GlobalX.serialize(buffer);
            GlobalY.serialize(buffer);
            Time.serialize(buffer);
            Message.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            FromAgentId.deserialize(buffer);
            ToAgentId.deserialize(buffer);
            GlobalX.deserialize(buffer);
            GlobalY.deserialize(buffer);
            Time.deserialize(buffer);
            Message.deserialize(buffer);
        }
    };
    // LogTextMessagePacket Member List
    VariableSerializable<DataBlockBlock> DataBlock;

public:
    LogTextMessagePacket() {
        this->setID(LogTextMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~LogTextMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LogTextMessagePacket();
    }
};

// ViewerEffectPacket
class ViewerEffectPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class EffectBlock : public PacketSerializable {
    public:
        // EffectBlock Member List
        SerializableUUID ID;
        SerializableUUID AgentID;
        SerializableU8 Type;
        SerializableF32 Duration;
        SerializableFixed<4> Color;
        SerializableVariable1 TypeData;
    public:
        EffectBlock() {};
        virtual ~EffectBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ID.serialize(buffer);
            AgentID.serialize(buffer);
            Type.serialize(buffer);
            Duration.serialize(buffer);
            Color.serialize(buffer);
            TypeData.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ID.deserialize(buffer);
            AgentID.deserialize(buffer);
            Type.deserialize(buffer);
            Duration.deserialize(buffer);
            Color.deserialize(buffer);
            TypeData.deserialize(buffer);
        }
    };
    // ViewerEffectPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<EffectBlock> Effect;

public:
    ViewerEffectPacket() {
        this->setID(ViewerEffect_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ViewerEffectPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Effect.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Effect.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ViewerEffectPacket();
    }
};

// CreateTrustedCircuitPacket
class CreateTrustedCircuitPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID EndPointID;
        SerializableFixed<32> Digest;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EndPointID.serialize(buffer);
            Digest.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EndPointID.deserialize(buffer);
            Digest.deserialize(buffer);
        }
    };
    // CreateTrustedCircuitPacket Member List
    DataBlockBlock DataBlock;

public:
    CreateTrustedCircuitPacket() {
        this->setID(CreateTrustedCircuit_ID);
    };
    virtual ~CreateTrustedCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateTrustedCircuitPacket();
    }
};

// DenyTrustedCircuitPacket
class DenyTrustedCircuitPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID EndPointID;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            EndPointID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            EndPointID.deserialize(buffer);
        }
    };
    // DenyTrustedCircuitPacket Member List
    DataBlockBlock DataBlock;

public:
    DenyTrustedCircuitPacket() {
        this->setID(DenyTrustedCircuit_ID);
    };
    virtual ~DenyTrustedCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DenyTrustedCircuitPacket();
    }
};

// RequestTrustedCircuitPacket
class RequestTrustedCircuitPacket : public PacketBase {
public:

    // Block Class List
    // RequestTrustedCircuitPacket Member List

public:
    RequestTrustedCircuitPacket() {
        this->setID(RequestTrustedCircuit_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RequestTrustedCircuitPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {}
    virtual void deserialize(PacketBuffer &buffer) {}
    virtual PacketBase *clone() const {
        return new RequestTrustedCircuitPacket();
    }
};

// RezSingleAttachmentFromInvPacket
class RezSingleAttachmentFromInvPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID OwnerID;
        SerializableU8 AttachmentPt;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            OwnerID.serialize(buffer);
            AttachmentPt.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            AttachmentPt.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // RezSingleAttachmentFromInvPacket Member List
    AgentDataBlock AgentData;
    ObjectDataBlock ObjectData;

public:
    RezSingleAttachmentFromInvPacket() {
        this->setID(RezSingleAttachmentFromInv_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezSingleAttachmentFromInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezSingleAttachmentFromInvPacket();
    }
};

// RezMultipleAttachmentsFromInvPacket
class RezMultipleAttachmentsFromInvPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableUUID CompoundMsgID;
        SerializableU8 TotalObjects;
        SerializableBool FirstDetachAll;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            CompoundMsgID.serialize(buffer);
            TotalObjects.serialize(buffer);
            FirstDetachAll.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            CompoundMsgID.deserialize(buffer);
            TotalObjects.deserialize(buffer);
            FirstDetachAll.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID ItemID;
        SerializableUUID OwnerID;
        SerializableU8 AttachmentPt;
        SerializableU32 ItemFlags;
        SerializableU32 GroupMask;
        SerializableU32 EveryoneMask;
        SerializableU32 NextOwnerMask;
        SerializableVariable1 Name;
        SerializableVariable1 Description;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemID.serialize(buffer);
            OwnerID.serialize(buffer);
            AttachmentPt.serialize(buffer);
            ItemFlags.serialize(buffer);
            GroupMask.serialize(buffer);
            EveryoneMask.serialize(buffer);
            NextOwnerMask.serialize(buffer);
            Name.serialize(buffer);
            Description.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemID.deserialize(buffer);
            OwnerID.deserialize(buffer);
            AttachmentPt.deserialize(buffer);
            ItemFlags.deserialize(buffer);
            GroupMask.deserialize(buffer);
            EveryoneMask.deserialize(buffer);
            NextOwnerMask.deserialize(buffer);
            Name.deserialize(buffer);
            Description.deserialize(buffer);
        }
    };
    // RezMultipleAttachmentsFromInvPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    RezMultipleAttachmentsFromInvPacket() {
        this->setID(RezMultipleAttachmentsFromInv_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~RezMultipleAttachmentsFromInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RezMultipleAttachmentsFromInvPacket();
    }
};

// DetachAttachmentIntoInvPacket
class DetachAttachmentIntoInvPacket : public PacketBase {
public:

    // Block Class List
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID ItemID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // DetachAttachmentIntoInvPacket Member List
    ObjectDataBlock ObjectData;

public:
    DetachAttachmentIntoInvPacket() {
        this->setID(DetachAttachmentIntoInv_ID);
    };
    virtual ~DetachAttachmentIntoInvPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new DetachAttachmentIntoInvPacket();
    }
};

// CreateNewOutfitAttachmentsPacket
class CreateNewOutfitAttachmentsPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class HeaderDataBlock : public PacketSerializable {
    public:
        // HeaderDataBlock Member List
        SerializableUUID NewFolderID;
    public:
        HeaderDataBlock() {};
        virtual ~HeaderDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            NewFolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            NewFolderID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableUUID OldItemID;
        SerializableUUID OldFolderID;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            OldItemID.serialize(buffer);
            OldFolderID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            OldItemID.deserialize(buffer);
            OldFolderID.deserialize(buffer);
        }
    };
    // CreateNewOutfitAttachmentsPacket Member List
    AgentDataBlock AgentData;
    HeaderDataBlock HeaderData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    CreateNewOutfitAttachmentsPacket() {
        this->setID(CreateNewOutfitAttachments_ID);
    };
    virtual ~CreateNewOutfitAttachmentsPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        HeaderData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        HeaderData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new CreateNewOutfitAttachmentsPacket();
    }
};

// UserInfoRequestPacket
class UserInfoRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    // UserInfoRequestPacket Member List
    AgentDataBlock AgentData;

public:
    UserInfoRequestPacket() {
        this->setID(UserInfoRequest_ID);
    };
    virtual ~UserInfoRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserInfoRequestPacket();
    }
};

// UserInfoReplyPacket
class UserInfoReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class UserDataBlock : public PacketSerializable {
    public:
        // UserDataBlock Member List
        SerializableBool IMViaEMail;
        SerializableVariable1 DirectoryVisibility;
        SerializableVariable2 EMail;
    public:
        UserDataBlock() {};
        virtual ~UserDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IMViaEMail.serialize(buffer);
            DirectoryVisibility.serialize(buffer);
            EMail.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IMViaEMail.deserialize(buffer);
            DirectoryVisibility.deserialize(buffer);
            EMail.deserialize(buffer);
        }
    };
    // UserInfoReplyPacket Member List
    AgentDataBlock AgentData;
    UserDataBlock UserData;

public:
    UserInfoReplyPacket() {
        this->setID(UserInfoReply_ID);
    };
    virtual ~UserInfoReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UserData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UserData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UserInfoReplyPacket();
    }
};

// UpdateUserInfoPacket
class UpdateUserInfoPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class UserDataBlock : public PacketSerializable {
    public:
        // UserDataBlock Member List
        SerializableBool IMViaEMail;
        SerializableVariable1 DirectoryVisibility;
    public:
        UserDataBlock() {};
        virtual ~UserDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            IMViaEMail.serialize(buffer);
            DirectoryVisibility.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            IMViaEMail.deserialize(buffer);
            DirectoryVisibility.deserialize(buffer);
        }
    };
    // UpdateUserInfoPacket Member List
    AgentDataBlock AgentData;
    UserDataBlock UserData;

public:
    UpdateUserInfoPacket() {
        this->setID(UpdateUserInfo_ID);
    };
    virtual ~UpdateUserInfoPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        UserData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        UserData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new UpdateUserInfoPacket();
    }
};

// ParcelRenamePacket
class ParcelRenamePacket : public PacketBase {
public:

    // Block Class List
    class ParcelDataBlock : public PacketSerializable {
    public:
        // ParcelDataBlock Member List
        SerializableUUID ParcelID;
        SerializableVariable1 NewName;
    public:
        ParcelDataBlock() {};
        virtual ~ParcelDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ParcelID.serialize(buffer);
            NewName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ParcelID.deserialize(buffer);
            NewName.deserialize(buffer);
        }
    };
    // ParcelRenamePacket Member List
    VariableSerializable<ParcelDataBlock> ParcelData;

public:
    ParcelRenamePacket() {
        this->setID(ParcelRename_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelRenamePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        ParcelData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        ParcelData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelRenamePacket();
    }
};

// InitiateDownloadPacket
class InitiateDownloadPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class FileDataBlock : public PacketSerializable {
    public:
        // FileDataBlock Member List
        SerializableVariable1 SimFilename;
        SerializableVariable1 ViewerFilename;
    public:
        FileDataBlock() {};
        virtual ~FileDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            SimFilename.serialize(buffer);
            ViewerFilename.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            SimFilename.deserialize(buffer);
            ViewerFilename.deserialize(buffer);
        }
    };
    // InitiateDownloadPacket Member List
    AgentDataBlock AgentData;
    FileDataBlock FileData;

public:
    InitiateDownloadPacket() {
        this->setID(InitiateDownload_ID);
    };
    virtual ~InitiateDownloadPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        FileData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        FileData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new InitiateDownloadPacket();
    }
};

// SystemMessagePacket
class SystemMessagePacket : public PacketBase {
public:

    // Block Class List
    class MethodDataBlock : public PacketSerializable {
    public:
        // MethodDataBlock Member List
        SerializableVariable1 Method;
        SerializableUUID Invoice;
        SerializableFixed<32> Digest;
    public:
        MethodDataBlock() {};
        virtual ~MethodDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Method.serialize(buffer);
            Invoice.serialize(buffer);
            Digest.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Method.deserialize(buffer);
            Invoice.deserialize(buffer);
            Digest.deserialize(buffer);
        }
    };
    class ParamListBlock : public PacketSerializable {
    public:
        // ParamListBlock Member List
        SerializableVariable1 Parameter;
    public:
        ParamListBlock() {};
        virtual ~ParamListBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Parameter.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Parameter.deserialize(buffer);
        }
    };
    // SystemMessagePacket Member List
    MethodDataBlock MethodData;
    VariableSerializable<ParamListBlock> ParamList;

public:
    SystemMessagePacket() {
        this->setID(SystemMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~SystemMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        MethodData.serialize(buffer);
        ParamList.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        MethodData.deserialize(buffer);
        ParamList.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SystemMessagePacket();
    }
};

// MapLayerRequestPacket
class MapLayerRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    // MapLayerRequestPacket Member List
    AgentDataBlock AgentData;

public:
    MapLayerRequestPacket() {
        this->setID(MapLayerRequest_ID);
    };
    virtual ~MapLayerRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapLayerRequestPacket();
    }
};

// MapLayerReplyPacket
class MapLayerReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class LayerDataBlock : public PacketSerializable {
    public:
        // LayerDataBlock Member List
        SerializableU32 Left;
        SerializableU32 Right;
        SerializableU32 Top;
        SerializableU32 Bottom;
        SerializableUUID ImageID;
    public:
        LayerDataBlock() {};
        virtual ~LayerDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Left.serialize(buffer);
            Right.serialize(buffer);
            Top.serialize(buffer);
            Bottom.serialize(buffer);
            ImageID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Left.deserialize(buffer);
            Right.deserialize(buffer);
            Top.deserialize(buffer);
            Bottom.deserialize(buffer);
            ImageID.deserialize(buffer);
        }
    };
    // MapLayerReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<LayerDataBlock> LayerData;

public:
    MapLayerReplyPacket() {
        this->setID(MapLayerReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~MapLayerReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        LayerData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        LayerData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapLayerReplyPacket();
    }
};

// MapBlockRequestPacket
class MapBlockRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class PositionDataBlock : public PacketSerializable {
    public:
        // PositionDataBlock Member List
        SerializableU16 MinX;
        SerializableU16 MaxX;
        SerializableU16 MinY;
        SerializableU16 MaxY;
    public:
        PositionDataBlock() {};
        virtual ~PositionDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MinX.serialize(buffer);
            MaxX.serialize(buffer);
            MinY.serialize(buffer);
            MaxY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MinX.deserialize(buffer);
            MaxX.deserialize(buffer);
            MinY.deserialize(buffer);
            MaxY.deserialize(buffer);
        }
    };
    // MapBlockRequestPacket Member List
    AgentDataBlock AgentData;
    PositionDataBlock PositionData;

public:
    MapBlockRequestPacket() {
        this->setID(MapBlockRequest_ID);
    };
    virtual ~MapBlockRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        PositionData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        PositionData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapBlockRequestPacket();
    }
};

// MapNameRequestPacket
class MapNameRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class NameDataBlock : public PacketSerializable {
    public:
        // NameDataBlock Member List
        SerializableVariable1 Name;
    public:
        NameDataBlock() {};
        virtual ~NameDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Name.deserialize(buffer);
        }
    };
    // MapNameRequestPacket Member List
    AgentDataBlock AgentData;
    NameDataBlock NameData;

public:
    MapNameRequestPacket() {
        this->setID(MapNameRequest_ID);
    };
    virtual ~MapNameRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        NameData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        NameData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapNameRequestPacket();
    }
};

// MapBlockReplyPacket
class MapBlockReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU16 X;
        SerializableU16 Y;
        SerializableVariable1 Name;
        SerializableU8 Access;
        SerializableU32 RegionFlags;
        SerializableU8 WaterHeight;
        SerializableU8 Agents;
        SerializableUUID MapImageID;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            X.serialize(buffer);
            Y.serialize(buffer);
            Name.serialize(buffer);
            Access.serialize(buffer);
            RegionFlags.serialize(buffer);
            WaterHeight.serialize(buffer);
            Agents.serialize(buffer);
            MapImageID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            X.deserialize(buffer);
            Y.deserialize(buffer);
            Name.deserialize(buffer);
            Access.deserialize(buffer);
            RegionFlags.deserialize(buffer);
            WaterHeight.deserialize(buffer);
            Agents.deserialize(buffer);
            MapImageID.deserialize(buffer);
        }
    };
    // MapBlockReplyPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<DataBlock> Data;

public:
    MapBlockReplyPacket() {
        this->setID(MapBlockReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~MapBlockReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapBlockReplyPacket();
    }
};

// MapItemRequestPacket
class MapItemRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableU32 Flags;
        SerializableU32 EstateID;
        SerializableBool Godlike;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            Flags.serialize(buffer);
            EstateID.serialize(buffer);
            Godlike.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            Flags.deserialize(buffer);
            EstateID.deserialize(buffer);
            Godlike.deserialize(buffer);
        }
    };
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ItemType;
        SerializableU64 RegionHandle;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemType.serialize(buffer);
            RegionHandle.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemType.deserialize(buffer);
            RegionHandle.deserialize(buffer);
        }
    };
    // MapItemRequestPacket Member List
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;

public:
    MapItemRequestPacket() {
        this->setID(MapItemRequest_ID);
    };
    virtual ~MapItemRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapItemRequestPacket();
    }
};

// MapItemReplyPacket
class MapItemReplyPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableU32 Flags;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ItemType;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ItemType.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ItemType.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableU32 X;
        SerializableU32 Y;
        SerializableUUID ID;
        SerializableS32 Extra;
        SerializableS32 Extra2;
        SerializableVariable1 Name;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            X.serialize(buffer);
            Y.serialize(buffer);
            ID.serialize(buffer);
            Extra.serialize(buffer);
            Extra2.serialize(buffer);
            Name.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            X.deserialize(buffer);
            Y.deserialize(buffer);
            ID.deserialize(buffer);
            Extra.deserialize(buffer);
            Extra2.deserialize(buffer);
            Name.deserialize(buffer);
        }
    };
    // MapItemReplyPacket Member List
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;
    VariableSerializable<DataBlock> Data;

public:
    MapItemReplyPacket() {
        this->setID(MapItemReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~MapItemReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new MapItemReplyPacket();
    }
};

// SendPostcardPacket
class SendPostcardPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
        SerializableUUID AssetID;
        SerializableVector3d PosGlobal;
        SerializableVariable1 To;
        SerializableVariable1 From;
        SerializableVariable1 Name;
        SerializableVariable1 Subject;
        SerializableVariable2 Msg;
        SerializableBool AllowPublish;
        SerializableBool MaturePublish;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
            AssetID.serialize(buffer);
            PosGlobal.serialize(buffer);
            To.serialize(buffer);
            From.serialize(buffer);
            Name.serialize(buffer);
            Subject.serialize(buffer);
            Msg.serialize(buffer);
            AllowPublish.serialize(buffer);
            MaturePublish.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
            AssetID.deserialize(buffer);
            PosGlobal.deserialize(buffer);
            To.deserialize(buffer);
            From.deserialize(buffer);
            Name.deserialize(buffer);
            Subject.deserialize(buffer);
            Msg.deserialize(buffer);
            AllowPublish.deserialize(buffer);
            MaturePublish.deserialize(buffer);
        }
    };
    // SendPostcardPacket Member List
    AgentDataBlock AgentData;

public:
    SendPostcardPacket() {
        this->setID(SendPostcard_ID);
    };
    virtual ~SendPostcardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new SendPostcardPacket();
    }
};

// RpcChannelRequestPacket
class RpcChannelRequestPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableU32 GridX;
        SerializableU32 GridY;
        SerializableUUID TaskID;
        SerializableUUID ItemID;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GridX.serialize(buffer);
            GridY.serialize(buffer);
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
        }
    };
    // RpcChannelRequestPacket Member List
    DataBlockBlock DataBlock;

public:
    RpcChannelRequestPacket() {
        this->setID(RpcChannelRequest_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RpcChannelRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcChannelRequestPacket();
    }
};

// RpcChannelReplyPacket
class RpcChannelReplyPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
        }
    };
    // RpcChannelReplyPacket Member List
    DataBlockBlock DataBlock;

public:
    RpcChannelReplyPacket() {
        this->setID(RpcChannelReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RpcChannelReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcChannelReplyPacket();
    }
};

// RpcScriptRequestInboundPacket
class RpcScriptRequestInboundPacket : public PacketBase {
public:

    // Block Class List
    class TargetBlockBlock : public PacketSerializable {
    public:
        // TargetBlockBlock Member List
        SerializableU32 GridX;
        SerializableU32 GridY;
    public:
        TargetBlockBlock() {};
        virtual ~TargetBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            GridX.serialize(buffer);
            GridY.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            GridX.deserialize(buffer);
            GridY.deserialize(buffer);
        }
    };
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
        SerializableU32 IntValue;
        SerializableVariable2 StringValue;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
            IntValue.serialize(buffer);
            StringValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
            IntValue.deserialize(buffer);
            StringValue.deserialize(buffer);
        }
    };
    // RpcScriptRequestInboundPacket Member List
    TargetBlockBlock TargetBlock;
    DataBlockBlock DataBlock;

public:
    RpcScriptRequestInboundPacket() {
        this->setID(RpcScriptRequestInbound_ID);
    };
    virtual ~RpcScriptRequestInboundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        TargetBlock.serialize(buffer);
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        TargetBlock.deserialize(buffer);
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcScriptRequestInboundPacket();
    }
};

// RpcScriptRequestInboundForwardPacket
class RpcScriptRequestInboundForwardPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableIPADDR RPCServerIP;
        SerializableIPPORT RPCServerPort;
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
        SerializableU32 IntValue;
        SerializableVariable2 StringValue;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            RPCServerIP.serialize(buffer);
            RPCServerPort.serialize(buffer);
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
            IntValue.serialize(buffer);
            StringValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            RPCServerIP.deserialize(buffer);
            RPCServerPort.deserialize(buffer);
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
            IntValue.deserialize(buffer);
            StringValue.deserialize(buffer);
        }
    };
    // RpcScriptRequestInboundForwardPacket Member List
    DataBlockBlock DataBlock;

public:
    RpcScriptRequestInboundForwardPacket() {
        this->setID(RpcScriptRequestInboundForward_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~RpcScriptRequestInboundForwardPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcScriptRequestInboundForwardPacket();
    }
};

// RpcScriptReplyInboundPacket
class RpcScriptReplyInboundPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableUUID TaskID;
        SerializableUUID ItemID;
        SerializableUUID ChannelID;
        SerializableU32 IntValue;
        SerializableVariable2 StringValue;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskID.serialize(buffer);
            ItemID.serialize(buffer);
            ChannelID.serialize(buffer);
            IntValue.serialize(buffer);
            StringValue.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskID.deserialize(buffer);
            ItemID.deserialize(buffer);
            ChannelID.deserialize(buffer);
            IntValue.deserialize(buffer);
            StringValue.deserialize(buffer);
        }
    };
    // RpcScriptReplyInboundPacket Member List
    DataBlockBlock DataBlock;

public:
    RpcScriptReplyInboundPacket() {
        this->setID(RpcScriptReplyInbound_ID);
    };
    virtual ~RpcScriptReplyInboundPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new RpcScriptReplyInboundPacket();
    }
};

// ScriptMailRegistrationPacket
class ScriptMailRegistrationPacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableVariable1 TargetIP;
        SerializableIPPORT TargetPort;
        SerializableUUID TaskID;
        SerializableU32 Flags;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TargetIP.serialize(buffer);
            TargetPort.serialize(buffer);
            TaskID.serialize(buffer);
            Flags.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TargetIP.deserialize(buffer);
            TargetPort.deserialize(buffer);
            TaskID.deserialize(buffer);
            Flags.deserialize(buffer);
        }
    };
    // ScriptMailRegistrationPacket Member List
    DataBlockBlock DataBlock;

public:
    ScriptMailRegistrationPacket() {
        this->setID(ScriptMailRegistration_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ScriptMailRegistrationPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ScriptMailRegistrationPacket();
    }
};

// ParcelMediaCommandMessagePacket
class ParcelMediaCommandMessagePacket : public PacketBase {
public:

    // Block Class List
    class CommandBlockBlock : public PacketSerializable {
    public:
        // CommandBlockBlock Member List
        SerializableU32 Flags;
        SerializableU32 Command;
        SerializableF32 Time;
    public:
        CommandBlockBlock() {};
        virtual ~CommandBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Flags.serialize(buffer);
            Command.serialize(buffer);
            Time.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Flags.deserialize(buffer);
            Command.deserialize(buffer);
            Time.deserialize(buffer);
        }
    };
    // ParcelMediaCommandMessagePacket Member List
    CommandBlockBlock CommandBlock;

public:
    ParcelMediaCommandMessagePacket() {
        this->setID(ParcelMediaCommandMessage_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelMediaCommandMessagePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        CommandBlock.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        CommandBlock.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelMediaCommandMessagePacket();
    }
};

// ParcelMediaUpdatePacket
class ParcelMediaUpdatePacket : public PacketBase {
public:

    // Block Class List
    class DataBlockBlock : public PacketSerializable {
    public:
        // DataBlockBlock Member List
        SerializableVariable1 MediaURL;
        SerializableUUID MediaID;
        SerializableU8 MediaAutoScale;
    public:
        DataBlockBlock() {};
        virtual ~DataBlockBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MediaURL.serialize(buffer);
            MediaID.serialize(buffer);
            MediaAutoScale.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MediaURL.deserialize(buffer);
            MediaID.deserialize(buffer);
            MediaAutoScale.deserialize(buffer);
        }
    };
    class DataBlockExtendedBlock : public PacketSerializable {
    public:
        // DataBlockExtendedBlock Member List
        SerializableVariable1 MediaType;
        SerializableVariable1 MediaDesc;
        SerializableS32 MediaWidth;
        SerializableS32 MediaHeight;
        SerializableU8 MediaLoop;
    public:
        DataBlockExtendedBlock() {};
        virtual ~DataBlockExtendedBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            MediaType.serialize(buffer);
            MediaDesc.serialize(buffer);
            MediaWidth.serialize(buffer);
            MediaHeight.serialize(buffer);
            MediaLoop.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            MediaType.deserialize(buffer);
            MediaDesc.deserialize(buffer);
            MediaWidth.deserialize(buffer);
            MediaHeight.deserialize(buffer);
            MediaLoop.deserialize(buffer);
        }
    };
    // ParcelMediaUpdatePacket Member List
    DataBlockBlock DataBlock;
    DataBlockExtendedBlock DataBlockExtended;

public:
    ParcelMediaUpdatePacket() {
        this->setID(ParcelMediaUpdate_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~ParcelMediaUpdatePacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        DataBlock.serialize(buffer);
        DataBlockExtended.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        DataBlock.deserialize(buffer);
        DataBlockExtended.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ParcelMediaUpdatePacket();
    }
};

// LandStatRequestPacket
class LandStatRequestPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ReportType;
        SerializableU32 RequestFlags;
        SerializableVariable1 Filter;
        SerializableS32 ParcelLocalID;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            RequestFlags.serialize(buffer);
            Filter.serialize(buffer);
            ParcelLocalID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            RequestFlags.deserialize(buffer);
            Filter.deserialize(buffer);
            ParcelLocalID.deserialize(buffer);
        }
    };
    // LandStatRequestPacket Member List
    AgentDataBlock AgentData;
    RequestDataBlock RequestData;

public:
    LandStatRequestPacket() {
        this->setID(LandStatRequest_ID);
    };
    virtual ~LandStatRequestPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        RequestData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        RequestData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LandStatRequestPacket();
    }
};

// LandStatReplyPacket
class LandStatReplyPacket : public PacketBase {
public:

    // Block Class List
    class RequestDataBlock : public PacketSerializable {
    public:
        // RequestDataBlock Member List
        SerializableU32 ReportType;
        SerializableU32 RequestFlags;
        SerializableU32 TotalObjectCount;
    public:
        RequestDataBlock() {};
        virtual ~RequestDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ReportType.serialize(buffer);
            RequestFlags.serialize(buffer);
            TotalObjectCount.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ReportType.deserialize(buffer);
            RequestFlags.deserialize(buffer);
            TotalObjectCount.deserialize(buffer);
        }
    };
    class ReportDataBlock : public PacketSerializable {
    public:
        // ReportDataBlock Member List
        SerializableU32 TaskLocalID;
        SerializableUUID TaskID;
        SerializableF32 LocationX;
        SerializableF32 LocationY;
        SerializableF32 LocationZ;
        SerializableF32 Score;
        SerializableVariable1 TaskName;
        SerializableVariable1 OwnerName;
    public:
        ReportDataBlock() {};
        virtual ~ReportDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            TaskLocalID.serialize(buffer);
            TaskID.serialize(buffer);
            LocationX.serialize(buffer);
            LocationY.serialize(buffer);
            LocationZ.serialize(buffer);
            Score.serialize(buffer);
            TaskName.serialize(buffer);
            OwnerName.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            TaskLocalID.deserialize(buffer);
            TaskID.deserialize(buffer);
            LocationX.deserialize(buffer);
            LocationY.deserialize(buffer);
            LocationZ.deserialize(buffer);
            Score.deserialize(buffer);
            TaskName.deserialize(buffer);
            OwnerName.deserialize(buffer);
        }
    };
    // LandStatReplyPacket Member List
    RequestDataBlock RequestData;
    VariableSerializable<ReportDataBlock> ReportData;

public:
    LandStatReplyPacket() {
        this->setID(LandStatReply_ID);
        this->setFlag(PacketHeader::FLAG_RELIABLE);
    };
    virtual ~LandStatReplyPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        RequestData.serialize(buffer);
        ReportData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        RequestData.deserialize(buffer);
        ReportData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new LandStatReplyPacket();
    }
};

// ErrorPacket
class ErrorPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
        }
    };
    class DataBlock : public PacketSerializable {
    public:
        // DataBlock Member List
        SerializableS32 Code;
        SerializableVariable1 Token;
        SerializableUUID ID;
        SerializableVariable1 System;
        SerializableVariable2 Message;
        SerializableVariable2 Data;
    public:
        DataBlock() {};
        virtual ~DataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            Code.serialize(buffer);
            Token.serialize(buffer);
            ID.serialize(buffer);
            System.serialize(buffer);
            Message.serialize(buffer);
            Data.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            Code.deserialize(buffer);
            Token.deserialize(buffer);
            ID.deserialize(buffer);
            System.deserialize(buffer);
            Message.deserialize(buffer);
            Data.deserialize(buffer);
        }
    };
    // ErrorPacket Member List
    AgentDataBlock AgentData;
    DataBlock Data;

public:
    ErrorPacket() {
        this->setID(Error_ID);
        this->setFlag(PacketHeader::FLAG_ZEROCODED);
    };
    virtual ~ErrorPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        Data.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        Data.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ErrorPacket();
    }
};

// ObjectIncludeInSearchPacket
class ObjectIncludeInSearchPacket : public PacketBase {
public:

    // Block Class List
    class AgentDataBlock : public PacketSerializable {
    public:
        // AgentDataBlock Member List
        SerializableUUID AgentID;
        SerializableUUID SessionID;
    public:
        AgentDataBlock() {};
        virtual ~AgentDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            AgentID.serialize(buffer);
            SessionID.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            AgentID.deserialize(buffer);
            SessionID.deserialize(buffer);
        }
    };
    class ObjectDataBlock : public PacketSerializable {
    public:
        // ObjectDataBlock Member List
        SerializableU32 ObjectLocalID;
        SerializableBool IncludeInSearch;
    public:
        ObjectDataBlock() {};
        virtual ~ObjectDataBlock() {};
        virtual void serialize(PacketBuffer &buffer) const {
            ObjectLocalID.serialize(buffer);
            IncludeInSearch.serialize(buffer);
        }
        virtual void deserialize(PacketBuffer &buffer) {
            ObjectLocalID.deserialize(buffer);
            IncludeInSearch.deserialize(buffer);
        }
    };
    // ObjectIncludeInSearchPacket Member List
    AgentDataBlock AgentData;
    VariableSerializable<ObjectDataBlock> ObjectData;

public:
    ObjectIncludeInSearchPacket() {
        this->setID(ObjectIncludeInSearch_ID);
    };
    virtual ~ObjectIncludeInSearchPacket() {};

    virtual void serialize(PacketBuffer &buffer) const {
        AgentData.serialize(buffer);
        ObjectData.serialize(buffer);
    }
    virtual void deserialize(PacketBuffer &buffer) {
        AgentData.deserialize(buffer);
        ObjectData.deserialize(buffer);
    }
    virtual PacketBase *clone() const {
        return new ObjectIncludeInSearchPacket();
    }
};



};

#endif // PACKET_IMPL_H

