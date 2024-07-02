#include <stdio.h>
#include <stdlib.h>

#include "./builtin.h"

#include "../global/util.h"

#include "../tokenizer/tokenizer.h"

int main(){
	char *sample = "(exit (+ 1 1))";
	ast_node *root = tokenize(sample);
	doCall(root);	

	CheckedFreeALL();
	
	return 0;
}
