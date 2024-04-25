#include <stdio.h>

#include "dict.h"

int main(){
	dict_t *dict = dictalloc();
	dictset(dict, 1, "hello");
	printf("%d:%s\n", dict->id, (char *)dict->data);
	dictfree(dict);
}
