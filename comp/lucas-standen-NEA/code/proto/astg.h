typedef struct ast_node ast_node;

typedef enum op {
	ADD = 0,
	SUB = 1,
	MUL = 2,
	DIV = 3,
} op;

typedef struct ast_node {
	op operation;
	int realLeft;
	int realRight;
	ast_node *right;
	ast_node *left;
} ast_node;

int exec(ast_node *exp);
void freeAst(ast_node *head);
