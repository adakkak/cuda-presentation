BOOST_DIR = /usr/local/boost/include/boost-1_33_1/
THRIFT_DIR = /usr/local/include/thrift
GEN_SRC = ../gen-cpp/Split.cpp ../gen-cpp/split_types.cpp 

LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I src/shared -I/usr/include/GL  -I$(THRIFT_DIR) -I$(BOOST_DIR)  -I../gen-cpp -L${LIB_DIR} -lthrift
SRCPATH = src/
SHAREDPATH = src/shared/

CC = gcc
CFLAGS = $(COMPILERFLAGS) -g $(INCDIRS)
LIBS = -lglut -lGL -lGLU -lm

prog : bounceServer bounceClient

.cpp.o : 
	$(CC) -c $(CCFLAGS) $(INCDIRS) $*.cpp

.c.o :
	$(CC) -c $(CCFLAGS) $(INCDIRS) $*.c

bounceServer.o : $(SRCPATH)bounceServer.cpp

bounceClient.o : $(SRCPATH)bounceClient.cpp

math3d.o : $(SHAREDPATH)math3d.cpp

gltools.o : $(SHAREDPATH)gltools.cpp

bounceServer : bounceServer.o gltools.o math3d.o
	$(CC) $(CFLAGS) -o bounceServer $(LIBDIRS) $(SRCPATH)bounceServer.cpp $(SHAREDPATH)math3d.cpp $(SHAREDPATH)gltools.cpp $(SHAREDPATH)GLee.c $(LIBS) $(GEN_SRC)

bounceClient : bounceClient.o gltools.o math3d.o
	$(CC) $(CFLAGS) -o bounceClient $(LIBDIRS) $(SRCPATH)bounceClient.cpp $(SHAREDPATH)math3d.cpp $(SHAREDPATH)gltools.cpp $(SHAREDPATH)GLee.c $(LIBS) $(GEN_SRC)

clean:
	rm -f *.o bounceClient bounceServer


