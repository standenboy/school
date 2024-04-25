#include <stdio.h>

#include "dll.h"

int main(){
	dll_t *head = dllalloc();
	dllsetdata(head, "hello");

	for (int i = 0; i < 3; i++){
		dll_t *node = dllalloc();
		dllsetdata(node, "hi");
		dllsetnext(head, node);
	}

	for (int i = 0; i < 4; i++)
		printf("%s\n", (char *)dllgetat(head, i)); 
	printf("%s\n", (char *)head->prev->next->data);

	dllfreeall(head);
}
