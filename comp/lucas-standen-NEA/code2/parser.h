#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "util.h"

typedef struct strings {
	char **strs;
	int count;
} strings;

strings *parse(FILE *f);
