all: brutus

brutus: main.c permute.o butils.o
	g++ main.c permute.o butils.o -o brutus

permute.o: permute.c butils.o
	g++ -c permute.c butils.o

butils.o: butils.cpp
	g++ -c butils.cpp

clean:
	rm -rf *o brutus
