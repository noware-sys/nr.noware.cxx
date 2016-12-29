#.PHONY: clean

# QUEX_PATH = /opt/quex
QUEX_PATH = /usr/include/quex
LIB_PATH = /root/Documents/C++/NoWare
LIB = order.test
COMPILER = g++
CCOMPILER = gcc
# IN = main.c++ $(LIB_PATH)/mathematics.c++ $(LIB_PATH)/tools.c++ $(LIB_PATH)/network/endpoint.c++ $(LIB_PATH)/network/ip.c++ $(LIB_PATH)/network/ip/tcp.c++ $(LIB_PATH)/network/ip/udp.c++ $(LIB_PATH)/network/ip/mpi.c++ $(LIB_PATH)/network/mpi.c++ $(LIB_PATH)/network/connection.c++ $(LIB_PATH)/containers/variable.c++ $(LIB_PATH)/language/interpreter.c++ $(LIB_PATH)/machine/device.c++ $(LIB_PATH)/machine/devices/memory.c++ $(LIB_PATH)/machine/devices/processor.c++ $(LIB_PATH)/machine/network/communication/message.c++ $(LIB_PATH)/cluster/machine.c++
# IN = mathematics.obj tools.obj network-endpoint.obj network/ip.obj network-ip-tcp.obj network-ip-udp.obj network-ip-mpi.obj network-mpi.obj network-connection.obj containers-variable.obj language-interpreter.obj machine-device.obj machine-devices-memory.obj machine-devices-processor.obj machine-network-communication-message.obj cluster-machine.obj
IN = content.obj .content/descendant.obj
# For "entity" only:
#IN = main.c++ $(LIB_PATH)/containers/variable.c++ $(LIB_PATH)/tools.c++
#IN = tools.obj containers-variable.obj cluster.obj
OUT = index.do
OUT_32 = index-32.do
IN_QUEX = quex-example.cpp
OUT_QUEX = quex-example.do
#	COMPILER = g++ -o main.exe

ifdef ASSERTS_ENABLED_F
	CCFLAG_ASSERTS = # By default, asserts are enabled.
else 
	CCFLAG_ASSERTS = -DQUEX_OPTION_ASSERTS_DISABLED
endif

#ADD_FLAGS := #
#COMPILER_FLAGS = -g -ggdb -pedantic -fpermissive -W -Wall -Wmain -Wcomment -Wconversion -Wunused-parameter -Wparentheses -std=c++14 -I . -I $(QUEX_PATH) -I /usr/include/boost -I $(LIB_PATH) $(CCFLAG_ASSERTS) -L . -l boost_system -l boost_serialization -l boost_thread -l boost_random -l cln -fopenmp -lsqlite3 -l pthread -l dl
COMPILER_FLAGS = -std=c++14 -I $(LIB_PATH)
#CC = $(COMPILER) \
	# -I ./ -I $(QUEX_PATH)  \
#	 -I ./ -I /usr/include/quex  \
#	 $(COMPILER_FLAGS) \
#	$(CCFLAG_ASSERTS)
	# -DQUEX_OPTION_ASSERTS_DISABLED \
	# -DQUEX_OPTION_ASSERTS_WARNING_MESSAGE_DISABLED \
	# -DQUEX_OPTION_DEBUG_SHOW \

#ifndef QUEX_PATH
#	$(error The environment variable QUEX_PATH is not defined!)
#endif

#include $(QUEX_PATH)/quex/code_base/core.mkd
# include /usr/include/quex/quex/code_base/core.mkd

all:
	if test ! -f $(OUT); \
	then \
		$(COMPILER) $(COMPILER_FLAGS) -o index.obj -c index.c++;\
		#$(COMPILER) $(COMPILER_FLAGS) -o mathematics.obj -c $(LIB_PATH)/$(LIB)/mathematics.c++; \
		$(COMPILER) $(COMPILER_FLAGS) -o .content/descendant.obj -c $(LIB_PATH)/$(LIB)/.content/descendant.c++;\
		$(COMPILER) $(COMPILER_FLAGS) -o content.obj -c $(LIB_PATH)/$(LIB)/content.c++;\
		\
		$(COMPILER) $(COMPILER_FLAGS) -o $(OUT) index.obj $(IN);\
	fi
	
	if test -f $(OUT) && test ! -x $(OUT); \
	#if test ! -x $(OUT); \
	then \
		chmod +x $(OUT); \
	fi
32:
	if test ! -f $(OUT_32); \
	then \
		#$(CC) $(IN); \
		$(COMPILER) $(COMPILER_FLAGS) -m32 -o $(OUT_32) $(IN); \
	fi
	
	if test -f $(OUT_32) && test ! -x $(OUT_32); \
	#if test ! -x $(OUT_32); \
	then \
		chmod +x $(OUT_32); \
	fi
clean:
	#rm --force *.do *.run *.exe *.bin lexical_analyzer* *.bak *.E lexer
	#rm --force *.do lexical_analyzer* *.bak *.E lexer
	#rm --force *.do lexer/lexical_analyzer lexer/lexical_analyzer.cpp lexer/lexical_analyzer-configuration lexer/lexical_analyzer-token lexer/lexical_analyzer-token_ids *.bak *.E
	rm --force *.do *.obj .content/*.do .content/*.obj