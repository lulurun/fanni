#!/usr/bin/perl -w

use strict;

my $_pwd = `pwd`;
my $base_dir = $_pwd;
$base_dir =~ s/\n//g;
my $generator_dir = $base_dir . "/../packet_code_generator";
my $test_log = $base_dir . "/test.log";

&cleanup();

eval {
    print "generate code\n";
    chdir($generator_dir) || die "can not chdir to $generator_dir";
    !system("./packet_generator.pl generate2") || die "Error! generate code\n";
    chdir($base_dir);

    print "scons\n";
    chdir("../../../");
    !system("scons") || die "Error! scons\n";;
    chdir($base_dir);

    # compile c#
    print "generate data\n";
    !system("gmcs TestDataGenerator.cs -lib:libomv -r:OpenMetaverse.dll,OpenMetaverseTypes.dll > /dev/null") || die "Error! gmcs\n";;
    !system("export MONO_PATH=libomv;mono TestDataGenerator.exe") || die "Error! mono TestDataGenerator.exe\n";;
    !system("mv libomv_generated_messages.txt ../../Protocol/")  || die "Error! mv\n";;

    # exec test
    print "test\n";
    chdir("../../Protocol");
    my $cmd = "export LD_LIBRARY_PATH=$ENV{TMP_INSTALL}/lib:../../lib;./test_serializer >$test_log";
    print $cmd . "\n";
    !system($cmd)  || die "Error! test\n";;
    chdir($base_dir);
};
if ($@) {
    print "failed " . $@ . "\n";
    print "logs saved in $test_log\n";
} else {
    print "test OK\n";
    system("rm test.log");
}

&cleanup();

;

sub cleanup() {
    print "clean ...\n";
    chdir($base_dir);
    system("rm -rf libomv_generated_messages.txt TestDataGenerator.cs TestDataGenerator.exe");
    system("rm -rf ../../Protocol/libomv_generated_messages.txt");
}

