#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct dll_t dll_t;

typedef struct dll_t {
	void *data;
	dll_t *next;
	dll_t *prev;
} dll_t;

dll_t *dllalloc(){
	dll_t *output = malloc(sizeof(dll_t));
	if (output == NULL)
		return NULL;
	output->next = NULL;
	output->prev = NULL;
	return output;
}

void dllsetdata(dll_t *node, void *data){
	node->data = malloc(sizeof(data));
	memcpy(node->data, data, sizeof(data));
}

void dllsetnext(dll_t *node, dll_t *next){
	if (node->next == NULL) {
		node->next = next;
		node->next->prev = node;
	}
	else
		dllsetnext(node->next, next);
}
void dllsetprev(dll_t *node, dll_t *prev){
	if (node->prev == NULL) {
		node->prev = prev;
		node->prev->next = node;
	}
	else
		dllsetprev(node->prev, prev);
}

void *dllgetat(dll_t *head, int index){
	if (index == 0)
		return head->data;
	else {
		if (head->next != NULL)  {
			return dllgetat(head->next, index - 1);
		}else {
			return NULL;
		}
	}
}

void dllfreeall(dll_t *head){
	if (head->next != NULL)
		dllfreeall(head->next);
	free(head->data);
	free(head);
}

