#include <string.h>
#include "../global/types.h"
#include "../global/util.h"
#include "../tokenizer/tokenizer.h"

var *userVars[MAXVARS];
long varCount = 0;

void newVar(Vdef *definiton, literal *value){
	var *new = CheckedMalloc(sizeof(var));
	new->type = definiton->type;
	new->id = definiton->id;
	new->value = value;
	userVars[varCount] = new;
}

literal *getVarCalled(char *name){
	for (int i = 0; i < varCount; i++){
		if (strcmp(userVars[i]->id, name)){
			return userVars[i]->value;
		}
	}
	printf("no such variable %s\n", name);
	return NULL;
}
