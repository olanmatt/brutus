# From: http://mrbook.org/tutorials/make/

all: brutus

brutus: main.c permute.o butils.o
	gcc main.c permute.o butils.o -o brutus

permute.o: permute.c butils.o
	gcc -c permute.c butils.o

butils.o: butils.c
	gcc -c butils.c

clean:
	rm -rf *o brutus
