#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
// http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
/*char *trimwhitespace(char *str){
	char *end;

	// Trim leading space
	while(isspace(*str)) str++;
	if(*str == 0) // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while(end > str && isspace(*end)) end--;

	// Write new null terminator
	*(end+1) = 0;
	return str;
}*/

/*char** str_split(char* a_str, const char a_delim){
	char** result    = 0;
	size_t count     = 0;
	char* tmp        = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	// Count how many elements will be extracted.
	while (*tmp){
		if (a_delim == *tmp){
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	// Add space for trailing token.
	count += last_comma < (a_str + strlen(a_str) - 1);

	// Add space for terminating null string so caller
	// knows where the list of returned strings ends.
	count++;

	result = malloc(sizeof(char*) * count);

	if (result){
		size_t idx  = 0;
		char* token = strtok(a_str, delim);

		while (token){
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}
	return result;
}*/
