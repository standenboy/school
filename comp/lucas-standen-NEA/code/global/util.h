#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <error.h>

// functions for user
void Die(); // brings down the program
void *CheckedMalloc(long size); // malloc checked with autofree
void *CheckedRealloc(void *out, long size); // realloc checked with autofree
int CheckedFree(void *ptr); // frees a pointer if it is in the array MEMptrs
void CheckedFreeALL(); // frees all pointers in the array MEMptrs
