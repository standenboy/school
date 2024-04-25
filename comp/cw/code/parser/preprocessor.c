#include <stdbool.h>
#include <string.h>

#include "readfile.h"

char *preprocessor(int argc, char **argv){
	char *buf = readfile(argv[1]);
	if (buf == NULL)
		return NULL;
	
	int i = 0;

	while (buf[i] != '\0'){
		if (buf[i] == '\n'){
			buf[i] = ' ';
		}
		if (buf[i] == '\t'){
			buf[i] = ' ';
		}
		i++;
	}

	return buf;
}
