#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <error.h>
#include <ctype.h>

#include "types.h"


// functions for user
void Die(); // brings down the program
void *CheckedMalloc(long size); // CheckedMalloc checked with autofree
void *CheckedRealloc(void *out, long size); // realloc checked with autofree
literal *giveType(char *tok);


void Die(){
	fprintf(stderr, "error occured, bringing down the program\n");
	exit(1);
}

void *CheckedMalloc(long size){
	void *out = malloc(size);
	if (out == NULL)
		Die();
	return out;
}

void *CheckedRealloc(void *orig, long size){
	void *out = realloc(orig, size);
	if (out == NULL)
		Die();
	return out;
}

I64 *isNum(char *str){
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i]) == 0 && str[i] != '-'){
			return NULL;	
		}
	}
	I64 *out = CheckedMalloc(sizeof(I64));
	out->data = strtol(str, NULL, 10);
	return out;
}

Float *isFloat(char *str){
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '.'){
			return NULL;	
		}
	}
	Float *out = CheckedMalloc(sizeof(Float));
	out->data = strtod(str, NULL);
	return out;
}

Char *isChar(char *str){
	if (str[0] == '\'' && str[strlen(str)-1] == '\''){
		str++;
		str[strlen(str)-1] = '\0';
		if (strlen(str) == 1){
			Char *out = CheckedMalloc(sizeof(Char));
			out->data = str[0];
			return out;
		}
		else return NULL;
	}
	return NULL;
}

Arr *isArr(char *str){
	char *strbak = CheckedMalloc(strlen(str));
	memcpy(strbak, str, strlen(str)+1);
	if (strbak[0] == '[' && strbak[strlen(strbak)-1] == ']'){
		Arr *arr = CheckedMalloc(sizeof(Arr));
		arr->arr = CheckedMalloc(sizeof(literal));
		strbak++;
		strbak[strlen(strbak)-1] = '\0';
		char *tok;
		int length = 0;
		size_t cCount = 1;
		tok = strtok(strbak, ",");
		while (tok != NULL){
			cCount++;
			arr = CheckedRealloc(arr, sizeof(Arr) * cCount);
			arr->arr[cCount - 2] = *giveType(tok);
			tok = strtok(NULL, ",");
			length++;
		}
		arr->len = length;
		free(strbak - 1);
		return arr;
	} else {
		free(strbak);
		return NULL;
	}
}

Vdef *isVdef(char *str){
	if (strchr(str, ':') != NULL){
		Vdef *out = CheckedMalloc(sizeof(Vdef));
		char *type;

		out->id = strtok(str, ":");
		
		type = strtok(NULL, ":");	
		if (strcmp(type, "i64") == 0) out->type = TI64;
		else if (strcmp(type, "i32") == 0) out->type = TI32;
		else if (strcmp(type, "u64") == 0) out->type = TU64;
		else if (strcmp(type, "u32") == 0) out->type = TU32;

		else if (strcmp(type, "char") == 0) out->type = TChar;
		else if (strcmp(type, "float") == 0) out->type = Tfloat;
		// do something with arrays here
		else {
			fprintf(stderr, "%s is not a valid data type\n", type);
			Die();
		}

		return out;
	}
	return NULL;
}

literal *giveType(char *tok){
	literal *out = CheckedMalloc(sizeof(literal));
	Arr *arr = isArr(tok);
	I64 *i64 = isNum(tok);
	Float *fl = isFloat(tok);
	Char *ch = isChar(tok);
	Vdef *vdef = isVdef(tok);

	if (arr != NULL){
		out->arr = arr;
	} else if (i64 != NULL){
		out->i64 = i64;
	} else if (fl != NULL){
		out->fl = fl;
	} else if (ch != NULL){
		out->ch = ch;
	}else if (vdef != NULL){
		out->vdef = vdef;
	} else {
		fprintf(stderr, "data %s could not be typed\n", tok);
		Die();
	}
	return out;
}
