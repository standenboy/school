#include <string.h>
#include "../global/types.h"
#include "../global/util.h"
#include "../tokenizer/tokenizer.h"

char *userVars[MAXVARS];
long varCount = 0;

literal *newVar(char *name, literal *value){
	userVars[varCount] = name;
	varCount++;
	literal *out = CheckedMalloc(sizeof(literal));
	
}

literal *toLiteral(char *str){
	for (int i = 0; i < userVarCount; i++){
		if (strcmp(str, userDefinedVars[i]) == 0){
			
		}
	}
}
