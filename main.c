#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "butils.h"
#include "permute.h"

void usage(){
	printf("Usage: brutus [-w] [-c charset] [-m min] [-M max]\n");
	printf("Generate string permutations of charset to standard output.\n\n");
	printf("  -c, --charset\t\tcharset to permute over\n");
	printf("  -m, --min\t\tminimum length of strings\n");
	printf("  -M, --max\t\tmaximum length of strings\n");
	printf("  -w, --no-replace\tdo not reuse letters from charset\n");
	printf("      --help\t\tdisplay this help and exit\n");
	printf("      --version\t\toutput version infomation and exit\n");
}

void version(){
	printf("brutus 0.1\n");
	printf("Copyright (C) 2014 Matt Olan.\n");
	printf("License: The MIT License (MIT).\n\n");
	printf("This is free software: you are free to change and redistribute it.\n");
	printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
	printf("Written by Matt Olan.");

}

int main (int argc, char **argv){

	int c;
	int min = 1;
	int max = 7;
	int no_replace = 0;

	static struct option long_options[] = {
		{"charset",		required_argument,	0, 'c'},
		{"min",			required_argument,	0, 'm'},
		{"max",			required_argument,	0, 'M'},
		{"no-replace",	no_argument,		&no_replace, 1},
		{"help",		no_argument,		0, 'h'},
		{"version",		no_argument,		0, 'V'} 
	};

	int option_index = 0;

	while (1){
		c = getopt_long(argc, argv, "c:m:M:w:", long_options, &option_index);

		if (c == -1)
			break;

		switch (c){

			case 'h':
				usage();
				exit(0);

			case 'V':
				version();
				exit(0);

			case 'c':
				printf ("option -c with value `%s'\n", optarg);
				// charset = loadCharset(optarg);
				// setlen = strlen(charset);
				break;

			case 'm':
				min = atoi(optarg);
				break;

			case 'M':
				max = atoi(optarg);
				break;

			default:
				printf("Try `cat --help' for more information.");
				exit(1);
		}
	}

	char charset[256];
	int setlen;
	loadCharset(1, charset, &setlen);
	fwrite(charset, setlen, 1, stdout);
	printf("length: %d\n", setlen);
	permute(charset, setlen, min, max);
	exit(0);
}
