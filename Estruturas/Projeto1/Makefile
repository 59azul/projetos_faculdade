all: prog

prog: matriz.o lista.o
    gcc -Wall main.c lista.o matriz.o -o prog

lista.o: lista.c
    gcc -Wall -c lista.c

matriz.o: matriz.c
    gcc -Wall -c matriz.c

run: prog
    ./prog
