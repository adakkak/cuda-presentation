MAIN = bumpmap
LIBDIRS = -L /usr/local/lib
INCDIRS = -I /usr/include -I /usr/local/include/GL -I src/shared -I/usr/include/GL
SRCPATH = src/
SHAREDPATH = src/shared/

CC = gcc
CFLAGS = $(COMPILERFLAGS) -g $(INCDIRS)
LIBS = -lglut -lGL -lGLU -lm

prog : $(MAIN)

$(MAIN).o : $(SRCPATH)$(MAIN).cpp

math3d.o : $(SHAREDPATH)math3d.cpp

gltools.o : $(SHAREDPATH)gltools.cpp

$(MAIN) : $(MAIN).o gltools.o math3d.o
	$(CC) $(CFLAGS) -o $(MAIN) $(LIBDIRS) $(SRCPATH)$(MAIN).cpp $(SHAREDPATH)math3d.cpp $(SHAREDPATH)gltools.cpp $(SHAREDPATH)GLee.c $(LIBS)

clean:
	rm -f *.o


