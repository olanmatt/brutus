#include <stdio.h>
#include <stdlib.h>
#include "permute.h"

int main(int argc, char **argv) {
	char str[] = "abcd"; //argv[1];
	int min = atoi(argv[2]);
	int max = atoi(argv[3]);
	permute(str, min, max);
	return 0;
}

