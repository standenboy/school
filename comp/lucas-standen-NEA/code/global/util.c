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
void *CheckedMalloc(long size); // malloc checked with autofree
void *CheckedRealloc(void *out, long size); // realloc checked with autofree
int CheckedFree(void *ptr); // frees a pointer if it is in the array MEMptrs
void CheckedFreeALL(); // frees all pointers in the array MEMptrs

#define MAXPTRS 30000 // maximum allocs done by user

void *MEMptrs[MAXPTRS] = { NULL };
size_t currentPtr = 0;

void Die(){
	perror("zpy parser");
	exit(errno);
}

void *CheckedMalloc(long size){
	void *out = malloc(size);
	if (out == NULL)
		Die();
	MEMptrs[currentPtr] = out;	
	currentPtr++;
	if (currentPtr > MAXPTRS){
		printf("used %d ptrs!\n", MAXPTRS);
		Die();
	}
	return out;
}

void *CheckedRealloc(void *orig, long size){
	void *out = realloc(orig, size);
	if (out == NULL)
		Die();
	MEMptrs[currentPtr] = out;	
	currentPtr++;
	if (currentPtr > MAXPTRS){
		printf("used %d ptrs!\n", MAXPTRS);
		Die();
	}

	for (int i = 0; i < MAXPTRS; i++)
		if (MEMptrs[i] == orig && MEMptrs[i] != NULL) MEMptrs[i] = NULL;

	return out;
}

int CheckedFree(void *ptr){
	if (ptr == NULL) return 1;
	for (int i = 0; i < MAXPTRS; i++){
		if (MEMptrs[i] == ptr){
			free(MEMptrs[i]);
			MEMptrs[i] = NULL;
			return 0;
		}
	}
	return 1;
}

void CheckedFreeALL(){
	for (int i = 0; i < MAXPTRS; i++){
		if (MEMptrs[i] != NULL){
			free(MEMptrs[i]);
		}
	}
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
	if (strlen(str) == 1){
		Char *out = malloc(sizeof(Char));
		out->data = str[0];
		return out;
	}
	else return NULL;
}
