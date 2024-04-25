#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dll_t dll_t;

typedef struct dll_t {
	void *data;
	dll_t *next;
	dll_t *prev;
} dll_t;

dll_t *dllalloc();
void dllsetdata(dll_t *node, void *data);
void dllsetnext(dll_t *node, dll_t *next);
void dllsetprev(dll_t *node, dll_t *prev);
void *dllgetat(dll_t *head, int index);
void dllfreeall(dll_t *head);

