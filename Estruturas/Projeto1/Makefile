### Makefile ###

# Nome do compilador
CC = gcc

# Opções de compilação
CFLAGS = -g

# Wildcard para arquivos fonte
FONTES = $(wildcard *.c)

# Lista dos arquivos-objeto usando lista de arquivos fonte
OBJETOS = $(FONTES:.c=.o)

# Nome do arquivo executável
EXECUTAVEL = prog

# all: prog
all: $(EXECUTAVEL)

# prog: lista.o matriz.o main.o
#	gcc -o prog lista.o matriz.o main.o
$(EXECUTAVEL): $(OBJETOS)
	$(CC) -o $@ $^

# main.o: ...
%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf *.o

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)
