package Generator2;

use strict;
use PacketGenerator::CodeTemplate::Packets_Include;
use PacketGenerator::CodeTemplate::PacketsID_Include;
use PacketGenerator::CodeTemplate::Packets_def_Include;
use PacketGenerator::CodeTemplate::PacketFactory_Include;
use PacketGenerator::CodeTemplate::PacketFactory_Src;

my $limit = 1000; # max is 473

my %data_type_table = (
    BOOL => "SerializableBool",
    F32 => "SerializableF32",
    F64 => "SerializableF64",
    Fixed => "SerializableFixed",
    IPADDR => "SerializableIPADDR",
    IPPORT => "SerializableIPPORT",
    LLQuaternion => "SerializableQuaternion",
    LLUUID => "SerializableUUID",
    LLVector3 => "SerializableVector3",
    LLVector3d => "SerializableVector3d",
    LLVector4 => "SerializableVector4",
    S16 => "SerializableS16",
    S32 => "SerializableS32",
    S8 => "SerializableS8",
    U16 => "SerializableU16",
    U32 => "SerializableU32",
    U64 => "SerializableU64",
    U8 => "SerializableU8",
    Variable1 => "SerializableVariable1",
    Variable2 => "SerializableVariable2",
);

sub PacketsID_Include {
    my $packet_list = shift;
    my $packet_id_enum = &_generate_packet_classes_header($packet_list);

    my $text = $CodeTemplate::PacketsID_Include::Template;
    $text =~ s/{PacketIDEnum}/$packet_id_enum/;
    return $text;
}

sub Packets_Include {
    my $packet_list = shift;
    my $packet_classes = &_generate_serializable_classes($packet_list);

    my $text = $CodeTemplate::Packets_Include::Template;
    $text =~ s/{PacketClasses}/$packet_classes/;
    return $text;
}

sub _generate_serializable_classes {
    my $packet_list = shift;
    my $text = "";
    my $count = 0;
    foreach my $packet (@$packet_list) {
	my $class_name = $packet->{name} . "Packet";
	# packet info
	my $packet_info = "        this->setID(" . $packet->{name} . "_ID);\n";
	#if ($packet->{reliable} eq "true") {
	#    $packet_info .= "        this->setFlag(PacketHeader::FLAG_RELIABLE);";
	#}
	if ($packet->{zerocoded} eq "Zerocoded") {
	    $packet_info .= "        this->setFlag(PacketHeader::FLAG_ZEROCODED);";
	}
	# block info
	my $block_class_list = "";
	my $member_list = "";
	my $member_list_serialize = "";
	my $member_list_deserialize = "";
	my $block_list = $packet->{block_list};
	foreach my $block (@$block_list) {
	    $block_class_list .= &_generate_block($block);
	    my $member_class_name = "";
	    my $define_new_type = 0;
	    if ($block->{number} eq "Variable") {
		$member_class_name = "VariableSerializable<" . $block->{name} . "Block>";
		$define_new_type = 1;
	    } elsif ($block->{number} eq "Single" || $block->{number} eq "//") {
		$member_class_name = $block->{name} . "Block";
	    } else {
		$member_class_name = "MultipleSerializable<" . $block->{name} . "Block, " .  $block->{number} . ">";
		$define_new_type = 1;
	    }
	    $member_list .= "    " . $member_class_name . " " . $block->{name} . ";\n";
	    $member_list .= "    typedef " . $member_class_name . " " . uc($block->{name} . "Block") . "_LIST_TYPE;\n" if ($define_new_type);
	    $member_list_serialize .= "        " . $block->{name} . ".serialize(buffer);\n";
	    $member_list_deserialize .= "        " . $block->{name} . ".deserialize(buffer);\n";
	}
	# make source file readable
	$block_class_list = &_indent_block_list($block_class_list);
	# CODE TEMPLATE !
	my $class_impl = $CodeTemplate::Packets_Include::PacketClass_Template;
	$class_impl =~ s/{ClassName}/$class_name/g;
	$class_impl =~ s/{BaseClassName}/PacketBase/g;
	$class_impl =~ s/{BlockClassList}/$block_class_list/g;
	$class_impl =~ s/{MemberList}/$member_list/g;
	$class_impl =~ s/{MemberListSerialize}/$member_list_serialize/g;
	$class_impl =~ s/{MemberListDeserialize}/$member_list_deserialize/g;
	$class_impl =~ s/{SetPacketInfo}/$packet_info/g;
	$text .= $class_impl;
	# for Debug
	last if ++$count == $limit;
    }
    # make source file readable
    $text =~ s/\n\n\n/\n\n/g;
    $text =~ s/\n\s+\n/\n/g;
    $text =~ s/\n\n(\s+)}/\n$1}/g;
    $text =~ s/{\s+}/{}/g;
    return $text;
}

sub _generate_block {
    my $block = shift;
    my $block_name = $block->{name} . "Block";
    my $block_number = $block->{number};

    my $member_list = "";
    my $member_list_serialize = "";
    my $member_list_deserialize = "";
    foreach (@{$block->{members}}) {
	my ($name, $type, $number) = split(/\s+/, $_);
	my $serializable_class = "";
	if ($type eq "Variable" && $number == 1) {
	    $serializable_class = "SerializableVariable1";
	} elsif ($type eq "Variable" && $number == 2) {
	    $serializable_class = "SerializableVariable2";
	} elsif ($type eq "Fixed" && $number > 0) {
	    $serializable_class = "SerializableFixed<" . $number . ">";
	} elsif (!$number) {
	    $serializable_class = $data_type_table{$type};
	} else {
	    die "WARN !!! unexpect format !!!\n";
	}
	$member_list .= "    " . $serializable_class . " " . $name . ";\n";
	$member_list_serialize .= "        " . $name . ".serialize(buffer);\n";
	$member_list_deserialize .= "        " . $name . ".deserialize(buffer);\n";
    }
    my $class_impl = $CodeTemplate::Packets_Include::BlockClass_Template;
    $class_impl =~ s/{ClassName}/$block_name/g;
    $class_impl =~ s/{BaseClassName}/PacketSerializable/g;
    $class_impl =~ s/{MemberList}/$member_list/g;
    $class_impl =~ s/{MemberListSerialize}/$member_list_serialize/g;
    $class_impl =~ s/{MemberListDeserialize}/$member_list_deserialize/g;
    $class_impl =~ s/{SetPacketInfo}//g;

    return $class_impl;
}

sub _indent_block_list {
    my $text = shift;
    $text =~ s/\n/\n    /g;
    $text = "    " . $text;
    return $text;
}

sub _generate_packet_classes_header {
    my $packet_list = shift;
    my $text = "";
    # class name
    # my $count1 = 0;
    # foreach my $packet (@$packet_list) {
    # print "class " . $packet->{name} . "Packet;\n";
    # last if ++$count1 == $limit;
    # }
    #
    # packet id
    $text .= "typedef enum {\n";
    my $count2 = 0;
    foreach my $packet (@$packet_list) {
	my $id = 0;
	if ($packet->{freq} eq "Low") {
	    $id = 0xFFFF0000 | $packet->{id};
	} elsif ($packet->{freq} eq "Medium") {
	    $id = 0x00FF0000 | $packet->{id};
	} elsif ($packet->{freq} eq "High") {
	    $id = 0x00000000 | $packet->{id};
	} elsif ($packet->{freq} eq "Fixed") {
	    $id = $packet->{id};
	}
	my $hex_id;
	if ($id =~ /0x/i) {
	    $hex_id = $id;
	} else {
	    $hex_id = sprintf("0x%08x", $id);
	}
	$text .= "\t " . $packet->{name} . "_ID = " . $hex_id . ",\n";
	# for Debug
	last if ++$count2 == $limit;
    }
    $text .= "} PacketID;\n";
    return $text;
}

sub PacketFactory_Src {
    my $packet_list = shift;
    my $init_all_packets = "";
    my $count = 0;
    foreach my $packet (@$packet_list) {
	my $classname = $packet->{name} . "Packet";
	my $packet_name = $packet->{name};
	$init_all_packets .=<< "INIT_PACKET";
    PacketList[$packet_name\_ID] = new $classname();
INIT_PACKET
        last if ++$count == $limit;
    }

    my $text = $CodeTemplate::PacketFactory_Src::Template;
    $text =~ s/{InitAllPackets}/$init_all_packets/;
    return $text;
}

sub PacketFactory_Include {
    my $packet_list = shift;
    my $text = $CodeTemplate::PacketFactory_Include::Template;
    return $text;
}

sub Packets_def_Include {
    my $packet_list = shift;
    my $text = $CodeTemplate::Packets_def_Include::Template;
    return $text;
}

1;

