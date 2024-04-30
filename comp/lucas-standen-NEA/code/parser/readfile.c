#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool instring = false;

char *readfile(char *filepath){
	FILE *fptr;
	fptr = fopen(filepath, "r");

	if (fptr == NULL)
		return NULL;
	int size = 10;
	char *buf = malloc(size);
	char c;

	int i = 0;

	buf = buf+i;
	buf[0] = '{';
	buf = buf-i;
	
	i++;

	while ((c = getc(fptr)) != EOF){
		if (i > size + 1){
			size = size + 10;
			buf = realloc(buf, size);
		}
		if (c == '"'){
			if (instring == false)
				instring = true;
			else
				instring = false;
		}

		if (c == '!' && instring == false){
			while ((c = getc(fptr)) != EOF && c != '\n'){}
		}
		buf = buf+i;
		buf[0] = c;
		buf = buf-i;
		i++;

	}

	buf = buf+i;
	buf[0] = '}';
	buf = buf-i;
	
	i++;

	buf = buf+i;
	buf[0] = '\0';
	buf = buf-i;

	fclose(fptr);

	return buf;
}
