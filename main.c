#include <stdio.h>
#include "permute.h"

int main(void) {
	char str[] = "hello";
	permute(str, 0, 5, 2, 4);
	return 0;
}

