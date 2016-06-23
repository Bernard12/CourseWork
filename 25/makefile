main: main.o
	cc -std=c99 -o main main.o #list.o sor.o
main.o: main.c
	cc -std=c99 -c main.c
main.c: sor.c list.c list.h
sor.o: sor.c
	cc -std=c99 -c sor.c 
sor.c: list.c
list.o: list.c
	cc -std=c99 -c list.c
list.c: list.h
