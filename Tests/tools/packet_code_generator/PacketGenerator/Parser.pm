package Parser;

use strict;
use PacketGenerator::Packet;

use constant {
	OUT_TEMPLATE => 1,
	IN_TEMPLATE => 2,
};

our $Packets_cpp_Header =<< "HEADER";
#include "PacketBase.h"

using namespace Fanni;

HEADER

our $Packet_Class_Template =<< "TEMPLATE";
class <<CLASSNAME>> : public PacketBase {
public:
    <<MEMBER_LIST>>

public:
    <<CLASSNAME>>() { };
    virtual ~<<CLASSNAME>>() { };

protected:
    virtual void serialize(SerializableBuffer &buffer) const {
	<<MEMBER_SERIALIZE_LIST>>
    }
    virtual void deserialize(SerializableBuffer &buffer) {
	<<MEMBER_DESERIALIZE_LIST>>
    }
};

TEMPLATE

sub parse {
	my $file = shift;
	my @packet_list = ();
	open(FILE, $file) || die "can not open $file";
	my $fh = *FILE;
	while(1) {
		my $block_text = &_get_next_template($fh);
		last if (!$block_text);
		my $packet = &_parse_template($block_text);
		push @packet_list, $packet;
	}
	close(FILE);
	return \@packet_list;
}

sub _get_next_template {
	my $filehandler = shift;
	my $state = OUT_TEMPLATE;
	my $block_text = "";
	while(<$filehandler>) {
		next if $_ =~ /^\s*\/\//;
		next if $_ =~ /^\s*$/;
		if ($_ =~ /^\{/) {
			die "bad format: $_" if ($state != OUT_TEMPLATE);
			$state = IN_TEMPLATE;
			next;
		}
		if ($_ =~ /^\}/) {
			die "bad format: $_" if ($state != IN_TEMPLATE);
			$state = OUT_TEMPLATE;
			last;
		}
		if ($state == IN_TEMPLATE) {
			$block_text .= $_;
		}
	}
	return $block_text;
}

sub _parse_template {
	my $block_text = shift;
	my $packet = new Packet();
	$packet->parse_template($block_text);
	return $packet;
}

1;

