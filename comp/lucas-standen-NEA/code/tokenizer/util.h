#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

void Die(); // brings down the program
void *CheckedMalloc(long size); // malloc checked
void *CheckedRealloc(void *out, long size); // realloc checked
char **Split(char *s, char c); // splits a string into an array of strings around c
