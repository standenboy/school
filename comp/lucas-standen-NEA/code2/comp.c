#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "tokenizer.h"
#include "util.h"
#include "appendsnprintf.h"

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
	"for", // takes a iterator and type, a start point, a condition, and an increment // 8
	"endfor", // takes no args // 9
	"symbol", // takes a name and return type and args // 10
	// arithmetic
	"+", // 11
	"-", // 12
	"*", // 13
	"/", // 14
	// comparison
	"=", // 15
	"!=", // 16
	"<", // 17
	">", // 18
	"<=", // 19
	">=", // 20

	"exit", // takes an int // 21
	"return", // takes an int // 22
	
	"alloc", // takes a size and allocates a block of it // 23
	
	"struct", // takes a name for the struct // 24
	"endstruct", // takes nothing // 25
	
	"def", // takes a name and type does not asign // 26
	
	"sizeof", // takes a datatype and returns its size // 27
	
	"defunptr" // takes the same stuff as defun but outputs it in fuction ptr form 
};

// function prototype for recursion
char *compile(astNode *node);

// globals for memory management
char *tofree[256];
int freeptr = 0;
bool neededmemptr = false;

// globals for stucts
char *structname;

char *vartypeToC(char *str, char *out){
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

	char *outbuf = calloc(0, 64);
	outbuf = appendsnprintf(outbuf, MAXOUTLEN, "%s %s", type, name);
	out = appendsnprintf(out, MAXOUTLEN, "%s", outbuf);
	free(type);
	free(name);
	return out;
}

char *getVarName(char *exp){
	char *out = malloc(strlen(exp));
	memcpy(out, exp, strlen(exp));
	char *pos = strchr(out, ':');
	pos[0] = '\0';
	return out;
}

char *getVarType(char *exp){
	char *out = malloc(strlen(exp));
	char *pos = strchr(exp, ':')+1;
	memcpy(out, pos, strlen(pos) + 1);	
	return out;
}

char *reversepolishToC(astNode *exp, char *out){
	out = appendsnprintf(out, MAXOUTLEN, "%s ", exp->args[0]);
	if (exp->func[0] == '=') out = appendsnprintf(out, MAXOUTLEN, "==");
	else out = appendsnprintf(out, MAXOUTLEN, "%s", exp->func);
	out = appendsnprintf(out, MAXOUTLEN, " %s", exp->args[1]);
	return out;
}

astNode *processChildren(astNode *node){
	for (int i = 0; i < 8; i++){
		if (node->children[i] != NULL){
			node->args[i] = compile(node->children[i]);
			node->children[i] = NULL;
		}
	}
	return node;
}


char *compile(astNode *node){
	char *out = calloc(0, MAXOUTLEN);
	node = processChildren(node);
	if (strcmp(names[0], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			if (i != 2) out = appendsnprintf(out, MAXOUTLEN, ",");
			out = vartypeToC(node->args[i], out);
			i++;
		}
		out = appendsnprintf(out, MAXOUTLEN, "){\n");
	}
	else if (strcmp(names[1], node->func) == 0){
		
		out = appendsnprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[2], node->func) == 0){
		out = vartypeToC(node->args[0], out);
		out = appendsnprintf(out, MAXOUTLEN, " = %s;\n", node->args[1]);
	}
	else if (strcmp(names[3], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "%s = %s;\n", node->args[0], node->args[1]);
	}
	else if (strcmp(names[4], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "if (%s", node->args[0]);
		out = appendsnprintf(out, MAXOUTLEN, "){\n");
	}
	else if (strcmp(names[5], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[6], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "else if (%s", node->args[0]);
		out = appendsnprintf(out, MAXOUTLEN, "){\n");
	}
	else if (strcmp(names[7], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "}\n");
		out = appendsnprintf(out, MAXOUTLEN, "else{");
	} 
	else if (strcmp(names[8], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "for (");
		out = vartypeToC(node->args[0], out);
		out = appendsnprintf(out, MAXOUTLEN, " = %s;", node->args[1]);
		out = appendsnprintf(out, MAXOUTLEN, "%s", node->args[2]);
		out = appendsnprintf(out, MAXOUTLEN, "; %s+=%s){", getVarName(node->args[0]), node->args[3]);
	} 
	else if (strcmp(names[9], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "}\n");
	}
	else if (strcmp(names[10], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "%s %s(", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			if (i != 2) out = appendsnprintf(out, MAXOUTLEN, ",", node->args[i]);
			out = vartypeToC(node->args[i], out);
			i++;
		}
		out = appendsnprintf(out, MAXOUTLEN, ");\n");
	}
	else if (strcmp(names[21], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "exit(%s);\n", node->args[0]);
	}	
	else if (strcmp(names[22], node->func) == 0){
		for (int i = 0; i < 256; i++){
			if (tofree[i] != NULL){
				out = appendsnprintf(out, MAXOUTLEN, "free(%s);\n", tofree[i]);
			} else{
				for (int j = 0; j < 256; j++){
					tofree[j] = NULL;
				}
				freeptr = 0;
				break;
			}
		}
		out = appendsnprintf(out, MAXOUTLEN, "return %s;\n", node->args[0]);
	}	
	else if (strcmp(names[23], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "calloc(0, %s)", node->args[0]);
		neededmemptr = true;
	}	
	else if (strcmp(names[24], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "typedef struct %s %s;\n", node->args[0], node->args[0]);
		out = appendsnprintf(out, MAXOUTLEN, "typedef struct %s {", node->args[0]);
		structname = node->args[0];
	}	
	else if (strcmp(names[25], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "} %s", structname);
		structname = NULL;
	}	
	else if (strcmp(names[26], node->func) == 0){
		out = vartypeToC(node->args[0], out);
	}	
	else if (strcmp(names[27], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "sizeof(%s)", node->args[0]); 
	}
	else if (strcmp(names[28], node->func) == 0){
		out = appendsnprintf(out, MAXOUTLEN, "%s (*%s)", node->args[1], node->args[0]);
		int i = 2;
		while (node->args[i] != NULL){
			if (i != 2) out = appendsnprintf(out, MAXOUTLEN, ",");
			else out = appendsnprintf(out, MAXOUTLEN, "(");
			out = appendsnprintf(out, MAXOUTLEN, "%s", getVarType(node->args[i]));
			i++;
		}
		out = appendsnprintf(out, MAXOUTLEN, ")");
	}
	
	else {
		// arithmetic operators and comparitors
		for (int i = 0; i < 9; i++){
			if (strcmp(names[11+i], node->func) == 0){
				out = reversepolishToC(node, out);
				goto end;
			}
		}

		out = appendsnprintf(out, MAXOUTLEN, "%s(", node->func);
		int i = 0;
		while (node->args[i] != NULL){
			if (i != 0) out = appendsnprintf(out, MAXOUTLEN, ",", node->args[i]);
			out = appendsnprintf(out, MAXOUTLEN, "%s", node->args[i]);
			i++;
		}
		out = appendsnprintf(out, MAXOUTLEN, ")");
	}	
end:
	return out;
}

void Compile(astNode *line, FILE *f){
	char *code = compile(line);
	if (neededmemptr == true){
		tofree[freeptr] = getVarName(line->args[0]);
		freeptr++;
		neededmemptr = false;
	}
	int len = strlen(code);
	if (code[len-2] == ';' || code[len-2] == '{' || code[len-2] == '}')  fprintf(f, "%s", code);
	else fprintf(f, "%s;\n", code);
	free(code);
}
