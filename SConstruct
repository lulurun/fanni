import os

TMP_INSTALL = os.environ['TMP_INSTALL']
EXTRA_INC = "-I" + TMP_INSTALL + "/include"
EXTRA_LIB = "-L" + TMP_INSTALL + "/lib"

RELEASE_CCFLAGS = "-Wall -Werror -O2"
DEBUG_CCFLAGS = "-Wall -Werror -g -ggdb -O0 -DDEBUG " + EXTRA_INC
DEBUG_LDFLAGS = EXTRA_LIB

env = Environment(CCFLAGS=DEBUG_CCFLAGS, LINKFLAGS=DEBUG_LDFLAGS)
Export("env")

# Libraries
env.SConscript('Basic/SConscript')
env.SConscript('Framework/Threads/SConscript')
env.SConscript('Framework/Network/SConscript')
env.SConscript('Framework/Packets/SConscript')
env.SConscript('Protocol/LLPackets/SConscript')
env.SConscript('Protocol/FileTransferPackets/SConscript')

# Programs

# Tests
env.SConscript('Tests/SConstruct')

