#include <stdio.h>

void swap(char *x, char *y){
	char w;
	w = *x;
	*x = *y;
	*y = w;
}

void prnt(char *str, int *per) {
	for(int i = 0; per[i] != -1; i++)
		printf("%c", str[per[i]]);
	printf("\n");
}
