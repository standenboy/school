#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "util.h"

int countChars(char *s, char c){
	int count = 0;
	for (int i = 0; i < strlen(s); i++){
		if (s[i] == c) count++;	
	}
	return count;
}

char **parse(FILE *f){
	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	rewind(f);
	
	char *contents = malloc(len);
	
	if (fread(contents, 1, len, f) == 0){
		die("failed to read file, is it formated properly");
	}

	char **tokens = malloc(countChars(contents, '\n'));

	int tokCount = 0;
	int charCount = 0;
	char *line = malloc(strlen(contents));
	for (int i = 0; i < len; i++){
		line[charCount] = contents[i];
		charCount++;
			
		if (contents[i] == '\n'){
			charCount--;
			line[charCount] = '\0';
			tokens[tokCount] = malloc(strlen(line)+1);

			memcpy(tokens[tokCount], line, strlen(line)+1);
			charCount = 0;
			tokCount++;
		}	
	}
	
	free(line);
	free(contents);

	return tokens;
}
