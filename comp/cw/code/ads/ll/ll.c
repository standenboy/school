#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct ll_t ll_t;

typedef struct ll_t {
	void *data;
	ll_t *next;
} ll_t;

ll_t *llalloc(){
	ll_t *output = malloc(sizeof(ll_t));
	if (output == NULL)
		return NULL;
	output->next = NULL;
	return output;
}

void llsetdata(ll_t *node, void *data){
	node->data = malloc(sizeof(data));
	memcpy(node->data, data, sizeof(data));
}

void llsetnext(ll_t *node, ll_t *next){
	if (node->next == NULL)
		node->next = next;
	else
		llsetnext(node->next, next);
}

void *llgetat(ll_t *head, int index){
	if (index == 0)
		return head->data;
	else {
		if (head->next != NULL)  {
			return llgetat(head->next, index - 1);
		}else {
			return NULL;
		}
	}
}

void llfreeall(ll_t *head){
	if (head->next != NULL)
		llfreeall(head->next);
	free(head->data);
	free(head);
}

