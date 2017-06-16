IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lncurses
 
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp Interfaces.hpp headers.hpp lista_usuario.hpp transacoes.hpp grafos.hpp categoria.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Interfaces.o main.o grafos.o lista_usuario.o transacoes.o categoria.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
