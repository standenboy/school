#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "String.h"

size_t STRINGSPLITCOUNT = 0;

void __stringfree(string *self){
	free(self->_str);
	free(self);
}

void __stringprint(string *self){
	printf("%s\n", self->_str);
}

void __stringinput(string *self, size_t len){
	char *tmp = calloc(0, len);
	fgets(tmp, len, stdin);
	self->fromcstring(self, tmp);
}

void __stringappendchar(string *self, char c){
	self->_len++;
	self->_str = realloc(self->_str, self->_len);
	self->_str[self->_len-1] = c;
}

int __stringinsert(string *self, string *substring, size_t point){
	if (point > self->_len) return 1;

	size_t len = self->_len + substring->_len;

	char *start = malloc(point);
	char *end = malloc(self->_len - point);
	
	int i;
	for (i = 0; i < point; i++){
		start[i] = self->_str[i];
	}

	int j = 0;
	for (; i < self->_len; i++){
		end[j] = self->_str[i];
		j++;
	}
	
	self->_str = realloc(self->_str, len);

	for (i = 0; i < strlen(start); i++){
		self->_str[i] = start[i];
	}
	j = 0;
	for (; j < substring->_len; i++){
		self->_str[i] = substring->_str[j];
		j++;
	}
	j = 0;
	for (; i < len; i++){
		self->_str[i] = end[j];
		j++;
	}

	self->_len = len;
	free(start);
	free(end);
	
	return 0;
}

void __stringreplacechar(string *self, char orig, char new){
	for (int i = 0; i < self->_len; i++)
		if (self->_str[i] == orig) self->_str[i] = new;
}

int __stringcountchar(string *self, char c){
	int count = 0;
	for (int i = 0; i < self->_len; i++)
		if (self->_str[i] == c) count++;

	return count;
}

int __stringcmp(string *str1, string *str2){
	return strcmp(str1->_str, str2->_str);
}

void __stringfromcstring(string *self, char *cstring){
	size_t len = strlen(cstring);
	
	self->_str = realloc(self->_str, len);

	memcpy(self->_str, cstring, len);

	self->_len = len;
}

char *__stringtocstring(string *self){
	char *cstring = malloc(self->_len + 1); 
	memcpy(cstring, self->_str, self->_len);
	cstring[self->_len + 1] = '\0';
	return cstring;
}

string **__stringsplit(string *self, char delim){
	int splitcount = self->countchar(self, delim) + 1;
	string **strs = malloc(sizeof(string **)); 

	int j = 0;
	for (int i = 0; i < splitcount; i++){
		char *str = calloc(0, self->_len);
		int charcount = 0;
		for (; self->_str[j] != delim && j < self->_len; j++){
			str[charcount] = self->_str[j];
			charcount++;
		}
		j++;
		str[charcount+1] = '\0';
		strs[i] = String(str);
		free(str);
	}

	STRINGSPLITCOUNT = splitcount;
	return strs;
}

string *String(char *cstring){ // returns an allocated String from a C string input
	size_t len = strlen(cstring);
	string *str = malloc(sizeof(string));

	str->_str = calloc(0, len);
	memcpy(str->_str, cstring, len);
	str->_len = len; 

	str->free = &__stringfree;
	str->appendchar = &__stringappendchar;
	str->insert = &__stringinsert;
	str->replacechar = &__stringreplacechar;
	str->countchar = &__stringcountchar;
	str->cmp = &__stringcmp;
	str->fromcstring = &__stringfromcstring;
	str->tocstring = &__stringtocstring;
	str->split = &__stringsplit;
	str->print = &__stringprint;
	str->input = &__stringinput;

	return str;
}
