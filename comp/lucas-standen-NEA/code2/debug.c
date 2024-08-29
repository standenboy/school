#include <stdio.h>
#include "tokenizer.h"

#include "util.h"

void printAST(astNode *head){
	printf("\n>>>\nfunc: %s\n", head->func);
	printf("args: ");
	for (int i = 0; i < 8; i++){
		if (head->children[i] == NULL && head->args[i] == NULL){
			printf("<<<");
			return;
		}
				
		if (head->args[i] != NULL){
			printf("%s ", head->args[i]);
		}
		if (head->children[i] != NULL){
			printAST(head->children[i]);
		}

	}
	printf("\n");
}
