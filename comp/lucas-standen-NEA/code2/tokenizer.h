typedef struct astNode {
	char *funcName;
	char *args[8];
	struct astNode *children[8];
} astNode;

astNode *tokenize(char *line);
