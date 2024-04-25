#include <stdio.h>

#include "ll.h"

int main(){
	ll_t *head = llalloc();
	llsetdata(head, "hello");

	for (int i = 0; i < 3; i++){
		ll_t *node = llalloc();
		llsetdata(node, "hi");
		llsetnext(head, node);
	}
	for (int i = 0; i < 4; i++)
		printf("%s\n", (char *)llgetat(head, i)); 

	llfreeall(head);
}
