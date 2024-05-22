#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "util.h"
#include "types.h"

int functionIdCounter = 0;

ast_node *GenAst(char *exp); // generates the ast of 1 expression
int getArgCount(char *exp); // counts how many args are pressent in exp
char **GetStringArgs(char *exp); // gets the string args of an expression
char *GetFunction(char *exp); // gets the function used in 1 expression
builtInFuncs IsBuiltIn(char *func); // returns the id of a function thats built in, or -1 if its not


builtInFuncs IsBuiltIn(char *func){
	if (strcmp(func, "defun") == 0){
		return DEFUN;
	}else if (strcmp(func, "let") == 0){
		return LET;
	}else if (strcmp(func, "set") == 0){
		return SET;
	}else if (strcmp(func, "if") == 0){
		return IF;
	}else if (strcmp(func, "elif") == 0){
		return ELIF;
	}else if (strcmp(func, "else") == 0){
		return ELSE;
	}else if (strcmp(func, "for") == 0){
		return FOR;
	}else if (strcmp(func, "while") == 0){
		return WHILE;
	}else if (strcmp(func, "symbol") == 0){
		return SYMBOL;
	}else if (strcmp(func, "struct") == 0){
		return STRUCT;
	}else if (strcmp(func, "+") == 0){
		return ADD;
	}else if (strcmp(func, "-") == 0){
		return SUB;
	}else if (strcmp(func, "*") == 0){
		return MUL;
	}else if (strcmp(func, "/") == 0){
		return DIV;
	}else if (strcmp(func, "=") == 0){
		return EQ;
	}else if (strcmp(func, "!=") == 0){
		return NEQ;
	}else if (strcmp(func, ">") == 0){
		return GT;
	}else if (strcmp(func, "<") == 0){
		return LT;
	}else if (strcmp(func, ">=") == 0){
		return GTEQ;
	}else if (strcmp(func, "<=") == 0){
		return LTEQ;
	}else if (strcmp(func, "cast") == 0){
		return CAST;
	}else if (strcmp(func, "typeof") == 0){
		return TYPEOF;
	}else if (strcmp(func, "terminate") == 0){
		return TERMINATE;
	}else if (strcmp(func, "return") == 0){
		return RETURN;
	}
	else {
		return -1;
	}
}

char *GetFunction(char *exp){ // takes exp with brackets
	char *out = CheckedMalloc(strlen(exp));
	int i = 1;
	char c = exp[i];
	while (c != ' '){
		out[i-1] = c;
		i++;
		c = exp[i];
	}
	i++;
	out[i] = '\0';
	out = CheckedRealloc(out, i);
	return out;
}

// TODO make it count any arg inside () as one arg
char **GetStringArgs(char *exp){ // takes exp without brackets
	int spaceCount = 0;
	int i = 0;
	char c = exp[i];
	while (c != '\0'){
		spaceCount++;
		i++;
		c = exp[i];

	}

	char **out = CheckedMalloc(spaceCount);
	for (int i = 0; i < spaceCount; i++){
		out[i] = CheckedMalloc(strlen(exp));
	}

	int tokCounter = 0;
	i = 0;
	int charCounter = 0;
	while (exp[i] != '\0'){
		if (exp[i] != ' '){
			if (tokCounter != 0){
				out[tokCounter-1][charCounter] = exp[i];
				charCounter++;
			}
		} else{
			out[tokCounter][i] = '\0';
			charCounter = 0;
			tokCounter++;
		}
		i++;
	}

	return out;
}

ast_node *GenAst(char *exp){ // takes exp with brackets
	ast_node *head = CheckedMalloc(sizeof(ast_node));
	char *function = GetFunction(exp);
	head->builtInFunc = IsBuiltIn(function);	
	free(function);

	if (head->builtInFunc == -1){
		head->func = CheckedMalloc(sizeof(functionToken));
		head->func->id = functionIdCounter;
		functionIdCounter++;
	}else {
		head->func = NULL;
	}

	return head;
}

int main(){
	ast_node *node = GenAst("(+ 1 2)");
	printf("%d\n", node->builtInFunc);

	char **args = GetStringArgs("+ 1 2");
	for (int i = 0; i < 2; i++){
		printf("%s\n", args[i]);
	}

	free(args);

	free(node);
}
