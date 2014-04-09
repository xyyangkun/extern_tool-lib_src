CROSS=
#arm-hisiv200-linux-
#arm-linux-
CC=$(CROSS)gcc
CXX=$(CROSS)g++
LINK=$(CROSS)g++ -o
LIBRARY_LINK=$(CROSS)ar cr

OUT=./OUT
SRCDIR=./src

TOP=/home/xy/mywork/git/extern_tool-lib_src/OUT
#LIBJDIR_JRTP=/workplace/mywork/git/jrtplib
#头文件
INCLUDE= -I ./include -I$(TOP)/include


#库文件
LIBDIR= -L./lib  -L$(TOP)/lib
LIBS =  
LDLIBS=$(LIBDIR) $(LIBS)

#编译选项
CXXFLAGS=-g
CXXFLAGS+= $(INCLUDE) $(LDLIBS) 
CFLAGS=-g
CFLAGS+=   $(INCLUDE) $(LDLIBS)

#目标
all: test_libav_filter

%.o:%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

CPPOBJS = 
CPPOBJS=


test_libav_filter: test_libav_filter.o $(CPPOBJS)
	$(LINK) $@ $< $(CPPOBJS) $(CFLAGS) 	
test_libav_filter.o:  test_libav_filter.c
	$(CC) -c $< -o $@ $(CFLAGS)


 
	
clean:
	rm $(OUT)/*

	