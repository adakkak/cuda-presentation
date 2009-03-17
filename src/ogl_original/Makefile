LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I src/shared -I/usr/include/GL
SRCPATH = src/
SHAREDPATH = src/shared/

CC = gcc
CFLAGS = $(COMPILERFLAGS) -g $(INCDIRS)
LIBS = -lglut -lGL -lGLU -lm

prog : bounce

.cpp.o : 
	$(CC) -c $(CCFLAGS) $(INCDIRS) $*.cpp

.c.o :
	$(CC) -c $(CCFLAGS) $(INCDIRS) $*.c

bounce.o : $(SRCPATH)bounce.cpp

math3d.o : $(SHAREDPATH)math3d.cpp

gltools.o : $(SHAREDPATH)gltools.cpp

bounce : bounce.o gltools.o math3d.o
	$(CC) $(CFLAGS) -o bounce $(LIBDIRS) $(SRCPATH)bounce.cpp $(SHAREDPATH)math3d.cpp $(SHAREDPATH)gltools.cpp $(SHAREDPATH)GLee.c $(LIBS)

clean:
	rm -f *.o


