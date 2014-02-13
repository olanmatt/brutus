#include <stdio.h>
#include "butils.h"

// Code originally from StackOverflow user Dukeling
void permute(char *str, int start, int n, int minLength, int maxLength){
	int i;

	if (start >= minLength){
		char temp = str[start]; // store the character, so we don't lose it
		str[start] = 0; // 0x00 - end of string
		printf("%s\n", str);
		str[start] = temp;
	}

	if (start == maxLength)
		return;

	for (i = start; i < n; i++){
		swap(str+i, str+start);
		permute(str, start+1, n, minLength, maxLength);
		swap(str+i, str+start);
	}
}
