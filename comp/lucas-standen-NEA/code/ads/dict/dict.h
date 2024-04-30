typedef struct dict_t {
	int id;
	void *data;
}dict_t;

dict_t *dictalloc();
int dictset(dict_t *dict, int id, void *data);
void dictfree(dict_t *dict);

