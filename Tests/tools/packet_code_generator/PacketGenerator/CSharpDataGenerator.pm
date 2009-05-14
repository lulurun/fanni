package CSharpDataGenerator;

use strict;
use PacketGenerator::CodeTemplate;

my $program_template = $CodeTemplate::CSharp_TestProgram_Template;
my $gen_function_template = $CodeTemplate::CSharp_DataGenFunction_Template;

my %unused_packets = (
    AddCircuitCode => 1,
    NeighborList => 1,
    AvatarTextureUpdate => 1,
    SimulatorMapUpdate => 1,
    SimulatorSetMap => 1,
    SubscribeLoad => 1,
    UnsubscribeLoad => 1,
    SimulatorReady => 1,
    SimulatorPresentAtLocation => 1,
    SimulatorLoad => 1,
    SimulatorShutdownRequest => 1,
    RegionPresenceRequestByRegionID => 1,
    RegionPresenceRequestByHandle => 1,
    RegionPresenceResponse => 1,
    UpdateSimulator => 1,
    LogDwellTime => 1,
    FeatureDisabled => 1,
    LogFailedMoneyTransaction => 1,
    UserReportInternal => 1,
    SetSimStatusInDatabase => 1,
    SetSimPresenceInDatabase => 1,
    AvatarPickerRequestBackend => 1,
    DirFindQueryBackend => 1,
    DirPlacesQueryBackend => 1,
    DirClassifiedQueryBackend => 1,
    DirLandQueryBackend => 1,
    DirPopularQueryBackend => 1,
    GroupNoticeAdd => 1,
    DataHomeLocationRequest => 1,
    DataHomeLocationReply => 1,
    NearestLandingRegionRequest => 1,
    NearestLandingRegionReply => 1,
    TeleportLandingStatusChanged => 1,
    SystemKickUser => 1,
    AvatarPropertiesRequestBackend => 1,
    RequestParcelTransfer => 1,
    UpdateParcel => 1,
    RemoveParcel => 1,
    MergeParcel => 1,
    LogParcelChanges => 1,
    CheckParcelSales => 1,
    ParcelSales => 1,
    StartAuction => 1,
    ConfirmAuctionStart => 1,
    CompleteAuction =>1 ,
    UpdateAttachment => 1,
    RemoveAttachment => 1,
    EmailMessageRequest => 1,
    EmailMessageReply => 1,
    InternalScriptMail => 1,
    ScriptDataRequest => 1,
    ScriptDataReply => 1,
    InviteGroupResponse => 1,
    TallyVotes => 1,
    LogTextMessage => 1,
    ParcelRename => 1,
    CancelAuction => 1,
    CheckParcelAuctions => 1,
    ParcelAuctions => 1,
    ChatPass => 1,
    EdgeDataPacket => 1,
    SimStatus => 1,
    AtomicPassObject => 1,
    KillChildAgents => 1,
    DataServerLogout => 1,
    TransferInventory => 1,
    TransferInventoryAck => 1,
    EventLocationRequest => 1,
    EventLocationReply => 1,
    MoneyTransferBackend => 1,
    SetStartLocation => 1,
    NetTest => 1,
    SetCPURatio => 1,
    SimCrashed => 1,
    NameValuePair => 1,
    RemoveNameValuePair => 1,
    RpcChannelRequest => 1,
    RpcChannelReply => 1,
    RpcScriptRequestInbound => 1,
    RpcScriptRequestInboundForward => 1,
    RpcScriptReplyInbound => 1,
    ScriptMailRegistration => 1,
    );


my %changed_packets = (
);

sub generate_test_program {
    my $packet_list = shift;
    my $packet_functions_def = "";
    my $packet_functions_call = "";
    foreach my $packet (@$packet_list) {
	next if ($unused_packets{$packet->{name}});
	next if ($changed_packets{$packet->{name}});
	$packet_functions_def .= &generate_packet($packet);
	$packet_functions_call .= "            " . $packet->{name} . "_gen();\n";
    }

    my $text = $CodeTemplate::CSharp_TestProgram_Template;
    $text =~ s/{TestDataGen_FuncDef_List}/$packet_functions_def/;
    $text =~ s/{TestDataGen_FuncCall_List}/$packet_functions_call/;
    return $text;
}

sub generate_packet {
    my $packet = shift;
    my $packet_name = $packet->{name};
    my $block_list = $packet->{block_list};
    my $set_packet_data = "";
    foreach my $block (@$block_list) {
	# TODO @@@ !!!!!????
	$block->{name} = "_" . $block->{name} if ($block->{name} eq "Header");
	if ($block->{number} eq "Variable" || $block->{number} eq "//") {
	    $set_packet_data .= &generate_variable_block($block, $packet);
	} elsif ($block->{number} eq "Single") {
	    $set_packet_data .= &generate_single_block($block);
	} else {
	    $set_packet_data .= &generate_multiple_block($block, $packet);
	}
    }

    my $text = $CodeTemplate::CSharp_DataGenFunction_Template;
    $text =~ s/{PacketName}/$packet->{name}/g;
    $text =~ s/{Set_PacketData}/$set_packet_data/;
    return $text;
}

sub generate_single_block {
    my $block = shift;
    return &_block_member_assignment($block, 0);
}

sub generate_multiple_block {
    my ($block, $packet) = @_;
    my $block_member_assign = &_block_member_assignment($block, 1);
    my $text = $CodeTemplate::CSharp_BlockData_Template;
    $text =~ s/{BlockName}/$block->{name}/g;
    $text =~ s/{PacketName}/$packet->{name}/g;
    $text =~ s/{BlockNumber}/$block->{number}/g;
    $text =~ s/{BlockMemberAssignment}/$block_member_assign/g;
    return $text;
}

sub generate_variable_block {
    my ($block, $packet) = @_;
    my $block_member_assign = &_block_member_assignment($block, 1);
    my $default_block_number = "DefaultValues.variable_blocks_length";
    my $text = $CodeTemplate::CSharp_BlockData_Template;
    $text =~ s/{BlockName}/$block->{name}/g;
    $text =~ s/{PacketName}/$packet->{name}/g;
    $text =~ s/{BlockNumber}/$default_block_number/g;
    $text =~ s/{BlockMemberAssignment}/$block_member_assign/g;
    return $text;
}

# ##################
# sub functions
sub _block_member_assignment {
    my ($block, $is_multi) = @_;
    my $block_name = $block->{name} . ($is_multi ? "[i]" : "");
    my $text = "";
    foreach (@{$block->{members}}) {
	my ($member_name, $type, $number) = split(/\s+/, $_);
	my $default_value = &_get_default_value($type, $number);
	$text .= << "BLOCK_MEMBER_ASSIGN";
                packet.$block_name.$member_name = $default_value;
BLOCK_MEMBER_ASSIGN
    }
    return $text;
}

sub _get_default_value {
    my ($type, $number) = @_;
    my $default_value = "";
    if ($type eq "Variable" && $number == 1) {
	$default_value = "DefaultValues.Variable1";
    } elsif ($type eq "Variable" && $number == 2) {
	$default_value = "DefaultValues.Variable2";
    } elsif ($type eq "Fixed" && $number > 0) {
	$default_value = "DefaultValues.Fixed" . $number;
    } elsif (!$number) {
	$default_value = "DefaultValues." . $type;
    } else {
	die "WARN !!! unexpect format !!!\n";
    }
    return $default_value;
}

1;

