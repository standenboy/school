#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "util.h"

typedef struct strings {
	char **strs;
	int count;
} strings;

//# counts the number of times c ocurrs in s
int countChars(char *s, char c){ 
	int count = 0;
	for (int i = 0; i < strlen(s); i++){
		if (s[i] == c) count++;	
	}
	return count;
}

//# returns an array of strings (type strings) of the file contents, split by line
strings *fileread(FILE *f){
	strings *strs = malloc(sizeof(strings));
	strs->strs = malloc(sizeof(char **));

	char *line = alloca(256);
	int count = 0;
	while (fgets(line, 256, f) != NULL){
		if (line[0] != '\n' && line[0] != '/'){ 
			while (line[0] == '\t') line++;
			line[strlen(line)-1] = '\0';
			strs->strs[count] = malloc(256);
			memcpy(strs->strs[count], line, 256);
			count++;
		}
	}
	strs->count = count;

	return strs;
}
