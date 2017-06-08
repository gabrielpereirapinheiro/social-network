IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lncurses
 
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp InterfaceUsuario.hpp InterfaceAdmin.hpp headers.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = InterfaceAdmin.o InterfaceUsuario.o Testes.o grafo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Testes: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
