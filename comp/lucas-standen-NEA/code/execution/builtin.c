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

	literal *out = CheckedMalloc(sizeof(literal));
	switch (id){
		case ADD:
    			out->i64 = CheckedMalloc(sizeof(I64));
			out->i64->data = node->literalArgs[0]->i64->data + node->literalArgs[1]->i64->data;
			return out;
			break;
			
	       	case SUB:
    			out->i64 = CheckedMalloc(sizeof(I64));
			out->i64->data = node->literalArgs[0]->i64->data - node->literalArgs[1]->i64->data;
			return out;
			break;
		case DIV:
    			out->i64 = CheckedMalloc(sizeof(I64));
			out->i64->data = node->literalArgs[0]->i64->data / node->literalArgs[1]->i64->data;
			return out;
			break;
		case MUL:
    			out->i64 = CheckedMalloc(sizeof(I64));
			out->i64->data = node->literalArgs[0]->i64->data * node->literalArgs[1]->i64->data;
			return out;
			break;

		case WRITE:
			for (int i = 0; i < node->literalArgs[0]->arr->len; i++)
				fputc(node->literalArgs[0]->arr->arr[i].ch->data, stdout);
			break;
		
		case EXIT:
			int returnValue = (int)node->literalArgs[0]->i64->data;
			exit(returnValue);
			break;
	}
}
