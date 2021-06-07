
#Compiler
#support the dynamic and static library , C C++ at same time
#for c++
CXX  = g++
#for c
GCC  = gcc
LINK = $(CXX)

#Flag
INCLS		= -I./ -I/mnt/d/EastMoney/asio-asio-1-18-1/asio/include/
CCFLAGS		= -g -Wall -Werror -m64 -Wno-deprecated -std=c++11 
#for c
CFLAGS		= -g -Wall -Werror -m64 -Wno-deprecated
LFLAGS		= -pthread -Wl,-Bdynamic
#LFLAGS		= -lrt -lz -lm -lpthread -Llib -Wl,-Bdynamic -llog4cplus -lmysqlclient -Wl,-Bstatic

#Target
TARGETS		= asio

#Files
SOURCEALL :=$(shell find ./ -maxdepth 1 -iname "*.c" -o -iname "*.cpp" -o -iname "*.cc" -o -iname "*.h" -o -iname "*.hpp")
OBJSCPP = $(patsubst %.cpp,%.o,$(filter %.cpp, $(SOURCEALL)))
OBJSC   = $(patsubst %.c,%.o,$(filter %.c, $(SOURCEALL)))
OBJSCC  = $(patsubst %.cc,%.o,$(filter %.cc, $(SOURCEALL)))
TARGETSSOURCE = $(OBJSCPP) $(OBJSC) $(OBJSCC)

#Linker
$(TARGETS) : $(TARGETSSOURCE)
	@$(LINK) -o $(TARGETS) $(TARGETSSOURCE) $(LFLAGS)
	@echo $(TARGETS) "link successfully"

#Compile	
$(OBJSCPP):%.o:%.cpp
	@$(CXX) -c $(INCLS) $(CCFLAGS)  $< -o $@
	@echo $< "compile successfully"
	
$(OBJSC):%.o:%.c
	@$(GCC) -c $(INCLS) $(CFLAGS)  $< -o $@
	@echo $< "compile successfully"
	
$(OBJSCC):%.o:%.cc
	@$(CXX) -c $(INCLS) $(CCFLAGS)  $< -o $@
	@echo $< "compile successfully"
	
	
.PHONY : all clean

#md5
all : $(TARGETS)
	@md5sum $(TARGETS)
clean :
	@rm -f $(TARGETS) $(TARGETSSOURCE)
	@echo "All object is cleaning"


# Command '@' means DO NOT display the process of command execution
#compile ice Linux slice2cpp -I/usr/share/Ice-3.4.2/slice QuotePushServer.ice
#compile ice Windows slice2cpp *.ice -I "D:\Program Files\ZeroC\Ice-3.4.2\slice"
#-L/usr/lib64 -L/usr/lib64/mysql
