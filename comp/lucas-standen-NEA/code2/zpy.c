#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "parser.h"
#include "tokenizer.h"

#include "debug.h"

int main(int argc, char **argv){
	if (argc < 2)
		die("no input files!");
	
	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
		die("no such file or directory");

	strings *stringTokens = parse(f);

	if (stringTokens == NULL)
		die("couldn't parse file, is it formated properly?");



	for (int i = 0; i < stringTokens->count; i++){
		stringTokens->strs[i]++;
		stringTokens->strs[i][strlen(stringTokens->strs[i])] = '\0';
		astNode *line = tokenize(stringTokens->strs[i]);
	}
	
	
}
