IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs -lncurses -g
 
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp Interfaces.hpp headers.hpp lista_usuario.hpp transacoes.hpp grafos.hpp categoria.hpp bancodados.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Interfaces.o Testes.o grafos.o lista_usuario.o transacoes.o categoria.o bancodados.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = Interfaces.o main.o grafos.o lista_usuario.o transacoes.o categoria.o bancodados.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Testes: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS) 

main: $(OBJ2)
	g++ -o $@ $^ $(CFLAGS) $(LIBS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
