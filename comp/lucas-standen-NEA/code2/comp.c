#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tokenizer.h"

#define MAXOUTLEN 512

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

void vartypeToC(char *str, char *out){
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

	snprintf(out, MAXOUTLEN, "%s%s %s", out, type, name);
	free(type);
	free(name);
}

char *getVarName(char *exp){
	char *out = malloc(strlen(exp));
	memcpy(out, exp, strlen(exp));
	char *pos = strchr(out, ':');
	pos[0] = '\0';
	return out;
}

void reversepolishToC(astNode *exp, char *out){
	snprintf(out, MAXOUTLEN, "%s ", exp->args[0]);
	if (exp->func[0] == '=') snprintf(out, MAXOUTLEN, "==");
	else snprintf(out, MAXOUTLEN, "%s", exp->func);
	snprintf(out, MAXOUTLEN, " %s", exp->args[1]);
}

void compile(astNode *node, char *out){
	if (strcmp(names[0], node->func) == 0){
		snprintf(out, MAXOUTLEN, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			vartypeToC(node->args[i], out);
			i++;
		}
		snprintf(out, MAXOUTLEN, "%s){\n", out);
	}
	else if (strcmp(names[1], node->func) == 0){
		snprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[2], node->func) == 0){
		snprintf(out, MAXOUTLEN, "const ");
		vartypeToC(node->args[0], out);
		snprintf(out, MAXOUTLEN, " = %s;\n", node->args[1]);
	}
	else if (strcmp(names[3], node->func) == 0){
		vartypeToC(node->args[0], out);
		snprintf(out, MAXOUTLEN, " = %s;\n", node->args[1]);
	}
	else if (strcmp(names[4], node->func) == 0){
		snprintf(out, MAXOUTLEN, "if (");
		reversepolishToC(node->children[0], out);
		snprintf(out, MAXOUTLEN, "){\n");
	}
	else if (strcmp(names[5], node->func) == 0){
		snprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[6], node->func) == 0){
		snprintf(out, MAXOUTLEN, "}\n");
		snprintf(out, MAXOUTLEN, "else if (");
		reversepolishToC(node->children[0], out);
		snprintf(out, MAXOUTLEN, "){\n");
	}
	else if (strcmp(names[7], node->func) == 0){
		snprintf(out, MAXOUTLEN, "}\n");
		snprintf(out, MAXOUTLEN, "else{");
	} 
	else if (strcmp(names[8], node->func) == 0){
		snprintf(out, MAXOUTLEN, "for (");
		vartypeToC(node->args[0], out);
		snprintf(out, MAXOUTLEN, " = 0;");
		reversepolishToC(node->children[1], out);
		snprintf(out, MAXOUTLEN, "; %s+=%s){", getVarName(node->args[0]), node->args[2]);
	} 
	else if (strcmp(names[9], node->func) == 0){
		snprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[10], node->func) == 0){
		snprintf(out, MAXOUTLEN, "printf(\"");
		snprintf(out, MAXOUTLEN, "%%d\\n");
		snprintf(out, MAXOUTLEN, "\", %s);", node->args[0]);
		
	}
	else if (strcmp(names[11], node->func) == 0){
		snprintf(out, MAXOUTLEN, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			vartypeToC(node->args[i], out);
			i++;
		}
		snprintf(out, MAXOUTLEN, ");\n");
	}
	else if (strcmp(names[12], node->func) == 0){
		reversepolishToC(node->children[0], out);
	}

	else {
		snprintf(out, MAXOUTLEN, "%s(", node->func);
		int i = 0;
		while (node->args[i] != NULL){
			snprintf(out, MAXOUTLEN, "%s", node->args[i]);
			i++;
		}
		snprintf(out, MAXOUTLEN, ");\n");
	}	
}

