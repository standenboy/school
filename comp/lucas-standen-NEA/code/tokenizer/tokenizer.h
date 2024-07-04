#include <stdio.h>
#include <string.h>

#define MAXARGS 8
#define MAXFUNCS 2048
#define MAXVARS 8192

int getBuiltIn(char *func, ast_node *node); // checks if a function is built in to zippy
void expressFunction(char *function, ast_node *node); // puts a string into the ast_node struct
ast_node *tokenize(char *input); // does the tokenization
void printAst(ast_node *root); // shows an ast and its sub nodes
void freeAst(ast_node *head); // frees most of the ast;
