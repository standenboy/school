#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "preprocessor.h"

int main(int argc, char **argv){
	if (argc <= 1){
		printf("no args given!\n");
		return 1;
	}
	char *code = preprocessor(argc, argv);
	if (code == NULL){
		printf("falled to open file\n");
		return 1;
	}
	for (int i = 0; i < strlen(code); i++){
		if (code[i] == '{'){
			printf("\nopen-scope\n");
		} else if (code[i] == '}'){
			printf("\nclose-scope\n");
		}else {
			if (code[i] == '(')
				printf("\n");
			else if (code[i] != ')')
				printf("%c", code[i]);
		}
	}
	printf("\n");
	free(code);
	return 0;
}
