#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct docpair {
	char *doc;
	char *func;
} docpair;

docpair funcs[2048];
int count = 0;

//# returns a bool as to weather s2 is contained fully in s1
bool contains(char *s1, char *s2){
	int j = 0;
	if (strlen(s1) < strlen(s2)) return false;
	for (int i = 0; i < strlen(s1); i++){
		if (s1[i] == s2[j]){
			if (j+1 == strlen(s2)) return true;
			j++;
		}
	}
	return false;
}

int main(int argc, char **argv){
	FILE *in;
	if (argv[1][0] == '-') in = stdin;
	else in = fopen(argv[1], "r");

	char *search = argv[2];

	char *line = malloc(512);
	char *tmp = malloc(512);

	bool nextIsFunc = false;

	while (fgets(line, 512, in) != NULL){
		strcpy(tmp, line);
		tmp[4] = '\0';
		if (strcmp(tmp, "//# ") == 0){
			funcs[count].doc = malloc(strlen(line)+1);
			strcpy(funcs[count].doc, line);
			nextIsFunc = true;
		}
		else if (nextIsFunc == true){
			funcs[count].func = malloc(strlen(line)+1);
			strcpy(funcs[count].func, line);
			nextIsFunc = false;
			count++;
		}
	}
	
	if (search != NULL){
		for (int i = 0; i < 2048; i++){
			if (funcs[i].doc != NULL)
				if (contains(funcs[i].func, search)) 
					printf("%s \e[1m%s\e[0m\n", funcs[i].doc, funcs[i].func);
		}
	}
	else {
		for (int i = 0; i < 2048; i++){
			if (funcs[i].doc != NULL)
				printf("%s \e[1m%s\e[0m\n", funcs[i].doc, funcs[i].func);
		}
	}

	free(line);
	free(tmp);


}
