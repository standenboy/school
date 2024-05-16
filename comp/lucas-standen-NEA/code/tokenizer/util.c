#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

void Die(); // brings down the program
void *CheckedMalloc(long size); // malloc checked
void *CheckedRealloc(void *out, long size); // realloc checked

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
