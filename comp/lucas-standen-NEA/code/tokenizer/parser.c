#include <stdio.h>
#include <stdlib.h>

#include "../global/util.h"

char *ReadFile(char *fileName); // reads the file into a single var
char *Parse(char *fileName); // general parser function

char *ReadFile(char *filename){
	FILE *f = fopen(filename, "r");
	if (f == NULL)
		Die();	

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	rewind(f);
	
	char *out = malloc(len+1);

	char c;
	for (int i = 0; i < len; i++){
		c = fgetc(f);	
		if (c == '\n' || c == '\t')
			out[i] = ' ';
		else
			out[i] = c;
	}
	out[len+1] = '\0';

	fclose(f);
	return out;
}

char *Parser(char *fileName){
	return ReadFile(fileName);
}
