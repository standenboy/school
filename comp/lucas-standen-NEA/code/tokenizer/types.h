#include <stdint.h>
#include "../ads/ll/ll.h"

// all language types
typedef enum types { 
	I32_T = 0,
	I64_T = 1,
	U32_T = 2,
	U64_T = 3,
	FLOAT_t = 4,
	CHAR_T = 5,
	FUNCTION_T = 6,
} types;

// int types
typedef int32_t i32;
typedef int64_t i64;

// uint types
typedef uint32_t u32;
typedef uint64_t u64;

// char and float types are still called char and float so no typedef needed

// built in functions
typedef enum builtInFuncs {
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

	CAST = 20,
	TYPEOF = 21,
	EXIT = 22,
	RETURN = 23, 
} builtInFuncs;

// function type
typedef struct functionToken { 
	int id; // a function id to avoid strings
	types returnType; // what the function returns
	types *args; // the types of args a function takes
	ll_t *func; // the code for the function
	builtInFuncs builtInFunc; // a built in functions
} functionToken;

// built in functions

typedef struct ast_node ast_node;

typedef struct ast_node {
	functionToken *func; // if it's not builtin then use this
	void **literalArgs; // the args of the node, this will be an array of litteral values
	ast_node **args; // the non litteral tokens
	// if litteralArgs[x] is real then args[x] should be NULL, and vice versa
} ast_node;
