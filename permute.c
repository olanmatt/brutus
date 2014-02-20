#include <stdio.h>
#include <string.h>
#include <math.h>
#include "butils.h"

void permute(char *str, int len, int min, int max){
	int per[max];
	int ind = min - 1;

	// Setting up initial values for array
	for(int i = 0; i <= max; i++)
		if (i < min)
			per[i] = 0;
		else
			per[i] = -1;

	// For length in given range
	for(int x = min; x <= max; x++){

		// Permutation for length
		for(int y = 0; y < pow(len, ind); y++){

			for(int i = 0; per[i] != -1; i++)
				printf("%c", str[per[i]]);
			printf("\n");

			// Incrementing and printing
			for(int i = 1; i < len; i++){
				per[ind]++;
				for(int i = 0; per[i] != -1; i++)
					printf("%c", str[per[i]]);
				printf("\n");
			}

			// Normalizing values
			for(int i = ind; i > 0; i--){
				if(per[i] == len - 1){
					if(per[i - 1] != len - 1){
						per[i] = 0;
						per[i - 1]++;
						i--;
					}else{
						per[i] = 0;
					}
				}
			}
		}
		ind++; // increase number of chars
		per[ind] = 0;
		per[0] = 0; // reset leading char
	}
}
