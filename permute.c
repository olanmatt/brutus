#include <stdio.h>
#include <string.h>
#include <math.h>
#include "butils.h"

void permute(char *str, int min, int max){
	int per[max];
	int len = strlen(str);
	int ind = min - 1;

	// Setting up initial values for array
	for(int i = 0; i <= max; i++)
		if ( i < min )
			per[i] = 0;
		else
			per[i] = -1;
	prnt(str, per);

	// For length in given range
	for(int x = min; x <= max; x++){

		// Permutation for length
		for(int y = 0; y < pow(len, ind); y++){

			// Incrementing and printing
			for(int i = 1; i < len; i++){
				per[ind]++;
				prnt(str, per);
			}

			// Normalizing values
			for(int i = ind; i >= 0; i--){
				if(per[i] == len-1){
					per[i] = 0;
					per[i - 1]++;
				}
			}
			// TODO fix printing one too many times
			prnt(str, per);
		}
		ind++;
		per[ind] = 0;
	}
}
