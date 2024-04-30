#include <stdlib.h>
#include <string.h>

typedef struct ll_t ll_t;

typedef struct ll_t {
	void *data;
	ll_t *next;
} ll_t;

ll_t *llalloc();
void llsetdata(ll_t *node, void *data);
void llsetnext(ll_t *node, ll_t *next);
void *llgetat(ll_t *head, int index);
ll_t *llgetendnode(ll_t *head);
void llfreeall(ll_t *head);
