#!/usr/bin/perl -w

use strict;
use PacketGenerator::Parser;
use PacketGenerator::Generator2;
use PacketGenerator::CSharpDataGenerator;

# get opts
my $act = shift @ARGV || "";
my $out_packet = "";
if ($act eq "packet") {
    $out_packet = shift @ARGV || "";
}
my $input_message_template = shift @ARGV || "message_template.msg";
my $output_prefix = shift @ARGV || "LL";
# settings
my $_pwd = `pwd`;
my $base_dir = $_pwd;
$base_dir =~ s/\n//g; # TODO @@@ ???

my $base_output_dir = $base_dir . "/../../../Protocol/" . $output_prefix . "Packets";
if (! -e $base_output_dir) {
    mkdir($base_output_dir);
}
my $packet_id_target = $base_output_dir . "/" . $output_prefix . "PacketsID.h";
my $packet_impl_target = $base_output_dir . "/" . $output_prefix . "Packets.h";
my $packet_factory_cpp_target = $base_output_dir . "/" . $output_prefix . "PacketFactory.cpp";
my $packet_factory_h_target = $base_output_dir . "/" . $output_prefix . "PacketFactory.h";
# for test
my $csharp_data_generator_target = $base_dir . "/../packet_code_test/TestDataGenerator.cs";

# init
my $packet_list = &Parser::parse($input_message_template);

if ($act eq "packet") {
    &dump_packets($packet_list, $out_packet);
} elsif ($act eq "type") {
    &dump_member_types($packet_list);
} elsif ($act eq "generate2_packet") {
    &save_file(&Generator2::generate_packet_id($packet_list), $packet_id_target);
    &save_file(&Generator2::generate_packet_impls($packet_list), $packet_impl_target);
} elsif ($act eq "generate2_factory") {
    &save_file(&Generator2::generate_packet_factory_cpp($packet_list), $packet_factory_cpp_target);
    &save_file(&Generator2::generate_packet_factory_h($packet_list), $packet_factory_h_target);
} elsif ($act eq "generate_c#_testdata") {
    &save_file(&CSharpDataGenerator::generate_test_program($packet_list), $csharp_data_generator_target);
} elsif ($act eq "generate2") {
    &save_file(&Generator2::generate_packet_id($packet_list), $packet_id_target);
    &save_file(&Generator2::generate_packet_impls($packet_list), $packet_impl_target);
    &save_file(&Generator2::generate_packet_factory_cpp($packet_list), $packet_factory_cpp_target);
    &save_file(&Generator2::generate_packet_factory_h($packet_list), $packet_factory_h_target);
    &save_file(&CSharpDataGenerator::generate_test_program($packet_list), $csharp_data_generator_target);
} else {
    die "unknown action -" . $act . "-\n";
}

sub save_file {
    my ($text, $filename) = @_;
    # TODO @@@ should not be here !!
    $text =~ s/{IMPL_PREFIX}/$output_prefix/g;

    print "output file: $filename\n";
    open(FILE, ">$filename") || die "can not write to file $filename";
    print FILE $text;
    close(FILE);
}

sub dump_packets {
    my ($packet_list, $out_packet) = @_;
    my $packet_count = @$packet_list;
    foreach my $packet (@$packet_list) {
	if (!$out_packet || $packet->{name} =~ /$out_packet/i) {
	    print $packet->toString();
	}
	if ($packet->{id} eq $out_packet) {
	    print $packet->toString();
	}
    }
    print "total: $packet_count\n";
}

sub dump_member_types {
    my $packet_list = shift;
    my %PACKET_TYPE = ();
    foreach my $packet (@$packet_list) {
	foreach	my $block (@{$packet->{block_list}}) {
	    foreach my $member (@{$block->{members}}) {
		my ($name, $type, $number) = split(/\s+/, $member);
		$PACKET_TYPE{$type} = 1;
	    }
	}
    }
    foreach (sort keys %PACKET_TYPE) {
	print $_ . "\n";
    }
}

