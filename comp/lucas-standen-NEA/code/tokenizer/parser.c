#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../global/types.h"
#include "../global/util.h"

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

FILE *preProcess(char *contents){
	int currentSize = strlen(contents)+1;
	char *out = CheckedMalloc(currentSize);

	FILE *tmp = fopen("/tmp/zpy.tmp", "w+");

	for (char c = contents[0]; c != '\0'; c = (contents += 1)[0]){
		if (c == '"'){
			fprintf(tmp, "[");
			c = (contents += 1)[0];
			do {
				fprintf(tmp, "'%c'", c);
				if ((contents+1)[0] != '"') {
					fprintf(tmp, ",");
				}
				c = (contents += 1)[0];
			} while (c != '"');
			c = (contents += 1)[0];
			fprintf(tmp, "]");
		}	
		fprintf(tmp, "%c", c);
	}
	fprintf(tmp, "\n");
	return tmp;
}

char **getExpressions(char *file){
	int depth = 0;
	char *str = CheckedMalloc(strlen(file)+1);
	int pos = 0;
	for (int i = 0; i < strlen(file); i++){
		str[pos] = str[i];
		pos++;
		if (file[i] == '(')
			depth++;
		if (file[i] == ')')
			depth--;

		if (depth == 0) {
			str[pos] = '\0';
			printf("%s\n", str);
			pos = 0;
		}
	}

	return NULL;
}

char *parser(char *fileName){
	FILE *tmp = preProcess(readFile(fileName));
	fseek(tmp, 0, SEEK_END);
	int len = ftell(tmp);
	rewind(tmp);
	char *buf = CheckedMalloc(len);
	fgets(buf, len, tmp);
	fclose(tmp);
	getExpressions(buf);
	return buf;	
}
