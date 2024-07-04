#include <stdio.h>
#include <stdlib.h>

#include "../global/types.h"
#include "../global/util.h"

char *readFile(char *fileName); // reads the file into a single var
char *parse(char *fileName); // general parser function

char *readFile(char *filename){
	FILE *f = fopen(filename, "r");
	if (f == NULL)
		Die();	

	fseek(f, 0, SEEK_END);
	size_t len = ftell(f);
	rewind(f);
	
	char *out = CheckedMalloc(len+1);

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

char *preProcess(char *contents){
	char *out = CheckedMalloc(strlen(contents)+1);
	for (char c = contents[0]; c != '\0'; c = (contents += 1)[0]){
		printf("%c", c);
	}
}

char *parser(char *fileName){
	return readFile(fileName);
}
