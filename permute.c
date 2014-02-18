#include <stdio.h>
#include <string.h>
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

	// Incrementing and printing
	for(int i = 1; i < len; i++){
		per[ind]++;
		prnt(str, per);
	}

	// Normalizing values
	for(int i = ind; i >= 0; i--){
		if(per[i] == str[len - 1]){
			// if i = 0, break
			per[i] = 0;
			per[i - 1]++;
		}
	}

	prnt(str, per);

}
