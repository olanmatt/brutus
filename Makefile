# From: http://mrbook.org/tutorials/make/

all: brutus

brutus: main.c permute.o butils.o
	g++ main.c permute.o butils.o -o brutus

permute.o: permute.c butils.o
	g++ -c permute.c butils.o

butils.o: butils.c charset.o
	g++ -c butils.c

charset.o: charset.cpp
	g++ -c charset.cpp

clean:
	rm -rf *o brutus
