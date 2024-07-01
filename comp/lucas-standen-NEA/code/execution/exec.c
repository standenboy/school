#include <stdio.h>
#include <stdlib.h>

#include "./builtin.h"

#include "../global/util.h"

#include "../tokenizer/tokenizer.h"

int main(){
	char *sample = "(write (* 2 5))"; 
	ast_node *root = tokenize(sample);
	doCall(root);	
	sample = "(write \n)";
	root = tokenize(sample);
	doCall(root);	
	sample = "(exit 0)";
	root = tokenize(sample);
	doCall(root);	

	CheckedFreeALL();
	
	return 0;
}
