#include <stdlib.h>
#include <string.h>

typedef struct dict_t {
	int id;
	void *data;
}dict_t;

dict_t *dictalloc(){
	dict_t *output = malloc(sizeof(dict_t));
	return output;
}

int dictset(dict_t *dict, int id, void *data){
	dict->id = id;
	
	dict->data = malloc(sizeof(data));
	if (dict->data == NULL)
		return 1;
	memcpy(dict->data, data, sizeof(data));
	
	return 0;
}

void dictfree(dict_t *dict){
	free(dict->data);
	free(dict);
}

