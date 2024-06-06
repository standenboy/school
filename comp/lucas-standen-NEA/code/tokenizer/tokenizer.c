#include <stdio.h>
#include <string.h>

#include "types.h"
#include "util.h"

void getBuiltIn(char *func, ast_node *node){
	if (strcmp(func, "defun") == 0){
		node->func->builtInFunc = DEFUN;
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
	}
	else {
		node->func->builtInFunc = -1;
	}
}

ll_t *getUserDefinedFunction(char *function);

void expressFunction(char *function, ast_node *node){
	if ((node->func->builtInFunc = getBuiltIn(function)) == -1){
		node->func->func = getUserDefinedFunction(function);
	} else {
		node->func->func = NULL;
	}
}

ast_node *tokenize(char *input){
	ast_node *node;

	char *exp, *function, **args;
	size_t i, j;
	int depth;

	for (int i = 0; i < strlen(input); i++){
		if (input[i] == '('){
			depth = 1;
			j = i;
			exp = CheckedMalloc(strlen(input));
			while (depth != 0){
				if (input[j] == '('){
					depth++;
				} else if (input[j] == ')'){
					depth--;
				}
				exp[j - i] = input[j+1];
				j++;
				if (input[j] == '\0'){
					fprintf(stderr, "error brace not closed");
					exit(1);
				}
			}
			j -= 2;
			exp[j] = '\0';
			printf("%s\n", exp);
		}else if (input[i] == '"'){
			i++;
			while (input[i] != '"') i++;
		}
	}

	node = CheckedMalloc(sizeof(ast_node));

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

	free(function);
	free(exp);

	return NULL;
}

int main(){
	char sample[] = "(+ \"hello(\" 1)";
	tokenize(sample);
}
