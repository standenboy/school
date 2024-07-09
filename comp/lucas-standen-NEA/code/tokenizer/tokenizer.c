#include <stdio.h>
#include <string.h>

#include "../global/types.h"
#include "../global/util.h"

#define MAXARGS 8
#define MAXFUNCS 2048
#define MAXVARS 8192

int getBuiltIn(char *func, ast_node *node); // checks if a function is built in to zippy
void expressFunction(char *function, ast_node *node); // puts a string into the ast_node struct
ast_node *tokenize(char *input); // does the tokenization
void printAst(ast_node *root); // shows an ast and its sub nodes

int getBuiltIn(char *func, ast_node *node){ // returns NIL when the function doesn't exist
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
	}else if (strcmp(func, "write") == 0){
		node->func->builtInFunc = WRITE;
	}else {
		node->func->builtInFunc = NIL;
		return -1;
	}
	return 0;
}

void expressFunction(char *function, ast_node *node){
	node->func = CheckedMalloc(sizeof(functionToken));
	if ((getBuiltIn(function, node)) == NIL) // non user defined function
		node->func->name = function;
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

	expressFunction(function, node);

	char *tok;
	tok = strtok(strstr(exp, " ") + 1, " ");
	argCount = 0;
	depth = 0;
	do {
		if (node->args[argCount] != NULL){
			argCount++;
		}
		if (tok[0] != '(' && tok[strlen(tok)-1] != ')' && depth == 0){
			if (node->args[argCount] == NULL){
				node->literalArgs[argCount] = giveType(tok);
			}
			argCount++;
		}
		
		if (tok[0] == '(') depth++;
		if (tok[strlen(tok)-1] == ')') depth--;
		tok = strtok(NULL, " ");
	} while (tok != NULL);

	free(exp);

	return node;
}

void printAst(ast_node *root){
	printf("-----------\n");
	if (root->func->builtInFunc == -1) printf("function: %s\n", root->func->name);
	else printf("function (built in): %d\n", root->func->builtInFunc);
	for (int i = 0; i < MAXARGS + 1; i++){
		if (root->args[i] != NULL) printAst(root->args[i]);
		else {
			if (root->literalArgs[i] != NULL) printf("%s\n", root->literalArgs[i]);
		}
	}
	printf("-----------\n");
}
