#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

char *names[] = {
	"defun", // takes a func name, func return type, and args // 0
	"endfun", // takes no args // 1
	"let", // takes a name and type, then a value (immutable) // 2
	"set", // same as above but mutable values // 3
	"if", // takes a condition // 4
	"endif", // takes no args  // 5
	"elif", // same as if, but only executes if the prev statment didnt // 6
	"else", // its else! // 7
	"for", // takes a iterator and type, a condition, and an increment // 8
	"endfor", // takes no args // 9
	"write", // takes an int and puts it on the screen // 10
	"symbol", // takes a name and return type and args
	"+",
	"-",
	"*",
	"/",
	"=",
	"!=",
	"<",
	">",
	"<=",
	">=",
	"cast",
	"typeof",
	"exit",
	"return",
};

void vartypeToC(char *str, FILE *f){
	char *name = malloc(strlen(str));
	char *type = malloc(strlen(str));
	
	int j = 0, i = 0;

	for (; i < strlen(str); i++){
		if (str[i] == ':'){
			break;
		}
		name[i] = str[i];
	}
	name[i] = '\0';
	i++;

	for (; i < strlen(str); i++){
		if (str[i] == ':'){
			break;
		}
		type[j] = str[i];
		j++;
	}
	type[j] = '\0';

	fprintf(f, "%s %s", type, name);
	free(type);
	free(name);
}

char *getVarName(char *exp, FILE *f){
	char *out = malloc(strlen(exp));
	memcpy(out, exp, strlen(exp));
	char *pos = strchr(out, ':');
	pos[0] = '\0';
	return out;
}

void reversepolishToC(astNode *exp, FILE *f){
	fprintf(f, "%s ", exp->args[0]);
	if (exp->func[0] == '=') fprintf(f, "==");
	else fprintf(f, "%s", exp->func);
	fprintf(f, " %s", exp->args[1]);
}

void compile(astNode *node, FILE *f){
	if (strcmp(names[0], node->func) == 0){
		fprintf(f, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			vartypeToC(node->args[i], f);
			i++;
		}
		fprintf(f, "){\n");
	}
	else if (strcmp(names[1], node->func) == 0){
		fprintf(f, "\n}\n");
	}
	else if (strcmp(names[2], node->func) == 0){
		fprintf(f, "const ");
		vartypeToC(node->args[0], f);
		fprintf(f, " = %s;\n", node->args[1]);
	}
	else if (strcmp(names[3], node->func) == 0){
		vartypeToC(node->args[0], f);
		fprintf(f, " = %s;\n", node->args[1]);
	}
	else if (strcmp(names[4], node->func) == 0){
		fprintf(f, "if (");
		reversepolishToC(node->children[0], f);
		fprintf(f, "){\n");
	}
	else if (strcmp(names[5], node->func) == 0){
		fprintf(f, "\n}\n");
	}
	else if (strcmp(names[6], node->func) == 0){
		fprintf(f, "\n}\n");
		fprintf(f, "else if (");
		reversepolishToC(node->children[0], f);
		fprintf(f, "){\n");
	}
	else if (strcmp(names[7], node->func) == 0){
		fprintf(f, "\n}\n");
		fprintf(f, "else{");
	} 
	else if (strcmp(names[8], node->func) == 0){
		fprintf(f, "for (");
		vartypeToC(node->args[0], f);
		fprintf(f, " = 0;");
		reversepolishToC(node->children[1], f);
		fprintf(f, "; %s+=%s){", getVarName(node->args[0], f), node->args[2]);
	} 
	else if (strcmp(names[9], node->func) == 0){
		fprintf(f, "\n}\n");
	}
	else if (strcmp(names[10], node->func) == 0){
		fprintf(f, "printf(\"");
		fprintf(f, "%%d\\n");
		fprintf(f, "\", %s);", node->args[0]);
		
	}
	else if (strcmp(names[11], node->func) == 0){
		fprintf(f, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			vartypeToC(node->args[i], f);
			i++;
		}
		fprintf(f, ");\n");
	}
	else if (strcmp(names[12], node->func) == 0){
		reversepolishToC(node->children[0], f);
	}

	else {
		fprintf(f, "%s(", node->func);
		int i = 0;
		while (node->args[i] != NULL){
			fprintf(f, "%s", node->args[i]);
			i++;
		}
		fprintf(f, ");\n");
	}	
}

