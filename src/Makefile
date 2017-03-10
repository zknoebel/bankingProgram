IDIR = ../include
CC=gcc
CFLAGS= -I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = pj1.h globalV.h record.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = main.o printFunctions.o stubs.o getaddress.o databaseFunctions.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -ansi -pedantic-errors -Wall -c -o $@ $< $(CFLAGS)

pj1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)  $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ pj1
