#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "util.h"
#include "appendsnprintf.h"

typedef struct astNode {
	char *func;
	char *args[8];
	struct astNode *children[8];
} astNode;

//# reads a block of code from src, until char, outputting to dst, it allows for brackets so it stays on the same depth
static int readuntil(char *src, char c, char *dst){ 
	int ptr = 0;
	int depth = 0;
	int i = 0;

	while ((src[i] != c || depth != 0) && src[i] != '\0'){
		if (c == ')'){
			if (src[i] == '('){
				depth++;
			}else if (src[i] == ')'){
				depth--;
			}
		}
		dst[ptr] = src[i];
		ptr++;
		i++;
	}
	
	dst[ptr] = '\0';

	return i;
}

//# this function will converts one line of zpy into an astNode, which can be compiled
astNode *tokenize(char *line){ // asume the first set of brackets have been stripped
	astNode *head = malloc(sizeof(astNode));
	head->func = NULL;
	for (int i = 0; i < 8; i++){
		head->args[i] = NULL;
		head->children[i] = NULL;
	}	

	int depth = 0;
	int argCount = 0;
	int i = 0;

top:
	for (;i < strlen(line); i++){
		char *chunk = malloc(strlen(line));
		if (line[i] == ')'){ 
			i++; 
			goto top;
		}
		if (line[i] == '('){
			i++;
			i += readuntil(&line[i], ')', chunk); // reads a nested function
			i++;
			head->children[argCount] = tokenize(chunk);
			argCount++;
		}else { 
			if (line[i] == '"'){
				i += readuntil(&line[i+1], '"', chunk); // reads a comptime string 
				i++;
				char *tmp = malloc(strlen(chunk)+2);
				tmp[0] = '"';
				tmp[1] = '\0';
				strcat(tmp, chunk);
				strcat(tmp, "\"");
				chunk = tmp;

			}
			else {
				i += readuntil(&line[i], ' ', chunk); // reads func name or arg
			}
			if (head->func == NULL){
				head->func = chunk;
			} else{
				head->args[argCount] = chunk;
				argCount++;
			} 
		}
	}

	return head;
}
