#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "parser.h"
#include "tokenizer.h"

int main(int argc, char **argv){
	if (argc < 2)
		die("no input files!");
	
	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
		die("no such file or directory");

	char **stringTokens = parse(f);

	if (stringTokens == NULL)
		die("couldn't parse file, is it formated properly?");
	
	tokenize(stringTokens[0]);
	
}
