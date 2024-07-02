#include <stdlib.h>
#include <stdio.h>
#include "../global/types.h"
#include "../global/util.h"

#define MAXARGS 8

void *doCall(ast_node *node){
	builtInFuncs id = node->func->builtInFunc;
	for (int i = 0; i < MAXARGS; i++){
		if (node->args[i] != NULL){
			node->literalArgs[i] = doCall(node->args[i]);
		}
	}

	I64 *outi64 = CheckedMalloc(sizeof(I64));
	switch (id){
		case ADD:
			outi64->data = node->literalArgs[0]->i64->data + node->literalArgs[1]->i64->data;
			return outi64;
			break;
		case SUB:
			outi64->data = node->literalArgs[0]->i64->data - node->literalArgs[1]->i64->data;
			return outi64;
			break;
		case DIV:
			outi64->data = node->literalArgs[0]->i64->data / node->literalArgs[1]->i64->data;
			return outi64;
			break;
		case MUL:
			outi64->data = node->literalArgs[0]->i64->data * node->literalArgs[1]->i64->data;
			return outi64;
			break;

		case WRITE:
			fputs(node->literalArgs[0], stdout);
			break;

		case EXIT:
			int returnValue = node->literalArgs[0]->i64->data;
			CheckedFreeALL();
			exit(returnValue);
			break;
	}
}
