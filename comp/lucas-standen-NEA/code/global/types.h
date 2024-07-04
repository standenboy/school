#include <stdint.h>

// int types
typedef struct I32 {
	int32_t data;
} I32;

typedef struct I64 {
	int64_t data;
} I64;

// uint types
typedef struct U32 {
	uint32_t data;
} U32;

typedef struct U64 {
	uint64_t data;
} U64;

typedef struct Char {
	char data;
} Char;

typedef struct Float {
	float data;
} Float;

typedef struct Arr {
	union literal *arr;
	long len;
} Arr;

typedef union literal {
	I32 *i32;
	I64 *i64;
	U32 *u32;
	I64 *u64;
	Char *ch;
	Float *fl;

	Arr *arr;
} literal;

// built in functions
typedef enum builtInFuncs {
	// general
	DEFUN = 0,
	LET = 1,
	SET = 2,
	IF = 3,
	ELIF = 4,
	ELSE = 5,
	FOR = 6,
	WHILE = 7,
	SYMBOL = 8,
	
	// arithmetic
	ADD = 10,
	SUB = 11,
	MUL = 12,
	DIV = 13,
	
	// comparison
	EQ = 14,
	NEQ = 15,
	GT = 16,
	LT = 17,
	GTEQ = 18,
	LTEQ = 19,

	// misc
	CAST = 20,
	TYPEOF = 21,
	EXIT = 22,
	RETURN = 23, 
	WRITE = 24,
	NIL = -1,
} builtInFuncs;

// function type
typedef struct functionToken { 
	int id; // a function id to avoid strings
	char *name; // the code for the function
	builtInFuncs builtInFunc; // a built in functions
} functionToken;

typedef struct ast_node ast_node;

typedef struct ast_node {
	functionToken *func; // if it's not builtin then use this
	literal **literalArgs; // the args of the node, this will be an array of literal values
	ast_node **args; // the non litteral tokens
	// if litteralArgs[x] is real then args[x] should be NULL, and vice versa
} ast_node;
