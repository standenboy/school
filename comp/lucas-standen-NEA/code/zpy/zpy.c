#include <stdio.h>

#include "../tokenizer/parser.h"
#include "../global/types.h"
#include "../global/util.h"

int main(int argc, char **argv){
	if (argc < 2) {
		printf("repl not yet implemented\n");
		Die();
	}
	parser(argv[1]);
	return 0;
}
