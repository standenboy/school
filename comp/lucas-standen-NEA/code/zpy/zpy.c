#include <stdio.h>

#include "../tokenizer/parser.h"
#include "../global/types.h"
#include "../tokenizer/tokenizer.h"
#include "../global/util.h"

int main(int argc, char **argv){
	if (argc < 2) {
		printf("repl not yet implemented\n");
		Die();
	}
	char **file = parser(argv[1]);

	for (int i = 0; i < 10; i++){
		printf("%s\n", file[i]);
	}	
	return 0;
}
