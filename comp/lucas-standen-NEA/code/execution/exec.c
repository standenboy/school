#include <stdio.h>
#include <stdlib.h>

#include "./builtin.h"
#include "../global/util.h"
#include "../tokenizer/tokenizer.h"

int main(){
	char *sample = "(write ['h','e','l','l','o','\n'])";
	ast_node *root = tokenize(sample);
	doCall(root);	

	free(root);

	return 0;
}
