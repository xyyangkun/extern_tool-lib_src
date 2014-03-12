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
LIBS =  -lSDL -lfreetype -lSDL_ttf
LDLIBS=$(LIBDIR) $(LIBS)

#编译选项
CXXFLAGS=-g
CXXFLAGS+= $(INCLUDE) $(LDLIBS) 
CFLAGS=-g
CFLAGS+=   $(INCLUDE) $(LDLIBS)

#目标
all: test

%.o:%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)
%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

CPPOBJS = 
CPPOBJS= 


test:test_text.o $(CPPOBJS)
	$(LINK) $@ $< $(CPPOBJS) $(CXXFLAGS) 	
encoder.o: test_text.c
	$(CC) -c $< -o $@ $(CXXFLAGS)


	
clean:
	rm $(OUT)/*
	rm unit_test/*.o
	
	
	
	
	
	
