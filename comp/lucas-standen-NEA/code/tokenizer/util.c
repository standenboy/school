#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

void Die(); // brings down the program
void *CheckedMalloc(long size); // malloc checked
void *CheckedRealloc(void *out, long size); // realloc checked
char **Split(char *s, char c); // splits a string into an array of strings around c

void Die(){
	perror("zpy parser");
	exit(errno);
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

static size_t countSegment(char const *s, char c){
	size_t counter = 0;
	int i = 0;
	while (s[i]){
		if (s[i] == c){
			i++;
			continue;
		}
		counter++;
		while (s[i] && s[i] != c) i++;
	}
	return counter;
}

char **Split(char *s, char c){
	char **strs;
	size_t tab_counter;
	size_t i;
	size_t j;

	if (s == NULL) return NULL;
	tab_counter = countSegment(s, c);
	if ((strs = (char**)CheckedMalloc(sizeof(char*) * (tab_counter + 1))) == NULL) return NULL;
	tab_counter = 0;
	j = -1;
	while (s[++j]) {
		if (s[j] == c) continue;
		i = 0;
		while (s[j + i] && s[j + i] != c) i++;
		if ((strs[tab_counter++] = strndup(&s[j], i)) == NULL) return NULL;
		j += i - 1;
	}
	strs[tab_counter] = NULL;
	return strs;
}
