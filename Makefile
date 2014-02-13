# From: http://mrbook.org/tutorials/make/

all: brutus

brutus: main.c
	gcc main.c -o brutus

clean:
	rm -rf *o brutus
