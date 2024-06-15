#include <stdio.h>
#include <string.h>

#include "types.h"
#include "util.h"

#define MAXARGS 8

int getBuiltIn(char *func, ast_node *node){
	if (strcmp(func, "defun") == 0){
		node->func->builtInFunc= DEFUN;
	}else if (strcmp(func, "let") == 0){
		node->func->builtInFunc = LET;
	}else if (strcmp(func, "set") == 0){
		node->func->builtInFunc = SET;
	}else if (strcmp(func, "if") == 0){
		node->func->builtInFunc = IF;
	}else if (strcmp(func, "elif") == 0){
		node->func->builtInFunc = ELIF;
	}else if (strcmp(func, "else") == 0){
		node->func->builtInFunc = ELSE;
	}else if (strcmp(func, "for") == 0){
		node->func->builtInFunc = FOR;
	}else if (strcmp(func, "while") == 0){
		node->func->builtInFunc = WHILE;
	}else if (strcmp(func, "symbol") == 0){
		node->func->builtInFunc = SYMBOL;
	}else if (strcmp(func, "+") == 0){
		node->func->builtInFunc = ADD;
	}else if (strcmp(func, "-") == 0){
		node->func->builtInFunc = SUB;
	}else if (strcmp(func, "*") == 0){
		node->func->builtInFunc = MUL;
	}else if (strcmp(func, "/") == 0){
		node->func->builtInFunc = DIV;
	}else if (strcmp(func, "=") == 0){
		node->func->builtInFunc = EQ;
	}else if (strcmp(func, "!=") == 0){
		node->func->builtInFunc = NEQ;
	}else if (strcmp(func, ">") == 0){
		node->func->builtInFunc = GT;
	}else if (strcmp(func, "<") == 0){
		node->func->builtInFunc = LT;
	}else if (strcmp(func, ">=") == 0){
		node->func->builtInFunc = GTEQ;
	}else if (strcmp(func, "<=") == 0){
		node->func->builtInFunc = LTEQ;
	}else if (strcmp(func, "cast") == 0){
		node->func->builtInFunc = CAST;
	}else if (strcmp(func, "typeof") == 0){
		node->func->builtInFunc = TYPEOF;
	}else if (strcmp(func, "exit") == 0){
		node->func->builtInFunc = EXIT;
	}else if (strcmp(func, "return") == 0){
		node->func->builtInFunc = RETURN;
	}else {
		node->func->builtInFunc = NIL;
		return -1;
	}
	return 0;
}

ll_t *getUserDefinedFunction(char *function);

void expressFunction(char *function, ast_node *node){
	node->func = CheckedMalloc(sizeof(functionToken));
	if ((getBuiltIn(function, node)) == -1){
		//node->func->func = getUserDefinedFunction(function);
	} else {
		node->func->func = NULL;
	}
}

void expressArgs(char **args, ast_node *node){
	for (int i = 0; i < MAXARGS; i++){
		if (node->args[i] == NULL){
			memcpy(node->literalArgs[i], args[i], strlen(args[i]) + 1);
		}
	}
	
}

ast_node *tokenize(char *input){
	ast_node *node, *child;

	char *exp, *function, **args;
	size_t i = 0, argCount = -1;
	int depth = 0;

	node = CheckedMalloc(sizeof(ast_node));
	node->args = CheckedMalloc(sizeof(ast_node) * MAXARGS);
	node->literalArgs = CheckedMalloc(sizeof(void *) * MAXARGS);

	if (input[i] == '('){
		depth = 1;
		i++;
		exp = CheckedMalloc(strlen(input));
		while (depth != 0){
			if (input[i] == ' ') argCount++;
			if (input[i] == '('){
				child = tokenize(&input[i]);
				node->args[argCount] = child;
				depth++;
			} else if (input[i] == ')'){
				depth--;
			}
			exp[i - 1] = input[i];
			if (input[i] == '\0'){
				fprintf(stderr, "error brace not closed\n");
				exit(1);
			}
			i++;
		}
		exp[i-2] = '\0';
		exp = CheckedRealloc(exp, strlen(exp) + 1);
		printf("%s\n", exp);
	}else if (input[i] == '"'){
		i++;
		while (input[i] != '"') i++;
	}


	i = 0;
	function = CheckedMalloc(strlen(exp));
	while (exp[i] != ' '){
		function[i] = exp[i];
		i++;	
	}

	function[i] = '\0';
	function = CheckedRealloc(function, i);
	printf("%s\n", function);

	expressFunction(function, node);

	i++;
	args = Split(&input[i], ' ');
	// need a length
	expressArgs(args, node /* length */ );

	free(exp);

	return node;
}

int main(){
	char sample[] = "(+ (- 2 2) 1)";
	ast_node *root = tokenize(sample);
	printf("%d", root->args[0]->func->builtInFunc);
	free(root);
}
