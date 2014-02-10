#include <stdio.h>
#include <string.h>

void swap(char *x, char *y){
	char w;
	w = *x;
	*x = *y;
	*y = w;
}

void permute(char *str, int start, int n){
	int i;

	if(start == n-1)
		printf("%s\n", str);
	else
		for(i = start; i < n; i++){
			swap(str+i, str+start);
			permute(str, start+1, n);
			swap(str+i, str+start);
		}
}

int main(){
	char line[10], str[10];
	int n, op;

	printf("Enter a string: ");
	if( fgets(line, 10, stdin) == NULL ){
		printf("Ops! Early stop\n");
		return 1;
	}

	if( sscanf(line, "%s", str) != 1 ){
		printf("Next time put some valid characters\n");
		return 1;
	}

	n = strlen(str);
	permute(str, 0, n);
	return 0;
}
