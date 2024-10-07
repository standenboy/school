typedef struct stack {
	int *sp;
	int value;
	int (*pop)(struct stack *stack);
	void (*push)(struct stack *stack, int value);
	void (*free)(struct stack *stack);
	int *stack;
} stack;

stack *initstack(int value, size_t size);
