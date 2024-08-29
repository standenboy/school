#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "util.h"

typedef struct astNode {
	char *func;
	char *args[8];
	struct astNode *children[8];
} astNode;

int readuntil(char *src, char c, char *dst){ // returns how many chars read, will read until 
					     // the end of an expression, not the first 
					     // occurence
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


astNode *tokenize(char *line){ // asume the first set of brackets have been stripped
	astNode *head = malloc(sizeof(astNode));

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
			i += readuntil(&line[i], ' ', chunk); // reads func name or arg
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
