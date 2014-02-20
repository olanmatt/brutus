#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "permute.h"

int main (int argc, char **argv){

	int c;
	int min = 1;
	int max = 7;
	char str[] = "abcd";


	while (1){
		static struct option long_options[] = {
			/* These options don't set a flag.
			 * We distinguish them by their indices.
			 */
			{"charset",	required_argument, 0, 'c'},
			{"min",		required_argument, 0, 'm'},
			{"max",		required_argument, 0, 'M'},
			{0, 0, 0, 0}
		};
		/* getopt_long stores the option index here. */
		int option_index = 0;

		c = getopt_long(argc, argv, "abc:dm:fM:", long_options, &option_index);

		/* Detect the end of the options. */
		if (c == -1)
			break;

		switch (c){
			case 'c':
				printf ("option -c with value `%s'\n", optarg);
				break;

			case 'm':
				min = atoi(optarg);
				break;

			case 'M':
				max = atoi(optarg);
				break;

			case '?':
				/* getopt_long already printed an error message. */
				break;

			default:
				abort ();
		}
	}

	/* Print any remaining command line arguments (not options). */
	if (optind < argc){
		printf ("non-option ARGV-elements: ");
		while (optind < argc)
			printf ("%s ", argv[optind++]);
		putchar ('\n');
	}

	permute(str, min, max);
	exit(0);
}
