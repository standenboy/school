#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "util.h"

typedef struct astNode {
	char *funcName;
	char *args[8];
	struct astNode *children[8];
} astNode;

astNode *tokenize(char *line){
	astNode *head = malloc(sizeof(astNode));

	int depth = 0;
	int charCount = 0;
	int argCount = 0;


	for (int i = 0; i < strlen(line); i++){
		switch (line[i]){
			case ' ':
				argCount++;
				charCount = 0;
				break;
			case '(':
				1
			default:
				if (argCount >= 1){
					head->args[argCount][charCount] = line[i];
					charCount++;
				}
				else {
					head->funcName[charCount] = line[i];
					charCount++;
				}
		}
	}

	return NULL;
}
