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

	char *str = CheckedMalloc(20);
	switch (id){
		case ADD:
			snprintf(str, 20, "%d", atoi(node->literalArgs[0]) + atoi(node->literalArgs[1]));
			return str;
			break;
		case SUB:
			snprintf(str, 20, "%d", atoi(node->literalArgs[0]) - atoi(node->literalArgs[1]));
			return str;
			break;
		case DIV:
			snprintf(str, 20, "%d", atoi(node->literalArgs[0]) / atoi(node->literalArgs[1]));
			return str;
			break;
		case MUL:
			snprintf(str, 20, "%d", atoi(node->literalArgs[0]) * atoi(node->literalArgs[1]));
			return str;
			break;

		case WRITE:
			fputs(node->literalArgs[0], stdout);
			break;

		case EXIT:
			int returnValue = atoi(node->literalArgs[0]);
			CheckedFreeALL();
			exit(returnValue);
			break;
	}
}
