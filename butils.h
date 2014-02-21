#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

void swap(char *, char *);

unsigned int GetFileLen(FILE*);
string TrimString(string);
bool ReadLinesFromFile(string, vector<string>);
bool SeperateString(string, string, vector<string>);
int loadCharset(char *, char *, int *);
