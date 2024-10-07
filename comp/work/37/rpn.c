#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <math.h>

#include "stack.h"

int main(int argc, char **argv){
	stack *s = initstack(0, 64);
	char in[128] = {0};

	if (argc > 1){
		for (int i = 1; i < argc; i++){
			strcat(in, argv[i]);
			strcat(in, " ");
		}
	} else fgets(in, 128, stdin);

	for (int i = 0; i < 128; i++) if (in[i] == '\n') in[i] = '\0';
	fflush(stdin);

	int r;

	int a;
	int b;

	char *tok = strtok(in, " ");
	while (tok != NULL){
		switch (tok[0]) {
			case '+':
				a = s->pop(s);
				b = s->pop(s);
				s->push(s, b+a);
				break;
			case '-':
				a = s->pop(s);
				b = s->pop(s);
				s->push(s, b-a);
				break;
			case '*':
				a = s->pop(s);
				b = s->pop(s);
				s->push(s, b*a);
				break;
			case '/':
				a = s->pop(s);
				b = s->pop(s);
				s->push(s, b/a);
				break;
			case '^':
				a = s->pop(s);
				b = s->pop(s);
				s->push(s, pow(b, a));
				break;
			case '.': 
				r = s->pop(s);
				printf("%d\n", r);
				break;
			default:
				s->push(s, atoi(tok));
				break;
		}
		tok = strtok(NULL, " ");
		if (tok == NULL){
			r = s->pop(s);
			printf("%d\n", r);
			break;
		}
	}
	s->free(s);
	return 0;
}
