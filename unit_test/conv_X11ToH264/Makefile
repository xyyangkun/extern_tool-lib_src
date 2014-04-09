
CROSS=
#arm-hisiv200-linux-
#arm-linux-
CC=$(CROSS)gcc
CXX=$(CROSS)g++
LINK=$(CROSS)g++ -o
LIBRARY_LINK=$(CROSS)ar cr


TOP=/workplace/mywork/git/extern_tool-lib_src/
OUT=./OUT
SRCDIR=./src
				   
#头文件
INCLUDE= -I $(TOP)/OUT/include 

#库文件
LIBDIR= -L$(TOP)/OUT/lib 
LIBS =  -lX11 -lx264 -lva -lm -pthread -lz -lx264 -lavdevice -lavcodec -lavformat -lavfilter -lavutil -lswscale -lavresample
LDLIBS=$(LIBDIR) $(LIBS)

#编译选项
CXXFLAGS=-g
CXXFLAGS+= $(INCLUDE) $(LDLIBS) 
CFLAGS=-g
CFLAGS+=   $(INCLUDE) $(LDLIBS)

#目标
all: main

%.o:%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

CPPOBJS = 
CPPOBJS= 


main:main.o $(CPPOBJS)
	$(LINK) $@ $< $(CPPOBJS) $(CXXFLAGS) 	
main.o: main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)


	
clean:
	rm $(OUT)/*
	rm unit_test/*.o
	
	
	
	
	
	
